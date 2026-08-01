#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void static_5_800C82F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
RECOMP_FUNC void static_5_800C85DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
    goto skip_0;
    // 0x800C8608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
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
    goto skip_1;
    // 0x800C866C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_1:
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
    goto skip_2;
    // 0x800C8730: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
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
    goto skip_3;
    // 0x800C8788: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
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

;}
RECOMP_FUNC void static_5_800C87AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
    goto skip_0;
    // 0x800C87F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
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
        goto after_0;
    // 0x800C8818: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_0:
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
        goto after_1;
    // 0x800C8850: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    after_1:
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
        goto after_2;
    // 0x800C886C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
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
    goto skip_1;
    // 0x800C8890: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
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
        goto after_3;
    // 0x800C88D0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
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
    goto skip_2;
    // 0x800C891C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x800C8920: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800C8924: beql        $v0, $zero, L_800C8984
    if (ctx->r2 == 0) {
        // 0x800C8928: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800C8984;
    }
    goto skip_3;
    // 0x800C8928: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
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
        goto after_4;
    // 0x800C8948: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
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
        goto after_5;
    // 0x800C8970: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_5:
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
    goto skip_4;
    // 0x800C89A8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
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
    goto skip_5;
    // 0x800C8A20: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_5:
    // 0x800C8A24: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800C8A28: beql        $v0, $zero, L_800C8A8C
    if (ctx->r2 == 0) {
        // 0x800C8A2C: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800C8A8C;
    }
    goto skip_6;
    // 0x800C8A2C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_6:
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
        goto after_6;
    // 0x800C8A4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
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
        goto after_7;
    // 0x800C8A78: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_7:
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
        goto after_8;
    // 0x800C8AC0: nop

    after_8:
    // 0x800C8AC4: andi        $fp, $v0, 0xFF
    ctx->r30 = ctx->r2 & 0XFF;
    // 0x800C8AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8ACC: jal         0x800D2184
    // 0x800C8AD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_9;
    // 0x800C8AD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
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
        goto after_10;
    // 0x800C8AFC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
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
        goto after_11;
    // 0x800C8B34: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    after_11:
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
    goto skip_7;
    // 0x800C8B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
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
        goto after_12;
    // 0x800C8B84: nop

    after_12:
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
        goto after_13;
    // 0x800C8B9C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_13:
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
        goto after_14;
    // 0x800C8BDC: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_14:
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
        goto after_15;
    // 0x800C8BF4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_15:
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
        goto after_16;
    // 0x800C8C0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
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
        goto after_17;
    // 0x800C8C24: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_17:
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
        goto after_18;
    // 0x800C8C40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
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
    goto skip_8;
    // 0x800C8C54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
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
    goto skip_9;
    // 0x800C8C6C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x800C8C70: jal         0x800D2184
    // 0x800C8C74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    __vsVol(rdram, ctx);
        goto after_19;
    // 0x800C8C74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    after_19:
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
        goto after_20;
    // 0x800C8C8C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_20:
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
        goto after_21;
    // 0x800C8CA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x800C8CAC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8CB0:
    // 0x800C8CB0: bnel        $s0, $zero, L_800C8C60
    if (ctx->r16 != 0) {
        // 0x800C8CB4: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8C60;
    }
    goto skip_10;
    // 0x800C8CB4: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_10:
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
    goto skip_11;
    // 0x800C8CEC: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    skip_11:
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
    goto skip_12;
    // 0x800C8D10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
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
    goto skip_13;
    // 0x800C8D24: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x800C8D28: jal         0x800D25A4
    // 0x800C8D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsPan(rdram, ctx);
        goto after_22;
    // 0x800C8D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
    // 0x800C8D30: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C8D34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C8D38: jal         0x800D4220
    // 0x800C8D3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_23;
    // 0x800C8D3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_23:
    // 0x800C8D40: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8D44:
    // 0x800C8D44: bnel        $s0, $zero, L_800C8D1C
    if (ctx->r16 != 0) {
        // 0x800C8D48: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8D1C;
    }
    goto skip_14;
    // 0x800C8D48: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_14:
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
    goto skip_15;
    // 0x800C8D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
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
    goto skip_16;
    // 0x800C8D80: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
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
    goto skip_17;
    // 0x800C8D90: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x800C8D94: jal         0x800D2184
    // 0x800C8D98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_24;
    // 0x800C8D98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
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
        goto after_25;
    // 0x800C8DB0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_25:
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
        goto after_26;
    // 0x800C8DCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x800C8DD0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8DD4:
    // 0x800C8DD4: bnel        $s0, $zero, L_800C8D7C
    if (ctx->r16 != 0) {
        // 0x800C8DD8: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8D7C;
    }
    goto skip_18;
    // 0x800C8DD8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_18:
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
    goto skip_19;
    // 0x800C8E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
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
    goto skip_20;
    // 0x800C8E34: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
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
    goto skip_21;
    // 0x800C8E44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
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
    goto skip_22;
    // 0x800C8E54: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
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
    goto skip_23;
    // 0x800C8E74: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
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
        goto after_27;
    // 0x800C8E90: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    after_27:
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
    goto skip_24;
    // 0x800C8E9C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_24:
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
    goto skip_25;
    // 0x800C8EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
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
    goto skip_26;
    // 0x800C8ED8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x800C8EDC: jal         0x800D42B0
    // 0x800C8EE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    alSynSetFXMix(rdram, ctx);
        goto after_28;
    // 0x800C8EE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_28:
    // 0x800C8EE4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8EE8:
    // 0x800C8EE8: bnel        $s0, $zero, L_800C8ECC
    if (ctx->r16 != 0) {
        // 0x800C8EEC: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8ECC;
    }
    goto skip_27;
    // 0x800C8EEC: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_27:
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
    goto skip_28;
    // 0x800C8F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x800C8F1C: jal         0x800D1FD0
    // 0x800C8F20: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    __setInstChanState(rdram, ctx);
        goto after_29;
    // 0x800C8F20: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    after_29:
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
        goto after_30;
    // 0x800C8F64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_30:
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
    goto skip_29;
    // 0x800C8F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
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
    goto skip_30;
    // 0x800C8F90: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
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
        goto after_31;
    // 0x800C8FB4: nop

    after_31:
    // 0x800C8FB8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C8FBC:
    // 0x800C8FBC: bnel        $s0, $zero, L_800C8F8C
    if (ctx->r16 != 0) {
        // 0x800C8FC0: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800C8F8C;
    }
    goto skip_31;
    // 0x800C8FC0: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_31:
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
    goto skip_32;
    // 0x800C9048: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_32:
    // 0x800C904C: jal         0x800CA444
    // 0x800C9050: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alCSeqNextEvent(rdram, ctx);
        goto after_32;
    // 0x800C9050: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_32:
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
    static_5_800C87AC(rdram, ctx);
        goto after_33;
    // 0x800C9088: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_33:
    // 0x800C908C: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800C9090: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9094: jal         0x800C8530
    // 0x800C9098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_34;
    // 0x800C9098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
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
    static_5_800C85DC(rdram, ctx);
        goto after_35;
    // 0x800C90B4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_35:
    // 0x800C90B8: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800C90BC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800C90C0: jal         0x800C8530
    // 0x800C90C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_36;
    // 0x800C90C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_36:
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
        goto after_37;
    // 0x800C90F0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_37:
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
        goto after_38;
    // 0x800C9100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_38:
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
        goto after_39;
    // 0x800C9120: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_39:
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
        goto after_40;
    // 0x800C9138: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_40:
    // 0x800C913C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C9140: jal         0x800D3D20
    // 0x800C9144: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_41;
    // 0x800C9144: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_41:
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
    goto skip_33;
    // 0x800C9158: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_33:
    // 0x800C915C: jal         0x800D3610
    // 0x800C9160: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_42;
    // 0x800C9160: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_42:
    // 0x800C9164: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C9168:
    // 0x800C9168: jal         0x800D23E0
    // 0x800C916C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_43;
    // 0x800C916C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_43:
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
    goto skip_34;
    // 0x800C918C: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    skip_34:
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
        goto after_44;
    // 0x800C91B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    after_44:
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
        goto after_45;
    // 0x800C91D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_45:
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
        goto after_46;
    // 0x800C91F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_46:
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
    goto skip_35;
    // 0x800C9228: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_35:
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
        goto after_47;
    // 0x800C9288: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    after_47:
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
        goto after_48;
    // 0x800C92A0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_48:
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
        goto after_49;
    // 0x800C92BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_49:
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
        goto after_50;
    // 0x800C92DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_50:
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
        goto after_51;
    // 0x800C9300: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_51:
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
        goto after_52;
    // 0x800C9340: nop

    after_52:
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
        goto after_53;
    // 0x800C9364: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_53:
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
    static_5_800C87AC(rdram, ctx);
        goto after_54;
    // 0x800C937C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_54:
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
    static_5_800C85DC(rdram, ctx);
        goto after_55;
    // 0x800C939C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_55:
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
        goto after_56;
    // 0x800C93C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_56:
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
        goto after_57;
    // 0x800C93DC: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_57:
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
        goto after_58;
    // 0x800C93F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_58:
    // 0x800C93FC: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800C9400: bnel        $s1, $zero, L_800C93C0
    if (ctx->r17 != 0) {
        // 0x800C9404: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C93C0;
    }
    goto skip_36;
    // 0x800C9404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_36:
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
        goto after_59;
    // 0x800C9428: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    after_59:
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
    goto skip_37;
    // 0x800C9440: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_37:
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
        goto after_60;
    // 0x800C9458: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_60:
    // 0x800C945C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800C9460: jal         0x800D3D20
    // 0x800C9464: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_61;
    // 0x800C9464: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_61:
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
    goto skip_38;
    // 0x800C9474: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_38:
    // 0x800C9478: jal         0x800D3610
    // 0x800C947C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_62;
    // 0x800C947C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_62:
    // 0x800C9480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C9484:
    // 0x800C9484: jal         0x800D23E0
    // 0x800C9488: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_63;
    // 0x800C9488: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_63:
    // 0x800C948C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800C9490: bnel        $s1, $zero, L_800C9450
    if (ctx->r17 != 0) {
        // 0x800C9494: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C9450;
    }
    goto skip_39;
    // 0x800C9494: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_39:
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
    goto skip_40;
    // 0x800C94B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_40:
    // 0x800C94B4: jal         0x800D3910
    // 0x800C94B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_64;
    // 0x800C94B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_64:
    // 0x800C94BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C94C0: jal         0x800D3910
    // 0x800C94C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    alEvtqFlushType(rdram, ctx);
        goto after_65;
    // 0x800C94C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_65:
    // 0x800C94C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C94CC: jal         0x800D3910
    // 0x800C94D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_66;
    // 0x800C94D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_66:
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
        goto after_67;
    // 0x800C94EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_67:
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
        goto after_68;
    // 0x800C9500: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_68:
L_800C9504:
    // 0x800C9504: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800C9508: bnel        $s1, $zero, L_800C94E0
    if (ctx->r17 != 0) {
        // 0x800C950C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C94E0;
    }
    goto skip_41;
    // 0x800C950C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_41:
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
        goto after_69;
    // 0x800C9530: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_69:
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
        goto after_70;
    // 0x800C956C: lwc1        $f12, 0x1A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1A4);
    after_70:
    // 0x800C9570: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x800C9574: beql        $a1, $zero, L_800C95A0
    if (ctx->r5 == 0) {
        // 0x800C9578: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C95A0;
    }
    goto skip_42;
    // 0x800C9578: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_42:
    // 0x800C957C: jal         0x800D20A4
    // 0x800C9580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_71;
    // 0x800C9580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_71:
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
        goto after_72;
    // 0x800C9598: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_72:
L_800C959C:
    // 0x800C959C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C95A0:
    // 0x800C95A0: jal         0x800D3B50
    // 0x800C95A4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    alEvtqNextEvent(rdram, ctx);
        goto after_73;
    // 0x800C95A4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_73:
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
RECOMP_FUNC void static_5_800CA3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA3E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA3EC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800CA3F0: jal         0x800CA320
    // 0x800CA3F4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800CA320(rdram, ctx);
        goto after_0;
    // 0x800CA3F4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800CA3F8: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800CA3FC: beq         $t6, $zero, L_800CA428
    if (ctx->r14 == 0) {
        // 0x800CA400: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800CA428;
    }
    // 0x800CA400: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800CA404: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_800CA408:
    // 0x800CA408: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800CA40C: jal         0x800CA320
    // 0x800CA410: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800CA320(rdram, ctx);
        goto after_1;
    // 0x800CA410: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800CA414: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x800CA418: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800CA41C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800CA420: bne         $t9, $zero, L_800CA408
    if (ctx->r25 != 0) {
        // 0x800CA424: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_800CA408;
    }
    // 0x800CA424: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_800CA428:
    // 0x800CA428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA430: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CA434: jr          $ra
    // 0x800CA438: nop

    return;
    // 0x800CA438: nop

    // 0x800CA43C: jr          $ra
    // 0x800CA440: nop

    return;
    // 0x800CA440: nop

