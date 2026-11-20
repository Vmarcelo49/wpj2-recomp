#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void alSndpGetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C97D0: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800C97D4: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x800C97D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C97DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C97E0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C97E4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C97E8: jr          $ra
    // 0x800C97EC: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
    return;
    // 0x800C97EC: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
;}
RECOMP_FUNC void alSndpDeallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C97F0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800C97F4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C97F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C97FC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800C9800: sll         $v1, $t7, 2
    ctx->r3 = S32(ctx->r15 << 2);
    // 0x800C9804: subu        $v1, $v1, $t7
    ctx->r3 = SUB32(ctx->r3, ctx->r15);
    // 0x800C9808: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C980C: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9810: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x800C9814: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9818: bne         $t9, $zero, L_800C9838
    if (ctx->r25 != 0) {
        // 0x800C981C: nop

            goto L_800C9838;
    }
    // 0x800C981C: nop

    // 0x800C9820: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x800C9824: lw          $t1, 0x3C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X3C);
    // 0x800C9828: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800C982C: bne         $t7, $t1, L_800C9838
    if (ctx->r15 != ctx->r9) {
        // 0x800C9830: nop

            goto L_800C9838;
    }
    // 0x800C9830: nop

    // 0x800C9834: sw          $t2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r10;
L_800C9838:
    // 0x800C9838: jr          $ra
    // 0x800C983C: nop

    return;
    // 0x800C983C: nop

;}
RECOMP_FUNC void func_800C9840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9848: jal         0x800C41A0
    // 0x800C984C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C984C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C9850: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800C9854: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800C9858: beq         $s0, $zero, L_800C98A4
    if (ctx->r16 == 0) {
        // 0x800C985C: nop

            goto L_800C98A4;
    }
    // 0x800C985C: nop

L_800C9860:
    // 0x800C9860: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x800C9864: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800C9868: bne         $s3, $t6, L_800C989C
    if (ctx->r19 != ctx->r14) {
        // 0x800C986C: nop

            goto L_800C989C;
    }
    // 0x800C986C: nop

    // 0x800C9870: beq         $s1, $zero, L_800C9888
    if (ctx->r17 == 0) {
        // 0x800C9874: nop

            goto L_800C9888;
    }
    // 0x800C9874: nop

    // 0x800C9878: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800C987C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800C9880: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C9884: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
L_800C9888:
    // 0x800C9888: jal         0x800C7890
    // 0x800C988C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C988C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9894: jal         0x800C78C0
    // 0x800C9898: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C9898: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800C989C:
    // 0x800C989C: bne         $s1, $zero, L_800C9860
    if (ctx->r17 != 0) {
        // 0x800C98A0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C9860;
    }
    // 0x800C98A0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C98A4:
    // 0x800C98A4: jal         0x800C41A0
    // 0x800C98A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C98A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x800C98AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C98B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C98B4: jr          $ra
    // 0x800C98B8: nop

    return;
    // 0x800C98B8: nop

    // 0x800C98BC: jr          $ra
    // 0x800C98C0: nop

    return;
    // 0x800C98C0: nop

    // 0x800C98C4: jr          $ra
    // 0x800C98C8: nop

    return;
    // 0x800C98C8: nop

;}
RECOMP_FUNC void func_800C98CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C98CC: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800C98D0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C98D4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C98D8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C98DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C98E0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C98E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C98E8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800C98EC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C98F0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C98F4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C98F8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C98FC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C9900: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9904: ldc1        $f20, 0x1B0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X1B0);
    // 0x800C9908: addiu       $s4, $a0, 0x28
    ctx->r20 = ADD32(ctx->r4, 0X28);
    // 0x800C990C: addiu       $s7, $a0, 0x14
    ctx->r23 = ADD32(ctx->r4, 0X14);
    // 0x800C9910: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800C9914:
    // 0x800C9914: lh          $v0, 0x28($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X28);
    // 0x800C9918: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800C991C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800C9920: bne         $v0, $at, L_800C9940
    if (ctx->r2 != ctx->r1) {
        // 0x800C9924: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800C9940;
    }
    // 0x800C9924: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800C9928: sh          $t6, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r14;
    // 0x800C992C: lw          $a2, 0x48($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X48);
    // 0x800C9930: jal         0x800D3A2C
    // 0x800C9934: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C9934: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    after_0:
    // 0x800C9938: b           L_800C9DC4
    // 0x800C993C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800C9DC4;
    // 0x800C993C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9940:
    // 0x800C9940: lw          $s5, 0x2C($s6)
    ctx->r21 = MEM_W(ctx->r22, 0X2C);
    // 0x800C9944: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x800C9948: beq         $at, $zero, L_800C9DC0
    if (ctx->r1 == 0) {
        // 0x800C994C: lw          $s1, 0x1C($s5)
        ctx->r17 = MEM_W(ctx->r21, 0X1C);
            goto L_800C9DC0;
    }
    // 0x800C994C: lw          $s1, 0x1C($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X1C);
    // 0x800C9950: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800C9954: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9958: addu        $at, $at, $t7
    gpr jr_addend_800C9960 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C995C: lw          $t7, 0x1B8($at)
    ctx->r15 = ADD32(ctx->r1, 0X1B8);
    // 0x800C9960: jr          $t7
    // 0x800C9964: nop

    switch (jr_addend_800C9960 >> 2) {
        case 0: goto L_800C9968; break;
        case 1: goto L_800C9AD0; break;
        case 2: goto L_800C9B9C; break;
        case 3: goto L_800C9C80; break;
        case 4: goto L_800C9C04; break;
        case 5: goto L_800C9DC0; break;
        case 6: goto L_800C9CE4; break;
        case 7: goto L_800C9D90; break;
        case 8: goto L_800C9C58; break;
        default: switch_error(__func__, 0x800C9960, 0x800F01B8);
    }
    // 0x800C9964: nop

