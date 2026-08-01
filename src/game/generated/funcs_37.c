#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006F800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F800: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F804: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F808: nop

    // 0x8006F80C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8006F810: nop

    // 0x8006F814: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006F818: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F81C: jr          $ra
    // 0x8006F820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F824: jr          $ra
    // 0x8006F828: nop

    return;
    // 0x8006F828: nop

    // 0x8006F82C: jr          $ra
    // 0x8006F830: nop

    return;
    // 0x8006F830: nop

;}
RECOMP_FUNC void func_8008D728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D72C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D738: jal         0x8008E0A8
    // 0x8008D73C: nop

    func_8008E0A8(rdram, ctx);
        goto after_0;
    // 0x8008D73C: nop

    after_0:
    // 0x8008D740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D744: jal         0x8008E380
    // 0x8008D748: nop

    func_8008E380(rdram, ctx);
        goto after_1;
    // 0x8008D748: nop

    after_1:
    // 0x8008D74C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008D750: nop

    // 0x8008D754: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008D758: nop

    // 0x8008D75C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8008D760: beq         $t8, $zero, L_8008D790
    if (ctx->r24 == 0) {
        // 0x8008D764: nop
    
            goto L_8008D790;
    }
    // 0x8008D764: nop

    // 0x8008D768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D76C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008D770: jal         0x8008E184
    // 0x8008D774: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E184(rdram, ctx);
        goto after_2;
    // 0x8008D774: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_2:
    // 0x8008D778: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008D77C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8008D780: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8008D784: nop

    // 0x8008D788: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8008D78C: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8008D790:
    // 0x8008D790: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008D794: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8008D798: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008D79C: lhu         $t3, 0xFF4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XFF4);
    // 0x8008D7A0: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x8008D7A4: lhu         $t6, 0x3B0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X3B0);
    // 0x8008D7A8: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8008D7AC: and         $t7, $t6, $t4
    ctx->r15 = ctx->r14 & ctx->r12;
    // 0x8008D7B0: beq         $t7, $zero, L_8008D858
    if (ctx->r15 == 0) {
        // 0x8008D7B4: nop
    
            goto L_8008D858;
    }
    // 0x8008D7B4: nop

    // 0x8008D7B8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008D7BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D7C0: lh          $t0, 0x168($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X168);
    // 0x8008D7C4: nop

    // 0x8008D7C8: bne         $t0, $at, L_8008D7E0
    if (ctx->r8 != ctx->r1) {
        // 0x8008D7CC: nop
    
            goto L_8008D7E0;
    }
    // 0x8008D7CC: nop

    // 0x8008D7D0: jal         0x800B9000
    // 0x8008D7D4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8008D7D4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x8008D7D8: b           L_8008D8FC
    // 0x8008D7DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008D8FC;
    // 0x8008D7DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8008D7E0:
    // 0x8008D7E0: jal         0x800B9000
    // 0x8008D7E4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800B9000(rdram, ctx);
        goto after_4;
    // 0x8008D7E4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x8008D7E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D7EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008D7F0: jal         0x8008E184
    // 0x8008D7F4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E184(rdram, ctx);
        goto after_5;
    // 0x8008D7F4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_5:
    // 0x8008D7F8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008D7FC: nop

    // 0x8008D800: lhu         $t9, 0x0($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X0);
    // 0x8008D804: nop

    // 0x8008D808: ori         $t2, $t9, 0x2
    ctx->r10 = ctx->r25 | 0X2;
    // 0x8008D80C: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x8008D810: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008D814: nop

    // 0x8008D818: lhu         $t5, 0x4($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X4);
    // 0x8008D81C: nop

    // 0x8008D820: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008D824: sh          $t6, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r14;
    // 0x8008D828: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008D82C: nop

    // 0x8008D830: lhu         $t7, 0x4($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X4);
    // 0x8008D834: lh          $t0, 0x3AC($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X3AC);
    // 0x8008D838: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008D83C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008D840: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8008D844: bne         $at, $zero, L_8008D858
    if (ctx->r1 != 0) {
        // 0x8008D848: nop
    
            goto L_8008D858;
    }
    // 0x8008D848: nop

    // 0x8008D84C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008D850: nop

    // 0x8008D854: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
L_8008D858:
    // 0x8008D858: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008D85C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008D860: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8008D864: lhu         $t1, 0x3B0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X3B0);
    // 0x8008D868: nop

    // 0x8008D86C: and         $t6, $t1, $t5
    ctx->r14 = ctx->r9 & ctx->r13;
    // 0x8008D870: beq         $t6, $zero, L_8008D888
    if (ctx->r14 == 0) {
        // 0x8008D874: nop
    
            goto L_8008D888;
    }
    // 0x8008D874: nop

    // 0x8008D878: jal         0x800B9000
    // 0x8008D87C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_6;
    // 0x8008D87C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_6:
    // 0x8008D880: b           L_8008D8FC
    // 0x8008D884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008D8FC;
    // 0x8008D884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8008D888:
    // 0x8008D888: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008D88C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008D890: lhu         $t4, 0xEEC($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XEEC);
    // 0x8008D894: lhu         $t7, 0x3AE($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X3AE);
    // 0x8008D898: nop

    // 0x8008D89C: and         $t8, $t7, $t4
    ctx->r24 = ctx->r15 & ctx->r12;
    // 0x8008D8A0: beq         $t8, $zero, L_8008D8B4
    if (ctx->r24 == 0) {
        // 0x8008D8A4: nop
    
            goto L_8008D8B4;
    }
    // 0x8008D8A4: nop

    // 0x8008D8A8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008D8B0: sh          $t0, 0x168($t9)
    MEM_H(0X168, ctx->r25) = ctx->r8;
L_8008D8B4:
    // 0x8008D8B4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008D8BC: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x8008D8C0: lhu         $t1, 0x3AE($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X3AE);
    // 0x8008D8C4: nop

    // 0x8008D8C8: and         $t6, $t1, $t5
    ctx->r14 = ctx->r9 & ctx->r13;
    // 0x8008D8CC: beq         $t6, $zero, L_8008D8E0
    if (ctx->r14 == 0) {
        // 0x8008D8D0: nop
    
            goto L_8008D8E0;
    }
    // 0x8008D8D0: nop

    // 0x8008D8D4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8D8: nop

    // 0x8008D8DC: sh          $zero, 0x168($t3)
    MEM_H(0X168, ctx->r11) = 0;
L_8008D8E0:
    // 0x8008D8E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8E4: jal         0x8008DFA8
    // 0x8008D8E8: nop

    func_8008DFA8(rdram, ctx);
        goto after_7;
    // 0x8008D8E8: nop

    after_7:
    // 0x8008D8EC: b           L_8008D8FC
    // 0x8008D8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008D8FC;
    // 0x8008D8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008D8F4: b           L_8008D8FC
    // 0x8008D8F8: nop

        goto L_8008D8FC;
    // 0x8008D8F8: nop

L_8008D8FC:
    // 0x8008D8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D904: jr          $ra
    // 0x8008D908: nop

    return;
    // 0x8008D908: nop

;}
RECOMP_FUNC void func_80067DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067DC8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067DCC: nop

    // 0x80067DD0: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067DD4: nop

    // 0x80067DD8: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067DDC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067DE0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067DE4: beq         $v0, $zero, L_80067E00
    if (ctx->r2 == 0) {
        // 0x80067DE8: nop
    
            goto L_80067E00;
    }
    // 0x80067DE8: nop

    // 0x80067DEC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067DF0: nop

    // 0x80067DF4: slti        $t8, $v0, 0x258
    ctx->r24 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067DF8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067DFC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067E00:
    // 0x80067E00: jr          $ra
    // 0x80067E04: nop

    return;
    // 0x80067E04: nop

    // 0x80067E08: jr          $ra
    // 0x80067E0C: nop

    return;
    // 0x80067E0C: nop

    // 0x80067E10: jr          $ra
    // 0x80067E14: nop

    return;
    // 0x80067E14: nop

;}
RECOMP_FUNC void func_80088CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088CCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80088CD0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80088CD4: nop

    // 0x80088CD8: lw          $a0, 0x728($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X728);
    // 0x80088CDC: jal         0x8008A674
    // 0x80088CE0: nop

    func_8008A674(rdram, ctx);
        goto after_0;
    // 0x80088CE0: nop

    after_0:
L_80088CE4:
    // 0x80088CE4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80088CE8: nop

    // 0x80088CEC: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80088CF0: nop

    // 0x80088CF4: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x80088CF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80088CFC: jal         0x8008A788
    // 0x80088D00: nop

    func_8008A788(rdram, ctx);
        goto after_1;
    // 0x80088D00: nop

    after_1:
    // 0x80088D04: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80088D08: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x80088D0C: sh          $t9, 0x750($t0)
    MEM_H(0X750, ctx->r8) = ctx->r25;
    // 0x80088D10: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80088D14: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80088D18: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80088D1C: nop

    // 0x80088D20: beq         $t2, $at, L_80088D90
    if (ctx->r10 == ctx->r1) {
        // 0x80088D24: nop
    
            goto L_80088D90;
    }
    // 0x80088D24: nop

    // 0x80088D28: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80088D2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80088D30: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80088D34: nop

    // 0x80088D38: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80088D3C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80088D40: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80088D44: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80088D48: lw          $t6, 0x4530($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4530);
    // 0x80088D4C: nop

    // 0x80088D50: beq         $t6, $zero, L_80088D88
    if (ctx->r14 == 0) {
        // 0x80088D54: nop
    
            goto L_80088D88;
    }
    // 0x80088D54: nop

    // 0x80088D58: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80088D5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D60: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80088D64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80088D68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088D6C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80088D70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80088D74: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80088D78: lw          $t9, 0x4530($at)
    ctx->r25 = MEM_W(ctx->r1, 0X4530);
    // 0x80088D7C: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80088D80: jalr        $t9
    // 0x80088D84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80088D84: nop

    after_2:
L_80088D88:
    // 0x80088D88: b           L_80088DB0
    // 0x80088D8C: nop

        goto L_80088DB0;
    // 0x80088D8C: nop

L_80088D90:
    // 0x80088D90: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80088D94: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80088D98: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80088D9C: nop

    // 0x80088DA0: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80088DA4: sh          $t2, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r10;
    // 0x80088DA8: b           L_80088DE4
    // 0x80088DAC: nop

        goto L_80088DE4;
    // 0x80088DAC: nop

L_80088DB0:
    // 0x80088DB0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80088DB4: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x80088DB8: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80088DBC: nop

    // 0x80088DC0: bne         $t4, $t5, L_80088CE4
    if (ctx->r12 != ctx->r13) {
        // 0x80088DC4: nop
    
            goto L_80088CE4;
    }
    // 0x80088DC4: nop

    // 0x80088DC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80088DCC: jal         0x8008997C
    // 0x80088DD0: nop

    func_8008997C(rdram, ctx);
        goto after_3;
    // 0x80088DD0: nop

    after_3:
    // 0x80088DD4: b           L_80088DE4
    // 0x80088DD8: nop

        goto L_80088DE4;
    // 0x80088DD8: nop

    // 0x80088DDC: b           L_80088DE4
    // 0x80088DE0: nop

        goto L_80088DE4;
    // 0x80088DE0: nop

L_80088DE4:
    // 0x80088DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80088DEC: jr          $ra
    // 0x80088DF0: nop

    return;
    // 0x80088DF0: nop

;}
RECOMP_FUNC void alEnvmixerNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFA5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CFA60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CFA64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CFA68: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CFA6C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CFA70: addiu       $a2, $a2, 0x1134
    ctx->r6 = ADD32(ctx->r6, 0X1134);
    // 0x800CFA74: addiu       $a1, $a1, 0x172C
    ctx->r5 = ADD32(ctx->r5, 0X172C);
    // 0x800CFA78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CFA7C: jal         0x800D56B0
    // 0x800CFA80: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CFA80: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x800CFA84: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800CFA88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CFA8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFA90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFA94: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800CFA98: jal         0x800C7950
    // 0x800CFA9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CFA9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CFAA0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CFAA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800CFAA8: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800CFAAC: sw          $v1, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r3;
    // 0x800CFAB0: sw          $zero, 0x48($t0)
    MEM_W(0X48, ctx->r8) = 0;
    // 0x800CFAB4: sh          $v1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r3;
    // 0x800CFAB8: sh          $v1, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r3;
    // 0x800CFABC: sh          $v1, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r3;
    // 0x800CFAC0: sh          $v1, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r3;
    // 0x800CFAC4: sh          $v1, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = ctx->r3;
    // 0x800CFAC8: sh          $zero, 0x20($t0)
    MEM_H(0X20, ctx->r8) = 0;
    // 0x800CFACC: sh          $zero, 0x22($t0)
    MEM_H(0X22, ctx->r8) = 0;
    // 0x800CFAD0: sh          $v1, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r3;
    // 0x800CFAD4: sh          $zero, 0x24($t0)
    MEM_H(0X24, ctx->r8) = 0;
    // 0x800CFAD8: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800CFADC: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
    // 0x800CFAE0: sh          $zero, 0x18($t0)
    MEM_H(0X18, ctx->r8) = 0;
    // 0x800CFAE4: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x800CFAE8: sw          $zero, 0x40($t0)
    MEM_W(0X40, ctx->r8) = 0;
    // 0x800CFAEC: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    // 0x800CFAF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CFAF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CFAF8: jr          $ra
    // 0x800CFAFC: nop

    return;
    // 0x800CFAFC: nop

;}
RECOMP_FUNC void func_80084D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084D90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80084D94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80084D98: jal         0x8008A46C
    // 0x80084D9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80084D9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80084DA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80084DA4: jal         0x80089170
    // 0x80084DA8: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80084DA8: nop

    after_1:
    // 0x80084DAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80084DB0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80084DB4: jal         0x800898D8
    // 0x80084DB8: addiu       $a2, $zero, 0x4008
    ctx->r6 = ADD32(0, 0X4008);
    func_800898D8(rdram, ctx);
        goto after_2;
    // 0x80084DB8: addiu       $a2, $zero, 0x4008
    ctx->r6 = ADD32(0, 0X4008);
    after_2:
    // 0x80084DBC: beq         $v0, $zero, L_80084E0C
    if (ctx->r2 == 0) {
        // 0x80084DC0: nop
    
            goto L_80084E0C;
    }
    // 0x80084DC0: nop

    // 0x80084DC4: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80084DC8: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x80084DCC: lh          $t9, 0x20($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20);
    // 0x80084DD0: lh          $t0, 0x24($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X24);
    // 0x80084DD4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80084DD8: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80084DDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80084DE0: bgez        $a1, L_80084DF0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80084DE4: sra         $t8, $a1, 1
        ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80084DF0;
    }
    // 0x80084DE4: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80084DE8: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80084DEC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80084DF0:
    // 0x80084DF0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80084DF4: bgez        $a2, L_80084E04
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80084DF8: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80084E04;
    }
    // 0x80084DF8: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084DFC: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80084E00: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80084E04:
    // 0x80084E04: jal         0x80089B04
    // 0x80084E08: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_80089B04(rdram, ctx);
        goto after_3;
    // 0x80084E08: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_3:
L_80084E0C:
    // 0x80084E0C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084E10: nop

    // 0x80084E14: lh          $v0, 0x4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X4);
    // 0x80084E18: b           L_80084E28
    // 0x80084E1C: nop

        goto L_80084E28;
    // 0x80084E1C: nop

    // 0x80084E20: b           L_80084E28
    // 0x80084E24: nop

        goto L_80084E28;
    // 0x80084E24: nop

L_80084E28:
    // 0x80084E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084E2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80084E30: jr          $ra
    // 0x80084E34: nop

    return;
    // 0x80084E34: nop

;}
RECOMP_FUNC void func_80084020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084020: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084028: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008402C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80084030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084034: jal         0x8008C34C
    // 0x80084038: nop

    func_8008C34C(rdram, ctx);
        goto after_0;
    // 0x80084038: nop

    after_0:
    // 0x8008403C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084040: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80084044: beq         $s0, $at, L_80084148
    if (ctx->r16 == ctx->r1) {
        // 0x80084048: nop
    
            goto L_80084148;
    }
    // 0x80084048: nop

    // 0x8008404C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80084050: beq         $s0, $at, L_800840E8
    if (ctx->r16 == ctx->r1) {
        // 0x80084054: nop
    
            goto L_800840E8;
    }
    // 0x80084054: nop

    // 0x80084058: beq         $s0, $zero, L_80084068
    if (ctx->r16 == 0) {
        // 0x8008405C: nop
    
            goto L_80084068;
    }
    // 0x8008405C: nop

    // 0x80084060: b           L_800841A0
    // 0x80084064: nop

        goto L_800841A0;
    // 0x80084064: nop

L_80084068:
    // 0x80084068: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008406C: lhu         $t6, 0x7A10($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7A10);
    // 0x80084070: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084074: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x80084078: sh          $t7, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r15;
    // 0x8008407C: jal         0x800AE580
    // 0x80084080: nop

    ContPak_GetAvailableSlots(rdram, ctx);
        goto after_1;
    // 0x80084080: nop

    after_1:
    // 0x80084084: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80084088: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x8008408C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084090: sh          $t9, 0x7A14($at)
    MEM_H(0X7A14, ctx->r1) = ctx->r25;
    // 0x80084094: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80084098: lw          $t0, 0x1638($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1638);
    // 0x8008409C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800840A0: sh          $t0, 0x7A12($at)
    MEM_H(0X7A12, ctx->r1) = ctx->r8;
    // 0x800840A4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800840A8: nop

    // 0x800840AC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800840B0: nop

    // 0x800840B4: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800840B8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x800840BC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800840C0: nop

    // 0x800840C4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800840C8: nop

    // 0x800840CC: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x800840D0: beq         $t6, $zero, L_800840E0
    if (ctx->r14 == 0) {
        // 0x800840D4: nop
    
            goto L_800840E0;
    }
    // 0x800840D4: nop

    // 0x800840D8: b           L_800841BC
    // 0x800840DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800841BC;
    // 0x800840DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800840E0:
    // 0x800840E0: b           L_800841BC
    // 0x800840E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800841BC;
    // 0x800840E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800840E8:
    // 0x800840E8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800840EC: lhu         $t7, 0x7A10($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7A10);
    // 0x800840F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800840F4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800840F8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800840FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084100: sh          $t8, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r24;
    // 0x80084104: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084108: nop

    // 0x8008410C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80084110: nop

    // 0x80084114: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x80084118: beq         $t2, $zero, L_80084128
    if (ctx->r10 == 0) {
        // 0x8008411C: nop
    
            goto L_80084128;
    }
    // 0x8008411C: nop

    // 0x80084120: b           L_800841BC
    // 0x80084124: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800841BC;
    // 0x80084124: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084128:
    // 0x80084128: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008412C: nop

    // 0x80084130: lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X0);
    // 0x80084134: nop

    // 0x80084138: ori         $t4, $t1, 0x200
    ctx->r12 = ctx->r9 | 0X200;
    // 0x8008413C: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
    // 0x80084140: b           L_800841BC
    // 0x80084144: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800841BC;
    // 0x80084144: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80084148:
    // 0x80084148: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008414C: lhu         $t5, 0x7A10($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7A10);
    // 0x80084150: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80084154: ori         $t6, $t5, 0xC000
    ctx->r14 = ctx->r13 | 0XC000;
    // 0x80084158: sh          $t6, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = ctx->r14;
    // 0x8008415C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80084160: nop

    // 0x80084164: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80084168: nop

    // 0x8008416C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80084170: beq         $t9, $zero, L_80084180
    if (ctx->r25 == 0) {
        // 0x80084174: nop
    
            goto L_80084180;
    }
    // 0x80084174: nop

    // 0x80084178: b           L_800841BC
    // 0x8008417C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800841BC;
    // 0x8008417C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084180:
    // 0x80084180: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084184: nop

    // 0x80084188: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x8008418C: nop

    // 0x80084190: ori         $t1, $t2, 0x200
    ctx->r9 = ctx->r10 | 0X200;
    // 0x80084194: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
    // 0x80084198: b           L_800841BC
    // 0x8008419C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800841BC;
    // 0x8008419C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800841A0:
    // 0x800841A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800841A4: nop

    // 0x800841A8: lh          $v0, 0x4($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X4);
    // 0x800841AC: b           L_800841BC
    // 0x800841B0: nop

        goto L_800841BC;
    // 0x800841B0: nop

    // 0x800841B4: b           L_800841BC
    // 0x800841B8: nop

        goto L_800841BC;
    // 0x800841B8: nop

L_800841BC:
    // 0x800841BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800841C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800841C4: jr          $ra
    // 0x800841C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800841C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
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
RECOMP_FUNC void func_800527C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800527C4: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800527C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800527CC: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800527D0: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800527D4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800527D8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800527DC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800527E0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800527E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800527E8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800527EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800527F0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800527F4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800527F8: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800527FC: lui         $at, 0xFBFB
    ctx->r1 = S32(0XFBFB << 16);
    // 0x80052800: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80052804: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80052808: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8005280C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80052810: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x80052814: nop

    // 0x80052818: beq         $t7, $zero, L_80052830
    if (ctx->r15 == 0) {
        // 0x8005281C: nop
    
            goto L_80052830;
    }
    // 0x8005281C: nop

    // 0x80052820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052824: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80052828: b           L_8005283C
    // 0x8005282C: cvt.d.s     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f20.d = CVT_D_S(ctx->f4.fl);
        goto L_8005283C;
    // 0x8005282C: cvt.d.s     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f20.d = CVT_D_S(ctx->f4.fl);
L_80052830:
    // 0x80052830: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x80052834: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80052838: nop

L_8005283C:
    // 0x8005283C: cvt.s.d     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f6.fl = CVT_S_D(ctx->f20.d);
    // 0x80052840: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052844: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80052848: jal         0x80054198
    // 0x8005284C: nop

    func_80054198(rdram, ctx);
        goto after_0;
    // 0x8005284C: nop

    after_0:
    // 0x80052850: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052854: jal         0x80054264
    // 0x80052858: nop

    func_80054264(rdram, ctx);
        goto after_1;
    // 0x80052858: nop

    after_1:
    // 0x8005285C: beq         $v0, $zero, L_80052888
    if (ctx->r2 == 0) {
        // 0x80052860: nop
    
            goto L_80052888;
    }
    // 0x80052860: nop

    // 0x80052864: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052868: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x8005286C: jal         0x80052508
    // 0x80052870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_2;
    // 0x80052870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80052874: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80052878: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005287C: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80052880: b           L_80053564
    // 0x80052884: nop

        goto L_80053564;
    // 0x80052884: nop

L_80052888:
    // 0x80052888: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005288C: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80052890: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052894: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x80052898: nop
    
            goto L_800528FC;
    }
    // 0x80052898: nop

    // 0x8005289C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800528A0: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528A4: nop
    
            goto L_800528FC;
    }
    // 0x800528A4: nop

    // 0x800528A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800528AC: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528B0: nop
    
            goto L_800528FC;
    }
    // 0x800528B0: nop

    // 0x800528B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800528B8: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528BC: nop
    
            goto L_800528FC;
    }
    // 0x800528BC: nop

    // 0x800528C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800528C4: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528C8: nop
    
            goto L_800528FC;
    }
    // 0x800528C8: nop

    // 0x800528CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800528D0: beq         $t3, $at, L_800528FC
    if (ctx->r11 == ctx->r1) {
        // 0x800528D4: nop
    
            goto L_800528FC;
    }
    // 0x800528D4: nop

    // 0x800528D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800528DC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800528E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800528E4: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x800528E8: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800528EC: bne         $t0, $zero, L_800528FC
    if (ctx->r8 != 0) {
        // 0x800528F0: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_800528FC;
    }
    // 0x800528F0: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x800528F4: beq         $t1, $zero, L_8005293C
    if (ctx->r9 == 0) {
        // 0x800528F8: nop
    
            goto L_8005293C;
    }
    // 0x800528F8: nop

L_800528FC:
    // 0x800528FC: jal         0x80061F08
    // 0x80052900: nop

    func_80061F08(rdram, ctx);
        goto after_3;
    // 0x80052900: nop

    after_3:
    // 0x80052904: bne         $v0, $zero, L_8005293C
    if (ctx->r2 != 0) {
        // 0x80052908: nop
    
            goto L_8005293C;
    }
    // 0x80052908: nop

    // 0x8005290C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052910: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x80052914: nop

    // 0x80052918: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x8005291C: beq         $at, $zero, L_80052934
    if (ctx->r1 == 0) {
        // 0x80052920: nop
    
            goto L_80052934;
    }
    // 0x80052920: nop

    // 0x80052924: jal         0x8005A578
    // 0x80052928: nop

    func_8005A578(rdram, ctx);
        goto after_4;
    // 0x80052928: nop

    after_4:
    // 0x8005292C: beq         $v0, $zero, L_8005293C
    if (ctx->r2 == 0) {
        // 0x80052930: nop
    
            goto L_8005293C;
    }
    // 0x80052930: nop

L_80052934:
    // 0x80052934: b           L_80053564
    // 0x80052938: nop

        goto L_80053564;
    // 0x80052938: nop

L_8005293C:
    // 0x8005293C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052940: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80052944: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052948: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8005294C: lh          $t2, 0xC($t6)
    ctx->r10 = MEM_H(ctx->r14, 0XC);
    // 0x80052950: lh          $t4, 0xE($t6)
    ctx->r12 = MEM_H(ctx->r14, 0XE);
    // 0x80052954: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80052958: lw          $t0, 0x678($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X678);
    // 0x8005295C: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x80052960: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80052964: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80052968: beq         $at, $zero, L_8005298C
    if (ctx->r1 == 0) {
        // 0x8005296C: nop
    
            goto L_8005298C;
    }
    // 0x8005296C: nop

    // 0x80052970: lw          $t1, 0x104($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X104);
    // 0x80052974: nop

    // 0x80052978: bne         $t1, $zero, L_8005298C
    if (ctx->r9 != 0) {
        // 0x8005297C: nop
    
            goto L_8005298C;
    }
    // 0x8005297C: nop

    // 0x80052980: addiu       $t5, $zero, 0x8E
    ctx->r13 = ADD32(0, 0X8E);
    // 0x80052984: b           L_80052994
    // 0x80052988: sh          $t5, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r13;
        goto L_80052994;
    // 0x80052988: sh          $t5, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r13;
L_8005298C:
    // 0x8005298C: addiu       $t7, $zero, 0x71
    ctx->r15 = ADD32(0, 0X71);
    // 0x80052990: sh          $t7, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r15;
L_80052994:
    // 0x80052994: lh          $t2, 0xF6($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XF6);
    // 0x80052998: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x8005299C: bne         $t2, $at, L_800529E0
    if (ctx->r10 != ctx->r1) {
        // 0x800529A0: nop
    
            goto L_800529E0;
    }
    // 0x800529A0: nop

    // 0x800529A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800529A8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800529AC: nop

    // 0x800529B0: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x800529B4: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x800529B8: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x800529BC: ori         $t9, $t5, 0x80
    ctx->r25 = ctx->r13 | 0X80;
    // 0x800529C0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800529C4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800529C8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800529CC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800529D0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800529D4: lw          $t3, 0x258C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X258C);
    // 0x800529D8: nop

    // 0x800529DC: sw          $t3, 0x90($t0)
    MEM_W(0X90, ctx->r8) = ctx->r11;
L_800529E0:
    // 0x800529E0: lh          $a0, 0xF6($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XF6);
    // 0x800529E4: jal         0x80056E88
    // 0x800529E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_5;
    // 0x800529E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800529EC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800529F0: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800529F4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800529F8: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800529FC: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80052A00: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x80052A04: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x80052A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052A0C: jal         0x8004EF90
    // 0x80052A10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_6;
    // 0x80052A10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80052A14: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80052A18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052A1C: sh          $t2, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r10;
L_80052A20:
    // 0x80052A20: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80052A24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052A28: sh          $t4, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r12;
L_80052A2C:
    // 0x80052A2C: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052A30: jal         0x800499B0
    // 0x80052A34: nop

    func_800499B0(rdram, ctx);
        goto after_7;
    // 0x80052A34: nop

    after_7:
    // 0x80052A38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052A3C: lbu         $t5, 0xD74($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0XD74);
    // 0x80052A40: nop

    // 0x80052A44: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80052A48: bne         $at, $zero, L_80052AEC
    if (ctx->r1 != 0) {
        // 0x80052A4C: nop
    
            goto L_80052AEC;
    }
    // 0x80052A4C: nop

    // 0x80052A50: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052A54: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052A58: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80052A5C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80052A60: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80052A64: bne         $t0, $zero, L_80052A74
    if (ctx->r8 != 0) {
        // 0x80052A68: andi        $t1, $t7, 0x80
        ctx->r9 = ctx->r15 & 0X80;
            goto L_80052A74;
    }
    // 0x80052A68: andi        $t1, $t7, 0x80
    ctx->r9 = ctx->r15 & 0X80;
    // 0x80052A6C: beq         $t1, $zero, L_80052AEC
    if (ctx->r9 == 0) {
        // 0x80052A70: nop
    
            goto L_80052AEC;
    }
    // 0x80052A70: nop

L_80052A74:
    // 0x80052A74: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80052A78: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80052A7C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052A80: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x80052A84: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80052A88: bne         $t4, $zero, L_80052A98
    if (ctx->r12 != 0) {
        // 0x80052A8C: andi        $t5, $t3, 0x8
        ctx->r13 = ctx->r11 & 0X8;
            goto L_80052A98;
    }
    // 0x80052A8C: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x80052A90: beq         $t5, $zero, L_80052AA0
    if (ctx->r13 == 0) {
        // 0x80052A94: nop
    
            goto L_80052AA0;
    }
    // 0x80052A94: nop

L_80052A98:
    // 0x80052A98: b           L_80052AA4
    // 0x80052A9C: addiu       $s1, $zero, -0x3C
    ctx->r17 = ADD32(0, -0X3C);
        goto L_80052AA4;
    // 0x80052A9C: addiu       $s1, $zero, -0x3C
    ctx->r17 = ADD32(0, -0X3C);
L_80052AA0:
    // 0x80052AA0: addiu       $s1, $zero, 0x3C
    ctx->r17 = ADD32(0, 0X3C);
L_80052AA4:
    // 0x80052AA4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052AA8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052AAC: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80052AB0: lw          $a1, 0x4C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4C);
    // 0x80052AB4: lw          $a2, 0x50($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X50);
    // 0x80052AB8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80052ABC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80052AC0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80052AC4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80052AC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80052ACC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80052AD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052AD4: jal         0x80077FF0
    // 0x80052AD8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_80077FF0(rdram, ctx);
        goto after_8;
    // 0x80052AD8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x80052ADC: beq         $v0, $zero, L_80052AEC
    if (ctx->r2 == 0) {
        // 0x80052AE0: nop
    
            goto L_80052AEC;
    }
    // 0x80052AE0: nop

    // 0x80052AE4: b           L_800532C4
    // 0x80052AE8: nop

        goto L_800532C4;
    // 0x80052AE8: nop

