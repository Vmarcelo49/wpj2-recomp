#include "recomp.h"
#include "shims.h"
#include "funcs.h"

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
RECOMP_FUNC void func_8007012C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007012C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070134: jal         0x80061348
    // 0x80070138: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070138: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x8007013C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070140: b           L_80070150
    // 0x80070144: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80070150;
    // 0x80070144: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070148: b           L_80070150
    // 0x8007014C: nop

        goto L_80070150;
    // 0x8007014C: nop

L_80070150:
    // 0x80070150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070158: jr          $ra
    // 0x8007015C: nop

    return;
    // 0x8007015C: nop

;}
RECOMP_FUNC void func_8007724C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007724C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077254: jal         0x80061488
    // 0x80077258: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077258: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    after_0:
    // 0x8007725C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077260: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077264: b           L_80077274
    // 0x80077268: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077274;
    // 0x80077268: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007726C: b           L_80077274
    // 0x80077270: nop

        goto L_80077274;
    // 0x80077270: nop

L_80077274:
    // 0x80077274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007727C: jr          $ra
    // 0x80077280: nop

    return;
    // 0x80077280: nop

;}
RECOMP_FUNC void func_8008AAA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AAA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AAAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AAB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008AAB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008AAB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008AABC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008AAC0: nop

    // 0x8008AAC4: bne         $t6, $zero, L_8008AB48
    if (ctx->r14 != 0) {
        // 0x8008AAC8: nop
    
            goto L_8008AB48;
    }
    // 0x8008AAC8: nop

    // 0x8008AACC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008AAD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008AAD4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008AAD8: blez        $t8, L_8008AB40
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008AADC: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8008AB40;
    }
    // 0x8008AADC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8008AAE0:
    // 0x8008AAE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AAE4: jal         0x80099E2C
    // 0x8008AAE8: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x8008AAE8: nop

    after_0:
    // 0x8008AAEC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AAF0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008AAF4: sh          $t9, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r25;
    // 0x8008AAF8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AAFC: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x8008AB00: sw          $t1, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r9;
    // 0x8008AB04: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AB08: nop

    // 0x8008AB0C: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x8008AB10: nop

    // 0x8008AB14: ori         $t5, $t4, 0xC
    ctx->r13 = ctx->r12 | 0XC;
    // 0x8008AB18: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x8008AB1C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008AB20: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AB24: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008AB28: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008AB2C: addiu       $t9, $t8, 0x160
    ctx->r25 = ADD32(ctx->r24, 0X160);
    // 0x8008AB30: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8008AB34: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8008AB38: bne         $at, $zero, L_8008AAE0
    if (ctx->r1 != 0) {
        // 0x8008AB3C: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_8008AAE0;
    }
    // 0x8008AB3C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_8008AB40:
    // 0x8008AB40: b           L_8008ABA4
    // 0x8008AB44: nop

        goto L_8008ABA4;
    // 0x8008AB44: nop

L_8008AB48:
    // 0x8008AB48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB4C: jal         0x80099E2C
    // 0x8008AB50: nop

    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x8008AB50: nop

    after_1:
    // 0x8008AB54: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB58: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8008AB5C: sw          $t1, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r9;
    // 0x8008AB60: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB64: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8008AB68: sh          $t4, 0x116($t5)
    MEM_H(0X116, ctx->r13) = ctx->r12;
    // 0x8008AB6C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB70: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8008AB74: sh          $t3, 0x114($t6)
    MEM_H(0X114, ctx->r14) = ctx->r11;
    // 0x8008AB78: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB7C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8008AB80: sw          $t8, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->r24;
    // 0x8008AB84: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB88: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8008AB8C: sh          $t7, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r15;
    // 0x8008AB90: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB94: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8008AB98: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x8008AB9C: b           L_8008ABA4
    // 0x8008ABA0: nop

        goto L_8008ABA4;
    // 0x8008ABA0: nop

L_8008ABA4:
    // 0x8008ABA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ABA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008ABAC: jr          $ra
    // 0x8008ABB0: nop

    return;
    // 0x8008ABB0: nop

;}
RECOMP_FUNC void func_8004B770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B770: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8004B774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004B778: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8004B77C: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x8004B780: nop

    // 0x8004B784: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x8004B788: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B78C: nop

    // 0x8004B790: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8004B794: nop

    // 0x8004B798: sw          $t8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r24;
    // 0x8004B79C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x8004B7A0: nop

    // 0x8004B7A4: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x8004B7A8: lw          $t0, 0x2F9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2F9);
    // 0x8004B7AC: nop

    // 0x8004B7B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8004B7B4: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B7B8: nop

    // 0x8004B7BC: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x8004B7C0: jal         0x80098754
    // 0x8004B7C4: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8004B7C4: nop

    after_0:
    // 0x8004B7C8: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B7CC: jal         0x80032410
    // 0x8004B7D0: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x8004B7D0: nop

    after_1:
    // 0x8004B7D4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8004B7D8: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8004B7DC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8004B7E0: nop

    // 0x8004B7E4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8004B7E8: beq         $t4, $zero, L_8004B818
    if (ctx->r12 == 0) {
        // 0x8004B7EC: nop
    
            goto L_8004B818;
    }
    // 0x8004B7EC: nop

L_8004B7F0:
    // 0x8004B7F0: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B7F4: jal         0x800499B0
    // 0x8004B7F8: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8004B7F8: nop

    after_2:
    // 0x8004B7FC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8004B800: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x8004B804: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8004B808: nop

    // 0x8004B80C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8004B810: bne         $t7, $zero, L_8004B7F0
    if (ctx->r15 != 0) {
        // 0x8004B814: nop
    
            goto L_8004B7F0;
    }
    // 0x8004B814: nop

L_8004B818:
    // 0x8004B818: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8004B81C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B820: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8004B824: lw          $t1, 0x634($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X634);
    // 0x8004B828: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8004B82C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8004B830: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8004B834: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8004B838: lh          $t3, -0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, -0X2);
    // 0x8004B83C: nop

    // 0x8004B840: bne         $t3, $zero, L_8004B85C
    if (ctx->r11 != 0) {
        // 0x8004B844: sh          $t3, 0x1C($sp)
        MEM_H(0X1C, ctx->r29) = ctx->r11;
            goto L_8004B85C;
    }
    // 0x8004B844: sh          $t3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r11;
L_8004B848:
    // 0x8004B848: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B84C: jal         0x800499B0
    // 0x8004B850: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8004B850: nop

    after_3:
    // 0x8004B854: b           L_8004B848
    // 0x8004B858: nop

        goto L_8004B848;
    // 0x8004B858: nop

L_8004B85C:
    // 0x8004B85C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8004B860: lh          $a0, 0x1C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1C);
    // 0x8004B864: lw          $a1, 0x74($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X74);
    // 0x8004B868: lw          $a2, 0x78($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X78);
    // 0x8004B86C: jal         0x80061990
    // 0x8004B870: nop

    func_80061990(rdram, ctx);
        goto after_4;
    // 0x8004B870: nop

    after_4:
L_8004B874:
    // 0x8004B874: jal         0x80031AC8
    // 0x8004B878: nop

    func_80031AC8(rdram, ctx);
        goto after_5;
    // 0x8004B878: nop

    after_5:
    // 0x8004B87C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B880: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8004B884: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B888: beq         $t5, $at, L_8004B8C8
    if (ctx->r13 == ctx->r1) {
        // 0x8004B88C: nop
    
            goto L_8004B8C8;
    }
    // 0x8004B88C: nop

    // 0x8004B890: beq         $t5, $zero, L_8004B8C8
    if (ctx->r13 == 0) {
        // 0x8004B894: nop
    
            goto L_8004B8C8;
    }
    // 0x8004B894: nop

L_8004B898:
    // 0x8004B898: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B89C: jal         0x800499B0
    // 0x8004B8A0: nop

    func_800499B0(rdram, ctx);
        goto after_6;
    // 0x8004B8A0: nop

    after_6:
    // 0x8004B8A4: jal         0x80031AC8
    // 0x8004B8A8: nop

    func_80031AC8(rdram, ctx);
        goto after_7;
    // 0x8004B8A8: nop

    after_7:
    // 0x8004B8AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B8B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8004B8B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B8B8: beq         $t6, $at, L_8004B8C8
    if (ctx->r14 == ctx->r1) {
        // 0x8004B8BC: nop
    
            goto L_8004B8C8;
    }
    // 0x8004B8BC: nop

    // 0x8004B8C0: bne         $t6, $zero, L_8004B898
    if (ctx->r14 != 0) {
        // 0x8004B8C4: nop
    
            goto L_8004B898;
    }
    // 0x8004B8C4: nop

L_8004B8C8:
    // 0x8004B8C8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8004B8CC: nop

    // 0x8004B8D0: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8004B8D4: jal         0x8006081C
    // 0x8004B8D8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8006081C(rdram, ctx);
        goto after_8;
    // 0x8004B8D8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_8:
    // 0x8004B8DC: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8004B8E0: lh          $t8, 0x1E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1E);
    // 0x8004B8E4: nop

    // 0x8004B8E8: beq         $t8, $zero, L_8004B908
    if (ctx->r24 == 0) {
        // 0x8004B8EC: nop
    
            goto L_8004B908;
    }
    // 0x8004B8EC: nop

    // 0x8004B8F0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004B8F4: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x8004B8F8: lw          $a1, 0x74($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X74);
    // 0x8004B8FC: lw          $a2, 0x78($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X78);
    // 0x8004B900: jal         0x80061990
    // 0x8004B904: nop

    func_80061990(rdram, ctx);
        goto after_9;
    // 0x8004B904: nop

    after_9:
L_8004B908:
    // 0x8004B908: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x8004B90C: nop

    // 0x8004B910: bne         $t0, $zero, L_8004B874
    if (ctx->r8 != 0) {
        // 0x8004B914: nop
    
            goto L_8004B874;
    }
    // 0x8004B914: nop

    // 0x8004B918: jal         0x80031AC8
    // 0x8004B91C: nop

    func_80031AC8(rdram, ctx);
        goto after_10;
    // 0x8004B91C: nop

    after_10:
    // 0x8004B920: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B924: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8004B928: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B92C: beq         $t1, $at, L_8004B96C
    if (ctx->r9 == ctx->r1) {
        // 0x8004B930: nop
    
            goto L_8004B96C;
    }
    // 0x8004B930: nop

    // 0x8004B934: beq         $t1, $zero, L_8004B96C
    if (ctx->r9 == 0) {
        // 0x8004B938: nop
    
            goto L_8004B96C;
    }
    // 0x8004B938: nop

L_8004B93C:
    // 0x8004B93C: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B940: jal         0x800499B0
    // 0x8004B944: nop

    func_800499B0(rdram, ctx);
        goto after_11;
    // 0x8004B944: nop

    after_11:
    // 0x8004B948: jal         0x80031AC8
    // 0x8004B94C: nop

    func_80031AC8(rdram, ctx);
        goto after_12;
    // 0x8004B94C: nop

    after_12:
    // 0x8004B950: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B954: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8004B958: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B95C: beq         $t2, $at, L_8004B96C
    if (ctx->r10 == ctx->r1) {
        // 0x8004B960: nop
    
            goto L_8004B96C;
    }
    // 0x8004B960: nop

    // 0x8004B964: bne         $t2, $zero, L_8004B93C
    if (ctx->r10 != 0) {
        // 0x8004B968: nop
    
            goto L_8004B93C;
    }
    // 0x8004B968: nop

L_8004B96C:
    // 0x8004B96C: jal         0x80031B6C
    // 0x8004B970: nop

    func_80031B6C(rdram, ctx);
        goto after_13;
    // 0x8004B970: nop

    after_13:
    // 0x8004B974: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8004B978: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8004B97C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004B980: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B984: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004B988: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004B98C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004B990: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004B994: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004B998: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B99C: nop

    // 0x8004B9A0: sb          $zero, 0x20($t8)
    MEM_B(0X20, ctx->r24) = 0;
    // 0x8004B9A4: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9A8: nop

    // 0x8004B9AC: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8004B9B0: jal         0x80098AD8
    // 0x8004B9B4: nop

    func_80098AD8(rdram, ctx);
        goto after_14;
    // 0x8004B9B4: nop

    after_14:
    // 0x8004B9B8: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9BC: jal         0x80049544
    // 0x8004B9C0: nop

    func_80049544(rdram, ctx);
        goto after_15;
    // 0x8004B9C0: nop

    after_15:
    // 0x8004B9C4: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9C8: nop

    // 0x8004B9CC: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8004B9D0: jal         0x800C0D34
    // 0x8004B9D4: nop

    Thread_StopThread(rdram, ctx);
        goto after_16;
    // 0x8004B9D4: nop

    after_16:
L_8004B9D8:
    // 0x8004B9D8: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9DC: jal         0x800499B0
    // 0x8004B9E0: nop

    func_800499B0(rdram, ctx);
        goto after_17;
    // 0x8004B9E0: nop

    after_17:
    // 0x8004B9E4: b           L_8004B9D8
    // 0x8004B9E8: nop

        goto L_8004B9D8;
    // 0x8004B9E8: nop

    // 0x8004B9EC: b           L_8004B9F4
    // 0x8004B9F0: nop

        goto L_8004B9F4;
    // 0x8004B9F0: nop

L_8004B9F4:
    // 0x8004B9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004B9F8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x8004B9FC: jr          $ra
    // 0x8004BA00: nop

    return;
    // 0x8004BA00: nop

;}
RECOMP_FUNC void func_800AFB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFB70: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x800AFB74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AFB78: sw          $a0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r4;
    // 0x800AFB7C: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x800AFB80: sw          $a2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r6;
    // 0x800AFB84: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800AFB88: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800AFB8C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AFB90: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AFB94: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800AFB98: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AFB9C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800AFBA0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AFBA4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800AFBA8: lhu         $t6, 0x162($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X162);
    // 0x800AFBAC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AFBB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFBB4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800AFBB8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AFBBC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AFBC0: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AFBC4: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AFBC8: lw          $a2, 0x4110($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4110);
    // 0x800AFBCC: jal         0x800BD1FC
    // 0x800AFBD0: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800AFBD0: nop

    after_0:
    // 0x800AFBD4: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x800AFBD8: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800AFBDC: jal         0x800BED70
    // 0x800AFBE0: nop

    Spi_GetHeader(rdram, ctx);
        goto after_1;
    // 0x800AFBE0: nop

    after_1:
    // 0x800AFBE4: sw          $v0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r2;
    // 0x800AFBE8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800AFBEC: addiu       $t8, $t8, 0x4A8
    ctx->r24 = ADD32(ctx->r24, 0X4A8);
    // 0x800AFBF0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800AFBF4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800AFBF8: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800AFBFC: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800AFC00: lw          $a1, 0x15C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X15C);
    // 0x800AFC04: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x800AFC08: jal         0x800BF0B4
    // 0x800AFC0C: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_2;
    // 0x800AFC0C: nop

    after_2:
    // 0x800AFC10: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800AFC14: lw          $t0, 0x494($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X494);
    // 0x800AFC18: nop

    // 0x800AFC1C: sw          $t0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r8;
    // 0x800AFC20: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800AFC24: lw          $t2, 0x154($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X154);
    // 0x800AFC28: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800AFC2C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800AFC30: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x800AFC34: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x800AFC38: nop

    // 0x800AFC3C: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x800AFC40: beq         $t5, $zero, L_800AFC60
    if (ctx->r13 == 0) {
        // 0x800AFC44: sw          $t5, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r13;
            goto L_800AFC60;
    }
    // 0x800AFC44: sw          $t5, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r13;
    // 0x800AFC48: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800AFC4C: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800AFC50: nop

    // 0x800AFC54: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800AFC58: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AFC5C: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
L_800AFC60:
    // 0x800AFC60: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800AFC64: nop

    // 0x800AFC68: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x800AFC6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800AFC70: sw          $t1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r9;
    // 0x800AFC74: sw          $zero, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = 0;
    // 0x800AFC78: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800AFC7C: nop

    // 0x800AFC80: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800AFC84: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x800AFC88: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x800AFC8C: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800AFC90: lui         $t4, 0xBB00
    ctx->r12 = S32(0XBB00 << 16);
    // 0x800AFC94: ori         $t4, $t4, 0x1
    ctx->r12 = ctx->r12 | 0X1;
    // 0x800AFC98: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800AFC9C: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800AFCA0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800AFCA4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800AFCA8: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x800AFCAC: nop

    // 0x800AFCB0: blez        $t8, L_800B085C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AFCB4: nop
    
            goto L_800B085C;
    }
    // 0x800AFCB4: nop

