#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800C4D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4D78: nop

    // 0x800C4D7C: nop

;}
RECOMP_FUNC void func_800C4E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4E44: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800C4E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4E4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C4E50: addiu       $t6, $t6, -0x500
    ctx->r14 = ADD32(ctx->r14, -0X500);
    // 0x800C4E54: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800C4E58: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C4E5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C4E60: jal         0x800CCC80
    // 0x800C4E64: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4E64: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x800C4E68: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4E6C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x800C4E70: beq         $t8, $zero, L_800C4E88
    if (ctx->r24 == 0) {
        // 0x800C4E74: nop

            goto L_800C4E88;
    }
    // 0x800C4E74: nop

    // 0x800C4E78: jal         0x800C79C0
    // 0x800C4E7C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800C4E7C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800C4E80: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4E84: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
L_800C4E88:
    // 0x800C4E88: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4E8C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x800C4E90: beq         $t1, $zero, L_800C4EA8
    if (ctx->r9 == 0) {
        // 0x800C4E94: nop

            goto L_800C4EA8;
    }
    // 0x800C4E94: nop

    // 0x800C4E98: jal         0x800C79C0
    // 0x800C4E9C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800C4E9C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x800C4EA0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EA4: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
L_800C4EA8:
    // 0x800C4EA8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EAC: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x800C4EB0: beq         $t4, $zero, L_800C4EC8
    if (ctx->r12 == 0) {
        // 0x800C4EB4: nop

            goto L_800C4EC8;
    }
    // 0x800C4EB4: nop

    // 0x800C4EB8: jal         0x800C79C0
    // 0x800C4EBC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800C4EBC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x800C4EC0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EC4: sw          $v0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r2;
L_800C4EC8:
    // 0x800C4EC8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4ECC: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800C4ED0: beq         $t7, $zero, L_800C4EE8
    if (ctx->r15 == 0) {
        // 0x800C4ED4: nop

            goto L_800C4EE8;
    }
    // 0x800C4ED4: nop

    // 0x800C4ED8: jal         0x800C79C0
    // 0x800C4EDC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800C4EDC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x800C4EE0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EE4: sw          $v0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r2;
L_800C4EE8:
    // 0x800C4EE8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EEC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x800C4EF0: beq         $t0, $zero, L_800C4F08
    if (ctx->r8 == 0) {
        // 0x800C4EF4: nop

            goto L_800C4F08;
    }
    // 0x800C4EF4: nop

    // 0x800C4EF8: jal         0x800C79C0
    // 0x800C4EFC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800C4EFC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x800C4F00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F04: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
L_800C4F08:
    // 0x800C4F08: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F0C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x800C4F10: beq         $t3, $zero, L_800C4F28
    if (ctx->r11 == 0) {
        // 0x800C4F14: nop

            goto L_800C4F28;
    }
    // 0x800C4F14: nop

    // 0x800C4F18: jal         0x800C79C0
    // 0x800C4F1C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800C4F1C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x800C4F20: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F24: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_800C4F28:
    // 0x800C4F28: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F2C: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x800C4F30: beq         $t6, $zero, L_800C4F48
    if (ctx->r14 == 0) {
        // 0x800C4F34: nop

            goto L_800C4F48;
    }
    // 0x800C4F34: nop

    // 0x800C4F38: jal         0x800C79C0
    // 0x800C4F3C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800C4F3C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_7:
    // 0x800C4F40: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F44: sw          $v0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r2;
L_800C4F48:
    // 0x800C4F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4F4C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4F54: jr          $ra
    // 0x800C4F58: nop

    return;
    // 0x800C4F58: nop

;}
RECOMP_FUNC void func_800C50FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C50FC: nop

;}
RECOMP_FUNC void func_800C51A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C51A8: nop

    // 0x800C51AC: nop

;}
RECOMP_FUNC void func_800C558C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C558C: nop

;}
RECOMP_FUNC void func_800C56FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56FC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C5700: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800C5704: addiu       $t6, $t6, -0x4C0
    ctx->r14 = ADD32(ctx->r14, -0X4C0);
    // 0x800C5708: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C570C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C5710:
    // 0x800C5710: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800C5714: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800C5718: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C571C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C5720: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C5724: sw          $zero, -0x4C0($at)
    MEM_W(-0X4C0, ctx->r1) = 0;
    // 0x800C5728: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C572C: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800C5730: bne         $at, $zero, L_800C5710
    if (ctx->r1 != 0) {
        // 0x800C5734: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_800C5710;
    }
    // 0x800C5734: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800C5738: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800C573C: lbu         $t9, -0x47F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X47F);
    // 0x800C5740: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C5744: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C5748: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C574C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C5750: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C5754: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C5758: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800C575C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C5760: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C5764: sw          $t1, -0x484($at)
    MEM_W(-0X484, ctx->r1) = ctx->r9;
    // 0x800C5768: sb          $t2, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r10;
    // 0x800C576C: sb          $t3, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r11;
    // 0x800C5770: sb          $t4, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r12;
    // 0x800C5774: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
    // 0x800C5778: sh          $t6, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r14;
    // 0x800C577C: sb          $t7, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r15;
    // 0x800C5780: sb          $t8, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r24;
    // 0x800C5784: blez        $t9, L_800C57D4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C5788: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_800C57D4;
    }
    // 0x800C5788: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C578C:
    // 0x800C578C: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x800C5790: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x800C5794: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C5798: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800C579C: swl         $at, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r1);
    // 0x800C57A0: swr         $at, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r1);
    // 0x800C57A4: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x800C57A8: swl         $t3, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r11);
    // 0x800C57AC: swr         $t3, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r11);
    // 0x800C57B0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C57B4: lbu         $t8, -0x47F($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X47F);
    // 0x800C57B8: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C57BC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C57C0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C57C4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C57C8: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800C57CC: bne         $at, $zero, L_800C578C
    if (ctx->r1 != 0) {
        // 0x800C57D0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C578C;
    }
    // 0x800C57D0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_800C57D4:
    // 0x800C57D4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C57D8: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x800C57DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800C57E0: jr          $ra
    // 0x800C57E4: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    return;
    // 0x800C57E4: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x800C57E8: nop

    // 0x800C57EC: nop

;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C74: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C5C78: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5C80: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C5C84: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800C5C88: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800C5C8C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800C5C90: blez        $t6, L_800C5CA4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C5C94: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800C5CA4;
    }
    // 0x800C5C94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C5C98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C5C9C: b           L_800C5CB0
    // 0x800C5CA0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_800C5CB0;
    // 0x800C5CA0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800C5CA4:
    // 0x800C5CA4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800C5CA8: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x800C5CAC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800C5CB0:
    // 0x800C5CB0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C5CB4: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800C5CB8: beq         $at, $zero, L_800C5CF4
    if (ctx->r1 == 0) {
        // 0x800C5CBC: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800C5CF4;
    }
    // 0x800C5CBC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_800C5CC0:
    // 0x800C5CC0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5CC4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800C5CC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C5CCC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800C5CD0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C5CD4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800C5CD8: beq         $t5, $at, L_800C5CF4
    if (ctx->r13 == ctx->r1) {
        // 0x800C5CDC: nop

            goto L_800C5CF4;
    }
    // 0x800C5CDC: nop

    // 0x800C5CE0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5CE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C5CE8: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800C5CEC: bne         $at, $zero, L_800C5CC0
    if (ctx->r1 != 0) {
        // 0x800C5CF0: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_800C5CC0;
    }
    // 0x800C5CF0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800C5CF4:
    // 0x800C5CF4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5CF8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800C5CFC: bne         $t8, $at, L_800C5D18
    if (ctx->r24 != ctx->r1) {
        // 0x800C5D00: nop

            goto L_800C5D18;
    }
    // 0x800C5D00: nop

    // 0x800C5D04: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800C5D08: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800C5D0C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C5D10: b           L_800C5EC8
    // 0x800C5D14: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800C5EC8;
    // 0x800C5D14: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800C5D18:
    // 0x800C5D18: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800C5D1C:
    // 0x800C5D1C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C5D20: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x800C5D24: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x800C5D28: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C5D2C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C5D30: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x800C5D34: bne         $at, $zero, L_800C5D1C
    if (ctx->r1 != 0) {
        // 0x800C5D38: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800C5D1C;
    }
    // 0x800C5D38: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800C5D3C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5D40: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800C5D44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C5D48: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800C5D4C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800C5D50: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5D54: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800C5D58: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800C5D5C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C5D60: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800C5D64: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800C5D68: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800C5D6C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C5D70: beq         $at, $zero, L_800C5E44
    if (ctx->r1 == 0) {
        // 0x800C5D74: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_800C5E44;
    }
    // 0x800C5D74: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800C5D78: beq         $at, $zero, L_800C5E44
    if (ctx->r1 == 0) {
        // 0x800C5D7C: nop

            goto L_800C5E44;
    }
    // 0x800C5D7C: nop

L_800C5D80:
    // 0x800C5D80: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5D84: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800C5D88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C5D8C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800C5D90: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800C5D94: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800C5D98: bne         $t7, $at, L_800C5E10
    if (ctx->r15 != ctx->r1) {
        // 0x800C5D9C: nop

            goto L_800C5E10;
    }
    // 0x800C5D9C: nop

    // 0x800C5DA0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800C5DA4: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5DA8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800C5DAC: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800C5DB0: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800C5DB4: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x800C5DB8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800C5DBC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800C5DC0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5DC4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C5DC8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800C5DCC: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800C5DD0: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5DD4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800C5DD8: jal         0x800C5ED8
    // 0x800C5DDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    __osClearPage(rdram, ctx);
        goto after_0;
    // 0x800C5DDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800C5DE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C5DE4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5DE8: beq         $t2, $zero, L_800C5DF8
    if (ctx->r10 == 0) {
        // 0x800C5DEC: nop

            goto L_800C5DF8;
    }
    // 0x800C5DEC: nop

    // 0x800C5DF0: b           L_800C5EC8
    // 0x800C5DF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800C5EC8;
    // 0x800C5DF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800C5DF8:
    // 0x800C5DF8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5DFC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800C5E00: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800C5E04: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800C5E08: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800C5E0C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_800C5E10:
    // 0x800C5E10: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5E14: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800C5E18: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800C5E1C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800C5E20: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800C5E24: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800C5E28: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C5E2C: beq         $at, $zero, L_800C5E44
    if (ctx->r1 == 0) {
        // 0x800C5E30: nop

            goto L_800C5E44;
    }
    // 0x800C5E30: nop

    // 0x800C5E34: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5E38: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800C5E3C: bne         $at, $zero, L_800C5D80
    if (ctx->r1 != 0) {
        // 0x800C5E40: nop

            goto L_800C5D80;
    }
    // 0x800C5E40: nop

L_800C5E44:
    // 0x800C5E44: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800C5E48: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800C5E4C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800C5E50: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800C5E54: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5E58: bne         $t1, $at, L_800C5E8C
    if (ctx->r9 != ctx->r1) {
        // 0x800C5E5C: nop

            goto L_800C5E8C;
    }
    // 0x800C5E5C: nop

    // 0x800C5E60: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800C5E64: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800C5E68: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800C5E6C: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C5E70: beq         $at, $zero, L_800C5E8C
    if (ctx->r1 == 0) {
        // 0x800C5E74: nop

            goto L_800C5E8C;
    }
    // 0x800C5E74: nop

    // 0x800C5E78: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800C5E7C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800C5E80: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800C5E84: b           L_800C5EC8
    // 0x800C5E88: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800C5EC8;
    // 0x800C5E88: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800C5E8C:
    // 0x800C5E8C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800C5E90: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800C5E94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C5E98: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800C5E9C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800C5EA0: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x800C5EA4: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5EA8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800C5EAC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800C5EB0: jal         0x800C5ED8
    // 0x800C5EB4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    __osClearPage(rdram, ctx);
        goto after_1;
    // 0x800C5EB4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800C5EB8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800C5EBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C5EC0: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800C5EC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800C5EC8:
    // 0x800C5EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5ECC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800C5ED0: jr          $ra
    // 0x800C5ED4: nop

    return;
    // 0x800C5ED4: nop

;}
RECOMP_FUNC void __osClearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5ED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C5EDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C5EE0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C5EE4: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800C5EE8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C5EEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5EF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C5EF4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C5EF8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C5EFC: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800C5F00: jal         0x800CE34C
    // 0x800C5F04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800C5F04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800C5F08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C5F0C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C5F10: beq         $t8, $zero, L_800C5F20
    if (ctx->r24 == 0) {
        // 0x800C5F14: nop

            goto L_800C5F20;
    }
    // 0x800C5F14: nop

    // 0x800C5F18: b           L_800C5F88
    // 0x800C5F1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800C5F88;
    // 0x800C5F1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C5F20:
    // 0x800C5F20: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800C5F24:
    // 0x800C5F24: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F28: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5F2C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C5F30: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800C5F34: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800C5F38: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C5F3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C5F40: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800C5F44: jal         0x800CE580
    // 0x800C5F48: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x800C5F48: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800C5F4C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C5F50: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C5F54: bne         $t3, $zero, L_800C5F70
    if (ctx->r11 != 0) {
        // 0x800C5F58: nop

            goto L_800C5F70;
    }
    // 0x800C5F58: nop

    // 0x800C5F5C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800C5F60: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C5F64: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x800C5F68: bne         $at, $zero, L_800C5F24
    if (ctx->r1 != 0) {
        // 0x800C5F6C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800C5F24;
    }
    // 0x800C5F6C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800C5F70:
    // 0x800C5F70: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F74: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x800C5F78: jal         0x800CE34C
    // 0x800C5F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800C5F80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C5F84: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800C5F88:
    // 0x800C5F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C5F90: jr          $ra
    // 0x800C5F94: nop

    return;
    // 0x800C5F94: nop

;}
RECOMP_FUNC void func_800C5F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5F98: nop

    // 0x800C5F9C: nop

