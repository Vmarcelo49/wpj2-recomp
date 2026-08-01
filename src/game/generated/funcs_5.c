#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006ED44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED4C: jal         0x80061348
    // 0x8006ED50: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ED50: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_0:
    // 0x8006ED54: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ED58: b           L_8006ED68
    // 0x8006ED5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006ED68;
    // 0x8006ED5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ED60: b           L_8006ED68
    // 0x8006ED64: nop

        goto L_8006ED68;
    // 0x8006ED64: nop

L_8006ED68:
    // 0x8006ED68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED70: jr          $ra
    // 0x8006ED74: nop

    return;
    // 0x8006ED74: nop

;}
RECOMP_FUNC void func_80065680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065688: jal         0x8005F064
    // 0x8006568C: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006568C: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_0:
    // 0x80065690: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065694: b           L_800656A4
    // 0x80065698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800656A4;
    // 0x80065698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006569C: b           L_800656A4
    // 0x800656A0: nop

        goto L_800656A4;
    // 0x800656A0: nop

L_800656A4:
    // 0x800656A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800656A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800656AC: jr          $ra
    // 0x800656B0: nop

    return;
    // 0x800656B0: nop

;}
RECOMP_FUNC void func_8006F9E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F9E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F9E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F9E8: jal         0x80061348
    // 0x8006F9EC: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F9EC: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006F9F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F9F4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F9F8: b           L_8006FA08
    // 0x8006F9FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FA08;
    // 0x8006F9FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FA00: b           L_8006FA08
    // 0x8006FA04: nop

        goto L_8006FA08;
    // 0x8006FA04: nop

L_8006FA08:
    // 0x8006FA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FA0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FA10: jr          $ra
    // 0x8006FA14: nop

    return;
    // 0x8006FA14: nop

;}
RECOMP_FUNC void func_8006D5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D5F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D5F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D5F8: nop

    // 0x8006D5FC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D600: nop

    // 0x8006D604: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8006D608: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D60C: jr          $ra
    // 0x8006D610: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D610: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D614: jr          $ra
    // 0x8006D618: nop

    return;
    // 0x8006D618: nop

    // 0x8006D61C: jr          $ra
    // 0x8006D620: nop

    return;
    // 0x8006D620: nop

;}
RECOMP_FUNC void func_80080C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080C28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80080C2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80080C30: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80080C34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80080C38: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80080C3C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80080C40: nop

    // 0x80080C44: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x80080C48: nop

    // 0x80080C4C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80080C50: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080C54: nop

    // 0x80080C58: lhu         $t0, 0xE($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XE);
    // 0x80080C5C: nop

    // 0x80080C60: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x80080C64: beq         $at, $zero, L_800810F8
    if (ctx->r1 == 0) {
        // 0x80080C68: nop
    
            goto L_800810F8;
    }
    // 0x80080C68: nop

    // 0x80080C6C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80080C70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80080C74: addu        $at, $at, $t0
    gpr jr_addend_80080C80 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80080C78: lw          $t0, -0xB30($at)
    ctx->r8 = ADD32(ctx->r1, -0XB30);
    // 0x80080C7C: nop

    // 0x80080C80: jr          $t0
    // 0x80080C84: nop

    switch (jr_addend_80080C80 >> 2) {
        case 0: goto L_80080C88; break;
        case 1: goto L_80080D20; break;
        case 2: goto L_80080D78; break;
        case 3: goto L_80080DE0; break;
        case 4: goto L_80080F20; break;
        case 5: goto L_80080F90; break;
        case 6: goto L_80081000; break;
        default: switch_error(__func__, 0x80080C80, 0x800EF4D0);
    }
    // 0x80080C84: nop

L_80080C88:
    // 0x80080C88: jal         0x80016074
    // 0x80080C8C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80080C8C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80080C90: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80080C94: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80080C98: nop

    // 0x80080C9C: beq         $t1, $zero, L_80080CC4
    if (ctx->r9 == 0) {
        // 0x80080CA0: nop
    
            goto L_80080CC4;
    }
    // 0x80080CA0: nop

    // 0x80080CA4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80080CA8: nop

    // 0x80080CAC: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x80080CB0: nop

    // 0x80080CB4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80080CB8: bne         $t4, $zero, L_80080CC4
    if (ctx->r12 != 0) {
        // 0x80080CBC: nop
    
            goto L_80080CC4;
    }
    // 0x80080CBC: nop

    // 0x80080CC0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80080CC4:
    // 0x80080CC4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80080CC8: nop

    // 0x80080CCC: beq         $t5, $zero, L_80080D18
    if (ctx->r13 == 0) {
        // 0x80080CD0: nop
    
            goto L_80080D18;
    }
    // 0x80080CD0: nop

    // 0x80080CD4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080CD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80080CDC: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x80080CE0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80080CE4: nop

    // 0x80080CE8: lhu         $a0, 0xE($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XE);
    // 0x80080CEC: jal         0x80081B00
    // 0x80080CF0: nop

    func_80081B00(rdram, ctx);
        goto after_1;
    // 0x80080CF0: nop

    after_1:
    // 0x80080CF4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080CF8: nop

    // 0x80080CFC: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x80080D00: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D04: nop

    // 0x80080D08: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x80080D0C: nop

    // 0x80080D10: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80080D14: sh          $t2, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r10;
L_80080D18:
    // 0x80080D18: b           L_80081108
    // 0x80080D1C: nop

        goto L_80081108;
    // 0x80080D1C: nop

L_80080D20:
    // 0x80080D20: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D24: nop

    // 0x80080D28: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x80080D2C: nop

    // 0x80080D30: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80080D34: beq         $t5, $zero, L_80080D44
    if (ctx->r13 == 0) {
        // 0x80080D38: nop
    
            goto L_80080D44;
    }
    // 0x80080D38: nop

    // 0x80080D3C: b           L_80081108
    // 0x80080D40: nop

        goto L_80081108;
    // 0x80080D40: nop

L_80080D44:
    // 0x80080D44: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D48: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80080D4C: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x80080D50: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D54: nop

    // 0x80080D58: lhu         $a0, 0xE($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XE);
    // 0x80080D5C: jal         0x80081B00
    // 0x80080D60: nop

    func_80081B00(rdram, ctx);
        goto after_2;
    // 0x80080D60: nop

    after_2:
    // 0x80080D64: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D68: nop

    // 0x80080D6C: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x80080D70: b           L_80081108
    // 0x80080D74: nop

        goto L_80081108;
    // 0x80080D74: nop

L_80080D78:
    // 0x80080D78: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80080D7C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80080D80: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80080D84: nop

    // 0x80080D88: ori         $t0, $t2, 0x40
    ctx->r8 = ctx->r10 | 0X40;
    // 0x80080D8C: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80080D90: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080D94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080D98: lh          $t4, 0x16($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X16);
    // 0x80080D9C: nop

    // 0x80080DA0: sh          $t4, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r12;
    // 0x80080DA4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080DA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080DAC: lh          $t6, 0x18($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X18);
    // 0x80080DB0: nop

    // 0x80080DB4: sh          $t6, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r14;
    // 0x80080DB8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080DBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80080DC0: lh          $t8, 0x1A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X1A);
    // 0x80080DC4: nop

    // 0x80080DC8: sh          $t8, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r24;
    // 0x80080DCC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80080DD0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80080DD4: sh          $t9, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r25;
    // 0x80080DD8: b           L_80081108
    // 0x80080DDC: nop

        goto L_80081108;
    // 0x80080DDC: nop

L_80080DE0:
    // 0x80080DE0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80080DE4: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80080DE8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80080DEC: nop

    // 0x80080DF0: andi        $t3, $t1, 0x40
    ctx->r11 = ctx->r9 & 0X40;
    // 0x80080DF4: beq         $t3, $zero, L_80080E04
    if (ctx->r11 == 0) {
        // 0x80080DF8: nop
    
            goto L_80080E04;
    }
    // 0x80080DF8: nop

    // 0x80080DFC: b           L_80081108
    // 0x80080E00: nop

        goto L_80081108;
    // 0x80080E00: nop

L_80080E04:
    // 0x80080E04: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80080E08: lh          $t4, 0x7132($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7132);
    // 0x80080E0C: nop

    // 0x80080E10: sh          $t4, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r12;
    // 0x80080E14: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E18: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80080E1C: lh          $t6, 0x16($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X16);
    // 0x80080E20: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80080E24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80080E28: lh          $t7, 0x18($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X18);
    // 0x80080E2C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80080E30: lh          $t0, 0x728C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X728C);
    // 0x80080E34: lh          $t2, 0x7280($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7280);
    // 0x80080E38: lh          $t9, 0x7274($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7274);
    // 0x80080E3C: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x80080E40: addiu       $a0, $t5, 0x1C
    ctx->r4 = ADD32(ctx->r13, 0X1C);
    // 0x80080E44: addiu       $a1, $t5, 0x1E
    ctx->r5 = ADD32(ctx->r13, 0X1E);
    // 0x80080E48: addiu       $a2, $t5, 0x20
    ctx->r6 = ADD32(ctx->r13, 0X20);
    // 0x80080E4C: addiu       $a3, $t5, 0x22
    ctx->r7 = ADD32(ctx->r13, 0X22);
    // 0x80080E50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80080E54: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80080E58: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80080E5C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80080E60: jal         0x80081CE8
    // 0x80080E64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80081CE8(rdram, ctx);
        goto after_3;
    // 0x80080E64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_3:
    // 0x80080E68: bgez        $v0, L_80080EBC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80080E6C: nop
    
            goto L_80080EBC;
    }
    // 0x80080E6C: nop

    // 0x80080E70: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E74: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80080E78: sh          $t1, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r9;
    // 0x80080E7C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E80: nop

    // 0x80080E84: lhu         $a0, 0xE($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0XE);
    // 0x80080E88: jal         0x80081B00
    // 0x80080E8C: nop

    func_80081B00(rdram, ctx);
        goto after_4;
    // 0x80080E8C: nop

    after_4:
    // 0x80080E90: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80080E94: nop

    // 0x80080E98: sh          $v0, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r2;
    // 0x80080E9C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EA0: nop

    // 0x80080EA4: lhu         $t7, 0xC($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0XC);
    // 0x80080EA8: nop

    // 0x80080EAC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80080EB0: sh          $t8, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r24;
    // 0x80080EB4: b           L_80081108
    // 0x80080EB8: nop

        goto L_80081108;
    // 0x80080EB8: nop

L_80080EBC:
    // 0x80080EBC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EC0: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x80080EC4: lh          $t2, 0x1A($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X1A);
    // 0x80080EC8: nop

    // 0x80080ECC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80080ED0: beq         $at, $zero, L_80080EE8
    if (ctx->r1 == 0) {
        // 0x80080ED4: nop
    
            goto L_80080EE8;
    }
    // 0x80080ED4: nop

    // 0x80080ED8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80080EE0: b           L_80080EF4
    // 0x80080EE4: sh          $t1, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r9;
        goto L_80080EF4;
    // 0x80080EE4: sh          $t1, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r9;
L_80080EE8:
    // 0x80080EE8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EEC: nop

    // 0x80080EF0: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
L_80080EF4:
    // 0x80080EF4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080EF8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80080EFC: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x80080F00: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F04: nop

    // 0x80080F08: lhu         $t5, 0xC($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0XC);
    // 0x80080F0C: nop

    // 0x80080F10: ori         $t9, $t5, 0x2
    ctx->r25 = ctx->r13 | 0X2;
    // 0x80080F14: sh          $t9, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r25;
    // 0x80080F18: b           L_80081108
    // 0x80080F1C: nop

        goto L_80081108;
    // 0x80080F1C: nop

L_80080F20:
    // 0x80080F20: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F24: nop

    // 0x80080F28: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x80080F2C: nop

    // 0x80080F30: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80080F34: beq         $t1, $zero, L_80080F44
    if (ctx->r9 == 0) {
        // 0x80080F38: nop
    
            goto L_80080F44;
    }
    // 0x80080F38: nop

    // 0x80080F3C: b           L_80081108
    // 0x80080F40: nop

        goto L_80081108;
    // 0x80080F40: nop

L_80080F44:
    // 0x80080F44: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F48: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80080F4C: sh          $t3, 0xE($t4)
    MEM_H(0XE, ctx->r12) = ctx->r11;
    // 0x80080F50: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F54: nop

    // 0x80080F58: lhu         $a0, 0xE($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XE);
    // 0x80080F5C: jal         0x80081B00
    // 0x80080F60: nop

    func_80081B00(rdram, ctx);
        goto after_5;
    // 0x80080F60: nop

    after_5:
    // 0x80080F64: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F68: nop

    // 0x80080F6C: sh          $v0, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r2;
    // 0x80080F70: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F74: nop

    // 0x80080F78: lhu         $t9, 0xC($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0XC);
    // 0x80080F7C: nop

    // 0x80080F80: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x80080F84: sh          $t8, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r24;
    // 0x80080F88: b           L_80081108
    // 0x80080F8C: nop

        goto L_80081108;
    // 0x80080F8C: nop

L_80080F90:
    // 0x80080F90: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80080F94: nop

    // 0x80080F98: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x80080F9C: nop

    // 0x80080FA0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80080FA4: beq         $t1, $zero, L_80080FB4
    if (ctx->r9 == 0) {
        // 0x80080FA8: nop
    
            goto L_80080FB4;
    }
    // 0x80080FA8: nop

    // 0x80080FAC: b           L_80081108
    // 0x80080FB0: nop

        goto L_80081108;
    // 0x80080FB0: nop

L_80080FB4:
    // 0x80080FB4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FB8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80080FBC: sh          $t3, 0xE($t4)
    MEM_H(0XE, ctx->r12) = ctx->r11;
    // 0x80080FC0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FC4: nop

    // 0x80080FC8: lhu         $a0, 0xE($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XE);
    // 0x80080FCC: jal         0x80081B00
    // 0x80080FD0: nop

    func_80081B00(rdram, ctx);
        goto after_6;
    // 0x80080FD0: nop

    after_6:
    // 0x80080FD4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FD8: nop

    // 0x80080FDC: sh          $v0, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r2;
    // 0x80080FE0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FE4: nop

    // 0x80080FE8: lhu         $t8, 0xC($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0XC);
    // 0x80080FEC: nop

    // 0x80080FF0: ori         $t5, $t8, 0x1
    ctx->r13 = ctx->r24 | 0X1;
    // 0x80080FF4: sh          $t5, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r13;
    // 0x80080FF8: b           L_80081108
    // 0x80080FFC: nop

        goto L_80081108;
    // 0x80080FFC: nop

L_80081000:
    // 0x80081000: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80081004: nop

    // 0x80081008: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x8008100C: nop

    // 0x80081010: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80081014: beq         $t1, $zero, L_80081024
    if (ctx->r9 == 0) {
        // 0x80081018: nop
    
            goto L_80081024;
    }
    // 0x80081018: nop

    // 0x8008101C: b           L_80081108
    // 0x80081020: nop

        goto L_80081108;
    // 0x80081020: nop

L_80081024:
    // 0x80081024: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80081028: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008102C: lh          $t4, 0x22($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X22);
    // 0x80081030: nop

    // 0x80081034: bne         $t4, $at, L_800810BC
    if (ctx->r12 != ctx->r1) {
        // 0x80081038: nop
    
            goto L_800810BC;
    }
    // 0x80081038: nop

    // 0x8008103C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80081040: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80081044: lh          $t7, 0x1C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1C);
    // 0x80081048: nop

    // 0x8008104C: sh          $t7, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r15;
    // 0x80081050: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80081054: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80081058: lh          $t5, 0x1E($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X1E);
    // 0x8008105C: nop

    // 0x80081060: sh          $t5, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r13;
    // 0x80081064: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80081068: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008106C: lh          $t2, 0x20($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X20);
    // 0x80081070: nop

    // 0x80081074: sh          $t2, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r10;
    // 0x80081078: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008107C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081080: sw          $t0, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r8;
    // 0x80081084: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80081088: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008108C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80081090: swc1        $f4, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f4.u32l;
    // 0x80081094: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80081098: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8008109C: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
    // 0x800810A0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800810A4: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x800810A8: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x800810AC: nop

    // 0x800810B0: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x800810B4: b           L_800810E4
    // 0x800810B8: sh          $t6, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r14;
        goto L_800810E4;
    // 0x800810B8: sh          $t6, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r14;
L_800810BC:
    // 0x800810BC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800810C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800810C4: lh          $t8, 0x22($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X22);
    // 0x800810C8: nop

    // 0x800810CC: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x800810D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800810D4: lh          $t5, 0x7254($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7254);
    // 0x800810D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800810DC: ori         $t9, $t5, 0x8000
    ctx->r25 = ctx->r13 | 0X8000;
    // 0x800810E0: sh          $t9, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r25;
L_800810E4:
    // 0x800810E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800810E8: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800810EC: sh          $t2, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r10;
    // 0x800810F0: b           L_80081108
    // 0x800810F4: nop

        goto L_80081108;
    // 0x800810F4: nop

L_800810F8:
    // 0x800810F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800810FC: sh          $zero, -0x498($at)
    MEM_H(-0X498, ctx->r1) = 0;
    // 0x80081100: b           L_80081108
    // 0x80081104: nop

        goto L_80081108;
    // 0x80081104: nop

L_80081108:
    // 0x80081108: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008110C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80081110: lhu         $t4, 0xE($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0XE);
    // 0x80081114: nop

    // 0x80081118: beq         $t4, $at, L_8008112C
    if (ctx->r12 == ctx->r1) {
        // 0x8008111C: nop
    
            goto L_8008112C;
    }
    // 0x8008111C: nop

    // 0x80081120: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80081124: jal         0x80081204
    // 0x80081128: nop

    func_80081204(rdram, ctx);
        goto after_7;
    // 0x80081128: nop

    after_7:
L_8008112C:
    // 0x8008112C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80081130: nop

    // 0x80081134: lhu         $t3, 0xC($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0XC);
    // 0x80081138: nop

    // 0x8008113C: andi        $t7, $t3, 0x1
    ctx->r15 = ctx->r11 & 0X1;
    // 0x80081140: beq         $t7, $zero, L_80081174
    if (ctx->r15 == 0) {
        // 0x80081144: nop
    
            goto L_80081174;
    }
    // 0x80081144: nop

    // 0x80081148: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8008114C: jal         0x80081260
    // 0x80081150: nop

    func_80081260(rdram, ctx);
        goto after_8;
    // 0x80081150: nop

    after_8:
    // 0x80081154: bgez        $v0, L_80081174
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80081158: nop
    
            goto L_80081174;
    }
    // 0x80081158: nop

    // 0x8008115C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80081160: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80081164: lhu         $t5, 0xC($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0XC);
    // 0x80081168: nop

    // 0x8008116C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80081170: sh          $t9, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r25;