L_800AFCB8:
    // 0x800AFCB8: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x800AFCBC: nop

    // 0x800AFCC0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800AFCC4: sw          $t0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r8;
    // 0x800AFCC8: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x800AFCCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFCD0: lbu         $s0, 0x0($t1)
    ctx->r16 = MEM_BU(ctx->r9, 0X0);
    // 0x800AFCD4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800AFCD8: beq         $s0, $at, L_800AFD00
    if (ctx->r16 == ctx->r1) {
        // 0x800AFCDC: sw          $t2, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r10;
            goto L_800AFD00;
    }
    // 0x800AFCDC: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AFCE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AFCE4: beq         $s0, $at, L_800B0270
    if (ctx->r16 == ctx->r1) {
        // 0x800AFCE8: nop
    
            goto L_800B0270;
    }
    // 0x800AFCE8: nop

    // 0x800AFCEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AFCF0: beq         $s0, $at, L_800B03E0
    if (ctx->r16 == ctx->r1) {
        // 0x800AFCF4: nop
    
            goto L_800B03E0;
    }
    // 0x800AFCF4: nop

    // 0x800AFCF8: b           L_800B084C
    // 0x800AFCFC: nop

        goto L_800B084C;
    // 0x800AFCFC: nop

L_800AFD00:
    // 0x800AFD00: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800AFD04: nop

    // 0x800AFD08: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x800AFD0C: nop

    // 0x800AFD10: sh          $t4, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r12;
    // 0x800AFD14: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x800AFD18: nop

    // 0x800AFD1C: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x800AFD20: nop

    // 0x800AFD24: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x800AFD28: sh          $t7, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r15;
    // 0x800AFD2C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800AFD30: nop

    // 0x800AFD34: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x800AFD38: nop

    // 0x800AFD3C: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800AFD40: sh          $t0, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r8;
    // 0x800AFD44: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800AFD48: nop

    // 0x800AFD4C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800AFD50: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800AFD54: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x800AFD58: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800AFD5C: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x800AFD60: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800AFD64: lh          $t5, 0x14A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X14A);
    // 0x800AFD68: lh          $t9, 0x148($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X148);
    // 0x800AFD6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AFD70: lh          $t4, 0x146($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X146);
    // 0x800AFD74: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800AFD78: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800AFD7C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800AFD80: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800AFD84: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800AFD88: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFD8C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800AFD90: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800AFD94: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800AFD98: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800AFD9C: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800AFDA0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800AFDA4: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800AFDA8: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800AFDAC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800AFDB0: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800AFDB4: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800AFDB8: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x800AFDBC: nop

    // 0x800AFDC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800AFDC4: sw          $t1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r9;
    // 0x800AFDC8: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800AFDCC: nop

    // 0x800AFDD0: addiu       $t2, $t8, 0x3
    ctx->r10 = ADD32(ctx->r24, 0X3);
    // 0x800AFDD4: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AFDD8: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800AFDDC: nop

    // 0x800AFDE0: addiu       $t5, $t4, -0x3
    ctx->r13 = ADD32(ctx->r12, -0X3);
    // 0x800AFDE4: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x800AFDE8: lh          $t3, 0x166($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X166);
    // 0x800AFDEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFDF0: bne         $t3, $at, L_800B0268
    if (ctx->r11 != ctx->r1) {
        // 0x800AFDF4: nop
    
            goto L_800B0268;
    }
    // 0x800AFDF4: nop

    // 0x800AFDF8: lh          $t6, 0x14A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X14A);
    // 0x800AFDFC: nop

    // 0x800AFE00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFE04: addu        $t9, $sp, $t7
    ctx->r25 = ADD32(ctx->r29, ctx->r15);
    // 0x800AFE08: lw          $t9, 0x9C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X9C);
    // 0x800AFE0C: nop

    // 0x800AFE10: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x800AFE14: lh          $t0, 0x148($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X148);
    // 0x800AFE18: nop

    // 0x800AFE1C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AFE20: addu        $t8, $sp, $t1
    ctx->r24 = ADD32(ctx->r29, ctx->r9);
    // 0x800AFE24: lw          $t8, 0x9C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X9C);
    // 0x800AFE28: nop

    // 0x800AFE2C: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x800AFE30: lh          $t2, 0x146($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X146);
    // 0x800AFE34: nop

    // 0x800AFE38: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800AFE3C: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800AFE40: lw          $t5, 0x9C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X9C);
    // 0x800AFE44: nop

    // 0x800AFE48: sw          $t5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r13;
    // 0x800AFE4C: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x800AFE50: nop

    // 0x800AFE54: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x800AFE58: nop

    // 0x800AFE5C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AFE60: nop

    // 0x800AFE64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AFE68: swc1        $f6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f6.u32l;
    // 0x800AFE6C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x800AFE70: nop

    // 0x800AFE74: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x800AFE78: nop

    // 0x800AFE7C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AFE80: nop

    // 0x800AFE84: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AFE88: swc1        $f10, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f10.u32l;
    // 0x800AFE8C: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x800AFE90: nop

    // 0x800AFE94: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x800AFE98: nop

    // 0x800AFE9C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800AFEA0: nop

    // 0x800AFEA4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AFEA8: swc1        $f18, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f18.u32l;
    // 0x800AFEAC: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x800AFEB0: nop

    // 0x800AFEB4: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x800AFEB8: nop

    // 0x800AFEBC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800AFEC0: nop

    // 0x800AFEC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AFEC8: swc1        $f6, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f6.u32l;
    // 0x800AFECC: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x800AFED0: nop

    // 0x800AFED4: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x800AFED8: nop

    // 0x800AFEDC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800AFEE0: nop

    // 0x800AFEE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AFEE8: swc1        $f10, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f10.u32l;
    // 0x800AFEEC: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x800AFEF0: nop

    // 0x800AFEF4: lh          $t6, 0x4($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X4);
    // 0x800AFEF8: nop

    // 0x800AFEFC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800AFF00: nop

    // 0x800AFF04: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AFF08: swc1        $f18, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f18.u32l;
    // 0x800AFF0C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x800AFF10: nop

    // 0x800AFF14: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x800AFF18: nop

    // 0x800AFF1C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800AFF20: nop

    // 0x800AFF24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AFF28: swc1        $f6, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f6.u32l;
    // 0x800AFF2C: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800AFF30: nop

    // 0x800AFF34: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x800AFF38: nop

    // 0x800AFF3C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800AFF40: nop

    // 0x800AFF44: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AFF48: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
    // 0x800AFF4C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800AFF50: nop

    // 0x800AFF54: lh          $t2, 0x4($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4);
    // 0x800AFF58: nop

    // 0x800AFF5C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800AFF60: nop

    // 0x800AFF64: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AFF68: swc1        $f18, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f18.u32l;
    // 0x800AFF6C: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800AFF70: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800AFF74: lwc1        $f8, 0x128($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800AFF78: lwc1        $f16, 0x130($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X130);
    // 0x800AFF7C: lwc1        $f18, 0x11C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AFF80: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x800AFF84: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AFF88: sub.s       $f20, $f6, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800AFF8C: swc1        $f24, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f24.u32l;
    // 0x800AFF90: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AFF94: swc1        $f20, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f20.u32l;
    // 0x800AFF98: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AFF9C: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x800AFFA0: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AFFA4: swc1        $f22, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f22.u32l;
    // 0x800AFFA8: mul.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800AFFAC: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AFFB0: swc1        $f16, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f16.u32l;
    // 0x800AFFB4: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800AFFB8: lwc1        $f4, 0x138($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800AFFBC: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AFFC0: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800AFFC4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800AFFC8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFFCC: sub.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AFFD0: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800AFFD4: swc1        $f20, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f20.u32l;
    // 0x800AFFD8: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800AFFDC: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x800AFFE0: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800AFFE4: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    // 0x800AFFE8: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800AFFEC: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800AFFF0: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800AFFF4: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFFF8: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800AFFFC: nop

    // 0x800B0000: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800B0004: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B0008: swc1        $f6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f6.u32l;
    // 0x800B000C: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B0010: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0014: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B0018: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B001C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800B0020: nop

    // 0x800B0024: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B0028: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B002C: jal         0x800C42A0
    // 0x800B0030: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B0030: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_3:
    // 0x800B0034: swc1        $f0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f0.u32l;
    // 0x800B0038: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B003C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800B0040: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B0044: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x800B0048: c.eq.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d == ctx->f18.d;
    // 0x800B004C: nop

    // 0x800B0050: bc1t        L_800B0268
    if (c1cs) {
        // 0x800B0054: nop
    
            goto L_800B0268;
    }
    // 0x800B0054: nop

    // 0x800B0058: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B005C: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B0060: lwc1        $f7, -0x6D8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6D8);
    // 0x800B0064: lwc1        $f6, -0x6D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6D4);
    // 0x800B0068: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800B006C: nop

    // 0x800B0070: div.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x800B0074: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x800B0078: swc1        $f8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f8.u32l;
    // 0x800B007C: lwc1        $f18, 0x114($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B0080: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B0084: nop

    // 0x800B0088: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B008C: swc1        $f6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f6.u32l;
    // 0x800B0090: lwc1        $f10, 0x110($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0094: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B0098: nop

    // 0x800B009C: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B00A0: swc1        $f8, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f8.u32l;
    // 0x800B00A4: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B00A8: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B00AC: nop

    // 0x800B00B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B00B4: swc1        $f6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f6.u32l;
    // 0x800B00B8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B00BC: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B00C0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B00C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B00C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B00CC: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x800B00D0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B00D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B00D8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B00DC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B00E0: jal         0x800AFAB0
    // 0x800B00E4: nop

    func_800AFAB0(rdram, ctx);
        goto after_4;
    // 0x800B00E4: nop

    after_4:
    // 0x800B00E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B00EC: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B00F0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B00F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B00F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B00FC: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800B0100: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B0104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B0108: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B010C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B0110: jal         0x800AFAB0
    // 0x800B0114: nop

    func_800AFAB0(rdram, ctx);
        goto after_5;
    // 0x800B0114: nop

    after_5:
    // 0x800B0118: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B011C: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B0120: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B0124: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0128: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B012C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800B0130: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B0134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B0138: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B013C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B0140: jal         0x800AFAB0
    // 0x800B0144: nop

    func_800AFAB0(rdram, ctx);
        goto after_6;
    // 0x800B0144: nop

    after_6:
    // 0x800B0148: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B014C: lwc1        $f10, 0x110($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0150: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B0154: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0158: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B015C: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x800B0160: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B0164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B0168: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B016C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B0170: jal         0x800AFAB0
    // 0x800B0174: nop

    func_800AFAB0(rdram, ctx);
        goto after_7;
    // 0x800B0174: nop

    after_7:
    // 0x800B0178: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B017C: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0180: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B0184: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0188: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B018C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800B0190: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B0194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B0198: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B019C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B01A0: jal         0x800AFAB0
    // 0x800B01A4: nop

    func_800AFAB0(rdram, ctx);
        goto after_8;
    // 0x800B01A4: nop

    after_8:
    // 0x800B01A8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B01AC: lwc1        $f4, 0x110($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B01B0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B01B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B01B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B01BC: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800B01C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B01C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B01C8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B01CC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B01D0: jal         0x800AFAB0
    // 0x800B01D4: nop

    func_800AFAB0(rdram, ctx);
        goto after_9;
    // 0x800B01D4: nop

    after_9:
    // 0x800B01D8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800B01DC: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B01E0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800B01E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B01E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B01EC: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x800B01F0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B01F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B01F8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B01FC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800B0200: jal         0x800AFAB0
    // 0x800B0204: nop

    func_800AFAB0(rdram, ctx);
        goto after_10;
    // 0x800B0204: nop

    after_10:
    // 0x800B0208: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B020C: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B0210: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B0214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B021C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800B0220: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B0224: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B0228: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B022C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B0230: jal         0x800AFAB0
    // 0x800B0234: nop

    func_800AFAB0(rdram, ctx);
        goto after_11;
    // 0x800B0234: nop

    after_11:
    // 0x800B0238: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B023C: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B0240: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B0244: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0248: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B024C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800B0250: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B0254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B0258: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B025C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B0260: jal         0x800AFAB0
    // 0x800B0264: nop

    func_800AFAB0(rdram, ctx);
        goto after_12;
    // 0x800B0264: nop

    after_12:
L_800B0268:
    // 0x800B0268: b           L_800B084C
    // 0x800B026C: nop

        goto L_800B084C;
    // 0x800B026C: nop

L_800B0270:
    // 0x800B0270: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x800B0274: nop

    // 0x800B0278: bne         $t2, $zero, L_800B02A0
    if (ctx->r10 != 0) {
        // 0x800B027C: nop
    
            goto L_800B02A0;
    }
    // 0x800B027C: nop

    // 0x800B0280: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x800B0284: lh          $a1, 0x16A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X16A);
    // 0x800B0288: lbu         $at, 0x1($t4)
    ctx->r1 = MEM_BU(ctx->r12, 0X1);
    // 0x800B028C: lbu         $a0, 0x2($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X2);
    // 0x800B0290: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800B0294: jal         0x800B0A3C
    // 0x800B0298: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_800B0A3C(rdram, ctx);
        goto after_13;
    // 0x800B0298: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_13:
    // 0x800B029C: sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
L_800B02A0:
    // 0x800B02A0: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x800B02A4: nop

    // 0x800B02A8: lbu         $at, 0x3($t5)
    ctx->r1 = MEM_BU(ctx->r13, 0X3);
    // 0x800B02AC: lbu         $t3, 0x4($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X4);
    // 0x800B02B0: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800B02B4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
    // 0x800B02B8: sh          $t3, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r11;
    // 0x800B02BC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800B02C0: nop

    // 0x800B02C4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800B02C8: nop

    // 0x800B02CC: sra         $t9, $t7, 4
    ctx->r25 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800B02D0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B02D4: sh          $t0, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r8;
    // 0x800B02D8: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x800B02DC: nop

    // 0x800B02E0: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x800B02E4: nop

    // 0x800B02E8: andi        $t2, $t8, 0xF
    ctx->r10 = ctx->r24 & 0XF;
    // 0x800B02EC: sh          $t2, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r10;
    // 0x800B02F0: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800B02F4: nop

    // 0x800B02F8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800B02FC: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x800B0300: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800B0304: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B0308: lh          $t9, 0x146($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X146);
    // 0x800B030C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x800B0310: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800B0314: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x800B0318: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800B031C: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x800B0320: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B0324: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800B0328: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800B032C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800B0330: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x800B0334: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800B0338: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800B033C: lh          $t9, 0x14A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X14A);
    // 0x800B0340: lw          $t1, 0xE8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE8);
    // 0x800B0344: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800B0348: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800B034C: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x800B0350: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x800B0354: lh          $t4, 0x148($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X148);
    // 0x800B0358: sw          $zero, 0x158($sp)
    MEM_W(0X158, ctx->r29) = 0;
    // 0x800B035C: blez        $t4, L_800B03A8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B0360: nop
    
            goto L_800B03A8;
    }
    // 0x800B0360: nop

L_800B0364:
    // 0x800B0364: lw          $t5, 0x158($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X158);
    // 0x800B0368: lh          $t2, 0x14A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X14A);
    // 0x800B036C: lh          $t1, 0x146($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X146);
    // 0x800B0370: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    // 0x800B0374: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800B0378: addu        $t8, $t1, $t5
    ctx->r24 = ADD32(ctx->r9, ctx->r13);
    // 0x800B037C: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x800B0380: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800B0384: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x800B0388: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B038C: sw          $t0, 0x9C($t4)
    MEM_W(0X9C, ctx->r12) = ctx->r8;
    // 0x800B0390: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800B0394: lh          $t7, 0x148($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X148);
    // 0x800B0398: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800B039C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B03A0: bne         $at, $zero, L_800B0364
    if (ctx->r1 != 0) {
        // 0x800B03A4: sw          $t6, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r14;
            goto L_800B0364;
    }
    // 0x800B03A4: sw          $t6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r14;
L_800B03A8:
    // 0x800B03A8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800B03AC: nop

    // 0x800B03B0: addiu       $t1, $t9, 0x5
    ctx->r9 = ADD32(ctx->r25, 0X5);
    // 0x800B03B4: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800B03B8: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x800B03BC: nop

    // 0x800B03C0: addiu       $t8, $t5, -0x5
    ctx->r24 = ADD32(ctx->r13, -0X5);
    // 0x800B03C4: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
    // 0x800B03C8: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x800B03CC: nop

    // 0x800B03D0: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800B03D4: sw          $t3, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r11;
    // 0x800B03D8: b           L_800B084C
    // 0x800B03DC: nop

        goto L_800B084C;
    // 0x800B03DC: nop

