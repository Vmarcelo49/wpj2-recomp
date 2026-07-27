#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void alAudioFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C38: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C7C3C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800C7C40: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800C7C44: lw          $s1, -0x33E0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X33E0);
    // 0x800C7C48: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C7C4C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800C7C50: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800C7C54: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800C7C58: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800C7C5C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800C7C60: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800C7C64: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800C7C68: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800C7C6C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C7C70: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800C7C74: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800C7C78: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
    // 0x800C7C7C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800C7C80: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800C7C84: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800C7C88: bne         $t7, $zero, L_800C7C9C
    if (ctx->r15 != 0) {
        // 0x800C7C8C: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_800C7C9C;
    }
    // 0x800C7C8C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800C7C90: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C7C94: b           L_800C7E9C
    // 0x800C7C98: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800C7E9C;
    // 0x800C7C98: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800C7C9C:
    // 0x800C7C9C: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800C7CA0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C7CA4: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x800C7CA8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x800C7CAC: beq         $v0, $zero, L_800C7CE8
    if (ctx->r2 == 0) {
        // 0x800C7CB0: addiu       $s2, $zero, -0x10
        ctx->r18 = ADD32(0, -0X10);
            goto L_800C7CE8;
    }
    // 0x800C7CB0: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800C7CB4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7CB8: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
L_800C7CBC:
    // 0x800C7CBC: subu        $t0, $t9, $a0
    ctx->r8 = SUB32(ctx->r25, ctx->r4);
    // 0x800C7CC0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C7CC4: beql        $at, $zero, L_800C7CE0
    if (ctx->r1 == 0) {
        // 0x800C7CC8: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800C7CE0;
    }
    goto skip_0;
    // 0x800C7CC8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800C7CCC: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800C7CD0: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x800C7CD4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7CD8: subu        $v1, $t1, $a0
    ctx->r3 = SUB32(ctx->r9, ctx->r4);
    // 0x800C7CDC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800C7CE0:
    // 0x800C7CE0: bnel        $v0, $zero, L_800C7CBC
    if (ctx->r2 != 0) {
        // 0x800C7CE4: lw          $t9, 0x10($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X10);
            goto L_800C7CBC;
    }
    goto skip_1;
    // 0x800C7CE4: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    skip_1:
L_800C7CE8:
    // 0x800C7CE8: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800C7CEC: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7CF0: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x800C7CF4: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x800C7CF8: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C7CFC: beq         $at, $zero, L_800C7DE0
    if (ctx->r1 == 0) {
        // 0x800C7D00: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800C7DE0;
    }
    // 0x800C7D00: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800C7D04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C7D08: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800C7D0C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C7D10: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800C7D14: ldc1        $f20, -0x98($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X98);
L_800C7D18:
    // 0x800C7D18: lw          $t4, 0x1C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1C);
    // 0x800C7D1C: lui         $s0, 0x7FFF
    ctx->r16 = S32(0X7FFF << 16);
    // 0x800C7D20: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800C7D24: and         $t5, $t4, $s2
    ctx->r13 = ctx->r12 & ctx->r18;
    // 0x800C7D28: sw          $t5, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r13;
    // 0x800C7D2C: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x800C7D30: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C7D34: jalr        $t9
    // 0x800C7D38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800C7D38: nop

    after_0:
    // 0x800C7D3C: lw          $t8, 0x44($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X44);
    // 0x800C7D40: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800C7D44: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800C7D48: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C7D4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7D50: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x800C7D54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C7D58: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C7D5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C7D60: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x800C7D64: add.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f4.d + ctx->f22.d;
    // 0x800C7D68: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800C7D6C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7D70: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C7D74: nop

    // 0x800C7D78: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800C7D7C: sw          $t2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r10;
    // 0x800C7D80: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800C7D84: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C7D88: beql        $v1, $zero, L_800C7DC8
    if (ctx->r3 == 0) {
        // 0x800C7D8C: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800C7DC8;
    }
    goto skip_2;
    // 0x800C7D8C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    skip_2:
    // 0x800C7D90: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7D94: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
L_800C7D98:
    // 0x800C7D98: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x800C7D9C: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C7DA0: beql        $at, $zero, L_800C7DBC
    if (ctx->r1 == 0) {
        // 0x800C7DA4: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800C7DBC;
    }
    goto skip_3;
    // 0x800C7DA4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800C7DA8: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    // 0x800C7DAC: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x800C7DB0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7DB4: subu        $s0, $t5, $a0
    ctx->r16 = SUB32(ctx->r13, ctx->r4);
    // 0x800C7DB8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800C7DBC:
    // 0x800C7DBC: bnel        $v1, $zero, L_800C7D98
    if (ctx->r3 != 0) {
        // 0x800C7DC0: lw          $t3, 0x10($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X10);
            goto L_800C7D98;
    }
    goto skip_4;
    // 0x800C7DC0: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    skip_4:
    // 0x800C7DC4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_800C7DC8:
    // 0x800C7DC8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800C7DCC: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x800C7DD0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800C7DD4: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C7DD8: bne         $at, $zero, L_800C7D18
    if (ctx->r1 != 0) {
        // 0x800C7DDC: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800C7D18;
    }
    // 0x800C7DDC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_800C7DE0:
    // 0x800C7DE0: lw          $t8, 0x1C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C);
    // 0x800C7DE4: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800C7DE8: addiu       $s7, $sp, 0xAA
    ctx->r23 = ADD32(ctx->r29, 0XAA);
    // 0x800C7DEC: and         $t6, $t8, $s2
    ctx->r14 = ctx->r24 & ctx->r18;
    // 0x800C7DF0: blez        $s3, L_800C7E7C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800C7DF4: sw          $t6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r14;
            goto L_800C7E7C;
    }
    // 0x800C7DF4: sw          $t6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r14;
    // 0x800C7DF8: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_800C7DFC:
    // 0x800C7DFC: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x800C7E00: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800C7E04: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C7E08: beq         $at, $zero, L_800C7E18
    if (ctx->r1 == 0) {
        // 0x800C7E0C: nop
    
            goto L_800C7E18;
    }
    // 0x800C7E0C: nop

    // 0x800C7E10: b           L_800C7E18
    // 0x800C7E14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800C7E18;
    // 0x800C7E14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C7E18:
    // 0x800C7E18: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x800C7E1C: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x800C7E20: lw          $s2, 0x38($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X38);
    // 0x800C7E24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800C7E28: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800C7E2C: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x800C7E30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C7E34: jalr        $t9
    // 0x800C7E38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C7E38: nop

    after_1:
    // 0x800C7E3C: lw          $a3, 0x20($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X20);
    // 0x800C7E40: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x800C7E44: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C7E48: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x800C7E4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C7E50: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800C7E54: jalr        $t9
    // 0x800C7E58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C7E58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800C7E5C: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x800C7E60: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x800C7E64: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800C7E68: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800C7E6C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800C7E70: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x800C7E74: bgtz        $s3, L_800C7DFC
    if (SIGNED(ctx->r19) > 0) {
        // 0x800C7E78: sw          $t4, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->r12;
            goto L_800C7DFC;
    }
    // 0x800C7E78: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
L_800C7E7C:
    // 0x800C7E7C: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800C7E80: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800C7E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C7E88: subu        $t7, $s4, $t5
    ctx->r15 = SUB32(ctx->r20, ctx->r13);
    // 0x800C7E8C: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800C7E90: jal         0x800C7B88
    // 0x800C7E94: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    _collectPVoices(rdram, ctx);
        goto after_3;
    // 0x800C7E94: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    after_3:
    // 0x800C7E98: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800C7E9C:
    // 0x800C7E9C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800C7EA0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C7EA4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800C7EA8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7EAC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800C7EB0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800C7EB4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800C7EB8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7EBC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800C7EC0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800C7EC4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800C7EC8: jr          $ra
    // 0x800C7ECC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800C7ECC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8006E080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E088: jal         0x80061348
    // 0x8006E08C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E08C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006E090: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E094: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E098: beq         $v0, $zero, L_8006E0B0
    if (ctx->r2 == 0) {
        // 0x8006E09C: nop
    
            goto L_8006E0B0;
    }
    // 0x8006E09C: nop

    // 0x8006E0A0: jal         0x80061348
    // 0x8006E0A4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E0A4: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_1:
    // 0x8006E0A8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E0AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E0B0:
    // 0x8006E0B0: b           L_8006E0C0
    // 0x8006E0B4: nop

        goto L_8006E0C0;
    // 0x8006E0B4: nop

    // 0x8006E0B8: b           L_8006E0C0
    // 0x8006E0BC: nop

        goto L_8006E0C0;
    // 0x8006E0BC: nop

L_8006E0C0:
    // 0x8006E0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E0C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E0C8: jr          $ra
    // 0x8006E0CC: nop

    return;
    // 0x8006E0CC: nop

;}
RECOMP_FUNC void func_80056C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056C60: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056C64: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80056C68: addiu       $t6, $t6, 0x2C4C
    ctx->r14 = ADD32(ctx->r14, 0X2C4C);
    // 0x80056C6C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80056C70: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056C74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056C78: beq         $t7, $at, L_80056D10
    if (ctx->r15 == ctx->r1) {
        // 0x80056C7C: nop
    
            goto L_80056D10;
    }
    // 0x80056C7C: nop

L_80056C80:
    // 0x80056C80: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x80056C84: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056C88: addiu       $t0, $t0, 0x2C4C
    ctx->r8 = ADD32(ctx->r8, 0X2C4C);
    // 0x80056C8C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80056C90: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80056C94: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80056C98: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80056C9C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80056CA0: nop

    // 0x80056CA4: bne         $t2, $t3, L_80056CE4
    if (ctx->r10 != ctx->r11) {
        // 0x80056CA8: nop
    
            goto L_80056CE4;
    }
    // 0x80056CA8: nop

    // 0x80056CAC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80056CB0: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80056CB4: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80056CB8: nop

    // 0x80056CBC: bne         $t4, $t5, L_80056CE4
    if (ctx->r12 != ctx->r13) {
        // 0x80056CC0: nop
    
            goto L_80056CE4;
    }
    // 0x80056CC0: nop

    // 0x80056CC4: lh          $t6, 0x4($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X4);
    // 0x80056CC8: lbu         $t7, 0x16($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X16);
    // 0x80056CCC: nop

    // 0x80056CD0: bne         $t6, $t7, L_80056CE4
    if (ctx->r14 != ctx->r15) {
        // 0x80056CD4: nop
    
            goto L_80056CE4;
    }
    // 0x80056CD4: nop

    // 0x80056CD8: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x80056CDC: b           L_80056D20
    // 0x80056CE0: nop

        goto L_80056D20;
    // 0x80056CE0: nop

L_80056CE4:
    // 0x80056CE4: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x80056CE8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80056CEC: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x80056CF0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x80056CF4: sra         $t2, $t0, 16
    ctx->r10 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80056CF8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80056CFC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80056D00: lh          $t4, 0x2C4C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2C4C);
    // 0x80056D04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056D08: bne         $t4, $at, L_80056C80
    if (ctx->r12 != ctx->r1) {
        // 0x80056D0C: sh          $t9, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r25;
            goto L_80056C80;
    }
    // 0x80056D0C: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
L_80056D10:
    // 0x80056D10: b           L_80056D20
    // 0x80056D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80056D20;
    // 0x80056D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056D18: b           L_80056D20
    // 0x80056D1C: nop

        goto L_80056D20;
    // 0x80056D1C: nop

L_80056D20:
    // 0x80056D20: jr          $ra
    // 0x80056D24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80056D24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8007405C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007405C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074064: jal         0x80061348
    // 0x80074068: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074068: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007406C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074070: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074074: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074078: beq         $v0, $zero, L_80074094
    if (ctx->r2 == 0) {
        // 0x8007407C: nop
    
            goto L_80074094;
    }
    // 0x8007407C: nop

    // 0x80074080: jal         0x80061348
    // 0x80074084: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074084: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074088: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007408C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074090: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074094:
    // 0x80074094: b           L_800740A4
    // 0x80074098: nop

        goto L_800740A4;
    // 0x80074098: nop

    // 0x8007409C: b           L_800740A4
    // 0x800740A0: nop

        goto L_800740A4;
    // 0x800740A0: nop

L_800740A4:
    // 0x800740A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800740A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800740AC: jr          $ra
    // 0x800740B0: nop

    return;
    // 0x800740B0: nop

;}
RECOMP_FUNC void func_80071ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071EE0: jal         0x80061348
    // 0x80071EE4: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071EE4: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    after_0:
    // 0x80071EE8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071EEC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071EF0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071EF4: beq         $v0, $zero, L_80071F10
    if (ctx->r2 == 0) {
        // 0x80071EF8: nop
    
            goto L_80071F10;
    }
    // 0x80071EF8: nop

    // 0x80071EFC: jal         0x80061348
    // 0x80071F00: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071F00: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    after_1:
    // 0x80071F04: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071F08: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071F0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071F10:
    // 0x80071F10: b           L_80071F20
    // 0x80071F14: nop

        goto L_80071F20;
    // 0x80071F14: nop

    // 0x80071F18: b           L_80071F20
    // 0x80071F1C: nop

        goto L_80071F20;
    // 0x80071F1C: nop

L_80071F20:
    // 0x80071F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071F28: jr          $ra
    // 0x80071F2C: nop

    return;
    // 0x80071F2C: nop

;}
RECOMP_FUNC void func_800B0A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0A3C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B0A40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B0A44: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800B0A48: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800B0A4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B0A50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B0A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0A58: lui         $t6, 0x80A2
    ctx->r14 = S32(0X80A2 << 16);
    // 0x800B0A5C: addiu       $t6, $t6, 0x25B0
    ctx->r14 = ADD32(ctx->r14, 0X25B0);
    // 0x800B0A60: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0A64: sw          $t6, -0x458($at)
    MEM_W(-0X458, ctx->r1) = ctx->r14;
    // 0x800B0A68: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B0A6C: addiu       $t7, $t7, 0x5B0
    ctx->r15 = ADD32(ctx->r15, 0X5B0);
    // 0x800B0A70: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800B0A74: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x800B0A78: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800B0A7C: lw          $t0, -0x458($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X458);
    // 0x800B0A80: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B0A84: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B0A88: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800B0A8C: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800B0A90: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B0A94: jal         0x800BD1FC
    // 0x800B0A98: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800B0A98: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x800B0A9C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B0AA0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0AA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800B0AA8: jal         0x800BD218
    // 0x800B0AAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B0AAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800B0AB0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B0AB4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B0AB8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B0ABC: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800B0AC0: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800B0AC4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800B0AC8: jal         0x800BD1FC
    // 0x800B0ACC: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B0ACC: nop

    after_2:
    // 0x800B0AD0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B0AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0AD8: jal         0x800BED70
    // 0x800B0ADC: nop

    Spi_GetHeader(rdram, ctx);
        goto after_3;
    // 0x800B0ADC: nop

    after_3:
    // 0x800B0AE0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800B0AE4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800B0AE8: lw          $t2, 0x494($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X494);
    // 0x800B0AEC: nop

    // 0x800B0AF0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800B0AF4: bgez        $t2, L_800B0B10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B0AF8: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_800B0B10;
    }
    // 0x800B0AF8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800B0AFC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800B0B00: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B0B04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B0B08: nop

    // 0x800B0B0C: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_800B0B10:
    // 0x800B0B10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0B14: lwc1        $f11, -0x6D0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6D0);
    // 0x800B0B18: lwc1        $f10, -0x6CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6CC);
    // 0x800B0B1C: nop

    // 0x800B0B20: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800B0B24: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B0B28: nop

    // 0x800B0B2C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B0B30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0B34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0B38: nop

    // 0x800B0B3C: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800B0B40: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800B0B44: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B0B48: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x800B0B4C: jal         0x800BC6EC
    // 0x800B0B50: sll         $a0, $t4, 4
    ctx->r4 = S32(ctx->r12 << 4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800B0B50: sll         $a0, $t4, 4
    ctx->r4 = S32(ctx->r12 << 4);
    after_4:
    // 0x800B0B54: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800B0B58: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0B5C: nop

    // 0x800B0B60: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800B0B64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0B68: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0B6C: jal         0x800BEE48
    // 0x800B0B70: nop

    Spi_LimitedDecompress(rdram, ctx);
        goto after_5;
    // 0x800B0B70: nop

    after_5:
    // 0x800B0B74: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B0B78: addiu       $t6, $t6, 0x4A8
    ctx->r14 = ADD32(ctx->r14, 0X4A8);
    // 0x800B0B7C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800B0B80: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B0B84: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800B0B88: blez        $t7, L_800B0CB0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B0B8C: nop
    
            goto L_800B0CB0;
    }
    // 0x800B0B8C: nop

