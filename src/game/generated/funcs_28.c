#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800705D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800705D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800705DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800705E0: jal         0x80061348
    // 0x800705E4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800705E4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800705E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800705EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800705F0: beq         $v0, $zero, L_80070640
    if (ctx->r2 == 0) {
        // 0x800705F4: nop
    
            goto L_80070640;
    }
    // 0x800705F4: nop

    // 0x800705F8: jal         0x80061348
    // 0x800705FC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800705FC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070600: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070604: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070608: beq         $v0, $zero, L_80070640
    if (ctx->r2 == 0) {
        // 0x8007060C: nop
    
            goto L_80070640;
    }
    // 0x8007060C: nop

    // 0x80070610: jal         0x80061348
    // 0x80070614: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070614: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070618: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007061C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070620: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070624: beq         $v0, $zero, L_80070640
    if (ctx->r2 == 0) {
        // 0x80070628: nop
    
            goto L_80070640;
    }
    // 0x80070628: nop

    // 0x8007062C: jal         0x80061348
    // 0x80070630: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070630: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070634: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070638: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007063C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070640:
    // 0x80070640: b           L_80070650
    // 0x80070644: nop

        goto L_80070650;
    // 0x80070644: nop

    // 0x80070648: b           L_80070650
    // 0x8007064C: nop

        goto L_80070650;
    // 0x8007064C: nop

L_80070650:
    // 0x80070650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070658: jr          $ra
    // 0x8007065C: nop

    return;
    // 0x8007065C: nop

;}
RECOMP_FUNC void func_800BCBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCBF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BCBFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCC00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCC04: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCC08: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCC0C: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCC10: nop

    // 0x800BCC14: beq         $t6, $t7, L_800BCC74
    if (ctx->r14 == ctx->r15) {
        // 0x800BCC18: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800BCC74;
    }
    // 0x800BCC18: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800BCC1C:
    // 0x800BCC1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC20: nop

    // 0x800BCC24: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BCC28: nop

    // 0x800BCC2C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BCC30: bne         $t0, $zero, L_800BCC40
    if (ctx->r8 != 0) {
        // 0x800BCC34: nop
    
            goto L_800BCC40;
    }
    // 0x800BCC34: nop

    // 0x800BCC38: b           L_800BCC58
    // 0x800BCC3C: nop

        goto L_800BCC58;
    // 0x800BCC3C: nop

L_800BCC40:
    // 0x800BCC40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC44: jal         0x800BCCE4
    // 0x800BCC48: nop

    func_800BCCE4(rdram, ctx);
        goto after_0;
    // 0x800BCC48: nop

    after_0:
    // 0x800BCC4C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC50: jal         0x800BC980
    // 0x800BCC54: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800BCC54: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
L_800BCC58:
    // 0x800BCC58: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC5C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BCC60: lw          $t3, 0x25E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X25E8);
    // 0x800BCC64: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800BCC68: nop

    // 0x800BCC6C: bne         $t2, $t3, L_800BCC1C
    if (ctx->r10 != ctx->r11) {
        // 0x800BCC70: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800BCC1C;
    }
    // 0x800BCC70: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_800BCC74:
    // 0x800BCC74: b           L_800BCC7C
    // 0x800BCC78: nop

        goto L_800BCC7C;
    // 0x800BCC78: nop

L_800BCC7C:
    // 0x800BCC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCC80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BCC84: jr          $ra
    // 0x800BCC88: nop

    return;
    // 0x800BCC88: nop

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
RECOMP_FUNC void func_800A3FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3FC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A3FCC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A3FD0: nop

    // 0x800A3FD4: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x800A3FD8: nop

    // 0x800A3FDC: beq         $t7, $zero, L_800A3FF8
    if (ctx->r15 == 0) {
        // 0x800A3FE0: nop
    
            goto L_800A3FF8;
    }
    // 0x800A3FE0: nop

    // 0x800A3FE4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A3FE8: nop

    // 0x800A3FEC: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x800A3FF0: jal         0x800BC980
    // 0x800A3FF4: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800A3FF4: nop

    after_0:
L_800A3FF8:
    // 0x800A3FF8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800A3FFC: nop

    // 0x800A4000: lw          $t0, 0x12C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X12C);
    // 0x800A4004: nop

    // 0x800A4008: beq         $t0, $zero, L_800A4024
    if (ctx->r8 == 0) {
        // 0x800A400C: nop
    
            goto L_800A4024;
    }
    // 0x800A400C: nop

    // 0x800A4010: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A4014: nop

    // 0x800A4018: lw          $a0, 0x12C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X12C);
    // 0x800A401C: jal         0x800BC980
    // 0x800A4020: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800A4020: nop

    after_1:
L_800A4024:
    // 0x800A4024: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800A4028: nop

    // 0x800A402C: lw          $t3, 0x130($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X130);
    // 0x800A4030: nop

    // 0x800A4034: beq         $t3, $zero, L_800A4050
    if (ctx->r11 == 0) {
        // 0x800A4038: nop
    
            goto L_800A4050;
    }
    // 0x800A4038: nop

    // 0x800A403C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800A4040: nop

    // 0x800A4044: lw          $a0, 0x130($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X130);
    // 0x800A4048: jal         0x800BC980
    // 0x800A404C: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800A404C: nop

    after_2:
L_800A4050:
    // 0x800A4050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A4054: jal         0x800BC980
    // 0x800A4058: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800A4058: nop

    after_3:
    // 0x800A405C: b           L_800A4064
    // 0x800A4060: nop

        goto L_800A4064;
    // 0x800A4060: nop

L_800A4064:
    // 0x800A4064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A406C: jr          $ra
    // 0x800A4070: nop

    return;
    // 0x800A4070: nop

;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4630: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800D4634: bne         $at, $zero, L_800D46AC
    if (ctx->r1 != 0) {
        // 0x800D4638: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_800D46AC;
    }
    // 0x800D4638: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800D463C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800D4640: beq         $v1, $zero, L_800D4650
    if (ctx->r3 == 0) {
        // 0x800D4644: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800D4650;
    }
    // 0x800D4644: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800D4648: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800D464C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800D4650:
    // 0x800D4650: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D4654: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D4658: beq         $a3, $zero, L_800D468C
    if (ctx->r7 == 0) {
        // 0x800D465C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D468C;
    }
    // 0x800D465C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D4660: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D4664:
    // 0x800D4664: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D4668: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800D466C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800D4670: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800D4674: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800D4678: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800D467C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x800D4680: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x800D4684: bne         $a0, $a3, L_800D4664
    if (ctx->r4 != ctx->r7) {
        // 0x800D4688: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D4664;
    }
    // 0x800D4688: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D468C:
    // 0x800D468C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4690: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D4694: beq         $a3, $zero, L_800D46AC
    if (ctx->r7 == 0) {
        // 0x800D4698: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D46AC;
    }
    // 0x800D4698: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D469C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D46A0:
    // 0x800D46A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D46A4: bne         $a0, $a3, L_800D46A0
    if (ctx->r4 != ctx->r7) {
        // 0x800D46A8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D46A0;
    }
    // 0x800D46A8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D46AC:
    // 0x800D46AC: blez        $a1, L_800D46C4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D46B0: nop
    
            goto L_800D46C4;
    }
    // 0x800D46B0: nop

    // 0x800D46B4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800D46B8:
    // 0x800D46B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D46BC: bne         $a0, $a1, L_800D46B8
    if (ctx->r4 != ctx->r5) {
        // 0x800D46C0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800D46B8;
    }
    // 0x800D46C0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800D46C4:
    // 0x800D46C4: jr          $ra
    // 0x800D46C8: nop

    return;
    // 0x800D46C8: nop

;}
RECOMP_FUNC void func_80086F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086F60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086F64: jal         0x8008BFF4
    // 0x80086F68: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x80086F68: nop

    after_0:
    // 0x80086F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086F70: jal         0x80089170
    // 0x80086F74: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80086F74: nop

    after_1:
    // 0x80086F78: b           L_80086F88
    // 0x80086F7C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80086F88;
    // 0x80086F7C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80086F80: b           L_80086F88
    // 0x80086F84: nop

        goto L_80086F88;
    // 0x80086F84: nop

L_80086F88:
    // 0x80086F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086F90: jr          $ra
    // 0x80086F94: nop

    return;
    // 0x80086F94: nop

;}
RECOMP_FUNC void func_80098754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098754: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009875C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80098760: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80098764: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80098768: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8009876C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098770: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80098774: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80098778: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8009877C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098780: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80098784: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x80098788: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009878C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80098790: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098794: nop

    // 0x80098798: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8009879C: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800987A0: nop

    // 0x800987A4: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800987A8: bne         $t2, $zero, L_800987B8
    if (ctx->r10 != 0) {
        // 0x800987AC: nop
    
            goto L_800987B8;
    }
    // 0x800987AC: nop

    // 0x800987B0: b           L_80098810
    // 0x800987B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098810;
    // 0x800987B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800987B8:
    // 0x800987B8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800987BC: jal         0x800C1154
    // 0x800987C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C1154(rdram, ctx);
        goto after_0;
    // 0x800987C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800987C4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800987C8: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x800987CC: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    // 0x800987D0: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800987D4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800987D8: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x800987DC: jal         0x80097258
    // 0x800987E0: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    func_80097258(rdram, ctx);
        goto after_1;
    // 0x800987E0: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    after_1:
    // 0x800987E4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800987E8: nop

    // 0x800987EC: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x800987F0: lbu         $t5, 0x2E9($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2E9);
    // 0x800987F4: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x800987F8: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x800987FC: sb          $t6, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r14;
    // 0x80098800: b           L_80098810
    // 0x80098804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098810;
    // 0x80098804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098808: b           L_80098810
    // 0x8009880C: nop

        goto L_80098810;
    // 0x8009880C: nop

L_80098810:
    // 0x80098810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098818: jr          $ra
    // 0x8009881C: nop

    return;
    // 0x8009881C: nop

;}
RECOMP_FUNC void func_80097150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097158: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009715C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097160: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80097164: jal         0x800C41A0
    // 0x80097168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80097168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009716C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097170: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097174: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097178: nop

    // 0x8009717C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80097180: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80097184: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097188: lw          $t9, 0x280($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X280);
    // 0x8009718C: nop

    // 0x80097190: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80097194: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80097198: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8009719C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x800971A0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800971A4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800971A8: nop

    // 0x800971AC: sw          $t3, 0x280($t4)
    MEM_W(0X280, ctx->r12) = ctx->r11;
    // 0x800971B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800971B4: jal         0x800C41A0
    // 0x800971B8: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800971B8: nop

    after_1:
    // 0x800971BC: b           L_800971C4
    // 0x800971C0: nop

        goto L_800971C4;
    // 0x800971C0: nop

L_800971C4:
    // 0x800971C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800971C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800971CC: jr          $ra
    // 0x800971D0: nop

    return;
    // 0x800971D0: nop

;}
RECOMP_FUNC void func_80086BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80086BF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80086BF4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80086BF8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80086BFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80086C00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086C04: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80086C08: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80086C0C: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80086C10: lhu         $t9, 0x4E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4E);
    // 0x80086C14: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086C18: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086C1C: beq         $t0, $zero, L_80086E00
    if (ctx->r8 == 0) {
        // 0x80086C20: nop
    
            goto L_80086E00;
    }
    // 0x80086C20: nop

    // 0x80086C24: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80086C28: jal         0x8008A518
    // 0x80086C2C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80086C2C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80086C30: beq         $v0, $zero, L_80086E00
    if (ctx->r2 == 0) {
        // 0x80086C34: nop
    
            goto L_80086E00;
    }
    // 0x80086C34: nop

    // 0x80086C38: lhu         $t1, 0x3C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086C3C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086C40: bne         $t1, $at, L_80086C70
    if (ctx->r9 != ctx->r1) {
        // 0x80086C44: nop
    
            goto L_80086C70;
    }
    // 0x80086C44: nop

    // 0x80086C48: jal         0x8008CE48
    // 0x80086C4C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80086C4C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80086C50: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80086C54: nop

    // 0x80086C58: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086C5C: nop

    // 0x80086C60: ori         $t4, $t3, 0x200
    ctx->r12 = ctx->r11 | 0X200;
    // 0x80086C64: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80086C68: b           L_80086E54
    // 0x80086C6C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80086E54;
    // 0x80086C6C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80086C70:
    // 0x80086C70: lhu         $t5, 0x3C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086C74: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086C78: slt         $at, $t5, $at
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086C7C: bne         $at, $zero, L_80086E00
    if (ctx->r1 != 0) {
        // 0x80086C80: nop
    
            goto L_80086E00;
    }
    // 0x80086C80: nop

    // 0x80086C84: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80086C88: slt         $at, $t5, $at
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086C8C: beq         $at, $zero, L_80086E00
    if (ctx->r1 == 0) {
        // 0x80086C90: nop
    
            goto L_80086E00;
    }
    // 0x80086C90: nop

    // 0x80086C94: lhu         $t6, 0x3C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086C98: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086C9C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80086CA0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80086CA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80086CA8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80086CAC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80086CB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80086CB4: addiu       $t8, $t8, 0x7AE8
    ctx->r24 = ADD32(ctx->r24, 0X7AE8);
    // 0x80086CB8: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x80086CBC: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80086CC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80086CC4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80086CC8: nop

    // 0x80086CCC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80086CD0: nop

    // 0x80086CD4: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086CD8: beq         $t4, $zero, L_80086DEC
    if (ctx->r12 == 0) {
        // 0x80086CDC: nop
    
            goto L_80086DEC;
    }
    // 0x80086CDC: nop

    // 0x80086CE0: lhu         $s0, 0x3C($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086CE4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80086CE8: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x80086CEC: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x80086CF0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80086CF4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80086CF8: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80086CFC: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80086D00: sh          $s0, 0xBEA($t6)
    MEM_H(0XBEA, ctx->r14) = ctx->r16;
    // 0x80086D04: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80086D08: nop

    // 0x80086D0C: lh          $t9, 0xBE8($t7)
    ctx->r25 = MEM_H(ctx->r15, 0XBE8);
    // 0x80086D10: nop

    // 0x80086D14: bne         $s0, $t9, L_80086D38
    if (ctx->r16 != ctx->r25) {
        // 0x80086D18: nop
    
            goto L_80086D38;
    }
    // 0x80086D18: nop

    // 0x80086D1C: jal         0x8008CE48
    // 0x80086D20: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80086D20: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x80086D24: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086D28: jal         0x8008A730
    // 0x80086D2C: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    func_8008A730(rdram, ctx);
        goto after_3;
    // 0x80086D2C: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_3:
    // 0x80086D30: b           L_80086DE4
    // 0x80086D34: nop

        goto L_80086DE4;
    // 0x80086D34: nop

L_80086D38:
    // 0x80086D38: jal         0x8008CE48
    // 0x80086D3C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x80086D3C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x80086D40: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80086D44: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80086D48: jal         0x800898D8
    // 0x80086D4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800898D8(rdram, ctx);
        goto after_5;
    // 0x80086D4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_5:
    // 0x80086D50: beq         $v0, $zero, L_80086DA0
    if (ctx->r2 == 0) {
        // 0x80086D54: nop
    
            goto L_80086DA0;
    }
    // 0x80086D54: nop

    // 0x80086D58: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x80086D5C: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x80086D60: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80086D64: lh          $t4, 0x38($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X38);
    // 0x80086D68: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x80086D6C: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80086D70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086D74: bgez        $a1, L_80086D84
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80086D78: sra         $t1, $a1, 1
        ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80086D84;
    }
    // 0x80086D78: sra         $t1, $a1, 1
    ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80086D7C: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80086D80: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80086D84:
    // 0x80086D84: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80086D88: bgez        $a2, L_80086D98
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80086D8C: sra         $t2, $a2, 1
        ctx->r10 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80086D98;
    }
    // 0x80086D8C: sra         $t2, $a2, 1
    ctx->r10 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80086D90: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80086D94: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_80086D98:
    // 0x80086D98: jal         0x80089B04
    // 0x80086D9C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    func_80089B04(rdram, ctx);
        goto after_6;
    // 0x80086D9C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_6:
L_80086DA0:
    // 0x80086DA0: lh          $t5, 0x44($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X44);
    // 0x80086DA4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086DA8: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x80086DAC: lh          $a2, 0x40($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X40);
    // 0x80086DB0: lh          $a3, 0x42($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X42);
    // 0x80086DB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80086DB8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80086DBC: jal         0x8008A368
    // 0x80086DC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8008A368(rdram, ctx);
        goto after_7;
    // 0x80086DC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x80086DC4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80086DC8: nop

    // 0x80086DCC: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x80086DD0: nop

    // 0x80086DD4: ori         $t8, $t9, 0x200
    ctx->r24 = ctx->r25 | 0X200;
    // 0x80086DD8: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x80086DDC: b           L_80086E54
    // 0x80086DE0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80086E54;
    // 0x80086DE0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80086DE4:
    // 0x80086DE4: b           L_80086E00
    // 0x80086DE8: nop

        goto L_80086E00;
    // 0x80086DE8: nop

L_80086DEC:
    // 0x80086DEC: jal         0x8008CE48
    // 0x80086DF0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80086DF0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_8:
    // 0x80086DF4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086DF8: jal         0x8008A730
    // 0x80086DFC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_9;
    // 0x80086DFC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_9:
L_80086E00:
    // 0x80086E00: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80086E04: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x80086E08: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x80086E0C: nop

    // 0x80086E10: and         $t3, $t0, $t1
    ctx->r11 = ctx->r8 & ctx->r9;
    // 0x80086E14: beq         $t3, $zero, L_80086E44
    if (ctx->r11 == 0) {
        // 0x80086E18: nop
    
            goto L_80086E44;
    }
    // 0x80086E18: nop

    // 0x80086E1C: jal         0x8008CE48
    // 0x80086E20: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80086E20: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80086E24: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80086E28: nop

    // 0x80086E2C: lhu         $t2, 0x0($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X0);
    // 0x80086E30: nop

    // 0x80086E34: ori         $t5, $t2, 0x200
    ctx->r13 = ctx->r10 | 0X200;
    // 0x80086E38: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
    // 0x80086E3C: b           L_80086E54
    // 0x80086E40: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80086E54;
    // 0x80086E40: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80086E44:
    // 0x80086E44: b           L_80086E54
    // 0x80086E48: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80086E54;
    // 0x80086E48: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80086E4C: b           L_80086E54
    // 0x80086E50: nop

        goto L_80086E54;
    // 0x80086E50: nop

L_80086E54:
    // 0x80086E54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80086E58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086E5C: jr          $ra
    // 0x80086E60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80086E60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
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
RECOMP_FUNC void func_80064BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064C00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064C04: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064C08: nop

    // 0x80064C0C: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064C10: nop

    // 0x80064C14: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80064C18: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064C20: beq         $v0, $zero, L_80064C38
    if (ctx->r2 == 0) {
        // 0x80064C24: nop
    
            goto L_80064C38;
    }
    // 0x80064C24: nop

    // 0x80064C28: jal         0x8005F064
    // 0x80064C2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064C2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064C30: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064C34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80064C38:
    // 0x80064C38: b           L_80064C48
    // 0x80064C3C: nop

        goto L_80064C48;
    // 0x80064C3C: nop

    // 0x80064C40: b           L_80064C48
    // 0x80064C44: nop

        goto L_80064C48;
    // 0x80064C44: nop

L_80064C48:
    // 0x80064C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064C50: jr          $ra
    // 0x80064C54: nop

    return;
    // 0x80064C54: nop

;}
RECOMP_FUNC void func_80065E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E2C: jal         0x80061488
    // 0x80065E30: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065E30: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x80065E34: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065E38: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065E3C: b           L_80065E4C
    // 0x80065E40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065E4C;
    // 0x80065E40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065E44: b           L_80065E4C
    // 0x80065E48: nop

        goto L_80065E4C;
    // 0x80065E48: nop

L_80065E4C:
    // 0x80065E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065E54: jr          $ra
    // 0x80065E58: nop

    return;
    // 0x80065E58: nop

;}
RECOMP_FUNC void alSndpAllocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F50: lw          $a2, 0x44($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X44);
    // 0x800C9F54: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800C9F58: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9F5C: blez        $a2, L_800C9FE0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C9F60: addiu       $a3, $zero, 0x30
        ctx->r7 = ADD32(0, 0X30);
            goto L_800C9FE0;
    }
    // 0x800C9F60: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
L_800C9F64:
    // 0x800C9F64: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9F68: mflo        $t6
    ctx->r14 = lo;
    // 0x800C9F6C: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800C9F70: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x800C9F74: bne         $t7, $zero, L_800C9FC8
    if (ctx->r15 != 0) {
        // 0x800C9F78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800C9FC8;
    }
    // 0x800C9F78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9F7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C9F80: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800C9F84: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x800C9F88: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x800C9F8C: sh          $t8, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r24;
    // 0x800C9F90: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800C9F94: sb          $t9, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r25;
    // 0x800C9F98: sb          $zero, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = 0;
    // 0x800C9F9C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800C9FA0: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x800C9FA4: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800C9FA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C9FAC: sll         $t1, $t0, 15
    ctx->r9 = S32(ctx->r8 << 15);
    // 0x800C9FB0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C9FB4: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800C9FB8: mflo        $t2
    ctx->r10 = lo;
    // 0x800C9FBC: sh          $t2, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r10;
    // 0x800C9FC0: jr          $ra
    // 0x800C9FC4: nop

    return;
    // 0x800C9FC4: nop

L_800C9FC8:
    // 0x800C9FC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C9FCC: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x800C9FD0: sra         $v1, $t3, 16
    ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800C9FD4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C9FD8: bne         $at, $zero, L_800C9F64
    if (ctx->r1 != 0) {
        // 0x800C9FDC: nop
    
            goto L_800C9F64;
    }
    // 0x800C9FDC: nop

L_800C9FE0:
    // 0x800C9FE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C9FE4: jr          $ra
    // 0x800C9FE8: nop

    return;
    // 0x800C9FE8: nop

;}
RECOMP_FUNC void func_800A5624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A5628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A562C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A5630: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A5634: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A5638: nop

    // 0x800A563C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800A5640: bne         $at, $zero, L_800A5650
    if (ctx->r1 != 0) {
        // 0x800A5644: nop
    
            goto L_800A5650;
    }
    // 0x800A5644: nop

    // 0x800A5648: b           L_800A57B4
    // 0x800A564C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A57B4;
    // 0x800A564C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A5650:
    // 0x800A5650: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800A5654: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5658: sw          $t7, -0x7268($at)
    MEM_W(-0X7268, ctx->r1) = ctx->r15;
    // 0x800A565C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A5660: lw          $t8, -0x7268($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7268);
    // 0x800A5664: nop

    // 0x800A5668: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x800A566C: beq         $at, $zero, L_800A5790
    if (ctx->r1 == 0) {
        // 0x800A5670: nop
    
            goto L_800A5790;
    }
    // 0x800A5670: nop

    // 0x800A5674: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A5678: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A567C: addu        $at, $at, $t8
    gpr jr_addend_800A5688 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800A5680: lw          $t8, -0x798($at)
    ctx->r24 = ADD32(ctx->r1, -0X798);
    // 0x800A5684: nop

    // 0x800A5688: jr          $t8
    // 0x800A568C: nop

    switch (jr_addend_800A5688 >> 2) {
        case 0: goto L_800A5690; break;
        case 1: goto L_800A56B0; break;
        case 2: goto L_800A56D0; break;
        case 3: goto L_800A56F0; break;
        case 4: goto L_800A5710; break;
        case 5: goto L_800A5730; break;
        case 6: goto L_800A5750; break;
        case 7: goto L_800A5770; break;
        default: switch_error(__func__, 0x800A5688, 0x800EF868);
    }
    // 0x800A568C: nop