L_80081174:
    // 0x80081174: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80081178: nop

    // 0x8008117C: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x80081180: nop

    // 0x80081184: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80081188: beq         $t1, $zero, L_800811BC
    if (ctx->r9 == 0) {
        // 0x8008118C: nop
    
            goto L_800811BC;
    }
    // 0x8008118C: nop

    // 0x80081190: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80081194: jal         0x80081554
    // 0x80081198: nop

    func_80081554(rdram, ctx);
        goto after_9;
    // 0x80081198: nop

    after_9:
    // 0x8008119C: bgez        $v0, L_800811BC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800811A0: nop
    
            goto L_800811BC;
    }
    // 0x800811A0: nop

    // 0x800811A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800811A8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800811AC: lhu         $t6, 0xC($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0XC);
    // 0x800811B0: nop

    // 0x800811B4: and         $t3, $t6, $at
    ctx->r11 = ctx->r14 & ctx->r1;
    // 0x800811B8: sh          $t3, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r11;
L_800811BC:
    // 0x800811BC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800811C0: nop

    // 0x800811C4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800811C8: jal         0x80081A60
    // 0x800811CC: nop

    func_80081A60(rdram, ctx);
        goto after_10;
    // 0x800811CC: nop

    after_10:
    // 0x800811D0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800811D4: nop

    // 0x800811D8: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    // 0x800811DC: jal         0x80081A60
    // 0x800811E0: nop

    func_80081A60(rdram, ctx);
        goto after_11;
    // 0x800811E0: nop

    after_11:
    // 0x800811E4: b           L_800811F4
    // 0x800811E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800811F4;
    // 0x800811E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800811EC: b           L_800811F4
    // 0x800811F0: nop

        goto L_800811F4;
    // 0x800811F0: nop

L_800811F4:
    // 0x800811F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800811F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800811FC: jr          $ra
    // 0x80081200: nop

    return;
    // 0x80081200: nop

;}
RECOMP_FUNC void func_80077A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077A74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077A78: nop

    // 0x80077A7C: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x80077A80: nop

    // 0x80077A84: slti        $t7, $v0, 0x65
    ctx->r15 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80077A88: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077A8C: bne         $v0, $zero, L_80077AA4
    if (ctx->r2 != 0) {
        // 0x80077A90: nop
    
            goto L_80077AA4;
    }
    // 0x80077A90: nop

    // 0x80077A94: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80077A98: nop

    // 0x80077A9C: slti        $t8, $v0, 0x65
    ctx->r24 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80077AA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80077AA4:
    // 0x80077AA4: jr          $ra
    // 0x80077AA8: nop

    return;
    // 0x80077AA8: nop

    // 0x80077AAC: jr          $ra
    // 0x80077AB0: nop

    return;
    // 0x80077AB0: nop

    // 0x80077AB4: jr          $ra
    // 0x80077AB8: nop

    return;
    // 0x80077AB8: nop

;}
RECOMP_FUNC void func_8008E5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E5A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008E5A4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008E5A8:
    // 0x8008E5A8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5B0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8008E5B4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008E5B8: sw          $zero, -0x38B8($at)
    MEM_W(-0X38B8, ctx->r1) = 0;
    // 0x8008E5BC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5C4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8008E5C8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008E5CC: sw          $zero, -0x38B4($at)
    MEM_W(-0X38B4, ctx->r1) = 0;
    // 0x8008E5D0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5D8: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008E5DC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008E5E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008E5E4: sw          $t0, -0x38B0($at)
    MEM_W(-0X38B0, ctx->r1) = ctx->r8;
    // 0x8008E5E8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5F0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8008E5F4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008E5F8: sw          $zero, -0x38AC($at)
    MEM_W(-0X38AC, ctx->r1) = 0;
    // 0x8008E5FC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8008E600: nop

    // 0x8008E604: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008E608: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008E60C: bne         $at, $zero, L_8008E5A8
    if (ctx->r1 != 0) {
        // 0x8008E610: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8008E5A8;
    }
    // 0x8008E610: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008E614: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8008E618: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E61C: sh          $t7, -0x44C8($at)
    MEM_H(-0X44C8, ctx->r1) = ctx->r15;
    // 0x8008E620: b           L_8008E628
    // 0x8008E624: nop

        goto L_8008E628;
    // 0x8008E624: nop

L_8008E628:
    // 0x8008E628: jr          $ra
    // 0x8008E62C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008E62C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006613C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006613C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066144: jal         0x80061348
    // 0x80066148: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066148: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006614C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066150: b           L_80066160
    // 0x80066154: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066160;
    // 0x80066154: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066158: b           L_80066160
    // 0x8006615C: nop

        goto L_80066160;
    // 0x8006615C: nop

L_80066160:
    // 0x80066160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066168: jr          $ra
    // 0x8006616C: nop

    return;
    // 0x8006616C: nop

;}
RECOMP_FUNC void func_8007F930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F930: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007F934: bltz        $a1, L_8007F9CC
    if (SIGNED(ctx->r5) < 0) {
        // 0x8007F938: nop
    
            goto L_8007F9CC;
    }
    // 0x8007F938: nop

    // 0x8007F93C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8007F940: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8007F944: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007F948: nop

    // 0x8007F94C: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x8007F950: beq         $at, $zero, L_8007F9C0
    if (ctx->r1 == 0) {
        // 0x8007F954: nop
    
            goto L_8007F9C0;
    }
    // 0x8007F954: nop

L_8007F958:
    // 0x8007F958: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007F95C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007F960: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007F964: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007F968: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007F96C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007F970: lh          $t9, 0x2460($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2460);
    // 0x8007F974: nop

    // 0x8007F978: bltz        $t9, L_8007F9A8
    if (SIGNED(ctx->r25) < 0) {
        // 0x8007F97C: nop
    
            goto L_8007F9A8;
    }
    // 0x8007F97C: nop

    // 0x8007F980: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007F984: nop

    // 0x8007F988: bne         $t0, $a1, L_8007F998
    if (ctx->r8 != ctx->r5) {
        // 0x8007F98C: nop
    
            goto L_8007F998;
    }
    // 0x8007F98C: nop

    // 0x8007F990: b           L_8007F9C0
    // 0x8007F994: nop

        goto L_8007F9C0;
    // 0x8007F994: nop

L_8007F998:
    // 0x8007F998: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8007F99C: nop

    // 0x8007F9A0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8007F9A4: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_8007F9A8:
    // 0x8007F9A8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9AC: nop

    // 0x8007F9B0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007F9B4: slti        $at, $t4, 0x28
    ctx->r1 = SIGNED(ctx->r12) < 0X28 ? 1 : 0;
    // 0x8007F9B8: bne         $at, $zero, L_8007F958
    if (ctx->r1 != 0) {
        // 0x8007F9BC: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8007F958;
    }
    // 0x8007F9BC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
L_8007F9C0:
    // 0x8007F9C0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9C4: b           L_8007FA5C
    // 0x8007F9C8: nop

        goto L_8007FA5C;
    // 0x8007F9C8: nop

L_8007F9CC:
    // 0x8007F9CC: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8007F9D0: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8007F9D4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9D8: nop

    // 0x8007F9DC: bltz        $t5, L_8007FA48
    if (SIGNED(ctx->r13) < 0) {
        // 0x8007F9E0: nop
    
            goto L_8007FA48;
    }
    // 0x8007F9E0: nop

L_8007F9E4:
    // 0x8007F9E4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007F9E8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007F9EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007F9F0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007F9F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F9F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007F9FC: lh          $t8, 0x2460($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2460);
    // 0x8007FA00: nop

    // 0x8007FA04: bltz        $t8, L_8007FA34
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007FA08: nop
    
            goto L_8007FA34;
    }
    // 0x8007FA08: nop

    // 0x8007FA0C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA10: nop

    // 0x8007FA14: bne         $t9, $a1, L_8007FA24
    if (ctx->r25 != ctx->r5) {
        // 0x8007FA18: nop
    
            goto L_8007FA24;
    }
    // 0x8007FA18: nop

    // 0x8007FA1C: b           L_8007FA48
    // 0x8007FA20: nop

        goto L_8007FA48;
    // 0x8007FA20: nop

L_8007FA24:
    // 0x8007FA24: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA28: nop

    // 0x8007FA2C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007FA30: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_8007FA34:
    // 0x8007FA34: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007FA38: nop

    // 0x8007FA3C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8007FA40: bgez        $t3, L_8007F9E4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007FA44: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8007F9E4;
    }
    // 0x8007FA44: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_8007FA48:
    // 0x8007FA48: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8007FA4C: b           L_8007FA5C
    // 0x8007FA50: nop

        goto L_8007FA5C;
    // 0x8007FA50: nop

    // 0x8007FA54: b           L_8007FA5C
    // 0x8007FA58: nop

        goto L_8007FA5C;
    // 0x8007FA58: nop

L_8007FA5C:
    // 0x8007FA5C: jr          $ra
    // 0x8007FA60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007FA60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80009484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009484: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80009488: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000948C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009490: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80009494: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009498: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8000949C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800094A0: nop

    // 0x800094A4: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800094A8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800094AC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800094B0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800094B4: lw          $t9, 0x34C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34C);
    // 0x800094B8: nop

    // 0x800094BC: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800094C0: beq         $t0, $zero, L_800094F0
    if (ctx->r8 == 0) {
        // 0x800094C4: nop
    
            goto L_800094F0;
    }
    // 0x800094C4: nop

    // 0x800094C8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800094CC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800094D0: jal         0x800B1BC8
    // 0x800094D4: nop

    func_800B1BC8(rdram, ctx);
        goto after_0;
    // 0x800094D4: nop

    after_0:
    // 0x800094D8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800094DC: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x800094E0: lw          $t2, 0x34C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34C);
    // 0x800094E4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800094E8: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800094EC: sw          $t3, 0x34C($t1)
    MEM_W(0X34C, ctx->r9) = ctx->r11;
L_800094F0:
    // 0x800094F0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800094F4: nop

    // 0x800094F8: bne         $t4, $zero, L_80009508
    if (ctx->r12 != 0) {
        // 0x800094FC: nop
    
            goto L_80009508;
    }
    // 0x800094FC: nop

    // 0x80009500: b           L_80009748
    // 0x80009504: nop

        goto L_80009748;
    // 0x80009504: nop

L_80009508:
    // 0x80009508: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8000950C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80009510: lw          $t6, 0x344($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X344);
    // 0x80009514: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009518: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000951C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80009520: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80009524: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80009528: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8000952C: nop

    // 0x80009530: beq         $t0, $at, L_80009740
    if (ctx->r8 == ctx->r1) {
        // 0x80009534: nop
    
            goto L_80009740;
    }
    // 0x80009534: nop

    // 0x80009538: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000953C: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x80009540: lw          $t3, 0x34C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34C);
    // 0x80009544: nop

    // 0x80009548: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8000954C: sw          $t1, 0x34C($t2)
    MEM_W(0X34C, ctx->r10) = ctx->r9;
    // 0x80009550: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80009554: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80009558: jal         0x800B1B04
    // 0x8000955C: nop

    func_800B1B04(rdram, ctx);
        goto after_1;
    // 0x8000955C: nop

    after_1:
    // 0x80009560: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80009564: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80009568: lw          $t5, 0x344($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X344);
    // 0x8000956C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009570: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80009574: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80009578: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8000957C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80009580: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x80009584: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x80009588: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8000958C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009590: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80009594: ori         $t0, $a2, 0x245
    ctx->r8 = ctx->r6 | 0X245;
    // 0x80009598: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000959C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800095A0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800095A4: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800095A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800095AC: jal         0x800B1F0C
    // 0x800095B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_2;
    // 0x800095B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800095B4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800095B8: addiu       $at, $zero, -0x849
    ctx->r1 = ADD32(0, -0X849);
    // 0x800095BC: lw          $t1, 0xC0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0XC0);
    // 0x800095C0: nop

    // 0x800095C4: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800095C8: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x800095CC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800095D0: nop

    // 0x800095D4: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x800095D8: nop

    // 0x800095DC: ori         $t6, $t5, 0x14
    ctx->r14 = ctx->r13 | 0X14;
    // 0x800095E0: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x800095E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800095E8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800095EC: nop

    // 0x800095F0: swc1        $f8, 0xF0($t7)
    MEM_W(0XF0, ctx->r15) = ctx->f8.u32l;
    // 0x800095F4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800095F8: nop

    // 0x800095FC: lwc1        $f20, 0xF0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x80009600: nop

    // 0x80009604: swc1        $f20, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f20.u32l;
    // 0x80009608: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8000960C: nop

    // 0x80009610: swc1        $f20, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f20.u32l;
    // 0x80009614: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80009618: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8000961C: sw          $t8, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r24;
    // 0x80009620: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80009624: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80009628: sh          $t2, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r10;
    // 0x8000962C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80009630: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80009634: lwc1        $f10, 0x32C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X32C);
    // 0x80009638: nop

    // 0x8000963C: swc1        $f10, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f10.u32l;
    // 0x80009640: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80009644: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80009648: lwc1        $f16, 0x330($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X330);
    // 0x8000964C: nop

    // 0x80009650: swc1        $f16, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f16.u32l;
    // 0x80009654: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80009658: nop

    // 0x8000965C: lwc1        $f18, 0x32C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X32C);
    // 0x80009660: nop

    // 0x80009664: swc1        $f18, 0x1A4($t9)
    MEM_W(0X1A4, ctx->r25) = ctx->f18.u32l;
    // 0x80009668: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000966C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80009670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009674: lwc1        $f4, 0x330($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X330);
    // 0x80009678: nop

    // 0x8000967C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80009680: swc1        $f8, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->f8.u32l;
    // 0x80009684: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80009688: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000968C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80009690: nop

    // 0x80009694: swc1        $f10, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->f10.u32l;
    // 0x80009698: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000969C: nop

    // 0x800096A0: lwc1        $f16, 0x1A4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X1A4);
    // 0x800096A4: lwc1        $f18, 0x32C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X32C);
    // 0x800096A8: lwc1        $f6, 0x1A0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X1A0);
    // 0x800096AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800096B0: nop

    // 0x800096B4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800096B8: swc1        $f8, 0x1AC($t1)
    MEM_W(0X1AC, ctx->r9) = ctx->f8.u32l;
    // 0x800096BC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800096C0: nop

    // 0x800096C4: lwc1        $f10, 0x1A8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X1A8);
    // 0x800096C8: lwc1        $f16, 0x330($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X330);
    // 0x800096CC: lwc1        $f4, 0x1A0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X1A0);
    // 0x800096D0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800096D4: nop

    // 0x800096D8: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800096DC: swc1        $f6, 0x1B0($t2)
    MEM_W(0X1B0, ctx->r10) = ctx->f6.u32l;
    // 0x800096E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800096E4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800096E8: nop

    // 0x800096EC: swc1        $f8, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->f8.u32l;
    // 0x800096F0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800096F4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800096F8: lwc1        $f16, 0x1A0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X1A0);
    // 0x800096FC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80009700: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009704: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80009708: nop

    // 0x8000970C: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80009710: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80009714: swc1        $f6, 0x1B4($t5)
    MEM_W(0X1B4, ctx->r13) = ctx->f6.u32l;
    // 0x80009718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000971C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009720: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80009724: nop

    // 0x80009728: swc1        $f8, 0x1B8($t6)
    MEM_W(0X1B8, ctx->r14) = ctx->f8.u32l;
    // 0x8000972C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009730: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80009734: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80009738: nop

    // 0x8000973C: swc1        $f16, 0x1BC($t4)
    MEM_W(0X1BC, ctx->r12) = ctx->f16.u32l;
L_80009740:
    // 0x80009740: b           L_80009748
    // 0x80009744: nop

        goto L_80009748;
    // 0x80009744: nop

L_80009748:
    // 0x80009748: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000974C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80009750: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80009754: jr          $ra
    // 0x80009758: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80009758: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void alSndpSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA110: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA118: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CA11C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800CA120: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800CA124: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x800CA128: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA12C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800CA130: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x800CA134: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CA138: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800CA13C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800CA140: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800CA144: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800CA148: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA14C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA150: jal         0x800D3A2C
    // 0x800CA154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CA158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA15C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA160: jr          $ra
    // 0x800CA164: nop

    return;
    // 0x800CA164: nop

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
RECOMP_FUNC void func_80017438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017438: jr          $ra
    // 0x8001743C: nop

    return;
    // 0x8001743C: nop

    // 0x80017440: jr          $ra
    // 0x80017444: nop

    return;
    // 0x80017444: nop