L_800C9968:
    // 0x800C9968: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    // 0x800C996C: bnel        $t8, $zero, L_800C9DC4
    if (ctx->r24 != 0) {
        // 0x800C9970: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800C9DC4;
    }
    goto skip_0;
    // 0x800C9970: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
    // 0x800C9974: beq         $s1, $zero, L_800C9DC0
    if (ctx->r17 == 0) {
        // 0x800C9978: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800C9DC0;
    }
    // 0x800C9978: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C997C: sh          $zero, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = 0;
    // 0x800C9980: lh          $t9, 0x20($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X20);
    // 0x800C9984: sb          $zero, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = 0;
    // 0x800C9988: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x800C998C: sh          $t9, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r25;
    // 0x800C9990: jal         0x800D3FE8
    // 0x800C9994: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    alSynAllocVoice(rdram, ctx);
        goto after_1;
    // 0x800C9994: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_1:
    // 0x800C9998: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C999C: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x800C99A0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800C99A4: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x800C99A8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800C99AC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C99B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800C99B4: nop

    // 0x800C99B8: nop

    // 0x800C99BC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800C99C0: mflo        $t9
    ctx->r25 = lo;
    // 0x800C99C4: sh          $t9, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r25;
    // 0x800C99C8: lbu         $t7, 0xC($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XC);
    // 0x800C99CC: lbu         $t6, 0x2E($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X2E);
    // 0x800C99D0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800C99D4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800C99D8: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x800C99DC: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800C99E0: bgtzl       $v1, L_800C99F0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C99E4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800C99F0;
    }
    goto skip_1;
    // 0x800C99E4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_1:
    // 0x800C99E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C99EC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800C99F0:
    // 0x800C99F0: beq         $at, $zero, L_800C9A00
    if (ctx->r1 == 0) {
        // 0x800C99F4: nop

            goto L_800C9A00;
    }
    // 0x800C99F4: nop

    // 0x800C99F8: b           L_800C9A00
    // 0x800C99FC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800C9A00;
    // 0x800C99FC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800C9A00:
    // 0x800C9A00: lwc1        $f4, 0x24($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800C9A04: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9A08: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x800C9A0C: lw          $s0, 0x0($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X0);
    // 0x800C9A10: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x800C9A14: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9A18: jal         0x800D4350
    // 0x800C9A1C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    alSynStartVoice(rdram, ctx);
        goto after_2;
    // 0x800C9A1C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C9A20: lbu         $a2, 0xD7($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD7);
    // 0x800C9A24: sw          $fp, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r30;
    // 0x800C9A28: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9A2C: jal         0x800D4220
    // 0x800C9A30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynSetPan(rdram, ctx);
        goto after_3;
    // 0x800C9A30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x800C9A34: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9A38: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9A3C: lh          $a2, 0xBA($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XBA);
    // 0x800C9A40: jal         0x800D3DD0
    // 0x800C9A44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_4;
    // 0x800C9A44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800C9A48: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9A4C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9A50: jal         0x800D3E70
    // 0x800C9A54: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    alSynSetPitch(rdram, ctx);
        goto after_5;
    // 0x800C9A54: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    after_5:
    // 0x800C9A58: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9A5C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9A60: jal         0x800D42B0
    // 0x800C9A64: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    alSynSetFXMix(rdram, ctx);
        goto after_6;
    // 0x800C9A64: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    after_6:
    // 0x800C9A68: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800C9A6C: sh          $t6, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r14;
    // 0x800C9A70: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800C9A74: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800C9A78: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800C9A7C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800C9A80: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800C9A84: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800C9A88: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800C9A8C: nop

    // 0x800C9A90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C9A94: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl);
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800C9A98: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800C9A9C: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800C9AA0: nop

    // 0x800C9AA4: bc1fl       L_800C9AB8
    if (!c1cs) {
        // 0x800C9AA8: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800C9AB8;
    }
    goto skip_2;
    // 0x800C9AA8: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_2:
    // 0x800C9AAC: b           L_800C9AC0
    // 0x800C9AB0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
        goto L_800C9AC0;
    // 0x800C9AB0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800C9AB4: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800C9AB8:
    // 0x800C9AB8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C9ABC: nop

L_800C9AC0:
    // 0x800C9AC0: jal         0x800D3A2C
    // 0x800C9AC4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800C9AC4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_7:
    // 0x800C9AC8: b           L_800C9DC4
    // 0x800C9ACC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800C9DC4;
    // 0x800C9ACC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9AD0:
    // 0x800C9AD0: lw          $t9, 0x28($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X28);
    // 0x800C9AD4: bnel        $fp, $t9, L_800C9DC4
    if (ctx->r30 != ctx->r25) {
        // 0x800C9AD8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800C9DC4;
    }
    goto skip_3;
    // 0x800C9AD8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_3:
    // 0x800C9ADC: beq         $s1, $zero, L_800C9DC0
    if (ctx->r17 == 0) {
        // 0x800C9AE0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800C9DC0;
    }
    // 0x800C9AE0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9AE4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800C9AE8: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800C9AEC: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800C9AF0: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x800C9AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C9AF8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800C9AFC: nop

    // 0x800C9B00: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C9B04: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl);
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800C9B08: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800C9B0C: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800C9B10: nop

    // 0x800C9B14: bc1fl       L_800C9B28
    if (!c1cs) {
        // 0x800C9B18: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800C9B28;
    }
    goto skip_4;
    // 0x800C9B18: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_4:
    // 0x800C9B1C: b           L_800C9B30
    // 0x800C9B20: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_800C9B30;
    // 0x800C9B20: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x800C9B24: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800C9B28:
    // 0x800C9B28: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800C9B2C: nop

L_800C9B30:
    // 0x800C9B30: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800C9B34: jal         0x800D3DD0
    // 0x800C9B38: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    alSynSetVol(rdram, ctx);
        goto after_8;
    // 0x800C9B38: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_8:
    // 0x800C9B3C: beq         $s0, $zero, L_800C9B6C
    if (ctx->r16 == 0) {
        // 0x800C9B40: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800C9B6C;
    }
    // 0x800C9B40: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9B44: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800C9B48: sh          $t8, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r24;
    // 0x800C9B4C: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800C9B50: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800C9B54: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800C9B58: jal         0x800D3A2C
    // 0x800C9B5C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_9;
    // 0x800C9B5C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x800C9B60: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800C9B64: b           L_800C9DC0
    // 0x800C9B68: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
        goto L_800C9DC0;
    // 0x800C9B68: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