L_800B0B90:
    // 0x800B0B90: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B0B94: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0B98: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800B0B9C: nop

    // 0x800B0BA0: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800B0BA4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BA8: nop

    // 0x800B0BAC: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B0BB0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B0BB4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BB8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0BBC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800B0BC0: nop

    // 0x800B0BC4: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x800B0BC8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BCC: nop

    // 0x800B0BD0: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800B0BD4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B0BD8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BDC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0BE0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800B0BE4: nop

    // 0x800B0BE8: sh          $t9, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r25;
    // 0x800B0BEC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BF0: nop

    // 0x800B0BF4: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B0BF8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B0BFC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B0C04: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x800B0C08: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C0C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C10: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x800B0C14: nop

    // 0x800B0C18: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x800B0C1C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C20: nop

    // 0x800B0C24: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x800B0C28: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800B0C2C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C30: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C34: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800B0C38: nop

    // 0x800B0C3C: sh          $t1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r9;
    // 0x800B0C40: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C44: nop

    // 0x800B0C48: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800B0C4C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800B0C50: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C54: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800B0C58: sb          $t5, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r13;
    // 0x800B0C5C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C60: nop

    // 0x800B0C64: lbu         $s1, 0xF($t7)
    ctx->r17 = MEM_BU(ctx->r15, 0XF);
    // 0x800B0C68: nop

    // 0x800B0C6C: sb          $s1, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r17;
    // 0x800B0C70: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C74: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800B0C78: sb          $s0, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r16;
    // 0x800B0C7C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C80: nop

    // 0x800B0C84: sb          $s0, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r16;
    // 0x800B0C88: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C8C: nop

    // 0x800B0C90: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800B0C94: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800B0C98: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800B0C9C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800B0CA0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B0CA4: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B0CA8: bne         $at, $zero, L_800B0B90
    if (ctx->r1 != 0) {
        // 0x800B0CAC: sw          $t3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r11;
            goto L_800B0B90;
    }
    // 0x800B0CAC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800B0CB0:
    // 0x800B0CB0: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x800B0CB4: nop

    // 0x800B0CB8: beq         $t5, $zero, L_800B0D04
    if (ctx->r13 == 0) {
        // 0x800B0CBC: nop
    
            goto L_800B0D04;
    }
    // 0x800B0CBC: nop

    // 0x800B0CC0: jal         0x800BC6EC
    // 0x800B0CC4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800B0CC4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_6:
    // 0x800B0CC8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B0CCC: lw          $t6, -0x440($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X440);
    // 0x800B0CD0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800B0CD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0CD8: sw          $s2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r18;
    // 0x800B0CDC: sw          $s2, -0x440($at)
    MEM_W(-0X440, ctx->r1) = ctx->r18;
    // 0x800B0CE0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B0CE4: lw          $t8, -0x440($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X440);
    // 0x800B0CE8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800B0CEC: nop

    // 0x800B0CF0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800B0CF4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B0CF8: lw          $t9, -0x440($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X440);
    // 0x800B0CFC: nop

    // 0x800B0D00: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_800B0D04:
    // 0x800B0D04: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800B0D08: b           L_800B0D18
    // 0x800B0D0C: nop

        goto L_800B0D18;
    // 0x800B0D0C: nop

    // 0x800B0D10: b           L_800B0D18
    // 0x800B0D14: nop

        goto L_800B0D18;
    // 0x800B0D14: nop

L_800B0D18:
    // 0x800B0D18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B0D1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0D20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0D24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B0D28: jr          $ra
    // 0x800B0D2C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B0D2C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800ABC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABC30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ABC34: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ABC38: nop

    // 0x800ABC3C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800ABC40: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABC44: nop

    // 0x800ABC48: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800ABC4C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800ABC50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800ABC54: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800ABC58: lui         $t9, 0xFF10
    ctx->r25 = S32(0XFF10 << 16);
    // 0x800ABC5C: ori         $t9, $t9, 0x13F
    ctx->r25 = ctx->r25 | 0X13F;
    // 0x800ABC60: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800ABC64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800ABC68: lw          $t1, 0x24DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X24DC);
    // 0x800ABC6C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800ABC70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABC74: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800ABC78: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800ABC7C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABC80: nop

    // 0x800ABC84: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800ABC88: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800ABC8C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800ABC90: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800ABC94: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800ABC98: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x800ABC9C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800ABCA0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800ABCA4: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x800ABCA8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800ABCAC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800ABCB0:
    // 0x800ABCB0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABCB4: nop

    // 0x800ABCB8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800ABCBC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800ABCC0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x800ABCC4: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800ABCC8: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x800ABCCC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800ABCD0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800ABCD4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800ABCD8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800ABCDC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800ABCE0: lhu         $t6, -0x4CB8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4CB8);
    // 0x800ABCE4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800ABCE8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800ABCEC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800ABCF0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800ABCF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800ABCF8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800ABCFC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD00: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD04: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800ABD08: addiu       $t5, $t5, -0x4CB8
    ctx->r13 = ADD32(ctx->r13, -0X4CB8);
    // 0x800ABD0C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800ABD10: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800ABD14: sll         $t8, $t1, 3
    ctx->r24 = S32(ctx->r9 << 3);
    // 0x800ABD18: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800ABD1C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800ABD20: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800ABD24: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800ABD28: nop

    // 0x800ABD2C: bne         $t7, $t0, L_800ABDA0
    if (ctx->r15 != ctx->r8) {
        // 0x800ABD30: nop
    
            goto L_800ABDA0;
    }
    // 0x800ABD30: nop

L_800ABD34:
    // 0x800ABD34: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD38: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD3C: nop

    // 0x800ABD40: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800ABD44: slti        $at, $t4, 0xEF
    ctx->r1 = SIGNED(ctx->r12) < 0XEF ? 1 : 0;
    // 0x800ABD48: bne         $at, $zero, L_800ABD58
    if (ctx->r1 != 0) {
        // 0x800ABD4C: nop
    
            goto L_800ABD58;
    }
    // 0x800ABD4C: nop

    // 0x800ABD50: b           L_800ABDA0
    // 0x800ABD54: nop

        goto L_800ABDA0;
    // 0x800ABD54: nop

L_800ABD58:
    // 0x800ABD58: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD5C: nop

    // 0x800ABD60: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x800ABD64: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800ABD68: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD6C: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD70: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800ABD74: addiu       $t0, $t0, -0x4CB8
    ctx->r8 = ADD32(ctx->r8, -0X4CB8);
    // 0x800ABD78: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800ABD7C: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800ABD80: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800ABD84: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x800ABD88: addu        $t2, $t7, $t0
    ctx->r10 = ADD32(ctx->r15, ctx->r8);
    // 0x800ABD8C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800ABD90: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x800ABD94: nop

    // 0x800ABD98: beq         $t3, $t1, L_800ABD34
    if (ctx->r11 == ctx->r9) {
        // 0x800ABD9C: nop
    
            goto L_800ABD34;
    }
    // 0x800ABD9C: nop

L_800ABDA0:
    // 0x800ABDA0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABDA4: nop

    // 0x800ABDA8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800ABDAC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800ABDB0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800ABDB4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800ABDB8: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800ABDBC: lui         $at, 0xF64F
    ctx->r1 = S32(0XF64F << 16);
    // 0x800ABDC0: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x800ABDC4: andi        $t4, $t8, 0x3FF
    ctx->r12 = ctx->r24 & 0X3FF;
    // 0x800ABDC8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800ABDCC: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x800ABDD0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x800ABDD4: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x800ABDD8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800ABDDC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800ABDE0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABDE4: andi        $t5, $t1, 0x3FF
    ctx->r13 = ctx->r9 & 0X3FF;
    // 0x800ABDE8: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800ABDEC: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800ABDF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABDF4: nop

    // 0x800ABDF8: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x800ABDFC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800ABE00: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x800ABE04: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800ABE08: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800ABE0C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800ABE10: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800ABE14: nop

    // 0x800ABE18: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800ABE1C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800ABE20: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800ABE24: nop

    // 0x800ABE28: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x800ABE2C: slti        $at, $t5, 0xEF
    ctx->r1 = SIGNED(ctx->r13) < 0XEF ? 1 : 0;
    // 0x800ABE30: bne         $at, $zero, L_800ABCB0
    if (ctx->r1 != 0) {
        // 0x800ABE34: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_800ABCB0;
    }
    // 0x800ABE34: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800ABE38: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABE3C: nop

    // 0x800ABE40: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800ABE44: b           L_800ABE4C
    // 0x800ABE48: nop

        goto L_800ABE4C;
    // 0x800ABE48: nop

L_800ABE4C:
    // 0x800ABE4C: jr          $ra
    // 0x800ABE50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800ABE50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800650C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800650C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800650C8: nop

    // 0x800650CC: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x800650D0: nop

    // 0x800650D4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800650D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800650DC: jr          $ra
    // 0x800650E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800650E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800650E4: jr          $ra
    // 0x800650E8: nop

    return;
    // 0x800650E8: nop

    // 0x800650EC: jr          $ra
    // 0x800650F0: nop

    return;
    // 0x800650F0: nop

;}
RECOMP_FUNC void func_8005A144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A14C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005A150: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A154: lw          $t6, 0x630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X630);
    // 0x8005A158: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005A15C: addiu       $t7, $t6, 0x318
    ctx->r15 = ADD32(ctx->r14, 0X318);
    // 0x8005A160: beq         $t7, $t8, L_8005A188
    if (ctx->r15 == ctx->r24) {
        // 0x8005A164: nop
    
            goto L_8005A188;
    }
    // 0x8005A164: nop

    // 0x8005A168: addiu       $t9, $t6, 0x32A
    ctx->r25 = ADD32(ctx->r14, 0X32A);
    // 0x8005A16C: beq         $t9, $t8, L_8005A188
    if (ctx->r25 == ctx->r24) {
        // 0x8005A170: nop
    
            goto L_8005A188;
    }
    // 0x8005A170: nop

    // 0x8005A174: addiu       $t0, $t6, 0x18C
    ctx->r8 = ADD32(ctx->r14, 0X18C);
    // 0x8005A178: beq         $t0, $t8, L_8005A188
    if (ctx->r8 == ctx->r24) {
        // 0x8005A17C: nop
    
            goto L_8005A188;
    }
    // 0x8005A17C: nop

    // 0x8005A180: b           L_8005A2BC
    // 0x8005A184: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A184: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005A188:
    // 0x8005A188: jal         0x80059E28
    // 0x8005A18C: nop

    func_80059E28(rdram, ctx);
        goto after_0;
    // 0x8005A18C: nop

    after_0:
    // 0x8005A190: bne         $v0, $zero, L_8005A1A0
    if (ctx->r2 != 0) {
        // 0x8005A194: nop
    
            goto L_8005A1A0;
    }
    // 0x8005A194: nop

    // 0x8005A198: b           L_8005A2BC
    // 0x8005A19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005A1A0:
    // 0x8005A1A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005A1A4: lw          $t1, 0x630($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X630);
    // 0x8005A1A8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8005A1AC: addiu       $t2, $t1, 0x318
    ctx->r10 = ADD32(ctx->r9, 0X318);
    // 0x8005A1B0: bne         $t2, $t3, L_8005A220
    if (ctx->r10 != ctx->r11) {
        // 0x8005A1B4: nop
    
            goto L_8005A220;
    }
    // 0x8005A1B4: nop

    // 0x8005A1B8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005A1BC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005A1C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A1C4: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8005A1C8: nop

    // 0x8005A1CC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005A1D0: nop

    // 0x8005A1D4: bc1f        L_8005A1EC
    if (!c1cs) {
        // 0x8005A1D8: nop
    
            goto L_8005A1EC;
    }
    // 0x8005A1D8: nop

    // 0x8005A1DC: b           L_8005A2BC
    // 0x8005A1E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A1E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005A1E4: b           L_8005A220
    // 0x8005A1E8: nop

        goto L_8005A220;
    // 0x8005A1E8: nop

L_8005A1EC:
    // 0x8005A1EC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005A1F0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005A1F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A1F8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8005A1FC: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8005A200: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8005A204: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8005A208: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005A20C: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8005A210: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8005A214: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x8005A218: b           L_8005A2BC
    // 0x8005A21C: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
        goto L_8005A2BC;
    // 0x8005A21C: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
L_8005A220:
    // 0x8005A220: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005A224: lw          $t9, 0x630($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X630);
    // 0x8005A228: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005A22C: addiu       $t8, $t9, 0x32A
    ctx->r24 = ADD32(ctx->r25, 0X32A);
    // 0x8005A230: beq         $t8, $t2, L_8005A244
    if (ctx->r24 == ctx->r10) {
        // 0x8005A234: nop
    
            goto L_8005A244;
    }
    // 0x8005A234: nop

    // 0x8005A238: addiu       $t3, $t9, 0x18C
    ctx->r11 = ADD32(ctx->r25, 0X18C);
    // 0x8005A23C: bne         $t3, $t2, L_8005A2AC
    if (ctx->r11 != ctx->r10) {
        // 0x8005A240: nop
    
            goto L_8005A2AC;
    }
    // 0x8005A240: nop

L_8005A244:
    // 0x8005A244: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005A248: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005A24C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005A250: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8005A254: nop

    // 0x8005A258: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005A25C: nop

    // 0x8005A260: bc1f        L_8005A278
    if (!c1cs) {
        // 0x8005A264: nop
    
            goto L_8005A278;
    }
    // 0x8005A264: nop

    // 0x8005A268: b           L_8005A2BC
    // 0x8005A26C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A26C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005A270: b           L_8005A2AC
    // 0x8005A274: nop

        goto L_8005A2AC;
    // 0x8005A274: nop

L_8005A278:
    // 0x8005A278: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A27C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005A280: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A284: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8005A288: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x8005A28C: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x8005A290: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8005A294: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005A298: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8005A29C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8005A2A0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8005A2A4: b           L_8005A2BC
    // 0x8005A2A8: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
        goto L_8005A2BC;
    // 0x8005A2A8: addiu       $v0, $zero, 0x5BD
    ctx->r2 = ADD32(0, 0X5BD);
L_8005A2AC:
    // 0x8005A2AC: b           L_8005A2BC
    // 0x8005A2B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005A2BC;
    // 0x8005A2B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005A2B4: b           L_8005A2BC
    // 0x8005A2B8: nop

        goto L_8005A2BC;
    // 0x8005A2B8: nop

L_8005A2BC:
    // 0x8005A2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A2C4: jr          $ra
    // 0x8005A2C8: nop

    return;
    // 0x8005A2C8: nop

;}
RECOMP_FUNC void Thread_GetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C10AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C10B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C10B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C10B8: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C10BC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C10C0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C10C4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C10C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C10CC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C10D0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C10D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C10D8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C10DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C10E0: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C10E4: nop

    // 0x800C10E8: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C10EC: bne         $t9, $zero, L_800C10FC
    if (ctx->r25 != 0) {
        // 0x800C10F0: nop
    
            goto L_800C10FC;
    }
    // 0x800C10F0: nop

    // 0x800C10F4: b           L_800C1144
    // 0x800C10F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1144;
    // 0x800C10F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C10FC:
    // 0x800C10FC: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C1100: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C1104: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C1108: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C110C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C1110: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C1114: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C1118: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C111C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C1120: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C1124: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C1128: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C112C: jal         0x800CBA00
    // 0x800C1130: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osGetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1130: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C1134: b           L_800C1144
    // 0x800C1138: nop

        goto L_800C1144;
    // 0x800C1138: nop

    // 0x800C113C: b           L_800C1144
    // 0x800C1140: nop

        goto L_800C1144;
    // 0x800C1140: nop

L_800C1144:
    // 0x800C1144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C114C: jr          $ra
    // 0x800C1150: nop

    return;
    // 0x800C1150: nop

;}
RECOMP_FUNC void ContPak_WriteFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AED0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AED10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AED14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AED18: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AED1C: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800AED20: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AED24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AED28: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AED2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AED30: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AED34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AED38: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800AED3C: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AED40: jal         0x800AE40C
    // 0x800AED44: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AED44: nop

    after_0:
    // 0x800AED48: bgez        $v0, L_800AED70
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AED4C: nop
    
            goto L_800AED70;
    }
    // 0x800AED4C: nop

    // 0x800AED50: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AED54: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AED58: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800AED5C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AED60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AED64: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AED68: b           L_800AEDD8
    // 0x800AED6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AEDD8;
    // 0x800AED6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AED70:
    // 0x800AED70: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AED74: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AED78: lw          $t3, 0x1670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1670);
    // 0x800AED7C: lw          $t2, 0x1674($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1674);
    // 0x800AED80: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AED84: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AED88: lw          $a3, 0x1678($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1678);
    // 0x800AED8C: lw          $a1, 0x167C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X167C);
    // 0x800AED90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AED94: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AED98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AED9C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AEDA0: jal         0x800C72EC
    // 0x800AEDA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_1;
    // 0x800AEDA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AEDA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEDAC: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AEDB0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AEDB4: lw          $t4, 0x129C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X129C);
    // 0x800AEDB8: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800AEDBC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AEDC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEDC4: sw          $t5, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r13;
    // 0x800AEDC8: b           L_800AEDD8
    // 0x800AEDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AEDD8;
    // 0x800AEDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEDD0: b           L_800AEDD8
    // 0x800AEDD4: nop

        goto L_800AEDD8;
    // 0x800AEDD4: nop

L_800AEDD8:
    // 0x800AEDD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEDDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AEDE0: jr          $ra
    // 0x800AEDE4: nop

    return;
    // 0x800AEDE4: nop

;}
RECOMP_FUNC void func_80069388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006938C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069390: jal         0x80061348
    // 0x80069394: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069394: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x80069398: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006939C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800693A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800693A4: beq         $v0, $zero, L_800693E4
    if (ctx->r2 == 0) {
        // 0x800693A8: nop
    
            goto L_800693E4;
    }
    // 0x800693A8: nop

    // 0x800693AC: jal         0x80061348
    // 0x800693B0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800693B0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x800693B4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800693B8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800693BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800693C0: beq         $v0, $zero, L_800693E4
    if (ctx->r2 == 0) {
        // 0x800693C4: nop
    
            goto L_800693E4;
    }
    // 0x800693C4: nop

    // 0x800693C8: jal         0x80061348
    // 0x800693CC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800693CC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x800693D0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800693D4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800693D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800693DC: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x800693E0: nop
    
            goto L_80069628;
    }
    // 0x800693E0: nop

L_800693E4:
    // 0x800693E4: jal         0x80061348
    // 0x800693E8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800693E8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x800693EC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800693F0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800693F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800693F8: beq         $v0, $zero, L_80069438
    if (ctx->r2 == 0) {
        // 0x800693FC: nop
    
            goto L_80069438;
    }
    // 0x800693FC: nop

    // 0x80069400: jal         0x80061348
    // 0x80069404: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x80069404: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x80069408: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006940C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069410: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069414: beq         $v0, $zero, L_80069438
    if (ctx->r2 == 0) {
        // 0x80069418: nop
    
            goto L_80069438;
    }
    // 0x80069418: nop

    // 0x8006941C: jal         0x80061348
    // 0x80069420: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x80069420: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x80069424: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069428: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006942C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069430: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069434: nop
    
            goto L_80069628;
    }
    // 0x80069434: nop

