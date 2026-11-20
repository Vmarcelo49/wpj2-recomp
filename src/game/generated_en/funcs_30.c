#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80074FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074FF8: jal         0x80061348
    // 0x80074FFC: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074FFC: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    after_0:
    // 0x80075000: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80075004: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075008: bne         $v0, $zero, L_80075020
    if (ctx->r2 != 0) {
        // 0x8007500C: nop

            goto L_80075020;
    }
    // 0x8007500C: nop

    // 0x80075010: jal         0x80061348
    // 0x80075014: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075014: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    after_1:
    // 0x80075018: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007501C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80075020:
    // 0x80075020: b           L_80075030
    // 0x80075024: nop

        goto L_80075030;
    // 0x80075024: nop

    // 0x80075028: b           L_80075030
    // 0x8007502C: nop

        goto L_80075030;
    // 0x8007502C: nop

L_80075030:
    // 0x80075030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075038: jr          $ra
    // 0x8007503C: nop

    return;
    // 0x8007503C: nop

;}
RECOMP_FUNC void func_80075040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075040: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075044: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075048: nop

    // 0x8007504C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075050: nop

    // 0x80075054: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075058: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007505C: jr          $ra
    // 0x80075060: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075060: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075064: jr          $ra
    // 0x80075068: nop

    return;
    // 0x80075068: nop

    // 0x8007506C: jr          $ra
    // 0x80075070: nop

    return;
    // 0x80075070: nop

;}
RECOMP_FUNC void func_80075074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075078: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007507C: nop

    // 0x80075080: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075084: nop

    // 0x80075088: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007508C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075090: jr          $ra
    // 0x80075094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075098: jr          $ra
    // 0x8007509C: nop

    return;
    // 0x8007509C: nop

    // 0x800750A0: jr          $ra
    // 0x800750A4: nop

    return;
    // 0x800750A4: nop

;}
RECOMP_FUNC void func_800750A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800750A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800750AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800750B0: jal         0x80061348
    // 0x800750B4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800750B4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x800750B8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800750BC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800750C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800750C4: beq         $v0, $zero, L_80075118
    if (ctx->r2 == 0) {
        // 0x800750C8: nop

            goto L_80075118;
    }
    // 0x800750C8: nop

    // 0x800750CC: jal         0x80061348
    // 0x800750D0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800750D0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x800750D4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800750D8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800750DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800750E0: beq         $v0, $zero, L_80075118
    if (ctx->r2 == 0) {
        // 0x800750E4: nop

            goto L_80075118;
    }
    // 0x800750E4: nop

    // 0x800750E8: jal         0x80061348
    // 0x800750EC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800750EC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x800750F0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800750F4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800750F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800750FC: beq         $v0, $zero, L_80075118
    if (ctx->r2 == 0) {
        // 0x80075100: nop

            goto L_80075118;
    }
    // 0x80075100: nop

    // 0x80075104: jal         0x80061348
    // 0x80075108: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075108: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x8007510C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075110: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075114: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075118:
    // 0x80075118: b           L_80075128
    // 0x8007511C: nop

        goto L_80075128;
    // 0x8007511C: nop

    // 0x80075120: b           L_80075128
    // 0x80075124: nop

        goto L_80075128;
    // 0x80075124: nop

L_80075128:
    // 0x80075128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007512C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075130: jr          $ra
    // 0x80075134: nop

    return;
    // 0x80075134: nop

;}
RECOMP_FUNC void func_80075138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007513C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075140: jal         0x80061348
    // 0x80075144: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075144: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80075148: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007514C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075150: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075154: beq         $v0, $zero, L_800751A8
    if (ctx->r2 == 0) {
        // 0x80075158: nop

            goto L_800751A8;
    }
    // 0x80075158: nop

    // 0x8007515C: jal         0x80061348
    // 0x80075160: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075160: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80075164: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075168: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007516C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075170: beq         $v0, $zero, L_800751A8
    if (ctx->r2 == 0) {
        // 0x80075174: nop

            goto L_800751A8;
    }
    // 0x80075174: nop

    // 0x80075178: jal         0x80061348
    // 0x8007517C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007517C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80075180: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075184: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075188: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007518C: beq         $v0, $zero, L_800751A8
    if (ctx->r2 == 0) {
        // 0x80075190: nop

            goto L_800751A8;
    }
    // 0x80075190: nop

    // 0x80075194: jal         0x80061348
    // 0x80075198: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075198: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x8007519C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800751A0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800751A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800751A8:
    // 0x800751A8: b           L_800751B8
    // 0x800751AC: nop

        goto L_800751B8;
    // 0x800751AC: nop

    // 0x800751B0: b           L_800751B8
    // 0x800751B4: nop

        goto L_800751B8;
    // 0x800751B4: nop

L_800751B8:
    // 0x800751B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800751BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800751C0: jr          $ra
    // 0x800751C4: nop

    return;
    // 0x800751C4: nop

;}
RECOMP_FUNC void func_800751C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800751C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800751CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800751D0: jal         0x80061348
    // 0x800751D4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800751D4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x800751D8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800751DC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800751E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800751E4: beq         $v0, $zero, L_80075238
    if (ctx->r2 == 0) {
        // 0x800751E8: nop

            goto L_80075238;
    }
    // 0x800751E8: nop

    // 0x800751EC: jal         0x80061348
    // 0x800751F0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800751F0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x800751F4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800751F8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800751FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075200: beq         $v0, $zero, L_80075238
    if (ctx->r2 == 0) {
        // 0x80075204: nop

            goto L_80075238;
    }
    // 0x80075204: nop

    // 0x80075208: jal         0x80061348
    // 0x8007520C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007520C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80075210: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075214: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075218: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007521C: beq         $v0, $zero, L_80075238
    if (ctx->r2 == 0) {
        // 0x80075220: nop

            goto L_80075238;
    }
    // 0x80075220: nop

    // 0x80075224: jal         0x80061348
    // 0x80075228: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075228: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x8007522C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075230: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075234: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075238:
    // 0x80075238: b           L_80075248
    // 0x8007523C: nop

        goto L_80075248;
    // 0x8007523C: nop

    // 0x80075240: b           L_80075248
    // 0x80075244: nop

        goto L_80075248;
    // 0x80075244: nop

L_80075248:
    // 0x80075248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007524C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075250: jr          $ra
    // 0x80075254: nop

    return;
    // 0x80075254: nop