;}
RECOMP_FUNC void func_800831E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800831E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800831E8: jal         0x800BC6EC
    // 0x800831EC: addiu       $a0, $zero, 0xC30
    ctx->r4 = ADD32(0, 0XC30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800831EC: addiu       $a0, $zero, 0xC30
    ctx->r4 = ADD32(0, 0XC30);
    after_0:
    // 0x800831F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800831F4: sw          $v0, 0x7B4C($at)
    MEM_W(0X7B4C, ctx->r1) = ctx->r2;
    // 0x800831F8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800831FC: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x80083200: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80083204: bne         $t6, $at, L_80083244
    if (ctx->r14 != ctx->r1) {
        // 0x80083208: nop
    
            goto L_80083244;
    }
    // 0x80083208: nop

    // 0x8008320C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80083210: lh          $t7, 0x72B4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X72B4);
    // 0x80083214: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80083218: bne         $t7, $at, L_80083244
    if (ctx->r15 != ctx->r1) {
        // 0x8008321C: nop
    
            goto L_80083244;
    }
    // 0x8008321C: nop

    // 0x80083220: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083224: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083228: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8008322C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80083230: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083234: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083238: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008323C: b           L_8008326C
    // 0x80083240: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
        goto L_8008326C;
    // 0x80083240: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
L_80083244:
    // 0x80083244: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083248: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x8008324C: nop

    // 0x80083250: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x80083254: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083258: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x8008325C: nop

    // 0x80083260: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x80083264: jal         0x80021ED0
    // 0x80083268: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_1;
    // 0x80083268: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_1:
L_8008326C:
    // 0x8008326C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083270: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083274: nop

    // 0x80083278: sh          $zero, 0x2($t4)
    MEM_H(0X2, ctx->r12) = 0;
    // 0x8008327C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083280: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083284: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80083288: jal         0x8008A964
    // 0x8008328C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_8008A964(rdram, ctx);
        goto after_2;
    // 0x8008328C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_2:
    // 0x80083290: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083294: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083298: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x8008329C: jal         0x8008A964
    // 0x800832A0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8008A964(rdram, ctx);
        goto after_3;
    // 0x800832A0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_3:
    // 0x800832A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800832A8: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800832AC: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x800832B0: jal         0x8008A964
    // 0x800832B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_8008A964(rdram, ctx);
        goto after_4;
    // 0x800832B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_4:
    // 0x800832B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800832BC: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x800832C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800832C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800832C8: swc1        $f4, 0x744($t5)
    MEM_W(0X744, ctx->r13) = ctx->f4.u32l;
    // 0x800832CC: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x800832D0: nop

    // 0x800832D4: lwc1        $f6, 0x744($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X744);
    // 0x800832D8: nop

    // 0x800832DC: swc1        $f6, 0x740($t6)
    MEM_W(0X740, ctx->r14) = ctx->f6.u32l;
    // 0x800832E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800832E4: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800832E8: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x800832EC: lwc1        $f8, 0x740($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X740);
    // 0x800832F0: ori         $a2, $a2, 0x229
    ctx->r6 = ctx->r6 | 0X229;
    // 0x800832F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800832F8: lwc1        $f10, 0x744($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X744);
    // 0x800832FC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80083300: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x80083304: addiu       $a0, $t7, 0x3C
    ctx->r4 = ADD32(ctx->r15, 0X3C);
    // 0x80083308: addiu       $a1, $t7, 0x40
    ctx->r5 = ADD32(ctx->r15, 0X40);
    // 0x8008330C: jal         0x800B202C
    // 0x80083310: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B202C(rdram, ctx);
        goto after_5;
    // 0x80083310: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80083314: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083318: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x8008331C: nop

    // 0x80083320: sh          $v0, 0x46($t8)
    MEM_H(0X46, ctx->r24) = ctx->r2;
    // 0x80083324: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083328: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x8008332C: nop

    // 0x80083330: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80083334: nop

    // 0x80083338: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x8008333C: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x80083340: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083344: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008334C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80083350: jal         0x8008AAA8
    // 0x80083354: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_8008AAA8(rdram, ctx);
        goto after_6;
    // 0x80083354: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_6:
    // 0x80083358: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008335C: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083360: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80083364: sh          $t2, 0x160($t3)
    MEM_H(0X160, ctx->r11) = ctx->r10;
    // 0x80083368: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008336C: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083370: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083374: sh          $zero, 0x164($t4)
    MEM_H(0X164, ctx->r12) = 0;
    // 0x80083378: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x8008337C: nop

    // 0x80083380: lh          $t6, 0x164($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X164);
    // 0x80083384: nop

    // 0x80083388: sh          $t6, 0x162($t5)
    MEM_H(0X162, ctx->r13) = ctx->r14;
    // 0x8008338C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083390: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083394: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80083398: sw          $t7, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->r15;
    // 0x8008339C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800833A0:
    // 0x800833A0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800833A4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800833A8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x800833AC: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x800833B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800833B4: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x800833B8: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x800833BC: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800833C0: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x800833C4: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    // 0x800833C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800833CC: jal         0x8008AAA8
    // 0x800833D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8008AAA8(rdram, ctx);
        goto after_7;
    // 0x800833D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800833D4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800833D8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800833DC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800833E0: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800833E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800833E8: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x800833EC: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800833F0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800833F4: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x800833F8: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800833FC: sh          $t2, 0x2C2($t5)
    MEM_H(0X2C2, ctx->r13) = ctx->r10;
    // 0x80083400: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80083404: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083408: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8008340C: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80083410: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80083414: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083418: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8008341C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80083420: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80083424: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80083428: sh          $t7, 0x2C4($t9)
    MEM_H(0X2C4, ctx->r25) = ctx->r15;
    // 0x8008342C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80083430: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083434: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80083438: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x8008343C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083440: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083444: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80083448: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8008344C: addu        $t2, $t4, $t6
    ctx->r10 = ADD32(ctx->r12, ctx->r14);
    // 0x80083450: sh          $zero, 0x2C0($t2)
    MEM_H(0X2C0, ctx->r10) = 0;
    // 0x80083454: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80083458: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008345C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80083460: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x80083464: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80083468: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x8008346C: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x80083470: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80083474: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x80083478: lw          $t7, 0x268($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X268);
    // 0x8008347C: nop

    // 0x80083480: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x80083484: sw          $t9, 0x268($t0)
    MEM_W(0X268, ctx->r8) = ctx->r25;
    // 0x80083488: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008348C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083490: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80083494: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x80083498: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008349C: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x800834A0: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x800834A4: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800834A8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800834AC: addu        $t1, $t4, $t2
    ctx->r9 = ADD32(ctx->r12, ctx->r10);
    // 0x800834B0: sw          $t3, 0x270($t1)
    MEM_W(0X270, ctx->r9) = ctx->r11;
    // 0x800834B4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800834B8: nop

    // 0x800834BC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800834C0: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800834C4: bne         $at, $zero, L_800833A0
    if (ctx->r1 != 0) {
        // 0x800834C8: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_800833A0;
    }
    // 0x800834C8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800834CC: jal         0x800BC6EC
    // 0x800834D0: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800834D0: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    after_8:
    // 0x800834D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800834D8: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800834DC: nop

    // 0x800834E0: sw          $v0, 0x728($t7)
    MEM_W(0X728, ctx->r15) = ctx->r2;
    // 0x800834E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800834E8: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x800834EC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800834F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800834F4: lw          $t0, 0x728($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X728);
    // 0x800834F8: nop

    // 0x800834FC: swc1        $f16, 0x1B0($t0)
    MEM_W(0X1B0, ctx->r8) = ctx->f16.u32l;
    // 0x80083500: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083504: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083508: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x8008350C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80083510: lw          $t4, 0x728($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X728);
    // 0x80083514: nop

    // 0x80083518: swc1        $f18, 0x1B4($t4)
    MEM_W(0X1B4, ctx->r12) = ctx->f18.u32l;
    // 0x8008351C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083520: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083524: nop

    // 0x80083528: lw          $a0, 0x728($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X728);
    // 0x8008352C: jal         0x8001A690
    // 0x80083530: nop

    func_8001A690(rdram, ctx);
        goto after_9;
    // 0x80083530: nop

    after_9:
    // 0x80083534: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083538: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x8008353C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80083540: lw          $t5, 0x728($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X728);
    // 0x80083544: nop

    // 0x80083548: sh          $t3, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r11;
    // 0x8008354C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083550: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083554: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80083558: lw          $t7, 0x728($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X728);
    // 0x8008355C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083560: swc1        $f4, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f4.u32l;
    // 0x80083564: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083568: nop

    // 0x8008356C: lw          $t0, 0x728($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X728);
    // 0x80083570: nop

    // 0x80083574: lwc1        $f6, 0xD0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80083578: nop

    // 0x8008357C: swc1        $f6, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f6.u32l;
    // 0x80083580: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083584: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083588: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8008358C: lw          $t2, 0x728($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X728);
    // 0x80083590: nop

    // 0x80083594: sw          $t6, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r14;
    // 0x80083598: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008359C: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x800835A0: nop

    // 0x800835A4: lw          $a0, 0x728($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X728);
    // 0x800835A8: jal         0x8008C0A4
    // 0x800835AC: nop

    func_8008C0A4(rdram, ctx);
        goto after_10;
    // 0x800835AC: nop

    after_10:
    // 0x800835B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800835B4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800835B8: jal         0x8008ABB4
    // 0x800835BC: nop

    func_8008ABB4(rdram, ctx);
        goto after_11;
    // 0x800835BC: nop

    after_11:
    // 0x800835C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800835C4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800835C8: jal         0x8008AD88
    // 0x800835CC: nop

    func_8008AD88(rdram, ctx);
        goto after_12;
    // 0x800835CC: nop

    after_12:
    // 0x800835D0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800835D4: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x800835D8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800835DC: sh          $t3, 0x73C($t5)
    MEM_H(0X73C, ctx->r13) = ctx->r11;
    // 0x800835E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800835E4: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x800835E8: nop

    // 0x800835EC: sh          $zero, 0xBD8($t8)
    MEM_H(0XBD8, ctx->r24) = 0;
    // 0x800835F0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800835F4: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800835F8: nop

    // 0x800835FC: sh          $zero, 0xBEC($t7)
    MEM_H(0XBEC, ctx->r15) = 0;
    // 0x80083600: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80083604:
    // 0x80083604: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80083608: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008360C: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083610: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80083614: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80083618: sw          $zero, 0xC04($t6)
    MEM_W(0XC04, ctx->r14) = 0;
    // 0x8008361C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80083620: nop

    // 0x80083624: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80083628: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8008362C: bne         $at, $zero, L_80083604
    if (ctx->r1 != 0) {
        // 0x80083630: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80083604;
    }
    // 0x80083630: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80083634: jal         0x800BC6EC
    // 0x80083638: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_13;
    // 0x80083638: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    after_13:
    // 0x8008363C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083640: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083644: nop

    // 0x80083648: sw          $v0, 0xC10($t3)
    MEM_W(0XC10, ctx->r11) = ctx->r2;
    // 0x8008364C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083650: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083654: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80083658: nop

    // 0x8008365C: swc1        $f8, 0xBD4($t5)
    MEM_W(0XBD4, ctx->r13) = ctx->f8.u32l;
    // 0x80083660: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80083664: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083668: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x8008366C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083670: nop

    // 0x80083674: swc1        $f10, 0xC24($t8)
    MEM_W(0XC24, ctx->r24) = ctx->f10.u32l;
    // 0x80083678: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8008367C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80083680: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x80083684: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80083688: nop

    // 0x8008368C: swc1        $f16, 0xC28($t7)
    MEM_W(0XC28, ctx->r15) = ctx->f16.u32l;
    // 0x80083690: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80083694: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80083698: lhu         $t9, 0x4($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X4);
    // 0x8008369C: addiu       $at, $zero, -0x19
    ctx->r1 = ADD32(0, -0X19);
    // 0x800836A0: and         $t4, $t9, $at
    ctx->r12 = ctx->r25 & ctx->r1;
    // 0x800836A4: sh          $t4, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r12;
    // 0x800836A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800836AC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800836B0: lhu         $t2, 0x4($t6)
    ctx->r10 = MEM_HU(ctx->r14, 0X4);
    // 0x800836B4: nop

    // 0x800836B8: ori         $t1, $t2, 0x1
    ctx->r9 = ctx->r10 | 0X1;
    // 0x800836BC: sh          $t1, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r9;
    // 0x800836C0: jal         0x8003168C
    // 0x800836C4: nop

    func_8003168C(rdram, ctx);
        goto after_14;
    // 0x800836C4: nop

    after_14:
    // 0x800836C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800836CC: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x800836D0: jal         0x80088CC4
    // 0x800836D4: nop

    func_80088CC4(rdram, ctx);
        goto after_15;
    // 0x800836D4: nop

    after_15:
    // 0x800836D8: jal         0x80031C34
    // 0x800836DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C34(rdram, ctx);
        goto after_16;
    // 0x800836DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x800836E0: b           L_800836F0
    // 0x800836E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800836F0;
    // 0x800836E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800836E8: b           L_800836F0
    // 0x800836EC: nop

        goto L_800836F0;
    // 0x800836EC: nop

L_800836F0:
    // 0x800836F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800836F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800836F8: jr          $ra
    // 0x800836FC: nop

    return;
    // 0x800836FC: nop

;}
RECOMP_FUNC void func_80069648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006964C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069650: jal         0x80061348
    // 0x80069654: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069654: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x80069658: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006965C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069660: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069664: beq         $v0, $zero, L_800696A4
    if (ctx->r2 == 0) {
        // 0x80069668: nop
    
            goto L_800696A4;
    }
    // 0x80069668: nop

    // 0x8006966C: jal         0x80061348
    // 0x80069670: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069670: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x80069674: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069678: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006967C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069680: beq         $v0, $zero, L_800696A4
    if (ctx->r2 == 0) {
        // 0x80069684: nop
    
            goto L_800696A4;
    }
    // 0x80069684: nop

    // 0x80069688: jal         0x80061348
    // 0x8006968C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006968C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x80069690: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069694: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069698: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006969C: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x800696A0: nop
    
            goto L_800698E8;
    }
    // 0x800696A0: nop

L_800696A4:
    // 0x800696A4: jal         0x80061348
    // 0x800696A8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800696A8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x800696AC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800696B0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800696B4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800696B8: beq         $v0, $zero, L_800696F8
    if (ctx->r2 == 0) {
        // 0x800696BC: nop
    
            goto L_800696F8;
    }
    // 0x800696BC: nop

    // 0x800696C0: jal         0x80061348
    // 0x800696C4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x800696C4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x800696C8: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x800696CC: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800696D0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800696D4: beq         $v0, $zero, L_800696F8
    if (ctx->r2 == 0) {
        // 0x800696D8: nop
    
            goto L_800696F8;
    }
    // 0x800696D8: nop

    // 0x800696DC: jal         0x80061348
    // 0x800696E0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x800696E0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x800696E4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x800696E8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x800696EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800696F0: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x800696F4: nop
    
            goto L_800698E8;
    }
    // 0x800696F4: nop

L_800696F8:
    // 0x800696F8: jal         0x80061348
    // 0x800696FC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800696FC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x80069700: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069704: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069708: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006970C: beq         $v0, $zero, L_8006974C
    if (ctx->r2 == 0) {
        // 0x80069710: nop
    
            goto L_8006974C;
    }
    // 0x80069710: nop

    // 0x80069714: jal         0x80061348
    // 0x80069718: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x80069718: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006971C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069720: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069724: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069728: beq         $v0, $zero, L_8006974C
    if (ctx->r2 == 0) {
        // 0x8006972C: nop
    
            goto L_8006974C;
    }
    // 0x8006972C: nop

    // 0x80069730: jal         0x80061348
    // 0x80069734: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x80069734: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x80069738: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006973C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069740: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069744: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x80069748: nop
    
            goto L_800698E8;
    }
    // 0x80069748: nop

L_8006974C:
    // 0x8006974C: jal         0x80061348
    // 0x80069750: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x80069750: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x80069754: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069758: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006975C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069760: beq         $v0, $zero, L_800697A0
    if (ctx->r2 == 0) {
        // 0x80069764: nop
    
            goto L_800697A0;
    }
    // 0x80069764: nop

    // 0x80069768: jal         0x80061348
    // 0x8006976C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006976C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x80069770: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069774: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006977C: beq         $v0, $zero, L_800697A0
    if (ctx->r2 == 0) {
        // 0x80069780: nop
    
            goto L_800697A0;
    }
    // 0x80069780: nop

    // 0x80069784: jal         0x80061348
    // 0x80069788: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x80069788: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006978C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069790: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069794: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069798: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x8006979C: nop
    
            goto L_800698E8;
    }
    // 0x8006979C: nop

L_800697A0:
    // 0x800697A0: jal         0x80061348
    // 0x800697A4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x800697A4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x800697A8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800697AC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800697B0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800697B4: beq         $v0, $zero, L_800697F4
    if (ctx->r2 == 0) {
        // 0x800697B8: nop
    
            goto L_800697F4;
    }
    // 0x800697B8: nop

    // 0x800697BC: jal         0x80061348
    // 0x800697C0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x800697C0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x800697C4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800697C8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800697CC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800697D0: beq         $v0, $zero, L_800697F4
    if (ctx->r2 == 0) {
        // 0x800697D4: nop
    
            goto L_800697F4;
    }
    // 0x800697D4: nop

    // 0x800697D8: jal         0x80061348
    // 0x800697DC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x800697DC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x800697E0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x800697E4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800697E8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800697EC: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x800697F0: nop
    
            goto L_800698E8;
    }
    // 0x800697F0: nop

L_800697F4:
    // 0x800697F4: jal         0x80061348
    // 0x800697F8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x800697F8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x800697FC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069800: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069804: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069808: beq         $v0, $zero, L_80069848
    if (ctx->r2 == 0) {
        // 0x8006980C: nop
    
            goto L_80069848;
    }
    // 0x8006980C: nop

    // 0x80069810: jal         0x80061348
    // 0x80069814: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069814: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069818: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006981C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069820: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069824: beq         $v0, $zero, L_80069848
    if (ctx->r2 == 0) {
        // 0x80069828: nop
    
            goto L_80069848;
    }
    // 0x80069828: nop

    // 0x8006982C: jal         0x80061348
    // 0x80069830: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x80069830: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x80069834: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069838: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006983C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069840: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x80069844: nop
    
            goto L_800698E8;
    }
    // 0x80069844: nop

L_80069848:
    // 0x80069848: jal         0x80061348
    // 0x8006984C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006984C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x80069850: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x80069854: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069858: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006985C: beq         $v0, $zero, L_8006989C
    if (ctx->r2 == 0) {
        // 0x80069860: nop
    
            goto L_8006989C;
    }
    // 0x80069860: nop

    // 0x80069864: jal         0x80061348
    // 0x80069868: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x80069868: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006986C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069870: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80069874: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069878: beq         $v0, $zero, L_8006989C
    if (ctx->r2 == 0) {
        // 0x8006987C: nop
    
            goto L_8006989C;
    }
    // 0x8006987C: nop

    // 0x80069880: jal         0x80061348
    // 0x80069884: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x80069884: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x80069888: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006988C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069890: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069894: bne         $v0, $zero, L_800698E8
    if (ctx->r2 != 0) {
        // 0x80069898: nop
    
            goto L_800698E8;
    }
    // 0x80069898: nop

L_8006989C:
    // 0x8006989C: jal         0x80061348
    // 0x800698A0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x800698A0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x800698A4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800698A8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800698AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800698B0: beq         $v0, $zero, L_800698E8
    if (ctx->r2 == 0) {
        // 0x800698B4: nop
    
            goto L_800698E8;
    }
    // 0x800698B4: nop

    // 0x800698B8: jal         0x80061348
    // 0x800698BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x800698BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x800698C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800698C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800698C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800698CC: beq         $v0, $zero, L_800698E8
    if (ctx->r2 == 0) {
        // 0x800698D0: nop
    
            goto L_800698E8;
    }
    // 0x800698D0: nop

    // 0x800698D4: jal         0x80061348
    // 0x800698D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x800698D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x800698DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800698E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800698E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800698E8:
    // 0x800698E8: b           L_800698F8
    // 0x800698EC: nop

        goto L_800698F8;
    // 0x800698EC: nop

    // 0x800698F0: b           L_800698F8
    // 0x800698F4: nop

        goto L_800698F8;
    // 0x800698F4: nop

