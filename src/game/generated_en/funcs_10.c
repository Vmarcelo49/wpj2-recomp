#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80061F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F08: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061F0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061F10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80061F14: nop

    // 0x80061F18: lh          $t7, 0x30($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X30);
    // 0x80061F1C: nop

    // 0x80061F20: slti        $at, $t7, 0x384
    ctx->r1 = SIGNED(ctx->r15) < 0X384 ? 1 : 0;
    // 0x80061F24: beq         $at, $zero, L_80061F68
    if (ctx->r1 == 0) {
        // 0x80061F28: nop

            goto L_80061F68;
    }
    // 0x80061F28: nop

    // 0x80061F2C: lh          $t8, 0x32($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X32);
    // 0x80061F30: nop

    // 0x80061F34: slti        $at, $t8, 0x384
    ctx->r1 = SIGNED(ctx->r24) < 0X384 ? 1 : 0;
    // 0x80061F38: beq         $at, $zero, L_80061F68
    if (ctx->r1 == 0) {
        // 0x80061F3C: nop

            goto L_80061F68;
    }
    // 0x80061F3C: nop

    // 0x80061F40: lh          $t9, 0x34($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X34);
    // 0x80061F44: nop

    // 0x80061F48: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80061F4C: beq         $at, $zero, L_80061F68
    if (ctx->r1 == 0) {
        // 0x80061F50: nop

            goto L_80061F68;
    }
    // 0x80061F50: nop

    // 0x80061F54: lh          $t0, 0x36($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X36);
    // 0x80061F58: nop

    // 0x80061F5C: slti        $at, $t0, 0x384
    ctx->r1 = SIGNED(ctx->r8) < 0X384 ? 1 : 0;
    // 0x80061F60: bne         $at, $zero, L_80061FE4
    if (ctx->r1 != 0) {
        // 0x80061F64: nop

            goto L_80061FE4;
    }
    // 0x80061F64: nop

L_80061F68:
    // 0x80061F68: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80061F6C: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80061F70: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80061F74: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_80061F78:
    // 0x80061F78: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061F7C: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061F80: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80061F84: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80061F88: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80061F8C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80061F90: addu        $t0, $t3, $t6
    ctx->r8 = ADD32(ctx->r11, ctx->r14);
    // 0x80061F94: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80061F98: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061F9C: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80061FA0: nop

    // 0x80061FA4: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061FA8: beq         $at, $zero, L_80061FC0
    if (ctx->r1 == 0) {
        // 0x80061FAC: nop

            goto L_80061FC0;
    }
    // 0x80061FAC: nop

    // 0x80061FB0: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061FB4: nop

    // 0x80061FB8: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80061FBC: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
L_80061FC0:
    // 0x80061FC0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80061FC4: nop

    // 0x80061FC8: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80061FCC: slti        $at, $t7, 0x1B
    ctx->r1 = SIGNED(ctx->r15) < 0X1B ? 1 : 0;
    // 0x80061FD0: bne         $at, $zero, L_80061F78
    if (ctx->r1 != 0) {
        // 0x80061FD4: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80061F78;
    }
    // 0x80061FD4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80061FD8: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80061FDC: b           L_80061FF4
    // 0x80061FE0: nop

        goto L_80061FF4;
    // 0x80061FE0: nop

L_80061FE4:
    // 0x80061FE4: b           L_80061FF4
    // 0x80061FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061FF4;
    // 0x80061FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061FEC: b           L_80061FF4
    // 0x80061FF0: nop

        goto L_80061FF4;
    // 0x80061FF0: nop

L_80061FF4:
    // 0x80061FF4: jr          $ra
    // 0x80061FF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80061FF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80061FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061FFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80062000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062004: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80062008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006200C: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x80062010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80062014: beq         $t6, $at, L_80062090
    if (ctx->r14 == ctx->r1) {
        // 0x80062018: nop

            goto L_80062090;
    }
    // 0x80062018: nop

L_8006201C:
    // 0x8006201C: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x80062020: lui         $t9, 0x809D
    ctx->r25 = S32(0X809D << 16);
    // 0x80062024: addiu       $t9, $t9, 0x546C
    ctx->r25 = ADD32(ctx->r25, 0X546C);
    // 0x80062028: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8006202C: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80062030: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80062034: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80062038: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8006203C: jal         0x800BD1FC
    // 0x80062040: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80062040: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x80062044: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80062048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006204C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80062050: jal         0x800BD218
    // 0x80062054: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80062054: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x80062058: jal         0x800620A8
    // 0x8006205C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800620A8(rdram, ctx);
        goto after_2;
    // 0x8006205C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80062060: beq         $v0, $zero, L_8006207C
    if (ctx->r2 == 0) {
        // 0x80062064: nop

            goto L_8006207C;
    }
    // 0x80062064: nop

    // 0x80062068: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x8006206C: nop

    // 0x80062070: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80062074: b           L_80062080
    // 0x80062078: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
        goto L_80062080;
    // 0x80062078: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
L_8006207C:
    // 0x8006207C: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
L_80062080:
    // 0x80062080: lh          $t2, 0x3A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3A);
    // 0x80062084: nop

    // 0x80062088: bne         $t2, $zero, L_8006201C
    if (ctx->r10 != 0) {
        // 0x8006208C: nop

            goto L_8006201C;
    }
    // 0x8006208C: nop

L_80062090:
    // 0x80062090: b           L_80062098
    // 0x80062094: nop

        goto L_80062098;
    // 0x80062094: nop