L_800B03E0:
    // 0x800B03E0: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x800B03E4: nop

    // 0x800B03E8: lbu         $at, 0x1($t4)
    ctx->r1 = MEM_BU(ctx->r12, 0X1);
    // 0x800B03EC: lbu         $t2, 0x2($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X2);
    // 0x800B03F0: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800B03F4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
    // 0x800B03F8: sh          $t2, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r10;
    // 0x800B03FC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800B0400: nop

    // 0x800B0404: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x800B0408: nop

    // 0x800B040C: sh          $t7, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r15;
    // 0x800B0410: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800B0414: nop

    // 0x800B0418: lbu         $t1, 0x4($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X4);
    // 0x800B041C: nop

    // 0x800B0420: sh          $t1, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r9;
    // 0x800B0424: lh          $t5, 0x148($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X148);
    // 0x800B0428: nop

    // 0x800B042C: andi        $t8, $t5, 0x80
    ctx->r24 = ctx->r13 & 0X80;
    // 0x800B0430: beq         $t8, $zero, L_800B0444
    if (ctx->r24 == 0) {
        // 0x800B0434: nop
    
            goto L_800B0444;
    }
    // 0x800B0434: nop

    // 0x800B0438: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800B043C: b           L_800B0448
    // 0x800B0440: sw          $t0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r8;
        goto L_800B0448;
    // 0x800B0440: sw          $t0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r8;
L_800B0444:
    // 0x800B0444: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
L_800B0448:
    // 0x800B0448: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B044C: nop

    // 0x800B0450: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x800B0454: sh          $t4, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r12;
    // 0x800B0458: lh          $t2, 0x146($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X146);
    // 0x800B045C: nop

    // 0x800B0460: andi        $t6, $t2, 0x80
    ctx->r14 = ctx->r10 & 0X80;
    // 0x800B0464: beq         $t6, $zero, L_800B0478
    if (ctx->r14 == 0) {
        // 0x800B0468: nop
    
            goto L_800B0478;
    }
    // 0x800B0468: nop

    // 0x800B046C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800B0470: b           L_800B047C
    // 0x800B0474: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
        goto L_800B047C;
    // 0x800B0474: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
L_800B0478:
    // 0x800B0478: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800B047C:
    // 0x800B047C: lh          $t9, 0x146($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X146);
    // 0x800B0480: nop

    // 0x800B0484: andi        $t1, $t9, 0x7F
    ctx->r9 = ctx->r25 & 0X7F;
    // 0x800B0488: sh          $t1, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r9;
    // 0x800B048C: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x800B0490: sh          $zero, 0x140($sp)
    MEM_H(0X140, ctx->r29) = 0;
    // 0x800B0494: lh          $t5, 0x148($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X148);
    // 0x800B0498: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B049C: beq         $t5, $at, L_800B04C8
    if (ctx->r13 == ctx->r1) {
        // 0x800B04A0: sw          $t5, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r13;
            goto L_800B04C8;
    }
    // 0x800B04A0: sw          $t5, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r13;
L_800B04A4:
    // 0x800B04A4: lhu         $t8, 0x140($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X140);
    // 0x800B04A8: nop

    // 0x800B04AC: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800B04B0: sh          $t0, 0x140($sp)
    MEM_H(0X140, ctx->r29) = ctx->r8;
    // 0x800B04B4: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x800B04B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B04BC: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800B04C0: bne         $t4, $at, L_800B04A4
    if (ctx->r12 != ctx->r1) {
        // 0x800B04C4: sw          $t4, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r12;
            goto L_800B04A4;
    }
    // 0x800B04C4: sw          $t4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r12;
L_800B04C8:
    // 0x800B04C8: lh          $t2, 0x146($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X146);
    // 0x800B04CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B04D0: beq         $t2, $at, L_800B04FC
    if (ctx->r10 == ctx->r1) {
        // 0x800B04D4: sw          $t2, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r10;
            goto L_800B04FC;
    }
    // 0x800B04D4: sw          $t2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r10;
L_800B04D8:
    // 0x800B04D8: lhu         $t6, 0x13E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X13E);
    // 0x800B04DC: nop

    // 0x800B04E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B04E4: sh          $t7, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r15;
    // 0x800B04E8: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800B04EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B04F0: sra         $t1, $t9, 1
    ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800B04F4: bne         $t1, $at, L_800B04D8
    if (ctx->r9 != ctx->r1) {
        // 0x800B04F8: sw          $t1, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r9;
            goto L_800B04D8;
    }
    // 0x800B04F8: sw          $t1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r9;
L_800B04FC:
    // 0x800B04FC: lh          $a0, 0x14A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X14A);
    // 0x800B0500: lh          $a1, 0x16A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X16A);
    // 0x800B0504: jal         0x800B08FC
    // 0x800B0508: nop

    func_800B08FC(rdram, ctx);
        goto after_14;
    // 0x800B0508: nop

    after_14:
    // 0x800B050C: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    // 0x800B0510: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x800B0514: nop

    // 0x800B0518: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x800B051C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x800B0520: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x800B0524: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x800B0528: lui         $t0, 0xFD10
    ctx->r8 = S32(0XFD10 << 16);
    // 0x800B052C: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800B0530: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    // 0x800B0534: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800B0538: nop

    // 0x800B053C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x800B0540: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800B0544: nop

    // 0x800B0548: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800B054C: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B0550: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x800B0554: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800B0558: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x800B055C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800B0560: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800B0564: lhu         $t4, 0x13E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X13E);
    // 0x800B0568: andi        $t8, $t5, 0x3
    ctx->r24 = ctx->r13 & 0X3;
    // 0x800B056C: sll         $t0, $t8, 18
    ctx->r8 = S32(ctx->r24 << 18);
    // 0x800B0570: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0574: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800B0578: or          $t3, $t0, $at
    ctx->r11 = ctx->r8 | ctx->r1;
    // 0x800B057C: andi        $t2, $t4, 0xF
    ctx->r10 = ctx->r12 & 0XF;
    // 0x800B0580: lhu         $t0, 0x140($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X140);
    // 0x800B0584: sll         $t6, $t2, 14
    ctx->r14 = S32(ctx->r10 << 14);
    // 0x800B0588: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800B058C: andi        $t1, $t9, 0x3
    ctx->r9 = ctx->r25 & 0X3;
    // 0x800B0590: sll         $t5, $t1, 8
    ctx->r13 = S32(ctx->r9 << 8);
    // 0x800B0594: andi        $t4, $t0, 0xF
    ctx->r12 = ctx->r8 & 0XF;
    // 0x800B0598: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800B059C: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x800B05A0: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x800B05A4: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800B05A8: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800B05AC: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800B05B0: nop

    // 0x800B05B4: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x800B05B8: sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
    // 0x800B05BC: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x800B05C0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800B05C4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B05C8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800B05CC: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800B05D0: nop

    // 0x800B05D4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800B05D8: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800B05DC: nop

    // 0x800B05E0: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800B05E4: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x800B05E8: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x800B05EC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800B05F0: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x800B05F4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800B05F8: lh          $t6, 0x148($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X148);
    // 0x800B05FC: lh          $t9, 0x146($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X146);
    // 0x800B0600: nop

    // 0x800B0604: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0608: mflo        $t1
    ctx->r9 = lo;
    // 0x800B060C: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x800B0610: slti        $at, $t7, 0x7FF
    ctx->r1 = SIGNED(ctx->r15) < 0X7FF ? 1 : 0;
    // 0x800B0614: beq         $at, $zero, L_800B0624
    if (ctx->r1 == 0) {
        // 0x800B0618: nop
    
            goto L_800B0624;
    }
    // 0x800B0618: nop

    // 0x800B061C: b           L_800B0628
    // 0x800B0620: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
        goto L_800B0628;
    // 0x800B0620: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800B0624:
    // 0x800B0624: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800B0628:
    // 0x800B0628: lh          $t5, 0x148($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X148);
    // 0x800B062C: nop

    // 0x800B0630: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x800B0634: bgez        $t0, L_800B0644
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B0638: sra         $t4, $t0, 3
        ctx->r12 = S32(SIGNED(ctx->r8) >> 3);
            goto L_800B0644;
    }
    // 0x800B0638: sra         $t4, $t0, 3
    ctx->r12 = S32(SIGNED(ctx->r8) >> 3);
    // 0x800B063C: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x800B0640: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800B0644:
    // 0x800B0644: bgtz        $t4, L_800B0654
    if (SIGNED(ctx->r12) > 0) {
        // 0x800B0648: nop
    
            goto L_800B0654;
    }
    // 0x800B0648: nop

    // 0x800B064C: b           L_800B0678
    // 0x800B0650: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800B0678;
    // 0x800B0650: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800B0654:
    // 0x800B0654: lh          $s1, 0x148($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X148);
    // 0x800B0658: nop

    // 0x800B065C: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x800B0660: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800B0664: bgez        $s1, L_800B0674
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800B0668: sra         $t2, $s1, 3
        ctx->r10 = S32(SIGNED(ctx->r17) >> 3);
            goto L_800B0674;
    }
    // 0x800B0668: sra         $t2, $s1, 3
    ctx->r10 = S32(SIGNED(ctx->r17) >> 3);
    // 0x800B066C: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x800B0670: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_800B0674:
    // 0x800B0674: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
L_800B0678:
    // 0x800B0678: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B067C: nop

    // 0x800B0680: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800B0684: bgez        $t6, L_800B0694
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B0688: sra         $t9, $t6, 3
        ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
            goto L_800B0694;
    }
    // 0x800B0688: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B068C: addiu       $at, $t6, 0x7
    ctx->r1 = ADD32(ctx->r14, 0X7);
    // 0x800B0690: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800B0694:
    // 0x800B0694: bgtz        $t9, L_800B06A4
    if (SIGNED(ctx->r25) > 0) {
        // 0x800B0698: nop
    
            goto L_800B06A4;
    }
    // 0x800B0698: nop

    // 0x800B069C: b           L_800B06C8
    // 0x800B06A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800B06C8;
    // 0x800B06A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800B06A4:
    // 0x800B06A4: lh          $s0, 0x148($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X148);
    // 0x800B06A8: nop

    // 0x800B06AC: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x800B06B0: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x800B06B4: bgez        $s0, L_800B06C4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800B06B8: sra         $t7, $s0, 3
        ctx->r15 = S32(SIGNED(ctx->r16) >> 3);
            goto L_800B06C4;
    }
    // 0x800B06B8: sra         $t7, $s0, 3
    ctx->r15 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800B06BC: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x800B06C0: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800B06C4:
    // 0x800B06C4: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_800B06C8:
    // 0x800B06C8: addiu       $t5, $s1, 0x7FF
    ctx->r13 = ADD32(ctx->r17, 0X7FF);
    // 0x800B06CC: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800B06D0: andi        $t8, $s2, 0xFFF
    ctx->r24 = ctx->r18 & 0XFFF;
    // 0x800B06D4: bne         $s0, $zero, L_800B06E0
    if (ctx->r16 != 0) {
        // 0x800B06D8: nop
    
            goto L_800B06E0;
    }
    // 0x800B06D8: nop

    // 0x800B06DC: break       7
    do_break(2148206300);
L_800B06E0:
    // 0x800B06E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B06E4: bne         $s0, $at, L_800B06F8
    if (ctx->r16 != ctx->r1) {
        // 0x800B06E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B06F8;
    }
    // 0x800B06E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B06EC: bne         $t5, $at, L_800B06F8
    if (ctx->r13 != ctx->r1) {
        // 0x800B06F0: nop
    
            goto L_800B06F8;
    }
    // 0x800B06F0: nop

    // 0x800B06F4: break       6
    do_break(2148206324);
L_800B06F8:
    // 0x800B06F8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B06FC: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x800B0700: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800B0704: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800B0708: mflo        $t0
    ctx->r8 = lo;
    // 0x800B070C: andi        $t4, $t0, 0xFFF
    ctx->r12 = ctx->r8 & 0XFFF;
    // 0x800B0710: or          $t6, $t4, $t3
    ctx->r14 = ctx->r12 | ctx->r11;
    // 0x800B0714: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800B0718: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800B071C: nop

    // 0x800B0720: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800B0724: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B0728: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x800B072C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800B0730: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800B0734: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800B0738: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800B073C: nop

    // 0x800B0740: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800B0744: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800B0748: nop

    // 0x800B074C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800B0750: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x800B0754: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x800B0758: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B075C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800B0760: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800B0764: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x800B0768: sra         $t1, $t9, 3
    ctx->r9 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B076C: andi        $t7, $t1, 0x1FF
    ctx->r15 = ctx->r9 & 0X1FF;
    // 0x800B0770: sll         $t5, $t7, 9
    ctx->r13 = S32(ctx->r15 << 9);
    // 0x800B0774: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800B0778: or          $t0, $t5, $at
    ctx->r8 = ctx->r13 | ctx->r1;
    // 0x800B077C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800B0780: lw          $t2, 0x14C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14C);
    // 0x800B0784: lhu         $t6, 0x13E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X13E);
    // 0x800B0788: andi        $t4, $t2, 0x3
    ctx->r12 = ctx->r10 & 0X3;
    // 0x800B078C: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800B0790: sll         $t3, $t4, 18
    ctx->r11 = S32(ctx->r12 << 18);
    // 0x800B0794: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x800B0798: lhu         $t4, 0x140($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X140);
    // 0x800B079C: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x800B07A0: or          $t7, $t3, $t1
    ctx->r15 = ctx->r11 | ctx->r9;
    // 0x800B07A4: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800B07A8: sll         $t8, $t0, 8
    ctx->r24 = S32(ctx->r8 << 8);
    // 0x800B07AC: andi        $t6, $t4, 0xF
    ctx->r14 = ctx->r12 & 0XF;
    // 0x800B07B0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800B07B4: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x800B07B8: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x800B07BC: or          $t3, $t2, $t9
    ctx->r11 = ctx->r10 | ctx->r25;
    // 0x800B07C0: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800B07C4: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x800B07C8: nop

    // 0x800B07CC: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800B07D0: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x800B07D4: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x800B07D8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800B07DC: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800B07E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800B07E4: lh          $t4, 0x148($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X148);
    // 0x800B07E8: lh          $t1, 0x146($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X146);
    // 0x800B07EC: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x800B07F0: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800B07F4: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x800B07F8: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x800B07FC: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x800B0800: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800B0804: sll         $t3, $t9, 12
    ctx->r11 = S32(ctx->r25 << 12);
    // 0x800B0808: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x800B080C: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800B0810: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x800B0814: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800B0818: nop

    // 0x800B081C: addiu       $t2, $t6, 0x5
    ctx->r10 = ADD32(ctx->r14, 0X5);
    // 0x800B0820: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800B0824: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x800B0828: nop

    // 0x800B082C: addiu       $t1, $t9, -0x5
    ctx->r9 = ADD32(ctx->r25, -0X5);
    // 0x800B0830: sw          $t1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r9;
    // 0x800B0834: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x800B0838: nop

    // 0x800B083C: addiu       $t0, $t5, 0x7
    ctx->r8 = ADD32(ctx->r13, 0X7);
    // 0x800B0840: sw          $t0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r8;
    // 0x800B0844: b           L_800B084C
    // 0x800B0848: nop

        goto L_800B084C;
    // 0x800B0848: nop

L_800B084C:
    // 0x800B084C: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x800B0850: nop

    // 0x800B0854: bgtz        $t3, L_800AFCB8
    if (SIGNED(ctx->r11) > 0) {
        // 0x800B0858: nop
    
            goto L_800AFCB8;
    }
    // 0x800B0858: nop

L_800B085C:
    // 0x800B085C: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800B0860: nop

    // 0x800B0864: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800B0868: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x800B086C: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800B0870: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800B0874: lui         $t4, 0xB800
    ctx->r12 = S32(0XB800 << 16);
    // 0x800B0878: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800B087C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800B0880: nop

    // 0x800B0884: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800B0888: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x800B088C: nop

    // 0x800B0890: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800B0894: sw          $t1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r9;
    // 0x800B0898: jal         0x800BC6EC
    // 0x800B089C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_15;
    // 0x800B089C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_15:
    // 0x800B08A0: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x800B08A4: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800B08A8: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800B08AC: lw          $a2, 0x158($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X158);
    // 0x800B08B0: jal         0x800BD218
    // 0x800B08B4: nop

    SysMem_DmaCopy(rdram, ctx);
        goto after_16;
    // 0x800B08B4: nop

    after_16:
    // 0x800B08B8: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x800B08BC: b           L_800B08CC
    // 0x800B08C0: nop

        goto L_800B08CC;
    // 0x800B08C0: nop

    // 0x800B08C4: b           L_800B08CC
    // 0x800B08C8: nop

        goto L_800B08CC;
    // 0x800B08C8: nop

L_800B08CC:
    // 0x800B08CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B08D0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B08D4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B08D8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B08DC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B08E0: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800B08E4: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B08E8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800B08EC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800B08F0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800B08F4: jr          $ra
    // 0x800B08F8: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x800B08F8: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void MtxUtil_InitStack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C15C0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C15C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C15C8: addiu       $t6, $t6, 0x6D0
    ctx->r14 = ADD32(ctx->r14, 0X6D0);
    // 0x800C15CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C15D0: sw          $t6, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r14;
    // 0x800C15D4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800C15D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C15DC: sw          $t7, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r15;
    // 0x800C15E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C15E4: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C15E8: nop

    // 0x800C15EC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800C15F0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800C15F4: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