L_80069438:
    // 0x80069438: jal         0x80061348
    // 0x8006943C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006943C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x80069440: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069444: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069448: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006944C: beq         $v0, $zero, L_8006948C
    if (ctx->r2 == 0) {
        // 0x80069450: nop
    
            goto L_8006948C;
    }
    // 0x80069450: nop

    // 0x80069454: jal         0x80061348
    // 0x80069458: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x80069458: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006945C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069460: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069464: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069468: beq         $v0, $zero, L_8006948C
    if (ctx->r2 == 0) {
        // 0x8006946C: nop
    
            goto L_8006948C;
    }
    // 0x8006946C: nop

    // 0x80069470: jal         0x80061348
    // 0x80069474: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x80069474: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x80069478: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006947C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069480: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069484: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069488: nop
    
            goto L_80069628;
    }
    // 0x80069488: nop

L_8006948C:
    // 0x8006948C: jal         0x80061348
    // 0x80069490: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x80069490: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x80069494: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069498: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006949C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800694A0: beq         $v0, $zero, L_800694E0
    if (ctx->r2 == 0) {
        // 0x800694A4: nop
    
            goto L_800694E0;
    }
    // 0x800694A4: nop

    // 0x800694A8: jal         0x80061348
    // 0x800694AC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x800694AC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x800694B0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800694B4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800694B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800694BC: beq         $v0, $zero, L_800694E0
    if (ctx->r2 == 0) {
        // 0x800694C0: nop
    
            goto L_800694E0;
    }
    // 0x800694C0: nop

    // 0x800694C4: jal         0x80061348
    // 0x800694C8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x800694C8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x800694CC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800694D0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800694D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800694D8: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x800694DC: nop
    
            goto L_80069628;
    }
    // 0x800694DC: nop

L_800694E0:
    // 0x800694E0: jal         0x80061348
    // 0x800694E4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x800694E4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x800694E8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800694EC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800694F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800694F4: beq         $v0, $zero, L_80069534
    if (ctx->r2 == 0) {
        // 0x800694F8: nop
    
            goto L_80069534;
    }
    // 0x800694F8: nop

    // 0x800694FC: jal         0x80061348
    // 0x80069500: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x80069500: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x80069504: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069508: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006950C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069510: beq         $v0, $zero, L_80069534
    if (ctx->r2 == 0) {
        // 0x80069514: nop
    
            goto L_80069534;
    }
    // 0x80069514: nop

    // 0x80069518: jal         0x80061348
    // 0x8006951C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006951C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x80069520: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069524: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069528: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006952C: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069530: nop
    
            goto L_80069628;
    }
    // 0x80069530: nop

L_80069534:
    // 0x80069534: jal         0x80061348
    // 0x80069538: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x80069538: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006953C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069540: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069544: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069548: beq         $v0, $zero, L_80069588
    if (ctx->r2 == 0) {
        // 0x8006954C: nop
    
            goto L_80069588;
    }
    // 0x8006954C: nop

    // 0x80069550: jal         0x80061348
    // 0x80069554: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069554: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069558: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006955C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069560: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069564: beq         $v0, $zero, L_80069588
    if (ctx->r2 == 0) {
        // 0x80069568: nop
    
            goto L_80069588;
    }
    // 0x80069568: nop

    // 0x8006956C: jal         0x80061348
    // 0x80069570: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x80069570: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x80069574: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069578: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006957C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069580: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x80069584: nop
    
            goto L_80069628;
    }
    // 0x80069584: nop

L_80069588:
    // 0x80069588: jal         0x80061348
    // 0x8006958C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006958C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x80069590: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x80069594: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069598: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006959C: beq         $v0, $zero, L_800695DC
    if (ctx->r2 == 0) {
        // 0x800695A0: nop
    
            goto L_800695DC;
    }
    // 0x800695A0: nop

    // 0x800695A4: jal         0x80061348
    // 0x800695A8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x800695A8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x800695AC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x800695B0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x800695B4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800695B8: beq         $v0, $zero, L_800695DC
    if (ctx->r2 == 0) {
        // 0x800695BC: nop
    
            goto L_800695DC;
    }
    // 0x800695BC: nop

    // 0x800695C0: jal         0x80061348
    // 0x800695C4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x800695C4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x800695C8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800695CC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800695D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800695D4: bne         $v0, $zero, L_80069628
    if (ctx->r2 != 0) {
        // 0x800695D8: nop
    
            goto L_80069628;
    }
    // 0x800695D8: nop

L_800695DC:
    // 0x800695DC: jal         0x80061348
    // 0x800695E0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x800695E0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x800695E4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800695E8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800695EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800695F0: beq         $v0, $zero, L_80069628
    if (ctx->r2 == 0) {
        // 0x800695F4: nop
    
            goto L_80069628;
    }
    // 0x800695F4: nop

    // 0x800695F8: jal         0x80061348
    // 0x800695FC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x800695FC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x80069600: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069604: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069608: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006960C: beq         $v0, $zero, L_80069628
    if (ctx->r2 == 0) {
        // 0x80069610: nop
    
            goto L_80069628;
    }
    // 0x80069610: nop

    // 0x80069614: jal         0x80061348
    // 0x80069618: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x80069618: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006961C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069620: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069624: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80069628:
    // 0x80069628: b           L_80069638
    // 0x8006962C: nop

        goto L_80069638;
    // 0x8006962C: nop

    // 0x80069630: b           L_80069638
    // 0x80069634: nop

        goto L_80069638;
    // 0x80069634: nop

L_80069638:
    // 0x80069638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006963C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069640: jr          $ra
    // 0x80069644: nop

    return;
    // 0x80069644: nop

;}
RECOMP_FUNC void func_800656B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800656B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800656BC: jal         0x8005F064
    // 0x800656C0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800656C0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x800656C4: b           L_800656D4
    // 0x800656C8: nop

        goto L_800656D4;
    // 0x800656C8: nop

    // 0x800656CC: b           L_800656D4
    // 0x800656D0: nop

        goto L_800656D4;
    // 0x800656D0: nop

L_800656D4:
    // 0x800656D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800656D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800656DC: jr          $ra
    // 0x800656E0: nop

    return;
    // 0x800656E0: nop

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
RECOMP_FUNC void func_8008EAA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EAA8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008EAAC: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x8008EAB0: nop

    // 0x8008EAB4: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8008EAB8: beq         $t7, $zero, L_8008EADC
    if (ctx->r15 == 0) {
        // 0x8008EABC: nop
    
            goto L_8008EADC;
    }
    // 0x8008EABC: nop

    // 0x8008EAC0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8008EAC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EAC8: sw          $t8, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r24;
    // 0x8008EACC: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008EAD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EAD4: b           L_8008EB90
    // 0x8008EAD8: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
        goto L_8008EB90;
    // 0x8008EAD8: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
L_8008EADC:
    // 0x8008EADC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EAE0: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x8008EAE4: nop

    // 0x8008EAE8: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8008EAEC: beq         $t1, $zero, L_8008EB10
    if (ctx->r9 == 0) {
        // 0x8008EAF0: nop
    
            goto L_8008EB10;
    }
    // 0x8008EAF0: nop

    // 0x8008EAF4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008EAF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EAFC: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x8008EB00: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8008EB04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB08: b           L_8008EB90
    // 0x8008EB0C: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
        goto L_8008EB90;
    // 0x8008EB0C: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_8008EB10:
    // 0x8008EB10: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8008EB14: lh          $t4, -0x4CC8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CC8);
    // 0x8008EB18: nop

    // 0x8008EB1C: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x8008EB20: beq         $t5, $zero, L_8008EB44
    if (ctx->r13 == 0) {
        // 0x8008EB24: nop
    
            goto L_8008EB44;
    }
    // 0x8008EB24: nop

    // 0x8008EB28: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008EB2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB30: sw          $t6, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r14;
    // 0x8008EB34: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8008EB38: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB3C: b           L_8008EB90
    // 0x8008EB40: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
        goto L_8008EB90;
    // 0x8008EB40: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
L_8008EB44:
    // 0x8008EB44: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008EB48: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x8008EB4C: nop

    // 0x8008EB50: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x8008EB54: beq         $t9, $zero, L_8008EB78
    if (ctx->r25 == 0) {
        // 0x8008EB58: nop
    
            goto L_8008EB78;
    }
    // 0x8008EB58: nop

    // 0x8008EB5C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8008EB60: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB64: sw          $t0, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r8;
    // 0x8008EB68: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008EB6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB70: b           L_8008EB90
    // 0x8008EB74: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
        goto L_8008EB90;
    // 0x8008EB74: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
L_8008EB78:
    // 0x8008EB78: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8008EB7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB80: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x8008EB84: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8008EB88: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB8C: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_8008EB90:
    // 0x8008EB90: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8008EB94: lw          $t4, 0x61CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X61CC);
    // 0x8008EB98: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB9C: multu       $a0, $t4
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EBA0: mflo        $t5
    ctx->r13 = lo;
    // 0x8008EBA4: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008EBA8: nop

    // 0x8008EBAC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8008EBB0: lw          $t6, 0x61D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X61D4);
    // 0x8008EBB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EBB8: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EBBC: mflo        $t7
    ctx->r15 = lo;
    // 0x8008EBC0: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x8008EBC4: nop

    // 0x8008EBC8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008EBCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EBD0: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8008EBD4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8008EBD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008EBDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008EBE0: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008EBE4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008EBE8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8008EBEC: lw          $t1, 0x61CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X61CC);
    // 0x8008EBF0: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x8008EBF4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8008EBF8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8008EBFC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008EC00: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008EC04: beq         $at, $zero, L_8008EC30
    if (ctx->r1 == 0) {
        // 0x8008EC08: nop
    
            goto L_8008EC30;
    }
    // 0x8008EC08: nop

    // 0x8008EC0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EC10: sw          $zero, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = 0;
    // 0x8008EC14: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8008EC18: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8008EC1C: lw          $t4, 0x61D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X61D4);
    // 0x8008EC20: lw          $t3, 0x6BA0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BA0);
    // 0x8008EC24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EC28: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8008EC2C: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
L_8008EC30:
    // 0x8008EC30: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8008EC34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EC38: lwc1        $f8, -0x4534($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8008EC3C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8008EC40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008EC44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008EC48: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008EC4C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008EC50: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008EC54: lw          $t0, 0x61D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X61D4);
    // 0x8008EC58: lw          $t8, 0x6BA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BA0);
    // 0x8008EC5C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8008EC60: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008EC64: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8008EC68: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008EC6C: beq         $at, $zero, L_8008EC7C
    if (ctx->r1 == 0) {
        // 0x8008EC70: nop
    
            goto L_8008EC7C;
    }
    // 0x8008EC70: nop

    // 0x8008EC74: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EC78: sw          $zero, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = 0;
L_8008EC7C:
    // 0x8008EC7C: jr          $ra
    // 0x8008EC80: nop

    return;
    // 0x8008EC80: nop

    // 0x8008EC84: jr          $ra
    // 0x8008EC88: nop

    return;
    // 0x8008EC88: nop

;}
RECOMP_FUNC void AudioDriver_LoadBanks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B96D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B96D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B96DC: lui         $t6, 0x76
    ctx->r14 = S32(0X76 << 16);
    // 0x800B96E0: lui         $t7, 0x75
    ctx->r15 = S32(0X75 << 16);
    // 0x800B96E4: addiu       $t7, $t7, 0x6140
    ctx->r15 = ADD32(ctx->r15, 0X6140);
    // 0x800B96E8: addiu       $t6, $t6, -0x69F0
    ctx->r14 = ADD32(ctx->r14, -0X69F0);
    // 0x800B96EC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B96F0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800B96F4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B96F8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B96FC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9700: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9704: addiu       $a0, $a0, -0x370
    ctx->r4 = ADD32(ctx->r4, -0X370);
    // 0x800B9708: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x800B970C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B9710: jal         0x800C7950
    // 0x800B9714: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800B9714: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x800B9718: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B971C: lui         $a0, 0x75
    ctx->r4 = S32(0X75 << 16);
    // 0x800B9720: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B9724: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B9728: jal         0x800BC590
    // 0x800B972C: addiu       $a0, $a0, 0x6140
    ctx->r4 = ADD32(ctx->r4, 0X6140);
    AudioDmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B972C: addiu       $a0, $a0, 0x6140
    ctx->r4 = ADD32(ctx->r4, 0X6140);
    after_1:
    // 0x800B9730: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B9734: lui         $a1, 0x76
    ctx->r5 = S32(0X76 << 16);
    // 0x800B9738: jal         0x800C83E4
    // 0x800B973C: addiu       $a1, $a1, -0x69F0
    ctx->r5 = ADD32(ctx->r5, -0X69F0);
    alBnkfNew(rdram, ctx);
        goto after_2;
    // 0x800B973C: addiu       $a1, $a1, -0x69F0
    ctx->r5 = ADD32(ctx->r5, -0X69F0);
    after_2:
    // 0x800B9740: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B9744: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9748: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800B974C: nop

    // 0x800B9750: sw          $t1, -0x17E8($at)
    MEM_W(-0X17E8, ctx->r1) = ctx->r9;
    // 0x800B9754: lui         $t2, 0x79
    ctx->r10 = S32(0X79 << 16);
    // 0x800B9758: lui         $t3, 0x78
    ctx->r11 = S32(0X78 << 16);
    // 0x800B975C: addiu       $t3, $t3, 0x5F70
    ctx->r11 = ADD32(ctx->r11, 0X5F70);
    // 0x800B9760: addiu       $t2, $t2, -0x5490
    ctx->r10 = ADD32(ctx->r10, -0X5490);
    // 0x800B9764: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800B9768: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B976C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B9770: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9774: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9778: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B977C: addiu       $a0, $a0, -0x360
    ctx->r4 = ADD32(ctx->r4, -0X360);
    // 0x800B9780: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    // 0x800B9784: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B9788: jal         0x800C7950
    // 0x800B978C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800B978C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800B9790: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B9794: lui         $a0, 0x78
    ctx->r4 = S32(0X78 << 16);
    // 0x800B9798: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B979C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B97A0: jal         0x800BC590
    // 0x800B97A4: addiu       $a0, $a0, 0x5F70
    ctx->r4 = ADD32(ctx->r4, 0X5F70);
    AudioDmaCopy(rdram, ctx);
        goto after_4;
    // 0x800B97A4: addiu       $a0, $a0, 0x5F70
    ctx->r4 = ADD32(ctx->r4, 0X5F70);
    after_4:
    // 0x800B97A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B97AC: lui         $a1, 0x79
    ctx->r5 = S32(0X79 << 16);
    // 0x800B97B0: jal         0x800C83E4
    // 0x800B97B4: addiu       $a1, $a1, -0x5490
    ctx->r5 = ADD32(ctx->r5, -0X5490);
    alBnkfNew(rdram, ctx);
        goto after_5;
    // 0x800B97B4: addiu       $a1, $a1, -0x5490
    ctx->r5 = ADD32(ctx->r5, -0X5490);
    after_5:
    // 0x800B97B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B97BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B97C0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B97C4: nop

    // 0x800B97C8: sw          $t7, -0x17E4($at)
    MEM_W(-0X17E4, ctx->r1) = ctx->r15;
    // 0x800B97CC: b           L_800B97D4
    // 0x800B97D0: nop

        goto L_800B97D4;
    // 0x800B97D0: nop

L_800B97D4:
    // 0x800B97D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B97D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B97DC: jr          $ra
    // 0x800B97E0: nop

    return;
    // 0x800B97E0: nop

;}
RECOMP_FUNC void func_80086A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086A9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80086AA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086AA4: jal         0x8008B4EC
    // 0x80086AA8: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086AA8: nop

    after_0:
    // 0x80086AAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086AB0: jal         0x8008B600
    // 0x80086AB4: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086AB4: nop

    after_1:
    // 0x80086AB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80086AC0: jal         0x8008B738
    // 0x80086AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80086AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80086AC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80086ACC: jal         0x8008A518
    // 0x80086AD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80086AD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80086AD4: beq         $v0, $zero, L_80086B6C
    if (ctx->r2 == 0) {
        // 0x80086AD8: nop
    
            goto L_80086B6C;
    }
    // 0x80086AD8: nop

    // 0x80086ADC: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086AE0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086AE4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086AE8: bne         $at, $zero, L_80086B6C
    if (ctx->r1 != 0) {
        // 0x80086AEC: nop
    
            goto L_80086B6C;
    }
    // 0x80086AEC: nop

    // 0x80086AF0: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80086AF4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086AF8: beq         $at, $zero, L_80086B6C
    if (ctx->r1 == 0) {
        // 0x80086AFC: nop
    
            goto L_80086B6C;
    }
    // 0x80086AFC: nop

    // 0x80086B00: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086B04: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086B08: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086B0C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086B10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086B14: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086B18: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086B1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80086B20: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086B24: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80086B28: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80086B2C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80086B30: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80086B34: nop

    // 0x80086B38: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086B3C: nop

    // 0x80086B40: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086B44: beq         $t4, $zero, L_80086B6C
    if (ctx->r12 == 0) {
        // 0x80086B48: nop
    
            goto L_80086B6C;
    }
    // 0x80086B48: nop

    // 0x80086B4C: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80086B50: beq         $t5, $zero, L_80086B6C
    if (ctx->r13 == 0) {
        // 0x80086B54: nop
    
            goto L_80086B6C;
    }
    // 0x80086B54: nop

    // 0x80086B58: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80086B5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086B60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086B64: jal         0x8008B738
    // 0x80086B68: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80086B68: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_4:
L_80086B6C:
    // 0x80086B6C: b           L_80086B74
    // 0x80086B70: nop

        goto L_80086B74;
    // 0x80086B70: nop

L_80086B74:
    // 0x80086B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086B7C: jr          $ra
    // 0x80086B80: nop

    return;
    // 0x80086B80: nop

;}
RECOMP_FUNC void func_800B6E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6E04: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B6E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B6E0C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800B6E10: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800B6E14: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800B6E18: nop

    // 0x800B6E1C: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B6E20: nop

    // 0x800B6E24: bne         $t7, $zero, L_800B6E34
    if (ctx->r15 != 0) {
        // 0x800B6E28: nop
    
            goto L_800B6E34;
    }
    // 0x800B6E28: nop

    // 0x800B6E2C: b           L_800B73CC
    // 0x800B6E30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B73CC;
    // 0x800B6E30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6E34:
    // 0x800B6E34: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800B6E38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B6E3C: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x800B6E40: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B6E44: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B6E48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B6E4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B6E50: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B6E54: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B6E58: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B6E5C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800B6E60: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B6E64: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800B6E68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B6E6C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B6E70: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800B6E74: nop

    // 0x800B6E78: bc1f        L_800B6E94
    if (!c1cs) {
        // 0x800B6E7C: nop
    
            goto L_800B6E94;
    }
    // 0x800B6E7C: nop

    // 0x800B6E80: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800B6E84: nop

    // 0x800B6E88: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x800B6E8C: b           L_800B6EB4
    // 0x800B6E90: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
        goto L_800B6EB4;
    // 0x800B6E90: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