L_80052AEC:
    // 0x80052AEC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052AF0: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80052AF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80052AF8: bne         $t7, $at, L_80052B60
    if (ctx->r15 != ctx->r1) {
        // 0x80052AFC: nop
    
            goto L_80052B60;
    }
    // 0x80052AFC: nop

    // 0x80052B00: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052B04: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x80052B08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052B0C: beq         $t0, $at, L_80052B60
    if (ctx->r8 == ctx->r1) {
        // 0x80052B10: nop
    
            goto L_80052B60;
    }
    // 0x80052B10: nop

    // 0x80052B14: jal         0x80057960
    // 0x80052B18: nop

    func_80057960(rdram, ctx);
        goto after_9;
    // 0x80052B18: nop

    after_9:
    // 0x80052B1C: bne         $v0, $zero, L_80052B60
    if (ctx->r2 != 0) {
        // 0x80052B20: nop
    
            goto L_80052B60;
    }
    // 0x80052B20: nop

    // 0x80052B24: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052B28: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80052B2C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052B30: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80052B34: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80052B38: bne         $t4, $zero, L_80052B60
    if (ctx->r12 != 0) {
        // 0x80052B3C: andi        $t5, $t3, 0x1000
        ctx->r13 = ctx->r11 & 0X1000;
            goto L_80052B60;
    }
    // 0x80052B3C: andi        $t5, $t3, 0x1000
    ctx->r13 = ctx->r11 & 0X1000;
    // 0x80052B40: bne         $t5, $zero, L_80052B60
    if (ctx->r13 != 0) {
        // 0x80052B44: nop
    
            goto L_80052B60;
    }
    // 0x80052B44: nop

    // 0x80052B48: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80052B4C: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x80052B50: bne         $t8, $zero, L_80052B60
    if (ctx->r24 != 0) {
        // 0x80052B54: and         $t9, $t3, $at
        ctx->r25 = ctx->r11 & ctx->r1;
            goto L_80052B60;
    }
    // 0x80052B54: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80052B58: beq         $t9, $zero, L_80052A2C
    if (ctx->r25 == 0) {
        // 0x80052B5C: nop
    
            goto L_80052A2C;
    }
    // 0x80052B5C: nop

L_80052B60:
    // 0x80052B60: jal         0x80057960
    // 0x80052B64: nop

    func_80057960(rdram, ctx);
        goto after_10;
    // 0x80052B64: nop

    after_10:
    // 0x80052B68: beq         $v0, $zero, L_80052B84
    if (ctx->r2 == 0) {
        // 0x80052B6C: nop
    
            goto L_80052B84;
    }
    // 0x80052B6C: nop

    // 0x80052B70: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80052B74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052B78: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x80052B7C: b           L_80053554
    // 0x80052B80: nop

        goto L_80053554;
    // 0x80052B80: nop

L_80052B84:
    // 0x80052B84: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052B88: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80052B8C: nop

    // 0x80052B90: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80052B94: beq         $at, $zero, L_80052BB4
    if (ctx->r1 == 0) {
        // 0x80052B98: nop
    
            goto L_80052BB4;
    }
    // 0x80052B98: nop

    // 0x80052B9C: jal         0x8005A578
    // 0x80052BA0: nop

    func_8005A578(rdram, ctx);
        goto after_11;
    // 0x80052BA0: nop

    after_11:
    // 0x80052BA4: bne         $v0, $zero, L_80052BB4
    if (ctx->r2 != 0) {
        // 0x80052BA8: nop
    
            goto L_80052BB4;
    }
    // 0x80052BA8: nop

    // 0x80052BAC: b           L_80052A20
    // 0x80052BB0: nop

        goto L_80052A20;
    // 0x80052BB0: nop

L_80052BB4:
    // 0x80052BB4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052BB8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80052BBC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80052BC0: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80052BC4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80052BC8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80052BCC: bne         $t2, $zero, L_80052BDC
    if (ctx->r10 != 0) {
        // 0x80052BD0: and         $t3, $t5, $at
        ctx->r11 = ctx->r13 & ctx->r1;
            goto L_80052BDC;
    }
    // 0x80052BD0: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x80052BD4: beq         $t3, $zero, L_80052C20
    if (ctx->r11 == 0) {
        // 0x80052BD8: nop
    
            goto L_80052C20;
    }
    // 0x80052BD8: nop

L_80052BDC:
    // 0x80052BDC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052BE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052BE4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052BE8: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x80052BEC: nop

    // 0x80052BF0: sw          $t1, 0x94($t8)
    MEM_W(0X94, ctx->r24) = ctx->r9;
    // 0x80052BF4: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052BF8: jal         0x80054618
    // 0x80052BFC: nop

    func_80054618(rdram, ctx);
        goto after_12;
    // 0x80052BFC: nop

    after_12:
    // 0x80052C00: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052C04: jal         0x800543B0
    // 0x80052C08: nop

    func_800543B0(rdram, ctx);
        goto after_13;
    // 0x80052C08: nop

    after_13:
    // 0x80052C0C: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80052C10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052C14: sh          $t9, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r25;
    // 0x80052C18: b           L_80053554
    // 0x80052C1C: nop

        goto L_80053554;
    // 0x80052C1C: nop

L_80052C20:
    // 0x80052C20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052C24: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052C28: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052C2C: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80052C30: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80052C34: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80052C38: bne         $t4, $zero, L_80052C48
    if (ctx->r12 != 0) {
        // 0x80052C3C: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_80052C48;
    }
    // 0x80052C3C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80052C40: beq         $t5, $zero, L_80052DF4
    if (ctx->r13 == 0) {
        // 0x80052C44: nop
    
            goto L_80052DF4;
    }
    // 0x80052C44: nop

L_80052C48:
    // 0x80052C48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052C4C: lh          $t7, 0x12BA($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X12BA);
    // 0x80052C50: nop

    // 0x80052C54: andi        $t2, $t7, 0xC0
    ctx->r10 = ctx->r15 & 0XC0;
    // 0x80052C58: bne         $t2, $zero, L_80052C68
    if (ctx->r10 != 0) {
        // 0x80052C5C: nop
    
            goto L_80052C68;
    }
    // 0x80052C5C: nop

    // 0x80052C60: b           L_800532C4
    // 0x80052C64: nop

        goto L_800532C4;
    // 0x80052C64: nop

L_80052C68:
    // 0x80052C68: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052C6C: lbu         $t3, 0xD74($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0XD74);
    // 0x80052C70: nop

    // 0x80052C74: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x80052C78: bne         $at, $zero, L_80052C88
    if (ctx->r1 != 0) {
        // 0x80052C7C: nop
    
            goto L_80052C88;
    }
    // 0x80052C7C: nop

    // 0x80052C80: b           L_800532C4
    // 0x80052C84: nop

        goto L_800532C4;
    // 0x80052C84: nop

L_80052C88:
    // 0x80052C88: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052C8C: lbu         $t8, 0xD74($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0XD74);
    // 0x80052C90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052C94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80052C98: sb          $t9, 0xD74($at)
    MEM_B(0XD74, ctx->r1) = ctx->r25;
    // 0x80052C9C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052CA0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052CA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052CA8: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80052CAC: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80052CB0: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x80052CB4: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x80052CB8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80052CBC: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80052CC0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80052CC4: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80052CC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80052CCC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052CD0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80052CD4: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x80052CD8: nop

    // 0x80052CDC: sw          $t7, 0x94($t2)
    MEM_W(0X94, ctx->r10) = ctx->r15;
    // 0x80052CE0: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052CE4: jal         0x800507AC
    // 0x80052CE8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    func_800507AC(rdram, ctx);
        goto after_14;
    // 0x80052CE8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_14:
    // 0x80052CEC: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052CF0: jal         0x800507AC
    // 0x80052CF4: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800507AC(rdram, ctx);
        goto after_15;
    // 0x80052CF4: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_15:
    // 0x80052CF8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052CFC: jal         0x800543B0
    // 0x80052D00: nop

    func_800543B0(rdram, ctx);
        goto after_16;
    // 0x80052D00: nop

    after_16:
    // 0x80052D04: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052D08: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x80052D0C: jal         0x80052508
    // 0x80052D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_17;
    // 0x80052D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80052D14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052D18: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80052D1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052D20: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D24: nop
    
            goto L_80052D88;
    }
    // 0x80052D24: nop

    // 0x80052D28: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80052D2C: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D30: nop
    
            goto L_80052D88;
    }
    // 0x80052D30: nop

    // 0x80052D34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052D38: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D3C: nop
    
            goto L_80052D88;
    }
    // 0x80052D3C: nop

    // 0x80052D40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052D44: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D48: nop
    
            goto L_80052D88;
    }
    // 0x80052D48: nop

    // 0x80052D4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052D50: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D54: nop
    
            goto L_80052D88;
    }
    // 0x80052D54: nop

    // 0x80052D58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052D5C: beq         $t3, $at, L_80052D88
    if (ctx->r11 == ctx->r1) {
        // 0x80052D60: nop
    
            goto L_80052D88;
    }
    // 0x80052D60: nop

    // 0x80052D64: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052D68: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052D6C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80052D70: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80052D74: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80052D78: bne         $t4, $zero, L_80052D88
    if (ctx->r12 != 0) {
        // 0x80052D7C: andi        $t5, $t1, 0x1000
        ctx->r13 = ctx->r9 & 0X1000;
            goto L_80052D88;
    }
    // 0x80052D7C: andi        $t5, $t1, 0x1000
    ctx->r13 = ctx->r9 & 0X1000;
    // 0x80052D80: beq         $t5, $zero, L_80052DC8
    if (ctx->r13 == 0) {
        // 0x80052D84: nop
    
            goto L_80052DC8;
    }
    // 0x80052D84: nop

L_80052D88:
    // 0x80052D88: jal         0x80061F08
    // 0x80052D8C: nop

    func_80061F08(rdram, ctx);
        goto after_18;
    // 0x80052D8C: nop

    after_18:
    // 0x80052D90: bne         $v0, $zero, L_80052DC8
    if (ctx->r2 != 0) {
        // 0x80052D94: nop
    
            goto L_80052DC8;
    }
    // 0x80052D94: nop

    // 0x80052D98: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80052D9C: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x80052DA0: nop

    // 0x80052DA4: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80052DA8: beq         $at, $zero, L_80052DC0
    if (ctx->r1 == 0) {
        // 0x80052DAC: nop
    
            goto L_80052DC0;
    }
    // 0x80052DAC: nop

    // 0x80052DB0: jal         0x8005A578
    // 0x80052DB4: nop

    func_8005A578(rdram, ctx);
        goto after_19;
    // 0x80052DB4: nop

    after_19:
    // 0x80052DB8: beq         $v0, $zero, L_80052DC8
    if (ctx->r2 == 0) {
        // 0x80052DBC: nop
    
            goto L_80052DC8;
    }
    // 0x80052DBC: nop

L_80052DC0:
    // 0x80052DC0: b           L_80053554
    // 0x80052DC4: nop

        goto L_80053554;
    // 0x80052DC4: nop

L_80052DC8:
    // 0x80052DC8: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x80052DCC: nop

    // 0x80052DD0: bne         $t6, $zero, L_80052DE4
    if (ctx->r14 != 0) {
        // 0x80052DD4: nop
    
            goto L_80052DE4;
    }
    // 0x80052DD4: nop

    // 0x80052DD8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052DDC: jal         0x80054198
    // 0x80052DE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80054198(rdram, ctx);
        goto after_20;
    // 0x80052DE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_20:
L_80052DE4:
    // 0x80052DE4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80052DE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052DEC: b           L_80053540
    // 0x80052DF0: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
        goto L_80053540;
    // 0x80052DF0: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
L_80052DF4:
    // 0x80052DF4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052DF8: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x80052DFC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052E00: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E04: nop
    
            goto L_80052E68;
    }
    // 0x80052E04: nop

    // 0x80052E08: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80052E0C: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E10: nop
    
            goto L_80052E68;
    }
    // 0x80052E10: nop

    // 0x80052E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052E18: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E1C: nop
    
            goto L_80052E68;
    }
    // 0x80052E1C: nop

    // 0x80052E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052E24: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E28: nop
    
            goto L_80052E68;
    }
    // 0x80052E28: nop

    // 0x80052E2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052E30: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E34: nop
    
            goto L_80052E68;
    }
    // 0x80052E34: nop

    // 0x80052E38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052E3C: beq         $t2, $at, L_80052E68
    if (ctx->r10 == ctx->r1) {
        // 0x80052E40: nop
    
            goto L_80052E68;
    }
    // 0x80052E40: nop

    // 0x80052E44: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052E48: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80052E4C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80052E50: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80052E54: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80052E58: bne         $t0, $zero, L_80052E68
    if (ctx->r8 != 0) {
        // 0x80052E5C: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_80052E68;
    }
    // 0x80052E5C: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x80052E60: beq         $t1, $zero, L_80052EB0
    if (ctx->r9 == 0) {
        // 0x80052E64: nop
    
            goto L_80052EB0;
    }
    // 0x80052E64: nop

L_80052E68:
    // 0x80052E68: jal         0x80061F08
    // 0x80052E6C: nop

    func_80061F08(rdram, ctx);
        goto after_21;
    // 0x80052E6C: nop

    after_21:
    // 0x80052E70: bne         $v0, $zero, L_80052EB0
    if (ctx->r2 != 0) {
        // 0x80052E74: nop
    
            goto L_80052EB0;
    }
    // 0x80052E74: nop

    // 0x80052E78: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80052E7C: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x80052E80: nop

    // 0x80052E84: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x80052E88: beq         $at, $zero, L_80052EA0
    if (ctx->r1 == 0) {
        // 0x80052E8C: nop
    
            goto L_80052EA0;
    }
    // 0x80052E8C: nop

    // 0x80052E90: jal         0x8005A578
    // 0x80052E94: nop

    func_8005A578(rdram, ctx);
        goto after_22;
    // 0x80052E94: nop

    after_22:
    // 0x80052E98: beq         $v0, $zero, L_80052EA8
    if (ctx->r2 == 0) {
        // 0x80052E9C: nop
    
            goto L_80052EA8;
    }
    // 0x80052E9C: nop

L_80052EA0:
    // 0x80052EA0: b           L_800532D0
    // 0x80052EA4: nop

        goto L_800532D0;
    // 0x80052EA4: nop

L_80052EA8:
    // 0x80052EA8: b           L_80053540
    // 0x80052EAC: nop

        goto L_80053540;
    // 0x80052EAC: nop

L_80052EB0:
    // 0x80052EB0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052EB4: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x80052EB8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80052EBC: bne         $t5, $at, L_8005329C
    if (ctx->r13 != ctx->r1) {
        // 0x80052EC0: nop
    
            goto L_8005329C;
    }
    // 0x80052EC0: nop

    // 0x80052EC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052EC8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052ECC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80052ED0: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80052ED4: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80052ED8: bne         $t8, $zero, L_80052EE8
    if (ctx->r24 != 0) {
        // 0x80052EDC: andi        $t9, $t3, 0x80
        ctx->r25 = ctx->r11 & 0X80;
            goto L_80052EE8;
    }
    // 0x80052EDC: andi        $t9, $t3, 0x80
    ctx->r25 = ctx->r11 & 0X80;
    // 0x80052EE0: beq         $t9, $zero, L_80052EF8
    if (ctx->r25 == 0) {
        // 0x80052EE4: nop
    
            goto L_80052EF8;
    }
    // 0x80052EE4: nop

L_80052EE8:
    // 0x80052EE8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80052EEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052EF0: b           L_80053294
    // 0x80052EF4: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
        goto L_80053294;
    // 0x80052EF4: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
L_80052EF8:
    // 0x80052EF8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80052EFC: lw          $a1, 0xE60($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE60);
    // 0x80052F00: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052F04: jal         0x80054198
    // 0x80052F08: nop

    func_80054198(rdram, ctx);
        goto after_23;
    // 0x80052F08: nop

    after_23:
    // 0x80052F0C: beq         $v0, $zero, L_800530F8
    if (ctx->r2 == 0) {
        // 0x80052F10: nop
    
            goto L_800530F8;
    }
    // 0x80052F10: nop

    // 0x80052F14: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052F18: lh          $t0, 0x10F0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X10F0);
    // 0x80052F1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052F20: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F24: nop
    
            goto L_80052F88;
    }
    // 0x80052F24: nop

    // 0x80052F28: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80052F2C: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F30: nop
    
            goto L_80052F88;
    }
    // 0x80052F30: nop

    // 0x80052F34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052F38: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F3C: nop
    
            goto L_80052F88;
    }
    // 0x80052F3C: nop

    // 0x80052F40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052F44: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F48: nop
    
            goto L_80052F88;
    }
    // 0x80052F48: nop

    // 0x80052F4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052F50: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F54: nop
    
            goto L_80052F88;
    }
    // 0x80052F54: nop

    // 0x80052F58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052F5C: beq         $t0, $at, L_80052F88
    if (ctx->r8 == ctx->r1) {
        // 0x80052F60: nop
    
            goto L_80052F88;
    }
    // 0x80052F60: nop

    // 0x80052F64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052F68: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80052F6C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80052F70: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x80052F74: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80052F78: bne         $t6, $zero, L_80052F88
    if (ctx->r14 != 0) {
        // 0x80052F7C: andi        $t7, $t5, 0x1000
        ctx->r15 = ctx->r13 & 0X1000;
            goto L_80052F88;
    }
    // 0x80052F7C: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x80052F80: beq         $t7, $zero, L_80052FC8
    if (ctx->r15 == 0) {
        // 0x80052F84: nop
    
            goto L_80052FC8;
    }
    // 0x80052F84: nop

L_80052F88:
    // 0x80052F88: jal         0x80061F08
    // 0x80052F8C: nop

    func_80061F08(rdram, ctx);
        goto after_24;
    // 0x80052F8C: nop

    after_24:
    // 0x80052F90: bne         $v0, $zero, L_80052FC8
    if (ctx->r2 != 0) {
        // 0x80052F94: nop
    
            goto L_80052FC8;
    }
    // 0x80052F94: nop

    // 0x80052F98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052F9C: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x80052FA0: nop

    // 0x80052FA4: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x80052FA8: beq         $at, $zero, L_80052FC0
    if (ctx->r1 == 0) {
        // 0x80052FAC: nop
    
            goto L_80052FC0;
    }
    // 0x80052FAC: nop

    // 0x80052FB0: jal         0x8005A578
    // 0x80052FB4: nop

    func_8005A578(rdram, ctx);
        goto after_25;
    // 0x80052FB4: nop

    after_25:
    // 0x80052FB8: beq         $v0, $zero, L_80052FC8
    if (ctx->r2 == 0) {
        // 0x80052FBC: nop
    
            goto L_80052FC8;
    }
    // 0x80052FBC: nop

L_80052FC0:
    // 0x80052FC0: b           L_80053554
    // 0x80052FC4: nop

        goto L_80053554;
    // 0x80052FC4: nop

L_80052FC8:
    // 0x80052FC8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052FCC: jal         0x80054264
    // 0x80052FD0: nop

    func_80054264(rdram, ctx);
        goto after_26;
    // 0x80052FD0: nop

    after_26:
    // 0x80052FD4: beq         $v0, $zero, L_800530B4
    if (ctx->r2 == 0) {
        // 0x80052FD8: nop
    
            goto L_800530B4;
    }
    // 0x80052FD8: nop

    // 0x80052FDC: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80052FE0: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x80052FE4: jal         0x80052508
    // 0x80052FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_27;
    // 0x80052FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80052FEC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052FF0: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80052FF4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052FF8: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80052FFC: nop
    
            goto L_80053060;
    }
    // 0x80052FFC: nop

    // 0x80053000: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053004: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053008: nop
    
            goto L_80053060;
    }
    // 0x80053008: nop

    // 0x8005300C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053010: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053014: nop
    
            goto L_80053060;
    }
    // 0x80053014: nop

    // 0x80053018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005301C: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053020: nop
    
            goto L_80053060;
    }
    // 0x80053020: nop

    // 0x80053024: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053028: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x8005302C: nop
    
            goto L_80053060;
    }
    // 0x8005302C: nop

    // 0x80053030: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053034: beq         $t3, $at, L_80053060
    if (ctx->r11 == ctx->r1) {
        // 0x80053038: nop
    
            goto L_80053060;
    }
    // 0x80053038: nop

    // 0x8005303C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053040: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80053044: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80053048: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005304C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80053050: bne         $t4, $zero, L_80053060
    if (ctx->r12 != 0) {
        // 0x80053054: andi        $t5, $t1, 0x1000
        ctx->r13 = ctx->r9 & 0X1000;
            goto L_80053060;
    }
    // 0x80053054: andi        $t5, $t1, 0x1000
    ctx->r13 = ctx->r9 & 0X1000;
    // 0x80053058: beq         $t5, $zero, L_800530A0
    if (ctx->r13 == 0) {
        // 0x8005305C: nop
    
            goto L_800530A0;
    }
    // 0x8005305C: nop

L_80053060:
    // 0x80053060: jal         0x80061F08
    // 0x80053064: nop

    func_80061F08(rdram, ctx);
        goto after_28;
    // 0x80053064: nop

    after_28:
    // 0x80053068: bne         $v0, $zero, L_800530A0
    if (ctx->r2 != 0) {
        // 0x8005306C: nop
    
            goto L_800530A0;
    }
    // 0x8005306C: nop

    // 0x80053070: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80053074: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x80053078: nop

    // 0x8005307C: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80053080: beq         $at, $zero, L_80053098
    if (ctx->r1 == 0) {
        // 0x80053084: nop
    
            goto L_80053098;
    }
    // 0x80053084: nop

    // 0x80053088: jal         0x8005A578
    // 0x8005308C: nop

    func_8005A578(rdram, ctx);
        goto after_29;
    // 0x8005308C: nop

    after_29:
    // 0x80053090: beq         $v0, $zero, L_800530A0
    if (ctx->r2 == 0) {
        // 0x80053094: nop
    
            goto L_800530A0;
    }
    // 0x80053094: nop

L_80053098:
    // 0x80053098: b           L_80053554
    // 0x8005309C: nop

        goto L_80053554;
    // 0x8005309C: nop

L_800530A0:
    // 0x800530A0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800530A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800530A8: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x800530AC: b           L_80053554
    // 0x800530B0: nop

        goto L_80053554;
    // 0x800530B0: nop

L_800530B4:
    // 0x800530B4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x800530B8: jal         0x80056E88
    // 0x800530BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_30;
    // 0x800530BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x800530C0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800530C4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x800530C8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800530CC: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800530D0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800530D4: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x800530D8: lh          $a1, 0x42($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X42);
    // 0x800530DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800530E0: jal         0x8004EF90
    // 0x800530E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_31;
    // 0x800530E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_31:
    // 0x800530E8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800530EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800530F0: b           L_80053294
    // 0x800530F4: sh          $t3, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r11;
        goto L_80053294;
    // 0x800530F4: sh          $t3, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r11;
L_800530F8:
    // 0x800530F8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x800530FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053100: jal         0x80052508
    // 0x80053104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_32;
    // 0x80053104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x80053108: bne         $v0, $zero, L_80053294
    if (ctx->r2 != 0) {
        // 0x8005310C: nop
    
            goto L_80053294;
    }
    // 0x8005310C: nop

    // 0x80053110: jal         0x80061E14
    // 0x80053114: nop

    func_80061E14(rdram, ctx);
        goto after_33;
    // 0x80053114: nop

    after_33:
    // 0x80053118: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // 0x8005311C: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x80053120: nop

    // 0x80053124: beq         $t8, $zero, L_80053144
    if (ctx->r24 == 0) {
        // 0x80053128: nop
    
            goto L_80053144;
    }
    // 0x80053128: nop

    // 0x8005312C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80053130: beq         $t8, $at, L_80053144
    if (ctx->r24 == ctx->r1) {
        // 0x80053134: nop
    
            goto L_80053144;
    }
    // 0x80053134: nop

    // 0x80053138: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8005313C: bne         $t8, $at, L_80053294
    if (ctx->r24 != ctx->r1) {
        // 0x80053140: nop
    
            goto L_80053294;
    }
    // 0x80053140: nop

L_80053144:
    // 0x80053144: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80053148: jal         0x80054264
    // 0x8005314C: nop

    func_80054264(rdram, ctx);
        goto after_34;
    // 0x8005314C: nop

    after_34:
    // 0x80053150: beq         $v0, $zero, L_80053230
    if (ctx->r2 == 0) {
        // 0x80053154: nop
    
            goto L_80053230;
    }
    // 0x80053154: nop

    // 0x80053158: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x8005315C: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x80053160: jal         0x80052508
    // 0x80053164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_35;
    // 0x80053164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x80053168: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005316C: lh          $t0, 0x10F0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X10F0);
    // 0x80053170: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053174: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x80053178: nop
    
            goto L_800531DC;
    }
    // 0x80053178: nop

    // 0x8005317C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80053180: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x80053184: nop
    
            goto L_800531DC;
    }
    // 0x80053184: nop

    // 0x80053188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005318C: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x80053190: nop
    
            goto L_800531DC;
    }
    // 0x80053190: nop

    // 0x80053194: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053198: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x8005319C: nop
    
            goto L_800531DC;
    }
    // 0x8005319C: nop

    // 0x800531A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800531A4: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x800531A8: nop
    
            goto L_800531DC;
    }
    // 0x800531A8: nop

    // 0x800531AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800531B0: beq         $t0, $at, L_800531DC
    if (ctx->r8 == ctx->r1) {
        // 0x800531B4: nop
    
            goto L_800531DC;
    }
    // 0x800531B4: nop

    // 0x800531B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800531BC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x800531C0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800531C4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x800531C8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800531CC: bne         $t6, $zero, L_800531DC
    if (ctx->r14 != 0) {
        // 0x800531D0: andi        $t7, $t5, 0x1000
        ctx->r15 = ctx->r13 & 0X1000;
            goto L_800531DC;
    }
    // 0x800531D0: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800531D4: beq         $t7, $zero, L_8005321C
    if (ctx->r15 == 0) {
        // 0x800531D8: nop
    
            goto L_8005321C;
    }
    // 0x800531D8: nop

L_800531DC:
    // 0x800531DC: jal         0x80061F08
    // 0x800531E0: nop

    func_80061F08(rdram, ctx);
        goto after_36;
    // 0x800531E0: nop

    after_36:
    // 0x800531E4: bne         $v0, $zero, L_8005321C
    if (ctx->r2 != 0) {
        // 0x800531E8: nop
    
            goto L_8005321C;
    }
    // 0x800531E8: nop

    // 0x800531EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800531F0: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x800531F4: nop

    // 0x800531F8: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x800531FC: beq         $at, $zero, L_80053214
    if (ctx->r1 == 0) {
        // 0x80053200: nop
    
            goto L_80053214;
    }
    // 0x80053200: nop

    // 0x80053204: jal         0x8005A578
    // 0x80053208: nop

    func_8005A578(rdram, ctx);
        goto after_37;
    // 0x80053208: nop

    after_37:
    // 0x8005320C: beq         $v0, $zero, L_8005321C
    if (ctx->r2 == 0) {
        // 0x80053210: nop
    
            goto L_8005321C;
    }
    // 0x80053210: nop

L_80053214:
    // 0x80053214: b           L_80053554
    // 0x80053218: nop

        goto L_80053554;
    // 0x80053218: nop

L_8005321C:
    // 0x8005321C: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80053220: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053224: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80053228: b           L_80053554
    // 0x8005322C: nop

        goto L_80053554;
    // 0x8005322C: nop

L_80053230:
    // 0x80053230: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80053234: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80053238: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x8005323C: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80053240: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    // 0x80053244: jal         0x8004EF90
    // 0x80053248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_38;
    // 0x80053248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_38:
    // 0x8005324C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80053250: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80053254: nop

    // 0x80053258: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005325C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80053260: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80053264: ori         $t5, $t1, 0x80
    ctx->r13 = ctx->r9 | 0X80;
    // 0x80053268: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8005326C: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80053270: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80053274: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053278: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x8005327C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80053280: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80053284: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80053288: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x8005328C: nop

    // 0x80053290: sw          $t7, 0x90($t9)
    MEM_W(0X90, ctx->r25) = ctx->r15;
L_80053294:
    // 0x80053294: b           L_80053540
    // 0x80053298: nop

        goto L_80053540;
    // 0x80053298: nop

L_8005329C:
    // 0x8005329C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800532A0: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x800532A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800532A8: beq         $t2, $at, L_800532C4
    if (ctx->r10 == ctx->r1) {
        // 0x800532AC: nop
    
            goto L_800532C4;
    }
    // 0x800532AC: nop

    // 0x800532B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800532B4: lh          $t3, 0x6C0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X6C0);
    // 0x800532B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800532BC: bne         $t3, $at, L_80053540
    if (ctx->r11 != ctx->r1) {
        // 0x800532C0: nop
    
            goto L_80053540;
    }
    // 0x800532C0: nop

L_800532C4:
    // 0x800532C4: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800532C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800532CC: sh          $t0, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r8;
L_800532D0:
    // 0x800532D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800532D4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x800532D8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800532DC: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x800532E0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800532E4: bne         $t8, $zero, L_800532F4
    if (ctx->r24 != 0) {
        // 0x800532E8: andi        $t9, $t5, 0x80
        ctx->r25 = ctx->r13 & 0X80;
            goto L_800532F4;
    }
    // 0x800532E8: andi        $t9, $t5, 0x80
    ctx->r25 = ctx->r13 & 0X80;
    // 0x800532EC: beq         $t9, $zero, L_800533E4
    if (ctx->r25 == 0) {
        // 0x800532F0: nop
    
            goto L_800533E4;
    }
    // 0x800532F0: nop

L_800532F4:
    // 0x800532F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800532F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800532FC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80053300: lw          $t6, 0x258C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X258C);
    // 0x80053304: nop

    // 0x80053308: sw          $t6, 0x94($t7)
    MEM_W(0X94, ctx->r15) = ctx->r14;
    // 0x8005330C: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    // 0x80053310: jal         0x80056E88
    // 0x80053314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_39;
    // 0x80053314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80053318: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005331C: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80053320: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80053324: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80053328: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8005332C: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x80053330: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80053334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80053338: jal         0x8004EF90
    // 0x8005333C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_40;
    // 0x8005333C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_40:
    // 0x80053340: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80053344: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80053348: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8005334C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80053350: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x80053354: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80053358: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005335C: bne         $t8, $zero, L_800533A4
    if (ctx->r24 != 0) {
        // 0x80053360: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_800533A4;
    }
    // 0x80053360: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80053364: bne         $t9, $zero, L_800533A4
    if (ctx->r25 != 0) {
        // 0x80053368: nop
    
            goto L_800533A4;
    }
    // 0x80053368: nop

