#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800AD5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD5EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD5F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AD5F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AD5FC: nop

    // 0x800AD600: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800AD604: bne         $at, $zero, L_800AD614
    if (ctx->r1 != 0) {
        // 0x800AD608: nop
    
            goto L_800AD614;
    }
    // 0x800AD608: nop

    // 0x800AD60C: b           L_800AD670
    // 0x800AD610: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AD670;
    // 0x800AD610: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AD614:
    // 0x800AD614: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AD618: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD61C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AD620: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AD624: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD628: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800AD62C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD630: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800AD634: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD638: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AD63C: jal         0x800C1680
    // 0x800AD640: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800AD640: nop

    after_0:
    // 0x800AD644: jal         0x800C1B64
    // 0x800AD648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_1;
    // 0x800AD648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800AD64C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD650: jal         0x800C1A84
    // 0x800AD654: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_2;
    // 0x800AD654: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_2:
    // 0x800AD658: jal         0x800C1A28
    // 0x800AD65C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x800AD65C: nop

    after_3:
    // 0x800AD660: b           L_800AD670
    // 0x800AD664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD670;
    // 0x800AD664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD668: b           L_800AD670
    // 0x800AD66C: nop

        goto L_800AD670;
    // 0x800AD66C: nop

L_800AD670:
    // 0x800AD670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AD678: jr          $ra
    // 0x800AD67C: nop

    return;
    // 0x800AD67C: nop

;}
RECOMP_FUNC void func_800765E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800765E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800765EC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800765F0: nop

    // 0x800765F4: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x800765F8: nop

    // 0x800765FC: slti        $t7, $v0, 0xE6
    ctx->r15 = SIGNED(ctx->r2) < 0XE6 ? 1 : 0;
    // 0x80076600: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076604: jr          $ra
    // 0x80076608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007660C: jr          $ra
    // 0x80076610: nop

    return;
    // 0x80076610: nop

    // 0x80076614: jr          $ra
    // 0x80076618: nop

    return;
    // 0x80076618: nop

;}
RECOMP_FUNC void func_800897A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897A8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800897AC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x800897B0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800897B4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800897B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800897BC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800897C0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800897C4: lhu         $t6, 0x750($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X750);
    // 0x800897C8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800897CC: beq         $t6, $at, L_80089804
    if (ctx->r14 == ctx->r1) {
        // 0x800897D0: nop
    
            goto L_80089804;
    }
    // 0x800897D0: nop

L_800897D4:
    // 0x800897D4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800897D8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800897DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800897E0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800897E4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800897E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800897EC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800897F0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800897F4: lhu         $t1, 0x750($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X750);
    // 0x800897F8: nop

    // 0x800897FC: bne         $t1, $at, L_800897D4
    if (ctx->r9 != ctx->r1) {
        // 0x80089800: nop
    
            goto L_800897D4;
    }
    // 0x80089800: nop

L_80089804:
    // 0x80089804: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80089808: nop

    // 0x8008980C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80089810: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80089814: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80089818: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008981C: sh          $a1, 0x750($t4)
    MEM_H(0X750, ctx->r12) = ctx->r5;
    // 0x80089820: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80089824: nop

    // 0x80089828: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008982C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80089830: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80089834: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80089838: sh          $a2, 0x752($t7)
    MEM_H(0X752, ctx->r15) = ctx->r6;
    // 0x8008983C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80089840: nop

    // 0x80089844: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80089848: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008984C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089850: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80089854: sh          $a3, 0x754($t0)
    MEM_H(0X754, ctx->r8) = ctx->r7;
    // 0x80089858: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008985C: lh          $t1, 0x1A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X1A);
    // 0x80089860: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80089864: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80089868: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008986C: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80089870: sh          $t1, 0x756($t4)
    MEM_H(0X756, ctx->r12) = ctx->r9;
    // 0x80089874: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80089878: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x8008987C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80089880: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80089884: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089888: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008988C: sh          $t5, 0x758($t8)
    MEM_H(0X758, ctx->r24) = ctx->r13;
    // 0x80089890: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80089894: lhu         $t9, 0x22($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X22);
    // 0x80089898: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8008989C: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x800898A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800898A4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800898A8: sh          $t9, 0x75A($t3)
    MEM_H(0X75A, ctx->r11) = ctx->r25;
    // 0x800898AC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800898B0: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800898B4: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800898B8: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800898BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800898C0: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800898C4: sh          $t1, 0x75C($t7)
    MEM_H(0X75C, ctx->r15) = ctx->r9;
    // 0x800898C8: b           L_800898D0
    // 0x800898CC: nop

        goto L_800898D0;
    // 0x800898CC: nop

L_800898D0:
    // 0x800898D0: jr          $ra
    // 0x800898D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800898D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006518C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006518C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065190: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065194: nop

    // 0x80065198: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x8006519C: nop

    // 0x800651A0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800651A4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800651A8: jr          $ra
    // 0x800651AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800651AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800651B0: jr          $ra
    // 0x800651B4: nop

    return;
    // 0x800651B4: nop

    // 0x800651B8: jr          $ra
    // 0x800651BC: nop

    return;
    // 0x800651BC: nop

;}
RECOMP_FUNC void SysMem_GetLockedSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCDFC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCE00: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800BCE04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCE08: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BCE0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCE10: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCE14: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCE18: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCE1C: nop

    // 0x800BCE20: beq         $t6, $t7, L_800BCE98
    if (ctx->r14 == ctx->r15) {
        // 0x800BCE24: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800BCE98;
    }
    // 0x800BCE24: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
L_800BCE28:
    // 0x800BCE28: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCE2C: nop

    // 0x800BCE30: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BCE34: nop

    // 0x800BCE38: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BCE3C: beq         $t0, $zero, L_800BCE7C
    if (ctx->r8 == 0) {
        // 0x800BCE40: nop
    
            goto L_800BCE7C;
    }
    // 0x800BCE40: nop

    // 0x800BCE44: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x800BCE48: beq         $t1, $zero, L_800BCE7C
    if (ctx->r9 == 0) {
        // 0x800BCE4C: nop
    
            goto L_800BCE7C;
    }
    // 0x800BCE4C: nop

    // 0x800BCE50: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800BCE54: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BCE58: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800BCE5C: nop

    // 0x800BCE60: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800BCE64: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800BCE68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCE6C: lh          $t6, 0x2638($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2638);
    // 0x800BCE70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCE74: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BCE78: sh          $t7, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = ctx->r15;
L_800BCE7C:
    // 0x800BCE7C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCE80: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BCE84: lw          $t9, 0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25E8);
    // 0x800BCE88: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800BCE8C: nop

    // 0x800BCE90: bne         $t0, $t9, L_800BCE28
    if (ctx->r8 != ctx->r25) {
        // 0x800BCE94: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_800BCE28;
    }
    // 0x800BCE94: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_800BCE98:
    // 0x800BCE98: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BCE9C: nop

    // 0x800BCEA0: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800BCEA4: b           L_800BCEB4
    // 0x800BCEA8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800BCEB4;
    // 0x800BCEA8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800BCEAC: b           L_800BCEB4
    // 0x800BCEB0: nop

        goto L_800BCEB4;
    // 0x800BCEB0: nop

L_800BCEB4:
    // 0x800BCEB4: jr          $ra
    // 0x800BCEB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCEB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8009A264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009A268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009A26C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009A270: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009A274: nop

    // 0x8009A278: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8009A27C: nop

    // 0x8009A280: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8009A284: bne         $t8, $zero, L_8009A2AC
    if (ctx->r24 != 0) {
        // 0x8009A288: nop
    
            goto L_8009A2AC;
    }
    // 0x8009A288: nop

    // 0x8009A28C: andi        $t9, $t7, 0x10
    ctx->r25 = ctx->r15 & 0X10;
    // 0x8009A290: beq         $t9, $zero, L_8009A2AC
    if (ctx->r25 == 0) {
        // 0x8009A294: nop
    
            goto L_8009A2AC;
    }
    // 0x8009A294: nop

    // 0x8009A298: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009A29C: nop

    // 0x8009A2A0: lwc1        $f12, 0xF0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x8009A2A4: jal         0x800C2780
    // 0x8009A2A8: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_0;
    // 0x8009A2A8: nop

    after_0:
L_8009A2AC:
    // 0x8009A2AC: b           L_8009A2B4
    // 0x8009A2B0: nop

        goto L_8009A2B4;
    // 0x8009A2B0: nop

L_8009A2B4:
    // 0x8009A2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009A2B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009A2BC: jr          $ra
    // 0x8009A2C0: nop

    return;
    // 0x8009A2C0: nop

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
RECOMP_FUNC void Spi_GetHeader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BED74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BED78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BED7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BED80: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800BED84: addiu       $a1, $a1, 0x490
    ctx->r5 = ADD32(ctx->r5, 0X490);
    // 0x800BED88: jal         0x800BD218
    // 0x800BED8C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    SysMem_DmaCopy(rdram, ctx);
        goto after_0;
    // 0x800BED8C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x800BED90: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BED94: addiu       $t6, $t6, 0x490
    ctx->r14 = ADD32(ctx->r14, 0X490);
    // 0x800BED98: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BED9C: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800BEDA0: bne         $t7, $at, L_800BEE28
    if (ctx->r15 != ctx->r1) {
        // 0x800BEDA4: nop
    
            goto L_800BEE28;
    }
    // 0x800BEDA4: nop

    // 0x800BEDA8: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x800BEDAC: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800BEDB0: bne         $t8, $at, L_800BEE28
    if (ctx->r24 != ctx->r1) {
        // 0x800BEDB4: nop
    
            goto L_800BEE28;
    }
    // 0x800BEDB4: nop

    // 0x800BEDB8: lbu         $t9, 0x2($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X2);
    // 0x800BEDBC: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800BEDC0: bne         $t9, $at, L_800BEE28
    if (ctx->r25 != ctx->r1) {
        // 0x800BEDC4: nop
    
            goto L_800BEE28;
    }
    // 0x800BEDC4: nop

    // 0x800BEDC8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BEDCC: addiu       $t0, $t0, 0x490
    ctx->r8 = ADD32(ctx->r8, 0X490);
    // 0x800BEDD0: lbu         $t1, 0x3($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3);
    // 0x800BEDD4: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800BEDD8: beq         $t1, $at, L_800BEE10
    if (ctx->r9 == ctx->r1) {
        // 0x800BEDDC: nop
    
            goto L_800BEE10;
    }
    // 0x800BEDDC: nop

    // 0x800BEDE0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BEDE4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BEDE8: lw          $t3, 0x49C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X49C);
    // 0x800BEDEC: lw          $t2, 0x498($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X498);
    // 0x800BEDF0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BEDF4: lw          $t5, 0x4A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4A0);
    // 0x800BEDF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800BEDFC: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800BEE00: b           L_800BEE38
    // 0x800BEE04: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
        goto L_800BEE38;
    // 0x800BEE04: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800BEE08: b           L_800BEE20
    // 0x800BEE0C: nop

        goto L_800BEE20;
    // 0x800BEE0C: nop

L_800BEE10:
    // 0x800BEE10: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800BEE14: lw          $v0, 0x494($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494);
    // 0x800BEE18: b           L_800BEE38
    // 0x800BEE1C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
        goto L_800BEE38;
    // 0x800BEE1C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_800BEE20:
    // 0x800BEE20: b           L_800BEE30
    // 0x800BEE24: nop

        goto L_800BEE30;
    // 0x800BEE24: nop

L_800BEE28:
    // 0x800BEE28: b           L_800BEE38
    // 0x800BEE2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BEE38;
    // 0x800BEE2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BEE30:
    // 0x800BEE30: b           L_800BEE38
    // 0x800BEE34: nop

        goto L_800BEE38;
    // 0x800BEE34: nop

L_800BEE38:
    // 0x800BEE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BEE3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BEE40: jr          $ra
    // 0x800BEE44: nop

    return;
    // 0x800BEE44: nop

;}
RECOMP_FUNC void func_80059E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E28: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059E2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80059E30: addiu       $t6, $t6, 0x28A8
    ctx->r14 = ADD32(ctx->r14, 0X28A8);
    // 0x80059E34: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80059E38: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80059E3C: nop

    // 0x80059E40: beq         $t7, $zero, L_80059EB8
    if (ctx->r15 == 0) {
        // 0x80059E44: nop
    
            goto L_80059EB8;
    }
    // 0x80059E44: nop

L_80059E48:
    // 0x80059E48: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80059E4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80059E50: addiu       $t0, $t0, 0x28A8
    ctx->r8 = ADD32(ctx->r8, 0X28A8);
    // 0x80059E54: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80059E58: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80059E5C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80059E60: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80059E64: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80059E68: nop

    // 0x80059E6C: bne         $t2, $t3, L_80059E94
    if (ctx->r10 != ctx->r11) {
        // 0x80059E70: nop
    
            goto L_80059E94;
    }
    // 0x80059E70: nop

    // 0x80059E74: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80059E78: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80059E7C: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80059E80: nop

    // 0x80059E84: bne         $t4, $t5, L_80059E94
    if (ctx->r12 != ctx->r13) {
        // 0x80059E88: nop
    
            goto L_80059E94;
    }
    // 0x80059E88: nop

    // 0x80059E8C: b           L_80059EC8
    // 0x80059E90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80059EC8;
    // 0x80059E90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059E94:
    // 0x80059E94: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80059E98: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80059E9C: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80059EA0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80059EA4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80059EA8: lh          $t9, 0x28A8($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X28A8);
    // 0x80059EAC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80059EB0: bne         $t9, $zero, L_80059E48
    if (ctx->r25 != 0) {
        // 0x80059EB4: nop
    
            goto L_80059E48;
    }
    // 0x80059EB4: nop

L_80059EB8:
    // 0x80059EB8: b           L_80059EC8
    // 0x80059EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059EC8;
    // 0x80059EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059EC0: b           L_80059EC8
    // 0x80059EC4: nop

        goto L_80059EC8;
    // 0x80059EC4: nop

L_80059EC8:
    // 0x80059EC8: jr          $ra
    // 0x80059ECC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059ECC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C0278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0278: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C027C: lw          $t6, 0x47C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X47C);
    // 0x800C0280: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C0284: bne         $t6, $at, L_800C02A8
    if (ctx->r14 != ctx->r1) {
        // 0x800C0288: nop
    
            goto L_800C02A8;
    }
    // 0x800C0288: nop

    // 0x800C028C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0290: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800C0294: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C0298: lw          $t7, 0x44C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44C);
    // 0x800C029C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C02A0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C02A4: sw          $t8, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r24;
L_800C02A8:
    // 0x800C02A8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C02AC: lw          $t9, 0x44C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X44C);
    // 0x800C02B0: nop

    // 0x800C02B4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800C02B8: nop

    // 0x800C02BC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800C02C0: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
    // 0x800C02C4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C02C8: lw          $t2, 0x44C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X44C);
    // 0x800C02CC: nop

    // 0x800C02D0: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800C02D4: nop

    // 0x800C02D8: andi        $t4, $t3, 0xFE
    ctx->r12 = ctx->r11 & 0XFE;
    // 0x800C02DC: sb          $t4, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r12;
    // 0x800C02E0: beq         $a0, $zero, L_800C0304
    if (ctx->r4 == 0) {
        // 0x800C02E4: nop
    
            goto L_800C0304;
    }
    // 0x800C02E4: nop

    // 0x800C02E8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800C02EC: lw          $t5, 0x44C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X44C);
    // 0x800C02F0: nop

    // 0x800C02F4: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800C02F8: nop

    // 0x800C02FC: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800C0300: sb          $t7, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r15;
L_800C0304:
    // 0x800C0304: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800C0308: lw          $t8, 0x47C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X47C);
    // 0x800C030C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0310: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800C0314: sw          $t0, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = ctx->r8;
    // 0x800C0318: jr          $ra
    // 0x800C031C: nop

    return;
    // 0x800C031C: nop

    // 0x800C0320: jr          $ra
    // 0x800C0324: nop

    return;
    // 0x800C0324: nop

;}
RECOMP_FUNC void func_800734F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800734F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800734FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073500: jal         0x8005F064
    // 0x80073504: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80073504: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x80073508: b           L_80073518
    // 0x8007350C: nop

        goto L_80073518;
    // 0x8007350C: nop

    // 0x80073510: b           L_80073518
    // 0x80073514: nop

        goto L_80073518;
    // 0x80073514: nop

L_80073518:
    // 0x80073518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007351C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073520: jr          $ra
    // 0x80073524: nop

    return;
    // 0x80073524: nop

;}
RECOMP_FUNC void func_800B2FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2FB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B2FBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B2FC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B2FC4: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800B2FC8: nop

    // 0x800B2FCC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B2FD0: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x800B2FD4: beq         $at, $zero, L_800B3210
    if (ctx->r1 == 0) {
        // 0x800B2FD8: nop
    
            goto L_800B3210;
    }
    // 0x800B2FD8: nop

    // 0x800B2FDC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B2FE0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2FE4: addu        $at, $at, $t7
    gpr jr_addend_800B2FF0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B2FE8: lw          $t7, -0x6A0($at)
    ctx->r15 = ADD32(ctx->r1, -0X6A0);
    // 0x800B2FEC: nop

    // 0x800B2FF0: jr          $t7
    // 0x800B2FF4: nop

    switch (jr_addend_800B2FF0 >> 2) {
        case 0: goto L_800B2FF8; break;
        case 1: goto L_800B30BC; break;
        case 2: goto L_800B3190; break;
        case 3: goto L_800B31B0; break;
        case 4: goto L_800B31D0; break;
        case 5: goto L_800B31F0; break;
        default: switch_error(__func__, 0x800B2FF0, 0x800EF960);
    }
    // 0x800B2FF4: nop

L_800B2FF8:
    // 0x800B2FF8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2FFC: nop

    // 0x800B3000: lhu         $t9, 0x3A($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B3004: nop

    // 0x800B3008: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800B300C: beq         $t0, $zero, L_800B304C
    if (ctx->r8 == 0) {
        // 0x800B3010: nop
    
            goto L_800B304C;
    }
    // 0x800B3010: nop

    // 0x800B3014: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3018: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800B301C: lhu         $t2, 0x3A($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X3A);
    // 0x800B3020: nop

    // 0x800B3024: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800B3028: sh          $t3, 0x3A($t1)
    MEM_H(0X3A, ctx->r9) = ctx->r11;
    // 0x800B302C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B3030: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3034: nop

    // 0x800B3038: swc1        $f4, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f4.u32l;
    // 0x800B303C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B3040: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3044: nop

    // 0x800B3048: swc1        $f6, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->f6.u32l;
L_800B304C:
    // 0x800B304C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3050: nop

    // 0x800B3054: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B3058: nop

    // 0x800B305C: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800B3060: beq         $t8, $zero, L_800B30B4
    if (ctx->r24 == 0) {
        // 0x800B3064: nop
    
            goto L_800B30B4;
    }
    // 0x800B3064: nop

    // 0x800B3068: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B306C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800B3070: lhu         $t0, 0x3A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B3074: nop

    // 0x800B3078: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x800B307C: sh          $t2, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r10;
    // 0x800B3080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3084: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3088: jal         0x800B4448
    // 0x800B308C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800B4448(rdram, ctx);
        goto after_0;
    // 0x800B308C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800B3090: beq         $v0, $zero, L_800B30A0
    if (ctx->r2 == 0) {
        // 0x800B3094: nop
    
            goto L_800B30A0;
    }
    // 0x800B3094: nop

    // 0x800B3098: b           L_800B3220
    // 0x800B309C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B3220;
    // 0x800B309C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B30A0:
    // 0x800B30A0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B30A8: lhu         $a2, 0x12($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X12);
    // 0x800B30AC: jal         0x800B47A0
    // 0x800B30B0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800B47A0(rdram, ctx);
        goto after_1;
    // 0x800B30B0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
L_800B30B4:
    // 0x800B30B4: b           L_800B3210
    // 0x800B30B8: nop

        goto L_800B3210;
    // 0x800B30B8: nop

L_800B30BC:
    // 0x800B30BC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30C0: nop

    // 0x800B30C4: lhu         $t4, 0x3A($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X3A);
    // 0x800B30C8: nop

    // 0x800B30CC: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x800B30D0: beq         $t5, $zero, L_800B30F0
    if (ctx->r13 == 0) {
        // 0x800B30D4: nop
    
            goto L_800B30F0;
    }
    // 0x800B30D4: nop

    // 0x800B30D8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30DC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800B30E0: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B30E4: nop

    // 0x800B30E8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B30EC: sh          $t8, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r24;
L_800B30F0:
    // 0x800B30F0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B30F4: nop

    // 0x800B30F8: lhu         $t2, 0x3A($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X3A);
    // 0x800B30FC: nop

    // 0x800B3100: andi        $t9, $t2, 0x80
    ctx->r25 = ctx->r10 & 0X80;
    // 0x800B3104: beq         $t9, $zero, L_800B3124
    if (ctx->r25 == 0) {
        // 0x800B3108: nop
    
            goto L_800B3124;
    }
    // 0x800B3108: nop

    // 0x800B310C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3110: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800B3114: lhu         $t1, 0x3A($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B3118: nop

    // 0x800B311C: and         $t4, $t1, $at
    ctx->r12 = ctx->r9 & ctx->r1;
    // 0x800B3120: sh          $t4, 0x3A($t3)
    MEM_H(0X3A, ctx->r11) = ctx->r12;
L_800B3124:
    // 0x800B3124: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3128: jal         0x800B4680
    // 0x800B312C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800B4680(rdram, ctx);
        goto after_2;
    // 0x800B312C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x800B3130: beq         $v0, $zero, L_800B3170
    if (ctx->r2 == 0) {
        // 0x800B3134: nop
    
            goto L_800B3170;
    }
    // 0x800B3134: nop

    // 0x800B3138: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B313C: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800B3140: lhu         $t7, 0x3A($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B3144: nop

    // 0x800B3148: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B314C: sh          $t8, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r24;
    // 0x800B3150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3154: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3158: jal         0x800B4448
    // 0x800B315C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B4448(rdram, ctx);
        goto after_3;
    // 0x800B315C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x800B3160: beq         $v0, $zero, L_800B3170
    if (ctx->r2 == 0) {
        // 0x800B3164: nop
    
            goto L_800B3170;
    }
    // 0x800B3164: nop

    // 0x800B3168: b           L_800B3220
    // 0x800B316C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B3220;
    // 0x800B316C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B3170:
    // 0x800B3170: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3174: nop

    // 0x800B3178: lhu         $t0, 0x3A($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B317C: nop

    // 0x800B3180: ori         $t2, $t0, 0x100
    ctx->r10 = ctx->r8 | 0X100;
    // 0x800B3184: sh          $t2, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r10;
    // 0x800B3188: b           L_800B3210
    // 0x800B318C: nop

        goto L_800B3210;
    // 0x800B318C: nop

L_800B3190:
    // 0x800B3190: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3194: nop

    // 0x800B3198: lhu         $t1, 0x3A($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B319C: nop

    // 0x800B31A0: ori         $t4, $t1, 0x200
    ctx->r12 = ctx->r9 | 0X200;
    // 0x800B31A4: sh          $t4, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r12;
    // 0x800B31A8: b           L_800B3210
    // 0x800B31AC: nop

        goto L_800B3210;
    // 0x800B31AC: nop

L_800B31B0:
    // 0x800B31B0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B31B4: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800B31B8: lhu         $t7, 0x3A($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B31BC: nop

    // 0x800B31C0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B31C4: sh          $t8, 0x3A($t3)
    MEM_H(0X3A, ctx->r11) = ctx->r24;
    // 0x800B31C8: b           L_800B3210
    // 0x800B31CC: nop

        goto L_800B3210;
    // 0x800B31CC: nop

L_800B31D0:
    // 0x800B31D0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B31D4: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x800B31D8: lhu         $t0, 0x3A($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B31DC: nop

    // 0x800B31E0: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x800B31E4: sh          $t2, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r10;
    // 0x800B31E8: b           L_800B3210
    // 0x800B31EC: nop

        goto L_800B3210;
    // 0x800B31EC: nop

L_800B31F0:
    // 0x800B31F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B31F4: nop

    // 0x800B31F8: lhu         $t1, 0x3A($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B31FC: nop

    // 0x800B3200: ori         $t4, $t1, 0x1000
    ctx->r12 = ctx->r9 | 0X1000;
    // 0x800B3204: sh          $t4, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r12;
    // 0x800B3208: b           L_800B3210
    // 0x800B320C: nop

        goto L_800B3210;
    // 0x800B320C: nop

L_800B3210:
    // 0x800B3210: b           L_800B3220
    // 0x800B3214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3220;
    // 0x800B3214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3218: b           L_800B3220
    // 0x800B321C: nop

        goto L_800B3220;
    // 0x800B321C: nop

L_800B3220:
    // 0x800B3220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3228: jr          $ra
    // 0x800B322C: nop

    return;
    // 0x800B322C: nop

;}
RECOMP_FUNC void func_8006ACD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ACD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ACDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ACE0: jal         0x80061348
    // 0x8006ACE4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ACE4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006ACE8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006ACEC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006ACF0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ACF4: beq         $v0, $zero, L_8006AD34
    if (ctx->r2 == 0) {
        // 0x8006ACF8: nop
    
            goto L_8006AD34;
    }
    // 0x8006ACF8: nop

    // 0x8006ACFC: jal         0x80061348
    // 0x8006AD00: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006AD00: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006AD04: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AD08: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AD0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AD10: beq         $v0, $zero, L_8006AD34
    if (ctx->r2 == 0) {
        // 0x8006AD14: nop
    
            goto L_8006AD34;
    }
    // 0x8006AD14: nop

    // 0x8006AD18: jal         0x80061348
    // 0x8006AD1C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006AD1C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006AD20: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AD24: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AD28: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AD2C: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AD30: nop
    
            goto L_8006AF78;
    }
    // 0x8006AD30: nop

L_8006AD34:
    // 0x8006AD34: jal         0x80061348
    // 0x8006AD38: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006AD38: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006AD3C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AD40: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AD44: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006AD48: beq         $v0, $zero, L_8006AD88
    if (ctx->r2 == 0) {
        // 0x8006AD4C: nop
    
            goto L_8006AD88;
    }
    // 0x8006AD4C: nop

    // 0x8006AD50: jal         0x80061348
    // 0x8006AD54: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006AD54: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006AD58: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006AD5C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006AD60: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006AD64: beq         $v0, $zero, L_8006AD88
    if (ctx->r2 == 0) {
        // 0x8006AD68: nop
    
            goto L_8006AD88;
    }
    // 0x8006AD68: nop

    // 0x8006AD6C: jal         0x80061348
    // 0x8006AD70: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006AD70: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006AD74: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006AD78: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006AD7C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006AD80: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AD84: nop
    
            goto L_8006AF78;
    }
    // 0x8006AD84: nop

L_8006AD88:
    // 0x8006AD88: jal         0x80061348
    // 0x8006AD8C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006AD8C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006AD90: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006AD94: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006AD98: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006AD9C: beq         $v0, $zero, L_8006ADDC
    if (ctx->r2 == 0) {
        // 0x8006ADA0: nop
    
            goto L_8006ADDC;
    }
    // 0x8006ADA0: nop

    // 0x8006ADA4: jal         0x80061348
    // 0x8006ADA8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006ADA8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006ADAC: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006ADB0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006ADB4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006ADB8: beq         $v0, $zero, L_8006ADDC
    if (ctx->r2 == 0) {
        // 0x8006ADBC: nop
    
            goto L_8006ADDC;
    }
    // 0x8006ADBC: nop

    // 0x8006ADC0: jal         0x80061348
    // 0x8006ADC4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006ADC4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006ADC8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006ADCC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006ADD0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006ADD4: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006ADD8: nop
    
            goto L_8006AF78;
    }
    // 0x8006ADD8: nop

L_8006ADDC:
    // 0x8006ADDC: jal         0x80061348
    // 0x8006ADE0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006ADE0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006ADE4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006ADE8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006ADEC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006ADF0: beq         $v0, $zero, L_8006AE30
    if (ctx->r2 == 0) {
        // 0x8006ADF4: nop
    
            goto L_8006AE30;
    }
    // 0x8006ADF4: nop

    // 0x8006ADF8: jal         0x80061348
    // 0x8006ADFC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006ADFC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006AE00: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AE04: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AE08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AE0C: beq         $v0, $zero, L_8006AE30
    if (ctx->r2 == 0) {
        // 0x8006AE10: nop
    
            goto L_8006AE30;
    }
    // 0x8006AE10: nop

    // 0x8006AE14: jal         0x80061348
    // 0x8006AE18: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006AE18: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006AE1C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AE20: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AE24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AE28: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AE2C: nop
    
            goto L_8006AF78;
    }
    // 0x8006AE2C: nop

L_8006AE30:
    // 0x8006AE30: jal         0x80061348
    // 0x8006AE34: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006AE34: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006AE38: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AE3C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AE40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AE44: beq         $v0, $zero, L_8006AE84
    if (ctx->r2 == 0) {
        // 0x8006AE48: nop
    
            goto L_8006AE84;
    }
    // 0x8006AE48: nop

    // 0x8006AE4C: jal         0x80061348
    // 0x8006AE50: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006AE50: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006AE54: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AE58: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AE5C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006AE60: beq         $v0, $zero, L_8006AE84
    if (ctx->r2 == 0) {
        // 0x8006AE64: nop
    
            goto L_8006AE84;
    }
    // 0x8006AE64: nop

    // 0x8006AE68: jal         0x80061348
    // 0x8006AE6C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006AE6C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006AE70: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006AE74: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006AE78: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006AE7C: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AE80: nop
    
            goto L_8006AF78;
    }
    // 0x8006AE80: nop

L_8006AE84:
    // 0x8006AE84: jal         0x80061348
    // 0x8006AE88: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006AE88: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006AE8C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006AE90: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006AE94: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006AE98: beq         $v0, $zero, L_8006AED8
    if (ctx->r2 == 0) {
        // 0x8006AE9C: nop
    
            goto L_8006AED8;
    }
    // 0x8006AE9C: nop

    // 0x8006AEA0: jal         0x80061348
    // 0x8006AEA4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006AEA4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006AEA8: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006AEAC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006AEB0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006AEB4: beq         $v0, $zero, L_8006AED8
    if (ctx->r2 == 0) {
        // 0x8006AEB8: nop
    
            goto L_8006AED8;
    }
    // 0x8006AEB8: nop

    // 0x8006AEBC: jal         0x80061348
    // 0x8006AEC0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006AEC0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006AEC4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006AEC8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006AECC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006AED0: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AED4: nop
    
            goto L_8006AF78;
    }
    // 0x8006AED4: nop

L_8006AED8:
    // 0x8006AED8: jal         0x80061348
    // 0x8006AEDC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006AEDC: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006AEE0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006AEE4: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006AEE8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006AEEC: beq         $v0, $zero, L_8006AF2C
    if (ctx->r2 == 0) {
        // 0x8006AEF0: nop
    
            goto L_8006AF2C;
    }
    // 0x8006AEF0: nop

    // 0x8006AEF4: jal         0x80061348
    // 0x8006AEF8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006AEF8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006AEFC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006AF00: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006AF04: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006AF08: beq         $v0, $zero, L_8006AF2C
    if (ctx->r2 == 0) {
        // 0x8006AF0C: nop
    
            goto L_8006AF2C;
    }
    // 0x8006AF0C: nop

    // 0x8006AF10: jal         0x80061348
    // 0x8006AF14: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006AF14: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006AF18: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AF1C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AF20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AF24: bne         $v0, $zero, L_8006AF78
    if (ctx->r2 != 0) {
        // 0x8006AF28: nop
    
            goto L_8006AF78;
    }
    // 0x8006AF28: nop

L_8006AF2C:
    // 0x8006AF2C: jal         0x80061348
    // 0x8006AF30: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006AF30: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006AF34: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AF38: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AF3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AF40: beq         $v0, $zero, L_8006AF78
    if (ctx->r2 == 0) {
        // 0x8006AF44: nop
    
            goto L_8006AF78;
    }
    // 0x8006AF44: nop

    // 0x8006AF48: jal         0x80061348
    // 0x8006AF4C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006AF4C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006AF50: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AF54: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AF58: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AF5C: beq         $v0, $zero, L_8006AF78
    if (ctx->r2 == 0) {
        // 0x8006AF60: nop
    
            goto L_8006AF78;
    }
    // 0x8006AF60: nop

    // 0x8006AF64: jal         0x80061348
    // 0x8006AF68: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006AF68: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006AF6C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AF70: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AF74: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006AF78:
    // 0x8006AF78: b           L_8006AF88
    // 0x8006AF7C: nop

        goto L_8006AF88;
    // 0x8006AF7C: nop

    // 0x8006AF80: b           L_8006AF88
    // 0x8006AF84: nop

        goto L_8006AF88;
    // 0x8006AF84: nop

L_8006AF88:
    // 0x8006AF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006AF90: jr          $ra
    // 0x8006AF94: nop

    return;
    // 0x8006AF94: nop

;}
RECOMP_FUNC void func_8006FB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FB1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FB20: jal         0x80061348
    // 0x8006FB24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FB24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FB28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FB2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FB30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FB34: beq         $v0, $zero, L_8006FB88
    if (ctx->r2 == 0) {
        // 0x8006FB38: nop
    
            goto L_8006FB88;
    }
    // 0x8006FB38: nop

    // 0x8006FB3C: jal         0x80061348
    // 0x8006FB40: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FB40: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FB44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FB48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FB4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FB50: beq         $v0, $zero, L_8006FB88
    if (ctx->r2 == 0) {
        // 0x8006FB54: nop
    
            goto L_8006FB88;
    }
    // 0x8006FB54: nop

    // 0x8006FB58: jal         0x80061348
    // 0x8006FB5C: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FB5C: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FB60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FB64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FB68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FB6C: beq         $v0, $zero, L_8006FB88
    if (ctx->r2 == 0) {
        // 0x8006FB70: nop
    
            goto L_8006FB88;
    }
    // 0x8006FB70: nop

    // 0x8006FB74: jal         0x80061348
    // 0x8006FB78: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FB78: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FB7C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FB80: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FB84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FB88:
    // 0x8006FB88: b           L_8006FB98
    // 0x8006FB8C: nop

        goto L_8006FB98;
    // 0x8006FB8C: nop

    // 0x8006FB90: b           L_8006FB98
    // 0x8006FB94: nop

        goto L_8006FB98;
    // 0x8006FB94: nop

L_8006FB98:
    // 0x8006FB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FB9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FBA0: jr          $ra
    // 0x8006FBA4: nop

    return;
    // 0x8006FBA4: nop

;}
RECOMP_FUNC void func_8006A8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A8FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A900: jal         0x80061488
    // 0x8006A904: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006A904: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_0:
    // 0x8006A908: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006A90C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006A910: b           L_8006A920
    // 0x8006A914: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006A920;
    // 0x8006A914: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A918: b           L_8006A920
    // 0x8006A91C: nop

        goto L_8006A920;
    // 0x8006A91C: nop

L_8006A920:
    // 0x8006A920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A928: jr          $ra
    // 0x8006A92C: nop

    return;
    // 0x8006A92C: nop

;}
RECOMP_FUNC void func_80088F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F50: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80088F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088F58: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80088F5C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80088F60: nop

    // 0x80088F64: lhu         $t7, 0xBD0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XBD0);
    // 0x80088F68: nop

    // 0x80088F6C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80088F70: beq         $at, $zero, L_80089150
    if (ctx->r1 == 0) {
        // 0x80088F74: nop
    
            goto L_80089150;
    }
    // 0x80088F74: nop

    // 0x80088F78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80088F7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80088F80: addu        $at, $at, $t7
    gpr jr_addend_80088F8C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80088F84: lw          $t7, -0xA44($at)
    ctx->r15 = ADD32(ctx->r1, -0XA44);
    // 0x80088F88: nop

    // 0x80088F8C: jr          $t7
    // 0x80088F90: nop

    switch (jr_addend_80088F8C >> 2) {
        case 0: goto L_80088F94; break;
        case 1: goto L_80088FE0; break;
        case 2: goto L_8008906C; break;
        case 3: goto L_800890F0; break;
        case 4: goto L_8008913C; break;
        default: switch_error(__func__, 0x80088F8C, 0x800EF5BC);
    }
    // 0x80088F90: nop

L_80088F94:
    // 0x80088F94: jal         0x80016074
    // 0x80088F98: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80088F98: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80088F9C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80088FA0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80088FA4: nop

    // 0x80088FA8: beq         $t8, $zero, L_80088FD8
    if (ctx->r24 == 0) {
        // 0x80088FAC: nop
    
            goto L_80088FD8;
    }
    // 0x80088FAC: nop

    // 0x80088FB0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80088FB4: nop

    // 0x80088FB8: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x80088FBC: nop

    // 0x80088FC0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80088FC4: beq         $t1, $zero, L_80088FD8
    if (ctx->r9 == 0) {
        // 0x80088FC8: nop
    
            goto L_80088FD8;
    }
    // 0x80088FC8: nop

    // 0x80088FCC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80088FD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80088FD4: sh          $t2, 0xBD0($t3)
    MEM_H(0XBD0, ctx->r11) = ctx->r10;