L_800B6E94:
    // 0x800B6E94: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B6E98: nop

    // 0x800B6E9C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800B6EA0: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800B6EA4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800B6EA8: nop

    // 0x800B6EAC: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x800B6EB0: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
L_800B6EB4:
    // 0x800B6EB4: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800B6EB8: nop

    // 0x800B6EBC: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800B6EC0: nop

    // 0x800B6EC4: bne         $t5, $zero, L_800B7298
    if (ctx->r13 != 0) {
        // 0x800B6EC8: nop
    
            goto L_800B7298;
    }
    // 0x800B6EC8: nop

    // 0x800B6ECC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800B6ED0: nop

    // 0x800B6ED4: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x800B6ED8: jal         0x8000D688
    // 0x800B6EDC: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B6EDC: nop

    after_0:
    // 0x800B6EE0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B6EE4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800B6EE8: nop

    // 0x800B6EEC: bne         $t7, $zero, L_800B6EFC
    if (ctx->r15 != 0) {
        // 0x800B6EF0: nop
    
            goto L_800B6EFC;
    }
    // 0x800B6EF0: nop

    // 0x800B6EF4: b           L_800B73CC
    // 0x800B6EF8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800B73CC;
    // 0x800B6EF8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800B6EFC:
    // 0x800B6EFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800B6F00: nop

    // 0x800B6F04: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x800B6F08: nop

    // 0x800B6F0C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B6F10: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6F14: nop

    // 0x800B6F18: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800B6F1C: nop

    // 0x800B6F20: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800B6F24: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800B6F28: nop

    // 0x800B6F2C: lhu         $t3, 0xA($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XA);
    // 0x800B6F30: nop

    // 0x800B6F34: bne         $t3, $zero, L_800B6F64
    if (ctx->r11 != 0) {
        // 0x800B6F38: nop
    
            goto L_800B6F64;
    }
    // 0x800B6F38: nop

    // 0x800B6F3C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B6F40: nop

    // 0x800B6F44: lwc1        $f18, 0xCC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B6F48: nop

    // 0x800B6F4C: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800B6F50: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B6F54: nop

    // 0x800B6F58: lwc1        $f4, 0xD0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x800B6F5C: b           L_800B7290
    // 0x800B6F60: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
        goto L_800B7290;
    // 0x800B6F60: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_800B6F64:
    // 0x800B6F64: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x800B6F68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B6F6C: nop

    // 0x800B6F70: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800B6F74: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x800B6F78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6F7C: nop

    // 0x800B6F80: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800B6F84: lui         $at, 0xC30C
    ctx->r1 = S32(0XC30C << 16);
    // 0x800B6F88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B6F8C: nop

    // 0x800B6F90: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800B6F94: lui         $at, 0xC2E0
    ctx->r1 = S32(0XC2E0 << 16);
    // 0x800B6F98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B6F9C: nop

    // 0x800B6FA0: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800B6FA4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B6FA8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6FAC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B6FB0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800B6FB4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800B6FB8: nop

    // 0x800B6FBC: blez        $t8, L_800B7104
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B6FC0: nop
    
            goto L_800B7104;
    }
    // 0x800B6FC0: nop

L_800B6FC4:
    // 0x800B6FC4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800B6FC8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B6FCC: lw          $t0, 0x104($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X104);
    // 0x800B6FD0: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800B6FD4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B6FD8: nop

    // 0x800B6FDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B6FE0: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B6FE4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800B6FE8: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800B6FEC: bc1f        L_800B7000
    if (!c1cs) {
        // 0x800B6FF0: nop
    
            goto L_800B7000;
    }
    // 0x800B6FF0: nop

    // 0x800B6FF4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B6FF8: nop

    // 0x800B6FFC: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
L_800B7000:
    // 0x800B7000: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7004: nop

    // 0x800B7008: lw          $t2, 0x108($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X108);
    // 0x800B700C: lh          $t3, 0x102($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X102);
    // 0x800B7010: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800B7014: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800B7018: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B701C: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x800B7020: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B7024: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7028: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B702C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800B7030: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800B7034: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x800B7038: bc1f        L_800B704C
    if (!c1cs) {
        // 0x800B703C: nop
    
            goto L_800B704C;
    }
    // 0x800B703C: nop

    // 0x800B7040: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B7044: nop

    // 0x800B7048: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_800B704C:
    // 0x800B704C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B7050: nop

    // 0x800B7054: lw          $t5, 0x104($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X104);
    // 0x800B7058: lh          $t6, 0x100($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X100);
    // 0x800B705C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B7060: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B7064: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B7068: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B706C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7070: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B7074: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B7078: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B707C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800B7080: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800B7084: bc1f        L_800B7098
    if (!c1cs) {
        // 0x800B7088: nop
    
            goto L_800B7098;
    }
    // 0x800B7088: nop

    // 0x800B708C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B7090: nop

    // 0x800B7094: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
L_800B7098:
    // 0x800B7098: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B709C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B70A0: lw          $t8, 0x108($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X108);
    // 0x800B70A4: lwc1        $f4, 0xD0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x800B70A8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800B70AC: nop

    // 0x800B70B0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B70B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B70B8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800B70BC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800B70C0: bc1f        L_800B70D4
    if (!c1cs) {
        // 0x800B70C4: nop
    
            goto L_800B70D4;
    }
    // 0x800B70C4: nop

    // 0x800B70C8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B70CC: nop

    // 0x800B70D0: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
L_800B70D4:
    // 0x800B70D4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800B70D8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B70DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B70E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B70E4: addiu       $t1, $t2, 0x160
    ctx->r9 = ADD32(ctx->r10, 0X160);
    // 0x800B70E8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800B70EC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800B70F0: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x800B70F4: nop

    // 0x800B70F8: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B70FC: bne         $at, $zero, L_800B6FC4
    if (ctx->r1 != 0) {
        // 0x800B7100: nop
    
            goto L_800B6FC4;
    }
    // 0x800B7100: nop

L_800B7104:
    // 0x800B7104: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B7108: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B710C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800B7110: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B7114: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B711C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B7120: nop

    // 0x800B7124: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800B7128: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B712C: nop

    // 0x800B7130: lwc1        $f18, 0xF4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x800B7134: nop

    // 0x800B7138: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B713C: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800B7140: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B7144: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800B7148: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B714C: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B7150: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800B7154: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800B7158: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B715C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B7160: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800B7164: nop

    // 0x800B7168: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800B716C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B7170: nop

    // 0x800B7174: lwc1        $f10, 0xF8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XF8);
    // 0x800B7178: nop

    // 0x800B717C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800B7180: mul.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x800B7184: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800B7188: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800B718C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B7190: nop

    // 0x800B7194: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800B7198: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B719C: nop

    // 0x800B71A0: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800B71A4: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800B71A8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800B71AC: lhu         $t8, 0xA($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XA);
    // 0x800B71B0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B71B4: subu        $t2, $t9, $t8
    ctx->r10 = SUB32(ctx->r25, ctx->r24);
    // 0x800B71B8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800B71BC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B71C0: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B71C4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B71C8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B71CC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800B71D0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800B71D4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800B71D8: lhu         $t3, 0xA($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0XA);
    // 0x800B71DC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B71E0: subu        $t5, $t0, $t3
    ctx->r13 = SUB32(ctx->r8, ctx->r11);
    // 0x800B71E4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B71E8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B71EC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B71F0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B71F4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B71F8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800B71FC: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800B7200: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800B7204: lhu         $t6, 0xA($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0XA);
    // 0x800B7208: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B720C: subu        $t9, $t7, $t6
    ctx->r25 = SUB32(ctx->r15, ctx->r14);
    // 0x800B7210: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800B7214: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B7218: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B721C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B7220: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7224: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800B7228: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800B722C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x800B7230: lhu         $t2, 0xA($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0XA);
    // 0x800B7234: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B7238: subu        $t0, $t1, $t2
    ctx->r8 = SUB32(ctx->r9, ctx->r10);
    // 0x800B723C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800B7240: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B7244: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B7248: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B724C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7250: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800B7254: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B7258: nop

    // 0x800B725C: lwc1        $f8, 0xCC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x800B7260: nop

    // 0x800B7264: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800B7268: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B726C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B7270: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B7274: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800B7278: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B727C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7280: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B7284: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800B7288: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x800B728C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_800B7290:
    // 0x800B7290: b           L_800B72D8
    // 0x800B7294: nop

        goto L_800B72D8;
    // 0x800B7294: nop

L_800B7298:
    // 0x800B7298: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800B729C: nop

    // 0x800B72A0: lh          $t4, 0x8($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X8);
    // 0x800B72A4: nop

    // 0x800B72A8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800B72AC: nop

    // 0x800B72B0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B72B4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x800B72B8: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800B72BC: nop

    // 0x800B72C0: lh          $t6, 0xA($t7)
    ctx->r14 = MEM_H(ctx->r15, 0XA);
    // 0x800B72C4: nop

    // 0x800B72C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800B72CC: nop

    // 0x800B72D0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B72D4: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
L_800B72D8:
    // 0x800B72D8: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x800B72DC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B72E0: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B72E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B72E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B72EC: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800B72F0: lwc1        $f7, -0x5A8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5A8);
    // 0x800B72F4: lwc1        $f6, -0x5A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A4);
    // 0x800B72F8: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x800B72FC: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x800B7300: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800B7304: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800B7308: lui         $at, 0xC02C
    ctx->r1 = S32(0XC02C << 16);
    // 0x800B730C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B7310: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B7314: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B7318: lui         $at, 0x405C
    ctx->r1 = S32(0X405C << 16);
    // 0x800B731C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800B7320: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7324: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7328: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x800B732C: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800B7330: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x800B7334: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800B7338: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800B733C: nop

    // 0x800B7340: lhu         $t8, 0xC($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0XC);
    // 0x800B7344: nop

    // 0x800B7348: beq         $t8, $zero, L_800B735C
    if (ctx->r24 == 0) {
        // 0x800B734C: nop
    
            goto L_800B735C;
    }
    // 0x800B734C: nop

    // 0x800B7350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7354: bne         $t8, $at, L_800B736C
    if (ctx->r24 != ctx->r1) {
        // 0x800B7358: nop
    
            goto L_800B736C;
    }
    // 0x800B7358: nop

L_800B735C:
    // 0x800B735C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800B7360: nop

    // 0x800B7364: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x800B7368: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
L_800B736C:
    // 0x800B736C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800B7370: nop

    // 0x800B7374: lhu         $t3, 0xC($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0XC);
    // 0x800B7378: nop

    // 0x800B737C: beq         $t3, $zero, L_800B7390
    if (ctx->r11 == 0) {
        // 0x800B7380: nop
    
            goto L_800B7390;
    }
    // 0x800B7380: nop

    // 0x800B7384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B7388: bne         $t3, $at, L_800B73A0
    if (ctx->r11 != ctx->r1) {
        // 0x800B738C: nop
    
            goto L_800B73A0;
    }
    // 0x800B738C: nop

L_800B7390:
    // 0x800B7390: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800B7394: nop

    // 0x800B7398: ori         $t4, $t5, 0x2
    ctx->r12 = ctx->r13 | 0X2;
    // 0x800B739C: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_800B73A0:
    // 0x800B73A0: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B73A4: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B73A8: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800B73AC: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x800B73B0: jal         0x80016BF4
    // 0x800B73B4: nop

    func_80016BF4(rdram, ctx);
        goto after_1;
    // 0x800B73B4: nop

    after_1:
    // 0x800B73B8: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x800B73BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B73C0: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
    // 0x800B73C4: b           L_800B73CC
    // 0x800B73C8: nop

        goto L_800B73CC;
    // 0x800B73C8: nop

L_800B73CC:
    // 0x800B73CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B73D0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800B73D4: jr          $ra
    // 0x800B73D8: nop

    return;
    // 0x800B73D8: nop

;}
RECOMP_FUNC void AudioDriver_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9580: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B9584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9588: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B958C: sw          $zero, -0x17AC($at)
    MEM_W(-0X17AC, ctx->r1) = 0;
    // 0x800B9590: jal         0x800B96D4
    // 0x800B9594: nop

    AudioDriver_LoadBanks(rdram, ctx);
        goto after_0;
    // 0x800B9594: nop

    after_0:
    // 0x800B9598: jal         0x800B95D0
    // 0x800B959C: nop

    AudioDriver_LoadSequences(rdram, ctx);
        goto after_1;
    // 0x800B959C: nop

    after_1:
    // 0x800B95A0: jal         0x800B9890
    // 0x800B95A4: nop

    AudioDriver_InitSeqPlayer(rdram, ctx);
        goto after_2;
    // 0x800B95A4: nop

    after_2:
    // 0x800B95A8: jal         0x800B9C74
    // 0x800B95AC: nop

    AudioDriver_InitSoundPlayer(rdram, ctx);
        goto after_3;
    // 0x800B95AC: nop

    after_3:
    // 0x800B95B0: jal         0x800B9CEC
    // 0x800B95B4: nop

    func_800B9CEC(rdram, ctx);
        goto after_4;
    // 0x800B95B4: nop

    after_4:
    // 0x800B95B8: b           L_800B95C0
    // 0x800B95BC: nop

        goto L_800B95C0;
    // 0x800B95BC: nop

L_800B95C0:
    // 0x800B95C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B95C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B95C8: jr          $ra
    // 0x800B95CC: nop

    return;
    // 0x800B95CC: nop

;}
RECOMP_FUNC void func_800B7FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7FCC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B7FD0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800B7FD4:
    // 0x800B7FD4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800B7FD8: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7FDC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B7FE0: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B7FE4: sh          $t6, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r14;
    // 0x800B7FE8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7FEC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B7FF0: nop

    // 0x800B7FF4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B7FF8: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x800B7FFC: bne         $at, $zero, L_800B7FD4
    if (ctx->r1 != 0) {
        // 0x800B8000: sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
            goto L_800B7FD4;
    }
    // 0x800B8000: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800B8004: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B8008: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x800B800C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x800B8010: lw          $t2, 0x718C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X718C);
    // 0x800B8014: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B8018: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800B801C: sw          $t5, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r13;
    // 0x800B8020: b           L_800B8030
    // 0x800B8024: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B8030;
    // 0x800B8024: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B8028: b           L_800B8030
    // 0x800B802C: nop

        goto L_800B8030;
    // 0x800B802C: nop

L_800B8030:
    // 0x800B8030: jr          $ra
    // 0x800B8034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B8034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006EF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EF58: jal         0x80061348
    // 0x8006EF5C: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EF5C: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    after_0:
    // 0x8006EF60: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EF64: b           L_8006EF74
    // 0x8006EF68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EF74;
    // 0x8006EF68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EF6C: b           L_8006EF74
    // 0x8006EF70: nop

        goto L_8006EF74;
    // 0x8006EF70: nop

L_8006EF74:
    // 0x8006EF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EF7C: jr          $ra
    // 0x8006EF80: nop

    return;
    // 0x8006EF80: nop

;}
RECOMP_FUNC void func_80075758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075758: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007575C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075760: nop

    // 0x80075764: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075768: nop

    // 0x8007576C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075770: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075774: jr          $ra
    // 0x80075778: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075778: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007577C: jr          $ra
    // 0x80075780: nop

    return;
    // 0x80075780: nop

    // 0x80075784: jr          $ra
    // 0x80075788: nop

    return;
    // 0x80075788: nop

;}
RECOMP_FUNC void func_8001AD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AD24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001AD28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AD2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001AD30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001AD34: jal         0x80016074
    // 0x8001AD38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x8001AD38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001AD3C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001AD40: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AD44: nop

    // 0x8001AD48: bne         $t6, $zero, L_8001AD58
    if (ctx->r14 != 0) {
        // 0x8001AD4C: nop
    
            goto L_8001AD58;
    }
    // 0x8001AD4C: nop

    // 0x8001AD50: b           L_8001AD88
    // 0x8001AD54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001AD88;
    // 0x8001AD54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001AD58:
    // 0x8001AD58: lhu         $t7, 0x22($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X22);
    // 0x8001AD5C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AD60: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001AD64: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x8001AD68: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001AD6C: sra         $t9, $t7, 15
    ctx->r25 = S32(SIGNED(ctx->r15) >> 15);
    // 0x8001AD70: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8001AD74: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x8001AD78: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8001AD7C: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    // 0x8001AD80: b           L_8001AD88
    // 0x8001AD84: nop

        goto L_8001AD88;
    // 0x8001AD84: nop

L_8001AD88:
    // 0x8001AD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AD8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AD90: jr          $ra
    // 0x8001AD94: nop

    return;
    // 0x8001AD94: nop

;}
RECOMP_FUNC void func_800BCB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCB14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCB18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BCB1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BCB20: jal         0x800BCCE4
    // 0x800BCB24: nop

    func_800BCCE4(rdram, ctx);
        goto after_0;
    // 0x800BCB24: nop

    after_0:
    // 0x800BCB28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BCB2C: jal         0x800BC980
    // 0x800BCB30: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800BCB30: nop

    after_1:
    // 0x800BCB34: b           L_800BCB44
    // 0x800BCB38: nop

        goto L_800BCB44;
    // 0x800BCB38: nop

    // 0x800BCB3C: b           L_800BCB44
    // 0x800BCB40: nop

        goto L_800BCB44;
    // 0x800BCB40: nop

L_800BCB44:
    // 0x800BCB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCB48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BCB4C: jr          $ra
    // 0x800BCB50: nop

    return;
    // 0x800BCB50: nop