L_8005336C:
    // 0x8005336C: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80053370: jal         0x800499B0
    // 0x80053374: nop

    func_800499B0(rdram, ctx);
        goto after_41;
    // 0x80053374: nop

    after_41:
    // 0x80053378: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005337C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80053380: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80053384: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80053388: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8005338C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80053390: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80053394: bne         $t2, $zero, L_800533A4
    if (ctx->r10 != 0) {
        // 0x80053398: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_800533A4;
    }
    // 0x80053398: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8005339C: beq         $t3, $zero, L_8005336C
    if (ctx->r11 == 0) {
        // 0x800533A0: nop
    
            goto L_8005336C;
    }
    // 0x800533A0: nop

L_800533A4:
    // 0x800533A4: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x800533A8: jal         0x800543B0
    // 0x800533AC: nop

    func_800543B0(rdram, ctx);
        goto after_42;
    // 0x800533AC: nop

    after_42:
    // 0x800533B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800533B4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800533B8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800533BC: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x800533C0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800533C4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800533C8: bne         $t8, $zero, L_800533D8
    if (ctx->r24 != 0) {
        // 0x800533CC: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_800533D8;
    }
    // 0x800533CC: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x800533D0: beq         $t9, $zero, L_800533E4
    if (ctx->r25 == 0) {
        // 0x800533D4: nop
    
            goto L_800533E4;
    }
    // 0x800533D4: nop

L_800533D8:
    // 0x800533D8: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x800533DC: jal         0x80054618
    // 0x800533E0: nop

    func_80054618(rdram, ctx);
        goto after_43;
    // 0x800533E0: nop

    after_43:
L_800533E4:
    // 0x800533E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800533E8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x800533EC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800533F0: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x800533F4: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800533F8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800533FC: bne         $t2, $zero, L_8005340C
    if (ctx->r10 != 0) {
        // 0x80053400: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8005340C;
    }
    // 0x80053400: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x80053404: beq         $t3, $zero, L_8005348C
    if (ctx->r11 == 0) {
        // 0x80053408: nop
    
            goto L_8005348C;
    }
    // 0x80053408: nop

L_8005340C:
    // 0x8005340C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80053410: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80053414: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80053418: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005341C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80053420: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80053424: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x80053428: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005342C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80053430: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80053434: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80053438: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005343C: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80053440: nop

    // 0x80053444: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80053448: nop

    // 0x8005344C: slti        $at, $t6, 0x3D
    ctx->r1 = SIGNED(ctx->r14) < 0X3D ? 1 : 0;
    // 0x80053450: bne         $at, $zero, L_80053478
    if (ctx->r1 != 0) {
        // 0x80053454: nop
    
            goto L_80053478;
    }
    // 0x80053454: nop

    // 0x80053458: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x8005345C: nop

    // 0x80053460: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x80053464: bne         $at, $zero, L_80053478
    if (ctx->r1 != 0) {
        // 0x80053468: nop
    
            goto L_80053478;
    }
    // 0x80053468: nop

    // 0x8005346C: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x80053470: jal         0x80054198
    // 0x80053474: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80054198(rdram, ctx);
        goto after_44;
    // 0x80053474: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_44:
L_80053478:
    // 0x80053478: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8005347C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053480: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80053484: b           L_80053554
    // 0x80053488: nop

        goto L_80053554;
    // 0x80053488: nop

L_8005348C:
    // 0x8005348C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80053490: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x80053494: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053498: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x8005349C: nop
    
            goto L_80053500;
    }
    // 0x8005349C: nop

    // 0x800534A0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800534A4: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534A8: nop
    
            goto L_80053500;
    }
    // 0x800534A8: nop

    // 0x800534AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800534B0: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534B4: nop
    
            goto L_80053500;
    }
    // 0x800534B4: nop

    // 0x800534B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800534BC: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534C0: nop
    
            goto L_80053500;
    }
    // 0x800534C0: nop

    // 0x800534C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800534C8: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534CC: nop
    
            goto L_80053500;
    }
    // 0x800534CC: nop

    // 0x800534D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800534D4: beq         $t3, $at, L_80053500
    if (ctx->r11 == ctx->r1) {
        // 0x800534D8: nop
    
            goto L_80053500;
    }
    // 0x800534D8: nop

    // 0x800534DC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800534E0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800534E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800534E8: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x800534EC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800534F0: bne         $t0, $zero, L_80053500
    if (ctx->r8 != 0) {
        // 0x800534F4: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_80053500;
    }
    // 0x800534F4: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x800534F8: beq         $t1, $zero, L_80053540
    if (ctx->r9 == 0) {
        // 0x800534FC: nop
    
            goto L_80053540;
    }
    // 0x800534FC: nop

L_80053500:
    // 0x80053500: jal         0x80061F08
    // 0x80053504: nop

    func_80061F08(rdram, ctx);
        goto after_45;
    // 0x80053504: nop

    after_45:
    // 0x80053508: bne         $v0, $zero, L_80053540
    if (ctx->r2 != 0) {
        // 0x8005350C: nop
    
            goto L_80053540;
    }
    // 0x8005350C: nop

    // 0x80053510: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80053514: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x80053518: nop

    // 0x8005351C: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x80053520: beq         $at, $zero, L_80053538
    if (ctx->r1 == 0) {
        // 0x80053524: nop
    
            goto L_80053538;
    }
    // 0x80053524: nop

    // 0x80053528: jal         0x8005A578
    // 0x8005352C: nop

    func_8005A578(rdram, ctx);
        goto after_46;
    // 0x8005352C: nop

    after_46:
    // 0x80053530: beq         $v0, $zero, L_80053540
    if (ctx->r2 == 0) {
        // 0x80053534: nop
    
            goto L_80053540;
    }
    // 0x80053534: nop

L_80053538:
    // 0x80053538: b           L_80053554
    // 0x8005353C: nop

        goto L_80053554;
    // 0x8005353C: nop

L_80053540:
    // 0x80053540: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80053544: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x80053548: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005354C: bne         $t6, $at, L_80052A20
    if (ctx->r14 != ctx->r1) {
        // 0x80053550: nop
    
            goto L_80052A20;
    }
    // 0x80053550: nop

L_80053554:
    // 0x80053554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80053558: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
    // 0x8005355C: b           L_80053564
    // 0x80053560: nop

        goto L_80053564;
    // 0x80053560: nop

L_80053564:
    // 0x80053564: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80053568: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005356C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80053570: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80053574: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80053578: jr          $ra
    // 0x8005357C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8005357C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_8004F8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004F8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F8D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004F8D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F8DC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F8E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004F8E4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004F8E8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004F8EC: bne         $t0, $zero, L_8004F8FC
    if (ctx->r8 != 0) {
        // 0x8004F8F0: andi        $t1, $t9, 0x8000
        ctx->r9 = ctx->r25 & 0X8000;
            goto L_8004F8FC;
    }
    // 0x8004F8F0: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x8004F8F4: beq         $t1, $zero, L_8004FA40
    if (ctx->r9 == 0) {
        // 0x8004F8F8: nop
    
            goto L_8004FA40;
    }
    // 0x8004F8F8: nop

L_8004F8FC:
    // 0x8004F8FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F900: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F904: nop

    // 0x8004F908: lw          $t2, 0x5C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X5C);
    // 0x8004F90C: nop

    // 0x8004F910: beq         $t2, $zero, L_8004F960
    if (ctx->r10 == 0) {
        // 0x8004F914: nop
    
            goto L_8004F960;
    }
    // 0x8004F914: nop

    // 0x8004F918: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x8004F91C: nop

    // 0x8004F920: beq         $t3, $zero, L_8004F960
    if (ctx->r11 == 0) {
        // 0x8004F924: nop
    
            goto L_8004F960;
    }
    // 0x8004F924: nop

    // 0x8004F928: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F92C: beq         $t3, $at, L_8004F960
    if (ctx->r11 == ctx->r1) {
        // 0x8004F930: nop
    
            goto L_8004F960;
    }
    // 0x8004F930: nop

    // 0x8004F934: lhu         $t4, 0x60($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X60);
    // 0x8004F938: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x8004F93C: beq         $t4, $at, L_8004F960
    if (ctx->r12 == ctx->r1) {
        // 0x8004F940: nop
    
            goto L_8004F960;
    }
    // 0x8004F940: nop

    // 0x8004F944: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F948: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F94C: ori         $a2, $zero, 0x8037
    ctx->r6 = 0 | 0X8037;
    // 0x8004F950: lw          $a0, 0x5C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X5C);
    // 0x8004F954: lhu         $a1, 0x60($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X60);
    // 0x8004F958: jal         0x80029538
    // 0x8004F95C: nop

    func_80029538(rdram, ctx);
        goto after_0;
    // 0x8004F95C: nop

    after_0:
L_8004F960:
    // 0x8004F960: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F964: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F968: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004F96C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004F970: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004F974: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004F978: bne         $t0, $zero, L_8004F988
    if (ctx->r8 != 0) {
        // 0x8004F97C: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8004F988;
    }
    // 0x8004F97C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8004F980: beq         $t1, $zero, L_8004F9B8
    if (ctx->r9 == 0) {
        // 0x8004F984: nop
    
            goto L_8004F9B8;
    }
    // 0x8004F984: nop

L_8004F988:
    // 0x8004F988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F98C: jal         0x800507AC
    // 0x8004F990: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    func_800507AC(rdram, ctx);
        goto after_1;
    // 0x8004F990: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    after_1:
    // 0x8004F994: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F998: jal         0x800507AC
    // 0x8004F99C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x8004F99C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    after_2:
    // 0x8004F9A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F9A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004F9A8: jal         0x80052508
    // 0x8004F9AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_3;
    // 0x8004F9AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8004F9B0: b           L_8004FA14
    // 0x8004F9B4: nop

        goto L_8004FA14;
    // 0x8004F9B4: nop

L_8004F9B8:
    // 0x8004F9B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F9BC: jal         0x800507AC
    // 0x8004F9C0: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    func_800507AC(rdram, ctx);
        goto after_4;
    // 0x8004F9C0: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_4:
    // 0x8004F9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F9C8: jal         0x800507AC
    // 0x8004F9CC: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800507AC(rdram, ctx);
        goto after_5;
    // 0x8004F9CC: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_5:
    // 0x8004F9D0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004F9D4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004F9D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004F9DC: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8004F9E0: nop

    // 0x8004F9E4: addiu       $t7, $t3, -0xA
    ctx->r15 = ADD32(ctx->r11, -0XA);
    // 0x8004F9E8: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
    // 0x8004F9EC: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004F9F0: nop

    // 0x8004F9F4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8004F9F8: nop

    // 0x8004F9FC: bgez        $t5, L_8004FA14
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8004FA00: nop
    
            goto L_8004FA14;
    }
    // 0x8004FA00: nop

    // 0x8004FA04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004FA08: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8004FA0C: nop

    // 0x8004FA10: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
L_8004FA14:
    // 0x8004FA14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004FA18: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004FA1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004FA20: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004FA24: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004FA28: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8004FA2C: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x8004FA30: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004FA34: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004FA38: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8004FA3C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
L_8004FA40:
    // 0x8004FA40: b           L_8004FA48
    // 0x8004FA44: nop

        goto L_8004FA48;
    // 0x8004FA44: nop

L_8004FA48:
    // 0x8004FA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004FA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004FA50: jr          $ra
    // 0x8004FA54: nop

    return;
    // 0x8004FA54: nop

;}
RECOMP_FUNC void func_8006343C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006343C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063444: jal         0x8005F064
    // 0x80063448: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063448: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x8006344C: b           L_8006345C
    // 0x80063450: nop

        goto L_8006345C;
    // 0x80063450: nop

    // 0x80063454: b           L_8006345C
    // 0x80063458: nop

        goto L_8006345C;
    // 0x80063458: nop

L_8006345C:
    // 0x8006345C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063464: jr          $ra
    // 0x80063468: nop

    return;
    // 0x80063468: nop

;}
RECOMP_FUNC void func_8000D74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D74C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000D750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D754: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000D758: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000D75C:
    // 0x8000D75C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D760: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D764: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D768: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000D76C: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x8000D770: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8000D774: nop

    // 0x8000D778: bne         $t8, $t9, L_8000D8D4
    if (ctx->r24 != ctx->r25) {
        // 0x8000D77C: nop
    
            goto L_8000D8D4;
    }
    // 0x8000D77C: nop

    // 0x8000D780: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D784: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D788: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000D78C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000D790: sw          $zero, -0x7E8($at)
    MEM_W(-0X7E8, ctx->r1) = 0;
    // 0x8000D794: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8000D798: nop

    // 0x8000D79C: sw          $zero, 0x1A0($t2)
    MEM_W(0X1A0, ctx->r10) = 0;
    // 0x8000D7A0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7A4: nop

    // 0x8000D7A8: sw          $zero, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = 0;
    // 0x8000D7AC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7B0: nop

    // 0x8000D7B4: lw          $t5, 0x20C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20C);
    // 0x8000D7B8: nop

    // 0x8000D7BC: beq         $t5, $zero, L_8000D894
    if (ctx->r13 == 0) {
        // 0x8000D7C0: nop
    
            goto L_8000D894;
    }
    // 0x8000D7C0: nop

    // 0x8000D7C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7C8: nop

    // 0x8000D7CC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000D7D0: nop

    // 0x8000D7D4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8000D7D8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7DC: nop

    // 0x8000D7E0: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x8000D7E4: nop

    // 0x8000D7E8: slti        $at, $t9, 0x4000
    ctx->r1 = SIGNED(ctx->r25) < 0X4000 ? 1 : 0;
    // 0x8000D7EC: bne         $at, $zero, L_8000D804
    if (ctx->r1 != 0) {
        // 0x8000D7F0: nop
    
            goto L_8000D804;
    }
    // 0x8000D7F0: nop

    // 0x8000D7F4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x8000D7F8: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000D7FC: bne         $at, $zero, L_8000D83C
    if (ctx->r1 != 0) {
        // 0x8000D800: nop
    
            goto L_8000D83C;
    }
    // 0x8000D800: nop

L_8000D804:
    // 0x8000D804: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000D808: nop

    // 0x8000D80C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000D810: nop

    // 0x8000D814: beq         $t1, $zero, L_8000D83C
    if (ctx->r9 == 0) {
        // 0x8000D818: nop
    
            goto L_8000D83C;
    }
    // 0x8000D818: nop

    // 0x8000D81C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8000D820: nop

    // 0x8000D824: lw          $a0, 0xC($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XC);
    // 0x8000D828: jal         0x8000D390
    // 0x8000D82C: nop

    TempHeap_Free(rdram, ctx);
        goto after_0;
    // 0x8000D82C: nop

    after_0:
    // 0x8000D830: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8000D834: nop

    // 0x8000D838: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
L_8000D83C:
    // 0x8000D83C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8000D840: nop

    // 0x8000D844: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8000D848: nop

    // 0x8000D84C: beq         $t5, $zero, L_8000D874
    if (ctx->r13 == 0) {
        // 0x8000D850: nop
    
            goto L_8000D874;
    }
    // 0x8000D850: nop

    // 0x8000D854: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8000D858: nop

    // 0x8000D85C: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x8000D860: jal         0x8000D390
    // 0x8000D864: nop

    TempHeap_Free(rdram, ctx);
        goto after_1;
    // 0x8000D864: nop

    after_1:
    // 0x8000D868: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000D86C: nop

    // 0x8000D870: sw          $zero, 0x10($t7)
    MEM_W(0X10, ctx->r15) = 0;
L_8000D874:
    // 0x8000D874: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000D878: nop

    // 0x8000D87C: lw          $a0, 0x20C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X20C);
    // 0x8000D880: jal         0x8000D390
    // 0x8000D884: nop

    TempHeap_Free(rdram, ctx);
        goto after_2;
    // 0x8000D884: nop

    after_2:
    // 0x8000D888: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8000D88C: nop

    // 0x8000D890: sw          $zero, 0x20C($t9)
    MEM_W(0X20C, ctx->r25) = 0;
L_8000D894:
    // 0x8000D894: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8000D898: nop

    // 0x8000D89C: lw          $t1, 0x210($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X210);
    // 0x8000D8A0: nop

    // 0x8000D8A4: beq         $t1, $zero, L_8000D8CC
    if (ctx->r9 == 0) {
        // 0x8000D8A8: nop
    
            goto L_8000D8CC;
    }
    // 0x8000D8A8: nop

    // 0x8000D8AC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8000D8B0: nop

    // 0x8000D8B4: lw          $a0, 0x210($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X210);
    // 0x8000D8B8: jal         0x8000D390
    // 0x8000D8BC: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x8000D8BC: nop

    after_3:
    // 0x8000D8C0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8000D8C4: nop

    // 0x8000D8C8: sw          $zero, 0x210($t3)
    MEM_W(0X210, ctx->r11) = 0;
L_8000D8CC:
    // 0x8000D8CC: b           L_8000D8FC
    // 0x8000D8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D8FC;
    // 0x8000D8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000D8D4:
    // 0x8000D8D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D8D8: nop

    // 0x8000D8DC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000D8E0: slti        $at, $t5, 0x14
    ctx->r1 = SIGNED(ctx->r13) < 0X14 ? 1 : 0;
    // 0x8000D8E4: bne         $at, $zero, L_8000D75C
    if (ctx->r1 != 0) {
        // 0x8000D8E8: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_8000D75C;
    }
    // 0x8000D8E8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8000D8EC: b           L_8000D8FC
    // 0x8000D8F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D8FC;
    // 0x8000D8F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000D8F4: b           L_8000D8FC
    // 0x8000D8F8: nop

        goto L_8000D8FC;
    // 0x8000D8F8: nop

L_8000D8FC:
    // 0x8000D8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000D904: jr          $ra
    // 0x8000D908: nop

    return;
    // 0x8000D908: nop

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
RECOMP_FUNC void func_80059C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059C44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80059C48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80059C4C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80059C50: addiu       $t6, $t6, 0x28A0
    ctx->r14 = ADD32(ctx->r14, 0X28A0);
    // 0x80059C54: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80059C58: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80059C5C: nop

    // 0x80059C60: beq         $t7, $zero, L_80059D28
    if (ctx->r15 == 0) {
        // 0x80059C64: nop
    
            goto L_80059D28;
    }
    // 0x80059C64: nop

    // 0x80059C68: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x80059C6C: nop

    // 0x80059C70: beq         $t8, $zero, L_80059D28
    if (ctx->r24 == 0) {
        // 0x80059C74: nop
    
            goto L_80059D28;
    }
    // 0x80059C74: nop

L_80059C78:
    // 0x80059C78: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80059C7C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80059C80: addiu       $t0, $t0, 0x28A0
    ctx->r8 = ADD32(ctx->r8, 0X28A0);
    // 0x80059C84: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80059C88: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80059C8C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80059C90: nop

    // 0x80059C94: bne         $t2, $t3, L_80059CF0
    if (ctx->r10 != ctx->r11) {
        // 0x80059C98: nop
    
            goto L_80059CF0;
    }
    // 0x80059C98: nop

    // 0x80059C9C: lbu         $t4, 0x1($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X1);
    // 0x80059CA0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80059CA4: nop

    // 0x80059CA8: bne         $t4, $t5, L_80059CF0
    if (ctx->r12 != ctx->r13) {
        // 0x80059CAC: nop
    
            goto L_80059CF0;
    }
    // 0x80059CAC: nop

    // 0x80059CB0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80059CB4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80059CB8: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80059CBC: lbu         $t6, 0x28A2($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X28A2);
    // 0x80059CC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80059CC4: sh          $t6, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r14;
    // 0x80059CC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059CCC: sb          $t6, 0xD9C($at)
    MEM_B(0XD9C, ctx->r1) = ctx->r14;
    // 0x80059CD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80059CD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059CD8: sb          $t8, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r24;
    // 0x80059CDC: addiu       $t9, $zero, 0x1F
    ctx->r25 = ADD32(0, 0X1F);
    // 0x80059CE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059CE4: sh          $t9, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r25;
    // 0x80059CE8: b           L_80059D38
    // 0x80059CEC: nop

        goto L_80059D38;
    // 0x80059CEC: nop

L_80059CF0:
    // 0x80059CF0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80059CF4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80059CF8: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x80059CFC: addiu       $t3, $t3, 0x28A0
    ctx->r11 = ADD32(ctx->r11, 0X28A0);
    // 0x80059D00: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x80059D04: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80059D08: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80059D0C: nop

    // 0x80059D10: beq         $t4, $zero, L_80059D28
    if (ctx->r12 == 0) {
        // 0x80059D14: nop
    
            goto L_80059D28;
    }
    // 0x80059D14: nop

    // 0x80059D18: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80059D1C: nop

    // 0x80059D20: bne         $t5, $zero, L_80059C78
    if (ctx->r13 != 0) {
        // 0x80059D24: nop
    
            goto L_80059C78;
    }
    // 0x80059D24: nop

L_80059D28:
    // 0x80059D28: jal         0x80059D48
    // 0x80059D2C: nop

    func_80059D48(rdram, ctx);
        goto after_0;
    // 0x80059D2C: nop

    after_0:
    // 0x80059D30: b           L_80059D38
    // 0x80059D34: nop

        goto L_80059D38;
    // 0x80059D34: nop

L_80059D38:
    // 0x80059D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059D40: jr          $ra
    // 0x80059D44: nop

    return;
    // 0x80059D44: nop

;}
RECOMP_FUNC void MtxUtil__MtxFToMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2DD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C2DD4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800C2DD8: addiu       $t6, $a1, 0x20
    ctx->r14 = ADD32(ctx->r5, 0X20);
    // 0x800C2DDC: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C2DE0: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800C2DE4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800C2DE8:
    // 0x800C2DE8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800C2DEC:
    // 0x800C2DEC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C2DF0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800C2DF4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C2DF8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800C2DFC: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800C2E00: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C2E04: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C2E08: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800C2E0C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C2E10: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x800C2E14: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C2E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2E1C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800C2E20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C2E24: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C2E28: nop

    // 0x800C2E2C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C2E30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2E34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2E38: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C2E3C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C2E40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C2E44: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800C2E48: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C2E4C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800C2E50: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C2E54: nop

    // 0x800C2E58: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2E5C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C2E60: nop

    // 0x800C2E64: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800C2E68: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2E6C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2E70: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800C2E74: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C2E78: and         $t0, $a2, $at
    ctx->r8 = ctx->r6 & ctx->r1;
    // 0x800C2E7C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800C2E80: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C2E84: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800C2E88: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800C2E8C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800C2E90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C2E94: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C2E98: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x800C2E9C: nop

    // 0x800C2EA0: addiu       $t5, $t2, 0x4
    ctx->r13 = ADD32(ctx->r10, 0X4);
    // 0x800C2EA4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C2EA8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C2EAC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C2EB0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800C2EB4: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800C2EB8: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C2EBC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800C2EC0: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800C2EC4: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x800C2EC8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800C2ECC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C2ED0: nop

    // 0x800C2ED4: addiu       $t2, $t3, 0x4
    ctx->r10 = ADD32(ctx->r11, 0X4);
    // 0x800C2ED8: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x800C2EDC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800C2EE0: nop

    // 0x800C2EE4: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800C2EE8: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800C2EEC: bne         $at, $zero, L_800C2DEC
    if (ctx->r1 != 0) {
        // 0x800C2EF0: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800C2DEC;
    }
    // 0x800C2EF0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800C2EF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C2EF8: nop

    // 0x800C2EFC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800C2F00: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800C2F04: bne         $at, $zero, L_800C2DE8
    if (ctx->r1 != 0) {
        // 0x800C2F08: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_800C2DE8;
    }
    // 0x800C2F08: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800C2F0C: b           L_800C2F14
    // 0x800C2F10: nop

        goto L_800C2F14;
    // 0x800C2F10: nop

L_800C2F14:
    // 0x800C2F14: jr          $ra
    // 0x800C2F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C2F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800731F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800731F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800731F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800731FC: nop

    // 0x80073200: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80073204: nop

    // 0x80073208: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007320C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073210: jr          $ra
    // 0x80073214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073218: jr          $ra
    // 0x8007321C: nop

    return;
    // 0x8007321C: nop

    // 0x80073220: jr          $ra
    // 0x80073224: nop

    return;
    // 0x80073224: nop

;}
RECOMP_FUNC void func_8000DE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DE84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000DE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DE8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000DE90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000DE94: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8000DE98: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000DE9C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8000DEA0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000DEA4: nop

    // 0x8000DEA8: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x8000DEAC: nop

    // 0x8000DEB0: beq         $t8, $zero, L_8000DF68
    if (ctx->r24 == 0) {
        // 0x8000DEB4: nop
    
            goto L_8000DF68;
    }
    // 0x8000DEB4: nop

    // 0x8000DEB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000DEBC: nop

    // 0x8000DEC0: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x8000DEC4: nop

    // 0x8000DEC8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8000DECC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DED0: nop

    // 0x8000DED4: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x8000DED8: nop

    // 0x8000DEDC: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8000DEE0: bne         $at, $zero, L_8000DF04
    if (ctx->r1 != 0) {
        // 0x8000DEE4: nop
    
            goto L_8000DF04;
    }
    // 0x8000DEE4: nop

    // 0x8000DEE8: slti        $at, $t2, 0x2A
    ctx->r1 = SIGNED(ctx->r10) < 0X2A ? 1 : 0;
    // 0x8000DEEC: beq         $at, $zero, L_8000DF04
    if (ctx->r1 == 0) {
        // 0x8000DEF0: nop
    
            goto L_8000DF04;
    }
    // 0x8000DEF0: nop

    // 0x8000DEF4: lw          $t3, 0x7C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X7C);
    // 0x8000DEF8: nop

    // 0x8000DEFC: bne         $t3, $zero, L_8000DF68
    if (ctx->r11 != 0) {
        // 0x8000DF00: nop
    
            goto L_8000DF68;
    }
    // 0x8000DF00: nop

L_8000DF04:
    // 0x8000DF04: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DF08: nop

    // 0x8000DF0C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8000DF10: nop

    // 0x8000DF14: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8000DF18: beq         $t6, $zero, L_8000DF3C
    if (ctx->r14 == 0) {
        // 0x8000DF1C: nop
    
            goto L_8000DF3C;
    }
    // 0x8000DF1C: nop

    // 0x8000DF20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF24: jal         0x8000E524
    // 0x8000DF28: nop

    func_8000E524(rdram, ctx);
        goto after_0;
    // 0x8000DF28: nop

    after_0:
    // 0x8000DF2C: bgez        $v0, L_8000DF3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000DF30: nop
    
            goto L_8000DF3C;
    }
    // 0x8000DF30: nop

    // 0x8000DF34: b           L_8000E3C4
    // 0x8000DF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E3C4;
    // 0x8000DF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DF3C:
    // 0x8000DF3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF40: jal         0x8000E678
    // 0x8000DF44: nop

    func_8000E678(rdram, ctx);
        goto after_1;
    // 0x8000DF44: nop

    after_1:
    // 0x8000DF48: bgez        $v0, L_8000DF58
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000DF4C: nop
    
            goto L_8000DF58;
    }
    // 0x8000DF4C: nop

    // 0x8000DF50: b           L_8000E3C4
    // 0x8000DF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E3C4;
    // 0x8000DF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DF58:
    // 0x8000DF58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF5C: jal         0x8000E9F8
    // 0x8000DF60: nop

    func_8000E9F8(rdram, ctx);
        goto after_2;
    // 0x8000DF60: nop

    after_2:
    // 0x8000DF64: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8000DF68:
    // 0x8000DF68: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000DF6C: nop

    // 0x8000DF70: bne         $t7, $zero, L_8000E354
    if (ctx->r15 != 0) {
        // 0x8000DF74: nop
    
            goto L_8000E354;
    }
    // 0x8000DF74: nop

    // 0x8000DF78: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000DF7C: nop

    // 0x8000DF80: beq         $t8, $zero, L_8000E354
    if (ctx->r24 == 0) {
        // 0x8000DF84: nop
    
            goto L_8000E354;
    }
    // 0x8000DF84: nop

L_8000DF88:
    // 0x8000DF88: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF8C: nop

    // 0x8000DF90: lwc1        $f4, 0x1EC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1EC);
    // 0x8000DF94: lwc1        $f6, 0x1E8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1E8);
    // 0x8000DF98: nop

    // 0x8000DF9C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8000DFA0: nop

    // 0x8000DFA4: bc1f        L_8000DFB4
    if (!c1cs) {
        // 0x8000DFA8: nop
    
            goto L_8000DFB4;
    }
    // 0x8000DFA8: nop

    // 0x8000DFAC: b           L_8000E354
    // 0x8000DFB0: nop

        goto L_8000E354;
    // 0x8000DFB0: nop

L_8000DFB4:
    // 0x8000DFB4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000DFB8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000DFBC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8000DFC0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000DFC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000DFC8: lwc1        $f8, 0x1E8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1E8);
    // 0x8000DFCC: lw          $t2, 0x210($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X210);
    // 0x8000DFD0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000DFD4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000DFD8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8000DFDC: ori         $at, $at, 0x3FFE
    ctx->r1 = ctx->r1 | 0X3FFE;
    // 0x8000DFE0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000DFE4: bgez        $t3, L_8000DFF8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000DFE8: andi        $t4, $t3, 0x7F
        ctx->r12 = ctx->r11 & 0X7F;
            goto L_8000DFF8;
    }
    // 0x8000DFE8: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x8000DFEC: beq         $t4, $zero, L_8000DFF8
    if (ctx->r12 == 0) {
        // 0x8000DFF0: nop
    
            goto L_8000DFF8;
    }
    // 0x8000DFF0: nop

    // 0x8000DFF4: addiu       $t4, $t4, -0x80
    ctx->r12 = ADD32(ctx->r12, -0X80);