L_80088FD8:
    // 0x80088FD8: b           L_80089150
    // 0x80088FDC: nop

        goto L_80089150;
    // 0x80088FDC: nop

L_80088FE0:
    // 0x80088FE0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80088FE4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80088FE8: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80088FEC: nop

    // 0x80088FF0: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80088FF4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80088FF8: lh          $t7, 0x4660($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X4660);
    // 0x80088FFC: nop

    // 0x80089000: sh          $t7, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r15;
    // 0x80089004: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80089008: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008900C: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80089010: nop

    // 0x80089014: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80089018: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008901C: lh          $t1, 0x4662($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4662);
    // 0x80089020: nop

    // 0x80089024: sh          $t1, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r9;
    // 0x80089028: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008902C: nop

    // 0x80089030: lh          $a0, 0xA($t2)
    ctx->r4 = MEM_H(ctx->r10, 0XA);
    // 0x80089034: lh          $a1, 0xC($t2)
    ctx->r5 = MEM_H(ctx->r10, 0XC);
    // 0x80089038: jal         0x8008B494
    // 0x8008903C: nop

    func_8008B494(rdram, ctx);
        goto after_1;
    // 0x8008903C: nop

    after_1:
    // 0x80089040: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80089044: nop

    // 0x80089048: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x8008904C: nop

    // 0x80089050: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80089054: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
    // 0x80089058: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8008905C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80089060: sh          $t7, 0xBD0($t4)
    MEM_H(0XBD0, ctx->r12) = ctx->r15;
    // 0x80089064: b           L_80089150
    // 0x80089068: nop

        goto L_80089150;
    // 0x80089068: nop

L_8008906C:
    // 0x8008906C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80089070: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80089074: nop

    // 0x80089078: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8008907C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80089080: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80089084: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80089088: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8008908C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80089090: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x80089094: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80089098: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008909C: nop

    // 0x800890A0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800890A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800890A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800890AC: nop

    // 0x800890B0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800890B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800890B8: nop

    // 0x800890BC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800890C0: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x800890C4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800890C8: jal         0x80016620
    // 0x800890CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_2;
    // 0x800890CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800890D0: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x800890D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800890D8: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
    // 0x800890DC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800890E0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800890E4: sh          $t2, 0xBD0($t5)
    MEM_H(0XBD0, ctx->r13) = ctx->r10;
    // 0x800890E8: b           L_80089150
    // 0x800890EC: nop

        goto L_80089150;
    // 0x800890EC: nop

L_800890F0:
    // 0x800890F0: jal         0x80016074
    // 0x800890F4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_3;
    // 0x800890F4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_3:
    // 0x800890F8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800890FC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80089100: nop

    // 0x80089104: beq         $t6, $zero, L_80089134
    if (ctx->r14 == 0) {
        // 0x80089108: nop
    
            goto L_80089134;
    }
    // 0x80089108: nop

    // 0x8008910C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80089110: nop

    // 0x80089114: lw          $t7, 0x1A8($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X1A8);
    // 0x80089118: nop

    // 0x8008911C: andi        $t4, $t7, 0x2
    ctx->r12 = ctx->r15 & 0X2;
    // 0x80089120: beq         $t4, $zero, L_80089134
    if (ctx->r12 == 0) {
        // 0x80089124: nop
    
            goto L_80089134;
    }
    // 0x80089124: nop

    // 0x80089128: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008912C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80089130: sh          $t9, 0xBD0($t0)
    MEM_H(0XBD0, ctx->r8) = ctx->r25;
L_80089134:
    // 0x80089134: b           L_80089150
    // 0x80089138: nop

        goto L_80089150;
    // 0x80089138: nop

L_8008913C:
    // 0x8008913C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80089140: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80089144: sh          $t1, 0xBD0($t8)
    MEM_H(0XBD0, ctx->r24) = ctx->r9;
    // 0x80089148: b           L_80089160
    // 0x8008914C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80089160;
    // 0x8008914C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80089150:
    // 0x80089150: b           L_80089160
    // 0x80089154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80089160;
    // 0x80089154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80089158: b           L_80089160
    // 0x8008915C: nop

        goto L_80089160;
    // 0x8008915C: nop

L_80089160:
    // 0x80089160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089164: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80089168: jr          $ra
    // 0x8008916C: nop

    return;
    // 0x8008916C: nop

;}
RECOMP_FUNC void func_800633D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800633D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800633DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800633E0: jal         0x8005F064
    // 0x800633E4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800633E4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x800633E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800633EC: b           L_800633FC
    // 0x800633F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800633FC;
    // 0x800633F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800633F4: b           L_800633FC
    // 0x800633F8: nop

        goto L_800633FC;
    // 0x800633F8: nop

L_800633FC:
    // 0x800633FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063404: jr          $ra
    // 0x80063408: nop

    return;
    // 0x80063408: nop

;}
RECOMP_FUNC void func_8006DAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DAF8: jal         0x80061348
    // 0x8006DAFC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DAFC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DB00: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DB08: beq         $v0, $zero, L_8006DB38
    if (ctx->r2 == 0) {
        // 0x8006DB0C: nop
    
            goto L_8006DB38;
    }
    // 0x8006DB0C: nop

    // 0x8006DB10: jal         0x80061348
    // 0x8006DB14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DB14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DB18: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DB20: beq         $v0, $zero, L_8006DB38
    if (ctx->r2 == 0) {
        // 0x8006DB24: nop
    
            goto L_8006DB38;
    }
    // 0x8006DB24: nop

    // 0x8006DB28: jal         0x80061348
    // 0x8006DB2C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DB2C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_2:
    // 0x8006DB30: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DB38:
    // 0x8006DB38: b           L_8006DB48
    // 0x8006DB3C: nop

        goto L_8006DB48;
    // 0x8006DB3C: nop

    // 0x8006DB40: b           L_8006DB48
    // 0x8006DB44: nop

        goto L_8006DB48;
    // 0x8006DB44: nop

L_8006DB48:
    // 0x8006DB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DB4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DB50: jr          $ra
    // 0x8006DB54: nop

    return;
    // 0x8006DB54: nop

;}
RECOMP_FUNC void func_80082124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008212C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80082130: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80082134: nop

    // 0x80082138: lhu         $a2, 0x8($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X8);
    // 0x8008213C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80082140: jal         0x800B1C10
    // 0x80082144: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x80082144: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x80082148: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008214C: nop

    // 0x80082150: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80082154: jal         0x800BC980
    // 0x80082158: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80082158: nop

    after_1:
    // 0x8008215C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80082160: nop

    // 0x80082164: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x80082168: jal         0x800BC980
    // 0x8008216C: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8008216C: nop

    after_2:
    // 0x80082170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80082174: jal         0x800BC980
    // 0x80082178: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80082178: nop

    after_3:
    // 0x8008217C: b           L_80082184
    // 0x80082180: nop

        goto L_80082184;
    // 0x80082180: nop

L_80082184:
    // 0x80082184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008218C: jr          $ra
    // 0x80082190: nop

    return;
    // 0x80082190: nop

    // 0x80082194: nop

    // 0x80082198: nop

    // 0x8008219C: nop

;}
RECOMP_FUNC void func_800A3918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3918: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A391C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A3924: jal         0x800BC6EC
    // 0x800A3928: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A3928: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_0:
    // 0x800A392C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A3930: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A3934: nop

    // 0x800A3938: bne         $t6, $zero, L_800A3948
    if (ctx->r14 != 0) {
        // 0x800A393C: nop
    
            goto L_800A3948;
    }
    // 0x800A393C: nop

    // 0x800A3940: b           L_800A39B4
    // 0x800A3944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A39B4;
    // 0x800A3944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A3948:
    // 0x800A3948: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A394C: jal         0x80099E2C
    // 0x800A3950: nop

    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x800A3950: nop

    after_1:
    // 0x800A3954: jal         0x800BC6EC
    // 0x800A3958: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800A3958: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_2:
    // 0x800A395C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800A3960: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A3964: bne         $s0, $zero, L_800A3980
    if (ctx->r16 != 0) {
        // 0x800A3968: sw          $s0, 0x138($t7)
        MEM_W(0X138, ctx->r15) = ctx->r16;
            goto L_800A3980;
    }
    // 0x800A3968: sw          $s0, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r16;
    // 0x800A396C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A3970: jal         0x800BC980
    // 0x800A3974: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800A3974: nop

    after_3:
    // 0x800A3978: b           L_800A39B4
    // 0x800A397C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A39B4;
    // 0x800A397C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A3980:
    // 0x800A3980: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A3984: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x800A3988: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x800A398C: jal         0x80090A38
    // 0x800A3990: nop

    func_80090A38(rdram, ctx);
        goto after_4;
    // 0x800A3990: nop

    after_4:
    // 0x800A3994: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800A3998: addiu       $t9, $zero, 0x108
    ctx->r25 = ADD32(0, 0X108);
    // 0x800A399C: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x800A39A0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800A39A4: b           L_800A39B4
    // 0x800A39A8: nop

        goto L_800A39B4;
    // 0x800A39A8: nop

    // 0x800A39AC: b           L_800A39B4
    // 0x800A39B0: nop

        goto L_800A39B4;
    // 0x800A39B0: nop

L_800A39B4:
    // 0x800A39B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A39B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A39BC: jr          $ra
    // 0x800A39C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A39C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Thread_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C05A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C05A4: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
L_800C05A8:
    // 0x800C05A8: lbu         $t6, 0x7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7);
    // 0x800C05AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C05B0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C05B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C05B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C05BC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C05C0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C05C4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C05C8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C05CC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C05D0: sb          $zero, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = 0;
    // 0x800C05D4: lbu         $t8, 0x7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X7);
    // 0x800C05D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C05DC: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800C05E0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C05E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C05E8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C05EC: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C05F0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C05F4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C05F8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C05FC: sb          $zero, -0x63C7($at)
    MEM_B(-0X63C7, ctx->r1) = 0;
    // 0x800C0600: lbu         $t0, 0x7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7);
    // 0x800C0604: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800C0608: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800C060C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800C0610: sw          $zero, 0x3DC0($at)
    MEM_W(0X3DC0, ctx->r1) = 0;
    // 0x800C0614: lbu         $t2, 0x7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7);
    // 0x800C0618: nop

    // 0x800C061C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C0620: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800C0624: slti        $at, $t4, 0xC
    ctx->r1 = SIGNED(ctx->r12) < 0XC ? 1 : 0;
    // 0x800C0628: bne         $at, $zero, L_800C05A8
    if (ctx->r1 != 0) {
        // 0x800C062C: sb          $t3, 0x7($sp)
        MEM_B(0X7, ctx->r29) = ctx->r11;
            goto L_800C05A8;
    }
    // 0x800C062C: sb          $t3, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r11;
    // 0x800C0630: b           L_800C0638
    // 0x800C0634: nop

        goto L_800C0638;
    // 0x800C0634: nop

L_800C0638:
    // 0x800C0638: jr          $ra
    // 0x800C063C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C063C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ContPak_GetReadFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEFD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEFD8: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEFDC: nop

    // 0x800AEFE0: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x800AEFE4: beq         $t7, $zero, L_800AEFF4
    if (ctx->r15 == 0) {
        // 0x800AEFE8: nop
    
            goto L_800AEFF4;
    }
    // 0x800AEFE8: nop

    // 0x800AEFEC: jr          $ra
    // 0x800AEFF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEFF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEFF4:
    // 0x800AEFF4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEFF8: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEFFC: nop

    // 0x800AF000: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800AF004: beq         $t9, $zero, L_800AF014
    if (ctx->r25 == 0) {
        // 0x800AF008: nop
    
            goto L_800AF014;
    }
    // 0x800AF008: nop

    // 0x800AF00C: jr          $ra
    // 0x800AF010: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AF010: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AF014:
    // 0x800AF014: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AF018: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AF01C: nop

    // 0x800AF020: beq         $t0, $zero, L_800AF040
    if (ctx->r8 == 0) {
        // 0x800AF024: nop
    
            goto L_800AF040;
    }
    // 0x800AF024: nop

    // 0x800AF028: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AF02C: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AF030: nop

    // 0x800AF034: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AF038: jr          $ra
    // 0x800AF03C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AF03C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AF040:
    // 0x800AF040: jr          $ra
    // 0x800AF044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AF044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF048: jr          $ra
    // 0x800AF04C: nop

    return;
    // 0x800AF04C: nop

    // 0x800AF050: jr          $ra
    // 0x800AF054: nop

    return;
    // 0x800AF054: nop

;}
RECOMP_FUNC void func_80071540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071540: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071544: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071548: nop

    // 0x8007154C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80071550: nop

    // 0x80071554: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071558: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007155C: jr          $ra
    // 0x80071560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071564: jr          $ra
    // 0x80071568: nop

    return;
    // 0x80071568: nop

    // 0x8007156C: jr          $ra
    // 0x80071570: nop

    return;
    // 0x80071570: nop

;}
RECOMP_FUNC void func_8004BB74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BB74: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8004BB78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004BB7C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8004BB80: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8004BB84: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8004BB88: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8004BB8C: nop

    // 0x8004BB90: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8004BB94: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8004BB98: nop

    // 0x8004BB9C: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8004BBA0: nop

    // 0x8004BBA4: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x8004BBA8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8004BBAC: nop

    // 0x8004BBB0: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x8004BBB4: lw          $t0, 0x2F9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2F9);
    // 0x8004BBB8: nop

    // 0x8004BBBC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004BBC0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8004BBC4: nop

    // 0x8004BBC8: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x8004BBCC: jal         0x80098754
    // 0x8004BBD0: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8004BBD0: nop

    after_0:
    // 0x8004BBD4: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8004BBD8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8004BBDC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8004BBE0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8004BBE4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8004BBE8:
    // 0x8004BBE8: jal         0x80031AC8
    // 0x8004BBEC: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x8004BBEC: nop

    after_1:
    // 0x8004BBF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BBF4: bne         $v0, $at, L_8004BC1C
    if (ctx->r2 != ctx->r1) {
        // 0x8004BBF8: nop
    
            goto L_8004BC1C;
    }
    // 0x8004BBF8: nop

L_8004BBFC:
    // 0x8004BBFC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004BC00: jal         0x800499B0
    // 0x8004BC04: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8004BC04: nop

    after_2:
    // 0x8004BC08: jal         0x80031AC8
    // 0x8004BC0C: nop

    func_80031AC8(rdram, ctx);
        goto after_3;
    // 0x8004BC0C: nop

    after_3:
    // 0x8004BC10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BC14: beq         $v0, $at, L_8004BBFC
    if (ctx->r2 == ctx->r1) {
        // 0x8004BC18: nop
    
            goto L_8004BBFC;
    }
    // 0x8004BC18: nop

L_8004BC1C:
    // 0x8004BC1C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8004BC20: nop

    // 0x8004BC24: addiu       $t4, $t3, 0x7FFF
    ctx->r12 = ADD32(ctx->r11, 0X7FFF);
    // 0x8004BC28: lh          $t4, 0x2F3($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2F3);
    // 0x8004BC2C: nop

    // 0x8004BC30: bne         $t4, $zero, L_8004BC90
    if (ctx->r12 != 0) {
        // 0x8004BC34: nop
    
            goto L_8004BC90;
    }
    // 0x8004BC34: nop

    // 0x8004BC38: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8004BC3C: lui         $t8, 0x809F
    ctx->r24 = S32(0X809F << 16);
    // 0x8004BC40: addiu       $t6, $t5, 0x7FFF
    ctx->r14 = ADD32(ctx->r13, 0X7FFF);
    // 0x8004BC44: lh          $t6, 0x2F1($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2F1);
    // 0x8004BC48: addiu       $t8, $t8, -0x4688
    ctx->r24 = ADD32(ctx->r24, -0X4688);
    // 0x8004BC4C: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8004BC50: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8004BC54: addiu       $at, $t5, 0x7FFF
    ctx->r1 = ADD32(ctx->r13, 0X7FFF);
    // 0x8004BC58: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004BC5C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8004BC60: sh          $t9, 0x2F1($at)
    MEM_H(0X2F1, ctx->r1) = ctx->r25;
    // 0x8004BC64: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8004BC68: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8004BC6C: jal         0x800BD1FC
    // 0x8004BC70: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x8004BC70: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_4:
    // 0x8004BC74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004BC78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004BC7C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8004BC80: jal         0x800BD218
    // 0x8004BC84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x8004BC84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8004BC88: b           L_8004BCE0
    // 0x8004BC8C: nop

        goto L_8004BCE0;
    // 0x8004BC8C: nop

L_8004BC90:
    // 0x8004BC90: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8004BC94: lui         $t3, 0x809F
    ctx->r11 = S32(0X809F << 16);
    // 0x8004BC98: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8004BC9C: lh          $t1, 0x2F1($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2F1);
    // 0x8004BCA0: addiu       $t3, $t3, 0xF74
    ctx->r11 = ADD32(ctx->r11, 0XF74);
    // 0x8004BCA4: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8004BCA8: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8004BCAC: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x8004BCB0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004BCB4: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x8004BCB8: sh          $t4, 0x2F1($at)
    MEM_H(0X2F1, ctx->r1) = ctx->r12;
    // 0x8004BCBC: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8004BCC0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8004BCC4: jal         0x800BD1FC
    // 0x8004BCC8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x8004BCC8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_6:
    // 0x8004BCCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004BCD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004BCD4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8004BCD8: jal         0x800BD218
    // 0x8004BCDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_7;
    // 0x8004BCDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
L_8004BCE0:
    // 0x8004BCE0: lhu         $t7, 0x50($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X50);
    // 0x8004BCE4: nop

    // 0x8004BCE8: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x8004BCEC: beq         $t8, $zero, L_8004BD0C
    if (ctx->r24 == 0) {
        // 0x8004BCF0: nop
    
            goto L_8004BD0C;
    }
    // 0x8004BCF0: nop

    // 0x8004BCF4: lhu         $t6, 0x50($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X50);
    // 0x8004BCF8: nop

    // 0x8004BCFC: andi        $t9, $t6, 0x1FFF
    ctx->r25 = ctx->r14 & 0X1FFF;
    // 0x8004BD00: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8004BD04: b           L_8004D470
    // 0x8004BD08: nop

        goto L_8004D470;
    // 0x8004BD08: nop

L_8004BD0C:
    // 0x8004BD0C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004BD10: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004BD14: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8004BD18: nop

    // 0x8004BD1C: bne         $t5, $t2, L_8004C5B8
    if (ctx->r13 != ctx->r10) {
        // 0x8004BD20: nop
    
            goto L_8004C5B8;
    }
    // 0x8004BD20: nop

    // 0x8004BD24: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8004BD28: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004BD2C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004BD30: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004BD34: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004BD38: bne         $t0, $zero, L_8004BD48
    if (ctx->r8 != 0) {
        // 0x8004BD3C: and         $t1, $t5, $at
        ctx->r9 = ctx->r13 & ctx->r1;
            goto L_8004BD48;
    }
    // 0x8004BD3C: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x8004BD40: beq         $t1, $zero, L_8004BD58
    if (ctx->r9 == 0) {
        // 0x8004BD44: nop
    
            goto L_8004BD58;
    }
    // 0x8004BD44: nop

L_8004BD48:
    // 0x8004BD48: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8004BD4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004BD50: b           L_8004BD64
    // 0x8004BD54: sh          $t7, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r15;
        goto L_8004BD64;
    // 0x8004BD54: sh          $t7, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r15;
L_8004BD58:
    // 0x8004BD58: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004BD5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004BD60: sh          $t8, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r24;
L_8004BD64:
    // 0x8004BD64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004BD68: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004BD6C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004BD70: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8004BD74: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x8004BD78: bne         $t4, $zero, L_8004BD88
    if (ctx->r12 != 0) {
        // 0x8004BD7C: andi        $t5, $t3, 0x8000
        ctx->r13 = ctx->r11 & 0X8000;
            goto L_8004BD88;
    }
    // 0x8004BD7C: andi        $t5, $t3, 0x8000
    ctx->r13 = ctx->r11 & 0X8000;
    // 0x8004BD80: beq         $t5, $zero, L_8004C0C0
    if (ctx->r13 == 0) {
        // 0x8004BD84: nop
    
            goto L_8004C0C0;
    }
    // 0x8004BD84: nop

L_8004BD88:
    // 0x8004BD88: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8004BD8C: nop

    // 0x8004BD90: bne         $t9, $zero, L_8004C0C0
    if (ctx->r25 != 0) {
        // 0x8004BD94: nop
    
            goto L_8004C0C0;
    }
    // 0x8004BD94: nop

    // 0x8004BD98: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004BD9C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004BDA0: nop

    // 0x8004BDA4: addiu       $a0, $t0, 0x68
    ctx->r4 = ADD32(ctx->r8, 0X68);
    // 0x8004BDA8: jal         0x80056274
    // 0x8004BDAC: addiu       $a1, $t0, 0x6A
    ctx->r5 = ADD32(ctx->r8, 0X6A);
    func_80056274(rdram, ctx);
        goto after_8;
    // 0x8004BDAC: addiu       $a1, $t0, 0x6A
    ctx->r5 = ADD32(ctx->r8, 0X6A);
    after_8:
    // 0x8004BDB0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004BDB4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004BDB8: nop

    // 0x8004BDBC: swc1        $f0, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f0.u32l;
    // 0x8004BDC0: lhu         $t7, 0x50($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X50);
    // 0x8004BDC4: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x8004BDC8: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8004BDCC: bne         $t8, $at, L_8004BDF4
    if (ctx->r24 != ctx->r1) {
        // 0x8004BDD0: nop
    
            goto L_8004BDF4;
    }
    // 0x8004BDD0: nop

    // 0x8004BDD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004BDD8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004BDDC: nop

    // 0x8004BDE0: lw          $t2, 0x5C($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X5C);
    // 0x8004BDE4: nop

    // 0x8004BDE8: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8004BDEC: nop

    // 0x8004BDF0: swc1        $f4, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f4.u32l;
L_8004BDF4:
    // 0x8004BDF4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8004BDF8: jal         0x8004F6E4
    // 0x8004BDFC: nop

    func_8004F6E4(rdram, ctx);
        goto after_9;
    // 0x8004BDFC: nop

    after_9:
    // 0x8004BE00: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004BE04: jal         0x80054264
    // 0x8004BE08: nop

    func_80054264(rdram, ctx);
        goto after_10;
    // 0x8004BE08: nop

    after_10:
    // 0x8004BE0C: beq         $v0, $zero, L_8004BE24
    if (ctx->r2 == 0) {
        // 0x8004BE10: nop
    
            goto L_8004BE24;
    }
    // 0x8004BE10: nop

    // 0x8004BE14: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004BE18: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x8004BE1C: jal         0x80052508
    // 0x8004BE20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_11;
    // 0x8004BE20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
L_8004BE24:
    // 0x8004BE24: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004BE28: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004BE2C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004BE30: lw          $a1, 0x6C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X6C);
    // 0x8004BE34: jal         0x80053580
    // 0x8004BE38: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80053580(rdram, ctx);
        goto after_12;
    // 0x8004BE38: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_12:
    // 0x8004BE3C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004BE40: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x8004BE44: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004BE48: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BE4C: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BE4C: nop

    // 0x8004BE50: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004BE54: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BE58: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BE58: nop

    // 0x8004BE5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004BE60: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BE64: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BE64: nop

    // 0x8004BE68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004BE6C: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BE70: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BE70: nop

    // 0x8004BE74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004BE78: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BE7C: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BE7C: nop

    // 0x8004BE80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004BE84: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BE88: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BE88: nop

    // 0x8004BE8C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004BE90: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BE94: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BE94: nop

    // 0x8004BE98: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004BE9C: beq         $t4, $at, L_8004BEB8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BEA0: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BEA0: nop

    // 0x8004BEA4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004BEA8: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x8004BEAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004BEB0: bne         $t5, $at, L_8004BEE0
    if (ctx->r13 != ctx->r1) {
        // 0x8004BEB4: nop
    
            goto L_8004BEE0;
    }
    // 0x8004BEB4: nop

L_8004BEB8:
    // 0x8004BEB8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004BEBC: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004BEC0: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004BEC4: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004BEC8: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004BECC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004BED0: bne         $t8, $zero, L_8004BF08
    if (ctx->r24 != 0) {
        // 0x8004BED4: and         $t9, $t1, $at
        ctx->r25 = ctx->r9 & ctx->r1;
            goto L_8004BF08;
    }
    // 0x8004BED4: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8004BED8: bne         $t9, $zero, L_8004BF08
    if (ctx->r25 != 0) {
        // 0x8004BEDC: nop
    
            goto L_8004BF08;
    }
    // 0x8004BEDC: nop

L_8004BEE0:
    // 0x8004BEE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004BEE4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004BEE8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004BEEC: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8004BEF0: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8004BEF4: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8004BEF8: bne         $t6, $zero, L_8004BF08
    if (ctx->r14 != 0) {
        // 0x8004BEFC: and         $t7, $t3, $at
        ctx->r15 = ctx->r11 & ctx->r1;
            goto L_8004BF08;
    }
    // 0x8004BEFC: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8004BF00: beq         $t7, $zero, L_8004BFB8
    if (ctx->r15 == 0) {
        // 0x8004BF04: nop
    
            goto L_8004BFB8;
    }
    // 0x8004BF04: nop

L_8004BF08:
    // 0x8004BF08: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004BF0C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004BF10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BF14: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004BF18: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x8004BF1C: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x8004BF20: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004BF24: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004BF28: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8004BF2C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004BF30: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8004BF34: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004BF38: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004BF3C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004BF40: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004BF44: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004BF48: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004BF4C: bne         $t6, $zero, L_8004BF5C
    if (ctx->r14 != 0) {
        // 0x8004BF50: and         $t7, $t3, $at
        ctx->r15 = ctx->r11 & ctx->r1;
            goto L_8004BF5C;
    }
    // 0x8004BF50: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8004BF54: beq         $t7, $zero, L_8004BF64
    if (ctx->r15 == 0) {
        // 0x8004BF58: nop
    
            goto L_8004BF64;
    }
    // 0x8004BF58: nop

L_8004BF5C:
    // 0x8004BF5C: b           L_8004C2CC
    // 0x8004BF60: nop

        goto L_8004C2CC;
    // 0x8004BF60: nop

L_8004BF64:
    // 0x8004BF64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004BF68: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004BF6C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004BF70: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8004BF74: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004BF78: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8004BF7C: bne         $t4, $zero, L_8004BF8C
    if (ctx->r12 != 0) {
        // 0x8004BF80: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004BF8C;
    }
    // 0x8004BF80: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004BF84: beq         $t5, $zero, L_8004BFB0
    if (ctx->r13 == 0) {
        // 0x8004BF88: nop
    
            goto L_8004BFB0;
    }
    // 0x8004BF88: nop

L_8004BF8C:
    // 0x8004BF8C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004BF90: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004BF94: nop

    // 0x8004BF98: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004BF9C: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8004BFA0: ori         $t6, $t2, 0x1
    ctx->r14 = ctx->r10 | 0X1;
    // 0x8004BFA4: ori         $t7, $t3, 0x0
    ctx->r15 = ctx->r11 | 0X0;
    // 0x8004BFA8: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8004BFAC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_8004BFB0:
    // 0x8004BFB0: b           L_8004C300
    // 0x8004BFB4: nop

        goto L_8004C300;
    // 0x8004BFB4: nop

L_8004BFB8:
    // 0x8004BFB8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004BFBC: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004BFC0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004BFC4: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8004BFC8: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004BFCC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8004BFD0: bne         $t4, $zero, L_8004BFE0
    if (ctx->r12 != 0) {
        // 0x8004BFD4: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004BFE0;
    }
    // 0x8004BFD4: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004BFD8: beq         $t5, $zero, L_8004C018
    if (ctx->r13 == 0) {
        // 0x8004BFDC: nop
    
            goto L_8004C018;
    }
    // 0x8004BFDC: nop

L_8004BFE0:
    // 0x8004BFE0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004BFE4: jal         0x80054198
    // 0x8004BFE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80054198(rdram, ctx);
        goto after_13;
    // 0x8004BFE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x8004BFEC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004BFF0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004BFF4: nop

    // 0x8004BFF8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8004BFFC: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8004C000: ori         $t0, $t6, 0x1
    ctx->r8 = ctx->r14 | 0X1;
    // 0x8004C004: ori         $t1, $t7, 0x0
    ctx->r9 = ctx->r15 | 0X0;
    // 0x8004C008: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8004C00C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x8004C010: b           L_8004C300
    // 0x8004C014: nop

        goto L_8004C300;
    // 0x8004C014: nop

L_8004C018:
    // 0x8004C018: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004C01C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004C020: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004C024: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8004C028: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004C02C: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8004C030: bne         $t4, $zero, L_8004C040
    if (ctx->r12 != 0) {
        // 0x8004C034: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004C040;
    }
    // 0x8004C034: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004C038: beq         $t5, $zero, L_8004C078
    if (ctx->r13 == 0) {
        // 0x8004C03C: nop
    
            goto L_8004C078;
    }
    // 0x8004C03C: nop

L_8004C040:
    // 0x8004C040: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004C044: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C048: sh          $t6, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r14;
    // 0x8004C04C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004C050: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004C054: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C058: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8004C05C: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8004C060: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8004C064: lui         $at, 0xFDFF
    ctx->r1 = S32(0XFDFF << 16);
    // 0x8004C068: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004C06C: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004C070: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x8004C074: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
L_8004C078:
    // 0x8004C078: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004C07C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004C080: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C084: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x8004C088: nop

    // 0x8004C08C: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8004C090: jal         0x80054198
    // 0x8004C094: nop

    func_80054198(rdram, ctx);
        goto after_14;
    // 0x8004C094: nop

    after_14:
    // 0x8004C098: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004C09C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004C0A0: nop

    // 0x8004C0A4: lwc1        $f6, 0x6C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X6C);
    // 0x8004C0A8: nop

    // 0x8004C0AC: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x8004C0B0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8004C0B4: nop

    // 0x8004C0B8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004C0BC: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
L_8004C0C0:
    // 0x8004C0C0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004C0C4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004C0C8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004C0CC: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004C0D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004C0D4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004C0D8: bne         $t8, $zero, L_8004C0E8
    if (ctx->r24 != 0) {
        // 0x8004C0DC: and         $t9, $t3, $at
        ctx->r25 = ctx->r11 & ctx->r1;
            goto L_8004C0E8;
    }
    // 0x8004C0DC: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x8004C0E0: beq         $t9, $zero, L_8004C3E8
    if (ctx->r25 == 0) {
        // 0x8004C0E4: nop
    
            goto L_8004C3E8;
    }
    // 0x8004C0E4: nop

L_8004C0E8:
    // 0x8004C0E8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8004C0EC: nop

    // 0x8004C0F0: bne         $t1, $zero, L_8004C3E8
    if (ctx->r9 != 0) {
        // 0x8004C0F4: nop
    
            goto L_8004C3E8;
    }
    // 0x8004C0F4: nop

    // 0x8004C0F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004C0FC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004C100: nop

    // 0x8004C104: lw          $t4, 0x58($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X58);
    // 0x8004C108: nop

    // 0x8004C10C: lh          $t5, 0x1C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X1C);
    // 0x8004C110: nop

    // 0x8004C114: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8004C118: nop

    // 0x8004C11C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004C120: swc1        $f10, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f10.u32l;
    // 0x8004C124: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004C128: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004C12C: nop

    // 0x8004C130: lwc1        $f16, 0xC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8004C134: lwc1        $f18, 0x6C($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X6C);
    // 0x8004C138: nop

    // 0x8004C13C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8004C140: nop

    // 0x8004C144: bc1t        L_8004C314
    if (c1cs) {
        // 0x8004C148: nop
    
            goto L_8004C314;
    }
    // 0x8004C148: nop

    // 0x8004C14C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004C150: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004C154: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C158: lw          $a1, 0x6C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X6C);
    // 0x8004C15C: jal         0x80054198
    // 0x8004C160: nop

    func_80054198(rdram, ctx);
        goto after_15;
    // 0x8004C160: nop

    after_15:
    // 0x8004C164: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C168: jal         0x80054264
    // 0x8004C16C: nop

    func_80054264(rdram, ctx);
        goto after_16;
    // 0x8004C16C: nop

    after_16:
    // 0x8004C170: beq         $v0, $zero, L_8004C188
    if (ctx->r2 == 0) {
        // 0x8004C174: nop
    
            goto L_8004C188;
    }
    // 0x8004C174: nop

    // 0x8004C178: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C17C: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // 0x8004C180: jal         0x80052508
    // 0x8004C184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_17;
    // 0x8004C184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
L_8004C188:
    // 0x8004C188: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004C18C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004C190: nop

    // 0x8004C194: lw          $a0, 0x58($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X58);
    // 0x8004C198: jal         0x80056C60
    // 0x8004C19C: nop

    func_80056C60(rdram, ctx);
        goto after_18;
    // 0x8004C19C: nop

    after_18:
    // 0x8004C1A0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8004C1A4: sra         $t3, $s1, 16
    ctx->r11 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004C1A8: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8004C1AC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004C1B0: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004C1B4: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8004C1B8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8004C1BC: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8004C1C0: lh          $a2, 0x2C52($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X2C52);
    // 0x8004C1C4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C1C8: lw          $a1, 0x6C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X6C);
    // 0x8004C1CC: jal         0x80053580
    // 0x8004C1D0: nop

    func_80053580(rdram, ctx);
        goto after_19;
    // 0x8004C1D0: nop

    after_19:
    // 0x8004C1D4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004C1D8: lh          $t1, 0x10F0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X10F0);
    // 0x8004C1DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004C1E0: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C1E4: nop
    
            goto L_8004C250;
    }
    // 0x8004C1E4: nop

    // 0x8004C1E8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004C1EC: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C1F0: nop
    
            goto L_8004C250;
    }
    // 0x8004C1F0: nop

    // 0x8004C1F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C1F8: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C1FC: nop
    
            goto L_8004C250;
    }
    // 0x8004C1FC: nop

    // 0x8004C200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C204: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C208: nop
    
            goto L_8004C250;
    }
    // 0x8004C208: nop

    // 0x8004C20C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004C210: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C214: nop
    
            goto L_8004C250;
    }
    // 0x8004C214: nop

    // 0x8004C218: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004C21C: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C220: nop
    
            goto L_8004C250;
    }
    // 0x8004C220: nop

    // 0x8004C224: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004C228: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C22C: nop
    
            goto L_8004C250;
    }
    // 0x8004C22C: nop

    // 0x8004C230: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004C234: beq         $t1, $at, L_8004C250
    if (ctx->r9 == ctx->r1) {
        // 0x8004C238: nop
    
            goto L_8004C250;
    }
    // 0x8004C238: nop

    // 0x8004C23C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004C240: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8004C244: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004C248: bne         $t4, $at, L_8004C278
    if (ctx->r12 != ctx->r1) {
        // 0x8004C24C: nop
    
            goto L_8004C278;
    }
    // 0x8004C24C: nop

L_8004C250:
    // 0x8004C250: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004C254: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004C258: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004C25C: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004C260: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004C264: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004C268: bne         $t0, $zero, L_8004C2A0
    if (ctx->r8 != 0) {
        // 0x8004C26C: and         $t1, $t7, $at
        ctx->r9 = ctx->r15 & ctx->r1;
            goto L_8004C2A0;
    }
    // 0x8004C26C: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8004C270: bne         $t1, $zero, L_8004C2A0
    if (ctx->r9 != 0) {
        // 0x8004C274: nop
    
            goto L_8004C2A0;
    }
    // 0x8004C274: nop

L_8004C278:
    // 0x8004C278: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004C27C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004C280: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004C284: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004C288: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004C28C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004C290: bne         $t4, $zero, L_8004C2A0
    if (ctx->r12 != 0) {
        // 0x8004C294: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004C2A0;
    }
    // 0x8004C294: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004C298: beq         $t5, $zero, L_8004C314
    if (ctx->r13 == 0) {
        // 0x8004C29C: nop
    
            goto L_8004C314;
    }
    // 0x8004C29C: nop

L_8004C2A0:
    // 0x8004C2A0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004C2A4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004C2A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C2AC: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8004C2B0: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x8004C2B4: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8004C2B8: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8004C2BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004C2C0: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8004C2C4: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8004C2C8: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