L_800A5690:
    // 0x800A5690: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5694: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5698: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A569C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A56A0: jal         0x800BCFCC
    // 0x800A56A4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800A56A4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x800A56A8: b           L_800A5790
    // 0x800A56AC: nop

        goto L_800A5790;
    // 0x800A56AC: nop

L_800A56B0:
    // 0x800A56B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A56B4: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A56B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A56BC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A56C0: jal         0x800BCFCC
    // 0x800A56C4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x800A56C4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_1:
    // 0x800A56C8: b           L_800A5790
    // 0x800A56CC: nop

        goto L_800A5790;
    // 0x800A56CC: nop

L_800A56D0:
    // 0x800A56D0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A56D4: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A56D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A56DC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A56E0: jal         0x800BCFCC
    // 0x800A56E4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x800A56E4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_2:
    // 0x800A56E8: b           L_800A5790
    // 0x800A56EC: nop

        goto L_800A5790;
    // 0x800A56EC: nop

L_800A56F0:
    // 0x800A56F0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A56F4: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A56F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A56FC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5700: jal         0x800BCFCC
    // 0x800A5704: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x800A5704: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_3:
    // 0x800A5708: b           L_800A5790
    // 0x800A570C: nop

        goto L_800A5790;
    // 0x800A570C: nop

L_800A5710:
    // 0x800A5710: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5714: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5718: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A571C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5720: jal         0x800BCFCC
    // 0x800A5724: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x800A5724: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_4:
    // 0x800A5728: b           L_800A5790
    // 0x800A572C: nop

        goto L_800A5790;
    // 0x800A572C: nop

L_800A5730:
    // 0x800A5730: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5734: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5738: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A573C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5740: jal         0x800BCFCC
    // 0x800A5744: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x800A5744: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    after_5:
    // 0x800A5748: b           L_800A5790
    // 0x800A574C: nop

        goto L_800A5790;
    // 0x800A574C: nop

L_800A5750:
    // 0x800A5750: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5754: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5758: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A575C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5760: jal         0x800BCFCC
    // 0x800A5764: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    SysMem_Copy8(rdram, ctx);
        goto after_6;
    // 0x800A5764: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    after_6:
    // 0x800A5768: b           L_800A5790
    // 0x800A576C: nop

        goto L_800A5790;
    // 0x800A576C: nop

L_800A5770:
    // 0x800A5770: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5774: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5778: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A577C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5780: jal         0x800BCFCC
    // 0x800A5784: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    SysMem_Copy8(rdram, ctx);
        goto after_7;
    // 0x800A5784: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_7:
    // 0x800A5788: b           L_800A5790
    // 0x800A578C: nop

        goto L_800A5790;
    // 0x800A578C: nop

L_800A5790:
    // 0x800A5790: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5794: lw          $t9, -0x71D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X71D0);
    // 0x800A5798: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A579C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800A57A0: sw          $t0, -0x71D0($at)
    MEM_W(-0X71D0, ctx->r1) = ctx->r8;
    // 0x800A57A4: b           L_800A57B4
    // 0x800A57A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A57B4;
    // 0x800A57A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A57AC: b           L_800A57B4
    // 0x800A57B0: nop

        goto L_800A57B4;
    // 0x800A57B0: nop

L_800A57B4:
    // 0x800A57B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A57B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A57BC: jr          $ra
    // 0x800A57C0: nop

    return;
    // 0x800A57C0: nop

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
RECOMP_FUNC void func_80019C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019C20: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80019C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019C28: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80019C2C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80019C30: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80019C34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80019C38: jal         0x80099E2C
    // 0x80019C3C: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x80019C3C: nop

    after_0:
    // 0x80019C40: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80019C44: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80019C48: sh          $t6, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r14;
    // 0x80019C4C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80019C50: nop

    // 0x80019C54: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x80019C58: nop

    // 0x80019C5C: ori         $t0, $t9, 0x1108
    ctx->r8 = ctx->r25 | 0X1108;
    // 0x80019C60: sw          $t0, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r8;
    // 0x80019C64: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80019C68: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80019C6C: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
    // 0x80019C70: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80019C74: nop

    // 0x80019C78: bne         $t3, $zero, L_80019CAC
    if (ctx->r11 != 0) {
        // 0x80019C7C: nop
    
            goto L_80019CAC;
    }
    // 0x80019C7C: nop

    // 0x80019C80: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x80019C84: jal         0x800BC6EC
    // 0x80019C88: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80019C88: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_1:
    // 0x80019C8C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80019C90: nop

    // 0x80019C94: sw          $v0, 0x12C($t4)
    MEM_W(0X12C, ctx->r12) = ctx->r2;
    // 0x80019C98: jal         0x800BC6EC
    // 0x80019C9C: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80019C9C: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_2:
    // 0x80019CA0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80019CA4: b           L_80019CF0
    // 0x80019CA8: sw          $v0, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r2;
        goto L_80019CF0;
    // 0x80019CA8: sw          $v0, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r2;
L_80019CAC:
    // 0x80019CAC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80019CB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019CB4: bne         $t6, $at, L_80019CE8
    if (ctx->r14 != ctx->r1) {
        // 0x80019CB8: nop
    
            goto L_80019CE8;
    }
    // 0x80019CB8: nop

    // 0x80019CBC: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x80019CC0: jal         0x800BC918
    // 0x80019CC4: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_3;
    // 0x80019CC4: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_3:
    // 0x80019CC8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80019CCC: nop

    // 0x80019CD0: sw          $v0, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->r2;
    // 0x80019CD4: jal         0x800BC918
    // 0x80019CD8: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_4;
    // 0x80019CD8: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_4:
    // 0x80019CDC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80019CE0: b           L_80019CF0
    // 0x80019CE4: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
        goto L_80019CF0;
    // 0x80019CE4: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
L_80019CE8:
    // 0x80019CE8: b           L_80019F3C
    // 0x80019CEC: nop

        goto L_80019F3C;
    // 0x80019CEC: nop

L_80019CF0:
    // 0x80019CF0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80019CF4: nop

    // 0x80019CF8: lw          $t8, 0x12C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X12C);
    // 0x80019CFC: nop

    // 0x80019D00: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80019D04: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80019D08: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x80019D0C: lw          $t2, 0x12C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C);
    // 0x80019D10: ori         $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 | 0X7FFF;
    // 0x80019D14: addiu       $a0, $t2, 0x1
    ctx->r4 = ADD32(ctx->r10, 0X1);
    // 0x80019D18: jal         0x800BCFCC
    // 0x80019D1C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80019D1C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_5:
    // 0x80019D20: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80019D24: nop

    // 0x80019D28: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80019D2C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80019D30: nop

    // 0x80019D34: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x80019D38: nop

    // 0x80019D3C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80019D40: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80019D44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019D48: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x80019D4C: bne         $at, $zero, L_80019D64
    if (ctx->r1 != 0) {
        // 0x80019D50: nop
    
            goto L_80019D64;
    }
    // 0x80019D50: nop

    // 0x80019D54: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x80019D58: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x80019D5C: bne         $at, $zero, L_80019D70
    if (ctx->r1 != 0) {
        // 0x80019D60: nop
    
            goto L_80019D70;
    }
    // 0x80019D60: nop

L_80019D64:
    // 0x80019D64: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019D68: nop

    // 0x80019D6C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80019D70:
    // 0x80019D70: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80019D74: nop

    // 0x80019D78: lw          $t0, 0x128($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X128);
    // 0x80019D7C: nop

    // 0x80019D80: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80019D84: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80019D88:
    // 0x80019D88: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80019D8C:
    // 0x80019D8C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80019D90: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80019D94: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x80019D98: addiu       $t2, $t1, -0xA0
    ctx->r10 = ADD32(ctx->r9, -0XA0);
    // 0x80019D9C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80019DA0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80019DA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80019DA8: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80019DAC: addiu       $t6, $t5, -0x78
    ctx->r14 = ADD32(ctx->r13, -0X78);
    // 0x80019DB0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80019DB4: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80019DB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019DBC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80019DC0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80019DC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80019DC8: nop

    // 0x80019DCC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80019DD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80019DD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80019DD8: nop

    // 0x80019DDC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80019DE0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80019DE4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80019DE8: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80019DEC: nop

    // 0x80019DF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80019DF4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80019DF8: sh          $t8, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r24;
    // 0x80019DFC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80019E00: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80019E04: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x80019E08: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80019E0C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80019E10: nop

    // 0x80019E14: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x80019E18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80019E1C: nop

    // 0x80019E20: addiu       $t7, $t6, 0xC
    ctx->r15 = ADD32(ctx->r14, 0XC);
    // 0x80019E24: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80019E28: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80019E2C:
    // 0x80019E2C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80019E30: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80019E34: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80019E38: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x80019E3C: slti        $at, $t1, 0xF0
    ctx->r1 = SIGNED(ctx->r9) < 0XF0 ? 1 : 0;
    // 0x80019E40: bne         $at, $zero, L_80019E50
    if (ctx->r1 != 0) {
        // 0x80019E44: nop
    
            goto L_80019E50;
    }
    // 0x80019E44: nop

    // 0x80019E48: b           L_80019EEC
    // 0x80019E4C: nop

        goto L_80019EEC;
    // 0x80019E4C: nop

L_80019E50:
    // 0x80019E50: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80019E54:
    // 0x80019E54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80019E58: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80019E5C: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80019E60: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80019E64: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80019E68: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80019E6C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80019E70: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x80019E74: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80019E78: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80019E7C: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80019E80: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80019E84: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80019E88: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80019E8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80019E90: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80019E94: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80019E98: addu        $t3, $t5, $t4
    ctx->r11 = ADD32(ctx->r13, ctx->r12);
    // 0x80019E9C: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x80019EA0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019EA4: nop

    // 0x80019EA8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80019EAC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80019EB0: nop

    // 0x80019EB4: addiu       $t8, $t9, 0x2
    ctx->r24 = ADD32(ctx->r25, 0X2);
    // 0x80019EB8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80019EBC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80019EC0: nop

    // 0x80019EC4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80019EC8: slti        $at, $t1, 0x40
    ctx->r1 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x80019ECC: bne         $at, $zero, L_80019E54
    if (ctx->r1 != 0) {
        // 0x80019ED0: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80019E54;
    }
    // 0x80019ED0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80019ED4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80019ED8: nop

    // 0x80019EDC: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80019EE0: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x80019EE4: bne         $at, $zero, L_80019E2C
    if (ctx->r1 != 0) {
        // 0x80019EE8: sw          $t5, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r13;
            goto L_80019E2C;
    }
    // 0x80019EE8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_80019EEC:
    // 0x80019EEC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80019EF0: nop

    // 0x80019EF4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80019EF8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80019EFC: bne         $at, $zero, L_80019D8C
    if (ctx->r1 != 0) {
        // 0x80019F00: sw          $t3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r11;
            goto L_80019D8C;
    }
    // 0x80019F00: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80019F04: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80019F08: nop

    // 0x80019F0C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80019F10: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80019F14: bne         $at, $zero, L_80019D88
    if (ctx->r1 != 0) {
        // 0x80019F18: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_80019D88;
    }
    // 0x80019F18: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80019F1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80019F20: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x80019F24: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x80019F28: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80019F2C: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x80019F30: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
    // 0x80019F34: b           L_80019F3C
    // 0x80019F38: nop

        goto L_80019F3C;
    // 0x80019F38: nop

L_80019F3C:
    // 0x80019F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019F40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80019F44: jr          $ra
    // 0x80019F48: nop

    return;
    // 0x80019F48: nop

;}
RECOMP_FUNC void func_80018380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80018384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018388: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001838C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80018390: nop

    // 0x80018394: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80018398: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001839C: nop

    // 0x800183A0: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x800183A4: nop

    // 0x800183A8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800183AC: beq         $t9, $zero, L_80019898
    if (ctx->r25 == 0) {
        // 0x800183B0: nop
    
            goto L_80019898;
    }
    // 0x800183B0: nop

    // 0x800183B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800183B8: addiu       $t0, $t0, 0x61D8
    ctx->r8 = ADD32(ctx->r8, 0X61D8);
    // 0x800183BC: addiu       $t1, $t0, 0x618
    ctx->r9 = ADD32(ctx->r8, 0X618);
    // 0x800183C0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800183C4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800183C8: addiu       $t2, $t2, 0x61D8
    ctx->r10 = ADD32(ctx->r10, 0X61D8);
    // 0x800183CC: addiu       $t3, $t2, 0x750
    ctx->r11 = ADD32(ctx->r10, 0X750);
    // 0x800183D0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800183D4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800183D8: nop

    // 0x800183DC: lw          $t5, 0x1A8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A8);
    // 0x800183E0: nop

    // 0x800183E4: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x800183E8: beq         $t6, $zero, L_800183F8
    if (ctx->r14 == 0) {
        // 0x800183EC: nop
    
            goto L_800183F8;
    }
    // 0x800183EC: nop

    // 0x800183F0: b           L_80019890
    // 0x800183F4: nop

        goto L_80019890;
    // 0x800183F4: nop

L_800183F8:
    // 0x800183F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800183FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80018400: lwc1        $f4, 0x1E8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1E8);
    // 0x80018404: nop

    // 0x80018408: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8001840C: nop

    // 0x80018410: bc1f        L_80019720
    if (!c1cs) {
        // 0x80018414: nop
    
            goto L_80019720;
    }
    // 0x80018414: nop

    // 0x80018418: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001841C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80018420: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018424: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018428: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001842C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80018430: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80018434: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80018438: nop

    // 0x8001843C: lwc1        $f4, 0x1E8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1E8);
    // 0x80018440: nop

    // 0x80018444: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80018448: sub.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
    // 0x8001844C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80018450: swc1        $f8, 0x1E8($t8)
    MEM_W(0X1E8, ctx->r24) = ctx->f8.u32l;
    // 0x80018454: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80018458: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x8001845C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018460: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018464: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80018468: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001846C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80018470: lwc1        $f18, 0xF8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x80018474: nop

    // 0x80018478: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8001847C: swc1        $f10, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f10.u32l;
    // 0x80018480: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018484: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018488: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001848C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018490: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80018494: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80018498: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001849C: lwc1        $f18, 0x100($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X100);
    // 0x800184A0: nop

    // 0x800184A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800184A8: swc1        $f6, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->f6.u32l;
    // 0x800184AC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800184B0: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x800184B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800184B8: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800184BC: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800184C0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800184C4: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800184C8: lwc1        $f18, 0xFC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XFC);
    // 0x800184CC: nop

    // 0x800184D0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800184D4: swc1        $f4, 0xFC($t4)
    MEM_W(0XFC, ctx->r12) = ctx->f4.u32l;
    // 0x800184D8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800184DC: addiu       $t5, $t5, -0x59C0
    ctx->r13 = ADD32(ctx->r13, -0X59C0);
    // 0x800184E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800184E4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800184E8: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800184EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800184F0: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800184F4: lwc1        $f18, 0x104($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X104);
    // 0x800184F8: nop

    // 0x800184FC: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80018500: swc1        $f16, 0x104($t6)
    MEM_W(0X104, ctx->r14) = ctx->f16.u32l;
    // 0x80018504: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80018508: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x8001850C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018510: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018514: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80018518: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001851C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018520: lwc1        $f18, 0xF8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x80018524: nop

    // 0x80018528: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8001852C: swc1        $f8, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f8.u32l;
    // 0x80018530: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80018534: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x80018538: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001853C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018540: lwc1        $f16, 0x14($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80018544: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80018548: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8001854C: lwc1        $f18, 0x100($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X100);
    // 0x80018550: nop

    // 0x80018554: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80018558: swc1        $f10, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f10.u32l;
    // 0x8001855C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018560: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018568: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001856C: lwc1        $f8, 0x18($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80018570: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018574: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80018578: lwc1        $f18, 0xFC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XFC);
    // 0x8001857C: nop

    // 0x80018580: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80018584: swc1        $f6, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->f6.u32l;
    // 0x80018588: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001858C: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x80018590: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018594: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018598: lwc1        $f10, 0x1C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8001859C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800185A0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800185A4: lwc1        $f18, 0x104($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X104);
    // 0x800185A8: nop

    // 0x800185AC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800185B0: swc1        $f4, 0x104($t4)
    MEM_W(0X104, ctx->r12) = ctx->f4.u32l;
    // 0x800185B4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800185B8: nop

    // 0x800185BC: lw          $t6, 0x1AC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1AC);
    // 0x800185C0: nop

    // 0x800185C4: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x800185C8: beq         $at, $zero, L_800196F0
    if (ctx->r1 == 0) {
        // 0x800185CC: nop
    
            goto L_800196F0;
    }
    // 0x800185CC: nop

    // 0x800185D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800185D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800185D8: addu        $at, $at, $t6
    gpr jr_addend_800185E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800185DC: lw          $t6, -0x2A18($at)
    ctx->r14 = ADD32(ctx->r1, -0X2A18);
    // 0x800185E0: nop

    // 0x800185E4: jr          $t6
    // 0x800185E8: nop

    switch (jr_addend_800185E4 >> 2) {
        case 0: goto L_800191D8; break;
        case 1: goto L_80018C40; break;
        case 2: goto L_80018C40; break;
        case 3: goto L_80018C40; break;
        case 4: goto L_80019448; break;
        case 5: goto L_80018F28; break;
        case 6: goto L_80018F28; break;
        case 7: goto L_80018F28; break;
        case 8: goto L_800186B8; break;
        case 9: goto L_800185EC; break;
        default: switch_error(__func__, 0x800185E4, 0x800ED5E8);
    }
    // 0x800185E8: nop

L_800185EC:
    // 0x800185EC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800185F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800185F4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800185F8: nop

    // 0x800185FC: swc1        $f6, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f6.u32l;
    // 0x80018600: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018608: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001860C: nop

    // 0x80018610: swc1        $f10, 0x100($t8)
    MEM_W(0X100, ctx->r24) = ctx->f10.u32l;
    // 0x80018614: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001861C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018620: nop

    // 0x80018624: swc1        $f8, 0xFC($t9)
    MEM_W(0XFC, ctx->r25) = ctx->f8.u32l;
    // 0x80018628: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001862C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018630: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018634: nop

    // 0x80018638: swc1        $f18, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f18.u32l;
    // 0x8001863C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018640: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018644: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80018648: nop

    // 0x8001864C: swc1        $f16, 0x110($t1)
    MEM_W(0X110, ctx->r9) = ctx->f16.u32l;
    // 0x80018650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018654: lwc1        $f4, -0x599C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018658: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8001865C: nop

    // 0x80018660: swc1        $f4, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f4.u32l;
    // 0x80018664: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018668: lwc1        $f6, -0x5998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x8001866C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018670: nop

    // 0x80018674: swc1        $f6, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->f6.u32l;
    // 0x80018678: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001867C: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018680: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018684: nop

    // 0x80018688: swc1        $f10, 0x11C($t4)
    MEM_W(0X11C, ctx->r12) = ctx->f10.u32l;
    // 0x8001868C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80018690: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018694: nop

    // 0x80018698: swc1        $f8, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f8.u32l;
    // 0x8001869C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800186A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800186A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800186A8: nop

    // 0x800186AC: swc1        $f18, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f18.u32l;
    // 0x800186B0: b           L_800196F0
    // 0x800186B4: nop

        goto L_800196F0;
    // 0x800186B4: nop

L_800186B8:
    // 0x800186B8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800186BC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800186C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800186C4: lwc1        $f16, 0x100($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X100);
    // 0x800186C8: nop

    // 0x800186CC: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x800186D0: nop

    // 0x800186D4: bc1f        L_800186F0
    if (!c1cs) {
        // 0x800186D8: nop
    
            goto L_800186F0;
    }
    // 0x800186D8: nop

    // 0x800186DC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800186E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800186E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800186E8: nop

    // 0x800186EC: swc1        $f6, 0x100($t8)
    MEM_W(0X100, ctx->r24) = ctx->f6.u32l;
L_800186F0:
    // 0x800186F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800186F4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800186F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800186FC: lwc1        $f10, 0x104($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X104);
    // 0x80018700: nop

    // 0x80018704: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80018708: nop

    // 0x8001870C: bc1f        L_80018728
    if (!c1cs) {
        // 0x80018710: nop
    
            goto L_80018728;
    }
    // 0x80018710: nop

    // 0x80018714: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018718: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001871C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018720: nop

    // 0x80018724: swc1        $f18, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f18.u32l;
L_80018728:
    // 0x80018728: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8001872C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018730: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018734: lwc1        $f16, 0x100($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X100);
    // 0x80018738: nop

    // 0x8001873C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80018740: nop

    // 0x80018744: bc1f        L_80018760
    if (!c1cs) {
        // 0x80018748: nop
    
            goto L_80018760;
    }
    // 0x80018748: nop

    // 0x8001874C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018750: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018754: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018758: nop

    // 0x8001875C: swc1        $f6, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->f6.u32l;
L_80018760:
    // 0x80018760: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80018764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001876C: lwc1        $f10, 0x104($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X104);
    // 0x80018770: nop

    // 0x80018774: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80018778: nop

    // 0x8001877C: bc1f        L_80018798
    if (!c1cs) {
        // 0x80018780: nop
    
            goto L_80018798;
    }
    // 0x80018780: nop

    // 0x80018784: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018788: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001878C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80018790: nop

    // 0x80018794: swc1        $f18, 0x104($t4)
    MEM_W(0X104, ctx->r12) = ctx->f18.u32l;
