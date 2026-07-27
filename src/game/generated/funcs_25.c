#include "recomp.h"
#include "funcs.h"

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
RECOMP_FUNC void func_8006F044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F04C: jal         0x80061348
    // 0x8006F050: addiu       $a0, $zero, 0x2B1
    ctx->r4 = ADD32(0, 0X2B1);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F050: addiu       $a0, $zero, 0x2B1
    ctx->r4 = ADD32(0, 0X2B1);
    after_0:
    // 0x8006F054: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F058: b           L_8006F068
    // 0x8006F05C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F068;
    // 0x8006F05C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F060: b           L_8006F068
    // 0x8006F064: nop

        goto L_8006F068;
    // 0x8006F064: nop

L_8006F068:
    // 0x8006F068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F06C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F070: jr          $ra
    // 0x8006F074: nop

    return;
    // 0x8006F074: nop

;}
RECOMP_FUNC void func_800A57C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A57C4: slti        $at, $a0, 0x3E8
    ctx->r1 = SIGNED(ctx->r4) < 0X3E8 ? 1 : 0;
    // 0x800A57C8: bne         $at, $zero, L_800A57D4
    if (ctx->r1 != 0) {
        // 0x800A57CC: nop
    
            goto L_800A57D4;
    }
    // 0x800A57CC: nop

    // 0x800A57D0: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
L_800A57D4:
    // 0x800A57D4: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
    // 0x800A57D8: bne         $at, $zero, L_800A57E4
    if (ctx->r1 != 0) {
        // 0x800A57DC: nop
    
            goto L_800A57E4;
    }
    // 0x800A57DC: nop

    // 0x800A57E0: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
L_800A57E4:
    // 0x800A57E4: bne         $a0, $a1, L_800A57F0
    if (ctx->r4 != ctx->r5) {
        // 0x800A57E8: nop
    
            goto L_800A57F0;
    }
    // 0x800A57E8: nop

    // 0x800A57EC: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
L_800A57F0:
    // 0x800A57F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A57F4: sw          $a0, -0x71E8($at)
    MEM_W(-0X71E8, ctx->r1) = ctx->r4;
    // 0x800A57F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A57FC: sw          $a1, -0x71E4($at)
    MEM_W(-0X71E4, ctx->r1) = ctx->r5;
    // 0x800A5800: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5804: sw          $a2, -0x71E0($at)
    MEM_W(-0X71E0, ctx->r1) = ctx->r6;
    // 0x800A5808: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A580C: sw          $a3, -0x71DC($at)
    MEM_W(-0X71DC, ctx->r1) = ctx->r7;
    // 0x800A5810: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800A5814: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5818: sw          $t6, -0x71D8($at)
    MEM_W(-0X71D8, ctx->r1) = ctx->r14;
    // 0x800A581C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800A5820: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5824: sw          $t7, -0x71D4($at)
    MEM_W(-0X71D4, ctx->r1) = ctx->r15;
    // 0x800A5828: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A582C: lw          $t8, -0x71D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X71D0);
    // 0x800A5830: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5834: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x800A5838: sw          $t9, -0x71D0($at)
    MEM_W(-0X71D0, ctx->r1) = ctx->r25;
    // 0x800A583C: jr          $ra
    // 0x800A5840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A5840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80066C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066C24: jal         0x80061348
    // 0x80066C28: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066C28: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    after_0:
    // 0x80066C2C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066C30: b           L_80066C40
    // 0x80066C34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066C40;
    // 0x80066C34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066C38: b           L_80066C40
    // 0x80066C3C: nop

        goto L_80066C40;
    // 0x80066C3C: nop

L_80066C40:
    // 0x80066C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066C48: jr          $ra
    // 0x80066C4C: nop

    return;
    // 0x80066C4C: nop

;}
RECOMP_FUNC void func_80056D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056D28: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80056D2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056D30: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056D34: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80056D38: addiu       $t6, $t6, 0x2C4C
    ctx->r14 = ADD32(ctx->r14, 0X2C4C);
    // 0x80056D3C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80056D40: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056D44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056D48: beq         $t7, $at, L_80056DDC
    if (ctx->r15 == ctx->r1) {
        // 0x80056D4C: nop
    
            goto L_80056DDC;
    }
    // 0x80056D4C: nop

L_80056D50:
    // 0x80056D50: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x80056D54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056D58: addiu       $t0, $t0, 0x2C4C
    ctx->r8 = ADD32(ctx->r8, 0X2C4C);
    // 0x80056D5C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80056D60: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80056D64: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80056D68: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80056D6C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80056D70: nop

    // 0x80056D74: bne         $t2, $t3, L_80056DB0
    if (ctx->r10 != ctx->r11) {
        // 0x80056D78: nop
    
            goto L_80056DB0;
    }
    // 0x80056D78: nop

    // 0x80056D7C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80056D80: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80056D84: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80056D88: nop

    // 0x80056D8C: bne         $t4, $t5, L_80056DB0
    if (ctx->r12 != ctx->r13) {
        // 0x80056D90: nop
    
            goto L_80056DB0;
    }
    // 0x80056D90: nop

    // 0x80056D94: lh          $t6, 0x4($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X4);
    // 0x80056D98: nop

    // 0x80056D9C: bne         $t6, $a0, L_80056DB0
    if (ctx->r14 != ctx->r4) {
        // 0x80056DA0: nop
    
            goto L_80056DB0;
    }
    // 0x80056DA0: nop

    // 0x80056DA4: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x80056DA8: b           L_80056DEC
    // 0x80056DAC: nop

        goto L_80056DEC;
    // 0x80056DAC: nop

L_80056DB0:
    // 0x80056DB0: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x80056DB4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80056DB8: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x80056DBC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80056DC0: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80056DC4: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80056DC8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80056DCC: lh          $t3, 0x2C4C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2C4C);
    // 0x80056DD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056DD4: bne         $t3, $at, L_80056D50
    if (ctx->r11 != ctx->r1) {
        // 0x80056DD8: sh          $t8, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r24;
            goto L_80056D50;
    }
    // 0x80056DD8: sh          $t8, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r24;
L_80056DDC:
    // 0x80056DDC: b           L_80056DEC
    // 0x80056DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80056DEC;
    // 0x80056DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056DE4: b           L_80056DEC
    // 0x80056DE8: nop

        goto L_80056DEC;
    // 0x80056DE8: nop

L_80056DEC:
    // 0x80056DEC: jr          $ra
    // 0x80056DF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056DF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80070550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070558: jal         0x80061348
    // 0x8007055C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007055C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070560: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070564: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070568: beq         $v0, $zero, L_800705B8
    if (ctx->r2 == 0) {
        // 0x8007056C: nop
    
            goto L_800705B8;
    }
    // 0x8007056C: nop

    // 0x80070570: jal         0x80061348
    // 0x80070574: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070574: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070578: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007057C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070580: beq         $v0, $zero, L_800705B8
    if (ctx->r2 == 0) {
        // 0x80070584: nop
    
            goto L_800705B8;
    }
    // 0x80070584: nop

    // 0x80070588: jal         0x80061348
    // 0x8007058C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007058C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070590: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070594: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070598: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007059C: beq         $v0, $zero, L_800705B8
    if (ctx->r2 == 0) {
        // 0x800705A0: nop
    
            goto L_800705B8;
    }
    // 0x800705A0: nop

    // 0x800705A4: jal         0x80061348
    // 0x800705A8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800705A8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800705AC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800705B0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800705B4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800705B8:
    // 0x800705B8: b           L_800705C8
    // 0x800705BC: nop

        goto L_800705C8;
    // 0x800705BC: nop

    // 0x800705C0: b           L_800705C8
    // 0x800705C4: nop

        goto L_800705C8;
    // 0x800705C4: nop

L_800705C8:
    // 0x800705C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800705CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800705D0: jr          $ra
    // 0x800705D4: nop

    return;
    // 0x800705D4: nop

;}
RECOMP_FUNC void func_80068B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068B78: jal         0x80061348
    // 0x80068B7C: addiu       $a0, $zero, 0x707
    ctx->r4 = ADD32(0, 0X707);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80068B7C: addiu       $a0, $zero, 0x707
    ctx->r4 = ADD32(0, 0X707);
    after_0:
    // 0x80068B80: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80068B84: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80068B88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068B8C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80068B90: beq         $v0, $zero, L_80068BB0
    if (ctx->r2 == 0) {
        // 0x80068B94: nop
    
            goto L_80068BB0;
    }
    // 0x80068B94: nop

    // 0x80068B98: jal         0x80061348
    // 0x80068B9C: addiu       $a0, $zero, 0x70B
    ctx->r4 = ADD32(0, 0X70B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80068B9C: addiu       $a0, $zero, 0x70B
    ctx->r4 = ADD32(0, 0X70B);
    after_1:
    // 0x80068BA0: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x80068BA4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80068BA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068BAC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80068BB0:
    // 0x80068BB0: b           L_80068BC0
    // 0x80068BB4: nop

        goto L_80068BC0;
    // 0x80068BB4: nop

    // 0x80068BB8: b           L_80068BC0
    // 0x80068BBC: nop

        goto L_80068BC0;
    // 0x80068BBC: nop

L_80068BC0:
    // 0x80068BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068BC8: jr          $ra
    // 0x80068BCC: nop

    return;
    // 0x80068BCC: nop

;}
RECOMP_FUNC void func_80076DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076DC0: jal         0x80061488
    // 0x80076DC4: addiu       $a0, $zero, 0x54F
    ctx->r4 = ADD32(0, 0X54F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076DC4: addiu       $a0, $zero, 0x54F
    ctx->r4 = ADD32(0, 0X54F);
    after_0:
    // 0x80076DC8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076DCC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076DD0: b           L_80076DE0
    // 0x80076DD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076DE0;
    // 0x80076DD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076DD8: b           L_80076DE0
    // 0x80076DDC: nop

        goto L_80076DE0;
    // 0x80076DDC: nop

L_80076DE0:
    // 0x80076DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076DE8: jr          $ra
    // 0x80076DEC: nop

    return;
    // 0x80076DEC: nop

;}
RECOMP_FUNC void func_80061E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E14: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061E18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061E1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80061E20: nop

    // 0x80061E24: lh          $t7, 0x30($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X30);
    // 0x80061E28: nop

    // 0x80061E2C: slti        $at, $t7, 0x2BC
    ctx->r1 = SIGNED(ctx->r15) < 0X2BC ? 1 : 0;
    // 0x80061E30: beq         $at, $zero, L_80061E74
    if (ctx->r1 == 0) {
        // 0x80061E34: nop
    
            goto L_80061E74;
    }
    // 0x80061E34: nop

    // 0x80061E38: lh          $t8, 0x32($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X32);
    // 0x80061E3C: nop

    // 0x80061E40: slti        $at, $t8, 0x2BC
    ctx->r1 = SIGNED(ctx->r24) < 0X2BC ? 1 : 0;
    // 0x80061E44: beq         $at, $zero, L_80061E74
    if (ctx->r1 == 0) {
        // 0x80061E48: nop
    
            goto L_80061E74;
    }
    // 0x80061E48: nop

    // 0x80061E4C: lh          $t9, 0x34($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X34);
    // 0x80061E50: nop

    // 0x80061E54: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x80061E58: beq         $at, $zero, L_80061E74
    if (ctx->r1 == 0) {
        // 0x80061E5C: nop
    
            goto L_80061E74;
    }
    // 0x80061E5C: nop

    // 0x80061E60: lh          $t0, 0x36($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X36);
    // 0x80061E64: nop

    // 0x80061E68: slti        $at, $t0, 0x2BC
    ctx->r1 = SIGNED(ctx->r8) < 0X2BC ? 1 : 0;
    // 0x80061E6C: bne         $at, $zero, L_80061EF0
    if (ctx->r1 != 0) {
        // 0x80061E70: nop
    
            goto L_80061EF0;
    }
    // 0x80061E70: nop