;}
RECOMP_FUNC void __osPackResetData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6098: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C609C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C60A0:
    // 0x800C60A0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C60A4: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800C60A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C60AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C60B0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C60B4: sw          $zero, -0x4C0($at)
    MEM_W(-0X4C0, ctx->r1) = 0;
    // 0x800C60B8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C60BC: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800C60C0: bne         $at, $zero, L_800C60A0
    if (ctx->r1 != 0) {
        // 0x800C60C4: sw          $t9, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r25;
            goto L_800C60A0;
    }
    // 0x800C60C4: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x800C60C8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800C60CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C60D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C60D4: addiu       $t1, $t1, -0x4C0
    ctx->r9 = ADD32(ctx->r9, -0X4C0);
    // 0x800C60D8: sw          $t0, -0x484($at)
    MEM_W(-0X484, ctx->r1) = ctx->r8;
    // 0x800C60DC: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C60E0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C60E4:
    // 0x800C60E4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C60E8: addiu       $t2, $zero, 0xFD
    ctx->r10 = ADD32(0, 0XFD);
    // 0x800C60EC: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x800C60F0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C60F4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C60F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C60FC: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800C6100: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C6104: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800C6108: bne         $at, $zero, L_800C60E4
    if (ctx->r1 != 0) {
        // 0x800C610C: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_800C60E4;
    }
    // 0x800C610C: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800C6110: jr          $ra
    // 0x800C6114: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C6114: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C6118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6118: nop

    // 0x800C611C: nop

;}
RECOMP_FUNC void func_800C648C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C648C: nop

;}
RECOMP_FUNC void func_800C6794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6794: nop

    // 0x800C6798: nop

    // 0x800C679C: nop

;}
RECOMP_FUNC void func_800C6BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6BDC: nop

;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C6EC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C6EC8: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x800C6ECC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C6ED0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6ED4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C6ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6EDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C6EE0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C6EE4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C6EE8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800C6EEC: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x800C6EF0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800C6EF4: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x800C6EF8: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x800C6EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6F00: beq         $t4, $at, L_800C6F30
    if (ctx->r12 == ctx->r1) {
        // 0x800C6F04: nop

            goto L_800C6F30;
    }
    // 0x800C6F04: nop

    // 0x800C6F08: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x800C6F0C: blez        $t5, L_800C6F20
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800C6F10: nop

            goto L_800C6F20;
    }
    // 0x800C6F10: nop

    // 0x800C6F14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C6F18: b           L_800C6F54
    // 0x800C6F1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_800C6F54;
    // 0x800C6F1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_800C6F20:
    // 0x800C6F20: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C6F24: lw          $t9, 0x60($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X60);
    // 0x800C6F28: b           L_800C6F54
    // 0x800C6F2C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_800C6F54;
    // 0x800C6F2C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800C6F30:
    // 0x800C6F30: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C6F34: blez        $t2, L_800C6F48
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800C6F38: nop

            goto L_800C6F48;
    }
    // 0x800C6F38: nop

    // 0x800C6F3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C6F40: b           L_800C6F54
    // 0x800C6F44: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_800C6F54;
    // 0x800C6F44: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_800C6F48:
    // 0x800C6F48: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C6F4C: lw          $t0, 0x60($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X60);
    // 0x800C6F50: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800C6F54:
    // 0x800C6F54: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x800C6F58: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C6F5C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C6F60: beq         $at, $zero, L_800C6F80
    if (ctx->r1 == 0) {
        // 0x800C6F64: nop

            goto L_800C6F80;
    }
    // 0x800C6F64: nop

    // 0x800C6F68: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x800C6F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6F70: beq         $t5, $at, L_800C6F80
    if (ctx->r13 == ctx->r1) {
        // 0x800C6F74: nop

            goto L_800C6F80;
    }
    // 0x800C6F74: nop

    // 0x800C6F78: b           L_800C70E8
    // 0x800C6F7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800C70E8;
    // 0x800C6F7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800C6F80:
    // 0x800C6F80: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x800C6F84: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x800C6F88: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6F8C: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x800C6F90: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800C6F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6F98: bne         $t1, $at, L_800C6FB8
    if (ctx->r9 != ctx->r1) {
        // 0x800C6F9C: nop

            goto L_800C6FB8;
    }
    // 0x800C6F9C: nop

    // 0x800C6FA0: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800C6FA4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6FA8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800C6FAC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800C6FB0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800C6FB4: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_800C6FB8:
    // 0x800C6FB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6FBC: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x800C6FC0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C6FC4: jal         0x800C70F8
    // 0x800C6FC8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x800C6FC8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800C6FCC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C6FD0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6FD4: beq         $t9, $zero, L_800C6FE4
    if (ctx->r25 == 0) {
        // 0x800C6FD8: nop

            goto L_800C6FE4;
    }
    // 0x800C6FD8: nop

    // 0x800C6FDC: b           L_800C70E8
    // 0x800C6FE0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800C70E8;
    // 0x800C6FE0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800C6FE4:
    // 0x800C6FE4: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800C6FE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6FEC: bne         $t8, $at, L_800C6FFC
    if (ctx->r24 != ctx->r1) {
        // 0x800C6FF0: nop

            goto L_800C6FFC;
    }
    // 0x800C6FF0: nop

    // 0x800C6FF4: b           L_800C70E8
    // 0x800C6FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C70E8;
    // 0x800C6FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C6FFC:
    // 0x800C6FFC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800C7000: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x800C7004: lw          $t1, 0x60($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X60);
    // 0x800C7008: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C700C: bne         $at, $zero, L_800C70A4
    if (ctx->r1 != 0) {
        // 0x800C7010: nop

            goto L_800C70A4;
    }
    // 0x800C7010: nop

L_800C7014:
    // 0x800C7014: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x800C7018: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x800C701C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7020: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800C7024: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x800C7028: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800C702C: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x800C7030: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800C7034: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800C7038: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x800C703C: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x800C7040: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7044: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800C7048: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x800C704C: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x800C7050: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C7054: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C7058: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x800C705C: jal         0x800C70F8
    // 0x800C7060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x800C7060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800C7064: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C7068: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C706C: beq         $t5, $zero, L_800C707C
    if (ctx->r13 == 0) {
        // 0x800C7070: nop

            goto L_800C707C;
    }
    // 0x800C7070: nop

    // 0x800C7074: b           L_800C70E8
    // 0x800C7078: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800C70E8;
    // 0x800C7078: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800C707C:
    // 0x800C707C: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x800C7080: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C7084: bne         $t8, $t0, L_800C70A4
    if (ctx->r24 != ctx->r8) {
        // 0x800C7088: nop

            goto L_800C70A4;
    }
    // 0x800C7088: nop

    // 0x800C708C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800C7090: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800C7094: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800C7098: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800C709C: beq         $at, $zero, L_800C7014
    if (ctx->r1 == 0) {
        // 0x800C70A0: nop

            goto L_800C7014;
    }
    // 0x800C70A0: nop

L_800C70A4:
    // 0x800C70A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C70A8: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x800C70AC: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x800C70B0: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C70B4: bne         $at, $zero, L_800C70D4
    if (ctx->r1 != 0) {
        // 0x800C70B8: nop

            goto L_800C70D4;
    }
    // 0x800C70B8: nop

    // 0x800C70BC: lbu         $t8, 0x25($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X25);
    // 0x800C70C0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C70C4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800C70C8: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800C70CC: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x800C70D0: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
L_800C70D4:
    // 0x800C70D4: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800C70D8: lhu         $at, 0x0($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0X0);
    // 0x800C70DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800C70E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C70E4: sh          $at, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r1;
L_800C70E8:
    // 0x800C70E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C70EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C70F0: jr          $ra
    // 0x800C70F4: nop

    return;
    // 0x800C70F4: nop

;}
RECOMP_FUNC void __osBlockSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C70F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C70FC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800C7100: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800C7104: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x800C7108: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800C710C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7110: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C7114: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800C7118: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800C711C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800C7120: jal         0x800CE34C
    // 0x800C7124: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7124: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800C7128: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C712C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800C7130: beq         $t8, $zero, L_800C7140
    if (ctx->r24 == 0) {
        // 0x800C7134: nop

            goto L_800C7140;
    }
    // 0x800C7134: nop

    // 0x800C7138: b           L_800C71D8
    // 0x800C713C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800C71D8;
    // 0x800C713C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C7140:
    // 0x800C7140: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800C7144:
    // 0x800C7144: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x800C7148: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800C714C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7150: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C7154: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800C7158: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800C715C: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800C7160: jal         0x800CF390
    // 0x800C7164: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamRead_recomp(rdram, ctx);
        goto after_1;
    // 0x800C7164: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800C7168: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C716C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800C7170: beq         $t3, $zero, L_800C7190
    if (ctx->r11 == 0) {
        // 0x800C7174: nop

            goto L_800C7190;
    }
    // 0x800C7174: nop

    // 0x800C7178: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800C717C: sb          $zero, 0x65($t4)
    MEM_B(0X65, ctx->r12) = 0;
    // 0x800C7180: jal         0x800CE34C
    // 0x800C7184: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800C7184: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800C7188: b           L_800C71D8
    // 0x800C718C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800C71D8;
    // 0x800C718C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800C7190:
    // 0x800C7190: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C7194: jal         0x800CD660
    // 0x800C7198: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    __osSumcalc(rdram, ctx);
        goto after_3;
    // 0x800C7198: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x800C719C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800C71A0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800C71A4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800C71A8: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800C71AC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C71B0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C71B4: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800C71B8: bne         $at, $zero, L_800C7144
    if (ctx->r1 != 0) {
        // 0x800C71BC: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_800C7144;
    }
    // 0x800C71BC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800C71C0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800C71C4: sb          $zero, 0x65($t0)
    MEM_B(0X65, ctx->r8) = 0;
    // 0x800C71C8: jal         0x800CE34C
    // 0x800C71CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800C71CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800C71D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C71D4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800C71D8:
    // 0x800C71D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C71DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800C71E0: jr          $ra
    // 0x800C71E4: nop

    return;
    // 0x800C71E4: nop

;}
RECOMP_FUNC void func_800C71E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C71E8: nop

    // 0x800C71EC: nop

    // 0x800C71F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C71F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C71F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C71FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7200: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C7204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7208: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C720C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C7210: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800C7214: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800C7218: beq         $t7, $t9, L_800C7254
    if (ctx->r15 == ctx->r25) {
        // 0x800C721C: nop

            goto L_800C7254;
    }
    // 0x800C721C: nop

    // 0x800C7220: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800C7224: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800C7228: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C722C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C7230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C7234: jal         0x800CE02C
    // 0x800C7238: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    __osPfsRWInode_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7238: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    after_0:
    // 0x800C723C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C7240: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7244: beq         $t1, $zero, L_800C7254
    if (ctx->r9 == 0) {
        // 0x800C7248: nop

            goto L_800C7254;
    }
    // 0x800C7248: nop

    // 0x800C724C: b           L_800C72DC
    // 0x800C7250: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800C72DC;
    // 0x800C7250: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800C7254:
    // 0x800C7254: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7258: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800C725C: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x800C7260: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800C7264: addu        $t8, $t3, $t5
    ctx->r24 = ADD32(ctx->r11, ctx->r13);
    // 0x800C7268: lhu         $at, 0x0($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X0);
    // 0x800C726C: sh          $at, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r1;
    // 0x800C7270: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800C7274: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7278: lw          $t4, 0x60($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X60);
    // 0x800C727C: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800C7280: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C7284: bne         $at, $zero, L_800C72B4
    if (ctx->r1 != 0) {
        // 0x800C7288: nop

            goto L_800C72B4;
    }
    // 0x800C7288: nop

    // 0x800C728C: lbu         $t3, 0x0($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X0);
    // 0x800C7290: lbu         $t5, 0x64($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X64);
    // 0x800C7294: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C7298: beq         $at, $zero, L_800C72B4
    if (ctx->r1 == 0) {
        // 0x800C729C: nop

            goto L_800C72B4;
    }
    // 0x800C729C: nop

    // 0x800C72A0: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x800C72A4: blez        $t7, L_800C72B4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C72A8: slti        $at, $t7, 0x80
        ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
            goto L_800C72B4;
    }
    // 0x800C72A8: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800C72AC: bne         $at, $zero, L_800C72D8
    if (ctx->r1 != 0) {
        // 0x800C72B0: nop

            goto L_800C72D8;
    }
    // 0x800C72B0: nop

L_800C72B4:
    // 0x800C72B4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C72B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C72BC: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x800C72C0: bne         $t8, $at, L_800C72D0
    if (ctx->r24 != ctx->r1) {
        // 0x800C72C4: nop

            goto L_800C72D0;
    }
    // 0x800C72C4: nop

    // 0x800C72C8: b           L_800C72DC
    // 0x800C72CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800C72DC;
    // 0x800C72CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800C72D0:
    // 0x800C72D0: b           L_800C72DC
    // 0x800C72D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800C72DC;
    // 0x800C72D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800C72D8:
    // 0x800C72D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C72DC:
    // 0x800C72DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C72E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C72E4: jr          $ra
    // 0x800C72E8: nop

    return;
    // 0x800C72E8: nop

;}
RECOMP_FUNC void func_800C76EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76EC: nop

;}
RECOMP_FUNC void alHeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76F0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800C76F4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800C76F8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800C76FC: beq         $v1, $v0, L_800C770C
    if (ctx->r3 == ctx->r2) {
        // 0x800C7700: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800C770C;
    }
    // 0x800C7700: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800C7704: b           L_800C7710
    // 0x800C7708: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800C7710;
    // 0x800C7708: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800C770C:
    // 0x800C770C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800C7710:
    // 0x800C7710: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800C7714: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800C7718: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C771C: jr          $ra
    // 0x800C7720: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x800C7720: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_800C7724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7724: nop

    // 0x800C7728: nop

    // 0x800C772C: nop

;}
RECOMP_FUNC void alUnlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7890: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C7894: beql        $v0, $zero, L_800C78A8
    if (ctx->r2 == 0) {
        // 0x800C7898: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800C78A8;
    }
    goto skip_0;
    // 0x800C7898: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800C789C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C78A0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C78A4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800C78A8:
    // 0x800C78A8: beq         $v0, $zero, L_800C78B8
    if (ctx->r2 == 0) {
        // 0x800C78AC: nop

            goto L_800C78B8;
    }
    // 0x800C78AC: nop

    // 0x800C78B0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800C78B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800C78B8:
    // 0x800C78B8: jr          $ra
    // 0x800C78BC: nop

    return;
    // 0x800C78BC: nop