L_80018798:
    // 0x80018798: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8001879C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800187A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800187A4: lwc1        $f4, -0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x800187A8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800187AC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800187B0: lwc1        $f10, 0x100($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X100);
    // 0x800187B4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800187B8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800187BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800187C0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800187C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800187C8: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800187CC: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800187D0: swc1        $f6, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f6.u32l;
    // 0x800187D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800187D8: lwc1        $f10, -0x5988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800187DC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800187E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800187E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800187E8: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800187EC: lwc1        $f4, 0x100($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X100);
    // 0x800187F0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800187F4: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800187F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800187FC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80018800: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018804: div.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80018808: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001880C: swc1        $f18, 0x118($t6)
    MEM_W(0X118, ctx->r14) = ctx->f18.u32l;
    // 0x80018810: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018814: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018818: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001881C: lwc1        $f16, -0x598C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x80018820: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80018824: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80018828: lwc1        $f10, 0x104($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X104);
    // 0x8001882C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018830: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018834: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018838: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8001883C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018840: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018844: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018848: swc1        $f6, 0x114($t7)
    MEM_W(0X114, ctx->r15) = ctx->f6.u32l;
    // 0x8001884C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018850: lwc1        $f10, -0x5984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80018854: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018858: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001885C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80018860: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80018864: lwc1        $f16, 0x104($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X104);
    // 0x80018868: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001886C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80018870: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018874: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018878: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001887C: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018880: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018884: swc1        $f18, 0x11C($t8)
    MEM_W(0X11C, ctx->r24) = ctx->f18.u32l;
    // 0x80018888: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8001888C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018890: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018894: lwc1        $f4, -0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018898: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001889C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800188A0: lwc1        $f10, 0x100($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X100);
    // 0x800188A4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800188A8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800188AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800188B0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800188B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800188B8: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800188BC: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800188C0: swc1        $f6, 0x110($t9)
    MEM_W(0X110, ctx->r25) = ctx->f6.u32l;
    // 0x800188C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800188C8: lwc1        $f10, -0x5988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800188CC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800188D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800188D4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800188D8: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800188DC: lwc1        $f4, 0x100($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X100);
    // 0x800188E0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800188E4: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800188E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800188EC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800188F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800188F4: div.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800188F8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800188FC: swc1        $f18, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f18.u32l;
    // 0x80018900: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018908: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001890C: lwc1        $f16, -0x598C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x80018910: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80018914: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80018918: lwc1        $f10, 0x104($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X104);
    // 0x8001891C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018920: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018924: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018928: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8001892C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018930: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018934: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018938: swc1        $f6, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->f6.u32l;
    // 0x8001893C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018940: lwc1        $f10, -0x5984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80018944: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018948: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001894C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018950: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80018954: lwc1        $f16, 0x104($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X104);
    // 0x80018958: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001895C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80018960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018964: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018968: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001896C: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018970: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018974: swc1        $f18, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f18.u32l;
    // 0x80018978: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001897C: nop

    // 0x80018980: lwc1        $f16, 0x110($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X110);
    // 0x80018984: lwc1        $f4, 0x118($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X118);
    // 0x80018988: nop

    // 0x8001898C: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x80018990: nop

    // 0x80018994: bc1f        L_800189B8
    if (!c1cs) {
        // 0x80018998: nop
    
            goto L_800189B8;
    }
    // 0x80018998: nop

    // 0x8001899C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800189A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800189A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800189A8: lwc1        $f6, 0x118($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X118);
    // 0x800189AC: nop

    // 0x800189B0: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800189B4: swc1        $f8, 0x110($t4)
    MEM_W(0X110, ctx->r12) = ctx->f8.u32l;
L_800189B8:
    // 0x800189B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800189BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800189C0: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800189C4: lwc1        $f18, 0x110($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X110);
    // 0x800189C8: nop

    // 0x800189CC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800189D0: nop

    // 0x800189D4: bc1f        L_800189F0
    if (!c1cs) {
        // 0x800189D8: nop
    
            goto L_800189F0;
    }
    // 0x800189D8: nop

    // 0x800189DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800189E0: lwc1        $f4, -0x59A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800189E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800189E8: nop

    // 0x800189EC: swc1        $f4, 0x110($t6)
    MEM_W(0X110, ctx->r14) = ctx->f4.u32l;
L_800189F0:
    // 0x800189F0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800189F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800189F8: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x800189FC: lwc1        $f6, 0x118($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X118);
    // 0x80018A00: nop

    // 0x80018A04: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80018A08: nop

    // 0x80018A0C: bc1f        L_80018A28
    if (!c1cs) {
        // 0x80018A10: nop
    
            goto L_80018A28;
    }
    // 0x80018A10: nop

    // 0x80018A14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018A18: lwc1        $f8, -0x5998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018A1C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80018A20: nop

    // 0x80018A24: swc1        $f8, 0x118($t8)
    MEM_W(0X118, ctx->r24) = ctx->f8.u32l;
L_80018A28:
    // 0x80018A28: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018A2C: nop

    // 0x80018A30: lwc1        $f18, 0x114($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X114);
    // 0x80018A34: lwc1        $f16, 0x11C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X11C);
    // 0x80018A38: nop

    // 0x80018A3C: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80018A40: nop

    // 0x80018A44: bc1f        L_80018A68
    if (!c1cs) {
        // 0x80018A48: nop
    
            goto L_80018A68;
    }
    // 0x80018A48: nop

    // 0x80018A4C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018A50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018A58: lwc1        $f4, 0x11C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X11C);
    // 0x80018A5C: nop

    // 0x80018A60: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80018A64: swc1        $f10, 0x114($t0)
    MEM_W(0X114, ctx->r8) = ctx->f10.u32l;
L_80018A68:
    // 0x80018A68: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80018A6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018A70: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018A74: lwc1        $f8, 0x114($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X114);
    // 0x80018A78: nop

    // 0x80018A7C: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80018A80: nop

    // 0x80018A84: bc1f        L_80018AA0
    if (!c1cs) {
        // 0x80018A88: nop
    
            goto L_80018AA0;
    }
    // 0x80018A88: nop

    // 0x80018A8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018A90: lwc1        $f16, -0x599C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018A94: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80018A98: nop

    // 0x80018A9C: swc1        $f16, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f16.u32l;
L_80018AA0:
    // 0x80018AA0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018AA4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018AA8: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018AAC: lwc1        $f4, 0x11C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X11C);
    // 0x80018AB0: nop

    // 0x80018AB4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80018AB8: nop

    // 0x80018ABC: bc1f        L_80018AD8
    if (!c1cs) {
        // 0x80018AC0: nop
    
            goto L_80018AD8;
    }
    // 0x80018AC0: nop

    // 0x80018AC4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018AC8: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018ACC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018AD0: nop

    // 0x80018AD4: swc1        $f10, 0x11C($t4)
    MEM_W(0X11C, ctx->r12) = ctx->f10.u32l;
L_80018AD8:
    // 0x80018AD8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018ADC: nop

    // 0x80018AE0: lwc1        $f8, 0x110($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X110);
    // 0x80018AE4: lwc1        $f18, 0x118($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X118);
    // 0x80018AE8: nop

    // 0x80018AEC: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80018AF0: nop

    // 0x80018AF4: bc1f        L_80018B18
    if (!c1cs) {
        // 0x80018AF8: nop
    
            goto L_80018B18;
    }
    // 0x80018AF8: nop

    // 0x80018AFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018B00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018B04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018B08: lwc1        $f16, 0x118($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X118);
    // 0x80018B0C: nop

    // 0x80018B10: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018B14: swc1        $f6, 0x110($t6)
    MEM_W(0X110, ctx->r14) = ctx->f6.u32l;
L_80018B18:
    // 0x80018B18: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80018B1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B20: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018B24: lwc1        $f10, 0x110($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X110);
    // 0x80018B28: nop

    // 0x80018B2C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80018B30: nop

    // 0x80018B34: bc1f        L_80018B50
    if (!c1cs) {
        // 0x80018B38: nop
    
            goto L_80018B50;
    }
    // 0x80018B38: nop

    // 0x80018B3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B40: lwc1        $f18, -0x59A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018B44: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018B48: nop

    // 0x80018B4C: swc1        $f18, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f18.u32l;
L_80018B50:
    // 0x80018B50: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80018B54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B58: lwc1        $f4, -0x5998($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018B5C: lwc1        $f16, 0x118($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X118);
    // 0x80018B60: nop

    // 0x80018B64: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80018B68: nop

    // 0x80018B6C: bc1f        L_80018B88
    if (!c1cs) {
        // 0x80018B70: nop
    
            goto L_80018B88;
    }
    // 0x80018B70: nop

    // 0x80018B74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B78: lwc1        $f6, -0x5998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018B7C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80018B80: nop

    // 0x80018B84: swc1        $f6, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f6.u32l;
L_80018B88:
    // 0x80018B88: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80018B8C: nop

    // 0x80018B90: lwc1        $f10, 0x114($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X114);
    // 0x80018B94: lwc1        $f8, 0x11C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X11C);
    // 0x80018B98: nop

    // 0x80018B9C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80018BA0: nop

    // 0x80018BA4: bc1f        L_80018BC8
    if (!c1cs) {
        // 0x80018BA8: nop
    
            goto L_80018BC8;
    }
    // 0x80018BA8: nop

    // 0x80018BAC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018BB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018BB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018BB8: lwc1        $f18, 0x11C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X11C);
    // 0x80018BBC: nop

    // 0x80018BC0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80018BC4: swc1        $f4, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f4.u32l;
L_80018BC8:
    // 0x80018BC8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80018BCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018BD0: lwc1        $f10, -0x599C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018BD4: lwc1        $f6, 0x114($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X114);
    // 0x80018BD8: nop

    // 0x80018BDC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018BE0: nop

    // 0x80018BE4: bc1f        L_80018C00
    if (!c1cs) {
        // 0x80018BE8: nop
    
            goto L_80018C00;
    }
    // 0x80018BE8: nop

    // 0x80018BEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018BF0: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018BF4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80018BF8: nop

    // 0x80018BFC: swc1        $f8, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f8.u32l;
L_80018C00:
    // 0x80018C00: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018C04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018C08: lwc1        $f16, -0x5994($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018C0C: lwc1        $f18, 0x11C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X11C);
    // 0x80018C10: nop

    // 0x80018C14: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80018C18: nop

    // 0x80018C1C: bc1f        L_80018C38
    if (!c1cs) {
        // 0x80018C20: nop
    
            goto L_80018C38;
    }
    // 0x80018C20: nop

    // 0x80018C24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018C28: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018C2C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018C30: nop

    // 0x80018C34: swc1        $f4, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f4.u32l;
L_80018C38:
    // 0x80018C38: b           L_800196F0
    // 0x80018C3C: nop

        goto L_800196F0;
    // 0x80018C3C: nop

L_80018C40:
    // 0x80018C40: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80018C44: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018C48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018C4C: lwc1        $f6, 0xF8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XF8);
    // 0x80018C50: nop

    // 0x80018C54: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018C58: nop

    // 0x80018C5C: bc1f        L_80018C78
    if (!c1cs) {
        // 0x80018C60: nop
    
            goto L_80018C78;
    }
    // 0x80018C60: nop

    // 0x80018C64: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018C68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018C6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80018C70: nop

    // 0x80018C74: swc1        $f8, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f8.u32l;
L_80018C78:
    // 0x80018C78: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018C7C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018C80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018C84: lwc1        $f18, 0x100($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X100);
    // 0x80018C88: nop

    // 0x80018C8C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80018C90: nop

    // 0x80018C94: bc1f        L_80018CB0
    if (!c1cs) {
        // 0x80018C98: nop
    
            goto L_80018CB0;
    }
    // 0x80018C98: nop

    // 0x80018C9C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018CA4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018CA8: nop

    // 0x80018CAC: swc1        $f4, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f4.u32l;
L_80018CB0:
    // 0x80018CB0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80018CB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018CB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018CBC: lwc1        $f6, 0xF8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x80018CC0: nop

    // 0x80018CC4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018CC8: nop

    // 0x80018CCC: bc1f        L_80018CE8
    if (!c1cs) {
        // 0x80018CD0: nop
    
            goto L_80018CE8;
    }
    // 0x80018CD0: nop

    // 0x80018CD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018CD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018CDC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018CE0: nop

    // 0x80018CE4: swc1        $f8, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f8.u32l;
L_80018CE8:
    // 0x80018CE8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80018CEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018CF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018CF4: lwc1        $f18, 0x100($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X100);
    // 0x80018CF8: nop

    // 0x80018CFC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80018D00: nop

    // 0x80018D04: bc1f        L_80018D20
    if (!c1cs) {
        // 0x80018D08: nop
    
            goto L_80018D20;
    }
    // 0x80018D08: nop

    // 0x80018D0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018D10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018D14: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80018D18: nop

    // 0x80018D1C: swc1        $f4, 0x100($t4)
    MEM_W(0X100, ctx->r12) = ctx->f4.u32l;
L_80018D20:
    // 0x80018D20: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80018D24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018D28: lwc1        $f6, -0x5990($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018D2C: lwc1        $f10, 0x100($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X100);
    // 0x80018D30: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018D34: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018D38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018D3C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018D40: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018D44: lwc1        $f4, 0x100($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X100);
    // 0x80018D48: nop

    // 0x80018D4C: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80018D50: swc1        $f6, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f6.u32l;
    // 0x80018D54: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80018D58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018D5C: lwc1        $f10, -0x5988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80018D60: lwc1        $f8, 0x100($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X100);
    // 0x80018D64: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018D68: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018D6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018D70: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018D74: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018D78: lwc1        $f6, 0x100($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X100);
    // 0x80018D7C: nop

    // 0x80018D80: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80018D84: swc1        $f10, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->f10.u32l;
    // 0x80018D88: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80018D8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018D90: lwc1        $f18, -0x5990($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018D94: lwc1        $f8, 0x100($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X100);
    // 0x80018D98: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018D9C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018DA4: nop

    // 0x80018DA8: div.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018DAC: swc1        $f16, 0x110($t9)
    MEM_W(0X110, ctx->r25) = ctx->f16.u32l;
    // 0x80018DB0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80018DB4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018DB8: lwc1        $f8, -0x5988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80018DBC: lwc1        $f10, 0x100($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X100);
    // 0x80018DC0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018DC4: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018DC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018DCC: nop

    // 0x80018DD0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018DD4: swc1        $f6, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f6.u32l;
    // 0x80018DD8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80018DDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018DE0: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018DE4: lwc1        $f16, 0x110($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X110);
    // 0x80018DE8: nop

    // 0x80018DEC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80018DF0: nop

    // 0x80018DF4: bc1f        L_80018E10
    if (!c1cs) {
        // 0x80018DF8: nop
    
            goto L_80018E10;
    }
    // 0x80018DF8: nop

    // 0x80018DFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E00: lwc1        $f8, -0x5998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018E04: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80018E08: nop

    // 0x80018E0C: swc1        $f8, 0x110($t2)
    MEM_W(0X110, ctx->r10) = ctx->f8.u32l;
L_80018E10:
    // 0x80018E10: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E14: lwc1        $f4, -0x5998($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018E18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018E20: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018E24: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018E28: lwc1        $f18, 0x118($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X118);
    // 0x80018E2C: nop

    // 0x80018E30: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80018E34: nop

    // 0x80018E38: bc1f        L_80018E5C
    if (!c1cs) {
        // 0x80018E3C: nop
    
            goto L_80018E5C;
    }
    // 0x80018E3C: nop

    // 0x80018E40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E44: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018E48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018E50: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018E54: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018E58: swc1        $f4, 0x118($t4)
    MEM_W(0X118, ctx->r12) = ctx->f4.u32l;
L_80018E5C:
    // 0x80018E5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E60: lwc1        $f18, -0x59A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018E64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018E6C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018E70: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80018E74: lwc1        $f6, 0x110($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X110);
    // 0x80018E78: nop

    // 0x80018E7C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018E80: nop

    // 0x80018E84: bc1f        L_80018EA8
    if (!c1cs) {
        // 0x80018E88: nop
    
            goto L_80018EA8;
    }
    // 0x80018E88: nop

    // 0x80018E8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E90: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018E94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018E9C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018EA0: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80018EA4: swc1        $f18, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f18.u32l;
L_80018EA8:
    // 0x80018EA8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018EAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018EB0: lwc1        $f6, -0x59A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018EB4: lwc1        $f16, 0x118($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X118);
    // 0x80018EB8: nop

    // 0x80018EBC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80018EC0: nop

    // 0x80018EC4: bc1f        L_80018EE0
    if (!c1cs) {
        // 0x80018EC8: nop
    
            goto L_80018EE0;
    }
    // 0x80018EC8: nop

    // 0x80018ECC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018ED0: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018ED4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80018ED8: nop

    // 0x80018EDC: swc1        $f10, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->f10.u32l;
L_80018EE0:
    // 0x80018EE0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80018EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018EE8: lw          $t0, 0x1AC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1AC);
    // 0x80018EEC: nop

    // 0x80018EF0: bne         $t0, $at, L_80018F00
    if (ctx->r8 != ctx->r1) {
        // 0x80018EF4: nop
    
            goto L_80018F00;
    }
    // 0x80018EF4: nop

    // 0x80018EF8: b           L_800191D8
    // 0x80018EFC: nop

        goto L_800191D8;
    // 0x80018EFC: nop

L_80018F00:
    // 0x80018F00: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80018F04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018F08: lw          $t2, 0x1AC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1AC);
    // 0x80018F0C: nop

    // 0x80018F10: bne         $t2, $at, L_80018F20
    if (ctx->r10 != ctx->r1) {
        // 0x80018F14: nop
    
            goto L_80018F20;
    }
    // 0x80018F14: nop

    // 0x80018F18: b           L_80019448
    // 0x80018F1C: nop

        goto L_80019448;
    // 0x80018F1C: nop

L_80018F20:
    // 0x80018F20: b           L_800196F0
    // 0x80018F24: nop

        goto L_800196F0;
    // 0x80018F24: nop

L_80018F28:
    // 0x80018F28: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018F2C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018F34: lwc1        $f8, 0xF8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x80018F38: nop

    // 0x80018F3C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80018F40: nop

    // 0x80018F44: bc1f        L_80018F60
    if (!c1cs) {
        // 0x80018F48: nop
    
            goto L_80018F60;
    }
    // 0x80018F48: nop

    // 0x80018F4C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018F54: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018F58: nop

    // 0x80018F5C: swc1        $f18, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f18.u32l;
L_80018F60:
    // 0x80018F60: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80018F64: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018F6C: lwc1        $f16, 0x100($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X100);
    // 0x80018F70: nop

    // 0x80018F74: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80018F78: nop

    // 0x80018F7C: bc1f        L_80018F98
    if (!c1cs) {
        // 0x80018F80: nop
    
            goto L_80018F98;
    }
    // 0x80018F80: nop

    // 0x80018F84: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018F8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80018F90: nop

    // 0x80018F94: swc1        $f10, 0x100($t5)
    MEM_W(0X100, ctx->r13) = ctx->f10.u32l;
L_80018F98:
    // 0x80018F98: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018F9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018FA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018FA4: lwc1        $f8, 0x100($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X100);
    // 0x80018FA8: nop

    // 0x80018FAC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80018FB0: nop

    // 0x80018FB4: bc1f        L_80018FD0
    if (!c1cs) {
        // 0x80018FB8: nop
    
            goto L_80018FD0;
    }
    // 0x80018FB8: nop

    // 0x80018FBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018FC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018FC4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80018FC8: nop

    // 0x80018FCC: swc1        $f18, 0x100($t7)
    MEM_W(0X100, ctx->r15) = ctx->f18.u32l;
L_80018FD0:
    // 0x80018FD0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018FD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018FD8: lwc1        $f6, -0x5990($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018FDC: lwc1        $f16, 0x100($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X100);
    // 0x80018FE0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018FE4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80018FE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018FEC: nop

    // 0x80018FF0: div.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018FF4: swc1        $f4, 0x110($t9)
    MEM_W(0X110, ctx->r25) = ctx->f4.u32l;
    // 0x80018FF8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018FFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019000: lwc1        $f16, -0x5988($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80019004: lwc1        $f18, 0x100($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X100);
    // 0x80019008: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8001900C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80019010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019014: nop

    // 0x80019018: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001901C: swc1        $f8, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f8.u32l;
    // 0x80019020: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80019024: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019028: lwc1        $f4, -0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x8001902C: lwc1        $f18, 0x100($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X100);
    // 0x80019030: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019034: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80019038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001903C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80019040: div.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80019044: lwc1        $f8, 0x100($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X100);
    // 0x80019048: nop

    // 0x8001904C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80019050: swc1        $f4, 0x110($t1)
    MEM_W(0X110, ctx->r9) = ctx->f4.u32l;
    // 0x80019054: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80019058: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001905C: lwc1        $f18, -0x5988($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80019060: lwc1        $f16, 0x100($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X100);
    // 0x80019064: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019068: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8001906C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019070: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80019074: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80019078: lwc1        $f4, 0x100($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X100);
    // 0x8001907C: nop

    // 0x80019080: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80019084: swc1        $f18, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->f18.u32l;
    // 0x80019088: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001908C: lwc1        $f6, -0x59A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80019090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019098: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001909C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800190A0: lwc1        $f16, 0x110($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X110);
    // 0x800190A4: nop

    // 0x800190A8: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800190AC: nop

    // 0x800190B0: bc1f        L_800190D4
    if (!c1cs) {
        // 0x800190B4: nop
    
            goto L_800190D4;
    }
    // 0x800190B4: nop

    // 0x800190B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800190BC: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800190C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800190C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800190C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800190CC: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800190D0: swc1        $f6, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f6.u32l;
L_800190D4:
    // 0x800190D4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800190D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800190DC: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800190E0: lwc1        $f8, 0x118($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X118);
    // 0x800190E4: nop

    // 0x800190E8: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800190EC: nop

    // 0x800190F0: bc1f        L_8001910C
    if (!c1cs) {
        // 0x800190F4: nop
    
            goto L_8001910C;
    }
    // 0x800190F4: nop

    // 0x800190F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800190FC: lwc1        $f4, -0x59A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80019100: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019104: nop

    // 0x80019108: swc1        $f4, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->f4.u32l;
L_8001910C:
    // 0x8001910C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80019110: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019114: lwc1        $f18, -0x5998($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019118: lwc1        $f10, 0x110($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X110);
    // 0x8001911C: nop

    // 0x80019120: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80019124: nop

    // 0x80019128: bc1f        L_80019144
    if (!c1cs) {
        // 0x8001912C: nop
    
            goto L_80019144;
    }
    // 0x8001912C: nop

    // 0x80019130: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019134: lwc1        $f6, -0x5998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019138: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001913C: nop

    // 0x80019140: swc1        $f6, 0x110($t0)
    MEM_W(0X110, ctx->r8) = ctx->f6.u32l;
L_80019144:
    // 0x80019144: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019148: lwc1        $f16, -0x5998($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x8001914C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019154: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80019158: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8001915C: lwc1        $f8, 0x118($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X118);
    // 0x80019160: nop

    // 0x80019164: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80019168: nop

    // 0x8001916C: bc1f        L_80019190
    if (!c1cs) {
        // 0x80019170: nop
    
            goto L_80019190;
    }
    // 0x80019170: nop

    // 0x80019174: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019178: lwc1        $f18, -0x5998($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x8001917C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019184: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80019188: add.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8001918C: swc1        $f16, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->f16.u32l;