L_80062098:
    // 0x80062098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006209C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800620A0: jr          $ra
    // 0x800620A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800620A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800620A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800620A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800620AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800620B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800620B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800620B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800620BC: nop

    // 0x800620C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800620C4: nop

    // 0x800620C8: beq         $t7, $zero, L_800620F8
    if (ctx->r15 == 0) {
        // 0x800620CC: nop

            goto L_800620F8;
    }
    // 0x800620CC: nop

    // 0x800620D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800620D4: nop

    // 0x800620D8: lbu         $t1, 0x4($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X4);
    // 0x800620DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800620E0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800620E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800620E8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800620EC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800620F0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800620F4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_800620F8:
    // 0x800620F8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800620FC: nop

    // 0x80062100: lh          $t5, 0xC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XC);
    // 0x80062104: nop

    // 0x80062108: beq         $t5, $zero, L_800625D8
    if (ctx->r13 == 0) {
        // 0x8006210C: nop

            goto L_800625D8;
    }
    // 0x8006210C: nop

    // 0x80062110: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80062114: nop

    // 0x80062118: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8006211C: nop

    // 0x80062120: beq         $t7, $zero, L_80062174
    if (ctx->r15 == 0) {
        // 0x80062124: nop

            goto L_80062174;
    }
    // 0x80062124: nop

    // 0x80062128: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8006212C: nop

    // 0x80062130: lw          $t9, 0x8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X8);
    // 0x80062134: nop

    // 0x80062138: jalr        $t9
    // 0x8006213C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006213C: nop

    after_0:
    // 0x80062140: bne         $v0, $zero, L_80062174
    if (ctx->r2 != 0) {
        // 0x80062144: nop

            goto L_80062174;
    }
    // 0x80062144: nop

    // 0x80062148: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006214C: nop

    // 0x80062150: lbu         $v0, 0xE($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0XE);
    // 0x80062154: nop

    // 0x80062158: andi        $t1, $v0, 0x80
    ctx->r9 = ctx->r2 & 0X80;
    // 0x8006215C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80062160: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80062164: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80062168: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006216C: b           L_8006260C
    // 0x80062170: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8006260C;
    // 0x80062170: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80062174:
    // 0x80062174: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80062178: nop

    // 0x8006217C: lbu         $t4, 0xE($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XE);
    // 0x80062180: nop

    // 0x80062184: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x80062188: sltiu       $at, $t5, 0xA
    ctx->r1 = ctx->r13 < 0XA ? 1 : 0;
    // 0x8006218C: beq         $at, $zero, L_800625D8
    if (ctx->r1 == 0) {
        // 0x80062190: nop

            goto L_800625D8;
    }
    // 0x80062190: nop

    // 0x80062194: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80062198: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8006219C: addu        $at, $at, $t5
    gpr jr_addend_800621A8 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800621A0: lw          $t5, -0xE30($at)
    ctx->r13 = ADD32(ctx->r1, -0XE30);
    // 0x800621A4: nop

    // 0x800621A8: jr          $t5
    // 0x800621AC: nop

    switch (jr_addend_800621A8 >> 2) {
        case 0: goto L_800623F0; break;
        case 1: goto L_800621B0; break;
        case 2: goto L_8006228C; break;
        case 3: goto L_80062350; break;
        case 4: goto L_80062370; break;
        case 5: goto L_80062390; break;
        case 6: goto L_800623B0; break;
        case 7: goto L_800623D0; break;
        case 8: goto L_80062578; break;
        case 9: goto L_800625A8; break;
        default: switch_error(__func__, 0x800621A8, 0x800EF1D0);
    }
    // 0x800621AC: nop

L_800621B0:
    // 0x800621B0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800621B4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800621B8: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800621BC: lh          $t8, 0xC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XC);
    // 0x800621C0: nop

    // 0x800621C4: bne         $t7, $t8, L_800621E4
    if (ctx->r15 != ctx->r24) {
        // 0x800621C8: nop

            goto L_800621E4;
    }
    // 0x800621C8: nop

    // 0x800621CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800621D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800621D4: jal         0x8006261C
    // 0x800621D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006261C(rdram, ctx);
        goto after_1;
    // 0x800621D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800621DC: b           L_80062284
    // 0x800621E0: nop

        goto L_80062284;
    // 0x800621E0: nop

L_800621E4:
    // 0x800621E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800621E8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800621EC: lh          $t0, 0x2($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2);
    // 0x800621F0: lh          $t3, 0xC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XC);
    // 0x800621F4: nop

    // 0x800621F8: bne         $t0, $t3, L_8006221C
    if (ctx->r8 != ctx->r11) {
        // 0x800621FC: nop

            goto L_8006221C;
    }
    // 0x800621FC: nop

    // 0x80062200: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062204: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80062208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006220C: jal         0x8006261C
    // 0x80062210: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_8006261C(rdram, ctx);
        goto after_2;
    // 0x80062210: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_2:
    // 0x80062214: b           L_80062284
    // 0x80062218: nop

        goto L_80062284;
    // 0x80062218: nop

L_8006221C:
    // 0x8006221C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80062220: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80062224: lh          $t5, 0x4($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4);
    // 0x80062228: lh          $t9, 0xC($t6)
    ctx->r25 = MEM_H(ctx->r14, 0XC);
    // 0x8006222C: nop

    // 0x80062230: bne         $t5, $t9, L_80062254
    if (ctx->r13 != ctx->r25) {
        // 0x80062234: nop

            goto L_80062254;
    }
    // 0x80062234: nop

    // 0x80062238: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006223C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80062240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062244: jal         0x8006261C
    // 0x80062248: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8006261C(rdram, ctx);
        goto after_3;
    // 0x80062248: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x8006224C: b           L_80062284
    // 0x80062250: nop

        goto L_80062284;
    // 0x80062250: nop

L_80062254:
    // 0x80062254: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80062258: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8006225C: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80062260: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x80062264: nop

    // 0x80062268: bne         $t8, $t2, L_80062284
    if (ctx->r24 != ctx->r10) {
        // 0x8006226C: nop

            goto L_80062284;
    }
    // 0x8006226C: nop

    // 0x80062270: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062274: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80062278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006227C: jal         0x8006261C
    // 0x80062280: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_8006261C(rdram, ctx);
        goto after_4;
    // 0x80062280: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_4:
L_80062284:
    // 0x80062284: b           L_800625D8
    // 0x80062288: nop

        goto L_800625D8;
    // 0x80062288: nop

L_8006228C:
    // 0x8006228C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80062290: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80062294: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80062298: lh          $t6, 0xC($t4)
    ctx->r14 = MEM_H(ctx->r12, 0XC);
    // 0x8006229C: nop

    // 0x800622A0: beq         $t3, $t6, L_800622B8
    if (ctx->r11 == ctx->r14) {
        // 0x800622A4: nop

            goto L_800622B8;
    }
    // 0x800622A4: nop

    // 0x800622A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800622AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800622B0: jal         0x8006261C
    // 0x800622B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006261C(rdram, ctx);
        goto after_5;
    // 0x800622B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_800622B8:
    // 0x800622B8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800622BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800622C0: lh          $t9, 0x2($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X2);
    // 0x800622C4: lh          $t1, 0xC($t7)
    ctx->r9 = MEM_H(ctx->r15, 0XC);
    // 0x800622C8: nop

    // 0x800622CC: beq         $t9, $t1, L_800622E8
    if (ctx->r25 == ctx->r9) {
        // 0x800622D0: nop

            goto L_800622E8;
    }
    // 0x800622D0: nop

    // 0x800622D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800622D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800622DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800622E0: jal         0x8006261C
    // 0x800622E4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_8006261C(rdram, ctx);
        goto after_6;
    // 0x800622E4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_6:
L_800622E8:
    // 0x800622E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800622EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800622F0: lh          $t2, 0x4($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4);
    // 0x800622F4: lh          $t4, 0xC($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XC);
    // 0x800622F8: nop

    // 0x800622FC: beq         $t2, $t4, L_80062318
    if (ctx->r10 == ctx->r12) {
        // 0x80062300: nop

            goto L_80062318;
    }
    // 0x80062300: nop

    // 0x80062304: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062308: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006230C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062310: jal         0x8006261C
    // 0x80062314: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8006261C(rdram, ctx);
        goto after_7;
    // 0x80062314: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
L_80062318:
    // 0x80062318: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8006231C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80062320: lh          $t6, 0x6($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X6);
    // 0x80062324: lh          $t7, 0xC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XC);
    // 0x80062328: nop

    // 0x8006232C: beq         $t6, $t7, L_80062348
    if (ctx->r14 == ctx->r15) {
        // 0x80062330: nop

            goto L_80062348;
    }
    // 0x80062330: nop

    // 0x80062334: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062338: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006233C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062340: jal         0x8006261C
    // 0x80062344: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_8006261C(rdram, ctx);
        goto after_8;
    // 0x80062344: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_8:
L_80062348:
    // 0x80062348: b           L_800625D8
    // 0x8006234C: nop

        goto L_800625D8;
    // 0x8006234C: nop

L_80062350:
    // 0x80062350: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80062354: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062358: lh          $a1, 0xC($t9)
    ctx->r5 = MEM_H(ctx->r25, 0XC);
    // 0x8006235C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80062360: jal         0x8006261C
    // 0x80062364: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8006261C(rdram, ctx);
        goto after_9;
    // 0x80062364: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_9:
    // 0x80062368: b           L_800625D8
    // 0x8006236C: nop

        goto L_800625D8;
    // 0x8006236C: nop

L_80062370:
    // 0x80062370: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80062374: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062378: lh          $a1, 0xC($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XC);
    // 0x8006237C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80062380: jal         0x8006261C
    // 0x80062384: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    func_8006261C(rdram, ctx);
        goto after_10;
    // 0x80062384: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    after_10:
    // 0x80062388: b           L_800625D8
    // 0x8006238C: nop

        goto L_800625D8;
    // 0x8006238C: nop

L_80062390:
    // 0x80062390: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80062394: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062398: lh          $a1, 0xC($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XC);
    // 0x8006239C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800623A0: jal         0x8006261C
    // 0x800623A4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_8006261C(rdram, ctx);
        goto after_11;
    // 0x800623A4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_11:
    // 0x800623A8: b           L_800625D8
    // 0x800623AC: nop

        goto L_800625D8;
    // 0x800623AC: nop

L_800623B0:
    // 0x800623B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800623B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800623B8: lh          $a1, 0xC($t0)
    ctx->r5 = MEM_H(ctx->r8, 0XC);
    // 0x800623BC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800623C0: jal         0x8006261C
    // 0x800623C4: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8006261C(rdram, ctx);
        goto after_12;
    // 0x800623C4: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_12:
    // 0x800623C8: b           L_800625D8
    // 0x800623CC: nop

        goto L_800625D8;
    // 0x800623CC: nop

L_800623D0:
    // 0x800623D0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800623D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800623D8: lh          $a1, 0xC($t2)
    ctx->r5 = MEM_H(ctx->r10, 0XC);
    // 0x800623DC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800623E0: jal         0x8006261C
    // 0x800623E4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_8006261C(rdram, ctx);
        goto after_13;
    // 0x800623E4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_13:
    // 0x800623E8: b           L_800625D8
    // 0x800623EC: nop

        goto L_800625D8;
    // 0x800623EC: nop

L_800623F0:
    // 0x800623F0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800623F4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800623F8: lh          $t3, 0x0($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X0);
    // 0x800623FC: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x80062400: nop

    // 0x80062404: beq         $t3, $t6, L_80062570
    if (ctx->r11 == ctx->r14) {
        // 0x80062408: nop

            goto L_80062570;
    }
    // 0x80062408: nop

    // 0x8006240C: lh          $t7, 0x2($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2);
    // 0x80062410: nop

    // 0x80062414: beq         $t7, $t6, L_80062570
    if (ctx->r15 == ctx->r14) {
        // 0x80062418: nop

            goto L_80062570;
    }
    // 0x80062418: nop

    // 0x8006241C: lh          $t9, 0x4($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X4);
    // 0x80062420: nop

    // 0x80062424: beq         $t9, $t6, L_80062570
    if (ctx->r25 == ctx->r14) {
        // 0x80062428: nop

            goto L_80062570;
    }
    // 0x80062428: nop

    // 0x8006242C: lh          $t1, 0x6($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X6);
    // 0x80062430: nop

    // 0x80062434: beq         $t1, $t6, L_80062570
    if (ctx->r9 == ctx->r14) {
        // 0x80062438: nop

            goto L_80062570;
    }
    // 0x80062438: nop

    // 0x8006243C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80062440: nop

    // 0x80062444: lh          $a0, 0xC($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XC);
    // 0x80062448: jal         0x800615C8
    // 0x8006244C: nop

    func_800615C8(rdram, ctx);
        goto after_14;
    // 0x8006244C: nop

    after_14:
    // 0x80062450: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80062454: bne         $v0, $at, L_8006249C
    if (ctx->r2 != ctx->r1) {
        // 0x80062458: nop

            goto L_8006249C;
    }
    // 0x80062458: nop

    // 0x8006245C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80062460: nop

    // 0x80062464: sh          $zero, 0x2($t0)
    MEM_H(0X2, ctx->r8) = 0;
    // 0x80062468: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8006246C: nop

    // 0x80062470: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x80062474: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80062478: nop

    // 0x8006247C: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x80062480: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80062484: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062488: lh          $a1, 0xC($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XC);
    // 0x8006248C: jal         0x8006261C
    // 0x80062490: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_8006261C(rdram, ctx);
        goto after_15;
    // 0x80062490: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_15:
    // 0x80062494: b           L_80062570
    // 0x80062498: nop

        goto L_80062570;
    // 0x80062498: nop