L_800C15F8:
    // 0x800C15F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C15FC: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C1600: nop

    // 0x800C1604: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x800C1608: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C160C: nop

    // 0x800C1610: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800C1614: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800C1618: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C161C: nop

    // 0x800C1620: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800C1624: bgtz        $t4, L_800C15F8
    if (SIGNED(ctx->r12) > 0) {
        // 0x800C1628: sw          $t4, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r12;
            goto L_800C15F8;
    }
    // 0x800C1628: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800C162C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C1630: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800C1634: lw          $t5, 0xCE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE4);
    // 0x800C1638: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C163C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1640: swc1        $f6, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f6.u32l;
    // 0x800C1644: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1648: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C164C: lwc1        $f14, 0x3C($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x800C1650: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C1654: swc1        $f14, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f14.u32l;
    // 0x800C1658: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C165C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C1660: swc1        $f12, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f12.u32l;
    // 0x800C1664: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C1668: nop

    // 0x800C166C: swc1        $f12, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f12.u32l;
    // 0x800C1670: b           L_800C1678
    // 0x800C1674: nop

        goto L_800C1678;
    // 0x800C1674: nop

L_800C1678:
    // 0x800C1678: jr          $ra
    // 0x800C167C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C167C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008997C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008997C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80089980: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80089984: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80089988: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008998C: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80089990: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089994: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80089998: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008999C: lh          $t9, 0x4666($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4666);
    // 0x800899A0: nop

    // 0x800899A4: bne         $t9, $at, L_80089AD4
    if (ctx->r25 != ctx->r1) {
        // 0x800899A8: nop
    
            goto L_80089AD4;
    }
    // 0x800899A8: nop

    // 0x800899AC: addiu       $t0, $zero, 0x7B
    ctx->r8 = ADD32(0, 0X7B);
    // 0x800899B0: sh          $t0, 0x748($a0)
    MEM_H(0X748, ctx->r4) = ctx->r8;
    // 0x800899B4: addiu       $t1, $zero, 0x5E
    ctx->r9 = ADD32(0, 0X5E);
    // 0x800899B8: sh          $t1, 0x74A($a0)
    MEM_H(0X74A, ctx->r4) = ctx->r9;
    // 0x800899BC: addiu       $t2, $zero, -0x8C
    ctx->r10 = ADD32(0, -0X8C);
    // 0x800899C0: sh          $t2, 0x74C($a0)
    MEM_H(0X74C, ctx->r4) = ctx->r10;
    // 0x800899C4: addiu       $t3, $zero, -0x35
    ctx->r11 = ADD32(0, -0X35);
    // 0x800899C8: sh          $t3, 0x74E($a0)
    MEM_H(0X74E, ctx->r4) = ctx->r11;
    // 0x800899CC: addiu       $t4, $a0, 0x750
    ctx->r12 = ADD32(ctx->r4, 0X750);
    // 0x800899D0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800899D4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800899D8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800899DC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800899E0: nop

    // 0x800899E4: beq         $t6, $at, L_80089ACC
    if (ctx->r14 == ctx->r1) {
        // 0x800899E8: nop
    
            goto L_80089ACC;
    }
    // 0x800899E8: nop

L_800899EC:
    // 0x800899EC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800899F0: lh          $t9, 0x748($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X748);
    // 0x800899F4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800899F8: nop

    // 0x800899FC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80089A00: beq         $at, $zero, L_80089A1C
    if (ctx->r1 == 0) {
        // 0x80089A04: nop
    
            goto L_80089A1C;
    }
    // 0x80089A04: nop

    // 0x80089A08: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80089A0C: nop

    // 0x80089A10: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80089A14: nop

    // 0x80089A18: sh          $t1, 0x748($a0)
    MEM_H(0X748, ctx->r4) = ctx->r9;
L_80089A1C:
    // 0x80089A1C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80089A20: lh          $t4, 0x74A($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X74A);
    // 0x80089A24: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x80089A28: nop

    // 0x80089A2C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80089A30: beq         $at, $zero, L_80089A4C
    if (ctx->r1 == 0) {
        // 0x80089A34: nop
    
            goto L_80089A4C;
    }
    // 0x80089A34: nop

    // 0x80089A38: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80089A3C: nop

    // 0x80089A40: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80089A44: nop

    // 0x80089A48: sh          $t6, 0x74A($a0)
    MEM_H(0X74A, ctx->r4) = ctx->r14;
L_80089A4C:
    // 0x80089A4C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80089A50: lh          $t9, 0x74C($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X74C);
    // 0x80089A54: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80089A58: nop

    // 0x80089A5C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80089A60: beq         $at, $zero, L_80089A7C
    if (ctx->r1 == 0) {
        // 0x80089A64: nop
    
            goto L_80089A7C;
    }
    // 0x80089A64: nop

    // 0x80089A68: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80089A6C: nop

    // 0x80089A70: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x80089A74: nop

    // 0x80089A78: sh          $t1, 0x74C($a0)
    MEM_H(0X74C, ctx->r4) = ctx->r9;
L_80089A7C:
    // 0x80089A7C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80089A80: lh          $t4, 0x74E($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X74E);
    // 0x80089A84: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x80089A88: nop

    // 0x80089A8C: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80089A90: beq         $at, $zero, L_80089AAC
    if (ctx->r1 == 0) {
        // 0x80089A94: nop
    
            goto L_80089AAC;
    }
    // 0x80089A94: nop

    // 0x80089A98: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80089A9C: nop

    // 0x80089AA0: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x80089AA4: nop

    // 0x80089AA8: sh          $t6, 0x74E($a0)
    MEM_H(0X74E, ctx->r4) = ctx->r14;
L_80089AAC:
    // 0x80089AAC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80089AB0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80089AB4: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80089AB8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80089ABC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80089AC0: nop

    // 0x80089AC4: bne         $t9, $at, L_800899EC
    if (ctx->r25 != ctx->r1) {
        // 0x80089AC8: nop
    
            goto L_800899EC;
    }
    // 0x80089AC8: nop

L_80089ACC:
    // 0x80089ACC: b           L_80089AFC
    // 0x80089AD0: nop

        goto L_80089AFC;
    // 0x80089AD0: nop

L_80089AD4:
    // 0x80089AD4: addiu       $t0, $zero, -0x8C
    ctx->r8 = ADD32(0, -0X8C);
    // 0x80089AD8: sh          $t0, 0x748($a0)
    MEM_H(0X748, ctx->r4) = ctx->r8;
    // 0x80089ADC: addiu       $t1, $zero, -0x35
    ctx->r9 = ADD32(0, -0X35);
    // 0x80089AE0: sh          $t1, 0x74A($a0)
    MEM_H(0X74A, ctx->r4) = ctx->r9;
    // 0x80089AE4: addiu       $t2, $zero, 0x7B
    ctx->r10 = ADD32(0, 0X7B);
    // 0x80089AE8: sh          $t2, 0x74C($a0)
    MEM_H(0X74C, ctx->r4) = ctx->r10;
    // 0x80089AEC: addiu       $t3, $zero, 0x5E
    ctx->r11 = ADD32(0, 0X5E);
    // 0x80089AF0: sh          $t3, 0x74E($a0)
    MEM_H(0X74E, ctx->r4) = ctx->r11;
    // 0x80089AF4: b           L_80089AFC
    // 0x80089AF8: nop

        goto L_80089AFC;
    // 0x80089AF8: nop

L_80089AFC:
    // 0x80089AFC: jr          $ra
    // 0x80089B00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80089B00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80081260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081260: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80081264: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081268: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008126C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80081270: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081274: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80081278: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008127C: nop

    // 0x80081280: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80081284: nop

    // 0x80081288: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x8008128C: nop

    // 0x80081290: blez        $t9, L_80081380
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80081294: nop
    
            goto L_80081380;
    }
    // 0x80081294: nop

    // 0x80081298: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008129C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800812A0: lhu         $t1, 0xA($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XA);
    // 0x800812A4: nop

    // 0x800812A8: andi        $t2, $t1, 0xE
    ctx->r10 = ctx->r9 & 0XE;
    // 0x800812AC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800812B0: beq         $t3, $at, L_80081380
    if (ctx->r11 == ctx->r1) {
        // 0x800812B4: nop
    
            goto L_80081380;
    }
    // 0x800812B4: nop

    // 0x800812B8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800812BC: nop

    // 0x800812C0: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800812C4: nop

    // 0x800812C8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800812CC: jal         0x800B2748
    // 0x800812D0: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x800812D0: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    after_0:
    // 0x800812D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800812D8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800812DC: nop

    // 0x800812E0: blez        $t6, L_80081380
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800812E4: nop
    
            goto L_80081380;
    }
    // 0x800812E4: nop

    // 0x800812E8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800812EC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800812F0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800812F4: nop

    // 0x800812F8: sh          $t7, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r15;
    // 0x800812FC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80081300: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80081304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081308: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x8008130C: jal         0x800B3434
    // 0x80081310: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B3434(rdram, ctx);
        goto after_1;
    // 0x80081310: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80081314: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80081318: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x8008131C: nop

    // 0x80081320: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x80081324: beq         $t2, $zero, L_8008134C
    if (ctx->r10 == 0) {
        // 0x80081328: nop
    
            goto L_8008134C;
    }
    // 0x80081328: nop

    // 0x8008132C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80081330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081334: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x80081338: jal         0x800B32E4
    // 0x8008133C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_2;
    // 0x8008133C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80081340: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80081344: jal         0x800B9000
    // 0x80081348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x80081348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8008134C:
    // 0x8008134C: lhu         $t4, 0x36($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X36);
    // 0x80081350: nop

    // 0x80081354: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80081358: beq         $t5, $zero, L_80081380
    if (ctx->r13 == 0) {
        // 0x8008135C: nop
    
            goto L_80081380;
    }
    // 0x8008135C: nop

    // 0x80081360: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80081364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80081368: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8008136C: jal         0x800B32E4
    // 0x80081370: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_4;
    // 0x80081370: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80081374: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80081378: jal         0x800B9000
    // 0x8008137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x8008137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80081380:
    // 0x80081380: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80081384: nop

    // 0x80081388: bne         $t8, $zero, L_80081398
    if (ctx->r24 != 0) {
        // 0x8008138C: nop
    
            goto L_80081398;
    }
    // 0x8008138C: nop

    // 0x80081390: b           L_80081544
    // 0x80081394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081544;
    // 0x80081394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081398:
    // 0x80081398: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008139C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800813A0: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x800813A4: lhu         $t2, 0xE($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0XE);
    // 0x800813A8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800813AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800813B0: lh          $t1, 0x2830($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2830);
    // 0x800813B4: nop

    // 0x800813B8: bne         $t1, $t2, L_800814FC
    if (ctx->r9 != ctx->r10) {
        // 0x800813BC: nop
    
            goto L_800814FC;
    }
    // 0x800813BC: nop

    // 0x800813C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800813C4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800813C8: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x800813CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800813D0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800813D4: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x800813D8: lh          $a3, 0x2832($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X2832);
    // 0x800813DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800813E0: or          $t6, $a3, $at
    ctx->r14 = ctx->r7 | ctx->r1;
    // 0x800813E4: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800813E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800813EC: jal         0x800B3230
    // 0x800813F0: addiu       $a0, $t3, 0xA
    ctx->r4 = ADD32(ctx->r11, 0XA);
    func_800B3230(rdram, ctx);
        goto after_6;
    // 0x800813F0: addiu       $a0, $t3, 0xA
    ctx->r4 = ADD32(ctx->r11, 0XA);
    after_6:
    // 0x800813F4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800813F8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800813FC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80081400: lhu         $t0, 0x8($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X8);
    // 0x80081404: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80081408: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8008140C: lwc1        $f4, 0xCC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x80081410: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80081414: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80081418: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8008141C: lh          $a3, 0x42($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X42);
    // 0x80081420: lh          $a2, 0x2832($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X2832);
    // 0x80081424: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80081428: lwc1        $f6, 0xD0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8008142C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80081430: or          $t1, $a2, $at
    ctx->r9 = ctx->r6 | ctx->r1;
    // 0x80081434: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80081438: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008143C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80081440: addiu       $a1, $t9, 0x4
    ctx->r5 = ADD32(ctx->r25, 0X4);
    // 0x80081444: jal         0x800B202C
    // 0x80081448: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_7;
    // 0x80081448: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8008144C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80081450: nop

    // 0x80081454: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80081458: nop

    // 0x8008145C: sh          $v0, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r2;
    // 0x80081460: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80081464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081468: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8008146C: jal         0x800B3434
    // 0x80081470: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B3434(rdram, ctx);
        goto after_8;
    // 0x80081470: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_8:
    // 0x80081474: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80081478: lhu         $t8, 0x36($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X36);
    // 0x8008147C: nop

    // 0x80081480: andi        $t0, $t8, 0x4000
    ctx->r8 = ctx->r24 & 0X4000;
    // 0x80081484: beq         $t0, $zero, L_800814AC
    if (ctx->r8 == 0) {
        // 0x80081488: nop
    
            goto L_800814AC;
    }
    // 0x80081488: nop

    // 0x8008148C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80081490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081494: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80081498: jal         0x800B32E4
    // 0x8008149C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_9;
    // 0x8008149C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_9:
    // 0x800814A0: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800814A4: jal         0x800B9000
    // 0x800814A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_10;
    // 0x800814A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_800814AC:
    // 0x800814AC: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x800814B0: nop

    // 0x800814B4: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800814B8: beq         $t2, $zero, L_800814E0
    if (ctx->r10 == 0) {
        // 0x800814BC: nop
    
            goto L_800814E0;
    }
    // 0x800814BC: nop

    // 0x800814C0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800814C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800814C8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800814CC: jal         0x800B32E4
    // 0x800814D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B32E4(rdram, ctx);
        goto after_11;
    // 0x800814D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_11:
    // 0x800814D4: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800814D8: jal         0x800B9000
    // 0x800814DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_12;
    // 0x800814DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_800814E0:
    // 0x800814E0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800814E4: nop

    // 0x800814E8: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x800814EC: nop

    // 0x800814F0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800814F4: b           L_80081534
    // 0x800814F8: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
        goto L_80081534;
    // 0x800814F8: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
L_800814FC:
    // 0x800814FC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80081500: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081504: lhu         $t8, 0x8($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X8);
    // 0x80081508: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008150C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80081510: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80081514: lh          $t7, 0x2830($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2830);
    // 0x80081518: nop

    // 0x8008151C: bne         $t7, $at, L_8008152C
    if (ctx->r15 != ctx->r1) {
        // 0x80081520: nop
    
            goto L_8008152C;
    }
    // 0x80081520: nop

    // 0x80081524: b           L_80081544
    // 0x80081528: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80081544;
    // 0x80081528: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_8008152C:
    // 0x8008152C: b           L_80081544
    // 0x80081530: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081544;
    // 0x80081530: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80081534:
    // 0x80081534: b           L_80081544
    // 0x80081538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081544;
    // 0x80081538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008153C: b           L_80081544
    // 0x80081540: nop

        goto L_80081544;
    // 0x80081540: nop

L_80081544:
    // 0x80081544: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80081548: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008154C: jr          $ra
    // 0x80081550: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80081550: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800293EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800293EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800293F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800293F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800293F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800293FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80029400: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80029404: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x80029408: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8002940C: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80029410: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80029414: nop

    // 0x80029418: bne         $t7, $t8, L_800294B0
    if (ctx->r15 != ctx->r24) {
        // 0x8002941C: nop
    
            goto L_800294B0;
    }
    // 0x8002941C: nop

    // 0x80029420: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80029424: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x80029428: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x8002942C: nop

    // 0x80029430: bne         $t9, $t0, L_800294B0
    if (ctx->r25 != ctx->r8) {
        // 0x80029434: nop
    
            goto L_800294B0;
    }
    // 0x80029434: nop

    // 0x80029438: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002943C: lh          $t1, 0x1B48($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B48);
    // 0x80029440: nop

    // 0x80029444: bne         $t1, $zero, L_80029458
    if (ctx->r9 != 0) {
        // 0x80029448: nop
    
            goto L_80029458;
    }
    // 0x80029448: nop

    // 0x8002944C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80029450: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029454: sw          $t2, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r10;
L_80029458:
    // 0x80029458: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002945C: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80029460: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029464: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80029468: sh          $t4, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = ctx->r12;
    // 0x8002946C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80029470: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029474: swc1        $f4, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f4.u32l;
    // 0x80029478: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002947C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029480: swc1        $f6, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f6.u32l;
    // 0x80029484: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80029488: nop

    // 0x8002948C: lh          $a0, 0x0($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X0);
    // 0x80029490: jal         0x8002BB9C
    // 0x80029494: nop

    func_8002BB9C(rdram, ctx);
        goto after_0;
    // 0x80029494: nop

    after_0:
    // 0x80029498: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002949C: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x800294A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800294A4: jal         0x800296FC
    // 0x800294A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800296FC(rdram, ctx);
        goto after_1;
    // 0x800294A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800294AC: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_800294B0:
    // 0x800294B0: lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1E);
    // 0x800294B4: b           L_800294C4
    // 0x800294B8: nop

        goto L_800294C4;
    // 0x800294B8: nop

    // 0x800294BC: b           L_800294C4
    // 0x800294C0: nop

        goto L_800294C4;
    // 0x800294C0: nop