;}
RECOMP_FUNC void Thread_Start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0C94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0C98: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C9C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0CA0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0CA4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0CA8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0CAC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0CB0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0CB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0CB8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0CBC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0CC0: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0CC4: nop

    // 0x800C0CC8: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0CCC: bne         $t9, $zero, L_800C0CDC
    if (ctx->r25 != 0) {
        // 0x800C0CD0: nop
    
            goto L_800C0CDC;
    }
    // 0x800C0CD0: nop

    // 0x800C0CD4: b           L_800C0D24
    // 0x800C0CD8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0D24;
    // 0x800C0CD8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0CDC:
    // 0x800C0CDC: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0CE0: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0CE4: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C0CE8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0CEC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C0CF0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0CF4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C0CF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0CFC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C0D00: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C0D04: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C0D08: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C0D0C: jal         0x800C4950
    // 0x800C0D10: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0D10: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C0D14: b           L_800C0D24
    // 0x800C0D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0D24;
    // 0x800C0D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0D1C: b           L_800C0D24
    // 0x800C0D20: nop

        goto L_800C0D24;
    // 0x800C0D20: nop

L_800C0D24:
    // 0x800C0D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0D2C: jr          $ra
    // 0x800C0D30: nop

    return;
    // 0x800C0D30: nop

;}
RECOMP_FUNC void func_80073400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073408: jal         0x80061488
    // 0x8007340C: addiu       $a0, $zero, 0x63E
    ctx->r4 = ADD32(0, 0X63E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007340C: addiu       $a0, $zero, 0x63E
    ctx->r4 = ADD32(0, 0X63E);
    after_0:
    // 0x80073410: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073414: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073418: b           L_80073428
    // 0x8007341C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073428;
    // 0x8007341C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073420: b           L_80073428
    // 0x80073424: nop

        goto L_80073428;
    // 0x80073424: nop

L_80073428:
    // 0x80073428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007342C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073430: jr          $ra
    // 0x80073434: nop

    return;
    // 0x80073434: nop

;}
RECOMP_FUNC void func_8006B7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B7AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B7B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B7B4: jal         0x80061488
    // 0x8006B7B8: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B7B8: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    after_0:
    // 0x8006B7BC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006B7C0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B7C4: b           L_8006B7D4
    // 0x8006B7C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006B7D4;
    // 0x8006B7C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B7CC: b           L_8006B7D4
    // 0x8006B7D0: nop

        goto L_8006B7D4;
    // 0x8006B7D0: nop

L_8006B7D4:
    // 0x8006B7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B7D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B7DC: jr          $ra
    // 0x8006B7E0: nop

    return;
    // 0x8006B7E0: nop

;}
RECOMP_FUNC void func_80067C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067C68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067C6C: nop

    // 0x80067C70: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80067C74: nop

    // 0x80067C78: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067C7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067C80: jr          $ra
    // 0x80067C84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067C84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067C88: jr          $ra
    // 0x80067C8C: nop

    return;
    // 0x80067C8C: nop

    // 0x80067C90: jr          $ra
    // 0x80067C94: nop

    return;
    // 0x80067C94: nop

;}
RECOMP_FUNC void SysMem_Copy16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD038: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD03C: bne         $a2, $zero, L_800BD04C
    if (ctx->r6 != 0) {
        // 0x800BD040: nop
    
            goto L_800BD04C;
    }
    // 0x800BD040: nop

    // 0x800BD044: b           L_800BD09C
    // 0x800BD048: nop

        goto L_800BD09C;
    // 0x800BD048: nop

L_800BD04C:
    // 0x800BD04C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BD050: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BD054: blez        $a2, L_800BD094
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BD058: nop
    
            goto L_800BD094;
    }
    // 0x800BD058: nop

L_800BD05C:
    // 0x800BD05C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BD060: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BD064: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800BD068: nop

    // 0x800BD06C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800BD070: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800BD074: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800BD078: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800BD07C: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x800BD080: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800BD084: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800BD088: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD08C: bgtz        $a2, L_800BD05C
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD090: nop
    
            goto L_800BD05C;
    }
    // 0x800BD090: nop

L_800BD094:
    // 0x800BD094: b           L_800BD09C
    // 0x800BD098: nop

        goto L_800BD09C;
    // 0x800BD098: nop

L_800BD09C:
    // 0x800BD09C: jr          $ra
    // 0x800BD0A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD0A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80009F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009F70: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009F74: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80009F78: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80009F7C: nop

    // 0x80009F80: ori         $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 | 0X1000;
    // 0x80009F84: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80009F88: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80009F8C: jr          $ra
    // 0x80009F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009F94: jr          $ra
    // 0x80009F98: nop

    return;
    // 0x80009F98: nop

    // 0x80009F9C: jr          $ra
    // 0x80009FA0: nop

    return;
    // 0x80009FA0: nop

;}
RECOMP_FUNC void func_80067C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067C34: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067C38: nop

    // 0x80067C3C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067C40: nop

    // 0x80067C44: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067C48: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067C4C: jr          $ra
    // 0x80067C50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067C50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067C54: jr          $ra
    // 0x80067C58: nop

    return;
    // 0x80067C58: nop

    // 0x80067C5C: jr          $ra
    // 0x80067C60: nop

    return;
    // 0x80067C60: nop

;}
RECOMP_FUNC void func_8007A488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A48C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007A494: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007A498: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007A49C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4A0: sh          $t6, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r14;
    // 0x8007A4A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A4A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4AC: sh          $t7, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r15;
    // 0x8007A4B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007A4B4: lbu         $a0, 0x1918($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1918);
    // 0x8007A4B8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8007A4BC: addiu       $a1, $a1, -0x820
    ctx->r5 = ADD32(ctx->r5, -0X820);
    // 0x8007A4C0: jal         0x800C1264
    // 0x8007A4C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x8007A4C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007A4C8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A4CC: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007A4D0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8007A4D4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007A4D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4DC: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007A4E0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007A4E4: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007A4E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A4EC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8007A4F0: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007A4F4: b           L_8007A504
    // 0x8007A4F8: nop

        goto L_8007A504;
    // 0x8007A4F8: nop

    // 0x8007A4FC: b           L_8007A504
    // 0x8007A500: nop

        goto L_8007A504;
    // 0x8007A500: nop

L_8007A504:
    // 0x8007A504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A50C: jr          $ra
    // 0x8007A510: nop

    return;
    // 0x8007A510: nop

;}
RECOMP_FUNC void func_80068780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068780: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068784: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068788: nop

    // 0x8006878C: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068790: nop

    // 0x80068794: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068798: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006879C: jr          $ra
    // 0x800687A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800687A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800687A4: jr          $ra
    // 0x800687A8: nop

    return;
    // 0x800687A8: nop

    // 0x800687AC: jr          $ra
    // 0x800687B0: nop

    return;
    // 0x800687B0: nop

;}
RECOMP_FUNC void func_8006D1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D1C4: jal         0x8005F064
    // 0x8006D1C8: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D1C8: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x8006D1CC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D1D0: b           L_8006D1E0
    // 0x8006D1D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D1E0;
    // 0x8006D1D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D1D8: b           L_8006D1E0
    // 0x8006D1DC: nop

        goto L_8006D1E0;
    // 0x8006D1DC: nop

L_8006D1E0:
    // 0x8006D1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D1E8: jr          $ra
    // 0x8006D1EC: nop

    return;
    // 0x8006D1EC: nop

;}
RECOMP_FUNC void func_8006E8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E8B8: jal         0x80061348
    // 0x8006E8BC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E8BC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E8C0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E8C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E8C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E8CC: beq         $v0, $zero, L_8006E8E4
    if (ctx->r2 == 0) {
        // 0x8006E8D0: nop
    
            goto L_8006E8E4;
    }
    // 0x8006E8D0: nop

    // 0x8006E8D4: jal         0x80061348
    // 0x8006E8D8: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E8D8: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_1:
    // 0x8006E8DC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E8E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E8E4:
    // 0x8006E8E4: b           L_8006E8F4
    // 0x8006E8E8: nop

        goto L_8006E8F4;
    // 0x8006E8E8: nop

    // 0x8006E8EC: b           L_8006E8F4
    // 0x8006E8F0: nop

        goto L_8006E8F4;
    // 0x8006E8F0: nop

L_8006E8F4:
    // 0x8006E8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E8F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E8FC: jr          $ra
    // 0x8006E900: nop

    return;
    // 0x8006E900: nop

;}
RECOMP_FUNC void func_80049230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80049234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049238: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004923C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80049240: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80049244: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80049248: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8004924C: nop

    // 0x80049250: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80049254: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80049258: lbu         $t8, 0x1040($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1040);
    // 0x8004925C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80049260: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80049264: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
    // 0x80049268: beq         $t9, $zero, L_800492A8
    if (ctx->r25 == 0) {
        // 0x8004926C: sw          $zero, 0x20($sp)
        MEM_W(0X20, ctx->r29) = 0;
            goto L_800492A8;
    }
    // 0x8004926C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80049270:
    // 0x80049270: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80049274: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80049278: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004927C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80049280: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80049284: sb          $t3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r11;
    // 0x80049288: beq         $at, $zero, L_800492A8
    if (ctx->r1 == 0) {
        // 0x8004928C: sw          $t1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r9;
            goto L_800492A8;
    }
    // 0x8004928C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80049290: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80049294: lbu         $t4, 0x1040($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1040);
    // 0x80049298: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8004929C: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x800492A0: bne         $t6, $zero, L_80049270
    if (ctx->r14 != 0) {
        // 0x800492A4: nop
    
            goto L_80049270;
    }
    // 0x800492A4: nop

L_800492A8:
    // 0x800492A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800492AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800492B0: bne         $t7, $at, L_800492C0
    if (ctx->r15 != ctx->r1) {
        // 0x800492B4: nop
    
            goto L_800492C0;
    }
    // 0x800492B4: nop

    // 0x800492B8: b           L_80049428
    // 0x800492BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80049428;
    // 0x800492BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800492C0:
    // 0x800492C0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800492C4: lbu         $t8, 0x1040($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1040);
    // 0x800492C8: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x800492CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800492D0: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800492D4: sb          $t0, 0x1040($at)
    MEM_B(0X1040, ctx->r1) = ctx->r8;
    // 0x800492D8: jal         0x800BC6EC
    // 0x800492DC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800492DC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x800492E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800492E4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800492E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800492EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800492F0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800492F4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800492F8: sw          $t2, 0x1028($at)
    MEM_W(0X1028, ctx->r1) = ctx->r10;
    // 0x800492FC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80049300: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80049304: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x80049308: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004930C: jal         0x800C0640
    // 0x80049310: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    Thread_CreateSimple(rdram, ctx);
        goto after_1;
    // 0x80049310: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_1:
    // 0x80049314: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80049318: nop

    // 0x8004931C: sb          $v0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r2;
    // 0x80049320: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80049324: nop

    // 0x80049328: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8004932C: jal         0x800C0988
    // 0x80049330: nop

    func_800C0988(rdram, ctx);
        goto after_2;
    // 0x80049330: nop

    after_2:
    // 0x80049334: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80049338: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8004933C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80049340: nop

    // 0x80049344: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80049348: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8004934C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80049350: nop

    // 0x80049354: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80049358: jal         0x800C0E04
    // 0x8004935C: nop

    Thread_GetPtr(rdram, ctx);
        goto after_3;
    // 0x8004935C: nop

    after_3:
    // 0x80049360: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80049364: nop

    // 0x80049368: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
    // 0x8004936C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80049370: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80049374: nop

    // 0x80049378: sw          $t3, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r11;
    // 0x8004937C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80049380: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80049384: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80049388: nop

    // 0x8004938C: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x80049390: sh          $t5, 0x2F1($at)
    MEM_H(0X2F1, ctx->r1) = ctx->r13;
    // 0x80049394: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80049398: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8004939C: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800493A0: nop

    // 0x800493A4: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x800493A8: sh          $t8, 0x2F3($at)
    MEM_H(0X2F3, ctx->r1) = ctx->r24;
    // 0x800493AC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800493B0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800493B4: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x800493B8: nop

    // 0x800493BC: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x800493C0: sh          $t1, 0x2F5($at)
    MEM_H(0X2F5, ctx->r1) = ctx->r9;
    // 0x800493C4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800493C8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800493CC: lw          $t5, 0x18($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X18);
    // 0x800493D0: nop

    // 0x800493D4: addiu       $at, $t5, 0x7FFF
    ctx->r1 = ADD32(ctx->r13, 0X7FFF);
    // 0x800493D8: sh          $t4, 0x2F7($at)
    MEM_H(0X2F7, ctx->r1) = ctx->r12;
    // 0x800493DC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800493E0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800493E4: lw          $t8, 0x18($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X18);
    // 0x800493E8: nop

    // 0x800493EC: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x800493F0: sw          $t7, 0x2F9($at)
    MEM_W(0X2F9, ctx->r1) = ctx->r15;
    // 0x800493F4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800493F8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800493FC: nop

    // 0x80049400: sw          $t0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r8;
    // 0x80049404: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80049408: nop

    // 0x8004940C: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80049410: jal         0x800C0C8C
    // 0x80049414: nop

    Thread_Start(rdram, ctx);
        goto after_4;
    // 0x80049414: nop

    after_4:
    // 0x80049418: b           L_80049428
    // 0x8004941C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80049428;
    // 0x8004941C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049420: b           L_80049428
    // 0x80049424: nop

        goto L_80049428;
    // 0x80049424: nop

L_80049428:
    // 0x80049428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004942C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80049430: jr          $ra
    // 0x80049434: nop

    return;
    // 0x80049434: nop

;}
RECOMP_FUNC void func_80072FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072FB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072FBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072FC0: nop

    // 0x80072FC4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072FC8: nop

    // 0x80072FCC: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072FD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072FD4: jr          $ra
    // 0x80072FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072FDC: jr          $ra
    // 0x80072FE0: nop

    return;
    // 0x80072FE0: nop

    // 0x80072FE4: jr          $ra
    // 0x80072FE8: nop

    return;
    // 0x80072FE8: nop

;}
RECOMP_FUNC void func_80063584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063584: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063588: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006358C: nop

    // 0x80063590: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80063594: nop

    // 0x80063598: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006359C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800635A0: jr          $ra
    // 0x800635A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800635A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800635A8: jr          $ra
    // 0x800635AC: nop

    return;
    // 0x800635AC: nop

    // 0x800635B0: jr          $ra
    // 0x800635B4: nop

    return;
    // 0x800635B4: nop

;}
RECOMP_FUNC void func_80017B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017B80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80017B84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80017B88: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80017B8C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80017B90: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017B94: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80017B98: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017B9C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80017BA0: jal         0x80016074
    // 0x80017BA4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80017BA4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x80017BA8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80017BAC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BB0: nop

    // 0x80017BB4: bne         $t6, $zero, L_80017BC4
    if (ctx->r14 != 0) {
        // 0x80017BB8: nop
    
            goto L_80017BC4;
    }
    // 0x80017BB8: nop

    // 0x80017BBC: b           L_80018364
    // 0x80017BC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80018364;
    // 0x80017BC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017BC4:
    // 0x80017BC4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BC8: nop

    // 0x80017BCC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80017BD0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BD4: nop

    // 0x80017BD8: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x80017BDC: nop

    // 0x80017BE0: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x80017BE4: bne         $t0, $zero, L_80017BF8
    if (ctx->r8 != 0) {
        // 0x80017BE8: nop
    
            goto L_80017BF8;
    }
    // 0x80017BE8: nop

    // 0x80017BEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80017BF0: jal         0x800198F8
    // 0x80017BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800198F8(rdram, ctx);
        goto after_1;
    // 0x80017BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80017BF8:
    // 0x80017BF8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BFC: nop

    // 0x80017C00: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x80017C04: nop

    // 0x80017C08: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80017C0C: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x80017C10: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C14: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x80017C18: lw          $t5, 0x1A8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A8);
    // 0x80017C1C: nop

    // 0x80017C20: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80017C24: sw          $t6, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r14;
    // 0x80017C28: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80017C2C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C30: nop

    // 0x80017C34: sw          $t7, 0x1AC($t8)
    MEM_W(0X1AC, ctx->r24) = ctx->r15;
    // 0x80017C38: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017C3C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C40: nop

    // 0x80017C44: swc1        $f4, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f4.u32l;
    // 0x80017C48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80017C4C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C50: nop

    // 0x80017C54: swc1        $f6, 0x1EC($t0)
    MEM_W(0X1EC, ctx->r8) = ctx->f6.u32l;
    // 0x80017C58: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80017C5C: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80017C60: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80017C64: nop

    // 0x80017C68: andi        $t1, $t3, 0x2000
    ctx->r9 = ctx->r11 & 0X2000;
    // 0x80017C6C: beq         $t1, $zero, L_80017CF8
    if (ctx->r9 == 0) {
        // 0x80017C70: nop
    
            goto L_80017CF8;
    }
    // 0x80017C70: nop

    // 0x80017C74: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017C78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017C7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017C80: swc1        $f8, -0x59A0($at)
    MEM_W(-0X59A0, ctx->r1) = ctx->f8.u32l;
    // 0x80017C84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80017C88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017C8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017C90: swc1        $f10, -0x599C($at)
    MEM_W(-0X599C, ctx->r1) = ctx->f10.u32l;
    // 0x80017C94: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017C98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017C9C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CA0: swc1        $f16, -0x5998($at)
    MEM_W(-0X5998, ctx->r1) = ctx->f16.u32l;
    // 0x80017CA4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80017CA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017CAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CB0: swc1        $f18, -0x5994($at)
    MEM_W(-0X5994, ctx->r1) = ctx->f18.u32l;
    // 0x80017CB4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017CB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017CBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CC0: swc1        $f4, -0x5990($at)
    MEM_W(-0X5990, ctx->r1) = ctx->f4.u32l;
    // 0x80017CC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80017CC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017CCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CD0: swc1        $f6, -0x598C($at)
    MEM_W(-0X598C, ctx->r1) = ctx->f6.u32l;
    // 0x80017CD4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017CD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017CDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CE0: swc1        $f8, -0x5988($at)
    MEM_W(-0X5988, ctx->r1) = ctx->f8.u32l;
    // 0x80017CE4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80017CE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017CEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CF0: b           L_80017D78
    // 0x80017CF4: swc1        $f10, -0x5984($at)
    MEM_W(-0X5984, ctx->r1) = ctx->f10.u32l;
        goto L_80017D78;
    // 0x80017CF4: swc1        $f10, -0x5984($at)
    MEM_W(-0X5984, ctx->r1) = ctx->f10.u32l;
