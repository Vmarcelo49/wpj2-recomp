#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8004984C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004984C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80049850: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80049854:
    // 0x80049854: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80049858: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004985C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80049860: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80049864: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80049868: addiu       $t8, $t8, 0xEF8
    ctx->r24 = ADD32(ctx->r24, 0XEF8);
    // 0x8004986C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80049870: lbu         $t0, 0x20($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X20);
    // 0x80049874: nop

    // 0x80049878: beq         $t0, $zero, L_8004989C
    if (ctx->r8 == 0) {
        // 0x8004987C: nop
    
            goto L_8004989C;
    }
    // 0x8004987C: nop

    // 0x80049880: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x80049884: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x80049888: nop

    // 0x8004988C: bne         $t1, $t2, L_8004989C
    if (ctx->r9 != ctx->r10) {
        // 0x80049890: nop
    
            goto L_8004989C;
    }
    // 0x80049890: nop

    // 0x80049894: b           L_800498C4
    // 0x80049898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800498C4;
    // 0x80049898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004989C:
    // 0x8004989C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800498A0: nop

    // 0x800498A4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800498A8: slti        $at, $t4, 0x7
    ctx->r1 = SIGNED(ctx->r12) < 0X7 ? 1 : 0;
    // 0x800498AC: bne         $at, $zero, L_80049854
    if (ctx->r1 != 0) {
        // 0x800498B0: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_80049854;
    }
    // 0x800498B0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800498B4: b           L_800498C4
    // 0x800498B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800498C4;
    // 0x800498B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800498BC: b           L_800498C4
    // 0x800498C0: nop

        goto L_800498C4;
    // 0x800498C0: nop

L_800498C4:
    // 0x800498C4: jr          $ra
    // 0x800498C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800498C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80076FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076FFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077004: jal         0x80061488
    // 0x80077008: addiu       $a0, $zero, 0x557
    ctx->r4 = ADD32(0, 0X557);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077008: addiu       $a0, $zero, 0x557
    ctx->r4 = ADD32(0, 0X557);
    after_0:
    // 0x8007700C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80077010: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077014: b           L_80077024
    // 0x80077018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077024;
    // 0x80077018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007701C: b           L_80077024
    // 0x80077020: nop

        goto L_80077024;
    // 0x80077020: nop

L_80077024:
    // 0x80077024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007702C: jr          $ra
    // 0x80077030: nop

    return;
    // 0x80077030: nop

;}
RECOMP_FUNC void func_800A5844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5844: jr          $ra
    // 0x800A5848: nop

    return;
    // 0x800A5848: nop

    // 0x800A584C: jr          $ra
    // 0x800A5850: nop

    return;
    // 0x800A5850: nop

;}
RECOMP_FUNC void func_80067900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067900: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067904: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067908: nop

    // 0x8006790C: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80067910: nop

    // 0x80067914: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067918: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006791C: jr          $ra
    // 0x80067920: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067920: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067924: jr          $ra
    // 0x80067928: nop

    return;
    // 0x80067928: nop

    // 0x8006792C: jr          $ra
    // 0x80067930: nop

    return;
    // 0x80067930: nop

;}
RECOMP_FUNC void func_800317E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800317E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800317E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800317EC: jal         0x80031AC8
    // 0x800317F0: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x800317F0: nop

    after_0:
    // 0x800317F4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800317F8: bne         $v0, $at, L_80031808
    if (ctx->r2 != ctx->r1) {
        // 0x800317FC: nop
    
            goto L_80031808;
    }
    // 0x800317FC: nop

    // 0x80031800: b           L_80031864
    // 0x80031804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80031864;
    // 0x80031804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031808:
    // 0x80031808: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8003180C:
    // 0x8003180C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80031810: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031814: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031818: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8003181C: sw          $zero, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = 0;
    // 0x80031820: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80031824: nop

    // 0x80031828: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003182C: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x80031830: bne         $at, $zero, L_8003180C
    if (ctx->r1 != 0) {
        // 0x80031834: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_8003180C;
    }
    // 0x80031834: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80031838: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003183C: sh          $zero, 0x2570($at)
    MEM_H(0X2570, ctx->r1) = 0;
    // 0x80031840: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031844: sh          $zero, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = 0;
    // 0x80031848: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x8003184C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031850: sh          $t0, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r8;
    // 0x80031854: b           L_80031864
    // 0x80031858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031864;
    // 0x80031858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003185C: b           L_80031864
    // 0x80031860: nop

        goto L_80031864;
    // 0x80031860: nop

L_80031864:
    // 0x80031864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003186C: jr          $ra
    // 0x80031870: nop

    return;
    // 0x80031870: nop

;}
RECOMP_FUNC void ContPak_SetFileDeleteParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE5F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE5F4: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE5F8: nop

    // 0x800AE5FC: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AE600: beq         $t7, $zero, L_800AE610
    if (ctx->r15 == 0) {
        // 0x800AE604: nop
    
            goto L_800AE610;
    }
    // 0x800AE604: nop

    // 0x800AE608: jr          $ra
    // 0x800AE60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE610:
    // 0x800AE610: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE614: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE618: nop

    // 0x800AE61C: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AE620: beq         $t9, $zero, L_800AE630
    if (ctx->r25 == 0) {
        // 0x800AE624: nop
    
            goto L_800AE630;
    }
    // 0x800AE624: nop

    // 0x800AE628: jr          $ra
    // 0x800AE62C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE62C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE630:
    // 0x800AE630: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE634: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AE638: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE63C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x800AE640: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AE644: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE648: sw          $a0, 0x1640($at)
    MEM_W(0X1640, ctx->r1) = ctx->r4;
    // 0x800AE64C: jr          $ra
    // 0x800AE650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE654: jr          $ra
    // 0x800AE658: nop

    return;
    // 0x800AE658: nop

    // 0x800AE65C: jr          $ra
    // 0x800AE660: nop

    return;
    // 0x800AE660: nop

;}
RECOMP_FUNC void func_80067A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067A2C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067A30: nop

    // 0x80067A34: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80067A38: nop

    // 0x80067A3C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067A40: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067A44: jr          $ra
    // 0x80067A48: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067A48: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067A4C: jr          $ra
    // 0x80067A50: nop

    return;
    // 0x80067A50: nop

    // 0x80067A54: jr          $ra
    // 0x80067A58: nop

    return;
    // 0x80067A58: nop

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
RECOMP_FUNC void func_80062CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062CE4: jal         0x80061488
    // 0x80062CE8: addiu       $a0, $zero, 0x695
    ctx->r4 = ADD32(0, 0X695);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062CE8: addiu       $a0, $zero, 0x695
    ctx->r4 = ADD32(0, 0X695);
    after_0:
    // 0x80062CEC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062CF0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062CF4: b           L_80062D04
    // 0x80062CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062D04;
    // 0x80062CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062CFC: b           L_80062D04
    // 0x80062D00: nop

        goto L_80062D04;
    // 0x80062D00: nop

L_80062D04:
    // 0x80062D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062D0C: jr          $ra
    // 0x80062D10: nop

    return;
    // 0x80062D10: nop

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
RECOMP_FUNC void func_8006BDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BDF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BDF8: jal         0x8005F064
    // 0x8006BDFC: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BDFC: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_0:
    // 0x8006BE00: b           L_8006BE10
    // 0x8006BE04: nop

        goto L_8006BE10;
    // 0x8006BE04: nop

    // 0x8006BE08: b           L_8006BE10
    // 0x8006BE0C: nop

        goto L_8006BE10;
    // 0x8006BE0C: nop

L_8006BE10:
    // 0x8006BE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BE18: jr          $ra
    // 0x8006BE1C: nop

    return;
    // 0x8006BE1C: nop

;}
RECOMP_FUNC void func_8001AFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AFA0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8001AFA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001AFA8: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8001AFAC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001AFB0: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001AFB4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8001AFB8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8001AFBC: nop

    // 0x8001AFC0: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8001AFC4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8001AFC8: nop

    // 0x8001AFCC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8001AFD0: nop

    // 0x8001AFD4: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8001AFD8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001AFDC: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8001AFE0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8001AFE4: nop

    // 0x8001AFE8: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8001AFEC: beq         $t1, $zero, L_8001B08C
    if (ctx->r9 == 0) {
        // 0x8001AFF0: nop
    
            goto L_8001B08C;
    }
    // 0x8001AFF0: nop

    // 0x8001AFF4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8001AFF8: addiu       $t2, $t2, 0x7340
    ctx->r10 = ADD32(ctx->r10, 0X7340);
    // 0x8001AFFC: addiu       $t3, $t2, 0x1080
    ctx->r11 = ADD32(ctx->r10, 0X1080);
    // 0x8001B000: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x8001B004: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B00C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001B010: nop

    // 0x8001B014: swc1        $f4, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f4.u32l;
    // 0x8001B018: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001B01C: nop

    // 0x8001B020: lwc1        $f6, 0xF8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x8001B024: nop

    // 0x8001B028: swc1        $f6, 0xF4($t5)
    MEM_W(0XF4, ctx->r13) = ctx->f6.u32l;
    // 0x8001B02C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001B030: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001B034: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8001B038: nop

    // 0x8001B03C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8001B040: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x8001B044: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001B048: nop

    // 0x8001B04C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8001B050: nop

    // 0x8001B054: ori         $t1, $t0, 0x810
    ctx->r9 = ctx->r8 | 0X810;
    // 0x8001B058: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
    // 0x8001B05C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001B060: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001B064: nop

    // 0x8001B068: swc1        $f8, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f8.u32l;
    // 0x8001B06C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001B070: nop

    // 0x8001B074: lwc1        $f20, 0xF0($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8001B078: nop

    // 0x8001B07C: swc1        $f20, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = ctx->f20.u32l;
    // 0x8001B080: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001B084: nop

    // 0x8001B088: swc1        $f20, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f20.u32l;
L_8001B08C:
    // 0x8001B08C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x8001B090: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001B094: nop

    // 0x8001B098: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x8001B09C: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
L_8001B0A0:
    // 0x8001B0A0: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8001B0A4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8001B0A8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8001B0AC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8001B0B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B0B4: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8001B0B8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8001B0BC: addiu       $t8, $t8, -0x5980
    ctx->r24 = ADD32(ctx->r24, -0X5980);
    // 0x8001B0C0: jal         0x80099E2C
    // 0x8001B0C4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x8001B0C4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8001B0C8: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8001B0CC: nop

    // 0x8001B0D0: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8001B0D4: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x8001B0D8: bne         $at, $zero, L_8001B0A0
    if (ctx->r1 != 0) {
        // 0x8001B0DC: sw          $t0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r8;
            goto L_8001B0A0;
    }
    // 0x8001B0DC: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x8001B0E0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001B0E4: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001B0E8: jal         0x800A6670
    // 0x8001B0EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_1;
    // 0x8001B0EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8001B0F0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001B0F4: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001B0F8: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8001B0FC: jal         0x800A6670
    // 0x8001B100: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_2;
    // 0x8001B100: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x8001B104: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001B108: addiu       $t1, $t1, -0x4E80
    ctx->r9 = ADD32(ctx->r9, -0X4E80);
    // 0x8001B10C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8001B110: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B114: jal         0x80099E2C
    // 0x8001B118: nop

    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x8001B118: nop

    after_3:
    // 0x8001B11C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001B120: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B124: swc1        $f16, -0x4DAC($at)
    MEM_W(-0X4DAC, ctx->r1) = ctx->f16.u32l;
    // 0x8001B128: swc1        $f16, -0x4DB0($at)
    MEM_W(-0X4DB0, ctx->r1) = ctx->f16.u32l;
    // 0x8001B12C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B130: swc1        $f16, -0x4DB4($at)
    MEM_W(-0X4DB4, ctx->r1) = ctx->f16.u32l;
    // 0x8001B134: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B138: sw          $zero, -0x4D78($at)
    MEM_W(-0X4D78, ctx->r1) = 0;
    // 0x8001B13C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B140: sw          $zero, -0x4D7C($at)
    MEM_W(-0X4D7C, ctx->r1) = 0;
    // 0x8001B144: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001B148: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B14C: swc1        $f18, -0x4D90($at)
    MEM_W(-0X4D90, ctx->r1) = ctx->f18.u32l;
    // 0x8001B150: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B154: swc1        $f18, -0x4D94($at)
    MEM_W(-0X4D94, ctx->r1) = ctx->f18.u32l;
    // 0x8001B158: swc1        $f18, -0x4D98($at)
    MEM_W(-0X4D98, ctx->r1) = ctx->f18.u32l;
    // 0x8001B15C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B160: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B164: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B168: swc1        $f4, -0x4D88($at)
    MEM_W(-0X4D88, ctx->r1) = ctx->f4.u32l;
    // 0x8001B16C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B170: swc1        $f4, -0x4D8C($at)
    MEM_W(-0X4D8C, ctx->r1) = ctx->f4.u32l;
    // 0x8001B174: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8001B178: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B17C: sh          $t9, -0x4D62($at)
    MEM_H(-0X4D62, ctx->r1) = ctx->r25;
    // 0x8001B180: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B184: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B188: sh          $t2, -0x4D6A($at)
    MEM_H(-0X4D6A, ctx->r1) = ctx->r10;
    // 0x8001B18C: addiu       $t3, $zero, 0x854
    ctx->r11 = ADD32(0, 0X854);
    // 0x8001B190: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B194: sw          $t3, -0x4DC0($at)
    MEM_W(-0X4DC0, ctx->r1) = ctx->r11;
    // 0x8001B198: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001B19C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1A0: sh          $t4, -0x4D6C($at)
    MEM_H(-0X4D6C, ctx->r1) = ctx->r12;
    // 0x8001B1A4: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x8001B1A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1AC: sh          $t5, -0x4D80($at)
    MEM_H(-0X4D80, ctx->r1) = ctx->r13;
    // 0x8001B1B0: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x8001B1B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1B8: sh          $t7, -0x4D7E($at)
    MEM_H(-0X4D7E, ctx->r1) = ctx->r15;
    // 0x8001B1BC: jal         0x800BC6EC
    // 0x8001B1C0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8001B1C0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    after_4:
    // 0x8001B1C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1C8: sw          $v0, -0x4D44($at)
    MEM_W(-0X4D44, ctx->r1) = ctx->r2;
    // 0x8001B1CC: jal         0x800BC6EC
    // 0x8001B1D0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8001B1D0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    after_5:
    // 0x8001B1D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1D8: sw          $v0, -0x4D40($at)
    MEM_W(-0X4D40, ctx->r1) = ctx->r2;
    // 0x8001B1DC: jal         0x800BC6EC
    // 0x8001B1E0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x8001B1E0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_6:
    // 0x8001B1E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1E8: sw          $v0, -0x4D48($at)
    MEM_W(-0X4D48, ctx->r1) = ctx->r2;
    // 0x8001B1EC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001B1F0: lw          $a0, -0x4D48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D48);
    // 0x8001B1F4: jal         0x80090A38
    // 0x8001B1F8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_80090A38(rdram, ctx);
        goto after_7;
    // 0x8001B1F8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_7:
    // 0x8001B1FC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8001B200: addiu       $t8, $t8, -0x44B8
    ctx->r24 = ADD32(ctx->r24, -0X44B8);
    // 0x8001B204: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x8001B208: nop

    // 0x8001B20C: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
    // 0x8001B210: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8001B214: addiu       $t1, $t1, -0x44B8
    ctx->r9 = ADD32(ctx->r9, -0X44B8);
    // 0x8001B218: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B21C: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8001B220: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001B224: lw          $t9, -0x4D44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D44);
    // 0x8001B228: nop

    // 0x8001B22C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8001B230: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001B234: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001B238: lh          $t3, -0x4D7E($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4D7E);
    // 0x8001B23C: lh          $t2, -0x4D80($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4D80);
    // 0x8001B240: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8001B244: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B248: mflo        $t4
    ctx->r12 = lo;
    // 0x8001B24C: blez        $t4, L_8001B298
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8001B250: nop
    
            goto L_8001B298;
    }
    // 0x8001B250: nop

L_8001B254:
    // 0x8001B254: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8001B258: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8001B25C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001B260: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8001B264: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8001B268: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001B26C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001B270: lh          $t2, -0x4D7E($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4D7E);
    // 0x8001B274: lh          $t9, -0x4D80($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4D80);
    // 0x8001B278: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8001B27C: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B280: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001B284: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x8001B288: mflo        $t3
    ctx->r11 = lo;
    // 0x8001B28C: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001B290: bne         $at, $zero, L_8001B254
    if (ctx->r1 != 0) {
        // 0x8001B294: nop
    
            goto L_8001B254;
    }
    // 0x8001B294: nop

L_8001B298:
    // 0x8001B298: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001B29C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001B2A0: lw          $a1, -0x4D44($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4D44);
    // 0x8001B2A4: lw          $a0, -0x4D40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D40);
    // 0x8001B2A8: jal         0x800BCFCC
    // 0x8001B2AC: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    SysMem_Copy8(rdram, ctx);
        goto after_8;
    // 0x8001B2AC: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_8:
    // 0x8001B2B0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8001B2B4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8001B2B8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001B2BC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001B2C0: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x8001B2C4: nop

    // 0x8001B2C8: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8001B2CC: beq         $t8, $zero, L_8001B2E4
    if (ctx->r24 == 0) {
        // 0x8001B2D0: nop
    
            goto L_8001B2E4;
    }
    // 0x8001B2D0: nop

    // 0x8001B2D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8001B2D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B2DC: b           L_8001B2F4
    // 0x8001B2E0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_8001B2F4;
    // 0x8001B2E0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8001B2E4:
    // 0x8001B2E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001B2E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B2EC: nop

    // 0x8001B2F0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_8001B2F4:
    // 0x8001B2F4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8001B2F8: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8001B2FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001B300: sh          $t5, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r13;
    // 0x8001B304: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8001B308: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8001B30C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001B310: sh          $t6, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r14;
    // 0x8001B314: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8001B318: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001B31C: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8001B320: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x8001B324: nop

    // 0x8001B328: andi        $t2, $t9, 0x4
    ctx->r10 = ctx->r25 & 0X4;
    // 0x8001B32C: bne         $t2, $zero, L_8001B344
    if (ctx->r10 != 0) {
        // 0x8001B330: nop
    
            goto L_8001B344;
    }
    // 0x8001B330: nop

    // 0x8001B334: jal         0x80098820
    // 0x8001B338: nop

    func_80098820(rdram, ctx);
        goto after_9;
    // 0x8001B338: nop

    after_9:
    // 0x8001B33C: jal         0x80098868
    // 0x8001B340: nop

    func_80098868(rdram, ctx);
        goto after_10;
    // 0x8001B340: nop

    after_10:
L_8001B344:
    // 0x8001B344: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8001B348: nop

    // 0x8001B34C: bne         $t1, $zero, L_8001C044
    if (ctx->r9 != 0) {
        // 0x8001B350: nop
    
            goto L_8001C044;
    }
    // 0x8001B350: nop

L_8001B354:
    // 0x8001B354: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8001B358: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8001B35C: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x8001B360: jal         0x800C143C
    // 0x8001B364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_11;
    // 0x8001B364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8001B368: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8001B36C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001B370: lh          $s0, 0x0($t4)
    ctx->r16 = MEM_H(ctx->r12, 0X0);
    // 0x8001B374: nop

    // 0x8001B378: beq         $s0, $at, L_8001B3AC
    if (ctx->r16 == ctx->r1) {
        // 0x8001B37C: nop
    
            goto L_8001B3AC;
    }
    // 0x8001B37C: nop

    // 0x8001B380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001B384: beq         $s0, $at, L_8001BD80
    if (ctx->r16 == ctx->r1) {
        // 0x8001B388: nop
    
            goto L_8001BD80;
    }
    // 0x8001B388: nop

    // 0x8001B38C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001B390: beq         $s0, $at, L_8001C014
    if (ctx->r16 == ctx->r1) {
        // 0x8001B394: nop
    
            goto L_8001C014;
    }
    // 0x8001B394: nop

    // 0x8001B398: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8001B39C: beq         $s0, $at, L_8001BF18
    if (ctx->r16 == ctx->r1) {
        // 0x8001B3A0: nop
    
            goto L_8001BF18;
    }
    // 0x8001B3A0: nop

    // 0x8001B3A4: b           L_8001C02C
    // 0x8001B3A8: nop

        goto L_8001C02C;
    // 0x8001B3A8: nop

L_8001B3AC:
    // 0x8001B3AC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8001B3B0: nop

    // 0x8001B3B4: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x8001B3B8: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x8001B3BC: nop

    // 0x8001B3C0: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8001B3C4: beq         $at, $zero, L_8001BD78
    if (ctx->r1 == 0) {
        // 0x8001B3C8: nop
    
            goto L_8001BD78;
    }
    // 0x8001B3C8: nop

    // 0x8001B3CC: jal         0x80099768
    // 0x8001B3D0: nop

    func_80099768(rdram, ctx);
        goto after_12;
    // 0x8001B3D0: nop

    after_12:
    // 0x8001B3D4: jal         0x800AFB28
    // 0x8001B3D8: nop

    func_800AFB28(rdram, ctx);
        goto after_13;
    // 0x8001B3D8: nop

    after_13:
    // 0x8001B3DC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8001B3E0: lw          $t6, -0x4CC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CC4);
    // 0x8001B3E4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8001B3E8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001B3EC: lw          $t5, -0x4CCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CCC);
    // 0x8001B3F0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001B3F4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8001B3F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B3FC: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x8001B400: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8001B404: jal         0x800BE510
    // 0x8001B408: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_800BE510(rdram, ctx);
        goto after_14;
    // 0x8001B408: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_14:
    // 0x8001B40C: jal         0x80032604
    // 0x8001B410: nop

    func_80032604(rdram, ctx);
        goto after_15;
    // 0x8001B410: nop

    after_15:
    // 0x8001B414: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001B418: lhu         $t0, 0x24FC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X24FC);
    // 0x8001B41C: nop

    // 0x8001B420: beq         $t0, $zero, L_8001B43C
    if (ctx->r8 == 0) {
        // 0x8001B424: nop
    
            goto L_8001B43C;
    }
    // 0x8001B424: nop

    // 0x8001B428: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001B42C: lw          $t9, -0x4D44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D44);
    // 0x8001B430: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B434: b           L_8001B44C
    // 0x8001B438: sw          $t9, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->r25;
        goto L_8001B44C;
    // 0x8001B438: sw          $t9, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->r25;
L_8001B43C:
    // 0x8001B43C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001B440: lw          $t2, -0x4D40($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4D40);
    // 0x8001B444: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B448: sw          $t2, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->r10;
L_8001B44C:
    // 0x8001B44C: jal         0x80096474
    // 0x8001B450: nop

    func_80096474(rdram, ctx);
        goto after_16;
    // 0x8001B450: nop

    after_16:
    // 0x8001B454: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001B458: lw          $a0, -0x4D58($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D58);
    // 0x8001B45C: jal         0x8008ECCC
    // 0x8001B460: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_17;
    // 0x8001B460: nop

    after_17:
    // 0x8001B464: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8001B468: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B46C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001B470: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001B474: jal         0x8008EC8C
    // 0x8001B478: nop

    func_8008EC8C(rdram, ctx);
        goto after_18;
    // 0x8001B478: nop

    after_18:
    // 0x8001B47C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8001B480: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B484: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001B488: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001B48C: jal         0x8008ECAC
    // 0x8001B490: nop

    func_8008ECAC(rdram, ctx);
        goto after_19;
    // 0x8001B490: nop

    after_19:
    // 0x8001B494: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B498: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001B49C: sw          $t1, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r9;
    // 0x8001B4A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8001B4A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001B4A8: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
    // 0x8001B4AC: jal         0x80090754
    // 0x8001B4B0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    func_80090754(rdram, ctx);
        goto after_20;
    // 0x8001B4B0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    after_20:
    // 0x8001B4B4: jal         0x80090728
    // 0x8001B4B8: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    func_80090728(rdram, ctx);
        goto after_21;
    // 0x8001B4B8: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    after_21:
    // 0x8001B4BC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8001B4C0: nop

    // 0x8001B4C4: bne         $t4, $zero, L_8001B974
    if (ctx->r12 != 0) {
        // 0x8001B4C8: nop
    
            goto L_8001B974;
    }
    // 0x8001B4C8: nop

    // 0x8001B4CC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B4D0: addiu       $t7, $zero, 0x3F
    ctx->r15 = ADD32(0, 0X3F);
    // 0x8001B4D4: lw          $t5, 0x138($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X138);
    // 0x8001B4D8: nop

    // 0x8001B4DC: sh          $t7, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r15;
    // 0x8001B4E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B4E4: addiu       $t6, $t6, -0x4E60
    ctx->r14 = ADD32(ctx->r14, -0X4E60);
    // 0x8001B4E8: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8001B4EC: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8001B4F0: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8001B4F4: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_8001B4F8:
    // 0x8001B4F8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8001B4FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B500: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8001B504: nop

    // 0x8001B508: bne         $t9, $at, L_8001B518
    if (ctx->r25 != ctx->r1) {
        // 0x8001B50C: nop
    
            goto L_8001B518;
    }
    // 0x8001B50C: nop

    // 0x8001B510: b           L_8001B6BC
    // 0x8001B514: nop

        goto L_8001B6BC;
    // 0x8001B514: nop

L_8001B518:
    // 0x8001B518: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8001B51C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B520: lw          $t1, 0xC($t2)
    ctx->r9 = MEM_W(ctx->r10, 0XC);
    // 0x8001B524: nop

    // 0x8001B528: beq         $t1, $at, L_8001B564
    if (ctx->r9 == ctx->r1) {
        // 0x8001B52C: nop
    
            goto L_8001B564;
    }
    // 0x8001B52C: nop

    // 0x8001B530: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8001B534: nop

    // 0x8001B538: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8001B53C: lw          $a1, 0xC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC);
    // 0x8001B540: jal         0x8008EAA8
    // 0x8001B544: nop

    func_8008EAA8(rdram, ctx);
        goto after_22;
    // 0x8001B544: nop

    after_22:
    // 0x8001B548: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8001B54C: nop

    // 0x8001B550: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x8001B554: nop

    // 0x8001B558: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001B55C: b           L_8001B580
    // 0x8001B560: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
        goto L_8001B580;
    // 0x8001B560: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
L_8001B564:
    // 0x8001B564: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8001B568: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8001B56C: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8001B570: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8001B574: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x8001B578: jal         0x8008EAA8
    // 0x8001B57C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_23;
    // 0x8001B57C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_23:
L_8001B580:
    // 0x8001B580: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8001B584: nop

    // 0x8001B588: lw          $t2, 0x10($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X10);
    // 0x8001B58C: nop

    // 0x8001B590: beq         $t2, $zero, L_8001B68C
    if (ctx->r10 == 0) {
        // 0x8001B594: nop
    
            goto L_8001B68C;
    }
    // 0x8001B594: nop

    // 0x8001B598: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B59C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8001B5A0: nop

    // 0x8001B5A4: bne         $t1, $t3, L_8001B634
    if (ctx->r9 != ctx->r11) {
        // 0x8001B5A8: nop
    
            goto L_8001B634;
    }
    // 0x8001B5A8: nop

    // 0x8001B5AC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8001B5B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B5B4: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x8001B5B8: jal         0x8008ECE4
    // 0x8001B5BC: addiu       $a0, $a0, -0x28AC
    ctx->r4 = ADD32(ctx->r4, -0X28AC);
    func_8008ECE4(rdram, ctx);
        goto after_24;
    // 0x8001B5BC: addiu       $a0, $a0, -0x28AC
    ctx->r4 = ADD32(ctx->r4, -0X28AC);
    after_24:
    // 0x8001B5C0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8001B5C4: nop

    // 0x8001B5C8: lw          $t7, 0x14($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X14);
    // 0x8001B5CC: nop

    // 0x8001B5D0: beq         $t7, $zero, L_8001B5F4
    if (ctx->r15 == 0) {
        // 0x8001B5D4: nop
    
            goto L_8001B5F4;
    }
    // 0x8001B5D4: nop

    // 0x8001B5D8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8001B5DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B5E0: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8001B5E4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8001B5E8: jalr        $t9
    // 0x8001B5EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_25;
    // 0x8001B5EC: nop

    after_25:
    // 0x8001B5F0: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
L_8001B5F4:
    // 0x8001B5F4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8001B5F8: nop

    // 0x8001B5FC: beq         $t6, $zero, L_8001B62C
    if (ctx->r14 == 0) {
        // 0x8001B600: nop
    
            goto L_8001B62C;
    }
    // 0x8001B600: nop

    // 0x8001B604: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8001B608: nop

    // 0x8001B60C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8001B610: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8001B614: nop

    // 0x8001B618: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x8001B61C: nop

    // 0x8001B620: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x8001B624: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B628: sw          $zero, 0x25E4($at)
    MEM_W(0X25E4, ctx->r1) = 0;
L_8001B62C:
    // 0x8001B62C: b           L_8001B678
    // 0x8001B630: nop

        goto L_8001B678;
    // 0x8001B630: nop

L_8001B634:
    // 0x8001B634: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8001B638: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B63C: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x8001B640: jal         0x8008ECE4
    // 0x8001B644: addiu       $a0, $a0, -0x28A8
    ctx->r4 = ADD32(ctx->r4, -0X28A8);
    func_8008ECE4(rdram, ctx);
        goto after_26;
    // 0x8001B644: addiu       $a0, $a0, -0x28A8
    ctx->r4 = ADD32(ctx->r4, -0X28A8);
    after_26:
    // 0x8001B648: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8001B64C: nop

    // 0x8001B650: lw          $t8, 0x14($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X14);
    // 0x8001B654: nop

    // 0x8001B658: beq         $t8, $zero, L_8001B678
    if (ctx->r24 == 0) {
        // 0x8001B65C: nop
    
            goto L_8001B678;
    }
    // 0x8001B65C: nop

    // 0x8001B660: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8001B664: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8001B668: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x8001B66C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001B670: jalr        $t9
    // 0x8001B674: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_27;
    // 0x8001B674: nop

    after_27:
L_8001B678:
    // 0x8001B678: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8001B67C: nop

    // 0x8001B680: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001B684: b           L_8001B6A0
    // 0x8001B688: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
        goto L_8001B6A0;
    // 0x8001B688: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
L_8001B68C:
    // 0x8001B68C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8001B690: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B694: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x8001B698: jal         0x8008ECE4
    // 0x8001B69C: addiu       $a0, $a0, -0x28A4
    ctx->r4 = ADD32(ctx->r4, -0X28A4);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x8001B69C: addiu       $a0, $a0, -0x28A4
    ctx->r4 = ADD32(ctx->r4, -0X28A4);
    after_28:
L_8001B6A0:
    // 0x8001B6A0: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x8001B6A4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8001B6A8: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8001B6AC: addiu       $t4, $t3, 0x28
    ctx->r12 = ADD32(ctx->r11, 0X28);
    // 0x8001B6B0: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x8001B6B4: b           L_8001B4F8
    // 0x8001B6B8: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
        goto L_8001B4F8;
    // 0x8001B6B8: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
L_8001B6BC:
    // 0x8001B6BC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001B6C0: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001B6C4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001B6C8: lhu         $t9, 0xE68($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE68);
    // 0x8001B6CC: lhu         $t7, 0x8($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X8);
    // 0x8001B6D0: nop

    // 0x8001B6D4: and         $t5, $t7, $t9
    ctx->r13 = ctx->r15 & ctx->r25;
    // 0x8001B6D8: beq         $t5, $zero, L_8001B6F0
    if (ctx->r13 == 0) {
        // 0x8001B6DC: nop
    
            goto L_8001B6F0;
    }
    // 0x8001B6DC: nop

    // 0x8001B6E0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B6E4: nop

    // 0x8001B6E8: addiu       $t0, $t6, -0x1
    ctx->r8 = ADD32(ctx->r14, -0X1);
    // 0x8001B6EC: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
L_8001B6F0:
    // 0x8001B6F0: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001B6F4: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001B6F8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001B6FC: lhu         $t3, 0xE74($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE74);
    // 0x8001B700: lhu         $t1, 0x8($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X8);
    // 0x8001B704: nop

    // 0x8001B708: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x8001B70C: beq         $t4, $zero, L_8001B724
    if (ctx->r12 == 0) {
        // 0x8001B710: nop
    
            goto L_8001B724;
    }
    // 0x8001B710: nop

    // 0x8001B714: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B718: nop

    // 0x8001B71C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001B720: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
L_8001B724:
    // 0x8001B724: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B728: nop

    // 0x8001B72C: bgez        $t9, L_8001B744
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001B730: nop
    
            goto L_8001B744;
    }
    // 0x8001B730: nop

    // 0x8001B734: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8001B738: nop

    // 0x8001B73C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8001B740: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_8001B744:
    // 0x8001B744: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B748: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8001B74C: nop

    // 0x8001B750: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001B754: bne         $at, $zero, L_8001B760
    if (ctx->r1 != 0) {
        // 0x8001B758: nop
    
            goto L_8001B760;
    }
    // 0x8001B758: nop

    // 0x8001B75C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
L_8001B760:
    // 0x8001B760: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8001B764: nop

    // 0x8001B768: beq         $t1, $zero, L_8001B950
    if (ctx->r9 == 0) {
        // 0x8001B76C: nop
    
            goto L_8001B950;
    }
    // 0x8001B76C: nop

    // 0x8001B770: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001B774: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001B778: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001B77C: nop

    // 0x8001B780: andi        $t8, $t4, 0x4
    ctx->r24 = ctx->r12 & 0X4;
    // 0x8001B784: beq         $t8, $zero, L_8001B830
    if (ctx->r24 == 0) {
        // 0x8001B788: nop
    
            goto L_8001B830;
    }
    // 0x8001B788: nop

    // 0x8001B78C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B790: jal         0x8008EAA8
    // 0x8001B794: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8008EAA8(rdram, ctx);
        goto after_29;
    // 0x8001B794: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_29:
    // 0x8001B798: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001B79C: lw          $t7, 0x251C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X251C);
    // 0x8001B7A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001B7A4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001B7A8: lwc1        $f6, -0x249C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X249C);
    // 0x8001B7AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001B7B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001B7B4: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x8001B7B8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001B7BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B7C0: addiu       $a0, $a0, -0x28A0
    ctx->r4 = ADD32(ctx->r4, -0X28A0);
    // 0x8001B7C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8001B7C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001B7CC: nop

    // 0x8001B7D0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001B7D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001B7D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001B7DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B7E0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001B7E4: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001B7E8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001B7EC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001B7F0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001B7F4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8001B7F8: mfc1        $a2, $f19
    ctx->r6 = (int32_t)ctx->f_odd[(19 - 1) * 2];
    // 0x8001B7FC: jal         0x8008ECE4
    // 0x8001B800: nop

    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x8001B800: nop

    after_30:
    // 0x8001B804: jal         0x800BCEBC
    // 0x8001B808: nop

    SysMem_GetFreeSpace(rdram, ctx);
        goto after_31;
    // 0x8001B808: nop

    after_31:
    // 0x8001B80C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001B810: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B814: lui         $a2, 0x1B
    ctx->r6 = S32(0X1B << 16);
    // 0x8001B818: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x8001B81C: addiu       $a0, $a0, -0x2880
    ctx->r4 = ADD32(ctx->r4, -0X2880);
    // 0x8001B820: jal         0x8008ECE4
    // 0x8001B824: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8008ECE4(rdram, ctx);
        goto after_32;
    // 0x8001B824: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_32:
    // 0x8001B828: b           L_8001B8FC
    // 0x8001B82C: nop

        goto L_8001B8FC;
    // 0x8001B82C: nop

L_8001B830:
    // 0x8001B830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B834: jal         0x8008EAA8
    // 0x8001B838: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_33;
    // 0x8001B838: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_33:
    // 0x8001B83C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8001B840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B844: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B848: nop

    // 0x8001B84C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8001B850: nop

    // 0x8001B854: bc1f        L_8001B87C
    if (!c1cs) {
        // 0x8001B858: nop
    
            goto L_8001B87C;
    }
    // 0x8001B858: nop

    // 0x8001B85C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B860: jal         0x8008ECE4
    // 0x8001B864: addiu       $a0, $a0, -0x2860
    ctx->r4 = ADD32(ctx->r4, -0X2860);
    func_8008ECE4(rdram, ctx);
        goto after_34;
    // 0x8001B864: addiu       $a0, $a0, -0x2860
    ctx->r4 = ADD32(ctx->r4, -0X2860);
    after_34:
    // 0x8001B868: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B86C: jal         0x8008ECE4
    // 0x8001B870: addiu       $a0, $a0, -0x2838
    ctx->r4 = ADD32(ctx->r4, -0X2838);
    func_8008ECE4(rdram, ctx);
        goto after_35;
    // 0x8001B870: addiu       $a0, $a0, -0x2838
    ctx->r4 = ADD32(ctx->r4, -0X2838);
    after_35:
    // 0x8001B874: b           L_8001B8C8
    // 0x8001B878: nop

        goto L_8001B8C8;
    // 0x8001B878: nop

