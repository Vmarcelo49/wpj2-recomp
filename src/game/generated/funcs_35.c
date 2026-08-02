#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80063954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063954: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063958: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006395C: nop

    // 0x80063960: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80063964: nop

    // 0x80063968: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006396C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063970: jr          $ra
    // 0x80063974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063978: jr          $ra
    // 0x8006397C: nop

    return;
    // 0x8006397C: nop

    // 0x80063980: jr          $ra
    // 0x80063984: nop

    return;
    // 0x80063984: nop

;}
RECOMP_FUNC void func_800B8104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8104: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B8108: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B810C:
    // 0x800B810C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B8110: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B8114: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B8118: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B811C: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x800B8120: nop

    // 0x800B8124: beq         $t8, $zero, L_800B8184
    if (ctx->r24 == 0) {
        // 0x800B8128: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_800B8184;
    }
    // 0x800B8128: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800B812C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800B8130: nop

    // 0x800B8134: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x800B8138: nop

    // 0x800B813C: beq         $t0, $zero, L_800B8184
    if (ctx->r8 == 0) {
        // 0x800B8140: sw          $t0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r8;
            goto L_800B8184;
    }
    // 0x800B8140: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x800B8144: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800B8148: nop

    // 0x800B814C: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x800B8150: nop

    // 0x800B8154: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x800B8158: bne         $t3, $zero, L_800B817C
    if (ctx->r11 != 0) {
        // 0x800B815C: nop
    
            goto L_800B817C;
    }
    // 0x800B815C: nop

    // 0x800B8160: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800B8164: nop

    // 0x800B8168: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800B816C: nop

    // 0x800B8170: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800B8174: beq         $t6, $zero, L_800B8184
    if (ctx->r14 == 0) {
        // 0x800B8178: nop
    
            goto L_800B8184;
    }
    // 0x800B8178: nop

L_800B817C:
    // 0x800B817C: b           L_800B81AC
    // 0x800B8180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B81AC;
    // 0x800B8180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B8184:
    // 0x800B8184: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800B8188: nop

    // 0x800B818C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B8190: slti        $at, $t8, 0x14
    ctx->r1 = SIGNED(ctx->r24) < 0X14 ? 1 : 0;
    // 0x800B8194: bne         $at, $zero, L_800B810C
    if (ctx->r1 != 0) {
        // 0x800B8198: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_800B810C;
    }
    // 0x800B8198: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800B819C: b           L_800B81AC
    // 0x800B81A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B81AC;
    // 0x800B81A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B81A4: b           L_800B81AC
    // 0x800B81A8: nop

        goto L_800B81AC;
    // 0x800B81A8: nop

L_800B81AC:
    // 0x800B81AC: jr          $ra
    // 0x800B81B0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B81B0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
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
RECOMP_FUNC void func_80065054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006505C: jal         0x80061488
    // 0x80065060: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065060: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    after_0:
    // 0x80065064: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80065068: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006506C: b           L_8006507C
    // 0x80065070: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006507C;
    // 0x80065070: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065074: b           L_8006507C
    // 0x80065078: nop

        goto L_8006507C;
    // 0x80065078: nop

L_8006507C:
    // 0x8006507C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065084: jr          $ra
    // 0x80065088: nop

    return;
    // 0x80065088: nop

;}
RECOMP_FUNC void Scheduler_IsTaskReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097BDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80097BE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097BE4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80097BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80097BEC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80097BF0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097BF4: nop

    // 0x80097BF8: beq         $t6, $zero, L_80097C3C
    if (ctx->r14 == 0) {
        // 0x80097BFC: nop
    
            goto L_80097C3C;
    }
    // 0x80097BFC: nop

    // 0x80097C00: jal         0x800C4160
    // 0x80097C04: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80097C04: nop

    after_0:
    // 0x80097C08: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80097C0C: jal         0x800C4E00
    // 0x80097C10: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80097C10: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_1:
    // 0x80097C14: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80097C18: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097C1C: nop

    // 0x80097C20: beq         $t7, $s0, L_80097C30
    if (ctx->r15 == ctx->r16) {
        // 0x80097C24: nop
    
            goto L_80097C30;
    }
    // 0x80097C24: nop

    // 0x80097C28: b           L_80097C4C
    // 0x80097C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097C4C;
    // 0x80097C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097C30:
    // 0x80097C30: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80097C34: b           L_80097C4C
    // 0x80097C38: nop

        goto L_80097C4C;
    // 0x80097C38: nop

L_80097C3C:
    // 0x80097C3C: b           L_80097C4C
    // 0x80097C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097C4C;
    // 0x80097C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097C44: b           L_80097C4C
    // 0x80097C48: nop

        goto L_80097C4C;
    // 0x80097C48: nop

L_80097C4C:
    // 0x80097C4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80097C50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097C54: jr          $ra
    // 0x80097C58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80097C58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80074CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074CC0: jal         0x80061348
    // 0x80074CC4: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074CC4: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x80074CC8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074CCC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074CD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074CD4: beq         $v0, $zero, L_80074D28
    if (ctx->r2 == 0) {
        // 0x80074CD8: nop
    
            goto L_80074D28;
    }
    // 0x80074CD8: nop

    // 0x80074CDC: jal         0x80061348
    // 0x80074CE0: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074CE0: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074CE4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074CE8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074CEC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074CF0: beq         $v0, $zero, L_80074D28
    if (ctx->r2 == 0) {
        // 0x80074CF4: nop
    
            goto L_80074D28;
    }
    // 0x80074CF4: nop

    // 0x80074CF8: jal         0x80061348
    // 0x80074CFC: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074CFC: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074D00: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074D04: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074D08: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074D0C: beq         $v0, $zero, L_80074D28
    if (ctx->r2 == 0) {
        // 0x80074D10: nop
    
            goto L_80074D28;
    }
    // 0x80074D10: nop

    // 0x80074D14: jal         0x80061348
    // 0x80074D18: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074D18: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074D1C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074D20: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074D24: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074D28:
    // 0x80074D28: b           L_80074D38
    // 0x80074D2C: nop

        goto L_80074D38;
    // 0x80074D2C: nop

    // 0x80074D30: b           L_80074D38
    // 0x80074D34: nop

        goto L_80074D38;
    // 0x80074D34: nop

L_80074D38:
    // 0x80074D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074D40: jr          $ra
    // 0x80074D44: nop

    return;
    // 0x80074D44: nop

;}
RECOMP_FUNC void func_80066850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066858: jal         0x80061348
    // 0x8006685C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006685C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x80066860: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066864: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066868: bne         $v0, $zero, L_80066880
    if (ctx->r2 != 0) {
        // 0x8006686C: nop
    
            goto L_80066880;
    }
    // 0x8006686C: nop

    // 0x80066870: jal         0x80061348
    // 0x80066874: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066874: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x80066878: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006687C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066880:
    // 0x80066880: b           L_80066890
    // 0x80066884: nop

        goto L_80066890;
    // 0x80066884: nop

    // 0x80066888: b           L_80066890
    // 0x8006688C: nop

        goto L_80066890;
    // 0x8006688C: nop

L_80066890:
    // 0x80066890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066898: jr          $ra
    // 0x8006689C: nop

    return;
    // 0x8006689C: nop

;}
RECOMP_FUNC void func_800111E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800111E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800111EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800111F0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800111F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800111F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800111FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80011200: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80011204: jal         0x8000DA44
    // 0x80011208: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80011208: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8001120C: bgez        $v0, L_8001121C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011210: nop
    
            goto L_8001121C;
    }
    // 0x80011210: nop

    // 0x80011214: b           L_80011728
    // 0x80011218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011728;
    // 0x80011218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001121C:
    // 0x8001121C: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80011220: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80011224: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80011228: nop

    // 0x8001122C: sh          $t7, 0x208($t8)
    MEM_H(0X208, ctx->r24) = ctx->r15;
    // 0x80011230: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80011234: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80011238: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8001123C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80011240: nop

    // 0x80011244: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011248: swc1        $f6, 0x1B0($t1)
    MEM_W(0X1B0, ctx->r9) = ctx->f6.u32l;
    // 0x8001124C: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x80011250: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x80011254: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80011258: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8001125C: nop

    // 0x80011260: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011264: swc1        $f10, 0x1B4($t4)
    MEM_W(0X1B4, ctx->r12) = ctx->f10.u32l;
    // 0x80011268: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x8001126C: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x80011270: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80011274: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80011278: nop

    // 0x8001127C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80011280: swc1        $f18, 0x1B8($t7)
    MEM_W(0X1B8, ctx->r15) = ctx->f18.u32l;
    // 0x80011284: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80011288: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x8001128C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80011290: nop

    // 0x80011294: sh          $t9, 0x20A($t0)
    MEM_H(0X20A, ctx->r8) = ctx->r25;
    // 0x80011298: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8001129C: nop

    // 0x800112A0: lw          $t2, 0x20C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20C);
    // 0x800112A4: nop

    // 0x800112A8: bne         $t2, $zero, L_800112C4
    if (ctx->r10 != 0) {
        // 0x800112AC: nop
    
            goto L_800112C4;
    }
    // 0x800112AC: nop

    // 0x800112B0: jal         0x8000D164
    // 0x800112B4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    TempHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x800112B4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x800112B8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800112BC: nop

    // 0x800112C0: sw          $v0, 0x20C($t3)
    MEM_W(0X20C, ctx->r11) = ctx->r2;
L_800112C4:
    // 0x800112C4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800112C8: nop

    // 0x800112CC: lw          $t5, 0x20C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20C);
    // 0x800112D0: nop

    // 0x800112D4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800112D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800112DC: jal         0x8000E3D4
    // 0x800112E0: nop

    func_8000E3D4(rdram, ctx);
        goto after_2;
    // 0x800112E0: nop

    after_2:
    // 0x800112E4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800112E8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800112EC: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800112F0: nop

    // 0x800112F4: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800112F8: bne         $at, $zero, L_80011424
    if (ctx->r1 != 0) {
        // 0x800112FC: nop
    
            goto L_80011424;
    }
    // 0x800112FC: nop

    // 0x80011300: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80011304: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011308: beq         $at, $zero, L_80011424
    if (ctx->r1 == 0) {
        // 0x8001130C: nop
    
            goto L_80011424;
    }
    // 0x8001130C: nop

    // 0x80011310: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80011314: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x80011318: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8001131C: nop

    // 0x80011320: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80011324: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80011328: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001132C: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    // 0x80011330: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80011334: nop

    // 0x80011338: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x8001133C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80011340: nop

    // 0x80011344: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x80011348: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001134C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80011350: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80011354: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80011358: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001135C: lw          $t8, 0x1AC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1AC);
    // 0x80011360: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80011364: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80011368: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001136C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80011370: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80011374: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80011378: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8001137C: lui         $at, 0xFF50
    ctx->r1 = S32(0XFF50 << 16);
    // 0x80011380: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x80011384: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x80011388: sw          $s0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r16;
    // 0x8001138C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80011390: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80011394: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80011398: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x8001139C: nop

    // 0x800113A0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800113A4: bne         $t4, $zero, L_800113B4
    if (ctx->r12 != 0) {
        // 0x800113A8: nop
    
            goto L_800113B4;
    }
    // 0x800113A8: nop

    // 0x800113AC: b           L_80011728
    // 0x800113B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011728;
    // 0x800113B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800113B4:
    // 0x800113B4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800113B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800113BC: lwc1        $f4, 0x1B0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1B0);
    // 0x800113C0: nop

    // 0x800113C4: swc1        $f4, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f4.u32l;
    // 0x800113C8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800113CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800113D0: lwc1        $f6, 0x1B4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1B4);
    // 0x800113D4: nop

    // 0x800113D8: swc1        $f6, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f6.u32l;
    // 0x800113DC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800113E0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800113E4: lwc1        $f8, 0x1B8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1B8);
    // 0x800113E8: nop

    // 0x800113EC: swc1        $f8, 0xD4($t0)
    MEM_W(0XD4, ctx->r8) = ctx->f8.u32l;
    // 0x800113F0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800113F4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800113F8: lhu         $t2, 0x20A($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X20A);
    // 0x800113FC: nop

    // 0x80011400: beq         $t2, $at, L_8001141C
    if (ctx->r10 == ctx->r1) {
        // 0x80011404: nop
    
            goto L_8001141C;
    }
    // 0x80011404: nop

    // 0x80011408: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8001140C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80011410: lhu         $t4, 0x20A($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X20A);
    // 0x80011414: nop

    // 0x80011418: sh          $t4, 0x124($t5)
    MEM_H(0X124, ctx->r13) = ctx->r12;
L_8001141C:
    // 0x8001141C: b           L_80011700
    // 0x80011420: nop

        goto L_80011700;
    // 0x80011420: nop

L_80011424:
    // 0x80011424: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80011428: nop

    // 0x8001142C: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80011430: nop

    // 0x80011434: slti        $at, $t7, 0x4000
    ctx->r1 = SIGNED(ctx->r15) < 0X4000 ? 1 : 0;
    // 0x80011438: bne         $at, $zero, L_800114A8
    if (ctx->r1 != 0) {
        // 0x8001143C: nop
    
            goto L_800114A8;
    }
    // 0x8001143C: nop

    // 0x80011440: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80011444: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011448: beq         $at, $zero, L_800114A8
    if (ctx->r1 == 0) {
        // 0x8001144C: nop
    
            goto L_800114A8;
    }
    // 0x8001144C: nop

    // 0x80011450: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80011454: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x80011458: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8001145C: nop

    // 0x80011460: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80011464: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80011468: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001146C: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    // 0x80011470: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80011474: nop

    // 0x80011478: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x8001147C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80011480: nop

    // 0x80011484: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x80011488: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001148C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80011490: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80011494: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80011498: jal         0x80014C70
    // 0x8001149C: nop

    func_80014C70(rdram, ctx);
        goto after_3;
    // 0x8001149C: nop

    after_3:
    // 0x800114A0: b           L_80011700
    // 0x800114A4: nop

        goto L_80011700;
    // 0x800114A4: nop

L_800114A8:
    // 0x800114A8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800114AC: nop

    // 0x800114B0: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x800114B4: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x800114B8: lhu         $s1, 0x2($t8)
    ctx->r17 = MEM_HU(ctx->r24, 0X2);
    // 0x800114BC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800114C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800114C4: beq         $s1, $at, L_800116D0
    if (ctx->r17 == ctx->r1) {
        // 0x800114C8: sh          $s1, 0x2($t9)
        MEM_H(0X2, ctx->r25) = ctx->r17;
            goto L_800116D0;
    }
    // 0x800114C8: sh          $s1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r17;
    // 0x800114CC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800114D0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800114D4: lw          $t1, 0x1AC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1AC);
    // 0x800114D8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800114DC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800114E0: lbu         $t2, -0x6230($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6230);
    // 0x800114E4: nop

    // 0x800114E8: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x800114EC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800114F0: nop

    // 0x800114F4: lhu         $a0, 0x6($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X6);
    // 0x800114F8: nop

    // 0x800114FC: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80011500: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80011504: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80011508: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8001150C: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80011510: jal         0x8000D164
    // 0x80011514: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    TempHeap_Alloc(rdram, ctx);
        goto after_4;
    // 0x80011514: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_4:
    // 0x80011518: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001151C: nop

    // 0x80011520: sw          $v0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r2;
    // 0x80011524: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80011528: nop

    // 0x8001152C: lhu         $a0, 0x6($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X6);
    // 0x80011530: nop

    // 0x80011534: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x80011538: jal         0x8000D164
    // 0x8001153C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    TempHeap_Alloc(rdram, ctx);
        goto after_5;
    // 0x8001153C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_5:
    // 0x80011540: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80011544: nop

    // 0x80011548: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x8001154C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80011550: nop

    // 0x80011554: lhu         $a2, 0x6($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X6);
    // 0x80011558: addiu       $a0, $t0, 0xC
    ctx->r4 = ADD32(ctx->r8, 0XC);
    // 0x8001155C: jal         0x800B1B3C
    // 0x80011560: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    func_800B1B3C(rdram, ctx);
        goto after_6;
    // 0x80011560: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    after_6:
    // 0x80011564: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80011568: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8001156C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80011570: nop

    // 0x80011574: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80011578: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x8001157C: nop

    // 0x80011580: blez        $t3, L_80011684
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80011584: nop
    
            goto L_80011684;
    }
    // 0x80011584: nop

L_80011588:
    // 0x80011588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001158C: jal         0x80099E2C
    // 0x80011590: nop

    func_80099E2C(rdram, ctx);
        goto after_7;
    // 0x80011590: nop

    after_7:
    // 0x80011594: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80011598: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001159C: lwc1        $f10, 0x1B0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X1B0);
    // 0x800115A0: nop

    // 0x800115A4: swc1        $f10, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f10.u32l;
    // 0x800115A8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800115AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800115B0: lwc1        $f18, -0x71C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x800115B4: lwc1        $f16, 0x1B4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X1B4);
    // 0x800115B8: lwc1        $f8, 0x1B8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1B8);
    // 0x800115BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800115C0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800115C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800115C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800115CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800115D0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800115D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800115D8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800115DC: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x800115E0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800115E4: swc1        $f8, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f8.u32l;
    // 0x800115E8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800115EC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800115F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800115F4: lwc1        $f16, 0x1B8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1B8);
    // 0x800115F8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800115FC: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80011600: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80011604: nop

    // 0x80011608: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001160C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011614: nop

    // 0x80011618: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001161C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80011620: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80011624: sw          $t0, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r8;
    // 0x80011628: nop

    // 0x8001162C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80011630: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80011634: nop

    // 0x80011638: swc1        $f4, 0xD4($t1)
    MEM_W(0XD4, ctx->r9) = ctx->f4.u32l;
    // 0x8001163C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80011640: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80011644: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x80011648: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001164C: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80011650: sh          $t5, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r13;
    // 0x80011654: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80011658: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001165C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80011660: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80011664: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80011668: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001166C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80011670: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x80011674: nop

    // 0x80011678: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001167C: bne         $at, $zero, L_80011588
    if (ctx->r1 != 0) {
        // 0x80011680: nop
    
            goto L_80011588;
    }
    // 0x80011680: nop

L_80011684:
    // 0x80011684: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80011688: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001168C: lhu         $t4, 0x20A($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X20A);
    // 0x80011690: nop

    // 0x80011694: bne         $t4, $at, L_800116B4
    if (ctx->r12 != ctx->r1) {
        // 0x80011698: nop
    
            goto L_800116B4;
    }
    // 0x80011698: nop

    // 0x8001169C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800116A0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800116A4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800116A8: lh          $t6, 0x42($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X42);
    // 0x800116AC: b           L_800116C8
    // 0x800116B0: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
        goto L_800116C8;
    // 0x800116B0: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
L_800116B4:
    // 0x800116B4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800116B8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800116BC: lhu         $t0, 0x20A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X20A);
    // 0x800116C0: nop

    // 0x800116C4: sh          $t0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r8;
L_800116C8:
    // 0x800116C8: b           L_80011700
    // 0x800116CC: nop

        goto L_80011700;
    // 0x800116CC: nop

L_800116D0:
    // 0x800116D0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800116D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800116D8: sh          $t8, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r24;
    // 0x800116DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800116E0: nop

    // 0x800116E4: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x800116E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800116EC: nop

    // 0x800116F0: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x800116F4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800116F8: nop

    // 0x800116FC: sw          $zero, 0x10($t5)
    MEM_W(0X10, ctx->r13) = 0;
L_80011700:
    // 0x80011700: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80011704: nop

    // 0x80011708: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x8001170C: nop

    // 0x80011710: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x80011714: sw          $t9, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = ctx->r25;
    // 0x80011718: b           L_80011728
    // 0x8001171C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011728;
    // 0x8001171C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011720: b           L_80011728
    // 0x80011724: nop

        goto L_80011728;
    // 0x80011724: nop

L_80011728:
    // 0x80011728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001172C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80011730: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80011734: jr          $ra
    // 0x80011738: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80011738: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80089170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089170: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80089174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089178: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8008917C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80089180: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089184: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x80089188: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008918C: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x80089190: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80089194: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80089198: nop

    // 0x8008919C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800891A0: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800891A4: nop

    // 0x800891A8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800891AC: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x800891B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800891B4: nop

    // 0x800891B8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800891BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800891C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800891C4: nop

    // 0x800891C8: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800891CC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800891D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800891D4: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x800891D8: nop

    // 0x800891DC: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800891E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800891E4: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x800891E8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800891EC: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x800891F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800891F4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800891F8: nop

    // 0x800891FC: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80089200: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80089204: nop

    // 0x80089208: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008920C: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80089210: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80089214: nop

    // 0x80089218: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8008921C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80089220: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80089224: nop

    // 0x80089228: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x8008922C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80089230: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80089234: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x80089238: nop

    // 0x8008923C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089240: addiu       $t4, $t4, 0x4720
    ctx->r12 = ADD32(ctx->r12, 0X4720);
    // 0x80089244: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80089248: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008924C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089250: beq         $t5, $at, L_80089400
    if (ctx->r13 == ctx->r1) {
        // 0x80089254: nop
    
            goto L_80089400;
    }
    // 0x80089254: nop

L_80089258:
    // 0x80089258: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8008925C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80089260: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80089264: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80089268: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8008926C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089270: addiu       $t8, $t8, 0x4720
    ctx->r24 = ADD32(ctx->r24, 0X4720);
    // 0x80089274: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80089278: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8008927C: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80089280: nop

    // 0x80089284: bne         $t0, $t2, L_800893D4
    if (ctx->r8 != ctx->r10) {
        // 0x80089288: nop
    
            goto L_800893D4;
    }
    // 0x80089288: nop

    // 0x8008928C: lh          $t3, 0xA($t9)
    ctx->r11 = MEM_H(ctx->r25, 0XA);
    // 0x80089290: nop

    // 0x80089294: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80089298: beq         $t4, $zero, L_800893D4
    if (ctx->r12 == 0) {
        // 0x8008929C: nop
    
            goto L_800893D4;
    }
    // 0x8008929C: nop

    // 0x800892A0: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800892A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800892A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800892AC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800892B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800892B4: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800892B8: lh          $a2, 0x4726($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X4726);
    // 0x800892BC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800892C0: jal         0x8008B388
    // 0x800892C4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8008B388(rdram, ctx);
        goto after_0;
    // 0x800892C4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800892C8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800892CC: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800892D0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800892D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800892D8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800892DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800892E0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800892E4: lh          $t1, 0x4726($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4726);
    // 0x800892E8: nop

    // 0x800892EC: slti        $at, $t1, 0x4000
    ctx->r1 = SIGNED(ctx->r9) < 0X4000 ? 1 : 0;
    // 0x800892F0: bne         $at, $zero, L_80089368
    if (ctx->r1 != 0) {
        // 0x800892F4: nop
    
            goto L_80089368;
    }
    // 0x800892F4: nop

    // 0x800892F8: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800892FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80089300: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80089304: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80089308: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008930C: addiu       $t9, $t9, 0x4720
    ctx->r25 = ADD32(ctx->r25, 0X4720);
    // 0x80089310: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x80089314: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80089318: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x8008931C: lh          $t5, 0x2E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2E);
    // 0x80089320: lh          $t8, 0x4($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X4);
    // 0x80089324: lh          $t7, 0x2C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2C);
    // 0x80089328: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8008932C: lh          $a1, 0x6($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X6);
    // 0x80089330: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80089334: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80089338: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8008933C: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
    // 0x80089340: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80089344: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089348: lh          $t4, 0xA($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XA);
    // 0x8008934C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80089350: addiu       $a3, $t1, -0xA
    ctx->r7 = ADD32(ctx->r9, -0XA);
    // 0x80089354: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80089358: jal         0x800897A8
    // 0x8008935C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_800897A8(rdram, ctx);
        goto after_1;
    // 0x8008935C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_1:
    // 0x80089360: b           L_800893D4
    // 0x80089364: nop

        goto L_800893D4;
    // 0x80089364: nop

L_80089368:
    // 0x80089368: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8008936C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80089370: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80089374: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80089378: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008937C: addiu       $t8, $t8, 0x4720
    ctx->r24 = ADD32(ctx->r24, 0X4720);
    // 0x80089380: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80089384: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80089388: lh          $t6, 0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X2);
    // 0x8008938C: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x80089390: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80089394: lh          $t3, 0x4($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X4);
    // 0x80089398: lh          $t1, 0x2C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2C);
    // 0x8008939C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800893A0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800893A4: lh          $a1, 0x6($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X6);
    // 0x800893A8: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x800893AC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800893B0: subu        $t4, $t1, $t3
    ctx->r12 = SUB32(ctx->r9, ctx->r11);
    // 0x800893B4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800893B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800893BC: lh          $t6, 0xA($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XA);
    // 0x800893C0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800893C4: addiu       $a3, $t4, -0xC
    ctx->r7 = ADD32(ctx->r12, -0XC);
    // 0x800893C8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800893CC: jal         0x800897A8
    // 0x800893D0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800897A8(rdram, ctx);
        goto after_2;
    // 0x800893D0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_2:
L_800893D4:
    // 0x800893D4: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800893D8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800893DC: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800893E0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800893E4: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800893E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800893EC: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800893F0: lh          $t5, 0x4720($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X4720);
    // 0x800893F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800893F8: bne         $t5, $at, L_80089258
    if (ctx->r13 != ctx->r1) {
        // 0x800893FC: sw          $t1, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r9;
            goto L_80089258;
    }
    // 0x800893FC: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
L_80089400:
    // 0x80089400: b           L_80089408
    // 0x80089404: nop

        goto L_80089408;
    // 0x80089404: nop

L_80089408:
    // 0x80089408: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008940C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80089410: jr          $ra
    // 0x80089414: nop

    return;
    // 0x80089414: nop

;}
RECOMP_FUNC void ContPak_SetOpenFileParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE880: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE884: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE888: nop

    // 0x800AE88C: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AE890: beq         $t7, $zero, L_800AE8A0
    if (ctx->r15 == 0) {
        // 0x800AE894: nop
    
            goto L_800AE8A0;
    }
    // 0x800AE894: nop

    // 0x800AE898: jr          $ra
    // 0x800AE89C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE89C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE8A0:
    // 0x800AE8A0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE8A4: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE8A8: nop

    // 0x800AE8AC: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AE8B0: beq         $t9, $zero, L_800AE8C0
    if (ctx->r25 == 0) {
        // 0x800AE8B4: nop
    
            goto L_800AE8C0;
    }
    // 0x800AE8B4: nop

    // 0x800AE8B8: jr          $ra
    // 0x800AE8BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE8BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE8C0:
    // 0x800AE8C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8C4: sw          $a0, 0x1654($at)
    MEM_W(0X1654, ctx->r1) = ctx->r4;
    // 0x800AE8C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8CC: sw          $a1, 0x1660($at)
    MEM_W(0X1660, ctx->r1) = ctx->r5;
    // 0x800AE8D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8D4: sw          $a2, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r6;
    // 0x800AE8D8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE8DC: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AE8E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8E4: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x800AE8E8: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AE8EC: jr          $ra
    // 0x800AE8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE8F4: jr          $ra
    // 0x800AE8F8: nop

    return;
    // 0x800AE8F8: nop

    // 0x800AE8FC: jr          $ra
    // 0x800AE900: nop

    return;
    // 0x800AE900: nop

;}
RECOMP_FUNC void func_80031E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031E3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031E44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031E48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80031E4C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80031E50: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80031E54: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80031E58: nop

    // 0x80031E5C: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80031E60: nop

    // 0x80031E64: bgez        $t7, L_80031FDC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80031E68: nop
    
            goto L_80031FDC;
    }
    // 0x80031E68: nop

    // 0x80031E6C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80031E70: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80031E74: nop

    // 0x80031E78: sw          $t8, 0x1AC($t9)
    MEM_W(0X1AC, ctx->r25) = ctx->r24;
    // 0x80031E7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80031E80: jal         0x800BB448
    // 0x80031E84: nop

    func_800BB448(rdram, ctx);
        goto after_0;
    // 0x80031E84: nop

    after_0:
    // 0x80031E88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80031E8C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80031E90: nop

    // 0x80031E94: beq         $t0, $zero, L_80031F9C
    if (ctx->r8 == 0) {
        // 0x80031E98: nop
    
            goto L_80031F9C;
    }
    // 0x80031E98: nop

    // 0x80031E9C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80031EA0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80031EA4: lhu         $t3, 0x208($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X208);
    // 0x80031EA8: nop

    // 0x80031EAC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80031EB0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80031EB4: sw          $t1, 0x20C($t5)
    MEM_W(0X20C, ctx->r13) = ctx->r9;
    // 0x80031EB8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80031EBC: nop

    // 0x80031EC0: lhu         $t7, 0x208($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X208);
    // 0x80031EC4: nop

    // 0x80031EC8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80031ECC: sh          $t8, 0x208($t6)
    MEM_H(0X208, ctx->r14) = ctx->r24;
    // 0x80031ED0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80031ED4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80031ED8: nop

    // 0x80031EDC: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x80031EE0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80031EE4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80031EE8: nop

    // 0x80031EEC: sb          $t3, 0x1A($t2)
    MEM_B(0X1A, ctx->r10) = ctx->r11;
    // 0x80031EF0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80031EF4: jal         0x800BB4B4
    // 0x80031EF8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BB4B4(rdram, ctx);
        goto after_1;
    // 0x80031EF8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80031EFC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80031F00: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80031F04: bgez        $t4, L_80031F14
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80031F08: sra         $t1, $t4, 8
        ctx->r9 = S32(SIGNED(ctx->r12) >> 8);
            goto L_80031F14;
    }
    // 0x80031F08: sra         $t1, $t4, 8
    ctx->r9 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80031F0C: addiu       $at, $t4, 0xFF
    ctx->r1 = ADD32(ctx->r12, 0XFF);
    // 0x80031F10: sra         $t1, $at, 8
    ctx->r9 = S32(SIGNED(ctx->r1) >> 8);
L_80031F14:
    // 0x80031F14: subu        $t7, $t5, $t1
    ctx->r15 = SUB32(ctx->r13, ctx->r9);
    // 0x80031F18: bgez        $t7, L_80031F28
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80031F1C: sra         $t8, $t7, 3
        ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
            goto L_80031F28;
    }
    // 0x80031F1C: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80031F20: addiu       $at, $t7, 0x7
    ctx->r1 = ADD32(ctx->r15, 0X7);
    // 0x80031F24: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80031F28:
    // 0x80031F28: blez        $t8, L_80031F5C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80031F2C: nop
    
            goto L_80031F5C;
    }
    // 0x80031F2C: nop

    // 0x80031F30: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80031F34: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x80031F38: bgez        $t9, L_80031F48
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80031F3C: sra         $t0, $t9, 3
        ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
            goto L_80031F48;
    }
    // 0x80031F3C: sra         $t0, $t9, 3
    ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80031F40: addiu       $at, $t9, 0x7
    ctx->r1 = ADD32(ctx->r25, 0X7);
    // 0x80031F44: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_80031F48:
    // 0x80031F48: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80031F4C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80031F50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80031F54: b           L_80031F9C
    // 0x80031F58: swc1        $f6, 0x1EC($t3)
    MEM_W(0X1EC, ctx->r11) = ctx->f6.u32l;
        goto L_80031F9C;
    // 0x80031F58: swc1        $f6, 0x1EC($t3)
    MEM_W(0X1EC, ctx->r11) = ctx->f6.u32l;
L_80031F5C:
    // 0x80031F5C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80031F60: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80031F64: bgez        $t2, L_80031F74
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80031F68: sra         $t4, $t2, 8
        ctx->r12 = S32(SIGNED(ctx->r10) >> 8);
            goto L_80031F74;
    }
    // 0x80031F68: sra         $t4, $t2, 8
    ctx->r12 = S32(SIGNED(ctx->r10) >> 8);
    // 0x80031F6C: addiu       $at, $t2, 0xFF
    ctx->r1 = ADD32(ctx->r10, 0XFF);
    // 0x80031F70: sra         $t4, $at, 8
    ctx->r12 = S32(SIGNED(ctx->r1) >> 8);
L_80031F74:
    // 0x80031F74: subu        $t7, $t5, $t4
    ctx->r15 = SUB32(ctx->r13, ctx->r12);
    // 0x80031F78: bgez        $t7, L_80031F88
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80031F7C: sra         $t8, $t7, 3
        ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
            goto L_80031F88;
    }
    // 0x80031F7C: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80031F80: addiu       $at, $t7, 0x7
    ctx->r1 = ADD32(ctx->r15, 0X7);
    // 0x80031F84: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80031F88:
    // 0x80031F88: negu        $t6, $t8
    ctx->r14 = SUB32(0, ctx->r24);
    // 0x80031F8C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80031F90: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80031F94: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80031F98: swc1        $f10, 0x1EC($t1)
    MEM_W(0X1EC, ctx->r9) = ctx->f10.u32l;
L_80031F9C:
    // 0x80031F9C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80031FA0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80031FA4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80031FA8: nop

    // 0x80031FAC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80031FB0: swc1        $f18, 0x1F0($t0)
    MEM_W(0X1F0, ctx->r8) = ctx->f18.u32l;
    // 0x80031FB4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80031FB8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80031FBC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80031FC0: nop

    // 0x80031FC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80031FC8: swc1        $f6, 0x1F4($t2)
    MEM_W(0X1F4, ctx->r10) = ctx->f6.u32l;
    // 0x80031FCC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80031FD0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80031FD4: nop

    // 0x80031FD8: sw          $t5, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r13;
L_80031FDC:
    // 0x80031FDC: b           L_80031FE4
    // 0x80031FE0: nop

        goto L_80031FE4;
    // 0x80031FE0: nop

L_80031FE4:
    // 0x80031FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031FE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031FEC: jr          $ra
    // 0x80031FF0: nop

    return;
    // 0x80031FF0: nop

;}
RECOMP_FUNC void func_8006548C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006548C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065494: jal         0x8005F064
    // 0x80065498: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065498: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x8006549C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800654A0: b           L_800654B0
    // 0x800654A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800654B0;
    // 0x800654A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800654A8: b           L_800654B0
    // 0x800654AC: nop

        goto L_800654B0;
    // 0x800654AC: nop

L_800654B0:
    // 0x800654B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800654B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800654B8: jr          $ra
    // 0x800654BC: nop

    return;
    // 0x800654BC: nop

