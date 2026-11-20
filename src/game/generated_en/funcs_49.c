#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800CCC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCC68: nop

    // 0x800CCC6C: nop

;}
RECOMP_FUNC void func_800CCC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCC7C: nop

;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCC80: beq         $a2, $zero, L_800CCCEC
    if (ctx->r6 == 0) {
        // 0x800CCC84: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800CCCEC;
    }
    // 0x800CCC84: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CCC88: beq         $a0, $a1, L_800CCCEC
    if (ctx->r4 == ctx->r5) {
        // 0x800CCC8C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800CCCEC;
    }
    // 0x800CCC8C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CCC90: bnel        $at, $zero, L_800CCCB4
    if (ctx->r1 != 0) {
        // 0x800CCC94: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCCB4;
    }
    goto skip_0;
    // 0x800CCC94: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800CCC98: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800CCC9C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CCCA0: beql        $at, $zero, L_800CCCB4
    if (ctx->r1 == 0) {
        // 0x800CCCA4: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCCB4;
    }
    goto skip_1;
    // 0x800CCCA4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x800CCCA8: b           L_800CCE18
    // 0x800CCCAC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800CCE18;
    // 0x800CCCAC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800CCCB0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCCB4:
    // 0x800CCCB4: bne         $at, $zero, L_800CCCCC
    if (ctx->r1 != 0) {
        // 0x800CCCB8: nop

            goto L_800CCCCC;
    }
    // 0x800CCCB8: nop

    // 0x800CCCBC: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CCCC0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CCCC4: beq         $v0, $v1, L_800CCCF4
    if (ctx->r2 == ctx->r3) {
        // 0x800CCCC8: nop

            goto L_800CCCF4;
    }
    // 0x800CCCC8: nop

L_800CCCCC:
    // 0x800CCCCC: beq         $a2, $zero, L_800CCCEC
    if (ctx->r6 == 0) {
        // 0x800CCCD0: nop

            goto L_800CCCEC;
    }
    // 0x800CCCD0: nop

    // 0x800CCCD4: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_800CCCD8:
    // 0x800CCCD8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCCDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CCCE0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CCCE4: bne         $a0, $v1, L_800CCCD8
    if (ctx->r4 != ctx->r3) {
        // 0x800CCCE8: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_800CCCD8;
    }
    // 0x800CCCE8: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_800CCCEC:
    // 0x800CCCEC: jr          $ra
    // 0x800CCCF0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CCCF0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CCCF4:
    // 0x800CCCF4: beq         $v0, $zero, L_800CCD58
    if (ctx->r2 == 0) {
        // 0x800CCCF8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CCD58;
    }
    // 0x800CCCF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CCCFC: beq         $v0, $at, L_800CCD3C
    if (ctx->r2 == ctx->r1) {
        // 0x800CCD00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CCD3C;
    }
    // 0x800CCD00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CCD04: beql        $v0, $at, L_800CCD28
    if (ctx->r2 == ctx->r1) {
        // 0x800CCD08: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800CCD28;
    }
    goto skip_2;
    // 0x800CCD08: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800CCD0C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCD10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CCD14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CCD18: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CCD1C: b           L_800CCD58
    // 0x800CCD20: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800CCD58;
    // 0x800CCD20: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800CCD24: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800CCD28:
    // 0x800CCD28: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800CCD2C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800CCD30: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CCD34: b           L_800CCD58
    // 0x800CCD38: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800CCD58;
    // 0x800CCD38: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800CCD3C:
    // 0x800CCD3C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCD40: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800CCD44: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800CCD48: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800CCD4C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CCD50: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800CCD54: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800CCD58:
    // 0x800CCD58: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CCD5C: bnel        $at, $zero, L_800CCDB8
    if (ctx->r1 != 0) {
        // 0x800CCD60: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCDB8;
    }
    goto skip_3;
    // 0x800CCD60: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800CCD64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CCD68: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CCD6C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CCD70: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CCD74: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800CCD78: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CCD7C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800CCD80: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800CCD84: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800CCD88: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800CCD8C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CCD90: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800CCD94: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800CCD98: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800CCD9C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x800CCDA0: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x800CCDA4: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x800CCDA8: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x800CCDAC: b           L_800CCD58
    // 0x800CCDB0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800CCD58;
    // 0x800CCDB0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_800CCDB4:
    // 0x800CCDB4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCDB8:
    // 0x800CCDB8: bnel        $at, $zero, L_800CCDF4
    if (ctx->r1 != 0) {
        // 0x800CCDBC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CCDF4;
    }
    goto skip_4;
    // 0x800CCDBC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x800CCDC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CCDC4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CCDC8: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CCDCC: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CCDD0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800CCDD4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800CCDD8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CCDDC: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x800CCDE0: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x800CCDE4: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x800CCDE8: b           L_800CCDB4
    // 0x800CCDEC: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_800CCDB4;
    // 0x800CCDEC: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_800CCDF0:
    // 0x800CCDF0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CCDF4:
    // 0x800CCDF4: bne         $at, $zero, L_800CCCCC
    if (ctx->r1 != 0) {
        // 0x800CCDF8: nop

            goto L_800CCCCC;
    }
    // 0x800CCDF8: nop

    // 0x800CCDFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CCE00: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CCE04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CCE08: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CCE0C: b           L_800CCDF0
    // 0x800CCE10: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_800CCDF0;
    // 0x800CCE10: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800CCE14: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCE18:
    // 0x800CCE18: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800CCE1C: bne         $at, $zero, L_800CCE34
    if (ctx->r1 != 0) {
        // 0x800CCE20: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800CCE34;
    }
    // 0x800CCE20: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800CCE24: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CCE28: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CCE2C: beq         $v0, $v1, L_800CCE64
    if (ctx->r2 == ctx->r3) {
        // 0x800CCE30: nop

            goto L_800CCE64;
    }
    // 0x800CCE30: nop

L_800CCE34:
    // 0x800CCE34: beq         $a2, $zero, L_800CCCEC
    if (ctx->r6 == 0) {
        // 0x800CCE38: nop

            goto L_800CCCEC;
    }
    // 0x800CCE38: nop

    // 0x800CCE3C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CCE40: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CCE44: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800CCE48:
    // 0x800CCE48: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CCE4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CCE50: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CCE54: bne         $a0, $v1, L_800CCE48
    if (ctx->r4 != ctx->r3) {
        // 0x800CCE58: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800CCE48;
    }
    // 0x800CCE58: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800CCE5C: jr          $ra
    // 0x800CCE60: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CCE60: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CCE64:
    // 0x800CCE64: beq         $v0, $zero, L_800CCEC8
    if (ctx->r2 == 0) {
        // 0x800CCE68: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CCEC8;
    }
    // 0x800CCE68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CCE6C: beq         $v0, $at, L_800CCEAC
    if (ctx->r2 == ctx->r1) {
        // 0x800CCE70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CCEAC;
    }
    // 0x800CCE70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CCE74: beql        $v0, $at, L_800CCE98
    if (ctx->r2 == ctx->r1) {
        // 0x800CCE78: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_800CCE98;
    }
    goto skip_5;
    // 0x800CCE78: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x800CCE7C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CCE80: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CCE84: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CCE88: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CCE8C: b           L_800CCEC8
    // 0x800CCE90: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800CCEC8;
    // 0x800CCE90: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800CCE94: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_800CCE98:
    // 0x800CCE98: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800CCE9C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800CCEA0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CCEA4: b           L_800CCEC8
    // 0x800CCEA8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_800CCEC8;
    // 0x800CCEA8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800CCEAC:
    // 0x800CCEAC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CCEB0: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x800CCEB4: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x800CCEB8: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x800CCEBC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CCEC0: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x800CCEC4: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_800CCEC8:
    // 0x800CCEC8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CCECC: bnel        $at, $zero, L_800CCF28
    if (ctx->r1 != 0) {
        // 0x800CCED0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CCF28;
    }
    goto skip_6;
    // 0x800CCED0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x800CCED4: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CCED8: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CCEDC: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CCEE0: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CCEE4: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x800CCEE8: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x800CCEEC: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x800CCEF0: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x800CCEF4: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800CCEF8: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x800CCEFC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CCF00: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800CCF04: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800CCF08: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800CCF0C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800CCF10: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800CCF14: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800CCF18: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800CCF1C: b           L_800CCEC8
    // 0x800CCF20: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_800CCEC8;
    // 0x800CCF20: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800CCF24:
    // 0x800CCF24: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CCF28:
    // 0x800CCF28: bnel        $at, $zero, L_800CCF64
    if (ctx->r1 != 0) {
        // 0x800CCF2C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CCF64;
    }
    goto skip_7;
    // 0x800CCF2C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800CCF30: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CCF34: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CCF38: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CCF3C: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CCF40: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CCF44: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800CCF48: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CCF4C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800CCF50: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800CCF54: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800CCF58: b           L_800CCF24
    // 0x800CCF5C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800CCF24;
    // 0x800CCF5C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800CCF60:
    // 0x800CCF60: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CCF64:
    // 0x800CCF64: bne         $at, $zero, L_800CCE34
    if (ctx->r1 != 0) {
        // 0x800CCF68: nop

            goto L_800CCE34;
    }
    // 0x800CCF68: nop

    // 0x800CCF6C: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CCF70: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800CCF74: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800CCF78: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CCF7C: b           L_800CCF60
    // 0x800CCF80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800CCF60;
    // 0x800CCF80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_800CCF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCF84: nop

    // 0x800CCF88: nop

    // 0x800CCF8C: nop

;}
RECOMP_FUNC void func_800CD004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD004: nop

    // 0x800CD008: nop

    // 0x800CD00C: nop

;}
RECOMP_FUNC void func_800CD01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD01C: nop

;}
RECOMP_FUNC void func_800CD054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD054: nop

    // 0x800CD058: nop

    // 0x800CD05C: nop

;}
RECOMP_FUNC void func_800CD0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD0EC: nop

;}
RECOMP_FUNC void func_800CD11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD11C: nop

;}
RECOMP_FUNC void func_800CD14C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD14C: nop

;}
RECOMP_FUNC void func_800CD4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD4E4: nop

    // 0x800CD4E8: nop

    // 0x800CD4EC: nop

;}
RECOMP_FUNC void func_800CD59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD59C: nop

;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD660: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CD664: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800CD668: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800CD66C: blez        $a1, L_800CD6B0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800CD670: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_800CD6B0;
    }
    // 0x800CD670: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800CD674:
    // 0x800CD674: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800CD678: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800CD67C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800CD680: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800CD684: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800CD688: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800CD68C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800CD690: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800CD694: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800CD698: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CD69C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800CD6A0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800CD6A4: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800CD6A8: bne         $at, $zero, L_800CD674
    if (ctx->r1 != 0) {
        // 0x800CD6AC: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_800CD674;
    }
    // 0x800CD6AC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800CD6B0:
    // 0x800CD6B0: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x800CD6B4: jr          $ra
    // 0x800CD6B8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CD6B8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
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
RECOMP_FUNC void func_800CE3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE3B8: nop

    // 0x800CE3BC: nop

;}
RECOMP_FUNC void func_800CE574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE574: nop

    // 0x800CE578: nop

    // 0x800CE57C: nop