L_800294C4:
    // 0x800294C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800294C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800294CC: jr          $ra
    // 0x800294D0: nop

    return;
    // 0x800294D0: nop

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
RECOMP_FUNC void func_800BB4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB4B4: beq         $a0, $zero, L_800BB4CC
    if (ctx->r4 == 0) {
        // 0x800BB4B8: nop
    
            goto L_800BB4CC;
    }
    // 0x800BB4B8: nop

    // 0x800BB4BC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BB4C0: ori         $t7, $a1, 0x2
    ctx->r15 = ctx->r5 | 0X2;
    // 0x800BB4C4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800BB4C8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
L_800BB4CC:
    // 0x800BB4CC: jr          $ra
    // 0x800BB4D0: nop

    return;
    // 0x800BB4D0: nop

    // 0x800BB4D4: jr          $ra
    // 0x800BB4D8: nop

    return;
    // 0x800BB4D8: nop

;}
RECOMP_FUNC void func_80081554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081554: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80081558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008155C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80081560: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80081564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80081568: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008156C: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80081570: nop

    // 0x80081574: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081578: swc1        $f8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f8.u32l;
    // 0x8008157C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80081580: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081584: lwc1        $f16, -0xB14($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XB14);
    // 0x80081588: lwc1        $f10, 0x10($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8008158C: nop

    // 0x80081590: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80081594: nop

    // 0x80081598: bc1f        L_800815B8
    if (!c1cs) {
        // 0x8008159C: nop
    
            goto L_800815B8;
    }
    // 0x8008159C: nop

    // 0x800815A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800815A4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800815A8: nop

    // 0x800815AC: swc1        $f18, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f18.u32l;
    // 0x800815B0: b           L_80081A50
    // 0x800815B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081A50;
    // 0x800815B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800815B8:
    // 0x800815B8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800815BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800815C0: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800815C4: nop

    // 0x800815C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800815CC: nop

    // 0x800815D0: bc1f        L_800816A0
    if (!c1cs) {
        // 0x800815D4: nop
    
            goto L_800816A0;
    }
    // 0x800815D4: nop

    // 0x800815D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800815DC: nop

    // 0x800815E0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800815E4: nop

    // 0x800815E8: bc1f        L_800816A0
    if (!c1cs) {
        // 0x800815EC: nop
    
            goto L_800816A0;
    }
    // 0x800815EC: nop

    // 0x800815F0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800815F4: nop

    // 0x800815F8: lhu         $t1, 0x14($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X14);
    // 0x800815FC: nop

    // 0x80081600: bne         $t1, $zero, L_80081618
    if (ctx->r9 != 0) {
        // 0x80081604: nop
    
            goto L_80081618;
    }
    // 0x80081604: nop

    // 0x80081608: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008160C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80081610: b           L_80081628
    // 0x80081614: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
        goto L_80081628;
    // 0x80081614: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
L_80081618:
    // 0x80081618: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8008161C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081620: nop

    // 0x80081624: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
L_80081628:
    // 0x80081628: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008162C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80081630: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80081634: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80081638: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008163C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80081640: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80081644: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081648: lwc1        $f11, -0xB10($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XB10);
    // 0x8008164C: lwc1        $f10, -0xB0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XB0C);
    // 0x80081650: nop

    // 0x80081654: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80081658: jal         0x800C3070
    // 0x8008165C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_0;
    // 0x8008165C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_0:
    // 0x80081660: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80081664: nop

    // 0x80081668: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8008166C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80081670: nop

    // 0x80081674: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80081678: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008167C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80081680: nop

    // 0x80081684: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80081688: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8008168C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80081690: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80081694: nop

    // 0x80081698: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008169C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_800816A0:
    // 0x800816A0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800816A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800816A8: lwc1        $f16, 0x10($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800816AC: nop

    // 0x800816B0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800816B4: nop

    // 0x800816B8: bc1f        L_800817C4
    if (!c1cs) {
        // 0x800816BC: nop
    
            goto L_800817C4;
    }
    // 0x800816BC: nop

    // 0x800816C0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800816C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800816C8: nop

    // 0x800816CC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800816D0: nop

    // 0x800816D4: bc1f        L_800817C4
    if (!c1cs) {
        // 0x800816D8: nop
    
            goto L_800817C4;
    }
    // 0x800816D8: nop

    // 0x800816DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800816E0: lw          $t6, 0x2890($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2890);
    // 0x800816E4: nop

    // 0x800816E8: bne         $t6, $zero, L_80081774
    if (ctx->r14 != 0) {
        // 0x800816EC: nop
    
            goto L_80081774;
    }
    // 0x800816EC: nop

    // 0x800816F0: jal         0x800B9000
    // 0x800816F4: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x800816F4: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_1:
    // 0x800816F8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800816FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081700: nop

    // 0x80081704: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80081708: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8008170C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80081710: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80081714: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80081718: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008171C: addiu       $t8, $zero, 0xA8
    ctx->r24 = ADD32(0, 0XA8);
    // 0x80081720: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80081724: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80081728: nop

    // 0x8008172C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80081730: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80081734: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80081738: nop

    // 0x8008173C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80081740: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80081744: nop

    // 0x80081748: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8008174C: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80081750: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80081754: jal         0x80016620
    // 0x80081758: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_2;
    // 0x80081758: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8008175C: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80081760: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80081764: sw          $t0, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r8;
    // 0x80081768: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008176C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081770: sw          $t1, 0x2890($at)
    MEM_W(0X2890, ctx->r1) = ctx->r9;
L_80081774:
    // 0x80081774: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80081778: nop

    // 0x8008177C: lhu         $t3, 0x14($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X14);
    // 0x80081780: nop

    // 0x80081784: bne         $t3, $zero, L_800817AC
    if (ctx->r11 != 0) {
        // 0x80081788: nop
    
            goto L_800817AC;
    }
    // 0x80081788: nop

    // 0x8008178C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80081790: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80081794: lwc1        $f16, 0x10($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80081798: nop

    // 0x8008179C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800817A0: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800817A4: b           L_800817C4
    // 0x800817A8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_800817C4;
    // 0x800817A8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_800817AC:
    // 0x800817AC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800817B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800817B4: lwc1        $f10, 0x10($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800817B8: nop

    // 0x800817BC: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800817C0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_800817C4:
    // 0x800817C4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800817C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800817CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800817D0: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800817D4: nop

    // 0x800817D8: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800817DC: nop

    // 0x800817E0: bc1f        L_800818F0
    if (!c1cs) {
        // 0x800817E4: nop
    
            goto L_800818F0;
    }
    // 0x800817E4: nop

    // 0x800817E8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800817EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800817F0: nop

    // 0x800817F4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800817F8: nop

    // 0x800817FC: bc1f        L_800818F0
    if (!c1cs) {
        // 0x80081800: nop
    
            goto L_800818F0;
    }
    // 0x80081800: nop

    // 0x80081804: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081808: lw          $t7, 0x2890($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2890);
    // 0x8008180C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80081810: bne         $t7, $at, L_80081898
    if (ctx->r15 != ctx->r1) {
        // 0x80081814: nop
    
            goto L_80081898;
    }
    // 0x80081814: nop

    // 0x80081818: jal         0x800B9000
    // 0x8008181C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8008181C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_3:
    // 0x80081820: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80081824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80081828: nop

    // 0x8008182C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80081830: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80081834: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80081838: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8008183C: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x80081840: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80081844: addiu       $t9, $zero, 0xA8
    ctx->r25 = ADD32(0, 0XA8);
    // 0x80081848: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8008184C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80081850: nop

    // 0x80081854: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80081858: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008185C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081860: nop

    // 0x80081864: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80081868: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008186C: nop

    // 0x80081870: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80081874: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x80081878: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8008187C: jal         0x80016620
    // 0x80081880: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_4;
    // 0x80081880: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x80081884: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80081888: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8008188C: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
    // 0x80081890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081894: sw          $zero, 0x2890($at)
    MEM_W(0X2890, ctx->r1) = 0;
L_80081898:
    // 0x80081898: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008189C: nop

    // 0x800818A0: lhu         $t3, 0x14($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X14);
    // 0x800818A4: nop

    // 0x800818A8: bne         $t3, $zero, L_800818D0
    if (ctx->r11 != 0) {
        // 0x800818AC: nop
    
            goto L_800818D0;
    }
    // 0x800818AC: nop

    // 0x800818B0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800818B4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800818B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800818BC: lwc1        $f8, 0x10($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800818C0: nop

    // 0x800818C4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800818C8: b           L_800818F0
    // 0x800818CC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
        goto L_800818F0;
    // 0x800818CC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_800818D0:
    // 0x800818D0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800818D4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800818D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800818DC: lwc1        $f16, 0x10($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800818E0: nop

    // 0x800818E4: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800818E8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800818EC: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_800818F0:
    // 0x800818F0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800818F4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800818F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800818FC: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80081900: nop

    // 0x80081904: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80081908: nop

    // 0x8008190C: bc1f        L_80081A18
    if (!c1cs) {
        // 0x80081910: nop
    
            goto L_80081A18;
    }
    // 0x80081910: nop

    // 0x80081914: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081918: lwc1        $f18, -0xB08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XB08);
    // 0x8008191C: nop

    // 0x80081920: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80081924: nop

    // 0x80081928: bc1f        L_80081A18
    if (!c1cs) {
        // 0x8008192C: nop
    
            goto L_80081A18;
    }
    // 0x8008192C: nop

    // 0x80081930: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80081934: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80081938: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008193C: lwc1        $f16, 0x10($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80081940: nop

    // 0x80081944: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x80081948: nop

    // 0x8008194C: bc1f        L_8008195C
    if (!c1cs) {
        // 0x80081950: nop
    
            goto L_8008195C;
    }
    // 0x80081950: nop

    // 0x80081954: jal         0x800B9000
    // 0x80081958: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x80081958: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_5:
L_8008195C:
    // 0x8008195C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80081960: nop

    // 0x80081964: lhu         $t9, 0x14($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X14);
    // 0x80081968: nop

    // 0x8008196C: bne         $t9, $zero, L_80081984
    if (ctx->r25 != 0) {
        // 0x80081970: nop
    
            goto L_80081984;
    }
    // 0x80081970: nop

    // 0x80081974: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80081978: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008197C: b           L_80081994
    // 0x80081980: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
        goto L_80081994;
    // 0x80081980: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
L_80081984:
    // 0x80081984: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80081988: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008198C: nop

    // 0x80081990: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
L_80081994:
    // 0x80081994: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80081998: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008199C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800819A0: lwc1        $f8, 0x10($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800819A4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800819A8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800819AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800819B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800819B4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800819B8: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800819BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800819C0: lwc1        $f9, -0xB00($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XB00);
    // 0x800819C4: lwc1        $f8, -0xAFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XAFC);
    // 0x800819C8: nop

    // 0x800819CC: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800819D0: jal         0x800C3070
    // 0x800819D4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_6;
    // 0x800819D4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_6:
    // 0x800819D8: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800819DC: nop

    // 0x800819E0: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800819E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800819E8: nop

    // 0x800819EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800819F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800819F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800819F8: nop

    // 0x800819FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80081A00: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80081A04: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80081A08: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80081A0C: nop

    // 0x80081A10: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80081A14: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_80081A18:
    // 0x80081A18: jal         0x800C1754
    // 0x80081A1C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_7;
    // 0x80081A1C: nop

    after_7:
    // 0x80081A20: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80081A24: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80081A28: jal         0x800C2304
    // 0x80081A2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_8;
    // 0x80081A2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80081A30: jal         0x800AD5EC
    // 0x80081A34: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD5EC(rdram, ctx);
        goto after_9;
    // 0x80081A34: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_9:
    // 0x80081A38: jal         0x800C1A28
    // 0x80081A3C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_10;
    // 0x80081A3C: nop

    after_10:
    // 0x80081A40: b           L_80081A50
    // 0x80081A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081A50;
    // 0x80081A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80081A48: b           L_80081A50
    // 0x80081A4C: nop

        goto L_80081A50;
    // 0x80081A4C: nop

L_80081A50:
    // 0x80081A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081A54: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80081A58: jr          $ra
    // 0x80081A5C: nop

    return;
    // 0x80081A5C: nop

;}
RECOMP_FUNC void func_800659F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800659F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800659F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800659FC: jal         0x80061488
    // 0x80065A00: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065A00: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065A04: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065A08: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065A0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065A10: beq         $v0, $zero, L_80065A38
    if (ctx->r2 == 0) {
        // 0x80065A14: nop
    
            goto L_80065A38;
    }
    // 0x80065A14: nop

    // 0x80065A18: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065A1C: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065A20: nop

    // 0x80065A24: lh          $v0, 0x30($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X30);
    // 0x80065A28: nop

    // 0x80065A2C: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065A30: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065A34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065A38:
    // 0x80065A38: b           L_80065A48
    // 0x80065A3C: nop

        goto L_80065A48;
    // 0x80065A3C: nop

    // 0x80065A40: b           L_80065A48
    // 0x80065A44: nop

        goto L_80065A48;
    // 0x80065A44: nop

L_80065A48:
    // 0x80065A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065A50: jr          $ra
    // 0x80065A54: nop

    return;
    // 0x80065A54: nop