;}
RECOMP_FUNC void func_80075258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007525C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075260: jal         0x80061348
    // 0x80075264: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075264: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80075268: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007526C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075274: beq         $v0, $zero, L_800752C8
    if (ctx->r2 == 0) {
        // 0x80075278: nop

            goto L_800752C8;
    }
    // 0x80075278: nop

    // 0x8007527C: jal         0x80061348
    // 0x80075280: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075280: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80075284: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075288: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007528C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075290: beq         $v0, $zero, L_800752C8
    if (ctx->r2 == 0) {
        // 0x80075294: nop

            goto L_800752C8;
    }
    // 0x80075294: nop

    // 0x80075298: jal         0x80061348
    // 0x8007529C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007529C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x800752A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800752A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800752A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800752AC: beq         $v0, $zero, L_800752C8
    if (ctx->r2 == 0) {
        // 0x800752B0: nop

            goto L_800752C8;
    }
    // 0x800752B0: nop

    // 0x800752B4: jal         0x80061348
    // 0x800752B8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800752B8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x800752BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800752C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800752C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800752C8:
    // 0x800752C8: b           L_800752D8
    // 0x800752CC: nop

        goto L_800752D8;
    // 0x800752CC: nop

    // 0x800752D0: b           L_800752D8
    // 0x800752D4: nop

        goto L_800752D8;
    // 0x800752D4: nop

L_800752D8:
    // 0x800752D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800752DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800752E0: jr          $ra
    // 0x800752E4: nop

    return;
    // 0x800752E4: nop

;}
RECOMP_FUNC void func_800752E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800752E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800752EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800752F0: jal         0x80061348
    // 0x800752F4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800752F4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x800752F8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800752FC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075300: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075304: beq         $v0, $zero, L_80075358
    if (ctx->r2 == 0) {
        // 0x80075308: nop

            goto L_80075358;
    }
    // 0x80075308: nop

    // 0x8007530C: jal         0x80061348
    // 0x80075310: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075310: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80075314: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075318: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007531C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075320: beq         $v0, $zero, L_80075358
    if (ctx->r2 == 0) {
        // 0x80075324: nop

            goto L_80075358;
    }
    // 0x80075324: nop

    // 0x80075328: jal         0x80061348
    // 0x8007532C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007532C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80075330: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075334: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075338: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007533C: beq         $v0, $zero, L_80075358
    if (ctx->r2 == 0) {
        // 0x80075340: nop

            goto L_80075358;
    }
    // 0x80075340: nop

    // 0x80075344: jal         0x80061348
    // 0x80075348: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075348: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x8007534C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075350: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075354: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075358:
    // 0x80075358: b           L_80075368
    // 0x8007535C: nop

        goto L_80075368;
    // 0x8007535C: nop

    // 0x80075360: b           L_80075368
    // 0x80075364: nop

        goto L_80075368;
    // 0x80075364: nop

L_80075368:
    // 0x80075368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007536C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075370: jr          $ra
    // 0x80075374: nop

    return;
    // 0x80075374: nop

;}
RECOMP_FUNC void func_80075378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007537C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075380: jal         0x80061348
    // 0x80075384: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075384: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80075388: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007538C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075390: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075394: beq         $v0, $zero, L_800753E8
    if (ctx->r2 == 0) {
        // 0x80075398: nop

            goto L_800753E8;
    }
    // 0x80075398: nop

    // 0x8007539C: jal         0x80061348
    // 0x800753A0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800753A0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x800753A4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800753A8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800753AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800753B0: beq         $v0, $zero, L_800753E8
    if (ctx->r2 == 0) {
        // 0x800753B4: nop

            goto L_800753E8;
    }
    // 0x800753B4: nop

    // 0x800753B8: jal         0x80061348
    // 0x800753BC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800753BC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x800753C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800753C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800753C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800753CC: beq         $v0, $zero, L_800753E8
    if (ctx->r2 == 0) {
        // 0x800753D0: nop

            goto L_800753E8;
    }
    // 0x800753D0: nop

    // 0x800753D4: jal         0x80061348
    // 0x800753D8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800753D8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x800753DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800753E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800753E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800753E8:
    // 0x800753E8: b           L_800753F8
    // 0x800753EC: nop

        goto L_800753F8;
    // 0x800753EC: nop

    // 0x800753F0: b           L_800753F8
    // 0x800753F4: nop

        goto L_800753F8;
    // 0x800753F4: nop

L_800753F8:
    // 0x800753F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800753FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075400: jr          $ra
    // 0x80075404: nop

    return;
    // 0x80075404: nop

;}
RECOMP_FUNC void func_80075408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007540C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075410: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075414: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075418: nop

    // 0x8007541C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80075420: nop

    // 0x80075424: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80075428: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007542C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075430: beq         $v0, $zero, L_80075464
    if (ctx->r2 == 0) {
        // 0x80075434: nop

            goto L_80075464;
    }
    // 0x80075434: nop

    // 0x80075438: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8007543C: nop

    // 0x80075440: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80075444: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80075448: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007544C: beq         $v0, $zero, L_80075464
    if (ctx->r2 == 0) {
        // 0x80075450: nop

            goto L_80075464;
    }
    // 0x80075450: nop

    // 0x80075454: jal         0x8005F064
    // 0x80075458: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80075458: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    after_0:
    // 0x8007545C: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80075460: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075464:
    // 0x80075464: b           L_80075474
    // 0x80075468: nop

        goto L_80075474;
    // 0x80075468: nop

    // 0x8007546C: b           L_80075474
    // 0x80075470: nop

        goto L_80075474;
    // 0x80075470: nop

L_80075474:
    // 0x80075474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007547C: jr          $ra
    // 0x80075480: nop

    return;
    // 0x80075480: nop

;}
RECOMP_FUNC void func_80075484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075484: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075488: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007548C: nop

    // 0x80075490: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80075494: nop

    // 0x80075498: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x8007549C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800754A0: jr          $ra
    // 0x800754A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800754A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800754A8: jr          $ra
    // 0x800754AC: nop

    return;
    // 0x800754AC: nop

    // 0x800754B0: jr          $ra
    // 0x800754B4: nop

    return;
    // 0x800754B4: nop