;}
RECOMP_FUNC void alLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78C0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C78C4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800C78C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C78CC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C78D0: beq         $v0, $zero, L_800C78DC
    if (ctx->r2 == 0) {
        // 0x800C78D4: nop

            goto L_800C78DC;
    }
    // 0x800C78D4: nop

    // 0x800C78D8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800C78DC:
    // 0x800C78DC: jr          $ra
    // 0x800C78E0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x800C78E0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void alClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78E4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C78E8: lw          $t6, -0x33E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33E0);
    // 0x800C78EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C78F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C78F4: beql        $t6, $zero, L_800C7910
    if (ctx->r14 == 0) {
        // 0x800C78F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7910;
    }
    goto skip_0;
    // 0x800C78F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C78FC: jal         0x800CF740
    // 0x800C7900: nop

    alSynDelete(rdram, ctx);
        goto after_0;
    // 0x800C7900: nop

    after_0:
    // 0x800C7904: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C7908: sw          $zero, -0x33E0($at)
    MEM_W(-0X33E0, ctx->r1) = 0;
    // 0x800C790C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C7910:
    // 0x800C7910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7914: jr          $ra
    // 0x800C7918: nop

    return;
    // 0x800C7918: nop

;}
RECOMP_FUNC void alInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C791C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C7920: addiu       $v0, $v0, -0x33E0
    ctx->r2 = ADD32(ctx->r2, -0X33E0);
    // 0x800C7924: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C7928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C792C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7930: bnel        $t6, $zero, L_800C7944
    if (ctx->r14 != 0) {
        // 0x800C7934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7944;
    }
    goto skip_0;
    // 0x800C7934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C7938: jal         0x800C7ED0
    // 0x800C793C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    alSynNew(rdram, ctx);
        goto after_0;
    // 0x800C793C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800C7940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C7944:
    // 0x800C7944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7948: jr          $ra
    // 0x800C794C: nop

    return;
    // 0x800C794C: nop

;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7950: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800C7954: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C7958: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C795C: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7960: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800C7964: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C7968: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C796C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800C7970: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C7974: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C7978: mflo        $v0
    ctx->r2 = lo;
    // 0x800C797C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800C7980: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800C7984: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7988: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800C798C: bne         $at, $zero, L_800C799C
    if (ctx->r1 != 0) {
        // 0x800C7990: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_800C799C;
    }
    // 0x800C7990: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7994: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7998: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_800C799C:
    // 0x800C799C: jr          $ra
    // 0x800C79A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C79A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800C79A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79A4: nop

    // 0x800C79A8: nop

    // 0x800C79AC: nop

;}
RECOMP_FUNC void func_800C79BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79BC: nop

;}
RECOMP_FUNC void func_800C7A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A3C: nop

;}
RECOMP_FUNC void func_800C7AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AE8: nop

    // 0x800C7AEC: nop

    // 0x800C7AF0: jr          $ra
    // 0x800C7AF4: nop

    return;
    // 0x800C7AF4: nop

;}
RECOMP_FUNC void _timeToSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AF8: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800C7AFC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C7B00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C7B04: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800C7B08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7B0C: ldc1        $f4, -0xA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XA0);
    // 0x800C7B10: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C7B14: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C7B18: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800C7B1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C7B20: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C7B24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C7B28: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C7B2C: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x800C7B30: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800C7B34: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800C7B38: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7B3C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C7B40: nop

    // 0x800C7B44: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x800C7B48: jr          $ra
    // 0x800C7B4C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800C7B4C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void _freePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C7B5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C7B60: jal         0x800C7890
    // 0x800C7B64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C7B64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800C7B68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C7B6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7B70: jal         0x800C78C0
    // 0x800C7B74: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C7B74: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x800C7B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7B80: jr          $ra
    // 0x800C7B84: nop

    return;
    // 0x800C7B84: nop

;}
RECOMP_FUNC void _collectPVoices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7B8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C7B90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C7B94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C7B98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C7B9C: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x800C7BA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C7BA4: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x800C7BA8: beql        $s0, $zero, L_800C7BD4
    if (ctx->r16 == 0) {
        // 0x800C7BAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C7BD4;
    }
    goto skip_0;
    // 0x800C7BAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800C7BB0:
    // 0x800C7BB0: jal         0x800C7890
    // 0x800C7BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C7BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C7BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7BBC: jal         0x800C78C0
    // 0x800C7BC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C7BC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800C7BC4: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x800C7BC8: bne         $s0, $zero, L_800C7BB0
    if (ctx->r16 != 0) {
        // 0x800C7BCC: nop

            goto L_800C7BB0;
    }
    // 0x800C7BCC: nop

    // 0x800C7BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C7BD4:
    // 0x800C7BD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7BD8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7BDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C7BE0: jr          $ra
    // 0x800C7BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C7BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __freeParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7BE8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C7BEC: lw          $v0, -0x33E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33E0);
    // 0x800C7BF0: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x800C7BF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C7BF8: jr          $ra
    // 0x800C7BFC: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    return;
    // 0x800C7BFC: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void __allocParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C00: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C7C04: lw          $v0, -0x33E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33E0);
    // 0x800C7C08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C7C0C: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x800C7C10: beq         $a0, $zero, L_800C7C28
    if (ctx->r4 == 0) {
        // 0x800C7C14: nop

            goto L_800C7C28;
    }
    // 0x800C7C14: nop

    // 0x800C7C18: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C7C1C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7C20: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x800C7C24: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800C7C28:
    // 0x800C7C28: jr          $ra
    // 0x800C7C2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C7C2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800C7C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C30: jr          $ra
    // 0x800C7C34: nop

    return;
    // 0x800C7C34: nop

;}
RECOMP_FUNC void alAudioFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C38: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C7C3C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800C7C40: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800C7C44: lw          $s1, -0x33E0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X33E0);
    // 0x800C7C48: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C7C4C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800C7C50: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800C7C54: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800C7C58: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800C7C5C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800C7C60: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800C7C64: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800C7C68: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800C7C6C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C7C70: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800C7C74: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800C7C78: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
    // 0x800C7C7C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800C7C80: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800C7C84: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800C7C88: bne         $t7, $zero, L_800C7C9C
    if (ctx->r15 != 0) {
        // 0x800C7C8C: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_800C7C9C;
    }
    // 0x800C7C8C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800C7C90: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C7C94: b           L_800C7E9C
    // 0x800C7C98: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800C7E9C;
    // 0x800C7C98: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800C7C9C:
    // 0x800C7C9C: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800C7CA0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C7CA4: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x800C7CA8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x800C7CAC: beq         $v0, $zero, L_800C7CE8
    if (ctx->r2 == 0) {
        // 0x800C7CB0: addiu       $s2, $zero, -0x10
        ctx->r18 = ADD32(0, -0X10);
            goto L_800C7CE8;
    }
    // 0x800C7CB0: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800C7CB4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7CB8: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
L_800C7CBC:
    // 0x800C7CBC: subu        $t0, $t9, $a0
    ctx->r8 = SUB32(ctx->r25, ctx->r4);
    // 0x800C7CC0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C7CC4: beql        $at, $zero, L_800C7CE0
    if (ctx->r1 == 0) {
        // 0x800C7CC8: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800C7CE0;
    }
    goto skip_0;
    // 0x800C7CC8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800C7CCC: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800C7CD0: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x800C7CD4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7CD8: subu        $v1, $t1, $a0
    ctx->r3 = SUB32(ctx->r9, ctx->r4);
    // 0x800C7CDC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800C7CE0:
    // 0x800C7CE0: bnel        $v0, $zero, L_800C7CBC
    if (ctx->r2 != 0) {
        // 0x800C7CE4: lw          $t9, 0x10($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X10);
            goto L_800C7CBC;
    }
    goto skip_1;
    // 0x800C7CE4: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    skip_1:
L_800C7CE8:
    // 0x800C7CE8: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800C7CEC: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7CF0: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x800C7CF4: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x800C7CF8: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C7CFC: beq         $at, $zero, L_800C7DE0
    if (ctx->r1 == 0) {
        // 0x800C7D00: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800C7DE0;
    }
    // 0x800C7D00: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800C7D04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C7D08: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800C7D0C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C7D10: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800C7D14: ldc1        $f20, -0x98($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X98);
L_800C7D18:
    // 0x800C7D18: lw          $t4, 0x1C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1C);
    // 0x800C7D1C: lui         $s0, 0x7FFF
    ctx->r16 = S32(0X7FFF << 16);
    // 0x800C7D20: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800C7D24: and         $t5, $t4, $s2
    ctx->r13 = ctx->r12 & ctx->r18;
    // 0x800C7D28: sw          $t5, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r13;
    // 0x800C7D2C: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x800C7D30: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C7D34: jalr        $t9
    // 0x800C7D38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800C7D38: nop

    after_0:
    // 0x800C7D3C: lw          $t8, 0x44($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X44);
    // 0x800C7D40: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800C7D44: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800C7D48: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C7D4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7D50: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x800C7D54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C7D58: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C7D5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C7D60: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d);
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x800C7D64: add.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d);
    ctx->f8.d = ctx->f4.d + ctx->f22.d;
    // 0x800C7D68: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800C7D6C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7D70: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C7D74: nop

    // 0x800C7D78: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800C7D7C: sw          $t2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r10;
    // 0x800C7D80: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800C7D84: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C7D88: beql        $v1, $zero, L_800C7DC8
    if (ctx->r3 == 0) {
        // 0x800C7D8C: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800C7DC8;
    }
    goto skip_2;
    // 0x800C7D8C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    skip_2:
    // 0x800C7D90: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7D94: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
L_800C7D98:
    // 0x800C7D98: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x800C7D9C: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C7DA0: beql        $at, $zero, L_800C7DBC
    if (ctx->r1 == 0) {
        // 0x800C7DA4: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800C7DBC;
    }
    goto skip_3;
    // 0x800C7DA4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800C7DA8: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    // 0x800C7DAC: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x800C7DB0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7DB4: subu        $s0, $t5, $a0
    ctx->r16 = SUB32(ctx->r13, ctx->r4);
    // 0x800C7DB8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800C7DBC:
    // 0x800C7DBC: bnel        $v1, $zero, L_800C7D98
    if (ctx->r3 != 0) {
        // 0x800C7DC0: lw          $t3, 0x10($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X10);
            goto L_800C7D98;
    }
    goto skip_4;
    // 0x800C7DC0: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    skip_4:
    // 0x800C7DC4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_800C7DC8:
    // 0x800C7DC8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7DCC: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x800C7DD0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800C7DD4: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C7DD8: bne         $at, $zero, L_800C7D18
    if (ctx->r1 != 0) {
        // 0x800C7DDC: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800C7D18;
    }
    // 0x800C7DDC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_800C7DE0:
    // 0x800C7DE0: lw          $t8, 0x1C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C);
    // 0x800C7DE4: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800C7DE8: addiu       $s7, $sp, 0xAA
    ctx->r23 = ADD32(ctx->r29, 0XAA);
    // 0x800C7DEC: and         $t6, $t8, $s2
    ctx->r14 = ctx->r24 & ctx->r18;
    // 0x800C7DF0: blez        $s3, L_800C7E7C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800C7DF4: sw          $t6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r14;
            goto L_800C7E7C;
    }
    // 0x800C7DF4: sw          $t6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r14;
    // 0x800C7DF8: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_800C7DFC:
    // 0x800C7DFC: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x800C7E00: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800C7E04: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C7E08: beq         $at, $zero, L_800C7E18
    if (ctx->r1 == 0) {
        // 0x800C7E0C: nop

            goto L_800C7E18;
    }
    // 0x800C7E0C: nop

    // 0x800C7E10: b           L_800C7E18
    // 0x800C7E14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800C7E18;
    // 0x800C7E14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C7E18:
    // 0x800C7E18: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x800C7E1C: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x800C7E20: lw          $s2, 0x38($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X38);
    // 0x800C7E24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800C7E28: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800C7E2C: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x800C7E30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C7E34: jalr        $t9
    // 0x800C7E38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C7E38: nop

    after_1:
    // 0x800C7E3C: lw          $a3, 0x20($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X20);
    // 0x800C7E40: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x800C7E44: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C7E48: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x800C7E4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C7E50: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800C7E54: jalr        $t9
    // 0x800C7E58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C7E58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800C7E5C: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x800C7E60: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x800C7E64: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800C7E68: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800C7E6C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800C7E70: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x800C7E74: bgtz        $s3, L_800C7DFC
    if (SIGNED(ctx->r19) > 0) {
        // 0x800C7E78: sw          $t4, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->r12;
            goto L_800C7DFC;
    }
    // 0x800C7E78: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
L_800C7E7C:
    // 0x800C7E7C: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800C7E80: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800C7E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C7E88: subu        $t7, $s4, $t5
    ctx->r15 = SUB32(ctx->r20, ctx->r13);
    // 0x800C7E8C: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800C7E90: jal         0x800C7B88
    // 0x800C7E94: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    _collectPVoices(rdram, ctx);
        goto after_3;
    // 0x800C7E94: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    after_3:
    // 0x800C7E98: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800C7E9C:
    // 0x800C7E9C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800C7EA0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C7EA4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800C7EA8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7EAC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800C7EB0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800C7EB4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800C7EB8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7EBC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800C7EC0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800C7EC4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800C7EC8: jr          $ra
    // 0x800C7ECC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800C7ECC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void alSynNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7ED0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800C7ED4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C7ED8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C7EDC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C7EE0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C7EE4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C7EE8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C7EEC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C7EF0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C7EF4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C7EF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C7EFC: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x800C7F00: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800C7F04: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800C7F08: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800C7F0C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800C7F10: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x800C7F14: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x800C7F18: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800C7F1C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800C7F20: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x800C7F24: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x800C7F28: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800C7F2C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800C7F30: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800C7F34: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x800C7F38: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C7F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7F44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C7F48: jal         0x800C7950
    // 0x800C7F4C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800C7F4C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x800C7F50: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800C7F54: jal         0x800CF840
    // 0x800C7F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew(rdram, ctx);
        goto after_1;
    // 0x800C7F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C7F5C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800C7F60: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x800C7F64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7F68: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x800C7F6C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C7F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7F74: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800C7F78: jal         0x800C7950
    // 0x800C7F7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800C7F7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800C7F80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C7F84: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x800C7F88: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x800C7F8C: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800C7F90: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C7F94: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C7F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7FA0: jal         0x800C7950
    // 0x800C7FA4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800C7FA4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x800C7FA8: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x800C7FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C7FB0: jal         0x800CF8D8
    // 0x800C7FB4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alAuxBusNew(rdram, ctx);
        goto after_4;
    // 0x800C7FB4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_4:
    // 0x800C7FB8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800C7FBC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C7FC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7FC8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800C7FCC: jal         0x800C7950
    // 0x800C7FD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x800C7FD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800C7FD4: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x800C7FD8: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800C7FDC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800C7FE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C7FE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7FEC: jal         0x800C7950
    // 0x800C7FF0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800C7FF0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x800C7FF4: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800C7FF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C7FFC: jal         0x800CF884
    // 0x800C8000: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alMainBusNew(rdram, ctx);
        goto after_7;
    // 0x800C8000: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_7:
    // 0x800C8004: lbu         $t7, 0x1C($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1C);
    // 0x800C8008: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800C800C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800C8010: beq         $t7, $zero, L_800C802C
    if (ctx->r15 == 0) {
        // 0x800C8014: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800C802C;
    }
    // 0x800C8014: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C8018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C801C: jal         0x800CFFE0
    // 0x800C8020: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alSynAllocFX(rdram, ctx);
        goto after_8;
    // 0x800C8020: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x800C8024: b           L_800C803C
    // 0x800C8028: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
        goto L_800C803C;
    // 0x800C8028: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800C802C:
    // 0x800C802C: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800C8030: jal         0x800D0080
    // 0x800C8034: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    alMainBusParam(rdram, ctx);
        goto after_9;
    // 0x800C8034: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    after_9:
    // 0x800C8038: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800C803C:
    // 0x800C803C: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x800C8040: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x800C8044: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x800C8048: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x800C804C: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x800C8050: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800C8054: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x800C8058: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C805C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C8060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C8064: jal         0x800C7950
    // 0x800C8068: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x800C8068: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x800C806C: lw          $t9, 0x4($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X4);
    // 0x800C8070: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C8074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C8078: blez        $t9, L_800C8138
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C807C: addiu       $a1, $s6, 0x4
        ctx->r5 = ADD32(ctx->r22, 0X4);
            goto L_800C8138;
    }
    // 0x800C807C: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x800C8080: addiu       $s1, $v0, 0x8C
    ctx->r17 = ADD32(ctx->r2, 0X8C);
    // 0x800C8084: addiu       $s2, $v0, 0x58
    ctx->r18 = ADD32(ctx->r2, 0X58);
    // 0x800C8088: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x800C808C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