L_800C9B6C:
    // 0x800C9B6C: jal         0x800D3CA0
    // 0x800C9B70: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    alSynStopVoice(rdram, ctx);
        goto after_10;
    // 0x800C9B70: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_10:
    // 0x800C9B74: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9B78: jal         0x800D3D20
    // 0x800C9B7C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_11;
    // 0x800C9B7C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x800C9B80: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800C9B84: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800C9B88: jal         0x800C9840
    // 0x800C9B8C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    func_800C9840(rdram, ctx);
        goto after_12;
    // 0x800C9B8C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_12:
    // 0x800C9B90: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9B94: b           L_800C9DC0
    // 0x800C9B98: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
        goto L_800C9DC0;
    // 0x800C9B98: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800C9B9C:
    // 0x800C9B9C: lw          $t7, 0x28($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X28);
    // 0x800C9BA0: lbu         $t6, 0x8($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X8);
    // 0x800C9BA4: bne         $fp, $t7, L_800C9DC0
    if (ctx->r30 != ctx->r15) {
        // 0x800C9BA8: sb          $t6, 0x2E($s5)
        MEM_B(0X2E, ctx->r21) = ctx->r14;
            goto L_800C9DC0;
    }
    // 0x800C9BA8: sb          $t6, 0x2E($s5)
    MEM_B(0X2E, ctx->r21) = ctx->r14;
    // 0x800C9BAC: beq         $s1, $zero, L_800C9DC0
    if (ctx->r17 == 0) {
        // 0x800C9BB0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800C9DC0;
    }
    // 0x800C9BB0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9BB4: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x800C9BB8: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800C9BBC: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800C9BC0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C9BC4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800C9BC8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800C9BCC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C9BD0: bgtzl       $v1, L_800C9BE0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C9BD4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800C9BE0;
    }
    goto skip_5;
    // 0x800C9BD4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_5:
    // 0x800C9BD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9BDC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800C9BE0:
    // 0x800C9BE0: beq         $at, $zero, L_800C9BF0
    if (ctx->r1 == 0) {
        // 0x800C9BE4: nop

            goto L_800C9BF0;
    }
    // 0x800C9BE4: nop

    // 0x800C9BE8: b           L_800C9BF0
    // 0x800C9BEC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800C9BF0;
    // 0x800C9BEC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800C9BF0:
    // 0x800C9BF0: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9BF4: jal         0x800D4220
    // 0x800C9BF8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_13;
    // 0x800C9BF8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_13:
    // 0x800C9BFC: b           L_800C9DC4
    // 0x800C9C00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800C9DC4;
    // 0x800C9C00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9C04:
    // 0x800C9C04: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800C9C08: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9C0C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9C10: swc1        $f0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f0.u32l;
    // 0x800C9C14: ldc1        $f8, 0x1E0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1E0);
    // 0x800C9C18: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800C9C1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9C20: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800C9C24: nop

    // 0x800C9C28: bc1fl       L_800C9C3C
    if (!c1cs) {
        // 0x800C9C2C: lw          $t8, 0x28($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X28);
            goto L_800C9C3C;
    }
    goto skip_6;
    // 0x800C9C2C: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    skip_6:
    // 0x800C9C30: lwc1        $f10, 0x1E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1E8);
    // 0x800C9C34: swc1        $f10, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f10.u32l;
    // 0x800C9C38: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
L_800C9C3C:
    // 0x800C9C3C: bnel        $fp, $t8, L_800C9DC4
    if (ctx->r30 != ctx->r24) {
        // 0x800C9C40: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800C9DC4;
    }
    goto skip_7;
    // 0x800C9C40: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_7:
    // 0x800C9C44: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9C48: jal         0x800D3E70
    // 0x800C9C4C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    alSynSetPitch(rdram, ctx);
        goto after_14;
    // 0x800C9C4C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    after_14:
    // 0x800C9C50: b           L_800C9DC4
    // 0x800C9C54: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800C9DC4;
    // 0x800C9C54: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9C58:
    // 0x800C9C58: lw          $t6, 0x28($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X28);
    // 0x800C9C5C: lbu         $t9, 0x8($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X8);
    // 0x800C9C60: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9C64: bne         $fp, $t6, L_800C9DC0
    if (ctx->r30 != ctx->r14) {
        // 0x800C9C68: sb          $t9, 0x2F($s5)
        MEM_B(0X2F, ctx->r21) = ctx->r25;
            goto L_800C9DC0;
    }
    // 0x800C9C68: sb          $t9, 0x2F($s5)
    MEM_B(0X2F, ctx->r21) = ctx->r25;
    // 0x800C9C6C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9C70: jal         0x800D42B0
    // 0x800C9C74: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_15;
    // 0x800C9C74: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    after_15:
    // 0x800C9C78: b           L_800C9DC4
    // 0x800C9C7C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800C9DC4;
    // 0x800C9C7C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9C80:
    // 0x800C9C80: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    // 0x800C9C84: lh          $t7, 0x8($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X8);
    // 0x800C9C88: bne         $fp, $t8, L_800C9DC0
    if (ctx->r30 != ctx->r24) {
        // 0x800C9C8C: sh          $t7, 0x2C($s5)
        MEM_H(0X2C, ctx->r21) = ctx->r15;
            goto L_800C9DC0;
    }
    // 0x800C9C8C: sh          $t7, 0x2C($s5)
    MEM_H(0X2C, ctx->r21) = ctx->r15;
    // 0x800C9C90: beql        $s1, $zero, L_800C9DC4
    if (ctx->r17 == 0) {
        // 0x800C9C94: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800C9DC4;
    }
    goto skip_8;
    // 0x800C9C94: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_8:
    // 0x800C9C98: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C9C9C: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x800C9CA0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800C9CA4: lbu         $t6, 0xD($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XD);
    // 0x800C9CA8: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9CAC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9CB0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9CB4: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x800C9CB8: mflo        $t0
    ctx->r8 = lo;
    // 0x800C9CBC: nop

    // 0x800C9CC0: nop

    // 0x800C9CC4: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800C9CC8: mflo        $t8
    ctx->r24 = lo;
    // 0x800C9CCC: sll         $a2, $t8, 16
    ctx->r6 = S32(ctx->r24 << 16);
    // 0x800C9CD0: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C9CD4: jal         0x800D3DD0
    // 0x800C9CD8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    alSynSetVol(rdram, ctx);
        goto after_16;
    // 0x800C9CD8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_16:
    // 0x800C9CDC: b           L_800C9DC4
    // 0x800C9CE0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800C9DC4;
    // 0x800C9CE0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9CE4:
    // 0x800C9CE4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C9CE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C9CEC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C9CF0: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800C9CF4: beql        $v1, $at, L_800C9DC4
    if (ctx->r3 == ctx->r1) {
        // 0x800C9CF8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800C9DC4;
    }
    goto skip_9;
    // 0x800C9CF8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_9:
    // 0x800C9CFC: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    // 0x800C9D00: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x800C9D04: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800C9D08: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800C9D0C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9D10: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800C9D14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C9D18: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800C9D1C: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl);
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800C9D20: mflo        $t0
    ctx->r8 = lo;
    // 0x800C9D24: nop

    // 0x800C9D28: nop

    // 0x800C9D2C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800C9D30: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800C9D34: mflo        $t0
    ctx->r8 = lo;
    // 0x800C9D38: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800C9D3C: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800C9D40: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C9D44: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800C9D48: bc1fl       L_800C9D5C
    if (!c1cs) {
        // 0x800C9D4C: trunc.w.d   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800C9D5C;
    }
    goto skip_10;
    // 0x800C9D4C: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    skip_10:
    // 0x800C9D50: b           L_800C9D64
    // 0x800C9D54: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_800C9D64;
    // 0x800C9D54: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x800C9D58: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
L_800C9D5C:
    // 0x800C9D5C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800C9D60: nop