;}
RECOMP_FUNC void func_800754B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800754B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800754BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800754C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800754C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800754C8: nop

    // 0x800754CC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x800754D0: nop

    // 0x800754D4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800754D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800754DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800754E0: beq         $v0, $zero, L_80075514
    if (ctx->r2 == 0) {
        // 0x800754E4: nop

            goto L_80075514;
    }
    // 0x800754E4: nop

    // 0x800754E8: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x800754EC: nop

    // 0x800754F0: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800754F4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800754F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800754FC: beq         $v0, $zero, L_80075514
    if (ctx->r2 == 0) {
        // 0x80075500: nop

            goto L_80075514;
    }
    // 0x80075500: nop

    // 0x80075504: jal         0x8005F064
    // 0x80075508: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80075508: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    after_0:
    // 0x8007550C: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80075510: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075514:
    // 0x80075514: b           L_80075524
    // 0x80075518: nop

        goto L_80075524;
    // 0x80075518: nop

    // 0x8007551C: b           L_80075524
    // 0x80075520: nop

        goto L_80075524;
    // 0x80075520: nop

L_80075524:
    // 0x80075524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007552C: jr          $ra
    // 0x80075530: nop

    return;
    // 0x80075530: nop

;}
RECOMP_FUNC void func_80075534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075534: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075538: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007553C: nop

    // 0x80075540: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075544: nop

    // 0x80075548: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007554C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075550: jr          $ra
    // 0x80075554: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075554: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075558: jr          $ra
    // 0x8007555C: nop

    return;
    // 0x8007555C: nop

    // 0x80075560: jr          $ra
    // 0x80075564: nop

    return;
    // 0x80075564: nop

;}
RECOMP_FUNC void func_80075568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075568: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007556C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075570: nop

    // 0x80075574: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075578: nop

    // 0x8007557C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075580: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075584: jr          $ra
    // 0x80075588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007558C: jr          $ra
    // 0x80075590: nop

    return;
    // 0x80075590: nop

    // 0x80075594: jr          $ra
    // 0x80075598: nop

    return;
    // 0x80075598: nop

;}
RECOMP_FUNC void func_8007559C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007559C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800755A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800755A4: nop

    // 0x800755A8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800755AC: nop

    // 0x800755B0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800755B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800755B8: jr          $ra
    // 0x800755BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800755BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800755C0: jr          $ra
    // 0x800755C4: nop

    return;
    // 0x800755C4: nop

    // 0x800755C8: jr          $ra
    // 0x800755CC: nop

    return;
    // 0x800755CC: nop

;}
RECOMP_FUNC void func_800755D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800755D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800755D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800755D8: nop

    // 0x800755DC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800755E0: nop

    // 0x800755E4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800755E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800755EC: jr          $ra
    // 0x800755F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800755F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800755F4: jr          $ra
    // 0x800755F8: nop

    return;
    // 0x800755F8: nop

    // 0x800755FC: jr          $ra
    // 0x80075600: nop

    return;
    // 0x80075600: nop

;}
RECOMP_FUNC void func_80075604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007560C: jal         0x80061348
    // 0x80075610: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075610: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075614: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075618: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007561C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075620: beq         $v0, $zero, L_80075674
    if (ctx->r2 == 0) {
        // 0x80075624: nop

            goto L_80075674;
    }
    // 0x80075624: nop

    // 0x80075628: jal         0x80061348
    // 0x8007562C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007562C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075630: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075634: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075638: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007563C: beq         $v0, $zero, L_80075674
    if (ctx->r2 == 0) {
        // 0x80075640: nop

            goto L_80075674;
    }
    // 0x80075640: nop

    // 0x80075644: jal         0x80061348
    // 0x80075648: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075648: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x8007564C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075650: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075654: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075658: beq         $v0, $zero, L_80075674
    if (ctx->r2 == 0) {
        // 0x8007565C: nop

            goto L_80075674;
    }
    // 0x8007565C: nop

    // 0x80075660: jal         0x80061348
    // 0x80075664: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075664: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075668: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007566C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075670: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075674:
    // 0x80075674: b           L_80075684
    // 0x80075678: nop

        goto L_80075684;
    // 0x80075678: nop

    // 0x8007567C: b           L_80075684
    // 0x80075680: nop

        goto L_80075684;
    // 0x80075680: nop

L_80075684:
    // 0x80075684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007568C: jr          $ra
    // 0x80075690: nop

    return;
    // 0x80075690: nop

;}
RECOMP_FUNC void func_80075694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007569C: jal         0x80061348
    // 0x800756A0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800756A0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x800756A4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800756A8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800756AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800756B0: beq         $v0, $zero, L_80075704
    if (ctx->r2 == 0) {
        // 0x800756B4: nop

            goto L_80075704;
    }
    // 0x800756B4: nop

    // 0x800756B8: jal         0x80061348
    // 0x800756BC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800756BC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x800756C0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800756C4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800756C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800756CC: beq         $v0, $zero, L_80075704
    if (ctx->r2 == 0) {
        // 0x800756D0: nop

            goto L_80075704;
    }
    // 0x800756D0: nop

    // 0x800756D4: jal         0x80061348
    // 0x800756D8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800756D8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x800756DC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800756E0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800756E4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800756E8: beq         $v0, $zero, L_80075704
    if (ctx->r2 == 0) {
        // 0x800756EC: nop

            goto L_80075704;
    }
    // 0x800756EC: nop

    // 0x800756F0: jal         0x80061348
    // 0x800756F4: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800756F4: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x800756F8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800756FC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075700: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075704:
    // 0x80075704: b           L_80075714
    // 0x80075708: nop

        goto L_80075714;
    // 0x80075708: nop

    // 0x8007570C: b           L_80075714
    // 0x80075710: nop

        goto L_80075714;
    // 0x80075710: nop

L_80075714:
    // 0x80075714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007571C: jr          $ra
    // 0x80075720: nop

    return;
    // 0x80075720: nop

;}
RECOMP_FUNC void func_80075724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075724: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075728: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007572C: nop

    // 0x80075730: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075734: nop

    // 0x80075738: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007573C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075740: jr          $ra
    // 0x80075744: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075744: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075748: jr          $ra
    // 0x8007574C: nop

    return;
    // 0x8007574C: nop

    // 0x80075750: jr          $ra
    // 0x80075754: nop

    return;
    // 0x80075754: nop

;}
RECOMP_FUNC void func_80075758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075758: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007575C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075760: nop

    // 0x80075764: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075768: nop

    // 0x8007576C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075770: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075774: jr          $ra
    // 0x80075778: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075778: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007577C: jr          $ra
    // 0x80075780: nop

    return;
    // 0x80075780: nop

    // 0x80075784: jr          $ra
    // 0x80075788: nop

    return;
    // 0x80075788: nop