L_800698F8:
    // 0x800698F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800698FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069900: jr          $ra
    // 0x80069904: nop

    return;
    // 0x80069904: nop

;}
RECOMP_FUNC void func_80068DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068DA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068DAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068DB0: nop

    // 0x80068DB4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068DB8: nop

    // 0x80068DBC: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068DC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068DC4: jr          $ra
    // 0x80068DC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068DC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068DCC: jr          $ra
    // 0x80068DD0: nop

    return;
    // 0x80068DD0: nop

    // 0x80068DD4: jr          $ra
    // 0x80068DD8: nop

    return;
    // 0x80068DD8: nop

;}
RECOMP_FUNC void func_800974C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800974C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800974C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800974C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800974CC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800974D0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800974D4: lw          $t7, 0x280($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X280);
    // 0x800974D8: nop

    // 0x800974DC: beq         $t7, $zero, L_8009753C
    if (ctx->r15 == 0) {
        // 0x800974E0: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_8009753C;
    }
    // 0x800974E0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800974E4:
    // 0x800974E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800974E8: nop

    // 0x800974EC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800974F0: nop

    // 0x800974F4: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x800974F8: beq         $t0, $zero, L_80097524
    if (ctx->r8 == 0) {
        // 0x800974FC: nop
    
            goto L_80097524;
    }
    // 0x800974FC: nop

    // 0x80097500: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80097504: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80097508: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x8009750C: jal         0x800C4AA0
    // 0x80097510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80097510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80097514: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80097518: nop

    // 0x8009751C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80097520: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_80097524:
    // 0x80097524: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80097528: nop

    // 0x8009752C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80097530: nop

    // 0x80097534: bne         $t5, $zero, L_800974E4
    if (ctx->r13 != 0) {
        // 0x80097538: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_800974E4;
    }
    // 0x80097538: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
L_8009753C:
    // 0x8009753C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80097540: nop

    // 0x80097544: beq         $t6, $zero, L_80097554
    if (ctx->r14 == 0) {
        // 0x80097548: nop
    
            goto L_80097554;
    }
    // 0x80097548: nop

    // 0x8009754C: jal         0x800C4BF0
    // 0x80097550: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80097550: nop

    after_1:
L_80097554:
    // 0x80097554: b           L_8009755C
    // 0x80097558: nop

        goto L_8009755C;
    // 0x80097558: nop

L_8009755C:
    // 0x8009755C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097564: jr          $ra
    // 0x80097568: nop

    return;
    // 0x80097568: nop

;}
RECOMP_FUNC void func_8006C150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C158: jal         0x8005F064
    // 0x8006C15C: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C15C: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_0:
    // 0x8006C160: b           L_8006C170
    // 0x8006C164: nop

        goto L_8006C170;
    // 0x8006C164: nop

    // 0x8006C168: b           L_8006C170
    // 0x8006C16C: nop

        goto L_8006C170;
    // 0x8006C16C: nop

L_8006C170:
    // 0x8006C170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C178: jr          $ra
    // 0x8006C17C: nop

    return;
    // 0x8006C17C: nop

;}
RECOMP_FUNC void func_80067E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067E70: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067E74: nop

    // 0x80067E78: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067E7C: nop

    // 0x80067E80: slti        $t7, $v0, 0x190
    ctx->r15 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80067E84: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067E88: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067E8C: beq         $v0, $zero, L_80067EA8
    if (ctx->r2 == 0) {
        // 0x80067E90: nop
    
            goto L_80067EA8;
    }
    // 0x80067E90: nop

    // 0x80067E94: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x80067E98: nop

    // 0x80067E9C: slti        $t8, $v0, 0x190
    ctx->r24 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80067EA0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067EA4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067EA8:
    // 0x80067EA8: jr          $ra
    // 0x80067EAC: nop

    return;
    // 0x80067EAC: nop

    // 0x80067EB0: jr          $ra
    // 0x80067EB4: nop

    return;
    // 0x80067EB4: nop

    // 0x80067EB8: jr          $ra
    // 0x80067EBC: nop

    return;
    // 0x80067EBC: nop

;}
RECOMP_FUNC void func_8006B8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B8EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B8F0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B8F4: nop

    // 0x8006B8F8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B8FC: nop

    // 0x8006B900: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006B904: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B908: jr          $ra
    // 0x8006B90C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B90C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B910: jr          $ra
    // 0x8006B914: nop

    return;
    // 0x8006B914: nop

    // 0x8006B918: jr          $ra
    // 0x8006B91C: nop

    return;
    // 0x8006B91C: nop

;}
RECOMP_FUNC void alCSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA444: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CA44C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CA450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA454: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800CA458: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800CA45C: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x800CA460: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800CA464: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800CA468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA46C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
L_800CA470:
    // 0x800CA470: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x800CA474: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CA478: beql        $t8, $zero, L_800CA4BC
    if (ctx->r24 == 0) {
        // 0x800CA47C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800CA4BC;
    }
    goto skip_0;
    // 0x800CA47C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800CA480: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x800CA484: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800CA488: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800CA48C: beql        $t6, $zero, L_800CA4A4
    if (ctx->r14 == 0) {
        // 0x800CA490: lw          $a0, 0xB8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XB8);
            goto L_800CA4A4;
    }
    goto skip_1;
    // 0x800CA490: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
    skip_1:
    // 0x800CA494: lw          $t7, 0xB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB8);
    // 0x800CA498: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x800CA49C: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x800CA4A0: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
L_800CA4A4:
    // 0x800CA4A4: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x800CA4A8: beql        $at, $zero, L_800CA4BC
    if (ctx->r1 == 0) {
        // 0x800CA4AC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800CA4BC;
    }
    goto skip_2;
    // 0x800CA4AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800CA4B0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800CA4B4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800CA4B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800CA4BC:
    // 0x800CA4BC: bnel        $v0, $a1, L_800CA470
    if (ctx->r2 != ctx->r5) {
        // 0x800CA4C0: lw          $t6, 0x4($t4)
        ctx->r14 = MEM_W(ctx->r12, 0X4);
            goto L_800CA470;
    }
    goto skip_3;
    // 0x800CA4C0: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    skip_3:
    // 0x800CA4C4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA4C8: jal         0x800CA320
    // 0x800CA4CC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_0;
    // 0x800CA4CC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800CA4D0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800CA4D4: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800CA4D8: bne         $v0, $at, L_800CA644
    if (ctx->r2 != ctx->r1) {
        // 0x800CA4DC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800CA644;
    }
    // 0x800CA4DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CA4E0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA4E4: jal         0x800CA320
    // 0x800CA4E8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_1;
    // 0x800CA4E8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800CA4EC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800CA4F0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800CA4F4: bne         $v0, $at, L_800CA548
    if (ctx->r2 != ctx->r1) {
        // 0x800CA4F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800CA548;
    }
    // 0x800CA4F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CA4FC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800CA500: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800CA504: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800CA508: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x800CA50C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA510: jal         0x800CA320
    // 0x800CA514: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_2;
    // 0x800CA514: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x800CA518: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800CA51C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA520: jal         0x800CA320
    // 0x800CA524: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_3;
    // 0x800CA524: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x800CA528: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x800CA52C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA530: jal         0x800CA320
    // 0x800CA534: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_4;
    // 0x800CA534: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x800CA538: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x800CA53C: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800CA540: b           L_800CA6E0
    // 0x800CA544: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_800CA6E0;
    // 0x800CA544: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_800CA548:
    // 0x800CA548: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800CA54C: bnel        $v1, $at, L_800CA588
    if (ctx->r3 != ctx->r1) {
        // 0x800CA550: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800CA588;
    }
    goto skip_4;
    // 0x800CA550: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x800CA554: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800CA558: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CA55C: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x800CA560: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x800CA564: beq         $t6, $zero, L_800CA578
    if (ctx->r14 == 0) {
        // 0x800CA568: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_800CA578;
    }
    // 0x800CA568: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800CA56C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x800CA570: b           L_800CA6E0
    // 0x800CA574: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800CA6E0;
    // 0x800CA574: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800CA578:
    // 0x800CA578: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800CA57C: b           L_800CA6E0
    // 0x800CA580: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_800CA6E0;
    // 0x800CA580: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800CA584: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800CA588:
    // 0x800CA588: bne         $v1, $at, L_800CA5B8
    if (ctx->r3 != ctx->r1) {
        // 0x800CA58C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800CA5B8;
    }
    // 0x800CA58C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA590: jal         0x800CA320
    // 0x800CA594: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_5;
    // 0x800CA594: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x800CA598: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA59C: jal         0x800CA320
    // 0x800CA5A0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_6;
    // 0x800CA5A0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x800CA5A4: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800CA5A8: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800CA5AC: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x800CA5B0: b           L_800CA6E0
    // 0x800CA5B4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800CA6E0;
    // 0x800CA5B4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800CA5B8:
    // 0x800CA5B8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800CA5BC: bne         $v1, $at, L_800CA6E0
    if (ctx->r3 != ctx->r1) {
        // 0x800CA5C0: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_800CA6E0;
    }
    // 0x800CA5C0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800CA5C4: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x800CA5C8: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x800CA5CC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800CA5D0: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800CA5D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CA5D8: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800CA5DC: bne         $a0, $zero, L_800CA5F0
    if (ctx->r4 != 0) {
        // 0x800CA5E0: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_800CA5F0;
    }
    // 0x800CA5E0: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x800CA5E4: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800CA5E8: b           L_800CA630
    // 0x800CA5EC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_800CA630;
    // 0x800CA5EC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800CA5F0:
    // 0x800CA5F0: beq         $a0, $at, L_800CA5FC
    if (ctx->r4 == ctx->r1) {
        // 0x800CA5F4: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800CA5FC;
    }
    // 0x800CA5F4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800CA5F8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_800CA5FC:
    // 0x800CA5FC: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800CA600: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800CA604: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800CA608: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800CA60C: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x800CA610: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800CA614: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800CA618: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800CA61C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800CA620: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800CA624: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800CA628: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800CA62C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800CA630:
    // 0x800CA630: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800CA634: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800CA638: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x800CA63C: b           L_800CA6E0
    // 0x800CA640: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800CA6E0;
    // 0x800CA640: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800CA644:
    // 0x800CA644: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CA648: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x800CA64C: beq         $t9, $zero, L_800CA674
    if (ctx->r25 == 0) {
        // 0x800CA650: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_800CA674;
    }
    // 0x800CA650: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800CA654: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800CA658: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA65C: jal         0x800CA320
    // 0x800CA660: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_7;
    // 0x800CA660: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x800CA664: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800CA668: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800CA66C: b           L_800CA684
    // 0x800CA670: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
        goto L_800CA684;
    // 0x800CA670: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
L_800CA674:
    // 0x800CA674: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x800CA678: lbu         $t7, 0xA8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA8);
    // 0x800CA67C: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800CA680: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_800CA684:
    // 0x800CA684: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800CA688: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800CA68C: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800CA690: beq         $t9, $at, L_800CA6DC
    if (ctx->r25 == ctx->r1) {
        // 0x800CA694: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800CA6DC;
    }
    // 0x800CA694: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800CA698: beq         $t9, $at, L_800CA6DC
    if (ctx->r25 == ctx->r1) {
        // 0x800CA69C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800CA6DC;
    }
    // 0x800CA69C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA6A0: jal         0x800CA320
    // 0x800CA6A4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800CA320(rdram, ctx);
        goto after_8;
    // 0x800CA6A4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x800CA6A8: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x800CA6AC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x800CA6B0: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x800CA6B4: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x800CA6B8: bne         $t8, $at, L_800CA6E0
    if (ctx->r24 != ctx->r1) {
        // 0x800CA6BC: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_800CA6E0;
    }
    // 0x800CA6BC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800CA6C0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800CA6C4: jal         0x800CA3E4
    // 0x800CA6C8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    static_5_800CA3E4(rdram, ctx);
        goto after_9;
    // 0x800CA6C8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x800CA6CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CA6D0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800CA6D4: b           L_800CA6E0
    // 0x800CA6D8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_800CA6E0;
    // 0x800CA6D8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_800CA6DC:
    // 0x800CA6DC: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_800CA6E0:
    // 0x800CA6E0: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800CA6E4: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x800CA6E8: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x800CA6EC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800CA6F0: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800CA6F4: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x800CA6F8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800CA6FC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800CA700: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800CA704: beql        $t6, $at, L_800CA724
    if (ctx->r14 == ctx->r1) {
        // 0x800CA708: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800CA724;
    }
    goto skip_5;
    // 0x800CA708: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_5:
    // 0x800CA70C: jal         0x800CA3E4
    // 0x800CA710: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    static_5_800CA3E4(rdram, ctx);
        goto after_10;
    // 0x800CA710: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800CA714: lw          $t7, 0xB8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XB8);
    // 0x800CA718: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800CA71C: sw          $t9, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r25;
    // 0x800CA720: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800CA724:
    // 0x800CA724: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x800CA728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA72C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CA730: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA734: jr          $ra
    // 0x800CA738: nop

    return;
    // 0x800CA738: nop

;}
RECOMP_FUNC void func_8006DC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DC7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DC80: jal         0x80061348
    // 0x8006DC84: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DC84: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x8006DC88: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DC90: beq         $v0, $zero, L_8006DCA8
    if (ctx->r2 == 0) {
        // 0x8006DC94: nop
    
            goto L_8006DCA8;
    }
    // 0x8006DC94: nop

    // 0x8006DC98: jal         0x80061348
    // 0x8006DC9C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DC9C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_1:
    // 0x8006DCA0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DCA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DCA8:
    // 0x8006DCA8: b           L_8006DCB8
    // 0x8006DCAC: nop

        goto L_8006DCB8;
    // 0x8006DCAC: nop

    // 0x8006DCB0: b           L_8006DCB8
    // 0x8006DCB4: nop

        goto L_8006DCB8;
    // 0x8006DCB4: nop

L_8006DCB8:
    // 0x8006DCB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DCBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DCC0: jr          $ra
    // 0x8006DCC4: nop

    return;
    // 0x8006DCC4: nop

;}
RECOMP_FUNC void func_80065748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006574C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065750: jal         0x8005F064
    // 0x80065754: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065754: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x80065758: b           L_80065768
    // 0x8006575C: nop

        goto L_80065768;
    // 0x8006575C: nop

    // 0x80065760: b           L_80065768
    // 0x80065764: nop

        goto L_80065768;
    // 0x80065764: nop

L_80065768:
    // 0x80065768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006576C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065770: jr          $ra
    // 0x80065774: nop

    return;
    // 0x80065774: nop

;}
RECOMP_FUNC void alCSeqTicksToSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAAC0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800CAAC4: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800CAAC8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CAACC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CAAD0: bgez        $a2, L_800CAAE4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800CAAD4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800CAAE4;
    }
    // 0x800CAAD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CAAD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CAADC: nop

    // 0x800CAAE0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800CAAE4:
    // 0x800CAAE4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800CAAE8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800CAAEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CAAF0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800CAAF4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800CAAF8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800CAAFC: bgez        $t7, L_800CAB10
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CAB00: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800CAB10;
    }
    // 0x800CAB00: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CAB04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CAB08: nop

    // 0x800CAB0C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800CAB10:
    // 0x800CAB10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAB14: ldc1        $f18, 0x1F8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1F8);
    // 0x800CAB18: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800CAB1C: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800CAB20: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800CAB24: jr          $ra
    // 0x800CAB28: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    return;
    // 0x800CAB28: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
;}
RECOMP_FUNC void func_800139B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800139B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800139BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800139C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800139C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800139C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800139CC: jal         0x8000DA44
    // 0x800139D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800139D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800139D4: bgez        $v0, L_800139E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800139D8: nop
    
            goto L_800139E4;
    }
    // 0x800139D8: nop

    // 0x800139DC: b           L_80013AEC
    // 0x800139E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013AEC;
    // 0x800139E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800139E4:
    // 0x800139E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800139E8: nop

    // 0x800139EC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800139F0: nop

    // 0x800139F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800139F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800139FC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80013A00: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x80013A04: nop

    // 0x80013A08: beq         $t9, $at, L_80013A18
    if (ctx->r25 == ctx->r1) {
        // 0x80013A0C: nop
    
            goto L_80013A18;
    }
    // 0x80013A0C: nop

    // 0x80013A10: b           L_80013AEC
    // 0x80013A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013AEC;
    // 0x80013A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013A18:
    // 0x80013A18: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80013A1C: nop

    // 0x80013A20: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80013A24: nop

    // 0x80013A28: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x80013A2C: bne         $t2, $zero, L_80013A3C
    if (ctx->r10 != 0) {
        // 0x80013A30: nop
    
            goto L_80013A3C;
    }
    // 0x80013A30: nop

    // 0x80013A34: b           L_80013AEC
    // 0x80013A38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013AEC;
    // 0x80013A38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013A3C:
    // 0x80013A3C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80013A40: nop

    // 0x80013A44: lw          $t4, 0x5C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X5C);
    // 0x80013A48: nop

    // 0x80013A4C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80013A50: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80013A54: nop

    // 0x80013A58: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80013A5C: jal         0x8001AE90
    // 0x80013A60: nop

    func_8001AE90(rdram, ctx);
        goto after_1;
    // 0x80013A60: nop

    after_1:
    // 0x80013A64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80013A68: nop

    // 0x80013A6C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80013A70: jal         0x8000D390
    // 0x80013A74: nop

    TempHeap_Free(rdram, ctx);
        goto after_2;
    // 0x80013A74: nop

    after_2:
    // 0x80013A78: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80013A7C: nop

    // 0x80013A80: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x80013A84: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80013A88: nop

    // 0x80013A8C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x80013A90: jal         0x8000D390
    // 0x80013A94: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x80013A94: nop

    after_3:
    // 0x80013A98: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80013A9C: nop

    // 0x80013AA0: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80013AA4: jal         0x8000D390
    // 0x80013AA8: nop

    TempHeap_Free(rdram, ctx);
        goto after_4;
    // 0x80013AA8: nop

    after_4:
    // 0x80013AAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80013AB0: jal         0x8000D390
    // 0x80013AB4: nop

    TempHeap_Free(rdram, ctx);
        goto after_5;
    // 0x80013AB4: nop

    after_5:
    // 0x80013AB8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80013ABC: nop

    // 0x80013AC0: sw          $zero, 0x5C($t0)
    MEM_W(0X5C, ctx->r8) = 0;
    // 0x80013AC4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80013AC8: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80013ACC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80013AD0: nop

    // 0x80013AD4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80013AD8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80013ADC: b           L_80013AEC
    // 0x80013AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013AEC;
    // 0x80013AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013AE4: b           L_80013AEC
    // 0x80013AE8: nop

        goto L_80013AEC;
    // 0x80013AE8: nop