L_800C9D64:
    // 0x800C9D64: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800C9D68: jal         0x800D3DD0
    // 0x800C9D6C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x800C9D6C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_17:
    // 0x800C9D70: sh          $fp, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r30;
    // 0x800C9D74: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800C9D78: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800C9D7C: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800C9D80: jal         0x800D3A2C
    // 0x800C9D84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x800C9D84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x800C9D88: b           L_800C9DC4
    // 0x800C9D8C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800C9DC4;
    // 0x800C9D8C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9D90:
    // 0x800C9D90: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9D94: jal         0x800D3CA0
    // 0x800C9D98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_19;
    // 0x800C9D98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_19:
    // 0x800C9D9C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800C9DA0: jal         0x800D3D20
    // 0x800C9DA4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_20;
    // 0x800C9DA4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
    // 0x800C9DA8: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800C9DAC: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800C9DB0: jal         0x800C9840
    // 0x800C9DB4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    func_800C9840(rdram, ctx);
        goto after_21;
    // 0x800C9DB4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_21:
    // 0x800C9DB8: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9DBC: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800C9DC0:
    // 0x800C9DC0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800C9DC4:
    // 0x800C9DC4: jal         0x800D3B50
    // 0x800C9DC8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_22;
    // 0x800C9DC8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_22:
    // 0x800C9DCC: beq         $v0, $zero, L_800C9914
    if (ctx->r2 == 0) {
        // 0x800C9DD0: sw          $v0, 0x4C($s6)
        MEM_W(0X4C, ctx->r22) = ctx->r2;
            goto L_800C9914;
    }
    // 0x800C9DD0: sw          $v0, 0x4C($s6)
    MEM_W(0X4C, ctx->r22) = ctx->r2;
    // 0x800C9DD4: lw          $t7, 0x50($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X50);
    // 0x800C9DD8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C9DDC: sw          $t8, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->r24;
    // 0x800C9DE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C9DE4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C9DE8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C9DEC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C9DF0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C9DF4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C9DF8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9DFC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C9E00: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C9E04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9E08: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C9E0C: jr          $ra
    // 0x800C9E10: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800C9E10: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void alSndpNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E14: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C9E18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9E1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9E20: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C9E24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C9E28: addiu       $t8, $zero, 0x3E80
    ctx->r24 = ADD32(0, 0X3E80);
    // 0x800C9E2C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800C9E30: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    // 0x800C9E34: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800C9E38: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800C9E3C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800C9E40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C9E44: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800C9E48: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800C9E4C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x800C9E50: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C9E54: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C9E58: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800C9E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9E64: jal         0x800C7950
    // 0x800C9E68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800C9E68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800C9E6C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9E70: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x800C9E74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9E78: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800C9E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9E84: beq         $t2, $zero, L_800C9EA8
    if (ctx->r10 == 0) {
        // 0x800C9E88: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800C9EA8;
    }
    // 0x800C9E88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C9E8C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
L_800C9E90:
    // 0x800C9E90: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800C9E94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C9E98: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800C9E9C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800C9EA0: bnel        $at, $zero, L_800C9E90
    if (ctx->r1 != 0) {
        // 0x800C9EA4: sw          $zero, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = 0;
            goto L_800C9E90;
    }
    goto skip_0;
    // 0x800C9EA4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    skip_0:
L_800C9EA8:
    // 0x800C9EA8: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x800C9EAC: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800C9EB0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800C9EB4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C9EB8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C9EBC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C9EC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C9EC4: jal         0x800C7950
    // 0x800C9EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800C9EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800C9ECC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9ED0: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800C9ED4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C9ED8: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x800C9EDC: jal         0x800D3BDC
    // 0x800C9EE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    alEvtqNew(rdram, ctx);
        goto after_2;
    // 0x800C9EE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x800C9EE4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9EE8: lw          $a0, -0x33E0($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X33E0);
    // 0x800C9EEC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800C9EF0: addiu       $t7, $t7, -0x6734
    ctx->r15 = ADD32(ctx->r15, -0X6734);
    // 0x800C9EF4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800C9EF8: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x800C9EFC: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800C9F00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C9F04: jal         0x800D3C50
    // 0x800C9F08: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    alSynAddPlayer(rdram, ctx);
        goto after_3;
    // 0x800C9F08: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    after_3:
    // 0x800C9F0C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800C9F10: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x800C9F14: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x800C9F18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9F1C: jal         0x800D3A2C
    // 0x800C9F20: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x800C9F20: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x800C9F24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9F28: jal         0x800D3B50
    // 0x800C9F2C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    alEvtqNextEvent(rdram, ctx);
        goto after_5;
    // 0x800C9F2C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x800C9F30: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x800C9F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9F38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9F3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C9F40: jr          $ra
    // 0x800C9F44: nop

    return;
    // 0x800C9F44: nop

;}
RECOMP_FUNC void func_800C9F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F48: nop

    // 0x800C9F4C: nop

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
RECOMP_FUNC void func_800C9FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9FEC: nop

;}
RECOMP_FUNC void alSndpSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9FF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9FF8: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800C9FFC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800CA000: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800CA004: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA008: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA00C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA010: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CA014: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CA018: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800CA01C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CA020: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800CA024: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA02C: jal         0x800D3A2C
    // 0x800CA030: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA030: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800CA034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA038: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA03C: jr          $ra
    // 0x800CA040: nop

    return;
    // 0x800CA040: nop

;}
RECOMP_FUNC void func_800CA044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA044: nop

    // 0x800CA048: nop

    // 0x800CA04C: nop

;}
RECOMP_FUNC void alSndpSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA050: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA058: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CA05C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800CA060: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800CA064: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800CA068: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA06C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800CA070: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x800CA074: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CA078: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CA07C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800CA080: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CA084: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800CA088: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA08C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA090: jal         0x800D3A2C
    // 0x800CA094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CA098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA09C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA0A0: jr          $ra
    // 0x800CA0A4: nop

    return;
    // 0x800CA0A4: nop

;}
RECOMP_FUNC void func_800CA0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA0A8: nop

    // 0x800CA0AC: nop

;}
RECOMP_FUNC void alSndpSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA0B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA0B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CA0BC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800CA0C0: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800CA0C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800CA0C8: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800CA0CC: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x800CA0D0: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA0D4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA0D8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA0DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CA0E0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CA0E4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800CA0E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CA0EC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800CA0F0: jal         0x800D3A2C
    // 0x800CA0F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA0F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CA0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA0FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA100: jr          $ra
    // 0x800CA104: nop

    return;
    // 0x800CA104: nop

;}
RECOMP_FUNC void func_800CA108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA108: nop

    // 0x800CA10C: nop

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
RECOMP_FUNC void func_800CA168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA168: nop

    // 0x800CA16C: nop