L_8004C2CC:
    // 0x8004C2CC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004C2D0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004C2D4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004C2D8: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004C2DC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004C2E0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004C2E4: bne         $t4, $zero, L_8004C2F4
    if (ctx->r12 != 0) {
        // 0x8004C2E8: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004C2F4;
    }
    // 0x8004C2E8: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004C2EC: beq         $t5, $zero, L_8004C300
    if (ctx->r13 == 0) {
        // 0x8004C2F0: nop
    
            goto L_8004C300;
    }
    // 0x8004C2F0: nop

L_8004C2F4:
    // 0x8004C2F4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C2F8: jal         0x80054618
    // 0x8004C2FC: nop

    func_80054618(rdram, ctx);
        goto after_20;
    // 0x8004C2FC: nop

    after_20:
L_8004C300:
    // 0x8004C300: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004C304: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C308: sh          $t6, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r14;
    // 0x8004C30C: b           L_8004D6F4
    // 0x8004C310: nop

        goto L_8004D6F4;
    // 0x8004C310: nop

L_8004C314:
    // 0x8004C314: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004C318: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004C31C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004C320: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8004C324: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004C328: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8004C32C: bne         $t2, $zero, L_8004C33C
    if (ctx->r10 != 0) {
        // 0x8004C330: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004C33C;
    }
    // 0x8004C330: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004C334: beq         $t3, $zero, L_8004C374
    if (ctx->r11 == 0) {
        // 0x8004C338: nop
    
            goto L_8004C374;
    }
    // 0x8004C338: nop

L_8004C33C:
    // 0x8004C33C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004C340: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C344: sh          $t8, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r24;
    // 0x8004C348: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004C34C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004C350: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C354: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8004C358: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8004C35C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8004C360: lui         $at, 0xFDFF
    ctx->r1 = S32(0XFDFF << 16);
    // 0x8004C364: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004C368: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004C36C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8004C370: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
L_8004C374:
    // 0x8004C374: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004C378: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004C37C: nop

    // 0x8004C380: lw          $a0, 0x58($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X58);
    // 0x8004C384: jal         0x80056C60
    // 0x8004C388: nop

    func_80056C60(rdram, ctx);
        goto after_21;
    // 0x8004C388: nop

    after_21:
    // 0x8004C38C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8004C390: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004C394: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8004C398: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    // 0x8004C39C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8004C3A0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004C3A4: lh          $t3, 0x2C54($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2C54);
    // 0x8004C3A8: nop

    // 0x8004C3AC: beq         $t3, $zero, L_8004C3D8
    if (ctx->r11 == 0) {
        // 0x8004C3B0: nop
    
            goto L_8004C3D8;
    }
    // 0x8004C3B0: nop

    // 0x8004C3B4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004C3B8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004C3BC: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x8004C3C0: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8004C3C4: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8004C3C8: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x8004C3CC: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8004C3D0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8004C3D4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_8004C3D8:
    // 0x8004C3D8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8004C3DC: nop

    // 0x8004C3E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8004C3E4: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
L_8004C3E8:
    // 0x8004C3E8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8004C3EC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8004C3F0: nop

    // 0x8004C3F4: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x8004C3F8: lh          $t2, 0x2F5($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2F5);
    // 0x8004C3FC: nop

    // 0x8004C400: bne         $t2, $zero, L_8004C44C
    if (ctx->r10 != 0) {
        // 0x8004C404: nop
    
            goto L_8004C44C;
    }
    // 0x8004C404: nop

    // 0x8004C408: lhu         $t3, 0x50($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C40C: nop

    // 0x8004C410: andi        $t4, $t3, 0x4000
    ctx->r12 = ctx->r11 & 0X4000;
    // 0x8004C414: bne         $t4, $zero, L_8004C44C
    if (ctx->r12 != 0) {
        // 0x8004C418: nop
    
            goto L_8004C44C;
    }
    // 0x8004C418: nop

    // 0x8004C41C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004C420: lw          $t5, 0x640($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X640);
    // 0x8004C424: nop

    // 0x8004C428: lbu         $t6, 0xA($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XA);
    // 0x8004C42C: nop

    // 0x8004C430: bne         $t6, $zero, L_8004C44C
    if (ctx->r14 != 0) {
        // 0x8004C434: nop
    
            goto L_8004C44C;
    }
    // 0x8004C434: nop

    // 0x8004C438: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8004C43C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C440: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
    // 0x8004C444: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004C448: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_8004C44C:
    // 0x8004C44C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C450: lhu         $a1, 0x50($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C454: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8004C458: jal         0x80051804
    // 0x8004C45C: nop

    func_80051804(rdram, ctx);
        goto after_22;
    // 0x8004C45C: nop

    after_22:
    // 0x8004C460: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8004C464: nop

    // 0x8004C468: blez        $t9, L_8004C484
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8004C46C: nop
    
            goto L_8004C484;
    }
    // 0x8004C46C: nop

    // 0x8004C470: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8004C474: jal         0x800B9000
    // 0x8004C478: nop

    func_800B9000(rdram, ctx);
        goto after_23;
    // 0x8004C478: nop

    after_23:
    // 0x8004C47C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004C480: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_8004C484:
    // 0x8004C484: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C488: sw          $zero, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = 0;
    // 0x8004C48C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004C490: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004C494: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004C498: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8004C49C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004C4A0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004C4A4: bne         $t4, $zero, L_8004C4B4
    if (ctx->r12 != 0) {
        // 0x8004C4A8: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8004C4B4;
    }
    // 0x8004C4A8: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004C4AC: beq         $t5, $zero, L_8004C4F0
    if (ctx->r13 == 0) {
        // 0x8004C4B0: nop
    
            goto L_8004C4F0;
    }
    // 0x8004C4B0: nop

L_8004C4B4:
    // 0x8004C4B4: lhu         $a0, 0x50($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C4B8: jal         0x80056E88
    // 0x8004C4BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_24;
    // 0x8004C4BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x8004C4C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004C4C4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004C4C8: nop

    // 0x8004C4CC: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x8004C4D0: nop

    // 0x8004C4D4: bne         $v0, $t7, L_8004C4F0
    if (ctx->r2 != ctx->r15) {
        // 0x8004C4D8: nop
    
            goto L_8004C4F0;
    }
    // 0x8004C4D8: nop

    // 0x8004C4DC: lhu         $t8, 0x50($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C4E0: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x8004C4E4: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x8004C4E8: beq         $t9, $at, L_8004C53C
    if (ctx->r25 == ctx->r1) {
        // 0x8004C4EC: nop
    
            goto L_8004C53C;
    }
    // 0x8004C4EC: nop

L_8004C4F0:
    // 0x8004C4F0: lhu         $a0, 0x50($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C4F4: jal         0x80056E88
    // 0x8004C4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_25;
    // 0x8004C4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8004C4FC: lhu         $t1, 0x50($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C500: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8004C504: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004C508: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8004C50C: beq         $t2, $zero, L_8004C51C
    if (ctx->r10 == 0) {
        // 0x8004C510: or          $s1, $t0, $zero
        ctx->r17 = ctx->r8 | 0;
            goto L_8004C51C;
    }
    // 0x8004C510: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8004C514: b           L_8004C520
    // 0x8004C518: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_8004C520;
    // 0x8004C518: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8004C51C:
    // 0x8004C51C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8004C520:
    // 0x8004C520: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004C524: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004C528: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8004C52C: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x8004C530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C534: jal         0x8004EF90
    // 0x8004C538: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8004EF90(rdram, ctx);
        goto after_26;
    // 0x8004C538: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_26:
L_8004C53C:
    // 0x8004C53C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004C540: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004C544: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004C548: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004C54C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004C550: bne         $t8, $zero, L_8004C560
    if (ctx->r24 != 0) {
        // 0x8004C554: andi        $t9, $t7, 0x8000
        ctx->r25 = ctx->r15 & 0X8000;
            goto L_8004C560;
    }
    // 0x8004C554: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x8004C558: beq         $t9, $zero, L_8004C588
    if (ctx->r25 == 0) {
        // 0x8004C55C: nop
    
            goto L_8004C588;
    }
    // 0x8004C55C: nop

L_8004C560:
    // 0x8004C560: lwl         $t5, 0x50($sp)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r29, 0X50);
    // 0x8004C564: lwr         $t5, 0x53($sp)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r29, 0X53);
    // 0x8004C568: nop

    // 0x8004C56C: swl         $t5, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r13);
    // 0x8004C570: swr         $t5, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r13);
    // 0x8004C574: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8004C578: jal         0x80056590
    // 0x8004C57C: nop

    func_80056590(rdram, ctx);
        goto after_27;
    // 0x8004C57C: nop

    after_27:
    // 0x8004C580: jal         0x80056848
    // 0x8004C584: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80056848(rdram, ctx);
        goto after_28;
    // 0x8004C584: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_28:
L_8004C588:
    // 0x8004C588: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8004C58C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C590: addiu       $a2, $t0, 0x7FFF
    ctx->r6 = ADD32(ctx->r8, 0X7FFF);
    // 0x8004C594: lh          $a2, 0x2F3($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X2F3);
    // 0x8004C598: jal         0x8005031C
    // 0x8004C59C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8005031C(rdram, ctx);
        goto after_29;
    // 0x8004C59C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_29:
    // 0x8004C5A0: beq         $v0, $zero, L_8004C5B0
    if (ctx->r2 == 0) {
        // 0x8004C5A4: nop
    
            goto L_8004C5B0;
    }
    // 0x8004C5A4: nop

    // 0x8004C5A8: b           L_8004D448
    // 0x8004C5AC: nop

        goto L_8004D448;
    // 0x8004C5AC: nop

L_8004C5B0:
    // 0x8004C5B0: b           L_8004C5FC
    // 0x8004C5B4: nop

        goto L_8004C5FC;
    // 0x8004C5B4: nop

L_8004C5B8:
    // 0x8004C5B8: lhu         $t1, 0x50($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C5BC: nop

    // 0x8004C5C0: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8004C5C4: beq         $t2, $zero, L_8004C5D4
    if (ctx->r10 == 0) {
        // 0x8004C5C8: nop
    
            goto L_8004C5D4;
    }
    // 0x8004C5C8: nop

    // 0x8004C5CC: b           L_8004C5D8
    // 0x8004C5D0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_8004C5D8;
    // 0x8004C5D0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8004C5D4:
    // 0x8004C5D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8004C5D8:
    // 0x8004C5D8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8004C5DC: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8004C5E0: lh          $a1, 0x7C($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X7C);
    // 0x8004C5E4: lw          $a3, 0x44($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X44);
    // 0x8004C5E8: lhu         $a2, 0x50($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X50);
    // 0x8004C5EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004C5F0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8004C5F4: jal         0x8004F3E8
    // 0x8004C5F8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_8004F3E8(rdram, ctx);
        goto after_30;
    // 0x8004C5F8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_30:
L_8004C5FC:
    // 0x8004C5FC: lh          $t6, 0x52($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X52);
    // 0x8004C600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C604: beq         $t6, $at, L_8004C778
    if (ctx->r14 == ctx->r1) {
        // 0x8004C608: nop
    
            goto L_8004C778;
    }
    // 0x8004C608: nop

    // 0x8004C60C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8004C610: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004C614: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8004C618: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004C61C: bne         $t0, $zero, L_8004C62C
    if (ctx->r8 != 0) {
        // 0x8004C620: andi        $t1, $t9, 0x400
        ctx->r9 = ctx->r25 & 0X400;
            goto L_8004C62C;
    }
    // 0x8004C620: andi        $t1, $t9, 0x400
    ctx->r9 = ctx->r25 & 0X400;
    // 0x8004C624: beq         $t1, $zero, L_8004C6A4
    if (ctx->r9 == 0) {
        // 0x8004C628: nop
    
            goto L_8004C6A4;
    }
    // 0x8004C628: nop

L_8004C62C:
    // 0x8004C62C: addiu       $t5, $zero, 0x258
    ctx->r13 = ADD32(0, 0X258);
    // 0x8004C630: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C634: sw          $t5, 0xCD4($at)
    MEM_W(0XCD4, ctx->r1) = ctx->r13;
    // 0x8004C638: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8004C63C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8004C640: jal         0x800B334C
    // 0x8004C644: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_31;
    // 0x8004C644: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_31:
    // 0x8004C648: andi        $t2, $v0, 0x1000
    ctx->r10 = ctx->r2 & 0X1000;
    // 0x8004C64C: bne         $t2, $zero, L_8004C6A4
    if (ctx->r10 != 0) {
        // 0x8004C650: nop
    
            goto L_8004C6A4;
    }
    // 0x8004C650: nop

    // 0x8004C654: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004C658: lw          $t3, 0xCD4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XCD4);
    // 0x8004C65C: nop

    // 0x8004C660: beq         $t3, $zero, L_8004C6A4
    if (ctx->r11 == 0) {
        // 0x8004C664: nop
    
            goto L_8004C6A4;
    }
    // 0x8004C664: nop

L_8004C668:
    // 0x8004C668: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C66C: jal         0x800499B0
    // 0x8004C670: nop

    func_800499B0(rdram, ctx);
        goto after_32;
    // 0x8004C670: nop

    after_32:
    // 0x8004C674: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8004C678: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8004C67C: jal         0x800B334C
    // 0x8004C680: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_33;
    // 0x8004C680: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_33:
    // 0x8004C684: andi        $t4, $v0, 0x1000
    ctx->r12 = ctx->r2 & 0X1000;
    // 0x8004C688: bne         $t4, $zero, L_8004C6A4
    if (ctx->r12 != 0) {
        // 0x8004C68C: nop
    
            goto L_8004C6A4;
    }
    // 0x8004C68C: nop

    // 0x8004C690: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004C694: lw          $t6, 0xCD4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCD4);
    // 0x8004C698: nop

    // 0x8004C69C: bne         $t6, $zero, L_8004C668
    if (ctx->r14 != 0) {
        // 0x8004C6A0: nop
    
            goto L_8004C668;
    }
    // 0x8004C6A0: nop

L_8004C6A4:
    // 0x8004C6A4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8004C6A8: nop

    // 0x8004C6AC: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x8004C6B0: lh          $t8, 0x2F3($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2F3);
    // 0x8004C6B4: nop

    // 0x8004C6B8: beq         $t8, $zero, L_8004C6CC
    if (ctx->r24 == 0) {
        // 0x8004C6BC: nop
    
            goto L_8004C6CC;
    }
    // 0x8004C6BC: nop

    // 0x8004C6C0: lh          $s0, 0x52($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X52);
    // 0x8004C6C4: b           L_8004C6D4
    // 0x8004C6C8: addiu       $s0, $s0, 0x2710
    ctx->r16 = ADD32(ctx->r16, 0X2710);
        goto L_8004C6D4;
    // 0x8004C6C8: addiu       $s0, $s0, 0x2710
    ctx->r16 = ADD32(ctx->r16, 0X2710);
L_8004C6CC:
    // 0x8004C6CC: lh          $s0, 0x52($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X52);
    // 0x8004C6D0: nop

L_8004C6D4:
    // 0x8004C6D4: jal         0x80062678
    // 0x8004C6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80062678(rdram, ctx);
        goto after_34;
    // 0x8004C6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8004C6DC: addiu       $t9, $zero, 0x258
    ctx->r25 = ADD32(0, 0X258);
    // 0x8004C6E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C6E4: sw          $t9, 0xCD4($at)
    MEM_W(0XCD4, ctx->r1) = ctx->r25;
    // 0x8004C6E8: jal         0x80031AC8
    // 0x8004C6EC: nop

    func_80031AC8(rdram, ctx);
        goto after_35;
    // 0x8004C6EC: nop

    after_35:
    // 0x8004C6F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C6F4: beq         $v0, $at, L_8004C744
    if (ctx->r2 == ctx->r1) {
        // 0x8004C6F8: nop
    
            goto L_8004C744;
    }
    // 0x8004C6F8: nop

    // 0x8004C6FC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004C700: lw          $t0, 0xCD4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCD4);
    // 0x8004C704: nop

    // 0x8004C708: beq         $t0, $zero, L_8004C744
    if (ctx->r8 == 0) {
        // 0x8004C70C: nop
    
            goto L_8004C744;
    }
    // 0x8004C70C: nop

L_8004C710:
    // 0x8004C710: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C714: jal         0x800499B0
    // 0x8004C718: nop

    func_800499B0(rdram, ctx);
        goto after_36;
    // 0x8004C718: nop

    after_36:
    // 0x8004C71C: jal         0x80031AC8
    // 0x8004C720: nop

    func_80031AC8(rdram, ctx);
        goto after_37;
    // 0x8004C720: nop

    after_37:
    // 0x8004C724: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C728: beq         $v0, $at, L_8004C744
    if (ctx->r2 == ctx->r1) {
        // 0x8004C72C: nop
    
            goto L_8004C744;
    }
    // 0x8004C72C: nop

    // 0x8004C730: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004C734: lw          $t1, 0xCD4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCD4);
    // 0x8004C738: nop

    // 0x8004C73C: bne         $t1, $zero, L_8004C710
    if (ctx->r9 != 0) {
        // 0x8004C740: nop
    
            goto L_8004C710;
    }
    // 0x8004C740: nop

L_8004C744:
    // 0x8004C744: jal         0x80031AC8
    // 0x8004C748: nop

    func_80031AC8(rdram, ctx);
        goto after_38;
    // 0x8004C748: nop

    after_38:
    // 0x8004C74C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C750: bne         $v0, $at, L_8004C778
    if (ctx->r2 != ctx->r1) {
        // 0x8004C754: nop
    
            goto L_8004C778;
    }
    // 0x8004C754: nop

L_8004C758:
    // 0x8004C758: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C75C: jal         0x800499B0
    // 0x8004C760: nop

    func_800499B0(rdram, ctx);
        goto after_39;
    // 0x8004C760: nop

    after_39:
    // 0x8004C764: jal         0x80031AC8
    // 0x8004C768: nop

    func_80031AC8(rdram, ctx);
        goto after_40;
    // 0x8004C768: nop

    after_40:
    // 0x8004C76C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C770: beq         $v0, $at, L_8004C758
    if (ctx->r2 == ctx->r1) {
        // 0x8004C774: nop
    
            goto L_8004C758;
    }
    // 0x8004C774: nop

L_8004C778:
    // 0x8004C778: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004C77C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004C780: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8004C784: nop

    // 0x8004C788: bne         $t5, $t2, L_8004CB98
    if (ctx->r13 != ctx->r10) {
        // 0x8004C78C: nop
    
            goto L_8004CB98;
    }
    // 0x8004C78C: nop

    // 0x8004C790: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8004C794: nop

    // 0x8004C798: beq         $t3, $zero, L_8004CB98
    if (ctx->r11 == 0) {
        // 0x8004C79C: nop
    
            goto L_8004CB98;
    }
    // 0x8004C79C: nop

    // 0x8004C7A0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C7A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004C7A8: jal         0x80052508
    // 0x8004C7AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_41;
    // 0x8004C7AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_41:
    // 0x8004C7B0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8004C7B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C7B8: sh          $t4, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r12;
    // 0x8004C7BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004C7C0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004C7C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004C7C8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004C7CC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004C7D0: bne         $t0, $zero, L_8004C7E0
    if (ctx->r8 != 0) {
        // 0x8004C7D4: andi        $t1, $t9, 0x10
        ctx->r9 = ctx->r25 & 0X10;
            goto L_8004C7E0;
    }
    // 0x8004C7D4: andi        $t1, $t9, 0x10
    ctx->r9 = ctx->r25 & 0X10;
    // 0x8004C7D8: beq         $t1, $zero, L_8004C804
    if (ctx->r9 == 0) {
        // 0x8004C7DC: nop
    
            goto L_8004C804;
    }
    // 0x8004C7DC: nop

L_8004C7E0:
    // 0x8004C7E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004C7E4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004C7E8: nop

    // 0x8004C7EC: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8004C7F0: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8004C7F4: ori         $t4, $t2, 0x4
    ctx->r12 = ctx->r10 | 0X4;
    // 0x8004C7F8: ori         $t5, $t3, 0x0
    ctx->r13 = ctx->r11 | 0X0;
    // 0x8004C7FC: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8004C800: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
L_8004C804:
    // 0x8004C804: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C808: sb          $zero, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = 0;
    // 0x8004C80C: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x8004C810: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C814: sw          $t6, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r14;
L_8004C818:
    // 0x8004C818: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C81C: jal         0x800499B0
    // 0x8004C820: nop

    func_800499B0(rdram, ctx);
        goto after_42;
    // 0x8004C820: nop

    after_42:
    // 0x8004C824: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004C828: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004C82C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004C830: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004C834: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004C838: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004C83C: bne         $t2, $zero, L_8004C864
    if (ctx->r10 != 0) {
        // 0x8004C840: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004C864;
    }
    // 0x8004C840: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004C844: bne         $t3, $zero, L_8004C864
    if (ctx->r11 != 0) {
        // 0x8004C848: nop
    
            goto L_8004C864;
    }
    // 0x8004C848: nop

    // 0x8004C84C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004C850: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004C854: bne         $t4, $zero, L_8004C864
    if (ctx->r12 != 0) {
        // 0x8004C858: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_8004C864;
    }
    // 0x8004C858: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004C85C: beq         $t5, $zero, L_8004C870
    if (ctx->r13 == 0) {
        // 0x8004C860: nop
    
            goto L_8004C870;
    }
    // 0x8004C860: nop

L_8004C864:
    // 0x8004C864: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C868: jal         0x8004F8CC
    // 0x8004C86C: nop

    func_8004F8CC(rdram, ctx);
        goto after_43;
    // 0x8004C86C: nop

    after_43:
L_8004C870:
    // 0x8004C870: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004C874: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004C878: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004C87C: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004C880: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004C884: bne         $t8, $zero, L_8004C894
    if (ctx->r24 != 0) {
        // 0x8004C888: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_8004C894;
    }
    // 0x8004C888: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8004C88C: beq         $t9, $zero, L_8004C8C8
    if (ctx->r25 == 0) {
        // 0x8004C890: nop
    
            goto L_8004C8C8;
    }
    // 0x8004C890: nop

L_8004C894:
    // 0x8004C894: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C898: jal         0x80051700
    // 0x8004C89C: nop

    func_80051700(rdram, ctx);
        goto after_44;
    // 0x8004C89C: nop

    after_44:
    // 0x8004C8A0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004C8A4: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004C8A8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8004C8AC: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004C8B0: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8004C8B4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8004C8B8: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x8004C8BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C8C0: jal         0x8004EF90
    // 0x8004C8C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_45;
    // 0x8004C8C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_45:
L_8004C8C8:
    // 0x8004C8C8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004C8CC: lw          $t0, 0x6CC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CC);
    // 0x8004C8D0: nop

    // 0x8004C8D4: beq         $t0, $zero, L_8004C914
    if (ctx->r8 == 0) {
        // 0x8004C8D8: nop
    
            goto L_8004C914;
    }
    // 0x8004C8D8: nop

    // 0x8004C8DC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004C8E0: lh          $t1, 0x10F0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X10F0);
    // 0x8004C8E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004C8E8: bne         $t1, $at, L_8004C914
    if (ctx->r9 != ctx->r1) {
        // 0x8004C8EC: nop
    
            goto L_8004C914;
    }
    // 0x8004C8EC: nop

    // 0x8004C8F0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8004C8F4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004C8F8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004C8FC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004C900: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004C904: bne         $t8, $zero, L_8004C914
    if (ctx->r24 != 0) {
        // 0x8004C908: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004C914;
    }
    // 0x8004C908: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004C90C: beq         $t9, $zero, L_8004C818
    if (ctx->r25 == 0) {
        // 0x8004C910: nop
    
            goto L_8004C818;
    }
    // 0x8004C910: nop

L_8004C914:
    // 0x8004C914: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004C918: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x8004C91C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004C920: beq         $t5, $at, L_8004CB0C
    if (ctx->r13 == ctx->r1) {
        // 0x8004C924: nop
    
            goto L_8004CB0C;
    }
    // 0x8004C924: nop

    // 0x8004C928: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004C92C: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x8004C930: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004C934: beq         $t2, $at, L_8004CA5C
    if (ctx->r10 == ctx->r1) {
        // 0x8004C938: nop
    
            goto L_8004CA5C;
    }
    // 0x8004C938: nop

    // 0x8004C93C: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8004C940: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C944: sw          $t3, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r11;
L_8004C948:
    // 0x8004C948: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C94C: jal         0x800499B0
    // 0x8004C950: nop

    func_800499B0(rdram, ctx);
        goto after_46;
    // 0x8004C950: nop

    after_46:
    // 0x8004C954: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004C958: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004C95C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004C960: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8004C964: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004C968: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8004C96C: bne         $t6, $zero, L_8004C994
    if (ctx->r14 != 0) {
        // 0x8004C970: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_8004C994;
    }
    // 0x8004C970: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004C974: bne         $t7, $zero, L_8004C994
    if (ctx->r15 != 0) {
        // 0x8004C978: nop
    
            goto L_8004C994;
    }
    // 0x8004C978: nop

    // 0x8004C97C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004C980: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004C984: bne         $t8, $zero, L_8004C994
    if (ctx->r24 != 0) {
        // 0x8004C988: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_8004C994;
    }
    // 0x8004C988: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x8004C98C: beq         $t9, $zero, L_8004C9A0
    if (ctx->r25 == 0) {
        // 0x8004C990: nop
    
            goto L_8004C9A0;
    }
    // 0x8004C990: nop

L_8004C994:
    // 0x8004C994: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C998: jal         0x8004F8CC
    // 0x8004C99C: nop

    func_8004F8CC(rdram, ctx);
        goto after_47;
    // 0x8004C99C: nop

    after_47:
L_8004C9A0:
    // 0x8004C9A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004C9A4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004C9A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004C9AC: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8004C9B0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004C9B4: bne         $t0, $zero, L_8004C9C4
    if (ctx->r8 != 0) {
        // 0x8004C9B8: andi        $t1, $t3, 0x2
        ctx->r9 = ctx->r11 & 0X2;
            goto L_8004C9C4;
    }
    // 0x8004C9B8: andi        $t1, $t3, 0x2
    ctx->r9 = ctx->r11 & 0X2;
    // 0x8004C9BC: beq         $t1, $zero, L_8004C9F8
    if (ctx->r9 == 0) {
        // 0x8004C9C0: nop
    
            goto L_8004C9F8;
    }
    // 0x8004C9C0: nop

L_8004C9C4:
    // 0x8004C9C4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004C9C8: jal         0x80051700
    // 0x8004C9CC: nop

    func_80051700(rdram, ctx);
        goto after_48;
    // 0x8004C9CC: nop

    after_48:
    // 0x8004C9D0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004C9D4: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004C9D8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8004C9DC: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004C9E0: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8004C9E4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8004C9E8: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x8004C9EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C9F0: jal         0x8004EF90
    // 0x8004C9F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_49;
    // 0x8004C9F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_49:
L_8004C9F8:
    // 0x8004C9F8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004C9FC: lw          $t4, 0x6CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6CC);
    // 0x8004CA00: nop

    // 0x8004CA04: beq         $t4, $zero, L_8004CA5C
    if (ctx->r12 == 0) {
        // 0x8004CA08: nop
    
            goto L_8004CA5C;
    }
    // 0x8004CA08: nop

    // 0x8004CA0C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004CA10: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x8004CA14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004CA18: beq         $t5, $at, L_8004CA5C
    if (ctx->r13 == ctx->r1) {
        // 0x8004CA1C: nop
    
            goto L_8004CA5C;
    }
    // 0x8004CA1C: nop

    // 0x8004CA20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004CA24: beq         $t5, $at, L_8004CA5C
    if (ctx->r13 == ctx->r1) {
        // 0x8004CA28: nop
    
            goto L_8004CA5C;
    }
    // 0x8004CA28: nop

    // 0x8004CA2C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004CA30: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004CA34: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8004CA38: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004CA3C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8004CA40: bne         $t0, $zero, L_8004CA5C
    if (ctx->r8 != 0) {
        // 0x8004CA44: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_8004CA5C;
    }
    // 0x8004CA44: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004CA48: bne         $t1, $zero, L_8004CA5C
    if (ctx->r9 != 0) {
        // 0x8004CA4C: nop
    
            goto L_8004CA5C;
    }
    // 0x8004CA4C: nop

    // 0x8004CA50: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004CA54: bne         $t5, $at, L_8004C948
    if (ctx->r13 != ctx->r1) {
        // 0x8004CA58: nop
    
            goto L_8004C948;
    }
    // 0x8004CA58: nop

L_8004CA5C:
    // 0x8004CA5C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004CA60: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x8004CA64: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004CA68: bne         $t9, $at, L_8004CA8C
    if (ctx->r25 != ctx->r1) {
        // 0x8004CA6C: nop
    
            goto L_8004CA8C;
    }
    // 0x8004CA6C: nop

    // 0x8004CA70: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8004CA74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004CA78: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x8004CA7C: jal         0x800B9000
    // 0x8004CA80: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800B9000(rdram, ctx);
        goto after_50;
    // 0x8004CA80: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_50:
    // 0x8004CA84: b           L_8004CB04
    // 0x8004CA88: nop

        goto L_8004CB04;
    // 0x8004CA88: nop

L_8004CA8C:
    // 0x8004CA8C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CA90: jal         0x800499B0
    // 0x8004CA94: nop

    func_800499B0(rdram, ctx);
        goto after_51;
    // 0x8004CA94: nop

    after_51:
    // 0x8004CA98: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004CA9C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004CAA0: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004CAA4: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x8004CAA8: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x8004CAAC: bne         $t8, $zero, L_8004CABC
    if (ctx->r24 != 0) {
        // 0x8004CAB0: andi        $t9, $t5, 0x2
        ctx->r25 = ctx->r13 & 0X2;
            goto L_8004CABC;
    }
    // 0x8004CAB0: andi        $t9, $t5, 0x2
    ctx->r25 = ctx->r13 & 0X2;
    // 0x8004CAB4: beq         $t9, $zero, L_8004CAF0
    if (ctx->r25 == 0) {
        // 0x8004CAB8: nop
    
            goto L_8004CAF0;
    }
    // 0x8004CAB8: nop

L_8004CABC:
    // 0x8004CABC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CAC0: jal         0x80051700
    // 0x8004CAC4: nop

    func_80051700(rdram, ctx);
        goto after_52;
    // 0x8004CAC4: nop

    after_52:
    // 0x8004CAC8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004CACC: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004CAD0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8004CAD4: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004CAD8: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8004CADC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8004CAE0: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x8004CAE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CAE8: jal         0x8004EF90
    // 0x8004CAEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_53;
    // 0x8004CAEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_53:
L_8004CAF0:
    // 0x8004CAF0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004CAF4: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x8004CAF8: nop

    // 0x8004CAFC: bne         $t0, $zero, L_8004CA8C
    if (ctx->r8 != 0) {
        // 0x8004CB00: nop
    
            goto L_8004CA8C;
    }
    // 0x8004CB00: nop

L_8004CB04:
    // 0x8004CB04: b           L_8004CB20
    // 0x8004CB08: nop

        goto L_8004CB20;
    // 0x8004CB08: nop

L_8004CB0C:
    // 0x8004CB0C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8004CB10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004CB14: sh          $t1, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r9;
    // 0x8004CB18: jal         0x800B9000
    // 0x8004CB1C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800B9000(rdram, ctx);
        goto after_54;
    // 0x8004CB1C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_54:
L_8004CB20:
    // 0x8004CB20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004CB24: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004CB28: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004CB2C: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x8004CB30: nop

    // 0x8004CB34: sb          $t6, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r14;
    // 0x8004CB38: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004CB3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004CB40: sh          $t4, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r12;
    // 0x8004CB44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004CB48: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x8004CB4C: jal         0x80031AC8
    // 0x8004CB50: nop

    func_80031AC8(rdram, ctx);
        goto after_55;
    // 0x8004CB50: nop

    after_55:
    // 0x8004CB54: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CB58: beq         $v0, $at, L_8004CB8C
    if (ctx->r2 == ctx->r1) {
        // 0x8004CB5C: nop
    
            goto L_8004CB8C;
    }
    // 0x8004CB5C: nop

    // 0x8004CB60: jal         0x80031BB0
    // 0x8004CB64: nop

    func_80031BB0(rdram, ctx);
        goto after_56;
    // 0x8004CB64: nop

    after_56:
    // 0x8004CB68: beq         $v0, $zero, L_8004CB8C
    if (ctx->r2 == 0) {
        // 0x8004CB6C: nop
    
            goto L_8004CB8C;
    }
    // 0x8004CB6C: nop

L_8004CB70:
    // 0x8004CB70: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CB74: jal         0x800499B0
    // 0x8004CB78: nop

    func_800499B0(rdram, ctx);
        goto after_57;
    // 0x8004CB78: nop

    after_57:
    // 0x8004CB7C: jal         0x80031BB0
    // 0x8004CB80: nop

    func_80031BB0(rdram, ctx);
        goto after_58;
    // 0x8004CB80: nop

    after_58:
    // 0x8004CB84: bne         $v0, $zero, L_8004CB70
    if (ctx->r2 != 0) {
        // 0x8004CB88: nop
    
            goto L_8004CB70;
    }
    // 0x8004CB88: nop

L_8004CB8C:
    // 0x8004CB8C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004CB90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004CB94: sb          $t5, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = ctx->r13;
L_8004CB98:
    // 0x8004CB98: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004CB9C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004CBA0: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8004CBA4: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8004CBA8: bne         $t0, $zero, L_8004CBB8
    if (ctx->r8 != 0) {
        // 0x8004CBAC: andi        $t1, $t3, 0x100
        ctx->r9 = ctx->r11 & 0X100;
            goto L_8004CBB8;
    }
    // 0x8004CBAC: andi        $t1, $t3, 0x100
    ctx->r9 = ctx->r11 & 0X100;
    // 0x8004CBB0: beq         $t1, $zero, L_8004CD68
    if (ctx->r9 == 0) {
        // 0x8004CBB4: nop
    
            goto L_8004CD68;
    }
    // 0x8004CBB4: nop

L_8004CBB8:
    // 0x8004CBB8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004CBBC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004CBC0: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004CBC4: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x8004CBC8: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004CBCC: bne         $t4, $zero, L_8004CBDC
    if (ctx->r12 != 0) {
        // 0x8004CBD0: and         $t5, $t7, $at
        ctx->r13 = ctx->r15 & ctx->r1;
            goto L_8004CBDC;
    }
    // 0x8004CBD0: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x8004CBD4: beq         $t5, $zero, L_8004CC78
    if (ctx->r13 == 0) {
        // 0x8004CBD8: nop
    
            goto L_8004CC78;
    }
    // 0x8004CBD8: nop

L_8004CBDC:
    // 0x8004CBDC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004CBE0: nop

    // 0x8004CBE4: lh          $a0, 0x4A($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4A);
    // 0x8004CBE8: jal         0x8004F66C
    // 0x8004CBEC: nop

    func_8004F66C(rdram, ctx);
        goto after_59;
    // 0x8004CBEC: nop

    after_59:
    // 0x8004CBF0: beq         $v0, $zero, L_8004CC14
    if (ctx->r2 == 0) {
        // 0x8004CBF4: nop
    
            goto L_8004CC14;
    }
    // 0x8004CBF4: nop

L_8004CBF8:
    // 0x8004CBF8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CBFC: jal         0x800499B0
    // 0x8004CC00: nop

    func_800499B0(rdram, ctx);
        goto after_60;
    // 0x8004CC00: nop

    after_60:
    // 0x8004CC04: b           L_8004CBF8
    // 0x8004CC08: nop

        goto L_8004CBF8;
    // 0x8004CC08: nop

    // 0x8004CC0C: b           L_8004CC70
    // 0x8004CC10: nop

        goto L_8004CC70;
    // 0x8004CC10: nop

L_8004CC14:
    // 0x8004CC14: jal         0x80031AC8
    // 0x8004CC18: nop

    func_80031AC8(rdram, ctx);
        goto after_61;
    // 0x8004CC18: nop

    after_61:
    // 0x8004CC1C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CC20: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8004CC24: nop

    // 0x8004CC28: beq         $t2, $zero, L_8004CC70
    if (ctx->r10 == 0) {
        // 0x8004CC2C: nop
    
            goto L_8004CC70;
    }
    // 0x8004CC2C: nop

    // 0x8004CC30: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CC34: beq         $t2, $at, L_8004CC70
    if (ctx->r10 == ctx->r1) {
        // 0x8004CC38: nop
    
            goto L_8004CC70;
    }
    // 0x8004CC38: nop