L_80013AEC:
    // 0x80013AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013AF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80013AF4: jr          $ra
    // 0x80013AF8: nop

    return;
    // 0x80013AF8: nop

;}
RECOMP_FUNC void func_80073BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073BD4: jal         0x80061348
    // 0x80073BD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073BD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073BDC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073BE0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073BE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073BE8: beq         $v0, $zero, L_80073C3C
    if (ctx->r2 == 0) {
        // 0x80073BEC: nop
    
            goto L_80073C3C;
    }
    // 0x80073BEC: nop

    // 0x80073BF0: jal         0x80061348
    // 0x80073BF4: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073BF4: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073BF8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073BFC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073C00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073C04: beq         $v0, $zero, L_80073C3C
    if (ctx->r2 == 0) {
        // 0x80073C08: nop
    
            goto L_80073C3C;
    }
    // 0x80073C08: nop

    // 0x80073C0C: jal         0x80061348
    // 0x80073C10: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073C10: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073C14: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073C18: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073C1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073C20: beq         $v0, $zero, L_80073C3C
    if (ctx->r2 == 0) {
        // 0x80073C24: nop
    
            goto L_80073C3C;
    }
    // 0x80073C24: nop

    // 0x80073C28: jal         0x80061348
    // 0x80073C2C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073C2C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073C30: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073C34: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073C38: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073C3C:
    // 0x80073C3C: b           L_80073C4C
    // 0x80073C40: nop

        goto L_80073C4C;
    // 0x80073C40: nop

    // 0x80073C44: b           L_80073C4C
    // 0x80073C48: nop

        goto L_80073C4C;
    // 0x80073C48: nop

L_80073C4C:
    // 0x80073C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073C54: jr          $ra
    // 0x80073C58: nop

    return;
    // 0x80073C58: nop

;}
RECOMP_FUNC void func_80063FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063FE0: jal         0x80061488
    // 0x80063FE4: addiu       $a0, $zero, 0x5E3
    ctx->r4 = ADD32(0, 0X5E3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063FE4: addiu       $a0, $zero, 0x5E3
    ctx->r4 = ADD32(0, 0X5E3);
    after_0:
    // 0x80063FE8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063FEC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063FF0: b           L_80064000
    // 0x80063FF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064000;
    // 0x80063FF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063FF8: b           L_80064000
    // 0x80063FFC: nop

        goto L_80064000;
    // 0x80063FFC: nop

L_80064000:
    // 0x80064000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064008: jr          $ra
    // 0x8006400C: nop

    return;
    // 0x8006400C: nop

;}
RECOMP_FUNC void func_80011040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011040: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011048: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001104C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80011050: nop

    // 0x80011054: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80011058: nop

    // 0x8001105C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80011060: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80011064: nop

    // 0x80011068: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x8001106C: nop

    // 0x80011070: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80011074: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80011078: nop

    // 0x8001107C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80011080: nop

    // 0x80011084: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80011088: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001108C: jal         0x8001ABEC
    // 0x80011090: nop

    func_8001ABEC(rdram, ctx);
        goto after_0;
    // 0x80011090: nop

    after_0:
    // 0x80011094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011098: jal         0x8008EAA8
    // 0x8001109C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_1;
    // 0x8001109C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800110A0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800110A4: nop

    // 0x800110A8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800110AC: nop

    // 0x800110B0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800110B4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800110B8: nop

    // 0x800110BC: beq         $t4, $zero, L_800111A4
    if (ctx->r12 == 0) {
        // 0x800110C0: nop
    
            goto L_800111A4;
    }
    // 0x800110C0: nop

L_800110C4:
    // 0x800110C4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800110C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800110CC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800110D0: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x800110D4: jal         0x800BD218
    // 0x800110D8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800110D8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_2:
    // 0x800110DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800110E0: nop

    // 0x800110E4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800110E8: nop

    // 0x800110EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800110F0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800110F4: nop

    // 0x800110F8: beq         $t9, $zero, L_80011138
    if (ctx->r25 == 0) {
        // 0x800110FC: nop
    
            goto L_80011138;
    }
    // 0x800110FC: nop

    // 0x80011100: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80011104: beq         $t9, $at, L_80011138
    if (ctx->r25 == ctx->r1) {
        // 0x80011108: nop
    
            goto L_80011138;
    }
    // 0x80011108: nop

L_8001110C:
    // 0x8001110C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80011110: nop

    // 0x80011114: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80011118: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8001111C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80011120: nop

    // 0x80011124: beq         $t2, $zero, L_80011138
    if (ctx->r10 == 0) {
        // 0x80011128: nop
    
            goto L_80011138;
    }
    // 0x80011128: nop

    // 0x8001112C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80011130: bne         $t2, $at, L_8001110C
    if (ctx->r10 != ctx->r1) {
        // 0x80011134: nop
    
            goto L_8001110C;
    }
    // 0x80011134: nop

L_80011138:
    // 0x80011138: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001113C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80011140: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80011144: nop

    // 0x80011148: bne         $t4, $at, L_80011170
    if (ctx->r12 != ctx->r1) {
        // 0x8001114C: nop
    
            goto L_80011170;
    }
    // 0x8001114C: nop

    // 0x80011150: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80011154: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80011158: lbu         $a1, 0x7208($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7208);
    // 0x8001115C: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x80011160: jal         0x8008ECE4
    // 0x80011164: nop

    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x80011164: nop

    after_3:
    // 0x80011168: b           L_80011184
    // 0x8001116C: nop

        goto L_80011184;
    // 0x8001116C: nop

L_80011170:
    // 0x80011170: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80011174: nop

    // 0x80011178: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8001117C: jal         0x8008ECE4
    // 0x80011180: nop

    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x80011180: nop

    after_4:
L_80011184:
    // 0x80011184: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011188: nop

    // 0x8001118C: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80011190: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80011194: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80011198: nop

    // 0x8001119C: bne         $t9, $zero, L_800110C4
    if (ctx->r25 != 0) {
        // 0x800111A0: nop
    
            goto L_800110C4;
    }
    // 0x800111A0: nop

L_800111A4:
    // 0x800111A4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800111A8: nop

    // 0x800111AC: lw          $t1, 0x138($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X138);
    // 0x800111B0: nop

    // 0x800111B4: sh          $zero, 0x20($t1)
    MEM_H(0X20, ctx->r9) = 0;
    // 0x800111B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800111BC: jal         0x8001ACDC
    // 0x800111C0: nop

    func_8001ACDC(rdram, ctx);
        goto after_5;
    // 0x800111C0: nop

    after_5:
    // 0x800111C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800111C8: jal         0x8001ADBC
    // 0x800111CC: nop

    func_8001ADBC(rdram, ctx);
        goto after_6;
    // 0x800111CC: nop

    after_6:
    // 0x800111D0: b           L_800111D8
    // 0x800111D4: nop

        goto L_800111D8;
    // 0x800111D4: nop

L_800111D8:
    // 0x800111D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800111DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800111E0: jr          $ra
    // 0x800111E4: nop

    return;
    // 0x800111E4: nop

;}
RECOMP_FUNC void func_800C1D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1D0C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C1D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1D14: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800C1D18: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800C1D1C: jal         0x800C2F1C
    // 0x800C1D20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x800C1D20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800C1D24: jal         0x800C1D44
    // 0x800C1D28: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800C1D44(rdram, ctx);
        goto after_1;
    // 0x800C1D28: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800C1D2C: b           L_800C1D34
    // 0x800C1D30: nop

        goto L_800C1D34;
    // 0x800C1D30: nop

L_800C1D34:
    // 0x800C1D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1D38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800C1D3C: jr          $ra
    // 0x800C1D40: nop

    return;
    // 0x800C1D40: nop

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
RECOMP_FUNC void func_800639BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800639BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800639C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800639C4: nop

    // 0x800639C8: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x800639CC: nop

    // 0x800639D0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800639D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800639D8: jr          $ra
    // 0x800639DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800639DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800639E0: jr          $ra
    // 0x800639E4: nop

    return;
    // 0x800639E4: nop

    // 0x800639E8: jr          $ra
    // 0x800639EC: nop

    return;
    // 0x800639EC: nop

;}
RECOMP_FUNC void func_800C1D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1D44: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C1D48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1D4C: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1D50: nop

    // 0x800C1D54: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C1D58: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C1D5C: addiu       $t7, $t7, 0xCF0
    ctx->r15 = ADD32(ctx->r15, 0XCF0);
    // 0x800C1D60: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C1D64: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_800C1D68:
    // 0x800C1D68: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1D6C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C1D70: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C1D74: nop

    // 0x800C1D78: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1D7C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C1D80: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C1D84: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1D88: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C1D8C: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x800C1D90: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800C1D94: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1D98: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C1D9C: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C1DA0: nop

    // 0x800C1DA4: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x800C1DA8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DAC: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C1DB0: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C1DB4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C1DB8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C1DBC: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C1DC0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DC4: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C1DC8: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C1DCC: nop

    // 0x800C1DD0: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x800C1DD4: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DD8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C1DDC: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800C1DE0: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1DE4: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C1DE8: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C1DEC: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DF0: nop

    // 0x800C1DF4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C1DF8: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800C1DFC: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C1E00: nop

    // 0x800C1E04: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C1E08: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C1E0C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C1E10: nop

    // 0x800C1E14: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C1E18: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800C1E1C: bne         $at, $zero, L_800C1D68
    if (ctx->r1 != 0) {
        // 0x800C1E20: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_800C1D68;
    }
    // 0x800C1E20: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800C1E24: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800C1E28: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E2C: nop

    // 0x800C1E30: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C1E34: nop

    // 0x800C1E38: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800C1E3C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E40: nop

    // 0x800C1E44: lwc1        $f16, 0x4($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800C1E48: nop

    // 0x800C1E4C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800C1E50: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E54: nop

    // 0x800C1E58: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800C1E5C: nop

    // 0x800C1E60: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x800C1E64: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E68: nop

    // 0x800C1E6C: lwc1        $f4, 0x10($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800C1E70: nop

    // 0x800C1E74: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800C1E78: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E7C: nop

    // 0x800C1E80: lwc1        $f6, 0x14($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800C1E84: nop

    // 0x800C1E88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800C1E8C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E90: nop

    // 0x800C1E94: lwc1        $f8, 0x18($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X18);
    // 0x800C1E98: nop

    // 0x800C1E9C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800C1EA0: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EA4: nop

    // 0x800C1EA8: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x800C1EAC: nop

    // 0x800C1EB0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800C1EB4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EB8: nop

    // 0x800C1EBC: lwc1        $f16, 0x24($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X24);
    // 0x800C1EC0: nop

    // 0x800C1EC4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800C1EC8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C1ECC: nop

    // 0x800C1ED0: lwc1        $f18, 0x28($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X28);
    // 0x800C1ED4: nop

    // 0x800C1ED8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800C1EDC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EE0: nop

    // 0x800C1EE4: lwc1        $f4, 0x30($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X30);
    // 0x800C1EE8: nop

    // 0x800C1EEC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800C1EF0: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EF4: nop

    // 0x800C1EF8: lwc1        $f6, 0x34($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800C1EFC: nop

    // 0x800C1F00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C1F04: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C1F08: nop

    // 0x800C1F0C: lwc1        $f8, 0x38($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X38);
    // 0x800C1F10: nop

    // 0x800C1F14: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800C1F18: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800C1F1C: lw          $t4, 0xCE4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCE4);
    // 0x800C1F20: nop

    // 0x800C1F24: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800C1F28: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800C1F2C: addiu       $t5, $t5, 0xCF0
    ctx->r13 = ADD32(ctx->r13, 0XCF0);
    // 0x800C1F30: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x800C1F34: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800C1F38: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_800C1F3C:
    // 0x800C1F3C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C1F40: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C1F44: lwc1        $f14, 0x10($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X10);
    // 0x800C1F48: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C1F4C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800C1F50: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800C1F54: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C1F58: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C1F5C: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800C1F60: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1F64: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C1F68: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800C1F6C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800C1F70: nop

    // 0x800C1F74: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800C1F78: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C1F7C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C1F80: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800C1F84: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C1F88: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C1F8C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1F90: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C1F94: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C1F98: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C1F9C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C1FA0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800C1FA4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C1FA8: nop

    // 0x800C1FAC: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800C1FB0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800C1FB4: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C1FB8: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x800C1FBC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C1FC0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C1FC4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1FC8: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1FCC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C1FD0: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C1FD4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C1FD8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C1FDC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C1FE0: nop

    // 0x800C1FE4: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C1FE8: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800C1FEC: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800C1FF0: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800C1FF4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C1FF8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C1FFC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2000: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800C2004: lwc1        $f16, 0x14($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2008: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C200C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C2010: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800C2014: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C2018: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C201C: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800C2020: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800C2024: lwc1        $f18, 0x30($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X30);
    // 0x800C2028: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C202C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C2030: swc1        $f6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f6.u32l;
    // 0x800C2034: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C2038: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C203C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800C2040: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x800C2044: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800C2048: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800C204C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800C2050: nop

    // 0x800C2054: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C2058: bgtz        $t8, L_800C1F3C
    if (SIGNED(ctx->r24) > 0) {
        // 0x800C205C: sw          $t8, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r24;
            goto L_800C1F3C;
    }
    // 0x800C205C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C2060: b           L_800C2068
    // 0x800C2064: nop

        goto L_800C2068;
    // 0x800C2064: nop

L_800C2068:
    // 0x800C2068: jr          $ra
    // 0x800C206C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C206C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8002D598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D59C: sh          $zero, 0x8($sp)
    MEM_H(0X8, ctx->r29) = 0;
    // 0x8002D5A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002D5A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8002D5A8: nop

    // 0x8002D5AC: lh          $t7, 0x40($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X40);
    // 0x8002D5B0: nop

    // 0x8002D5B4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002D5B8: sh          $t8, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r24;
    // 0x8002D5BC: sh          $t7, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r15;
    // 0x8002D5C0: lhu         $t9, 0xE($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XE);
    // 0x8002D5C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8002D5C8: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8002D5CC: addiu       $t1, $sp, 0x10
    ctx->r9 = ADD32(ctx->r29, 0X10);
    // 0x8002D5D0: mfhi        $t0
    ctx->r8 = hi;
    // 0x8002D5D4: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
    // 0x8002D5D8: nop

    // 0x8002D5DC: addiu       $t3, $sp, 0x10
    ctx->r11 = ADD32(ctx->r29, 0X10);
    // 0x8002D5E0: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x8002D5E4: lhu         $t2, 0xE($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XE);
    // 0x8002D5E8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8002D5EC: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x8002D5F0: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002D5F4: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8002D5F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002D5FC: lwc1        $f9, -0x1850($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1850);
    // 0x8002D600: lwc1        $f8, -0x184C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X184C);
    // 0x8002D604: sh          $t5, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r13;
    // 0x8002D608: mfhi        $t7
    ctx->r15 = hi;
    // 0x8002D60C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8002D610: nop

    // 0x8002D614: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002D618: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002D61C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002D620: nop

    // 0x8002D624: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002D628: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002D62C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002D630: nop

    // 0x8002D634: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x8002D638: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8002D63C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002D640: sh          $t9, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r25;
    // 0x8002D644: nop

    // 0x8002D648: addiu       $t1, $sp, 0x10
    ctx->r9 = ADD32(ctx->r29, 0X10);
    // 0x8002D64C: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8002D650: lhu         $t0, 0xE($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XE);
    // 0x8002D654: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8002D658: subu        $t4, $t0, $t2
    ctx->r12 = SUB32(ctx->r8, ctx->r10);
    // 0x8002D65C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8002D660: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8002D664: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002D668: lwc1        $f7, -0x1848($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1848);
    // 0x8002D66C: lwc1        $f6, -0x1844($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1844);
    // 0x8002D670: sh          $t4, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r12;
    // 0x8002D674: mfhi        $t6
    ctx->r14 = hi;
    // 0x8002D678: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002D67C: nop

    // 0x8002D680: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8002D684: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002D688: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002D68C: nop

    // 0x8002D690: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002D694: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002D698: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002D69C: nop

    // 0x8002D6A0: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x8002D6A4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8002D6A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002D6AC: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x8002D6B0: nop

    // 0x8002D6B4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002D6B8: lw          $t9, 0x16C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X16C0);
    // 0x8002D6BC: nop

    // 0x8002D6C0: lw          $t3, 0x128($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X128);
    // 0x8002D6C4: nop

    // 0x8002D6C8: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8002D6CC: sh          $zero, 0xE($sp)
    MEM_H(0XE, ctx->r29) = 0;
L_8002D6D0:
    // 0x8002D6D0: lhu         $t0, 0xE($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XE);
    // 0x8002D6D4: nop

    // 0x8002D6D8: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x8002D6DC: addu        $t4, $sp, $t2
    ctx->r12 = ADD32(ctx->r29, ctx->r10);
    // 0x8002D6E0: lh          $t4, 0x10($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10);
    // 0x8002D6E4: nop

    // 0x8002D6E8: bne         $t4, $zero, L_8002D728
    if (ctx->r12 != 0) {
        // 0x8002D6EC: sh          $t4, 0xA($sp)
        MEM_H(0XA, ctx->r29) = ctx->r12;
            goto L_8002D728;
    }
    // 0x8002D6EC: sh          $t4, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r12;
    // 0x8002D6F0: lh          $t5, 0x8($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X8);
    // 0x8002D6F4: nop

    // 0x8002D6F8: bne         $t5, $zero, L_8002D728
    if (ctx->r13 != 0) {
        // 0x8002D6FC: nop
    
            goto L_8002D728;
    }
    // 0x8002D6FC: nop

    // 0x8002D700: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002D704: lw          $t6, -0x6A08($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A08);
    // 0x8002D708: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8002D70C: addiu       $t7, $t6, 0x508
    ctx->r15 = ADD32(ctx->r14, 0X508);
    // 0x8002D710: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8002D714: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8002D718: nop

    // 0x8002D71C: addiu       $t9, $t1, 0xC
    ctx->r25 = ADD32(ctx->r9, 0XC);
    // 0x8002D720: b           L_8002D760
    // 0x8002D724: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
        goto L_8002D760;
    // 0x8002D724: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_8002D728:
    // 0x8002D728: lh          $t0, 0xA($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA);
    // 0x8002D72C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8002D730: lw          $t3, -0x6A08($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6A08);
    // 0x8002D734: sll         $t2, $t0, 7
    ctx->r10 = S32(ctx->r8 << 7);
    // 0x8002D738: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8002D73C: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x8002D740: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8002D744: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x8002D748: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8002D74C: nop

    // 0x8002D750: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x8002D754: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8002D758: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002D75C: sh          $t1, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r9;