;}
RECOMP_FUNC void func_8007578C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007578C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075794: jal         0x80061348
    // 0x80075798: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075798: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x8007579C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800757A0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800757A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800757A8: beq         $v0, $zero, L_800757FC
    if (ctx->r2 == 0) {
        // 0x800757AC: nop

            goto L_800757FC;
    }
    // 0x800757AC: nop

    // 0x800757B0: jal         0x80061348
    // 0x800757B4: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800757B4: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x800757B8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800757BC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800757C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800757C4: beq         $v0, $zero, L_800757FC
    if (ctx->r2 == 0) {
        // 0x800757C8: nop

            goto L_800757FC;
    }
    // 0x800757C8: nop

    // 0x800757CC: jal         0x80061348
    // 0x800757D0: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800757D0: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x800757D4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800757D8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800757DC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800757E0: beq         $v0, $zero, L_800757FC
    if (ctx->r2 == 0) {
        // 0x800757E4: nop

            goto L_800757FC;
    }
    // 0x800757E4: nop

    // 0x800757E8: jal         0x80061348
    // 0x800757EC: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800757EC: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x800757F0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800757F4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800757F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800757FC:
    // 0x800757FC: b           L_8007580C
    // 0x80075800: nop

        goto L_8007580C;
    // 0x80075800: nop

    // 0x80075804: b           L_8007580C
    // 0x80075808: nop

        goto L_8007580C;
    // 0x80075808: nop

L_8007580C:
    // 0x8007580C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075814: jr          $ra
    // 0x80075818: nop

    return;
    // 0x80075818: nop

;}
RECOMP_FUNC void func_8007581C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007581C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075824: jal         0x80061348
    // 0x80075828: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075828: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x8007582C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075830: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075834: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075838: beq         $v0, $zero, L_8007588C
    if (ctx->r2 == 0) {
        // 0x8007583C: nop

            goto L_8007588C;
    }
    // 0x8007583C: nop

    // 0x80075840: jal         0x80061348
    // 0x80075844: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075844: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075848: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007584C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075850: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075854: beq         $v0, $zero, L_8007588C
    if (ctx->r2 == 0) {
        // 0x80075858: nop

            goto L_8007588C;
    }
    // 0x80075858: nop

    // 0x8007585C: jal         0x80061348
    // 0x80075860: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075860: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x80075864: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075868: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007586C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075870: beq         $v0, $zero, L_8007588C
    if (ctx->r2 == 0) {
        // 0x80075874: nop

            goto L_8007588C;
    }
    // 0x80075874: nop

    // 0x80075878: jal         0x80061348
    // 0x8007587C: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007587C: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075880: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075884: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075888: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007588C:
    // 0x8007588C: b           L_8007589C
    // 0x80075890: nop

        goto L_8007589C;
    // 0x80075890: nop

    // 0x80075894: b           L_8007589C
    // 0x80075898: nop

        goto L_8007589C;
    // 0x80075898: nop

L_8007589C:
    // 0x8007589C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800758A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800758A4: jr          $ra
    // 0x800758A8: nop

    return;
    // 0x800758A8: nop

;}
RECOMP_FUNC void func_800758AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800758AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800758B0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800758B4: nop

    // 0x800758B8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800758BC: nop

    // 0x800758C0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800758C4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800758C8: jr          $ra
    // 0x800758CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800758CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800758D0: jr          $ra
    // 0x800758D4: nop

    return;
    // 0x800758D4: nop

    // 0x800758D8: jr          $ra
    // 0x800758DC: nop

    return;
    // 0x800758DC: nop

;}
RECOMP_FUNC void func_800758E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800758E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800758E4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800758E8: nop

    // 0x800758EC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800758F0: nop

    // 0x800758F4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800758F8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800758FC: jr          $ra
    // 0x80075900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075904: jr          $ra
    // 0x80075908: nop

    return;
    // 0x80075908: nop

    // 0x8007590C: jr          $ra
    // 0x80075910: nop

    return;
    // 0x80075910: nop

;}
RECOMP_FUNC void func_80075914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007591C: jal         0x80061348
    // 0x80075920: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075920: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075924: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075928: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007592C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075930: beq         $v0, $zero, L_80075984
    if (ctx->r2 == 0) {
        // 0x80075934: nop

            goto L_80075984;
    }
    // 0x80075934: nop

    // 0x80075938: jal         0x80061348
    // 0x8007593C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007593C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075940: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075944: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075948: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007594C: beq         $v0, $zero, L_80075984
    if (ctx->r2 == 0) {
        // 0x80075950: nop

            goto L_80075984;
    }
    // 0x80075950: nop

    // 0x80075954: jal         0x80061348
    // 0x80075958: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075958: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x8007595C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075960: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075964: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075968: beq         $v0, $zero, L_80075984
    if (ctx->r2 == 0) {
        // 0x8007596C: nop

            goto L_80075984;
    }
    // 0x8007596C: nop

    // 0x80075970: jal         0x80061348
    // 0x80075974: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075974: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075978: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007597C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075980: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075984:
    // 0x80075984: b           L_80075994
    // 0x80075988: nop

        goto L_80075994;
    // 0x80075988: nop

    // 0x8007598C: b           L_80075994
    // 0x80075990: nop

        goto L_80075994;
    // 0x80075990: nop

L_80075994:
    // 0x80075994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007599C: jr          $ra
    // 0x800759A0: nop

    return;
    // 0x800759A0: nop

;}
RECOMP_FUNC void func_800759A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800759A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800759A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800759AC: jal         0x80061348
    // 0x800759B0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800759B0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x800759B4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800759B8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800759BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800759C0: beq         $v0, $zero, L_80075A14
    if (ctx->r2 == 0) {
        // 0x800759C4: nop

            goto L_80075A14;
    }
    // 0x800759C4: nop

    // 0x800759C8: jal         0x80061348
    // 0x800759CC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800759CC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x800759D0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800759D4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800759D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800759DC: beq         $v0, $zero, L_80075A14
    if (ctx->r2 == 0) {
        // 0x800759E0: nop

            goto L_80075A14;
    }
    // 0x800759E0: nop

    // 0x800759E4: jal         0x80061348
    // 0x800759E8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800759E8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x800759EC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800759F0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800759F4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800759F8: beq         $v0, $zero, L_80075A14
    if (ctx->r2 == 0) {
        // 0x800759FC: nop

            goto L_80075A14;
    }
    // 0x800759FC: nop

    // 0x80075A00: jal         0x80061348
    // 0x80075A04: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075A04: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075A08: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075A0C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075A10: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075A14:
    // 0x80075A14: b           L_80075A24
    // 0x80075A18: nop

        goto L_80075A24;
    // 0x80075A18: nop

    // 0x80075A1C: b           L_80075A24
    // 0x80075A20: nop

        goto L_80075A24;
    // 0x80075A20: nop

