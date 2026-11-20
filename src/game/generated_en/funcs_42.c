#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800B2FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2FB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B2FBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B2FC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B2FC4: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800B2FC8: nop

    // 0x800B2FCC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B2FD0: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x800B2FD4: beq         $at, $zero, L_800B3210
    if (ctx->r1 == 0) {
        // 0x800B2FD8: nop

            goto L_800B3210;
    }
    // 0x800B2FD8: nop

    // 0x800B2FDC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B2FE0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2FE4: addu        $at, $at, $t7
    gpr jr_addend_800B2FF0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B2FE8: lw          $t7, -0x6A0($at)
    ctx->r15 = ADD32(ctx->r1, -0X6A0);
    // 0x800B2FEC: nop

    // 0x800B2FF0: jr          $t7
    // 0x800B2FF4: nop

    switch (jr_addend_800B2FF0 >> 2) {
        case 0: goto L_800B2FF8; break;
        case 1: goto L_800B30BC; break;
        case 2: goto L_800B3190; break;
        case 3: goto L_800B31B0; break;
        case 4: goto L_800B31D0; break;
        case 5: goto L_800B31F0; break;
        default: switch_error(__func__, 0x800B2FF0, 0x800EF960);
    }
    // 0x800B2FF4: nop

L_800B2FF8:
    // 0x800B2FF8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2FFC: nop

    // 0x800B3000: lhu         $t9, 0x3A($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B3004: nop

    // 0x800B3008: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800B300C: beq         $t0, $zero, L_800B304C
    if (ctx->r8 == 0) {
        // 0x800B3010: nop

            goto L_800B304C;
    }
    // 0x800B3010: nop

    // 0x800B3014: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3018: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800B301C: lhu         $t2, 0x3A($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X3A);
    // 0x800B3020: nop

    // 0x800B3024: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800B3028: sh          $t3, 0x3A($t1)
    MEM_H(0X3A, ctx->r9) = ctx->r11;
    // 0x800B302C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B3030: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3034: nop

    // 0x800B3038: swc1        $f4, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f4.u32l;
    // 0x800B303C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B3040: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3044: nop

    // 0x800B3048: swc1        $f6, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->f6.u32l;
L_800B304C:
    // 0x800B304C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3050: nop

    // 0x800B3054: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B3058: nop

    // 0x800B305C: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800B3060: beq         $t8, $zero, L_800B30B4
    if (ctx->r24 == 0) {
        // 0x800B3064: nop

            goto L_800B30B4;
    }
    // 0x800B3064: nop

    // 0x800B3068: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B306C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800B3070: lhu         $t0, 0x3A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B3074: nop

    // 0x800B3078: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x800B307C: sh          $t2, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r10;
    // 0x800B3080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3084: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3088: jal         0x800B4448
    // 0x800B308C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800B4448(rdram, ctx);
        goto after_0;
    // 0x800B308C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800B3090: beq         $v0, $zero, L_800B30A0
    if (ctx->r2 == 0) {
        // 0x800B3094: nop

            goto L_800B30A0;
    }
    // 0x800B3094: nop

    // 0x800B3098: b           L_800B3220
    // 0x800B309C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B3220;
    // 0x800B309C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B30A0:
    // 0x800B30A0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B30A8: lhu         $a2, 0x12($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X12);
    // 0x800B30AC: jal         0x800B47A0
    // 0x800B30B0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800B47A0(rdram, ctx);
        goto after_1;
    // 0x800B30B0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
L_800B30B4:
    // 0x800B30B4: b           L_800B3210
    // 0x800B30B8: nop

        goto L_800B3210;
    // 0x800B30B8: nop

L_800B30BC:
    // 0x800B30BC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30C0: nop

    // 0x800B30C4: lhu         $t4, 0x3A($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X3A);
    // 0x800B30C8: nop

    // 0x800B30CC: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x800B30D0: beq         $t5, $zero, L_800B30F0
    if (ctx->r13 == 0) {
        // 0x800B30D4: nop

            goto L_800B30F0;
    }
    // 0x800B30D4: nop

    // 0x800B30D8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30DC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800B30E0: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B30E4: nop

    // 0x800B30E8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B30EC: sh          $t8, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r24;
L_800B30F0:
    // 0x800B30F0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30F4: nop

    // 0x800B30F8: lhu         $t2, 0x3A($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X3A);
    // 0x800B30FC: nop

    // 0x800B3100: andi        $t9, $t2, 0x80
    ctx->r25 = ctx->r10 & 0X80;
    // 0x800B3104: beq         $t9, $zero, L_800B3124
    if (ctx->r25 == 0) {
        // 0x800B3108: nop

            goto L_800B3124;
    }
    // 0x800B3108: nop

    // 0x800B310C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3110: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800B3114: lhu         $t1, 0x3A($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B3118: nop

    // 0x800B311C: and         $t4, $t1, $at
    ctx->r12 = ctx->r9 & ctx->r1;
    // 0x800B3120: sh          $t4, 0x3A($t3)
    MEM_H(0X3A, ctx->r11) = ctx->r12;
L_800B3124:
    // 0x800B3124: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3128: jal         0x800B4680
    // 0x800B312C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800B4680(rdram, ctx);
        goto after_2;
    // 0x800B312C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x800B3130: beq         $v0, $zero, L_800B3170
    if (ctx->r2 == 0) {
        // 0x800B3134: nop

            goto L_800B3170;
    }
    // 0x800B3134: nop

    // 0x800B3138: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B313C: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800B3140: lhu         $t7, 0x3A($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B3144: nop

    // 0x800B3148: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B314C: sh          $t8, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r24;
    // 0x800B3150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3154: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3158: jal         0x800B4448
    // 0x800B315C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B4448(rdram, ctx);
        goto after_3;
    // 0x800B315C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x800B3160: beq         $v0, $zero, L_800B3170
    if (ctx->r2 == 0) {
        // 0x800B3164: nop

            goto L_800B3170;
    }
    // 0x800B3164: nop

    // 0x800B3168: b           L_800B3220
    // 0x800B316C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B3220;
    // 0x800B316C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B3170:
    // 0x800B3170: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3174: nop

    // 0x800B3178: lhu         $t0, 0x3A($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B317C: nop

    // 0x800B3180: ori         $t2, $t0, 0x100
    ctx->r10 = ctx->r8 | 0X100;
    // 0x800B3184: sh          $t2, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r10;
    // 0x800B3188: b           L_800B3210
    // 0x800B318C: nop

        goto L_800B3210;
    // 0x800B318C: nop

L_800B3190:
    // 0x800B3190: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3194: nop

    // 0x800B3198: lhu         $t1, 0x3A($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B319C: nop

    // 0x800B31A0: ori         $t4, $t1, 0x200
    ctx->r12 = ctx->r9 | 0X200;
    // 0x800B31A4: sh          $t4, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r12;
    // 0x800B31A8: b           L_800B3210
    // 0x800B31AC: nop

        goto L_800B3210;
    // 0x800B31AC: nop

L_800B31B0:
    // 0x800B31B0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B31B4: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800B31B8: lhu         $t7, 0x3A($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B31BC: nop

    // 0x800B31C0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B31C4: sh          $t8, 0x3A($t3)
    MEM_H(0X3A, ctx->r11) = ctx->r24;
    // 0x800B31C8: b           L_800B3210
    // 0x800B31CC: nop

        goto L_800B3210;
    // 0x800B31CC: nop

L_800B31D0:
    // 0x800B31D0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B31D4: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x800B31D8: lhu         $t0, 0x3A($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B31DC: nop

    // 0x800B31E0: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x800B31E4: sh          $t2, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r10;
    // 0x800B31E8: b           L_800B3210
    // 0x800B31EC: nop

        goto L_800B3210;
    // 0x800B31EC: nop

L_800B31F0:
    // 0x800B31F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B31F4: nop

    // 0x800B31F8: lhu         $t1, 0x3A($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B31FC: nop

    // 0x800B3200: ori         $t4, $t1, 0x1000
    ctx->r12 = ctx->r9 | 0X1000;
    // 0x800B3204: sh          $t4, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r12;
    // 0x800B3208: b           L_800B3210
    // 0x800B320C: nop

        goto L_800B3210;
    // 0x800B320C: nop

L_800B3210:
    // 0x800B3210: b           L_800B3220
    // 0x800B3214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3220;
    // 0x800B3214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3218: b           L_800B3220
    // 0x800B321C: nop

        goto L_800B3220;
    // 0x800B321C: nop

L_800B3220:
    // 0x800B3220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3228: jr          $ra
    // 0x800B322C: nop

    return;
    // 0x800B322C: nop

;}
RECOMP_FUNC void func_800B3230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B3234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3238: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B323C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B3240: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B3244: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800B3248: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800B324C: jal         0x800B3EC0
    // 0x800B3250: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800B3EC0(rdram, ctx);
        goto after_0;
    // 0x800B3250: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800B3254: beq         $v0, $zero, L_800B3264
    if (ctx->r2 == 0) {
        // 0x800B3258: nop

            goto L_800B3264;
    }
    // 0x800B3258: nop

    // 0x800B325C: b           L_800B32D4
    // 0x800B3260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B32D4;
    // 0x800B3260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B3264:
    // 0x800B3264: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B3268: nop

    // 0x800B326C: beq         $t6, $zero, L_800B3284
    if (ctx->r14 == 0) {
        // 0x800B3270: nop

            goto L_800B3284;
    }
    // 0x800B3270: nop

    // 0x800B3274: lhu         $t7, 0x20($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X20);
    // 0x800B3278: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800B327C: nop

    // 0x800B3280: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800B3284:
    // 0x800B3284: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3288: nop

    // 0x800B328C: beq         $t9, $zero, L_800B32A4
    if (ctx->r25 == 0) {
        // 0x800B3290: nop

            goto L_800B32A4;
    }
    // 0x800B3290: nop

    // 0x800B3294: lh          $t0, 0x22($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X22);
    // 0x800B3298: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B329C: nop

    // 0x800B32A0: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
L_800B32A4:
    // 0x800B32A4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B32A8: nop

    // 0x800B32AC: beq         $t2, $zero, L_800B32C4
    if (ctx->r10 == 0) {
        // 0x800B32B0: nop

            goto L_800B32C4;
    }
    // 0x800B32B0: nop

    // 0x800B32B4: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x800B32B8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B32BC: nop

    // 0x800B32C0: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_800B32C4:
    // 0x800B32C4: b           L_800B32D4
    // 0x800B32C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B32D4;
    // 0x800B32C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B32CC: b           L_800B32D4
    // 0x800B32D0: nop

        goto L_800B32D4;
    // 0x800B32D0: nop

L_800B32D4:
    // 0x800B32D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B32D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B32DC: jr          $ra
    // 0x800B32E0: nop

    return;
    // 0x800B32E0: nop

;}
RECOMP_FUNC void func_800B32E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B32E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B32E8: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B32EC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800B32F0: nop

    // 0x800B32F4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B32F8: lhu         $v0, 0xC($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0XC);
    // 0x800B32FC: jr          $ra
    // 0x800B3300: nop

    return;
    // 0x800B3300: nop

    // 0x800B3304: jr          $ra
    // 0x800B3308: nop

    return;
    // 0x800B3308: nop

    // 0x800B330C: jr          $ra
    // 0x800B3310: nop

    return;
    // 0x800B3310: nop

;}
RECOMP_FUNC void func_800B3314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B331C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B3320: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3324: jal         0x800B3590
    // 0x800B3328: nop

    func_800B3590(rdram, ctx);
        goto after_0;
    // 0x800B3328: nop

    after_0:
    // 0x800B332C: b           L_800B333C
    // 0x800B3330: nop

        goto L_800B333C;
    // 0x800B3330: nop

    // 0x800B3334: b           L_800B333C
    // 0x800B3338: nop

        goto L_800B333C;
    // 0x800B3338: nop

L_800B333C:
    // 0x800B333C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3344: jr          $ra
    // 0x800B3348: nop

    return;
    // 0x800B3348: nop

;}
RECOMP_FUNC void func_800B334C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B334C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B3358: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B335C: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x800B3360: nop

    // 0x800B3364: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800B3368: bne         $t7, $zero, L_800B338C
    if (ctx->r15 != 0) {
        // 0x800B336C: nop

            goto L_800B338C;
    }
    // 0x800B336C: nop

    // 0x800B3370: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B3374: nop

    // 0x800B3378: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B337C: jal         0x800B3590
    // 0x800B3380: nop

    func_800B3590(rdram, ctx);
        goto after_0;
    // 0x800B3380: nop

    after_0:
    // 0x800B3384: b           L_800B3424
    // 0x800B3388: nop

        goto L_800B3424;
    // 0x800B3388: nop

L_800B338C:
    // 0x800B338C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B3390: nop

    // 0x800B3394: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B3398: nop

    // 0x800B339C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800B33A0: nop

    // 0x800B33A4: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800B33A8: bne         $t2, $zero, L_800B33B8
    if (ctx->r10 != 0) {
        // 0x800B33AC: nop

            goto L_800B33B8;
    }
    // 0x800B33AC: nop

    // 0x800B33B0: b           L_800B3424
    // 0x800B33B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3424;
    // 0x800B33B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B33B8:
    // 0x800B33B8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B33BC: nop

    // 0x800B33C0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800B33C4: nop

    // 0x800B33C8: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800B33CC: nop

    // 0x800B33D0: lbu         $t6, 0xF($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XF);
    // 0x800B33D4: nop

    // 0x800B33D8: bne         $t6, $zero, L_800B33E8
    if (ctx->r14 != 0) {
        // 0x800B33DC: nop

            goto L_800B33E8;
    }
    // 0x800B33DC: nop

    // 0x800B33E0: b           L_800B3424
    // 0x800B33E4: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
        goto L_800B3424;
    // 0x800B33E4: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_800B33E8:
    // 0x800B33E8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B33EC: nop

    // 0x800B33F0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800B33F4: nop

    // 0x800B33F8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800B33FC: nop

    // 0x800B3400: lbu         $t0, 0xE($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XE);
    // 0x800B3404: nop

    // 0x800B3408: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x800B340C: jal         0x800B3590
    // 0x800B3410: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    func_800B3590(rdram, ctx);
        goto after_1;
    // 0x800B3410: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    after_1:
    // 0x800B3414: b           L_800B3424
    // 0x800B3418: nop

        goto L_800B3424;
    // 0x800B3418: nop

    // 0x800B341C: b           L_800B3424
    // 0x800B3420: nop

        goto L_800B3424;
    // 0x800B3420: nop

L_800B3424:
    // 0x800B3424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3428: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B342C: jr          $ra
    // 0x800B3430: nop

    return;
    // 0x800B3430: nop

;}
RECOMP_FUNC void func_800B3434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B343C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B3440: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B3444: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x800B3448: nop

    // 0x800B344C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800B3450: bne         $t7, $zero, L_800B3474
    if (ctx->r15 != 0) {
        // 0x800B3454: nop

            goto L_800B3474;
    }
    // 0x800B3454: nop

    // 0x800B3458: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B345C: nop

    // 0x800B3460: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B3464: jal         0x800B351C
    // 0x800B3468: nop

    func_800B351C(rdram, ctx);
        goto after_0;
    // 0x800B3468: nop

    after_0:
    // 0x800B346C: b           L_800B350C
    // 0x800B3470: nop

        goto L_800B350C;
    // 0x800B3470: nop

L_800B3474:
    // 0x800B3474: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800B3478: nop

    // 0x800B347C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B3480: nop

    // 0x800B3484: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800B3488: nop

    // 0x800B348C: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800B3490: bne         $t2, $zero, L_800B34A0
    if (ctx->r10 != 0) {
        // 0x800B3494: nop

            goto L_800B34A0;
    }
    // 0x800B3494: nop

    // 0x800B3498: b           L_800B350C
    // 0x800B349C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B350C;
    // 0x800B349C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B34A0:
    // 0x800B34A0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B34A4: nop

    // 0x800B34A8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800B34AC: nop

    // 0x800B34B0: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800B34B4: nop

    // 0x800B34B8: lbu         $t6, 0xF($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XF);
    // 0x800B34BC: nop

    // 0x800B34C0: bne         $t6, $zero, L_800B34D0
    if (ctx->r14 != 0) {
        // 0x800B34C4: nop

            goto L_800B34D0;
    }
    // 0x800B34C4: nop

    // 0x800B34C8: b           L_800B350C
    // 0x800B34CC: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
        goto L_800B350C;
    // 0x800B34CC: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_800B34D0:
    // 0x800B34D0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800B34D4: nop

    // 0x800B34D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800B34DC: nop

    // 0x800B34E0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800B34E4: nop

    // 0x800B34E8: lbu         $t0, 0xE($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XE);
    // 0x800B34EC: nop

    // 0x800B34F0: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x800B34F4: jal         0x800B351C
    // 0x800B34F8: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    func_800B351C(rdram, ctx);
        goto after_1;
    // 0x800B34F8: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    after_1:
    // 0x800B34FC: b           L_800B350C
    // 0x800B3500: nop

        goto L_800B350C;
    // 0x800B3500: nop

    // 0x800B3504: b           L_800B350C
    // 0x800B3508: nop

        goto L_800B350C;
    // 0x800B3508: nop

L_800B350C:
    // 0x800B350C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3514: jr          $ra
    // 0x800B3518: nop

    return;
    // 0x800B3518: nop

;}
RECOMP_FUNC void func_800B351C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B351C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3524: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B3528: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B352C: nop

    // 0x800B3530: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B3534: nop

    // 0x800B3538: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x800B353C: beq         $t8, $zero, L_800B354C
    if (ctx->r24 == 0) {
        // 0x800B3540: nop

            goto L_800B354C;
    }
    // 0x800B3540: nop

    // 0x800B3544: b           L_800B3580
    // 0x800B3548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3580;
    // 0x800B3548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B354C:
    // 0x800B354C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B3550: nop

    // 0x800B3554: lhu         $t0, 0x3A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B3558: nop

    // 0x800B355C: ori         $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 | 0X2000;
    // 0x800B3560: sh          $t1, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r9;
    // 0x800B3564: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B3568: jal         0x800B3590
    // 0x800B356C: nop

    func_800B3590(rdram, ctx);
        goto after_0;
    // 0x800B356C: nop

    after_0:
    // 0x800B3570: b           L_800B3580
    // 0x800B3574: nop

        goto L_800B3580;
    // 0x800B3574: nop

    // 0x800B3578: b           L_800B3580
    // 0x800B357C: nop

        goto L_800B3580;
    // 0x800B357C: nop

L_800B3580:
    // 0x800B3580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B3588: jr          $ra
    // 0x800B358C: nop

    return;
    // 0x800B358C: nop

;}
RECOMP_FUNC void func_800B3590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3590: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B3594: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x800B3598: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800B359C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B35A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B35A4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B35A8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B35AC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B35B0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800B35B4: nop

    // 0x800B35B8: lhu         $v0, 0xA($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XA);
    // 0x800B35BC: b           L_800B35CC
    // 0x800B35C0: nop

        goto L_800B35CC;
    // 0x800B35C0: nop

    // 0x800B35C4: b           L_800B35CC
    // 0x800B35C8: nop

        goto L_800B35CC;
    // 0x800B35C8: nop

L_800B35CC:
    // 0x800B35CC: jr          $ra
    // 0x800B35D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B35D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B35D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B35D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B35D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B35DC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B35E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B35E4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B35E8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B35EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B35F0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B35F4: nop

    // 0x800B35F8: bltz        $t6, L_800B360C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B35FC: nop

            goto L_800B360C;
    }
    // 0x800B35FC: nop

    // 0x800B3600: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800B3604: bne         $at, $zero, L_800B3614
    if (ctx->r1 != 0) {
        // 0x800B3608: nop

            goto L_800B3614;
    }
    // 0x800B3608: nop

L_800B360C:
    // 0x800B360C: b           L_800B3A14
    // 0x800B3610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3A14;
    // 0x800B3610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B3614:
    // 0x800B3614: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B3618: nop

    // 0x800B361C: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x800B3620: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800B3624: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B3628: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800B362C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800B3630: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800B3634: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800B3638: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B363C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B3640: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800B3644: nop

    // 0x800B3648: bne         $t3, $at, L_800B3658
    if (ctx->r11 != ctx->r1) {
        // 0x800B364C: nop

            goto L_800B3658;
    }
    // 0x800B364C: nop

    // 0x800B3650: b           L_800B3A14
    // 0x800B3654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3A14;
    // 0x800B3654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B3658:
    // 0x800B3658: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B365C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800B3660: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800B3664: lw          $t4, 0xD4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD4C);
    // 0x800B3668: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B366C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B3670: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B3674: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B3678: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B367C: jal         0x800BD1FC
    // 0x800B3680: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800B3680: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    after_0:
    // 0x800B3684: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B368C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B3690: jal         0x800BD218
    // 0x800B3694: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B3694: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800B3698: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B369C: nop

    // 0x800B36A0: addu        $t8, $sp, $t9
    ctx->r24 = ADD32(ctx->r29, ctx->r25);
    // 0x800B36A4: lbu         $t8, 0x3C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3C);
    // 0x800B36A8: nop

    // 0x800B36AC: bne         $t8, $zero, L_800B36BC
    if (ctx->r24 != 0) {
        // 0x800B36B0: nop

            goto L_800B36BC;
    }
    // 0x800B36B0: nop

    // 0x800B36B4: b           L_800B3A14
    // 0x800B36B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3A14;
    // 0x800B36B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B36BC:
    // 0x800B36BC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800B36C0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800B36C4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800B36C8: blez        $t0, L_800B3708
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B36CC: nop

            goto L_800B3708;
    }
    // 0x800B36CC: nop

L_800B36D0:
    // 0x800B36D0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B36D4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B36D8: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x800B36DC: lbu         $t3, 0x3C($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3C);
    // 0x800B36E0: nop

    // 0x800B36E4: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x800B36E8: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x800B36EC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800B36F0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B36F4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B36F8: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x800B36FC: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B3700: bne         $at, $zero, L_800B36D0
    if (ctx->r1 != 0) {
        // 0x800B3704: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_800B36D0;
    }
    // 0x800B3704: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_800B3708:
    // 0x800B3708: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800B370C: nop

    // 0x800B3710: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x800B3714: lbu         $t0, 0x3C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3C);
    // 0x800B3718: nop

    // 0x800B371C: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800B3720: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B3724: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B3728: jal         0x800BC6EC
    // 0x800B372C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800B372C: nop

    after_2:
    // 0x800B3730: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B3734: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B3738: lw          $t3, 0xD50($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD50);
    // 0x800B373C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B3740: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3744: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B3748: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B374C: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B3750: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B3754: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x800B3758: jal         0x800BD1FC
    // 0x800B375C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x800B375C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    after_3:
    // 0x800B3760: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3764: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B3768: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800B376C: jal         0x800BD218
    // 0x800B3770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x800B3770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800B3774: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800B3778: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800B377C: addu        $t7, $sp, $t4
    ctx->r15 = ADD32(ctx->r29, ctx->r12);
    // 0x800B3780: lbu         $t7, 0x3C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3C);
    // 0x800B3784: nop

    // 0x800B3788: blez        $t7, L_800B39E8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B378C: nop

            goto L_800B39E8;
    }
    // 0x800B378C: nop

L_800B3790:
    // 0x800B3790: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B3794: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800B3798: lhu         $t8, 0xA($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0XA);
    // 0x800B379C: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800B37A0: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x800B37A4: andi        $t1, $t3, 0x1
    ctx->r9 = ctx->r11 & 0X1;
    // 0x800B37A8: xor         $t5, $t0, $t1
    ctx->r13 = ctx->r8 ^ ctx->r9;
    // 0x800B37AC: bne         $t5, $zero, L_800B3830
    if (ctx->r13 != 0) {
        // 0x800B37B0: nop

            goto L_800B3830;
    }
    // 0x800B37B0: nop

    // 0x800B37B4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B37B8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B37BC: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x800B37C0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B37C4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800B37C8: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x800B37CC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B37D0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800B37D4: lwc1        $f8, 0xCC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x800B37D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B37DC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B37E0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x800B37E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B37E8: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B37EC: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800B37F0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B37F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B37F8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800B37FC: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B3800: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x800B3804: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x800B3808: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B380C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800B3810: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B3814: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B3818: lwc1        $f4, 0xCC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800B381C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800B3820: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B3824: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3828: b           L_800B38A8
    // 0x800B382C: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
        goto L_800B38A8;
    // 0x800B382C: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
L_800B3830:
    // 0x800B3830: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B3834: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B3838: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B383C: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x800B3840: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x800B3844: lh          $t7, 0x4($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X4);
    // 0x800B3848: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B384C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B3850: lwc1        $f16, 0xCC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800B3854: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3858: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B385C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800B3860: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800B3864: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3868: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x800B386C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B3870: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B3874: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800B3878: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800B387C: addu        $t7, $t4, $t3
    ctx->r15 = ADD32(ctx->r12, ctx->r11);
    // 0x800B3880: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x800B3884: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B3888: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B388C: lwc1        $f8, 0xCC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x800B3890: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3894: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B3898: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x800B389C: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B38A0: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B38A4: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
L_800B38A8:
    // 0x800B38A8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B38AC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B38B0: lhu         $t4, 0xA($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0XA);
    // 0x800B38B4: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800B38B8: andi        $t3, $t4, 0x2
    ctx->r11 = ctx->r12 & 0X2;
    // 0x800B38BC: andi        $t8, $t9, 0x2
    ctx->r24 = ctx->r25 & 0X2;
    // 0x800B38C0: xor         $t2, $t3, $t8
    ctx->r10 = ctx->r11 ^ ctx->r24;
    // 0x800B38C4: bne         $t2, $zero, L_800B3948
    if (ctx->r10 != 0) {
        // 0x800B38C8: nop

            goto L_800B3948;
    }
    // 0x800B38C8: nop

    // 0x800B38CC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B38D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B38D4: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x800B38D8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800B38DC: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x800B38E0: lh          $t7, 0x2($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2);
    // 0x800B38E4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B38E8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800B38EC: lwc1        $f4, 0xD0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x800B38F0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B38F4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B38F8: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800B38FC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B3900: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B3904: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x800B3908: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B390C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B3910: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x800B3914: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x800B3918: addu        $t7, $t1, $t4
    ctx->r15 = ADD32(ctx->r9, ctx->r12);
    // 0x800B391C: lh          $t9, 0x6($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X6);
    // 0x800B3920: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B3924: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800B3928: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B392C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B3930: lwc1        $f10, 0xD0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x800B3934: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B3938: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B393C: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B3940: b           L_800B39C0
    // 0x800B3944: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
        goto L_800B39C0;
    // 0x800B3944: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
L_800B3948:
    // 0x800B3948: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B394C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B3950: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800B3954: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800B3958: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x800B395C: lh          $t5, 0x6($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X6);
    // 0x800B3960: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B3964: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B3968: lwc1        $f6, 0xD0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x800B396C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3970: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B3974: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B3978: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B397C: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B3980: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x800B3984: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B3988: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B398C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800B3990: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B3994: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x800B3998: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800B399C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B39A0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800B39A4: lwc1        $f4, 0xD0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x800B39A8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B39AC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B39B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B39B4: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800B39B8: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B39BC: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
L_800B39C0:
    // 0x800B39C0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B39C4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B39C8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B39CC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800B39D0: addu        $t5, $sp, $t9
    ctx->r13 = ADD32(ctx->r29, ctx->r25);
    // 0x800B39D4: lbu         $t5, 0x3C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3C);
    // 0x800B39D8: nop

    // 0x800B39DC: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B39E0: bne         $at, $zero, L_800B3790
    if (ctx->r1 != 0) {
        // 0x800B39E4: nop

            goto L_800B3790;
    }
    // 0x800B39E4: nop

L_800B39E8:
    // 0x800B39E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800B39EC: jal         0x800BC980
    // 0x800B39F0: nop

    SysMem_Free(rdram, ctx);
        goto after_5;
    // 0x800B39F0: nop

    after_5:
    // 0x800B39F4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B39F8: nop

    // 0x800B39FC: addu        $v0, $sp, $t6
    ctx->r2 = ADD32(ctx->r29, ctx->r14);
    // 0x800B3A00: lbu         $v0, 0x3C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3C);
    // 0x800B3A04: b           L_800B3A14
    // 0x800B3A08: nop

        goto L_800B3A14;
    // 0x800B3A08: nop

    // 0x800B3A0C: b           L_800B3A14
    // 0x800B3A10: nop

        goto L_800B3A14;
    // 0x800B3A10: nop