;}
RECOMP_FUNC void func_800CE7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE7B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800CE7B4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800CE7B8: addiu       $t6, $t6, -0x430
    ctx->r14 = ADD32(ctx->r14, -0X430);
    // 0x800CE7BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE7C0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800CE7C4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800CE7C8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800CE7CC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800CE7D0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800CE7D4:
    // 0x800CE7D4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800CE7D8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800CE7DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800CE7E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CE7E4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800CE7E8: sw          $zero, -0x430($at)
    MEM_W(-0X430, ctx->r1) = 0;
    // 0x800CE7EC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CE7F0: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800CE7F4: bne         $at, $zero, L_800CE7D4
    if (ctx->r1 != 0) {
        // 0x800CE7F8: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_800CE7D4;
    }
    // 0x800CE7F8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800CE7FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CE800: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800CE804: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800CE808: addiu       $t3, $zero, 0x23
    ctx->r11 = ADD32(0, 0X23);
    // 0x800CE80C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CE810: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800CE814: sw          $t1, -0x3F4($at)
    MEM_W(-0X3F4, ctx->r1) = ctx->r9;
    // 0x800CE818: sb          $t2, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r10;
    // 0x800CE81C: sb          $t3, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r11;
    // 0x800CE820: sb          $t4, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r12;
    // 0x800CE824: sb          $t5, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r13;
    // 0x800CE828: jal         0x800D5530
    // 0x800CE82C: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    __osContAddressCrc_recomp(rdram, ctx);
        goto after_0;
    // 0x800CE82C: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x800CE830: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x800CE834: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800CE838: sb          $t9, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r25;
    // 0x800CE83C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800CE840: or          $t8, $v0, $t7
    ctx->r24 = ctx->r2 | ctx->r15;
    // 0x800CE844: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x800CE848: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800CE84C:
    // 0x800CE84C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800CE850: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800CE854: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800CE858: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x800CE85C: sb          $t1, 0x22($t3)
    MEM_B(0X22, ctx->r11) = ctx->r9;
    // 0x800CE860: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CE864: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800CE868: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CE86C: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x800CE870: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800CE874: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800CE878: bne         $at, $zero, L_800CE84C
    if (ctx->r1 != 0) {
        // 0x800CE87C: sw          $t5, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r13;
            goto L_800CE84C;
    }
    // 0x800CE87C: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x800CE880: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CE884: beq         $t8, $zero, L_800CE8C0
    if (ctx->r24 == 0) {
        // 0x800CE888: nop

            goto L_800CE8C0;
    }
    // 0x800CE888: nop

    // 0x800CE88C: blez        $t8, L_800CE8C0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800CE890: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_800CE8C0;
    }
    // 0x800CE890: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800CE894:
    // 0x800CE894: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800CE898: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800CE89C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800CE8A0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800CE8A4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800CE8A8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800CE8AC: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CE8B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800CE8B4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800CE8B8: bne         $at, $zero, L_800CE894
    if (ctx->r1 != 0) {
        // 0x800CE8BC: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_800CE894;
    }
    // 0x800CE8BC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_800CE8C0:
    // 0x800CE8C0: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x800CE8C4: addiu       $t8, $t6, 0x24
    ctx->r24 = ADD32(ctx->r14, 0X24);
    // 0x800CE8C8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_800CE8CC:
    // 0x800CE8CC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800CE8D0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800CE8D4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800CE8D8: swl         $at, -0xC($t5)
    do_swl(rdram, -0XC, ctx->r13, ctx->r1);
    // 0x800CE8DC: swr         $at, -0x9($t5)
    do_swr(rdram, -0X9, ctx->r13, ctx->r1);
    // 0x800CE8E0: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x800CE8E4: swl         $at, -0x8($t5)
    do_swl(rdram, -0X8, ctx->r13, ctx->r1);
    // 0x800CE8E8: swr         $at, -0x5($t5)
    do_swr(rdram, -0X5, ctx->r13, ctx->r1);
    // 0x800CE8EC: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x800CE8F0: swl         $at, -0x4($t5)
    do_swl(rdram, -0X4, ctx->r13, ctx->r1);
    // 0x800CE8F4: bne         $t6, $t8, L_800CE8CC
    if (ctx->r14 != ctx->r24) {
        // 0x800CE8F8: swr         $at, -0x1($t5)
        do_swr(rdram, -0X1, ctx->r13, ctx->r1);
            goto L_800CE8CC;
    }
    // 0x800CE8F8: swr         $at, -0x1($t5)
    do_swr(rdram, -0X1, ctx->r13, ctx->r1);
    // 0x800CE8FC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800CE900: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x800CE904: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x800CE908: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x800CE90C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800CE910: addiu       $t0, $t9, 0x28
    ctx->r8 = ADD32(ctx->r25, 0X28);
    // 0x800CE914: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800CE918: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x800CE91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE920: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800CE924: jr          $ra
    // 0x800CE928: nop

    return;
    // 0x800CE928: nop

    // 0x800CE92C: nop

;}
RECOMP_FUNC void func_800CF5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF5D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800CF5D8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800CF5DC: addiu       $t6, $t6, -0x430
    ctx->r14 = ADD32(ctx->r14, -0X430);
    // 0x800CF5E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF5E4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800CF5E8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800CF5EC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800CF5F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800CF5F4:
    // 0x800CF5F4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800CF5F8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800CF5FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800CF600: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CF604: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800CF608: sw          $zero, -0x430($at)
    MEM_W(-0X430, ctx->r1) = 0;
    // 0x800CF60C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CF610: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800CF614: bne         $at, $zero, L_800CF5F4
    if (ctx->r1 != 0) {
        // 0x800CF618: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_800CF5F4;
    }
    // 0x800CF618: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800CF61C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CF620: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800CF624: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800CF628: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800CF62C: addiu       $t4, $zero, 0x21
    ctx->r12 = ADD32(0, 0X21);
    // 0x800CF630: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800CF634: sw          $t1, -0x3F4($at)
    MEM_W(-0X3F4, ctx->r1) = ctx->r9;
    // 0x800CF638: sb          $t2, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r10;
    // 0x800CF63C: sb          $t3, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r11;
    // 0x800CF640: sb          $t4, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r12;
    // 0x800CF644: sb          $t5, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r13;
    // 0x800CF648: jal         0x800D5530
    // 0x800CF64C: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    __osContAddressCrc_recomp(rdram, ctx);
        goto after_0;
    // 0x800CF64C: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x800CF650: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x800CF654: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800CF658: sb          $t9, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r25;
    // 0x800CF65C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800CF660: or          $t8, $v0, $t7
    ctx->r24 = ctx->r2 | ctx->r15;
    // 0x800CF664: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x800CF668: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800CF66C:
    // 0x800CF66C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800CF670: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800CF674: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x800CF678: sb          $t0, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r8;
    // 0x800CF67C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800CF680: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800CF684: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x800CF688: bne         $at, $zero, L_800CF66C
    if (ctx->r1 != 0) {
        // 0x800CF68C: sw          $t4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r12;
            goto L_800CF66C;
    }
    // 0x800CF68C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800CF690: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800CF694: beq         $t5, $zero, L_800CF6D0
    if (ctx->r13 == 0) {
        // 0x800CF698: nop

            goto L_800CF6D0;
    }
    // 0x800CF698: nop

    // 0x800CF69C: blez        $t5, L_800CF6D0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800CF6A0: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_800CF6D0;
    }
    // 0x800CF6A0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800CF6A4:
    // 0x800CF6A4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800CF6A8: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x800CF6AC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800CF6B0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CF6B4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800CF6B8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CF6BC: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CF6C0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800CF6C4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800CF6C8: bne         $at, $zero, L_800CF6A4
    if (ctx->r1 != 0) {
        // 0x800CF6CC: sw          $t8, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r24;
            goto L_800CF6A4;
    }
    // 0x800CF6CC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800CF6D0:
    // 0x800CF6D0: addiu       $t3, $sp, 0x1C
    ctx->r11 = ADD32(ctx->r29, 0X1C);
    // 0x800CF6D4: addiu       $t5, $t3, 0x24
    ctx->r13 = ADD32(ctx->r11, 0X24);
    // 0x800CF6D8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_800CF6DC:
    // 0x800CF6DC: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800CF6E0: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800CF6E4: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800CF6E8: swl         $at, -0xC($t2)
    do_swl(rdram, -0XC, ctx->r10, ctx->r1);
    // 0x800CF6EC: swr         $at, -0x9($t2)
    do_swr(rdram, -0X9, ctx->r10, ctx->r1);
    // 0x800CF6F0: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x800CF6F4: swl         $at, -0x8($t2)
    do_swl(rdram, -0X8, ctx->r10, ctx->r1);
    // 0x800CF6F8: swr         $at, -0x5($t2)
    do_swr(rdram, -0X5, ctx->r10, ctx->r1);
    // 0x800CF6FC: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x800CF700: swl         $at, -0x4($t2)
    do_swl(rdram, -0X4, ctx->r10, ctx->r1);
    // 0x800CF704: bne         $t3, $t5, L_800CF6DC
    if (ctx->r11 != ctx->r13) {
        // 0x800CF708: swr         $at, -0x1($t2)
        do_swr(rdram, -0X1, ctx->r10, ctx->r1);
            goto L_800CF6DC;
    }
    // 0x800CF708: swr         $at, -0x1($t2)
    do_swr(rdram, -0X1, ctx->r10, ctx->r1);
    // 0x800CF70C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800CF710: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x800CF714: swl         $at, 0x0($t2)
    do_swl(rdram, 0X0, ctx->r10, ctx->r1);
    // 0x800CF718: swr         $at, 0x3($t2)
    do_swr(rdram, 0X3, ctx->r10, ctx->r1);
    // 0x800CF71C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800CF720: addiu       $t7, $t6, 0x28
    ctx->r15 = ADD32(ctx->r14, 0X28);
    // 0x800CF724: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x800CF728: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x800CF72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF730: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800CF734: jr          $ra
    // 0x800CF738: nop

    return;
    // 0x800CF738: nop

    // 0x800CF73C: nop

;}
RECOMP_FUNC void alSynDelete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF740: jr          $ra
    // 0x800CF744: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800CF744: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800CF748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF748: nop

    // 0x800CF74C: nop

;}
RECOMP_FUNC void func_800CF808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF808: nop

    // 0x800CF80C: nop

;}
RECOMP_FUNC void alSaveNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF848: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF84C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF850: addiu       $a2, $a2, 0x1D90
    ctx->r6 = ADD32(ctx->r6, 0X1D90);
    // 0x800CF854: addiu       $a1, $a1, 0x1DC4
    ctx->r5 = ADD32(ctx->r5, 0X1DC4);
    // 0x800CF858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CF85C: jal         0x800D56B0
    // 0x800CF860: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF860: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x800CF864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CF868: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CF86C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CF870: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CF874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF87C: jr          $ra
    // 0x800CF880: nop

    return;
    // 0x800CF880: nop

;}
RECOMP_FUNC void alMainBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF888: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CF88C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CF890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF894: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF898: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF89C: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    // 0x800CF8A0: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    // 0x800CF8A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CF8A8: jal         0x800D56B0
    // 0x800CF8AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF8AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800CF8B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CF8B4: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CF8B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CF8BC: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CF8C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF8C4: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800CF8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF8CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF8D0: jr          $ra
    // 0x800CF8D4: nop

    return;
    // 0x800CF8D4: nop

;}
RECOMP_FUNC void alAuxBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF8D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF8DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CF8E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CF8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF8E8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF8EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF8F0: addiu       $a1, $a1, 0x1CB0
    ctx->r5 = ADD32(ctx->r5, 0X1CB0);
    // 0x800CF8F4: addiu       $a2, $a2, 0x1C80
    ctx->r6 = ADD32(ctx->r6, 0X1C80);
    // 0x800CF8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CF8FC: jal         0x800D56B0
    // 0x800CF900: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF900: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x800CF904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CF908: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CF90C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CF910: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CF914: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF918: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800CF91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF924: jr          $ra
    // 0x800CF928: nop

    return;
    // 0x800CF928: nop

;}
RECOMP_FUNC void alResampleNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF92C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CF930: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CF934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CF938: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF93C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF940: addiu       $a2, $a2, 0xD20
    ctx->r6 = ADD32(ctx->r6, 0XD20);
    // 0x800CF944: addiu       $a1, $a1, 0xE0C
    ctx->r5 = ADD32(ctx->r5, 0XE0C);
    // 0x800CF948: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CF94C: jal         0x800D56B0
    // 0x800CF950: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF950: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800CF954: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800CF958: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CF95C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CF960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CF964: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800CF968: jal         0x800C7950
    // 0x800CF96C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CF96C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CF970: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CF974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CF978: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CF97C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF980: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CF984: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800CF988: sw          $t7, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r15;
    // 0x800CF98C: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800CF990: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x800CF994: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x800CF998: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800CF99C: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x800CF9A0: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x800CF9A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF9A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CF9AC: jr          $ra
    // 0x800CF9B0: nop

    return;
    // 0x800CF9B0: nop

;}
RECOMP_FUNC void alLoadNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF9B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CF9B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CF9BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800CF9C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CF9C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CF9C8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF9CC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF9D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CF9D4: addiu       $a1, $a1, 0x87C
    ctx->r5 = ADD32(ctx->r5, 0X87C);
    // 0x800CF9D8: addiu       $a2, $a2, 0x1D0
    ctx->r6 = ADD32(ctx->r6, 0X1D0);
    // 0x800CF9DC: jal         0x800D56B0
    // 0x800CF9E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF9E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800CF9E4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800CF9E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CF9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CF9F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CF9F4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800CF9F8: jal         0x800C7950
    // 0x800CF9FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CF9FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CFA00: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800CFA04: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x800CFA08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CFA0C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800CFA10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFA14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFA18: jal         0x800C7950
    // 0x800CFA1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800CFA1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800CFA20: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800CFA24: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800CFA28: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800CFA2C: jalr        $t9
    // 0x800CFA30: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CFA30: nop

    after_3:
    // 0x800CFA34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CFA38: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800CFA3C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800CFA40: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x800CFA44: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800CFA48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CFA4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CFA50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CFA54: jr          $ra
    // 0x800CFA58: nop

    return;
    // 0x800CFA58: nop

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
RECOMP_FUNC void _init_lpfilter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFB00: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800CFB04: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x800CFB08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CFB0C: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x800CFB10: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CFB14: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800CFB18: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800CFB1C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x800CFB20: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x800CFB24: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x800CFB28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFB2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_800CFB30:
    // 0x800CFB30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CFB34: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800CFB38: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800CFB3C: bne         $at, $zero, L_800CFB30
    if (ctx->r1 != 0) {
        // 0x800CFB40: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_800CFB30;
    }
    // 0x800CFB40: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x800CFB44: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800CFB48: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x800CFB4C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800CFB50: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CFB54: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800CFB58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CFB5C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800CFB60: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x800CFB64: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d);
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x800CFB68: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800CFB6C: beq         $at, $zero, L_800CFB98
    if (ctx->r1 == 0) {
        // 0x800CFB70: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_800CFB98;
    }
    // 0x800CFB70: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_800CFB74:
    // 0x800CFB74: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d);
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800CFB78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CFB7C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800CFB80: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800CFB84: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d);
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x800CFB88: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800CFB8C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800CFB90: bne         $at, $zero, L_800CFB74
    if (ctx->r1 != 0) {
        // 0x800CFB94: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_800CFB74;
    }
    // 0x800CFB94: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_800CFB98:
    // 0x800CFB98: jr          $ra
    // 0x800CFB9C: nop

    return;
    // 0x800CFB9C: nop