L_80075A24:
    // 0x80075A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075A2C: jr          $ra
    // 0x80075A30: nop

    return;
    // 0x80075A30: nop

;}
RECOMP_FUNC void func_80075A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075A3C: jal         0x80061348
    // 0x80075A40: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075A40: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075A44: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075A48: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075A4C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075A50: beq         $v0, $zero, L_80075AA4
    if (ctx->r2 == 0) {
        // 0x80075A54: nop

            goto L_80075AA4;
    }
    // 0x80075A54: nop

    // 0x80075A58: jal         0x80061348
    // 0x80075A5C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075A5C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075A60: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075A64: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075A68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075A6C: beq         $v0, $zero, L_80075AA4
    if (ctx->r2 == 0) {
        // 0x80075A70: nop

            goto L_80075AA4;
    }
    // 0x80075A70: nop

    // 0x80075A74: jal         0x80061348
    // 0x80075A78: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075A78: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x80075A7C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075A80: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075A84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075A88: beq         $v0, $zero, L_80075AA4
    if (ctx->r2 == 0) {
        // 0x80075A8C: nop

            goto L_80075AA4;
    }
    // 0x80075A8C: nop

    // 0x80075A90: jal         0x80061348
    // 0x80075A94: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075A94: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075A98: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075A9C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075AA0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075AA4:
    // 0x80075AA4: b           L_80075AB4
    // 0x80075AA8: nop

        goto L_80075AB4;
    // 0x80075AA8: nop

    // 0x80075AAC: b           L_80075AB4
    // 0x80075AB0: nop

        goto L_80075AB4;
    // 0x80075AB0: nop

L_80075AB4:
    // 0x80075AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075ABC: jr          $ra
    // 0x80075AC0: nop

    return;
    // 0x80075AC0: nop

;}
RECOMP_FUNC void func_80075AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075ACC: jal         0x80061348
    // 0x80075AD0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075AD0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075AD4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075AD8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075ADC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075AE0: beq         $v0, $zero, L_80075B34
    if (ctx->r2 == 0) {
        // 0x80075AE4: nop

            goto L_80075B34;
    }
    // 0x80075AE4: nop

    // 0x80075AE8: jal         0x80061348
    // 0x80075AEC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075AEC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075AF0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075AF4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075AF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075AFC: beq         $v0, $zero, L_80075B34
    if (ctx->r2 == 0) {
        // 0x80075B00: nop

            goto L_80075B34;
    }
    // 0x80075B00: nop

    // 0x80075B04: jal         0x80061348
    // 0x80075B08: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075B08: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x80075B0C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075B10: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075B14: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075B18: beq         $v0, $zero, L_80075B34
    if (ctx->r2 == 0) {
        // 0x80075B1C: nop

            goto L_80075B34;
    }
    // 0x80075B1C: nop

    // 0x80075B20: jal         0x80061348
    // 0x80075B24: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075B24: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075B28: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075B2C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075B30: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075B34:
    // 0x80075B34: b           L_80075B44
    // 0x80075B38: nop

        goto L_80075B44;
    // 0x80075B38: nop

    // 0x80075B3C: b           L_80075B44
    // 0x80075B40: nop

        goto L_80075B44;
    // 0x80075B40: nop

L_80075B44:
    // 0x80075B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075B4C: jr          $ra
    // 0x80075B50: nop

    return;
    // 0x80075B50: nop

;}
RECOMP_FUNC void func_80075B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075B5C: jal         0x80061348
    // 0x80075B60: addiu       $a0, $zero, 0x45C
    ctx->r4 = ADD32(0, 0X45C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075B60: addiu       $a0, $zero, 0x45C
    ctx->r4 = ADD32(0, 0X45C);
    after_0:
    // 0x80075B64: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075B68: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075B6C: b           L_80075B7C
    // 0x80075B70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075B7C;
    // 0x80075B70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075B74: b           L_80075B7C
    // 0x80075B78: nop

        goto L_80075B7C;
    // 0x80075B78: nop

L_80075B7C:
    // 0x80075B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075B84: jr          $ra
    // 0x80075B88: nop

    return;
    // 0x80075B88: nop

;}
RECOMP_FUNC void func_80075B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075B94: jal         0x8005F064
    // 0x80075B98: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80075B98: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_0:
    // 0x80075B9C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80075BA0: b           L_80075BB0
    // 0x80075BA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075BB0;
    // 0x80075BA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075BA8: b           L_80075BB0
    // 0x80075BAC: nop

        goto L_80075BB0;
    // 0x80075BAC: nop

L_80075BB0:
    // 0x80075BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075BB8: jr          $ra
    // 0x80075BBC: nop

    return;
    // 0x80075BBC: nop

;}
RECOMP_FUNC void func_80075BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075BC8: jal         0x80061488
    // 0x80075BCC: addiu       $a0, $zero, 0x464
    ctx->r4 = ADD32(0, 0X464);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075BCC: addiu       $a0, $zero, 0x464
    ctx->r4 = ADD32(0, 0X464);
    after_0:
    // 0x80075BD0: slti        $t6, $v0, 0x4
    ctx->r14 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80075BD4: b           L_80075BE4
    // 0x80075BD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075BE4;
    // 0x80075BD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075BDC: b           L_80075BE4
    // 0x80075BE0: nop

        goto L_80075BE4;
    // 0x80075BE0: nop

L_80075BE4:
    // 0x80075BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075BEC: jr          $ra
    // 0x80075BF0: nop

    return;
    // 0x80075BF0: nop

;}
RECOMP_FUNC void func_80075BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075BFC: jal         0x80061488
    // 0x80075C00: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075C00: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    after_0:
    // 0x80075C04: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80075C08: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80075C0C: b           L_80075C1C
    // 0x80075C10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075C1C;
    // 0x80075C10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075C14: b           L_80075C1C
    // 0x80075C18: nop

        goto L_80075C1C;
    // 0x80075C18: nop