L_80019190:
    // 0x80019190: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80019194: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80019198: lw          $t3, 0x1AC($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X1AC);
    // 0x8001919C: nop

    // 0x800191A0: bne         $t3, $at, L_800191B0
    if (ctx->r11 != ctx->r1) {
        // 0x800191A4: nop
    
            goto L_800191B0;
    }
    // 0x800191A4: nop

    // 0x800191A8: b           L_800191D8
    // 0x800191AC: nop

        goto L_800191D8;
    // 0x800191AC: nop

L_800191B0:
    // 0x800191B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800191B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800191B8: lw          $t5, 0x1AC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X1AC);
    // 0x800191BC: nop

    // 0x800191C0: bne         $t5, $at, L_800191D0
    if (ctx->r13 != ctx->r1) {
        // 0x800191C4: nop
    
            goto L_800191D0;
    }
    // 0x800191C4: nop

    // 0x800191C8: b           L_80019448
    // 0x800191CC: nop

        goto L_80019448;
    // 0x800191CC: nop

L_800191D0:
    // 0x800191D0: b           L_800196F0
    // 0x800191D4: nop

        goto L_800196F0;
    // 0x800191D4: nop

L_800191D8:
    // 0x800191D8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800191DC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800191E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800191E4: lwc1        $f4, 0xFC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800191E8: nop

    // 0x800191EC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800191F0: nop

    // 0x800191F4: bc1f        L_80019210
    if (!c1cs) {
        // 0x800191F8: nop
    
            goto L_80019210;
    }
    // 0x800191F8: nop

    // 0x800191FC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019204: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019208: nop

    // 0x8001920C: swc1        $f10, 0xFC($t7)
    MEM_W(0XFC, ctx->r15) = ctx->f10.u32l;
L_80019210:
    // 0x80019210: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80019214: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019218: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001921C: lwc1        $f18, 0x104($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X104);
    // 0x80019220: nop

    // 0x80019224: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80019228: nop

    // 0x8001922C: bc1f        L_80019248
    if (!c1cs) {
        // 0x80019230: nop
    
            goto L_80019248;
    }
    // 0x80019230: nop

    // 0x80019234: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019238: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001923C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80019240: nop

    // 0x80019244: swc1        $f16, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f16.u32l;
L_80019248:
    // 0x80019248: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8001924C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019254: lwc1        $f4, 0x104($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X104);
    // 0x80019258: nop

    // 0x8001925C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80019260: nop

    // 0x80019264: bc1f        L_80019280
    if (!c1cs) {
        // 0x80019268: nop
    
            goto L_80019280;
    }
    // 0x80019268: nop

    // 0x8001926C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019270: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019274: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80019278: nop

    // 0x8001927C: swc1        $f10, 0x104($t1)
    MEM_W(0X104, ctx->r9) = ctx->f10.u32l;
L_80019280:
    // 0x80019280: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80019284: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019288: lwc1        $f6, -0x598C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x8001928C: lwc1        $f18, 0x104($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X104);
    // 0x80019290: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019294: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80019298: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001929C: nop

    // 0x800192A0: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800192A4: swc1        $f8, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f8.u32l;
    // 0x800192A8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800192AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800192B0: lwc1        $f18, -0x5984($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800192B4: lwc1        $f10, 0x104($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X104);
    // 0x800192B8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800192BC: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800192C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800192C4: nop

    // 0x800192C8: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800192CC: swc1        $f4, 0x11C($t3)
    MEM_W(0X11C, ctx->r11) = ctx->f4.u32l;
    // 0x800192D0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800192D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800192D8: lwc1        $f8, -0x598C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x800192DC: lwc1        $f10, 0x104($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X104);
    // 0x800192E0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800192E4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800192E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800192EC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800192F0: div.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800192F4: lwc1        $f4, 0x104($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X104);
    // 0x800192F8: nop

    // 0x800192FC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80019300: swc1        $f8, 0x114($t6)
    MEM_W(0X114, ctx->r14) = ctx->f8.u32l;
    // 0x80019304: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80019308: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001930C: lwc1        $f10, -0x5984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80019310: lwc1        $f18, 0x104($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X104);
    // 0x80019314: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019318: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8001931C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019320: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019324: div.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80019328: lwc1        $f8, 0x104($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X104);
    // 0x8001932C: nop

    // 0x80019330: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80019334: swc1        $f10, 0x11C($t8)
    MEM_W(0X11C, ctx->r24) = ctx->f10.u32l;
    // 0x80019338: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001933C: lwc1        $f6, -0x599C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80019340: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019348: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001934C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80019350: lwc1        $f18, 0x114($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X114);
    // 0x80019354: nop

    // 0x80019358: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8001935C: nop

    // 0x80019360: bc1f        L_80019384
    if (!c1cs) {
        // 0x80019364: nop
    
            goto L_80019384;
    }
    // 0x80019364: nop

    // 0x80019368: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001936C: lwc1        $f16, -0x599C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80019370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019378: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001937C: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80019380: swc1        $f6, 0x114($t0)
    MEM_W(0X114, ctx->r8) = ctx->f6.u32l;
L_80019384:
    // 0x80019384: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80019388: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001938C: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80019390: lwc1        $f4, 0x11C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X11C);
    // 0x80019394: nop

    // 0x80019398: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8001939C: nop

    // 0x800193A0: bc1f        L_800193BC
    if (!c1cs) {
        // 0x800193A4: nop
    
            goto L_800193BC;
    }
    // 0x800193A4: nop

    // 0x800193A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193AC: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800193B0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800193B4: nop

    // 0x800193B8: swc1        $f8, 0x11C($t1)
    MEM_W(0X11C, ctx->r9) = ctx->f8.u32l;
L_800193BC:
    // 0x800193BC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800193C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193C4: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800193C8: lwc1        $f16, 0x114($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X114);
    // 0x800193CC: nop

    // 0x800193D0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800193D4: nop

    // 0x800193D8: bc1f        L_800193F4
    if (!c1cs) {
        // 0x800193DC: nop
    
            goto L_800193F4;
    }
    // 0x800193DC: nop

    // 0x800193E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193E4: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800193E8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800193EC: nop

    // 0x800193F0: swc1        $f6, 0x114($t3)
    MEM_W(0X114, ctx->r11) = ctx->f6.u32l;
L_800193F4:
    // 0x800193F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193F8: lwc1        $f18, -0x5994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800193FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019404: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80019408: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8001940C: lwc1        $f4, 0x11C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X11C);
    // 0x80019410: nop

    // 0x80019414: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80019418: nop

    // 0x8001941C: bc1f        L_80019440
    if (!c1cs) {
        // 0x80019420: nop
    
            goto L_80019440;
    }
    // 0x80019420: nop

    // 0x80019424: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019428: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x8001942C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019434: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019438: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001943C: swc1        $f18, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f18.u32l;
L_80019440:
    // 0x80019440: b           L_800196F0
    // 0x80019444: nop

        goto L_800196F0;
    // 0x80019444: nop

L_80019448:
    // 0x80019448: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001944C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019450: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019454: lwc1        $f8, 0xFC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x80019458: nop

    // 0x8001945C: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80019460: nop

    // 0x80019464: bc1f        L_80019480
    if (!c1cs) {
        // 0x80019468: nop
    
            goto L_80019480;
    }
    // 0x80019468: nop

    // 0x8001946C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019470: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019474: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80019478: nop

    // 0x8001947C: swc1        $f16, 0xFC($t8)
    MEM_W(0XFC, ctx->r24) = ctx->f16.u32l;
L_80019480:
    // 0x80019480: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80019484: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019488: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001948C: lwc1        $f10, 0x104($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X104);
    // 0x80019490: nop

    // 0x80019494: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80019498: nop

    // 0x8001949C: bc1f        L_800194B8
    if (!c1cs) {
        // 0x800194A0: nop
    
            goto L_800194B8;
    }
    // 0x800194A0: nop

    // 0x800194A4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800194A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800194AC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800194B0: nop

    // 0x800194B4: swc1        $f18, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f18.u32l;
L_800194B8:
    // 0x800194B8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800194BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800194C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800194C4: lwc1        $f8, 0xFC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XFC);
    // 0x800194C8: nop

    // 0x800194CC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800194D0: nop

    // 0x800194D4: bc1f        L_800194F0
    if (!c1cs) {
        // 0x800194D8: nop
    
            goto L_800194F0;
    }
    // 0x800194D8: nop

    // 0x800194DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800194E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800194E4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800194E8: nop

    // 0x800194EC: swc1        $f16, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = ctx->f16.u32l;
L_800194F0:
    // 0x800194F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800194F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800194F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800194FC: lwc1        $f10, 0x104($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X104);
    // 0x80019500: nop

    // 0x80019504: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80019508: nop

    // 0x8001950C: bc1f        L_80019528
    if (!c1cs) {
        // 0x80019510: nop
    
            goto L_80019528;
    }
    // 0x80019510: nop

    // 0x80019514: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019518: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001951C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80019520: nop

    // 0x80019524: swc1        $f18, 0x104($t3)
    MEM_W(0X104, ctx->r11) = ctx->f18.u32l;
L_80019528:
    // 0x80019528: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8001952C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019530: lwc1        $f8, -0x598C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x80019534: lwc1        $f4, 0x104($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X104);
    // 0x80019538: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001953C: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80019540: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019544: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019548: div.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8001954C: lwc1        $f18, 0x104($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X104);
    // 0x80019550: nop

    // 0x80019554: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80019558: swc1        $f8, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f8.u32l;
    // 0x8001955C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019560: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019564: lwc1        $f4, -0x5984($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80019568: lwc1        $f16, 0x104($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X104);
    // 0x8001956C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019570: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80019574: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80019578: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001957C: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80019580: lwc1        $f8, 0x104($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X104);
    // 0x80019584: nop

    // 0x80019588: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001958C: swc1        $f4, 0x11C($t7)
    MEM_W(0X11C, ctx->r15) = ctx->f4.u32l;
    // 0x80019590: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80019594: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019598: lwc1        $f10, -0x598C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x8001959C: lwc1        $f16, 0x104($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X104);
    // 0x800195A0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800195A4: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800195A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800195AC: nop

    // 0x800195B0: div.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800195B4: swc1        $f6, 0x114($t9)
    MEM_W(0X114, ctx->r25) = ctx->f6.u32l;
    // 0x800195B8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800195BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800195C0: lwc1        $f16, -0x5984($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800195C4: lwc1        $f4, 0x104($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X104);
    // 0x800195C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800195CC: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800195D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800195D4: nop

    // 0x800195D8: div.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800195DC: swc1        $f8, 0x11C($t0)
    MEM_W(0X11C, ctx->r8) = ctx->f8.u32l;
    // 0x800195E0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800195E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800195E8: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800195EC: lwc1        $f6, 0x114($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X114);
    // 0x800195F0: nop

    // 0x800195F4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800195F8: nop

    // 0x800195FC: bc1f        L_80019618
    if (!c1cs) {
        // 0x80019600: nop
    
            goto L_80019618;
    }
    // 0x80019600: nop

    // 0x80019604: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019608: lwc1        $f16, -0x5994($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x8001960C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80019610: nop

    // 0x80019614: swc1        $f16, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->f16.u32l;
L_80019618:
    // 0x80019618: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001961C: lwc1        $f18, -0x5994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019624: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019628: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001962C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80019630: lwc1        $f10, 0x11C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X11C);
    // 0x80019634: nop

    // 0x80019638: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8001963C: nop

    // 0x80019640: bc1f        L_80019664
    if (!c1cs) {
        // 0x80019644: nop
    
            goto L_80019664;
    }
    // 0x80019644: nop

    // 0x80019648: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001964C: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019650: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019654: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019658: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001965C: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80019660: swc1        $f18, 0x11C($t3)
    MEM_W(0X11C, ctx->r11) = ctx->f18.u32l;
L_80019664:
    // 0x80019664: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019668: lwc1        $f10, -0x599C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001966C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019674: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019678: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001967C: lwc1        $f8, 0x114($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X114);
    // 0x80019680: nop

    // 0x80019684: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80019688: nop

    // 0x8001968C: bc1f        L_800196B0
    if (!c1cs) {
        // 0x80019690: nop
    
            goto L_800196B0;
    }
    // 0x80019690: nop

    // 0x80019694: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019698: lwc1        $f16, -0x599C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001969C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800196A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800196A4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800196A8: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800196AC: swc1        $f10, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f10.u32l;
L_800196B0:
    // 0x800196B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800196B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800196B8: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800196BC: lwc1        $f6, 0x11C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X11C);
    // 0x800196C0: nop

    // 0x800196C4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800196C8: nop

    // 0x800196CC: bc1f        L_800196E8
    if (!c1cs) {
        // 0x800196D0: nop
    
            goto L_800196E8;
    }
    // 0x800196D0: nop

    // 0x800196D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800196D8: lwc1        $f4, -0x599C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800196DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800196E0: nop

    // 0x800196E4: swc1        $f4, 0x11C($t7)
    MEM_W(0X11C, ctx->r15) = ctx->f4.u32l;
L_800196E8:
    // 0x800196E8: b           L_800196F0
    // 0x800196EC: nop

        goto L_800196F0;
    // 0x800196EC: nop

L_800196F0:
    // 0x800196F0: jal         0x800C1754
    // 0x800196F4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800196F4: nop

    after_0:
    // 0x800196F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800196FC: jal         0x8009A14C
    // 0x80019700: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x80019700: nop

    after_1:
    // 0x80019704: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80019708: jal         0x800997D8
    // 0x8001970C: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x8001970C: nop

    after_2:
    // 0x80019710: jal         0x800C1A28
    // 0x80019714: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x80019714: nop

    after_3:
    // 0x80019718: b           L_80019890
    // 0x8001971C: nop

        goto L_80019890;
    // 0x8001971C: nop

L_80019720:
    // 0x80019720: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80019724: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80019728: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x8001972C: nop

    // 0x80019730: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80019734: sw          $t2, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->r10;
    // 0x80019738: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001973C: nop

    // 0x80019740: lw          $t4, 0x1A8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X1A8);
    // 0x80019744: nop

    // 0x80019748: ori         $t3, $t4, 0x2
    ctx->r11 = ctx->r12 | 0X2;
    // 0x8001974C: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x80019750: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019754: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019758: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001975C: nop

    // 0x80019760: swc1        $f16, 0xF8($t6)
    MEM_W(0XF8, ctx->r14) = ctx->f16.u32l;
    // 0x80019764: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019768: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001976C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80019770: nop

    // 0x80019774: swc1        $f18, 0x100($t5)
    MEM_W(0X100, ctx->r13) = ctx->f18.u32l;
    // 0x80019778: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8001977C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019780: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80019784: nop

    // 0x80019788: swc1        $f10, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f10.u32l;
    // 0x8001978C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019794: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019798: nop

    // 0x8001979C: swc1        $f6, 0x100($t7)
    MEM_W(0X100, ctx->r15) = ctx->f6.u32l;
    // 0x800197A0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800197A8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800197AC: nop

    // 0x800197B0: swc1        $f8, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->f8.u32l;
    // 0x800197B4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800197BC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800197C0: nop

    // 0x800197C4: swc1        $f4, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->f4.u32l;
    // 0x800197C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800197D0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800197D4: nop

    // 0x800197D8: swc1        $f16, 0xFC($t9)
    MEM_W(0XFC, ctx->r25) = ctx->f16.u32l;
    // 0x800197DC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800197E4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800197E8: nop

    // 0x800197EC: swc1        $f18, 0x104($t4)
    MEM_W(0X104, ctx->r12) = ctx->f18.u32l;
    // 0x800197F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800197F4: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800197F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800197FC: nop

    // 0x80019800: swc1        $f10, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->f10.u32l;
    // 0x80019804: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019808: lwc1        $f6, -0x599C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001980C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80019810: nop

    // 0x80019814: swc1        $f6, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->f6.u32l;
    // 0x80019818: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001981C: lwc1        $f8, -0x5998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019820: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80019824: nop

    // 0x80019828: swc1        $f8, 0x118($t6)
    MEM_W(0X118, ctx->r14) = ctx->f8.u32l;
    // 0x8001982C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019830: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019834: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80019838: nop

    // 0x8001983C: swc1        $f4, 0x11C($t5)
    MEM_W(0X11C, ctx->r13) = ctx->f4.u32l;
    // 0x80019840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019844: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80019848: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001984C: nop

    // 0x80019850: swc1        $f16, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f16.u32l;
    // 0x80019854: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019858: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001985C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019860: nop

    // 0x80019864: swc1        $f18, 0x114($t7)
    MEM_W(0X114, ctx->r15) = ctx->f18.u32l;
    // 0x80019868: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001986C: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019870: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80019874: nop

    // 0x80019878: swc1        $f10, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f10.u32l;
    // 0x8001987C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019880: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019884: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80019888: nop

    // 0x8001988C: swc1        $f6, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f6.u32l;
L_80019890:
    // 0x80019890: b           L_800198D8
    // 0x80019894: nop

        goto L_800198D8;
    // 0x80019894: nop

L_80019898:
    // 0x80019898: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001989C: nop

    // 0x800198A0: lw          $t4, 0x1A8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X1A8);
    // 0x800198A4: nop

    // 0x800198A8: andi        $t3, $t4, 0x2
    ctx->r11 = ctx->r12 & 0X2;
    // 0x800198AC: beq         $t3, $zero, L_800198D8
    if (ctx->r11 == 0) {
        // 0x800198B0: nop
    
            goto L_800198D8;
    }
    // 0x800198B0: nop

    // 0x800198B4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800198B8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800198BC: lw          $t6, 0x1A8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X1A8);
    // 0x800198C0: nop

    // 0x800198C4: and         $t5, $t6, $at
    ctx->r13 = ctx->r14 & ctx->r1;
    // 0x800198C8: sw          $t5, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r13;
    // 0x800198CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800198D0: jal         0x80019F4C
    // 0x800198D4: nop

    func_80019F4C(rdram, ctx);
        goto after_4;
    // 0x800198D4: nop

    after_4:
L_800198D8:
    // 0x800198D8: b           L_800198E8
    // 0x800198DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800198E8;
    // 0x800198DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800198E0: b           L_800198E8
    // 0x800198E4: nop

        goto L_800198E8;
    // 0x800198E4: nop

L_800198E8:
    // 0x800198E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800198EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800198F0: jr          $ra
    // 0x800198F4: nop

    return;
    // 0x800198F4: nop

;}
RECOMP_FUNC void func_80016B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B10: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80016B14: lw          $t6, 0x1A0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A0);
    // 0x80016B18: nop

    // 0x80016B1C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80016B20: sw          $t7, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r15;
    // 0x80016B24: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80016B28: sw          $zero, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = 0;
    // 0x80016B2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016B30: nop

    // 0x80016B34: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x80016B38: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80016B3C: nop

    // 0x80016B40: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x80016B44: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016B48: nop

    // 0x80016B4C: swc1        $f8, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f8.u32l;
    // 0x80016B50: lwc1        $f10, 0x1F4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x80016B54: nop

    // 0x80016B58: swc1        $f10, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f10.u32l;
    // 0x80016B5C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80016B60: lw          $t8, -0x4538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4538);
    // 0x80016B64: nop

    // 0x80016B68: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x80016B6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B70: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x80016B74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016B78: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016B7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B80: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80016B84: swc1        $f4, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f4.u32l;
    // 0x80016B88: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B8C: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80016B90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016B94: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016B98: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80016BA0: swc1        $f10, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f10.u32l;
    // 0x80016BA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BA8: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80016BAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016BB0: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016BB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BB8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80016BBC: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80016BC0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BC4: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x80016BC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016BCC: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016BD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BD4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80016BD8: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
    // 0x80016BDC: b           L_80016BEC
    // 0x80016BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016BEC;
    // 0x80016BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016BE4: b           L_80016BEC
    // 0x80016BE8: nop

        goto L_80016BEC;
    // 0x80016BE8: nop

L_80016BEC:
    // 0x80016BEC: jr          $ra
    // 0x80016BF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80016BF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Main_GfxFullSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE610: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BE614: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE618: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x800BE61C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE620: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE624: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x800BE628: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BE62C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800BE630: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x800BE634: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE638: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BE63C: nop

    // 0x800BE640: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800BE644: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800BE648: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x800BE64C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE650: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800BE654: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x800BE658: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800BE65C: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800BE660: lui         $t3, 0xB800
    ctx->r11 = S32(0XB800 << 16);
    // 0x800BE664: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800BE668: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800BE66C: nop

    // 0x800BE670: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800BE674: b           L_800BE67C
    // 0x800BE678: nop

        goto L_800BE67C;
    // 0x800BE678: nop

L_800BE67C:
    // 0x800BE67C: jr          $ra
    // 0x800BE680: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BE680: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_8005A768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A768: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A770: jal         0x80061F08
    // 0x8005A774: nop

    func_80061F08(rdram, ctx);
        goto after_0;
    // 0x8005A774: nop

    after_0:
    // 0x8005A778: beq         $v0, $zero, L_8005A788
    if (ctx->r2 == 0) {
        // 0x8005A77C: nop
    
            goto L_8005A788;
    }
    // 0x8005A77C: nop

    // 0x8005A780: b           L_8005A7B0
    // 0x8005A784: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_8005A7B0;
    // 0x8005A784: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8005A788:
    // 0x8005A788: jal         0x80061E14
    // 0x8005A78C: nop

    func_80061E14(rdram, ctx);
        goto after_1;
    // 0x8005A78C: nop

    after_1:
    // 0x8005A790: beq         $v0, $zero, L_8005A7A0
    if (ctx->r2 == 0) {
        // 0x8005A794: nop
    
            goto L_8005A7A0;
    }
    // 0x8005A794: nop

    // 0x8005A798: b           L_8005A7B0
    // 0x8005A79C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
        goto L_8005A7B0;
    // 0x8005A79C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_8005A7A0:
    // 0x8005A7A0: b           L_8005A7B0
    // 0x8005A7A4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
        goto L_8005A7B0;
    // 0x8005A7A4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // 0x8005A7A8: b           L_8005A7B0
    // 0x8005A7AC: nop

        goto L_8005A7B0;
    // 0x8005A7AC: nop

L_8005A7B0:
    // 0x8005A7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A7B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A7B8: jr          $ra
    // 0x8005A7BC: nop

    return;
    // 0x8005A7BC: nop

;}
RECOMP_FUNC void func_800B1B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1B48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B1B4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B1B50: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B1B54: nop

    // 0x800B1B58: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B1B5C: bltz        $t7, L_800B1BB0
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B1B60: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_800B1BB0;
    }
    // 0x800B1B60: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800B1B64:
    // 0x800B1B64: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B1B68: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B1B6C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B1B70: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1B74: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1B78: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B1B7C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B1B80: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B1B84: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1B88: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800B1B8C: sll         $t4, $t0, 6
    ctx->r12 = S32(ctx->r8 << 6);
    // 0x800B1B90: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x800B1B94: jal         0x800B1E58
    // 0x800B1B98: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    func_800B1E58(rdram, ctx);
        goto after_0;
    // 0x800B1B98: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x800B1B9C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800B1BA0: nop

    // 0x800B1BA4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B1BA8: bgez        $t6, L_800B1B64
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B1BAC: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_800B1B64;
    }
    // 0x800B1BAC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_800B1BB0:
    // 0x800B1BB0: b           L_800B1BB8
    // 0x800B1BB4: nop

        goto L_800B1BB8;
    // 0x800B1BB4: nop