L_80017CF8:
    // 0x80017CF8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017CFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017D00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D04: swc1        $f16, -0x59A0($at)
    MEM_W(-0X59A0, ctx->r1) = ctx->f16.u32l;
    // 0x80017D08: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80017D0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017D10: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D14: swc1        $f18, -0x599C($at)
    MEM_W(-0X599C, ctx->r1) = ctx->f18.u32l;
    // 0x80017D18: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017D1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017D20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D24: swc1        $f4, -0x5998($at)
    MEM_W(-0X5998, ctx->r1) = ctx->f4.u32l;
    // 0x80017D28: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80017D2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017D30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D34: swc1        $f6, -0x5994($at)
    MEM_W(-0X5994, ctx->r1) = ctx->f6.u32l;
    // 0x80017D38: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017D3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017D40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D44: swc1        $f8, -0x5990($at)
    MEM_W(-0X5990, ctx->r1) = ctx->f8.u32l;
    // 0x80017D48: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80017D4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017D50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D54: swc1        $f10, -0x598C($at)
    MEM_W(-0X598C, ctx->r1) = ctx->f10.u32l;
    // 0x80017D58: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017D5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017D60: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D64: swc1        $f16, -0x5988($at)
    MEM_W(-0X5988, ctx->r1) = ctx->f16.u32l;
    // 0x80017D68: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80017D6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017D70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D74: swc1        $f18, -0x5984($at)
    MEM_W(-0X5984, ctx->r1) = ctx->f18.u32l;
L_80017D78:
    // 0x80017D78: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80017D7C: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80017D80: addiu       $t6, $t5, 0x618
    ctx->r14 = ADD32(ctx->r13, 0X618);
    // 0x80017D84: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80017D88: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80017D8C: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x80017D90: addiu       $t7, $t4, 0x750
    ctx->r15 = ADD32(ctx->r12, 0X750);
    // 0x80017D94: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80017D98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017D9C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80017DA0: addiu       $t8, $t8, -0x59C0
    ctx->r24 = ADD32(ctx->r24, -0X59C0);
    // 0x80017DA4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80017DA8: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x80017DAC: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x80017DB0: lwc1        $f22, 0xC($t9)
    ctx->f22.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80017DB4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80017DB8: addiu       $t0, $t0, -0x59C0
    ctx->r8 = ADD32(ctx->r8, -0X59C0);
    // 0x80017DBC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80017DC0: swc1        $f22, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f22.u32l;
    // 0x80017DC4: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80017DC8: swc1        $f20, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f20.u32l;
    // 0x80017DCC: addiu       $t2, $t2, -0x59C0
    ctx->r10 = ADD32(ctx->r10, -0X59C0);
    // 0x80017DD0: swc1        $f20, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f20.u32l;
    // 0x80017DD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80017DD8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80017DDC: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x80017DE0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80017DE4: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80017DE8: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
    // 0x80017DEC: lwc1        $f22, 0x1C($t1)
    ctx->f22.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80017DF0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80017DF4: addiu       $t5, $t5, -0x59C0
    ctx->r13 = ADD32(ctx->r13, -0X59C0);
    // 0x80017DF8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80017DFC: swc1        $f22, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f22.u32l;
    // 0x80017E00: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80017E04: swc1        $f20, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f20.u32l;
    // 0x80017E08: addiu       $t6, $t6, -0x59C0
    ctx->r14 = ADD32(ctx->r14, -0X59C0);
    // 0x80017E0C: swc1        $f20, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f20.u32l;
    // 0x80017E10: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017E18: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80017E1C: nop

    // 0x80017E20: swc1        $f8, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f8.u32l;
    // 0x80017E24: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017E2C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80017E30: nop

    // 0x80017E34: swc1        $f10, 0x100($t7)
    MEM_W(0X100, ctx->r15) = ctx->f10.u32l;
    // 0x80017E38: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017E3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017E40: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80017E44: nop

    // 0x80017E48: swc1        $f16, 0xFC($t8)
    MEM_W(0XFC, ctx->r24) = ctx->f16.u32l;
    // 0x80017E4C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017E50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017E54: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80017E58: nop

    // 0x80017E5C: swc1        $f18, 0x104($t9)
    MEM_W(0X104, ctx->r25) = ctx->f18.u32l;
    // 0x80017E60: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017E68: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80017E6C: nop

    // 0x80017E70: swc1        $f4, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f4.u32l;
    // 0x80017E74: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017E7C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80017E80: nop

    // 0x80017E84: swc1        $f6, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->f6.u32l;
    // 0x80017E88: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017E8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017E90: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80017E94: nop

    // 0x80017E98: swc1        $f8, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->f8.u32l;
    // 0x80017E9C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017EA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017EA4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80017EA8: nop

    // 0x80017EAC: swc1        $f10, 0x104($t1)
    MEM_W(0X104, ctx->r9) = ctx->f10.u32l;
    // 0x80017EB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EB4: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80017EB8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80017EBC: nop

    // 0x80017EC0: swc1        $f16, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f16.u32l;
    // 0x80017EC4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EC8: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80017ECC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80017ED0: nop

    // 0x80017ED4: swc1        $f18, 0x114($t6)
    MEM_W(0X114, ctx->r14) = ctx->f18.u32l;
    // 0x80017ED8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EDC: lwc1        $f4, -0x5998($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80017EE0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80017EE4: nop

    // 0x80017EE8: swc1        $f4, 0x118($t4)
    MEM_W(0X118, ctx->r12) = ctx->f4.u32l;
    // 0x80017EEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EF0: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80017EF4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80017EF8: nop

    // 0x80017EFC: swc1        $f6, 0x11C($t7)
    MEM_W(0X11C, ctx->r15) = ctx->f6.u32l;
    // 0x80017F00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F04: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80017F08: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80017F0C: nop

    // 0x80017F10: swc1        $f8, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f8.u32l;
    // 0x80017F14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F18: lwc1        $f10, -0x599C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80017F1C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80017F20: nop

    // 0x80017F24: swc1        $f10, 0x114($t9)
    MEM_W(0X114, ctx->r25) = ctx->f10.u32l;
    // 0x80017F28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F2C: lwc1        $f16, -0x5998($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80017F30: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80017F34: nop

    // 0x80017F38: swc1        $f16, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f16.u32l;
    // 0x80017F3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F40: lwc1        $f18, -0x5994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80017F44: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80017F48: nop

    // 0x80017F4C: swc1        $f18, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f18.u32l;
    // 0x80017F50: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80017F54: nop

    // 0x80017F58: lw          $t1, 0x1AC($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X1AC);
    // 0x80017F5C: nop

    // 0x80017F60: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x80017F64: beq         $at, $zero, L_80018354
    if (ctx->r1 == 0) {
        // 0x80017F68: nop
    
            goto L_80018354;
    }
    // 0x80017F68: nop

    // 0x80017F6C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80017F70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80017F74: addu        $at, $at, $t1
    gpr jr_addend_80017F80 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80017F78: lw          $t1, -0x2A40($at)
    ctx->r9 = ADD32(ctx->r1, -0X2A40);
    // 0x80017F7C: nop

    // 0x80017F80: jr          $t1
    // 0x80017F84: nop

    switch (jr_addend_80017F80 >> 2) {
        case 0: goto L_80018214; break;
        case 1: goto L_80018054; break;
        case 2: goto L_80018054; break;
        case 3: goto L_80018054; break;
        case 4: goto L_800182B4; break;
        case 5: goto L_80018134; break;
        case 6: goto L_80018134; break;
        case 7: goto L_80018134; break;
        case 8: goto L_80017FB4; break;
        case 9: goto L_80017F88; break;
        default: switch_error(__func__, 0x80017F80, 0x800ED5C0);
    }
    // 0x80017F84: nop

L_80017F88:
    // 0x80017F88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017F8C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80017F90: nop

    // 0x80017F94: swc1        $f4, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f4.u32l;
    // 0x80017F98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017F9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017FA0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80017FA4: nop

    // 0x80017FA8: swc1        $f6, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f6.u32l;
    // 0x80017FAC: b           L_80018354
    // 0x80017FB0: nop

        goto L_80018354;
    // 0x80017FB0: nop

L_80017FB4:
    // 0x80017FB4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017FB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017FBC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017FC0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80017FC4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80017FC8: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x80017FCC: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x80017FD0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017FD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017FD8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017FDC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80017FE0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80017FE4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x80017FE8: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x80017FEC: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80017FF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017FF4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017FF8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80017FFC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80018000: addiu       $t8, $t8, -0x59C0
    ctx->r24 = ADD32(ctx->r24, -0X59C0);
    // 0x80018004: swc1        $f16, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f16.u32l;
    // 0x80018008: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x8001800C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018010: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018014: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80018018: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001801C: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x80018020: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x80018024: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018028: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001802C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80018030: nop

    // 0x80018034: swc1        $f8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f8.u32l;
    // 0x80018038: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001803C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018040: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80018044: nop

    // 0x80018048: swc1        $f10, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->f10.u32l;
    // 0x8001804C: b           L_80018354
    // 0x80018050: nop

        goto L_80018354;
    // 0x80018050: nop

L_80018054:
    // 0x80018054: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80018058: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001805C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018060: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018064: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80018068: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001806C: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x80018070: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018074: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018078: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001807C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018080: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80018084: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018088: swc1        $f10, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f10.u32l;
    // 0x8001808C: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80018090: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018094: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80018098: nop

    // 0x8001809C: swc1        $f16, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f16.u32l;
    // 0x800180A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800180A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800180A8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800180AC: nop

    // 0x800180B0: swc1        $f18, 0x100($t6)
    MEM_W(0X100, ctx->r14) = ctx->f18.u32l;
    // 0x800180B4: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x800180B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800180BC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800180C0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800180C4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800180C8: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x800180CC: swc1        $f8, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f8.u32l;
    // 0x800180D0: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x800180D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800180D8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800180DC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800180E0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800180E4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x800180E8: swc1        $f18, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f18.u32l;
    // 0x800180EC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800180F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800180F4: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x800180F8: nop

    // 0x800180FC: bne         $t9, $at, L_8001810C
    if (ctx->r25 != ctx->r1) {
        // 0x80018100: nop
    
            goto L_8001810C;
    }
    // 0x80018100: nop

    // 0x80018104: b           L_80018214
    // 0x80018108: nop

        goto L_80018214;
    // 0x80018108: nop

L_8001810C:
    // 0x8001810C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80018110: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018114: lw          $t2, 0x1AC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1AC);
    // 0x80018118: nop

    // 0x8001811C: bne         $t2, $at, L_8001812C
    if (ctx->r10 != ctx->r1) {
        // 0x80018120: nop
    
            goto L_8001812C;
    }
    // 0x80018120: nop

    // 0x80018124: b           L_800182B4
    // 0x80018128: nop

        goto L_800182B4;
    // 0x80018128: nop

L_8001812C:
    // 0x8001812C: b           L_80018354
    // 0x80018130: nop

        goto L_80018354;
    // 0x80018130: nop

L_80018134:
    // 0x80018134: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018138: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001813C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018140: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018144: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018148: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001814C: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x80018150: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018154: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018158: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001815C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018160: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80018164: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018168: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
    // 0x8001816C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018174: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80018178: nop

    // 0x8001817C: swc1        $f4, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f4.u32l;
    // 0x80018180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018184: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018188: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001818C: nop

    // 0x80018190: swc1        $f6, 0x100($t6)
    MEM_W(0X100, ctx->r14) = ctx->f6.u32l;
    // 0x80018194: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001819C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800181A0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800181A4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800181A8: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x800181AC: swc1        $f16, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f16.u32l;
    // 0x800181B0: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x800181B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800181B8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800181BC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800181C0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800181C4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x800181C8: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x800181CC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800181D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800181D4: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x800181D8: nop

    // 0x800181DC: bne         $t9, $at, L_800181EC
    if (ctx->r25 != ctx->r1) {
        // 0x800181E0: nop
    
            goto L_800181EC;
    }
    // 0x800181E0: nop

    // 0x800181E4: b           L_80018214
    // 0x800181E8: nop

        goto L_80018214;
    // 0x800181E8: nop

L_800181EC:
    // 0x800181EC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800181F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800181F4: lw          $t2, 0x1AC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1AC);
    // 0x800181F8: nop

    // 0x800181FC: bne         $t2, $at, L_8001820C
    if (ctx->r10 != ctx->r1) {
        // 0x80018200: nop
    
            goto L_8001820C;
    }
    // 0x80018200: nop

    // 0x80018204: b           L_800182B4
    // 0x80018208: nop

        goto L_800182B4;
    // 0x80018208: nop

L_8001820C:
    // 0x8001820C: b           L_80018354
    // 0x80018210: nop

        goto L_80018354;
    // 0x80018210: nop

L_80018214:
    // 0x80018214: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018218: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001821C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018220: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018224: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80018228: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001822C: swc1        $f16, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f16.u32l;
    // 0x80018230: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018234: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018238: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001823C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018240: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018244: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018248: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x8001824C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018254: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80018258: nop

    // 0x8001825C: swc1        $f8, 0xFC($t5)
    MEM_W(0XFC, ctx->r13) = ctx->f8.u32l;
    // 0x80018260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018264: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018268: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001826C: nop

    // 0x80018270: swc1        $f10, 0x104($t6)
    MEM_W(0X104, ctx->r14) = ctx->f10.u32l;
    // 0x80018274: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018278: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001827C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018280: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80018284: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80018288: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x8001828C: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x80018290: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80018294: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018298: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001829C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800182A0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800182A4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x800182A8: swc1        $f10, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f10.u32l;
    // 0x800182AC: b           L_80018354
    // 0x800182B0: nop

        goto L_80018354;
    // 0x800182B0: nop

L_800182B4:
    // 0x800182B4: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x800182B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800182BC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800182C0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800182C4: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800182C8: addiu       $t8, $t8, -0x59C0
    ctx->r24 = ADD32(ctx->r24, -0X59C0);
    // 0x800182CC: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x800182D0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800182D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800182D8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800182DC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800182E0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800182E4: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x800182E8: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x800182EC: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x800182F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800182F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800182F8: nop

    // 0x800182FC: swc1        $f16, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->f16.u32l;
    // 0x80018300: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018304: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018308: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8001830C: nop

    // 0x80018310: swc1        $f18, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->f18.u32l;
    // 0x80018314: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80018318: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001831C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018320: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018324: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018328: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001832C: swc1        $f8, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f8.u32l;
    // 0x80018330: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80018334: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018338: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001833C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018340: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80018344: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018348: swc1        $f18, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f18.u32l;
    // 0x8001834C: b           L_80018354
    // 0x80018350: nop

        goto L_80018354;
    // 0x80018350: nop

L_80018354:
    // 0x80018354: b           L_80018364
    // 0x80018358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80018364;
    // 0x80018358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001835C: b           L_80018364
    // 0x80018360: nop

        goto L_80018364;
    // 0x80018360: nop

L_80018364:
    // 0x80018364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80018368: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001836C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80018370: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80018374: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80018378: jr          $ra
    // 0x8001837C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001837C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
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
RECOMP_FUNC void func_8006340C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006340C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063414: jal         0x8005F064
    // 0x80063418: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063418: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x8006341C: b           L_8006342C
    // 0x80063420: nop

        goto L_8006342C;
    // 0x80063420: nop

    // 0x80063424: b           L_8006342C
    // 0x80063428: nop

        goto L_8006342C;
    // 0x80063428: nop

L_8006342C:
    // 0x8006342C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063434: jr          $ra
    // 0x80063438: nop

    return;
    // 0x80063438: nop

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
RECOMP_FUNC void func_80060ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060ACC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060AD4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80060AD8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80060ADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060AE0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80060AE4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060AE8: lw          $t8, 0x644($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X644);
    // 0x80060AEC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80060AF0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80060AF4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80060AF8: jal         0x800BC6EC
    // 0x80060AFC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80060AFC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_0:
    // 0x80060B00: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80060B04: jal         0x80061E14
    // 0x80060B08: nop

    func_80061E14(rdram, ctx);
        goto after_1;
    // 0x80060B08: nop

    after_1:
    // 0x80060B0C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80060B10: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80060B14: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80060B18: jal         0x80060A04
    // 0x80060B1C: nop

    func_80060A04(rdram, ctx);
        goto after_2;
    // 0x80060B1C: nop

    after_2:
    // 0x80060B20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80060B24: jal         0x800611EC
    // 0x80060B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800611EC(rdram, ctx);
        goto after_3;
    // 0x80060B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80060B2C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80060B30: nop

    // 0x80060B34: beq         $t0, $zero, L_80060B98
    if (ctx->r8 == 0) {
        // 0x80060B38: nop
    
            goto L_80060B98;
    }
    // 0x80060B38: nop

    // 0x80060B3C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80060B40: nop

    // 0x80060B44: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80060B48: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80060B4C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80060B50: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80060B54: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80060B58: addiu       $t5, $t4, -0x2C1
    ctx->r13 = ADD32(ctx->r12, -0X2C1);
    // 0x80060B5C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80060B60: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80060B64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80060B68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80060B6C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80060B70: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80060B74: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80060B78: nop

    // 0x80060B7C: slti        $at, $t0, 0x320
    ctx->r1 = SIGNED(ctx->r8) < 0X320 ? 1 : 0;
    // 0x80060B80: bne         $at, $zero, L_80060B98
    if (ctx->r1 != 0) {
        // 0x80060B84: nop
    
            goto L_80060B98;
    }
    // 0x80060B84: nop

    // 0x80060B88: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80060B8C: nop

    // 0x80060B90: addiu       $t2, $t1, 0xF
    ctx->r10 = ADD32(ctx->r9, 0XF);
    // 0x80060B94: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80060B98:
    // 0x80060B98: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80060B9C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80060BA0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80060BA4: nop

    // 0x80060BA8: beq         $t4, $at, L_80060DBC
    if (ctx->r12 == ctx->r1) {
        // 0x80060BAC: nop
    
            goto L_80060DBC;
    }
    // 0x80060BAC: nop

    // 0x80060BB0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80060BB4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80060BB8: lui         $a2, 0x809F
    ctx->r6 = S32(0X809F << 16);
    // 0x80060BBC: addiu       $a2, $a2, -0x4798
    ctx->r6 = ADD32(ctx->r6, -0X4798);
    // 0x80060BC0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80060BC4: jal         0x800BD1FC
    // 0x80060BC8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x80060BC8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_4:
    // 0x80060BCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80060BD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80060BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80060BD8: jal         0x800BD218
    // 0x80060BDC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x80060BDC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_5:
    // 0x80060BE0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80060BE4: nop

    // 0x80060BE8: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x80060BEC: nop

    // 0x80060BF0: bltz        $t7, L_80060C18
    if (SIGNED(ctx->r15) < 0) {
        // 0x80060BF4: nop
    
            goto L_80060C18;
    }
    // 0x80060BF4: nop

    // 0x80060BF8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80060BFC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060C00: lh          $a0, 0x2($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2);
    // 0x80060C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060C08: jal         0x8004BA04
    // 0x80060C0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_6;
    // 0x80060C0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80060C10: b           L_80060DBC
    // 0x80060C14: nop

        goto L_80060DBC;
    // 0x80060C14: nop

