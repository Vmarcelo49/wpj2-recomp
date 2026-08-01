#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80067758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006775C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067760: jal         0x80061348
    // 0x80067764: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067764: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80067768: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006776C: b           L_8006777C
    // 0x80067770: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006777C;
    // 0x80067770: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067774: b           L_8006777C
    // 0x80067778: nop

        goto L_8006777C;
    // 0x80067778: nop

L_8006777C:
    // 0x8006777C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067784: jr          $ra
    // 0x80067788: nop

    return;
    // 0x80067788: nop

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
RECOMP_FUNC void func_80033EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033EFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80033F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033F04: jal         0x800C1680
    // 0x80033F08: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x80033F08: nop

    after_0:
    // 0x80033F0C: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
L_80033F10:
    // 0x80033F10: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80033F14: lw          $t6, 0x72B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72B8);
    // 0x80033F18: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x80033F1C: nop

    // 0x80033F20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80033F24: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80033F28: nop

    // 0x80033F2C: beq         $t9, $zero, L_8003400C
    if (ctx->r25 == 0) {
        // 0x80033F30: nop
    
            goto L_8003400C;
    }
    // 0x80033F30: nop

    // 0x80033F34: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x80033F38: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80033F3C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80033F40: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80033F44: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80033F48: lw          $t0, 0x72B8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72B8);
    // 0x80033F4C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80033F50: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80033F54: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80033F58: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x80033F5C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80033F60: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80033F64: nop

    // 0x80033F68: lwc1        $f4, 0xFC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XFC);
    // 0x80033F6C: nop

    // 0x80033F70: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80033F74: jal         0x800C1850
    // 0x80033F78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x80033F78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80033F7C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80033F80: nop

    // 0x80033F84: lwc1        $f12, 0xCC($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x80033F88: lwc1        $f14, 0xD0($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x80033F8C: lw          $a2, 0xD4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XD4);
    // 0x80033F90: jal         0x800C2304
    // 0x80033F94: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_2;
    // 0x80033F94: nop

    after_2:
    // 0x80033F98: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80033F9C: nop

    // 0x80033FA0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80033FA4: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x80033FA8: jal         0x800C2948
    // 0x80033FAC: mov.s       $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = ctx->f6.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_3;
    // 0x80033FAC: mov.s       $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = ctx->f6.fl;
    after_3:
    // 0x80033FB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80033FB4: jal         0x800997D8
    // 0x80033FB8: nop

    func_800997D8(rdram, ctx);
        goto after_4;
    // 0x80033FB8: nop

    after_4:
    // 0x80033FBC: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x80033FC0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80033FC4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80033FC8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80033FCC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80033FD0: lw          $t7, 0x72B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72B8);
    // 0x80033FD4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80033FD8: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80033FDC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80033FE0: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    // 0x80033FE4: jal         0x800B26E0
    // 0x80033FE8: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    func_800B26E0(rdram, ctx);
        goto after_5;
    // 0x80033FE8: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    after_5:
    // 0x80033FEC: bgez        $v0, L_8003400C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80033FF0: nop
    
            goto L_8003400C;
    }
    // 0x80033FF0: nop

    // 0x80033FF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80033FF8: lw          $t1, 0x72B8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72B8);
    // 0x80033FFC: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x80034000: nop

    // 0x80034004: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80034008: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
L_8003400C:
    // 0x8003400C: lhu         $t3, 0x26($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X26);
    // 0x80034010: nop

    // 0x80034014: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80034018: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8003401C: slti        $at, $t5, 0xA
    ctx->r1 = SIGNED(ctx->r13) < 0XA ? 1 : 0;
    // 0x80034020: bne         $at, $zero, L_80033F10
    if (ctx->r1 != 0) {
        // 0x80034024: sh          $t4, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r12;
            goto L_80033F10;
    }
    // 0x80034024: sh          $t4, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r12;
    // 0x80034028: jal         0x800C1A28
    // 0x8003402C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8003402C: nop

    after_6:
    // 0x80034030: b           L_80034038
    // 0x80034034: nop

        goto L_80034038;
    // 0x80034034: nop

L_80034038:
    // 0x80034038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003403C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80034040: jr          $ra
    // 0x80034044: nop

    return;
    // 0x80034044: nop

;}
RECOMP_FUNC void func_8000849C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000849C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800084A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800084A4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800084A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800084AC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800084B0: nop

    // 0x800084B4: addiu       $t7, $t6, 0x1C8
    ctx->r15 = ADD32(ctx->r14, 0X1C8);
    // 0x800084B8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800084BC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800084C0: nop

    // 0x800084C4: lw          $t9, 0x34C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34C);
    // 0x800084C8: nop

    // 0x800084CC: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800084D0: bne         $t0, $zero, L_80008BCC
    if (ctx->r8 != 0) {
        // 0x800084D4: nop
    
            goto L_80008BCC;
    }
    // 0x800084D4: nop

    // 0x800084D8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800084DC: nop

    // 0x800084E0: lw          $t2, 0x34C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34C);
    // 0x800084E4: nop

    // 0x800084E8: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x800084EC: beq         $t3, $zero, L_800087CC
    if (ctx->r11 == 0) {
        // 0x800084F0: nop
    
            goto L_800087CC;
    }
    // 0x800084F0: nop

    // 0x800084F4: andi        $t4, $t2, 0x1
    ctx->r12 = ctx->r10 & 0X1;
    // 0x800084F8: bne         $t4, $zero, L_800087CC
    if (ctx->r12 != 0) {
        // 0x800084FC: nop
    
            goto L_800087CC;
    }
    // 0x800084FC: nop

    // 0x80008500: andi        $t5, $t2, 0x2
    ctx->r13 = ctx->r10 & 0X2;
    // 0x80008504: bne         $t5, $zero, L_800087CC
    if (ctx->r13 != 0) {
        // 0x80008508: nop
    
            goto L_800087CC;
    }
    // 0x80008508: nop

    // 0x8000850C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008510: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80008514: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80008518: nop

    // 0x8000851C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x80008520: bne         $t8, $zero, L_800087CC
    if (ctx->r24 != 0) {
        // 0x80008524: nop
    
            goto L_800087CC;
    }
    // 0x80008524: nop

    // 0x80008528: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000852C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80008530: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80008534: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80008538: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8000853C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80008540: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80008544: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80008548: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000854C: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80008550: nop

    // 0x80008554: bc1f        L_80008564
    if (!c1cs) {
        // 0x80008558: nop
    
            goto L_80008564;
    }
    // 0x80008558: nop

    // 0x8000855C: b           L_80008598
    // 0x80008560: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
        goto L_80008598;
    // 0x80008560: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80008564:
    // 0x80008564: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80008568: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8000856C: lwc1        $f10, 0x14($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X14);
    // 0x80008570: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80008574: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80008578: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000857C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80008580: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80008584: nop

    // 0x80008588: bc1f        L_80008598
    if (!c1cs) {
        // 0x8000858C: nop
    
            goto L_80008598;
    }
    // 0x8000858C: nop

    // 0x80008590: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80008594: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_80008598:
    // 0x80008598: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000859C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x800085A0: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800085A4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800085A8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800085AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800085B0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800085B4: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800085B8: nop

    // 0x800085BC: bc1f        L_8000860C
    if (!c1cs) {
        // 0x800085C0: nop
    
            goto L_8000860C;
    }
    // 0x800085C0: nop

    // 0x800085C4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800085C8: nop

    // 0x800085CC: bne         $t2, $zero, L_800085E0
    if (ctx->r10 != 0) {
        // 0x800085D0: nop
    
            goto L_800085E0;
    }
    // 0x800085D0: nop

    // 0x800085D4: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800085D8: b           L_80008604
    // 0x800085DC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_80008604;
    // 0x800085DC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800085E0:
    // 0x800085E0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800085E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800085E8: bne         $t6, $at, L_800085FC
    if (ctx->r14 != ctx->r1) {
        // 0x800085EC: nop
    
            goto L_800085FC;
    }
    // 0x800085EC: nop

    // 0x800085F0: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800085F4: b           L_80008604
    // 0x800085F8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_80008604;
    // 0x800085F8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800085FC:
    // 0x800085FC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80008600: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80008604:
    // 0x80008604: b           L_80008678
    // 0x80008608: nop

        goto L_80008678;
    // 0x80008608: nop

L_8000860C:
    // 0x8000860C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80008610: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80008614: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80008618: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8000861C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80008620: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80008624: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80008628: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8000862C: nop

    // 0x80008630: bc1f        L_80008678
    if (!c1cs) {
        // 0x80008634: nop
    
            goto L_80008678;
    }
    // 0x80008634: nop

    // 0x80008638: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8000863C: nop

    // 0x80008640: bne         $t0, $zero, L_80008654
    if (ctx->r8 != 0) {
        // 0x80008644: nop
    
            goto L_80008654;
    }
    // 0x80008644: nop

    // 0x80008648: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8000864C: b           L_80008678
    // 0x80008650: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_80008678;
    // 0x80008650: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80008654:
    // 0x80008654: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80008658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000865C: bne         $t3, $at, L_80008670
    if (ctx->r11 != ctx->r1) {
        // 0x80008660: nop
    
            goto L_80008670;
    }
    // 0x80008660: nop

    // 0x80008664: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80008668: b           L_80008678
    // 0x8000866C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_80008678;
    // 0x8000866C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80008670:
    // 0x80008670: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80008674: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80008678:
    // 0x80008678: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8000867C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80008680: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80008684: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008688: beq         $t6, $at, L_8000869C
    if (ctx->r14 == ctx->r1) {
        // 0x8000868C: nop
    
            goto L_8000869C;
    }
    // 0x8000868C: nop

    // 0x80008690: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80008694: nop

    // 0x80008698: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_8000869C:
    // 0x8000869C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800086A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800086A4: beq         $t8, $at, L_800087CC
    if (ctx->r24 == ctx->r1) {
        // 0x800086A8: nop
    
            goto L_800087CC;
    }
    // 0x800086A8: nop

    // 0x800086AC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800086B0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800086B4: lw          $t0, 0x344($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X344);
    // 0x800086B8: lw          $t3, -0x5B34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B34);
    // 0x800086BC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800086C0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800086C4: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800086C8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800086CC: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800086D0: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x800086D4: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800086D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800086DC: beq         $t6, $at, L_800087CC
    if (ctx->r14 == ctx->r1) {
        // 0x800086E0: nop
    
            goto L_800087CC;
    }
    // 0x800086E0: nop

    // 0x800086E4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800086E8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800086EC: lw          $t9, 0x344($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X344);
    // 0x800086F0: lw          $t1, -0x5B34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5B34);
    // 0x800086F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800086F8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800086FC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80008700: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80008704: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80008708: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8000870C: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x80008710: lw          $t5, 0x10($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X10);
    // 0x80008714: nop

    // 0x80008718: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8000871C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80008720: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80008724: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80008728: lw          $t9, -0x5B34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B34);
    // 0x8000872C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80008730: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80008734: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80008738: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000873C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008740: beq         $t1, $at, L_80008760
    if (ctx->r9 == ctx->r1) {
        // 0x80008744: nop
    
            goto L_80008760;
    }
    // 0x80008744: nop

    // 0x80008748: jal         0x8005F064
    // 0x8000874C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8000874C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x80008750: bne         $v0, $zero, L_80008760
    if (ctx->r2 != 0) {
        // 0x80008754: nop
    
            goto L_80008760;
    }
    // 0x80008754: nop

    // 0x80008758: b           L_800087CC
    // 0x8000875C: nop

        goto L_800087CC;
    // 0x8000875C: nop

L_80008760:
    // 0x80008760: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80008764: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80008768: nop

    // 0x8000876C: sw          $t8, 0x348($t3)
    MEM_W(0X348, ctx->r11) = ctx->r24;
    // 0x80008770: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80008774: nop

    // 0x80008778: lw          $t2, 0x34C($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X34C);
    // 0x8000877C: nop

    // 0x80008780: ori         $t5, $t2, 0x3
    ctx->r13 = ctx->r10 | 0X3;
    // 0x80008784: sw          $t5, 0x34C($t4)
    MEM_W(0X34C, ctx->r12) = ctx->r13;
    // 0x80008788: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000878C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80008790: jal         0x80008FF0
    // 0x80008794: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80008FF0(rdram, ctx);
        goto after_1;
    // 0x80008794: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_1:
    // 0x80008798: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000879C: lw          $t6, -0x5B40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B40);
    // 0x800087A0: nop

    // 0x800087A4: beq         $t6, $zero, L_800087CC
    if (ctx->r14 == 0) {
        // 0x800087A8: nop
    
            goto L_800087CC;
    }
    // 0x800087A8: nop

    // 0x800087AC: jal         0x80031BB0
    // 0x800087B0: nop

    func_80031BB0(rdram, ctx);
        goto after_2;
    // 0x800087B0: nop

    after_2:
    // 0x800087B4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800087B8: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800087BC: lw          $t9, 0x34C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X34C);
    // 0x800087C0: nop

    // 0x800087C4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800087C8: sw          $t0, 0x34C($t7)
    MEM_W(0X34C, ctx->r15) = ctx->r8;