L_80061E74:
    // 0x80061E74: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80061E78: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80061E7C: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80061E80: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_80061E84:
    // 0x80061E84: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061E88: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061E8C: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80061E90: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80061E94: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80061E98: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80061E9C: addu        $t0, $t3, $t6
    ctx->r8 = ADD32(ctx->r11, ctx->r14);
    // 0x80061EA0: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80061EA4: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061EA8: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80061EAC: nop

    // 0x80061EB0: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061EB4: beq         $at, $zero, L_80061ECC
    if (ctx->r1 == 0) {
        // 0x80061EB8: nop
    
            goto L_80061ECC;
    }
    // 0x80061EB8: nop

    // 0x80061EBC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061EC0: nop

    // 0x80061EC4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80061EC8: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
L_80061ECC:
    // 0x80061ECC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80061ED0: nop

    // 0x80061ED4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80061ED8: slti        $at, $t7, 0x1B
    ctx->r1 = SIGNED(ctx->r15) < 0X1B ? 1 : 0;
    // 0x80061EDC: bne         $at, $zero, L_80061E84
    if (ctx->r1 != 0) {
        // 0x80061EE0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80061E84;
    }
    // 0x80061EE0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80061EE4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80061EE8: b           L_80061F00
    // 0x80061EEC: nop

        goto L_80061F00;
    // 0x80061EEC: nop

L_80061EF0:
    // 0x80061EF0: b           L_80061F00
    // 0x80061EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061F00;
    // 0x80061EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061EF8: b           L_80061F00
    // 0x80061EFC: nop

        goto L_80061F00;
    // 0x80061EFC: nop

L_80061F00:
    // 0x80061F00: jr          $ra
    // 0x80061F04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80061F04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8004F3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F3E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004F3EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004F3F0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8004F3F4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8004F3F8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8004F3FC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8004F400: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004F404: lh          $t6, 0x46($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X46);
    // 0x8004F408: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8004F40C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8004F410: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x8004F414: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8004F418: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004F41C: lh          $t1, 0x46($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X46);
    // 0x8004F420: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8004F424: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8004F428: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x8004F42C: or          $a3, $t2, $t4
    ctx->r7 = ctx->r10 | ctx->r12;
    // 0x8004F430: addiu       $a0, $sp, 0x3E
    ctx->r4 = ADD32(ctx->r29, 0X3E);
    // 0x8004F434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004F438: jal         0x800B3230
    // 0x8004F43C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_0;
    // 0x8004F43C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8004F440: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F444: bne         $v0, $at, L_8004F460
    if (ctx->r2 != ctx->r1) {
        // 0x8004F448: nop
    
            goto L_8004F460;
    }
    // 0x8004F448: nop

    // 0x8004F44C: lui         $t5, 0x2A
    ctx->r13 = S32(0X2A << 16);
    // 0x8004F450: ori         $t5, $t5, 0x45
    ctx->r13 = ctx->r13 | 0X45;
    // 0x8004F454: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8004F458: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8004F45C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_8004F460:
    // 0x8004F460: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8004F464: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004F468: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004F46C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004F470: bne         $t2, $zero, L_8004F480
    if (ctx->r10 != 0) {
        // 0x8004F474: andi        $t3, $t1, 0x8
        ctx->r11 = ctx->r9 & 0X8;
            goto L_8004F480;
    }
    // 0x8004F474: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x8004F478: beq         $t3, $zero, L_8004F48C
    if (ctx->r11 == 0) {
        // 0x8004F47C: nop
    
            goto L_8004F48C;
    }
    // 0x8004F47C: nop

L_8004F480:
    // 0x8004F480: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x8004F484: b           L_8004F49C
    // 0x8004F488: nop

        goto L_8004F49C;
    // 0x8004F488: nop

L_8004F48C:
    // 0x8004F48C: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x8004F490: nop

    // 0x8004F494: ori         $t7, $s0, 0x1
    ctx->r15 = ctx->r16 | 0X1;
    // 0x8004F498: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8004F49C:
    // 0x8004F49C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8004F4A0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8004F4A4: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8004F4A8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004F4AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8004F4B0: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8004F4B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F4B8: addiu       $a0, $t9, 0x4C
    ctx->r4 = ADD32(ctx->r25, 0X4C);
    // 0x8004F4BC: addiu       $a1, $t9, 0x50
    ctx->r5 = ADD32(ctx->r25, 0X50);
    // 0x8004F4C0: jal         0x800B202C
    // 0x8004F4C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_1;
    // 0x8004F4C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8004F4C8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8004F4CC: nop

    // 0x8004F4D0: sh          $v0, 0x48($t4)
    MEM_H(0X48, ctx->r12) = ctx->r2;
    // 0x8004F4D4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8004F4D8: nop

    // 0x8004F4DC: addiu       $a0, $t5, 0x50
    ctx->r4 = ADD32(ctx->r13, 0X50);
    // 0x8004F4E0: jal         0x8005A5F4
    // 0x8004F4E4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_2;
    // 0x8004F4E4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_2:
    // 0x8004F4E8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8004F4EC: nop

    // 0x8004F4F0: lw          $t8, 0x4C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4C);
    // 0x8004F4F4: nop

    // 0x8004F4F8: lwc1        $f8, 0xCC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x8004F4FC: nop

    // 0x8004F500: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x8004F504: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8004F508: nop

    // 0x8004F50C: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8004F510: nop

    // 0x8004F514: lwc1        $f10, 0xD0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x8004F518: nop

    // 0x8004F51C: swc1        $f10, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f10.u32l;
    // 0x8004F520: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8004F524: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8004F528: nop

    // 0x8004F52C: sh          $t2, 0x4A($t3)
    MEM_H(0X4A, ctx->r11) = ctx->r10;
    // 0x8004F530: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8004F534: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F538: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x8004F53C: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x8004F540: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x8004F544: addiu       $at, $zero, -0x703
    ctx->r1 = ADD32(0, -0X703);
    // 0x8004F548: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x8004F54C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8004F550: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8004F554: lhu         $t6, 0x3E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3E);
    // 0x8004F558: nop

    // 0x8004F55C: andi        $t1, $t6, 0x1
    ctx->r9 = ctx->r14 & 0X1;
    // 0x8004F560: beq         $t1, $zero, L_8004F5B4
    if (ctx->r9 == 0) {
        // 0x8004F564: nop
    
            goto L_8004F5B4;
    }
    // 0x8004F564: nop

    // 0x8004F568: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8004F56C: nop

    // 0x8004F570: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x8004F574: beq         $t2, $zero, L_8004F5A0
    if (ctx->r10 == 0) {
        // 0x8004F578: nop
    
            goto L_8004F5A0;
    }
    // 0x8004F578: nop

    // 0x8004F57C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8004F580: nop

    // 0x8004F584: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004F588: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004F58C: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004F590: ori         $t9, $t5, 0x400
    ctx->r25 = ctx->r13 | 0X400;
    // 0x8004F594: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8004F598: b           L_8004F5B4
    // 0x8004F59C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
        goto L_8004F5B4;
    // 0x8004F59C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