L_800B1BB8:
    // 0x800B1BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1BC0: jr          $ra
    // 0x800B1BC4: nop

    return;
    // 0x800B1BC4: nop

;}
RECOMP_FUNC void func_800145D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800145D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800145D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800145DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800145E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800145E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800145E8: jal         0x8000DA44
    // 0x800145EC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800145EC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800145F0: bgez        $v0, L_80014600
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800145F4: nop
    
            goto L_80014600;
    }
    // 0x800145F4: nop

    // 0x800145F8: b           L_80014A70
    // 0x800145FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80014A70;
    // 0x800145FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014600:
    // 0x80014600: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014604: nop

    // 0x80014608: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001460C: nop

    // 0x80014610: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80014614: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80014618: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x8001461C: nop

    // 0x80014620: bne         $t9, $zero, L_80014634
    if (ctx->r25 != 0) {
        // 0x80014624: nop
    
            goto L_80014634;
    }
    // 0x80014624: nop

    // 0x80014628: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001462C: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80014630: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
L_80014634:
    // 0x80014634: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x80014638: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x8001463C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80014640: ori         $at, $at, 0x1FFE
    ctx->r1 = ctx->r1 | 0X1FFE;
    // 0x80014644: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80014648: sltiu       $at, $t4, 0xB
    ctx->r1 = ctx->r12 < 0XB ? 1 : 0;
    // 0x8001464C: beq         $at, $zero, L_80014A60
    if (ctx->r1 == 0) {
        // 0x80014650: nop
    
            goto L_80014A60;
    }
    // 0x80014650: nop

    // 0x80014654: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80014658: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001465C: addu        $at, $at, $t4
    gpr jr_addend_80014668 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80014660: lw          $t4, -0x2AA4($at)
    ctx->r12 = ADD32(ctx->r1, -0X2AA4);
    // 0x80014664: nop

    // 0x80014668: jr          $t4
    // 0x8001466C: nop

    switch (jr_addend_80014668 >> 2) {
        case 0: goto L_80014670; break;
        case 1: goto L_800146D4; break;
        case 2: goto L_80014A60; break;
        case 3: goto L_80014A60; break;
        case 4: goto L_80014A60; break;
        case 5: goto L_80014A60; break;
        case 6: goto L_80014738; break;
        case 7: goto L_80014A60; break;
        case 8: goto L_8001479C; break;
        case 9: goto L_80014888; break;
        case 10: goto L_80014974; break;
        default: switch_error(__func__, 0x80014668, 0x800ED55C);
    }
    // 0x8001466C: nop

L_80014670:
    // 0x80014670: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x80014674: lhu         $a0, 0x6($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X6);
    // 0x80014678: jal         0x80014BD4
    // 0x8001467C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x8001467C: nop

    after_1:
    // 0x80014680: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80014684: nop

    // 0x80014688: swc1        $f0, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->f0.u32l;
    // 0x8001468C: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80014690: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x80014694: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80014698: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8001469C: lwc1        $f4, 0x98($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X98);
    // 0x800146A0: lwc1        $f6, 0x6C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x800146A4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800146A8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800146AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800146B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800146B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800146B8: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800146BC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800146C0: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800146C4: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800146C8: swc1        $f8, 0xA4($t7)
    MEM_W(0XA4, ctx->r15) = ctx->f8.u32l;
    // 0x800146CC: b           L_80014A60
    // 0x800146D0: nop

        goto L_80014A60;
    // 0x800146D0: nop

L_800146D4:
    // 0x800146D4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x800146D8: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    // 0x800146DC: jal         0x80014BD4
    // 0x800146E0: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x800146E0: nop

    after_2:
    // 0x800146E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800146E8: nop

    // 0x800146EC: swc1        $f0, 0x9C($t1)
    MEM_W(0X9C, ctx->r9) = ctx->f0.u32l;
    // 0x800146F0: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800146F4: lh          $t4, 0x8($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X8);
    // 0x800146F8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800146FC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80014700: lwc1        $f16, 0x9C($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X9C);
    // 0x80014704: lwc1        $f18, 0x70($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X70);
    // 0x80014708: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001470C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014710: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80014714: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80014718: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001471C: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80014720: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80014724: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80014728: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8001472C: swc1        $f4, 0xA8($t2)
    MEM_W(0XA8, ctx->r10) = ctx->f4.u32l;
    // 0x80014730: b           L_80014A60
    // 0x80014734: nop

        goto L_80014A60;
    // 0x80014734: nop

L_80014738:
    // 0x80014738: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x8001473C: lhu         $a0, 0x6($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X6);
    // 0x80014740: jal         0x80014BD4
    // 0x80014744: nop

    func_80014BD4(rdram, ctx);
        goto after_3;
    // 0x80014744: nop

    after_3:
    // 0x80014748: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001474C: nop

    // 0x80014750: swc1        $f0, 0xA0($t6)
    MEM_W(0XA0, ctx->r14) = ctx->f0.u32l;
    // 0x80014754: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x80014758: lh          $t7, 0x8($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X8);
    // 0x8001475C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80014760: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80014764: lwc1        $f10, 0xA0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x80014768: lwc1        $f8, 0x74($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8001476C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80014770: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014774: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80014778: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8001477C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80014780: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80014784: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80014788: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8001478C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80014790: swc1        $f16, 0xAC($t8)
    MEM_W(0XAC, ctx->r24) = ctx->f16.u32l;
    // 0x80014794: b           L_80014A60
    // 0x80014798: nop

        goto L_80014A60;
    // 0x80014798: nop

L_8001479C:
    // 0x8001479C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x800147A0: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    // 0x800147A4: jal         0x80014BD4
    // 0x800147A8: nop

    func_80014BD4(rdram, ctx);
        goto after_4;
    // 0x800147A8: nop

    after_4:
    // 0x800147AC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800147B0: nop

    // 0x800147B4: swc1        $f0, 0xB0($t1)
    MEM_W(0XB0, ctx->r9) = ctx->f0.u32l;
    // 0x800147B8: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x800147BC: lh          $t2, 0x8($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X8);
    // 0x800147C0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800147C4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800147C8: lwc1        $f6, 0xB0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XB0);
    // 0x800147CC: lwc1        $f4, 0x18($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X18);
    // 0x800147D0: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800147D4: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800147D8: nop

    // 0x800147DC: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800147E0: swc1        $f16, 0xBC($t3)
    MEM_W(0XBC, ctx->r11) = ctx->f16.u32l;
    // 0x800147E4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800147E8: nop

    // 0x800147EC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800147F0: nop

    // 0x800147F4: ori         $t9, $t6, 0x20
    ctx->r25 = ctx->r14 | 0X20;
    // 0x800147F8: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x800147FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80014800: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80014804: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80014808: nop

    // 0x8001480C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80014810: lhu         $t0, 0x6($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X6);
    // 0x80014814: nop

    // 0x80014818: blez        $t0, L_80014880
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001481C: nop
    
            goto L_80014880;
    }
    // 0x8001481C: nop

L_80014820:
    // 0x80014820: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80014824: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80014828: lw          $t4, 0xC0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC0);
    // 0x8001482C: nop

    // 0x80014830: and         $t2, $t4, $at
    ctx->r10 = ctx->r12 & ctx->r1;
    // 0x80014834: sw          $t2, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r10;
    // 0x80014838: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001483C: nop

    // 0x80014840: lw          $t6, 0xC0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC0);
    // 0x80014844: nop

    // 0x80014848: ori         $t9, $t6, 0x10
    ctx->r25 = ctx->r14 | 0X10;
    // 0x8001484C: sw          $t9, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r25;
    // 0x80014850: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80014854: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80014858: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001485C: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80014860: addiu       $t0, $t7, 0x160
    ctx->r8 = ADD32(ctx->r15, 0X160);
    // 0x80014864: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80014868: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8001486C: lhu         $t2, 0x6($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X6);
    // 0x80014870: nop

    // 0x80014874: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80014878: bne         $at, $zero, L_80014820
    if (ctx->r1 != 0) {
        // 0x8001487C: nop
    
            goto L_80014820;
    }
    // 0x8001487C: nop

L_80014880:
    // 0x80014880: b           L_80014A60
    // 0x80014884: nop

        goto L_80014A60;
    // 0x80014884: nop

L_80014888:
    // 0x80014888: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x8001488C: lhu         $a0, 0x6($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X6);
    // 0x80014890: jal         0x80014BD4
    // 0x80014894: nop

    func_80014BD4(rdram, ctx);
        goto after_5;
    // 0x80014894: nop

    after_5:
    // 0x80014898: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001489C: nop

    // 0x800148A0: swc1        $f0, 0xB4($t6)
    MEM_W(0XB4, ctx->r14) = ctx->f0.u32l;
    // 0x800148A4: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800148A8: lh          $t5, 0x8($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X8);
    // 0x800148AC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800148B0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800148B4: lwc1        $f6, 0xB4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XB4);
    // 0x800148B8: lwc1        $f4, 0x1C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x800148BC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800148C0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800148C4: nop

    // 0x800148C8: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800148CC: swc1        $f16, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->f16.u32l;
    // 0x800148D0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800148D4: nop

    // 0x800148D8: lhu         $t0, 0x0($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X0);
    // 0x800148DC: nop

    // 0x800148E0: ori         $t4, $t0, 0x20
    ctx->r12 = ctx->r8 | 0X20;
    // 0x800148E4: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
    // 0x800148E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800148EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800148F0: lw          $t2, 0xC($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XC);
    // 0x800148F4: nop

    // 0x800148F8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800148FC: lhu         $t1, 0x6($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X6);
    // 0x80014900: nop

    // 0x80014904: blez        $t1, L_8001496C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80014908: nop
    
            goto L_8001496C;
    }
    // 0x80014908: nop

L_8001490C:
    // 0x8001490C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80014910: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80014914: lw          $t3, 0xC0($t6)
    ctx->r11 = MEM_W(ctx->r14, 0XC0);
    // 0x80014918: nop

    // 0x8001491C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80014920: sw          $t5, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r13;
    // 0x80014924: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80014928: nop

    // 0x8001492C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x80014930: nop

    // 0x80014934: ori         $t4, $t0, 0x10
    ctx->r12 = ctx->r8 | 0X10;
    // 0x80014938: sw          $t4, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r12;
    // 0x8001493C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80014940: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80014944: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80014948: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8001494C: addiu       $t1, $t8, 0x160
    ctx->r9 = ADD32(ctx->r24, 0X160);
    // 0x80014950: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80014954: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80014958: lhu         $t5, 0x6($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X6);
    // 0x8001495C: nop

    // 0x80014960: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80014964: bne         $at, $zero, L_8001490C
    if (ctx->r1 != 0) {
        // 0x80014968: nop
    
            goto L_8001490C;
    }
    // 0x80014968: nop

L_8001496C:
    // 0x8001496C: b           L_80014A60
    // 0x80014970: nop

        goto L_80014A60;
    // 0x80014970: nop

L_80014974:
    // 0x80014974: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80014978: lhu         $a0, 0x6($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X6);
    // 0x8001497C: jal         0x80014BD4
    // 0x80014980: nop

    func_80014BD4(rdram, ctx);
        goto after_6;
    // 0x80014980: nop

    after_6:
    // 0x80014984: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80014988: nop

    // 0x8001498C: swc1        $f0, 0xB8($t0)
    MEM_W(0XB8, ctx->r8) = ctx->f0.u32l;
    // 0x80014990: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x80014994: lh          $t7, 0x8($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X8);
    // 0x80014998: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001499C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800149A0: lwc1        $f6, 0xB8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XB8);
    // 0x800149A4: lwc1        $f4, 0x20($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X20);
    // 0x800149A8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800149AC: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800149B0: nop

    // 0x800149B4: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800149B8: swc1        $f16, 0xC4($t4)
    MEM_W(0XC4, ctx->r12) = ctx->f16.u32l;
    // 0x800149BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800149C0: nop

    // 0x800149C4: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x800149C8: nop

    // 0x800149CC: ori         $t3, $t1, 0x20
    ctx->r11 = ctx->r9 | 0X20;
    // 0x800149D0: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x800149D4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800149D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800149DC: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800149E0: nop

    // 0x800149E4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800149E8: lhu         $t6, 0x6($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X6);
    // 0x800149EC: nop

    // 0x800149F0: blez        $t6, L_80014A58
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800149F4: nop
    
            goto L_80014A58;
    }
    // 0x800149F4: nop

L_800149F8:
    // 0x800149F8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800149FC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80014A00: lw          $t9, 0xC0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC0);
    // 0x80014A04: nop

    // 0x80014A08: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80014A0C: sw          $t7, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r15;
    // 0x80014A10: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80014A14: nop

    // 0x80014A18: lw          $t1, 0xC0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC0);
    // 0x80014A1C: nop

    // 0x80014A20: ori         $t3, $t1, 0x10
    ctx->r11 = ctx->r9 | 0X10;
    // 0x80014A24: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x80014A28: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80014A2C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80014A30: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80014A34: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x80014A38: addiu       $t6, $t2, 0x160
    ctx->r14 = ADD32(ctx->r10, 0X160);
    // 0x80014A3C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80014A40: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80014A44: lhu         $t7, 0x6($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X6);
    // 0x80014A48: nop

    // 0x80014A4C: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80014A50: bne         $at, $zero, L_800149F8
    if (ctx->r1 != 0) {
        // 0x80014A54: nop
    
            goto L_800149F8;
    }
    // 0x80014A54: nop

L_80014A58:
    // 0x80014A58: b           L_80014A60
    // 0x80014A5C: nop

        goto L_80014A60;
    // 0x80014A5C: nop

L_80014A60:
    // 0x80014A60: b           L_80014A70
    // 0x80014A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80014A70;
    // 0x80014A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014A68: b           L_80014A70
    // 0x80014A6C: nop

        goto L_80014A70;
    // 0x80014A6C: nop

L_80014A70:
    // 0x80014A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014A74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014A78: jr          $ra
    // 0x80014A7C: nop

    return;
    // 0x80014A7C: nop

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
RECOMP_FUNC void func_80082D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082D1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80082D20: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80082D24: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80082D28: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80082D2C: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80082D30: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80082D34: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x80082D38: lhu         $a3, 0x2C($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X2C);
    // 0x80082D3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80082D40: lwc1        $f6, 0x18($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80082D44: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80082D48: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80082D4C: addiu       $a0, $t6, 0x24
    ctx->r4 = ADD32(ctx->r14, 0X24);
    // 0x80082D50: addiu       $a1, $t6, 0x28
    ctx->r5 = ADD32(ctx->r14, 0X28);
    // 0x80082D54: or          $a2, $t8, $t9
    ctx->r6 = ctx->r24 | ctx->r25;
    // 0x80082D58: jal         0x800B202C
    // 0x80082D5C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_0;
    // 0x80082D5C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80082D60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80082D64: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80082D68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082D6C: beq         $t0, $at, L_80082DA4
    if (ctx->r8 == ctx->r1) {
        // 0x80082D70: nop
    
            goto L_80082DA4;
    }
    // 0x80082D70: nop

    // 0x80082D74: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80082D78: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80082D7C: nop

    // 0x80082D80: sw          $t1, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r9;
    // 0x80082D84: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80082D88: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80082D8C: nop

    // 0x80082D90: sh          $t3, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r11;
    // 0x80082D94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80082D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082D9C: jal         0x8005A5F4
    // 0x80082DA0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8005A5F4(rdram, ctx);
        goto after_1;
    // 0x80082DA0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
L_80082DA4:
    // 0x80082DA4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80082DA8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80082DAC: lbu         $t7, 0x0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X0);
    // 0x80082DB0: nop

    // 0x80082DB4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80082DB8: sb          $t8, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r24;
    // 0x80082DBC: b           L_80082DC4
    // 0x80082DC0: nop

        goto L_80082DC4;
    // 0x80082DC0: nop

L_80082DC4:
    // 0x80082DC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80082DC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80082DCC: jr          $ra
    // 0x80082DD0: nop

    return;
    // 0x80082DD0: nop

;}
RECOMP_FUNC void func_800773B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800773B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800773B8: jal         0x80061488
    // 0x800773BC: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800773BC: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x800773C0: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800773C4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800773C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800773CC: beq         $v0, $zero, L_800773F4
    if (ctx->r2 == 0) {
        // 0x800773D0: nop
    
            goto L_800773F4;
    }
    // 0x800773D0: nop

    // 0x800773D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800773D8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800773DC: nop

    // 0x800773E0: lh          $v0, 0x36($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X36);
    // 0x800773E4: nop

    // 0x800773E8: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800773EC: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800773F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800773F4:
    // 0x800773F4: b           L_80077404
    // 0x800773F8: nop

        goto L_80077404;
    // 0x800773F8: nop

    // 0x800773FC: b           L_80077404
    // 0x80077400: nop

        goto L_80077404;
    // 0x80077400: nop

L_80077404:
    // 0x80077404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007740C: jr          $ra
    // 0x80077410: nop

    return;
    // 0x80077410: nop

;}
RECOMP_FUNC void func_80061030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061030: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061034: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80061038: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8006103C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061040: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061044: nop

    // 0x80061048: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006104C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80061050: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061054: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061058: nop

    // 0x8006105C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061060: bne         $at, $zero, L_800611D4
    if (ctx->r1 != 0) {
        // 0x80061064: nop
    
            goto L_800611D4;
    }
    // 0x80061064: nop

L_80061068:
    // 0x80061068: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8006106C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061070: nop

    // 0x80061074: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061078: bgez        $t2, L_80061088
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006107C: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061088;
    }
    // 0x8006107C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80061080: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061084: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061088:
    // 0x80061088: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8006108C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80061090: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061094: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061098: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006109C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800610A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800610A4: lw          $t4, 0x640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X640);
    // 0x800610A8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800610AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800610B0: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800610B4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800610B8: nop

    // 0x800610BC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800610C0: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610C4: nop
    
            goto L_800610DC;
    }
    // 0x800610C4: nop

    // 0x800610C8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800610CC: nop

    // 0x800610D0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800610D4: b           L_800611BC
    // 0x800610D8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
        goto L_800611BC;
    // 0x800610D8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800610DC:
    // 0x800610DC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800610E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800610E4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800610E8: lw          $t7, 0x650($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X650);
    // 0x800610EC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800610F0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800610F4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x800610F8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800610FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80061100: lh          $t5, 0x0($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X0);
    // 0x80061104: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80061108: nop

    // 0x8006110C: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80061110: beq         $at, $zero, L_8006112C
    if (ctx->r1 == 0) {
        // 0x80061114: nop
    
            goto L_8006112C;
    }
    // 0x80061114: nop

    // 0x80061118: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8006111C: nop

    // 0x80061120: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80061124: b           L_800611BC
    // 0x80061128: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
        goto L_800611BC;
    // 0x80061128: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_8006112C:
    // 0x8006112C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061130: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061134: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80061138: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006113C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061140: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061144: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80061148: lbu         $t8, 0x3($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3);
    // 0x8006114C: nop

    // 0x80061150: slti        $at, $t8, 0xF
    ctx->r1 = SIGNED(ctx->r24) < 0XF ? 1 : 0;
    // 0x80061154: beq         $at, $zero, L_8006118C
    if (ctx->r1 == 0) {
        // 0x80061158: nop
    
            goto L_8006118C;
    }
    // 0x80061158: nop

    // 0x8006115C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80061160: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80061164: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80061168: lw          $t9, 0x650($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X650);
    // 0x8006116C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80061170: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80061174: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
    // 0x80061178: lbu         $t1, 0x3($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3);
    // 0x8006117C: nop

    // 0x80061180: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80061184: b           L_800611B0
    // 0x80061188: sb          $t2, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r10;
        goto L_800611B0;
    // 0x80061188: sb          $t2, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r10;
L_8006118C:
    // 0x8006118C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80061190: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061194: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061198: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006119C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800611A0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800611A4: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800611A8: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x800611AC: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
L_800611B0:
    // 0x800611B0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800611B4: b           L_800611E4
    // 0x800611B8: nop

        goto L_800611E4;
    // 0x800611B8: nop

L_800611BC:
    // 0x800611BC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800611C0: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800611C4: nop

    // 0x800611C8: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800611CC: beq         $at, $zero, L_80061068
    if (ctx->r1 == 0) {
        // 0x800611D0: nop
    
            goto L_80061068;
    }
    // 0x800611D0: nop

L_800611D4:
    // 0x800611D4: b           L_800611E4
    // 0x800611D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800611E4;
    // 0x800611D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800611DC: b           L_800611E4
    // 0x800611E0: nop

        goto L_800611E4;
    // 0x800611E0: nop

L_800611E4:
    // 0x800611E4: jr          $ra
    // 0x800611E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800611E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80009D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009D3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009D40: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80009D44: nop

    // 0x80009D48: bne         $t6, $zero, L_80009D58
    if (ctx->r14 != 0) {
        // 0x80009D4C: nop
    
            goto L_80009D58;
    }
    // 0x80009D4C: nop

    // 0x80009D50: b           L_80009E4C
    // 0x80009D54: nop

        goto L_80009E4C;
    // 0x80009D54: nop

L_80009D58:
    // 0x80009D58: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80009D5C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80009D60: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80009D64: nop

    // 0x80009D68: beq         $t8, $at, L_80009E44
    if (ctx->r24 == ctx->r1) {
        // 0x80009D6C: nop
    
            goto L_80009E44;
    }
    // 0x80009D6C: nop

L_80009D70:
    // 0x80009D70: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80009D74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009D78: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80009D7C: nop

    // 0x80009D80: beq         $t0, $at, L_80009E24
    if (ctx->r8 == ctx->r1) {
        // 0x80009D84: nop
    
            goto L_80009E24;
    }
    // 0x80009D84: nop

    // 0x80009D88: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80009D8C: nop

    // 0x80009D90: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80009D94: jal         0x8005F064
    // 0x80009D98: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80009D98: nop

    after_0:
    // 0x80009D9C: bne         $v0, $zero, L_80009DE4
    if (ctx->r2 != 0) {
        // 0x80009DA0: nop
    
            goto L_80009DE4;
    }
    // 0x80009DA0: nop

    // 0x80009DA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80009DA8:
    // 0x80009DA8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80009DAC: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80009DB0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80009DB4: lw          $t3, 0x138($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X138);
    // 0x80009DB8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80009DBC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80009DC0: sh          $zero, 0x1F0($t6)
    MEM_H(0X1F0, ctx->r14) = 0;
    // 0x80009DC4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80009DC8: nop

    // 0x80009DCC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80009DD0: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x80009DD4: bne         $at, $zero, L_80009DA8
    if (ctx->r1 != 0) {
        // 0x80009DD8: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80009DA8;
    }
    // 0x80009DD8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80009DDC: b           L_80009E24
    // 0x80009DE0: nop

        goto L_80009E24;
    // 0x80009DE0: nop