;}
RECOMP_FUNC void static_5_800D13E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
        goto after_0;
    // 0x800D1424: nop

    after_0:
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
        goto after_1;
    // 0x800D14F0: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_1:
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
        goto after_2;
    // 0x800D1548: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_2:
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
        goto after_3;
    // 0x800D162C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_3:
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
        goto after_4;
    // 0x800D1648: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_4:
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

;}
RECOMP_FUNC void static_5_800D167C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
    goto skip_0;
    // 0x800D1718: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    skip_0:
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
RECOMP_FUNC void static_5_800D63E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63E8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800D63EC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D63F0: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D63F4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D63F8: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x800D63FC: beq         $t7, $zero, L_800D642C
    if (ctx->r15 == 0) {
        // 0x800D6400: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D642C;
    }
    // 0x800D6400: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D6404: andi        $a1, $v0, 0x7F
    ctx->r5 = ctx->r2 & 0X7F;
L_800D6408:
    // 0x800D6408: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800D640C: sll         $t9, $a1, 7
    ctx->r25 = S32(ctx->r5 << 7);
    // 0x800D6410: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6414: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D6418: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800D641C: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x800D6420: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x800D6424: bne         $t7, $zero, L_800D6408
    if (ctx->r15 != 0) {
        // 0x800D6428: addu        $a1, $t9, $t6
        ctx->r5 = ADD32(ctx->r25, ctx->r14);
            goto L_800D6408;
    }
    // 0x800D6428: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
L_800D642C:
    // 0x800D642C: jr          $ra
    // 0x800D6430: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800D6430: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void static_5_800D68B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D68B8: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800D68BC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800D68C0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x800D68C4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800D68C8: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x800D68CC: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x800D68D0: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800D68D4: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800D68D8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800D68DC: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D68E0: jr          $ra
    // 0x800D68E4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x800D68E4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}