;}
RECOMP_FUNC void func_80055E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055E40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80055E44: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80055E48: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80055E4C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80055E50:
    // 0x80055E50: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055E54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80055E58: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055E5C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80055E60: addiu       $t0, $t0, -0x2AC0
    ctx->r8 = ADD32(ctx->r8, -0X2AC0);
    // 0x80055E64: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80055E68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055E6C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80055E70: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80055E74: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80055E78: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80055E7C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80055E80: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80055E84: addu        $t4, $t6, $t3
    ctx->r12 = ADD32(ctx->r14, ctx->r11);
    // 0x80055E88: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80055E8C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80055E90: nop

    // 0x80055E94: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80055E98: bne         $at, $zero, L_80055F38
    if (ctx->r1 != 0) {
        // 0x80055E9C: nop
    
            goto L_80055F38;
    }
    // 0x80055E9C: nop

    // 0x80055EA0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055EA4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80055EA8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80055EAC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80055EB0: addiu       $t1, $t1, -0x2AC0
    ctx->r9 = ADD32(ctx->r9, -0X2AC0);
    // 0x80055EB4: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x80055EB8: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x80055EBC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055EC0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80055EC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80055EC8: lw          $t9, -0x2A60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2A60);
    // 0x80055ECC: nop

    // 0x80055ED0: beq         $t9, $zero, L_80055F38
    if (ctx->r25 == 0) {
        // 0x80055ED4: nop
    
            goto L_80055F38;
    }
    // 0x80055ED4: nop

    // 0x80055ED8: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80055EDC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80055EE0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80055EE4: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80055EE8: addu        $t3, $t5, $t2
    ctx->r11 = ADD32(ctx->r13, ctx->r10);
    // 0x80055EEC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80055EF0: nop

    // 0x80055EF4: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80055EF8: bne         $at, $zero, L_80055F38
    if (ctx->r1 != 0) {
        // 0x80055EFC: nop
    
            goto L_80055F38;
    }
    // 0x80055EFC: nop

    // 0x80055F00: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80055F04: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F08: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80055F0C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80055F10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055F14: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80055F18: lw          $t9, -0x2AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AB8);
    // 0x80055F1C: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80055F20: addu        $t5, $sp, $t0
    ctx->r13 = ADD32(ctx->r29, ctx->r8);
    // 0x80055F24: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80055F28: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F2C: nop

    // 0x80055F30: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80055F34: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80055F38:
    // 0x80055F38: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055F3C: nop

    // 0x80055F40: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x80055F44: sltiu       $at, $t1, 0x7
    ctx->r1 = ctx->r9 < 0X7 ? 1 : 0;
    // 0x80055F48: bne         $at, $zero, L_80055E50
    if (ctx->r1 != 0) {
        // 0x80055F4C: sw          $t1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r9;
            goto L_80055E50;
    }
    // 0x80055F4C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80055F50: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F54: nop

    // 0x80055F58: bne         $t6, $zero, L_80055F70
    if (ctx->r14 != 0) {
        // 0x80055F5C: nop
    
            goto L_80055F70;
    }
    // 0x80055F5C: nop

    // 0x80055F60: b           L_80055FB0
    // 0x80055F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055FB0;
    // 0x80055F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055F68: b           L_80055FA8
    // 0x80055F6C: nop

        goto L_80055FA8;
    // 0x80055F6C: nop

L_80055F70:
    // 0x80055F70: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055F74: lw          $t8, 0x258C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X258C);
    // 0x80055F78: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80055F7C: srl         $t7, $t8, 1
    ctx->r15 = S32(U32(ctx->r24) >> 1);
    // 0x80055F80: divu        $zero, $t7, $t9
    lo = S32(U32(ctx->r15) / U32(ctx->r25)); hi = S32(U32(ctx->r15) % U32(ctx->r25));
    // 0x80055F84: bne         $t9, $zero, L_80055F90
    if (ctx->r25 != 0) {
        // 0x80055F88: nop
    
            goto L_80055F90;
    }
    // 0x80055F88: nop

    // 0x80055F8C: break       7
    do_break(2147835788);
L_80055F90:
    // 0x80055F90: mfhi        $t0
    ctx->r8 = hi;
    // 0x80055F94: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80055F98: addu        $v0, $sp, $t5
    ctx->r2 = ADD32(ctx->r29, ctx->r13);
    // 0x80055F9C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80055FA0: b           L_80055FB0
    // 0x80055FA4: nop

        goto L_80055FB0;
    // 0x80055FA4: nop

L_80055FA8:
    // 0x80055FA8: b           L_80055FB0
    // 0x80055FAC: nop

        goto L_80055FB0;
    // 0x80055FAC: nop

L_80055FB0:
    // 0x80055FB0: jr          $ra
    // 0x80055FB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80055FB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005D394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D394: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005D398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D39C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D3A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D3A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8005D3A8: addiu       $t7, $t7, -0x24E8
    ctx->r15 = ADD32(ctx->r15, -0X24E8);
    // 0x8005D3AC: addiu       $t9, $t7, 0x24
    ctx->r25 = ADD32(ctx->r15, 0X24);
    // 0x8005D3B0: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
L_8005D3B4:
    // 0x8005D3B4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005D3B8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8005D3BC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005D3C0: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8005D3C4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8005D3C8: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8005D3CC: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8005D3D0: bne         $t7, $t9, L_8005D3B4
    if (ctx->r15 != ctx->r25) {
        // 0x8005D3D4: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8005D3B4;
    }
    // 0x8005D3D4: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8005D3D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005D3DC: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8005D3E0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005D3E4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8005D3E8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8005D3EC:
    // 0x8005D3EC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005D3F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D3F4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005D3F8: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8005D3FC: lw          $a0, -0x2514($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2514);
    // 0x8005D400: nop

    // 0x8005D404: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x8005D408: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8005D40C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005D410: jal         0x800BC918
    // 0x8005D414: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_0;
    // 0x8005D414: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_0:
    // 0x8005D418: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005D41C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005D420: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005D424: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005D428: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x8005D42C: nop

    // 0x8005D430: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8005D434: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005D438: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D43C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005D440: addu        $a2, $sp, $t9
    ctx->r6 = ADD32(ctx->r29, ctx->r25);
    // 0x8005D444: lw          $a2, 0x3C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3C);
    // 0x8005D448: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D44C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D450: jal         0x800BD1FC
    // 0x8005D454: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8005D454: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_1:
    // 0x8005D458: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005D45C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D460: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8005D464: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005D468: lw          $a0, -0x2514($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2514);
    // 0x8005D46C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8005D470: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x8005D474: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8005D478: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005D47C: jal         0x800BC6EC
    // 0x8005D480: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8005D480: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
    // 0x8005D484: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005D488: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005D48C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8005D490: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8005D494: lw          $a2, -0x2514($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2514);
    // 0x8005D498: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D49C: sll         $t3, $a2, 3
    ctx->r11 = S32(ctx->r6 << 3);
    // 0x8005D4A0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8005D4A4: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x8005D4A8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8005D4AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D4B0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8005D4B4: jal         0x800BD218
    // 0x8005D4B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8005D4B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8005D4BC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005D4C0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005D4C4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005D4C8: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8005D4CC: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x8005D4D0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8005D4D4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005D4D8: lw          $t7, -0x2514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2514);
    // 0x8005D4DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005D4E0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8005D4E4: blez        $t7, L_8005D67C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005D4E8: sw          $t9, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r25;
            goto L_8005D67C;
    }
    // 0x8005D4E8: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_8005D4EC:
    // 0x8005D4EC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005D4F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D4F4: sll         $t0, $t6, 3
    ctx->r8 = S32(ctx->r14 << 3);
    // 0x8005D4F8: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8005D4FC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005D500: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005D504: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8005D508: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8005D50C: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
    // 0x8005D510: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x8005D514: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005D518: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D51C: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x8005D520: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8005D524: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8005D528: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005D52C: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8005D530: lh          $t1, 0x2($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X2);
    // 0x8005D534: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8005D538: sh          $t1, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r9;
    // 0x8005D53C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005D540: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D544: sll         $t3, $t0, 3
    ctx->r11 = S32(ctx->r8 << 3);
    // 0x8005D548: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8005D54C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8005D550: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005D554: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x8005D558: lh          $t7, 0x4($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X4);
    // 0x8005D55C: addu        $t2, $t6, $t3
    ctx->r10 = ADD32(ctx->r14, ctx->r11);
    // 0x8005D560: sh          $t7, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r15;
    // 0x8005D564: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005D568: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D56C: sll         $t1, $t5, 3
    ctx->r9 = S32(ctx->r13 << 3);
    // 0x8005D570: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8005D574: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005D578: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005D57C: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x8005D580: lh          $t8, 0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X6);
    // 0x8005D584: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x8005D588: sh          $t8, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r24;
    // 0x8005D58C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8005D590: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D594: sll         $t7, $t3, 3
    ctx->r15 = S32(ctx->r11 << 3);
    // 0x8005D598: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8005D59C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8005D5A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005D5A4: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x8005D5A8: lh          $t4, 0x8($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X8);
    // 0x8005D5AC: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x8005D5B0: sh          $t4, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r12;
    // 0x8005D5B4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005D5B8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D5BC: sll         $t8, $t1, 3
    ctx->r24 = S32(ctx->r9 << 3);
    // 0x8005D5C0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8005D5C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8005D5C8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005D5CC: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8005D5D0: lh          $t2, 0xA($t3)
    ctx->r10 = MEM_H(ctx->r11, 0XA);
    // 0x8005D5D4: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x8005D5D8: sh          $t2, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r10;
    // 0x8005D5DC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005D5E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D5E4: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x8005D5E8: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8005D5EC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8005D5F0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005D5F4: addu        $t1, $t4, $t9
    ctx->r9 = ADD32(ctx->r12, ctx->r25);
    // 0x8005D5F8: lh          $t6, 0xC($t1)
    ctx->r14 = MEM_H(ctx->r9, 0XC);
    // 0x8005D5FC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8005D600: sh          $t6, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r14;
    // 0x8005D604: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005D608: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D60C: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x8005D610: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8005D614: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005D618: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005D61C: addu        $t7, $t2, $t0
    ctx->r15 = ADD32(ctx->r10, ctx->r8);
    // 0x8005D620: lh          $t9, 0xE($t7)
    ctx->r25 = MEM_H(ctx->r15, 0XE);
    // 0x8005D624: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8005D628: sh          $t9, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r25;
    // 0x8005D62C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005D630: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D634: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x8005D638: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8005D63C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005D640: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005D644: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x8005D648: lh          $t0, 0x10($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X10);
    // 0x8005D64C: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x8005D650: sh          $t0, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r8;
    // 0x8005D654: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005D658: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005D65C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005D660: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005D664: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005D668: lw          $t5, -0x2514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2514);
    // 0x8005D66C: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8005D670: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005D674: bne         $at, $zero, L_8005D4EC
    if (ctx->r1 != 0) {
        // 0x8005D678: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_8005D4EC;
    }
    // 0x8005D678: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8005D67C:
    // 0x8005D67C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D680: jal         0x800BC980
    // 0x8005D684: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x8005D684: nop

    after_4:
    // 0x8005D688: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005D68C: nop

    // 0x8005D690: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8005D694: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x8005D698: bne         $at, $zero, L_8005D3EC
    if (ctx->r1 != 0) {
        // 0x8005D69C: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_8005D3EC;
    }
    // 0x8005D69C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8005D6A0: b           L_8005D6A8
    // 0x8005D6A4: nop

        goto L_8005D6A8;
    // 0x8005D6A4: nop

L_8005D6A8:
    // 0x8005D6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D6AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005D6B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005D6B4: jr          $ra
    // 0x8005D6B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8005D6B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80013F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013F04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80013F08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013F0C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80013F10: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80013F14: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80013F18: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80013F1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80013F20: jal         0x8000DA44
    // 0x80013F24: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80013F24: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80013F28: bgez        $v0, L_80013F38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013F2C: nop
    
            goto L_80013F38;
    }
    // 0x80013F2C: nop

    // 0x80013F30: b           L_80013FD8
    // 0x80013F34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013FD8;
    // 0x80013F34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013F38:
    // 0x80013F38: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80013F3C: nop

    // 0x80013F40: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80013F44: nop

    // 0x80013F48: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80013F4C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80013F50: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80013F54: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80013F58: nop

    // 0x80013F5C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80013F60: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x80013F64: nop

    // 0x80013F68: blez        $t0, L_80013FC8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80013F6C: nop
    
            goto L_80013FC8;
    }
    // 0x80013F6C: nop

L_80013F70:
    // 0x80013F70: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x80013F74: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    // 0x80013F78: jal         0x80014BD4
    // 0x80013F7C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80013F7C: nop

    after_1:
    // 0x80013F80: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80013F84: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80013F88: swc1        $f20, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f20.u32l;
    // 0x80013F8C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80013F90: nop

    // 0x80013F94: swc1        $f20, 0xF4($t3)
    MEM_W(0XF4, ctx->r11) = ctx->f20.u32l;
    // 0x80013F98: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80013F9C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80013FA0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80013FA4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80013FA8: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x80013FAC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80013FB0: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80013FB4: lhu         $t8, 0x6($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X6);
    // 0x80013FB8: nop

    // 0x80013FBC: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80013FC0: bne         $at, $zero, L_80013F70
    if (ctx->r1 != 0) {
        // 0x80013FC4: nop
    
            goto L_80013F70;
    }
    // 0x80013FC4: nop

L_80013FC8:
    // 0x80013FC8: b           L_80013FD8
    // 0x80013FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013FD8;
    // 0x80013FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013FD0: b           L_80013FD8
    // 0x80013FD4: nop

        goto L_80013FD8;
    // 0x80013FD4: nop

L_80013FD8:
    // 0x80013FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013FDC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80013FE0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80013FE4: jr          $ra
    // 0x80013FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80013FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800628D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800628D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800628DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800628E0: jal         0x8005F064
    // 0x800628E4: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800628E4: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_0:
    // 0x800628E8: b           L_800628F8
    // 0x800628EC: nop

        goto L_800628F8;
    // 0x800628EC: nop

    // 0x800628F0: b           L_800628F8
    // 0x800628F4: nop

        goto L_800628F8;
    // 0x800628F4: nop

L_800628F8:
    // 0x800628F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800628FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062900: jr          $ra
    // 0x80062904: nop

    return;
    // 0x80062904: nop

;}
RECOMP_FUNC void func_80065320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065320: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065324: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065328: nop

    // 0x8006532C: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80065330: nop

    // 0x80065334: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065338: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006533C: jr          $ra
    // 0x80065340: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065340: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065344: jr          $ra
    // 0x80065348: nop

    return;
    // 0x80065348: nop

    // 0x8006534C: jr          $ra
    // 0x80065350: nop

    return;
    // 0x80065350: nop

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
RECOMP_FUNC void func_80065D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065D88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065D8C: nop

    // 0x80065D90: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80065D94: nop

    // 0x80065D98: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065D9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065DA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065DA4: beq         $v0, $zero, L_80065DBC
    if (ctx->r2 == 0) {
        // 0x80065DA8: nop
    
            goto L_80065DBC;
    }
    // 0x80065DA8: nop

    // 0x80065DAC: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80065DB0: nop

    // 0x80065DB4: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065DB8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065DBC:
    // 0x80065DBC: jr          $ra
    // 0x80065DC0: nop

    return;
    // 0x80065DC0: nop

    // 0x80065DC4: jr          $ra
    // 0x80065DC8: nop

    return;
    // 0x80065DC8: nop

    // 0x80065DCC: jr          $ra
    // 0x80065DD0: nop

    return;
    // 0x80065DD0: nop

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
RECOMP_FUNC void func_8001EB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EB1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001EB20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001EB24: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EB28: nop

    // 0x8001EB2C: bltz        $t6, L_8001EBA0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001EB30: nop
    
            goto L_8001EBA0;
    }
    // 0x8001EB30: nop

    // 0x8001EB34: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EB38: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EB3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EB40: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001EB44: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EB48: nop

    // 0x8001EB4C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EB50: bne         $t0, $zero, L_8001EB70
    if (ctx->r8 != 0) {
        // 0x8001EB54: nop
    
            goto L_8001EB70;
    }
    // 0x8001EB54: nop

    // 0x8001EB58: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001EB5C: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001EB60: nop

    // 0x8001EB64: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001EB68: beq         $t2, $zero, L_8001EBA0
    if (ctx->r10 == 0) {
        // 0x8001EB6C: nop
    
            goto L_8001EBA0;
    }
    // 0x8001EB6C: nop

L_8001EB70:
    // 0x8001EB70: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001EB74: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x8001EB78: nop

    // 0x8001EB7C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8001EB80: beq         $t4, $zero, L_8001EB98
    if (ctx->r12 == 0) {
        // 0x8001EB84: nop
    
            goto L_8001EB98;
    }
    // 0x8001EB84: nop

    // 0x8001EB88: jal         0x800BDA58
    // 0x8001EB8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001EB8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8001EB90: b           L_8001EBA0
    // 0x8001EB94: nop

        goto L_8001EBA0;
    // 0x8001EB94: nop

L_8001EB98:
    // 0x8001EB98: jal         0x800BDA58
    // 0x8001EB9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BDA58(rdram, ctx);
        goto after_1;
    // 0x8001EB9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8001EBA0:
    // 0x8001EBA0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001EBA4: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x8001EBA8: nop

    // 0x8001EBAC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8001EBB0: beq         $t6, $zero, L_8001EBCC
    if (ctx->r14 == 0) {
        // 0x8001EBB4: nop
    
            goto L_8001EBCC;
    }
    // 0x8001EBB4: nop

    // 0x8001EBB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EBBC: jal         0x8008ECE4
    // 0x8001EBC0: addiu       $a0, $a0, -0x24FC
    ctx->r4 = ADD32(ctx->r4, -0X24FC);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001EBC0: addiu       $a0, $a0, -0x24FC
    ctx->r4 = ADD32(ctx->r4, -0X24FC);
    after_2:
    // 0x8001EBC4: b           L_8001EBD8
    // 0x8001EBC8: nop

        goto L_8001EBD8;
    // 0x8001EBC8: nop

L_8001EBCC:
    // 0x8001EBCC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EBD0: jal         0x8008ECE4
    // 0x8001EBD4: addiu       $a0, $a0, -0x24F4
    ctx->r4 = ADD32(ctx->r4, -0X24F4);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001EBD4: addiu       $a0, $a0, -0x24F4
    ctx->r4 = ADD32(ctx->r4, -0X24F4);
    after_3:
L_8001EBD8:
    // 0x8001EBD8: b           L_8001EBE8
    // 0x8001EBDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EBE8;
    // 0x8001EBDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EBE0: b           L_8001EBE8
    // 0x8001EBE4: nop

        goto L_8001EBE8;
    // 0x8001EBE4: nop

L_8001EBE8:
    // 0x8001EBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EBEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EBF0: jr          $ra
    // 0x8001EBF4: nop

    return;
    // 0x8001EBF4: nop

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
RECOMP_FUNC void AudioDmaCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC590: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BC594: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC598: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BC59C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BC5A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BC5A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BC5A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BC5AC: jal         0x800CAFD0
    // 0x800BC5B0: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800BC5B0: nop

    after_0:
    // 0x800BC5B4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800BC5B8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800BC5BC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BC5C0: addiu       $t8, $t8, -0x1E48
    ctx->r24 = ADD32(ctx->r24, -0X1E48);
    // 0x800BC5C4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BC5C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800BC5CC: addiu       $a0, $a0, -0x1E28
    ctx->r4 = ADD32(ctx->r4, -0X1E28);
    // 0x800BC5D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800BC5D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BC5D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BC5DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BC5E0: jal         0x800C81D0
    // 0x800BC5E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x800BC5E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x800BC5E8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BC5EC: addiu       $a0, $a0, -0x1E48
    ctx->r4 = ADD32(ctx->r4, -0X1E48);
    // 0x800BC5F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BC5F4: jal         0x800C4C40
    // 0x800BC5F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800BC5F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800BC5FC: b           L_800BC604
    // 0x800BC600: nop

        goto L_800BC604;
    // 0x800BC600: nop

L_800BC604:
    // 0x800BC604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC608: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BC60C: jr          $ra
    // 0x800BC610: nop

    return;
    // 0x800BC610: nop

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
RECOMP_FUNC void func_8007385C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007385C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073860: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073864: nop

    // 0x80073868: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x8007386C: nop

    // 0x80073870: slti        $t7, $v0, 0x14A
    ctx->r15 = SIGNED(ctx->r2) < 0X14A ? 1 : 0;
    // 0x80073874: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073878: jr          $ra
    // 0x8007387C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007387C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073880: jr          $ra
    // 0x80073884: nop

    return;
    // 0x80073884: nop

    // 0x80073888: jr          $ra
    // 0x8007388C: nop

    return;
    // 0x8007388C: nop

;}
RECOMP_FUNC void func_8000A2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2C0: addiu       $sp, $sp, -0x2C8
    ctx->r29 = ADD32(ctx->r29, -0X2C8);
    // 0x8000A2C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000A2C8: sw          $a0, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->r4;
    // 0x8000A2CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000A2D0: lw          $t6, 0x2C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C8);
    // 0x8000A2D4: nop

    // 0x8000A2D8: sw          $t6, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r14;
    // 0x8000A2DC: lw          $t7, 0x284($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X284);
    // 0x8000A2E0: nop

    // 0x8000A2E4: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8000A2E8: nop

    // 0x8000A2EC: sw          $t8, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r24;
    // 0x8000A2F0: sw          $zero, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = 0;
    // 0x8000A2F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000A2F8: nop

    // 0x8000A2FC: swc1        $f4, 0x290($sp)
    MEM_W(0X290, ctx->r29) = ctx->f4.u32l;
    // 0x8000A300: sw          $zero, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = 0;
    // 0x8000A304: sw          $zero, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = 0;
    // 0x8000A308: sw          $zero, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = 0;
    // 0x8000A30C: sw          $zero, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = 0;
    // 0x8000A310: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A314: sw          $t9, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r25;
    // 0x8000A318: sw          $zero, 0x294($sp)
    MEM_W(0X294, ctx->r29) = 0;
    // 0x8000A31C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A320: sw          $zero, -0x5B18($at)
    MEM_W(-0X5B18, ctx->r1) = 0;
    // 0x8000A324: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A328: sw          $zero, -0x5B14($at)
    MEM_W(-0X5B14, ctx->r1) = 0;
    // 0x8000A32C: jal         0x800BCB54
    // 0x8000A330: nop

    func_800BCB54(rdram, ctx);
        goto after_0;
    // 0x8000A330: nop

    after_0:
    // 0x8000A334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A338: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8000A33C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8000A340: jal         0x800BDC70
    // 0x8000A344: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BDC70(rdram, ctx);
        goto after_1;
    // 0x8000A344: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8000A348: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8000A34C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000A350: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000A354: jal         0x80099F90
    // 0x8000A358: nop

    func_80099F90(rdram, ctx);
        goto after_2;
    // 0x8000A358: nop

    after_2:
    // 0x8000A35C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A360: sw          $zero, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = 0;
    // 0x8000A364: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8000A368: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A36C: sw          $t0, 0x7244($at)
    MEM_W(0X7244, ctx->r1) = ctx->r8;
    // 0x8000A370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000A374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000A378: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A37C: swc1        $f6, 0x727C($at)
    MEM_W(0X727C, ctx->r1) = ctx->f6.u32l;
    // 0x8000A380: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A384: swc1        $f6, 0x7270($at)
    MEM_W(0X7270, ctx->r1) = ctx->f6.u32l;
    // 0x8000A388: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A38C: swc1        $f6, 0x7264($at)
    MEM_W(0X7264, ctx->r1) = ctx->f6.u32l;
    // 0x8000A390: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000A394: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000A398: lwc1        $f8, 0x25A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25A8);
    // 0x8000A39C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8000A3A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A3A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A3A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A3AC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A3B0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8000A3B4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000A3B8: sw          $t2, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r10;
    // 0x8000A3BC: nop

    // 0x8000A3C0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8000A3C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000A3C8: lwc1        $f16, 0x25B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B0);
    // 0x8000A3CC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8000A3D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A3D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A3D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A3DC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A3E0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8000A3E4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8000A3E8: sw          $t4, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r12;
    // 0x8000A3EC: nop

    // 0x8000A3F0: jal         0x80015E50
    // 0x8000A3F4: nop

    func_80015E50(rdram, ctx);
        goto after_3;
    // 0x8000A3F4: nop

    after_3:
    // 0x8000A3F8: jal         0x80015E94
    // 0x8000A3FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80015E94(rdram, ctx);
        goto after_4;
    // 0x8000A3FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8000A400: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8000A404: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A408: nop

    // 0x8000A40C: swc1        $f4, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->f4.u32l;
    // 0x8000A410: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8000A414: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000A418: nop

    // 0x8000A41C: swc1        $f6, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->f6.u32l;
    // 0x8000A420: jal         0x8001A690
    // 0x8000A424: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001A690(rdram, ctx);
        goto after_5;
    // 0x8000A424: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x8000A428: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8000A42C: sh          $t5, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r13;
    // 0x8000A430: jal         0x800ACE50
    // 0x8000A434: nop

    func_800ACE50(rdram, ctx);
        goto after_6;
    // 0x8000A434: nop

    after_6:
    // 0x8000A438: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8000A43C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000A440: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000A444: addiu       $t6, $t6, 0x61D8
    ctx->r14 = ADD32(ctx->r14, 0X61D8);
    // 0x8000A448: swc1        $f8, 0x5F4($t6)
    MEM_W(0X5F4, ctx->r14) = ctx->f8.u32l;
    // 0x8000A44C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000A450: addiu       $t7, $t7, 0x61D8
    ctx->r15 = ADD32(ctx->r15, 0X61D8);
    // 0x8000A454: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8000A458: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000A45C: lwc1        $f10, 0x5F4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X5F4);
    // 0x8000A460: nop

    // 0x8000A464: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000A468: swc1        $f18, 0x5FC($t7)
    MEM_W(0X5FC, ctx->r15) = ctx->f18.u32l;
    // 0x8000A46C: lui         $at, 0x43A8
    ctx->r1 = S32(0X43A8 << 16);
    // 0x8000A470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A474: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000A478: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x8000A47C: swc1        $f4, 0x5DC($t8)
    MEM_W(0X5DC, ctx->r24) = ctx->f4.u32l;
    // 0x8000A480: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A484: sw          $zero, -0x5B20($at)
    MEM_W(-0X5B20, ctx->r1) = 0;
    // 0x8000A488: sw          $zero, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = 0;
    // 0x8000A48C: sw          $zero, 0x264($sp)
    MEM_W(0X264, ctx->r29) = 0;
    // 0x8000A490: jal         0x800AE348
    // 0x8000A494: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    ContPak_SetPakInitializationAttempts(rdram, ctx);
        goto after_7;
    // 0x8000A494: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x8000A498: jal         0x80098820
    // 0x8000A49C: nop

    func_80098820(rdram, ctx);
        goto after_8;
    // 0x8000A49C: nop

    after_8:
    // 0x8000A4A0: jal         0x80098868
    // 0x8000A4A4: nop

    func_80098868(rdram, ctx);
        goto after_9;
    // 0x8000A4A4: nop

    after_9:
    // 0x8000A4A8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000A4AC: lw          $t9, -0x5B20($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B20);
    // 0x8000A4B0: nop

    // 0x8000A4B4: bne         $t9, $zero, L_8000B0C4
    if (ctx->r25 != 0) {
        // 0x8000A4B8: nop
    
            goto L_8000B0C4;
    }
    // 0x8000A4B8: nop

L_8000A4BC:
    // 0x8000A4BC: lw          $t0, 0x284($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X284);
    // 0x8000A4C0: addiu       $a1, $sp, 0x27C
    ctx->r5 = ADD32(ctx->r29, 0X27C);
    // 0x8000A4C4: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8000A4C8: jal         0x800C143C
    // 0x8000A4CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_10;
    // 0x8000A4CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x8000A4D0: lw          $t1, 0x27C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X27C);
    // 0x8000A4D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A4D8: lh          $s0, 0x0($t1)
    ctx->r16 = MEM_H(ctx->r9, 0X0);
    // 0x8000A4DC: nop

    // 0x8000A4E0: beq         $s0, $at, L_8000A508
    if (ctx->r16 == ctx->r1) {
        // 0x8000A4E4: nop
    
            goto L_8000A508;
    }
    // 0x8000A4E4: nop

    // 0x8000A4E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A4EC: beq         $s0, $at, L_8000B064
    if (ctx->r16 == ctx->r1) {
        // 0x8000A4F0: nop
    
            goto L_8000B064;
    }
    // 0x8000A4F0: nop

    // 0x8000A4F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000A4F8: beq         $s0, $at, L_8000B090
    if (ctx->r16 == ctx->r1) {
        // 0x8000A4FC: nop
    
            goto L_8000B090;
    }
    // 0x8000A4FC: nop

    // 0x8000A500: b           L_8000B0A8
    // 0x8000A504: nop

        goto L_8000B0A8;
    // 0x8000A504: nop

L_8000A508:
    // 0x8000A508: lw          $t2, 0x280($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X280);
    // 0x8000A50C: nop

    // 0x8000A510: addiu       $t3, $t2, 0x7FFF
    ctx->r11 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000A514: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x8000A518: nop

    // 0x8000A51C: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8000A520: beq         $at, $zero, L_8000B05C
    if (ctx->r1 == 0) {
        // 0x8000A524: nop
    
            goto L_8000B05C;
    }
    // 0x8000A524: nop

    // 0x8000A528: jal         0x80099768
    // 0x8000A52C: nop

    func_80099768(rdram, ctx);
        goto after_11;
    // 0x8000A52C: nop

    after_11:
    // 0x8000A530: jal         0x800AFB28
    // 0x8000A534: nop

    func_800AFB28(rdram, ctx);
        goto after_12;
    // 0x8000A534: nop

    after_12:
    // 0x8000A538: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8000A53C: lw          $t5, -0x4CC4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CC4);
    // 0x8000A540: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8000A544: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8000A548: lw          $t4, -0x4CCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CCC);
    // 0x8000A54C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000A550: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8000A554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000A558: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x8000A55C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8000A560: jal         0x800BE510
    // 0x8000A564: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800BE510(rdram, ctx);
        goto after_13;
    // 0x8000A564: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_13:
    // 0x8000A568: jal         0x80032604
    // 0x8000A56C: nop

    func_80032604(rdram, ctx);
        goto after_14;
    // 0x8000A56C: nop

    after_14:
    // 0x8000A570: lw          $t6, 0x2B0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000A574: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A578: bne         $t6, $at, L_8000AF74
    if (ctx->r14 != ctx->r1) {
        // 0x8000A57C: nop
    
            goto L_8000AF74;
    }
    // 0x8000A57C: nop

    // 0x8000A580: jal         0x8001AB84
    // 0x8000A584: nop

    func_8001AB84(rdram, ctx);
        goto after_15;
    // 0x8000A584: nop

    after_15:
    // 0x8000A588: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000A58C: addiu       $t7, $t7, -0x5AC0
    ctx->r15 = ADD32(ctx->r15, -0X5AC0);
    // 0x8000A590: sw          $t7, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r15;
    // 0x8000A594: sw          $zero, 0x288($sp)
    MEM_W(0X288, ctx->r29) = 0;
    // 0x8000A598: sw          $zero, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = 0;
    // 0x8000A59C: sw          $zero, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = 0;
L_8000A5A0:
    // 0x8000A5A0: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A5A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000A5AC: nop

    // 0x8000A5B0: bne         $t9, $at, L_8000A5C0
    if (ctx->r25 != ctx->r1) {
        // 0x8000A5B4: nop
    
            goto L_8000A5C0;
    }
    // 0x8000A5B4: nop

    // 0x8000A5B8: b           L_8000A820
    // 0x8000A5BC: nop

        goto L_8000A820;
    // 0x8000A5BC: nop

L_8000A5C0:
    // 0x8000A5C0: lw          $t0, 0x26C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A5C8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000A5CC: nop

    // 0x8000A5D0: beq         $t1, $at, L_8000A60C
    if (ctx->r9 == ctx->r1) {
        // 0x8000A5D4: nop
    
            goto L_8000A60C;
    }
    // 0x8000A5D4: nop

    // 0x8000A5D8: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5DC: nop

    // 0x8000A5E0: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x8000A5E4: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8000A5E8: jal         0x8008EAA8
    // 0x8000A5EC: nop

    func_8008EAA8(rdram, ctx);
        goto after_16;
    // 0x8000A5EC: nop

    after_16:
    // 0x8000A5F0: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5F4: nop

    // 0x8000A5F8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8000A5FC: nop

    // 0x8000A600: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000A604: b           L_8000A628
    // 0x8000A608: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
        goto L_8000A628;
    // 0x8000A608: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
L_8000A60C:
    // 0x8000A60C: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A610: lw          $t7, 0x2B4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2B4);
    // 0x8000A614: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8000A618: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000A61C: sw          $t8, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r24;
    // 0x8000A620: jal         0x8008EAA8
    // 0x8000A624: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_17;
    // 0x8000A624: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_17:
L_8000A628:
    // 0x8000A628: lw          $t9, 0x26C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A62C: nop

    // 0x8000A630: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8000A634: nop

    // 0x8000A638: beq         $t0, $zero, L_8000A7C0
    if (ctx->r8 == 0) {
        // 0x8000A63C: nop
    
            goto L_8000A7C0;
    }
    // 0x8000A63C: nop

    // 0x8000A640: lw          $t1, 0x2BC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000A644: lw          $t2, 0x2B8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000A648: nop

    // 0x8000A64C: bne         $t1, $t2, L_8000A75C
    if (ctx->r9 != ctx->r10) {
        // 0x8000A650: nop
    
            goto L_8000A75C;
    }
    // 0x8000A650: nop

    // 0x8000A654: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A658: nop

    // 0x8000A65C: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8000A660: nop

    // 0x8000A664: beq         $t4, $zero, L_8000A688
    if (ctx->r12 == 0) {
        // 0x8000A668: nop
    
            goto L_8000A688;
    }
    // 0x8000A668: nop

    // 0x8000A66C: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A674: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8000A678: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8000A67C: jalr        $t9
    // 0x8000A680: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_18;
    // 0x8000A680: nop

    after_18:
    // 0x8000A684: sw          $v0, 0x288($sp)
    MEM_W(0X288, ctx->r29) = ctx->r2;