;}
RECOMP_FUNC void alFxNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFBA0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CFBA4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800CFBA8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800CFBAC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800CFBB0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800CFBB4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800CFBB8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CFBBC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800CFBC0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800CFBC4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800CFBC8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800CFBCC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800CFBD0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800CFBD4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800CFBD8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800CFBDC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800CFBE0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800CFBE4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800CFBE8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800CFBEC: addiu       $a2, $a2, 0x5FC4
    ctx->r6 = ADD32(ctx->r6, 0X5FC4);
    // 0x800CFBF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFBF4: jal         0x800D56B0
    // 0x800CFBF8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CFBF8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x800CFBFC: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800CFC00: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CFC04: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CFC08: addiu       $t6, $t6, 0x5FDC
    ctx->r14 = ADD32(ctx->r14, 0X5FDC);
    // 0x800CFC0C: addiu       $t7, $t7, 0x5D68
    ctx->r15 = ADD32(ctx->r15, 0X5D68);
    // 0x800CFC10: sw          $t6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r14;
    // 0x800CFC14: sw          $t7, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r15;
    // 0x800CFC18: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x800CFC1C: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC20: addiu       $s3, $s3, -0x3148
    ctx->r19 = ADD32(ctx->r19, -0X3148);
    // 0x800CFC24: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800CFC28: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x800CFC2C: beq         $at, $zero, L_800CFC8C
    if (ctx->r1 == 0) {
        // 0x800CFC30: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800CFC8C;
    }
    // 0x800CFC30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800CFC34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CFC38: addu        $at, $at, $t9
    gpr jr_addend_800CFC40 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CFC3C: lw          $t9, 0x2B0($at)
    ctx->r25 = ADD32(ctx->r1, 0X2B0);
    // 0x800CFC40: jr          $t9
    // 0x800CFC44: nop

    switch (jr_addend_800CFC40 >> 2) {
        case 0: goto L_800CFC48; break;
        case 1: goto L_800CFC54; break;
        case 2: goto L_800CFC6C; break;
        case 3: goto L_800CFC78; break;
        case 4: goto L_800CFC60; break;
        case 5: goto L_800CFC84; break;
        default: switch_error(__func__, 0x800CFC40, 0x800F02B0);
    }
    // 0x800CFC44: nop

L_800CFC48:
    // 0x800CFC48: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC4C: b           L_800CFC8C
    // 0x800CFC50: addiu       $s3, $s3, -0x32B0
    ctx->r19 = ADD32(ctx->r19, -0X32B0);
        goto L_800CFC8C;
    // 0x800CFC50: addiu       $s3, $s3, -0x32B0
    ctx->r19 = ADD32(ctx->r19, -0X32B0);
L_800CFC54:
    // 0x800CFC54: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC58: b           L_800CFC8C
    // 0x800CFC5C: addiu       $s3, $s3, -0x3248
    ctx->r19 = ADD32(ctx->r19, -0X3248);
        goto L_800CFC8C;
    // 0x800CFC5C: addiu       $s3, $s3, -0x3248
    ctx->r19 = ADD32(ctx->r19, -0X3248);
L_800CFC60:
    // 0x800CFC60: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC64: b           L_800CFC8C
    // 0x800CFC68: addiu       $s3, $s3, -0x31C0
    ctx->r19 = ADD32(ctx->r19, -0X31C0);
        goto L_800CFC8C;
    // 0x800CFC68: addiu       $s3, $s3, -0x31C0
    ctx->r19 = ADD32(ctx->r19, -0X31C0);
L_800CFC6C:
    // 0x800CFC6C: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC70: b           L_800CFC8C
    // 0x800CFC74: addiu       $s3, $s3, -0x3198
    ctx->r19 = ADD32(ctx->r19, -0X3198);
        goto L_800CFC8C;
    // 0x800CFC74: addiu       $s3, $s3, -0x3198
    ctx->r19 = ADD32(ctx->r19, -0X3198);
L_800CFC78:
    // 0x800CFC78: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC7C: b           L_800CFC8C
    // 0x800CFC80: addiu       $s3, $s3, -0x3170
    ctx->r19 = ADD32(ctx->r19, -0X3170);
        goto L_800CFC8C;
    // 0x800CFC80: addiu       $s3, $s3, -0x3170
    ctx->r19 = ADD32(ctx->r19, -0X3170);
L_800CFC84:
    // 0x800CFC84: b           L_800CFC8C
    // 0x800CFC88: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
        goto L_800CFC8C;
    // 0x800CFC88: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
L_800CFC8C:
    // 0x800CFC8C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800CFC90: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x800CFC94: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800CFC98: sb          $t0, 0x24($s5)
    MEM_B(0X24, ctx->r21) = ctx->r8;
    // 0x800CFC9C: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x800CFCA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFCA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFCA8: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800CFCAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800CFCB0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFCB4: jal         0x800C7950
    // 0x800CFCB8: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CFCB8: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    after_1:
    // 0x800CFCBC: sw          $v0, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r2;
    // 0x800CFCC0: lw          $a3, 0x1C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X1C);
    // 0x800CFCC4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800CFCC8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CFCCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFCD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFCD4: jal         0x800C7950
    // 0x800CFCD8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800CFCD8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x800CFCDC: lw          $t4, 0x1C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1C);
    // 0x800CFCE0: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x800CFCE4: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x800CFCE8: beq         $t4, $zero, L_800CFD1C
    if (ctx->r12 == 0) {
        // 0x800CFCEC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800CFD1C;
    }
    // 0x800CFCEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CFCF0: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
L_800CFCF4:
    // 0x800CFCF4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800CFCF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CFCFC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800CFD00: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x800CFD04: lw          $t9, 0x1C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1C);
    // 0x800CFD08: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x800CFD0C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800CFD10: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x800CFD14: bnel        $at, $zero, L_800CFCF4
    if (ctx->r1 != 0) {
        // 0x800CFD18: lw          $t5, 0x14($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X14);
            goto L_800CFCF4;
    }
    goto skip_0;
    // 0x800CFD18: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
    skip_0:
L_800CFD1C:
    // 0x800CFD1C: lbu         $t0, 0x24($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X24);
    // 0x800CFD20: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800CFD24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CFD28: blez        $t0, L_800CFF9C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800CFD2C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_800CFF9C;
    }
    // 0x800CFD2C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800CFD30: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800CFD34: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800CFD38: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800CFD3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CFD40: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800CFD44: ldc1        $f20, 0x2C8($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X2C8);
    // 0x800CFD48: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
L_800CFD4C:
    // 0x800CFD4C: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CFD50: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800CFD54: lw          $t1, 0x20($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X20);
    // 0x800CFD58: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x800CFD5C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800CFD60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFD64: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x800CFD68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CFD6C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800CFD70: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x800CFD74: mflo        $t2
    ctx->r10 = lo;
    // 0x800CFD78: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800CFD7C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800CFD80: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800CFD84: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800CFD88: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800CFD8C: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800CFD90: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800CFD94: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800CFD98: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x800CFD9C: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800CFDA0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800CFDA4: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x800CFDA8: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x800CFDAC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CFDB0: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x800CFDB4: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800CFDB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CFDBC: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x800CFDC0: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x800CFDC4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800CFDC8: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x800CFDCC: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x800CFDD0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800CFDD4: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x800CFDD8: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x800CFDDC: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800CFDE0: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800CFDE4: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x800CFDE8: beq         $v0, $zero, L_800CFEEC
    if (ctx->r2 == 0) {
        // 0x800CFDEC: addiu       $s1, $t0, 0x2
        ctx->r17 = ADD32(ctx->r8, 0X2);
            goto L_800CFEEC;
    }
    // 0x800CFDEC: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x800CFDF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800CFDF4: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800CFDF8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800CFDFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CFE00: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x800CFE04: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800CFE08: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x800CFE0C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800CFE10: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x800CFE14: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl);
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800CFE18: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800CFE1C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800CFE20: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x800CFE24: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800CFE28: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800CFE2C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800CFE30: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800CFE34: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800CFE38: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d);
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800CFE3C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CFE40: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x800CFE44: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800CFE48: bgez        $t0, L_800CFE60
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CFE4C: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_800CFE60;
    }
    // 0x800CFE4C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800CFE50: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800CFE54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CFE58: nop

    // 0x800CFE5C: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_800CFE60:
    // 0x800CFE60: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800CFE64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFE68: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800CFE6C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800CFE70: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x800CFE74: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800CFE78: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CFE7C: addiu       $t5, $zero, 0x34
    ctx->r13 = ADD32(0, 0X34);
    // 0x800CFE80: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800CFE84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFE88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFE8C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFE90: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800CFE94: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800CFE98: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d);
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x800CFE9C: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800CFEA0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800CFEA4: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x800CFEA8: jal         0x800C7950
    // 0x800CFEAC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800CFEAC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800CFEB0: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800CFEB4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800CFEB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CFEBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFEC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFEC4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFEC8: jal         0x800C7950
    // 0x800CFECC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800CFECC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x800CFED0: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800CFED4: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x800CFED8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800CFEDC: swc1        $f26, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f26.u32l;
    // 0x800CFEE0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800CFEE4: b           L_800CFEF8
    // 0x800CFEE8: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
        goto L_800CFEF8;
    // 0x800CFEE8: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
L_800CFEEC:
    // 0x800CFEEC: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x800CFEF0: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x800CFEF4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_800CFEF8:
    // 0x800CFEF8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x800CFEFC: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x800CFF00: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800CFF04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFF08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFF0C: beq         $t3, $zero, L_800CFF74
    if (ctx->r11 == 0) {
        // 0x800CFF10: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_800CFF74;
    }
    // 0x800CFF10: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFF14: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x800CFF18: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800CFF1C: jal         0x800C7950
    // 0x800CFF20: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x800CFF20: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_5:
    // 0x800CFF24: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800CFF28: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800CFF2C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800CFF30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFF34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFF38: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFF3C: jal         0x800C7950
    // 0x800CFF40: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800CFF40: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
    // 0x800CFF44: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800CFF48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFF4C: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x800CFF50: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x800CFF54: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800CFF58: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800CFF5C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800CFF60: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CFF64: jal         0x800CFB00
    // 0x800CFF68: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _init_lpfilter(rdram, ctx);
        goto after_7;
    // 0x800CFF68: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x800CFF6C: b           L_800CFF88
    // 0x800CFF70: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
        goto L_800CFF88;
    // 0x800CFF70: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800CFF74:
    // 0x800CFF74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFF78: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800CFF7C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800CFF80: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800CFF84: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800CFF88:
    // 0x800CFF88: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800CFF8C: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x800CFF90: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800CFF94: bne         $at, $zero, L_800CFD4C
    if (ctx->r1 != 0) {
        // 0x800CFF98: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_800CFD4C;
    }
    // 0x800CFF98: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_800CFF9C:
    // 0x800CFF9C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800CFFA0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800CFFA4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800CFFA8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800CFFAC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800CFFB0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800CFFB4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800CFFB8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800CFFBC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800CFFC0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800CFFC4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800CFFC8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800CFFCC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800CFFD0: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800CFFD4: jr          $ra
    // 0x800CFFD8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800CFFD8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800CFFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFFDC: nop

;}
RECOMP_FUNC void alSynAllocFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFFE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CFFE4: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x800CFFE8: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800CFFEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CFFF0: sll         $s1, $t6, 2
    ctx->r17 = S32(ctx->r14 << 2);
    // 0x800CFFF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CFFF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CFFFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D0000: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x800D0004: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x800D0008: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800D000C: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x800D0010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D0014: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800D0018: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800D001C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800D0020: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D0024: jal         0x800CFBA0
    // 0x800D0028: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    alFxNew(rdram, ctx);
        goto after_0;
    // 0x800D0028: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x800D002C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x800D0030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D0034: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x800D0038: jal         0x800D5FC4
    // 0x800D003C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    alFxParam(rdram, ctx);
        goto after_1;
    // 0x800D003C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x800D0040: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800D0044: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x800D0048: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800D004C: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x800D0050: jal         0x800D0080
    // 0x800D0054: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    alMainBusParam(rdram, ctx);
        goto after_2;
    // 0x800D0054: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x800D0058: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x800D005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0060: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D0064: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x800D0068: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D0070: jr          $ra
    // 0x800D0074: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x800D0074: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
;}
RECOMP_FUNC void func_800D0078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0078: nop

    // 0x800D007C: nop