L_8006249C:
    // 0x8006249C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800624A0: nop

    // 0x800624A4: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x800624A8: nop

    // 0x800624AC: bne         $t9, $zero, L_800624D0
    if (ctx->r25 != 0) {
        // 0x800624B0: nop

            goto L_800624D0;
    }
    // 0x800624B0: nop

    // 0x800624B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800624B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800624BC: lh          $a1, 0xC($t4)
    ctx->r5 = MEM_H(ctx->r12, 0XC);
    // 0x800624C0: jal         0x8006261C
    // 0x800624C4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    func_8006261C(rdram, ctx);
        goto after_16;
    // 0x800624C4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_16:
    // 0x800624C8: b           L_80062570
    // 0x800624CC: nop

        goto L_80062570;
    // 0x800624CC: nop

L_800624D0:
    // 0x800624D0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800624D4: nop

    // 0x800624D8: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x800624DC: nop

    // 0x800624E0: bne         $t6, $zero, L_80062508
    if (ctx->r14 != 0) {
        // 0x800624E4: nop

            goto L_80062508;
    }
    // 0x800624E4: nop

    // 0x800624E8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800624EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800624F0: lh          $a1, 0xC($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XC);
    // 0x800624F4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800624F8: jal         0x8006261C
    // 0x800624FC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_8006261C(rdram, ctx);
        goto after_17;
    // 0x800624FC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_17:
    // 0x80062500: b           L_80062570
    // 0x80062504: nop

        goto L_80062570;
    // 0x80062504: nop

L_80062508:
    // 0x80062508: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006250C: nop

    // 0x80062510: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80062514: nop

    // 0x80062518: bne         $t2, $zero, L_80062540
    if (ctx->r10 != 0) {
        // 0x8006251C: nop

            goto L_80062540;
    }
    // 0x8006251C: nop

    // 0x80062520: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80062524: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062528: lh          $a1, 0xC($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XC);
    // 0x8006252C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80062530: jal         0x8006261C
    // 0x80062534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8006261C(rdram, ctx);
        goto after_18;
    // 0x80062534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_18:
    // 0x80062538: b           L_80062570
    // 0x8006253C: nop

        goto L_80062570;
    // 0x8006253C: nop

L_80062540:
    // 0x80062540: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80062544: nop

    // 0x80062548: lh          $t7, 0x6($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X6);
    // 0x8006254C: nop

    // 0x80062550: bne         $t7, $zero, L_80062570
    if (ctx->r15 != 0) {
        // 0x80062554: nop

            goto L_80062570;
    }
    // 0x80062554: nop

    // 0x80062558: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8006255C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062560: lh          $a1, 0xC($t9)
    ctx->r5 = MEM_H(ctx->r25, 0XC);
    // 0x80062564: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80062568: jal         0x8006261C
    // 0x8006256C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_8006261C(rdram, ctx);
        goto after_19;
    // 0x8006256C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_19:
L_80062570:
    // 0x80062570: b           L_800625D8
    // 0x80062574: nop

        goto L_800625D8;
    // 0x80062574: nop

L_80062578:
    // 0x80062578: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006257C: nop

    // 0x80062580: lh          $a0, 0xC($t4)
    ctx->r4 = MEM_H(ctx->r12, 0XC);
    // 0x80062584: jal         0x8005F0DC
    // 0x80062588: nop

    func_8005F0DC(rdram, ctx);
        goto after_20;
    // 0x80062588: nop

    after_20:
    // 0x8006258C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80062590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80062594: lh          $a1, 0xC($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XC);
    // 0x80062598: jal         0x8006261C
    // 0x8006259C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_8006261C(rdram, ctx);
        goto after_21;
    // 0x8006259C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_21:
    // 0x800625A0: b           L_800625D8
    // 0x800625A4: nop

        goto L_800625D8;
    // 0x800625A4: nop

L_800625A8:
    // 0x800625A8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800625AC: nop

    // 0x800625B0: lh          $a0, 0xC($t6)
    ctx->r4 = MEM_H(ctx->r14, 0XC);
    // 0x800625B4: jal         0x8005F268
    // 0x800625B8: nop

    func_8005F268(rdram, ctx);
        goto after_22;
    // 0x800625B8: nop

    after_22:
    // 0x800625BC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800625C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800625C4: lh          $a1, 0xC($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XC);
    // 0x800625C8: jal         0x8006261C
    // 0x800625CC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_8006261C(rdram, ctx);
        goto after_23;
    // 0x800625CC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_23:
    // 0x800625D0: b           L_800625D8
    // 0x800625D4: nop

        goto L_800625D8;
    // 0x800625D4: nop

L_800625D8:
    // 0x800625D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800625DC: nop

    // 0x800625E0: lbu         $v0, 0xE($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XE);
    // 0x800625E4: nop

    // 0x800625E8: andi        $t2, $v0, 0x80
    ctx->r10 = ctx->r2 & 0X80;
    // 0x800625EC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800625F0: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x800625F4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800625F8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800625FC: b           L_8006260C
    // 0x80062600: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_8006260C;
    // 0x80062600: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80062604: b           L_8006260C
    // 0x80062608: nop

        goto L_8006260C;
    // 0x80062608: nop

L_8006260C:
    // 0x8006260C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80062614: jr          $ra
    // 0x80062618: nop

    return;
    // 0x80062618: nop

;}
RECOMP_FUNC void func_8006261C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006261C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80062620: beq         $a0, $zero, L_8006262C
    if (ctx->r4 == 0) {
        // 0x80062624: nop

            goto L_8006262C;
    }
    // 0x80062624: nop

    // 0x80062628: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
L_8006262C:
    // 0x8006262C: b           L_80062634
    // 0x80062630: nop

        goto L_80062634;
    // 0x80062630: nop

L_80062634:
    // 0x80062634: jr          $ra
    // 0x80062638: nop

    return;
    // 0x80062638: nop

    // 0x8006263C: nop

;}
RECOMP_FUNC void func_80062640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062648: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8006264C: sh          $zero, 0xCE0($at)
    MEM_H(0XCE0, ctx->r1) = 0;
    // 0x80062650: jal         0x800BC6EC
    // 0x80062654: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80062654: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x80062658: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8006265C: sw          $v0, 0xCEC($at)
    MEM_W(0XCEC, ctx->r1) = ctx->r2;
    // 0x80062660: b           L_80062668
    // 0x80062664: nop

        goto L_80062668;
    // 0x80062664: nop

L_80062668:
    // 0x80062668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006266C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062670: jr          $ra
    // 0x80062674: nop

    return;
    // 0x80062674: nop

