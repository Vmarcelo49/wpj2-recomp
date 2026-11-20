#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8002BB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BB04: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BB08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BB0C: slti        $at, $a0, 0x2A
    ctx->r1 = SIGNED(ctx->r4) < 0X2A ? 1 : 0;
    // 0x8002BB10: bne         $at, $zero, L_8002BB28
    if (ctx->r1 != 0) {
        // 0x8002BB14: nop

            goto L_8002BB28;
    }
    // 0x8002BB14: nop

    // 0x8002BB18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002BB1C: lwc1        $f0, -0x1910($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1910);
    // 0x8002BB20: jr          $ra
    // 0x8002BB24: nop

    return;
    // 0x8002BB24: nop

L_8002BB28:
    // 0x8002BB28: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BB2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002BB30: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002BB34: lwc1        $f0, -0x46C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X46C8);
    // 0x8002BB38: jr          $ra
    // 0x8002BB3C: nop

    return;
    // 0x8002BB3C: nop

    // 0x8002BB40: jr          $ra
    // 0x8002BB44: nop

    return;
    // 0x8002BB44: nop

    // 0x8002BB48: jr          $ra
    // 0x8002BB4C: nop

    return;
    // 0x8002BB4C: nop

;}
RECOMP_FUNC void func_8002BB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BB50: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BB54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BB58: slti        $at, $a0, 0x2A
    ctx->r1 = SIGNED(ctx->r4) < 0X2A ? 1 : 0;
    // 0x8002BB5C: bne         $at, $zero, L_8002BB74
    if (ctx->r1 != 0) {
        // 0x8002BB60: nop

            goto L_8002BB74;
    }
    // 0x8002BB60: nop

    // 0x8002BB64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BB68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BB6C: jr          $ra
    // 0x8002BB70: nop

    return;
    // 0x8002BB70: nop

L_8002BB74:
    // 0x8002BB74: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BB78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002BB7C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002BB80: lwc1        $f0, -0x4620($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4620);
    // 0x8002BB84: jr          $ra
    // 0x8002BB88: nop

    return;
    // 0x8002BB88: nop

    // 0x8002BB8C: jr          $ra
    // 0x8002BB90: nop

    return;
    // 0x8002BB90: nop

    // 0x8002BB94: jr          $ra
    // 0x8002BB98: nop

    return;
    // 0x8002BB98: nop

;}
RECOMP_FUNC void func_8002BB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BB9C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BBA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BBA4: slti        $at, $a0, 0x2A
    ctx->r1 = SIGNED(ctx->r4) < 0X2A ? 1 : 0;
    // 0x8002BBA8: bne         $at, $zero, L_8002BBC0
    if (ctx->r1 != 0) {
        // 0x8002BBAC: nop

            goto L_8002BBC0;
    }
    // 0x8002BBAC: nop

    // 0x8002BBB0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002BBB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BBB8: jr          $ra
    // 0x8002BBBC: nop

    return;
    // 0x8002BBBC: nop

L_8002BBC0:
    // 0x8002BBC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BBC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002BBC8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002BBCC: lwc1        $f0, -0x44D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X44D0);
    // 0x8002BBD0: jr          $ra
    // 0x8002BBD4: nop

    return;
    // 0x8002BBD4: nop

    // 0x8002BBD8: jr          $ra
    // 0x8002BBDC: nop

    return;
    // 0x8002BBDC: nop

    // 0x8002BBE0: jr          $ra
    // 0x8002BBE4: nop

    return;
    // 0x8002BBE4: nop

;}
RECOMP_FUNC void func_8002BBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BBE8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BBEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BBF0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002BBF4: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8002BBF8: slt         $a1, $at, $a0
    ctx->r5 = SIGNED(ctx->r1) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002BBFC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8002BC00: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002BC04: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002BC08: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BC0C: beq         $a1, $zero, L_8002BC1C
    if (ctx->r5 == 0) {
        // 0x8002BC10: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8002BC1C;
    }
    // 0x8002BC10: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8002BC14: b           L_8002BC7C
    // 0x8002BC18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002BC7C;
    // 0x8002BC18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002BC1C:
    // 0x8002BC1C: bgez        $a0, L_8002BC2C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002BC20: sra         $t8, $a0, 3
        ctx->r24 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8002BC2C;
    }
    // 0x8002BC20: sra         $t8, $a0, 3
    ctx->r24 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8002BC24: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8002BC28: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8002BC2C:
    // 0x8002BC2C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8002BC30: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002BC34: lbu         $t9, -0x414C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X414C);
    // 0x8002BC38: bgez        $a0, L_8002BC4C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002BC3C: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_8002BC4C;
    }
    // 0x8002BC3C: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8002BC40: beq         $t0, $zero, L_8002BC4C
    if (ctx->r8 == 0) {
        // 0x8002BC44: nop

            goto L_8002BC4C;
    }
    // 0x8002BC44: nop

    // 0x8002BC48: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_8002BC4C:
    // 0x8002BC4C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8002BC50: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x8002BC54: srav        $v0, $t9, $t2
    ctx->r2 = S32(SIGNED(ctx->r25) >> (ctx->r10 & 31));
    // 0x8002BC58: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8002BC5C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8002BC60: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8002BC64: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8002BC68: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002BC6C: b           L_8002BC7C
    // 0x8002BC70: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_8002BC7C;
    // 0x8002BC70: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8002BC74: b           L_8002BC7C
    // 0x8002BC78: nop

        goto L_8002BC7C;
    // 0x8002BC78: nop

L_8002BC7C:
    // 0x8002BC7C: jr          $ra
    // 0x8002BC80: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002BC80: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_8002BD8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BD8C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BD90: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BD94: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8002BD98: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002BD9C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002BDA0: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BDA4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8002BDA8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8002BDAC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8002BDB0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002BDB4: lh          $t9, -0x4574($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4574);
    // 0x8002BDB8: nop

    // 0x8002BDBC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002BDC0: nop

    // 0x8002BDC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002BDC8: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8002BDCC: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8002BDD0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8002BDD4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002BDD8: lh          $t1, -0x4572($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4572);
    // 0x8002BDDC: nop

    // 0x8002BDE0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8002BDE4: nop

    // 0x8002BDE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002BDEC: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8002BDF0: jr          $ra
    // 0x8002BDF4: nop

    return;
    // 0x8002BDF4: nop

    // 0x8002BDF8: jr          $ra
    // 0x8002BDFC: nop

    return;
    // 0x8002BDFC: nop

;}
RECOMP_FUNC void func_8002BE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BE00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002BE04: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002BE08: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8002BE0C: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002BE10: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002BE14: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BE1C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002BE20: nop

    // 0x8002BE24: sh          $t7, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r15;
    // 0x8002BE28: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE2C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002BE30: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8002BE34: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002BE38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002BE3C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002BE40: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002BE44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002BE48: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002BE4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BE50: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002BE54: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x8002BE58: bc1f        L_8002BE8C
    if (!c1cs) {
        // 0x8002BE5C: nop

            goto L_8002BE8C;
    }
    // 0x8002BE5C: nop

    // 0x8002BE60: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8002BE64: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002BE68: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002BE6C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002BE70: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002BE74: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002BE78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BE7C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002BE80: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x8002BE84: b           L_8002BEB8
    // 0x8002BE88: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
        goto L_8002BEB8;
    // 0x8002BE88: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_8002BE8C:
    // 0x8002BE8C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE90: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002BE94: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002BE98: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002BE9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002BEA0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002BEA4: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002BEA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BEAC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002BEB0: swc1        $f10, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f10.u32l;
    // 0x8002BEB4: neg.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f20.fl = -ctx->f10.fl;
L_8002BEB8:
    // 0x8002BEB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002BEBC: lwc1        $f19, -0x1908($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1908);
    // 0x8002BEC0: lwc1        $f18, -0x1904($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1904);
    // 0x8002BEC4: cvt.d.s     $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f16.d = CVT_D_S(ctx->f20.fl);
    // 0x8002BEC8: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8002BECC: nop

    // 0x8002BED0: bc1f        L_8002BEE8
    if (!c1cs) {
        // 0x8002BED4: nop

            goto L_8002BEE8;
    }
    // 0x8002BED4: nop

    // 0x8002BED8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002BEDC: lwc1        $f4, -0x1900($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1900);
    // 0x8002BEE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BEE4: swc1        $f4, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f4.u32l;
L_8002BEE8:
    // 0x8002BEE8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8002BEEC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002BEF0: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8002BEF4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002BEF8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002BEFC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002BF00: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8002BF04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF08: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002BF0C: swc1        $f18, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f18.u32l;
    // 0x8002BF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF14: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002BF18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002BF1C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002BF20: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002BF24: addiu       $t1, $t1, 0x3090
    ctx->r9 = ADD32(ctx->r9, 0X3090);
    // 0x8002BF28: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002BF2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002BF30: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002BF34: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8002BF38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002BF3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002BF40: jal         0x800C3D70
    // 0x8002BF44: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_0;
    // 0x8002BF44: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8002BF48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002BF4C: lwc1        $f8, 0x30A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002BF50: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8002BF54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002BF58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002BF5C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002BF60: swc1        $f16, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f16.u32l;
    // 0x8002BF64: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8002BF68: jal         0x800299C4
    // 0x8002BF6C: nop

    func_800299C4(rdram, ctx);
        goto after_1;
    // 0x8002BF6C: nop

    after_1:
    // 0x8002BF70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002BF74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF78: sh          $t2, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = ctx->r10;
    // 0x8002BF7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002BF80: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002BF84: jal         0x8002BB04
    // 0x8002BF88: nop

    func_8002BB04(rdram, ctx);
        goto after_2;
    // 0x8002BF88: nop

    after_2:
    // 0x8002BF8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF90: swc1        $f0, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f0.u32l;
    // 0x8002BF94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002BF98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BF9C: swc1        $f18, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f18.u32l;
    // 0x8002BFA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BFA4: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002BFA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BFAC: swc1        $f18, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f18.u32l;
    // 0x8002BFB0: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002BFB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002BFB8: sh          $t3, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r11;
    // 0x8002BFBC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002BFC0: lh          $t4, 0x1644($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X1644);
    // 0x8002BFC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002BFC8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8002BFCC: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8002BFD0: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x8002BFD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002BFD8: jal         0x800AFB70
    // 0x8002BFDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_3;
    // 0x8002BFDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8002BFE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002BFE4: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x8002BFE8: b           L_8002BFF0
    // 0x8002BFEC: nop

        goto L_8002BFF0;
    // 0x8002BFEC: nop

L_8002BFF0:
    // 0x8002BFF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002BFF4: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002BFF8: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002BFFC: jr          $ra
    // 0x8002C000: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002C000: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002C004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C00C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002C018: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8002C01C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002C020: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002C024: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002C028: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C02C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C030: lwc1        $f17, -0x18F8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X18F8);
    // 0x8002C034: lwc1        $f16, -0x18F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X18F4);
    // 0x8002C038: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002C03C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C040: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8002C044: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002C048: swc1        $f4, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f4.u32l;
    // 0x8002C04C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8002C050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002C054: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C058: swc1        $f6, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f6.u32l;
    // 0x8002C05C: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8002C060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C064: sh          $t6, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r14;
    // 0x8002C068: jal         0x8002BB9C
    // 0x8002C06C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8002BB9C(rdram, ctx);
        goto after_0;
    // 0x8002C06C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8002C070: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C074: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x8002C078: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002C07C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C080: sh          $t7, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r15;
    // 0x8002C084: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002C088: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C08C: sh          $t8, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = ctx->r24;
    // 0x8002C090: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8002C094: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C098: sb          $t9, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = ctx->r25;
    // 0x8002C09C: jal         0x800B9000
    // 0x8002C0A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8002C0A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x8002C0A4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002C0A8: lw          $t0, 0x307C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X307C);
    // 0x8002C0AC: nop

    // 0x8002C0B0: bne         $t0, $zero, L_8002C0E4
    if (ctx->r8 != 0) {
        // 0x8002C0B4: nop

            goto L_8002C0E4;
    }
    // 0x8002C0B4: nop

    // 0x8002C0B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C0BC: lh          $t1, 0x1644($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1644);
    // 0x8002C0C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002C0C4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002C0C8: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8002C0CC: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x8002C0D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C0D4: jal         0x800AFB70
    // 0x8002C0D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x8002C0D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8002C0DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C0E0: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
L_8002C0E4:
    // 0x8002C0E4: b           L_8002C0EC
    // 0x8002C0E8: nop

        goto L_8002C0EC;
    // 0x8002C0E8: nop

L_8002C0EC:
    // 0x8002C0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C0F4: jr          $ra
    // 0x8002C0F8: nop

    return;
    // 0x8002C0F8: nop

;}
RECOMP_FUNC void func_8002C0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C0FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C10C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002C110: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8002C114: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C118: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002C11C: nop

    // 0x8002C120: sh          $t7, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r15;
    // 0x8002C124: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8002C128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C12C: sw          $t8, 0x1658($at)
    MEM_W(0X1658, ctx->r1) = ctx->r24;
    // 0x8002C130: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002C134: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C138: sh          $t9, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = ctx->r25;
    // 0x8002C13C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C140: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002C144: jal         0x8002BB04
    // 0x8002C148: nop

    func_8002BB04(rdram, ctx);
        goto after_0;
    // 0x8002C148: nop

    after_0:
    // 0x8002C14C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C150: swc1        $f0, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f0.u32l;
    // 0x8002C154: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002C158: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002C15C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002C160: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002C164: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C168: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002C16C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C170: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002C174: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x8002C178: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002C17C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002C180: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C188: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C18C: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002C190: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C194: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C198: swc1        $f10, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f10.u32l;
    // 0x8002C19C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C1A0: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002C1A4: lwc1        $f5, -0x18F0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X18F0);
    // 0x8002C1A8: lwc1        $f4, -0x18EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X18EC);
    // 0x8002C1AC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C1B0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8002C1B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C1B8: neg.d       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.d = -ctx->f6.d;
    // 0x8002C1BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C1C0: swc1        $f10, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f10.u32l;
    // 0x8002C1C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002C1C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002C1CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C1D0: swc1        $f16, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f16.u32l;
    // 0x8002C1D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C1D8: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002C1DC: jal         0x8002BB9C
    // 0x8002C1E0: nop

    func_8002BB9C(rdram, ctx);
        goto after_1;
    // 0x8002C1E0: nop

    after_1:
    // 0x8002C1E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C1E8: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x8002C1EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C1F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C1F4: swc1        $f18, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f18.u32l;
    // 0x8002C1F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C1FC: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002C200: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C204: swc1        $f18, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f18.u32l;
    // 0x8002C208: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8002C20C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C210: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C214: swc1        $f4, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f4.u32l;
    // 0x8002C218: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002C21C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C220: sh          $t0, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r8;
    // 0x8002C224: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C228: lh          $t1, 0x1644($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1644);
    // 0x8002C22C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002C230: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002C234: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8002C238: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x8002C23C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C240: jal         0x800AFB70
    // 0x8002C244: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x8002C244: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8002C248: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C24C: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x8002C250: b           L_8002C258
    // 0x8002C254: nop

        goto L_8002C258;
    // 0x8002C254: nop

L_8002C258:
    // 0x8002C258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C260: jr          $ra
    // 0x8002C264: nop

    return;
    // 0x8002C264: nop

    // 0x8002C268: nop

    // 0x8002C26C: nop

;}
RECOMP_FUNC void func_8002C270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C278: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002C27C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8002C280: lbu         $t6, 0x448($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X448);
    // 0x8002C284: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C288: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002C28C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8002C290: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8002C294: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002C298: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002C29C: lw          $t1, 0x1668($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1668);
    // 0x8002C2A0: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x8002C2A4: beq         $t1, $zero, L_8002C2C8
    if (ctx->r9 == 0) {
        // 0x8002C2A8: nop

            goto L_8002C2C8;
    }
    // 0x8002C2A8: nop

    // 0x8002C2AC: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x8002C2B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C2B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8002C2B8: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8002C2BC: lw          $a0, 0x1668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1668);
    // 0x8002C2C0: jal         0x800BC980
    // 0x8002C2C4: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x8002C2C4: nop

    after_0:
L_8002C2C8:
    // 0x8002C2C8: lhu         $t5, 0x1E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X1E);
    // 0x8002C2CC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002C2D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C2D4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002C2D8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002C2DC: sw          $t4, 0x1668($at)
    MEM_W(0X1668, ctx->r1) = ctx->r12;
    // 0x8002C2E0: b           L_8002C2E8
    // 0x8002C2E4: nop

        goto L_8002C2E8;
    // 0x8002C2E4: nop

L_8002C2E8:
    // 0x8002C2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C2EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C2F0: jr          $ra
    // 0x8002C2F4: nop

    return;
    // 0x8002C2F4: nop

;}
RECOMP_FUNC void func_8002C2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C2F8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002C2FC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002C300: swc1        $f29, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002C304: swc1        $f28, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f28.u32l;
    // 0x8002C308: swc1        $f27, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002C30C: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x8002C310: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002C314: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x8002C318: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002C31C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002C320: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002C324: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002C328: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002C32C: lh          $t6, 0x1630($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1630);
    // 0x8002C330: nop

    // 0x8002C334: bne         $t6, $zero, L_8002C344
    if (ctx->r14 != 0) {
        // 0x8002C338: nop

            goto L_8002C344;
    }
    // 0x8002C338: nop

    // 0x8002C33C: b           L_8002D1CC
    // 0x8002C340: nop

        goto L_8002D1CC;
    // 0x8002C340: nop

L_8002C344:
    // 0x8002C344: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002C348: sh          $t7, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r15;
    // 0x8002C34C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002C350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C354: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8002C358: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002C35C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8002C360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002C364: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C368: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C36C: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x8002C370: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x8002C374: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x8002C378: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002C37C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8002C380: jal         0x800B0E88
    // 0x8002C384: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800B0E88(rdram, ctx);
        goto after_0;
    // 0x8002C384: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8002C388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002C38C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002C390: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x8002C394: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8002C398: swc1        $f10, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f10.u32l;
    // 0x8002C39C: lwc1        $f20, 0x20($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8002C3A0: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x8002C3A4: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x8002C3A8: swc1        $f20, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f20.u32l;
    // 0x8002C3AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002C3B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002C3B4: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x8002C3B8: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x8002C3BC: swc1        $f16, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f16.u32l;
    // 0x8002C3C0: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8002C3C4: nop

    // 0x8002C3C8: swc1        $f18, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f18.u32l;
    // 0x8002C3CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002C3D0: addiu       $t3, $sp, 0x70
    ctx->r11 = ADD32(ctx->r29, 0X70);
    // 0x8002C3D4: addiu       $t4, $sp, 0x70
    ctx->r12 = ADD32(ctx->r29, 0X70);
    // 0x8002C3D8: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8002C3DC: lwc1        $f28, 0x8($t4)
    ctx->f28.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8002C3E0: addiu       $t5, $sp, 0x70
    ctx->r13 = ADD32(ctx->r29, 0X70);
    // 0x8002C3E4: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x8002C3E8: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x8002C3EC: swc1        $f28, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f28.u32l;
    // 0x8002C3F0: swc1        $f26, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f26.u32l;
    // 0x8002C3F4: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x8002C3F8: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8002C3FC: swc1        $f24, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f24.u32l;
    // 0x8002C400: addiu       $t7, $sp, 0x70
    ctx->r15 = ADD32(ctx->r29, 0X70);
    // 0x8002C404: swc1        $f22, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f22.u32l;
    // 0x8002C408: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8002C40C: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x8002C410: swc1        $f20, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f20.u32l;
    // 0x8002C414: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8002C418: swc1        $f20, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f20.u32l;
    // 0x8002C41C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C420: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C424: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8002C428: jal         0x800B1250
    // 0x8002C42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_1;
    // 0x8002C42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8002C430: jal         0x800C1850
    // 0x8002C434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_2;
    // 0x8002C434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8002C438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C43C: lwc1        $f6, 0x1618($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x8002C440: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C444: lwc1        $f11, -0x18E0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X18E0);
    // 0x8002C448: lwc1        $f10, -0x18DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X18DC);
    // 0x8002C44C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C450: lwc1        $f18, 0x1624($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C454: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C458: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8002C45C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8002C460: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C464: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C468: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x8002C46C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C470: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002C474: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C478: jal         0x800C2304
    // 0x8002C47C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_3;
    // 0x8002C47C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    after_3:
    // 0x8002C480: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002C484: lh          $t0, 0x163C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X163C);
    // 0x8002C488: nop

    // 0x8002C48C: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8002C490: bne         $at, $zero, L_8002C4A8
    if (ctx->r1 != 0) {
        // 0x8002C494: nop

            goto L_8002C4A8;
    }
    // 0x8002C494: nop

    // 0x8002C498: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C49C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C4A0: jal         0x800AD1E4
    // 0x8002C4A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800AD1E4(rdram, ctx);
        goto after_4;
    // 0x8002C4A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_8002C4A8:
    // 0x8002C4A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C4AC: lh          $t1, 0x163C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X163C);
    // 0x8002C4B0: nop

    // 0x8002C4B4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8002C4B8: sltiu       $at, $t2, 0xD
    ctx->r1 = ctx->r10 < 0XD ? 1 : 0;
    // 0x8002C4BC: beq         $at, $zero, L_8002D190
    if (ctx->r1 == 0) {
        // 0x8002C4C0: nop

            goto L_8002D190;
    }
    // 0x8002C4C0: nop

    // 0x8002C4C4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002C4C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C4CC: addu        $at, $at, $t2
    gpr jr_addend_8002C4D8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8002C4D0: lw          $t2, -0x18D8($at)
    ctx->r10 = ADD32(ctx->r1, -0X18D8);
    // 0x8002C4D4: nop

    // 0x8002C4D8: jr          $t2
    // 0x8002C4DC: nop

    switch (jr_addend_8002C4D8 >> 2) {
        case 0: goto L_8002C4E0; break;
        case 1: goto L_8002C6AC; break;
        case 2: goto L_8002C714; break;
        case 3: goto L_8002D190; break;
        case 4: goto L_8002D190; break;
        case 5: goto L_8002D190; break;
        case 6: goto L_8002D190; break;
        case 7: goto L_8002D190; break;
        case 8: goto L_8002D190; break;
        case 9: goto L_8002C984; break;
        case 10: goto L_8002CAE0; break;
        case 11: goto L_8002CE6C; break;
        case 12: goto L_8002CF64; break;
        default: switch_error(__func__, 0x8002C4D8, 0x800EE728);
    }
    // 0x8002C4DC: nop

L_8002C4E0:
    // 0x8002C4E0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C4E4: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C4E8: jal         0x800AD1E4
    // 0x8002C4EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800AD1E4(rdram, ctx);
        goto after_5;
    // 0x8002C4EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x8002C4F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C4F4: lwc1        $f10, -0x69E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X69E8);
    // 0x8002C4F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C4FC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C504: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8002C508: lwc1        $f4, 0x1618($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x8002C50C: nop

    // 0x8002C510: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8002C514: swc1        $f6, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f6.u32l;
    // 0x8002C518: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C51C: lwc1        $f8, -0x69E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C520: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C524: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C528: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C52C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002C530: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C534: nop

    // 0x8002C538: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8002C53C: swc1        $f18, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f18.u32l;
    // 0x8002C540: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8002C544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002C548: nop

    // 0x8002C54C: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8002C550: nop

    // 0x8002C554: bc1f        L_8002C5BC
    if (!c1cs) {
        // 0x8002C558: nop

            goto L_8002C5BC;
    }
    // 0x8002C558: nop

    // 0x8002C55C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002C560: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002C564: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C568: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8002C56C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002C570: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002C574: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002C578: lh          $a2, 0x1644($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1644);
    // 0x8002C57C: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8002C580: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8002C584: jal         0x800298A4
    // 0x8002C588: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800298A4(rdram, ctx);
        goto after_6;
    // 0x8002C588: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8002C58C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C590: sb          $zero, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = 0;
    // 0x8002C594: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C598: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x8002C59C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C5A0: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002C5A4: jal         0x8002C270
    // 0x8002C5A8: nop

    func_8002C270(rdram, ctx);
        goto after_7;
    // 0x8002C5A8: nop

    after_7:
    // 0x8002C5AC: jal         0x800B0E08
    // 0x8002C5B0: nop

    func_800B0E08(rdram, ctx);
        goto after_8;
    // 0x8002C5B0: nop

    after_8:
    // 0x8002C5B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C5B8: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8002C5BC:
    // 0x8002C5BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C5C0: lwc1        $f11, -0x18A0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X18A0);
    // 0x8002C5C4: lwc1        $f10, -0x189C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X189C);
    // 0x8002C5C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C5CC: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C5D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C5D4: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C5D8: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8002C5DC: lwc1        $f6, -0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C5E0: nop

    // 0x8002C5E4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C5E8: sub.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f8.d - ctx->f18.d;
    // 0x8002C5EC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8002C5F0: swc1        $f10, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f10.u32l;
    // 0x8002C5F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C5F8: lwc1        $f7, -0x1898($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1898);
    // 0x8002C5FC: lwc1        $f6, -0x1894($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1894);
    // 0x8002C600: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002C604: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x8002C608: nop

    // 0x8002C60C: bc1f        L_8002C624
    if (!c1cs) {
        // 0x8002C610: nop

            goto L_8002C624;
    }
    // 0x8002C610: nop

    // 0x8002C614: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C618: lwc1        $f8, -0x1890($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1890);
    // 0x8002C61C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C620: swc1        $f8, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f8.u32l;
L_8002C624:
    // 0x8002C624: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8002C628: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002C62C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C630: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C634: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C638: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C63C: mul.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8002C640: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C644: lwc1        $f6, 0x1354($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x8002C648: nop

    // 0x8002C64C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C650: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x8002C654: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8002C658: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002C65C: jal         0x800C25B8
    // 0x8002C660: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_9;
    // 0x8002C660: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    after_9:
    // 0x8002C664: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x8002C668: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002C66C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C670: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C674: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002C678: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C67C: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8002C680: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C684: lwc1        $f4, 0x12A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002C688: nop

    // 0x8002C68C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C690: sub.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = ctx->f18.d - ctx->f16.d;
    // 0x8002C694: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8002C698: swc1        $f10, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f10.u32l;
    // 0x8002C69C: jal         0x800C23E8
    // 0x8002C6A0: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_10;
    // 0x8002C6A0: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    after_10:
    // 0x8002C6A4: b           L_8002D190
    // 0x8002C6A8: nop

        goto L_8002D190;
    // 0x8002C6A8: nop

L_8002C6AC:
    // 0x8002C6AC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C6B0: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C6B4: jal         0x800AD1E4
    // 0x8002C6B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_11;
    // 0x8002C6B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x8002C6BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6C0: lwc1        $f8, 0x1650($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1650);
    // 0x8002C6C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6C8: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C6CC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8002C6D0: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8002C6D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C6D8: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C6DC: c.le.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d <= ctx->f6.d;
    // 0x8002C6E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6E4: bc1f        L_8002C708
    if (!c1cs) {
        // 0x8002C6E8: swc1        $f18, 0x1650($at)
        MEM_W(0X1650, ctx->r1) = ctx->f18.u32l;
            goto L_8002C708;
    }
    // 0x8002C6E8: swc1        $f18, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f18.u32l;
    // 0x8002C6EC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8002C6F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6F4: sh          $t3, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r11;
    // 0x8002C6F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C6FC: lw          $a0, 0x1658($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1658);
    // 0x8002C700: jal         0x800299C4
    // 0x8002C704: nop

    func_800299C4(rdram, ctx);
        goto after_12;
    // 0x8002C704: nop

    after_12:
L_8002C708:
    // 0x8002C708: sh          $zero, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = 0;
    // 0x8002C70C: b           L_8002D190
    // 0x8002C710: nop

        goto L_8002D190;
    // 0x8002C710: nop

L_8002C714:
    // 0x8002C714: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C718: lwc1        $f11, -0x1888($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1888);
    // 0x8002C71C: lwc1        $f10, -0x1884($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1884);
    // 0x8002C720: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C724: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C728: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C72C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C730: mul.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8002C734: lwc1        $f16, 0x15D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002C738: nop

    // 0x8002C73C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C740: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x8002C744: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C748: swc1        $f10, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f10.u32l;
    // 0x8002C74C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8002C750: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002C754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C758: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C75C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002C760: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C764: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002C768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C76C: lwc1        $f8, 0x1354($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x8002C770: nop

    // 0x8002C774: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C778: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x8002C77C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C780: swc1        $f4, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f4.u32l;
    // 0x8002C784: jal         0x800C25B8
    // 0x8002C788: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_13;
    // 0x8002C788: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    after_13:
    // 0x8002C78C: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002C790: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C798: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C79C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C7A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C7A4: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8002C7A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C7AC: lwc1        $f16, 0x12A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002C7B0: nop

    // 0x8002C7B4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C7B8: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x8002C7BC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C7C0: swc1        $f6, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f6.u32l;
    // 0x8002C7C4: jal         0x800C23E8
    // 0x8002C7C8: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_14;
    // 0x8002C7C8: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    after_14:
    // 0x8002C7CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C7D0: lwc1        $f10, -0x69E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X69E8);
    // 0x8002C7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C7D8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C7DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C7E0: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8002C7E4: lwc1        $f18, 0x1618($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x8002C7E8: nop

    // 0x8002C7EC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8002C7F0: swc1        $f8, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f8.u32l;
    // 0x8002C7F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C7F8: lwc1        $f6, -0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C7FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C800: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C804: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C808: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002C80C: lwc1        $f18, 0x1624($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C810: nop

    // 0x8002C814: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8002C818: swc1        $f4, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f4.u32l;
    // 0x8002C81C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C820: lwc1        $f8, -0x69E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C824: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002C828: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002C82C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C830: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x8002C834: nop

    // 0x8002C838: bc1f        L_8002C858
    if (!c1cs) {
        // 0x8002C83C: nop

            goto L_8002C858;
    }
    // 0x8002C83C: nop

    // 0x8002C840: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C844: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C848: jal         0x800AD1E4
    // 0x8002C84C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_15;
    // 0x8002C84C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x8002C850: b           L_8002C868
    // 0x8002C854: nop

        goto L_8002C868;
    // 0x8002C854: nop

L_8002C858:
    // 0x8002C858: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C85C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C860: jal         0x800AD1E4
    // 0x8002C864: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800AD1E4(rdram, ctx);
        goto after_16;
    // 0x8002C864: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
L_8002C868:
    // 0x8002C868: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C86C: lwc1        $f19, -0x1880($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1880);
    // 0x8002C870: lwc1        $f18, -0x187C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X187C);
    // 0x8002C874: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C878: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C87C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C880: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C884: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8002C888: lwc1        $f6, -0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C88C: nop

    // 0x8002C890: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C894: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C898: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x8002C89C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C8A0: swc1        $f18, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f18.u32l;
    // 0x8002C8A4: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x8002C8A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C8AC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C8B0: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8002C8B4: nop

    // 0x8002C8B8: bc1f        L_8002C8D0
    if (!c1cs) {
        // 0x8002C8BC: nop

            goto L_8002C8D0;
    }
    // 0x8002C8BC: nop

    // 0x8002C8C0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8002C8C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002C8C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C8CC: swc1        $f10, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f10.u32l;
L_8002C8D0:
    // 0x8002C8D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C8D4: lwc1        $f8, 0x1624($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C8D8: lui         $at, 0xC054
    ctx->r1 = S32(0XC054 << 16);
    // 0x8002C8DC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002C8E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C8E4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C8E8: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8002C8EC: nop

    // 0x8002C8F0: bc1f        L_8002C94C
    if (!c1cs) {
        // 0x8002C8F4: nop

            goto L_8002C94C;
    }
    // 0x8002C8F4: nop

    // 0x8002C8F8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002C8FC: lh          $t4, 0x1644($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X1644);
    // 0x8002C900: nop

    // 0x8002C904: beq         $t4, $zero, L_8002C94C
    if (ctx->r12 == 0) {
        // 0x8002C908: nop

            goto L_8002C94C;
    }
    // 0x8002C908: nop

    // 0x8002C90C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C910: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002C914: jal         0x80029C8C
    // 0x8002C918: nop

    func_80029C8C(rdram, ctx);
        goto after_17;
    // 0x8002C918: nop

    after_17:
    // 0x8002C91C: jal         0x80029ED8
    // 0x8002C920: nop

    func_80029ED8(rdram, ctx);
        goto after_18;
    // 0x8002C920: nop

    after_18:
    // 0x8002C924: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C928: sh          $zero, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = 0;
    // 0x8002C92C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C930: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002C934: jal         0x8002C270
    // 0x8002C938: nop

    func_8002C270(rdram, ctx);
        goto after_19;
    // 0x8002C938: nop

    after_19:
    // 0x8002C93C: jal         0x800B0E08
    // 0x8002C940: nop

    func_800B0E08(rdram, ctx);
        goto after_20;
    // 0x8002C940: nop

    after_20:
    // 0x8002C944: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C948: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8002C94C:
    // 0x8002C94C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C950: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C954: lui         $at, 0xC05E
    ctx->r1 = S32(0XC05E << 16);
    // 0x8002C958: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002C95C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002C960: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C964: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002C968: nop

    // 0x8002C96C: bc1f        L_8002C97C
    if (!c1cs) {
        // 0x8002C970: nop

            goto L_8002C97C;
    }
    // 0x8002C970: nop

    // 0x8002C974: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C978: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
L_8002C97C:
    // 0x8002C97C: b           L_8002D190
    // 0x8002C980: nop

        goto L_8002D190;
    // 0x8002C980: nop

L_8002C984:
    // 0x8002C984: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C988: lwc1        $f9, -0x1878($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1878);
    // 0x8002C98C: lwc1        $f8, -0x1874($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1874);
    // 0x8002C990: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C994: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C998: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C99C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C9A0: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8002C9A4: lwc1        $f6, 0x15D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002C9A8: nop

    // 0x8002C9AC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C9B0: add.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = ctx->f10.d + ctx->f4.d;
    // 0x8002C9B4: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C9B8: swc1        $f8, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f8.u32l;
    // 0x8002C9BC: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002C9C0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002C9C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C9C8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C9CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C9D0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C9D4: mul.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8002C9D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C9DC: lwc1        $f16, 0x1354($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x8002C9E0: nop

    // 0x8002C9E4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C9E8: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8002C9EC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8002C9F0: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002C9F4: jal         0x800C25B8
    // 0x8002C9F8: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_21;
    // 0x8002C9F8: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    after_21:
    // 0x8002C9FC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8002CA00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002CA04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CA08: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CA0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002CA10: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002CA14: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8002CA18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CA1C: lwc1        $f6, 0x12A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002CA20: nop

    // 0x8002CA24: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002CA28: sub.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = ctx->f18.d - ctx->f4.d;
    // 0x8002CA2C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8002CA30: swc1        $f10, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f10.u32l;
    // 0x8002CA34: jal         0x800C23E8
    // 0x8002CA38: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_22;
    // 0x8002CA38: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    after_22:
    // 0x8002CA3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CA40: lwc1        $f8, 0x3088($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002CA44: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002CA48: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002CA4C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002CA50: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002CA54: addiu       $a3, $a3, -0x69E8
    ctx->r7 = ADD32(ctx->r7, -0X69E8);
    // 0x8002CA58: addiu       $a2, $a2, 0x1624
    ctx->r6 = ADD32(ctx->r6, 0X1624);
    // 0x8002CA5C: addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, 0X1618);
    // 0x8002CA60: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    // 0x8002CA64: jal         0x800C3F2C
    // 0x8002CA68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_23;
    // 0x8002CA68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_23:
    // 0x8002CA6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CA70: lwc1        $f6, 0x30A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002CA74: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002CA78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CA7C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002CA80: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x8002CA84: nop

    // 0x8002CA88: bc1f        L_8002CAD8
    if (!c1cs) {
        // 0x8002CA8C: nop

            goto L_8002CAD8;
    }
    // 0x8002CA8C: nop

    // 0x8002CA90: jal         0x800B9000
    // 0x8002CA94: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800B9000(rdram, ctx);
        goto after_24;
    // 0x8002CA94: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_24:
    // 0x8002CA98: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002CA9C: lh          $t5, 0x163C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X163C);
    // 0x8002CAA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CAA4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002CAA8: sh          $t6, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r14;
    // 0x8002CAAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002CAB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002CAB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CAB8: swc1        $f16, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f16.u32l;
    // 0x8002CABC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002CAC0: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002CAC4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002CAC8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002CACC: addiu       $a2, $a2, 0x13C8
    ctx->r6 = ADD32(ctx->r6, 0X13C8);
    // 0x8002CAD0: jal         0x8002BD8C
    // 0x8002CAD4: addiu       $a1, $a1, 0x12A0
    ctx->r5 = ADD32(ctx->r5, 0X12A0);
    func_8002BD8C(rdram, ctx);
        goto after_25;
    // 0x8002CAD4: addiu       $a1, $a1, 0x12A0
    ctx->r5 = ADD32(ctx->r5, 0X12A0);
    after_25:
L_8002CAD8:
    // 0x8002CAD8: b           L_8002D190
    // 0x8002CADC: nop

        goto L_8002D190;
    // 0x8002CADC: nop

L_8002CAE0:
    // 0x8002CAE0: jal         0x800C4240
    // 0x8002CAE4: nop

    guRandom(rdram, ctx);
        goto after_26;
    // 0x8002CAE4: nop

    after_26:
    // 0x8002CAE8: bgez        $v0, L_8002CAFC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002CAEC: andi        $t7, $v0, 0xF
        ctx->r15 = ctx->r2 & 0XF;
            goto L_8002CAFC;
    }
    // 0x8002CAEC: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x8002CAF0: beq         $t7, $zero, L_8002CAFC
    if (ctx->r15 == 0) {
        // 0x8002CAF4: nop

            goto L_8002CAFC;
    }
    // 0x8002CAF4: nop

    // 0x8002CAF8: addiu       $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
L_8002CAFC:
    // 0x8002CAFC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8002CB00: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002CB04: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x8002CB08: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002CB0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002CB10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CB14: sub.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d);
    ctx->f18.d = ctx->f8.d - ctx->f6.d;
    // 0x8002CB18: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002CB1C: swc1        $f4, 0x7224($at)
    MEM_W(0X7224, ctx->r1) = ctx->f4.u32l;
    // 0x8002CB20: jal         0x800C4240
    // 0x8002CB24: nop

    guRandom(rdram, ctx);
        goto after_27;
    // 0x8002CB24: nop

    after_27:
    // 0x8002CB28: bgez        $v0, L_8002CB3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002CB2C: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_8002CB3C;
    }
    // 0x8002CB2C: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x8002CB30: beq         $t8, $zero, L_8002CB3C
    if (ctx->r24 == 0) {
        // 0x8002CB34: nop

            goto L_8002CB3C;
    }
    // 0x8002CB34: nop

    // 0x8002CB38: addiu       $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
L_8002CB3C:
    // 0x8002CB3C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8002CB40: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002CB44: cvt.d.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.d = CVT_D_W(ctx->f16.u32l);
    // 0x8002CB48: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002CB4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002CB50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CB54: sub.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = ctx->f10.d - ctx->f8.d;
    // 0x8002CB58: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8002CB5C: swc1        $f18, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = ctx->f18.u32l;
    // 0x8002CB60: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002CB64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CB68: lwc1        $f4, 0x61C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x8002CB6C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002CB70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CB74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CB78: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CB7C: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002CB80: lwc1        $f10, 0x61C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x8002CB84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002CB88: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8002CB8C: nop

    // 0x8002CB90: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8002CB94: nop

    // 0x8002CB98: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8002CB9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CBA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CBA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CBA8: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002CBAC: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8002CBB0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8002CBB4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8002CBB8: nop

    // 0x8002CBBC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002CBC0: nop

    // 0x8002CBC4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8002CBC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CBCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CBD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CBD4: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002CBD8: lwc1        $f4, 0x61D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x8002CBDC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002CBE0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8002CBE4: nop

    // 0x8002CBE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002CBEC: nop

    // 0x8002CBF0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002CBF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CBF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CBFC: nop

    // 0x8002CC00: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002CC04: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8002CC08: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002CC0C: jal         0x800AC0A4
    // 0x8002CC10: nop

    func_800AC0A4(rdram, ctx);
        goto after_28;
    // 0x8002CC10: nop

    after_28:
    // 0x8002CC14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC18: lwc1        $f12, 0x13C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x8002CC1C: jal         0x800C2780
    // 0x8002CC20: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_29;
    // 0x8002CC20: nop

    after_29:
    // 0x8002CC24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC28: lwc1        $f12, 0x12A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002CC2C: jal         0x800C23E8
    // 0x8002CC30: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_30;
    // 0x8002CC30: nop

    after_30:
    // 0x8002CC34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC38: lwc1        $f10, 0x1650($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1650);
    // 0x8002CC3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC40: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CC44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002CC48: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8002CC4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC50: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x8002CC54: swc1        $f6, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f6.u32l;
    // 0x8002CC58: bc1f        L_8002CE64
    if (!c1cs) {
        // 0x8002CC5C: nop

            goto L_8002CE64;
    }
    // 0x8002CC5C: nop

    // 0x8002CC60: b           L_8002CE04
    // 0x8002CC64: nop

        goto L_8002CE04;
    // 0x8002CC64: nop

    // 0x8002CC68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002CC6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002CC70: lui         $at, 0xC2A8
    ctx->r1 = S32(0XC2A8 << 16);
    // 0x8002CC74: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CC78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC7C: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002CC80: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002CC84: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002CC88: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002CC8C: addiu       $t3, $t3, 0x3090
    ctx->r11 = ADD32(ctx->r11, 0X3090);
    // 0x8002CC90: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002CC94: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8002CC98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002CC9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002CCA0: jal         0x800C3D70
    // 0x8002CCA4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800C3D70(rdram, ctx);
        goto after_31;
    // 0x8002CCA4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_31:
    // 0x8002CCA8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002CCAC: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002CCB0: jal         0x8002BB04
    // 0x8002CCB4: nop

    func_8002BB04(rdram, ctx);
        goto after_32;
    // 0x8002CCB4: nop

    after_32:
    // 0x8002CCB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CCBC: lwc1        $f10, 0x15D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002CCC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CCC4: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl);
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8002CCC8: swc1        $f8, 0x1648($at)
    MEM_W(0X1648, ctx->r1) = ctx->f8.u32l;
    // 0x8002CCCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CCD0: lwc1        $f6, 0x1648($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1648);
    // 0x8002CCD4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002CCD8: lwc1        $f5, -0x1870($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1870);
    // 0x8002CCDC: lwc1        $f4, -0x186C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X186C);
    // 0x8002CCE0: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002CCE4: nop

    // 0x8002CCE8: div.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x8002CCEC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8002CCF0: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x8002CCF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CCF8: lwc1        $f8, 0x30A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002CCFC: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002CD00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CD04: div.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002CD08: swc1        $f18, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f18.u32l;
    // 0x8002CD0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CD10: lwc1        $f4, 0x1648($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1648);
    // 0x8002CD14: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002CD18: nop

    // 0x8002CD1C: div.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8002CD20: swc1        $f10, 0x1648($at)
    MEM_W(0X1648, ctx->r1) = ctx->f10.u32l;
    // 0x8002CD24: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002CD28: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CD2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002CD30: jal         0x80099F90
    // 0x8002CD34: nop

    func_80099F90(rdram, ctx);
        goto after_33;
    // 0x8002CD34: nop

    after_33:
    // 0x8002CD38: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8002CD3C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CD40: lwc1        $f8, 0x61C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x8002CD44: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002CD48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CD4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CD50: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CD54: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002CD58: lwc1        $f18, 0x61C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x8002CD5C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002CD60: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8002CD64: nop

    // 0x8002CD68: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002CD6C: nop

    // 0x8002CD70: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002CD74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CD78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CD7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CD80: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8002CD84: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8002CD88: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002CD8C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8002CD90: nop

    // 0x8002CD94: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002CD98: nop

    // 0x8002CD9C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002CDA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CDA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CDA8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CDAC: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002CDB0: lwc1        $f8, 0x61D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x8002CDB4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002CDB8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8002CDBC: nop

    // 0x8002CDC0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002CDC4: nop

    // 0x8002CDC8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002CDCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CDD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CDD4: nop

    // 0x8002CDD8: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002CDDC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8002CDE0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002CDE4: jal         0x800AC0A4
    // 0x8002CDE8: nop

    func_800AC0A4(rdram, ctx);
        goto after_34;
    // 0x8002CDE8: nop

    after_34:
    // 0x8002CDEC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002CDF0: lh          $t8, 0x163C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X163C);
    // 0x8002CDF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CDF8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002CDFC: b           L_8002CE64
    // 0x8002CE00: sh          $t9, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r25;
        goto L_8002CE64;
    // 0x8002CE00: sh          $t9, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r25;
L_8002CE04:
    // 0x8002CE04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002CE08: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002CE0C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8002CE10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CE14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE18: lwc1        $f18, 0x1624($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002CE1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CE20: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002CE24: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002CE28: addiu       $t0, $t0, 0x3090
    ctx->r8 = ADD32(ctx->r8, 0X3090);
    // 0x8002CE2C: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002CE30: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8002CE34: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002CE38: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8002CE3C: jal         0x800C3D70
    // 0x8002CE40: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_35;
    // 0x8002CE40: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_35:
    // 0x8002CE44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002CE48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CE4C: swc1        $f16, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f16.u32l;
    // 0x8002CE50: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002CE54: lh          $t1, 0x163C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X163C);
    // 0x8002CE58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE5C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x8002CE60: sh          $t2, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r10;
L_8002CE64:
    // 0x8002CE64: b           L_8002D190
    // 0x8002CE68: nop

        goto L_8002D190;
    // 0x8002CE68: nop

L_8002CE6C:
    // 0x8002CE6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE70: lwc1        $f12, 0x13C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x8002CE74: jal         0x800C2780
    // 0x8002CE78: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_36;
    // 0x8002CE78: nop

    after_36:
    // 0x8002CE7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE80: lwc1        $f12, 0x12A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002CE84: jal         0x800C23E8
    // 0x8002CE88: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_37;
    // 0x8002CE88: nop

    after_37:
    // 0x8002CE8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE90: lwc1        $f10, 0x1648($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1648);
    // 0x8002CE94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE98: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CE9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CEA0: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002CEA4: lwc1        $f18, 0x15D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002CEA8: nop

    // 0x8002CEAC: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8002CEB0: swc1        $f4, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f4.u32l;
    // 0x8002CEB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CEB8: lwc1        $f16, 0x3088($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002CEBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CEC0: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CEC4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002CEC8: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8002CECC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002CED0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002CED4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002CED8: addiu       $a3, $a3, -0x69E8
    ctx->r7 = ADD32(ctx->r7, -0X69E8);
    // 0x8002CEDC: addiu       $a2, $a2, 0x1624
    ctx->r6 = ADD32(ctx->r6, 0X1624);
    // 0x8002CEE0: addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, 0X1618);
    // 0x8002CEE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8002CEE8: jal         0x800C3F2C
    // 0x8002CEEC: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    func_800C3F2C(rdram, ctx);
        goto after_38;
    // 0x8002CEEC: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    after_38:
    // 0x8002CEF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CEF4: lwc1        $f18, 0x30A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002CEF8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002CEFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CF00: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002CF04: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x8002CF08: nop

    // 0x8002CF0C: bc1f        L_8002CF5C
    if (!c1cs) {
        // 0x8002CF10: nop

            goto L_8002CF5C;
    }
    // 0x8002CF10: nop

    // 0x8002CF14: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002CF18: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002CF1C: jal         0x8002C270
    // 0x8002CF20: nop

    func_8002C270(rdram, ctx);
        goto after_39;
    // 0x8002CF20: nop

    after_39:
    // 0x8002CF24: jal         0x800B0E08
    // 0x8002CF28: nop

    func_800B0E08(rdram, ctx);
        goto after_40;
    // 0x8002CF28: nop

    after_40:
    // 0x8002CF2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CF30: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x8002CF34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CF38: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
    // 0x8002CF3C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002CF40: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002CF44: jal         0x80029C8C
    // 0x8002CF48: nop

    func_80029C8C(rdram, ctx);
        goto after_41;
    // 0x8002CF48: nop

    after_41:
    // 0x8002CF4C: jal         0x80029ED8
    // 0x8002CF50: nop

    func_80029ED8(rdram, ctx);
        goto after_42;
    // 0x8002CF50: nop

    after_42:
    // 0x8002CF54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CF58: sh          $zero, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = 0;
L_8002CF5C:
    // 0x8002CF5C: b           L_8002D190
    // 0x8002CF60: nop

        goto L_8002D190;
    // 0x8002CF60: nop

L_8002CF64:
    // 0x8002CF64: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002CF68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CF6C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002CF70: jal         0x80099F90
    // 0x8002CF74: nop

    func_80099F90(rdram, ctx);
        goto after_43;
    // 0x8002CF74: nop

    after_43:
    // 0x8002CF78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8002CF7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CF80: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x8002CF84: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8002CF88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CF8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CF90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CF94: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002CF98: lwc1        $f8, 0x61C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x8002CF9C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8002CFA0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8002CFA4: nop

    // 0x8002CFA8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8002CFAC: nop

    // 0x8002CFB0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002CFB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CFB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CFBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CFC0: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002CFC4: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8002CFC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002CFCC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8002CFD0: nop

    // 0x8002CFD4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002CFD8: nop

    // 0x8002CFDC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002CFE0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CFE4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CFE8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CFEC: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002CFF0: lwc1        $f16, 0x61D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x8002CFF4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002CFF8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8002CFFC: nop

    // 0x8002D000: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002D004: nop

    // 0x8002D008: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002D00C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002D010: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002D014: nop

    // 0x8002D018: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002D01C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8002D020: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002D024: jal         0x800AC0A4
    // 0x8002D028: nop

    func_800AC0A4(rdram, ctx);
        goto after_44;
    // 0x8002D028: nop

    after_44:
    // 0x8002D02C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D030: lwc1        $f12, 0x13C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x8002D034: jal         0x800C2780
    // 0x8002D038: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_45;
    // 0x8002D038: nop

    after_45:
    // 0x8002D03C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D040: lwc1        $f12, 0x12A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002D044: jal         0x800C23E8
    // 0x8002D048: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_46;
    // 0x8002D048: nop

    after_46:
    // 0x8002D04C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D050: lwc1        $f8, 0x3088($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002D054: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002D058: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002D05C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002D060: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8002D064: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x8002D068: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D06C: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8002D070: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002D074: swc1        $f16, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f16.u32l;
    // 0x8002D078: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002D07C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002D080: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8002D084: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8002D088: nop

    // 0x8002D08C: bc1f        L_8002D0A4
    if (!c1cs) {
        // 0x8002D090: nop

            goto L_8002D0A4;
    }
    // 0x8002D090: nop

    // 0x8002D094: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8002D098: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002D09C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D0A0: swc1        $f18, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f18.u32l;
L_8002D0A4:
    // 0x8002D0A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002D0A8: lh          $t7, 0x1644($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1644);
    // 0x8002D0AC: nop

    // 0x8002D0B0: beq         $t7, $zero, L_8002D100
    if (ctx->r15 == 0) {
        // 0x8002D0B4: nop

            goto L_8002D100;
    }
    // 0x8002D0B4: nop

    // 0x8002D0B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D0BC: lwc1        $f6, 0x1624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002D0C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002D0C4: lwc1        $f17, -0x1868($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1868);
    // 0x8002D0C8: lwc1        $f16, -0x1864($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1864);
    // 0x8002D0CC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8002D0D0: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8002D0D4: nop

    // 0x8002D0D8: bc1f        L_8002D100
    if (!c1cs) {
        // 0x8002D0DC: nop

            goto L_8002D100;
    }
    // 0x8002D0DC: nop

    // 0x8002D0E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002D0E4: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002D0E8: jal         0x80029C8C
    // 0x8002D0EC: nop

    func_80029C8C(rdram, ctx);
        goto after_47;
    // 0x8002D0EC: nop

    after_47:
    // 0x8002D0F0: jal         0x80029ED8
    // 0x8002D0F4: nop

    func_80029ED8(rdram, ctx);
        goto after_48;
    // 0x8002D0F4: nop

    after_48:
    // 0x8002D0F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D0FC: sh          $zero, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = 0;
L_8002D100:
    // 0x8002D100: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D104: lwc1        $f10, 0x3088($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002D108: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D10C: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002D110: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002D114: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002D118: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002D11C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002D120: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002D124: addiu       $a3, $a3, -0x69E8
    ctx->r7 = ADD32(ctx->r7, -0X69E8);
    // 0x8002D128: addiu       $a2, $a2, 0x1624
    ctx->r6 = ADD32(ctx->r6, 0X1624);
    // 0x8002D12C: addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, 0X1618);
    // 0x8002D130: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8002D134: jal         0x800C3F2C
    // 0x8002D138: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    func_800C3F2C(rdram, ctx);
        goto after_49;
    // 0x8002D138: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    after_49:
    // 0x8002D13C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D140: lwc1        $f6, 0x30A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002D144: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002D148: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002D14C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8002D150: c.eq.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d == ctx->f16.d;
    // 0x8002D154: nop

    // 0x8002D158: bc1f        L_8002D188
    if (!c1cs) {
        // 0x8002D15C: nop

            goto L_8002D188;
    }
    // 0x8002D15C: nop

    // 0x8002D160: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002D164: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002D168: jal         0x8002C270
    // 0x8002D16C: nop

    func_8002C270(rdram, ctx);
        goto after_50;
    // 0x8002D16C: nop

    after_50:
    // 0x8002D170: jal         0x800B0E08
    // 0x8002D174: nop

    func_800B0E08(rdram, ctx);
        goto after_51;
    // 0x8002D174: nop

    after_51:
    // 0x8002D178: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D17C: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x8002D180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D184: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8002D188:
    // 0x8002D188: b           L_8002D190
    // 0x8002D18C: nop

        goto L_8002D190;
    // 0x8002D18C: nop

L_8002D190:
    // 0x8002D190: lhu         $t8, 0xAE($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XAE);
    // 0x8002D194: nop

    // 0x8002D198: beq         $t8, $zero, L_8002D1C4
    if (ctx->r24 == 0) {
        // 0x8002D19C: nop

            goto L_8002D1C4;
    }
    // 0x8002D19C: nop

    // 0x8002D1A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D1A4: lwc1        $f10, 0x15D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002D1A8: nop

    // 0x8002D1AC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8002D1B0: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x8002D1B4: jal         0x800C2948
    // 0x8002D1B8: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_52;
    // 0x8002D1B8: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    after_52:
    // 0x8002D1BC: jal         0x8002D200
    // 0x8002D1C0: nop

    func_8002D200(rdram, ctx);
        goto after_53;
    // 0x8002D1C0: nop

    after_53:
L_8002D1C4:
    // 0x8002D1C4: b           L_8002D1CC
    // 0x8002D1C8: nop

        goto L_8002D1CC;
    // 0x8002D1C8: nop

L_8002D1CC:
    // 0x8002D1CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002D1D0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002D1D4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002D1D8: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002D1DC: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002D1E0: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002D1E4: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002D1E8: lwc1        $f27, 0x38($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002D1EC: lwc1        $f26, 0x3C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002D1F0: lwc1        $f29, 0x40($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002D1F4: lwc1        $f28, 0x44($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002D1F8: jr          $ra
    // 0x8002D1FC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8002D1FC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8002D200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D200: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D208: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002D20C: lw          $t6, 0x307C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X307C);
    // 0x8002D210: nop

    // 0x8002D214: beq         $t6, $zero, L_8002D390
    if (ctx->r14 == 0) {
        // 0x8002D218: nop

            goto L_8002D390;
    }
    // 0x8002D218: nop

    // 0x8002D21C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002D220: lw          $t7, 0x1B44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B44);
    // 0x8002D224: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D228: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8002D22C: sw          $t8, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r24;
    // 0x8002D230: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8002D234: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D238: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8002D23C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8002D240: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8002D244: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002D248: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D24C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002D250: addiu       $t1, $t1, -0x47F8
    ctx->r9 = ADD32(ctx->r9, -0X47F8);
    // 0x8002D254: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8002D258: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8002D25C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002D260: lw          $t4, 0x1B44($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B44);
    // 0x8002D264: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D268: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8002D26C: sw          $t5, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r13;
    // 0x8002D270: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8002D274: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002D278: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8002D27C: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x8002D280: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8002D284: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002D288: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x8002D28C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8002D290: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002D294: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x8002D298: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D29C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002D2A0: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x8002D2A4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8002D2A8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002D2AC: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x8002D2B0: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x8002D2B4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8002D2B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8002D2BC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8002D2C0: ori         $t4, $t4, 0x60
    ctx->r12 = ctx->r12 | 0X60;
    // 0x8002D2C4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8002D2C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002D2CC: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x8002D2D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D2D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D2D8: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x8002D2DC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8002D2E0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8002D2E4: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x8002D2E8: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8002D2EC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8002D2F0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002D2F4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002D2F8: addiu       $t0, $t0, -0x4820
    ctx->r8 = ADD32(ctx->r8, -0X4820);
    // 0x8002D2FC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002D300: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8002D304: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002D308: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x8002D30C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D310: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8002D314: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8002D318: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8002D31C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D320: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x8002D324: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x8002D328: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8002D32C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002D330: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D334: addiu       $t7, $t7, -0x4820
    ctx->r15 = ADD32(ctx->r15, -0X4820);
    // 0x8002D338: addiu       $t8, $t7, 0x18
    ctx->r24 = ADD32(ctx->r15, 0X18);
    // 0x8002D33C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8002D340: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002D344: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x8002D348: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D34C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002D350: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x8002D354: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8002D358: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8002D35C: lui         $t2, 0x38A
    ctx->r10 = S32(0X38A << 16);
    // 0x8002D360: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x8002D364: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8002D368: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8002D36C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8002D370: addiu       $t4, $t4, -0x4820
    ctx->r12 = ADD32(ctx->r12, -0X4820);
    // 0x8002D374: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8002D378: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8002D37C: lw          $a1, 0x307C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X307C);
    // 0x8002D380: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002D384: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002D388: jal         0x800B18C4
    // 0x8002D38C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800B18C4(rdram, ctx);
        goto after_0;
    // 0x8002D38C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_8002D390:
    // 0x8002D390: b           L_8002D398
    // 0x8002D394: nop

        goto L_8002D398;
    // 0x8002D394: nop

L_8002D398:
    // 0x8002D398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D39C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002D3A0: jr          $ra
    // 0x8002D3A4: nop

    return;
    // 0x8002D3A4: nop

;}
RECOMP_FUNC void func_8002D3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D3A8: nop

    // 0x8002D3AC: nop

;}
RECOMP_FUNC void func_8002D3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D3B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D3B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002D3BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002D3C0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002D3C4: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x8002D3C8: nop

    // 0x8002D3CC: slti        $at, $t6, 0x79
    ctx->r1 = SIGNED(ctx->r14) < 0X79 ? 1 : 0;
    // 0x8002D3D0: bne         $at, $zero, L_8002D3E0
    if (ctx->r1 != 0) {
        // 0x8002D3D4: nop

            goto L_8002D3E0;
    }
    // 0x8002D3D4: nop

    // 0x8002D3D8: b           L_8002D424
    // 0x8002D3DC: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
        goto L_8002D424;
    // 0x8002D3DC: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
L_8002D3E0:
    // 0x8002D3E0: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8002D3E4: nop

    // 0x8002D3E8: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x8002D3EC: bne         $at, $zero, L_8002D400
    if (ctx->r1 != 0) {
        // 0x8002D3F0: nop

            goto L_8002D400;
    }
    // 0x8002D3F0: nop

    // 0x8002D3F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002D3F8: b           L_8002D424
    // 0x8002D3FC: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
        goto L_8002D424;
    // 0x8002D3FC: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
L_8002D400:
    // 0x8002D400: lh          $t9, 0x3A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3A);
    // 0x8002D404: nop

    // 0x8002D408: bne         $t9, $zero, L_8002D41C
    if (ctx->r25 != 0) {
        // 0x8002D40C: nop

            goto L_8002D41C;
    }
    // 0x8002D40C: nop

    // 0x8002D410: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8002D414: b           L_8002D424
    // 0x8002D418: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
        goto L_8002D424;
    // 0x8002D418: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
L_8002D41C:
    // 0x8002D41C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8002D420: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
L_8002D424:
    // 0x8002D424: lh          $t2, 0x36($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X36);
    // 0x8002D428: nop

    // 0x8002D42C: bltz        $t2, L_8002D450
    if (SIGNED(ctx->r10) < 0) {
        // 0x8002D430: nop

            goto L_8002D450;
    }
    // 0x8002D430: nop

    // 0x8002D434: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D438: nop

    // 0x8002D43C: bne         $t2, $t3, L_8002D450
    if (ctx->r10 != ctx->r11) {
        // 0x8002D440: nop

            goto L_8002D450;
    }
    // 0x8002D440: nop

    // 0x8002D444: lh          $v0, 0x2E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D448: b           L_8002D588
    // 0x8002D44C: nop

        goto L_8002D588;
    // 0x8002D44C: nop

L_8002D450:
    // 0x8002D450: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002D454: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002D458: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x8002D45C: addiu       $a2, $a2, 0x3E00
    ctx->r6 = ADD32(ctx->r6, 0X3E00);
    // 0x8002D460: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002D464: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002D468: jal         0x800BD1FC
    // 0x8002D46C: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, 0X200);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8002D46C: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, 0X200);
    after_0:
    // 0x8002D470: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002D474: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002D478: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D47C: lw          $a1, 0x138($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X138);
    // 0x8002D480: jal         0x800BD218
    // 0x8002D484: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8002D484: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    after_1:
    // 0x8002D488: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002D48C: nop

    // 0x8002D490: lw          $t6, 0x128($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X128);
    // 0x8002D494: nop

    // 0x8002D498: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8002D49C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002D4A0: nop

    // 0x8002D4A4: beq         $t7, $zero, L_8002D4B8
    if (ctx->r15 == 0) {
        // 0x8002D4A8: nop

            goto L_8002D4B8;
    }
    // 0x8002D4A8: nop

    // 0x8002D4AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002D4B0: jal         0x800BC980
    // 0x8002D4B4: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8002D4B4: nop

    after_2:
L_8002D4B8:
    // 0x8002D4B8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8002D4BC: addiu       $t8, $t8, 0x5B0
    ctx->r24 = ADD32(ctx->r24, 0X5B0);
    // 0x8002D4C0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8002D4C4: lh          $t9, 0x2E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D4C8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002D4CC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002D4D0: lui         $t2, 0x809B
    ctx->r10 = S32(0X809B << 16);
    // 0x8002D4D4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8002D4D8: addiu       $t1, $t0, 0x1A8
    ctx->r9 = ADD32(ctx->r8, 0X1A8);
    // 0x8002D4DC: addiu       $t2, $t2, 0x3C30
    ctx->r10 = ADD32(ctx->r10, 0X3C30);
    // 0x8002D4E0: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002D4E4: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002D4E8: jal         0x800BD1FC
    // 0x8002D4EC: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8002D4EC: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x8002D4F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002D4F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D4F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8002D4FC: jal         0x800BD218
    // 0x8002D500: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x8002D500: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x8002D504: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D508: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002D50C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8002D510: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002D514: lui         $t5, 0x809B
    ctx->r13 = S32(0X809B << 16);
    // 0x8002D518: addiu       $t5, $t5, 0x1E10
    ctx->r13 = ADD32(ctx->r13, 0X1E10);
    // 0x8002D51C: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002D520: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002D524: jal         0x800BD1FC
    // 0x8002D528: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8002D528: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x8002D52C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002D530: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D534: jal         0x800BED70
    // 0x8002D538: nop

    Spi_GetHeader(rdram, ctx);
        goto after_6;
    // 0x8002D538: nop

    after_6:
    // 0x8002D53C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8002D540: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8002D544: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8002D548: jal         0x800BC6EC
    // 0x8002D54C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8002D54C: nop

    after_7:
    // 0x8002D550: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8002D554: nop

    // 0x8002D558: sw          $v0, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r2;
    // 0x8002D55C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002D560: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D564: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x8002D568: lw          $a2, 0x128($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X128);
    // 0x8002D56C: jal         0x800BF0B4
    // 0x8002D570: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_8;
    // 0x8002D570: nop

    after_8:
    // 0x8002D574: lh          $v0, 0x2E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2E);
    // 0x8002D578: b           L_8002D588
    // 0x8002D57C: nop

        goto L_8002D588;
    // 0x8002D57C: nop

    // 0x8002D580: b           L_8002D588
    // 0x8002D584: nop

        goto L_8002D588;
    // 0x8002D584: nop

L_8002D588:
    // 0x8002D588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D58C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002D590: jr          $ra
    // 0x8002D594: nop

    return;
    // 0x8002D594: nop

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
RECOMP_FUNC void func_8002D798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D798: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D79C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D7A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002D7A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002D7A8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002D7AC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002D7B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D7B4: jal         0x80096474
    // 0x8002D7B8: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x8002D7B8: nop

    after_0:
    // 0x8002D7BC: jal         0x80090754
    // 0x8002D7C0: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    func_80090754(rdram, ctx);
        goto after_1;
    // 0x8002D7C0: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    after_1:
    // 0x8002D7C4: jal         0x80090728
    // 0x8002D7C8: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    func_80090728(rdram, ctx);
        goto after_2;
    // 0x8002D7C8: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    after_2:
    // 0x8002D7CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D7D0: jal         0x8008EAA8
    // 0x8002D7D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x8002D7D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8002D7D8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002D7DC: nop

    // 0x8002D7E0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8002D7E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002D7E8: jal         0x8008ECCC
    // 0x8002D7EC: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_4;
    // 0x8002D7EC: nop

    after_4:
    // 0x8002D7F0: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x8002D7F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8002D7F8: blez        $t7, L_8002D938
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8002D7FC: nop

            goto L_8002D938;
    }
    // 0x8002D7FC: nop

L_8002D800:
    // 0x8002D800: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D804: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D808: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D80C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D810: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D814: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D818: nop

    // 0x8002D81C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D820: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D824: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D828: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D82C: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D830: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D834: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D838: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D83C: nop

    // 0x8002D840: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D844: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D848: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D84C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D850: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D854: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D858: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D85C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D860: nop

    // 0x8002D864: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D868: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D86C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D870: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D874: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D878: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D87C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D880: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D884: nop

    // 0x8002D888: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D88C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D890: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D894: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D898: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D89C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D8A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D8A4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8A8: nop

    // 0x8002D8AC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D8B0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D8B4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8B8: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D8BC: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D8C0: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D8C4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D8C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8CC: nop

    // 0x8002D8D0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D8D4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D8D8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8DC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D8E0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D8E4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D8E8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D8EC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8F0: nop

    // 0x8002D8F4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D8F8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D8FC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D900: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D904: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D908: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D90C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D910: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D914: nop

    // 0x8002D918: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D91C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D920: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D924: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x8002D928: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002D92C: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002D930: bne         $at, $zero, L_8002D800
    if (ctx->r1 != 0) {
        // 0x8002D934: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8002D800;
    }
    // 0x8002D934: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8002D938:
    // 0x8002D938: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x8002D93C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002D940: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
    // 0x8002D944: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002D948: sw          $zero, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = 0;
    // 0x8002D94C: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x8002D950: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002D954: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8002D958: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8002D95C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002D960: jal         0x8008ECAC
    // 0x8002D964: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_8008ECAC(rdram, ctx);
        goto after_5;
    // 0x8002D964: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_5:
    // 0x8002D968: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x8002D96C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002D970: sll         $t3, $t5, 3
    ctx->r11 = S32(ctx->r13 << 3);
    // 0x8002D974: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002D978: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002D97C: jal         0x8008EC8C
    // 0x8002D980: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_8008EC8C(rdram, ctx);
        goto after_6;
    // 0x8002D980: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_6:
    // 0x8002D984: lh          $s0, 0x32($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X32);
    // 0x8002D988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002D98C: beq         $s0, $at, L_8002D9B4
    if (ctx->r16 == ctx->r1) {
        // 0x8002D990: nop

            goto L_8002D9B4;
    }
    // 0x8002D990: nop

    // 0x8002D994: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002D998: beq         $s0, $at, L_8002D9CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002D99C: nop

            goto L_8002D9CC;
    }
    // 0x8002D99C: nop

    // 0x8002D9A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002D9A4: beq         $s0, $at, L_8002D9E4
    if (ctx->r16 == ctx->r1) {
        // 0x8002D9A8: nop

            goto L_8002D9E4;
    }
    // 0x8002D9A8: nop

    // 0x8002D9AC: b           L_8002D9FC
    // 0x8002D9B0: nop

        goto L_8002D9FC;
    // 0x8002D9B0: nop

L_8002D9B4:
    // 0x8002D9B4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002D9B8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002D9BC: jal         0x8008ECE4
    // 0x8002D9C0: addiu       $a0, $a0, -0x1860
    ctx->r4 = ADD32(ctx->r4, -0X1860);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8002D9C0: addiu       $a0, $a0, -0x1860
    ctx->r4 = ADD32(ctx->r4, -0X1860);
    after_7:
    // 0x8002D9C4: b           L_8002D9FC
    // 0x8002D9C8: nop

        goto L_8002D9FC;
    // 0x8002D9C8: nop

L_8002D9CC:
    // 0x8002D9CC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002D9D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002D9D4: jal         0x8008ECE4
    // 0x8002D9D8: addiu       $a0, $a0, -0x185C
    ctx->r4 = ADD32(ctx->r4, -0X185C);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x8002D9D8: addiu       $a0, $a0, -0x185C
    ctx->r4 = ADD32(ctx->r4, -0X185C);
    after_8:
    // 0x8002D9DC: b           L_8002D9FC
    // 0x8002D9E0: nop

        goto L_8002D9FC;
    // 0x8002D9E0: nop

L_8002D9E4:
    // 0x8002D9E4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002D9E8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002D9EC: jal         0x8008ECE4
    // 0x8002D9F0: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8002D9F0: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
    after_9:
    // 0x8002D9F4: b           L_8002D9FC
    // 0x8002D9F8: nop

        goto L_8002D9FC;
    // 0x8002D9F8: nop

L_8002D9FC:
    // 0x8002D9FC: jal         0x800967D8
    // 0x8002DA00: nop

    func_800967D8(rdram, ctx);
        goto after_10;
    // 0x8002DA00: nop

    after_10:
    // 0x8002DA04: b           L_8002DA0C
    // 0x8002DA08: nop

        goto L_8002DA0C;
    // 0x8002DA08: nop

L_8002DA0C:
    // 0x8002DA0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DA10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DA14: jr          $ra
    // 0x8002DA18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002DA18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002DA1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DA1C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002DA20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002DA24: lw          $t6, 0x69C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X69C8);
    // 0x8002DA28: nop

    // 0x8002DA2C: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8002DA30: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8002DA34:
    // 0x8002DA34: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8002DA38: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002DA3C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002DA40: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8002DA44: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8002DA48: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8002DA4C: nop

    // 0x8002DA50: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002DA54: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8002DA58: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8002DA5C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8002DA60: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8002DA64: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8002DA68: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8002DA6C: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8002DA70: nop

    // 0x8002DA74: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002DA78: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8002DA7C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8002DA80: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002DA84: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002DA88: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8002DA8C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8002DA90: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8002DA94: nop

    // 0x8002DA98: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002DA9C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8002DAA0: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8002DAA4: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8002DAA8: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8002DAAC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8002DAB0: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8002DAB4: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8002DAB8: nop

    // 0x8002DABC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002DAC0: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8002DAC4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8002DAC8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002DACC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002DAD0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8002DAD4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8002DAD8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8002DADC: nop

    // 0x8002DAE0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002DAE4: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8002DAE8: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8002DAEC: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8002DAF0: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8002DAF4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8002DAF8: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8002DAFC: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB00: nop

    // 0x8002DB04: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002DB08: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8002DB0C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB10: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002DB14: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002DB18: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8002DB1C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8002DB20: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB24: nop

    // 0x8002DB28: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002DB2C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8002DB30: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB34: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8002DB38: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8002DB3C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8002DB40: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8002DB44: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB48: nop

    // 0x8002DB4C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002DB50: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8002DB54: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB58: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002DB5C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002DB60: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8002DB64: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8002DB68: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB6C: nop

    // 0x8002DB70: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002DB74: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8002DB78: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB7C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8002DB80: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8002DB84: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8002DB88: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8002DB8C: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8002DB90: nop

    // 0x8002DB94: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002DB98: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8002DB9C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8002DBA0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002DBA4: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002DBA8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8002DBAC: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8002DBB0: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8002DBB4: nop

    // 0x8002DBB8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002DBBC: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8002DBC0: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8002DBC4: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8002DBC8: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8002DBCC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8002DBD0: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8002DBD4: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8002DBD8: nop

    // 0x8002DBDC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002DBE0: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8002DBE4: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x8002DBE8: nop

    // 0x8002DBEC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002DBF0: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8002DBF4: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002DBF8: slti        $at, $t0, 0x41
    ctx->r1 = SIGNED(ctx->r8) < 0X41 ? 1 : 0;
    // 0x8002DBFC: bne         $at, $zero, L_8002DA34
    if (ctx->r1 != 0) {
        // 0x8002DC00: sh          $t9, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r25;
            goto L_8002DA34;
    }
    // 0x8002DC00: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x8002DC04: b           L_8002DC0C
    // 0x8002DC08: nop

        goto L_8002DC0C;
    // 0x8002DC08: nop