L_8000DFF8:
    // 0x8000DFF8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000DFFC: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8000E000: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000E004: nop

    // 0x8000E008: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8000E00C: sltiu       $at, $t8, 0x30
    ctx->r1 = ctx->r24 < 0X30 ? 1 : 0;
    // 0x8000E010: beq         $at, $zero, L_8000E318
    if (ctx->r1 == 0) {
        // 0x8000E014: nop
    
            goto L_8000E318;
    }
    // 0x8000E014: nop

    // 0x8000E018: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000E01C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000E020: addu        $at, $at, $t8
    gpr jr_addend_8000E02C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8000E024: lw          $t8, -0x2CA0($at)
    ctx->r24 = ADD32(ctx->r1, -0X2CA0);
    // 0x8000E028: nop

    // 0x8000E02C: jr          $t8
    // 0x8000E030: nop

    switch (jr_addend_8000E02C >> 2) {
        case 0: goto L_8000E034; break;
        case 1: goto L_8000E098; break;
        case 2: goto L_8000E0AC; break;
        case 3: goto L_8000E0C0; break;
        case 4: goto L_8000E318; break;
        case 5: goto L_8000E318; break;
        case 6: goto L_8000E318; break;
        case 7: goto L_8000E318; break;
        case 8: goto L_8000E0D4; break;
        case 9: goto L_8000E318; break;
        case 10: goto L_8000E318; break;
        case 11: goto L_8000E318; break;
        case 12: goto L_8000E318; break;
        case 13: goto L_8000E318; break;
        case 14: goto L_8000E144; break;
        case 15: goto L_8000E318; break;
        case 16: goto L_8000E120; break;
        case 17: goto L_8000E318; break;
        case 18: goto L_8000E318; break;
        case 19: goto L_8000E0F8; break;
        case 20: goto L_8000E10C; break;
        case 21: goto L_8000E318; break;
        case 22: goto L_8000E168; break;
        case 23: goto L_8000E17C; break;
        case 24: goto L_8000E190; break;
        case 25: goto L_8000E1A4; break;
        case 26: goto L_8000E1B8; break;
        case 27: goto L_8000E1CC; break;
        case 28: goto L_8000E1E0; break;
        case 29: goto L_8000E1F4; break;
        case 30: goto L_8000E208; break;
        case 31: goto L_8000E21C; break;
        case 32: goto L_8000E240; break;
        case 33: goto L_8000E318; break;
        case 34: goto L_8000E318; break;
        case 35: goto L_8000E254; break;
        case 36: goto L_8000E268; break;
        case 37: goto L_8000E27C; break;
        case 38: goto L_8000E2A0; break;
        case 39: goto L_8000E2B4; break;
        case 40: goto L_8000E318; break;
        case 41: goto L_8000E318; break;
        case 42: goto L_8000E2C8; break;
        case 43: goto L_8000E2DC; break;
        case 44: goto L_8000E318; break;
        case 45: goto L_8000E318; break;
        case 46: goto L_8000E2F0; break;
        case 47: goto L_8000E304; break;
        default: switch_error(__func__, 0x8000E02C, 0x800ED360);
    }
    // 0x8000E030: nop

L_8000E034:
    // 0x8000E034: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000E038: nop

    // 0x8000E03C: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x8000E040: nop

    // 0x8000E044: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8000E048: beq         $t1, $zero, L_8000E070
    if (ctx->r9 == 0) {
        // 0x8000E04C: nop
    
            goto L_8000E070;
    }
    // 0x8000E04C: nop

    // 0x8000E050: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8000E054: nop

    // 0x8000E058: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000E05C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8000E060: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8000E064: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8000E068: b           L_8000E334
    // 0x8000E06C: nop

        goto L_8000E334;
    // 0x8000E06C: nop

L_8000E070:
    // 0x8000E070: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E074: jal         0x800111E8
    // 0x8000E078: nop

    func_800111E8(rdram, ctx);
        goto after_3;
    // 0x8000E078: nop

    after_3:
    // 0x8000E07C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8000E080: nop

    // 0x8000E084: lw          $t6, 0x20C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20C);
    // 0x8000E088: nop

    // 0x8000E08C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000E090: b           L_8000E334
    // 0x8000E094: nop

        goto L_8000E334;
    // 0x8000E094: nop

L_8000E098:
    // 0x8000E098: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E09C: jal         0x8001173C
    // 0x8000E0A0: nop

    func_8001173C(rdram, ctx);
        goto after_4;
    // 0x8000E0A0: nop

    after_4:
    // 0x8000E0A4: b           L_8000E334
    // 0x8000E0A8: nop

        goto L_8000E334;
    // 0x8000E0A8: nop

L_8000E0AC:
    // 0x8000E0AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0B0: jal         0x80011A0C
    // 0x8000E0B4: nop

    func_80011A0C(rdram, ctx);
        goto after_5;
    // 0x8000E0B4: nop

    after_5:
    // 0x8000E0B8: b           L_8000E334
    // 0x8000E0BC: nop

        goto L_8000E334;
    // 0x8000E0BC: nop

L_8000E0C0:
    // 0x8000E0C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0C4: jal         0x800131F4
    // 0x8000E0C8: nop

    func_800131F4(rdram, ctx);
        goto after_6;
    // 0x8000E0C8: nop

    after_6:
    // 0x8000E0CC: b           L_8000E334
    // 0x8000E0D0: nop

        goto L_8000E334;
    // 0x8000E0D0: nop

L_8000E0D4:
    // 0x8000E0D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0D8: jal         0x80011B88
    // 0x8000E0DC: nop

    func_80011B88(rdram, ctx);
        goto after_7;
    // 0x8000E0DC: nop

    after_7:
    // 0x8000E0E0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000E0E4: nop

    // 0x8000E0E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000E0EC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8000E0F0: b           L_8000E334
    // 0x8000E0F4: nop

        goto L_8000E334;
    // 0x8000E0F4: nop

L_8000E0F8:
    // 0x8000E0F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0FC: jal         0x80011F7C
    // 0x8000E100: nop

    func_80011F7C(rdram, ctx);
        goto after_8;
    // 0x8000E100: nop

    after_8:
    // 0x8000E104: b           L_8000E334
    // 0x8000E108: nop

        goto L_8000E334;
    // 0x8000E108: nop

L_8000E10C:
    // 0x8000E10C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E110: jal         0x80012068
    // 0x8000E114: nop

    func_80012068(rdram, ctx);
        goto after_9;
    // 0x8000E114: nop

    after_9:
    // 0x8000E118: b           L_8000E334
    // 0x8000E11C: nop

        goto L_8000E334;
    // 0x8000E11C: nop

L_8000E120:
    // 0x8000E120: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E124: jal         0x800123AC
    // 0x8000E128: nop

    func_800123AC(rdram, ctx);
        goto after_10;
    // 0x8000E128: nop

    after_10:
    // 0x8000E12C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E130: nop

    // 0x8000E134: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000E138: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8000E13C: b           L_8000E334
    // 0x8000E140: nop

        goto L_8000E334;
    // 0x8000E140: nop

L_8000E144:
    // 0x8000E144: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E148: jal         0x80012164
    // 0x8000E14C: nop

    func_80012164(rdram, ctx);
        goto after_11;
    // 0x8000E14C: nop

    after_11:
    // 0x8000E150: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000E154: nop

    // 0x8000E158: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8000E15C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8000E160: b           L_8000E334
    // 0x8000E164: nop

        goto L_8000E334;
    // 0x8000E164: nop

L_8000E168:
    // 0x8000E168: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E16C: jal         0x800124B8
    // 0x8000E170: nop

    func_800124B8(rdram, ctx);
        goto after_12;
    // 0x8000E170: nop

    after_12:
    // 0x8000E174: b           L_8000E334
    // 0x8000E178: nop

        goto L_8000E334;
    // 0x8000E178: nop

L_8000E17C:
    // 0x8000E17C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E180: jal         0x80012634
    // 0x8000E184: nop

    func_80012634(rdram, ctx);
        goto after_13;
    // 0x8000E184: nop

    after_13:
    // 0x8000E188: b           L_8000E334
    // 0x8000E18C: nop

        goto L_8000E334;
    // 0x8000E18C: nop

L_8000E190:
    // 0x8000E190: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E194: jal         0x8001292C
    // 0x8000E198: nop

    func_8001292C(rdram, ctx);
        goto after_14;
    // 0x8000E198: nop

    after_14:
    // 0x8000E19C: b           L_8000E334
    // 0x8000E1A0: nop

        goto L_8000E334;
    // 0x8000E1A0: nop

L_8000E1A4:
    // 0x8000E1A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1A8: jal         0x80013474
    // 0x8000E1AC: nop

    func_80013474(rdram, ctx);
        goto after_15;
    // 0x8000E1AC: nop

    after_15:
    // 0x8000E1B0: b           L_8000E334
    // 0x8000E1B4: nop

        goto L_8000E334;
    // 0x8000E1B4: nop

L_8000E1B8:
    // 0x8000E1B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1BC: jal         0x80012798
    // 0x8000E1C0: nop

    func_80012798(rdram, ctx);
        goto after_16;
    // 0x8000E1C0: nop

    after_16:
    // 0x8000E1C4: b           L_8000E334
    // 0x8000E1C8: nop

        goto L_8000E334;
    // 0x8000E1C8: nop

L_8000E1CC:
    // 0x8000E1CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1D0: jal         0x800129FC
    // 0x8000E1D4: nop

    func_800129FC(rdram, ctx);
        goto after_17;
    // 0x8000E1D4: nop

    after_17:
    // 0x8000E1D8: b           L_8000E334
    // 0x8000E1DC: nop

        goto L_8000E334;
    // 0x8000E1DC: nop

L_8000E1E0:
    // 0x8000E1E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1E4: jal         0x80012E7C
    // 0x8000E1E8: nop

    func_80012E7C(rdram, ctx);
        goto after_18;
    // 0x8000E1E8: nop

    after_18:
    // 0x8000E1EC: b           L_8000E334
    // 0x8000E1F0: nop

        goto L_8000E334;
    // 0x8000E1F0: nop

L_8000E1F4:
    // 0x8000E1F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1F8: jal         0x80013398
    // 0x8000E1FC: nop

    func_80013398(rdram, ctx);
        goto after_19;
    // 0x8000E1FC: nop

    after_19:
    // 0x8000E200: b           L_8000E334
    // 0x8000E204: nop

        goto L_8000E334;
    // 0x8000E204: nop

L_8000E208:
    // 0x8000E208: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E20C: jal         0x80013624
    // 0x8000E210: nop

    func_80013624(rdram, ctx);
        goto after_20;
    // 0x8000E210: nop

    after_20:
    // 0x8000E214: b           L_8000E334
    // 0x8000E218: nop

        goto L_8000E334;
    // 0x8000E218: nop

L_8000E21C:
    // 0x8000E21C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E220: jal         0x800139B8
    // 0x8000E224: nop

    func_800139B8(rdram, ctx);
        goto after_21;
    // 0x8000E224: nop

    after_21:
    // 0x8000E228: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8000E22C: nop

    // 0x8000E230: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x8000E234: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8000E238: b           L_8000E334
    // 0x8000E23C: nop

        goto L_8000E334;
    // 0x8000E23C: nop

L_8000E240:
    // 0x8000E240: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E244: jal         0x80013AFC
    // 0x8000E248: nop

    func_80013AFC(rdram, ctx);
        goto after_22;
    // 0x8000E248: nop

    after_22:
    // 0x8000E24C: b           L_8000E334
    // 0x8000E250: nop

        goto L_8000E334;
    // 0x8000E250: nop

L_8000E254:
    // 0x8000E254: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E258: jal         0x80013F04
    // 0x8000E25C: nop

    func_80013F04(rdram, ctx);
        goto after_23;
    // 0x8000E25C: nop

    after_23:
    // 0x8000E260: b           L_8000E334
    // 0x8000E264: nop

        goto L_8000E334;
    // 0x8000E264: nop

L_8000E268:
    // 0x8000E268: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E26C: jal         0x800140D8
    // 0x8000E270: nop

    func_800140D8(rdram, ctx);
        goto after_24;
    // 0x8000E270: nop

    after_24:
    // 0x8000E274: b           L_8000E334
    // 0x8000E278: nop

        goto L_8000E334;
    // 0x8000E278: nop

L_8000E27C:
    // 0x8000E27C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E280: jal         0x80014228
    // 0x8000E284: nop

    func_80014228(rdram, ctx);
        goto after_25;
    // 0x8000E284: nop

    after_25:
    // 0x8000E288: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8000E28C: nop

    // 0x8000E290: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000E294: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8000E298: b           L_8000E334
    // 0x8000E29C: nop

        goto L_8000E334;
    // 0x8000E29C: nop

L_8000E2A0:
    // 0x8000E2A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2A4: jal         0x80015C30
    // 0x8000E2A8: nop

    func_80015C30(rdram, ctx);
        goto after_26;
    // 0x8000E2A8: nop

    after_26:
    // 0x8000E2AC: b           L_8000E334
    // 0x8000E2B0: nop

        goto L_8000E334;
    // 0x8000E2B0: nop

L_8000E2B4:
    // 0x8000E2B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2B8: jal         0x800145D4
    // 0x8000E2BC: nop

    func_800145D4(rdram, ctx);
        goto after_27;
    // 0x8000E2BC: nop

    after_27:
    // 0x8000E2C0: b           L_8000E334
    // 0x8000E2C4: nop

        goto L_8000E334;
    // 0x8000E2C4: nop

L_8000E2C8:
    // 0x8000E2C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2CC: jal         0x80015D74
    // 0x8000E2D0: nop

    func_80015D74(rdram, ctx);
        goto after_28;
    // 0x8000E2D0: nop

    after_28:
    // 0x8000E2D4: b           L_8000E334
    // 0x8000E2D8: nop

        goto L_8000E334;
    // 0x8000E2D8: nop

L_8000E2DC:
    // 0x8000E2DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2E0: jal         0x80014A80
    // 0x8000E2E4: nop

    func_80014A80(rdram, ctx);
        goto after_29;
    // 0x8000E2E4: nop

    after_29:
    // 0x8000E2E8: b           L_8000E334
    // 0x8000E2EC: nop

        goto L_8000E334;
    // 0x8000E2EC: nop

L_8000E2F0:
    // 0x8000E2F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2F4: jal         0x80013C90
    // 0x8000E2F8: nop

    func_80013C90(rdram, ctx);
        goto after_30;
    // 0x8000E2F8: nop

    after_30:
    // 0x8000E2FC: b           L_8000E334
    // 0x8000E300: nop

        goto L_8000E334;
    // 0x8000E300: nop

L_8000E304:
    // 0x8000E304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E308: jal         0x80013FEC
    // 0x8000E30C: nop

    func_80013FEC(rdram, ctx);
        goto after_31;
    // 0x8000E30C: nop

    after_31:
    // 0x8000E310: b           L_8000E334
    // 0x8000E314: nop

        goto L_8000E334;
    // 0x8000E314: nop

L_8000E318:
    // 0x8000E318: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000E31C: lw          $t7, 0x3DF4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3DF4);
    // 0x8000E320: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000E324: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000E328: sw          $t8, 0x3DF4($at)
    MEM_W(0X3DF4, ctx->r1) = ctx->r24;
    // 0x8000E32C: b           L_8000E334
    // 0x8000E330: nop

        goto L_8000E334;
    // 0x8000E330: nop

L_8000E334:
    // 0x8000E334: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E338: nop

    // 0x8000E33C: bne         $t9, $zero, L_8000E354
    if (ctx->r25 != 0) {
        // 0x8000E340: nop
    
            goto L_8000E354;
    }
    // 0x8000E340: nop

    // 0x8000E344: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000E348: nop

    // 0x8000E34C: bne         $t0, $zero, L_8000DF88
    if (ctx->r8 != 0) {
        // 0x8000E350: nop
    
            goto L_8000DF88;
    }
    // 0x8000E350: nop

L_8000E354:
    // 0x8000E354: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000E358: nop

    // 0x8000E35C: lw          $t3, 0x20C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X20C);
    // 0x8000E360: nop

    // 0x8000E364: beq         $t3, $zero, L_8000E3B0
    if (ctx->r11 == 0) {
        // 0x8000E368: nop
    
            goto L_8000E3B0;
    }
    // 0x8000E368: nop

    // 0x8000E36C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E370: nop

    // 0x8000E374: lhu         $t2, 0x2($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X2);
    // 0x8000E378: nop

    // 0x8000E37C: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8000E380: bne         $at, $zero, L_8000E3A4
    if (ctx->r1 != 0) {
        // 0x8000E384: nop
    
            goto L_8000E3A4;
    }
    // 0x8000E384: nop

    // 0x8000E388: slti        $at, $t2, 0x2A
    ctx->r1 = SIGNED(ctx->r10) < 0X2A ? 1 : 0;
    // 0x8000E38C: beq         $at, $zero, L_8000E3A4
    if (ctx->r1 == 0) {
        // 0x8000E390: nop
    
            goto L_8000E3A4;
    }
    // 0x8000E390: nop

    // 0x8000E394: lw          $t5, 0x7C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X7C);
    // 0x8000E398: nop

    // 0x8000E39C: bne         $t5, $zero, L_8000E3B0
    if (ctx->r13 != 0) {
        // 0x8000E3A0: nop
    
            goto L_8000E3B0;
    }
    // 0x8000E3A0: nop

L_8000E3A4:
    // 0x8000E3A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E3A8: jal         0x8000E7E4
    // 0x8000E3AC: nop

    func_8000E7E4(rdram, ctx);
        goto after_32;
    // 0x8000E3AC: nop

    after_32:
L_8000E3B0:
    // 0x8000E3B0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8000E3B4: b           L_8000E3C4
    // 0x8000E3B8: nop

        goto L_8000E3C4;
    // 0x8000E3B8: nop

    // 0x8000E3BC: b           L_8000E3C4
    // 0x8000E3C0: nop

        goto L_8000E3C4;
    // 0x8000E3C0: nop

L_8000E3C4:
    // 0x8000E3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E3C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000E3CC: jr          $ra
    // 0x8000E3D0: nop

    return;
    // 0x8000E3D0: nop

;}
RECOMP_FUNC void func_8006E120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E128: jal         0x80061348
    // 0x8006E12C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E12C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006E130: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E134: b           L_8006E144
    // 0x8006E138: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E144;
    // 0x8006E138: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E13C: b           L_8006E144
    // 0x8006E140: nop

        goto L_8006E144;
    // 0x8006E140: nop

L_8006E144:
    // 0x8006E144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E14C: jr          $ra
    // 0x8006E150: nop

    return;
    // 0x8006E150: nop

;}
RECOMP_FUNC void func_800AC524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC524: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800AC528: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800AC52C: nop

    // 0x800AC530: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800AC534: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC538: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC53C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AC540: nop

    // 0x800AC544: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AC548: nop

    // 0x800AC54C: bc1f        L_800AC560
    if (!c1cs) {
        // 0x800AC550: nop
    
            goto L_800AC560;
    }
    // 0x800AC550: nop

    // 0x800AC554: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AC558: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC55C: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
L_800AC560:
    // 0x800AC560: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC564: lwc1        $f10, 0x6198($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC568: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AC56C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AC570: nop

    // 0x800AC574: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800AC578: nop

    // 0x800AC57C: bc1f        L_800AC594
    if (!c1cs) {
        // 0x800AC580: nop
    
            goto L_800AC594;
    }
    // 0x800AC580: nop

    // 0x800AC584: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AC588: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC58C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC590: swc1        $f18, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f18.u32l;
L_800AC594:
    // 0x800AC594: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC598: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC59C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AC5A0: nop

    // 0x800AC5A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AC5A8: nop

    // 0x800AC5AC: bc1f        L_800AC5C0
    if (!c1cs) {
        // 0x800AC5B0: nop
    
            goto L_800AC5C0;
    }
    // 0x800AC5B0: nop

    // 0x800AC5B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AC5B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC5BC: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
L_800AC5C0:
    // 0x800AC5C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC5C4: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC5C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AC5CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AC5D0: nop

    // 0x800AC5D4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800AC5D8: nop

    // 0x800AC5DC: bc1f        L_800AC5F4
    if (!c1cs) {
        // 0x800AC5E0: nop
    
            goto L_800AC5F4;
    }
    // 0x800AC5E0: nop

    // 0x800AC5E4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AC5E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC5EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC5F0: swc1        $f18, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f18.u32l;
L_800AC5F4:
    // 0x800AC5F4: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800AC5F8: nop

    // 0x800AC5FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AC600: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800AC604: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800AC608: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AC60C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC610: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC614: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AC618: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC61C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC620: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC624: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC628: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AC62C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800AC630: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AC634: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800AC638: nop

    // 0x800AC63C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AC640: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AC644: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AC648: nop

    // 0x800AC64C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AC650: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC654: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC658: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800AC65C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AC660: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800AC664: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AC668: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800AC66C: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x800AC670: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800AC674: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC678: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC67C: lwc1        $f6, 0x6194($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC680: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC684: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC688: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC68C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC690: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC694: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC698: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800AC69C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC6A0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800AC6A4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800AC6A8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC6AC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AC6B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AC6B4: nop

    // 0x800AC6B8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AC6BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC6C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC6C4: nop

    // 0x800AC6C8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC6CC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AC6D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AC6D4: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x800AC6D8: or          $t1, $t5, $t0
    ctx->r9 = ctx->r13 | ctx->r8;
    // 0x800AC6DC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800AC6E0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AC6E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC6E8: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC6EC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AC6F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC6F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC6F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC6FC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AC704: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AC708: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AC70C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800AC710: nop

    // 0x800AC714: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AC718: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AC71C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC720: nop

    // 0x800AC724: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC728: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC72C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC730: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC734: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC738: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC73C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC740: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800AC744: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800AC748: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AC74C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800AC750: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AC754: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC758: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC75C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC760: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AC764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AC768: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x800AC76C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AC770: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800AC774: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800AC778: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AC77C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AC780: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AC784: nop

    // 0x800AC788: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AC78C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC790: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC794: nop

    // 0x800AC798: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC79C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800AC7A0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AC7A4: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800AC7A8: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800AC7AC: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x800AC7B0: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800AC7B4: nop

    // 0x800AC7B8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AC7BC: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800AC7C0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800AC7C4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800AC7C8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800AC7CC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AC7D0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800AC7D4: nop

    // 0x800AC7D8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AC7DC: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800AC7E0: nop

    // 0x800AC7E4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800AC7E8: b           L_800AC7F0
    // 0x800AC7EC: nop

        goto L_800AC7F0;
    // 0x800AC7EC: nop

L_800AC7F0:
    // 0x800AC7F0: jr          $ra
    // 0x800AC7F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800AC7F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80085C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80085C90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085C94: jal         0x8008B4EC
    // 0x80085C98: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80085C98: nop

    after_0:
    // 0x80085C9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CA0: jal         0x8008B600
    // 0x80085CA4: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80085CA4: nop

    after_1:
    // 0x80085CA8: b           L_80085CB0
    // 0x80085CAC: nop

        goto L_80085CB0;
    // 0x80085CAC: nop

L_80085CB0:
    // 0x80085CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085CB8: jr          $ra
    // 0x80085CBC: nop

    return;
    // 0x80085CBC: nop

;}
RECOMP_FUNC void func_80074EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074EB0: jal         0x80061348
    // 0x80074EB4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074EB4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80074EB8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074EBC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074EC0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074EC4: beq         $v0, $zero, L_80074F18
    if (ctx->r2 == 0) {
        // 0x80074EC8: nop
    
            goto L_80074F18;
    }
    // 0x80074EC8: nop

    // 0x80074ECC: jal         0x80061348
    // 0x80074ED0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074ED0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80074ED4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074ED8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074EDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074EE0: beq         $v0, $zero, L_80074F18
    if (ctx->r2 == 0) {
        // 0x80074EE4: nop
    
            goto L_80074F18;
    }
    // 0x80074EE4: nop

    // 0x80074EE8: jal         0x80061348
    // 0x80074EEC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074EEC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80074EF0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074EF4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074EF8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074EFC: beq         $v0, $zero, L_80074F18
    if (ctx->r2 == 0) {
        // 0x80074F00: nop
    
            goto L_80074F18;
    }
    // 0x80074F00: nop

    // 0x80074F04: jal         0x80061348
    // 0x80074F08: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074F08: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x80074F0C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074F10: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074F14: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074F18:
    // 0x80074F18: b           L_80074F28
    // 0x80074F1C: nop

        goto L_80074F28;
    // 0x80074F1C: nop

    // 0x80074F20: b           L_80074F28
    // 0x80074F24: nop

        goto L_80074F28;
    // 0x80074F24: nop

L_80074F28:
    // 0x80074F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074F30: jr          $ra
    // 0x80074F34: nop

    return;
    // 0x80074F34: nop

;}
RECOMP_FUNC void func_8006BBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BBD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BBD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BBD8: jal         0x80061488
    // 0x8006BBDC: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BBDC: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
    after_0:
    // 0x8006BBE0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006BBE4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006BBE8: b           L_8006BBF8
    // 0x8006BBEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BBF8;
    // 0x8006BBEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BBF0: b           L_8006BBF8
    // 0x8006BBF4: nop

        goto L_8006BBF8;
    // 0x8006BBF4: nop

L_8006BBF8:
    // 0x8006BBF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BC00: jr          $ra
    // 0x8006BC04: nop

    return;
    // 0x8006BC04: nop

;}
RECOMP_FUNC void func_8008AF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AF5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008AF60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008AF64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008AF68: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008AF6C: nop

    // 0x8008AF70: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008AF74: nop

    // 0x8008AF78: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x8008AF7C: bne         $t8, $zero, L_8008AFE4
    if (ctx->r24 != 0) {
        // 0x8008AF80: nop
    
            goto L_8008AFE4;
    }
    // 0x8008AF80: nop

    // 0x8008AF84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AF88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008AF8C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008AF90: lui         $at, 0xC254
    ctx->r1 = S32(0XC254 << 16);
    // 0x8008AF94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008AF98: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008AF9C: ori         $a2, $a2, 0x227
    ctx->r6 = ctx->r6 | 0X227;
    // 0x8008AFA0: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008AFA4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008AFA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8008AFAC: addiu       $a0, $t9, 0x24
    ctx->r4 = ADD32(ctx->r25, 0X24);
    // 0x8008AFB0: addiu       $a1, $t9, 0x28
    ctx->r5 = ADD32(ctx->r25, 0X28);
    // 0x8008AFB4: jal         0x800B202C
    // 0x8008AFB8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_0;
    // 0x8008AFB8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8008AFBC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFC0: nop

    // 0x8008AFC4: sh          $v0, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r2;
    // 0x8008AFC8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFCC: nop

    // 0x8008AFD0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8008AFD4: nop

    // 0x8008AFD8: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8008AFDC: b           L_8008B004
    // 0x8008AFE0: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_8008B004;
    // 0x8008AFE0: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_8008AFE4:
    // 0x8008AFE4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFE8: nop

    // 0x8008AFEC: addiu       $a0, $t4, 0x24
    ctx->r4 = ADD32(ctx->r12, 0X24);
    // 0x8008AFF0: jal         0x800B2748
    // 0x8008AFF4: addiu       $a1, $t4, 0x28
    ctx->r5 = ADD32(ctx->r12, 0X28);
    func_800B2748(rdram, ctx);
        goto after_1;
    // 0x8008AFF4: addiu       $a1, $t4, 0x28
    ctx->r5 = ADD32(ctx->r12, 0X28);
    after_1:
    // 0x8008AFF8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFFC: nop

    // 0x8008B000: sh          $v0, 0x2E($t5)
    MEM_H(0X2E, ctx->r13) = ctx->r2;
L_8008B004:
    // 0x8008B004: jal         0x80031AC8
    // 0x8008B008: nop

    func_80031AC8(rdram, ctx);
        goto after_2;
    // 0x8008B008: nop

    after_2:
    // 0x8008B00C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B010: bne         $v0, $at, L_8008B0BC
    if (ctx->r2 != ctx->r1) {
        // 0x8008B014: nop
    
            goto L_8008B0BC;
    }
    // 0x8008B014: nop

    // 0x8008B018: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008B01C: nop

    // 0x8008B020: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008B024: nop

    // 0x8008B028: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8008B02C: bne         $t8, $zero, L_8008B094
    if (ctx->r24 != 0) {
        // 0x8008B030: nop
    
            goto L_8008B094;
    }
    // 0x8008B030: nop

    // 0x8008B034: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008B03C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008B040: lui         $at, 0xC254
    ctx->r1 = S32(0XC254 << 16);
    // 0x8008B044: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B048: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008B04C: ori         $a2, $a2, 0x228
    ctx->r6 = ctx->r6 | 0X228;
    // 0x8008B050: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008B054: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008B058: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8008B05C: addiu       $a0, $t9, 0x30
    ctx->r4 = ADD32(ctx->r25, 0X30);
    // 0x8008B060: addiu       $a1, $t9, 0x34
    ctx->r5 = ADD32(ctx->r25, 0X34);
    // 0x8008B064: jal         0x800B202C
    // 0x8008B068: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B202C(rdram, ctx);
        goto after_3;
    // 0x8008B068: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8008B06C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008B070: nop

    // 0x8008B074: sh          $v0, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r2;
    // 0x8008B078: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008B07C: nop

    // 0x8008B080: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8008B084: nop

    // 0x8008B088: ori         $t1, $t3, 0x10
    ctx->r9 = ctx->r11 | 0X10;
    // 0x8008B08C: b           L_8008B0B4
    // 0x8008B090: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
        goto L_8008B0B4;
    // 0x8008B090: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
L_8008B094:
    // 0x8008B094: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008B098: nop

    // 0x8008B09C: addiu       $a0, $t4, 0x30
    ctx->r4 = ADD32(ctx->r12, 0X30);
    // 0x8008B0A0: jal         0x800B2748
    // 0x8008B0A4: addiu       $a1, $t4, 0x34
    ctx->r5 = ADD32(ctx->r12, 0X34);
    func_800B2748(rdram, ctx);
        goto after_4;
    // 0x8008B0A4: addiu       $a1, $t4, 0x34
    ctx->r5 = ADD32(ctx->r12, 0X34);
    after_4:
    // 0x8008B0A8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8008B0AC: nop

    // 0x8008B0B0: sh          $v0, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r2;
L_8008B0B4:
    // 0x8008B0B4: b           L_8008B0F0
    // 0x8008B0B8: nop

        goto L_8008B0F0;
    // 0x8008B0B8: nop

L_8008B0BC:
    // 0x8008B0BC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008B0C0: nop

    // 0x8008B0C4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008B0C8: nop

    // 0x8008B0CC: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8008B0D0: beq         $t8, $zero, L_8008B0F0
    if (ctx->r24 == 0) {
        // 0x8008B0D4: nop
    
            goto L_8008B0F0;
    }
    // 0x8008B0D4: nop

    // 0x8008B0D8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008B0DC: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8008B0E0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8008B0E4: nop

    // 0x8008B0E8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8008B0EC: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