L_8000A688:
    // 0x8000A688: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A68C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A690: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000A694: nop

    // 0x8000A698: bne         $t7, $at, L_8000A6D4
    if (ctx->r15 != ctx->r1) {
        // 0x8000A69C: nop
    
            goto L_8000A6D4;
    }
    // 0x8000A69C: nop

    // 0x8000A6A0: lw          $t8, 0x288($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X288);
    // 0x8000A6A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A6A8: bne         $t8, $at, L_8000A6D4
    if (ctx->r24 != ctx->r1) {
        // 0x8000A6AC: nop
    
            goto L_8000A6D4;
    }
    // 0x8000A6AC: nop

    // 0x8000A6B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A6B4: sw          $t0, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r8;
    // 0x8000A6B8: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A6BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A6C0: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x8000A6C4: jal         0x8008ECE4
    // 0x8000A6C8: addiu       $a0, $a0, -0x2DA8
    ctx->r4 = ADD32(ctx->r4, -0X2DA8);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x8000A6C8: addiu       $a0, $a0, -0x2DA8
    ctx->r4 = ADD32(ctx->r4, -0X2DA8);
    after_19:
    // 0x8000A6CC: b           L_8000A74C
    // 0x8000A6D0: nop

        goto L_8000A74C;
    // 0x8000A6D0: nop

L_8000A6D4:
    // 0x8000A6D4: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A6D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A6DC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8000A6E0: nop

    // 0x8000A6E4: bne         $t3, $at, L_8000A72C
    if (ctx->r11 != ctx->r1) {
        // 0x8000A6E8: nop
    
            goto L_8000A72C;
    }
    // 0x8000A6E8: nop

    // 0x8000A6EC: lw          $t4, 0x288($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X288);
    // 0x8000A6F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A6F4: bne         $t4, $at, L_8000A72C
    if (ctx->r12 != ctx->r1) {
        // 0x8000A6F8: nop
    
            goto L_8000A72C;
    }
    // 0x8000A6F8: nop

    // 0x8000A6FC: lw          $t5, 0x2A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000A700: nop

    // 0x8000A704: bne         $t5, $zero, L_8000A724
    if (ctx->r13 != 0) {
        // 0x8000A708: nop
    
            goto L_8000A724;
    }
    // 0x8000A708: nop

    // 0x8000A70C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A710: sw          $t9, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = ctx->r25;
    // 0x8000A714: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A718: sw          $t6, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = ctx->r14;
    // 0x8000A71C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A720: sw          $zero, -0x5B1C($at)
    MEM_W(-0X5B1C, ctx->r1) = 0;
L_8000A724:
    // 0x8000A724: b           L_8000A74C
    // 0x8000A728: nop

        goto L_8000A74C;
    // 0x8000A728: nop

L_8000A72C:
    // 0x8000A72C: addiu       $t7, $zero, 0xF4
    ctx->r15 = ADD32(0, 0XF4);
    // 0x8000A730: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A734: sw          $t7, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r15;
    // 0x8000A738: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A73C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A740: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8000A744: jal         0x8008ECE4
    // 0x8000A748: addiu       $a0, $a0, -0x2DA4
    ctx->r4 = ADD32(ctx->r4, -0X2DA4);
    func_8008ECE4(rdram, ctx);
        goto after_20;
    // 0x8000A748: addiu       $a0, $a0, -0x2DA4
    ctx->r4 = ADD32(ctx->r4, -0X2DA4);
    after_20:
L_8000A74C:
    // 0x8000A74C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8000A750: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A754: b           L_8000A7AC
    // 0x8000A758: sw          $t0, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r8;
        goto L_8000A7AC;
    // 0x8000A758: sw          $t0, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r8;
L_8000A75C:
    // 0x8000A75C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8000A760: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A764: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
    // 0x8000A768: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A76C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A770: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x8000A774: jal         0x8008ECE4
    // 0x8000A778: addiu       $a0, $a0, -0x2DA0
    ctx->r4 = ADD32(ctx->r4, -0X2DA0);
    func_8008ECE4(rdram, ctx);
        goto after_21;
    // 0x8000A778: addiu       $a0, $a0, -0x2DA0
    ctx->r4 = ADD32(ctx->r4, -0X2DA0);
    after_21:
    // 0x8000A77C: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A780: nop

    // 0x8000A784: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8000A788: nop

    // 0x8000A78C: beq         $t4, $zero, L_8000A7AC
    if (ctx->r12 == 0) {
        // 0x8000A790: nop
    
            goto L_8000A7AC;
    }
    // 0x8000A790: nop

    // 0x8000A794: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A798: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000A79C: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8000A7A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8000A7A4: jalr        $t9
    // 0x8000A7A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_22;
    // 0x8000A7A8: nop

    after_22:
L_8000A7AC:
    // 0x8000A7AC: lw          $t6, 0x2B8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000A7B0: nop

    // 0x8000A7B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000A7B8: b           L_8000A804
    // 0x8000A7BC: sw          $t7, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r15;
        goto L_8000A804;
    // 0x8000A7BC: sw          $t7, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r15;
L_8000A7C0:
    // 0x8000A7C0: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A7C4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A7C8: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8000A7CC: jal         0x8008ECE4
    // 0x8000A7D0: addiu       $a0, $a0, -0x2D9C
    ctx->r4 = ADD32(ctx->r4, -0X2D9C);
    func_8008ECE4(rdram, ctx);
        goto after_23;
    // 0x8000A7D0: addiu       $a0, $a0, -0x2D9C
    ctx->r4 = ADD32(ctx->r4, -0X2D9C);
    after_23:
    // 0x8000A7D4: lw          $t0, 0x26C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A7D8: nop

    // 0x8000A7DC: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8000A7E0: nop

    // 0x8000A7E4: beq         $t1, $zero, L_8000A804
    if (ctx->r9 == 0) {
        // 0x8000A7E8: nop
    
            goto L_8000A804;
    }
    // 0x8000A7E8: nop

    // 0x8000A7EC: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A7F0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000A7F4: lw          $t9, 0x14($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X14);
    // 0x8000A7F8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8000A7FC: jalr        $t9
    // 0x8000A800: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_24;
    // 0x8000A800: nop

    after_24:
L_8000A804:
    // 0x8000A804: lw          $t3, 0x2C4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C4);
    // 0x8000A808: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A80C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000A810: addiu       $t6, $t5, 0x28
    ctx->r14 = ADD32(ctx->r13, 0X28);
    // 0x8000A814: sw          $t6, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r14;
    // 0x8000A818: b           L_8000A5A0
    // 0x8000A81C: sw          $t4, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r12;
        goto L_8000A5A0;
    // 0x8000A81C: sw          $t4, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r12;
L_8000A820:
    // 0x8000A820: lw          $t7, 0x2A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000A824: nop

    // 0x8000A828: beq         $t7, $zero, L_8000A9D4
    if (ctx->r15 == 0) {
        // 0x8000A82C: nop
    
            goto L_8000A9D4;
    }
    // 0x8000A82C: nop

    // 0x8000A830: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000A834: lw          $t8, -0x5B1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B1C);
    // 0x8000A838: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A83C: bne         $t8, $at, L_8000A9D4
    if (ctx->r24 != ctx->r1) {
        // 0x8000A840: nop
    
            goto L_8000A9D4;
    }
    // 0x8000A840: nop

    // 0x8000A844: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A848: jal         0x8008EAA8
    // 0x8000A84C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_25;
    // 0x8000A84C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_25:
    // 0x8000A850: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A854: jal         0x8008ECE4
    // 0x8000A858: addiu       $a0, $a0, -0x2D98
    ctx->r4 = ADD32(ctx->r4, -0X2D98);
    func_8008ECE4(rdram, ctx);
        goto after_26;
    // 0x8000A858: addiu       $a0, $a0, -0x2D98
    ctx->r4 = ADD32(ctx->r4, -0X2D98);
    after_26:
    // 0x8000A85C: lw          $t0, 0x298($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X298);
    // 0x8000A860: nop

    // 0x8000A864: bne         $t0, $zero, L_8000A878
    if (ctx->r8 != 0) {
        // 0x8000A868: nop
    
            goto L_8000A878;
    }
    // 0x8000A868: nop

    // 0x8000A86C: addiu       $t1, $zero, 0xF4
    ctx->r9 = ADD32(0, 0XF4);
    // 0x8000A870: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A874: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
L_8000A878:
    // 0x8000A878: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A87C: jal         0x8008ECE4
    // 0x8000A880: addiu       $a0, $a0, -0x2D84
    ctx->r4 = ADD32(ctx->r4, -0X2D84);
    func_8008ECE4(rdram, ctx);
        goto after_27;
    // 0x8000A880: addiu       $a0, $a0, -0x2D84
    ctx->r4 = ADD32(ctx->r4, -0X2D84);
    after_27:
    // 0x8000A884: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8000A888: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A88C: sw          $t2, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r10;
    // 0x8000A890: lw          $t9, 0x298($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X298);
    // 0x8000A894: nop

    // 0x8000A898: beq         $t9, $zero, L_8000A8AC
    if (ctx->r25 == 0) {
        // 0x8000A89C: nop
    
            goto L_8000A8AC;
    }
    // 0x8000A89C: nop

    // 0x8000A8A0: addiu       $t3, $zero, 0xF4
    ctx->r11 = ADD32(0, 0XF4);
    // 0x8000A8A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A8A8: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
L_8000A8AC:
    // 0x8000A8AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A8B0: jal         0x8008ECE4
    // 0x8000A8B4: addiu       $a0, $a0, -0x2D7C
    ctx->r4 = ADD32(ctx->r4, -0X2D7C);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x8000A8B4: addiu       $a0, $a0, -0x2D7C
    ctx->r4 = ADD32(ctx->r4, -0X2D7C);
    after_28:
    // 0x8000A8B8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000A8BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A8C0: sw          $t4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r12;
    // 0x8000A8C4: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000A8C8: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8000A8CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000A8D0: lhu         $t7, 0xEC0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XEC0);
    // 0x8000A8D4: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8000A8D8: nop

    // 0x8000A8DC: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8000A8E0: beq         $t8, $zero, L_8000A8F8
    if (ctx->r24 == 0) {
        // 0x8000A8E4: nop
    
            goto L_8000A8F8;
    }
    // 0x8000A8E4: nop

    // 0x8000A8E8: lw          $t0, 0x298($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X298);
    // 0x8000A8EC: nop

    // 0x8000A8F0: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000A8F4: sw          $t1, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r9;
L_8000A8F8:
    // 0x8000A8F8: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000A8FC: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8000A900: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000A904: lhu         $t3, 0xEEC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XEEC);
    // 0x8000A908: lhu         $t9, 0x8($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X8);
    // 0x8000A90C: nop

    // 0x8000A910: and         $t4, $t9, $t3
    ctx->r12 = ctx->r25 & ctx->r11;
    // 0x8000A914: beq         $t4, $zero, L_8000A92C
    if (ctx->r12 == 0) {
        // 0x8000A918: nop
    
            goto L_8000A92C;
    }
    // 0x8000A918: nop

    // 0x8000A91C: lw          $t5, 0x298($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X298);
    // 0x8000A920: nop

    // 0x8000A924: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000A928: sw          $t6, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r14;
L_8000A92C:
    // 0x8000A92C: lw          $t7, 0x298($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X298);
    // 0x8000A930: nop

    // 0x8000A934: bgez        $t7, L_8000A940
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000A938: nop
    
            goto L_8000A940;
    }
    // 0x8000A938: nop

    // 0x8000A93C: sw          $zero, 0x298($sp)
    MEM_W(0X298, ctx->r29) = 0;
L_8000A940:
    // 0x8000A940: lw          $t8, 0x298($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X298);
    // 0x8000A944: nop

    // 0x8000A948: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8000A94C: bne         $at, $zero, L_8000A95C
    if (ctx->r1 != 0) {
        // 0x8000A950: nop
    
            goto L_8000A95C;
    }
    // 0x8000A950: nop

    // 0x8000A954: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A958: sw          $t0, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r8;
L_8000A95C:
    // 0x8000A95C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8000A960: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000A964: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000A968: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8000A96C: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8000A970: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8000A974: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8000A978: or          $t9, $t1, $t2
    ctx->r25 = ctx->r9 | ctx->r10;
    // 0x8000A97C: and         $t5, $t4, $t9
    ctx->r13 = ctx->r12 & ctx->r25;
    // 0x8000A980: beq         $t5, $zero, L_8000A9D4
    if (ctx->r13 == 0) {
        // 0x8000A984: nop
    
            goto L_8000A9D4;
    }
    // 0x8000A984: nop

    // 0x8000A988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A98C: jal         0x8008EAA8
    // 0x8000A990: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_29;
    // 0x8000A990: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_29:
    // 0x8000A994: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A998: jal         0x8008ECE4
    // 0x8000A99C: addiu       $a0, $a0, -0x2D74
    ctx->r4 = ADD32(ctx->r4, -0X2D74);
    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x8000A99C: addiu       $a0, $a0, -0x2D74
    ctx->r4 = ADD32(ctx->r4, -0X2D74);
    after_30:
    // 0x8000A9A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A9A4: sw          $zero, -0x5B1C($at)
    MEM_W(-0X5B1C, ctx->r1) = 0;
    // 0x8000A9A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A9AC: sw          $t6, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = ctx->r14;
    // 0x8000A9B0: lw          $t7, 0x298($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X298);
    // 0x8000A9B4: nop

    // 0x8000A9B8: bne         $t7, $zero, L_8000A9D4
    if (ctx->r15 != 0) {
        // 0x8000A9BC: nop
    
            goto L_8000A9D4;
    }
    // 0x8000A9BC: nop

    // 0x8000A9C0: lw          $a0, 0x2AC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000A9C4: jal         0x800AE5F0
    // 0x8000A9C8: nop

    ContPak_SetFileDeleteParams(rdram, ctx);
        goto after_31;
    // 0x8000A9C8: nop

    after_31:
    // 0x8000A9CC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000A9D0: sw          $t8, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r24;
L_8000A9D4:
    // 0x8000A9D4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8000A9D8: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x8000A9DC: nop

    // 0x8000A9E0: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x8000A9E4: beq         $t1, $zero, L_8000AA0C
    if (ctx->r9 == 0) {
        // 0x8000A9E8: nop
    
            goto L_8000AA0C;
    }
    // 0x8000A9E8: nop

    // 0x8000A9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A9F0: jal         0x8008EAA8
    // 0x8000A9F4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_32;
    // 0x8000A9F4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_32:
    // 0x8000A9F8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A9FC: jal         0x8008ECE4
    // 0x8000AA00: addiu       $a0, $a0, -0x2D54
    ctx->r4 = ADD32(ctx->r4, -0X2D54);
    func_8008ECE4(rdram, ctx);
        goto after_33;
    // 0x8000AA00: addiu       $a0, $a0, -0x2D54
    ctx->r4 = ADD32(ctx->r4, -0X2D54);
    after_33:
    // 0x8000AA04: b           L_8000AA44
    // 0x8000AA08: nop

        goto L_8000AA44;
    // 0x8000AA08: nop

L_8000AA0C:
    // 0x8000AA0C: lw          $t2, 0x294($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X294);
    // 0x8000AA10: nop

    // 0x8000AA14: beq         $t2, $zero, L_8000AA44
    if (ctx->r10 == 0) {
        // 0x8000AA18: nop
    
            goto L_8000AA44;
    }
    // 0x8000AA18: nop

    // 0x8000AA1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000AA20: jal         0x8008EAA8
    // 0x8000AA24: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_34;
    // 0x8000AA24: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_34:
    // 0x8000AA28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000AA2C: jal         0x8008ECE4
    // 0x8000AA30: addiu       $a0, $a0, -0x2D40
    ctx->r4 = ADD32(ctx->r4, -0X2D40);
    func_8008ECE4(rdram, ctx);
        goto after_35;
    // 0x8000AA30: addiu       $a0, $a0, -0x2D40
    ctx->r4 = ADD32(ctx->r4, -0X2D40);
    after_35:
    // 0x8000AA34: lw          $t3, 0x294($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X294);
    // 0x8000AA38: nop

    // 0x8000AA3C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000AA40: sw          $t4, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r12;
L_8000AA44:
    // 0x8000AA44: jal         0x8001AC74
    // 0x8000AA48: nop

    func_8001AC74(rdram, ctx);
        goto after_36;
    // 0x8000AA48: nop

    after_36:
    // 0x8000AA4C: jal         0x8001ABEC
    // 0x8000AA50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001ABEC(rdram, ctx);
        goto after_37;
    // 0x8000AA50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_37:
    // 0x8000AA54: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000AA58: lw          $t9, -0x5B1C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B1C);
    // 0x8000AA5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AA60: beq         $t9, $at, L_8000AD7C
    if (ctx->r25 == ctx->r1) {
        // 0x8000AA64: nop
    
            goto L_8000AD7C;
    }
    // 0x8000AA64: nop

    // 0x8000AA68: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x8000AA6C: sw          $t5, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r13;
    // 0x8000AA70: lw          $t6, 0x278($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X278);
    // 0x8000AA74: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8000AA78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000AA7C: lwc1        $f10, 0xD0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8000AA80: nop

    // 0x8000AA84: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000AA88: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000AA8C: nop

    // 0x8000AA90: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000AA94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000AA98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000AA9C: nop

    // 0x8000AAA0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000AAA4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8000AAA8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000AAAC: sw          $t8, 0x2C0($sp)
    MEM_W(0X2C0, ctx->r29) = ctx->r24;
    // 0x8000AAB0: nop

    // 0x8000AAB4: lw          $t0, 0x2C0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C0);
    // 0x8000AAB8: lw          $t1, 0x2AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AABC: nop

    // 0x8000AAC0: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000AAC4: beq         $at, $zero, L_8000AAEC
    if (ctx->r1 == 0) {
        // 0x8000AAC8: nop
    
            goto L_8000AAEC;
    }
    // 0x8000AAC8: nop

    // 0x8000AACC: lw          $t2, 0x278($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X278);
    // 0x8000AAD0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8000AAD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000AAD8: lwc1        $f6, 0xD0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8000AADC: nop

    // 0x8000AAE0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000AAE4: b           L_8000AB28
    // 0x8000AAE8: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
        goto L_8000AB28;
    // 0x8000AAE8: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
L_8000AAEC:
    // 0x8000AAEC: lw          $t3, 0x2AC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AAF0: lw          $t4, 0x2C0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C0);
    // 0x8000AAF4: nop

    // 0x8000AAF8: subu        $t9, $t3, $t4
    ctx->r25 = SUB32(ctx->r11, ctx->r12);
    // 0x8000AAFC: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8000AB00: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x8000AB04: bne         $at, $zero, L_8000AB28
    if (ctx->r1 != 0) {
        // 0x8000AB08: nop
    
            goto L_8000AB28;
    }
    // 0x8000AB08: nop

    // 0x8000AB0C: lw          $t6, 0x278($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X278);
    // 0x8000AB10: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8000AB14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000AB18: lwc1        $f16, 0xD0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8000AB1C: nop

    // 0x8000AB20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000AB24: swc1        $f4, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f4.u32l;
L_8000AB28:
    // 0x8000AB28: jal         0x80090754
    // 0x8000AB2C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090754(rdram, ctx);
        goto after_38;
    // 0x8000AB2C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_38:
    // 0x8000AB30: jal         0x80090728
    // 0x8000AB34: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090728(rdram, ctx);
        goto after_39;
    // 0x8000AB34: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_39:
    // 0x8000AB38: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000AB3C: addiu       $t7, $t7, -0x59F8
    ctx->r15 = ADD32(ctx->r15, -0X59F8);
    // 0x8000AB40: sw          $t7, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r15;
    // 0x8000AB44: sw          $zero, 0x288($sp)
    MEM_W(0X288, ctx->r29) = 0;
    // 0x8000AB48: sw          $zero, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = 0;
    // 0x8000AB4C: sw          $zero, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = 0;
L_8000AB50:
    // 0x8000AB50: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AB54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AB58: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8000AB5C: nop

    // 0x8000AB60: bne         $t0, $at, L_8000AB70
    if (ctx->r8 != ctx->r1) {
        // 0x8000AB64: nop
    
            goto L_8000AB70;
    }
    // 0x8000AB64: nop

    // 0x8000AB68: b           L_8000AD7C
    // 0x8000AB6C: nop

        goto L_8000AD7C;
    // 0x8000AB6C: nop

L_8000AB70:
    // 0x8000AB70: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AB74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AB78: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000AB7C: nop

    // 0x8000AB80: beq         $t2, $at, L_8000ABBC
    if (ctx->r10 == ctx->r1) {
        // 0x8000AB84: nop
    
            goto L_8000ABBC;
    }
    // 0x8000AB84: nop

    // 0x8000AB88: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AB8C: nop

    // 0x8000AB90: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8000AB94: lw          $a1, 0xC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC);
    // 0x8000AB98: jal         0x8008EAA8
    // 0x8000AB9C: nop

    func_8008EAA8(rdram, ctx);
        goto after_40;
    // 0x8000AB9C: nop

    after_40:
    // 0x8000ABA0: lw          $t4, 0x26C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ABA4: nop

    // 0x8000ABA8: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x8000ABAC: nop

    // 0x8000ABB0: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8000ABB4: b           L_8000ABD8
    // 0x8000ABB8: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
        goto L_8000ABD8;
    // 0x8000ABB8: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
L_8000ABBC:
    // 0x8000ABBC: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ABC0: lw          $t7, 0x2B4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2B4);
    // 0x8000ABC4: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8000ABC8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000ABCC: sw          $t8, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r24;
    // 0x8000ABD0: jal         0x8008EAA8
    // 0x8000ABD4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_41;
    // 0x8000ABD4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_41:
L_8000ABD8:
    // 0x8000ABD8: lw          $t0, 0x26C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ABDC: nop

    // 0x8000ABE0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8000ABE4: nop

    // 0x8000ABE8: beq         $t1, $zero, L_8000AD4C
    if (ctx->r9 == 0) {
        // 0x8000ABEC: nop
    
            goto L_8000AD4C;
    }
    // 0x8000ABEC: nop

    // 0x8000ABF0: lw          $t2, 0x2A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000ABF4: nop

    // 0x8000ABF8: beq         $t2, $zero, L_8000ACE8
    if (ctx->r10 == 0) {
        // 0x8000ABFC: nop
    
            goto L_8000ACE8;
    }
    // 0x8000ABFC: nop

    // 0x8000AC00: lw          $t3, 0x2AC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AC04: lw          $t4, 0x2A0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2A0);
    // 0x8000AC08: nop

    // 0x8000AC0C: bne         $t3, $t4, L_8000ACE8
    if (ctx->r11 != ctx->r12) {
        // 0x8000AC10: nop
    
            goto L_8000ACE8;
    }
    // 0x8000AC10: nop

    // 0x8000AC14: addiu       $t9, $zero, 0xF4
    ctx->r25 = ADD32(0, 0XF4);
    // 0x8000AC18: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000AC1C: sw          $t9, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r25;
    // 0x8000AC20: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AC24: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000AC28: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x8000AC2C: jal         0x8008ECE4
    // 0x8000AC30: addiu       $a0, $a0, -0x2D2C
    ctx->r4 = ADD32(ctx->r4, -0X2D2C);
    func_8008ECE4(rdram, ctx);
        goto after_42;
    // 0x8000AC30: addiu       $a0, $a0, -0x2D2C
    ctx->r4 = ADD32(ctx->r4, -0X2D2C);
    after_42:
    // 0x8000AC34: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AC38: nop

    // 0x8000AC3C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8000AC40: nop

    // 0x8000AC44: beq         $t7, $zero, L_8000ACD8
    if (ctx->r15 == 0) {
        // 0x8000AC48: nop
    
            goto L_8000ACD8;
    }
    // 0x8000AC48: nop

    // 0x8000AC4C: lw          $t8, 0x28C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28C);
    // 0x8000AC50: nop

    // 0x8000AC54: bne         $t8, $zero, L_8000ACBC
    if (ctx->r24 != 0) {
        // 0x8000AC58: nop
    
            goto L_8000ACBC;
    }
    // 0x8000AC58: nop

    // 0x8000AC5C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000AC60: lw          $t0, -0x5B1C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B1C);
    // 0x8000AC64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AC68: beq         $t0, $at, L_8000AC9C
    if (ctx->r8 == ctx->r1) {
        // 0x8000AC6C: nop
    
            goto L_8000AC9C;
    }
    // 0x8000AC6C: nop

    // 0x8000AC70: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AC74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000AC78: lw          $t9, 0x14($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X14);
    // 0x8000AC7C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8000AC80: jalr        $t9
    // 0x8000AC84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_43;
    // 0x8000AC84: nop

    after_43:
    // 0x8000AC88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000AC8C: sw          $v0, -0x5B1C($at)
    MEM_W(-0X5B1C, ctx->r1) = ctx->r2;
    // 0x8000AC90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000AC94: b           L_8000ACB4
    // 0x8000AC98: sw          $t2, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r10;
        goto L_8000ACB4;
    // 0x8000AC98: sw          $t2, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r10;
L_8000AC9C:
    // 0x8000AC9C: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ACA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000ACA4: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x8000ACA8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8000ACAC: jalr        $t9
    // 0x8000ACB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_44;
    // 0x8000ACB0: nop

    after_44:
L_8000ACB4:
    // 0x8000ACB4: b           L_8000ACD8
    // 0x8000ACB8: nop

        goto L_8000ACD8;
    // 0x8000ACB8: nop

L_8000ACBC:
    // 0x8000ACBC: lw          $t4, 0x26C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ACC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000ACC4: lw          $t9, 0x14($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14);
    // 0x8000ACC8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000ACCC: jalr        $t9
    // 0x8000ACD0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_45;
    // 0x8000ACD0: nop

    after_45:
    // 0x8000ACD4: sw          $zero, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = 0;
L_8000ACD8:
    // 0x8000ACD8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8000ACDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000ACE0: b           L_8000AD38
    // 0x8000ACE4: sw          $t5, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r13;
        goto L_8000AD38;
    // 0x8000ACE4: sw          $t5, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r13;
L_8000ACE8:
    // 0x8000ACE8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8000ACEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000ACF0: sw          $t6, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r14;
    // 0x8000ACF4: lw          $t7, 0x26C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ACF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000ACFC: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x8000AD00: jal         0x8008ECE4
    // 0x8000AD04: addiu       $a0, $a0, -0x2D28
    ctx->r4 = ADD32(ctx->r4, -0X2D28);
    func_8008ECE4(rdram, ctx);
        goto after_46;
    // 0x8000AD04: addiu       $a0, $a0, -0x2D28
    ctx->r4 = ADD32(ctx->r4, -0X2D28);
    after_46:
    // 0x8000AD08: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD0C: nop

    // 0x8000AD10: lw          $t0, 0x14($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X14);
    // 0x8000AD14: nop

    // 0x8000AD18: beq         $t0, $zero, L_8000AD38
    if (ctx->r8 == 0) {
        // 0x8000AD1C: nop
    
            goto L_8000AD38;
    }
    // 0x8000AD1C: nop

    // 0x8000AD20: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000AD28: lw          $t9, 0x14($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X14);
    // 0x8000AD2C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8000AD30: jalr        $t9
    // 0x8000AD34: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_47;
    // 0x8000AD34: nop

    after_47:
L_8000AD38:
    // 0x8000AD38: lw          $t2, 0x2A0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2A0);
    // 0x8000AD3C: nop

    // 0x8000AD40: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000AD44: b           L_8000AD60
    // 0x8000AD48: sw          $t3, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r11;
        goto L_8000AD60;
    // 0x8000AD48: sw          $t3, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r11;
L_8000AD4C:
    // 0x8000AD4C: lw          $t4, 0x26C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000AD54: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x8000AD58: jal         0x8008ECE4
    // 0x8000AD5C: addiu       $a0, $a0, -0x2D24
    ctx->r4 = ADD32(ctx->r4, -0X2D24);
    func_8008ECE4(rdram, ctx);
        goto after_48;
    // 0x8000AD5C: addiu       $a0, $a0, -0x2D24
    ctx->r4 = ADD32(ctx->r4, -0X2D24);
    after_48:
L_8000AD60:
    // 0x8000AD60: lw          $t5, 0x2C4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C4);
    // 0x8000AD64: lw          $t7, 0x26C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD68: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000AD6C: addiu       $t8, $t7, 0x28
    ctx->r24 = ADD32(ctx->r15, 0X28);
    // 0x8000AD70: sw          $t8, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r24;
    // 0x8000AD74: b           L_8000AB50
    // 0x8000AD78: sw          $t6, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r14;
        goto L_8000AB50;
    // 0x8000AD78: sw          $t6, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r14;
L_8000AD7C:
    // 0x8000AD7C: jal         0x8001ACDC
    // 0x8000AD80: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001ACDC(rdram, ctx);
        goto after_49;
    // 0x8000AD80: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_49:
    // 0x8000AD84: jal         0x8001ADBC
    // 0x8000AD88: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001ADBC(rdram, ctx);
        goto after_50;
    // 0x8000AD88: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_50:
    // 0x8000AD8C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000AD90: lw          $t0, -0x5B1C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B1C);
    // 0x8000AD94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000AD98: bne         $t0, $at, L_8000ADA4
    if (ctx->r8 != ctx->r1) {
        // 0x8000AD9C: nop
    
            goto L_8000ADA4;
    }
    // 0x8000AD9C: nop

    // 0x8000ADA0: sw          $zero, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = 0;
L_8000ADA4:
    // 0x8000ADA4: lw          $t1, 0x2A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000ADA8: nop

    // 0x8000ADAC: bne         $t1, $zero, L_8000AE60
    if (ctx->r9 != 0) {
        // 0x8000ADB0: nop
    
            goto L_8000AE60;
    }
    // 0x8000ADB0: nop

    // 0x8000ADB4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000ADB8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8000ADBC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000ADC0: lhu         $t3, 0xE68($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE68);
    // 0x8000ADC4: lhu         $t2, 0x8($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X8);
    // 0x8000ADC8: nop

    // 0x8000ADCC: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8000ADD0: beq         $t4, $zero, L_8000ADE8
    if (ctx->r12 == 0) {
        // 0x8000ADD4: nop
    
            goto L_8000ADE8;
    }
    // 0x8000ADD4: nop

    // 0x8000ADD8: lw          $t5, 0x2BC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000ADDC: nop

    // 0x8000ADE0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8000ADE4: sw          $t6, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r14;
L_8000ADE8:
    // 0x8000ADE8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000ADEC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8000ADF0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8000ADF4: lhu         $t0, 0xE74($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XE74);
    // 0x8000ADF8: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8000ADFC: nop

    // 0x8000AE00: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x8000AE04: beq         $t1, $zero, L_8000AE1C
    if (ctx->r9 == 0) {
        // 0x8000AE08: nop
    
            goto L_8000AE1C;
    }
    // 0x8000AE08: nop

    // 0x8000AE0C: lw          $t9, 0x2BC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000AE10: nop

    // 0x8000AE14: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8000AE18: sw          $t2, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r10;
L_8000AE1C:
    // 0x8000AE1C: lw          $t3, 0x2BC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000AE20: nop

    // 0x8000AE24: bgez        $t3, L_8000AE30
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000AE28: nop
    
            goto L_8000AE30;
    }
    // 0x8000AE28: nop

    // 0x8000AE2C: sw          $zero, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = 0;
L_8000AE30:
    // 0x8000AE30: lw          $t4, 0x2BC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000AE34: lw          $t5, 0x2B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000AE38: nop

    // 0x8000AE3C: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000AE40: bne         $at, $zero, L_8000AE58
    if (ctx->r1 != 0) {
        // 0x8000AE44: nop
    
            goto L_8000AE58;
    }
    // 0x8000AE44: nop

    // 0x8000AE48: lw          $t6, 0x2B8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000AE4C: nop

    // 0x8000AE50: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000AE54: sw          $t7, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r15;
L_8000AE58:
    // 0x8000AE58: b           L_8000AF18
    // 0x8000AE5C: nop

        goto L_8000AF18;
    // 0x8000AE5C: nop

L_8000AE60:
    // 0x8000AE60: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000AE64: lw          $t8, -0x5B1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B1C);
    // 0x8000AE68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AE6C: beq         $t8, $at, L_8000AF18
    if (ctx->r24 == ctx->r1) {
        // 0x8000AE70: nop
    
            goto L_8000AF18;
    }
    // 0x8000AE70: nop

    // 0x8000AE74: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000AE78: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8000AE7C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000AE80: lhu         $t9, 0xE68($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE68);
    // 0x8000AE84: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x8000AE88: nop

    // 0x8000AE8C: and         $t2, $t1, $t9
    ctx->r10 = ctx->r9 & ctx->r25;
    // 0x8000AE90: beq         $t2, $zero, L_8000AEA8
    if (ctx->r10 == 0) {
        // 0x8000AE94: nop
    
            goto L_8000AEA8;
    }
    // 0x8000AE94: nop

    // 0x8000AE98: lw          $t3, 0x2AC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AE9C: nop

    // 0x8000AEA0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000AEA4: sw          $t4, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r12;
L_8000AEA8:
    // 0x8000AEA8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000AEAC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8000AEB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000AEB4: lhu         $t7, 0xE74($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XE74);
    // 0x8000AEB8: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8000AEBC: nop

    // 0x8000AEC0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8000AEC4: beq         $t8, $zero, L_8000AEDC
    if (ctx->r24 == 0) {
        // 0x8000AEC8: nop
    
            goto L_8000AEDC;
    }
    // 0x8000AEC8: nop

    // 0x8000AECC: lw          $t0, 0x2AC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AED0: nop

    // 0x8000AED4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000AED8: sw          $t1, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r9;
L_8000AEDC:
    // 0x8000AEDC: lw          $t9, 0x2AC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AEE0: lw          $t2, 0x29C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X29C);
    // 0x8000AEE4: nop

    // 0x8000AEE8: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000AEEC: bne         $at, $zero, L_8000AF04
    if (ctx->r1 != 0) {
        // 0x8000AEF0: nop
    
            goto L_8000AF04;
    }
    // 0x8000AEF0: nop

    // 0x8000AEF4: lw          $t3, 0x29C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X29C);
    // 0x8000AEF8: nop

    // 0x8000AEFC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000AF00: sw          $t4, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r12;