L_8004F5A0:
    // 0x8004F5A0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8004F5A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004F5A8: addiu       $a0, $t7, 0x4C
    ctx->r4 = ADD32(ctx->r15, 0X4C);
    // 0x8004F5AC: jal         0x800B2CBC
    // 0x8004F5B0: addiu       $a1, $t7, 0x50
    ctx->r5 = ADD32(ctx->r15, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_3;
    // 0x8004F5B0: addiu       $a1, $t7, 0x50
    ctx->r5 = ADD32(ctx->r15, 0X50);
    after_3:
L_8004F5B4:
    // 0x8004F5B4: lhu         $t6, 0x3E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3E);
    // 0x8004F5B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F5BC: andi        $t1, $t6, 0xE
    ctx->r9 = ctx->r14 & 0XE;
    // 0x8004F5C0: sra         $t0, $t1, 1
    ctx->r8 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8004F5C4: bne         $t0, $at, L_8004F5EC
    if (ctx->r8 != ctx->r1) {
        // 0x8004F5C8: nop
    
            goto L_8004F5EC;
    }
    // 0x8004F5C8: nop

    // 0x8004F5CC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8004F5D0: nop

    // 0x8004F5D4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8004F5D8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8004F5DC: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004F5E0: ori         $t9, $t5, 0x100
    ctx->r25 = ctx->r13 | 0X100;
    // 0x8004F5E4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8004F5E8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8004F5EC:
    // 0x8004F5EC: lhu         $t3, 0x3E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3E);
    // 0x8004F5F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004F5F4: andi        $t7, $t3, 0xE
    ctx->r15 = ctx->r11 & 0XE;
    // 0x8004F5F8: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8004F5FC: beq         $t6, $at, L_8004F610
    if (ctx->r14 == ctx->r1) {
        // 0x8004F600: nop
    
            goto L_8004F610;
    }
    // 0x8004F600: nop

    // 0x8004F604: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004F608: bne         $t6, $at, L_8004F634
    if (ctx->r14 != ctx->r1) {
        // 0x8004F60C: nop
    
            goto L_8004F634;
    }
    // 0x8004F60C: nop

L_8004F610:
    // 0x8004F610: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8004F614: nop

    // 0x8004F618: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8004F61C: or          $t4, $t1, $zero
    ctx->r12 = ctx->r9 | 0;
    // 0x8004F620: lw          $t1, 0x4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4);
    // 0x8004F624: or          $t8, $t0, $zero
    ctx->r24 = ctx->r8 | 0;
    // 0x8004F628: ori         $t9, $t1, 0x200
    ctx->r25 = ctx->r9 | 0X200;
    // 0x8004F62C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004F630: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_8004F634:
    // 0x8004F634: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8004F638: nop

    // 0x8004F63C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004F640: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004F644: or          $t6, $t2, $zero
    ctx->r14 = ctx->r10 | 0;
    // 0x8004F648: ori         $t7, $t3, 0x4
    ctx->r15 = ctx->r11 | 0X4;
    // 0x8004F64C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8004F650: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8004F654: b           L_8004F65C
    // 0x8004F658: nop

        goto L_8004F65C;
    // 0x8004F658: nop

L_8004F65C:
    // 0x8004F65C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F660: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004F664: jr          $ra
    // 0x8004F668: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8004F668: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80077800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077800: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077804: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077808: nop

    // 0x8007780C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80077810: nop

    // 0x80077814: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077818: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007781C: jr          $ra
    // 0x80077820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077824: jr          $ra
    // 0x80077828: nop

    return;
    // 0x80077828: nop

    // 0x8007782C: jr          $ra
    // 0x80077830: nop

    return;
    // 0x80077830: nop

;}
RECOMP_FUNC void func_80039F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039F78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80039F7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80039F80: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80039F84: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80039F88: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80039F8C: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x80039F90: jal         0x800C1850
    // 0x80039F94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_0;
    // 0x80039F94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80039F98: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80039F9C: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80039FA0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80039FA4: jal         0x800C2304
    // 0x80039FA8: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_1;
    // 0x80039FA8: nop

    after_1:
    // 0x80039FAC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80039FB0: jal         0x800C1D44
    // 0x80039FB4: nop

    func_800C1D44(rdram, ctx);
        goto after_2;
    // 0x80039FB4: nop

    after_2:
    // 0x80039FB8: jal         0x800C1680
    // 0x80039FBC: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_3;
    // 0x80039FBC: nop

    after_3:
    // 0x80039FC0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80039FC4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80039FC8: jal         0x800C2304
    // 0x80039FCC: lui         $a2, 0xC416
    ctx->r6 = S32(0XC416 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_4;
    // 0x80039FCC: lui         $a2, 0xC416
    ctx->r6 = S32(0XC416 << 16);
    after_4:
    // 0x80039FD0: jal         0x800B1844
    // 0x80039FD4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800B1844(rdram, ctx);
        goto after_5;
    // 0x80039FD4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x80039FD8: jal         0x800C1A28
    // 0x80039FDC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x80039FDC: nop

    after_6:
    // 0x80039FE0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80039FE4: lw          $t6, -0x4CCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CCC);
    // 0x80039FE8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80039FEC: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80039FF0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80039FF4: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80039FF8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80039FFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003A000: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003A004: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003A008: jal         0x800C2304
    // 0x8003A00C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x8003A00C: nop

    after_7:
    // 0x8003A010: jal         0x800B1844
    // 0x8003A014: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B1844(rdram, ctx);
        goto after_8;
    // 0x8003A014: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_8:
    // 0x8003A018: addiu       $t9, $sp, 0x3C
    ctx->r25 = ADD32(ctx->r29, 0X3C);
    // 0x8003A01C: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x8003A020: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8003A024: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x8003A028: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8003A02C: lwc1        $f14, 0x4($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8003A030: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x8003A034: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8003A038: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8003A03C: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8003A040: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x8003A044: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8003A048: jal         0x800C3D70
    // 0x8003A04C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800C3D70(rdram, ctx);
        goto after_9;
    // 0x8003A04C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8003A050: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x8003A054: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8003A058: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8003A05C: nop

    // 0x8003A060: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x8003A064: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x8003A068: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8003A06C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8003A070: nop

    // 0x8003A074: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x8003A078: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8003A07C: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8003A080: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8003A084: nop

    // 0x8003A088: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x8003A08C: b           L_8003A094
    // 0x8003A090: nop

        goto L_8003A094;
    // 0x8003A090: nop

L_8003A094:
    // 0x8003A094: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003A098: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8003A09C: jr          $ra
    // 0x8003A0A0: nop

    return;
    // 0x8003A0A0: nop

;}
RECOMP_FUNC void func_800775C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800775C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800775C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800775CC: nop

    // 0x800775D0: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x800775D4: nop

    // 0x800775D8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800775DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800775E0: jr          $ra
    // 0x800775E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800775E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800775E8: jr          $ra
    // 0x800775EC: nop

    return;
    // 0x800775EC: nop

    // 0x800775F0: jr          $ra
    // 0x800775F4: nop

    return;
    // 0x800775F4: nop

;}
RECOMP_FUNC void func_80033788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033788: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003378C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80033790: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80033794: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80033798: jal         0x8001AB84
    // 0x8003379C: nop

    func_8001AB84(rdram, ctx);
        goto after_0;
    // 0x8003379C: nop

    after_0:
    // 0x800337A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800337A4: jal         0x8008EAA8
    // 0x800337A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_1;
    // 0x800337A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800337AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800337B0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800337B4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800337B8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800337BC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800337C0: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x800337C4: lw          $a1, 0x258C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X258C);
    // 0x800337C8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800337CC: jal         0x8008ECE4
    // 0x800337D0: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x800337D0: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    after_2:
    // 0x800337D4: jal         0x800BCDFC
    // 0x800337D8: nop

    SysMem_GetLockedSize(rdram, ctx);
        goto after_3;
    // 0x800337D8: nop

    after_3:
    // 0x800337DC: jal         0x800BCD3C
    // 0x800337E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    SysMem_GetUnlockedSize(rdram, ctx);
        goto after_4;
    // 0x800337E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_4:
    // 0x800337E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800337E8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800337EC: addiu       $a0, $a0, -0x1754
    ctx->r4 = ADD32(ctx->r4, -0X1754);
    // 0x800337F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800337F4: jal         0x8008ECE4
    // 0x800337F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x800337F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800337FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80033800: lh          $t6, 0x2638($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2638);
    // 0x80033804: nop

    // 0x80033808: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8003380C: jal         0x800BCEBC
    // 0x80033810: nop

    SysMem_GetFreeSpace(rdram, ctx);
        goto after_6;
    // 0x80033810: nop

    after_6:
    // 0x80033814: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80033818: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8003381C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80033820: addiu       $a0, $a0, -0x1734
    ctx->r4 = ADD32(ctx->r4, -0X1734);
    // 0x80033824: jal         0x8008ECE4
    // 0x80033828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x80033828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8003382C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80033830: jal         0x8008ECE4
    // 0x80033834: addiu       $a0, $a0, -0x1710
    ctx->r4 = ADD32(ctx->r4, -0X1710);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x80033834: addiu       $a0, $a0, -0x1710
    ctx->r4 = ADD32(ctx->r4, -0X1710);
    after_8:
    // 0x80033838: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8003383C:
    // 0x8003383C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80033840: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80033844: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80033848: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8003384C: lhu         $a2, -0x7278($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X7278);
    // 0x80033850: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80033854: addiu       $a0, $a0, -0x1700
    ctx->r4 = ADD32(ctx->r4, -0X1700);
    // 0x80033858: jal         0x8008ECE4
    // 0x8003385C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8003385C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_9:
    // 0x80033860: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80033864: nop

    // 0x80033868: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8003386C: bgez        $t0, L_80033880
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80033870: andi        $t1, $t0, 0x3
        ctx->r9 = ctx->r8 & 0X3;
            goto L_80033880;
    }
    // 0x80033870: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80033874: beq         $t1, $zero, L_80033880
    if (ctx->r9 == 0) {
        // 0x80033878: nop
    
            goto L_80033880;
    }
    // 0x80033878: nop

    // 0x8003387C: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_80033880:
    // 0x80033880: bne         $t1, $zero, L_80033894
    if (ctx->r9 != 0) {
        // 0x80033884: nop
    
            goto L_80033894;
    }
    // 0x80033884: nop

    // 0x80033888: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8003388C: jal         0x8008ECE4
    // 0x80033890: addiu       $a0, $a0, -0x16F4
    ctx->r4 = ADD32(ctx->r4, -0X16F4);
    func_8008ECE4(rdram, ctx);
        goto after_10;
    // 0x80033890: addiu       $a0, $a0, -0x16F4
    ctx->r4 = ADD32(ctx->r4, -0X16F4);
    after_10:
L_80033894:
    // 0x80033894: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80033898: nop

    // 0x8003389C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800338A0: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x800338A4: bne         $at, $zero, L_8003383C
    if (ctx->r1 != 0) {
        // 0x800338A8: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8003383C;
    }
    // 0x800338A8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800338AC: jal         0x8001AC74
    // 0x800338B0: nop

    func_8001AC74(rdram, ctx);
        goto after_11;
    // 0x800338B0: nop

    after_11:
    // 0x800338B4: b           L_800338BC
    // 0x800338B8: nop

        goto L_800338BC;
    // 0x800338B8: nop