L_8004CC3C:
    // 0x8004CC3C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CC40: jal         0x800499B0
    // 0x8004CC44: nop

    func_800499B0(rdram, ctx);
        goto after_62;
    // 0x8004CC44: nop

    after_62:
    // 0x8004CC48: jal         0x80031AC8
    // 0x8004CC4C: nop

    func_80031AC8(rdram, ctx);
        goto after_63;
    // 0x8004CC4C: nop

    after_63:
    // 0x8004CC50: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CC54: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8004CC58: nop

    // 0x8004CC5C: beq         $t3, $zero, L_8004CC70
    if (ctx->r11 == 0) {
        // 0x8004CC60: nop
    
            goto L_8004CC70;
    }
    // 0x8004CC60: nop

    // 0x8004CC64: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CC68: bne         $t3, $at, L_8004CC3C
    if (ctx->r11 != ctx->r1) {
        // 0x8004CC6C: nop
    
            goto L_8004CC3C;
    }
    // 0x8004CC6C: nop

L_8004CC70:
    // 0x8004CC70: b           L_8004CD60
    // 0x8004CC74: nop

        goto L_8004CD60;
    // 0x8004CC74: nop

L_8004CC78:
    // 0x8004CC78: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004CC7C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8004CC80: lh          $t1, 0x4A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4A);
    // 0x8004CC84: nop

    // 0x8004CC88: andi        $t9, $t1, 0x1FFF
    ctx->r25 = ctx->r9 & 0X1FFF;
    // 0x8004CC8C: beq         $t9, $at, L_8004CCA0
    if (ctx->r25 == ctx->r1) {
        // 0x8004CC90: nop
    
            goto L_8004CCA0;
    }
    // 0x8004CC90: nop

    // 0x8004CC94: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8004CC98: bne         $t9, $at, L_8004CD04
    if (ctx->r25 != ctx->r1) {
        // 0x8004CC9C: nop
    
            goto L_8004CD04;
    }
    // 0x8004CC9C: nop

L_8004CCA0:
    // 0x8004CCA0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8004CCA4: lui         $at, 0xC069
    ctx->r1 = S32(0XC069 << 16);
    // 0x8004CCA8: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8004CCAC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004CCB0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004CCB4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004CCB8: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8004CCBC: nop

    // 0x8004CCC0: bc1f        L_8004CCFC
    if (!c1cs) {
        // 0x8004CCC4: nop
    
            goto L_8004CCFC;
    }
    // 0x8004CCC4: nop

L_8004CCC8:
    // 0x8004CCC8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CCCC: jal         0x800499B0
    // 0x8004CCD0: nop

    func_800499B0(rdram, ctx);
        goto after_64;
    // 0x8004CCD0: nop

    after_64:
    // 0x8004CCD4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8004CCD8: lui         $at, 0xC069
    ctx->r1 = S32(0XC069 << 16);
    // 0x8004CCDC: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8004CCE0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004CCE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004CCE8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004CCEC: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8004CCF0: nop

    // 0x8004CCF4: bc1t        L_8004CCC8
    if (c1cs) {
        // 0x8004CCF8: nop
    
            goto L_8004CCC8;
    }
    // 0x8004CCF8: nop

L_8004CCFC:
    // 0x8004CCFC: b           L_8004CD60
    // 0x8004CD00: nop

        goto L_8004CD60;
    // 0x8004CD00: nop

L_8004CD04:
    // 0x8004CD04: jal         0x80031AC8
    // 0x8004CD08: nop

    func_80031AC8(rdram, ctx);
        goto after_65;
    // 0x8004CD08: nop

    after_65:
    // 0x8004CD0C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CD10: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8004CD14: nop

    // 0x8004CD18: beq         $t4, $zero, L_8004CD60
    if (ctx->r12 == 0) {
        // 0x8004CD1C: nop
    
            goto L_8004CD60;
    }
    // 0x8004CD1C: nop

    // 0x8004CD20: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CD24: beq         $t4, $at, L_8004CD60
    if (ctx->r12 == ctx->r1) {
        // 0x8004CD28: nop
    
            goto L_8004CD60;
    }
    // 0x8004CD28: nop

L_8004CD2C:
    // 0x8004CD2C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CD30: jal         0x800499B0
    // 0x8004CD34: nop

    func_800499B0(rdram, ctx);
        goto after_66;
    // 0x8004CD34: nop

    after_66:
    // 0x8004CD38: jal         0x80031AC8
    // 0x8004CD3C: nop

    func_80031AC8(rdram, ctx);
        goto after_67;
    // 0x8004CD3C: nop

    after_67:
    // 0x8004CD40: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CD44: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8004CD48: nop

    // 0x8004CD4C: beq         $t5, $zero, L_8004CD60
    if (ctx->r13 == 0) {
        // 0x8004CD50: nop
    
            goto L_8004CD60;
    }
    // 0x8004CD50: nop

    // 0x8004CD54: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CD58: bne         $t5, $at, L_8004CD2C
    if (ctx->r13 != ctx->r1) {
        // 0x8004CD5C: nop
    
            goto L_8004CD2C;
    }
    // 0x8004CD5C: nop

L_8004CD60:
    // 0x8004CD60: b           L_8004D448
    // 0x8004CD64: nop

        goto L_8004D448;
    // 0x8004CD64: nop

L_8004CD68:
    // 0x8004CD68: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004CD6C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004CD70: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8004CD74: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8004CD78: bne         $t0, $zero, L_8004CD88
    if (ctx->r8 != 0) {
        // 0x8004CD7C: andi        $t1, $t3, 0x600
        ctx->r9 = ctx->r11 & 0X600;
            goto L_8004CD88;
    }
    // 0x8004CD7C: andi        $t1, $t3, 0x600
    ctx->r9 = ctx->r11 & 0X600;
    // 0x8004CD80: beq         $t1, $zero, L_8004CF80
    if (ctx->r9 == 0) {
        // 0x8004CD84: nop
    
            goto L_8004CF80;
    }
    // 0x8004CD84: nop

L_8004CD88:
    // 0x8004CD88: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004CD8C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004CD90: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004CD94: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004CD98: bne         $t4, $zero, L_8004CDA8
    if (ctx->r12 != 0) {
        // 0x8004CD9C: andi        $t5, $t7, 0x8000
        ctx->r13 = ctx->r15 & 0X8000;
            goto L_8004CDA8;
    }
    // 0x8004CD9C: andi        $t5, $t7, 0x8000
    ctx->r13 = ctx->r15 & 0X8000;
    // 0x8004CDA0: beq         $t5, $zero, L_8004CE80
    if (ctx->r13 == 0) {
        // 0x8004CDA4: nop
    
            goto L_8004CE80;
    }
    // 0x8004CDA4: nop

L_8004CDA8:
    // 0x8004CDA8: jal         0x80031AC8
    // 0x8004CDAC: nop

    func_80031AC8(rdram, ctx);
        goto after_68;
    // 0x8004CDAC: nop

    after_68:
    // 0x8004CDB0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CDB4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8004CDB8: nop

    // 0x8004CDBC: beq         $t8, $zero, L_8004CE4C
    if (ctx->r24 == 0) {
        // 0x8004CDC0: nop
    
            goto L_8004CE4C;
    }
    // 0x8004CDC0: nop

    // 0x8004CDC4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CDC8: beq         $t8, $at, L_8004CE4C
    if (ctx->r24 == ctx->r1) {
        // 0x8004CDCC: nop
    
            goto L_8004CE4C;
    }
    // 0x8004CDCC: nop

    // 0x8004CDD0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8004CDD4: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004CDD8: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004CDDC: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8004CDE0: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004CDE4: bne         $t6, $zero, L_8004CE4C
    if (ctx->r14 != 0) {
        // 0x8004CDE8: and         $t7, $t1, $at
        ctx->r15 = ctx->r9 & ctx->r1;
            goto L_8004CE4C;
    }
    // 0x8004CDE8: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004CDEC: bne         $t7, $zero, L_8004CE4C
    if (ctx->r15 != 0) {
        // 0x8004CDF0: nop
    
            goto L_8004CE4C;
    }
    // 0x8004CDF0: nop

L_8004CDF4:
    // 0x8004CDF4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CDF8: jal         0x800499B0
    // 0x8004CDFC: nop

    func_800499B0(rdram, ctx);
        goto after_69;
    // 0x8004CDFC: nop

    after_69:
    // 0x8004CE00: jal         0x80031AC8
    // 0x8004CE04: nop

    func_80031AC8(rdram, ctx);
        goto after_70;
    // 0x8004CE04: nop

    after_70:
    // 0x8004CE08: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CE0C: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8004CE10: nop

    // 0x8004CE14: beq         $t3, $zero, L_8004CE4C
    if (ctx->r11 == 0) {
        // 0x8004CE18: nop
    
            goto L_8004CE4C;
    }
    // 0x8004CE18: nop

    // 0x8004CE1C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CE20: beq         $t3, $at, L_8004CE4C
    if (ctx->r11 == ctx->r1) {
        // 0x8004CE24: nop
    
            goto L_8004CE4C;
    }
    // 0x8004CE24: nop

    // 0x8004CE28: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004CE2C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004CE30: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8004CE34: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8004CE38: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8004CE3C: bne         $t8, $zero, L_8004CE4C
    if (ctx->r24 != 0) {
        // 0x8004CE40: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_8004CE4C;
    }
    // 0x8004CE40: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x8004CE44: beq         $t9, $zero, L_8004CDF4
    if (ctx->r25 == 0) {
        // 0x8004CE48: nop
    
            goto L_8004CDF4;
    }
    // 0x8004CE48: nop

L_8004CE4C:
    // 0x8004CE4C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8004CE50: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004CE54: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004CE58: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8004CE5C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004CE60: bne         $t6, $zero, L_8004CE70
    if (ctx->r14 != 0) {
        // 0x8004CE64: and         $t7, $t1, $at
        ctx->r15 = ctx->r9 & ctx->r1;
            goto L_8004CE70;
    }
    // 0x8004CE64: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004CE68: beq         $t7, $zero, L_8004CE78
    if (ctx->r15 == 0) {
        // 0x8004CE6C: nop
    
            goto L_8004CE78;
    }
    // 0x8004CE6C: nop

L_8004CE70:
    // 0x8004CE70: b           L_8004D1C0
    // 0x8004CE74: nop

        goto L_8004D1C0;
    // 0x8004CE74: nop

L_8004CE78:
    // 0x8004CE78: b           L_8004CEDC
    // 0x8004CE7C: nop

        goto L_8004CEDC;
    // 0x8004CE7C: nop

L_8004CE80:
    // 0x8004CE80: jal         0x80031AC8
    // 0x8004CE84: nop

    func_80031AC8(rdram, ctx);
        goto after_71;
    // 0x8004CE84: nop

    after_71:
    // 0x8004CE88: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CE8C: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8004CE90: nop

    // 0x8004CE94: beq         $t3, $zero, L_8004CEDC
    if (ctx->r11 == 0) {
        // 0x8004CE98: nop
    
            goto L_8004CEDC;
    }
    // 0x8004CE98: nop

    // 0x8004CE9C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CEA0: beq         $t3, $at, L_8004CEDC
    if (ctx->r11 == ctx->r1) {
        // 0x8004CEA4: nop
    
            goto L_8004CEDC;
    }
    // 0x8004CEA4: nop

L_8004CEA8:
    // 0x8004CEA8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CEAC: jal         0x800499B0
    // 0x8004CEB0: nop

    func_800499B0(rdram, ctx);
        goto after_72;
    // 0x8004CEB0: nop

    after_72:
    // 0x8004CEB4: jal         0x80031AC8
    // 0x8004CEB8: nop

    func_80031AC8(rdram, ctx);
        goto after_73;
    // 0x8004CEB8: nop

    after_73:
    // 0x8004CEBC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004CEC0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8004CEC4: nop

    // 0x8004CEC8: beq         $t4, $zero, L_8004CEDC
    if (ctx->r12 == 0) {
        // 0x8004CECC: nop
    
            goto L_8004CEDC;
    }
    // 0x8004CECC: nop

    // 0x8004CED0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CED4: bne         $t4, $at, L_8004CEA8
    if (ctx->r12 != ctx->r1) {
        // 0x8004CED8: nop
    
            goto L_8004CEA8;
    }
    // 0x8004CED8: nop

L_8004CEDC:
    // 0x8004CEDC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8004CEE0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004CEE4: addiu       $a0, $t5, 0x4C
    ctx->r4 = ADD32(ctx->r13, 0X4C);
    // 0x8004CEE8: jal         0x800B2CBC
    // 0x8004CEEC: addiu       $a1, $t5, 0x50
    ctx->r5 = ADD32(ctx->r13, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_74;
    // 0x8004CEEC: addiu       $a1, $t5, 0x50
    ctx->r5 = ADD32(ctx->r13, 0X50);
    after_74:
    // 0x8004CEF0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004CEF4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004CEF8: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8004CEFC: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8004CF00: bne         $t0, $zero, L_8004CF10
    if (ctx->r8 != 0) {
        // 0x8004CF04: andi        $t1, $t3, 0x8000
        ctx->r9 = ctx->r11 & 0X8000;
            goto L_8004CF10;
    }
    // 0x8004CF04: andi        $t1, $t3, 0x8000
    ctx->r9 = ctx->r11 & 0X8000;
    // 0x8004CF08: beq         $t1, $zero, L_8004CF80
    if (ctx->r9 == 0) {
        // 0x8004CF0C: nop
    
            goto L_8004CF80;
    }
    // 0x8004CF0C: nop

L_8004CF10:
    // 0x8004CF10: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004CF14: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004CF18: lw          $t6, 0x5C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X5C);
    // 0x8004CF1C: addiu       $t5, $t5, 0x24D8
    ctx->r13 = ADD32(ctx->r13, 0X24D8);
    // 0x8004CF20: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x8004CF24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004CF28: sll         $t4, $t7, 5
    ctx->r12 = S32(ctx->r15 << 5);
    // 0x8004CF2C: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x8004CF30: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    // 0x8004CF34: lw          $a1, 0x1C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X1C);
    // 0x8004CF38: jal         0x800B2C4C
    // 0x8004CF3C: nop

    func_800B2C4C(rdram, ctx);
        goto after_75;
    // 0x8004CF3C: nop

    after_75:
    // 0x8004CF40: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8004CF44: nop

    // 0x8004CF48: lhu         $t3, 0x66($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X66);
    // 0x8004CF4C: nop

    // 0x8004CF50: beq         $t3, $zero, L_8004CF80
    if (ctx->r11 == 0) {
        // 0x8004CF54: nop
    
            goto L_8004CF80;
    }
    // 0x8004CF54: nop

    // 0x8004CF58: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004CF5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004CF60: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004CF64: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8004CF68: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x8004CF6C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004CF70: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004CF74: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x8004CF78: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8004CF7C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_8004CF80:
    // 0x8004CF80: addiu       $t1, $zero, 0x258
    ctx->r9 = ADD32(0, 0X258);
    // 0x8004CF84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004CF88: sw          $t1, 0xCD4($at)
    MEM_W(0XCD4, ctx->r1) = ctx->r9;
    // 0x8004CF8C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004CF90: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004CF94: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8004CF98: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x8004CF9C: bne         $t2, $zero, L_8004CFAC
    if (ctx->r10 != 0) {
        // 0x8004CFA0: andi        $t3, $t9, 0x8000
        ctx->r11 = ctx->r25 & 0X8000;
            goto L_8004CFAC;
    }
    // 0x8004CFA0: andi        $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 & 0X8000;
    // 0x8004CFA4: beq         $t3, $zero, L_8004D06C
    if (ctx->r11 == 0) {
        // 0x8004CFA8: nop
    
            goto L_8004D06C;
    }
    // 0x8004CFA8: nop

L_8004CFAC:
    // 0x8004CFAC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8004CFB0: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8004CFB4: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x8004CFB8: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8004CFBC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004CFC0: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8004CFC4: bne         $t0, $zero, L_8004D030
    if (ctx->r8 != 0) {
        // 0x8004CFC8: and         $t1, $t5, $at
        ctx->r9 = ctx->r13 & ctx->r1;
            goto L_8004D030;
    }
    // 0x8004CFC8: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x8004CFCC: bne         $t1, $zero, L_8004D030
    if (ctx->r9 != 0) {
        // 0x8004CFD0: nop
    
            goto L_8004D030;
    }
    // 0x8004CFD0: nop

    // 0x8004CFD4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004CFD8: lw          $t7, 0xCD4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCD4);
    // 0x8004CFDC: nop

    // 0x8004CFE0: beq         $t7, $zero, L_8004D030
    if (ctx->r15 == 0) {
        // 0x8004CFE4: nop
    
            goto L_8004D030;
    }
    // 0x8004CFE4: nop

L_8004CFE8:
    // 0x8004CFE8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004CFEC: jal         0x800499B0
    // 0x8004CFF0: nop

    func_800499B0(rdram, ctx);
        goto after_76;
    // 0x8004CFF0: nop

    after_76:
    // 0x8004CFF4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004CFF8: lui         $at, 0x404
    ctx->r1 = S32(0X404 << 16);
    // 0x8004CFFC: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8004D000: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8004D004: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004D008: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8004D00C: bne         $t6, $zero, L_8004D030
    if (ctx->r14 != 0) {
        // 0x8004D010: and         $t7, $t3, $at
        ctx->r15 = ctx->r11 & ctx->r1;
            goto L_8004D030;
    }
    // 0x8004D010: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8004D014: bne         $t7, $zero, L_8004D030
    if (ctx->r15 != 0) {
        // 0x8004D018: nop
    
            goto L_8004D030;
    }
    // 0x8004D018: nop

    // 0x8004D01C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004D020: lw          $t9, 0xCD4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCD4);
    // 0x8004D024: nop

    // 0x8004D028: bne         $t9, $zero, L_8004CFE8
    if (ctx->r25 != 0) {
        // 0x8004D02C: nop
    
            goto L_8004CFE8;
    }
    // 0x8004D02C: nop

L_8004D030:
    // 0x8004D030: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004D034: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004D038: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004D03C: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x8004D040: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004D044: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004D048: bne         $t8, $zero, L_8004D058
    if (ctx->r24 != 0) {
        // 0x8004D04C: and         $t9, $t1, $at
        ctx->r25 = ctx->r9 & ctx->r1;
            goto L_8004D058;
    }
    // 0x8004D04C: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8004D050: beq         $t9, $zero, L_8004D064
    if (ctx->r25 == 0) {
        // 0x8004D054: nop
    
            goto L_8004D064;
    }
    // 0x8004D054: nop

L_8004D058:
    // 0x8004D058: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D05C: jal         0x8004F8CC
    // 0x8004D060: nop

    func_8004F8CC(rdram, ctx);
        goto after_77;
    // 0x8004D060: nop

    after_77:
L_8004D064:
    // 0x8004D064: b           L_8004D170
    // 0x8004D068: nop

        goto L_8004D170;
    // 0x8004D068: nop

L_8004D06C:
    // 0x8004D06C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8004D070: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004D074: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004D078: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8004D07C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004D080: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004D084: bne         $t6, $zero, L_8004D118
    if (ctx->r14 != 0) {
        // 0x8004D088: and         $t7, $t3, $at
        ctx->r15 = ctx->r11 & ctx->r1;
            goto L_8004D118;
    }
    // 0x8004D088: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8004D08C: bne         $t7, $zero, L_8004D118
    if (ctx->r15 != 0) {
        // 0x8004D090: nop
    
            goto L_8004D118;
    }
    // 0x8004D090: nop

    // 0x8004D094: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004D098: lw          $t4, 0xCD4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCD4);
    // 0x8004D09C: nop

    // 0x8004D0A0: beq         $t4, $zero, L_8004D118
    if (ctx->r12 == 0) {
        // 0x8004D0A4: nop
    
            goto L_8004D118;
    }
    // 0x8004D0A4: nop

L_8004D0A8:
    // 0x8004D0A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004D0AC: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004D0B0: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x8004D0B4: lh          $t1, 0x4A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4A);
    // 0x8004D0B8: nop

    // 0x8004D0BC: andi        $t8, $t1, 0x1FFF
    ctx->r24 = ctx->r9 & 0X1FFF;
    // 0x8004D0C0: bne         $t8, $at, L_8004D0D0
    if (ctx->r24 != ctx->r1) {
        // 0x8004D0C4: nop
    
            goto L_8004D0D0;
    }
    // 0x8004D0C4: nop

    // 0x8004D0C8: jal         0x80056848
    // 0x8004D0CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80056848(rdram, ctx);
        goto after_78;
    // 0x8004D0CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_78:
L_8004D0D0:
    // 0x8004D0D0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D0D4: jal         0x800499B0
    // 0x8004D0D8: nop

    func_800499B0(rdram, ctx);
        goto after_79;
    // 0x8004D0D8: nop

    after_79:
    // 0x8004D0DC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D0E0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004D0E4: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8004D0E8: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8004D0EC: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004D0F0: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8004D0F4: bne         $t6, $zero, L_8004D118
    if (ctx->r14 != 0) {
        // 0x8004D0F8: and         $t7, $t3, $at
        ctx->r15 = ctx->r11 & ctx->r1;
            goto L_8004D118;
    }
    // 0x8004D0F8: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8004D0FC: bne         $t7, $zero, L_8004D118
    if (ctx->r15 != 0) {
        // 0x8004D100: nop
    
            goto L_8004D118;
    }
    // 0x8004D100: nop

    // 0x8004D104: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004D108: lw          $t5, 0xCD4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCD4);
    // 0x8004D10C: nop

    // 0x8004D110: bne         $t5, $zero, L_8004D0A8
    if (ctx->r13 != 0) {
        // 0x8004D114: nop
    
            goto L_8004D0A8;
    }
    // 0x8004D114: nop

L_8004D118:
    // 0x8004D118: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004D11C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004D120: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004D124: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x8004D128: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004D12C: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004D130: bne         $t8, $zero, L_8004D140
    if (ctx->r24 != 0) {
        // 0x8004D134: and         $t9, $t1, $at
        ctx->r25 = ctx->r9 & ctx->r1;
            goto L_8004D140;
    }
    // 0x8004D134: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8004D138: beq         $t9, $zero, L_8004D170
    if (ctx->r25 == 0) {
        // 0x8004D13C: nop
    
            goto L_8004D170;
    }
    // 0x8004D13C: nop

L_8004D140:
    // 0x8004D140: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004D144: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004D148: nop

    // 0x8004D14C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8004D150: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8004D154: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x8004D158: ori         $t5, $t7, 0x8000
    ctx->r13 = ctx->r15 | 0X8000;
    // 0x8004D15C: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8004D160: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8004D164: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D168: jal         0x8004F8CC
    // 0x8004D16C: nop

    func_8004F8CC(rdram, ctx);
        goto after_80;
    // 0x8004D16C: nop

    after_80:
L_8004D170:
    // 0x8004D170: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8004D174: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004D178: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004D17C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004D180: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004D184: bne         $t8, $zero, L_8004D1C0
    if (ctx->r24 != 0) {
        // 0x8004D188: and         $t9, $t1, $at
        ctx->r25 = ctx->r9 & ctx->r1;
            goto L_8004D1C0;
    }
    // 0x8004D188: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8004D18C: bne         $t9, $zero, L_8004D1C0
    if (ctx->r25 != 0) {
        // 0x8004D190: nop
    
            goto L_8004D1C0;
    }
    // 0x8004D190: nop

    // 0x8004D194: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004D198: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004D19C: bne         $t6, $zero, L_8004D1AC
    if (ctx->r14 != 0) {
        // 0x8004D1A0: and         $t7, $t1, $at
        ctx->r15 = ctx->r9 & ctx->r1;
            goto L_8004D1AC;
    }
    // 0x8004D1A0: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004D1A4: beq         $t7, $zero, L_8004D268
    if (ctx->r15 == 0) {
        // 0x8004D1A8: nop
    
            goto L_8004D268;
    }
    // 0x8004D1A8: nop

L_8004D1AC:
    // 0x8004D1AC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004D1B0: bne         $t4, $zero, L_8004D1C0
    if (ctx->r12 != 0) {
        // 0x8004D1B4: andi        $t5, $t1, 0x8000
        ctx->r13 = ctx->r9 & 0X8000;
            goto L_8004D1C0;
    }
    // 0x8004D1B4: andi        $t5, $t1, 0x8000
    ctx->r13 = ctx->r9 & 0X8000;
    // 0x8004D1B8: beq         $t5, $zero, L_8004D268
    if (ctx->r13 == 0) {
        // 0x8004D1BC: nop
    
            goto L_8004D268;
    }
    // 0x8004D1BC: nop

L_8004D1C0:
    // 0x8004D1C0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004D1C4: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004D1C8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004D1CC: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004D1D0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004D1D4: bne         $t6, $zero, L_8004D1E4
    if (ctx->r14 != 0) {
        // 0x8004D1D8: andi        $t7, $t9, 0x8000
        ctx->r15 = ctx->r25 & 0X8000;
            goto L_8004D1E4;
    }
    // 0x8004D1D8: andi        $t7, $t9, 0x8000
    ctx->r15 = ctx->r25 & 0X8000;
    // 0x8004D1DC: beq         $t7, $zero, L_8004D24C
    if (ctx->r15 == 0) {
        // 0x8004D1E0: nop
    
            goto L_8004D24C;
    }
    // 0x8004D1E0: nop

L_8004D1E4:
    // 0x8004D1E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004D1E8: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004D1EC: bne         $t0, $zero, L_8004D1FC
    if (ctx->r8 != 0) {
        // 0x8004D1F0: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8004D1FC;
    }
    // 0x8004D1F0: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8004D1F4: beq         $t1, $zero, L_8004D24C
    if (ctx->r9 == 0) {
        // 0x8004D1F8: nop
    
            goto L_8004D24C;
    }
    // 0x8004D1F8: nop

L_8004D1FC:
    // 0x8004D1FC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004D200: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004D204: nop

    // 0x8004D208: lbu         $t4, 0xA($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XA);
    // 0x8004D20C: nop

    // 0x8004D210: bne         $t4, $zero, L_8004D24C
    if (ctx->r12 != 0) {
        // 0x8004D214: nop
    
            goto L_8004D24C;
    }
    // 0x8004D214: nop

    // 0x8004D218: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8004D21C: nop

    // 0x8004D220: bne         $t5, $zero, L_8004D24C
    if (ctx->r13 != 0) {
        // 0x8004D224: nop
    
            goto L_8004D24C;
    }
    // 0x8004D224: nop

    // 0x8004D228: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004D22C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004D230: nop

    // 0x8004D234: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8004D238: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8004D23C: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x8004D240: ori         $t9, $t7, 0x0
    ctx->r25 = ctx->r15 | 0X0;
    // 0x8004D244: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8004D248: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8004D24C:
    // 0x8004D24C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D250: jal         0x8004F8CC
    // 0x8004D254: nop

    func_8004F8CC(rdram, ctx);
        goto after_81;
    // 0x8004D254: nop

    after_81:
    // 0x8004D258: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8004D25C: nop

    // 0x8004D260: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004D264: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_8004D268:
    // 0x8004D268: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D26C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004D270: jal         0x8005007C
    // 0x8004D274: nop

    func_8005007C(rdram, ctx);
        goto after_82;
    // 0x8004D274: nop

    after_82:
    // 0x8004D278: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8004D27C: nop

    // 0x8004D280: lh          $t4, 0x4A($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4A);
    // 0x8004D284: nop

    // 0x8004D288: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x8004D28C: sh          $t5, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r13;
    // 0x8004D290: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004D294: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004D298: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8004D29C: nop

    // 0x8004D2A0: bne         $t6, $t7, L_8004D2B8
    if (ctx->r14 != ctx->r15) {
        // 0x8004D2A4: nop
    
            goto L_8004D2B8;
    }
    // 0x8004D2A4: nop

    // 0x8004D2A8: lw          $t8, 0x5C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X5C);
    // 0x8004D2AC: nop

    // 0x8004D2B0: beq         $t8, $zero, L_8004D340
    if (ctx->r24 == 0) {
        // 0x8004D2B4: nop
    
            goto L_8004D340;
    }
    // 0x8004D2B4: nop

L_8004D2B8:
    // 0x8004D2B8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004D2BC: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004D2C0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D2C4: nop

    // 0x8004D2C8: bne         $t9, $t2, L_8004D2E8
    if (ctx->r25 != ctx->r10) {
        // 0x8004D2CC: nop
    
            goto L_8004D2E8;
    }
    // 0x8004D2CC: nop

    // 0x8004D2D0: lw          $t0, 0x5C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X5C);
    // 0x8004D2D4: nop

    // 0x8004D2D8: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8004D2DC: nop

    // 0x8004D2E0: beq         $t1, $zero, L_8004D340
    if (ctx->r9 == 0) {
        // 0x8004D2E4: nop
    
            goto L_8004D340;
    }
    // 0x8004D2E4: nop

L_8004D2E8:
    // 0x8004D2E8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004D2EC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004D2F0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8004D2F4: nop

    // 0x8004D2F8: bne         $t3, $t4, L_8004D318
    if (ctx->r11 != ctx->r12) {
        // 0x8004D2FC: nop
    
            goto L_8004D318;
    }
    // 0x8004D2FC: nop

    // 0x8004D300: lw          $t5, 0x5C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X5C);
    // 0x8004D304: nop

    // 0x8004D308: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8004D30C: nop

    // 0x8004D310: beq         $t6, $zero, L_8004D340
    if (ctx->r14 == 0) {
        // 0x8004D314: nop
    
            goto L_8004D340;
    }
    // 0x8004D314: nop

L_8004D318:
    // 0x8004D318: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004D31C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004D320: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8004D324: nop

    // 0x8004D328: bne         $t7, $t8, L_8004D3AC
    if (ctx->r15 != ctx->r24) {
        // 0x8004D32C: nop
    
            goto L_8004D3AC;
    }
    // 0x8004D32C: nop

    // 0x8004D330: lhu         $t9, 0x66($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X66);
    // 0x8004D334: nop

    // 0x8004D338: beq         $t9, $zero, L_8004D3AC
    if (ctx->r25 == 0) {
        // 0x8004D33C: nop
    
            goto L_8004D3AC;
    }
    // 0x8004D33C: nop

L_8004D340:
    // 0x8004D340: lh          $t2, 0x48($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X48);
    // 0x8004D344: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x8004D348: beq         $t2, $at, L_8004D3AC
    if (ctx->r10 == ctx->r1) {
        // 0x8004D34C: nop
    
            goto L_8004D3AC;
    }
    // 0x8004D34C: nop

    // 0x8004D350: addiu       $at, $zero, 0xB2
    ctx->r1 = ADD32(0, 0XB2);
    // 0x8004D354: beq         $t2, $at, L_8004D3AC
    if (ctx->r10 == ctx->r1) {
        // 0x8004D358: nop
    
            goto L_8004D3AC;
    }
    // 0x8004D358: nop

    // 0x8004D35C: addiu       $at, $zero, 0xB3
    ctx->r1 = ADD32(0, 0XB3);
    // 0x8004D360: beq         $t2, $at, L_8004D3AC
    if (ctx->r10 == ctx->r1) {
        // 0x8004D364: nop
    
            goto L_8004D3AC;
    }
    // 0x8004D364: nop

    // 0x8004D368: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D36C: jal         0x80051700
    // 0x8004D370: nop

    func_80051700(rdram, ctx);
        goto after_83;
    // 0x8004D370: nop

    after_83:
    // 0x8004D374: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8004D378: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x8004D37C: lh          $t3, 0x4A($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X4A);
    // 0x8004D380: lh          $t0, 0x4C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4C);
    // 0x8004D384: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x8004D388: beq         $t0, $t4, L_8004D3AC
    if (ctx->r8 == ctx->r12) {
        // 0x8004D38C: nop
    
            goto L_8004D3AC;
    }
    // 0x8004D38C: nop

    // 0x8004D390: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004D394: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8004D398: lh          $a0, 0x4C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4C);
    // 0x8004D39C: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8004D3A0: lh          $a1, 0x42($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X42);
    // 0x8004D3A4: jal         0x8004EF90
    // 0x8004D3A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_84;
    // 0x8004D3A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_84:
L_8004D3AC:
    // 0x8004D3AC: lh          $t6, 0x48($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X48);
    // 0x8004D3B0: addiu       $at, $zero, 0xB3
    ctx->r1 = ADD32(0, 0XB3);
    // 0x8004D3B4: bne         $t6, $at, L_8004D3DC
    if (ctx->r14 != ctx->r1) {
        // 0x8004D3B8: nop
    
            goto L_8004D3DC;
    }
    // 0x8004D3B8: nop

    // 0x8004D3BC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8004D3C0: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x8004D3C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004D3C8: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8004D3CC: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x8004D3D0: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x8004D3D4: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x8004D3D8: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
L_8004D3DC:
    // 0x8004D3DC: jal         0x80031AC8
    // 0x8004D3E0: nop

    func_80031AC8(rdram, ctx);
        goto after_85;
    // 0x8004D3E0: nop

    after_85:
    // 0x8004D3E4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004D3E8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8004D3EC: nop

    // 0x8004D3F0: beq         $t1, $zero, L_8004D438
    if (ctx->r9 == 0) {
        // 0x8004D3F4: nop
    
            goto L_8004D438;
    }
    // 0x8004D3F4: nop

    // 0x8004D3F8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004D3FC: beq         $t1, $at, L_8004D438
    if (ctx->r9 == ctx->r1) {
        // 0x8004D400: nop
    
            goto L_8004D438;
    }
    // 0x8004D400: nop

L_8004D404:
    // 0x8004D404: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D408: jal         0x800499B0
    // 0x8004D40C: nop

    func_800499B0(rdram, ctx);
        goto after_86;
    // 0x8004D40C: nop

    after_86:
    // 0x8004D410: jal         0x80031AC8
    // 0x8004D414: nop

    func_80031AC8(rdram, ctx);
        goto after_87;
    // 0x8004D414: nop

    after_87:
    // 0x8004D418: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004D41C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8004D420: nop

    // 0x8004D424: beq         $t0, $zero, L_8004D438
    if (ctx->r8 == 0) {
        // 0x8004D428: nop
    
            goto L_8004D438;
    }
    // 0x8004D428: nop

    // 0x8004D42C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004D430: bne         $t0, $at, L_8004D404
    if (ctx->r8 != ctx->r1) {
        // 0x8004D434: nop
    
            goto L_8004D404;
    }
    // 0x8004D434: nop

L_8004D438:
    // 0x8004D438: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D43C: lh          $a1, 0x48($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X48);
    // 0x8004D440: jal         0x8004FAB0
    // 0x8004D444: nop

    func_8004FAB0(rdram, ctx);
        goto after_88;
    // 0x8004D444: nop

    after_88:
L_8004D448:
    // 0x8004D448: lhu         $a0, 0x50($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X50);
    // 0x8004D44C: nop

    // 0x8004D450: andi        $t4, $a0, 0x1FFF
    ctx->r12 = ctx->r4 & 0X1FFF;
    // 0x8004D454: jal         0x80056B74
    // 0x8004D458: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_80056B74(rdram, ctx);
        goto after_89;
    // 0x8004D458: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_89:
    // 0x8004D45C: lhu         $a1, 0x50($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X50);
    // 0x8004D460: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D464: andi        $t5, $a1, 0x1FFF
    ctx->r13 = ctx->r5 & 0X1FFF;
    // 0x8004D468: jal         0x8004FE20
    // 0x8004D46C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    func_8004FE20(rdram, ctx);
        goto after_90;
    // 0x8004D46C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_90:
L_8004D470:
    // 0x8004D470: lhu         $t6, 0x50($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X50);
    // 0x8004D474: nop

    // 0x8004D478: andi        $t8, $t6, 0x4000
    ctx->r24 = ctx->r14 & 0X4000;
    // 0x8004D47C: beq         $t8, $zero, L_8004D4B8
    if (ctx->r24 == 0) {
        // 0x8004D480: nop
    
            goto L_8004D4B8;
    }
    // 0x8004D480: nop

    // 0x8004D484: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D488: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004D48C: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8004D490: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004D494: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8004D498: bne         $t0, $zero, L_8004D4B8
    if (ctx->r8 != 0) {
        // 0x8004D49C: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_8004D4B8;
    }
    // 0x8004D49C: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004D4A0: bne         $t1, $zero, L_8004D4B8
    if (ctx->r9 != 0) {
        // 0x8004D4A4: nop
    
            goto L_8004D4B8;
    }
    // 0x8004D4A4: nop

    // 0x8004D4A8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8004D4AC: nop

    // 0x8004D4B0: beq         $t7, $zero, L_8004BBE8
    if (ctx->r15 == 0) {
        // 0x8004D4B4: nop
    
            goto L_8004BBE8;
    }
    // 0x8004D4B4: nop

L_8004D4B8:
    // 0x8004D4B8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8004D4BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D4C0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004D4C4: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004D4C8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8004D4CC: lui         $at, 0xFBFF
    ctx->r1 = S32(0XFBFF << 16);
    // 0x8004D4D0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004D4D4: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004D4D8: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004D4DC: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8004D4E0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8004D4E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004D4E8: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004D4EC: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004D4F0: bne         $t0, $zero, L_8004D500
    if (ctx->r8 != 0) {
        // 0x8004D4F4: andi        $t1, $t3, 0x8000
        ctx->r9 = ctx->r11 & 0X8000;
            goto L_8004D500;
    }
    // 0x8004D4F4: andi        $t1, $t3, 0x8000
    ctx->r9 = ctx->r11 & 0X8000;
    // 0x8004D4F8: beq         $t1, $zero, L_8004D57C
    if (ctx->r9 == 0) {
        // 0x8004D4FC: nop
    
            goto L_8004D57C;
    }
    // 0x8004D4FC: nop

L_8004D500:
    // 0x8004D500: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8004D504: nop

    // 0x8004D508: lw          $t7, 0x5C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X5C);
    // 0x8004D50C: nop

    // 0x8004D510: beq         $t7, $zero, L_8004D554
    if (ctx->r15 == 0) {
        // 0x8004D514: nop
    
            goto L_8004D554;
    }
    // 0x8004D514: nop

    // 0x8004D518: lhu         $t8, 0x60($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X60);
    // 0x8004D51C: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x8004D520: beq         $t8, $at, L_8004D554
    if (ctx->r24 == ctx->r1) {
        // 0x8004D524: nop
    
            goto L_8004D554;
    }
    // 0x8004D524: nop

    // 0x8004D528: addiu       $at, $zero, 0x15E
    ctx->r1 = ADD32(0, 0X15E);
    // 0x8004D52C: beq         $t8, $at, L_8004D554
    if (ctx->r24 == ctx->r1) {
        // 0x8004D530: nop
    
            goto L_8004D554;
    }
    // 0x8004D530: nop

    // 0x8004D534: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D538: nop

    // 0x8004D53C: lhu         $a2, 0x64($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X64);
    // 0x8004D540: lw          $a0, 0x5C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X5C);
    // 0x8004D544: lhu         $a1, 0x60($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X60);
    // 0x8004D548: ori         $t4, $a2, 0x37
    ctx->r12 = ctx->r6 | 0X37;
    // 0x8004D54C: jal         0x80029538
    // 0x8004D550: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    func_80029538(rdram, ctx);
        goto after_91;
    // 0x8004D550: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_91:
L_8004D554:
    // 0x8004D554: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8004D558: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D55C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004D560: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004D564: and         $t0, $t2, $at
    ctx->r8 = ctx->r10 & ctx->r1;
    // 0x8004D568: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004D56C: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004D570: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004D574: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8004D578: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
L_8004D57C:
    // 0x8004D57C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8004D580: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004D584: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8004D588: lw          $t7, 0x4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4);
    // 0x8004D58C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004D590: bne         $t8, $zero, L_8004D5A0
    if (ctx->r24 != 0) {
        // 0x8004D594: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004D5A0;
    }
    // 0x8004D594: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004D598: beq         $t9, $zero, L_8004D6F4
    if (ctx->r25 == 0) {
        // 0x8004D59C: nop
    
            goto L_8004D6F4;
    }
    // 0x8004D59C: nop

L_8004D5A0:
    // 0x8004D5A0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8004D5A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8004D5A8: lw          $t2, 0x58($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X58);
    // 0x8004D5AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004D5B0: lbu         $a0, 0x16($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X16);
    // 0x8004D5B4: jal         0x8008312C
    // 0x8004D5B8: nop

    func_8008312C(rdram, ctx);
        goto after_92;
    // 0x8004D5B8: nop

    after_92:
    // 0x8004D5BC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8004D5C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D5C4: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004D5C8: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004D5CC: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x8004D5D0: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8004D5D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004D5D8: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004D5DC: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004D5E0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004D5E4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004D5E8: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8004D5EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004D5F0: bne         $t5, $at, L_8004D670
    if (ctx->r13 != ctx->r1) {
        // 0x8004D5F4: nop
    
            goto L_8004D670;
    }
    // 0x8004D5F4: nop

    // 0x8004D5F8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8004D5FC: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x8004D600: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004D604: bne         $t8, $at, L_8004D670
    if (ctx->r24 != ctx->r1) {
        // 0x8004D608: nop
    
            goto L_8004D670;
    }
    // 0x8004D608: nop

    // 0x8004D60C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D610: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004D614: lw          $t4, 0x58($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X58);
    // 0x8004D618: nop

    // 0x8004D61C: lbu         $t2, 0x16($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X16);
    // 0x8004D620: nop

    // 0x8004D624: bne         $t2, $at, L_8004D670
    if (ctx->r10 != ctx->r1) {
        // 0x8004D628: nop
    
            goto L_8004D670;
    }
    // 0x8004D628: nop

    // 0x8004D62C: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8004D630: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004D634: sh          $t0, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r8;
    // 0x8004D638: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8004D63C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004D640: sh          $t1, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r9;
    // 0x8004D644: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004D648: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004D64C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004D650: nop

    // 0x8004D654: ori         $t3, $t7, 0x40
    ctx->r11 = ctx->r15 | 0X40;
    // 0x8004D658: sh          $t3, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r11;
    // 0x8004D65C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D660: jal         0x800499B0
    // 0x8004D664: nop

    func_800499B0(rdram, ctx);
        goto after_93;
    // 0x8004D664: nop

    after_93:
    // 0x8004D668: b           L_8004D6F4
    // 0x8004D66C: nop

        goto L_8004D6F4;
    // 0x8004D66C: nop

L_8004D670:
    // 0x8004D670: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004D674: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8004D678: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004D67C: bne         $t5, $at, L_8004D6F4
    if (ctx->r13 != ctx->r1) {
        // 0x8004D680: nop
    
            goto L_8004D6F4;
    }
    // 0x8004D680: nop

    // 0x8004D684: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8004D688: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x8004D68C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004D690: bne         $t8, $at, L_8004D6F4
    if (ctx->r24 != ctx->r1) {
        // 0x8004D694: nop
    
            goto L_8004D6F4;
    }
    // 0x8004D694: nop

    // 0x8004D698: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D69C: nop

    // 0x8004D6A0: lw          $t4, 0x58($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X58);
    // 0x8004D6A4: nop

    // 0x8004D6A8: lbu         $t2, 0x16($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X16);
    // 0x8004D6AC: nop

    // 0x8004D6B0: bne         $t2, $zero, L_8004D6F4
    if (ctx->r10 != 0) {
        // 0x8004D6B4: nop
    
            goto L_8004D6F4;
    }
    // 0x8004D6B4: nop

    // 0x8004D6B8: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8004D6BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004D6C0: sh          $t0, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r8;
    // 0x8004D6C4: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x8004D6C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004D6CC: sh          $t1, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r9;
    // 0x8004D6D0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8004D6D4: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8004D6D8: lhu         $t3, 0x0($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X0);
    // 0x8004D6DC: nop

    // 0x8004D6E0: ori         $t6, $t3, 0x40
    ctx->r14 = ctx->r11 | 0X40;
    // 0x8004D6E4: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8004D6E8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D6EC: jal         0x800499B0
    // 0x8004D6F0: nop

    func_800499B0(rdram, ctx);
        goto after_94;
    // 0x8004D6F0: nop

    after_94:
L_8004D6F4:
    // 0x8004D6F4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8004D6F8: nop

    // 0x8004D6FC: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x8004D700: jal         0x80098AD8
    // 0x8004D704: nop

    func_80098AD8(rdram, ctx);
        goto after_95;
    // 0x8004D704: nop

    after_95:
    // 0x8004D708: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8004D70C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8004D710: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x8004D714: addiu       $a1, $a1, 0x72F0
    ctx->r5 = ADD32(ctx->r5, 0X72F0);
    // 0x8004D718: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8004D71C: jal         0x800C1264
    // 0x8004D720: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_96;
    // 0x8004D720: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_96:
    // 0x8004D724: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8004D728: nop

    // 0x8004D72C: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x8004D730: jal         0x800C0D34
    // 0x8004D734: nop

    Thread_StopThread(rdram, ctx);
        goto after_97;
    // 0x8004D734: nop

    after_97:
L_8004D738:
    // 0x8004D738: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8004D73C: jal         0x800499B0
    // 0x8004D740: nop

    func_800499B0(rdram, ctx);
        goto after_98;
    // 0x8004D740: nop

    after_98:
    // 0x8004D744: b           L_8004D738
    // 0x8004D748: nop

        goto L_8004D738;
    // 0x8004D748: nop

    // 0x8004D74C: b           L_8004D754
    // 0x8004D750: nop

        goto L_8004D754;
    // 0x8004D750: nop

L_8004D754:
    // 0x8004D754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004D758: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8004D75C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8004D760: jr          $ra
    // 0x8004D764: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8004D764: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80061990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061990: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80061994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061998: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006199C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800619A0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800619A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800619A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800619AC: lh          $a0, 0x42($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X42);
    // 0x800619B0: jal         0x80061348
    // 0x800619B4: nop

    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800619B4: nop

    after_0:
    // 0x800619B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800619BC: bne         $v0, $at, L_800619CC
    if (ctx->r2 != ctx->r1) {
        // 0x800619C0: nop
    
            goto L_800619CC;
    }
    // 0x800619C0: nop

    // 0x800619C4: addiu       $t6, $zero, 0x1387
    ctx->r14 = ADD32(0, 0X1387);
    // 0x800619C8: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
L_800619CC:
    // 0x800619CC: lh          $t7, 0x42($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X42);
    // 0x800619D0: addiu       $at, $zero, 0x64D
    ctx->r1 = ADD32(0, 0X64D);
    // 0x800619D4: bne         $t7, $at, L_80061A00
    if (ctx->r15 != ctx->r1) {
        // 0x800619D8: nop
    
            goto L_80061A00;
    }
    // 0x800619D8: nop

    // 0x800619DC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800619E0: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800619E4: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x800619E8: nop

    // 0x800619EC: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x800619F0: beq         $t0, $zero, L_80061A00
    if (ctx->r8 == 0) {
        // 0x800619F4: nop
    
            goto L_80061A00;
    }
    // 0x800619F4: nop

    // 0x800619F8: addiu       $t1, $zero, 0x64E
    ctx->r9 = ADD32(0, 0X64E);
    // 0x800619FC: sh          $t1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r9;
L_80061A00:
    // 0x80061A00: lh          $a0, 0x42($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X42);
    // 0x80061A04: jal         0x80061840
    // 0x80061A08: nop

    func_80061840(rdram, ctx);
        goto after_1;
    // 0x80061A08: nop

    after_1:
    // 0x80061A0C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80061A10: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
    // 0x80061A14: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80061A18: lui         $t3, 0x809E
    ctx->r11 = S32(0X809E << 16);
    // 0x80061A1C: addiu       $t3, $t3, -0xE3C
    ctx->r11 = ADD32(ctx->r11, -0XE3C);
    // 0x80061A20: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80061A24: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061A28: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061A2C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061A30: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    // 0x80061A34: jal         0x800BD1FC
    // 0x80061A38: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x80061A38: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x80061A3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061A40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80061A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061A48: jal         0x800BD218
    // 0x80061A4C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x80061A4C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_3:
    // 0x80061A50: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80061A54: lui         $t7, 0x809F
    ctx->r15 = S32(0X809F << 16);
    // 0x80061A58: lbu         $t5, 0x6($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X6);
    // 0x80061A5C: addiu       $t7, $t7, -0x4AB0
    ctx->r15 = ADD32(ctx->r15, -0X4AB0);
    // 0x80061A60: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061A64: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061A68: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80061A6C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80061A70: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061A74: jal         0x800BD1FC
    // 0x80061A78: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x80061A78: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_4:
    // 0x80061A7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061A84: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80061A88: jal         0x800BD218
    // 0x80061A8C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x80061A8C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x80061A90: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80061A94: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80061A98: lbu         $t9, 0x6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X6);
    // 0x80061A9C: nop

    // 0x80061AA0: beq         $t9, $at, L_80061AD0
    if (ctx->r25 == ctx->r1) {
        // 0x80061AA4: nop
    
            goto L_80061AD0;
    }
    // 0x80061AA4: nop

    // 0x80061AA8: lh          $t0, 0x2C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2C);
    // 0x80061AAC: nop

    // 0x80061AB0: beq         $t0, $zero, L_80061AD0
    if (ctx->r8 == 0) {
        // 0x80061AB4: sh          $t0, 0x42($sp)
        MEM_H(0X42, ctx->r29) = ctx->r8;
            goto L_80061AD0;
    }
    // 0x80061AB4: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x80061AB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80061ABC: nop

    // 0x80061AC0: jalr        $t9
    // 0x80061AC4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80061AC4: nop

    after_6:
    // 0x80061AC8: beq         $v0, $zero, L_80061A00
    if (ctx->r2 == 0) {
        // 0x80061ACC: nop
    
            goto L_80061A00;
    }
    // 0x80061ACC: nop

L_80061AD0:
    // 0x80061AD0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80061AD4: lui         $t4, 0x809E
    ctx->r12 = S32(0X809E << 16);
    // 0x80061AD8: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x80061ADC: addiu       $t4, $t4, 0x7530
    ctx->r12 = ADD32(ctx->r12, 0X7530);
    // 0x80061AE0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061AE4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061AE8: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80061AEC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80061AF0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061AF4: jal         0x800BD1FC
    // 0x80061AF8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_7;
    // 0x80061AF8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_7:
    // 0x80061AFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061B00: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80061B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061B08: jal         0x800BD218
    // 0x80061B0C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    SysMem_DmaCopy(rdram, ctx);
        goto after_8;
    // 0x80061B0C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_8:
    // 0x80061B10: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80061B14: b           L_80061B24
    // 0x80061B18: nop

        goto L_80061B24;
    // 0x80061B18: nop

    // 0x80061B1C: b           L_80061B24
    // 0x80061B20: nop

        goto L_80061B24;
    // 0x80061B20: nop

L_80061B24:
    // 0x80061B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80061B28: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80061B2C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80061B30: jr          $ra
    // 0x80061B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80061B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006D6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D6C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D6CC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D6D0: nop

    // 0x8006D6D4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006D6D8: nop

    // 0x8006D6DC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D6E0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D6E4: jr          $ra
    // 0x8006D6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D6EC: jr          $ra
    // 0x8006D6F0: nop

    return;
    // 0x8006D6F0: nop

    // 0x8006D6F4: jr          $ra
    // 0x8006D6F8: nop

    return;
    // 0x8006D6F8: nop

;}
RECOMP_FUNC void func_8006CC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CC60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CC64: jal         0x80061488
    // 0x8006CC68: addiu       $a0, $zero, 0x482
    ctx->r4 = ADD32(0, 0X482);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CC68: addiu       $a0, $zero, 0x482
    ctx->r4 = ADD32(0, 0X482);
    after_0:
    // 0x8006CC6C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006CC70: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006CC74: b           L_8006CC84
    // 0x8006CC78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CC84;
    // 0x8006CC78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CC7C: b           L_8006CC84
    // 0x8006CC80: nop

        goto L_8006CC84;
    // 0x8006CC80: nop