L_8001B87C:
    // 0x8001B87C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8001B880: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001B884: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B888: nop

    // 0x8001B88C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8001B890: nop

    // 0x8001B894: bc1f        L_8001B8BC
    if (!c1cs) {
        // 0x8001B898: nop
    
            goto L_8001B8BC;
    }
    // 0x8001B898: nop

    // 0x8001B89C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B8A0: jal         0x8008ECE4
    // 0x8001B8A4: addiu       $a0, $a0, -0x2810
    ctx->r4 = ADD32(ctx->r4, -0X2810);
    func_8008ECE4(rdram, ctx);
        goto after_36;
    // 0x8001B8A4: addiu       $a0, $a0, -0x2810
    ctx->r4 = ADD32(ctx->r4, -0X2810);
    after_36:
    // 0x8001B8A8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B8AC: jal         0x8008ECE4
    // 0x8001B8B0: addiu       $a0, $a0, -0x27E8
    ctx->r4 = ADD32(ctx->r4, -0X27E8);
    func_8008ECE4(rdram, ctx);
        goto after_37;
    // 0x8001B8B0: addiu       $a0, $a0, -0x27E8
    ctx->r4 = ADD32(ctx->r4, -0X27E8);
    after_37:
    // 0x8001B8B4: b           L_8001B8C8
    // 0x8001B8B8: nop

        goto L_8001B8C8;
    // 0x8001B8B8: nop

L_8001B8BC:
    // 0x8001B8BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001B8C0: nop

    // 0x8001B8C4: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
L_8001B8C8:
    // 0x8001B8C8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001B8CC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001B8D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B8D4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001B8D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001B8DC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001B8E0: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8001B8E4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B8E8: nop

    // 0x8001B8EC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001B8F0: add.d       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f16.d + ctx->f8.d;
    // 0x8001B8F4: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8001B8F8: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
L_8001B8FC:
    // 0x8001B8FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B900: lw          $t6, 0x4CA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4CA4);
    // 0x8001B904: nop

    // 0x8001B908: beq         $t6, $zero, L_8001B928
    if (ctx->r14 == 0) {
        // 0x8001B90C: nop
    
            goto L_8001B928;
    }
    // 0x8001B90C: nop

    // 0x8001B910: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8001B914: jal         0x8008EAA8
    // 0x8001B918: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_38;
    // 0x8001B918: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_38:
    // 0x8001B91C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B920: jal         0x8008ECE4
    // 0x8001B924: addiu       $a0, $a0, -0x27C0
    ctx->r4 = ADD32(ctx->r4, -0X27C0);
    func_8008ECE4(rdram, ctx);
        goto after_39;
    // 0x8001B924: addiu       $a0, $a0, -0x27C0
    ctx->r4 = ADD32(ctx->r4, -0X27C0);
    after_39:
L_8001B928:
    // 0x8001B928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B92C: jal         0x8008EAA8
    // 0x8001B930: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_40;
    // 0x8001B930: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_40:
    // 0x8001B934: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B938: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8001B93C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8001B940: addiu       $a2, $a2, -0x2788
    ctx->r6 = ADD32(ctx->r6, -0X2788);
    // 0x8001B944: addiu       $a1, $a1, -0x2794
    ctx->r5 = ADD32(ctx->r5, -0X2794);
    // 0x8001B948: jal         0x8008ECE4
    // 0x8001B94C: addiu       $a0, $a0, -0x27AC
    ctx->r4 = ADD32(ctx->r4, -0X27AC);
    func_8008ECE4(rdram, ctx);
        goto after_41;
    // 0x8001B94C: addiu       $a0, $a0, -0x27AC
    ctx->r4 = ADD32(ctx->r4, -0X27AC);
    after_41:
L_8001B950:
    // 0x8001B950: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8001B954: nop

    // 0x8001B958: beq         $t0, $zero, L_8001B96C
    if (ctx->r8 == 0) {
        // 0x8001B95C: nop
    
            goto L_8001B96C;
    }
    // 0x8001B95C: nop

    // 0x8001B960: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B964: jal         0x8001C1F4
    // 0x8001B968: nop

    func_8001C1F4(rdram, ctx);
        goto after_42;
    // 0x8001B968: nop

    after_42:
L_8001B96C:
    // 0x8001B96C: b           L_8001BA44
    // 0x8001B970: nop

        goto L_8001BA44;
    // 0x8001B970: nop

L_8001B974:
    // 0x8001B974: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B978: nop

    // 0x8001B97C: lw          $t1, 0x138($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X138);
    // 0x8001B980: nop

    // 0x8001B984: sh          $zero, 0x2($t1)
    MEM_H(0X2, ctx->r9) = 0;
    // 0x8001B988: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8001B98C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8001B990: jalr        $t9
    // 0x8001B994: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_43;
    // 0x8001B994: nop

    after_43:
    // 0x8001B998: bgez        $v0, L_8001B9B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001B99C: nop
    
            goto L_8001B9B0;
    }
    // 0x8001B99C: nop

    // 0x8001B9A0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8001B9A4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B9A8: jal         0x8001C1F4
    // 0x8001B9AC: nop

    func_8001C1F4(rdram, ctx);
        goto after_44;
    // 0x8001B9AC: nop

    after_44:
L_8001B9B0:
    // 0x8001B9B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001B9B4: lw          $t3, 0x25E4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X25E4);
    // 0x8001B9B8: nop

    // 0x8001B9BC: bne         $t3, $zero, L_8001B9D8
    if (ctx->r11 != 0) {
        // 0x8001B9C0: nop
    
            goto L_8001B9D8;
    }
    // 0x8001B9C0: nop

    // 0x8001B9C4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001B9C8: lw          $t4, 0x25E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X25E4);
    // 0x8001B9CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B9D0: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x8001B9D4: sw          $t8, 0x25E4($at)
    MEM_W(0X25E4, ctx->r1) = ctx->r24;
L_8001B9D8:
    // 0x8001B9D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B9DC: jal         0x8008EAA8
    // 0x8001B9E0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8008EAA8(rdram, ctx);
        goto after_45;
    // 0x8001B9E0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_45:
    // 0x8001B9E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001B9E8: lw          $t7, 0x251C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X251C);
    // 0x8001B9EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001B9F0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001B9F4: lwc1        $f16, -0x2498($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2498);
    // 0x8001B9F8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001B9FC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001BA00: addiu       $a0, $a0, -0x277C
    ctx->r4 = ADD32(ctx->r4, -0X277C);
    // 0x8001BA04: div.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001BA08: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8001BA0C: nop

    // 0x8001BA10: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8001BA14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001BA18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001BA1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001BA20: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001BA24: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001BA28: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8001BA2C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8001BA30: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8001BA34: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8001BA38: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8001BA3C: jal         0x8008ECE4
    // 0x8001BA40: nop

    func_8008ECE4(rdram, ctx);
        goto after_46;
    // 0x8001BA40: nop

    after_46:
L_8001BA44:
    // 0x8001BA44: jal         0x800967D8
    // 0x8001BA48: nop

    func_800967D8(rdram, ctx);
        goto after_47;
    // 0x8001BA48: nop

    after_47:
    // 0x8001BA4C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BA50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001BA54: nop

    // 0x8001BA58: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8001BA5C: nop

    // 0x8001BA60: bc1t        L_8001BA84
    if (c1cs) {
        // 0x8001BA64: nop
    
            goto L_8001BA84;
    }
    // 0x8001BA64: nop

    // 0x8001BA68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BA6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001BA70: nop

    // 0x8001BA74: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x8001BA78: nop

    // 0x8001BA7C: bc1f        L_8001BAB8
    if (!c1cs) {
        // 0x8001BA80: nop
    
            goto L_8001BAB8;
    }
    // 0x8001BA80: nop

L_8001BA84:
    // 0x8001BA84: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BA88: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8001BA8C: lw          $t0, 0xC0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC0);
    // 0x8001BA90: nop

    // 0x8001BA94: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8001BA98: sw          $t2, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r10;
    // 0x8001BA9C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BAA0: nop

    // 0x8001BAA4: lw          $t9, 0xC0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC0);
    // 0x8001BAA8: nop

    // 0x8001BAAC: ori         $t3, $t9, 0x8
    ctx->r11 = ctx->r25 | 0X8;
    // 0x8001BAB0: b           L_8001BB34
    // 0x8001BAB4: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
        goto L_8001BB34;
    // 0x8001BAB4: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
L_8001BAB8:
    // 0x8001BAB8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001BABC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001BAC0: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x8001BAC4: nop

    // 0x8001BAC8: andi        $t7, $t8, 0x4
    ctx->r15 = ctx->r24 & 0X4;
    // 0x8001BACC: beq         $t7, $zero, L_8001BB04
    if (ctx->r15 == 0) {
        // 0x8001BAD0: nop
    
            goto L_8001BB04;
    }
    // 0x8001BAD0: nop

    // 0x8001BAD4: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001BAD8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001BADC: lw          $t0, 0xC0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC0);
    // 0x8001BAE0: nop

    // 0x8001BAE4: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8001BAE8: sw          $t2, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r10;
    // 0x8001BAEC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001BAF0: nop

    // 0x8001BAF4: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x8001BAF8: nop

    // 0x8001BAFC: ori         $t3, $t9, 0x10
    ctx->r11 = ctx->r25 | 0X10;
    // 0x8001BB00: sw          $t3, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r11;
L_8001BB04:
    // 0x8001BB04: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BB08: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001BB0C: lw          $t4, 0xC0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC0);
    // 0x8001BB10: nop

    // 0x8001BB14: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x8001BB18: sw          $t8, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r24;
    // 0x8001BB1C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BB20: nop

    // 0x8001BB24: lw          $t0, 0xC0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC0);
    // 0x8001BB28: nop

    // 0x8001BB2C: ori         $t2, $t0, 0x10
    ctx->r10 = ctx->r8 | 0X10;
    // 0x8001BB30: sw          $t2, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r10;
L_8001BB34:
    // 0x8001BB34: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8001BB38: nop

    // 0x8001BB3C: bne         $t5, $zero, L_8001BBA0
    if (ctx->r13 != 0) {
        // 0x8001BB40: nop
    
            goto L_8001BBA0;
    }
    // 0x8001BB40: nop

    // 0x8001BB44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BB48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001BB4C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BB50: nop

    // 0x8001BB54: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8001BB58: nop

    // 0x8001BB5C: bc1f        L_8001BB88
    if (!c1cs) {
        // 0x8001BB60: nop
    
            goto L_8001BB88;
    }
    // 0x8001BB60: nop

    // 0x8001BB64: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BB68: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8001BB6C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001BB70: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001BB74: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8001BB78: add.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f16.d + ctx->f10.d;
    // 0x8001BB7C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8001BB80: b           L_8001BB98
    // 0x8001BB84: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
        goto L_8001BB98;
    // 0x8001BB84: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_8001BB88:
    // 0x8001BB88: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BB8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001BB90: nop

    // 0x8001BB94: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
L_8001BB98:
    // 0x8001BB98: b           L_8001BC0C
    // 0x8001BB9C: nop

        goto L_8001BC0C;
    // 0x8001BB9C: nop

L_8001BBA0:
    // 0x8001BBA0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BBA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001BBA8: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BBAC: nop

    // 0x8001BBB0: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x8001BBB4: nop

    // 0x8001BBB8: bc1f        L_8001BC00
    if (!c1cs) {
        // 0x8001BBBC: nop
    
            goto L_8001BC00;
    }
    // 0x8001BBBC: nop

    // 0x8001BBC0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8001BBC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001BBC8: nop

    // 0x8001BBCC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8001BBD0: nop

    // 0x8001BBD4: bc1f        L_8001BC00
    if (!c1cs) {
        // 0x8001BBD8: nop
    
            goto L_8001BC00;
    }
    // 0x8001BBD8: nop

    // 0x8001BBDC: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BBE0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8001BBE4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001BBE8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001BBEC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8001BBF0: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x8001BBF4: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8001BBF8: b           L_8001BC0C
    // 0x8001BBFC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_8001BC0C;
    // 0x8001BBFC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8001BC00:
    // 0x8001BC00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001BC04: nop

    // 0x8001BC08: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_8001BC0C:
    // 0x8001BC0C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001BC10: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8001BC14: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x8001BC18: nop

    // 0x8001BC1C: andi        $t6, $t3, 0x4
    ctx->r14 = ctx->r11 & 0X4;
    // 0x8001BC20: beq         $t6, $zero, L_8001BC94
    if (ctx->r14 == 0) {
        // 0x8001BC24: nop
    
            goto L_8001BC94;
    }
    // 0x8001BC24: nop

    // 0x8001BC28: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BC2C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC30: nop

    // 0x8001BC34: swc1        $f8, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f8.u32l;
    // 0x8001BC38: jal         0x800C1754
    // 0x8001BC3C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_48;
    // 0x8001BC3C: nop

    after_48:
    // 0x8001BC40: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC44: jal         0x8009A14C
    // 0x8001BC48: nop

    func_8009A14C(rdram, ctx);
        goto after_49;
    // 0x8001BC48: nop

    after_49:
    // 0x8001BC4C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC50: nop

    // 0x8001BC54: lwc1        $f12, 0xF0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8001BC58: jal         0x800C2780
    // 0x8001BC5C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_50;
    // 0x8001BC5C: nop

    after_50:
    // 0x8001BC60: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC64: nop

    // 0x8001BC68: lwc1        $f12, 0xEC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XEC);
    // 0x8001BC6C: jal         0x800C25B8
    // 0x8001BC70: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_51;
    // 0x8001BC70: nop

    after_51:
    // 0x8001BC74: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC78: nop

    // 0x8001BC7C: lwc1        $f12, 0xE8($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8001BC80: jal         0x800C23E8
    // 0x8001BC84: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_52;
    // 0x8001BC84: nop

    after_52:
    // 0x8001BC88: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC8C: jal         0x800997D8
    // 0x8001BC90: nop

    func_800997D8(rdram, ctx);
        goto after_53;
    // 0x8001BC90: nop

    after_53:
L_8001BC94:
    // 0x8001BC94: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BC98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001BC9C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BCA0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCA4: sub.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8001BCA8: swc1        $f16, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f16.u32l;
    // 0x8001BCAC: jal         0x800C1850
    // 0x8001BCB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_54;
    // 0x8001BCB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x8001BCB4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCB8: jal         0x8009A14C
    // 0x8001BCBC: nop

    func_8009A14C(rdram, ctx);
        goto after_55;
    // 0x8001BCBC: nop

    after_55:
    // 0x8001BCC0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCC4: nop

    // 0x8001BCC8: lwc1        $f12, 0xF0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XF0);
    // 0x8001BCCC: jal         0x800C2780
    // 0x8001BCD0: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_56;
    // 0x8001BCD0: nop

    after_56:
    // 0x8001BCD4: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCD8: nop

    // 0x8001BCDC: lwc1        $f12, 0xEC($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x8001BCE0: jal         0x800C25B8
    // 0x8001BCE4: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_57;
    // 0x8001BCE4: nop

    after_57:
    // 0x8001BCE8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCEC: nop

    // 0x8001BCF0: lwc1        $f12, 0xE8($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0XE8);
    // 0x8001BCF4: jal         0x800C23E8
    // 0x8001BCF8: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_58;
    // 0x8001BCF8: nop

    after_58:
    // 0x8001BCFC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BD00: jal         0x800997D8
    // 0x8001BD04: nop

    func_800997D8(rdram, ctx);
        goto after_59;
    // 0x8001BD04: nop

    after_59:
    // 0x8001BD08: jal         0x800C1A28
    // 0x8001BD0C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_60;
    // 0x8001BD0C: nop

    after_60:
    // 0x8001BD10: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8001BD14: jal         0x8009A664
    // 0x8001BD18: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_61;
    // 0x8001BD18: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_61:
    // 0x8001BD1C: jal         0x800BE610
    // 0x8001BD20: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_62;
    // 0x8001BD20: nop

    after_62:
    // 0x8001BD24: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001BD28: lw          $t3, 0x1B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B4C);
    // 0x8001BD2C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8001BD30: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x8001BD34: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8001BD38: jal         0x8009908C
    // 0x8001BD3C: subu        $a1, $t6, $t3
    ctx->r5 = SUB32(ctx->r14, ctx->r11);
    CreateGfxTask(rdram, ctx);
        goto after_63;
    // 0x8001BD3C: subu        $a1, $t6, $t3
    ctx->r5 = SUB32(ctx->r14, ctx->r11);
    after_63:
    // 0x8001BD40: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BD44: nop

    // 0x8001BD48: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x8001BD4C: jal         0x80098D24
    // 0x8001BD50: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_64;
    // 0x8001BD50: nop

    after_64:
    // 0x8001BD54: jal         0x80099450
    // 0x8001BD58: nop

    func_80099450(rdram, ctx);
        goto after_65;
    // 0x8001BD58: nop

    after_65:
    // 0x8001BD5C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8001BD60: nop

    // 0x8001BD64: addiu       $t1, $t8, 0x7FFF
    ctx->r9 = ADD32(ctx->r24, 0X7FFF);
    // 0x8001BD68: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8001BD6C: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x8001BD70: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8001BD74: sw          $t0, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r8;
L_8001BD78:
    // 0x8001BD78: b           L_8001C034
    // 0x8001BD7C: nop

        goto L_8001C034;
    // 0x8001BD7C: nop