L_80009DE4:
    // 0x80009DE4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80009DE8:
    // 0x80009DE8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80009DEC: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x80009DF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80009DF4: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x80009DF8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80009DFC: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80009E00: lhu         $t3, 0x1E0($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X1E0);
    // 0x80009E04: nop

    // 0x80009E08: sh          $t3, 0x1F0($t4)
    MEM_H(0X1F0, ctx->r12) = ctx->r11;
    // 0x80009E0C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80009E10: nop

    // 0x80009E14: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80009E18: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80009E1C: bne         $at, $zero, L_80009DE8
    if (ctx->r1 != 0) {
        // 0x80009E20: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80009DE8;
    }
    // 0x80009E20: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80009E24:
    // 0x80009E24: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80009E28: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80009E2C: addiu       $t8, $t7, 0x30
    ctx->r24 = ADD32(ctx->r15, 0X30);
    // 0x80009E30: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80009E34: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80009E38: nop

    // 0x80009E3C: bne         $t9, $at, L_80009D70
    if (ctx->r25 != ctx->r1) {
        // 0x80009E40: nop
    
            goto L_80009D70;
    }
    // 0x80009E40: nop

L_80009E44:
    // 0x80009E44: b           L_80009E4C
    // 0x80009E48: nop

        goto L_80009E4C;
    // 0x80009E48: nop

L_80009E4C:
    // 0x80009E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80009E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009E54: jr          $ra
    // 0x80009E58: nop

    return;
    // 0x80009E58: nop

;}
RECOMP_FUNC void func_8006B954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B954: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B958: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B95C: nop

    // 0x8006B960: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B964: nop

    // 0x8006B968: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006B96C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B970: jr          $ra
    // 0x8006B974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B978: jr          $ra
    // 0x8006B97C: nop

    return;
    // 0x8006B97C: nop

    // 0x8006B980: jr          $ra
    // 0x8006B984: nop

    return;
    // 0x8006B984: nop

;}
RECOMP_FUNC void func_8006F254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F254: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F258: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F25C: nop

    // 0x8006F260: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F264: nop

    // 0x8006F268: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F26C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F270: jr          $ra
    // 0x8006F274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F278: jr          $ra
    // 0x8006F27C: nop

    return;
    // 0x8006F27C: nop

    // 0x8006F280: jr          $ra
    // 0x8006F284: nop

    return;
    // 0x8006F284: nop

;}
RECOMP_FUNC void func_80096D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096D40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096D48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80096D4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80096D50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80096D54: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80096D58: nop

    // 0x80096D5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80096D60: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80096D64:
    // 0x80096D64: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D68: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80096D6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80096D70: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80096D74: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80096D78: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80096D7C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D80: nop

    // 0x80096D84: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80096D88: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80096D8C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D90: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80096D94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80096D98: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80096D9C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_80096DA0:
    // 0x80096DA0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80096DA4: nop

    // 0x80096DA8: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80096DAC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80096DB0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80096DB4: nop

    // 0x80096DB8: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80096DBC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80096DC0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80096DC4: nop

    // 0x80096DC8: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80096DCC: nop

    // 0x80096DD0: bne         $t3, $zero, L_80096DA0
    if (ctx->r11 != 0) {
        // 0x80096DD4: nop
    
            goto L_80096DA0;
    }
    // 0x80096DD4: nop

L_80096DD8:
    // 0x80096DD8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80096DDC: nop

    // 0x80096DE0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80096DE4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80096DE8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80096DEC: nop

    // 0x80096DF0: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80096DF4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80096DF8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80096DFC: nop

    // 0x80096E00: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x80096E04: nop

    // 0x80096E08: beq         $t0, $zero, L_80096DD8
    if (ctx->r8 == 0) {
        // 0x80096E0C: nop
    
            goto L_80096DD8;
    }
    // 0x80096E0C: nop

    // 0x80096E10: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80096E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80096E18: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x80096E1C: nop

    // 0x80096E20: bne         $t1, $at, L_80096D64
    if (ctx->r9 != ctx->r1) {
        // 0x80096E24: nop
    
            goto L_80096D64;
    }
    // 0x80096E24: nop

    // 0x80096E28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80096E2C: jal         0x800BC980
    // 0x80096E30: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x80096E30: nop

    after_0:
    // 0x80096E34: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80096E38: b           L_80096E48
    // 0x80096E3C: nop

        goto L_80096E48;
    // 0x80096E3C: nop

    // 0x80096E40: b           L_80096E48
    // 0x80096E44: nop

        goto L_80096E48;
    // 0x80096E44: nop

L_80096E48:
    // 0x80096E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096E50: jr          $ra
    // 0x80096E54: nop

    return;
    // 0x80096E54: nop

;}
RECOMP_FUNC void func_800863D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800863D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800863DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800863E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800863E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800863E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800863EC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800863F0: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x800863F4: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x800863F8: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x800863FC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086400: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086404: beq         $t0, $zero, L_800864B0
    if (ctx->r8 == 0) {
        // 0x80086408: nop
    
            goto L_800864B0;
    }
    // 0x80086408: nop

    // 0x8008640C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80086410: jal         0x8008A518
    // 0x80086414: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80086414: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80086418: beq         $v0, $zero, L_800864B0
    if (ctx->r2 == 0) {
        // 0x8008641C: nop
    
            goto L_800864B0;
    }
    // 0x8008641C: nop

    // 0x80086420: lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X24);
    // 0x80086424: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80086428: beq         $s0, $at, L_800864A0
    if (ctx->r16 == ctx->r1) {
        // 0x8008642C: nop
    
            goto L_800864A0;
    }
    // 0x8008642C: nop

    // 0x80086430: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086434: beq         $s0, $at, L_80086478
    if (ctx->r16 == ctx->r1) {
        // 0x80086438: nop
    
            goto L_80086478;
    }
    // 0x80086438: nop

    // 0x8008643C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80086440: beq         $s0, $at, L_80086450
    if (ctx->r16 == ctx->r1) {
        // 0x80086444: nop
    
            goto L_80086450;
    }
    // 0x80086444: nop

    // 0x80086448: b           L_800864B0
    // 0x8008644C: nop

        goto L_800864B0;
    // 0x8008644C: nop

L_80086450:
    // 0x80086450: jal         0x8008CE48
    // 0x80086454: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80086454: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80086458: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008645C: nop

    // 0x80086460: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80086464: nop

    // 0x80086468: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x8008646C: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80086470: b           L_80086504
    // 0x80086474: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_80086504;
    // 0x80086474: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80086478:
    // 0x80086478: jal         0x8008CE48
    // 0x8008647C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x8008647C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_2:
    // 0x80086480: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80086484: nop

    // 0x80086488: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8008648C: nop

    // 0x80086490: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x80086494: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80086498: b           L_80086504
    // 0x8008649C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80086504;
    // 0x8008649C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800864A0:
    // 0x800864A0: jal         0x8008CE48
    // 0x800864A4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x800864A4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x800864A8: b           L_80086504
    // 0x800864AC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086504;
    // 0x800864AC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800864B0:
    // 0x800864B0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800864B4: lhu         $t9, 0x101C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X101C);
    // 0x800864B8: lhu         $t7, 0x36($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X36);
    // 0x800864BC: nop

    // 0x800864C0: and         $t8, $t7, $t9
    ctx->r24 = ctx->r15 & ctx->r25;
    // 0x800864C4: beq         $t8, $zero, L_800864F4
    if (ctx->r24 == 0) {
        // 0x800864C8: nop
    
            goto L_800864F4;
    }
    // 0x800864C8: nop

    // 0x800864CC: jal         0x8008CE48
    // 0x800864D0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x800864D0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_4:
    // 0x800864D4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800864D8: nop

    // 0x800864DC: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x800864E0: nop

    // 0x800864E4: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800864E8: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x800864EC: b           L_80086504
    // 0x800864F0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80086504;
    // 0x800864F0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800864F4:
    // 0x800864F4: b           L_80086504
    // 0x800864F8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80086504;
    // 0x800864F8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800864FC: b           L_80086504
    // 0x80086500: nop

        goto L_80086504;
    // 0x80086500: nop

L_80086504:
    // 0x80086504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80086508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008650C: jr          $ra
    // 0x80086510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80086510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800671E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800671E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800671EC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800671F0: nop

    // 0x800671F4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800671F8: nop

    // 0x800671FC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067200: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067204: jr          $ra
    // 0x80067208: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067208: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006720C: jr          $ra
    // 0x80067210: nop

    return;
    // 0x80067210: nop

    // 0x80067214: jr          $ra
    // 0x80067218: nop

    return;
    // 0x80067218: nop

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
RECOMP_FUNC void func_8003A52C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A52C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003A530: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003A534: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8003A538: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8003A53C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8003A540: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8003A544: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003A548: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003A54C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003A550: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8003A554: nop

    // 0x8003A558: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8003A55C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003A560: nop

    // 0x8003A564: addiu       $t8, $t7, 0x30
    ctx->r24 = ADD32(ctx->r15, 0X30);
    // 0x8003A568: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8003A56C: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x8003A570: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8003A574: nop

    // 0x8003A578: lhu         $s0, 0x2($t9)
    ctx->r16 = MEM_HU(ctx->r25, 0X2);
    // 0x8003A57C: nop

    // 0x8003A580: beq         $s0, $zero, L_8003A59C
    if (ctx->r16 == 0) {
        // 0x8003A584: nop
    
            goto L_8003A59C;
    }
    // 0x8003A584: nop

    // 0x8003A588: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A58C: beq         $s0, $at, L_8003A6C4
    if (ctx->r16 == ctx->r1) {
        // 0x8003A590: nop
    
            goto L_8003A6C4;
    }
    // 0x8003A590: nop

    // 0x8003A594: b           L_8003A7C4
    // 0x8003A598: nop

        goto L_8003A7C4;
    // 0x8003A598: nop

L_8003A59C:
    // 0x8003A59C: lhu         $t0, 0x5A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X5A);
    // 0x8003A5A0: nop

    // 0x8003A5A4: beq         $t0, $zero, L_8003A6BC
    if (ctx->r8 == 0) {
        // 0x8003A5A8: nop
    
            goto L_8003A6BC;
    }
    // 0x8003A5A8: nop

    // 0x8003A5AC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8003A5B0: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8003A5B4: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003A5B8: lwc1        $f14, 0x4($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8003A5BC: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8003A5C0: jal         0x80039C5C
    // 0x8003A5C4: nop

    func_80039C5C(rdram, ctx);
        goto after_0;
    // 0x8003A5C4: nop

    after_0:
    // 0x8003A5C8: beq         $v0, $zero, L_8003A6BC
    if (ctx->r2 == 0) {
        // 0x8003A5CC: nop
    
            goto L_8003A6BC;
    }
    // 0x8003A5CC: nop

    // 0x8003A5D0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8003A5D4: nop

    // 0x8003A5D8: lhu         $t3, 0x10($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X10);
    // 0x8003A5DC: nop

    // 0x8003A5E0: bne         $t3, $zero, L_8003A684
    if (ctx->r11 != 0) {
        // 0x8003A5E4: nop
    
            goto L_8003A684;
    }
    // 0x8003A5E4: nop

    // 0x8003A5E8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8003A5EC: nop

    // 0x8003A5F0: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x8003A5F4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8003A5F8: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8003A5FC: nop

    // 0x8003A600: addiu       $t6, $t5, 0x48
    ctx->r14 = ADD32(ctx->r13, 0X48);
    // 0x8003A604: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8003A608: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8003A60C: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8003A610: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x8003A614: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x8003A618: slt         $t8, $at, $s0
    ctx->r24 = SIGNED(ctx->r1) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8003A61C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8003A620: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8003A624: beq         $s0, $zero, L_8003A638
    if (ctx->r16 == 0) {
        // 0x8003A628: sh          $t0, 0x0($t7)
        MEM_H(0X0, ctx->r15) = ctx->r8;
            goto L_8003A638;
    }
    // 0x8003A628: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x8003A62C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8003A630: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x8003A634: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
L_8003A638:
    // 0x8003A638: jal         0x800B9000
    // 0x8003A63C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8003A63C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_1:
    // 0x8003A640: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8003A644: sh          $t3, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r11;
    // 0x8003A648: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8003A64C: addiu       $t5, $zero, 0x69
    ctx->r13 = ADD32(0, 0X69);
    // 0x8003A650: lwc1        $f12, 0x0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003A654: lwc1        $f14, 0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8003A658: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x8003A65C: addiu       $t6, $zero, 0x1E1
    ctx->r14 = ADD32(0, 0X1E1);
    // 0x8003A660: addiu       $t8, $zero, 0x36
    ctx->r24 = ADD32(0, 0X36);
    // 0x8003A664: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8003A668: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8003A66C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8003A670: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003A674: jal         0x80033D78
    // 0x8003A678: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80033D78(rdram, ctx);
        goto after_2;
    // 0x8003A678: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8003A67C: b           L_8003A7C4
    // 0x8003A680: nop

        goto L_8003A7C4;
    // 0x8003A680: nop

L_8003A684:
    // 0x8003A684: jal         0x800B9000
    // 0x8003A688: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8003A688: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_3:
    // 0x8003A68C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003A690: nop

    // 0x8003A694: lhu         $t0, 0x10($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X10);
    // 0x8003A698: nop

    // 0x8003A69C: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x8003A6A0: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    // 0x8003A6A4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8003A6A8: nop

    // 0x8003A6AC: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x8003A6B0: nop

    // 0x8003A6B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003A6B8: sh          $t3, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r11;
L_8003A6BC:
    // 0x8003A6BC: b           L_8003A7C4
    // 0x8003A6C0: nop

        goto L_8003A7C4;
    // 0x8003A6C0: nop

L_8003A6C4:
    // 0x8003A6C4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003A6C8: nop

    // 0x8003A6CC: lhu         $t5, 0xE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XE);
    // 0x8003A6D0: nop

    // 0x8003A6D4: bgez        $t5, L_8003A6E8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003A6D8: andi        $t6, $t5, 0x1
        ctx->r14 = ctx->r13 & 0X1;
            goto L_8003A6E8;
    }
    // 0x8003A6D8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8003A6DC: beq         $t6, $zero, L_8003A6E8
    if (ctx->r14 == 0) {
        // 0x8003A6E0: nop
    
            goto L_8003A6E8;
    }
    // 0x8003A6E0: nop

    // 0x8003A6E4: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_8003A6E8:
    // 0x8003A6E8: beq         $t6, $zero, L_8003A6FC
    if (ctx->r14 == 0) {
        // 0x8003A6EC: nop
    
            goto L_8003A6FC;
    }
    // 0x8003A6EC: nop

    // 0x8003A6F0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x8003A6F4: b           L_8003A700
    // 0x8003A6F8: sb          $t8, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r24;
        goto L_8003A700;
    // 0x8003A6F8: sb          $t8, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r24;
L_8003A6FC:
    // 0x8003A6FC: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
L_8003A700:
    // 0x8003A700: lbu         $s2, 0x4F($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X4F);
    // 0x8003A704: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8003A708: sll         $s1, $s2, 16
    ctx->r17 = S32(ctx->r18 << 16);
    // 0x8003A70C: sh          $s2, 0xD0($t0)
    MEM_H(0XD0, ctx->r8) = ctx->r18;
    // 0x8003A710: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8003A714: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8003A718: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8003A71C: sh          $s1, 0xCE($t9)
    MEM_H(0XCE, ctx->r25) = ctx->r17;
    // 0x8003A720: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003A724: nop

    // 0x8003A728: sh          $s1, 0xCC($t2)
    MEM_H(0XCC, ctx->r10) = ctx->r17;
    // 0x8003A72C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8003A730: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003A734: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003A738: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8003A73C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8003A740: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003A744: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003A748: swc1        $f8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f8.u32l;
    // 0x8003A74C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8003A750: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003A754: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8003A758: nop

    // 0x8003A75C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003A760: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8003A764: nop

    // 0x8003A768: bc1f        L_8003A7BC
    if (!c1cs) {
        // 0x8003A76C: nop
    
            goto L_8003A7BC;
    }
    // 0x8003A76C: nop

    // 0x8003A770: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003A774: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003A778: nop

    // 0x8003A77C: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x8003A780: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003A784: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8003A788: lhu         $s0, 0xE($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0XE);
    // 0x8003A78C: lhu         $t8, 0xE($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0XE);
    // 0x8003A790: slt         $t6, $at, $s0
    ctx->r14 = SIGNED(ctx->r1) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8003A794: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8003A798: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8003A79C: beq         $s0, $zero, L_8003A7BC
    if (ctx->r16 == 0) {
        // 0x8003A7A0: sh          $t0, 0xE($t5)
        MEM_H(0XE, ctx->r13) = ctx->r8;
            goto L_8003A7BC;
    }
    // 0x8003A7A0: sh          $t0, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r8;
    // 0x8003A7A4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003A7A8: nop

    // 0x8003A7AC: sh          $zero, 0xE($t7)
    MEM_H(0XE, ctx->r15) = 0;
    // 0x8003A7B0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8003A7B4: nop

    // 0x8003A7B8: sh          $zero, 0x2($t9)
    MEM_H(0X2, ctx->r25) = 0;
L_8003A7BC:
    // 0x8003A7BC: b           L_8003A7C4
    // 0x8003A7C0: nop

        goto L_8003A7C4;
    // 0x8003A7C0: nop

L_8003A7C4:
    // 0x8003A7C4: lh          $v0, 0x4C($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X4C);
    // 0x8003A7C8: b           L_8003A7D8
    // 0x8003A7CC: nop

        goto L_8003A7D8;
    // 0x8003A7CC: nop

    // 0x8003A7D0: b           L_8003A7D8
    // 0x8003A7D4: nop

        goto L_8003A7D8;
    // 0x8003A7D4: nop

L_8003A7D8:
    // 0x8003A7D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003A7DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003A7E0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003A7E4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003A7E8: jr          $ra
    // 0x8003A7EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003A7EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8001ADBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ADBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001ADC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ADC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001ADC8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001ADCC: nop

    // 0x8001ADD0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8001ADD4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001ADD8: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8001ADDC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8001ADE0: nop

    // 0x8001ADE4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8001ADE8: bne         $t9, $zero, L_8001AE0C
    if (ctx->r25 != 0) {
        // 0x8001ADEC: nop
    
            goto L_8001AE0C;
    }
    // 0x8001ADEC: nop

    // 0x8001ADF0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001ADF4: nop

    // 0x8001ADF8: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8001ADFC: nop

    // 0x8001AE00: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8001AE04: bne         $t2, $zero, L_8001AE70
    if (ctx->r10 != 0) {
        // 0x8001AE08: nop
    
            goto L_8001AE70;
    }
    // 0x8001AE08: nop

L_8001AE0C:
    // 0x8001AE0C: jal         0x800C1754
    // 0x8001AE10: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8001AE10: nop

    after_0:
    // 0x8001AE14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE18: jal         0x8009A14C
    // 0x8001AE1C: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x8001AE1C: nop

    after_1:
    // 0x8001AE20: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE24: nop

    // 0x8001AE28: lwc1        $f12, 0xF0($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8001AE2C: jal         0x800C2780
    // 0x8001AE30: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8001AE30: nop

    after_2:
    // 0x8001AE34: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE38: nop

    // 0x8001AE3C: lwc1        $f12, 0xEC($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x8001AE40: jal         0x800C25B8
    // 0x8001AE44: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8001AE44: nop

    after_3:
    // 0x8001AE48: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE4C: nop

    // 0x8001AE50: lwc1        $f12, 0xE8($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x8001AE54: jal         0x800C23E8
    // 0x8001AE58: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8001AE58: nop

    after_4:
    // 0x8001AE5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE60: jal         0x800997D8
    // 0x8001AE64: nop

    func_800997D8(rdram, ctx);
        goto after_5;
    // 0x8001AE64: nop

    after_5:
    // 0x8001AE68: jal         0x800C1A28
    // 0x8001AE6C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8001AE6C: nop

    after_6:
L_8001AE70:
    // 0x8001AE70: b           L_8001AE80
    // 0x8001AE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AE80;
    // 0x8001AE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AE78: b           L_8001AE80
    // 0x8001AE7C: nop

        goto L_8001AE80;
    // 0x8001AE7C: nop

L_8001AE80:
    // 0x8001AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AE88: jr          $ra
    // 0x8001AE8C: nop

    return;
    // 0x8001AE8C: nop

;}
RECOMP_FUNC void func_8006B9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B9F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B9F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B9FC: jal         0x80061488
    // 0x8006BA00: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006BA00: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    after_0:
    // 0x8006BA04: xori        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 ^ 0X4;
    // 0x8006BA08: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006BA0C: b           L_8006BA1C
    // 0x8006BA10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006BA1C;
    // 0x8006BA10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006BA14: b           L_8006BA1C
    // 0x8006BA18: nop

        goto L_8006BA1C;
    // 0x8006BA18: nop

L_8006BA1C:
    // 0x8006BA1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BA20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BA24: jr          $ra
    // 0x8006BA28: nop

    return;
    // 0x8006BA28: nop

;}
RECOMP_FUNC void func_800A5854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5854: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800A5858: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A585C: nop

    // 0x800A5860: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A5864: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5868: lw          $t7, -0x71D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71D0);
    // 0x800A586C: nop

    // 0x800A5870: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800A5874: beq         $t8, $zero, L_800A62A8
    if (ctx->r24 == 0) {
        // 0x800A5878: nop
    
            goto L_800A62A8;
    }
    // 0x800A5878: nop

    // 0x800A587C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5880: lw          $t9, -0x7268($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7268);
    // 0x800A5884: nop

    // 0x800A5888: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x800A588C: beq         $at, $zero, L_800A62A8
    if (ctx->r1 == 0) {
        // 0x800A5890: nop
    
            goto L_800A62A8;
    }
    // 0x800A5890: nop

    // 0x800A5894: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A5898: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A589C: addu        $at, $at, $t9
    gpr jr_addend_800A58A8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A58A0: lw          $t9, -0x778($at)
    ctx->r25 = ADD32(ctx->r1, -0X778);
    // 0x800A58A4: nop

    // 0x800A58A8: jr          $t9
    // 0x800A58AC: nop

    switch (jr_addend_800A58A8 >> 2) {
        case 0: goto L_800A58B0; break;
        case 1: goto L_800A595C; break;
        case 2: goto L_800A5A08; break;
        case 3: goto L_800A5AEC; break;
        case 4: goto L_800A5C08; break;
        case 5: goto L_800A5D5C; break;
        case 6: goto L_800A5EE8; break;
        case 7: goto L_800A60AC; break;
        default: switch_error(__func__, 0x800A58A8, 0x800EF888);
    }
    // 0x800A58AC: nop