L_800338BC:
    // 0x800338BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800338C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800338C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800338C8: jr          $ra
    // 0x800338CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800338CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006525C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006525C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065260: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065264: nop

    // 0x80065268: lh          $v0, 0x26($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X26);
    // 0x8006526C: nop

    // 0x80065270: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80065274: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065278: jr          $ra
    // 0x8006527C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006527C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065280: jr          $ra
    // 0x80065284: nop

    return;
    // 0x80065284: nop

    // 0x80065288: jr          $ra
    // 0x8006528C: nop

    return;
    // 0x8006528C: nop

;}
RECOMP_FUNC void func_800C1314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C1318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C131C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C1320: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C1324: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800C1328: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C132C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1330: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1334: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1338: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C133C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1340: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1344: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1348: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800C134C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C1350: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C1354: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1358: nop

    // 0x800C135C: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800C1360: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800C1364: nop

    // 0x800C1368: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800C136C: bne         $t2, $zero, L_800C137C
    if (ctx->r10 != 0) {
        // 0x800C1370: nop
    
            goto L_800C137C;
    }
    // 0x800C1370: nop

    // 0x800C1374: b           L_800C13A8
    // 0x800C1378: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C13A8;
    // 0x800C1378: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C137C:
    // 0x800C137C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1380: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C1384: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    // 0x800C1388: ori         $at, $zero, 0x82B0
    ctx->r1 = 0 | 0X82B0;
    // 0x800C138C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C1390: jal         0x800C4C40
    // 0x800C1394: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1394: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    after_0:
    // 0x800C1398: b           L_800C13A8
    // 0x800C139C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C13A8;
    // 0x800C139C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C13A0: b           L_800C13A8
    // 0x800C13A4: nop

        goto L_800C13A8;
    // 0x800C13A4: nop

L_800C13A8:
    // 0x800C13A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C13AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C13B0: jr          $ra
    // 0x800C13B4: nop

    return;
    // 0x800C13B4: nop

;}
RECOMP_FUNC void func_80077A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A08: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077A0C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077A10: nop

    // 0x80077A14: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077A18: nop

    // 0x80077A1C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077A20: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077A24: jr          $ra
    // 0x80077A28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077A28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077A2C: jr          $ra
    // 0x80077A30: nop

    return;
    // 0x80077A30: nop

    // 0x80077A34: jr          $ra
    // 0x80077A38: nop

    return;
    // 0x80077A38: nop

;}
RECOMP_FUNC void func_8007318C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007318C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073190: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073194: nop

    // 0x80073198: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007319C: nop

    // 0x800731A0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800731A4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800731A8: jr          $ra
    // 0x800731AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800731AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800731B0: jr          $ra
    // 0x800731B4: nop

    return;
    // 0x800731B4: nop

    // 0x800731B8: jr          $ra
    // 0x800731BC: nop

    return;
    // 0x800731BC: nop

;}
RECOMP_FUNC void func_80080910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008091C: jal         0x800317E4
    // 0x80080920: nop

    func_800317E4(rdram, ctx);
        goto after_0;
    // 0x80080920: nop

    after_0:
    // 0x80080924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080928: jal         0x800319B0
    // 0x8008092C: nop

    func_800319B0(rdram, ctx);
        goto after_1;
    // 0x8008092C: nop

    after_1:
    // 0x80080930: b           L_80080938
    // 0x80080934: nop

        goto L_80080938;
    // 0x80080934: nop

L_80080938:
    // 0x80080938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008093C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080940: jr          $ra
    // 0x80080944: nop

    return;
    // 0x80080944: nop

;}
RECOMP_FUNC void func_80043E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043E24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043E28: jal         0x800BC6EC
    // 0x80043E2C: addiu       $a0, $zero, 0x1050
    ctx->r4 = ADD32(0, 0X1050);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80043E2C: addiu       $a0, $zero, 0x1050
    ctx->r4 = ADD32(0, 0X1050);
    after_0:
    // 0x80043E30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80043E34: sw          $v0, 0x72B8($at)
    MEM_W(0X72B8, ctx->r1) = ctx->r2;
    // 0x80043E38: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_80043E3C:
    // 0x80043E3C: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x80043E40: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80043E44: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80043E48: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80043E4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80043E50: lw          $t6, 0x72B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72B8);
    // 0x80043E54: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80043E58: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80043E5C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80043E60: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80043E64: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80043E68: jal         0x80099E2C
    // 0x80043E6C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x80043E6C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x80043E70: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x80043E74: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80043E78: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80043E7C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80043E80: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80043E84: lw          $t1, 0x72B8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72B8);
    // 0x80043E88: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80043E8C: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80043E90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80043E94: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    // 0x80043E98: jal         0x800B1B04
    // 0x80043E9C: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    func_800B1B04(rdram, ctx);
        goto after_2;
    // 0x80043E9C: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    after_2:
    // 0x80043EA0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80043EA4: lui         $t4, 0x4
    ctx->r12 = S32(0X4 << 16);
    // 0x80043EA8: ori         $t4, $t4, 0x4
    ctx->r12 = ctx->r12 | 0X4;
    // 0x80043EAC: sw          $t4, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r12;
    // 0x80043EB0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80043EB4: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80043EB8: sw          $t7, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r15;
    // 0x80043EBC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80043EC0: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80043EC4: sh          $t8, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r24;
    // 0x80043EC8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80043ECC: lw          $t0, 0x72B8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72B8);
    // 0x80043ED0: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x80043ED4: nop

    // 0x80043ED8: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x80043EDC: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80043EE0: lhu         $t3, 0x1E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X1E);
    // 0x80043EE4: nop

    // 0x80043EE8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80043EEC: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80043EF0: slti        $at, $t5, 0xA
    ctx->r1 = SIGNED(ctx->r13) < 0XA ? 1 : 0;
    // 0x80043EF4: bne         $at, $zero, L_80043E3C
    if (ctx->r1 != 0) {
        // 0x80043EF8: sh          $t4, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r12;
            goto L_80043E3C;
    }
    // 0x80043EF8: sh          $t4, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r12;
    // 0x80043EFC: b           L_80043F04
    // 0x80043F00: nop

        goto L_80043F04;
    // 0x80043F00: nop

L_80043F04:
    // 0x80043F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043F0C: jr          $ra
    // 0x80043F10: nop

    return;
    // 0x80043F10: nop

;}
RECOMP_FUNC void func_80069BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069BD0: jal         0x80061488
    // 0x80069BD4: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80069BD4: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_0:
    // 0x80069BD8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80069BDC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80069BE0: b           L_80069BF0
    // 0x80069BE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80069BF0;
    // 0x80069BE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069BE8: b           L_80069BF0
    // 0x80069BEC: nop

        goto L_80069BF0;
    // 0x80069BEC: nop

L_80069BF0:
    // 0x80069BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069BF8: jr          $ra
    // 0x80069BFC: nop

    return;
    // 0x80069BFC: nop

;}
RECOMP_FUNC void func_800B81B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B81B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B81B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B81BC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B81C0:
    // 0x800B81C0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B81C4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B81C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B81CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B81D0: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x800B81D4: nop

    // 0x800B81D8: beq         $t8, $zero, L_800B82A8
    if (ctx->r24 == 0) {
        // 0x800B81DC: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_800B82A8;
    }
    // 0x800B81DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B81E0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B81E4: nop

    // 0x800B81E8: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x800B81EC: nop

    // 0x800B81F0: beq         $t0, $zero, L_800B8294
    if (ctx->r8 == 0) {
        // 0x800B81F4: nop
    
            goto L_800B8294;
    }
    // 0x800B81F4: nop

    // 0x800B81F8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B81FC: nop

    // 0x800B8200: lw          $t2, 0x1AC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1AC);
    // 0x800B8204: nop

    // 0x800B8208: slti        $at, $t2, 0x4000
    ctx->r1 = SIGNED(ctx->r10) < 0X4000 ? 1 : 0;
    // 0x800B820C: bne         $at, $zero, L_800B8224
    if (ctx->r1 != 0) {
        // 0x800B8210: nop
    
            goto L_800B8224;
    }
    // 0x800B8210: nop

    // 0x800B8214: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x800B8218: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B821C: bne         $at, $zero, L_800B8294
    if (ctx->r1 != 0) {
        // 0x800B8220: nop
    
            goto L_800B8294;
    }
    // 0x800B8220: nop

L_800B8224:
    // 0x800B8224: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B8228: nop

    // 0x800B822C: lw          $t4, 0x20C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20C);
    // 0x800B8230: nop

    // 0x800B8234: beq         $t4, $zero, L_800B8294
    if (ctx->r12 == 0) {
        // 0x800B8238: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B8294;
    }
    // 0x800B8238: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B823C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8240: nop

    // 0x800B8244: lhu         $a2, 0x6($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X6);
    // 0x800B8248: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    // 0x800B824C: jal         0x800B1C10
    // 0x800B8250: addiu       $a1, $t5, 0x10
    ctx->r5 = ADD32(ctx->r13, 0X10);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x800B8250: addiu       $a1, $t5, 0x10
    ctx->r5 = ADD32(ctx->r13, 0X10);
    after_0:
    // 0x800B8254: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B8258: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B825C: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800B8260: nop

    // 0x800B8264: bne         $t7, $at, L_800B8294
    if (ctx->r15 != ctx->r1) {
        // 0x800B8268: nop
    
            goto L_800B8294;
    }
    // 0x800B8268: nop

    // 0x800B826C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8270: nop

    // 0x800B8274: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800B8278: nop

    // 0x800B827C: andi        $t0, $t9, 0x200
    ctx->r8 = ctx->r25 & 0X200;
    // 0x800B8280: beq         $t0, $zero, L_800B8294
    if (ctx->r8 == 0) {
        // 0x800B8284: nop
    
            goto L_800B8294;
    }
    // 0x800B8284: nop

    // 0x800B8288: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B828C: jal         0x800B82D8
    // 0x800B8290: nop

    func_800B82D8(rdram, ctx);
        goto after_1;
    // 0x800B8290: nop

    after_1:
L_800B8294:
    // 0x800B8294: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B8298: jal         0x8000D74C
    // 0x800B829C: nop

    func_8000D74C(rdram, ctx);
        goto after_2;
    // 0x800B829C: nop

    after_2:
    // 0x800B82A0: beq         $v0, $zero, L_800B82A8
    if (ctx->r2 == 0) {
        // 0x800B82A4: nop
    
            goto L_800B82A8;
    }
    // 0x800B82A4: nop