L_800087CC:
    // 0x800087CC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800087D0: nop

    // 0x800087D4: lw          $t8, 0x344($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X344);
    // 0x800087D8: lw          $t3, 0x348($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X348);
    // 0x800087DC: nop

    // 0x800087E0: beq         $t8, $t3, L_800089F0
    if (ctx->r24 == ctx->r11) {
        // 0x800087E4: nop
    
            goto L_800089F0;
    }
    // 0x800087E4: nop

    // 0x800087E8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800087EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800087F0: lwc1        $f4, 0x328($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X328);
    // 0x800087F4: nop

    // 0x800087F8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800087FC: nop

    // 0x80008800: bc1f        L_800088FC
    if (!c1cs) {
        // 0x80008804: nop
    
            goto L_800088FC;
    }
    // 0x80008804: nop

    // 0x80008808: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000880C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008810: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008814: lwc1        $f8, 0x33C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X33C);
    // 0x80008818: lwc1        $f18, 0x32C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X32C);
    // 0x8000881C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80008820: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80008824: swc1        $f4, 0x32C($t5)
    MEM_W(0X32C, ctx->r13) = ctx->f4.u32l;
    // 0x80008828: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8000882C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008830: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008834: lwc1        $f6, 0x340($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X340);
    // 0x80008838: lwc1        $f18, 0x330($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X330);
    // 0x8000883C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80008840: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80008844: swc1        $f16, 0x330($t4)
    MEM_W(0X330, ctx->r12) = ctx->f16.u32l;
    // 0x80008848: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000884C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80008850: lw          $t9, 0x34C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X34C);
    // 0x80008854: nop

    // 0x80008858: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8000885C: beq         $t0, $zero, L_800088BC
    if (ctx->r8 == 0) {
        // 0x80008860: nop
    
            goto L_800088BC;
    }
    // 0x80008860: nop

    // 0x80008864: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80008868: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8000886C: lwc1        $f4, 0x328($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X328);
    // 0x80008870: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80008874: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80008878: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000887C: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80008880: nop

    // 0x80008884: bc1f        L_800088BC
    if (!c1cs) {
        // 0x80008888: nop
    
            goto L_800088BC;
    }
    // 0x80008888: nop

    // 0x8000888C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008890: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80008894: lw          $t8, 0x34C($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X34C);
    // 0x80008898: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000889C: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x800088A0: sw          $t3, 0x34C($t1)
    MEM_W(0X34C, ctx->r9) = ctx->r11;
    // 0x800088A4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800088A8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800088AC: lw          $t5, 0x34C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X34C);
    // 0x800088B0: nop

    // 0x800088B4: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800088B8: sw          $t4, 0x34C($t2)
    MEM_W(0X34C, ctx->r10) = ctx->r12;
L_800088BC:
    // 0x800088BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800088C0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800088C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800088C8: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800088CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800088D0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800088D4: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800088D8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800088DC: nop

    // 0x800088E0: lwc1        $f6, 0x328($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X328);
    // 0x800088E4: nop

    // 0x800088E8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800088EC: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x800088F0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800088F4: b           L_800089F0
    // 0x800088F8: swc1        $f18, 0x328($t6)
    MEM_W(0X328, ctx->r14) = ctx->f18.u32l;
        goto L_800089F0;
    // 0x800088F8: swc1        $f18, 0x328($t6)
    MEM_W(0X328, ctx->r14) = ctx->f18.u32l;
L_800088FC:
    // 0x800088FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80008900: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80008904: nop

    // 0x80008908: swc1        $f16, 0x328($t9)
    MEM_W(0X328, ctx->r25) = ctx->f16.u32l;
    // 0x8000890C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008910: nop

    // 0x80008914: lwc1        $f6, 0x334($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X334);
    // 0x80008918: nop

    // 0x8000891C: swc1        $f6, 0x32C($t0)
    MEM_W(0X32C, ctx->r8) = ctx->f6.u32l;
    // 0x80008920: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80008924: nop

    // 0x80008928: lwc1        $f8, 0x338($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X338);
    // 0x8000892C: nop

    // 0x80008930: swc1        $f8, 0x330($t7)
    MEM_W(0X330, ctx->r15) = ctx->f8.u32l;
    // 0x80008934: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80008938: nop

    // 0x8000893C: lw          $t3, 0x348($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X348);
    // 0x80008940: nop

    // 0x80008944: sw          $t3, 0x344($t8)
    MEM_W(0X344, ctx->r24) = ctx->r11;
    // 0x80008948: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8000894C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80008950: lw          $t5, 0x34C($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X34C);
    // 0x80008954: nop

    // 0x80008958: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x8000895C: sw          $t4, 0x34C($t1)
    MEM_W(0X34C, ctx->r9) = ctx->r12;
    // 0x80008960: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80008964: lw          $a1, -0x5B34($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5B34);
    // 0x80008968: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000896C: jal         0x80009484
    // 0x80008970: nop

    func_80009484(rdram, ctx);
        goto after_3;
    // 0x80008970: nop

    after_3:
    // 0x80008974: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80008978: lw          $t2, -0x5B40($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5B40);
    // 0x8000897C: nop

    // 0x80008980: beq         $t2, $zero, L_80008998
    if (ctx->r10 == 0) {
        // 0x80008984: nop
    
            goto L_80008998;
    }
    // 0x80008984: nop

    // 0x80008988: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8000898C: lw          $a0, -0x5B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B40);
    // 0x80008990: jal         0x800BC980
    // 0x80008994: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x80008994: nop

    after_4:
L_80008998:
    // 0x80008998: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000899C: nop

    // 0x800089A0: lw          $a0, 0x344($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X344);
    // 0x800089A4: jal         0x80009C64
    // 0x800089A8: nop

    func_80009C64(rdram, ctx);
        goto after_5;
    // 0x800089A8: nop

    after_5:
    // 0x800089AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800089B0: sw          $v0, -0x5B40($at)
    MEM_W(-0X5B40, ctx->r1) = ctx->r2;
    // 0x800089B4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800089B8: lw          $t9, -0x5B40($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B40);
    // 0x800089BC: nop

    // 0x800089C0: beq         $t9, $zero, L_800089F0
    if (ctx->r25 == 0) {
        // 0x800089C4: nop
    
            goto L_800089F0;
    }
    // 0x800089C4: nop

    // 0x800089C8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800089CC: lw          $a0, -0x5B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B40);
    // 0x800089D0: jal         0x800319B0
    // 0x800089D4: nop

    func_800319B0(rdram, ctx);
        goto after_6;
    // 0x800089D4: nop

    after_6:
    // 0x800089D8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800089DC: nop

    // 0x800089E0: lw          $t7, 0x34C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X34C);
    // 0x800089E4: nop

    // 0x800089E8: ori         $t3, $t7, 0x4
    ctx->r11 = ctx->r15 | 0X4;
    // 0x800089EC: sw          $t3, 0x34C($t0)
    MEM_W(0X34C, ctx->r8) = ctx->r11;
L_800089F0:
    // 0x800089F0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800089F4: nop

    // 0x800089F8: lw          $t5, 0x34C($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X34C);
    // 0x800089FC: nop

    // 0x80008A00: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x80008A04: bne         $t4, $zero, L_80008A34
    if (ctx->r12 != 0) {
        // 0x80008A08: nop
    
            goto L_80008A34;
    }
    // 0x80008A08: nop

    // 0x80008A0C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80008A10: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x80008A14: bne         $t1, $zero, L_80008A34
    if (ctx->r9 != 0) {
        // 0x80008A18: nop
    
            goto L_80008A34;
    }
    // 0x80008A18: nop

    // 0x80008A1C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008A20: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80008A24: lw          $t6, 0x34C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X34C);
    // 0x80008A28: nop

    // 0x80008A2C: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80008A30: sw          $t9, 0x34C($t2)
    MEM_W(0X34C, ctx->r10) = ctx->r25;
L_80008A34:
    // 0x80008A34: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80008A38: nop

    // 0x80008A3C: lw          $t3, 0x34C($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X34C);
    // 0x80008A40: nop

    // 0x80008A44: andi        $t0, $t3, 0x8
    ctx->r8 = ctx->r11 & 0X8;
    // 0x80008A48: bne         $t0, $zero, L_80008ADC
    if (ctx->r8 != 0) {
        // 0x80008A4C: nop
    
            goto L_80008ADC;
    }
    // 0x80008A4C: nop

    // 0x80008A50: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80008A54: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80008A58: lhu         $t4, 0x0($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X0);
    // 0x80008A5C: nop

    // 0x80008A60: andi        $t5, $t4, 0x400
    ctx->r13 = ctx->r12 & 0X400;
    // 0x80008A64: bne         $t5, $zero, L_80008ADC
    if (ctx->r13 != 0) {
        // 0x80008A68: nop
    
            goto L_80008ADC;
    }
    // 0x80008A68: nop

    // 0x80008A6C: jal         0x80031874
    // 0x80008A70: nop

    func_80031874(rdram, ctx);
        goto after_7;
    // 0x80008A70: nop

    after_7:
    // 0x80008A74: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80008A78: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x80008A7C: lh          $a2, 0x7280($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7280);
    // 0x80008A80: lh          $a1, 0x7274($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7274);
    // 0x80008A84: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008A88: jal         0x80008FF0
    // 0x80008A8C: nop

    func_80008FF0(rdram, ctx);
        goto after_8;
    // 0x80008A8C: nop

    after_8:
    // 0x80008A90: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008A94: nop

    // 0x80008A98: lw          $s0, 0x348($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X348);
    // 0x80008A9C: nop

    // 0x80008AA0: sltiu       $t6, $s0, 0x1
    ctx->r14 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80008AA4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80008AA8: sw          $s0, 0x344($t1)
    MEM_W(0X344, ctx->r9) = ctx->r16;
    // 0x80008AAC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80008AB0: nop

    // 0x80008AB4: lw          $t2, 0x34C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X34C);
    // 0x80008AB8: nop

    // 0x80008ABC: ori         $t7, $t2, 0x3
    ctx->r15 = ctx->r10 | 0X3;
    // 0x80008AC0: sw          $t7, 0x34C($t9)
    MEM_W(0X34C, ctx->r25) = ctx->r15;
    // 0x80008AC4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80008AC8: nop

    // 0x80008ACC: lw          $t0, 0x34C($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X34C);
    // 0x80008AD0: nop

    // 0x80008AD4: ori         $t8, $t0, 0x8
    ctx->r24 = ctx->r8 | 0X8;
    // 0x80008AD8: sw          $t8, 0x34C($t3)
    MEM_W(0X34C, ctx->r11) = ctx->r24;
L_80008ADC:
    // 0x80008ADC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80008AE0: nop

    // 0x80008AE4: lw          $t5, 0x34C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34C);
    // 0x80008AE8: nop

    // 0x80008AEC: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x80008AF0: beq         $t6, $zero, L_80008B04
    if (ctx->r14 == 0) {
        // 0x80008AF4: nop
    
            goto L_80008B04;
    }
    // 0x80008AF4: nop

    // 0x80008AF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80008AFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008B00: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
L_80008B04:
    // 0x80008B04: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008B08: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x80008B0C: lw          $t2, 0x34C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34C);
    // 0x80008B10: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80008B14: and         $t7, $t2, $at
    ctx->r15 = ctx->r10 & ctx->r1;
    // 0x80008B18: bne         $t7, $zero, L_80008BC4
    if (ctx->r15 != 0) {
        // 0x80008B1C: nop
    
            goto L_80008BC4;
    }
    // 0x80008B1C: nop

    // 0x80008B20: lw          $t9, 0x344($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X344);
    // 0x80008B24: lw          $t0, 0x348($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X348);
    // 0x80008B28: nop

    // 0x80008B2C: bne         $t9, $t0, L_80008BC4
    if (ctx->r25 != ctx->r8) {
        // 0x80008B30: nop
    
            goto L_80008BC4;
    }
    // 0x80008B30: nop

    // 0x80008B34: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80008B38: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80008B3C: lhu         $t3, 0x0($t8)
    ctx->r11 = MEM_HU(ctx->r24, 0X0);
    // 0x80008B40: nop

    // 0x80008B44: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x80008B48: bne         $t4, $zero, L_80008BC4
    if (ctx->r12 != 0) {
        // 0x80008B4C: nop
    
            goto L_80008BC4;
    }
    // 0x80008B4C: nop

    // 0x80008B50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80008B54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80008B58: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80008B5C: lhu         $t6, 0xFF4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XFF4);
    // 0x80008B60: lhu         $t5, 0x10F2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X10F2);
    // 0x80008B64: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80008B68: lhu         $t1, 0x6($t7)
    ctx->r9 = MEM_HU(ctx->r15, 0X6);
    // 0x80008B6C: or          $t2, $t5, $t6
    ctx->r10 = ctx->r13 | ctx->r14;
    // 0x80008B70: and         $t9, $t1, $t2
    ctx->r25 = ctx->r9 & ctx->r10;
    // 0x80008B74: beq         $t9, $zero, L_80008BC4
    if (ctx->r25 == 0) {
        // 0x80008B78: nop
    
            goto L_80008BC4;
    }
    // 0x80008B78: nop

    // 0x80008B7C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008B80: nop

    // 0x80008B84: lw          $t8, 0x34C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X34C);
    // 0x80008B88: nop

    // 0x80008B8C: ori         $t3, $t8, 0x8000
    ctx->r11 = ctx->r24 | 0X8000;
    // 0x80008B90: sw          $t3, 0x34C($t0)
    MEM_W(0X34C, ctx->r8) = ctx->r11;
    // 0x80008B94: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80008B98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80008B9C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80008BA0: nop

    // 0x80008BA4: swc1        $f10, 0x328($t4)
    MEM_W(0X328, ctx->r12) = ctx->f10.u32l;
    // 0x80008BA8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008BAC: jal         0x8000975C
    // 0x80008BB0: nop

    func_8000975C(rdram, ctx);
        goto after_9;
    // 0x80008BB0: nop

    after_9:
    // 0x80008BB4: jal         0x80031BB0
    // 0x80008BB8: nop

    func_80031BB0(rdram, ctx);
        goto after_10;
    // 0x80008BB8: nop

    after_10:
    // 0x80008BBC: jal         0x80031728
    // 0x80008BC0: nop

    func_80031728(rdram, ctx);
        goto after_11;
    // 0x80008BC0: nop

    after_11:
L_80008BC4:
    // 0x80008BC4: b           L_80008D60
    // 0x80008BC8: nop

        goto L_80008D60;
    // 0x80008BC8: nop