L_8001BD80:
    // 0x8001BD80: jal         0x80099520
    // 0x8001BD84: nop

    func_80099520(rdram, ctx);
        goto after_66;
    // 0x8001BD84: nop

    after_66:
    // 0x8001BD88: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8001BD8C: nop

    // 0x8001BD90: addiu       $t7, $t2, 0x7FFF
    ctx->r15 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BD94: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x8001BD98: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BD9C: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x8001BDA0: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x8001BDA4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001BDA8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001BDAC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001BDB0: lhu         $t3, 0x1038($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1038);
    // 0x8001BDB4: lhu         $t6, 0x6($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X6);
    // 0x8001BDB8: nop

    // 0x8001BDBC: and         $t4, $t6, $t3
    ctx->r12 = ctx->r14 & ctx->r11;
    // 0x8001BDC0: beq         $t4, $zero, L_8001BE38
    if (ctx->r12 == 0) {
        // 0x8001BDC4: nop
    
            goto L_8001BE38;
    }
    // 0x8001BDC4: nop

    // 0x8001BDC8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8001BDCC: nop

    // 0x8001BDD0: bne         $t1, $zero, L_8001BE38
    if (ctx->r9 != 0) {
        // 0x8001BDD4: nop
    
            goto L_8001BE38;
    }
    // 0x8001BDD4: nop

    // 0x8001BDD8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8001BDDC: nop

    // 0x8001BDE0: bne         $t0, $zero, L_8001BE38
    if (ctx->r8 != 0) {
        // 0x8001BDE4: nop
    
            goto L_8001BE38;
    }
    // 0x8001BDE4: nop

    // 0x8001BDE8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BDEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001BDF0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BDF4: nop

    // 0x8001BDF8: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x8001BDFC: nop

    // 0x8001BE00: bc1f        L_8001BE38
    if (!c1cs) {
        // 0x8001BE04: nop
    
            goto L_8001BE38;
    }
    // 0x8001BE04: nop

    // 0x8001BE08: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8001BE0C: nop

    // 0x8001BE10: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001BE14: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8001BE18: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BE1C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8001BE20: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001BE24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001BE28: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8001BE2C: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x8001BE30: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8001BE34: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8001BE38:
    // 0x8001BE38: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8001BE3C: nop

    // 0x8001BE40: beq         $t5, $zero, L_8001BF10
    if (ctx->r13 == 0) {
        // 0x8001BE44: nop
    
            goto L_8001BF10;
    }
    // 0x8001BE44: nop

    // 0x8001BE48: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BE4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001BE50: nop

    // 0x8001BE54: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x8001BE58: nop

    // 0x8001BE5C: bc1t        L_8001BE80
    if (c1cs) {
        // 0x8001BE60: nop
    
            goto L_8001BE80;
    }
    // 0x8001BE60: nop

    // 0x8001BE64: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BE68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001BE6C: nop

    // 0x8001BE70: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x8001BE74: nop

    // 0x8001BE78: bc1f        L_8001BF10
    if (!c1cs) {
        // 0x8001BE7C: nop
    
            goto L_8001BF10;
    }
    // 0x8001BE7C: nop

L_8001BE80:
    // 0x8001BE80: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001BE84: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8001BE88: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x8001BE8C: nop

    // 0x8001BE90: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x8001BE94: beq         $t6, $zero, L_8001BEFC
    if (ctx->r14 == 0) {
        // 0x8001BE98: nop
    
            goto L_8001BEFC;
    }
    // 0x8001BE98: nop

    // 0x8001BE9C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEA0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8001BEA4: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x8001BEA8: nop

    // 0x8001BEAC: and         $t1, $t4, $at
    ctx->r9 = ctx->r12 & ctx->r1;
    // 0x8001BEB0: sw          $t1, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r9;
    // 0x8001BEB4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEB8: nop

    // 0x8001BEBC: lw          $t8, 0xC0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC0);
    // 0x8001BEC0: nop

    // 0x8001BEC4: ori         $t7, $t8, 0x8
    ctx->r15 = ctx->r24 | 0X8;
    // 0x8001BEC8: sw          $t7, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r15;
    // 0x8001BECC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001BED0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001BED4: nop

    // 0x8001BED8: swc1        $f18, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f18.u32l;
    // 0x8001BEDC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEE0: nop

    // 0x8001BEE4: lwc1        $f20, 0xF0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x8001BEE8: nop

    // 0x8001BEEC: swc1        $f20, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f20.u32l;
    // 0x8001BEF0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEF4: nop

    // 0x8001BEF8: swc1        $f20, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f20.u32l;
L_8001BEFC:
    // 0x8001BEFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001BF00: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x8001BF04: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BF08: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001BF0C: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
L_8001BF10:
    // 0x8001BF10: b           L_8001C034
    // 0x8001BF14: nop

        goto L_8001C034;
    // 0x8001BF14: nop

L_8001BF18:
    // 0x8001BF18: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8001BF1C: nop

    // 0x8001BF20: addiu       $t8, $t3, 0x7FFF
    ctx->r24 = ADD32(ctx->r11, 0X7FFF);
    // 0x8001BF24: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x8001BF28: nop

    // 0x8001BF2C: blez        $t8, L_8001BFB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001BF30: nop
    
            goto L_8001BFB0;
    }
    // 0x8001BF30: nop

L_8001BF34:
    // 0x8001BF34: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BF38: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8001BF3C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8001BF40: jal         0x800C143C
    // 0x8001BF44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_67;
    // 0x8001BF44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_67:
    // 0x8001BF48: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8001BF4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001BF50: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x8001BF54: nop

    // 0x8001BF58: bne         $t5, $at, L_8001BF94
    if (ctx->r13 != ctx->r1) {
        // 0x8001BF5C: nop
    
            goto L_8001BF94;
    }
    // 0x8001BF5C: nop

    // 0x8001BF60: b           L_8001BF68
    // 0x8001BF64: nop

        goto L_8001BF68;
    // 0x8001BF64: nop

L_8001BF68:
    // 0x8001BF68: jal         0x80099520
    // 0x8001BF6C: nop

    func_80099520(rdram, ctx);
        goto after_68;
    // 0x8001BF6C: nop

    after_68:
    // 0x8001BF70: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8001BF74: nop

    // 0x8001BF78: addiu       $t9, $t2, 0x7FFF
    ctx->r25 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BF7C: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x8001BF80: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BF84: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8001BF88: sw          $t6, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r14;
    // 0x8001BF8C: b           L_8001BF94
    // 0x8001BF90: nop

        goto L_8001BF94;
    // 0x8001BF90: nop

L_8001BF94:
    // 0x8001BF94: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8001BF98: nop

    // 0x8001BF9C: addiu       $t1, $t4, 0x7FFF
    ctx->r9 = ADD32(ctx->r12, 0X7FFF);
    // 0x8001BFA0: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8001BFA4: nop

    // 0x8001BFA8: bgtz        $t1, L_8001BF34
    if (SIGNED(ctx->r9) > 0) {
        // 0x8001BFAC: nop
    
            goto L_8001BF34;
    }
    // 0x8001BFAC: nop

L_8001BFB0:
    // 0x8001BFB0: jal         0x80098820
    // 0x8001BFB4: nop

    func_80098820(rdram, ctx);
        goto after_69;
    // 0x8001BFB4: nop

    after_69:
    // 0x8001BFB8: jal         0x80098868
    // 0x8001BFBC: nop

    func_80098868(rdram, ctx);
        goto after_70;
    // 0x8001BFBC: nop

    after_70:
    // 0x8001BFC0: jal         0x80005460
    // 0x8001BFC4: nop

    func_80005460(rdram, ctx);
        goto after_71;
    // 0x8001BFC4: nop

    after_71:
    // 0x8001BFC8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001BFCC: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001BFD0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8001BFD4: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x8001BFD8: jal         0x80005124
    // 0x8001BFDC: nop

    func_80005124(rdram, ctx);
        goto after_72;
    // 0x8001BFDC: nop

    after_72:
    // 0x8001BFE0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8001BFE4: nop

    // 0x8001BFE8: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x8001BFEC: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x8001BFF0: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BFF4: nop

    // 0x8001BFF8: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8001BFFC: jal         0x800C13B8
    // 0x8001C000: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_73;
    // 0x8001C000: nop

    after_73:
    // 0x8001C004: jal         0x80098820
    // 0x8001C008: nop

    func_80098820(rdram, ctx);
        goto after_74;
    // 0x8001C008: nop

    after_74:
    // 0x8001C00C: b           L_8001C034
    // 0x8001C010: nop

        goto L_8001C034;
    // 0x8001C010: nop

L_8001C014:
    // 0x8001C014: jal         0x800029BC
    // 0x8001C018: nop

    func_800029BC(rdram, ctx);
        goto after_75;
    // 0x8001C018: nop

    after_75:
L_8001C01C:
    // 0x8001C01C: b           L_8001C01C
    pause_self(rdram);
    // 0x8001C020: nop

    // 0x8001C024: b           L_8001C034
    // 0x8001C028: nop

        goto L_8001C034;
    // 0x8001C028: nop

L_8001C02C:
    // 0x8001C02C: b           L_8001C034
    // 0x8001C030: nop

        goto L_8001C034;
    // 0x8001C030: nop

L_8001C034:
    // 0x8001C034: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8001C038: nop

    // 0x8001C03C: beq         $t0, $zero, L_8001B354
    if (ctx->r8 == 0) {
        // 0x8001C040: nop
    
            goto L_8001B354;
    }
    // 0x8001C040: nop

L_8001C044:
    // 0x8001C044: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001C048: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x8001C04C: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x8001C050: nop

    // 0x8001C054: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x8001C058: bne         $t6, $zero, L_8001C108
    if (ctx->r14 != 0) {
        // 0x8001C05C: nop
    
            goto L_8001C108;
    }
    // 0x8001C05C: nop

    // 0x8001C060: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8001C064: nop

    // 0x8001C068: addiu       $t4, $t2, 0x7FFF
    ctx->r12 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001C06C: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x8001C070: nop

    // 0x8001C074: blez        $t4, L_8001C0F8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8001C078: nop
    
            goto L_8001C0F8;
    }
    // 0x8001C078: nop

L_8001C07C:
    // 0x8001C07C: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8001C080: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8001C084: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x8001C088: jal         0x800C143C
    // 0x8001C08C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_76;
    // 0x8001C08C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_76:
    // 0x8001C090: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8001C094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C098: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8001C09C: nop

    // 0x8001C0A0: bne         $t8, $at, L_8001C0DC
    if (ctx->r24 != ctx->r1) {
        // 0x8001C0A4: nop
    
            goto L_8001C0DC;
    }
    // 0x8001C0A4: nop

    // 0x8001C0A8: b           L_8001C0B0
    // 0x8001C0AC: nop

        goto L_8001C0B0;
    // 0x8001C0AC: nop

L_8001C0B0:
    // 0x8001C0B0: jal         0x80099520
    // 0x8001C0B4: nop

    func_80099520(rdram, ctx);
        goto after_77;
    // 0x8001C0B4: nop

    after_77:
    // 0x8001C0B8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8001C0BC: nop

    // 0x8001C0C0: addiu       $t0, $t7, 0x7FFF
    ctx->r8 = ADD32(ctx->r15, 0X7FFF);
    // 0x8001C0C4: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x8001C0C8: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x8001C0CC: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x8001C0D0: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x8001C0D4: b           L_8001C0DC
    // 0x8001C0D8: nop

        goto L_8001C0DC;
    // 0x8001C0D8: nop

L_8001C0DC:
    // 0x8001C0DC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8001C0E0: nop

    // 0x8001C0E4: addiu       $t6, $t9, 0x7FFF
    ctx->r14 = ADD32(ctx->r25, 0X7FFF);
    // 0x8001C0E8: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x8001C0EC: nop

    // 0x8001C0F0: bgtz        $t6, L_8001C07C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8001C0F4: nop
    
            goto L_8001C07C;
    }
    // 0x8001C0F4: nop

L_8001C0F8:
    // 0x8001C0F8: jal         0x80098820
    // 0x8001C0FC: nop

    func_80098820(rdram, ctx);
        goto after_78;
    // 0x8001C0FC: nop

    after_78:
    // 0x8001C100: jal         0x80098868
    // 0x8001C104: nop

    func_80098868(rdram, ctx);
        goto after_79;
    // 0x8001C104: nop

    after_79:
L_8001C108:
    // 0x8001C108: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001C10C: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001C110: jal         0x800A6670
    // 0x8001C114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_80;
    // 0x8001C114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_80:
    // 0x8001C118: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001C11C: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001C120: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8001C124: jal         0x800A6670
    // 0x8001C128: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_81;
    // 0x8001C128: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_81:
    // 0x8001C12C: jal         0x80005460
    // 0x8001C130: nop

    func_80005460(rdram, ctx);
        goto after_82;
    // 0x8001C130: nop

    after_82:
    // 0x8001C134: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8001C138: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8001C13C: jal         0x800A6670
    // 0x8001C140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_83;
    // 0x8001C140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_83:
    // 0x8001C144: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8001C148: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8001C14C: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8001C150: jal         0x800A6670
    // 0x8001C154: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_84;
    // 0x8001C154: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_84:
    // 0x8001C158: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001C15C: lw          $a0, -0x4D48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D48);
    // 0x8001C160: jal         0x800BC980
    // 0x8001C164: nop

    SysMem_Free(rdram, ctx);
        goto after_85;
    // 0x8001C164: nop

    after_85:
    // 0x8001C168: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001C16C: lw          $a0, -0x4D40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D40);
    // 0x8001C170: jal         0x800BC980
    // 0x8001C174: nop

    SysMem_Free(rdram, ctx);
        goto after_86;
    // 0x8001C174: nop

    after_86:
    // 0x8001C178: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001C17C: lw          $a0, -0x4D44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D44);
    // 0x8001C180: jal         0x800BC980
    // 0x8001C184: nop

    SysMem_Free(rdram, ctx);
        goto after_87;
    // 0x8001C184: nop

    after_87:
    // 0x8001C188: lhu         $t2, 0x56($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X56);
    // 0x8001C18C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8001C190: addiu       $t4, $t4, -0x44B8
    ctx->r12 = ADD32(ctx->r12, -0X44B8);
    // 0x8001C194: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
    // 0x8001C198: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C19C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001C1A0: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8001C1A4: nop

    // 0x8001C1A8: andi        $t8, $t3, 0x4
    ctx->r24 = ctx->r11 & 0X4;
    // 0x8001C1AC: bne         $t8, $zero, L_8001C1D4
    if (ctx->r24 != 0) {
        // 0x8001C1B0: nop
    
            goto L_8001C1D4;
    }
    // 0x8001C1B0: nop

    // 0x8001C1B4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8001C1B8: lh          $t0, 0x7320($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7320);
    // 0x8001C1BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C1C0: sh          $t0, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r8;
    // 0x8001C1C4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8001C1C8: lh          $t5, 0x7338($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7338);
    // 0x8001C1CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C1D0: sh          $t5, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r13;
L_8001C1D4:
    // 0x8001C1D4: b           L_8001C1DC
    // 0x8001C1D8: nop

        goto L_8001C1DC;
    // 0x8001C1D8: nop

L_8001C1DC:
    // 0x8001C1DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C1E0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001C1E4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C1E8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001C1EC: jr          $ra
    // 0x8001C1F0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8001C1F0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8006FEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FEA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FEAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FEB0: nop

    // 0x8006FEB4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006FEB8: nop

    // 0x8006FEBC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006FEC0: jr          $ra
    // 0x8006FEC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FEC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FEC8: jr          $ra
    // 0x8006FECC: nop

    return;
    // 0x8006FECC: nop

    // 0x8006FED0: jr          $ra
    // 0x8006FED4: nop

    return;
    // 0x8006FED4: nop

;}
RECOMP_FUNC void func_8002A0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A0F8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002A0FC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A100: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A104: bne         $a0, $zero, L_8002A144
    if (ctx->r4 != 0) {
        // 0x8002A108: nop
    
            goto L_8002A144;
    }
    // 0x8002A108: nop

    // 0x8002A10C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002A110: bne         $a1, $at, L_8002A128
    if (ctx->r5 != ctx->r1) {
        // 0x8002A114: nop
    
            goto L_8002A128;
    }
    // 0x8002A114: nop

    // 0x8002A118: b           L_8002A224
    // 0x8002A11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002A224;
    // 0x8002A11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A120: b           L_8002A13C
    // 0x8002A124: nop

        goto L_8002A13C;
    // 0x8002A124: nop

L_8002A128:
    // 0x8002A128: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002A12C: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x8002A130: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8002A134: nop

    // 0x8002A138: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_8002A13C:
    // 0x8002A13C: b           L_8002A150
    // 0x8002A140: nop

        goto L_8002A150;
    // 0x8002A140: nop

L_8002A144:
    // 0x8002A144: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8002A148: nop

    // 0x8002A14C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_8002A150:
    // 0x8002A150: sh          $zero, 0xA($sp)
    MEM_H(0XA, ctx->r29) = 0;
    // 0x8002A154: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8002A158: sh          $t9, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r25;
    // 0x8002A15C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8002A160: nop

    // 0x8002A164: beq         $t0, $zero, L_8002A210
    if (ctx->r8 == 0) {
        // 0x8002A168: nop
    
            goto L_8002A210;
    }
    // 0x8002A168: nop

L_8002A16C:
    // 0x8002A16C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8002A170: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002A174: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8002A178: nop

    // 0x8002A17C: bne         $t2, $at, L_8002A194
    if (ctx->r10 != ctx->r1) {
        // 0x8002A180: nop
    
            goto L_8002A194;
    }
    // 0x8002A180: nop

    // 0x8002A184: lh          $t3, 0x4($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X4);
    // 0x8002A188: nop

    // 0x8002A18C: beq         $t3, $zero, L_8002A19C
    if (ctx->r11 == 0) {
        // 0x8002A190: nop
    
            goto L_8002A19C;
    }
    // 0x8002A190: nop

L_8002A194:
    // 0x8002A194: b           L_8002A210
    // 0x8002A198: nop

        goto L_8002A210;
    // 0x8002A198: nop

L_8002A19C:
    // 0x8002A19C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8002A1A0: lh          $t6, 0xC($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XC);
    // 0x8002A1A4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8002A1A8: nop

    // 0x8002A1AC: beq         $t5, $t6, L_8002A1D0
    if (ctx->r13 == ctx->r14) {
        // 0x8002A1B0: sh          $t5, 0xE($sp)
        MEM_H(0XE, ctx->r29) = ctx->r13;
            goto L_8002A1D0;
    }
    // 0x8002A1B0: sh          $t5, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r13;
    // 0x8002A1B4: lh          $t7, 0xA($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XA);
    // 0x8002A1B8: nop

    // 0x8002A1BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002A1C0: sh          $t8, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r24;
    // 0x8002A1C4: lh          $t9, 0xE($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XE);
    // 0x8002A1C8: nop

    // 0x8002A1CC: sh          $t9, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r25;
L_8002A1D0:
    // 0x8002A1D0: beq         $a1, $zero, L_8002A1EC
    if (ctx->r5 == 0) {
        // 0x8002A1D4: nop
    
            goto L_8002A1EC;
    }
    // 0x8002A1D4: nop

    // 0x8002A1D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8002A1DC: nop

    // 0x8002A1E0: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
    // 0x8002A1E4: b           L_8002A200
    // 0x8002A1E8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
        goto L_8002A200;
    // 0x8002A1E8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
L_8002A1EC:
    // 0x8002A1EC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8002A1F0: nop

    // 0x8002A1F4: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8002A1F8: nop

    // 0x8002A1FC: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_8002A200:
    // 0x8002A200: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8002A204: nop

    // 0x8002A208: bne         $t4, $zero, L_8002A16C
    if (ctx->r12 != 0) {
        // 0x8002A20C: nop
    
            goto L_8002A16C;
    }
    // 0x8002A20C: nop