L_800B82A8:
    // 0x800B82A8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B82AC: nop

    // 0x800B82B0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B82B4: slti        $at, $t2, 0x14
    ctx->r1 = SIGNED(ctx->r10) < 0X14 ? 1 : 0;
    // 0x800B82B8: bne         $at, $zero, L_800B81C0
    if (ctx->r1 != 0) {
        // 0x800B82BC: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800B81C0;
    }
    // 0x800B82BC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800B82C0: b           L_800B82C8
    // 0x800B82C4: nop

        goto L_800B82C8;
    // 0x800B82C4: nop

L_800B82C8:
    // 0x800B82C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B82CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B82D0: jr          $ra
    // 0x800B82D4: nop

    return;
    // 0x800B82D4: nop

;}
RECOMP_FUNC void func_80072054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007205C: nop

    // 0x80072060: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072064: nop

    // 0x80072068: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007206C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072070: jr          $ra
    // 0x80072074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072078: jr          $ra
    // 0x8007207C: nop

    return;
    // 0x8007207C: nop

    // 0x80072080: jr          $ra
    // 0x80072084: nop

    return;
    // 0x80072084: nop

;}
RECOMP_FUNC void func_80068F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068F80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068F84: nop

    // 0x80068F88: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80068F8C: nop

    // 0x80068F90: slti        $t7, $v0, 0x385
    ctx->r15 = SIGNED(ctx->r2) < 0X385 ? 1 : 0;
    // 0x80068F94: jr          $ra
    // 0x80068F98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F9C: jr          $ra
    // 0x80068FA0: nop

    return;
    // 0x80068FA0: nop

    // 0x80068FA4: jr          $ra
    // 0x80068FA8: nop

    return;
    // 0x80068FA8: nop

;}
RECOMP_FUNC void func_8001A040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001A044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001A04C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001A050: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001A054: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001A058: jal         0x80016074
    // 0x8001A05C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x8001A05C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x8001A060: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001A064: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001A068: nop

    // 0x8001A06C: bne         $t6, $zero, L_8001A07C
    if (ctx->r14 != 0) {
        // 0x8001A070: nop
    
            goto L_8001A07C;
    }
    // 0x8001A070: nop

    // 0x8001A074: b           L_8001A200
    // 0x8001A078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001A200;
    // 0x8001A078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001A07C:
    // 0x8001A07C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001A080: nop

    // 0x8001A084: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8001A088: nop

    // 0x8001A08C: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x8001A090: bne         $t9, $zero, L_8001A0A4
    if (ctx->r25 != 0) {
        // 0x8001A094: nop
    
            goto L_8001A0A4;
    }
    // 0x8001A094: nop

    // 0x8001A098: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001A09C: jal         0x800198F8
    // 0x8001A0A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800198F8(rdram, ctx);
        goto after_1;
    // 0x8001A0A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8001A0A4:
    // 0x8001A0A4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0A8: nop

    // 0x8001A0AC: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8001A0B0: nop

    // 0x8001A0B4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8001A0B8: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x8001A0BC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0C0: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x8001A0C4: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x8001A0C8: nop

    // 0x8001A0CC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8001A0D0: sw          $t5, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = ctx->r13;
    // 0x8001A0D4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A0D8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0DC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001A0E0: nop

    // 0x8001A0E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001A0E8: swc1        $f6, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f6.u32l;
    // 0x8001A0EC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A0F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0F4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8001A0F8: nop

    // 0x8001A0FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001A100: swc1        $f10, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f10.u32l;
    // 0x8001A104: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A108: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001A10C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001A110: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8001A114: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001A118: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8001A11C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001A120: addiu       $t0, $t0, 0x61D8
    ctx->r8 = ADD32(ctx->r8, 0X61D8);
    // 0x8001A124: addu        $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
    // 0x8001A128: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8001A12C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A130: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001A134: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8001A138: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x8001A13C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8001A140: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x8001A144: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8001A148: addiu       $t6, $t6, 0x61D8
    ctx->r14 = ADD32(ctx->r14, 0X61D8);
    // 0x8001A14C: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8001A150: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001A154: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A158: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001A15C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001A160: nop

    // 0x8001A164: swc1        $f16, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f16.u32l;
    // 0x8001A168: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001A16C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A170: nop

    // 0x8001A174: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    // 0x8001A178: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001A17C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8001A180: nop

    // 0x8001A184: swc1        $f4, 0x1F0($t1)
    MEM_W(0X1F0, ctx->r9) = ctx->f4.u32l;
    // 0x8001A188: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001A18C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8001A190: nop

    // 0x8001A194: swc1        $f6, 0x1F4($t2)
    MEM_W(0X1F4, ctx->r10) = ctx->f6.u32l;
    // 0x8001A198: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001A19C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001A1A0: nop

    // 0x8001A1A4: swc1        $f8, 0x1F8($t0)
    MEM_W(0X1F8, ctx->r8) = ctx->f8.u32l;
    // 0x8001A1A8: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x8001A1AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001A1B0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001A1B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8001A1B8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001A1BC: swc1        $f18, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f18.u32l;
    // 0x8001A1C0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A1C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001A1C8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001A1CC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A1D0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001A1D4: swc1        $f8, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f8.u32l;
    // 0x8001A1D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001A1DC: jal         0x800AD774
    // 0x8001A1E0: nop

    func_800AD774(rdram, ctx);
        goto after_2;
    // 0x8001A1E0: nop

    after_2:
    // 0x8001A1E4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001A1E8: nop

    // 0x8001A1EC: sh          $v0, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r2;
    // 0x8001A1F0: b           L_8001A200
    // 0x8001A1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001A200;
    // 0x8001A1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A1F8: b           L_8001A200
    // 0x8001A1FC: nop

        goto L_8001A200;
    // 0x8001A1FC: nop

L_8001A200:
    // 0x8001A200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001A208: jr          $ra
    // 0x8001A20C: nop

    return;
    // 0x8001A20C: nop

;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD6BC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CD6C0: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x800CD6C4: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800CD6C8: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x800CD6CC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800CD6D0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800CD6D4:
    // 0x800CD6D4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800CD6D8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800CD6DC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800CD6E0: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x800CD6E4: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800CD6E8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800CD6EC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800CD6F0: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x800CD6F4: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x800CD6F8: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x800CD6FC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800CD700: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x800CD704: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800CD708: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800CD70C: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x800CD710: bne         $at, $zero, L_800CD6D4
    if (ctx->r1 != 0) {
        // 0x800CD714: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_800CD6D4;
    }
    // 0x800CD714: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800CD718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CD71C: jr          $ra
    // 0x800CD720: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CD720: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80063E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063E6C: jal         0x80061488
    // 0x80063E70: addiu       $a0, $zero, 0x5DC
    ctx->r4 = ADD32(0, 0X5DC);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063E70: addiu       $a0, $zero, 0x5DC
    ctx->r4 = ADD32(0, 0X5DC);
    after_0:
    // 0x80063E74: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063E78: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063E7C: b           L_80063E8C
    // 0x80063E80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063E8C;
    // 0x80063E80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063E84: b           L_80063E8C
    // 0x80063E88: nop

        goto L_80063E8C;
    // 0x80063E88: nop

L_80063E8C:
    // 0x80063E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063E94: jr          $ra
    // 0x80063E98: nop

    return;
    // 0x80063E98: nop

;}
RECOMP_FUNC void func_800AC7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC7F8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AC7FC: blez        $a2, L_800AC880
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AC800: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800AC880;
    }
    // 0x800AC800: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800AC804:
    // 0x800AC804: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC808: nop

    // 0x800AC80C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800AC810: bne         $t7, $zero, L_800AC840
    if (ctx->r15 != 0) {
        // 0x800AC814: nop
    
            goto L_800AC840;
    }
    // 0x800AC814: nop

    // 0x800AC818: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800AC81C: lw          $t4, 0x138($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X138);
    // 0x800AC820: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC824: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x800AC828: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800AC82C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x800AC830: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x800AC834: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800AC838: b           L_800AC868
    // 0x800AC83C: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
        goto L_800AC868;
    // 0x800AC83C: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
L_800AC840:
    // 0x800AC840: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC844: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x800AC848: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800AC84C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800AC850: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x800AC854: addu        $t3, $t9, $t7
    ctx->r11 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC858: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x800AC85C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800AC860: ori         $t4, $t2, 0x1
    ctx->r12 = ctx->r10 | 0X1;
    // 0x800AC864: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
L_800AC868:
    // 0x800AC868: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800AC86C: nop

    // 0x800AC870: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800AC874: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AC878: bne         $at, $zero, L_800AC804
    if (ctx->r1 != 0) {
        // 0x800AC87C: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800AC804;
    }
    // 0x800AC87C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_800AC880:
    // 0x800AC880: b           L_800AC888
    // 0x800AC884: nop

        goto L_800AC888;
    // 0x800AC884: nop

L_800AC888:
    // 0x800AC888: jr          $ra
    // 0x800AC88C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AC88C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void MtxUtil_Identity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1854: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800C1858: bne         $a0, $zero, L_800C1870
    if (ctx->r4 != 0) {
        // 0x800C185C: nop
    
            goto L_800C1870;
    }
    // 0x800C185C: nop

    // 0x800C1860: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1864: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1868: nop

    // 0x800C186C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
L_800C1870:
    // 0x800C1870: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800C1874: nop

    // 0x800C1878: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800C187C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800C1880: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
L_800C1884:
    // 0x800C1884: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C1888: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x800C188C: nop

    // 0x800C1890: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1894: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800C1898: nop

    // 0x800C189C: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C18A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C18A4: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800C18A8: nop

    // 0x800C18AC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800C18B0: bgtz        $t3, L_800C1884
    if (SIGNED(ctx->r11) > 0) {
        // 0x800C18B4: sw          $t3, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r11;
            goto L_800C1884;
    }
    // 0x800C18B4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800C18B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C18BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C18C0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C18C4: nop

    // 0x800C18C8: swc1        $f6, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f6.u32l;
    // 0x800C18CC: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C18D0: nop

    // 0x800C18D4: lwc1        $f14, 0x3C($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X3C);
    // 0x800C18D8: nop

    // 0x800C18DC: swc1        $f14, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f14.u32l;
    // 0x800C18E0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C18E4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C18E8: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    // 0x800C18EC: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C18F0: nop

    // 0x800C18F4: swc1        $f12, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f12.u32l;
    // 0x800C18F8: b           L_800C1900
    // 0x800C18FC: nop

        goto L_800C1900;
    // 0x800C18FC: nop