L_80075C1C:
    // 0x80075C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075C24: jr          $ra
    // 0x80075C28: nop

    return;
    // 0x80075C28: nop

;}
RECOMP_FUNC void func_80075C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075C34: jal         0x80061488
    // 0x80075C38: addiu       $a0, $zero, 0x468
    ctx->r4 = ADD32(0, 0X468);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075C38: addiu       $a0, $zero, 0x468
    ctx->r4 = ADD32(0, 0X468);
    after_0:
    // 0x80075C3C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80075C40: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80075C44: b           L_80075C54
    // 0x80075C48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075C54;
    // 0x80075C48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075C4C: b           L_80075C54
    // 0x80075C50: nop

        goto L_80075C54;
    // 0x80075C50: nop

L_80075C54:
    // 0x80075C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075C5C: jr          $ra
    // 0x80075C60: nop

    return;
    // 0x80075C60: nop

;}
RECOMP_FUNC void func_80075C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075C6C: jal         0x80061488
    // 0x80075C70: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075C70: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    after_0:
    // 0x80075C74: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80075C78: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80075C7C: b           L_80075C8C
    // 0x80075C80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075C8C;
    // 0x80075C80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075C84: b           L_80075C8C
    // 0x80075C88: nop

        goto L_80075C8C;
    // 0x80075C88: nop

L_80075C8C:
    // 0x80075C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075C94: jr          $ra
    // 0x80075C98: nop

    return;
    // 0x80075C98: nop

;}
RECOMP_FUNC void func_80075C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075C9C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075CA0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075CA4: nop

    // 0x80075CA8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80075CAC: nop

    // 0x80075CB0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80075CB4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075CB8: jr          $ra
    // 0x80075CBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075CBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075CC0: jr          $ra
    // 0x80075CC4: nop

    return;
    // 0x80075CC4: nop

    // 0x80075CC8: jr          $ra
    // 0x80075CCC: nop

    return;
    // 0x80075CCC: nop

;}
RECOMP_FUNC void func_80075CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075CD8: jal         0x80061488
    // 0x80075CDC: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075CDC: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    after_0:
    // 0x80075CE0: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80075CE4: b           L_80075CF4
    // 0x80075CE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075CF4;
    // 0x80075CE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075CEC: b           L_80075CF4
    // 0x80075CF0: nop

        goto L_80075CF4;
    // 0x80075CF0: nop

L_80075CF4:
    // 0x80075CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075CFC: jr          $ra
    // 0x80075D00: nop

    return;
    // 0x80075D00: nop

;}
RECOMP_FUNC void func_80075D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075D0C: jal         0x80061488
    // 0x80075D10: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075D10: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    after_0:
    // 0x80075D14: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80075D18: b           L_80075D28
    // 0x80075D1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075D28;
    // 0x80075D1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075D20: b           L_80075D28
    // 0x80075D24: nop

        goto L_80075D28;
    // 0x80075D24: nop

L_80075D28:
    // 0x80075D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075D30: jr          $ra
    // 0x80075D34: nop

    return;
    // 0x80075D34: nop

;}
RECOMP_FUNC void func_80075D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075D40: jal         0x80061348
    // 0x80075D44: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075D44: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80075D48: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075D4C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075D50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075D54: beq         $v0, $zero, L_80075DA8
    if (ctx->r2 == 0) {
        // 0x80075D58: nop

            goto L_80075DA8;
    }
    // 0x80075D58: nop

    // 0x80075D5C: jal         0x80061348
    // 0x80075D60: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075D60: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x80075D64: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075D68: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075D6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075D70: beq         $v0, $zero, L_80075DA8
    if (ctx->r2 == 0) {
        // 0x80075D74: nop

            goto L_80075DA8;
    }
    // 0x80075D74: nop

    // 0x80075D78: jal         0x80061348
    // 0x80075D7C: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075D7C: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80075D80: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075D84: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075D88: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075D8C: beq         $v0, $zero, L_80075DA8
    if (ctx->r2 == 0) {
        // 0x80075D90: nop

            goto L_80075DA8;
    }
    // 0x80075D90: nop

    // 0x80075D94: jal         0x80061348
    // 0x80075D98: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075D98: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80075D9C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075DA0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075DA4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075DA8:
    // 0x80075DA8: b           L_80075DB8
    // 0x80075DAC: nop

        goto L_80075DB8;
    // 0x80075DAC: nop

    // 0x80075DB0: b           L_80075DB8
    // 0x80075DB4: nop

        goto L_80075DB8;
    // 0x80075DB4: nop

L_80075DB8:
    // 0x80075DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075DC0: jr          $ra
    // 0x80075DC4: nop

    return;
    // 0x80075DC4: nop

;}
RECOMP_FUNC void func_80075DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075DC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075DD0: jal         0x80061348
    // 0x80075DD4: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075DD4: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80075DD8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075DDC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075DE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075DE4: beq         $v0, $zero, L_80075E38
    if (ctx->r2 == 0) {
        // 0x80075DE8: nop

            goto L_80075E38;
    }
    // 0x80075DE8: nop

    // 0x80075DEC: jal         0x80061348
    // 0x80075DF0: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075DF0: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x80075DF4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075DF8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075DFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075E00: beq         $v0, $zero, L_80075E38
    if (ctx->r2 == 0) {
        // 0x80075E04: nop

            goto L_80075E38;
    }
    // 0x80075E04: nop

    // 0x80075E08: jal         0x80061348
    // 0x80075E0C: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075E0C: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80075E10: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075E14: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075E18: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075E1C: beq         $v0, $zero, L_80075E38
    if (ctx->r2 == 0) {
        // 0x80075E20: nop

            goto L_80075E38;
    }
    // 0x80075E20: nop

    // 0x80075E24: jal         0x80061348
    // 0x80075E28: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075E28: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80075E2C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075E30: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075E34: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075E38:
    // 0x80075E38: b           L_80075E48
    // 0x80075E3C: nop

        goto L_80075E48;
    // 0x80075E3C: nop

    // 0x80075E40: b           L_80075E48
    // 0x80075E44: nop

        goto L_80075E48;
    // 0x80075E44: nop

L_80075E48:
    // 0x80075E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075E50: jr          $ra
    // 0x80075E54: nop

    return;
    // 0x80075E54: nop