L_8002A210:
    // 0x8002A210: lh          $v0, 0xA($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XA);
    // 0x8002A214: b           L_8002A224
    // 0x8002A218: nop

        goto L_8002A224;
    // 0x8002A218: nop

    // 0x8002A21C: b           L_8002A224
    // 0x8002A220: nop

        goto L_8002A224;
    // 0x8002A220: nop

L_8002A224:
    // 0x8002A224: jr          $ra
    // 0x8002A228: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A228: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80068A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068A1C: jal         0x80061488
    // 0x80068A20: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068A20: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x80068A24: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068A28: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068A2C: b           L_80068A3C
    // 0x80068A30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068A3C;
    // 0x80068A30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068A34: b           L_80068A3C
    // 0x80068A38: nop

        goto L_80068A3C;
    // 0x80068A38: nop

L_80068A3C:
    // 0x80068A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068A44: jr          $ra
    // 0x80068A48: nop

    return;
    // 0x80068A48: nop

;}
RECOMP_FUNC void func_80015BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015BD0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80015BD4: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x80015BD8: nop

    // 0x80015BDC: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80015BE0: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80015BE4: nop

    // 0x80015BE8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80015BEC: nop

    // 0x80015BF0: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80015BF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015BF8: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80015BFC: nop

    // 0x80015C00: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x80015C04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015C08: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80015C0C: nop

    // 0x80015C10: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x80015C14: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x80015C18: nop

    // 0x80015C1C: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x80015C20: b           L_80015C28
    // 0x80015C24: nop

        goto L_80015C28;
    // 0x80015C24: nop

L_80015C28:
    // 0x80015C28: jr          $ra
    // 0x80015C2C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80015C2C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void __seqpStopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3610: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D3614: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D3618: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800D361C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800D3620: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D3624: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D3628: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D362C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D3630: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3634: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3638: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800D363C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800D3640: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800D3644: beq         $s0, $zero, L_800D36E8
    if (ctx->r16 == 0) {
        // 0x800D3648: addiu       $s7, $zero, 0x17
        ctx->r23 = ADD32(0, 0X17);
            goto L_800D36E8;
    }
    // 0x800D3648: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x800D364C: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_800D3650:
    // 0x800D3650: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x800D3654: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D3658: beql        $s3, $s6, L_800D366C
    if (ctx->r19 == ctx->r22) {
        // 0x800D365C: lw          $t6, 0x10($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X10);
            goto L_800D366C;
    }
    goto skip_0;
    // 0x800D365C: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x800D3660: bne         $s3, $s7, L_800D36E0
    if (ctx->r19 != ctx->r23) {
        // 0x800D3664: nop
    
            goto L_800D36E0;
    }
    // 0x800D3664: nop

    // 0x800D3668: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
L_800D366C:
    // 0x800D366C: bne         $s2, $t6, L_800D36E0
    if (ctx->r18 != ctx->r14) {
        // 0x800D3670: nop
    
            goto L_800D36E0;
    }
    // 0x800D3670: nop

    // 0x800D3674: lw          $t9, 0x78($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X78);
    // 0x800D3678: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x800D367C: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    // 0x800D3680: jalr        $t9
    // 0x800D3684: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D3684: nop

    after_0:
    // 0x800D3688: jal         0x800C7890
    // 0x800D368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3690: beq         $s1, $zero, L_800D36A8
    if (ctx->r17 == 0) {
        // 0x800D3694: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D36A8;
    }
    // 0x800D3694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3698: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800D369C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D36A0: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x800D36A4: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800D36A8:
    // 0x800D36A8: jal         0x800C78C0
    // 0x800D36AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800D36AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x800D36B0: bnel        $s3, $s6, L_800D36CC
    if (ctx->r19 != ctx->r22) {
        // 0x800D36B4: lbu         $t3, 0x37($s2)
        ctx->r11 = MEM_BU(ctx->r18, 0X37);
            goto L_800D36CC;
    }
    goto skip_1;
    // 0x800D36B4: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    skip_1:
    // 0x800D36B8: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x800D36BC: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x800D36C0: b           L_800D36D4
    // 0x800D36C4: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_800D36D4;
    // 0x800D36C4: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
    // 0x800D36C8: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
L_800D36CC:
    // 0x800D36CC: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x800D36D0: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_800D36D4:
    // 0x800D36D4: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x800D36D8: beql        $t5, $zero, L_800D36EC
    if (ctx->r13 == 0) {
        // 0x800D36DC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800D36EC;
    }
    goto skip_2;
    // 0x800D36DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_800D36E0:
    // 0x800D36E0: bne         $s1, $zero, L_800D3650
    if (ctx->r17 != 0) {
        // 0x800D36E4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D3650;
    }
    // 0x800D36E4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800D36E8:
    // 0x800D36E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800D36EC:
    // 0x800D36EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D36F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D36F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D36F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D36FC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800D3700: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800D3704: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3708: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800D370C: jr          $ra
    // 0x800D3710: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D3710: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _loadOutputBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5B44: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D5B48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D5B4C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D5B50: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D5B54: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800D5B58: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x800D5B5C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D5B60: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800D5B64: beq         $t6, $zero, L_800D5D20
    if (ctx->r14 == 0) {
        // 0x800D5B68: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_800D5D20;
    }
    // 0x800D5B68: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D5B6C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800D5B70: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800D5B74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D5B78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D5B7C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800D5B80: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800D5B84: jal         0x800D56D0
    // 0x800D5B88: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    _doModFunc(rdram, ctx);
        goto after_0;
    // 0x800D5B88: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_0:
    // 0x800D5B8C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800D5B90: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D5B94: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800D5B98: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800D5B9C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D5BA0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D5BA4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5BA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D5BAC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D5BB0: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x800D5BB4: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D5BB8: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D5BBC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D5BC0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800D5BC4: nop

    // 0x800D5BC8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D5BCC: nop

    // 0x800D5BD0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5BD4: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D5BD8: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800D5BDC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800D5BE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D5BE4: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800D5BE8: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x800D5BEC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D5BF0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800D5BF4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D5BF8: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800D5BFC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D5C00: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800D5C04: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800D5C08: nop

    // 0x800D5C0C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800D5C10: nop

    // 0x800D5C14: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D5C18: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800D5C1C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x800D5C20: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x800D5C24: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800D5C28: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x800D5C2C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800D5C30: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x800D5C34: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800D5C38: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800D5C3C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x800D5C40: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800D5C44: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800D5C48: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800D5C4C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800D5C50: subu        $a1, $t0, $t3
    ctx->r5 = SUB32(ctx->r8, ctx->r11);
    // 0x800D5C54: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800D5C58: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800D5C5C: addu        $a3, $t1, $t8
    ctx->r7 = ADD32(ctx->r9, ctx->r24);
    // 0x800D5C60: jal         0x800D59B8
    // 0x800D5C64: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer(rdram, ctx);
        goto after_1;
    // 0x800D5C64: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800D5C68: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800D5C6C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D5C70: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D5C74: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x800D5C78: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800D5C7C: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800D5C80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D5C84: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800D5C88: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x800D5C8C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800D5C90: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D5C94: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800D5C98: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D5C9C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D5CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D5CA4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D5CA8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800D5CAC: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x800D5CB0: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D5CB4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800D5CB8: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x800D5CBC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800D5CC0: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800D5CC4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800D5CC8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D5CCC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800D5CD0: nop

    // 0x800D5CD4: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800D5CD8: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x800D5CDC: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800D5CE0: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800D5CE4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D5CE8: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x800D5CEC: jal         0x800C79C0
    // 0x800D5CF0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D5CF0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D5CF4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D5CF8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D5CFC: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800D5D00: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x800D5D04: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800D5D08: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x800D5D0C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800D5D10: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x800D5D14: subu        $t5, $t9, $s1
    ctx->r13 = SUB32(ctx->r25, ctx->r17);
    // 0x800D5D18: b           L_800D5D50
    // 0x800D5D1C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_800D5D50;
    // 0x800D5D1C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_800D5D20:
    // 0x800D5D20: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800D5D24: lw          $t7, 0x18($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X18);
    // 0x800D5D28: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800D5D2C: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800D5D30: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800D5D34: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800D5D38: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800D5D3C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D5D40: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800D5D44: jal         0x800D59B8
    // 0x800D5D48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer(rdram, ctx);
        goto after_3;
    // 0x800D5D48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800D5D4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D5D50:
    // 0x800D5D50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D5D54: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5D58: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D5D5C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800D5D60: jr          $ra
    // 0x800D5D64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D5D64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
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
RECOMP_FUNC void func_80077BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077BD0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077BD4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077BD8: nop

    // 0x80077BDC: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80077BE0: nop

    // 0x80077BE4: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80077BE8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077BEC: jr          $ra
    // 0x80077BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077BF4: jr          $ra
    // 0x80077BF8: nop

    return;
    // 0x80077BF8: nop

    // 0x80077BFC: jr          $ra
    // 0x80077C00: nop

    return;
    // 0x80077C00: nop

;}
RECOMP_FUNC void func_80098868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009886C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098870: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80098874: jal         0x80097420
    // 0x80098878: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    func_80097420(rdram, ctx);
        goto after_0;
    // 0x80098878: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_0:
    // 0x8009887C: b           L_80098884
    // 0x80098880: nop

        goto L_80098884;
    // 0x80098880: nop

L_80098884:
    // 0x80098884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009888C: jr          $ra
    // 0x80098890: nop

    return;
    // 0x80098890: nop

;}
RECOMP_FUNC void func_800875E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800875E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800875E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800875EC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800875F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800875F4: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x800875F8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800875FC: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x80087600: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80087604: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80087608: nop

    // 0x8008760C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80087610: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80087614: nop

    // 0x80087618: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008761C: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80087620: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80087624: nop

    // 0x80087628: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8008762C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087630: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087634: nop

    // 0x80087638: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8008763C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80087640: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80087644: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x80087648: nop

    // 0x8008764C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80087650: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80087654: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x80087658: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008765C: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80087660: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80087664: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80087668: nop

    // 0x8008766C: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80087670: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80087674: nop

    // 0x80087678: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008767C: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80087680: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80087684: nop

    // 0x80087688: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8008768C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087690: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087694: nop

    // 0x80087698: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x8008769C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800876A0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800876A4: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x800876A8: nop

    // 0x800876AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800876B0: jal         0x80089170
    // 0x800876B4: nop

    func_80089170(rdram, ctx);
        goto after_0;
    // 0x800876B4: nop

    after_0:
    // 0x800876B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800876BC: jal         0x80089584
    // 0x800876C0: nop

    func_80089584(rdram, ctx);
        goto after_1;
    // 0x800876C0: nop

    after_1:
    // 0x800876C4: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x800876C8: lh          $t5, 0x2C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2C);
    // 0x800876CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800876D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800876D4: addiu       $t6, $t4, 0xF5
    ctx->r14 = ADD32(ctx->r12, 0XF5);
    // 0x800876D8: addiu       $t7, $t5, -0x1E
    ctx->r15 = ADD32(ctx->r13, -0X1E);
    // 0x800876DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800876E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800876E4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800876E8: ori         $a1, $zero, 0x805A
    ctx->r5 = 0 | 0X805A;
    // 0x800876EC: addiu       $a2, $t4, 0xE1
    ctx->r6 = ADD32(ctx->r12, 0XE1);
    // 0x800876F0: jal         0x800897A8
    // 0x800876F4: addiu       $a3, $t5, -0x28
    ctx->r7 = ADD32(ctx->r13, -0X28);
    func_800897A8(rdram, ctx);
        goto after_2;
    // 0x800876F4: addiu       $a3, $t5, -0x28
    ctx->r7 = ADD32(ctx->r13, -0X28);
    after_2:
    // 0x800876F8: b           L_80087708
    // 0x800876FC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80087708;
    // 0x800876FC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80087700: b           L_80087708
    // 0x80087704: nop

        goto L_80087708;
    // 0x80087704: nop

L_80087708:
    // 0x80087708: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008770C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80087710: jr          $ra
    // 0x80087714: nop

    return;
    // 0x80087714: nop

;}
RECOMP_FUNC void func_80017448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017448: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001744C: lw          $t6, 0x1A8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A8);
    // 0x80017450: nop

    // 0x80017454: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80017458: beq         $t7, $zero, L_8001778C
    if (ctx->r15 == 0) {
        // 0x8001745C: nop
    
            goto L_8001778C;
    }
    // 0x8001745C: nop

    // 0x80017460: lw          $t8, 0x1A8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1A8);
    // 0x80017464: nop

    // 0x80017468: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8001746C: beq         $t9, $zero, L_8001747C
    if (ctx->r25 == 0) {
        // 0x80017470: nop
    
            goto L_8001747C;
    }
    // 0x80017470: nop

    // 0x80017474: b           L_80017784
    // 0x80017478: nop

        goto L_80017784;
    // 0x80017478: nop

L_8001747C:
    // 0x8001747C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017480: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017484: lwc1        $f4, 0x1EC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80017488: lwc1        $f10, 0x1E8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8001748C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80017490: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80017494: swc1        $f16, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f16.u32l;
    // 0x80017498: lwc1        $f18, 0x1EC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x8001749C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800174A0: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800174A4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800174A8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800174AC: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800174B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800174B4: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800174B8: lwc1        $f8, 0x1EC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x800174BC: nop

    // 0x800174C0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800174C4: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x800174C8: lwc1        $f4, 0x1E8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x800174CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800174D0: nop

    // 0x800174D4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800174D8: nop

    // 0x800174DC: bc1f        L_8001769C
    if (!c1cs) {
        // 0x800174E0: nop
    
            goto L_8001769C;
    }
    // 0x800174E0: nop

    // 0x800174E4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800174E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800174EC: lwc1        $f10, 0x1E8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x800174F0: nop

    // 0x800174F4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800174F8: nop

    // 0x800174FC: bc1f        L_8001769C
    if (!c1cs) {
        // 0x80017500: nop
    
            goto L_8001769C;
    }
    // 0x80017500: nop

    // 0x80017504: lw          $t0, 0x20C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X20C);
    // 0x80017508: nop

    // 0x8001750C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x80017510: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80017514: nop

    // 0x80017518: beq         $t1, $zero, L_800175C4
    if (ctx->r9 == 0) {
        // 0x8001751C: nop
    
            goto L_800175C4;
    }
    // 0x8001751C: nop

L_80017520:
    // 0x80017520: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80017524: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80017528: lh          $t3, 0x11E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X11E);
    // 0x8001752C: nop

    // 0x80017530: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80017534: nop

    // 0x80017538: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001753C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80017540: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80017544: nop

    // 0x80017548: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8001754C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80017550: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80017554: nop

    // 0x80017558: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001755C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80017560: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80017564: sh          $t5, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r13;
    // 0x80017568: nop

    // 0x8001756C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80017570: nop

    // 0x80017574: lh          $t7, 0x11E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X11E);
    // 0x80017578: nop

    // 0x8001757C: bgez        $t7, L_80017590
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80017580: nop
    
            goto L_80017590;
    }
    // 0x80017580: nop

    // 0x80017584: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80017588: nop

    // 0x8001758C: sh          $zero, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = 0;
L_80017590:
    // 0x80017590: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80017594: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80017598: lw          $t1, -0x5A50($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5A50);
    // 0x8001759C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800175A0: nop

    // 0x800175A4: or          $t3, $t0, $t1
    ctx->r11 = ctx->r8 | ctx->r9;
    // 0x800175A8: sw          $t3, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r11;
    // 0x800175AC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800175B0: nop

    // 0x800175B4: lw          $t5, 0x150($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X150);
    // 0x800175B8: nop

    // 0x800175BC: bne         $t5, $zero, L_80017520
    if (ctx->r13 != 0) {
        // 0x800175C0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_80017520;
    }
    // 0x800175C0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_800175C4:
    // 0x800175C4: lw          $t2, 0x210($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X210);
    // 0x800175C8: nop

    // 0x800175CC: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x800175D0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800175D4: nop

    // 0x800175D8: beq         $t6, $zero, L_80017694
    if (ctx->r14 == 0) {
        // 0x800175DC: nop
    
            goto L_80017694;
    }
    // 0x800175DC: nop

L_800175E0:
    // 0x800175E0: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800175E4: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800175E8: lh          $t8, 0x11E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X11E);
    // 0x800175EC: nop

    // 0x800175F0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800175F4: nop

    // 0x800175F8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800175FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80017600: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80017604: nop

    // 0x80017608: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8001760C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80017610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80017614: nop

    // 0x80017618: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001761C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80017620: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80017624: sh          $t1, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r9;
    // 0x80017628: nop

    // 0x8001762C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80017630: nop

    // 0x80017634: lh          $t9, 0x11E($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X11E);
    // 0x80017638: lh          $t4, 0x120($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X120);
    // 0x8001763C: nop

    // 0x80017640: slt         $at, $t4, $t9
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80017644: beq         $at, $zero, L_80017660
    if (ctx->r1 == 0) {
        // 0x80017648: nop
    
            goto L_80017660;
    }
    // 0x80017648: nop

    // 0x8001764C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80017650: nop

    // 0x80017654: lh          $t2, 0x120($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X120);
    // 0x80017658: nop

    // 0x8001765C: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
L_80017660:
    // 0x80017660: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80017664: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80017668: lw          $t0, -0x5A50($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5A50);
    // 0x8001766C: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x80017670: nop

    // 0x80017674: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80017678: sw          $t1, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r9;
    // 0x8001767C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80017680: nop

    // 0x80017684: lw          $t3, 0x150($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X150);
    // 0x80017688: nop

    // 0x8001768C: bne         $t3, $zero, L_800175E0
    if (ctx->r11 != 0) {
        // 0x80017690: sw          $t3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r11;
            goto L_800175E0;
    }
    // 0x80017690: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
L_80017694:
    // 0x80017694: b           L_80017784
    // 0x80017698: nop

        goto L_80017784;
    // 0x80017698: nop

L_8001769C:
    // 0x8001769C: lw          $t9, 0x1A8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A8);
    // 0x800176A0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800176A4: and         $t4, $t9, $at
    ctx->r12 = ctx->r25 & ctx->r1;
    // 0x800176A8: sw          $t4, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r12;
    // 0x800176AC: lw          $t2, 0x1A8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1A8);
    // 0x800176B0: nop

    // 0x800176B4: ori         $t5, $t2, 0x2
    ctx->r13 = ctx->r10 | 0X2;
    // 0x800176B8: sw          $t5, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r13;
    // 0x800176BC: lw          $t8, 0x20C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20C);
    // 0x800176C0: nop

    // 0x800176C4: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800176C8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800176CC: nop

    // 0x800176D0: beq         $t0, $zero, L_8001771C
    if (ctx->r8 == 0) {
        // 0x800176D4: nop
    
            goto L_8001771C;
    }
    // 0x800176D4: nop