;}
RECOMP_FUNC void alSndpPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA178: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA17C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x800CA180: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800CA184: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA188: mflo        $t7
    ctx->r15 = lo;
    // 0x800CA18C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800CA190: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x800CA194: bnel        $t9, $zero, L_800CA1C8
    if (ctx->r25 != 0) {
        // 0x800CA198: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CA1C8;
    }
    goto skip_0;
    // 0x800CA198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CA19C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800CA1A0: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA1A4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA1A8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA1AC: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA1B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA1B4: mflo        $t1
    ctx->r9 = lo;
    // 0x800CA1B8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800CA1BC: jal         0x800D3A2C
    // 0x800CA1C0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA1C0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_0:
    // 0x800CA1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CA1C8:
    // 0x800CA1C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA1CC: jr          $ra
    // 0x800CA1D0: nop

    return;
    // 0x800CA1D0: nop

;}
RECOMP_FUNC void func_800CA1D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA1D4: nop

    // 0x800CA1D8: nop

    // 0x800CA1DC: nop

;}
RECOMP_FUNC void alCSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA1E0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800CA1E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CA1E8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800CA1EC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800CA1F0: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800CA1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA1F8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CA1FC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800CA200: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x800CA204: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800CA208: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CA20C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_800CA210:
    // 0x800CA210: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    // 0x800CA214: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800CA218: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800CA21C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CA220: lw          $t1, 0x58($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X58);
    // 0x800CA224: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800CA228: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800CA22C: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x800CA230: lbu         $t2, 0x98($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X98);
    // 0x800CA234: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800CA238: sb          $t2, 0x8A($a3)
    MEM_B(0X8A, ctx->r7) = ctx->r10;
    // 0x800CA23C: lbu         $t3, 0xA6($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA6);
    // 0x800CA240: sb          $t3, 0x9A($a3)
    MEM_B(0X9A, ctx->r7) = ctx->r11;
    // 0x800CA244: lw          $t4, 0xB0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XB0);
    // 0x800CA248: sw          $t4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r12;
    // 0x800CA24C: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800CA250: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x800CA254: lw          $t6, 0x54($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X54);
    // 0x800CA258: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x800CA25C: lbu         $t7, 0x97($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X97);
    // 0x800CA260: sb          $t7, 0x8B($a3)
    MEM_B(0X8B, ctx->r7) = ctx->r15;
    // 0x800CA264: lbu         $t8, 0xA7($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA7);
    // 0x800CA268: sb          $t8, 0x9B($a3)
    MEM_B(0X9B, ctx->r7) = ctx->r24;
    // 0x800CA26C: lw          $t9, 0xB4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XB4);
    // 0x800CA270: bne         $v0, $a0, L_800CA210
    if (ctx->r2 != ctx->r4) {
        // 0x800CA274: sw          $t9, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r25;
            goto L_800CA210;
    }
    // 0x800CA274: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
    // 0x800CA278: jr          $ra
    // 0x800CA27C: nop

    return;
    // 0x800CA27C: nop

;}
RECOMP_FUNC void alCSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA280: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800CA284: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CA288: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA28C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CA290: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800CA294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA298: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CA29C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800CA2A0: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800CA2A4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800CA2A8: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800CA2AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_800CA2B0:
    // 0x800CA2B0: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800CA2B4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800CA2B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800CA2BC: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800CA2C0: lw          $t1, 0x4C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4C);
    // 0x800CA2C4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800CA2C8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800CA2CC: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x800CA2D0: lbu         $t2, 0x8C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8C);
    // 0x800CA2D4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800CA2D8: sb          $t2, 0x96($a3)
    MEM_B(0X96, ctx->r7) = ctx->r10;
    // 0x800CA2DC: lbu         $t3, 0x9A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9A);
    // 0x800CA2E0: sb          $t3, 0xA6($a3)
    MEM_B(0XA6, ctx->r7) = ctx->r11;
    // 0x800CA2E4: lw          $t4, 0xA4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA4);
    // 0x800CA2E8: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x800CA2EC: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800CA2F0: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x800CA2F4: lw          $t6, 0x48($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X48);
    // 0x800CA2F8: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
    // 0x800CA2FC: lbu         $t7, 0x8B($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8B);
    // 0x800CA300: sb          $t7, 0x97($a3)
    MEM_B(0X97, ctx->r7) = ctx->r15;
    // 0x800CA304: lbu         $t8, 0x9B($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9B);
    // 0x800CA308: sb          $t8, 0xA7($a3)
    MEM_B(0XA7, ctx->r7) = ctx->r24;
    // 0x800CA30C: lw          $t9, 0xA8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA8);
    // 0x800CA310: bne         $v0, $a0, L_800CA2B0
    if (ctx->r2 != ctx->r4) {
        // 0x800CA314: sw          $t9, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->r25;
            goto L_800CA2B0;
    }
    // 0x800CA314: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x800CA318: jr          $ra
    // 0x800CA31C: nop

    return;
    // 0x800CA31C: nop

;}
RECOMP_FUNC void func_800CA320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA320: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800CA324: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800CA328: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800CA32C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800CA330: beql        $t6, $zero, L_800CA368
    if (ctx->r14 == 0) {
        // 0x800CA334: lw          $a3, 0x18($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X18);
            goto L_800CA368;
    }
    goto skip_0;
    // 0x800CA334: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x800CA338: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800CA33C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800CA340: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800CA344: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800CA348: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800CA34C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800CA350: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x800CA354: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800CA358: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x800CA35C: jr          $ra
    // 0x800CA360: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800CA360: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CA364: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