;}
RECOMP_FUNC void func_80075E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075E58: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075E5C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075E60: nop

    // 0x80075E64: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075E68: nop

    // 0x80075E6C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075E70: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075E74: jr          $ra
    // 0x80075E78: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075E78: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075E7C: jr          $ra
    // 0x80075E80: nop

    return;
    // 0x80075E80: nop

    // 0x80075E84: jr          $ra
    // 0x80075E88: nop

    return;
    // 0x80075E88: nop

;}
RECOMP_FUNC void func_80075E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075E8C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075E90: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075E94: nop

    // 0x80075E98: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075E9C: nop

    // 0x80075EA0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075EA4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075EA8: jr          $ra
    // 0x80075EAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075EAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075EB0: jr          $ra
    // 0x80075EB4: nop

    return;
    // 0x80075EB4: nop

    // 0x80075EB8: jr          $ra
    // 0x80075EBC: nop

    return;
    // 0x80075EBC: nop

;}
RECOMP_FUNC void func_80075EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075EC8: jal         0x80061348
    // 0x80075ECC: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075ECC: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80075ED0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075ED4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075ED8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075EDC: beq         $v0, $zero, L_80075F30
    if (ctx->r2 == 0) {
        // 0x80075EE0: nop

            goto L_80075F30;
    }
    // 0x80075EE0: nop

    // 0x80075EE4: jal         0x80061348
    // 0x80075EE8: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075EE8: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x80075EEC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075EF0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075EF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075EF8: beq         $v0, $zero, L_80075F30
    if (ctx->r2 == 0) {
        // 0x80075EFC: nop

            goto L_80075F30;
    }
    // 0x80075EFC: nop

    // 0x80075F00: jal         0x80061348
    // 0x80075F04: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075F04: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80075F08: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075F0C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075F10: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075F14: beq         $v0, $zero, L_80075F30
    if (ctx->r2 == 0) {
        // 0x80075F18: nop

            goto L_80075F30;
    }
    // 0x80075F18: nop

    // 0x80075F1C: jal         0x80061348
    // 0x80075F20: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075F20: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80075F24: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075F28: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075F2C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075F30:
    // 0x80075F30: b           L_80075F40
    // 0x80075F34: nop

        goto L_80075F40;
    // 0x80075F34: nop

    // 0x80075F38: b           L_80075F40
    // 0x80075F3C: nop

        goto L_80075F40;
    // 0x80075F3C: nop

L_80075F40:
    // 0x80075F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075F48: jr          $ra
    // 0x80075F4C: nop

    return;
    // 0x80075F4C: nop

;}
RECOMP_FUNC void func_80075F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075F58: jal         0x80061348
    // 0x80075F5C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075F5C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80075F60: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075F64: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075F68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075F6C: beq         $v0, $zero, L_80075FC0
    if (ctx->r2 == 0) {
        // 0x80075F70: nop

            goto L_80075FC0;
    }
    // 0x80075F70: nop

    // 0x80075F74: jal         0x80061348
    // 0x80075F78: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075F78: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x80075F7C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075F80: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075F84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075F88: beq         $v0, $zero, L_80075FC0
    if (ctx->r2 == 0) {
        // 0x80075F8C: nop

            goto L_80075FC0;
    }
    // 0x80075F8C: nop

    // 0x80075F90: jal         0x80061348
    // 0x80075F94: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075F94: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80075F98: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075F9C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075FA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075FA4: beq         $v0, $zero, L_80075FC0
    if (ctx->r2 == 0) {
        // 0x80075FA8: nop

            goto L_80075FC0;
    }
    // 0x80075FA8: nop

    // 0x80075FAC: jal         0x80061348
    // 0x80075FB0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075FB0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80075FB4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075FB8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075FBC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075FC0:
    // 0x80075FC0: b           L_80075FD0
    // 0x80075FC4: nop

        goto L_80075FD0;
    // 0x80075FC4: nop

    // 0x80075FC8: b           L_80075FD0
    // 0x80075FCC: nop

        goto L_80075FD0;
    // 0x80075FCC: nop

L_80075FD0:
    // 0x80075FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075FD8: jr          $ra
    // 0x80075FDC: nop

    return;
    // 0x80075FDC: nop

;}
RECOMP_FUNC void func_80075FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075FE8: jal         0x80061348
    // 0x80075FEC: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075FEC: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80075FF0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075FF4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075FF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075FFC: beq         $v0, $zero, L_80076050
    if (ctx->r2 == 0) {
        // 0x80076000: nop

            goto L_80076050;
    }
    // 0x80076000: nop

    // 0x80076004: jal         0x80061348
    // 0x80076008: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076008: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x8007600C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80076010: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076014: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076018: beq         $v0, $zero, L_80076050
    if (ctx->r2 == 0) {
        // 0x8007601C: nop

            goto L_80076050;
    }
    // 0x8007601C: nop

    // 0x80076020: jal         0x80061348
    // 0x80076024: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076024: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80076028: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007602C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80076030: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80076034: beq         $v0, $zero, L_80076050
    if (ctx->r2 == 0) {
        // 0x80076038: nop

            goto L_80076050;
    }
    // 0x80076038: nop

    // 0x8007603C: jal         0x80061348
    // 0x80076040: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80076040: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80076044: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80076048: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007604C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076050:
    // 0x80076050: b           L_80076060
    // 0x80076054: nop

        goto L_80076060;
    // 0x80076054: nop

    // 0x80076058: b           L_80076060
    // 0x8007605C: nop

        goto L_80076060;
    // 0x8007605C: nop

L_80076060:
    // 0x80076060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076068: jr          $ra
    // 0x8007606C: nop

    return;
    // 0x8007606C: nop

;}
RECOMP_FUNC void func_80076070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076078: jal         0x80061348
    // 0x8007607C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007607C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80076080: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076084: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076088: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007608C: beq         $v0, $zero, L_800760E0
    if (ctx->r2 == 0) {
        // 0x80076090: nop

            goto L_800760E0;
    }
    // 0x80076090: nop

    // 0x80076094: jal         0x80061348
    // 0x80076098: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076098: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x8007609C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800760A0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800760A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800760A8: beq         $v0, $zero, L_800760E0
    if (ctx->r2 == 0) {
        // 0x800760AC: nop

            goto L_800760E0;
    }
    // 0x800760AC: nop

    // 0x800760B0: jal         0x80061348
    // 0x800760B4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800760B4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x800760B8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800760BC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800760C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800760C4: beq         $v0, $zero, L_800760E0
    if (ctx->r2 == 0) {
        // 0x800760C8: nop

            goto L_800760E0;
    }
    // 0x800760C8: nop

    // 0x800760CC: jal         0x80061348
    // 0x800760D0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800760D0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x800760D4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800760D8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800760DC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800760E0:
    // 0x800760E0: b           L_800760F0
    // 0x800760E4: nop

        goto L_800760F0;
    // 0x800760E4: nop

    // 0x800760E8: b           L_800760F0
    // 0x800760EC: nop

        goto L_800760F0;
    // 0x800760EC: nop