L_80060C18:
    // 0x80060C18: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060C1C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80060C20: nop

    // 0x80060C24: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x80060C28: nop

    // 0x80060C2C: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80060C30: bne         $at, $zero, L_80060C74
    if (ctx->r1 != 0) {
        // 0x80060C34: nop
    
            goto L_80060C74;
    }
    // 0x80060C34: nop

    // 0x80060C38: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80060C3C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80060C40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80060C44: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80060C48: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060C4C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80060C50: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80060C54: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80060C58: lh          $a0, 0x8($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X8);
    // 0x80060C5C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060C64: jal         0x8004BA04
    // 0x80060C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_7;
    // 0x80060C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80060C6C: b           L_80060DBC
    // 0x80060C70: nop

        goto L_80060DBC;
    // 0x80060C70: nop

L_80060C74:
    // 0x80060C74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80060C78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80060C7C: nop

    // 0x80060C80: lh          $t8, 0x2E($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2E);
    // 0x80060C84: nop

    // 0x80060C88: slti        $at, $t8, 0x2BC
    ctx->r1 = SIGNED(ctx->r24) < 0X2BC ? 1 : 0;
    // 0x80060C8C: bne         $at, $zero, L_80060CD0
    if (ctx->r1 != 0) {
        // 0x80060C90: nop
    
            goto L_80060CD0;
    }
    // 0x80060C90: nop

    // 0x80060C94: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80060C98: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80060C9C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80060CA0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80060CA4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060CA8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80060CAC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80060CB0: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x80060CB4: lh          $a0, 0x6($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X6);
    // 0x80060CB8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060CBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060CC0: jal         0x8004BA04
    // 0x80060CC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_8;
    // 0x80060CC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80060CC8: b           L_80060DBC
    // 0x80060CCC: nop

        goto L_80060DBC;
    // 0x80060CCC: nop

L_80060CD0:
    // 0x80060CD0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80060CD4: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80060CD8: nop

    // 0x80060CDC: lh          $t6, 0x2C($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X2C);
    // 0x80060CE0: nop

    // 0x80060CE4: slti        $at, $t6, 0x384
    ctx->r1 = SIGNED(ctx->r14) < 0X384 ? 1 : 0;
    // 0x80060CE8: bne         $at, $zero, L_80060D2C
    if (ctx->r1 != 0) {
        // 0x80060CEC: nop
    
            goto L_80060D2C;
    }
    // 0x80060CEC: nop

    // 0x80060CF0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80060CF4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80060CF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80060CFC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80060D00: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060D04: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80060D08: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80060D0C: addu        $t3, $t5, $t2
    ctx->r11 = ADD32(ctx->r13, ctx->r10);
    // 0x80060D10: lh          $a0, 0x4($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X4);
    // 0x80060D14: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060D18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060D1C: jal         0x8004BA04
    // 0x80060D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_9;
    // 0x80060D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80060D24: b           L_80060DBC
    // 0x80060D28: nop

        goto L_80060DBC;
    // 0x80060D28: nop

L_80060D2C:
    // 0x80060D2C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80060D30: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x80060D34: nop

    // 0x80060D38: lh          $t7, 0x2C($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2C);
    // 0x80060D3C: nop

    // 0x80060D40: slti        $at, $t7, 0x2BC
    ctx->r1 = SIGNED(ctx->r15) < 0X2BC ? 1 : 0;
    // 0x80060D44: bne         $at, $zero, L_80060D88
    if (ctx->r1 != 0) {
        // 0x80060D48: nop
    
            goto L_80060D88;
    }
    // 0x80060D48: nop

    // 0x80060D4C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80060D50: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80060D54: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80060D58: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80060D5C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060D60: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80060D64: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80060D68: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x80060D6C: lh          $a0, 0x4($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X4);
    // 0x80060D70: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060D78: jal         0x8004BA04
    // 0x80060D7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_10;
    // 0x80060D7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80060D80: b           L_80060DBC
    // 0x80060D84: nop

        goto L_80060DBC;
    // 0x80060D84: nop

L_80060D88:
    // 0x80060D88: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80060D8C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80060D90: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80060D94: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80060D98: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80060D9C: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80060DA0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80060DA4: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80060DA8: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x80060DAC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060DB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060DB4: jal         0x8004BA04
    // 0x80060DB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_11;
    // 0x80060DB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
L_80060DBC:
    // 0x80060DBC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80060DC0: nop

    // 0x80060DC4: lh          $a0, 0x0($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X0);
    // 0x80060DC8: jal         0x80061B38
    // 0x80060DCC: nop

    func_80061B38(rdram, ctx);
        goto after_12;
    // 0x80060DCC: nop

    after_12:
    // 0x80060DD0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80060DD4: nop

    // 0x80060DD8: lh          $a0, 0x6($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X6);
    // 0x80060DDC: jal         0x80061FFC
    // 0x80060DE0: nop

    func_80061FFC(rdram, ctx);
        goto after_13;
    // 0x80060DE0: nop

    after_13:
    // 0x80060DE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80060DE8: jal         0x800BC980
    // 0x80060DEC: nop

    SysMem_Free(rdram, ctx);
        goto after_14;
    // 0x80060DEC: nop

    after_14:
    // 0x80060DF0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80060DF4: nop

    // 0x80060DF8: lh          $a0, 0x4($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X4);
    // 0x80060DFC: jal         0x80060E9C
    // 0x80060E00: nop

    func_80060E9C(rdram, ctx);
        goto after_15;
    // 0x80060E00: nop

    after_15:
    // 0x80060E04: b           L_80060E14
    // 0x80060E08: nop

        goto L_80060E14;
    // 0x80060E08: nop

    // 0x80060E0C: b           L_80060E14
    // 0x80060E10: nop

        goto L_80060E14;
    // 0x80060E10: nop

L_80060E14:
    // 0x80060E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060E18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060E1C: jr          $ra
    // 0x80060E20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060E20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006D7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D7D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D7D8: jal         0x80061348
    // 0x8006D7DC: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D7DC: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_0:
    // 0x8006D7E0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D7E4: b           L_8006D7F4
    // 0x8006D7E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D7F4;
    // 0x8006D7E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D7EC: b           L_8006D7F4
    // 0x8006D7F0: nop

        goto L_8006D7F4;
    // 0x8006D7F0: nop

L_8006D7F4:
    // 0x8006D7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D7F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D7FC: jr          $ra
    // 0x8006D800: nop

    return;
    // 0x8006D800: nop

;}
RECOMP_FUNC void func_8006C180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C188: jal         0x8005F064
    // 0x8006C18C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C18C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x8006C190: b           L_8006C1A0
    // 0x8006C194: nop

        goto L_8006C1A0;
    // 0x8006C194: nop

    // 0x8006C198: b           L_8006C1A0
    // 0x8006C19C: nop

        goto L_8006C1A0;
    // 0x8006C19C: nop

L_8006C1A0:
    // 0x8006C1A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C1A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C1A8: jr          $ra
    // 0x8006C1AC: nop

    return;
    // 0x8006C1AC: nop

;}
RECOMP_FUNC void Scheduler_HandleVideoMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009769C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800976A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800976A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800976A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800976AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800976B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800976B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800976B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800976BC: jal         0x800C4C40
    // 0x800976C0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800976C0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_0:
    // 0x800976C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800976C8: beq         $v0, $at, L_80097700
    if (ctx->r2 == ctx->r1) {
        // 0x800976CC: nop
    
            goto L_80097700;
    }
    // 0x800976CC: nop

L_800976D0:
    // 0x800976D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800976D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800976D8: jal         0x80097D44
    // 0x800976DC: nop

    Scheduler_AppendTask(rdram, ctx);
        goto after_1;
    // 0x800976DC: nop

    after_1:
    // 0x800976E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800976E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800976E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800976EC: jal         0x800C4C40
    // 0x800976F0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800976F0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_2:
    // 0x800976F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800976F8: bne         $v0, $at, L_800976D0
    if (ctx->r2 != ctx->r1) {
        // 0x800976FC: nop
    
            goto L_800976D0;
    }
    // 0x800976FC: nop

L_80097700:
    // 0x80097700: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097704: nop

    // 0x80097708: lw          $t7, 0x2A4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2A4);
    // 0x8009770C: nop

    // 0x80097710: beq         $t7, $zero, L_8009773C
    if (ctx->r15 == 0) {
        // 0x80097714: nop
    
            goto L_8009773C;
    }
    // 0x80097714: nop

    // 0x80097718: lw          $t8, 0x294($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X294);
    // 0x8009771C: nop

    // 0x80097720: beq         $t8, $zero, L_8009773C
    if (ctx->r24 == 0) {
        // 0x80097724: nop
    
            goto L_8009773C;
    }
    // 0x80097724: nop

    // 0x80097728: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009772C: jal         0x80097F04
    // 0x80097730: nop

    Scheduler_RspTaskYield(rdram, ctx);
        goto after_3;
    // 0x80097730: nop

    after_3:
    // 0x80097734: b           L_80097798
    // 0x80097738: nop

        goto L_80097798;
    // 0x80097738: nop

L_8009773C:
    // 0x8009773C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80097740: nop

    // 0x80097744: lw          $t0, 0x294($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X294);
    // 0x80097748: lw          $t3, 0x298($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X298);
    // 0x8009774C: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80097750: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80097754: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80097758: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8009775C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80097760: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80097764: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80097768: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8009776C: jal         0x80097F78
    // 0x80097770: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    Scheduler_ScheduleTask(rdram, ctx);
        goto after_4;
    // 0x80097770: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x80097774: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80097778: nop

    // 0x8009777C: beq         $v0, $t7, L_80097798
    if (ctx->r2 == ctx->r15) {
        // 0x80097780: nop
    
            goto L_80097798;
    }
    // 0x80097780: nop

    // 0x80097784: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80097788: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8009778C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80097790: jal         0x80097DDC
    // 0x80097794: nop

    Scheduler_ExecuteTask(rdram, ctx);
        goto after_5;
    // 0x80097794: nop

    after_5:
L_80097798:
    // 0x80097798: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009779C: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x800977A0: nop

    // 0x800977A4: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800977A8: bne         $t8, $zero, L_80097818
    if (ctx->r24 != 0) {
        // 0x800977AC: nop
    
            goto L_80097818;
    }
    // 0x800977AC: nop

    // 0x800977B0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800977B4: nop

    // 0x800977B8: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x800977BC: nop

    // 0x800977C0: beq         $t1, $zero, L_80097810
    if (ctx->r9 == 0) {
        // 0x800977C4: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80097810;
    }
    // 0x800977C4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_800977C8:
    // 0x800977C8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800977CC: nop

    // 0x800977D0: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x800977D4: nop

    // 0x800977D8: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x800977DC: bne         $t2, $zero, L_800977F8
    if (ctx->r10 != 0) {
        // 0x800977E0: nop
    
            goto L_800977F8;
    }
    // 0x800977E0: nop

    // 0x800977E4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800977E8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800977EC: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x800977F0: jal         0x800C4AA0
    // 0x800977F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800977F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_800977F8:
    // 0x800977F8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800977FC: nop

    // 0x80097800: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80097804: nop

    // 0x80097808: bne         $t7, $zero, L_800977C8
    if (ctx->r15 != 0) {
        // 0x8009780C: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_800977C8;
    }
    // 0x8009780C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80097810:
    // 0x80097810: b           L_80097914
    // 0x80097814: nop

        goto L_80097914;
    // 0x80097814: nop

L_80097818:
    // 0x80097818: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009781C: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80097820: nop

    // 0x80097824: andi        $t8, $t6, 0x2
    ctx->r24 = ctx->r14 & 0X2;
    // 0x80097828: bne         $t8, $zero, L_8009789C
    if (ctx->r24 != 0) {
        // 0x8009782C: nop
    
            goto L_8009789C;
    }
    // 0x8009782C: nop

    // 0x80097830: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80097834: nop

    // 0x80097838: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x8009783C: nop

    // 0x80097840: beq         $t1, $zero, L_80097894
    if (ctx->r9 == 0) {
        // 0x80097844: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80097894;
    }
    // 0x80097844: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80097848:
    // 0x80097848: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009784C: nop

    // 0x80097850: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x80097854: nop

    // 0x80097858: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x8009785C: bne         $t2, $zero, L_8009787C
    if (ctx->r10 != 0) {
        // 0x80097860: nop
    
            goto L_8009787C;
    }
    // 0x80097860: nop

    // 0x80097864: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80097868: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8009786C: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x80097870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097874: jal         0x800C4AA0
    // 0x80097878: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80097878: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_7:
L_8009787C:
    // 0x8009787C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80097880: nop

    // 0x80097884: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80097888: nop

    // 0x8009788C: bne         $t7, $zero, L_80097848
    if (ctx->r15 != 0) {
        // 0x80097890: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_80097848;
    }
    // 0x80097890: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80097894:
    // 0x80097894: b           L_80097914
    // 0x80097898: nop

        goto L_80097914;
    // 0x80097898: nop

L_8009789C:
    // 0x8009789C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800978A0: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x800978A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800978A8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800978AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800978B0: sw          $t8, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r24;
    // 0x800978B4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800978B8: nop

    // 0x800978BC: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x800978C0: nop

    // 0x800978C4: beq         $t1, $zero, L_80097914
    if (ctx->r9 == 0) {
        // 0x800978C8: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80097914;
    }
    // 0x800978C8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_800978CC:
    // 0x800978CC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800978D0: nop

    // 0x800978D4: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x800978D8: nop

    // 0x800978DC: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x800978E0: bne         $t2, $zero, L_800978FC
    if (ctx->r10 != 0) {
        // 0x800978E4: nop
    
            goto L_800978FC;
    }
    // 0x800978E4: nop

    // 0x800978E8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800978EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800978F0: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x800978F4: jal         0x800C4AA0
    // 0x800978F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800978F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_800978FC:
    // 0x800978FC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80097900: nop

    // 0x80097904: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80097908: nop

    // 0x8009790C: bne         $t7, $zero, L_800978CC
    if (ctx->r15 != 0) {
        // 0x80097910: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_800978CC;
    }
    // 0x80097910: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80097914:
    // 0x80097914: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097918: nop

    // 0x8009791C: lw          $t8, 0x29C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X29C);
    // 0x80097920: nop

    // 0x80097924: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80097928: sw          $t0, 0x29C($t6)
    MEM_W(0X29C, ctx->r14) = ctx->r8;
    // 0x8009792C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80097930: nop

    // 0x80097934: lw          $t9, 0x2A0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X2A0);
    // 0x80097938: nop

    // 0x8009793C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80097940: sw          $t3, 0x2A0($t1)
    MEM_W(0X2A0, ctx->r9) = ctx->r11;
    // 0x80097944: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80097948: lw          $t2, 0x72DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72DC);
    // 0x8009794C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80097950: ori         $t4, $t2, 0x8
    ctx->r12 = ctx->r10 | 0X8;
    // 0x80097954: sw          $t4, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r12;
    // 0x80097958: jal         0x800C40D0
    // 0x8009795C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_9;
    // 0x8009795C: nop

    after_9:
    // 0x80097960: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80097964: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x80097968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009796C: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
    // 0x80097970: b           L_80097978
    // 0x80097974: nop

        goto L_80097978;
    // 0x80097974: nop

L_80097978:
    // 0x80097978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009797C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80097980: jr          $ra
    // 0x80097984: nop

    return;
    // 0x80097984: nop

;}
RECOMP_FUNC void func_800B2748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B274C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2750: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B2754: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B2758: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B275C: nop

    // 0x800B2760: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2764: nop

    // 0x800B2768: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B276C: nop

    // 0x800B2770: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x800B2774: nop

    // 0x800B2778: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800B277C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B2780: nop

    // 0x800B2784: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B2788: nop

    // 0x800B278C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800B2790: nop

    // 0x800B2794: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800B2798: beq         $t3, $zero, L_800B27C8
    if (ctx->r11 == 0) {
        // 0x800B279C: nop
    
            goto L_800B27C8;
    }
    // 0x800B279C: nop

    // 0x800B27A0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B27A4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B27A8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B27AC: nop

    // 0x800B27B0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B27B4: nop

    // 0x800B27B8: lbu         $t8, 0xF($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF);
    // 0x800B27BC: nop

    // 0x800B27C0: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800B27C4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800B27C8:
    // 0x800B27C8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B27CC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B27D0: blez        $t0, L_800B2884
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B27D4: nop
    
            goto L_800B2884;
    }
    // 0x800B27D4: nop

L_800B27D8:
    // 0x800B27D8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B27DC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B27E0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800B27E4: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x800B27E8: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800B27EC: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B27F0: nop

    // 0x800B27F4: andi        $t4, $t7, 0x400
    ctx->r12 = ctx->r15 & 0X400;
    // 0x800B27F8: beq         $t4, $zero, L_800B2808
    if (ctx->r12 == 0) {
        // 0x800B27FC: nop
    
            goto L_800B2808;
    }
    // 0x800B27FC: nop

    // 0x800B2800: b           L_800B286C
    // 0x800B2804: nop

        goto L_800B286C;
    // 0x800B2804: nop