L_8000AF04:
    // 0x8000AF04: lw          $t5, 0x2AC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AF08: nop

    // 0x8000AF0C: bgez        $t5, L_8000AF18
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000AF10: nop
    
            goto L_8000AF18;
    }
    // 0x8000AF10: nop

    // 0x8000AF14: sw          $zero, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = 0;
L_8000AF18:
    // 0x8000AF18: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8000AF1C: sw          $t6, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r14;
    // 0x8000AF20: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000AF24: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000AF28: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000AF2C: nop

    // 0x8000AF30: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x8000AF34: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x8000AF38: jal         0x80002824
    // 0x8000AF3C: nop

    func_80002824(rdram, ctx);
        goto after_51;
    // 0x8000AF3C: nop

    after_51:
    // 0x8000AF40: jal         0x8001635C
    // 0x8000AF44: nop

    func_8001635C(rdram, ctx);
        goto after_52;
    // 0x8000AF44: nop

    after_52:
    // 0x8000AF48: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8000AF4C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000AF50: lhu         $t9, 0x0($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X0);
    // 0x8000AF54: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000AF58: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x8000AF5C: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x8000AF60: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000AF64: jal         0x8009A664
    // 0x8000AF68: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_53;
    // 0x8000AF68: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_53:
    // 0x8000AF6C: b           L_8000B000
    // 0x8000AF70: nop

        goto L_8000B000;
    // 0x8000AF70: nop

L_8000AF74:
    // 0x8000AF74: lw          $t3, 0x2B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AF78: nop

    // 0x8000AF7C: slti        $at, $t3, 0x15
    ctx->r1 = SIGNED(ctx->r11) < 0X15 ? 1 : 0;
    // 0x8000AF80: bne         $at, $zero, L_8000AFC4
    if (ctx->r1 != 0) {
        // 0x8000AF84: nop
    
            goto L_8000AFC4;
    }
    // 0x8000AF84: nop

    // 0x8000AF88: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000AF8C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8000AF90: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000AF94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AF98: beq         $t5, $at, L_8000AFC4
    if (ctx->r13 == ctx->r1) {
        // 0x8000AF9C: nop
    
            goto L_8000AFC4;
    }
    // 0x8000AF9C: nop

    // 0x8000AFA0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000AFA4: lhu         $t8, 0x11A4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11A4);
    // 0x8000AFA8: lhu         $t6, 0x4($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X4);
    // 0x8000AFAC: nop

    // 0x8000AFB0: and         $t0, $t6, $t8
    ctx->r8 = ctx->r14 & ctx->r24;
    // 0x8000AFB4: beq         $t0, $zero, L_8000AFC4
    if (ctx->r8 == 0) {
        // 0x8000AFB8: nop
    
            goto L_8000AFC4;
    }
    // 0x8000AFB8: nop

    // 0x8000AFBC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000AFC0: sw          $t7, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r15;
L_8000AFC4:
    // 0x8000AFC4: lw          $t9, 0x2B0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AFC8: nop

    // 0x8000AFCC: bltz        $t9, L_8000AFE4
    if (SIGNED(ctx->r25) < 0) {
        // 0x8000AFD0: nop
    
            goto L_8000AFE4;
    }
    // 0x8000AFD0: nop

    // 0x8000AFD4: lw          $t2, 0x2B0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AFD8: nop

    // 0x8000AFDC: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8000AFE0: sw          $t1, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r9;
L_8000AFE4:
    // 0x8000AFE4: lw          $t3, 0x2B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AFE8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8000AFEC: bne         $t3, $at, L_8000B000
    if (ctx->r11 != ctx->r1) {
        // 0x8000AFF0: nop
    
            goto L_8000B000;
    }
    // 0x8000AFF0: nop

    // 0x8000AFF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000AFF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000AFFC: sw          $t5, -0x5B20($at)
    MEM_W(-0X5B20, ctx->r1) = ctx->r13;
L_8000B000:
    // 0x8000B000: jal         0x800BE610
    // 0x8000B004: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_54;
    // 0x8000B004: nop

    after_54:
    // 0x8000B008: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000B00C: lw          $t4, 0x1B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B4C);
    // 0x8000B010: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000B014: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x8000B018: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000B01C: jal         0x8009908C
    // 0x8000B020: subu        $a1, $t6, $t4
    ctx->r5 = SUB32(ctx->r14, ctx->r12);
    CreateGfxTask(rdram, ctx);
        goto after_55;
    // 0x8000B020: subu        $a1, $t6, $t4
    ctx->r5 = SUB32(ctx->r14, ctx->r12);
    after_55:
    // 0x8000B024: lw          $t8, 0x284($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X284);
    // 0x8000B028: nop

    // 0x8000B02C: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000B030: jal         0x80098D24
    // 0x8000B034: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_56;
    // 0x8000B034: nop

    after_56:
    // 0x8000B038: jal         0x80099450
    // 0x8000B03C: nop

    func_80099450(rdram, ctx);
        goto after_57;
    // 0x8000B03C: nop

    after_57:
    // 0x8000B040: lw          $t0, 0x280($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X280);
    // 0x8000B044: nop

    // 0x8000B048: addiu       $t7, $t0, 0x7FFF
    ctx->r15 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B04C: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x8000B050: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B054: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000B058: sw          $t9, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r25;
L_8000B05C:
    // 0x8000B05C: b           L_8000B0B0
    // 0x8000B060: nop

        goto L_8000B0B0;
    // 0x8000B060: nop

L_8000B064:
    // 0x8000B064: jal         0x80099520
    // 0x8000B068: nop

    func_80099520(rdram, ctx);
        goto after_58;
    // 0x8000B068: nop

    after_58:
    // 0x8000B06C: lw          $t2, 0x280($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X280);
    // 0x8000B070: nop

    // 0x8000B074: addiu       $t1, $t2, 0x7FFF
    ctx->r9 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000B078: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8000B07C: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000B080: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8000B084: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x8000B088: b           L_8000B0B0
    // 0x8000B08C: nop

        goto L_8000B0B0;
    // 0x8000B08C: nop

L_8000B090:
    // 0x8000B090: jal         0x800029BC
    // 0x8000B094: nop

    func_800029BC(rdram, ctx);
        goto after_59;
    // 0x8000B094: nop

    after_59:
L_8000B098:
    // 0x8000B098: b           L_8000B098
    pause_self(rdram);
    // 0x8000B09C: nop

    // 0x8000B0A0: b           L_8000B0B0
    // 0x8000B0A4: nop

        goto L_8000B0B0;
    // 0x8000B0A4: nop

L_8000B0A8:
    // 0x8000B0A8: b           L_8000B0B0
    // 0x8000B0AC: nop

        goto L_8000B0B0;
    // 0x8000B0AC: nop

L_8000B0B0:
    // 0x8000B0B0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000B0B4: lw          $t5, -0x5B20($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B20);
    // 0x8000B0B8: nop

    // 0x8000B0BC: beq         $t5, $zero, L_8000A4BC
    if (ctx->r13 == 0) {
        // 0x8000B0C0: nop
    
            goto L_8000A4BC;
    }
    // 0x8000B0C0: nop

L_8000B0C4:
    // 0x8000B0C4: lw          $t6, 0x280($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X280);
    // 0x8000B0C8: nop

    // 0x8000B0CC: addiu       $t4, $t6, 0x7FFF
    ctx->r12 = ADD32(ctx->r14, 0X7FFF);
    // 0x8000B0D0: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x8000B0D4: nop

    // 0x8000B0D8: blez        $t4, L_8000B15C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000B0DC: nop
    
            goto L_8000B15C;
    }
    // 0x8000B0DC: nop

L_8000B0E0:
    // 0x8000B0E0: lw          $t8, 0x284($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X284);
    // 0x8000B0E4: addiu       $a1, $sp, 0x27C
    ctx->r5 = ADD32(ctx->r29, 0X27C);
    // 0x8000B0E8: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000B0EC: jal         0x800C143C
    // 0x8000B0F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_60;
    // 0x8000B0F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_60:
    // 0x8000B0F4: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8000B0F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B0FC: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x8000B100: nop

    // 0x8000B104: bne         $t9, $at, L_8000B140
    if (ctx->r25 != ctx->r1) {
        // 0x8000B108: nop
    
            goto L_8000B140;
    }
    // 0x8000B108: nop

    // 0x8000B10C: b           L_8000B114
    // 0x8000B110: nop

        goto L_8000B114;
    // 0x8000B110: nop

L_8000B114:
    // 0x8000B114: jal         0x80099520
    // 0x8000B118: nop

    func_80099520(rdram, ctx);
        goto after_61;
    // 0x8000B118: nop

    after_61:
    // 0x8000B11C: lw          $t0, 0x280($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X280);
    // 0x8000B120: nop

    // 0x8000B124: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B128: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8000B12C: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B130: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8000B134: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x8000B138: b           L_8000B140
    // 0x8000B13C: nop

        goto L_8000B140;
    // 0x8000B13C: nop

L_8000B140:
    // 0x8000B140: lw          $t2, 0x280($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X280);
    // 0x8000B144: nop

    // 0x8000B148: addiu       $t5, $t2, 0x7FFF
    ctx->r13 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000B14C: lw          $t5, 0x2ED($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2ED);
    // 0x8000B150: nop

    // 0x8000B154: bgtz        $t5, L_8000B0E0
    if (SIGNED(ctx->r13) > 0) {
        // 0x8000B158: nop
    
            goto L_8000B0E0;
    }
    // 0x8000B158: nop

L_8000B15C:
    // 0x8000B15C: jal         0x80098820
    // 0x8000B160: nop

    func_80098820(rdram, ctx);
        goto after_62;
    // 0x8000B160: nop

    after_62:
    // 0x8000B164: jal         0x80098868
    // 0x8000B168: nop

    func_80098868(rdram, ctx);
        goto after_63;
    // 0x8000B168: nop

    after_63:
    // 0x8000B16C: jal         0x8001AE90
    // 0x8000B170: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001AE90(rdram, ctx);
        goto after_64;
    // 0x8000B170: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_64:
    // 0x8000B174: b           L_8000B184
    // 0x8000B178: nop

        goto L_8000B184;
    // 0x8000B178: nop

    // 0x8000B17C: b           L_8000B184
    // 0x8000B180: nop

        goto L_8000B184;
    // 0x8000B180: nop

L_8000B184:
    // 0x8000B184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B18C: jr          $ra
    // 0x8000B190: addiu       $sp, $sp, 0x2C8
    ctx->r29 = ADD32(ctx->r29, 0X2C8);
    return;
    // 0x8000B190: addiu       $sp, $sp, 0x2C8
    ctx->r29 = ADD32(ctx->r29, 0X2C8);
;}
RECOMP_FUNC void __initFromBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D20A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D20A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D20AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D20B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D20B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D20B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D20BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D20C0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D20C4: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
L_800D20C8:
    // 0x800D20C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D20CC: beql        $s1, $zero, L_800D20C8
    if (ctx->r17 == 0) {
        // 0x800D20D0: lw          $s1, 0xC($v0)
        ctx->r17 = MEM_W(ctx->r2, 0XC);
            goto L_800D20C8;
    }
    goto skip_0;
    // 0x800D20D0: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x800D20D4: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x800D20D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D20DC: blez        $t6, L_800D2110
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D20E0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D2110;
    }
    // 0x800D20E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D20E4:
    // 0x800D20E4: jal         0x800D2024
    // 0x800D20E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x800D20E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800D20EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D20F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D20F4: jal         0x800D1FD0
    // 0x800D20F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    __setInstChanState(rdram, ctx);
        goto after_1;
    // 0x800D20F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800D20FC: lbu         $t7, 0x34($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X34);
    // 0x800D2100: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D2104: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D2108: bnel        $at, $zero, L_800D20E4
    if (ctx->r1 != 0) {
        // 0x800D210C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D20E4;
    }
    goto skip_1;
    // 0x800D210C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_800D2110:
    // 0x800D2110: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2114: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D2118: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800D211C: beql        $t9, $zero, L_800D2144
    if (ctx->r25 == 0) {
        // 0x800D2120: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2144;
    }
    goto skip_2;
    // 0x800D2120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800D2124: jal         0x800D2024
    // 0x800D2128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_2;
    // 0x800D2128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800D212C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D2134: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x800D2138: jal         0x800D1FD0
    // 0x800D213C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    __setInstChanState(rdram, ctx);
        goto after_3;
    // 0x800D213C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x800D2140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2144:
    // 0x800D2144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D2148: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D214C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D2150: jr          $ra
    // 0x800D2154: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D2154: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005B994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B998: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005B99C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005B9A0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005B9A4: nop

    // 0x8005B9A8: bne         $a0, $t6, L_8005B9C0
    if (ctx->r4 != ctx->r14) {
        // 0x8005B9AC: nop
    
            goto L_8005B9C0;
    }
    // 0x8005B9AC: nop

    // 0x8005B9B0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005B9B4: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005B9B8: b           L_8005B9D0
    // 0x8005B9BC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
        goto L_8005B9D0;
    // 0x8005B9BC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_8005B9C0:
    // 0x8005B9C0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005B9C4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005B9C8: nop

    // 0x8005B9CC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_8005B9D0:
    // 0x8005B9D0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005B9D4: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005B9D8: nop

    // 0x8005B9DC: bne         $a0, $t9, L_8005B9F0
    if (ctx->r4 != ctx->r25) {
        // 0x8005B9E0: nop
    
            goto L_8005B9F0;
    }
    // 0x8005B9E0: nop

    // 0x8005B9E4: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8005B9E8: b           L_8005B9F8
    // 0x8005B9EC: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
        goto L_8005B9F8;
    // 0x8005B9EC: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
L_8005B9F0:
    // 0x8005B9F0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8005B9F4: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_8005B9F8:
    // 0x8005B9F8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005B9FC: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BA00: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005BA04: nop

    // 0x8005BA08: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005BA0C: nop

    // 0x8005BA10: bc1f        L_8005BA3C
    if (!c1cs) {
        // 0x8005BA14: nop
    
            goto L_8005BA3C;
    }
    // 0x8005BA14: nop

    // 0x8005BA18: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BA20: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8005BA24: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8005BA28: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005BA2C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005BA30: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8005BA34: b           L_8005BA54
    // 0x8005BA38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
        goto L_8005BA54;
    // 0x8005BA38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8005BA3C:
    // 0x8005BA3C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA40: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005BA44: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8005BA48: ori         $t1, $t9, 0x8
    ctx->r9 = ctx->r25 | 0X8;
    // 0x8005BA4C: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8005BA50: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8005BA54:
    // 0x8005BA54: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005BA58: nop

    // 0x8005BA5C: lh          $t2, 0xAC($t3)
    ctx->r10 = MEM_H(ctx->r11, 0XAC);
    // 0x8005BA60: nop

    // 0x8005BA64: andi        $t4, $t2, 0x40
    ctx->r12 = ctx->r10 & 0X40;
    // 0x8005BA68: beq         $t4, $zero, L_8005BA78
    if (ctx->r12 == 0) {
        // 0x8005BA6C: nop
    
            goto L_8005BA78;
    }
    // 0x8005BA6C: nop

    // 0x8005BA70: b           L_8005C2FC
    // 0x8005BA74: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_8005C2FC;
    // 0x8005BA74: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_8005BA78:
    // 0x8005BA78: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005BA7C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005BA80: nop

    // 0x8005BA84: bne         $a0, $t5, L_8005BB54
    if (ctx->r4 != ctx->r13) {
        // 0x8005BA88: nop
    
            goto L_8005BB54;
    }
    // 0x8005BA88: nop

    // 0x8005BA8C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005BA90: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005BA94: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BA98: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8005BA9C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005BAA0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005BAA4: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8005BAA8: nop

    // 0x8005BAAC: bc1f        L_8005BAC8
    if (!c1cs) {
        // 0x8005BAB0: nop
    
            goto L_8005BAC8;
    }
    // 0x8005BAB0: nop

    // 0x8005BAB4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BAB8: nop

    // 0x8005BABC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8005BAC0: b           L_8005BAE4
    // 0x8005BAC4: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
        goto L_8005BAE4;
    // 0x8005BAC4: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
L_8005BAC8:
    // 0x8005BAC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005BACC: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005BAD0: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BAD4: lwc1        $f16, 0xC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005BAD8: nop

    // 0x8005BADC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005BAE0: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
L_8005BAE4:
    // 0x8005BAE4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BAE8: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BAEC: lwc1        $f7, -0xE70($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XE70);
    // 0x8005BAF0: lwc1        $f6, -0xE6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XE6C);
    // 0x8005BAF4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BAF8: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005BAFC: nop

    // 0x8005BB00: bc1f        L_8005BB14
    if (!c1cs) {
        // 0x8005BB04: nop
    
            goto L_8005BB14;
    }
    // 0x8005BB04: nop

    // 0x8005BB08: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8005BB0C: b           L_8005BB4C
    // 0x8005BB10: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
        goto L_8005BB4C;
    // 0x8005BB10: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
L_8005BB14:
    // 0x8005BB14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BB18: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BB1C: lwc1        $f19, -0xE68($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XE68);
    // 0x8005BB20: lwc1        $f18, -0xE64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XE64);
    // 0x8005BB24: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005BB28: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8005BB2C: nop

    // 0x8005BB30: bc1f        L_8005BB44
    if (!c1cs) {
        // 0x8005BB34: nop
    
            goto L_8005BB44;
    }
    // 0x8005BB34: nop

    // 0x8005BB38: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8005BB3C: b           L_8005BB4C
    // 0x8005BB40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
        goto L_8005BB4C;
    // 0x8005BB40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_8005BB44:
    // 0x8005BB44: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8005BB48: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
L_8005BB4C:
    // 0x8005BB4C: b           L_8005BCF8
    // 0x8005BB50: nop

        goto L_8005BCF8;
    // 0x8005BB50: nop

L_8005BB54:
    // 0x8005BB54: lh          $t1, 0x7C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X7C);
    // 0x8005BB58: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005BB5C: bne         $t1, $at, L_8005BC28
    if (ctx->r9 != ctx->r1) {
        // 0x8005BB60: nop
    
            goto L_8005BC28;
    }
    // 0x8005BB60: nop

    // 0x8005BB64: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005BB68: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005BB6C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BB70: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x8005BB74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BB78: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8005BB7C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8005BB80: nop

    // 0x8005BB84: bc1f        L_8005BBA0
    if (!c1cs) {
        // 0x8005BB88: nop
    
            goto L_8005BBA0;
    }
    // 0x8005BB88: nop

    // 0x8005BB8C: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BB90: nop

    // 0x8005BB94: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8005BB98: b           L_8005BBBC
    // 0x8005BB9C: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
        goto L_8005BBBC;
    // 0x8005BB9C: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
L_8005BBA0:
    // 0x8005BBA0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005BBA4: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005BBA8: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BBAC: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005BBB0: nop

    // 0x8005BBB4: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005BBB8: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
L_8005BBBC:
    // 0x8005BBBC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BBC0: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BBC4: lwc1        $f19, -0xE60($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XE60);
    // 0x8005BBC8: lwc1        $f18, -0xE5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XE5C);
    // 0x8005BBCC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BBD0: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8005BBD4: nop

    // 0x8005BBD8: bc1f        L_8005BBE8
    if (!c1cs) {
        // 0x8005BBDC: nop
    
            goto L_8005BBE8;
    }
    // 0x8005BBDC: nop

    // 0x8005BBE0: b           L_8005BC20
    // 0x8005BBE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
        goto L_8005BC20;
    // 0x8005BBE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_8005BBE8:
    // 0x8005BBE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BBEC: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BBF0: lwc1        $f11, -0xE58($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XE58);
    // 0x8005BBF4: lwc1        $f10, -0xE54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE54);
    // 0x8005BBF8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BBFC: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8005BC00: nop

    // 0x8005BC04: bc1f        L_8005BC18
    if (!c1cs) {
        // 0x8005BC08: nop
    
            goto L_8005BC18;
    }
    // 0x8005BC08: nop

    // 0x8005BC0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005BC10: b           L_8005BC20
    // 0x8005BC14: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
        goto L_8005BC20;
    // 0x8005BC14: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
L_8005BC18:
    // 0x8005BC18: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005BC1C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
L_8005BC20:
    // 0x8005BC20: b           L_8005BCF8
    // 0x8005BC24: nop

        goto L_8005BCF8;
    // 0x8005BC24: nop

L_8005BC28:
    // 0x8005BC28: lh          $t6, 0x7C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X7C);
    // 0x8005BC2C: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8005BC30: bne         $t6, $at, L_8005BCF8
    if (ctx->r14 != ctx->r1) {
        // 0x8005BC34: nop
    
            goto L_8005BCF8;
    }
    // 0x8005BC34: nop

    // 0x8005BC38: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005BC3C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005BC40: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BC44: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005BC48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005BC4C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8005BC50: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8005BC54: nop

    // 0x8005BC58: bc1f        L_8005BC74
    if (!c1cs) {
        // 0x8005BC5C: nop
    
            goto L_8005BC74;
    }
    // 0x8005BC5C: nop

    // 0x8005BC60: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BC64: nop

    // 0x8005BC68: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005BC6C: b           L_8005BC90
    // 0x8005BC70: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
        goto L_8005BC90;
    // 0x8005BC70: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
L_8005BC74:
    // 0x8005BC74: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005BC78: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005BC7C: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BC80: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8005BC84: nop

    // 0x8005BC88: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005BC8C: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
L_8005BC90:
    // 0x8005BC90: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BC94: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BC98: lwc1        $f11, -0xE50($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XE50);
    // 0x8005BC9C: lwc1        $f10, -0xE4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE4C);
    // 0x8005BCA0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BCA4: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8005BCA8: nop

    // 0x8005BCAC: bc1f        L_8005BCC0
    if (!c1cs) {
        // 0x8005BCB0: nop
    
            goto L_8005BCC0;
    }
    // 0x8005BCB0: nop

    // 0x8005BCB4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005BCB8: b           L_8005BCF8
    // 0x8005BCBC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
        goto L_8005BCF8;
    // 0x8005BCBC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_8005BCC0:
    // 0x8005BCC0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BCC4: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BCC8: lwc1        $f5, -0xE48($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XE48);
    // 0x8005BCCC: lwc1        $f4, -0xE44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XE44);
    // 0x8005BCD0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005BCD4: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005BCD8: nop

    // 0x8005BCDC: bc1f        L_8005BCF0
    if (!c1cs) {
        // 0x8005BCE0: nop
    
            goto L_8005BCF0;
    }
    // 0x8005BCE0: nop

    // 0x8005BCE4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8005BCE8: b           L_8005BCF8
    // 0x8005BCEC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
        goto L_8005BCF8;
    // 0x8005BCEC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
L_8005BCF0:
    // 0x8005BCF0: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8005BCF4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
L_8005BCF8:
    // 0x8005BCF8: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x8005BCFC: nop

    // 0x8005BD00: andi        $t2, $t3, 0x3
    ctx->r10 = ctx->r11 & 0X3;
    // 0x8005BD04: beq         $t2, $zero, L_8005BDDC
    if (ctx->r10 == 0) {
        // 0x8005BD08: nop
    
            goto L_8005BDDC;
    }
    // 0x8005BD08: nop

    // 0x8005BD0C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005BD10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005BD14: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BD18: nop

    // 0x8005BD1C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8005BD20: nop

    // 0x8005BD24: bc1f        L_8005BD48
    if (!c1cs) {
        // 0x8005BD28: nop
    
            goto L_8005BD48;
    }
    // 0x8005BD28: nop

    // 0x8005BD2C: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8005BD30: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD34: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005BD38: bne         $t6, $zero, L_8005BD84
    if (ctx->r14 != 0) {
        // 0x8005BD3C: andi        $t7, $t5, 0x8
        ctx->r15 = ctx->r13 & 0X8;
            goto L_8005BD84;
    }
    // 0x8005BD3C: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x8005BD40: bne         $t7, $zero, L_8005BD84
    if (ctx->r15 != 0) {
        // 0x8005BD44: nop
    
            goto L_8005BD84;
    }
    // 0x8005BD44: nop

L_8005BD48:
    // 0x8005BD48: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8005BD4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005BD50: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BD54: nop

    // 0x8005BD58: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005BD5C: nop

    // 0x8005BD60: bc1f        L_8005BDDC
    if (!c1cs) {
        // 0x8005BD64: nop
    
            goto L_8005BDDC;
    }
    // 0x8005BD64: nop

    // 0x8005BD68: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005BD6C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005BD74: bne         $t0, $zero, L_8005BDDC
    if (ctx->r8 != 0) {
        // 0x8005BD78: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_8005BDDC;
    }
    // 0x8005BD78: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x8005BD7C: bne         $t1, $zero, L_8005BDDC
    if (ctx->r9 != 0) {
        // 0x8005BD80: nop
    
            goto L_8005BDDC;
    }
    // 0x8005BD80: nop

L_8005BD84:
    // 0x8005BD84: lh          $a3, 0x7C($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X7C);
    // 0x8005BD88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005BD8C: beq         $a3, $at, L_8005BDB4
    if (ctx->r7 == ctx->r1) {
        // 0x8005BD90: nop
    
            goto L_8005BDB4;
    }
    // 0x8005BD90: nop

    // 0x8005BD94: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005BD98: beq         $a3, $at, L_8005BDC4
    if (ctx->r7 == ctx->r1) {
        // 0x8005BD9C: nop
    
            goto L_8005BDC4;
    }
    // 0x8005BD9C: nop

    // 0x8005BDA0: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8005BDA4: beq         $a3, $at, L_8005BDD4
    if (ctx->r7 == ctx->r1) {
        // 0x8005BDA8: nop
    
            goto L_8005BDD4;
    }
    // 0x8005BDA8: nop

    // 0x8005BDAC: b           L_8005BDDC
    // 0x8005BDB0: nop

        goto L_8005BDDC;
    // 0x8005BDB0: nop

L_8005BDB4:
    // 0x8005BDB4: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8005BDB8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8005BDBC: b           L_8005BDDC
    // 0x8005BDC0: nop

        goto L_8005BDDC;
    // 0x8005BDC0: nop

L_8005BDC4:
    // 0x8005BDC4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8005BDC8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005BDCC: b           L_8005BDDC
    // 0x8005BDD0: nop

        goto L_8005BDDC;
    // 0x8005BDD0: nop

L_8005BDD4:
    // 0x8005BDD4: b           L_8005BDDC
    // 0x8005BDD8: nop

        goto L_8005BDDC;
    // 0x8005BDD8: nop

L_8005BDDC:
    // 0x8005BDDC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005BDE0: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x8005BDE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005BDE8: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x8005BDEC: mfhi        $t5
    ctx->r13 = hi;
    // 0x8005BDF0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8005BDF4: nop

    // 0x8005BDF8: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x8005BDFC: nop

    // 0x8005BE00: bgez        $t6, L_8005BE14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005BE04: andi        $t7, $t6, 0x3
        ctx->r15 = ctx->r14 & 0X3;
            goto L_8005BE14;
    }
    // 0x8005BE04: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8005BE08: beq         $t7, $zero, L_8005BE14
    if (ctx->r15 == 0) {
        // 0x8005BE0C: nop
    
            goto L_8005BE14;
    }
    // 0x8005BE0C: nop

    // 0x8005BE10: addiu       $t7, $t7, -0x4
    ctx->r15 = ADD32(ctx->r15, -0X4);
L_8005BE14:
    // 0x8005BE14: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8005BE18: beq         $at, $zero, L_8005BF20
    if (ctx->r1 == 0) {
        // 0x8005BE1C: nop
    
            goto L_8005BF20;
    }
    // 0x8005BE1C: nop

    // 0x8005BE20: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005BE24: nop

    // 0x8005BE28: lw          $t9, 0xA4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XA4);
    // 0x8005BE2C: nop

    // 0x8005BE30: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8005BE34: bne         $at, $zero, L_8005BF20
    if (ctx->r1 != 0) {
        // 0x8005BE38: nop
    
            goto L_8005BF20;
    }
    // 0x8005BE38: nop

    // 0x8005BE3C: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8005BE40: beq         $at, $zero, L_8005BF20
    if (ctx->r1 == 0) {
        // 0x8005BE44: nop
    
            goto L_8005BF20;
    }
    // 0x8005BE44: nop

    // 0x8005BE48: lh          $t0, 0xAC($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XAC);
    // 0x8005BE4C: nop

    // 0x8005BE50: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8005BE54: bne         $t1, $zero, L_8005BF20
    if (ctx->r9 != 0) {
        // 0x8005BE58: nop
    
            goto L_8005BF20;
    }
    // 0x8005BE58: nop

    // 0x8005BE5C: lh          $t3, 0xAC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XAC);
    // 0x8005BE60: nop

    // 0x8005BE64: ori         $t2, $t3, 0x10
    ctx->r10 = ctx->r11 | 0X10;
    // 0x8005BE68: sh          $t2, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r10;
    // 0x8005BE6C: lw          $t5, 0xB4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XB4);
    // 0x8005BE70: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005BE74: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x8005BE78: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x8005BE7C: bgez        $t6, L_8005BE8C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005BE80: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8005BE8C;
    }
    // 0x8005BE80: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005BE84: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8005BE88: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8005BE8C:
    // 0x8005BE8C: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005BE90: beq         $at, $zero, L_8005BF20
    if (ctx->r1 == 0) {
        // 0x8005BE94: nop
    
            goto L_8005BF20;
    }
    // 0x8005BE94: nop

    // 0x8005BE98: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005BE9C: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x8005BEA0: nop

    // 0x8005BEA4: bne         $a0, $t8, L_8005BEBC
    if (ctx->r4 != ctx->r24) {
        // 0x8005BEA8: nop
    
            goto L_8005BEBC;
    }
    // 0x8005BEA8: nop

    // 0x8005BEAC: b           L_8005C2FC
    // 0x8005BEB0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8005C2FC;
    // 0x8005BEB0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005BEB4: b           L_8005BF20
    // 0x8005BEB8: nop

        goto L_8005BF20;
    // 0x8005BEB8: nop

L_8005BEBC:
    // 0x8005BEBC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005BEC0: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005BEC4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005BEC8: lh          $t0, 0x7C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X7C);
    // 0x8005BECC: nop

    // 0x8005BED0: bne         $t0, $at, L_8005BEE0
    if (ctx->r8 != ctx->r1) {
        // 0x8005BED4: nop
    
            goto L_8005BEE0;
    }
    // 0x8005BED4: nop

    // 0x8005BED8: b           L_8005BEE8
    // 0x8005BEDC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_8005BEE8;
    // 0x8005BEDC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005BEE0:
    // 0x8005BEE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005BEE4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_8005BEE8:
    // 0x8005BEE8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005BEEC: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8005BEF0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8005BEF4: lw          $t6, 0xA4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XA4);
    // 0x8005BEF8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8005BEFC: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8005BF00: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005BF04: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x8005BF08: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8005BF0C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BF10: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8005BF14: lh          $v0, -0x2554($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2554);
    // 0x8005BF18: b           L_8005C2FC
    // 0x8005BF1C: nop

        goto L_8005C2FC;
    // 0x8005BF1C: nop

L_8005BF20:
    // 0x8005BF20: lw          $t8, 0xB4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB4);
    // 0x8005BF24: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x8005BF28: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8005BF2C: nop

    // 0x8005BF30: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8005BF34: bgez        $t1, L_8005BF44
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005BF38: sra         $t3, $t1, 2
        ctx->r11 = S32(SIGNED(ctx->r9) >> 2);
            goto L_8005BF44;
    }
    // 0x8005BF38: sra         $t3, $t1, 2
    ctx->r11 = S32(SIGNED(ctx->r9) >> 2);
    // 0x8005BF3C: addiu       $at, $t1, 0x3
    ctx->r1 = ADD32(ctx->r9, 0X3);
    // 0x8005BF40: sra         $t3, $at, 2
    ctx->r11 = S32(SIGNED(ctx->r1) >> 2);
L_8005BF44:
    // 0x8005BF44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005BF48: lw          $a3, 0x14($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14);
    // 0x8005BF4C: nop

    // 0x8005BF50: bgez        $a3, L_8005BF64
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8005BF54: andi        $t5, $a3, 0x3
        ctx->r13 = ctx->r7 & 0X3;
            goto L_8005BF64;
    }
    // 0x8005BF54: andi        $t5, $a3, 0x3
    ctx->r13 = ctx->r7 & 0X3;
    // 0x8005BF58: beq         $t5, $zero, L_8005BF64
    if (ctx->r13 == 0) {
        // 0x8005BF5C: nop
    
            goto L_8005BF64;
    }
    // 0x8005BF5C: nop

    // 0x8005BF60: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
L_8005BF64:
    // 0x8005BF64: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8005BF68: beq         $a3, $zero, L_8005C1A8
    if (ctx->r7 == 0) {
        // 0x8005BF6C: nop
    
            goto L_8005C1A8;
    }
    // 0x8005BF6C: nop

    // 0x8005BF70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005BF74: beq         $a3, $at, L_8005BFCC
    if (ctx->r7 == ctx->r1) {
        // 0x8005BF78: nop
    
            goto L_8005BFCC;
    }
    // 0x8005BF78: nop

    // 0x8005BF7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005BF80: beq         $a3, $at, L_8005BF9C
    if (ctx->r7 == ctx->r1) {
        // 0x8005BF84: nop
    
            goto L_8005BF9C;
    }
    // 0x8005BF84: nop

    // 0x8005BF88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005BF8C: beq         $a3, $at, L_8005BF9C
    if (ctx->r7 == ctx->r1) {
        // 0x8005BF90: nop
    
            goto L_8005BF9C;
    }
    // 0x8005BF90: nop

    // 0x8005BF94: b           L_8005C2F4
    // 0x8005BF98: nop

        goto L_8005C2F4;
    // 0x8005BF98: nop

L_8005BF9C:
    // 0x8005BF9C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x8005BFA0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BFA4: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8005BFA8: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8005BFAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8005BFB0: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8005BFB4: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8005BFB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BFBC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8005BFC0: lh          $v0, -0x268C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X268C);
    // 0x8005BFC4: b           L_8005C2FC
    // 0x8005BFC8: nop

        goto L_8005C2FC;
    // 0x8005BFC8: nop