L_800A58B0:
    // 0x800A58B0: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A58B4: nop

    // 0x800A58B8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A58BC: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A58C0: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x800A58C4: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x800A58C8: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A58CC: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A58D0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A58D4: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x800A58D8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A58DC: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x800A58E0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A58E4: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A58E8: nop

    // 0x800A58EC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A58F0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A58F4: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x800A58F8: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800A58FC: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A5900: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5904: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5908: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A590C: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x800A5910: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5914: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A5918: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A591C: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5920: nop

    // 0x800A5924: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5928: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A592C: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x800A5930: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x800A5934: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A5938: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A593C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5940: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5944: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800A5948: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A594C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5950: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5954: b           L_800A62A8
    // 0x800A5958: nop

        goto L_800A62A8;
    // 0x800A5958: nop

L_800A595C:
    // 0x800A595C: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5960: nop

    // 0x800A5964: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5968: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A596C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A5970: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800A5974: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A5978: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A597C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5980: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800A5984: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A5988: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x800A598C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5990: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5994: nop

    // 0x800A5998: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A599C: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A59A0: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x800A59A4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800A59A8: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A59AC: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A59B0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A59B4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A59B8: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800A59BC: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A59C0: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A59C4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A59C8: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A59CC: nop

    // 0x800A59D0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A59D4: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A59D8: sw          $t3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r11;
    // 0x800A59DC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800A59E0: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A59E4: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A59E8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A59EC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A59F0: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800A59F4: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A59F8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A59FC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5A00: b           L_800A62A8
    // 0x800A5A04: nop

        goto L_800A62A8;
    // 0x800A5A04: nop

L_800A5A08:
    // 0x800A5A08: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5A0C: nop

    // 0x800A5A10: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5A14: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5A18: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    // 0x800A5A1C: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x800A5A20: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A5A24: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A5A28: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5A2C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800A5A30: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A5A34: ori         $t4, $t4, 0x60
    ctx->r12 = ctx->r12 | 0X60;
    // 0x800A5A38: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5A3C: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5A40: nop

    // 0x800A5A44: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5A48: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A5A4C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x800A5A50: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800A5A54: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A5A58: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5A5C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5A60: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A5A64: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A5A68: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5A6C: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A5A70: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5A74: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5A78: nop

    // 0x800A5A7C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5A80: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5A84: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x800A5A88: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800A5A8C: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A5A90: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5A94: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5A98: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5A9C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x800A5AA0: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5AA4: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x800A5AA8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5AAC: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5AB0: nop

    // 0x800A5AB4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5AB8: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5ABC: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x800A5AC0: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x800A5AC4: lui         $t2, 0x38A
    ctx->r10 = S32(0X38A << 16);
    // 0x800A5AC8: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A5ACC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5AD0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A5AD4: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800A5AD8: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A5ADC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A5AE0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5AE4: b           L_800A62A8
    // 0x800A5AE8: nop

        goto L_800A62A8;
    // 0x800A5AE8: nop

L_800A5AEC:
    // 0x800A5AEC: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5AF0: nop

    // 0x800A5AF4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5AF8: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5AFC: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x800A5B00: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800A5B04: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800A5B08: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x800A5B0C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5B10: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800A5B14: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800A5B18: ori         $t1, $t1, 0x80
    ctx->r9 = ctx->r9 | 0X80;
    // 0x800A5B1C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5B20: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5B24: nop

    // 0x800A5B28: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5B2C: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5B30: sw          $t3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r11;
    // 0x800A5B34: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800A5B38: lui         $t5, 0x386
    ctx->r13 = S32(0X386 << 16);
    // 0x800A5B3C: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5B40: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5B44: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5B48: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800A5B4C: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5B50: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800A5B54: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5B58: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5B5C: nop

    // 0x800A5B60: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5B64: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5B68: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x800A5B6C: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x800A5B70: lui         $t2, 0x388
    ctx->r10 = S32(0X388 << 16);
    // 0x800A5B74: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A5B78: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5B7C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A5B80: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x800A5B84: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A5B88: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x800A5B8C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5B90: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5B94: nop

    // 0x800A5B98: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5B9C: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5BA0: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    // 0x800A5BA4: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800A5BA8: lui         $t9, 0x38A
    ctx->r25 = S32(0X38A << 16);
    // 0x800A5BAC: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800A5BB0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5BB4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800A5BB8: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800A5BBC: addiu       $t1, $t1, -0x7268
    ctx->r9 = ADD32(ctx->r9, -0X7268);
    // 0x800A5BC0: addiu       $t2, $t1, 0x30
    ctx->r10 = ADD32(ctx->r9, 0X30);
    // 0x800A5BC4: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A5BC8: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5BCC: nop

    // 0x800A5BD0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A5BD4: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A5BD8: sw          $t4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r12;
    // 0x800A5BDC: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800A5BE0: lui         $t6, 0x38C
    ctx->r14 = S32(0X38C << 16);
    // 0x800A5BE4: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800A5BE8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A5BEC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A5BF0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800A5BF4: addiu       $t8, $t8, -0x7268
    ctx->r24 = ADD32(ctx->r24, -0X7268);
    // 0x800A5BF8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A5BFC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A5C00: b           L_800A62A8
    // 0x800A5C04: nop

        goto L_800A62A8;
    // 0x800A5C04: nop

L_800A5C08:
    // 0x800A5C08: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5C0C: nop

    // 0x800A5C10: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A5C14: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A5C18: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x800A5C1C: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800A5C20: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x800A5C24: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x800A5C28: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A5C2C: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800A5C30: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800A5C34: ori         $t5, $t5, 0xA0
    ctx->r13 = ctx->r13 | 0XA0;
    // 0x800A5C38: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5C3C: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5C40: nop

    // 0x800A5C44: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5C48: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5C4C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5C50: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5C54: lui         $t9, 0x386
    ctx->r25 = S32(0X386 << 16);
    // 0x800A5C58: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800A5C5C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5C60: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800A5C64: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5C68: addiu       $t1, $t1, -0x7268
    ctx->r9 = ADD32(ctx->r9, -0X7268);
    // 0x800A5C6C: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x800A5C70: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A5C74: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5C78: nop

    // 0x800A5C7C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A5C80: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A5C84: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x800A5C88: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A5C8C: lui         $t6, 0x388
    ctx->r14 = S32(0X388 << 16);
    // 0x800A5C90: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800A5C94: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A5C98: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A5C9C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800A5CA0: addiu       $t8, $t8, -0x7268
    ctx->r24 = ADD32(ctx->r24, -0X7268);
    // 0x800A5CA4: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800A5CA8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A5CAC: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5CB0: nop

    // 0x800A5CB4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A5CB8: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A5CBC: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x800A5CC0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800A5CC4: lui         $t3, 0x38A
    ctx->r11 = S32(0X38A << 16);
    // 0x800A5CC8: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x800A5CCC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A5CD0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A5CD4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800A5CD8: addiu       $t5, $t5, -0x7268
    ctx->r13 = ADD32(ctx->r13, -0X7268);
    // 0x800A5CDC: addiu       $t6, $t5, 0x30
    ctx->r14 = ADD32(ctx->r13, 0X30);
    // 0x800A5CE0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A5CE4: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5CE8: nop

    // 0x800A5CEC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A5CF0: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A5CF4: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x800A5CF8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800A5CFC: lui         $t0, 0x38C
    ctx->r8 = S32(0X38C << 16);
    // 0x800A5D00: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A5D04: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A5D08: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A5D0C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800A5D10: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A5D14: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x800A5D18: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A5D1C: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5D20: nop

    // 0x800A5D24: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A5D28: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A5D2C: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x800A5D30: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800A5D34: lui         $t7, 0x38E
    ctx->r15 = S32(0X38E << 16);
    // 0x800A5D38: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800A5D3C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A5D40: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5D44: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800A5D48: addiu       $t9, $t9, -0x7268
    ctx->r25 = ADD32(ctx->r25, -0X7268);
    // 0x800A5D4C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A5D50: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A5D54: b           L_800A62A8
    // 0x800A5D58: nop

        goto L_800A62A8;
    // 0x800A5D58: nop

L_800A5D5C:
    // 0x800A5D5C: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5D60: nop

    // 0x800A5D64: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A5D68: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800A5D6C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x800A5D70: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800A5D74: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x800A5D78: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x800A5D7C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A5D80: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800A5D84: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A5D88: ori         $t6, $t6, 0xC0
    ctx->r14 = ctx->r14 | 0XC0;
    // 0x800A5D8C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A5D90: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5D94: nop

    // 0x800A5D98: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A5D9C: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A5DA0: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800A5DA4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800A5DA8: lui         $t0, 0x386
    ctx->r8 = S32(0X386 << 16);
    // 0x800A5DAC: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A5DB0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A5DB4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A5DB8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800A5DBC: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A5DC0: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800A5DC4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A5DC8: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5DCC: nop

    // 0x800A5DD0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A5DD4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A5DD8: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x800A5DDC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800A5DE0: lui         $t7, 0x388
    ctx->r15 = S32(0X388 << 16);
    // 0x800A5DE4: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800A5DE8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A5DEC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5DF0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800A5DF4: addiu       $t9, $t9, -0x7268
    ctx->r25 = ADD32(ctx->r25, -0X7268);
    // 0x800A5DF8: addiu       $t0, $t9, 0x20
    ctx->r8 = ADD32(ctx->r25, 0X20);
    // 0x800A5DFC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A5E00: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5E04: nop

    // 0x800A5E08: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A5E0C: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800A5E10: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x800A5E14: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800A5E18: lui         $t4, 0x38A
    ctx->r12 = S32(0X38A << 16);
    // 0x800A5E1C: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x800A5E20: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A5E24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A5E28: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800A5E2C: addiu       $t6, $t6, -0x7268
    ctx->r14 = ADD32(ctx->r14, -0X7268);
    // 0x800A5E30: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x800A5E34: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A5E38: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5E3C: nop

    // 0x800A5E40: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A5E44: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A5E48: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x800A5E4C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800A5E50: lui         $t1, 0x38C
    ctx->r9 = S32(0X38C << 16);
    // 0x800A5E54: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x800A5E58: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A5E5C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A5E60: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800A5E64: addiu       $t3, $t3, -0x7268
    ctx->r11 = ADD32(ctx->r11, -0X7268);
    // 0x800A5E68: addiu       $t4, $t3, 0x40
    ctx->r12 = ADD32(ctx->r11, 0X40);
    // 0x800A5E6C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5E70: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5E74: nop

    // 0x800A5E78: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5E7C: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A5E80: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800A5E84: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A5E88: lui         $t8, 0x38E
    ctx->r24 = S32(0X38E << 16);
    // 0x800A5E8C: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5E90: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5E94: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A5E98: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800A5E9C: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5EA0: addiu       $t1, $t0, 0x50
    ctx->r9 = ADD32(ctx->r8, 0X50);
    // 0x800A5EA4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5EA8: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5EAC: nop

    // 0x800A5EB0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5EB4: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5EB8: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800A5EBC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800A5EC0: lui         $t5, 0x390
    ctx->r13 = S32(0X390 << 16);
    // 0x800A5EC4: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5EC8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5ECC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5ED0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800A5ED4: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5ED8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5EDC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5EE0: b           L_800A62A8
    // 0x800A5EE4: nop

        goto L_800A62A8;
    // 0x800A5EE4: nop

L_800A5EE8:
    // 0x800A5EE8: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5EEC: nop

    // 0x800A5EF0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5EF4: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5EF8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800A5EFC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A5F00: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A5F04: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A5F08: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5F0C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A5F10: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A5F14: ori         $t4, $t4, 0xE0
    ctx->r12 = ctx->r12 | 0XE0;
    // 0x800A5F18: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5F1C: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5F20: nop

    // 0x800A5F24: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5F28: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A5F2C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x800A5F30: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800A5F34: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A5F38: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5F3C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5F40: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A5F44: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A5F48: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5F4C: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A5F50: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5F54: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5F58: nop

    // 0x800A5F5C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5F60: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5F64: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800A5F68: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A5F6C: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A5F70: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5F74: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5F78: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5F7C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800A5F80: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5F84: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x800A5F88: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5F8C: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5F90: nop

    // 0x800A5F94: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5F98: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5F9C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800A5FA0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A5FA4: lui         $t2, 0x38A
    ctx->r10 = S32(0X38A << 16);
    // 0x800A5FA8: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A5FAC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5FB0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A5FB4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A5FB8: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A5FBC: addiu       $t5, $t4, 0x30
    ctx->r13 = ADD32(ctx->r12, 0X30);
    // 0x800A5FC0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5FC4: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5FC8: nop

    // 0x800A5FCC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5FD0: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5FD4: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A5FD8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5FDC: lui         $t9, 0x38C
    ctx->r25 = S32(0X38C << 16);
    // 0x800A5FE0: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800A5FE4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5FE8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800A5FEC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5FF0: addiu       $t1, $t1, -0x7268
    ctx->r9 = ADD32(ctx->r9, -0X7268);
    // 0x800A5FF4: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x800A5FF8: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A5FFC: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6000: nop

    // 0x800A6004: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A6008: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A600C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800A6010: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A6014: lui         $t6, 0x38E
    ctx->r14 = S32(0X38E << 16);
    // 0x800A6018: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800A601C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A6020: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A6024: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800A6028: addiu       $t8, $t8, -0x7268
    ctx->r24 = ADD32(ctx->r24, -0X7268);
    // 0x800A602C: addiu       $t9, $t8, 0x50
    ctx->r25 = ADD32(ctx->r24, 0X50);
    // 0x800A6030: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A6034: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6038: nop

    // 0x800A603C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A6040: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A6044: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800A6048: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800A604C: lui         $t3, 0x390
    ctx->r11 = S32(0X390 << 16);
    // 0x800A6050: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x800A6054: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A6058: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A605C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A6060: addiu       $t5, $t5, -0x7268
    ctx->r13 = ADD32(ctx->r13, -0X7268);
    // 0x800A6064: addiu       $t6, $t5, 0x60
    ctx->r14 = ADD32(ctx->r13, 0X60);
    // 0x800A6068: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A606C: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6070: nop

    // 0x800A6074: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A6078: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A607C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800A6080: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A6084: lui         $t0, 0x392
    ctx->r8 = S32(0X392 << 16);
    // 0x800A6088: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A608C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A6090: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A6094: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A6098: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A609C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A60A0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A60A4: b           L_800A62A8
    // 0x800A60A8: nop

        goto L_800A62A8;
    // 0x800A60A8: nop

L_800A60AC:
    // 0x800A60AC: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A60B0: nop

    // 0x800A60B4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A60B8: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A60BC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800A60C0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800A60C4: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800A60C8: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800A60CC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A60D0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800A60D4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800A60D8: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x800A60DC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A60E0: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A60E4: nop

    // 0x800A60E8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A60EC: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A60F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800A60F4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800A60F8: lui         $t3, 0x386
    ctx->r11 = S32(0X386 << 16);
    // 0x800A60FC: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x800A6100: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A6104: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A6108: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A610C: addiu       $t5, $t5, -0x7268
    ctx->r13 = ADD32(ctx->r13, -0X7268);
    // 0x800A6110: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800A6114: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A6118: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A611C: nop

    // 0x800A6120: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A6124: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A6128: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800A612C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A6130: lui         $t0, 0x388
    ctx->r8 = S32(0X388 << 16);
    // 0x800A6134: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A6138: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A613C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A6140: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800A6144: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A6148: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x800A614C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A6150: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6154: nop

    // 0x800A6158: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A615C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A6160: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800A6164: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A6168: lui         $t7, 0x38A
    ctx->r15 = S32(0X38A << 16);
    // 0x800A616C: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800A6170: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A6174: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A6178: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800A617C: addiu       $t9, $t9, -0x7268
    ctx->r25 = ADD32(ctx->r25, -0X7268);
    // 0x800A6180: addiu       $t0, $t9, 0x30
    ctx->r8 = ADD32(ctx->r25, 0X30);
    // 0x800A6184: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A6188: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A618C: nop

    // 0x800A6190: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A6194: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800A6198: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A619C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800A61A0: lui         $t4, 0x38C
    ctx->r12 = S32(0X38C << 16);
    // 0x800A61A4: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x800A61A8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A61AC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A61B0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A61B4: addiu       $t6, $t6, -0x7268
    ctx->r14 = ADD32(ctx->r14, -0X7268);
    // 0x800A61B8: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800A61BC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A61C0: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800A61C4: nop

    // 0x800A61C8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A61CC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A61D0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A61D4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800A61D8: lui         $t1, 0x38E
    ctx->r9 = S32(0X38E << 16);
    // 0x800A61DC: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x800A61E0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A61E4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A61E8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A61EC: addiu       $t3, $t3, -0x7268
    ctx->r11 = ADD32(ctx->r11, -0X7268);
    // 0x800A61F0: addiu       $t4, $t3, 0x50
    ctx->r12 = ADD32(ctx->r11, 0X50);
    // 0x800A61F4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A61F8: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A61FC: nop

    // 0x800A6200: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A6204: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A6208: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A620C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800A6210: lui         $t8, 0x390
    ctx->r24 = S32(0X390 << 16);
    // 0x800A6214: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A6218: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A621C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A6220: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800A6224: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A6228: addiu       $t1, $t0, 0x60
    ctx->r9 = ADD32(ctx->r8, 0X60);
    // 0x800A622C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A6230: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6234: nop

    // 0x800A6238: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A623C: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A6240: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A6244: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800A6248: lui         $t5, 0x392
    ctx->r13 = S32(0X392 << 16);
    // 0x800A624C: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A6250: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A6254: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A6258: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x800A625C: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A6260: addiu       $t8, $t7, 0x70
    ctx->r24 = ADD32(ctx->r15, 0X70);
    // 0x800A6264: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A6268: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A626C: nop

    // 0x800A6270: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A6274: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A6278: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x800A627C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800A6280: lui         $t2, 0x394
    ctx->r10 = S32(0X394 << 16);
    // 0x800A6284: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A6288: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A628C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A6290: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800A6294: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A6298: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A629C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A62A0: b           L_800A62A8
    // 0x800A62A4: nop

        goto L_800A62A8;
    // 0x800A62A4: nop

L_800A62A8:
    // 0x800A62A8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A62AC: lw          $t7, -0x71D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71D0);
    // 0x800A62B0: nop

    // 0x800A62B4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800A62B8: beq         $t8, $zero, L_800A63F0
    if (ctx->r24 == 0) {
        // 0x800A62BC: nop
    
            goto L_800A63F0;
    }
    // 0x800A62BC: nop

    // 0x800A62C0: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800A62C4: nop

    // 0x800A62C8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A62CC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A62D0: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800A62D4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800A62D8: lui         $t1, 0xBC00
    ctx->r9 = S32(0XBC00 << 16);
    // 0x800A62DC: ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    // 0x800A62E0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A62E4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A62E8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A62EC: lw          $t4, -0x71E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X71E8);
    // 0x800A62F0: lw          $t3, -0x71E4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X71E4);
    // 0x800A62F4: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800A62F8: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800A62FC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800A6300: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x800A6304: negu        $t0, $t4
    ctx->r8 = SUB32(0, ctx->r12);
    // 0x800A6308: bne         $t5, $zero, L_800A6314
    if (ctx->r13 != 0) {
        // 0x800A630C: nop
    
            goto L_800A6314;
    }
    // 0x800A630C: nop

    // 0x800A6310: break       7
    do_break(2148164368);
L_800A6314:
    // 0x800A6314: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A6318: bne         $t5, $at, L_800A632C
    if (ctx->r13 != ctx->r1) {
        // 0x800A631C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A632C;
    }
    // 0x800A631C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A6320: bne         $t6, $at, L_800A632C
    if (ctx->r14 != ctx->r1) {
        // 0x800A6324: nop
    
            goto L_800A632C;
    }
    // 0x800A6324: nop

    // 0x800A6328: break       6
    do_break(2148164392);
L_800A632C:
    // 0x800A632C: addu        $at, $t6, $zero
    ctx->r1 = ADD32(ctx->r14, 0);
    // 0x800A6330: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800A6334: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800A6338: mflo        $t7
    ctx->r15 = lo;
    // 0x800A633C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800A6340: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800A6344: div         $zero, $t2, $t5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r13)));
    // 0x800A6348: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800A634C: bne         $t5, $zero, L_800A6358
    if (ctx->r13 != 0) {
        // 0x800A6350: nop
    
            goto L_800A6358;
    }
    // 0x800A6350: nop

    // 0x800A6354: break       7
    do_break(2148164436);
L_800A6358:
    // 0x800A6358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A635C: bne         $t5, $at, L_800A6370
    if (ctx->r13 != ctx->r1) {
        // 0x800A6360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A6370;
    }
    // 0x800A6360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A6364: bne         $t2, $at, L_800A6370
    if (ctx->r10 != ctx->r1) {
        // 0x800A6368: nop
    
            goto L_800A6370;
    }
    // 0x800A6368: nop

    // 0x800A636C: break       6
    do_break(2148164460);
L_800A6370:
    // 0x800A6370: mflo        $t3
    ctx->r11 = lo;
    // 0x800A6374: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800A6378: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800A637C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A6380: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6384: nop

    // 0x800A6388: addiu       $t0, $t4, 0x8
    ctx->r8 = ADD32(ctx->r12, 0X8);
    // 0x800A638C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A6390: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800A6394: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A6398: lui         $t1, 0xF800
    ctx->r9 = S32(0XF800 << 16);
    // 0x800A639C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A63A0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A63A4: lw          $t5, -0x71E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X71E0);
    // 0x800A63A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A63AC: lw          $t6, -0x71DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71DC);
    // 0x800A63B0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A63B4: andi        $t3, $t5, 0xFF
    ctx->r11 = ctx->r13 & 0XFF;
    // 0x800A63B8: lw          $t0, -0x71D8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X71D8);
    // 0x800A63BC: sll         $t9, $t3, 24
    ctx->r25 = S32(ctx->r11 << 24);
    // 0x800A63C0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A63C4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800A63C8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A63CC: lw          $t3, -0x71D4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X71D4);
    // 0x800A63D0: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x800A63D4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800A63D8: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800A63DC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A63E0: or          $t5, $t4, $t2
    ctx->r13 = ctx->r12 | ctx->r10;
    // 0x800A63E4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x800A63E8: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800A63EC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
L_800A63F0:
    // 0x800A63F0: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A63F4: nop

    // 0x800A63F8: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x800A63FC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A6400: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x800A6404: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800A6408: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800A640C: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800A6410: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800A6414: nop

    // 0x800A6418: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A641C: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6420: nop

    // 0x800A6424: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800A6428: b           L_800A6438
    // 0x800A642C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A6438;
    // 0x800A642C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A6430: b           L_800A6438
    // 0x800A6434: nop

        goto L_800A6438;
    // 0x800A6434: nop