L_800B2808:
    // 0x800B2808: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B280C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B2810: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B2814: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B2818: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B281C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B2820: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B2824: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x800B2828: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B282C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800B2830: sll         $t5, $t0, 6
    ctx->r13 = S32(ctx->r8 << 6);
    // 0x800B2834: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x800B2838: jal         0x800B2A34
    // 0x800B283C: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    func_800B2A34(rdram, ctx);
        goto after_0;
    // 0x800B283C: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    after_0:
    // 0x800B2840: beq         $v0, $zero, L_800B286C
    if (ctx->r2 == 0) {
        // 0x800B2844: nop
    
            goto L_800B286C;
    }
    // 0x800B2844: nop

    // 0x800B2848: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B284C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B2850: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2854: sll         $t8, $t4, 6
    ctx->r24 = S32(ctx->r12 << 6);
    // 0x800B2858: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B285C: lhu         $t1, 0x3A($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B2860: nop

    // 0x800B2864: ori         $t3, $t1, 0x400
    ctx->r11 = ctx->r9 | 0X400;
    // 0x800B2868: sh          $t3, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r11;
L_800B286C:
    // 0x800B286C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B2870: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2874: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800B2878: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B287C: bne         $at, $zero, L_800B27D8
    if (ctx->r1 != 0) {
        // 0x800B2880: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_800B27D8;
    }
    // 0x800B2880: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800B2884:
    // 0x800B2884: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2888: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B288C: blez        $t6, L_800B28DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B2890: nop
    
            goto L_800B28DC;
    }
    // 0x800B2890: nop

L_800B2894:
    // 0x800B2894: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B2898: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B289C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800B28A0: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x800B28A4: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800B28A8: lhu         $t9, 0x3A($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B28AC: nop

    // 0x800B28B0: andi        $t0, $t9, 0x400
    ctx->r8 = ctx->r25 & 0X400;
    // 0x800B28B4: bne         $t0, $zero, L_800B28C4
    if (ctx->r8 != 0) {
        // 0x800B28B8: nop
    
            goto L_800B28C4;
    }
    // 0x800B28B8: nop

    // 0x800B28BC: b           L_800B28DC
    // 0x800B28C0: nop

        goto L_800B28DC;
    // 0x800B28C0: nop

L_800B28C4:
    // 0x800B28C4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800B28C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B28CC: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x800B28D0: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B28D4: bne         $at, $zero, L_800B2894
    if (ctx->r1 != 0) {
        // 0x800B28D8: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_800B2894;
    }
    // 0x800B28D8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
L_800B28DC:
    // 0x800B28DC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B28E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B28E4: nop

    // 0x800B28E8: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B28EC: bne         $at, $zero, L_800B28FC
    if (ctx->r1 != 0) {
        // 0x800B28F0: nop
    
            goto L_800B28FC;
    }
    // 0x800B28F0: nop

    // 0x800B28F4: b           L_800B2A24
    // 0x800B28F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2A24;
    // 0x800B28F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B28FC:
    // 0x800B28FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B2900: nop

    // 0x800B2904: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x800B2908: nop

    // 0x800B290C: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x800B2910: nop

    // 0x800B2914: andi        $t9, $t3, 0x4
    ctx->r25 = ctx->r11 & 0X4;
    // 0x800B2918: beq         $t9, $zero, L_800B298C
    if (ctx->r25 == 0) {
        // 0x800B291C: nop
    
            goto L_800B298C;
    }
    // 0x800B291C: nop

    // 0x800B2920: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B2924: nop

    // 0x800B2928: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B292C: nop

    // 0x800B2930: lhu         $t5, 0x3A($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X3A);
    // 0x800B2934: nop

    // 0x800B2938: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x800B293C: beq         $t6, $zero, L_800B298C
    if (ctx->r14 == 0) {
        // 0x800B2940: nop
    
            goto L_800B298C;
    }
    // 0x800B2940: nop

    // 0x800B2944: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B2948: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B294C: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800B2950: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2954: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x800B2958: nop

    // 0x800B295C: lbu         $t1, 0xE($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0XE);
    // 0x800B2960: nop

    // 0x800B2964: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B2968: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800B296C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B2970: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800B2974: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800B2978: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x800B297C: lw          $t5, 0xC0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC0);
    // 0x800B2980: nop

    // 0x800B2984: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x800B2988: sw          $t6, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r14;
L_800B298C:
    // 0x800B298C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2990: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B2994: blez        $t4, L_800B2A10
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B2998: nop
    
            goto L_800B2A10;
    }
    // 0x800B2998: nop

L_800B299C:
    // 0x800B299C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B29A0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800B29A4: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800B29A8: sll         $t9, $t1, 6
    ctx->r25 = S32(ctx->r9 << 6);
    // 0x800B29AC: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x800B29B0: lhu         $t0, 0x3A($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B29B4: nop

    // 0x800B29B8: andi        $t5, $t0, 0x400
    ctx->r13 = ctx->r8 & 0X400;
    // 0x800B29BC: beq         $t5, $zero, L_800B29F8
    if (ctx->r13 == 0) {
        // 0x800B29C0: nop
    
            goto L_800B29F8;
    }
    // 0x800B29C0: nop

    // 0x800B29C4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B29C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B29CC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B29D0: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x800B29D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B29D8: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x800B29DC: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x800B29E0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800B29E4: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800B29E8: lw          $t7, 0xC0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XC0);
    // 0x800B29EC: nop

    // 0x800B29F0: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x800B29F4: sw          $t9, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r25;
L_800B29F8:
    // 0x800B29F8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B29FC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2A00: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x800B2A04: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2A08: bne         $at, $zero, L_800B299C
    if (ctx->r1 != 0) {
        // 0x800B2A0C: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_800B299C;
    }
    // 0x800B2A0C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800B2A10:
    // 0x800B2A10: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2A14: b           L_800B2A24
    // 0x800B2A18: nop

        goto L_800B2A24;
    // 0x800B2A18: nop

    // 0x800B2A1C: b           L_800B2A24
    // 0x800B2A20: nop

        goto L_800B2A24;
    // 0x800B2A20: nop

L_800B2A24:
    // 0x800B2A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B2A2C: jr          $ra
    // 0x800B2A30: nop

    return;
    // 0x800B2A30: nop

;}
RECOMP_FUNC void func_8006F2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F2F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F2F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F2F8: nop

    // 0x8006F2FC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F300: nop

    // 0x8006F304: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F308: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F30C: jr          $ra
    // 0x8006F310: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F310: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F314: jr          $ra
    // 0x8006F318: nop

    return;
    // 0x8006F318: nop

    // 0x8006F31C: jr          $ra
    // 0x8006F320: nop

    return;
    // 0x8006F320: nop

;}
RECOMP_FUNC void func_80082958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082958: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008295C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80082964: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80082968: lw          $t6, 0x165C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X165C);
    // 0x8008296C: nop

    // 0x80082970: bne         $t6, $zero, L_80082980
    if (ctx->r14 != 0) {
        // 0x80082974: nop
    
            goto L_80082980;
    }
    // 0x80082974: nop

    // 0x80082978: b           L_80082BF4
    // 0x8008297C: nop

        goto L_80082BF4;
    // 0x8008297C: nop

L_80082980:
    // 0x80082980: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80082984: lw          $t7, 0x165C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X165C);
    // 0x80082988: nop

    // 0x8008298C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80082990:
    // 0x80082990: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80082994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80082998: lh          $s0, 0xC($t8)
    ctx->r16 = MEM_H(ctx->r24, 0XC);
    // 0x8008299C: nop

    // 0x800829A0: beq         $s0, $at, L_800829D4
    if (ctx->r16 == ctx->r1) {
        // 0x800829A4: nop
    
            goto L_800829D4;
    }
    // 0x800829A4: nop

    // 0x800829A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800829AC: beq         $s0, $at, L_800829E8
    if (ctx->r16 == ctx->r1) {
        // 0x800829B0: nop
    
            goto L_800829E8;
    }
    // 0x800829B0: nop

    // 0x800829B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800829B8: beq         $s0, $at, L_80082B0C
    if (ctx->r16 == ctx->r1) {
        // 0x800829BC: nop
    
            goto L_80082B0C;
    }
    // 0x800829BC: nop

    // 0x800829C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800829C4: beq         $s0, $at, L_80082BA8
    if (ctx->r16 == ctx->r1) {
        // 0x800829C8: nop
    
            goto L_80082BA8;
    }
    // 0x800829C8: nop

    // 0x800829CC: b           L_80082BB0
    // 0x800829D0: nop

        goto L_80082BB0;
    // 0x800829D0: nop

L_800829D4:
    // 0x800829D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800829D8: jal         0x80082C04
    // 0x800829DC: nop

    func_80082C04(rdram, ctx);
        goto after_0;
    // 0x800829DC: nop

    after_0:
    // 0x800829E0: b           L_80082BB0
    // 0x800829E4: nop

        goto L_80082BB0;
    // 0x800829E4: nop

L_800829E8:
    // 0x800829E8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800829EC: addiu       $at, $zero, 0x244
    ctx->r1 = ADD32(0, 0X244);
    // 0x800829F0: lh          $s0, 0xA($t9)
    ctx->r16 = MEM_H(ctx->r25, 0XA);
    // 0x800829F4: nop

    // 0x800829F8: beq         $s0, $at, L_80082A20
    if (ctx->r16 == ctx->r1) {
        // 0x800829FC: nop
    
            goto L_80082A20;
    }
    // 0x800829FC: nop

    // 0x80082A00: addiu       $at, $zero, 0x246
    ctx->r1 = ADD32(0, 0X246);
    // 0x80082A04: beq         $s0, $at, L_80082A74
    if (ctx->r16 == ctx->r1) {
        // 0x80082A08: nop
    
            goto L_80082A74;
    }
    // 0x80082A08: nop

    // 0x80082A0C: addiu       $at, $zero, 0x247
    ctx->r1 = ADD32(0, 0X247);
    // 0x80082A10: beq         $s0, $at, L_80082AD4
    if (ctx->r16 == ctx->r1) {
        // 0x80082A14: nop
    
            goto L_80082AD4;
    }
    // 0x80082A14: nop

    // 0x80082A18: b           L_80082B04
    // 0x80082A1C: nop

        goto L_80082B04;
    // 0x80082A1C: nop

L_80082A20:
    // 0x80082A20: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80082A24: nop

    // 0x80082A28: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80082A2C: nop

    // 0x80082A30: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x80082A34: beq         $t2, $zero, L_80082A6C
    if (ctx->r10 == 0) {
        // 0x80082A38: nop
    
            goto L_80082A6C;
    }
    // 0x80082A38: nop

    // 0x80082A3C: andi        $t3, $t1, 0x4
    ctx->r11 = ctx->r9 & 0X4;
    // 0x80082A40: beq         $t3, $zero, L_80082A6C
    if (ctx->r11 == 0) {
        // 0x80082A44: nop
    
            goto L_80082A6C;
    }
    // 0x80082A44: nop

    // 0x80082A48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082A4C: jal         0x80082D18
    // 0x80082A50: addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    func_80082D18(rdram, ctx);
        goto after_1;
    // 0x80082A50: addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    after_1:
    // 0x80082A54: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80082A58: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80082A5C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80082A60: nop

    // 0x80082A64: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80082A68: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
L_80082A6C:
    // 0x80082A6C: b           L_80082B04
    // 0x80082A70: nop

        goto L_80082B04;
    // 0x80082A70: nop

L_80082A74:
    // 0x80082A74: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80082A78: nop

    // 0x80082A7C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80082A80: nop

    // 0x80082A84: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80082A88: beq         $t9, $zero, L_80082ACC
    if (ctx->r25 == 0) {
        // 0x80082A8C: nop
    
            goto L_80082ACC;
    }
    // 0x80082A8C: nop

    // 0x80082A90: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x80082A94: beq         $t0, $zero, L_80082ACC
    if (ctx->r8 == 0) {
        // 0x80082A98: nop
    
            goto L_80082ACC;
    }
    // 0x80082A98: nop

    // 0x80082A9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082AA0: jal         0x80082D18
    // 0x80082AA4: addiu       $a1, $zero, 0x247
    ctx->r5 = ADD32(0, 0X247);
    func_80082D18(rdram, ctx);
        goto after_2;
    // 0x80082AA4: addiu       $a1, $zero, 0x247
    ctx->r5 = ADD32(0, 0X247);
    after_2:
    // 0x80082AA8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082AAC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80082AB0: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x80082AB4: nop

    // 0x80082AB8: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80082ABC: sb          $t3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r11;
    // 0x80082AC0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80082AC4: nop

    // 0x80082AC8: sh          $zero, 0xE($t5)
    MEM_H(0XE, ctx->r13) = 0;
L_80082ACC:
    // 0x80082ACC: b           L_80082B04
    // 0x80082AD0: nop

        goto L_80082B04;
    // 0x80082AD0: nop

L_80082AD4:
    // 0x80082AD4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082AD8: nop

    // 0x80082ADC: lbu         $t4, 0x0($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X0);
    // 0x80082AE0: nop

    // 0x80082AE4: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80082AE8: beq         $t7, $zero, L_80082AFC
    if (ctx->r15 == 0) {
        // 0x80082AEC: nop
    
            goto L_80082AFC;
    }
    // 0x80082AEC: nop

    // 0x80082AF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082AF4: jal         0x80082D18
    // 0x80082AF8: addiu       $a1, $zero, 0x244
    ctx->r5 = ADD32(0, 0X244);
    func_80082D18(rdram, ctx);
        goto after_3;
    // 0x80082AF8: addiu       $a1, $zero, 0x244
    ctx->r5 = ADD32(0, 0X244);
    after_3:
L_80082AFC:
    // 0x80082AFC: b           L_80082B04
    // 0x80082B00: nop

        goto L_80082B04;
    // 0x80082B00: nop

L_80082B04:
    // 0x80082B04: b           L_80082BB0
    // 0x80082B08: nop

        goto L_80082BB0;
    // 0x80082B08: nop

L_80082B0C:
    // 0x80082B0C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80082B10: nop

    // 0x80082B14: lh          $t8, 0xE($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XE);
    // 0x80082B18: nop

    // 0x80082B1C: slti        $at, $t8, 0x259
    ctx->r1 = SIGNED(ctx->r24) < 0X259 ? 1 : 0;
    // 0x80082B20: bne         $at, $zero, L_80082B6C
    if (ctx->r1 != 0) {
        // 0x80082B24: nop
    
            goto L_80082B6C;
    }
    // 0x80082B24: nop

    // 0x80082B28: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80082B2C: nop

    // 0x80082B30: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80082B34: nop

    // 0x80082B38: andi        $t3, $t1, 0x4
    ctx->r11 = ctx->r9 & 0X4;
    // 0x80082B3C: beq         $t3, $zero, L_80082B58
    if (ctx->r11 == 0) {
        // 0x80082B40: nop
    
            goto L_80082B58;
    }
    // 0x80082B40: nop

    // 0x80082B44: lh          $t2, 0xE($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XE);
    // 0x80082B48: nop

    // 0x80082B4C: slti        $at, $t2, 0x259
    ctx->r1 = SIGNED(ctx->r10) < 0X259 ? 1 : 0;
    // 0x80082B50: bne         $at, $zero, L_80082B64
    if (ctx->r1 != 0) {
        // 0x80082B54: nop
    
            goto L_80082B64;
    }
    // 0x80082B54: nop

L_80082B58:
    // 0x80082B58: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082B5C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80082B60: sh          $t5, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r13;
L_80082B64:
    // 0x80082B64: b           L_80082BA0
    // 0x80082B68: nop

        goto L_80082BA0;
    // 0x80082B68: nop

L_80082B6C:
    // 0x80082B6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80082B70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082B74: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80082B78: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80082B7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082B80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082B84: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80082B88: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80082B8C: lh          $t7, 0xE($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XE);
    // 0x80082B90: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80082B94: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80082B98: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x80082B9C: sh          $t1, 0xE($t4)
    MEM_H(0XE, ctx->r12) = ctx->r9;
L_80082BA0:
    // 0x80082BA0: b           L_80082BB0
    // 0x80082BA4: nop

        goto L_80082BB0;
    // 0x80082BA4: nop

L_80082BA8:
    // 0x80082BA8: b           L_80082BB0
    // 0x80082BAC: nop

        goto L_80082BB0;
    // 0x80082BAC: nop

L_80082BB0:
    // 0x80082BB0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80082BB4: nop

    // 0x80082BB8: lh          $t0, 0xC($t3)
    ctx->r8 = MEM_H(ctx->r11, 0XC);
    // 0x80082BBC: nop

    // 0x80082BC0: blez        $t0, L_80082BD4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80082BC4: nop
    
            goto L_80082BD4;
    }
    // 0x80082BC4: nop

    // 0x80082BC8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80082BCC: jal         0x80082DD4
    // 0x80082BD0: nop

    func_80082DD4(rdram, ctx);
        goto after_4;
    // 0x80082BD0: nop

    after_4:
L_80082BD4:
    // 0x80082BD4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082BD8: nop

    // 0x80082BDC: lw          $t5, 0x44($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X44);
    // 0x80082BE0: nop

    // 0x80082BE4: bne         $t5, $zero, L_80082990
    if (ctx->r13 != 0) {
        // 0x80082BE8: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80082990;
    }
    // 0x80082BE8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80082BEC: b           L_80082BF4
    // 0x80082BF0: nop

        goto L_80082BF4;
    // 0x80082BF0: nop

L_80082BF4:
    // 0x80082BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082BF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082BFC: jr          $ra
    // 0x80082C00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80082C00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800726F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800726F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800726FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072700: nop

    // 0x80072704: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072708: nop

    // 0x8007270C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072710: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072714: jr          $ra
    // 0x80072718: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072718: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007271C: jr          $ra
    // 0x80072720: nop

    return;
    // 0x80072720: nop

    // 0x80072724: jr          $ra
    // 0x80072728: nop

    return;
    // 0x80072728: nop

;}