L_80008BCC:
    // 0x80008BCC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80008BD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80008BD4: lwc1        $f18, 0x328($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X328);
    // 0x80008BD8: nop

    // 0x80008BDC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80008BE0: nop

    // 0x80008BE4: bc1f        L_80008C88
    if (!c1cs) {
        // 0x80008BE8: nop
    
            goto L_80008C88;
    }
    // 0x80008BE8: nop

    // 0x80008BEC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80008BF0: lui         $at, 0x402A
    ctx->r1 = S32(0X402A << 16);
    // 0x80008BF4: lwc1        $f6, 0x328($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X328);
    // 0x80008BF8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80008BFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80008C00: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80008C04: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80008C08: nop

    // 0x80008C0C: bc1f        L_80008C48
    if (!c1cs) {
        // 0x80008C10: nop
    
            goto L_80008C48;
    }
    // 0x80008C10: nop

    // 0x80008C14: jal         0x80031914
    // 0x80008C18: nop

    func_80031914(rdram, ctx);
        goto after_12;
    // 0x80008C18: nop

    after_12:
    // 0x80008C1C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80008C20: lw          $t7, -0x5B40($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5B40);
    // 0x80008C24: nop

    // 0x80008C28: beq         $t7, $zero, L_80008C40
    if (ctx->r15 == 0) {
        // 0x80008C2C: nop
    
            goto L_80008C40;
    }
    // 0x80008C2C: nop

    // 0x80008C30: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80008C34: lw          $a0, -0x5B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B40);
    // 0x80008C38: jal         0x800BC980
    // 0x80008C3C: nop

    SysMem_Free(rdram, ctx);
        goto after_13;
    // 0x80008C3C: nop

    after_13:
L_80008C40:
    // 0x80008C40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80008C44: sw          $zero, -0x5B40($at)
    MEM_W(-0X5B40, ctx->r1) = 0;
L_80008C48:
    // 0x80008C48: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80008C4C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80008C50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008C54: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008C58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80008C5C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80008C60: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80008C64: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008C68: nop

    // 0x80008C6C: lwc1        $f8, 0x328($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X328);
    // 0x80008C70: nop

    // 0x80008C74: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80008C78: sub.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f4.d - ctx->f6.d;
    // 0x80008C7C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80008C80: b           L_80008D60
    // 0x80008C84: swc1        $f10, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->f10.u32l;
        goto L_80008D60;
    // 0x80008C84: swc1        $f10, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->f10.u32l;
L_80008C88:
    // 0x80008C88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80008C8C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008C90: nop

    // 0x80008C94: swc1        $f16, 0x328($t2)
    MEM_W(0X328, ctx->r10) = ctx->f16.u32l;
    // 0x80008C98: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80008C9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008CA0: lw          $t8, 0x344($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X344);
    // 0x80008CA4: nop

    // 0x80008CA8: sh          $t8, 0x7294($at)
    MEM_H(0X7294, ctx->r1) = ctx->r24;
    // 0x80008CAC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80008CB0: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x80008CB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008CB8: sh          $t3, 0x72A0($at)
    MEM_H(0X72A0, ctx->r1) = ctx->r11;
    // 0x80008CBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008CC0: jal         0x80008F58
    // 0x80008CC4: nop

    func_80008F58(rdram, ctx);
        goto after_14;
    // 0x80008CC4: nop

    after_14:
    // 0x80008CC8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008CCC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008CD0: lw          $t4, 0x344($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X344);
    // 0x80008CD4: lw          $t6, -0x5B34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B34);
    // 0x80008CD8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80008CDC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80008CE0: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80008CE4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80008CE8: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x80008CEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008CF0: beq         $t1, $at, L_80008D24
    if (ctx->r9 == ctx->r1) {
        // 0x80008CF4: nop
    
            goto L_80008D24;
    }
    // 0x80008CF4: nop

    // 0x80008CF8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008CFC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80008D00: lw          $t9, 0x344($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X344);
    // 0x80008D04: lw          $t3, -0x5B34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B34);
    // 0x80008D08: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80008D0C: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80008D10: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80008D14: addu        $t0, $t8, $t3
    ctx->r8 = ADD32(ctx->r24, ctx->r11);
    // 0x80008D18: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x80008D1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80008D20: sh          $t4, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r12;
L_80008D24:
    // 0x80008D24: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80008D28: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80008D2C: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x80008D30: nop

    // 0x80008D34: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80008D38: sh          $t7, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r15;
    // 0x80008D3C: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x80008D40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80008D44: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
    // 0x80008D48: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008D4C: nop

    // 0x80008D50: lw          $t9, 0x100($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X100);
    // 0x80008D54: nop

    // 0x80008D58: ori         $t8, $t9, 0x8
    ctx->r24 = ctx->r25 | 0X8;
    // 0x80008D5C: sw          $t8, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->r24;
L_80008D60:
    // 0x80008D60: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80008D64: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x80008D68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008D6C: bne         $t3, $at, L_80008D8C
    if (ctx->r11 != ctx->r1) {
        // 0x80008D70: nop
    
            goto L_80008D8C;
    }
    // 0x80008D70: nop

    // 0x80008D74: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80008D78: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80008D7C: nop

    // 0x80008D80: addiu       $t4, $t0, 0x2C0
    ctx->r12 = ADD32(ctx->r8, 0X2C0);
    // 0x80008D84: b           L_80008DA0
    // 0x80008D88: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
        goto L_80008DA0;
    // 0x80008D88: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80008D8C:
    // 0x80008D8C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008D90: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80008D94: nop

    // 0x80008D98: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x80008D9C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80008DA0:
    // 0x80008DA0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80008DA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008DA8: lh          $t1, 0x120($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X120);
    // 0x80008DAC: lh          $t9, 0x11E($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X11E);
    // 0x80008DB0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80008DB4: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008DB8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008DBC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80008DC0: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80008DC4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008DC8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80008DCC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80008DD0: nop

    // 0x80008DD4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80008DD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008DDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008DE0: nop

    // 0x80008DE4: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80008DE8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80008DEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80008DF0: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
    // 0x80008DF4: nop

    // 0x80008DF8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80008DFC: nop

    // 0x80008E00: lh          $t0, 0x11E($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X11E);
    // 0x80008E04: nop

    // 0x80008E08: bgez        $t0, L_80008E30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80008E0C: nop
    
            goto L_80008E30;
    }
    // 0x80008E0C: nop

    // 0x80008E10: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80008E14: nop

    // 0x80008E18: sh          $zero, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = 0;
    // 0x80008E1C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80008E20: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80008E24: sh          $t6, 0x120($t7)
    MEM_H(0X120, ctx->r15) = ctx->r14;
    // 0x80008E28: jal         0x80009E5C
    // 0x80008E2C: nop

    func_80009E5C(rdram, ctx);
        goto after_15;
    // 0x80008E2C: nop

    after_15:
L_80008E30:
    // 0x80008E30: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80008E34: nop

    // 0x80008E38: lh          $t9, 0x11E($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X11E);
    // 0x80008E3C: nop

    // 0x80008E40: slti        $at, $t9, 0xB0
    ctx->r1 = SIGNED(ctx->r25) < 0XB0 ? 1 : 0;
    // 0x80008E44: bne         $at, $zero, L_80008E64
    if (ctx->r1 != 0) {
        // 0x80008E48: nop
    
            goto L_80008E64;
    }
    // 0x80008E48: nop

    // 0x80008E4C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80008E50: addiu       $t8, $zero, 0xAF
    ctx->r24 = ADD32(0, 0XAF);
    // 0x80008E54: sh          $t8, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r24;
    // 0x80008E58: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80008E5C: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
    // 0x80008E60: sh          $t5, 0x120($t3)
    MEM_H(0X120, ctx->r11) = ctx->r13;
L_80008E64:
    // 0x80008E64: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008E68: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80008E6C: lwc1        $f6, 0x32C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X32C);
    // 0x80008E70: nop

    // 0x80008E74: swc1        $f6, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f6.u32l;
    // 0x80008E78: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80008E7C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80008E80: lwc1        $f10, 0x330($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X330);
    // 0x80008E84: nop

    // 0x80008E88: swc1        $f10, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f10.u32l;
    // 0x80008E8C: jal         0x800C1754
    // 0x80008E90: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_16;
    // 0x80008E90: nop

    after_16:
    // 0x80008E94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80008E98: jal         0x8009A14C
    // 0x80008E9C: nop

    func_8009A14C(rdram, ctx);
        goto after_17;
    // 0x80008E9C: nop

    after_17:
    // 0x80008EA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80008EA4: jal         0x800997D8
    // 0x80008EA8: nop

    func_800997D8(rdram, ctx);
        goto after_18;
    // 0x80008EA8: nop

    after_18:
    // 0x80008EAC: jal         0x800C1A28
    // 0x80008EB0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_19;
    // 0x80008EB0: nop

    after_19:
    // 0x80008EB4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008EB8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80008EBC: lw          $t9, 0x34C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X34C);
    // 0x80008EC0: nop

    // 0x80008EC4: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80008EC8: beq         $t8, $zero, L_80008F40
    if (ctx->r24 == 0) {
        // 0x80008ECC: nop
    
            goto L_80008F40;
    }
    // 0x80008ECC: nop

    // 0x80008ED0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008ED4: jal         0x800098F0
    // 0x80008ED8: nop

    func_800098F0(rdram, ctx);
        goto after_20;
    // 0x80008ED8: nop

    after_20:
    // 0x80008EDC: jal         0x800C1754
    // 0x80008EE0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_21;
    // 0x80008EE0: nop

    after_21:
    // 0x80008EE4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008EE8: jal         0x8009A14C
    // 0x80008EEC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_8009A14C(rdram, ctx);
        goto after_22;
    // 0x80008EEC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_22:
    // 0x80008EF0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008EF4: nop

    // 0x80008EF8: lwc1        $f12, 0x130($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X130);
    // 0x80008EFC: jal         0x800C2780
    // 0x80008F00: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_23;
    // 0x80008F00: nop

    after_23:
    // 0x80008F04: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80008F08: nop

    // 0x80008F0C: lwc1        $f12, 0x12C($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X12C);
    // 0x80008F10: jal         0x800C25B8
    // 0x80008F14: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_24;
    // 0x80008F14: nop

    after_24:
    // 0x80008F18: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80008F1C: nop

    // 0x80008F20: lwc1        $f12, 0x128($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X128);
    // 0x80008F24: jal         0x800C23E8
    // 0x80008F28: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_25;
    // 0x80008F28: nop

    after_25:
    // 0x80008F2C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008F30: jal         0x800997D8
    // 0x80008F34: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_800997D8(rdram, ctx);
        goto after_26;
    // 0x80008F34: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_26:
    // 0x80008F38: jal         0x800C1A28
    // 0x80008F3C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_27;
    // 0x80008F3C: nop

    after_27:
L_80008F40:
    // 0x80008F40: b           L_80008F48
    // 0x80008F44: nop

        goto L_80008F48;
    // 0x80008F44: nop

L_80008F48:
    // 0x80008F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80008F4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008F50: jr          $ra
    // 0x80008F54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80008F54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800847EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800847F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800847F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800847F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800847FC: jal         0x8008A46C
    // 0x80084800: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80084800: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80084804: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80084808: nop

    // 0x8008480C: sh          $zero, 0xC14($t6)
    MEM_H(0XC14, ctx->r14) = 0;
    // 0x80084810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084814: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80084818: lh          $a1, 0x7A16($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7A16);
    // 0x8008481C: jal         0x8008C2E8
    // 0x80084820: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_1;
    // 0x80084820: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    after_1:
    // 0x80084824: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80084828: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008482C: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084830: jal         0x800AEA98
    // 0x80084834: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_2;
    // 0x80084834: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_2:
    // 0x80084838: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008483C: nop

    // 0x80084840: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80084844: nop

    // 0x80084848: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008484C: beq         $t9, $zero, L_80084888
    if (ctx->r25 == 0) {
        // 0x80084850: nop
    
            goto L_80084888;
    }
    // 0x80084850: nop

    // 0x80084854: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80084858: lh          $t0, 0x7A16($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7A16);
    // 0x8008485C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80084860: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80084864: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80084868: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008486C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80084870: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80084874: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80084878: addiu       $t2, $t2, 0x7AE8
    ctx->r10 = ADD32(ctx->r10, 0X7AE8);
    // 0x8008487C: lw          $a1, 0xC10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC10);
    // 0x80084880: jal         0x8008C558
    // 0x80084884: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_8008C558(rdram, ctx);
        goto after_3;
    // 0x80084884: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_3:
L_80084888:
    // 0x80084888: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008488C: nop

    // 0x80084890: lh          $v0, 0x4($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X4);
    // 0x80084894: b           L_800848A4
    // 0x80084898: nop

        goto L_800848A4;
    // 0x80084898: nop

    // 0x8008489C: b           L_800848A4
    // 0x800848A0: nop

        goto L_800848A4;
    // 0x800848A0: nop

L_800848A4:
    // 0x800848A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800848A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800848AC: jr          $ra
    // 0x800848B0: nop

    return;
    // 0x800848B0: nop

;}
RECOMP_FUNC void func_8001CF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001CF10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001CF14: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001CF18: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8001CF1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001CF20: lhu         $t8, 0x11A4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11A4);
    // 0x8001CF24: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x8001CF28: nop

    // 0x8001CF2C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8001CF30: bne         $t9, $zero, L_8001CF50
    if (ctx->r25 != 0) {
        // 0x8001CF34: nop
    
            goto L_8001CF50;
    }
    // 0x8001CF34: nop

    // 0x8001CF38: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001CF3C: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x8001CF40: nop

    // 0x8001CF44: and         $t1, $t7, $t0
    ctx->r9 = ctx->r15 & ctx->r8;
    // 0x8001CF48: beq         $t1, $zero, L_8001CF58
    if (ctx->r9 == 0) {
        // 0x8001CF4C: nop
    
            goto L_8001CF58;
    }
    // 0x8001CF4C: nop

L_8001CF50:
    // 0x8001CF50: b           L_8001CF68
    // 0x8001CF54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001CF68;
    // 0x8001CF54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001CF58:
    // 0x8001CF58: b           L_8001CF68
    // 0x8001CF5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CF68;
    // 0x8001CF5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CF60: b           L_8001CF68
    // 0x8001CF64: nop

        goto L_8001CF68;
    // 0x8001CF64: nop