;}
RECOMP_FUNC void func_80062678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006267C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062680: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80062684: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80062688: nop

    // 0x8006268C: slti        $at, $t6, 0x2710
    ctx->r1 = SIGNED(ctx->r14) < 0X2710 ? 1 : 0;
    // 0x80062690: beq         $at, $zero, L_800626B4
    if (ctx->r1 == 0) {
        // 0x80062694: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800626B4;
    }
    // 0x80062694: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80062698: lui         $t7, 0x809D
    ctx->r15 = S32(0X809D << 16);
    // 0x8006269C: addiu       $t7, $t7, 0x7B0
    ctx->r15 = ADD32(ctx->r15, 0X7B0);
    // 0x800626A0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800626A4: lui         $t8, 0x809B
    ctx->r24 = S32(0X809B << 16);
    // 0x800626A8: addiu       $t8, $t8, 0x4200
    ctx->r24 = ADD32(ctx->r24, 0X4200);
    // 0x800626AC: b           L_800626DC
    // 0x800626B0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_800626DC;
    // 0x800626B0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800626B4:
    // 0x800626B4: lui         $t9, 0x809D
    ctx->r25 = S32(0X809D << 16);
    // 0x800626B8: addiu       $t9, $t9, 0x45E0
    ctx->r25 = ADD32(ctx->r25, 0X45E0);
    // 0x800626BC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800626C0: lui         $t0, 0x809D
    ctx->r8 = S32(0X809D << 16);
    // 0x800626C4: addiu       $t0, $t0, 0x3920
    ctx->r8 = ADD32(ctx->r8, 0X3920);
    // 0x800626C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800626CC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800626D0: nop

    // 0x800626D4: addiu       $t2, $t1, -0x2710
    ctx->r10 = ADD32(ctx->r9, -0X2710);
    // 0x800626D8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_800626DC:
    // 0x800626DC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800626E0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x800626E4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x800626E8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800626EC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800626F0: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800626F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800626F8: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x800626FC: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    // 0x80062700: jal         0x80096B38
    // 0x80062704: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_80096B38(rdram, ctx);
        goto after_0;
    // 0x80062704: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_0:
    // 0x80062708: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8006270C: jal         0x80031AC8
    // 0x80062710: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x80062710: nop

    after_1:
    // 0x80062714: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80062718: bne         $v0, $at, L_80062728
    if (ctx->r2 != ctx->r1) {
        // 0x8006271C: nop

            goto L_80062728;
    }
    // 0x8006271C: nop

    // 0x80062720: jal         0x80031874
    // 0x80062724: nop

    func_80031874(rdram, ctx);
        goto after_2;
    // 0x80062724: nop

    after_2:
L_80062728:
    // 0x80062728: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006272C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80062730: jal         0x80096C6C
    // 0x80062734: nop

    func_80096C6C(rdram, ctx);
        goto after_3;
    // 0x80062734: nop

    after_3:
    // 0x80062738: b           L_80062740
    // 0x8006273C: nop

        goto L_80062740;
    // 0x8006273C: nop

L_80062740:
    // 0x80062740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062744: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80062748: jr          $ra
    // 0x8006274C: nop

    return;
    // 0x8006274C: nop

;}
RECOMP_FUNC void func_80062750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062750: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80062754: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80062758: nop

    // 0x8006275C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80062760: nop

    // 0x80062764: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80062768: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006276C: jr          $ra
    // 0x80062770: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80062770: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80062774: jr          $ra
    // 0x80062778: nop

    return;
    // 0x80062778: nop

    // 0x8006277C: jr          $ra
    // 0x80062780: nop

    return;
    // 0x80062780: nop

;}
RECOMP_FUNC void func_80062784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062784: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80062788: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006278C: nop

    // 0x80062790: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80062794: nop

    // 0x80062798: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006279C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800627A0: jr          $ra
    // 0x800627A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800627A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800627A8: jr          $ra
    // 0x800627AC: nop

    return;
    // 0x800627AC: nop

    // 0x800627B0: jr          $ra
    // 0x800627B4: nop

    return;
    // 0x800627B4: nop

;}
RECOMP_FUNC void func_800627B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800627B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800627BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800627C0: jal         0x8005F064
    // 0x800627C4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800627C4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_0:
    // 0x800627C8: b           L_800627D8
    // 0x800627CC: nop

        goto L_800627D8;
    // 0x800627CC: nop

    // 0x800627D0: b           L_800627D8
    // 0x800627D4: nop

        goto L_800627D8;
    // 0x800627D4: nop

L_800627D8:
    // 0x800627D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800627DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800627E0: jr          $ra
    // 0x800627E4: nop

    return;
    // 0x800627E4: nop

;}
RECOMP_FUNC void func_800627E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800627E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800627EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800627F0: jal         0x8005F064
    // 0x800627F4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800627F4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_0:
    // 0x800627F8: b           L_80062808
    // 0x800627FC: nop

        goto L_80062808;
    // 0x800627FC: nop

    // 0x80062800: b           L_80062808
    // 0x80062804: nop

        goto L_80062808;
    // 0x80062804: nop

L_80062808:
    // 0x80062808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006280C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062810: jr          $ra
    // 0x80062814: nop

    return;
    // 0x80062814: nop

;}
RECOMP_FUNC void func_80062818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006281C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062820: jal         0x8005F064
    // 0x80062824: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062824: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_0:
    // 0x80062828: b           L_80062838
    // 0x8006282C: nop

        goto L_80062838;
    // 0x8006282C: nop

    // 0x80062830: b           L_80062838
    // 0x80062834: nop

        goto L_80062838;
    // 0x80062834: nop

L_80062838:
    // 0x80062838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006283C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062840: jr          $ra
    // 0x80062844: nop

    return;
    // 0x80062844: nop

;}
RECOMP_FUNC void func_80062848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006284C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062850: jal         0x8005F064
    // 0x80062854: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062854: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_0:
    // 0x80062858: b           L_80062868
    // 0x8006285C: nop

        goto L_80062868;
    // 0x8006285C: nop

    // 0x80062860: b           L_80062868
    // 0x80062864: nop

        goto L_80062868;
    // 0x80062864: nop

L_80062868:
    // 0x80062868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006286C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062870: jr          $ra
    // 0x80062874: nop

    return;
    // 0x80062874: nop

;}
RECOMP_FUNC void func_80062878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006287C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062880: jal         0x8005F064
    // 0x80062884: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062884: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_0:
    // 0x80062888: b           L_80062898
    // 0x8006288C: nop

        goto L_80062898;
    // 0x8006288C: nop

    // 0x80062890: b           L_80062898
    // 0x80062894: nop

        goto L_80062898;
    // 0x80062894: nop