L_8006CC84:
    // 0x8006CC84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CC88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC8C: jr          $ra
    // 0x8006CC90: nop

    return;
    // 0x8006CC90: nop

;}
RECOMP_FUNC void func_8005F268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F26C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F270: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005F274: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005F278: nop

    // 0x8005F27C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005F280: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8005F284: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005F288: nop

    // 0x8005F28C: bgez        $t8, L_8005F29C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005F290: sra         $t9, $t8, 3
        ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
            goto L_8005F29C;
    }
    // 0x8005F290: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005F294: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x8005F298: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8005F29C:
    // 0x8005F29C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8005F2A0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005F2A4: nop

    // 0x8005F2A8: bgez        $t0, L_8005F2BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005F2AC: andi        $t1, $t0, 0x7
        ctx->r9 = ctx->r8 & 0X7;
            goto L_8005F2BC;
    }
    // 0x8005F2AC: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x8005F2B0: beq         $t1, $zero, L_8005F2BC
    if (ctx->r9 == 0) {
        // 0x8005F2B4: nop
    
            goto L_8005F2BC;
    }
    // 0x8005F2B4: nop

    // 0x8005F2B8: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
L_8005F2BC:
    // 0x8005F2BC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8005F2C0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F2C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005F2C8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005F2CC: addiu       $t3, $t3, 0x680
    ctx->r11 = ADD32(ctx->r11, 0X680);
    // 0x8005F2D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F2D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005F2D8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8005F2DC: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8005F2E0: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005F2E4: xor         $t9, $t8, $at
    ctx->r25 = ctx->r24 ^ ctx->r1;
    // 0x8005F2E8: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8005F2EC: and         $t1, $t5, $t0
    ctx->r9 = ctx->r13 & ctx->r8;
    // 0x8005F2F0: sb          $t1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r9;
    // 0x8005F2F4: jal         0x8005F31C
    // 0x8005F2F8: nop

    func_8005F31C(rdram, ctx);
        goto after_0;
    // 0x8005F2F8: nop

    after_0:
    // 0x8005F2FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005F300: sb          $v0, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = ctx->r2;
    // 0x8005F304: b           L_8005F30C
    // 0x8005F308: nop

        goto L_8005F30C;
    // 0x8005F308: nop

L_8005F30C:
    // 0x8005F30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F314: jr          $ra
    // 0x8005F318: nop

    return;
    // 0x8005F318: nop

;}
RECOMP_FUNC void func_8009A2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A2C4: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009A2C8: nop

    // 0x8009A2CC: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8009A2D0: sw          $t7, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r15;
    // 0x8009A2D4: lw          $t8, 0xC0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC0);
    // 0x8009A2D8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8009A2DC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8009A2E0: sw          $t9, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r25;
    // 0x8009A2E4: jr          $ra
    // 0x8009A2E8: nop

    return;
    // 0x8009A2E8: nop

    // 0x8009A2EC: jr          $ra
    // 0x8009A2F0: nop

    return;
    // 0x8009A2F0: nop

;}
RECOMP_FUNC void func_80048F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048F88: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80048F8C: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x80048F90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048F94: bne         $t6, $at, L_80048FD4
    if (ctx->r14 != ctx->r1) {
        // 0x80048F98: nop
    
            goto L_80048FD4;
    }
    // 0x80048F98: nop

    // 0x80048F9C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80048FA0: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x80048FA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048FA8: bne         $t7, $at, L_80048FD4
    if (ctx->r15 != ctx->r1) {
        // 0x80048FAC: nop
    
            goto L_80048FD4;
    }
    // 0x80048FAC: nop

    // 0x80048FB0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80048FB4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80048FB8: addiu       $a1, $a1, 0xEC8
    ctx->r5 = ADD32(ctx->r5, 0XEC8);
    // 0x80048FBC: addiu       $a0, $a0, 0x7E00
    ctx->r4 = ADD32(ctx->r4, 0X7E00);
    // 0x80048FC0: jal         0x800C0640
    // 0x80048FC4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    Thread_CreateSimple(rdram, ctx);
        goto after_0;
    // 0x80048FC4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_0:
    // 0x80048FC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80048FCC: b           L_80049040
    // 0x80048FD0: sb          $v0, 0xEC8($at)
    MEM_B(0XEC8, ctx->r1) = ctx->r2;
        goto L_80049040;
    // 0x80048FD0: sb          $v0, 0xEC8($at)
    MEM_B(0XEC8, ctx->r1) = ctx->r2;
L_80048FD4:
    // 0x80048FD4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80048FD8: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80048FDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048FE0: bne         $t8, $at, L_80049020
    if (ctx->r24 != ctx->r1) {
        // 0x80048FE4: nop
    
            goto L_80049020;
    }
    // 0x80048FE4: nop

    // 0x80048FE8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80048FEC: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x80048FF0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80048FF4: bne         $t9, $at, L_80049020
    if (ctx->r25 != ctx->r1) {
        // 0x80048FF8: nop
    
            goto L_80049020;
    }
    // 0x80048FF8: nop

    // 0x80048FFC: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80049000: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80049004: addiu       $a1, $a1, 0xEC8
    ctx->r5 = ADD32(ctx->r5, 0XEC8);
    // 0x80049008: addiu       $a0, $a0, -0x5660
    ctx->r4 = ADD32(ctx->r4, -0X5660);
    // 0x8004900C: jal         0x800C0640
    // 0x80049010: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    Thread_CreateSimple(rdram, ctx);
        goto after_1;
    // 0x80049010: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_1:
    // 0x80049014: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049018: b           L_80049040
    // 0x8004901C: sb          $v0, 0xEC8($at)
    MEM_B(0XEC8, ctx->r1) = ctx->r2;
        goto L_80049040;
    // 0x8004901C: sb          $v0, 0xEC8($at)
    MEM_B(0XEC8, ctx->r1) = ctx->r2;
L_80049020:
    // 0x80049020: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80049024: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80049028: addiu       $a1, $a1, 0xEC8
    ctx->r5 = ADD32(ctx->r5, 0XEC8);
    // 0x8004902C: addiu       $a0, $a0, -0x5F4C
    ctx->r4 = ADD32(ctx->r4, -0X5F4C);
    // 0x80049030: jal         0x800C0640
    // 0x80049034: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    Thread_CreateSimple(rdram, ctx);
        goto after_2;
    // 0x80049034: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_2:
    // 0x80049038: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004903C: sb          $v0, 0xEC8($at)
    MEM_B(0XEC8, ctx->r1) = ctx->r2;
L_80049040:
    // 0x80049040: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049044: lbu         $a0, 0xEC8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XEC8);
    // 0x80049048: jal         0x800C0988
    // 0x8004904C: nop

    func_800C0988(rdram, ctx);
        goto after_3;
    // 0x8004904C: nop

    after_3:
    // 0x80049050: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x80049054: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049058: sw          $t0, 0xECC($at)
    MEM_W(0XECC, ctx->r1) = ctx->r8;
    // 0x8004905C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049060: lbu         $a0, 0xEC8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XEC8);
    // 0x80049064: jal         0x800C0E04
    // 0x80049068: nop

    Thread_GetPtr(rdram, ctx);
        goto after_4;
    // 0x80049068: nop

    after_4:
    // 0x8004906C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049070: sw          $v0, 0xEE0($at)
    MEM_W(0XEE0, ctx->r1) = ctx->r2;
    // 0x80049074: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80049078: lw          $t2, 0xEE0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XEE0);
    // 0x8004907C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80049080: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80049084: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80049088: sw          $t1, 0x2F9($at)
    MEM_W(0X2F9, ctx->r1) = ctx->r9;
    // 0x8004908C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80049090: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049094: sb          $t3, 0xEE8($at)
    MEM_B(0XEE8, ctx->r1) = ctx->r11;
    // 0x80049098: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004909C: lbu         $a0, 0xEC8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XEC8);
    // 0x800490A0: jal         0x800C0C8C
    // 0x800490A4: nop

    Thread_Start(rdram, ctx);
        goto after_5;
    // 0x800490A4: nop

    after_5:
    // 0x800490A8: b           L_800490B0
    // 0x800490AC: nop

        goto L_800490B0;
    // 0x800490AC: nop

L_800490B0:
    // 0x800490B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800490B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800490B8: jr          $ra
    // 0x800490BC: nop

    return;
    // 0x800490BC: nop

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
RECOMP_FUNC void CreateGfxTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009908C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80099090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80099094: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80099098: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009909C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800990A0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800990A4: addiu       $t6, $t6, 0x3DF8
    ctx->r14 = ADD32(ctx->r14, 0X3DF8);
    // 0x800990A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800990AC: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800990B0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800990B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800990B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800990BC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800990C0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800990C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800990C8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800990CC: addiu       $t9, $t9, 0x1950
    ctx->r25 = ADD32(ctx->r25, 0X1950);
    // 0x800990D0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800990D4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800990D8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800990DC: addiu       $t1, $t1, 0x3DF8
    ctx->r9 = ADD32(ctx->r9, 0X3DF8);
    // 0x800990E0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800990E4: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800990E8: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800990EC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800990F0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800990F4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800990F8: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800990FC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80099100: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80099104: addiu       $t4, $t4, 0x1950
    ctx->r12 = ADD32(ctx->r12, 0X1950);
    // 0x80099108: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009910C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80099110: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80099114: nop

    // 0x80099118: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x8009911C: lbu         $t7, 0x2E9($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2E9);
    // 0x80099120: nop

    // 0x80099124: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80099128: bne         $t8, $zero, L_80099138
    if (ctx->r24 != 0) {
        // 0x8009912C: nop
    
            goto L_80099138;
    }
    // 0x8009912C: nop

    // 0x80099130: b           L_8009939C
    // 0x80099134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8009939C;
    // 0x80099134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80099138:
    // 0x80099138: jal         0x800C4270
    // 0x8009913C: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8009913C: nop

    after_0:
    // 0x80099140: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80099144: lhu         $t9, 0x24FC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X24FC);
    // 0x80099148: nop

    // 0x8009914C: beq         $t9, $zero, L_8009915C
    if (ctx->r25 == 0) {
        // 0x80099150: nop
    
            goto L_8009915C;
    }
    // 0x80099150: nop

    // 0x80099154: b           L_80099160
    // 0x80099158: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80099160;
    // 0x80099158: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009915C:
    // 0x8009915C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80099160:
    // 0x80099160: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80099164: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x80099168: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8009916C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80099170: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x80099174: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80099178: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8009917C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80099180: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80099184: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80099188: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8009918C: nop

    // 0x80099190: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x80099194: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80099198: addiu       $t5, $zero, 0x63
    ctx->r13 = ADD32(0, 0X63);
    // 0x8009919C: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x800991A0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800991A4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800991A8: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800991AC: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800991B0: sw          $t8, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->r24;
    // 0x800991B4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800991B8: lhu         $t0, 0x24FC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X24FC);
    // 0x800991BC: nop

    // 0x800991C0: beq         $t0, $zero, L_800991D0
    if (ctx->r8 == 0) {
        // 0x800991C4: nop
    
            goto L_800991D0;
    }
    // 0x800991C4: nop

    // 0x800991C8: b           L_800991D4
    // 0x800991CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800991D4;
    // 0x800991CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800991D0:
    // 0x800991D0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800991D4:
    // 0x800991D4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800991D8: sll         $t2, $s0, 5
    ctx->r10 = S32(ctx->r16 << 5);
    // 0x800991DC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800991E0: ori         $at, $zero, 0x80BC
    ctx->r1 = 0 | 0X80BC;
    // 0x800991E4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800991E8: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800991EC: sw          $t4, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->r12;
    // 0x800991F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800991F4: lw          $t6, 0x24DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X24DC);
    // 0x800991F8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800991FC: nop

    // 0x80099200: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
    // 0x80099204: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80099208: nop

    // 0x8009920C: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x80099210: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80099214: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80099218: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009921C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80099220: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80099224: nop

    // 0x80099228: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8009922C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099230: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80099234: addiu       $t3, $t3, 0x6B70
    ctx->r11 = ADD32(ctx->r11, 0X6B70);
    // 0x80099238: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8009923C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80099240: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80099244: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80099248: addiu       $t6, $t6, 0x6B70
    ctx->r14 = ADD32(ctx->r14, 0X6B70);
    // 0x8009924C: addiu       $t5, $t5, 0x6C40
    ctx->r13 = ADD32(ctx->r13, 0X6C40);
    // 0x80099250: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80099254: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
    // 0x80099258: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009925C: lw          $t9, 0x72DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72DC);
    // 0x80099260: nop

    // 0x80099264: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x80099268: bne         $t0, $zero, L_80099294
    if (ctx->r8 != 0) {
        // 0x8009926C: nop
    
            goto L_80099294;
    }
    // 0x8009926C: nop

    // 0x80099270: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80099274: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80099278: addiu       $t1, $t1, 0x7BB0
    ctx->r9 = ADD32(ctx->r9, 0X7BB0);
    // 0x8009927C: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x80099280: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099284: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x80099288: addiu       $t3, $t3, 0xE20
    ctx->r11 = ADD32(ctx->r11, 0XE20);
    // 0x8009928C: b           L_800992B4
    // 0x80099290: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
        goto L_800992B4;
    // 0x80099290: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
L_80099294:
    // 0x80099294: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80099298: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8009929C: addiu       $t5, $t5, 0x6C40
    ctx->r13 = ADD32(ctx->r13, 0X6C40);
    // 0x800992A0: sw          $t5, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r13;
    // 0x800992A4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800992A8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800992AC: addiu       $t7, $t7, 0x620
    ctx->r15 = ADD32(ctx->r15, 0X620);
    // 0x800992B0: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
L_800992B4:
    // 0x800992B4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800992B8: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x800992BC: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x800992C0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800992C4: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x800992C8: sw          $t1, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r9;
    // 0x800992CC: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x800992D0: addiu       $t3, $t3, -0x69D8
    ctx->r11 = ADD32(ctx->r11, -0X69D8);
    // 0x800992D4: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x800992D8: addiu       $t7, $t5, 0xF
    ctx->r15 = ADD32(ctx->r13, 0XF);
    // 0x800992DC: sltiu       $at, $t7, 0xF
    ctx->r1 = ctx->r15 < 0XF ? 1 : 0;
    // 0x800992E0: sra         $t4, $t3, 31
    ctx->r12 = S32(SIGNED(ctx->r11) >> 31);
    // 0x800992E4: addu        $t6, $t4, $at
    ctx->r14 = ADD32(ctx->r12, ctx->r1);
    // 0x800992E8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800992EC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800992F0: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800992F4: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x800992F8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800992FC: sw          $t0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r8;
    // 0x80099300: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80099304: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x80099308: sw          $t2, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r10;
    // 0x8009930C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099310: nop

    // 0x80099314: sw          $zero, 0x28($t4)
    MEM_W(0X28, ctx->r12) = 0;
    // 0x80099318: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8009931C: nop

    // 0x80099320: sw          $zero, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = 0;
    // 0x80099324: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80099328: addiu       $t6, $t6, 0x1B58
    ctx->r14 = ADD32(ctx->r14, 0X1B58);
    // 0x8009932C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80099330: addiu       $t7, $t6, 0xF
    ctx->r15 = ADD32(ctx->r14, 0XF);
    // 0x80099334: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80099338: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8009933C: sw          $t8, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r24;
    // 0x80099340: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80099344: addiu       $t0, $zero, 0x900
    ctx->r8 = ADD32(0, 0X900);
    // 0x80099348: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
    // 0x8009934C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80099350: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80099354: nop

    // 0x80099358: sw          $t2, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r10;
    // 0x8009935C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80099360: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80099364: nop

    // 0x80099368: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    // 0x8009936C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80099370: jal         0x80097408
    // 0x80099374: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    func_80097408(rdram, ctx);
        goto after_1;
    // 0x80099374: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_1:
    // 0x80099378: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8009937C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80099380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099384: jal         0x800C4AA0
    // 0x80099388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80099388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8009938C: b           L_8009939C
    // 0x80099390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009939C;
    // 0x80099390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80099394: b           L_8009939C
    // 0x80099398: nop

        goto L_8009939C;
    // 0x80099398: nop

L_8009939C:
    // 0x8009939C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800993A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800993A4: jr          $ra
    // 0x800993A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800993A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B5E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5E90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B5E94: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800B5E98: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800B5E9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B5EA0: ori         $at, $zero, 0xE100
    ctx->r1 = 0 | 0XE100;
    // 0x800B5EA4: beq         $a1, $at, L_800B5ED8
    if (ctx->r5 == ctx->r1) {
        // 0x800B5EA8: nop
    
            goto L_800B5ED8;
    }
    // 0x800B5EA8: nop

    // 0x800B5EAC: ori         $at, $zero, 0xE101
    ctx->r1 = 0 | 0XE101;
    // 0x800B5EB0: beq         $a1, $at, L_800B5F08
    if (ctx->r5 == ctx->r1) {
        // 0x800B5EB4: nop
    
            goto L_800B5F08;
    }
    // 0x800B5EB4: nop

    // 0x800B5EB8: ori         $at, $zero, 0xE102
    ctx->r1 = 0 | 0XE102;
    // 0x800B5EBC: beq         $a1, $at, L_800B5F38
    if (ctx->r5 == ctx->r1) {
        // 0x800B5EC0: nop
    
            goto L_800B5F38;
    }
    // 0x800B5EC0: nop

    // 0x800B5EC4: ori         $at, $zero, 0xE103
    ctx->r1 = 0 | 0XE103;
    // 0x800B5EC8: beq         $a1, $at, L_800B5F68
    if (ctx->r5 == ctx->r1) {
        // 0x800B5ECC: nop
    
            goto L_800B5F68;
    }
    // 0x800B5ECC: nop

    // 0x800B5ED0: b           L_800B5F98
    // 0x800B5ED4: nop

        goto L_800B5F98;
    // 0x800B5ED4: nop

L_800B5ED8:
    // 0x800B5ED8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5EDC: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5EE0: nop

    // 0x800B5EE4: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B5EE8: nop

    // 0x800B5EEC: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800B5EF0: bne         $t8, $zero, L_800B5F00
    if (ctx->r24 != 0) {
        // 0x800B5EF4: nop
    
            goto L_800B5F00;
    }
    // 0x800B5EF4: nop

    // 0x800B5EF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B5EFC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_800B5F00:
    // 0x800B5F00: b           L_800B5F98
    // 0x800B5F04: nop

        goto L_800B5F98;
    // 0x800B5F04: nop

L_800B5F08:
    // 0x800B5F08: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5F0C: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5F10: nop

    // 0x800B5F14: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B5F18: nop

    // 0x800B5F1C: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x800B5F20: bne         $t2, $zero, L_800B5F30
    if (ctx->r10 != 0) {
        // 0x800B5F24: nop
    
            goto L_800B5F30;
    }
    // 0x800B5F24: nop

    // 0x800B5F28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B5F2C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_800B5F30:
    // 0x800B5F30: b           L_800B5F98
    // 0x800B5F34: nop

        goto L_800B5F98;
    // 0x800B5F34: nop

L_800B5F38:
    // 0x800B5F38: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B5F3C: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B5F40: nop

    // 0x800B5F44: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800B5F48: nop

    // 0x800B5F4C: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x800B5F50: bne         $t6, $zero, L_800B5F60
    if (ctx->r14 != 0) {
        // 0x800B5F54: nop
    
            goto L_800B5F60;
    }
    // 0x800B5F54: nop

    // 0x800B5F58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B5F5C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800B5F60:
    // 0x800B5F60: b           L_800B5F98
    // 0x800B5F64: nop

        goto L_800B5F98;
    // 0x800B5F64: nop

L_800B5F68:
    // 0x800B5F68: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5F6C: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5F70: nop

    // 0x800B5F74: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x800B5F78: nop

    // 0x800B5F7C: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x800B5F80: bne         $t0, $zero, L_800B5F90
    if (ctx->r8 != 0) {
        // 0x800B5F84: nop
    
            goto L_800B5F90;
    }
    // 0x800B5F84: nop

    // 0x800B5F88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800B5F8C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_800B5F90:
    // 0x800B5F90: b           L_800B5F98
    // 0x800B5F94: nop

        goto L_800B5F98;
    // 0x800B5F94: nop

L_800B5F98:
    // 0x800B5F98: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800B5F9C: b           L_800B5FAC
    // 0x800B5FA0: nop

        goto L_800B5FAC;
    // 0x800B5FA0: nop

    // 0x800B5FA4: b           L_800B5FAC
    // 0x800B5FA8: nop

        goto L_800B5FAC;
    // 0x800B5FA8: nop

L_800B5FAC:
    // 0x800B5FAC: jr          $ra
    // 0x800B5FB0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B5FB0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80067BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067BCC: jal         0x80061488
    // 0x80067BD0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067BD0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_0:
    // 0x80067BD4: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067BD8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067BDC: b           L_80067BEC
    // 0x80067BE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067BEC;
    // 0x80067BE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067BE4: b           L_80067BEC
    // 0x80067BE8: nop

        goto L_80067BEC;
    // 0x80067BE8: nop

L_80067BEC:
    // 0x80067BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067BF4: jr          $ra
    // 0x80067BF8: nop

    return;
    // 0x80067BF8: nop

;}
RECOMP_FUNC void func_8006D020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D020: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D024: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D028: nop

    // 0x8006D02C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D030: nop

    // 0x8006D034: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D038: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D03C: jr          $ra
    // 0x8006D040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D044: jr          $ra
    // 0x8006D048: nop

    return;
    // 0x8006D048: nop

    // 0x8006D04C: jr          $ra
    // 0x8006D050: nop

    return;
    // 0x8006D050: nop