L_8008B0F0:
    // 0x8008B0F0: b           L_8008B0F8
    // 0x8008B0F4: nop

        goto L_8008B0F8;
    // 0x8008B0F4: nop

L_8008B0F8:
    // 0x8008B0F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008B0FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008B100: jr          $ra
    // 0x8008B104: nop

    return;
    // 0x8008B104: nop

;}
RECOMP_FUNC void func_8008308C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008308C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80083090: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083094: lw          $t6, 0x165C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X165C);
    // 0x80083098: nop

    // 0x8008309C: bne         $t6, $zero, L_800830AC
    if (ctx->r14 != 0) {
        // 0x800830A0: nop
    
            goto L_800830AC;
    }
    // 0x800830A0: nop

    // 0x800830A4: b           L_80083124
    // 0x800830A8: nop

        goto L_80083124;
    // 0x800830A8: nop

L_800830AC:
    // 0x800830AC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800830B0: lw          $t7, 0x165C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X165C);
    // 0x800830B4: nop

    // 0x800830B8: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800830BC:
    // 0x800830BC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800830C0: nop

    // 0x800830C4: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x800830C8: nop

    // 0x800830CC: bne         $t9, $a0, L_80083104
    if (ctx->r25 != ctx->r4) {
        // 0x800830D0: nop
    
            goto L_80083104;
    }
    // 0x800830D0: nop

    // 0x800830D4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800830D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800830DC: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x800830E0: nop

    // 0x800830E4: bne         $t1, $at, L_80083104
    if (ctx->r9 != ctx->r1) {
        // 0x800830E8: nop
    
            goto L_80083104;
    }
    // 0x800830E8: nop

    // 0x800830EC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800830F0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800830F4: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x800830F8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800830FC: nop

    // 0x80083100: sh          $zero, 0xE($t4)
    MEM_H(0XE, ctx->r12) = 0;
L_80083104:
    // 0x80083104: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80083108: nop

    // 0x8008310C: lw          $t6, 0x44($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X44);
    // 0x80083110: nop

    // 0x80083114: bne         $t6, $zero, L_800830BC
    if (ctx->r14 != 0) {
        // 0x80083118: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800830BC;
    }
    // 0x80083118: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008311C: b           L_80083124
    // 0x80083120: nop

        goto L_80083124;
    // 0x80083120: nop

L_80083124:
    // 0x80083124: jr          $ra
    // 0x80083128: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80083128: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006B81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B81C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B820: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B824: nop

    // 0x8006B828: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B82C: nop

    // 0x8006B830: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006B834: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B838: jr          $ra
    // 0x8006B83C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B83C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B840: jr          $ra
    // 0x8006B844: nop

    return;
    // 0x8006B844: nop

    // 0x8006B848: jr          $ra
    // 0x8006B84C: nop

    return;
    // 0x8006B84C: nop

;}
RECOMP_FUNC void func_80073788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073788: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007378C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073790: nop

    // 0x80073794: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073798: nop

    // 0x8007379C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800737A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800737A4: jr          $ra
    // 0x800737A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800737A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800737AC: jr          $ra
    // 0x800737B0: nop

    return;
    // 0x800737B0: nop

    // 0x800737B4: jr          $ra
    // 0x800737B8: nop

    return;
    // 0x800737B8: nop

;}
RECOMP_FUNC void alResampleParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0D20: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800D0D24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D0D28: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800D0D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0D30: beq         $at, $zero, L_800D0DE0
    if (ctx->r1 == 0) {
        // 0x800D0D34: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800D0DE0;
    }
    // 0x800D0D34: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D0D38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D0D3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0D40: addu        $at, $at, $t6
    gpr jr_addend_800D0D48 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D0D44: lw          $t6, 0x2D0($at)
    ctx->r14 = ADD32(ctx->r1, 0X2D0);
    // 0x800D0D48: jr          $t6
    // 0x800D0D4C: nop

    switch (jr_addend_800D0D48 >> 2) {
        case 0: goto L_800D0D50; break;
        case 1: goto L_800D0DE0; break;
        case 2: goto L_800D0DE0; break;
        case 3: goto L_800D0D58; break;
        case 4: goto L_800D0DE0; break;
        case 5: goto L_800D0DE0; break;
        case 6: goto L_800D0DC4; break;
        case 7: goto L_800D0DD4; break;
        case 8: goto L_800D0D94; break;
        default: switch_error(__func__, 0x800D0D48, 0x800F02D0);
    }
    // 0x800D0D4C: nop

L_800D0D50:
    // 0x800D0D50: b           L_800D0DF8
    // 0x800D0D54: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800D0DF8;
    // 0x800D0D54: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_800D0D58:
    // 0x800D0D58: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800D0D5C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D0D60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D0D64: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x800D0D68: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800D0D6C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800D0D70: beq         $a0, $zero, L_800D0DF8
    if (ctx->r4 == 0) {
        // 0x800D0D74: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_800D0DF8;
    }
    // 0x800D0D74: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x800D0D78: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D0D7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800D0D80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0D84: jalr        $t9
    // 0x800D0D88: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0D88: nop

    after_0:
    // 0x800D0D8C: b           L_800D0DFC
    // 0x800D0D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D0DFC;
    // 0x800D0D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0D94:
    // 0x800D0D94: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800D0D98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D0D9C: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x800D0DA0: beql        $a0, $zero, L_800D0DFC
    if (ctx->r4 == 0) {
        // 0x800D0DA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0DFC;
    }
    goto skip_0;
    // 0x800D0DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D0DA8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D0DAC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D0DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0DB4: jalr        $t9
    // 0x800D0DB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D0DB8: nop

    after_1:
    // 0x800D0DBC: b           L_800D0DFC
    // 0x800D0DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D0DFC;
    // 0x800D0DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0DC4:
    // 0x800D0DC4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800D0DC8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D0DCC: b           L_800D0DF8
    // 0x800D0DD0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_800D0DF8;
    // 0x800D0DD0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_800D0DD4:
    // 0x800D0DD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D0DD8: b           L_800D0DF8
    // 0x800D0DDC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_800D0DF8;
    // 0x800D0DDC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_800D0DE0:
    // 0x800D0DE0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800D0DE4: beql        $a0, $zero, L_800D0DFC
    if (ctx->r4 == 0) {
        // 0x800D0DE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0DFC;
    }
    goto skip_1;
    // 0x800D0DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800D0DEC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D0DF0: jalr        $t9
    // 0x800D0DF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D0DF4: nop

    after_2:
L_800D0DF8:
    // 0x800D0DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0DFC:
    // 0x800D0DFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D0E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D0E04: jr          $ra
    // 0x800D0E08: nop

    return;
    // 0x800D0E08: nop

;}
RECOMP_FUNC void AudioGeneral_BGMFadeOut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021F28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021F2C: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x80021F30: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80021F34: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80021F38: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80021F3C: bne         $t6, $zero, L_80021F48
    if (ctx->r14 != 0) {
        // 0x80021F40: nop
    
            goto L_80021F48;
    }
    // 0x80021F40: nop

    // 0x80021F44: break       7
    do_break(2147622724);
L_80021F48:
    // 0x80021F48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021F4C: bne         $t6, $at, L_80021F60
    if (ctx->r14 != ctx->r1) {
        // 0x80021F50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021F60;
    }
    // 0x80021F50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021F54: bne         $t7, $at, L_80021F60
    if (ctx->r15 != ctx->r1) {
        // 0x80021F58: nop
    
            goto L_80021F60;
    }
    // 0x80021F58: nop

    // 0x80021F5C: break       6
    do_break(2147622748);
L_80021F60:
    // 0x80021F60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80021F64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80021F68: mflo        $a1
    ctx->r5 = lo;
    // 0x80021F6C: jal         0x800BB52C
    // 0x80021F70: nop

    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80021F70: nop

    after_0:
    // 0x80021F74: b           L_80021F7C
    // 0x80021F78: nop

        goto L_80021F7C;
    // 0x80021F78: nop

L_80021F7C:
    // 0x80021F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021F84: jr          $ra
    // 0x80021F88: nop

    return;
    // 0x80021F88: nop