L_800C8090:
    // 0x800C8090: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800C8094: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800C8098: jal         0x800C78C0
    // 0x800C809C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_11;
    // 0x800C809C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800C80A0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800C80A4: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x800C80A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C80AC: jal         0x800CF9B4
    // 0x800C80B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew(rdram, ctx);
        goto after_12;
    // 0x800C80B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x800C80B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C80B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C80BC: jal         0x800D01D0
    // 0x800C80C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alLoadParam(rdram, ctx);
        goto after_13;
    // 0x800C80C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x800C80C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C80C8: jal         0x800CF92C
    // 0x800C80CC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew(rdram, ctx);
        goto after_14;
    // 0x800C80CC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x800C80D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C80D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C80D8: jal         0x800D0D20
    // 0x800C80DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alResampleParam(rdram, ctx);
        goto after_15;
    // 0x800C80DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x800C80E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C80E4: jal         0x800CFA5C
    // 0x800C80E8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew(rdram, ctx);
        goto after_16;
    // 0x800C80E8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x800C80EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C80F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C80F4: jal         0x800D1134
    // 0x800C80F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alEnvmixerParam(rdram, ctx);
        goto after_17;
    // 0x800C80F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_17:
    // 0x800C80FC: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x800C8100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C8104: jal         0x800D1C80
    // 0x800C8108: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    alAuxBusParam(rdram, ctx);
        goto after_18;
    // 0x800C8108: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x800C810C: addiu       $t0, $s5, 0x8C
    ctx->r8 = ADD32(ctx->r21, 0X8C);
    // 0x800C8110: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x800C8114: lw          $t1, 0x4($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X4);
    // 0x800C8118: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C811C: addiu       $s0, $s0, 0xDC
    ctx->r16 = ADD32(ctx->r16, 0XDC);
    // 0x800C8120: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C8124: addiu       $s1, $s1, 0xDC
    ctx->r17 = ADD32(ctx->r17, 0XDC);
    // 0x800C8128: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
    // 0x800C812C: bne         $at, $zero, L_800C8090
    if (ctx->r1 != 0) {
        // 0x800C8130: addiu       $s3, $s3, 0xDC
        ctx->r19 = ADD32(ctx->r19, 0XDC);
            goto L_800C8090;
    }
    // 0x800C8130: addiu       $s3, $s3, 0xDC
    ctx->r19 = ADD32(ctx->r19, 0XDC);
    // 0x800C8134: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800C8138:
    // 0x800C8138: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800C813C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C8140: jal         0x800D1D90
    // 0x800C8144: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    alSaveParam(rdram, ctx);
        goto after_19;
    // 0x800C8144: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    after_19:
    // 0x800C8148: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x800C814C: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800C8150: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C8154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C8158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C815C: jal         0x800C7950
    // 0x800C8160: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_20;
    // 0x800C8160: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x800C8164: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x800C8168: lw          $t3, 0x8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8);
    // 0x800C816C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C8170: blezl       $t3, L_800C81A0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800C8174: sw          $s7, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r23;
            goto L_800C81A0;
    }
    goto skip_0;
    // 0x800C8174: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    skip_0:
    // 0x800C8178: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
L_800C817C:
    // 0x800C817C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C8180: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800C8184: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x800C8188: lw          $t5, 0x8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8);
    // 0x800C818C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800C8190: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C8194: bnel        $at, $zero, L_800C817C
    if (ctx->r1 != 0) {
        // 0x800C8198: lw          $t4, 0x2C($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X2C);
            goto L_800C817C;
    }
    goto skip_1;
    // 0x800C8198: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
    skip_1:
    // 0x800C819C: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
L_800C81A0:
    // 0x800C81A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C81A4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C81A8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C81AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C81B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C81B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C81B8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C81BC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C81C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C81C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C81C8: jr          $ra
    // 0x800C81CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800C81CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800C82DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C82DC: nop

    // 0x800C82E0: jr          $ra
    // 0x800C82E4: nop

    return;
    // 0x800C82E4: nop

    // 0x800C82E8: jr          $ra
    // 0x800C82EC: nop

    return;
    // 0x800C82EC: nop

    // 0x800C82F0: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800C82F4: bne         $t6, $zero, L_800C83D4
    if (ctx->r14 != 0) {
        // 0x800C82F8: nop

            goto L_800C83D4;
    }
    // 0x800C82F8: nop

    // 0x800C82FC: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800C8300: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C8304: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800C8308: blez        $t7, L_800C83D4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C830C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C83D4;
    }
    // 0x800C830C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C8310: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C8314: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C8318: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_800C831C:
    // 0x800C831C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C8320: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C8324: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800C8328: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C832C: bnel        $t6, $zero, L_800C83C0
    if (ctx->r14 != 0) {
        // 0x800C8330: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C83C0;
    }
    goto skip_0;
    // 0x800C8330: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800C8334: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800C8338: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800C833C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C8340: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C8344: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x800C8348: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800C834C: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x800C8350: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C8354: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800C8358: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800C835C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x800C8360: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800C8364: bnel        $t9, $zero, L_800C83C0
    if (ctx->r25 != 0) {
        // 0x800C8368: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C83C0;
    }
    goto skip_1;
    // 0x800C8368: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x800C836C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800C8370: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x800C8374: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x800C8378: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C837C: bne         $a2, $zero, L_800C83A4
    if (ctx->r6 != 0) {
        // 0x800C8380: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_800C83A4;
    }
    // 0x800C8380: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C8384: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x800C8388: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C838C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C8390: beq         $a2, $zero, L_800C83BC
    if (ctx->r6 == 0) {
        // 0x800C8394: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_800C83BC;
    }
    // 0x800C8394: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800C8398: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800C839C: b           L_800C83BC
    // 0x800C83A0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_800C83BC;
    // 0x800C83A0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_800C83A4:
    // 0x800C83A4: bnel        $t2, $a2, L_800C83C0
    if (ctx->r10 != ctx->r6) {
        // 0x800C83A8: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C83C0;
    }
    goto skip_2;
    // 0x800C83A8: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x800C83AC: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C83B0: beq         $a2, $zero, L_800C83BC
    if (ctx->r6 == 0) {
        // 0x800C83B4: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_800C83BC;
    }
    // 0x800C83B4: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x800C83B8: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800C83BC:
    // 0x800C83BC: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_800C83C0:
    // 0x800C83C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C83C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C83C8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C83CC: bnel        $at, $zero, L_800C831C
    if (ctx->r1 != 0) {
        // 0x800C83D0: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_800C831C;
    }
    goto skip_3;
    // 0x800C83D0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_800C83D4:
    // 0x800C83D4: jr          $ra
    // 0x800C83D8: nop

    return;
    // 0x800C83D8: nop

    // 0x800C83DC: jr          $ra
    // 0x800C83E0: nop

    return;
    // 0x800C83E0: nop

;}
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C83E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C83E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C83EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C83F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C83F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C83F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C83FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C8400: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800C8404: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x800C8408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C840C: bne         $t6, $at, L_800C84C8
    if (ctx->r14 != ctx->r1) {
        // 0x800C8410: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_800C84C8;
    }
    // 0x800C8410: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C8414: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800C8418: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C841C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C8420: blez        $t7, L_800C84C8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C8424: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800C84C8;
    }
    // 0x800C8424: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800C8428: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_800C842C:
    // 0x800C842C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800C8430: beq         $t9, $zero, L_800C84B0
    if (ctx->r25 == 0) {
        // 0x800C8434: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_800C84B0;
    }
    // 0x800C8434: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x800C8438: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800C843C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800C8440: bnel        $t6, $zero, L_800C84B4
    if (ctx->r14 != 0) {
        // 0x800C8444: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C84B4;
    }
    goto skip_0;
    // 0x800C8444: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x800C8448: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x800C844C: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x800C8450: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800C8454: beq         $v0, $zero, L_800C846C
    if (ctx->r2 == 0) {
        // 0x800C8458: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_800C846C;
    }
    // 0x800C8458: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800C845C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x800C8460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C8464: jal         0x800C82F0
    // 0x800C8468: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_1_800C82F0(rdram, ctx);
        goto after_0;
    // 0x800C8468: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_800C846C:
    // 0x800C846C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x800C8470: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C8474: blezl       $t8, L_800C84B4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C8478: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C84B4;
    }
    goto skip_1;
    // 0x800C8478: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x800C847C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_800C8480:
    // 0x800C8480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C8484: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x800C8488: beq         $a0, $zero, L_800C8498
    if (ctx->r4 == 0) {
        // 0x800C848C: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_800C8498;
    }
    // 0x800C848C: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x800C8490: jal         0x800C82F0
    // 0x800C8494: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_1_800C82F0(rdram, ctx);
        goto after_1;
    // 0x800C8494: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_800C8498:
    // 0x800C8498: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800C849C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C84A0: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C84A4: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C84A8: bnel        $at, $zero, L_800C8480
    if (ctx->r1 != 0) {
        // 0x800C84AC: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_800C8480;
    }
    goto skip_2;
    // 0x800C84AC: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_800C84B0:
    // 0x800C84B0: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_800C84B4:
    // 0x800C84B4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C84B8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C84BC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C84C0: bnel        $at, $zero, L_800C842C
    if (ctx->r1 != 0) {
        // 0x800C84C4: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_800C842C;
    }
    goto skip_3;
    // 0x800C84C4: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_800C84C8:
    // 0x800C84C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C84CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C84D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C84D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C84D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C84DC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C84E0: jr          $ra
    // 0x800C84E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C84E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C84E8: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800C84EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C84F0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C84F4: blez        $t6, L_800C8520
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C84F8: nop

            goto L_800C8520;
    }
    // 0x800C84F8: nop

    // 0x800C84FC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_800C8500:
    // 0x800C8500: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C8504: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C8508: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C850C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800C8510: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800C8514: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C8518: bnel        $at, $zero, L_800C8500
    if (ctx->r1 != 0) {
        // 0x800C851C: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_800C8500;
    }
    goto skip_0;
    // 0x800C851C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_800C8520:
    // 0x800C8520: jr          $ra
    // 0x800C8524: nop

    return;
    // 0x800C8524: nop

;}
RECOMP_FUNC void func_800C8528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8528: nop

    // 0x800C852C: nop

;}
RECOMP_FUNC void __CSPPostNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C8534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8538: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800C853C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C8540: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C8544: bnel        $t6, $at, L_800C8594
    if (ctx->r14 != ctx->r1) {
        // 0x800C8548: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8594;
    }
    goto skip_0;
    // 0x800C8548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C854C: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x800C8550: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800C8554: beql        $a0, $zero, L_800C8594
    if (ctx->r4 == 0) {
        // 0x800C8558: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8594;
    }
    goto skip_1;
    // 0x800C8558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C855C: jal         0x800CAB2C
    // 0x800C8560: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    __alCSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x800C8560: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C8564: beq         $v0, $zero, L_800C8590
    if (ctx->r2 == 0) {
        // 0x800C8568: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_800C8590;
    }
    // 0x800C8568: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800C856C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800C8570: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x800C8574: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8578: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x800C857C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C8580: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8584: mflo        $a2
    ctx->r6 = lo;
    // 0x800C8588: jal         0x800D3A2C
    // 0x800C858C: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x800C858C: nop

    after_1:
L_800C8590:
    // 0x800C8590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8594:
    // 0x800C8594: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C8598: jr          $ra
    // 0x800C859C: nop

    return;
    // 0x800C859C: nop

;}
RECOMP_FUNC void func_800C85A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C85A0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800C85A4: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800C85A8: beql        $v0, $zero, L_800C85CC
    if (ctx->r2 == 0) {
        // 0x800C85AC: sw          $t8, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r24;
            goto L_800C85CC;
    }
    goto skip_0;
    // 0x800C85AC: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    skip_0:
    // 0x800C85B0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800C85B4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800C85B8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C85BC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C85C0: jr          $ra
    // 0x800C85C4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    return;
    // 0x800C85C4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x800C85C8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