L_8005BFCC:
    // 0x8005BFCC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8005BFD0: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x8005BFD4: nop

    // 0x8005BFD8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8005BFDC: addiu       $t3, $t1, 0xA
    ctx->r11 = ADD32(ctx->r9, 0XA);
    // 0x8005BFE0: div         $zero, $a1, $t3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r11)));
    // 0x8005BFE4: bne         $t3, $zero, L_8005BFF0
    if (ctx->r11 != 0) {
        // 0x8005BFE8: nop
    
            goto L_8005BFF0;
    }
    // 0x8005BFE8: nop

    // 0x8005BFEC: break       7
    do_break(2147860460);
L_8005BFF0:
    // 0x8005BFF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BFF4: bne         $t3, $at, L_8005C008
    if (ctx->r11 != ctx->r1) {
        // 0x8005BFF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005C008;
    }
    // 0x8005BFF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005BFFC: bne         $a1, $at, L_8005C008
    if (ctx->r5 != ctx->r1) {
        // 0x8005C000: nop
    
            goto L_8005C008;
    }
    // 0x8005C000: nop

    // 0x8005C004: break       6
    do_break(2147860484);
L_8005C008:
    // 0x8005C008: mfhi        $t5
    ctx->r13 = hi;
    // 0x8005C00C: bne         $t5, $zero, L_8005C02C
    if (ctx->r13 != 0) {
        // 0x8005C010: nop
    
            goto L_8005C02C;
    }
    // 0x8005C010: nop

    // 0x8005C014: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005C018: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005C01C: lw          $t4, 0xA4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XA4);
    // 0x8005C020: nop

    // 0x8005C024: bne         $t4, $at, L_8005C064
    if (ctx->r12 != ctx->r1) {
        // 0x8005C028: nop
    
            goto L_8005C064;
    }
    // 0x8005C028: nop

L_8005C02C:
    // 0x8005C02C: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8005C030: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C034: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8005C038: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x8005C03C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005C040: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8005C044: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8005C048: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C04C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8005C050: lh          $v0, -0x268C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X268C);
    // 0x8005C054: b           L_8005C2FC
    // 0x8005C058: nop

        goto L_8005C2FC;
    // 0x8005C058: nop

    // 0x8005C05C: b           L_8005C1A8
    // 0x8005C060: nop

        goto L_8005C1A8;
    // 0x8005C060: nop

L_8005C064:
    // 0x8005C064: lh          $t1, 0x7C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C06C: bne         $t1, $at, L_8005C138
    if (ctx->r9 != ctx->r1) {
        // 0x8005C070: nop
    
            goto L_8005C138;
    }
    // 0x8005C070: nop

    // 0x8005C074: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005C078: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005C07C: nop

    // 0x8005C080: lh          $t5, 0xE($t3)
    ctx->r13 = MEM_H(ctx->r11, 0XE);
    // 0x8005C084: nop

    // 0x8005C088: slti        $at, $t5, 0x190
    ctx->r1 = SIGNED(ctx->r13) < 0X190 ? 1 : 0;
    // 0x8005C08C: beq         $at, $zero, L_8005C0C0
    if (ctx->r1 == 0) {
        // 0x8005C090: nop
    
            goto L_8005C0C0;
    }
    // 0x8005C090: nop

    // 0x8005C094: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C098: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C09C: bgez        $t6, L_8005C0AC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005C0A0: sra         $t4, $t6, 1
        ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8005C0AC;
    }
    // 0x8005C0A0: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005C0A4: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8005C0A8: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8005C0AC:
    // 0x8005C0AC: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8005C0B0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8005C0B4: lh          $v0, -0x256A($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X256A);
    // 0x8005C0B8: b           L_8005C2FC
    // 0x8005C0BC: nop

        goto L_8005C2FC;
    // 0x8005C0BC: nop

L_8005C0C0:
    // 0x8005C0C0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005C0C4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005C0C8: nop

    // 0x8005C0CC: lh          $t7, 0xE($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XE);
    // 0x8005C0D0: nop

    // 0x8005C0D4: slti        $at, $t7, 0x2BC
    ctx->r1 = SIGNED(ctx->r15) < 0X2BC ? 1 : 0;
    // 0x8005C0D8: beq         $at, $zero, L_8005C10C
    if (ctx->r1 == 0) {
        // 0x8005C0DC: nop
    
            goto L_8005C10C;
    }
    // 0x8005C0DC: nop

    // 0x8005C0E0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C0E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C0E8: bgez        $t0, L_8005C0F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005C0EC: sra         $t9, $t0, 1
        ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8005C0F8;
    }
    // 0x8005C0EC: sra         $t9, $t0, 1
    ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005C0F0: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8005C0F4: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8005C0F8:
    // 0x8005C0F8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8005C0FC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8005C100: lh          $v0, -0x2560($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2560);
    // 0x8005C104: b           L_8005C2FC
    // 0x8005C108: nop

        goto L_8005C2FC;
    // 0x8005C108: nop

L_8005C10C:
    // 0x8005C10C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C110: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C114: bgez        $t3, L_8005C124
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8005C118: sra         $t5, $t3, 1
        ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8005C124;
    }
    // 0x8005C118: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005C11C: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8005C120: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8005C124:
    // 0x8005C124: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8005C128: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005C12C: lh          $v0, -0x2556($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2556);
    // 0x8005C130: b           L_8005C2FC
    // 0x8005C134: nop

        goto L_8005C2FC;
    // 0x8005C134: nop

L_8005C138:
    // 0x8005C138: lh          $t4, 0x7C($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C13C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005C140: bne         $t4, $at, L_8005C17C
    if (ctx->r12 != ctx->r1) {
        // 0x8005C144: nop
    
            goto L_8005C17C;
    }
    // 0x8005C144: nop

    // 0x8005C148: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C14C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C150: bgez        $t2, L_8005C160
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8005C154: sra         $t8, $t2, 1
        ctx->r24 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8005C160;
    }
    // 0x8005C154: sra         $t8, $t2, 1
    ctx->r24 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8005C158: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8005C15C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8005C160:
    // 0x8005C160: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8005C164: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8005C168: lh          $v0, -0x2592($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2592);
    // 0x8005C16C: b           L_8005C2FC
    // 0x8005C170: nop

        goto L_8005C2FC;
    // 0x8005C170: nop

    // 0x8005C174: b           L_8005C1A8
    // 0x8005C178: nop

        goto L_8005C1A8;
    // 0x8005C178: nop

L_8005C17C:
    // 0x8005C17C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C180: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C184: bgez        $t0, L_8005C194
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005C188: sra         $t9, $t0, 1
        ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8005C194;
    }
    // 0x8005C188: sra         $t9, $t0, 1
    ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005C18C: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8005C190: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8005C194:
    // 0x8005C194: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8005C198: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8005C19C: lh          $v0, -0x257E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X257E);
    // 0x8005C1A0: b           L_8005C2FC
    // 0x8005C1A4: nop

        goto L_8005C2FC;
    // 0x8005C1A4: nop

L_8005C1A8:
    // 0x8005C1A8: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8005C1AC: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x8005C1B0: nop

    // 0x8005C1B4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8005C1B8: div         $zero, $a1, $t6
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r14)));
    // 0x8005C1BC: bne         $t6, $zero, L_8005C1C8
    if (ctx->r14 != 0) {
        // 0x8005C1C0: nop
    
            goto L_8005C1C8;
    }
    // 0x8005C1C0: nop

    // 0x8005C1C4: break       7
    do_break(2147860932);
L_8005C1C8:
    // 0x8005C1C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005C1CC: bne         $t6, $at, L_8005C1E0
    if (ctx->r14 != ctx->r1) {
        // 0x8005C1D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005C1E0;
    }
    // 0x8005C1D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005C1D4: bne         $a1, $at, L_8005C1E0
    if (ctx->r5 != ctx->r1) {
        // 0x8005C1D8: nop
    
            goto L_8005C1E0;
    }
    // 0x8005C1D8: nop

    // 0x8005C1DC: break       6
    do_break(2147860956);
L_8005C1E0:
    // 0x8005C1E0: mfhi        $t4
    ctx->r12 = hi;
    // 0x8005C1E4: bne         $t4, $zero, L_8005C210
    if (ctx->r12 != 0) {
        // 0x8005C1E8: nop
    
            goto L_8005C210;
    }
    // 0x8005C1E8: nop

    // 0x8005C1EC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005C1F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005C1F4: lw          $t8, 0xA4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XA4);
    // 0x8005C1F8: nop

    // 0x8005C1FC: beq         $t8, $at, L_8005C210
    if (ctx->r24 == ctx->r1) {
        // 0x8005C200: nop
    
            goto L_8005C210;
    }
    // 0x8005C200: nop

    // 0x8005C204: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005C208: bne         $t8, $at, L_8005C248
    if (ctx->r24 != ctx->r1) {
        // 0x8005C20C: nop
    
            goto L_8005C248;
    }
    // 0x8005C20C: nop

L_8005C210:
    // 0x8005C210: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8005C214: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C218: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8005C21C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8005C220: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8005C224: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8005C228: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x8005C22C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C230: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8005C234: lh          $v0, -0x268C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X268C);
    // 0x8005C238: b           L_8005C2FC
    // 0x8005C23C: nop

        goto L_8005C2FC;
    // 0x8005C23C: nop

    // 0x8005C240: b           L_8005C2F4
    // 0x8005C244: nop

        goto L_8005C2F4;
    // 0x8005C244: nop

L_8005C248:
    // 0x8005C248: lh          $t5, 0x7C($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C24C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C250: bne         $t5, $at, L_8005C284
    if (ctx->r13 != ctx->r1) {
        // 0x8005C254: nop
    
            goto L_8005C284;
    }
    // 0x8005C254: nop

    // 0x8005C258: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C25C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C260: bgez        $t6, L_8005C270
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005C264: sra         $t4, $t6, 1
        ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8005C270;
    }
    // 0x8005C264: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005C268: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8005C26C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8005C270:
    // 0x8005C270: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8005C274: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8005C278: lh          $v0, -0x2574($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2574);
    // 0x8005C27C: b           L_8005C2FC
    // 0x8005C280: nop

        goto L_8005C2FC;
    // 0x8005C280: nop

L_8005C284:
    // 0x8005C284: lh          $t8, 0x7C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C288: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005C28C: bne         $t8, $at, L_8005C2C8
    if (ctx->r24 != ctx->r1) {
        // 0x8005C290: nop
    
            goto L_8005C2C8;
    }
    // 0x8005C290: nop

    // 0x8005C294: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C298: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C29C: bgez        $t7, L_8005C2AC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005C2A0: sra         $t9, $t7, 1
        ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8005C2AC;
    }
    // 0x8005C2A0: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005C2A4: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8005C2A8: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8005C2AC:
    // 0x8005C2AC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8005C2B0: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8005C2B4: lh          $v0, -0x259C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X259C);
    // 0x8005C2B8: b           L_8005C2FC
    // 0x8005C2BC: nop

        goto L_8005C2FC;
    // 0x8005C2BC: nop

    // 0x8005C2C0: b           L_8005C2F4
    // 0x8005C2C4: nop

        goto L_8005C2F4;
    // 0x8005C2C4: nop

L_8005C2C8:
    // 0x8005C2C8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C2CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C2D0: bgez        $t1, L_8005C2E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005C2D4: sra         $t3, $t1, 1
        ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8005C2E0;
    }
    // 0x8005C2D4: sra         $t3, $t1, 1
    ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8005C2D8: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8005C2DC: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8005C2E0:
    // 0x8005C2E0: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8005C2E4: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x8005C2E8: lh          $v0, -0x2588($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2588);
    // 0x8005C2EC: b           L_8005C2FC
    // 0x8005C2F0: nop

        goto L_8005C2FC;
    // 0x8005C2F0: nop

L_8005C2F4:
    // 0x8005C2F4: b           L_8005C2FC
    // 0x8005C2F8: nop

        goto L_8005C2FC;
    // 0x8005C2F8: nop

L_8005C2FC:
    // 0x8005C2FC: jr          $ra
    // 0x8005C300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005C300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void SysMem_HeapAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC6EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC6F0: addiu       $t6, $a0, 0xF
    ctx->r14 = ADD32(ctx->r4, 0XF);
    // 0x800BC6F4: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x800BC6F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BC6FC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800BC700: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BC704: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BC708: lw          $t0, 0x25E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X25E8);
    // 0x800BC70C: lw          $t9, 0x25DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25DC);
    // 0x800BC710: nop

    // 0x800BC714: beq         $t9, $t0, L_800BC900
    if (ctx->r25 == ctx->r8) {
        // 0x800BC718: sw          $t9, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r25;
            goto L_800BC900;
    }
    // 0x800BC718: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_800BC71C:
    // 0x800BC71C: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BC720: nop

    // 0x800BC724: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800BC728: nop

    // 0x800BC72C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800BC730: beq         $t3, $zero, L_800BC740
    if (ctx->r11 == 0) {
        // 0x800BC734: nop
    
            goto L_800BC740;
    }
    // 0x800BC734: nop

    // 0x800BC738: b           L_800BC8DC
    // 0x800BC73C: nop

        goto L_800BC8DC;
    // 0x800BC73C: nop

L_800BC740:
    // 0x800BC740: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800BC744: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800BC748: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800BC74C: nop

    // 0x800BC750: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x800BC754: bne         $at, $zero, L_800BC8DC
    if (ctx->r1 != 0) {
        // 0x800BC758: nop
    
            goto L_800BC8DC;
    }
    // 0x800BC758: nop

    // 0x800BC75C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800BC760: nop

    // 0x800BC764: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800BC768: nop

    // 0x800BC76C: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800BC770: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800BC774: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800BC778: nop

    // 0x800BC77C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x800BC780: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800BC784: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800BC788: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800BC78C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800BC790: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800BC794: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BC798: nop

    // 0x800BC79C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800BC7A0: nop

    // 0x800BC7A4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800BC7A8: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x800BC7AC: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7B0: nop

    // 0x800BC7B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800BC7B8: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7BC: nop

    // 0x800BC7C0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800BC7C4: nop

    // 0x800BC7C8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800BC7CC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BC7D0: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7D4: nop

    // 0x800BC7D8: beq         $t1, $t2, L_800BC8D0
    if (ctx->r9 == ctx->r10) {
        // 0x800BC7DC: nop
    
            goto L_800BC8D0;
    }
    // 0x800BC7DC: nop

    // 0x800BC7E0: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x800BC7E4: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7E8: nop

    // 0x800BC7EC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800BC7F0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800BC7F4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800BC7F8: nop

    // 0x800BC7FC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800BC800: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800BC804: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800BC808: nop

    // 0x800BC80C: subu        $t9, $t5, $t8
    ctx->r25 = SUB32(ctx->r13, ctx->r24);
    // 0x800BC810: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x800BC814: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x800BC818: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BC81C: nop

    // 0x800BC820: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
    // 0x800BC824: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800BC828: nop

    // 0x800BC82C: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x800BC830: nop

    // 0x800BC834: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800BC838: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BC83C: lw          $t6, 0x25E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25E8);
    // 0x800BC840: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BC844: nop

    // 0x800BC848: beq         $t3, $t6, L_800BC8D0
    if (ctx->r11 == ctx->r14) {
        // 0x800BC84C: nop
    
            goto L_800BC8D0;
    }
    // 0x800BC84C: nop

    // 0x800BC850: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BC854: nop

    // 0x800BC858: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x800BC85C: nop

    // 0x800BC860: andi        $t9, $t5, 0x1
    ctx->r25 = ctx->r13 & 0X1;
    // 0x800BC864: beq         $t9, $zero, L_800BC87C
    if (ctx->r25 == 0) {
        // 0x800BC868: nop
    
            goto L_800BC87C;
    }
    // 0x800BC868: nop

    // 0x800BC86C: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800BC870: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800BC874: b           L_800BC8D0
    // 0x800BC878: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
        goto L_800BC8D0;
    // 0x800BC878: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_800BC87C:
    // 0x800BC87C: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BC880: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800BC884: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800BC888: nop

    // 0x800BC88C: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800BC890: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800BC894: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BC898: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x800BC89C: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x800BC8A0: nop

    // 0x800BC8A4: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x800BC8A8: sw          $t9, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r25;
    // 0x800BC8AC: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8B0: nop

    // 0x800BC8B4: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x800BC8B8: nop

    // 0x800BC8BC: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800BC8C0: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8C4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BC8C8: nop

    // 0x800BC8CC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_800BC8D0:
    // 0x800BC8D0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800BC8D4: b           L_800BC910
    // 0x800BC8D8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
        goto L_800BC910;
    // 0x800BC8D8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_800BC8DC:
    // 0x800BC8DC: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8E0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BC8E4: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800BC8E8: lw          $t5, 0x25E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X25E8);
    // 0x800BC8EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800BC8F0: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800BC8F4: nop

    // 0x800BC8F8: bne         $t6, $t5, L_800BC71C
    if (ctx->r14 != ctx->r13) {
        // 0x800BC8FC: nop
    
            goto L_800BC71C;
    }
    // 0x800BC8FC: nop

L_800BC900:
    // 0x800BC900: b           L_800BC910
    // 0x800BC904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BC910;
    // 0x800BC904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC908: b           L_800BC910
    // 0x800BC90C: nop

        goto L_800BC910;
    // 0x800BC90C: nop

L_800BC910:
    // 0x800BC910: jr          $ra
    // 0x800BC914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800BC914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80067254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006725C: jal         0x80061488
    // 0x80067260: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067260: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80067264: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067268: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006726C: b           L_8006727C
    // 0x80067270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006727C;
    // 0x80067270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067274: b           L_8006727C
    // 0x80067278: nop

        goto L_8006727C;
    // 0x80067278: nop

L_8006727C:
    // 0x8006727C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067284: jr          $ra
    // 0x80067288: nop

    return;
    // 0x80067288: nop

;}
RECOMP_FUNC void func_8005031C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005031C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80050328: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005032C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80050330: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80050334: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80050338: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005033C: nop

    // 0x80050340: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80050344: nop

    // 0x80050348: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8005034C: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
    // 0x80050350: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050354: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050358: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005035C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80050360: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80050364: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80050368: bne         $t2, $zero, L_80050378
    if (ctx->r10 != 0) {
        // 0x8005036C: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80050378;
    }
    // 0x8005036C: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80050370: beq         $t3, $zero, L_800503A0
    if (ctx->r11 == 0) {
        // 0x80050374: nop
    
            goto L_800503A0;
    }
    // 0x80050374: nop

L_80050378:
    // 0x80050378: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005037C: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80050380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050384: bne         $t4, $at, L_800503A0
    if (ctx->r12 != ctx->r1) {
        // 0x80050388: nop
    
            goto L_800503A0;
    }
    // 0x80050388: nop

    // 0x8005038C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80050390: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80050394: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050398: beq         $t5, $at, L_800503F0
    if (ctx->r13 == ctx->r1) {
        // 0x8005039C: nop
    
            goto L_800503F0;
    }
    // 0x8005039C: nop

L_800503A0:
    // 0x800503A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800503A4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800503A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800503AC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800503B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800503B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800503B8: bne         $t0, $zero, L_800503C8
    if (ctx->r8 != 0) {
        // 0x800503BC: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_800503C8;
    }
    // 0x800503BC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800503C0: beq         $t1, $zero, L_80050788
    if (ctx->r9 == 0) {
        // 0x800503C4: nop
    
            goto L_80050788;
    }
    // 0x800503C4: nop

L_800503C8:
    // 0x800503C8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800503CC: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x800503D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800503D4: bne         $t7, $at, L_80050788
    if (ctx->r15 != ctx->r1) {
        // 0x800503D8: nop
    
            goto L_80050788;
    }
    // 0x800503D8: nop

    // 0x800503DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800503E0: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x800503E4: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x800503E8: bne         $t2, $at, L_80050788
    if (ctx->r10 != ctx->r1) {
        // 0x800503EC: nop
    
            goto L_80050788;
    }
    // 0x800503EC: nop

L_800503F0:
    // 0x800503F0: lh          $t3, 0x2A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A);
    // 0x800503F4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800503F8: beq         $t3, $at, L_80050424
    if (ctx->r11 == ctx->r1) {
        // 0x800503FC: nop
    
            goto L_80050424;
    }
    // 0x800503FC: nop

    // 0x80050400: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80050404: beq         $t3, $at, L_80050424
    if (ctx->r11 == ctx->r1) {
        // 0x80050408: nop
    
            goto L_80050424;
    }
    // 0x80050408: nop

    // 0x8005040C: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x80050410: beq         $t3, $at, L_80050424
    if (ctx->r11 == ctx->r1) {
        // 0x80050414: nop
    
            goto L_80050424;
    }
    // 0x80050414: nop

    // 0x80050418: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8005041C: bne         $t3, $at, L_80050788
    if (ctx->r11 != ctx->r1) {
        // 0x80050420: nop
    
            goto L_80050788;
    }
    // 0x80050420: nop

L_80050424:
    // 0x80050424: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80050428: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005042C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80050430: jal         0x800B334C
    // 0x80050434: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_0;
    // 0x80050434: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x80050438: andi        $t4, $v0, 0x2000
    ctx->r12 = ctx->r2 & 0X2000;
    // 0x8005043C: bne         $t4, $zero, L_80050470
    if (ctx->r12 != 0) {
        // 0x80050440: nop
    
            goto L_80050470;
    }
    // 0x80050440: nop

L_80050444:
    // 0x80050444: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050448: jal         0x800499B0
    // 0x8005044C: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8005044C: nop

    after_1:
    // 0x80050450: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80050454: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x80050458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005045C: jal         0x800B334C
    // 0x80050460: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_2;
    // 0x80050460: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_2:
    // 0x80050464: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
    // 0x80050468: beq         $t5, $zero, L_80050444
    if (ctx->r13 == 0) {
        // 0x8005046C: nop
    
            goto L_80050444;
    }
    // 0x8005046C: nop

L_80050470:
    // 0x80050470: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050474: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8005047C: lw          $t8, 0x58($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X58);
    // 0x80050480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050484: lbu         $a0, 0x16($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X16);
    // 0x80050488: jal         0x8008312C
    // 0x8005048C: nop

    func_8008312C(rdram, ctx);
        goto after_3;
    // 0x8005048C: nop

    after_3:
    // 0x80050490: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050494: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050498: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005049C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x800504A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800504A4: bne         $t2, $zero, L_800504E4
    if (ctx->r10 != 0) {
        // 0x800504A8: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_800504E4;
    }
    // 0x800504A8: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x800504AC: bne         $t3, $zero, L_800504E4
    if (ctx->r11 != 0) {
        // 0x800504B0: nop
    
            goto L_800504E4;
    }
    // 0x800504B0: nop

L_800504B4:
    // 0x800504B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800504B8: jal         0x800499B0
    // 0x800504BC: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x800504BC: nop

    after_4:
    // 0x800504C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800504C4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800504C8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800504CC: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x800504D0: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x800504D4: bne         $t6, $zero, L_800504E4
    if (ctx->r14 != 0) {
        // 0x800504D8: andi        $t7, $t5, 0x2
        ctx->r15 = ctx->r13 & 0X2;
            goto L_800504E4;
    }
    // 0x800504D8: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x800504DC: beq         $t7, $zero, L_800504B4
    if (ctx->r15 == 0) {
        // 0x800504E0: nop
    
            goto L_800504B4;
    }
    // 0x800504E0: nop

L_800504E4:
    // 0x800504E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800504E8: jal         0x800578E8
    // 0x800504EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_5;
    // 0x800504EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_5:
    // 0x800504F0: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x800504F4: jal         0x80056E88
    // 0x800504F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_6;
    // 0x800504F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800504FC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050500: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80050504: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80050508: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005050C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80050510: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80050514: lh          $a1, 0x42($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X42);
    // 0x80050518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005051C: jal         0x8004EF90
    // 0x80050520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_7;
    // 0x80050520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80050524: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050528: jal         0x800578E8
    // 0x8005052C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_800578E8(rdram, ctx);
        goto after_8;
    // 0x8005052C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_8:
    // 0x80050530: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80050534: jal         0x80056E88
    // 0x80050538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_9;
    // 0x80050538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8005053C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050540: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80050544: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80050548: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005054C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80050550: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80050554: lh          $a1, 0x42($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X42);
    // 0x80050558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005055C: jal         0x8004EF90
    // 0x80050560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_10;
    // 0x80050560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80050564: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050568: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005056C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80050570: lw          $t3, 0x58($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X58);
    // 0x80050574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050578: lbu         $a0, 0x16($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X16);
    // 0x8005057C: jal         0x8008312C
    // 0x80050580: nop

    func_8008312C(rdram, ctx);
        goto after_11;
    // 0x80050580: nop

    after_11:
    // 0x80050584: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050588: jal         0x800578E8
    // 0x8005058C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800578E8(rdram, ctx);
        goto after_12;
    // 0x8005058C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_12:
    // 0x80050590: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80050594: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050598: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x8005059C: nop

    // 0x800505A0: beq         $t5, $at, L_80050618
    if (ctx->r13 == ctx->r1) {
        // 0x800505A4: nop
    
            goto L_80050618;
    }
    // 0x800505A4: nop

    // 0x800505A8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800505AC: nop

    // 0x800505B0: beq         $t6, $zero, L_800505CC
    if (ctx->r14 == 0) {
        // 0x800505B4: nop
    
            goto L_800505CC;
    }
    // 0x800505B4: nop

    // 0x800505B8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800505BC: nop

    // 0x800505C0: lh          $s1, 0x2($t7)
    ctx->r17 = MEM_H(ctx->r15, 0X2);
    // 0x800505C4: b           L_800505DC
    // 0x800505C8: addiu       $s1, $s1, 0x2710
    ctx->r17 = ADD32(ctx->r17, 0X2710);
        goto L_800505DC;
    // 0x800505C8: addiu       $s1, $s1, 0x2710
    ctx->r17 = ADD32(ctx->r17, 0X2710);
L_800505CC:
    // 0x800505CC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800505D0: nop

    // 0x800505D4: lh          $s1, 0x2($t8)
    ctx->r17 = MEM_H(ctx->r24, 0X2);
    // 0x800505D8: nop

L_800505DC:
    // 0x800505DC: jal         0x80062678
    // 0x800505E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80062678(rdram, ctx);
        goto after_13;
    // 0x800505E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800505E4: jal         0x80031AC8
    // 0x800505E8: nop

    func_80031AC8(rdram, ctx);
        goto after_14;
    // 0x800505E8: nop

    after_14:
    // 0x800505EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800505F0: beq         $v0, $at, L_80050618
    if (ctx->r2 == ctx->r1) {
        // 0x800505F4: nop
    
            goto L_80050618;
    }
    // 0x800505F4: nop

L_800505F8:
    // 0x800505F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800505FC: jal         0x800499B0
    // 0x80050600: nop

    func_800499B0(rdram, ctx);
        goto after_15;
    // 0x80050600: nop

    after_15:
    // 0x80050604: jal         0x80031AC8
    // 0x80050608: nop

    func_80031AC8(rdram, ctx);
        goto after_16;
    // 0x80050608: nop

    after_16:
    // 0x8005060C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050610: bne         $v0, $at, L_800505F8
    if (ctx->r2 != ctx->r1) {
        // 0x80050614: nop
    
            goto L_800505F8;
    }
    // 0x80050614: nop

L_80050618:
    // 0x80050618: jal         0x80031AC8
    // 0x8005061C: nop

    func_80031AC8(rdram, ctx);
        goto after_17;
    // 0x8005061C: nop

    after_17:
    // 0x80050620: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80050624: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80050628: nop

    // 0x8005062C: beq         $t9, $zero, L_80050674
    if (ctx->r25 == 0) {
        // 0x80050630: nop
    
            goto L_80050674;
    }
    // 0x80050630: nop

    // 0x80050634: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80050638: beq         $t9, $at, L_80050674
    if (ctx->r25 == ctx->r1) {
        // 0x8005063C: nop
    
            goto L_80050674;
    }
    // 0x8005063C: nop

L_80050640:
    // 0x80050640: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050644: jal         0x800499B0
    // 0x80050648: nop

    func_800499B0(rdram, ctx);
        goto after_18;
    // 0x80050648: nop

    after_18:
    // 0x8005064C: jal         0x80031AC8
    // 0x80050650: nop

    func_80031AC8(rdram, ctx);
        goto after_19;
    // 0x80050650: nop

    after_19:
    // 0x80050654: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80050658: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005065C: nop

    // 0x80050660: beq         $t0, $zero, L_80050674
    if (ctx->r8 == 0) {
        // 0x80050664: nop
    
            goto L_80050674;
    }
    // 0x80050664: nop

    // 0x80050668: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8005066C: bne         $t0, $at, L_80050640
    if (ctx->r8 != ctx->r1) {
        // 0x80050670: nop
    
            goto L_80050640;
    }
    // 0x80050670: nop

L_80050674:
    // 0x80050674: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050678: jal         0x800578E8
    // 0x8005067C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_20;
    // 0x8005067C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_20:
    // 0x80050680: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050684: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050688: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8005068C: lw          $t2, 0x58($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X58);
    // 0x80050690: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050694: lbu         $a0, 0x16($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X16);
    // 0x80050698: jal         0x8008312C
    // 0x8005069C: nop

    func_8008312C(rdram, ctx);
        goto after_21;
    // 0x8005069C: nop

    after_21:
    // 0x800506A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800506A4: jal         0x800578E8
    // 0x800506A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_22;
    // 0x800506A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_22:
    // 0x800506AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800506B0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800506B4: nop

    // 0x800506B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800506BC: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800506C0: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x800506C4: xori        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 ^ 0X8;
    // 0x800506C8: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x800506CC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800506D0: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x800506D4: jal         0x80056E88
    // 0x800506D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_23;
    // 0x800506D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x800506DC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800506E0: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x800506E4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800506E8: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800506EC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800506F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800506F4: lh          $a1, 0x42($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X42);
    // 0x800506F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800506FC: jal         0x8004EF90
    // 0x80050700: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_24;
    // 0x80050700: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x80050704: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050708: jal         0x800578E8
    // 0x8005070C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_800578E8(rdram, ctx);
        goto after_25;
    // 0x8005070C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_25:
    // 0x80050710: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050714: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050718: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8005071C: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
    // 0x80050720: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80050724: jal         0x80056E88
    // 0x80050728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_26;
    // 0x80050728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x8005072C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050730: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x80050734: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80050738: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005073C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80050740: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80050744: lh          $a1, 0x42($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X42);
    // 0x80050748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005074C: jal         0x8004EF90
    // 0x80050750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_27;
    // 0x80050750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80050754: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80050758: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005075C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80050760: lw          $t6, 0x58($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X58);
    // 0x80050764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050768: lbu         $a0, 0x16($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X16);
    // 0x8005076C: jal         0x8008312C
    // 0x80050770: nop

    func_8008312C(rdram, ctx);
        goto after_28;
    // 0x80050770: nop

    after_28:
    // 0x80050774: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050778: jal         0x800578E8
    // 0x8005077C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_29;
    // 0x8005077C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_29:
    // 0x80050780: b           L_80050798
    // 0x80050784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80050798;
    // 0x80050784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050788:
    // 0x80050788: b           L_80050798
    // 0x8005078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050798;
    // 0x8005078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80050790: b           L_80050798
    // 0x80050794: nop

        goto L_80050798;
    // 0x80050794: nop

L_80050798:
    // 0x80050798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005079C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800507A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800507A4: jr          $ra
    // 0x800507A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800507A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80020720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020720: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80020724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80020728: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8002072C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80020730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80020734: jal         0x8008EAA8
    // 0x80020738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x80020738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8002073C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80020740: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020744: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80020748: jal         0x8008ECE4
    // 0x8002074C: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8002074C: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    after_1:
    // 0x80020750: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80020754: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x80020758: nop

    // 0x8002075C: beq         $s0, $zero, L_80020778
    if (ctx->r16 == 0) {
        // 0x80020760: nop
    
            goto L_80020778;
    }
    // 0x80020760: nop

    // 0x80020764: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020768: beq         $s0, $at, L_80020918
    if (ctx->r16 == ctx->r1) {
        // 0x8002076C: nop
    
            goto L_80020918;
    }
    // 0x8002076C: nop

    // 0x80020770: b           L_80021514
    // 0x80020774: nop

        goto L_80021514;
    // 0x80020774: nop

L_80020778:
    // 0x80020778: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002077C: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80020780: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80020784: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020788: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8002078C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80020790: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020794: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020798: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8002079C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x800207A0: jal         0x800BC6EC
    // 0x800207A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800207A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_2:
    // 0x800207A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800207AC: addiu       $t1, $t1, 0x2618
    ctx->r9 = ADD32(ctx->r9, 0X2618);
    // 0x800207B0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x800207B4: jal         0x800BC6EC
    // 0x800207B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800207B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x800207BC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800207C0: addiu       $t2, $t2, 0x2618
    ctx->r10 = ADD32(ctx->r10, 0X2618);
    // 0x800207C4: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800207C8: jal         0x800BC6EC
    // 0x800207CC: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800207CC: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    after_4:
    // 0x800207D0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800207D4: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x800207D8: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x800207DC: jal         0x800BC6EC
    // 0x800207E0: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x800207E0: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    after_5:
    // 0x800207E4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800207E8: addiu       $t4, $t4, 0x2618
    ctx->r12 = ADD32(ctx->r12, 0X2618);
    // 0x800207EC: sw          $v0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r2;
    // 0x800207F0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800207F4: addiu       $t5, $t5, 0x2618
    ctx->r13 = ADD32(ctx->r13, 0X2618);
    // 0x800207F8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800207FC: nop

    // 0x80020800: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80020804: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80020808: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8002080C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80020810: nop

    // 0x80020814: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80020818: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8002081C:
    // 0x8002081C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80020820: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80020824: nop

    // 0x80020828: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002082C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80020830: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80020834: nop

    // 0x80020838: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002083C: slti        $at, $t3, 0x11
    ctx->r1 = SIGNED(ctx->r11) < 0X11 ? 1 : 0;
    // 0x80020840: bne         $at, $zero, L_8002081C
    if (ctx->r1 != 0) {
        // 0x80020844: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_8002081C;
    }
    // 0x80020844: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80020848: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002084C: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x80020850: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80020854: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80020858: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8002085C: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x80020860: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80020864: addiu       $t8, $zero, 0x2C
    ctx->r24 = ADD32(0, 0X2C);
    // 0x80020868: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x8002086C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80020870: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80020874: sb          $t0, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r8;
    // 0x80020878: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002087C: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80020880: sb          $t2, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r10;
    // 0x80020884: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80020888: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x8002088C: sb          $t4, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r12;
    // 0x80020890: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80020894: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x80020898: sb          $t6, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r14;
    // 0x8002089C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800208A0: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800208A4: sb          $t8, 0x7($t9)
    MEM_B(0X7, ctx->r25) = ctx->r24;
    // 0x800208A8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800208AC:
    // 0x800208AC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800208B0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800208B4: nop

    // 0x800208B8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800208BC: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x800208C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800208C4: nop

    // 0x800208C8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800208CC: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x800208D0: bne         $at, $zero, L_800208AC
    if (ctx->r1 != 0) {
        // 0x800208D4: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_800208AC;
    }
    // 0x800208D4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800208D8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800208DC:
    // 0x800208DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800208E0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800208E4: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x800208E8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800208EC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800208F0: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800208F4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800208F8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800208FC: nop

    // 0x80020900: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80020904: slti        $at, $t1, 0x1600
    ctx->r1 = SIGNED(ctx->r9) < 0X1600 ? 1 : 0;
    // 0x80020908: bne         $at, $zero, L_800208DC
    if (ctx->r1 != 0) {
        // 0x8002090C: sw          $t1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r9;
            goto L_800208DC;
    }
    // 0x8002090C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80020910: b           L_80021514
    // 0x80020914: nop

        goto L_80021514;
    // 0x80020914: nop