;}
RECOMP_FUNC void alMainBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0080: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D0084: bne         $a1, $at, L_800D00A8
    if (ctx->r5 != ctx->r1) {
        // 0x800D0088: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800D00A8;
    }
    // 0x800D0088: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800D008C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800D0090: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D0094: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800D0098: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800D009C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800D00A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800D00A4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800D00A8:
    // 0x800D00A8: jr          $ra
    // 0x800D00AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D00AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alMainBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D00B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D00B4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D00B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D00BC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D00C0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D00C4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D00C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D00CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D00D0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D00D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D00D8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D00DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D00E0: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800D00E4: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800D00E8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800D00EC: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800D00F0: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x800D00F4: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x800D00F8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800D00FC: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800D0100: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800D0104: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800D0108: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800D010C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800D0110: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800D0114: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x800D0118: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D011C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D0120: blez        $t8, L_800D019C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800D0124: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_800D019C;
    }
    // 0x800D0124: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x800D0128: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x800D012C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x800D0130: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800D0134: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_800D0138:
    // 0x800D0138: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D013C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800D0140: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D0144: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D0148: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800D014C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800D0150: jalr        $t9
    // 0x800D0154: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0154: nop

    after_0:
    // 0x800D0158: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800D015C: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800D0160: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x800D0164: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x800D0168: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x800D016C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800D0170: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800D0174: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800D0178: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x800D017C: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800D0180: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800D0184: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x800D0188: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D018C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800D0190: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800D0194: bne         $at, $zero, L_800D0138
    if (ctx->r1 != 0) {
        // 0x800D0198: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_800D0138;
    }
    // 0x800D0198: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_800D019C:
    // 0x800D019C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D01A0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800D01A4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D01A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D01AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D01B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D01B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D01B8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D01BC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D01C0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D01C4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D01C8: jr          $ra
    // 0x800D01CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D01CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D01D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D01D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D01D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D01DC: beq         $a1, $at, L_800D0334
    if (ctx->r5 == ctx->r1) {
        // 0x800D01E0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800D0334;
    }
    // 0x800D01E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D01E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800D01E8: bnel        $a1, $at, L_800D0398
    if (ctx->r5 != ctx->r1) {
        // 0x800D01EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_0;
    // 0x800D01EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D01F0: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800D01F4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D01F8: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800D01FC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D0200: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800D0204: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x800D0208: beql        $v0, $zero, L_800D0228
    if (ctx->r2 == 0) {
        // 0x800D020C: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_800D0228;
    }
    goto skip_1;
    // 0x800D020C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x800D0210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D0214: beq         $v0, $a0, L_800D02E8
    if (ctx->r2 == ctx->r4) {
        // 0x800D0218: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800D02E8;
    }
    // 0x800D0218: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800D021C: b           L_800D0398
    // 0x800D0220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D0398;
    // 0x800D0220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0224: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_800D0228:
    // 0x800D0228: addiu       $t7, $t7, 0x87C
    ctx->r15 = ADD32(ctx->r15, 0X87C);
    // 0x800D022C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800D0230: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800D0234: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D0238: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800D023C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D0240: bne         $a1, $zero, L_800D024C
    if (ctx->r5 != 0) {
        // 0x800D0244: nop

            goto L_800D024C;
    }
    // 0x800D0244: nop

    // 0x800D0248: break       7
    do_break(2148336200);
L_800D024C:
    // 0x800D024C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0250: bne         $a1, $at, L_800D0264
    if (ctx->r5 != ctx->r1) {
        // 0x800D0254: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D0264;
    }
    // 0x800D0254: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D0258: bne         $t8, $at, L_800D0264
    if (ctx->r24 != ctx->r1) {
        // 0x800D025C: nop

            goto L_800D0264;
    }
    // 0x800D025C: nop

    // 0x800D0260: break       6
    do_break(2148336224);
L_800D0264:
    // 0x800D0264: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0268: mflo        $t0
    ctx->r8 = lo;
    // 0x800D026C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800D0270: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800D0274: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800D0278: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800D027C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800D0280: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800D0284: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0288: mflo        $t4
    ctx->r12 = lo;
    // 0x800D028C: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x800D0290: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D0294: beql        $v1, $zero, L_800D02DC
    if (ctx->r3 == 0) {
        // 0x800D0298: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800D02DC;
    }
    goto skip_2;
    // 0x800D0298: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x800D029C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800D02A0: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x800D02A4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800D02A8: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x800D02AC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800D02B0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800D02B4: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800D02B8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800D02BC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800D02C0: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x800D02C4: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800D02C8: jal         0x800D6320
    // 0x800D02CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x800D02CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800D02D0: b           L_800D0398
    // 0x800D02D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D0398;
    // 0x800D02D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D02D8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800D02DC:
    // 0x800D02DC: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800D02E0: b           L_800D0394
    // 0x800D02E4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800D0394;
    // 0x800D02E4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800D02E8:
    // 0x800D02E8: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800D02EC: addiu       $t0, $t0, 0x3A4
    ctx->r8 = ADD32(ctx->r8, 0X3A4);
    // 0x800D02F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x800D02F4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D02F8: beql        $v1, $zero, L_800D0328
    if (ctx->r3 == 0) {
        // 0x800D02FC: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800D0328;
    }
    goto skip_3;
    // 0x800D02FC: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x800D0300: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800D0304: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x800D0308: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800D030C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800D0310: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x800D0314: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800D0318: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800D031C: b           L_800D0394
    // 0x800D0320: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_800D0394;
    // 0x800D0320: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x800D0324: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800D0328:
    // 0x800D0328: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800D032C: b           L_800D0394
    // 0x800D0330: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800D0394;
    // 0x800D0330: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800D0334:
    // 0x800D0334: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800D0338: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D033C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800D0340: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800D0344: beq         $v0, $zero, L_800D0394
    if (ctx->r2 == 0) {
        // 0x800D0348: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800D0394;
    }
    // 0x800D0348: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800D034C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D0350: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x800D0354: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x800D0358: bne         $v1, $zero, L_800D0378
    if (ctx->r3 != 0) {
        // 0x800D035C: nop

            goto L_800D0378;
    }
    // 0x800D035C: nop

    // 0x800D0360: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D0364: beql        $v1, $zero, L_800D0398
    if (ctx->r3 == 0) {
        // 0x800D0368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_4;
    // 0x800D0368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800D036C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800D0370: b           L_800D0394
    // 0x800D0374: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_800D0394;
    // 0x800D0374: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_800D0378:
    // 0x800D0378: bnel        $a0, $v1, L_800D0398
    if (ctx->r4 != ctx->r3) {
        // 0x800D037C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_5;
    // 0x800D037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800D0380: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D0384: beql        $v1, $zero, L_800D0398
    if (ctx->r3 == 0) {
        // 0x800D0388: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_6;
    // 0x800D0388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800D038C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800D0390: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_800D0394:
    // 0x800D0394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0398:
    // 0x800D0398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D039C: jr          $ra
    // 0x800D03A0: nop

    return;
    // 0x800D03A0: nop

;}
RECOMP_FUNC void alRaw16Pull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D03A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D03A8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800D03AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D03B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D03B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D03B8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800D03BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D03C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D03C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D03C8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800D03CC: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800D03D0: bne         $a2, $zero, L_800D03E0
    if (ctx->r6 != 0) {
        // 0x800D03D4: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_800D03E0;
    }
    // 0x800D03D4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800D03D8: b           L_800D0734
    // 0x800D03DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800D0734;
    // 0x800D03DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800D03E0:
    // 0x800D03E0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800D03E4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800D03E8: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x800D03EC: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800D03F0: beql        $at, $zero, L_800D0604
    if (ctx->r1 == 0) {
        // 0x800D03F4: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800D0604;
    }
    goto skip_0;
    // 0x800D03F4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x800D03F8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D03FC: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x800D0400: beql        $t7, $zero, L_800D0604
    if (ctx->r15 == 0) {
        // 0x800D0404: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800D0604;
    }
    goto skip_1;
    // 0x800D0404: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x800D0408: blez        $s2, L_800D0484
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800D040C: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_800D0484;
    }
    // 0x800D040C: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800D0410: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800D0414: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800D0418: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800D041C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D0420: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D0424: jalr        $t9
    // 0x800D0428: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0428: nop

    after_0:
    // 0x800D042C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800D0430: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800D0434: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800D0438: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800D043C: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x800D0440: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x800D0444: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x800D0448: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D044C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x800D0450: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800D0454: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D0458: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800D045C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D0460: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0464: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x800D0468: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800D046C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D0470: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800D0474: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800D0478: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D047C: b           L_800D0488
    // 0x800D0480: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D0488;
    // 0x800D0480: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D0484:
    // 0x800D0484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800D0488:
    // 0x800D0488: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800D048C: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D0490: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800D0494: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x800D0498: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800D049C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800D04A0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800D04A4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800D04A8: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800D04AC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D04B0: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x800D04B4: beq         $at, $zero, L_800D05DC
    if (ctx->r1 == 0) {
        // 0x800D04B8: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_800D05DC;
    }
    // 0x800D04B8: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x800D04BC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800D04C0:
    // 0x800D04C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D04C4: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800D04C8: beq         $v0, $at, L_800D04DC
    if (ctx->r2 == ctx->r1) {
        // 0x800D04CC: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_800D04DC;
    }
    // 0x800D04CC: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800D04D0: beq         $v0, $zero, L_800D04DC
    if (ctx->r2 == 0) {
        // 0x800D04D4: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800D04DC;
    }
    // 0x800D04D4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800D04D8: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_800D04DC:
    // 0x800D04DC: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800D04E0: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x800D04E4: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x800D04E8: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800D04EC: beq         $at, $zero, L_800D04FC
    if (ctx->r1 == 0) {
        // 0x800D04F0: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800D04FC;
    }
    // 0x800D04F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800D04F4: b           L_800D04FC
    // 0x800D04F8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_800D04FC;
    // 0x800D04F8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_800D04FC:
    // 0x800D04FC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800D0500: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800D0504: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800D0508: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800D050C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D0510: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800D0514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D0518: jalr        $t9
    // 0x800D051C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D051C: nop

    after_1:
    // 0x800D0520: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0524: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x800D0528: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D052C: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800D0530: beq         $v1, $zero, L_800D0544
    if (ctx->r3 == 0) {
        // 0x800D0534: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_800D0544;
    }
    // 0x800D0534: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x800D0538: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800D053C: b           L_800D0548
    // 0x800D0540: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_800D0548;
    // 0x800D0540: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_800D0544:
    // 0x800D0544: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800D0548:
    // 0x800D0548: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x800D054C: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x800D0550: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x800D0554: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D0558: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D055C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0560: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800D0564: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D0568: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800D056C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800D0570: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0574: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D0578: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800D057C: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800D0580: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800D0584: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800D0588: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800D058C: bne         $a1, $zero, L_800D0598
    if (ctx->r5 != 0) {
        // 0x800D0590: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800D0598;
    }
    // 0x800D0590: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D0594: beq         $a2, $zero, L_800D05D0
    if (ctx->r6 == 0) {
        // 0x800D0598: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_800D05D0;
    }
L_800D0598:
    // 0x800D0598: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x800D059C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D05A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D05A4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800D05A8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800D05AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D05B0: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800D05B4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800D05B8: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800D05BC: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x800D05C0: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x800D05C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D05C8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800D05CC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D05D0:
    // 0x800D05D0: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D05D4: bnel        $at, $zero, L_800D04C0
    if (ctx->r1 != 0) {
        // 0x800D05D8: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800D04C0;
    }
    goto skip_2;
    // 0x800D05D8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_800D05DC:
    // 0x800D05DC: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800D05E0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800D05E4: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800D05E8: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x800D05EC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800D05F0: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x800D05F4: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x800D05F8: b           L_800D0734
    // 0x800D05FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800D0734;
    // 0x800D05FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D0600: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_800D0604:
    // 0x800D0604: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800D0608: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x800D060C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D0610: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800D0614: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x800D0618: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x800D061C: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x800D0620: bgezl       $s2, L_800D0630
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800D0624: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800D0630;
    }
    goto skip_3;
    // 0x800D0624: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x800D0628: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D062C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_800D0630:
    // 0x800D0630: beql        $at, $zero, L_800D0640
    if (ctx->r1 == 0) {
        // 0x800D0634: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_800D0640;
    }
    goto skip_4;
    // 0x800D0634: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x800D0638: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800D063C: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_800D0640:
    // 0x800D0640: beql        $at, $zero, L_800D06F4
    if (ctx->r1 == 0) {
        // 0x800D0644: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_800D06F4;
    }
    goto skip_5;
    // 0x800D0644: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x800D0648: blez        $s3, L_800D06C8
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800D064C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800D06C8;
    }
    // 0x800D064C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0650: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800D0654: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x800D0658: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800D065C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800D0660: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D0664: jalr        $t9
    // 0x800D0668: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D0668: nop

    after_2:
    // 0x800D066C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800D0670: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800D0674: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800D0678: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x800D067C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800D0680: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x800D0684: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x800D0688: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x800D068C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0690: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800D0694: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0698: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800D069C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800D06A0: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800D06A4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D06A8: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x800D06AC: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800D06B0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D06B4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800D06B8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800D06BC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800D06C0: b           L_800D06C8
    // 0x800D06C4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D06C8;
    // 0x800D06C4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D06C8:
    // 0x800D06C8: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x800D06CC: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800D06D0: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x800D06D4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800D06D8: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800D06DC: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x800D06E0: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x800D06E4: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x800D06E8: b           L_800D06F4
    // 0x800D06EC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_800D06F4;
    // 0x800D06EC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x800D06F0: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_800D06F4:
    // 0x800D06F4: beq         $s2, $zero, L_800D0730
    if (ctx->r18 == 0) {
        // 0x800D06F8: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_800D0730;
    }
    // 0x800D06F8: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x800D06FC: bgez        $v1, L_800D0708
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0700: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800D0708;
    }
    // 0x800D0700: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D0704: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D0708:
    // 0x800D0708: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x800D070C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0710: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0714: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800D0718: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D071C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800D0720: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800D0724: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800D0728: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x800D072C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D0730:
    // 0x800D0730: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800D0734:
    // 0x800D0734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D0738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D073C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D0740: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0744: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D0748: jr          $ra
    // 0x800D074C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D074C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800D0750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0754: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D0758: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D075C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800D0760: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x800D0764: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D0768: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D076C: blez        $s1, L_800D07D8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800D0770: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D07D8;
    }
    // 0x800D0770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0774: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x800D0778: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x800D077C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D0780: jalr        $t9
    // 0x800D0784: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0784: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
    // 0x800D0788: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800D078C: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x800D0790: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800D0794: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0798: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D079C: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x800D07A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D07A4: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x800D07A8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800D07AC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800D07B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D07B4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800D07B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D07BC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800D07C0: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x800D07C4: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800D07C8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D07CC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800D07D0: b           L_800D07DC
    // 0x800D07D4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800D07DC;
    // 0x800D07D4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800D07D8:
    // 0x800D07D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800D07DC:
    // 0x800D07DC: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x800D07E0: beq         $t6, $zero, L_800D0808
    if (ctx->r14 == 0) {
        // 0x800D07E4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800D0808;
    }
    // 0x800D07E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D07E8: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x800D07EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D07F0: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800D07F4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800D07F8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D07FC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D0800: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D0804: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800D0808:
    // 0x800D0808: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x800D080C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800D0810: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0814: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800D0818: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D081C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D0820: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x800D0824: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D0828: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x800D082C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800D0830: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x800D0834: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D0838: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800D083C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800D0840: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D0844: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800D0848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D084C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D0850: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x800D0854: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800D0858: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D085C: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800D0860: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800D0864: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800D0868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D086C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D0870: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D0874: jr          $ra
    // 0x800D0878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D0878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alAdpcmPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D087C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800D0880: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800D0884: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800D0888: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D088C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800D0890: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800D0894: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800D0898: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800D089C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800D08A0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800D08A4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800D08A8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800D08AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800D08B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800D08B4: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800D08B8: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800D08BC: bne         $a2, $zero, L_800D08CC
    if (ctx->r6 != 0) {
        // 0x800D08C0: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800D08CC;
    }
    // 0x800D08C0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800D08C4: b           L_800D0CEC
    // 0x800D08C8: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_800D0CEC;
    // 0x800D08C8: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800D08CC:
    // 0x800D08CC: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x800D08D0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D08D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D08D8: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800D08DC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D08E0: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800D08E4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800D08E8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D08EC: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x800D08F0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800D08F4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D08F8: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800D08FC: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800D0900: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0904: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D0908: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D090C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800D0910: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x800D0914: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x800D0918: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800D091C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800D0920: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800D0924: beq         $t1, $zero, L_800D0938
    if (ctx->r9 == 0) {
        // 0x800D0928: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_800D0938;
    }
    // 0x800D0928: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800D092C: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x800D0930: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x800D0934: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_800D0938:
    // 0x800D0938: beq         $t1, $zero, L_800D0948
    if (ctx->r9 == 0) {
        // 0x800D093C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800D0948;
    }
    // 0x800D093C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D0940: b           L_800D0948
    // 0x800D0944: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_800D0948;
    // 0x800D0944: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_800D0948:
    // 0x800D0948: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800D094C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800D0950: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800D0954: beq         $v1, $zero, L_800D0964
    if (ctx->r3 == 0) {
        // 0x800D0958: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800D0964;
    }
    // 0x800D0958: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D095C: b           L_800D0964
    // 0x800D0960: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_800D0964;
    // 0x800D0960: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_800D0964:
    // 0x800D0964: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800D0968: bgez        $a0, L_800D0974
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D096C: nop

            goto L_800D0974;
    }
    // 0x800D096C: nop

    // 0x800D0970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800D0974:
    // 0x800D0974: beq         $t1, $zero, L_800D0B7C
    if (ctx->r9 == 0) {
        // 0x800D0978: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_800D0B7C;
    }
    // 0x800D0978: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800D097C: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800D0980: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800D0984: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800D0988: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800D098C: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800D0990: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800D0994: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800D0998: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800D099C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800D09A0: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800D09A4: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800D09A8: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x800D09AC: jal         0x800D0750
    // 0x800D09B0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_800D0750(rdram, ctx);
        goto after_0;
    // 0x800D09B0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x800D09B4: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800D09B8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800D09BC: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D09C0: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800D09C4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800D09C8: beq         $v1, $zero, L_800D09E4
    if (ctx->r3 == 0) {
        // 0x800D09CC: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800D09E4;
    }
    // 0x800D09CC: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800D09D0: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800D09D4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800D09D8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800D09DC: b           L_800D09F0
    // 0x800D09E0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_800D09F0;
    // 0x800D09E0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800D09E4:
    // 0x800D09E4: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800D09E8: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800D09EC: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_800D09F0:
    // 0x800D09F0: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x800D09F4: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x800D09F8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D09FC: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800D0A00: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800D0A04: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D0A08: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x800D0A0C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800D0A10: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800D0A14: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D0A18: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x800D0A1C: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x800D0A20: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x800D0A24: beq         $at, $zero, L_800D0B4C
    if (ctx->r1 == 0) {
        // 0x800D0A28: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_800D0B4C;
    }
    // 0x800D0A28: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x800D0A2C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800D0A30:
    // 0x800D0A30: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x800D0A34: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800D0A38: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x800D0A3C: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x800D0A40: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D0A44: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x800D0A48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0A4C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800D0A50: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800D0A54: beq         $v0, $at, L_800D0A68
    if (ctx->r2 == ctx->r1) {
        // 0x800D0A58: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_800D0A68;
    }
    // 0x800D0A58: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800D0A5C: beq         $v0, $zero, L_800D0A68
    if (ctx->r2 == 0) {
        // 0x800D0A60: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800D0A68;
    }
    // 0x800D0A60: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800D0A64: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_800D0A68:
    // 0x800D0A68: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x800D0A6C: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x800D0A70: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800D0A74: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800D0A78: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800D0A7C: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800D0A80: beq         $at, $zero, L_800D0A90
    if (ctx->r1 == 0) {
        // 0x800D0A84: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_800D0A90;
    }
    // 0x800D0A84: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x800D0A88: b           L_800D0A94
    // 0x800D0A8C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_800D0A94;
    // 0x800D0A8C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800D0A90:
    // 0x800D0A90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D0A94:
    // 0x800D0A94: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0A98: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800D0A9C: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x800D0AA0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800D0AA4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800D0AA8: bgez        $a0, L_800D0AB4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D0AAC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800D0AB4;
    }
    // 0x800D0AAC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D0AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800D0AB4:
    // 0x800D0AB4: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800D0AB8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800D0ABC: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800D0AC0: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800D0AC4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800D0AC8: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x800D0ACC: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800D0AD0: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800D0AD4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800D0AD8: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x800D0ADC: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800D0AE0: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x800D0AE4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800D0AE8: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800D0AEC: jal         0x800D0750
    // 0x800D0AF0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_800D0750(rdram, ctx);
        goto after_1;
    // 0x800D0AF0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x800D0AF4: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0AF8: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x800D0AFC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0B00: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800D0B04: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0B08: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x800D0B0C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800D0B10: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800D0B14: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800D0B18: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800D0B1C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0B20: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800D0B24: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800D0B28: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800D0B2C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800D0B30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D0B34: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800D0B38: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800D0B3C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D0B40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D0B44: bne         $at, $zero, L_800D0A30
    if (ctx->r1 != 0) {
        // 0x800D0B48: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_800D0A30;
    }
    // 0x800D0B48: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_800D0B4C:
    // 0x800D0B4C: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0B50: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800D0B54: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800D0B58: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800D0B5C: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800D0B60: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800D0B64: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800D0B68: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800D0B6C: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800D0B70: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800D0B74: b           L_800D0CEC
    // 0x800D0B78: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800D0CEC;
    // 0x800D0B78: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800D0B7C:
    // 0x800D0B7C: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x800D0B80: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800D0B84: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x800D0B88: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800D0B8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D0B90: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800D0B94: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800D0B98: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800D0B9C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800D0BA0: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x800D0BA4: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x800D0BA8: bgez        $v1, L_800D0BB4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0BAC: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_800D0BB4;
    }
    // 0x800D0BAC: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x800D0BB0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D0BB4:
    // 0x800D0BB4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800D0BB8: mflo        $v0
    ctx->r2 = lo;
    // 0x800D0BBC: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800D0BC0: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x800D0BC4: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D0BC8: beq         $at, $zero, L_800D0BD4
    if (ctx->r1 == 0) {
        // 0x800D0BCC: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800D0BD4;
    }
    // 0x800D0BCC: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800D0BD0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800D0BD4:
    // 0x800D0BD4: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800D0BD8: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x800D0BDC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D0BE0: beq         $at, $zero, L_800D0C90
    if (ctx->r1 == 0) {
        // 0x800D0BE4: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_800D0C90;
    }
    // 0x800D0BE4: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x800D0BE8: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800D0BEC: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800D0BF0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D0BF4: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800D0BF8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800D0BFC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800D0C00: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800D0C04: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800D0C08: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800D0C0C: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800D0C10: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x800D0C14: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800D0C18: jal         0x800D0750
    // 0x800D0C1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_800D0750(rdram, ctx);
        goto after_2;
    // 0x800D0C1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x800D0C20: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0C24: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800D0C28: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D0C2C: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800D0C30: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800D0C34: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800D0C38: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800D0C3C: beq         $v1, $zero, L_800D0C58
    if (ctx->r3 == 0) {
        // 0x800D0C40: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800D0C58;
    }
    // 0x800D0C40: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800D0C44: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800D0C48: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800D0C4C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D0C50: b           L_800D0C64
    // 0x800D0C54: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800D0C64;
    // 0x800D0C54: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800D0C58:
    // 0x800D0C58: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800D0C5C: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800D0C60: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800D0C64:
    // 0x800D0C64: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0C68: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800D0C6C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800D0C70: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800D0C74: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800D0C78: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800D0C7C: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800D0C80: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800D0C84: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800D0C88: b           L_800D0C98
    // 0x800D0C8C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800D0C98;
    // 0x800D0C8C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800D0C90:
    // 0x800D0C90: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800D0C94: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_800D0C98:
    // 0x800D0C98: beq         $a0, $zero, L_800D0CE8
    if (ctx->r4 == 0) {
        // 0x800D0C9C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800D0CE8;
    }
    // 0x800D0C9C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800D0CA0: beq         $t5, $zero, L_800D0CB8
    if (ctx->r13 == 0) {
        // 0x800D0CA4: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_800D0CB8;
    }
    // 0x800D0CA4: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800D0CA8: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x800D0CAC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800D0CB0: b           L_800D0CBC
    // 0x800D0CB4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_800D0CBC;
    // 0x800D0CB4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800D0CB8:
    // 0x800D0CB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D0CBC:
    // 0x800D0CBC: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800D0CC0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0CC4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0CC8: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800D0CCC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800D0CD0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800D0CD4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0CD8: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800D0CDC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D0CE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D0CE4: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_800D0CE8:
    // 0x800D0CE8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D0CEC:
    // 0x800D0CEC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800D0CF0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800D0CF4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0CF8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800D0CFC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800D0D00: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800D0D04: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800D0D08: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800D0D0C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800D0D10: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800D0D14: jr          $ra
    // 0x800D0D18: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800D0D18: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_800D0D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0D1C: nop

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
RECOMP_FUNC void alResamplePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0E0C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D0E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D0E14: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D0E18: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800D0E1C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800D0E20: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D0E24: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800D0E28: bne         $a2, $zero, L_800D0E38
    if (ctx->r6 != 0) {
        // 0x800D0E2C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_800D0E38;
    }
    // 0x800D0E2C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800D0E30: b           L_800D1004
    // 0x800D0E34: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_800D1004;
    // 0x800D0E34: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_800D0E38:
    // 0x800D0E38: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800D0E3C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800D0E40: beql        $t7, $zero, L_800D0EAC
    if (ctx->r15 == 0) {
        // 0x800D0E44: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_800D0EAC;
    }
    goto skip_0;
    // 0x800D0E44: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x800D0E48: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D0E4C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800D0E50: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800D0E54: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0E58: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800D0E5C: jalr        $t9
    // 0x800D0E60: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0E60: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800D0E64: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x800D0E68: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0E6C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0E70: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800D0E74: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800D0E78: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800D0E7C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800D0E80: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800D0E84: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800D0E88: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800D0E8C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800D0E90: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800D0E94: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800D0E98: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D0E9C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800D0EA0: b           L_800D1000
    // 0x800D0EA4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800D1000;
    // 0x800D0EA4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800D0EA8: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_800D0EAC:
    // 0x800D0EAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0EB0: ldc1        $f4, 0x2F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X2F8);
    // 0x800D0EB4: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl);
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800D0EB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0EBC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800D0EC0: nop

    // 0x800D0EC4: bc1fl       L_800D0EDC
    if (!c1cs) {
        // 0x800D0EC8: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_800D0EDC;
    }
    goto skip_1;
    // 0x800D0EC8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x800D0ECC: lwc1        $f8, 0x300($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X300);
    // 0x800D0ED0: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800D0ED4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0ED8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_800D0EDC:
    // 0x800D0EDC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800D0EE0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0EE4: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800D0EE8: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800D0EEC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D0EF0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800D0EF4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800D0EF8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800D0EFC: nop

    // 0x800D0F00: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D0F04: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D0F08: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800D0F0C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0F10: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800D0F14: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800D0F18: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800D0F1C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0F20: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800D0F24: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D0F28: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D0F2C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800D0F30: nop

    // 0x800D0F34: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800D0F38: nop

    // 0x800D0F3C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D0F40: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800D0F44: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800D0F48: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800D0F4C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800D0F50: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800D0F54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800D0F58: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800D0F5C: jalr        $t9
    // 0x800D0F60: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D0F60: nop

    after_1:
    // 0x800D0F64: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800D0F68: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x800D0F6C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D0F70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0F74: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800D0F78: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0F7C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800D0F80: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800D0F84: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0F88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D0F8C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800D0F90: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D0F94: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800D0F98: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800D0F9C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800D0FA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D0FA4: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800D0FA8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800D0FAC: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D0FB0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D0FB4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800D0FB8: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x800D0FBC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800D0FC0: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800D0FC4: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800D0FC8: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800D0FCC: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800D0FD0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800D0FD4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800D0FD8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800D0FDC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800D0FE0: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x800D0FE4: jal         0x800C79C0
    // 0x800D0FE8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D0FE8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x800D0FEC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800D0FF0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800D0FF4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800D0FF8: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800D0FFC: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_800D1000:
    // 0x800D1000: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800D1004:
    // 0x800D1004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1008: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D100C: jr          $ra
    // 0x800D1010: nop

    return;
    // 0x800D1010: nop