L_800CA368:
    // 0x800CA368: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800CA36C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800CA370: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800CA374: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x800CA378: bne         $t0, $v1, L_800CA3DC
    if (ctx->r8 != ctx->r3) {
        // 0x800CA37C: nop

            goto L_800CA3DC;
    }
    // 0x800CA37C: nop

    // 0x800CA380: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x800CA384: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800CA388: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x800CA38C: beq         $t0, $a0, L_800CA3DC
    if (ctx->r8 == ctx->r4) {
        // 0x800CA390: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_800CA3DC;
    }
    // 0x800CA390: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800CA394: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800CA398: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800CA39C: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800CA3A0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CA3A4: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x800CA3A8: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x800CA3AC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800CA3B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800CA3B4: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x800CA3B8: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x800CA3BC: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x800CA3C0: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800CA3C4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800CA3C8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800CA3CC: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800CA3D0: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800CA3D4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800CA3D8: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_800CA3DC:
    // 0x800CA3DC: jr          $ra
    // 0x800CA3E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800CA3E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
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
    func_800CA320(rdram, ctx);
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
    func_800CA320(rdram, ctx);
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
    func_800CA320(rdram, ctx);
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
    func_800CA320(rdram, ctx);
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
    func_800CA320(rdram, ctx);
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
    func_800CA320(rdram, ctx);
        goto after_5;
    // 0x800CA594: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x800CA598: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800CA59C: jal         0x800CA320
    // 0x800CA5A0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800CA320(rdram, ctx);
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
    func_800CA320(rdram, ctx);
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
    func_800CA320(rdram, ctx);
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
    static_1_800CA3E4(rdram, ctx);
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
    static_1_800CA3E4(rdram, ctx);
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
RECOMP_FUNC void alCSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA73C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA740: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800CA744: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CA748: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CA74C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CA750: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CA754: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CA758: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CA75C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CA760: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800CA764: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800CA768: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CA76C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800CA770: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800CA774: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800CA778: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CA77C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CA780: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x800CA784: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800CA788: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_800CA78C:
    // 0x800CA78C: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x800CA790: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x800CA794: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x800CA798: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800CA79C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CA7A0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800CA7A4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800CA7A8: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800CA7AC: beq         $v0, $zero, L_800CA7D8
    if (ctx->r2 == 0) {
        // 0x800CA7B0: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_800CA7D8;
    }
    // 0x800CA7B0: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x800CA7B4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800CA7B8: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800CA7BC: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800CA7C0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800CA7C4: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800CA7C8: jal         0x800CA3E4
    // 0x800CA7CC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    static_1_800CA3E4(rdram, ctx);
        goto after_0;
    // 0x800CA7CC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x800CA7D0: b           L_800CA7DC
    // 0x800CA7D4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_800CA7DC;
    // 0x800CA7D4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_800CA7D8:
    // 0x800CA7D8: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_800CA7DC:
    // 0x800CA7DC: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800CA7E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CA7E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800CA7E8: bne         $t5, $s3, L_800CA78C
    if (ctx->r13 != ctx->r19) {
        // 0x800CA7EC: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_800CA78C;
    }
    // 0x800CA7EC: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800CA7F0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800CA7F4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CA7F8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800CA7FC: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x800CA800: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CA804: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CA808: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800CA80C: bgez        $t7, L_800CA820
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CA810: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800CA820;
    }
    // 0x800CA810: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CA814: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800CA818: nop

    // 0x800CA81C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800CA820:
    // 0x800CA820: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800CA824: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800CA828: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800CA82C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800CA830: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA834: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800CA838: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800CA83C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CA840: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CA848: jr          $ra
    // 0x800CA84C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CA84C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alCSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA850: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800CA854: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CA858: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CA85C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800CA860: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x800CA864: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CA868: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CA86C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800CA870: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CA874: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CA878: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA87C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800CA880: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800CA884: jal         0x800CA73C
    // 0x800CA888: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    alCSeqNew(rdram, ctx);
        goto after_0;
    // 0x800CA888: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800CA88C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800CA890: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x800CA894: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800CA898: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_800CA89C:
    // 0x800CA89C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800CA8A0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CA8A4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800CA8A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800CA8AC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800CA8B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CA8B4: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800CA8B8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8BC: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_800CA8C0:
    // 0x800CA8C0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x800CA8C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CA8C8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CA8CC: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x800CA8D0: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x800CA8D4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800CA8D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CA8DC: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800CA8E0: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x800CA8E4: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x800CA8E8: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x800CA8EC: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x800CA8F0: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x800CA8F4: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x800CA8F8: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800CA8FC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800CA900: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x800CA904: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x800CA908: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x800CA90C: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x800CA910: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x800CA914: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x800CA918: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x800CA91C: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x800CA920: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x800CA924: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CA928: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x800CA92C: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x800CA930: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x800CA934: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x800CA938: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x800CA93C: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x800CA940: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x800CA944: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x800CA948: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x800CA94C: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800CA950: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x800CA954: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x800CA958: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x800CA95C: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x800CA960: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x800CA964: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x800CA968: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x800CA96C: bne         $a0, $s0, L_800CA8C0
    if (ctx->r4 != ctx->r16) {
        // 0x800CA970: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_800CA8C0;
    }
    // 0x800CA970: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x800CA974: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CA978: jal         0x800CA444
    // 0x800CA97C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alCSeqNextEvent(rdram, ctx);
        goto after_1;
    // 0x800CA97C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800CA980: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x800CA984: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800CA988: beq         $t0, $s5, L_800CA998
    if (ctx->r8 == ctx->r21) {
        // 0x800CA98C: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_800CA998;
    }
    // 0x800CA98C: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x800CA990: bnel        $at, $zero, L_800CA89C
    if (ctx->r1 != 0) {
        // 0x800CA994: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_800CA89C;
    }
    goto skip_0;
    // 0x800CA994: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_800CA998:
    // 0x800CA998: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA99C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CA9A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CA9A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA9A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CA9AC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800CA9B0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800CA9B4: jr          $ra
    // 0x800CA9B8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x800CA9B8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void alCSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA9BC: jr          $ra
    // 0x800CA9C0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800CA9C0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void alCSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA9C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800CA9C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA9CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CA9D0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800CA9D4: ldc1        $f6, 0x1F0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1F0);
    // 0x800CA9D8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800CA9DC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CA9E0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800CA9E4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800CA9E8: bgez        $t7, L_800CAA00
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CA9EC: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_800CAA00;
    }
    // 0x800CA9EC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800CA9F0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CA9F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CA9F8: nop

    // 0x800CA9FC: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_800CAA00:
    // 0x800CAA00: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800CAA04: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800CAA08: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800CAA0C: bgez        $a2, L_800CAA24
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800CAA10: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_800CAA24;
    }
    // 0x800CAA10: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800CAA14: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CAA18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CAA1C: nop

    // 0x800CAA20: add.d       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = ctx->f10.d + ctx->f18.d;
L_800CAA24:
    // 0x800CAA24: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800CAA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAA2C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800CAA30: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CAA34: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800CAA38: nop

    // 0x800CAA3C: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800CAA40: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800CAA44: nop

    // 0x800CAA48: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800CAA4C: beql        $v0, $zero, L_800CAAA8
    if (ctx->r2 == 0) {
        // 0x800CAA50: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800CAAA8;
    }
    goto skip_0;
    // 0x800CAA50: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800CAA54: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CAA58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CAA5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAA60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CAA64: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800CAA68: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800CAA6C: nop

    // 0x800CAA70: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800CAA74: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800CAA78: nop

    // 0x800CAA7C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800CAA80: bnel        $v0, $zero, L_800CAA9C
    if (ctx->r2 != 0) {
        // 0x800CAA84: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800CAA9C;
    }
    goto skip_1;
    // 0x800CAA84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_1:
    // 0x800CAA88: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800CAA8C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CAA90: jr          $ra
    // 0x800CAA94: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800CAA94: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800CAA98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