L_8002D760:
    // 0x8002D760: lhu         $t9, 0xE($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XE);
    // 0x8002D764: nop

    // 0x8002D768: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8002D76C: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x8002D770: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x8002D774: bne         $at, $zero, L_8002D6D0
    if (ctx->r1 != 0) {
        // 0x8002D778: sh          $t0, 0xE($sp)
        MEM_H(0XE, ctx->r29) = ctx->r8;
            goto L_8002D6D0;
    }
    // 0x8002D778: sh          $t0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r8;
    // 0x8002D77C: lhu         $t2, 0xC($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XC);
    // 0x8002D780: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002D784: sh          $t2, -0x6A10($at)
    MEM_H(-0X6A10, ctx->r1) = ctx->r10;
    // 0x8002D788: b           L_8002D790
    // 0x8002D78C: nop

        goto L_8002D790;
    // 0x8002D78C: nop

L_8002D790:
    // 0x8002D790: jr          $ra
    // 0x8002D794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002D794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80088868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088868: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008886C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80088870: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80088874: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80088878: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008887C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80088880: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80088884: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80088888: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008888C: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x80088890: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80088894: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088898: beq         $t0, $zero, L_80088A3C
    if (ctx->r8 == 0) {
        // 0x8008889C: nop
    
            goto L_80088A3C;
    }
    // 0x8008889C: nop

    // 0x800888A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800888A4: jal         0x8008A518
    // 0x800888A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800888A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800888AC: beq         $v0, $zero, L_80088A3C
    if (ctx->r2 == 0) {
        // 0x800888B0: nop
    
            goto L_80088A3C;
    }
    // 0x800888B0: nop

    // 0x800888B4: lhu         $s0, 0x2C($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X2C);
    // 0x800888B8: nop

    // 0x800888BC: slti        $at, $s0, 0x4001
    ctx->r1 = SIGNED(ctx->r16) < 0X4001 ? 1 : 0;
    // 0x800888C0: bne         $at, $zero, L_800888DC
    if (ctx->r1 != 0) {
        // 0x800888C4: nop
    
            goto L_800888DC;
    }
    // 0x800888C4: nop

    // 0x800888C8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x800888CC: beq         $s0, $at, L_800889F0
    if (ctx->r16 == ctx->r1) {
        // 0x800888D0: nop
    
            goto L_800889F0;
    }
    // 0x800888D0: nop

    // 0x800888D4: b           L_80088A3C
    // 0x800888D8: nop

        goto L_80088A3C;
    // 0x800888D8: nop

L_800888DC:
    // 0x800888DC: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x800888E0: bne         $at, $zero, L_800888FC
    if (ctx->r1 != 0) {
        // 0x800888E4: nop
    
            goto L_800888FC;
    }
    // 0x800888E4: nop

    // 0x800888E8: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800888EC: beq         $s0, $at, L_80088A20
    if (ctx->r16 == ctx->r1) {
        // 0x800888F0: nop
    
            goto L_80088A20;
    }
    // 0x800888F0: nop

    // 0x800888F4: b           L_80088A3C
    // 0x800888F8: nop

        goto L_80088A3C;
    // 0x800888F8: nop

L_800888FC:
    // 0x800888FC: addiu       $t1, $s0, -0x6
    ctx->r9 = ADD32(ctx->r16, -0X6);
    // 0x80088900: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x80088904: beq         $at, $zero, L_80088A3C
    if (ctx->r1 == 0) {
        // 0x80088908: nop
    
            goto L_80088A3C;
    }
    // 0x80088908: nop

    // 0x8008890C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80088910: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80088914: addu        $at, $at, $t1
    gpr jr_addend_80088920 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80088918: lw          $t1, -0xA6C($at)
    ctx->r9 = ADD32(ctx->r1, -0XA6C);
    // 0x8008891C: nop

    // 0x80088920: jr          $t1
    // 0x80088924: nop

    switch (jr_addend_80088920 >> 2) {
        case 0: goto L_80088928; break;
        case 1: goto L_80088928; break;
        case 2: goto L_80088928; break;
        case 3: goto L_80088A3C; break;
        case 4: goto L_80088968; break;
        case 5: goto L_80088968; break;
        case 6: goto L_80088A3C; break;
        case 7: goto L_800889AC; break;
        case 8: goto L_800889AC; break;
        case 9: goto L_800889AC; break;
        default: switch_error(__func__, 0x80088920, 0x800EF594);
    }
    // 0x80088924: nop

L_80088928:
    // 0x80088928: jal         0x8008CE48
    // 0x8008892C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x8008892C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_1:
    // 0x80088930: lhu         $t2, 0x2C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2C);
    // 0x80088934: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80088938: addiu       $t3, $t2, -0x6
    ctx->r11 = ADD32(ctx->r10, -0X6);
    // 0x8008893C: sh          $t3, 0x1E($t4)
    MEM_H(0X1E, ctx->r12) = ctx->r11;
    // 0x80088940: lh          $t5, 0x34($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X34);
    // 0x80088944: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088948: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x8008894C: lh          $a2, 0x30($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X30);
    // 0x80088950: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x80088954: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80088958: jal         0x8008A368
    // 0x8008895C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8008A368(rdram, ctx);
        goto after_2;
    // 0x8008895C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x80088960: b           L_80088A3C
    // 0x80088964: nop

        goto L_80088A3C;
    // 0x80088964: nop

L_80088968:
    // 0x80088968: jal         0x8008CE48
    // 0x8008896C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x8008896C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_3:
    // 0x80088970: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x80088974: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80088978: addiu       $t7, $t6, -0xA
    ctx->r15 = ADD32(ctx->r14, -0XA);
    // 0x8008897C: sh          $t7, 0x20($t9)
    MEM_H(0X20, ctx->r25) = ctx->r15;
    // 0x80088980: lh          $t8, 0x34($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X34);
    // 0x80088984: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088988: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x8008898C: lh          $a2, 0x30($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X30);
    // 0x80088990: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x80088994: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088998: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8008899C: jal         0x8008A368
    // 0x800889A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8008A368(rdram, ctx);
        goto after_4;
    // 0x800889A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_4:
    // 0x800889A4: b           L_80088A3C
    // 0x800889A8: nop

        goto L_80088A3C;
    // 0x800889A8: nop

L_800889AC:
    // 0x800889AC: jal         0x8008CE48
    // 0x800889B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_5;
    // 0x800889B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_5:
    // 0x800889B4: lhu         $t1, 0x2C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2C);
    // 0x800889B8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800889BC: addiu       $t2, $t1, -0xD
    ctx->r10 = ADD32(ctx->r9, -0XD);
    // 0x800889C0: sh          $t2, 0x22($t3)
    MEM_H(0X22, ctx->r11) = ctx->r10;
    // 0x800889C4: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800889C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800889CC: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x800889D0: lh          $a2, 0x30($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X30);
    // 0x800889D4: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x800889D8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800889DC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800889E0: jal         0x8008A368
    // 0x800889E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8008A368(rdram, ctx);
        goto after_6;
    // 0x800889E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x800889E8: b           L_80088A3C
    // 0x800889EC: nop

        goto L_80088A3C;
    // 0x800889EC: nop

L_800889F0:
    // 0x800889F0: jal         0x8008CE48
    // 0x800889F4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_7;
    // 0x800889F4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_7:
    // 0x800889F8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800889FC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80088A00: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x80088A04: nop

    // 0x80088A08: bne         $t7, $at, L_80088A18
    if (ctx->r15 != ctx->r1) {
        // 0x80088A0C: nop
    
            goto L_80088A18;
    }
    // 0x80088A0C: nop

    // 0x80088A10: b           L_80088ADC
    // 0x80088A14: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088ADC;
    // 0x80088A14: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088A18:
    // 0x80088A18: b           L_80088ADC
    // 0x80088A1C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80088ADC;
    // 0x80088A1C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80088A20:
    // 0x80088A20: jal         0x8008CE48
    // 0x80088A24: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80088A24: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_8:
    // 0x80088A28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088A2C: jal         0x8008CA00
    // 0x80088A30: nop

    func_8008CA00(rdram, ctx);
        goto after_9;
    // 0x80088A30: nop

    after_9:
    // 0x80088A34: b           L_80088ADC
    // 0x80088A38: nop

        goto L_80088ADC;
    // 0x80088A38: nop

L_80088A3C:
    // 0x80088A3C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80088A40: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x80088A44: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x80088A48: nop

    // 0x80088A4C: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088A50: beq         $t0, $zero, L_80088A88
    if (ctx->r8 == 0) {
        // 0x80088A54: nop
    
            goto L_80088A88;
    }
    // 0x80088A54: nop

    // 0x80088A58: jal         0x8008CE48
    // 0x80088A5C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80088A5C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80088A60: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80088A64: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80088A68: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x80088A6C: nop

    // 0x80088A70: bne         $t2, $at, L_80088A80
    if (ctx->r10 != ctx->r1) {
        // 0x80088A74: nop
    
            goto L_80088A80;
    }
    // 0x80088A74: nop

    // 0x80088A78: b           L_80088ADC
    // 0x80088A7C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088ADC;
    // 0x80088A7C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088A80:
    // 0x80088A80: b           L_80088ADC
    // 0x80088A84: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80088ADC;
    // 0x80088A84: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80088A88:
    // 0x80088A88: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80088A8C: lhu         $t4, 0x11A4($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X11A4);
    // 0x80088A90: lhu         $t3, 0x3E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3E);
    // 0x80088A94: nop

    // 0x80088A98: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80088A9C: beq         $t5, $zero, L_80088AC0
    if (ctx->r13 == 0) {
        // 0x80088AA0: nop
    
            goto L_80088AC0;
    }
    // 0x80088AA0: nop

    // 0x80088AA4: jal         0x8008CE48
    // 0x80088AA8: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_11;
    // 0x80088AA8: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_11:
    // 0x80088AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088AB0: jal         0x8008CA00
    // 0x80088AB4: nop

    func_8008CA00(rdram, ctx);
        goto after_12;
    // 0x80088AB4: nop

    after_12:
    // 0x80088AB8: b           L_80088ADC
    // 0x80088ABC: nop

        goto L_80088ADC;
    // 0x80088ABC: nop

L_80088AC0:
    // 0x80088AC0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80088AC4: nop

    // 0x80088AC8: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80088ACC: b           L_80088ADC
    // 0x80088AD0: nop

        goto L_80088ADC;
    // 0x80088AD0: nop

    // 0x80088AD4: b           L_80088ADC
    // 0x80088AD8: nop

        goto L_80088ADC;
    // 0x80088AD8: nop

L_80088ADC:
    // 0x80088ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80088AE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80088AE4: jr          $ra
    // 0x80088AE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80088AE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006F508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F508: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F50C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F510: nop

    // 0x8006F514: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006F518: nop

    // 0x8006F51C: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x8006F520: jr          $ra
    // 0x8006F524: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F524: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F528: jr          $ra
    // 0x8006F52C: nop

    return;
    // 0x8006F52C: nop

    // 0x8006F530: jr          $ra
    // 0x8006F534: nop

    return;
    // 0x8006F534: nop

;}
RECOMP_FUNC void func_80029ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029ED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80029EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029EE0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80029EE4: addiu       $a0, $a0, 0x2578
    ctx->r4 = ADD32(ctx->r4, 0X2578);
    // 0x80029EE8: jal         0x8002A0F8
    // 0x80029EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_0;
    // 0x80029EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80029EF0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80029EF4: beq         $at, $zero, L_80029F0C
    if (ctx->r1 == 0) {
        // 0x80029EF8: nop
    
            goto L_80029F0C;
    }
    // 0x80029EF8: nop

    // 0x80029EFC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80029F00: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x80029F04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029F08: sw          $t6, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r14;
L_80029F0C:
    // 0x80029F0C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80029F10: lw          $t7, 0x3074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3074);
    // 0x80029F14: nop

    // 0x80029F18: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80029F1C: nop

    // 0x80029F20: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80029F24: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
L_80029F28:
    // 0x80029F28: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80029F2C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029F30: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80029F34: sb          $zero, -0x6500($at)
    MEM_B(-0X6500, ctx->r1) = 0;
    // 0x80029F38: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80029F3C: nop

    // 0x80029F40: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80029F44: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80029F48: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80029F4C: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x80029F50: bne         $at, $zero, L_80029F28
    if (ctx->r1 != 0) {
        // 0x80029F54: sh          $t1, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r9;
            goto L_80029F28;
    }
    // 0x80029F54: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80029F58: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x80029F5C: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x80029F60: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80029F64: nop

    // 0x80029F68: beq         $t4, $zero, L_8002A010
    if (ctx->r12 == 0) {
        // 0x80029F6C: nop
    
            goto L_8002A010;
    }
    // 0x80029F6C: nop

L_80029F70:
    // 0x80029F70: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80029F74: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029F78: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x80029F7C: nop

    // 0x80029F80: bne         $t6, $at, L_80029FA8
    if (ctx->r14 != ctx->r1) {
        // 0x80029F84: nop
    
            goto L_80029FA8;
    }
    // 0x80029F84: nop

    // 0x80029F88: lh          $t7, 0x4($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X4);
    // 0x80029F8C: nop

    // 0x80029F90: bne         $t7, $zero, L_80029FA8
    if (ctx->r15 != 0) {
        // 0x80029F94: nop
    
            goto L_80029FA8;
    }
    // 0x80029F94: nop

    // 0x80029F98: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80029F9C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80029FA0: bne         $t8, $at, L_80029FB0
    if (ctx->r24 != ctx->r1) {
        // 0x80029FA4: nop
    
            goto L_80029FB0;
    }
    // 0x80029FA4: nop

L_80029FA8:
    // 0x80029FA8: b           L_8002A010
    // 0x80029FAC: nop

        goto L_8002A010;
    // 0x80029FAC: nop

L_80029FB0:
    // 0x80029FB0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80029FB4: lh          $t1, 0x24($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X24);
    // 0x80029FB8: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80029FBC: nop

    // 0x80029FC0: beq         $t0, $t1, L_80029FEC
    if (ctx->r8 == ctx->r9) {
        // 0x80029FC4: sh          $t0, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r8;
            goto L_80029FEC;
    }
    // 0x80029FC4: sh          $t0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r8;
    // 0x80029FC8: lh          $t2, 0x22($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X22);
    // 0x80029FCC: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80029FD0: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x80029FD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029FD8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80029FDC: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80029FE0: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x80029FE4: sb          $t2, -0x6500($at)
    MEM_B(-0X6500, ctx->r1) = ctx->r10;
    // 0x80029FE8: sh          $t2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r10;
L_80029FEC:
    // 0x80029FEC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80029FF0: nop

    // 0x80029FF4: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x80029FF8: nop

    // 0x80029FFC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8002A000: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A004: nop

    // 0x8002A008: bne         $t8, $zero, L_80029F70
    if (ctx->r24 != 0) {
        // 0x8002A00C: nop
    
            goto L_80029F70;
    }
    // 0x8002A00C: nop

L_8002A010:
    // 0x8002A010: b           L_8002A018
    // 0x8002A014: nop

        goto L_8002A018;
    // 0x8002A014: nop

L_8002A018:
    // 0x8002A018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A01C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002A020: jr          $ra
    // 0x8002A024: nop

    return;
    // 0x8002A024: nop

;}
RECOMP_FUNC void func_800C3D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3D70: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C3D74: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C3D78: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800C3D7C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800C3D80: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x800C3D84: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x800C3D88: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800C3D8C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800C3D90: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800C3D94: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800C3D98: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800C3D9C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800C3DA0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3DA4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3DA8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C3DAC: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C3DB0: nop

    // 0x800C3DB4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800C3DB8: nop

    // 0x800C3DBC: bc1f        L_800C3E0C
    if (!c1cs) {
        // 0x800C3DC0: nop
    
            goto L_800C3E0C;
    }
    // 0x800C3DC0: nop

    // 0x800C3DC4: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C3DC8: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C3DCC: nop

    // 0x800C3DD0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800C3DD4: nop

    // 0x800C3DD8: bc1f        L_800C3E0C
    if (!c1cs) {
        // 0x800C3DDC: nop
    
            goto L_800C3E0C;
    }
    // 0x800C3DDC: nop

    // 0x800C3DE0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C3DE4: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C3DE8: nop

    // 0x800C3DEC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800C3DF0: nop

    // 0x800C3DF4: bc1f        L_800C3E0C
    if (!c1cs) {
        // 0x800C3DF8: nop
    
            goto L_800C3E0C;
    }
    // 0x800C3DF8: nop

    // 0x800C3DFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3E00: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800C3E04: b           L_800C3EF8
    // 0x800C3E08: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
        goto L_800C3EF8;
    // 0x800C3E08: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
L_800C3E0C:
    // 0x800C3E0C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C3E10: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C3E14: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800C3E18: sub.s       $f26, $f6, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C3E1C: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x800C3E20: swc1        $f26, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f26.u32l;
    // 0x800C3E24: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C3E28: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C3E2C: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x800C3E30: sub.s       $f24, $f10, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800C3E34: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x800C3E38: swc1        $f24, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f24.u32l;
    // 0x800C3E3C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C3E40: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C3E44: nop

    // 0x800C3E48: sub.s       $f22, $f18, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800C3E4C: swc1        $f22, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f22.u32l;
    // 0x800C3E50: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C3E54: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C3E58: mul.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x800C3E5C: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C3E60: mul.s       $f16, $f26, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x800C3E64: nop

    // 0x800C3E68: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800C3E6C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C3E70: jal         0x800C42A0
    // 0x800C3E74: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3E74: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_0:
    // 0x800C3E78: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800C3E7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C3E80: swc1        $f20, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f20.u32l;
    // 0x800C3E84: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x800C3E88: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_800C3E8C:
    // 0x800C3E8C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800C3E90: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3E94: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C3E98: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x800C3E9C: lwc1        $f10, 0x50($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X50);
    // 0x800C3EA0: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800C3EA4: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800C3EA8: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x800C3EAC: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x800C3EB0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800C3EB4: nop

    // 0x800C3EB8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C3EBC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800C3EC0: bne         $at, $zero, L_800C3E8C
    if (ctx->r1 != 0) {
        // 0x800C3EC4: sw          $t8, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r24;
            goto L_800C3E8C;
    }
    // 0x800C3EC4: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800C3EC8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C3ECC: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800C3ED0: nop

    // 0x800C3ED4: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x800C3ED8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C3EDC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800C3EE0: nop

    // 0x800C3EE4: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x800C3EE8: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C3EEC: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800C3EF0: nop

    // 0x800C3EF4: swc1        $f18, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f18.u32l;