L_8002DC0C:
    // 0x8002DC0C: jr          $ra
    // 0x8002DC10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002DC10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8002DC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002DC18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002DC1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002DC20: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002DC24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002DC28: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002DC2C: lh          $t6, -0x69F0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X69F0);
    // 0x8002DC30: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8002DC34: beq         $t6, $at, L_8002DC54
    if (ctx->r14 == ctx->r1) {
        // 0x8002DC38: nop

            goto L_8002DC54;
    }
    // 0x8002DC38: nop

    // 0x8002DC3C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8002DC40: lhu         $t7, -0x6504($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6504);
    // 0x8002DC44: nop

    // 0x8002DC48: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8002DC4C: beq         $t8, $zero, L_8002DC5C
    if (ctx->r24 == 0) {
        // 0x8002DC50: nop

            goto L_8002DC5C;
    }
    // 0x8002DC50: nop

L_8002DC54:
    // 0x8002DC54: b           L_8002E3FC
    // 0x8002DC58: nop

        goto L_8002E3FC;
    // 0x8002DC58: nop

L_8002DC5C:
    // 0x8002DC5C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8002DC60: lh          $t9, -0x69F0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X69F0);
    // 0x8002DC64: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8002DC68: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002DC6C: lw          $t0, -0x73D0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73D0);
    // 0x8002DC70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DC74: swc1        $f6, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f6.u32l;
    // 0x8002DC78: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8002DC7C: lh          $t1, -0x69F0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X69F0);
    // 0x8002DC80: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002DC84: addiu       $t2, $t1, 0x72
    ctx->r10 = ADD32(ctx->r9, 0X72);
    // 0x8002DC88: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8002DC8C: lw          $t3, 0x16C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X16C0);
    // 0x8002DC90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DC94: swc1        $f10, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f10.u32l;
    // 0x8002DC98: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8002DC9C: lh          $t4, -0x69F0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X69F0);
    // 0x8002DCA0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8002DCA4: addiu       $t5, $t4, 0x63
    ctx->r13 = ADD32(ctx->r12, 0X63);
    // 0x8002DCA8: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8002DCAC: lw          $t6, -0x4BBC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BBC);
    // 0x8002DCB0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002DCB4: swc1        $f18, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f18.u32l;
    // 0x8002DCB8: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8002DCBC: lh          $t7, -0x69F0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X69F0);
    // 0x8002DCC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002DCC4: addiu       $t8, $t7, 0x6F
    ctx->r24 = ADD32(ctx->r15, 0X6F);
    // 0x8002DCC8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002DCCC: lw          $t9, 0x2648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2648);
    // 0x8002DCD0: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DCD4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002DCD8: swc1        $f20, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f20.u32l;
    // 0x8002DCDC: lw          $t0, 0x2644($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2644);
    // 0x8002DCE0: nop

    // 0x8002DCE4: swc1        $f20, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f20.u32l;
    // 0x8002DCE8: jal         0x800C1754
    // 0x8002DCEC: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002DCEC: nop

    after_0:
    // 0x8002DCF0: jal         0x800A7160
    // 0x8002DCF4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002DCF4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8002DCF8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002DCFC: addiu       $t1, $t1, 0x7340
    ctx->r9 = ADD32(ctx->r9, 0X7340);
    // 0x8002DD00: lwc1        $f12, 0xBF0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XBF0);
    // 0x8002DD04: jal         0x800C2780
    // 0x8002DD08: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002DD08: nop

    after_2:
    // 0x8002DD0C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002DD10: addiu       $t2, $t2, 0x7340
    ctx->r10 = ADD32(ctx->r10, 0X7340);
    // 0x8002DD14: lwc1        $f12, 0xBEC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XBEC);
    // 0x8002DD18: jal         0x800C25B8
    // 0x8002DD1C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002DD1C: nop

    after_3:
    // 0x8002DD20: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002DD24: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x8002DD28: lwc1        $f12, 0xBE8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XBE8);
    // 0x8002DD2C: jal         0x800C23E8
    // 0x8002DD30: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002DD30: nop

    after_4:
    // 0x8002DD34: jal         0x800A72BC
    // 0x8002DD38: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002DD38: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_5:
    // 0x8002DD3C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002DD40: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8002DD44: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002DD48: lhu         $t6, -0x6A10($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6A10);
    // 0x8002DD4C: lh          $t5, 0x40($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X40);
    // 0x8002DD50: nop

    // 0x8002DD54: beq         $t5, $t6, L_8002DD64
    if (ctx->r13 == ctx->r14) {
        // 0x8002DD58: nop

            goto L_8002DD64;
    }
    // 0x8002DD58: nop

    // 0x8002DD5C: jal         0x8002D598
    // 0x8002DD60: nop

    func_8002D598(rdram, ctx);
        goto after_6;
    // 0x8002DD60: nop

    after_6:
L_8002DD64:
    // 0x8002DD64: jal         0x800C1850
    // 0x8002DD68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_7;
    // 0x8002DD68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8002DD6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002DD70: lw          $a0, 0x16C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C0);
    // 0x8002DD74: jal         0x8009A14C
    // 0x8002DD78: nop

    func_8009A14C(rdram, ctx);
        goto after_8;
    // 0x8002DD78: nop

    after_8:
    // 0x8002DD7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002DD80: lw          $a0, 0x16C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C0);
    // 0x8002DD84: jal         0x800997D8
    // 0x8002DD88: nop

    func_800997D8(rdram, ctx);
        goto after_9;
    // 0x8002DD88: nop

    after_9:
    // 0x8002DD8C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8002DD90: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8002DD94: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8002DD98: nop

    // 0x8002DD9C: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x8002DDA0: beq         $t9, $zero, L_8002DE44
    if (ctx->r25 == 0) {
        // 0x8002DDA4: nop

            goto L_8002DE44;
    }
    // 0x8002DDA4: nop

    // 0x8002DDA8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002DDAC: lw          $t0, 0x640($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X640);
    // 0x8002DDB0: nop

    // 0x8002DDB4: bne         $t0, $zero, L_8002DDC4
    if (ctx->r8 != 0) {
        // 0x8002DDB8: nop

            goto L_8002DDC4;
    }
    // 0x8002DDB8: nop

    // 0x8002DDBC: b           L_8002DDDC
    // 0x8002DDC0: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
        goto L_8002DDDC;
    // 0x8002DDC0: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
L_8002DDC4:
    // 0x8002DDC4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002DDC8: lw          $t1, 0x640($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X640);
    // 0x8002DDCC: nop

    // 0x8002DDD0: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8002DDD4: nop

    // 0x8002DDD8: sh          $t2, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r10;
L_8002DDDC:
    // 0x8002DDDC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8002DDE0: lw          $t4, -0x4BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BB8);
    // 0x8002DDE4: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x8002DDE8: nop

    // 0x8002DDEC: beq         $t3, $t4, L_8002DE1C
    if (ctx->r11 == ctx->r12) {
        // 0x8002DDF0: nop

            goto L_8002DE1C;
    }
    // 0x8002DDF0: nop

    // 0x8002DDF4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8002DDF8: lw          $t5, -0x4BBC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BBC);
    // 0x8002DDFC: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x8002DE00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002DE04: lw          $a1, 0x128($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X128);
    // 0x8002DE08: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002DE0C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8002DE10: sw          $t6, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r14;
    // 0x8002DE14: jal         0x8002D798
    // 0x8002DE18: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    func_8002D798(rdram, ctx);
        goto after_10;
    // 0x8002DE18: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_10:
L_8002DE1C:
    // 0x8002DE1C: jal         0x800C1850
    // 0x8002DE20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_11;
    // 0x8002DE20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8002DE24: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8002DE28: lw          $a0, -0x4BBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BBC);
    // 0x8002DE2C: jal         0x8009A14C
    // 0x8002DE30: nop

    func_8009A14C(rdram, ctx);
        goto after_12;
    // 0x8002DE30: nop

    after_12:
    // 0x8002DE34: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8002DE38: lw          $a0, -0x4BBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BBC);
    // 0x8002DE3C: jal         0x800997D8
    // 0x8002DE40: nop

    func_800997D8(rdram, ctx);
        goto after_13;
    // 0x8002DE40: nop

    after_13:
L_8002DE44:
    // 0x8002DE44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DE48: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DE4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DE50: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002DE54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DE58: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002DE5C: swc1        $f10, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f10.u32l;
    // 0x8002DE60: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002DE64: lh          $s0, 0x25A4($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25A4);
    // 0x8002DE68: nop

    // 0x8002DE6C: beq         $s0, $zero, L_8002DEA0
    if (ctx->r16 == 0) {
        // 0x8002DE70: nop

            goto L_8002DEA0;
    }
    // 0x8002DE70: nop

    // 0x8002DE74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DE78: beq         $s0, $at, L_8002DF4C
    if (ctx->r16 == ctx->r1) {
        // 0x8002DE7C: nop

            goto L_8002DF4C;
    }
    // 0x8002DE7C: nop

    // 0x8002DE80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002DE84: beq         $s0, $at, L_8002DFF8
    if (ctx->r16 == ctx->r1) {
        // 0x8002DE88: nop

            goto L_8002DFF8;
    }
    // 0x8002DE88: nop

    // 0x8002DE8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002DE90: beq         $s0, $at, L_8002DFF8
    if (ctx->r16 == ctx->r1) {
        // 0x8002DE94: nop

            goto L_8002DFF8;
    }
    // 0x8002DE94: nop

    // 0x8002DE98: b           L_8002E0A4
    // 0x8002DE9C: nop

        goto L_8002E0A4;
    // 0x8002DE9C: nop

L_8002DEA0:
    // 0x8002DEA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DEA4: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DEA8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DEAC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002DEB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DEB4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002DEB8: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002DEBC: nop

    // 0x8002DEC0: bc1f        L_8002DF44
    if (!c1cs) {
        // 0x8002DEC4: nop

            goto L_8002DF44;
    }
    // 0x8002DEC4: nop

L_8002DEC8:
    // 0x8002DEC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002DECC: lw          $t7, 0x2644($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2644);
    // 0x8002DED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DED4: lw          $a0, 0x138($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X138);
    // 0x8002DED8: jal         0x80030438
    // 0x8002DEDC: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_14;
    // 0x8002DEDC: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_14:
    // 0x8002DEE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DEE4: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DEE8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DEEC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002DEF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002DEF4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002DEF8: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8002DEFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF00: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002DF04: swc1        $f18, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f18.u32l;
    // 0x8002DF08: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002DF0C: lh          $t8, 0x25C4($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X25C4);
    // 0x8002DF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF14: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002DF18: sh          $t9, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r25;
    // 0x8002DF1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF20: lwc1        $f4, 0x25B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DF24: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DF28: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002DF2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002DF30: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002DF34: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002DF38: nop

    // 0x8002DF3C: bc1t        L_8002DEC8
    if (c1cs) {
        // 0x8002DF40: nop

            goto L_8002DEC8;
    }
    // 0x8002DF40: nop

L_8002DF44:
    // 0x8002DF44: b           L_8002E0A4
    // 0x8002DF48: nop

        goto L_8002E0A4;
    // 0x8002DF48: nop

L_8002DF4C:
    // 0x8002DF4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF50: lwc1        $f10, 0x25B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DF54: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DF58: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002DF5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002DF60: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002DF64: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002DF68: nop

    // 0x8002DF6C: bc1f        L_8002DFF0
    if (!c1cs) {
        // 0x8002DF70: nop

            goto L_8002DFF0;
    }
    // 0x8002DF70: nop

L_8002DF74:
    // 0x8002DF74: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002DF78: lw          $t0, 0x2644($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2644);
    // 0x8002DF7C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002DF80: lw          $a0, 0x138($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X138);
    // 0x8002DF84: jal         0x80030438
    // 0x8002DF88: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_15;
    // 0x8002DF88: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_15:
    // 0x8002DF8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF90: lwc1        $f4, 0x25B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DF94: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DF98: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002DF9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002DFA0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002DFA4: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002DFA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFAC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002DFB0: swc1        $f16, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f16.u32l;
    // 0x8002DFB4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002DFB8: lh          $t1, 0x25C4($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X25C4);
    // 0x8002DFBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFC0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8002DFC4: sh          $t2, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r10;
    // 0x8002DFC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFCC: lwc1        $f18, 0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DFD0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DFD4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002DFD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002DFDC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002DFE0: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002DFE4: nop

    // 0x8002DFE8: bc1t        L_8002DF74
    if (c1cs) {
        // 0x8002DFEC: nop

            goto L_8002DF74;
    }
    // 0x8002DFEC: nop

L_8002DFF0:
    // 0x8002DFF0: b           L_8002E0A4
    // 0x8002DFF4: nop

        goto L_8002E0A4;
    // 0x8002DFF4: nop

L_8002DFF8:
    // 0x8002DFF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFFC: lwc1        $f8, 0x25B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E000: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E004: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E008: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E00C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E010: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E014: nop

    // 0x8002E018: bc1f        L_8002E09C
    if (!c1cs) {
        // 0x8002E01C: nop

            goto L_8002E09C;
    }
    // 0x8002E01C: nop

L_8002E020:
    // 0x8002E020: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002E024: lw          $t3, 0x2644($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2644);
    // 0x8002E028: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E02C: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x8002E030: jal         0x80030438
    // 0x8002E034: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_16;
    // 0x8002E034: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_16:
    // 0x8002E038: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E03C: lwc1        $f18, 0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E040: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E044: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E048: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E04C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E050: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002E054: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E058: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002E05C: swc1        $f10, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f10.u32l;
    // 0x8002E060: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002E064: lh          $t4, 0x25C4($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X25C4);
    // 0x8002E068: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E06C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002E070: sh          $t5, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r13;
    // 0x8002E074: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E078: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E07C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E080: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E088: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E08C: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002E090: nop

    // 0x8002E094: bc1t        L_8002E020
    if (c1cs) {
        // 0x8002E098: nop

            goto L_8002E020;
    }
    // 0x8002E098: nop

L_8002E09C:
    // 0x8002E09C: b           L_8002E0A4
    // 0x8002E0A0: nop

        goto L_8002E0A4;
    // 0x8002E0A0: nop

L_8002E0A4:
    // 0x8002E0A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E0A8: lh          $t6, 0x25C4($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X25C4);
    // 0x8002E0AC: nop

    // 0x8002E0B0: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8002E0B4: bne         $at, $zero, L_8002E0F0
    if (ctx->r1 != 0) {
        // 0x8002E0B8: nop

            goto L_8002E0F0;
    }
    // 0x8002E0B8: nop

    // 0x8002E0BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E0C0: sh          $zero, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = 0;
    // 0x8002E0C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E0C8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8002E0CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E0D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002E0D4: lh          $a1, 0x25A4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25A4);
    // 0x8002E0D8: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E0DC: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x8002E0E0: jal         0x8002D3B0
    // 0x8002E0E4: nop

    func_8002D3B0(rdram, ctx);
        goto after_17;
    // 0x8002E0E4: nop

    after_17:
    // 0x8002E0E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E0EC: sh          $v0, 0x25A4($at)
    MEM_H(0X25A4, ctx->r1) = ctx->r2;
L_8002E0F0:
    // 0x8002E0F0: jal         0x800C1850
    // 0x8002E0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_18;
    // 0x8002E0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x8002E0F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E0FC: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E100: jal         0x8009A14C
    // 0x8002E104: nop

    func_8009A14C(rdram, ctx);
        goto after_19;
    // 0x8002E104: nop

    after_19:
    // 0x8002E108: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E10C: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E110: jal         0x800997D8
    // 0x8002E114: nop

    func_800997D8(rdram, ctx);
        goto after_20;
    // 0x8002E114: nop

    after_20:
    // 0x8002E118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E11C: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E120: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E124: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002E128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E12C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002E130: swc1        $f10, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f10.u32l;
    // 0x8002E134: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002E138: lh          $s0, 0x25AC($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25AC);
    // 0x8002E13C: nop

    // 0x8002E140: beq         $s0, $zero, L_8002E174
    if (ctx->r16 == 0) {
        // 0x8002E144: nop

            goto L_8002E174;
    }
    // 0x8002E144: nop

    // 0x8002E148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E14C: beq         $s0, $at, L_8002E220
    if (ctx->r16 == ctx->r1) {
        // 0x8002E150: nop

            goto L_8002E220;
    }
    // 0x8002E150: nop

    // 0x8002E154: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002E158: beq         $s0, $at, L_8002E2CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002E15C: nop

            goto L_8002E2CC;
    }
    // 0x8002E15C: nop

    // 0x8002E160: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E164: beq         $s0, $at, L_8002E2CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002E168: nop

            goto L_8002E2CC;
    }
    // 0x8002E168: nop

    // 0x8002E16C: b           L_8002E378
    // 0x8002E170: nop

        goto L_8002E378;
    // 0x8002E170: nop

L_8002E174:
    // 0x8002E174: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E178: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E17C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E180: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E188: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E18C: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002E190: nop

    // 0x8002E194: bc1f        L_8002E218
    if (!c1cs) {
        // 0x8002E198: nop

            goto L_8002E218;
    }
    // 0x8002E198: nop

L_8002E19C:
    // 0x8002E19C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002E1A0: lw          $t8, 0x2648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2648);
    // 0x8002E1A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E1A8: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x8002E1AC: jal         0x80030438
    // 0x8002E1B0: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_21;
    // 0x8002E1B0: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_21:
    // 0x8002E1B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1B8: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E1BC: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E1C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E1C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E1C8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E1CC: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8002E1D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1D4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002E1D8: swc1        $f18, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f18.u32l;
    // 0x8002E1DC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002E1E0: lh          $t9, 0x25CC($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X25CC);
    // 0x8002E1E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1E8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8002E1EC: sh          $t0, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r8;
    // 0x8002E1F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1F4: lwc1        $f4, 0x25BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E1F8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E1FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E200: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E204: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E208: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002E20C: nop

    // 0x8002E210: bc1t        L_8002E19C
    if (c1cs) {
        // 0x8002E214: nop

            goto L_8002E19C;
    }
    // 0x8002E214: nop

L_8002E218:
    // 0x8002E218: b           L_8002E378
    // 0x8002E21C: nop

        goto L_8002E378;
    // 0x8002E21C: nop

L_8002E220:
    // 0x8002E220: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E224: lwc1        $f10, 0x25BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E228: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E22C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E230: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E234: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E238: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002E23C: nop

    // 0x8002E240: bc1f        L_8002E2C4
    if (!c1cs) {
        // 0x8002E244: nop

            goto L_8002E2C4;
    }
    // 0x8002E244: nop

L_8002E248:
    // 0x8002E248: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002E24C: lw          $t1, 0x2648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2648);
    // 0x8002E250: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002E254: lw          $a0, 0x138($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X138);
    // 0x8002E258: jal         0x80030438
    // 0x8002E25C: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_22;
    // 0x8002E25C: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_22:
    // 0x8002E260: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E264: lwc1        $f4, 0x25BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E268: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E26C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E270: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E274: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E278: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002E27C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E280: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002E284: swc1        $f16, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f16.u32l;
    // 0x8002E288: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002E28C: lh          $t2, 0x25CC($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X25CC);
    // 0x8002E290: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E294: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002E298: sh          $t3, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r11;
    // 0x8002E29C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E2A0: lwc1        $f18, 0x25BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E2A4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E2A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E2AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E2B0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E2B4: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002E2B8: nop

    // 0x8002E2BC: bc1t        L_8002E248
    if (c1cs) {
        // 0x8002E2C0: nop

            goto L_8002E248;
    }
    // 0x8002E2C0: nop

L_8002E2C4:
    // 0x8002E2C4: b           L_8002E378
    // 0x8002E2C8: nop

        goto L_8002E378;
    // 0x8002E2C8: nop

L_8002E2CC:
    // 0x8002E2CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E2D0: lwc1        $f8, 0x25BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E2D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E2D8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E2DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E2E0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E2E4: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E2E8: nop

    // 0x8002E2EC: bc1f        L_8002E370
    if (!c1cs) {
        // 0x8002E2F0: nop

            goto L_8002E370;
    }
    // 0x8002E2F0: nop

L_8002E2F4:
    // 0x8002E2F4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002E2F8: lw          $t4, 0x2648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2648);
    // 0x8002E2FC: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E300: lw          $a0, 0x138($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X138);
    // 0x8002E304: jal         0x80030438
    // 0x8002E308: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_23;
    // 0x8002E308: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_23:
    // 0x8002E30C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E310: lwc1        $f18, 0x25BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E314: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E318: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E31C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E320: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E324: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002E328: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E32C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002E330: swc1        $f10, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f10.u32l;
    // 0x8002E334: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002E338: lh          $t5, 0x25CC($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X25CC);
    // 0x8002E33C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E340: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002E344: sh          $t6, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r14;
    // 0x8002E348: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E34C: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E350: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E354: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E358: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E35C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E360: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002E364: nop

    // 0x8002E368: bc1t        L_8002E2F4
    if (c1cs) {
        // 0x8002E36C: nop

            goto L_8002E2F4;
    }
    // 0x8002E36C: nop

L_8002E370:
    // 0x8002E370: b           L_8002E378
    // 0x8002E374: nop

        goto L_8002E378;
    // 0x8002E374: nop

L_8002E378:
    // 0x8002E378: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E37C: lh          $t7, 0x25CC($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X25CC);
    // 0x8002E380: nop

    // 0x8002E384: slti        $at, $t7, 0x1F
    ctx->r1 = SIGNED(ctx->r15) < 0X1F ? 1 : 0;
    // 0x8002E388: bne         $at, $zero, L_8002E3C4
    if (ctx->r1 != 0) {
        // 0x8002E38C: nop

            goto L_8002E3C4;
    }
    // 0x8002E38C: nop

    // 0x8002E390: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E394: sh          $zero, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = 0;
    // 0x8002E398: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002E39C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8002E3A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E3A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002E3A8: lh          $a1, 0x25AC($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25AC);
    // 0x8002E3AC: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002E3B0: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    // 0x8002E3B4: jal         0x8002D3B0
    // 0x8002E3B8: nop

    func_8002D3B0(rdram, ctx);
        goto after_24;
    // 0x8002E3B8: nop

    after_24:
    // 0x8002E3BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E3C0: sh          $v0, 0x25AC($at)
    MEM_H(0X25AC, ctx->r1) = ctx->r2;
L_8002E3C4:
    // 0x8002E3C4: jal         0x800C1850
    // 0x8002E3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_25;
    // 0x8002E3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x8002E3CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E3D0: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002E3D4: jal         0x8009A14C
    // 0x8002E3D8: nop

    func_8009A14C(rdram, ctx);
        goto after_26;
    // 0x8002E3D8: nop

    after_26:
    // 0x8002E3DC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E3E0: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002E3E4: jal         0x800997D8
    // 0x8002E3E8: nop

    func_800997D8(rdram, ctx);
        goto after_27;
    // 0x8002E3E8: nop

    after_27:
    // 0x8002E3EC: jal         0x800C1A28
    // 0x8002E3F0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_28;
    // 0x8002E3F0: nop

    after_28:
    // 0x8002E3F4: b           L_8002E3FC
    // 0x8002E3F8: nop

        goto L_8002E3FC;
    // 0x8002E3F8: nop

L_8002E3FC:
    // 0x8002E3FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002E400: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002E404: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002E408: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002E40C: jr          $ra
    // 0x8002E410: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002E410: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002E414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E414: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002E418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E41C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E420: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002E424: lhu         $t6, -0x6504($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6504);
    // 0x8002E428: nop

    // 0x8002E42C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8002E430: bne         $t7, $zero, L_8002E440
    if (ctx->r15 != 0) {
        // 0x8002E434: nop

            goto L_8002E440;
    }
    // 0x8002E434: nop

    // 0x8002E438: b           L_8002EAE0
    // 0x8002E43C: nop

        goto L_8002EAE0;
    // 0x8002E43C: nop

L_8002E440:
    // 0x8002E440: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8002E444: lw          $t8, -0x73D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73D0);
    // 0x8002E448: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E44C: nop

    // 0x8002E450: swc1        $f4, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f4.u32l;
    // 0x8002E454: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8002E458: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002E45C: lw          $t9, 0x16C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X16C0);
    // 0x8002E460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E464: nop

    // 0x8002E468: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8002E46C: lui         $at, 0x42DE
    ctx->r1 = S32(0X42DE << 16);
    // 0x8002E470: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002E474: lw          $t0, 0x2648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2648);
    // 0x8002E478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E47C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002E480: swc1        $f8, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f8.u32l;
    // 0x8002E484: lw          $t1, 0x2648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2648);
    // 0x8002E488: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002E48C: lw          $t2, 0x2644($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2644);
    // 0x8002E490: lwc1        $f10, 0xD0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x8002E494: nop

    // 0x8002E498: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
    // 0x8002E49C: jal         0x800C1754
    // 0x8002E4A0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002E4A0: nop

    after_0:
    // 0x8002E4A4: jal         0x800A7160
    // 0x8002E4A8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002E4A8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x8002E4AC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002E4B0: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x8002E4B4: lwc1        $f12, 0x1010($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X1010);
    // 0x8002E4B8: jal         0x800C2780
    // 0x8002E4BC: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002E4BC: nop

    after_2:
    // 0x8002E4C0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002E4C4: addiu       $t4, $t4, 0x7340
    ctx->r12 = ADD32(ctx->r12, 0X7340);
    // 0x8002E4C8: lwc1        $f12, 0x100C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X100C);
    // 0x8002E4CC: jal         0x800C25B8
    // 0x8002E4D0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002E4D0: nop

    after_3:
    // 0x8002E4D4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002E4D8: addiu       $t5, $t5, 0x7340
    ctx->r13 = ADD32(ctx->r13, 0X7340);
    // 0x8002E4DC: lwc1        $f12, 0x1008($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X1008);
    // 0x8002E4E0: jal         0x800C23E8
    // 0x8002E4E4: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002E4E4: nop

    after_4:
    // 0x8002E4E8: jal         0x800A72BC
    // 0x8002E4EC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002E4EC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_5:
    // 0x8002E4F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E4F4: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E4F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E4FC: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002E500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E504: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8002E508: swc1        $f4, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f4.u32l;
    // 0x8002E50C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002E510: lh          $s0, 0x25A4($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25A4);
    // 0x8002E514: nop

    // 0x8002E518: beq         $s0, $zero, L_8002E54C
    if (ctx->r16 == 0) {
        // 0x8002E51C: nop

            goto L_8002E54C;
    }
    // 0x8002E51C: nop

    // 0x8002E520: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E524: beq         $s0, $at, L_8002E5F8
    if (ctx->r16 == ctx->r1) {
        // 0x8002E528: nop

            goto L_8002E5F8;
    }
    // 0x8002E528: nop

    // 0x8002E52C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002E530: beq         $s0, $at, L_8002E6A4
    if (ctx->r16 == ctx->r1) {
        // 0x8002E534: nop

            goto L_8002E6A4;
    }
    // 0x8002E534: nop

    // 0x8002E538: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E53C: beq         $s0, $at, L_8002E6A4
    if (ctx->r16 == ctx->r1) {
        // 0x8002E540: nop

            goto L_8002E6A4;
    }
    // 0x8002E540: nop

    // 0x8002E544: b           L_8002E750
    // 0x8002E548: nop

        goto L_8002E750;
    // 0x8002E548: nop

L_8002E54C:
    // 0x8002E54C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E550: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E554: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E558: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E55C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E560: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E564: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002E568: nop

    // 0x8002E56C: bc1f        L_8002E5F0
    if (!c1cs) {
        // 0x8002E570: nop

            goto L_8002E5F0;
    }
    // 0x8002E570: nop

L_8002E574:
    // 0x8002E574: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E578: lw          $t6, 0x2644($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2644);
    // 0x8002E57C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E580: lw          $a0, 0x138($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X138);
    // 0x8002E584: jal         0x80030438
    // 0x8002E588: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_6;
    // 0x8002E588: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_6:
    // 0x8002E58C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E590: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E594: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E598: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E59C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E5A0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E5A4: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x8002E5A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5AC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002E5B0: swc1        $f8, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f8.u32l;
    // 0x8002E5B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E5B8: lh          $t7, 0x25C4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X25C4);
    // 0x8002E5BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5C0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002E5C4: sh          $t8, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r24;
    // 0x8002E5C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5CC: lwc1        $f10, 0x25B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E5D0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E5D4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E5D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E5DC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E5E0: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002E5E4: nop

    // 0x8002E5E8: bc1t        L_8002E574
    if (c1cs) {
        // 0x8002E5EC: nop

            goto L_8002E574;
    }
    // 0x8002E5EC: nop

L_8002E5F0:
    // 0x8002E5F0: b           L_8002E750
    // 0x8002E5F4: nop

        goto L_8002E750;
    // 0x8002E5F4: nop

L_8002E5F8:
    // 0x8002E5F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E5FC: lwc1        $f4, 0x25B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E600: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E604: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E608: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E60C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E610: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002E614: nop

    // 0x8002E618: bc1f        L_8002E69C
    if (!c1cs) {
        // 0x8002E61C: nop

            goto L_8002E69C;
    }
    // 0x8002E61C: nop

L_8002E620:
    // 0x8002E620: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002E624: lw          $t9, 0x2644($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2644);
    // 0x8002E628: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002E62C: lw          $a0, 0x138($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X138);
    // 0x8002E630: jal         0x80030438
    // 0x8002E634: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_7;
    // 0x8002E634: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_7:
    // 0x8002E638: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E63C: lwc1        $f10, 0x25B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E640: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E644: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E648: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E64C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E650: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x8002E654: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E658: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8002E65C: swc1        $f6, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f6.u32l;
    // 0x8002E660: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002E664: lh          $t0, 0x25C4($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X25C4);
    // 0x8002E668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E66C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8002E670: sh          $t1, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r9;
    // 0x8002E674: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E678: lwc1        $f8, 0x25B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E67C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E680: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E684: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E688: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E68C: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E690: nop

    // 0x8002E694: bc1t        L_8002E620
    if (c1cs) {
        // 0x8002E698: nop

            goto L_8002E620;
    }
    // 0x8002E698: nop

L_8002E69C:
    // 0x8002E69C: b           L_8002E750
    // 0x8002E6A0: nop

        goto L_8002E750;
    // 0x8002E6A0: nop

L_8002E6A4:
    // 0x8002E6A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E6A8: lwc1        $f18, 0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E6AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E6B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E6B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E6B8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E6BC: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002E6C0: nop

    // 0x8002E6C4: bc1f        L_8002E748
    if (!c1cs) {
        // 0x8002E6C8: nop

            goto L_8002E748;
    }
    // 0x8002E6C8: nop

L_8002E6CC:
    // 0x8002E6CC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002E6D0: lw          $t2, 0x2644($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2644);
    // 0x8002E6D4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E6D8: lw          $a0, 0x138($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X138);
    // 0x8002E6DC: jal         0x80030438
    // 0x8002E6E0: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_8;
    // 0x8002E6E0: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_8:
    // 0x8002E6E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E6E8: lwc1        $f8, 0x25B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E6EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E6F0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E6F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E6F8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E6FC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8002E700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E704: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002E708: swc1        $f4, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f4.u32l;
    // 0x8002E70C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002E710: lh          $t3, 0x25C4($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X25C4);
    // 0x8002E714: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E718: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002E71C: sh          $t4, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r12;
    // 0x8002E720: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E724: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E728: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E72C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E730: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E734: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E738: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002E73C: nop

    // 0x8002E740: bc1t        L_8002E6CC
    if (c1cs) {
        // 0x8002E744: nop

            goto L_8002E6CC;
    }
    // 0x8002E744: nop

L_8002E748:
    // 0x8002E748: b           L_8002E750
    // 0x8002E74C: nop

        goto L_8002E750;
    // 0x8002E74C: nop

L_8002E750:
    // 0x8002E750: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002E754: lh          $t5, 0x25C4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X25C4);
    // 0x8002E758: nop

    // 0x8002E75C: slti        $at, $t5, 0x1F
    ctx->r1 = SIGNED(ctx->r13) < 0X1F ? 1 : 0;
    // 0x8002E760: bne         $at, $zero, L_8002E79C
    if (ctx->r1 != 0) {
        // 0x8002E764: nop

            goto L_8002E79C;
    }
    // 0x8002E764: nop

    // 0x8002E768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E76C: sh          $zero, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = 0;
    // 0x8002E770: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E774: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8002E778: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E77C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002E780: lh          $a1, 0x25A4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25A4);
    // 0x8002E784: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E788: lh          $a2, 0x0($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X0);
    // 0x8002E78C: jal         0x8002D3B0
    // 0x8002E790: nop

    func_8002D3B0(rdram, ctx);
        goto after_9;
    // 0x8002E790: nop

    after_9:
    // 0x8002E794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E798: sh          $v0, 0x25A4($at)
    MEM_H(0X25A4, ctx->r1) = ctx->r2;
L_8002E79C:
    // 0x8002E79C: jal         0x800C1850
    // 0x8002E7A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_10;
    // 0x8002E7A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8002E7A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E7A8: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E7AC: jal         0x8009A14C
    // 0x8002E7B0: nop

    func_8009A14C(rdram, ctx);
        goto after_11;
    // 0x8002E7B0: nop

    after_11:
    // 0x8002E7B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E7B8: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E7BC: jal         0x800997D8
    // 0x8002E7C0: nop

    func_800997D8(rdram, ctx);
        goto after_12;
    // 0x8002E7C0: nop

    after_12:
    // 0x8002E7C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E7C8: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E7CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E7D0: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002E7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E7D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8002E7DC: swc1        $f4, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f4.u32l;
    // 0x8002E7E0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002E7E4: lh          $s0, 0x25AC($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25AC);
    // 0x8002E7E8: nop

    // 0x8002E7EC: beq         $s0, $zero, L_8002E820
    if (ctx->r16 == 0) {
        // 0x8002E7F0: nop

            goto L_8002E820;
    }
    // 0x8002E7F0: nop

    // 0x8002E7F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E7F8: beq         $s0, $at, L_8002E8CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002E7FC: nop

            goto L_8002E8CC;
    }
    // 0x8002E7FC: nop

    // 0x8002E800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002E804: beq         $s0, $at, L_8002E978
    if (ctx->r16 == ctx->r1) {
        // 0x8002E808: nop

            goto L_8002E978;
    }
    // 0x8002E808: nop

    // 0x8002E80C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E810: beq         $s0, $at, L_8002E978
    if (ctx->r16 == ctx->r1) {
        // 0x8002E814: nop

            goto L_8002E978;
    }
    // 0x8002E814: nop

    // 0x8002E818: b           L_8002EA24
    // 0x8002E81C: nop

        goto L_8002EA24;
    // 0x8002E81C: nop