L_800C85CC:
    // 0x800C85CC: jr          $ra
    // 0x800C85D0: nop

    return;
    // 0x800C85D0: nop

    // 0x800C85D4: jr          $ra
    // 0x800C85D8: nop

    return;
    // 0x800C85D8: nop

    // 0x800C85DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C85E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C85E4: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800C85E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C85EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C85F0: bne         $t6, $at, L_800C879C
    if (ctx->r14 != ctx->r1) {
        // 0x800C85F4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800C879C;
    }
    // 0x800C85F4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C85F8: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800C85FC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800C8600: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800C8604: bnel        $t7, $at, L_800C87A0
    if (ctx->r15 != ctx->r1) {
        // 0x800C8608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C87A0;
    }
    goto skip_1;
    // 0x800C8608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C860C: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800C8610: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800C8614: lw          $fp, 0x24($s7)
    ctx->r30 = MEM_W(ctx->r23, 0X24);
    // 0x800C8618: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C861C: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800C8620: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C8624: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C8628: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800C862C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800C8630: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800C8634: jal         0x800C85A0
    // 0x800C8638: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800C85A0(rdram, ctx);
        goto after_0;
    // 0x800C8638: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800C863C: lw          $s1, 0x50($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X50);
    // 0x800C8640: beq         $s1, $zero, L_800C86B8
    if (ctx->r17 == 0) {
        // 0x800C8644: nop

            goto L_800C86B8;
    }
    // 0x800C8644: nop

    // 0x800C8648: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_800C864C:
    // 0x800C864C: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
    // 0x800C8650: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800C8654: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800C8658: bne         $s4, $t7, L_800C86B0
    if (ctx->r20 != ctx->r15) {
        // 0x800C865C: addu        $s0, $s0, $t9
        ctx->r16 = ADD32(ctx->r16, ctx->r25);
            goto L_800C86B0;
    }
    // 0x800C865C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800C8660: jal         0x800C7890
    // 0x800C8664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C8664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800C8668: beql        $s3, $zero, L_800C8688
    if (ctx->r19 == 0) {
        // 0x800C866C: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_800C8688;
    }
    goto skip_2;
    // 0x800C866C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_2:
    // 0x800C8670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C8674: jal         0x800C78C0
    // 0x800C8678: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C8678: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x800C867C: b           L_800C8690
    // 0x800C8680: nop

        goto L_800C8690;
    // 0x800C8680: nop

    // 0x800C8684: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800C8688:
    // 0x800C8688: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x800C868C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
L_800C8690:
    // 0x800C8690: beq         $s2, $zero, L_800C86AC
    if (ctx->r18 == 0) {
        // 0x800C8694: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_800C86AC;
    }
    // 0x800C8694: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800C8698: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x800C869C: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x800C86A0: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C86A4: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800C86A8: sw          $t6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r14;
L_800C86AC:
    // 0x800C86AC: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_800C86B0:
    // 0x800C86B0: bne         $s2, $zero, L_800C864C
    if (ctx->r18 != 0) {
        // 0x800C86B4: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800C864C;
    }
    // 0x800C86B4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800C86B8:
    // 0x800C86B8: beq         $s3, $zero, L_800C879C
    if (ctx->r19 == 0) {
        // 0x800C86BC: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_800C879C;
    }
    // 0x800C86BC: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800C86C0: addiu       $s4, $s7, 0x48
    ctx->r20 = ADD32(ctx->r23, 0X48);
    // 0x800C86C4: addiu       $s5, $s4, 0x8
    ctx->r21 = ADD32(ctx->r20, 0X8);
    // 0x800C86C8: addiu       $s6, $zero, -0x8
    ctx->r22 = ADD32(0, -0X8);
L_800C86CC:
    // 0x800C86CC: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800C86D0: lw          $t7, 0x24($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X24);
    // 0x800C86D4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800C86D8: div         $zero, $t9, $fp
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r30)));
    // 0x800C86DC: mflo        $v0
    ctx->r2 = lo;
    // 0x800C86E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C86E4: bne         $fp, $zero, L_800C86F0
    if (ctx->r30 != 0) {
        // 0x800C86E8: nop

            goto L_800C86F0;
    }
    // 0x800C86E8: nop

    // 0x800C86EC: break       7
    do_break(2148304620);
L_800C86F0:
    // 0x800C86F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C86F4: bne         $fp, $at, L_800C8708
    if (ctx->r30 != ctx->r1) {
        // 0x800C86F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C8708;
    }
    // 0x800C86F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C86FC: bne         $t9, $at, L_800C8708
    if (ctx->r25 != ctx->r1) {
        // 0x800C8700: nop

            goto L_800C8708;
    }
    // 0x800C8700: nop

    // 0x800C8704: break       6
    do_break(2148304644);
L_800C8708:
    // 0x800C8708: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C870C: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x800C8710: mflo        $t8
    ctx->r24 = lo;
    // 0x800C8714: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x800C8718: jal         0x800C41A0
    // 0x800C871C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C871C: nop

    after_3:
    // 0x800C8720: beq         $s4, $s6, L_800C878C
    if (ctx->r20 == ctx->r22) {
        // 0x800C8724: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800C878C;
    }
    // 0x800C8724: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C8728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800C872C:
    // 0x800C872C: bnel        $a0, $zero, L_800C874C
    if (ctx->r4 != 0) {
        // 0x800C8730: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_800C874C;
    }
    goto skip_3;
    // 0x800C8730: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_3:
    // 0x800C8734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C8738: jal         0x800C78C0
    // 0x800C873C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800C873C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800C8740: b           L_800C878C
    // 0x800C8744: nop

        goto L_800C878C;
    // 0x800C8744: nop

    // 0x800C8748: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_800C874C:
    // 0x800C874C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800C8750: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8754: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C8758: beq         $at, $zero, L_800C877C
    if (ctx->r1 == 0) {
        // 0x800C875C: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800C877C;
    }
    // 0x800C875C: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800C8760: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x800C8764: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800C8768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C876C: jal         0x800C78C0
    // 0x800C8770: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800C8770: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800C8774: b           L_800C878C
    // 0x800C8778: nop

        goto L_800C878C;
    // 0x800C8778: nop

L_800C877C:
    // 0x800C877C: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x800C8780: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800C8784: bnel        $s0, $zero, L_800C872C
    if (ctx->r16 != 0) {
        // 0x800C8788: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800C872C;
    }
    goto skip_4;
    // 0x800C8788: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_4:
L_800C878C:
    // 0x800C878C: jal         0x800C41A0
    // 0x800C8790: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800C8790: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x800C8794: bne         $s2, $zero, L_800C86CC
    if (ctx->r18 != 0) {
        // 0x800C8798: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800C86CC;
    }
    // 0x800C8798: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800C879C:
    // 0x800C879C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C87A0:
    // 0x800C87A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C87A4: jr          $ra
    // 0x800C87A8: nop

    return;
    // 0x800C87A8: nop

    // 0x800C87AC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C87B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C87B4: lbu         $s6, 0x8($t0)
    ctx->r22 = MEM_BU(ctx->r8, 0X8);
    // 0x800C87B8: lbu         $s4, 0x9($t0)
    ctx->r20 = MEM_BU(ctx->r8, 0X9);
    // 0x800C87BC: lbu         $s1, 0xA($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0XA);
    // 0x800C87C0: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x800C87C4: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x800C87C8: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x800C87CC: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x800C87D0: beq         $at, $zero, L_800C8FC4
    if (ctx->r1 == 0) {
        // 0x800C87D4: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_800C8FC4;
    }
    // 0x800C87D4: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x800C87D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C87DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C87E0: addu        $at, $at, $t7
    gpr jr_addend_800C87E8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C87E4: lw          $t7, -0x90($at)
    ctx->r15 = ADD32(ctx->r1, -0X90);
    // 0x800C87E8: jr          $t7
    // 0x800C87EC: nop

    switch (jr_addend_800C87E8 >> 2) {
        case 0: goto L_800C8B90; break;
        case 1: goto L_800C8FC4; break;
        case 2: goto L_800C8FC4; break;
        case 3: goto L_800C8FC4; break;
        case 4: goto L_800C8FC4; break;
        case 5: goto L_800C8FC4; break;
        case 6: goto L_800C8FC4; break;
        case 7: goto L_800C8FC4; break;
        case 8: goto L_800C8FC4; break;
        case 9: goto L_800C8FC4; break;
        case 10: goto L_800C8FC4; break;
        case 11: goto L_800C8FC4; break;
        case 12: goto L_800C8FC4; break;
        case 13: goto L_800C8FC4; break;
        case 14: goto L_800C8FC4; break;
        case 15: goto L_800C8FC4; break;
        case 16: goto L_800C87F0; break;
        case 17: goto L_800C8FC4; break;
        case 18: goto L_800C8FC4; break;
        case 19: goto L_800C8FC4; break;
        case 20: goto L_800C8FC4; break;
        case 21: goto L_800C8FC4; break;
        case 22: goto L_800C8FC4; break;
        case 23: goto L_800C8FC4; break;
        case 24: goto L_800C8FC4; break;
        case 25: goto L_800C8FC4; break;
        case 26: goto L_800C8FC4; break;
        case 27: goto L_800C8FC4; break;
        case 28: goto L_800C8FC4; break;
        case 29: goto L_800C8FC4; break;
        case 30: goto L_800C8FC4; break;
        case 31: goto L_800C8FC4; break;
        case 32: goto L_800C8BE8; break;
        case 33: goto L_800C8FC4; break;
        case 34: goto L_800C8FC4; break;
        case 35: goto L_800C8FC4; break;
        case 36: goto L_800C8FC4; break;
        case 37: goto L_800C8FC4; break;
        case 38: goto L_800C8FC4; break;
        case 39: goto L_800C8FC4; break;
        case 40: goto L_800C8FC4; break;
        case 41: goto L_800C8FC4; break;
        case 42: goto L_800C8FC4; break;
        case 43: goto L_800C8FC4; break;
        case 44: goto L_800C8FC4; break;
        case 45: goto L_800C8FC4; break;
        case 46: goto L_800C8FC4; break;
        case 47: goto L_800C8FC4; break;
        case 48: goto L_800C8CC0; break;
        case 49: goto L_800C8FC4; break;
        case 50: goto L_800C8FC4; break;
        case 51: goto L_800C8FC4; break;
        case 52: goto L_800C8FC4; break;
        case 53: goto L_800C8FC4; break;
        case 54: goto L_800C8FC4; break;
        case 55: goto L_800C8FC4; break;
        case 56: goto L_800C8FC4; break;
        case 57: goto L_800C8FC4; break;
        case 58: goto L_800C8FC4; break;
        case 59: goto L_800C8FC4; break;
        case 60: goto L_800C8FC4; break;
        case 61: goto L_800C8FC4; break;
        case 62: goto L_800C8FC4; break;
        case 63: goto L_800C8FC4; break;
        case 64: goto L_800C8EF8; break;
        case 65: goto L_800C8FC4; break;
        case 66: goto L_800C8FC4; break;
        case 67: goto L_800C8FC4; break;
        case 68: goto L_800C8FC4; break;
        case 69: goto L_800C8FC4; break;
        case 70: goto L_800C8FC4; break;
        case 71: goto L_800C8FC4; break;
        case 72: goto L_800C8FC4; break;
        case 73: goto L_800C8FC4; break;
        case 74: goto L_800C8FC4; break;
        case 75: goto L_800C8FC4; break;
        case 76: goto L_800C8FC4; break;
        case 77: goto L_800C8FC4; break;
        case 78: goto L_800C8FC4; break;
        case 79: goto L_800C8FC4; break;
        case 80: goto L_800C8C4C; break;
        case 81: goto L_800C8FC4; break;
        case 82: goto L_800C8FC4; break;
        case 83: goto L_800C8FC4; break;
        case 84: goto L_800C8FC4; break;
        case 85: goto L_800C8FC4; break;
        case 86: goto L_800C8FC4; break;
        case 87: goto L_800C8FC4; break;
        case 88: goto L_800C8FC4; break;
        case 89: goto L_800C8FC4; break;
        case 90: goto L_800C8FC4; break;
        case 91: goto L_800C8FC4; break;
        case 92: goto L_800C8FC4; break;
        case 93: goto L_800C8FC4; break;
        case 94: goto L_800C8FC4; break;
        case 95: goto L_800C8FC4; break;
        case 96: goto L_800C8F2C; break;
        default: switch_error(__func__, 0x800C87E8, 0x800EFF70);
    }
    // 0x800C87EC: nop

L_800C87F0:
    // 0x800C87F0: beql        $s1, $zero, L_800C8B94
    if (ctx->r17 == 0) {
        // 0x800C87F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C8B94;
    }
    goto skip_5;
    // 0x800C87F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_5:
    // 0x800C87F8: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x800C87FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C8800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8804: bne         $t8, $at, L_800C8FC4
    if (ctx->r24 != ctx->r1) {
        // 0x800C8808: andi        $a1, $s4, 0xFF
        ctx->r5 = ctx->r20 & 0XFF;
            goto L_800C8FC4;
    }
    // 0x800C8808: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C880C: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C8810: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800C8814: jal         0x800D26D0
    // 0x800C8818: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    __lookupSoundQuick(rdram, ctx);
        goto after_7;
    // 0x800C8818: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_7:
    // 0x800C881C: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8820: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8820: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800C8824: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800C8828: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800C882C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8830: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800C8834: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x800C8838: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800C883C: sb          $zero, 0x78($sp)
    MEM_B(0X78, ctx->r29) = 0;
    // 0x800C8840: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C8844: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C8848: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800C884C: jal         0x800D2660
    // 0x800C8850: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    __mapVoice(rdram, ctx);
        goto after_8;
    // 0x800C8850: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    after_8:
    // 0x800C8854: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8858: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8858: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C885C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8860: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800C8864: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x800C8868: jal         0x800D3FE8
    // 0x800C886C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    alSynAllocVoice(rdram, ctx);
        goto after_9;
    // 0x800C886C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_9:
    // 0x800C8870: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x800C8874: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x800C8878: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C887C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800C8880: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x800C8884: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x800C8888: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x800C888C: bnel        $at, $zero, L_800C88A0
    if (ctx->r1 != 0) {
        // 0x800C8890: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_800C88A0;
    }
    goto skip_6;
    // 0x800C8890: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_6:
    // 0x800C8894: b           L_800C88A0
    // 0x800C8898: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800C88A0;
    // 0x800C8898: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x800C889C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800C88A0:
    // 0x800C88A0: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x800C88A4: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C88A8: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x800C88AC: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x800C88B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C88B4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C88B8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C88BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C88C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C88C4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800C88C8: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800C88CC: jal         0x800CADC0
    // 0x800C88D0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_10;
    // 0x800C88D0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_10:
    // 0x800C88D4: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800C88D8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800C88DC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800C88E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C88E4: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x800C88E8: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x800C88EC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C88F0: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x800C88F4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C88F8: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x800C88FC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800C8900: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x800C8904: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C8908: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x800C890C: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x800C8910: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800C8914: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x800C8918: beql        $a2, $zero, L_800C8984
    if (ctx->r6 == 0) {
        // 0x800C891C: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800C8984;
    }
    goto skip_7;
    // 0x800C891C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_7:
    // 0x800C8920: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800C8924: beql        $v0, $zero, L_800C8984
    if (ctx->r2 == 0) {
        // 0x800C8928: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800C8984;
    }
    goto skip_8;
    // 0x800C8928: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_8:
    // 0x800C892C: lbu         $t9, 0x6($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6);
    // 0x800C8930: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x800C8934: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800C8938: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C893C: lbu         $t6, 0x7($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X7);
    // 0x800C8940: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800C8944: jalr        $v0
    // 0x800C8948: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_11;
    // 0x800C8948: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_11:
    // 0x800C894C: beq         $v0, $zero, L_800C8980
    if (ctx->r2 == 0) {
        // 0x800C8950: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_800C8980;
    }
    // 0x800C8950: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800C8954: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800C8958: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C895C: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800C8960: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x800C8964: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8968: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C896C: jal         0x800D3A2C
    // 0x800C8970: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_12;
    // 0x800C8970: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_12:
    // 0x800C8974: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800C8978: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x800C897C: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800C8980:
    // 0x800C8980: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_800C8984:
    // 0x800C8984: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C8988: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C898C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C8990: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C8994: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C8998: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C899C: nop

    // 0x800C89A0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800C89A4: beql        $t7, $zero, L_800C89F4
    if (ctx->r15 == 0) {
        // 0x800C89A8: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_800C89F4;
    }
    goto skip_9;
    // 0x800C89A8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_9:
    // 0x800C89AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C89B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C89B4: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C89B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C89BC: nop

    // 0x800C89C0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C89C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C89C8: nop

    // 0x800C89CC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800C89D0: bne         $t7, $zero, L_800C89E8
    if (ctx->r15 != 0) {
        // 0x800C89D4: nop

            goto L_800C89E8;
    }
    // 0x800C89D4: nop

    // 0x800C89D8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C89DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C89E0: b           L_800C8A00
    // 0x800C89E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800C8A00;
    // 0x800C89E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800C89E8:
    // 0x800C89E8: b           L_800C8A00
    // 0x800C89EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800C8A00;
    // 0x800C89EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C89F0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_800C89F4:
    // 0x800C89F4: nop

    // 0x800C89F8: bltz        $t7, L_800C89E8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800C89FC: nop

            goto L_800C89E8;
    }
    // 0x800C89FC: nop