L_800176D8:
    // 0x800176D8: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800176DC: nop

    // 0x800176E0: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x800176E4: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800176E8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800176EC: lw          $t3, -0x5A50($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5A50);
    // 0x800176F0: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800176F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800176F8: xor         $t9, $t3, $at
    ctx->r25 = ctx->r11 ^ ctx->r1;
    // 0x800176FC: and         $t4, $t7, $t9
    ctx->r12 = ctx->r15 & ctx->r25;
    // 0x80017700: sw          $t4, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r12;
    // 0x80017704: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80017708: nop

    // 0x8001770C: lw          $t5, 0x150($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X150);
    // 0x80017710: nop

    // 0x80017714: bne         $t5, $zero, L_800176D8
    if (ctx->r13 != 0) {
        // 0x80017718: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800176D8;
    }
    // 0x80017718: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_8001771C:
    // 0x8001771C: lw          $t8, 0x210($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X210);
    // 0x80017720: nop

    // 0x80017724: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x80017728: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8001772C: nop

    // 0x80017730: beq         $t0, $zero, L_80017784
    if (ctx->r8 == 0) {
        // 0x80017734: nop
    
            goto L_80017784;
    }
    // 0x80017734: nop

L_80017738:
    // 0x80017738: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8001773C: nop

    // 0x80017740: lh          $t3, 0x120($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X120);
    // 0x80017744: nop

    // 0x80017748: sh          $t3, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r11;
    // 0x8001774C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80017750: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80017754: lw          $t4, -0x5A50($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5A50);
    // 0x80017758: lw          $t9, 0xC0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC0);
    // 0x8001775C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017760: xor         $t6, $t4, $at
    ctx->r14 = ctx->r12 ^ ctx->r1;
    // 0x80017764: and         $t2, $t9, $t6
    ctx->r10 = ctx->r25 & ctx->r14;
    // 0x80017768: sw          $t2, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r10;
    // 0x8001776C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80017770: nop

    // 0x80017774: lw          $t8, 0x150($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X150);
    // 0x80017778: nop

    // 0x8001777C: bne         $t8, $zero, L_80017738
    if (ctx->r24 != 0) {
        // 0x80017780: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_80017738;
    }
    // 0x80017780: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_80017784:
    // 0x80017784: b           L_800177C0
    // 0x80017788: nop

        goto L_800177C0;
    // 0x80017788: nop

L_8001778C:
    // 0x8001778C: lw          $t0, 0x1A8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1A8);
    // 0x80017790: nop

    // 0x80017794: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x80017798: beq         $t3, $zero, L_800177C0
    if (ctx->r11 == 0) {
        // 0x8001779C: nop
    
            goto L_800177C0;
    }
    // 0x8001779C: nop

    // 0x800177A0: lw          $t1, 0x1A8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1A8);
    // 0x800177A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800177A8: and         $t4, $t1, $at
    ctx->r12 = ctx->r9 & ctx->r1;
    // 0x800177AC: sw          $t4, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r12;
    // 0x800177B0: sw          $zero, 0x210($a0)
    MEM_W(0X210, ctx->r4) = 0;
    // 0x800177B4: lw          $t9, 0x210($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X210);
    // 0x800177B8: nop

    // 0x800177BC: sw          $t9, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->r25;
L_800177C0:
    // 0x800177C0: b           L_800177D0
    // 0x800177C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800177D0;
    // 0x800177C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800177C8: b           L_800177D0
    // 0x800177CC: nop

        goto L_800177D0;
    // 0x800177CC: nop

L_800177D0:
    // 0x800177D0: jr          $ra
    // 0x800177D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800177D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
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
RECOMP_FUNC void func_80064160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064168: jal         0x80061488
    // 0x8006416C: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006416C: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064170: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064174: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064178: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x8006417C: nop
    
            goto L_8006420C;
    }
    // 0x8006417C: nop

    // 0x80064180: jal         0x80061488
    // 0x80064184: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064184: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064188: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006418C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064190: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x80064194: nop
    
            goto L_8006420C;
    }
    // 0x80064194: nop

    // 0x80064198: jal         0x80061488
    // 0x8006419C: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x8006419C: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800641A0: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800641A4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800641A8: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641AC: nop
    
            goto L_8006420C;
    }
    // 0x800641AC: nop

    // 0x800641B0: jal         0x80061488
    // 0x800641B4: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800641B4: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800641B8: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800641BC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800641C0: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641C4: nop
    
            goto L_8006420C;
    }
    // 0x800641C4: nop

    // 0x800641C8: jal         0x80061488
    // 0x800641CC: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x800641CC: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x800641D0: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800641D4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800641D8: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641DC: nop
    
            goto L_8006420C;
    }
    // 0x800641DC: nop

    // 0x800641E0: jal         0x8005F064
    // 0x800641E4: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800641E4: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800641E8: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800641EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800641F0: beq         $v0, $zero, L_8006420C
    if (ctx->r2 == 0) {
        // 0x800641F4: nop
    
            goto L_8006420C;
    }
    // 0x800641F4: nop

    // 0x800641F8: jal         0x80061348
    // 0x800641FC: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800641FC: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064200: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064204: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064208: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006420C:
    // 0x8006420C: b           L_8006421C
    // 0x80064210: nop

        goto L_8006421C;
    // 0x80064210: nop

    // 0x80064214: b           L_8006421C
    // 0x80064218: nop

        goto L_8006421C;
    // 0x80064218: nop

L_8006421C:
    // 0x8006421C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064224: jr          $ra
    // 0x80064228: nop

    return;
    // 0x80064228: nop

;}
RECOMP_FUNC void func_80055870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055870: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80055874: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80055878: addiu       $t7, $t7, -0x27B0
    ctx->r15 = ADD32(ctx->r15, -0X27B0);
    // 0x8005587C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80055880: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80055884: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80055888: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005588C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80055890: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80055894: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80055898: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8005589C: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x800558A0: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800558A4: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x800558A8: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x800558AC: lw          $t0, 0x14($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X14);
    // 0x800558B0: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800558B4: sw          $t0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r8;
    // 0x800558B8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800558BC:
    // 0x800558BC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800558C0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800558C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800558C8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800558CC: addiu       $t5, $t5, -0x2AC0
    ctx->r13 = ADD32(ctx->r13, -0X2AC0);
    // 0x800558D0: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800558D4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800558D8: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x800558DC: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x800558E0: lw          $t3, 0xC($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XC);
    // 0x800558E4: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800558E8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800558EC: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800558F0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800558F4: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x800558F8: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x800558FC: nop

    // 0x80055900: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80055904: bne         $at, $zero, L_80055920
    if (ctx->r1 != 0) {
        // 0x80055908: nop
    
            goto L_80055920;
    }
    // 0x80055908: nop

    // 0x8005590C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80055910: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80055914: addu        $t3, $a0, $t7
    ctx->r11 = ADD32(ctx->r4, ctx->r15);
    // 0x80055918: b           L_80055944
    // 0x8005591C: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
        goto L_80055944;
    // 0x8005591C: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
L_80055920:
    // 0x80055920: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80055924: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80055928: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8005592C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80055930: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x80055934: lw          $t0, -0x2AB8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AB8);
    // 0x80055938: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8005593C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80055940: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
L_80055944:
    // 0x80055944: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055948: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8005594C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80055950: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80055954: addiu       $t4, $t4, -0x2AC0
    ctx->r12 = ADD32(ctx->r12, -0X2AC0);
    // 0x80055958: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8005595C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80055960: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80055964: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x80055968: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8005596C: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x80055970: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x80055974: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80055978: addu        $t0, $t2, $t8
    ctx->r8 = ADD32(ctx->r10, ctx->r24);
    // 0x8005597C: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80055980: lh          $t1, 0x0($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X0);
    // 0x80055984: nop

    // 0x80055988: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005598C: bne         $at, $zero, L_800559A4
    if (ctx->r1 != 0) {
        // 0x80055990: nop
    
            goto L_800559A4;
    }
    // 0x80055990: nop

    // 0x80055994: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055998: addu        $t0, $a0, $t8
    ctx->r8 = ADD32(ctx->r4, ctx->r24);
    // 0x8005599C: b           L_800559DC
    // 0x800559A0: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
        goto L_800559DC;
    // 0x800559A0: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
L_800559A4:
    // 0x800559A4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800559A8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800559AC: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800559B0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800559B4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800559B8: lw          $t4, -0x2AB4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AB4);
    // 0x800559BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800559C0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800559C4: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x800559C8: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x800559CC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800559D0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800559D4: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800559D8: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
L_800559DC:
    // 0x800559DC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800559E0: nop

    // 0x800559E4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800559E8: sltiu       $at, $t3, 0x7
    ctx->r1 = ctx->r11 < 0X7 ? 1 : 0;
    // 0x800559EC: bne         $at, $zero, L_800558BC
    if (ctx->r1 != 0) {
        // 0x800559F0: sw          $t3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r11;
            goto L_800558BC;
    }
    // 0x800559F0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_800559F4:
    // 0x800559F4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800559F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800559FC:
    // 0x800559FC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055A00: nop

    // 0x80055A04: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80055A08: addu        $t1, $t5, $a0
    ctx->r9 = ADD32(ctx->r13, ctx->r4);
    // 0x80055A0C: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80055A10: lh          $t9, 0x6($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X6);
    // 0x80055A14: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x80055A18: nop

    // 0x80055A1C: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80055A20: beq         $at, $zero, L_80055A98
    if (ctx->r1 == 0) {
        // 0x80055A24: nop
    
            goto L_80055A98;
    }
    // 0x80055A24: nop

    // 0x80055A28: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80055A2C: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80055A30: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80055A34: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80055A38: lwl         $at, 0x0($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0X0);
    // 0x80055A3C: lwr         $at, 0x3($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0X3);
    // 0x80055A40: nop

    // 0x80055A44: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80055A48: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80055A4C: nop

    // 0x80055A50: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80055A54: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x80055A58: lwl         $at, 0x4($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X4);
    // 0x80055A5C: lwr         $at, 0x7($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X7);
    // 0x80055A60: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80055A64: swl         $at, 0x0($t7)
    do_swl(rdram, 0X0, ctx->r15, ctx->r1);
    // 0x80055A68: swr         $at, 0x3($t7)
    do_swr(rdram, 0X3, ctx->r15, ctx->r1);
    // 0x80055A6C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055A70: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80055A74: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80055A78: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80055A7C: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x80055A80: swl         $at, 0x4($t3)
    do_swl(rdram, 0X4, ctx->r11, ctx->r1);
    // 0x80055A84: swr         $at, 0x7($t3)
    do_swr(rdram, 0X7, ctx->r11, ctx->r1);
    // 0x80055A88: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80055A8C: nop

    // 0x80055A90: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80055A94: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80055A98:
    // 0x80055A98: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80055A9C: nop

    // 0x80055AA0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80055AA4: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x80055AA8: bne         $at, $zero, L_800559FC
    if (ctx->r1 != 0) {
        // 0x80055AAC: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_800559FC;
    }
    // 0x80055AAC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80055AB0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80055AB4: nop

    // 0x80055AB8: bne         $t4, $zero, L_800559F4
    if (ctx->r12 != 0) {
        // 0x80055ABC: nop
    
            goto L_800559F4;
    }
    // 0x80055ABC: nop

    // 0x80055AC0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80055AC4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80055AC8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80055ACC:
    // 0x80055ACC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80055AD0: nop

    // 0x80055AD4: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80055AD8: addu        $t3, $t5, $a0
    ctx->r11 = ADD32(ctx->r13, ctx->r4);
    // 0x80055ADC: lh          $t1, 0x2($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X2);
    // 0x80055AE0: nop

    // 0x80055AE4: beq         $t1, $zero, L_80055BC4
    if (ctx->r9 == 0) {
        // 0x80055AE8: nop
    
            goto L_80055BC4;
    }
    // 0x80055AE8: nop

    // 0x80055AEC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055AF0: nop

    // 0x80055AF4: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80055AF8: addu        $t7, $t0, $a0
    ctx->r15 = ADD32(ctx->r8, ctx->r4);
    // 0x80055AFC: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80055B00: nop

    // 0x80055B04: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80055B08: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055B0C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80055B10: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80055B14: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80055B18: addu        $t6, $sp, $t1
    ctx->r14 = ADD32(ctx->r29, ctx->r9);
    // 0x80055B1C: addu        $t8, $t4, $a0
    ctx->r24 = ADD32(ctx->r12, ctx->r4);
    // 0x80055B20: lh          $t5, 0x2($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X2);
    // 0x80055B24: lw          $t6, 0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4);
    // 0x80055B28: addu        $t7, $t4, $a0
    ctx->r15 = ADD32(ctx->r12, ctx->r4);
    // 0x80055B2C: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055B30: mflo        $t0
    ctx->r8 = lo;
    // 0x80055B34: sh          $t0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r8;
    // 0x80055B38: nop

    // 0x80055B3C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80055B40: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055B44: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80055B48: addu        $t8, $t2, $a0
    ctx->r24 = ADD32(ctx->r10, ctx->r4);
    // 0x80055B4C: lh          $t3, 0x2($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X2);
    // 0x80055B50: addu        $t5, $t2, $a0
    ctx->r13 = ADD32(ctx->r10, ctx->r4);
    // 0x80055B54: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80055B58: mflo        $t1
    ctx->r9 = lo;
    // 0x80055B5C: sh          $t1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r9;
    // 0x80055B60: nop

    // 0x80055B64: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055B68: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80055B6C: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80055B70: addu        $t7, $a0, $t0
    ctx->r15 = ADD32(ctx->r4, ctx->r8);
    // 0x80055B74: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80055B78: nop

    // 0x80055B7C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80055B80: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80055B84: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80055B88: nop

    // 0x80055B8C: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x80055B90: beq         $at, $zero, L_80055BC4
    if (ctx->r1 == 0) {
        // 0x80055B94: nop
    
            goto L_80055BC4;
    }
    // 0x80055B94: nop

    // 0x80055B98: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80055B9C: addu        $t1, $t2, $a0
    ctx->r9 = ADD32(ctx->r10, ctx->r4);
    // 0x80055BA0: lh          $t5, 0x6($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X6);
    // 0x80055BA4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80055BA8: nop

    // 0x80055BAC: beq         $t5, $t4, L_80055BC4
    if (ctx->r13 == ctx->r12) {
        // 0x80055BB0: nop
    
            goto L_80055BC4;
    }
    // 0x80055BB0: nop

    // 0x80055BB4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80055BB8: nop

    // 0x80055BBC: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80055BC0: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_80055BC4:
    // 0x80055BC4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055BC8: nop

    // 0x80055BCC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80055BD0: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x80055BD4: bne         $at, $zero, L_80055ACC
    if (ctx->r1 != 0) {
        // 0x80055BD8: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80055ACC;
    }
    // 0x80055BD8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80055BDC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80055BE0: nop

    // 0x80055BE4: bne         $t8, $zero, L_80055BFC
    if (ctx->r24 != 0) {
        // 0x80055BE8: nop
    
            goto L_80055BFC;
    }
    // 0x80055BE8: nop

    // 0x80055BEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80055BF0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80055BF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80055BF8: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
L_80055BFC:
    // 0x80055BFC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80055C00: lw          $t1, 0x670($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X670);
    // 0x80055C04: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80055C08: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80055C0C: div         $zero, $t1, $t5
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r13)));
    // 0x80055C10: bne         $t5, $zero, L_80055C1C
    if (ctx->r13 != 0) {
        // 0x80055C14: nop
    
            goto L_80055C1C;
    }
    // 0x80055C14: nop

    // 0x80055C18: break       7
    do_break(2147834904);
L_80055C1C:
    // 0x80055C1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055C20: bne         $t5, $at, L_80055C34
    if (ctx->r13 != ctx->r1) {
        // 0x80055C24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80055C34;
    }
    // 0x80055C24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80055C28: bne         $t1, $at, L_80055C34
    if (ctx->r9 != ctx->r1) {
        // 0x80055C2C: nop
    
            goto L_80055C34;
    }
    // 0x80055C2C: nop

    // 0x80055C30: break       6
    do_break(2147834928);
L_80055C34:
    // 0x80055C34: mfhi        $t4
    ctx->r12 = hi;
    // 0x80055C38: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80055C3C: nop

L_80055C40:
    // 0x80055C40: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80055C44: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80055C48: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80055C4C: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x80055C50: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x80055C54: nop

    // 0x80055C58: subu        $t3, $t0, $t8
    ctx->r11 = SUB32(ctx->r8, ctx->r24);
    // 0x80055C5C: bgez        $t3, L_80055C80
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80055C60: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80055C80;
    }
    // 0x80055C60: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80055C64: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80055C68: nop

    // 0x80055C6C: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80055C70: addu        $t5, $t1, $a0
    ctx->r13 = ADD32(ctx->r9, ctx->r4);
    // 0x80055C74: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80055C78: b           L_80055CBC
    // 0x80055C7C: nop

        goto L_80055CBC;
    // 0x80055C7C: nop

L_80055C80:
    // 0x80055C80: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055C84: nop

    // 0x80055C88: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x80055C8C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80055C90: bne         $at, $zero, L_80055C40
    if (ctx->r1 != 0) {
        // 0x80055C94: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_80055C40;
    }
    // 0x80055C94: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80055C98: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80055C9C: nop

    // 0x80055CA0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80055CA4: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80055CA8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80055CAC: b           L_80055CBC
    // 0x80055CB0: nop

        goto L_80055CBC;
    // 0x80055CB0: nop

    // 0x80055CB4: b           L_80055CBC
    // 0x80055CB8: nop

        goto L_80055CBC;
    // 0x80055CB8: nop

L_80055CBC:
    // 0x80055CBC: jr          $ra
    // 0x80055CC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80055CC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80063ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063ED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063ED4: jal         0x80061488
    // 0x80063ED8: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063ED8: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    after_0:
    // 0x80063EDC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80063EE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80063EE4: b           L_80063EF4
    // 0x80063EE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063EF4;
    // 0x80063EE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063EEC: b           L_80063EF4
    // 0x80063EF0: nop

        goto L_80063EF4;
    // 0x80063EF0: nop

L_80063EF4:
    // 0x80063EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063EFC: jr          $ra
    // 0x80063F00: nop

    return;
    // 0x80063F00: nop