L_800B3A14:
    // 0x800B3A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B3A1C: jr          $ra
    // 0x800B3A20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B3A20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800B3A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3A24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3A28: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B3A2C: lwc1        $f4, -0x688($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X688);
    // 0x800B3A30: nop

    // 0x800B3A34: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800B3A38: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800B3A3C: lui         $at, 0xC700
    ctx->r1 = S32(0XC700 << 16);
    // 0x800B3A40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B3A44: nop

    // 0x800B3A48: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800B3A4C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800B3A50: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800B3A54: nop

    // 0x800B3A58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B3A5C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B3A60: nop

    // 0x800B3A64: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B3A68: nop

    // 0x800B3A6C: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x800B3A70: nop

    // 0x800B3A74: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B3A78: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800B3A7C: nop

    // 0x800B3A80: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800B3A84: nop

    // 0x800B3A88: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800B3A8C: beq         $t2, $zero, L_800B3AB4
    if (ctx->r10 == 0) {
        // 0x800B3A90: nop

            goto L_800B3AB4;
    }
    // 0x800B3A90: nop

    // 0x800B3A94: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800B3A98: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800B3A9C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800B3AA0: nop

    // 0x800B3AA4: lbu         $t6, 0xF($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XF);
    // 0x800B3AA8: nop

    // 0x800B3AAC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800B3AB0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800B3AB4:
    // 0x800B3AB4: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800B3AB8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800B3ABC: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800B3AC0: blez        $t9, L_800B3D74
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800B3AC4: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_800B3D74;
    }
    // 0x800B3AC4: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_800B3AC8:
    // 0x800B3AC8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800B3ACC: nop

    // 0x800B3AD0: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x800B3AD4: nop

    // 0x800B3AD8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800B3ADC: bne         $t2, $zero, L_800B3B7C
    if (ctx->r10 != 0) {
        // 0x800B3AE0: nop

            goto L_800B3B7C;
    }
    // 0x800B3AE0: nop

    // 0x800B3AE4: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800B3AE8: nop

    // 0x800B3AEC: lw          $t5, 0x104($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X104);
    // 0x800B3AF0: lwc1        $f16, 0xF4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x800B3AF4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B3AF8: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B3AFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3B00: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B3B04: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B3B08: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800B3B0C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800B3B10: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800B3B14: bc1f        L_800B3B28
    if (!c1cs) {
        // 0x800B3B18: nop

            goto L_800B3B28;
    }
    // 0x800B3B18: nop

    // 0x800B3B1C: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3B20: nop

    // 0x800B3B24: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_800B3B28:
    // 0x800B3B28: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800B3B2C: nop

    // 0x800B3B30: lw          $t6, 0x104($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X104);
    // 0x800B3B34: lh          $t7, 0x100($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X100);
    // 0x800B3B38: lwc1        $f18, 0xF4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XF4);
    // 0x800B3B3C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B3B40: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B3B44: lwc1        $f8, 0xCC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x800B3B48: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B3B4C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B3B50: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B3B54: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B3B58: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800B3B5C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800B3B60: bc1f        L_800B3B74
    if (!c1cs) {
        // 0x800B3B64: nop

            goto L_800B3B74;
    }
    // 0x800B3B64: nop

    // 0x800B3B68: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3B6C: nop

    // 0x800B3B70: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
L_800B3B74:
    // 0x800B3B74: b           L_800B3C0C
    // 0x800B3B78: nop

        goto L_800B3C0C;
    // 0x800B3B78: nop

L_800B3B7C:
    // 0x800B3B7C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800B3B80: nop

    // 0x800B3B84: lw          $t0, 0x104($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X104);
    // 0x800B3B88: lwc1        $f6, 0xF4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x800B3B8C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800B3B90: lwc1        $f16, 0xCC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800B3B94: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B3B98: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B3B9C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800B3BA0: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800B3BA4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800B3BA8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800B3BAC: bc1f        L_800B3BC0
    if (!c1cs) {
        // 0x800B3BB0: nop

            goto L_800B3BC0;
    }
    // 0x800B3BB0: nop

    // 0x800B3BB4: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3BB8: nop

    // 0x800B3BBC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_800B3BC0:
    // 0x800B3BC0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800B3BC4: nop

    // 0x800B3BC8: lw          $t2, 0x104($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X104);
    // 0x800B3BCC: lh          $t5, 0x100($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X100);
    // 0x800B3BD0: lwc1        $f10, 0xF4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XF4);
    // 0x800B3BD4: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x800B3BD8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800B3BDC: lwc1        $f18, 0xCC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x800B3BE0: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B3BE4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B3BE8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800B3BEC: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B3BF0: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800B3BF4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800B3BF8: bc1f        L_800B3C0C
    if (!c1cs) {
        // 0x800B3BFC: nop

            goto L_800B3C0C;
    }
    // 0x800B3BFC: nop

    // 0x800B3C00: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3C04: nop

    // 0x800B3C08: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_800B3C0C:
    // 0x800B3C0C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800B3C10: nop

    // 0x800B3C14: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800B3C18: nop

    // 0x800B3C1C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800B3C20: bne         $t8, $zero, L_800B3CC0
    if (ctx->r24 != 0) {
        // 0x800B3C24: nop

            goto L_800B3CC0;
    }
    // 0x800B3C24: nop

    // 0x800B3C28: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800B3C2C: nop

    // 0x800B3C30: lw          $t0, 0x108($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X108);
    // 0x800B3C34: lh          $t9, 0x102($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X102);
    // 0x800B3C38: lwc1        $f4, 0xF8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x800B3C3C: subu        $t2, $t0, $t9
    ctx->r10 = SUB32(ctx->r8, ctx->r25);
    // 0x800B3C40: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800B3C44: lwc1        $f6, 0xD0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800B3C48: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B3C4C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B3C50: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B3C54: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3C58: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800B3C5C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800B3C60: bc1f        L_800B3C74
    if (!c1cs) {
        // 0x800B3C64: nop

            goto L_800B3C74;
    }
    // 0x800B3C64: nop

    // 0x800B3C68: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3C6C: nop

    // 0x800B3C70: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_800B3C74:
    // 0x800B3C74: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800B3C78: nop

    // 0x800B3C7C: lw          $t4, 0x108($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X108);
    // 0x800B3C80: lwc1        $f8, 0xF8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x800B3C84: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B3C88: lwc1        $f10, 0xD0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x800B3C8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3C90: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B3C94: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B3C98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B3C9C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800B3CA0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800B3CA4: bc1f        L_800B3CB8
    if (!c1cs) {
        // 0x800B3CA8: nop

            goto L_800B3CB8;
    }
    // 0x800B3CA8: nop

    // 0x800B3CAC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3CB0: nop

    // 0x800B3CB4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
L_800B3CB8:
    // 0x800B3CB8: b           L_800B3D50
    // 0x800B3CBC: nop

        goto L_800B3D50;
    // 0x800B3CBC: nop

L_800B3CC0:
    // 0x800B3CC0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800B3CC4: nop

    // 0x800B3CC8: lw          $t6, 0x108($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X108);
    // 0x800B3CCC: lh          $t7, 0x102($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X102);
    // 0x800B3CD0: lwc1        $f16, 0xF8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x800B3CD4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B3CD8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800B3CDC: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x800B3CE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3CE4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B3CE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B3CEC: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800B3CF0: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800B3CF4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800B3CF8: bc1f        L_800B3D0C
    if (!c1cs) {
        // 0x800B3CFC: nop

            goto L_800B3D0C;
    }
    // 0x800B3CFC: nop

    // 0x800B3D00: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3D04: nop

    // 0x800B3D08: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
L_800B3D0C:
    // 0x800B3D0C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800B3D10: nop

    // 0x800B3D14: lw          $t9, 0x108($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X108);
    // 0x800B3D18: lwc1        $f18, 0xF8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x800B3D1C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800B3D20: lwc1        $f8, 0xD0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x800B3D24: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B3D28: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B3D2C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B3D30: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B3D34: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800B3D38: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800B3D3C: bc1f        L_800B3D50
    if (!c1cs) {
        // 0x800B3D40: nop

            goto L_800B3D50;
    }
    // 0x800B3D40: nop

    // 0x800B3D44: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B3D48: nop

    // 0x800B3D4C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_800B3D50:
    // 0x800B3D50: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800B3D54: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800B3D58: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B3D5C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B3D60: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x800B3D64: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3D68: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800B3D6C: bne         $at, $zero, L_800B3AC8
    if (ctx->r1 != 0) {
        // 0x800B3D70: sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
            goto L_800B3AC8;
    }
    // 0x800B3D70: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
L_800B3D74:
    // 0x800B3D74: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B3D78: nop

    // 0x800B3D7C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800B3D80: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B3D84: nop

    // 0x800B3D88: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800B3D8C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B3D90: nop

    // 0x800B3D94: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800B3D98: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B3D9C: nop

    // 0x800B3DA0: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800B3DA4: b           L_800B3DB4
    // 0x800B3DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3DB4;
    // 0x800B3DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3DAC: b           L_800B3DB4
    // 0x800B3DB0: nop

        goto L_800B3DB4;
    // 0x800B3DB0: nop

L_800B3DB4:
    // 0x800B3DB4: jr          $ra
    // 0x800B3DB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3DB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B3DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3DBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B3DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3DC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B3DC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B3DCC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B3DD0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3DD4: nop

    // 0x800B3DD8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B3DDC: nop

    // 0x800B3DE0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B3DE4: nop

    // 0x800B3DE8: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x800B3DEC: nop

    // 0x800B3DF0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800B3DF4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3DF8: nop

    // 0x800B3DFC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B3E00: nop

    // 0x800B3E04: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800B3E08: nop

    // 0x800B3E0C: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800B3E10: beq         $t3, $zero, L_800B3E40
    if (ctx->r11 == 0) {
        // 0x800B3E14: nop

            goto L_800B3E40;
    }
    // 0x800B3E14: nop

    // 0x800B3E18: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3E1C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B3E20: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B3E24: nop

    // 0x800B3E28: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B3E2C: nop

    // 0x800B3E30: lbu         $t8, 0xF($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF);
    // 0x800B3E34: nop

    // 0x800B3E38: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800B3E3C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800B3E40:
    // 0x800B3E40: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B3E44: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800B3E48: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B3E4C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3E50: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800B3E54: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B3E58: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B3E5C: blez        $t5, L_800B3EA8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B3E60: sw          $t3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r11;
            goto L_800B3EA8;
    }
    // 0x800B3E60: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_800B3E64:
    // 0x800B3E64: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3E68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B3E6C: lhu         $a2, 0x32($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X32);
    // 0x800B3E70: jal         0x800B53A0
    // 0x800B3E74: nop

    LoadPalette(rdram, ctx);
        goto after_0;
    // 0x800B3E74: nop

    after_0:
    // 0x800B3E78: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B3E7C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3E80: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800B3E84: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B3E88: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B3E8C: addiu       $t8, $t4, 0x160
    ctx->r24 = ADD32(ctx->r12, 0X160);
    // 0x800B3E90: addiu       $t0, $t9, 0x40
    ctx->r8 = ADD32(ctx->r25, 0X40);
    // 0x800B3E94: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B3E98: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800B3E9C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800B3EA0: bne         $at, $zero, L_800B3E64
    if (ctx->r1 != 0) {
        // 0x800B3EA4: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_800B3E64;
    }
    // 0x800B3EA4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800B3EA8:
    // 0x800B3EA8: b           L_800B3EB0
    // 0x800B3EAC: nop

        goto L_800B3EB0;
    // 0x800B3EAC: nop

L_800B3EB0:
    // 0x800B3EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3EB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B3EB8: jr          $ra
    // 0x800B3EBC: nop

    return;
    // 0x800B3EBC: nop

;}
RECOMP_FUNC void func_800B3EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3EC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B3EC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B3EC8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B3ECC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B3ED0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B3ED4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B3ED8: lw          $t6, 0xD60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD60);
    // 0x800B3EDC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3EE0: nop

    // 0x800B3EE4: bne         $t6, $t7, L_800B3F08
    if (ctx->r14 != ctx->r15) {
        // 0x800B3EE8: nop

            goto L_800B3F08;
    }
    // 0x800B3EE8: nop

    // 0x800B3EEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B3EF0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B3EF4: addiu       $a1, $a1, 0xD60
    ctx->r5 = ADD32(ctx->r5, 0XD60);
    // 0x800B3EF8: jal         0x800BCFCC
    // 0x800B3EFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800B3EFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x800B3F00: b           L_800B406C
    // 0x800B3F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B406C;
    // 0x800B3F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B3F08:
    // 0x800B3F08: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B3F0C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B3F10: lw          $t9, 0xD30($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD30);
    // 0x800B3F14: lw          $t8, 0xD34($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD34);
    // 0x800B3F18: nop

    // 0x800B3F1C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800B3F20: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B3F24: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B3F28: nop

    // 0x800B3F2C: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x800B3F30: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B3F34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B3F38: jal         0x800BC6EC
    // 0x800B3F3C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800B3F3C: nop

    after_1:
    // 0x800B3F40: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B3F44: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B3F48: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B3F4C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800B3F50: lw          $a2, 0xD30($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XD30);
    // 0x800B3F54: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B3F58: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B3F5C: jal         0x800BD1FC
    // 0x800B3F60: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B3F60: nop

    after_2:
    // 0x800B3F64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3F68: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B3F6C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B3F70: jal         0x800BD218
    // 0x800B3F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B3F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B3F78: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800B3F7C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800B3F80: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800B3F84: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3F88: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800B3F8C: nop

    // 0x800B3F90: sltu        $at, $t5, $t4
    ctx->r1 = ctx->r13 < ctx->r12 ? 1 : 0;
    // 0x800B3F94: beq         $at, $zero, L_800B3FF0
    if (ctx->r1 == 0) {
        // 0x800B3F98: nop

            goto L_800B3FF0;
    }
    // 0x800B3F98: nop

    // 0x800B3F9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B3FA0: nop

    // 0x800B3FA4: blez        $t6, L_800B3FF0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B3FA8: nop

            goto L_800B3FF0;
    }
    // 0x800B3FA8: nop

L_800B3FAC:
    // 0x800B3FAC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3FB0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B3FB4: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800B3FB8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B3FBC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B3FC0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800B3FC4: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800B3FC8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3FCC: nop

    // 0x800B3FD0: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    // 0x800B3FD4: beq         $at, $zero, L_800B3FF0
    if (ctx->r1 == 0) {
        // 0x800B3FD8: nop

            goto L_800B3FF0;
    }
    // 0x800B3FD8: nop

    // 0x800B3FDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800B3FE0: nop

    // 0x800B3FE4: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B3FE8: bne         $at, $zero, L_800B3FAC
    if (ctx->r1 != 0) {
        // 0x800B3FEC: nop

            goto L_800B3FAC;
    }
    // 0x800B3FEC: nop

L_800B3FF0:
    // 0x800B3FF0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3FF4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3FF8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800B3FFC: nop

    // 0x800B4000: bne         $t5, $t6, L_800B402C
    if (ctx->r13 != ctx->r14) {
        // 0x800B4004: nop

            goto L_800B402C;
    }
    // 0x800B4004: nop

    // 0x800B4008: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B400C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B4010: jal         0x800BCFCC
    // 0x800B4014: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x800B4014: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x800B4018: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B401C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B4020: addiu       $a0, $a0, 0xD60
    ctx->r4 = ADD32(ctx->r4, 0XD60);
    // 0x800B4024: jal         0x800BCFCC
    // 0x800B4028: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x800B4028: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_5:
L_800B402C:
    // 0x800B402C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B4030: jal         0x800BC980
    // 0x800B4034: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x800B4034: nop

    after_6:
    // 0x800B4038: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B403C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4040: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B4044: nop

    // 0x800B4048: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x800B404C: beq         $at, $zero, L_800B405C
    if (ctx->r1 == 0) {
        // 0x800B4050: nop

            goto L_800B405C;
    }
    // 0x800B4050: nop

    // 0x800B4054: b           L_800B406C
    // 0x800B4058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B406C;
    // 0x800B4058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B405C:
    // 0x800B405C: b           L_800B406C
    // 0x800B4060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B406C;
    // 0x800B4060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4064: b           L_800B406C
    // 0x800B4068: nop

        goto L_800B406C;
    // 0x800B4068: nop

L_800B406C:
    // 0x800B406C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B4074: jr          $ra
    // 0x800B4078: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B4078: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B407C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B407C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B4080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4084: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B4088: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B408C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B4090: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B4094: nop

    // 0x800B4098: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800B409C: nop

    // 0x800B40A0: sb          $t7, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r15;
    // 0x800B40A4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B40A8: nop

    // 0x800B40AC: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x800B40B0: lbu         $t9, 0x30($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X30);
    // 0x800B40B4: lbu         $t1, 0x10($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X10);
    // 0x800B40B8: nop

    // 0x800B40BC: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B40C0: beq         $at, $zero, L_800B43D8
    if (ctx->r1 == 0) {
        // 0x800B40C4: nop

            goto L_800B43D8;
    }
    // 0x800B40C4: nop

L_800B40C8:
    // 0x800B40C8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B40CC: nop

    // 0x800B40D0: lbu         $t4, 0x30($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X30);
    // 0x800B40D4: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800B40D8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800B40DC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B40E0: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800B40E4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800B40E8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800B40EC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B40F0: nop

    // 0x800B40F4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800B40F8: nop

    // 0x800B40FC: andi        $t0, $t8, 0x8000
    ctx->r8 = ctx->r24 & 0X8000;
    // 0x800B4100: bne         $t0, $zero, L_800B4190
    if (ctx->r8 != 0) {
        // 0x800B4104: nop

            goto L_800B4190;
    }
    // 0x800B4104: nop

    // 0x800B4108: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B410C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B4110: lbu         $t2, 0x4($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X4);
    // 0x800B4114: lwc1        $f4, 0x34($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X34);
    // 0x800B4118: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800B411C: bgez        $t2, L_800B4134
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B4120: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800B4134;
    }
    // 0x800B4120: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B4124: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B4128: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B412C: nop

    // 0x800B4130: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800B4134:
    // 0x800B4134: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B4138: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800B413C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B4140: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B4144: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x800B4148: nop

    // 0x800B414C: bc1f        L_800B415C
    if (!c1cs) {
        // 0x800B4150: nop

            goto L_800B415C;
    }
    // 0x800B4150: nop

    // 0x800B4154: b           L_800B43D8
    // 0x800B4158: nop

        goto L_800B43D8;
    // 0x800B4158: nop

L_800B415C:
    // 0x800B415C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4160: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B4164: lbu         $t5, 0x4($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X4);
    // 0x800B4168: lwc1        $f10, 0x34($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X34);
    // 0x800B416C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B4170: bgez        $t5, L_800B4188
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B4174: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B4188;
    }
    // 0x800B4174: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4178: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B417C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B4180: nop

    // 0x800B4184: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_800B4188:
    // 0x800B4188: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B418C: swc1        $f18, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f18.u32l;
L_800B4190:
    // 0x800B4190: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4194: nop

    // 0x800B4198: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B419C: nop

    // 0x800B41A0: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x800B41A4: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x800B41A8: beq         $at, $zero, L_800B439C
    if (ctx->r1 == 0) {
        // 0x800B41AC: nop

            goto L_800B439C;
    }
    // 0x800B41AC: nop

    // 0x800B41B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B41B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B41B8: addu        $at, $at, $t8
    gpr jr_addend_800B41C4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B41BC: lw          $t8, -0x684($at)
    ctx->r24 = ADD32(ctx->r1, -0X684);
    // 0x800B41C0: nop

    // 0x800B41C4: jr          $t8
    // 0x800B41C8: nop

    switch (jr_addend_800B41C4 >> 2) {
        case 0: goto L_800B41CC; break;
        case 1: goto L_800B41E8; break;
        case 2: goto L_800B429C; break;
        case 3: goto L_800B42D0; break;
        case 4: goto L_800B4304; break;
        default: switch_error(__func__, 0x800B41C4, 0x800EF97C);
    }
    // 0x800B41C8: nop

L_800B41CC:
    // 0x800B41CC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B41D0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B41D4: lbu         $t9, 0x2($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X2);
    // 0x800B41D8: nop

    // 0x800B41DC: sb          $t9, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r25;
    // 0x800B41E0: b           L_800B43B4
    // 0x800B41E4: nop

        goto L_800B43B4;
    // 0x800B41E4: nop

L_800B41E8:
    // 0x800B41E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B41EC: nop

    // 0x800B41F0: lbu         $t3, 0x38($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X38);
    // 0x800B41F4: nop

    // 0x800B41F8: blez        $t3, L_800B426C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B41FC: nop

            goto L_800B426C;
    }
    // 0x800B41FC: nop

    // 0x800B4200: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B4204: nop

    // 0x800B4208: lbu         $t4, 0x38($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X38);
    // 0x800B420C: nop

    // 0x800B4210: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x800B4214: sb          $t6, 0x38($t5)
    MEM_B(0X38, ctx->r13) = ctx->r14;
    // 0x800B4218: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B421C: nop

    // 0x800B4220: lbu         $t8, 0x38($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X38);
    // 0x800B4224: nop

    // 0x800B4228: blez        $t8, L_800B4244
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B422C: nop

            goto L_800B4244;
    }
    // 0x800B422C: nop

    // 0x800B4230: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4234: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B4238: lbu         $t9, 0x2($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X2);
    // 0x800B423C: b           L_800B4264
    // 0x800B4240: sb          $t9, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r25;
        goto L_800B4264;
    // 0x800B4240: sb          $t9, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r25;
L_800B4244:
    // 0x800B4244: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B4248: nop

    // 0x800B424C: lbu         $t3, 0x30($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X30);
    // 0x800B4250: nop

    // 0x800B4254: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800B4258: sb          $t4, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r12;
    // 0x800B425C: b           L_800B439C
    // 0x800B4260: nop

        goto L_800B439C;
    // 0x800B4260: nop

L_800B4264:
    // 0x800B4264: b           L_800B43B4
    // 0x800B4268: nop

        goto L_800B43B4;
    // 0x800B4268: nop

L_800B426C:
    // 0x800B426C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4270: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B4274: lbu         $t5, 0x2($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X2);
    // 0x800B4278: nop

    // 0x800B427C: sb          $t5, 0x30($t7)
    MEM_B(0X30, ctx->r15) = ctx->r13;
    // 0x800B4280: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4284: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B4288: lbu         $t0, 0x3($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X3);
    // 0x800B428C: nop

    // 0x800B4290: sb          $t0, 0x38($t9)
    MEM_B(0X38, ctx->r25) = ctx->r8;
    // 0x800B4294: b           L_800B43B4
    // 0x800B4298: nop

        goto L_800B43B4;
    // 0x800B4298: nop

L_800B429C:
    // 0x800B429C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B42A0: nop

    // 0x800B42A4: lhu         $t2, 0x3A($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X3A);
    // 0x800B42A8: nop

    // 0x800B42AC: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x800B42B0: sh          $t3, 0x3A($t1)
    MEM_H(0X3A, ctx->r9) = ctx->r11;
    // 0x800B42B4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B42B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B42BC: lbu         $t6, 0x2($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X2);
    // 0x800B42C0: nop

    // 0x800B42C4: sb          $t6, 0x30($t5)
    MEM_B(0X30, ctx->r13) = ctx->r14;
    // 0x800B42C8: b           L_800B43B4
    // 0x800B42CC: nop

        goto L_800B43B4;
    // 0x800B42CC: nop

L_800B42D0:
    // 0x800B42D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B42D4: nop

    // 0x800B42D8: lhu         $t8, 0x3A($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X3A);
    // 0x800B42DC: nop

    // 0x800B42E0: ori         $t0, $t8, 0x20
    ctx->r8 = ctx->r24 | 0X20;
    // 0x800B42E4: sh          $t0, 0x3A($t7)
    MEM_H(0X3A, ctx->r15) = ctx->r8;
    // 0x800B42E8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B42EC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B42F0: lbu         $t2, 0x2($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X2);
    // 0x800B42F4: nop

    // 0x800B42F8: sb          $t2, 0x30($t3)
    MEM_B(0X30, ctx->r11) = ctx->r10;
    // 0x800B42FC: b           L_800B43B4
    // 0x800B4300: nop

        goto L_800B43B4;
    // 0x800B4300: nop

L_800B4304:
    // 0x800B4304: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B4308: nop

    // 0x800B430C: lhu         $t4, 0x3A($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X3A);
    // 0x800B4310: nop

    // 0x800B4314: andi        $t6, $t4, 0x100
    ctx->r14 = ctx->r12 & 0X100;
    // 0x800B4318: beq         $t6, $zero, L_800B4368
    if (ctx->r14 == 0) {
        // 0x800B431C: nop

            goto L_800B4368;
    }
    // 0x800B431C: nop

    // 0x800B4320: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4324: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B4328: jal         0x800B4448
    // 0x800B432C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800B4448(rdram, ctx);
        goto after_0;
    // 0x800B432C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x800B4330: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B4334: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B4338: lhu         $t8, 0x3A($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B433C: nop

    // 0x800B4340: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800B4344: sh          $t0, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r8;
    // 0x800B4348: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B434C: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800B4350: lhu         $t9, 0x3A($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X3A);
    // 0x800B4354: nop

    // 0x800B4358: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x800B435C: sh          $t2, 0x3A($t7)
    MEM_H(0X3A, ctx->r15) = ctx->r10;
    // 0x800B4360: b           L_800B439C
    // 0x800B4364: nop

        goto L_800B439C;
    // 0x800B4364: nop

L_800B4368:
    // 0x800B4368: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B436C: nop

    // 0x800B4370: lhu         $t1, 0x3A($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B4374: nop

    // 0x800B4378: ori         $t4, $t1, 0x40
    ctx->r12 = ctx->r9 | 0X40;
    // 0x800B437C: sh          $t4, 0x3A($t3)
    MEM_H(0X3A, ctx->r11) = ctx->r12;
    // 0x800B4380: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4384: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B4388: lbu         $t8, 0x2($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X2);
    // 0x800B438C: nop

    // 0x800B4390: sb          $t8, 0x30($t0)
    MEM_B(0X30, ctx->r8) = ctx->r24;
    // 0x800B4394: b           L_800B43B4
    // 0x800B4398: nop

        goto L_800B43B4;
    // 0x800B4398: nop

L_800B439C:
    // 0x800B439C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B43A0: nop

    // 0x800B43A4: lbu         $t9, 0x30($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X30);
    // 0x800B43A8: nop

    // 0x800B43AC: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800B43B0: sb          $t2, 0x30($t5)
    MEM_B(0X30, ctx->r13) = ctx->r10;
L_800B43B4:
    // 0x800B43B4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B43B8: nop

    // 0x800B43BC: lw          $t4, 0x8($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X8);
    // 0x800B43C0: lbu         $t1, 0x30($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X30);
    // 0x800B43C4: lbu         $t3, 0x10($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X10);
    // 0x800B43C8: nop

    // 0x800B43CC: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B43D0: bne         $at, $zero, L_800B40C8
    if (ctx->r1 != 0) {
        // 0x800B43D4: nop

            goto L_800B40C8;
    }
    // 0x800B43D4: nop

L_800B43D8:
    // 0x800B43D8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B43DC: nop

    // 0x800B43E0: lw          $t0, 0x8($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X8);
    // 0x800B43E4: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x800B43E8: lbu         $t9, 0x10($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X10);
    // 0x800B43EC: nop

    // 0x800B43F0: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B43F4: bne         $at, $zero, L_800B4414
    if (ctx->r1 != 0) {
        // 0x800B43F8: nop

            goto L_800B4414;
    }
    // 0x800B43F8: nop

    // 0x800B43FC: lbu         $t2, 0x1B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1B);
    // 0x800B4400: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B4404: nop

    // 0x800B4408: sb          $t2, 0x30($t5)
    MEM_B(0X30, ctx->r13) = ctx->r10;
    // 0x800B440C: b           L_800B4438
    // 0x800B4410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B4438;
    // 0x800B4410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B4414:
    // 0x800B4414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4418: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B441C: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    // 0x800B4420: jal         0x800B47A0
    // 0x800B4424: nop

    func_800B47A0(rdram, ctx);
        goto after_1;
    // 0x800B4424: nop

    after_1:
    // 0x800B4428: b           L_800B4438
    // 0x800B442C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B4438;
    // 0x800B442C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4430: b           L_800B4438
    // 0x800B4434: nop

        goto L_800B4438;
    // 0x800B4434: nop

L_800B4438:
    // 0x800B4438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B443C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4440: jr          $ra
    // 0x800B4444: nop

    return;
    // 0x800B4444: nop