L_8002E820:
    // 0x8002E820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E824: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E828: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E82C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E830: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E834: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E838: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002E83C: nop

    // 0x8002E840: bc1f        L_8002E8C4
    if (!c1cs) {
        // 0x8002E844: nop

            goto L_8002E8C4;
    }
    // 0x8002E844: nop

L_8002E848:
    // 0x8002E848: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E84C: lw          $t7, 0x2648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2648);
    // 0x8002E850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E854: lw          $a0, 0x138($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X138);
    // 0x8002E858: jal         0x80030438
    // 0x8002E85C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_13;
    // 0x8002E85C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_13:
    // 0x8002E860: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E864: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E868: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E86C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E870: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E874: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E878: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x8002E87C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E880: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002E884: swc1        $f8, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f8.u32l;
    // 0x8002E888: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002E88C: lh          $t8, 0x25CC($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X25CC);
    // 0x8002E890: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E894: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002E898: sh          $t9, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r25;
    // 0x8002E89C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E8A0: lwc1        $f10, 0x25BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E8A4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E8A8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E8AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E8B0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E8B4: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002E8B8: nop

    // 0x8002E8BC: bc1t        L_8002E848
    if (c1cs) {
        // 0x8002E8C0: nop

            goto L_8002E848;
    }
    // 0x8002E8C0: nop

L_8002E8C4:
    // 0x8002E8C4: b           L_8002EA24
    // 0x8002E8C8: nop

        goto L_8002EA24;
    // 0x8002E8C8: nop

L_8002E8CC:
    // 0x8002E8CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E8D0: lwc1        $f4, 0x25BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E8D4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E8D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E8DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E8E0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E8E4: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002E8E8: nop

    // 0x8002E8EC: bc1f        L_8002E970
    if (!c1cs) {
        // 0x8002E8F0: nop

            goto L_8002E970;
    }
    // 0x8002E8F0: nop

L_8002E8F4:
    // 0x8002E8F4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002E8F8: lw          $t0, 0x2648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2648);
    // 0x8002E8FC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002E900: lw          $a0, 0x138($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X138);
    // 0x8002E904: jal         0x80030438
    // 0x8002E908: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_14;
    // 0x8002E908: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_14:
    // 0x8002E90C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E910: lwc1        $f10, 0x25BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E914: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E918: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E91C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E920: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E924: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x8002E928: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E92C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8002E930: swc1        $f6, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f6.u32l;
    // 0x8002E934: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002E938: lh          $t1, 0x25CC($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X25CC);
    // 0x8002E93C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E940: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8002E944: sh          $t2, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r10;
    // 0x8002E948: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E94C: lwc1        $f8, 0x25BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E950: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E954: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E958: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E95C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E960: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E964: nop

    // 0x8002E968: bc1t        L_8002E8F4
    if (c1cs) {
        // 0x8002E96C: nop

            goto L_8002E8F4;
    }
    // 0x8002E96C: nop

L_8002E970:
    // 0x8002E970: b           L_8002EA24
    // 0x8002E974: nop

        goto L_8002EA24;
    // 0x8002E974: nop

L_8002E978:
    // 0x8002E978: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E97C: lwc1        $f18, 0x25BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E980: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E984: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E988: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E98C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E990: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002E994: nop

    // 0x8002E998: bc1f        L_8002EA1C
    if (!c1cs) {
        // 0x8002E99C: nop

            goto L_8002EA1C;
    }
    // 0x8002E99C: nop

L_8002E9A0:
    // 0x8002E9A0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002E9A4: lw          $t3, 0x2648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2648);
    // 0x8002E9A8: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E9AC: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x8002E9B0: jal         0x80030438
    // 0x8002E9B4: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_15;
    // 0x8002E9B4: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_15:
    // 0x8002E9B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9BC: lwc1        $f8, 0x25BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E9C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E9C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E9C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E9CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E9D0: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8002E9D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9D8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002E9DC: swc1        $f4, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f4.u32l;
    // 0x8002E9E0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002E9E4: lh          $t4, 0x25CC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X25CC);
    // 0x8002E9E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9EC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002E9F0: sh          $t5, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r13;
    // 0x8002E9F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E9F8: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E9FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002EA00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002EA04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EA08: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EA0C: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8002EA10: nop

    // 0x8002EA14: bc1t        L_8002E9A0
    if (c1cs) {
        // 0x8002EA18: nop

            goto L_8002E9A0;
    }
    // 0x8002EA18: nop

L_8002EA1C:
    // 0x8002EA1C: b           L_8002EA24
    // 0x8002EA20: nop

        goto L_8002EA24;
    // 0x8002EA20: nop

L_8002EA24:
    // 0x8002EA24: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002EA28: lh          $t6, 0x25CC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X25CC);
    // 0x8002EA2C: nop

    // 0x8002EA30: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8002EA34: bne         $at, $zero, L_8002EAA8
    if (ctx->r1 != 0) {
        // 0x8002EA38: nop

            goto L_8002EAA8;
    }
    // 0x8002EA38: nop

    // 0x8002EA3C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002EA40: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8002EA44: nop

    // 0x8002EA48: bne         $t7, $zero, L_8002EA5C
    if (ctx->r15 != 0) {
        // 0x8002EA4C: nop

            goto L_8002EA5C;
    }
    // 0x8002EA4C: nop

    // 0x8002EA50: addiu       $t8, $zero, 0x3E7
    ctx->r24 = ADD32(0, 0X3E7);
    // 0x8002EA54: b           L_8002EA7C
    // 0x8002EA58: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
        goto L_8002EA7C;
    // 0x8002EA58: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
L_8002EA5C:
    // 0x8002EA5C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002EA60: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8002EA64: nop

    // 0x8002EA68: lw          $t0, 0xB4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XB4);
    // 0x8002EA6C: nop

    // 0x8002EA70: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8002EA74: nop

    // 0x8002EA78: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
L_8002EA7C:
    // 0x8002EA7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EA80: sh          $zero, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = 0;
    // 0x8002EA84: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EA88: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002EA8C: lh          $a1, 0x25AC($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25AC);
    // 0x8002EA90: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002EA94: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    // 0x8002EA98: jal         0x8002D3B0
    // 0x8002EA9C: nop

    func_8002D3B0(rdram, ctx);
        goto after_16;
    // 0x8002EA9C: nop

    after_16:
    // 0x8002EAA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EAA4: sh          $v0, 0x25AC($at)
    MEM_H(0X25AC, ctx->r1) = ctx->r2;
L_8002EAA8:
    // 0x8002EAA8: jal         0x800C1850
    // 0x8002EAAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_17;
    // 0x8002EAAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8002EAB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EAB4: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002EAB8: jal         0x8009A14C
    // 0x8002EABC: nop

    func_8009A14C(rdram, ctx);
        goto after_18;
    // 0x8002EABC: nop

    after_18:
    // 0x8002EAC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EAC4: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002EAC8: jal         0x800997D8
    // 0x8002EACC: nop

    func_800997D8(rdram, ctx);
        goto after_19;
    // 0x8002EACC: nop

    after_19:
    // 0x8002EAD0: jal         0x800C1A28
    // 0x8002EAD4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_20;
    // 0x8002EAD4: nop

    after_20:
    // 0x8002EAD8: b           L_8002EAE0
    // 0x8002EADC: nop

        goto L_8002EAE0;
    // 0x8002EADC: nop

L_8002EAE0:
    // 0x8002EAE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EAE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002EAE8: jr          $ra
    // 0x8002EAEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002EAEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002EAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EAF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002EAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EAF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002EAFC: nop

    // 0x8002EB00: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8002EB04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EB08: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EB0C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002EB10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EB14: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EB18: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8002EB1C: nop

    // 0x8002EB20: bc1f        L_8002EBD4
    if (!c1cs) {
        // 0x8002EB24: nop

            goto L_8002EBD4;
    }
    // 0x8002EB24: nop

    // 0x8002EB28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002EB2C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002EB30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EB34: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002EB38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002EB3C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002EB40: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8002EB44: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EB48: lwc1        $f8, -0x7820($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EB4C: nop

    // 0x8002EB50: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002EB54: add.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f18.d = ctx->f10.d + ctx->f6.d;
    // 0x8002EB58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EB5C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8002EB60: swc1        $f16, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f16.u32l;
    // 0x8002EB64: lui         $at, 0xC030
    ctx->r1 = S32(0XC030 << 16);
    // 0x8002EB68: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002EB6C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002EB70: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x8002EB74: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8002EB78: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8002EB7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EB80: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EB84: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002EB88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EB8C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8002EB90: c.le.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d <= ctx->f16.d;
    // 0x8002EB94: nop

    // 0x8002EB98: bc1f        L_8002EBCC
    if (!c1cs) {
        // 0x8002EB9C: nop

            goto L_8002EBCC;
    }
    // 0x8002EB9C: nop

    // 0x8002EBA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002EBA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EBA8: swc1        $f4, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f4.u32l;
    // 0x8002EBAC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8002EBB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002EBB4: jal         0x8002A22C
    // 0x8002EBB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A22C(rdram, ctx);
        goto after_0;
    // 0x8002EBB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8002EBBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002EBC0: sw          $v0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r2;
    // 0x8002EBC4: jal         0x80029ED8
    // 0x8002EBC8: nop

    func_80029ED8(rdram, ctx);
        goto after_1;
    // 0x8002EBC8: nop

    after_1:
L_8002EBCC:
    // 0x8002EBCC: b           L_8002EC6C
    // 0x8002EBD0: nop

        goto L_8002EC6C;
    // 0x8002EBD0: nop

L_8002EBD4:
    // 0x8002EBD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EBD8: lwc1        $f10, -0x7820($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EBDC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8002EBE0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002EBE4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8002EBE8: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8002EBEC: nop

    // 0x8002EBF0: bc1f        L_8002EC6C
    if (!c1cs) {
        // 0x8002EBF4: nop

            goto L_8002EC6C;
    }
    // 0x8002EBF4: nop

    // 0x8002EBF8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002EBFC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002EC00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002EC04: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002EC08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002EC0C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8002EC10: mul.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8002EC14: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EC18: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EC1C: nop

    // 0x8002EC20: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EC24: sub.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f18.d - ctx->f10.d;
    // 0x8002EC28: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8002EC2C: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = -ctx->f16.fl;
    // 0x8002EC30: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8002EC34: swc1        $f16, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f16.u32l;
    // 0x8002EC38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EC3C: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EC40: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002EC44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EC48: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EC4C: c.le.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d <= ctx->f10.d;
    // 0x8002EC50: nop

    // 0x8002EC54: bc1f        L_8002EC6C
    if (!c1cs) {
        // 0x8002EC58: nop

            goto L_8002EC6C;
    }
    // 0x8002EC58: nop

    // 0x8002EC5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EC60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EC64: swc1        $f8, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f8.u32l;
    // 0x8002EC68: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_8002EC6C:
    // 0x8002EC6C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002EC70: b           L_8002EC80
    // 0x8002EC74: nop

        goto L_8002EC80;
    // 0x8002EC74: nop

    // 0x8002EC78: b           L_8002EC80
    // 0x8002EC7C: nop

        goto L_8002EC80;
    // 0x8002EC7C: nop

L_8002EC80:
    // 0x8002EC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EC84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002EC88: jr          $ra
    // 0x8002EC8C: nop

    return;
    // 0x8002EC8C: nop

;}
RECOMP_FUNC void func_8002EC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EC90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002EC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EC98: jal         0x800C1754
    // 0x8002EC9C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002EC9C: nop

    after_0:
    // 0x8002ECA0: jal         0x800A7160
    // 0x8002ECA4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002ECA4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x8002ECA8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002ECAC: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x8002ECB0: lwc1        $f12, 0xEB0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XEB0);
    // 0x8002ECB4: jal         0x800C2780
    // 0x8002ECB8: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002ECB8: nop

    after_2:
    // 0x8002ECBC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002ECC0: addiu       $t7, $t7, 0x7340
    ctx->r15 = ADD32(ctx->r15, 0X7340);
    // 0x8002ECC4: lwc1        $f12, 0xEAC($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XEAC);
    // 0x8002ECC8: jal         0x800C25B8
    // 0x8002ECCC: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002ECCC: nop

    after_3:
    // 0x8002ECD0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8002ECD4: addiu       $t8, $t8, 0x7340
    ctx->r24 = ADD32(ctx->r24, 0X7340);
    // 0x8002ECD8: lwc1        $f12, 0xEA8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XEA8);
    // 0x8002ECDC: jal         0x800C23E8
    // 0x8002ECE0: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002ECE0: nop

    after_4:
    // 0x8002ECE4: jal         0x800A72BC
    // 0x8002ECE8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002ECE8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x8002ECEC: jal         0x800C1A28
    // 0x8002ECF0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8002ECF0: nop

    after_6:
    // 0x8002ECF4: jal         0x8002EAF0
    // 0x8002ECF8: nop

    func_8002EAF0(rdram, ctx);
        goto after_7;
    // 0x8002ECF8: nop

    after_7:
    // 0x8002ECFC: b           L_8002ED04
    // 0x8002ED00: nop

        goto L_8002ED04;
    // 0x8002ED00: nop

L_8002ED04:
    // 0x8002ED04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002ED08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002ED0C: jr          $ra
    // 0x8002ED10: nop

    return;
    // 0x8002ED10: nop

;}
RECOMP_FUNC void func_8002ED14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ED14: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002ED18: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002ED1C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002ED20: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002ED24: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8002ED28: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002ED2C: lh          $t6, -0x6558($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6558);
    // 0x8002ED30: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8002ED34: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002ED38: lw          $t7, -0x73D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73D0);
    // 0x8002ED3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002ED40: swc1        $f6, 0x230($t7)
    MEM_W(0X230, ctx->r15) = ctx->f6.u32l;
    // 0x8002ED44: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8002ED48: lh          $t8, -0x6558($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6558);
    // 0x8002ED4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002ED50: addiu       $t9, $t8, -0x50
    ctx->r25 = ADD32(ctx->r24, -0X50);
    // 0x8002ED54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8002ED58: lw          $t0, 0x1688($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1688);
    // 0x8002ED5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002ED60: swc1        $f10, 0x230($t0)
    MEM_W(0X230, ctx->r8) = ctx->f10.u32l;
    // 0x8002ED64: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8002ED68: lh          $t1, -0x6558($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6558);
    // 0x8002ED6C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002ED70: addiu       $t2, $t1, -0x4A
    ctx->r10 = ADD32(ctx->r9, -0X4A);
    // 0x8002ED74: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8002ED78: lw          $t3, 0x24D8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24D8);
    // 0x8002ED7C: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002ED80: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002ED84: swc1        $f20, 0x230($t3)
    MEM_W(0X230, ctx->r11) = ctx->f20.u32l;
    // 0x8002ED88: lw          $t4, 0x24D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X24D8);
    // 0x8002ED8C: nop

    // 0x8002ED90: swc1        $f20, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f20.u32l;
    // 0x8002ED94: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8002ED98: lh          $t5, -0x6558($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6558);
    // 0x8002ED9C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002EDA0: addiu       $t6, $t5, -0x53
    ctx->r14 = ADD32(ctx->r13, -0X53);
    // 0x8002EDA4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002EDA8: lw          $t7, 0x29BC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X29BC);
    // 0x8002EDAC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EDB0: swc1        $f4, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f4.u32l;
    // 0x8002EDB4: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8002EDB8: lh          $t8, -0x6558($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6558);
    // 0x8002EDBC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002EDC0: addiu       $t9, $t8, -0x5F
    ctx->r25 = ADD32(ctx->r24, -0X5F);
    // 0x8002EDC4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002EDC8: lw          $t0, 0x49C4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X49C4);
    // 0x8002EDCC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002EDD0: swc1        $f8, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f8.u32l;
    // 0x8002EDD4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002EDD8: lh          $t1, 0x2518($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2518);
    // 0x8002EDDC: nop

    // 0x8002EDE0: slti        $at, $t1, 0x28
    ctx->r1 = SIGNED(ctx->r9) < 0X28 ? 1 : 0;
    // 0x8002EDE4: beq         $at, $zero, L_8002EE00
    if (ctx->r1 == 0) {
        // 0x8002EDE8: nop

            goto L_8002EE00;
    }
    // 0x8002EDE8: nop

    // 0x8002EDEC: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8002EDF0: lh          $t2, -0x6558($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6558);
    // 0x8002EDF4: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8002EDF8: bne         $t2, $at, L_8002EE08
    if (ctx->r10 != ctx->r1) {
        // 0x8002EDFC: nop

            goto L_8002EE08;
    }
    // 0x8002EDFC: nop

L_8002EE00:
    // 0x8002EE00: b           L_8002F5AC
    // 0x8002EE04: nop

        goto L_8002F5AC;
    // 0x8002EE04: nop

L_8002EE08:
    // 0x8002EE08: jal         0x800C1754
    // 0x8002EE0C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002EE0C: nop

    after_0:
    // 0x8002EE10: jal         0x800A7160
    // 0x8002EE14: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002EE14: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x8002EE18: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002EE1C: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x8002EE20: lwc1        $f12, 0xD50($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XD50);
    // 0x8002EE24: jal         0x800C2780
    // 0x8002EE28: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002EE28: nop

    after_2:
    // 0x8002EE2C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002EE30: addiu       $t4, $t4, 0x7340
    ctx->r12 = ADD32(ctx->r12, 0X7340);
    // 0x8002EE34: lwc1        $f12, 0xD4C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XD4C);
    // 0x8002EE38: jal         0x800C25B8
    // 0x8002EE3C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002EE3C: nop

    after_3:
    // 0x8002EE40: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002EE44: addiu       $t5, $t5, 0x7340
    ctx->r13 = ADD32(ctx->r13, 0X7340);
    // 0x8002EE48: lwc1        $f12, 0xD48($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XD48);
    // 0x8002EE4C: jal         0x800C23E8
    // 0x8002EE50: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002EE50: nop

    after_4:
    // 0x8002EE54: jal         0x800A72BC
    // 0x8002EE58: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002EE58: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_5:
    // 0x8002EE5C: jal         0x800C1850
    // 0x8002EE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_6;
    // 0x8002EE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8002EE64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EE68: lw          $a0, 0x1688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1688);
    // 0x8002EE6C: jal         0x8009A14C
    // 0x8002EE70: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    func_8009A14C(rdram, ctx);
        goto after_7;
    // 0x8002EE70: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    after_7:
    // 0x8002EE74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EE78: lw          $a0, 0x1688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1688);
    // 0x8002EE7C: jal         0x800997D8
    // 0x8002EE80: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    func_800997D8(rdram, ctx);
        goto after_8;
    // 0x8002EE80: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    after_8:
    // 0x8002EE84: jal         0x800C1850
    // 0x8002EE88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_9;
    // 0x8002EE88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8002EE8C: jal         0x8002EAF0
    // 0x8002EE90: nop

    func_8002EAF0(rdram, ctx);
        goto after_10;
    // 0x8002EE90: nop

    after_10:
    // 0x8002EE94: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8002EE98: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8002EE9C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002EEA0: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002EEA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002EEA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002EEAC: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8002EEB0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002EEB4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8002EEB8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002EEBC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EEC0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x8002EEC4: lh          $t6, -0x6558($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6558);
    // 0x8002EEC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002EECC: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8002EED0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8002EED4: lui         $at, 0xC054
    ctx->r1 = S32(0XC054 << 16);
    // 0x8002EED8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002EEDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002EEE0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8002EEE4: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8002EEE8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002EEEC: lw          $a2, 0x7218($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7218);
    // 0x8002EEF0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002EEF4: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x8002EEF8: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x8002EEFC: jal         0x800C2304
    // 0x8002EF00: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_11;
    // 0x8002EF00: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    after_11:
    // 0x8002EF04: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8002EF08: sh          $t7, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r15;
    // 0x8002EF0C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EF10: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EF14: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002EF18: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EF1C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002EF20: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8002EF24: nop

    // 0x8002EF28: bc1f        L_8002EF40
    if (!c1cs) {
        // 0x8002EF2C: nop

            goto L_8002EF40;
    }
    // 0x8002EF2C: nop

    // 0x8002EF30: lhu         $t8, 0x46($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X46);
    // 0x8002EF34: nop

    // 0x8002EF38: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002EF3C: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
L_8002EF40:
    // 0x8002EF40: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x8002EF44: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8002EF48: blez        $t0, L_8002F13C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002EF4C: nop

            goto L_8002F13C;
    }
    // 0x8002EF4C: nop

L_8002EF50:
    // 0x8002EF50: lh          $t1, 0x62($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X62);
    // 0x8002EF54: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8002EF58: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002EF5C: lbu         $t2, -0x6500($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6500);
    // 0x8002EF60: nop

    // 0x8002EF64: beq         $t2, $zero, L_8002F108
    if (ctx->r10 == 0) {
        // 0x8002EF68: sh          $t2, 0x5E($sp)
        MEM_H(0X5E, ctx->r29) = ctx->r10;
            goto L_8002F108;
    }
    // 0x8002EF68: sh          $t2, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r10;
    // 0x8002EF6C: lh          $t3, 0x62($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X62);
    // 0x8002EF70: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002EF74: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8002EF78: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002EF7C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002EF80: lw          $t5, 0x1694($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1694);
    // 0x8002EF84: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002EF88: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8002EF8C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8002EF90: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8002EF94: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
L_8002EF98:
    // 0x8002EF98: lh          $t7, 0x60($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X60);
    // 0x8002EF9C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002EFA0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002EFA4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002EFA8: lh          $t9, 0x2590($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2590);
    // 0x8002EFAC: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x8002EFB0: nop

    // 0x8002EFB4: bne         $t9, $t0, L_8002EFE8
    if (ctx->r25 != ctx->r8) {
        // 0x8002EFB8: nop

            goto L_8002EFE8;
    }
    // 0x8002EFB8: nop

    // 0x8002EFBC: lh          $t1, 0x60($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X60);
    // 0x8002EFC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002EFC4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8002EFC8: lw          $t3, 0x7B54($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B54);
    // 0x8002EFCC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002EFD0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8002EFD4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8002EFD8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002EFDC: sw          $t4, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r12;
    // 0x8002EFE0: b           L_8002F008
    // 0x8002EFE4: nop

        goto L_8002F008;
    // 0x8002EFE4: nop

L_8002EFE8:
    // 0x8002EFE8: lh          $t6, 0x60($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X60);
    // 0x8002EFEC: nop

    // 0x8002EFF0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002EFF4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002EFF8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002EFFC: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8002F000: bne         $at, $zero, L_8002EF98
    if (ctx->r1 != 0) {
        // 0x8002F004: sh          $t7, 0x60($sp)
        MEM_H(0X60, ctx->r29) = ctx->r15;
            goto L_8002EF98;
    }
    // 0x8002F004: sh          $t7, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r15;
L_8002F008:
    // 0x8002F008: lh          $t0, 0x60($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X60);
    // 0x8002F00C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002F010: bne         $t0, $at, L_8002F0FC
    if (ctx->r8 != ctx->r1) {
        // 0x8002F014: nop

            goto L_8002F0FC;
    }
    // 0x8002F014: nop

    // 0x8002F018: jal         0x8002A028
    // 0x8002F01C: nop

    func_8002A028(rdram, ctx);
        goto after_12;
    // 0x8002F01C: nop

    after_12:
    // 0x8002F020: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002F024: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002F028: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8002F02C: lh          $t2, 0x5E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5E);
    // 0x8002F030: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x8002F034: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F038: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002F03C: sh          $s0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r16;
    // 0x8002F040: sh          $t2, 0x2590($at)
    MEM_H(0X2590, ctx->r1) = ctx->r10;
    // 0x8002F044: lh          $t4, 0x5C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X5C);
    // 0x8002F048: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002F04C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8002F050: lw          $t6, 0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B54);
    // 0x8002F054: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8002F058: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8002F05C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8002F060: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8002F064: sw          $t7, 0x128($t8)
    MEM_W(0X128, ctx->r24) = ctx->r15;
    // 0x8002F068: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8002F06C: addiu       $t9, $t9, 0x5B0
    ctx->r25 = ADD32(ctx->r25, 0X5B0);
    // 0x8002F070: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8002F074: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x8002F078: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8002F07C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002F080: lbu         $t1, -0x46F1($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X46F1);
    // 0x8002F084: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F088: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002F08C: lui         $t3, 0x809B
    ctx->r11 = S32(0X809B << 16);
    // 0x8002F090: addiu       $t3, $t3, 0x3C30
    ctx->r11 = ADD32(ctx->r11, 0X3C30);
    // 0x8002F094: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002F098: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002F09C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8002F0A0: jal         0x800BD1FC
    // 0x8002F0A4: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_13;
    // 0x8002F0A4: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_13:
    // 0x8002F0A8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8002F0AC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F0B0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002F0B4: jal         0x800BD218
    // 0x8002F0B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_14;
    // 0x8002F0B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_14:
    // 0x8002F0BC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8002F0C0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F0C4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002F0C8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002F0CC: lui         $t6, 0x809B
    ctx->r14 = S32(0X809B << 16);
    // 0x8002F0D0: addiu       $t6, $t6, 0x1E10
    ctx->r14 = ADD32(ctx->r14, 0X1E10);
    // 0x8002F0D4: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002F0D8: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002F0DC: jal         0x800BD1FC
    // 0x8002F0E0: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_15;
    // 0x8002F0E0: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    after_15:
    // 0x8002F0E4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8002F0E8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8002F0EC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F0F0: lw          $a2, 0x128($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X128);
    // 0x8002F0F4: jal         0x800BF0B4
    // 0x8002F0F8: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    Spi_DecompressAsset(rdram, ctx);
        goto after_16;
    // 0x8002F0F8: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    after_16:
L_8002F0FC:
    // 0x8002F0FC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F100: jal         0x800997D8
    // 0x8002F104: nop

    func_800997D8(rdram, ctx);
        goto after_17;
    // 0x8002F104: nop

    after_17:
L_8002F108:
    // 0x8002F108: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002F10C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002F110: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002F114: jal         0x800C2304
    // 0x8002F118: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_18;
    // 0x8002F118: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_18:
    // 0x8002F11C: lh          $t8, 0x62($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X62);
    // 0x8002F120: lhu         $t2, 0x46($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X46);
    // 0x8002F124: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002F128: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x8002F12C: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002F130: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002F134: bne         $at, $zero, L_8002EF50
    if (ctx->r1 != 0) {
        // 0x8002F138: sh          $t9, 0x62($sp)
        MEM_H(0X62, ctx->r29) = ctx->r25;
            goto L_8002EF50;
    }
    // 0x8002F138: sh          $t9, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r25;
L_8002F13C:
    // 0x8002F13C: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x8002F140: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8002F144: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F148: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F14C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002F150: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002F154: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002F158: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8002F15C: nop

    // 0x8002F160: bc1f        L_8002F1A0
    if (!c1cs) {
        // 0x8002F164: nop

            goto L_8002F1A0;
    }
    // 0x8002F164: nop

    // 0x8002F168: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002F16C: lh          $t3, 0x2588($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2588);
    // 0x8002F170: nop

    // 0x8002F174: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8002F178: bne         $t4, $zero, L_8002F1A0
    if (ctx->r12 != 0) {
        // 0x8002F17C: nop

            goto L_8002F1A0;
    }
    // 0x8002F17C: nop

    // 0x8002F180: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F184: lh          $t5, 0x2588($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2588);
    // 0x8002F188: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F18C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8002F190: sh          $t6, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r14;
    // 0x8002F194: addiu       $t7, $zero, 0x141
    ctx->r15 = ADD32(0, 0X141);
    // 0x8002F198: b           L_8002F210
    // 0x8002F19C: sh          $t7, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r15;
        goto L_8002F210;
    // 0x8002F19C: sh          $t7, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r15;
L_8002F1A0:
    // 0x8002F1A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F1A4: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F1A8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002F1AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002F1B0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002F1B4: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8002F1B8: nop

    // 0x8002F1BC: bc1f        L_8002F210
    if (!c1cs) {
        // 0x8002F1C0: nop

            goto L_8002F210;
    }
    // 0x8002F1C0: nop

    // 0x8002F1C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002F1C8: lh          $t8, 0x2588($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2588);
    // 0x8002F1CC: nop

    // 0x8002F1D0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8002F1D4: beq         $t9, $zero, L_8002F210
    if (ctx->r25 == 0) {
        // 0x8002F1D8: nop

            goto L_8002F210;
    }
    // 0x8002F1D8: nop

    // 0x8002F1DC: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x8002F1E0: bne         $t0, $zero, L_8002F210
    if (ctx->r8 != 0) {
        // 0x8002F1E4: nop

            goto L_8002F210;
    }
    // 0x8002F1E4: nop

    // 0x8002F1E8: andi        $t1, $t8, 0x2
    ctx->r9 = ctx->r24 & 0X2;
    // 0x8002F1EC: bne         $t1, $zero, L_8002F210
    if (ctx->r9 != 0) {
        // 0x8002F1F0: nop

            goto L_8002F210;
    }
    // 0x8002F1F0: nop

    // 0x8002F1F4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002F1F8: lh          $t2, 0x2588($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2588);
    // 0x8002F1FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F200: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8002F204: sh          $t3, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r11;
    // 0x8002F208: addiu       $t4, $zero, 0x142
    ctx->r12 = ADD32(0, 0X142);
    // 0x8002F20C: sh          $t4, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r12;
L_8002F210:
    // 0x8002F210: lh          $t5, 0x60($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X60);
    // 0x8002F214: nop

    // 0x8002F218: beq         $t5, $zero, L_8002F270
    if (ctx->r13 == 0) {
        // 0x8002F21C: nop

            goto L_8002F270;
    }
    // 0x8002F21C: nop

    // 0x8002F220: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8002F224: lh          $t7, -0x6558($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6558);
    // 0x8002F228: lh          $a2, 0x60($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X60);
    // 0x8002F22C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8002F230: addiu       $t9, $t7, -0x4A
    ctx->r25 = ADD32(ctx->r15, -0X4A);
    // 0x8002F234: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8002F238: or          $t6, $a2, $at
    ctx->r14 = ctx->r6 | ctx->r1;
    // 0x8002F23C: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x8002F240: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002F248: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F24C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002F250: lw          $a1, 0x24F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24F8);
    // 0x8002F254: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F258: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8002F25C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8002F260: addiu       $a3, $zero, 0x41
    ctx->r7 = ADD32(0, 0X41);
    // 0x8002F264: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8002F268: jal         0x800B1F0C
    // 0x8002F26C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_19;
    // 0x8002F26C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
L_8002F270:
    // 0x8002F270: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002F274: lh          $t0, 0x2588($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X2588);
    // 0x8002F278: nop

    // 0x8002F27C: andi        $t8, $t0, 0x1
    ctx->r24 = ctx->r8 & 0X1;
    // 0x8002F280: beq         $t8, $zero, L_8002F2E8
    if (ctx->r24 == 0) {
        // 0x8002F284: nop

            goto L_8002F2E8;
    }
    // 0x8002F284: nop

    // 0x8002F288: jal         0x800C1850
    // 0x8002F28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_20;
    // 0x8002F28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x8002F290: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F294: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F298: jal         0x8009A14C
    // 0x8002F29C: nop

    func_8009A14C(rdram, ctx);
        goto after_21;
    // 0x8002F29C: nop

    after_21:
    // 0x8002F2A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F2A4: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F2A8: jal         0x800997D8
    // 0x8002F2AC: nop

    func_800997D8(rdram, ctx);
        goto after_22;
    // 0x8002F2AC: nop

    after_22:
    // 0x8002F2B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F2B4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002F2B8: lw          $a1, 0x24F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24F8);
    // 0x8002F2BC: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F2C0: jal         0x800B26E0
    // 0x8002F2C4: nop

    func_800B26E0(rdram, ctx);
        goto after_23;
    // 0x8002F2C4: nop

    after_23:
    // 0x8002F2C8: bgez        $v0, L_8002F2E8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002F2CC: nop

            goto L_8002F2E8;
    }
    // 0x8002F2CC: nop

    // 0x8002F2D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002F2D4: lh          $t1, 0x2588($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2588);
    // 0x8002F2D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002F2DC: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8002F2E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F2E4: sh          $t2, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r10;
L_8002F2E8:
    // 0x8002F2E8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002F2EC: lw          $t3, 0x24D8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24D8);
    // 0x8002F2F0: nop

    // 0x8002F2F4: addiu       $t4, $t3, 0x160
    ctx->r12 = ADD32(ctx->r11, 0X160);
    // 0x8002F2F8: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8002F2FC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F300: lw          $t5, 0x24F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X24F8);
    // 0x8002F304: nop

    // 0x8002F308: addiu       $t6, $t5, 0x40
    ctx->r14 = ADD32(ctx->r13, 0X40);
    // 0x8002F30C: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8002F310: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F314: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F318: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002F31C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002F320: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002F324: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8002F328: nop

    // 0x8002F32C: bc1f        L_8002F36C
    if (!c1cs) {
        // 0x8002F330: nop

            goto L_8002F36C;
    }
    // 0x8002F330: nop

    // 0x8002F334: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002F338: lh          $t7, 0x2588($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2588);
    // 0x8002F33C: nop

    // 0x8002F340: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x8002F344: bne         $t9, $zero, L_8002F36C
    if (ctx->r25 != 0) {
        // 0x8002F348: nop

            goto L_8002F36C;
    }
    // 0x8002F348: nop

    // 0x8002F34C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002F350: lh          $t0, 0x2588($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X2588);
    // 0x8002F354: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F358: ori         $t8, $t0, 0x8
    ctx->r24 = ctx->r8 | 0X8;
    // 0x8002F35C: sh          $t8, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r24;
    // 0x8002F360: addiu       $t1, $zero, 0x13F
    ctx->r9 = ADD32(0, 0X13F);
    // 0x8002F364: b           L_8002F3DC
    // 0x8002F368: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
        goto L_8002F3DC;
    // 0x8002F368: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
L_8002F36C:
    // 0x8002F36C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F370: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F374: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002F378: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002F37C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002F380: c.eq.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d == ctx->f16.d;
    // 0x8002F384: nop

    // 0x8002F388: bc1f        L_8002F3DC
    if (!c1cs) {
        // 0x8002F38C: nop

            goto L_8002F3DC;
    }
    // 0x8002F38C: nop

    // 0x8002F390: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002F394: lh          $t2, 0x2588($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2588);
    // 0x8002F398: nop

    // 0x8002F39C: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8002F3A0: beq         $t3, $zero, L_8002F3DC
    if (ctx->r11 == 0) {
        // 0x8002F3A4: nop

            goto L_8002F3DC;
    }
    // 0x8002F3A4: nop

    // 0x8002F3A8: andi        $t4, $t2, 0x20
    ctx->r12 = ctx->r10 & 0X20;
    // 0x8002F3AC: bne         $t4, $zero, L_8002F3DC
    if (ctx->r12 != 0) {
        // 0x8002F3B0: nop

            goto L_8002F3DC;
    }
    // 0x8002F3B0: nop

    // 0x8002F3B4: andi        $t5, $t2, 0x10
    ctx->r13 = ctx->r10 & 0X10;
    // 0x8002F3B8: bne         $t5, $zero, L_8002F3DC
    if (ctx->r13 != 0) {
        // 0x8002F3BC: nop

            goto L_8002F3DC;
    }
    // 0x8002F3BC: nop

    // 0x8002F3C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002F3C4: lh          $t6, 0x2588($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2588);
    // 0x8002F3C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F3CC: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8002F3D0: sh          $t7, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r15;
    // 0x8002F3D4: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8002F3D8: sh          $t9, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r25;
L_8002F3DC:
    // 0x8002F3DC: lh          $t0, 0x62($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X62);
    // 0x8002F3E0: nop

    // 0x8002F3E4: beq         $t0, $zero, L_8002F434
    if (ctx->r8 == 0) {
        // 0x8002F3E8: nop

            goto L_8002F434;
    }
    // 0x8002F3E8: nop

    // 0x8002F3EC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8002F3F0: lh          $t1, -0x6558($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6558);
    // 0x8002F3F4: lh          $a2, 0x62($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X62);
    // 0x8002F3F8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8002F3FC: addiu       $t3, $t1, -0x4A
    ctx->r11 = ADD32(ctx->r9, -0X4A);
    // 0x8002F400: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002F404: or          $t8, $a2, $at
    ctx->r24 = ctx->r6 | ctx->r1;
    // 0x8002F408: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x8002F40C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002F410: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002F414: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F418: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8002F41C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8002F420: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002F424: addiu       $a3, $zero, 0x41
    ctx->r7 = ADD32(0, 0X41);
    // 0x8002F428: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8002F42C: jal         0x800B1F0C
    // 0x8002F430: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_24;
    // 0x8002F430: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_24:
L_8002F434:
    // 0x8002F434: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002F438: lh          $t4, 0x2588($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2588);
    // 0x8002F43C: nop

    // 0x8002F440: andi        $t2, $t4, 0x8
    ctx->r10 = ctx->r12 & 0X8;
    // 0x8002F444: beq         $t2, $zero, L_8002F49C
    if (ctx->r10 == 0) {
        // 0x8002F448: nop

            goto L_8002F49C;
    }
    // 0x8002F448: nop

    // 0x8002F44C: jal         0x800C1850
    // 0x8002F450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_25;
    // 0x8002F450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x8002F454: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F458: jal         0x8009A14C
    // 0x8002F45C: nop

    func_8009A14C(rdram, ctx);
        goto after_26;
    // 0x8002F45C: nop

    after_26:
    // 0x8002F460: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F464: jal         0x800997D8
    // 0x8002F468: nop

    func_800997D8(rdram, ctx);
        goto after_27;
    // 0x8002F468: nop

    after_27:
    // 0x8002F46C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F470: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8002F474: jal         0x800B26E0
    // 0x8002F478: nop

    func_800B26E0(rdram, ctx);
        goto after_28;
    // 0x8002F478: nop

    after_28:
    // 0x8002F47C: bgez        $v0, L_8002F49C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002F480: nop

            goto L_8002F49C;
    }
    // 0x8002F480: nop

    // 0x8002F484: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F488: lh          $t5, 0x2588($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2588);
    // 0x8002F48C: addiu       $at, $zero, -0x19
    ctx->r1 = ADD32(0, -0X19);
    // 0x8002F490: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8002F494: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F498: sh          $t6, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r14;
L_8002F49C:
    // 0x8002F49C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002F4A0: lw          $t7, 0x70E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E8);
    // 0x8002F4A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8002F4A8: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8002F4AC: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x8002F4B0: bne         $at, $zero, L_8002F4C4
    if (ctx->r1 != 0) {
        // 0x8002F4B4: sw          $t7, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r15;
            goto L_8002F4C4;
    }
    // 0x8002F4B4: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x8002F4B8: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8002F4BC: ori         $t9, $t9, 0x869F
    ctx->r25 = ctx->r25 | 0X869F;
    // 0x8002F4C0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
L_8002F4C4:
    // 0x8002F4C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002F4C8: lw          $t0, 0x25D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X25D4);
    // 0x8002F4CC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8002F4D0: nop

    // 0x8002F4D4: beq         $t0, $t8, L_8002F504
    if (ctx->r8 == ctx->r24) {
        // 0x8002F4D8: nop

            goto L_8002F504;
    }
    // 0x8002F4D8: nop

    // 0x8002F4DC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002F4E0: lw          $t1, 0x29BC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X29BC);
    // 0x8002F4E4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8002F4E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F4EC: lw          $a1, 0x128($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X128);
    // 0x8002F4F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002F4F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8002F4F8: sw          $t3, 0x25D4($at)
    MEM_W(0X25D4, ctx->r1) = ctx->r11;
    // 0x8002F4FC: jal         0x8002D798
    // 0x8002F500: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_8002D798(rdram, ctx);
        goto after_29;
    // 0x8002F500: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_29:
L_8002F504:
    // 0x8002F504: jal         0x800C1850
    // 0x8002F508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_30;
    // 0x8002F508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_30:
    // 0x8002F50C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F510: lw          $a0, 0x29BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29BC);
    // 0x8002F514: jal         0x8009A14C
    // 0x8002F518: nop

    func_8009A14C(rdram, ctx);
        goto after_31;
    // 0x8002F518: nop

    after_31:
    // 0x8002F51C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F520: lw          $a0, 0x29BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29BC);
    // 0x8002F524: jal         0x800997D8
    // 0x8002F528: nop

    func_800997D8(rdram, ctx);
        goto after_32;
    // 0x8002F528: nop

    after_32:
    // 0x8002F52C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002F530: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002F534: lbu         $t2, 0x7208($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7208);
    // 0x8002F538: lh          $t4, 0x25E0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X25E0);
    // 0x8002F53C: nop

    // 0x8002F540: beq         $t4, $t2, L_8002F574
    if (ctx->r12 == ctx->r10) {
        // 0x8002F544: nop

            goto L_8002F574;
    }
    // 0x8002F544: nop

    // 0x8002F548: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F54C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002F550: lbu         $t6, 0x7208($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7208);
    // 0x8002F554: lw          $t5, 0x49C4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X49C4);
    // 0x8002F558: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F55C: lw          $a1, 0x128($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X128);
    // 0x8002F560: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002F564: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8002F568: sh          $t6, 0x25E0($at)
    MEM_H(0X25E0, ctx->r1) = ctx->r14;
    // 0x8002F56C: jal         0x8002D798
    // 0x8002F570: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    func_8002D798(rdram, ctx);
        goto after_33;
    // 0x8002F570: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_33:
L_8002F574:
    // 0x8002F574: jal         0x800C1850
    // 0x8002F578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_34;
    // 0x8002F578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x8002F57C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F580: lw          $a0, 0x49C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X49C4);
    // 0x8002F584: jal         0x8009A14C
    // 0x8002F588: nop

    func_8009A14C(rdram, ctx);
        goto after_35;
    // 0x8002F588: nop

    after_35:
    // 0x8002F58C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F590: lw          $a0, 0x49C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X49C4);
    // 0x8002F594: jal         0x800997D8
    // 0x8002F598: nop

    func_800997D8(rdram, ctx);
        goto after_36;
    // 0x8002F598: nop

    after_36:
    // 0x8002F59C: jal         0x800C1A28
    // 0x8002F5A0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_37;
    // 0x8002F5A0: nop

    after_37:
    // 0x8002F5A4: b           L_8002F5AC
    // 0x8002F5A8: nop

        goto L_8002F5AC;
    // 0x8002F5A8: nop

L_8002F5AC:
    // 0x8002F5AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002F5B0: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002F5B4: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002F5B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002F5BC: jr          $ra
    // 0x8002F5C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002F5C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002F5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F5C4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8002F5C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002F5CC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8002F5D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F5D4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002F5D8: addiu       $t7, $t7, -0x4790
    ctx->r15 = ADD32(ctx->r15, -0X4790);
    // 0x8002F5DC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8002F5E0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x8002F5E4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8002F5E8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8002F5EC: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8002F5F0: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8002F5F4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8002F5F8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8002F5FC: addiu       $t1, $t1, -0x4784
    ctx->r9 = ADD32(ctx->r9, -0X4784);
    // 0x8002F600: lwr         $at, 0x2($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0X2);
    // 0x8002F604: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x8002F608: swr         $at, 0x2($t0)
    do_swr(rdram, 0X2, ctx->r8, ctx->r1);
    // 0x8002F60C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002F610: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x8002F614: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8002F618: bne         $t4, $at, L_8002F648
    if (ctx->r12 != ctx->r1) {
        // 0x8002F61C: nop

            goto L_8002F648;
    }
    // 0x8002F61C: nop

    // 0x8002F620: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002F624: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x8002F628: nop

    // 0x8002F62C: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8002F630: beq         $at, $zero, L_8002F648
    if (ctx->r1 == 0) {
        // 0x8002F634: nop

            goto L_8002F648;
    }
    // 0x8002F634: nop

    // 0x8002F638: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002F63C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F640: b           L_8002F650
    // 0x8002F644: sb          $t8, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = ctx->r24;
        goto L_8002F650;
    // 0x8002F644: sb          $t8, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = ctx->r24;
L_8002F648:
    // 0x8002F648: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F64C: sb          $zero, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = 0;
L_8002F650:
    // 0x8002F650: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F654: sh          $zero, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = 0;
    // 0x8002F658: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F65C: sh          $zero, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = 0;
    // 0x8002F660: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F664: sh          $zero, 0x2570($at)
    MEM_H(0X2570, ctx->r1) = 0;
    // 0x8002F668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F66C: sh          $zero, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = 0;
    // 0x8002F670: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F674: sh          $zero, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = 0;
    // 0x8002F678: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F67C: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x8002F680: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002F684: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F688: swc1        $f4, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f4.u32l;
    // 0x8002F68C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F690: swc1        $f4, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f4.u32l;
    // 0x8002F694: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F698: swc1        $f4, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f4.u32l;
    // 0x8002F69C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002F6A0: sh          $zero, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = 0;
    // 0x8002F6A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002F6A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F6AC: sb          $t6, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = ctx->r14;
    // 0x8002F6B0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002F6B4: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x8002F6B8: nop

    // 0x8002F6BC: bne         $t7, $zero, L_8002F6D0
    if (ctx->r15 != 0) {
        // 0x8002F6C0: nop

            goto L_8002F6D0;
    }
    // 0x8002F6C0: nop

    // 0x8002F6C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002F6C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002F6CC: swc1        $f6, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f6.u32l;
L_8002F6D0:
    // 0x8002F6D0: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
L_8002F6D4:
    // 0x8002F6D4: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x8002F6D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F6DC: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8002F6E0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8002F6E4: sw          $zero, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = 0;
    // 0x8002F6E8: lh          $t0, 0x5A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5A);
    // 0x8002F6EC: nop

    // 0x8002F6F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8002F6F4: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x8002F6F8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8002F6FC: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8002F700: bne         $at, $zero, L_8002F6D4
    if (ctx->r1 != 0) {
        // 0x8002F704: sh          $t1, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r9;
            goto L_8002F6D4;
    }
    // 0x8002F704: sh          $t1, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r9;
    // 0x8002F708: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
L_8002F70C:
    // 0x8002F70C: lh          $t5, 0x5A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X5A);
    // 0x8002F710: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F714: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8002F718: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002F71C: sh          $zero, 0x2590($at)
    MEM_H(0X2590, ctx->r1) = 0;
    // 0x8002F720: lh          $t6, 0x5A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5A);
    // 0x8002F724: nop

    // 0x8002F728: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002F72C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8002F730: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002F734: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8002F738: bne         $at, $zero, L_8002F70C
    if (ctx->r1 != 0) {
        // 0x8002F73C: sh          $t7, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r15;
            goto L_8002F70C;
    }
    // 0x8002F73C: sh          $t7, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r15;
    // 0x8002F740: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8002F744: lw          $t0, -0x73D0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73D0);
    // 0x8002F748: nop

    // 0x8002F74C: lw          $t1, 0x380($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X380);
    // 0x8002F750: nop

    // 0x8002F754: ori         $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 | 0X8000;
    // 0x8002F758: sw          $t3, 0x380($t0)
    MEM_W(0X380, ctx->r8) = ctx->r11;
    // 0x8002F75C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8002F760: nop

    // 0x8002F764: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x8002F768: beq         $at, $zero, L_8002F834
    if (ctx->r1 == 0) {
        // 0x8002F76C: nop

            goto L_8002F834;
    }
    // 0x8002F76C: nop

    // 0x8002F770: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002F774: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002F778: addu        $at, $at, $t4
    gpr jr_addend_8002F784 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8002F77C: lw          $t4, -0x1840($at)
    ctx->r12 = ADD32(ctx->r1, -0X1840);
    // 0x8002F780: nop

    // 0x8002F784: jr          $t4
    // 0x8002F788: nop

    switch (jr_addend_8002F784 >> 2) {
        case 0: goto L_8002F78C; break;
        case 1: goto L_8002F7B8; break;
        case 2: goto L_8002F7D8; break;
        case 3: goto L_8002F7F8; break;
        case 4: goto L_8002F818; break;
        default: switch_error(__func__, 0x8002F784, 0x800EE7C0);
    }
    // 0x8002F788: nop

L_8002F78C:
    // 0x8002F78C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F790: sh          $zero, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = 0;
    // 0x8002F794: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8002F798: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F79C: sh          $t5, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r13;
    // 0x8002F7A0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8002F7A4: lw          $t6, -0x73D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73D0);
    // 0x8002F7A8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8002F7AC: sh          $t8, 0x3DE($t6)
    MEM_H(0X3DE, ctx->r14) = ctx->r24;
    // 0x8002F7B0: b           L_8002F834
    // 0x8002F7B4: nop

        goto L_8002F834;
    // 0x8002F7B4: nop

L_8002F7B8:
    // 0x8002F7B8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8002F7BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F7C0: sh          $t7, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r15;
    // 0x8002F7C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002F7C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F7CC: sh          $t9, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r25;
    // 0x8002F7D0: b           L_8002F834
    // 0x8002F7D4: nop

        goto L_8002F834;
    // 0x8002F7D4: nop

L_8002F7D8:
    // 0x8002F7D8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002F7DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F7E0: sh          $t2, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r10;
    // 0x8002F7E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002F7E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F7EC: sh          $t1, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r9;
    // 0x8002F7F0: b           L_8002F834
    // 0x8002F7F4: nop

        goto L_8002F834;
    // 0x8002F7F4: nop

L_8002F7F8:
    // 0x8002F7F8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8002F7FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F800: sh          $t3, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r11;
    // 0x8002F804: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8002F808: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F80C: sh          $t0, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r8;
    // 0x8002F810: b           L_8002F834
    // 0x8002F814: nop

        goto L_8002F834;
    // 0x8002F814: nop

L_8002F818:
    // 0x8002F818: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x8002F81C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F820: sh          $t4, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r12;
    // 0x8002F824: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F828: sh          $zero, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = 0;
    // 0x8002F82C: b           L_8002F834
    // 0x8002F830: nop

        goto L_8002F834;
    // 0x8002F830: nop

L_8002F834:
    // 0x8002F834: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F838: lh          $t5, 0x2518($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2518);
    // 0x8002F83C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F840: sb          $t5, -0x6A00($at)
    MEM_B(-0X6A00, ctx->r1) = ctx->r13;
    // 0x8002F844: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8002F848: lhu         $t8, -0x6504($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6504);
    // 0x8002F84C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002F850: sh          $t8, 0x72E4($at)
    MEM_H(0X72E4, ctx->r1) = ctx->r24;
    // 0x8002F854: jal         0x800BC6EC
    // 0x8002F858: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8002F858: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    after_0:
    // 0x8002F85C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F860: sw          $v0, 0x24D8($at)
    MEM_W(0X24D8, ctx->r1) = ctx->r2;
    // 0x8002F864: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002F868: lw          $t6, 0x24D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X24D8);
    // 0x8002F86C: nop

    // 0x8002F870: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8002F874: jal         0x800BC6EC
    // 0x8002F878: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8002F878: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_1:
    // 0x8002F87C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F880: sw          $v0, 0x24F8($at)
    MEM_W(0X24F8, ctx->r1) = ctx->r2;
    // 0x8002F884: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002F888: lw          $t7, 0x24F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X24F8);
    // 0x8002F88C: nop

    // 0x8002F890: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8002F894: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
L_8002F898:
    // 0x8002F898: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002F89C: jal         0x80099E2C
    // 0x8002F8A0: nop

    func_80099E2C(rdram, ctx);
        goto after_2;
    // 0x8002F8A0: nop

    after_2:
    // 0x8002F8A4: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002F8A8: addiu       $t9, $zero, 0x148
    ctx->r25 = ADD32(0, 0X148);
    // 0x8002F8AC: sw          $t9, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r25;
    // 0x8002F8B0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002F8B4: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x8002F8B8: sw          $t1, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r9;
    // 0x8002F8BC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002F8C0: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8002F8C4: sh          $t0, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r8;
    // 0x8002F8C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002F8CC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002F8D0: jal         0x800B1B04
    // 0x8002F8D4: nop

    func_800B1B04(rdram, ctx);
        goto after_3;
    // 0x8002F8D4: nop

    after_3:
    // 0x8002F8D8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002F8DC: nop

    // 0x8002F8E0: addiu       $t8, $t5, 0x160
    ctx->r24 = ADD32(ctx->r13, 0X160);
    // 0x8002F8E4: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8002F8E8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8002F8EC: nop

    // 0x8002F8F0: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x8002F8F4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8002F8F8: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x8002F8FC: nop

    // 0x8002F900: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8002F904: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x8002F908: sra         $t3, $t1, 16
    ctx->r11 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002F90C: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8002F910: bne         $at, $zero, L_8002F898
    if (ctx->r1 != 0) {
        // 0x8002F914: sh          $t2, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r10;
            goto L_8002F898;
    }
    // 0x8002F914: sh          $t2, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r10;
    // 0x8002F918: jal         0x800BC6EC
    // 0x8002F91C: addiu       $a0, $zero, 0x1A00
    ctx->r4 = ADD32(0, 0X1A00);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8002F91C: addiu       $a0, $zero, 0x1A00
    ctx->r4 = ADD32(0, 0X1A00);
    after_4:
    // 0x8002F920: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F924: sw          $v0, 0x7B70($at)
    MEM_W(0X7B70, ctx->r1) = ctx->r2;
    // 0x8002F928: jal         0x800BC6EC
    // 0x8002F92C: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8002F92C: addiu       $a0, $zero, 0xD00
    ctx->r4 = ADD32(0, 0XD00);
    after_5:
    // 0x8002F930: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F934: sw          $v0, 0x7BBC($at)
    MEM_W(0X7BBC, ctx->r1) = ctx->r2;
    // 0x8002F938: jal         0x800BC6EC
    // 0x8002F93C: addiu       $a0, $zero, 0x9C0
    ctx->r4 = ADD32(0, 0X9C0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x8002F93C: addiu       $a0, $zero, 0x9C0
    ctx->r4 = ADD32(0, 0X9C0);
    after_6:
    // 0x8002F940: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F944: sw          $v0, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r2;
    // 0x8002F948: jal         0x800BC6EC
    // 0x8002F94C: addiu       $a0, $zero, 0x1860
    ctx->r4 = ADD32(0, 0X1860);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8002F94C: addiu       $a0, $zero, 0x1860
    ctx->r4 = ADD32(0, 0X1860);
    after_7:
    // 0x8002F950: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F954: sw          $v0, 0x69C8($at)
    MEM_W(0X69C8, ctx->r1) = ctx->r2;
    // 0x8002F958: jal         0x800BC6EC
    // 0x8002F95C: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x8002F95C: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    after_8:
    // 0x8002F960: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F964: sw          $v0, 0x7AE0($at)
    MEM_W(0X7AE0, ctx->r1) = ctx->r2;
    // 0x8002F968: jal         0x800BC6EC
    // 0x8002F96C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_9;
    // 0x8002F96C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_9:
    // 0x8002F970: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F974: sw          $v0, 0x263C($at)
    MEM_W(0X263C, ctx->r1) = ctx->r2;
    // 0x8002F978: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002F97C: lw          $t0, 0x263C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X263C);
    // 0x8002F980: nop

    // 0x8002F984: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8002F988: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
L_8002F98C:
    // 0x8002F98C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002F990: jal         0x80099E2C
    // 0x8002F994: nop

    func_80099E2C(rdram, ctx);
        goto after_10;
    // 0x8002F994: nop

    after_10:
    // 0x8002F998: lh          $t4, 0x5A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X5A);
    // 0x8002F99C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002F9A0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002F9A4: addu        $t8, $sp, $t5
    ctx->r24 = ADD32(ctx->r29, ctx->r13);
    // 0x8002F9A8: lwc1        $f8, 0x28($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8002F9AC: nop

    // 0x8002F9B0: swc1        $f8, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f8.u32l;
    // 0x8002F9B4: lui         $at, 0xC2AE
    ctx->r1 = S32(0XC2AE << 16);
    // 0x8002F9B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002F9BC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002F9C0: nop

    // 0x8002F9C4: swc1        $f10, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f10.u32l;
    // 0x8002F9C8: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x8002F9CC: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002F9D0: addu        $t2, $sp, $t9
    ctx->r10 = ADD32(ctx->r29, ctx->r25);
    // 0x8002F9D4: lbu         $t2, 0x24($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X24);
    // 0x8002F9D8: nop

    // 0x8002F9DC: sh          $t2, 0x100($t1)
    MEM_H(0X100, ctx->r9) = ctx->r10;
    // 0x8002F9E0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002F9E4: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x8002F9E8: sh          $t3, 0x102($t0)
    MEM_H(0X102, ctx->r8) = ctx->r11;
    // 0x8002F9EC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002F9F0: ori         $t4, $zero, 0x8048
    ctx->r12 = 0 | 0X8048;
    // 0x8002F9F4: sw          $t4, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r12;
    // 0x8002F9F8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002F9FC: addiu       $t8, $zero, 0xBE
    ctx->r24 = ADD32(0, 0XBE);
    // 0x8002FA00: sw          $t8, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r24;
    // 0x8002FA04: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002FA08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002FA0C: sh          $t7, 0x116($t9)
    MEM_H(0X116, ctx->r25) = ctx->r15;
    // 0x8002FA10: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002FA14: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8002FA18: sh          $t2, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r10;
    // 0x8002FA1C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002FA20: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8002FA24: addiu       $t3, $t3, -0x44B8
    ctx->r11 = ADD32(ctx->r11, -0X44B8);
    // 0x8002FA28: sw          $t3, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r11;
    // 0x8002FA2C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002FA30: nop

    // 0x8002FA34: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x8002FA38: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x8002FA3C: lh          $t8, 0x5A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5A);
    // 0x8002FA40: nop

    // 0x8002FA44: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8002FA48: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8002FA4C: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002FA50: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8002FA54: bne         $at, $zero, L_8002F98C
    if (ctx->r1 != 0) {
        // 0x8002FA58: sh          $t6, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r14;
            goto L_8002F98C;
    }
    // 0x8002FA58: sh          $t6, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r14;
    // 0x8002FA5C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002FA60: addiu       $t2, $t2, 0x16E8
    ctx->r10 = ADD32(ctx->r10, 0X16E8);
    // 0x8002FA64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002FA68: sw          $t2, 0x1688($at)
    MEM_W(0X1688, ctx->r1) = ctx->r10;
    // 0x8002FA6C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8002FA70: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8002FA74: addiu       $t1, $t1, 0x5B0
    ctx->r9 = ADD32(ctx->r9, 0X5B0);
    // 0x8002FA78: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8002FA7C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002FA80: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002FA84: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002FA88: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002FA8C: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x8002FA90: jal         0x800BD1FC
    // 0x8002FA94: addiu       $a2, $a2, 0x3C30
    ctx->r6 = ADD32(ctx->r6, 0X3C30);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_11;
    // 0x8002FA94: addiu       $a2, $a2, 0x3C30
    ctx->r6 = ADD32(ctx->r6, 0X3C30);
    after_11:
    // 0x8002FA98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002FA9C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002FAA0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002FAA4: jal         0x800BD218
    // 0x8002FAA8: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    SysMem_DmaCopy(rdram, ctx);
        goto after_12;
    // 0x8002FAA8: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    after_12:
    // 0x8002FAAC: jal         0x800BC6EC
    // 0x8002FAB0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_13;
    // 0x8002FAB0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_13:
    // 0x8002FAB4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002FAB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002FABC: sw          $s0, 0x138($t3)
    MEM_W(0X138, ctx->r11) = ctx->r16;
    // 0x8002FAC0: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8002FAC4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002FAC8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002FACC: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002FAD0: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002FAD4: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x8002FAD8: jal         0x800BD1FC
    // 0x8002FADC: addiu       $a2, $a2, 0x3E00
    ctx->r6 = ADD32(ctx->r6, 0X3E00);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_14;
    // 0x8002FADC: addiu       $a2, $a2, 0x3E00
    ctx->r6 = ADD32(ctx->r6, 0X3E00);
    after_14:
    // 0x8002FAE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002FAE4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002FAE8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FAEC: jal         0x800BD218
    // 0x8002FAF0: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    SysMem_DmaCopy(rdram, ctx);
        goto after_15;
    // 0x8002FAF0: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_15:
    // 0x8002FAF4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8002FAF8: nop

    // 0x8002FAFC: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x8002FB00: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8002FB04: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB08: nop

    // 0x8002FB0C: addiu       $t8, $t5, 0x160
    ctx->r24 = ADD32(ctx->r13, 0X160);
    // 0x8002FB10: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8002FB14: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB18: jal         0x80099E2C
    // 0x8002FB1C: nop

    func_80099E2C(rdram, ctx);
        goto after_16;
    // 0x8002FB1C: nop

    after_16:
    // 0x8002FB20: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002FB24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002FB28: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB2C: nop

    // 0x8002FB30: swc1        $f16, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f16.u32l;
    // 0x8002FB34: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8002FB38: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB3C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8002FB40: nop

    // 0x8002FB44: sh          $t9, 0x100($t2)
    MEM_H(0X100, ctx->r10) = ctx->r25;
    // 0x8002FB48: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8002FB4C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB50: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x8002FB54: nop

    // 0x8002FB58: sh          $t3, 0x102($t0)
    MEM_H(0X102, ctx->r8) = ctx->r11;
    // 0x8002FB5C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB60: addiu       $t4, $zero, 0x148
    ctx->r12 = ADD32(0, 0X148);
    // 0x8002FB64: sw          $t4, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r12;
    // 0x8002FB68: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB6C: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x8002FB70: sw          $t8, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r24;
    // 0x8002FB74: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FB78: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB7C: nop

    // 0x8002FB80: sw          $t7, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r15;
    // 0x8002FB84: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002FB88: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8002FB8C: sh          $t2, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r10;
    // 0x8002FB90: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8002FB94: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002FB98: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8002FB9C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002FBA0: lui         $t4, 0x809B
    ctx->r12 = S32(0X809B << 16);
    // 0x8002FBA4: addiu       $t4, $t4, 0x1E10
    ctx->r12 = ADD32(ctx->r12, 0X1E10);
    // 0x8002FBA8: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002FBAC: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002FBB0: jal         0x800BD1FC
    // 0x8002FBB4: addu        $a2, $t0, $t4
    ctx->r6 = ADD32(ctx->r8, ctx->r12);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_17;
    // 0x8002FBB4: addu        $a2, $t0, $t4
    ctx->r6 = ADD32(ctx->r8, ctx->r12);
    after_17:
    // 0x8002FBB8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002FBBC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002FBC0: jal         0x800BED70
    // 0x8002FBC4: nop

    Spi_GetHeader(rdram, ctx);
        goto after_18;
    // 0x8002FBC4: nop

    after_18:
    // 0x8002FBC8: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x8002FBCC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8002FBD0: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8002FBD4: jal         0x800BC6EC
    // 0x8002FBD8: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_19;
    // 0x8002FBD8: nop

    after_19:
    // 0x8002FBDC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002FBE0: nop

    // 0x8002FBE4: sw          $v0, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r2;
    // 0x8002FBE8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002FBEC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002FBF0: lh          $a1, 0x58($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X58);
    // 0x8002FBF4: lw          $a2, 0x128($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X128);
    // 0x8002FBF8: jal         0x800BF0B4
    // 0x8002FBFC: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_20;
    // 0x8002FBFC: nop

    after_20:
    // 0x8002FC00: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8002FC04: addiu       $t6, $t6, 0x5B0
    ctx->r14 = ADD32(ctx->r14, 0X5B0);
    // 0x8002FC08: addiu       $t7, $t6, 0x68
    ctx->r15 = ADD32(ctx->r14, 0X68);
    // 0x8002FC0C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8002FC10: jal         0x800BC6EC
    // 0x8002FC14: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_21;
    // 0x8002FC14: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_21:
    // 0x8002FC18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002FC1C: sw          $v0, 0x16C0($at)
    MEM_W(0X16C0, ctx->r1) = ctx->r2;
    // 0x8002FC20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002FC24: lw          $t9, 0x16C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X16C0);
    // 0x8002FC28: nop

    // 0x8002FC2C: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8002FC30: jal         0x800BC6EC
    // 0x8002FC34: addiu       $a0, $zero, 0x590
    ctx->r4 = ADD32(0, 0X590);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_22;
    // 0x8002FC34: addiu       $a0, $zero, 0x590
    ctx->r4 = ADD32(0, 0X590);
    after_22:
    // 0x8002FC38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002FC3C: sw          $v0, -0x6A08($at)
    MEM_W(-0X6A08, ctx->r1) = ctx->r2;
    // 0x8002FC40: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002FC44: jal         0x80099E2C
    // 0x8002FC48: nop

    func_80099E2C(rdram, ctx);
        goto after_23;
    // 0x8002FC48: nop

    after_23:
    // 0x8002FC4C: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8002FC50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002FC54: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002FC58: nop

    // 0x8002FC5C: swc1        $f18, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f18.u32l;
    // 0x8002FC60: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8002FC64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002FC68: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002FC6C: nop

    // 0x8002FC70: swc1        $f4, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f4.u32l;
    // 0x8002FC74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002FC78: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002FC7C: nop

    // 0x8002FC80: swc1        $f6, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f6.u32l;
    // 0x8002FC84: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8002FC88: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002FC8C: lhu         $t4, 0x4($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X4);
    // 0x8002FC90: nop

    // 0x8002FC94: sh          $t4, 0x100($t5)
    MEM_H(0X100, ctx->r13) = ctx->r12;
    // 0x8002FC98: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8002FC9C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002FCA0: lhu         $t6, 0x6($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X6);
    // 0x8002FCA4: nop

    // 0x8002FCA8: sh          $t6, 0x102($t7)
    MEM_H(0X102, ctx->r15) = ctx->r14;
    // 0x8002FCAC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002FCB0: addiu       $t9, $zero, 0x1148
    ctx->r25 = ADD32(0, 0X1148);
    // 0x8002FCB4: sw          $t9, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r25;
    // 0x8002FCB8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002FCBC: addiu       $t1, $zero, 0xBE
    ctx->r9 = ADD32(0, 0XBE);
    // 0x8002FCC0: sw          $t1, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r9;
    // 0x8002FCC4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002FCC8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8002FCCC: sh          $t0, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r8;
    // 0x8002FCD0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FCD4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002FCD8: nop

    // 0x8002FCDC: sw          $t5, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r13;
    // 0x8002FCE0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002FCE4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8002FCE8: sh          $t6, 0xC4($t7)
    MEM_H(0XC4, ctx->r15) = ctx->r14;
    // 0x8002FCEC: jal         0x800BC6EC
    // 0x8002FCF0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_24;
    // 0x8002FCF0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_24:
    // 0x8002FCF4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8002FCF8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8002FCFC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002FD00: nop

    // 0x8002FD04: sw          $t9, 0x128($t2)
    MEM_W(0X128, ctx->r10) = ctx->r25;
    // 0x8002FD08: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8002FD0C: nop

    // 0x8002FD10: addiu       $t3, $t1, 0x24
    ctx->r11 = ADD32(ctx->r9, 0X24);
    // 0x8002FD14: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8002FD18: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002FD1C: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x8002FD20: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
    // 0x8002FD24: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8002FD28: sh          $t5, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r13;
L_8002FD2C:
    // 0x8002FD2C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8002FD30: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002FD34: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8002FD38: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002FD3C: lui         $t7, 0x809B
    ctx->r15 = S32(0X809B << 16);
    // 0x8002FD40: addiu       $t7, $t7, 0x1E10
    ctx->r15 = ADD32(ctx->r15, 0X1E10);
    // 0x8002FD44: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002FD48: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002FD4C: jal         0x800BD1FC
    // 0x8002FD50: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_25;
    // 0x8002FD50: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    after_25:
    // 0x8002FD54: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002FD58: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002FD5C: jal         0x800BED70
    // 0x8002FD60: nop

    Spi_GetHeader(rdram, ctx);
        goto after_26;
    // 0x8002FD60: nop

    after_26:
    // 0x8002FD64: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x8002FD68: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x8002FD6C: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8002FD70: lw          $t1, -0x6A08($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A08);
    // 0x8002FD74: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002FD78: lh          $a1, 0x58($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X58);
    // 0x8002FD7C: sll         $t2, $t9, 7
    ctx->r10 = S32(ctx->r25 << 7);
    // 0x8002FD80: jal         0x800BF0B4
    // 0x8002FD84: addu        $a2, $t2, $t1
    ctx->r6 = ADD32(ctx->r10, ctx->r9);
    Spi_DecompressAsset(rdram, ctx);
        goto after_27;
    // 0x8002FD84: addu        $a2, $t2, $t1
    ctx->r6 = ADD32(ctx->r10, ctx->r9);
    after_27:
    // 0x8002FD88: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8002FD8C: nop

    // 0x8002FD90: addiu       $t0, $t3, -0x8
    ctx->r8 = ADD32(ctx->r11, -0X8);
    // 0x8002FD94: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8002FD98: lh          $t4, 0x5A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X5A);
    // 0x8002FD9C: nop

    // 0x8002FDA0: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8002FDA4: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8002FDA8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002FDAC: bgez        $t6, L_8002FD2C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8002FDB0: sh          $t5, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r13;
            goto L_8002FD2C;
    }
    // 0x8002FDB0: sh          $t5, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r13;
    // 0x8002FDB4: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
L_8002FDB8:
    // 0x8002FDB8: lh          $t7, 0x5A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5A);
    // 0x8002FDBC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8002FDC0: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8002FDC4: sh          $t9, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r25;
    // 0x8002FDC8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8002FDCC: nop

    // 0x8002FDD0: sh          $zero, 0x2($t1)
    MEM_H(0X2, ctx->r9) = 0;
    // 0x8002FDD4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8002FDD8: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8002FDDC: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    // 0x8002FDE0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8002FDE4: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8002FDE8: sh          $t4, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r12;
    // 0x8002FDEC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8002FDF0: nop

    // 0x8002FDF4: addiu       $t6, $t8, 0xC
    ctx->r14 = ADD32(ctx->r24, 0XC);
    // 0x8002FDF8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8002FDFC: lh          $t7, 0x5A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5A);
    // 0x8002FE00: nop

    // 0x8002FE04: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8002FE08: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x8002FE0C: sra         $t1, $t2, 16
    ctx->r9 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8002FE10: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8002FE14: bne         $at, $zero, L_8002FDB8
    if (ctx->r1 != 0) {
        // 0x8002FE18: sh          $t9, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r25;
            goto L_8002FDB8;
    }
    // 0x8002FE18: sh          $t9, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r25;
    // 0x8002FE1C: jal         0x8002D598
    // 0x8002FE20: nop

    func_8002D598(rdram, ctx);
        goto after_28;
    // 0x8002FE20: nop

    after_28:
    // 0x8002FE24: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002FE28: addiu       $t3, $t3, 0x19D0
    ctx->r11 = ADD32(ctx->r11, 0X19D0);
    // 0x8002FE2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002FE30: sw          $t3, 0x1694($at)
    MEM_W(0X1694, ctx->r1) = ctx->r11;
    // 0x8002FE34: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8002FE38: jal         0x800BC6EC
    // 0x8002FE3C: addiu       $a0, $zero, 0x880
    ctx->r4 = ADD32(0, 0X880);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_29;
    // 0x8002FE3C: addiu       $a0, $zero, 0x880
    ctx->r4 = ADD32(0, 0X880);
    after_29:
    // 0x8002FE40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002FE44: sw          $v0, 0x7B54($at)
    MEM_W(0X7B54, ctx->r1) = ctx->r2;
    // 0x8002FE48: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