;}
RECOMP_FUNC void func_80077ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077AC4: jal         0x80061348
    // 0x80077AC8: addiu       $a0, $zero, 0x5C7
    ctx->r4 = ADD32(0, 0X5C7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077AC8: addiu       $a0, $zero, 0x5C7
    ctx->r4 = ADD32(0, 0X5C7);
    after_0:
    // 0x80077ACC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077AD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077AD4: b           L_80077AE4
    // 0x80077AD8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80077AE4;
    // 0x80077AD8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077ADC: b           L_80077AE4
    // 0x80077AE0: nop

        goto L_80077AE4;
    // 0x80077AE0: nop

L_80077AE4:
    // 0x80077AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077AEC: jr          $ra
    // 0x80077AF0: nop

    return;
    // 0x80077AF0: nop

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
RECOMP_FUNC void func_8007495C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007495C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074964: jal         0x80061348
    // 0x80074968: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074968: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x8007496C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074970: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074974: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074978: beq         $v0, $zero, L_800749CC
    if (ctx->r2 == 0) {
        // 0x8007497C: nop
    
            goto L_800749CC;
    }
    // 0x8007497C: nop

    // 0x80074980: jal         0x80061348
    // 0x80074984: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074984: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074988: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007498C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074990: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074994: beq         $v0, $zero, L_800749CC
    if (ctx->r2 == 0) {
        // 0x80074998: nop
    
            goto L_800749CC;
    }
    // 0x80074998: nop

    // 0x8007499C: jal         0x80061348
    // 0x800749A0: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800749A0: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x800749A4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800749A8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800749AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800749B0: beq         $v0, $zero, L_800749CC
    if (ctx->r2 == 0) {
        // 0x800749B4: nop
    
            goto L_800749CC;
    }
    // 0x800749B4: nop

    // 0x800749B8: jal         0x80061348
    // 0x800749BC: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800749BC: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x800749C0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800749C4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800749C8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800749CC:
    // 0x800749CC: b           L_800749DC
    // 0x800749D0: nop

        goto L_800749DC;
    // 0x800749D0: nop

    // 0x800749D4: b           L_800749DC
    // 0x800749D8: nop

        goto L_800749DC;
    // 0x800749D8: nop

L_800749DC:
    // 0x800749DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800749E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800749E4: jr          $ra
    // 0x800749E8: nop

    return;
    // 0x800749E8: nop

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
RECOMP_FUNC void func_8007915C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007915C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80079160: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80079164: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079168: nop

    // 0x8007916C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80079170: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80079174: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80079178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007917C: bne         $t6, $at, L_800792C0
    if (ctx->r14 != ctx->r1) {
        // 0x80079180: nop
    
            goto L_800792C0;
    }
    // 0x80079180: nop

    // 0x80079184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80079188: nop

    // 0x8007918C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80079190: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80079194: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80079198: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007919C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800791A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800791A4: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x800791A8: nop

    // 0x800791AC: bc1f        L_80079240
    if (!c1cs) {
        // 0x800791B0: nop
    
            goto L_80079240;
    }
    // 0x800791B0: nop

    // 0x800791B4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800791B8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800791BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800791C0: nop

    // 0x800791C4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x800791C8: nop

    // 0x800791CC: bc1f        L_80079240
    if (!c1cs) {
        // 0x800791D0: nop
    
            goto L_80079240;
    }
    // 0x800791D0: nop

    // 0x800791D4: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800791D8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800791DC: lw          $t7, 0xA4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XA4);
    // 0x800791E0: lw          $t1, 0xA4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XA4);
    // 0x800791E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800791E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800791EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800791F0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800791F4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800791F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800791FC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80079200: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80079204: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80079208: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8007920C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80079210: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80079214: lwc1        $f6, 0x20($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80079218: lwc1        $f4, 0x28($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8007921C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80079220: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80079224: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80079228: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007922C: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80079230: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x80079234: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80079238: b           L_8007924C
    // 0x8007923C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
        goto L_8007924C;
    // 0x8007923C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
L_80079240:
    // 0x80079240: lwc1        $f16, 0x14($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80079244: nop

    // 0x80079248: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
L_8007924C:
    // 0x8007924C: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80079250: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80079254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079258: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007925C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80079260: nop

    // 0x80079264: bc1f        L_80079294
    if (!c1cs) {
        // 0x80079268: nop
    
            goto L_80079294;
    }
    // 0x80079268: nop

    // 0x8007926C: lw          $t5, 0xA4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XA4);
    // 0x80079270: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80079274: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80079278: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007927C: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80079280: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80079284: nop

    // 0x80079288: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007928C: b           L_800792B8
    // 0x80079290: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
        goto L_800792B8;
    // 0x80079290: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
L_80079294:
    // 0x80079294: lw          $t9, 0xA4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA4);
    // 0x80079298: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8007929C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800792A0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800792A4: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x800792A8: lwc1        $f18, 0x28($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X28);
    // 0x800792AC: nop

    // 0x800792B0: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800792B4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_800792B8:
    // 0x800792B8: b           L_800793FC
    // 0x800792BC: nop

        goto L_800793FC;
    // 0x800792BC: nop

L_800792C0:
    // 0x800792C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800792C4: nop

    // 0x800792C8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800792CC: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800792D0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800792D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800792D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800792DC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800792E0: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x800792E4: nop

    // 0x800792E8: bc1f        L_8007937C
    if (!c1cs) {
        // 0x800792EC: nop
    
            goto L_8007937C;
    }
    // 0x800792EC: nop

    // 0x800792F0: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800792F4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800792F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800792FC: nop

    // 0x80079300: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80079304: nop

    // 0x80079308: bc1f        L_8007937C
    if (!c1cs) {
        // 0x8007930C: nop
    
            goto L_8007937C;
    }
    // 0x8007930C: nop

    // 0x80079310: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80079314: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80079318: lw          $t3, 0xA4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XA4);
    // 0x8007931C: lw          $t7, 0xA4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XA4);
    // 0x80079320: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80079324: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80079328: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007932C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80079330: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80079334: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80079338: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007933C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80079340: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x80079344: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80079348: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007934C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80079350: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80079354: lwc1        $f4, 0x2C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X2C);
    // 0x80079358: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007935C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80079360: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80079364: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80079368: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8007936C: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x80079370: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80079374: b           L_80079388
    // 0x80079378: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
        goto L_80079388;
    // 0x80079378: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
L_8007937C:
    // 0x8007937C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80079380: nop

    // 0x80079384: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
L_80079388:
    // 0x80079388: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8007938C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80079390: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079394: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80079398: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8007939C: nop

    // 0x800793A0: bc1f        L_800793D0
    if (!c1cs) {
        // 0x800793A4: nop
    
            goto L_800793D0;
    }
    // 0x800793A4: nop

    // 0x800793A8: lw          $t1, 0xA4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XA4);
    // 0x800793AC: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800793B0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800793B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800793B8: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x800793BC: lwc1        $f8, 0x24($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800793C0: nop

    // 0x800793C4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800793C8: b           L_800793F4
    // 0x800793CC: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
        goto L_800793F4;
    // 0x800793CC: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_800793D0:
    // 0x800793D0: lw          $t5, 0xA4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XA4);
    // 0x800793D4: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800793D8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800793DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800793E0: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800793E4: lwc1        $f18, 0x2C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x800793E8: nop

    // 0x800793EC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800793F0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_800793F4:
    // 0x800793F4: b           L_800793FC
    // 0x800793F8: nop

        goto L_800793FC;
    // 0x800793F8: nop

L_800793FC:
    // 0x800793FC: jr          $ra
    // 0x80079400: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80079400: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_8000E9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E9FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000EA00: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000EA04: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000EA08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000EA0C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000EA10: nop

    // 0x8000EA14: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000EA18: nop

    // 0x8000EA1C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8000EA20: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EA24: nop

    // 0x8000EA28: lhu         $s0, 0x62($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X62);
    // 0x8000EA2C: nop

    // 0x8000EA30: slti        $at, $s0, 0x2001
    ctx->r1 = SIGNED(ctx->r16) < 0X2001 ? 1 : 0;
    // 0x8000EA34: bne         $at, $zero, L_8000EA70
    if (ctx->r1 != 0) {
        // 0x8000EA38: nop
    
            goto L_8000EA70;
    }
    // 0x8000EA38: nop

    // 0x8000EA3C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000EA40: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8000EA44: addu        $t9, $s0, $at
    ctx->r25 = ADD32(ctx->r16, ctx->r1);
    // 0x8000EA48: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x8000EA4C: beq         $at, $zero, L_8000F460
    if (ctx->r1 == 0) {
        // 0x8000EA50: nop
    
            goto L_8000F460;
    }
    // 0x8000EA50: nop

    // 0x8000EA54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000EA58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000EA5C: addu        $at, $at, $t9
    gpr jr_addend_8000EA68 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000EA60: lw          $t9, -0x2BE0($at)
    ctx->r25 = ADD32(ctx->r1, -0X2BE0);
    // 0x8000EA64: nop

    // 0x8000EA68: jr          $t9
    // 0x8000EA6C: nop

    switch (jr_addend_8000EA68 >> 2) {
        case 0: goto L_8000EA84; break;
        case 1: goto L_8000EB0C; break;
        case 2: goto L_8000EBAC; break;
        case 3: goto L_8000EC98; break;
        case 4: goto L_8000F460; break;
        case 5: goto L_8000F460; break;
        case 6: goto L_8000F460; break;
        case 7: goto L_8000EE6C; break;
        case 8: goto L_8000EF34; break;
        case 9: goto L_8000ED84; break;
        case 10: goto L_8000F104; break;
        case 11: goto L_8000F1D8; break;
        case 12: goto L_8000F2AC; break;
        case 13: goto L_8000F380; break;
        case 14: goto L_8000EBAC; break;
        case 15: goto L_8000EC98; break;
        case 16: goto L_8000EF34; break;
        default: switch_error(__func__, 0x8000EA68, 0x800ED420);
    }
    // 0x8000EA6C: nop

L_8000EA70:
    // 0x8000EA70: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8000EA74: beq         $s0, $at, L_8000EEE8
    if (ctx->r16 == ctx->r1) {
        // 0x8000EA78: nop
    
            goto L_8000EEE8;
    }
    // 0x8000EA78: nop

    // 0x8000EA7C: b           L_8000F460
    // 0x8000EA80: nop

        goto L_8000F460;
    // 0x8000EA80: nop

L_8000EA84:
    // 0x8000EA84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EA88: nop

    // 0x8000EA8C: lh          $t1, 0x66($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X66);
    // 0x8000EA90: lwc1        $f4, 0x78($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8000EA94: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8000EA98: nop

    // 0x8000EA9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EAA0: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8000EAA4: nop

    // 0x8000EAA8: bc1f        L_8000EAC8
    if (!c1cs) {
        // 0x8000EAAC: nop
    
            goto L_8000EAC8;
    }
    // 0x8000EAAC: nop

    // 0x8000EAB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EAB4: jal         0x8000F4B0
    // 0x8000EAB8: nop

    func_8000F4B0(rdram, ctx);
        goto after_0;
    // 0x8000EAB8: nop

    after_0:
    // 0x8000EABC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EAC0: b           L_8000EB04
    // 0x8000EAC4: sh          $zero, 0x62($t2)
    MEM_H(0X62, ctx->r10) = 0;
        goto L_8000EB04;
    // 0x8000EAC4: sh          $zero, 0x62($t2)
    MEM_H(0X62, ctx->r10) = 0;
L_8000EAC8:
    // 0x8000EAC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000EACC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000EAD0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000EAD4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8000EAD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000EADC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8000EAE0: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8000EAE4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EAE8: nop

    // 0x8000EAEC: lwc1        $f4, 0x78($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X78);
    // 0x8000EAF0: nop

    // 0x8000EAF4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8000EAF8: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8000EAFC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8000EB00: swc1        $f16, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->f16.u32l;
L_8000EB04:
    // 0x8000EB04: b           L_8000F46C
    // 0x8000EB08: nop

        goto L_8000F46C;
    // 0x8000EB08: nop

L_8000EB0C:
    // 0x8000EB0C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB10: nop

    // 0x8000EB14: lhu         $t5, 0x60($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X60);
    // 0x8000EB18: nop

    // 0x8000EB1C: andi        $t6, $t5, 0xE
    ctx->r14 = ctx->r13 & 0XE;
    // 0x8000EB20: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000EB24: sh          $t7, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r15;
    // 0x8000EB28: lhu         $t8, 0x36($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X36);
    // 0x8000EB2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000EB30: beq         $t8, $at, L_8000EB50
    if (ctx->r24 == ctx->r1) {
        // 0x8000EB34: nop
    
            goto L_8000EB50;
    }
    // 0x8000EB34: nop

    // 0x8000EB38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000EB3C: beq         $t8, $at, L_8000EB50
    if (ctx->r24 == ctx->r1) {
        // 0x8000EB40: nop
    
            goto L_8000EB50;
    }
    // 0x8000EB40: nop

    // 0x8000EB44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000EB48: bne         $t8, $at, L_8000EB70
    if (ctx->r24 != ctx->r1) {
        // 0x8000EB4C: nop
    
            goto L_8000EB70;
    }
    // 0x8000EB4C: nop

L_8000EB50:
    // 0x8000EB50: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EB54: jal         0x8000F4B0
    // 0x8000EB58: nop

    func_8000F4B0(rdram, ctx);
        goto after_1;
    // 0x8000EB58: nop

    after_1:
    // 0x8000EB5C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB60: nop

    // 0x8000EB64: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
    // 0x8000EB68: b           L_8000F46C
    // 0x8000EB6C: nop

        goto L_8000F46C;
    // 0x8000EB6C: nop

L_8000EB70:
    // 0x8000EB70: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB74: nop

    // 0x8000EB78: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000EB7C: nop

    // 0x8000EB80: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000EB84: bne         $t2, $zero, L_8000EBA4
    if (ctx->r10 != 0) {
        // 0x8000EB88: nop
    
            goto L_8000EBA4;
    }
    // 0x8000EB88: nop

    // 0x8000EB8C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EB90: jal         0x8000F4B0
    // 0x8000EB94: nop

    func_8000F4B0(rdram, ctx);
        goto after_2;
    // 0x8000EB94: nop

    after_2:
    // 0x8000EB98: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB9C: nop

    // 0x8000EBA0: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
L_8000EBA4:
    // 0x8000EBA4: b           L_8000F46C
    // 0x8000EBA8: nop

        goto L_8000F46C;
    // 0x8000EBA8: nop

L_8000EBAC:
    // 0x8000EBAC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EBB0: nop

    // 0x8000EBB4: lh          $t5, 0x66($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X66);
    // 0x8000EBB8: nop

    // 0x8000EBBC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8000EBC0: nop

    // 0x8000EBC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000EBC8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8000EBCC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EBD0: nop

    // 0x8000EBD4: lhu         $t7, 0x68($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X68);
    // 0x8000EBD8: nop

    // 0x8000EBDC: bne         $t7, $zero, L_8000EC1C
    if (ctx->r15 != 0) {
        // 0x8000EBE0: nop
    
            goto L_8000EC1C;
    }
    // 0x8000EBE0: nop

    // 0x8000EBE4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EBE8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EBEC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000EBF0: nop

    // 0x8000EBF4: lwc1        $f8, 0xCC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8000EBF8: nop

    // 0x8000EBFC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8000EC00: nop

    // 0x8000EC04: bc1f        L_8000EC14
    if (!c1cs) {
        // 0x8000EC08: nop
    
            goto L_8000EC14;
    }
    // 0x8000EC08: nop

    // 0x8000EC0C: b           L_8000F46C
    // 0x8000EC10: nop

        goto L_8000F46C;
    // 0x8000EC10: nop

L_8000EC14:
    // 0x8000EC14: b           L_8000EC4C
    // 0x8000EC18: nop

        goto L_8000EC4C;
    // 0x8000EC18: nop

L_8000EC1C:
    // 0x8000EC1C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC20: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EC24: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000EC28: nop

    // 0x8000EC2C: lwc1        $f10, 0xCC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8000EC30: nop

    // 0x8000EC34: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8000EC38: nop

    // 0x8000EC3C: bc1f        L_8000EC4C
    if (!c1cs) {
        // 0x8000EC40: nop
    
            goto L_8000EC4C;
    }
    // 0x8000EC40: nop

    // 0x8000EC44: b           L_8000F46C
    // 0x8000EC48: nop

        goto L_8000F46C;
    // 0x8000EC48: nop

L_8000EC4C:
    // 0x8000EC4C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC50: ori         $at, $zero, 0xE002
    ctx->r1 = 0 | 0XE002;
    // 0x8000EC54: lhu         $t3, 0x62($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X62);
    // 0x8000EC58: nop

    // 0x8000EC5C: bne         $t3, $at, L_8000EC78
    if (ctx->r11 != ctx->r1) {
        // 0x8000EC60: nop
    
            goto L_8000EC78;
    }
    // 0x8000EC60: nop

    // 0x8000EC64: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC68: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EC6C: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8000EC70: nop

    // 0x8000EC74: swc1        $f18, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f18.u32l;
L_8000EC78:
    // 0x8000EC78: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EC7C: jal         0x8000F4B0
    // 0x8000EC80: nop

    func_8000F4B0(rdram, ctx);
        goto after_3;
    // 0x8000EC80: nop

    after_3:
    // 0x8000EC84: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC88: nop

    // 0x8000EC8C: sh          $zero, 0x62($t6)
    MEM_H(0X62, ctx->r14) = 0;
    // 0x8000EC90: b           L_8000F46C
    // 0x8000EC94: nop

        goto L_8000F46C;
    // 0x8000EC94: nop

L_8000EC98:
    // 0x8000EC98: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC9C: nop

    // 0x8000ECA0: lh          $t8, 0x66($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X66);
    // 0x8000ECA4: nop

    // 0x8000ECA8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000ECAC: nop

    // 0x8000ECB0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000ECB4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8000ECB8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ECBC: nop

    // 0x8000ECC0: lhu         $t0, 0x68($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X68);
    // 0x8000ECC4: nop

    // 0x8000ECC8: bne         $t0, $zero, L_8000ED08
    if (ctx->r8 != 0) {
        // 0x8000ECCC: nop
    
            goto L_8000ED08;
    }
    // 0x8000ECCC: nop

    // 0x8000ECD0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ECD4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000ECD8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000ECDC: nop

    // 0x8000ECE0: lwc1        $f6, 0xD0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8000ECE4: nop

    // 0x8000ECE8: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8000ECEC: nop

    // 0x8000ECF0: bc1f        L_8000ED00
    if (!c1cs) {
        // 0x8000ECF4: nop
    
            goto L_8000ED00;
    }
    // 0x8000ECF4: nop

    // 0x8000ECF8: b           L_8000F46C
    // 0x8000ECFC: nop

        goto L_8000F46C;
    // 0x8000ECFC: nop

L_8000ED00:
    // 0x8000ED00: b           L_8000ED38
    // 0x8000ED04: nop

        goto L_8000ED38;
    // 0x8000ED04: nop

L_8000ED08:
    // 0x8000ED08: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED0C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000ED10: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8000ED14: nop

    // 0x8000ED18: lwc1        $f16, 0xD0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8000ED1C: nop

    // 0x8000ED20: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8000ED24: nop

    // 0x8000ED28: bc1f        L_8000ED38
    if (!c1cs) {
        // 0x8000ED2C: nop
    
            goto L_8000ED38;
    }
    // 0x8000ED2C: nop

    // 0x8000ED30: b           L_8000F46C
    // 0x8000ED34: nop

        goto L_8000F46C;
    // 0x8000ED34: nop

L_8000ED38:
    // 0x8000ED38: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED3C: ori         $at, $zero, 0xE003
    ctx->r1 = 0 | 0XE003;
    // 0x8000ED40: lhu         $t6, 0x62($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X62);
    // 0x8000ED44: nop

    // 0x8000ED48: bne         $t6, $at, L_8000ED64
    if (ctx->r14 != ctx->r1) {
        // 0x8000ED4C: nop
    
            goto L_8000ED64;
    }
    // 0x8000ED4C: nop

    // 0x8000ED50: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED54: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000ED58: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000ED5C: nop

    // 0x8000ED60: swc1        $f4, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f4.u32l;
L_8000ED64:
    // 0x8000ED64: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000ED68: jal         0x8000F4B0
    // 0x8000ED6C: nop

    func_8000F4B0(rdram, ctx);
        goto after_4;
    // 0x8000ED6C: nop

    after_4:
    // 0x8000ED70: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED74: nop

    // 0x8000ED78: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
    // 0x8000ED7C: b           L_8000F46C
    // 0x8000ED80: nop

        goto L_8000F46C;
    // 0x8000ED80: nop

L_8000ED84:
    // 0x8000ED84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED88: nop

    // 0x8000ED8C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000ED90: nop

    // 0x8000ED94: andi        $t2, $t1, 0x40
    ctx->r10 = ctx->r9 & 0X40;
    // 0x8000ED98: bne         $t2, $zero, L_8000EDC0
    if (ctx->r10 != 0) {
        // 0x8000ED9C: nop
    
            goto L_8000EDC0;
    }
    // 0x8000ED9C: nop

    // 0x8000EDA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EDA4: jal         0x8000F4B0
    // 0x8000EDA8: nop

    func_8000F4B0(rdram, ctx);
        goto after_5;
    // 0x8000EDA8: nop

    after_5:
    // 0x8000EDAC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDB0: nop

    // 0x8000EDB4: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
    // 0x8000EDB8: b           L_8000F46C
    // 0x8000EDBC: nop

        goto L_8000F46C;
    // 0x8000EDBC: nop

L_8000EDC0:
    // 0x8000EDC0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDC4: nop

    // 0x8000EDC8: lhu         $t5, 0x66($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X66);
    // 0x8000EDCC: nop

    // 0x8000EDD0: sh          $t5, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r13;
    // 0x8000EDD4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDD8: nop

    // 0x8000EDDC: lhu         $t7, 0x68($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X68);
    // 0x8000EDE0: nop

    // 0x8000EDE4: bne         $t7, $zero, L_8000EE20
    if (ctx->r15 != 0) {
        // 0x8000EDE8: nop
    
            goto L_8000EE20;
    }
    // 0x8000EDE8: nop

    // 0x8000EDEC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDF0: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
    // 0x8000EDF4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000EDF8: nop

    // 0x8000EDFC: lhu         $t0, 0x11E($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X11E);
    // 0x8000EE00: nop

    // 0x8000EE04: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000EE08: beq         $at, $zero, L_8000EE18
    if (ctx->r1 == 0) {
        // 0x8000EE0C: nop
    
            goto L_8000EE18;
    }
    // 0x8000EE0C: nop

    // 0x8000EE10: b           L_8000F46C
    // 0x8000EE14: nop

        goto L_8000F46C;
    // 0x8000EE14: nop

L_8000EE18:
    // 0x8000EE18: b           L_8000EE4C
    // 0x8000EE1C: nop

        goto L_8000EE4C;
    // 0x8000EE1C: nop

L_8000EE20:
    // 0x8000EE20: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EE24: lhu         $t5, 0x2E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2E);
    // 0x8000EE28: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8000EE2C: nop

    // 0x8000EE30: lhu         $t4, 0x11E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X11E);
    // 0x8000EE34: nop

    // 0x8000EE38: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000EE3C: beq         $at, $zero, L_8000EE4C
    if (ctx->r1 == 0) {
        // 0x8000EE40: nop
    
            goto L_8000EE4C;
    }
    // 0x8000EE40: nop

    // 0x8000EE44: b           L_8000F46C
    // 0x8000EE48: nop

        goto L_8000F46C;
    // 0x8000EE48: nop

L_8000EE4C:
    // 0x8000EE4C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EE50: jal         0x8000F4B0
    // 0x8000EE54: nop

    func_8000F4B0(rdram, ctx);
        goto after_6;
    // 0x8000EE54: nop

    after_6:
    // 0x8000EE58: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EE5C: nop

    // 0x8000EE60: sh          $zero, 0x62($t6)
    MEM_H(0X62, ctx->r14) = 0;
    // 0x8000EE64: b           L_8000F46C
    // 0x8000EE68: nop

        goto L_8000F46C;
    // 0x8000EE68: nop

L_8000EE6C:
    // 0x8000EE6C: jal         0x80031AC8
    // 0x8000EE70: nop

    func_80031AC8(rdram, ctx);
        goto after_7;
    // 0x8000EE70: nop

    after_7:
    // 0x8000EE74: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000EE78: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EE7C: nop

    // 0x8000EE80: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000EE84: nop

    // 0x8000EE88: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8000EE8C: beq         $t9, $zero, L_8000EEB8
    if (ctx->r25 == 0) {
        // 0x8000EE90: nop
    
            goto L_8000EEB8;
    }
    // 0x8000EE90: nop

    // 0x8000EE94: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000EE98: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000EE9C: bne         $t0, $at, L_8000EEB8
    if (ctx->r8 != ctx->r1) {
        // 0x8000EEA0: nop
    
            goto L_8000EEB8;
    }
    // 0x8000EEA0: nop

    // 0x8000EEA4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EEA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000EEAC: addiu       $a0, $t1, 0xC
    ctx->r4 = ADD32(ctx->r9, 0XC);
    // 0x8000EEB0: jal         0x800B2CBC
    // 0x8000EEB4: addiu       $a1, $t1, 0x10
    ctx->r5 = ADD32(ctx->r9, 0X10);
    func_800B2CBC(rdram, ctx);
        goto after_8;
    // 0x8000EEB4: addiu       $a1, $t1, 0x10
    ctx->r5 = ADD32(ctx->r9, 0X10);
    after_8:
L_8000EEB8:
    // 0x8000EEB8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000EEBC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000EEC0: bne         $t2, $at, L_8000EEE0
    if (ctx->r10 != ctx->r1) {
        // 0x8000EEC4: nop
    
            goto L_8000EEE0;
    }
    // 0x8000EEC4: nop

    // 0x8000EEC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EECC: jal         0x8000F4B0
    // 0x8000EED0: nop

    func_8000F4B0(rdram, ctx);
        goto after_9;
    // 0x8000EED0: nop

    after_9:
    // 0x8000EED4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EED8: nop

    // 0x8000EEDC: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
L_8000EEE0:
    // 0x8000EEE0: b           L_8000F46C
    // 0x8000EEE4: nop

        goto L_8000F46C;
    // 0x8000EEE4: nop

L_8000EEE8:
    // 0x8000EEE8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EEEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000EEF0: jal         0x800B334C
    // 0x8000EEF4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800B334C(rdram, ctx);
        goto after_10;
    // 0x8000EEF4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_10:
    // 0x8000EEF8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EEFC: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x8000EF00: lhu         $t5, 0x66($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X66);
    // 0x8000EF04: nop

    // 0x8000EF08: and         $t6, $t5, $s1
    ctx->r14 = ctx->r13 & ctx->r17;
    // 0x8000EF0C: beq         $t6, $zero, L_8000EF2C
    if (ctx->r14 == 0) {
        // 0x8000EF10: nop
    
            goto L_8000EF2C;
    }
    // 0x8000EF10: nop

    // 0x8000EF14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EF18: jal         0x8000F4B0
    // 0x8000EF1C: nop

    func_8000F4B0(rdram, ctx);
        goto after_11;
    // 0x8000EF1C: nop

    after_11:
    // 0x8000EF20: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF24: nop

    // 0x8000EF28: sh          $zero, 0x62($t7)
    MEM_H(0X62, ctx->r15) = 0;
L_8000EF2C:
    // 0x8000EF2C: b           L_8000F46C
    // 0x8000EF30: nop

        goto L_8000F46C;
    // 0x8000EF30: nop

L_8000EF34:
    // 0x8000EF34: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000EF38: nop

    // 0x8000EF3C: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x8000EF40: nop

    // 0x8000EF44: slti        $at, $t9, 0x4000
    ctx->r1 = SIGNED(ctx->r25) < 0X4000 ? 1 : 0;
    // 0x8000EF48: bne         $at, $zero, L_8000EF60
    if (ctx->r1 != 0) {
        // 0x8000EF4C: nop
    
            goto L_8000EF60;
    }
    // 0x8000EF4C: nop

    // 0x8000EF50: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000EF54: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000EF58: bne         $at, $zero, L_8000F030
    if (ctx->r1 != 0) {
        // 0x8000EF5C: nop
    
            goto L_8000F030;
    }
    // 0x8000EF5C: nop

L_8000EF60:
    // 0x8000EF60: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF64: nop

    // 0x8000EF68: lh          $t1, 0x66($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X66);
    // 0x8000EF6C: nop

    // 0x8000EF70: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8000EF74: nop

    // 0x8000EF78: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EF7C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8000EF80: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF84: nop

    // 0x8000EF88: lhu         $t3, 0x68($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X68);
    // 0x8000EF8C: nop

    // 0x8000EF90: bne         $t3, $zero, L_8000EFC8
    if (ctx->r11 != 0) {
        // 0x8000EF94: nop
    
            goto L_8000EFC8;
    }
    // 0x8000EF94: nop

    // 0x8000EF98: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF9C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EFA0: lwc1        $f10, 0x14($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8000EFA4: nop

    // 0x8000EFA8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8000EFAC: nop

    // 0x8000EFB0: bc1f        L_8000EFC0
    if (!c1cs) {
        // 0x8000EFB4: nop
    
            goto L_8000EFC0;
    }
    // 0x8000EFB4: nop

    // 0x8000EFB8: b           L_8000F46C
    // 0x8000EFBC: nop

        goto L_8000F46C;
    // 0x8000EFBC: nop

L_8000EFC0:
    // 0x8000EFC0: b           L_8000EFF0
    // 0x8000EFC4: nop

        goto L_8000EFF0;
    // 0x8000EFC4: nop

L_8000EFC8:
    // 0x8000EFC8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EFCC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EFD0: lwc1        $f18, 0x14($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8000EFD4: nop

    // 0x8000EFD8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8000EFDC: nop

    // 0x8000EFE0: bc1f        L_8000EFF0
    if (!c1cs) {
        // 0x8000EFE4: nop
    
            goto L_8000EFF0;
    }
    // 0x8000EFE4: nop

    // 0x8000EFE8: b           L_8000F46C
    // 0x8000EFEC: nop

        goto L_8000F46C;
    // 0x8000EFEC: nop

L_8000EFF0:
    // 0x8000EFF0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EFF4: ori         $at, $zero, 0xE008
    ctx->r1 = 0 | 0XE008;
    // 0x8000EFF8: lhu         $t7, 0x62($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X62);
    // 0x8000EFFC: nop

    // 0x8000F000: bne         $t7, $at, L_8000F018
    if (ctx->r15 != ctx->r1) {
        // 0x8000F004: nop
    
            goto L_8000F018;
    }
    // 0x8000F004: nop

    // 0x8000F008: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000F00C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F010: nop

    // 0x8000F014: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
L_8000F018:
    // 0x8000F018: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F01C: jal         0x8000F4B0
    // 0x8000F020: nop

    func_8000F4B0(rdram, ctx);
        goto after_12;
    // 0x8000F020: nop

    after_12:
    // 0x8000F024: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F028: b           L_8000F0FC
    // 0x8000F02C: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
        goto L_8000F0FC;
    // 0x8000F02C: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
L_8000F030:
    // 0x8000F030: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F034: nop

    // 0x8000F038: lh          $t1, 0x66($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X66);
    // 0x8000F03C: nop

    // 0x8000F040: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8000F044: nop

    // 0x8000F048: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F04C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8000F050: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F054: nop

    // 0x8000F058: lhu         $t3, 0x68($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X68);
    // 0x8000F05C: nop

    // 0x8000F060: bne         $t3, $zero, L_8000F0A0
    if (ctx->r11 != 0) {
        // 0x8000F064: nop
    
            goto L_8000F0A0;
    }
    // 0x8000F064: nop

    // 0x8000F068: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F06C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F070: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8000F074: nop

    // 0x8000F078: lwc1        $f16, 0xD4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XD4);
    // 0x8000F07C: nop

    // 0x8000F080: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8000F084: nop

    // 0x8000F088: bc1f        L_8000F098
    if (!c1cs) {
        // 0x8000F08C: nop
    
            goto L_8000F098;
    }
    // 0x8000F08C: nop

    // 0x8000F090: b           L_8000F46C
    // 0x8000F094: nop

        goto L_8000F46C;
    // 0x8000F094: nop

L_8000F098:
    // 0x8000F098: b           L_8000F0D0
    // 0x8000F09C: nop

        goto L_8000F0D0;
    // 0x8000F09C: nop

L_8000F0A0:
    // 0x8000F0A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F0A4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F0A8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8000F0AC: nop

    // 0x8000F0B0: lwc1        $f4, 0xD4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XD4);
    // 0x8000F0B4: nop

    // 0x8000F0B8: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8000F0BC: nop

    // 0x8000F0C0: bc1f        L_8000F0D0
    if (!c1cs) {
        // 0x8000F0C4: nop
    
            goto L_8000F0D0;
    }
    // 0x8000F0C4: nop

    // 0x8000F0C8: b           L_8000F46C
    // 0x8000F0CC: nop

        goto L_8000F46C;
    // 0x8000F0CC: nop

L_8000F0D0:
    // 0x8000F0D0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F0D4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F0D8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000F0DC: nop

    // 0x8000F0E0: swc1        $f6, 0xD4($t9)
    MEM_W(0XD4, ctx->r25) = ctx->f6.u32l;
    // 0x8000F0E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F0E8: jal         0x8000F4B0
    // 0x8000F0EC: nop

    func_8000F4B0(rdram, ctx);
        goto after_13;
    // 0x8000F0EC: nop

    after_13:
    // 0x8000F0F0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F0F4: nop

    // 0x8000F0F8: sh          $zero, 0x62($t0)
    MEM_H(0X62, ctx->r8) = 0;
L_8000F0FC:
    // 0x8000F0FC: b           L_8000F46C
    // 0x8000F100: nop

        goto L_8000F46C;
    // 0x8000F100: nop

L_8000F104:
    // 0x8000F104: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F108: nop

    // 0x8000F10C: lh          $t2, 0x66($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X66);
    // 0x8000F110: nop

    // 0x8000F114: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8000F118: nop

    // 0x8000F11C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000F120: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8000F124: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F128: nop

    // 0x8000F12C: lhu         $t4, 0x68($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X68);
    // 0x8000F130: nop

    // 0x8000F134: bne         $t4, $zero, L_8000F174
    if (ctx->r12 != 0) {
        // 0x8000F138: nop
    
            goto L_8000F174;
    }
    // 0x8000F138: nop

    // 0x8000F13C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F140: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F144: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8000F148: nop

    // 0x8000F14C: lwc1        $f18, 0xE8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8000F150: nop

    // 0x8000F154: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8000F158: nop

    // 0x8000F15C: bc1f        L_8000F16C
    if (!c1cs) {
        // 0x8000F160: nop
    
            goto L_8000F16C;
    }
    // 0x8000F160: nop

    // 0x8000F164: b           L_8000F46C
    // 0x8000F168: nop

        goto L_8000F46C;
    // 0x8000F168: nop

L_8000F16C:
    // 0x8000F16C: b           L_8000F1A4
    // 0x8000F170: nop

        goto L_8000F1A4;
    // 0x8000F170: nop

L_8000F174:
    // 0x8000F174: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F178: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F17C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000F180: nop

    // 0x8000F184: lwc1        $f8, 0xE8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8000F188: nop

    // 0x8000F18C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8000F190: nop

    // 0x8000F194: bc1f        L_8000F1A4
    if (!c1cs) {
        // 0x8000F198: nop
    
            goto L_8000F1A4;
    }
    // 0x8000F198: nop

    // 0x8000F19C: b           L_8000F46C
    // 0x8000F1A0: nop

        goto L_8000F46C;
    // 0x8000F1A0: nop

L_8000F1A4:
    // 0x8000F1A4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1A8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F1AC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8000F1B0: nop

    // 0x8000F1B4: swc1        $f10, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f10.u32l;
    // 0x8000F1B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F1BC: jal         0x8000F4B0
    // 0x8000F1C0: nop

    func_8000F4B0(rdram, ctx);
        goto after_14;
    // 0x8000F1C0: nop

    after_14:
    // 0x8000F1C4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1C8: nop

    // 0x8000F1CC: sh          $zero, 0x62($t1)
    MEM_H(0X62, ctx->r9) = 0;
    // 0x8000F1D0: b           L_8000F46C
    // 0x8000F1D4: nop

        goto L_8000F46C;
    // 0x8000F1D4: nop

L_8000F1D8:
    // 0x8000F1D8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1DC: nop

    // 0x8000F1E0: lh          $t3, 0x66($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X66);
    // 0x8000F1E4: nop

    // 0x8000F1E8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8000F1EC: nop

    // 0x8000F1F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000F1F4: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8000F1F8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1FC: nop

    // 0x8000F200: lhu         $t5, 0x68($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X68);
    // 0x8000F204: nop

    // 0x8000F208: bne         $t5, $zero, L_8000F248
    if (ctx->r13 != 0) {
        // 0x8000F20C: nop
    
            goto L_8000F248;
    }
    // 0x8000F20C: nop

    // 0x8000F210: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F214: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F218: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8000F21C: nop

    // 0x8000F220: lwc1        $f4, 0xEC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XEC);
    // 0x8000F224: nop

    // 0x8000F228: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8000F22C: nop

    // 0x8000F230: bc1f        L_8000F240
    if (!c1cs) {
        // 0x8000F234: nop
    
            goto L_8000F240;
    }
    // 0x8000F234: nop

    // 0x8000F238: b           L_8000F46C
    // 0x8000F23C: nop

        goto L_8000F46C;
    // 0x8000F23C: nop

L_8000F240:
    // 0x8000F240: b           L_8000F278
    // 0x8000F244: nop

        goto L_8000F278;
    // 0x8000F244: nop

L_8000F248:
    // 0x8000F248: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F24C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F250: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000F254: nop

    // 0x8000F258: lwc1        $f6, 0xEC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XEC);
    // 0x8000F25C: nop

    // 0x8000F260: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8000F264: nop

    // 0x8000F268: bc1f        L_8000F278
    if (!c1cs) {
        // 0x8000F26C: nop
    
            goto L_8000F278;
    }
    // 0x8000F26C: nop

    // 0x8000F270: b           L_8000F46C
    // 0x8000F274: nop

        goto L_8000F46C;
    // 0x8000F274: nop

L_8000F278:
    // 0x8000F278: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F27C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F280: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000F284: nop

    // 0x8000F288: swc1        $f16, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f16.u32l;
    // 0x8000F28C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F290: jal         0x8000F4B0
    // 0x8000F294: nop

    func_8000F4B0(rdram, ctx);
        goto after_15;
    // 0x8000F294: nop

    after_15:
    // 0x8000F298: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F29C: nop

    // 0x8000F2A0: sh          $zero, 0x62($t2)
    MEM_H(0X62, ctx->r10) = 0;
    // 0x8000F2A4: b           L_8000F46C
    // 0x8000F2A8: nop

        goto L_8000F46C;
    // 0x8000F2A8: nop

L_8000F2AC:
    // 0x8000F2AC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F2B0: nop

    // 0x8000F2B4: lh          $t4, 0x66($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X66);
    // 0x8000F2B8: nop

    // 0x8000F2BC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8000F2C0: nop

    // 0x8000F2C4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000F2C8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8000F2CC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F2D0: nop

    // 0x8000F2D4: lhu         $t6, 0x68($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X68);
    // 0x8000F2D8: nop

    // 0x8000F2DC: bne         $t6, $zero, L_8000F31C
    if (ctx->r14 != 0) {
        // 0x8000F2E0: nop
    
            goto L_8000F31C;
    }
    // 0x8000F2E0: nop

    // 0x8000F2E4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F2E8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F2EC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000F2F0: nop

    // 0x8000F2F4: lwc1        $f8, 0xF0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8000F2F8: nop

    // 0x8000F2FC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8000F300: nop

    // 0x8000F304: bc1f        L_8000F314
    if (!c1cs) {
        // 0x8000F308: nop
    
            goto L_8000F314;
    }
    // 0x8000F308: nop

    // 0x8000F30C: b           L_8000F46C
    // 0x8000F310: nop

        goto L_8000F46C;
    // 0x8000F310: nop

L_8000F314:
    // 0x8000F314: b           L_8000F34C
    // 0x8000F318: nop

        goto L_8000F34C;
    // 0x8000F318: nop

L_8000F31C:
    // 0x8000F31C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F320: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F324: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8000F328: nop

    // 0x8000F32C: lwc1        $f10, 0xF0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x8000F330: nop

    // 0x8000F334: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8000F338: nop

    // 0x8000F33C: bc1f        L_8000F34C
    if (!c1cs) {
        // 0x8000F340: nop
    
            goto L_8000F34C;
    }
    // 0x8000F340: nop

    // 0x8000F344: b           L_8000F46C
    // 0x8000F348: nop

        goto L_8000F46C;
    // 0x8000F348: nop

L_8000F34C:
    // 0x8000F34C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F350: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F354: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000F358: nop

    // 0x8000F35C: swc1        $f18, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f18.u32l;
    // 0x8000F360: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F364: jal         0x8000F4B0
    // 0x8000F368: nop

    func_8000F4B0(rdram, ctx);
        goto after_16;
    // 0x8000F368: nop

    after_16:
    // 0x8000F36C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F370: nop

    // 0x8000F374: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
    // 0x8000F378: b           L_8000F46C
    // 0x8000F37C: nop

        goto L_8000F46C;
    // 0x8000F37C: nop

L_8000F380:
    // 0x8000F380: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F384: nop

    // 0x8000F388: lhu         $a0, 0x66($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X66);
    // 0x8000F38C: jal         0x80014BD4
    // 0x8000F390: nop

    func_80014BD4(rdram, ctx);
        goto after_17;
    // 0x8000F390: nop

    after_17:
    // 0x8000F394: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8000F398: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F39C: nop

    // 0x8000F3A0: lhu         $t6, 0x68($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X68);
    // 0x8000F3A4: nop

    // 0x8000F3A8: bne         $t6, $zero, L_8000F3E8
    if (ctx->r14 != 0) {
        // 0x8000F3AC: nop
    
            goto L_8000F3E8;
    }
    // 0x8000F3AC: nop

    // 0x8000F3B0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F3B4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F3B8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000F3BC: nop

    // 0x8000F3C0: lwc1        $f4, 0xF4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x8000F3C4: nop

    // 0x8000F3C8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8000F3CC: nop

    // 0x8000F3D0: bc1f        L_8000F3E0
    if (!c1cs) {
        // 0x8000F3D4: nop
    
            goto L_8000F3E0;
    }
    // 0x8000F3D4: nop

    // 0x8000F3D8: b           L_8000F46C
    // 0x8000F3DC: nop

        goto L_8000F46C;
    // 0x8000F3DC: nop

L_8000F3E0:
    // 0x8000F3E0: b           L_8000F418
    // 0x8000F3E4: nop

        goto L_8000F418;
    // 0x8000F3E4: nop

L_8000F3E8:
    // 0x8000F3E8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F3EC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F3F0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8000F3F4: nop

    // 0x8000F3F8: lwc1        $f6, 0xF4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF4);
    // 0x8000F3FC: nop

    // 0x8000F400: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8000F404: nop

    // 0x8000F408: bc1f        L_8000F418
    if (!c1cs) {
        // 0x8000F40C: nop
    
            goto L_8000F418;
    }
    // 0x8000F40C: nop

    // 0x8000F410: b           L_8000F46C
    // 0x8000F414: nop

        goto L_8000F46C;
    // 0x8000F414: nop

L_8000F418:
    // 0x8000F418: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F41C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F420: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000F424: nop

    // 0x8000F428: swc1        $f16, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f16.u32l;
    // 0x8000F42C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F430: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F434: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8000F438: nop

    // 0x8000F43C: swc1        $f18, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f18.u32l;
    // 0x8000F440: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F444: jal         0x8000F4B0
    // 0x8000F448: nop

    func_8000F4B0(rdram, ctx);
        goto after_18;
    // 0x8000F448: nop

    after_18:
    // 0x8000F44C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F450: nop

    // 0x8000F454: sh          $zero, 0x62($t5)
    MEM_H(0X62, ctx->r13) = 0;
    // 0x8000F458: b           L_8000F46C
    // 0x8000F45C: nop

        goto L_8000F46C;
    // 0x8000F45C: nop

L_8000F460:
    // 0x8000F460: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F464: nop

    // 0x8000F468: sh          $zero, 0x62($t6)
    MEM_H(0X62, ctx->r14) = 0;
L_8000F46C:
    // 0x8000F46C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F470: nop

    // 0x8000F474: lhu         $t8, 0x62($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X62);
    // 0x8000F478: nop

    // 0x8000F47C: bne         $t8, $zero, L_8000F48C
    if (ctx->r24 != 0) {
        // 0x8000F480: nop
    
            goto L_8000F48C;
    }
    // 0x8000F480: nop

    // 0x8000F484: b           L_8000F49C
    // 0x8000F488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F49C;
    // 0x8000F488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F48C:
    // 0x8000F48C: b           L_8000F49C
    // 0x8000F490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F49C;
    // 0x8000F490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000F494: b           L_8000F49C
    // 0x8000F498: nop

        goto L_8000F49C;
    // 0x8000F498: nop

L_8000F49C:
    // 0x8000F49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F4A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F4A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F4A8: jr          $ra
    // 0x8000F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8000262C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000262C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002634: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80002638: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000263C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80002640: nop

    // 0x80002644: beq         $t6, $zero, L_80002658
    if (ctx->r14 == 0) {
        // 0x80002648: nop
    
            goto L_80002658;
    }
    // 0x80002648: nop

    // 0x8000264C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80002650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80002654: sw          $t7, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r15;
L_80002658:
    // 0x80002658: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000265C: nop

    // 0x80002660: beq         $t8, $zero, L_80002674
    if (ctx->r24 == 0) {
        // 0x80002664: nop
    
            goto L_80002674;
    }
    // 0x80002664: nop

    // 0x80002668: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8000266C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80002670: sw          $t9, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r25;
L_80002674:
    // 0x80002674: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80002678: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8000267C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80002680: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_80002684:
    // 0x80002684: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80002688: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8000268C: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x80002690: nop

    // 0x80002694: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80002698: beq         $t3, $zero, L_80002704
    if (ctx->r11 == 0) {
        // 0x8000269C: nop
    
            goto L_80002704;
    }
    // 0x8000269C: nop

    // 0x800026A0: jal         0x800C1754
    // 0x800026A4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800026A4: nop

    after_0:
    // 0x800026A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800026AC: jal         0x800A7230
    // 0x800026B0: nop

    func_800A7230(rdram, ctx);
        goto after_1;
    // 0x800026B0: nop

    after_1:
    // 0x800026B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800026B8: nop

    // 0x800026BC: lwc1        $f12, 0xF0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800026C0: jal         0x800C2780
    // 0x800026C4: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x800026C4: nop

    after_2:
    // 0x800026C8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800026CC: nop

    // 0x800026D0: lwc1        $f12, 0xEC($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x800026D4: jal         0x800C25B8
    // 0x800026D8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x800026D8: nop

    after_3:
    // 0x800026DC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800026E0: nop

    // 0x800026E4: lwc1        $f12, 0xE8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x800026E8: jal         0x800C23E8
    // 0x800026EC: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x800026EC: nop

    after_4:
    // 0x800026F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800026F4: jal         0x800997D8
    // 0x800026F8: nop

    func_800997D8(rdram, ctx);
        goto after_5;
    // 0x800026F8: nop

    after_5:
    // 0x800026FC: jal         0x800C1A28
    // 0x80002700: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x80002700: nop

    after_6:
L_80002704:
    // 0x80002704: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80002708: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8000270C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80002710: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80002714: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80002718: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8000271C: bne         $at, $zero, L_80002684
    if (ctx->r1 != 0) {
        // 0x80002720: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80002684;
    }
    // 0x80002720: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80002724: jal         0x80016074
    // 0x80002728: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_7;
    // 0x80002728: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_7:
    // 0x8000272C: beq         $v0, $zero, L_8000280C
    if (ctx->r2 == 0) {
        // 0x80002730: nop
    
            goto L_8000280C;
    }
    // 0x80002730: nop

    // 0x80002734: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80002738: lw          $t1, -0x4538($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4538);
    // 0x8000273C: nop

    // 0x80002740: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80002744: nop

    // 0x80002748: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x8000274C: nop

    // 0x80002750: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80002754: beq         $t4, $zero, L_8000280C
    if (ctx->r12 == 0) {
        // 0x80002758: nop
    
            goto L_8000280C;
    }
    // 0x80002758: nop

    // 0x8000275C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80002760: lw          $t5, -0x73DC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73DC);
    // 0x80002764: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80002768: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_8000276C:
    // 0x8000276C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80002770: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80002774: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x80002778: nop

    // 0x8000277C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80002780: beq         $t9, $zero, L_800027EC
    if (ctx->r25 == 0) {
        // 0x80002784: nop
    
            goto L_800027EC;
    }
    // 0x80002784: nop

    // 0x80002788: jal         0x800C1754
    // 0x8000278C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_8;
    // 0x8000278C: nop

    after_8:
    // 0x80002790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80002794: jal         0x800A7230
    // 0x80002798: nop

    func_800A7230(rdram, ctx);
        goto after_9;
    // 0x80002798: nop

    after_9:
    // 0x8000279C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800027A0: nop

    // 0x800027A4: lwc1        $f12, 0xF0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x800027A8: jal         0x800C2780
    // 0x800027AC: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_10;
    // 0x800027AC: nop

    after_10:
    // 0x800027B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800027B4: nop

    // 0x800027B8: lwc1        $f12, 0xEC($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XEC);
    // 0x800027BC: jal         0x800C25B8
    // 0x800027C0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_11;
    // 0x800027C0: nop

    after_11:
    // 0x800027C4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800027C8: nop

    // 0x800027CC: lwc1        $f12, 0xE8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x800027D0: jal         0x800C23E8
    // 0x800027D4: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_12;
    // 0x800027D4: nop

    after_12:
    // 0x800027D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800027DC: jal         0x800997D8
    // 0x800027E0: nop

    func_800997D8(rdram, ctx);
        goto after_13;
    // 0x800027E0: nop

    after_13:
    // 0x800027E4: jal         0x800C1A28
    // 0x800027E8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_14;
    // 0x800027E8: nop

    after_14:
L_800027EC:
    // 0x800027EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800027F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800027F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800027F8: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800027FC: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x80002800: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80002804: bne         $at, $zero, L_8000276C
    if (ctx->r1 != 0) {
        // 0x80002808: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8000276C;
    }
    // 0x80002808: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_8000280C:
    // 0x8000280C: b           L_80002814
    // 0x80002810: nop

        goto L_80002814;
    // 0x80002810: nop

L_80002814:
    // 0x80002814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000281C: jr          $ra
    // 0x80002820: nop

    return;
    // 0x80002820: nop

;}
RECOMP_FUNC void func_8000D688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D688: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000D68C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000D690:
    // 0x8000D690: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000D694: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D698: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D69C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000D6A0: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x8000D6A4: nop

    // 0x8000D6A8: beq         $t8, $zero, L_8000D71C
    if (ctx->r24 == 0) {
        // 0x8000D6AC: nop
    
            goto L_8000D71C;
    }
    // 0x8000D6AC: nop

    // 0x8000D6B0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8000D6B4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8000D6B8: addiu       $t1, $t1, -0x7E8
    ctx->r9 = ADD32(ctx->r9, -0X7E8);
    // 0x8000D6BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8000D6C0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000D6C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D6C8: sw          $t2, -0x7F4($at)
    MEM_W(-0X7F4, ctx->r1) = ctx->r10;
    // 0x8000D6CC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8000D6D0: lw          $t3, -0x7F4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7F4);
    // 0x8000D6D4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8000D6D8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000D6DC: nop

    // 0x8000D6E0: lw          $t5, 0x1AC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1AC);
    // 0x8000D6E4: nop

    // 0x8000D6E8: bne         $t5, $t6, L_8000D71C
    if (ctx->r13 != ctx->r14) {
        // 0x8000D6EC: nop
    
            goto L_8000D71C;
    }
    // 0x8000D6EC: nop

    // 0x8000D6F0: lw          $t7, 0x1A8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X1A8);
    // 0x8000D6F4: nop

    // 0x8000D6F8: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8000D6FC: bne         $t8, $zero, L_8000D71C
    if (ctx->r24 != 0) {
        // 0x8000D700: nop
    
            goto L_8000D71C;
    }
    // 0x8000D700: nop

    // 0x8000D704: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8000D708: lw          $t9, -0x7F4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7F4);
    // 0x8000D70C: nop

    // 0x8000D710: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000D714: b           L_8000D744
    // 0x8000D718: nop

        goto L_8000D744;
    // 0x8000D718: nop

L_8000D71C:
    // 0x8000D71C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8000D720: nop

    // 0x8000D724: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000D728: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8000D72C: bne         $at, $zero, L_8000D690
    if (ctx->r1 != 0) {
        // 0x8000D730: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8000D690;
    }
    // 0x8000D730: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8000D734: b           L_8000D744
    // 0x8000D738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D744;
    // 0x8000D738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D73C: b           L_8000D744
    // 0x8000D740: nop

        goto L_8000D744;
    // 0x8000D740: nop