L_800760F0:
    // 0x800760F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800760F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800760F8: jr          $ra
    // 0x800760FC: nop

    return;
    // 0x800760FC: nop

;}
RECOMP_FUNC void func_80076100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076108: jal         0x80061348
    // 0x8007610C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007610C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80076110: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076114: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076118: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007611C: beq         $v0, $zero, L_80076170
    if (ctx->r2 == 0) {
        // 0x80076120: nop

            goto L_80076170;
    }
    // 0x80076120: nop

    // 0x80076124: jal         0x80061348
    // 0x80076128: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076128: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x8007612C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80076130: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076134: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076138: beq         $v0, $zero, L_80076170
    if (ctx->r2 == 0) {
        // 0x8007613C: nop

            goto L_80076170;
    }
    // 0x8007613C: nop

    // 0x80076140: jal         0x80061348
    // 0x80076144: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076144: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80076148: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007614C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80076150: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80076154: beq         $v0, $zero, L_80076170
    if (ctx->r2 == 0) {
        // 0x80076158: nop

            goto L_80076170;
    }
    // 0x80076158: nop

    // 0x8007615C: jal         0x80061348
    // 0x80076160: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80076160: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80076164: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80076168: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007616C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076170:
    // 0x80076170: b           L_80076180
    // 0x80076174: nop

        goto L_80076180;
    // 0x80076174: nop

    // 0x80076178: b           L_80076180
    // 0x8007617C: nop

        goto L_80076180;
    // 0x8007617C: nop

L_80076180:
    // 0x80076180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076188: jr          $ra
    // 0x8007618C: nop

    return;
    // 0x8007618C: nop

;}
RECOMP_FUNC void func_80076190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076198: jal         0x80061348
    // 0x8007619C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007619C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x800761A0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800761A4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800761A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800761AC: beq         $v0, $zero, L_80076200
    if (ctx->r2 == 0) {
        // 0x800761B0: nop

            goto L_80076200;
    }
    // 0x800761B0: nop

    // 0x800761B4: jal         0x80061348
    // 0x800761B8: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800761B8: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x800761BC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800761C0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800761C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800761C8: beq         $v0, $zero, L_80076200
    if (ctx->r2 == 0) {
        // 0x800761CC: nop

            goto L_80076200;
    }
    // 0x800761CC: nop

    // 0x800761D0: jal         0x80061348
    // 0x800761D4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800761D4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x800761D8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800761DC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800761E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800761E4: beq         $v0, $zero, L_80076200
    if (ctx->r2 == 0) {
        // 0x800761E8: nop

            goto L_80076200;
    }
    // 0x800761E8: nop

    // 0x800761EC: jal         0x80061348
    // 0x800761F0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800761F0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x800761F4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800761F8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800761FC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076200:
    // 0x80076200: b           L_80076210
    // 0x80076204: nop

        goto L_80076210;
    // 0x80076204: nop

    // 0x80076208: b           L_80076210
    // 0x8007620C: nop

        goto L_80076210;
    // 0x8007620C: nop

L_80076210:
    // 0x80076210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076218: jr          $ra
    // 0x8007621C: nop

    return;
    // 0x8007621C: nop

;}
RECOMP_FUNC void func_80076220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076220: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076224: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076228: nop

    // 0x8007622C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076230: nop

    // 0x80076234: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80076238: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007623C: jr          $ra
    // 0x80076240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076244: jr          $ra
    // 0x80076248: nop

    return;
    // 0x80076248: nop

    // 0x8007624C: jr          $ra
    // 0x80076250: nop

    return;
    // 0x80076250: nop

;}
RECOMP_FUNC void func_80076254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076254: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076258: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007625C: nop

    // 0x80076260: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076264: nop

    // 0x80076268: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007626C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076270: jr          $ra
    // 0x80076274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076278: jr          $ra
    // 0x8007627C: nop

    return;
    // 0x8007627C: nop

    // 0x80076280: jr          $ra
    // 0x80076284: nop

    return;
    // 0x80076284: nop

;}
RECOMP_FUNC void func_80076288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007628C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076290: jal         0x8005F064
    // 0x80076294: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80076294: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x80076298: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007629C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800762A0: beq         $v0, $zero, L_800762E8
    if (ctx->r2 == 0) {
        // 0x800762A4: nop

            goto L_800762E8;
    }
    // 0x800762A4: nop

    // 0x800762A8: jal         0x8005F064
    // 0x800762AC: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x800762AC: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_1:
    // 0x800762B0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800762B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800762B8: beq         $v0, $zero, L_800762E8
    if (ctx->r2 == 0) {
        // 0x800762BC: nop

            goto L_800762E8;
    }
    // 0x800762BC: nop

    // 0x800762C0: jal         0x8005F064
    // 0x800762C4: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_8005F064(rdram, ctx);
        goto after_2;
    // 0x800762C4: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_2:
    // 0x800762C8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800762CC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800762D0: beq         $v0, $zero, L_800762E8
    if (ctx->r2 == 0) {
        // 0x800762D4: nop

            goto L_800762E8;
    }
    // 0x800762D4: nop

    // 0x800762D8: jal         0x8005F064
    // 0x800762DC: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    func_8005F064(rdram, ctx);
        goto after_3;
    // 0x800762DC: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    after_3:
    // 0x800762E0: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x800762E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800762E8:
    // 0x800762E8: b           L_800762F8
    // 0x800762EC: nop

        goto L_800762F8;
    // 0x800762EC: nop

    // 0x800762F0: b           L_800762F8
    // 0x800762F4: nop

        goto L_800762F8;
    // 0x800762F4: nop

L_800762F8:
    // 0x800762F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800762FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076300: jr          $ra
    // 0x80076304: nop

    return;
    // 0x80076304: nop

;}