L_800C1900:
    // 0x800C1900: jr          $ra
    // 0x800C1904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C1904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80071C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071C58: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071C5C: nop

    // 0x80071C60: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80071C64: nop

    // 0x80071C68: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071C6C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80071C70: jr          $ra
    // 0x80071C74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071C74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071C78: jr          $ra
    // 0x80071C7C: nop

    return;
    // 0x80071C7C: nop

    // 0x80071C80: jr          $ra
    // 0x80071C84: nop

    return;
    // 0x80071C84: nop

;}
RECOMP_FUNC void func_800290EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290EC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800290F0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800290F4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800290F8: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x800290FC: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80029100: nop

    // 0x80029104: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80029108: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x8002910C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80029110: nop

    // 0x80029114: beq         $t8, $zero, L_80029198
    if (ctx->r24 == 0) {
        // 0x80029118: nop
    
            goto L_80029198;
    }
    // 0x80029118: nop

L_8002911C:
    // 0x8002911C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80029120: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029124: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80029128: nop

    // 0x8002912C: bne         $t0, $at, L_80029144
    if (ctx->r8 != ctx->r1) {
        // 0x80029130: nop
    
            goto L_80029144;
    }
    // 0x80029130: nop

    // 0x80029134: lh          $t1, 0x4($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X4);
    // 0x80029138: nop

    // 0x8002913C: beq         $t1, $zero, L_8002914C
    if (ctx->r9 == 0) {
        // 0x80029140: nop
    
            goto L_8002914C;
    }
    // 0x80029140: nop

L_80029144:
    // 0x80029144: b           L_80029198
    // 0x80029148: nop

        goto L_80029198;
    // 0x80029148: nop

L_8002914C:
    // 0x8002914C: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80029150: nop

    // 0x80029154: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80029158: nop

    // 0x8002915C: bne         $t3, $a0, L_80029174
    if (ctx->r11 != ctx->r4) {
        // 0x80029160: nop
    
            goto L_80029174;
    }
    // 0x80029160: nop

    // 0x80029164: lh          $t4, 0x6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6);
    // 0x80029168: nop

    // 0x8002916C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80029170: sh          $t5, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r13;
L_80029174:
    // 0x80029174: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80029178: nop

    // 0x8002917C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80029180: nop

    // 0x80029184: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80029188: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8002918C: nop

    // 0x80029190: bne         $t8, $zero, L_8002911C
    if (ctx->r24 != 0) {
        // 0x80029194: nop
    
            goto L_8002911C;
    }
    // 0x80029194: nop

L_80029198:
    // 0x80029198: lhu         $v0, 0x6($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X6);
    // 0x8002919C: b           L_800291AC
    // 0x800291A0: nop

        goto L_800291AC;
    // 0x800291A0: nop

    // 0x800291A4: b           L_800291AC
    // 0x800291A8: nop

        goto L_800291AC;
    // 0x800291A8: nop

L_800291AC:
    // 0x800291AC: jr          $ra
    // 0x800291B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800291B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80044444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044444: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80044448: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004444C: jal         0x800BC6EC
    // 0x80044450: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80044450: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    after_0:
    // 0x80044454: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80044458: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8004445C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80044460: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x80044464: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
    // 0x80044468: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004446C: nop

    // 0x80044470: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80044474: jal         0x80099E2C
    // 0x80044478: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x80044478: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x8004447C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80044480: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80044484: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80044488: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8004448C: jal         0x800B1B04
    // 0x80044490: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800B1B04(rdram, ctx);
        goto after_2;
    // 0x80044490: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_2:
    // 0x80044494: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80044498: ori         $t1, $zero, 0x8214
    ctx->r9 = 0 | 0X8214;
    // 0x8004449C: sw          $t1, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r9;
    // 0x800444A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800444A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800444A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800444AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800444B0: lui         $a2, 0xAE
    ctx->r6 = S32(0XAE << 16);
    // 0x800444B4: ori         $a2, $a2, 0x250
    ctx->r6 = ctx->r6 | 0X250;
    // 0x800444B8: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x800444BC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800444C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800444C4: jal         0x800B1F0C
    // 0x800444C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_3;
    // 0x800444C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800444CC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800444D0: addiu       $t3, $zero, 0x7FFF
    ctx->r11 = ADD32(0, 0X7FFF);
    // 0x800444D4: sw          $t3, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r11;
    // 0x800444D8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800444DC: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x800444E0: sh          $t5, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r13;
    // 0x800444E4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800444E8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800444EC: sh          $t7, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r15;
    // 0x800444F0: lui         $at, 0xC2DA
    ctx->r1 = S32(0XC2DA << 16);
    // 0x800444F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800444F8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800444FC: nop

    // 0x80044500: swc1        $f8, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f8.u32l;
    // 0x80044504: lui         $at, 0xC274
    ctx->r1 = S32(0XC274 << 16);
    // 0x80044508: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004450C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80044510: nop

    // 0x80044514: swc1        $f10, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f10.u32l;
    // 0x80044518: b           L_80044520
    // 0x8004451C: nop

        goto L_80044520;
    // 0x8004451C: nop

L_80044520:
    // 0x80044520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80044524: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80044528: jr          $ra
    // 0x8004452C: nop

    return;
    // 0x8004452C: nop

;}
RECOMP_FUNC void func_80073F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073F0C: jal         0x80061348
    // 0x80073F10: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073F10: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073F14: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073F18: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073F1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073F20: beq         $v0, $zero, L_80073F74
    if (ctx->r2 == 0) {
        // 0x80073F24: nop
    
            goto L_80073F74;
    }
    // 0x80073F24: nop

    // 0x80073F28: jal         0x80061348
    // 0x80073F2C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073F2C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073F30: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073F34: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073F38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073F3C: beq         $v0, $zero, L_80073F74
    if (ctx->r2 == 0) {
        // 0x80073F40: nop
    
            goto L_80073F74;
    }
    // 0x80073F40: nop

    // 0x80073F44: jal         0x80061348
    // 0x80073F48: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073F48: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073F4C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073F50: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073F54: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073F58: beq         $v0, $zero, L_80073F74
    if (ctx->r2 == 0) {
        // 0x80073F5C: nop
    
            goto L_80073F74;
    }
    // 0x80073F5C: nop

    // 0x80073F60: jal         0x80061348
    // 0x80073F64: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073F64: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073F68: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073F6C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073F70: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073F74:
    // 0x80073F74: b           L_80073F84
    // 0x80073F78: nop

        goto L_80073F84;
    // 0x80073F78: nop

    // 0x80073F7C: b           L_80073F84
    // 0x80073F80: nop

        goto L_80073F84;
    // 0x80073F80: nop

L_80073F84:
    // 0x80073F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073F88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073F8C: jr          $ra
    // 0x80073F90: nop

    return;
    // 0x80073F90: nop

;}
RECOMP_FUNC void func_80068B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068B40: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068B44: nop

    // 0x80068B48: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068B4C: nop

    // 0x80068B50: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068B54: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068B58: jr          $ra
    // 0x80068B5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068B5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068B60: jr          $ra
    // 0x80068B64: nop

    return;
    // 0x80068B64: nop

    // 0x80068B68: jr          $ra
    // 0x80068B6C: nop

    return;
    // 0x80068B6C: nop

;}
RECOMP_FUNC void func_8006DF7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DF80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DF84: jal         0x80061348
    // 0x8006DF88: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DF88: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x8006DF8C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF90: b           L_8006DFA0
    // 0x8006DF94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006DFA0;
    // 0x8006DF94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DF98: b           L_8006DFA0
    // 0x8006DF9C: nop

        goto L_8006DFA0;
    // 0x8006DF9C: nop

L_8006DFA0:
    // 0x8006DFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DFA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DFA8: jr          $ra
    // 0x8006DFAC: nop

    return;
    // 0x8006DFAC: nop

;}
RECOMP_FUNC void func_8006DE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DE0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DE10: jal         0x80061348
    // 0x8006DE14: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DE14: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DE18: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DE20: beq         $v0, $zero, L_8006DE38
    if (ctx->r2 == 0) {
        // 0x8006DE24: nop
    
            goto L_8006DE38;
    }
    // 0x8006DE24: nop

    // 0x8006DE28: jal         0x80061348
    // 0x8006DE2C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DE2C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DE30: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DE38:
    // 0x8006DE38: b           L_8006DE48
    // 0x8006DE3C: nop

        goto L_8006DE48;
    // 0x8006DE3C: nop

    // 0x8006DE40: b           L_8006DE48
    // 0x8006DE44: nop

        goto L_8006DE48;
    // 0x8006DE44: nop

L_8006DE48:
    // 0x8006DE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DE50: jr          $ra
    // 0x8006DE54: nop

    return;
    // 0x8006DE54: nop

;}
RECOMP_FUNC void MtxUtil_GetCurrentFromMtxF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2AF4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2AF8: lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE4);
    // 0x800C2AFC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C2B00: jal         0x800C2DD0
    // 0x800C2B04: nop

    MtxUtil__MtxFToMtx(rdram, ctx);
        goto after_0;
    // 0x800C2B04: nop

    after_0:
    // 0x800C2B08: b           L_800C2B10
    // 0x800C2B0C: nop

        goto L_800C2B10;
    // 0x800C2B0C: nop

L_800C2B10:
    // 0x800C2B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2B18: jr          $ra
    // 0x800C2B1C: nop

    return;
    // 0x800C2B1C: nop

;}
RECOMP_FUNC void func_800755D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800755D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800755D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800755D8: nop

    // 0x800755DC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800755E0: nop

    // 0x800755E4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800755E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800755EC: jr          $ra
    // 0x800755F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800755F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800755F4: jr          $ra
    // 0x800755F8: nop

    return;
    // 0x800755F8: nop

    // 0x800755FC: jr          $ra
    // 0x80075600: nop

    return;
    // 0x80075600: nop