L_8001CF68:
    // 0x8001CF68: jr          $ra
    // 0x8001CF6C: nop

    return;
    // 0x8001CF6C: nop

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
RECOMP_FUNC void func_800668A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800668A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800668A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800668A8: jal         0x80061348
    // 0x800668AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800668AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x800668B0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800668B4: b           L_800668C4
    // 0x800668B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800668C4;
    // 0x800668B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800668BC: b           L_800668C4
    // 0x800668C0: nop

        goto L_800668C4;
    // 0x800668C0: nop

L_800668C4:
    // 0x800668C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800668C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800668CC: jr          $ra
    // 0x800668D0: nop

    return;
    // 0x800668D0: nop

;}
RECOMP_FUNC void func_8006BFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BFD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BFD8: jal         0x8005F064
    // 0x8006BFDC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BFDC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_0:
    // 0x8006BFE0: b           L_8006BFF0
    // 0x8006BFE4: nop

        goto L_8006BFF0;
    // 0x8006BFE4: nop

    // 0x8006BFE8: b           L_8006BFF0
    // 0x8006BFEC: nop

        goto L_8006BFF0;
    // 0x8006BFEC: nop

L_8006BFF0:
    // 0x8006BFF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BFF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BFF8: jr          $ra
    // 0x8006BFFC: nop

    return;
    // 0x8006BFFC: nop

;}
RECOMP_FUNC void func_800984F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800984F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800984F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800984F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800984FC: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80098500: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80098504: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80098508: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009850C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80098510: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80098514: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80098518: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009851C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80098520: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x80098524: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80098528: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009852C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098530: nop

    // 0x80098534: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80098538: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x8009853C: nop

    // 0x80098540: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80098544: bne         $t2, $zero, L_80098554
    if (ctx->r10 != 0) {
        // 0x80098548: nop
    
            goto L_80098554;
    }
    // 0x80098548: nop

    // 0x8009854C: b           L_800985AC
    // 0x80098550: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800985AC;
    // 0x80098550: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098554:
    // 0x80098554: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x80098558: jal         0x800C1154
    // 0x8009855C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C1154(rdram, ctx);
        goto after_0;
    // 0x8009855C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80098560: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80098564: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098568: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    // 0x8009856C: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x80098570: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80098574: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x80098578: jal         0x80097258
    // 0x8009857C: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    func_80097258(rdram, ctx);
        goto after_1;
    // 0x8009857C: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    after_1:
    // 0x80098580: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80098584: nop

    // 0x80098588: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x8009858C: lbu         $t5, 0x2E9($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2E9);
    // 0x80098590: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80098594: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80098598: sb          $t6, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r14;
    // 0x8009859C: b           L_800985AC
    // 0x800985A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800985AC;
    // 0x800985A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800985A4: b           L_800985AC
    // 0x800985A8: nop

        goto L_800985AC;
    // 0x800985A8: nop

L_800985AC:
    // 0x800985AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800985B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800985B4: jr          $ra
    // 0x800985B8: nop

    return;
    // 0x800985B8: nop

;}
RECOMP_FUNC void func_8004A054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A054: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8004A058: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8004A05C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8004A060: nop

    // 0x8004A064: lh          $t7, 0x48($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X48);
    // 0x8004A068: nop

    // 0x8004A06C: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8004A070: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8004A074: lui         $at, 0x8080
    ctx->r1 = S32(0X8080 << 16);
    // 0x8004A078: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004A07C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004A080: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A084: addiu       $at, $zero, 0x0
    ctx->r1 = ADD32(0, 0X0);
    // 0x8004A088: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x8004A08C: xor         $v0, $v0, $t3
    ctx->r2 = ctx->r2 ^ ctx->r11;
    // 0x8004A090: xor         $at, $at, $t2
    ctx->r1 = ctx->r1 ^ ctx->r10;
    // 0x8004A094: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x8004A098: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004A09C: b           L_8004A0AC
    // 0x8004A0A0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_8004A0AC;
    // 0x8004A0A0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004A0A4: b           L_8004A0AC
    // 0x8004A0A8: nop

        goto L_8004A0AC;
    // 0x8004A0A8: nop

L_8004A0AC:
    // 0x8004A0AC: jr          $ra
    // 0x8004A0B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8004A0B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006C630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C638: jal         0x8005F064
    // 0x8006C63C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C63C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x8006C640: b           L_8006C650
    // 0x8006C644: nop

        goto L_8006C650;
    // 0x8006C644: nop

    // 0x8006C648: b           L_8006C650
    // 0x8006C64C: nop

        goto L_8006C650;
    // 0x8006C64C: nop

L_8006C650:
    // 0x8006C650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C658: jr          $ra
    // 0x8006C65C: nop

    return;
    // 0x8006C65C: nop

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
RECOMP_FUNC void func_8006407C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006407C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064084: jal         0x8005F064
    // 0x80064088: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064088: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    after_0:
    // 0x8006408C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064094: beq         $v0, $zero, L_800640AC
    if (ctx->r2 == 0) {
        // 0x80064098: nop
    
            goto L_800640AC;
    }
    // 0x80064098: nop

    // 0x8006409C: jal         0x8005F064
    // 0x800640A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x800640A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x800640A4: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800640A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800640AC:
    // 0x800640AC: b           L_800640BC
    // 0x800640B0: nop

        goto L_800640BC;
    // 0x800640B0: nop

    // 0x800640B4: b           L_800640BC
    // 0x800640B8: nop

        goto L_800640BC;
    // 0x800640B8: nop

L_800640BC:
    // 0x800640BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800640C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800640C4: jr          $ra
    // 0x800640C8: nop

    return;
    // 0x800640C8: nop

;}
RECOMP_FUNC void func_800662A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800662AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800662B0: jal         0x80061348
    // 0x800662B4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800662B4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800662B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800662BC: b           L_800662CC
    // 0x800662C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800662CC;
    // 0x800662C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800662C4: b           L_800662CC
    // 0x800662C8: nop

        goto L_800662CC;
    // 0x800662C8: nop

L_800662CC:
    // 0x800662CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800662D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800662D4: jr          $ra
    // 0x800662D8: nop

    return;
    // 0x800662D8: nop

;}
RECOMP_FUNC void func_80068578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068578: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006857C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068580: nop

    // 0x80068584: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068588: nop

    // 0x8006858C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068590: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068594: jr          $ra
    // 0x80068598: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068598: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006859C: jr          $ra
    // 0x800685A0: nop

    return;
    // 0x800685A0: nop

    // 0x800685A4: jr          $ra
    // 0x800685A8: nop

    return;
    // 0x800685A8: nop

;}
RECOMP_FUNC void Scheduler_HandleRspMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097988: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009798C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097990: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097994: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80097998: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009799C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800979A0: nop

    // 0x800979A4: lw          $t7, 0x294($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X294);
    // 0x800979A8: nop

    // 0x800979AC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800979B0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800979B4: nop

    // 0x800979B8: sw          $zero, 0x294($t8)
    MEM_W(0X294, ctx->r24) = 0;
    // 0x800979BC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800979C0: nop

    // 0x800979C4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800979C8: nop

    // 0x800979CC: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x800979D0: beq         $t1, $zero, L_80097A70
    if (ctx->r9 == 0) {
        // 0x800979D4: nop
    
            goto L_80097A70;
    }
    // 0x800979D4: nop

    // 0x800979D8: jal         0x800C4D80
    // 0x800979DC: addiu       $a0, $t9, 0x10
    ctx->r4 = ADD32(ctx->r25, 0X10);
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_0;
    // 0x800979DC: addiu       $a0, $t9, 0x10
    ctx->r4 = ADD32(ctx->r25, 0X10);
    after_0:
    // 0x800979E0: beq         $v0, $zero, L_80097A70
    if (ctx->r2 == 0) {
        // 0x800979E4: nop
    
            goto L_80097A70;
    }
    // 0x800979E4: nop

    // 0x800979E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800979EC: nop

    // 0x800979F0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800979F4: nop

    // 0x800979F8: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x800979FC: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80097A00: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80097A04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80097A08: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80097A0C: nop

    // 0x80097A10: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80097A14: bne         $t7, $at, L_80097A68
    if (ctx->r15 != ctx->r1) {
        // 0x80097A18: nop
    
            goto L_80097A68;
    }
    // 0x80097A18: nop

    // 0x80097A1C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097A20: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80097A24: lw          $t0, 0x288($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X288);
    // 0x80097A28: nop

    // 0x80097A2C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80097A30: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097A34: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80097A38: nop

    // 0x80097A3C: sw          $t9, 0x288($t3)
    MEM_W(0X288, ctx->r11) = ctx->r25;
    // 0x80097A40: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80097A44: nop

    // 0x80097A48: lw          $t2, 0x290($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X290);
    // 0x80097A4C: nop

    // 0x80097A50: bne         $t2, $zero, L_80097A68
    if (ctx->r10 != 0) {
        // 0x80097A54: nop
    
            goto L_80097A68;
    }
    // 0x80097A54: nop

    // 0x80097A58: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80097A5C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097A60: nop

    // 0x80097A64: sw          $t5, 0x290($t6)
    MEM_W(0X290, ctx->r14) = ctx->r13;
L_80097A68:
    // 0x80097A68: b           L_80097A98
    // 0x80097A6C: nop

        goto L_80097A98;
    // 0x80097A6C: nop

L_80097A70:
    // 0x80097A70: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097A74: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80097A78: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80097A7C: nop

    // 0x80097A80: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80097A84: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x80097A88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097A8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80097A90: jal         0x80097C5C
    // 0x80097A94: nop

    Scheduler_IsTaskComplete(rdram, ctx);
        goto after_1;
    // 0x80097A94: nop

    after_1:
L_80097A98:
    // 0x80097A98: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80097A9C: nop

    // 0x80097AA0: lw          $t9, 0x294($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X294);
    // 0x80097AA4: lw          $t2, 0x298($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X298);
    // 0x80097AA8: sltiu       $t3, $t9, 0x1
    ctx->r11 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80097AAC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80097AB0: sltiu       $t5, $t2, 0x1
    ctx->r13 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80097AB4: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80097AB8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80097ABC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097AC0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80097AC4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80097AC8: jal         0x80097F78
    // 0x80097ACC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    Scheduler_ScheduleTask(rdram, ctx);
        goto after_2;
    // 0x80097ACC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80097AD0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80097AD4: nop

    // 0x80097AD8: beq         $v0, $t8, L_80097AF4
    if (ctx->r2 == ctx->r24) {
        // 0x80097ADC: nop
    
            goto L_80097AF4;
    }
    // 0x80097ADC: nop

    // 0x80097AE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097AE4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80097AE8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80097AEC: jal         0x80097DDC
    // 0x80097AF0: nop

    Scheduler_ExecuteTask(rdram, ctx);
        goto after_3;
    // 0x80097AF0: nop

    after_3:
L_80097AF4:
    // 0x80097AF4: b           L_80097AFC
    // 0x80097AF8: nop

        goto L_80097AFC;
    // 0x80097AF8: nop

L_80097AFC:
    // 0x80097AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097B00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097B04: jr          $ra
    // 0x80097B08: nop

    return;
    // 0x80097B08: nop

;}
RECOMP_FUNC void func_800686E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800686E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800686E8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800686EC: nop

    // 0x800686F0: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800686F4: nop

    // 0x800686F8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800686FC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068700: jr          $ra
    // 0x80068704: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068704: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068708: jr          $ra
    // 0x8006870C: nop

    return;
    // 0x8006870C: nop

    // 0x80068710: jr          $ra
    // 0x80068714: nop

    return;
    // 0x80068714: nop

;}
RECOMP_FUNC void func_80065BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BBC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065BC0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065BC4: nop

    // 0x80065BC8: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80065BCC: nop

    // 0x80065BD0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065BD4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065BD8: jr          $ra
    // 0x80065BDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065BDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065BE0: jr          $ra
    // 0x80065BE4: nop

    return;
    // 0x80065BE4: nop

    // 0x80065BE8: jr          $ra
    // 0x80065BEC: nop

    return;
    // 0x80065BEC: nop

;}
RECOMP_FUNC void func_8006EE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE1C: jal         0x80061348
    // 0x8006EE20: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EE20: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x8006EE24: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006EE28: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006EE2C: b           L_8006EE3C
    // 0x8006EE30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EE3C;
    // 0x8006EE30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EE34: b           L_8006EE3C
    // 0x8006EE38: nop

        goto L_8006EE3C;
    // 0x8006EE38: nop

L_8006EE3C:
    // 0x8006EE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EE40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EE44: jr          $ra
    // 0x8006EE48: nop

    return;
    // 0x8006EE48: nop

;}
RECOMP_FUNC void func_8006F220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F220: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F224: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F228: nop

    // 0x8006F22C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F230: nop

    // 0x8006F234: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F238: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F23C: jr          $ra
    // 0x8006F240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F244: jr          $ra
    // 0x8006F248: nop

    return;
    // 0x8006F248: nop

    // 0x8006F24C: jr          $ra
    // 0x8006F250: nop

    return;
    // 0x8006F250: nop

;}
RECOMP_FUNC void func_80066D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066D5C: jal         0x80061348
    // 0x80066D60: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066D60: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_0:
    // 0x80066D64: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066D68: b           L_80066D78
    // 0x80066D6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066D78;
    // 0x80066D6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066D70: b           L_80066D78
    // 0x80066D74: nop

        goto L_80066D78;
    // 0x80066D74: nop

L_80066D78:
    // 0x80066D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066D80: jr          $ra
    // 0x80066D84: nop

    return;
    // 0x80066D84: nop

;}
RECOMP_FUNC void func_80031BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BA0: jr          $ra
    // 0x80031BA4: nop

    return;
    // 0x80031BA4: nop

    // 0x80031BA8: jr          $ra
    // 0x80031BAC: nop

    return;
    // 0x80031BAC: nop

;}
RECOMP_FUNC void func_80022124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002212C: jal         0x800BB4DC
    // 0x80022130: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800BB4DC(rdram, ctx);
        goto after_0;
    // 0x80022130: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x80022134: b           L_8002213C
    // 0x80022138: nop

        goto L_8002213C;
    // 0x80022138: nop

L_8002213C:
    // 0x8002213C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022144: jr          $ra
    // 0x80022148: nop

    return;
    // 0x80022148: nop