;}
RECOMP_FUNC void func_800D1014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1014: nop

    // 0x800D1018: nop

    // 0x800D101C: nop

;}
RECOMP_FUNC void _ldexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1020: beq         $a2, $zero, L_800D1040
    if (ctx->r6 == 0) {
        // 0x800D1024: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800D1040;
    }
    // 0x800D1024: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D1028: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x800D102C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800D1030: nop

    // 0x800D1034: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800D1038: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d);
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x800D103C: nop

L_800D1040:
    // 0x800D1040: jr          $ra
    // 0x800D1044: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800D1044: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
;}
RECOMP_FUNC void _frexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1048: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800D104C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D1050: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D1054: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D1058: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x800D105C: nop

    // 0x800D1060: bc1fl       L_800D1074
    if (!c1cs) {
        // 0x800D1064: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800D1074;
    }
    goto skip_0;
    // 0x800D1064: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_0:
    // 0x800D1068: jr          $ra
    // 0x800D106C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800D106C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800D1070: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800D1074:
    // 0x800D1074: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800D1078: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800D107C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D1080: bc1fl       L_800D1094
    if (!c1cs) {
        // 0x800D1084: neg.d       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d);
    ctx->f0.d = -ctx->f12.d;
            goto L_800D1094;
    }
    goto skip_1;
    // 0x800D1084: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d);
    ctx->f0.d = -ctx->f12.d;
    skip_1:
    // 0x800D1088: b           L_800D1094
    // 0x800D108C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800D1094;
    // 0x800D108C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800D1090: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d);
    ctx->f0.d = -ctx->f12.d;