L_800C8A00:
    // 0x800C8A00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C8A04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C8A08: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x800C8A0C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C8A10: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800C8A14: lbu         $a2, 0x8($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X8);
    // 0x800C8A18: addiu       $s5, $s2, 0x48
    ctx->r21 = ADD32(ctx->r18, 0X48);
    // 0x800C8A1C: beql        $a2, $zero, L_800C8A8C
    if (ctx->r6 == 0) {
        // 0x800C8A20: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800C8A8C;
    }
    goto skip_10;
    // 0x800C8A20: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_10:
    // 0x800C8A24: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800C8A28: beql        $v0, $zero, L_800C8A8C
    if (ctx->r2 == 0) {
        // 0x800C8A2C: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800C8A8C;
    }
    goto skip_11;
    // 0x800C8A2C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_11:
    // 0x800C8A30: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
    // 0x800C8A34: lbu         $a3, 0x9($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X9);
    // 0x800C8A38: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800C8A3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C8A40: lbu         $t6, 0xB($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XB);
    // 0x800C8A44: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800C8A48: jalr        $v0
    // 0x800C8A4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x800C8A4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_13:
    // 0x800C8A50: beq         $v0, $zero, L_800C8A88
    if (ctx->r2 == 0) {
        // 0x800C8A54: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_800C8A88;
    }
    // 0x800C8A54: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x800C8A58: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800C8A5C: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C8A60: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800C8A64: sb          $s6, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r22;
    // 0x800C8A68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C8A6C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8A70: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C8A74: jal         0x800D3A2C
    // 0x800C8A78: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_14;
    // 0x800C8A78: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_14:
    // 0x800C8A7C: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800C8A80: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x800C8A84: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800C8A88:
    // 0x800C8A88: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_800C8A8C:
    // 0x800C8A8C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C8A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8A94: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800C8A98: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C8A9C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800C8AA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C8AA4: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x800C8AA8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800C8AAC: lbu         $s1, 0xA($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XA);
    // 0x800C8AB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C8AB4: nop

    // 0x800C8AB8: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C8ABC: jal         0x800D25A4
    // 0x800C8AC0: nop

    __vsPan(rdram, ctx);
        goto after_15;
    // 0x800C8AC0: nop

    after_15:
    // 0x800C8AC4: andi        $fp, $v0, 0xFF
    ctx->r30 = ctx->r2 & 0XFF;
    // 0x800C8AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8ACC: jal         0x800D2184
    // 0x800C8AD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_16;
    // 0x800C8AD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x800C8AD4: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800C8AD8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8ADC: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x800C8AE0: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x800C8AE4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C8AE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C8AEC: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x800C8AF0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C8AF4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800C8AF8: jal         0x800D4130
    // 0x800C8AFC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    alSynStartVoiceParams(rdram, ctx);
        goto after_17;
    // 0x800C8AFC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_17:
    // 0x800C8B00: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C8B04: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800C8B08: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800C8B0C: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800C8B10: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C8B14: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C8B18: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8B1C: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x800C8B20: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C8B24: sb          $t7, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r15;
    // 0x800C8B28: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800C8B2C: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800C8B30: jal         0x800D3A2C
    // 0x800C8B34: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x800C8B34: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    after_18:
    // 0x800C8B38: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800C8B3C: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x800C8B40: ori         $t9, $s6, 0x80
    ctx->r25 = ctx->r22 | 0X80;
    // 0x800C8B44: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800C8B48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C8B4C: beql        $t8, $zero, L_800C8FC8
    if (ctx->r24 == 0) {
        // 0x800C8B50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_12;
    // 0x800C8B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x800C8B54: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800C8B58: sb          $t9, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r25;
    // 0x800C8B5C: sb          $s4, 0x95($sp)
    MEM_B(0X95, ctx->r29) = ctx->r20;
    // 0x800C8B60: sb          $zero, 0x96($sp)
    MEM_B(0X96, ctx->r29) = 0;
    // 0x800C8B64: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800C8B68: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x800C8B6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C8B70: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C8B74: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8B78: mflo        $s3
    ctx->r19 = lo;
    // 0x800C8B7C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C8B80: jal         0x800D3A2C
    // 0x800C8B84: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_19;
    // 0x800C8B84: nop

    after_19:
    // 0x800C8B88: b           L_800C8FC8
    // 0x800C8B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8B90:
    // 0x800C8B90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C8B94:
    // 0x800C8B94: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C8B98: jal         0x800D25EC
    // 0x800C8B9C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_20;
    // 0x800C8B9C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_20:
    // 0x800C8BA0: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8BA4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8BA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C8BA8: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x800C8BAC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800C8BB0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C8BB4: bne         $s6, $t7, L_800C8BC4
    if (ctx->r22 != ctx->r15) {
        // 0x800C8BB8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C8BC4;
    }
    // 0x800C8BB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8BBC: b           L_800C8FC4
    // 0x800C8BC0: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_800C8FC4;
    // 0x800C8BC0: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_800C8BC4:
    // 0x800C8BC4: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800C8BC8: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800C8BCC: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800C8BD0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800C8BD4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8BD8: jal         0x800D220C
    // 0x800C8BDC: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_21;
    // 0x800C8BDC: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_21:
    // 0x800C8BE0: b           L_800C8FC8
    // 0x800C8BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8BE8:
    // 0x800C8BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8BEC: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C8BF0: jal         0x800D25EC
    // 0x800C8BF4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_22;
    // 0x800C8BF4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_22:
    // 0x800C8BF8: beq         $v0, $zero, L_800C8FC4
    if (ctx->r2 == 0) {
        // 0x800C8BFC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8FC4;
    }
    // 0x800C8BFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C8C00: sb          $s1, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r17;
    // 0x800C8C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C8C08: jal         0x800D2184
    // 0x800C8C0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_23;
    // 0x800C8C0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    // 0x800C8C10: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C8C14: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C8C18: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800C8C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8C20: jal         0x800D2160
    // 0x800C8C24: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_24;
    // 0x800C8C24: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_24:
    // 0x800C8C28: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C8C2C: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C8C30: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C8C34: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8C38: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8C3C: jal         0x800D3DD0
    // 0x800C8C40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_25;
    // 0x800C8C40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_25:
    // 0x800C8C44: b           L_800C8FC8
    // 0x800C8C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8C4C:
    // 0x800C8C4C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8C50: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8C54: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_13;
    // 0x800C8C54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x800C8C58: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8C5C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800C8C60:
    // 0x800C8C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8C64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C8C68: bnel        $s3, $t6, L_800C8CB0
    if (ctx->r19 != ctx->r14) {
        // 0x800C8C6C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8CB0;
    }
    goto skip_14;
    // 0x800C8C6C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_14:
    // 0x800C8C70: jal         0x800D2184
    // 0x800C8C74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    __vsVol(rdram, ctx);
        goto after_26;
    // 0x800C8C74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    after_26:
    // 0x800C8C78: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C8C7C: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C8C80: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800C8C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8C88: jal         0x800D2160
    // 0x800C8C8C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_27;
    // 0x800C8C8C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_27:
    // 0x800C8C90: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C8C94: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C8C98: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C8C9C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8CA0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8CA4: jal         0x800D3DD0
    // 0x800C8CA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_28;
    // 0x800C8CA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_28:
    // 0x800C8CAC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8CB0:
    // 0x800C8CB0: bnel        $s0, $zero, L_800C8C60
    if (ctx->r16 != 0) {
        // 0x800C8CB4: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8C60;
    }
    goto skip_15;
    // 0x800C8CB4: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_15:
    // 0x800C8CB8: b           L_800C8FC8
    // 0x800C8CBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8CBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8CC0:
    // 0x800C8CC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800C8CC4: beq         $s4, $at, L_800C8D54
    if (ctx->r20 == ctx->r1) {
        // 0x800C8CC8: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_800C8D54;
    }
    // 0x800C8CC8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800C8CCC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800C8CD0: beq         $v0, $at, L_800C8CF8
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CD4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800C8CF8;
    }
    // 0x800C8CD4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C8CD8: beq         $v0, $at, L_800C8DE4
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CDC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800C8DE4;
    }
    // 0x800C8CDC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800C8CE0: beq         $v0, $at, L_800C8DF8
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CE4: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_800C8DF8;
    }
    // 0x800C8CE4: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800C8CE8: beql        $v0, $at, L_800C8EAC
    if (ctx->r2 == ctx->r1) {
        // 0x800C8CEC: lw          $t9, 0x60($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X60);
            goto L_800C8EAC;
    }
    goto skip_16;
    // 0x800C8CEC: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    skip_16:
    // 0x800C8CF0: b           L_800C8FC8
    // 0x800C8CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8CF8:
    // 0x800C8CF8: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800C8CFC: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C8D00: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C8D04: sb          $s1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r17;
    // 0x800C8D08: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8D0C: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8D10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_17;
    // 0x800C8D10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_17:
    // 0x800C8D14: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8D18: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C8D1C:
    // 0x800C8D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8D20: bnel        $s3, $t7, L_800C8D44
    if (ctx->r19 != ctx->r15) {
        // 0x800C8D24: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8D44;
    }
    goto skip_18;
    // 0x800C8D24: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_18:
    // 0x800C8D28: jal         0x800D25A4
    // 0x800C8D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsPan(rdram, ctx);
        goto after_29;
    // 0x800C8D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x800C8D30: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8D34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8D38: jal         0x800D4220
    // 0x800C8D3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_30;
    // 0x800C8D3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_30:
    // 0x800C8D40: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8D44:
    // 0x800C8D44: bnel        $s0, $zero, L_800C8D1C
    if (ctx->r16 != 0) {
        // 0x800C8D48: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8D1C;
    }
    goto skip_19;
    // 0x800C8D48: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_19:
    // 0x800C8D4C: b           L_800C8FC8
    // 0x800C8D50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8D50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8D54:
    // 0x800C8D54: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800C8D58: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C8D5C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C8D60: sb          $s1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r17;
    // 0x800C8D64: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8D68: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8D6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_20;
    // 0x800C8D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_20:
    // 0x800C8D70: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8D74: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800C8D78: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C8D7C:
    // 0x800C8D7C: bnel        $s3, $t7, L_800C8DD4
    if (ctx->r19 != ctx->r15) {
        // 0x800C8D80: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8DD4;
    }
    goto skip_21;
    // 0x800C8D80: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x800C8D84: lbu         $t9, 0x34($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X34);
    // 0x800C8D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8D8C: beql        $s4, $t9, L_800C8DD4
    if (ctx->r20 == ctx->r25) {
        // 0x800C8D90: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8DD4;
    }
    goto skip_22;
    // 0x800C8D90: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x800C8D94: jal         0x800D2184
    // 0x800C8D98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_31;
    // 0x800C8D98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_31:
    // 0x800C8D9C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C8DA0: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C8DA4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800C8DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8DAC: jal         0x800D2160
    // 0x800C8DB0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_32;
    // 0x800C8DB0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_32:
    // 0x800C8DB4: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C8DB8: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C8DBC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C8DC0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8DC4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8DC8: jal         0x800D3DD0
    // 0x800C8DCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_33;
    // 0x800C8DCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_33:
    // 0x800C8DD0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8DD4:
    // 0x800C8DD4: bnel        $s0, $zero, L_800C8D7C
    if (ctx->r16 != 0) {
        // 0x800C8DD8: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8D7C;
    }
    goto skip_23;
    // 0x800C8DD8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_23:
    // 0x800C8DDC: b           L_800C8FC8
    // 0x800C8DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8DE4:
    // 0x800C8DE4: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800C8DE8: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x800C8DEC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800C8DF0: b           L_800C8FC4
    // 0x800C8DF4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
        goto L_800C8FC4;
    // 0x800C8DF4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