;}
RECOMP_FUNC void func_800B4448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B444C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4450: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B4454: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B4458: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B445C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B4460: nop

    // 0x800B4464: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800B4468: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800B446C: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x800B4470: nop

    // 0x800B4474: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B4478: bne         $at, $zero, L_800B4488
    if (ctx->r1 != 0) {
        // 0x800B447C: nop

            goto L_800B4488;
    }
    // 0x800B447C: nop

    // 0x800B4480: b           L_800B4670
    // 0x800B4484: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B4670;
    // 0x800B4484: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B4488:
    // 0x800B4488: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B448C: nop

    // 0x800B4490: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x800B4494: lbu         $t1, 0x30($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X30);
    // 0x800B4498: lbu         $t3, 0x10($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X10);
    // 0x800B449C: nop

    // 0x800B44A0: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B44A4: beq         $at, $zero, L_800B4554
    if (ctx->r1 == 0) {
        // 0x800B44A8: nop

            goto L_800B4554;
    }
    // 0x800B44A8: nop

L_800B44AC:
    // 0x800B44AC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B44B0: nop

    // 0x800B44B4: lbu         $t6, 0x30($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X30);
    // 0x800B44B8: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800B44BC: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800B44C0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800B44C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B44C8: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800B44CC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800B44D0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B44D4: nop

    // 0x800B44D8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800B44DC: nop

    // 0x800B44E0: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x800B44E4: bne         $t2, $zero, L_800B44F4
    if (ctx->r10 != 0) {
        // 0x800B44E8: nop

            goto L_800B44F4;
    }
    // 0x800B44E8: nop

    // 0x800B44EC: b           L_800B4518
    // 0x800B44F0: nop

        goto L_800B4518;
    // 0x800B44F0: nop

L_800B44F4:
    // 0x800B44F4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B44F8: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x800B44FC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800B4500: nop

    // 0x800B4504: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x800B4508: bne         $t4, $t6, L_800B4518
    if (ctx->r12 != ctx->r14) {
        // 0x800B450C: nop

            goto L_800B4518;
    }
    // 0x800B450C: nop

    // 0x800B4510: b           L_800B4554
    // 0x800B4514: nop

        goto L_800B4554;
    // 0x800B4514: nop

L_800B4518:
    // 0x800B4518: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B451C: nop

    // 0x800B4520: lbu         $t8, 0x30($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X30);
    // 0x800B4524: nop

    // 0x800B4528: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800B452C: sb          $t7, 0x30($t5)
    MEM_B(0X30, ctx->r13) = ctx->r15;
    // 0x800B4530: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B4534: nop

    // 0x800B4538: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x800B453C: lbu         $t0, 0x30($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X30);
    // 0x800B4540: lbu         $t1, 0x10($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X10);
    // 0x800B4544: nop

    // 0x800B4548: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B454C: bne         $at, $zero, L_800B44AC
    if (ctx->r1 != 0) {
        // 0x800B4550: nop

            goto L_800B44AC;
    }
    // 0x800B4550: nop

L_800B4554:
    // 0x800B4554: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B4558: nop

    // 0x800B455C: lbu         $t4, 0x30($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X30);
    // 0x800B4560: nop

    // 0x800B4564: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800B4568: sb          $t6, 0x30($t3)
    MEM_B(0X30, ctx->r11) = ctx->r14;
    // 0x800B456C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B4570: nop

    // 0x800B4574: lw          $t5, 0x8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X8);
    // 0x800B4578: lbu         $t7, 0x30($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X30);
    // 0x800B457C: lbu         $t9, 0x10($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X10);
    // 0x800B4580: nop

    // 0x800B4584: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B4588: bne         $at, $zero, L_800B464C
    if (ctx->r1 != 0) {
        // 0x800B458C: nop

            goto L_800B464C;
    }
    // 0x800B458C: nop

    // 0x800B4590: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B4594: nop

    // 0x800B4598: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x800B459C: nop

    // 0x800B45A0: lbu         $t1, 0x10($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X10);
    // 0x800B45A4: nop

    // 0x800B45A8: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x800B45AC: sb          $t4, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r12;
    // 0x800B45B0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B45B4: nop

    // 0x800B45B8: lbu         $t3, 0x30($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X30);
    // 0x800B45BC: nop

    // 0x800B45C0: blez        $t3, L_800B4644
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B45C4: nop

            goto L_800B4644;
    }
    // 0x800B45C4: nop

L_800B45C8:
    // 0x800B45C8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B45CC: nop

    // 0x800B45D0: lbu         $t7, 0x30($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X30);
    // 0x800B45D4: lw          $t5, 0xC($t8)
    ctx->r13 = MEM_W(ctx->r24, 0XC);
    // 0x800B45D8: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800B45DC: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B45E0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800B45E4: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x800B45E8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B45EC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B45F0: nop

    // 0x800B45F4: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x800B45F8: nop

    // 0x800B45FC: andi        $t2, $t4, 0x8000
    ctx->r10 = ctx->r12 & 0X8000;
    // 0x800B4600: beq         $t2, $zero, L_800B4624
    if (ctx->r10 == 0) {
        // 0x800B4604: nop

            goto L_800B4624;
    }
    // 0x800B4604: nop

    // 0x800B4608: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B460C: nop

    // 0x800B4610: lbu         $t3, 0x30($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X30);
    // 0x800B4614: nop

    // 0x800B4618: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x800B461C: b           L_800B462C
    // 0x800B4620: sb          $t8, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r24;
        goto L_800B462C;
    // 0x800B4620: sb          $t8, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r24;
L_800B4624:
    // 0x800B4624: b           L_800B4644
    // 0x800B4628: nop

        goto L_800B4644;
    // 0x800B4628: nop

L_800B462C:
    // 0x800B462C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B4630: nop

    // 0x800B4634: lbu         $t5, 0x30($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X30);
    // 0x800B4638: nop

    // 0x800B463C: bgtz        $t5, L_800B45C8
    if (SIGNED(ctx->r13) > 0) {
        // 0x800B4640: nop

            goto L_800B45C8;
    }
    // 0x800B4640: nop

L_800B4644:
    // 0x800B4644: b           L_800B4670
    // 0x800B4648: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B4670;
    // 0x800B4648: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B464C:
    // 0x800B464C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B4650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4654: lhu         $a2, 0x12($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X12);
    // 0x800B4658: jal         0x800B47A0
    // 0x800B465C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800B47A0(rdram, ctx);
        goto after_0;
    // 0x800B465C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_0:
    // 0x800B4660: b           L_800B4670
    // 0x800B4664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B4670;
    // 0x800B4664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4668: b           L_800B4670
    // 0x800B466C: nop

        goto L_800B4670;
    // 0x800B466C: nop

L_800B4670:
    // 0x800B4670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4678: jr          $ra
    // 0x800B467C: nop

    return;
    // 0x800B467C: nop

;}
RECOMP_FUNC void func_800B4680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4680: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B4684: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800B4688: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800B468C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x800B4690: lbu         $t8, 0x10($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X10);
    // 0x800B4694: nop

    // 0x800B4698: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B469C: bne         $at, $zero, L_800B46AC
    if (ctx->r1 != 0) {
        // 0x800B46A0: nop

            goto L_800B46AC;
    }
    // 0x800B46A0: nop

    // 0x800B46A4: b           L_800B4798
    // 0x800B46A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B4798;
    // 0x800B46A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B46AC:
    // 0x800B46AC: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x800B46B0: nop

    // 0x800B46B4: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x800B46B8: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800B46BC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B46C0: lbu         $t2, 0x10($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X10);
    // 0x800B46C4: nop

    // 0x800B46C8: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B46CC: beq         $at, $zero, L_800B4764
    if (ctx->r1 == 0) {
        // 0x800B46D0: nop

            goto L_800B4764;
    }
    // 0x800B46D0: nop

L_800B46D4:
    // 0x800B46D4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800B46D8: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800B46DC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800B46E0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B46E4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800B46E8: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800B46EC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800B46F0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B46F4: nop

    // 0x800B46F8: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800B46FC: nop

    // 0x800B4700: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800B4704: bne         $t9, $zero, L_800B4714
    if (ctx->r25 != 0) {
        // 0x800B4708: nop

            goto L_800B4714;
    }
    // 0x800B4708: nop

    // 0x800B470C: b           L_800B4738
    // 0x800B4710: nop

        goto L_800B4738;
    // 0x800B4710: nop

L_800B4714:
    // 0x800B4714: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800B4718: nop

    // 0x800B471C: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x800B4720: nop

    // 0x800B4724: andi        $t2, $t0, 0x7FFF
    ctx->r10 = ctx->r8 & 0X7FFF;
    // 0x800B4728: bne         $t2, $a1, L_800B4738
    if (ctx->r10 != ctx->r5) {
        // 0x800B472C: nop

            goto L_800B4738;
    }
    // 0x800B472C: nop

    // 0x800B4730: b           L_800B4764
    // 0x800B4734: nop

        goto L_800B4764;
    // 0x800B4734: nop

L_800B4738:
    // 0x800B4738: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800B473C: nop

    // 0x800B4740: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800B4744: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x800B4748: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x800B474C: nop

    // 0x800B4750: lbu         $t7, 0x10($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X10);
    // 0x800B4754: nop

    // 0x800B4758: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B475C: bne         $at, $zero, L_800B46D4
    if (ctx->r1 != 0) {
        // 0x800B4760: nop

            goto L_800B46D4;
    }
    // 0x800B4760: nop

L_800B4764:
    // 0x800B4764: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800B4768: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800B476C: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x800B4770: nop

    // 0x800B4774: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B4778: beq         $at, $zero, L_800B4788
    if (ctx->r1 == 0) {
        // 0x800B477C: nop

            goto L_800B4788;
    }
    // 0x800B477C: nop

    // 0x800B4780: b           L_800B4798
    // 0x800B4784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B4798;
    // 0x800B4784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B4788:
    // 0x800B4788: b           L_800B4798
    // 0x800B478C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B4798;
    // 0x800B478C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4790: b           L_800B4798
    // 0x800B4794: nop

        goto L_800B4798;
    // 0x800B4794: nop

L_800B4798:
    // 0x800B4798: jr          $ra
    // 0x800B479C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B479C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B47A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B47A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B47A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B47A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B47AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B47B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B47B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B47B8: nop

    // 0x800B47BC: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x800B47C0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800B47C4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B47C8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B47CC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800B47D0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B47D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B47D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B47DC: nop

    // 0x800B47E0: lhu         $t2, 0xA($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XA);
    // 0x800B47E4: nop

    // 0x800B47E8: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x800B47EC: beq         $t3, $zero, L_800B480C
    if (ctx->r11 == 0) {
        // 0x800B47F0: nop

            goto L_800B480C;
    }
    // 0x800B47F0: nop

    // 0x800B47F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B47F8: nop

    // 0x800B47FC: lhu         $t5, 0x3A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X3A);
    // 0x800B4800: nop

    // 0x800B4804: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800B4808: sh          $t6, 0x3A($t4)
    MEM_H(0X3A, ctx->r12) = ctx->r14;
L_800B480C:
    // 0x800B480C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4810: nop

    // 0x800B4814: lhu         $t7, 0xA($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0XA);
    // 0x800B4818: nop

    // 0x800B481C: andi        $t9, $t7, 0x80
    ctx->r25 = ctx->r15 & 0X80;
    // 0x800B4820: beq         $t9, $zero, L_800B4840
    if (ctx->r25 == 0) {
        // 0x800B4824: nop

            goto L_800B4840;
    }
    // 0x800B4824: nop

    // 0x800B4828: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B482C: nop

    // 0x800B4830: lhu         $t1, 0x3A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X3A);
    // 0x800B4834: nop

    // 0x800B4838: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800B483C: sh          $t2, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r10;
L_800B4840:
    // 0x800B4840: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4844: nop

    // 0x800B4848: lhu         $t5, 0xA($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0XA);
    // 0x800B484C: nop

    // 0x800B4850: andi        $t6, $t5, 0x100
    ctx->r14 = ctx->r13 & 0X100;
    // 0x800B4854: beq         $t6, $zero, L_800B4874
    if (ctx->r14 == 0) {
        // 0x800B4858: nop

            goto L_800B4874;
    }
    // 0x800B4858: nop

    // 0x800B485C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B4860: nop

    // 0x800B4864: lhu         $t8, 0x3A($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X3A);
    // 0x800B4868: nop

    // 0x800B486C: ori         $t7, $t8, 0x4
    ctx->r15 = ctx->r24 | 0X4;
    // 0x800B4870: sh          $t7, 0x3A($t4)
    MEM_H(0X3A, ctx->r12) = ctx->r15;
L_800B4874:
    // 0x800B4874: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4878: nop

    // 0x800B487C: lhu         $t1, 0xA($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0XA);
    // 0x800B4880: nop

    // 0x800B4884: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x800B4888: beq         $t2, $zero, L_800B48C4
    if (ctx->r10 == 0) {
        // 0x800B488C: nop

            goto L_800B48C4;
    }
    // 0x800B488C: nop

    // 0x800B4890: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B4894: nop

    // 0x800B4898: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800B489C: nop

    // 0x800B48A0: andi        $t5, $t3, 0x10
    ctx->r13 = ctx->r11 & 0X10;
    // 0x800B48A4: bne         $t5, $zero, L_800B48C4
    if (ctx->r13 != 0) {
        // 0x800B48A8: nop

            goto L_800B48C4;
    }
    // 0x800B48A8: nop

    // 0x800B48AC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B48B0: nop

    // 0x800B48B4: lhu         $t8, 0x3A($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B48B8: nop

    // 0x800B48BC: ori         $t7, $t8, 0x8
    ctx->r15 = ctx->r24 | 0X8;
    // 0x800B48C0: sh          $t7, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r15;
L_800B48C4:
    // 0x800B48C4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B48C8: nop

    // 0x800B48CC: lhu         $t9, 0xA($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0XA);
    // 0x800B48D0: nop

    // 0x800B48D4: andi        $t1, $t9, 0x800
    ctx->r9 = ctx->r25 & 0X800;
    // 0x800B48D8: beq         $t1, $zero, L_800B4914
    if (ctx->r9 == 0) {
        // 0x800B48DC: nop

            goto L_800B4914;
    }
    // 0x800B48DC: nop

    // 0x800B48E0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B48E4: nop

    // 0x800B48E8: lbu         $t0, 0x0($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X0);
    // 0x800B48EC: nop

    // 0x800B48F0: andi        $t3, $t0, 0x4
    ctx->r11 = ctx->r8 & 0X4;
    // 0x800B48F4: beq         $t3, $zero, L_800B4914
    if (ctx->r11 == 0) {
        // 0x800B48F8: nop

            goto L_800B4914;
    }
    // 0x800B48F8: nop

    // 0x800B48FC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B4900: nop

    // 0x800B4904: lhu         $t8, 0x3A($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B4908: nop

    // 0x800B490C: ori         $t7, $t8, 0x80
    ctx->r15 = ctx->r24 | 0X80;
    // 0x800B4910: sh          $t7, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r15;
L_800B4914:
    // 0x800B4914: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4918: nop

    // 0x800B491C: lhu         $t4, 0xA($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0XA);
    // 0x800B4920: nop

    // 0x800B4924: andi        $t9, $t4, 0x4
    ctx->r25 = ctx->r12 & 0X4;
    // 0x800B4928: bne         $t9, $zero, L_800B49A0
    if (ctx->r25 != 0) {
        // 0x800B492C: nop

            goto L_800B49A0;
    }
    // 0x800B492C: nop

    // 0x800B4930: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B4934: nop

    // 0x800B4938: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800B493C: nop

    // 0x800B4940: andi        $t0, $t2, 0x1
    ctx->r8 = ctx->r10 & 0X1;
    // 0x800B4944: bne         $t0, $zero, L_800B4978
    if (ctx->r8 != 0) {
        // 0x800B4948: nop

            goto L_800B4978;
    }
    // 0x800B4948: nop

    // 0x800B494C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4950: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B4954: lb          $t8, 0xC($t3)
    ctx->r24 = MEM_B(ctx->r11, 0XC);
    // 0x800B4958: lwc1        $f8, 0xF4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x800B495C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B4960: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800B4964: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4968: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B496C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B4970: b           L_800B49A0
    // 0x800B4974: swc1        $f18, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f18.u32l;
        goto L_800B49A0;
    // 0x800B4974: swc1        $f18, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f18.u32l;
L_800B4978:
    // 0x800B4978: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B497C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800B4980: lb          $t6, 0xC($t5)
    ctx->r14 = MEM_B(ctx->r13, 0XC);
    // 0x800B4984: lwc1        $f8, 0xF4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x800B4988: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B498C: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B4990: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4994: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B4998: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B499C: swc1        $f18, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f18.u32l;
L_800B49A0:
    // 0x800B49A0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B49A4: nop

    // 0x800B49A8: lhu         $t1, 0xA($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0XA);
    // 0x800B49AC: nop

    // 0x800B49B0: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x800B49B4: bne         $t2, $zero, L_800B4A2C
    if (ctx->r10 != 0) {
        // 0x800B49B8: nop

            goto L_800B4A2C;
    }
    // 0x800B49B8: nop

    // 0x800B49BC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B49C0: nop

    // 0x800B49C4: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800B49C8: nop

    // 0x800B49CC: andi        $t8, $t3, 0x2
    ctx->r24 = ctx->r11 & 0X2;
    // 0x800B49D0: bne         $t8, $zero, L_800B4A04
    if (ctx->r24 != 0) {
        // 0x800B49D4: nop

            goto L_800B4A04;
    }
    // 0x800B49D4: nop

    // 0x800B49D8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B49DC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B49E0: lb          $t5, 0xD($t7)
    ctx->r13 = MEM_B(ctx->r15, 0XD);
    // 0x800B49E4: lwc1        $f8, 0xF8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XF8);
    // 0x800B49E8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B49EC: lwc1        $f16, 0xD0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x800B49F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B49F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B49F8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B49FC: b           L_800B4A2C
    // 0x800B4A00: swc1        $f18, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f18.u32l;
        goto L_800B4A2C;
    // 0x800B4A00: swc1        $f18, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f18.u32l;
L_800B4A04:
    // 0x800B4A04: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4A08: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B4A0C: lb          $t9, 0xD($t4)
    ctx->r25 = MEM_B(ctx->r12, 0XD);
    // 0x800B4A10: lwc1        $f8, 0xF8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x800B4A14: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B4A18: lwc1        $f10, 0xD0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x800B4A1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4A20: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B4A24: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B4A28: swc1        $f18, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f18.u32l;
L_800B4A2C:
    // 0x800B4A2C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4A30: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A34: lbu         $t3, 0x4($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X4);
    // 0x800B4A38: lwc1        $f4, 0x34($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800B4A3C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800B4A40: bgez        $t3, L_800B4A58
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B4A44: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800B4A58;
    }
    // 0x800B4A44: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B4A48: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B4A4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B4A50: nop

    // 0x800B4A54: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800B4A58:
    // 0x800B4A58: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B4A5C: swc1        $f16, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f16.u32l;
    // 0x800B4A60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4A64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A68: jal         0x800B4AB4
    // 0x800B4A6C: nop

    func_800B4AB4(rdram, ctx);
        goto after_0;
    // 0x800B4A6C: nop

    after_0:
    // 0x800B4A70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4A74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A78: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    // 0x800B4A7C: jal         0x800B4F68
    // 0x800B4A80: nop

    func_800B4F68(rdram, ctx);
        goto after_1;
    // 0x800B4A80: nop

    after_1:
    // 0x800B4A84: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A88: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x800B4A8C: lhu         $t7, 0x3A($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B4A90: nop

    // 0x800B4A94: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x800B4A98: sh          $t5, 0x3A($t8)
    MEM_H(0X3A, ctx->r24) = ctx->r13;
    // 0x800B4A9C: b           L_800B4AA4
    // 0x800B4AA0: nop

        goto L_800B4AA4;
    // 0x800B4AA0: nop

L_800B4AA4:
    // 0x800B4AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4AA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4AAC: jr          $ra
    // 0x800B4AB0: nop

    return;
    // 0x800B4AB0: nop

;}
RECOMP_FUNC void func_800B4AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4AB4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B4AB8: lbu         $t7, 0x30($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X30);
    // 0x800B4ABC: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x800B4AC0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B4AC4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B4AC8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B4ACC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B4AD0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B4AD4: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4AD8: nop

    // 0x800B4ADC: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x800B4AE0: beq         $t1, $zero, L_800B4AF8
    if (ctx->r9 == 0) {
        // 0x800B4AE4: nop

            goto L_800B4AF8;
    }
    // 0x800B4AE4: nop

    // 0x800B4AE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B4AEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B4AF0: b           L_800B4B20
    // 0x800B4AF4: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
        goto L_800B4B20;
    // 0x800B4AF4: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
L_800B4AF8:
    // 0x800B4AF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B4AFC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800B4B00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B4B04: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B4B08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4B0C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B4B10: nop

    // 0x800B4B14: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800B4B18: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B4B1C: swc1        $f18, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f18.u32l;
L_800B4B20:
    // 0x800B4B20: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800B4B24: nop

    // 0x800B4B28: lhu         $t3, 0xA($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XA);
    // 0x800B4B2C: nop

    // 0x800B4B30: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x800B4B34: beq         $t4, $zero, L_800B4B54
    if (ctx->r12 == 0) {
        // 0x800B4B38: nop

            goto L_800B4B54;
    }
    // 0x800B4B38: nop

    // 0x800B4B3C: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800B4B40: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B4B44: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B4B48: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B4B4C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B4B50: swc1        $f16, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f16.u32l;
L_800B4B54:
    // 0x800B4B54: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B4B58: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800B4B5C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B4B60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B4B64: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B4B68: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800B4B6C: nop

    // 0x800B4B70: bc1f        L_800B4B88
    if (!c1cs) {
        // 0x800B4B74: nop

            goto L_800B4B88;
    }
    // 0x800B4B74: nop

    // 0x800B4B78: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B4B7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B4B80: nop

    // 0x800B4B84: swc1        $f10, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f10.u32l;
L_800B4B88:
    // 0x800B4B88: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B4B8C: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800B4B90: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B4B94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B4B98: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800B4B9C: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x800B4BA0: nop

    // 0x800B4BA4: bc1f        L_800B4BBC
    if (!c1cs) {
        // 0x800B4BA8: nop

            goto L_800B4BBC;
    }
    // 0x800B4BA8: nop

    // 0x800B4BAC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800B4BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B4BB4: nop

    // 0x800B4BB8: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
L_800B4BBC:
    // 0x800B4BBC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800B4BC0: nop

    // 0x800B4BC4: lhu         $t7, 0xA($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0XA);
    // 0x800B4BC8: nop

    // 0x800B4BCC: andi        $t6, $t7, 0x20
    ctx->r14 = ctx->r15 & 0X20;
    // 0x800B4BD0: beq         $t6, $zero, L_800B4BF0
    if (ctx->r14 == 0) {
        // 0x800B4BD4: nop

            goto L_800B4BF0;
    }
    // 0x800B4BD4: nop

    // 0x800B4BD8: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800B4BDC: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B4BE0: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800B4BE4: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B4BE8: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800B4BEC: swc1        $f18, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f18.u32l;
L_800B4BF0:
    // 0x800B4BF0: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800B4BF4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800B4BF8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B4BFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4C00: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B4C04: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x800B4C08: nop

    // 0x800B4C0C: bc1f        L_800B4C24
    if (!c1cs) {
        // 0x800B4C10: nop

            goto L_800B4C24;
    }
    // 0x800B4C10: nop

    // 0x800B4C14: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B4C18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B4C1C: nop

    // 0x800B4C20: swc1        $f16, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f16.u32l;
L_800B4C24:
    // 0x800B4C24: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800B4C28: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800B4C2C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B4C30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B4C34: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800B4C38: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x800B4C3C: nop

    // 0x800B4C40: bc1f        L_800B4C58
    if (!c1cs) {
        // 0x800B4C44: nop

            goto L_800B4C58;
    }
    // 0x800B4C44: nop

    // 0x800B4C48: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800B4C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B4C50: nop

    // 0x800B4C54: swc1        $f6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f6.u32l;
L_800B4C58:
    // 0x800B4C58: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800B4C5C: nop

    // 0x800B4C60: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x800B4C64: nop

    // 0x800B4C68: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800B4C6C: beq         $t0, $zero, L_800B4C94
    if (ctx->r8 == 0) {
        // 0x800B4C70: nop

            goto L_800B4C94;
    }
    // 0x800B4C70: nop

    // 0x800B4C74: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B4C78: lwc1        $f16, 0x0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B4C7C: lwc1        $f18, 0xF4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x800B4C80: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B4C84: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x800B4C88: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B4C8C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B4C90: swc1        $f10, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f10.u32l;
L_800B4C94:
    // 0x800B4C94: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800B4C98: nop

    // 0x800B4C9C: lhu         $t2, 0xA($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XA);
    // 0x800B4CA0: nop

    // 0x800B4CA4: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x800B4CA8: beq         $t3, $zero, L_800B4CD0
    if (ctx->r11 == 0) {
        // 0x800B4CAC: nop

            goto L_800B4CD0;
    }
    // 0x800B4CAC: nop

    // 0x800B4CB0: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800B4CB4: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B4CB8: lwc1        $f6, 0xF8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x800B4CBC: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800B4CC0: lwc1        $f10, 0xD0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XD0);
    // 0x800B4CC4: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B4CC8: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B4CCC: swc1        $f16, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->f16.u32l;
L_800B4CD0:
    // 0x800B4CD0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800B4CD4: nop

    // 0x800B4CD8: lhu         $t5, 0xA($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XA);
    // 0x800B4CDC: nop

    // 0x800B4CE0: andi        $t7, $t5, 0x10
    ctx->r15 = ctx->r13 & 0X10;
    // 0x800B4CE4: beq         $t7, $zero, L_800B4E2C
    if (ctx->r15 == 0) {
        // 0x800B4CE8: nop

            goto L_800B4E2C;
    }
    // 0x800B4CE8: nop

    // 0x800B4CEC: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4CF0: nop

    // 0x800B4CF4: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800B4CF8: bne         $t8, $zero, L_800B4D18
    if (ctx->r24 != 0) {
        // 0x800B4CFC: nop

            goto L_800B4D18;
    }
    // 0x800B4CFC: nop

    // 0x800B4D00: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800B4D04: nop

    // 0x800B4D08: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x800B4D0C: nop

    // 0x800B4D10: bgtz        $t0, L_800B4D44
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B4D14: nop

            goto L_800B4D44;
    }
    // 0x800B4D14: nop

L_800B4D18:
    // 0x800B4D18: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D1C: nop

    // 0x800B4D20: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800B4D24: beq         $t2, $zero, L_800B4D8C
    if (ctx->r10 == 0) {
        // 0x800B4D28: nop

            goto L_800B4D8C;
    }
    // 0x800B4D28: nop

    // 0x800B4D2C: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800B4D30: nop

    // 0x800B4D34: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x800B4D38: nop

    // 0x800B4D3C: bgez        $t4, L_800B4D8C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B4D40: nop

            goto L_800B4D8C;
    }
    // 0x800B4D40: nop

L_800B4D44:
    // 0x800B4D44: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B4D48: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800B4D4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B4D50: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800B4D54: c.le.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d <= ctx->f6.d;
    // 0x800B4D58: nop

    // 0x800B4D5C: bc1f        L_800B4D8C
    if (!c1cs) {
        // 0x800B4D60: nop

            goto L_800B4D8C;
    }
    // 0x800B4D60: nop

    // 0x800B4D64: lhu         $t5, 0x3A($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X3A);
    // 0x800B4D68: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B4D6C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800B4D70: sh          $t7, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r15;
    // 0x800B4D74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4D78: nop

    // 0x800B4D7C: swc1        $f10, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f10.u32l;
    // 0x800B4D80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B4D84: nop

    // 0x800B4D88: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
L_800B4D8C:
    // 0x800B4D8C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D90: nop

    // 0x800B4D94: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800B4D98: bne         $t8, $zero, L_800B4DB8
    if (ctx->r24 != 0) {
        // 0x800B4D9C: nop

            goto L_800B4DB8;
    }
    // 0x800B4D9C: nop

    // 0x800B4DA0: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800B4DA4: nop

    // 0x800B4DA8: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x800B4DAC: nop

    // 0x800B4DB0: bltz        $t0, L_800B4DE4
    if (SIGNED(ctx->r8) < 0) {
        // 0x800B4DB4: nop

            goto L_800B4DE4;
    }
    // 0x800B4DB4: nop

L_800B4DB8:
    // 0x800B4DB8: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4DBC: nop

    // 0x800B4DC0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800B4DC4: beq         $t2, $zero, L_800B4E2C
    if (ctx->r10 == 0) {
        // 0x800B4DC8: nop

            goto L_800B4E2C;
    }
    // 0x800B4DC8: nop

    // 0x800B4DCC: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800B4DD0: nop

    // 0x800B4DD4: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x800B4DD8: nop

    // 0x800B4DDC: blez        $t4, L_800B4E2C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B4DE0: nop

            goto L_800B4E2C;
    }
    // 0x800B4DE0: nop