;}
RECOMP_FUNC void func_80077C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077C04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077C08: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077C0C: nop

    // 0x80077C10: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80077C14: nop

    // 0x80077C18: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80077C1C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077C20: jr          $ra
    // 0x80077C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077C28: jr          $ra
    // 0x80077C2C: nop

    return;
    // 0x80077C2C: nop

    // 0x80077C30: jr          $ra
    // 0x80077C34: nop

    return;
    // 0x80077C34: nop

;}
RECOMP_FUNC void func_80072B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B78: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072B7C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072B80: nop

    // 0x80072B84: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072B88: nop

    // 0x80072B8C: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x80072B90: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072B94: jr          $ra
    // 0x80072B98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072B98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B9C: jr          $ra
    // 0x80072BA0: nop

    return;
    // 0x80072BA0: nop

    // 0x80072BA4: jr          $ra
    // 0x80072BA8: nop

    return;
    // 0x80072BA8: nop

;}
RECOMP_FUNC void func_80064B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064B3C: jal         0x8005F064
    // 0x80064B40: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064B40: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x80064B44: b           L_80064B54
    // 0x80064B48: nop

        goto L_80064B54;
    // 0x80064B48: nop

    // 0x80064B4C: b           L_80064B54
    // 0x80064B50: nop

        goto L_80064B54;
    // 0x80064B50: nop

L_80064B54:
    // 0x80064B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064B5C: jr          $ra
    // 0x80064B60: nop

    return;
    // 0x80064B60: nop

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
RECOMP_FUNC void func_80099E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099E2C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80099E30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80099E34: nop

    // 0x80099E38: swc1        $f4, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->f4.u32l;
    // 0x80099E3C: lwc1        $f12, 0xD4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XD4);
    // 0x80099E40: nop

    // 0x80099E44: swc1        $f12, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->f12.u32l;
    // 0x80099E48: swc1        $f12, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f12.u32l;
    // 0x80099E4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80099E50: nop

    // 0x80099E54: swc1        $f6, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f6.u32l;
    // 0x80099E58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80099E5C: nop

    // 0x80099E60: swc1        $f8, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f8.u32l;
    // 0x80099E64: lwc1        $f12, 0xF0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XF0);
    // 0x80099E68: nop

    // 0x80099E6C: swc1        $f12, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f12.u32l;
    // 0x80099E70: swc1        $f12, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f12.u32l;
    // 0x80099E74: sw          $zero, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = 0;
    // 0x80099E78: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x80099E7C: nop

    // 0x80099E80: sw          $t6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->r14;
    // 0x80099E84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80099E88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80099E8C: nop

    // 0x80099E90: swc1        $f10, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f10.u32l;
    // 0x80099E94: lwc1        $f16, 0xF8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80099E98: nop

    // 0x80099E9C: swc1        $f16, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f16.u32l;
    // 0x80099EA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80099EA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80099EA8: nop

    // 0x80099EAC: swc1        $f18, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f18.u32l;
    // 0x80099EB0: sh          $zero, 0x102($a0)
    MEM_H(0X102, ctx->r4) = 0;
    // 0x80099EB4: lh          $t7, 0x102($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X102);
    // 0x80099EB8: nop

    // 0x80099EBC: sh          $t7, 0x100($a0)
    MEM_H(0X100, ctx->r4) = ctx->r15;
    // 0x80099EC0: sw          $zero, 0x108($a0)
    MEM_W(0X108, ctx->r4) = 0;
    // 0x80099EC4: lw          $t8, 0x108($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X108);
    // 0x80099EC8: nop

    // 0x80099ECC: sw          $t8, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r24;
    // 0x80099ED0: sh          $zero, 0x10E($a0)
    MEM_H(0X10E, ctx->r4) = 0;
    // 0x80099ED4: lh          $t9, 0x10E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X10E);
    // 0x80099ED8: nop

    // 0x80099EDC: sh          $t9, 0x10C($a0)
    MEM_H(0X10C, ctx->r4) = ctx->r25;
    // 0x80099EE0: sw          $zero, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = 0;
    // 0x80099EE4: sw          $zero, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = 0;
    // 0x80099EE8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80099EEC: sh          $t0, 0x114($a0)
    MEM_H(0X114, ctx->r4) = ctx->r8;
    // 0x80099EF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80099EF4: sh          $t1, 0x116($a0)
    MEM_H(0X116, ctx->r4) = ctx->r9;
    // 0x80099EF8: sw          $zero, 0x110($a0)
    MEM_W(0X110, ctx->r4) = 0;
    // 0x80099EFC: sh          $zero, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = 0;
    // 0x80099F00: lh          $a1, 0x11C($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X11C);
    // 0x80099F04: nop

    // 0x80099F08: sh          $a1, 0x11A($a0)
    MEM_H(0X11A, ctx->r4) = ctx->r5;
    // 0x80099F0C: sh          $a1, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r5;
    // 0x80099F10: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80099F14: sh          $t2, 0x11E($a0)
    MEM_H(0X11E, ctx->r4) = ctx->r10;
    // 0x80099F18: sh          $zero, 0x122($a0)
    MEM_H(0X122, ctx->r4) = 0;
    // 0x80099F1C: sh          $zero, 0x124($a0)
    MEM_H(0X124, ctx->r4) = 0;
    // 0x80099F20: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80099F24: sh          $t3, 0xC4($a0)
    MEM_H(0XC4, ctx->r4) = ctx->r11;
    // 0x80099F28: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80099F2C: sh          $t4, 0x126($a0)
    MEM_H(0X126, ctx->r4) = ctx->r12;
    // 0x80099F30: sw          $zero, 0x128($a0)
    MEM_W(0X128, ctx->r4) = 0;
    // 0x80099F34: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_80099F38:
    // 0x80099F38: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80099F3C: nop

    // 0x80099F40: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80099F44: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80099F48: sw          $zero, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = 0;
    // 0x80099F4C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80099F50: nop

    // 0x80099F54: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80099F58: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80099F5C: bne         $at, $zero, L_80099F38
    if (ctx->r1 != 0) {
        // 0x80099F60: sw          $t9, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r25;
            goto L_80099F38;
    }
    // 0x80099F60: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x80099F64: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80099F68: sw          $zero, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = 0;
    // 0x80099F6C: sw          $zero, 0x140($a0)
    MEM_W(0X140, ctx->r4) = 0;
    // 0x80099F70: sw          $zero, 0x144($a0)
    MEM_W(0X144, ctx->r4) = 0;
    // 0x80099F74: sw          $zero, 0x148($a0)
    MEM_W(0X148, ctx->r4) = 0;
    // 0x80099F78: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80099F7C: sw          $zero, 0x150($a0)
    MEM_W(0X150, ctx->r4) = 0;
    // 0x80099F80: b           L_80099F88
    // 0x80099F84: nop

        goto L_80099F88;
    // 0x80099F84: nop

L_80099F88:
    // 0x80099F88: jr          $ra
    // 0x80099F8C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80099F8C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_RotateZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2780: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C2784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2788: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C278C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C2790: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C2794: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2798: jal         0x800C1A84
    // 0x800C279C: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_0;
    // 0x800C279C: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    after_0:
    // 0x800C27A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C27A4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C27A8: lwc1        $f9, -0x180($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X180);
    // 0x800C27AC: lwc1        $f8, -0x17C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X17C);
    // 0x800C27B0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C27B4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800C27B8: jal         0x800C3338
    // 0x800C27BC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_1;
    // 0x800C27BC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800C27C0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800C27C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C27C8: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C27CC: lwc1        $f5, -0x178($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X178);
    // 0x800C27D0: lwc1        $f4, -0x174($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X174);
    // 0x800C27D4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C27D8: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C27DC: jal         0x800C3070
    // 0x800C27E0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800C27E0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_2:
    // 0x800C27E4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C27E8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C27EC: nop

    // 0x800C27F0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800C27F4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C27F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C27FC: addiu       $t6, $t6, 0xCF0
    ctx->r14 = ADD32(ctx->r14, 0XCF0);
    // 0x800C2800: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800C2804: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800C2808: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800C280C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2810: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C2814: nop

    // 0x800C2818: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800C281C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800C2820: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800C2824: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C2828: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C282C: lwc1        $f20, 0x0($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C2830: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2834: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2838: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C283C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2840: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2844: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C2848: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800C284C: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2850: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C2854: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x800C2858: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C285C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2860: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2864: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2868: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C286C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2870: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2874: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C2878: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x800C287C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800C2880: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C2884: lwc1        $f20, 0x4($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C2888: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C288C: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2890: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x800C2894: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2898: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C289C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C28A0: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800C28A4: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C28A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C28AC: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x800C28B0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C28B4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C28B8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C28BC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C28C0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C28C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C28C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C28CC: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C28D0: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x800C28D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C28D8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C28DC: lwc1        $f20, 0x8($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800C28E0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C28E4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C28E8: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800C28EC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C28F0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C28F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C28F8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C28FC: mul.s       $f16, $f20, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2900: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C2904: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x800C2908: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C290C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2910: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2914: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2918: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C291C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2920: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C2924: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C2928: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x800C292C: b           L_800C2934
    // 0x800C2930: nop

        goto L_800C2934;
    // 0x800C2930: nop

L_800C2934:
    // 0x800C2934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2938: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C293C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2940: jr          $ra
    // 0x800C2944: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C2944: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80073A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073A2C: jal         0x80061488
    // 0x80073A30: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073A30: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073A34: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x80073A38: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073A3C: b           L_80073A4C
    // 0x80073A40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073A4C;
    // 0x80073A40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073A44: b           L_80073A4C
    // 0x80073A48: nop

        goto L_80073A4C;
    // 0x80073A48: nop

L_80073A4C:
    // 0x80073A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073A54: jr          $ra
    // 0x80073A58: nop

    return;
    // 0x80073A58: nop

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
RECOMP_FUNC void func_8006C420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C428: jal         0x8005F064
    // 0x8006C42C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C42C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_0:
    // 0x8006C430: b           L_8006C440
    // 0x8006C434: nop

        goto L_8006C440;
    // 0x8006C434: nop

    // 0x8006C438: b           L_8006C440
    // 0x8006C43C: nop

        goto L_8006C440;
    // 0x8006C43C: nop

L_8006C440:
    // 0x8006C440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C448: jr          $ra
    // 0x8006C44C: nop

    return;
    // 0x8006C44C: nop

;}
RECOMP_FUNC void func_80090D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090D34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80090D38: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090D3C: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x80090D40: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80090D44: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80090D48: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x80090D4C: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80090D50: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80090D54: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x80090D58: sh          $t0, 0x100($t2)
    MEM_H(0X100, ctx->r10) = ctx->r8;
    // 0x80090D5C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80090D60: lw          $t4, -0x282C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X282C);
    // 0x80090D64: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80090D68: addiu       $t3, $t3, -0x2870
    ctx->r11 = ADD32(ctx->r11, -0X2870);
    // 0x80090D6C: beq         $t3, $t4, L_80090D98
    if (ctx->r11 == ctx->r12) {
        // 0x80090D70: nop
    
            goto L_80090D98;
    }
    // 0x80090D70: nop

    // 0x80090D74: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80090D78: lw          $t5, -0x282C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X282C);
    // 0x80090D7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090D80: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80090D84: addiu       $t8, $t5, -0x2
    ctx->r24 = ADD32(ctx->r13, -0X2);
    // 0x80090D88: sh          $t6, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r14;
    // 0x80090D8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090D90: b           L_80090DB0
    // 0x80090D94: sw          $t8, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r24;
        goto L_80090DB0;
    // 0x80090D94: sw          $t8, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r24;
L_80090D98:
    // 0x80090D98: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80090D9C: lw          $t9, -0x282C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X282C);
    // 0x80090DA0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090DA4: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x80090DA8: nop

    // 0x80090DAC: sh          $t1, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r9;
L_80090DB0:
    // 0x80090DB0: jr          $ra
    // 0x80090DB4: nop

    return;
    // 0x80090DB4: nop

    // 0x80090DB8: jr          $ra
    // 0x80090DBC: nop

    return;
    // 0x80090DBC: nop

;}
RECOMP_FUNC void func_80017A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80017A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017A28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80017A2C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80017A30: jal         0x80016074
    // 0x80017A34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80017A34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x80017A38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80017A3C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A40: nop

    // 0x80017A44: bne         $t6, $zero, L_80017A54
    if (ctx->r14 != 0) {
        // 0x80017A48: nop
    
            goto L_80017A54;
    }
    // 0x80017A48: nop

    // 0x80017A4C: b           L_80017AEC
    // 0x80017A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80017AEC;
    // 0x80017A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017A54:
    // 0x80017A54: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A58: nop

    // 0x80017A5C: lw          $t8, 0x210($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X210);
    // 0x80017A60: lw          $t9, 0x20C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X20C);
    // 0x80017A64: nop

    // 0x80017A68: bne         $t8, $t9, L_80017A80
    if (ctx->r24 != ctx->r25) {
        // 0x80017A6C: nop
    
            goto L_80017A80;
    }
    // 0x80017A6C: nop

    // 0x80017A70: bne         $t9, $zero, L_80017A80
    if (ctx->r25 != 0) {
        // 0x80017A74: nop
    
            goto L_80017A80;
    }
    // 0x80017A74: nop

    // 0x80017A78: b           L_80017AEC
    // 0x80017A7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80017AEC;
    // 0x80017A7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017A80:
    // 0x80017A80: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A84: nop

    // 0x80017A88: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x80017A8C: nop

    // 0x80017A90: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80017A94: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x80017A98: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A9C: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x80017AA0: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x80017AA4: nop

    // 0x80017AA8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80017AAC: sw          $t5, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = ctx->r13;
    // 0x80017AB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017AB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80017AB8: nop

    // 0x80017ABC: swc1        $f4, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f4.u32l;
    // 0x80017AC0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80017AC4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80017AC8: nop

    // 0x80017ACC: swc1        $f6, 0x1EC($t7)
    MEM_W(0X1EC, ctx->r15) = ctx->f6.u32l;
    // 0x80017AD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80017AD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017AD8: sw          $t8, -0x5A50($at)
    MEM_W(-0X5A50, ctx->r1) = ctx->r24;
    // 0x80017ADC: b           L_80017AEC
    // 0x80017AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017AEC;
    // 0x80017AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017AE4: b           L_80017AEC
    // 0x80017AE8: nop

        goto L_80017AEC;
    // 0x80017AE8: nop