;}
RECOMP_FUNC void func_8006874C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006874C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068750: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068754: nop

    // 0x80068758: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x8006875C: nop

    // 0x80068760: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068764: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068768: jr          $ra
    // 0x8006876C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006876C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068770: jr          $ra
    // 0x80068774: nop

    return;
    // 0x80068774: nop

    // 0x80068778: jr          $ra
    // 0x8006877C: nop

    return;
    // 0x8006877C: nop

;}
RECOMP_FUNC void func_8005EB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EB00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005EB04: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x8005EB08: beq         $at, $zero, L_8005EC3C
    if (ctx->r1 == 0) {
        // 0x8005EB0C: nop
    
            goto L_8005EC3C;
    }
    // 0x8005EB0C: nop

L_8005EB10:
    // 0x8005EB10: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8005EB14: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005EB18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005EB1C: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005EB20: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005EB24: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8005EB28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EB2C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005EB30: bne         $t0, $zero, L_8005EC2C
    if (ctx->r8 != 0) {
        // 0x8005EB34: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005EC2C;
    }
    // 0x8005EB34: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005EB38: bne         $t1, $zero, L_8005EC2C
    if (ctx->r9 != 0) {
        // 0x8005EB3C: nop
    
            goto L_8005EC2C;
    }
    // 0x8005EB3C: nop

    // 0x8005EB40: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8005EB44: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005EB48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005EB4C: lw          $t3, 0xE80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE80);
    // 0x8005EB50: nop

    // 0x8005EB54: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8005EB58: lwc1        $f4, 0xCC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8005EB5C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB60: nop

    // 0x8005EB64: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8005EB68: lwc1        $f6, 0xD0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XD0);
    // 0x8005EB6C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB70: nop

    // 0x8005EB74: swc1        $f6, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f6.u32l;
    // 0x8005EB78: lwc1        $f8, 0xD4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XD4);
    // 0x8005EB7C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB80: nop

    // 0x8005EB84: swc1        $f8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f8.u32l;
    // 0x8005EB88: lwc1        $f10, 0xF0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XF0);
    // 0x8005EB8C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB90: nop

    // 0x8005EB94: swc1        $f10, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f10.u32l;
    // 0x8005EB98: lwc1        $f16, 0xF4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x8005EB9C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBA0: nop

    // 0x8005EBA4: swc1        $f16, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f16.u32l;
    // 0x8005EBA8: lwc1        $f18, 0xF8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x8005EBAC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBB0: nop

    // 0x8005EBB4: swc1        $f18, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f18.u32l;
    // 0x8005EBB8: lw          $t0, 0xC0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC0);
    // 0x8005EBBC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBC0: nop

    // 0x8005EBC4: sw          $t0, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->r8;
    // 0x8005EBC8: lh          $t2, 0x11E($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X11E);
    // 0x8005EBCC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBD0: nop

    // 0x8005EBD4: sw          $t2, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->r10;
    // 0x8005EBD8: lw          $t4, 0xC8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC8);
    // 0x8005EBDC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBE0: nop

    // 0x8005EBE4: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x8005EBE8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBEC: nop

    // 0x8005EBF0: sw          $a0, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r4;
    // 0x8005EBF4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBF8: nop

    // 0x8005EBFC: sw          $a1, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r5;
    // 0x8005EC00: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005EC04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EC08: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005EC0C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005EC10: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8005EC14: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x8005EC18: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005EC1C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005EC20: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8005EC24: b           L_8005EC4C
    // 0x8005EC28: nop

        goto L_8005EC4C;
    // 0x8005EC28: nop

L_8005EC2C:
    // 0x8005EC2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005EC30: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x8005EC34: bne         $at, $zero, L_8005EB10
    if (ctx->r1 != 0) {
        // 0x8005EC38: nop
    
            goto L_8005EB10;
    }
    // 0x8005EC38: nop

L_8005EC3C:
    // 0x8005EC3C: b           L_8005EC4C
    // 0x8005EC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EC4C;
    // 0x8005EC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005EC44: b           L_8005EC4C
    // 0x8005EC48: nop

        goto L_8005EC4C;
    // 0x8005EC48: nop

L_8005EC4C:
    // 0x8005EC4C: jr          $ra
    // 0x8005EC50: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005EC50: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void Main_SetContStickScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED4C: swc1        $f12, 0xE50($at)
    MEM_W(0XE50, ctx->r1) = ctx->f12.u32l;
    // 0x800BED50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED54: swc1        $f14, 0xE5C($at)
    MEM_W(0XE5C, ctx->r1) = ctx->f14.u32l;
    // 0x800BED58: jr          $ra
    // 0x800BED5C: nop

    return;
    // 0x800BED5C: nop

    // 0x800BED60: jr          $ra
    // 0x800BED64: nop

    return;
    // 0x800BED64: nop

;}
RECOMP_FUNC void func_8006F59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F59C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F5A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F5A4: jal         0x80061488
    // 0x8006F5A8: addiu       $a0, $zero, 0x3BB
    ctx->r4 = ADD32(0, 0X3BB);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F5A8: addiu       $a0, $zero, 0x3BB
    ctx->r4 = ADD32(0, 0X3BB);
    after_0:
    // 0x8006F5AC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F5B0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006F5B4: b           L_8006F5C4
    // 0x8006F5B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F5C4;
    // 0x8006F5B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F5BC: b           L_8006F5C4
    // 0x8006F5C0: nop

        goto L_8006F5C4;
    // 0x8006F5C0: nop

L_8006F5C4:
    // 0x8006F5C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F5C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F5CC: jr          $ra
    // 0x8006F5D0: nop

    return;
    // 0x8006F5D0: nop

;}
RECOMP_FUNC void func_8003A0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A0A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003A0A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003A0AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003A0B0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8003A0B4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8003A0B8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8003A0BC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003A0C0: lw          $t6, 0x7298($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7298);
    // 0x8003A0C4: nop

    // 0x8003A0C8: addiu       $t7, $t6, 0xAE0
    ctx->r15 = ADD32(ctx->r14, 0XAE0);
    // 0x8003A0CC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8003A0D0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003A0D4: lw          $t8, 0x7298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7298);
    // 0x8003A0D8: nop

    // 0x8003A0DC: lwc1        $f4, 0xAE4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XAE4);
    // 0x8003A0E0: nop

    // 0x8003A0E4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8003A0E8: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8003A0EC: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8003A0F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003A0F4: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8003A0F8: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8003A0FC: nop

    // 0x8003A100: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8003A104: beq         $t2, $zero, L_8003A1D8
    if (ctx->r10 == 0) {
        // 0x8003A108: nop
    
            goto L_8003A1D8;
    }
    // 0x8003A108: nop

    // 0x8003A10C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8003A110: lbu         $t3, -0x69F8($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X69F8);
    // 0x8003A114: nop

    // 0x8003A118: beq         $t3, $zero, L_8003A1D8
    if (ctx->r11 == 0) {
        // 0x8003A11C: nop
    
            goto L_8003A1D8;
    }
    // 0x8003A11C: nop

    // 0x8003A120: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003A124: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003A128: nop

    // 0x8003A12C: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8003A130: nop

    // 0x8003A134: bc1f        L_8003A1D8
    if (!c1cs) {
        // 0x8003A138: nop
    
            goto L_8003A1D8;
    }
    // 0x8003A138: nop

    // 0x8003A13C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003A140: lw          $t5, 0x7298($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7298);
    // 0x8003A144: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8003A148: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8003A14C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A150: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003A154: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003A158: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003A15C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8003A160: jal         0x80039F78
    // 0x8003A164: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80039F78(rdram, ctx);
        goto after_0;
    // 0x8003A164: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x8003A168: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003A16C: lw          $t7, 0x7298($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7298);
    // 0x8003A170: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003A174: sh          $t6, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r14;
    // 0x8003A178: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003A17C: lw          $t9, 0x7298($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7298);
    // 0x8003A180: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003A184: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8003A188: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A18C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003A190: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003A194: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003A198: addiu       $t0, $t9, 0x1D0
    ctx->r8 = ADD32(ctx->r25, 0X1D0);
    // 0x8003A19C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003A1A0: jal         0x80039F78
    // 0x8003A1A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80039F78(rdram, ctx);
        goto after_1;
    // 0x8003A1A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8003A1A8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003A1AC: lw          $t2, 0x7298($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7298);
    // 0x8003A1B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003A1B4: sh          $t1, 0x1DC($t2)
    MEM_H(0X1DC, ctx->r10) = ctx->r9;
    // 0x8003A1B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003A1BC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003A1C0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003A1C4: nop

    // 0x8003A1C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003A1CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8003A1D0: jal         0x800B9000
    // 0x8003A1D4: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    func_800B9000(rdram, ctx);
        goto after_2;
    // 0x8003A1D4: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_2:
L_8003A1D8:
    // 0x8003A1D8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003A1DC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003A1E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003A1E4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A1E8: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8003A1EC: nop

    // 0x8003A1F0: bc1t        L_8003A3D0
    if (c1cs) {
        // 0x8003A1F4: nop
    
            goto L_8003A3D0;
    }
    // 0x8003A1F4: nop

    // 0x8003A1F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003A1FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003A200: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003A204: nop

    // 0x8003A208: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8003A20C: nop

    // 0x8003A210: bc1f        L_8003A2DC
    if (!c1cs) {
        // 0x8003A214: nop
    
            goto L_8003A2DC;
    }
    // 0x8003A214: nop

    // 0x8003A218: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8003A21C: nop

    // 0x8003A220: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8003A224: nop

    // 0x8003A228: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8003A22C: bne         $t5, $zero, L_8003A2DC
    if (ctx->r13 != 0) {
        // 0x8003A230: nop
    
            goto L_8003A2DC;
    }
    // 0x8003A230: nop

    // 0x8003A234: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003A238: lw          $t7, 0x7298($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7298);
    // 0x8003A23C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8003A240: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8003A244: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A248: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003A24C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003A250: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003A254: addiu       $t8, $t7, 0x3A0
    ctx->r24 = ADD32(ctx->r15, 0X3A0);
    // 0x8003A258: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003A25C: jal         0x80039F78
    // 0x8003A260: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80039F78(rdram, ctx);
        goto after_3;
    // 0x8003A260: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8003A264: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003A268: lw          $t0, 0x7298($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7298);
    // 0x8003A26C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003A270: sh          $t9, 0x3AC($t0)
    MEM_H(0X3AC, ctx->r8) = ctx->r25;
    // 0x8003A274: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003A278: lw          $t2, 0x7298($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7298);
    // 0x8003A27C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8003A280: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8003A284: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A288: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003A28C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003A290: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003A294: addiu       $t3, $t2, 0x570
    ctx->r11 = ADD32(ctx->r10, 0X570);
    // 0x8003A298: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8003A29C: jal         0x80039F78
    // 0x8003A2A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_80039F78(rdram, ctx);
        goto after_4;
    // 0x8003A2A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
    // 0x8003A2A4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003A2A8: lw          $t5, 0x7298($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7298);
    // 0x8003A2AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003A2B0: sh          $t4, 0x57C($t5)
    MEM_H(0X57C, ctx->r13) = ctx->r12;
    // 0x8003A2B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8003A2B8: nop

    // 0x8003A2BC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8003A2C0: nop

    // 0x8003A2C4: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8003A2C8: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x8003A2CC: jal         0x800B9000
    // 0x8003A2D0: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x8003A2D0: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_5:
    // 0x8003A2D4: b           L_8003A3B8
    // 0x8003A2D8: nop

        goto L_8003A3B8;
    // 0x8003A2D8: nop

L_8003A2DC:
    // 0x8003A2DC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A2E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003A2E4: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003A2E8: nop

    // 0x8003A2EC: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8003A2F0: nop

    // 0x8003A2F4: bc1f        L_8003A3B8
    if (!c1cs) {
        // 0x8003A2F8: nop
    
            goto L_8003A3B8;
    }
    // 0x8003A2F8: nop

    // 0x8003A2FC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8003A300: nop

    // 0x8003A304: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8003A308: nop

    // 0x8003A30C: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8003A310: bne         $t1, $zero, L_8003A3B8
    if (ctx->r9 != 0) {
        // 0x8003A314: nop
    
            goto L_8003A3B8;
    }
    // 0x8003A314: nop

    // 0x8003A318: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003A31C: lw          $t3, 0x7298($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7298);
    // 0x8003A320: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8003A324: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8003A328: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A32C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003A330: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003A334: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003A338: addiu       $t4, $t3, 0x740
    ctx->r12 = ADD32(ctx->r11, 0X740);
    // 0x8003A33C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8003A340: jal         0x80039F78
    // 0x8003A344: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_80039F78(rdram, ctx);
        goto after_6;
    // 0x8003A344: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_6:
    // 0x8003A348: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003A34C: lw          $t7, 0x7298($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7298);
    // 0x8003A350: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003A354: sh          $t5, 0x74C($t7)
    MEM_H(0X74C, ctx->r15) = ctx->r13;
    // 0x8003A358: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003A35C: lw          $t6, 0x7298($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7298);
    // 0x8003A360: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003A364: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8003A368: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A36C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003A370: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003A374: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003A378: addiu       $t9, $t6, 0x910
    ctx->r25 = ADD32(ctx->r14, 0X910);
    // 0x8003A37C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003A380: jal         0x80039F78
    // 0x8003A384: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80039F78(rdram, ctx);
        goto after_7;
    // 0x8003A384: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_7:
    // 0x8003A388: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003A38C: lw          $t1, 0x7298($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7298);
    // 0x8003A390: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003A394: sh          $t0, 0x91C($t1)
    MEM_H(0X91C, ctx->r9) = ctx->r8;
    // 0x8003A398: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8003A39C: nop

    // 0x8003A3A0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8003A3A4: nop

    // 0x8003A3A8: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8003A3AC: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x8003A3B0: jal         0x800B9000
    // 0x8003A3B4: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    func_800B9000(rdram, ctx);
        goto after_8;
    // 0x8003A3B4: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_8:
L_8003A3B8:
    // 0x8003A3B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003A3BC: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003A3C0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003A3C4: nop

    // 0x8003A3C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003A3CC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_8003A3D0:
    // 0x8003A3D0: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // 0x8003A3D4: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
L_8003A3D8:
    // 0x8003A3D8: lh          $t7, 0x2A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2A);
    // 0x8003A3DC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003A3E0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8003A3E4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003A3E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8003A3EC: lw          $t5, 0x7298($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7298);
    // 0x8003A3F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003A3F4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8003A3F8: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x8003A3FC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8003A400: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8003A404: nop

    // 0x8003A408: lhu         $t0, 0xC($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XC);
    // 0x8003A40C: nop

    // 0x8003A410: beq         $t0, $zero, L_8003A4B8
    if (ctx->r8 == 0) {
        // 0x8003A414: nop
    
            goto L_8003A4B8;
    }
    // 0x8003A414: nop

    // 0x8003A418: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8003A41C: nop

    // 0x8003A420: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8003A424: sh          $t3, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r11;
    // 0x8003A428: jal         0x800C1850
    // 0x8003A42C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_9;
    // 0x8003A42C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8003A430: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003A434: nop

    // 0x8003A438: lwc1        $f12, 0x0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003A43C: lwc1        $f14, 0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8003A440: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x8003A444: jal         0x800C2304
    // 0x8003A448: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_10;
    // 0x8003A448: nop

    after_10:
    // 0x8003A44C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003A450: jal         0x800997D8
    // 0x8003A454: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_800997D8(rdram, ctx);
        goto after_11;
    // 0x8003A454: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_11:
    // 0x8003A458: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003A45C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003A460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003A464: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003A468: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003A46C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003A470: addiu       $a0, $t2, 0x10
    ctx->r4 = ADD32(ctx->r10, 0X10);
    // 0x8003A474: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8003A478: addiu       $a2, $t2, 0x4
    ctx->r6 = ADD32(ctx->r10, 0X4);
    // 0x8003A47C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003A480: jal         0x800C3F2C
    // 0x8003A484: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    func_800C3F2C(rdram, ctx);
        goto after_12;
    // 0x8003A484: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    after_12:
    // 0x8003A488: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8003A48C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8003A490: lwc1        $f6, 0x28($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X28);
    // 0x8003A494: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003A498: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A49C: c.eq.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d == ctx->f10.d;
    // 0x8003A4A0: nop

    // 0x8003A4A4: bc1f        L_8003A4B8
    if (!c1cs) {
        // 0x8003A4A8: nop
    
            goto L_8003A4B8;
    }
    // 0x8003A4A8: nop

    // 0x8003A4AC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8003A4B0: nop

    // 0x8003A4B4: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
L_8003A4B8:
    // 0x8003A4B8: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8003A4BC: nop

    // 0x8003A4C0: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8003A4C4: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8003A4C8: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003A4CC: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8003A4D0: bne         $at, $zero, L_8003A3D8
    if (ctx->r1 != 0) {
        // 0x8003A4D4: sh          $t6, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r14;
            goto L_8003A3D8;
    }
    // 0x8003A4D4: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x8003A4D8: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8003A4DC: nop

    // 0x8003A4E0: bne         $t1, $zero, L_8003A500
    if (ctx->r9 != 0) {
        // 0x8003A4E4: nop
    
            goto L_8003A500;
    }
    // 0x8003A4E4: nop

    // 0x8003A4E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003A4EC: nop

    // 0x8003A4F0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8003A4F4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8003A4F8: nop

    // 0x8003A4FC: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
L_8003A500:
    // 0x8003A500: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003A504: lw          $t4, 0x7298($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7298);
    // 0x8003A508: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003A50C: nop

    // 0x8003A510: swc1        $f18, 0xAE4($t4)
    MEM_W(0XAE4, ctx->r12) = ctx->f18.u32l;
    // 0x8003A514: b           L_8003A51C
    // 0x8003A518: nop

        goto L_8003A51C;
    // 0x8003A518: nop

L_8003A51C:
    // 0x8003A51C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003A520: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003A524: jr          $ra
    // 0x8003A528: nop

    return;
    // 0x8003A528: nop

;}
RECOMP_FUNC void func_8006CFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CFEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CFF0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CFF4: nop

    // 0x8006CFF8: lh          $v0, 0x2A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2A);
    // 0x8006CFFC: nop

    // 0x8006D000: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D004: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D008: jr          $ra
    // 0x8006D00C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D00C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D010: jr          $ra
    // 0x8006D014: nop

    return;
    // 0x8006D014: nop

    // 0x8006D018: jr          $ra
    // 0x8006D01C: nop

    return;
    // 0x8006D01C: nop