L_800B4DE4:
    // 0x800B4DE4: lwc1        $f16, 0x20($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B4DE8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800B4DEC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B4DF0: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x800B4DF4: c.le.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d <= ctx->f8.d;
    // 0x800B4DF8: nop

    // 0x800B4DFC: bc1f        L_800B4E2C
    if (!c1cs) {
        // 0x800B4E00: nop

            goto L_800B4E2C;
    }
    // 0x800B4E00: nop

    // 0x800B4E04: lhu         $t5, 0x3A($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X3A);
    // 0x800B4E08: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B4E0C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800B4E10: sh          $t7, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r15;
    // 0x800B4E14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B4E18: nop

    // 0x800B4E1C: swc1        $f6, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f6.u32l;
    // 0x800B4E20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4E24: nop

    // 0x800B4E28: swc1        $f10, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f10.u32l;
L_800B4E2C:
    // 0x800B4E2C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B4E30: nop

    // 0x800B4E34: lhu         $t8, 0xA($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0XA);
    // 0x800B4E38: nop

    // 0x800B4E3C: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x800B4E40: beq         $t9, $zero, L_800B4F58
    if (ctx->r25 == 0) {
        // 0x800B4E44: nop

            goto L_800B4F58;
    }
    // 0x800B4E44: nop

    // 0x800B4E48: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4E4C: nop

    // 0x800B4E50: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B4E54: bne         $t1, $zero, L_800B4E74
    if (ctx->r9 != 0) {
        // 0x800B4E58: nop

            goto L_800B4E74;
    }
    // 0x800B4E58: nop

    // 0x800B4E5C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800B4E60: nop

    // 0x800B4E64: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x800B4E68: nop

    // 0x800B4E6C: bgtz        $t3, L_800B4EA0
    if (SIGNED(ctx->r11) > 0) {
        // 0x800B4E70: nop

            goto L_800B4EA0;
    }
    // 0x800B4E70: nop

L_800B4E74:
    // 0x800B4E74: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4E78: nop

    // 0x800B4E7C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800B4E80: beq         $t5, $zero, L_800B4ED0
    if (ctx->r13 == 0) {
        // 0x800B4E84: nop

            goto L_800B4ED0;
    }
    // 0x800B4E84: nop

    // 0x800B4E88: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800B4E8C: nop

    // 0x800B4E90: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800B4E94: nop

    // 0x800B4E98: bgez        $t6, L_800B4ED0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B4E9C: nop

            goto L_800B4ED0;
    }
    // 0x800B4E9C: nop

L_800B4EA0:
    // 0x800B4EA0: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800B4EA4: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800B4EA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B4EAC: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800B4EB0: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x800B4EB4: nop

    // 0x800B4EB8: bc1f        L_800B4ED0
    if (!c1cs) {
        // 0x800B4EBC: nop

            goto L_800B4ED0;
    }
    // 0x800B4EBC: nop

    // 0x800B4EC0: lhu         $t8, 0x3A($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X3A);
    // 0x800B4EC4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800B4EC8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800B4ECC: sh          $t9, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r25;
L_800B4ED0:
    // 0x800B4ED0: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4ED4: nop

    // 0x800B4ED8: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B4EDC: bne         $t1, $zero, L_800B4EFC
    if (ctx->r9 != 0) {
        // 0x800B4EE0: nop

            goto L_800B4EFC;
    }
    // 0x800B4EE0: nop

    // 0x800B4EE4: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800B4EE8: nop

    // 0x800B4EEC: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x800B4EF0: nop

    // 0x800B4EF4: bltz        $t3, L_800B4F28
    if (SIGNED(ctx->r11) < 0) {
        // 0x800B4EF8: nop

            goto L_800B4F28;
    }
    // 0x800B4EF8: nop

L_800B4EFC:
    // 0x800B4EFC: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4F00: nop

    // 0x800B4F04: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800B4F08: beq         $t5, $zero, L_800B4F58
    if (ctx->r13 == 0) {
        // 0x800B4F0C: nop

            goto L_800B4F58;
    }
    // 0x800B4F0C: nop

    // 0x800B4F10: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800B4F14: nop

    // 0x800B4F18: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800B4F1C: nop

    // 0x800B4F20: blez        $t6, L_800B4F58
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B4F24: nop

            goto L_800B4F58;
    }
    // 0x800B4F24: nop

L_800B4F28:
    // 0x800B4F28: lwc1        $f18, 0x24($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800B4F2C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800B4F30: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4F34: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800B4F38: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x800B4F3C: nop

    // 0x800B4F40: bc1f        L_800B4F58
    if (!c1cs) {
        // 0x800B4F44: nop

            goto L_800B4F58;
    }
    // 0x800B4F44: nop

    // 0x800B4F48: lhu         $t8, 0x3A($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X3A);
    // 0x800B4F4C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800B4F50: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800B4F54: sh          $t9, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r25;
L_800B4F58:
    // 0x800B4F58: b           L_800B4F60
    // 0x800B4F5C: nop

        goto L_800B4F60;
    // 0x800B4F5C: nop

L_800B4F60:
    // 0x800B4F60: jr          $ra
    // 0x800B4F64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B4F64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B4F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4F68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B4F6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B4F70: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B4F74: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B4F78: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B4F7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B4F80: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B4F84: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B4F88: jal         0x800B5558
    // 0x800B4F8C: nop

    func_800B5558(rdram, ctx);
        goto after_0;
    // 0x800B4F8C: nop

    after_0:
    // 0x800B4F90: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B4F94: nop

    // 0x800B4F98: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x800B4F9C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800B4FA0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B4FA4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B4FA8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800B4FAC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B4FB0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800B4FB4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4FB8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800B4FBC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800B4FC0: lw          $t4, 0xD40($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD40);
    // 0x800B4FC4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B4FC8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B4FCC: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B4FD0: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B4FD4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B4FD8: jal         0x800BD1FC
    // 0x800B4FDC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x800B4FDC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x800B4FE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_800B4FE4:
    // 0x800B4FE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800B4FE8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800B4FEC: jal         0x800BD218
    // 0x800B4FF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800B4FF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800B4FF4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B4FF8: nop

    // 0x800B4FFC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800B5000: bne         $t6, $zero, L_800B5010
    if (ctx->r14 != 0) {
        // 0x800B5004: nop

            goto L_800B5010;
    }
    // 0x800B5004: nop

    // 0x800B5008: b           L_800B5018
    // 0x800B500C: nop

        goto L_800B5018;
    // 0x800B500C: nop

L_800B5010:
    // 0x800B5010: b           L_800B4FE4
    // 0x800B5014: nop

        goto L_800B4FE4;
    // 0x800B5014: nop

L_800B5018:
    // 0x800B5018: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800B501C: nop

    // 0x800B5020: sh          $zero, 0x114($t8)
    MEM_H(0X114, ctx->r24) = 0;
    // 0x800B5024: lbu         $t7, 0x38($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X38);
    // 0x800B5028: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B502C: nop

    // 0x800B5030: sh          $t7, 0x100($t9)
    MEM_H(0X100, ctx->r25) = ctx->r15;
    // 0x800B5034: lbu         $t0, 0x39($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X39);
    // 0x800B5038: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B503C: nop

    // 0x800B5040: sh          $t0, 0x102($t1)
    MEM_H(0X102, ctx->r9) = ctx->r8;
    // 0x800B5044: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B5048: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B504C: lhu         $t3, 0xA($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XA);
    // 0x800B5050: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800B5054: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800B5058: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800B505C: xor         $t7, $t4, $t8
    ctx->r15 = ctx->r12 ^ ctx->r24;
    // 0x800B5060: beq         $t7, $zero, L_800B5084
    if (ctx->r15 == 0) {
        // 0x800B5064: nop

            goto L_800B5084;
    }
    // 0x800B5064: nop

    // 0x800B5068: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B506C: nop

    // 0x800B5070: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800B5074: nop

    // 0x800B5078: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800B507C: b           L_800B509C
    // 0x800B5080: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
        goto L_800B509C;
    // 0x800B5080: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
L_800B5084:
    // 0x800B5084: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800B5088: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B508C: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800B5090: nop

    // 0x800B5094: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800B5098: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
L_800B509C:
    // 0x800B509C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B50A0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B50A4: lhu         $t4, 0xA($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0XA);
    // 0x800B50A8: lbu         $t0, 0x0($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X0);
    // 0x800B50AC: andi        $t8, $t4, 0x2
    ctx->r24 = ctx->r12 & 0X2;
    // 0x800B50B0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B50B4: xor         $t9, $t8, $t1
    ctx->r25 = ctx->r24 ^ ctx->r9;
    // 0x800B50B8: beq         $t9, $zero, L_800B50DC
    if (ctx->r25 == 0) {
        // 0x800B50BC: nop

            goto L_800B50DC;
    }
    // 0x800B50BC: nop

    // 0x800B50C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B50C4: nop

    // 0x800B50C8: lw          $t5, 0xC0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC0);
    // 0x800B50CC: nop

    // 0x800B50D0: ori         $t2, $t5, 0x2
    ctx->r10 = ctx->r13 | 0X2;
    // 0x800B50D4: b           L_800B50F4
    // 0x800B50D8: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
        goto L_800B50F4;
    // 0x800B50D8: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
L_800B50DC:
    // 0x800B50DC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800B50E0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800B50E4: lw          $t4, 0xC0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XC0);
    // 0x800B50E8: nop

    // 0x800B50EC: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x800B50F0: sw          $t7, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r15;
L_800B50F4:
    // 0x800B50F4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B50F8: nop

    // 0x800B50FC: lhu         $t8, 0xA($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0XA);
    // 0x800B5100: nop

    // 0x800B5104: andi        $t1, $t8, 0x400
    ctx->r9 = ctx->r24 & 0X400;
    // 0x800B5108: beq         $t1, $zero, L_800B512C
    if (ctx->r9 == 0) {
        // 0x800B510C: nop

            goto L_800B512C;
    }
    // 0x800B510C: nop

    // 0x800B5110: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B5114: nop

    // 0x800B5118: lw          $t5, 0xC0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC0);
    // 0x800B511C: nop

    // 0x800B5120: ori         $t2, $t5, 0x80
    ctx->r10 = ctx->r13 | 0X80;
    // 0x800B5124: b           L_800B5144
    // 0x800B5128: sw          $t2, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r10;
        goto L_800B5144;
    // 0x800B5128: sw          $t2, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r10;
L_800B512C:
    // 0x800B512C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B5130: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800B5134: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x800B5138: nop

    // 0x800B513C: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x800B5140: sw          $t7, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r15;
L_800B5144:
    // 0x800B5144: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B5148: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B514C: sh          $t6, 0x116($t0)
    MEM_H(0X116, ctx->r8) = ctx->r14;
    // 0x800B5150: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B5154: lhu         $t8, 0xD54($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XD54);
    // 0x800B5158: nop

    // 0x800B515C: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x800B5160: beq         $t1, $zero, L_800B5184
    if (ctx->r9 == 0) {
        // 0x800B5164: nop

            goto L_800B5184;
    }
    // 0x800B5164: nop

    // 0x800B5168: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800B516C: nop

    // 0x800B5170: lw          $t2, 0xC0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC0);
    // 0x800B5174: nop

    // 0x800B5178: ori         $t9, $t2, 0x100
    ctx->r25 = ctx->r10 | 0X100;
    // 0x800B517C: b           L_800B519C
    // 0x800B5180: sw          $t9, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r25;
        goto L_800B519C;
    // 0x800B5180: sw          $t9, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r25;
L_800B5184:
    // 0x800B5184: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800B5188: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B518C: lw          $t7, 0xC0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC0);
    // 0x800B5190: nop

    // 0x800B5194: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x800B5198: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
L_800B519C:
    // 0x800B519C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B51A0: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B51A4: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800B51A8: lhu         $t1, 0x10($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X10);
    // 0x800B51AC: nop

    // 0x800B51B0: beq         $t0, $t1, L_800B5374
    if (ctx->r8 == ctx->r9) {
        // 0x800B51B4: nop

            goto L_800B5374;
    }
    // 0x800B51B4: nop

    // 0x800B51B8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B51BC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800B51C0: lbu         $t5, 0x3C($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X3C);
    // 0x800B51C4: nop

    // 0x800B51C8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B51CC: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x800B51D0: addiu       $t4, $t3, 0x12C
    ctx->r12 = ADD32(ctx->r11, 0X12C);
    // 0x800B51D4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B51D8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B51DC: nop

    // 0x800B51E0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B51E4: nop

    // 0x800B51E8: beq         $t8, $zero, L_800B5204
    if (ctx->r24 == 0) {
        // 0x800B51EC: nop

            goto L_800B5204;
    }
    // 0x800B51EC: nop

    // 0x800B51F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B51F4: nop

    // 0x800B51F8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B51FC: jal         0x800BC980
    // 0x800B5200: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800B5200: nop

    after_3:
L_800B5204:
    // 0x800B5204: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B5208: lhu         $t1, 0xD54($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XD54);
    // 0x800B520C: nop

    // 0x800B5210: andi        $t9, $t1, 0x2
    ctx->r25 = ctx->r9 & 0X2;
    // 0x800B5214: beq         $t9, $zero, L_800B52D8
    if (ctx->r25 == 0) {
        // 0x800B5218: nop

            goto L_800B52D8;
    }
    // 0x800B5218: nop

    // 0x800B521C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800B5220: lw          $t5, 0xD44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD44);
    // 0x800B5224: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B5228: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B522C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B5230: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B5234: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B5238: jal         0x800BD1FC
    // 0x800B523C: addu        $a2, $t5, $t2
    ctx->r6 = ADD32(ctx->r13, ctx->r10);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800B523C: addu        $a2, $t5, $t2
    ctx->r6 = ADD32(ctx->r13, ctx->r10);
    after_4:
    // 0x800B5240: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B5244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B5248: jal         0x800BED70
    // 0x800B524C: nop

    Spi_GetHeader(rdram, ctx);
        goto after_5;
    // 0x800B524C: nop

    after_5:
    // 0x800B5250: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B5254: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B5258: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x800B525C: jal         0x800BC6EC
    // 0x800B5260: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800B5260: nop

    after_6:
    // 0x800B5264: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5268: nop

    // 0x800B526C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800B5270: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5274: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B5278: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B527C: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x800B5280: jal         0x800BF0B4
    // 0x800B5284: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_7;
    // 0x800B5284: nop

    after_7:
    // 0x800B5288: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B528C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800B5290: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800B5294: nop

    // 0x800B5298: sw          $t6, 0x128($t8)
    MEM_W(0X128, ctx->r24) = ctx->r14;
    // 0x800B529C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800B52A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B52A4: lbu         $t1, 0x3C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3C);
    // 0x800B52A8: nop

    // 0x800B52AC: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800B52B0: sb          $t9, 0x3C($t0)
    MEM_B(0X3C, ctx->r8) = ctx->r25;
    // 0x800B52B4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B52B8: nop

    // 0x800B52BC: lbu         $t2, 0x3C($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X3C);
    // 0x800B52C0: nop

    // 0x800B52C4: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x800B52C8: mfhi        $t7
    ctx->r15 = hi;
    // 0x800B52CC: sb          $t7, 0x3C($t5)
    MEM_B(0X3C, ctx->r13) = ctx->r15;
    // 0x800B52D0: b           L_800B5360
    // 0x800B52D4: nop

        goto L_800B5360;
    // 0x800B52D4: nop

L_800B52D8:
    // 0x800B52D8: lbu         $t3, 0x38($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X38);
    // 0x800B52DC: lbu         $t4, 0x39($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X39);
    // 0x800B52E0: nop

    // 0x800B52E4: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B52E8: mflo        $a0
    ctx->r4 = lo;
    // 0x800B52EC: jal         0x800BC6EC
    // 0x800B52F0: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800B52F0: nop

    after_8:
    // 0x800B52F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B52F8: nop

    // 0x800B52FC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800B5300: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B5304: lw          $t8, 0xD44($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD44);
    // 0x800B5308: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B530C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B5310: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B5314: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B5318: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B531C: jal         0x800BD1FC
    // 0x800B5320: addu        $a2, $t8, $t1
    ctx->r6 = ADD32(ctx->r24, ctx->r9);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_9;
    // 0x800B5320: addu        $a2, $t8, $t1
    ctx->r6 = ADD32(ctx->r24, ctx->r9);
    after_9:
    // 0x800B5324: lbu         $t0, 0x38($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X38);
    // 0x800B5328: lbu         $t2, 0x39($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X39);
    // 0x800B532C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5330: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5334: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B5338: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800B533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B5340: mflo        $a2
    ctx->r6 = lo;
    // 0x800B5344: jal         0x800BD218
    // 0x800B5348: nop

    SysMem_DmaCopy(rdram, ctx);
        goto after_10;
    // 0x800B5348: nop

    after_10:
    // 0x800B534C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5350: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B5354: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x800B5358: nop

    // 0x800B535C: sw          $t5, 0x128($t3)
    MEM_W(0X128, ctx->r11) = ctx->r13;
L_800B5360:
    // 0x800B5360: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B5364: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B5368: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x800B536C: nop

    // 0x800B5370: sh          $t6, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r14;
L_800B5374:
    // 0x800B5374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B5378: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B537C: lhu         $a2, 0x4A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X4A);
    // 0x800B5380: jal         0x800B53A0
    // 0x800B5384: nop

    LoadPalette(rdram, ctx);
        goto after_11;
    // 0x800B5384: nop

    after_11:
    // 0x800B5388: b           L_800B5390
    // 0x800B538C: nop

        goto L_800B5390;
    // 0x800B538C: nop

L_800B5390:
    // 0x800B5390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5398: jr          $ra
    // 0x800B539C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B539C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void LoadPalette(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B53A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B53A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B53A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B53AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B53B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B53B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B53B8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B53BC: lhu         $t8, 0x32($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X32);
    // 0x800B53C0: lhu         $t7, 0x12($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12);
    // 0x800B53C4: nop

    // 0x800B53C8: beq         $t7, $t8, L_800B5540
    if (ctx->r15 == ctx->r24) {
        // 0x800B53CC: nop

            goto L_800B5540;
    }
    // 0x800B53CC: nop

    // 0x800B53D0: lhu         $t9, 0x32($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X32);
    // 0x800B53D4: nop

    // 0x800B53D8: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800B53DC: bne         $t0, $zero, L_800B5500
    if (ctx->r8 != 0) {
        // 0x800B53E0: nop

            goto L_800B5500;
    }
    // 0x800B53E0: nop

    // 0x800B53E4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B53E8: nop

    // 0x800B53EC: lbu         $t2, 0x3D($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X3D);
    // 0x800B53F0: nop

    // 0x800B53F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B53F8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800B53FC: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x800B5400: nop

    // 0x800B5404: beq         $t5, $zero, L_800B5430
    if (ctx->r13 == 0) {
        // 0x800B5408: nop

            goto L_800B5430;
    }
    // 0x800B5408: nop

    // 0x800B540C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5410: nop

    // 0x800B5414: lbu         $t7, 0x3D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3D);
    // 0x800B5418: nop

    // 0x800B541C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B5420: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B5424: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x800B5428: jal         0x800BC980
    // 0x800B542C: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800B542C: nop

    after_0:
L_800B5430:
    // 0x800B5430: jal         0x800BC6EC
    // 0x800B5434: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800B5434: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_1:
    // 0x800B5438: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B543C: nop

    // 0x800B5440: lbu         $t2, 0x3D($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X3D);
    // 0x800B5444: nop

    // 0x800B5448: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x800B544C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800B5450: sw          $v0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r2;
    // 0x800B5454: lhu         $t4, 0x32($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X32);
    // 0x800B5458: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B545C: lw          $t7, 0xD48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD48);
    // 0x800B5460: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B5464: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B5468: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B546C: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B5470: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x800B5474: jal         0x800BD1FC
    // 0x800B5478: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B5478: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    after_2:
    // 0x800B547C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5480: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B5484: lbu         $t8, 0x3D($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X3D);
    // 0x800B5488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B548C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B5490: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x800B5494: lw          $a1, 0x14($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X14);
    // 0x800B5498: jal         0x800BD218
    // 0x800B549C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B549C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_3:
    // 0x800B54A0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B54A4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800B54A8: lbu         $t1, 0x3D($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3D);
    // 0x800B54AC: nop

    // 0x800B54B0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B54B4: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800B54B8: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x800B54BC: nop

    // 0x800B54C0: sw          $t5, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r13;
    // 0x800B54C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B54C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B54CC: lbu         $t6, 0x3D($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X3D);
    // 0x800B54D0: nop

    // 0x800B54D4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800B54D8: sb          $t9, 0x3D($t8)
    MEM_B(0X3D, ctx->r24) = ctx->r25;
    // 0x800B54DC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B54E0: nop

    // 0x800B54E4: lbu         $t1, 0x3D($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X3D);
    // 0x800B54E8: nop

    // 0x800B54EC: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800B54F0: mfhi        $t0
    ctx->r8 = hi;
    // 0x800B54F4: sb          $t0, 0x3D($t2)
    MEM_B(0X3D, ctx->r10) = ctx->r8;
    // 0x800B54F8: b           L_800B5530
    // 0x800B54FC: nop

        goto L_800B5530;
    // 0x800B54FC: nop

L_800B5500:
    // 0x800B5500: lhu         $t5, 0x32($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X32);
    // 0x800B5504: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800B5508: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800B550C: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x800B5510: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800B5514: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800B5518: lw          $t4, 0x138($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X138);
    // 0x800B551C: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800B5520: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B5524: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800B5528: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x800B552C: sw          $t8, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r24;
L_800B5530:
    // 0x800B5530: lhu         $t0, 0x32($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X32);
    // 0x800B5534: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5538: nop

    // 0x800B553C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
L_800B5540:
    // 0x800B5540: b           L_800B5548
    // 0x800B5544: nop

        goto L_800B5548;
    // 0x800B5544: nop

L_800B5548:
    // 0x800B5548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B554C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5550: jr          $ra
    // 0x800B5554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B5554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B5558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5558: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B555C: lbu         $t7, 0x30($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X30);
    // 0x800B5560: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x800B5564: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B5568: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B556C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B5570: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B5574: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B5578: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800B557C: nop

    // 0x800B5580: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x800B5584: nop

    // 0x800B5588: sw          $t1, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r9;
    // 0x800B558C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800B5590: nop

    // 0x800B5594: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x800B5598: nop

    // 0x800B559C: sw          $t3, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->r11;
    // 0x800B55A0: b           L_800B55A8
    // 0x800B55A4: nop

        goto L_800B55A8;
    // 0x800B55A4: nop

L_800B55A8:
    // 0x800B55A8: jr          $ra
    // 0x800B55AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B55AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B55B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B55B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B55B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B55B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B55BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B55C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B55C4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B55C8: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B55CC: nop

    // 0x800B55D0: bne         $t6, $zero, L_800B55E8
    if (ctx->r14 != 0) {
        // 0x800B55D4: nop

            goto L_800B55E8;
    }
    // 0x800B55D4: nop

    // 0x800B55D8: jal         0x8000D164
    // 0x800B55DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    TempHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x800B55DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800B55E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B55E4: sw          $v0, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = ctx->r2;
L_800B55E8:
    // 0x800B55E8: ori         $t7, $zero, 0xC002
    ctx->r15 = 0 | 0XC002;
    // 0x800B55EC: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B55F0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800B55F4: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x800B55F8: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B55FC: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x800B5600: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x800B5604: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x800B5608: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x800B560C: lhu         $s1, 0xA($t2)
    ctx->r17 = MEM_HU(ctx->r10, 0XA);
    // 0x800B5610: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x800B5614: sh          $s1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r17;
    // 0x800B5618: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800B561C: sh          $s0, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r16;
    // 0x800B5620: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x800B5624: sh          $s0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r16;
    // 0x800B5628: jal         0x800B6A00
    // 0x800B562C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800B6A00(rdram, ctx);
        goto after_1;
    // 0x800B562C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x800B5630: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800B5634: beq         $at, $zero, L_800B5644
    if (ctx->r1 == 0) {
        // 0x800B5638: nop

            goto L_800B5644;
    }
    // 0x800B5638: nop

    // 0x800B563C: b           L_800B56DC
    // 0x800B5640: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B56DC;
    // 0x800B5640: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B5644:
    // 0x800B5644: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5648: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B564C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B5650: nop

    // 0x800B5654: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800B5658: jal         0x800B8398
    // 0x800B565C: nop

    func_800B8398(rdram, ctx);
        goto after_2;
    // 0x800B565C: nop

    after_2:
    // 0x800B5660: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5664: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5668: nop

    // 0x800B566C: sh          $v0, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r2;
    // 0x800B5670: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5674: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5678: nop

    // 0x800B567C: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x800B5680: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B5684: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B5688: nop

    // 0x800B568C: sh          $zero, 0x8($t9)
    MEM_H(0X8, ctx->r25) = 0;
    // 0x800B5690: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5694: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5698: nop

    // 0x800B569C: sh          $zero, 0xA($t0)
    MEM_H(0XA, ctx->r8) = 0;
    // 0x800B56A0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B56A4: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B56A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B56AC: nop

    // 0x800B56B0: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x800B56B4: jal         0x800B5730
    // 0x800B56B8: nop

    func_800B5730(rdram, ctx);
        goto after_3;
    // 0x800B56B8: nop

    after_3:
    // 0x800B56BC: beq         $v0, $zero, L_800B56CC
    if (ctx->r2 == 0) {
        // 0x800B56C0: nop

            goto L_800B56CC;
    }
    // 0x800B56C0: nop

    // 0x800B56C4: b           L_800B56DC
    // 0x800B56C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B56DC;
    // 0x800B56C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B56CC:
    // 0x800B56CC: b           L_800B56DC
    // 0x800B56D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B56DC;
    // 0x800B56D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B56D4: b           L_800B56DC
    // 0x800B56D8: nop

        goto L_800B56DC;
    // 0x800B56D8: nop

L_800B56DC:
    // 0x800B56DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B56E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B56E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B56E8: jr          $ra
    // 0x800B56EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B56EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B56F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B56F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B56F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B56F8: jal         0x800B5730
    // 0x800B56FC: nop

    func_800B5730(rdram, ctx);
        goto after_0;
    // 0x800B56FC: nop

    after_0:
    // 0x800B5700: beq         $v0, $zero, L_800B5710
    if (ctx->r2 == 0) {
        // 0x800B5704: nop

            goto L_800B5710;
    }
    // 0x800B5704: nop

    // 0x800B5708: b           L_800B5720
    // 0x800B570C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B5720;
    // 0x800B570C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B5710:
    // 0x800B5710: b           L_800B5720
    // 0x800B5714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5720;
    // 0x800B5714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5718: b           L_800B5720
    // 0x800B571C: nop

        goto L_800B5720;
    // 0x800B571C: nop

L_800B5720:
    // 0x800B5720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B5728: jr          $ra
    // 0x800B572C: nop

    return;
    // 0x800B572C: nop

;}
RECOMP_FUNC void func_800B5730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5738: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B573C: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5740: nop

    // 0x800B5744: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B5748: nop

    // 0x800B574C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800B5750: beq         $t8, $zero, L_800B5768
    if (ctx->r24 == 0) {
        // 0x800B5754: nop

            goto L_800B5768;
    }
    // 0x800B5754: nop

    // 0x800B5758: jal         0x80031728
    // 0x800B575C: nop

    func_80031728(rdram, ctx);
        goto after_0;
    // 0x800B575C: nop

    after_0:
    // 0x800B5760: b           L_800B57A0
    // 0x800B5764: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B57A0;
    // 0x800B5764: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B5768:
    // 0x800B5768: jal         0x800B57B0
    // 0x800B576C: nop

    func_800B57B0(rdram, ctx);
        goto after_1;
    // 0x800B576C: nop

    after_1:
    // 0x800B5770: jal         0x800B5AA0
    // 0x800B5774: nop

    func_800B5AA0(rdram, ctx);
        goto after_2;
    // 0x800B5774: nop

    after_2:
    // 0x800B5778: jal         0x800B5AF0
    // 0x800B577C: nop

    func_800B5AF0(rdram, ctx);
        goto after_3;
    // 0x800B577C: nop

    after_3:
    // 0x800B5780: beq         $v0, $zero, L_800B5790
    if (ctx->r2 == 0) {
        // 0x800B5784: nop

            goto L_800B5790;
    }
    // 0x800B5784: nop

    // 0x800B5788: jal         0x800B5FB4
    // 0x800B578C: nop

    func_800B5FB4(rdram, ctx);
        goto after_4;
    // 0x800B578C: nop

    after_4:
L_800B5790:
    // 0x800B5790: b           L_800B57A0
    // 0x800B5794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B57A0;
    // 0x800B5794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5798: b           L_800B57A0
    // 0x800B579C: nop

        goto L_800B57A0;
    // 0x800B579C: nop

L_800B57A0:
    // 0x800B57A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B57A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B57A8: jr          $ra
    // 0x800B57AC: nop

    return;
    // 0x800B57AC: nop

;}
RECOMP_FUNC void func_800B57B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B57B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B57B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B57B8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B57BC: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B57C0: nop

    // 0x800B57C4: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B57C8: nop

    // 0x800B57CC: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800B57D0: beq         $t8, $zero, L_800B586C
    if (ctx->r24 == 0) {
        // 0x800B57D4: nop

            goto L_800B586C;
    }
    // 0x800B57D4: nop

    // 0x800B57D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B57DC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800B57E0: jal         0x80016074
    // 0x800B57E4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800B57E4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x800B57E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B57EC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B57F0: nop

    // 0x800B57F4: beq         $t0, $zero, L_800B581C
    if (ctx->r8 == 0) {
        // 0x800B57F8: nop

            goto L_800B581C;
    }
    // 0x800B57F8: nop

    // 0x800B57FC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B5800: nop

    // 0x800B5804: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x800B5808: nop

    // 0x800B580C: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800B5810: bne         $t3, $zero, L_800B581C
    if (ctx->r11 != 0) {
        // 0x800B5814: nop

            goto L_800B581C;
    }
    // 0x800B5814: nop

    // 0x800B5818: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800B581C:
    // 0x800B581C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800B5820: nop

    // 0x800B5824: beq         $t4, $zero, L_800B586C
    if (ctx->r12 == 0) {
        // 0x800B5828: nop

            goto L_800B586C;
    }
    // 0x800B5828: nop

    // 0x800B582C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B5830: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B5834: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800B5838: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x800B583C: nop

    // 0x800B5840: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800B5844: sh          $t7, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r15;
    // 0x800B5848: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B584C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B5850: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
    // 0x800B5854: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B5858: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800B585C: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x800B5860: nop

    // 0x800B5864: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x800B5868: sh          $t1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r9;
L_800B586C:
    // 0x800B586C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B5870: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B5874: nop

    // 0x800B5878: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x800B587C: nop

    // 0x800B5880: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x800B5884: beq         $t4, $zero, L_800B5920
    if (ctx->r12 == 0) {
        // 0x800B5888: nop

            goto L_800B5920;
    }
    // 0x800B5888: nop

    // 0x800B588C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B5890: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800B5894: jal         0x80016074
    // 0x800B5898: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80016074(rdram, ctx);
        goto after_1;
    // 0x800B5898: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x800B589C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B58A0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B58A4: nop

    // 0x800B58A8: beq         $t7, $zero, L_800B58D0
    if (ctx->r15 == 0) {
        // 0x800B58AC: nop

            goto L_800B58D0;
    }
    // 0x800B58AC: nop

    // 0x800B58B0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B58B4: nop

    // 0x800B58B8: lw          $t8, 0x1A8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1A8);
    // 0x800B58BC: nop

    // 0x800B58C0: andi        $t0, $t8, 0x2
    ctx->r8 = ctx->r24 & 0X2;
    // 0x800B58C4: bne         $t0, $zero, L_800B58D0
    if (ctx->r8 != 0) {
        // 0x800B58C8: nop

            goto L_800B58D0;
    }
    // 0x800B58C8: nop

    // 0x800B58CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800B58D0:
    // 0x800B58D0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B58D4: nop

    // 0x800B58D8: beq         $t1, $zero, L_800B5920
    if (ctx->r9 == 0) {
        // 0x800B58DC: nop

            goto L_800B5920;
    }
    // 0x800B58DC: nop

    // 0x800B58E0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B58E4: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B58E8: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800B58EC: lhu         $t2, 0x4($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X4);
    // 0x800B58F0: nop

    // 0x800B58F4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800B58F8: sh          $t3, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r11;
    // 0x800B58FC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B5900: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B5904: sw          $t4, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r12;
    // 0x800B5908: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B590C: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800B5910: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800B5914: nop

    // 0x800B5918: ori         $t5, $t7, 0x8
    ctx->r13 = ctx->r15 | 0X8;
    // 0x800B591C: sh          $t5, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r13;
L_800B5920:
    // 0x800B5920: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5924: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5928: nop

    // 0x800B592C: lhu         $t0, 0x4($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X4);
    // 0x800B5930: nop

    // 0x800B5934: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x800B5938: beq         $t1, $zero, L_800B59D4
    if (ctx->r9 == 0) {
        // 0x800B593C: nop

            goto L_800B59D4;
    }
    // 0x800B593C: nop

    // 0x800B5940: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B5944: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800B5948: jal         0x80016074
    // 0x800B594C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_2;
    // 0x800B594C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x800B5950: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B5954: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B5958: nop

    // 0x800B595C: beq         $t3, $zero, L_800B5984
    if (ctx->r11 == 0) {
        // 0x800B5960: nop

            goto L_800B5984;
    }
    // 0x800B5960: nop

    // 0x800B5964: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B5968: nop

    // 0x800B596C: lw          $t4, 0x1A8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X1A8);
    // 0x800B5970: nop

    // 0x800B5974: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x800B5978: bne         $t7, $zero, L_800B5984
    if (ctx->r15 != 0) {
        // 0x800B597C: nop

            goto L_800B5984;
    }
    // 0x800B597C: nop

    // 0x800B5980: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800B5984:
    // 0x800B5984: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800B5988: nop

    // 0x800B598C: beq         $t5, $zero, L_800B59D4
    if (ctx->r13 == 0) {
        // 0x800B5990: nop

            goto L_800B59D4;
    }
    // 0x800B5990: nop

    // 0x800B5994: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5998: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B599C: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800B59A0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800B59A4: nop

    // 0x800B59A8: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800B59AC: sh          $t0, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r8;
    // 0x800B59B0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800B59B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B59B8: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
    // 0x800B59BC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B59C0: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800B59C4: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800B59C8: nop

    // 0x800B59CC: ori         $t9, $t3, 0x8
    ctx->r25 = ctx->r11 | 0X8;
    // 0x800B59D0: sh          $t9, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r25;
L_800B59D4:
    // 0x800B59D4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B59D8: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B59DC: nop

    // 0x800B59E0: lhu         $t7, 0x4($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X4);
    // 0x800B59E4: nop

    // 0x800B59E8: andi        $t5, $t7, 0x80
    ctx->r13 = ctx->r15 & 0X80;
    // 0x800B59EC: beq         $t5, $zero, L_800B5A88
    if (ctx->r13 == 0) {
        // 0x800B59F0: nop

            goto L_800B5A88;
    }
    // 0x800B59F0: nop

    // 0x800B59F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B59F8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B59FC: jal         0x80016074
    // 0x800B5A00: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_3;
    // 0x800B5A00: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x800B5A04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B5A08: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B5A0C: nop

    // 0x800B5A10: beq         $t0, $zero, L_800B5A38
    if (ctx->r8 == 0) {
        // 0x800B5A14: nop

            goto L_800B5A38;
    }
    // 0x800B5A14: nop

    // 0x800B5A18: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B5A1C: nop

    // 0x800B5A20: lw          $t1, 0x1A8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X1A8);
    // 0x800B5A24: nop

    // 0x800B5A28: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x800B5A2C: bne         $t3, $zero, L_800B5A38
    if (ctx->r11 != 0) {
        // 0x800B5A30: nop

            goto L_800B5A38;
    }
    // 0x800B5A30: nop

    // 0x800B5A34: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800B5A38:
    // 0x800B5A38: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B5A3C: nop

    // 0x800B5A40: beq         $t9, $zero, L_800B5A88
    if (ctx->r25 == 0) {
        // 0x800B5A44: nop

            goto L_800B5A88;
    }
    // 0x800B5A44: nop

    // 0x800B5A48: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B5A4C: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B5A50: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800B5A54: lhu         $t4, 0x4($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X4);
    // 0x800B5A58: nop

    // 0x800B5A5C: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x800B5A60: sh          $t7, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r15;
    // 0x800B5A64: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B5A68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B5A6C: sw          $t5, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r13;
    // 0x800B5A70: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B5A74: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800B5A78: lhu         $t0, 0x2($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X2);
    // 0x800B5A7C: nop

    // 0x800B5A80: ori         $t6, $t0, 0x8
    ctx->r14 = ctx->r8 | 0X8;
    // 0x800B5A84: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
L_800B5A88:
    // 0x800B5A88: b           L_800B5A90
    // 0x800B5A8C: nop

        goto L_800B5A90;
    // 0x800B5A8C: nop

L_800B5A90:
    // 0x800B5A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5A94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B5A98: jr          $ra
    // 0x800B5A9C: nop

    return;
    // 0x800B5A9C: nop

;}
RECOMP_FUNC void func_800B5AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5AA0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5AA4: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5AA8: nop

    // 0x800B5AAC: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B5AB0: nop

    // 0x800B5AB4: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x800B5AB8: beq         $t8, $zero, L_800B5AE0
    if (ctx->r24 == 0) {
        // 0x800B5ABC: nop

            goto L_800B5AE0;
    }
    // 0x800B5ABC: nop

    // 0x800B5AC0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800B5AC4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B5AC8: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x800B5ACC: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x800B5AD0: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x800B5AD4: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x800B5AD8: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x800B5ADC: sh          $t3, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r11;
L_800B5AE0:
    // 0x800B5AE0: jr          $ra
    // 0x800B5AE4: nop

    return;
    // 0x800B5AE4: nop

    // 0x800B5AE8: jr          $ra
    // 0x800B5AEC: nop

    return;
    // 0x800B5AEC: nop

;}
RECOMP_FUNC void func_800B5AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5AF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B5AF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B5AF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5AFC: jal         0x800B8104
    // 0x800B5B00: nop

    func_800B8104(rdram, ctx);
        goto after_0;
    // 0x800B5B00: nop

    after_0:
    // 0x800B5B04: beq         $v0, $zero, L_800B5B14
    if (ctx->r2 == 0) {
        // 0x800B5B08: nop

            goto L_800B5B14;
    }
    // 0x800B5B08: nop

    // 0x800B5B0C: b           L_800B5E80
    // 0x800B5B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5E80;
    // 0x800B5B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5B14:
    // 0x800B5B14: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5B18: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5B1C: ori         $at, $zero, 0xE000
    ctx->r1 = 0 | 0XE000;
    // 0x800B5B20: lhu         $s0, 0x6($t6)
    ctx->r16 = MEM_HU(ctx->r14, 0X6);
    // 0x800B5B24: nop

    // 0x800B5B28: beq         $s0, $at, L_800B5B50
    if (ctx->r16 == ctx->r1) {
        // 0x800B5B2C: nop

            goto L_800B5B50;
    }
    // 0x800B5B2C: nop

    // 0x800B5B30: ori         $at, $zero, 0xE006
    ctx->r1 = 0 | 0XE006;
    // 0x800B5B34: beq         $s0, $at, L_800B5DE8
    if (ctx->r16 == ctx->r1) {
        // 0x800B5B38: nop

            goto L_800B5DE8;
    }
    // 0x800B5B38: nop

    // 0x800B5B3C: ori         $at, $zero, 0xE011
    ctx->r1 = 0 | 0XE011;
    // 0x800B5B40: beq         $s0, $at, L_800B5C70
    if (ctx->r16 == ctx->r1) {
        // 0x800B5B44: nop

            goto L_800B5C70;
    }
    // 0x800B5B44: nop

    // 0x800B5B48: b           L_800B5E3C
    // 0x800B5B4C: nop

        goto L_800B5E3C;
    // 0x800B5B4C: nop

L_800B5B50:
    // 0x800B5B50: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5B54: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5B58: nop

    // 0x800B5B5C: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x800B5B60: nop

    // 0x800B5B64: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x800B5B68: beq         $t9, $zero, L_800B5BB8
    if (ctx->r25 == 0) {
        // 0x800B5B6C: nop

            goto L_800B5BB8;
    }
    // 0x800B5B6C: nop

    // 0x800B5B70: jal         0x80031AC8
    // 0x800B5B74: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x800B5B74: nop

    after_1:
    // 0x800B5B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5B7C: bne         $v0, $at, L_800B5BB0
    if (ctx->r2 != ctx->r1) {
        // 0x800B5B80: nop

            goto L_800B5BB0;
    }
    // 0x800B5B80: nop

    // 0x800B5B84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B5B88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5B8C: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x800B5B90: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800B5B94: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800B5B98: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x800B5B9C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800B5BA0: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x800B5BA4: nor         $t3, $t2, $zero
    ctx->r11 = ~(ctx->r10 | 0);
    // 0x800B5BA8: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x800B5BAC: sh          $t4, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r12;
L_800B5BB0:
    // 0x800B5BB0: b           L_800B5E4C
    // 0x800B5BB4: nop

        goto L_800B5E4C;
    // 0x800B5BB4: nop

L_800B5BB8:
    // 0x800B5BB8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B5BBC: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B5BC0: nop

    // 0x800B5BC4: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x800B5BC8: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800B5BCC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800B5BD0: bgez        $t6, L_800B5BE8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B5BD4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800B5BE8;
    }
    // 0x800B5BD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B5BD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B5BDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B5BE0: nop

    // 0x800B5BE4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800B5BE8:
    // 0x800B5BE8: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800B5BEC: nop

    // 0x800B5BF0: bc1f        L_800B5C28
    if (!c1cs) {
        // 0x800B5BF4: nop

            goto L_800B5C28;
    }
    // 0x800B5BF4: nop

    // 0x800B5BF8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5BFC: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5C00: nop

    // 0x800B5C04: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x800B5C08: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5C0C: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5C10: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5C14: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x800B5C18: nop

    // 0x800B5C1C: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x800B5C20: b           L_800B5C68
    // 0x800B5C24: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
        goto L_800B5C68;
    // 0x800B5C24: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
L_800B5C28:
    // 0x800B5C28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5C2C: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800B5C30: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B5C34: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B5C38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B5C3C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B5C40: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B5C44: mul.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800B5C48: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B5C4C: nop

    // 0x800B5C50: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800B5C54: nop

    // 0x800B5C58: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800B5C5C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x800B5C60: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800B5C64: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
L_800B5C68:
    // 0x800B5C68: b           L_800B5E4C
    // 0x800B5C6C: nop

        goto L_800B5E4C;
    // 0x800B5C6C: nop

L_800B5C70:
    // 0x800B5C70: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B5C74: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B5C78: nop

    // 0x800B5C7C: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x800B5C80: nop

    // 0x800B5C84: andi        $t0, $t4, 0x400
    ctx->r8 = ctx->r12 & 0X400;
    // 0x800B5C88: beq         $t0, $zero, L_800B5CD8
    if (ctx->r8 == 0) {
        // 0x800B5C8C: nop

            goto L_800B5CD8;
    }
    // 0x800B5C8C: nop

    // 0x800B5C90: jal         0x80031AC8
    // 0x800B5C94: nop

    func_80031AC8(rdram, ctx);
        goto after_2;
    // 0x800B5C94: nop

    after_2:
    // 0x800B5C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5C9C: bne         $v0, $at, L_800B5CD0
    if (ctx->r2 != ctx->r1) {
        // 0x800B5CA0: nop

            goto L_800B5CD0;
    }
    // 0x800B5CA0: nop

    // 0x800B5CA4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B5CA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5CAC: swc1        $f8, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f8.u32l;
    // 0x800B5CB0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800B5CB4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B5CB8: lhu         $t7, 0x10F2($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X10F2);
    // 0x800B5CBC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x800B5CC0: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x800B5CC4: nor         $t9, $t7, $zero
    ctx->r25 = ~(ctx->r15 | 0);
    // 0x800B5CC8: and         $t2, $t6, $t9
    ctx->r10 = ctx->r14 & ctx->r25;
    // 0x800B5CCC: sh          $t2, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r10;
L_800B5CD0:
    // 0x800B5CD0: b           L_800B5E4C
    // 0x800B5CD4: nop

        goto L_800B5E4C;
    // 0x800B5CD4: nop

L_800B5CD8:
    // 0x800B5CD8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800B5CDC: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800B5CE0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B5CE4: lhu         $t3, 0x10F2($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X10F2);
    // 0x800B5CE8: lhu         $t1, 0x6($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X6);
    // 0x800B5CEC: nop

    // 0x800B5CF0: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x800B5CF4: beq         $t4, $zero, L_800B5D30
    if (ctx->r12 == 0) {
        // 0x800B5CF8: nop

            goto L_800B5D30;
    }
    // 0x800B5CF8: nop

    // 0x800B5CFC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5D00: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5D04: nop

    // 0x800B5D08: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x800B5D0C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5D10: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5D14: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5D18: lhu         $t6, 0x4($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X4);
    // 0x800B5D1C: nop

    // 0x800B5D20: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800B5D24: sh          $t9, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r25;
    // 0x800B5D28: b           L_800B5E4C
    // 0x800B5D2C: nop

        goto L_800B5E4C;
    // 0x800B5D2C: nop

L_800B5D30:
    // 0x800B5D30: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B5D34: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B5D38: nop

    // 0x800B5D3C: lhu         $t5, 0x8($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X8);
    // 0x800B5D40: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800B5D44: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800B5D48: bgez        $t5, L_800B5D60
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B5D4C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800B5D60;
    }
    // 0x800B5D4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B5D50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B5D54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B5D58: nop

    // 0x800B5D5C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800B5D60:
    // 0x800B5D60: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x800B5D64: nop

    // 0x800B5D68: bc1f        L_800B5DA0
    if (!c1cs) {
        // 0x800B5D6C: nop

            goto L_800B5DA0;
    }
    // 0x800B5D6C: nop

    // 0x800B5D70: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5D74: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5D78: nop

    // 0x800B5D7C: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x800B5D80: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B5D84: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B5D88: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5D8C: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x800B5D90: nop

    // 0x800B5D94: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800B5D98: b           L_800B5DE0
    // 0x800B5D9C: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
        goto L_800B5DE0;
    // 0x800B5D9C: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
L_800B5DA0:
    // 0x800B5DA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5DA4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800B5DA8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B5DAC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B5DB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B5DB4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5DB8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800B5DBC: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B5DC0: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5DC4: nop

    // 0x800B5DC8: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800B5DCC: nop

    // 0x800B5DD0: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800B5DD4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800B5DD8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800B5DDC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
L_800B5DE0:
    // 0x800B5DE0: b           L_800B5E4C
    // 0x800B5DE4: nop

        goto L_800B5E4C;
    // 0x800B5DE4: nop

L_800B5DE8:
    // 0x800B5DE8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5DEC: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5DF0: nop

    // 0x800B5DF4: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x800B5DF8: jal         0x800B5E90
    // 0x800B5DFC: nop

    func_800B5E90(rdram, ctx);
        goto after_3;
    // 0x800B5DFC: nop

    after_3:
    // 0x800B5E00: beq         $v0, $zero, L_800B5E34
    if (ctx->r2 == 0) {
        // 0x800B5E04: nop

            goto L_800B5E34;
    }
    // 0x800B5E04: nop

    // 0x800B5E08: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B5E0C: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B5E10: nop

    // 0x800B5E14: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x800B5E18: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5E1C: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5E20: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B5E24: lhu         $t2, 0x4($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X4);
    // 0x800B5E28: nop

    // 0x800B5E2C: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x800B5E30: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
L_800B5E34:
    // 0x800B5E34: b           L_800B5E4C
    // 0x800B5E38: nop

        goto L_800B5E4C;
    // 0x800B5E38: nop

L_800B5E3C:
    // 0x800B5E3C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5E40: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5E44: nop

    // 0x800B5E48: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
L_800B5E4C:
    // 0x800B5E4C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B5E50: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B5E54: nop

    // 0x800B5E58: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x800B5E5C: nop

    // 0x800B5E60: bne         $t4, $zero, L_800B5E70
    if (ctx->r12 != 0) {
        // 0x800B5E64: nop

            goto L_800B5E70;
    }
    // 0x800B5E64: nop

    // 0x800B5E68: b           L_800B5E80
    // 0x800B5E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B5E80;
    // 0x800B5E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B5E70:
    // 0x800B5E70: b           L_800B5E80
    // 0x800B5E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5E80;
    // 0x800B5E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5E78: b           L_800B5E80
    // 0x800B5E7C: nop

        goto L_800B5E80;
    // 0x800B5E7C: nop

L_800B5E80:
    // 0x800B5E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5E84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5E88: jr          $ra
    // 0x800B5E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B5E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B5E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5E90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B5E94: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800B5E98: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800B5E9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B5EA0: ori         $at, $zero, 0xE100
    ctx->r1 = 0 | 0XE100;
    // 0x800B5EA4: beq         $a1, $at, L_800B5ED8
    if (ctx->r5 == ctx->r1) {
        // 0x800B5EA8: nop

            goto L_800B5ED8;
    }
    // 0x800B5EA8: nop

    // 0x800B5EAC: ori         $at, $zero, 0xE101
    ctx->r1 = 0 | 0XE101;
    // 0x800B5EB0: beq         $a1, $at, L_800B5F08
    if (ctx->r5 == ctx->r1) {
        // 0x800B5EB4: nop

            goto L_800B5F08;
    }
    // 0x800B5EB4: nop

    // 0x800B5EB8: ori         $at, $zero, 0xE102
    ctx->r1 = 0 | 0XE102;
    // 0x800B5EBC: beq         $a1, $at, L_800B5F38
    if (ctx->r5 == ctx->r1) {
        // 0x800B5EC0: nop

            goto L_800B5F38;
    }
    // 0x800B5EC0: nop

    // 0x800B5EC4: ori         $at, $zero, 0xE103
    ctx->r1 = 0 | 0XE103;
    // 0x800B5EC8: beq         $a1, $at, L_800B5F68
    if (ctx->r5 == ctx->r1) {
        // 0x800B5ECC: nop

            goto L_800B5F68;
    }
    // 0x800B5ECC: nop

    // 0x800B5ED0: b           L_800B5F98
    // 0x800B5ED4: nop

        goto L_800B5F98;
    // 0x800B5ED4: nop

L_800B5ED8:
    // 0x800B5ED8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5EDC: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5EE0: nop

    // 0x800B5EE4: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B5EE8: nop

    // 0x800B5EEC: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800B5EF0: bne         $t8, $zero, L_800B5F00
    if (ctx->r24 != 0) {
        // 0x800B5EF4: nop

            goto L_800B5F00;
    }
    // 0x800B5EF4: nop

    // 0x800B5EF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B5EFC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_800B5F00:
    // 0x800B5F00: b           L_800B5F98
    // 0x800B5F04: nop

        goto L_800B5F98;
    // 0x800B5F04: nop

L_800B5F08:
    // 0x800B5F08: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5F0C: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5F10: nop

    // 0x800B5F14: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B5F18: nop

    // 0x800B5F1C: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x800B5F20: bne         $t2, $zero, L_800B5F30
    if (ctx->r10 != 0) {
        // 0x800B5F24: nop

            goto L_800B5F30;
    }
    // 0x800B5F24: nop

    // 0x800B5F28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B5F2C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_800B5F30:
    // 0x800B5F30: b           L_800B5F98
    // 0x800B5F34: nop

        goto L_800B5F98;
    // 0x800B5F34: nop

L_800B5F38:
    // 0x800B5F38: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B5F3C: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B5F40: nop

    // 0x800B5F44: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800B5F48: nop

    // 0x800B5F4C: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x800B5F50: bne         $t6, $zero, L_800B5F60
    if (ctx->r14 != 0) {
        // 0x800B5F54: nop

            goto L_800B5F60;
    }
    // 0x800B5F54: nop

    // 0x800B5F58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B5F5C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800B5F60:
    // 0x800B5F60: b           L_800B5F98
    // 0x800B5F64: nop

        goto L_800B5F98;
    // 0x800B5F64: nop

L_800B5F68:
    // 0x800B5F68: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5F6C: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5F70: nop

    // 0x800B5F74: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x800B5F78: nop

    // 0x800B5F7C: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x800B5F80: bne         $t0, $zero, L_800B5F90
    if (ctx->r8 != 0) {
        // 0x800B5F84: nop

            goto L_800B5F90;
    }
    // 0x800B5F84: nop

    // 0x800B5F88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800B5F8C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_800B5F90:
    // 0x800B5F90: b           L_800B5F98
    // 0x800B5F94: nop

        goto L_800B5F98;
    // 0x800B5F94: nop

L_800B5F98:
    // 0x800B5F98: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800B5F9C: b           L_800B5FAC
    // 0x800B5FA0: nop

        goto L_800B5FAC;
    // 0x800B5FA0: nop

    // 0x800B5FA4: b           L_800B5FAC
    // 0x800B5FA8: nop

        goto L_800B5FAC;
    // 0x800B5FA8: nop

L_800B5FAC:
    // 0x800B5FAC: jr          $ra
    // 0x800B5FB0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B5FB0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B5FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5FB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B5FB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B5FBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5FC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B5FC4:
    // 0x800B5FC4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5FC8: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5FCC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800B5FD0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800B5FD4: jal         0x800BD218
    // 0x800B5FD8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_0;
    // 0x800B5FD8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x800B5FDC: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x800B5FE0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800B5FE4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5FE8: nop

    // 0x800B5FEC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800B5FF0: nop

    // 0x800B5FF4: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x800B5FF8: lhu         $t0, 0x2A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2A);
    // 0x800B5FFC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800B6000: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x800B6004: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800B6008: sltiu       $at, $t1, 0x32
    ctx->r1 = ctx->r9 < 0X32 ? 1 : 0;
    // 0x800B600C: beq         $at, $zero, L_800B696C
    if (ctx->r1 == 0) {
        // 0x800B6010: nop

            goto L_800B696C;
    }
    // 0x800B6010: nop

    // 0x800B6014: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B6018: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B601C: addu        $at, $at, $t1
    gpr jr_addend_800B6028 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800B6020: lw          $t1, -0x670($at)
    ctx->r9 = ADD32(ctx->r1, -0X670);
    // 0x800B6024: nop

    // 0x800B6028: jr          $t1
    // 0x800B602C: nop

    switch (jr_addend_800B6028 >> 2) {
        case 0: goto L_800B6030; break;
        case 1: goto L_800B6060; break;
        case 2: goto L_800B60C4; break;
        case 3: goto L_800B60F4; break;
        case 4: goto L_800B612C; break;
        case 5: goto L_800B6164; break;
        case 6: goto L_800B619C; break;
        case 7: goto L_800B61CC; break;
        case 8: goto L_800B61FC; break;
        case 9: goto L_800B622C; break;
        case 10: goto L_800B625C; break;
        case 11: goto L_800B628C; break;
        case 12: goto L_800B62B8; break;
        case 13: goto L_800B696C; break;
        case 14: goto L_800B696C; break;
        case 15: goto L_800B696C; break;
        case 16: goto L_800B6380; break;
        case 17: goto L_800B696C; break;
        case 18: goto L_800B62E0; break;
        case 19: goto L_800B696C; break;
        case 20: goto L_800B696C; break;
        case 21: goto L_800B6310; break;
        case 22: goto L_800B6348; break;
        case 23: goto L_800B63B8; break;
        case 24: goto L_800B63E8; break;
        case 25: goto L_800B6418; break;
        case 26: goto L_800B6450; break;
        case 27: goto L_800B6488; break;
        case 28: goto L_800B64C0; break;
        case 29: goto L_800B64F8; break;
        case 30: goto L_800B6530; break;
        case 31: goto L_800B6568; break;
        case 32: goto L_800B65A0; break;
        case 33: goto L_800B65D4; break;
        case 34: goto L_800B6608; break;
        case 35: goto L_800B6640; break;
        case 36: goto L_800B6670; break;
        case 37: goto L_800B66A0; break;
        case 38: goto L_800B66D8; break;
        case 39: goto L_800B6710; break;
        case 40: goto L_800B6740; break;
        case 41: goto L_800B6774; break;
        case 42: goto L_800B67AC; break;
        case 43: goto L_800B67DC; break;
        case 44: goto L_800B680C; break;
        case 45: goto L_800B6840; break;
        case 46: goto L_800B6878; break;
        case 47: goto L_800B68A8; break;
        case 48: goto L_800B68D8; break;
        case 49: goto L_800B6910; break;
        default: switch_error(__func__, 0x800B6028, 0x800EF990);
    }
    // 0x800B602C: nop