L_8000D744:
    // 0x8000D744: jr          $ra
    // 0x8000D748: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000D748: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006ED78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED80: jal         0x80061348
    // 0x8006ED84: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ED84: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    after_0:
    // 0x8006ED88: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ED8C: b           L_8006ED9C
    // 0x8006ED90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006ED9C;
    // 0x8006ED90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ED94: b           L_8006ED9C
    // 0x8006ED98: nop

        goto L_8006ED9C;
    // 0x8006ED98: nop

L_8006ED9C:
    // 0x8006ED9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EDA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EDA4: jr          $ra
    // 0x8006EDA8: nop

    return;
    // 0x8006EDA8: nop

;}
RECOMP_FUNC void AudioMgr_StopMusic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B8FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8FB0: jal         0x800BB3EC
    // 0x800B8FB4: nop

    AudioDriver_StopSeqplayer(rdram, ctx);
        goto after_0;
    // 0x800B8FB4: nop

    after_0:
    // 0x800B8FB8: b           L_800B8FC0
    // 0x800B8FBC: nop

        goto L_800B8FC0;
    // 0x800B8FBC: nop

L_800B8FC0:
    // 0x800B8FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B8FC8: jr          $ra
    // 0x800B8FCC: nop

    return;
    // 0x800B8FCC: nop

    // 0x800B8FD0: jr          $ra
    // 0x800B8FD4: nop

    return;
    // 0x800B8FD4: nop

    // 0x800B8FD8: jr          $ra
    // 0x800B8FDC: nop

    return;
    // 0x800B8FDC: nop

    // 0x800B8FE0: jr          $ra
    // 0x800B8FE4: nop

    return;
    // 0x800B8FE4: nop

    // 0x800B8FE8: jr          $ra
    // 0x800B8FEC: nop

    return;
    // 0x800B8FEC: nop

    // 0x800B8FF0: jr          $ra
    // 0x800B8FF4: nop

    return;
    // 0x800B8FF4: nop

    // 0x800B8FF8: jr          $ra
    // 0x800B8FFC: nop

    return;
    // 0x800B8FFC: nop

;}
RECOMP_FUNC void func_8006BF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF48: jal         0x8005F064
    // 0x8006BF4C: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BF4C: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    after_0:
    // 0x8006BF50: b           L_8006BF60
    // 0x8006BF54: nop

        goto L_8006BF60;
    // 0x8006BF54: nop

    // 0x8006BF58: b           L_8006BF60
    // 0x8006BF5C: nop

        goto L_8006BF60;
    // 0x8006BF5C: nop

L_8006BF60:
    // 0x8006BF60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF68: jr          $ra
    // 0x8006BF6C: nop

    return;
    // 0x8006BF6C: nop

;}
RECOMP_FUNC void func_80067F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067F6C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067F70: nop

    // 0x80067F74: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067F78: nop

    // 0x80067F7C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067F80: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067F84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067F88: beq         $v0, $zero, L_80067FC0
    if (ctx->r2 == 0) {
        // 0x80067F8C: nop
    
            goto L_80067FC0;
    }
    // 0x80067F8C: nop

    // 0x80067F90: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067F94: nop

    // 0x80067F98: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067F9C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067FA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80067FA4: beq         $v0, $zero, L_80067FC0
    if (ctx->r2 == 0) {
        // 0x80067FA8: nop
    
            goto L_80067FC0;
    }
    // 0x80067FA8: nop

    // 0x80067FAC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067FB0: nop

    // 0x80067FB4: slti        $t9, $v0, 0x12C
    ctx->r25 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067FB8: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80067FBC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80067FC0:
    // 0x80067FC0: jr          $ra
    // 0x80067FC4: nop

    return;
    // 0x80067FC4: nop

    // 0x80067FC8: jr          $ra
    // 0x80067FCC: nop

    return;
    // 0x80067FCC: nop

    // 0x80067FD0: jr          $ra
    // 0x80067FD4: nop

    return;
    // 0x80067FD4: nop

;}
RECOMP_FUNC void func_8009A324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A324: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8009A328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009A32C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8009A330: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8009A334: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8009A338: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009A33C: lw          $t7, 0x70E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E4);
    // 0x8009A340: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8009A344: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8009A348: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8009A34C: jal         0x800C2D08
    // 0x8009A350: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    MtxUtil_MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x8009A350: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_0:
    // 0x8009A354: addiu       $t9, $sp, 0x18
    ctx->r25 = ADD32(ctx->r29, 0X18);
    // 0x8009A358: lwc1        $f4, 0x38($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X38);
    // 0x8009A35C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8009A360: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009A364: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8009A368: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8009A36C: nop

    // 0x8009A370: bc1f        L_8009A380
    if (!c1cs) {
        // 0x8009A374: nop
    
            goto L_8009A380;
    }
    // 0x8009A374: nop

    // 0x8009A378: b           L_8009A3D8
    // 0x8009A37C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8009A3D8;
    // 0x8009A37C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009A380:
    // 0x8009A380: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A384: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x8009A388: lwc1        $f16, 0x38($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X38);
    // 0x8009A38C: lwc1        $f10, 0x7218($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A390: lwc1        $f4, 0x30($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8009A394: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009A398: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A39C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009A3A0: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x8009A3A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A3A8: addiu       $t2, $sp, 0x18
    ctx->r10 = ADD32(ctx->r29, 0X18);
    // 0x8009A3AC: lwc1        $f10, 0x38($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X38);
    // 0x8009A3B0: lwc1        $f8, 0x7218($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A3B4: lwc1        $f18, 0x34($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8009A3B8: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8009A3BC: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8009A3C0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009A3C4: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x8009A3C8: b           L_8009A3D8
    // 0x8009A3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A3D8;
    // 0x8009A3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009A3D0: b           L_8009A3D8
    // 0x8009A3D4: nop

        goto L_8009A3D8;
    // 0x8009A3D4: nop

L_8009A3D8:
    // 0x8009A3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009A3DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8009A3E0: jr          $ra
    // 0x8009A3E4: nop

    return;
    // 0x8009A3E4: nop

;}
RECOMP_FUNC void func_8005FC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FC18: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005FC1C: lbu         $t6, 0x1726($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1726);
    // 0x8005FC20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005FC24: sb          $t6, 0xD74($at)
    MEM_B(0XD74, ctx->r1) = ctx->r14;
    // 0x8005FC28: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FC2C:
    // 0x8005FC2C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005FC34: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8005FC38: lbu         $t9, 0x16E6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X16E6);
    // 0x8005FC3C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005FC40: sb          $t9, 0x680($at)
    MEM_B(0X680, ctx->r1) = ctx->r25;
    // 0x8005FC44: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC48: nop

    // 0x8005FC4C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005FC50: slti        $at, $t1, 0x40
    ctx->r1 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x8005FC54: bne         $at, $zero, L_8005FC2C
    if (ctx->r1 != 0) {
        // 0x8005FC58: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8005FC2C;
    }
    // 0x8005FC58: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8005FC5C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FC60:
    // 0x8005FC60: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005FC68: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8005FC6C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005FC70: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8005FC74: lh          $t5, 0x6E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6E);
    // 0x8005FC78: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x8005FC7C: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x8005FC80: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC84: nop

    // 0x8005FC88: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FC8C: slti        $at, $t7, 0x2A
    ctx->r1 = SIGNED(ctx->r15) < 0X2A ? 1 : 0;
    // 0x8005FC90: bne         $at, $zero, L_8005FC60
    if (ctx->r1 != 0) {
        // 0x8005FC94: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FC60;
    }
    // 0x8005FC94: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FC98: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FC9C:
    // 0x8005FC9C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005FCA0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005FCA4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8005FCA8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005FCAC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FCB0: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FCB4: lw          $t0, 0x468($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X468);
    // 0x8005FCB8: lwl         $at, 0xAF2($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XAF2);
    // 0x8005FCBC: lwr         $at, 0xAF5($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XAF5);
    // 0x8005FCC0: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x8005FCC4: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x8005FCC8: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x8005FCCC: lwl         $t8, 0xAF6($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XAF6);
    // 0x8005FCD0: lwr         $t8, 0xAF9($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XAF9);
    // 0x8005FCD4: nop

    // 0x8005FCD8: swl         $t8, 0x4($t4)
    do_swl(rdram, 0X4, ctx->r12, ctx->r24);
    // 0x8005FCDC: swr         $t8, 0x7($t4)
    do_swr(rdram, 0X7, ctx->r12, ctx->r24);
    // 0x8005FCE0: lwl         $at, 0xAFA($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XAFA);
    // 0x8005FCE4: lwr         $at, 0xAFD($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XAFD);
    // 0x8005FCE8: nop

    // 0x8005FCEC: swl         $at, 0x8($t4)
    do_swl(rdram, 0X8, ctx->r12, ctx->r1);
    // 0x8005FCF0: swr         $at, 0xB($t4)
    do_swr(rdram, 0XB, ctx->r12, ctx->r1);
    // 0x8005FCF4: lwl         $t8, 0xAFE($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XAFE);
    // 0x8005FCF8: lwr         $t8, 0xB01($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XB01);
    // 0x8005FCFC: nop

    // 0x8005FD00: swl         $t8, 0xC($t4)
    do_swl(rdram, 0XC, ctx->r12, ctx->r24);
    // 0x8005FD04: swr         $t8, 0xF($t4)
    do_swr(rdram, 0XF, ctx->r12, ctx->r24);
    // 0x8005FD08: lhu         $at, 0xB02($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0XB02);
    // 0x8005FD0C: nop

    // 0x8005FD10: sh          $at, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r1;
    // 0x8005FD14: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FD18: nop

    // 0x8005FD1C: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FD20: slti        $at, $t7, 0x11
    ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
    // 0x8005FD24: bne         $at, $zero, L_8005FC9C
    if (ctx->r1 != 0) {
        // 0x8005FD28: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FC9C;
    }
    // 0x8005FD28: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FD2C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FD30:
    // 0x8005FD30: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FD34: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005FD38: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8005FD3C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8005FD40: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FD44: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FD48: lw          $t1, 0x470($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X470);
    // 0x8005FD4C: lwl         $at, 0xD0E($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XD0E);
    // 0x8005FD50: lwr         $at, 0xD11($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XD11);
    // 0x8005FD54: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x8005FD58: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8005FD5C: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x8005FD60: lwl         $t8, 0xD12($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XD12);
    // 0x8005FD64: lwr         $t8, 0xD15($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XD15);
    // 0x8005FD68: nop

    // 0x8005FD6C: swl         $t8, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r24);
    // 0x8005FD70: swr         $t8, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r24);
    // 0x8005FD74: lwl         $at, 0xD16($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XD16);
    // 0x8005FD78: lwr         $at, 0xD19($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XD19);
    // 0x8005FD7C: nop

    // 0x8005FD80: swl         $at, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r1);
    // 0x8005FD84: swr         $at, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r1);
    // 0x8005FD88: lwl         $t8, 0xD1A($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XD1A);
    // 0x8005FD8C: lwr         $t8, 0xD1D($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XD1D);
    // 0x8005FD90: nop

    // 0x8005FD94: swl         $t8, 0xC($t5)
    do_swl(rdram, 0XC, ctx->r13, ctx->r24);
    // 0x8005FD98: swr         $t8, 0xF($t5)
    do_swr(rdram, 0XF, ctx->r13, ctx->r24);
    // 0x8005FD9C: lhu         $at, 0xD1E($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0XD1E);
    // 0x8005FDA0: nop

    // 0x8005FDA4: sh          $at, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r1;
    // 0x8005FDA8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FDAC: nop

    // 0x8005FDB0: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FDB4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8005FDB8: bne         $at, $zero, L_8005FD30
    if (ctx->r1 != 0) {
        // 0x8005FDBC: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FD30;
    }
    // 0x8005FDBC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FDC0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FDC4:
    // 0x8005FDC4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005FDC8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005FDCC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8005FDD0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005FDD4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FDD8: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FDDC: lw          $t0, 0x478($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X478);
    // 0x8005FDE0: lwl         $at, 0xD56($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XD56);
    // 0x8005FDE4: lwr         $at, 0xD59($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XD59);
    // 0x8005FDE8: addu        $t6, $t0, $t2
    ctx->r14 = ADD32(ctx->r8, ctx->r10);
    // 0x8005FDEC: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x8005FDF0: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
    // 0x8005FDF4: lwl         $t8, 0xD5A($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XD5A);
    // 0x8005FDF8: lwr         $t8, 0xD5D($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XD5D);
    // 0x8005FDFC: nop

    // 0x8005FE00: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x8005FE04: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x8005FE08: lwl         $at, 0xD5E($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XD5E);
    // 0x8005FE0C: lwr         $at, 0xD61($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XD61);
    // 0x8005FE10: nop

    // 0x8005FE14: swl         $at, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r1);
    // 0x8005FE18: swr         $at, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r1);
    // 0x8005FE1C: lwl         $t8, 0xD62($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XD62);
    // 0x8005FE20: lwr         $t8, 0xD65($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XD65);
    // 0x8005FE24: nop

    // 0x8005FE28: swl         $t8, 0xC($t6)
    do_swl(rdram, 0XC, ctx->r14, ctx->r24);
    // 0x8005FE2C: swr         $t8, 0xF($t6)
    do_swr(rdram, 0XF, ctx->r14, ctx->r24);
    // 0x8005FE30: lhu         $at, 0xD66($t4)
    ctx->r1 = MEM_HU(ctx->r12, 0XD66);
    // 0x8005FE34: nop

    // 0x8005FE38: sh          $at, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r1;
    // 0x8005FE3C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FE40: nop

    // 0x8005FE44: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FE48: slti        $at, $t7, 0x2F
    ctx->r1 = SIGNED(ctx->r15) < 0X2F ? 1 : 0;
    // 0x8005FE4C: bne         $at, $zero, L_8005FDC4
    if (ctx->r1 != 0) {
        // 0x8005FE50: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FDC4;
    }
    // 0x8005FE50: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FE54: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FE58:
    // 0x8005FE58: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FE5C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005FE60: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8005FE64: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8005FE68: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FE6C: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FE70: lw          $t1, 0x488($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X488);
    // 0x8005FE74: lwl         $at, 0xC24($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0XC24);
    // 0x8005FE78: lwr         $at, 0xC27($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0XC27);
    // 0x8005FE7C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8005FE80: swl         $at, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r1);
    // 0x8005FE84: swr         $at, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r1);
    // 0x8005FE88: lwl         $t8, 0xC28($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0XC28);
    // 0x8005FE8C: lwr         $t8, 0xC2B($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0XC2B);
    // 0x8005FE90: nop

    // 0x8005FE94: swl         $t8, 0x4($t3)
    do_swl(rdram, 0X4, ctx->r11, ctx->r24);
    // 0x8005FE98: swr         $t8, 0x7($t3)
    do_swr(rdram, 0X7, ctx->r11, ctx->r24);
    // 0x8005FE9C: lwl         $at, 0xC2C($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0XC2C);
    // 0x8005FEA0: lwr         $at, 0xC2F($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0XC2F);
    // 0x8005FEA4: nop

    // 0x8005FEA8: swl         $at, 0x8($t3)
    do_swl(rdram, 0X8, ctx->r11, ctx->r1);
    // 0x8005FEAC: swr         $at, 0xB($t3)
    do_swr(rdram, 0XB, ctx->r11, ctx->r1);
    // 0x8005FEB0: lwl         $t8, 0xC30($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0XC30);
    // 0x8005FEB4: lwr         $t8, 0xC33($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0XC33);
    // 0x8005FEB8: nop

    // 0x8005FEBC: swl         $t8, 0xC($t3)
    do_swl(rdram, 0XC, ctx->r11, ctx->r24);
    // 0x8005FEC0: swr         $t8, 0xF($t3)
    do_swr(rdram, 0XF, ctx->r11, ctx->r24);
    // 0x8005FEC4: lhu         $at, 0xC34($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0XC34);
    // 0x8005FEC8: nop

    // 0x8005FECC: sh          $at, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r1;
    // 0x8005FED0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FED4: nop

    // 0x8005FED8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FEDC: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8005FEE0: bne         $at, $zero, L_8005FE58
    if (ctx->r1 != 0) {
        // 0x8005FEE4: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FE58;
    }
    // 0x8005FEE4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FEE8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FEEC:
    // 0x8005FEEC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005FEF0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005FEF4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8005FEF8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005FEFC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FF00: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FF04: lw          $t0, 0x4A4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4A4);
    // 0x8005FF08: lwl         $at, 0xCD8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XCD8);
    // 0x8005FF0C: lwr         $at, 0xCDB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XCDB);
    // 0x8005FF10: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x8005FF14: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x8005FF18: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x8005FF1C: lwl         $t8, 0xCDC($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XCDC);
    // 0x8005FF20: lwr         $t8, 0xCDF($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XCDF);
    // 0x8005FF24: nop

    // 0x8005FF28: swl         $t8, 0x4($t4)
    do_swl(rdram, 0X4, ctx->r12, ctx->r24);
    // 0x8005FF2C: swr         $t8, 0x7($t4)
    do_swr(rdram, 0X7, ctx->r12, ctx->r24);
    // 0x8005FF30: lwl         $at, 0xCE0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XCE0);
    // 0x8005FF34: lwr         $at, 0xCE3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XCE3);
    // 0x8005FF38: nop

    // 0x8005FF3C: swl         $at, 0x8($t4)
    do_swl(rdram, 0X8, ctx->r12, ctx->r1);
    // 0x8005FF40: swr         $at, 0xB($t4)
    do_swr(rdram, 0XB, ctx->r12, ctx->r1);
    // 0x8005FF44: lwl         $t8, 0xCE4($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XCE4);
    // 0x8005FF48: lwr         $t8, 0xCE7($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XCE7);
    // 0x8005FF4C: nop

    // 0x8005FF50: swl         $t8, 0xC($t4)
    do_swl(rdram, 0XC, ctx->r12, ctx->r24);
    // 0x8005FF54: swr         $t8, 0xF($t4)
    do_swr(rdram, 0XF, ctx->r12, ctx->r24);
    // 0x8005FF58: lhu         $at, 0xCE8($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0XCE8);
    // 0x8005FF5C: nop

    // 0x8005FF60: sh          $at, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r1;
    // 0x8005FF64: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FF68: nop

    // 0x8005FF6C: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FF70: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8005FF74: bne         $at, $zero, L_8005FEEC
    if (ctx->r1 != 0) {
        // 0x8005FF78: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FEEC;
    }
    // 0x8005FF78: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FF7C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FF80:
    // 0x8005FF80: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FF84: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8005FF88: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8005FF8C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8005FF90: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FF94: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FF98: lw          $t1, 0x5A8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5A8);
    // 0x8005FF9C: lwl         $at, 0xC48($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XC48);
    // 0x8005FFA0: lwr         $at, 0xC4B($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XC4B);
    // 0x8005FFA4: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x8005FFA8: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8005FFAC: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x8005FFB0: lwl         $t8, 0xC4C($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XC4C);
    // 0x8005FFB4: lwr         $t8, 0xC4F($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XC4F);
    // 0x8005FFB8: nop

    // 0x8005FFBC: swl         $t8, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r24);
    // 0x8005FFC0: swr         $t8, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r24);
    // 0x8005FFC4: lwl         $at, 0xC50($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XC50);
    // 0x8005FFC8: lwr         $at, 0xC53($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XC53);
    // 0x8005FFCC: nop

    // 0x8005FFD0: swl         $at, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r1);
    // 0x8005FFD4: swr         $at, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r1);
    // 0x8005FFD8: lwl         $t8, 0xC54($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XC54);
    // 0x8005FFDC: lwr         $t8, 0xC57($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XC57);
    // 0x8005FFE0: nop

    // 0x8005FFE4: swl         $t8, 0xC($t5)
    do_swl(rdram, 0XC, ctx->r13, ctx->r24);
    // 0x8005FFE8: swr         $t8, 0xF($t5)
    do_swr(rdram, 0XF, ctx->r13, ctx->r24);
    // 0x8005FFEC: lhu         $at, 0xC58($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0XC58);
    // 0x8005FFF0: nop

    // 0x8005FFF4: sh          $at, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r1;
    // 0x8005FFF8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FFFC: nop

    // 0x80060000: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80060004: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80060008: bne         $at, $zero, L_8005FF80
    if (ctx->r1 != 0) {
        // 0x8006000C: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FF80;
    }
    // 0x8006000C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80060010: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80060014:
    // 0x80060014: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80060018: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006001C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80060020: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80060024: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80060028: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8006002C: lw          $t0, 0x630($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X630);
    // 0x80060030: lwl         $at, 0x10A4($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X10A4);
    // 0x80060034: lwr         $at, 0x10A7($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X10A7);
    // 0x80060038: addu        $t6, $t0, $t2
    ctx->r14 = ADD32(ctx->r8, ctx->r10);
    // 0x8006003C: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x80060040: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
    // 0x80060044: lwl         $t8, 0x10A8($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0X10A8);
    // 0x80060048: lwr         $t8, 0x10AB($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0X10AB);
    // 0x8006004C: nop

    // 0x80060050: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x80060054: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x80060058: lwl         $at, 0x10AC($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X10AC);
    // 0x8006005C: lwr         $at, 0x10AF($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X10AF);
    // 0x80060060: nop

    // 0x80060064: swl         $at, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r1);
    // 0x80060068: swr         $at, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r1);
    // 0x8006006C: lwl         $t8, 0x10B0($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0X10B0);
    // 0x80060070: lwr         $t8, 0x10B3($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0X10B3);
    // 0x80060074: nop

    // 0x80060078: swl         $t8, 0xC($t6)
    do_swl(rdram, 0XC, ctx->r14, ctx->r24);
    // 0x8006007C: swr         $t8, 0xF($t6)
    do_swr(rdram, 0XF, ctx->r14, ctx->r24);
    // 0x80060080: lhu         $at, 0x10B4($t4)
    ctx->r1 = MEM_HU(ctx->r12, 0X10B4);
    // 0x80060084: nop

    // 0x80060088: sh          $at, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r1;
    // 0x8006008C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80060090: nop

    // 0x80060094: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80060098: slti        $at, $t7, 0x2E
    ctx->r1 = SIGNED(ctx->r15) < 0X2E ? 1 : 0;
    // 0x8006009C: bne         $at, $zero, L_80060014
    if (ctx->r1 != 0) {
        // 0x800600A0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80060014;
    }
    // 0x800600A0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800600A4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800600A8:
    // 0x800600A8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800600AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800600B0: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800600B4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800600B8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800600BC: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x800600C0: lw          $t1, 0x634($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X634);
    // 0x800600C4: lwl         $at, 0x1548($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X1548);
    // 0x800600C8: lwr         $at, 0x154B($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X154B);
    // 0x800600CC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800600D0: swl         $at, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r1);
    // 0x800600D4: swr         $at, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r1);
    // 0x800600D8: lwl         $t8, 0x154C($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0X154C);
    // 0x800600DC: lwr         $t8, 0x154F($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0X154F);
    // 0x800600E0: nop

    // 0x800600E4: swl         $t8, 0x4($t3)
    do_swl(rdram, 0X4, ctx->r11, ctx->r24);
    // 0x800600E8: swr         $t8, 0x7($t3)
    do_swr(rdram, 0X7, ctx->r11, ctx->r24);
    // 0x800600EC: lwl         $at, 0x1550($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X1550);
    // 0x800600F0: lwr         $at, 0x1553($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X1553);
    // 0x800600F4: nop

    // 0x800600F8: swl         $at, 0x8($t3)
    do_swl(rdram, 0X8, ctx->r11, ctx->r1);
    // 0x800600FC: swr         $at, 0xB($t3)
    do_swr(rdram, 0XB, ctx->r11, ctx->r1);
    // 0x80060100: lwl         $t8, 0x1554($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0X1554);
    // 0x80060104: lwr         $t8, 0x1557($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0X1557);
    // 0x80060108: nop

    // 0x8006010C: swl         $t8, 0xC($t3)
    do_swl(rdram, 0XC, ctx->r11, ctx->r24);
    // 0x80060110: swr         $t8, 0xF($t3)
    do_swr(rdram, 0XF, ctx->r11, ctx->r24);
    // 0x80060114: lhu         $at, 0x1558($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0X1558);
    // 0x80060118: nop

    // 0x8006011C: sh          $at, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r1;
    // 0x80060120: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80060124: nop

    // 0x80060128: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8006012C: slti        $at, $t7, 0x17
    ctx->r1 = SIGNED(ctx->r15) < 0X17 ? 1 : 0;
    // 0x80060130: bne         $at, $zero, L_800600A8
    if (ctx->r1 != 0) {
        // 0x80060134: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800600A8;
    }
    // 0x80060134: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80060138: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8006013C:
    // 0x8006013C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80060140: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80060144: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80060148: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8006014C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80060150: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x80060154: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x80060158: lwl         $at, 0x13E0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X13E0);
    // 0x8006015C: lwr         $at, 0x13E3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X13E3);
    // 0x80060160: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80060164: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x80060168: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x8006016C: lwl         $t8, 0x13E4($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X13E4);
    // 0x80060170: lwr         $t8, 0x13E7($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X13E7);
    // 0x80060174: nop

    // 0x80060178: swl         $t8, 0x4($t4)
    do_swl(rdram, 0X4, ctx->r12, ctx->r24);
    // 0x8006017C: swr         $t8, 0x7($t4)
    do_swr(rdram, 0X7, ctx->r12, ctx->r24);
    // 0x80060180: lwl         $at, 0x13E8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X13E8);
    // 0x80060184: lwr         $at, 0x13EB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X13EB);
    // 0x80060188: nop

    // 0x8006018C: swl         $at, 0x8($t4)
    do_swl(rdram, 0X8, ctx->r12, ctx->r1);
    // 0x80060190: swr         $at, 0xB($t4)
    do_swr(rdram, 0XB, ctx->r12, ctx->r1);
    // 0x80060194: lwl         $t8, 0x13EC($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X13EC);
    // 0x80060198: lwr         $t8, 0x13EF($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X13EF);
    // 0x8006019C: nop

    // 0x800601A0: swl         $t8, 0xC($t4)
    do_swl(rdram, 0XC, ctx->r12, ctx->r24);
    // 0x800601A4: swr         $t8, 0xF($t4)
    do_swr(rdram, 0XF, ctx->r12, ctx->r24);
    // 0x800601A8: lhu         $at, 0x13F0($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X13F0);
    // 0x800601AC: nop

    // 0x800601B0: sh          $at, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r1;
    // 0x800601B4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800601B8: nop

    // 0x800601BC: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800601C0: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x800601C4: bne         $at, $zero, L_8006013C
    if (ctx->r1 != 0) {
        // 0x800601C8: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8006013C;
    }
    // 0x800601C8: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800601CC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800601D0:
    // 0x800601D0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800601D4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800601D8: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800601DC: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800601E0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800601E4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800601E8: lw          $t1, 0x638($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X638);
    // 0x800601EC: lwl         $at, 0xA86($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XA86);
    // 0x800601F0: lwr         $at, 0xA89($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XA89);
    // 0x800601F4: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x800601F8: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x800601FC: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x80060200: lwl         $t8, 0xA8A($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XA8A);
    // 0x80060204: lwr         $t8, 0xA8D($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XA8D);
    // 0x80060208: nop

    // 0x8006020C: swl         $t8, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r24);
    // 0x80060210: swr         $t8, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r24);
    // 0x80060214: lwl         $at, 0xA8E($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XA8E);
    // 0x80060218: lwr         $at, 0xA91($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XA91);
    // 0x8006021C: nop

    // 0x80060220: swl         $at, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r1);
    // 0x80060224: swr         $at, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r1);
    // 0x80060228: lwl         $t8, 0xA92($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XA92);
    // 0x8006022C: lwr         $t8, 0xA95($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XA95);
    // 0x80060230: nop

    // 0x80060234: swl         $t8, 0xC($t5)
    do_swl(rdram, 0XC, ctx->r13, ctx->r24);
    // 0x80060238: swr         $t8, 0xF($t5)
    do_swr(rdram, 0XF, ctx->r13, ctx->r24);
    // 0x8006023C: lhu         $at, 0xA96($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0XA96);
    // 0x80060240: nop

    // 0x80060244: sh          $at, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r1;
    // 0x80060248: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006024C: nop

    // 0x80060250: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80060254: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80060258: bne         $at, $zero, L_800601D0
    if (ctx->r1 != 0) {
        // 0x8006025C: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800601D0;
    }
    // 0x8006025C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80060260: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80060264:
    // 0x80060264: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80060268: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006026C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80060270: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80060274: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80060278: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8006027C: lw          $t0, 0x63C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X63C);
    // 0x80060280: lwl         $at, 0xABC($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XABC);
    // 0x80060284: lwr         $at, 0xABF($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XABF);
    // 0x80060288: addu        $t6, $t0, $t2
    ctx->r14 = ADD32(ctx->r8, ctx->r10);
    // 0x8006028C: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x80060290: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
    // 0x80060294: lwl         $t8, 0xAC0($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XAC0);
    // 0x80060298: lwr         $t8, 0xAC3($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XAC3);
    // 0x8006029C: nop

    // 0x800602A0: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x800602A4: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x800602A8: lwl         $at, 0xAC4($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XAC4);
    // 0x800602AC: lwr         $at, 0xAC7($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XAC7);
    // 0x800602B0: nop

    // 0x800602B4: swl         $at, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r1);
    // 0x800602B8: swr         $at, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r1);
    // 0x800602BC: lwl         $t8, 0xAC8($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XAC8);
    // 0x800602C0: lwr         $t8, 0xACB($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XACB);
    // 0x800602C4: nop

    // 0x800602C8: swl         $t8, 0xC($t6)
    do_swl(rdram, 0XC, ctx->r14, ctx->r24);
    // 0x800602CC: swr         $t8, 0xF($t6)
    do_swr(rdram, 0XF, ctx->r14, ctx->r24);
    // 0x800602D0: lhu         $at, 0xACC($t4)
    ctx->r1 = MEM_HU(ctx->r12, 0XACC);
    // 0x800602D4: nop

    // 0x800602D8: sh          $at, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r1;
    // 0x800602DC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800602E0: nop

    // 0x800602E4: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800602E8: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x800602EC: bne         $at, $zero, L_80060264
    if (ctx->r1 != 0) {
        // 0x800602F0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80060264;
    }
    // 0x800602F0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800602F4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800602F8:
    // 0x800602F8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800602FC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80060300: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80060304: addu        $t0, $a0, $t1
    ctx->r8 = ADD32(ctx->r4, ctx->r9);
    // 0x80060308: lbu         $t2, 0x172C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X172C);
    // 0x8006030C: lbu         $t3, 0x668($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X668);
    // 0x80060310: nop

    // 0x80060314: beq         $t2, $t3, L_80060324
    if (ctx->r10 == ctx->r11) {
        // 0x80060318: nop
    
            goto L_80060324;
    }
    // 0x80060318: nop

    // 0x8006031C: b           L_8006042C
    // 0x80060320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006042C;
    // 0x80060320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060324:
    // 0x80060324: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80060328: nop

    // 0x8006032C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80060330: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80060334: bne         $at, $zero, L_800602F8
    if (ctx->r1 != 0) {
        // 0x80060338: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800602F8;
    }
    // 0x80060338: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8006033C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80060340: lw          $t4, 0x658($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X658);
    // 0x80060344: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80060348: beq         $t4, $zero, L_80060408
    if (ctx->r12 == 0) {
        // 0x8006034C: nop
    
            goto L_80060408;
    }
    // 0x8006034C: nop