L_8002FE4C:
    // 0x8002FE4C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FE50: jal         0x80099E2C
    // 0x8002FE54: nop

    func_80099E2C(rdram, ctx);
        goto after_30;
    // 0x8002FE54: nop

    after_30:
    // 0x8002FE58: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FE5C: addiu       $t0, $zero, 0x148
    ctx->r8 = ADD32(0, 0X148);
    // 0x8002FE60: sw          $t0, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r8;
    // 0x8002FE64: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FE68: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x8002FE6C: sw          $t5, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r13;
    // 0x8002FE70: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002FE74: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FE78: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x8002FE7C: nop

    // 0x8002FE80: sw          $t7, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r15;
    // 0x8002FE84: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FE88: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8002FE8C: sh          $t2, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r10;
    // 0x8002FE90: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FE94: nop

    // 0x8002FE98: addiu       $t0, $t3, 0x160
    ctx->r8 = ADD32(ctx->r11, 0X160);
    // 0x8002FE9C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8002FEA0: lh          $t4, 0x5A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X5A);
    // 0x8002FEA4: nop

    // 0x8002FEA8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002FEAC: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8002FEB0: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002FEB4: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8002FEB8: bne         $at, $zero, L_8002FE4C
    if (ctx->r1 != 0) {
        // 0x8002FEBC: sh          $t5, 0x5A($sp)
        MEM_H(0X5A, ctx->r29) = ctx->r13;
            goto L_8002FE4C;
    }
    // 0x8002FEBC: sh          $t5, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r13;
    // 0x8002FEC0: jal         0x80029ED8
    // 0x8002FEC4: nop

    func_80029ED8(rdram, ctx);
        goto after_31;
    // 0x8002FEC4: nop

    after_31:
    // 0x8002FEC8: jal         0x800BC6EC
    // 0x8002FECC: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_32;
    // 0x8002FECC: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_32:
    // 0x8002FED0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002FED4: sw          $v0, 0x29BC($at)
    MEM_W(0X29BC, ctx->r1) = ctx->r2;
    // 0x8002FED8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002FEDC: lw          $a0, 0x29BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29BC);
    // 0x8002FEE0: jal         0x80099E2C
    // 0x8002FEE4: nop

    func_80099E2C(rdram, ctx);
        goto after_33;
    // 0x8002FEE4: nop

    after_33:
    // 0x8002FEE8: jal         0x800BC6EC
    // 0x8002FEEC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_34;
    // 0x8002FEEC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_34:
    // 0x8002FEF0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002FEF4: lw          $t7, 0x29BC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X29BC);
    // 0x8002FEF8: nop

    // 0x8002FEFC: sw          $v0, 0x128($t7)
    MEM_W(0X128, ctx->r15) = ctx->r2;
    // 0x8002FF00: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002FF04: lw          $t2, 0x29BC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X29BC);
    // 0x8002FF08: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x8002FF0C: sw          $t9, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r25;
    // 0x8002FF10: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002FF14: lw          $t3, 0x29BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X29BC);
    // 0x8002FF18: addiu       $t1, $zero, 0xBE
    ctx->r9 = ADD32(0, 0XBE);
    // 0x8002FF1C: sw          $t1, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r9;
    // 0x8002FF20: lui         $at, 0xC2B0
    ctx->r1 = S32(0XC2B0 << 16);
    // 0x8002FF24: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002FF28: lw          $t0, 0x29BC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X29BC);
    // 0x8002FF2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002FF30: nop

    // 0x8002FF34: swc1        $f8, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f8.u32l;
    // 0x8002FF38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002FF3C: lw          $t5, 0x29BC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X29BC);
    // 0x8002FF40: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x8002FF44: sh          $t4, 0x100($t5)
    MEM_H(0X100, ctx->r13) = ctx->r12;
    // 0x8002FF48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002FF4C: lw          $t6, 0x29BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X29BC);
    // 0x8002FF50: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8002FF54: sh          $t8, 0x102($t6)
    MEM_H(0X102, ctx->r14) = ctx->r24;
    // 0x8002FF58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002FF5C: lw          $t9, 0x29BC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X29BC);
    // 0x8002FF60: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8002FF64: sh          $t7, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r15;
    // 0x8002FF68: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002FF6C: lw          $t1, 0x29BC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X29BC);
    // 0x8002FF70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002FF74: sh          $t2, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r10;
    // 0x8002FF78: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002FF7C: lw          $t0, 0x29BC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X29BC);
    // 0x8002FF80: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8002FF84: addiu       $t3, $t3, -0x44B8
    ctx->r11 = ADD32(ctx->r11, -0X44B8);
    // 0x8002FF88: sw          $t3, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r11;
    // 0x8002FF8C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002FF90: lw          $t4, 0x70E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70E8);
    // 0x8002FF94: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8002FF98: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8002FF9C: sltu        $at, $t4, $at
    ctx->r1 = ctx->r12 < ctx->r1 ? 1 : 0;
    // 0x8002FFA0: bne         $at, $zero, L_8002FFB4
    if (ctx->r1 != 0) {
        // 0x8002FFA4: sw          $t4, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r12;
            goto L_8002FFB4;
    }
    // 0x8002FFA4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x8002FFA8: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8002FFAC: ori         $t5, $t5, 0x869F
    ctx->r13 = ctx->r13 | 0X869F;
    // 0x8002FFB0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
L_8002FFB4:
    // 0x8002FFB4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002FFB8: lw          $t8, 0x29BC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X29BC);
    // 0x8002FFBC: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8002FFC0: lw          $a1, 0x128($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X128);
    // 0x8002FFC4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002FFC8: jal         0x8002D798
    // 0x8002FFCC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_8002D798(rdram, ctx);
        goto after_35;
    // 0x8002FFCC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_35:
    // 0x8002FFD0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8002FFD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002FFD8: sw          $t6, 0x25D4($at)
    MEM_W(0X25D4, ctx->r1) = ctx->r14;
    // 0x8002FFDC: jal         0x800BC6EC
    // 0x8002FFE0: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_36;
    // 0x8002FFE0: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_36:
    // 0x8002FFE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002FFE8: sw          $v0, 0x49C4($at)
    MEM_W(0X49C4, ctx->r1) = ctx->r2;
    // 0x8002FFEC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002FFF0: lw          $a0, 0x49C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X49C4);
    // 0x8002FFF4: jal         0x80099E2C
    // 0x8002FFF8: nop

    func_80099E2C(rdram, ctx);
        goto after_37;
    // 0x8002FFF8: nop

    after_37:
    // 0x8002FFFC: jal         0x800BC6EC
    // 0x80030000: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_38;
    // 0x80030000: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_38:
    // 0x80030004: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80030008: lw          $t7, 0x49C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X49C4);
    // 0x8003000C: nop

    // 0x80030010: sw          $v0, 0x128($t7)
    MEM_W(0X128, ctx->r15) = ctx->r2;
    // 0x80030014: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80030018: lw          $t2, 0x49C4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X49C4);
    // 0x8003001C: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x80030020: sw          $t9, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r25;
    // 0x80030024: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80030028: lw          $t3, 0x49C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X49C4);
    // 0x8003002C: addiu       $t1, $zero, 0xBE
    ctx->r9 = ADD32(0, 0XBE);
    // 0x80030030: sw          $t1, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r9;
    // 0x80030034: lui         $at, 0xC2B0
    ctx->r1 = S32(0XC2B0 << 16);
    // 0x80030038: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8003003C: lw          $t0, 0x49C4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X49C4);
    // 0x80030040: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80030044: nop

    // 0x80030048: swc1        $f10, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f10.u32l;
    // 0x8003004C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80030050: lw          $t5, 0x49C4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X49C4);
    // 0x80030054: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80030058: sh          $t4, 0x100($t5)
    MEM_H(0X100, ctx->r13) = ctx->r12;
    // 0x8003005C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030060: lw          $t6, 0x49C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X49C4);
    // 0x80030064: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80030068: sh          $t8, 0x102($t6)
    MEM_H(0X102, ctx->r14) = ctx->r24;
    // 0x8003006C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80030070: lw          $t9, 0x49C4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X49C4);
    // 0x80030074: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80030078: sh          $t7, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r15;
    // 0x8003007C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80030080: lw          $t1, 0x49C4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X49C4);
    // 0x80030084: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80030088: sh          $t2, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r10;
    // 0x8003008C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80030090: lw          $t0, 0x49C4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X49C4);
    // 0x80030094: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80030098: addiu       $t3, $t3, -0x44B8
    ctx->r11 = ADD32(ctx->r11, -0X44B8);
    // 0x8003009C: sw          $t3, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r11;
    // 0x800300A0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800300A4: lw          $t4, 0x49C4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X49C4);
    // 0x800300A8: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x800300AC: lbu         $a2, 0x7208($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7208);
    // 0x800300B0: lw          $a1, 0x128($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X128);
    // 0x800300B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800300B8: jal         0x8002D798
    // 0x800300BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_8002D798(rdram, ctx);
        goto after_39;
    // 0x800300BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_39:
    // 0x800300C0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800300C4: lbu         $t5, 0x7208($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7208);
    // 0x800300C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800300CC: sh          $t5, 0x25E0($at)
    MEM_H(0X25E0, ctx->r1) = ctx->r13;
    // 0x800300D0: jal         0x800BC6EC
    // 0x800300D4: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_40;
    // 0x800300D4: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_40:
    // 0x800300D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800300DC: sw          $v0, -0x4BBC($at)
    MEM_W(-0X4BBC, ctx->r1) = ctx->r2;
    // 0x800300E0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800300E4: lw          $a0, -0x4BBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BBC);
    // 0x800300E8: jal         0x80099E2C
    // 0x800300EC: nop

    func_80099E2C(rdram, ctx);
        goto after_41;
    // 0x800300EC: nop

    after_41:
    // 0x800300F0: jal         0x800BC6EC
    // 0x800300F4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_42;
    // 0x800300F4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_42:
    // 0x800300F8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800300FC: lw          $t8, -0x4BBC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BBC);
    // 0x80030100: nop

    // 0x80030104: sw          $v0, 0x128($t8)
    MEM_W(0X128, ctx->r24) = ctx->r2;
    // 0x80030108: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8003010C: lw          $t7, -0x4BBC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4BBC);
    // 0x80030110: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x80030114: sw          $t6, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r14;
    // 0x80030118: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8003011C: lw          $t2, -0x4BBC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4BBC);
    // 0x80030120: addiu       $t9, $zero, 0xBF
    ctx->r25 = ADD32(0, 0XBF);
    // 0x80030124: sw          $t9, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r25;
    // 0x80030128: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x8003012C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80030130: lw          $t1, -0x4BBC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4BBC);
    // 0x80030134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80030138: nop

    // 0x8003013C: swc1        $f16, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f16.u32l;
    // 0x80030140: lui         $at, 0x42C6
    ctx->r1 = S32(0X42C6 << 16);
    // 0x80030144: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80030148: lw          $t3, -0x4BBC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4BBC);
    // 0x8003014C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80030150: nop

    // 0x80030154: swc1        $f18, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f18.u32l;
    // 0x80030158: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8003015C: lw          $t4, -0x4BBC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BBC);
    // 0x80030160: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80030164: sh          $t0, 0x100($t4)
    MEM_H(0X100, ctx->r12) = ctx->r8;
    // 0x80030168: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8003016C: lw          $t8, -0x4BBC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BBC);
    // 0x80030170: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80030174: sh          $t5, 0x102($t8)
    MEM_H(0X102, ctx->r24) = ctx->r13;
    // 0x80030178: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8003017C: lw          $t7, -0x4BBC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4BBC);
    // 0x80030180: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80030184: sh          $t6, 0xC4($t7)
    MEM_H(0XC4, ctx->r15) = ctx->r14;
    // 0x80030188: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8003018C: lw          $t2, -0x4BBC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4BBC);
    // 0x80030190: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80030194: sh          $t9, 0x116($t2)
    MEM_H(0X116, ctx->r10) = ctx->r25;
    // 0x80030198: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8003019C: lw          $t3, -0x4BBC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4BBC);
    // 0x800301A0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800301A4: addiu       $t1, $t1, -0x44B8
    ctx->r9 = ADD32(ctx->r9, -0X44B8);
    // 0x800301A8: sw          $t1, 0x138($t3)
    MEM_W(0X138, ctx->r11) = ctx->r9;
    // 0x800301AC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800301B0: lw          $t0, 0x640($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X640);
    // 0x800301B4: nop

    // 0x800301B8: bne         $t0, $zero, L_800301CC
    if (ctx->r8 != 0) {
        // 0x800301BC: nop

            goto L_800301CC;
    }
    // 0x800301BC: nop

    // 0x800301C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800301C4: b           L_800301E4
    // 0x800301C8: sw          $zero, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = 0;
        goto L_800301E4;
    // 0x800301C8: sw          $zero, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = 0;
L_800301CC:
    // 0x800301CC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800301D0: lw          $t4, 0x640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X640);
    // 0x800301D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800301D8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800301DC: nop

    // 0x800301E0: sw          $t5, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r13;
L_800301E4:
    // 0x800301E4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800301E8: lw          $t8, -0x4BBC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BBC);
    // 0x800301EC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800301F0: lw          $a2, -0x4BB8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BB8);
    // 0x800301F4: lw          $a1, 0x128($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X128);
    // 0x800301F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800301FC: jal         0x8002D798
    // 0x80030200: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_8002D798(rdram, ctx);
        goto after_43;
    // 0x80030200: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_43:
    // 0x80030204: jal         0x800BC6EC
    // 0x80030208: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_44;
    // 0x80030208: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_44:
    // 0x8003020C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030210: sw          $v0, 0x2644($at)
    MEM_W(0X2644, ctx->r1) = ctx->r2;
    // 0x80030214: jal         0x800BC6EC
    // 0x80030218: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_45;
    // 0x80030218: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_45:
    // 0x8003021C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030220: sw          $v0, 0x2648($at)
    MEM_W(0X2648, ctx->r1) = ctx->r2;
    // 0x80030224: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030228: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8003022C: jal         0x80099E2C
    // 0x80030230: nop

    func_80099E2C(rdram, ctx);
        goto after_46;
    // 0x80030230: nop

    after_46:
    // 0x80030234: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030238: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8003023C: jal         0x80099E2C
    // 0x80030240: nop

    func_80099E2C(rdram, ctx);
        goto after_47;
    // 0x80030240: nop

    after_47:
    // 0x80030244: jal         0x800BC6EC
    // 0x80030248: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_48;
    // 0x80030248: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_48:
    // 0x8003024C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030250: lw          $t6, 0x2644($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2644);
    // 0x80030254: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80030258: sw          $s0, 0x138($t6)
    MEM_W(0X138, ctx->r14) = ctx->r16;
    // 0x8003025C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80030260: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80030264: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80030268: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x8003026C: addiu       $a2, $a2, 0x3E00
    ctx->r6 = ADD32(ctx->r6, 0X3E00);
    // 0x80030270: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x80030274: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x80030278: jal         0x800BD1FC
    // 0x8003027C: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, 0X200);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_49;
    // 0x8003027C: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, 0X200);
    after_49:
    // 0x80030280: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80030284: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80030288: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8003028C: jal         0x800BD218
    // 0x80030290: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    SysMem_DmaCopy(rdram, ctx);
        goto after_50;
    // 0x80030290: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    after_50:
    // 0x80030294: jal         0x800BC6EC
    // 0x80030298: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_51;
    // 0x80030298: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_51:
    // 0x8003029C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800302A0: lw          $t7, 0x2648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2648);
    // 0x800302A4: nop

    // 0x800302A8: sw          $v0, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r2;
    // 0x800302AC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800302B0: lw          $t9, 0x2648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2648);
    // 0x800302B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800302B8: lw          $a1, 0x138($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X138);
    // 0x800302BC: jal         0x800BD218
    // 0x800302C0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    SysMem_DmaCopy(rdram, ctx);
        goto after_52;
    // 0x800302C0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    after_52:
    // 0x800302C4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800302C8: lw          $t1, 0x2648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2648);
    // 0x800302CC: addiu       $t2, $zero, 0x148
    ctx->r10 = ADD32(0, 0X148);
    // 0x800302D0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800302D4: sw          $t2, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r10;
    // 0x800302D8: lw          $t3, 0x2648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2648);
    // 0x800302DC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800302E0: lw          $t4, 0x2644($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2644);
    // 0x800302E4: lw          $t0, 0xC0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC0);
    // 0x800302E8: nop

    // 0x800302EC: sw          $t0, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r8;
    // 0x800302F0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800302F4: lw          $t8, 0x2648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2648);
    // 0x800302F8: addiu       $t5, $zero, 0xBE
    ctx->r13 = ADD32(0, 0XBE);
    // 0x800302FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030300: sw          $t5, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r13;
    // 0x80030304: lw          $t6, 0x2648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2648);
    // 0x80030308: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003030C: lw          $t9, 0x2644($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2644);
    // 0x80030310: lw          $t7, 0xC8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC8);
    // 0x80030314: nop

    // 0x80030318: sw          $t7, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->r15;
    // 0x8003031C: lui         $at, 0xC2CE
    ctx->r1 = S32(0XC2CE << 16);
    // 0x80030320: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80030324: lw          $t2, 0x2644($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2644);
    // 0x80030328: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003032C: nop

    // 0x80030330: swc1        $f4, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f4.u32l;
    // 0x80030334: lui         $at, 0x42DE
    ctx->r1 = S32(0X42DE << 16);
    // 0x80030338: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003033C: lw          $t1, 0x2644($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2644);
    // 0x80030340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80030344: nop

    // 0x80030348: swc1        $f6, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f6.u32l;
    // 0x8003034C: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80030350: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80030354: lw          $t3, 0x2648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2648);
    // 0x80030358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003035C: nop

    // 0x80030360: swc1        $f8, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f8.u32l;
    // 0x80030364: lui         $at, 0x42DE
    ctx->r1 = S32(0X42DE << 16);
    // 0x80030368: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8003036C: lw          $t0, 0x2648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2648);
    // 0x80030370: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80030374: nop

    // 0x80030378: swc1        $f10, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f10.u32l;
    // 0x8003037C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80030380: lw          $t5, 0x2644($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2644);
    // 0x80030384: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80030388: sh          $t4, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r12;
    // 0x8003038C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80030390: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030394: sh          $t8, 0x25AC($at)
    MEM_H(0X25AC, ctx->r1) = ctx->r24;
    // 0x80030398: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003039C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800303A0: sh          $t6, 0x25A4($at)
    MEM_H(0X25A4, ctx->r1) = ctx->r14;
    // 0x800303A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800303A8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800303AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800303B0: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x800303B4: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x800303B8: jal         0x8002D3B0
    // 0x800303BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8002D3B0(rdram, ctx);
        goto after_53;
    // 0x800303BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_53:
    // 0x800303C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800303C4: sh          $v0, 0x25A4($at)
    MEM_H(0X25A4, ctx->r1) = ctx->r2;
    // 0x800303C8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x800303CC: lhu         $t9, -0x6504($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X6504);
    // 0x800303D0: nop

    // 0x800303D4: andi        $t2, $t9, 0x4
    ctx->r10 = ctx->r25 & 0X4;
    // 0x800303D8: beq         $t2, $zero, L_800303EC
    if (ctx->r10 == 0) {
        // 0x800303DC: nop

            goto L_800303EC;
    }
    // 0x800303DC: nop

    // 0x800303E0: addiu       $t1, $zero, 0x3E7
    ctx->r9 = ADD32(0, 0X3E7);
    // 0x800303E4: b           L_80030404
    // 0x800303E8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
        goto L_80030404;
    // 0x800303E8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
L_800303EC:
    // 0x800303EC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800303F0: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x800303F4: nop

    // 0x800303F8: lh          $t0, 0x2($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X2);
    // 0x800303FC: nop

    // 0x80030400: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
L_80030404:
    // 0x80030404: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030408: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8003040C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80030410: jal         0x8002D3B0
    // 0x80030414: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8002D3B0(rdram, ctx);
        goto after_54;
    // 0x80030414: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_54:
    // 0x80030418: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003041C: sh          $v0, 0x25AC($at)
    MEM_H(0X25AC, ctx->r1) = ctx->r2;
    // 0x80030420: b           L_80030428
    // 0x80030424: nop

        goto L_80030428;
    // 0x80030424: nop

L_80030428:
    // 0x80030428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003042C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80030430: jr          $ra
    // 0x80030434: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80030434: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80030438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030438: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8003043C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80030440: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80030444: beq         $a0, $zero, L_80030454
    if (ctx->r4 == 0) {
        // 0x80030448: nop

            goto L_80030454;
    }
    // 0x80030448: nop

    // 0x8003044C: bne         $a1, $a2, L_8003045C
    if (ctx->r5 != ctx->r6) {
        // 0x80030450: nop

            goto L_8003045C;
    }
    // 0x80030450: nop

L_80030454:
    // 0x80030454: b           L_8003059C
    // 0x80030458: nop

        goto L_8003059C;
    // 0x80030458: nop

L_8003045C:
    // 0x8003045C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80030460: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80030464: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80030468: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003046C: beq         $at, $zero, L_80030500
    if (ctx->r1 == 0) {
        // 0x80030470: nop

            goto L_80030500;
    }
    // 0x80030470: nop

    // 0x80030474: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80030478: nop

    // 0x8003047C: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x80030480: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80030484: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80030488: nop

    // 0x8003048C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80030490: nop

    // 0x80030494: sh          $t1, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r9;
    // 0x80030498: sh          $a2, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r6;
    // 0x8003049C: lhu         $t2, 0xE($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XE);
    // 0x800304A0: nop

    // 0x800304A4: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800304A8: beq         $at, $zero, L_800304F8
    if (ctx->r1 == 0) {
        // 0x800304AC: nop

            goto L_800304F8;
    }
    // 0x800304AC: nop

L_800304B0:
    // 0x800304B0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800304B4: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800304B8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800304BC: nop

    // 0x800304C0: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x800304C4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800304C8: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800304CC: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x800304D0: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x800304D4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800304D8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800304DC: lhu         $t0, 0xE($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XE);
    // 0x800304E0: nop

    // 0x800304E4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800304E8: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800304EC: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800304F0: bne         $at, $zero, L_800304B0
    if (ctx->r1 != 0) {
        // 0x800304F4: sh          $t1, 0xE($sp)
        MEM_H(0XE, ctx->r29) = ctx->r9;
            goto L_800304B0;
    }
    // 0x800304F4: sh          $t1, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r9;
L_800304F8:
    // 0x800304F8: b           L_80030584
    // 0x800304FC: nop

        goto L_80030584;
    // 0x800304FC: nop

L_80030500:
    // 0x80030500: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80030504: nop

    // 0x80030508: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8003050C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80030510: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x80030514: nop

    // 0x80030518: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8003051C: nop

    // 0x80030520: sh          $t6, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r14;
    // 0x80030524: sh          $a1, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r5;
    // 0x80030528: lhu         $t7, 0xE($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XE);
    // 0x8003052C: nop

    // 0x80030530: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80030534: beq         $at, $zero, L_80030584
    if (ctx->r1 == 0) {
        // 0x80030538: nop

            goto L_80030584;
    }
    // 0x80030538: nop

L_8003053C:
    // 0x8003053C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80030540: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80030544: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80030548: nop

    // 0x8003054C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80030550: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80030554: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80030558: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8003055C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x80030560: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x80030564: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80030568: lhu         $t5, 0xE($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XE);
    // 0x8003056C: nop

    // 0x80030570: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80030574: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80030578: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003057C: bne         $at, $zero, L_8003053C
    if (ctx->r1 != 0) {
        // 0x80030580: sh          $t6, 0xE($sp)
        MEM_H(0XE, ctx->r29) = ctx->r14;
            goto L_8003053C;
    }
    // 0x80030580: sh          $t6, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r14;
L_80030584:
    // 0x80030584: lhu         $t8, 0xC($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XC);
    // 0x80030588: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x8003058C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80030590: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80030594: b           L_8003059C
    // 0x80030598: nop

        goto L_8003059C;
    // 0x80030598: nop

L_8003059C:
    // 0x8003059C: jr          $ra
    // 0x800305A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800305A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800305A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800305A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800305A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800305AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800305B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800305B4: lw          $t6, 0x718C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X718C);
    // 0x800305B8: nop

    // 0x800305BC: beq         $t6, $zero, L_8003083C
    if (ctx->r14 == 0) {
        // 0x800305C0: nop

            goto L_8003083C;
    }
    // 0x800305C0: nop

    // 0x800305C4: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x800305C8: lbu         $t7, -0x6A00($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6A00);
    // 0x800305CC: nop

    // 0x800305D0: beq         $t7, $zero, L_80030600
    if (ctx->r15 == 0) {
        // 0x800305D4: nop

            goto L_80030600;
    }
    // 0x800305D4: nop

    // 0x800305D8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800305DC: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800305E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800305E4: bne         $t8, $at, L_8003083C
    if (ctx->r24 != ctx->r1) {
        // 0x800305E8: nop

            goto L_8003083C;
    }
    // 0x800305E8: nop

    // 0x800305EC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800305F0: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x800305F4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800305F8: bne         $t9, $at, L_8003083C
    if (ctx->r25 != ctx->r1) {
        // 0x800305FC: nop

            goto L_8003083C;
    }
    // 0x800305FC: nop

L_80030600:
    // 0x80030600: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80030604: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80030608: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8003060C: nop

    // 0x80030610: andi        $t2, $t1, 0x400
    ctx->r10 = ctx->r9 & 0X400;
    // 0x80030614: bne         $t2, $zero, L_8003083C
    if (ctx->r10 != 0) {
        // 0x80030618: nop

            goto L_8003083C;
    }
    // 0x80030618: nop

    // 0x8003061C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030620: lwc1        $f4, -0x4BB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BB0);
    // 0x80030624: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80030628: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003062C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80030630: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80030634: nop

    // 0x80030638: bc1f        L_80030650
    if (!c1cs) {
        // 0x8003063C: nop

            goto L_80030650;
    }
    // 0x8003063C: nop

    // 0x80030640: jal         0x800220F4
    // 0x80030644: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800220F4(rdram, ctx);
        goto after_0;
    // 0x80030644: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x80030648: jal         0x800B9000
    // 0x8003064C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8003064C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_1:
L_80030650:
    // 0x80030650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030654: lwc1        $f10, -0x4BB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4BB0);
    // 0x80030658: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003065C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80030660: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030664: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80030668: swc1        $f18, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f18.u32l;
    // 0x8003066C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80030670: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80030674: nop

    // 0x80030678: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8003067C: nop

    // 0x80030680: bc1f        L_80030694
    if (!c1cs) {
        // 0x80030684: nop

            goto L_80030694;
    }
    // 0x80030684: nop

    // 0x80030688: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003068C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030690: swc1        $f6, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f6.u32l;
L_80030694:
    // 0x80030694: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80030698: lw          $t3, 0x718C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X718C);
    // 0x8003069C: nop

    // 0x800306A0: blez        $t3, L_8003074C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800306A4: nop

            goto L_8003074C;
    }
    // 0x800306A4: nop

    // 0x800306A8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800306AC: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x800306B0: nop

    // 0x800306B4: slti        $at, $t4, 0x65
    ctx->r1 = SIGNED(ctx->r12) < 0X65 ? 1 : 0;
    // 0x800306B8: bne         $at, $zero, L_800306E8
    if (ctx->r1 != 0) {
        // 0x800306BC: nop

            goto L_800306E8;
    }
    // 0x800306BC: nop

    // 0x800306C0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800306C4: lw          $t5, 0x718C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X718C);
    // 0x800306C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800306CC: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800306D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800306D4: mflo        $s0
    ctx->r16 = lo;
    // 0x800306D8: subu        $t6, $t5, $s0
    ctx->r14 = SUB32(ctx->r13, ctx->r16);
    // 0x800306DC: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
    // 0x800306E0: b           L_80030744
    // 0x800306E4: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_80030744;
    // 0x800306E4: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_800306E8:
    // 0x800306E8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800306EC: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x800306F0: nop

    // 0x800306F4: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x800306F8: bne         $at, $zero, L_80030720
    if (ctx->r1 != 0) {
        // 0x800306FC: nop

            goto L_80030720;
    }
    // 0x800306FC: nop

    // 0x80030700: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80030704: lw          $t8, 0x718C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X718C);
    // 0x80030708: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8003070C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030710: subu        $t9, $t8, $s0
    ctx->r25 = SUB32(ctx->r24, ctx->r16);
    // 0x80030714: sw          $t9, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r25;
    // 0x80030718: b           L_80030744
    // 0x8003071C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_80030744;
    // 0x8003071C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_80030720:
    // 0x80030720: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80030724: lw          $t0, 0x718C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X718C);
    // 0x80030728: nop

    // 0x8003072C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80030730: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030734: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x80030738: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003073C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030740: swc1        $f8, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f8.u32l;
L_80030744:
    // 0x80030744: b           L_80030824
    // 0x80030748: nop

        goto L_80030824;
    // 0x80030748: nop

L_8003074C:
    // 0x8003074C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80030750: lw          $t1, 0x718C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X718C);
    // 0x80030754: nop

    // 0x80030758: slti        $at, $t1, -0x64
    ctx->r1 = SIGNED(ctx->r9) < -0X64 ? 1 : 0;
    // 0x8003075C: beq         $at, $zero, L_8003078C
    if (ctx->r1 == 0) {
        // 0x80030760: nop

            goto L_8003078C;
    }
    // 0x80030760: nop

    // 0x80030764: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80030768: lw          $t2, 0x718C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X718C);
    // 0x8003076C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80030770: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80030774: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030778: mflo        $s0
    ctx->r16 = lo;
    // 0x8003077C: subu        $t3, $t2, $s0
    ctx->r11 = SUB32(ctx->r10, ctx->r16);
    // 0x80030780: sw          $t3, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r11;
    // 0x80030784: b           L_800307E8
    // 0x80030788: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_800307E8;
    // 0x80030788: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_8003078C:
    // 0x8003078C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80030790: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x80030794: nop

    // 0x80030798: slti        $at, $t4, -0xA
    ctx->r1 = SIGNED(ctx->r12) < -0XA ? 1 : 0;
    // 0x8003079C: beq         $at, $zero, L_800307C4
    if (ctx->r1 == 0) {
        // 0x800307A0: nop

            goto L_800307C4;
    }
    // 0x800307A0: nop

    // 0x800307A4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800307A8: lw          $t5, 0x718C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X718C);
    // 0x800307AC: addiu       $s0, $zero, -0xA
    ctx->r16 = ADD32(0, -0XA);
    // 0x800307B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800307B4: subu        $t6, $t5, $s0
    ctx->r14 = SUB32(ctx->r13, ctx->r16);
    // 0x800307B8: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
    // 0x800307BC: b           L_800307E8
    // 0x800307C0: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_800307E8;
    // 0x800307C0: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_800307C4:
    // 0x800307C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800307C8: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x800307CC: nop

    // 0x800307D0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800307D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800307D8: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x800307DC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800307E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800307E4: swc1        $f10, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f10.u32l;
L_800307E8:
    // 0x800307E8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800307EC: lw          $t8, 0x70E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70E8);
    // 0x800307F0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800307F4: nop

    // 0x800307F8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800307FC: bgtz        $t0, L_80030824
    if (SIGNED(ctx->r8) > 0) {
        // 0x80030800: nop

            goto L_80030824;
    }
    // 0x80030800: nop

    // 0x80030804: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030808: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x8003080C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030810: sw          $zero, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = 0;
    // 0x80030814: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80030818: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003081C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030820: swc1        $f16, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f16.u32l;
L_80030824:
    // 0x80030824: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80030828: lw          $t1, 0x70E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E8);
    // 0x8003082C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80030830: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030834: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80030838: sw          $t3, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r11;
L_8003083C:
    // 0x8003083C: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80030840: lhu         $t4, -0x6504($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6504);
    // 0x80030844: nop

    // 0x80030848: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8003084C: beq         $t5, $zero, L_80030884
    if (ctx->r13 == 0) {
        // 0x80030850: nop

            goto L_80030884;
    }
    // 0x80030850: nop

    // 0x80030854: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80030858: lh          $t6, -0x69F0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X69F0);
    // 0x8003085C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030860: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80030864: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80030868: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003086C: bgez        $t9, L_8003087C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80030870: sh          $t7, -0x69F0($at)
        MEM_H(-0X69F0, ctx->r1) = ctx->r15;
            goto L_8003087C;
    }
    // 0x80030870: sh          $t7, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r15;
    // 0x80030874: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030878: sh          $zero, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = 0;
L_8003087C:
    // 0x8003087C: b           L_800308B8
    // 0x80030880: nop

        goto L_800308B8;
    // 0x80030880: nop

L_80030884:
    // 0x80030884: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80030888: lh          $t0, -0x69F0($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X69F0);
    // 0x8003088C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030890: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x80030894: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80030898: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8003089C: sh          $t1, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r9;
    // 0x800308A0: slti        $at, $t3, 0x1B
    ctx->r1 = SIGNED(ctx->r11) < 0X1B ? 1 : 0;
    // 0x800308A4: bne         $at, $zero, L_800308B8
    if (ctx->r1 != 0) {
        // 0x800308A8: nop

            goto L_800308B8;
    }
    // 0x800308A8: nop

    // 0x800308AC: addiu       $t4, $zero, 0x1A
    ctx->r12 = ADD32(0, 0X1A);
    // 0x800308B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800308B4: sh          $t4, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r12;
L_800308B8:
    // 0x800308B8: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x800308BC: lhu         $t5, -0x6504($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X6504);
    // 0x800308C0: nop

    // 0x800308C4: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x800308C8: beq         $t6, $zero, L_80030900
    if (ctx->r14 == 0) {
        // 0x800308CC: nop

            goto L_80030900;
    }
    // 0x800308CC: nop

    // 0x800308D0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x800308D4: lh          $t7, -0x6558($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6558);
    // 0x800308D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800308DC: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800308E0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800308E4: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800308E8: blez        $t0, L_800308F8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800308EC: sh          $t8, -0x6558($at)
        MEM_H(-0X6558, ctx->r1) = ctx->r24;
            goto L_800308F8;
    }
    // 0x800308EC: sh          $t8, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r24;
    // 0x800308F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800308F4: sh          $zero, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = 0;
L_800308F8:
    // 0x800308F8: b           L_80030934
    // 0x800308FC: nop

        goto L_80030934;
    // 0x800308FC: nop

L_80030900:
    // 0x80030900: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x80030904: lh          $t1, -0x6558($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6558);
    // 0x80030908: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003090C: addiu       $t2, $t1, -0x2
    ctx->r10 = ADD32(ctx->r9, -0X2);
    // 0x80030910: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80030914: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80030918: sh          $t2, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r10;
    // 0x8003091C: slti        $at, $t4, -0x21
    ctx->r1 = SIGNED(ctx->r12) < -0X21 ? 1 : 0;
    // 0x80030920: beq         $at, $zero, L_80030934
    if (ctx->r1 == 0) {
        // 0x80030924: nop

            goto L_80030934;
    }
    // 0x80030924: nop

    // 0x80030928: addiu       $t5, $zero, -0x21
    ctx->r13 = ADD32(0, -0X21);
    // 0x8003092C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030930: sh          $t5, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r13;
L_80030934:
    // 0x80030934: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030938: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x8003093C: nop

    // 0x80030940: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x80030944: bne         $at, $zero, L_80030A58
    if (ctx->r1 != 0) {
        // 0x80030948: nop

            goto L_80030A58;
    }
    // 0x80030948: nop

    // 0x8003094C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80030950: lbu         $t7, -0x6A00($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6A00);
    // 0x80030954: nop

    // 0x80030958: beq         $t7, $zero, L_80030A58
    if (ctx->r15 == 0) {
        // 0x8003095C: nop

            goto L_80030A58;
    }
    // 0x8003095C: nop

    // 0x80030960: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80030964: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80030968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003096C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80030970: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030974: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80030978: lwc1        $f8, -0x4BB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x8003097C: nop

    // 0x80030980: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80030984: swc1        $f10, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f10.u32l;
    // 0x80030988: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8003098C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80030990: nop

    // 0x80030994: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80030998: nop

    // 0x8003099C: bc1f        L_800309B4
    if (!c1cs) {
        // 0x800309A0: nop

            goto L_800309B4;
    }
    // 0x800309A0: nop

    // 0x800309A4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800309A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800309AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800309B0: swc1        $f18, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f18.u32l;