L_80062898:
    // 0x80062898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006289C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800628A0: jr          $ra
    // 0x800628A4: nop

    return;
    // 0x800628A4: nop

;}
RECOMP_FUNC void func_800628A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800628A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800628AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800628B0: jal         0x8005F064
    // 0x800628B4: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800628B4: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_0:
    // 0x800628B8: b           L_800628C8
    // 0x800628BC: nop

        goto L_800628C8;
    // 0x800628BC: nop

    // 0x800628C0: b           L_800628C8
    // 0x800628C4: nop

        goto L_800628C8;
    // 0x800628C4: nop

L_800628C8:
    // 0x800628C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800628CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800628D0: jr          $ra
    // 0x800628D4: nop

    return;
    // 0x800628D4: nop

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
RECOMP_FUNC void func_80062908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006290C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062910: jal         0x8005F064
    // 0x80062914: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062914: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_0:
    // 0x80062918: b           L_80062928
    // 0x8006291C: nop

        goto L_80062928;
    // 0x8006291C: nop

    // 0x80062920: b           L_80062928
    // 0x80062924: nop

        goto L_80062928;
    // 0x80062924: nop

L_80062928:
    // 0x80062928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006292C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062930: jr          $ra
    // 0x80062934: nop

    return;
    // 0x80062934: nop

;}
RECOMP_FUNC void func_80062938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006293C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062940: jal         0x8005F064
    // 0x80062944: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062944: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    after_0:
    // 0x80062948: b           L_80062958
    // 0x8006294C: nop

        goto L_80062958;
    // 0x8006294C: nop

    // 0x80062950: b           L_80062958
    // 0x80062954: nop

        goto L_80062958;
    // 0x80062954: nop

L_80062958:
    // 0x80062958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006295C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062960: jr          $ra
    // 0x80062964: nop

    return;
    // 0x80062964: nop

;}
RECOMP_FUNC void func_80062968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006296C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062970: jal         0x8005F064
    // 0x80062974: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062974: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    after_0:
    // 0x80062978: b           L_80062988
    // 0x8006297C: nop

        goto L_80062988;
    // 0x8006297C: nop

    // 0x80062980: b           L_80062988
    // 0x80062984: nop

        goto L_80062988;
    // 0x80062984: nop

L_80062988:
    // 0x80062988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006298C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062990: jr          $ra
    // 0x80062994: nop

    return;
    // 0x80062994: nop

;}
RECOMP_FUNC void func_80062998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006299C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800629A0: jal         0x8005F064
    // 0x800629A4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800629A4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x800629A8: b           L_800629B8
    // 0x800629AC: nop

        goto L_800629B8;
    // 0x800629AC: nop

    // 0x800629B0: b           L_800629B8
    // 0x800629B4: nop

        goto L_800629B8;
    // 0x800629B4: nop

L_800629B8:
    // 0x800629B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800629BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800629C0: jr          $ra
    // 0x800629C4: nop

    return;
    // 0x800629C4: nop

;}
RECOMP_FUNC void func_800629C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800629CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800629D0: jal         0x8005F064
    // 0x800629D4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800629D4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x800629D8: b           L_800629E8
    // 0x800629DC: nop

        goto L_800629E8;
    // 0x800629DC: nop

    // 0x800629E0: b           L_800629E8
    // 0x800629E4: nop

        goto L_800629E8;
    // 0x800629E4: nop

L_800629E8:
    // 0x800629E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800629EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800629F0: jr          $ra
    // 0x800629F4: nop

    return;
    // 0x800629F4: nop

;}
RECOMP_FUNC void func_800629F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800629FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062A00: jal         0x8005F064
    // 0x80062A04: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062A04: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80062A08: b           L_80062A18
    // 0x80062A0C: nop

        goto L_80062A18;
    // 0x80062A0C: nop

    // 0x80062A10: b           L_80062A18
    // 0x80062A14: nop

        goto L_80062A18;
    // 0x80062A14: nop

L_80062A18:
    // 0x80062A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062A20: jr          $ra
    // 0x80062A24: nop

    return;
    // 0x80062A24: nop

;}
RECOMP_FUNC void func_80062A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062A30: jal         0x8005F064
    // 0x80062A34: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062A34: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80062A38: b           L_80062A48
    // 0x80062A3C: nop

        goto L_80062A48;
    // 0x80062A3C: nop

    // 0x80062A40: b           L_80062A48
    // 0x80062A44: nop

        goto L_80062A48;
    // 0x80062A44: nop

L_80062A48:
    // 0x80062A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062A50: jr          $ra
    // 0x80062A54: nop

    return;
    // 0x80062A54: nop

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
RECOMP_FUNC void func_80062A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062A90: jal         0x8005F064
    // 0x80062A94: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062A94: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_0:
    // 0x80062A98: b           L_80062AA8
    // 0x80062A9C: nop

        goto L_80062AA8;
    // 0x80062A9C: nop

    // 0x80062AA0: b           L_80062AA8
    // 0x80062AA4: nop

        goto L_80062AA8;
    // 0x80062AA4: nop

L_80062AA8:
    // 0x80062AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062AB0: jr          $ra
    // 0x80062AB4: nop

    return;
    // 0x80062AB4: nop

;}
RECOMP_FUNC void func_80062AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062AC0: jal         0x8005F064
    // 0x80062AC4: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062AC4: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    after_0:
    // 0x80062AC8: b           L_80062AD8
    // 0x80062ACC: nop

        goto L_80062AD8;
    // 0x80062ACC: nop

    // 0x80062AD0: b           L_80062AD8
    // 0x80062AD4: nop

        goto L_80062AD8;
    // 0x80062AD4: nop

L_80062AD8:
    // 0x80062AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062AE0: jr          $ra
    // 0x80062AE4: nop

    return;
    // 0x80062AE4: nop

;}
RECOMP_FUNC void func_80062AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062AF0: jal         0x8005F064
    // 0x80062AF4: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062AF4: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    after_0:
    // 0x80062AF8: b           L_80062B08
    // 0x80062AFC: nop

        goto L_80062B08;
    // 0x80062AFC: nop

    // 0x80062B00: b           L_80062B08
    // 0x80062B04: nop

        goto L_80062B08;
    // 0x80062B04: nop

L_80062B08:
    // 0x80062B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062B10: jr          $ra
    // 0x80062B14: nop

    return;
    // 0x80062B14: nop