L_800B6030:
    // 0x800B6030: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6034: jal         0x800B69C4
    // 0x800B6038: nop

    func_800B69C4(rdram, ctx);
        goto after_1;
    // 0x800B6038: nop

    after_1:
    // 0x800B603C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B6040: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B6044: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6048: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B604C: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x800B6050: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B6054: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x800B6058: b           L_800B696C
    // 0x800B605C: nop

        goto L_800B696C;
    // 0x800B605C: nop

L_800B6060:
    // 0x800B6060: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B6064: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B6068: nop

    // 0x800B606C: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B6070: nop

    // 0x800B6074: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800B6078: bne         $t8, $zero, L_800B60A0
    if (ctx->r24 != 0) {
        // 0x800B607C: nop

            goto L_800B60A0;
    }
    // 0x800B607C: nop

    // 0x800B6080: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B6084: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B6088: nop

    // 0x800B608C: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x800B6090: nop

    // 0x800B6094: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800B6098: b           L_800B60BC
    // 0x800B609C: sh          $t1, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r9;
        goto L_800B60BC;
    // 0x800B609C: sh          $t1, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r9;
L_800B60A0:
    // 0x800B60A0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B60A4: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B60A8: nop

    // 0x800B60AC: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x800B60B0: nop

    // 0x800B60B4: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x800B60B8: sh          $t5, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r13;
L_800B60BC:
    // 0x800B60BC: b           L_800B696C
    // 0x800B60C0: nop

        goto L_800B696C;
    // 0x800B60C0: nop

L_800B60C4:
    // 0x800B60C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B60C8: jal         0x800B6A00
    // 0x800B60CC: nop

    func_800B6A00(rdram, ctx);
        goto after_2;
    // 0x800B60CC: nop

    after_2:
    // 0x800B60D0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B60D4: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B60D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B60DC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800B60E0: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800B60E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B60E8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800B60EC: b           L_800B696C
    // 0x800B60F0: nop

        goto L_800B696C;
    // 0x800B60F0: nop

L_800B60F4:
    // 0x800B60F4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B60F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800B60FC: lhu         $a2, 0x2($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X2);
    // 0x800B6100: jal         0x800B80A4
    // 0x800B6104: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800B80A4(rdram, ctx);
        goto after_3;
    // 0x800B6104: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_3:
    // 0x800B6108: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B610C: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B6110: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6114: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800B6118: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x800B611C: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800B6120: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800B6124: b           L_800B696C
    // 0x800B6128: nop

        goto L_800B696C;
    // 0x800B6128: nop

L_800B612C:
    // 0x800B612C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B6134: lhu         $a2, 0x2($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X2);
    // 0x800B6138: jal         0x800B80A4
    // 0x800B613C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800B80A4(rdram, ctx);
        goto after_4;
    // 0x800B613C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_4:
    // 0x800B6140: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B6144: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B6148: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B614C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B6150: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800B6154: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x800B6158: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x800B615C: b           L_800B696C
    // 0x800B6160: nop

        goto L_800B696C;
    // 0x800B6160: nop

L_800B6164:
    // 0x800B6164: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B616C: lhu         $a2, 0x2($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X2);
    // 0x800B6170: jal         0x800B80A4
    // 0x800B6174: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800B80A4(rdram, ctx);
        goto after_5;
    // 0x800B6174: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x800B6178: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B617C: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B6180: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6184: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x800B6188: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x800B618C: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x800B6190: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x800B6194: b           L_800B696C
    // 0x800B6198: nop

        goto L_800B696C;
    // 0x800B6198: nop

L_800B619C:
    // 0x800B619C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B61A0: jal         0x800B6B18
    // 0x800B61A4: nop

    func_800B6B18(rdram, ctx);
        goto after_6;
    // 0x800B61A4: nop

    after_6:
    // 0x800B61A8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B61AC: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B61B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B61B4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800B61B8: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800B61BC: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x800B61C0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800B61C4: b           L_800B696C
    // 0x800B61C8: nop

        goto L_800B696C;
    // 0x800B61C8: nop

L_800B61CC:
    // 0x800B61CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B61D0: jal         0x800B7510
    // 0x800B61D4: nop

    func_800B7510(rdram, ctx);
        goto after_7;
    // 0x800B61D4: nop

    after_7:
    // 0x800B61D8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B61DC: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B61E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B61E4: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800B61E8: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x800B61EC: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800B61F0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800B61F4: b           L_800B696C
    // 0x800B61F8: nop

        goto L_800B696C;
    // 0x800B61F8: nop

L_800B61FC:
    // 0x800B61FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6200: jal         0x800B7678
    // 0x800B6204: nop

    func_800B7678(rdram, ctx);
        goto after_8;
    // 0x800B6204: nop

    after_8:
    // 0x800B6208: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B620C: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B6210: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6214: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800B6218: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800B621C: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800B6220: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800B6224: b           L_800B696C
    // 0x800B6228: nop

        goto L_800B696C;
    // 0x800B6228: nop

L_800B622C:
    // 0x800B622C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6230: jal         0x800B7788
    // 0x800B6234: nop

    func_800B7788(rdram, ctx);
        goto after_9;
    // 0x800B6234: nop

    after_9:
    // 0x800B6238: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B623C: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B6240: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6244: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B6248: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800B624C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800B6250: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800B6254: b           L_800B696C
    // 0x800B6258: nop

        goto L_800B696C;
    // 0x800B6258: nop

L_800B625C:
    // 0x800B625C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6260: jal         0x800B77D8
    // 0x800B6264: nop

    func_800B77D8(rdram, ctx);
        goto after_10;
    // 0x800B6264: nop

    after_10:
    // 0x800B6268: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B626C: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B6270: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6274: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B6278: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800B627C: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800B6280: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800B6284: b           L_800B696C
    // 0x800B6288: nop

        goto L_800B696C;
    // 0x800B6288: nop

L_800B628C:
    // 0x800B628C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B6290: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B6294: nop

    // 0x800B6298: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800B629C: nop

    // 0x800B62A0: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x800B62A4: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800B62A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B62AC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B62B0: b           L_800B696C
    // 0x800B62B4: nop

        goto L_800B696C;
    // 0x800B62B4: nop

L_800B62B8:
    // 0x800B62B8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B62BC: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B62C0: nop

    // 0x800B62C4: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x800B62C8: nop

    // 0x800B62CC: addiu       $t6, $t2, 0x2
    ctx->r14 = ADD32(ctx->r10, 0X2);
    // 0x800B62D0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800B62D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800B62D8: b           L_800B696C
    // 0x800B62DC: nop

        goto L_800B696C;
    // 0x800B62DC: nop

L_800B62E0:
    // 0x800B62E0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B62E4: jal         0x800B7B94
    // 0x800B62E8: nop

    func_800B7B94(rdram, ctx);
        goto after_11;
    // 0x800B62E8: nop

    after_11:
    // 0x800B62EC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B62F0: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B62F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B62F8: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B62FC: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x800B6300: addu        $t1, $t7, $t5
    ctx->r9 = ADD32(ctx->r15, ctx->r13);
    // 0x800B6304: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x800B6308: b           L_800B696C
    // 0x800B630C: nop

        goto L_800B696C;
    // 0x800B630C: nop

L_800B6310:
    // 0x800B6310: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6314: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B6318: lhu         $a2, 0x2($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X2);
    // 0x800B631C: jal         0x800B80A4
    // 0x800B6320: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800B80A4(rdram, ctx);
        goto after_12;
    // 0x800B6320: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_12:
    // 0x800B6324: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B6328: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B632C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6330: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800B6334: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x800B6338: addu        $t6, $t0, $t2
    ctx->r14 = ADD32(ctx->r8, ctx->r10);
    // 0x800B633C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800B6340: b           L_800B696C
    // 0x800B6344: nop

        goto L_800B696C;
    // 0x800B6344: nop

L_800B6348:
    // 0x800B6348: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B634C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800B6350: lhu         $a2, 0x2($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X2);
    // 0x800B6354: jal         0x800B80A4
    // 0x800B6358: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800B80A4(rdram, ctx);
        goto after_13;
    // 0x800B6358: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_13:
    // 0x800B635C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B6360: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B6364: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6368: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x800B636C: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x800B6370: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x800B6374: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800B6378: b           L_800B696C
    // 0x800B637C: nop

        goto L_800B696C;
    // 0x800B637C: nop

L_800B6380:
    // 0x800B6380: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6384: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800B6388: lhu         $a2, 0x2($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X2);
    // 0x800B638C: jal         0x800B80A4
    // 0x800B6390: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800B80A4(rdram, ctx);
        goto after_14;
    // 0x800B6390: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_14:
    // 0x800B6394: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B6398: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B639C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B63A0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B63A4: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x800B63A8: addu        $t8, $t2, $t6
    ctx->r24 = ADD32(ctx->r10, ctx->r14);
    // 0x800B63AC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800B63B0: b           L_800B696C
    // 0x800B63B4: nop

        goto L_800B696C;
    // 0x800B63B4: nop

L_800B63B8:
    // 0x800B63B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B63BC: jal         0x800B7D20
    // 0x800B63C0: nop

    func_800B7D20(rdram, ctx);
        goto after_15;
    // 0x800B63C0: nop

    after_15:
    // 0x800B63C4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B63C8: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B63CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B63D0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800B63D4: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x800B63D8: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x800B63DC: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800B63E0: b           L_800B696C
    // 0x800B63E4: nop

        goto L_800B696C;
    // 0x800B63E4: nop

L_800B63E8:
    // 0x800B63E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B63EC: jal         0x800B7C4C
    // 0x800B63F0: nop

    func_800B7C4C(rdram, ctx);
        goto after_16;
    // 0x800B63F0: nop

    after_16:
    // 0x800B63F4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B63F8: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B63FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6400: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x800B6404: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x800B6408: addu        $t6, $t3, $t2
    ctx->r14 = ADD32(ctx->r11, ctx->r10);
    // 0x800B640C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800B6410: b           L_800B696C
    // 0x800B6414: nop

        goto L_800B696C;
    // 0x800B6414: nop

L_800B6418:
    // 0x800B6418: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B641C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B6420: lhu         $a2, 0x2($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X2);
    // 0x800B6424: jal         0x800B80A4
    // 0x800B6428: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800B80A4(rdram, ctx);
        goto after_17;
    // 0x800B6428: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_17:
    // 0x800B642C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B6430: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B6434: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6438: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800B643C: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x800B6440: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x800B6444: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B6448: b           L_800B696C
    // 0x800B644C: nop

        goto L_800B696C;
    // 0x800B644C: nop

L_800B6450:
    // 0x800B6450: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6454: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B6458: lhu         $a2, 0x2($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X2);
    // 0x800B645C: jal         0x800B80A4
    // 0x800B6460: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800B80A4(rdram, ctx);
        goto after_18;
    // 0x800B6460: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_18:
    // 0x800B6464: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B6468: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B646C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6470: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x800B6474: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x800B6478: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800B647C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x800B6480: b           L_800B696C
    // 0x800B6484: nop

        goto L_800B696C;
    // 0x800B6484: nop

L_800B6488:
    // 0x800B6488: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B648C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800B6490: lhu         $a2, 0x2($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X2);
    // 0x800B6494: jal         0x800B80A4
    // 0x800B6498: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800B80A4(rdram, ctx);
        goto after_19;
    // 0x800B6498: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_19:
    // 0x800B649C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B64A0: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B64A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B64A8: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x800B64AC: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800B64B0: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x800B64B4: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x800B64B8: b           L_800B696C
    // 0x800B64BC: nop

        goto L_800B696C;
    // 0x800B64BC: nop

L_800B64C0:
    // 0x800B64C0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B64C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B64C8: lhu         $a2, 0x2($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X2);
    // 0x800B64CC: jal         0x800B80A4
    // 0x800B64D0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800B80A4(rdram, ctx);
        goto after_20;
    // 0x800B64D0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_20:
    // 0x800B64D4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B64D8: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B64DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B64E0: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800B64E4: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800B64E8: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x800B64EC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800B64F0: b           L_800B696C
    // 0x800B64F4: nop

        goto L_800B696C;
    // 0x800B64F4: nop

L_800B64F8:
    // 0x800B64F8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B64FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B6500: lhu         $a2, 0x2($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X2);
    // 0x800B6504: jal         0x800B80A4
    // 0x800B6508: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800B80A4(rdram, ctx);
        goto after_21;
    // 0x800B6508: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_21:
    // 0x800B650C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B6510: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B6514: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6518: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800B651C: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800B6520: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800B6524: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800B6528: b           L_800B696C
    // 0x800B652C: nop

        goto L_800B696C;
    // 0x800B652C: nop

L_800B6530:
    // 0x800B6530: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6534: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800B6538: lhu         $a2, 0x2($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X2);
    // 0x800B653C: jal         0x800B80A4
    // 0x800B6540: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800B80A4(rdram, ctx);
        goto after_22;
    // 0x800B6540: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_22:
    // 0x800B6544: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B6548: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B654C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6550: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B6554: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x800B6558: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x800B655C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x800B6560: b           L_800B696C
    // 0x800B6564: nop

        goto L_800B696C;
    // 0x800B6564: nop

L_800B6568:
    // 0x800B6568: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B656C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B6570: lhu         $a2, 0x2($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X2);
    // 0x800B6574: jal         0x800B80A4
    // 0x800B6578: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800B80A4(rdram, ctx);
        goto after_23;
    // 0x800B6578: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_23:
    // 0x800B657C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B6580: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B6584: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6588: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B658C: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x800B6590: addu        $t1, $t0, $t5
    ctx->r9 = ADD32(ctx->r8, ctx->r13);
    // 0x800B6594: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x800B6598: b           L_800B696C
    // 0x800B659C: nop

        goto L_800B696C;
    // 0x800B659C: nop

L_800B65A0:
    // 0x800B65A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B65A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800B65A8: jal         0x800B80A4
    // 0x800B65AC: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    func_800B80A4(rdram, ctx);
        goto after_24;
    // 0x800B65AC: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    after_24:
    // 0x800B65B0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B65B4: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B65B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B65BC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800B65C0: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x800B65C4: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x800B65C8: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800B65CC: b           L_800B696C
    // 0x800B65D0: nop

        goto L_800B696C;
    // 0x800B65D0: nop

L_800B65D4:
    // 0x800B65D4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B65D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B65DC: jal         0x800B80A4
    // 0x800B65E0: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    func_800B80A4(rdram, ctx);
        goto after_25;
    // 0x800B65E0: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    after_25:
    // 0x800B65E4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B65E8: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B65EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B65F0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B65F4: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800B65F8: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x800B65FC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800B6600: b           L_800B696C
    // 0x800B6604: nop

        goto L_800B696C;
    // 0x800B6604: nop

L_800B6608:
    // 0x800B6608: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B660C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800B6610: lhu         $a2, 0x2($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X2);
    // 0x800B6614: jal         0x800B80A4
    // 0x800B6618: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800B80A4(rdram, ctx);
        goto after_26;
    // 0x800B6618: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_26:
    // 0x800B661C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B6620: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B6624: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6628: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B662C: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x800B6630: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x800B6634: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x800B6638: b           L_800B696C
    // 0x800B663C: nop

        goto L_800B696C;
    // 0x800B663C: nop

L_800B6640:
    // 0x800B6640: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6644: jal         0x800B7DCC
    // 0x800B6648: nop

    func_800B7DCC(rdram, ctx);
        goto after_27;
    // 0x800B6648: nop

    after_27:
    // 0x800B664C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B6650: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B6654: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6658: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800B665C: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800B6660: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x800B6664: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800B6668: b           L_800B696C
    // 0x800B666C: nop

        goto L_800B696C;
    // 0x800B666C: nop

L_800B6670:
    // 0x800B6670: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6674: jal         0x800B7EA4
    // 0x800B6678: nop

    func_800B7EA4(rdram, ctx);
        goto after_28;
    // 0x800B6678: nop

    after_28:
    // 0x800B667C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B6680: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B6684: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6688: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x800B668C: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800B6690: addu        $t3, $t1, $t7
    ctx->r11 = ADD32(ctx->r9, ctx->r15);
    // 0x800B6694: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800B6698: b           L_800B696C
    // 0x800B669C: nop

        goto L_800B696C;
    // 0x800B669C: nop

L_800B66A0:
    // 0x800B66A0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B66A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B66A8: lhu         $a2, 0x2($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X2);
    // 0x800B66AC: jal         0x800B80A4
    // 0x800B66B0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800B80A4(rdram, ctx);
        goto after_29;
    // 0x800B66B0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_29:
    // 0x800B66B4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B66B8: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B66BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B66C0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B66C4: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800B66C8: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x800B66CC: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800B66D0: b           L_800B696C
    // 0x800B66D4: nop

        goto L_800B696C;
    // 0x800B66D4: nop

L_800B66D8:
    // 0x800B66D8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B66DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B66E0: lhu         $a2, 0x2($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X2);
    // 0x800B66E4: jal         0x800B80A4
    // 0x800B66E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800B80A4(rdram, ctx);
        goto after_30;
    // 0x800B66E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_30:
    // 0x800B66EC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B66F0: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B66F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B66F8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B66FC: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x800B6700: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800B6704: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B6708: b           L_800B696C
    // 0x800B670C: nop

        goto L_800B696C;
    // 0x800B670C: nop

L_800B6710:
    // 0x800B6710: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6714: jal         0x800B79FC
    // 0x800B6718: nop

    func_800B79FC(rdram, ctx);
        goto after_31;
    // 0x800B6718: nop

    after_31:
    // 0x800B671C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B6720: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B6724: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6728: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800B672C: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800B6730: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x800B6734: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x800B6738: b           L_800B696C
    // 0x800B673C: nop

        goto L_800B696C;
    // 0x800B673C: nop

L_800B6740:
    // 0x800B6740: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6744: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800B6748: jal         0x800B80A4
    // 0x800B674C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800B80A4(rdram, ctx);
        goto after_32;
    // 0x800B674C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_32:
    // 0x800B6750: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B6754: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B6758: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B675C: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x800B6760: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800B6764: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x800B6768: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x800B676C: b           L_800B696C
    // 0x800B6770: nop

        goto L_800B696C;
    // 0x800B6770: nop

L_800B6774:
    // 0x800B6774: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6778: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B677C: lhu         $a2, 0x2($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X2);
    // 0x800B6780: jal         0x800B80A4
    // 0x800B6784: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800B80A4(rdram, ctx);
        goto after_33;
    // 0x800B6784: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_33:
    // 0x800B6788: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B678C: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B6790: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6794: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B6798: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800B679C: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x800B67A0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800B67A4: b           L_800B696C
    // 0x800B67A8: nop

        goto L_800B696C;
    // 0x800B67A8: nop

L_800B67AC:
    // 0x800B67AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B67B0: jal         0x800B7F2C
    // 0x800B67B4: nop

    func_800B7F2C(rdram, ctx);
        goto after_34;
    // 0x800B67B4: nop

    after_34:
    // 0x800B67B8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B67BC: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B67C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B67C4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800B67C8: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800B67CC: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x800B67D0: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800B67D4: b           L_800B696C
    // 0x800B67D8: nop

        goto L_800B696C;
    // 0x800B67D8: nop

L_800B67DC:
    // 0x800B67DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B67E0: jal         0x800B7FCC
    // 0x800B67E4: nop

    func_800B7FCC(rdram, ctx);
        goto after_35;
    // 0x800B67E4: nop

    after_35:
    // 0x800B67E8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B67EC: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B67F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B67F4: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800B67F8: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800B67FC: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x800B6800: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800B6804: b           L_800B696C
    // 0x800B6808: nop

        goto L_800B696C;
    // 0x800B6808: nop

L_800B680C:
    // 0x800B680C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6810: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B6814: jal         0x800B80A4
    // 0x800B6818: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800B80A4(rdram, ctx);
        goto after_36;
    // 0x800B6818: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_36:
    // 0x800B681C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B6820: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B6824: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6828: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x800B682C: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x800B6830: addu        $t7, $t1, $t4
    ctx->r15 = ADD32(ctx->r9, ctx->r12);
    // 0x800B6834: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800B6838: b           L_800B696C
    // 0x800B683C: nop

        goto L_800B696C;
    // 0x800B683C: nop

L_800B6840:
    // 0x800B6840: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6844: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800B6848: lhu         $a2, 0x2($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X2);
    // 0x800B684C: jal         0x800B80A4
    // 0x800B6850: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800B80A4(rdram, ctx);
        goto after_37;
    // 0x800B6850: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_37:
    // 0x800B6854: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B6858: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B685C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6860: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800B6864: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800B6868: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x800B686C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800B6870: b           L_800B696C
    // 0x800B6874: nop

        goto L_800B696C;
    // 0x800B6874: nop

L_800B6878:
    // 0x800B6878: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B687C: jal         0x800B8038
    // 0x800B6880: nop

    func_800B8038(rdram, ctx);
        goto after_38;
    // 0x800B6880: nop

    after_38:
    // 0x800B6884: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B6888: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B688C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6890: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800B6894: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x800B6898: addu        $t7, $t1, $t4
    ctx->r15 = ADD32(ctx->r9, ctx->r12);
    // 0x800B689C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800B68A0: b           L_800B696C
    // 0x800B68A4: nop

        goto L_800B696C;
    // 0x800B68A4: nop

L_800B68A8:
    // 0x800B68A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B68AC: jal         0x800B75EC
    // 0x800B68B0: nop

    func_800B75EC(rdram, ctx);
        goto after_39;
    // 0x800B68B0: nop

    after_39:
    // 0x800B68B4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B68B8: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B68BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B68C0: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x800B68C4: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x800B68C8: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x800B68CC: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800B68D0: b           L_800B696C
    // 0x800B68D4: nop

        goto L_800B696C;
    // 0x800B68D4: nop

L_800B68D8:
    // 0x800B68D8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B68DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800B68E0: lhu         $a2, 0x2($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X2);
    // 0x800B68E4: jal         0x800B80A4
    // 0x800B68E8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800B80A4(rdram, ctx);
        goto after_40;
    // 0x800B68E8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_40:
    // 0x800B68EC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B68F0: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B68F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B68F8: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800B68FC: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x800B6900: addu        $t7, $t1, $t4
    ctx->r15 = ADD32(ctx->r9, ctx->r12);
    // 0x800B6904: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800B6908: b           L_800B696C
    // 0x800B690C: nop

        goto L_800B696C;
    // 0x800B690C: nop

L_800B6910:
    // 0x800B6910: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6914: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800B6918: lhu         $a2, 0x2($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X2);
    // 0x800B691C: jal         0x800B80A4
    // 0x800B6920: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800B80A4(rdram, ctx);
        goto after_41;
    // 0x800B6920: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_41:
    // 0x800B6924: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B6928: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B692C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B6930: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800B6934: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800B6938: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x800B693C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800B6940: b           L_800B696C
    // 0x800B6944: nop

        goto L_800B696C;
    // 0x800B6944: nop

    // 0x800B6948: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B694C: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B6950: nop

    // 0x800B6954: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B6958: nop

    // 0x800B695C: addiu       $t4, $t1, 0x2
    ctx->r12 = ADD32(ctx->r9, 0X2);
    // 0x800B6960: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B6964: b           L_800B696C
    // 0x800B6968: nop

        goto L_800B696C;
    // 0x800B6968: nop

L_800B696C:
    // 0x800B696C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B6970: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B6974: nop

    // 0x800B6978: lhu         $t2, 0x4($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X4);
    // 0x800B697C: nop

    // 0x800B6980: andi        $t9, $t2, 0x2
    ctx->r25 = ctx->r10 & 0X2;
    // 0x800B6984: beq         $t9, $zero, L_800B6994
    if (ctx->r25 == 0) {
        // 0x800B6988: nop

            goto L_800B6994;
    }
    // 0x800B6988: nop

    // 0x800B698C: b           L_800B69B4
    // 0x800B6990: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B69B4;
    // 0x800B6990: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6994:
    // 0x800B6994: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B6998: nop

    // 0x800B699C: bne         $t6, $zero, L_800B5FC4
    if (ctx->r14 != 0) {
        // 0x800B69A0: nop

            goto L_800B5FC4;
    }
    // 0x800B69A0: nop

    // 0x800B69A4: b           L_800B69B4
    // 0x800B69A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B69B4;
    // 0x800B69A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B69AC: b           L_800B69B4
    // 0x800B69B0: nop

        goto L_800B69B4;
    // 0x800B69B0: nop

L_800B69B4:
    // 0x800B69B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B69B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B69BC: jr          $ra
    // 0x800B69C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B69C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800B69C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B69C4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B69C8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B69CC: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B69D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B69D4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B69D8: sh          $t6, -0x73F0($at)
    MEM_H(-0X73F0, ctx->r1) = ctx->r14;
    // 0x800B69DC: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800B69E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B69E4: sh          $t7, -0x73E4($at)
    MEM_H(-0X73E4, ctx->r1) = ctx->r15;
    // 0x800B69E8: b           L_800B69F8
    // 0x800B69EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B69F8;
    // 0x800B69EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B69F0: b           L_800B69F8
    // 0x800B69F4: nop

        goto L_800B69F8;
    // 0x800B69F4: nop

L_800B69F8:
    // 0x800B69F8: jr          $ra
    // 0x800B69FC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B69FC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800B6A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6A00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B6A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B6A08: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B6A0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B6A10:
    // 0x800B6A10: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B6A14: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6A18: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B6A1C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B6A20: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B6A24: sh          $t7, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r15;
    // 0x800B6A28: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B6A2C: nop

    // 0x800B6A30: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B6A34: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B6A38: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6A3C: nop

    // 0x800B6A40: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B6A44: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x800B6A48: bne         $at, $zero, L_800B6A10
    if (ctx->r1 != 0) {
        // 0x800B6A4C: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B6A10;
    }
    // 0x800B6A4C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B6A50: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x800B6A54: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B6A58: jal         0x8000D688
    // 0x800B6A5C: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B6A5C: nop

    after_0:
    // 0x800B6A60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B6A64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800B6A68: nop

    // 0x800B6A6C: beq         $t6, $zero, L_800B6AB4
    if (ctx->r14 == 0) {
        // 0x800B6A70: nop

            goto L_800B6AB4;
    }
    // 0x800B6A70: nop

    // 0x800B6A74: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B6A78: nop

    // 0x800B6A7C: lw          $t7, 0x1AC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X1AC);
    // 0x800B6A80: nop

    // 0x800B6A84: slti        $at, $t7, 0x4000
    ctx->r1 = SIGNED(ctx->r15) < 0X4000 ? 1 : 0;
    // 0x800B6A88: bne         $at, $zero, L_800B6AAC
    if (ctx->r1 != 0) {
        // 0x800B6A8C: nop

            goto L_800B6AAC;
    }
    // 0x800B6A8C: nop

    // 0x800B6A90: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800B6A94: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B6A98: beq         $at, $zero, L_800B6AAC
    if (ctx->r1 == 0) {
        // 0x800B6A9C: nop

            goto L_800B6AAC;
    }
    // 0x800B6A9C: nop

    // 0x800B6AA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B6AA4: jal         0x80015B6C
    // 0x800B6AA8: nop

    func_80015B6C(rdram, ctx);
        goto after_1;
    // 0x800B6AA8: nop

    after_1:
L_800B6AAC:
    // 0x800B6AAC: b           L_800B6B08
    // 0x800B6AB0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800B6B08;
    // 0x800B6AB0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800B6AB4:
    // 0x800B6AB4: addiu       $t9, $sp, 0x24
    ctx->r25 = ADD32(ctx->r29, 0X24);
    // 0x800B6AB8: lhu         $a0, 0x2($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X2);
    // 0x800B6ABC: jal         0x8000D5A8
    // 0x800B6AC0: nop

    func_8000D5A8(rdram, ctx);
        goto after_2;
    // 0x800B6AC0: nop

    after_2:
    // 0x800B6AC4: beq         $v0, $zero, L_800B6AD4
    if (ctx->r2 == 0) {
        // 0x800B6AC8: nop

            goto L_800B6AD4;
    }
    // 0x800B6AC8: nop

    // 0x800B6ACC: b           L_800B6B08
    // 0x800B6AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6B08;
    // 0x800B6AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6AD4:
    // 0x800B6AD4: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800B6AD8: lhu         $a0, 0x2($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X2);
    // 0x800B6ADC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800B6AE0: jal         0x8000D934
    // 0x800B6AE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8000D934(rdram, ctx);
        goto after_3;
    // 0x800B6AE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x800B6AE8: bgez        $v0, L_800B6AF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B6AEC: nop

            goto L_800B6AF8;
    }
    // 0x800B6AEC: nop

    // 0x800B6AF0: b           L_800B6B08
    // 0x800B6AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6B08;
    // 0x800B6AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6AF8:
    // 0x800B6AF8: b           L_800B6B08
    // 0x800B6AFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800B6B08;
    // 0x800B6AFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800B6B00: b           L_800B6B08
    // 0x800B6B04: nop

        goto L_800B6B08;
    // 0x800B6B04: nop