L_80017AEC:
    // 0x80017AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017AF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017AF4: jr          $ra
    // 0x80017AF8: nop

    return;
    // 0x80017AF8: nop

    // 0x80017AFC: nop

;}
RECOMP_FUNC void func_80066464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006646C: jal         0x80061348
    // 0x80066470: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066470: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066474: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066478: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006647C: beq         $v0, $zero, L_80066494
    if (ctx->r2 == 0) {
        // 0x80066480: nop
    
            goto L_80066494;
    }
    // 0x80066480: nop

    // 0x80066484: jal         0x80061348
    // 0x80066488: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066488: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006648C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066490: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066494:
    // 0x80066494: b           L_800664A4
    // 0x80066498: nop

        goto L_800664A4;
    // 0x80066498: nop

    // 0x8006649C: b           L_800664A4
    // 0x800664A0: nop

        goto L_800664A4;
    // 0x800664A0: nop

L_800664A4:
    // 0x800664A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800664A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800664AC: jr          $ra
    // 0x800664B0: nop

    return;
    // 0x800664B0: nop

;}
RECOMP_FUNC void func_80057960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057968: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8005796C: lw          $t6, 0x480($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X480);
    // 0x80057970: nop

    // 0x80057974: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80057978: jal         0x8005A578
    // 0x8005797C: nop

    func_8005A578(rdram, ctx);
        goto after_0;
    // 0x8005797C: nop

    after_0:
    // 0x80057980: beq         $v0, $zero, L_80057A98
    if (ctx->r2 == 0) {
        // 0x80057984: nop
    
            goto L_80057A98;
    }
    // 0x80057984: nop

    // 0x80057988: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005798C: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80057990: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057994: beq         $t7, $at, L_80057A98
    if (ctx->r15 == ctx->r1) {
        // 0x80057998: nop
    
            goto L_80057A98;
    }
    // 0x80057998: nop

    // 0x8005799C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800579A0: lh          $t8, 0x6C0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X6C0);
    // 0x800579A4: nop

    // 0x800579A8: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800579AC: beq         $at, $zero, L_80057A98
    if (ctx->r1 == 0) {
        // 0x800579B0: nop
    
            goto L_80057A98;
    }
    // 0x800579B0: nop

    // 0x800579B4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800579B8: nop

    // 0x800579BC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800579C0: nop

    // 0x800579C4: bne         $t0, $zero, L_800579FC
    if (ctx->r8 != 0) {
        // 0x800579C8: nop
    
            goto L_800579FC;
    }
    // 0x800579C8: nop

    // 0x800579CC: lh          $t1, 0x2($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X2);
    // 0x800579D0: nop

    // 0x800579D4: bne         $t1, $zero, L_800579FC
    if (ctx->r9 != 0) {
        // 0x800579D8: nop
    
            goto L_800579FC;
    }
    // 0x800579D8: nop

    // 0x800579DC: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x800579E0: nop

    // 0x800579E4: bne         $t2, $zero, L_800579FC
    if (ctx->r10 != 0) {
        // 0x800579E8: nop
    
            goto L_800579FC;
    }
    // 0x800579E8: nop

    // 0x800579EC: lh          $t3, 0x6($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X6);
    // 0x800579F0: nop

    // 0x800579F4: beq         $t3, $zero, L_80057A58
    if (ctx->r11 == 0) {
        // 0x800579F8: nop
    
            goto L_80057A58;
    }
    // 0x800579F8: nop

L_800579FC:
    // 0x800579FC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80057A00: addiu       $at, $zero, 0x694
    ctx->r1 = ADD32(0, 0X694);
    // 0x80057A04: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80057A08: nop

    // 0x80057A0C: bne         $t5, $at, L_80057A4C
    if (ctx->r13 != ctx->r1) {
        // 0x80057A10: nop
    
            goto L_80057A4C;
    }
    // 0x80057A10: nop

    // 0x80057A14: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80057A18: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80057A1C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80057A20: nop

    // 0x80057A24: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80057A28: beq         $t8, $zero, L_80057A4C
    if (ctx->r24 == 0) {
        // 0x80057A2C: nop
    
            goto L_80057A4C;
    }
    // 0x80057A2C: nop

    // 0x80057A30: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80057A34: nop

    // 0x80057A38: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x80057A3C: b           L_80057AA8
    // 0x80057A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80057AA8;
    // 0x80057A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057A44: b           L_80057A58
    // 0x80057A48: nop

        goto L_80057A58;
    // 0x80057A48: nop

L_80057A4C:
    // 0x80057A4C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80057A50: b           L_80057AA8
    // 0x80057A54: nop

        goto L_80057AA8;
    // 0x80057A54: nop

L_80057A58:
    // 0x80057A58: jal         0x8005A7C0
    // 0x80057A5C: nop

    func_8005A7C0(rdram, ctx);
        goto after_1;
    // 0x80057A5C: nop

    after_1:
    // 0x80057A60: beq         $v0, $zero, L_80057A98
    if (ctx->r2 == 0) {
        // 0x80057A64: nop
    
            goto L_80057A98;
    }
    // 0x80057A64: nop

    // 0x80057A68: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80057A6C: lw          $t2, 0x480($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X480);
    // 0x80057A70: addiu       $t1, $zero, 0x6DD
    ctx->r9 = ADD32(0, 0X6DD);
    // 0x80057A74: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80057A78: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80057A7C: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80057A80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80057A84: sh          $t9, 0x4E($t3)
    MEM_H(0X4E, ctx->r11) = ctx->r25;
    // 0x80057A88: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80057A8C: lw          $v0, 0x480($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X480);
    // 0x80057A90: b           L_80057AA8
    // 0x80057A94: nop

        goto L_80057AA8;
    // 0x80057A94: nop

L_80057A98:
    // 0x80057A98: b           L_80057AA8
    // 0x80057A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80057AA8;
    // 0x80057A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057AA0: b           L_80057AA8
    // 0x80057AA4: nop

        goto L_80057AA8;
    // 0x80057AA4: nop

L_80057AA8:
    // 0x80057AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057AAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057AB0: jr          $ra
    // 0x80057AB4: nop

    return;
    // 0x80057AB4: nop

;}
RECOMP_FUNC void func_8001C2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C2B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C2B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001C2BC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C2C0: nop

    // 0x8001C2C4: bltz        $t6, L_8001C500
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001C2C8: nop
    
            goto L_8001C500;
    }
    // 0x8001C2C8: nop

    // 0x8001C2CC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C2D0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C2D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C2D8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001C2DC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C2E0: nop

    // 0x8001C2E4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C2E8: beq         $t0, $zero, L_8001C304
    if (ctx->r8 == 0) {
        // 0x8001C2EC: nop
    
            goto L_8001C304;
    }
    // 0x8001C2EC: nop

    // 0x8001C2F0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8001C2F4: lh          $t1, 0x7320($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7320);
    // 0x8001C2F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C2FC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001C300: sh          $t2, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r10;
L_8001C304:
    // 0x8001C304: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C308: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C30C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C310: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001C314: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001C318: nop

    // 0x8001C31C: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C320: beq         $t6, $zero, L_8001C33C
    if (ctx->r14 == 0) {
        // 0x8001C324: nop
    
            goto L_8001C33C;
    }
    // 0x8001C324: nop

    // 0x8001C328: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8001C32C: lh          $t7, 0x7320($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7320);
    // 0x8001C330: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C334: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001C338: sh          $t8, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r24;
L_8001C33C:
    // 0x8001C33C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001C340: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001C344: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C348: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001C34C: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001C350: nop

    // 0x8001C354: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001C358: beq         $t2, $zero, L_8001C374
    if (ctx->r10 == 0) {
        // 0x8001C35C: nop
    
            goto L_8001C374;
    }
    // 0x8001C35C: nop

    // 0x8001C360: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001C364: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x8001C368: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C36C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8001C370: sh          $t4, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r12;
L_8001C374:
    // 0x8001C374: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001C378: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001C37C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001C380: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001C384: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001C388: nop

    // 0x8001C38C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001C390: beq         $t8, $zero, L_8001C3AC
    if (ctx->r24 == 0) {
        // 0x8001C394: nop
    
            goto L_8001C3AC;
    }
    // 0x8001C394: nop

    // 0x8001C398: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8001C39C: lh          $t9, 0x7338($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7338);
    // 0x8001C3A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C3A4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8001C3A8: sh          $t0, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r8;
L_8001C3AC:
    // 0x8001C3AC: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001C3B0: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001C3B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001C3B8: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001C3BC: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001C3C0: nop

    // 0x8001C3C4: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001C3C8: beq         $t4, $zero, L_8001C3E4
    if (ctx->r12 == 0) {
        // 0x8001C3CC: nop
    
            goto L_8001C3E4;
    }
    // 0x8001C3CC: nop

    // 0x8001C3D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8001C3D4: lh          $t5, 0x7338($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7338);
    // 0x8001C3D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C3DC: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x8001C3E0: sh          $t6, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r14;
L_8001C3E4:
    // 0x8001C3E4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C3E8: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C3EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C3F0: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001C3F4: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C3F8: nop

    // 0x8001C3FC: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C400: beq         $t0, $zero, L_8001C41C
    if (ctx->r8 == 0) {
        // 0x8001C404: nop
    
            goto L_8001C41C;
    }
    // 0x8001C404: nop

    // 0x8001C408: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8001C40C: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x8001C410: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C414: addiu       $t2, $t1, -0xA
    ctx->r10 = ADD32(ctx->r9, -0XA);
    // 0x8001C418: sh          $t2, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r10;
L_8001C41C:
    // 0x8001C41C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C420: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C424: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C428: lhu         $t5, 0x10F2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X10F2);
    // 0x8001C42C: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8001C430: nop

    // 0x8001C434: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C438: beq         $t6, $zero, L_8001C450
    if (ctx->r14 == 0) {
        // 0x8001C43C: nop
    
            goto L_8001C450;
    }
    // 0x8001C43C: nop

    // 0x8001C440: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C444: sh          $zero, 0x7248($at)
    MEM_H(0X7248, ctx->r1) = 0;
    // 0x8001C448: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C44C: sh          $zero, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = 0;
L_8001C450:
    // 0x8001C450: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C454: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C458: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C45C: lhu         $t9, 0xEC0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEC0);
    // 0x8001C460: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8001C464: nop

    // 0x8001C468: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C46C: beq         $t0, $zero, L_8001C48C
    if (ctx->r8 == 0) {
        // 0x8001C470: nop
    
            goto L_8001C48C;
    }
    // 0x8001C470: nop

    // 0x8001C474: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8001C478: lw          $t1, 0x72DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72DC);
    // 0x8001C47C: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8001C480: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8001C484: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C488: sw          $t2, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r10;
L_8001C48C:
    // 0x8001C48C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C490: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C494: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C498: lhu         $t5, 0xEEC($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEEC);
    // 0x8001C49C: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8001C4A0: nop

    // 0x8001C4A4: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C4A8: beq         $t6, $zero, L_8001C4C4
    if (ctx->r14 == 0) {
        // 0x8001C4AC: nop
    
            goto L_8001C4C4;
    }
    // 0x8001C4AC: nop

    // 0x8001C4B0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8001C4B4: lw          $t7, 0x72DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72DC);
    // 0x8001C4B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C4BC: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8001C4C0: sw          $t8, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r24;
L_8001C4C4:
    // 0x8001C4C4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001C4C8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001C4CC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C4D0: lhu         $t1, 0x1042($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1042);
    // 0x8001C4D4: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8001C4D8: nop

    // 0x8001C4DC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001C4E0: beq         $t2, $zero, L_8001C500
    if (ctx->r10 == 0) {
        // 0x8001C4E4: nop
    
            goto L_8001C500;
    }
    // 0x8001C4E4: nop

    // 0x8001C4E8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8001C4EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C4F0: sh          $t3, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r11;
    // 0x8001C4F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001C4F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C4FC: sh          $t4, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r12;
L_8001C500:
    // 0x8001C500: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001C504: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x8001C508: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8001C50C: nop

    // 0x8001C510: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8001C514: beq         $t7, $zero, L_8001C564
    if (ctx->r15 == 0) {
        // 0x8001C518: nop
    
            goto L_8001C564;
    }
    // 0x8001C518: nop

    // 0x8001C51C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8001C520: lh          $t8, 0x7320($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7320);
    // 0x8001C524: nop

    // 0x8001C528: bgtz        $t8, L_8001C53C
    if (SIGNED(ctx->r24) > 0) {
        // 0x8001C52C: nop
    
            goto L_8001C53C;
    }
    // 0x8001C52C: nop

    // 0x8001C530: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C534: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C538: sh          $t9, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r25;
L_8001C53C:
    // 0x8001C53C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8001C540: lh          $t0, 0x7338($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7338);
    // 0x8001C544: nop

    // 0x8001C548: bgtz        $t0, L_8001C55C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8001C54C: nop
    
            goto L_8001C55C;
    }
    // 0x8001C54C: nop

    // 0x8001C550: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001C554: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C558: sh          $t1, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r9;
L_8001C55C:
    // 0x8001C55C: b           L_8001C59C
    // 0x8001C560: nop

        goto L_8001C59C;
    // 0x8001C560: nop

L_8001C564:
    // 0x8001C564: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8001C568: lh          $t2, 0x7320($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7320);
    // 0x8001C56C: nop

    // 0x8001C570: bgtz        $t2, L_8001C580
    if (SIGNED(ctx->r10) > 0) {
        // 0x8001C574: nop
    
            goto L_8001C580;
    }
    // 0x8001C574: nop

    // 0x8001C578: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C57C: sh          $zero, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = 0;
L_8001C580:
    // 0x8001C580: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001C584: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x8001C588: nop

    // 0x8001C58C: bgtz        $t3, L_8001C59C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8001C590: nop
    
            goto L_8001C59C;
    }
    // 0x8001C590: nop

    // 0x8001C594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C598: sh          $zero, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = 0;