L_800C3EF8:
    // 0x800C3EF8: b           L_800C3F00
    // 0x800C3EFC: nop

        goto L_800C3F00;
    // 0x800C3EFC: nop

L_800C3F00:
    // 0x800C3F00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C3F04: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3F08: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C3F0C: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C3F10: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3F14: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3F18: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3F1C: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800C3F20: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C3F24: jr          $ra
    // 0x800C3F28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800C3F28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8006FED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FEDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FEE0: jal         0x80061348
    // 0x8006FEE4: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FEE4: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    after_0:
    // 0x8006FEE8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FEEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FEF0: bne         $v0, $zero, L_8006FF0C
    if (ctx->r2 != 0) {
        // 0x8006FEF4: nop
    
            goto L_8006FF0C;
    }
    // 0x8006FEF4: nop

    // 0x8006FEF8: jal         0x80061348
    // 0x8006FEFC: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FEFC: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x8006FF00: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FF04: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FF08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006FF0C:
    // 0x8006FF0C: b           L_8006FF1C
    // 0x8006FF10: nop

        goto L_8006FF1C;
    // 0x8006FF10: nop

    // 0x8006FF14: b           L_8006FF1C
    // 0x8006FF18: nop

        goto L_8006FF1C;
    // 0x8006FF18: nop

L_8006FF1C:
    // 0x8006FF1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FF20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FF24: jr          $ra
    // 0x8006FF28: nop

    return;
    // 0x8006FF28: nop

;}
RECOMP_FUNC void func_80077034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007703C: jal         0x80061348
    // 0x80077040: addiu       $a0, $zero, 0x494
    ctx->r4 = ADD32(0, 0X494);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077040: addiu       $a0, $zero, 0x494
    ctx->r4 = ADD32(0, 0X494);
    after_0:
    // 0x80077044: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80077048: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007704C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077050: b           L_80077060
    // 0x80077054: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80077060;
    // 0x80077054: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077058: b           L_80077060
    // 0x8007705C: nop

        goto L_80077060;
    // 0x8007705C: nop

L_80077060:
    // 0x80077060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077068: jr          $ra
    // 0x8007706C: nop

    return;
    // 0x8007706C: nop

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
RECOMP_FUNC void func_800338D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800338D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800338D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800338D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800338DC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800338E0: addiu       $t6, $t6, 0x1918
    ctx->r14 = ADD32(ctx->r14, 0X1918);
    // 0x800338E4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800338E8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800338EC: nop

    // 0x800338F0: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800338F4: nop

    // 0x800338F8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800338FC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80033900: nop

    // 0x80033904: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80033908: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x8003390C: nop

    // 0x80033910: blez        $t0, L_800339C0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80033914: nop
    
            goto L_800339C0;
    }
    // 0x80033914: nop

    // 0x80033918: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8003391C: nop

    // 0x80033920: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x80033924: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x80033928: nop

    // 0x8003392C: blez        $t2, L_800339B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80033930: nop
    
            goto L_800339B0;
    }
    // 0x80033930: nop

L_80033934:
    // 0x80033934: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80033938: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8003393C: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80033940: jal         0x800C143C
    // 0x80033944: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_0;
    // 0x80033944: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80033948: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8003394C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80033950: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80033954: nop

    // 0x80033958: bne         $t5, $at, L_80033994
    if (ctx->r13 != ctx->r1) {
        // 0x8003395C: nop
    
            goto L_80033994;
    }
    // 0x8003395C: nop

    // 0x80033960: b           L_80033968
    // 0x80033964: nop

        goto L_80033968;
    // 0x80033964: nop

L_80033968:
    // 0x80033968: jal         0x80099520
    // 0x8003396C: nop

    func_80099520(rdram, ctx);
        goto after_1;
    // 0x8003396C: nop

    after_1:
    // 0x80033970: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80033974: nop

    // 0x80033978: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x8003397C: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80033980: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x80033984: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80033988: sw          $t8, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r24;
    // 0x8003398C: b           L_80033994
    // 0x80033990: nop

        goto L_80033994;
    // 0x80033990: nop

L_80033994:
    // 0x80033994: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80033998: nop

    // 0x8003399C: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x800339A0: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x800339A4: nop

    // 0x800339A8: bgtz        $t0, L_80033934
    if (SIGNED(ctx->r8) > 0) {
        // 0x800339AC: nop
    
            goto L_80033934;
    }
    // 0x800339AC: nop

L_800339B0:
    // 0x800339B0: jal         0x80098820
    // 0x800339B4: nop

    func_80098820(rdram, ctx);
        goto after_2;
    // 0x800339B4: nop

    after_2:
    // 0x800339B8: jal         0x80098868
    // 0x800339BC: nop

    func_80098868(rdram, ctx);
        goto after_3;
    // 0x800339BC: nop

    after_3:
L_800339C0:
    // 0x800339C0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800339C4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800339C8: nop

    // 0x800339CC: bne         $t1, $zero, L_80033C3C
    if (ctx->r9 != 0) {
        // 0x800339D0: nop
    
            goto L_80033C3C;
    }
    // 0x800339D0: nop

L_800339D4:
    // 0x800339D4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800339D8: addiu       $t2, $t2, 0x3DF8
    ctx->r10 = ADD32(ctx->r10, 0X3DF8);
    // 0x800339DC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800339E0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800339E4: jal         0x800C143C
    // 0x800339E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_4;
    // 0x800339E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800339EC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800339F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800339F4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800339F8: nop

    // 0x800339FC: bne         $t4, $at, L_80033C2C
    if (ctx->r12 != ctx->r1) {
        // 0x80033A00: nop
    
            goto L_80033C2C;
    }
    // 0x80033A00: nop

    // 0x80033A04: b           L_80033A0C
    // 0x80033A08: nop

        goto L_80033A0C;
    // 0x80033A08: nop

L_80033A0C:
    // 0x80033A0C: jal         0x80032604
    // 0x80033A10: nop

    func_80032604(rdram, ctx);
        goto after_5;
    // 0x80033A10: nop

    after_5:
    // 0x80033A14: jal         0x80096474
    // 0x80033A18: nop

    func_80096474(rdram, ctx);
        goto after_6;
    // 0x80033A18: nop

    after_6:
    // 0x80033A1C: jal         0x800C4160
    // 0x80033A20: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_7;
    // 0x80033A20: nop

    after_7:
    // 0x80033A24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80033A28: jal         0x8008ECCC
    // 0x80033A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_8;
    // 0x80033A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80033A30: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80033A34: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80033A38: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80033A3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80033A40: jal         0x8008EC8C
    // 0x80033A44: nop

    func_8008EC8C(rdram, ctx);
        goto after_9;
    // 0x80033A44: nop

    after_9:
    // 0x80033A48: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80033A4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80033A50: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80033A54: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80033A58: jal         0x8008ECAC
    // 0x80033A5C: nop

    func_8008ECAC(rdram, ctx);
        goto after_10;
    // 0x80033A5C: nop

    after_10:
    // 0x80033A60: jal         0x80090754
    // 0x80033A64: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80090754(rdram, ctx);
        goto after_11;
    // 0x80033A64: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_11:
    // 0x80033A68: jal         0x80090728
    // 0x80033A6C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090728(rdram, ctx);
        goto after_12;
    // 0x80033A6C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_12:
    // 0x80033A70: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80033A74: jal         0x8008EAA8
    // 0x80033A78: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8008EAA8(rdram, ctx);
        goto after_13;
    // 0x80033A78: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_13:
    // 0x80033A7C: jal         0x800045AC
    // 0x80033A80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_14;
    // 0x80033A80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x80033A84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80033A88: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80033A8C: nop

    // 0x80033A90: lw          $t7, 0x20C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X20C);
    // 0x80033A94: nop

    // 0x80033A98: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80033A9C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80033AA0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80033AA4: sw          $t8, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r24;
    // 0x80033AA8: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80033AAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80033AB0: sw          $t6, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r14;
    // 0x80033AB4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80033AB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80033ABC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80033AC0: addiu       $a0, $a0, -0x16F0
    ctx->r4 = ADD32(ctx->r4, -0X16F0);
    // 0x80033AC4: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80033AC8: jal         0x8008ECE4
    // 0x80033ACC: nop

    func_8008ECE4(rdram, ctx);
        goto after_15;
    // 0x80033ACC: nop

    after_15:
    // 0x80033AD0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80033AD4: jal         0x8008EAA8
    // 0x80033AD8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8008EAA8(rdram, ctx);
        goto after_16;
    // 0x80033AD8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_16:
    // 0x80033ADC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80033AE0: nop

    // 0x80033AE4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80033AE8: nop

    // 0x80033AEC: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x80033AF0: jal         0x8005F064
    // 0x80033AF4: nop

    func_8005F064(rdram, ctx);
        goto after_17;
    // 0x80033AF4: nop

    after_17:
    // 0x80033AF8: beq         $v0, $zero, L_80033B14
    if (ctx->r2 == 0) {
        // 0x80033AFC: nop
    
            goto L_80033B14;
    }
    // 0x80033AFC: nop

    // 0x80033B00: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80033B04: jal         0x8008ECE4
    // 0x80033B08: addiu       $a0, $a0, -0x16D0
    ctx->r4 = ADD32(ctx->r4, -0X16D0);
    func_8008ECE4(rdram, ctx);
        goto after_18;
    // 0x80033B08: addiu       $a0, $a0, -0x16D0
    ctx->r4 = ADD32(ctx->r4, -0X16D0);
    after_18:
    // 0x80033B0C: b           L_80033B20
    // 0x80033B10: nop

        goto L_80033B20;
    // 0x80033B10: nop

L_80033B14:
    // 0x80033B14: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80033B18: jal         0x8008ECE4
    // 0x80033B1C: addiu       $a0, $a0, -0x16C4
    ctx->r4 = ADD32(ctx->r4, -0X16C4);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x80033B1C: addiu       $a0, $a0, -0x16C4
    ctx->r4 = ADD32(ctx->r4, -0X16C4);
    after_19:
L_80033B20:
    // 0x80033B20: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80033B24: jal         0x8008ECE4
    // 0x80033B28: addiu       $a0, $a0, -0x16B8
    ctx->r4 = ADD32(ctx->r4, -0X16B8);
    func_8008ECE4(rdram, ctx);
        goto after_20;
    // 0x80033B28: addiu       $a0, $a0, -0x16B8
    ctx->r4 = ADD32(ctx->r4, -0X16B8);
    after_20:
    // 0x80033B2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80033B30: jal         0x8008EAA8
    // 0x80033B34: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8008EAA8(rdram, ctx);
        goto after_21;
    // 0x80033B34: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_21:
    // 0x80033B38: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80033B3C: jal         0x8008ECE4
    // 0x80033B40: addiu       $a0, $a0, -0x16A8
    ctx->r4 = ADD32(ctx->r4, -0X16A8);
    func_8008ECE4(rdram, ctx);
        goto after_22;
    // 0x80033B40: addiu       $a0, $a0, -0x16A8
    ctx->r4 = ADD32(ctx->r4, -0X16A8);
    after_22:
    // 0x80033B44: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80033B48: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80033B4C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80033B50: lhu         $t5, 0xFF4($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XFF4);
    // 0x80033B54: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x80033B58: nop

    // 0x80033B5C: and         $t7, $t4, $t5
    ctx->r15 = ctx->r12 & ctx->r13;
    // 0x80033B60: beq         $t7, $zero, L_80033B8C
    if (ctx->r15 == 0) {
        // 0x80033B64: nop
    
            goto L_80033B8C;
    }
    // 0x80033B64: nop

    // 0x80033B68: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80033B6C: nop

    // 0x80033B70: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x80033B74: nop

    // 0x80033B78: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x80033B7C: jal         0x8005F0DC
    // 0x80033B80: nop

    func_8005F0DC(rdram, ctx);
        goto after_23;
    // 0x80033B80: nop

    after_23:
    // 0x80033B84: b           L_80033BCC
    // 0x80033B88: nop

        goto L_80033BCC;
    // 0x80033B88: nop

L_80033B8C:
    // 0x80033B8C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80033B90: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80033B94: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80033B98: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x80033B9C: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x80033BA0: nop

    // 0x80033BA4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x80033BA8: beq         $t2, $zero, L_80033BCC
    if (ctx->r10 == 0) {
        // 0x80033BAC: nop
    
            goto L_80033BCC;
    }
    // 0x80033BAC: nop

    // 0x80033BB0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80033BB4: nop

    // 0x80033BB8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80033BBC: nop

    // 0x80033BC0: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x80033BC4: jal         0x8005F268
    // 0x80033BC8: nop

    func_8005F268(rdram, ctx);
        goto after_24;
    // 0x80033BC8: nop

    after_24:
L_80033BCC:
    // 0x80033BCC: jal         0x800967D8
    // 0x80033BD0: nop

    func_800967D8(rdram, ctx);
        goto after_25;
    // 0x80033BD0: nop

    after_25:
    // 0x80033BD4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80033BD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80033BDC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80033BE0: lhu         $t7, 0x11A4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X11A4);
    // 0x80033BE4: lhu         $t5, 0x10F2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X10F2);
    // 0x80033BE8: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80033BEC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80033BF0: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80033BF4: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80033BF8: beq         $t0, $zero, L_80033C10
    if (ctx->r8 == 0) {
        // 0x80033BFC: nop
    
            goto L_80033C10;
    }
    // 0x80033BFC: nop

    // 0x80033C00: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80033C04: nop

    // 0x80033C08: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80033C0C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
L_80033C10:
    // 0x80033C10: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80033C14: addiu       $t3, $t3, 0x3DF8
    ctx->r11 = ADD32(ctx->r11, 0X3DF8);
    // 0x80033C18: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80033C1C: jal         0x80098D24
    // 0x80033C20: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_26;
    // 0x80033C20: nop

    after_26:
    // 0x80033C24: b           L_80033C2C
    // 0x80033C28: nop

        goto L_80033C2C;
    // 0x80033C28: nop

L_80033C2C:
    // 0x80033C2C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80033C30: nop

    // 0x80033C34: beq         $t4, $zero, L_800339D4
    if (ctx->r12 == 0) {
        // 0x80033C38: nop
    
            goto L_800339D4;
    }
    // 0x80033C38: nop

L_80033C3C:
    // 0x80033C3C: b           L_80033C44
    // 0x80033C40: nop

        goto L_80033C44;
    // 0x80033C40: nop

L_80033C44:
    // 0x80033C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80033C48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80033C4C: jr          $ra
    // 0x80033C50: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80033C50: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80033C54: nop

    // 0x80033C58: nop

    // 0x80033C5C: nop

;}
RECOMP_FUNC void func_8001EBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EBF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EBFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EC00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001EC04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001EC08: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EC0C: nop

    // 0x8001EC10: bltz        $t6, L_8001EC84
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001EC14: nop
    
            goto L_8001EC84;
    }
    // 0x8001EC14: nop

    // 0x8001EC18: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EC1C: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EC20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EC24: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001EC28: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EC2C: nop

    // 0x8001EC30: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EC34: bne         $t0, $zero, L_8001EC54
    if (ctx->r8 != 0) {
        // 0x8001EC38: nop
    
            goto L_8001EC54;
    }
    // 0x8001EC38: nop

    // 0x8001EC3C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001EC40: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001EC44: nop

    // 0x8001EC48: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001EC4C: beq         $t2, $zero, L_8001EC84
    if (ctx->r10 == 0) {
        // 0x8001EC50: nop
    
            goto L_8001EC84;
    }
    // 0x8001EC50: nop

L_8001EC54:
    // 0x8001EC54: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001EC58: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x8001EC5C: nop

    // 0x8001EC60: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x8001EC64: beq         $t4, $zero, L_8001EC7C
    if (ctx->r12 == 0) {
        // 0x8001EC68: nop
    
            goto L_8001EC7C;
    }
    // 0x8001EC68: nop

    // 0x8001EC6C: jal         0x800BDA58
    // 0x8001EC70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001EC70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x8001EC74: b           L_8001EC84
    // 0x8001EC78: nop

        goto L_8001EC84;
    // 0x8001EC78: nop

L_8001EC7C:
    // 0x8001EC7C: jal         0x800BDA58
    // 0x8001EC80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800BDA58(rdram, ctx);
        goto after_1;
    // 0x8001EC80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
L_8001EC84:
    // 0x8001EC84: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001EC88: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x8001EC8C: nop

    // 0x8001EC90: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8001EC94: beq         $t6, $zero, L_8001ECB0
    if (ctx->r14 == 0) {
        // 0x8001EC98: nop
    
            goto L_8001ECB0;
    }
    // 0x8001EC98: nop

    // 0x8001EC9C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ECA0: jal         0x8008ECE4
    // 0x8001ECA4: addiu       $a0, $a0, -0x24EC
    ctx->r4 = ADD32(ctx->r4, -0X24EC);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001ECA4: addiu       $a0, $a0, -0x24EC
    ctx->r4 = ADD32(ctx->r4, -0X24EC);
    after_2:
    // 0x8001ECA8: b           L_8001ECBC
    // 0x8001ECAC: nop

        goto L_8001ECBC;
    // 0x8001ECAC: nop

L_8001ECB0:
    // 0x8001ECB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ECB4: jal         0x8008ECE4
    // 0x8001ECB8: addiu       $a0, $a0, -0x24E4
    ctx->r4 = ADD32(ctx->r4, -0X24E4);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001ECB8: addiu       $a0, $a0, -0x24E4
    ctx->r4 = ADD32(ctx->r4, -0X24E4);
    after_3:
L_8001ECBC:
    // 0x8001ECBC: b           L_8001ECCC
    // 0x8001ECC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001ECCC;
    // 0x8001ECC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001ECC4: b           L_8001ECCC
    // 0x8001ECC8: nop

        goto L_8001ECCC;
    // 0x8001ECC8: nop

L_8001ECCC:
    // 0x8001ECCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ECD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001ECD4: jr          $ra
    // 0x8001ECD8: nop

    return;
    // 0x8001ECD8: nop