L_800B6B08:
    // 0x800B6B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6B0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B6B10: jr          $ra
    // 0x800B6B14: nop

    return;
    // 0x800B6B14: nop

;}
RECOMP_FUNC void func_800B6B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6B18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B6B1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B6B20: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B6B24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B6B28: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800B6B2C:
    // 0x800B6B2C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800B6B30: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6B34: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B6B38: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B6B3C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B6B40: sh          $t7, 0x30($t0)
    MEM_H(0X30, ctx->r8) = ctx->r15;
    // 0x800B6B44: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B6B48: nop

    // 0x800B6B4C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B6B50: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800B6B54: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6B58: nop

    // 0x800B6B5C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B6B60: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800B6B64: bne         $at, $zero, L_800B6B2C
    if (ctx->r1 != 0) {
        // 0x800B6B68: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_800B6B2C;
    }
    // 0x800B6B68: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B6B6C: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x800B6B70: lhu         $s0, 0x2($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0X2);
    // 0x800B6B74: ori         $at, $zero, 0xE100
    ctx->r1 = 0 | 0XE100;
    // 0x800B6B78: beq         $s0, $at, L_800B6BAC
    if (ctx->r16 == ctx->r1) {
        // 0x800B6B7C: nop

            goto L_800B6BAC;
    }
    // 0x800B6B7C: nop

    // 0x800B6B80: ori         $at, $zero, 0xE101
    ctx->r1 = 0 | 0XE101;
    // 0x800B6B84: beq         $s0, $at, L_800B6BE8
    if (ctx->r16 == ctx->r1) {
        // 0x800B6B88: nop

            goto L_800B6BE8;
    }
    // 0x800B6B88: nop

    // 0x800B6B8C: ori         $at, $zero, 0xE102
    ctx->r1 = 0 | 0XE102;
    // 0x800B6B90: beq         $s0, $at, L_800B6C30
    if (ctx->r16 == ctx->r1) {
        // 0x800B6B94: nop

            goto L_800B6C30;
    }
    // 0x800B6B94: nop

    // 0x800B6B98: ori         $at, $zero, 0xE103
    ctx->r1 = 0 | 0XE103;
    // 0x800B6B9C: beq         $s0, $at, L_800B6C6C
    if (ctx->r16 == ctx->r1) {
        // 0x800B6BA0: nop

            goto L_800B6C6C;
    }
    // 0x800B6BA0: nop

    // 0x800B6BA4: b           L_800B6CA8
    // 0x800B6BA8: nop

        goto L_800B6CA8;
    // 0x800B6BA8: nop

L_800B6BAC:
    // 0x800B6BAC: jal         0x800B6CC8
    // 0x800B6BB0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B6CC8(rdram, ctx);
        goto after_0;
    // 0x800B6BB0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800B6BB4: beq         $v0, $zero, L_800B6BC4
    if (ctx->r2 == 0) {
        // 0x800B6BB8: nop

            goto L_800B6BC4;
    }
    // 0x800B6BB8: nop

    // 0x800B6BBC: b           L_800B6CB8
    // 0x800B6BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6CB8;
    // 0x800B6BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6BC4:
    // 0x800B6BC4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B6BC8: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B6BCC: nop

    // 0x800B6BD0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800B6BD4: nop

    // 0x800B6BD8: ori         $t7, $t8, 0x10
    ctx->r15 = ctx->r24 | 0X10;
    // 0x800B6BDC: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
    // 0x800B6BE0: b           L_800B6CA8
    // 0x800B6BE4: nop

        goto L_800B6CA8;
    // 0x800B6BE4: nop

L_800B6BE8:
    // 0x800B6BE8: jal         0x800B6E04
    // 0x800B6BEC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B6E04(rdram, ctx);
        goto after_1;
    // 0x800B6BEC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x800B6BF0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B6BF4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800B6BF8: nop

    // 0x800B6BFC: bgez        $t9, L_800B6C0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B6C00: nop

            goto L_800B6C0C;
    }
    // 0x800B6C00: nop

    // 0x800B6C04: b           L_800B6CB8
    // 0x800B6C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6CB8;
    // 0x800B6C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6C0C:
    // 0x800B6C0C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B6C10: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B6C14: nop

    // 0x800B6C18: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B6C1C: nop

    // 0x800B6C20: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x800B6C24: sh          $t2, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r10;
    // 0x800B6C28: b           L_800B6CA8
    // 0x800B6C2C: nop

        goto L_800B6CA8;
    // 0x800B6C2C: nop

L_800B6C30:
    // 0x800B6C30: jal         0x800B73DC
    // 0x800B6C34: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B73DC(rdram, ctx);
        goto after_2;
    // 0x800B6C34: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800B6C38: beq         $v0, $zero, L_800B6C48
    if (ctx->r2 == 0) {
        // 0x800B6C3C: nop

            goto L_800B6C48;
    }
    // 0x800B6C3C: nop

    // 0x800B6C40: b           L_800B6CB8
    // 0x800B6C44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B6CB8;
    // 0x800B6C44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6C48:
    // 0x800B6C48: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B6C4C: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B6C50: nop

    // 0x800B6C54: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x800B6C58: nop

    // 0x800B6C5C: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x800B6C60: sh          $t5, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r13;
    // 0x800B6C64: b           L_800B6CA8
    // 0x800B6C68: nop

        goto L_800B6CA8;
    // 0x800B6C68: nop

L_800B6C6C:
    // 0x800B6C6C: jal         0x800B749C
    // 0x800B6C70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B749C(rdram, ctx);
        goto after_3;
    // 0x800B6C70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x800B6C74: beq         $v0, $zero, L_800B6C84
    if (ctx->r2 == 0) {
        // 0x800B6C78: nop

            goto L_800B6C84;
    }
    // 0x800B6C78: nop

    // 0x800B6C7C: b           L_800B6CB8
    // 0x800B6C80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B6CB8;
    // 0x800B6C80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6C84:
    // 0x800B6C84: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B6C88: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B6C8C: nop

    // 0x800B6C90: lhu         $t7, 0x4($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X4);
    // 0x800B6C94: nop

    // 0x800B6C98: ori         $t6, $t7, 0x80
    ctx->r14 = ctx->r15 | 0X80;
    // 0x800B6C9C: sh          $t6, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r14;
    // 0x800B6CA0: b           L_800B6CA8
    // 0x800B6CA4: nop

        goto L_800B6CA8;
    // 0x800B6CA4: nop

L_800B6CA8:
    // 0x800B6CA8: b           L_800B6CB8
    // 0x800B6CAC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800B6CB8;
    // 0x800B6CAC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800B6CB0: b           L_800B6CB8
    // 0x800B6CB4: nop

        goto L_800B6CB8;
    // 0x800B6CB4: nop

L_800B6CB8:
    // 0x800B6CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6CBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B6CC0: jr          $ra
    // 0x800B6CC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B6CC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800B6CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6CC8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B6CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B6CD0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800B6CD4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B6CD8: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x800B6CDC: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800B6CE0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B6CE4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800B6CE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B6CEC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B6CF0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B6CF4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B6CF8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B6CFC: nop

    // 0x800B6D00: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800B6D04: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B6D08: nop

    // 0x800B6D0C: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B6D10: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B6D14: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800B6D18: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D1C: nop

    // 0x800B6D20: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800B6D24: nop

    // 0x800B6D28: andi        $t0, $t9, 0xF800
    ctx->r8 = ctx->r25 & 0XF800;
    // 0x800B6D2C: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x800B6D30: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800B6D34: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D38: nop

    // 0x800B6D3C: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800B6D40: nop

    // 0x800B6D44: andi        $t4, $t3, 0x7C0
    ctx->r12 = ctx->r11 & 0X7C0;
    // 0x800B6D48: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800B6D4C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800B6D50: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D54: nop

    // 0x800B6D58: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x800B6D5C: nop

    // 0x800B6D60: andi        $t8, $t7, 0x3E
    ctx->r24 = ctx->r15 & 0X3E;
    // 0x800B6D64: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B6D68: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800B6D6C: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x800B6D70: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B6D74: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D78: nop

    // 0x800B6D7C: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x800B6D80: nop

    // 0x800B6D84: bne         $t2, $zero, L_800B6D98
    if (ctx->r10 != 0) {
        // 0x800B6D88: nop

            goto L_800B6D98;
    }
    // 0x800B6D88: nop

    // 0x800B6D8C: addiu       $t3, $zero, 0xA8
    ctx->r11 = ADD32(0, 0XA8);
    // 0x800B6D90: b           L_800B6DA0
    // 0x800B6D94: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
        goto L_800B6DA0;
    // 0x800B6D94: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_800B6D98:
    // 0x800B6D98: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x800B6D9C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_800B6DA0:
    // 0x800B6DA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B6DA4: nop

    // 0x800B6DA8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800B6DAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B6DB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B6DB4: nop

    // 0x800B6DB8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800B6DBC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B6DC0: nop

    // 0x800B6DC4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800B6DC8: addiu       $t5, $zero, 0x3E8
    ctx->r13 = ADD32(0, 0X3E8);
    // 0x800B6DCC: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800B6DD0: jal         0x80016620
    // 0x800B6DD4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_0;
    // 0x800B6DD4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800B6DD8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800B6DDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B6DE0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
    // 0x800B6DE4: b           L_800B6DF4
    // 0x800B6DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B6DF4;
    // 0x800B6DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B6DEC: b           L_800B6DF4
    // 0x800B6DF0: nop

        goto L_800B6DF4;
    // 0x800B6DF0: nop

L_800B6DF4:
    // 0x800B6DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6DF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800B6DFC: jr          $ra
    // 0x800B6E00: nop

    return;
    // 0x800B6E00: nop

;}
RECOMP_FUNC void func_800B6E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6E04: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B6E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B6E0C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800B6E10: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800B6E14: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800B6E18: nop

    // 0x800B6E1C: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B6E20: nop

    // 0x800B6E24: bne         $t7, $zero, L_800B6E34
    if (ctx->r15 != 0) {
        // 0x800B6E28: nop

            goto L_800B6E34;
    }
    // 0x800B6E28: nop

    // 0x800B6E2C: b           L_800B73CC
    // 0x800B6E30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B73CC;
    // 0x800B6E30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6E34:
    // 0x800B6E34: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800B6E38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B6E3C: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x800B6E40: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B6E44: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B6E48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B6E4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B6E50: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B6E54: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B6E58: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B6E5C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800B6E60: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B6E64: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800B6E68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B6E6C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B6E70: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800B6E74: nop

    // 0x800B6E78: bc1f        L_800B6E94
    if (!c1cs) {
        // 0x800B6E7C: nop

            goto L_800B6E94;
    }
    // 0x800B6E7C: nop

    // 0x800B6E80: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800B6E84: nop

    // 0x800B6E88: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x800B6E8C: b           L_800B6EB4
    // 0x800B6E90: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
        goto L_800B6EB4;
    // 0x800B6E90: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
L_800B6E94:
    // 0x800B6E94: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B6E98: nop

    // 0x800B6E9C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800B6EA0: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800B6EA4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800B6EA8: nop

    // 0x800B6EAC: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x800B6EB0: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
L_800B6EB4:
    // 0x800B6EB4: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800B6EB8: nop

    // 0x800B6EBC: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800B6EC0: nop

    // 0x800B6EC4: bne         $t5, $zero, L_800B7298
    if (ctx->r13 != 0) {
        // 0x800B6EC8: nop

            goto L_800B7298;
    }
    // 0x800B6EC8: nop

    // 0x800B6ECC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800B6ED0: nop

    // 0x800B6ED4: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x800B6ED8: jal         0x8000D688
    // 0x800B6EDC: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B6EDC: nop

    after_0:
    // 0x800B6EE0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B6EE4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800B6EE8: nop

    // 0x800B6EEC: bne         $t7, $zero, L_800B6EFC
    if (ctx->r15 != 0) {
        // 0x800B6EF0: nop

            goto L_800B6EFC;
    }
    // 0x800B6EF0: nop

    // 0x800B6EF4: b           L_800B73CC
    // 0x800B6EF8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800B73CC;
    // 0x800B6EF8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800B6EFC:
    // 0x800B6EFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800B6F00: nop

    // 0x800B6F04: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x800B6F08: nop

    // 0x800B6F0C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B6F10: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6F14: nop

    // 0x800B6F18: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800B6F1C: nop

    // 0x800B6F20: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800B6F24: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800B6F28: nop

    // 0x800B6F2C: lhu         $t3, 0xA($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XA);
    // 0x800B6F30: nop

    // 0x800B6F34: bne         $t3, $zero, L_800B6F64
    if (ctx->r11 != 0) {
        // 0x800B6F38: nop

            goto L_800B6F64;
    }
    // 0x800B6F38: nop

    // 0x800B6F3C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B6F40: nop

    // 0x800B6F44: lwc1        $f18, 0xCC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B6F48: nop

    // 0x800B6F4C: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800B6F50: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B6F54: nop

    // 0x800B6F58: lwc1        $f4, 0xD0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x800B6F5C: b           L_800B7290
    // 0x800B6F60: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
        goto L_800B7290;
    // 0x800B6F60: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_800B6F64:
    // 0x800B6F64: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x800B6F68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B6F6C: nop

    // 0x800B6F70: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800B6F74: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x800B6F78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6F7C: nop

    // 0x800B6F80: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800B6F84: lui         $at, 0xC30C
    ctx->r1 = S32(0XC30C << 16);
    // 0x800B6F88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B6F8C: nop

    // 0x800B6F90: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800B6F94: lui         $at, 0xC2E0
    ctx->r1 = S32(0XC2E0 << 16);
    // 0x800B6F98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B6F9C: nop

    // 0x800B6FA0: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800B6FA4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B6FA8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6FAC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B6FB0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800B6FB4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800B6FB8: nop

    // 0x800B6FBC: blez        $t8, L_800B7104
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B6FC0: nop

            goto L_800B7104;
    }
    // 0x800B6FC0: nop

L_800B6FC4:
    // 0x800B6FC4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800B6FC8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B6FCC: lw          $t0, 0x104($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X104);
    // 0x800B6FD0: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800B6FD4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B6FD8: nop

    // 0x800B6FDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B6FE0: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B6FE4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800B6FE8: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800B6FEC: bc1f        L_800B7000
    if (!c1cs) {
        // 0x800B6FF0: nop

            goto L_800B7000;
    }
    // 0x800B6FF0: nop

    // 0x800B6FF4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B6FF8: nop

    // 0x800B6FFC: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
L_800B7000:
    // 0x800B7000: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7004: nop

    // 0x800B7008: lw          $t2, 0x108($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X108);
    // 0x800B700C: lh          $t3, 0x102($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X102);
    // 0x800B7010: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800B7014: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800B7018: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B701C: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x800B7020: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B7024: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7028: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B702C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800B7030: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800B7034: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x800B7038: bc1f        L_800B704C
    if (!c1cs) {
        // 0x800B703C: nop

            goto L_800B704C;
    }
    // 0x800B703C: nop

    // 0x800B7040: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B7044: nop

    // 0x800B7048: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_800B704C:
    // 0x800B704C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B7050: nop

    // 0x800B7054: lw          $t5, 0x104($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X104);
    // 0x800B7058: lh          $t6, 0x100($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X100);
    // 0x800B705C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B7060: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B7064: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B7068: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B706C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7070: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B7074: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B7078: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B707C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800B7080: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800B7084: bc1f        L_800B7098
    if (!c1cs) {
        // 0x800B7088: nop

            goto L_800B7098;
    }
    // 0x800B7088: nop

    // 0x800B708C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B7090: nop

    // 0x800B7094: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
L_800B7098:
    // 0x800B7098: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B709C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B70A0: lw          $t8, 0x108($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X108);
    // 0x800B70A4: lwc1        $f4, 0xD0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x800B70A8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800B70AC: nop

    // 0x800B70B0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B70B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B70B8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800B70BC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800B70C0: bc1f        L_800B70D4
    if (!c1cs) {
        // 0x800B70C4: nop

            goto L_800B70D4;
    }
    // 0x800B70C4: nop

    // 0x800B70C8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B70CC: nop

    // 0x800B70D0: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
L_800B70D4:
    // 0x800B70D4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800B70D8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B70DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B70E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B70E4: addiu       $t1, $t2, 0x160
    ctx->r9 = ADD32(ctx->r10, 0X160);
    // 0x800B70E8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800B70EC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800B70F0: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x800B70F4: nop

    // 0x800B70F8: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B70FC: bne         $at, $zero, L_800B6FC4
    if (ctx->r1 != 0) {
        // 0x800B7100: nop

            goto L_800B6FC4;
    }
    // 0x800B7100: nop

L_800B7104:
    // 0x800B7104: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B7108: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B710C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800B7110: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B7114: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B711C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B7120: nop

    // 0x800B7124: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800B7128: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B712C: nop

    // 0x800B7130: lwc1        $f18, 0xF4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x800B7134: nop

    // 0x800B7138: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B713C: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800B7140: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B7144: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800B7148: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B714C: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B7150: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800B7154: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800B7158: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B715C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B7160: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800B7164: nop

    // 0x800B7168: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800B716C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B7170: nop

    // 0x800B7174: lwc1        $f10, 0xF8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XF8);
    // 0x800B7178: nop

    // 0x800B717C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800B7180: mul.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x800B7184: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800B7188: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800B718C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B7190: nop

    // 0x800B7194: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800B7198: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B719C: nop

    // 0x800B71A0: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800B71A4: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800B71A8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800B71AC: lhu         $t8, 0xA($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XA);
    // 0x800B71B0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B71B4: subu        $t2, $t9, $t8
    ctx->r10 = SUB32(ctx->r25, ctx->r24);
    // 0x800B71B8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800B71BC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B71C0: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B71C4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B71C8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B71CC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800B71D0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800B71D4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800B71D8: lhu         $t3, 0xA($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0XA);
    // 0x800B71DC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B71E0: subu        $t5, $t0, $t3
    ctx->r13 = SUB32(ctx->r8, ctx->r11);
    // 0x800B71E4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B71E8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B71EC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B71F0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B71F4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B71F8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800B71FC: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800B7200: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800B7204: lhu         $t6, 0xA($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0XA);
    // 0x800B7208: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B720C: subu        $t9, $t7, $t6
    ctx->r25 = SUB32(ctx->r15, ctx->r14);
    // 0x800B7210: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800B7214: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B7218: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B721C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B7220: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7224: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800B7228: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800B722C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x800B7230: lhu         $t2, 0xA($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0XA);
    // 0x800B7234: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B7238: subu        $t0, $t1, $t2
    ctx->r8 = SUB32(ctx->r9, ctx->r10);
    // 0x800B723C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800B7240: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B7244: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B7248: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B724C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7250: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800B7254: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B7258: nop

    // 0x800B725C: lwc1        $f8, 0xCC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x800B7260: nop

    // 0x800B7264: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800B7268: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B726C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B7270: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B7274: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800B7278: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B727C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7280: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B7284: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800B7288: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x800B728C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_800B7290:
    // 0x800B7290: b           L_800B72D8
    // 0x800B7294: nop

        goto L_800B72D8;
    // 0x800B7294: nop

L_800B7298:
    // 0x800B7298: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800B729C: nop

    // 0x800B72A0: lh          $t4, 0x8($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X8);
    // 0x800B72A4: nop

    // 0x800B72A8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800B72AC: nop

    // 0x800B72B0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B72B4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x800B72B8: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800B72BC: nop

    // 0x800B72C0: lh          $t6, 0xA($t7)
    ctx->r14 = MEM_H(ctx->r15, 0XA);
    // 0x800B72C4: nop

    // 0x800B72C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800B72CC: nop

    // 0x800B72D0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B72D4: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
L_800B72D8:
    // 0x800B72D8: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x800B72DC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B72E0: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B72E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B72E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B72EC: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800B72F0: lwc1        $f7, -0x5A8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5A8);
    // 0x800B72F4: lwc1        $f6, -0x5A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A4);
    // 0x800B72F8: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x800B72FC: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x800B7300: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800B7304: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800B7308: lui         $at, 0xC02C
    ctx->r1 = S32(0XC02C << 16);
    // 0x800B730C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B7310: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B7314: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B7318: lui         $at, 0x405C
    ctx->r1 = S32(0X405C << 16);
    // 0x800B731C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800B7320: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7324: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7328: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x800B732C: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800B7330: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x800B7334: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800B7338: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800B733C: nop

    // 0x800B7340: lhu         $t8, 0xC($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0XC);
    // 0x800B7344: nop

    // 0x800B7348: beq         $t8, $zero, L_800B735C
    if (ctx->r24 == 0) {
        // 0x800B734C: nop

            goto L_800B735C;
    }
    // 0x800B734C: nop

    // 0x800B7350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7354: bne         $t8, $at, L_800B736C
    if (ctx->r24 != ctx->r1) {
        // 0x800B7358: nop

            goto L_800B736C;
    }
    // 0x800B7358: nop

L_800B735C:
    // 0x800B735C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800B7360: nop

    // 0x800B7364: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x800B7368: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
L_800B736C:
    // 0x800B736C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800B7370: nop

    // 0x800B7374: lhu         $t3, 0xC($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0XC);
    // 0x800B7378: nop

    // 0x800B737C: beq         $t3, $zero, L_800B7390
    if (ctx->r11 == 0) {
        // 0x800B7380: nop

            goto L_800B7390;
    }
    // 0x800B7380: nop

    // 0x800B7384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B7388: bne         $t3, $at, L_800B73A0
    if (ctx->r11 != ctx->r1) {
        // 0x800B738C: nop

            goto L_800B73A0;
    }
    // 0x800B738C: nop

L_800B7390:
    // 0x800B7390: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800B7394: nop

    // 0x800B7398: ori         $t4, $t5, 0x2
    ctx->r12 = ctx->r13 | 0X2;
    // 0x800B739C: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_800B73A0:
    // 0x800B73A0: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B73A4: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B73A8: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800B73AC: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x800B73B0: jal         0x80016BF4
    // 0x800B73B4: nop

    func_80016BF4(rdram, ctx);
        goto after_1;
    // 0x800B73B4: nop

    after_1:
    // 0x800B73B8: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x800B73BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B73C0: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
    // 0x800B73C4: b           L_800B73CC
    // 0x800B73C8: nop

        goto L_800B73CC;
    // 0x800B73C8: nop

L_800B73CC:
    // 0x800B73CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B73D0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800B73D4: jr          $ra
    // 0x800B73D8: nop

    return;
    // 0x800B73D8: nop

;}
RECOMP_FUNC void func_800B73DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B73DC: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B73E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B73E4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B73E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B73EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B73F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B73F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B73F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B73FC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B7400: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B7404: swc1        $f18, -0x44CC($at)
    MEM_W(-0X44CC, ctx->r1) = ctx->f18.u32l;
    // 0x800B7408: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800B740C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B7410: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B7414: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7418: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B741C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7420: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B7424: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B7428: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B742C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B7430: swc1        $f18, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f18.u32l;
    // 0x800B7434: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x800B7438: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B743C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B7440: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7444: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7448: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B744C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B7450: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B7454: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B7458: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B745C: swc1        $f18, -0x44C4($at)
    MEM_W(-0X44C4, ctx->r1) = ctx->f18.u32l;
    // 0x800B7460: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x800B7464: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B7468: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
    // 0x800B746C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B7470: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x800B7474: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x800B7478: nop

    // 0x800B747C: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x800B7480: sh          $t2, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r10;
    // 0x800B7484: jr          $ra
    // 0x800B7488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B7488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800B748C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B748C: jr          $ra
    // 0x800B7490: nop

    return;
    // 0x800B7490: nop

    // 0x800B7494: jr          $ra
    // 0x800B7498: nop

    return;
    // 0x800B7498: nop

;}
RECOMP_FUNC void func_800B749C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B749C: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x800B74A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B74A4: sw          $t6, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r14;
    // 0x800B74A8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800B74AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B74B0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B74B4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B74B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B74BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B74C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B74C4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B74C8: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B74CC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B74D0: swc1        $f18, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f18.u32l;
    // 0x800B74D4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800B74D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B74DC: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
    // 0x800B74E0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B74E4: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800B74E8: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x800B74EC: nop

    // 0x800B74F0: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x800B74F4: sh          $t1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r9;
    // 0x800B74F8: jr          $ra
    // 0x800B74FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B74FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800B7500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7500: jr          $ra
    // 0x800B7504: nop

    return;
    // 0x800B7504: nop

    // 0x800B7508: jr          $ra
    // 0x800B750C: nop

    return;
    // 0x800B750C: nop

;}
RECOMP_FUNC void func_800B7510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7510: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B7514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B7518: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B751C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B7520: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B7524:
    // 0x800B7524: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B7528: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B752C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7530: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7534: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7538: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B753C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7540: nop

    // 0x800B7544: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7548: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B754C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B7550: nop

    // 0x800B7554: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7558: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800B755C: bne         $at, $zero, L_800B7524
    if (ctx->r1 != 0) {
        // 0x800B7560: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_800B7524;
    }
    // 0x800B7560: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B7564: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B7568: lhu         $s0, 0x2($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0X2);
    // 0x800B756C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800B7570: beq         $s0, $at, L_800B758C
    if (ctx->r16 == ctx->r1) {
        // 0x800B7574: nop

            goto L_800B758C;
    }
    // 0x800B7574: nop

    // 0x800B7578: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800B757C: beq         $s0, $at, L_800B759C
    if (ctx->r16 == ctx->r1) {
        // 0x800B7580: nop

            goto L_800B759C;
    }
    // 0x800B7580: nop

    // 0x800B7584: b           L_800B75BC
    // 0x800B7588: nop

        goto L_800B75BC;
    // 0x800B7588: nop

L_800B758C:
    // 0x800B758C: jal         0x800B8FA8
    // 0x800B7590: nop

    AudioMgr_StopMusic(rdram, ctx);
        goto after_0;
    // 0x800B7590: nop

    after_0:
    // 0x800B7594: b           L_800B75CC
    // 0x800B7598: nop

        goto L_800B75CC;
    // 0x800B7598: nop

L_800B759C:
    // 0x800B759C: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B75A0: lhu         $a0, 0x4($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X4);
    // 0x800B75A4: nop

    // 0x800B75A8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800B75AC: jal         0x80021F20
    // 0x800B75B0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_1;
    // 0x800B75B0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800B75B4: b           L_800B75CC
    // 0x800B75B8: nop

        goto L_800B75CC;
    // 0x800B75B8: nop

L_800B75BC:
    // 0x800B75BC: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800B75C0: lhu         $a0, 0x2($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X2);
    // 0x800B75C4: jal         0x80021ED0
    // 0x800B75C8: nop

    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_2;
    // 0x800B75C8: nop

    after_2:
L_800B75CC:
    // 0x800B75CC: b           L_800B75DC
    // 0x800B75D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B75DC;
    // 0x800B75D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B75D4: b           L_800B75DC
    // 0x800B75D8: nop

        goto L_800B75DC;
    // 0x800B75D8: nop

L_800B75DC:
    // 0x800B75DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B75E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B75E4: jr          $ra
    // 0x800B75E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B75E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B75EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B75EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B75F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B75F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B75F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B75FC:
    // 0x800B75FC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7600: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7604: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7608: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B760C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7610: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7614: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7618: nop

    // 0x800B761C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7620: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7624: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7628: nop

    // 0x800B762C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7630: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B7634: bne         $at, $zero, L_800B75FC
    if (ctx->r1 != 0) {
        // 0x800B7638: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B75FC;
    }
    // 0x800B7638: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B763C: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7640: lhu         $a1, 0x4($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X4);
    // 0x800B7644: lh          $a0, 0x2($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X2);
    // 0x800B7648: lhu         $a2, 0x6($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X6);
    // 0x800B764C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800B7650: jal         0x80021FF8
    // 0x800B7654: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80021FF8(rdram, ctx);
        goto after_0;
    // 0x800B7654: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x800B7658: b           L_800B7668
    // 0x800B765C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7668;
    // 0x800B765C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B7660: b           L_800B7668
    // 0x800B7664: nop

        goto L_800B7668;
    // 0x800B7664: nop

L_800B7668:
    // 0x800B7668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B766C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7670: jr          $ra
    // 0x800B7674: nop

    return;
    // 0x800B7674: nop