L_8001C59C:
    // 0x8001C59C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8001C5A0: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8001C5A4: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8001C5A8: lh          $a3, 0x7268($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7268);
    // 0x8001C5AC: lh          $a2, 0x7338($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7338);
    // 0x8001C5B0: lh          $a1, 0x7320($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7320);
    // 0x8001C5B4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C5B8: jal         0x8008ECE4
    // 0x8001C5BC: addiu       $a0, $a0, -0x2764
    ctx->r4 = ADD32(ctx->r4, -0X2764);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001C5BC: addiu       $a0, $a0, -0x2764
    ctx->r4 = ADD32(ctx->r4, -0X2764);
    after_0:
    // 0x8001C5C0: b           L_8001C5D0
    // 0x8001C5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001C5D0;
    // 0x8001C5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001C5C8: b           L_8001C5D0
    // 0x8001C5CC: nop

        goto L_8001C5D0;
    // 0x8001C5CC: nop

L_8001C5D0:
    // 0x8001C5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C5D8: jr          $ra
    // 0x8001C5DC: nop

    return;
    // 0x8001C5DC: nop

;}
RECOMP_FUNC void func_8006C4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C4B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C4B8: jal         0x8005F064
    // 0x8006C4BC: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C4BC: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_0:
    // 0x8006C4C0: b           L_8006C4D0
    // 0x8006C4C4: nop

        goto L_8006C4D0;
    // 0x8006C4C4: nop

    // 0x8006C4C8: b           L_8006C4D0
    // 0x8006C4CC: nop

        goto L_8006C4D0;
    // 0x8006C4CC: nop

L_8006C4D0:
    // 0x8006C4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C4D8: jr          $ra
    // 0x8006C4DC: nop

    return;
    // 0x8006C4DC: nop

;}
RECOMP_FUNC void func_8006DD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DD6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DD70: jal         0x80061348
    // 0x8006DD74: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DD74: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x8006DD78: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DD80: beq         $v0, $zero, L_8006DD98
    if (ctx->r2 == 0) {
        // 0x8006DD84: nop
    
            goto L_8006DD98;
    }
    // 0x8006DD84: nop

    // 0x8006DD88: jal         0x80061348
    // 0x8006DD8C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DD8C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_1:
    // 0x8006DD90: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DD98:
    // 0x8006DD98: b           L_8006DDA8
    // 0x8006DD9C: nop

        goto L_8006DDA8;
    // 0x8006DD9C: nop

    // 0x8006DDA0: b           L_8006DDA8
    // 0x8006DDA4: nop

        goto L_8006DDA8;
    // 0x8006DDA4: nop

L_8006DDA8:
    // 0x8006DDA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DDAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DDB0: jr          $ra
    // 0x8006DDB4: nop

    return;
    // 0x8006DDB4: nop

;}
RECOMP_FUNC void func_8008BFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BFF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008BFF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BFFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008C000: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008C004: addiu       $t6, $t6, 0x7AE8
    ctx->r14 = ADD32(ctx->r14, 0X7AE8);
    // 0x8008C008: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8008C00C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8008C010:
    // 0x8008C010: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008C014: nop

    // 0x8008C018: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008C01C: nop

    // 0x8008C020: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008C024: bne         $t9, $zero, L_8008C06C
    if (ctx->r25 != 0) {
        // 0x8008C028: nop
    
            goto L_8008C06C;
    }
    // 0x8008C028: nop

    // 0x8008C02C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8008C030: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8008C034: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008C038: lw          $t1, 0x138($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X138);
    // 0x8008C03C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8008C040: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008C044: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8008C048: addiu       $t6, $t5, 0xA0
    ctx->r14 = ADD32(ctx->r13, 0XA0);
    // 0x8008C04C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8008C050: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008C054: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008C058: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C05C: lw          $a1, 0x138($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X138);
    // 0x8008C060: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8008C064: jal         0x800BCFCC
    // 0x8008C068: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, 0X1E0);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8008C068: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, 0X1E0);
    after_0:
L_8008C06C:
    // 0x8008C06C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008C070: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008C074: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008C078: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8008C07C: addiu       $t2, $t0, 0x16
    ctx->r10 = ADD32(ctx->r8, 0X16);
    // 0x8008C080: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8008C084: bne         $at, $zero, L_8008C010
    if (ctx->r1 != 0) {
        // 0x8008C088: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8008C010;
    }
    // 0x8008C088: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8008C08C: b           L_8008C094
    // 0x8008C090: nop

        goto L_8008C094;
    // 0x8008C090: nop

L_8008C094:
    // 0x8008C094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008C09C: jr          $ra
    // 0x8008C0A0: nop

    return;
    // 0x8008C0A0: nop

;}
RECOMP_FUNC void _doModFunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D56D0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800D56D4: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800D56D8: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800D56DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D56E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D56E4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D56E8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800D56EC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D56F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D56F4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800D56F8: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800D56FC: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800D5700: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800D5704: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D5708: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800D570C: nop

    // 0x800D5710: bc1fl       L_800D5738
    if (!c1cs) {
        // 0x800D5714: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_800D5738;
    }
    goto skip_0;
    // 0x800D5714: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_0:
    // 0x800D5718: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800D571C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D5720: nop

    // 0x800D5724: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x800D5728: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800D572C: b           L_800D573C
    // 0x800D5730: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_800D573C;
    // 0x800D5730: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800D5734: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
L_800D5738:
    // 0x800D5738: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_800D573C:
    // 0x800D573C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800D5740: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D5744: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800D5748: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800D574C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D5750: bc1fl       L_800D5760
    if (!c1cs) {
        // 0x800D5754: cvt.d.s     $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
            goto L_800D5760;
    }
    goto skip_1;
    // 0x800D5754: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    skip_1:
    // 0x800D5758: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800D575C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
L_800D5760:
    // 0x800D5760: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800D5764: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x800D5768: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x800D576C: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800D5770: jr          $ra
    // 0x800D5774: nop

    return;
    // 0x800D5774: nop

;}
RECOMP_FUNC void MtxUtil_RotateX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C23E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C23EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C23F0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C23F4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C23F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C23FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2400: jal         0x800C1A84
    // 0x800C2404: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_0;
    // 0x800C2404: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    after_0:
    // 0x800C2408: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C240C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2410: lwc1        $f9, -0x1A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A0);
    // 0x800C2414: lwc1        $f8, -0x19C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X19C);
    // 0x800C2418: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C241C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800C2420: jal         0x800C3338
    // 0x800C2424: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_1;
    // 0x800C2424: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800C2428: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800C242C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C2430: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2434: lwc1        $f5, -0x198($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X198);
    // 0x800C2438: lwc1        $f4, -0x194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X194);
    // 0x800C243C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C2440: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C2444: jal         0x800C3070
    // 0x800C2448: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800C2448: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_2:
    // 0x800C244C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C2450: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2454: nop

    // 0x800C2458: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800C245C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C2460: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2464: addiu       $t6, $t6, 0xCF0
    ctx->r14 = ADD32(ctx->r14, 0XCF0);
    // 0x800C2468: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800C246C: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800C2470: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800C2474: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800C2478: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C247C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C2480: nop

    // 0x800C2484: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800C2488: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800C248C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800C2490: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800C2494: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800C2498: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C249C: lwc1        $f20, 0x0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C24A0: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C24A4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C24A8: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C24AC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C24B0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C24B4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800C24B8: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800C24BC: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C24C0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C24C4: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800C24C8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C24CC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C24D0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C24D4: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C24D8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C24DC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C24E0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C24E4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C24E8: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
    // 0x800C24EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C24F0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C24F4: lwc1        $f20, 0x4($t6)
    ctx->f20.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C24F8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C24FC: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2500: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800C2504: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2508: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C250C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C2510: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800C2514: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2518: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C251C: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x800C2520: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2524: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2528: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C252C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C2530: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2534: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2538: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C253C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C2540: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
    // 0x800C2544: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C2548: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C254C: lwc1        $f20, 0x8($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C2550: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2554: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2558: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800C255C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2560: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2564: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C2568: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C256C: mul.s       $f16, $f20, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2570: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C2574: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x800C2578: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C257C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2580: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2584: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2588: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C258C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2590: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C2594: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C2598: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x800C259C: b           L_800C25A4
    // 0x800C25A0: nop

        goto L_800C25A4;
    // 0x800C25A0: nop

L_800C25A4:
    // 0x800C25A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C25A8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C25AC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C25B0: jr          $ra
    // 0x800C25B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C25B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80015FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015FB4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80015FB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015FBC: bne         $a0, $at, L_80015FCC
    if (ctx->r4 != ctx->r1) {
        // 0x80015FC0: nop
    
            goto L_80015FCC;
    }
    // 0x80015FC0: nop

    // 0x80015FC4: b           L_8001606C
    // 0x80015FC8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001606C;
    // 0x80015FC8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015FCC:
    // 0x80015FCC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80015FD0:
    // 0x80015FD0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80015FD4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80015FD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80015FDC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80015FE0: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x80015FE4: nop

    // 0x80015FE8: beq         $t8, $zero, L_80016044
    if (ctx->r24 == 0) {
        // 0x80015FEC: nop
    
            goto L_80016044;
    }
    // 0x80015FEC: nop

    // 0x80015FF0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80015FF4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80015FF8: addiu       $t1, $t1, -0x4530
    ctx->r9 = ADD32(ctx->r9, -0X4530);
    // 0x80015FFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80016000: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80016004: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80016008: sw          $t2, -0x4538($at)
    MEM_W(-0X4538, ctx->r1) = ctx->r10;
    // 0x8001600C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80016010: lw          $t3, -0x4538($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4538);
    // 0x80016014: nop

    // 0x80016018: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001601C: nop

    // 0x80016020: lw          $t5, 0x1A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A4);
    // 0x80016024: nop

    // 0x80016028: bne         $t5, $a0, L_80016044
    if (ctx->r13 != ctx->r4) {
        // 0x8001602C: nop
    
            goto L_80016044;
    }
    // 0x8001602C: nop

    // 0x80016030: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80016034: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80016038: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001603C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80016040: sw          $zero, -0x4530($at)
    MEM_W(-0X4530, ctx->r1) = 0;
L_80016044:
    // 0x80016044: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80016048: nop

    // 0x8001604C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80016050: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80016054: bne         $at, $zero, L_80015FD0
    if (ctx->r1 != 0) {
        // 0x80016058: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_80015FD0;
    }
    // 0x80016058: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8001605C: b           L_8001606C
    // 0x80016060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001606C;
    // 0x80016060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016064: b           L_8001606C
    // 0x80016068: nop

        goto L_8001606C;
    // 0x80016068: nop

L_8001606C:
    // 0x8001606C: jr          $ra
    // 0x80016070: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80016070: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006D088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D088: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D08C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D090: nop

    // 0x8006D094: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D098: nop

    // 0x8006D09C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D0A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D0A4: jr          $ra
    // 0x8006D0A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D0A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D0AC: jr          $ra
    // 0x8006D0B0: nop

    return;
    // 0x8006D0B0: nop

    // 0x8006D0B4: jr          $ra
    // 0x8006D0B8: nop

    return;
    // 0x8006D0B8: nop

;}
RECOMP_FUNC void func_80072F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072F88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072F8C: nop

    // 0x80072F90: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072F94: nop

    // 0x80072F98: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072F9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072FA0: jr          $ra
    // 0x80072FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072FA8: jr          $ra
    // 0x80072FAC: nop

    return;
    // 0x80072FAC: nop

    // 0x80072FB0: jr          $ra
    // 0x80072FB4: nop

    return;
    // 0x80072FB4: nop

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
RECOMP_FUNC void func_80085ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80085AD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80085ADC: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80085AE0: jal         0x8008BFF4
    // 0x80085AE4: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x80085AE4: nop

    after_0:
    // 0x80085AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085AEC: jal         0x80089170
    // 0x80085AF0: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80085AF0: nop

    after_1:
    // 0x80085AF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80085AF8: nop

    // 0x80085AFC: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80085B00: b           L_80085B10
    // 0x80085B04: nop

        goto L_80085B10;
    // 0x80085B04: nop

    // 0x80085B08: b           L_80085B10
    // 0x80085B0C: nop

        goto L_80085B10;
    // 0x80085B0C: nop

L_80085B10:
    // 0x80085B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085B18: jr          $ra
    // 0x80085B1C: nop

    return;
    // 0x80085B1C: nop

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
RECOMP_FUNC void func_800020A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800020AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800020B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800020B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800020B8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800020BC: lw          $t6, -0x73CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73CC);
    // 0x800020C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800020C4: beq         $t6, $at, L_800020F8
    if (ctx->r14 == ctx->r1) {
        // 0x800020C8: nop
    
            goto L_800020F8;
    }
    // 0x800020C8: nop

    // 0x800020CC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800020D0: lw          $a0, -0x73CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73CC);
    // 0x800020D4: jal         0x80016074
    // 0x800020D8: nop

    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800020D8: nop

    after_0:
    // 0x800020DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800020E0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800020E4: nop

    // 0x800020E8: bne         $t7, $zero, L_800020F8
    if (ctx->r15 != 0) {
        // 0x800020EC: nop
    
            goto L_800020F8;
    }
    // 0x800020EC: nop

    // 0x800020F0: b           L_8000261C
    // 0x800020F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000261C;
    // 0x800020F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800020F8:
    // 0x800020F8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800020FC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80002100: lh          $t9, 0x7254($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7254);
    // 0x80002104: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80002108: nop

    // 0x8000210C: bne         $t8, $t9, L_8000214C
    if (ctx->r24 != ctx->r25) {
        // 0x80002110: nop
    
            goto L_8000214C;
    }
    // 0x80002110: nop

    // 0x80002114: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80002118: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8000211C: lh          $t1, 0x725C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X725C);
    // 0x80002120: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x80002124: nop

    // 0x80002128: bne         $t0, $t1, L_8000214C
    if (ctx->r8 != ctx->r9) {
        // 0x8000212C: nop
    
            goto L_8000214C;
    }
    // 0x8000212C: nop

    // 0x80002130: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80002134: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80002138: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000213C: nop

    // 0x80002140: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80002144: beq         $t4, $zero, L_8000260C
    if (ctx->r12 == 0) {
        // 0x80002148: nop
    
            goto L_8000260C;
    }
    // 0x80002148: nop