L_800D1094:
    // 0x800D1094: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800D1098: nop

    // 0x800D109C: bc1fl       L_800D10D4
    if (!c1cs) {
        // 0x800D10A0: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800D10D4;
    }
    goto skip_2;
    // 0x800D10A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_2:
    // 0x800D10A4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D10A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D10AC: nop

L_800D10B0:
    // 0x800D10B0: mul.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d);
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x800D10B4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D10B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D10BC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D10C0: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800D10C4: nop

    // 0x800D10C8: bc1t        L_800D10B0
    if (c1cs) {
        // 0x800D10CC: nop

            goto L_800D10B0;
    }
    // 0x800D10CC: nop

    // 0x800D10D0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_800D10D4:
    // 0x800D10D4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D10D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D10DC: nop

    // 0x800D10E0: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800D10E4: nop

    // 0x800D10E8: bc1fl       L_800D1110
    if (!c1cs) {
        // 0x800D10EC: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800D1110;
    }
    goto skip_3;
    // 0x800D10EC: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x800D10F0: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d);
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
L_800D10F4:
    // 0x800D10F4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D10F8: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800D10FC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800D1100: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D1104: bc1tl       L_800D10F4
    if (c1cs) {
        // 0x800D1108: add.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d);
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
            goto L_800D10F4;
    }
    goto skip_4;
    // 0x800D1108: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d);
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    skip_4:
    // 0x800D110C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800D1110:
    // 0x800D1110: nop

    // 0x800D1114: bc1fl       L_800D1128
    if (!c1cs) {
        // 0x800D1118: neg.d       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d);
    ctx->f2.d = -ctx->f0.d;
            goto L_800D1128;
    }
    goto skip_5;
    // 0x800D1118: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d);
    ctx->f2.d = -ctx->f0.d;
    skip_5:
    // 0x800D111C: b           L_800D1128
    // 0x800D1120: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
        goto L_800D1128;
    // 0x800D1120: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x800D1124: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d);
    ctx->f2.d = -ctx->f0.d;
L_800D1128:
    // 0x800D1128: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x800D112C: jr          $ra
    // 0x800D1130: nop

    return;
    // 0x800D1130: nop

;}
RECOMP_FUNC void alEnvmixerParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1140: beq         $a1, $v0, L_800D11E0
    if (ctx->r5 == ctx->r2) {
        // 0x800D1144: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800D11E0;
    }
    // 0x800D1144: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D1148: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D114C: beq         $a1, $at, L_800D116C
    if (ctx->r5 == ctx->r1) {
        // 0x800D1150: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800D116C;
    }
    // 0x800D1150: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D1154: beq         $a1, $at, L_800D118C
    if (ctx->r5 == ctx->r1) {
        // 0x800D1158: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800D118C;
    }
    // 0x800D1158: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D115C: beql        $a1, $at, L_800D11BC
    if (ctx->r5 == ctx->r1) {
        // 0x800D1160: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_800D11BC;
    }
    goto skip_0;
    // 0x800D1160: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x800D1164: b           L_800D11EC
    // 0x800D1168: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
        goto L_800D11EC;
    // 0x800D1168: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800D116C:
    // 0x800D116C: lw          $v0, 0x40($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X40);
    // 0x800D1170: beql        $v0, $zero, L_800D1184
    if (ctx->r2 == 0) {
        // 0x800D1174: sw          $a2, 0x3C($a3)
        MEM_W(0X3C, ctx->r7) = ctx->r6;
            goto L_800D1184;
    }
    goto skip_1;
    // 0x800D1174: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x800D1178: b           L_800D1184
    // 0x800D117C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_800D1184;
    // 0x800D117C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800D1180: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
L_800D1184:
    // 0x800D1184: b           L_800D1200
    // 0x800D1188: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
        goto L_800D1200;
    // 0x800D1188: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
L_800D118C:
    // 0x800D118C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800D1190: sw          $v0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r2;
    // 0x800D1194: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x800D1198: beq         $a0, $zero, L_800D1200
    if (ctx->r4 == 0) {
        // 0x800D119C: sh          $v0, 0x1A($a3)
        MEM_H(0X1A, ctx->r7) = ctx->r2;
            goto L_800D1200;
    }
    // 0x800D119C: sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // 0x800D11A0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D11A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800D11A8: jalr        $t9
    // 0x800D11AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D11AC: nop

    after_0:
    // 0x800D11B0: b           L_800D1204
    // 0x800D11B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D1204;
    // 0x800D11B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D11B8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800D11BC:
    // 0x800D11BC: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x800D11C0: beql        $a0, $zero, L_800D1204
    if (ctx->r4 == 0) {
        // 0x800D11C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D1204;
    }
    goto skip_2;
    // 0x800D11C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800D11C8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D11CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D11D0: jalr        $t9
    // 0x800D11D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D11D4: nop

    after_1:
    // 0x800D11D8: b           L_800D1204
    // 0x800D11DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D1204;
    // 0x800D11DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D11E0:
    // 0x800D11E0: b           L_800D1200
    // 0x800D11E4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800D1200;
    // 0x800D11E4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x800D11E8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800D11EC:
    // 0x800D11EC: beql        $a0, $zero, L_800D1204
    if (ctx->r4 == 0) {
        // 0x800D11F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D1204;
    }
    goto skip_3;
    // 0x800D11F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800D11F4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D11F8: jalr        $t9
    // 0x800D11FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D11FC: nop

    after_2:
L_800D1200:
    // 0x800D1200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D1204:
    // 0x800D1204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D120C: jr          $ra
    // 0x800D1210: nop

    return;
    // 0x800D1210: nop

;}
RECOMP_FUNC void func_800D1214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1214: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800D1218: bne         $a0, $zero, L_800D1248
    if (ctx->r4 != 0) {
        // 0x800D121C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D1248;
    }
    // 0x800D121C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1220: c.le.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d <= ctx->f14.d;
    // 0x800D1224: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800D1228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D122C: bc1f        L_800D1240
    if (!c1cs) {
        // 0x800D1230: nop

            goto L_800D1240;
    }
    // 0x800D1230: nop

    // 0x800D1234: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x800D1238: b           L_800D13D4
    // 0x800D123C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800D13D4;
    // 0x800D123C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800D1240:
    // 0x800D1240: b           L_800D13D4
    // 0x800D1244: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
        goto L_800D13D4;
    // 0x800D1244: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_800D1248:
    // 0x800D1248: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D124C: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800D1250: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800D1254: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800D1258: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D125C: c.lt.d      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.d < ctx->f22.d;
    // 0x800D1260: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x800D1264: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1268: addiu       $t7, $t7, -0x3020
    ctx->r15 = ADD32(ctx->r15, -0X3020);
    // 0x800D126C: bc1f        L_800D1278
    if (!c1cs) {
        // 0x800D1270: or          $t6, $s2, $zero
        ctx->r14 = ctx->r18 | 0;
            goto L_800D1278;
    }
    // 0x800D1270: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x800D1274: mov.d       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.d = ctx->f22.d;
L_800D1278:
    // 0x800D1278: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x800D127C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D1280: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x800D1284: bc1f        L_800D1298
    if (!c1cs) {
        // 0x800D1288: nop

            goto L_800D1298;
    }
    // 0x800D1288: nop

    // 0x800D128C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D1290: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D1294: nop

L_800D1298:
    // 0x800D1298: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800D129C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800D12A0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800D12A4: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800D12A8: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800D12AC: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800D12B0: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800D12B4: bne         $t7, $t9, L_800D1298
    if (ctx->r15 != ctx->r25) {
        // 0x800D12B8: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_800D1298;
    }
    // 0x800D12B8: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800D12BC: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800D12C0: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x800D12C4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800D12C8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800D12CC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800D12D0: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800D12D4: cvt.d.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.d = CVT_D_W(ctx->f6.u32l);
    // 0x800D12D8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800D12DC: div.d       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = DIV_D(ctx->f22.d, ctx->f10.d);
    // 0x800D12E0: div.d       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f16.d);
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f16.d);
    // 0x800D12E4: mul.d       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d);
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x800D12E8: trunc.w.d   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800D12EC: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800D12F0: jal         0x800D1048
    // 0x800D12F4: nop

    _frexpf(rdram, ctx);
        goto after_0;
    // 0x800D12F4: nop

    after_0:
    // 0x800D12F8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800D12FC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800D1300: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800D1304: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D1308: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800D130C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800D1310: mul.d       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d);
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800D1314: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800D1318: ldc1        $f8, 0x310($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X310);
    // 0x800D131C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D1320: trunc.w.d   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800D1324: mov.d       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.d = ctx->f22.d;
    // 0x800D1328: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800D132C: nop

    // 0x800D1330: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800D1334: addu        $t7, $s2, $t9
    ctx->r15 = ADD32(ctx->r18, ctx->r25);
    // 0x800D1338: ldc1        $f6, -0x40($t7)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r15, -0X40);
    // 0x800D133C: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x800D1340: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D1344: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800D1348: mul.d       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800D134C: nop

    // 0x800D1350: mul.d       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d);
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x800D1354: div.d       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f14.d);
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f14.d);
    // 0x800D1358: beq         $s0, $zero, L_800D1380
    if (ctx->r16 == 0) {
        // 0x800D135C: add.d       $f0, $f22, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d);
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
            goto L_800D1380;
    }
    // 0x800D135C: add.d       $f0, $f22, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d);
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
L_800D1360:
    // 0x800D1360: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x800D1364: beq         $t8, $zero, L_800D1374
    if (ctx->r24 == 0) {
        // 0x800D1368: sra         $t9, $s0, 1
        ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
            goto L_800D1374;
    }
    // 0x800D1368: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800D136C: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d);
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x800D1370: nop

L_800D1374:
    // 0x800D1374: mul.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d);
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x800D1378: bne         $t9, $zero, L_800D1360
    if (ctx->r25 != 0) {
        // 0x800D137C: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_800D1360;
    }
    // 0x800D137C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800D1380:
    // 0x800D1380: mul.d       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d);
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D1384: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D1388: mul.d       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d);
    ctx->f12.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x800D138C: nop

    // 0x800D1390: mul.d       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d);
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f12.d);
    // 0x800D1394: trunc.w.d   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800D1398: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800D139C: nop

    // 0x800D13A0: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800D13A4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D13A8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800D13AC: nop

    // 0x800D13B0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D13B4: ldc1        $f4, 0x318($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X318);
    // 0x800D13B8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800D13BC: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x800D13C0: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800D13C4: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800D13C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800D13CC: nop

    // 0x800D13D0: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_800D13D4:
    // 0x800D13D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D13D8: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x800D13DC: jr          $ra
    // 0x800D13E0: nop

    return;
    // 0x800D13E0: nop

    // 0x800D13E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D13E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D13EC: lw          $t6, 0x48($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X48);
    // 0x800D13F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D13F4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800D13F8: bne         $t6, $at, L_800D1408
    if (ctx->r14 != ctx->r1) {
        // 0x800D13FC: nop

            goto L_800D1408;
    }
    // 0x800D13FC: nop

    // 0x800D1400: bnel        $s5, $zero, L_800D1414
    if (ctx->r21 != 0) {
        // 0x800D1404: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_800D1414;
    }
    goto skip_0;
    // 0x800D1404: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    skip_0:
L_800D1408:
    // 0x800D1408: b           L_800D166C
    // 0x800D140C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800D166C;
    // 0x800D140C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800D1410: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_800D1414:
    // 0x800D1414: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D1418: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800D141C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800D1420: jalr        $t9
    // 0x800D1424: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D1424: nop

    after_1:
    // 0x800D1428: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x800D142C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D1430: sll         $s7, $s5, 1
    ctx->r23 = S32(ctx->r21 << 1);
    // 0x800D1434: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D1438: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800D143C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D1440: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800D1444: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x800D1448: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
    // 0x800D144C: addiu       $t8, $t9, 0x440
    ctx->r24 = ADD32(ctx->r25, 0X440);
    // 0x800D1450: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800D1454: andi        $t9, $s7, 0xFFFF
    ctx->r25 = ctx->r23 & 0XFFFF;
    // 0x800D1458: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800D145C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D1460: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800D1464: addiu       $t6, $t8, 0x580
    ctx->r14 = ADD32(ctx->r24, 0X580);
    // 0x800D1468: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x800D146C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800D1470: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800D1474: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x800D1478: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800D147C: addiu       $t8, $v1, 0x800
    ctx->r24 = ADD32(ctx->r3, 0X800);
    // 0x800D1480: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800D1484: addiu       $t7, $v1, 0x6C0
    ctx->r15 = ADD32(ctx->r3, 0X6C0);
    // 0x800D1488: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800D148C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800D1490: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800D1494: lw          $t7, 0x38($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X38);
    // 0x800D1498: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800D149C: beql        $t7, $zero, L_800D163C
    if (ctx->r15 == 0) {
        // 0x800D14A0: lui         $t7, 0x308
        ctx->r15 = S32(0X308 << 16);
            goto L_800D163C;
    }
    goto skip_1;
    // 0x800D14A0: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
    skip_1:
    // 0x800D14A4: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x800D14A8: sw          $zero, 0x38($s3)
    MEM_W(0X38, ctx->r19) = 0;
    // 0x800D14AC: lh          $t7, 0x1A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1A);
    // 0x800D14B0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800D14B4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800D14B8: lh          $t9, -0x3120($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X3120);
    // 0x800D14BC: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x800D14C0: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x800D14C4: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D14C8: lh          $t9, 0x1C($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1C);
    // 0x800D14CC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800D14D0: nop

    // 0x800D14D4: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x800D14D8: mflo        $t6
    ctx->r14 = lo;
    // 0x800D14DC: sra         $t8, $t6, 15
    ctx->r24 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800D14E0: sh          $t8, 0x28($s3)
    MEM_H(0X28, ctx->r19) = ctx->r24;
    // 0x800D14E4: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x800D14E8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800D14EC: jal         0x800D1214
    // 0x800D14F0: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    func_800D1214(rdram, ctx);
        goto after_2;
    // 0x800D14F0: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_2:
    // 0x800D14F4: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x800D14F8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D14FC: sh          $v0, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r2;
    // 0x800D1500: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800D1504: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x800D1508: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800D150C: lh          $t7, -0x3022($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3022);
    // 0x800D1510: lh          $t6, 0x1A($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1A);
    // 0x800D1514: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x800D1518: addiu       $s1, $s3, 0x2A
    ctx->r17 = ADD32(ctx->r19, 0X2A);
    // 0x800D151C: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1520: lh          $t7, 0x1E($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1E);
    // 0x800D1524: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800D1528: nop

    // 0x800D152C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800D1530: mflo        $t8
    ctx->r24 = lo;
    // 0x800D1534: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x800D1538: sh          $t9, 0x2E($s3)
    MEM_H(0X2E, ctx->r19) = ctx->r25;
    // 0x800D153C: lh          $t6, 0x2E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2E);
    // 0x800D1540: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D1544: jal         0x800D1214
    // 0x800D1548: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    func_800D1214(rdram, ctx);
        goto after_3;
    // 0x800D1548: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_3:
    // 0x800D154C: lh          $t8, 0x1C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1C);
    // 0x800D1550: sh          $v0, 0x2C($s3)
    MEM_H(0X2C, ctx->r19) = ctx->r2;
    // 0x800D1554: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800D1558: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x800D155C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D1560: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800D1564: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D1568: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800D156C: lh          $t6, 0x1E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1E);
    // 0x800D1570: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800D1574: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D1578: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x800D157C: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800D1580: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800D1584: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800D1588: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D158C: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x800D1590: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800D1594: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x800D1598: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800D159C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800D15A0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D15A4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D15A8: lh          $t7, 0x26($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X26);
    // 0x800D15AC: lhu         $t9, 0x24($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X24);
    // 0x800D15B0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800D15B4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800D15B8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800D15BC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800D15C0: lh          $t8, 0x2E($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2E);
    // 0x800D15C4: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x800D15C8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800D15CC: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800D15D0: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800D15D4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D15D8: lh          $t8, 0x2C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2C);
    // 0x800D15DC: lhu         $t7, 0x2A($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X2A);
    // 0x800D15E0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800D15E4: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800D15E8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D15EC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800D15F0: lh          $t9, 0x20($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X20);
    // 0x800D15F4: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x800D15F8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800D15FC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800D1600: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D1604: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D1608: lh          $t8, 0x22($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X22);
    // 0x800D160C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800D1610: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800D1614: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D1618: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D161C: lui         $t6, 0x309
    ctx->r14 = S32(0X309 << 16);
    // 0x800D1620: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D1624: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800D1628: jal         0x800C79C0
    // 0x800D162C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800D162C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_4:
    // 0x800D1630: b           L_800D1650
    // 0x800D1634: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_800D1650;
    // 0x800D1634: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800D1638: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
L_800D163C:
    // 0x800D163C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800D1640: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800D1644: jal         0x800C79C0
    // 0x800D1648: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800D1648: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_5:
    // 0x800D164C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800D1650:
    // 0x800D1650: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
    // 0x800D1654: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800D1658: addu        $t9, $t8, $s7
    ctx->r25 = ADD32(ctx->r24, ctx->r23);
    // 0x800D165C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x800D1660: lw          $t6, 0x30($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X30);
    // 0x800D1664: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x800D1668: sw          $t7, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r15;
L_800D166C:
    // 0x800D166C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D1674: jr          $ra
    // 0x800D1678: nop

    return;
    // 0x800D1678: nop

    // 0x800D167C: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x800D1680: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800D1684: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x800D1688: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x800D168C: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x800D1690: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800D1694: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D1698: bne         $t9, $zero, L_800D16A8
    if (ctx->r25 != 0) {
        // 0x800D169C: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_800D16A8;
    }
    // 0x800D169C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800D16A0: jr          $ra
    // 0x800D16A4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x800D16A4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D16A8:
    // 0x800D16A8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800D16AC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D16B0: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800D16B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D16B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D16BC: bgez        $a2, L_800D16D4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800D16C0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D16D4;
    }
    // 0x800D16C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D16C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D16C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D16CC: nop

    // 0x800D16D0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800D16D4:
    // 0x800D16D4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D16D8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D16DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D16E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D16E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800D16E8: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800D16EC: div.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800D16F0: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
L_800D16F4:
    // 0x800D16F4: beq         $t7, $zero, L_800D1704
    if (ctx->r15 == 0) {
        // 0x800D16F8: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800D1704;
    }
    // 0x800D16F8: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800D16FC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl);
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800D1700: nop

L_800D1704:
    // 0x800D1704: beq         $t8, $zero, L_800D171C
    if (ctx->r24 == 0) {
        // 0x800D1708: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800D171C;
    }
    // 0x800D1708: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800D170C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D1710: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl);
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D1714: bnel        $v0, $v1, L_800D16F4
    if (ctx->r2 != ctx->r3) {
        // 0x800D1718: andi        $t7, $a0, 0x1
        ctx->r15 = ctx->r4 & 0X1;
            goto L_800D16F4;
    }
    goto skip_2;
    // 0x800D1718: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    skip_2:
L_800D171C:
    // 0x800D171C: mul.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl);
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800D1720: nop

    // 0x800D1724: jr          $ra
    // 0x800D1728: nop

    return;
    // 0x800D1728: nop

;}
RECOMP_FUNC void alEnvmixerPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D172C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800D1730: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800D1734: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800D1738: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800D173C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800D1740: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800D1744: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800D1748: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800D174C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800D1750: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800D1754: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800D1758: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800D175C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800D1760: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800D1764: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800D1768: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800D176C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800D1770: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800D1774: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x800D1778: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800D177C: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800D1780: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x800D1784: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800D1788: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800D178C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D1790: beql        $t8, $zero, L_800D1C04
    if (ctx->r24 == 0) {
        // 0x800D1794: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_800D1C04;
    }
    goto skip_0;
    // 0x800D1794: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    skip_0:
    // 0x800D1798: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_800D179C:
    // 0x800D179C: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x800D17A0: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x800D17A4: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800D17A8: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x800D17AC: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D17B0: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800D17B4: bne         $at, $zero, L_800D1C00
    if (ctx->r1 != 0) {
        // 0x800D17B8: sw          $t9, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r25;
            goto L_800D1C00;
    }
    // 0x800D17B8: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800D17BC: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x800D17C0: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x800D17C4: beq         $at, $zero, L_800D1B78
    if (ctx->r1 == 0) {
        // 0x800D17C8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D1B78;
    }
    // 0x800D17C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D17CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D17D0: addu        $at, $at, $t9
    gpr jr_addend_800D17D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D17D4: lw          $t9, 0x320($at)
    ctx->r25 = ADD32(ctx->r1, 0X320);
    // 0x800D17D8: jr          $t9
    // 0x800D17DC: nop

    switch (jr_addend_800D17D8 >> 2) {
        case 0: goto L_800D1B58; break;
        case 1: goto L_800D1B78; break;
        case 2: goto L_800D1B78; break;
        case 3: goto L_800D1B78; break;
        case 4: goto L_800D1B78; break;
        case 5: goto L_800D1B78; break;
        case 6: goto L_800D1B78; break;
        case 7: goto L_800D1B78; break;
        case 8: goto L_800D1B78; break;
        case 9: goto L_800D1B78; break;
        case 10: goto L_800D1B78; break;
        case 11: goto L_800D1920; break;
        case 12: goto L_800D1920; break;
        case 13: goto L_800D17E0; break;
        case 14: goto L_800D1AC4; break;
        case 15: goto L_800D1B18; break;
        case 16: goto L_800D1920; break;
        default: switch_error(__func__, 0x800D17D8, 0x800F0320);
    }
    // 0x800D17DC: nop

L_800D17E0:
    // 0x800D17E0: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x800D17E4: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800D17E8: beql        $t6, $zero, L_800D1808
    if (ctx->r14 == 0) {
        // 0x800D17EC: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_800D1808;
    }
    goto skip_1;
    // 0x800D17EC: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_1:
    // 0x800D17F0: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D17F4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D17F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D17FC: jalr        $t9
    // 0x800D1800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D1800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800D1804: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_800D1808:
    // 0x800D1808: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D180C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800D1810: jalr        $t9
    // 0x800D1814: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D1814: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x800D1818: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D181C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1820: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D1824: jalr        $t9
    // 0x800D1828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D1828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800D182C: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
    // 0x800D1830: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800D1834: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D1838: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800D183C: lh          $v1, 0x10($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X10);
    // 0x800D1840: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1844: mflo        $a0
    ctx->r4 = lo;
    // 0x800D1848: sra         $t7, $a0, 15
    ctx->r15 = S32(SIGNED(ctx->r4) >> 15);
    // 0x800D184C: sh          $t7, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r15;
    // 0x800D1850: lbu         $t6, 0x12($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X12);
    // 0x800D1854: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1858: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800D185C: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800D1860: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800D1864: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D1868: lh          $t7, -0x3120($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3120);
    // 0x800D186C: sh          $t7, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r15;
    // 0x800D1870: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x800D1874: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1878: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800D187C: negu        $t8, $t9
    ctx->r24 = SUB32(0, ctx->r25);
    // 0x800D1880: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D1884: lh          $t7, -0x3022($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3022);
    // 0x800D1888: sh          $t7, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r15;
    // 0x800D188C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D1890: beql        $t6, $zero, L_800D18A8
    if (ctx->r14 == 0) {
        // 0x800D1894: lh          $v0, 0x18($fp)
        ctx->r2 = MEM_H(ctx->r30, 0X18);
            goto L_800D18A8;
    }
    goto skip_2;
    // 0x800D1894: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    skip_2:
    // 0x800D1898: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800D189C: b           L_800D18EC
    // 0x800D18A0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
        goto L_800D18EC;
    // 0x800D18A0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800D18A4: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