L_800C8DF8:
    // 0x800C8DF8: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800C8DFC: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x800C8E00: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800C8E04: sb          $s1, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r17;
    // 0x800C8E08: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8E0C: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8E10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_24;
    // 0x800C8E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_24:
    // 0x800C8E14: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8E18: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800C8E1C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800C8E20: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800C8E24: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800C8E28: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800C8E2C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800C8E30:
    // 0x800C8E30: bnel        $s3, $t6, L_800C8E98
    if (ctx->r19 != ctx->r14) {
        // 0x800C8E34: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_25;
    // 0x800C8E34: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_25:
    // 0x800C8E38: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800C8E3C: slti        $at, $s1, 0x40
    ctx->r1 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x800C8E40: beql        $s4, $v0, L_800C8E98
    if (ctx->r20 == ctx->r2) {
        // 0x800C8E44: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_26;
    // 0x800C8E44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x800C8E48: bne         $at, $zero, L_800C8E60
    if (ctx->r1 != 0) {
        // 0x800C8E4C: nop

            goto L_800C8E60;
    }
    // 0x800C8E4C: nop

    // 0x800C8E50: bnel        $v0, $zero, L_800C8E98
    if (ctx->r2 != 0) {
        // 0x800C8E54: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_27;
    // 0x800C8E54: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_27:
    // 0x800C8E58: b           L_800C8E94
    // 0x800C8E5C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800C8E94;
    // 0x800C8E5C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_800C8E60:
    // 0x800C8E60: bne         $s6, $v0, L_800C8E70
    if (ctx->r22 != ctx->r2) {
        // 0x800C8E64: nop

            goto L_800C8E70;
    }
    // 0x800C8E64: nop

    // 0x800C8E68: b           L_800C8E94
    // 0x800C8E6C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_800C8E94;
    // 0x800C8E6C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800C8E70:
    // 0x800C8E70: bnel        $s7, $v0, L_800C8E98
    if (ctx->r23 != ctx->r2) {
        // 0x800C8E74: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8E98;
    }
    goto skip_28;
    // 0x800C8E74: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_28:
    // 0x800C8E78: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800C8E7C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800C8E80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8E84: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800C8E88: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8E8C: jal         0x800D220C
    // 0x800C8E90: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_34;
    // 0x800C8E90: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    after_34:
L_800C8E94:
    // 0x800C8E94: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8E98:
    // 0x800C8E98: bnel        $s0, $zero, L_800C8E30
    if (ctx->r16 != 0) {
        // 0x800C8E9C: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8E30;
    }
    goto skip_29;
    // 0x800C8E9C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_29:
    // 0x800C8EA0: b           L_800C8FC8
    // 0x800C8EA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8EA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C8EA8: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
L_800C8EAC:
    // 0x800C8EAC: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C8EB0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C8EB4: sb          $s1, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r17;
    // 0x800C8EB8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8EBC: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8EC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_30;
    // 0x800C8EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_30:
    // 0x800C8EC4: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8EC8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C8ECC:
    // 0x800C8ECC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8ED0: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C8ED4: bnel        $s3, $t7, L_800C8EE8
    if (ctx->r19 != ctx->r15) {
        // 0x800C8ED8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8EE8;
    }
    goto skip_31;
    // 0x800C8ED8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_31:
    // 0x800C8EDC: jal         0x800D42B0
    // 0x800C8EE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    alSynSetFXMix(rdram, ctx);
        goto after_35;
    // 0x800C8EE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_35:
    // 0x800C8EE4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8EE8:
    // 0x800C8EE8: bnel        $s0, $zero, L_800C8ECC
    if (ctx->r16 != 0) {
        // 0x800C8EEC: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8ECC;
    }
    goto skip_32;
    // 0x800C8EEC: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_32:
    // 0x800C8EF0: b           L_800C8FC8
    // 0x800C8EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8EF8:
    // 0x800C8EF8: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800C8EFC: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x800C8F00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8F04: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800C8F08: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800C8F0C: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800C8F10: slt         $at, $s4, $t9
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C8F14: beql        $at, $zero, L_800C8FC8
    if (ctx->r1 == 0) {
        // 0x800C8F18: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_33;
    // 0x800C8F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_33:
    // 0x800C8F1C: jal         0x800D1FD0
    // 0x800C8F20: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    __setInstChanState(rdram, ctx);
        goto after_36;
    // 0x800C8F20: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    after_36:
    // 0x800C8F24: b           L_800C8FC8
    // 0x800C8F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8FC8;
    // 0x800C8F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8F2C:
    // 0x800C8F2C: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800C8F30: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800C8F34: sll         $t8, $s1, 7
    ctx->r24 = S32(ctx->r17 << 7);
    // 0x800C8F38: addu        $t9, $t7, $fp
    ctx->r25 = ADD32(ctx->r15, ctx->r30);
    // 0x800C8F3C: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x800C8F40: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x800C8F44: addiu       $t9, $t7, -0x2000
    ctx->r25 = ADD32(ctx->r15, -0X2000);
    // 0x800C8F48: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8F4C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C8F50: bgez        $a0, L_800C8F60
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C8F54: sra         $t8, $a0, 13
        ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
            goto L_800C8F60;
    }
    // 0x800C8F54: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x800C8F58: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x800C8F5C: sra         $t8, $at, 13
    ctx->r24 = S32(SIGNED(ctx->r1) >> 13);
L_800C8F60:
    // 0x800C8F60: jal         0x800CADC0
    // 0x800C8F64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_37;
    // 0x800C8F64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_37:
    // 0x800C8F68: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800C8F6C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C8F70: addu        $t6, $t7, $fp
    ctx->r14 = ADD32(ctx->r15, ctx->r30);
    // 0x800C8F74: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x800C8F78: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800C8F7C: beql        $s0, $zero, L_800C8FC8
    if (ctx->r16 == 0) {
        // 0x800C8F80: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C8FC8;
    }
    goto skip_34;
    // 0x800C8F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_34:
    // 0x800C8F84: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C8F88: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800C8F8C:
    // 0x800C8F8C: bnel        $s3, $t9, L_800C8FBC
    if (ctx->r19 != ctx->r25) {
        // 0x800C8F90: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C8FBC;
    }
    goto skip_35;
    // 0x800C8F90: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_35:
    // 0x800C8F94: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C8F98: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800C8F9C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8FA0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C8FA4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8FA8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C8FAC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C8FB0: jal         0x800D3E70
    // 0x800C8FB4: nop

    alSynSetPitch(rdram, ctx);
        goto after_38;
    // 0x800C8FB4: nop

    after_38:
    // 0x800C8FB8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8FBC:
    // 0x800C8FBC: bnel        $s0, $zero, L_800C8F8C
    if (ctx->r16 != 0) {
        // 0x800C8FC0: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8F8C;
    }
    goto skip_36;
    // 0x800C8FC0: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_36:
L_800C8FC4:
    // 0x800C8FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8FC8:
    // 0x800C8FC8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x800C8FCC: jr          $ra
    // 0x800C8FD0: nop

    return;
    // 0x800C8FD0: nop

    // 0x800C8FD4: jr          $ra
    // 0x800C8FD8: nop

    return;
    // 0x800C8FD8: nop

;}
RECOMP_FUNC void func_800C8FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8FDC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800C8FE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C8FE4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C8FE8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800C8FEC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C8FF0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C8FF4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C8FF8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C8FFC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C9000: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C9004: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C9008: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C900C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9010: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C9014: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800C9018: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_800C901C:
    // 0x800C901C: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x800C9020: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800C9024: beq         $at, $zero, L_800C959C
    if (ctx->r1 == 0) {
        // 0x800C9028: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C959C;
    }
    // 0x800C9028: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C902C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9030: addu        $at, $at, $t7
    gpr jr_addend_800C9038 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C9034: lw          $t7, 0xF4($at)
    ctx->r15 = ADD32(ctx->r1, 0XF4);
    // 0x800C9038: jr          $t7
    // 0x800C903C: nop

    switch (jr_addend_800C9038 >> 2) {
        case 0: goto L_800C9040; break;
        case 1: goto L_800C959C; break;
        case 2: goto L_800C9370; break;
        case 3: goto L_800C959C; break;
        case 4: goto L_800C959C; break;
        case 5: goto L_800C912C; break;
        case 6: goto L_800C9178; break;
        case 7: goto L_800C938C; break;
        case 8: goto L_800C959C; break;
        case 9: goto L_800C910C; break;
        case 10: goto L_800C93AC; break;
        case 11: goto L_800C959C; break;
        case 12: goto L_800C953C; break;
        case 13: goto L_800C9558; break;
        case 14: goto L_800C958C; break;
        case 15: goto L_800C9410; break;
        case 16: goto L_800C9434; break;
        case 17: goto L_800C94A0; break;
        case 18: goto L_800C959C; break;
        case 19: goto L_800C959C; break;
        case 20: goto L_800C959C; break;
        case 21: goto L_800C9370; break;
        case 22: goto L_800C91DC; break;
        case 23: goto L_800C92E8; break;
        default: switch_error(__func__, 0x800C9038, 0x800F00F4);
    }
    // 0x800C903C: nop

L_800C9040:
    // 0x800C9040: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x800C9044: beql        $a0, $zero, L_800C95A0
    if (ctx->r4 == 0) {
        // 0x800C9048: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C95A0;
    }
    goto skip_0;
    // 0x800C9048: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x800C904C: jal         0x800CA444
    // 0x800C9050: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alCSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x800C9050: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x800C9054: lh          $t8, 0x58($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X58);
    // 0x800C9058: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C905C: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x800C9060: beq         $at, $zero, L_800C959C
    if (ctx->r1 == 0) {
        // 0x800C9064: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800C959C;
    }
    // 0x800C9064: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C9068: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C906C: addu        $at, $at, $t9
    gpr jr_addend_800C9074 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C9070: lw          $t9, 0x154($at)
    ctx->r25 = ADD32(ctx->r1, 0X154);
    // 0x800C9074: jr          $t9
    // 0x800C9078: nop

    switch (jr_addend_800C9074 >> 2) {
        case 0: goto L_800C907C; break;
        case 1: goto L_800C959C; break;
        case 2: goto L_800C90A4; break;
        case 3: goto L_800C90D0; break;
        case 4: goto L_800C959C; break;
        case 5: goto L_800C959C; break;
        case 6: goto L_800C959C; break;
        case 7: goto L_800C959C; break;
        case 8: goto L_800C959C; break;
        case 9: goto L_800C959C; break;
        case 10: goto L_800C959C; break;
        case 11: goto L_800C959C; break;
        case 12: goto L_800C959C; break;
        case 13: goto L_800C959C; break;
        case 14: goto L_800C959C; break;
        case 15: goto L_800C959C; break;
        case 16: goto L_800C959C; break;
        case 17: goto L_800C90FC; break;
        case 18: goto L_800C90FC; break;
        case 19: goto L_800C90FC; break;
        default: switch_error(__func__, 0x800C9074, 0x800F0154);
    }
    // 0x800C9078: nop

L_800C907C:
    // 0x800C907C: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x800C9080: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C9084: jal         0x800C87AC
    // 0x800C9088: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_1_800C87AC(rdram, ctx);
        goto after_1;
    // 0x800C9088: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_1:
    // 0x800C908C: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800C9090: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9094: jal         0x800C8530
    // 0x800C9098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_2;
    // 0x800C9098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800C909C: b           L_800C95A0
    // 0x800C90A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C90A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C90A4:
    // 0x800C90A4: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x800C90A8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800C90AC: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C90B0: jal         0x800C85DC
    // 0x800C90B4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_1_800C85DC(rdram, ctx);
        goto after_3;
    // 0x800C90B4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_3:
    // 0x800C90B8: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800C90BC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800C90C0: jal         0x800C8530
    // 0x800C90C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_4;
    // 0x800C90C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800C90C8: b           L_800C95A0
    // 0x800C90CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C90CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C90D0:
    // 0x800C90D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C90D4: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x800C90D8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C90DC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800C90E0: sh          $t7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r15;
    // 0x800C90E4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800C90E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C90EC: jal         0x800D3A2C
    // 0x800C90F0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x800C90F0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x800C90F4: b           L_800C95A0
    // 0x800C90F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C90F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C90FC:
    // 0x800C90FC: jal         0x800C8530
    // 0x800C9100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_6;
    // 0x800C9100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800C9104: b           L_800C95A0
    // 0x800C9108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C9108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C910C:
    // 0x800C910C: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800C9110: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C9114: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x800C9118: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C911C: jal         0x800D3A2C
    // 0x800C9120: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800C9120: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_7:
    // 0x800C9124: b           L_800C95A0
    // 0x800C9128: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C9128: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C912C:
    // 0x800C912C: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800C9130: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C9134: jal         0x800D3CA0
    // 0x800C9138: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_8;
    // 0x800C9138: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800C913C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C9140: jal         0x800D3D20
    // 0x800C9144: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_9;
    // 0x800C9144: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800C9148: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800C914C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C9150: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x800C9154: beql        $t9, $zero, L_800C9168
    if (ctx->r25 == 0) {
        // 0x800C9158: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C9168;
    }
    goto skip_1;
    // 0x800C9158: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x800C915C: jal         0x800D3610
    // 0x800C9160: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_10;
    // 0x800C9160: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x800C9164: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C9168:
    // 0x800C9168: jal         0x800D23E0
    // 0x800C916C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_11;
    // 0x800C916C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x800C9170: b           L_800C95A0
    // 0x800C9174: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C9174: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C9178:
    // 0x800C9178: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800C917C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C9180: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800C9184: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x800C9188: bnel        $t6, $zero, L_800C9198
    if (ctx->r14 != 0) {
        // 0x800C918C: lw          $s3, 0x40($s2)
        ctx->r19 = MEM_W(ctx->r18, 0X40);
            goto L_800C9198;
    }
    goto skip_2;
    // 0x800C918C: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    skip_2:
    // 0x800C9190: sb          $t7, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r15;
    // 0x800C9194: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
L_800C9198:
    // 0x800C9198: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x800C919C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C91A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C91A4: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x800C91A8: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x800C91AC: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    // 0x800C91B0: jal         0x800D2184
    // 0x800C91B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    __vsVol(rdram, ctx);
        goto after_12;
    // 0x800C91B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    after_12:
    // 0x800C91B8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800C91BC: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C91C0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C91C4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C91C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C91CC: jal         0x800D3DD0
    // 0x800C91D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    alSynSetVol(rdram, ctx);
        goto after_13;
    // 0x800C91D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_13:
    // 0x800C91D4: b           L_800C95A0
    // 0x800C91D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C91D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C91DC:
    // 0x800C91DC: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800C91E0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800C91E4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800C91E8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800C91EC: jalr        $t9
    // 0x800C91F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800C91F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x800C91F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C91F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C91FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C9200: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C9204: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C9208: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C920C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C9210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C9214: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C9218: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C921C: nop

    // 0x800C9220: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800C9224: beql        $t6, $zero, L_800C9274
    if (ctx->r14 == 0) {
        // 0x800C9228: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_800C9274;
    }
    goto skip_3;
    // 0x800C9228: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800C922C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C9230: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C9234: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C9238: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C923C: nop

    // 0x800C9240: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C9244: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C9248: nop

    // 0x800C924C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800C9250: bne         $t6, $zero, L_800C9268
    if (ctx->r14 != 0) {
        // 0x800C9254: nop

            goto L_800C9268;
    }
    // 0x800C9254: nop

    // 0x800C9258: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800C925C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C9260: b           L_800C9280
    // 0x800C9264: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800C9280;
    // 0x800C9264: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800C9268:
    // 0x800C9268: b           L_800C9280
    // 0x800C926C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800C9280;
    // 0x800C926C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C9270: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_800C9274:
    // 0x800C9274: nop

    // 0x800C9278: bltz        $t6, L_800C9268
    if (SIGNED(ctx->r14) < 0) {
        // 0x800C927C: nop

            goto L_800C9268;
    }
    // 0x800C927C: nop

L_800C9280:
    // 0x800C9280: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C9284: jal         0x800D2184
    // 0x800C9288: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    __vsVol(rdram, ctx);
        goto after_15;
    // 0x800C9288: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    after_15:
    // 0x800C928C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800C9290: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800C9294: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C9298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C929C: jal         0x800D2160
    // 0x800C92A0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_16;
    // 0x800C92A0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_16:
    // 0x800C92A4: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800C92A8: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C92AC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C92B0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C92B4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C92B8: jal         0x800D3DD0
    // 0x800C92BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x800C92BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_17:
    // 0x800C92C0: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800C92C4: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C92C8: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x800C92CC: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x800C92D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C92D4: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C92D8: jal         0x800D3A2C
    // 0x800C92DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x800C92DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_18:
    // 0x800C92E0: b           L_800C95A0
    // 0x800C92E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C92E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C92E8:
    // 0x800C92E8: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800C92EC: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800C92F0: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800C92F4: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800C92F8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800C92FC: jalr        $t9
    // 0x800C9300: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x800C9300: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_19:
    // 0x800C9304: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C9308: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800C930C: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x800C9310: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800C9314: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800C9318: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x800C931C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C9320: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C9324: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C9328: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800C932C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C9330: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C9334: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800C9338: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C933C: jal         0x800D3E70
    // 0x800C9340: nop

    alSynSetPitch(rdram, ctx);
        goto after_20;
    // 0x800C9340: nop

    after_20:
    // 0x800C9344: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x800C9348: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800C934C: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x800C9350: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x800C9354: sb          $s0, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r16;
    // 0x800C9358: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C935C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C9360: jal         0x800D3A2C
    // 0x800C9364: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_21;
    // 0x800C9364: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_21:
    // 0x800C9368: b           L_800C95A0
    // 0x800C936C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C936C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C9370:
    // 0x800C9370: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800C9374: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C9378: jal         0x800C87AC
    // 0x800C937C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_1_800C87AC(rdram, ctx);
        goto after_22;
    // 0x800C937C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_22:
    // 0x800C9380: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800C9384: b           L_800C959C
    // 0x800C9388: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_800C959C;
    // 0x800C9388: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_800C938C:
    // 0x800C938C: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x800C9390: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800C9394: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C9398: jal         0x800C85DC
    // 0x800C939C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_1_800C85DC(rdram, ctx);
        goto after_23;
    // 0x800C939C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_23:
    // 0x800C93A0: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800C93A4: b           L_800C959C
    // 0x800C93A8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_800C959C;
    // 0x800C93A8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_800C93AC:
    // 0x800C93AC: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800C93B0: lh          $t6, 0x3C($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3C);
    // 0x800C93B4: beq         $s1, $zero, L_800C959C
    if (ctx->r17 == 0) {
        // 0x800C93B8: sh          $t6, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r14;
            goto L_800C959C;
    }
    // 0x800C93B8: sh          $t6, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r14;
    // 0x800C93BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800C93C0:
    // 0x800C93C0: jal         0x800D2184
    // 0x800C93C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_24;
    // 0x800C93C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x800C93C8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800C93CC: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800C93D0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C93D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C93D8: jal         0x800D2160
    // 0x800C93DC: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __vsDelta(rdram, ctx);
        goto after_25;
    // 0x800C93DC: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_25:
    // 0x800C93E0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800C93E4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C93E8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C93EC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C93F0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C93F4: jal         0x800D3DD0
    // 0x800C93F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x800C93F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x800C93FC: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800C9400: bnel        $s1, $zero, L_800C93C0
    if (ctx->r17 != 0) {
        // 0x800C9404: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C93C0;
    }
    goto skip_4;
    // 0x800C9404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x800C9408: b           L_800C95A0
    // 0x800C940C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C940C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C9410:
    // 0x800C9410: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x800C9414: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C9418: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C941C: beq         $t9, $at, L_800C959C
    if (ctx->r25 == ctx->r1) {
        // 0x800C9420: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C959C;
    }
    // 0x800C9420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C9424: jal         0x800C8530
    // 0x800C9428: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_27;
    // 0x800C9428: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    after_27:
    // 0x800C942C: b           L_800C95A0
    // 0x800C9430: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C9430: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C9434:
    // 0x800C9434: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x800C9438: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C943C: bnel        $t7, $at, L_800C95A0
    if (ctx->r15 != ctx->r1) {
        // 0x800C9440: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C95A0;
    }
    goto skip_5;
    // 0x800C9440: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_5:
    // 0x800C9444: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800C9448: beq         $s1, $zero, L_800C9498
    if (ctx->r17 == 0) {
        // 0x800C944C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C9498;
    }
    // 0x800C944C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800C9450:
    // 0x800C9450: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C9454: jal         0x800D3CA0
    // 0x800C9458: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    alSynStopVoice(rdram, ctx);
        goto after_28;
    // 0x800C9458: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_28:
    // 0x800C945C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C9460: jal         0x800D3D20
    // 0x800C9464: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_29;
    // 0x800C9464: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_29:
    // 0x800C9468: lbu         $t8, 0x37($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X37);
    // 0x800C946C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C9470: beql        $t8, $zero, L_800C9484
    if (ctx->r24 == 0) {
        // 0x800C9474: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C9484;
    }
    goto skip_6;
    // 0x800C9474: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
    // 0x800C9478: jal         0x800D3610
    // 0x800C947C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_30;
    // 0x800C947C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x800C9480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C9484:
    // 0x800C9484: jal         0x800D23E0
    // 0x800C9488: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_31;
    // 0x800C9488: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_31:
    // 0x800C948C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800C9490: bnel        $s1, $zero, L_800C9450
    if (ctx->r17 != 0) {
        // 0x800C9494: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C9450;
    }
    goto skip_7;
    // 0x800C9494: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_7:
L_800C9498:
    // 0x800C9498: b           L_800C959C
    // 0x800C949C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_800C959C;
    // 0x800C949C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_800C94A0:
    // 0x800C94A0: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x800C94A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C94A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C94AC: bnel        $t9, $at, L_800C95A0
    if (ctx->r25 != ctx->r1) {
        // 0x800C94B0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C95A0;
    }
    goto skip_8;
    // 0x800C94B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_8:
    // 0x800C94B4: jal         0x800D3910
    // 0x800C94B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_32;
    // 0x800C94B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x800C94BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C94C0: jal         0x800D3910
    // 0x800C94C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    alEvtqFlushType(rdram, ctx);
        goto after_33;
    // 0x800C94C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_33:
    // 0x800C94C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C94CC: jal         0x800D3910
    // 0x800C94D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_34;
    // 0x800C94D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x800C94D4: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800C94D8: beq         $s1, $zero, L_800C9510
    if (ctx->r17 == 0) {
        // 0x800C94DC: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C9510;
    }
    // 0x800C94DC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800C94E0:
    // 0x800C94E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C94E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C94E8: jal         0x800D2338
    // 0x800C94EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_35;
    // 0x800C94EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_35:
    // 0x800C94F0: beq         $v0, $zero, L_800C9504
    if (ctx->r2 == 0) {
        // 0x800C94F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C9504;
    }
    // 0x800C94F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C94F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C94FC: jal         0x800D220C
    // 0x800C9500: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __seqpReleaseVoice(rdram, ctx);
        goto after_36;
    // 0x800C9500: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_36:
L_800C9504:
    // 0x800C9504: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800C9508: bnel        $s1, $zero, L_800C94E0
    if (ctx->r17 != 0) {
        // 0x800C950C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C94E0;
    }
    goto skip_9;
    // 0x800C950C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_9:
L_800C9510:
    // 0x800C9510: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C9514: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x800C9518: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C951C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800C9520: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800C9524: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800C9528: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C952C: jal         0x800D3A2C
    // 0x800C9530: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_37;
    // 0x800C9530: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_37:
    // 0x800C9534: b           L_800C95A0
    // 0x800C9538: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C9538: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C953C:
    // 0x800C953C: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x800C9540: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800C9544: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x800C9548: sll         $t6, $s0, 4
    ctx->r14 = S32(ctx->r16 << 4);
    // 0x800C954C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800C9550: b           L_800C959C
    // 0x800C9554: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_800C959C;
    // 0x800C9554: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_800C9558:
    // 0x800C9558: lw          $t9, 0x3C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X3C);
    // 0x800C955C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9560: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C9564: sw          $t9, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r25;
    // 0x800C9568: jal         0x800C85A0
    // 0x800C956C: lwc1        $f12, 0x1A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1A4);
    func_800C85A0(rdram, ctx);
        goto after_38;
    // 0x800C956C: lwc1        $f12, 0x1A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1A4);
    after_38:
    // 0x800C9570: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x800C9574: beql        $a1, $zero, L_800C95A0
    if (ctx->r5 == 0) {
        // 0x800C9578: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C95A0;
    }
    goto skip_10;
    // 0x800C9578: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_10:
    // 0x800C957C: jal         0x800D20A4
    // 0x800C9580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_39;
    // 0x800C9580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_39:
    // 0x800C9584: b           L_800C95A0
    // 0x800C9588: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C95A0;
    // 0x800C9588: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C958C:
    // 0x800C958C: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x800C9590: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C9594: jal         0x800D20A4
    // 0x800C9598: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_40;
    // 0x800C9598: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_40:
L_800C959C:
    // 0x800C959C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C95A0:
    // 0x800C95A0: jal         0x800D3B50
    // 0x800C95A4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    alEvtqNextEvent(rdram, ctx);
        goto after_41;
    // 0x800C95A4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_41:
    // 0x800C95A8: beq         $v0, $zero, L_800C901C
    if (ctx->r2 == 0) {
        // 0x800C95AC: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800C901C;
    }
    // 0x800C95AC: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x800C95B0: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x800C95B4: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C95B8: sw          $t8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r24;
    // 0x800C95BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C95C0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C95C4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C95C8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C95CC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C95D0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C95D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C95D8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C95DC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C95E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C95E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C95E8: jr          $ra
    // 0x800C95EC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800C95EC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void alCSPNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C95F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C95F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C95F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C95FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C9600: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800C9604: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800C9608: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800C960C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9610: lw          $t6, -0x33E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33E0);
    // 0x800C9614: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C9618: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800C961C: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800C9620: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x800C9624: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x800C9628: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800C962C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800C9630: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800C9634: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x800C9638: sw          $t0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r8;
    // 0x800C963C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800C9640: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800C9644: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x800C9648: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x800C964C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C9650: sw          $t1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r9;
    // 0x800C9654: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x800C9658: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C965C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800C9660: sw          $t2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r10;
    // 0x800C9664: lw          $t3, 0x18($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X18);
    // 0x800C9668: sh          $t4, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r12;
    // 0x800C966C: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
    // 0x800C9670: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800C9674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9678: sb          $t5, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r13;
    // 0x800C967C: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x800C9680: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C9684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9688: jal         0x800C7950
    // 0x800C968C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800C968C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C9690: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800C9694: jal         0x800D3714
    // 0x800C9698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __initChanState(rdram, ctx);
        goto after_1;
    // 0x800C9698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C969C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C96A0: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800C96A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C96A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C96AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C96B0: jal         0x800C7950
    // 0x800C96B4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800C96B4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800C96B8: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800C96BC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800C96C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C96C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C96C8: blez        $t8, L_800C96F8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C96CC: addiu       $t1, $zero, 0x1C
        ctx->r9 = ADD32(0, 0X1C);
            goto L_800C96F8;
    }
    // 0x800C96CC: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x800C96D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C96D4: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
L_800C96D8:
    // 0x800C96D8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C96DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C96E0: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x800C96E4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800C96E8: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800C96EC: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C96F0: bnel        $at, $zero, L_800C96D8
    if (ctx->r1 != 0) {
        // 0x800C96F4: lw          $t9, 0x6C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X6C);
            goto L_800C96D8;
    }
    goto skip_0;
    // 0x800C96F4: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_800C96F8:
    // 0x800C96F8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800C96FC: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800C9700: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800C9704: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C9708: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C970C: jal         0x800C7950
    // 0x800C9710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800C9710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800C9714: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800C9718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C971C: jal         0x800D3BDC
    // 0x800C9720: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x800C9720: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x800C9724: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800C9728: addiu       $t2, $t2, -0x7024
    ctx->r10 = ADD32(ctx->r10, -0X7024);
    // 0x800C972C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800C9730: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800C9734: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800C9738: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C973C: lw          $a0, -0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33E0);
    // 0x800C9740: jal         0x800D3C50
    // 0x800C9744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x800C9744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800C9748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C974C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9750: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C9754: jr          $ra
    // 0x800C9758: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C9758: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800C975C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C975C: nop

;}
RECOMP_FUNC void alSndpSetSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9760: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800C9764: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C9768: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C976C: jr          $ra
    // 0x800C9770: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    return;
    // 0x800C9770: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800C9774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9774: nop

    // 0x800C9778: nop

    // 0x800C977C: nop

;}
RECOMP_FUNC void alSndpStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9780: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9788: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800C978C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C9790: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800C9794: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800C9798: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C979C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800C97A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C97A4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800C97A8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800C97AC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C97B0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800C97B4: jal         0x800D3A2C
    // 0x800C97B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C97B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C97BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C97C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C97C4: jr          $ra
    // 0x800C97C8: nop

    return;
    // 0x800C97C8: nop

;}
RECOMP_FUNC void func_800C97CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C97CC: nop

;}