L_80060350:
    // 0x80060350: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80060354: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80060358: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8006035C: lw          $t2, 0x650($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X650);
    // 0x80060360: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80060364: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80060368: lbu         $t7, 0xC2($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XC2);
    // 0x8006036C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80060370: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80060374: lbu         $t6, 0x4($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4);
    // 0x80060378: sra         $t0, $t7, 6
    ctx->r8 = S32(SIGNED(ctx->r15) >> 6);
    // 0x8006037C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80060380: beq         $t1, $t6, L_80060390
    if (ctx->r9 == ctx->r14) {
        // 0x80060384: nop
    
            goto L_80060390;
    }
    // 0x80060384: nop

    // 0x80060388: b           L_8006042C
    // 0x8006038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006042C;
    // 0x8006038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060390:
    // 0x80060390: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80060394: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060398: addu        $t9, $a0, $t4
    ctx->r25 = ADD32(ctx->r4, ctx->r12);
    // 0x8006039C: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x800603A0: lbu         $t7, 0xC2($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XC2);
    // 0x800603A4: lw          $t8, 0x650($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X650);
    // 0x800603A8: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x800603AC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800603B0: andi        $t0, $t7, 0x3
    ctx->r8 = ctx->r15 & 0X3;
    // 0x800603B4: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x800603B8: sb          $t0, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r8;
    // 0x800603BC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800603C0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800603C4: addu        $t1, $a0, $t5
    ctx->r9 = ADD32(ctx->r4, ctx->r13);
    // 0x800603C8: lbu         $t6, 0xC2($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XC2);
    // 0x800603CC: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800603D0: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800603D4: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800603D8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800603DC: sra         $t9, $t6, 2
    ctx->r25 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800603E0: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x800603E4: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x800603E8: sb          $t7, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r15;
    // 0x800603EC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800603F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800603F4: lw          $t1, 0x658($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X658);
    // 0x800603F8: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800603FC: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x80060400: bne         $at, $zero, L_80060350
    if (ctx->r1 != 0) {
        // 0x80060404: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_80060350;
    }
    // 0x80060404: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_80060408:
    // 0x80060408: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8006040C: lw          $t9, 0x658($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X658);
    // 0x80060410: lw          $t6, 0x1728($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1728);
    // 0x80060414: nop

    // 0x80060418: xor         $v0, $t6, $t9
    ctx->r2 = ctx->r14 ^ ctx->r25;
    // 0x8006041C: b           L_8006042C
    // 0x80060420: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_8006042C;
    // 0x80060420: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80060424: b           L_8006042C
    // 0x80060428: nop

        goto L_8006042C;
    // 0x80060428: nop

L_8006042C:
    // 0x8006042C: jr          $ra
    // 0x80060430: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80060430: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80060434: nop

    // 0x80060438: nop

    // 0x8006043C: nop

;}
RECOMP_FUNC void func_8006C3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C3C8: jal         0x8005F064
    // 0x8006C3CC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C3CC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_0:
    // 0x8006C3D0: b           L_8006C3E0
    // 0x8006C3D4: nop

        goto L_8006C3E0;
    // 0x8006C3D4: nop

    // 0x8006C3D8: b           L_8006C3E0
    // 0x8006C3DC: nop

        goto L_8006C3E0;
    // 0x8006C3DC: nop

L_8006C3E0:
    // 0x8006C3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3E8: jr          $ra
    // 0x8006C3EC: nop

    return;
    // 0x8006C3EC: nop

;}
RECOMP_FUNC void func_80077414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007741C: jal         0x80061488
    // 0x80077420: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077420: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x80077424: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077428: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007742C: b           L_8007743C
    // 0x80077430: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007743C;
    // 0x80077430: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077434: b           L_8007743C
    // 0x80077438: nop

        goto L_8007743C;
    // 0x80077438: nop

L_8007743C:
    // 0x8007743C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077444: jr          $ra
    // 0x80077448: nop

    return;
    // 0x80077448: nop

;}
RECOMP_FUNC void func_8008A808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A808: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008A80C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008A810: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008A814: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008A818: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008A81C: jal         0x80031AC8
    // 0x8008A820: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x8008A820: nop

    after_0:
    // 0x8008A824: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8008A828: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008A82C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008A830: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x8008A834: lh          $t0, 0x73C($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X73C);
    // 0x8008A838: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008A83C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008A840: lh          $t9, 0x4664($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4664);
    // 0x8008A844: nop

    // 0x8008A848: bne         $t9, $t0, L_8008A894
    if (ctx->r25 != ctx->r8) {
        // 0x8008A84C: nop
    
            goto L_8008A894;
    }
    // 0x8008A84C: nop

    // 0x8008A850: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A854: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A858: beq         $t1, $at, L_8008A88C
    if (ctx->r9 == ctx->r1) {
        // 0x8008A85C: nop
    
            goto L_8008A88C;
    }
    // 0x8008A85C: nop

    // 0x8008A860: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008A864: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008A868: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x8008A86C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8008A870: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008A874: lhu         $t4, 0x10F2($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X10F2);
    // 0x8008A878: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8008A87C: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x8008A880: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x8008A884: and         $t7, $t3, $t5
    ctx->r15 = ctx->r11 & ctx->r13;
    // 0x8008A888: sh          $t7, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r15;
L_8008A88C:
    // 0x8008A88C: b           L_8008A950
    // 0x8008A890: nop

        goto L_8008A950;
    // 0x8008A890: nop

L_8008A894:
    // 0x8008A894: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A898: nop

    // 0x8008A89C: bne         $t8, $zero, L_8008A948
    if (ctx->r24 != 0) {
        // 0x8008A8A0: nop
    
            goto L_8008A948;
    }
    // 0x8008A8A0: nop

    // 0x8008A8A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008A8A8: nop

    // 0x8008A8AC: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x8008A8B0: nop

    // 0x8008A8B4: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x8008A8B8: beq         $t0, $zero, L_8008A8DC
    if (ctx->r8 == 0) {
        // 0x8008A8BC: nop
    
            goto L_8008A8DC;
    }
    // 0x8008A8BC: nop

    // 0x8008A8C0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008A8C4: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8008A8C8: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x8008A8CC: nop

    // 0x8008A8D0: and         $t3, $t4, $at
    ctx->r11 = ctx->r12 & ctx->r1;
    // 0x8008A8D4: b           L_8008A90C
    // 0x8008A8D8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_8008A90C;
    // 0x8008A8D8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_8008A8DC:
    // 0x8008A8DC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8008A8E0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008A8E4: lh          $t7, 0x4($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X4);
    // 0x8008A8E8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8008A8EC: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x8008A8F0: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x8008A8F4: lh          $s0, 0x4664($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X4664);
    // 0x8008A8F8: nop

    // 0x8008A8FC: bne         $s0, $at, L_8008A90C
    if (ctx->r16 != ctx->r1) {
        // 0x8008A900: sh          $s0, 0x73C($t5)
        MEM_H(0X73C, ctx->r13) = ctx->r16;
            goto L_8008A90C;
    }
    // 0x8008A900: sh          $s0, 0x73C($t5)
    MEM_H(0X73C, ctx->r13) = ctx->r16;
    // 0x8008A904: b           L_8008A950
    // 0x8008A908: nop

        goto L_8008A950;
    // 0x8008A908: nop

L_8008A90C:
    // 0x8008A90C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8008A910: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008A914: lh          $t9, 0x73C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X73C);
    // 0x8008A918: lw          $t6, 0x72C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X72C);
    // 0x8008A91C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008A920: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008A924: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x8008A928: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x8008A92C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008A930: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008A934: jal         0x800BD1FC
    // 0x8008A938: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8008A938: nop

    after_1:
    // 0x8008A93C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008A940: jal         0x800319B0
    // 0x8008A944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800319B0(rdram, ctx);
        goto after_2;
    // 0x8008A944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_8008A948:
    // 0x8008A948: b           L_8008A950
    // 0x8008A94C: nop

        goto L_8008A950;
    // 0x8008A94C: nop

L_8008A950:
    // 0x8008A950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A954: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008A958: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008A95C: jr          $ra
    // 0x8008A960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008A960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
RECOMP_FUNC void Main_IdleThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD76C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BD770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD774: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BD778: jal         0x800BC620
    // 0x800BD77C: nop

    SysMem_HeapInit(rdram, ctx);
        goto after_0;
    // 0x800BD77C: nop

    after_0:
    // 0x800BD780: jal         0x800C05A0
    // 0x800BD784: nop

    Thread_Init(rdram, ctx);
        goto after_1;
    // 0x800BD784: nop

    after_1:
    // 0x800BD788: jal         0x800ABE54
    // 0x800BD78C: nop

    func_800ABE54(rdram, ctx);
        goto after_2;
    // 0x800BD78C: nop

    after_2:
    // 0x800BD790: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800BD794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD798: sw          $t6, 0x2584($at)
    MEM_W(0X2584, ctx->r1) = ctx->r14;
    // 0x800BD79C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BD7A0: sw          $zero, -0x7F8($at)
    MEM_W(-0X7F8, ctx->r1) = 0;
    // 0x800BD7A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BD7A8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BD7AC: addiu       $a2, $a2, 0x7A18
    ctx->r6 = ADD32(ctx->r6, 0X7A18);
    // 0x800BD7B0: addiu       $a1, $a1, 0x7B30
    ctx->r5 = ADD32(ctx->r5, 0X7B30);
    // 0x800BD7B4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800BD7B8: jal         0x800CB410
    // 0x800BD7BC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x800BD7BC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_3:
    // 0x800BD7C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD7C4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BD7C8: addiu       $a1, $a1, 0x7B78
    ctx->r5 = ADD32(ctx->r5, 0X7B78);
    // 0x800BD7CC: addiu       $a0, $a0, 0x7BC0
    ctx->r4 = ADD32(ctx->r4, 0X7BC0);
    // 0x800BD7D0: jal         0x800C42B0
    // 0x800BD7D4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800BD7D4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x800BD7D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BD7DC:
    // 0x800BD7DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD7E0: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x800BD7E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BD7E8: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x800BD7EC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BD7F0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800BD7F4: addiu       $t1, $t1, -0x6C10
    ctx->r9 = ADD32(ctx->r9, -0X6C10);
    // 0x800BD7F8: addiu       $t9, $t9, -0x7818
    ctx->r25 = ADD32(ctx->r25, -0X7818);
    // 0x800BD7FC: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x800BD800: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x800BD804: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800BD808: jal         0x800C42B0
    // 0x800BD80C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800BD80C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800BD810: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD814: nop

    // 0x800BD818: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BD81C: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x800BD820: bne         $at, $zero, L_800BD7DC
    if (ctx->r1 != 0) {
        // 0x800BD824: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_800BD7DC;
    }
    // 0x800BD824: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800BD828: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BD82C: sw          $zero, -0x6A0C($at)
    MEM_W(-0X6A0C, ctx->r1) = 0;
    // 0x800BD830: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800BD834: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800BD838: addiu       $a1, $a1, 0x1918
    ctx->r5 = ADD32(ctx->r5, 0X1918);
    // 0x800BD83C: addiu       $a0, $a0, 0x450
    ctx->r4 = ADD32(ctx->r4, 0X450);
    // 0x800BD840: jal         0x800C0640
    // 0x800BD844: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    Thread_CreateSimple(rdram, ctx);
        goto after_6;
    // 0x800BD844: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_6:
    // 0x800BD848: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BD84C: sb          $v0, -0x71C4($at)
    MEM_B(-0X71C4, ctx->r1) = ctx->r2;
    // 0x800BD850: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BD854: lbu         $t4, -0x71C4($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X71C4);
    // 0x800BD858: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BD85C: sb          $t4, 0x1918($at)
    MEM_B(0X1918, ctx->r1) = ctx->r12;
    // 0x800BD860: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BD864: lbu         $a0, -0x71C4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X71C4);
    // 0x800BD868: jal         0x800C0E04
    // 0x800BD86C: nop

    Thread_GetPtr(rdram, ctx);
        goto after_7;
    // 0x800BD86C: nop

    after_7:
    // 0x800BD870: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BD874: sw          $v0, 0x1930($at)
    MEM_W(0X1930, ctx->r1) = ctx->r2;
    // 0x800BD878: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x800BD87C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BD880: sw          $t5, 0x191C($at)
    MEM_W(0X191C, ctx->r1) = ctx->r13;
    // 0x800BD884: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD888: lw          $t6, 0x1698($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1698);
    // 0x800BD88C: nop

    // 0x800BD890: bne         $t6, $zero, L_800BD8A8
    if (ctx->r14 != 0) {
        // 0x800BD894: nop
    
            goto L_800BD8A8;
    }
    // 0x800BD894: nop

    // 0x800BD898: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BD89C: lbu         $a0, -0x71C4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X71C4);
    // 0x800BD8A0: jal         0x800C0C8C
    // 0x800BD8A4: nop

    Thread_Start(rdram, ctx);
        goto after_8;
    // 0x800BD8A4: nop

    after_8:
L_800BD8A8:
    // 0x800BD8A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BD8AC: jal         0x800CB5A0
    // 0x800BD8B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_9;
    // 0x800BD8B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_800BD8B4:
    // 0x800BD8B4: b           L_800BD8B4
    pause_self(rdram);
    // 0x800BD8B8: nop

    // 0x800BD8BC: b           L_800BD8C4
    // 0x800BD8C0: nop

        goto L_800BD8C4;
    // 0x800BD8C0: nop

L_800BD8C4:
    // 0x800BD8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD8C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BD8CC: jr          $ra
    // 0x800BD8D0: nop

    return;
    // 0x800BD8D0: nop

;}
RECOMP_FUNC void func_80078628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078628: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x8007862C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80078630: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x80078634: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    // 0x80078638: sw          $a2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r6;
    // 0x8007863C: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x80078640: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80078644: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80078648: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8007864C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80078650: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80078654: nop

    // 0x80078658: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007865C: nop

    // 0x80078660: bne         $t7, $zero, L_80078670
    if (ctx->r15 != 0) {
        // 0x80078664: nop
    
            goto L_80078670;
    }
    // 0x80078664: nop

    // 0x80078668: b           L_80078A7C
    // 0x8007866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078A7C;
    // 0x8007866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078670:
    // 0x80078670: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80078674: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80078678: lh          $t0, 0x106($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X106);
    // 0x8007867C: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x80078680: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80078684: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80078688: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8007868C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80078690: lh          $t4, 0x106($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X106);
    // 0x80078694: nop

    // 0x80078698: sh          $t4, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r12;
L_8007869C:
    // 0x8007869C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800786A0:
    // 0x800786A0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800786A4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800786A8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800786AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800786B0: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x800786B4: sh          $t6, 0x50($t0)
    MEM_H(0X50, ctx->r8) = ctx->r14;
    // 0x800786B8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800786BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800786C0: bne         $t1, $at, L_800786FC
    if (ctx->r9 != ctx->r1) {
        // 0x800786C4: nop
    
            goto L_800786FC;
    }
    // 0x800786C4: nop

    // 0x800786C8: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x800786CC: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x800786D0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800786D4: bne         $t2, $at, L_800786FC
    if (ctx->r10 != ctx->r1) {
        // 0x800786D8: nop
    
            goto L_800786FC;
    }
    // 0x800786D8: nop

    // 0x800786DC: lhu         $t3, 0x2($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X2);
    // 0x800786E0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800786E4: bne         $t3, $at, L_800786FC
    if (ctx->r11 != ctx->r1) {
        // 0x800786E8: nop
    
            goto L_800786FC;
    }
    // 0x800786E8: nop

    // 0x800786EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800786F0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800786F4: b           L_8007871C
    // 0x800786F8: nop

        goto L_8007871C;
    // 0x800786F8: nop

L_800786FC:
    // 0x800786FC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80078700: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80078704: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80078708: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x8007870C: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x80078710: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80078714: bne         $at, $zero, L_800786A0
    if (ctx->r1 != 0) {
        // 0x80078718: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800786A0;
    }
    // 0x80078718: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_8007871C:
    // 0x8007871C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80078720: nop

    // 0x80078724: beq         $t0, $zero, L_80078734
    if (ctx->r8 == 0) {
        // 0x80078728: nop
    
            goto L_80078734;
    }
    // 0x80078728: nop

    // 0x8007872C: b           L_80078A30
    // 0x80078730: nop

        goto L_80078A30;
    // 0x80078730: nop

L_80078734:
    // 0x80078734: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x80078738: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8007873C: nop

    // 0x80078740: andi        $t9, $t2, 0x8000
    ctx->r25 = ctx->r10 & 0X8000;
    // 0x80078744: beq         $t9, $zero, L_80078754
    if (ctx->r25 == 0) {
        // 0x80078748: nop
    
            goto L_80078754;
    }
    // 0x80078748: nop

    // 0x8007874C: b           L_80078A1C
    // 0x80078750: nop

        goto L_80078A1C;
    // 0x80078750: nop

L_80078754:
    // 0x80078754: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80078758: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x8007875C: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80078760: nop

    // 0x80078764: andi        $t5, $t4, 0xFF00
    ctx->r13 = ctx->r12 & 0XFF00;
    // 0x80078768: sh          $t5, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r13;
    // 0x8007876C: lhu         $s0, 0x3E($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X3E);
    // 0x80078770: nop

    // 0x80078774: beq         $s0, $zero, L_8007879C
    if (ctx->r16 == 0) {
        // 0x80078778: nop
    
            goto L_8007879C;
    }
    // 0x80078778: nop

    // 0x8007877C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80078780: beq         $s0, $at, L_800787C0
    if (ctx->r16 == ctx->r1) {
        // 0x80078784: nop
    
            goto L_800787C0;
    }
    // 0x80078784: nop

    // 0x80078788: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8007878C: beq         $s0, $at, L_800787E4
    if (ctx->r16 == ctx->r1) {
        // 0x80078790: nop
    
            goto L_800787E4;
    }
    // 0x80078790: nop

    // 0x80078794: b           L_80078808
    // 0x80078798: nop

        goto L_80078808;
    // 0x80078798: nop

L_8007879C:
    // 0x8007879C: lhu         $t6, 0x112($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X112);
    // 0x800787A0: nop

    // 0x800787A4: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800787A8: beq         $t8, $zero, L_800787B8
    if (ctx->r24 == 0) {
        // 0x800787AC: nop
    
            goto L_800787B8;
    }
    // 0x800787AC: nop

    // 0x800787B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800787B4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800787B8:
    // 0x800787B8: b           L_80078808
    // 0x800787BC: nop

        goto L_80078808;
    // 0x800787BC: nop

L_800787C0:
    // 0x800787C0: lhu         $t0, 0x112($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X112);
    // 0x800787C4: nop

    // 0x800787C8: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800787CC: beq         $t1, $zero, L_800787DC
    if (ctx->r9 == 0) {
        // 0x800787D0: nop
    
            goto L_800787DC;
    }
    // 0x800787D0: nop

    // 0x800787D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800787D8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800787DC:
    // 0x800787DC: b           L_80078808
    // 0x800787E0: nop

        goto L_80078808;
    // 0x800787E0: nop

L_800787E4:
    // 0x800787E4: lhu         $t9, 0x112($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X112);
    // 0x800787E8: nop

    // 0x800787EC: andi        $t3, $t9, 0x4
    ctx->r11 = ctx->r25 & 0X4;
    // 0x800787F0: beq         $t3, $zero, L_80078800
    if (ctx->r11 == 0) {
        // 0x800787F4: nop
    
            goto L_80078800;
    }
    // 0x800787F4: nop

    // 0x800787F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800787FC: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80078800:
    // 0x80078800: b           L_80078808
    // 0x80078804: nop

        goto L_80078808;
    // 0x80078804: nop

L_80078808:
    // 0x80078808: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8007880C: nop

    // 0x80078810: bne         $t5, $zero, L_80078820
    if (ctx->r13 != 0) {
        // 0x80078814: nop
    
            goto L_80078820;
    }
    // 0x80078814: nop

    // 0x80078818: b           L_80078A1C
    // 0x8007881C: nop

        goto L_80078A1C;
    // 0x8007881C: nop

L_80078820:
    // 0x80078820: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x80078824: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x80078828: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x8007882C: nop

    // 0x80078830: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80078834: beq         $at, $zero, L_80078878
    if (ctx->r1 == 0) {
        // 0x80078838: nop
    
            goto L_80078878;
    }
    // 0x80078838: nop

    // 0x8007883C: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x80078840: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80078844: addiu       $t2, $sp, 0xE4
    ctx->r10 = ADD32(ctx->r29, 0XE4);
    // 0x80078848: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8007884C: nop

    // 0x80078850: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078854: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80078858: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x8007885C: lh          $t3, 0x4($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X4);
    // 0x80078860: addiu       $t4, $sp, 0xE4
    ctx->r12 = ADD32(ctx->r29, 0XE4);
    // 0x80078864: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80078868: nop

    // 0x8007886C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80078870: b           L_800788B0
    // 0x80078874: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
        goto L_800788B0;
    // 0x80078874: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
L_80078878:
    // 0x80078878: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x8007887C: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80078880: addiu       $t8, $sp, 0xE4
    ctx->r24 = ADD32(ctx->r29, 0XE4);
    // 0x80078884: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80078888: nop

    // 0x8007888C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80078890: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x80078894: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x80078898: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x8007889C: addiu       $t1, $sp, 0xE4
    ctx->r9 = ADD32(ctx->r29, 0XE4);
    // 0x800788A0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800788A4: nop

    // 0x800788A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800788AC: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
L_800788B0:
    // 0x800788B0: addiu       $t2, $sp, 0x50
    ctx->r10 = ADD32(ctx->r29, 0X50);
    // 0x800788B4: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x800788B8: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x800788BC: nop

    // 0x800788C0: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800788C4: beq         $at, $zero, L_80078908
    if (ctx->r1 == 0) {
        // 0x800788C8: nop
    
            goto L_80078908;
    }
    // 0x800788C8: nop

    // 0x800788CC: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x800788D0: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x800788D4: addiu       $t6, $sp, 0xE4
    ctx->r14 = ADD32(ctx->r29, 0XE4);
    // 0x800788D8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800788DC: nop

    // 0x800788E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800788E4: swc1        $f10, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f10.u32l;
    // 0x800788E8: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x800788EC: lh          $t7, 0x6($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X6);
    // 0x800788F0: addiu       $t0, $sp, 0xE4
    ctx->r8 = ADD32(ctx->r29, 0XE4);
    // 0x800788F4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800788F8: nop

    // 0x800788FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80078900: b           L_80078940
    // 0x80078904: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
        goto L_80078940;
    // 0x80078904: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
L_80078908:
    // 0x80078908: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x8007890C: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x80078910: addiu       $t9, $sp, 0xE4
    ctx->r25 = ADD32(ctx->r29, 0XE4);
    // 0x80078914: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80078918: nop

    // 0x8007891C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078920: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x80078924: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x80078928: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x8007892C: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
    // 0x80078930: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80078934: nop

    // 0x80078938: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007893C: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
L_80078940:
    // 0x80078940: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80078944: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80078948: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8007894C: blez        $t8, L_800789E0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80078950: nop
    
            goto L_800789E0;
    }
    // 0x80078950: nop

L_80078954:
    // 0x80078954: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80078958: nop

    // 0x8007895C: bgez        $t7, L_80078970
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80078960: andi        $t0, $t7, 0x1
        ctx->r8 = ctx->r15 & 0X1;
            goto L_80078970;
    }
    // 0x80078960: andi        $t0, $t7, 0x1
    ctx->r8 = ctx->r15 & 0X1;
    // 0x80078964: beq         $t0, $zero, L_80078970
    if (ctx->r8 == 0) {
        // 0x80078968: nop
    
            goto L_80078970;
    }
    // 0x80078968: nop

    // 0x8007896C: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_80078970:
    // 0x80078970: bne         $t0, $zero, L_800789A0
    if (ctx->r8 != 0) {
        // 0x80078974: nop
    
            goto L_800789A0;
    }
    // 0x80078974: nop

    // 0x80078978: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8007897C: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80078980: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80078984: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x80078988: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8007898C: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80078990: addu        $t4, $sp, $t9
    ctx->r12 = ADD32(ctx->r29, ctx->r25);
    // 0x80078994: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80078998: b           L_800789C4
    // 0x8007899C: swc1        $f4, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f4.u32l;
        goto L_800789C4;
    // 0x8007899C: swc1        $f4, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f4.u32l;
L_800789A0:
    // 0x800789A0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800789A4: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x800789A8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800789AC: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800789B0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800789B4: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800789B8: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x800789BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800789C0: swc1        $f10, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f10.u32l;
L_800789C4:
    // 0x800789C4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800789C8: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x800789CC: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800789D0: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800789D4: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800789D8: bne         $at, $zero, L_80078954
    if (ctx->r1 != 0) {
        // 0x800789DC: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_80078954;
    }
    // 0x800789DC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
L_800789E0:
    // 0x800789E0: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x800789E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800789E8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x800789EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800789F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800789F4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800789F8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800789FC: jal         0x80078A8C
    // 0x80078A00: addiu       $a3, $sp, 0xE4
    ctx->r7 = ADD32(ctx->r29, 0XE4);
    func_80078A8C(rdram, ctx);
        goto after_0;
    // 0x80078A00: addiu       $a3, $sp, 0xE4
    ctx->r7 = ADD32(ctx->r29, 0XE4);
    after_0:
    // 0x80078A04: beq         $v0, $zero, L_80078A1C
    if (ctx->r2 == 0) {
        // 0x80078A08: nop
    
            goto L_80078A1C;
    }
    // 0x80078A08: nop

    // 0x80078A0C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80078A10: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80078A14: b           L_80078A30
    // 0x80078A18: nop

        goto L_80078A30;
    // 0x80078A18: nop

L_80078A1C:
    // 0x80078A1C: lh          $t7, 0xF6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XF6);
    // 0x80078A20: nop

    // 0x80078A24: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80078A28: b           L_8007869C
    // 0x80078A2C: sh          $t8, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r24;
        goto L_8007869C;
    // 0x80078A2C: sh          $t8, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r24;
L_80078A30:
    // 0x80078A30: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80078A34: nop

    // 0x80078A38: bne         $t0, $zero, L_80078A48
    if (ctx->r8 != 0) {
        // 0x80078A3C: nop
    
            goto L_80078A48;
    }
    // 0x80078A3C: nop

    // 0x80078A40: b           L_80078A7C
    // 0x80078A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078A7C;
    // 0x80078A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078A48:
    // 0x80078A48: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x80078A4C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80078A50: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x80078A54: lh          $a2, 0xF6($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XF6);
    // 0x80078A58: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    // 0x80078A5C: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    // 0x80078A60: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80078A64: jal         0x80079404
    // 0x80078A68: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_80079404(rdram, ctx);
        goto after_1;
    // 0x80078A68: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_1:
    // 0x80078A6C: b           L_80078A7C
    // 0x80078A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078A7C;
    // 0x80078A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078A74: b           L_80078A7C
    // 0x80078A78: nop

        goto L_80078A7C;
    // 0x80078A78: nop

L_80078A7C:
    // 0x80078A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078A80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80078A84: jr          $ra
    // 0x80078A88: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80078A88: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80056B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056B74: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80056B78: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056B7C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056B80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80056B84: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x80056B88: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056B8C: nop
    
            goto L_80056BC8;
    }
    // 0x80056B8C: nop

    // 0x80056B90: addiu       $at, $zero, 0x79
    ctx->r1 = ADD32(0, 0X79);
    // 0x80056B94: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056B98: nop
    
            goto L_80056BC8;
    }
    // 0x80056B98: nop

    // 0x80056B9C: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    // 0x80056BA0: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056BA4: nop
    
            goto L_80056BC8;
    }
    // 0x80056BA4: nop

    // 0x80056BA8: addiu       $at, $zero, 0x7B
    ctx->r1 = ADD32(0, 0X7B);
    // 0x80056BAC: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056BB0: nop
    
            goto L_80056BC8;
    }
    // 0x80056BB0: nop

    // 0x80056BB4: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x80056BB8: beq         $a1, $at, L_80056BC8
    if (ctx->r5 == ctx->r1) {
        // 0x80056BBC: nop
    
            goto L_80056BC8;
    }
    // 0x80056BBC: nop

    // 0x80056BC0: b           L_80056BFC
    // 0x80056BC4: nop

        goto L_80056BFC;
    // 0x80056BC4: nop

L_80056BC8:
    // 0x80056BC8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056BCC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80056BD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056BD4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80056BD8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80056BDC: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80056BE0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80056BE4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80056BE8: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80056BEC: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80056BF0: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80056BF4: b           L_80056BFC
    // 0x80056BF8: nop

        goto L_80056BFC;
    // 0x80056BF8: nop

L_80056BFC:
    // 0x80056BFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056C00: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80056C04: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80056C08: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80056C0C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80056C10: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80056C14: bne         $t4, $zero, L_80056C24
    if (ctx->r12 != 0) {
        // 0x80056C18: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_80056C24;
    }
    // 0x80056C18: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80056C1C: beq         $t5, $zero, L_80056C50
    if (ctx->r13 == 0) {
        // 0x80056C20: nop
    
            goto L_80056C50;
    }
    // 0x80056C20: nop

L_80056C24:
    // 0x80056C24: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80056C28: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80056C2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056C30: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80056C34: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80056C38: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x80056C3C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80056C40: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80056C44: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x80056C48: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80056C4C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_80056C50:
    // 0x80056C50: b           L_80056C58
    // 0x80056C54: nop

        goto L_80056C58;
    // 0x80056C54: nop

L_80056C58:
    // 0x80056C58: jr          $ra
    // 0x80056C5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056C5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