L_800309B4:
    // 0x800309B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800309B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800309BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800309C0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800309C4: lwc1        $f4, -0x4BB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x800309C8: nop

    // 0x800309CC: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800309D0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800309D4: nop

    // 0x800309D8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800309DC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800309E0: beq         $t9, $zero, L_80030A34
    if (ctx->r25 == 0) {
        // 0x800309E4: nop

            goto L_80030A34;
    }
    // 0x800309E4: nop

    // 0x800309E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800309EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800309F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800309F4: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800309F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800309FC: nop

    // 0x80030A00: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80030A04: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80030A08: nop

    // 0x80030A0C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80030A10: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80030A14: bne         $t9, $zero, L_80030A2C
    if (ctx->r25 != 0) {
        // 0x80030A18: nop

            goto L_80030A2C;
    }
    // 0x80030A18: nop

    // 0x80030A1C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80030A20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A24: b           L_80030A44
    // 0x80030A28: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80030A44;
    // 0x80030A28: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80030A2C:
    // 0x80030A2C: b           L_80030A44
    // 0x80030A30: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80030A44;
    // 0x80030A30: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80030A34:
    // 0x80030A34: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80030A38: nop

    // 0x80030A3C: bltz        $t9, L_80030A2C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80030A40: nop

            goto L_80030A2C;
    }
    // 0x80030A40: nop

L_80030A44:
    // 0x80030A44: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80030A48: lw          $t1, -0x73D0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73D0);
    // 0x80030A4C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80030A50: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80030A54: sh          $t0, 0x3DE($t1)
    MEM_H(0X3DE, ctx->r9) = ctx->r8;
L_80030A58:
    // 0x80030A58: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80030A5C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80030A60: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80030A64: nop

    // 0x80030A68: sh          $t3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r11;
    // 0x80030A6C: jal         0x800C1754
    // 0x80030A70: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_2;
    // 0x80030A70: nop

    after_2:
    // 0x80030A74: jal         0x8002DC14
    // 0x80030A78: nop

    func_8002DC14(rdram, ctx);
        goto after_3;
    // 0x80030A78: nop

    after_3:
    // 0x80030A7C: jal         0x8002E414
    // 0x80030A80: nop

    func_8002E414(rdram, ctx);
        goto after_4;
    // 0x80030A80: nop

    after_4:
    // 0x80030A84: jal         0x8002ED14
    // 0x80030A88: nop

    func_8002ED14(rdram, ctx);
        goto after_5;
    // 0x80030A88: nop

    after_5:
    // 0x80030A8C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80030A90: lhu         $t4, 0x2518($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X2518);
    // 0x80030A94: nop

    // 0x80030A98: sltiu       $at, $t4, 0x2E
    ctx->r1 = ctx->r12 < 0X2E ? 1 : 0;
    // 0x80030A9C: beq         $at, $zero, L_8003166C
    if (ctx->r1 == 0) {
        // 0x80030AA0: nop

            goto L_8003166C;
    }
    // 0x80030AA0: nop

    // 0x80030AA4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80030AA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80030AAC: addu        $at, $at, $t4
    gpr jr_addend_80030AB8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80030AB0: lw          $t4, -0x182C($at)
    ctx->r12 = ADD32(ctx->r1, -0X182C);
    // 0x80030AB4: nop

    // 0x80030AB8: jr          $t4
    // 0x80030ABC: nop

    switch (jr_addend_80030AB8 >> 2) {
        case 0: goto L_80030AC0; break;
        case 1: goto L_8003166C; break;
        case 2: goto L_8003166C; break;
        case 3: goto L_8003166C; break;
        case 4: goto L_8003166C; break;
        case 5: goto L_8003166C; break;
        case 6: goto L_8003166C; break;
        case 7: goto L_8003166C; break;
        case 8: goto L_8003166C; break;
        case 9: goto L_8003166C; break;
        case 10: goto L_80030AC0; break;
        case 11: goto L_8003166C; break;
        case 12: goto L_8003166C; break;
        case 13: goto L_8003166C; break;
        case 14: goto L_8003166C; break;
        case 15: goto L_8003166C; break;
        case 16: goto L_8003166C; break;
        case 17: goto L_8003166C; break;
        case 18: goto L_8003166C; break;
        case 19: goto L_8003166C; break;
        case 20: goto L_80030AC0; break;
        case 21: goto L_8003166C; break;
        case 22: goto L_8003166C; break;
        case 23: goto L_8003166C; break;
        case 24: goto L_8003166C; break;
        case 25: goto L_8003166C; break;
        case 26: goto L_8003166C; break;
        case 27: goto L_8003166C; break;
        case 28: goto L_8003166C; break;
        case 29: goto L_8003166C; break;
        case 30: goto L_80030AC0; break;
        case 31: goto L_8003166C; break;
        case 32: goto L_8003166C; break;
        case 33: goto L_8003166C; break;
        case 34: goto L_8003166C; break;
        case 35: goto L_80031568; break;
        case 36: goto L_8003166C; break;
        case 37: goto L_8003166C; break;
        case 38: goto L_8003166C; break;
        case 39: goto L_8003166C; break;
        case 40: goto L_80030AC8; break;
        case 41: goto L_8003166C; break;
        case 42: goto L_8003166C; break;
        case 43: goto L_8003166C; break;
        case 44: goto L_8003166C; break;
        case 45: goto L_80030C00; break;
        default: switch_error(__func__, 0x80030AB8, 0x800EE7D4);
    }
    // 0x80030ABC: nop

L_80030AC0:
    // 0x80030AC0: b           L_8003166C
    // 0x80030AC4: nop

        goto L_8003166C;
    // 0x80030AC4: nop

L_80030AC8:
    // 0x80030AC8: jal         0x8002EC90
    // 0x80030ACC: nop

    func_8002EC90(rdram, ctx);
        goto after_6;
    // 0x80030ACC: nop

    after_6:
    // 0x80030AD0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80030AD4: lh          $t5, 0x2570($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2570);
    // 0x80030AD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80030ADC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80030AE0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80030AE4: lw          $t7, 0x79D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X79D0);
    // 0x80030AE8: nop

    // 0x80030AEC: beq         $t7, $zero, L_80030BA8
    if (ctx->r15 == 0) {
        // 0x80030AF0: sw          $t7, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r15;
            goto L_80030BA8;
    }
    // 0x80030AF0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80030AF4: jal         0x8002DA1C
    // 0x80030AF8: nop

    func_8002DA1C(rdram, ctx);
        goto after_7;
    // 0x80030AF8: nop

    after_7:
    // 0x80030AFC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80030B00: lw          $t8, 0x7AE0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AE0);
    // 0x80030B04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B08: sw          $t8, 0x7B48($at)
    MEM_W(0X7B48, ctx->r1) = ctx->r24;
    // 0x80030B0C: jal         0x80090728
    // 0x80030B10: addiu       $a0, $zero, 0x4A0
    ctx->r4 = ADD32(0, 0X4A0);
    func_80090728(rdram, ctx);
        goto after_8;
    // 0x80030B10: addiu       $a0, $zero, 0x4A0
    ctx->r4 = ADD32(0, 0X4A0);
    after_8:
    // 0x80030B14: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80030B18: addiu       $t9, $t9, 0x5B0
    ctx->r25 = ADD32(ctx->r25, 0X5B0);
    // 0x80030B1C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80030B20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80030B24: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80030B28: jal         0x800BD218
    // 0x80030B2C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x80030B2C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_9:
    // 0x80030B30: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030B34: lw          $a0, 0x7AE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7AE0);
    // 0x80030B38: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80030B3C: jal         0x8008ED4C
    // 0x80030B40: nop

    func_8008ED4C(rdram, ctx);
        goto after_10;
    // 0x80030B40: nop

    after_10:
    // 0x80030B44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80030B48: jal         0x8008EAA8
    // 0x80030B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_11;
    // 0x80030B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80030B50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80030B58: sh          $zero, 0x2550($at)
    MEM_H(0X2550, ctx->r1) = 0;
    // 0x80030B5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B60: sb          $zero, 0x2614($at)
    MEM_B(0X2614, ctx->r1) = 0;
    // 0x80030B64: bgez        $zero, L_80030B7C
    if (SIGNED(0) >= 0) {
        // 0x80030B68: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80030B7C;
    }
    // 0x80030B68: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80030B6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80030B70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80030B74: nop

    // 0x80030B78: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80030B7C:
    // 0x80030B7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B80: swc1        $f10, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f10.u32l;
    // 0x80030B84: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80030B88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B8C: sh          $t0, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r8;
    // 0x80030B90: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80030B94: lh          $t1, 0x1B08($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B08);
    // 0x80030B98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030B9C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80030BA0: b           L_80030BF8
    // 0x80030BA4: sh          $t2, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = ctx->r10;
        goto L_80030BF8;
    // 0x80030BA4: sh          $t2, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = ctx->r10;
L_80030BA8:
    // 0x80030BA8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80030BAC: lh          $t3, 0x2580($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2580);
    // 0x80030BB0: nop

    // 0x80030BB4: beq         $t3, $zero, L_80030BF8
    if (ctx->r11 == 0) {
        // 0x80030BB8: nop

            goto L_80030BF8;
    }
    // 0x80030BB8: nop

    // 0x80030BBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030BC0: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x80030BC4: jal         0x8009600C
    // 0x80030BC8: nop

    func_8009600C(rdram, ctx);
        goto after_12;
    // 0x80030BC8: nop

    after_12:
    // 0x80030BCC: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80030BD0: lbu         $t4, -0x6A00($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X6A00);
    // 0x80030BD4: nop

    // 0x80030BD8: beq         $t4, $zero, L_80030BF0
    if (ctx->r12 == 0) {
        // 0x80030BDC: nop

            goto L_80030BF0;
    }
    // 0x80030BDC: nop

    // 0x80030BE0: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x80030BE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030BE8: b           L_80030BF8
    // 0x80030BEC: sh          $t5, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r13;
        goto L_80030BF8;
    // 0x80030BEC: sh          $t5, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r13;
L_80030BF0:
    // 0x80030BF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030BF4: sh          $zero, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = 0;
L_80030BF8:
    // 0x80030BF8: b           L_8003166C
    // 0x80030BFC: nop

        goto L_8003166C;
    // 0x80030BFC: nop

L_80030C00:
    // 0x80030C00: jal         0x8002EC90
    // 0x80030C04: nop

    func_8002EC90(rdram, ctx);
        goto after_13;
    // 0x80030C04: nop

    after_13:
    // 0x80030C08: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030C0C: lh          $t6, 0x2550($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2550);
    // 0x80030C10: nop

    // 0x80030C14: bne         $t6, $zero, L_800313B8
    if (ctx->r14 != 0) {
        // 0x80030C18: nop

            goto L_800313B8;
    }
    // 0x80030C18: nop

    // 0x80030C1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80030C20: lhu         $t8, 0x10F2($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X10F2);
    // 0x80030C24: lhu         $t7, 0x46($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X46);
    // 0x80030C28: nop

    // 0x80030C2C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80030C30: beq         $t9, $zero, L_80030C40
    if (ctx->r25 == 0) {
        // 0x80030C34: nop

            goto L_80030C40;
    }
    // 0x80030C34: nop

    // 0x80030C38: jal         0x80090754
    // 0x80030C3C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_80090754(rdram, ctx);
        goto after_14;
    // 0x80030C3C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_14:
L_80030C40:
    // 0x80030C40: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80030C44: lw          $t0, 0x7B48($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B48);
    // 0x80030C48: nop

    // 0x80030C4C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80030C50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030C54: lw          $a0, 0x69C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X69C8);
    // 0x80030C58: jal         0x8008ECCC
    // 0x80030C5C: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_15;
    // 0x80030C5C: nop

    after_15:
    // 0x80030C60: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80030C64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80030C68: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80030C6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80030C70: jal         0x8008EC8C
    // 0x80030C74: nop

    func_8008EC8C(rdram, ctx);
        goto after_16;
    // 0x80030C74: nop

    after_16:
    // 0x80030C78: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80030C7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80030C80: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80030C84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80030C88: jal         0x8008ECAC
    // 0x80030C8C: nop

    func_8008ECAC(rdram, ctx);
        goto after_17;
    // 0x80030C8C: nop

    after_17:
    // 0x80030C90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030C94: jal         0x80090E58
    // 0x80030C98: addiu       $a0, $a0, 0x7B48
    ctx->r4 = ADD32(ctx->r4, 0X7B48);
    func_80090E58(rdram, ctx);
        goto after_18;
    // 0x80030C98: addiu       $a0, $a0, 0x7B48
    ctx->r4 = ADD32(ctx->r4, 0X7B48);
    after_18:
    // 0x80030C9C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80030CA0: lw          $t1, 0x7B48($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B48);
    // 0x80030CA4: nop

    // 0x80030CA8: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80030CAC: nop

    // 0x80030CB0: bne         $t2, $zero, L_80030CD8
    if (ctx->r10 != 0) {
        // 0x80030CB4: nop

            goto L_80030CD8;
    }
    // 0x80030CB4: nop

    // 0x80030CB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80030CBC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80030CC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80030CC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80030CC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030CCC: sh          $t3, 0x2550($at)
    MEM_H(0X2550, ctx->r1) = ctx->r11;
    // 0x80030CD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030CD4: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
L_80030CD8:
    // 0x80030CD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030CDC: lw          $t6, 0x7B48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B48);
    // 0x80030CE0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80030CE4: nop

    // 0x80030CE8: beq         $t5, $t6, L_800313B0
    if (ctx->r13 == ctx->r14) {
        // 0x80030CEC: nop

            goto L_800313B0;
    }
    // 0x80030CEC: nop

    // 0x80030CF0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80030CF4: lw          $t7, 0x263C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X263C);
    // 0x80030CF8: nop

    // 0x80030CFC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80030D00: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80030D04: lhu         $t8, 0x24FC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X24FC);
    // 0x80030D08: nop

    // 0x80030D0C: beq         $t8, $zero, L_80030D1C
    if (ctx->r24 == 0) {
        // 0x80030D10: nop

            goto L_80030D1C;
    }
    // 0x80030D10: nop

    // 0x80030D14: b           L_80030D20
    // 0x80030D18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80030D20;
    // 0x80030D18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80030D1C:
    // 0x80030D1C: addiu       $s0, $zero, 0xD00
    ctx->r16 = ADD32(0, 0XD00);
L_80030D20:
    // 0x80030D20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80030D24: lw          $t9, 0x7B70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B70);
    // 0x80030D28: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80030D2C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80030D30: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80030D34: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80030D38: nop

    // 0x80030D3C: sw          $t1, 0x128($t2)
    MEM_W(0X128, ctx->r10) = ctx->r9;
    // 0x80030D40: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80030D44: nop

    // 0x80030D48: addiu       $t4, $t3, 0x160
    ctx->r12 = ADD32(ctx->r11, 0X160);
    // 0x80030D4C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80030D50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80030D54: lhu         $t5, 0x24FC($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X24FC);
    // 0x80030D58: nop

    // 0x80030D5C: beq         $t5, $zero, L_80030D6C
    if (ctx->r13 == 0) {
        // 0x80030D60: nop

            goto L_80030D6C;
    }
    // 0x80030D60: nop

    // 0x80030D64: b           L_80030D70
    // 0x80030D68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80030D70;
    // 0x80030D68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80030D6C:
    // 0x80030D6C: addiu       $s0, $zero, 0x680
    ctx->r16 = ADD32(0, 0X680);
L_80030D70:
    // 0x80030D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030D74: lw          $t6, 0x7BBC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7BBC);
    // 0x80030D78: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80030D7C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80030D80: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80030D84: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80030D88: nop

    // 0x80030D8C: sw          $t8, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r24;
    // 0x80030D90: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80030D94: nop

    // 0x80030D98: addiu       $t1, $t0, 0x160
    ctx->r9 = ADD32(ctx->r8, 0X160);
    // 0x80030D9C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80030DA0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80030DA4: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x80030DA8: nop

    // 0x80030DAC: beq         $t2, $zero, L_80030DBC
    if (ctx->r10 == 0) {
        // 0x80030DB0: nop

            goto L_80030DBC;
    }
    // 0x80030DB0: nop

    // 0x80030DB4: b           L_80030DC0
    // 0x80030DB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80030DC0;
    // 0x80030DB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80030DBC:
    // 0x80030DBC: addiu       $s0, $zero, 0x4E0
    ctx->r16 = ADD32(0, 0X4E0);
L_80030DC0:
    // 0x80030DC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80030DC4: lw          $t3, 0x7BD8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7BD8);
    // 0x80030DC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80030DCC: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80030DD0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80030DD4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80030DD8: nop

    // 0x80030DDC: sw          $t5, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r13;
    // 0x80030DE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80030DE4: lw          $t7, 0x69C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69C8);
    // 0x80030DE8: nop

    // 0x80030DEC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80030DF0: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
L_80030DF4:
    // 0x80030DF4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030DF8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80030DFC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80030E00: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80030E04: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80030E08: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80030E0C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030E10: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80030E14: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030E18: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030E1C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80030E20: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80030E24: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030E28: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80030E2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80030E30: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80030E34: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80030E38: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80030E3C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030E40: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80030E44: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030E48: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030E4C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80030E50: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80030E54: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030E58: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80030E5C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80030E60: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80030E64: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80030E68: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80030E6C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030E70: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80030E74: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030E78: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030E7C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80030E80: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80030E84: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030E88: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80030E8C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80030E90: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80030E94: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80030E98: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80030E9C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030EA0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80030EA4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030EA8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030EAC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80030EB0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80030EB4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030EB8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80030EBC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80030EC0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80030EC4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80030EC8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80030ECC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030ED0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80030ED4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030ED8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030EDC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80030EE0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80030EE4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030EE8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80030EEC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80030EF0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80030EF4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80030EF8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80030EFC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030F00: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80030F04: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030F08: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030F0C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80030F10: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80030F14: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030F18: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80030F1C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80030F20: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80030F24: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80030F28: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80030F2C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030F30: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80030F34: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030F38: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030F3C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80030F40: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80030F44: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030F48: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80030F4C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80030F50: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80030F54: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80030F58: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80030F5C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030F60: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80030F64: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030F68: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030F6C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80030F70: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80030F74: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030F78: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80030F7C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80030F80: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80030F84: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80030F88: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80030F8C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030F90: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80030F94: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030F98: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030F9C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80030FA0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80030FA4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030FA8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80030FAC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80030FB0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80030FB4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80030FB8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80030FBC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030FC0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80030FC4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030FC8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030FCC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80030FD0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80030FD4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030FD8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80030FDC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80030FE0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80030FE4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80030FE8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80030FEC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030FF0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80030FF4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030FF8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030FFC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80031000: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80031004: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80031008: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8003100C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80031010: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80031014: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80031018: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8003101C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031020: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80031024: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80031028: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003102C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80031030: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031034: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031038: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8003103C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031040: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031044: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031048: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003104C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031050: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80031054: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031058: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003105C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80031060: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031064: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031068: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8003106C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031070: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031074: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031078: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003107C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031080: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80031084: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031088: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003108C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80031090: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031094: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031098: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8003109C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800310A0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800310A4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800310A8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800310AC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800310B0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800310B4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800310B8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800310BC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800310C0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800310C4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800310C8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800310CC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800310D0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800310D4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800310D8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800310DC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800310E0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800310E4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800310E8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800310EC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800310F0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800310F4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800310F8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800310FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80031100: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80031104: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80031108: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8003110C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031110: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80031114: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80031118: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003111C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80031120: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031124: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031128: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8003112C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031130: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031134: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031138: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003113C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031140: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80031144: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031148: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003114C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80031150: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031154: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031158: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8003115C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031160: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031164: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031168: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003116C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031170: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80031174: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031178: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003117C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80031180: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031184: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031188: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003118C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80031190: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80031194: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80031198: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8003119C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800311A0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800311A4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800311A8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800311AC: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800311B0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800311B4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800311B8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800311BC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800311C0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800311C4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800311C8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800311CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800311D0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800311D4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800311D8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800311DC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800311E0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800311E4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800311E8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800311EC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800311F0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800311F4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800311F8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800311FC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031200: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80031204: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80031208: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003120C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80031210: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031214: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031218: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8003121C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031220: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031224: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031228: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003122C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031230: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80031234: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031238: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003123C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80031240: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031244: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031248: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8003124C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031250: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031254: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031258: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003125C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031260: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80031264: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031268: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003126C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80031270: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031274: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031278: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8003127C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80031280: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80031284: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80031288: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8003128C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80031290: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80031294: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80031298: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8003129C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800312A0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800312A4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800312A8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800312AC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800312B0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800312B4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800312B8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800312BC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800312C0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800312C4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800312C8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800312CC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800312D0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800312D4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800312D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800312DC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800312E0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800312E4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800312E8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800312EC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800312F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800312F4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800312F8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800312FC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80031300: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031304: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031308: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8003130C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031310: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031314: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031318: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003131C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031320: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80031324: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031328: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003132C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80031330: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031334: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031338: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8003133C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031340: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031344: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031348: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003134C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031350: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80031354: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031358: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003135C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80031360: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031364: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031368: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8003136C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80031370: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80031374: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80031378: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8003137C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80031380: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80031384: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80031388: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8003138C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80031390: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80031394: lhu         $t8, 0x4A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4A);
    // 0x80031398: nop

    // 0x8003139C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800313A0: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x800313A4: slti        $at, $t0, 0x1A
    ctx->r1 = SIGNED(ctx->r8) < 0X1A ? 1 : 0;
    // 0x800313A8: bne         $at, $zero, L_80030DF4
    if (ctx->r1 != 0) {
        // 0x800313AC: sh          $t9, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r25;
            goto L_80030DF4;
    }
    // 0x800313AC: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
L_800313B0:
    // 0x800313B0: b           L_800314A4
    // 0x800313B4: nop

        goto L_800314A4;
    // 0x800313B4: nop

L_800313B8:
    // 0x800313B8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800313BC: lbu         $t2, 0x25EC($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X25EC);
    // 0x800313C0: nop

    // 0x800313C4: bne         $t2, $zero, L_800313F0
    if (ctx->r10 != 0) {
        // 0x800313C8: nop

            goto L_800313F0;
    }
    // 0x800313C8: nop

    // 0x800313CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800313D0: lwc1        $f8, 0x2530($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x800313D4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800313D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800313DC: nop

    // 0x800313E0: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x800313E4: nop

    // 0x800313E8: bc1f        L_800314A4
    if (!c1cs) {
        // 0x800313EC: nop

            goto L_800314A4;
    }
    // 0x800313EC: nop

L_800313F0:
    // 0x800313F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800313F4: lwc1        $f16, 0x2530($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x800313F8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800313FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031400: nop

    // 0x80031404: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x80031408: nop

    // 0x8003140C: bc1t        L_80031444
    if (c1cs) {
        // 0x80031410: nop

            goto L_80031444;
    }
    // 0x80031410: nop

    // 0x80031414: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80031418: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8003141C: lhu         $t3, 0x46($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X46);
    // 0x80031420: nop

    // 0x80031424: and         $t4, $t3, $t1
    ctx->r12 = ctx->r11 & ctx->r9;
    // 0x80031428: beq         $t4, $zero, L_80031488
    if (ctx->r12 == 0) {
        // 0x8003142C: nop

            goto L_80031488;
    }
    // 0x8003142C: nop

    // 0x80031430: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80031434: lbu         $t5, -0x69F8($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X69F8);
    // 0x80031438: nop

    // 0x8003143C: bne         $t5, $zero, L_80031488
    if (ctx->r13 != 0) {
        // 0x80031440: nop

            goto L_80031488;
    }
    // 0x80031440: nop

L_80031444:
    // 0x80031444: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031448: lh          $t6, 0x2570($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2570);
    // 0x8003144C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031450: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031454: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80031458: sw          $zero, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = 0;
    // 0x8003145C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80031460: lh          $t8, 0x2570($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2570);
    // 0x80031464: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031468: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003146C: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x80031470: sh          $t0, 0x2570($at)
    MEM_H(0X2570, ctx->r1) = ctx->r8;
    // 0x80031474: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80031478: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003147C: sh          $t2, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r10;
    // 0x80031480: b           L_8003166C
    // 0x80031484: nop

        goto L_8003166C;
    // 0x80031484: nop

L_80031488:
    // 0x80031488: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003148C: lwc1        $f18, 0x2530($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x80031490: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031494: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80031498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003149C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800314A0: swc1        $f8, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f8.u32l;
L_800314A4:
    // 0x800314A4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800314A8: lbu         $t3, 0x2614($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X2614);
    // 0x800314AC: nop

    // 0x800314B0: beq         $t3, $zero, L_80031554
    if (ctx->r11 == 0) {
        // 0x800314B4: nop

            goto L_80031554;
    }
    // 0x800314B4: nop

    // 0x800314B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800314BC: lw          $t1, 0x263C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X263C);
    // 0x800314C0: nop

    // 0x800314C4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800314C8: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
L_800314CC:
    // 0x800314CC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800314D0: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800314D4: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x800314D8: nop

    // 0x800314DC: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800314E0: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x800314E4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800314E8: lw          $t9, -0x73D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73D0);
    // 0x800314EC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800314F0: lw          $t0, 0x380($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X380);
    // 0x800314F4: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x800314F8: andi        $t2, $t0, 0x200
    ctx->r10 = ctx->r8 & 0X200;
    // 0x800314FC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x80031500: sw          $t3, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r11;
    // 0x80031504: jal         0x800C1850
    // 0x80031508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_19;
    // 0x80031508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x8003150C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80031510: jal         0x8009A14C
    // 0x80031514: nop

    func_8009A14C(rdram, ctx);
        goto after_20;
    // 0x80031514: nop

    after_20:
    // 0x80031518: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8003151C: nop

    // 0x80031520: addiu       $t5, $t1, 0x160
    ctx->r13 = ADD32(ctx->r9, 0X160);
    // 0x80031524: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80031528: jal         0x800997D8
    // 0x8003152C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800997D8(rdram, ctx);
        goto after_21;
    // 0x8003152C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_21:
    // 0x80031530: lhu         $t6, 0x4A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4A);
    // 0x80031534: nop

    // 0x80031538: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8003153C: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x80031540: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80031544: bne         $at, $zero, L_800314CC
    if (ctx->r1 != 0) {
        // 0x80031548: sh          $t4, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r12;
            goto L_800314CC;
    }
    // 0x80031548: sh          $t4, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r12;
    // 0x8003154C: b           L_80031560
    // 0x80031550: nop

        goto L_80031560;
    // 0x80031550: nop

L_80031554:
    // 0x80031554: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80031558: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003155C: sb          $t0, 0x2614($at)
    MEM_B(0X2614, ctx->r1) = ctx->r8;
L_80031560:
    // 0x80031560: b           L_8003166C
    // 0x80031564: nop

        goto L_8003166C;
    // 0x80031564: nop

L_80031568:
    // 0x80031568: jal         0x8002EC90
    // 0x8003156C: nop

    func_8002EC90(rdram, ctx);
        goto after_22;
    // 0x8003156C: nop

    after_22:
    // 0x80031570: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80031574: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80031578: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003157C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80031580: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80031584: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80031588: lwc1        $f18, -0x4BB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x8003158C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80031590: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80031594: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80031598: swc1        $f4, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f4.u32l;
    // 0x8003159C: bc1f        L_800315C0
    if (!c1cs) {
        // 0x800315A0: nop

            goto L_800315C0;
    }
    // 0x800315A0: nop

    // 0x800315A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800315A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800315AC: swc1        $f6, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f6.u32l;
    // 0x800315B0: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x800315B4: lbu         $t8, -0x6A00($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X6A00);
    // 0x800315B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800315BC: sh          $t8, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r24;
L_800315C0:
    // 0x800315C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800315C4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800315C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800315CC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800315D0: lwc1        $f16, -0x4BB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x800315D4: nop

    // 0x800315D8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800315DC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800315E0: nop

    // 0x800315E4: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800315E8: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800315EC: beq         $t3, $zero, L_80031640
    if (ctx->r11 == 0) {
        // 0x800315F0: nop

            goto L_80031640;
    }
    // 0x800315F0: nop

    // 0x800315F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800315F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800315FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80031600: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80031604: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80031608: nop

    // 0x8003160C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80031610: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80031614: nop

    // 0x80031618: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x8003161C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80031620: bne         $t3, $zero, L_80031638
    if (ctx->r11 != 0) {
        // 0x80031624: nop

            goto L_80031638;
    }
    // 0x80031624: nop

    // 0x80031628: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8003162C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80031630: b           L_80031650
    // 0x80031634: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80031650;
    // 0x80031634: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80031638:
    // 0x80031638: b           L_80031650
    // 0x8003163C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80031650;
    // 0x8003163C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80031640:
    // 0x80031640: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80031644: nop

    // 0x80031648: bltz        $t3, L_80031638
    if (SIGNED(ctx->r11) < 0) {
        // 0x8003164C: nop

            goto L_80031638;
    }
    // 0x8003164C: nop

L_80031650:
    // 0x80031650: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80031654: lw          $t1, -0x73D0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73D0);
    // 0x80031658: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003165C: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x80031660: sh          $t7, 0x3DE($t1)
    MEM_H(0X3DE, ctx->r9) = ctx->r15;
    // 0x80031664: b           L_8003166C
    // 0x80031668: nop

        goto L_8003166C;
    // 0x80031668: nop

L_8003166C:
    // 0x8003166C: jal         0x800C1A28
    // 0x80031670: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_23;
    // 0x80031670: nop

    after_23:
    // 0x80031674: b           L_8003167C
    // 0x80031678: nop

        goto L_8003167C;
    // 0x80031678: nop

L_8003167C:
    // 0x8003167C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031684: jr          $ra
    // 0x80031688: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80031688: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8003168C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003168C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031690: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031694: nop

    // 0x80031698: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8003169C: bne         $at, $zero, L_800316AC
    if (ctx->r1 != 0) {
        // 0x800316A0: nop

            goto L_800316AC;
    }
    // 0x800316A0: nop

    // 0x800316A4: jr          $ra
    // 0x800316A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800316A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800316AC:
    // 0x800316AC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800316B0: lh          $t7, 0x664($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X664);
    // 0x800316B4: nop

    // 0x800316B8: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x800316BC: bne         $at, $zero, L_800316CC
    if (ctx->r1 != 0) {
        // 0x800316C0: nop

            goto L_800316CC;
    }
    // 0x800316C0: nop

    // 0x800316C4: jr          $ra
    // 0x800316C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800316C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800316CC:
    // 0x800316CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800316D0: sh          $zero, 0x2524($at)
    MEM_H(0X2524, ctx->r1) = 0;
    // 0x800316D4: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x800316D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800316DC: sh          $t8, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r24;
    // 0x800316E0: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x800316E4: lbu         $t9, -0x6A00($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6A00);
    // 0x800316E8: nop

    // 0x800316EC: beq         $t9, $zero, L_80031700
    if (ctx->r25 == 0) {
        // 0x800316F0: nop

            goto L_80031700;
    }
    // 0x800316F0: nop

    // 0x800316F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800316F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800316FC: swc1        $f4, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f4.u32l;
L_80031700:
    // 0x80031700: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80031704: sh          $zero, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = 0;
    // 0x80031708: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003170C: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x80031710: jr          $ra
    // 0x80031714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80031718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031718: jr          $ra
    // 0x8003171C: nop

    return;
    // 0x8003171C: nop

    // 0x80031720: jr          $ra
    // 0x80031724: nop

    return;
    // 0x80031724: nop

;}
RECOMP_FUNC void func_80031728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003172C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031730: jal         0x80031AC8
    // 0x80031734: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x80031734: nop

    after_0:
    // 0x80031738: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003173C: bne         $v0, $at, L_8003174C
    if (ctx->r2 != ctx->r1) {
        // 0x80031740: nop

            goto L_8003174C;
    }
    // 0x80031740: nop

    // 0x80031744: b           L_800317D4
    // 0x80031748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800317D4;
    // 0x80031748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003174C:
    // 0x8003174C: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_80031750:
    // 0x80031750: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80031754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031758: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8003175C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80031760: sw          $zero, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = 0;
    // 0x80031764: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x80031768: nop

    // 0x8003176C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80031770: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80031774: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80031778: bne         $at, $zero, L_80031750
    if (ctx->r1 != 0) {
        // 0x8003177C: sh          $t9, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r25;
            goto L_80031750;
    }
    // 0x8003177C: sh          $t9, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r25;
    // 0x80031780: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031784: sh          $zero, 0x2570($at)
    MEM_H(0X2570, ctx->r1) = 0;
    // 0x80031788: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003178C: sh          $zero, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = 0;
    // 0x80031790: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x80031794: lbu         $t1, -0x6A00($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X6A00);
    // 0x80031798: nop

    // 0x8003179C: beq         $t1, $zero, L_800317B4
    if (ctx->r9 == 0) {
        // 0x800317A0: nop

            goto L_800317B4;
    }
    // 0x800317A0: nop

    // 0x800317A4: addiu       $t2, $zero, 0x23
    ctx->r10 = ADD32(0, 0X23);
    // 0x800317A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800317AC: b           L_800317BC
    // 0x800317B0: sh          $t2, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r10;
        goto L_800317BC;
    // 0x800317B0: sh          $t2, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r10;
L_800317B4:
    // 0x800317B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800317B8: sh          $zero, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = 0;
L_800317BC:
    // 0x800317BC: jal         0x8009600C
    // 0x800317C0: nop

    func_8009600C(rdram, ctx);
        goto after_1;
    // 0x800317C0: nop

    after_1:
    // 0x800317C4: b           L_800317D4
    // 0x800317C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800317D4;
    // 0x800317C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800317CC: b           L_800317D4
    // 0x800317D0: nop

        goto L_800317D4;
    // 0x800317D0: nop

L_800317D4:
    // 0x800317D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800317D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800317DC: jr          $ra
    // 0x800317E0: nop

    return;
    // 0x800317E0: nop

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
RECOMP_FUNC void func_80031874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031874: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031878: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x8003187C: nop

    // 0x80031880: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80031884: bne         $at, $zero, L_80031894
    if (ctx->r1 != 0) {
        // 0x80031888: nop

            goto L_80031894;
    }
    // 0x80031888: nop

    // 0x8003188C: jr          $ra
    // 0x80031890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80031890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031894:
    // 0x80031894: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031898: lh          $t7, 0x664($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X664);
    // 0x8003189C: nop

    // 0x800318A0: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x800318A4: bne         $at, $zero, L_800318B4
    if (ctx->r1 != 0) {
        // 0x800318A8: nop

            goto L_800318B4;
    }
    // 0x800318A8: nop

    // 0x800318AC: jr          $ra
    // 0x800318B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800318B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800318B4:
    // 0x800318B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800318B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800318BC: sh          $t8, 0x2524($at)
    MEM_H(0X2524, ctx->r1) = ctx->r24;
    // 0x800318C0: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x800318C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800318C8: sh          $t9, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r25;
    // 0x800318CC: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x800318D0: lbu         $t0, -0x6A00($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6A00);
    // 0x800318D4: nop

    // 0x800318D8: beq         $t0, $zero, L_800318EC
    if (ctx->r8 == 0) {
        // 0x800318DC: nop

            goto L_800318EC;
    }
    // 0x800318DC: nop

    // 0x800318E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800318E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800318E8: swc1        $f4, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f4.u32l;
L_800318EC:
    // 0x800318EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800318F0: sh          $zero, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = 0;
    // 0x800318F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800318F8: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x800318FC: jr          $ra
    // 0x80031900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80031904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031904: jr          $ra
    // 0x80031908: nop

    return;
    // 0x80031908: nop

    // 0x8003190C: jr          $ra
    // 0x80031910: nop

    return;
    // 0x80031910: nop

;}
RECOMP_FUNC void func_80031914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003191C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031920: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031924: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80031928: bne         $t6, $at, L_80031990
    if (ctx->r14 != ctx->r1) {
        // 0x8003192C: nop

            goto L_80031990;
    }
    // 0x8003192C: nop

    // 0x80031930: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031934: lh          $t7, 0x2570($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2570);
    // 0x80031938: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003193C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80031940: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80031944: lw          $t9, 0x79D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79D0);
    // 0x80031948: nop

    // 0x8003194C: bne         $t9, $zero, L_80031990
    if (ctx->r25 != 0) {
        // 0x80031950: nop

            goto L_80031990;
    }
    // 0x80031950: nop

    // 0x80031954: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80031958: lbu         $t0, -0x6A00($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6A00);
    // 0x8003195C: nop

    // 0x80031960: beq         $t0, $zero, L_80031978
    if (ctx->r8 == 0) {
        // 0x80031964: nop

            goto L_80031978;
    }
    // 0x80031964: nop

    // 0x80031968: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x8003196C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031970: b           L_80031980
    // 0x80031974: sh          $t1, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r9;
        goto L_80031980;
    // 0x80031974: sh          $t1, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r9;