;}
RECOMP_FUNC void func_800C03C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C03C8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C03CC: lw          $t6, 0x47C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X47C);
    // 0x800C03D0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C03D4: beq         $t6, $at, L_800C0420
    if (ctx->r14 == ctx->r1) {
        // 0x800C03D8: nop
    
            goto L_800C0420;
    }
    // 0x800C03D8: nop

L_800C03DC:
    // 0x800C03DC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C03E0: lw          $t7, 0x44C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44C);
    // 0x800C03E4: nop

    // 0x800C03E8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C03EC: nop

    // 0x800C03F0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C03F4: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800C03F8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800C03FC: lw          $t0, 0x47C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X47C);
    // 0x800C0400: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0404: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C0408: sw          $t1, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = ctx->r9;
    // 0x800C040C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C0410: lw          $t2, 0x47C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X47C);
    // 0x800C0414: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C0418: bne         $t2, $at, L_800C03DC
    if (ctx->r10 != ctx->r1) {
        // 0x800C041C: nop
    
            goto L_800C03DC;
    }
    // 0x800C041C: nop

L_800C0420:
    // 0x800C0420: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800C0424: lw          $t3, 0x44C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X44C);
    // 0x800C0428: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C042C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C0430: sw          $t4, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r12;
    // 0x800C0434: jr          $ra
    // 0x800C0438: nop

    return;
    // 0x800C0438: nop

    // 0x800C043C: jr          $ra
    // 0x800C0440: nop

    return;
    // 0x800C0440: nop

;}
RECOMP_FUNC void func_8005A9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A9A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005A9A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005A9A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005A9AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005A9B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A9B4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005A9B8: nop

    // 0x8005A9BC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8005A9C0: jal         0x8005F268
    // 0x8005A9C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F268(rdram, ctx);
        goto after_0;
    // 0x8005A9C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8005A9C8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8005A9CC: nop

    // 0x8005A9D0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8005A9D4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A9D8: nop

    // 0x8005A9DC: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8005A9E0: nop

    // 0x8005A9E4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8005A9E8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A9EC: nop

    // 0x8005A9F0: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8005A9F4: jal         0x80098754
    // 0x8005A9F8: nop

    func_80098754(rdram, ctx);
        goto after_1;
    // 0x8005A9F8: nop

    after_1:
    // 0x8005A9FC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AA00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005AA04: sh          $t1, 0x7C($t2)
    MEM_H(0X7C, ctx->r10) = ctx->r9;
    // 0x8005AA08: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AA0C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005AA10: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005AA14: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8005AA18: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AA1C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8005AA20: bne         $t6, $zero, L_8005AA64
    if (ctx->r14 != 0) {
        // 0x8005AA24: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_8005AA64;
    }
    // 0x8005AA24: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005AA28: bne         $t7, $zero, L_8005AA64
    if (ctx->r15 != 0) {
        // 0x8005AA2C: nop
    
            goto L_8005AA64;
    }
    // 0x8005AA2C: nop

L_8005AA30:
    // 0x8005AA30: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AA34: jal         0x800499B0
    // 0x8005AA38: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8005AA38: nop

    after_2:
    // 0x8005AA3C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005AA40: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005AA44: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005AA48: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005AA4C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AA50: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005AA54: bne         $t2, $zero, L_8005AA64
    if (ctx->r10 != 0) {
        // 0x8005AA58: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8005AA64;
    }
    // 0x8005AA58: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8005AA5C: beq         $t3, $zero, L_8005AA30
    if (ctx->r11 == 0) {
        // 0x8005AA60: nop
    
            goto L_8005AA30;
    }
    // 0x8005AA60: nop

L_8005AA64:
    // 0x8005AA64: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8005AA68: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8005AA6C: lhu         $t4, 0x0($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X0);
    // 0x8005AA70: nop

    // 0x8005AA74: andi        $t5, $t4, 0x402
    ctx->r13 = ctx->r12 & 0X402;
    // 0x8005AA78: beq         $t5, $zero, L_8005AAA8
    if (ctx->r13 == 0) {
        // 0x8005AA7C: nop
    
            goto L_8005AAA8;
    }
    // 0x8005AA7C: nop

L_8005AA80:
    // 0x8005AA80: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AA84: jal         0x800499B0
    // 0x8005AA88: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8005AA88: nop

    after_3:
    // 0x8005AA8C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8005AA90: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8005AA94: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8005AA98: nop

    // 0x8005AA9C: andi        $t8, $t7, 0x402
    ctx->r24 = ctx->r15 & 0X402;
    // 0x8005AAA0: bne         $t8, $zero, L_8005AA80
    if (ctx->r24 != 0) {
        // 0x8005AAA4: nop
    
            goto L_8005AA80;
    }
    // 0x8005AAA4: nop

L_8005AAA8:
    // 0x8005AAA8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005AAAC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005AAB0: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005AAB4: lw          $t0, 0xE70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE70);
    // 0x8005AAB8: nop

    // 0x8005AABC: sw          $t0, 0xB0($t1)
    MEM_W(0XB0, ctx->r9) = ctx->r8;
    // 0x8005AAC0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005AAC4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8005AAC8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005AACC: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8005AAD0: addiu       $t9, $t9, 0x1270
    ctx->r25 = ADD32(ctx->r25, 0X1270);
    // 0x8005AAD4: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x8005AAD8: jal         0x8005F064
    // 0x8005AADC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_8005F064(rdram, ctx);
        goto after_4;
    // 0x8005AADC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_4:
    // 0x8005AAE0: beq         $v0, $zero, L_8005AAFC
    if (ctx->r2 == 0) {
        // 0x8005AAE4: nop
    
            goto L_8005AAFC;
    }
    // 0x8005AAE4: nop

    // 0x8005AAE8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AAEC: addiu       $t5, $t5, 0x1270
    ctx->r13 = ADD32(ctx->r13, 0X1270);
    // 0x8005AAF0: addiu       $t4, $zero, 0x3E7
    ctx->r12 = ADD32(0, 0X3E7);
    // 0x8005AAF4: b           L_8005AB48
    // 0x8005AAF8: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
        goto L_8005AB48;
    // 0x8005AAF8: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
L_8005AAFC:
    // 0x8005AAFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005AB00: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005AB04: nop

    // 0x8005AB08: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8005AB0C: nop

    // 0x8005AB10: slti        $at, $t7, 0x399
    ctx->r1 = SIGNED(ctx->r15) < 0X399 ? 1 : 0;
    // 0x8005AB14: bne         $at, $zero, L_8005AB30
    if (ctx->r1 != 0) {
        // 0x8005AB18: nop
    
            goto L_8005AB30;
    }
    // 0x8005AB18: nop

    // 0x8005AB1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005AB20: addiu       $t0, $t0, 0x1270
    ctx->r8 = ADD32(ctx->r8, 0X1270);
    // 0x8005AB24: addiu       $t8, $zero, 0x398
    ctx->r24 = ADD32(0, 0X398);
    // 0x8005AB28: b           L_8005AB48
    // 0x8005AB2C: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
        goto L_8005AB48;
    // 0x8005AB2C: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
L_8005AB30:
    // 0x8005AB30: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005AB34: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005AB38: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AB3C: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x8005AB40: addiu       $t3, $t3, 0x1270
    ctx->r11 = ADD32(ctx->r11, 0X1270);
    // 0x8005AB44: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
L_8005AB48:
    // 0x8005AB48: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005AB4C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8005AB50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AB54: lh          $t4, 0x8($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X8);
    // 0x8005AB58: addiu       $t5, $t5, 0x1270
    ctx->r13 = ADD32(ctx->r13, 0X1270);
    // 0x8005AB5C: sh          $t4, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r12;
    // 0x8005AB60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005AB64: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005AB68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005AB6C: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8005AB70: addiu       $t8, $t8, 0x1270
    ctx->r24 = ADD32(ctx->r24, 0X1270);
    // 0x8005AB74: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x8005AB78: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005AB7C: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8005AB80: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005AB84: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8005AB88: addiu       $t2, $t2, 0x1270
    ctx->r10 = ADD32(ctx->r10, 0X1270);
    // 0x8005AB8C: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x8005AB90: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AB94: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005AB98: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005AB9C: lh          $t9, 0x28($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X28);
    // 0x8005ABA0: addiu       $t4, $t4, 0x1270
    ctx->r12 = ADD32(ctx->r12, 0X1270);
    // 0x8005ABA4: sh          $t9, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r25;
    // 0x8005ABA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005ABAC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005ABB0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005ABB4: addiu       $t5, $t5, 0x1270
    ctx->r13 = ADD32(ctx->r13, 0X1270);
    // 0x8005ABB8: sw          $t5, 0xB4($t6)
    MEM_W(0XB4, ctx->r14) = ctx->r13;
    // 0x8005ABBC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005ABC0: jal         0x800507AC
    // 0x8005ABC4: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    func_800507AC(rdram, ctx);
        goto after_5;
    // 0x8005ABC4: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    after_5:
    // 0x8005ABC8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ABCC: nop

    // 0x8005ABD0: sw          $zero, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = 0;
    // 0x8005ABD4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ABD8: nop

    // 0x8005ABDC: lw          $t0, 0xA8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XA8);
    // 0x8005ABE0: nop

    // 0x8005ABE4: sw          $t0, 0xA4($t8)
    MEM_W(0XA4, ctx->r24) = ctx->r8;
    // 0x8005ABE8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ABEC: nop

    // 0x8005ABF0: lh          $t2, 0xAC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XAC);
    // 0x8005ABF4: nop

    // 0x8005ABF8: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8005ABFC: sh          $t3, 0xAC($t1)
    MEM_H(0XAC, ctx->r9) = ctx->r11;
    // 0x8005AC00: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005AC04:
    // 0x8005AC04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005AC08: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005AC0C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AC10: lh          $t4, 0x7C($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X7C);
    // 0x8005AC14: nop

    // 0x8005AC18: bne         $t4, $at, L_8005AC2C
    if (ctx->r12 != ctx->r1) {
        // 0x8005AC1C: nop
    
            goto L_8005AC2C;
    }
    // 0x8005AC1C: nop

    // 0x8005AC20: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AC24: b           L_8005AC34
    // 0x8005AC28: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
        goto L_8005AC34;
    // 0x8005AC28: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
L_8005AC2C:
    // 0x8005AC2C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AC30: addiu       $s0, $s0, 0x1290
    ctx->r16 = ADD32(ctx->r16, 0X1290);
L_8005AC34:
    // 0x8005AC34: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AC38: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AC3C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005AC40: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005AC44: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x8005AC48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005AC4C: jal         0x8005B110
    // 0x8005AC50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8005B110(rdram, ctx);
        goto after_6;
    // 0x8005AC50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_6:
    // 0x8005AC54: beq         $v0, $zero, L_8005AC70
    if (ctx->r2 == 0) {
        // 0x8005AC58: nop
    
            goto L_8005AC70;
    }
    // 0x8005AC58: nop

    // 0x8005AC5C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AC60: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005AC64: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005AC68: jal         0x8005B490
    // 0x8005AC6C: addiu       $a2, $a2, 0x1270
    ctx->r6 = ADD32(ctx->r6, 0X1270);
    func_8005B490(rdram, ctx);
        goto after_7;
    // 0x8005AC6C: addiu       $a2, $a2, 0x1270
    ctx->r6 = ADD32(ctx->r6, 0X1270);
    after_7:
L_8005AC70:
    // 0x8005AC70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AC74: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AC78: jal         0x8005B610
    // 0x8005AC7C: nop

    func_8005B610(rdram, ctx);
        goto after_8;
    // 0x8005AC7C: nop

    after_8:
    // 0x8005AC80: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AC84: jal         0x800499B0
    // 0x8005AC88: nop

    func_800499B0(rdram, ctx);
        goto after_9;
    // 0x8005AC88: nop

    after_9:
    // 0x8005AC8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005AC90: nop

    // 0x8005AC94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005AC98: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8005AC9C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ACA0: nop

    // 0x8005ACA4: lh          $t8, 0xAC($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XAC);
    // 0x8005ACA8: nop

    // 0x8005ACAC: andi        $t2, $t8, 0x40
    ctx->r10 = ctx->r24 & 0X40;
    // 0x8005ACB0: bne         $t2, $zero, L_8005ACE4
    if (ctx->r10 != 0) {
        // 0x8005ACB4: nop
    
            goto L_8005ACE4;
    }
    // 0x8005ACB4: nop

    // 0x8005ACB8: lw          $t3, 0xA4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XA4);
    // 0x8005ACBC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8005ACC0: bne         $t3, $at, L_8005AC04
    if (ctx->r11 != ctx->r1) {
        // 0x8005ACC4: nop
    
            goto L_8005AC04;
    }
    // 0x8005ACC4: nop

    // 0x8005ACC8: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8005ACCC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005ACD0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005ACD4: bne         $t6, $zero, L_8005ACE4
    if (ctx->r14 != 0) {
        // 0x8005ACD8: andi        $t7, $t5, 0x2
        ctx->r15 = ctx->r13 & 0X2;
            goto L_8005ACE4;
    }
    // 0x8005ACD8: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x8005ACDC: beq         $t7, $zero, L_8005AC04
    if (ctx->r15 == 0) {
        // 0x8005ACE0: nop
    
            goto L_8005AC04;
    }
    // 0x8005ACE0: nop

L_8005ACE4:
    // 0x8005ACE4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ACE8: nop

    // 0x8005ACEC: lh          $t9, 0xAC($t1)
    ctx->r25 = MEM_H(ctx->r9, 0XAC);
    // 0x8005ACF0: nop

    // 0x8005ACF4: andi        $t8, $t9, 0x40
    ctx->r24 = ctx->r25 & 0X40;
    // 0x8005ACF8: bne         $t8, $zero, L_8005AD10
    if (ctx->r24 != 0) {
        // 0x8005ACFC: nop
    
            goto L_8005AD10;
    }
    // 0x8005ACFC: nop

    // 0x8005AD00: jal         0x8005F0DC
    // 0x8005AD04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F0DC(rdram, ctx);
        goto after_10;
    // 0x8005AD04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x8005AD08: b           L_8005AD28
    // 0x8005AD0C: nop

        goto L_8005AD28;
    // 0x8005AD0C: nop

L_8005AD10:
    // 0x8005AD10: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x8005AD14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005AD18: sb          $t2, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r10;
    // 0x8005AD1C: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x8005AD20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005AD24: sh          $t3, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r11;
L_8005AD28:
    // 0x8005AD28: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AD2C: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8005AD30: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8005AD34: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005AD38: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005AD3C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005AD40: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005AD44: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8005AD48: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005AD4C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD50: nop

    // 0x8005AD54: sb          $zero, 0x20($t1)
    MEM_B(0X20, ctx->r9) = 0;
    // 0x8005AD58: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD5C: nop

    // 0x8005AD60: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8005AD64: jal         0x80098AD8
    // 0x8005AD68: nop

    func_80098AD8(rdram, ctx);
        goto after_11;
    // 0x8005AD68: nop

    after_11:
    // 0x8005AD6C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD70: jal         0x80049544
    // 0x8005AD74: nop

    func_80049544(rdram, ctx);
        goto after_12;
    // 0x8005AD74: nop

    after_12:
    // 0x8005AD78: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD7C: nop

    // 0x8005AD80: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8005AD84: jal         0x800C0D34
    // 0x8005AD88: nop

    Thread_StopThread(rdram, ctx);
        goto after_13;
    // 0x8005AD88: nop

    after_13:
L_8005AD8C:
    // 0x8005AD8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD90: jal         0x800499B0
    // 0x8005AD94: nop

    func_800499B0(rdram, ctx);
        goto after_14;
    // 0x8005AD94: nop

    after_14:
    // 0x8005AD98: b           L_8005AD8C
    // 0x8005AD9C: nop

        goto L_8005AD8C;
    // 0x8005AD9C: nop

    // 0x8005ADA0: b           L_8005ADA8
    // 0x8005ADA4: nop

        goto L_8005ADA8;
    // 0x8005ADA4: nop

L_8005ADA8:
    // 0x8005ADA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005ADAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005ADB0: jr          $ra
    // 0x8005ADB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005ADB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800044BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800044BC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800044C0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800044C4:
    // 0x800044C4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800044C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800044CC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800044D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800044D4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800044D8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800044DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800044E0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800044E4: sw          $zero, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = 0;
    // 0x800044E8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800044EC: nop

    // 0x800044F0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800044F4: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x800044F8: bne         $at, $zero, L_800044C4
    if (ctx->r1 != 0) {
        // 0x800044FC: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_800044C4;
    }
    // 0x800044FC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80004500: b           L_80004508
    // 0x80004504: nop

        goto L_80004508;
    // 0x80004504: nop

L_80004508:
    // 0x80004508: jr          $ra
    // 0x8000450C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000450C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006B8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B8B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B8BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B8C0: nop

    // 0x8006B8C4: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006B8C8: nop

    // 0x8006B8CC: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8006B8D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B8D4: jr          $ra
    // 0x8006B8D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B8D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B8DC: jr          $ra
    // 0x8006B8E0: nop

    return;
    // 0x8006B8E0: nop

    // 0x8006B8E4: jr          $ra
    // 0x8006B8E8: nop

    return;
    // 0x8006B8E8: nop

;}
RECOMP_FUNC void func_800737F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800737F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800737F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800737F8: nop

    // 0x800737FC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073800: nop

    // 0x80073804: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80073808: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007380C: jr          $ra
    // 0x80073810: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073810: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073814: jr          $ra
    // 0x80073818: nop

    return;
    // 0x80073818: nop

    // 0x8007381C: jr          $ra
    // 0x80073820: nop

    return;
    // 0x80073820: nop

;}
RECOMP_FUNC void func_80002F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F1C: nop

;}
RECOMP_FUNC void func_80005878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005878: nop

    // 0x8000587C: nop

;}
RECOMP_FUNC void func_80007794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007794: nop

    // 0x80007798: nop

    // 0x8000779C: nop

;}
RECOMP_FUNC void func_8000D57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D57C: nop

;}
RECOMP_FUNC void func_8000DDD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DDD4: nop

    // 0x8000DDD8: nop

    // 0x8000DDDC: nop

;}
RECOMP_FUNC void func_80014C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014C68: nop

    // 0x80014C6C: nop

;}
RECOMP_FUNC void func_80015E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015E48: nop

    // 0x80015E4C: nop

;}
RECOMP_FUNC void func_800173C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800173C4: nop

    // 0x800173C8: nop

    // 0x800173CC: nop

;}
RECOMP_FUNC void func_8001F38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F38C: nop

;}
RECOMP_FUNC void func_80021598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021598: nop

    // 0x8002159C: nop

;}