L_800A6438:
    // 0x800A6438: jr          $ra
    // 0x800A643C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800A643C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800AF72C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF72C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AF730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AF734: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AF738: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF73C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF740: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF744: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF748: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800AF74C: jal         0x800BD1FC
    // 0x800AF750: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800AF750: nop

    after_0:
    // 0x800AF754: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF758: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF75C: addiu       $t6, $t6, 0x4A8
    ctx->r14 = ADD32(ctx->r14, 0X4A8);
    // 0x800AF760: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800AF764: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF768: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AF76C: jal         0x800BD218
    // 0x800AF770: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800AF770: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800AF774: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AF778: nop

    // 0x800AF77C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800AF780: nop

    // 0x800AF784: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800AF788: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800AF78C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF790: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF794: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF798: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF79C: jal         0x800BD1FC
    // 0x800AF7A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800AF7A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_2:
    // 0x800AF7A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF7A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF7AC: nop

    // 0x800AF7B0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800AF7B4: jal         0x800BC6EC
    // 0x800AF7B8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800AF7B8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x800AF7BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800AF7C0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800AF7C4: nop

    // 0x800AF7C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800AF7CC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800AF7D0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF7D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF7D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AF7DC: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x800AF7E0: jal         0x800BD218
    // 0x800AF7E4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x800AF7E4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_4:
    // 0x800AF7E8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF7EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF7F0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800AF7F4: sh          $t3, 0x1D8($at)
    MEM_H(0X1D8, ctx->r1) = ctx->r11;
    // 0x800AF7F8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF7FC: lhu         $a0, 0x1D8($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1D8);
    // 0x800AF800: nop

    // 0x800AF804: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800AF808: jal         0x800BC6EC
    // 0x800AF80C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x800AF80C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x800AF810: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF814: sw          $v0, 0x1D4($at)
    MEM_W(0X1D4, ctx->r1) = ctx->r2;
    // 0x800AF818: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800AF81C: lw          $t5, 0x1D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1D4);
    // 0x800AF820: nop

    // 0x800AF824: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800AF828: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF82C: lhu         $t6, 0x1D8($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1D8);
    // 0x800AF830: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800AF834: blez        $t6, L_800AF908
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AF838: nop
    
            goto L_800AF908;
    }
    // 0x800AF838: nop

L_800AF83C:
    // 0x800AF83C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800AF840: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF844: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF848: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF84C: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF850: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x800AF854: jal         0x800BD1FC
    // 0x800AF858: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x800AF858: nop

    after_6:
    // 0x800AF85C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF860: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF864: jal         0x800BED70
    // 0x800AF868: nop

    Spi_GetHeader(rdram, ctx);
        goto after_7;
    // 0x800AF868: nop

    after_7:
    // 0x800AF86C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800AF870: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800AF874: addiu       $t8, $t8, 0x4A8
    ctx->r24 = ADD32(ctx->r24, 0X4A8);
    // 0x800AF878: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800AF87C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF880: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800AF884: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800AF888: jal         0x800BF0B4
    // 0x800AF88C: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_8;
    // 0x800AF88C: nop

    after_8:
    // 0x800AF890: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800AF894: lw          $t9, 0x494($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X494);
    // 0x800AF898: nop

    // 0x800AF89C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800AF8A0: jal         0x800BC6EC
    // 0x800AF8A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_9;
    // 0x800AF8A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
    // 0x800AF8A8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8AC: nop

    // 0x800AF8B0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800AF8B4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AF8BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF8C0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800AF8C4: jal         0x800BD218
    // 0x800AF8C8: nop

    SysMem_DmaCopy(rdram, ctx);
        goto after_10;
    // 0x800AF8C8: nop

    after_10:
    // 0x800AF8CC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8D0: nop

    // 0x800AF8D4: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800AF8D8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800AF8DC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800AF8E0: nop

    // 0x800AF8E4: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800AF8E8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AF8EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF8F0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800AF8F4: lhu         $t8, 0x1D8($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1D8);
    // 0x800AF8F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800AF8FC: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AF900: bne         $at, $zero, L_800AF83C
    if (ctx->r1 != 0) {
        // 0x800AF904: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_800AF83C;
    }
    // 0x800AF904: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_800AF908:
    // 0x800AF908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800AF90C: jal         0x800BC980
    // 0x800AF910: nop

    SysMem_Free(rdram, ctx);
        goto after_11;
    // 0x800AF910: nop

    after_11:
    // 0x800AF914: b           L_800AF91C
    // 0x800AF918: nop

        goto L_800AF91C;
    // 0x800AF918: nop

L_800AF91C:
    // 0x800AF91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AF920: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AF924: jr          $ra
    // 0x800AF928: nop

    return;
    // 0x800AF928: nop

;}
RECOMP_FUNC void func_8004EF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EF90: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004EF94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004EF98: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8004EF9C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8004EFA0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8004EFA4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8004EFA8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004EFAC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8004EFB0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004EFB4: andi        $t7, $t6, 0x1FFF
    ctx->r15 = ctx->r14 & 0X1FFF;
    // 0x8004EFB8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8004EFBC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8004EFC0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8004EFC4: nop

    // 0x8004EFC8: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x8004EFCC: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x8004EFD0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004EFD4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004EFD8: nop

    // 0x8004EFDC: sw          $zero, 0x98($t1)
    MEM_W(0X98, ctx->r9) = 0;
    // 0x8004EFE0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004EFE4: lw          $t2, 0x258C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X258C);
    // 0x8004EFE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004EFEC: sw          $t2, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r10;
    // 0x8004EFF0: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    // 0x8004EFF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004EFF8: or          $t3, $a3, $at
    ctx->r11 = ctx->r7 | ctx->r1;
    // 0x8004EFFC: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x8004F000: addiu       $a0, $sp, 0x46
    ctx->r4 = ADD32(ctx->r29, 0X46);
    // 0x8004F004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004F008: jal         0x800B3230
    // 0x8004F00C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_0;
    // 0x8004F00C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8004F010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F014: bne         $v0, $at, L_8004F050
    if (ctx->r2 != ctx->r1) {
        // 0x8004F018: nop
    
            goto L_8004F050;
    }
    // 0x8004F018: nop

    // 0x8004F01C: addiu       $t4, $zero, 0x23
    ctx->r12 = ADD32(0, 0X23);
    // 0x8004F020: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x8004F024: ori         $a3, $a3, 0x23
    ctx->r7 = ctx->r7 | 0X23;
    // 0x8004F028: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8004F02C: addiu       $a0, $sp, 0x46
    ctx->r4 = ADD32(ctx->r29, 0X46);
    // 0x8004F030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004F034: jal         0x800B3230
    // 0x8004F038: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_1;
    // 0x8004F038: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8004F03C: lui         $t5, 0x2A
    ctx->r13 = S32(0X2A << 16);
    // 0x8004F040: ori         $t5, $t5, 0x45
    ctx->r13 = ctx->r13 | 0X45;
    // 0x8004F044: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8004F048: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8004F04C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_8004F050:
    // 0x8004F050: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004F054: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x8004F058: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004F05C: bne         $t7, $at, L_8004F080
    if (ctx->r15 != ctx->r1) {
        // 0x8004F060: nop
    
            goto L_8004F080;
    }
    // 0x8004F060: nop

    // 0x8004F064: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8004F068: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x8004F06C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004F070: bne         $t8, $at, L_8004F080
    if (ctx->r24 != ctx->r1) {
        // 0x8004F074: nop
    
            goto L_8004F080;
    }
    // 0x8004F074: nop

    // 0x8004F078: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8004F07C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_8004F080:
    // 0x8004F080: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004F084: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004F088: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004F08C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004F090: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004F094: bne         $t4, $zero, L_8004F0A4
    if (ctx->r12 != 0) {
        // 0x8004F098: andi        $t5, $t3, 0x8
        ctx->r13 = ctx->r11 & 0X8;
            goto L_8004F0A4;
    }
    // 0x8004F098: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x8004F09C: beq         $t5, $zero, L_8004F0B0
    if (ctx->r13 == 0) {
        // 0x8004F0A0: nop
    
            goto L_8004F0B0;
    }
    // 0x8004F0A0: nop

L_8004F0A4:
    // 0x8004F0A4: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x8004F0A8: b           L_8004F0C0
    // 0x8004F0AC: nop

        goto L_8004F0C0;
    // 0x8004F0AC: nop

L_8004F0B0:
    // 0x8004F0B0: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x8004F0B4: nop

    // 0x8004F0B8: ori         $t1, $s0, 0x1
    ctx->r9 = ctx->r16 | 0X1;
    // 0x8004F0BC: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8004F0C0:
    // 0x8004F0C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F0C4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F0C8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8004F0CC: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8004F0D0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004F0D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8004F0D8: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8004F0DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F0E0: addiu       $a0, $t6, 0x4C
    ctx->r4 = ADD32(ctx->r14, 0X4C);
    // 0x8004F0E4: addiu       $a1, $t6, 0x50
    ctx->r5 = ADD32(ctx->r14, 0X50);
    // 0x8004F0E8: jal         0x800B202C
    // 0x8004F0EC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_2;
    // 0x8004F0EC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8004F0F0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F0F4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F0F8: nop

    // 0x8004F0FC: sh          $v0, 0x48($t7)
    MEM_H(0X48, ctx->r15) = ctx->r2;
    // 0x8004F100: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004F104: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004F108: nop

    // 0x8004F10C: addiu       $a0, $t8, 0x50
    ctx->r4 = ADD32(ctx->r24, 0X50);
    // 0x8004F110: jal         0x8005A5F4
    // 0x8004F114: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_3;
    // 0x8004F114: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_3:
    // 0x8004F118: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004F11C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004F120: nop

    // 0x8004F124: lw          $t0, 0x4C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4C);
    // 0x8004F128: nop

    // 0x8004F12C: lwc1        $f8, 0xCC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x8004F130: nop

    // 0x8004F134: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x8004F138: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004F13C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004F140: nop

    // 0x8004F144: lw          $t3, 0x4C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4C);
    // 0x8004F148: nop

    // 0x8004F14C: lwc1        $f10, 0xD0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8004F150: nop

    // 0x8004F154: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x8004F158: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F15C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F160: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8004F164: nop

    // 0x8004F168: sh          $t4, 0x4A($t5)
    MEM_H(0X4A, ctx->r13) = ctx->r12;
    // 0x8004F16C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F170: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004F174: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F178: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8004F17C: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8004F180: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8004F184: lui         $at, 0xEFFF
    ctx->r1 = S32(0XEFFF << 16);
    // 0x8004F188: ori         $at, $at, 0xF8FD
    ctx->r1 = ctx->r1 | 0XF8FD;
    // 0x8004F18C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004F190: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004F194: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004F198: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x8004F19C: nop

    // 0x8004F1A0: andi        $t3, $t0, 0x1
    ctx->r11 = ctx->r8 & 0X1;
    // 0x8004F1A4: beq         $t3, $zero, L_8004F200
    if (ctx->r11 == 0) {
        // 0x8004F1A8: nop
    
            goto L_8004F200;
    }
    // 0x8004F1A8: nop

    // 0x8004F1AC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8004F1B0: nop

    // 0x8004F1B4: andi        $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 & 0X8000;
    // 0x8004F1B8: beq         $t4, $zero, L_8004F1E8
    if (ctx->r12 == 0) {
        // 0x8004F1BC: nop
    
            goto L_8004F1E8;
    }
    // 0x8004F1BC: nop

    // 0x8004F1C0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F1C4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F1C8: nop

    // 0x8004F1CC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004F1D0: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004F1D4: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004F1D8: ori         $t9, $t7, 0x400
    ctx->r25 = ctx->r15 | 0X400;
    // 0x8004F1DC: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8004F1E0: b           L_8004F200
    // 0x8004F1E4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
        goto L_8004F200;
    // 0x8004F1E4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
L_8004F1E8:
    // 0x8004F1E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F1EC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004F1F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004F1F4: addiu       $a0, $t1, 0x4C
    ctx->r4 = ADD32(ctx->r9, 0X4C);
    // 0x8004F1F8: jal         0x800B2CBC
    // 0x8004F1FC: addiu       $a1, $t1, 0x50
    ctx->r5 = ADD32(ctx->r9, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_4;
    // 0x8004F1FC: addiu       $a1, $t1, 0x50
    ctx->r5 = ADD32(ctx->r9, 0X50);
    after_4:
L_8004F200:
    // 0x8004F200: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x8004F204: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F208: andi        $t3, $t0, 0xE
    ctx->r11 = ctx->r8 & 0XE;
    // 0x8004F20C: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8004F210: bne         $t2, $at, L_8004F23C
    if (ctx->r10 != ctx->r1) {
        // 0x8004F214: nop
    
            goto L_8004F23C;
    }
    // 0x8004F214: nop

    // 0x8004F218: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004F21C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004F220: nop

    // 0x8004F224: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004F228: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004F22C: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004F230: ori         $t9, $t7, 0x100
    ctx->r25 = ctx->r15 | 0X100;
    // 0x8004F234: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004F238: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_8004F23C:
    // 0x8004F23C: lhu         $t5, 0x46($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X46);
    // 0x8004F240: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004F244: andi        $t1, $t5, 0xE
    ctx->r9 = ctx->r13 & 0XE;
    // 0x8004F248: sra         $t0, $t1, 1
    ctx->r8 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8004F24C: beq         $t0, $at, L_8004F260
    if (ctx->r8 == ctx->r1) {
        // 0x8004F250: nop
    
            goto L_8004F260;
    }
    // 0x8004F250: nop

    // 0x8004F254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004F258: bne         $t0, $at, L_8004F288
    if (ctx->r8 != ctx->r1) {
        // 0x8004F25C: nop
    
            goto L_8004F288;
    }
    // 0x8004F25C: nop

L_8004F260:
    // 0x8004F260: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004F264: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004F268: nop

    // 0x8004F26C: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x8004F270: or          $t6, $t3, $zero
    ctx->r14 = ctx->r11 | 0;
    // 0x8004F274: lw          $t3, 0x4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4);
    // 0x8004F278: or          $t8, $t2, $zero
    ctx->r24 = ctx->r10 | 0;
    // 0x8004F27C: ori         $t9, $t3, 0x200
    ctx->r25 = ctx->r11 | 0X200;
    // 0x8004F280: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8004F284: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8004F288:
    // 0x8004F288: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F28C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F290: nop

    // 0x8004F294: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x8004F298: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x8004F29C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8004F2A0: ori         $t1, $t5, 0x4
    ctx->r9 = ctx->r13 | 0X4;
    // 0x8004F2A4: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x8004F2A8: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8004F2AC: lh          $t2, 0x3A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3A);
    // 0x8004F2B0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8004F2B4: beq         $t2, $at, L_8004F2E0
    if (ctx->r10 == ctx->r1) {
        // 0x8004F2B8: nop
    
            goto L_8004F2E0;
    }
    // 0x8004F2B8: nop

    // 0x8004F2BC: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8004F2C0: beq         $t2, $at, L_8004F2E0
    if (ctx->r10 == ctx->r1) {
        // 0x8004F2C4: nop
    
            goto L_8004F2E0;
    }
    // 0x8004F2C4: nop

    // 0x8004F2C8: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8004F2CC: beq         $t2, $at, L_8004F2E0
    if (ctx->r10 == ctx->r1) {
        // 0x8004F2D0: nop
    
            goto L_8004F2E0;
    }
    // 0x8004F2D0: nop

    // 0x8004F2D4: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8004F2D8: bne         $t2, $at, L_8004F3D0
    if (ctx->r10 != ctx->r1) {
        // 0x8004F2DC: nop
    
            goto L_8004F3D0;
    }
    // 0x8004F2DC: nop

L_8004F2E0:
    // 0x8004F2E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004F2E4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004F2E8: addiu       $t3, $zero, 0x63
    ctx->r11 = ADD32(0, 0X63);
    // 0x8004F2EC: sw          $t3, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r11;
    // 0x8004F2F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004F2F4: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004F2F8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8004F2FC: lwc1        $f16, 0xC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8004F300: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004F304: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F308: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8004F30C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8004F310: nop

    // 0x8004F314: bc1f        L_8004F334
    if (!c1cs) {
        // 0x8004F318: nop
    
            goto L_8004F334;
    }
    // 0x8004F318: nop

    // 0x8004F31C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8004F320: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F324: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F328: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F32C: b           L_8004F38C
    // 0x8004F330: swc1        $f6, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f6.u32l;
        goto L_8004F38C;
    // 0x8004F330: swc1        $f6, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f6.u32l;
L_8004F334:
    // 0x8004F334: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004F338: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004F33C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8004F340: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8004F344: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8004F348: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004F34C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004F350: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8004F354: nop

    // 0x8004F358: bc1f        L_8004F374
    if (!c1cs) {
        // 0x8004F35C: nop
    
            goto L_8004F374;
    }
    // 0x8004F35C: nop

    // 0x8004F360: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F364: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F368: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004F36C: b           L_8004F38C
    // 0x8004F370: swc1        $f18, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f18.u32l;
        goto L_8004F38C;
    // 0x8004F370: swc1        $f18, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f18.u32l;
L_8004F374:
    // 0x8004F374: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004F378: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004F37C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004F380: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004F384: nop

    // 0x8004F388: swc1        $f4, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f4.u32l;
L_8004F38C:
    // 0x8004F38C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F390: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004F394: lui         $at, 0x4041
    ctx->r1 = S32(0X4041 << 16);
    // 0x8004F398: lwc1        $f6, 0x6C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x8004F39C: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8004F3A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004F3A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004F3A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004F3AC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004F3B0: nop

    // 0x8004F3B4: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x8004F3B8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004F3BC: swc1        $f6, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f6.u32l;
    // 0x8004F3C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F3C4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F3C8: nop

    // 0x8004F3CC: sw          $zero, 0x88($t7)
    MEM_W(0X88, ctx->r15) = 0;
L_8004F3D0:
    // 0x8004F3D0: b           L_8004F3D8
    // 0x8004F3D4: nop

        goto L_8004F3D8;
    // 0x8004F3D4: nop

L_8004F3D8:
    // 0x8004F3D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F3DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004F3E0: jr          $ra
    // 0x8004F3E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004F3E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006E154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E15C: jal         0x80061348
    // 0x8006E160: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E160: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006E164: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E168: b           L_8006E178
    // 0x8006E16C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E178;
    // 0x8006E16C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E170: b           L_8006E178
    // 0x8006E174: nop

        goto L_8006E178;
    // 0x8006E174: nop

L_8006E178:
    // 0x8006E178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E180: jr          $ra
    // 0x8006E184: nop

    return;
    // 0x8006E184: nop

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
RECOMP_FUNC void func_800C01D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C01D4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C01D8: lw          $t6, 0x484($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X484);
    // 0x800C01DC: nop

    // 0x800C01E0: bne         $t6, $zero, L_800C022C
    if (ctx->r14 != 0) {
        // 0x800C01E4: nop
    
            goto L_800C022C;
    }
    // 0x800C01E4: nop

    // 0x800C01E8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C01EC: lw          $t7, 0x484($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X484);
    // 0x800C01F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C01F4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C01F8: sw          $t8, 0x484($at)
    MEM_W(0X484, ctx->r1) = ctx->r24;
    // 0x800C01FC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C0200: lw          $t9, 0x43C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X43C);
    // 0x800C0204: nop

    // 0x800C0208: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x800C020C: nop

    // 0x800C0210: sra         $t0, $v0, 4
    ctx->r8 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800C0214: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800C0218: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x800C021C: jr          $ra
    // 0x800C0220: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800C0220: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800C0224: b           L_800C0268
    // 0x800C0228: nop

        goto L_800C0268;
    // 0x800C0228: nop

L_800C022C:
    // 0x800C022C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C0230: lw          $t2, 0x43C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X43C);
    // 0x800C0234: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0238: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C023C: sw          $t3, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r11;
    // 0x800C0240: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0244: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
    // 0x800C0248: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800C024C: lw          $t4, 0x43C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X43C);
    // 0x800C0250: nop

    // 0x800C0254: lbu         $v0, -0x1($t4)
    ctx->r2 = MEM_BU(ctx->r12, -0X1);
    // 0x800C0258: nop

    // 0x800C025C: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x800C0260: jr          $ra
    // 0x800C0264: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    return;
    // 0x800C0264: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800C0268:
    // 0x800C0268: jr          $ra
    // 0x800C026C: nop

    return;
    // 0x800C026C: nop

    // 0x800C0270: jr          $ra
    // 0x800C0274: nop

    return;
    // 0x800C0274: nop

;}
RECOMP_FUNC void func_80062A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062A60: jal         0x8005F064
    // 0x80062A64: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062A64: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_0:
    // 0x80062A68: b           L_80062A78
    // 0x80062A6C: nop

        goto L_80062A78;
    // 0x80062A6C: nop

    // 0x80062A70: b           L_80062A78
    // 0x80062A74: nop

        goto L_80062A78;
    // 0x80062A74: nop

L_80062A78:
    // 0x80062A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062A80: jr          $ra
    // 0x80062A84: nop

    return;
    // 0x80062A84: nop

;}
RECOMP_FUNC void func_8008E358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E358: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8008E35C: addiu       $t6, $zero, 0x4A8B
    ctx->r14 = ADD32(0, 0X4A8B);
    // 0x8008E360: sh          $t6, 0x100($t7)
    MEM_H(0X100, ctx->r15) = ctx->r14;
    // 0x8008E364: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8008E368: ori         $t8, $zero, 0x8457
    ctx->r24 = 0 | 0X8457;
    // 0x8008E36C: sh          $t8, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r24;
    // 0x8008E370: jr          $ra
    // 0x8008E374: nop

    return;
    // 0x8008E374: nop

    // 0x8008E378: jr          $ra
    // 0x8008E37C: nop

    return;
    // 0x8008E37C: nop

;}
RECOMP_FUNC void Thread_ReceiveMsgInThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C143C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C1440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1444: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C1448: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C144C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C1450: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800C1454: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C1458: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C145C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1460: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1464: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C1468: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C146C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1470: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1474: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800C1478: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C147C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C1480: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1484: nop

    // 0x800C1488: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800C148C: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800C1490: nop

    // 0x800C1494: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800C1498: bne         $t2, $zero, L_800C14A8
    if (ctx->r10 != 0) {
        // 0x800C149C: nop
    
            goto L_800C14A8;
    }
    // 0x800C149C: nop

    // 0x800C14A0: b           L_800C14D0
    // 0x800C14A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C14D0;
    // 0x800C14A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C14A8:
    // 0x800C14A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C14AC: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C14B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800C14B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C14B8: jal         0x800C4C40
    // 0x800C14BC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C14BC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_0:
    // 0x800C14C0: b           L_800C14D0
    // 0x800C14C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C14D0;
    // 0x800C14C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C14C8: b           L_800C14D0
    // 0x800C14CC: nop

        goto L_800C14D0;
    // 0x800C14CC: nop

L_800C14D0:
    // 0x800C14D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C14D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C14D8: jr          $ra
    // 0x800C14DC: nop

    return;
    // 0x800C14DC: nop

;}