;}
RECOMP_FUNC void alSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D68E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D68EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D68F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D68F4: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800D68F8: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x800D68FC: sh          $zero, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = 0;
    // 0x800D6900: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800D6904: jal         0x800D6868
    // 0x800D6908: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    func_800D6868(rdram, ctx);
        goto after_0;
    // 0x800D6908: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    after_0:
    // 0x800D690C: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x800D6910: ori         $at, $at, 0x6864
    ctx->r1 = ctx->r1 | 0X6864;
    // 0x800D6914: bnel        $v0, $at, L_800D69B4
    if (ctx->r2 != ctx->r1) {
        // 0x800D6918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_0;
    // 0x800D6918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D691C: jal         0x800D6868
    // 0x800D6920: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800D6868(rdram, ctx);
        goto after_1;
    // 0x800D6920: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x800D6924: jal         0x800D68B8
    // 0x800D6928: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    static_5_800D68B8(rdram, ctx);
        goto after_2;
    // 0x800D6928: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x800D692C: bnel        $v0, $zero, L_800D69B4
    if (ctx->r2 != 0) {
        // 0x800D6930: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_1;
    // 0x800D6930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800D6934: jal         0x800D68B8
    // 0x800D6938: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    static_5_800D68B8(rdram, ctx);
        goto after_3;
    // 0x800D6938: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x800D693C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D6940: bnel        $v0, $at, L_800D69B4
    if (ctx->r2 != ctx->r1) {
        // 0x800D6944: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_2;
    // 0x800D6944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800D6948: jal         0x800D68B8
    // 0x800D694C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    static_5_800D68B8(rdram, ctx);
        goto after_4;
    // 0x800D694C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x800D6950: sh          $v0, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r2;
    // 0x800D6954: lh          $v1, 0x18($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X18);
    // 0x800D6958: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800D695C: bnel        $t6, $zero, L_800D69B4
    if (ctx->r14 != 0) {
        // 0x800D6960: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_3;
    // 0x800D6960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800D6964: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800D6968: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D696C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D6970: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D6974: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D6978: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D697C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800D6980: div.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800D6984: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800D6988: jal         0x800D6868
    // 0x800D698C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    func_800D6868(rdram, ctx);
        goto after_5;
    // 0x800D698C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    after_5:
    // 0x800D6990: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x800D6994: ori         $at, $at, 0x726B
    ctx->r1 = ctx->r1 | 0X726B;
    // 0x800D6998: bnel        $v0, $at, L_800D69B4
    if (ctx->r2 != ctx->r1) {
        // 0x800D699C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D69B4;
    }
    goto skip_4;
    // 0x800D699C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800D69A0: jal         0x800D6868
    // 0x800D69A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800D6868(rdram, ctx);
        goto after_6;
    // 0x800D69A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x800D69A8: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x800D69AC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800D69B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D69B4:
    // 0x800D69B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D69B8: jr          $ra
    // 0x800D69BC: nop

    return;
    // 0x800D69BC: nop

;}
RECOMP_FUNC void func_8003E568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E568: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003E56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E570: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003E574: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003E578: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003E57C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8003E580: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8003E584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003E588: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003E58C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8003E590: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E594: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003E598: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x8003E59C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003E5A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003E5A4: nop

    // 0x8003E5A8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003E5AC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003E5B0: nop

    // 0x8003E5B4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003E5B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003E5BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003E5C0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003E5C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003E5C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8003E5CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003E5D0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8003E5D4: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003E5D8: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003E5DC: bne         $at, $zero, L_8003E5EC
    if (ctx->r1 != 0) {
        // 0x8003E5E0: sh          $t7, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r15;
            goto L_8003E5EC;
    }
    // 0x8003E5E0: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
    // 0x8003E5E4: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
    // 0x8003E5E8: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
L_8003E5EC:
    // 0x8003E5EC: jal         0x800C1850
    // 0x8003E5F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_0;
    // 0x8003E5F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003E5F4: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8003E5F8: jal         0x800C25B8
    // 0x8003E5FC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_1;
    // 0x8003E5FC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x8003E600: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8003E604: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003E608: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8003E60C: jal         0x800C2304
    // 0x8003E610: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_2;
    // 0x8003E610: nop

    after_2:
    // 0x8003E614: jal         0x800B1844
    // 0x8003E618: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800B1844(rdram, ctx);
        goto after_3;
    // 0x8003E618: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x8003E61C: addiu       $t1, $sp, 0x1C
    ctx->r9 = ADD32(ctx->r29, 0X1C);
    // 0x8003E620: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8003E624: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E628: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003E62C: nop

    // 0x8003E630: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003E634: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8003E638: bc1f        L_8003E650
    if (!c1cs) {
        // 0x8003E63C: nop
    
            goto L_8003E650;
    }
    // 0x8003E63C: nop

    // 0x8003E640: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8003E644: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003E648: b           L_8003E680
    // 0x8003E64C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
        goto L_8003E680;
    // 0x8003E64C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
L_8003E650:
    // 0x8003E650: lui         $at, 0xC2FE
    ctx->r1 = S32(0XC2FE << 16);
    // 0x8003E654: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003E658: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003E65C: nop

    // 0x8003E660: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8003E664: nop

    // 0x8003E668: bc1f        L_8003E680
    if (!c1cs) {
        // 0x8003E66C: nop
    
            goto L_8003E680;
    }
    // 0x8003E66C: nop

    // 0x8003E670: lui         $at, 0xC2FE
    ctx->r1 = S32(0XC2FE << 16);
    // 0x8003E674: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003E678: nop

    // 0x8003E67C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
L_8003E680:
    // 0x8003E680: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003E684: lwc1        $f17, -0x13A8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X13A8);
    // 0x8003E688: lwc1        $f16, -0x13A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X13A4);
    // 0x8003E68C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003E690: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003E694: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003E698: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003E69C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003E6A0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8003E6A4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8003E6A8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003E6AC: nop

    // 0x8003E6B0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8003E6B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003E6B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003E6BC: nop

    // 0x8003E6C0: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x8003E6C4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8003E6C8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003E6CC: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x8003E6D0: nop

    // 0x8003E6D4: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003E6D8: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x8003E6DC: lh          $a3, 0x2C($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2C);
    // 0x8003E6E0: jal         0x80031C90
    // 0x8003E6E4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    func_80031C90(rdram, ctx);
        goto after_4;
    // 0x8003E6E4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_4:
    // 0x8003E6E8: b           L_8003E6F0
    // 0x8003E6EC: nop

        goto L_8003E6F0;
    // 0x8003E6EC: nop

L_8003E6F0:
    // 0x8003E6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E6F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003E6F8: jr          $ra
    // 0x8003E6FC: nop

    return;
    // 0x8003E6FC: nop

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
RECOMP_FUNC void func_80066ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066ED8: jal         0x80061488
    // 0x80066EDC: addiu       $a0, $zero, 0x256
    ctx->r4 = ADD32(0, 0X256);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80066EDC: addiu       $a0, $zero, 0x256
    ctx->r4 = ADD32(0, 0X256);
    after_0:
    // 0x80066EE0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80066EE4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80066EE8: b           L_80066EF8
    // 0x80066EEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066EF8;
    // 0x80066EEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066EF0: b           L_80066EF8
    // 0x80066EF4: nop

        goto L_80066EF8;
    // 0x80066EF4: nop

L_80066EF8:
    // 0x80066EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066F00: jr          $ra
    // 0x80066F04: nop

    return;
    // 0x80066F04: nop

;}
RECOMP_FUNC void func_800862A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800862A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800862A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800862AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800862B0: jal         0x8008B4EC
    // 0x800862B4: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800862B4: nop

    after_0:
    // 0x800862B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800862BC: jal         0x8008B600
    // 0x800862C0: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800862C0: nop

    after_1:
    // 0x800862C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800862C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800862CC: jal         0x8008B738
    // 0x800862D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x800862D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800862D4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800862D8: jal         0x8008A518
    // 0x800862DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x800862DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800862E0: beq         $v0, $zero, L_80086378
    if (ctx->r2 == 0) {
        // 0x800862E4: nop
    
            goto L_80086378;
    }
    // 0x800862E4: nop

    // 0x800862E8: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x800862EC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800862F0: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800862F4: bne         $at, $zero, L_80086378
    if (ctx->r1 != 0) {
        // 0x800862F8: nop
    
            goto L_80086378;
    }
    // 0x800862F8: nop

    // 0x800862FC: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80086300: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086304: beq         $at, $zero, L_80086378
    if (ctx->r1 == 0) {
        // 0x80086308: nop
    
            goto L_80086378;
    }
    // 0x80086308: nop

    // 0x8008630C: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086310: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086314: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086318: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008631C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086320: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086324: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086328: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008632C: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086330: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80086334: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80086338: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008633C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80086340: nop

    // 0x80086344: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086348: nop

    // 0x8008634C: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086350: beq         $t4, $zero, L_80086378
    if (ctx->r12 == 0) {
        // 0x80086354: nop
    
            goto L_80086378;
    }
    // 0x80086354: nop

    // 0x80086358: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x8008635C: beq         $t5, $zero, L_80086378
    if (ctx->r13 == 0) {
        // 0x80086360: nop
    
            goto L_80086378;
    }
    // 0x80086360: nop

    // 0x80086364: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80086368: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008636C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086370: jal         0x8008B738
    // 0x80086374: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80086374: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_4:
L_80086378:
    // 0x80086378: b           L_80086380
    // 0x8008637C: nop

        goto L_80086380;
    // 0x8008637C: nop

L_80086380:
    // 0x80086380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086384: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086388: jr          $ra
    // 0x8008638C: nop

    return;
    // 0x8008638C: nop

;}
RECOMP_FUNC void func_8006C120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C128: jal         0x8005F064
    // 0x8006C12C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C12C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_0:
    // 0x8006C130: b           L_8006C140
    // 0x8006C134: nop

        goto L_8006C140;
    // 0x8006C134: nop

    // 0x8006C138: b           L_8006C140
    // 0x8006C13C: nop

        goto L_8006C140;
    // 0x8006C13C: nop

L_8006C140:
    // 0x8006C140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C148: jr          $ra
    // 0x8006C14C: nop

    return;
    // 0x8006C14C: nop

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
RECOMP_FUNC void func_800670DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800670DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800670E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800670E4: nop

    // 0x800670E8: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800670EC: nop

    // 0x800670F0: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x800670F4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800670F8: jr          $ra
    // 0x800670FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800670FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067100: jr          $ra
    // 0x80067104: nop

    return;
    // 0x80067104: nop

    // 0x80067108: jr          $ra
    // 0x8006710C: nop

    return;
    // 0x8006710C: nop

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
RECOMP_FUNC void func_80065718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006571C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065720: jal         0x8005F064
    // 0x80065724: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065724: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x80065728: b           L_80065738
    // 0x8006572C: nop

        goto L_80065738;
    // 0x8006572C: nop

    // 0x80065730: b           L_80065738
    // 0x80065734: nop

        goto L_80065738;
    // 0x80065734: nop

L_80065738:
    // 0x80065738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006573C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065740: jr          $ra
    // 0x80065744: nop

    return;
    // 0x80065744: nop

;}
RECOMP_FUNC void func_80074F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074F74: jal         0x80061348
    // 0x80074F78: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074F78: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    after_0:
    // 0x80074F7C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074F80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074F84: bne         $v0, $zero, L_80074F9C
    if (ctx->r2 != 0) {
        // 0x80074F88: nop
    
            goto L_80074F9C;
    }
    // 0x80074F88: nop

    // 0x80074F8C: jal         0x80061348
    // 0x80074F90: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074F90: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    after_1:
    // 0x80074F94: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074F98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074F9C:
    // 0x80074F9C: b           L_80074FAC
    // 0x80074FA0: nop

        goto L_80074FAC;
    // 0x80074FA0: nop

    // 0x80074FA4: b           L_80074FAC
    // 0x80074FA8: nop

        goto L_80074FAC;
    // 0x80074FA8: nop

L_80074FAC:
    // 0x80074FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074FB4: jr          $ra
    // 0x80074FB8: nop

    return;
    // 0x80074FB8: nop

;}
RECOMP_FUNC void func_8006F56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F56C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F570: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F574: nop

    // 0x8006F578: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F57C: nop

    // 0x8006F580: slti        $t7, $v0, 0x385
    ctx->r15 = SIGNED(ctx->r2) < 0X385 ? 1 : 0;
    // 0x8006F584: jr          $ra
    // 0x8006F588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F58C: jr          $ra
    // 0x8006F590: nop

    return;
    // 0x8006F590: nop

    // 0x8006F594: jr          $ra
    // 0x8006F598: nop

    return;
    // 0x8006F598: nop

;}
RECOMP_FUNC void func_80031C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C04: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80031C08: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80031C0C: lhu         $t6, -0x6504($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6504);
    // 0x80031C10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80031C14: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80031C18: sh          $t7, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r15;
    // 0x80031C1C: jr          $ra
    // 0x80031C20: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    return;
    // 0x80031C20: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
;}
RECOMP_FUNC void func_80062BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062BE0: jal         0x8005F064
    // 0x80062BE4: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062BE4: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_0:
    // 0x80062BE8: b           L_80062BF8
    // 0x80062BEC: nop

        goto L_80062BF8;
    // 0x80062BEC: nop

    // 0x80062BF0: b           L_80062BF8
    // 0x80062BF4: nop

        goto L_80062BF8;
    // 0x80062BF4: nop

L_80062BF8:
    // 0x80062BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062C00: jr          $ra
    // 0x80062C04: nop

    return;
    // 0x80062C04: nop

;}
RECOMP_FUNC void alEnvmixerPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D172C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800D1730: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800D1734: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800D1738: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800D173C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800D1740: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800D1744: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800D1748: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800D174C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800D1750: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800D1754: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800D1758: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800D175C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800D1760: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800D1764: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800D1768: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800D176C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800D1770: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800D1774: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x800D1778: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800D177C: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800D1780: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x800D1784: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800D1788: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800D178C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D1790: beql        $t8, $zero, L_800D1C04
    if (ctx->r24 == 0) {
        // 0x800D1794: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_800D1C04;
    }
    goto skip_0;
    // 0x800D1794: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    skip_0:
    // 0x800D1798: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_800D179C:
    // 0x800D179C: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x800D17A0: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x800D17A4: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800D17A8: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x800D17AC: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D17B0: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800D17B4: bne         $at, $zero, L_800D1C00
    if (ctx->r1 != 0) {
        // 0x800D17B8: sw          $t9, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r25;
            goto L_800D1C00;
    }
    // 0x800D17B8: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800D17BC: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x800D17C0: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x800D17C4: beq         $at, $zero, L_800D1B78
    if (ctx->r1 == 0) {
        // 0x800D17C8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D1B78;
    }
    // 0x800D17C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D17CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D17D0: addu        $at, $at, $t9
    gpr jr_addend_800D17D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D17D4: lw          $t9, 0x320($at)
    ctx->r25 = ADD32(ctx->r1, 0X320);
    // 0x800D17D8: jr          $t9
    // 0x800D17DC: nop

    switch (jr_addend_800D17D8 >> 2) {
        case 0: goto L_800D1B58; break;
        case 1: goto L_800D1B78; break;
        case 2: goto L_800D1B78; break;
        case 3: goto L_800D1B78; break;
        case 4: goto L_800D1B78; break;
        case 5: goto L_800D1B78; break;
        case 6: goto L_800D1B78; break;
        case 7: goto L_800D1B78; break;
        case 8: goto L_800D1B78; break;
        case 9: goto L_800D1B78; break;
        case 10: goto L_800D1B78; break;
        case 11: goto L_800D1920; break;
        case 12: goto L_800D1920; break;
        case 13: goto L_800D17E0; break;
        case 14: goto L_800D1AC4; break;
        case 15: goto L_800D1B18; break;
        case 16: goto L_800D1920; break;
        default: switch_error(__func__, 0x800D17D8, 0x800F0320);
    }
    // 0x800D17DC: nop

L_800D17E0:
    // 0x800D17E0: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x800D17E4: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800D17E8: beql        $t6, $zero, L_800D1808
    if (ctx->r14 == 0) {
        // 0x800D17EC: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_800D1808;
    }
    goto skip_1;
    // 0x800D17EC: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_1:
    // 0x800D17F0: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D17F4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D17F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D17FC: jalr        $t9
    // 0x800D1800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D1800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800D1804: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_800D1808:
    // 0x800D1808: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D180C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800D1810: jalr        $t9
    // 0x800D1814: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D1814: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x800D1818: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D181C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1820: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D1824: jalr        $t9
    // 0x800D1828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D1828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800D182C: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
    // 0x800D1830: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800D1834: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D1838: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800D183C: lh          $v1, 0x10($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X10);
    // 0x800D1840: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1844: mflo        $a0
    ctx->r4 = lo;
    // 0x800D1848: sra         $t7, $a0, 15
    ctx->r15 = S32(SIGNED(ctx->r4) >> 15);
    // 0x800D184C: sh          $t7, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r15;
    // 0x800D1850: lbu         $t6, 0x12($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X12);
    // 0x800D1854: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1858: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800D185C: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800D1860: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800D1864: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D1868: lh          $t7, -0x3120($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3120);
    // 0x800D186C: sh          $t7, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r15;
    // 0x800D1870: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x800D1874: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1878: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800D187C: negu        $t8, $t9
    ctx->r24 = SUB32(0, ctx->r25);
    // 0x800D1880: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D1884: lh          $t7, -0x3022($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3022);
    // 0x800D1888: sh          $t7, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r15;
    // 0x800D188C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D1890: beql        $t6, $zero, L_800D18A8
    if (ctx->r14 == 0) {
        // 0x800D1894: lh          $v0, 0x18($fp)
        ctx->r2 = MEM_H(ctx->r30, 0X18);
            goto L_800D18A8;
    }
    goto skip_2;
    // 0x800D1894: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    skip_2:
    // 0x800D1898: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800D189C: b           L_800D18EC
    // 0x800D18A0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
        goto L_800D18EC;
    // 0x800D18A0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800D18A4: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
L_800D18A8:
    // 0x800D18A8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800D18AC: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x800D18B0: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800D18B4: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800D18B8: lh          $t8, -0x3120($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3120);
    // 0x800D18BC: negu        $t9, $t9
    ctx->r25 = SUB32(0, ctx->r25);
    // 0x800D18C0: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D18C4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800D18C8: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800D18CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800D18D0: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800D18D4: sh          $t6, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r14;
    // 0x800D18D8: lh          $t8, -0x3022($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3022);
    // 0x800D18DC: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D18E0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D18E4: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800D18E8: sh          $t6, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r14;
L_800D18EC:
    // 0x800D18EC: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800D18F0: beql        $t9, $zero, L_800D1BB8
    if (ctx->r25 == 0) {
        // 0x800D18F4: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_800D1BB8;
    }
    goto skip_3;
    // 0x800D18F4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_3:
    // 0x800D18F8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800D18FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800D1900: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800D1904: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800D1908: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800D190C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D1910: jalr        $t9
    // 0x800D1914: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800D1914: nop

    after_3:
    // 0x800D1918: b           L_800D1BB8
    // 0x800D191C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D191C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1920:
    // 0x800D1920: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800D1924: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1928: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D192C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800D1930: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1934: jal         0x800D13E4
    // 0x800D1938: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_5_800D13E4(rdram, ctx);
        goto after_4;
    // 0x800D1938: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_4:
    // 0x800D193C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1940: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x800D1944: lw          $a3, 0x30($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X30);
    // 0x800D1948: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D194C: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D1950: bnel        $at, $zero, L_800D19BC
    if (ctx->r1 != 0) {
        // 0x800D1954: lh          $t6, 0x1C($fp)
        ctx->r14 = MEM_H(ctx->r30, 0X1C);
            goto L_800D19BC;
    }
    goto skip_4;
    // 0x800D1954: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
    skip_4:
    // 0x800D1958: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    // 0x800D195C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1960: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x800D1964: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800D1968: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D196C: lh          $t7, -0x3120($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3120);
    // 0x800D1970: negu        $t8, $t8
    ctx->r24 = SUB32(0, ctx->r24);
    // 0x800D1974: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1978: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D197C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D1980: mflo        $t6
    ctx->r14 = lo;
    // 0x800D1984: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800D1988: sh          $t9, 0x28($fp)
    MEM_H(0X28, ctx->r30) = ctx->r25;
    // 0x800D198C: lh          $t7, -0x3022($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3022);
    // 0x800D1990: lh          $t8, 0x28($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X28);
    // 0x800D1994: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800D1998: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D199C: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800D19A0: mflo        $t6
    ctx->r14 = lo;
    // 0x800D19A4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800D19A8: sh          $t9, 0x2E($fp)
    MEM_H(0X2E, ctx->r30) = ctx->r25;
    // 0x800D19AC: lh          $t7, 0x2E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X2E);
    // 0x800D19B0: b           L_800D1A0C
    // 0x800D19B4: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
        goto L_800D1A0C;
    // 0x800D19B4: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
    // 0x800D19B8: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