L_800CAA9C:
    // 0x800CAA9C: jr          $ra
    // 0x800CAAA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800CAAA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800CAAA4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800CAAA8:
    // 0x800CAAA8: nop

    // 0x800CAAAC: bltzl       $v0, L_800CAA9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CAAB0: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800CAA9C;
    }
    goto skip_2;
    // 0x800CAAB0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_2:
    // 0x800CAAB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CAAB8: jr          $ra
    // 0x800CAABC: nop

    return;
    // 0x800CAABC: nop

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
RECOMP_FUNC void __alCSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAB2C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800CAB30: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800CAB34: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CAB38: bne         $t6, $zero, L_800CAB48
    if (ctx->r14 != 0) {
        // 0x800CAB3C: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_800CAB48;
    }
    // 0x800CAB3C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800CAB40: jr          $ra
    // 0x800CAB44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CAB44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CAB48:
    // 0x800CAB48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CAB4C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800CAB50: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_800CAB54:
    // 0x800CAB54: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800CAB58: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x800CAB5C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CAB60: beql        $t8, $zero, L_800CABA4
    if (ctx->r24 == 0) {
        // 0x800CAB64: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CABA4;
    }
    goto skip_0;
    // 0x800CAB64: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x800CAB68: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CAB6C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CAB70: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CAB74: beql        $t3, $zero, L_800CAB90
    if (ctx->r11 == 0) {
        // 0x800CAB78: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_800CAB90;
    }
    goto skip_1;
    // 0x800CAB78: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x800CAB7C: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x800CAB80: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CAB84: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x800CAB88: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800CAB8C: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_800CAB90:
    // 0x800CAB90: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800CAB94: beql        $at, $zero, L_800CABA4
    if (ctx->r1 == 0) {
        // 0x800CAB98: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CABA4;
    }
    goto skip_2;
    // 0x800CAB98: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x800CAB9C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800CABA0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800CABA4:
    // 0x800CABA4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CABA8: beq         $t8, $zero, L_800CABE8
    if (ctx->r24 == 0) {
        // 0x800CABAC: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_800CABE8;
    }
    // 0x800CABAC: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x800CABB0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CABB4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CABB8: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CABBC: beql        $t3, $zero, L_800CABD8
    if (ctx->r11 == 0) {
        // 0x800CABC0: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_800CABD8;
    }
    goto skip_3;
    // 0x800CABC0: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x800CABC4: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x800CABC8: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CABCC: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x800CABD0: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800CABD4: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_800CABD8:
    // 0x800CABD8: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800CABDC: beql        $at, $zero, L_800CABEC
    if (ctx->r1 == 0) {
        // 0x800CABE0: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CABEC;
    }
    goto skip_4;
    // 0x800CABE0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x800CABE4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800CABE8:
    // 0x800CABE8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800CABEC:
    // 0x800CABEC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CABF0: beq         $t8, $zero, L_800CAC30
    if (ctx->r24 == 0) {
        // 0x800CABF4: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_800CAC30;
    }
    // 0x800CABF4: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x800CABF8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CABFC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CAC00: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CAC04: beql        $t3, $zero, L_800CAC20
    if (ctx->r11 == 0) {
        // 0x800CAC08: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_800CAC20;
    }
    goto skip_5;
    // 0x800CAC08: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x800CAC0C: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x800CAC10: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CAC14: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x800CAC18: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800CAC1C: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_800CAC20:
    // 0x800CAC20: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800CAC24: beql        $at, $zero, L_800CAC34
    if (ctx->r1 == 0) {
        // 0x800CAC28: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CAC34;
    }
    goto skip_6;
    // 0x800CAC28: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x800CAC2C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800CAC30:
    // 0x800CAC30: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800CAC34:
    // 0x800CAC34: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CAC38: beql        $t8, $zero, L_800CAC78
    if (ctx->r24 == 0) {
        // 0x800CAC3C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800CAC78;
    }
    goto skip_7;
    // 0x800CAC3C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x800CAC40: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CAC44: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CAC48: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CAC4C: beql        $t3, $zero, L_800CAC64
    if (ctx->r11 == 0) {
        // 0x800CAC50: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_800CAC64;
    }
    goto skip_8;
    // 0x800CAC50: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x800CAC54: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x800CAC58: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CAC5C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x800CAC60: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_800CAC64:
    // 0x800CAC64: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800CAC68: beql        $at, $zero, L_800CAC78
    if (ctx->r1 == 0) {
        // 0x800CAC6C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800CAC78;
    }
    goto skip_9;
    // 0x800CAC6C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x800CAC70: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CAC74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800CAC78:
    // 0x800CAC78: bnel        $a2, $t2, L_800CAB54
    if (ctx->r6 != ctx->r10) {
        // 0x800CAC7C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_800CAB54;
    }
    goto skip_10;
    // 0x800CAC7C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x800CAC80: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CAC84: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x800CAC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAC8C: jr          $ra
    // 0x800CAC90: nop

    return;
    // 0x800CAC90: nop

;}
RECOMP_FUNC void func_800CAC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAC94: nop

    // 0x800CAC98: nop

    // 0x800CAC9C: nop

;}
RECOMP_FUNC void alSeqpSetSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CACA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CACA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CACA8: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800CACAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CACB0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800CACB4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CACB8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CACBC: jal         0x800D3A2C
    // 0x800CACC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CACC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CACC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CACC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CACCC: jr          $ra
    // 0x800CACD0: nop

    return;
    // 0x800CACD0: nop

;}
RECOMP_FUNC void func_800CACD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CACD4: nop

    // 0x800CACD8: nop

    // 0x800CACDC: nop

;}
RECOMP_FUNC void alSeqpSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CACE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CACE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CACE8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800CACEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CACF0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800CACF4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CACF8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CACFC: jal         0x800D3A2C
    // 0x800CAD00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CAD00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CAD04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAD08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CAD0C: jr          $ra
    // 0x800CAD10: nop

    return;
    // 0x800CAD10: nop

;}
RECOMP_FUNC void func_800CAD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD14: nop

    // 0x800CAD18: nop

    // 0x800CAD1C: nop

;}
RECOMP_FUNC void alSeqpPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CAD24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAD28: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800CAD2C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800CAD30: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CAD34: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CAD38: jal         0x800D3A2C
    // 0x800CAD3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CAD3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CAD40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAD44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CAD48: jr          $ra
    // 0x800CAD4C: nop

    return;
    // 0x800CAD4C: nop

;}
RECOMP_FUNC void alSeqpSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CAD54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAD58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CAD5C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800CAD60: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800CAD64: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800CAD68: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800CAD6C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CAD70: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CAD74: jal         0x800D3A2C
    // 0x800CAD78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CAD78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CAD7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAD80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CAD84: jr          $ra
    // 0x800CAD88: nop

    return;
    // 0x800CAD88: nop