L_80020918:
    // 0x80020918: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002091C: addiu       $t2, $t2, 0x2618
    ctx->r10 = ADD32(ctx->r10, 0X2618);
    // 0x80020920: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80020924: nop

    // 0x80020928: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8002092C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80020930: addiu       $t4, $t4, 0x2618
    ctx->r12 = ADD32(ctx->r12, 0X2618);
    // 0x80020934: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80020938: nop

    // 0x8002093C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80020940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80020944: jal         0x8008EAA8
    // 0x80020948: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x80020948: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x8002094C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020950: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x80020954: nop

    // 0x80020958: andi        $t5, $t8, 0x1
    ctx->r13 = ctx->r24 & 0X1;
    // 0x8002095C: beq         $t5, $zero, L_80020978
    if (ctx->r13 == 0) {
        // 0x80020960: nop
    
            goto L_80020978;
    }
    // 0x80020960: nop

    // 0x80020964: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020968: jal         0x8008ECE4
    // 0x8002096C: addiu       $a0, $a0, -0x2384
    ctx->r4 = ADD32(ctx->r4, -0X2384);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8002096C: addiu       $a0, $a0, -0x2384
    ctx->r4 = ADD32(ctx->r4, -0X2384);
    after_7:
    // 0x80020970: b           L_80020984
    // 0x80020974: nop

        goto L_80020984;
    // 0x80020974: nop

L_80020978:
    // 0x80020978: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002097C: jal         0x8008ECE4
    // 0x80020980: addiu       $a0, $a0, -0x2368
    ctx->r4 = ADD32(ctx->r4, -0X2368);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x80020980: addiu       $a0, $a0, -0x2368
    ctx->r4 = ADD32(ctx->r4, -0X2368);
    after_8:
L_80020984:
    // 0x80020984: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80020988: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x8002098C: nop

    // 0x80020990: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x80020994: beq         $t9, $zero, L_800209B8
    if (ctx->r25 == 0) {
        // 0x80020998: nop
    
            goto L_800209B8;
    }
    // 0x80020998: nop

    // 0x8002099C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800209A0: lw          $a1, 0x1638($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1638);
    // 0x800209A4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800209A8: jal         0x8008ECE4
    // 0x800209AC: addiu       $a0, $a0, -0x234C
    ctx->r4 = ADD32(ctx->r4, -0X234C);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x800209AC: addiu       $a0, $a0, -0x234C
    ctx->r4 = ADD32(ctx->r4, -0X234C);
    after_9:
    // 0x800209B0: b           L_800209C4
    // 0x800209B4: nop

        goto L_800209C4;
    // 0x800209B4: nop

L_800209B8:
    // 0x800209B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800209BC: jal         0x8008ECE4
    // 0x800209C0: addiu       $a0, $a0, -0x2324
    ctx->r4 = ADD32(ctx->r4, -0X2324);
    func_8008ECE4(rdram, ctx);
        goto after_10;
    // 0x800209C0: addiu       $a0, $a0, -0x2324
    ctx->r4 = ADD32(ctx->r4, -0X2324);
    after_10:
L_800209C4:
    // 0x800209C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800209C8: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x800209CC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800209D0: nop

    // 0x800209D4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800209D8: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x800209DC: beq         $at, $zero, L_80021220
    if (ctx->r1 == 0) {
        // 0x800209E0: nop
    
            goto L_80021220;
    }
    // 0x800209E0: nop

    // 0x800209E4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800209E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800209EC: addu        $at, $at, $t2
    gpr jr_addend_800209F8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800209F0: lw          $t2, -0x1E84($at)
    ctx->r10 = ADD32(ctx->r1, -0X1E84);
    // 0x800209F4: nop

    // 0x800209F8: jr          $t2
    // 0x800209FC: nop

    switch (jr_addend_800209F8 >> 2) {
        case 0: goto L_80020A00; break;
        case 1: goto L_80020BD0; break;
        case 2: goto L_80020D4C; break;
        case 3: goto L_80020EAC; break;
        case 4: goto L_80021090; break;
        default: switch_error(__func__, 0x800209F8, 0x800EE17C);
    }
    // 0x800209FC: nop

L_80020A00:
    // 0x80020A00: jal         0x800AEA0C
    // 0x80020A04: nop

    ContPak_GetOpenFileResult(rdram, ctx);
        goto after_11;
    // 0x80020A04: nop

    after_11:
    // 0x80020A08: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020A0C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020A10: nop

    // 0x80020A14: slti        $at, $t3, 0x1001
    ctx->r1 = SIGNED(ctx->r11) < 0X1001 ? 1 : 0;
    // 0x80020A18: bne         $at, $zero, L_80020B7C
    if (ctx->r1 != 0) {
        // 0x80020A1C: nop
    
            goto L_80020B7C;
    }
    // 0x80020A1C: nop

    // 0x80020A20: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80020A24: nop

    // 0x80020A28: addiu       $t7, $t4, -0x1000
    ctx->r15 = ADD32(ctx->r12, -0X1000);
    // 0x80020A2C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80020A30: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020A34: nop

    // 0x80020A38: addiu       $t5, $t8, -0x1
    ctx->r13 = ADD32(ctx->r24, -0X1);
    // 0x80020A3C: sltiu       $at, $t5, 0x9
    ctx->r1 = ctx->r13 < 0X9 ? 1 : 0;
    // 0x80020A40: beq         $at, $zero, L_80020B44
    if (ctx->r1 == 0) {
        // 0x80020A44: nop
    
            goto L_80020B44;
    }
    // 0x80020A44: nop

    // 0x80020A48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80020A4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020A50: addu        $at, $at, $t5
    gpr jr_addend_80020A5C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80020A54: lw          $t5, -0x1E70($at)
    ctx->r13 = ADD32(ctx->r1, -0X1E70);
    // 0x80020A58: nop

    // 0x80020A5C: jr          $t5
    // 0x80020A60: nop

    switch (jr_addend_80020A5C >> 2) {
        case 0: goto L_80020AE0; break;
        case 1: goto L_80020AF4; break;
        case 2: goto L_80020B08; break;
        case 3: goto L_80020A64; break;
        case 4: goto L_80020A78; break;
        case 5: goto L_80020B44; break;
        case 6: goto L_80020B30; break;
        case 7: goto L_80020B1C; break;
        case 8: goto L_80020A8C; break;
        default: switch_error(__func__, 0x80020A5C, 0x800EE190);
    }
    // 0x80020A60: nop

L_80020A64:
    // 0x80020A64: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020A68: jal         0x8008ECE4
    // 0x80020A6C: addiu       $a0, $a0, -0x22FC
    ctx->r4 = ADD32(ctx->r4, -0X22FC);
    func_8008ECE4(rdram, ctx);
        goto after_12;
    // 0x80020A6C: addiu       $a0, $a0, -0x22FC
    ctx->r4 = ADD32(ctx->r4, -0X22FC);
    after_12:
    // 0x80020A70: b           L_80020B5C
    // 0x80020A74: nop

        goto L_80020B5C;
    // 0x80020A74: nop

L_80020A78:
    // 0x80020A78: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020A7C: jal         0x8008ECE4
    // 0x80020A80: addiu       $a0, $a0, -0x22E4
    ctx->r4 = ADD32(ctx->r4, -0X22E4);
    func_8008ECE4(rdram, ctx);
        goto after_13;
    // 0x80020A80: addiu       $a0, $a0, -0x22E4
    ctx->r4 = ADD32(ctx->r4, -0X22E4);
    after_13:
    // 0x80020A84: b           L_80020B5C
    // 0x80020A88: nop

        goto L_80020B5C;
    // 0x80020A88: nop

L_80020A8C:
    // 0x80020A8C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020A90: jal         0x8008ECE4
    // 0x80020A94: addiu       $a0, $a0, -0x22CC
    ctx->r4 = ADD32(ctx->r4, -0X22CC);
    func_8008ECE4(rdram, ctx);
        goto after_14;
    // 0x80020A94: addiu       $a0, $a0, -0x22CC
    ctx->r4 = ADD32(ctx->r4, -0X22CC);
    after_14:
    // 0x80020A98: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80020A9C: nop

    // 0x80020AA0: lbu         $t9, 0x8($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X8);
    // 0x80020AA4: nop

    // 0x80020AA8: bne         $t9, $zero, L_80020AC0
    if (ctx->r25 != 0) {
        // 0x80020AAC: nop
    
            goto L_80020AC0;
    }
    // 0x80020AAC: nop

    // 0x80020AB0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80020AB4: addiu       $t0, $zero, 0x1A
    ctx->r8 = ADD32(0, 0X1A);
    // 0x80020AB8: b           L_80020AD8
    // 0x80020ABC: sb          $t0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r8;
        goto L_80020AD8;
    // 0x80020ABC: sb          $t0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r8;
L_80020AC0:
    // 0x80020AC0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80020AC4: nop

    // 0x80020AC8: lbu         $t3, 0x8($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X8);
    // 0x80020ACC: nop

    // 0x80020AD0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80020AD4: sb          $t4, 0x8($t2)
    MEM_B(0X8, ctx->r10) = ctx->r12;
L_80020AD8:
    // 0x80020AD8: b           L_80020B5C
    // 0x80020ADC: nop

        goto L_80020B5C;
    // 0x80020ADC: nop

L_80020AE0:
    // 0x80020AE0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020AE4: jal         0x8008ECE4
    // 0x80020AE8: addiu       $a0, $a0, -0x22B4
    ctx->r4 = ADD32(ctx->r4, -0X22B4);
    func_8008ECE4(rdram, ctx);
        goto after_15;
    // 0x80020AE8: addiu       $a0, $a0, -0x22B4
    ctx->r4 = ADD32(ctx->r4, -0X22B4);
    after_15:
    // 0x80020AEC: b           L_80020B5C
    // 0x80020AF0: nop

        goto L_80020B5C;
    // 0x80020AF0: nop

L_80020AF4:
    // 0x80020AF4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020AF8: jal         0x8008ECE4
    // 0x80020AFC: addiu       $a0, $a0, -0x229C
    ctx->r4 = ADD32(ctx->r4, -0X229C);
    func_8008ECE4(rdram, ctx);
        goto after_16;
    // 0x80020AFC: addiu       $a0, $a0, -0x229C
    ctx->r4 = ADD32(ctx->r4, -0X229C);
    after_16:
    // 0x80020B00: b           L_80020B5C
    // 0x80020B04: nop

        goto L_80020B5C;
    // 0x80020B04: nop

L_80020B08:
    // 0x80020B08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B0C: jal         0x8008ECE4
    // 0x80020B10: addiu       $a0, $a0, -0x2284
    ctx->r4 = ADD32(ctx->r4, -0X2284);
    func_8008ECE4(rdram, ctx);
        goto after_17;
    // 0x80020B10: addiu       $a0, $a0, -0x2284
    ctx->r4 = ADD32(ctx->r4, -0X2284);
    after_17:
    // 0x80020B14: b           L_80020B5C
    // 0x80020B18: nop

        goto L_80020B5C;
    // 0x80020B18: nop

L_80020B1C:
    // 0x80020B1C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B20: jal         0x8008ECE4
    // 0x80020B24: addiu       $a0, $a0, -0x226C
    ctx->r4 = ADD32(ctx->r4, -0X226C);
    func_8008ECE4(rdram, ctx);
        goto after_18;
    // 0x80020B24: addiu       $a0, $a0, -0x226C
    ctx->r4 = ADD32(ctx->r4, -0X226C);
    after_18:
    // 0x80020B28: b           L_80020B5C
    // 0x80020B2C: nop

        goto L_80020B5C;
    // 0x80020B2C: nop

L_80020B30:
    // 0x80020B30: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B34: jal         0x8008ECE4
    // 0x80020B38: addiu       $a0, $a0, -0x2254
    ctx->r4 = ADD32(ctx->r4, -0X2254);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x80020B38: addiu       $a0, $a0, -0x2254
    ctx->r4 = ADD32(ctx->r4, -0X2254);
    after_19:
    // 0x80020B3C: b           L_80020B5C
    // 0x80020B40: nop

        goto L_80020B5C;
    // 0x80020B40: nop

L_80020B44:
    // 0x80020B44: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B48: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020B4C: jal         0x8008ECE4
    // 0x80020B50: addiu       $a0, $a0, -0x223C
    ctx->r4 = ADD32(ctx->r4, -0X223C);
    func_8008ECE4(rdram, ctx);
        goto after_20;
    // 0x80020B50: addiu       $a0, $a0, -0x223C
    ctx->r4 = ADD32(ctx->r4, -0X223C);
    after_20:
    // 0x80020B54: b           L_80020B5C
    // 0x80020B58: nop

        goto L_80020B5C;
    // 0x80020B58: nop

L_80020B5C:
    // 0x80020B5C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020B60: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80020B64: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80020B68: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80020B6C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020B70: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020B74: b           L_80020BC8
    // 0x80020B78: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
        goto L_80020BC8;
    // 0x80020B78: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80020B7C:
    // 0x80020B7C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80020B80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020B84: beq         $t6, $at, L_80020BC8
    if (ctx->r14 == ctx->r1) {
        // 0x80020B88: nop
    
            goto L_80020BC8;
    }
    // 0x80020B88: nop

    // 0x80020B8C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B90: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020B94: jal         0x8008ECE4
    // 0x80020B98: addiu       $a0, $a0, -0x2224
    ctx->r4 = ADD32(ctx->r4, -0X2224);
    func_8008ECE4(rdram, ctx);
        goto after_21;
    // 0x80020B98: addiu       $a0, $a0, -0x2224
    ctx->r4 = ADD32(ctx->r4, -0X2224);
    after_21:
    // 0x80020B9C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020BA0: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020BA4: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80020BA8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80020BAC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80020BB0: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80020BB4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80020BB8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020BBC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80020BC0: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x80020BC4: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_80020BC8:
    // 0x80020BC8: b           L_8002150C
    // 0x80020BCC: nop

        goto L_8002150C;
    // 0x80020BCC: nop

L_80020BD0:
    // 0x80020BD0: jal         0x800AEBF4
    // 0x80020BD4: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_22;
    // 0x80020BD4: nop

    after_22:
    // 0x80020BD8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020BDC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80020BE0: nop

    // 0x80020BE4: slti        $at, $t2, 0x1001
    ctx->r1 = SIGNED(ctx->r10) < 0X1001 ? 1 : 0;
    // 0x80020BE8: bne         $at, $zero, L_80020CF8
    if (ctx->r1 != 0) {
        // 0x80020BEC: nop
    
            goto L_80020CF8;
    }
    // 0x80020BEC: nop

    // 0x80020BF0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80020BF4: nop

    // 0x80020BF8: addiu       $t8, $t7, -0x1000
    ctx->r24 = ADD32(ctx->r15, -0X1000);
    // 0x80020BFC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80020C00: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80020C04: nop

    // 0x80020C08: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80020C0C: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x80020C10: beq         $at, $zero, L_80020CC0
    if (ctx->r1 == 0) {
        // 0x80020C14: nop
    
            goto L_80020CC0;
    }
    // 0x80020C14: nop

    // 0x80020C18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80020C1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020C20: addu        $at, $at, $t6
    gpr jr_addend_80020C2C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80020C24: lw          $t6, -0x1E4C($at)
    ctx->r14 = ADD32(ctx->r1, -0X1E4C);
    // 0x80020C28: nop

    // 0x80020C2C: jr          $t6
    // 0x80020C30: nop

    switch (jr_addend_80020C2C >> 2) {
        case 0: goto L_80020C70; break;
        case 1: goto L_80020C84; break;
        case 2: goto L_80020C98; break;
        case 3: goto L_80020C34; break;
        case 4: goto L_80020C48; break;
        case 5: goto L_80020CC0; break;
        case 6: goto L_80020CC0; break;
        case 7: goto L_80020CAC; break;
        case 8: goto L_80020C5C; break;
        default: switch_error(__func__, 0x80020C2C, 0x800EE1B4);
    }
    // 0x80020C30: nop

L_80020C34:
    // 0x80020C34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C38: jal         0x8008ECE4
    // 0x80020C3C: addiu       $a0, $a0, -0x220C
    ctx->r4 = ADD32(ctx->r4, -0X220C);
    func_8008ECE4(rdram, ctx);
        goto after_23;
    // 0x80020C3C: addiu       $a0, $a0, -0x220C
    ctx->r4 = ADD32(ctx->r4, -0X220C);
    after_23:
    // 0x80020C40: b           L_80020CD8
    // 0x80020C44: nop

        goto L_80020CD8;
    // 0x80020C44: nop

L_80020C48:
    // 0x80020C48: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C4C: jal         0x8008ECE4
    // 0x80020C50: addiu       $a0, $a0, -0x21F4
    ctx->r4 = ADD32(ctx->r4, -0X21F4);
    func_8008ECE4(rdram, ctx);
        goto after_24;
    // 0x80020C50: addiu       $a0, $a0, -0x21F4
    ctx->r4 = ADD32(ctx->r4, -0X21F4);
    after_24:
    // 0x80020C54: b           L_80020CD8
    // 0x80020C58: nop

        goto L_80020CD8;
    // 0x80020C58: nop

L_80020C5C:
    // 0x80020C5C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C60: jal         0x8008ECE4
    // 0x80020C64: addiu       $a0, $a0, -0x21DC
    ctx->r4 = ADD32(ctx->r4, -0X21DC);
    func_8008ECE4(rdram, ctx);
        goto after_25;
    // 0x80020C64: addiu       $a0, $a0, -0x21DC
    ctx->r4 = ADD32(ctx->r4, -0X21DC);
    after_25:
    // 0x80020C68: b           L_80020CD8
    // 0x80020C6C: nop

        goto L_80020CD8;
    // 0x80020C6C: nop

L_80020C70:
    // 0x80020C70: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C74: jal         0x8008ECE4
    // 0x80020C78: addiu       $a0, $a0, -0x21C4
    ctx->r4 = ADD32(ctx->r4, -0X21C4);
    func_8008ECE4(rdram, ctx);
        goto after_26;
    // 0x80020C78: addiu       $a0, $a0, -0x21C4
    ctx->r4 = ADD32(ctx->r4, -0X21C4);
    after_26:
    // 0x80020C7C: b           L_80020CD8
    // 0x80020C80: nop

        goto L_80020CD8;
    // 0x80020C80: nop

L_80020C84:
    // 0x80020C84: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C88: jal         0x8008ECE4
    // 0x80020C8C: addiu       $a0, $a0, -0x21AC
    ctx->r4 = ADD32(ctx->r4, -0X21AC);
    func_8008ECE4(rdram, ctx);
        goto after_27;
    // 0x80020C8C: addiu       $a0, $a0, -0x21AC
    ctx->r4 = ADD32(ctx->r4, -0X21AC);
    after_27:
    // 0x80020C90: b           L_80020CD8
    // 0x80020C94: nop

        goto L_80020CD8;
    // 0x80020C94: nop

L_80020C98:
    // 0x80020C98: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C9C: jal         0x8008ECE4
    // 0x80020CA0: addiu       $a0, $a0, -0x2194
    ctx->r4 = ADD32(ctx->r4, -0X2194);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x80020CA0: addiu       $a0, $a0, -0x2194
    ctx->r4 = ADD32(ctx->r4, -0X2194);
    after_28:
    // 0x80020CA4: b           L_80020CD8
    // 0x80020CA8: nop

        goto L_80020CD8;
    // 0x80020CA8: nop

L_80020CAC:
    // 0x80020CAC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020CB0: jal         0x8008ECE4
    // 0x80020CB4: addiu       $a0, $a0, -0x217C
    ctx->r4 = ADD32(ctx->r4, -0X217C);
    func_8008ECE4(rdram, ctx);
        goto after_29;
    // 0x80020CB4: addiu       $a0, $a0, -0x217C
    ctx->r4 = ADD32(ctx->r4, -0X217C);
    after_29:
    // 0x80020CB8: b           L_80020CD8
    // 0x80020CBC: nop

        goto L_80020CD8;
    // 0x80020CBC: nop

L_80020CC0:
    // 0x80020CC0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020CC4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020CC8: jal         0x8008ECE4
    // 0x80020CCC: addiu       $a0, $a0, -0x2164
    ctx->r4 = ADD32(ctx->r4, -0X2164);
    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x80020CCC: addiu       $a0, $a0, -0x2164
    ctx->r4 = ADD32(ctx->r4, -0X2164);
    after_30:
    // 0x80020CD0: b           L_80020CD8
    // 0x80020CD4: nop

        goto L_80020CD8;
    // 0x80020CD4: nop

L_80020CD8:
    // 0x80020CD8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020CDC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020CE0: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80020CE4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80020CE8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80020CEC: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80020CF0: b           L_80020D44
    // 0x80020CF4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_80020D44;
    // 0x80020CF4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80020CF8:
    // 0x80020CF8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020CFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020D00: beq         $t3, $at, L_80020D44
    if (ctx->r11 == ctx->r1) {
        // 0x80020D04: nop
    
            goto L_80020D44;
    }
    // 0x80020D04: nop

    // 0x80020D08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020D0C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020D10: jal         0x8008ECE4
    // 0x80020D14: addiu       $a0, $a0, -0x214C
    ctx->r4 = ADD32(ctx->r4, -0X214C);
    func_8008ECE4(rdram, ctx);
        goto after_31;
    // 0x80020D14: addiu       $a0, $a0, -0x214C
    ctx->r4 = ADD32(ctx->r4, -0X214C);
    after_31:
    // 0x80020D18: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80020D1C: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x80020D20: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80020D24: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80020D28: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80020D2C: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80020D30: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80020D34: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020D38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020D3C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020D40: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
L_80020D44:
    // 0x80020D44: b           L_8002150C
    // 0x80020D48: nop

        goto L_8002150C;
    // 0x80020D48: nop

L_80020D4C:
    // 0x80020D4C: jal         0x800AEDE8
    // 0x80020D50: nop

    ContPak_GetWriteFileResult(rdram, ctx);
        goto after_32;
    // 0x80020D50: nop

    after_32:
    // 0x80020D54: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020D58: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80020D5C: nop

    // 0x80020D60: slti        $at, $t6, 0x1001
    ctx->r1 = SIGNED(ctx->r14) < 0X1001 ? 1 : 0;
    // 0x80020D64: bne         $at, $zero, L_80020E60
    if (ctx->r1 != 0) {
        // 0x80020D68: nop
    
            goto L_80020E60;
    }
    // 0x80020D68: nop

    // 0x80020D6C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80020D70: nop

    // 0x80020D74: addiu       $t0, $t9, -0x1000
    ctx->r8 = ADD32(ctx->r25, -0X1000);
    // 0x80020D78: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80020D7C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80020D80: nop

    // 0x80020D84: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x80020D88: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x80020D8C: beq         $at, $zero, L_80020E28
    if (ctx->r1 == 0) {
        // 0x80020D90: nop
    
            goto L_80020E28;
    }
    // 0x80020D90: nop

    // 0x80020D94: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80020D98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020D9C: addu        $at, $at, $t3
    gpr jr_addend_80020DA8 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80020DA0: lw          $t3, -0x1E28($at)
    ctx->r11 = ADD32(ctx->r1, -0X1E28);
    // 0x80020DA4: nop

    // 0x80020DA8: jr          $t3
    // 0x80020DAC: nop

    switch (jr_addend_80020DA8 >> 2) {
        case 0: goto L_80020DD8; break;
        case 1: goto L_80020DEC; break;
        case 2: goto L_80020E00; break;
        case 3: goto L_80020DB0; break;
        case 4: goto L_80020DC4; break;
        case 5: goto L_80020E14; break;
        default: switch_error(__func__, 0x80020DA8, 0x800EE1D8);
    }
    // 0x80020DAC: nop

L_80020DB0:
    // 0x80020DB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DB4: jal         0x8008ECE4
    // 0x80020DB8: addiu       $a0, $a0, -0x2134
    ctx->r4 = ADD32(ctx->r4, -0X2134);
    func_8008ECE4(rdram, ctx);
        goto after_33;
    // 0x80020DB8: addiu       $a0, $a0, -0x2134
    ctx->r4 = ADD32(ctx->r4, -0X2134);
    after_33:
    // 0x80020DBC: b           L_80020E40
    // 0x80020DC0: nop

        goto L_80020E40;
    // 0x80020DC0: nop

L_80020DC4:
    // 0x80020DC4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DC8: jal         0x8008ECE4
    // 0x80020DCC: addiu       $a0, $a0, -0x211C
    ctx->r4 = ADD32(ctx->r4, -0X211C);
    func_8008ECE4(rdram, ctx);
        goto after_34;
    // 0x80020DCC: addiu       $a0, $a0, -0x211C
    ctx->r4 = ADD32(ctx->r4, -0X211C);
    after_34:
    // 0x80020DD0: b           L_80020E40
    // 0x80020DD4: nop

        goto L_80020E40;
    // 0x80020DD4: nop

L_80020DD8:
    // 0x80020DD8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DDC: jal         0x8008ECE4
    // 0x80020DE0: addiu       $a0, $a0, -0x2104
    ctx->r4 = ADD32(ctx->r4, -0X2104);
    func_8008ECE4(rdram, ctx);
        goto after_35;
    // 0x80020DE0: addiu       $a0, $a0, -0x2104
    ctx->r4 = ADD32(ctx->r4, -0X2104);
    after_35:
    // 0x80020DE4: b           L_80020E40
    // 0x80020DE8: nop

        goto L_80020E40;
    // 0x80020DE8: nop

L_80020DEC:
    // 0x80020DEC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DF0: jal         0x8008ECE4
    // 0x80020DF4: addiu       $a0, $a0, -0x20EC
    ctx->r4 = ADD32(ctx->r4, -0X20EC);
    func_8008ECE4(rdram, ctx);
        goto after_36;
    // 0x80020DF4: addiu       $a0, $a0, -0x20EC
    ctx->r4 = ADD32(ctx->r4, -0X20EC);
    after_36:
    // 0x80020DF8: b           L_80020E40
    // 0x80020DFC: nop

        goto L_80020E40;
    // 0x80020DFC: nop

L_80020E00:
    // 0x80020E00: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E04: jal         0x8008ECE4
    // 0x80020E08: addiu       $a0, $a0, -0x20D4
    ctx->r4 = ADD32(ctx->r4, -0X20D4);
    func_8008ECE4(rdram, ctx);
        goto after_37;
    // 0x80020E08: addiu       $a0, $a0, -0x20D4
    ctx->r4 = ADD32(ctx->r4, -0X20D4);
    after_37:
    // 0x80020E0C: b           L_80020E40
    // 0x80020E10: nop

        goto L_80020E40;
    // 0x80020E10: nop

L_80020E14:
    // 0x80020E14: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E18: jal         0x8008ECE4
    // 0x80020E1C: addiu       $a0, $a0, -0x20BC
    ctx->r4 = ADD32(ctx->r4, -0X20BC);
    func_8008ECE4(rdram, ctx);
        goto after_38;
    // 0x80020E1C: addiu       $a0, $a0, -0x20BC
    ctx->r4 = ADD32(ctx->r4, -0X20BC);
    after_38:
    // 0x80020E20: b           L_80020E40
    // 0x80020E24: nop

        goto L_80020E40;
    // 0x80020E24: nop

L_80020E28:
    // 0x80020E28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E2C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020E30: jal         0x8008ECE4
    // 0x80020E34: addiu       $a0, $a0, -0x20A4
    ctx->r4 = ADD32(ctx->r4, -0X20A4);
    func_8008ECE4(rdram, ctx);
        goto after_39;
    // 0x80020E34: addiu       $a0, $a0, -0x20A4
    ctx->r4 = ADD32(ctx->r4, -0X20A4);
    after_39:
    // 0x80020E38: b           L_80020E40
    // 0x80020E3C: nop

        goto L_80020E40;
    // 0x80020E3C: nop

L_80020E40:
    // 0x80020E40: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80020E44: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x80020E48: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80020E4C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80020E50: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80020E54: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80020E58: b           L_80020EA4
    // 0x80020E5C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_80020EA4;
    // 0x80020E5C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80020E60:
    // 0x80020E60: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020E64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020E68: beq         $t8, $at, L_80020EA4
    if (ctx->r24 == ctx->r1) {
        // 0x80020E6C: nop
    
            goto L_80020EA4;
    }
    // 0x80020E6C: nop

    // 0x80020E70: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020E74: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020E78: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x80020E7C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E80: jal         0x8008ECE4
    // 0x80020E84: addiu       $a0, $a0, -0x208C
    ctx->r4 = ADD32(ctx->r4, -0X208C);
    func_8008ECE4(rdram, ctx);
        goto after_40;
    // 0x80020E84: addiu       $a0, $a0, -0x208C
    ctx->r4 = ADD32(ctx->r4, -0X208C);
    after_40:
    // 0x80020E88: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80020E8C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x80020E90: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80020E94: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80020E98: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020E9C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020EA0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80020EA4:
    // 0x80020EA4: b           L_8002150C
    // 0x80020EA8: nop

        goto L_8002150C;
    // 0x80020EA8: nop

L_80020EAC:
    // 0x80020EAC: jal         0x800AEFD4
    // 0x80020EB0: nop

    ContPak_GetReadFileResult(rdram, ctx);
        goto after_41;
    // 0x80020EB0: nop

    after_41:
    // 0x80020EB4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020EB8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80020EBC: nop

    // 0x80020EC0: slti        $at, $t1, 0x1001
    ctx->r1 = SIGNED(ctx->r9) < 0X1001 ? 1 : 0;
    // 0x80020EC4: bne         $at, $zero, L_80020FC0
    if (ctx->r1 != 0) {
        // 0x80020EC8: nop
    
            goto L_80020FC0;
    }
    // 0x80020EC8: nop

    // 0x80020ECC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020ED0: nop

    // 0x80020ED4: addiu       $t4, $t3, -0x1000
    ctx->r12 = ADD32(ctx->r11, -0X1000);
    // 0x80020ED8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80020EDC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80020EE0: nop

    // 0x80020EE4: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x80020EE8: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80020EEC: beq         $at, $zero, L_80020F88
    if (ctx->r1 == 0) {
        // 0x80020EF0: nop
    
            goto L_80020F88;
    }
    // 0x80020EF0: nop

    // 0x80020EF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80020EF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020EFC: addu        $at, $at, $t7
    gpr jr_addend_80020F08 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80020F00: lw          $t7, -0x1E10($at)
    ctx->r15 = ADD32(ctx->r1, -0X1E10);
    // 0x80020F04: nop

    // 0x80020F08: jr          $t7
    // 0x80020F0C: nop

    switch (jr_addend_80020F08 >> 2) {
        case 0: goto L_80020F38; break;
        case 1: goto L_80020F4C; break;
        case 2: goto L_80020F60; break;
        case 3: goto L_80020F10; break;
        case 4: goto L_80020F24; break;
        case 5: goto L_80020F74; break;
        default: switch_error(__func__, 0x80020F08, 0x800EE1F0);
    }
    // 0x80020F0C: nop

L_80020F10:
    // 0x80020F10: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F14: jal         0x8008ECE4
    // 0x80020F18: addiu       $a0, $a0, -0x2070
    ctx->r4 = ADD32(ctx->r4, -0X2070);
    func_8008ECE4(rdram, ctx);
        goto after_42;
    // 0x80020F18: addiu       $a0, $a0, -0x2070
    ctx->r4 = ADD32(ctx->r4, -0X2070);
    after_42:
    // 0x80020F1C: b           L_80020FA0
    // 0x80020F20: nop

        goto L_80020FA0;
    // 0x80020F20: nop

L_80020F24:
    // 0x80020F24: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F28: jal         0x8008ECE4
    // 0x80020F2C: addiu       $a0, $a0, -0x2058
    ctx->r4 = ADD32(ctx->r4, -0X2058);
    func_8008ECE4(rdram, ctx);
        goto after_43;
    // 0x80020F2C: addiu       $a0, $a0, -0x2058
    ctx->r4 = ADD32(ctx->r4, -0X2058);
    after_43:
    // 0x80020F30: b           L_80020FA0
    // 0x80020F34: nop

        goto L_80020FA0;
    // 0x80020F34: nop

L_80020F38:
    // 0x80020F38: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F3C: jal         0x8008ECE4
    // 0x80020F40: addiu       $a0, $a0, -0x2040
    ctx->r4 = ADD32(ctx->r4, -0X2040);
    func_8008ECE4(rdram, ctx);
        goto after_44;
    // 0x80020F40: addiu       $a0, $a0, -0x2040
    ctx->r4 = ADD32(ctx->r4, -0X2040);
    after_44:
    // 0x80020F44: b           L_80020FA0
    // 0x80020F48: nop

        goto L_80020FA0;
    // 0x80020F48: nop

L_80020F4C:
    // 0x80020F4C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F50: jal         0x8008ECE4
    // 0x80020F54: addiu       $a0, $a0, -0x2028
    ctx->r4 = ADD32(ctx->r4, -0X2028);
    func_8008ECE4(rdram, ctx);
        goto after_45;
    // 0x80020F54: addiu       $a0, $a0, -0x2028
    ctx->r4 = ADD32(ctx->r4, -0X2028);
    after_45:
    // 0x80020F58: b           L_80020FA0
    // 0x80020F5C: nop

        goto L_80020FA0;
    // 0x80020F5C: nop