L_800D19BC:
    // 0x800D19BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D19C0: lh          $a1, 0x26($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X26);
    // 0x800D19C4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D19C8: lhu         $a2, 0x24($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X24);
    // 0x800D19CC: jal         0x800D167C
    // 0x800D19D0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    static_5_800D167C(rdram, ctx);
        goto after_5;
    // 0x800D19D0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x800D19D4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D19D8: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    // 0x800D19DC: lw          $a0, 0x30($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X30);
    // 0x800D19E0: lh          $a1, 0x2C($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X2C);
    // 0x800D19E4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800D19E8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800D19EC: lhu         $a2, 0x2A($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X2A);
    // 0x800D19F0: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800D19F4: jal         0x800D167C
    // 0x800D19F8: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    static_5_800D167C(rdram, ctx);
        goto after_6;
    // 0x800D19F8: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_6:
    // 0x800D19FC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D1A00: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800D1A04: nop

    // 0x800D1A08: sh          $t9, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r25;
L_800D1A0C:
    // 0x800D1A0C: lh          $t8, 0x1C($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X1C);
    // 0x800D1A10: bnel        $t8, $zero, L_800D1A20
    if (ctx->r24 != 0) {
        // 0x800D1A14: lh          $t7, 0x1E($fp)
        ctx->r15 = MEM_H(ctx->r30, 0X1E);
            goto L_800D1A20;
    }
    goto skip_5;
    // 0x800D1A14: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    skip_5:
    // 0x800D1A18: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800D1A1C: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
L_800D1A20:
    // 0x800D1A20: bnel        $t7, $zero, L_800D1A30
    if (ctx->r15 != 0) {
        // 0x800D1A24: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_800D1A30;
    }
    goto skip_6;
    // 0x800D1A24: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_6:
    // 0x800D1A28: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800D1A2C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_800D1A30:
    // 0x800D1A30: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800D1A34: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800D1A38: bnel        $a0, $at, L_800D1A50
    if (ctx->r4 != ctx->r1) {
        // 0x800D1A3C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800D1A50;
    }
    goto skip_7;
    // 0x800D1A3C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_7:
    // 0x800D1A40: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x800D1A44: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800D1A48: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800D1A4C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_800D1A50:
    // 0x800D1A50: bnel        $a0, $at, L_800D1A80
    if (ctx->r4 != ctx->r1) {
        // 0x800D1A54: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800D1A80;
    }
    goto skip_8;
    // 0x800D1A54: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x800D1A58: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800D1A5C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800D1A60: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1A64: mflo        $v0
    ctx->r2 = lo;
    // 0x800D1A68: sra         $t9, $v0, 15
    ctx->r25 = S32(SIGNED(ctx->r2) >> 15);
    // 0x800D1A6C: sh          $t9, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r25;
    // 0x800D1A70: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x800D1A74: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800D1A78: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800D1A7C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_800D1A80:
    // 0x800D1A80: bne         $a0, $at, L_800D1ABC
    if (ctx->r4 != ctx->r1) {
        // 0x800D1A84: nop
    
            goto L_800D1ABC;
    }
    // 0x800D1A84: nop

    // 0x800D1A88: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800D1A8C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800D1A90: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800D1A94: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800D1A98: lh          $t9, -0x3120($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X3120);
    // 0x800D1A9C: sh          $t9, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r25;
    // 0x800D1AA0: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800D1AA4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800D1AA8: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800D1AAC: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x800D1AB0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800D1AB4: lh          $t9, -0x3022($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X3022);
    // 0x800D1AB8: sh          $t9, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r25;
L_800D1ABC:
    // 0x800D1ABC: b           L_800D1BB4
    // 0x800D1AC0: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
        goto L_800D1BB4;
    // 0x800D1AC0: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
L_800D1AC4:
    // 0x800D1AC4: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x800D1AC8: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800D1ACC: beql        $t8, $zero, L_800D1AEC
    if (ctx->r24 == 0) {
        // 0x800D1AD0: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_800D1AEC;
    }
    goto skip_9;
    // 0x800D1AD0: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_9:
    // 0x800D1AD4: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1AD8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1ADC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D1AE0: jalr        $t9
    // 0x800D1AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x800D1AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800D1AE8: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_800D1AEC:
    // 0x800D1AEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1AF0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800D1AF4: jalr        $t9
    // 0x800D1AF8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800D1AF8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x800D1AFC: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1B00: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1B04: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D1B08: jalr        $t9
    // 0x800D1B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800D1B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800D1B10: b           L_800D1BB8
    // 0x800D1B14: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D1B14: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1B18:
    // 0x800D1B18: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800D1B1C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1B20: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D1B24: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800D1B28: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1B2C: jal         0x800D13E4
    // 0x800D1B30: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_5_800D13E4(rdram, ctx);
        goto after_10;
    // 0x800D1B30: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_10:
    // 0x800D1B34: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1B38: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1B3C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D1B40: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1B44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800D1B48: jalr        $t9
    // 0x800D1B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800D1B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800D1B50: b           L_800D1BB8
    // 0x800D1B54: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D1B54: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1B58:
    // 0x800D1B58: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800D1B5C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D1B60: lw          $a0, -0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33E0);
    // 0x800D1B64: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x800D1B68: jal         0x800C7B50
    // 0x800D1B6C: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    _freePVoice(rdram, ctx);
        goto after_12;
    // 0x800D1B6C: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_12:
    // 0x800D1B70: b           L_800D1BB8
    // 0x800D1B74: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D1B74: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1B78:
    // 0x800D1B78: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800D1B7C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1B80: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D1B84: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800D1B88: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1B8C: jal         0x800D13E4
    // 0x800D1B90: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_5_800D13E4(rdram, ctx);
        goto after_13;
    // 0x800D1B90: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_13:
    // 0x800D1B94: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1B98: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1B9C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    // 0x800D1BA0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D1BA4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1BA8: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x800D1BAC: jalr        $t9
    // 0x800D1BB0: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800D1BB0: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_14:
L_800D1BB4:
    // 0x800D1BB4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1BB8:
    // 0x800D1BB8: lh          $t6, 0x8E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8E);
    // 0x800D1BBC: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800D1BC0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800D1BC4: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800D1BC8: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
    // 0x800D1BCC: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x800D1BD0: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800D1BD4: lw          $a0, 0x3C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X3C);
    // 0x800D1BD8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800D1BDC: bne         $t9, $zero, L_800D1BE8
    if (ctx->r25 != 0) {
        // 0x800D1BE0: sw          $t9, 0x3C($fp)
        MEM_W(0X3C, ctx->r30) = ctx->r25;
            goto L_800D1BE8;
    }
    // 0x800D1BE0: sw          $t9, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r25;
    // 0x800D1BE4: sw          $zero, 0x40($fp)
    MEM_W(0X40, ctx->r30) = 0;
L_800D1BE8:
    // 0x800D1BE8: jal         0x800C7BE8
    // 0x800D1BEC: nop

    __freeParam(rdram, ctx);
        goto after_15;
    // 0x800D1BEC: nop

    after_15:
    // 0x800D1BF0: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800D1BF4: lw          $t7, 0x3C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X3C);
    // 0x800D1BF8: bnel        $t7, $zero, L_800D179C
    if (ctx->r15 != 0) {
        // 0x800D1BFC: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_800D179C;
    }
    goto skip_10;
    // 0x800D1BFC: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_10:
L_800D1C00:
    // 0x800D1C00: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
L_800D1C04:
    // 0x800D1C04: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1C08: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D1C0C: lw          $s5, 0xB0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB0);
    // 0x800D1C10: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1C14: jal         0x800D13E4
    // 0x800D1C18: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_5_800D13E4(rdram, ctx);
        goto after_16;
    // 0x800D1C18: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_16:
    // 0x800D1C1C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1C20: lw          $t9, 0x30($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X30);
    // 0x800D1C24: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x800D1C28: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D1C2C: beql        $at, $zero, L_800D1C3C
    if (ctx->r1 == 0) {
        // 0x800D1C30: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800D1C3C;
    }
    goto skip_11;
    // 0x800D1C30: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_11:
    // 0x800D1C34: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800D1C38: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800D1C3C:
    // 0x800D1C3C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x800D1C40: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800D1C44: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800D1C48: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800D1C4C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800D1C50: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800D1C54: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1C58: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800D1C5C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C60: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800D1C64: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1C68: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800D1C6C: jr          $ra
    // 0x800D1C70: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800D1C70: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8001292C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001292C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80012930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012934: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80012938: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001293C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80012940: jal         0x8000DA44
    // 0x80012944: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012944: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80012948: bgez        $v0, L_80012958
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001294C: nop
    
            goto L_80012958;
    }
    // 0x8001294C: nop

    // 0x80012950: b           L_800129EC
    // 0x80012954: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800129EC;
    // 0x80012954: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012958:
    // 0x80012958: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001295C: nop

    // 0x80012960: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80012964: nop

    // 0x80012968: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001296C: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x80012970: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012974: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012978: nop

    // 0x8001297C: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012980: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80012984: nop

    // 0x80012988: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8001298C: nop

    // 0x80012990: lh          $t3, 0x11E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X11E);
    // 0x80012994: nop

    // 0x80012998: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8001299C: nop

    // 0x800129A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800129A4: swc1        $f6, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f6.u32l;
    // 0x800129A8: addiu       $t4, $sp, 0x1C
    ctx->r12 = ADD32(ctx->r29, 0X1C);
    // 0x800129AC: lhu         $a0, 0x4($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X4);
    // 0x800129B0: jal         0x80014BD4
    // 0x800129B4: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x800129B4: nop

    after_1:
    // 0x800129B8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800129BC: nop

    // 0x800129C0: swc1        $f0, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f0.u32l;
    // 0x800129C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800129C8: nop

    // 0x800129CC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800129D0: nop

    // 0x800129D4: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x800129D8: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x800129DC: b           L_800129EC
    // 0x800129E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800129EC;
    // 0x800129E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800129E4: b           L_800129EC
    // 0x800129E8: nop

        goto L_800129EC;
    // 0x800129E8: nop

L_800129EC:
    // 0x800129EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800129F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800129F4: jr          $ra
    // 0x800129F8: nop

    return;
    // 0x800129F8: nop

;}
RECOMP_FUNC void n_alSynFreeFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9044: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B9048: b           L_800B9050
    // 0x800B904C: nop

        goto L_800B9050;
    // 0x800B904C: nop

L_800B9050:
    // 0x800B9050: jr          $ra
    // 0x800B9054: nop

    return;
    // 0x800B9054: nop

    // 0x800B9058: jr          $ra
    // 0x800B905C: nop

    return;
    // 0x800B905C: nop

    // 0x800B9060: jr          $ra
    // 0x800B9064: nop

    return;
    // 0x800B9064: nop

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
RECOMP_FUNC void func_8006C9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C9B0: jal         0x8005F064
    // 0x8006C9B4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C9B4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_0:
    // 0x8006C9B8: b           L_8006C9C8
    // 0x8006C9BC: nop

        goto L_8006C9C8;
    // 0x8006C9BC: nop

    // 0x8006C9C0: b           L_8006C9C8
    // 0x8006C9C4: nop

        goto L_8006C9C8;
    // 0x8006C9C4: nop

L_8006C9C8:
    // 0x8006C9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C9CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C9D0: jr          $ra
    // 0x8006C9D4: nop

    return;
    // 0x8006C9D4: nop

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
RECOMP_FUNC void alSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63A0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800D63A4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D63A8: lh          $t7, 0x1A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1A);
    // 0x800D63AC: sh          $t7, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r15;
    // 0x800D63B0: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x800D63B4: jr          $ra
    // 0x800D63B8: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    return;
    // 0x800D63B8: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void func_800BD620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD620: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD624: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD628: lw          $t6, 0x2640($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2640);
    // 0x800BD62C: nop

    // 0x800BD630: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BD634: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BD638: lw          $t7, 0x2640($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2640);
    // 0x800BD63C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD640: or          $t8, $t7, $a0
    ctx->r24 = ctx->r15 | ctx->r4;
    // 0x800BD644: sw          $t8, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = ctx->r24;
    // 0x800BD648: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BD64C: b           L_800BD65C
    // 0x800BD650: nop

        goto L_800BD65C;
    // 0x800BD650: nop

    // 0x800BD654: b           L_800BD65C
    // 0x800BD658: nop

        goto L_800BD65C;
    // 0x800BD658: nop

L_800BD65C:
    // 0x800BD65C: jr          $ra
    // 0x800BD660: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD660: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void MtxUtil_SetCurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1AF4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1AF8: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800C1AFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1B00: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1B04: nop

    // 0x800C1B08: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800C1B0C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C1B10: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800C1B14:
    // 0x800C1B14: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C1B18: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C1B1C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C1B20: nop

    // 0x800C1B24: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1B28: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C1B2C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C1B30: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1B34: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C1B38: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C1B3C: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C1B40: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1B44: nop

    // 0x800C1B48: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800C1B4C: bgtz        $t5, L_800C1B14
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C1B50: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C1B14;
    }
    // 0x800C1B50: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C1B54: b           L_800C1B5C
    // 0x800C1B58: nop

        goto L_800C1B5C;
    // 0x800C1B58: nop

L_800C1B5C:
    // 0x800C1B5C: jr          $ra
    // 0x800C1B60: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1B60: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80077904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077904: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077908: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007790C: nop

    // 0x80077910: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077914: nop

    // 0x80077918: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007791C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077920: jr          $ra
    // 0x80077924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077928: jr          $ra
    // 0x8007792C: nop

    return;
    // 0x8007792C: nop

    // 0x80077930: jr          $ra
    // 0x80077934: nop

    return;
    // 0x80077934: nop

;}
RECOMP_FUNC void func_80029528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029528: jr          $ra
    // 0x8002952C: nop

    return;
    // 0x8002952C: nop

    // 0x80029530: jr          $ra
    // 0x80029534: nop

    return;
    // 0x80029534: nop

;}
RECOMP_FUNC void Update_ControllerRaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098D24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80098D28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098D2C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80098D30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80098D34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80098D38: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80098D3C: lw          $t6, 0x24D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X24D4);
    // 0x80098D40: nop

    // 0x80098D44: beq         $t6, $zero, L_80098D68
    if (ctx->r14 == 0) {
        // 0x80098D48: nop
    
            goto L_80098D68;
    }
    // 0x80098D48: nop

    // 0x80098D4C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80098D50: addiu       $t7, $t7, 0x3DF8
    ctx->r15 = ADD32(ctx->r15, 0X3DF8);
    // 0x80098D54: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x80098D58: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80098D5C: addiu       $a1, $a1, 0x16C8
    ctx->r5 = ADD32(ctx->r5, 0X16C8);
    // 0x80098D60: jal         0x800C1264
    // 0x80098D64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x80098D64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
L_80098D68:
    // 0x80098D68: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80098D6C:
    // 0x80098D6C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80098D70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80098D74: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80098D78: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80098D7C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80098D80: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80098D84: lbu         $t0, 0x255C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X255C);
    // 0x80098D88: nop

    // 0x80098D8C: bne         $t0, $zero, L_80098FB8
    if (ctx->r8 != 0) {
        // 0x80098D90: nop
    
            goto L_80098FB8;
    }
    // 0x80098D90: nop

    // 0x80098D94: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80098D98: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80098D9C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80098DA0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80098DA4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80098DA8: addiu       $t3, $t3, 0xDA8
    ctx->r11 = ADD32(ctx->r11, 0XDA8);
    // 0x80098DAC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80098DB0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80098DB4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80098DB8: nop

    // 0x80098DBC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80098DC0: nop

    // 0x80098DC4: beq         $t6, $zero, L_80098DF4
    if (ctx->r14 == 0) {
        // 0x80098DC8: nop
    
            goto L_80098DF4;
    }
    // 0x80098DC8: nop

    // 0x80098DCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80098DD0: lwc1        $f4, 0xE50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE50);
    // 0x80098DD4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80098DD8: nop

    // 0x80098DDC: swc1        $f4, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f4.u32l;
    // 0x80098DE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80098DE4: lwc1        $f6, 0xE5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE5C);
    // 0x80098DE8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80098DEC: nop

    // 0x80098DF0: swc1        $f6, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f6.u32l;