;}
RECOMP_FUNC void func_80062B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B20: jal         0x8005F064
    // 0x80062B24: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062B24: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    after_0:
    // 0x80062B28: b           L_80062B38
    // 0x80062B2C: nop

        goto L_80062B38;
    // 0x80062B2C: nop

    // 0x80062B30: b           L_80062B38
    // 0x80062B34: nop

        goto L_80062B38;
    // 0x80062B34: nop

L_80062B38:
    // 0x80062B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062B40: jr          $ra
    // 0x80062B44: nop

    return;
    // 0x80062B44: nop

;}
RECOMP_FUNC void func_80062B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B50: jal         0x8005F064
    // 0x80062B54: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062B54: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    after_0:
    // 0x80062B58: b           L_80062B68
    // 0x80062B5C: nop

        goto L_80062B68;
    // 0x80062B5C: nop

    // 0x80062B60: b           L_80062B68
    // 0x80062B64: nop

        goto L_80062B68;
    // 0x80062B64: nop

L_80062B68:
    // 0x80062B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062B70: jr          $ra
    // 0x80062B74: nop

    return;
    // 0x80062B74: nop

;}
RECOMP_FUNC void func_80062B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B80: jal         0x8005F064
    // 0x80062B84: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062B84: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062B88: b           L_80062B98
    // 0x80062B8C: nop

        goto L_80062B98;
    // 0x80062B8C: nop

    // 0x80062B90: b           L_80062B98
    // 0x80062B94: nop

        goto L_80062B98;
    // 0x80062B94: nop

L_80062B98:
    // 0x80062B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062BA0: jr          $ra
    // 0x80062BA4: nop

    return;
    // 0x80062BA4: nop

;}
RECOMP_FUNC void func_80062BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062BB0: jal         0x8005F064
    // 0x80062BB4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062BB4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062BB8: b           L_80062BC8
    // 0x80062BBC: nop

        goto L_80062BC8;
    // 0x80062BBC: nop

    // 0x80062BC0: b           L_80062BC8
    // 0x80062BC4: nop

        goto L_80062BC8;
    // 0x80062BC4: nop

L_80062BC8:
    // 0x80062BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062BD0: jr          $ra
    // 0x80062BD4: nop

    return;
    // 0x80062BD4: nop

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
RECOMP_FUNC void func_80062C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C10: jal         0x8005F064
    // 0x80062C14: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062C14: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_0:
    // 0x80062C18: b           L_80062C28
    // 0x80062C1C: nop

        goto L_80062C28;
    // 0x80062C1C: nop

    // 0x80062C20: b           L_80062C28
    // 0x80062C24: nop

        goto L_80062C28;
    // 0x80062C24: nop

L_80062C28:
    // 0x80062C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062C30: jr          $ra
    // 0x80062C34: nop

    return;
    // 0x80062C34: nop

;}
RECOMP_FUNC void func_80062C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C40: jal         0x80061488
    // 0x80062C44: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062C44: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    after_0:
    // 0x80062C48: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062C4C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062C50: b           L_80062C60
    // 0x80062C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062C60;
    // 0x80062C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062C58: b           L_80062C60
    // 0x80062C5C: nop

        goto L_80062C60;
    // 0x80062C5C: nop

L_80062C60:
    // 0x80062C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062C68: jr          $ra
    // 0x80062C6C: nop

    return;
    // 0x80062C6C: nop

;}
RECOMP_FUNC void func_80062C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C78: jal         0x80061488
    // 0x80062C7C: addiu       $a0, $zero, 0x6C5
    ctx->r4 = ADD32(0, 0X6C5);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062C7C: addiu       $a0, $zero, 0x6C5
    ctx->r4 = ADD32(0, 0X6C5);
    after_0:
    // 0x80062C80: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062C84: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062C88: b           L_80062C98
    // 0x80062C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062C98;
    // 0x80062C8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062C90: b           L_80062C98
    // 0x80062C94: nop

        goto L_80062C98;
    // 0x80062C94: nop

L_80062C98:
    // 0x80062C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062CA0: jr          $ra
    // 0x80062CA4: nop

    return;
    // 0x80062CA4: nop

;}
RECOMP_FUNC void func_80062CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062CB0: jal         0x80061348
    // 0x80062CB4: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80062CB4: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    after_0:
    // 0x80062CB8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80062CBC: b           L_80062CCC
    // 0x80062CC0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062CCC;
    // 0x80062CC0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062CC4: b           L_80062CCC
    // 0x80062CC8: nop

        goto L_80062CCC;
    // 0x80062CC8: nop

L_80062CCC:
    // 0x80062CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062CD4: jr          $ra
    // 0x80062CD8: nop

    return;
    // 0x80062CD8: nop

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
RECOMP_FUNC void func_80062D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D1C: jal         0x80061488
    // 0x80062D20: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062D20: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    after_0:
    // 0x80062D24: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062D28: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062D2C: b           L_80062D3C
    // 0x80062D30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062D3C;
    // 0x80062D30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062D34: b           L_80062D3C
    // 0x80062D38: nop

        goto L_80062D3C;
    // 0x80062D38: nop

L_80062D3C:
    // 0x80062D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062D44: jr          $ra
    // 0x80062D48: nop

    return;
    // 0x80062D48: nop

;}
RECOMP_FUNC void func_80062D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D54: jal         0x80061488
    // 0x80062D58: addiu       $a0, $zero, 0x697
    ctx->r4 = ADD32(0, 0X697);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062D58: addiu       $a0, $zero, 0x697
    ctx->r4 = ADD32(0, 0X697);
    after_0:
    // 0x80062D5C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062D60: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062D64: b           L_80062D74
    // 0x80062D68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062D74;
    // 0x80062D68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062D6C: b           L_80062D74
    // 0x80062D70: nop

        goto L_80062D74;
    // 0x80062D70: nop

L_80062D74:
    // 0x80062D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062D7C: jr          $ra
    // 0x80062D80: nop

    return;
    // 0x80062D80: nop