;}
RECOMP_FUNC void func_8009DB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DB6C: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x8009DB70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009DB74: sw          $a0, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r4;
    // 0x8009DB78: sw          $a1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r5;
    // 0x8009DB7C: sw          $a2, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r6;
    // 0x8009DB80: sw          $a3, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r7;
    // 0x8009DB84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009DB88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009DB8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009DB90: jal         0x800C1680
    // 0x8009DB94: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x8009DB94: nop

    after_0:
    // 0x8009DB98: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009DB9C: jal         0x800C1AF4
    // 0x8009DBA0: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_1;
    // 0x8009DBA0: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_1:
    // 0x8009DBA4: jal         0x800C1B64
    // 0x8009DBA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_2;
    // 0x8009DBA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8009DBAC: lw          $a0, 0x1C0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C0);
    // 0x8009DBB0: jal         0x800C1D44
    // 0x8009DBB4: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    func_800C1D44(rdram, ctx);
        goto after_3;
    // 0x8009DBB4: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_3:
    // 0x8009DBB8: lw          $a0, 0x1AC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DBBC: jal         0x800C1D44
    // 0x8009DBC0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_4;
    // 0x8009DBC0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_4:
    // 0x8009DBC4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009DBC8: jal         0x800C1A84
    // 0x8009DBCC: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_5;
    // 0x8009DBCC: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_5:
    // 0x8009DBD0: jal         0x800C1A28
    // 0x8009DBD4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8009DBD4: nop

    after_6:
    // 0x8009DBD8: lw          $t6, 0x1AC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DBDC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009DBE0: lw          $t8, 0x7250($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7250);
    // 0x8009DBE4: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8009DBE8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009DBEC: lw          $t0, 0x7258($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7258);
    // 0x8009DBF0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8009DBF4: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8009DBF8: sw          $t1, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r9;
    // 0x8009DBFC: lw          $t2, 0x180($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X180);
    // 0x8009DC00: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8009DC04: ori         $at, $at, 0x200
    ctx->r1 = ctx->r1 | 0X200;
    // 0x8009DC08: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8009DC0C: bne         $t3, $zero, L_8009DC4C
    if (ctx->r11 != 0) {
        // 0x8009DC10: nop
    
            goto L_8009DC4C;
    }
    // 0x8009DC10: nop

    // 0x8009DC14: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8009DC18: addiu       $t4, $t4, 0x6BC8
    ctx->r12 = ADD32(ctx->r12, 0X6BC8);
    // 0x8009DC1C: lwc1        $f4, 0x38($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X38);
    // 0x8009DC20: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x8009DC24: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8009DC28: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8009DC2C: jal         0x8009A084
    // 0x8009DC30: nop

    func_8009A084(rdram, ctx);
        goto after_7;
    // 0x8009DC30: nop

    after_7:
    // 0x8009DC34: bgez        $v0, L_8009DC44
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009DC38: nop
    
            goto L_8009DC44;
    }
    // 0x8009DC38: nop

    // 0x8009DC3C: b           L_8009FC50
    // 0x8009DC40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8009FC50;
    // 0x8009DC40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009DC44:
    // 0x8009DC44: b           L_8009DCEC
    // 0x8009DC48: nop

        goto L_8009DCEC;
    // 0x8009DC48: nop

L_8009DC4C:
    // 0x8009DC4C: lw          $t5, 0x180($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X180);
    // 0x8009DC50: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8009DC54: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8009DC58: beq         $t6, $zero, L_8009DC98
    if (ctx->r14 == 0) {
        // 0x8009DC5C: nop
    
            goto L_8009DC98;
    }
    // 0x8009DC5C: nop

    // 0x8009DC60: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8009DC64: addiu       $t7, $t7, 0x6BC8
    ctx->r15 = ADD32(ctx->r15, 0X6BC8);
    // 0x8009DC68: lwc1        $f8, 0x38($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X38);
    // 0x8009DC6C: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x8009DC70: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8009DC74: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8009DC78: jal         0x8009A084
    // 0x8009DC7C: nop

    func_8009A084(rdram, ctx);
        goto after_8;
    // 0x8009DC7C: nop

    after_8:
    // 0x8009DC80: bgez        $v0, L_8009DC90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009DC84: nop
    
            goto L_8009DC90;
    }
    // 0x8009DC84: nop

    // 0x8009DC88: b           L_8009FC50
    // 0x8009DC8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8009FC50;
    // 0x8009DC8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009DC90:
    // 0x8009DC90: b           L_8009DCEC
    // 0x8009DC94: nop

        goto L_8009DCEC;
    // 0x8009DC94: nop

L_8009DC98:
    // 0x8009DC98: lw          $t8, 0x180($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X180);
    // 0x8009DC9C: nop

    // 0x8009DCA0: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x8009DCA4: beq         $t9, $zero, L_8009DCEC
    if (ctx->r25 == 0) {
        // 0x8009DCA8: nop
    
            goto L_8009DCEC;
    }
    // 0x8009DCA8: nop

    // 0x8009DCAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009DCB0: lwc1        $f16, 0x25A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25A8);
    // 0x8009DCB4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8009DCB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009DCBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009DCC0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009DCC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009DCC8: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x8009DCCC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009DCD0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009DCD4: jal         0x8009A084
    // 0x8009DCD8: nop

    func_8009A084(rdram, ctx);
        goto after_9;
    // 0x8009DCD8: nop

    after_9:
    // 0x8009DCDC: bgez        $v0, L_8009DCEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009DCE0: nop
    
            goto L_8009DCEC;
    }
    // 0x8009DCE0: nop

    // 0x8009DCE4: b           L_8009FC50
    // 0x8009DCE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8009FC50;
    // 0x8009DCE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009DCEC:
    // 0x8009DCEC: lw          $t0, 0x1AC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DCF0: lw          $t2, 0x1C0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C0);
    // 0x8009DCF4: lh          $t1, 0x11E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X11E);
    // 0x8009DCF8: lwc1        $f18, 0xE8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x8009DCFC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8009DD00: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8009DD04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009DD08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009DD0C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009DD10: nop

    // 0x8009DD14: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009DD18: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8009DD1C: nop

    // 0x8009DD20: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8009DD24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009DD28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009DD2C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009DD30: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009DD34: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8009DD38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009DD3C: sh          $t4, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r12;
    // 0x8009DD40: nop

    // 0x8009DD44: jal         0x800C1680
    // 0x8009DD48: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_10;
    // 0x8009DD48: nop

    after_10:
    // 0x8009DD4C: lw          $a0, 0x1C0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C0);
    // 0x8009DD50: jal         0x800C1AF4
    // 0x8009DD54: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_11;
    // 0x8009DD54: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_11:
    // 0x8009DD58: lw          $a0, 0x1AC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DD5C: jal         0x800C1D44
    // 0x8009DD60: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_12;
    // 0x8009DD60: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_12:
    // 0x8009DD64: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009DD68: jal         0x800C1A84
    // 0x8009DD6C: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_13;
    // 0x8009DD6C: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_13:
    // 0x8009DD70: jal         0x800C1A28
    // 0x8009DD74: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_14;
    // 0x8009DD74: nop

    after_14:
    // 0x8009DD78: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x8009DD7C: nop

    // 0x8009DD80: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8009DD84: nop

    // 0x8009DD88: sw          $t6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r14;
    // 0x8009DD8C: lwc1        $f16, 0x1B8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1B8);
    // 0x8009DD90: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009DD94: nop

    // 0x8009DD98: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8009DD9C: nop

    // 0x8009DDA0: bc1f        L_8009DDB8
    if (!c1cs) {
        // 0x8009DDA4: nop
    
            goto L_8009DDB8;
    }
    // 0x8009DDA4: nop

    // 0x8009DDA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009DDAC: lwc1        $f4, -0x7F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F4);
    // 0x8009DDB0: nop

    // 0x8009DDB4: swc1        $f4, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->f4.u32l;
L_8009DDB8:
    // 0x8009DDB8: lwc1        $f6, 0x1BC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x8009DDBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009DDC0: nop

    // 0x8009DDC4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8009DDC8: nop

    // 0x8009DDCC: bc1f        L_8009DDE4
    if (!c1cs) {
        // 0x8009DDD0: nop
    
            goto L_8009DDE4;
    }
    // 0x8009DDD0: nop

    // 0x8009DDD4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009DDD8: lwc1        $f10, -0x7F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7F0);
    // 0x8009DDDC: nop

    // 0x8009DDE0: swc1        $f10, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->f10.u32l;
L_8009DDE4:
    // 0x8009DDE4: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DDE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009DDEC: lwc1        $f16, 0xF4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x8009DDF0: lwc1        $f18, 0xFC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x8009DDF4: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009DDF8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009DDFC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8009DE00: addiu       $t8, $t8, 0x6BC8
    ctx->r24 = ADD32(ctx->r24, 0X6BC8);
    // 0x8009DE04: lwc1        $f10, 0x38($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8009DE08: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009DE0C: nop

    // 0x8009DE10: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8009DE14: swc1        $f16, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f16.u32l;
    // 0x8009DE18: lw          $t9, 0x1AC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DE1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009DE20: lwc1        $f18, 0xF8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x8009DE24: lwc1        $f4, 0xFC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XFC);
    // 0x8009DE28: lwc1        $f8, 0x7218($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009DE2C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009DE30: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8009DE34: addiu       $t0, $t0, 0x6BC8
    ctx->r8 = ADD32(ctx->r8, 0X6BC8);
    // 0x8009DE38: lwc1        $f16, 0x38($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X38);
    // 0x8009DE3C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009DE40: nop

    // 0x8009DE44: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009DE48: swc1        $f18, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f18.u32l;
    // 0x8009DE4C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8009DE50: addiu       $t1, $t1, 0x6BC8
    ctx->r9 = ADD32(ctx->r9, 0X6BC8);
    // 0x8009DE54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009DE58: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009DE5C: lwc1        $f6, 0x38($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X38);
    // 0x8009DE60: nop

    // 0x8009DE64: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009DE68: swc1        $f8, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f8.u32l;
    // 0x8009DE6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009DE70: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8009DE74: lwc1        $f19, -0x7E8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X7E8);
    // 0x8009DE78: lwc1        $f18, -0x7E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7E4);
    // 0x8009DE7C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8009DE80: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8009DE84: nop

    // 0x8009DE88: bc1f        L_8009DEC0
    if (!c1cs) {
        // 0x8009DE8C: nop
    
            goto L_8009DEC0;
    }
    // 0x8009DE8C: nop

    // 0x8009DE90: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009DE94: lwc1        $f5, -0x7E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X7E0);
    // 0x8009DE98: lwc1        $f4, -0x7DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7DC);
    // 0x8009DE9C: nop

    // 0x8009DEA0: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x8009DEA4: nop

    // 0x8009DEA8: bc1f        L_8009DEC0
    if (!c1cs) {
        // 0x8009DEAC: nop
    
            goto L_8009DEC0;
    }
    // 0x8009DEAC: nop

    // 0x8009DEB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009DEB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009DEB8: nop

    // 0x8009DEBC: swc1        $f6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f6.u32l;
L_8009DEC0:
    // 0x8009DEC0: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8009DEC4: addiu       $t2, $t2, 0x6BC8
    ctx->r10 = ADD32(ctx->r10, 0X6BC8);
    // 0x8009DEC8: lwc1        $f8, 0x30($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X30);
    // 0x8009DECC: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8009DED0: lwc1        $f16, 0x1B8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1B8);
    // 0x8009DED4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8009DED8: nop

    // 0x8009DEDC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009DEE0: swc1        $f4, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f4.u32l;
    // 0x8009DEE4: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8009DEE8: addiu       $t3, $t3, 0x6BC8
    ctx->r11 = ADD32(ctx->r11, 0X6BC8);
    // 0x8009DEEC: lwc1        $f6, 0x34($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X34);
    // 0x8009DEF0: lwc1        $f8, 0x128($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8009DEF4: lwc1        $f18, 0x1BC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x8009DEF8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009DEFC: nop

    // 0x8009DF00: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8009DF04: swc1        $f16, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f16.u32l;
    // 0x8009DF08: lw          $t4, 0x180($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X180);
    // 0x8009DF0C: nop

    // 0x8009DF10: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x8009DF14: beq         $t5, $zero, L_8009DF54
    if (ctx->r13 == 0) {
        // 0x8009DF18: nop
    
            goto L_8009DF54;
    }
    // 0x8009DF18: nop

    // 0x8009DF1C: lw          $t6, 0x1AC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DF20: nop

    // 0x8009DF24: lwc1        $f4, 0xF4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XF4);
    // 0x8009DF28: lwc1        $f6, 0xFC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XFC);
    // 0x8009DF2C: nop

    // 0x8009DF30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009DF34: swc1        $f8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f8.u32l;
    // 0x8009DF38: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009DF3C: nop

    // 0x8009DF40: lwc1        $f10, 0xF8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XF8);
    // 0x8009DF44: lwc1        $f18, 0xFC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x8009DF48: nop

    // 0x8009DF4C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8009DF50: swc1        $f16, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
L_8009DF54:
    // 0x8009DF54: lwc1        $f4, 0x138($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8009DF58: lwc1        $f6, 0x1B8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1B8);
    // 0x8009DF5C: nop

    // 0x8009DF60: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009DF64: swc1        $f8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f8.u32l;
    // 0x8009DF68: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8009DF6C: lwc1        $f18, 0x1BC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x8009DF70: nop

    // 0x8009DF74: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8009DF78: swc1        $f16, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
    // 0x8009DF7C: lwc1        $f6, 0x138($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8009DF80: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8009DF84: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8009DF88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009DF8C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009DF90: nop

    // 0x8009DF94: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x8009DF98: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8009DF9C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8009DFA0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009DFA4: nop

    // 0x8009DFA8: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8009DFAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009DFB0: nop

    // 0x8009DFB4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8009DFB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009DFBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009DFC0: nop

    // 0x8009DFC4: cvt.w.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_D(ctx->f16.d);
    // 0x8009DFC8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8009DFCC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8009DFD0: sh          $t9, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r25;
    // 0x8009DFD4: nop

    // 0x8009DFD8: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8009DFDC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8009DFE0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8009DFE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009DFE8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8009DFEC: nop

    // 0x8009DFF0: div.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x8009DFF4: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8009DFF8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009DFFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009E000: nop

    // 0x8009E004: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8009E008: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8009E00C: nop

    // 0x8009E010: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8009E014: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009E018: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009E01C: nop

    // 0x8009E020: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x8009E024: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8009E028: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8009E02C: sh          $t1, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r9;
    // 0x8009E030: nop

    // 0x8009E034: lw          $t2, 0x1AC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E038: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009E03C: lw          $t3, 0x128($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X128);
    // 0x8009E040: nop

    // 0x8009E044: sw          $t3, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r11;
    // 0x8009E048: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E04C: nop

    // 0x8009E050: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8009E054: sw          $t5, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r13;
    // 0x8009E058: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x8009E05C: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x8009E060: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8009E064: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x8009E068: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009E06C: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8009E070: nop

    // 0x8009E074: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8009E078: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E07C: nop

    // 0x8009E080: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8009E084: sw          $t0, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r8;
    // 0x8009E088: sw          $t9, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r25;
    // 0x8009E08C: lw          $t2, 0x120($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X120);
    // 0x8009E090: lui         $t1, 0xBB00
    ctx->r9 = S32(0XBB00 << 16);
    // 0x8009E094: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x8009E098: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009E09C: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x8009E0A0: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8009E0A4: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x8009E0A8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8009E0AC: lw          $t5, 0x180($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X180);
    // 0x8009E0B0: nop

    // 0x8009E0B4: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x8009E0B8: beq         $t6, $zero, L_8009E164
    if (ctx->r14 == 0) {
        // 0x8009E0BC: nop
    
            goto L_8009E164;
    }
    // 0x8009E0BC: nop

    // 0x8009E0C0: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E0C4: nop

    // 0x8009E0C8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8009E0CC: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x8009E0D0: sw          $t7, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r15;
    // 0x8009E0D4: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x8009E0D8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8009E0DC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8009E0E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8009E0E4: lh          $t1, -0x4CDC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CDC);
    // 0x8009E0E8: lw          $t3, 0x11C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X11C);
    // 0x8009E0EC: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8009E0F0: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8009E0F4: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E0F8: nop

    // 0x8009E0FC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8009E100: sw          $t5, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r13;
    // 0x8009E104: sw          $t4, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r12;
    // 0x8009E108: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x8009E10C: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x8009E110: ori         $t6, $t6, 0x97FF
    ctx->r14 = ctx->r14 | 0X97FF;
    // 0x8009E114: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009E118: lw          $t9, 0x118($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X118);
    // 0x8009E11C: lui         $t8, 0xFF2C
    ctx->r24 = S32(0XFF2C << 16);
    // 0x8009E120: ori         $t8, $t8, 0xFE7F
    ctx->r24 = ctx->r24 | 0XFE7F;
    // 0x8009E124: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8009E128: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E12C: nop

    // 0x8009E130: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009E134: sw          $t1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r9;
    // 0x8009E138: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
    // 0x8009E13C: lw          $t3, 0x114($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X114);
    // 0x8009E140: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8009E144: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8009E148: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8009E14C: lw          $t5, 0x114($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X114);
    // 0x8009E150: lui         $t4, 0xF0A
    ctx->r12 = S32(0XF0A << 16);
    // 0x8009E154: ori         $t4, $t4, 0x233
    ctx->r12 = ctx->r12 | 0X233;
    // 0x8009E158: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8009E15C: b           L_8009E284
    // 0x8009E160: nop

        goto L_8009E284;
    // 0x8009E160: nop

L_8009E164:
    // 0x8009E164: lw          $t6, 0x180($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X180);
    // 0x8009E168: nop

    // 0x8009E16C: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8009E170: beq         $t7, $zero, L_8009E21C
    if (ctx->r15 == 0) {
        // 0x8009E174: nop
    
            goto L_8009E21C;
    }
    // 0x8009E174: nop

    // 0x8009E178: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E17C: nop

    // 0x8009E180: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009E184: sw          $t9, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r25;
    // 0x8009E188: sw          $t8, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r24;
    // 0x8009E18C: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x8009E190: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8009E194: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009E198: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8009E19C: lh          $t2, -0x4CDC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CDC);
    // 0x8009E1A0: lw          $t4, 0x110($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X110);
    // 0x8009E1A4: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8009E1A8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8009E1AC: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E1B0: nop

    // 0x8009E1B4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8009E1B8: sw          $t6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r14;
    // 0x8009E1BC: sw          $t5, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r13;
    // 0x8009E1C0: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x8009E1C4: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8009E1C8: ori         $t7, $t7, 0x97FF
    ctx->r15 = ctx->r15 | 0X97FF;
    // 0x8009E1CC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009E1D0: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x8009E1D4: lui         $t9, 0xFF2C
    ctx->r25 = S32(0XFF2C << 16);
    // 0x8009E1D8: ori         $t9, $t9, 0xFE7F
    ctx->r25 = ctx->r25 | 0XFE7F;
    // 0x8009E1DC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8009E1E0: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E1E4: nop

    // 0x8009E1E8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8009E1EC: sw          $t2, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r10;
    // 0x8009E1F0: sw          $t1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r9;
    // 0x8009E1F4: lw          $t4, 0x108($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X108);
    // 0x8009E1F8: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x8009E1FC: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x8009E200: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8009E204: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x8009E208: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8009E20C: ori         $t5, $t5, 0x4A50
    ctx->r13 = ctx->r13 | 0X4A50;
    // 0x8009E210: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8009E214: b           L_8009E284
    // 0x8009E218: nop

        goto L_8009E284;
    // 0x8009E218: nop

L_8009E21C:
    // 0x8009E21C: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E220: nop

    // 0x8009E224: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8009E228: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x8009E22C: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x8009E230: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x8009E234: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8009E238: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8009E23C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8009E240: lw          $t2, 0x104($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X104);
    // 0x8009E244: lui         $t1, 0xFFFC
    ctx->r9 = S32(0XFFFC << 16);
    // 0x8009E248: ori         $t1, $t1, 0xF279
    ctx->r9 = ctx->r9 | 0XF279;
    // 0x8009E24C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8009E250: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E254: nop

    // 0x8009E258: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8009E25C: sw          $t4, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r12;
    // 0x8009E260: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x8009E264: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x8009E268: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8009E26C: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x8009E270: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8009E274: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x8009E278: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x8009E27C: ori         $t7, $t7, 0x3078
    ctx->r15 = ctx->r15 | 0X3078;
    // 0x8009E280: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_8009E284:
    // 0x8009E284: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E288: nop

    // 0x8009E28C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8009E290: sw          $t0, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r8;
    // 0x8009E294: sw          $t9, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r25;
    // 0x8009E298: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8009E29C: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x8009E2A0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009E2A4: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8009E2A8: addiu       $t3, $zero, 0x205
    ctx->r11 = ADD32(0, 0X205);
    // 0x8009E2AC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8009E2B0: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E2B4: nop

    // 0x8009E2B8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8009E2BC: sw          $t6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r14;
    // 0x8009E2C0: sw          $t5, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r13;
    // 0x8009E2C4: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8009E2C8: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8009E2CC: ori         $t7, $t7, 0x1301
    ctx->r15 = ctx->r15 | 0X1301;
    // 0x8009E2D0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009E2D4: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8009E2D8: nop

    // 0x8009E2DC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009E2E0: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E2E4: nop

    // 0x8009E2E8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009E2EC: sw          $t1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r9;
    // 0x8009E2F0: sw          $t0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r8;
    // 0x8009E2F4: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x8009E2F8: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8009E2FC: ori         $t2, $t2, 0x1102
    ctx->r10 = ctx->r10 | 0X1102;
    // 0x8009E300: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8009E304: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x8009E308: nop

    // 0x8009E30C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8009E310: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E314: nop

    // 0x8009E318: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8009E31C: sw          $t6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r14;
    // 0x8009E320: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
    // 0x8009E324: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x8009E328: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8009E32C: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x8009E330: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009E334: lw          $t9, 0xF0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF0);
    // 0x8009E338: nop

    // 0x8009E33C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009E340: lw          $t0, 0x1AC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E344: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009E348: lh          $t1, 0x116($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X116);
    // 0x8009E34C: nop

    // 0x8009E350: beq         $t1, $at, L_8009E5E0
    if (ctx->r9 == ctx->r1) {
        // 0x8009E354: nop
    
            goto L_8009E5E0;
    }
    // 0x8009E354: nop

    // 0x8009E358: lw          $t2, 0x1AC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E35C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E360: lh          $t3, 0x116($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X116);
    // 0x8009E364: nop

    // 0x8009E368: bne         $t3, $at, L_8009E490
    if (ctx->r11 != ctx->r1) {
        // 0x8009E36C: nop
    
            goto L_8009E490;
    }
    // 0x8009E36C: nop

    // 0x8009E370: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E374: nop

    // 0x8009E378: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8009E37C: sw          $t5, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r13;
    // 0x8009E380: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
    // 0x8009E384: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8009E388: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8009E38C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009E390: lw          $t8, 0x1AC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E394: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x8009E398: lw          $t9, 0x138($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X138);
    // 0x8009E39C: nop

    // 0x8009E3A0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8009E3A4: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E3A8: nop

    // 0x8009E3AC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8009E3B0: sw          $t2, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r10;
    // 0x8009E3B4: sw          $t1, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r9;
    // 0x8009E3B8: lw          $t4, 0xE8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE8);
    // 0x8009E3BC: lui         $t3, 0xE800
    ctx->r11 = S32(0XE800 << 16);
    // 0x8009E3C0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8009E3C4: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x8009E3C8: nop

    // 0x8009E3CC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8009E3D0: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E3D4: nop

    // 0x8009E3D8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8009E3DC: sw          $t7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r15;
    // 0x8009E3E0: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x8009E3E4: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8009E3E8: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8009E3EC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8009E3F0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009E3F4: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x8009E3F8: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009E3FC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8009E400: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E404: nop

    // 0x8009E408: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8009E40C: sw          $t3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r11;
    // 0x8009E410: sw          $t2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r10;
    // 0x8009E414: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x8009E418: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x8009E41C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009E420: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8009E424: nop

    // 0x8009E428: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8009E42C: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E430: nop

    // 0x8009E434: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8009E438: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x8009E43C: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8009E440: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x8009E444: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8009E448: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8009E44C: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x8009E450: lui         $t1, 0x73F
    ctx->r9 = S32(0X73F << 16);
    // 0x8009E454: ori         $t1, $t1, 0xC000
    ctx->r9 = ctx->r9 | 0XC000;
    // 0x8009E458: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8009E45C: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E460: nop

    // 0x8009E464: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8009E468: sw          $t4, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r12;
    // 0x8009E46C: sw          $t3, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r11;
    // 0x8009E470: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x8009E474: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8009E478: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8009E47C: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x8009E480: nop

    // 0x8009E484: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8009E488: b           L_8009E5A8
    // 0x8009E48C: nop

        goto L_8009E5A8;
    // 0x8009E48C: nop

L_8009E490:
    // 0x8009E490: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E494: nop

    // 0x8009E498: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009E49C: sw          $t9, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r25;
    // 0x8009E4A0: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
    // 0x8009E4A4: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8009E4A8: lui         $t0, 0xFD10
    ctx->r8 = S32(0XFD10 << 16);
    // 0x8009E4AC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009E4B0: lw          $t2, 0x1AC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E4B4: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x8009E4B8: lw          $t3, 0x138($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X138);
    // 0x8009E4BC: nop

    // 0x8009E4C0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8009E4C4: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E4C8: nop

    // 0x8009E4CC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8009E4D0: sw          $t6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r14;
    // 0x8009E4D4: sw          $t5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r13;
    // 0x8009E4D8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8009E4DC: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8009E4E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009E4E4: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x8009E4E8: nop

    // 0x8009E4EC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009E4F0: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E4F4: nop

    // 0x8009E4F8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009E4FC: sw          $t1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r9;
    // 0x8009E500: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8009E504: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8009E508: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x8009E50C: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x8009E510: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8009E514: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8009E518: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x8009E51C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8009E520: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E524: nop

    // 0x8009E528: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8009E52C: sw          $t7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r15;
    // 0x8009E530: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8009E534: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8009E538: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8009E53C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009E540: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8009E544: nop

    // 0x8009E548: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009E54C: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E550: nop

    // 0x8009E554: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8009E558: sw          $t2, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r10;
    // 0x8009E55C: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x8009E560: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x8009E564: lui         $t3, 0xF000
    ctx->r11 = S32(0XF000 << 16);
    // 0x8009E568: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8009E56C: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x8009E570: lui         $t5, 0x703
    ctx->r13 = S32(0X703 << 16);
    // 0x8009E574: ori         $t5, $t5, 0xC000
    ctx->r13 = ctx->r13 | 0XC000;
    // 0x8009E578: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8009E57C: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E580: nop

    // 0x8009E584: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8009E588: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x8009E58C: sw          $t7, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r15;
    // 0x8009E590: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x8009E594: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009E598: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8009E59C: lw          $t1, 0xC0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC0);
    // 0x8009E5A0: nop

    // 0x8009E5A4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
L_8009E5A8:
    // 0x8009E5A8: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E5AC: nop

    // 0x8009E5B0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8009E5B4: sw          $t3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r11;
    // 0x8009E5B8: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x8009E5BC: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x8009E5C0: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x8009E5C4: ori         $t4, $t4, 0xE02
    ctx->r12 = ctx->r12 | 0XE02;
    // 0x8009E5C8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009E5CC: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8009E5D0: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8009E5D4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8009E5D8: b           L_8009E610
    // 0x8009E5DC: nop

        goto L_8009E610;
    // 0x8009E5DC: nop

L_8009E5E0:
    // 0x8009E5E0: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E5E4: nop

    // 0x8009E5E8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009E5EC: sw          $t9, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r25;
    // 0x8009E5F0: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8009E5F4: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8009E5F8: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8009E5FC: ori         $t0, $t0, 0xE02
    ctx->r8 = ctx->r8 | 0XE02;
    // 0x8009E600: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009E604: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x8009E608: nop

    // 0x8009E60C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_8009E610:
    // 0x8009E610: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E614: nop

    // 0x8009E618: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8009E61C: sw          $t4, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r12;
    // 0x8009E620: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x8009E624: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8009E628: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8009E62C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8009E630: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8009E634: nop

    // 0x8009E638: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8009E63C: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E640: nop

    // 0x8009E644: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009E648: sw          $t9, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r25;
    // 0x8009E64C: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x8009E650: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8009E654: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8009E658: ori         $t0, $t0, 0x903
    ctx->r8 = ctx->r8 | 0X903;
    // 0x8009E65C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009E660: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x8009E664: addiu       $t2, $zero, 0xC00
    ctx->r10 = ADD32(0, 0XC00);
    // 0x8009E668: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8009E66C: lw          $t4, 0x180($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X180);
    // 0x8009E670: nop

    // 0x8009E674: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8009E678: bne         $t5, $zero, L_8009E6B8
    if (ctx->r13 != 0) {
        // 0x8009E67C: nop
    
            goto L_8009E6B8;
    }
    // 0x8009E67C: nop

    // 0x8009E680: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E684: nop

    // 0x8009E688: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8009E68C: sw          $t7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r15;
    // 0x8009E690: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x8009E694: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8009E698: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8009E69C: ori         $t8, $t8, 0xC02
    ctx->r24 = ctx->r24 | 0XC02;
    // 0x8009E6A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009E6A4: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8009E6A8: nop

    // 0x8009E6AC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009E6B0: b           L_8009E6E8
    // 0x8009E6B4: nop

        goto L_8009E6E8;
    // 0x8009E6B4: nop

L_8009E6B8:
    // 0x8009E6B8: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009E6BC: nop

    // 0x8009E6C0: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8009E6C4: sw          $t2, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r10;
    // 0x8009E6C8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x8009E6CC: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x8009E6D0: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8009E6D4: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x8009E6D8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8009E6DC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8009E6E0: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x8009E6E4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_8009E6E8:
    // 0x8009E6E8: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E6EC: nop

    // 0x8009E6F0: lh          $t8, 0x100($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X100);
    // 0x8009E6F4: nop

    // 0x8009E6F8: sw          $t8, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r24;
    // 0x8009E6FC: lw          $t9, 0x1AC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E700: nop

    // 0x8009E704: lh          $t0, 0x102($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X102);
    // 0x8009E708: nop

    // 0x8009E70C: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009E710: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E714: nop

    // 0x8009E718: lh          $t2, 0x100($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X100);
    // 0x8009E71C: nop

    // 0x8009E720: sw          $t2, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r10;
    // 0x8009E724: lw          $t3, 0x198($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X198);
    // 0x8009E728: nop

    // 0x8009E72C: bgez        $t3, L_8009E73C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8009E730: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8009E73C;
    }
    // 0x8009E730: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8009E734: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8009E738: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8009E73C:
    // 0x8009E73C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8009E740: sw          $t5, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r13;
    // 0x8009E744: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8009E748: sw          $t6, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r14;
L_8009E74C:
    // 0x8009E74C: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x8009E750: nop

    // 0x8009E754: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8009E758: beq         $t8, $zero, L_8009E780
    if (ctx->r24 == 0) {
        // 0x8009E75C: nop
    
            goto L_8009E780;
    }
    // 0x8009E75C: nop

    // 0x8009E760: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
    // 0x8009E764: nop

    // 0x8009E768: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x8009E76C: beq         $t0, $zero, L_8009E778
    if (ctx->r8 == 0) {
        // 0x8009E770: nop
    
            goto L_8009E778;
    }
    // 0x8009E770: nop

    // 0x8009E774: sw          $zero, 0x174($sp)
    MEM_W(0X174, ctx->r29) = 0;
L_8009E778:
    // 0x8009E778: b           L_8009E7A4
    // 0x8009E77C: nop

        goto L_8009E7A4;
    // 0x8009E77C: nop

L_8009E780:
    // 0x8009E780: lw          $t1, 0x16C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X16C);
    // 0x8009E784: nop

    // 0x8009E788: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8009E78C: sw          $t2, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r10;
    // 0x8009E790: lw          $t3, 0x174($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X174);
    // 0x8009E794: nop

    // 0x8009E798: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8009E79C: bgtz        $t4, L_8009E74C
    if (SIGNED(ctx->r12) > 0) {
        // 0x8009E7A0: sw          $t4, 0x174($sp)
        MEM_W(0X174, ctx->r29) = ctx->r12;
            goto L_8009E74C;
    }
    // 0x8009E7A0: sw          $t4, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r12;
L_8009E7A4:
    // 0x8009E7A4: sw          $zero, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = 0;
    // 0x8009E7A8: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009E7AC: nop

    // 0x8009E7B0: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x8009E7B4: lw          $t6, 0x1AC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E7B8: nop

    // 0x8009E7BC: lhu         $t7, 0x114($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X114);
    // 0x8009E7C0: nop

    // 0x8009E7C4: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x8009E7C8: beq         $at, $zero, L_8009E9B4
    if (ctx->r1 == 0) {
        // 0x8009E7CC: nop
    
            goto L_8009E9B4;
    }
    // 0x8009E7CC: nop

    // 0x8009E7D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8009E7D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009E7D8: addu        $at, $at, $t7
    gpr jr_addend_8009E7E4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8009E7DC: lw          $t7, -0x7D8($at)
    ctx->r15 = ADD32(ctx->r1, -0X7D8);
    // 0x8009E7E0: nop

    // 0x8009E7E4: jr          $t7
    // 0x8009E7E8: nop

    switch (jr_addend_8009E7E4 >> 2) {
        case 0: goto L_8009E7EC; break;
        case 1: goto L_8009E7FC; break;
        case 2: goto L_8009E830; break;
        case 3: goto L_8009E854; break;
        case 4: goto L_8009E884; break;
        case 5: goto L_8009E8D8; break;
        case 6: goto L_8009E91C; break;
        case 7: goto L_8009E93C; break;
        case 8: goto L_8009E980; break;
        default: switch_error(__func__, 0x8009E7E4, 0x800EF828);
    }
    // 0x8009E7E8: nop

L_8009E7EC:
    // 0x8009E7EC: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x8009E7F0: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
    // 0x8009E7F4: b           L_8009E9B4
    // 0x8009E7F8: nop

        goto L_8009E9B4;
    // 0x8009E7F8: nop

L_8009E7FC:
    // 0x8009E7FC: lw          $t8, 0x1AC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E800: nop

    // 0x8009E804: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x8009E808: nop

    // 0x8009E80C: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8009E810: bgez        $t0, L_8009E820
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009E814: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8009E820;
    }
    // 0x8009E814: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8009E818: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8009E81C: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8009E820:
    // 0x8009E820: sw          $t1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r9;
    // 0x8009E824: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
    // 0x8009E828: b           L_8009E9B4
    // 0x8009E82C: nop

        goto L_8009E9B4;
    // 0x8009E82C: nop

L_8009E830:
    // 0x8009E830: lw          $t2, 0x1AC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E834: nop

    // 0x8009E838: lh          $t3, 0x100($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X100);
    // 0x8009E83C: nop

    // 0x8009E840: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8009E844: sw          $t4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r12;
    // 0x8009E848: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
    // 0x8009E84C: b           L_8009E9B4
    // 0x8009E850: nop

        goto L_8009E9B4;
    // 0x8009E850: nop

L_8009E854:
    // 0x8009E854: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x8009E858: lw          $t5, 0x1AC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E85C: nop

    // 0x8009E860: lh          $t6, 0x102($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X102);
    // 0x8009E864: nop

    // 0x8009E868: bgez        $t6, L_8009E878
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8009E86C: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8009E878;
    }
    // 0x8009E86C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8009E870: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8009E874: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8009E878:
    // 0x8009E878: sw          $t7, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r15;
    // 0x8009E87C: b           L_8009E9B4
    // 0x8009E880: nop

        goto L_8009E9B4;
    // 0x8009E880: nop

L_8009E884:
    // 0x8009E884: lw          $t8, 0x1AC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E888: nop

    // 0x8009E88C: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x8009E890: nop

    // 0x8009E894: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8009E898: bgez        $t0, L_8009E8A8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009E89C: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8009E8A8;
    }
    // 0x8009E89C: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8009E8A0: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8009E8A4: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8009E8A8:
    // 0x8009E8A8: sw          $t1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r9;
    // 0x8009E8AC: lw          $t2, 0x1AC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E8B0: nop

    // 0x8009E8B4: lh          $t3, 0x102($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X102);
    // 0x8009E8B8: nop

    // 0x8009E8BC: bgez        $t3, L_8009E8CC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8009E8C0: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8009E8CC;
    }
    // 0x8009E8C0: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8009E8C4: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8009E8C8: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8009E8CC:
    // 0x8009E8CC: sw          $t4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r12;
    // 0x8009E8D0: b           L_8009E9B4
    // 0x8009E8D4: nop

        goto L_8009E9B4;
    // 0x8009E8D4: nop