L_80098DF4:
    // 0x80098DF4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80098DF8: nop

    // 0x80098DFC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x80098E00: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80098E04: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80098E08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80098E0C: lwc1        $f8, 0x18($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80098E10: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80098E14: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80098E18: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80098E1C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80098E20: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80098E24: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80098E28: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80098E2C: lb          $t3, 0x255A($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X255A);
    // 0x80098E30: nop

    // 0x80098E34: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80098E38: nop

    // 0x80098E3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80098E40: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80098E44: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x80098E48: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80098E4C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80098E50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80098E54: lwc1        $f8, 0x1C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80098E58: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80098E5C: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80098E60: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80098E64: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80098E68: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80098E6C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80098E70: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098E74: lb          $t7, 0x255B($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X255B);
    // 0x80098E78: nop

    // 0x80098E7C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80098E80: nop

    // 0x80098E84: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80098E88: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80098E8C: swc1        $f6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f6.u32l;
    // 0x80098E90: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80098E94: nop

    // 0x80098E98: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x80098E9C: nop

    // 0x80098EA0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80098EA4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80098EA8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80098EAC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80098EB0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80098EB4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80098EB8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80098EBC: lhu         $t3, 0x2558($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X2558);
    // 0x80098EC0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80098EC4: nop

    // 0x80098EC8: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    // 0x80098ECC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80098ED0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80098ED4: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x80098ED8: nop

    // 0x80098EDC: xor         $t4, $t6, $t7
    ctx->r12 = ctx->r14 ^ ctx->r15;
    // 0x80098EE0: and         $t8, $t4, $t6
    ctx->r24 = ctx->r12 & ctx->r14;
    // 0x80098EE4: sh          $t8, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r24;
    // 0x80098EE8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80098EEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80098EF0: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80098EF4: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80098EF8: nop

    // 0x80098EFC: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80098F00: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x80098F04: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F08: nop

    // 0x80098F0C: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x80098F10: lhu         $t3, 0xA($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0XA);
    // 0x80098F14: nop

    // 0x80098F18: beq         $t2, $t3, L_80098F5C
    if (ctx->r10 == ctx->r11) {
        // 0x80098F1C: nop
    
            goto L_80098F5C;
    }
    // 0x80098F1C: nop

    // 0x80098F20: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F24: nop

    // 0x80098F28: lhu         $t7, 0x4($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X4);
    // 0x80098F2C: nop

    // 0x80098F30: sh          $t7, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r15;
    // 0x80098F34: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F38: nop

    // 0x80098F3C: lhu         $t6, 0x4($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X4);
    // 0x80098F40: nop

    // 0x80098F44: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
    // 0x80098F48: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80098F4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80098F50: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F54: b           L_80098FB0
    // 0x80098F58: swc1        $f16, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f16.u32l;
        goto L_80098FB0;
    // 0x80098F58: swc1        $f16, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f16.u32l;
L_80098F5C:
    // 0x80098F5C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80098F64: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80098F68: nop

    // 0x80098F6C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80098F70: nop

    // 0x80098F74: bc1f        L_80098FA4
    if (!c1cs) {
        // 0x80098F78: nop
    
            goto L_80098FA4;
    }
    // 0x80098F78: nop

    // 0x80098F7C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F80: nop

    // 0x80098F84: lhu         $t1, 0xA($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0XA);
    // 0x80098F88: nop

    // 0x80098F8C: sh          $t1, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r9;
    // 0x80098F90: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80098F94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80098F98: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F9C: b           L_80098FB0
    // 0x80098FA0: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
        goto L_80098FB0;
    // 0x80098FA0: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
L_80098FA4:
    // 0x80098FA4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80098FA8: nop

    // 0x80098FAC: sh          $zero, 0x8($t3)
    MEM_H(0X8, ctx->r11) = 0;
L_80098FB0:
    // 0x80098FB0: b           L_80099050
    // 0x80098FB4: nop

        goto L_80099050;
    // 0x80098FB4: nop

L_80098FB8:
    // 0x80098FB8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80098FBC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80098FC0: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80098FC4: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80098FC8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80098FCC: addiu       $t6, $t6, 0xDA8
    ctx->r14 = ADD32(ctx->r14, 0XDA8);
    // 0x80098FD0: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x80098FD4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80098FD8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80098FDC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80098FE0: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80098FE4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80098FE8: nop

    // 0x80098FEC: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x80098FF0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80098FF4: nop

    // 0x80098FF8: lhu         $s1, 0xA($t9)
    ctx->r17 = MEM_HU(ctx->r25, 0XA);
    // 0x80098FFC: nop

    // 0x80099000: sh          $s1, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r17;
    // 0x80099004: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80099008: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x8009900C: sh          $s0, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r16;
    // 0x80099010: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099014: nop

    // 0x80099018: sh          $s0, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r16;
    // 0x8009901C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80099020: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80099024: nop

    // 0x80099028: swc1        $f10, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f10.u32l;
    // 0x8009902C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80099030: nop

    // 0x80099034: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80099038: nop

    // 0x8009903C: swc1        $f4, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f4.u32l;
    // 0x80099040: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80099044: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80099048: nop

    // 0x8009904C: swc1        $f16, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f16.u32l;
L_80099050:
    // 0x80099050: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099054: nop

    // 0x80099058: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x8009905C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80099060: bne         $at, $zero, L_80098D6C
    if (ctx->r1 != 0) {
        // 0x80099064: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_80098D6C;
    }
    // 0x80099064: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80099068: b           L_80099078
    // 0x8009906C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80099078;
    // 0x8009906C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80099070: b           L_80099078
    // 0x80099074: nop

        goto L_80099078;
    // 0x80099074: nop

L_80099078:
    // 0x80099078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009907C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80099080: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80099084: jr          $ra
    // 0x80099088: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80099088: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD660: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CD664: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800CD668: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800CD66C: blez        $a1, L_800CD6B0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800CD670: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_800CD6B0;
    }
    // 0x800CD670: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800CD674:
    // 0x800CD674: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800CD678: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800CD67C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800CD680: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800CD684: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800CD688: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800CD68C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800CD690: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800CD694: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800CD698: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CD69C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800CD6A0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800CD6A4: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800CD6A8: bne         $at, $zero, L_800CD674
    if (ctx->r1 != 0) {
        // 0x800CD6AC: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_800CD674;
    }
    // 0x800CD6AC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800CD6B0:
    // 0x800CD6B0: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x800CD6B4: jr          $ra
    // 0x800CD6B8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CD6B8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80031874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031874: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031878: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x8003187C: nop

    // 0x80031880: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80031884: bne         $at, $zero, L_80031894
    if (ctx->r1 != 0) {
        // 0x80031888: nop
    
            goto L_80031894;
    }
    // 0x80031888: nop

    // 0x8003188C: jr          $ra
    // 0x80031890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80031890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031894:
    // 0x80031894: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031898: lh          $t7, 0x664($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X664);
    // 0x8003189C: nop

    // 0x800318A0: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x800318A4: bne         $at, $zero, L_800318B4
    if (ctx->r1 != 0) {
        // 0x800318A8: nop
    
            goto L_800318B4;
    }
    // 0x800318A8: nop

    // 0x800318AC: jr          $ra
    // 0x800318B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800318B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800318B4:
    // 0x800318B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800318B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800318BC: sh          $t8, 0x2524($at)
    MEM_H(0X2524, ctx->r1) = ctx->r24;
    // 0x800318C0: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x800318C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800318C8: sh          $t9, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r25;
    // 0x800318CC: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x800318D0: lbu         $t0, -0x6A00($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6A00);
    // 0x800318D4: nop

    // 0x800318D8: beq         $t0, $zero, L_800318EC
    if (ctx->r8 == 0) {
        // 0x800318DC: nop
    
            goto L_800318EC;
    }
    // 0x800318DC: nop

    // 0x800318E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800318E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800318E8: swc1        $f4, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f4.u32l;
L_800318EC:
    // 0x800318EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800318F0: sh          $zero, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = 0;
    // 0x800318F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800318F8: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x800318FC: jr          $ra
    // 0x80031900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80015D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015D74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80015D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015D7C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80015D80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80015D84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80015D88: jal         0x8000DA44
    // 0x80015D8C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80015D8C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80015D90: bgez        $v0, L_80015DA0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80015D94: nop
    
            goto L_80015DA0;
    }
    // 0x80015D94: nop

    // 0x80015D98: b           L_80015E38
    // 0x80015D9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015E38;
    // 0x80015D9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015DA0:
    // 0x80015DA0: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80015DA4: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80015DA8: nop

    // 0x80015DAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80015DB0: nop

    // 0x80015DB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015DB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80015DBC: nop

    // 0x80015DC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80015DC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015DC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015DCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80015DD0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80015DD4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80015DD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80015DDC: sw          $t9, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r25;
    // 0x80015DE0: nop

    // 0x80015DE4: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80015DE8: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80015DEC: nop

    // 0x80015DF0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80015DF4: nop

    // 0x80015DF8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80015DFC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80015E00: nop

    // 0x80015E04: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80015E08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015E0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015E10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80015E14: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80015E18: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80015E1C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80015E20: sw          $t3, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r11;
    // 0x80015E24: nop

    // 0x80015E28: b           L_80015E38
    // 0x80015E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80015E38;
    // 0x80015E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015E30: b           L_80015E38
    // 0x80015E34: nop

        goto L_80015E38;
    // 0x80015E34: nop

L_80015E38:
    // 0x80015E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015E3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80015E40: jr          $ra
    // 0x80015E44: nop

    return;
    // 0x80015E44: nop

;}
RECOMP_FUNC void func_800291B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800291B4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800291B8: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x800291BC: nop

    // 0x800291C0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800291C4: sw          $a0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r4;
    // 0x800291C8: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    // 0x800291CC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800291D0: nop

    // 0x800291D4: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x800291D8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800291DC: nop

    // 0x800291E0: beq         $t8, $zero, L_800291F4
    if (ctx->r24 == 0) {
        // 0x800291E4: nop
    
            goto L_800291F4;
    }
    // 0x800291E4: nop

    // 0x800291E8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800291EC: nop

    // 0x800291F0: sw          $a0, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r4;
L_800291F4:
    // 0x800291F4: b           L_800291FC
    // 0x800291F8: nop

        goto L_800291FC;
    // 0x800291F8: nop

L_800291FC:
    // 0x800291FC: jr          $ra
    // 0x80029200: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80029200: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void alSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D66D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D66DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D66E0: ldc1        $f6, 0x610($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X610);
    // 0x800D66E4: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x800D66E8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800D66EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D66F0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800D66F4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D66F8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800D66FC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D6700: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800D6704: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800D6708: bgezl       $a2, L_800D6724
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800D670C: div.d       $f8, $f18, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
            goto L_800D6724;
    }
    goto skip_0;
    // 0x800D670C: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    skip_0:
    // 0x800D6710: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800D6714: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800D6718: nop

    // 0x800D671C: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
    // 0x800D6720: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
L_800D6724:
    // 0x800D6724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D6728: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800D672C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D6730: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800D6734: nop

    // 0x800D6738: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800D673C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800D6740: nop

    // 0x800D6744: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800D6748: beql        $v0, $zero, L_800D67A4
    if (ctx->r2 == 0) {
        // 0x800D674C: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800D67A4;
    }
    goto skip_1;
    // 0x800D674C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x800D6750: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D6754: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D6758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D675C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D6760: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800D6764: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800D6768: nop

    // 0x800D676C: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800D6770: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800D6774: nop

    // 0x800D6778: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800D677C: bnel        $v0, $zero, L_800D6798
    if (ctx->r2 != 0) {
        // 0x800D6780: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_800D6798;
    }
    goto skip_2;
    // 0x800D6780: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_2:
    // 0x800D6784: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800D6788: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D678C: jr          $ra
    // 0x800D6790: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800D6790: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800D6794: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
L_800D6798:
    // 0x800D6798: jr          $ra
    // 0x800D679C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800D679C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800D67A0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800D67A4:
    // 0x800D67A4: nop

    // 0x800D67A8: bltzl       $v0, L_800D6798
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D67AC: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_800D6798;
    }
    goto skip_3;
    // 0x800D67AC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_3:
    // 0x800D67B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D67B4: jr          $ra
    // 0x800D67B8: nop

    return;
    // 0x800D67B8: nop

;}
RECOMP_FUNC void func_80028DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028DF8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80028DFC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80028E00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80028E04: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80028E08: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80028E0C: nop

    // 0x80028E10: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80028E14: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80028E18: sb          $t7, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r15;
    // 0x80028E1C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80028E20: nop

    // 0x80028E24: beq         $t8, $zero, L_80028F28
    if (ctx->r24 == 0) {
        // 0x80028E28: nop
    
            goto L_80028F28;
    }
    // 0x80028E28: nop

L_80028E2C:
    // 0x80028E2C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80028E30: nop

    // 0x80028E34: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80028E38: nop

    // 0x80028E3C: bne         $t0, $a3, L_80028E58
    if (ctx->r8 != ctx->r7) {
        // 0x80028E40: nop
    
            goto L_80028E58;
    }
    // 0x80028E40: nop

    // 0x80028E44: lh          $t1, 0x4($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X4);
    // 0x80028E48: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x80028E4C: nop

    // 0x80028E50: beq         $t1, $t2, L_80028E60
    if (ctx->r9 == ctx->r10) {
        // 0x80028E54: nop
    
            goto L_80028E60;
    }
    // 0x80028E54: nop

L_80028E58:
    // 0x80028E58: b           L_80028F28
    // 0x80028E5C: nop

        goto L_80028F28;
    // 0x80028E5C: nop

L_80028E60:
    // 0x80028E60: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80028E64: lbu         $t5, 0x5($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X5);
    // 0x80028E68: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80028E6C: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x80028E70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028E74: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x80028E78: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80028E7C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80028E80: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80028E84: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028E88: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80028E8C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028E90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028E94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028E98: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80028E9C: nop

    // 0x80028EA0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028EA4: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80028EA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028EAC: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80028EB0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80028EB4: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x80028EB8: bne         $at, $zero, L_80028ECC
    if (ctx->r1 != 0) {
        // 0x80028EBC: sh          $t1, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r9;
            goto L_80028ECC;
    }
    // 0x80028EBC: sh          $t1, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r9;
    // 0x80028EC0: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x80028EC4: b           L_80028EE8
    // 0x80028EC8: sh          $t4, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r12;
        goto L_80028EE8;
    // 0x80028EC8: sh          $t4, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r12;
L_80028ECC:
    // 0x80028ECC: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x80028ED0: nop

    // 0x80028ED4: slti        $at, $t5, -0x7F
    ctx->r1 = SIGNED(ctx->r13) < -0X7F ? 1 : 0;
    // 0x80028ED8: beq         $at, $zero, L_80028EE8
    if (ctx->r1 == 0) {
        // 0x80028EDC: nop
    
            goto L_80028EE8;
    }
    // 0x80028EDC: nop

    // 0x80028EE0: addiu       $t6, $zero, -0x7F
    ctx->r14 = ADD32(0, -0X7F);
    // 0x80028EE4: sh          $t6, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r14;
L_80028EE8:
    // 0x80028EE8: addu        $t8, $a0, $a1
    ctx->r24 = ADD32(ctx->r4, ctx->r5);
    // 0x80028EEC: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x80028EF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028EF4: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x80028EF8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80028EFC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80028F00: sb          $zero, 0x5($sp)
    MEM_B(0X5, ctx->r29) = 0;
    // 0x80028F04: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80028F08: nop

    // 0x80028F0C: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x80028F10: nop

    // 0x80028F14: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x80028F18: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80028F1C: nop

    // 0x80028F20: bne         $t2, $zero, L_80028E2C
    if (ctx->r10 != 0) {
        // 0x80028F24: nop
    
            goto L_80028E2C;
    }
    // 0x80028F24: nop

L_80028F28:
    // 0x80028F28: lbu         $t3, 0x5($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5);
    // 0x80028F2C: nop

    // 0x80028F30: beq         $t3, $zero, L_80028F50
    if (ctx->r11 == 0) {
        // 0x80028F34: nop
    
            goto L_80028F50;
    }
    // 0x80028F34: nop

    // 0x80028F38: addu        $t5, $a0, $a1
    ctx->r13 = ADD32(ctx->r4, ctx->r5);
    // 0x80028F3C: lbu         $t4, 0x5($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X5);
    // 0x80028F40: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028F44: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80028F48: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80028F4C: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
L_80028F50:
    // 0x80028F50: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80028F54: nop

    // 0x80028F58: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80028F5C: b           L_80028F6C
    // 0x80028F60: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80028F6C;
    // 0x80028F60: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80028F64: b           L_80028F6C
    // 0x80028F68: nop

        goto L_80028F6C;
    // 0x80028F68: nop

L_80028F6C:
    // 0x80028F6C: jr          $ra
    // 0x80028F70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80028F70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