L_8000214C:
    // 0x8000214C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80002150: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80002154: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80002158: nop

    // 0x8000215C: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x80002160: bne         $t7, $zero, L_80002178
    if (ctx->r15 != 0) {
        // 0x80002164: nop
    
            goto L_80002178;
    }
    // 0x80002164: nop

    // 0x80002168: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000216C: nop

    // 0x80002170: bne         $t8, $zero, L_800021A8
    if (ctx->r24 != 0) {
        // 0x80002174: nop
    
            goto L_800021A8;
    }
    // 0x80002174: nop

L_80002178:
    // 0x80002178: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8000217C: lh          $t9, 0x7254($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7254);
    // 0x80002180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002184: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x80002188: sh          $t0, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r8;
    // 0x8000218C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80002190: lh          $t1, 0x725C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X725C);
    // 0x80002194: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002198: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x8000219C: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
    // 0x800021A0: b           L_8000261C
    // 0x800021A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x800021A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800021A8:
    // 0x800021A8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800021AC: nop

    // 0x800021B0: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x800021B4: nop

    // 0x800021B8: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800021BC: beq         $t5, $zero, L_8000225C
    if (ctx->r13 == 0) {
        // 0x800021C0: nop
    
            goto L_8000225C;
    }
    // 0x800021C0: nop

    // 0x800021C4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800021C8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800021CC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800021D0: nop

    // 0x800021D4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800021D8: bne         $t8, $zero, L_8000220C
    if (ctx->r24 != 0) {
        // 0x800021DC: nop
    
            goto L_8000220C;
    }
    // 0x800021DC: nop

    // 0x800021E0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800021E4: lh          $t9, 0x7254($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7254);
    // 0x800021E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800021EC: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x800021F0: sh          $t0, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r8;
    // 0x800021F4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800021F8: lh          $t1, 0x725C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X725C);
    // 0x800021FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002200: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x80002204: b           L_8000224C
    // 0x80002208: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
        goto L_8000224C;
    // 0x80002208: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
L_8000220C:
    // 0x8000220C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80002210: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80002214: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002218: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x8000221C: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
    // 0x80002220: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80002224: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80002228: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000222C: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x80002230: sh          $t6, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r14;
    // 0x80002234: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80002238: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000223C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80002240: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80002244: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80002248: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
L_8000224C:
    // 0x8000224C: b           L_8000261C
    // 0x80002250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x80002250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002254: b           L_8000260C
    // 0x80002258: nop

        goto L_8000260C;
    // 0x80002258: nop

L_8000225C:
    // 0x8000225C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80002260: nop

    // 0x80002264: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x80002268: nop

    // 0x8000226C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80002270: bne         $t2, $zero, L_8000260C
    if (ctx->r10 != 0) {
        // 0x80002274: nop
    
            goto L_8000260C;
    }
    // 0x80002274: nop

    // 0x80002278: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8000227C: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80002280: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002284: sh          $t3, 0x7274($at)
    MEM_H(0X7274, ctx->r1) = ctx->r11;
    // 0x80002288: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000228C: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x80002290: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002294: sh          $t4, 0x7280($at)
    MEM_H(0X7280, ctx->r1) = ctx->r12;
    // 0x80002298: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000229C: lh          $t5, 0x7248($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7248);
    // 0x800022A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800022A4: sh          $t5, 0x728C($at)
    MEM_H(0X728C, ctx->r1) = ctx->r13;
    // 0x800022A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800022AC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800022B0: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x800022B4: nop

    // 0x800022B8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800022BC: beq         $t9, $zero, L_800022E4
    if (ctx->r25 == 0) {
        // 0x800022C0: nop
    
            goto L_800022E4;
    }
    // 0x800022C0: nop

    // 0x800022C4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800022C8: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800022CC: lhu         $t0, 0x6($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X6);
    // 0x800022D0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800022D4: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800022D8: sh          $t1, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r9;
    // 0x800022DC: jal         0x80021F20
    // 0x800022E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_1;
    // 0x800022E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
L_800022E4:
    // 0x800022E4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800022E8: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x800022EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800022F0: andi        $t3, $t2, 0x7FFF
    ctx->r11 = ctx->r10 & 0X7FFF;
    // 0x800022F4: bne         $t3, $at, L_80002364
    if (ctx->r11 != ctx->r1) {
        // 0x800022F8: nop
    
            goto L_80002364;
    }
    // 0x800022F8: nop

    // 0x800022FC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80002300: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x80002304: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80002308: andi        $t5, $t4, 0x7FFF
    ctx->r13 = ctx->r12 & 0X7FFF;
    // 0x8000230C: bne         $t5, $at, L_80002364
    if (ctx->r13 != ctx->r1) {
        // 0x80002310: nop
    
            goto L_80002364;
    }
    // 0x80002310: nop

    // 0x80002314: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80002318: lh          $t6, 0x7254($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7254);
    // 0x8000231C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002320: andi        $t8, $t6, 0x7FFF
    ctx->r24 = ctx->r14 & 0X7FFF;
    // 0x80002324: bne         $t8, $at, L_80002364
    if (ctx->r24 != ctx->r1) {
        // 0x80002328: nop
    
            goto L_80002364;
    }
    // 0x80002328: nop

    // 0x8000232C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80002330: lh          $t9, 0x725C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X725C);
    // 0x80002334: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002338: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x8000233C: bne         $t0, $at, L_80002364
    if (ctx->r8 != ctx->r1) {
        // 0x80002340: nop
    
            goto L_80002364;
    }
    // 0x80002340: nop

    // 0x80002344: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80002348: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000234C: lhu         $t7, 0x6($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X6);
    // 0x80002350: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80002354: and         $t2, $t7, $at
    ctx->r10 = ctx->r15 & ctx->r1;
    // 0x80002358: sh          $t2, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r10;
    // 0x8000235C: jal         0x80021F20
    // 0x80002360: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_2;
    // 0x80002360: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_2:
L_80002364:
    // 0x80002364: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80002368: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8000236C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002370: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x80002374: bne         $t4, $at, L_800023E4
    if (ctx->r12 != ctx->r1) {
        // 0x80002378: nop
    
            goto L_800023E4;
    }
    // 0x80002378: nop

    // 0x8000237C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80002380: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80002384: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002388: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x8000238C: bne         $t6, $at, L_800023E4
    if (ctx->r14 != ctx->r1) {
        // 0x80002390: nop
    
            goto L_800023E4;
    }
    // 0x80002390: nop

    // 0x80002394: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80002398: lh          $t8, 0x7254($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7254);
    // 0x8000239C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800023A0: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800023A4: bne         $t9, $at, L_800023E4
    if (ctx->r25 != ctx->r1) {
        // 0x800023A8: nop
    
            goto L_800023E4;
    }
    // 0x800023A8: nop

    // 0x800023AC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800023B0: lh          $t0, 0x725C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X725C);
    // 0x800023B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800023B8: andi        $t7, $t0, 0x7FFF
    ctx->r15 = ctx->r8 & 0X7FFF;
    // 0x800023BC: bne         $t7, $at, L_800023E4
    if (ctx->r15 != ctx->r1) {
        // 0x800023C0: nop
    
            goto L_800023E4;
    }
    // 0x800023C0: nop

    // 0x800023C4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800023C8: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800023CC: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x800023D0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800023D4: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800023D8: sh          $t3, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r11;
    // 0x800023DC: jal         0x80021F20
    // 0x800023E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_3;
    // 0x800023E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
L_800023E4:
    // 0x800023E4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800023E8: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x800023EC: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800023F0: nop

    // 0x800023F4: andi        $t6, $t5, 0x800
    ctx->r14 = ctx->r13 & 0X800;
    // 0x800023F8: beq         $t6, $zero, L_80002424
    if (ctx->r14 == 0) {
        // 0x800023FC: nop
    
            goto L_80002424;
    }
    // 0x800023FC: nop

    // 0x80002400: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80002404: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80002408: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x8000240C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80002410: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80002414: sh          $t0, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r8;
    // 0x80002418: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8000241C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80002420: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
L_80002424:
    // 0x80002424: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80002428: lw          $t1, -0x73CC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73CC);
    // 0x8000242C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80002430: bne         $t1, $at, L_80002510
    if (ctx->r9 != ctx->r1) {
        // 0x80002434: nop
    
            goto L_80002510;
    }
    // 0x80002434: nop

    // 0x80002438: b           L_80002440
    // 0x8000243C: nop

        goto L_80002440;
    // 0x8000243C: nop

L_80002440:
    // 0x80002440: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80002444: lwc1        $f4, -0x4508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x80002448: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000244C: nop

    // 0x80002450: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80002454: nop

    // 0x80002458: bc1f        L_80002474
    if (!c1cs) {
        // 0x8000245C: nop
    
            goto L_80002474;
    }
    // 0x8000245C: nop

    // 0x80002460: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80002464: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80002468: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000246C: b           L_800024DC
    // 0x80002470: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
        goto L_800024DC;
    // 0x80002470: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
L_80002474:
    // 0x80002474: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80002478: lwc1        $f10, -0x4508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x8000247C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80002480: nop

    // 0x80002484: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80002488: nop

    // 0x8000248C: bc1f        L_800024DC
    if (!c1cs) {
        // 0x80002490: nop
    
            goto L_800024DC;
    }
    // 0x80002490: nop

    // 0x80002494: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80002498: lwc1        $f18, -0x4508($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x8000249C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800024A0: nop

    // 0x800024A4: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800024A8: nop

    // 0x800024AC: bc1f        L_800024C4
    if (!c1cs) {
        // 0x800024B0: nop
    
            goto L_800024C4;
    }
    // 0x800024B0: nop

    // 0x800024B4: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x800024B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800024BC: b           L_800024DC
    // 0x800024C0: swc1        $f6, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f6.u32l;
        goto L_800024DC;
    // 0x800024C0: swc1        $f6, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f6.u32l;
L_800024C4:
    // 0x800024C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800024C8: lwc1        $f8, -0x4508($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800024CC: nop

    // 0x800024D0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800024D4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800024D8: swc1        $f16, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f16.u32l;
L_800024DC:
    // 0x800024DC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800024E0: jal         0x80016620
    // 0x800024E4: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    func_80016620(rdram, ctx);
        goto after_4;
    // 0x800024E4: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    after_4:
    // 0x800024E8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800024EC: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x800024F0: lhu         $t2, 0x0($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X0);
    // 0x800024F4: nop

    // 0x800024F8: ori         $t4, $t2, 0x400
    ctx->r12 = ctx->r10 | 0X400;
    // 0x800024FC: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
    // 0x80002500: b           L_8000261C
    // 0x80002504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000261C;
    // 0x80002504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002508: b           L_8000260C
    // 0x8000250C: nop

        goto L_8000260C;
    // 0x8000250C: nop

L_80002510:
    // 0x80002510: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80002514: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80002518: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8000251C: nop

    // 0x80002520: andi        $t9, $t6, 0x80
    ctx->r25 = ctx->r14 & 0X80;
    // 0x80002524: beq         $t9, $zero, L_8000255C
    if (ctx->r25 == 0) {
        // 0x80002528: nop
    
            goto L_8000255C;
    }
    // 0x80002528: nop

    // 0x8000252C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80002530: lh          $t0, 0x7254($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7254);
    // 0x80002534: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002538: andi        $t8, $t0, 0x7FFF
    ctx->r24 = ctx->r8 & 0X7FFF;
    // 0x8000253C: sh          $t8, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r24;
    // 0x80002540: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80002544: lh          $t7, 0x725C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X725C);
    // 0x80002548: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000254C: andi        $t1, $t7, 0x7FFF
    ctx->r9 = ctx->r15 & 0X7FFF;
    // 0x80002550: sh          $t1, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r9;
    // 0x80002554: b           L_8000261C
    // 0x80002558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x80002558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000255C:
    // 0x8000255C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80002560: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80002564: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x80002568: nop

    // 0x8000256C: andi        $t3, $t4, 0x10
    ctx->r11 = ctx->r12 & 0X10;
    // 0x80002570: bne         $t3, $zero, L_800025A4
    if (ctx->r11 != 0) {
        // 0x80002574: nop
    
            goto L_800025A4;
    }
    // 0x80002574: nop

    // 0x80002578: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000257C: lh          $t5, 0x7254($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7254);
    // 0x80002580: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002584: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x80002588: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
    // 0x8000258C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80002590: lh          $t9, 0x725C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X725C);
    // 0x80002594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002598: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x8000259C: b           L_800025E4
    // 0x800025A0: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
        goto L_800025E4;
    // 0x800025A0: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
L_800025A4:
    // 0x800025A4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800025A8: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800025AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800025B0: andi        $t7, $t8, 0x7FFF
    ctx->r15 = ctx->r24 & 0X7FFF;
    // 0x800025B4: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x800025B8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800025BC: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x800025C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800025C4: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x800025C8: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
    // 0x800025CC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800025D0: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x800025D4: lhu         $t3, 0x0($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X0);
    // 0x800025D8: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800025DC: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800025E0: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
L_800025E4:
    // 0x800025E4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800025E8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800025EC: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x800025F0: nop

    // 0x800025F4: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x800025F8: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
    // 0x800025FC: b           L_8000261C
    // 0x80002600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x80002600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002604: b           L_8000260C
    // 0x80002608: nop

        goto L_8000260C;
    // 0x80002608: nop

L_8000260C:
    // 0x8000260C: b           L_8000261C
    // 0x80002610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000261C;
    // 0x80002610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002614: b           L_8000261C
    // 0x80002618: nop

        goto L_8000261C;
    // 0x80002618: nop

L_8000261C:
    // 0x8000261C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002620: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002624: jr          $ra
    // 0x80002628: nop

    return;
    // 0x80002628: nop

;}