L_80020F60:
    // 0x80020F60: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F64: jal         0x8008ECE4
    // 0x80020F68: addiu       $a0, $a0, -0x2010
    ctx->r4 = ADD32(ctx->r4, -0X2010);
    func_8008ECE4(rdram, ctx);
        goto after_46;
    // 0x80020F68: addiu       $a0, $a0, -0x2010
    ctx->r4 = ADD32(ctx->r4, -0X2010);
    after_46:
    // 0x80020F6C: b           L_80020FA0
    // 0x80020F70: nop

        goto L_80020FA0;
    // 0x80020F70: nop

L_80020F74:
    // 0x80020F74: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F78: jal         0x8008ECE4
    // 0x80020F7C: addiu       $a0, $a0, -0x1FF8
    ctx->r4 = ADD32(ctx->r4, -0X1FF8);
    func_8008ECE4(rdram, ctx);
        goto after_47;
    // 0x80020F7C: addiu       $a0, $a0, -0x1FF8
    ctx->r4 = ADD32(ctx->r4, -0X1FF8);
    after_47:
    // 0x80020F80: b           L_80020FA0
    // 0x80020F84: nop

        goto L_80020FA0;
    // 0x80020F84: nop

L_80020F88:
    // 0x80020F88: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F8C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020F90: jal         0x8008ECE4
    // 0x80020F94: addiu       $a0, $a0, -0x1FE0
    ctx->r4 = ADD32(ctx->r4, -0X1FE0);
    func_8008ECE4(rdram, ctx);
        goto after_48;
    // 0x80020F94: addiu       $a0, $a0, -0x1FE0
    ctx->r4 = ADD32(ctx->r4, -0X1FE0);
    after_48:
    // 0x80020F98: b           L_80020FA0
    // 0x80020F9C: nop

        goto L_80020FA0;
    // 0x80020F9C: nop

L_80020FA0:
    // 0x80020FA0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020FA4: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020FA8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80020FAC: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80020FB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80020FB4: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x80020FB8: b           L_80021088
    // 0x80020FBC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
        goto L_80021088;
    // 0x80020FBC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_80020FC0:
    // 0x80020FC0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80020FC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020FC8: beq         $t9, $at, L_80021088
    if (ctx->r25 == ctx->r1) {
        // 0x80020FCC: nop
    
            goto L_80021088;
    }
    // 0x80020FCC: nop

    // 0x80020FD0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80020FD4:
    // 0x80020FD4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020FD8: addiu       $t0, $t0, 0x2618
    ctx->r8 = ADD32(ctx->r8, 0X2618);
    // 0x80020FDC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020FE0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80020FE4: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80020FE8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80020FEC: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x80020FF0: lbu         $t5, 0x0($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X0);
    // 0x80020FF4: lbu         $t2, 0x0($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X0);
    // 0x80020FF8: nop

    // 0x80020FFC: beq         $t2, $t5, L_8002100C
    if (ctx->r10 == ctx->r13) {
        // 0x80021000: nop
    
            goto L_8002100C;
    }
    // 0x80021000: nop

    // 0x80021004: b           L_80021024
    // 0x80021008: nop

        goto L_80021024;
    // 0x80021008: nop

L_8002100C:
    // 0x8002100C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80021010: nop

    // 0x80021014: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80021018: slti        $at, $t9, 0x1600
    ctx->r1 = SIGNED(ctx->r25) < 0X1600 ? 1 : 0;
    // 0x8002101C: bne         $at, $zero, L_80020FD4
    if (ctx->r1 != 0) {
        // 0x80021020: sw          $t9, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r25;
            goto L_80020FD4;
    }
    // 0x80021020: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_80021024:
    // 0x80021024: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80021028: addiu       $at, $zero, 0x1600
    ctx->r1 = ADD32(0, 0X1600);
    // 0x8002102C: bne         $t1, $at, L_80021054
    if (ctx->r9 != ctx->r1) {
        // 0x80021030: nop
    
            goto L_80021054;
    }
    // 0x80021030: nop

    // 0x80021034: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80021038: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8002103C: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x80021040: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021044: jal         0x8008ECE4
    // 0x80021048: addiu       $a0, $a0, -0x1FC8
    ctx->r4 = ADD32(ctx->r4, -0X1FC8);
    func_8008ECE4(rdram, ctx);
        goto after_49;
    // 0x80021048: addiu       $a0, $a0, -0x1FC8
    ctx->r4 = ADD32(ctx->r4, -0X1FC8);
    after_49:
    // 0x8002104C: b           L_8002106C
    // 0x80021050: nop

        goto L_8002106C;
    // 0x80021050: nop

L_80021054:
    // 0x80021054: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021058: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8002105C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x80021060: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021064: jal         0x8008ECE4
    // 0x80021068: addiu       $a0, $a0, -0x1FAC
    ctx->r4 = ADD32(ctx->r4, -0X1FAC);
    func_8008ECE4(rdram, ctx);
        goto after_50;
    // 0x80021068: addiu       $a0, $a0, -0x1FAC
    ctx->r4 = ADD32(ctx->r4, -0X1FAC);
    after_50:
L_8002106C:
    // 0x8002106C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80021070: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x80021074: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80021078: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8002107C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021080: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80021084: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_80021088:
    // 0x80021088: b           L_8002150C
    // 0x8002108C: nop

        goto L_8002150C;
    // 0x8002108C: nop

L_80021090:
    // 0x80021090: jal         0x800AE7FC
    // 0x80021094: nop

    ContPak_GetDeleteFileResult(rdram, ctx);
        goto after_51;
    // 0x80021094: nop

    after_51:
    // 0x80021098: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8002109C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800210A0: nop

    // 0x800210A4: slti        $at, $t2, 0x1001
    ctx->r1 = SIGNED(ctx->r10) < 0X1001 ? 1 : 0;
    // 0x800210A8: bne         $at, $zero, L_800211CC
    if (ctx->r1 != 0) {
        // 0x800210AC: nop
    
            goto L_800211CC;
    }
    // 0x800210AC: nop

    // 0x800210B0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800210B4: nop

    // 0x800210B8: addiu       $t6, $t5, -0x1000
    ctx->r14 = ADD32(ctx->r13, -0X1000);
    // 0x800210BC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800210C0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800210C4: nop

    // 0x800210C8: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800210CC: sltiu       $at, $t1, 0x9
    ctx->r1 = ctx->r9 < 0X9 ? 1 : 0;
    // 0x800210D0: beq         $at, $zero, L_80021194
    if (ctx->r1 == 0) {
        // 0x800210D4: nop
    
            goto L_80021194;
    }
    // 0x800210D4: nop

    // 0x800210D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800210DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800210E0: addu        $at, $at, $t1
    gpr jr_addend_800210EC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800210E4: lw          $t1, -0x1DF8($at)
    ctx->r9 = ADD32(ctx->r1, -0X1DF8);
    // 0x800210E8: nop

    // 0x800210EC: jr          $t1
    // 0x800210F0: nop

    switch (jr_addend_800210EC >> 2) {
        case 0: goto L_80021130; break;
        case 1: goto L_80021144; break;
        case 2: goto L_80021158; break;
        case 3: goto L_800210F4; break;
        case 4: goto L_80021108; break;
        case 5: goto L_80021194; break;
        case 6: goto L_80021180; break;
        case 7: goto L_8002116C; break;
        case 8: goto L_8002111C; break;
        default: switch_error(__func__, 0x800210EC, 0x800EE208);
    }
    // 0x800210F0: nop

L_800210F4:
    // 0x800210F4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800210F8: jal         0x8008ECE4
    // 0x800210FC: addiu       $a0, $a0, -0x1F90
    ctx->r4 = ADD32(ctx->r4, -0X1F90);
    func_8008ECE4(rdram, ctx);
        goto after_52;
    // 0x800210FC: addiu       $a0, $a0, -0x1F90
    ctx->r4 = ADD32(ctx->r4, -0X1F90);
    after_52:
    // 0x80021100: b           L_800211AC
    // 0x80021104: nop

        goto L_800211AC;
    // 0x80021104: nop

L_80021108:
    // 0x80021108: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002110C: jal         0x8008ECE4
    // 0x80021110: addiu       $a0, $a0, -0x1F78
    ctx->r4 = ADD32(ctx->r4, -0X1F78);
    func_8008ECE4(rdram, ctx);
        goto after_53;
    // 0x80021110: addiu       $a0, $a0, -0x1F78
    ctx->r4 = ADD32(ctx->r4, -0X1F78);
    after_53:
    // 0x80021114: b           L_800211AC
    // 0x80021118: nop

        goto L_800211AC;
    // 0x80021118: nop

L_8002111C:
    // 0x8002111C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021120: jal         0x8008ECE4
    // 0x80021124: addiu       $a0, $a0, -0x1F60
    ctx->r4 = ADD32(ctx->r4, -0X1F60);
    func_8008ECE4(rdram, ctx);
        goto after_54;
    // 0x80021124: addiu       $a0, $a0, -0x1F60
    ctx->r4 = ADD32(ctx->r4, -0X1F60);
    after_54:
    // 0x80021128: b           L_800211AC
    // 0x8002112C: nop

        goto L_800211AC;
    // 0x8002112C: nop

L_80021130:
    // 0x80021130: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021134: jal         0x8008ECE4
    // 0x80021138: addiu       $a0, $a0, -0x1F48
    ctx->r4 = ADD32(ctx->r4, -0X1F48);
    func_8008ECE4(rdram, ctx);
        goto after_55;
    // 0x80021138: addiu       $a0, $a0, -0x1F48
    ctx->r4 = ADD32(ctx->r4, -0X1F48);
    after_55:
    // 0x8002113C: b           L_800211AC
    // 0x80021140: nop

        goto L_800211AC;
    // 0x80021140: nop

L_80021144:
    // 0x80021144: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021148: jal         0x8008ECE4
    // 0x8002114C: addiu       $a0, $a0, -0x1F30
    ctx->r4 = ADD32(ctx->r4, -0X1F30);
    func_8008ECE4(rdram, ctx);
        goto after_56;
    // 0x8002114C: addiu       $a0, $a0, -0x1F30
    ctx->r4 = ADD32(ctx->r4, -0X1F30);
    after_56:
    // 0x80021150: b           L_800211AC
    // 0x80021154: nop

        goto L_800211AC;
    // 0x80021154: nop

L_80021158:
    // 0x80021158: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002115C: jal         0x8008ECE4
    // 0x80021160: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    func_8008ECE4(rdram, ctx);
        goto after_57;
    // 0x80021160: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    after_57:
    // 0x80021164: b           L_800211AC
    // 0x80021168: nop

        goto L_800211AC;
    // 0x80021168: nop

L_8002116C:
    // 0x8002116C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021170: jal         0x8008ECE4
    // 0x80021174: addiu       $a0, $a0, -0x1F00
    ctx->r4 = ADD32(ctx->r4, -0X1F00);
    func_8008ECE4(rdram, ctx);
        goto after_58;
    // 0x80021174: addiu       $a0, $a0, -0x1F00
    ctx->r4 = ADD32(ctx->r4, -0X1F00);
    after_58:
    // 0x80021178: b           L_800211AC
    // 0x8002117C: nop

        goto L_800211AC;
    // 0x8002117C: nop

L_80021180:
    // 0x80021180: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021184: jal         0x8008ECE4
    // 0x80021188: addiu       $a0, $a0, -0x1EE8
    ctx->r4 = ADD32(ctx->r4, -0X1EE8);
    func_8008ECE4(rdram, ctx);
        goto after_59;
    // 0x80021188: addiu       $a0, $a0, -0x1EE8
    ctx->r4 = ADD32(ctx->r4, -0X1EE8);
    after_59:
    // 0x8002118C: b           L_800211AC
    // 0x80021190: nop

        goto L_800211AC;
    // 0x80021190: nop

L_80021194:
    // 0x80021194: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021198: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002119C: jal         0x8008ECE4
    // 0x800211A0: addiu       $a0, $a0, -0x1ED0
    ctx->r4 = ADD32(ctx->r4, -0X1ED0);
    func_8008ECE4(rdram, ctx);
        goto after_60;
    // 0x800211A0: addiu       $a0, $a0, -0x1ED0
    ctx->r4 = ADD32(ctx->r4, -0X1ED0);
    after_60:
    // 0x800211A4: b           L_800211AC
    // 0x800211A8: nop

        goto L_800211AC;
    // 0x800211A8: nop

L_800211AC:
    // 0x800211AC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800211B0: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x800211B4: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x800211B8: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x800211BC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800211C0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x800211C4: b           L_80021218
    // 0x800211C8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_80021218;
    // 0x800211C8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_800211CC:
    // 0x800211CC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800211D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800211D4: beq         $t3, $at, L_80021218
    if (ctx->r11 == ctx->r1) {
        // 0x800211D8: nop
    
            goto L_80021218;
    }
    // 0x800211D8: nop

    // 0x800211DC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800211E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800211E4: jal         0x8008ECE4
    // 0x800211E8: addiu       $a0, $a0, -0x1EB8
    ctx->r4 = ADD32(ctx->r4, -0X1EB8);
    func_8008ECE4(rdram, ctx);
        goto after_61;
    // 0x800211E8: addiu       $a0, $a0, -0x1EB8
    ctx->r4 = ADD32(ctx->r4, -0X1EB8);
    after_61:
    // 0x800211EC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800211F0: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x800211F4: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x800211F8: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x800211FC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021200: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80021204: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80021208: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002120C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x80021210: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80021214: sw          $t6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r14;
L_80021218:
    // 0x80021218: b           L_8002150C
    // 0x8002121C: nop

        goto L_8002150C;
    // 0x8002121C: nop

L_80021220:
    // 0x80021220: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80021224: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x80021228: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002122C: lhu         $t0, 0x10F2($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X10F2);
    // 0x80021230: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x80021234: nop

    // 0x80021238: and         $t7, $t4, $t0
    ctx->r15 = ctx->r12 & ctx->r8;
    // 0x8002123C: beq         $t7, $zero, L_8002124C
    if (ctx->r15 == 0) {
        // 0x80021240: nop
    
            goto L_8002124C;
    }
    // 0x80021240: nop

    // 0x80021244: jal         0x800AE348
    // 0x80021248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ContPak_SetPakInitializationAttempts(rdram, ctx);
        goto after_62;
    // 0x80021248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_62:
L_8002124C:
    // 0x8002124C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021250: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80021254: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021258: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8002125C: lhu         $t8, 0x6($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X6);
    // 0x80021260: nop

    // 0x80021264: and         $t5, $t8, $t2
    ctx->r13 = ctx->r24 & ctx->r10;
    // 0x80021268: beq         $t5, $zero, L_80021298
    if (ctx->r13 == 0) {
        // 0x8002126C: nop
    
            goto L_80021298;
    }
    // 0x8002126C: nop

    // 0x80021270: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80021274: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80021278: jal         0x800AE880
    // 0x8002127C: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    ContPak_SetOpenFileParams(rdram, ctx);
        goto after_63;
    // 0x8002127C: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    after_63:
    // 0x80021280: bne         $v0, $zero, L_80021298
    if (ctx->r2 != 0) {
        // 0x80021284: nop
    
            goto L_80021298;
    }
    // 0x80021284: nop

    // 0x80021288: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002128C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x80021290: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80021294: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
L_80021298:
    // 0x80021298: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8002129C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x800212A0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800212A4: lhu         $t0, 0x101C($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X101C);
    // 0x800212A8: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x800212AC: nop

    // 0x800212B0: and         $t7, $t4, $t0
    ctx->r15 = ctx->r12 & ctx->r8;
    // 0x800212B4: beq         $t7, $zero, L_800212E4
    if (ctx->r15 == 0) {
        // 0x800212B8: nop
    
            goto L_800212E4;
    }
    // 0x800212B8: nop

    // 0x800212BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800212C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800212C4: jal         0x800AEA98
    // 0x800212C8: nop

    ContPak_SetFileFindParams(rdram, ctx);
        goto after_64;
    // 0x800212C8: nop

    after_64:
    // 0x800212CC: bne         $v0, $zero, L_800212E4
    if (ctx->r2 != 0) {
        // 0x800212D0: nop
    
            goto L_800212E4;
    }
    // 0x800212D0: nop

    // 0x800212D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800212D8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x800212DC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800212E0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
L_800212E4:
    // 0x800212E4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800212E8: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x800212EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800212F0: lhu         $t6, 0x1258($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1258);
    // 0x800212F4: lhu         $t5, 0x6($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X6);
    // 0x800212F8: nop

    // 0x800212FC: and         $t9, $t5, $t6
    ctx->r25 = ctx->r13 & ctx->r14;
    // 0x80021300: beq         $t9, $zero, L_8002135C
    if (ctx->r25 == 0) {
        // 0x80021304: nop
    
            goto L_8002135C;
    }
    // 0x80021304: nop

    // 0x80021308: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002130C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80021310: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x80021314: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021318: beq         $t4, $at, L_8002135C
    if (ctx->r12 == ctx->r1) {
        // 0x8002131C: nop
    
            goto L_8002135C;
    }
    // 0x8002131C: nop

    // 0x80021320: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021324: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80021328: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8002132C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021330: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x80021334: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x80021338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002133C: jal         0x800AEC80
    // 0x80021340: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_65;
    // 0x80021340: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    after_65:
    // 0x80021344: bne         $v0, $zero, L_8002135C
    if (ctx->r2 != 0) {
        // 0x80021348: nop
    
            goto L_8002135C;
    }
    // 0x80021348: nop

    // 0x8002134C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021350: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80021354: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80021358: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
L_8002135C:
    // 0x8002135C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80021360: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80021364: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021368: lhu         $t6, 0x1260($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1260);
    // 0x8002136C: lhu         $t5, 0x6($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X6);
    // 0x80021370: nop

    // 0x80021374: and         $t9, $t5, $t6
    ctx->r25 = ctx->r13 & ctx->r14;
    // 0x80021378: beq         $t9, $zero, L_80021418
    if (ctx->r25 == 0) {
        // 0x8002137C: nop
    
            goto L_80021418;
    }
    // 0x8002137C: nop

    // 0x80021380: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80021384: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80021388: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8002138C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021390: beq         $t4, $at, L_80021418
    if (ctx->r12 == ctx->r1) {
        // 0x80021394: nop
    
            goto L_80021418;
    }
    // 0x80021394: nop

    // 0x80021398: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8002139C:
    // 0x8002139C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800213A0: addiu       $t0, $t0, 0x2618
    ctx->r8 = ADD32(ctx->r8, 0X2618);
    // 0x800213A4: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x800213A8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800213AC: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x800213B0: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x800213B4: lbu         $t2, 0x0($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X0);
    // 0x800213B8: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x800213BC: xori        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 ^ 0XFF;
    // 0x800213C0: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
    // 0x800213C4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800213C8: nop

    // 0x800213CC: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x800213D0: slti        $at, $t4, 0x1600
    ctx->r1 = SIGNED(ctx->r12) < 0X1600 ? 1 : 0;
    // 0x800213D4: bne         $at, $zero, L_8002139C
    if (ctx->r1 != 0) {
        // 0x800213D8: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_8002139C;
    }
    // 0x800213D8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800213DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800213E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800213E4: addiu       $t8, $t8, 0x2618
    ctx->r24 = ADD32(ctx->r24, 0X2618);
    // 0x800213E8: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x800213EC: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x800213F0: lw          $a3, 0xC($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XC);
    // 0x800213F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800213F8: jal         0x800AEE6C
    // 0x800213FC: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    ContPak_SetFileReadParams(rdram, ctx);
        goto after_66;
    // 0x800213FC: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    after_66:
    // 0x80021400: bne         $v0, $zero, L_80021418
    if (ctx->r2 != 0) {
        // 0x80021404: nop
    
            goto L_80021418;
    }
    // 0x80021404: nop

    // 0x80021408: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002140C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021410: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80021414: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_80021418:
    // 0x80021418: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8002141C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80021420: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021424: lhu         $t5, 0x126C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X126C);
    // 0x80021428: lhu         $t3, 0x6($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X6);
    // 0x8002142C: nop

    // 0x80021430: and         $t9, $t3, $t5
    ctx->r25 = ctx->r11 & ctx->r13;
    // 0x80021434: beq         $t9, $zero, L_80021480
    if (ctx->r25 == 0) {
        // 0x80021438: nop
    
            goto L_80021480;
    }
    // 0x80021438: nop

    // 0x8002143C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80021440: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80021444: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x80021448: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002144C: beq         $t4, $at, L_80021480
    if (ctx->r12 == ctx->r1) {
        // 0x80021450: nop
    
            goto L_80021480;
    }
    // 0x80021450: nop

    // 0x80021454: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80021458: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8002145C: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80021460: jal         0x800AE5F0
    // 0x80021464: nop

    ContPak_SetFileDeleteParams(rdram, ctx);
        goto after_67;
    // 0x80021464: nop

    after_67:
    // 0x80021468: bne         $v0, $zero, L_80021480
    if (ctx->r2 != 0) {
        // 0x8002146C: nop
    
            goto L_80021480;
    }
    // 0x8002146C: nop

    // 0x80021470: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021474: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x80021478: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8002147C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80021480:
    // 0x80021480: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021484: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021488: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x8002148C: nop

    // 0x80021490: bne         $t6, $zero, L_800214AC
    if (ctx->r14 != 0) {
        // 0x80021494: nop
    
            goto L_800214AC;
    }
    // 0x80021494: nop

    // 0x80021498: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002149C: jal         0x8008ECE4
    // 0x800214A0: addiu       $a0, $a0, -0x1E9C
    ctx->r4 = ADD32(ctx->r4, -0X1E9C);
    func_8008ECE4(rdram, ctx);
        goto after_68;
    // 0x800214A0: addiu       $a0, $a0, -0x1E9C
    ctx->r4 = ADD32(ctx->r4, -0X1E9C);
    after_68:
    // 0x800214A4: b           L_80021504
    // 0x800214A8: nop

        goto L_80021504;
    // 0x800214A8: nop

L_800214AC:
    // 0x800214AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800214B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800214B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800214B8: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x800214BC: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800214C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800214C4: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800214C8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800214CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800214D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800214D4: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800214D8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800214DC: nop

    // 0x800214E0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800214E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800214E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800214EC: nop

    // 0x800214F0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800214F4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800214F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800214FC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80021500: nop

L_80021504:
    // 0x80021504: b           L_8002150C
    // 0x80021508: nop

        goto L_8002150C;
    // 0x80021508: nop

L_8002150C:
    // 0x8002150C: b           L_80021514
    // 0x80021510: nop

        goto L_80021514;
    // 0x80021510: nop

L_80021514:
    // 0x80021514: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021518: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8002151C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021520: lhu         $t8, 0x11A4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11A4);
    // 0x80021524: lhu         $t7, 0x6($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X6);
    // 0x80021528: nop

    // 0x8002152C: and         $t2, $t7, $t8
    ctx->r10 = ctx->r15 & ctx->r24;
    // 0x80021530: beq         $t2, $zero, L_80021578
    if (ctx->r10 == 0) {
        // 0x80021534: nop
    
            goto L_80021578;
    }
    // 0x80021534: nop

    // 0x80021538: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8002153C:
    // 0x8002153C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80021540: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80021544: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80021548: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8002154C: lw          $a0, 0x2618($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2618);
    // 0x80021550: jal         0x800BC980
    // 0x80021554: nop

    SysMem_Free(rdram, ctx);
        goto after_69;
    // 0x80021554: nop

    after_69:
    // 0x80021558: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8002155C: nop

    // 0x80021560: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80021564: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80021568: bne         $at, $zero, L_8002153C
    if (ctx->r1 != 0) {
        // 0x8002156C: sw          $t9, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r25;
            goto L_8002153C;
    }
    // 0x8002156C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80021570: b           L_80021588
    // 0x80021574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80021588;
    // 0x80021574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80021578:
    // 0x80021578: b           L_80021588
    // 0x8002157C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021588;
    // 0x8002157C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021580: b           L_80021588
    // 0x80021584: nop

        goto L_80021588;
    // 0x80021584: nop

L_80021588:
    // 0x80021588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002158C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021590: jr          $ra
    // 0x80021594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80021594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800129FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800129FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012A00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012A04: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80012A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012A0C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80012A10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80012A14: jal         0x8000DA44
    // 0x80012A18: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012A18: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80012A1C: bgez        $v0, L_80012A2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012A20: nop
    
            goto L_80012A2C;
    }
    // 0x80012A20: nop

    // 0x80012A24: b           L_80012E6C
    // 0x80012A28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012E6C;
    // 0x80012A28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012A2C:
    // 0x80012A2C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80012A30: nop

    // 0x80012A34: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80012A38: nop

    // 0x80012A3C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80012A40: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80012A44: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012A48: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80012A4C: nop

    // 0x80012A50: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012A54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80012A58: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80012A5C: nop

    // 0x80012A60: swc1        $f4, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f4.u32l;
    // 0x80012A64: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012A68: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80012A6C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80012A70: nop

    // 0x80012A74: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80012A78: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80012A7C: addiu       $t5, $sp, 0x2C
    ctx->r13 = ADD32(ctx->r29, 0X2C);
    // 0x80012A80: lh          $s0, 0x4($t5)
    ctx->r16 = MEM_H(ctx->r13, 0X4);
    // 0x80012A84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012A88: beq         $s0, $at, L_80012AB0
    if (ctx->r16 == ctx->r1) {
        // 0x80012A8C: nop
    
            goto L_80012AB0;
    }
    // 0x80012A8C: nop

    // 0x80012A90: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80012A94: beq         $s0, $at, L_80012B3C
    if (ctx->r16 == ctx->r1) {
        // 0x80012A98: nop
    
            goto L_80012B3C;
    }
    // 0x80012A98: nop

    // 0x80012A9C: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80012AA0: beq         $s0, $at, L_80012BB0
    if (ctx->r16 == ctx->r1) {
        // 0x80012AA4: nop
    
            goto L_80012BB0;
    }
    // 0x80012AA4: nop

    // 0x80012AA8: b           L_80012C3C
    // 0x80012AAC: nop

        goto L_80012C3C;
    // 0x80012AAC: nop

L_80012AB0:
    // 0x80012AB0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80012AB4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012AB8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80012ABC: nop

    // 0x80012AC0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80012AC4: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80012AC8: nop

    // 0x80012ACC: blez        $t8, L_80012B34
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80012AD0: nop
    
            goto L_80012B34;
    }
    // 0x80012AD0: nop

L_80012AD4:
    // 0x80012AD4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80012AD8: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80012ADC: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x80012AE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80012AE4: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80012AE8: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
    // 0x80012AEC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80012AF0: nop

    // 0x80012AF4: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80012AF8: nop

    // 0x80012AFC: ori         $t2, $t4, 0x200
    ctx->r10 = ctx->r12 | 0X200;
    // 0x80012B00: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x80012B04: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80012B08: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80012B0C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012B10: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80012B14: addiu       $t8, $t6, 0x160
    ctx->r24 = ADD32(ctx->r14, 0X160);
    // 0x80012B18: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80012B1C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80012B20: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x80012B24: nop

    // 0x80012B28: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80012B2C: bne         $at, $zero, L_80012AD4
    if (ctx->r1 != 0) {
        // 0x80012B30: nop
    
            goto L_80012AD4;
    }
    // 0x80012B30: nop

L_80012B34:
    // 0x80012B34: b           L_80012E5C
    // 0x80012B38: nop

        goto L_80012E5C;
    // 0x80012B38: nop

L_80012B3C:
    // 0x80012B3C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80012B40: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012B44: lw          $t4, 0xC($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC);
    // 0x80012B48: nop

    // 0x80012B4C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80012B50: lhu         $t2, 0x6($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X6);
    // 0x80012B54: nop

    // 0x80012B58: blez        $t2, L_80012BA8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80012B5C: nop
    
            goto L_80012BA8;
    }
    // 0x80012B5C: nop

L_80012B60:
    // 0x80012B60: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80012B64: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80012B68: lw          $t5, 0xC0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC0);
    // 0x80012B6C: ori         $at, $at, 0xFDFF
    ctx->r1 = ctx->r1 | 0XFDFF;
    // 0x80012B70: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80012B74: sw          $t6, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r14;
    // 0x80012B78: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80012B7C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80012B80: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80012B84: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80012B88: addiu       $t1, $t7, 0x160
    ctx->r9 = ADD32(ctx->r15, 0X160);
    // 0x80012B8C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80012B90: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80012B94: lhu         $t9, 0x6($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X6);
    // 0x80012B98: nop

    // 0x80012B9C: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80012BA0: bne         $at, $zero, L_80012B60
    if (ctx->r1 != 0) {
        // 0x80012BA4: nop
    
            goto L_80012B60;
    }
    // 0x80012BA4: nop

L_80012BA8:
    // 0x80012BA8: b           L_80012E5C
    // 0x80012BAC: nop

        goto L_80012E5C;
    // 0x80012BAC: nop

L_80012BB0:
    // 0x80012BB0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012BB4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012BB8: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x80012BBC: nop

    // 0x80012BC0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80012BC4: lhu         $t6, 0x6($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X6);
    // 0x80012BC8: nop

    // 0x80012BCC: blez        $t6, L_80012C34
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80012BD0: nop
    
            goto L_80012C34;
    }
    // 0x80012BD0: nop

L_80012BD4:
    // 0x80012BD4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80012BD8: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80012BDC: lw          $t8, 0xC0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0XC0);
    // 0x80012BE0: nop

    // 0x80012BE4: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x80012BE8: sw          $t7, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r15;
    // 0x80012BEC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80012BF0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80012BF4: lw          $t4, 0xC0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC0);
    // 0x80012BF8: nop

    // 0x80012BFC: or          $t0, $t4, $at
    ctx->r8 = ctx->r12 | ctx->r1;
    // 0x80012C00: sw          $t0, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r8;
    // 0x80012C04: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80012C08: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80012C0C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80012C10: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80012C14: addiu       $t6, $t2, 0x160
    ctx->r14 = ADD32(ctx->r10, 0X160);
    // 0x80012C18: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80012C1C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80012C20: lhu         $t7, 0x6($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X6);
    // 0x80012C24: nop

    // 0x80012C28: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80012C2C: bne         $at, $zero, L_80012BD4
    if (ctx->r1 != 0) {
        // 0x80012C30: nop
    
            goto L_80012BD4;
    }
    // 0x80012C30: nop

L_80012C34:
    // 0x80012C34: b           L_80012E5C
    // 0x80012C38: nop

        goto L_80012E5C;
    // 0x80012C38: nop

L_80012C3C:
    // 0x80012C3C: addiu       $t3, $sp, 0x2C
    ctx->r11 = ADD32(ctx->r29, 0X2C);
    // 0x80012C40: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80012C44: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012C48: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80012C4C: nop

    // 0x80012C50: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80012C54: swc1        $f8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f8.u32l;
    // 0x80012C58: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80012C5C: lh          $t1, 0x721C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X721C);
    // 0x80012C60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012C64: bne         $t1, $at, L_80012DD8
    if (ctx->r9 != ctx->r1) {
        // 0x80012C68: nop
    
            goto L_80012DD8;
    }
    // 0x80012C68: nop

    // 0x80012C6C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80012C70: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80012C74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80012C78: lwc1        $f10, 0x24($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X24);
    // 0x80012C7C: nop

    // 0x80012C80: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80012C84: nop

    // 0x80012C88: bc1f        L_80012D34
    if (!c1cs) {
        // 0x80012C8C: nop
    
            goto L_80012D34;
    }
    // 0x80012C8C: nop

    // 0x80012C90: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012C94: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012C98: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x80012C9C: nop

    // 0x80012CA0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80012CA4: lhu         $t8, 0x6($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X6);
    // 0x80012CA8: nop

    // 0x80012CAC: blez        $t8, L_80012D2C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80012CB0: nop
    
            goto L_80012D2C;
    }
    // 0x80012CB0: nop

L_80012CB4:
    // 0x80012CB4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80012CB8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80012CBC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80012CC0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012CC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012CC8: lwc1        $f18, 0x24($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X24);
    // 0x80012CCC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80012CD0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80012CD4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80012CD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80012CDC: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x80012CE0: nop

    // 0x80012CE4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80012CE8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80012CEC: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x80012CF0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80012CF4: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x80012CF8: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x80012CFC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80012D00: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80012D04: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80012D08: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x80012D0C: addiu       $t5, $t8, 0x160
    ctx->r13 = ADD32(ctx->r24, 0X160);
    // 0x80012D10: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80012D14: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80012D18: lhu         $t3, 0x6($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X6);
    // 0x80012D1C: nop

    // 0x80012D20: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80012D24: bne         $at, $zero, L_80012CB4
    if (ctx->r1 != 0) {
        // 0x80012D28: nop
    
            goto L_80012CB4;
    }
    // 0x80012D28: nop

L_80012D2C:
    // 0x80012D2C: b           L_80012DD0
    // 0x80012D30: nop

        goto L_80012DD0;
    // 0x80012D30: nop

L_80012D34:
    // 0x80012D34: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80012D38: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012D3C: lw          $t1, 0xC($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC);
    // 0x80012D40: nop

    // 0x80012D44: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80012D48: lhu         $t9, 0x6($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X6);
    // 0x80012D4C: nop

    // 0x80012D50: blez        $t9, L_80012DD0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80012D54: nop
    
            goto L_80012DD0;
    }
    // 0x80012D54: nop

L_80012D58:
    // 0x80012D58: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80012D5C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012D60: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80012D64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012D68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012D6C: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80012D70: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80012D74: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80012D78: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80012D7C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80012D80: sh          $t8, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r24;
    // 0x80012D84: nop

    // 0x80012D88: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80012D8C: nop

    // 0x80012D90: lw          $t2, 0xC0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0XC0);
    // 0x80012D94: nop

    // 0x80012D98: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x80012D9C: sw          $t3, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r11;
    // 0x80012DA0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80012DA4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80012DA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80012DAC: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x80012DB0: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80012DB4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80012DB8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80012DBC: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80012DC0: nop

    // 0x80012DC4: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80012DC8: bne         $at, $zero, L_80012D58
    if (ctx->r1 != 0) {
        // 0x80012DCC: nop
    
            goto L_80012D58;
    }
    // 0x80012DCC: nop