;}
RECOMP_FUNC void func_800687E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800687EC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800687F0: nop

    // 0x800687F4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800687F8: nop

    // 0x800687FC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068800: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068804: jr          $ra
    // 0x80068808: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068808: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006880C: jr          $ra
    // 0x80068810: nop

    return;
    // 0x80068810: nop

    // 0x80068814: jr          $ra
    // 0x80068818: nop

    return;
    // 0x80068818: nop

;}
RECOMP_FUNC void func_80065158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065158: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006515C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065160: nop

    // 0x80065164: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x80065168: nop

    // 0x8006516C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80065170: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065174: jr          $ra
    // 0x80065178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006517C: jr          $ra
    // 0x80065180: nop

    return;
    // 0x80065180: nop

    // 0x80065184: jr          $ra
    // 0x80065188: nop

    return;
    // 0x80065188: nop

;}
RECOMP_FUNC void func_8005F064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F064: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005F068: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8005F06C: bgez        $a0, L_8005F07C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005F070: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8005F07C;
    }
    // 0x8005F070: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8005F074: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8005F078: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8005F07C:
    // 0x8005F07C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8005F080: bgez        $a0, L_8005F094
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005F084: andi        $t7, $a0, 0x7
        ctx->r15 = ctx->r4 & 0X7;
            goto L_8005F094;
    }
    // 0x8005F084: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x8005F088: beq         $t7, $zero, L_8005F094
    if (ctx->r15 == 0) {
        // 0x8005F08C: nop
    
            goto L_8005F094;
    }
    // 0x8005F08C: nop

    // 0x8005F090: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
L_8005F094:
    // 0x8005F094: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8005F098: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005F09C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005F0A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005F0A4: lbu         $t9, 0x680($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X680);
    // 0x8005F0A8: nop

    // 0x8005F0AC: srav        $t0, $t9, $a0
    ctx->r8 = S32(SIGNED(ctx->r25) >> (ctx->r4 & 31));
    // 0x8005F0B0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8005F0B4: beq         $t1, $zero, L_8005F0C4
    if (ctx->r9 == 0) {
        // 0x8005F0B8: nop
    
            goto L_8005F0C4;
    }
    // 0x8005F0B8: nop

    // 0x8005F0BC: b           L_8005F0D4
    // 0x8005F0C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005F0D4;
    // 0x8005F0C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005F0C4:
    // 0x8005F0C4: b           L_8005F0D4
    // 0x8005F0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005F0D4;
    // 0x8005F0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F0CC: b           L_8005F0D4
    // 0x8005F0D0: nop

        goto L_8005F0D4;
    // 0x8005F0D0: nop

L_8005F0D4:
    // 0x8005F0D4: jr          $ra
    // 0x8005F0D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005F0D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80016F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016F80: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80016F84: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80016F88: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80016F8C: lw          $t6, 0x1A8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A8);
    // 0x80016F90: nop

    // 0x80016F94: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016F98: beq         $t7, $zero, L_80017198
    if (ctx->r15 == 0) {
        // 0x80016F9C: nop
    
            goto L_80017198;
    }
    // 0x80016F9C: nop

    // 0x80016FA0: lw          $t8, 0x1A8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1A8);
    // 0x80016FA4: nop

    // 0x80016FA8: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80016FAC: beq         $t9, $zero, L_80016FBC
    if (ctx->r25 == 0) {
        // 0x80016FB0: nop
    
            goto L_80016FBC;
    }
    // 0x80016FB0: nop

    // 0x80016FB4: b           L_80017190
    // 0x80016FB8: nop

        goto L_80017190;
    // 0x80016FB8: nop

L_80016FBC:
    // 0x80016FBC: lwc1        $f4, 0x1E8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x80016FC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80016FC4: nop

    // 0x80016FC8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80016FCC: nop

    // 0x80016FD0: bc1f        L_800170A0
    if (!c1cs) {
        // 0x80016FD4: nop
    
            goto L_800170A0;
    }
    // 0x80016FD4: nop

    // 0x80016FD8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80016FDC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80016FE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80016FE4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80016FE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016FEC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80016FF0: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80016FF4: lwc1        $f4, 0x1E8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x80016FF8: nop

    // 0x80016FFC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80017000: sub.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
    // 0x80017004: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80017008: swc1        $f8, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f8.u32l;
    // 0x8001700C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017010: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017014: lwc1        $f16, 0x1F0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1F0);
    // 0x80017018: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001701C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80017020: lwc1        $f18, 0x6190($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x80017024: nop

    // 0x80017028: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8001702C: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x80017030: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017034: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017038: lwc1        $f8, 0x1F4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x8001703C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017040: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80017044: lwc1        $f18, 0x6198($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80017048: nop

    // 0x8001704C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80017050: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
    // 0x80017054: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017058: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001705C: lwc1        $f10, 0x1F8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F8);
    // 0x80017060: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017064: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80017068: lwc1        $f18, 0x6194($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x8001706C: nop

    // 0x80017070: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80017074: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80017078: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001707C: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017080: lwc1        $f6, 0x1FC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1FC);
    // 0x80017084: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017088: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001708C: lwc1        $f18, 0x619C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80017090: nop

    // 0x80017094: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80017098: b           L_80017190
    // 0x8001709C: swc1        $f16, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f16.u32l;
        goto L_80017190;
    // 0x8001709C: swc1        $f16, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f16.u32l;
L_800170A0:
    // 0x800170A0: lw          $t0, 0x1A8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1A8);
    // 0x800170A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800170A8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800170AC: sw          $t1, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r9;
    // 0x800170B0: lw          $t2, 0x1A8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1A8);
    // 0x800170B4: nop

    // 0x800170B8: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800170BC: sw          $t3, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r11;
    // 0x800170C0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800170C4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800170C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800170CC: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800170D0: nop

    // 0x800170D4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800170D8: nop

    // 0x800170DC: bc1f        L_80017158
    if (!c1cs) {
        // 0x800170E0: nop
    
            goto L_80017158;
    }
    // 0x800170E0: nop

    // 0x800170E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800170E8: lwc1        $f10, 0x61C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800170EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800170F0: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800170F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800170F8: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800170FC: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
    // 0x80017100: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017104: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80017108: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001710C: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80017110: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017114: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80017118: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
    // 0x8001711C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017120: lwc1        $f10, 0x61C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80017124: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017128: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8001712C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017130: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80017134: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
    // 0x80017138: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001713C: lwc1        $f16, 0x61D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x80017140: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017144: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80017148: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001714C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80017150: b           L_80017190
    // 0x80017154: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
        goto L_80017190;
    // 0x80017154: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_80017158:
    // 0x80017158: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8001715C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017160: lwc1        $f10, 0xCC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x80017164: nop

    // 0x80017168: swc1        $f10, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f10.u32l;
    // 0x8001716C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017170: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x80017174: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80017178: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001717C: lwc1        $f18, 0xD0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x80017180: nop

    // 0x80017184: swc1        $f18, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f18.u32l;
    // 0x80017188: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001718C: swc1        $f18, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f18.u32l;
L_80017190:
    // 0x80017190: b           L_800171BC
    // 0x80017194: nop

        goto L_800171BC;
    // 0x80017194: nop

L_80017198:
    // 0x80017198: lw          $t7, 0x1A8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1A8);
    // 0x8001719C: nop

    // 0x800171A0: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800171A4: beq         $t8, $zero, L_800171BC
    if (ctx->r24 == 0) {
        // 0x800171A8: nop
    
            goto L_800171BC;
    }
    // 0x800171A8: nop

    // 0x800171AC: lw          $t9, 0x1A8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A8);
    // 0x800171B0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800171B4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800171B8: sw          $t0, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r8;
L_800171BC:
    // 0x800171BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800171C0: lwc1        $f8, 0x6190($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800171C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800171C8: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800171CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800171D0: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800171D4: nop

    // 0x800171D8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800171DC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800171E0: nop

    // 0x800171E4: bc1f        L_80017208
    if (!c1cs) {
        // 0x800171E8: nop
    
            goto L_80017208;
    }
    // 0x800171E8: nop

    // 0x800171EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800171F0: lwc1        $f10, 0x61C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800171F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800171F8: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800171FC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017200: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80017204: swc1        $f16, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f16.u32l;
L_80017208:
    // 0x80017208: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001720C: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80017210: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017214: lwc1        $f8, 0x61C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80017218: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001721C: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80017220: nop

    // 0x80017224: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80017228: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8001722C: nop

    // 0x80017230: bc1f        L_80017254
    if (!c1cs) {
        // 0x80017234: nop
    
            goto L_80017254;
    }
    // 0x80017234: nop

    // 0x80017238: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001723C: lwc1        $f18, 0x61C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80017240: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017244: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80017248: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001724C: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80017250: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
L_80017254:
    // 0x80017254: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017258: lwc1        $f6, 0x6198($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x8001725C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017260: lwc1        $f4, 0x61C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80017264: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017268: lwc1        $f10, 0x7224($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8001726C: nop

    // 0x80017270: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017274: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80017278: nop

    // 0x8001727C: bc1f        L_800172A0
    if (!c1cs) {
        // 0x80017280: nop
    
            goto L_800172A0;
    }
    // 0x80017280: nop

    // 0x80017284: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017288: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8001728C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017290: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80017294: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017298: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8001729C: swc1        $f4, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f4.u32l;
L_800172A0:
    // 0x800172A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172A4: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800172A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172AC: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800172B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800172B4: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800172B8: nop

    // 0x800172BC: sub.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800172C0: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800172C4: nop

    // 0x800172C8: bc1f        L_800172EC
    if (!c1cs) {
        // 0x800172CC: nop
    
            goto L_800172EC;
    }
    // 0x800172CC: nop

    // 0x800172D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172D4: lwc1        $f8, 0x61D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800172D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800172DC: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800172E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172E4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800172E8: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_800172EC:
    // 0x800172EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172F0: lwc1        $f18, 0x6190($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800172F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800172F8: nop

    // 0x800172FC: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80017300: nop

    // 0x80017304: bc1f        L_80017318
    if (!c1cs) {
        // 0x80017308: nop
    
            goto L_80017318;
    }
    // 0x80017308: nop

    // 0x8001730C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80017310: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017314: swc1        $f16, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f16.u32l;
L_80017318:
    // 0x80017318: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001731C: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80017320: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017324: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017328: nop

    // 0x8001732C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80017330: nop

    // 0x80017334: bc1f        L_8001734C
    if (!c1cs) {
        // 0x80017338: nop
    
            goto L_8001734C;
    }
    // 0x80017338: nop

    // 0x8001733C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017344: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017348: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
L_8001734C:
    // 0x8001734C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017350: lwc1        $f18, 0x6194($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80017354: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80017358: nop

    // 0x8001735C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80017360: nop

    // 0x80017364: bc1f        L_80017378
    if (!c1cs) {
        // 0x80017368: nop
    
            goto L_80017378;
    }
    // 0x80017368: nop

    // 0x8001736C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80017370: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017374: swc1        $f16, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f16.u32l;
L_80017378:
    // 0x80017378: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001737C: lwc1        $f8, 0x619C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80017380: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017388: nop

    // 0x8001738C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80017390: nop

    // 0x80017394: bc1f        L_800173AC
    if (!c1cs) {
        // 0x80017398: nop
    
            goto L_800173AC;
    }
    // 0x80017398: nop

    // 0x8001739C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800173A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800173A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800173A8: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_800173AC:
    // 0x800173AC: b           L_800173BC
    // 0x800173B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800173BC;
    // 0x800173B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800173B4: b           L_800173BC
    // 0x800173B8: nop

        goto L_800173BC;
    // 0x800173B8: nop

L_800173BC:
    // 0x800173BC: jr          $ra
    // 0x800173C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800173C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80086F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F98: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80086FA0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80086FA4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80086FA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80086FAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086FB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80086FB4: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80086FB8: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80086FBC: lhu         $t9, 0x46($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X46);
    // 0x80086FC0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086FC4: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086FC8: beq         $t0, $zero, L_80087058
    if (ctx->r8 == 0) {
        // 0x80086FCC: nop
    
            goto L_80087058;
    }
    // 0x80086FCC: nop

    // 0x80086FD0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80086FD4: jal         0x8008A518
    // 0x80086FD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80086FD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80086FDC: beq         $v0, $zero, L_80087058
    if (ctx->r2 == 0) {
        // 0x80086FE0: nop
    
            goto L_80087058;
    }
    // 0x80086FE0: nop

    // 0x80086FE4: lhu         $s0, 0x34($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X34);
    // 0x80086FE8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086FEC: beq         $s0, $at, L_80087008
    if (ctx->r16 == ctx->r1) {
        // 0x80086FF0: nop
    
            goto L_80087008;
    }
    // 0x80086FF0: nop

    // 0x80086FF4: addiu       $at, $zero, 0x4006
    ctx->r1 = ADD32(0, 0X4006);
    // 0x80086FF8: beq         $s0, $at, L_80087030
    if (ctx->r16 == ctx->r1) {
        // 0x80086FFC: nop
    
            goto L_80087030;
    }
    // 0x80086FFC: nop

    // 0x80087000: b           L_80087058
    // 0x80087004: nop

        goto L_80087058;
    // 0x80087004: nop

L_80087008:
    // 0x80087008: jal         0x8008CE48
    // 0x8008700C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x8008700C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80087010: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80087014: nop

    // 0x80087018: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8008701C: nop

    // 0x80087020: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80087024: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80087028: b           L_800870AC
    // 0x8008702C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_800870AC;
    // 0x8008702C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80087030:
    // 0x80087030: jal         0x8008CE48
    // 0x80087034: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80087034: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80087038: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008703C: nop

    // 0x80087040: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80087044: nop

    // 0x80087048: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x8008704C: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80087050: b           L_800870AC
    // 0x80087054: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_800870AC;
    // 0x80087054: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_80087058:
    // 0x80087058: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008705C: lhu         $t9, 0x101C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X101C);
    // 0x80087060: lhu         $t7, 0x46($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X46);
    // 0x80087064: nop

    // 0x80087068: and         $t8, $t7, $t9
    ctx->r24 = ctx->r15 & ctx->r25;
    // 0x8008706C: beq         $t8, $zero, L_8008709C
    if (ctx->r24 == 0) {
        // 0x80087070: nop
    
            goto L_8008709C;
    }
    // 0x80087070: nop

    // 0x80087074: jal         0x8008CE48
    // 0x80087078: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80087078: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x8008707C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80087080: nop

    // 0x80087084: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x80087088: nop

    // 0x8008708C: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80087090: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80087094: b           L_800870AC
    // 0x80087098: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_800870AC;
    // 0x80087098: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8008709C:
    // 0x8008709C: b           L_800870AC
    // 0x800870A0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_800870AC;
    // 0x800870A0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800870A4: b           L_800870AC
    // 0x800870A8: nop

        goto L_800870AC;
    // 0x800870A8: nop

L_800870AC:
    // 0x800870AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800870B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800870B4: jr          $ra
    // 0x800870B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800870B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800680B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800680B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800680B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800680B8: nop

    // 0x800680BC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x800680C0: nop

    // 0x800680C4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800680C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800680CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800680D0: beq         $v0, $zero, L_80068108
    if (ctx->r2 == 0) {
        // 0x800680D4: nop
    
            goto L_80068108;
    }
    // 0x800680D4: nop

    // 0x800680D8: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800680DC: nop

    // 0x800680E0: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800680E4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800680E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800680EC: beq         $v0, $zero, L_80068108
    if (ctx->r2 == 0) {
        // 0x800680F0: nop
    
            goto L_80068108;
    }
    // 0x800680F0: nop

    // 0x800680F4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800680F8: nop

    // 0x800680FC: slti        $t9, $v0, 0x1F4
    ctx->r25 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068100: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80068104: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80068108:
    // 0x80068108: jr          $ra
    // 0x8006810C: nop

    return;
    // 0x8006810C: nop

    // 0x80068110: jr          $ra
    // 0x80068114: nop

    return;
    // 0x80068114: nop

    // 0x80068118: jr          $ra
    // 0x8006811C: nop

    return;
    // 0x8006811C: nop

;}
RECOMP_FUNC void func_8006D360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D360: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D364: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D368: nop

    // 0x8006D36C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D370: nop

    // 0x8006D374: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D378: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D37C: jr          $ra
    // 0x8006D380: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D380: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D384: jr          $ra
    // 0x8006D388: nop

    return;
    // 0x8006D388: nop

    // 0x8006D38C: jr          $ra
    // 0x8006D390: nop

    return;
    // 0x8006D390: nop

;}
RECOMP_FUNC void func_8006499C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006499C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800649A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800649A4: jal         0x80061488
    // 0x800649A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800649A8: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x800649AC: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800649B4: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x800649B8: nop
    
            goto L_80064A48;
    }
    // 0x800649B8: nop

    // 0x800649BC: jal         0x80061488
    // 0x800649C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x800649C0: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x800649C4: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800649CC: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x800649D0: nop
    
            goto L_80064A48;
    }
    // 0x800649D0: nop

    // 0x800649D4: jal         0x80061488
    // 0x800649D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x800649D8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800649DC: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800649E4: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x800649E8: nop
    
            goto L_80064A48;
    }
    // 0x800649E8: nop

    // 0x800649EC: jal         0x80061488
    // 0x800649F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800649F0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800649F4: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800649F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800649FC: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x80064A00: nop
    
            goto L_80064A48;
    }
    // 0x80064A00: nop

    // 0x80064A04: jal         0x80061488
    // 0x80064A08: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064A08: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064A0C: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064A10: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064A14: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x80064A18: nop
    
            goto L_80064A48;
    }
    // 0x80064A18: nop

    // 0x80064A1C: jal         0x8005F064
    // 0x80064A20: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064A20: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064A24: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064A28: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064A2C: beq         $v0, $zero, L_80064A48
    if (ctx->r2 == 0) {
        // 0x80064A30: nop
    
            goto L_80064A48;
    }
    // 0x80064A30: nop

    // 0x80064A34: jal         0x80061348
    // 0x80064A38: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064A38: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064A3C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064A40: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064A44: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064A48:
    // 0x80064A48: b           L_80064A58
    // 0x80064A4C: nop

        goto L_80064A58;
    // 0x80064A4C: nop

    // 0x80064A50: b           L_80064A58
    // 0x80064A54: nop

        goto L_80064A58;
    // 0x80064A54: nop

L_80064A58:
    // 0x80064A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064A5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064A60: jr          $ra
    // 0x80064A64: nop

    return;
    // 0x80064A64: nop

;}