;}
RECOMP_FUNC void func_80062D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D8C: jal         0x80061488
    // 0x80062D90: addiu       $a0, $zero, 0x6A8
    ctx->r4 = ADD32(0, 0X6A8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062D90: addiu       $a0, $zero, 0x6A8
    ctx->r4 = ADD32(0, 0X6A8);
    after_0:
    // 0x80062D94: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062D98: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062D9C: b           L_80062DAC
    // 0x80062DA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062DAC;
    // 0x80062DA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062DA4: b           L_80062DAC
    // 0x80062DA8: nop

        goto L_80062DAC;
    // 0x80062DA8: nop

L_80062DAC:
    // 0x80062DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062DB4: jr          $ra
    // 0x80062DB8: nop

    return;
    // 0x80062DB8: nop

;}
RECOMP_FUNC void func_80062DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062DBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062DC4: jal         0x80061488
    // 0x80062DC8: addiu       $a0, $zero, 0x6A9
    ctx->r4 = ADD32(0, 0X6A9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062DC8: addiu       $a0, $zero, 0x6A9
    ctx->r4 = ADD32(0, 0X6A9);
    after_0:
    // 0x80062DCC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062DD0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062DD4: b           L_80062DE4
    // 0x80062DD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062DE4;
    // 0x80062DD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062DDC: b           L_80062DE4
    // 0x80062DE0: nop

        goto L_80062DE4;
    // 0x80062DE0: nop

L_80062DE4:
    // 0x80062DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062DEC: jr          $ra
    // 0x80062DF0: nop

    return;
    // 0x80062DF0: nop

;}
RECOMP_FUNC void func_80062DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062DFC: jal         0x8005F064
    // 0x80062E00: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062E00: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_0:
    // 0x80062E04: b           L_80062E14
    // 0x80062E08: nop

        goto L_80062E14;
    // 0x80062E08: nop

    // 0x80062E0C: b           L_80062E14
    // 0x80062E10: nop

        goto L_80062E14;
    // 0x80062E10: nop

L_80062E14:
    // 0x80062E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062E1C: jr          $ra
    // 0x80062E20: nop

    return;
    // 0x80062E20: nop

;}
RECOMP_FUNC void func_80062E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062E2C: jal         0x8005F064
    // 0x80062E30: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062E30: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062E34: b           L_80062E44
    // 0x80062E38: nop

        goto L_80062E44;
    // 0x80062E38: nop

    // 0x80062E3C: b           L_80062E44
    // 0x80062E40: nop

        goto L_80062E44;
    // 0x80062E40: nop

L_80062E44:
    // 0x80062E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062E4C: jr          $ra
    // 0x80062E50: nop

    return;
    // 0x80062E50: nop

;}
RECOMP_FUNC void func_80062E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062E5C: jal         0x80061488
    // 0x80062E60: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062E60: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_0:
    // 0x80062E64: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062E68: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062E6C: b           L_80062E7C
    // 0x80062E70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062E7C;
    // 0x80062E70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062E74: b           L_80062E7C
    // 0x80062E78: nop

        goto L_80062E7C;
    // 0x80062E78: nop

L_80062E7C:
    // 0x80062E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062E80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062E84: jr          $ra
    // 0x80062E88: nop

    return;
    // 0x80062E88: nop

;}
RECOMP_FUNC void func_80062E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062E94: jal         0x8005F064
    // 0x80062E98: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062E98: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062E9C: b           L_80062EAC
    // 0x80062EA0: nop

        goto L_80062EAC;
    // 0x80062EA0: nop

    // 0x80062EA4: b           L_80062EAC
    // 0x80062EA8: nop

        goto L_80062EAC;
    // 0x80062EA8: nop

L_80062EAC:
    // 0x80062EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062EB4: jr          $ra
    // 0x80062EB8: nop

    return;
    // 0x80062EB8: nop

;}
RECOMP_FUNC void func_80062EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062EC4: jal         0x8005F064
    // 0x80062EC8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062EC8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_0:
    // 0x80062ECC: b           L_80062EDC
    // 0x80062ED0: nop

        goto L_80062EDC;
    // 0x80062ED0: nop

    // 0x80062ED4: b           L_80062EDC
    // 0x80062ED8: nop

        goto L_80062EDC;
    // 0x80062ED8: nop

L_80062EDC:
    // 0x80062EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062EE4: jr          $ra
    // 0x80062EE8: nop

    return;
    // 0x80062EE8: nop

;}
RECOMP_FUNC void func_80062EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062EF4: jal         0x8005F064
    // 0x80062EF8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062EF8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_0:
    // 0x80062EFC: b           L_80062F0C
    // 0x80062F00: nop

        goto L_80062F0C;
    // 0x80062F00: nop

    // 0x80062F04: b           L_80062F0C
    // 0x80062F08: nop

        goto L_80062F0C;
    // 0x80062F08: nop

L_80062F0C:
    // 0x80062F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062F14: jr          $ra
    // 0x80062F18: nop

    return;
    // 0x80062F18: nop

;}
RECOMP_FUNC void func_80062F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062F1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062F24: jal         0x8005F064
    // 0x80062F28: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062F28: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_0:
    // 0x80062F2C: b           L_80062F3C
    // 0x80062F30: nop

        goto L_80062F3C;
    // 0x80062F30: nop

    // 0x80062F34: b           L_80062F3C
    // 0x80062F38: nop

        goto L_80062F3C;
    // 0x80062F38: nop

L_80062F3C:
    // 0x80062F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062F44: jr          $ra
    // 0x80062F48: nop

    return;
    // 0x80062F48: nop

;}
RECOMP_FUNC void func_80062F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062F54: jal         0x8005F064
    // 0x80062F58: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062F58: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_0:
    // 0x80062F5C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80062F60: b           L_80062F70
    // 0x80062F64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062F70;
    // 0x80062F64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062F68: b           L_80062F70
    // 0x80062F6C: nop

        goto L_80062F70;
    // 0x80062F6C: nop

L_80062F70:
    // 0x80062F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062F78: jr          $ra
    // 0x80062F7C: nop

    return;
    // 0x80062F7C: nop

;}
RECOMP_FUNC void func_80062F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062F88: jal         0x8005F064
    // 0x80062F8C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062F8C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80062F90: b           L_80062FA0
    // 0x80062F94: nop

        goto L_80062FA0;
    // 0x80062F94: nop

    // 0x80062F98: b           L_80062FA0
    // 0x80062F9C: nop

        goto L_80062FA0;
    // 0x80062F9C: nop

L_80062FA0:
    // 0x80062FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062FA8: jr          $ra
    // 0x80062FAC: nop

    return;
    // 0x80062FAC: nop

;}
RECOMP_FUNC void func_80062FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062FB8: jal         0x8005F064
    // 0x80062FBC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062FBC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80062FC0: b           L_80062FD0
    // 0x80062FC4: nop

        goto L_80062FD0;
    // 0x80062FC4: nop

    // 0x80062FC8: b           L_80062FD0
    // 0x80062FCC: nop

        goto L_80062FD0;
    // 0x80062FCC: nop

L_80062FD0:
    // 0x80062FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062FD8: jr          $ra
    // 0x80062FDC: nop

    return;
    // 0x80062FDC: nop

;}