;}
RECOMP_FUNC void func_800B7678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B767C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7680: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B7684: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800B7688:
    // 0x800B7688: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B768C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B7690: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7694: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7698: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B769C: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B76A0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B76A4: nop

    // 0x800B76A8: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B76AC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B76B0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B76B4: nop

    // 0x800B76B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B76BC: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B76C0: bne         $at, $zero, L_800B7688
    if (ctx->r1 != 0) {
        // 0x800B76C4: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800B7688;
    }
    // 0x800B76C4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800B76C8: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B76CC: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x800B76D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B76D4: bne         $t6, $at, L_800B76E8
    if (ctx->r14 != ctx->r1) {
        // 0x800B76D8: nop

            goto L_800B76E8;
    }
    // 0x800B76D8: nop

    // 0x800B76DC: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x800B76E0: b           L_800B76F8
    // 0x800B76E4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_800B76F8;
    // 0x800B76E4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800B76E8:
    // 0x800B76E8: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800B76EC: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800B76F0: nop

    // 0x800B76F4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800B76F8:
    // 0x800B76F8: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B76FC: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x800B7700: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B7704: bne         $t1, $at, L_800B7718
    if (ctx->r9 != ctx->r1) {
        // 0x800B7708: nop

            goto L_800B7718;
    }
    // 0x800B7708: nop

    // 0x800B770C: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800B7710: b           L_800B7728
    // 0x800B7714: sb          $t2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r10;
        goto L_800B7728;
    // 0x800B7714: sb          $t2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r10;
L_800B7718:
    // 0x800B7718: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x800B771C: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x800B7720: nop

    // 0x800B7724: sb          $t4, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r12;
L_800B7728:
    // 0x800B7728: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B772C: nop

    // 0x800B7730: bne         $t5, $zero, L_800B7750
    if (ctx->r13 != 0) {
        // 0x800B7734: nop

            goto L_800B7750;
    }
    // 0x800B7734: nop

    // 0x800B7738: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B773C: lhu         $a0, 0x2($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X2);
    // 0x800B7740: jal         0x800220F4
    // 0x800B7744: nop

    func_800220F4(rdram, ctx);
        goto after_0;
    // 0x800B7744: nop

    after_0:
    // 0x800B7748: b           L_800B7768
    // 0x800B774C: nop

        goto L_800B7768;
    // 0x800B774C: nop

L_800B7750:
    // 0x800B7750: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B7754: lhu         $a0, 0x2($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7758: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B775C: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    // 0x800B7760: jal         0x8002206C
    // 0x800B7764: nop

    func_8002206C(rdram, ctx);
        goto after_1;
    // 0x800B7764: nop

    after_1:
L_800B7768:
    // 0x800B7768: b           L_800B7778
    // 0x800B776C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7778;
    // 0x800B776C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B7770: b           L_800B7778
    // 0x800B7774: nop

        goto L_800B7778;
    // 0x800B7774: nop

L_800B7778:
    // 0x800B7778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B777C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B7780: jr          $ra
    // 0x800B7784: nop

    return;
    // 0x800B7784: nop

;}
RECOMP_FUNC void func_800B7788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7788: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B778C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800B7790:
    // 0x800B7790: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800B7794: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7798: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B779C: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B77A0: sh          $t6, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r14;
    // 0x800B77A4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B77A8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B77AC: nop

    // 0x800B77B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B77B4: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x800B77B8: bne         $at, $zero, L_800B7790
    if (ctx->r1 != 0) {
        // 0x800B77BC: sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
            goto L_800B7790;
    }
    // 0x800B77BC: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800B77C0: b           L_800B77D0
    // 0x800B77C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B77D0;
    // 0x800B77C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B77C8: b           L_800B77D0
    // 0x800B77CC: nop

        goto L_800B77D0;
    // 0x800B77CC: nop

L_800B77D0:
    // 0x800B77D0: jr          $ra
    // 0x800B77D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B77D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B77D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B77D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B77DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B77E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B77E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B77E8:
    // 0x800B77E8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B77EC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B77F0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B77F4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B77F8: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B77FC: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B7800: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7804: nop

    // 0x800B7808: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B780C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B7810: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B7814: nop

    // 0x800B7818: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B781C: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B7820: bne         $at, $zero, L_800B77E8
    if (ctx->r1 != 0) {
        // 0x800B7824: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_800B77E8;
    }
    // 0x800B7824: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B7828: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B782C: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7830: ori         $at, $zero, 0xE000
    ctx->r1 = 0 | 0XE000;
    // 0x800B7834: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7838: bne         $at, $zero, L_800B7850
    if (ctx->r1 != 0) {
        // 0x800B783C: nop

            goto L_800B7850;
    }
    // 0x800B783C: nop

    // 0x800B7840: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B7844: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7848: bne         $at, $zero, L_800B7858
    if (ctx->r1 != 0) {
        // 0x800B784C: nop

            goto L_800B7858;
    }
    // 0x800B784C: nop

L_800B7850:
    // 0x800B7850: b           L_800B79EC
    // 0x800B7854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B79EC;
    // 0x800B7854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7858:
    // 0x800B7858: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B785C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B7860: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B7864: lhu         $t7, 0x2($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7868: nop

    // 0x800B786C: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x800B7870: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B7874: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B7878: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B787C: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B7880: nop

    // 0x800B7884: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x800B7888: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x800B788C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B7890: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B7894: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x800B7898: nop

    // 0x800B789C: sh          $t4, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r12;
    // 0x800B78A0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B78A4: lhu         $t8, 0x2($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X2);
    // 0x800B78A8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800B78AC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x800B78B0: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x800B78B4: sltiu       $at, $t7, 0x12
    ctx->r1 = ctx->r15 < 0X12 ? 1 : 0;
    // 0x800B78B8: beq         $at, $zero, L_800B79C0
    if (ctx->r1 == 0) {
        // 0x800B78BC: nop

            goto L_800B79C0;
    }
    // 0x800B78BC: nop

    // 0x800B78C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B78C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B78C8: addu        $at, $at, $t7
    gpr jr_addend_800B78D4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B78CC: lw          $t7, -0x5A0($at)
    ctx->r15 = ADD32(ctx->r1, -0X5A0);
    // 0x800B78D0: nop

    // 0x800B78D4: jr          $t7
    // 0x800B78D8: nop

    switch (jr_addend_800B78D4 >> 2) {
        case 0: goto L_800B78DC; break;
        case 1: goto L_800B7928; break;
        case 2: goto L_800B7928; break;
        case 3: goto L_800B7928; break;
        case 4: goto L_800B79C0; break;
        case 5: goto L_800B79C0; break;
        case 6: goto L_800B79C0; break;
        case 7: goto L_800B7928; break;
        case 8: goto L_800B7928; break;
        case 9: goto L_800B7928; break;
        case 10: goto L_800B7928; break;
        case 11: goto L_800B7928; break;
        case 12: goto L_800B7928; break;
        case 13: goto L_800B7928; break;
        case 14: goto L_800B7928; break;
        case 15: goto L_800B7928; break;
        case 16: goto L_800B7928; break;
        case 17: goto L_800B78DC; break;
        default: switch_error(__func__, 0x800B78D4, 0x800EFA60);
    }
    // 0x800B78D8: nop

L_800B78DC:
    // 0x800B78DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B78E0: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B78E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B78E8: nop

    // 0x800B78EC: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x800B78F0: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B78F4: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B78F8: nop

    // 0x800B78FC: bne         $t1, $zero, L_800B7920
    if (ctx->r9 != 0) {
        // 0x800B7900: nop

            goto L_800B7920;
    }
    // 0x800B7900: nop

    // 0x800B7904: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B7908: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B790C: nop

    // 0x800B7910: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x800B7914: nop

    // 0x800B7918: ori         $t4, $t3, 0x400
    ctx->r12 = ctx->r11 | 0X400;
    // 0x800B791C: sh          $t4, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r12;
L_800B7920:
    // 0x800B7920: b           L_800B79C0
    // 0x800B7924: nop

        goto L_800B79C0;
    // 0x800B7924: nop

L_800B7928:
    // 0x800B7928: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B792C: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B7930: nop

    // 0x800B7934: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800B7938: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B793C: lhu         $a0, 0x4($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X4);
    // 0x800B7940: jal         0x8000D688
    // 0x800B7944: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B7944: nop

    after_0:
    // 0x800B7948: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B794C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7950: nop

    // 0x800B7954: bne         $t8, $zero, L_800B7964
    if (ctx->r24 != 0) {
        // 0x800B7958: nop

            goto L_800B7964;
    }
    // 0x800B7958: nop

    // 0x800B795C: b           L_800B79EC
    // 0x800B7960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B79EC;
    // 0x800B7960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7964:
    // 0x800B7964: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7968: nop

    // 0x800B796C: lw          $t9, 0x20C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X20C);
    // 0x800B7970: nop

    // 0x800B7974: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800B7978: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B797C: nop

    // 0x800B7980: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x800B7984: nop

    // 0x800B7988: andi        $t3, $t1, 0x100
    ctx->r11 = ctx->r9 & 0X100;
    // 0x800B798C: beq         $t3, $zero, L_800B799C
    if (ctx->r11 == 0) {
        // 0x800B7990: nop

            goto L_800B799C;
    }
    // 0x800B7990: nop

    // 0x800B7994: b           L_800B79EC
    // 0x800B7998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B79EC;
    // 0x800B7998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B799C:
    // 0x800B799C: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x800B79A0: lhu         $a0, 0x4($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X4);
    // 0x800B79A4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800B79A8: jal         0x8000D934
    // 0x800B79AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8000D934(rdram, ctx);
        goto after_1;
    // 0x800B79AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800B79B0: bgez        $v0, L_800B79C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B79B4: nop

            goto L_800B79C0;
    }
    // 0x800B79B4: nop

    // 0x800B79B8: b           L_800B79EC
    // 0x800B79BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B79EC;
    // 0x800B79BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B79C0:
    // 0x800B79C0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B79C4: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B79C8: nop

    // 0x800B79CC: lhu         $t5, 0x4($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X4);
    // 0x800B79D0: nop

    // 0x800B79D4: ori         $t6, $t5, 0x100
    ctx->r14 = ctx->r13 | 0X100;
    // 0x800B79D8: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x800B79DC: b           L_800B79EC
    // 0x800B79E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B79EC;
    // 0x800B79E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B79E4: b           L_800B79EC
    // 0x800B79E8: nop

        goto L_800B79EC;
    // 0x800B79E8: nop

L_800B79EC:
    // 0x800B79EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B79F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B79F4: jr          $ra
    // 0x800B79F8: nop

    return;
    // 0x800B79F8: nop

;}
RECOMP_FUNC void func_800B79FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B79FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B7A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7A04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B7A08: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B7A0C:
    // 0x800B7A0C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B7A10: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B7A14: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7A18: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7A1C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7A20: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B7A24: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7A28: nop

    // 0x800B7A2C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7A30: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B7A34: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B7A38: nop

    // 0x800B7A3C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7A40: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B7A44: bne         $at, $zero, L_800B7A0C
    if (ctx->r1 != 0) {
        // 0x800B7A48: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_800B7A0C;
    }
    // 0x800B7A48: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B7A4C: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B7A50: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7A54: ori         $at, $zero, 0xE000
    ctx->r1 = 0 | 0XE000;
    // 0x800B7A58: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7A5C: bne         $at, $zero, L_800B7A74
    if (ctx->r1 != 0) {
        // 0x800B7A60: nop

            goto L_800B7A74;
    }
    // 0x800B7A60: nop

    // 0x800B7A64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B7A68: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7A6C: bne         $at, $zero, L_800B7A7C
    if (ctx->r1 != 0) {
        // 0x800B7A70: nop

            goto L_800B7A7C;
    }
    // 0x800B7A70: nop

L_800B7A74:
    // 0x800B7A74: b           L_800B7B84
    // 0x800B7A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7A7C:
    // 0x800B7A7C: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B7A80: lhu         $t7, 0x2($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7A84: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800B7A88: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x800B7A8C: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x800B7A90: sltiu       $at, $t9, 0xD
    ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
    // 0x800B7A94: beq         $at, $zero, L_800B7B50
    if (ctx->r1 == 0) {
        // 0x800B7A98: nop

            goto L_800B7B50;
    }
    // 0x800B7A98: nop

    // 0x800B7A9C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B7AA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B7AA4: addu        $at, $at, $t9
    gpr jr_addend_800B7AB0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B7AA8: lw          $t9, -0x558($at)
    ctx->r25 = ADD32(ctx->r1, -0X558);
    // 0x800B7AAC: nop

    // 0x800B7AB0: jr          $t9
    // 0x800B7AB4: nop

    switch (jr_addend_800B7AB0 >> 2) {
        case 0: goto L_800B7AB8; break;
        case 1: goto L_800B7AB8; break;
        case 2: goto L_800B7AB8; break;
        case 3: goto L_800B7AB8; break;
        case 4: goto L_800B7B50; break;
        case 5: goto L_800B7B50; break;
        case 6: goto L_800B7B50; break;
        case 7: goto L_800B7B50; break;
        case 8: goto L_800B7AB8; break;
        case 9: goto L_800B7AB8; break;
        case 10: goto L_800B7AB8; break;
        case 11: goto L_800B7AB8; break;
        case 12: goto L_800B7AB8; break;
        default: switch_error(__func__, 0x800B7AB0, 0x800EFAA8);
    }
    // 0x800B7AB4: nop

L_800B7AB8:
    // 0x800B7AB8: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B7ABC: lhu         $a0, 0x4($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X4);
    // 0x800B7AC0: jal         0x8000D688
    // 0x800B7AC4: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B7AC4: nop

    after_0:
    // 0x800B7AC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B7ACC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7AD0: nop

    // 0x800B7AD4: bne         $t1, $zero, L_800B7AE4
    if (ctx->r9 != 0) {
        // 0x800B7AD8: nop

            goto L_800B7AE4;
    }
    // 0x800B7AD8: nop

    // 0x800B7ADC: b           L_800B7B84
    // 0x800B7AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7AE4:
    // 0x800B7AE4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7AE8: nop

    // 0x800B7AEC: lw          $t3, 0x20C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20C);
    // 0x800B7AF0: nop

    // 0x800B7AF4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800B7AF8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7AFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B7B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B7B04: lwc1        $f4, 0x1F0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1F0);
    // 0x800B7B08: nop

    // 0x800B7B0C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800B7B10: nop

    // 0x800B7B14: bc1f        L_800B7B24
    if (!c1cs) {
        // 0x800B7B18: nop

            goto L_800B7B24;
    }
    // 0x800B7B18: nop

    // 0x800B7B1C: b           L_800B7B84
    // 0x800B7B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B7B84;
    // 0x800B7B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B7B24:
    // 0x800B7B24: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B7B28: lhu         $a0, 0x4($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X4);
    // 0x800B7B2C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800B7B30: jal         0x8000D934
    // 0x800B7B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8000D934(rdram, ctx);
        goto after_1;
    // 0x800B7B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800B7B38: bgez        $v0, L_800B7B48
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B7B3C: nop

            goto L_800B7B48;
    }
    // 0x800B7B3C: nop

    // 0x800B7B40: b           L_800B7B84
    // 0x800B7B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7B48:
    // 0x800B7B48: b           L_800B7B58
    // 0x800B7B4C: nop

        goto L_800B7B58;
    // 0x800B7B4C: nop

L_800B7B50:
    // 0x800B7B50: b           L_800B7B84
    // 0x800B7B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7B84;
    // 0x800B7B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7B58:
    // 0x800B7B58: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7B5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B7B60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B7B64: lwc1        $f8, 0x1F0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1F0);
    // 0x800B7B68: nop

    // 0x800B7B6C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B7B70: swc1        $f16, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = ctx->f16.u32l;
    // 0x800B7B74: b           L_800B7B84
    // 0x800B7B78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7B84;
    // 0x800B7B78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B7B7C: b           L_800B7B84
    // 0x800B7B80: nop

        goto L_800B7B84;
    // 0x800B7B80: nop

L_800B7B84:
    // 0x800B7B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7B88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B7B8C: jr          $ra
    // 0x800B7B90: nop

    return;
    // 0x800B7B90: nop

;}
RECOMP_FUNC void func_800B7B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7B94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7B9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B7BA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B7BA4:
    // 0x800B7BA4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7BA8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7BAC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7BB0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7BB4: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7BB8: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7BBC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7BC0: nop

    // 0x800B7BC4: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7BC8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7BCC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7BD0: nop

    // 0x800B7BD4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7BD8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800B7BDC: bne         $at, $zero, L_800B7BA4
    if (ctx->r1 != 0) {
        // 0x800B7BE0: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B7BA4;
    }
    // 0x800B7BE0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B7BE4: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7BE8: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7BEC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800B7BF0: jal         0x8000D934
    // 0x800B7BF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8000D934(rdram, ctx);
        goto after_0;
    // 0x800B7BF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800B7BF8: bgez        $v0, L_800B7C08
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B7BFC: nop

            goto L_800B7C08;
    }
    // 0x800B7BFC: nop

    // 0x800B7C00: b           L_800B7C3C
    // 0x800B7C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7C3C;
    // 0x800B7C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7C08:
    // 0x800B7C08: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B7C0C: lw          $t6, -0x7F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7F4);
    // 0x800B7C10: nop

    // 0x800B7C14: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B7C18: nop

    // 0x800B7C1C: lw          $t7, 0x1A8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X1A8);
    // 0x800B7C20: nop

    // 0x800B7C24: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x800B7C28: sw          $t9, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = ctx->r25;
    // 0x800B7C2C: b           L_800B7C3C
    // 0x800B7C30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B7C3C;
    // 0x800B7C30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7C34: b           L_800B7C3C
    // 0x800B7C38: nop

        goto L_800B7C3C;
    // 0x800B7C38: nop

L_800B7C3C:
    // 0x800B7C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7C40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7C44: jr          $ra
    // 0x800B7C48: nop

    return;
    // 0x800B7C48: nop

;}
RECOMP_FUNC void func_800B7C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7C4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7C54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B7C58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B7C5C:
    // 0x800B7C5C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7C60: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7C64: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7C68: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7C6C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7C70: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7C74: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7C78: nop

    // 0x800B7C7C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7C80: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7C84: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7C88: nop

    // 0x800B7C8C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7C90: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B7C94: bne         $at, $zero, L_800B7C5C
    if (ctx->r1 != 0) {
        // 0x800B7C98: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B7C5C;
    }
    // 0x800B7C98: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B7C9C: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7CA0: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7CA4: jal         0x8000D688
    // 0x800B7CA8: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B7CA8: nop

    after_0:
    // 0x800B7CAC: beq         $v0, $zero, L_800B7CBC
    if (ctx->r2 == 0) {
        // 0x800B7CB0: nop

            goto L_800B7CBC;
    }
    // 0x800B7CB0: nop

    // 0x800B7CB4: b           L_800B7D10
    // 0x800B7CB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7D10;
    // 0x800B7CB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800B7CBC:
    // 0x800B7CBC: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x800B7CC0: lhu         $a0, 0x2($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X2);
    // 0x800B7CC4: jal         0x8000D5A8
    // 0x800B7CC8: nop

    func_8000D5A8(rdram, ctx);
        goto after_1;
    // 0x800B7CC8: nop

    after_1:
    // 0x800B7CCC: beq         $v0, $zero, L_800B7CDC
    if (ctx->r2 == 0) {
        // 0x800B7CD0: nop

            goto L_800B7CDC;
    }
    // 0x800B7CD0: nop

    // 0x800B7CD4: b           L_800B7D10
    // 0x800B7CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7D10;
    // 0x800B7CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7CDC:
    // 0x800B7CDC: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800B7CE0: lhu         $a0, 0x2($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7CE4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B7CE8: jal         0x8000D934
    // 0x800B7CEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8000D934(rdram, ctx);
        goto after_2;
    // 0x800B7CEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x800B7CF0: bgez        $v0, L_800B7D00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B7CF4: nop

            goto L_800B7D00;
    }
    // 0x800B7CF4: nop

    // 0x800B7CF8: b           L_800B7D10
    // 0x800B7CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7D10;
    // 0x800B7CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7D00:
    // 0x800B7D00: b           L_800B7D10
    // 0x800B7D04: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7D10;
    // 0x800B7D04: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B7D08: b           L_800B7D10
    // 0x800B7D0C: nop

        goto L_800B7D10;
    // 0x800B7D0C: nop

L_800B7D10:
    // 0x800B7D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7D14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7D18: jr          $ra
    // 0x800B7D1C: nop

    return;
    // 0x800B7D1C: nop

;}
RECOMP_FUNC void func_800B7D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7D28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B7D2C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B7D30:
    // 0x800B7D30: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7D34: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7D38: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7D3C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7D40: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7D44: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7D48: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7D4C: nop

    // 0x800B7D50: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7D54: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7D58: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7D5C: nop

    // 0x800B7D60: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7D64: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800B7D68: bne         $at, $zero, L_800B7D30
    if (ctx->r1 != 0) {
        // 0x800B7D6C: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B7D30;
    }
    // 0x800B7D6C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B7D70: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7D74: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x800B7D78: nop

    // 0x800B7D7C: bne         $t6, $zero, L_800B7D9C
    if (ctx->r14 != 0) {
        // 0x800B7D80: nop

            goto L_800B7D9C;
    }
    // 0x800B7D80: nop

    // 0x800B7D84: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800B7D88: lhu         $a0, 0x2($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7D8C: jal         0x8005F268
    // 0x800B7D90: nop

    func_8005F268(rdram, ctx);
        goto after_0;
    // 0x800B7D90: nop

    after_0:
    // 0x800B7D94: b           L_800B7DAC
    // 0x800B7D98: nop

        goto L_800B7DAC;
    // 0x800B7D98: nop

L_800B7D9C:
    // 0x800B7D9C: addiu       $t7, $sp, 0x20
    ctx->r15 = ADD32(ctx->r29, 0X20);
    // 0x800B7DA0: lhu         $a0, 0x2($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X2);
    // 0x800B7DA4: jal         0x8005F0DC
    // 0x800B7DA8: nop

    func_8005F0DC(rdram, ctx);
        goto after_1;
    // 0x800B7DA8: nop

    after_1:
L_800B7DAC:
    // 0x800B7DAC: b           L_800B7DBC
    // 0x800B7DB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B7DBC;
    // 0x800B7DB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7DB4: b           L_800B7DBC
    // 0x800B7DB8: nop

        goto L_800B7DBC;
    // 0x800B7DB8: nop

L_800B7DBC:
    // 0x800B7DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7DC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7DC4: jr          $ra
    // 0x800B7DC8: nop

    return;
    // 0x800B7DC8: nop

;}
RECOMP_FUNC void func_800B7DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7DCC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B7DD0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B7DD4:
    // 0x800B7DD4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800B7DD8: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7DDC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B7DE0: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B7DE4: sh          $t6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r14;
    // 0x800B7DE8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7DEC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800B7DF0: nop

    // 0x800B7DF4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B7DF8: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x800B7DFC: bne         $at, $zero, L_800B7DD4
    if (ctx->r1 != 0) {
        // 0x800B7E00: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800B7DD4;
    }
    // 0x800B7E00: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800B7E04: addiu       $t2, $sp, 0x8
    ctx->r10 = ADD32(ctx->r29, 0X8);
    // 0x800B7E08: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800B7E0C: nop

    // 0x800B7E10: bne         $t3, $zero, L_800B7E54
    if (ctx->r11 != 0) {
        // 0x800B7E14: nop

            goto L_800B7E54;
    }
    // 0x800B7E14: nop

    // 0x800B7E18: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B7E1C: lw          $t5, -0x794($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X794);
    // 0x800B7E20: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B7E24: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B7E28: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800B7E2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B7E30: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800B7E34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B7E38: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x800B7E3C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800B7E40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B7E44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B7E48: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800B7E4C: b           L_800B7E84
    // 0x800B7E50: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
        goto L_800B7E84;
    // 0x800B7E50: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
L_800B7E54:
    // 0x800B7E54: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B7E58: lw          $t9, -0x794($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X794);
    // 0x800B7E5C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B7E60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800B7E64: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800B7E68: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800B7E6C: lw          $t8, 0x718C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X718C);
    // 0x800B7E70: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B7E74: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800B7E78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B7E7C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800B7E80: sw          $t1, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r9;
L_800B7E84:
    // 0x800B7E84: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B7E88: sw          $zero, -0x794($at)
    MEM_W(-0X794, ctx->r1) = 0;
    // 0x800B7E8C: b           L_800B7E9C
    // 0x800B7E90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B7E9C;
    // 0x800B7E90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7E94: b           L_800B7E9C
    // 0x800B7E98: nop

        goto L_800B7E9C;
    // 0x800B7E98: nop

L_800B7E9C:
    // 0x800B7E9C: jr          $ra
    // 0x800B7EA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B7EA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800B7EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7EA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7EAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B7EB0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B7EB4:
    // 0x800B7EB4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7EB8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7EBC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7EC0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7EC4: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7EC8: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7ECC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7ED0: nop

    // 0x800B7ED4: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7ED8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7EDC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7EE0: nop

    // 0x800B7EE4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7EE8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800B7EEC: bne         $at, $zero, L_800B7EB4
    if (ctx->r1 != 0) {
        // 0x800B7EF0: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B7EB4;
    }
    // 0x800B7EF0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B7EF4: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7EF8: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7EFC: jal         0x80029C8C
    // 0x800B7F00: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    func_80029C8C(rdram, ctx);
        goto after_0;
    // 0x800B7F00: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    after_0:
    // 0x800B7F04: jal         0x80029ED8
    // 0x800B7F08: nop

    func_80029ED8(rdram, ctx);
        goto after_1;
    // 0x800B7F08: nop

    after_1:
    // 0x800B7F0C: b           L_800B7F1C
    // 0x800B7F10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B7F1C;
    // 0x800B7F10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7F14: b           L_800B7F1C
    // 0x800B7F18: nop

        goto L_800B7F1C;
    // 0x800B7F18: nop

L_800B7F1C:
    // 0x800B7F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7F24: jr          $ra
    // 0x800B7F28: nop

    return;
    // 0x800B7F28: nop

;}
RECOMP_FUNC void func_800B7F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7F2C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B7F30: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800B7F34:
    // 0x800B7F34: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800B7F38: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7F3C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B7F40: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B7F44: sh          $t6, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r14;
    // 0x800B7F48: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7F4C: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B7F50: nop

    // 0x800B7F54: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B7F58: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x800B7F5C: bne         $at, $zero, L_800B7F34
    if (ctx->r1 != 0) {
        // 0x800B7F60: sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
            goto L_800B7F34;
    }
    // 0x800B7F60: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800B7F64: addiu       $t2, $sp, 0x4
    ctx->r10 = ADD32(ctx->r29, 0X4);
    // 0x800B7F68: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800B7F6C: nop

    // 0x800B7F70: bne         $t3, $zero, L_800B7F98
    if (ctx->r11 != 0) {
        // 0x800B7F74: nop

            goto L_800B7F98;
    }
    // 0x800B7F74: nop

    // 0x800B7F78: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B7F7C: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B7F80: nop

    // 0x800B7F84: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800B7F88: nop

    // 0x800B7F8C: ori         $t7, $t5, 0x200
    ctx->r15 = ctx->r13 | 0X200;
    // 0x800B7F90: b           L_800B7FB4
    // 0x800B7F94: sh          $t7, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r15;
        goto L_800B7FB4;
    // 0x800B7F94: sh          $t7, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r15;
L_800B7F98:
    // 0x800B7F98: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B7F9C: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B7FA0: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800B7FA4: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800B7FA8: nop

    // 0x800B7FAC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800B7FB0: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
L_800B7FB4:
    // 0x800B7FB4: b           L_800B7FC4
    // 0x800B7FB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B7FC4;
    // 0x800B7FB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B7FBC: b           L_800B7FC4
    // 0x800B7FC0: nop

        goto L_800B7FC4;
    // 0x800B7FC0: nop

L_800B7FC4:
    // 0x800B7FC4: jr          $ra
    // 0x800B7FC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B7FC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B7FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7FCC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B7FD0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800B7FD4:
    // 0x800B7FD4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800B7FD8: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7FDC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B7FE0: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B7FE4: sh          $t6, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r14;
    // 0x800B7FE8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7FEC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B7FF0: nop

    // 0x800B7FF4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B7FF8: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x800B7FFC: bne         $at, $zero, L_800B7FD4
    if (ctx->r1 != 0) {
        // 0x800B8000: sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
            goto L_800B7FD4;
    }
    // 0x800B8000: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800B8004: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B8008: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x800B800C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x800B8010: lw          $t2, 0x718C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X718C);
    // 0x800B8014: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B8018: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800B801C: sw          $t5, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r13;
    // 0x800B8020: b           L_800B8030
    // 0x800B8024: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B8030;
    // 0x800B8024: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B8028: b           L_800B8030
    // 0x800B802C: nop

        goto L_800B8030;
    // 0x800B802C: nop

L_800B8030:
    // 0x800B8030: jr          $ra
    // 0x800B8034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B8034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