;}
RECOMP_FUNC void func_8005A2CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A2CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A2D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A2D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005A2D8: jal         0x80059E28
    // 0x8005A2DC: nop

    func_80059E28(rdram, ctx);
        goto after_0;
    // 0x8005A2DC: nop

    after_0:
    // 0x8005A2E0: beq         $v0, $zero, L_8005A2F8
    if (ctx->r2 == 0) {
        // 0x8005A2E4: nop
    
            goto L_8005A2F8;
    }
    // 0x8005A2E4: nop

    // 0x8005A2E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005A2EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005A2F0: beq         $t6, $at, L_8005A300
    if (ctx->r14 == ctx->r1) {
        // 0x8005A2F4: nop
    
            goto L_8005A300;
    }
    // 0x8005A2F4: nop

L_8005A2F8:
    // 0x8005A2F8: b           L_8005A470
    // 0x8005A2FC: nop

        goto L_8005A470;
    // 0x8005A2FC: nop

L_8005A300:
    // 0x8005A300: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A304: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A308: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A30C: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x8005A310: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005A314: nop

    // 0x8005A318: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005A31C: nop

    // 0x8005A320: bc1f        L_8005A368
    if (!c1cs) {
        // 0x8005A324: nop
    
            goto L_8005A368;
    }
    // 0x8005A324: nop

    // 0x8005A328: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005A32C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005A330: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005A334: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8005A338: nop

    // 0x8005A33C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005A340: nop

    // 0x8005A344: bc1f        L_8005A35C
    if (!c1cs) {
        // 0x8005A348: nop
    
            goto L_8005A35C;
    }
    // 0x8005A348: nop

    // 0x8005A34C: b           L_8005A470
    // 0x8005A350: nop

        goto L_8005A470;
    // 0x8005A350: nop

    // 0x8005A354: b           L_8005A360
    // 0x8005A358: nop

        goto L_8005A360;
    // 0x8005A358: nop

L_8005A35C:
    // 0x8005A35C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8005A360:
    // 0x8005A360: b           L_8005A3A4
    // 0x8005A364: nop

        goto L_8005A3A4;
    // 0x8005A364: nop

L_8005A368:
    // 0x8005A368: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005A36C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005A370: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005A374: lwc1        $f16, 0xC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8005A378: nop

    // 0x8005A37C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8005A380: nop

    // 0x8005A384: bc1f        L_8005A39C
    if (!c1cs) {
        // 0x8005A388: nop
    
            goto L_8005A39C;
    }
    // 0x8005A388: nop

    // 0x8005A38C: b           L_8005A470
    // 0x8005A390: nop

        goto L_8005A470;
    // 0x8005A390: nop

    // 0x8005A394: b           L_8005A3A4
    // 0x8005A398: nop

        goto L_8005A3A4;
    // 0x8005A398: nop

L_8005A39C:
    // 0x8005A39C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005A3A0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8005A3A4:
    // 0x8005A3A4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A3A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005A3AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005A3B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005A3B4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8005A3B8: addiu       $a0, $a0, 0x1048
    ctx->r4 = ADD32(ctx->r4, 0X1048);
    // 0x8005A3BC: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A3C0: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A3C4: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A3C8: jal         0x800782A8
    // 0x8005A3CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800782A8(rdram, ctx);
        goto after_1;
    // 0x8005A3CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8005A3D0: bne         $v0, $zero, L_8005A3E0
    if (ctx->r2 != 0) {
        // 0x8005A3D4: nop
    
            goto L_8005A3E0;
    }
    // 0x8005A3D4: nop

    // 0x8005A3D8: b           L_8005A470
    // 0x8005A3DC: nop

        goto L_8005A470;
    // 0x8005A3DC: nop

L_8005A3E0:
    // 0x8005A3E0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005A3E4: lbu         $t2, 0x105E($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X105E);
    // 0x8005A3E8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005A3EC: nop

    // 0x8005A3F0: beq         $t2, $t3, L_8005A44C
    if (ctx->r10 == ctx->r11) {
        // 0x8005A3F4: nop
    
            goto L_8005A44C;
    }
    // 0x8005A3F4: nop

L_8005A3F8:
    // 0x8005A3F8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A3FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A400: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005A404: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005A408: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8005A40C: addiu       $a0, $a0, 0x1048
    ctx->r4 = ADD32(ctx->r4, 0X1048);
    // 0x8005A410: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A414: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A418: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A41C: jal         0x800783EC
    // 0x8005A420: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800783EC(rdram, ctx);
        goto after_2;
    // 0x8005A420: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8005A424: bne         $v0, $zero, L_8005A434
    if (ctx->r2 != 0) {
        // 0x8005A428: nop
    
            goto L_8005A434;
    }
    // 0x8005A428: nop

    // 0x8005A42C: b           L_8005A470
    // 0x8005A430: nop

        goto L_8005A470;
    // 0x8005A430: nop

L_8005A434:
    // 0x8005A434: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005A438: lbu         $t5, 0x105E($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X105E);
    // 0x8005A43C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005A440: nop

    // 0x8005A444: bne         $t5, $t6, L_8005A3F8
    if (ctx->r13 != ctx->r14) {
        // 0x8005A448: nop
    
            goto L_8005A3F8;
    }
    // 0x8005A448: nop

L_8005A44C:
    // 0x8005A44C: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8005A450: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A454: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
    // 0x8005A458: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005A45C: addiu       $t8, $t8, 0x1048
    ctx->r24 = ADD32(ctx->r24, 0X1048);
    // 0x8005A460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A464: sw          $t8, 0x11A8($at)
    MEM_W(0X11A8, ctx->r1) = ctx->r24;
    // 0x8005A468: b           L_8005A470
    // 0x8005A46C: nop

        goto L_8005A470;
    // 0x8005A46C: nop

L_8005A470:
    // 0x8005A470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A474: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005A478: jr          $ra
    // 0x8005A47C: nop

    return;
    // 0x8005A47C: nop

;}
RECOMP_FUNC void func_8003276C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003276C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032774: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80032778: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003277C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80032780: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80032784: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80032788: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003278C: jal         0x800A424C
    // 0x80032790: nop

    func_800A424C(rdram, ctx);
        goto after_0;
    // 0x80032790: nop

    after_0:
    // 0x80032794: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80032798: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8003279C: nop

    // 0x800327A0: sh          $t6, 0xEC($t7)
    MEM_H(0XEC, ctx->r15) = ctx->r14;
    // 0x800327A4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800327A8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800327AC: nop

    // 0x800327B0: sh          $t8, 0xF0($t9)
    MEM_H(0XF0, ctx->r25) = ctx->r24;
    // 0x800327B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800327B8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800327BC: nop

    // 0x800327C0: sh          $t0, 0xEE($t1)
    MEM_H(0XEE, ctx->r9) = ctx->r8;
    // 0x800327C4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800327C8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800327CC: nop

    // 0x800327D0: sh          $t2, 0xF2($t3)
    MEM_H(0XF2, ctx->r11) = ctx->r10;
    // 0x800327D4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800327D8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800327DC: nop

    // 0x800327E0: sw          $t4, 0xE8($t5)
    MEM_W(0XE8, ctx->r13) = ctx->r12;
    // 0x800327E4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800327E8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800327EC: nop

    // 0x800327F0: swc1        $f4, 0xF4($t6)
    MEM_W(0XF4, ctx->r14) = ctx->f4.u32l;
    // 0x800327F4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800327F8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800327FC: nop

    // 0x80032800: swc1        $f6, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f6.u32l;
    // 0x80032804: jal         0x800BC6EC
    // 0x80032808: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80032808: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_1:
    // 0x8003280C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80032810: nop

    // 0x80032814: sw          $v0, 0xE0($t8)
    MEM_W(0XE0, ctx->r24) = ctx->r2;
    // 0x80032818: jal         0x800BC6EC
    // 0x8003281C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8003281C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_2:
    // 0x80032820: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80032824: nop

    // 0x80032828: sw          $v0, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->r2;
    // 0x8003282C: b           L_80032834
    // 0x80032830: nop

        goto L_80032834;
    // 0x80032830: nop

L_80032834:
    // 0x80032834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003283C: jr          $ra
    // 0x80032840: nop

    return;
    // 0x80032840: nop

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
RECOMP_FUNC void func_8006F8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F8C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F8C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F8CC: jal         0x80061348
    // 0x8006F8D0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F8D0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006F8D4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F8D8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F8DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F8E0: beq         $v0, $zero, L_8006F934
    if (ctx->r2 == 0) {
        // 0x8006F8E4: nop
    
            goto L_8006F934;
    }
    // 0x8006F8E4: nop

    // 0x8006F8E8: jal         0x80061348
    // 0x8006F8EC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006F8EC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006F8F0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006F8F4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006F8F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F8FC: beq         $v0, $zero, L_8006F934
    if (ctx->r2 == 0) {
        // 0x8006F900: nop
    
            goto L_8006F934;
    }
    // 0x8006F900: nop

    // 0x8006F904: jal         0x80061348
    // 0x8006F908: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006F908: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006F90C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006F910: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006F914: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006F918: beq         $v0, $zero, L_8006F934
    if (ctx->r2 == 0) {
        // 0x8006F91C: nop
    
            goto L_8006F934;
    }
    // 0x8006F91C: nop

    // 0x8006F920: jal         0x80061348
    // 0x8006F924: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006F924: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006F928: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006F92C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006F930: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006F934:
    // 0x8006F934: b           L_8006F944
    // 0x8006F938: nop

        goto L_8006F944;
    // 0x8006F938: nop

    // 0x8006F93C: b           L_8006F944
    // 0x8006F940: nop

        goto L_8006F944;
    // 0x8006F940: nop

L_8006F944:
    // 0x8006F944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F94C: jr          $ra
    // 0x8006F950: nop

    return;
    // 0x8006F950: nop

;}
RECOMP_FUNC void func_8006C6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C6F8: jal         0x8005F064
    // 0x8006C6FC: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C6FC: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_0:
    // 0x8006C700: b           L_8006C710
    // 0x8006C704: nop

        goto L_8006C710;
    // 0x8006C704: nop

    // 0x8006C708: b           L_8006C710
    // 0x8006C70C: nop

        goto L_8006C710;
    // 0x8006C70C: nop