L_800D18A8:
    // 0x800D18A8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800D18AC: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x800D18B0: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800D18B4: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800D18B8: lh          $t8, -0x3120($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3120);
    // 0x800D18BC: negu        $t9, $t9
    ctx->r25 = SUB32(0, ctx->r25);
    // 0x800D18C0: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D18C4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800D18C8: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800D18CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800D18D0: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800D18D4: sh          $t6, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r14;
    // 0x800D18D8: lh          $t8, -0x3022($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3022);
    // 0x800D18DC: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D18E0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D18E4: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800D18E8: sh          $t6, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r14;
L_800D18EC:
    // 0x800D18EC: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800D18F0: beql        $t9, $zero, L_800D1BB8
    if (ctx->r25 == 0) {
        // 0x800D18F4: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_800D1BB8;
    }
    goto skip_3;
    // 0x800D18F4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_3:
    // 0x800D18F8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800D18FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800D1900: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800D1904: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800D1908: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800D190C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D1910: jalr        $t9
    // 0x800D1914: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800D1914: nop

    after_3:
    // 0x800D1918: b           L_800D1BB8
    // 0x800D191C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D191C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1920:
    // 0x800D1920: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800D1924: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1928: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D192C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800D1930: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1934: jal         0x800D13E4
    // 0x800D1938: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_1_800D13E4(rdram, ctx);
        goto after_4;
    // 0x800D1938: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_4:
    // 0x800D193C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1940: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x800D1944: lw          $a3, 0x30($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X30);
    // 0x800D1948: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D194C: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D1950: bnel        $at, $zero, L_800D19BC
    if (ctx->r1 != 0) {
        // 0x800D1954: lh          $t6, 0x1C($fp)
        ctx->r14 = MEM_H(ctx->r30, 0X1C);
            goto L_800D19BC;
    }
    goto skip_4;
    // 0x800D1954: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
    skip_4:
    // 0x800D1958: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    // 0x800D195C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1960: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x800D1964: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800D1968: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D196C: lh          $t7, -0x3120($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3120);
    // 0x800D1970: negu        $t8, $t8
    ctx->r24 = SUB32(0, ctx->r24);
    // 0x800D1974: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1978: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D197C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D1980: mflo        $t6
    ctx->r14 = lo;
    // 0x800D1984: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800D1988: sh          $t9, 0x28($fp)
    MEM_H(0X28, ctx->r30) = ctx->r25;
    // 0x800D198C: lh          $t7, -0x3022($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3022);
    // 0x800D1990: lh          $t8, 0x28($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X28);
    // 0x800D1994: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800D1998: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D199C: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800D19A0: mflo        $t6
    ctx->r14 = lo;
    // 0x800D19A4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800D19A8: sh          $t9, 0x2E($fp)
    MEM_H(0X2E, ctx->r30) = ctx->r25;
    // 0x800D19AC: lh          $t7, 0x2E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X2E);
    // 0x800D19B0: b           L_800D1A0C
    // 0x800D19B4: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
        goto L_800D1A0C;
    // 0x800D19B4: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
    // 0x800D19B8: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
L_800D19BC:
    // 0x800D19BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D19C0: lh          $a1, 0x26($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X26);
    // 0x800D19C4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D19C8: lhu         $a2, 0x24($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X24);
    // 0x800D19CC: jal         0x800D167C
    // 0x800D19D0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    static_1_800D167C(rdram, ctx);
        goto after_5;
    // 0x800D19D0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x800D19D4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D19D8: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    // 0x800D19DC: lw          $a0, 0x30($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X30);
    // 0x800D19E0: lh          $a1, 0x2C($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X2C);
    // 0x800D19E4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800D19E8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800D19EC: lhu         $a2, 0x2A($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X2A);
    // 0x800D19F0: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800D19F4: jal         0x800D167C
    // 0x800D19F8: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    static_1_800D167C(rdram, ctx);
        goto after_6;
    // 0x800D19F8: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_6:
    // 0x800D19FC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D1A00: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800D1A04: nop

    // 0x800D1A08: sh          $t9, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r25;
L_800D1A0C:
    // 0x800D1A0C: lh          $t8, 0x1C($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X1C);
    // 0x800D1A10: bnel        $t8, $zero, L_800D1A20
    if (ctx->r24 != 0) {
        // 0x800D1A14: lh          $t7, 0x1E($fp)
        ctx->r15 = MEM_H(ctx->r30, 0X1E);
            goto L_800D1A20;
    }
    goto skip_5;
    // 0x800D1A14: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    skip_5:
    // 0x800D1A18: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800D1A1C: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
L_800D1A20:
    // 0x800D1A20: bnel        $t7, $zero, L_800D1A30
    if (ctx->r15 != 0) {
        // 0x800D1A24: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_800D1A30;
    }
    goto skip_6;
    // 0x800D1A24: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_6:
    // 0x800D1A28: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800D1A2C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_800D1A30:
    // 0x800D1A30: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800D1A34: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800D1A38: bnel        $a0, $at, L_800D1A50
    if (ctx->r4 != ctx->r1) {
        // 0x800D1A3C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800D1A50;
    }
    goto skip_7;
    // 0x800D1A3C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_7:
    // 0x800D1A40: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x800D1A44: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800D1A48: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800D1A4C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_800D1A50:
    // 0x800D1A50: bnel        $a0, $at, L_800D1A80
    if (ctx->r4 != ctx->r1) {
        // 0x800D1A54: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800D1A80;
    }
    goto skip_8;
    // 0x800D1A54: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x800D1A58: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800D1A5C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800D1A60: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1A64: mflo        $v0
    ctx->r2 = lo;
    // 0x800D1A68: sra         $t9, $v0, 15
    ctx->r25 = S32(SIGNED(ctx->r2) >> 15);
    // 0x800D1A6C: sh          $t9, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r25;
    // 0x800D1A70: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x800D1A74: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800D1A78: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800D1A7C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_800D1A80:
    // 0x800D1A80: bne         $a0, $at, L_800D1ABC
    if (ctx->r4 != ctx->r1) {
        // 0x800D1A84: nop

            goto L_800D1ABC;
    }
    // 0x800D1A84: nop

    // 0x800D1A88: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800D1A8C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800D1A90: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800D1A94: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800D1A98: lh          $t9, -0x3120($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X3120);
    // 0x800D1A9C: sh          $t9, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r25;
    // 0x800D1AA0: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800D1AA4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800D1AA8: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800D1AAC: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x800D1AB0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800D1AB4: lh          $t9, -0x3022($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X3022);
    // 0x800D1AB8: sh          $t9, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r25;
L_800D1ABC:
    // 0x800D1ABC: b           L_800D1BB4
    // 0x800D1AC0: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
        goto L_800D1BB4;
    // 0x800D1AC0: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
L_800D1AC4:
    // 0x800D1AC4: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x800D1AC8: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800D1ACC: beql        $t8, $zero, L_800D1AEC
    if (ctx->r24 == 0) {
        // 0x800D1AD0: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_800D1AEC;
    }
    goto skip_9;
    // 0x800D1AD0: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_9:
    // 0x800D1AD4: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1AD8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1ADC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D1AE0: jalr        $t9
    // 0x800D1AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x800D1AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800D1AE8: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_800D1AEC:
    // 0x800D1AEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1AF0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800D1AF4: jalr        $t9
    // 0x800D1AF8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800D1AF8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x800D1AFC: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1B00: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1B04: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D1B08: jalr        $t9
    // 0x800D1B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800D1B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800D1B10: b           L_800D1BB8
    // 0x800D1B14: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D1B14: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1B18:
    // 0x800D1B18: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800D1B1C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1B20: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D1B24: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800D1B28: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1B2C: jal         0x800D13E4
    // 0x800D1B30: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_1_800D13E4(rdram, ctx);
        goto after_10;
    // 0x800D1B30: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_10:
    // 0x800D1B34: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1B38: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1B3C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D1B40: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1B44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800D1B48: jalr        $t9
    // 0x800D1B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800D1B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800D1B50: b           L_800D1BB8
    // 0x800D1B54: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D1B54: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1B58:
    // 0x800D1B58: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800D1B5C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D1B60: lw          $a0, -0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33E0);
    // 0x800D1B64: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x800D1B68: jal         0x800C7B50
    // 0x800D1B6C: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    _freePVoice(rdram, ctx);
        goto after_12;
    // 0x800D1B6C: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_12:
    // 0x800D1B70: b           L_800D1BB8
    // 0x800D1B74: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800D1BB8;
    // 0x800D1B74: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1B78:
    // 0x800D1B78: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800D1B7C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1B80: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D1B84: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800D1B88: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1B8C: jal         0x800D13E4
    // 0x800D1B90: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_1_800D13E4(rdram, ctx);
        goto after_13;
    // 0x800D1B90: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_13:
    // 0x800D1B94: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1B98: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800D1B9C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    // 0x800D1BA0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D1BA4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1BA8: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x800D1BAC: jalr        $t9
    // 0x800D1BB0: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800D1BB0: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_14:
L_800D1BB4:
    // 0x800D1BB4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800D1BB8:
    // 0x800D1BB8: lh          $t6, 0x8E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8E);
    // 0x800D1BBC: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800D1BC0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800D1BC4: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800D1BC8: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
    // 0x800D1BCC: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x800D1BD0: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800D1BD4: lw          $a0, 0x3C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X3C);
    // 0x800D1BD8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800D1BDC: bne         $t9, $zero, L_800D1BE8
    if (ctx->r25 != 0) {
        // 0x800D1BE0: sw          $t9, 0x3C($fp)
        MEM_W(0X3C, ctx->r30) = ctx->r25;
            goto L_800D1BE8;
    }
    // 0x800D1BE0: sw          $t9, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r25;
    // 0x800D1BE4: sw          $zero, 0x40($fp)
    MEM_W(0X40, ctx->r30) = 0;
L_800D1BE8:
    // 0x800D1BE8: jal         0x800C7BE8
    // 0x800D1BEC: nop

    __freeParam(rdram, ctx);
        goto after_15;
    // 0x800D1BEC: nop

    after_15:
    // 0x800D1BF0: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800D1BF4: lw          $t7, 0x3C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X3C);
    // 0x800D1BF8: bnel        $t7, $zero, L_800D179C
    if (ctx->r15 != 0) {
        // 0x800D1BFC: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_800D179C;
    }
    goto skip_10;
    // 0x800D1BFC: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_10:
L_800D1C00:
    // 0x800D1C00: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
L_800D1C04:
    // 0x800D1C04: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800D1C08: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800D1C0C: lw          $s5, 0xB0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB0);
    // 0x800D1C10: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D1C14: jal         0x800D13E4
    // 0x800D1C18: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    static_1_800D13E4(rdram, ctx);
        goto after_16;
    // 0x800D1C18: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_16:
    // 0x800D1C1C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800D1C20: lw          $t9, 0x30($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X30);
    // 0x800D1C24: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x800D1C28: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D1C2C: beql        $at, $zero, L_800D1C3C
    if (ctx->r1 == 0) {
        // 0x800D1C30: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800D1C3C;
    }
    goto skip_11;
    // 0x800D1C30: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_11:
    // 0x800D1C34: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800D1C38: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800D1C3C:
    // 0x800D1C3C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x800D1C40: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800D1C44: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800D1C48: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800D1C4C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800D1C50: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800D1C54: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1C58: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800D1C5C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C60: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800D1C64: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1C68: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800D1C6C: jr          $ra
    // 0x800D1C70: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800D1C70: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800D1C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C74: nop

    // 0x800D1C78: nop

    // 0x800D1C7C: nop

;}
RECOMP_FUNC void alAuxBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D1C84: bne         $a1, $at, L_800D1CA8
    if (ctx->r5 != ctx->r1) {
        // 0x800D1C88: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800D1CA8;
    }
    // 0x800D1C88: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800D1C8C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800D1C90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D1C94: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800D1C98: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800D1C9C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800D1CA0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800D1CA4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800D1CA8:
    // 0x800D1CA8: jr          $ra
    // 0x800D1CAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D1CAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1CB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D1CB4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800D1CB8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D1CBC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D1CC0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D1CC4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D1CC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D1CCC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D1CD0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D1CD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D1CD8: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800D1CDC: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800D1CE0: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800D1CE4: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800D1CE8: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x800D1CEC: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x800D1CF0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800D1CF4: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800D1CF8: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800D1CFC: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800D1D00: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800D1D04: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800D1D08: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800D1D0C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800D1D10: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D1D14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D1D18: blez        $t8, L_800D1D5C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800D1D1C: addiu       $s2, $t0, 0x10
        ctx->r18 = ADD32(ctx->r8, 0X10);
            goto L_800D1D5C;
    }
    // 0x800D1D1C: addiu       $s2, $t0, 0x10
    ctx->r18 = ADD32(ctx->r8, 0X10);
    // 0x800D1D20: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800D1D24:
    // 0x800D1D24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D1D28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D1D2C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D1D30: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D1D34: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800D1D38: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800D1D3C: jalr        $t9
    // 0x800D1D40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D1D40: nop

    after_0:
    // 0x800D1D44: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x800D1D48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D1D4C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800D1D50: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D1D54: bne         $at, $zero, L_800D1D24
    if (ctx->r1 != 0) {
        // 0x800D1D58: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800D1D24;
    }
    // 0x800D1D58: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800D1D5C:
    // 0x800D1D5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1D60: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800D1D64: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D1D68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D1D6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D1D70: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1D74: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D1D78: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D1D7C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D1D80: jr          $ra
    // 0x800D1D84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D1D84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