L_8009E8D8:
    // 0x8009E8D8: lw          $t5, 0x1AC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E8DC: nop

    // 0x8009E8E0: lh          $t6, 0x100($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X100);
    // 0x8009E8E4: nop

    // 0x8009E8E8: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8009E8EC: sw          $t7, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r15;
    // 0x8009E8F0: lw          $t8, 0x1AC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E8F4: nop

    // 0x8009E8F8: lh          $t9, 0x102($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X102);
    // 0x8009E8FC: nop

    // 0x8009E900: bgez        $t9, L_8009E910
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8009E904: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8009E910;
    }
    // 0x8009E904: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8009E908: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8009E90C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8009E910:
    // 0x8009E910: sw          $t0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r8;
    // 0x8009E914: b           L_8009E9B4
    // 0x8009E918: nop

        goto L_8009E9B4;
    // 0x8009E918: nop

L_8009E91C:
    // 0x8009E91C: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x8009E920: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E924: nop

    // 0x8009E928: lh          $t2, 0x102($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X102);
    // 0x8009E92C: nop

    // 0x8009E930: sw          $t2, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r10;
    // 0x8009E934: b           L_8009E9B4
    // 0x8009E938: nop

        goto L_8009E9B4;
    // 0x8009E938: nop

L_8009E93C:
    // 0x8009E93C: lw          $t3, 0x1AC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E940: nop

    // 0x8009E944: lh          $t4, 0x100($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X100);
    // 0x8009E948: nop

    // 0x8009E94C: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8009E950: bgez        $t5, L_8009E960
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009E954: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8009E960;
    }
    // 0x8009E954: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8009E958: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8009E95C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8009E960:
    // 0x8009E960: sw          $t6, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r14;
    // 0x8009E964: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E968: nop

    // 0x8009E96C: lh          $t8, 0x102($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X102);
    // 0x8009E970: nop

    // 0x8009E974: sw          $t8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r24;
    // 0x8009E978: b           L_8009E9B4
    // 0x8009E97C: nop

        goto L_8009E9B4;
    // 0x8009E97C: nop

L_8009E980:
    // 0x8009E980: lw          $t9, 0x1AC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E984: nop

    // 0x8009E988: lh          $t0, 0x100($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X100);
    // 0x8009E98C: nop

    // 0x8009E990: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8009E994: sw          $t1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r9;
    // 0x8009E998: lw          $t2, 0x1AC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009E99C: nop

    // 0x8009E9A0: lh          $t3, 0x102($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X102);
    // 0x8009E9A4: nop

    // 0x8009E9A8: sw          $t3, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r11;
    // 0x8009E9AC: b           L_8009E9B4
    // 0x8009E9B0: nop

        goto L_8009E9B4;
    // 0x8009E9B0: nop

L_8009E9B4:
    // 0x8009E9B4: lw          $t4, 0x180($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X180);
    // 0x8009E9B8: nop

    // 0x8009E9BC: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x8009E9C0: bne         $t5, $zero, L_8009EA00
    if (ctx->r13 != 0) {
        // 0x8009E9C4: nop
    
            goto L_8009EA00;
    }
    // 0x8009E9C4: nop

    // 0x8009E9C8: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x8009E9CC: lwc1        $f18, 0x138($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8009E9D0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009E9D4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8009E9D8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E9DC: lwc1        $f4, 0x1B0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x8009E9E0: lwc1        $f6, 0x130($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X130);
    // 0x8009E9E4: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8009E9E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009E9EC: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8009E9F0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8009E9F4: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8009E9F8: b           L_8009EA68
    // 0x8009E9FC: swc1        $f16, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f16.u32l;
        goto L_8009EA68;
    // 0x8009E9FC: swc1        $f16, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f16.u32l;
L_8009EA00:
    // 0x8009EA00: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009EA04: lwc1        $f6, 0x130($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X130);
    // 0x8009EA08: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8009EA0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009EA10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009EA14: nop

    // 0x8009EA18: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009EA1C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009EA20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8009EA24: sw          $t8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r24;
    // 0x8009EA28: nop

    // 0x8009EA2C: lw          $t9, 0x17C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X17C);
    // 0x8009EA30: lwc1        $f18, 0x138($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8009EA34: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8009EA38: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8009EA3C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009EA40: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009EA44: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8009EA48: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8009EA4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EA50: lwc1        $f8, 0x1B0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x8009EA54: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009EA58: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8009EA5C: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8009EA60: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8009EA64: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
L_8009EA68:
    // 0x8009EA68: lw          $t1, 0x198($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X198);
    // 0x8009EA6C: lwc1        $f18, 0x138($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8009EA70: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8009EA74: lwc1        $f6, 0x158($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8009EA78: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009EA7C: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8009EA80: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8009EA84: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
    // 0x8009EA88: lw          $t2, 0x180($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X180);
    // 0x8009EA8C: nop

    // 0x8009EA90: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8009EA94: bne         $t3, $zero, L_8009EAA8
    if (ctx->r11 != 0) {
        // 0x8009EA98: nop
    
            goto L_8009EAA8;
    }
    // 0x8009EA98: nop

    // 0x8009EA9C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009EAA0: b           L_8009EAC0
    // 0x8009EAA4: swc1        $f16, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f16.u32l;
        goto L_8009EAC0;
    // 0x8009EAA4: swc1        $f16, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f16.u32l;
L_8009EAA8:
    // 0x8009EAA8: lw          $t4, 0x198($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X198);
    // 0x8009EAAC: nop

    // 0x8009EAB0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8009EAB4: nop

    // 0x8009EAB8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009EABC: swc1        $f18, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f18.u32l;
L_8009EAC0:
    // 0x8009EAC0: lwc1        $f10, 0x158($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8009EAC4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8009EAC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009EACC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8009EAD0: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8009EAD4: nop

    // 0x8009EAD8: bc1f        L_8009EB04
    if (!c1cs) {
        // 0x8009EADC: nop
    
            goto L_8009EB04;
    }
    // 0x8009EADC: nop

    // 0x8009EAE0: lwc1        $f16, 0x158($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8009EAE4: lwc1        $f8, 0x138($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8009EAE8: lwc1        $f10, 0x144($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8009EAEC: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8009EAF0: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8009EAF4: swc1        $f6, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f6.u32l;
    // 0x8009EAF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009EAFC: b           L_8009EB58
    // 0x8009EB00: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
        goto L_8009EB58;
    // 0x8009EB00: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
L_8009EB04:
    // 0x8009EB04: lwc1        $f16, 0x158($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8009EB08: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x8009EB0C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8009EB10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009EB14: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8009EB18: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8009EB1C: nop

    // 0x8009EB20: bc1f        L_8009EB58
    if (!c1cs) {
        // 0x8009EB24: nop
    
            goto L_8009EB58;
    }
    // 0x8009EB24: nop

    // 0x8009EB28: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009EB2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EB30: lwc1        $f6, 0x158($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8009EB34: lwc1        $f16, 0x138($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8009EB38: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8009EB3C: nop

    // 0x8009EB40: div.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8009EB44: swc1        $f8, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f8.u32l;
    // 0x8009EB48: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009EB4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009EB50: nop

    // 0x8009EB54: swc1        $f10, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f10.u32l;
L_8009EB58:
    // 0x8009EB58: lwc1        $f18, 0x150($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009EB5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009EB60: nop

    // 0x8009EB64: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8009EB68: nop

    // 0x8009EB6C: bc1f        L_8009EB80
    if (!c1cs) {
        // 0x8009EB70: nop
    
            goto L_8009EB80;
    }
    // 0x8009EB70: nop

    // 0x8009EB74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009EB78: b           L_8009EBB0
    // 0x8009EB7C: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
        goto L_8009EBB0;
    // 0x8009EB7C: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
L_8009EB80:
    // 0x8009EB80: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009EB84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009EB88: lwc1        $f16, 0x150($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009EB8C: nop

    // 0x8009EB90: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8009EB94: nop

    // 0x8009EB98: bc1f        L_8009EBB0
    if (!c1cs) {
        // 0x8009EB9C: nop
    
            goto L_8009EBB0;
    }
    // 0x8009EB9C: nop

    // 0x8009EBA0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009EBA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009EBA8: nop

    // 0x8009EBAC: swc1        $f10, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f10.u32l;
L_8009EBB0:
    // 0x8009EBB0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009EBB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009EBB8: lwc1        $f18, 0x158($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8009EBBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009EBC0: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8009EBC4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8009EBC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009EBCC: nop

    // 0x8009EBD0: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009EBD4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009EBD8: nop

    // 0x8009EBDC: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x8009EBE0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8009EBE4: beq         $t6, $zero, L_8009EC38
    if (ctx->r14 == 0) {
        // 0x8009EBE8: nop
    
            goto L_8009EC38;
    }
    // 0x8009EBE8: nop

    // 0x8009EBEC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009EBF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009EBF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009EBF8: sub.s       $f16, $f4, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8009EBFC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009EC00: nop

    // 0x8009EC04: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8009EC08: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009EC0C: nop

    // 0x8009EC10: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x8009EC14: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8009EC18: bne         $t6, $zero, L_8009EC30
    if (ctx->r14 != 0) {
        // 0x8009EC1C: nop
    
            goto L_8009EC30;
    }
    // 0x8009EC1C: nop

    // 0x8009EC20: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x8009EC24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009EC28: b           L_8009EC48
    // 0x8009EC2C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8009EC48;
    // 0x8009EC2C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8009EC30:
    // 0x8009EC30: b           L_8009EC48
    // 0x8009EC34: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8009EC48;
    // 0x8009EC34: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_8009EC38:
    // 0x8009EC38: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x8009EC3C: nop

    // 0x8009EC40: bltz        $t6, L_8009EC30
    if (SIGNED(ctx->r14) < 0) {
        // 0x8009EC44: nop
    
            goto L_8009EC30;
    }
    // 0x8009EC44: nop

L_8009EC48:
    // 0x8009EC48: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8009EC4C: sw          $t6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r14;
    // 0x8009EC50: nop

    // 0x8009EC54: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009EC58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009EC5C: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009EC60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009EC64: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8009EC68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009EC6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8009EC70: nop

    // 0x8009EC74: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8009EC78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009EC7C: nop

    // 0x8009EC80: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8009EC84: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8009EC88: beq         $t8, $zero, L_8009ECDC
    if (ctx->r24 == 0) {
        // 0x8009EC8C: nop
    
            goto L_8009ECDC;
    }
    // 0x8009EC8C: nop

    // 0x8009EC90: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009EC94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009EC98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009EC9C: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8009ECA0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8009ECA4: nop

    // 0x8009ECA8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009ECAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009ECB0: nop

    // 0x8009ECB4: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8009ECB8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8009ECBC: bne         $t8, $zero, L_8009ECD4
    if (ctx->r24 != 0) {
        // 0x8009ECC0: nop
    
            goto L_8009ECD4;
    }
    // 0x8009ECC0: nop

    // 0x8009ECC4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009ECC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009ECCC: b           L_8009ECEC
    // 0x8009ECD0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8009ECEC;
    // 0x8009ECD0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8009ECD4:
    // 0x8009ECD4: b           L_8009ECEC
    // 0x8009ECD8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8009ECEC;
    // 0x8009ECD8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8009ECDC:
    // 0x8009ECDC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009ECE0: nop

    // 0x8009ECE4: bltz        $t8, L_8009ECD4
    if (SIGNED(ctx->r24) < 0) {
        // 0x8009ECE8: nop
    
            goto L_8009ECD4;
    }
    // 0x8009ECE8: nop

L_8009ECEC:
    // 0x8009ECEC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8009ECF0: sw          $t8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r24;
    // 0x8009ECF4: nop

    // 0x8009ECF8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8009ECFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009ED00: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8009ED04: nop

    // 0x8009ED08: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8009ED0C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009ED10: nop

    // 0x8009ED14: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8009ED18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009ED1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009ED20: nop

    // 0x8009ED24: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009ED28: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8009ED2C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009ED30: sh          $t0, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r8;
    // 0x8009ED34: nop

    // 0x8009ED38: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x8009ED3C: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x8009ED40: nop

    // 0x8009ED44: sltu        $at, $t1, $t2
    ctx->r1 = ctx->r9 < ctx->r10 ? 1 : 0;
    // 0x8009ED48: beq         $at, $zero, L_8009FC40
    if (ctx->r1 == 0) {
        // 0x8009ED4C: nop
    
            goto L_8009FC40;
    }
    // 0x8009ED4C: nop

    // 0x8009ED50: sw          $zero, 0x188($sp)
    MEM_W(0X188, ctx->r29) = 0;
L_8009ED54:
    // 0x8009ED54: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x8009ED58: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
L_8009ED5C:
    // 0x8009ED5C: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009ED60: nop

    // 0x8009ED64: bne         $t3, $zero, L_8009ED74
    if (ctx->r11 != 0) {
        // 0x8009ED68: nop
    
            goto L_8009ED74;
    }
    // 0x8009ED68: nop

    // 0x8009ED6C: b           L_8009EDD4
    // 0x8009ED70: nop

        goto L_8009EDD4;
    // 0x8009ED70: nop

L_8009ED74:
    // 0x8009ED74: lw          $t4, 0x190($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X190);
    // 0x8009ED78: lw          $t5, 0x184($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X184);
    // 0x8009ED7C: nop

    // 0x8009ED80: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009ED84: slti        $at, $t6, 0x801
    ctx->r1 = SIGNED(ctx->r14) < 0X801 ? 1 : 0;
    // 0x8009ED88: bne         $at, $zero, L_8009ED98
    if (ctx->r1 != 0) {
        // 0x8009ED8C: nop
    
            goto L_8009ED98;
    }
    // 0x8009ED8C: nop

    // 0x8009ED90: b           L_8009EDD4
    // 0x8009ED94: nop

        goto L_8009EDD4;
    // 0x8009ED94: nop

L_8009ED98:
    // 0x8009ED98: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x8009ED9C: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x8009EDA0: nop

    // 0x8009EDA4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009EDA8: sw          $t9, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r25;
    // 0x8009EDAC: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x8009EDB0: nop

    // 0x8009EDB4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8009EDB8: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x8009EDBC: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x8009EDC0: nop

    // 0x8009EDC4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8009EDC8: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x8009EDCC: b           L_8009ED5C
    // 0x8009EDD0: nop

        goto L_8009ED5C;
    // 0x8009EDD0: nop

L_8009EDD4:
    // 0x8009EDD4: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x8009EDD8: nop

    // 0x8009EDDC: bne         $t4, $zero, L_8009EDEC
    if (ctx->r12 != 0) {
        // 0x8009EDE0: nop
    
            goto L_8009EDEC;
    }
    // 0x8009EDE0: nop

    // 0x8009EDE4: b           L_8009FC04
    // 0x8009EDE8: nop

        goto L_8009FC04;
    // 0x8009EDE8: nop

L_8009EDEC:
    // 0x8009EDEC: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x8009EDF0: nop

    // 0x8009EDF4: bgez        $t5, L_8009EE04
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009EDF8: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8009EE04;
    }
    // 0x8009EDF8: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8009EDFC: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8009EE00: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8009EE04:
    // 0x8009EE04: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8009EE08: sw          $t7, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r15;
    // 0x8009EE0C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8009EE10: sw          $t8, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r24;
L_8009EE14:
    // 0x8009EE14: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
    // 0x8009EE18: nop

    // 0x8009EE1C: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x8009EE20: beq         $t0, $zero, L_8009EE48
    if (ctx->r8 == 0) {
        // 0x8009EE24: nop
    
            goto L_8009EE48;
    }
    // 0x8009EE24: nop

    // 0x8009EE28: lw          $t1, 0x16C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X16C);
    // 0x8009EE2C: nop

    // 0x8009EE30: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x8009EE34: beq         $t2, $zero, L_8009EE40
    if (ctx->r10 == 0) {
        // 0x8009EE38: nop
    
            goto L_8009EE40;
    }
    // 0x8009EE38: nop

    // 0x8009EE3C: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
L_8009EE40:
    // 0x8009EE40: b           L_8009EE6C
    // 0x8009EE44: nop

        goto L_8009EE6C;
    // 0x8009EE44: nop

L_8009EE48:
    // 0x8009EE48: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8009EE4C: nop

    // 0x8009EE50: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8009EE54: sw          $t4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r12;
    // 0x8009EE58: lw          $t5, 0x170($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X170);
    // 0x8009EE5C: nop

    // 0x8009EE60: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8009EE64: bgtz        $t6, L_8009EE14
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009EE68: sw          $t6, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r14;
            goto L_8009EE14;
    }
    // 0x8009EE68: sw          $t6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r14;
L_8009EE6C:
    // 0x8009EE6C: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009EE70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009EE74: lh          $t8, 0x116($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X116);
    // 0x8009EE78: nop

    // 0x8009EE7C: bne         $t8, $at, L_8009F160
    if (ctx->r24 != ctx->r1) {
        // 0x8009EE80: nop
    
            goto L_8009F160;
    }
    // 0x8009EE80: nop

    // 0x8009EE84: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009EE88: nop

    // 0x8009EE8C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8009EE90: sw          $t0, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r8;
    // 0x8009EE94: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
    // 0x8009EE98: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x8009EE9C: lui         $t1, 0xFD50
    ctx->r9 = S32(0XFD50 << 16);
    // 0x8009EEA0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009EEA4: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x8009EEA8: lw          $t4, 0x198($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X198);
    // 0x8009EEAC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009EEB0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009EEB4: lw          $t6, 0x72E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72E0);
    // 0x8009EEB8: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x8009EEBC: mflo        $t5
    ctx->r13 = lo;
    // 0x8009EEC0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8009EEC4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8009EEC8: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009EECC: nop

    // 0x8009EED0: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8009EED4: sw          $t0, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r8;
    // 0x8009EED8: sw          $t9, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r25;
    // 0x8009EEDC: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x8009EEE0: lui         $t1, 0xF550
    ctx->r9 = S32(0XF550 << 16);
    // 0x8009EEE4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009EEE8: lw          $t3, 0x170($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X170);
    // 0x8009EEEC: lw          $t8, 0x174($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X174);
    // 0x8009EEF0: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8009EEF4: sll         $t5, $t4, 14
    ctx->r13 = S32(ctx->r12 << 14);
    // 0x8009EEF8: lui         $at, 0x704
    ctx->r1 = S32(0X704 << 16);
    // 0x8009EEFC: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8009EF00: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8009EF04: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x8009EF08: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8009EF0C: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8009EF10: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x8009EF14: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8009EF18: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009EF1C: nop

    // 0x8009EF20: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8009EF24: sw          $t4, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r12;
    // 0x8009EF28: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x8009EF2C: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8009EF30: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8009EF34: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8009EF38: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8009EF3C: nop

    // 0x8009EF40: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8009EF44: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009EF48: nop

    // 0x8009EF4C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8009EF50: sw          $t7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r15;
    // 0x8009EF54: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8009EF58: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x8009EF5C: lui         $t0, 0xF300
    ctx->r8 = S32(0XF300 << 16);
    // 0x8009EF60: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009EF64: lw          $t2, 0x198($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X198);
    // 0x8009EF68: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x8009EF6C: nop

    // 0x8009EF70: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009EF74: mflo        $t4
    ctx->r12 = lo;
    // 0x8009EF78: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009EF7C: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8009EF80: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8009EF84: slti        $at, $t8, 0x7FF
    ctx->r1 = SIGNED(ctx->r24) < 0X7FF ? 1 : 0;
    // 0x8009EF88: beq         $at, $zero, L_8009EF98
    if (ctx->r1 == 0) {
        // 0x8009EF8C: nop
    
            goto L_8009EF98;
    }
    // 0x8009EF8C: nop

    // 0x8009EF90: b           L_8009EF9C
    // 0x8009EF94: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_8009EF9C;
    // 0x8009EF94: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_8009EF98:
    // 0x8009EF98: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_8009EF9C:
    // 0x8009EF9C: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x8009EFA0: nop

    // 0x8009EFA4: bgez        $t9, L_8009EFB4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8009EFA8: sra         $t7, $t9, 3
        ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
            goto L_8009EFB4;
    }
    // 0x8009EFA8: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8009EFAC: addiu       $at, $t9, 0x7
    ctx->r1 = ADD32(ctx->r25, 0X7);
    // 0x8009EFB0: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_8009EFB4:
    // 0x8009EFB4: bgtz        $t7, L_8009EFC4
    if (SIGNED(ctx->r15) > 0) {
        // 0x8009EFB8: nop
    
            goto L_8009EFC4;
    }
    // 0x8009EFB8: nop

    // 0x8009EFBC: b           L_8009EFE0
    // 0x8009EFC0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8009EFE0;
    // 0x8009EFC0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8009EFC4:
    // 0x8009EFC4: lw          $s1, 0x198($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X198);
    // 0x8009EFC8: nop

    // 0x8009EFCC: bgez        $s1, L_8009EFDC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8009EFD0: sra         $t0, $s1, 3
        ctx->r8 = S32(SIGNED(ctx->r17) >> 3);
            goto L_8009EFDC;
    }
    // 0x8009EFD0: sra         $t0, $s1, 3
    ctx->r8 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8009EFD4: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x8009EFD8: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8009EFDC:
    // 0x8009EFDC: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
L_8009EFE0:
    // 0x8009EFE0: lw          $t1, 0x198($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X198);
    // 0x8009EFE4: nop

    // 0x8009EFE8: bgez        $t1, L_8009EFF8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8009EFEC: sra         $t2, $t1, 3
        ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
            goto L_8009EFF8;
    }
    // 0x8009EFEC: sra         $t2, $t1, 3
    ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8009EFF0: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x8009EFF4: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_8009EFF8:
    // 0x8009EFF8: bgtz        $t2, L_8009F008
    if (SIGNED(ctx->r10) > 0) {
        // 0x8009EFFC: nop
    
            goto L_8009F008;
    }
    // 0x8009EFFC: nop

    // 0x8009F000: b           L_8009F024
    // 0x8009F004: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8009F024;
    // 0x8009F004: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8009F008:
    // 0x8009F008: lw          $s0, 0x198($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X198);
    // 0x8009F00C: nop

    // 0x8009F010: bgez        $s0, L_8009F020
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8009F014: sra         $t3, $s0, 3
        ctx->r11 = S32(SIGNED(ctx->r16) >> 3);
            goto L_8009F020;
    }
    // 0x8009F014: sra         $t3, $s0, 3
    ctx->r11 = S32(SIGNED(ctx->r16) >> 3);
    // 0x8009F018: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x8009F01C: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8009F020:
    // 0x8009F020: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_8009F024:
    // 0x8009F024: addiu       $t4, $s1, 0x7FF
    ctx->r12 = ADD32(ctx->r17, 0X7FF);
    // 0x8009F028: div         $zero, $t4, $s0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r16)));
    // 0x8009F02C: andi        $t8, $s2, 0xFFF
    ctx->r24 = ctx->r18 & 0XFFF;
    // 0x8009F030: bne         $s0, $zero, L_8009F03C
    if (ctx->r16 != 0) {
        // 0x8009F034: nop
    
            goto L_8009F03C;
    }
    // 0x8009F034: nop

    // 0x8009F038: break       7
    do_break(2148134968);
L_8009F03C:
    // 0x8009F03C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009F040: bne         $s0, $at, L_8009F054
    if (ctx->r16 != ctx->r1) {
        // 0x8009F044: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009F054;
    }
    // 0x8009F044: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009F048: bne         $t4, $at, L_8009F054
    if (ctx->r12 != ctx->r1) {
        // 0x8009F04C: nop
    
            goto L_8009F054;
    }
    // 0x8009F04C: nop

    // 0x8009F050: break       6
    do_break(2148134992);
L_8009F054:
    // 0x8009F054: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009F058: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8009F05C: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x8009F060: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8009F064: mflo        $t5
    ctx->r13 = lo;
    // 0x8009F068: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8009F06C: or          $t0, $t6, $t7
    ctx->r8 = ctx->r14 | ctx->r15;
    // 0x8009F070: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8009F074: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F078: nop

    // 0x8009F07C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8009F080: sw          $t3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r11;
    // 0x8009F084: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x8009F088: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8009F08C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8009F090: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009F094: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8009F098: nop

    // 0x8009F09C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8009F0A0: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F0A4: nop

    // 0x8009F0A8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8009F0AC: sw          $t6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r14;
    // 0x8009F0B0: sw          $t9, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r25;
    // 0x8009F0B4: lw          $t7, 0x198($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X198);
    // 0x8009F0B8: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x8009F0BC: addiu       $t0, $t7, 0x7
    ctx->r8 = ADD32(ctx->r15, 0X7);
    // 0x8009F0C0: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8009F0C4: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x8009F0C8: sll         $t3, $t2, 9
    ctx->r11 = S32(ctx->r10 << 9);
    // 0x8009F0CC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8009F0D0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8009F0D4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009F0D8: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
    // 0x8009F0DC: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x8009F0E0: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8009F0E4: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x8009F0E8: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8009F0EC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8009F0F0: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8009F0F4: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x8009F0F8: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8009F0FC: ori         $t0, $t7, 0x100
    ctx->r8 = ctx->r15 | 0X100;
    // 0x8009F100: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8009F104: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8009F108: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F10C: nop

    // 0x8009F110: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009F114: sw          $t9, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r25;
    // 0x8009F118: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x8009F11C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8009F120: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009F124: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009F128: lw          $t1, 0x198($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X198);
    // 0x8009F12C: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x8009F130: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8009F134: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8009F138: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8009F13C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8009F140: andi        $t3, $t0, 0xFFF
    ctx->r11 = ctx->r8 & 0XFFF;
    // 0x8009F144: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8009F148: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8009F14C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009F150: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8009F154: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8009F158: b           L_8009F6C8
    // 0x8009F15C: nop

        goto L_8009F6C8;
    // 0x8009F15C: nop

L_8009F160:
    // 0x8009F160: lw          $t2, 0x1AC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1AC);
    // 0x8009F164: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009F168: lh          $t0, 0x116($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X116);
    // 0x8009F16C: nop

    // 0x8009F170: bne         $t0, $at, L_8009F46C
    if (ctx->r8 != ctx->r1) {
        // 0x8009F174: nop
    
            goto L_8009F46C;
    }
    // 0x8009F174: nop

    // 0x8009F178: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F17C: nop

    // 0x8009F180: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8009F184: sw          $t5, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r13;
    // 0x8009F188: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x8009F18C: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8009F190: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8009F194: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009F198: lw          $t4, 0x198($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X198);
    // 0x8009F19C: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x8009F1A0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8009F1A4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009F1A8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009F1AC: lw          $t2, 0x72E0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72E0);
    // 0x8009F1B0: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8009F1B4: mflo        $t1
    ctx->r9 = lo;
    // 0x8009F1B8: addu        $t0, $t1, $t2
    ctx->r8 = ADD32(ctx->r9, ctx->r10);
    // 0x8009F1BC: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x8009F1C0: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F1C4: nop

    // 0x8009F1C8: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x8009F1CC: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x8009F1D0: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x8009F1D4: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x8009F1D8: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x8009F1DC: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8009F1E0: lw          $t6, 0x170($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X170);
    // 0x8009F1E4: lw          $t3, 0x174($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X174);
    // 0x8009F1E8: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8009F1EC: sll         $t1, $t7, 14
    ctx->r9 = S32(ctx->r15 << 14);
    // 0x8009F1F0: lui         $at, 0x704
    ctx->r1 = S32(0X704 << 16);
    // 0x8009F1F4: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8009F1F8: andi        $t5, $t3, 0xF
    ctx->r13 = ctx->r11 & 0XF;
    // 0x8009F1FC: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x8009F200: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x8009F204: ori         $t0, $t2, 0x100
    ctx->r8 = ctx->r10 | 0X100;
    // 0x8009F208: or          $t9, $t0, $t8
    ctx->r25 = ctx->r8 | ctx->r24;
    // 0x8009F20C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8009F210: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F214: nop

    // 0x8009F218: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8009F21C: sw          $t7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r15;
    // 0x8009F220: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x8009F224: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x8009F228: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x8009F22C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009F230: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x8009F234: nop

    // 0x8009F238: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8009F23C: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F240: nop

    // 0x8009F244: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x8009F248: sw          $t0, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r8;
    // 0x8009F24C: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8009F250: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8009F254: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009F258: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009F25C: lw          $t4, 0x198($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X198);
    // 0x8009F260: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x8009F264: nop

    // 0x8009F268: multu       $t4, $t6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009F26C: mflo        $t7
    ctx->r15 = lo;
    // 0x8009F270: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x8009F274: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8009F278: beq         $at, $zero, L_8009F288
    if (ctx->r1 == 0) {
        // 0x8009F27C: nop
    
            goto L_8009F288;
    }
    // 0x8009F27C: nop

    // 0x8009F280: b           L_8009F28C
    // 0x8009F284: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
        goto L_8009F28C;
    // 0x8009F284: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
L_8009F288:
    // 0x8009F288: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_8009F28C:
    // 0x8009F28C: lw          $t2, 0x198($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X198);
    // 0x8009F290: nop

    // 0x8009F294: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8009F298: bgez        $t3, L_8009F2A8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8009F29C: sra         $t5, $t3, 3
        ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
            goto L_8009F2A8;
    }
    // 0x8009F29C: sra         $t5, $t3, 3
    ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8009F2A0: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x8009F2A4: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_8009F2A8:
    // 0x8009F2A8: bgtz        $t5, L_8009F2B8
    if (SIGNED(ctx->r13) > 0) {
        // 0x8009F2AC: nop
    
            goto L_8009F2B8;
    }
    // 0x8009F2AC: nop

    // 0x8009F2B0: b           L_8009F2DC
    // 0x8009F2B4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8009F2DC;
    // 0x8009F2B4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8009F2B8:
    // 0x8009F2B8: lw          $s1, 0x198($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X198);
    // 0x8009F2BC: nop

    // 0x8009F2C0: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    // 0x8009F2C4: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8009F2C8: bgez        $s1, L_8009F2D8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8009F2CC: sra         $t8, $s1, 3
        ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
            goto L_8009F2D8;
    }
    // 0x8009F2CC: sra         $t8, $s1, 3
    ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8009F2D0: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x8009F2D4: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8009F2D8:
    // 0x8009F2D8: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_8009F2DC:
    // 0x8009F2DC: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x8009F2E0: nop

    // 0x8009F2E4: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x8009F2E8: bgez        $t4, L_8009F2F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8009F2EC: sra         $t6, $t4, 3
        ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8009F2F8;
    }
    // 0x8009F2EC: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8009F2F0: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8009F2F4: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8009F2F8:
    // 0x8009F2F8: bgtz        $t6, L_8009F308
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009F2FC: nop
    
            goto L_8009F308;
    }
    // 0x8009F2FC: nop

    // 0x8009F300: b           L_8009F32C
    // 0x8009F304: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8009F32C;
    // 0x8009F304: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8009F308:
    // 0x8009F308: lw          $s0, 0x198($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X198);
    // 0x8009F30C: nop

    // 0x8009F310: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x8009F314: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8009F318: bgez        $s0, L_8009F328
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8009F31C: sra         $t1, $s0, 3
        ctx->r9 = S32(SIGNED(ctx->r16) >> 3);
            goto L_8009F328;
    }
    // 0x8009F31C: sra         $t1, $s0, 3
    ctx->r9 = S32(SIGNED(ctx->r16) >> 3);
    // 0x8009F320: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x8009F324: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8009F328:
    // 0x8009F328: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8009F32C:
    // 0x8009F32C: addiu       $t2, $s1, 0x7FF
    ctx->r10 = ADD32(ctx->r17, 0X7FF);
    // 0x8009F330: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x8009F334: andi        $t0, $s2, 0xFFF
    ctx->r8 = ctx->r18 & 0XFFF;
    // 0x8009F338: bne         $s0, $zero, L_8009F344
    if (ctx->r16 != 0) {
        // 0x8009F33C: nop
    
            goto L_8009F344;
    }
    // 0x8009F33C: nop

    // 0x8009F340: break       7
    do_break(2148135744);
L_8009F344:
    // 0x8009F344: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009F348: bne         $s0, $at, L_8009F35C
    if (ctx->r16 != ctx->r1) {
        // 0x8009F34C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009F35C;
    }
    // 0x8009F34C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009F350: bne         $t2, $at, L_8009F35C
    if (ctx->r10 != ctx->r1) {
        // 0x8009F354: nop
    
            goto L_8009F35C;
    }
    // 0x8009F354: nop

    // 0x8009F358: break       6
    do_break(2148135768);
L_8009F35C:
    // 0x8009F35C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009F360: sll         $t8, $t0, 12
    ctx->r24 = S32(ctx->r8 << 12);
    // 0x8009F364: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8009F368: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009F36C: mflo        $t3
    ctx->r11 = lo;
    // 0x8009F370: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x8009F374: or          $t4, $t5, $t9
    ctx->r12 = ctx->r13 | ctx->r25;
    // 0x8009F378: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x8009F37C: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F380: nop

    // 0x8009F384: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x8009F388: sw          $t1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r9;
    // 0x8009F38C: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8009F390: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8009F394: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8009F398: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8009F39C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8009F3A0: nop

    // 0x8009F3A4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009F3A8: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F3AC: nop

    // 0x8009F3B0: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8009F3B4: sw          $t5, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r13;
    // 0x8009F3B8: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x8009F3BC: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x8009F3C0: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8009F3C4: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x8009F3C8: addiu       $t6, $t4, 0x7
    ctx->r14 = ADD32(ctx->r12, 0X7);
    // 0x8009F3CC: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8009F3D0: andi        $t1, $t7, 0x1FF
    ctx->r9 = ctx->r15 & 0X1FF;
    // 0x8009F3D4: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x8009F3D8: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8009F3DC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8009F3E0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8009F3E4: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
    // 0x8009F3E8: lw          $t7, 0x174($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X174);
    // 0x8009F3EC: andi        $t5, $t8, 0xF
    ctx->r13 = ctx->r24 & 0XF;
    // 0x8009F3F0: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8009F3F4: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8009F3F8: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x8009F3FC: andi        $t1, $t7, 0xF
    ctx->r9 = ctx->r15 & 0XF;
    // 0x8009F400: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8009F404: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8009F408: ori         $t6, $t4, 0x100
    ctx->r14 = ctx->r12 | 0X100;
    // 0x8009F40C: or          $t3, $t6, $t2
    ctx->r11 = ctx->r14 | ctx->r10;
    // 0x8009F410: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8009F414: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F418: nop

    // 0x8009F41C: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8009F420: sw          $t5, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r13;
    // 0x8009F424: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x8009F428: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8009F42C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8009F430: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8009F434: lw          $t7, 0x198($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X198);
    // 0x8009F438: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x8009F43C: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x8009F440: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8009F444: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x8009F448: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8009F44C: andi        $t2, $t6, 0xFFF
    ctx->r10 = ctx->r14 & 0XFFF;
    // 0x8009F450: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8009F454: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x8009F458: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x8009F45C: or          $t4, $t3, $t9
    ctx->r12 = ctx->r11 | ctx->r25;
    // 0x8009F460: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x8009F464: b           L_8009F6C8
    // 0x8009F468: nop

        goto L_8009F6C8;
    // 0x8009F468: nop

L_8009F46C:
    // 0x8009F46C: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F470: nop

    // 0x8009F474: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8009F478: sw          $t6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r14;
    // 0x8009F47C: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x8009F480: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8009F484: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x8009F488: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8009F48C: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x8009F490: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x8009F494: bgez        $t8, L_8009F4A4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8009F498: sra         $t5, $t8, 1
        ctx->r13 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8009F4A4;
    }
    // 0x8009F498: sra         $t5, $t8, 1
    ctx->r13 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8009F49C: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8009F4A0: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8009F4A4:
    // 0x8009F4A4: multu       $t5, $t3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009F4A8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009F4AC: lw          $t4, 0x72E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72E0);
    // 0x8009F4B0: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8009F4B4: mflo        $t9
    ctx->r25 = lo;
    // 0x8009F4B8: addu        $t7, $t9, $t4
    ctx->r15 = ADD32(ctx->r25, ctx->r12);
    // 0x8009F4BC: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8009F4C0: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F4C4: nop

    // 0x8009F4C8: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x8009F4CC: sw          $t2, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r10;
    // 0x8009F4D0: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8009F4D4: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8009F4D8: lui         $t0, 0xF550
    ctx->r8 = S32(0XF550 << 16);
    // 0x8009F4DC: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8009F4E0: lw          $t5, 0x170($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X170);
    // 0x8009F4E4: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x8009F4E8: andi        $t3, $t5, 0xF
    ctx->r11 = ctx->r13 & 0XF;
    // 0x8009F4EC: sll         $t9, $t3, 14
    ctx->r25 = S32(ctx->r11 << 14);
    // 0x8009F4F0: lui         $at, 0x704
    ctx->r1 = S32(0X704 << 16);
    // 0x8009F4F4: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x8009F4F8: andi        $t6, $t1, 0xF
    ctx->r14 = ctx->r9 & 0XF;
    // 0x8009F4FC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8009F500: sll         $t2, $t6, 4
    ctx->r10 = S32(ctx->r14 << 4);
    // 0x8009F504: ori         $t7, $t4, 0x100
    ctx->r15 = ctx->r12 | 0X100;
    // 0x8009F508: or          $t0, $t7, $t2
    ctx->r8 = ctx->r15 | ctx->r10;
    // 0x8009F50C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x8009F510: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F514: nop

    // 0x8009F518: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x8009F51C: sw          $t3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r11;
    // 0x8009F520: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x8009F524: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8009F528: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8009F52C: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8009F530: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8009F534: nop

    // 0x8009F538: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8009F53C: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F540: nop

    // 0x8009F544: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8009F548: sw          $t7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r15;
    // 0x8009F54C: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x8009F550: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8009F554: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x8009F558: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8009F55C: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x8009F560: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x8009F564: nop

    // 0x8009F568: multu       $t8, $t5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009F56C: mflo        $t3
    ctx->r11 = lo;
    // 0x8009F570: addiu       $t9, $t3, 0x3
    ctx->r25 = ADD32(ctx->r11, 0X3);
    // 0x8009F574: sra         $t4, $t9, 2
    ctx->r12 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8009F578: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x8009F57C: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8009F580: beq         $at, $zero, L_8009F590
    if (ctx->r1 == 0) {
        // 0x8009F584: nop
    
            goto L_8009F590;
    }
    // 0x8009F584: nop

    // 0x8009F588: b           L_8009F594
    // 0x8009F58C: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
        goto L_8009F594;
    // 0x8009F58C: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