L_8006C710:
    // 0x8006C710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C718: jr          $ra
    // 0x8006C71C: nop

    return;
    // 0x8006C71C: nop

;}
RECOMP_FUNC void alSynSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3DD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D3DDC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D3DE0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800D3DE4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800D3DE8: beql        $t7, $zero, L_800D3E60
    if (ctx->r15 == 0) {
        // 0x800D3DEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3E60;
    }
    goto skip_0;
    // 0x800D3DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3DF0: jal         0x800C7C00
    // 0x800D3DF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3DF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D3DF8: beq         $v0, $zero, L_800D3E5C
    if (ctx->r2 == 0) {
        // 0x800D3DFC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800D3E5C;
    }
    // 0x800D3DFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D3E00: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D3E04: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800D3E08: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800D3E0C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800D3E10: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x800D3E14: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x800D3E18: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800D3E1C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800D3E20: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800D3E24: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800D3E28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D3E2C: jal         0x800C7AF8
    // 0x800D3E30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _timeToSamples(rdram, ctx);
        goto after_1;
    // 0x800D3E30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800D3E34: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3E38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3E3C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800D3E40: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D3E44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D3E48: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800D3E4C: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x800D3E50: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3E54: jalr        $t9
    // 0x800D3E58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D3E58: nop

    after_2:
L_800D3E5C:
    // 0x800D3E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3E60:
    // 0x800D3E60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3E64: jr          $ra
    // 0x800D3E68: nop

    return;
    // 0x800D3E68: nop

;}
RECOMP_FUNC void ContPak_FindFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEB14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AEB18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AEB1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEB20: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEB24: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800AEB28: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AEB2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEB30: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AEB34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEB38: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEB3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEB40: ori         $t9, $t8, 0x200
    ctx->r25 = ctx->r24 | 0X200;
    // 0x800AEB44: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AEB48: jal         0x800AE40C
    // 0x800AEB4C: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AEB4C: nop

    after_0:
    // 0x800AEB50: bgez        $v0, L_800AEB78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AEB54: nop
    
            goto L_800AEB78;
    }
    // 0x800AEB54: nop

    // 0x800AEB58: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEB5C: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AEB60: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800AEB64: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AEB68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEB6C: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AEB70: b           L_800AEBE4
    // 0x800AEB74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AEBE4;
    // 0x800AEB74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEB78:
    // 0x800AEB78: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AEB7C: lw          $t2, 0x1660($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1660);
    // 0x800AEB80: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AEB84: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800AEB88: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AEB8C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AEB90: addiu       $t3, $t3, 0x167C
    ctx->r11 = ADD32(ctx->r11, 0X167C);
    // 0x800AEB94: lw          $a3, 0x1654($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1654);
    // 0x800AEB98: lw          $a2, 0x164C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X164C);
    // 0x800AEB9C: lhu         $a1, 0x1646($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X1646);
    // 0x800AEBA0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AEBA4: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AEBA8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AEBAC: jal         0x800ADED0
    // 0x800AEBB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    ContPak_FindPfsSlot(rdram, ctx);
        goto after_1;
    // 0x800AEBB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AEBB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEBB8: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AEBBC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AEBC0: lw          $t4, 0x129C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X129C);
    // 0x800AEBC4: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800AEBC8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AEBCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEBD0: sw          $t5, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r13;
    // 0x800AEBD4: b           L_800AEBE4
    // 0x800AEBD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AEBE4;
    // 0x800AEBD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEBDC: b           L_800AEBE4
    // 0x800AEBE0: nop

        goto L_800AEBE4;
    // 0x800AEBE0: nop

L_800AEBE4:
    // 0x800AEBE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEBE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AEBEC: jr          $ra
    // 0x800AEBF0: nop

    return;
    // 0x800AEBF0: nop

;}
RECOMP_FUNC void func_80080738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080738: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008073C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80080740: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080744: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80080748:
    // 0x80080748: jal         0x800BC6EC
    // 0x8008074C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008074C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_0:
    // 0x80080750: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80080754: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80080758: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008075C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80080760: sw          $v0, -0x3808($at)
    MEM_W(-0X3808, ctx->r1) = ctx->r2;
    // 0x80080764: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80080768: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008076C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080770: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80080774: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80080778: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008077C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80080780: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80080784: lw          $a2, 0x23F8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X23F8);
    // 0x80080788: jal         0x800BD1FC
    // 0x8008078C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8008078C: nop

    after_1:
    // 0x80080790: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80080794: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80080798: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8008079C: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x800807A0: lw          $a1, -0x3808($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3808);
    // 0x800807A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800807A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800807AC: jal         0x800BD218
    // 0x800807B0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800807B0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_2:
    // 0x800807B4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800807B8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800807BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800807C0: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800807C4: lw          $a0, -0x3808($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3808);
    // 0x800807C8: jal         0x800808A4
    // 0x800807CC: nop

    func_800808A4(rdram, ctx);
        goto after_3;
    // 0x800807CC: nop

    after_3:
    // 0x800807D0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800807D4: nop

    // 0x800807D8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800807DC: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x800807E0: bne         $at, $zero, L_80080748
    if (ctx->r1 != 0) {
        // 0x800807E4: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80080748;
    }
    // 0x800807E4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800807E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800807EC:
    // 0x800807EC: jal         0x800BC6EC
    // 0x800807F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800807F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_4:
    // 0x800807F4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800807F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800807FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80080800: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80080804: sw          $v0, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r2;
    // 0x80080808: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008080C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080810: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080814: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80080818: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008081C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80080820: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80080824: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80080828: lw          $a2, 0x241C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X241C);
    // 0x8008082C: jal         0x800BD1FC
    // 0x80080830: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x80080830: nop

    after_5:
    // 0x80080834: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80080838: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8008083C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80080840: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80080844: lw          $a1, -0x37E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X37E0);
    // 0x80080848: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80080850: jal         0x800BD218
    // 0x80080854: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x80080854: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_6:
    // 0x80080858: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008085C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80080860: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80080864: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80080868: lw          $a0, -0x37E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37E0);
    // 0x8008086C: jal         0x800808A4
    // 0x80080870: nop

    func_800808A4(rdram, ctx);
        goto after_7;
    // 0x80080870: nop

    after_7:
    // 0x80080874: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80080878: nop

    // 0x8008087C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80080880: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x80080884: bne         $at, $zero, L_800807EC
    if (ctx->r1 != 0) {
        // 0x80080888: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800807EC;
    }
    // 0x80080888: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8008088C: b           L_80080894
    // 0x80080890: nop

        goto L_80080894;
    // 0x80080890: nop

L_80080894:
    // 0x80080894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80080898: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008089C: jr          $ra
    // 0x800808A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800808A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80075040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075040: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075044: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075048: nop

    // 0x8007504C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075050: nop

    // 0x80075054: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075058: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007505C: jr          $ra
    // 0x80075060: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075060: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075064: jr          $ra
    // 0x80075068: nop

    return;
    // 0x80075068: nop

    // 0x8007506C: jr          $ra
    // 0x80075070: nop

    return;
    // 0x80075070: nop

;}
RECOMP_FUNC void func_8008A674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A674: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008A678: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8008A67C:
    // 0x8008A67C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8008A680: nop

    // 0x8008A684: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008A688: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008A68C: lw          $t9, 0x12C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X12C);
    // 0x8008A690: nop

    // 0x8008A694: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8008A698: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8008A69C: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008A6A0: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008A6A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008A6A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008A6AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008A6B0: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8008A6B4: nop

    // 0x8008A6B8: bc1f        L_8008A708
    if (!c1cs) {
        // 0x8008A6BC: nop
    
            goto L_8008A708;
    }
    // 0x8008A6BC: nop

L_8008A6C0:
    // 0x8008A6C0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008A6C4: nop

    // 0x8008A6C8: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8008A6CC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008A6D0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008A6D4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008A6D8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008A6DC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008A6E0: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8008A6E4: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008A6E8: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008A6EC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8008A6F0: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008A6F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008A6F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008A6FC: nop

    // 0x8008A700: bc1t        L_8008A6C0
    if (c1cs) {
        // 0x8008A704: nop
    
            goto L_8008A6C0;
    }
    // 0x8008A704: nop

L_8008A708:
    // 0x8008A708: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8008A70C: nop

    // 0x8008A710: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008A714: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8008A718: bne         $at, $zero, L_8008A67C
    if (ctx->r1 != 0) {
        // 0x8008A71C: sw          $t6, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r14;
            goto L_8008A67C;
    }
    // 0x8008A71C: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8008A720: b           L_8008A728
    // 0x8008A724: nop

        goto L_8008A728;
    // 0x8008A724: nop

L_8008A728:
    // 0x8008A728: jr          $ra
    // 0x8008A72C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008A72C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800748CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800748CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800748D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800748D4: jal         0x80061348
    // 0x800748D8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800748D8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x800748DC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800748E0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800748E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800748E8: beq         $v0, $zero, L_8007493C
    if (ctx->r2 == 0) {
        // 0x800748EC: nop
    
            goto L_8007493C;
    }
    // 0x800748EC: nop

    // 0x800748F0: jal         0x80061348
    // 0x800748F4: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800748F4: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x800748F8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800748FC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074904: beq         $v0, $zero, L_8007493C
    if (ctx->r2 == 0) {
        // 0x80074908: nop
    
            goto L_8007493C;
    }
    // 0x80074908: nop

    // 0x8007490C: jal         0x80061348
    // 0x80074910: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074910: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074914: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074918: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007491C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074920: beq         $v0, $zero, L_8007493C
    if (ctx->r2 == 0) {
        // 0x80074924: nop
    
            goto L_8007493C;
    }
    // 0x80074924: nop

    // 0x80074928: jal         0x80061348
    // 0x8007492C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007492C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074930: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074934: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074938: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007493C:
    // 0x8007493C: b           L_8007494C
    // 0x80074940: nop

        goto L_8007494C;
    // 0x80074940: nop

    // 0x80074944: b           L_8007494C
    // 0x80074948: nop

        goto L_8007494C;
    // 0x80074948: nop

L_8007494C:
    // 0x8007494C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074954: jr          $ra
    // 0x80074958: nop

    return;
    // 0x80074958: nop

;}