L_80031978:
    // 0x80031978: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003197C: sh          $zero, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = 0;
L_80031980:
    // 0x80031980: jal         0x8009600C
    // 0x80031984: nop

    func_8009600C(rdram, ctx);
        goto after_0;
    // 0x80031984: nop

    after_0:
    // 0x80031988: b           L_800319A0
    // 0x8003198C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800319A0;
    // 0x8003198C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031990:
    // 0x80031990: b           L_800319A0
    // 0x80031994: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800319A0;
    // 0x80031994: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80031998: b           L_800319A0
    // 0x8003199C: nop

        goto L_800319A0;
    // 0x8003199C: nop

L_800319A0:
    // 0x800319A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800319A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800319A8: jr          $ra
    // 0x800319AC: nop

    return;
    // 0x800319AC: nop

;}
RECOMP_FUNC void func_800319B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800319B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800319B4: lh          $t6, 0x2524($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2524);
    // 0x800319B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800319BC: bne         $t6, $at, L_800319F8
    if (ctx->r14 != ctx->r1) {
        // 0x800319C0: nop

            goto L_800319F8;
    }
    // 0x800319C0: nop

    // 0x800319C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800319C8: lh          $t7, 0x2518($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2518);
    // 0x800319CC: nop

    // 0x800319D0: slti        $at, $t7, 0x28
    ctx->r1 = SIGNED(ctx->r15) < 0X28 ? 1 : 0;
    // 0x800319D4: bne         $at, $zero, L_800319E8
    if (ctx->r1 != 0) {
        // 0x800319D8: nop

            goto L_800319E8;
    }
    // 0x800319D8: nop

    // 0x800319DC: slti        $at, $t7, 0x2E
    ctx->r1 = SIGNED(ctx->r15) < 0X2E ? 1 : 0;
    // 0x800319E0: bne         $at, $zero, L_800319F8
    if (ctx->r1 != 0) {
        // 0x800319E4: nop

            goto L_800319F8;
    }
    // 0x800319E4: nop

L_800319E8:
    // 0x800319E8: jr          $ra
    // 0x800319EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800319EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800319F0: b           L_80031A54
    // 0x800319F4: nop

        goto L_80031A54;
    // 0x800319F4: nop

L_800319F8:
    // 0x800319F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800319FC: lh          $t8, 0x2524($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2524);
    // 0x80031A00: nop

    // 0x80031A04: bne         $t8, $zero, L_80031A54
    if (ctx->r24 != 0) {
        // 0x80031A08: nop

            goto L_80031A54;
    }
    // 0x80031A08: nop

    // 0x80031A0C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80031A10: lh          $t9, 0x2578($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2578);
    // 0x80031A14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80031A18: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80031A1C: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x80031A20: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80031A24: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80031A28: lw          $t3, 0x79D0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X79D0);
    // 0x80031A2C: nop

    // 0x80031A30: bne         $t3, $zero, L_80031A4C
    if (ctx->r11 != 0) {
        // 0x80031A34: nop

            goto L_80031A4C;
    }
    // 0x80031A34: nop

    // 0x80031A38: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80031A3C: lh          $t4, 0x2518($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2518);
    // 0x80031A40: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80031A44: beq         $t4, $at, L_80031A54
    if (ctx->r12 == ctx->r1) {
        // 0x80031A48: nop

            goto L_80031A54;
    }
    // 0x80031A48: nop

L_80031A4C:
    // 0x80031A4C: jr          $ra
    // 0x80031A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80031A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80031A54:
    // 0x80031A54: beq         $a0, $zero, L_80031A9C
    if (ctx->r4 == 0) {
        // 0x80031A58: nop

            goto L_80031A9C;
    }
    // 0x80031A58: nop

    // 0x80031A5C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80031A60: lh          $t5, 0x2578($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2578);
    // 0x80031A64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031A68: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031A6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80031A70: lh          $t7, 0x2578($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2578);
    // 0x80031A74: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80031A78: sw          $a0, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = ctx->r4;
    // 0x80031A7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031A80: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80031A84: sh          $t8, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = ctx->r24;
    // 0x80031A88: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80031A8C: lh          $t9, 0x2578($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2578);
    // 0x80031A90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031A94: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x80031A98: sh          $t0, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = ctx->r8;
L_80031A9C:
    // 0x80031A9C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80031AA0: lh          $t1, 0x1B08($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B08);
    // 0x80031AA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80031AA8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80031AAC: sh          $t2, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = ctx->r10;
    // 0x80031AB0: jr          $ra
    // 0x80031AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80031AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AB8: jr          $ra
    // 0x80031ABC: nop

    return;
    // 0x80031ABC: nop

    // 0x80031AC0: jr          $ra
    // 0x80031AC4: nop

    return;
    // 0x80031AC4: nop

;}
RECOMP_FUNC void func_80031AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AC8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031ACC: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031AD0: nop

    // 0x80031AD4: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80031AD8: beq         $at, $zero, L_80031AE8
    if (ctx->r1 == 0) {
        // 0x80031ADC: nop

            goto L_80031AE8;
    }
    // 0x80031ADC: nop

    // 0x80031AE0: jr          $ra
    // 0x80031AE4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    return;
    // 0x80031AE4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80031AE8:
    // 0x80031AE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031AEC: lh          $t7, 0x2518($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2518);
    // 0x80031AF0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80031AF4: bne         $t7, $at, L_80031B28
    if (ctx->r15 != ctx->r1) {
        // 0x80031AF8: nop

            goto L_80031B28;
    }
    // 0x80031AF8: nop

    // 0x80031AFC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80031B00: lh          $t8, 0x2570($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2570);
    // 0x80031B04: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80031B08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80031B0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80031B10: lw          $t0, 0x79D0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X79D0);
    // 0x80031B14: nop

    // 0x80031B18: bne         $t0, $zero, L_80031B28
    if (ctx->r8 != 0) {
        // 0x80031B1C: nop

            goto L_80031B28;
    }
    // 0x80031B1C: nop

    // 0x80031B20: jr          $ra
    // 0x80031B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031B28:
    // 0x80031B28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031B2C: lwc1        $f4, 0x2530($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x80031B30: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80031B34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80031B38: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80031B3C: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80031B40: nop

    // 0x80031B44: bc1t        L_80031B54
    if (c1cs) {
        // 0x80031B48: nop

            goto L_80031B54;
    }
    // 0x80031B48: nop

    // 0x80031B4C: jr          $ra
    // 0x80031B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80031B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031B54:
    // 0x80031B54: jr          $ra
    // 0x80031B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80031B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80031B5C: jr          $ra
    // 0x80031B60: nop

    return;
    // 0x80031B60: nop

    // 0x80031B64: jr          $ra
    // 0x80031B68: nop

    return;
    // 0x80031B68: nop

;}
RECOMP_FUNC void func_80031B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031B6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031B70: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x80031B74: nop

    // 0x80031B78: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80031B7C: beq         $at, $zero, L_80031B8C
    if (ctx->r1 == 0) {
        // 0x80031B80: nop

            goto L_80031B8C;
    }
    // 0x80031B80: nop

    // 0x80031B84: jr          $ra
    // 0x80031B88: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    return;
    // 0x80031B88: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80031B8C:
    // 0x80031B8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031B90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031B94: sh          $t7, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = ctx->r15;
    // 0x80031B98: jr          $ra
    // 0x80031B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
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
RECOMP_FUNC void func_80031BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031BB8: jal         0x80031AC8
    // 0x80031BBC: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x80031BBC: nop

    after_0:
    // 0x80031BC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031BC4: bne         $v0, $at, L_80031BE4
    if (ctx->r2 != ctx->r1) {
        // 0x80031BC8: nop

            goto L_80031BE4;
    }
    // 0x80031BC8: nop

    // 0x80031BCC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80031BD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031BD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031BD8: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x80031BDC: b           L_80031BF4
    // 0x80031BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031BF4;
    // 0x80031BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031BE4:
    // 0x80031BE4: b           L_80031BF4
    // 0x80031BE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80031BF4;
    // 0x80031BE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80031BEC: b           L_80031BF4
    // 0x80031BF0: nop

        goto L_80031BF4;
    // 0x80031BF0: nop

L_80031BF4:
    // 0x80031BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031BFC: jr          $ra
    // 0x80031C00: nop

    return;
    // 0x80031C00: nop

;}
RECOMP_FUNC void func_80031C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C04: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80031C08: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80031C0C: lhu         $t6, -0x6504($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6504);
    // 0x80031C10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80031C14: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80031C18: sh          $t7, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r15;
    // 0x80031C1C: jr          $ra
    // 0x80031C20: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    return;
    // 0x80031C20: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
;}
RECOMP_FUNC void func_80031C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C24: jr          $ra
    // 0x80031C28: nop

    return;
    // 0x80031C28: nop

    // 0x80031C2C: jr          $ra
    // 0x80031C30: nop

    return;
    // 0x80031C30: nop

;}
RECOMP_FUNC void func_80031C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80031C38: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80031C3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031C40: lhu         $t6, -0x6504($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6504);
    // 0x80031C44: xor         $t7, $a0, $at
    ctx->r15 = ctx->r4 ^ ctx->r1;
    // 0x80031C48: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80031C4C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80031C50: sh          $t8, -0x6504($at)
    MEM_H(-0X6504, ctx->r1) = ctx->r24;
    // 0x80031C54: jr          $ra
    // 0x80031C58: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    return;
    // 0x80031C58: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
;}
RECOMP_FUNC void func_80031C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C5C: jr          $ra
    // 0x80031C60: nop

    return;
    // 0x80031C60: nop

    // 0x80031C64: jr          $ra
    // 0x80031C68: nop

    return;
    // 0x80031C68: nop

;}
RECOMP_FUNC void func_80031C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C6C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80031C70: lhu         $v0, -0x6504($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6504);
    // 0x80031C74: jr          $ra
    // 0x80031C78: nop

    return;
    // 0x80031C78: nop

    // 0x80031C7C: jr          $ra
    // 0x80031C80: nop

    return;
    // 0x80031C80: nop

    // 0x80031C84: jr          $ra
    // 0x80031C88: nop

    return;
    // 0x80031C88: nop

    // 0x80031C8C: nop

;}
RECOMP_FUNC void func_80031C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80031C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031C98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80031C9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80031CA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80031CA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80031CA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80031CAC: nop

    // 0x80031CB0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80031CB4: bne         $t7, $zero, L_80031D10
    if (ctx->r15 != 0) {
        // 0x80031CB8: nop

            goto L_80031D10;
    }
    // 0x80031CB8: nop

    // 0x80031CBC: jal         0x80004654
    // 0x80031CC0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80004654(rdram, ctx);
        goto after_0;
    // 0x80031CC0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80031CC4: bgez        $v0, L_80031CD4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80031CC8: nop

            goto L_80031CD4;
    }
    // 0x80031CC8: nop

    // 0x80031CCC: b           L_80031D84
    // 0x80031CD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80031D84;
    // 0x80031CD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80031CD4:
    // 0x80031CD4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80031CD8: lw          $t8, 0x6C10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6C10);
    // 0x80031CDC: nop

    // 0x80031CE0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80031CE4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80031CE8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80031CEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80031CF0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80031CF4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80031CF8: andi        $t9, $a1, 0xFF00
    ctx->r25 = ctx->r5 & 0XFF00;
    // 0x80031CFC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80031D00: jal         0x80031E3C
    // 0x80031D04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80031E3C(rdram, ctx);
        goto after_1;
    // 0x80031D04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x80031D08: b           L_80031D84
    // 0x80031D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80031D84;
    // 0x80031D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031D10:
    // 0x80031D10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80031D14: nop

    // 0x80031D18: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x80031D1C: bne         $t2, $zero, L_80031D74
    if (ctx->r10 != 0) {
        // 0x80031D20: nop

            goto L_80031D74;
    }
    // 0x80031D20: nop

    // 0x80031D24: jal         0x800045AC
    // 0x80031D28: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800045AC(rdram, ctx);
        goto after_2;
    // 0x80031D28: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x80031D2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80031D30: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80031D34: nop

    // 0x80031D38: bne         $t3, $zero, L_80031D48
    if (ctx->r11 != 0) {
        // 0x80031D3C: nop

            goto L_80031D48;
    }
    // 0x80031D3C: nop

    // 0x80031D40: b           L_80031D84
    // 0x80031D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031D84;
    // 0x80031D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031D48:
    // 0x80031D48: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80031D4C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80031D50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80031D54: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80031D58: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80031D5C: andi        $t4, $a1, 0xFF00
    ctx->r12 = ctx->r5 & 0XFF00;
    // 0x80031D60: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80031D64: jal         0x80031E3C
    // 0x80031D68: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80031E3C(rdram, ctx);
        goto after_3;
    // 0x80031D68: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x80031D6C: b           L_80031D84
    // 0x80031D70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80031D84;
    // 0x80031D70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80031D74:
    // 0x80031D74: b           L_80031D84
    // 0x80031D78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031D84;
    // 0x80031D78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031D7C: b           L_80031D84
    // 0x80031D80: nop

        goto L_80031D84;
    // 0x80031D80: nop

L_80031D84:
    // 0x80031D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031D88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031D8C: jr          $ra
    // 0x80031D90: nop

    return;
    // 0x80031D90: nop

;}
RECOMP_FUNC void func_80031D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031D94: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80031D98: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80031D9C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80031DA0: sw          $t6, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = ctx->r14;
    // 0x80031DA4: sh          $zero, 0x208($a0)
    MEM_H(0X208, ctx->r4) = 0;
    // 0x80031DA8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80031DAC:
    // 0x80031DAC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80031DB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80031DB4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80031DB8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80031DBC: swc1        $f4, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f4.u32l;
    // 0x80031DC0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80031DC4: nop

    // 0x80031DC8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80031DCC: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80031DD0: lwc1        $f6, 0x1EC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X1EC);
    // 0x80031DD4: addu        $t3, $a0, $t1
    ctx->r11 = ADD32(ctx->r4, ctx->r9);
    // 0x80031DD8: swc1        $f6, 0x1E8($t3)
    MEM_W(0X1E8, ctx->r11) = ctx->f6.u32l;
    // 0x80031DDC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80031DE0: nop

    // 0x80031DE4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80031DE8: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80031DEC: bne         $at, $zero, L_80031DAC
    if (ctx->r1 != 0) {
        // 0x80031DF0: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_80031DAC;
    }
    // 0x80031DF0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80031DF4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80031DF8:
    // 0x80031DF8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80031DFC: nop

    // 0x80031E00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031E04: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80031E08: sw          $zero, 0x20C($t8)
    MEM_W(0X20C, ctx->r24) = 0;
    // 0x80031E0C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80031E10: nop

    // 0x80031E14: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80031E18: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80031E1C: bne         $at, $zero, L_80031DF8
    if (ctx->r1 != 0) {
        // 0x80031E20: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_80031DF8;
    }
    // 0x80031E20: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80031E24: b           L_80031E34
    // 0x80031E28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031E34;
    // 0x80031E28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031E2C: b           L_80031E34
    // 0x80031E30: nop

        goto L_80031E34;
    // 0x80031E30: nop

L_80031E34:
    // 0x80031E34: jr          $ra
    // 0x80031E38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80031E38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_80031FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031FF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80031FF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031FFC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80032000: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80032004: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80032008: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8003200C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80032010:
    // 0x80032010: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80032014: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80032018: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003201C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80032020: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x80032024: nop

    // 0x80032028: beq         $t0, $zero, L_80032070
    if (ctx->r8 == 0) {
        // 0x8003202C: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_80032070;
    }
    // 0x8003202C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80032030: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80032034: nop

    // 0x80032038: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8003203C: nop

    // 0x80032040: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80032044: beq         $t3, $zero, L_80032054
    if (ctx->r11 == 0) {
        // 0x80032048: nop

            goto L_80032054;
    }
    // 0x80032048: nop

    // 0x8003204C: b           L_80032068
    // 0x80032050: nop

        goto L_80032068;
    // 0x80032050: nop

L_80032054:
    // 0x80032054: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80032058: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8003205C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80032060: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80032064: sw          $zero, 0x20C($t6)
    MEM_W(0X20C, ctx->r14) = 0;
L_80032068:
    // 0x80032068: b           L_80032080
    // 0x8003206C: nop

        goto L_80032080;
    // 0x8003206C: nop

L_80032070:
    // 0x80032070: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80032074: nop

    // 0x80032078: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003207C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_80032080:
    // 0x80032080: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80032084: nop

    // 0x80032088: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003208C: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80032090: bne         $at, $zero, L_80032010
    if (ctx->r1 != 0) {
        // 0x80032094: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80032010;
    }
    // 0x80032094: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80032098: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8003209C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800320A0: bne         $t2, $at, L_800320BC
    if (ctx->r10 != ctx->r1) {
        // 0x800320A4: nop

            goto L_800320BC;
    }
    // 0x800320A4: nop

    // 0x800320A8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800320AC: nop

    // 0x800320B0: sw          $zero, 0x1A0($t3)
    MEM_W(0X1A0, ctx->r11) = 0;
    // 0x800320B4: b           L_8003236C
    // 0x800320B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8003236C;
    // 0x800320B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800320BC:
    // 0x800320BC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800320C0: nop

    // 0x800320C4: lw          $t4, 0x1A8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X1A8);
    // 0x800320C8: nop

    // 0x800320CC: andi        $t7, $t4, 0x100
    ctx->r15 = ctx->r12 & 0X100;
    // 0x800320D0: bne         $t7, $zero, L_8003235C
    if (ctx->r15 != 0) {
        // 0x800320D4: nop

            goto L_8003235C;
    }
    // 0x800320D4: nop

    // 0x800320D8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800320DC: nop

    // 0x800320E0: lhu         $t8, 0x208($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X208);
    // 0x800320E4: nop

    // 0x800320E8: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800320EC: beq         $at, $zero, L_8003235C
    if (ctx->r1 == 0) {
        // 0x800320F0: nop

            goto L_8003235C;
    }
    // 0x800320F0: nop

    // 0x800320F4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800320F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800320FC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80032100: lwc1        $f4, 0x1E8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1E8);
    // 0x80032104: nop

    // 0x80032108: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003210C: swc1        $f20, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f20.u32l;
    // 0x80032110: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80032114: nop

    // 0x80032118: lwc1        $f8, 0x1EC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1EC);
    // 0x8003211C: nop

    // 0x80032120: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80032124: nop

    // 0x80032128: bc1f        L_8003235C
    if (!c1cs) {
        // 0x8003212C: nop

            goto L_8003235C;
    }
    // 0x8003212C: nop

    // 0x80032130: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80032134: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80032138: nop

    // 0x8003213C: swc1        $f10, 0x1E8($t1)
    MEM_W(0X1E8, ctx->r9) = ctx->f10.u32l;
    // 0x80032140: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80032144: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80032148: lwc1        $f16, 0x1EC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X1EC);
    // 0x8003214C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80032150: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80032154: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80032158: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8003215C: nop

    // 0x80032160: bc1f        L_8003227C
    if (!c1cs) {
        // 0x80032164: nop

            goto L_8003227C;
    }
    // 0x80032164: nop

    // 0x80032168: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8003216C: nop

    // 0x80032170: lw          $a0, 0x1AC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X1AC);
    // 0x80032174: jal         0x800BB448
    // 0x80032178: nop

    func_800BB448(rdram, ctx);
        goto after_0;
    // 0x80032178: nop

    after_0:
    // 0x8003217C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80032180: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80032184: nop

    // 0x80032188: beq         $t5, $zero, L_8003227C
    if (ctx->r13 == 0) {
        // 0x8003218C: nop

            goto L_8003227C;
    }
    // 0x8003218C: nop

    // 0x80032190: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80032194: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80032198: lhu         $t7, 0x208($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X208);
    // 0x8003219C: lwc1        $f6, 0x1F0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X1F0);
    // 0x800321A0: sll         $t6, $t7, 11
    ctx->r14 = S32(ctx->r15 << 11);
    // 0x800321A4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800321A8: nop

    // 0x800321AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800321B0: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800321B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800321B8: nop

    // 0x800321BC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800321C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800321C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800321C8: nop

    // 0x800321CC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800321D0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800321D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800321D8: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x800321DC: nop

    // 0x800321E0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800321E4: nop

    // 0x800321E8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800321EC: nop

    // 0x800321F0: slti        $at, $t2, 0x1000
    ctx->r1 = SIGNED(ctx->r10) < 0X1000 ? 1 : 0;
    // 0x800321F4: beq         $at, $zero, L_80032208
    if (ctx->r1 == 0) {
        // 0x800321F8: nop

            goto L_80032208;
    }
    // 0x800321F8: nop

    // 0x800321FC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80032200: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x80032204: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
L_80032208:
    // 0x80032208: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003220C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80032210: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003221C: lwc1        $f4, 0x1F4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1F4);
    // 0x80032220: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80032224: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032228: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8003222C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032230: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80032234: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80032238: sb          $t9, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = ctx->r25;
    // 0x8003223C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80032240: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80032244: lhu         $t3, 0x208($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X208);
    // 0x80032248: nop

    // 0x8003224C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80032250: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80032254: sw          $t1, 0x20C($t4)
    MEM_W(0X20C, ctx->r12) = ctx->r9;
    // 0x80032258: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8003225C: nop

    // 0x80032260: lhu         $t6, 0x208($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X208);
    // 0x80032264: nop

    // 0x80032268: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8003226C: sh          $t8, 0x208($t7)
    MEM_H(0X208, ctx->r15) = ctx->r24;
    // 0x80032270: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80032274: jal         0x800BB4B4
    // 0x80032278: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BB4B4(rdram, ctx);
        goto after_1;
    // 0x80032278: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
L_8003227C:
    // 0x8003227C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80032280: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80032284: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80032288: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003228C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032290: lwc1        $f6, 0x1F0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1F0);
    // 0x80032294: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80032298: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8003229C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800322A0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800322A4: bgez        $t3, L_800322B4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800322A8: sra         $t2, $t3, 8
        ctx->r10 = S32(SIGNED(ctx->r11) >> 8);
            goto L_800322B4;
    }
    // 0x800322A8: sra         $t2, $t3, 8
    ctx->r10 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800322AC: addiu       $at, $t3, 0xFF
    ctx->r1 = ADD32(ctx->r11, 0XFF);
    // 0x800322B0: sra         $t2, $at, 8
    ctx->r10 = S32(SIGNED(ctx->r1) >> 8);
L_800322B4:
    // 0x800322B4: subu        $t1, $t5, $t2
    ctx->r9 = SUB32(ctx->r13, ctx->r10);
    // 0x800322B8: bgez        $t1, L_800322C8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800322BC: sra         $t4, $t1, 3
        ctx->r12 = S32(SIGNED(ctx->r9) >> 3);
            goto L_800322C8;
    }
    // 0x800322BC: sra         $t4, $t1, 3
    ctx->r12 = S32(SIGNED(ctx->r9) >> 3);
    // 0x800322C0: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x800322C4: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800322C8:
    // 0x800322C8: blez        $t4, L_800322FC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800322CC: nop

            goto L_800322FC;
    }
    // 0x800322CC: nop

    // 0x800322D0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x800322D4: subu        $t8, $t6, $t2
    ctx->r24 = SUB32(ctx->r14, ctx->r10);
    // 0x800322D8: bgez        $t8, L_800322E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800322DC: sra         $t7, $t8, 3
        ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
            goto L_800322E8;
    }
    // 0x800322DC: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800322E0: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x800322E4: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800322E8:
    // 0x800322E8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800322EC: nop

    // 0x800322F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800322F4: b           L_8003235C
    // 0x800322F8: swc1        $f18, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f18.u32l;
        goto L_8003235C;
    // 0x800322F8: swc1        $f18, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f18.u32l;
L_800322FC:
    // 0x800322FC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80032300: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80032304: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80032308: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003230C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032310: lwc1        $f4, 0x1F0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1F0);
    // 0x80032314: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80032318: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003231C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80032320: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80032324: bgez        $t5, L_80032334
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80032328: sra         $t1, $t5, 8
        ctx->r9 = S32(SIGNED(ctx->r13) >> 8);
            goto L_80032334;
    }
    // 0x80032328: sra         $t1, $t5, 8
    ctx->r9 = S32(SIGNED(ctx->r13) >> 8);
    // 0x8003232C: addiu       $at, $t5, 0xFF
    ctx->r1 = ADD32(ctx->r13, 0XFF);
    // 0x80032330: sra         $t1, $at, 8
    ctx->r9 = S32(SIGNED(ctx->r1) >> 8);
L_80032334:
    // 0x80032334: subu        $t6, $t4, $t1
    ctx->r14 = SUB32(ctx->r12, ctx->r9);
    // 0x80032338: bgez        $t6, L_80032348
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8003233C: sra         $t2, $t6, 3
        ctx->r10 = S32(SIGNED(ctx->r14) >> 3);
            goto L_80032348;
    }
    // 0x8003233C: sra         $t2, $t6, 3
    ctx->r10 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80032340: addiu       $at, $t6, 0x7
    ctx->r1 = ADD32(ctx->r14, 0X7);
    // 0x80032344: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_80032348:
    // 0x80032348: negu        $t8, $t2
    ctx->r24 = SUB32(0, ctx->r10);
    // 0x8003234C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80032350: nop

    // 0x80032354: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80032358: swc1        $f10, 0x1EC($t0)
    MEM_W(0X1EC, ctx->r8) = ctx->f10.u32l;
L_8003235C:
    // 0x8003235C: b           L_8003236C
    // 0x80032360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003236C;
    // 0x80032360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032364: b           L_8003236C
    // 0x80032368: nop

        goto L_8003236C;
    // 0x80032368: nop

L_8003236C:
    // 0x8003236C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032370: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80032374: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80032378: jr          $ra
    // 0x8003237C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003237C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80032380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032380: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80032384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032388: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8003238C: addiu       $t6, $t6, 0x3E30
    ctx->r14 = ADD32(ctx->r14, 0X3E30);
    // 0x80032390: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80032394: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80032398: lw          $t7, 0x6C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C4);
    // 0x8003239C: nop

    // 0x800323A0: bne         $t7, $zero, L_800323BC
    if (ctx->r15 != 0) {
        // 0x800323A4: nop

            goto L_800323BC;
    }
    // 0x800323A4: nop

    // 0x800323A8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800323AC: jal         0x800974C0
    // 0x800323B0: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    func_800974C0(rdram, ctx);
        goto after_0;
    // 0x800323B0: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_0:
    // 0x800323B4: b           L_800323F8
    // 0x800323B8: nop

        goto L_800323F8;
    // 0x800323B8: nop

L_800323BC:
    // 0x800323BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800323C0: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x800323C4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800323C8: jal         0x800C1264
    // 0x800323CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_1;
    // 0x800323CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_800323D0:
    // 0x800323D0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800323D4: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x800323D8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800323DC: jal         0x800C1570
    // 0x800323E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsg(rdram, ctx);
        goto after_2;
    // 0x800323E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800323E4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800323E8: lw          $t8, -0x3788($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3788);
    // 0x800323EC: nop

    // 0x800323F0: bne         $t8, $zero, L_800323D0
    if (ctx->r24 != 0) {
        // 0x800323F4: nop

            goto L_800323D0;
    }
    // 0x800323F4: nop

L_800323F8:
    // 0x800323F8: b           L_80032400
    // 0x800323FC: nop

        goto L_80032400;
    // 0x800323FC: nop

L_80032400:
    // 0x80032400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032404: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80032408: jr          $ra
    // 0x8003240C: nop

    return;
    // 0x8003240C: nop

;}
RECOMP_FUNC void func_80032410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032410: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80032414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80032418: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003241C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032420: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80032424: nop

    // 0x80032428: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8003242C: nop

    // 0x80032430: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x80032434: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80032438: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003243C: lw          $t8, 0x258C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X258C);
    // 0x80032440: nop

    // 0x80032444: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80032448: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8003244C: nop

    // 0x80032450: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80032454: nop

    // 0x80032458: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8003245C: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x80032460: nop

    // 0x80032464: bne         $t1, $zero, L_80032590
    if (ctx->r9 != 0) {
        // 0x80032468: nop

            goto L_80032590;
    }
    // 0x80032468: nop

L_8003246C:
    // 0x8003246C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80032470: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80032474: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80032478: jal         0x800C143C
    // 0x8003247C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_0;
    // 0x8003247C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80032480: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80032484: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032488: lh          $s0, 0x0($t3)
    ctx->r16 = MEM_H(ctx->r11, 0X0);
    // 0x8003248C: nop

    // 0x80032490: beq         $s0, $at, L_800324AC
    if (ctx->r16 == ctx->r1) {
        // 0x80032494: nop

            goto L_800324AC;
    }
    // 0x80032494: nop

    // 0x80032498: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003249C: beq         $s0, $at, L_80032508
    if (ctx->r16 == ctx->r1) {
        // 0x800324A0: nop

            goto L_80032508;
    }
    // 0x800324A0: nop

    // 0x800324A4: b           L_80032564
    // 0x800324A8: nop

        goto L_80032564;
    // 0x800324A8: nop

L_800324AC:
    // 0x800324AC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800324B0: lw          $t4, 0x72DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72DC);
    // 0x800324B4: nop

    // 0x800324B8: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x800324BC: bne         $t5, $zero, L_80032500
    if (ctx->r13 != 0) {
        // 0x800324C0: nop

            goto L_80032500;
    }
    // 0x800324C0: nop

    // 0x800324C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800324C8: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x800324CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800324D0: nop

    // 0x800324D4: beq         $t6, $t7, L_80032500
    if (ctx->r14 == ctx->r15) {
        // 0x800324D8: nop

            goto L_80032500;
    }
    // 0x800324D8: nop

    // 0x800324DC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800324E0: nop

    // 0x800324E4: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x800324E8: nop

    // 0x800324EC: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x800324F0: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x800324F4: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x800324F8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800324FC: sw          $t1, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r9;
L_80032500:
    // 0x80032500: b           L_8003256C
    // 0x80032504: nop

        goto L_8003256C;
    // 0x80032504: nop

L_80032508:
    // 0x80032508: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003250C: lw          $t2, 0x72DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72DC);
    // 0x80032510: nop

    // 0x80032514: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80032518: bne         $t3, $zero, L_8003255C
    if (ctx->r11 != 0) {
        // 0x8003251C: nop

            goto L_8003255C;
    }
    // 0x8003251C: nop

    // 0x80032520: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80032524: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x80032528: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8003252C: nop

    // 0x80032530: beq         $t4, $t5, L_8003255C
    if (ctx->r12 == ctx->r13) {
        // 0x80032534: nop

            goto L_8003255C;
    }
    // 0x80032534: nop

    // 0x80032538: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8003253C: nop

    // 0x80032540: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80032544: nop

    // 0x80032548: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x8003254C: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80032550: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x80032554: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80032558: sw          $t0, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r8;
L_8003255C:
    // 0x8003255C: b           L_8003256C
    // 0x80032560: nop

        goto L_8003256C;
    // 0x80032560: nop

L_80032564:
    // 0x80032564: b           L_8003256C
    // 0x80032568: nop

        goto L_8003256C;
    // 0x80032568: nop

L_8003256C:
    // 0x8003256C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80032570: nop

    // 0x80032574: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x80032578: nop

    // 0x8003257C: addiu       $t2, $t9, 0x7FFF
    ctx->r10 = ADD32(ctx->r25, 0X7FFF);
    // 0x80032580: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x80032584: nop

    // 0x80032588: beq         $t2, $zero, L_8003246C
    if (ctx->r10 == 0) {
        // 0x8003258C: nop

            goto L_8003246C;
    }
    // 0x8003258C: nop

L_80032590:
    // 0x80032590: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80032594: nop

    // 0x80032598: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8003259C: nop

    // 0x800325A0: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x800325A4: lw          $t5, 0x2D9($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2D9);
    // 0x800325A8: nop

    // 0x800325AC: beq         $t5, $zero, L_800325EC
    if (ctx->r13 == 0) {
        // 0x800325B0: nop

            goto L_800325EC;
    }
    // 0x800325B0: nop

L_800325B4:
    // 0x800325B4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800325B8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800325BC: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800325C0: jal         0x800C143C
    // 0x800325C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_1;
    // 0x800325C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800325C8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800325CC: nop

    // 0x800325D0: lw          $t0, 0x18($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X18);
    // 0x800325D4: nop

    // 0x800325D8: addiu       $t7, $t0, 0x7FFF
    ctx->r15 = ADD32(ctx->r8, 0X7FFF);
    // 0x800325DC: lw          $t7, 0x2D9($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2D9);
    // 0x800325E0: nop

    // 0x800325E4: bne         $t7, $zero, L_800325B4
    if (ctx->r15 != 0) {
        // 0x800325E8: nop

            goto L_800325B4;
    }
    // 0x800325E8: nop

L_800325EC:
    // 0x800325EC: b           L_800325F4
    // 0x800325F0: nop

        goto L_800325F4;
    // 0x800325F0: nop

L_800325F4:
    // 0x800325F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800325F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800325FC: jr          $ra
    // 0x80032600: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80032600: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80032604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032604: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80032608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003260C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032610: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80032614:
    // 0x80032614: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80032618: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003261C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80032620: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80032624: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80032628: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003262C: lw          $t8, 0xDA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XDA8);
    // 0x80032630: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80032634: beq         $t8, $at, L_80032674
    if (ctx->r24 == ctx->r1) {
        // 0x80032638: nop

            goto L_80032674;
    }
    // 0x80032638: nop

    // 0x8003263C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80032640: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80032644: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80032648: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003264C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80032650: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80032654: addiu       $t2, $t2, 0xDA8
    ctx->r10 = ADD32(ctx->r10, 0XDA8);
    // 0x80032658: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8003265C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x80032660: addu        $a1, $t0, $t2
    ctx->r5 = ADD32(ctx->r8, ctx->r10);
    // 0x80032664: jal         0x800BCFCC
    // 0x80032668: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x80032668: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x8003266C: b           L_8003273C
    // 0x80032670: nop

        goto L_8003273C;
    // 0x80032670: nop

L_80032674:
    // 0x80032674: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80032678: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003267C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80032680: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80032684: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80032688: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8003268C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80032690: sw          $t3, 0x60F0($at)
    MEM_W(0X60F0, ctx->r1) = ctx->r11;
    // 0x80032694: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80032698: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8003269C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800326A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800326A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800326A8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800326AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800326B0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800326B4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800326B8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800326BC: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x800326C0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800326C4: sh          $zero, 0x60F8($at)
    MEM_H(0X60F8, ctx->r1) = 0;
    // 0x800326C8: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x800326CC: lhu         $s0, 0x8($t0)
    ctx->r16 = MEM_HU(ctx->r8, 0X8);
    // 0x800326D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800326D4: sh          $s0, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r16;
    // 0x800326D8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800326DC: nop

    // 0x800326E0: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800326E4: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800326E8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800326EC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800326F0: sh          $s0, 0x60F6($at)
    MEM_H(0X60F6, ctx->r1) = ctx->r16;
    // 0x800326F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800326F8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800326FC: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80032700: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80032704: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80032708: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003270C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80032710: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80032714: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80032718: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8003271C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80032720: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80032724: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80032728: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003272C: swc1        $f4, 0x6104($at)
    MEM_W(0X6104, ctx->r1) = ctx->f4.u32l;
    // 0x80032730: lwc1        $f6, 0x14($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80032734: nop

    // 0x80032738: swc1        $f6, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f6.u32l;
L_8003273C:
    // 0x8003273C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80032740: nop

    // 0x80032744: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80032748: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8003274C: bne         $at, $zero, L_80032614
    if (ctx->r1 != 0) {
        // 0x80032750: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_80032614;
    }
    // 0x80032750: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80032754: b           L_8003275C
    // 0x80032758: nop

        goto L_8003275C;
    // 0x80032758: nop

L_8003275C:
    // 0x8003275C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032764: jr          $ra
    // 0x80032768: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80032768: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