L_8009F590:
    // 0x8009F590: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_8009F594:
    // 0x8009F594: b           L_8009F5A0
    // 0x8009F598: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8009F5A0;
    // 0x8009F598: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8009F59C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8009F5A0:
    // 0x8009F5A0: b           L_8009F5AC
    // 0x8009F5A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8009F5AC;
    // 0x8009F5A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8009F5A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009F5AC:
    // 0x8009F5AC: addiu       $t6, $s1, 0x7FF
    ctx->r14 = ADD32(ctx->r17, 0X7FF);
    // 0x8009F5B0: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x8009F5B4: andi        $t0, $s2, 0xFFF
    ctx->r8 = ctx->r18 & 0XFFF;
    // 0x8009F5B8: bne         $s0, $zero, L_8009F5C4
    if (ctx->r16 != 0) {
        // 0x8009F5BC: nop
    
            goto L_8009F5C4;
    }
    // 0x8009F5BC: nop

    // 0x8009F5C0: break       7
    do_break(2148136384);
L_8009F5C4:
    // 0x8009F5C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009F5C8: bne         $s0, $at, L_8009F5DC
    if (ctx->r16 != ctx->r1) {
        // 0x8009F5CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009F5DC;
    }
    // 0x8009F5CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009F5D0: bne         $t6, $at, L_8009F5DC
    if (ctx->r14 != ctx->r1) {
        // 0x8009F5D4: nop
    
            goto L_8009F5DC;
    }
    // 0x8009F5D4: nop

    // 0x8009F5D8: break       6
    do_break(2148136408);
L_8009F5DC:
    // 0x8009F5DC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009F5E0: sll         $t8, $t0, 12
    ctx->r24 = S32(ctx->r8 << 12);
    // 0x8009F5E4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009F5E8: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x8009F5EC: mflo        $t7
    ctx->r15 = lo;
    // 0x8009F5F0: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x8009F5F4: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x8009F5F8: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8009F5FC: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F600: nop

    // 0x8009F604: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x8009F608: sw          $t1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r9;
    // 0x8009F60C: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x8009F610: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009F614: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009F618: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009F61C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8009F620: nop

    // 0x8009F624: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009F628: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F62C: nop

    // 0x8009F630: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8009F634: sw          $t2, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r10;
    // 0x8009F638: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x8009F63C: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8009F640: lui         $t5, 0xF540
    ctx->r13 = S32(0XF540 << 16);
    // 0x8009F644: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8009F648: lw          $t9, 0x170($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X170);
    // 0x8009F64C: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8009F650: andi        $t4, $t9, 0xF
    ctx->r12 = ctx->r25 & 0XF;
    // 0x8009F654: sll         $t1, $t4, 14
    ctx->r9 = S32(ctx->r12 << 14);
    // 0x8009F658: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8009F65C: or          $t6, $t1, $at
    ctx->r14 = ctx->r9 | ctx->r1;
    // 0x8009F660: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x8009F664: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8009F668: sll         $t2, $t8, 4
    ctx->r10 = S32(ctx->r24 << 4);
    // 0x8009F66C: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8009F670: or          $t5, $t7, $t2
    ctx->r13 = ctx->r15 | ctx->r10;
    // 0x8009F674: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8009F678: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F67C: nop

    // 0x8009F680: addiu       $t4, $t9, 0x8
    ctx->r12 = ADD32(ctx->r25, 0X8);
    // 0x8009F684: sw          $t4, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r12;
    // 0x8009F688: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8009F68C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8009F690: lui         $t1, 0xF200
    ctx->r9 = S32(0XF200 << 16);
    // 0x8009F694: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x8009F698: lw          $t0, 0x198($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X198);
    // 0x8009F69C: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x8009F6A0: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x8009F6A4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8009F6A8: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x8009F6AC: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8009F6B0: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x8009F6B4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8009F6B8: sll         $t5, $t2, 12
    ctx->r13 = S32(ctx->r10 << 12);
    // 0x8009F6BC: andi        $t1, $t4, 0xFFF
    ctx->r9 = ctx->r12 & 0XFFF;
    // 0x8009F6C0: or          $t6, $t5, $t1
    ctx->r14 = ctx->r13 | ctx->r9;
    // 0x8009F6C4: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
L_8009F6C8:
    // 0x8009F6C8: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009F6CC: nop

    // 0x8009F6D0: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8009F6D4: sw          $t7, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r15;
    // 0x8009F6D8: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8009F6DC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8009F6E0: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8009F6E4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8009F6E8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8009F6EC: nop

    // 0x8009F6F0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009F6F4: lw          $t4, 0x180($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X180);
    // 0x8009F6F8: nop

    // 0x8009F6FC: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x8009F700: bne         $t5, $zero, L_8009F748
    if (ctx->r13 != 0) {
        // 0x8009F704: nop
    
            goto L_8009F748;
    }
    // 0x8009F704: nop

    // 0x8009F708: lw          $t1, 0x188($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X188);
    // 0x8009F70C: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x8009F710: lwc1        $f4, 0x134($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8009F714: subu        $t0, $t1, $t6
    ctx->r8 = SUB32(ctx->r9, ctx->r14);
    // 0x8009F718: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009F71C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8009F720: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009F724: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009F728: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8009F72C: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8009F730: lwc1        $f6, 0x1B4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1B4);
    // 0x8009F734: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8009F738: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8009F73C: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8009F740: b           L_8009F7B8
    // 0x8009F744: swc1        $f16, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f16.u32l;
        goto L_8009F7B8;
    // 0x8009F744: swc1        $f16, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f16.u32l;
L_8009F748:
    // 0x8009F748: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009F74C: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8009F750: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8009F754: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009F758: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009F75C: nop

    // 0x8009F760: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009F764: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009F768: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8009F76C: sw          $t7, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r15;
    // 0x8009F770: nop

    // 0x8009F774: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x8009F778: lw          $t3, 0x178($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X178);
    // 0x8009F77C: lwc1        $f4, 0x134($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8009F780: subu        $t9, $t2, $t3
    ctx->r25 = SUB32(ctx->r10, ctx->r11);
    // 0x8009F784: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009F788: lw          $t4, 0x16C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X16C);
    // 0x8009F78C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009F790: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8009F794: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8009F798: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8009F79C: lwc1        $f4, 0x1B4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1B4);
    // 0x8009F7A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009F7A4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F7A8: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009F7AC: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8009F7B0: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8009F7B4: swc1        $f16, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f16.u32l;
L_8009F7B8:
    // 0x8009F7B8: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x8009F7BC: lwc1        $f4, 0x134($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8009F7C0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8009F7C4: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8009F7C8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009F7CC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8009F7D0: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8009F7D4: swc1        $f16, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f16.u32l;
    // 0x8009F7D8: lw          $t1, 0x180($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X180);
    // 0x8009F7DC: nop

    // 0x8009F7E0: andi        $t6, $t1, 0x2
    ctx->r14 = ctx->r9 & 0X2;
    // 0x8009F7E4: bne         $t6, $zero, L_8009F7F8
    if (ctx->r14 != 0) {
        // 0x8009F7E8: nop
    
            goto L_8009F7F8;
    }
    // 0x8009F7E8: nop

    // 0x8009F7EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009F7F0: b           L_8009F810
    // 0x8009F7F4: swc1        $f18, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f18.u32l;
        goto L_8009F810;
    // 0x8009F7F4: swc1        $f18, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f18.u32l;
L_8009F7F8:
    // 0x8009F7F8: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x8009F7FC: nop

    // 0x8009F800: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8009F804: nop

    // 0x8009F808: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009F80C: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
L_8009F810:
    // 0x8009F810: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8009F814: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009F818: nop

    // 0x8009F81C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8009F820: nop

    // 0x8009F824: bc1f        L_8009F850
    if (!c1cs) {
        // 0x8009F828: nop
    
            goto L_8009F850;
    }
    // 0x8009F828: nop

    // 0x8009F82C: lwc1        $f16, 0x154($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8009F830: lwc1        $f18, 0x134($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8009F834: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x8009F838: div.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009F83C: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8009F840: swc1        $f6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f6.u32l;
    // 0x8009F844: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009F848: b           L_8009F8A0
    // 0x8009F84C: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
        goto L_8009F8A0;
    // 0x8009F84C: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
L_8009F850:
    // 0x8009F850: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009F854: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009F858: lwc1        $f16, 0x154($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8009F85C: nop

    // 0x8009F860: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8009F864: nop

    // 0x8009F868: bc1f        L_8009F8A0
    if (!c1cs) {
        // 0x8009F86C: nop
    
            goto L_8009F8A0;
    }
    // 0x8009F86C: nop

    // 0x8009F870: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009F874: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009F878: lwc1        $f10, 0x154($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8009F87C: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8009F880: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8009F884: nop

    // 0x8009F888: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009F88C: swc1        $f16, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f16.u32l;
    // 0x8009F890: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009F894: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009F898: nop

    // 0x8009F89C: swc1        $f18, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f18.u32l;
L_8009F8A0:
    // 0x8009F8A0: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009F8A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009F8A8: nop

    // 0x8009F8AC: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8009F8B0: nop

    // 0x8009F8B4: bc1f        L_8009F8C8
    if (!c1cs) {
        // 0x8009F8B8: nop
    
            goto L_8009F8C8;
    }
    // 0x8009F8B8: nop

    // 0x8009F8BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009F8C0: b           L_8009F8F8
    // 0x8009F8C4: swc1        $f6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f6.u32l;
        goto L_8009F8F8;
    // 0x8009F8C4: swc1        $f6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f6.u32l;
L_8009F8C8:
    // 0x8009F8C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009F8CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009F8D0: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009F8D4: nop

    // 0x8009F8D8: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8009F8DC: nop

    // 0x8009F8E0: bc1f        L_8009F8F8
    if (!c1cs) {
        // 0x8009F8E4: nop
    
            goto L_8009F8F8;
    }
    // 0x8009F8E4: nop

    // 0x8009F8E8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009F8EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009F8F0: nop

    // 0x8009F8F4: swc1        $f18, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f18.u32l;
L_8009F8F8:
    // 0x8009F8F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009F8FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009F900: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8009F904: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009F908: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8009F90C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009F910: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8009F914: nop

    // 0x8009F918: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009F91C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009F920: nop

    // 0x8009F924: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8009F928: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8009F92C: beq         $t7, $zero, L_8009F980
    if (ctx->r15 == 0) {
        // 0x8009F930: nop
    
            goto L_8009F980;
    }
    // 0x8009F930: nop

    // 0x8009F934: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009F938: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009F93C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009F940: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009F944: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8009F948: nop

    // 0x8009F94C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009F950: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009F954: nop

    // 0x8009F958: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8009F95C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8009F960: bne         $t7, $zero, L_8009F978
    if (ctx->r15 != 0) {
        // 0x8009F964: nop
    
            goto L_8009F978;
    }
    // 0x8009F964: nop

    // 0x8009F968: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009F96C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009F970: b           L_8009F990
    // 0x8009F974: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8009F990;
    // 0x8009F974: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8009F978:
    // 0x8009F978: b           L_8009F990
    // 0x8009F97C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8009F990;
    // 0x8009F97C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8009F980:
    // 0x8009F980: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009F984: nop

    // 0x8009F988: bltz        $t7, L_8009F978
    if (SIGNED(ctx->r15) < 0) {
        // 0x8009F98C: nop
    
            goto L_8009F978;
    }
    // 0x8009F98C: nop

L_8009F990:
    // 0x8009F990: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8009F994: sw          $t7, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r15;
    // 0x8009F998: nop

    // 0x8009F99C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009F9A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009F9A4: lwc1        $f16, 0x14C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009F9A8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009F9AC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009F9B0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8009F9B4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009F9B8: nop

    // 0x8009F9BC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009F9C0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8009F9C4: nop

    // 0x8009F9C8: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x8009F9CC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8009F9D0: beq         $t3, $zero, L_8009FA24
    if (ctx->r11 == 0) {
        // 0x8009F9D4: nop
    
            goto L_8009FA24;
    }
    // 0x8009F9D4: nop

    // 0x8009F9D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009F9DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009F9E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009F9E4: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8009F9E8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009F9EC: nop

    // 0x8009F9F0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009F9F4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8009F9F8: nop

    // 0x8009F9FC: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x8009FA00: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8009FA04: bne         $t3, $zero, L_8009FA1C
    if (ctx->r11 != 0) {
        // 0x8009FA08: nop
    
            goto L_8009FA1C;
    }
    // 0x8009FA08: nop

    // 0x8009FA0C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8009FA10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FA14: b           L_8009FA34
    // 0x8009FA18: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8009FA34;
    // 0x8009FA18: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8009FA1C:
    // 0x8009FA1C: b           L_8009FA34
    // 0x8009FA20: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8009FA34;
    // 0x8009FA20: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8009FA24:
    // 0x8009FA24: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8009FA28: nop

    // 0x8009FA2C: bltz        $t3, L_8009FA1C
    if (SIGNED(ctx->r11) < 0) {
        // 0x8009FA30: nop
    
            goto L_8009FA1C;
    }
    // 0x8009FA30: nop

L_8009FA34:
    // 0x8009FA34: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8009FA38: sw          $t3, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r11;
    // 0x8009FA3C: nop

    // 0x8009FA40: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8009FA44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009FA48: lwc1        $f6, 0x140($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X140);
    // 0x8009FA4C: nop

    // 0x8009FA50: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009FA54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009FA58: nop

    // 0x8009FA5C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8009FA60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009FA64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009FA68: nop

    // 0x8009FA6C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8009FA70: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8009FA74: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009FA78: sh          $t4, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r12;
    // 0x8009FA7C: nop

    // 0x8009FA80: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x8009FA84: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x8009FA88: nop

    // 0x8009FA8C: sltu        $at, $t5, $t1
    ctx->r1 = ctx->r13 < ctx->r9 ? 1 : 0;
    // 0x8009FA90: bne         $at, $zero, L_8009FAE0
    if (ctx->r1 != 0) {
        // 0x8009FA94: nop
    
            goto L_8009FAE0;
    }
    // 0x8009FA94: nop

    // 0x8009FA98: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x8009FA9C: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x8009FAA0: nop

    // 0x8009FAA4: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8009FAA8: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
    // 0x8009FAAC: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009FAB0: nop

    // 0x8009FAB4: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x8009FAB8: sw          $t2, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r10;
    // 0x8009FABC: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8009FAC0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8009FAC4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8009FAC8: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8009FACC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8009FAD0: nop

    // 0x8009FAD4: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8009FAD8: b           L_8009FBFC
    // 0x8009FADC: nop

        goto L_8009FBFC;
    // 0x8009FADC: nop

L_8009FAE0:
    // 0x8009FAE0: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009FAE4: nop

    // 0x8009FAE8: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x8009FAEC: sw          $t1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r9;
    // 0x8009FAF0: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8009FAF4: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x8009FAF8: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x8009FAFC: andi        $t0, $t6, 0xFFF
    ctx->r8 = ctx->r14 & 0XFFF;
    // 0x8009FB00: sll         $t8, $t0, 12
    ctx->r24 = S32(ctx->r8 << 12);
    // 0x8009FB04: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009FB08: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8009FB0C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8009FB10: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8009FB14: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x8009FB18: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8009FB1C: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x8009FB20: lw          $t0, 0x164($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X164);
    // 0x8009FB24: andi        $t1, $t5, 0xFFF
    ctx->r9 = ctx->r13 & 0XFFF;
    // 0x8009FB28: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009FB2C: sll         $t6, $t1, 12
    ctx->r14 = S32(ctx->r9 << 12);
    // 0x8009FB30: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x8009FB34: or          $t2, $t6, $t8
    ctx->r10 = ctx->r14 | ctx->r24;
    // 0x8009FB38: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x8009FB3C: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009FB40: nop

    // 0x8009FB44: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x8009FB48: sw          $t9, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r25;
    // 0x8009FB4C: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8009FB50: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8009FB54: lui         $t4, 0xB400
    ctx->r12 = S32(0XB400 << 16);
    // 0x8009FB58: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009FB5C: lh          $t1, 0x14A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X14A);
    // 0x8009FB60: lh          $t8, 0x148($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X148);
    // 0x8009FB64: andi        $t0, $t1, 0xFFFF
    ctx->r8 = ctx->r9 & 0XFFFF;
    // 0x8009FB68: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8009FB6C: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8009FB70: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x8009FB74: or          $t7, $t6, $t2
    ctx->r15 = ctx->r14 | ctx->r10;
    // 0x8009FB78: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8009FB7C: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009FB80: nop

    // 0x8009FB84: addiu       $t4, $t9, 0x8
    ctx->r12 = ADD32(ctx->r25, 0X8);
    // 0x8009FB88: sw          $t4, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r12;
    // 0x8009FB8C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8009FB90: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009FB94: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x8009FB98: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8009FB9C: lh          $t0, 0x13E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X13E);
    // 0x8009FBA0: lh          $t2, 0x13C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X13C);
    // 0x8009FBA4: andi        $t8, $t0, 0xFFFF
    ctx->r24 = ctx->r8 & 0XFFFF;
    // 0x8009FBA8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8009FBAC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8009FBB0: andi        $t7, $t2, 0xFFFF
    ctx->r15 = ctx->r10 & 0XFFFF;
    // 0x8009FBB4: or          $t3, $t6, $t7
    ctx->r11 = ctx->r14 | ctx->r15;
    // 0x8009FBB8: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8009FBBC: lw          $t4, 0x188($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X188);
    // 0x8009FBC0: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x8009FBC4: nop

    // 0x8009FBC8: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x8009FBCC: sw          $t1, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r9;
    // 0x8009FBD0: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009FBD4: nop

    // 0x8009FBD8: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x8009FBDC: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x8009FBE0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8009FBE4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8009FBE8: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8009FBEC: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8009FBF0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8009FBF4: nop

    // 0x8009FBF8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
L_8009FBFC:
    // 0x8009FBFC: b           L_8009ED54
    // 0x8009FC00: nop

        goto L_8009ED54;
    // 0x8009FC00: nop

L_8009FC04:
    // 0x8009FC04: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009FC08: nop

    // 0x8009FC0C: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x8009FC10: sw          $t9, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r25;
    // 0x8009FC14: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8009FC18: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8009FC1C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8009FC20: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009FC24: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8009FC28: nop

    // 0x8009FC2C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8009FC30: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x8009FC34: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x8009FC38: nop

    // 0x8009FC3C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_8009FC40:
    // 0x8009FC40: b           L_8009FC50
    // 0x8009FC44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009FC50;
    // 0x8009FC44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009FC48: b           L_8009FC50
    // 0x8009FC4C: nop

        goto L_8009FC50;
    // 0x8009FC4C: nop

L_8009FC50:
    // 0x8009FC50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009FC54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009FC58: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009FC5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009FC60: jr          $ra
    // 0x8009FC64: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x8009FC64: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void func_80012068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012068: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001206C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012070: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80012074: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80012078: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001207C: jal         0x8000DA44
    // 0x80012080: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012080: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80012084: bgez        $v0, L_80012094
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012088: nop
    
            goto L_80012094;
    }
    // 0x80012088: nop

    // 0x8001208C: b           L_80012154
    // 0x80012090: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012154;
    // 0x80012090: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012094:
    // 0x80012094: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80012098: nop

    // 0x8001209C: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800120A0: nop

    // 0x800120A4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800120A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800120AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800120B0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800120B4: nop

    // 0x800120B8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800120BC: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x800120C0: nop

    // 0x800120C4: blez        $t0, L_80012144
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800120C8: nop
    
            goto L_80012144;
    }
    // 0x800120C8: nop

L_800120CC:
    // 0x800120CC: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x800120D0: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x800120D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800120D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800120DC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800120E0: lwc1        $f4, -0x617C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X617C);
    // 0x800120E4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800120E8: nop

    // 0x800120EC: swc1        $f4, 0xF4($t4)
    MEM_W(0XF4, ctx->r12) = ctx->f4.u32l;
    // 0x800120F0: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x800120F4: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x800120F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800120FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80012100: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80012104: lwc1        $f6, -0x617C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X617C);
    // 0x80012108: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001210C: nop

    // 0x80012110: swc1        $f6, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f6.u32l;
    // 0x80012114: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80012118: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001211C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80012120: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80012124: addiu       $t2, $t1, 0x160
    ctx->r10 = ADD32(ctx->r9, 0X160);
    // 0x80012128: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8001212C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80012130: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x80012134: nop

    // 0x80012138: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001213C: bne         $at, $zero, L_800120CC
    if (ctx->r1 != 0) {
        // 0x80012140: nop
    
            goto L_800120CC;
    }
    // 0x80012140: nop

L_80012144:
    // 0x80012144: b           L_80012154
    // 0x80012148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012154;
    // 0x80012148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001214C: b           L_80012154
    // 0x80012150: nop

        goto L_80012154;
    // 0x80012150: nop

L_80012154:
    // 0x80012154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001215C: jr          $ra
    // 0x80012160: nop

    return;
    // 0x80012160: nop

;}
RECOMP_FUNC void func_80064BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064BD0: jal         0x8005F064
    // 0x80064BD4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064BD4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x80064BD8: b           L_80064BE8
    // 0x80064BDC: nop

        goto L_80064BE8;
    // 0x80064BDC: nop

    // 0x80064BE0: b           L_80064BE8
    // 0x80064BE4: nop

        goto L_80064BE8;
    // 0x80064BE4: nop

L_80064BE8:
    // 0x80064BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064BF0: jr          $ra
    // 0x80064BF4: nop

    return;
    // 0x80064BF4: nop

;}
RECOMP_FUNC void func_800BB16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB16C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BB170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB174: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BB178: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BB17C:
    // 0x800BB17C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB180: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BB184: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BB188: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BB18C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BB190: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800BB194: lw          $t8, -0x1A64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1A64);
    // 0x800BB198: nop

    // 0x800BB19C: beq         $t8, $zero, L_800BB21C
    if (ctx->r24 == 0) {
        // 0x800BB1A0: nop
    
            goto L_800BB21C;
    }
    // 0x800BB1A0: nop

    // 0x800BB1A4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB1A8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800BB1AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BB1B0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800BB1B4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BB1B8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800BB1BC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BB1C0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BB1C4: lbu         $t1, -0x1956($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1956);
    // 0x800BB1C8: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x800BB1CC: nop

    // 0x800BB1D0: bne         $t1, $t2, L_800BB21C
    if (ctx->r9 != ctx->r10) {
        // 0x800BB1D4: nop
    
            goto L_800BB21C;
    }
    // 0x800BB1D4: nop

    // 0x800BB1D8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB1DC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800BB1E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800BB1E4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800BB1E8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB1EC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800BB1F0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB1F4: addiu       $t5, $t5, -0x1988
    ctx->r13 = ADD32(ctx->r13, -0X1988);
    // 0x800BB1F8: jal         0x800BA1E8
    // 0x800BB1FC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    AudioDriver_DeallocSound(rdram, ctx);
        goto after_0;
    // 0x800BB1FC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_0:
    // 0x800BB200: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB204: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB208: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BB20C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BB210: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BB214: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BB218: sw          $zero, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = 0;
L_800BB21C:
    // 0x800BB21C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB220: nop

    // 0x800BB224: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BB228: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800BB22C: bne         $at, $zero, L_800BB17C
    if (ctx->r1 != 0) {
        // 0x800BB230: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_800BB17C;
    }
    // 0x800BB230: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800BB234: b           L_800BB23C
    // 0x800BB238: nop

        goto L_800BB23C;
    // 0x800BB238: nop

L_800BB23C:
    // 0x800BB23C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BB244: jr          $ra
    // 0x800BB248: nop

    return;
    // 0x800BB248: nop

;}
RECOMP_FUNC void func_80066974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006697C: jal         0x80061348
    // 0x80066980: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066980: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x80066984: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066988: b           L_80066998
    // 0x8006698C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066998;
    // 0x8006698C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066990: b           L_80066998
    // 0x80066994: nop

        goto L_80066998;
    // 0x80066994: nop

L_80066998:
    // 0x80066998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006699C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800669A0: jr          $ra
    // 0x800669A4: nop

    return;
    // 0x800669A4: nop

;}
RECOMP_FUNC void func_800055DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800055DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800055E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800055E4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800055E8: lw          $t6, -0x73DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73DC);
    // 0x800055EC: nop

    // 0x800055F0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800055F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800055F8:
    // 0x800055F8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800055FC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80005600: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x80005604: nop

    // 0x80005608: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000560C: beq         $t9, $zero, L_800056D4
    if (ctx->r25 == 0) {
        // 0x80005610: nop
    
            goto L_800056D4;
    }
    // 0x80005610: nop

    // 0x80005614: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x80005618: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8000561C: beq         $t0, $zero, L_800056D4
    if (ctx->r8 == 0) {
        // 0x80005620: nop
    
            goto L_800056D4;
    }
    // 0x80005620: nop

    // 0x80005624: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80005628: nop

    // 0x8000562C: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x80005630: nop

    // 0x80005634: beq         $t2, $zero, L_80005650
    if (ctx->r10 == 0) {
        // 0x80005638: nop
    
            goto L_80005650;
    }
    // 0x80005638: nop

    // 0x8000563C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80005640: nop

    // 0x80005644: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x80005648: jal         0x800BC980
    // 0x8000564C: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x8000564C: nop

    after_0:
L_80005650:
    // 0x80005650: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80005654: nop

    // 0x80005658: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x8000565C: nop

    // 0x80005660: beq         $t5, $zero, L_8000567C
    if (ctx->r13 == 0) {
        // 0x80005664: nop
    
            goto L_8000567C;
    }
    // 0x80005664: nop

    // 0x80005668: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8000566C: nop

    // 0x80005670: lw          $a0, 0x12C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X12C);
    // 0x80005674: jal         0x800BC980
    // 0x80005678: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80005678: nop

    after_1:
L_8000567C:
    // 0x8000567C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005680: nop

    // 0x80005684: lw          $t9, 0x130($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X130);
    // 0x80005688: nop

    // 0x8000568C: beq         $t9, $zero, L_800056A8
    if (ctx->r25 == 0) {
        // 0x80005690: nop
    
            goto L_800056A8;
    }
    // 0x80005690: nop

    // 0x80005694: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80005698: nop

    // 0x8000569C: lw          $a0, 0x130($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X130);
    // 0x800056A0: jal         0x800BC980
    // 0x800056A4: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800056A4: nop

    after_2:
L_800056A8:
    // 0x800056A8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800056AC: nop

    // 0x800056B0: lw          $t1, 0x144($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X144);
    // 0x800056B4: nop

    // 0x800056B8: beq         $t1, $zero, L_800056D4
    if (ctx->r9 == 0) {
        // 0x800056BC: nop
    
            goto L_800056D4;
    }
    // 0x800056BC: nop

    // 0x800056C0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800056C4: nop

    // 0x800056C8: lw          $a0, 0x144($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X144);
    // 0x800056CC: jal         0x800BC980
    // 0x800056D0: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800056D0: nop

    after_3:
L_800056D4:
    // 0x800056D4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800056D8: nop

    // 0x800056DC: sw          $zero, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = 0;
    // 0x800056E0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800056E4: nop

    // 0x800056E8: sw          $zero, 0x138($t4)
    MEM_W(0X138, ctx->r12) = 0;
    // 0x800056EC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800056F0: nop

    // 0x800056F4: sw          $zero, 0x12C($t5)
    MEM_W(0X12C, ctx->r13) = 0;
    // 0x800056F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800056FC: nop

    // 0x80005700: sw          $zero, 0x130($t6)
    MEM_W(0X130, ctx->r14) = 0;
    // 0x80005704: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005708: nop

    // 0x8000570C: sw          $zero, 0x144($t7)
    MEM_W(0X144, ctx->r15) = 0;
    // 0x80005710: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80005714: nop

    // 0x80005718: addiu       $t8, $t9, 0x160
    ctx->r24 = ADD32(ctx->r25, 0X160);
    // 0x8000571C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80005720: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80005724: nop

    // 0x80005728: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000572C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80005730: bne         $at, $zero, L_800055F8
    if (ctx->r1 != 0) {
        // 0x80005734: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_800055F8;
    }
    // 0x80005734: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80005738: b           L_80005748
    // 0x8000573C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005748;
    // 0x8000573C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005740: b           L_80005748
    // 0x80005744: nop

        goto L_80005748;
    // 0x80005744: nop

L_80005748:
    // 0x80005748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000574C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005750: jr          $ra
    // 0x80005754: nop

    return;
    // 0x80005754: nop

;}
RECOMP_FUNC void func_8001C1F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C1F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C1F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C1FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001C200: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001C204: nop

    // 0x8001C208: lw          $t7, 0x13C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X13C);
    // 0x8001C20C: nop

    // 0x8001C210: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001C214: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001C218: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8001C21C: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x8001C220: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x8001C224: nop

    // 0x8001C228: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C22C: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C230: blez        $t1, L_8001C27C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C234: nop
    
            goto L_8001C27C;
    }
    // 0x8001C234: nop

L_8001C238:
    // 0x8001C238: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001C23C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C240: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001C244: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8001C248: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8001C24C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C250: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001C254: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001C258: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001C25C: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x8001C260: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x8001C264: nop

    // 0x8001C268: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C26C: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C270: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C274: bne         $at, $zero, L_8001C238
    if (ctx->r1 != 0) {
        // 0x8001C278: nop
    
            goto L_8001C238;
    }
    // 0x8001C278: nop

L_8001C27C:
    // 0x8001C27C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8001C280: addiu       $a2, $zero, 0x1E00
    ctx->r6 = ADD32(0, 0X1E00);
    // 0x8001C284: lw          $a0, 0x140($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X140);
    // 0x8001C288: lw          $a1, 0x13C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X13C);
    // 0x8001C28C: jal         0x800BD110
    // 0x8001C290: nop

    SysMem_Copy64(rdram, ctx);
        goto after_0;
    // 0x8001C290: nop

    after_0:
    // 0x8001C294: b           L_8001C29C
    // 0x8001C298: nop

        goto L_8001C29C;
    // 0x8001C298: nop

L_8001C29C:
    // 0x8001C29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C2A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001C2A4: jr          $ra
    // 0x8001C2A8: nop

    return;
    // 0x8001C2A8: nop

;}
RECOMP_FUNC void func_8006F7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F7D0: jal         0x80061488
    // 0x8006F7D4: addiu       $a0, $zero, 0x3D3
    ctx->r4 = ADD32(0, 0X3D3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F7D4: addiu       $a0, $zero, 0x3D3
    ctx->r4 = ADD32(0, 0X3D3);
    after_0:
    // 0x8006F7D8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F7DC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006F7E0: b           L_8006F7F0
    // 0x8006F7E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F7F0;
    // 0x8006F7E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F7E8: b           L_8006F7F0
    // 0x8006F7EC: nop

        goto L_8006F7F0;
    // 0x8006F7EC: nop

L_8006F7F0:
    // 0x8006F7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F7F8: jr          $ra
    // 0x8006F7FC: nop

    return;
    // 0x8006F7FC: nop

;}
RECOMP_FUNC void func_80086864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008686C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086874: jal         0x8008A46C
    // 0x80086878: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80086878: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x8008687C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086880: jal         0x8008BFF4
    // 0x80086884: nop

    func_8008BFF4(rdram, ctx);
        goto after_1;
    // 0x80086884: nop

    after_1:
    // 0x80086888: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008688C: jal         0x80089170
    // 0x80086890: nop

    func_80089170(rdram, ctx);
        goto after_2;
    // 0x80086890: nop

    after_2:
    // 0x80086894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086898: jal         0x80089418
    // 0x8008689C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80089418(rdram, ctx);
        goto after_3;
    // 0x8008689C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800868A0: b           L_800868B0
    // 0x800868A4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_800868B0;
    // 0x800868A4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800868A8: b           L_800868B0
    // 0x800868AC: nop

        goto L_800868B0;
    // 0x800868AC: nop

L_800868B0:
    // 0x800868B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800868B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800868B8: jr          $ra
    // 0x800868BC: nop

    return;
    // 0x800868BC: nop

;}
RECOMP_FUNC void func_800B9000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B9004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B900C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B9010: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B9014: jal         0x800BB448
    // 0x800B9018: nop

    func_800BB448(rdram, ctx);
        goto after_0;
    // 0x800B9018: nop

    after_0:
    // 0x800B901C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B9020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B9024: jal         0x800BB4B4
    // 0x800B9028: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BB4B4(rdram, ctx);
        goto after_1;
    // 0x800B9028: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800B902C: b           L_800B9034
    // 0x800B9030: nop

        goto L_800B9034;
    // 0x800B9030: nop

L_800B9034:
    // 0x800B9034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9038: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B903C: jr          $ra
    // 0x800B9040: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B9040: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006FBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FBA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FBAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FBB0: nop

    // 0x8006FBB4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006FBB8: nop

    // 0x8006FBBC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006FBC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006FBC4: jr          $ra
    // 0x8006FBC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FBC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FBCC: jr          $ra
    // 0x8006FBD0: nop

    return;
    // 0x8006FBD0: nop

    // 0x8006FBD4: jr          $ra
    // 0x8006FBD8: nop

    return;
    // 0x8006FBD8: nop

;}
RECOMP_FUNC void func_8006E6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E6C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E6CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E6D0: jal         0x80061348
    // 0x8006E6D4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E6D4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E6D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E6DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E6E0: beq         $v0, $zero, L_8006E6FC
    if (ctx->r2 == 0) {
        // 0x8006E6E4: nop
    
            goto L_8006E6FC;
    }
    // 0x8006E6E4: nop

    // 0x8006E6E8: jal         0x80061348
    // 0x8006E6EC: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E6EC: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_1:
    // 0x8006E6F0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006E6F4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006E6F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E6FC:
    // 0x8006E6FC: b           L_8006E70C
    // 0x8006E700: nop

        goto L_8006E70C;
    // 0x8006E700: nop

    // 0x8006E704: b           L_8006E70C
    // 0x8006E708: nop

        goto L_8006E70C;
    // 0x8006E708: nop

L_8006E70C:
    // 0x8006E70C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E714: jr          $ra
    // 0x8006E718: nop

    return;
    // 0x8006E718: nop

;}
RECOMP_FUNC void func_80087EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087EEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087EF0: jal         0x8008B4EC
    // 0x80087EF4: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80087EF4: nop

    after_0:
    // 0x80087EF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087EFC: jal         0x8008BC70
    // 0x80087F00: nop

    func_8008BC70(rdram, ctx);
        goto after_1;
    // 0x80087F00: nop

    after_1:
    // 0x80087F04: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80087F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087F0C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80087F10: jal         0x8008B738
    // 0x80087F14: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80087F14: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    after_2:
    // 0x80087F18: b           L_80087F20
    // 0x80087F1C: nop

        goto L_80087F20;
    // 0x80087F1C: nop

L_80087F20:
    // 0x80087F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087F28: jr          $ra
    // 0x80087F2C: nop

    return;
    // 0x80087F2C: nop

;}
RECOMP_FUNC void alSeqpStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CAD94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAD98: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800CAD9C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800CADA0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CADA4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CADA8: jal         0x800D3A2C
    // 0x800CADAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CADAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CADB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CADB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CADB8: jr          $ra
    // 0x800CADBC: nop

    return;
    // 0x800CADBC: nop

;}