;}
RECOMP_FUNC void func_800CAD8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD8C: nop

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
RECOMP_FUNC void alCents2Ratio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CADC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CADC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800CADC8: bltz        $a0, L_800CADDC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800CADCC: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800CADDC;
    }
    // 0x800CADCC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CADD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CADD4: b           L_800CADE4
    // 0x800CADD8: lwc1        $f0, 0x200($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X200);
        goto L_800CADE4;
    // 0x800CADD8: lwc1        $f0, 0x200($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X200);
L_800CADDC:
    // 0x800CADDC: lwc1        $f0, 0x204($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X204);
    // 0x800CADE0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800CADE4:
    // 0x800CADE4: beq         $a0, $zero, L_800CAE08
    if (ctx->r4 == 0) {
        // 0x800CADE8: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_800CAE08;
    }
L_800CADE8:
    // 0x800CADE8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800CADEC: beq         $t6, $zero, L_800CADFC
    if (ctx->r14 == 0) {
        // 0x800CADF0: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800CADFC;
    }
    // 0x800CADF0: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800CADF4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl);
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800CADF8: nop

L_800CADFC:
    // 0x800CADFC: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl);
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800CAE00: bne         $t7, $zero, L_800CADE8
    if (ctx->r15 != 0) {
        // 0x800CAE04: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800CADE8;
    }
    // 0x800CAE04: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800CAE08:
    // 0x800CAE08: jr          $ra
    // 0x800CAE0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800CAE0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAE10: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800CAE14: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800CAE18: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800CAE1C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800CAE20: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800CAE24: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800CAE28: beq         $at, $zero, L_800CAE90
    if (ctx->r1 == 0) {
        // 0x800CAE2C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800CAE90;
    }
    // 0x800CAE2C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800CAE30: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800CAE34: bne         $at, $zero, L_800CAE88
    if (ctx->r1 != 0) {
        // 0x800CAE38: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800CAE88;
    }
    // 0x800CAE38: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800CAE3C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d);
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800CAE40: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800CAE44: addiu       $v1, $v1, 0x210
    ctx->r3 = ADD32(ctx->r3, 0X210);
    // 0x800CAE48: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800CAE4C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800CAE50: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800CAE54: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800CAE58: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800CAE5C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800CAE60: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800CAE64: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800CAE68: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800CAE6C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800CAE70: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d);
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800CAE74: nop

    // 0x800CAE78: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800CAE7C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d);
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800CAE80: jr          $ra
    // 0x800CAE84: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800CAE84: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800CAE88:
    // 0x800CAE88: jr          $ra
    // 0x800CAE8C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800CAE8C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800CAE90:
    // 0x800CAE90: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800CAE94: beq         $at, $zero, L_800CAFA8
    if (ctx->r1 == 0) {
        // 0x800CAE98: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800CAFA8;
    }
    // 0x800CAE98: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800CAE9C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800CAEA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAEA4: ldc1        $f10, 0x238($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X238);
    // 0x800CAEA8: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800CAEAC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800CAEB0: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d);
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800CAEB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CAEB8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CAEBC: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800CAEC0: nop

    // 0x800CAEC4: bc1fl       L_800CAEF4
    if (!c1cs) {
        // 0x800CAEC8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800CAEF4;
    }
    goto skip_0;
    // 0x800CAEC8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800CAECC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CAED0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CAED4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CAED8: nop

    // 0x800CAEDC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800CAEE0: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800CAEE4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800CAEE8: b           L_800CAF10
    // 0x800CAEEC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800CAF10;
    // 0x800CAEEC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800CAEF0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800CAEF4:
    // 0x800CAEF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CAEF8: nop

    // 0x800CAEFC: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800CAF00: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800CAF04: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800CAF08: nop

    // 0x800CAF0C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800CAF10:
    // 0x800CAF10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAF14: ldc1        $f18, 0x240($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X240);
    // 0x800CAF18: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800CAF1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAF20: ldc1        $f6, 0x248($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X248);
    // 0x800CAF24: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800CAF28: addiu       $v1, $v1, 0x210
    ctx->r3 = ADD32(ctx->r3, 0X210);
    // 0x800CAF2C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800CAF30: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800CAF34: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800CAF38: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800CAF3C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800CAF40: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d);
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800CAF44: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d);
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800CAF48: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800CAF4C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d);
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800CAF50: nop

    // 0x800CAF54: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800CAF58: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800CAF5C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800CAF60: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800CAF64: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800CAF68: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800CAF6C: bne         $t9, $zero, L_800CAF8C
    if (ctx->r25 != 0) {
        // 0x800CAF70: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800CAF8C;
    }
    // 0x800CAF70: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800CAF74: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d);
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800CAF78: nop

    // 0x800CAF7C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800CAF80: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d);
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800CAF84: jr          $ra
    // 0x800CAF88: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800CAF88: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800CAF8C:
    // 0x800CAF8C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d);
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800CAF90: nop

    // 0x800CAF94: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800CAF98: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d);
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800CAF9C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800CAFA0: jr          $ra
    // 0x800CAFA4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800CAFA4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f0.fl = -ctx->f0.fl;
L_800CAFA8:
    // 0x800CAFA8: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800CAFAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAFB0: bc1t        L_800CAFC4
    if (c1cs) {
        // 0x800CAFB4: nop

            goto L_800CAFC4;
    }
    // 0x800CAFB4: nop

    // 0x800CAFB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAFBC: jr          $ra
    // 0x800CAFC0: lwc1        $f0, 0x5B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B0);
    return;
    // 0x800CAFC0: lwc1        $f0, 0x5B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B0);
L_800CAFC4:
    // 0x800CAFC4: lwc1        $f0, 0x250($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X250);
    // 0x800CAFC8: jr          $ra
    // 0x800CAFCC: nop

    return;
    // 0x800CAFCC: nop

;}
RECOMP_FUNC void func_800CB07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB07C: nop

;}
RECOMP_FUNC void func_800CB08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB08C: nop

;}
RECOMP_FUNC void func_800CB598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB598: nop

    // 0x800CB59C: nop

;}
RECOMP_FUNC void func_800CB838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB838: nop

    // 0x800CB83C: nop

;}
RECOMP_FUNC void func_800CB938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB938: nop

    // 0x800CB93C: nop

;}
RECOMP_FUNC void func_800CBA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBA18: nop

    // 0x800CBA1C: nop

;}
RECOMP_FUNC void func_800CBA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBA5C: nop

;}
RECOMP_FUNC void func_800CBBAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBBAC: nop

;}
RECOMP_FUNC void func_800CBBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBBBC: nop

;}
RECOMP_FUNC void func_800CC00C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC00C: nop

;}
RECOMP_FUNC void func_800CC36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC36C: nop

;}