L_80012DD0:
    // 0x80012DD0: b           L_80012E5C
    // 0x80012DD4: nop

        goto L_80012E5C;
    // 0x80012DD4: nop

L_80012DD8:
    // 0x80012DD8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80012DDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012DE0: lw          $t2, 0xC($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC);
    // 0x80012DE4: nop

    // 0x80012DE8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80012DEC: lhu         $t3, 0x6($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X6);
    // 0x80012DF0: nop

    // 0x80012DF4: blez        $t3, L_80012E5C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80012DF8: nop
    
            goto L_80012E5C;
    }
    // 0x80012DF8: nop

L_80012DFC:
    // 0x80012DFC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80012E00: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80012E04: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80012E08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012E0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012E10: lwc1        $f10, 0x24($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X24);
    // 0x80012E14: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80012E18: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80012E1C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80012E20: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80012E24: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
    // 0x80012E28: nop

    // 0x80012E2C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80012E30: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80012E34: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80012E38: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x80012E3C: addiu       $t2, $t8, 0x160
    ctx->r10 = ADD32(ctx->r24, 0X160);
    // 0x80012E40: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80012E44: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80012E48: lhu         $t3, 0x6($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X6);
    // 0x80012E4C: nop

    // 0x80012E50: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80012E54: bne         $at, $zero, L_80012DFC
    if (ctx->r1 != 0) {
        // 0x80012E58: nop
    
            goto L_80012DFC;
    }
    // 0x80012E58: nop

L_80012E5C:
    // 0x80012E5C: b           L_80012E6C
    // 0x80012E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012E6C;
    // 0x80012E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012E64: b           L_80012E6C
    // 0x80012E68: nop

        goto L_80012E6C;
    // 0x80012E68: nop

L_80012E6C:
    // 0x80012E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012E70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012E74: jr          $ra
    // 0x80012E78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80012E78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __vsDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2160: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x800D2164: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800D2168: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x800D216C: bltz        $v1, L_800D217C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800D2170: nop
    
            goto L_800D217C;
    }
    // 0x800D2170: nop

    // 0x800D2174: jr          $ra
    // 0x800D2178: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D2178: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D217C:
    // 0x800D217C: jr          $ra
    // 0x800D2180: nop

    return;
    // 0x800D2180: nop

;}
RECOMP_FUNC void func_80098C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098C8C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098C90: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098C94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098C98: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80098C9C: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098CA0: jr          $ra
    // 0x80098CA4: nop

    return;
    // 0x80098CA4: nop

    // 0x80098CA8: jr          $ra
    // 0x80098CAC: nop

    return;
    // 0x80098CAC: nop

;}
RECOMP_FUNC void func_80096374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096374: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80096378: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x8009637C: nop

    // 0x80096380: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80096384: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80096388: lw          $t7, 0x6BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA0);
    // 0x8009638C: nop

    // 0x80096390: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80096394: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80096398: lw          $t8, 0x6BA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BA8);
    // 0x8009639C: nop

    // 0x800963A0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800963A4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800963A8: lw          $t9, 0x6BC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6BC0);
    // 0x800963AC: nop

    // 0x800963B0: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x800963B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800963B8: lw          $t0, 0x6C08($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C08);
    // 0x800963BC: nop

    // 0x800963C0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x800963C4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800963C8: lw          $t1, 0x6C14($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C14);
    // 0x800963CC: nop

    // 0x800963D0: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x800963D4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800963D8: lw          $t2, -0x4CE0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CE0);
    // 0x800963DC: nop

    // 0x800963E0: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x800963E4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800963E8: lw          $t3, -0x4CD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CD8);
    // 0x800963EC: nop

    // 0x800963F0: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    // 0x800963F4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800963F8: lw          $t4, -0x4CD0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CD0);
    // 0x800963FC: nop

    // 0x80096400: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x80096404: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096408: lh          $t5, -0x4CC8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4CC8);
    // 0x8009640C: nop

    // 0x80096410: sh          $t5, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r13;
    // 0x80096414: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096418: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009641C: nop

    // 0x80096420: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x80096424: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096428: lwc1        $f6, -0x4534($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8009642C: nop

    // 0x80096430: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    // 0x80096434: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096438: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x8009643C: nop

    // 0x80096440: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80096444: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096448: lwc1        $f10, -0x44D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X44D8);
    // 0x8009644C: nop

    // 0x80096450: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x80096454: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80096458: lw          $t6, -0x44BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44BC);
    // 0x8009645C: nop

    // 0x80096460: sw          $t6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r14;
    // 0x80096464: jr          $ra
    // 0x80096468: nop

    return;
    // 0x80096468: nop

    // 0x8009646C: jr          $ra
    // 0x80096470: nop

    return;
    // 0x80096470: nop

;}
RECOMP_FUNC void func_800661A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800661A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800661A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800661AC: jal         0x80061348
    // 0x800661B0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800661B0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800661B4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800661B8: b           L_800661C8
    // 0x800661BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800661C8;
    // 0x800661BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800661C0: b           L_800661C8
    // 0x800661C4: nop

        goto L_800661C8;
    // 0x800661C4: nop

L_800661C8:
    // 0x800661C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800661CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800661D0: jr          $ra
    // 0x800661D4: nop

    return;
    // 0x800661D4: nop

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
RECOMP_FUNC void func_80066C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066C8C: jal         0x80061348
    // 0x80066C90: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066C90: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x80066C94: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066C98: b           L_80066CA8
    // 0x80066C9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066CA8;
    // 0x80066C9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066CA0: b           L_80066CA8
    // 0x80066CA4: nop

        goto L_80066CA8;
    // 0x80066CA4: nop

L_80066CA8:
    // 0x80066CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066CB0: jr          $ra
    // 0x80066CB4: nop

    return;
    // 0x80066CB4: nop

;}
RECOMP_FUNC void func_8008CE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CE90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CE98: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8008CE9C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8008CEA0: jal         0x80021FF8
    // 0x8008CEA4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_80021FF8(rdram, ctx);
        goto after_0;
    // 0x8008CEA4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_0:
    // 0x8008CEA8: jal         0x80098BF4
    // 0x8008CEAC: nop

    func_80098BF4(rdram, ctx);
        goto after_1;
    // 0x8008CEAC: nop

    after_1:
    // 0x8008CEB0: jal         0x800BC6EC
    // 0x8008CEB4: addiu       $a0, $zero, 0x3B8
    ctx->r4 = ADD32(0, 0X3B8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8008CEB4: addiu       $a0, $zero, 0x3B8
    ctx->r4 = ADD32(0, 0X3B8);
    after_2:
    // 0x8008CEB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8008CEBC: sw          $v0, -0x76BC($at)
    MEM_W(-0X76BC, ctx->r1) = ctx->r2;
    // 0x8008CEC0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008CEC4: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8008CEC8: nop

    // 0x8008CECC: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
    // 0x8008CED0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008CED4: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8008CED8: nop

    // 0x8008CEDC: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x8008CEE0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CEE4: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CEE8: jal         0x8008D29C
    // 0x8008CEEC: nop

    func_8008D29C(rdram, ctx);
        goto after_3;
    // 0x8008CEEC: nop

    after_3:
    // 0x8008CEF0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008CEF4: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8008CEF8: nop

    // 0x8008CEFC: sh          $zero, 0x4($t8)
    MEM_H(0X4, ctx->r24) = 0;
    // 0x8008CF00: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008CF04: lw          $t9, -0x76BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76BC);
    // 0x8008CF08: nop

    // 0x8008CF0C: sh          $zero, 0x168($t9)
    MEM_H(0X168, ctx->r25) = 0;
    // 0x8008CF10: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8008CF14: lw          $t1, -0x76BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76BC);
    // 0x8008CF18: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8008CF1C: sh          $t0, 0x16A($t1)
    MEM_H(0X16A, ctx->r9) = ctx->r8;
    // 0x8008CF20: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CF24: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CF28: jal         0x8008E2E0
    // 0x8008CF2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8008E2E0(rdram, ctx);
        goto after_4;
    // 0x8008CF2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_4:
    // 0x8008CF30: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8008CF34: lw          $t3, -0x76BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76BC);
    // 0x8008CF38: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008CF3C: sh          $t2, 0x120($t3)
    MEM_H(0X120, ctx->r11) = ctx->r10;
    // 0x8008CF40: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8008CF44: lw          $t4, -0x76BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76BC);
    // 0x8008CF48: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8008CF4C: sh          $zero, 0x124($t4)
    MEM_H(0X124, ctx->r12) = 0;
    // 0x8008CF50: lw          $t5, -0x76BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76BC);
    // 0x8008CF54: nop

    // 0x8008CF58: lh          $t6, 0x124($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X124);
    // 0x8008CF5C: nop

    // 0x8008CF60: sh          $t6, 0x122($t5)
    MEM_H(0X122, ctx->r13) = ctx->r14;
    // 0x8008CF64: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CF68: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CF6C: jal         0x8008DFA8
    // 0x8008CF70: nop

    func_8008DFA8(rdram, ctx);
        goto after_5;
    // 0x8008CF70: nop

    after_5:
    // 0x8008CF74: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008CF78: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8008CF7C: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x8008CF80: sh          $t7, 0x126($t8)
    MEM_H(0X126, ctx->r24) = ctx->r15;
    // 0x8008CF84: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8008CF88: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008CF8C: lw          $t9, -0x76BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76BC);
    // 0x8008CF90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008CF94: nop

    // 0x8008CF98: swc1        $f4, 0x320($t9)
    MEM_W(0X320, ctx->r25) = ctx->f4.u32l;
    // 0x8008CF9C: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x8008CFA0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8008CFA4: lw          $t0, -0x76BC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76BC);
    // 0x8008CFA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008CFAC: nop

    // 0x8008CFB0: swc1        $f6, 0x324($t0)
    MEM_W(0X324, ctx->r8) = ctx->f6.u32l;
    // 0x8008CFB4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CFB8: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CFBC: jal         0x8001A690
    // 0x8008CFC0: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001A690(rdram, ctx);
        goto after_6;
    // 0x8008CFC0: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_6:
    // 0x8008CFC4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8008CFC8: lw          $t2, -0x76BC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76BC);
    // 0x8008CFCC: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8008CFD0: sh          $t1, 0x234($t2)
    MEM_H(0X234, ctx->r10) = ctx->r9;
    // 0x8008CFD4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8008CFD8: lw          $t3, -0x76BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76BC);
    // 0x8008CFDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008CFE0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8008CFE4: swc1        $f8, 0x240($t3)
    MEM_W(0X240, ctx->r11) = ctx->f8.u32l;
    // 0x8008CFE8: lw          $t4, -0x76BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76BC);
    // 0x8008CFEC: nop

    // 0x8008CFF0: lwc1        $f10, 0x240($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X240);
    // 0x8008CFF4: nop

    // 0x8008CFF8: swc1        $f10, 0x23C($t4)
    MEM_W(0X23C, ctx->r12) = ctx->f10.u32l;
    // 0x8008CFFC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8008D000: lw          $t5, -0x76BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76BC);
    // 0x8008D004: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8008D008: sw          $t6, 0x238($t5)
    MEM_W(0X238, ctx->r13) = ctx->r14;
    // 0x8008D00C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D010: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D014: jal         0x8008E358
    // 0x8008D018: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E358(rdram, ctx);
        goto after_7;
    // 0x8008D018: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_7:
    // 0x8008D01C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D020: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D028: jal         0x8008E184
    // 0x8008D02C: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E184(rdram, ctx);
        goto after_8;
    // 0x8008D02C: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_8:
    // 0x8008D030: jal         0x8008DD40
    // 0x8008D034: nop

    func_8008DD40(rdram, ctx);
        goto after_9;
    // 0x8008D034: nop

    after_9:
    // 0x8008D038: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D03C: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8008D040: nop

    // 0x8008D044: sw          $v0, 0x3A8($t7)
    MEM_W(0X3A8, ctx->r15) = ctx->r2;
    // 0x8008D048: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D04C: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8008D050: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008D054: addiu       $t9, $t9, 0x4C20
    ctx->r25 = ADD32(ctx->r25, 0X4C20);
    // 0x8008D058: sh          $zero, 0x3AC($t8)
    MEM_H(0X3AC, ctx->r24) = 0;
    // 0x8008D05C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8008D060: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008D064: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008D068: beq         $t0, $at, L_8008D0AC
    if (ctx->r8 == ctx->r1) {
        // 0x8008D06C: nop
    
            goto L_8008D0AC;
    }
    // 0x8008D06C: nop

L_8008D070:
    // 0x8008D070: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8008D074: lw          $t1, -0x76BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76BC);
    // 0x8008D078: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008D07C: lh          $t2, 0x3AC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X3AC);
    // 0x8008D080: nop

    // 0x8008D084: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008D088: sh          $t3, 0x3AC($t1)
    MEM_H(0X3AC, ctx->r9) = ctx->r11;
    // 0x8008D08C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D090: nop

    // 0x8008D094: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8008D098: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8008D09C: lbu         $t5, 0x0($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X0);
    // 0x8008D0A0: nop

    // 0x8008D0A4: bne         $t5, $at, L_8008D070
    if (ctx->r13 != ctx->r1) {
        // 0x8008D0A8: nop
    
            goto L_8008D070;
    }
    // 0x8008D0A8: nop

L_8008D0AC:
    // 0x8008D0AC: b           L_8008D0BC
    // 0x8008D0B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D0BC;
    // 0x8008D0B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D0B4: b           L_8008D0BC
    // 0x8008D0B8: nop

        goto L_8008D0BC;
    // 0x8008D0B8: nop

L_8008D0BC:
    // 0x8008D0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D0C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008D0C4: jr          $ra
    // 0x8008D0C8: nop

    return;
    // 0x8008D0C8: nop

;}
RECOMP_FUNC void func_8002BC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BC84: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002BC88: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002BC8C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002BC90: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002BC94: nop

    // 0x8002BC98: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8002BC9C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8002BCA0: slt         $a2, $at, $a1
    ctx->r6 = SIGNED(ctx->r1) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002BCA4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002BCA8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002BCAC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8002BCB0: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002BCB4: beq         $a2, $zero, L_8002BCC0
    if (ctx->r6 == 0) {
        // 0x8002BCB8: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8002BCC0;
    }
    // 0x8002BCB8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8002BCBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8002BCC0:
    // 0x8002BCC0: bgez        $a1, L_8002BCD0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8002BCC4: sra         $t9, $a1, 3
        ctx->r25 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8002BCD0;
    }
    // 0x8002BCC4: sra         $t9, $a1, 3
    ctx->r25 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002BCC8: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8002BCCC: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8002BCD0:
    // 0x8002BCD0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002BCD4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002BCD8: lbu         $t0, -0x4144($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X4144);
    // 0x8002BCDC: bgez        $a1, L_8002BCF0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8002BCE0: andi        $t1, $a1, 0x7
        ctx->r9 = ctx->r5 & 0X7;
            goto L_8002BCF0;
    }
    // 0x8002BCE0: andi        $t1, $a1, 0x7
    ctx->r9 = ctx->r5 & 0X7;
    // 0x8002BCE4: beq         $t1, $zero, L_8002BCF0
    if (ctx->r9 == 0) {
        // 0x8002BCE8: nop
    
            goto L_8002BCF0;
    }
    // 0x8002BCE8: nop

    // 0x8002BCEC: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
L_8002BCF0:
    // 0x8002BCF0: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8002BCF4: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x8002BCF8: srav        $t4, $t0, $t3
    ctx->r12 = S32(SIGNED(ctx->r8) >> (ctx->r11 & 31));
    // 0x8002BCFC: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8002BD00: beq         $t5, $zero, L_8002BD40
    if (ctx->r13 == 0) {
        // 0x8002BD04: nop
    
            goto L_8002BD40;
    }
    // 0x8002BD04: nop

    // 0x8002BD08: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8002BD0C: nop

    // 0x8002BD10: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002BD14: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8002BD18: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8002BD1C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8002BD20: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8002BD24: ori         $t8, $t8, 0xC02
    ctx->r24 = ctx->r24 | 0XC02;
    // 0x8002BD28: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8002BD2C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8002BD30: nop

    // 0x8002BD34: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8002BD38: b           L_8002BD70
    // 0x8002BD3C: nop

        goto L_8002BD70;
    // 0x8002BD3C: nop

L_8002BD40:
    // 0x8002BD40: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8002BD44: nop

    // 0x8002BD48: addiu       $t0, $t1, 0x8
    ctx->r8 = ADD32(ctx->r9, 0X8);
    // 0x8002BD4C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8002BD50: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8002BD54: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8002BD58: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8002BD5C: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x8002BD60: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8002BD64: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8002BD68: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x8002BD6C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_8002BD70:
    // 0x8002BD70: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8002BD74: nop

    // 0x8002BD78: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8002BD7C: b           L_8002BD84
    // 0x8002BD80: nop

        goto L_8002BD84;
    // 0x8002BD80: nop

L_8002BD84:
    // 0x8002BD84: jr          $ra
    // 0x8002BD88: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002BD88: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80056590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80056594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056598: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005659C: lhu         $a0, 0x20($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X20);
    // 0x800565A0: nop

    // 0x800565A4: andi        $t6, $a0, 0x1FFF
    ctx->r14 = ctx->r4 & 0X1FFF;
    // 0x800565A8: jal         0x800561E4
    // 0x800565AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800561E4(rdram, ctx);
        goto after_0;
    // 0x800565AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800565B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800565B4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800565B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800565BC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800565C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800565C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800565C8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800565CC: lh          $t9, -0x2A1E($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2A1E);
    // 0x800565D0: nop

    // 0x800565D4: sh          $t9, 0x60($t0)
    MEM_H(0X60, ctx->r8) = ctx->r25;
    // 0x800565D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800565DC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800565E0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800565E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800565E8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800565EC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800565F0: lh          $t3, -0x2A1C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2A1C);
    // 0x800565F4: nop

    // 0x800565F8: sh          $t3, 0x62($t4)
    MEM_H(0X62, ctx->r12) = ctx->r11;
    // 0x800565FC: lh          $t5, 0x22($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X22);
    // 0x80056600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056604: beq         $t5, $at, L_80056638
    if (ctx->r13 == ctx->r1) {
        // 0x80056608: nop
    
            goto L_80056638;
    }
    // 0x80056608: nop

    // 0x8005660C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056610: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80056614: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80056618: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005661C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80056620: bne         $t0, $zero, L_80056630
    if (ctx->r8 != 0) {
        // 0x80056624: andi        $t1, $t9, 0x400
        ctx->r9 = ctx->r25 & 0X400;
            goto L_80056630;
    }
    // 0x80056624: andi        $t1, $t9, 0x400
    ctx->r9 = ctx->r25 & 0X400;
    // 0x80056628: beq         $t1, $zero, L_80056638
    if (ctx->r9 == 0) {
        // 0x8005662C: nop
    
            goto L_80056638;
    }
    // 0x8005662C: nop

L_80056630:
    // 0x80056630: b           L_80056648
    // 0x80056634: sh          $zero, 0x64($t6)
    MEM_H(0X64, ctx->r14) = 0;
        goto L_80056648;
    // 0x80056634: sh          $zero, 0x64($t6)
    MEM_H(0X64, ctx->r14) = 0;
L_80056638:
    // 0x80056638: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005663C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80056640: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80056644: sh          $t7, 0x64($t2)
    MEM_H(0X64, ctx->r10) = ctx->r15;
L_80056648:
    // 0x80056648: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005664C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80056650: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80056654: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80056658: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005665C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80056660: lh          $t5, -0x2A1A($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2A1A);
    // 0x80056664: nop

    // 0x80056668: sh          $t5, 0x66($t8)
    MEM_H(0X66, ctx->r24) = ctx->r13;
    // 0x8005666C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80056670: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056674: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80056678: lhu         $t0, 0x62($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X62);
    // 0x8005667C: nop

    // 0x80056680: bne         $t0, $at, L_800566D0
    if (ctx->r8 != ctx->r1) {
        // 0x80056684: nop
    
            goto L_800566D0;
    }
    // 0x80056684: nop

    // 0x80056688: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005668C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80056690: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80056694: lw          $t6, 0x5C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X5C);
    // 0x80056698: nop

    // 0x8005669C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800566A0: nop

    // 0x800566A4: beq         $t7, $at, L_800566C0
    if (ctx->r15 == ctx->r1) {
        // 0x800566A8: nop
    
            goto L_800566C0;
    }
    // 0x800566A8: nop

    // 0x800566AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800566B0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800566B4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800566B8: b           L_800566D0
    // 0x800566BC: sh          $t2, 0x62($t3)
    MEM_H(0X62, ctx->r11) = ctx->r10;
        goto L_800566D0;
    // 0x800566BC: sh          $t2, 0x62($t3)
    MEM_H(0X62, ctx->r11) = ctx->r10;
L_800566C0:
    // 0x800566C0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800566C4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800566C8: addiu       $t4, $zero, 0x15A
    ctx->r12 = ADD32(0, 0X15A);
    // 0x800566CC: sh          $t4, 0x60($t5)
    MEM_H(0X60, ctx->r13) = ctx->r12;
L_800566D0:
    // 0x800566D0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800566D4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800566D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800566DC: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x800566E0: lhu         $t2, 0x60($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X60);
    // 0x800566E4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800566E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800566EC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800566F0: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x800566F4: lh          $t6, -0x28C0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X28C0);
    // 0x800566F8: addiu       $a1, $t8, 0x68
    ctx->r5 = ADD32(ctx->r24, 0X68);
    // 0x800566FC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80056700: addiu       $a2, $t8, 0x6A
    ctx->r6 = ADD32(ctx->r24, 0X6A);
    // 0x80056704: jal         0x800B3230
    // 0x80056708: or          $a3, $t7, $t2
    ctx->r7 = ctx->r15 | ctx->r10;
    func_800B3230(rdram, ctx);
        goto after_1;
    // 0x80056708: or          $a3, $t7, $t2
    ctx->r7 = ctx->r15 | ctx->r10;
    after_1:
    // 0x8005670C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80056710: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80056714: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80056718: lhu         $t4, 0x62($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X62);
    // 0x8005671C: nop

    // 0x80056720: bne         $t4, $at, L_800567AC
    if (ctx->r12 != ctx->r1) {
        // 0x80056724: nop
    
            goto L_800567AC;
    }
    // 0x80056724: nop

    // 0x80056728: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005672C: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80056730: nop

    // 0x80056734: lh          $t9, 0xA($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XA);
    // 0x80056738: nop

    // 0x8005673C: slti        $at, $t9, 0x321
    ctx->r1 = SIGNED(ctx->r25) < 0X321 ? 1 : 0;
    // 0x80056740: bne         $at, $zero, L_800567AC
    if (ctx->r1 != 0) {
        // 0x80056744: nop
    
            goto L_800567AC;
    }
    // 0x80056744: nop

    // 0x80056748: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005674C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80056750: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056754: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x80056758: nop

    // 0x8005675C: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80056760: nop

    // 0x80056764: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056768: nop
    
            goto L_800567AC;
    }
    // 0x80056768: nop

    // 0x8005676C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80056770: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056774: nop
    
            goto L_800567AC;
    }
    // 0x80056774: nop

    // 0x80056778: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8005677C: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056780: nop
    
            goto L_800567AC;
    }
    // 0x80056780: nop

    // 0x80056784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80056788: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x8005678C: nop
    
            goto L_800567AC;
    }
    // 0x8005678C: nop

    // 0x80056790: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80056794: beq         $t6, $at, L_800567AC
    if (ctx->r14 == ctx->r1) {
        // 0x80056798: nop
    
            goto L_800567AC;
    }
    // 0x80056798: nop

    // 0x8005679C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800567A0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800567A4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800567A8: sh          $t8, 0x62($t7)
    MEM_H(0X62, ctx->r15) = ctx->r24;
L_800567AC:
    // 0x800567AC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800567B0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800567B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800567B8: lhu         $t3, 0x66($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X66);
    // 0x800567BC: nop

    // 0x800567C0: beq         $t3, $at, L_800567D8
    if (ctx->r11 == ctx->r1) {
        // 0x800567C4: nop
    
            goto L_800567D8;
    }
    // 0x800567C4: nop

    // 0x800567C8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800567CC: nop

    // 0x800567D0: bgez        $t4, L_80056808
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800567D4: nop
    
            goto L_80056808;
    }
    // 0x800567D4: nop

L_800567D8:
    // 0x800567D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800567DC: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800567E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800567E4: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x800567E8: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x800567EC: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x800567F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800567F4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800567F8: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x800567FC: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80056800: b           L_80056830
    // 0x80056804: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_80056830;
    // 0x80056804: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80056808:
    // 0x80056808: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005680C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056810: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80056814: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80056818: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x8005681C: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80056820: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x80056824: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x80056828: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8005682C: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80056830:
    // 0x80056830: b           L_80056838
    // 0x80056834: nop

        goto L_80056838;
    // 0x80056834: nop

L_80056838:
    // 0x80056838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005683C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80056840: jr          $ra
    // 0x80056844: nop

    return;
    // 0x80056844: nop

;}
RECOMP_FUNC void func_80086E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086E6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80086E70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086E74: jal         0x8008B4EC
    // 0x80086E78: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086E78: nop

    after_0:
    // 0x80086E7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086E80: jal         0x8008B600
    // 0x80086E84: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086E84: nop

    after_1:
    // 0x80086E88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80086E90: jal         0x8008B738
    // 0x80086E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80086E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80086E98: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80086E9C: jal         0x8008A518
    // 0x80086EA0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80086EA0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80086EA4: beq         $v0, $zero, L_80086F3C
    if (ctx->r2 == 0) {
        // 0x80086EA8: nop
    
            goto L_80086F3C;
    }
    // 0x80086EA8: nop

    // 0x80086EAC: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086EB0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086EB4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086EB8: bne         $at, $zero, L_80086F3C
    if (ctx->r1 != 0) {
        // 0x80086EBC: nop
    
            goto L_80086F3C;
    }
    // 0x80086EBC: nop

    // 0x80086EC0: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80086EC4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086EC8: beq         $at, $zero, L_80086F3C
    if (ctx->r1 == 0) {
        // 0x80086ECC: nop
    
            goto L_80086F3C;
    }
    // 0x80086ECC: nop

    // 0x80086ED0: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086ED4: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086ED8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086EDC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086EE0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086EE4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086EE8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086EEC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80086EF0: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086EF4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80086EF8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80086EFC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80086F00: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80086F04: nop

    // 0x80086F08: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086F0C: nop

    // 0x80086F10: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086F14: beq         $t4, $zero, L_80086F3C
    if (ctx->r12 == 0) {
        // 0x80086F18: nop
    
            goto L_80086F3C;
    }
    // 0x80086F18: nop

    // 0x80086F1C: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80086F20: beq         $t5, $zero, L_80086F3C
    if (ctx->r13 == 0) {
        // 0x80086F24: nop
    
            goto L_80086F3C;
    }
    // 0x80086F24: nop

    // 0x80086F28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80086F2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086F30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086F34: jal         0x8008B738
    // 0x80086F38: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80086F38: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_4:
L_80086F3C:
    // 0x80086F3C: b           L_80086F44
    // 0x80086F40: nop

        goto L_80086F44;
    // 0x80086F40: nop

L_80086F44:
    // 0x80086F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086F4C: jr          $ra
    // 0x80086F50: nop

    return;
    // 0x80086F50: nop

;}
RECOMP_FUNC void func_80096E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096E58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80096E64: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80096E68: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80096E6C: jal         0x800BC6EC
    // 0x80096E70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80096E70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_0:
    // 0x80096E74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80096E78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80096E7C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80096E80: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80096E84: jal         0x8008ED4C
    // 0x80096E88: addiu       $a1, $a1, -0x9F0
    ctx->r5 = ADD32(ctx->r5, -0X9F0);
    func_8008ED4C(rdram, ctx);
        goto after_1;
    // 0x80096E88: addiu       $a1, $a1, -0x9F0
    ctx->r5 = ADD32(ctx->r5, -0X9F0);
    after_1:
    // 0x80096E8C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80096E90: b           L_80096EA0
    // 0x80096E94: nop

        goto L_80096EA0;
    // 0x80096E94: nop

    // 0x80096E98: b           L_80096EA0
    // 0x80096E9C: nop

        goto L_80096EA0;
    // 0x80096E9C: nop

L_80096EA0:
    // 0x80096EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096EA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096EA8: jr          $ra
    // 0x80096EAC: nop

    return;
    // 0x80096EAC: nop

;}
RECOMP_FUNC void func_80073890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073898: jal         0x80061488
    // 0x8007389C: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007389C: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x800738A0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800738A4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800738A8: b           L_800738B8
    // 0x800738AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800738B8;
    // 0x800738AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800738B0: b           L_800738B8
    // 0x800738B4: nop

        goto L_800738B8;
    // 0x800738B4: nop

L_800738B8:
    // 0x800738B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800738BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800738C0: jr          $ra
    // 0x800738C4: nop

    return;
    // 0x800738C4: nop

;}
RECOMP_FUNC void func_800745FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800745FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074604: jal         0x80061348
    // 0x80074608: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074608: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007460C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074610: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074614: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074618: beq         $v0, $zero, L_8007466C
    if (ctx->r2 == 0) {
        // 0x8007461C: nop
    
            goto L_8007466C;
    }
    // 0x8007461C: nop

    // 0x80074620: jal         0x80061348
    // 0x80074624: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074624: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074628: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007462C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074634: beq         $v0, $zero, L_8007466C
    if (ctx->r2 == 0) {
        // 0x80074638: nop
    
            goto L_8007466C;
    }
    // 0x80074638: nop

    // 0x8007463C: jal         0x80061348
    // 0x80074640: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074640: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x80074644: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074648: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007464C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074650: beq         $v0, $zero, L_8007466C
    if (ctx->r2 == 0) {
        // 0x80074654: nop
    
            goto L_8007466C;
    }
    // 0x80074654: nop

    // 0x80074658: jal         0x80061348
    // 0x8007465C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007465C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074660: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074664: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074668: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007466C:
    // 0x8007466C: b           L_8007467C
    // 0x80074670: nop

        goto L_8007467C;
    // 0x80074670: nop

    // 0x80074674: b           L_8007467C
    // 0x80074678: nop

        goto L_8007467C;
    // 0x80074678: nop

L_8007467C:
    // 0x8007467C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074684: jr          $ra
    // 0x80074688: nop

    return;
    // 0x80074688: nop

;}
RECOMP_FUNC void AudioDriver_DepthToCents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB5AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BB5B0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800BB5B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BB5B8: lwc1        $f4, -0x23C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X23C);
    // 0x800BB5BC: nop

    // 0x800BB5C0: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800BB5C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB5C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB5CC: nop

    // 0x800BB5D0: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x800BB5D4: beq         $a0, $zero, L_800BB624
    if (ctx->r4 == 0) {
        // 0x800BB5D8: nop
    
            goto L_800BB624;
    }
    // 0x800BB5D8: nop

L_800BB5DC:
    // 0x800BB5DC: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800BB5E0: beq         $t6, $zero, L_800BB5FC
    if (ctx->r14 == 0) {
        // 0x800BB5E4: nop
    
            goto L_800BB5FC;
    }
    // 0x800BB5E4: nop

    // 0x800BB5E8: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800BB5EC: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800BB5F0: nop

    // 0x800BB5F4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BB5F8: swc1        $f16, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f16.u32l;
L_800BB5FC:
    // 0x800BB5FC: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800BB600: nop

    // 0x800BB604: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BB608: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800BB60C: srl         $t7, $a0, 1
    ctx->r15 = S32(U32(ctx->r4) >> 1);
    // 0x800BB610: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800BB614: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800BB618: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800BB61C: bne         $a0, $zero, L_800BB5DC
    if (ctx->r4 != 0) {
        // 0x800BB620: nop
    
            goto L_800BB5DC;
    }
    // 0x800BB620: nop

L_800BB624:
    // 0x800BB624: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800BB628: b           L_800BB638
    // 0x800BB62C: nop

        goto L_800BB638;
    // 0x800BB62C: nop

    // 0x800BB630: b           L_800BB638
    // 0x800BB634: nop

        goto L_800BB638;
    // 0x800BB634: nop

L_800BB638:
    // 0x800BB638: jr          $ra
    // 0x800BB63C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BB63C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80015B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015B6C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80015B70: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x80015B74: nop

    // 0x80015B78: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80015B7C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80015B80: nop

    // 0x80015B84: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80015B88: nop

    // 0x80015B8C: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80015B90: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80015B94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015B98: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80015B9C: nop

    // 0x80015BA0: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x80015BA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015BA8: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80015BAC: nop

    // 0x80015BB0: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x80015BB4: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80015BB8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80015BBC: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x80015BC0: b           L_80015BC8
    // 0x80015BC4: nop

        goto L_80015BC8;
    // 0x80015BC4: nop

L_80015BC8:
    // 0x80015BC8: jr          $ra
    // 0x80015BCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80015BCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80073CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073CF4: jal         0x80061348
    // 0x80073CF8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073CF8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073CFC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073D00: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073D04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073D08: beq         $v0, $zero, L_80073D5C
    if (ctx->r2 == 0) {
        // 0x80073D0C: nop
    
            goto L_80073D5C;
    }
    // 0x80073D0C: nop

    // 0x80073D10: jal         0x80061348
    // 0x80073D14: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073D14: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073D18: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073D1C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073D20: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073D24: beq         $v0, $zero, L_80073D5C
    if (ctx->r2 == 0) {
        // 0x80073D28: nop
    
            goto L_80073D5C;
    }
    // 0x80073D28: nop

    // 0x80073D2C: jal         0x80061348
    // 0x80073D30: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073D30: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073D34: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073D38: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073D3C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073D40: beq         $v0, $zero, L_80073D5C
    if (ctx->r2 == 0) {
        // 0x80073D44: nop
    
            goto L_80073D5C;
    }
    // 0x80073D44: nop

    // 0x80073D48: jal         0x80061348
    // 0x80073D4C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073D4C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073D50: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073D54: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073D58: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073D5C:
    // 0x80073D5C: b           L_80073D6C
    // 0x80073D60: nop

        goto L_80073D6C;
    // 0x80073D60: nop

    // 0x80073D64: b           L_80073D6C
    // 0x80073D68: nop

        goto L_80073D6C;
    // 0x80073D68: nop

L_80073D6C:
    // 0x80073D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073D74: jr          $ra
    // 0x80073D78: nop

    return;
    // 0x80073D78: nop

;}
