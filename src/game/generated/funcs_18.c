#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80086514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008651C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086524: jal         0x8008B4EC
    // 0x80086528: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086528: nop

    after_0:
    // 0x8008652C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086530: jal         0x8008B600
    // 0x80086534: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086534: nop

    after_1:
    // 0x80086538: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008653C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80086540: lh          $t7, 0xBE8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XBE8);
    // 0x80086544: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086548: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008654C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086550: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086554: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086558: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008655C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x80086560: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80086564: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086568: jal         0x8008B738
    // 0x8008656C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x8008656C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x80086570: b           L_80086578
    // 0x80086574: nop

        goto L_80086578;
    // 0x80086574: nop

L_80086578:
    // 0x80086578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008657C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086580: jr          $ra
    // 0x80086584: nop

    return;
    // 0x80086584: nop

;}
RECOMP_FUNC void __osSetHWIntrRoutine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D46D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D46D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D46D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D46DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D46E0: jal         0x800CBA20
    // 0x800D46E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x800D46E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D46E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D46EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D46F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D46F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D46F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D46FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D4700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4704: jal         0x800CBA40
    // 0x800D4708: sw          $t6, -0x32E0($at)
    MEM_W(-0X32E0, ctx->r1) = ctx->r14;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x800D4708: sw          $t6, -0x32E0($at)
    MEM_W(-0X32E0, ctx->r1) = ctx->r14;
    after_1:
    // 0x800D470C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4710: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D4718: jr          $ra
    // 0x800D471C: nop

    return;
    // 0x800D471C: nop

;}
RECOMP_FUNC void func_800ABE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABE54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800ABE58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE5C: swc1        $f4, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f4.u32l;
    // 0x800ABE60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ABE64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE68: swc1        $f6, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f6.u32l;
    // 0x800ABE6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800ABE70: lwc1        $f8, -0x738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X738);
    // 0x800ABE74: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE78: swc1        $f8, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f8.u32l;
    // 0x800ABE7C: lui         $at, 0x436F
    ctx->r1 = S32(0X436F << 16);
    // 0x800ABE80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ABE84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE88: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
    // 0x800ABE8C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800ABE90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ABE94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE98: swc1        $f16, 0x61C0($at)
    MEM_W(0X61C0, ctx->r1) = ctx->f16.u32l;
    // 0x800ABE9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800ABEA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ABEA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEA8: swc1        $f18, 0x61C4($at)
    MEM_W(0X61C4, ctx->r1) = ctx->f18.u32l;
    // 0x800ABEAC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800ABEB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ABEB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEB8: swc1        $f4, 0x61C8($at)
    MEM_W(0X61C8, ctx->r1) = ctx->f4.u32l;
    // 0x800ABEBC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800ABEC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ABEC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEC8: swc1        $f6, 0x61D0($at)
    MEM_W(0X61D0, ctx->r1) = ctx->f6.u32l;
    // 0x800ABECC: jr          $ra
    // 0x800ABED0: nop

    return;
    // 0x800ABED0: nop

    // 0x800ABED4: jr          $ra
    // 0x800ABED8: nop

    return;
    // 0x800ABED8: nop

;}
RECOMP_FUNC void func_800AFAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFAB0: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x800AFAB4: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x800AFAB8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AFABC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800AFAC0: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x800AFAC4: lb          $t7, 0xC($t6)
    ctx->r15 = MEM_B(ctx->r14, 0XC);
    // 0x800AFAC8: nop

    // 0x800AFACC: sb          $t7, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r15;
    // 0x800AFAD0: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x800AFAD4: nop

    // 0x800AFAD8: beq         $t8, $zero, L_800AFAEC
    if (ctx->r24 == 0) {
        // 0x800AFADC: nop
    
            goto L_800AFAEC;
    }
    // 0x800AFADC: nop

    // 0x800AFAE0: sb          $a2, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r6;
    // 0x800AFAE4: b           L_800AFB0C
    // 0x800AFAE8: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
        goto L_800AFB0C;
    // 0x800AFAE8: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
L_800AFAEC:
    // 0x800AFAEC: lb          $t9, 0x6($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X6);
    // 0x800AFAF0: nop

    // 0x800AFAF4: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800AFAF8: bgez        $t0, L_800AFB08
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AFAFC: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_800AFB08;
    }
    // 0x800AFAFC: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800AFB00: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x800AFB04: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800AFB08:
    // 0x800AFB08: sb          $t1, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r9;
L_800AFB0C:
    // 0x800AFB0C: lb          $t2, 0x6($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X6);
    // 0x800AFB10: addu        $t3, $a0, $a1
    ctx->r11 = ADD32(ctx->r4, ctx->r5);
    // 0x800AFB14: sb          $t2, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r10;
    // 0x800AFB18: b           L_800AFB20
    // 0x800AFB1C: nop

        goto L_800AFB20;
    // 0x800AFB1C: nop

L_800AFB20:
    // 0x800AFB20: jr          $ra
    // 0x800AFB24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AFB24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80076EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076EF0: jal         0x80061488
    // 0x80076EF4: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076EF4: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076EF8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076EFC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076F00: b           L_80076F10
    // 0x80076F04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076F10;
    // 0x80076F04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076F08: b           L_80076F10
    // 0x80076F0C: nop

        goto L_80076F10;
    // 0x80076F0C: nop

L_80076F10:
    // 0x80076F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076F18: jr          $ra
    // 0x80076F1C: nop

    return;
    // 0x80076F1C: nop

;}
RECOMP_FUNC void func_8005CDBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CDBC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8005CDC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005CDC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CDC8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005CDCC: nop

    // 0x8005CDD0: beq         $t6, $zero, L_8005CE2C
    if (ctx->r14 == 0) {
        // 0x8005CDD4: nop
    
            goto L_8005CE2C;
    }
    // 0x8005CDD4: nop

    // 0x8005CDD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005CDDC: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005CDE0: nop

    // 0x8005CDE4: beq         $t7, $zero, L_8005CE2C
    if (ctx->r15 == 0) {
        // 0x8005CDE8: nop
    
            goto L_8005CE2C;
    }
    // 0x8005CDE8: nop

    // 0x8005CDEC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005CDF0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005CDF4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005CDF8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005CDFC: bne         $t0, $zero, L_8005CE0C
    if (ctx->r8 != 0) {
        // 0x8005CE00: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005CE0C;
    }
    // 0x8005CE00: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005CE04: beq         $t1, $zero, L_8005CE2C
    if (ctx->r9 == 0) {
        // 0x8005CE08: nop
    
            goto L_8005CE2C;
    }
    // 0x8005CE08: nop

L_8005CE0C:
    // 0x8005CE0C: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005CE10: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8005CE14: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005CE18: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005CE1C: bne         $t4, $zero, L_8005CE34
    if (ctx->r12 != 0) {
        // 0x8005CE20: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8005CE34;
    }
    // 0x8005CE20: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8005CE24: bne         $t5, $zero, L_8005CE34
    if (ctx->r13 != 0) {
        // 0x8005CE28: nop
    
            goto L_8005CE34;
    }
    // 0x8005CE28: nop

L_8005CE2C:
    // 0x8005CE2C: b           L_8005D06C
    // 0x8005CE30: nop

        goto L_8005D06C;
    // 0x8005CE30: nop

L_8005CE34:
    // 0x8005CE34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CE38: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005CE3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005CE40: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005CE44: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x8005CE48: lw          $a1, 0x4C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4C);
    // 0x8005CE4C: lw          $a2, 0x50($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X50);
    // 0x8005CE50: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005CE54: lw          $t0, 0x4C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4C);
    // 0x8005CE58: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8005CE5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8005CE60: lw          $t1, 0x50($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X50);
    // 0x8005CE64: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005CE68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005CE6C: jal         0x800784E8
    // 0x8005CE70: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800784E8(rdram, ctx);
        goto after_0;
    // 0x8005CE70: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x8005CE74: beq         $v0, $zero, L_8005CF54
    if (ctx->r2 == 0) {
        // 0x8005CE78: nop
    
            goto L_8005CF54;
    }
    // 0x8005CE78: nop

    // 0x8005CE7C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005CE80: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005CE84: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005CE88: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005CE8C: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005CE90: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005CE94: nop

    // 0x8005CE98: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005CE9C: nop

    // 0x8005CEA0: bc1f        L_8005CEEC
    if (!c1cs) {
        // 0x8005CEA4: nop
    
            goto L_8005CEEC;
    }
    // 0x8005CEA4: nop

    // 0x8005CEA8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005CEAC: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005CEB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CEB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005CEB8: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x8005CEBC: nop

    // 0x8005CEC0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8005CEC4: swc1        $f16, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f16.u32l;
    // 0x8005CEC8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005CECC: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005CED0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CED4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005CED8: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8005CEDC: nop

    // 0x8005CEE0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005CEE4: b           L_8005CF2C
    // 0x8005CEE8: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
        goto L_8005CF2C;
    // 0x8005CEE8: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
L_8005CEEC:
    // 0x8005CEEC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005CEF0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005CEF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CEF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005CEFC: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005CF00: nop

    // 0x8005CF04: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005CF08: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
    // 0x8005CF0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CF10: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005CF14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CF18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005CF1C: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8005CF20: nop

    // 0x8005CF24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005CF28: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
L_8005CF2C:
    // 0x8005CF2C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CF30: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005CF34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8005CF38: jal         0x8005D07C
    // 0x8005CF3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_1;
    // 0x8005CF3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x8005CF40: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CF44: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005CF48: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8005CF4C: jal         0x8005D07C
    // 0x8005CF50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_2;
    // 0x8005CF50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
L_8005CF54:
    // 0x8005CF54: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005CF58: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005CF5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005CF60: lw          $a1, 0x4C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4C);
    // 0x8005CF64: lw          $a2, 0x50($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X50);
    // 0x8005CF68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005CF6C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8005CF70: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005CF74: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8005CF78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005CF7C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8005CF80: jal         0x80077FF0
    // 0x8005CF84: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80077FF0(rdram, ctx);
        goto after_3;
    // 0x8005CF84: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8005CF88: beq         $v0, $zero, L_8005CFDC
    if (ctx->r2 == 0) {
        // 0x8005CF8C: nop
    
            goto L_8005CFDC;
    }
    // 0x8005CF8C: nop

    // 0x8005CF90: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005CF94: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005CF98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005CF9C: lw          $a3, 0x4C($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4C);
    // 0x8005CFA0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005CFA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005CFA8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005CFAC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8005CFB0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8005CFB4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8005CFB8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8005CFBC: jal         0x80078168
    // 0x8005CFC0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80078168(rdram, ctx);
        goto after_4;
    // 0x8005CFC0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8005CFC4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CFC8: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005CFCC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8005CFD0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8005CFD4: jal         0x8005D07C
    // 0x8005CFD8: nop

    func_8005D07C(rdram, ctx);
        goto after_5;
    // 0x8005CFD8: nop

    after_5:
L_8005CFDC:
    // 0x8005CFDC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005CFE0: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005CFE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005CFE8: lw          $a1, 0x4C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4C);
    // 0x8005CFEC: lw          $a2, 0x50($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X50);
    // 0x8005CFF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005CFF4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8005CFF8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8005CFFC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8005D000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005D004: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8005D008: jal         0x80077FF0
    // 0x8005D00C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80077FF0(rdram, ctx);
        goto after_6;
    // 0x8005D00C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8005D010: beq         $v0, $zero, L_8005D064
    if (ctx->r2 == 0) {
        // 0x8005D014: nop
    
            goto L_8005D064;
    }
    // 0x8005D014: nop

    // 0x8005D018: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005D01C: lw          $t3, 0xE70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE70);
    // 0x8005D020: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005D024: lw          $a3, 0x4C($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4C);
    // 0x8005D028: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005D02C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005D030: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8005D034: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8005D038: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8005D03C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8005D040: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8005D044: jal         0x80078168
    // 0x8005D048: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80078168(rdram, ctx);
        goto after_7;
    // 0x8005D048: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8005D04C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D050: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005D054: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8005D058: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8005D05C: jal         0x8005D07C
    // 0x8005D060: nop

    func_8005D07C(rdram, ctx);
        goto after_8;
    // 0x8005D060: nop

    after_8:
L_8005D064:
    // 0x8005D064: b           L_8005D06C
    // 0x8005D068: nop

        goto L_8005D06C;
    // 0x8005D068: nop

L_8005D06C:
    // 0x8005D06C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005D070: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // 0x8005D074: jr          $ra
    // 0x8005D078: nop

    return;
    // 0x8005D078: nop

;}
RECOMP_FUNC void func_80061708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061708: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006170C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061710: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061714: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061718: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006171C: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061720: nop

    // 0x80061724: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80061728: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8006172C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061730: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061734: nop

    // 0x80061738: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006173C: bne         $at, $zero, L_80061828
    if (ctx->r1 != 0) {
        // 0x80061740: nop
    
            goto L_80061828;
    }
    // 0x80061740: nop

L_80061744:
    // 0x80061744: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061748: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8006174C: nop

    // 0x80061750: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061754: bgez        $t2, L_80061764
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061758: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061764;
    }
    // 0x80061758: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8006175C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061760: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061764:
    // 0x80061764: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80061768: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8006176C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061770: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80061774: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x80061778: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8006177C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061780: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80061784: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061788: nop

    // 0x8006178C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061790: beq         $at, $zero, L_800617AC
    if (ctx->r1 == 0) {
        // 0x80061794: nop
    
            goto L_800617AC;
    }
    // 0x80061794: nop

    // 0x80061798: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006179C: nop

    // 0x800617A0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800617A4: b           L_80061810
    // 0x800617A8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061810;
    // 0x800617A8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_800617AC:
    // 0x800617AC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800617B0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800617B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800617B8: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x800617BC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800617C0: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800617C4: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x800617C8: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x800617CC: nop

    // 0x800617D0: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800617D4: beq         $at, $zero, L_800617F0
    if (ctx->r1 == 0) {
        // 0x800617D8: nop
    
            goto L_800617F0;
    }
    // 0x800617D8: nop

    // 0x800617DC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800617E0: nop

    // 0x800617E4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800617E8: b           L_80061810
    // 0x800617EC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061810;
    // 0x800617EC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800617F0:
    // 0x800617F0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800617F4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800617F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800617FC: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061800: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80061804: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061808: b           L_80061838
    // 0x8006180C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
        goto L_80061838;
    // 0x8006180C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
L_80061810:
    // 0x80061810: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80061814: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061818: nop

    // 0x8006181C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80061820: beq         $at, $zero, L_80061744
    if (ctx->r1 == 0) {
        // 0x80061824: nop
    
            goto L_80061744;
    }
    // 0x80061824: nop

L_80061828:
    // 0x80061828: b           L_80061838
    // 0x8006182C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061838;
    // 0x8006182C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061830: b           L_80061838
    // 0x80061834: nop

        goto L_80061838;
    // 0x80061834: nop

L_80061838:
    // 0x80061838: jr          $ra
    // 0x8006183C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006183C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800B1B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1B10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B1B14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1B18: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1B1C: jal         0x800B1E58
    // 0x800B1B20: nop

    func_800B1E58(rdram, ctx);
        goto after_0;
    // 0x800B1B20: nop

    after_0:
    // 0x800B1B24: b           L_800B1B2C
    // 0x800B1B28: nop

        goto L_800B1B2C;
    // 0x800B1B28: nop

L_800B1B2C:
    // 0x800B1B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1B34: jr          $ra
    // 0x800B1B38: nop

    return;
    // 0x800B1B38: nop

;}
RECOMP_FUNC void func_8005F0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F0E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005F0E8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005F0EC: nop

    // 0x8005F0F0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8005F0F4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005F0F8: nop

    // 0x8005F0FC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8005F100: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8005F104: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8005F108: nop

    // 0x8005F10C: bgez        $t9, L_8005F11C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005F110: sra         $t0, $t9, 3
        ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
            goto L_8005F11C;
    }
    // 0x8005F110: sra         $t0, $t9, 3
    ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8005F114: addiu       $at, $t9, 0x7
    ctx->r1 = ADD32(ctx->r25, 0X7);
    // 0x8005F118: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8005F11C:
    // 0x8005F11C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8005F120: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005F124: nop

    // 0x8005F128: bgez        $t1, L_8005F13C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005F12C: andi        $t2, $t1, 0x7
        ctx->r10 = ctx->r9 & 0X7;
            goto L_8005F13C;
    }
    // 0x8005F12C: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x8005F130: beq         $t2, $zero, L_8005F13C
    if (ctx->r10 == 0) {
        // 0x8005F134: nop
    
            goto L_8005F13C;
    }
    // 0x8005F134: nop

    // 0x8005F138: addiu       $t2, $t2, -0x8
    ctx->r10 = ADD32(ctx->r10, -0X8);
L_8005F13C:
    // 0x8005F13C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8005F140: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F144: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005F148: addiu       $t4, $t4, 0x680
    ctx->r12 = ADD32(ctx->r12, 0X680);
    // 0x8005F14C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005F150: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8005F154: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8005F158: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005F15C: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x8005F160: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x8005F164: sb          $t0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r8;
    // 0x8005F168: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005F16C: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x8005F170: beq         $t1, $at, L_8005F190
    if (ctx->r9 == ctx->r1) {
        // 0x8005F174: nop
    
            goto L_8005F190;
    }
    // 0x8005F174: nop

    // 0x8005F178: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8005F17C: beq         $t1, $at, L_8005F190
    if (ctx->r9 == ctx->r1) {
        // 0x8005F180: nop
    
            goto L_8005F190;
    }
    // 0x8005F180: nop

    // 0x8005F184: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x8005F188: bne         $t1, $at, L_8005F198
    if (ctx->r9 != ctx->r1) {
        // 0x8005F18C: nop
    
            goto L_8005F198;
    }
    // 0x8005F18C: nop

L_8005F190:
    // 0x8005F190: b           L_8005F258
    // 0x8005F194: nop

        goto L_8005F258;
    // 0x8005F194: nop

L_8005F198:
    // 0x8005F198: jal         0x8005F31C
    // 0x8005F19C: nop

    func_8005F31C(rdram, ctx);
        goto after_0;
    // 0x8005F19C: nop

    after_0:
    // 0x8005F1A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005F1A4: sb          $v0, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = ctx->r2;
    // 0x8005F1A8: jal         0x8005F064
    // 0x8005F1AC: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x8005F1AC: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    after_1:
    // 0x8005F1B0: bne         $v0, $zero, L_8005F1E0
    if (ctx->r2 != 0) {
        // 0x8005F1B4: nop
    
            goto L_8005F1E0;
    }
    // 0x8005F1B4: nop

    // 0x8005F1B8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005F1BC: lbu         $t2, 0x7208($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7208);
    // 0x8005F1C0: nop

    // 0x8005F1C4: slti        $at, $t2, 0x32
    ctx->r1 = SIGNED(ctx->r10) < 0X32 ? 1 : 0;
    // 0x8005F1C8: bne         $at, $zero, L_8005F1D8
    if (ctx->r1 != 0) {
        // 0x8005F1CC: nop
    
            goto L_8005F1D8;
    }
    // 0x8005F1CC: nop

    // 0x8005F1D0: jal         0x8005F0DC
    // 0x8005F1D4: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    func_8005F0DC(rdram, ctx);
        goto after_2;
    // 0x8005F1D4: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    after_2:
L_8005F1D8:
    // 0x8005F1D8: b           L_8005F258
    // 0x8005F1DC: nop

        goto L_8005F258;
    // 0x8005F1DC: nop

L_8005F1E0:
    // 0x8005F1E0: jal         0x8005F064
    // 0x8005F1E4: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    func_8005F064(rdram, ctx);
        goto after_3;
    // 0x8005F1E4: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    after_3:
    // 0x8005F1E8: bne         $v0, $zero, L_8005F218
    if (ctx->r2 != 0) {
        // 0x8005F1EC: nop
    
            goto L_8005F218;
    }
    // 0x8005F1EC: nop

    // 0x8005F1F0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005F1F4: lbu         $t3, 0x7208($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7208);
    // 0x8005F1F8: nop

    // 0x8005F1FC: slti        $at, $t3, 0x46
    ctx->r1 = SIGNED(ctx->r11) < 0X46 ? 1 : 0;
    // 0x8005F200: bne         $at, $zero, L_8005F210
    if (ctx->r1 != 0) {
        // 0x8005F204: nop
    
            goto L_8005F210;
    }
    // 0x8005F204: nop

    // 0x8005F208: jal         0x8005F0DC
    // 0x8005F20C: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    func_8005F0DC(rdram, ctx);
        goto after_4;
    // 0x8005F20C: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    after_4:
L_8005F210:
    // 0x8005F210: b           L_8005F258
    // 0x8005F214: nop

        goto L_8005F258;
    // 0x8005F214: nop

L_8005F218:
    // 0x8005F218: jal         0x8005F064
    // 0x8005F21C: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x8005F21C: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_5:
    // 0x8005F220: bne         $v0, $zero, L_8005F250
    if (ctx->r2 != 0) {
        // 0x8005F224: nop
    
            goto L_8005F250;
    }
    // 0x8005F224: nop

    // 0x8005F228: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005F22C: lbu         $t4, 0x7208($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7208);
    // 0x8005F230: nop

    // 0x8005F234: slti        $at, $t4, 0x64
    ctx->r1 = SIGNED(ctx->r12) < 0X64 ? 1 : 0;
    // 0x8005F238: bne         $at, $zero, L_8005F248
    if (ctx->r1 != 0) {
        // 0x8005F23C: nop
    
            goto L_8005F248;
    }
    // 0x8005F23C: nop

    // 0x8005F240: jal         0x8005F0DC
    // 0x8005F244: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_8005F0DC(rdram, ctx);
        goto after_6;
    // 0x8005F244: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_6:
L_8005F248:
    // 0x8005F248: b           L_8005F258
    // 0x8005F24C: nop

        goto L_8005F258;
    // 0x8005F24C: nop

L_8005F250:
    // 0x8005F250: b           L_8005F258
    // 0x8005F254: nop

        goto L_8005F258;
    // 0x8005F254: nop

L_8005F258:
    // 0x8005F258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F25C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F260: jr          $ra
    // 0x8005F264: nop

    return;
    // 0x8005F264: nop

;}
RECOMP_FUNC void func_80061348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061348: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006134C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061350: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061354: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061358: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006135C: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061360: nop

    // 0x80061364: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80061368: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8006136C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061370: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061374: nop

    // 0x80061378: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006137C: bne         $at, $zero, L_80061470
    if (ctx->r1 != 0) {
        // 0x80061380: nop
    
            goto L_80061470;
    }
    // 0x80061380: nop

L_80061384:
    // 0x80061384: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061388: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8006138C: nop

    // 0x80061390: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061394: bgez        $t2, L_800613A4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061398: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800613A4;
    }
    // 0x80061398: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8006139C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800613A0: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800613A4:
    // 0x800613A4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800613A8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800613AC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800613B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800613B4: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800613B8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800613BC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800613C0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800613C4: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800613C8: nop

    // 0x800613CC: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800613D0: beq         $at, $zero, L_800613EC
    if (ctx->r1 == 0) {
        // 0x800613D4: nop
    
            goto L_800613EC;
    }
    // 0x800613D4: nop

    // 0x800613D8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800613DC: nop

    // 0x800613E0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800613E4: b           L_80061458
    // 0x800613E8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061458;
    // 0x800613E8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_800613EC:
    // 0x800613EC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800613F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800613F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800613F8: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x800613FC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061400: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061404: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061408: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8006140C: nop

    // 0x80061410: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061414: beq         $at, $zero, L_80061430
    if (ctx->r1 == 0) {
        // 0x80061418: nop
    
            goto L_80061430;
    }
    // 0x80061418: nop

    // 0x8006141C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80061420: nop

    // 0x80061424: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80061428: b           L_80061458
    // 0x8006142C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061458;
    // 0x8006142C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80061430:
    // 0x80061430: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80061434: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80061438: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006143C: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061440: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80061444: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061448: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x8006144C: lbu         $v0, 0x2($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X2);
    // 0x80061450: b           L_80061480
    // 0x80061454: nop

        goto L_80061480;
    // 0x80061454: nop

L_80061458:
    // 0x80061458: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8006145C: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80061460: nop

    // 0x80061464: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061468: beq         $at, $zero, L_80061384
    if (ctx->r1 == 0) {
        // 0x8006146C: nop
    
            goto L_80061384;
    }
    // 0x8006146C: nop

L_80061470:
    // 0x80061470: b           L_80061480
    // 0x80061474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061480;
    // 0x80061474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80061478: b           L_80061480
    // 0x8006147C: nop

        goto L_80061480;
    // 0x8006147C: nop

L_80061480:
    // 0x80061480: jr          $ra
    // 0x80061484: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80061484: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
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
RECOMP_FUNC void func_800C0328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0328: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C032C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0330: lw          $t6, 0x47C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X47C);
    // 0x800C0334: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800C0338: bne         $t6, $at, L_800C035C
    if (ctx->r14 != ctx->r1) {
        // 0x800C033C: nop
    
            goto L_800C035C;
    }
    // 0x800C033C: nop

    // 0x800C0340: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0344: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800C0348: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C034C: lw          $t7, 0x44C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44C);
    // 0x800C0350: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0354: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C0358: sw          $t8, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r24;
L_800C035C:
    // 0x800C035C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800C0360: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C0364: lw          $t9, 0x44C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X44C);
    // 0x800C0368: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800C036C: lw          $t1, 0x47C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X47C);
    // 0x800C0370: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800C0374: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x800C0378: srav        $t3, $t2, $t1
    ctx->r11 = S32(SIGNED(ctx->r10) >> (ctx->r9 & 31));
    // 0x800C037C: and         $t4, $t0, $t3
    ctx->r12 = ctx->r8 & ctx->r11;
    // 0x800C0380: beq         $t4, $zero, L_800C0398
    if (ctx->r12 == 0) {
        // 0x800C0384: nop
    
            goto L_800C0398;
    }
    // 0x800C0384: nop

    // 0x800C0388: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C038C: nop

    // 0x800C0390: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800C0394: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_800C0398:
    // 0x800C0398: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C039C: lw          $t7, 0x47C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X47C);
    // 0x800C03A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C03A4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C03A8: sw          $t8, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = ctx->r24;
    // 0x800C03AC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800C03B0: b           L_800C03C0
    // 0x800C03B4: nop

        goto L_800C03C0;
    // 0x800C03B4: nop

    // 0x800C03B8: b           L_800C03C0
    // 0x800C03BC: nop

        goto L_800C03C0;
    // 0x800C03BC: nop

L_800C03C0:
    // 0x800C03C0: jr          $ra
    // 0x800C03C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C03C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006FA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FA1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FA20: jal         0x80061348
    // 0x8006FA24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FA24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FA28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FA2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FA30: b           L_8006FA40
    // 0x8006FA34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FA40;
    // 0x8006FA34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FA38: b           L_8006FA40
    // 0x8006FA3C: nop

        goto L_8006FA40;
    // 0x8006FA3C: nop

L_8006FA40:
    // 0x8006FA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FA44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FA48: jr          $ra
    // 0x8006FA4C: nop

    return;
    // 0x8006FA4C: nop

;}
RECOMP_FUNC void MtxUtil_PushCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1680: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1684: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1688: lw          $t6, 0xCD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCD8);
    // 0x800C168C: nop

    // 0x800C1690: bgtz        $t6, L_800C16A0
    if (SIGNED(ctx->r14) > 0) {
        // 0x800C1694: nop
    
            goto L_800C16A0;
    }
    // 0x800C1694: nop

    // 0x800C1698: b           L_800C174C
    // 0x800C169C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C174C;
    // 0x800C169C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C16A0:
    // 0x800C16A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C16A4: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C16A8: nop

    // 0x800C16AC: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C16B0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C16B4: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C16B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C16BC: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x800C16C0: sw          $t9, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r25;
    // 0x800C16C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C16C8: lw          $t0, 0xCE4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE4);
    // 0x800C16CC: nop

    // 0x800C16D0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800C16D4: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800C16D8: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_800C16DC:
    // 0x800C16DC: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C16E0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C16E4: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C16E8: nop

    // 0x800C16EC: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800C16F0: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C16F4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C16F8: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C16FC: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800C1700: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800C1704: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C1708: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C170C: nop

    // 0x800C1710: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C1714: bgtz        $t9, L_800C16DC
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C1718: sw          $t9, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r25;
            goto L_800C16DC;
    }
    // 0x800C1718: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C171C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C1720: lw          $t0, 0xCD8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCD8);
    // 0x800C1724: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1728: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800C172C: sw          $t1, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r9;
    // 0x800C1730: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800C1734: lw          $t2, 0xCD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD8);
    // 0x800C1738: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800C173C: b           L_800C174C
    // 0x800C1740: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
        goto L_800C174C;
    // 0x800C1740: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x800C1744: b           L_800C174C
    // 0x800C1748: nop

        goto L_800C174C;
    // 0x800C1748: nop

L_800C174C:
    // 0x800C174C: jr          $ra
    // 0x800C1750: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1750: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005EC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005EC58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005EC5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005EC60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005EC64: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x8005EC68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005EC6C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005EC70: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x8005EC74: nop

    // 0x8005EC78: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8005EC7C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8005EC80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EC84: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8005EC88: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005EC8C: jal         0x800BC6EC
    // 0x8005EC90: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8005EC90: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8005EC94: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005EC98: nop

    // 0x8005EC9C: sw          $v0, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->r2;
    // 0x8005ECA0: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8005ECA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005ECA8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8005ECAC: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x8005ECB0: nop

    // 0x8005ECB4: sll         $t0, $a0, 6
    ctx->r8 = S32(ctx->r4 << 6);
    // 0x8005ECB8: jal         0x800BC6EC
    // 0x8005ECBC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8005ECBC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x8005ECC0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005ECC4: nop

    // 0x8005ECC8: sw          $v0, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->r2;
    // 0x8005ECCC: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8005ECD0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8005ECD4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005ECD8: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x8005ECDC: lbu         $a2, -0x6230($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X6230);
    // 0x8005ECE0: addiu       $a0, $t2, 0x4C
    ctx->r4 = ADD32(ctx->r10, 0X4C);
    // 0x8005ECE4: jal         0x800B1B3C
    // 0x8005ECE8: addiu       $a1, $t2, 0x50
    ctx->r5 = ADD32(ctx->r10, 0X50);
    func_800B1B3C(rdram, ctx);
        goto after_2;
    // 0x8005ECE8: addiu       $a1, $t2, 0x50
    ctx->r5 = ADD32(ctx->r10, 0X50);
    after_2:
    // 0x8005ECEC: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8005ECF0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005ECF4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005ECF8: lbu         $t5, -0x6230($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X6230);
    // 0x8005ECFC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005ED00: blez        $t5, L_8005EF0C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005ED04: nop
    
            goto L_8005EF0C;
    }
    // 0x8005ED04: nop

L_8005ED08:
    // 0x8005ED08: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED0C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005ED14: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005ED18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005ED1C: lw          $t7, 0x4C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4C);
    // 0x8005ED20: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005ED24: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8005ED28: jal         0x80099E2C
    // 0x8005ED2C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x8005ED2C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_3:
    // 0x8005ED30: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED34: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED38: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005ED3C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005ED40: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005ED44: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8005ED48: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005ED4C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8005ED50: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8005ED54: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005ED58: swc1        $f4, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f4.u32l;
    // 0x8005ED5C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED60: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED64: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8005ED68: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005ED6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005ED70: lw          $t6, 0x4C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4C);
    // 0x8005ED74: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005ED78: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x8005ED7C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005ED80: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8005ED84: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8005ED88: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED8C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED90: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8005ED94: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8005ED98: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005ED9C: lw          $t2, 0x4C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EDA0: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8005EDA4: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8005EDA8: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8005EDAC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8005EDB0: swc1        $f8, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f8.u32l;
    // 0x8005EDB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EDB8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005EDBC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005EDC0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005EDC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EDC8: lw          $t8, 0x4C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4C);
    // 0x8005EDCC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005EDD0: lwc1        $f10, 0x20($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8005EDD4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005EDD8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8005EDDC: swc1        $f10, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f10.u32l;
    // 0x8005EDE0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EDE4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005EDE8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005EDEC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005EDF0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005EDF4: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EDF8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005EDFC: lwc1        $f16, 0x18($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8005EE00: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8005EE04: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005EE08: swc1        $f16, 0xF4($t4)
    MEM_W(0XF4, ctx->r12) = ctx->f16.u32l;
    // 0x8005EE0C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE10: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE14: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8005EE18: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005EE1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EE20: lw          $t6, 0x4C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4C);
    // 0x8005EE24: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005EE28: lwc1        $f18, 0x1C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8005EE2C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005EE30: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8005EE34: swc1        $f18, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f18.u32l;
    // 0x8005EE38: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE3C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE40: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005EE44: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8005EE48: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8005EE4C: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EE50: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8005EE54: lw          $t2, 0x40($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X40);
    // 0x8005EE58: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8005EE5C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8005EE60: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
    // 0x8005EE64: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE68: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE6C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005EE70: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8005EE74: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8005EE78: lw          $t7, 0x4C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4C);
    // 0x8005EE7C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8005EE80: lw          $t6, 0x3C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X3C);
    // 0x8005EE84: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8005EE88: addu        $t3, $t7, $t0
    ctx->r11 = ADD32(ctx->r15, ctx->r8);
    // 0x8005EE8C: sw          $t6, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r14;
    // 0x8005EE90: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE94: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE98: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8005EE9C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8005EEA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005EEA4: lw          $t2, 0x4C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4C);
    // 0x8005EEA8: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8005EEAC: lw          $t4, 0x38($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X38);
    // 0x8005EEB0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8005EEB4: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x8005EEB8: sw          $t4, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r12;
    // 0x8005EEBC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EEC0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005EEC4: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8005EEC8: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x8005EECC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8005EED0: lw          $t6, 0x4C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EED4: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x8005EED8: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8005EEDC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8005EEE0: addu        $t5, $t6, $t1
    ctx->r13 = ADD32(ctx->r14, ctx->r9);
    // 0x8005EEE4: sh          $t7, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r15;
    // 0x8005EEE8: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8005EEEC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8005EEF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EEF4: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8005EEF8: lbu         $t9, -0x6230($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6230);
    // 0x8005EEFC: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8005EF00: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8005EF04: bne         $at, $zero, L_8005ED08
    if (ctx->r1 != 0) {
        // 0x8005EF08: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_8005ED08;
    }
    // 0x8005EF08: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_8005EF0C:
    // 0x8005EF0C: b           L_8005EF14
    // 0x8005EF10: nop

        goto L_8005EF14;
    // 0x8005EF10: nop

L_8005EF14:
    // 0x8005EF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EF18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005EF1C: jr          $ra
    // 0x8005EF20: nop

    return;
    // 0x8005EF20: nop

;}
RECOMP_FUNC void func_800B35D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B35D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B35D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B35DC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B35E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B35E4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B35E8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B35EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B35F0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B35F4: nop

    // 0x800B35F8: bltz        $t6, L_800B360C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B35FC: nop
    
            goto L_800B360C;
    }
    // 0x800B35FC: nop

    // 0x800B3600: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800B3604: bne         $at, $zero, L_800B3614
    if (ctx->r1 != 0) {
        // 0x800B3608: nop
    
            goto L_800B3614;
    }
    // 0x800B3608: nop

L_800B360C:
    // 0x800B360C: b           L_800B3A14
    // 0x800B3610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3A14;
    // 0x800B3610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B3614:
    // 0x800B3614: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B3618: nop

    // 0x800B361C: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x800B3620: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800B3624: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B3628: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800B362C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800B3630: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800B3634: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800B3638: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B363C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B3640: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800B3644: nop

    // 0x800B3648: bne         $t3, $at, L_800B3658
    if (ctx->r11 != ctx->r1) {
        // 0x800B364C: nop
    
            goto L_800B3658;
    }
    // 0x800B364C: nop

    // 0x800B3650: b           L_800B3A14
    // 0x800B3654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3A14;
    // 0x800B3654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B3658:
    // 0x800B3658: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B365C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800B3660: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800B3664: lw          $t4, 0xD4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD4C);
    // 0x800B3668: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B366C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B3670: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B3674: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B3678: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B367C: jal         0x800BD1FC
    // 0x800B3680: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800B3680: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    after_0:
    // 0x800B3684: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B368C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B3690: jal         0x800BD218
    // 0x800B3694: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B3694: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800B3698: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B369C: nop

    // 0x800B36A0: addu        $t8, $sp, $t9
    ctx->r24 = ADD32(ctx->r29, ctx->r25);
    // 0x800B36A4: lbu         $t8, 0x3C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3C);
    // 0x800B36A8: nop

    // 0x800B36AC: bne         $t8, $zero, L_800B36BC
    if (ctx->r24 != 0) {
        // 0x800B36B0: nop
    
            goto L_800B36BC;
    }
    // 0x800B36B0: nop

    // 0x800B36B4: b           L_800B3A14
    // 0x800B36B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B3A14;
    // 0x800B36B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B36BC:
    // 0x800B36BC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800B36C0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800B36C4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800B36C8: blez        $t0, L_800B3708
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B36CC: nop
    
            goto L_800B3708;
    }
    // 0x800B36CC: nop

L_800B36D0:
    // 0x800B36D0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B36D4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B36D8: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x800B36DC: lbu         $t3, 0x3C($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3C);
    // 0x800B36E0: nop

    // 0x800B36E4: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x800B36E8: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x800B36EC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800B36F0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B36F4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B36F8: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x800B36FC: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B3700: bne         $at, $zero, L_800B36D0
    if (ctx->r1 != 0) {
        // 0x800B3704: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_800B36D0;
    }
    // 0x800B3704: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_800B3708:
    // 0x800B3708: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800B370C: nop

    // 0x800B3710: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x800B3714: lbu         $t0, 0x3C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3C);
    // 0x800B3718: nop

    // 0x800B371C: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800B3720: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B3724: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B3728: jal         0x800BC6EC
    // 0x800B372C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800B372C: nop

    after_2:
    // 0x800B3730: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B3734: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B3738: lw          $t3, 0xD50($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD50);
    // 0x800B373C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B3740: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3744: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B3748: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B374C: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B3750: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B3754: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x800B3758: jal         0x800BD1FC
    // 0x800B375C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x800B375C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    after_3:
    // 0x800B3760: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3764: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B3768: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800B376C: jal         0x800BD218
    // 0x800B3770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x800B3770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800B3774: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800B3778: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800B377C: addu        $t7, $sp, $t4
    ctx->r15 = ADD32(ctx->r29, ctx->r12);
    // 0x800B3780: lbu         $t7, 0x3C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3C);
    // 0x800B3784: nop

    // 0x800B3788: blez        $t7, L_800B39E8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B378C: nop
    
            goto L_800B39E8;
    }
    // 0x800B378C: nop

L_800B3790:
    // 0x800B3790: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B3794: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800B3798: lhu         $t8, 0xA($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0XA);
    // 0x800B379C: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800B37A0: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x800B37A4: andi        $t1, $t3, 0x1
    ctx->r9 = ctx->r11 & 0X1;
    // 0x800B37A8: xor         $t5, $t0, $t1
    ctx->r13 = ctx->r8 ^ ctx->r9;
    // 0x800B37AC: bne         $t5, $zero, L_800B3830
    if (ctx->r13 != 0) {
        // 0x800B37B0: nop
    
            goto L_800B3830;
    }
    // 0x800B37B0: nop

    // 0x800B37B4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B37B8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B37BC: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x800B37C0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B37C4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800B37C8: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x800B37CC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B37D0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800B37D4: lwc1        $f8, 0xCC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x800B37D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B37DC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B37E0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x800B37E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B37E8: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B37EC: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800B37F0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B37F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B37F8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800B37FC: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B3800: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x800B3804: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x800B3808: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B380C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800B3810: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B3814: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B3818: lwc1        $f4, 0xCC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800B381C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800B3820: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B3824: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3828: b           L_800B38A8
    // 0x800B382C: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
        goto L_800B38A8;
    // 0x800B382C: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
L_800B3830:
    // 0x800B3830: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B3834: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B3838: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B383C: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x800B3840: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x800B3844: lh          $t7, 0x4($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X4);
    // 0x800B3848: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B384C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B3850: lwc1        $f16, 0xCC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800B3854: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3858: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B385C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800B3860: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800B3864: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3868: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x800B386C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B3870: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B3874: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800B3878: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800B387C: addu        $t7, $t4, $t3
    ctx->r15 = ADD32(ctx->r12, ctx->r11);
    // 0x800B3880: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x800B3884: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B3888: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B388C: lwc1        $f8, 0xCC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x800B3890: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3894: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B3898: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x800B389C: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B38A0: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x800B38A4: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
L_800B38A8:
    // 0x800B38A8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B38AC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B38B0: lhu         $t4, 0xA($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0XA);
    // 0x800B38B4: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800B38B8: andi        $t3, $t4, 0x2
    ctx->r11 = ctx->r12 & 0X2;
    // 0x800B38BC: andi        $t8, $t9, 0x2
    ctx->r24 = ctx->r25 & 0X2;
    // 0x800B38C0: xor         $t2, $t3, $t8
    ctx->r10 = ctx->r11 ^ ctx->r24;
    // 0x800B38C4: bne         $t2, $zero, L_800B3948
    if (ctx->r10 != 0) {
        // 0x800B38C8: nop
    
            goto L_800B3948;
    }
    // 0x800B38C8: nop

    // 0x800B38CC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B38D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B38D4: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x800B38D8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800B38DC: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x800B38E0: lh          $t7, 0x2($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2);
    // 0x800B38E4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B38E8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800B38EC: lwc1        $f4, 0xD0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x800B38F0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B38F4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B38F8: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800B38FC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B3900: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B3904: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x800B3908: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B390C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B3910: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x800B3914: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x800B3918: addu        $t7, $t1, $t4
    ctx->r15 = ADD32(ctx->r9, ctx->r12);
    // 0x800B391C: lh          $t9, 0x6($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X6);
    // 0x800B3920: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B3924: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800B3928: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B392C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B3930: lwc1        $f10, 0xD0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x800B3934: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B3938: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B393C: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B3940: b           L_800B39C0
    // 0x800B3944: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
        goto L_800B39C0;
    // 0x800B3944: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
L_800B3948:
    // 0x800B3948: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B394C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B3950: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800B3954: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800B3958: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x800B395C: lh          $t5, 0x6($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X6);
    // 0x800B3960: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B3964: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B3968: lwc1        $f6, 0xD0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x800B396C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3970: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B3974: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B3978: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B397C: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B3980: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x800B3984: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B3988: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B398C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800B3990: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B3994: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x800B3998: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800B399C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B39A0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800B39A4: lwc1        $f4, 0xD0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x800B39A8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B39AC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B39B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B39B4: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800B39B8: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x800B39BC: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
L_800B39C0:
    // 0x800B39C0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B39C4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B39C8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B39CC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800B39D0: addu        $t5, $sp, $t9
    ctx->r13 = ADD32(ctx->r29, ctx->r25);
    // 0x800B39D4: lbu         $t5, 0x3C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3C);
    // 0x800B39D8: nop

    // 0x800B39DC: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B39E0: bne         $at, $zero, L_800B3790
    if (ctx->r1 != 0) {
        // 0x800B39E4: nop
    
            goto L_800B3790;
    }
    // 0x800B39E4: nop

L_800B39E8:
    // 0x800B39E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800B39EC: jal         0x800BC980
    // 0x800B39F0: nop

    SysMem_Free(rdram, ctx);
        goto after_5;
    // 0x800B39F0: nop

    after_5:
    // 0x800B39F4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B39F8: nop

    // 0x800B39FC: addu        $v0, $sp, $t6
    ctx->r2 = ADD32(ctx->r29, ctx->r14);
    // 0x800B3A00: lbu         $v0, 0x3C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3C);
    // 0x800B3A04: b           L_800B3A14
    // 0x800B3A08: nop

        goto L_800B3A14;
    // 0x800B3A08: nop

    // 0x800B3A0C: b           L_800B3A14
    // 0x800B3A10: nop

        goto L_800B3A14;
    // 0x800B3A10: nop

L_800B3A14:
    // 0x800B3A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B3A1C: jr          $ra
    // 0x800B3A20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B3A20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80091A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091A0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80091A10: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80091A14: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80091A18:
    // 0x80091A18: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80091A1C: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x80091A20: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80091A24: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80091A28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091A2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80091A30: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80091A34: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80091A38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80091A3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091A40: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80091A44: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80091A48: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091A4C: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80091A50: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80091A54: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80091A58: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x80091A5C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80091A60: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80091A64: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80091A68: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091A6C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80091A70: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80091A74: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80091A78: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80091A7C: nop

    // 0x80091A80: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80091A84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091A88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80091A8C: nop

    // 0x80091A90: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80091A94: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80091A98: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80091A9C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80091AA0: nop

    // 0x80091AA4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80091AA8: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80091AAC: nop

    // 0x80091AB0: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80091AB4: beq         $t3, $zero, L_80091AE4
    if (ctx->r11 == 0) {
        // 0x80091AB8: nop
    
            goto L_80091AE4;
    }
    // 0x80091AB8: nop

    // 0x80091ABC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80091AC0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80091AC4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80091AC8: lw          $t8, -0x798($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X798);
    // 0x80091ACC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80091AD0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80091AD4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80091AD8: lbu         $t0, -0x100($t9)
    ctx->r8 = MEM_BU(ctx->r25, -0X100);
    // 0x80091ADC: b           L_80091B0C
    // 0x80091AE0: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
        goto L_80091B0C;
    // 0x80091AE0: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
L_80091AE4:
    // 0x80091AE4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80091AE8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80091AEC: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80091AF0: lw          $t5, -0x7F0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7F0);
    // 0x80091AF4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80091AF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80091AFC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80091B00: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80091B04: nop

    // 0x80091B08: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
L_80091B0C:
    // 0x80091B0C: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091B10: nop

    // 0x80091B14: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x80091B18: beq         $t9, $zero, L_80091B48
    if (ctx->r25 == 0) {
        // 0x80091B1C: nop
    
            goto L_80091B48;
    }
    // 0x80091B1C: nop

    // 0x80091B20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091B24: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091B28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091B2C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091B30: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091B34: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091B38: jal         0x80090784
    // 0x80091B3C: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80091B3C: nop

    after_0:
    // 0x80091B40: b           L_80091B68
    // 0x80091B44: nop

        goto L_80091B68;
    // 0x80091B44: nop

L_80091B48:
    // 0x80091B48: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091B4C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091B50: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091B54: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091B58: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091B5C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091B60: jal         0x80090784
    // 0x80091B64: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80091B64: nop

    after_1:
L_80091B68:
    // 0x80091B68: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091B6C: nop

    // 0x80091B70: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x80091B74: beq         $t1, $zero, L_80091BA4
    if (ctx->r9 == 0) {
        // 0x80091B78: nop
    
            goto L_80091BA4;
    }
    // 0x80091B78: nop

    // 0x80091B7C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091B80: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091B84: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091B88: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091B8C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091B90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091B94: jal         0x80090784
    // 0x80091B98: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x80091B98: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80091B9C: b           L_80091BC4
    // 0x80091BA0: nop

        goto L_80091BC4;
    // 0x80091BA0: nop

L_80091BA4:
    // 0x80091BA4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091BA8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091BAC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091BB0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091BB4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091BB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091BBC: jal         0x80090784
    // 0x80091BC0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x80091BC0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_80091BC4:
    // 0x80091BC4: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091BC8: nop

    // 0x80091BCC: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80091BD0: beq         $t3, $zero, L_80091C00
    if (ctx->r11 == 0) {
        // 0x80091BD4: nop
    
            goto L_80091C00;
    }
    // 0x80091BD4: nop

    // 0x80091BD8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091BDC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091BE0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091BE4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091BE8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091BEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091BF0: jal         0x80090784
    // 0x80091BF4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80091BF4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80091BF8: b           L_80091C20
    // 0x80091BFC: nop

        goto L_80091C20;
    // 0x80091BFC: nop

L_80091C00:
    // 0x80091C00: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C04: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C08: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C0C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091C10: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091C14: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091C18: jal         0x80090784
    // 0x80091C1C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80091C1C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80091C20:
    // 0x80091C20: lbu         $t4, 0x1F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091C24: nop

    // 0x80091C28: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80091C2C: beq         $t5, $zero, L_80091C5C
    if (ctx->r13 == 0) {
        // 0x80091C30: nop
    
            goto L_80091C5C;
    }
    // 0x80091C30: nop

    // 0x80091C34: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C38: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C3C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C40: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091C44: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091C48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091C4C: jal         0x80090784
    // 0x80091C50: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80091C50: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80091C54: b           L_80091C7C
    // 0x80091C58: nop

        goto L_80091C7C;
    // 0x80091C58: nop

L_80091C5C:
    // 0x80091C5C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C60: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C64: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C68: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091C6C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091C70: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091C74: jal         0x80090784
    // 0x80091C78: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x80091C78: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80091C7C:
    // 0x80091C7C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091C80: nop

    // 0x80091C84: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80091C88: beq         $t7, $zero, L_80091CB8
    if (ctx->r15 == 0) {
        // 0x80091C8C: nop
    
            goto L_80091CB8;
    }
    // 0x80091C8C: nop

    // 0x80091C90: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C94: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C98: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C9C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091CA0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091CA4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091CA8: jal         0x80090784
    // 0x80091CAC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x80091CAC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x80091CB0: b           L_80091CD8
    // 0x80091CB4: nop

        goto L_80091CD8;
    // 0x80091CB4: nop

L_80091CB8:
    // 0x80091CB8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091CBC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091CC0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091CC4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091CC8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091CCC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091CD0: jal         0x80090784
    // 0x80091CD4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x80091CD4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_80091CD8:
    // 0x80091CD8: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091CDC: nop

    // 0x80091CE0: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80091CE4: beq         $t9, $zero, L_80091D14
    if (ctx->r25 == 0) {
        // 0x80091CE8: nop
    
            goto L_80091D14;
    }
    // 0x80091CE8: nop

    // 0x80091CEC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091CF0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091CF4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091CF8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091CFC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091D00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D04: jal         0x80090784
    // 0x80091D08: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x80091D08: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x80091D0C: b           L_80091D34
    // 0x80091D10: nop

        goto L_80091D34;
    // 0x80091D10: nop

L_80091D14:
    // 0x80091D14: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091D18: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091D1C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091D20: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091D24: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091D28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D2C: jal         0x80090784
    // 0x80091D30: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80091D30: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80091D34:
    // 0x80091D34: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091D38: nop

    // 0x80091D3C: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80091D40: beq         $t1, $zero, L_80091D70
    if (ctx->r9 == 0) {
        // 0x80091D44: nop
    
            goto L_80091D70;
    }
    // 0x80091D44: nop

    // 0x80091D48: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091D4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091D50: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091D54: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091D58: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091D5C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D60: jal         0x80090784
    // 0x80091D64: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80091D64: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x80091D68: b           L_80091D90
    // 0x80091D6C: nop

        goto L_80091D90;
    // 0x80091D6C: nop

L_80091D70:
    // 0x80091D70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091D74: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091D78: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091D7C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091D80: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091D84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D88: jal         0x80090784
    // 0x80091D8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80091D8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80091D90:
    // 0x80091D90: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091D94: nop

    // 0x80091D98: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80091D9C: beq         $t3, $zero, L_80091DCC
    if (ctx->r11 == 0) {
        // 0x80091DA0: nop
    
            goto L_80091DCC;
    }
    // 0x80091DA0: nop

    // 0x80091DA4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091DA8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091DAC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091DB0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091DB4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091DB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091DBC: jal         0x80090784
    // 0x80091DC0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x80091DC0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x80091DC4: b           L_80091DEC
    // 0x80091DC8: nop

        goto L_80091DEC;
    // 0x80091DC8: nop

L_80091DCC:
    // 0x80091DCC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091DD0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091DD4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091DD8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091DDC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091DE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091DE4: jal         0x80090784
    // 0x80091DE8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x80091DE8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_80091DEC:
    // 0x80091DEC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80091DF0: nop

    // 0x80091DF4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80091DF8: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80091DFC: bne         $at, $zero, L_80091A18
    if (ctx->r1 != 0) {
        // 0x80091E00: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80091A18;
    }
    // 0x80091E00: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80091E04: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80091E08: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x80091E0C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80091E10: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091E14: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80091E18: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x80091E1C: b           L_80091E24
    // 0x80091E20: nop

        goto L_80091E24;
    // 0x80091E20: nop

L_80091E24:
    // 0x80091E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091E28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80091E2C: jr          $ra
    // 0x80091E30: nop

    return;
    // 0x80091E30: nop

;}
RECOMP_FUNC void func_80065650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065650: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065654: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065658: nop

    // 0x8006565C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80065660: nop

    // 0x80065664: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80065668: jr          $ra
    // 0x8006566C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006566C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065670: jr          $ra
    // 0x80065674: nop

    return;
    // 0x80065674: nop

    // 0x80065678: jr          $ra
    // 0x8006567C: nop

    return;
    // 0x8006567C: nop

;}
RECOMP_FUNC void func_8006E7BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E7BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E7C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E7C4: jal         0x80061348
    // 0x8006E7C8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E7C8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E7CC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E7D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E7D4: beq         $v0, $zero, L_8006E7EC
    if (ctx->r2 == 0) {
        // 0x8006E7D8: nop
    
            goto L_8006E7EC;
    }
    // 0x8006E7D8: nop

    // 0x8006E7DC: jal         0x80061348
    // 0x8006E7E0: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E7E0: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    after_1:
    // 0x8006E7E4: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E7E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E7EC:
    // 0x8006E7EC: b           L_8006E7FC
    // 0x8006E7F0: nop

        goto L_8006E7FC;
    // 0x8006E7F0: nop

    // 0x8006E7F4: b           L_8006E7FC
    // 0x8006E7F8: nop

        goto L_8006E7FC;
    // 0x8006E7F8: nop

L_8006E7FC:
    // 0x8006E7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E804: jr          $ra
    // 0x8006E808: nop

    return;
    // 0x8006E808: nop

;}
RECOMP_FUNC void func_800729D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800729D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800729D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800729DC: jal         0x80061488
    // 0x800729E0: addiu       $a0, $zero, 0x523
    ctx->r4 = ADD32(0, 0X523);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800729E0: addiu       $a0, $zero, 0x523
    ctx->r4 = ADD32(0, 0X523);
    after_0:
    // 0x800729E4: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800729E8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800729EC: b           L_800729FC
    // 0x800729F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800729FC;
    // 0x800729F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800729F4: b           L_800729FC
    // 0x800729F8: nop

        goto L_800729FC;
    // 0x800729F8: nop

L_800729FC:
    // 0x800729FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072A04: jr          $ra
    // 0x80072A08: nop

    return;
    // 0x80072A08: nop

;}
RECOMP_FUNC void func_80057714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057714: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80057718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005771C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80057720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057724: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80057728: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8005772C: nop

    // 0x80057730: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80057734: nop

    // 0x80057738: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8005773C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80057740: nop

    // 0x80057744: bne         $t8, $zero, L_80057754
    if (ctx->r24 != 0) {
        // 0x80057748: nop
    
            goto L_80057754;
    }
    // 0x80057748: nop

    // 0x8005774C: b           L_800578D8
    // 0x80057750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800578D8;
    // 0x80057750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057754:
    // 0x80057754: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80057758: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8005775C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80057760: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80057764: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057768: bne         $t0, $at, L_80057780
    if (ctx->r8 != ctx->r1) {
        // 0x8005776C: nop
    
            goto L_80057780;
    }
    // 0x8005776C: nop

    // 0x80057770: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x80057774: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057778: beq         $t1, $at, L_80057848
    if (ctx->r9 == ctx->r1) {
        // 0x8005777C: nop
    
            goto L_80057848;
    }
    // 0x8005777C: nop

L_80057780:
    // 0x80057780: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80057784: nop

    // 0x80057788: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x8005778C: nop

    // 0x80057790: andi        $t4, $t3, 0xFF00
    ctx->r12 = ctx->r11 & 0XFF00;
    // 0x80057794: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80057798: bne         $t5, $zero, L_80057810
    if (ctx->r13 != 0) {
        // 0x8005779C: nop
    
            goto L_80057810;
    }
    // 0x8005779C: nop

    // 0x800577A0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800577A4: nop

    // 0x800577A8: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x800577AC: nop

    // 0x800577B0: sra         $t7, $a0, 2
    ctx->r15 = S32(SIGNED(ctx->r4) >> 2);
    // 0x800577B4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800577B8: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800577BC: jal         0x80056D28
    // 0x800577C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80056D28(rdram, ctx);
        goto after_0;
    // 0x800577C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800577C4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800577C8: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800577CC: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800577D0: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800577D4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800577D8: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800577DC: lh          $t1, 0x2C5E($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2C5E);
    // 0x800577E0: nop

    // 0x800577E4: beq         $t1, $zero, L_80057810
    if (ctx->r9 == 0) {
        // 0x800577E8: nop
    
            goto L_80057810;
    }
    // 0x800577E8: nop

    // 0x800577EC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800577F0: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800577F4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800577F8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800577FC: sw          $t2, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r10;
    // 0x80057800: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80057804: nop

    // 0x80057808: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005780C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
L_80057810:
    // 0x80057810: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80057814: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80057818: addiu       $t0, $t8, 0x10
    ctx->r8 = ADD32(ctx->r24, 0X10);
    // 0x8005781C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80057820: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x80057824: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80057828: lhu         $t3, 0x0($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X0);
    // 0x8005782C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057830: bne         $t3, $at, L_80057780
    if (ctx->r11 != ctx->r1) {
        // 0x80057834: nop
    
            goto L_80057780;
    }
    // 0x80057834: nop

    // 0x80057838: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x8005783C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80057840: bne         $t2, $at, L_80057780
    if (ctx->r10 != ctx->r1) {
        // 0x80057844: nop
    
            goto L_80057780;
    }
    // 0x80057844: nop

L_80057848:
    // 0x80057848: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8005784C: nop

    // 0x80057850: bne         $t4, $zero, L_80057860
    if (ctx->r12 != 0) {
        // 0x80057854: nop
    
            goto L_80057860;
    }
    // 0x80057854: nop

    // 0x80057858: b           L_800578D8
    // 0x8005785C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800578D8;
    // 0x8005785C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057860:
    // 0x80057860: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80057864: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x80057868: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8005786C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80057870: divu        $zero, $t5, $t6
    lo = S32(U32(ctx->r13) / U32(ctx->r14)); hi = S32(U32(ctx->r13) % U32(ctx->r14));
    // 0x80057874: bne         $t6, $zero, L_80057880
    if (ctx->r14 != 0) {
        // 0x80057878: nop
    
            goto L_80057880;
    }
    // 0x80057878: nop

    // 0x8005787C: break       7
    do_break(2147842172);
L_80057880:
    // 0x80057880: mfhi        $t7
    ctx->r15 = hi;
    // 0x80057884: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80057888: addu        $a1, $sp, $t8
    ctx->r5 = ADD32(ctx->r29, ctx->r24);
    // 0x8005788C: lw          $a1, 0x28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X28);
    // 0x80057890: jal         0x8007959C
    // 0x80057894: nop

    func_8007959C(rdram, ctx);
        goto after_1;
    // 0x80057894: nop

    after_1:
    // 0x80057898: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005789C: nop

    // 0x800578A0: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x800578A4: nop

    // 0x800578A8: beq         $t1, $zero, L_800578C4
    if (ctx->r9 == 0) {
        // 0x800578AC: nop
    
            goto L_800578C4;
    }
    // 0x800578AC: nop

    // 0x800578B0: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x800578B4: nop

    // 0x800578B8: lw          $a0, 0x18($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X18);
    // 0x800578BC: jal         0x800BC980
    // 0x800578C0: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800578C0: nop

    after_2:
L_800578C4:
    // 0x800578C4: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x800578C8: b           L_800578D8
    // 0x800578CC: nop

        goto L_800578D8;
    // 0x800578CC: nop

    // 0x800578D0: b           L_800578D8
    // 0x800578D4: nop

        goto L_800578D8;
    // 0x800578D4: nop

L_800578D8:
    // 0x800578D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800578DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800578E0: jr          $ra
    // 0x800578E4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800578E4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8007581C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007581C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075824: jal         0x80061348
    // 0x80075828: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075828: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x8007582C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075830: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075834: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075838: beq         $v0, $zero, L_8007588C
    if (ctx->r2 == 0) {
        // 0x8007583C: nop
    
            goto L_8007588C;
    }
    // 0x8007583C: nop

    // 0x80075840: jal         0x80061348
    // 0x80075844: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075844: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075848: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007584C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075850: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075854: beq         $v0, $zero, L_8007588C
    if (ctx->r2 == 0) {
        // 0x80075858: nop
    
            goto L_8007588C;
    }
    // 0x80075858: nop

    // 0x8007585C: jal         0x80061348
    // 0x80075860: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075860: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x80075864: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075868: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007586C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075870: beq         $v0, $zero, L_8007588C
    if (ctx->r2 == 0) {
        // 0x80075874: nop
    
            goto L_8007588C;
    }
    // 0x80075874: nop

    // 0x80075878: jal         0x80061348
    // 0x8007587C: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007587C: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075880: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075884: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075888: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007588C:
    // 0x8007588C: b           L_8007589C
    // 0x80075890: nop

        goto L_8007589C;
    // 0x80075890: nop

    // 0x80075894: b           L_8007589C
    // 0x80075898: nop

        goto L_8007589C;
    // 0x80075898: nop

L_8007589C:
    // 0x8007589C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800758A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800758A4: jr          $ra
    // 0x800758A8: nop

    return;
    // 0x800758A8: nop

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
RECOMP_FUNC void alSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63BC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800D63C0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D63C4: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x800D63C8: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x800D63CC: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x800D63D0: jr          $ra
    // 0x800D63D4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x800D63D4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_800C1154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C1158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C115C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C1160: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C1164: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800C1168: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C116C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1170: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1174: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1178: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C117C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1180: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1184: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1188: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800C118C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C1190: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C1194: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1198: nop

    // 0x800C119C: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800C11A0: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800C11A4: nop

    // 0x800C11A8: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800C11AC: bne         $t2, $zero, L_800C11BC
    if (ctx->r10 != 0) {
        // 0x800C11B0: nop
    
            goto L_800C11BC;
    }
    // 0x800C11B0: nop

    // 0x800C11B4: b           L_800C1254
    // 0x800C11B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1254;
    // 0x800C11B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C11BC:
    // 0x800C11BC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C11C0: nop

    // 0x800C11C4: slti        $at, $t3, 0x9
    ctx->r1 = SIGNED(ctx->r11) < 0X9 ? 1 : 0;
    // 0x800C11C8: bne         $at, $zero, L_800C11D8
    if (ctx->r1 != 0) {
        // 0x800C11CC: nop
    
            goto L_800C11D8;
    }
    // 0x800C11CC: nop

    // 0x800C11D0: b           L_800C1254
    // 0x800C11D4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800C1254;
    // 0x800C11D4: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800C11D8:
    // 0x800C11D8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800C11DC: nop

    // 0x800C11E0: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x800C11E4: lbu         $t5, 0x2EA($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2EA);
    // 0x800C11E8: nop

    // 0x800C11EC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800C11F0: beq         $t6, $zero, L_800C120C
    if (ctx->r14 == 0) {
        // 0x800C11F4: nop
    
            goto L_800C120C;
    }
    // 0x800C11F4: nop

    // 0x800C11F8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800C11FC: jal         0x800C13B8
    // 0x800C1200: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_0;
    // 0x800C1200: nop

    after_0:
    // 0x800C1204: b           L_800C1254
    // 0x800C1208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1254;
    // 0x800C1208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C120C:
    // 0x800C120C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1210: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C1214: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    // 0x800C1218: ori         $at, $zero, 0x82B0
    ctx->r1 = 0 | 0X82B0;
    // 0x800C121C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C1220: jal         0x800C42B0
    // 0x800C1224: addu        $a1, $t7, $at
    ctx->r5 = ADD32(ctx->r15, ctx->r1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800C1224: addu        $a1, $t7, $at
    ctx->r5 = ADD32(ctx->r15, ctx->r1);
    after_1:
    // 0x800C1228: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C122C: nop

    // 0x800C1230: addiu       $t9, $t8, 0x7FFF
    ctx->r25 = ADD32(ctx->r24, 0X7FFF);
    // 0x800C1234: lbu         $t9, 0x2EA($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2EA);
    // 0x800C1238: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x800C123C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800C1240: sb          $t0, 0x2EA($at)
    MEM_B(0X2EA, ctx->r1) = ctx->r8;
    // 0x800C1244: b           L_800C1254
    // 0x800C1248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1254;
    // 0x800C1248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C124C: b           L_800C1254
    // 0x800C1250: nop

        goto L_800C1254;
    // 0x800C1250: nop

L_800C1254:
    // 0x800C1254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C125C: jr          $ra
    // 0x800C1260: nop

    return;
    // 0x800C1260: nop

;}
RECOMP_FUNC void func_80076580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076588: jal         0x80061488
    // 0x8007658C: addiu       $a0, $zero, 0x46F
    ctx->r4 = ADD32(0, 0X46F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007658C: addiu       $a0, $zero, 0x46F
    ctx->r4 = ADD32(0, 0X46F);
    after_0:
    // 0x80076590: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076594: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076598: b           L_800765A8
    // 0x8007659C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800765A8;
    // 0x8007659C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800765A0: b           L_800765A8
    // 0x800765A4: nop

        goto L_800765A8;
    // 0x800765A4: nop

L_800765A8:
    // 0x800765A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800765AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800765B0: jr          $ra
    // 0x800765B4: nop

    return;
    // 0x800765B4: nop

;}
RECOMP_FUNC void func_80063074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006307C: jal         0x80061488
    // 0x80063080: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063080: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063084: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80063088: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006308C: b           L_8006309C
    // 0x80063090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006309C;
    // 0x80063090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063094: b           L_8006309C
    // 0x80063098: nop

        goto L_8006309C;
    // 0x80063098: nop

L_8006309C:
    // 0x8006309C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800630A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800630A4: jr          $ra
    // 0x800630A8: nop

    return;
    // 0x800630A8: nop

;}
RECOMP_FUNC void func_800630AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800630AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800630B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800630B4: jal         0x8005F064
    // 0x800630B8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800630B8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_0:
    // 0x800630BC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800630C0: b           L_800630D0
    // 0x800630C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800630D0;
    // 0x800630C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800630C8: b           L_800630D0
    // 0x800630CC: nop

        goto L_800630D0;
    // 0x800630CC: nop

L_800630D0:
    // 0x800630D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800630D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800630D8: jr          $ra
    // 0x800630DC: nop

    return;
    // 0x800630DC: nop

;}
RECOMP_FUNC void func_80043F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043F14: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80043F18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043F1C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80043F20: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80043F24: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80043F28: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80043F2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043F30: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80043F34: nop

    // 0x80043F38: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80043F3C: nop

    // 0x80043F40: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80043F44: lhu         $t8, 0x52($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X52);
    // 0x80043F48: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80043F4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80043F50: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80043F54: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80043F58: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80043F5C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80043F60: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043F64: mflo        $t1
    ctx->r9 = lo;
    // 0x80043F68: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80043F6C: jal         0x800BC6EC
    // 0x80043F70: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80043F70: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x80043F74: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80043F78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80043F7C: sw          $s0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r16;
    // 0x80043F80: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80043F84: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80043F88: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80043F8C: blez        $t3, L_80043FC8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80043F90: nop
    
            goto L_80043FC8;
    }
    // 0x80043F90: nop

L_80043F94:
    // 0x80043F94: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80043F98: nop

    // 0x80043F9C: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x80043FA0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80043FA4: nop

    // 0x80043FA8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80043FAC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80043FB0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80043FB4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80043FB8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80043FBC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80043FC0: bne         $at, $zero, L_80043F94
    if (ctx->r1 != 0) {
        // 0x80043FC4: sw          $t8, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r24;
            goto L_80043F94;
    }
    // 0x80043FC4: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
L_80043FC8:
    // 0x80043FC8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80043FCC: nop

    // 0x80043FD0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80043FD4: nop

    // 0x80043FD8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80043FDC: lhu         $t2, 0x56($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X56);
    // 0x80043FE0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80043FE4: blez        $t2, L_80044230
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80043FE8: nop
    
            goto L_80044230;
    }
    // 0x80043FE8: nop

L_80043FEC:
    // 0x80043FEC: lhu         $t3, 0x52($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X52);
    // 0x80043FF0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80043FF4: blez        $t3, L_80044218
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80043FF8: nop
    
            goto L_80044218;
    }
    // 0x80043FF8: nop

L_80043FFC:
    // 0x80043FFC: lhu         $t4, 0x56($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X56);
    // 0x80044000: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80044004: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80044008: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004400C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80044010: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044014: mflo        $t6
    ctx->r14 = lo;
    // 0x80044018: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8004401C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80044020: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80044024: nop

    // 0x80044028: beq         $t1, $at, L_80044200
    if (ctx->r9 == ctx->r1) {
        // 0x8004402C: sb          $t1, 0x3A($sp)
        MEM_B(0X3A, ctx->r29) = ctx->r9;
            goto L_80044200;
    }
    // 0x8004402C: sb          $t1, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r9;
    // 0x80044030: lbu         $t3, 0x3A($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3A);
    // 0x80044034: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80044038: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8004403C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80044040: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80044044: nop

    // 0x80044048: beq         $t6, $zero, L_80044200
    if (ctx->r14 == 0) {
        // 0x8004404C: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80044200;
    }
    // 0x8004404C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80044050: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80044054: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80044058: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x8004405C: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80044060: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80044064: jal         0x800BD1FC
    // 0x80044068: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x80044068: nop

    after_1:
    // 0x8004406C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80044070: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80044074: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x80044078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004407C: jal         0x800BD218
    // 0x80044080: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x80044080: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_2:
    // 0x80044084: lhu         $t7, 0x52($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X52);
    // 0x80044088: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8004408C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80044090: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044094: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80044098: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8004409C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800440A0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800440A4: mflo        $t9
    ctx->r25 = lo;
    // 0x800440A8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800440AC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800440B0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800440B4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800440B8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800440BC: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800440C0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800440C4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800440C8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800440CC: addiu       $t6, $t6, 0x5B0
    ctx->r14 = ADD32(ctx->r14, 0X5B0);
    // 0x800440D0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800440D4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800440D8:
    // 0x800440D8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800440DC: sb          $t7, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r15;
    // 0x800440E0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_800440E4:
    // 0x800440E4: sb          $zero, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = 0;
    // 0x800440E8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800440EC: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x800440F0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800440F4: nop

    // 0x800440F8: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800440FC: beq         $t1, $zero, L_8004410C
    if (ctx->r9 == 0) {
        // 0x80044100: nop
    
            goto L_8004410C;
    }
    // 0x80044100: nop

    // 0x80044104: addiu       $t2, $zero, 0xF0
    ctx->r10 = ADD32(0, 0XF0);
    // 0x80044108: sb          $t2, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r10;
L_8004410C:
    // 0x8004410C: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x80044110: nop

    // 0x80044114: srl         $t4, $t3, 1
    ctx->r12 = S32(U32(ctx->r11) >> 1);
    // 0x80044118: sb          $t4, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r12;
    // 0x8004411C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80044120: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x80044124: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80044128: nop

    // 0x8004412C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80044130: beq         $t8, $zero, L_80044148
    if (ctx->r24 == 0) {
        // 0x80044134: nop
    
            goto L_80044148;
    }
    // 0x80044134: nop

    // 0x80044138: lbu         $t9, 0x3A($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3A);
    // 0x8004413C: nop

    // 0x80044140: ori         $t0, $t9, 0xF
    ctx->r8 = ctx->r25 | 0XF;
    // 0x80044144: sb          $t0, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r8;
L_80044148:
    // 0x80044148: lbu         $t1, 0x3A($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3A);
    // 0x8004414C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80044150: nop

    // 0x80044154: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x80044158: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8004415C: nop

    // 0x80044160: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80044164: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80044168: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x8004416C: nop

    // 0x80044170: srl         $t6, $t5, 1
    ctx->r14 = S32(U32(ctx->r13) >> 1);
    // 0x80044174: sb          $t6, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r14;
    // 0x80044178: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x8004417C: nop

    // 0x80044180: bne         $t7, $zero, L_800441A0
    if (ctx->r15 != 0) {
        // 0x80044184: nop
    
            goto L_800441A0;
    }
    // 0x80044184: nop

    // 0x80044188: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8004418C: nop

    // 0x80044190: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80044194: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80044198: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8004419C: sb          $t0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r8;
L_800441A0:
    // 0x800441A0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800441A4: nop

    // 0x800441A8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800441AC: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x800441B0: bne         $at, $zero, L_800440E4
    if (ctx->r1 != 0) {
        // 0x800441B4: sw          $t2, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r10;
            goto L_800440E4;
    }
    // 0x800441B4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800441B8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800441BC: nop

    // 0x800441C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800441C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800441C8: lhu         $t6, 0x52($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X52);
    // 0x800441CC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800441D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800441D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800441D8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800441DC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800441E0: addiu       $t9, $t8, -0xA
    ctx->r25 = ADD32(ctx->r24, -0XA);
    // 0x800441E4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800441E8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800441EC: nop

    // 0x800441F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800441F4: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x800441F8: bne         $at, $zero, L_800440D8
    if (ctx->r1 != 0) {
        // 0x800441FC: sw          $t1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r9;
            goto L_800440D8;
    }
    // 0x800441FC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
L_80044200:
    // 0x80044200: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80044204: lhu         $t4, 0x52($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X52);
    // 0x80044208: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8004420C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80044210: bne         $at, $zero, L_80043FFC
    if (ctx->r1 != 0) {
        // 0x80044214: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_80043FFC;
    }
    // 0x80044214: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
L_80044218:
    // 0x80044218: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8004421C: lhu         $t7, 0x56($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X56);
    // 0x80044220: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80044224: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80044228: bne         $at, $zero, L_80043FEC
    if (ctx->r1 != 0) {
        // 0x8004422C: sw          $t5, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r13;
            goto L_80043FEC;
    }
    // 0x8004422C: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_80044230:
    // 0x80044230: b           L_80044238
    // 0x80044234: nop

        goto L_80044238;
    // 0x80044234: nop

L_80044238:
    // 0x80044238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004423C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044240: jr          $ra
    // 0x80044244: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80044244: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80083E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083E30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083E34: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083E38: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80083E3C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80083E40: nop

    // 0x80083E44: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80083E48: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80083E4C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083E50: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083E54: nop

    // 0x80083E58: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80083E5C: nop

    // 0x80083E60: sh          $t0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r8;
    // 0x80083E64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083E68: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083E6C: nop

    // 0x80083E70: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x80083E74: nop

    // 0x80083E78: sh          $t2, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r10;
    // 0x80083E7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083E80: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083E84: jal         0x80088CC4
    // 0x80083E88: nop

    func_80088CC4(rdram, ctx);
        goto after_0;
    // 0x80083E88: nop

    after_0:
    // 0x80083E8C: b           L_80083E9C
    // 0x80083E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80083E9C;
    // 0x80083E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083E94: b           L_80083E9C
    // 0x80083E98: nop

        goto L_80083E9C;
    // 0x80083E98: nop

L_80083E9C:
    // 0x80083E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083EA4: jr          $ra
    // 0x80083EA8: nop

    return;
    // 0x80083EA8: nop

;}
RECOMP_FUNC void func_8008C0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0D8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C0DC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8008C0E0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C0E4:
    // 0x8008C0E4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008C0E8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008C0EC: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C0F0: sb          $t6, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r14;
    // 0x8008C0F4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008C0F8: nop

    // 0x8008C0FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008C100: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8008C104: bne         $at, $zero, L_8008C0E4
    if (ctx->r1 != 0) {
        // 0x8008C108: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_8008C0E4;
    }
    // 0x8008C108: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8008C10C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C110:
    // 0x8008C110: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008C114: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008C118: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8008C11C: sb          $t1, 0x7($t3)
    MEM_B(0X7, ctx->r11) = ctx->r9;
    // 0x8008C120: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8008C124: nop

    // 0x8008C128: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008C12C: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8008C130: bne         $at, $zero, L_8008C110
    if (ctx->r1 != 0) {
        // 0x8008C134: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_8008C110;
    }
    // 0x8008C134: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8008C138: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008C13C: sh          $t7, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r15;
    // 0x8008C140: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x8008C144: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x8008C148: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x8008C14C: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x8008C150: b           L_8008C158
    // 0x8008C154: nop

        goto L_8008C158;
    // 0x8008C154: nop

L_8008C158:
    // 0x8008C158: jr          $ra
    // 0x8008C15C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C15C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80073950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073950: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073954: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073958: nop

    // 0x8007395C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073960: nop

    // 0x80073964: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073968: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007396C: jr          $ra
    // 0x80073970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073974: jr          $ra
    // 0x80073978: nop

    return;
    // 0x80073978: nop

    // 0x8007397C: jr          $ra
    // 0x80073980: nop

    return;
    // 0x80073980: nop

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
RECOMP_FUNC void func_800A4638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4638: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800A463C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4640: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800A4644: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4648: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A464C: lw          $t7, 0x70E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E4);
    // 0x800A4650: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A4654: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800A4658: jal         0x800C2AE8
    // 0x800A465C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_0;
    // 0x800A465C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_0:
    // 0x800A4660: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800A4664: jal         0x800C1A84
    // 0x800A4668: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_1;
    // 0x800A4668: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_1:
    // 0x800A466C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800A4670: nop

    // 0x800A4674: lhu         $t0, 0xC4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XC4);
    // 0x800A4678: nop

    // 0x800A467C: bne         $t0, $zero, L_800A4690
    if (ctx->r8 != 0) {
        // 0x800A4680: nop
    
            goto L_800A4690;
    }
    // 0x800A4680: nop

    // 0x800A4684: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800A4688: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800A468C: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
L_800A4690:
    // 0x800A4690: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800A4694: nop

    // 0x800A4698: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x800A469C: nop

    // 0x800A46A0: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x800A46A4: bne         $t5, $zero, L_800A4940
    if (ctx->r13 != 0) {
        // 0x800A46A8: nop
    
            goto L_800A4940;
    }
    // 0x800A46A8: nop

    // 0x800A46AC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A46B0: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x800A46B4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800A46B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A46BC: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800A46C0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800A46C4: sw          $t7, 0x30C8($at)
    MEM_W(0X30C8, ctx->r1) = ctx->r15;
    // 0x800A46C8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A46CC: lw          $t9, 0x7188($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7188);
    // 0x800A46D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A46D4: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800A46D8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800A46DC: sh          $zero, 0x30D0($at)
    MEM_H(0X30D0, ctx->r1) = 0;
    // 0x800A46E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A46E4: lw          $t1, 0x7238($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7238);
    // 0x800A46E8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800A46EC: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800A46F0: bne         $t2, $zero, L_800A471C
    if (ctx->r10 != 0) {
        // 0x800A46F4: nop
    
            goto L_800A471C;
    }
    // 0x800A46F4: nop

    // 0x800A46F8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A46FC: lw          $t4, 0x7188($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7188);
    // 0x800A4700: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800A4704: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4708: lwc1        $f4, 0xB8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XB8);
    // 0x800A470C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800A4710: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800A4714: b           L_800A47A0
    // 0x800A4718: swc1        $f4, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f4.u32l;
        goto L_800A47A0;
    // 0x800A4718: swc1        $f4, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f4.u32l;
L_800A471C:
    // 0x800A471C: jal         0x800C1680
    // 0x800A4720: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_2;
    // 0x800A4720: nop

    after_2:
    // 0x800A4724: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A4728: nop

    // 0x800A472C: lhu         $a0, 0xC4($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XC4);
    // 0x800A4730: jal         0x800AD70C
    // 0x800A4734: nop

    func_800AD70C(rdram, ctx);
        goto after_3;
    // 0x800A4734: nop

    after_3:
    // 0x800A4738: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A473C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800A4740: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800A4744: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A4748: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800A474C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A4750: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800A4754: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800A4758: addiu       $t8, $t7, 0xA0
    ctx->r24 = ADD32(ctx->r15, 0XA0);
    // 0x800A475C: jal         0x800C1AF4
    // 0x800A4760: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_4;
    // 0x800A4760: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x800A4764: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800A4768: jal         0x800C1D44
    // 0x800A476C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_5;
    // 0x800A476C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_5:
    // 0x800A4770: jal         0x800C1A84
    // 0x800A4774: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_6;
    // 0x800A4774: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x800A4778: jal         0x800C1A28
    // 0x800A477C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_7;
    // 0x800A477C: nop

    after_7:
    // 0x800A4780: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A4784: lw          $t1, 0x7188($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7188);
    // 0x800A4788: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800A478C: lwc1        $f6, 0x38($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X38);
    // 0x800A4790: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4794: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800A4798: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800A479C: swc1        $f6, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f6.u32l;
L_800A47A0:
    // 0x800A47A0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A47A4: lw          $t3, 0x7188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7188);
    // 0x800A47A8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A47AC: addiu       $t5, $t5, 0x30C8
    ctx->r13 = ADD32(ctx->r13, 0X30C8);
    // 0x800A47B0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800A47B4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A47B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A47BC: sw          $t6, 0x50D4($at)
    MEM_W(0X50D4, ctx->r1) = ctx->r14;
    // 0x800A47C0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A47C4: lw          $t7, 0x7188($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7188);
    // 0x800A47C8: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x800A47CC: blez        $t7, L_800A4914
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A47D0: nop
    
            goto L_800A4914;
    }
    // 0x800A47D0: nop

L_800A47D4:
    // 0x800A47D4: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800A47D8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A47DC: addiu       $t0, $t0, 0x30C8
    ctx->r8 = ADD32(ctx->r8, 0X30C8);
    // 0x800A47E0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800A47E4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800A47E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A47EC: sw          $t1, 0x50CC($at)
    MEM_W(0X50CC, ctx->r1) = ctx->r9;
    // 0x800A47F0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A47F4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A47F8: lw          $t3, 0x50CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50CC);
    // 0x800A47FC: lw          $t2, 0x50D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50D4);
    // 0x800A4800: lwc1        $f10, 0xC($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800A4804: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800A4808: nop

    // 0x800A480C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800A4810: nop

    // 0x800A4814: bc1f        L_800A483C
    if (!c1cs) {
        // 0x800A4818: nop
    
            goto L_800A483C;
    }
    // 0x800A4818: nop

    // 0x800A481C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A4820: lw          $t4, 0x50D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50D4);
    // 0x800A4824: nop

    // 0x800A4828: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x800A482C: nop

    // 0x800A4830: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800A4834: b           L_800A48F8
    // 0x800A4838: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
        goto L_800A48F8;
    // 0x800A4838: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
L_800A483C:
    // 0x800A483C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A4840: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A4844: lw          $t8, 0x50CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50CC);
    // 0x800A4848: lw          $t7, 0x50D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50D4);
    // 0x800A484C: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800A4850: lwc1        $f16, 0xC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800A4854: nop

    // 0x800A4858: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A485C: nop

    // 0x800A4860: bc1f        L_800A48DC
    if (!c1cs) {
        // 0x800A4864: nop
    
            goto L_800A48DC;
    }
    // 0x800A4864: nop

    // 0x800A4868: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A486C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A4870: lw          $t2, 0x50D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50D4);
    // 0x800A4874: lw          $t9, 0x50CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50CC);
    // 0x800A4878: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800A487C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800A4880: lw          $t5, 0xC8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC8);
    // 0x800A4884: lw          $t1, 0xC8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC8);
    // 0x800A4888: nop

    // 0x800A488C: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A4890: bne         $at, $zero, L_800A48B8
    if (ctx->r1 != 0) {
        // 0x800A4894: nop
    
            goto L_800A48B8;
    }
    // 0x800A4894: nop

    // 0x800A4898: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A489C: lw          $t6, 0x50CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50CC);
    // 0x800A48A0: nop

    // 0x800A48A4: lh          $t4, 0x8($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X8);
    // 0x800A48A8: nop

    // 0x800A48AC: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x800A48B0: b           L_800A48D4
    // 0x800A48B4: sh          $t7, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r15;
        goto L_800A48D4;
    // 0x800A48B4: sh          $t7, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r15;
L_800A48B8:
    // 0x800A48B8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A48BC: lw          $t8, 0x50D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50D4);
    // 0x800A48C0: nop

    // 0x800A48C4: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x800A48C8: nop

    // 0x800A48CC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800A48D0: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
L_800A48D4:
    // 0x800A48D4: b           L_800A48F8
    // 0x800A48D8: nop

        goto L_800A48F8;
    // 0x800A48D8: nop

L_800A48DC:
    // 0x800A48DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A48E0: lw          $t2, 0x50CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50CC);
    // 0x800A48E4: nop

    // 0x800A48E8: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x800A48EC: nop

    // 0x800A48F0: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x800A48F4: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
L_800A48F8:
    // 0x800A48F8: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800A48FC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A4900: lw          $t7, 0x7188($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7188);
    // 0x800A4904: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800A4908: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A490C: bne         $at, $zero, L_800A47D4
    if (ctx->r1 != 0) {
        // 0x800A4910: sw          $t4, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r12;
            goto L_800A47D4;
    }
    // 0x800A4910: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
L_800A4914:
    // 0x800A4914: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A4918: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x800A491C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4920: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800A4924: sw          $t9, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = ctx->r25;
    // 0x800A4928: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x800A492C: lw          $v0, 0x7188($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7188);
    // 0x800A4930: b           L_800A4BD4
    // 0x800A4934: nop

        goto L_800A4BD4;
    // 0x800A4934: nop

    // 0x800A4938: b           L_800A4BCC
    // 0x800A493C: nop

        goto L_800A4BCC;
    // 0x800A493C: nop

L_800A4940:
    // 0x800A4940: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A4944: lw          $t8, 0x7204($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7204);
    // 0x800A4948: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800A494C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4950: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x800A4954: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800A4958: sw          $t0, 0x50E0($at)
    MEM_W(0X50E0, ctx->r1) = ctx->r8;
    // 0x800A495C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A4960: lw          $t1, 0x7204($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7204);
    // 0x800A4964: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4968: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800A496C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800A4970: sh          $zero, 0x50E8($at)
    MEM_H(0X50E8, ctx->r1) = 0;
    // 0x800A4974: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A4978: lw          $t5, 0x7238($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7238);
    // 0x800A497C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800A4980: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x800A4984: bne         $t4, $zero, L_800A49B0
    if (ctx->r12 != 0) {
        // 0x800A4988: nop
    
            goto L_800A49B0;
    }
    // 0x800A4988: nop

    // 0x800A498C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A4990: lw          $t6, 0x7204($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7204);
    // 0x800A4994: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800A4998: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A499C: lwc1        $f4, 0xB8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XB8);
    // 0x800A49A0: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x800A49A4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A49A8: b           L_800A4A34
    // 0x800A49AC: swc1        $f4, 0x50EC($at)
    MEM_W(0X50EC, ctx->r1) = ctx->f4.u32l;
        goto L_800A4A34;
    // 0x800A49AC: swc1        $f4, 0x50EC($at)
    MEM_W(0X50EC, ctx->r1) = ctx->f4.u32l;
L_800A49B0:
    // 0x800A49B0: jal         0x800C1680
    // 0x800A49B4: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_8;
    // 0x800A49B4: nop

    after_8:
    // 0x800A49B8: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800A49BC: nop

    // 0x800A49C0: lhu         $a0, 0xC4($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XC4);
    // 0x800A49C4: jal         0x800AD70C
    // 0x800A49C8: nop

    func_800AD70C(rdram, ctx);
        goto after_9;
    // 0x800A49C8: nop

    after_9:
    // 0x800A49CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A49D0: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800A49D4: addu        $t0, $t0, $s0
    ctx->r8 = ADD32(ctx->r8, ctx->r16);
    // 0x800A49D8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800A49DC: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x800A49E0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800A49E4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800A49E8: addiu       $t1, $t1, 0x61D8
    ctx->r9 = ADD32(ctx->r9, 0X61D8);
    // 0x800A49EC: addiu       $t3, $t0, 0xA0
    ctx->r11 = ADD32(ctx->r8, 0XA0);
    // 0x800A49F0: jal         0x800C1AF4
    // 0x800A49F4: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_10;
    // 0x800A49F4: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    after_10:
    // 0x800A49F8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800A49FC: jal         0x800C1D44
    // 0x800A4A00: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_11;
    // 0x800A4A00: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_11:
    // 0x800A4A04: jal         0x800C1A84
    // 0x800A4A08: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_12;
    // 0x800A4A08: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_12:
    // 0x800A4A0C: jal         0x800C1A28
    // 0x800A4A10: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_13;
    // 0x800A4A10: nop

    after_13:
    // 0x800A4A14: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A4A18: lw          $t5, 0x7204($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7204);
    // 0x800A4A1C: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x800A4A20: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x800A4A24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4A28: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x800A4A2C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800A4A30: swc1        $f6, 0x50EC($at)
    MEM_W(0X50EC, ctx->r1) = ctx->f6.u32l;
L_800A4A34:
    // 0x800A4A34: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A4A38: lw          $t7, 0x7204($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7204);
    // 0x800A4A3C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A4A40: addiu       $t9, $t9, 0x50E0
    ctx->r25 = ADD32(ctx->r25, 0X50E0);
    // 0x800A4A44: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x800A4A48: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800A4A4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4A50: sw          $t8, 0x50D4($at)
    MEM_W(0X50D4, ctx->r1) = ctx->r24;
    // 0x800A4A54: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A4A58: lw          $t0, 0x7204($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7204);
    // 0x800A4A5C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x800A4A60: blez        $t0, L_800A4BA8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800A4A64: nop
    
            goto L_800A4BA8;
    }
    // 0x800A4A64: nop

L_800A4A68:
    // 0x800A4A68: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800A4A6C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A4A70: addiu       $t2, $t2, 0x50E0
    ctx->r10 = ADD32(ctx->r10, 0X50E0);
    // 0x800A4A74: sll         $t1, $t3, 4
    ctx->r9 = S32(ctx->r11 << 4);
    // 0x800A4A78: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x800A4A7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4A80: sw          $t5, 0x50CC($at)
    MEM_W(0X50CC, ctx->r1) = ctx->r13;
    // 0x800A4A84: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A4A88: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A4A8C: lw          $t7, 0x50CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50CC);
    // 0x800A4A90: lw          $t4, 0x50D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50D4);
    // 0x800A4A94: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800A4A98: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800A4A9C: nop

    // 0x800A4AA0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800A4AA4: nop

    // 0x800A4AA8: bc1f        L_800A4AD0
    if (!c1cs) {
        // 0x800A4AAC: nop
    
            goto L_800A4AD0;
    }
    // 0x800A4AAC: nop

    // 0x800A4AB0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A4AB4: lw          $t6, 0x50D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50D4);
    // 0x800A4AB8: nop

    // 0x800A4ABC: lh          $t9, 0x8($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X8);
    // 0x800A4AC0: nop

    // 0x800A4AC4: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800A4AC8: b           L_800A4B8C
    // 0x800A4ACC: sh          $t8, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r24;
        goto L_800A4B8C;
    // 0x800A4ACC: sh          $t8, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r24;
L_800A4AD0:
    // 0x800A4AD0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A4AD4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A4AD8: lw          $t3, 0x50CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50CC);
    // 0x800A4ADC: lw          $t0, 0x50D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50D4);
    // 0x800A4AE0: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800A4AE4: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800A4AE8: nop

    // 0x800A4AEC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A4AF0: nop

    // 0x800A4AF4: bc1f        L_800A4B70
    if (!c1cs) {
        // 0x800A4AF8: nop
    
            goto L_800A4B70;
    }
    // 0x800A4AF8: nop

    // 0x800A4AFC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A4B00: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A4B04: lw          $t4, 0x50D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50D4);
    // 0x800A4B08: lw          $t1, 0x50CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50CC);
    // 0x800A4B0C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800A4B10: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A4B14: lw          $t9, 0xC8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC8);
    // 0x800A4B18: lw          $t5, 0xC8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC8);
    // 0x800A4B1C: nop

    // 0x800A4B20: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800A4B24: bne         $at, $zero, L_800A4B4C
    if (ctx->r1 != 0) {
        // 0x800A4B28: nop
    
            goto L_800A4B4C;
    }
    // 0x800A4B28: nop

    // 0x800A4B2C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A4B30: lw          $t8, 0x50CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50CC);
    // 0x800A4B34: nop

    // 0x800A4B38: lh          $t6, 0x8($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X8);
    // 0x800A4B3C: nop

    // 0x800A4B40: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x800A4B44: b           L_800A4B68
    // 0x800A4B48: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
        goto L_800A4B68;
    // 0x800A4B48: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
L_800A4B4C:
    // 0x800A4B4C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A4B50: lw          $t3, 0x50D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50D4);
    // 0x800A4B54: nop

    // 0x800A4B58: lh          $t1, 0x8($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X8);
    // 0x800A4B5C: nop

    // 0x800A4B60: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800A4B64: sh          $t2, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r10;
L_800A4B68:
    // 0x800A4B68: b           L_800A4B8C
    // 0x800A4B6C: nop

        goto L_800A4B8C;
    // 0x800A4B6C: nop

L_800A4B70:
    // 0x800A4B70: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A4B74: lw          $t4, 0x50CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50CC);
    // 0x800A4B78: nop

    // 0x800A4B7C: lh          $t7, 0x8($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X8);
    // 0x800A4B80: nop

    // 0x800A4B84: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x800A4B88: sh          $t5, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r13;
L_800A4B8C:
    // 0x800A4B8C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800A4B90: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A4B94: lw          $t0, 0x7204($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7204);
    // 0x800A4B98: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800A4B9C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800A4BA0: bne         $at, $zero, L_800A4A68
    if (ctx->r1 != 0) {
        // 0x800A4BA4: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_800A4A68;
    }
    // 0x800A4BA4: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_800A4BA8:
    // 0x800A4BA8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A4BAC: lw          $t8, 0x7204($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7204);
    // 0x800A4BB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4BB4: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800A4BB8: sw          $t1, 0x7204($at)
    MEM_W(0X7204, ctx->r1) = ctx->r9;
    // 0x800A4BBC: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x800A4BC0: lw          $v0, 0x7204($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7204);
    // 0x800A4BC4: b           L_800A4BD4
    // 0x800A4BC8: nop

        goto L_800A4BD4;
    // 0x800A4BC8: nop

L_800A4BCC:
    // 0x800A4BCC: b           L_800A4BD4
    // 0x800A4BD0: nop

        goto L_800A4BD4;
    // 0x800A4BD0: nop

L_800A4BD4:
    // 0x800A4BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4BD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4BDC: jr          $ra
    // 0x800A4BE0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800A4BE0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80033C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80033C64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80033C68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80033C6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80033C70: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80033C74: jal         0x800B3434
    // 0x80033C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_0;
    // 0x80033C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80033C7C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80033C80: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x80033C84: nop

    // 0x80033C88: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x80033C8C: beq         $t7, $zero, L_80033CAC
    if (ctx->r15 == 0) {
        // 0x80033C90: nop
    
            goto L_80033CAC;
    }
    // 0x80033C90: nop

    // 0x80033C94: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80033C98: jal         0x800B32E4
    // 0x80033C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B32E4(rdram, ctx);
        goto after_1;
    // 0x80033C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80033CA0: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80033CA4: jal         0x800B9000
    // 0x80033CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_2;
    // 0x80033CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80033CAC:
    // 0x80033CAC: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x80033CB0: nop

    // 0x80033CB4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80033CB8: beq         $t9, $zero, L_80033CD8
    if (ctx->r25 == 0) {
        // 0x80033CBC: nop
    
            goto L_80033CD8;
    }
    // 0x80033CBC: nop

    // 0x80033CC0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80033CC4: jal         0x800B32E4
    // 0x80033CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B32E4(rdram, ctx);
        goto after_3;
    // 0x80033CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80033CCC: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80033CD0: jal         0x800B9000
    // 0x80033CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_4;
    // 0x80033CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80033CD8:
    // 0x80033CD8: b           L_80033CE0
    // 0x80033CDC: nop

        goto L_80033CE0;
    // 0x80033CDC: nop

L_80033CE0:
    // 0x80033CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80033CE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80033CE8: jr          $ra
    // 0x80033CEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80033CEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80077DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077DA8: jal         0x8005F064
    // 0x80077DAC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077DAC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077DB0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077DB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077DB8: beq         $v0, $zero, L_80077DD0
    if (ctx->r2 == 0) {
        // 0x80077DBC: nop
    
            goto L_80077DD0;
    }
    // 0x80077DBC: nop

    // 0x80077DC0: jal         0x8005F064
    // 0x80077DC4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80077DC4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x80077DC8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077DCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80077DD0:
    // 0x80077DD0: b           L_80077DE0
    // 0x80077DD4: nop

        goto L_80077DE0;
    // 0x80077DD4: nop

    // 0x80077DD8: b           L_80077DE0
    // 0x80077DDC: nop

        goto L_80077DE0;
    // 0x80077DDC: nop

L_80077DE0:
    // 0x80077DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077DE8: jr          $ra
    // 0x80077DEC: nop

    return;
    // 0x80077DEC: nop

;}
RECOMP_FUNC void func_800A4104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4104: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A4108: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A410C: lw          $t6, -0x73AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73AC);
    // 0x800A4110: nop

    // 0x800A4114: bne         $a0, $t6, L_800A4164
    if (ctx->r4 != ctx->r14) {
        // 0x800A4118: nop
    
            goto L_800A4164;
    }
    // 0x800A4118: nop

    // 0x800A411C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A4120: lw          $t7, -0x73AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73AC);
    // 0x800A4124: nop

    // 0x800A4128: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x800A412C: nop

    // 0x800A4130: bne         $t8, $zero, L_800A4144
    if (ctx->r24 != 0) {
        // 0x800A4134: nop
    
            goto L_800A4144;
    }
    // 0x800A4134: nop

    // 0x800A4138: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A413C: b           L_800A415C
    // 0x800A4140: sw          $zero, -0x73AC($at)
    MEM_W(-0X73AC, ctx->r1) = 0;
        goto L_800A415C;
    // 0x800A4140: sw          $zero, -0x73AC($at)
    MEM_W(-0X73AC, ctx->r1) = 0;
L_800A4144:
    // 0x800A4144: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A4148: lw          $t9, -0x73AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73AC);
    // 0x800A414C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A4150: lw          $t0, 0x14C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14C);
    // 0x800A4154: nop

    // 0x800A4158: sw          $t0, -0x73AC($at)
    MEM_W(-0X73AC, ctx->r1) = ctx->r8;
L_800A415C:
    // 0x800A415C: b           L_800A41A4
    // 0x800A4160: nop

        goto L_800A41A4;
    // 0x800A4160: nop

L_800A4164:
    // 0x800A4164: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x800A4168: lw          $t2, 0x148($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X148);
    // 0x800A416C: nop

    // 0x800A4170: sw          $t1, 0x14C($t2)
    MEM_W(0X14C, ctx->r10) = ctx->r9;
    // 0x800A4174: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x800A4178: nop

    // 0x800A417C: beq         $t3, $zero, L_800A4194
    if (ctx->r11 == 0) {
        // 0x800A4180: nop
    
            goto L_800A4194;
    }
    // 0x800A4180: nop

    // 0x800A4184: lw          $t4, 0x148($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X148);
    // 0x800A4188: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    // 0x800A418C: nop

    // 0x800A4190: sw          $t4, 0x148($t5)
    MEM_W(0X148, ctx->r13) = ctx->r12;
L_800A4194:
    // 0x800A4194: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800A4198: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x800A419C: nop

    // 0x800A41A0: sw          $t6, 0x148($a0)
    MEM_W(0X148, ctx->r4) = ctx->r14;
L_800A41A4:
    // 0x800A41A4: b           L_800A41AC
    // 0x800A41A8: nop

        goto L_800A41AC;
    // 0x800A41A8: nop

L_800A41AC:
    // 0x800A41AC: jr          $ra
    // 0x800A41B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A41B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80008FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008FF0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80008FF4: bne         $a1, $a2, L_80009104
    if (ctx->r5 != ctx->r6) {
        // 0x80008FF8: nop
    
            goto L_80009104;
    }
    // 0x80008FF8: nop

    // 0x80008FFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009000: bne         $a1, $at, L_80009104
    if (ctx->r5 != ctx->r1) {
        // 0x80009004: nop
    
            goto L_80009104;
    }
    // 0x80009004: nop

    // 0x80009008: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000900C: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80009010: nop

    // 0x80009014: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80009018: nop

    // 0x8000901C: beq         $t7, $zero, L_800090FC
    if (ctx->r15 == 0) {
        // 0x80009020: nop
    
            goto L_800090FC;
    }
    // 0x80009020: nop

    // 0x80009024: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80009028: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8000902C: lw          $t0, 0x348($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X348);
    // 0x80009030: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x80009034: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80009038: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000903C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80009040: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80009044: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009048: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x8000904C: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x80009050: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80009054: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80009058: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8000905C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80009060: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80009064: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80009068: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8000906C: swc1        $f16, 0x334($a0)
    MEM_W(0X334, ctx->r4) = ctx->f16.u32l;
    // 0x80009070: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80009074: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009078: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x8000907C: lh          $t0, 0x2($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X2);
    // 0x80009080: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80009084: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80009088: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8000908C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009090: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80009094: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80009098: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8000909C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800090A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800090A4: nop

    // 0x800090A8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800090AC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800090B0: swc1        $f18, 0x338($a0)
    MEM_W(0X338, ctx->r4) = ctx->f18.u32l;
    // 0x800090B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800090B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800090BC: nop

    // 0x800090C0: swc1        $f4, 0x328($a0)
    MEM_W(0X328, ctx->r4) = ctx->f4.u32l;
    // 0x800090C4: lwc1        $f6, 0x334($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X334);
    // 0x800090C8: lwc1        $f8, 0x32C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X32C);
    // 0x800090CC: lwc1        $f16, 0x328($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X328);
    // 0x800090D0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800090D4: nop

    // 0x800090D8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800090DC: swc1        $f18, 0x33C($a0)
    MEM_W(0X33C, ctx->r4) = ctx->f18.u32l;
    // 0x800090E0: lwc1        $f4, 0x338($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X338);
    // 0x800090E4: lwc1        $f6, 0x330($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X330);
    // 0x800090E8: lwc1        $f10, 0x328($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X328);
    // 0x800090EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800090F0: nop

    // 0x800090F4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800090F8: swc1        $f16, 0x340($a0)
    MEM_W(0X340, ctx->r4) = ctx->f16.u32l;
L_800090FC:
    // 0x800090FC: b           L_80009474
    // 0x80009100: nop

        goto L_80009474;
    // 0x80009100: nop

L_80009104:
    // 0x80009104: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80009108: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8000910C: nop

    // 0x80009110: lw          $t2, 0x144($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X144);
    // 0x80009114: nop

    // 0x80009118: beq         $t2, $zero, L_80009474
    if (ctx->r10 == 0) {
        // 0x8000911C: nop
    
            goto L_80009474;
    }
    // 0x8000911C: nop

    // 0x80009120: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80009124: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80009128: nop

    // 0x8000912C: lw          $t4, 0x144($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X144);
    // 0x80009130: nop

    // 0x80009134: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80009138: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8000913C: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x80009140: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80009144: nop

    // 0x80009148: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000914C: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x80009150: nop

    // 0x80009154: bne         $t6, $t7, L_8000916C
    if (ctx->r14 != ctx->r15) {
        // 0x80009158: nop
    
            goto L_8000916C;
    }
    // 0x80009158: nop

    // 0x8000915C: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80009160: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80009164: beq         $t8, $at, L_80009304
    if (ctx->r24 == ctx->r1) {
        // 0x80009168: nop
    
            goto L_80009304;
    }
    // 0x80009168: nop

L_8000916C:
    // 0x8000916C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009170: nop

    // 0x80009174: lhu         $t9, 0xA($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0XA);
    // 0x80009178: nop

    // 0x8000917C: bne         $t9, $a1, L_800092B8
    if (ctx->r25 != ctx->r5) {
        // 0x80009180: nop
    
            goto L_800092B8;
    }
    // 0x80009180: nop

    // 0x80009184: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x80009188: nop

    // 0x8000918C: bne         $t1, $a2, L_800092B8
    if (ctx->r9 != ctx->r6) {
        // 0x80009190: nop
    
            goto L_800092B8;
    }
    // 0x80009190: nop

    // 0x80009194: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80009198: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000919C: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x800091A0: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800091A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800091A8: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800091AC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800091B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800091B4: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800091B8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800091BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800091C0: swc1        $f10, 0x32C($a0)
    MEM_W(0X32C, ctx->r4) = ctx->f10.u32l;
    // 0x800091C4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800091C8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800091CC: lh          $t5, 0x6($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X6);
    // 0x800091D0: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800091D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800091D8: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800091DC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800091E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800091E4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800091E8: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x800091EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800091F0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800091F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800091F8: nop

    // 0x800091FC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80009200: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80009204: swc1        $f16, 0x330($a0)
    MEM_W(0X330, ctx->r4) = ctx->f16.u32l;
    // 0x80009208: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8000920C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009210: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80009214: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x80009218: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000921C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80009220: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80009224: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009228: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8000922C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80009230: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80009234: swc1        $f10, 0x334($a0)
    MEM_W(0X334, ctx->r4) = ctx->f10.u32l;
    // 0x80009238: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8000923C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009240: lh          $t6, 0x6($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X6);
    // 0x80009244: lh          $t7, 0x2($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2);
    // 0x80009248: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8000924C: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x80009250: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80009254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009258: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8000925C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80009260: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80009264: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80009268: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000926C: nop

    // 0x80009270: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80009274: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80009278: swc1        $f16, 0x338($a0)
    MEM_W(0X338, ctx->r4) = ctx->f16.u32l;
    // 0x8000927C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80009280: nop

    // 0x80009284: swc1        $f18, 0x328($a0)
    MEM_W(0X328, ctx->r4) = ctx->f18.u32l;
    // 0x80009288: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8000928C: nop

    // 0x80009290: sw          $t8, 0x344($a0)
    MEM_W(0X344, ctx->r4) = ctx->r24;
    // 0x80009294: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80009298: nop

    // 0x8000929C: sw          $t9, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r25;
    // 0x800092A0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800092A4: nop

    // 0x800092A8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800092AC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800092B0: b           L_80009304
    // 0x800092B4: nop

        goto L_80009304;
    // 0x800092B4: nop

L_800092B8:
    // 0x800092B8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800092BC: nop

    // 0x800092C0: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800092C4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800092C8: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800092CC: nop

    // 0x800092D0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800092D4: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800092D8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800092DC: nop

    // 0x800092E0: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800092E4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800092E8: nop

    // 0x800092EC: bne         $t5, $t8, L_8000916C
    if (ctx->r13 != ctx->r24) {
        // 0x800092F0: nop
    
            goto L_8000916C;
    }
    // 0x800092F0: nop

    // 0x800092F4: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800092F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800092FC: bne         $t9, $at, L_8000916C
    if (ctx->r25 != ctx->r1) {
        // 0x80009300: nop
    
            goto L_8000916C;
    }
    // 0x80009300: nop

L_80009304:
    // 0x80009304: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80009308: nop

    // 0x8000930C: bne         $t0, $zero, L_8000946C
    if (ctx->r8 != 0) {
        // 0x80009310: nop
    
            goto L_8000946C;
    }
    // 0x80009310: nop

    // 0x80009314: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80009318: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8000931C: lh          $t2, 0x72A0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X72A0);
    // 0x80009320: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x80009324: nop

    // 0x80009328: beq         $t1, $t2, L_80009338
    if (ctx->r9 == ctx->r10) {
        // 0x8000932C: nop
    
            goto L_80009338;
    }
    // 0x8000932C: nop

    // 0x80009330: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80009334: sh          $zero, 0x7294($at)
    MEM_H(0X7294, ctx->r1) = 0;
L_80009338:
    // 0x80009338: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000933C: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80009340: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80009344: lh          $t6, 0x7294($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7294);
    // 0x80009348: lw          $t4, 0x144($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X144);
    // 0x8000934C: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x80009350: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x80009354: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80009358: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8000935C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009360: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x80009364: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80009368: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000936C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80009370: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80009374: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80009378: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000937C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80009380: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80009384: swc1        $f16, 0x32C($a0)
    MEM_W(0X32C, ctx->r4) = ctx->f16.u32l;
    // 0x80009388: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8000938C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009390: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x80009394: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x80009398: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000939C: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x800093A0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800093A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800093A8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800093AC: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x800093B0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800093B4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800093B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800093BC: nop

    // 0x800093C0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800093C4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800093C8: swc1        $f18, 0x330($a0)
    MEM_W(0X330, ctx->r4) = ctx->f18.u32l;
    // 0x800093CC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800093D0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800093D4: lh          $t8, 0x4($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X4);
    // 0x800093D8: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800093DC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800093E0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800093E4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800093E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800093EC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800093F0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800093F4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800093F8: swc1        $f16, 0x334($a0)
    MEM_W(0X334, ctx->r4) = ctx->f16.u32l;
    // 0x800093FC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009400: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009404: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x80009408: lh          $t2, 0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X2);
    // 0x8000940C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80009410: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80009414: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80009418: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000941C: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80009420: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80009424: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80009428: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8000942C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009430: nop

    // 0x80009434: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80009438: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8000943C: swc1        $f18, 0x338($a0)
    MEM_W(0X338, ctx->r4) = ctx->f18.u32l;
    // 0x80009440: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009444: nop

    // 0x80009448: swc1        $f4, 0x328($a0)
    MEM_W(0X328, ctx->r4) = ctx->f4.u32l;
    // 0x8000944C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80009450: lh          $t6, 0x7294($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7294);
    // 0x80009454: nop

    // 0x80009458: sw          $t6, 0x344($a0)
    MEM_W(0X344, ctx->r4) = ctx->r14;
    // 0x8000945C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80009460: lh          $t4, 0x7294($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7294);
    // 0x80009464: nop

    // 0x80009468: sw          $t4, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r12;
L_8000946C:
    // 0x8000946C: b           L_8000947C
    // 0x80009470: nop

        goto L_8000947C;
    // 0x80009470: nop

L_80009474:
    // 0x80009474: b           L_8000947C
    // 0x80009478: nop

        goto L_8000947C;
    // 0x80009478: nop

L_8000947C:
    // 0x8000947C: jr          $ra
    // 0x80009480: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80009480: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800B748C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B748C: jr          $ra
    // 0x800B7490: nop

    return;
    // 0x800B7490: nop

    // 0x800B7494: jr          $ra
    // 0x800B7498: nop

    return;
    // 0x800B7498: nop

;}
RECOMP_FUNC void func_80055FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80055FC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055FC8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80055FCC: nop

    // 0x80055FD0: beq         $t6, $zero, L_8005608C
    if (ctx->r14 == 0) {
        // 0x80055FD4: nop
    
            goto L_8005608C;
    }
    // 0x80055FD4: nop

    // 0x80055FD8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80055FDC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055FE0: bne         $t7, $at, L_80056058
    if (ctx->r15 != ctx->r1) {
        // 0x80055FE4: nop
    
            goto L_80056058;
    }
    // 0x80055FE4: nop

    // 0x80055FE8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055FEC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80055FF0: nop

    // 0x80055FF4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80055FF8: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80055FFC: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80056000: ori         $t3, $t1, 0x1000
    ctx->r11 = ctx->r9 | 0X1000;
    // 0x80056004: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80056008: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005600C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80056010: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80056014: sh          $t9, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r25;
    // 0x80056018: jal         0x8005A578
    // 0x8005601C: nop

    func_8005A578(rdram, ctx);
        goto after_0;
    // 0x8005601C: nop

    after_0:
    // 0x80056020: bne         $v0, $zero, L_80056050
    if (ctx->r2 != 0) {
        // 0x80056024: nop
    
            goto L_80056050;
    }
    // 0x80056024: nop

    // 0x80056028: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005602C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80056030: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056034: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80056038: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005603C: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x80056040: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80056044: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x80056048: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8005604C: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_80056050:
    // 0x80056050: b           L_8005608C
    // 0x80056054: nop

        goto L_8005608C;
    // 0x80056054: nop

L_80056058:
    // 0x80056058: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005605C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80056060: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056064: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80056068: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8005606C: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x80056070: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80056074: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80056078: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8005607C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80056080: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80056084: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80056088: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
L_8005608C:
    // 0x8005608C: b           L_80056094
    // 0x80056090: nop

        goto L_80056094;
    // 0x80056090: nop

L_80056094:
    // 0x80056094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005609C: jr          $ra
    // 0x800560A0: nop

    return;
    // 0x800560A0: nop

;}
RECOMP_FUNC void func_80012634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012634: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80012638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001263C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80012640: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80012644: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80012648: jal         0x8000DA44
    // 0x8001264C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x8001264C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80012650: bgez        $v0, L_80012660
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012654: nop
    
            goto L_80012660;
    }
    // 0x80012654: nop

    // 0x80012658: b           L_80012788
    // 0x8001265C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012788;
    // 0x8001265C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012660:
    // 0x80012660: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80012664: nop

    // 0x80012668: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001266C: nop

    // 0x80012670: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80012674: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80012678: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8001267C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80012680: nop

    // 0x80012684: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012688: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x8001268C: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    // 0x80012690: jal         0x80014BD4
    // 0x80012694: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80012694: nop

    after_1:
    // 0x80012698: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8001269C: nop

    // 0x800126A0: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x800126A4: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800126A8: lhu         $a0, 0x6($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X6);
    // 0x800126AC: jal         0x80014BD4
    // 0x800126B0: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x800126B0: nop

    after_2:
    // 0x800126B4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800126B8: nop

    // 0x800126BC: swc1        $f0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f0.u32l;
    // 0x800126C0: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800126C4: lhu         $a0, 0x8($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X8);
    // 0x800126C8: jal         0x80014BD4
    // 0x800126CC: nop

    func_80014BD4(rdram, ctx);
        goto after_3;
    // 0x800126CC: nop

    after_3:
    // 0x800126D0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800126D4: nop

    // 0x800126D8: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x800126DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800126E0: nop

    // 0x800126E4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800126E8: nop

    // 0x800126EC: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x800126F0: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x800126F4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800126F8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800126FC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80012700: nop

    // 0x80012704: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80012708: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x8001270C: nop

    // 0x80012710: blez        $t2, L_80012778
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80012714: nop
    
            goto L_80012778;
    }
    // 0x80012714: nop

L_80012718:
    // 0x80012718: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001271C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80012720: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80012724: nop

    // 0x80012728: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8001272C: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x80012730: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80012734: nop

    // 0x80012738: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x8001273C: nop

    // 0x80012740: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80012744: sw          $t9, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r25;
    // 0x80012748: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001274C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80012750: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80012754: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80012758: addiu       $t2, $t0, 0x160
    ctx->r10 = ADD32(ctx->r8, 0X160);
    // 0x8001275C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80012760: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80012764: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80012768: nop

    // 0x8001276C: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80012770: bne         $at, $zero, L_80012718
    if (ctx->r1 != 0) {
        // 0x80012774: nop
    
            goto L_80012718;
    }
    // 0x80012774: nop

L_80012778:
    // 0x80012778: b           L_80012788
    // 0x8001277C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012788;
    // 0x8001277C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012780: b           L_80012788
    // 0x80012784: nop

        goto L_80012788;
    // 0x80012784: nop

L_80012788:
    // 0x80012788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001278C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80012790: jr          $ra
    // 0x80012794: nop

    return;
    // 0x80012794: nop

;}
RECOMP_FUNC void func_8009A664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A664: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8009A668: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009A66C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8009A670: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009A674: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x8009A678: nop

    // 0x8009A67C: bne         $t6, $zero, L_8009A6A0
    if (ctx->r14 != 0) {
        // 0x8009A680: nop
    
            goto L_8009A6A0;
    }
    // 0x8009A680: nop

    // 0x8009A684: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009A688: lw          $t7, 0x7204($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7204);
    // 0x8009A68C: nop

    // 0x8009A690: bne         $t7, $zero, L_8009A6A0
    if (ctx->r15 != 0) {
        // 0x8009A694: nop
    
            goto L_8009A6A0;
    }
    // 0x8009A694: nop

    // 0x8009A698: b           L_8009B520
    // 0x8009A69C: nop

        goto L_8009B520;
    // 0x8009A69C: nop

L_8009A6A0:
    // 0x8009A6A0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009A6A4: lw          $t8, 0x7238($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7238);
    // 0x8009A6A8: nop

    // 0x8009A6AC: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8009A6B0: bne         $t9, $zero, L_8009A734
    if (ctx->r25 != 0) {
        // 0x8009A6B4: nop
    
            goto L_8009A734;
    }
    // 0x8009A6B4: nop

    // 0x8009A6B8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009A6BC: lw          $t0, 0x7188($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7188);
    // 0x8009A6C0: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009A6C4: blez        $t0, L_8009A72C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009A6C8: nop
    
            goto L_8009A72C;
    }
    // 0x8009A6C8: nop

L_8009A6CC:
    // 0x8009A6CC: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A6D0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009A6D4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8009A6D8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8009A6DC: lh          $t3, 0x30D0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X30D0);
    // 0x8009A6E0: nop

    // 0x8009A6E4: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x8009A6E8: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A6EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009A6F0: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8009A6F4: addiu       $t6, $t6, 0x30C8
    ctx->r14 = ADD32(ctx->r14, 0X30C8);
    // 0x8009A6F8: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8009A6FC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8009A700: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8009A704: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8009A708: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x8009A70C: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8009A710: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A714: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009A718: lw          $t4, 0x7188($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7188);
    // 0x8009A71C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8009A720: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009A724: bne         $at, $zero, L_8009A6CC
    if (ctx->r1 != 0) {
        // 0x8009A728: sw          $t3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r11;
            goto L_8009A6CC;
    }
    // 0x8009A728: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
L_8009A72C:
    // 0x8009A72C: b           L_8009A7B8
    // 0x8009A730: nop

        goto L_8009A7B8;
    // 0x8009A730: nop

L_8009A734:
    // 0x8009A734: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009A738: lw          $t5, 0x7188($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7188);
    // 0x8009A73C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009A740: blez        $t5, L_8009A7B8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8009A744: nop
    
            goto L_8009A7B8;
    }
    // 0x8009A744: nop

L_8009A748:
    // 0x8009A748: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A74C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009A750: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8009A754: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8009A758: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009A75C: lw          $t7, 0x7188($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7188);
    // 0x8009A760: lh          $t6, 0x30D0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X30D0);
    // 0x8009A764: nop

    // 0x8009A768: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8009A76C: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x8009A770: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8009A774: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A778: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009A77C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8009A780: addiu       $t4, $t4, 0x30C8
    ctx->r12 = ADD32(ctx->r12, 0X30C8);
    // 0x8009A784: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8009A788: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009A78C: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8009A790: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x8009A794: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x8009A798: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8009A79C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A7A0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009A7A4: lw          $t2, 0x7188($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7188);
    // 0x8009A7A8: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8009A7AC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009A7B0: bne         $at, $zero, L_8009A748
    if (ctx->r1 != 0) {
        // 0x8009A7B4: sw          $t1, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r9;
            goto L_8009A748;
    }
    // 0x8009A7B4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
L_8009A7B8:
    // 0x8009A7B8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009A7BC: lw          $t3, 0x7204($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7204);
    // 0x8009A7C0: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009A7C4: blez        $t3, L_8009A83C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8009A7C8: nop
    
            goto L_8009A83C;
    }
    // 0x8009A7C8: nop

L_8009A7CC:
    // 0x8009A7CC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A7D0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009A7D4: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x8009A7D8: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8009A7DC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009A7E0: lw          $t5, 0x7204($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7204);
    // 0x8009A7E4: lh          $t4, 0x50E8($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X50E8);
    // 0x8009A7E8: nop

    // 0x8009A7EC: subu        $t9, $t5, $t4
    ctx->r25 = SUB32(ctx->r13, ctx->r12);
    // 0x8009A7F0: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8009A7F4: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8009A7F8: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A7FC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009A800: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8009A804: addiu       $t2, $t2, 0x50E0
    ctx->r10 = ADD32(ctx->r10, 0X50E0);
    // 0x8009A808: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x8009A80C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8009A810: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8009A814: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x8009A818: addu        $t4, $t5, $t2
    ctx->r12 = ADD32(ctx->r13, ctx->r10);
    // 0x8009A81C: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x8009A820: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A824: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009A828: lw          $t8, 0x7204($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7204);
    // 0x8009A82C: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8009A830: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009A834: bne         $at, $zero, L_8009A7CC
    if (ctx->r1 != 0) {
        // 0x8009A838: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_8009A7CC;
    }
    // 0x8009A838: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_8009A83C:
    // 0x8009A83C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009A840: jal         0x800A5854
    // 0x8009A844: nop

    func_800A5854(rdram, ctx);
        goto after_0;
    // 0x8009A844: nop

    after_0:
    // 0x8009A848: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8009A84C: lw          $t1, 0x6B9C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6B9C);
    // 0x8009A850: nop

    // 0x8009A854: bgez        $t1, L_8009A864
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8009A858: nop
    
            goto L_8009A864;
    }
    // 0x8009A858: nop

    // 0x8009A85C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009A860: sw          $zero, 0x6B9C($at)
    MEM_W(0X6B9C, ctx->r1) = 0;
L_8009A864:
    // 0x8009A864: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8009A868: lw          $t3, 0x6B9C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6B9C);
    // 0x8009A86C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009A870: bgez        $t3, L_8009A884
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8009A874: andi        $t7, $t3, 0x7
        ctx->r15 = ctx->r11 & 0X7;
            goto L_8009A884;
    }
    // 0x8009A874: andi        $t7, $t3, 0x7
    ctx->r15 = ctx->r11 & 0X7;
    // 0x8009A878: beq         $t7, $zero, L_8009A884
    if (ctx->r15 == 0) {
        // 0x8009A87C: nop
    
            goto L_8009A884;
    }
    // 0x8009A87C: nop

    // 0x8009A880: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
L_8009A884:
    // 0x8009A884: sw          $t7, 0x6B9C($at)
    MEM_W(0X6B9C, ctx->r1) = ctx->r15;
    // 0x8009A888: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8009A88C: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
L_8009A890:
    // 0x8009A890: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8009A894: lw          $t0, 0x6B9C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B9C);
    // 0x8009A898: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8009A89C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8009A8A0: addu        $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
    // 0x8009A8A4: bgez        $t4, L_8009A8B8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8009A8A8: andi        $t9, $t4, 0x7
        ctx->r25 = ctx->r12 & 0X7;
            goto L_8009A8B8;
    }
    // 0x8009A8A8: andi        $t9, $t4, 0x7
    ctx->r25 = ctx->r12 & 0X7;
    // 0x8009A8AC: beq         $t9, $zero, L_8009A8B8
    if (ctx->r25 == 0) {
        // 0x8009A8B0: nop
    
            goto L_8009A8B8;
    }
    // 0x8009A8B0: nop

    // 0x8009A8B4: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_8009A8B8:
    // 0x8009A8B8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8009A8BC: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8009A8C0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8009A8C4: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8009A8C8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8009A8CC: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x8009A8D0: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8009A8D4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x8009A8D8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009A8DC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8009A8E0: jal         0x800AD1E4
    // 0x8009A8E4: nop

    func_800AD1E4(rdram, ctx);
        goto after_1;
    // 0x8009A8E4: nop

    after_1:
    // 0x8009A8E8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009A8EC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009A8F0: lw          $t3, 0x7238($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7238);
    // 0x8009A8F4: lw          $t5, 0xF0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XF0);
    // 0x8009A8F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A8FC: or          $t2, $t3, $t5
    ctx->r10 = ctx->r11 | ctx->r13;
    // 0x8009A900: sw          $t2, 0x7250($at)
    MEM_W(0X7250, ctx->r1) = ctx->r10;
    // 0x8009A904: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8009A908: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009A90C: lw          $t0, 0x7244($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7244);
    // 0x8009A910: lw          $t9, 0xF4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XF4);
    // 0x8009A914: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A918: and         $t6, $t0, $t9
    ctx->r14 = ctx->r8 & ctx->r25;
    // 0x8009A91C: sw          $t6, 0x7258($at)
    MEM_W(0X7258, ctx->r1) = ctx->r14;
    // 0x8009A920: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8009A924: nop

    // 0x8009A928: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x8009A92C: nop

    // 0x8009A930: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8009A934: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8009A938: nop

    // 0x8009A93C: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8009A940: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8009A944: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8009A948: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8009A94C: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8009A950: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x8009A954: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8009A958: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009A95C: lw          $t0, 0x70E4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70E4);
    // 0x8009A960: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8009A964: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8009A968: sll         $t9, $t0, 6
    ctx->r25 = S32(ctx->r8 << 6);
    // 0x8009A96C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009A970: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8009A974: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8009A978: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8009A97C: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8009A980: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8009A984: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8009A988: nop

    // 0x8009A98C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8009A990: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8009A994: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8009A998: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009A99C: sw          $t5, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r13;
    // 0x8009A9A0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009A9A4: lw          $t2, 0x7188($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7188);
    // 0x8009A9A8: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009A9AC: blez        $t2, L_8009AF10
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009A9B0: nop
    
            goto L_8009AF10;
    }
    // 0x8009A9B0: nop

L_8009A9B4:
    // 0x8009A9B4: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A9B8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009A9BC: sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8 << 4);
    // 0x8009A9C0: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8009A9C4: lw          $t9, 0x30CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30CC);
    // 0x8009A9C8: nop

    // 0x8009A9CC: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8009A9D0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8009A9D4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009A9D8: lw          $t1, 0x7250($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7250);
    // 0x8009A9DC: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x8009A9E0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009A9E4: lw          $t3, 0x7258($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7258);
    // 0x8009A9E8: or          $t7, $t8, $t1
    ctx->r15 = ctx->r24 | ctx->r9;
    // 0x8009A9EC: and         $t5, $t7, $t3
    ctx->r13 = ctx->r15 & ctx->r11;
    // 0x8009A9F0: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x8009A9F4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8009A9F8: nop

    // 0x8009A9FC: lh          $t0, 0x116($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X116);
    // 0x8009AA00: nop

    // 0x8009AA04: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8009AA08: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009AA0C: nop

    // 0x8009AA10: andi        $t9, $t4, 0x4000
    ctx->r25 = ctx->r12 & 0X4000;
    // 0x8009AA14: bne         $t9, $zero, L_8009AA8C
    if (ctx->r25 != 0) {
        // 0x8009AA18: nop
    
            goto L_8009AA8C;
    }
    // 0x8009AA18: nop

    // 0x8009AA1C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8009AA20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009AA24: beq         $t6, $at, L_8009AA84
    if (ctx->r14 == ctx->r1) {
        // 0x8009AA28: nop
    
            goto L_8009AA84;
    }
    // 0x8009AA28: nop

    // 0x8009AA2C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8009AA30: nop

    // 0x8009AA34: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x8009AA38: nop

    // 0x8009AA3C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8009AA40: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8009AA44: nop

    // 0x8009AA48: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8009AA4C: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8009AA50: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8009AA54: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8009AA58: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8009AA5C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8009AA60: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8009AA64: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x8009AA68: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x8009AA6C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8009AA70: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8009AA74: nop

    // 0x8009AA78: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8009AA7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009AA80: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_8009AA84:
    // 0x8009AA84: b           L_8009AAF4
    // 0x8009AA88: nop

        goto L_8009AAF4;
    // 0x8009AA88: nop

L_8009AA8C:
    // 0x8009AA8C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8009AA90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009AA94: beq         $t1, $at, L_8009AAF4
    if (ctx->r9 == ctx->r1) {
        // 0x8009AA98: nop
    
            goto L_8009AAF4;
    }
    // 0x8009AA98: nop

    // 0x8009AA9C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8009AAA0: nop

    // 0x8009AAA4: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x8009AAA8: nop

    // 0x8009AAAC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8009AAB0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8009AAB4: nop

    // 0x8009AAB8: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x8009AABC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8009AAC0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8009AAC4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8009AAC8: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8009AACC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x8009AAD0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8009AAD4: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x8009AAD8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8009AADC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8009AAE0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8009AAE4: nop

    // 0x8009AAE8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8009AAEC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8009AAF0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
L_8009AAF4:
    // 0x8009AAF4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009AAF8: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8009AAFC: lw          $t5, 0xE4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XE4);
    // 0x8009AB00: lhu         $t0, 0xC4($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC4);
    // 0x8009AB04: nop

    // 0x8009AB08: and         $t4, $t5, $t0
    ctx->r12 = ctx->r13 & ctx->r8;
    // 0x8009AB0C: beq         $t4, $zero, L_8009AEF4
    if (ctx->r12 == 0) {
        // 0x8009AB10: nop
    
            goto L_8009AEF4;
    }
    // 0x8009AB10: nop

    // 0x8009AB14: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009AB18: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8009AB1C: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x8009AB20: beq         $t6, $zero, L_8009AB44
    if (ctx->r14 == 0) {
        // 0x8009AB24: nop
    
            goto L_8009AB44;
    }
    // 0x8009AB24: nop

    // 0x8009AB28: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009AB2C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009AB30: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009AB34: jal         0x800A4BE4
    // 0x8009AB38: nop

    func_800A4BE4(rdram, ctx);
        goto after_2;
    // 0x8009AB38: nop

    after_2:
    // 0x8009AB3C: b           L_8009AEF4
    // 0x8009AB40: nop

        goto L_8009AEF4;
    // 0x8009AB40: nop

L_8009AB44:
    // 0x8009AB44: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8009AB48: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8009AB4C: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x8009AB50: beq         $t1, $zero, L_8009AB74
    if (ctx->r9 == 0) {
        // 0x8009AB54: nop
    
            goto L_8009AB74;
    }
    // 0x8009AB54: nop

    // 0x8009AB58: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009AB5C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009AB60: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009AB64: jal         0x800A4ED8
    // 0x8009AB68: nop

    func_800A4ED8(rdram, ctx);
        goto after_3;
    // 0x8009AB68: nop

    after_3:
    // 0x8009AB6C: b           L_8009AEF4
    // 0x8009AB70: nop

        goto L_8009AEF4;
    // 0x8009AB70: nop

L_8009AB74:
    // 0x8009AB74: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8009AB78: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8009AB7C: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8009AB80: bne         $t3, $zero, L_8009AE1C
    if (ctx->r11 != 0) {
        // 0x8009AB84: nop
    
            goto L_8009AE1C;
    }
    // 0x8009AB84: nop

    // 0x8009AB88: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8009AB8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009AB90: bne         $t2, $at, L_8009AC04
    if (ctx->r10 != ctx->r1) {
        // 0x8009AB94: nop
    
            goto L_8009AC04;
    }
    // 0x8009AB94: nop

L_8009AB98:
    // 0x8009AB98: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8009AB9C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8009ABA0: and         $t0, $t5, $at
    ctx->r8 = ctx->r13 & ctx->r1;
    // 0x8009ABA4: bne         $t0, $zero, L_8009ABC4
    if (ctx->r8 != 0) {
        // 0x8009ABA8: nop
    
            goto L_8009ABC4;
    }
    // 0x8009ABA8: nop

    // 0x8009ABAC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009ABB0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009ABB4: jal         0x8009B530
    // 0x8009ABB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009B530(rdram, ctx);
        goto after_4;
    // 0x8009ABB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8009ABBC: b           L_8009ABD8
    // 0x8009ABC0: nop

        goto L_8009ABD8;
    // 0x8009ABC0: nop

L_8009ABC4:
    // 0x8009ABC4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009ABC8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009ABCC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009ABD0: jal         0x8009B530
    // 0x8009ABD4: nop

    func_8009B530(rdram, ctx);
        goto after_5;
    // 0x8009ABD4: nop

    after_5:
L_8009ABD8:
    // 0x8009ABD8: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8009ABDC: nop

    // 0x8009ABE0: lw          $t9, 0x14C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14C);
    // 0x8009ABE4: nop

    // 0x8009ABE8: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8009ABEC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8009ABF0: nop

    // 0x8009ABF4: bne         $t6, $zero, L_8009AB98
    if (ctx->r14 != 0) {
        // 0x8009ABF8: nop
    
            goto L_8009AB98;
    }
    // 0x8009ABF8: nop

    // 0x8009ABFC: b           L_8009AE14
    // 0x8009AC00: nop

        goto L_8009AE14;
    // 0x8009AC00: nop

L_8009AC04:
    // 0x8009AC04: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8009AC08: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009AC0C: sw          $t8, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r24;
L_8009AC10:
    // 0x8009AC10: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8009AC14: nop

    // 0x8009AC18: andi        $t7, $t1, 0x8
    ctx->r15 = ctx->r9 & 0X8;
    // 0x8009AC1C: beq         $t7, $zero, L_8009AD80
    if (ctx->r15 == 0) {
        // 0x8009AC20: nop
    
            goto L_8009AD80;
    }
    // 0x8009AC20: nop

    // 0x8009AC24: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8009AC28: nop

    // 0x8009AC2C: andi        $t2, $t3, 0x100
    ctx->r10 = ctx->r11 & 0X100;
    // 0x8009AC30: beq         $t2, $zero, L_8009ACDC
    if (ctx->r10 == 0) {
        // 0x8009AC34: nop
    
            goto L_8009ACDC;
    }
    // 0x8009AC34: nop

    // 0x8009AC38: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8009AC3C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009AC40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009AC44: lwc1        $f4, 0xF8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x8009AC48: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009AC4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009AC50: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009AC54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009AC58: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8009AC5C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8009AC60: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009AC64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009AC68: lwc1        $f6, 0xFC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XFC);
    // 0x8009AC6C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009AC70: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8009AC74: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8009AC78: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009AC7C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8009AC80: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8009AC84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009AC88: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8009AC8C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009AC90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009AC94: lwc1        $f10, 0x100($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X100);
    // 0x8009AC98: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8009AC9C: nop

    // 0x8009ACA0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009ACA4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009ACA8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009ACAC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009ACB0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8009ACB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009ACB8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009ACBC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8009ACC0: lwc1        $f4, 0x104($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X104);
    // 0x8009ACC4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8009ACC8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009ACCC: jal         0x800A19B0
    // 0x8009ACD0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800A19B0(rdram, ctx);
        goto after_6;
    // 0x8009ACD0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8009ACD4: b           L_8009AD78
    // 0x8009ACD8: nop

        goto L_8009AD78;
    // 0x8009ACD8: nop

L_8009ACDC:
    // 0x8009ACDC: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8009ACE0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009ACE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009ACE8: lwc1        $f10, 0xF8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x8009ACEC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009ACF0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8009ACF4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8009ACF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009ACFC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8009AD00: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8009AD04: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009AD08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009AD0C: lwc1        $f16, 0xFC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XFC);
    // 0x8009AD10: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009AD14: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8009AD18: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8009AD1C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009AD20: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009AD24: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8009AD28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009AD2C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009AD30: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009AD34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009AD38: lwc1        $f4, 0x100($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X100);
    // 0x8009AD3C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8009AD40: nop

    // 0x8009AD44: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009AD48: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009AD4C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009AD50: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009AD54: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8009AD58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009AD5C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8009AD60: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8009AD64: lwc1        $f10, 0x104($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X104);
    // 0x8009AD68: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8009AD6C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009AD70: jal         0x8009DB6C
    // 0x8009AD74: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8009DB6C(rdram, ctx);
        goto after_7;
    // 0x8009AD74: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_7:
L_8009AD78:
    // 0x8009AD78: b           L_8009ADC4
    // 0x8009AD7C: nop

        goto L_8009ADC4;
    // 0x8009AD7C: nop

L_8009AD80:
    // 0x8009AD80: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009AD84: nop

    // 0x8009AD88: andi        $t9, $t4, 0x100
    ctx->r25 = ctx->r12 & 0X100;
    // 0x8009AD8C: beq         $t9, $zero, L_8009ADB0
    if (ctx->r25 == 0) {
        // 0x8009AD90: nop
    
            goto L_8009ADB0;
    }
    // 0x8009AD90: nop

    // 0x8009AD94: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009AD98: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009AD9C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009ADA0: jal         0x8009FC68
    // 0x8009ADA4: nop

    func_8009FC68(rdram, ctx);
        goto after_8;
    // 0x8009ADA4: nop

    after_8:
    // 0x8009ADA8: b           L_8009ADC4
    // 0x8009ADAC: nop

        goto L_8009ADC4;
    // 0x8009ADAC: nop

L_8009ADB0:
    // 0x8009ADB0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009ADB4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009ADB8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009ADBC: jal         0x8009B530
    // 0x8009ADC0: nop

    func_8009B530(rdram, ctx);
        goto after_9;
    // 0x8009ADC0: nop

    after_9:
L_8009ADC4:
    // 0x8009ADC4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8009ADC8: nop

    // 0x8009ADCC: lw          $t8, 0x14C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14C);
    // 0x8009ADD0: nop

    // 0x8009ADD4: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8009ADD8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8009ADDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009ADE0: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x8009ADE4: bne         $at, $zero, L_8009ADFC
    if (ctx->r1 != 0) {
        // 0x8009ADE8: nop
    
            goto L_8009ADFC;
    }
    // 0x8009ADE8: nop

    // 0x8009ADEC: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x8009ADF0: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x8009ADF4: bne         $at, $zero, L_8009AE04
    if (ctx->r1 != 0) {
        // 0x8009ADF8: nop
    
            goto L_8009AE04;
    }
    // 0x8009ADF8: nop

L_8009ADFC:
    // 0x8009ADFC: b           L_8009AE14
    // 0x8009AE00: nop

        goto L_8009AE14;
    // 0x8009AE00: nop

L_8009AE04:
    // 0x8009AE04: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8009AE08: nop

    // 0x8009AE0C: bne         $t7, $zero, L_8009AC10
    if (ctx->r15 != 0) {
        // 0x8009AE10: nop
    
            goto L_8009AC10;
    }
    // 0x8009AE10: nop

L_8009AE14:
    // 0x8009AE14: b           L_8009AEF4
    // 0x8009AE18: nop

        goto L_8009AEF4;
    // 0x8009AE18: nop

L_8009AE1C:
    // 0x8009AE1C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8009AE20: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009AE24: sw          $t3, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r11;
    // 0x8009AE28: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8009AE2C: nop

    // 0x8009AE30: andi        $t5, $t2, 0x8
    ctx->r13 = ctx->r10 & 0X8;
    // 0x8009AE34: beq         $t5, $zero, L_8009AEE0
    if (ctx->r13 == 0) {
        // 0x8009AE38: nop
    
            goto L_8009AEE0;
    }
    // 0x8009AE38: nop

    // 0x8009AE3C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8009AE40: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009AE44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009AE48: lwc1        $f4, 0xF8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x8009AE4C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009AE50: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009AE54: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009AE58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009AE5C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8009AE60: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8009AE64: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009AE68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009AE6C: lwc1        $f6, 0xFC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XFC);
    // 0x8009AE70: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009AE74: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8009AE78: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8009AE7C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009AE80: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8009AE84: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8009AE88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009AE8C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8009AE90: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009AE94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009AE98: lwc1        $f10, 0x100($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X100);
    // 0x8009AE9C: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8009AEA0: nop

    // 0x8009AEA4: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009AEA8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009AEAC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009AEB0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009AEB4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8009AEB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009AEBC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009AEC0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8009AEC4: lwc1        $f4, 0x104($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X104);
    // 0x8009AEC8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8009AECC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009AED0: jal         0x800A9564
    // 0x8009AED4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800A9564(rdram, ctx);
        goto after_10;
    // 0x8009AED4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x8009AED8: b           L_8009AEF4
    // 0x8009AEDC: nop

        goto L_8009AEF4;
    // 0x8009AEDC: nop

L_8009AEE0:
    // 0x8009AEE0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009AEE4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009AEE8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009AEEC: jal         0x800A735C
    // 0x8009AEF0: nop

    func_800A735C(rdram, ctx);
        goto after_11;
    // 0x8009AEF0: nop

    after_11:
L_8009AEF4:
    // 0x8009AEF4: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8009AEF8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009AEFC: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x8009AF00: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8009AF04: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009AF08: bne         $at, $zero, L_8009A9B4
    if (ctx->r1 != 0) {
        // 0x8009AF0C: sw          $t9, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r25;
            goto L_8009A9B4;
    }
    // 0x8009AF0C: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
L_8009AF10:
    // 0x8009AF10: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8009AF14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009AF18: sw          $t8, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r24;
    // 0x8009AF1C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009AF20: lw          $t1, 0x7204($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7204);
    // 0x8009AF24: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009AF28: blez        $t1, L_8009B490
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8009AF2C: nop
    
            goto L_8009B490;
    }
    // 0x8009AF2C: nop

L_8009AF30:
    // 0x8009AF30: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8009AF34: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009AF38: sll         $t3, $t7, 4
    ctx->r11 = S32(ctx->r15 << 4);
    // 0x8009AF3C: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8009AF40: lw          $t2, 0x50E4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E4);
    // 0x8009AF44: nop

    // 0x8009AF48: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8009AF4C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8009AF50: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009AF54: lw          $t4, 0x7250($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7250);
    // 0x8009AF58: lw          $t0, 0xC0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC0);
    // 0x8009AF5C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009AF60: lw          $t6, 0x7258($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7258);
    // 0x8009AF64: or          $t9, $t0, $t4
    ctx->r25 = ctx->r8 | ctx->r12;
    // 0x8009AF68: and         $t8, $t9, $t6
    ctx->r24 = ctx->r25 & ctx->r14;
    // 0x8009AF6C: ori         $t1, $t8, 0x8000
    ctx->r9 = ctx->r24 | 0X8000;
    // 0x8009AF70: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x8009AF74: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8009AF78: nop

    // 0x8009AF7C: lh          $t3, 0x116($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X116);
    // 0x8009AF80: nop

    // 0x8009AF84: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8009AF88: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8009AF8C: nop

    // 0x8009AF90: andi        $t5, $t2, 0x4000
    ctx->r13 = ctx->r10 & 0X4000;
    // 0x8009AF94: bne         $t5, $zero, L_8009B00C
    if (ctx->r13 != 0) {
        // 0x8009AF98: nop
    
            goto L_8009B00C;
    }
    // 0x8009AF98: nop

    // 0x8009AF9C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8009AFA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009AFA4: beq         $t0, $at, L_8009B004
    if (ctx->r8 == ctx->r1) {
        // 0x8009AFA8: nop
    
            goto L_8009B004;
    }
    // 0x8009AFA8: nop

    // 0x8009AFAC: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8009AFB0: nop

    // 0x8009AFB4: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8009AFB8: nop

    // 0x8009AFBC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8009AFC0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8009AFC4: nop

    // 0x8009AFC8: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8009AFCC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8009AFD0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8009AFD4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8009AFD8: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x8009AFDC: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x8009AFE0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8009AFE4: lui         $t3, 0x2
    ctx->r11 = S32(0X2 << 16);
    // 0x8009AFE8: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x8009AFEC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8009AFF0: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x8009AFF4: nop

    // 0x8009AFF8: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8009AFFC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009B000: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
L_8009B004:
    // 0x8009B004: b           L_8009B074
    // 0x8009B008: nop

        goto L_8009B074;
    // 0x8009B008: nop

L_8009B00C:
    // 0x8009B00C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8009B010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009B014: beq         $t9, $at, L_8009B074
    if (ctx->r25 == ctx->r1) {
        // 0x8009B018: nop
    
            goto L_8009B074;
    }
    // 0x8009B018: nop

    // 0x8009B01C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8009B020: nop

    // 0x8009B024: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8009B028: nop

    // 0x8009B02C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8009B030: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8009B034: nop

    // 0x8009B038: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x8009B03C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8009B040: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8009B044: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8009B048: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8009B04C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8009B050: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8009B054: lui         $t5, 0x2
    ctx->r13 = S32(0X2 << 16);
    // 0x8009B058: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8009B05C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8009B060: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8009B064: nop

    // 0x8009B068: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8009B06C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8009B070: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_8009B074:
    // 0x8009B074: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009B078: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8009B07C: lw          $t1, 0xE4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0XE4);
    // 0x8009B080: lhu         $t3, 0xC4($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0XC4);
    // 0x8009B084: nop

    // 0x8009B088: and         $t2, $t1, $t3
    ctx->r10 = ctx->r9 & ctx->r11;
    // 0x8009B08C: beq         $t2, $zero, L_8009B474
    if (ctx->r10 == 0) {
        // 0x8009B090: nop
    
            goto L_8009B474;
    }
    // 0x8009B090: nop

    // 0x8009B094: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8009B098: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8009B09C: and         $t0, $t5, $at
    ctx->r8 = ctx->r13 & ctx->r1;
    // 0x8009B0A0: beq         $t0, $zero, L_8009B0C4
    if (ctx->r8 == 0) {
        // 0x8009B0A4: nop
    
            goto L_8009B0C4;
    }
    // 0x8009B0A4: nop

    // 0x8009B0A8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B0AC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B0B0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009B0B4: jal         0x800A4BE4
    // 0x8009B0B8: nop

    func_800A4BE4(rdram, ctx);
        goto after_12;
    // 0x8009B0B8: nop

    after_12:
    // 0x8009B0BC: b           L_8009B474
    // 0x8009B0C0: nop

        goto L_8009B474;
    // 0x8009B0C0: nop

L_8009B0C4:
    // 0x8009B0C4: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009B0C8: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8009B0CC: and         $t9, $t4, $at
    ctx->r25 = ctx->r12 & ctx->r1;
    // 0x8009B0D0: beq         $t9, $zero, L_8009B0F4
    if (ctx->r25 == 0) {
        // 0x8009B0D4: nop
    
            goto L_8009B0F4;
    }
    // 0x8009B0D4: nop

    // 0x8009B0D8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B0DC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B0E0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009B0E4: jal         0x800A4ED8
    // 0x8009B0E8: nop

    func_800A4ED8(rdram, ctx);
        goto after_13;
    // 0x8009B0E8: nop

    after_13:
    // 0x8009B0EC: b           L_8009B474
    // 0x8009B0F0: nop

        goto L_8009B474;
    // 0x8009B0F0: nop

L_8009B0F4:
    // 0x8009B0F4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8009B0F8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8009B0FC: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8009B100: bne         $t8, $zero, L_8009B39C
    if (ctx->r24 != 0) {
        // 0x8009B104: nop
    
            goto L_8009B39C;
    }
    // 0x8009B104: nop

    // 0x8009B108: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009B10C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009B110: bne         $t7, $at, L_8009B184
    if (ctx->r15 != ctx->r1) {
        // 0x8009B114: nop
    
            goto L_8009B184;
    }
    // 0x8009B114: nop

L_8009B118:
    // 0x8009B118: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8009B11C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8009B120: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8009B124: bne         $t3, $zero, L_8009B144
    if (ctx->r11 != 0) {
        // 0x8009B128: nop
    
            goto L_8009B144;
    }
    // 0x8009B128: nop

    // 0x8009B12C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B130: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B134: jal         0x8009B530
    // 0x8009B138: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009B530(rdram, ctx);
        goto after_14;
    // 0x8009B138: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x8009B13C: b           L_8009B158
    // 0x8009B140: nop

        goto L_8009B158;
    // 0x8009B140: nop

L_8009B144:
    // 0x8009B144: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B148: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B14C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009B150: jal         0x8009B530
    // 0x8009B154: nop

    func_8009B530(rdram, ctx);
        goto after_15;
    // 0x8009B154: nop

    after_15:
L_8009B158:
    // 0x8009B158: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8009B15C: nop

    // 0x8009B160: lw          $t5, 0x14C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X14C);
    // 0x8009B164: nop

    // 0x8009B168: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x8009B16C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8009B170: nop

    // 0x8009B174: bne         $t0, $zero, L_8009B118
    if (ctx->r8 != 0) {
        // 0x8009B178: nop
    
            goto L_8009B118;
    }
    // 0x8009B178: nop

    // 0x8009B17C: b           L_8009B394
    // 0x8009B180: nop

        goto L_8009B394;
    // 0x8009B180: nop

L_8009B184:
    // 0x8009B184: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8009B188: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009B18C: sw          $t4, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r12;
L_8009B190:
    // 0x8009B190: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009B194: nop

    // 0x8009B198: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x8009B19C: beq         $t6, $zero, L_8009B300
    if (ctx->r14 == 0) {
        // 0x8009B1A0: nop
    
            goto L_8009B300;
    }
    // 0x8009B1A0: nop

    // 0x8009B1A4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8009B1A8: nop

    // 0x8009B1AC: andi        $t7, $t8, 0x100
    ctx->r15 = ctx->r24 & 0X100;
    // 0x8009B1B0: beq         $t7, $zero, L_8009B25C
    if (ctx->r15 == 0) {
        // 0x8009B1B4: nop
    
            goto L_8009B25C;
    }
    // 0x8009B1B4: nop

    // 0x8009B1B8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8009B1BC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009B1C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B1C4: lwc1        $f10, 0xF8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x8009B1C8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009B1CC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8009B1D0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8009B1D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009B1D8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8009B1DC: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8009B1E0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009B1E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009B1E8: lwc1        $f16, 0xFC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x8009B1EC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009B1F0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8009B1F4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8009B1F8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009B1FC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009B200: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8009B204: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009B208: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009B20C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009B210: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009B214: lwc1        $f4, 0x100($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X100);
    // 0x8009B218: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8009B21C: nop

    // 0x8009B220: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009B224: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009B228: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B22C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B230: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8009B234: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B238: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8009B23C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8009B240: lwc1        $f10, 0x104($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X104);
    // 0x8009B244: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009B248: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009B24C: jal         0x800A19B0
    // 0x8009B250: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800A19B0(rdram, ctx);
        goto after_16;
    // 0x8009B250: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x8009B254: b           L_8009B2F8
    // 0x8009B258: nop

        goto L_8009B2F8;
    // 0x8009B258: nop

L_8009B25C:
    // 0x8009B25C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009B260: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009B264: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009B268: lwc1        $f4, 0xF8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x8009B26C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009B270: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009B274: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009B278: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009B27C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8009B280: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8009B284: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009B288: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009B28C: lwc1        $f6, 0xFC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XFC);
    // 0x8009B290: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009B294: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8009B298: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8009B29C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009B2A0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8009B2A4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8009B2A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009B2AC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8009B2B0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009B2B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B2B8: lwc1        $f10, 0x100($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X100);
    // 0x8009B2BC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8009B2C0: nop

    // 0x8009B2C4: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009B2C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009B2CC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B2D0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B2D4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8009B2D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009B2DC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009B2E0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8009B2E4: lwc1        $f4, 0x104($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X104);
    // 0x8009B2E8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8009B2EC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009B2F0: jal         0x8009DB6C
    // 0x8009B2F4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_8009DB6C(rdram, ctx);
        goto after_17;
    // 0x8009B2F4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_17:
L_8009B2F8:
    // 0x8009B2F8: b           L_8009B344
    // 0x8009B2FC: nop

        goto L_8009B344;
    // 0x8009B2FC: nop

L_8009B300:
    // 0x8009B300: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8009B304: nop

    // 0x8009B308: andi        $t5, $t2, 0x100
    ctx->r13 = ctx->r10 & 0X100;
    // 0x8009B30C: beq         $t5, $zero, L_8009B330
    if (ctx->r13 == 0) {
        // 0x8009B310: nop
    
            goto L_8009B330;
    }
    // 0x8009B310: nop

    // 0x8009B314: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B318: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B31C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009B320: jal         0x8009FC68
    // 0x8009B324: nop

    func_8009FC68(rdram, ctx);
        goto after_18;
    // 0x8009B324: nop

    after_18:
    // 0x8009B328: b           L_8009B344
    // 0x8009B32C: nop

        goto L_8009B344;
    // 0x8009B32C: nop

L_8009B330:
    // 0x8009B330: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B334: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B338: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009B33C: jal         0x8009B530
    // 0x8009B340: nop

    func_8009B530(rdram, ctx);
        goto after_19;
    // 0x8009B340: nop

    after_19:
L_8009B344:
    // 0x8009B344: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8009B348: nop

    // 0x8009B34C: lw          $t4, 0x14C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X14C);
    // 0x8009B350: nop

    // 0x8009B354: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8009B358: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8009B35C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009B360: sltu        $at, $t9, $at
    ctx->r1 = ctx->r25 < ctx->r1 ? 1 : 0;
    // 0x8009B364: bne         $at, $zero, L_8009B37C
    if (ctx->r1 != 0) {
        // 0x8009B368: nop
    
            goto L_8009B37C;
    }
    // 0x8009B368: nop

    // 0x8009B36C: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x8009B370: sltu        $at, $t9, $at
    ctx->r1 = ctx->r25 < ctx->r1 ? 1 : 0;
    // 0x8009B374: bne         $at, $zero, L_8009B384
    if (ctx->r1 != 0) {
        // 0x8009B378: nop
    
            goto L_8009B384;
    }
    // 0x8009B378: nop

L_8009B37C:
    // 0x8009B37C: b           L_8009B394
    // 0x8009B380: nop

        goto L_8009B394;
    // 0x8009B380: nop

L_8009B384:
    // 0x8009B384: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8009B388: nop

    // 0x8009B38C: bne         $t6, $zero, L_8009B190
    if (ctx->r14 != 0) {
        // 0x8009B390: nop
    
            goto L_8009B190;
    }
    // 0x8009B390: nop

L_8009B394:
    // 0x8009B394: b           L_8009B474
    // 0x8009B398: nop

        goto L_8009B474;
    // 0x8009B398: nop

L_8009B39C:
    // 0x8009B39C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8009B3A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009B3A4: sw          $t8, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r24;
    // 0x8009B3A8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8009B3AC: nop

    // 0x8009B3B0: andi        $t1, $t7, 0x8
    ctx->r9 = ctx->r15 & 0X8;
    // 0x8009B3B4: beq         $t1, $zero, L_8009B460
    if (ctx->r9 == 0) {
        // 0x8009B3B8: nop
    
            goto L_8009B460;
    }
    // 0x8009B3B8: nop

    // 0x8009B3BC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009B3C0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009B3C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B3C8: lwc1        $f10, 0xF8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x8009B3CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009B3D0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8009B3D4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8009B3D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009B3DC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8009B3E0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8009B3E4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009B3E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009B3EC: lwc1        $f16, 0xFC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XFC);
    // 0x8009B3F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8009B3F4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8009B3F8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8009B3FC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009B400: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009B404: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8009B408: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009B40C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009B410: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8009B414: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009B418: lwc1        $f4, 0x100($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X100);
    // 0x8009B41C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8009B420: nop

    // 0x8009B424: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009B428: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009B42C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B430: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B434: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8009B438: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B43C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8009B440: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8009B444: lwc1        $f10, 0x104($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X104);
    // 0x8009B448: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8009B44C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009B450: jal         0x800A9564
    // 0x8009B454: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800A9564(rdram, ctx);
        goto after_20;
    // 0x8009B454: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x8009B458: b           L_8009B474
    // 0x8009B45C: nop

        goto L_8009B474;
    // 0x8009B45C: nop

L_8009B460:
    // 0x8009B460: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B464: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009B468: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8009B46C: jal         0x800A735C
    // 0x8009B470: nop

    func_800A735C(rdram, ctx);
        goto after_21;
    // 0x8009B470: nop

    after_21:
L_8009B474:
    // 0x8009B474: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8009B478: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009B47C: lw          $t0, 0x7204($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7204);
    // 0x8009B480: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8009B484: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8009B488: bne         $at, $zero, L_8009AF30
    if (ctx->r1 != 0) {
        // 0x8009B48C: sw          $t5, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r13;
            goto L_8009AF30;
    }
    // 0x8009B48C: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
L_8009B490:
    // 0x8009B490: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8009B494: nop

    // 0x8009B498: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8009B49C: bgez        $t9, L_8009A890
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8009B4A0: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_8009A890;
    }
    // 0x8009B4A0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8009B4A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009B4A8: sw          $zero, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = 0;
    // 0x8009B4AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009B4B0: sw          $zero, 0x7204($at)
    MEM_W(0X7204, ctx->r1) = 0;
    // 0x8009B4B4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8009B4B8: nop

    // 0x8009B4BC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8009B4C0: nop

    // 0x8009B4C4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8009B4C8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8009B4CC: nop

    // 0x8009B4D0: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x8009B4D4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8009B4D8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8009B4DC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B4E0: lui         $t3, 0x380
    ctx->r11 = S32(0X380 << 16);
    // 0x8009B4E4: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8009B4E8: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8009B4EC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B4F0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8009B4F4: addiu       $t5, $t5, 0x6BB0
    ctx->r13 = ADD32(ctx->r13, 0X6BB0);
    // 0x8009B4F8: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8009B4FC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8009B500: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8009B504: nop

    // 0x8009B508: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8009B50C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009B510: jal         0x800AC524
    // 0x8009B514: nop

    func_800AC524(rdram, ctx);
        goto after_22;
    // 0x8009B514: nop

    after_22:
    // 0x8009B518: b           L_8009B520
    // 0x8009B51C: nop

        goto L_8009B520;
    // 0x8009B51C: nop

L_8009B520:
    // 0x8009B520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009B524: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8009B528: jr          $ra
    // 0x8009B52C: nop

    return;
    // 0x8009B52C: nop

;}
RECOMP_FUNC void func_80068CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068CA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068CAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068CB0: nop

    // 0x80068CB4: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x80068CB8: nop

    // 0x80068CBC: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068CC0: jr          $ra
    // 0x80068CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068CC8: jr          $ra
    // 0x80068CCC: nop

    return;
    // 0x80068CCC: nop

    // 0x80068CD0: jr          $ra
    // 0x80068CD4: nop

    return;
    // 0x80068CD4: nop

;}
RECOMP_FUNC void SoundDebugMenu_BGMTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800218CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800218D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800218D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800218D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800218DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800218E0: nop

    // 0x800218E4: bltz        $t6, L_80021A9C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800218E8: nop
    
            goto L_80021A9C;
    }
    // 0x800218E8: nop

    // 0x800218EC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800218F0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x800218F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800218F8: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x800218FC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021900: nop

    // 0x80021904: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021908: beq         $t0, $zero, L_80021924
    if (ctx->r8 == 0) {
        // 0x8002190C: nop
    
            goto L_80021924;
    }
    // 0x8002190C: nop

    // 0x80021910: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021914: lw          $t1, -0x33BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33BC);
    // 0x80021918: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002191C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021920: sw          $t2, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r10;
L_80021924:
    // 0x80021924: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021928: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8002192C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021930: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x80021934: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80021938: nop

    // 0x8002193C: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80021940: beq         $t6, $zero, L_8002195C
    if (ctx->r14 == 0) {
        // 0x80021944: nop
    
            goto L_8002195C;
    }
    // 0x80021944: nop

    // 0x80021948: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8002194C: lw          $t7, -0x33BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33BC);
    // 0x80021950: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021954: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80021958: sw          $t8, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r24;
L_8002195C:
    // 0x8002195C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80021960: lw          $t9, -0x33BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33BC);
    // 0x80021964: nop

    // 0x80021968: bgez        $t9, L_80021978
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002196C: nop
    
            goto L_80021978;
    }
    // 0x8002196C: nop

    // 0x80021970: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021974: sw          $zero, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = 0;
L_80021978:
    // 0x80021978: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8002197C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80021980: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021984: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x80021988: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x8002198C: nop

    // 0x80021990: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80021994: beq         $t3, $zero, L_800219AC
    if (ctx->r11 == 0) {
        // 0x80021998: nop
    
            goto L_800219AC;
    }
    // 0x80021998: nop

    // 0x8002199C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800219A0: lw          $a0, -0x33BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33BC);
    // 0x800219A4: jal         0x80021ED0
    // 0x800219A8: nop

    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_0;
    // 0x800219A8: nop

    after_0:
L_800219AC:
    // 0x800219AC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800219B0: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x800219B4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800219B8: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x800219BC: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800219C0: nop

    // 0x800219C4: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x800219C8: beq         $t7, $zero, L_800219D8
    if (ctx->r15 == 0) {
        // 0x800219CC: nop
    
            goto L_800219D8;
    }
    // 0x800219CC: nop

    // 0x800219D0: jal         0x800B8FA8
    // 0x800219D4: nop

    AudioMgr_StopMusic(rdram, ctx);
        goto after_1;
    // 0x800219D4: nop

    after_1:
L_800219D8:
    // 0x800219D8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800219DC: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800219E0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800219E4: lhu         $t0, 0x1258($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X1258);
    // 0x800219E8: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800219EC: nop

    // 0x800219F0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800219F4: beq         $t1, $zero, L_80021A10
    if (ctx->r9 == 0) {
        // 0x800219F8: nop
    
            goto L_80021A10;
    }
    // 0x800219F8: nop

    // 0x800219FC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80021A00: lh          $t2, -0x48A8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X48A8);
    // 0x80021A04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021A08: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80021A0C: sh          $t3, -0x48A8($at)
    MEM_H(-0X48A8, ctx->r1) = ctx->r11;
L_80021A10:
    // 0x80021A10: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021A14: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80021A18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021A1C: lhu         $t6, 0x1260($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1260);
    // 0x80021A20: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x80021A24: nop

    // 0x80021A28: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80021A2C: beq         $t7, $zero, L_80021A48
    if (ctx->r15 == 0) {
        // 0x80021A30: nop
    
            goto L_80021A48;
    }
    // 0x80021A30: nop

    // 0x80021A34: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80021A38: lh          $t8, -0x48A8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X48A8);
    // 0x80021A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021A40: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80021A44: sh          $t9, -0x48A8($at)
    MEM_H(-0X48A8, ctx->r1) = ctx->r25;
L_80021A48:
    // 0x80021A48: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80021A4C: lh          $t0, -0x48A8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X48A8);
    // 0x80021A50: nop

    // 0x80021A54: bgez        $t0, L_80021A68
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80021A58: nop
    
            goto L_80021A68;
    }
    // 0x80021A58: nop

    // 0x80021A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80021A60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021A64: sh          $t1, -0x48A8($at)
    MEM_H(-0X48A8, ctx->r1) = ctx->r9;
L_80021A68:
    // 0x80021A68: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80021A6C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80021A70: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80021A74: lhu         $t4, 0x126C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X126C);
    // 0x80021A78: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80021A7C: nop

    // 0x80021A80: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80021A84: beq         $t5, $zero, L_80021A9C
    if (ctx->r13 == 0) {
        // 0x80021A88: nop
    
            goto L_80021A9C;
    }
    // 0x80021A88: nop

    // 0x80021A8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80021A90: lh          $a0, -0x48A8($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X48A8);
    // 0x80021A94: jal         0x80021F20
    // 0x80021A98: nop

    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_2;
    // 0x80021A98: nop

    after_2:
L_80021A9C:
    // 0x80021A9C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80021AA0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80021AA4: lh          $a2, -0x48A8($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X48A8);
    // 0x80021AA8: lw          $a1, -0x33BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33BC);
    // 0x80021AAC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021AB0: jal         0x8008ECE4
    // 0x80021AB4: addiu       $a0, $a0, -0x1D24
    ctx->r4 = ADD32(ctx->r4, -0X1D24);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x80021AB4: addiu       $a0, $a0, -0x1D24
    ctx->r4 = ADD32(ctx->r4, -0X1D24);
    after_3:
    // 0x80021AB8: b           L_80021AC8
    // 0x80021ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021AC8;
    // 0x80021ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021AC0: b           L_80021AC8
    // 0x80021AC4: nop

        goto L_80021AC8;
    // 0x80021AC4: nop

L_80021AC8:
    // 0x80021AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021AD0: jr          $ra
    // 0x80021AD4: nop

    return;
    // 0x80021AD4: nop

;}
RECOMP_FUNC void func_80063304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006330C: jal         0x8005F064
    // 0x80063310: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063310: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_0:
    // 0x80063314: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063318: b           L_80063328
    // 0x8006331C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063328;
    // 0x8006331C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063320: b           L_80063328
    // 0x80063324: nop

        goto L_80063328;
    // 0x80063324: nop

L_80063328:
    // 0x80063328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006332C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063330: jr          $ra
    // 0x80063334: nop

    return;
    // 0x80063334: nop

;}
RECOMP_FUNC void func_8008B1D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B1DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B1E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008B1E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008B1E8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008B1F0: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008B1F4: lwc1        $f4, 0xC28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC28);
    // 0x8008B1F8: lwc1        $f10, 0xC24($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC24);
    // 0x8008B1FC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008B200: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8008B204: swc1        $f16, 0xC24($t6)
    MEM_W(0XC24, ctx->r14) = ctx->f16.u32l;
    // 0x8008B208: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008B20C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8008B210: lwc1        $f18, 0xC24($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC24);
    // 0x8008B214: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008B218: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008B21C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8008B220: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8008B224: nop

    // 0x8008B228: bc1f        L_8008B25C
    if (!c1cs) {
        // 0x8008B22C: nop
    
            goto L_8008B25C;
    }
    // 0x8008B22C: nop

    // 0x8008B230: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8008B234: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B238: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008B23C: nop

    // 0x8008B240: swc1        $f10, 0xC24($t8)
    MEM_W(0XC24, ctx->r24) = ctx->f10.u32l;
    // 0x8008B244: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008B248: nop

    // 0x8008B24C: lwc1        $f8, 0xC28($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC28);
    // 0x8008B250: nop

    // 0x8008B254: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8008B258: swc1        $f16, 0xC28($t9)
    MEM_W(0XC28, ctx->r25) = ctx->f16.u32l;
L_8008B25C:
    // 0x8008B25C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008B260: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8008B264: lwc1        $f18, 0xC24($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XC24);
    // 0x8008B268: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008B26C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8008B270: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8008B274: nop

    // 0x8008B278: bc1f        L_8008B2A8
    if (!c1cs) {
        // 0x8008B27C: nop
    
            goto L_8008B2A8;
    }
    // 0x8008B27C: nop

    // 0x8008B280: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008B284: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008B288: nop

    // 0x8008B28C: swc1        $f10, 0xC24($t1)
    MEM_W(0XC24, ctx->r9) = ctx->f10.u32l;
    // 0x8008B290: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008B294: nop

    // 0x8008B298: lwc1        $f8, 0xC28($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC28);
    // 0x8008B29C: nop

    // 0x8008B2A0: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8008B2A4: swc1        $f16, 0xC28($t2)
    MEM_W(0XC28, ctx->r10) = ctx->f16.u32l;
L_8008B2A8:
    // 0x8008B2A8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8008B2AC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008B2B0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8008B2B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008B2B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008B2BC: lwc1        $f18, 0xC24($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC24);
    // 0x8008B2C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B2C4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8008B2C8: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8008B2CC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8008B2D0: sh          $t5, 0x11E($t6)
    MEM_H(0X11E, ctx->r14) = ctx->r13;
    // 0x8008B2D4: nop

    // 0x8008B2D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B2DC: jal         0x8008B18C
    // 0x8008B2E0: nop

    func_8008B18C(rdram, ctx);
        goto after_0;
    // 0x8008B2E0: nop

    after_0:
    // 0x8008B2E4: b           L_8008B2EC
    // 0x8008B2E8: nop

        goto L_8008B2EC;
    // 0x8008B2E8: nop

L_8008B2EC:
    // 0x8008B2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B2F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B2F4: jr          $ra
    // 0x8008B2F8: nop

    return;
    // 0x8008B2F8: nop

;}
RECOMP_FUNC void func_8006D514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D51C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D520: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D524: nop

    // 0x8006D528: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D52C: nop

    // 0x8006D530: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D534: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D538: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D53C: beq         $v0, $zero, L_8006D560
    if (ctx->r2 == 0) {
        // 0x8006D540: nop
    
            goto L_8006D560;
    }
    // 0x8006D540: nop

    // 0x8006D544: jal         0x80061348
    // 0x8006D548: addiu       $a0, $zero, 0x71B
    ctx->r4 = ADD32(0, 0X71B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D548: addiu       $a0, $zero, 0x71B
    ctx->r4 = ADD32(0, 0X71B);
    after_0:
    // 0x8006D54C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006D550: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006D554: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D558: bne         $v0, $zero, L_8006D59C
    if (ctx->r2 != 0) {
        // 0x8006D55C: nop
    
            goto L_8006D59C;
    }
    // 0x8006D55C: nop

L_8006D560:
    // 0x8006D560: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8006D564: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8006D568: nop

    // 0x8006D56C: lh          $v0, 0x12($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X12);
    // 0x8006D570: nop

    // 0x8006D574: slti        $t0, $v0, 0x12C
    ctx->r8 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D578: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x8006D57C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006D580: beq         $v0, $zero, L_8006D59C
    if (ctx->r2 == 0) {
        // 0x8006D584: nop
    
            goto L_8006D59C;
    }
    // 0x8006D584: nop

    // 0x8006D588: jal         0x80061348
    // 0x8006D58C: addiu       $a0, $zero, 0x71C
    ctx->r4 = ADD32(0, 0X71C);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006D58C: addiu       $a0, $zero, 0x71C
    ctx->r4 = ADD32(0, 0X71C);
    after_1:
    // 0x8006D590: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006D594: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006D598: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8006D59C:
    // 0x8006D59C: b           L_8006D5AC
    // 0x8006D5A0: nop

        goto L_8006D5AC;
    // 0x8006D5A0: nop

    // 0x8006D5A4: b           L_8006D5AC
    // 0x8006D5A8: nop

        goto L_8006D5AC;
    // 0x8006D5A8: nop

L_8006D5AC:
    // 0x8006D5AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D5B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D5B4: jr          $ra
    // 0x8006D5B8: nop

    return;
    // 0x8006D5B8: nop

;}
RECOMP_FUNC void func_8005ADB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ADB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005ADBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005ADC0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005ADC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005ADC8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8005ADCC: nop

    // 0x8005ADD0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8005ADD4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005ADD8: nop

    // 0x8005ADDC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8005ADE0: nop

    // 0x8005ADE4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8005ADE8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005ADEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005ADF0: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x8005ADF4: lw          $t0, 0x2F9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2F9);
    // 0x8005ADF8: nop

    // 0x8005ADFC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8005AE00: sw          $t0, 0xE70($at)
    MEM_W(0XE70, ctx->r1) = ctx->r8;
    // 0x8005AE04: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005AE08: lw          $t1, 0xE70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE70);
    // 0x8005AE0C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AE10: lh          $t2, 0x7C($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X7C);
    // 0x8005AE14: nop

    // 0x8005AE18: bne         $t2, $at, L_8005AE30
    if (ctx->r10 != ctx->r1) {
        // 0x8005AE1C: nop
    
            goto L_8005AE30;
    }
    // 0x8005AE1C: nop

    // 0x8005AE20: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AE24: addiu       $t3, $t3, 0x1280
    ctx->r11 = ADD32(ctx->r11, 0X1280);
    // 0x8005AE28: b           L_8005AE44
    // 0x8005AE2C: sw          $t3, 0xB4($t1)
    MEM_W(0XB4, ctx->r9) = ctx->r11;
        goto L_8005AE44;
    // 0x8005AE2C: sw          $t3, 0xB4($t1)
    MEM_W(0XB4, ctx->r9) = ctx->r11;
L_8005AE30:
    // 0x8005AE30: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AE34: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8005AE38: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005AE3C: addiu       $t4, $t4, 0x1290
    ctx->r12 = ADD32(ctx->r12, 0X1290);
    // 0x8005AE40: sw          $t4, 0xB4($t5)
    MEM_W(0XB4, ctx->r13) = ctx->r12;
L_8005AE44:
    // 0x8005AE44: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AE48: nop

    // 0x8005AE4C: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8005AE50: jal         0x80098754
    // 0x8005AE54: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8005AE54: nop

    after_0:
    // 0x8005AE58: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AE5C: jal         0x80032410
    // 0x8005AE60: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x8005AE60: nop

    after_1:
    // 0x8005AE64: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005AE68: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005AE6C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005AE70: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8005AE74: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AE78: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005AE7C: bne         $t0, $zero, L_8005AEC0
    if (ctx->r8 != 0) {
        // 0x8005AE80: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005AEC0;
    }
    // 0x8005AE80: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005AE84: bne         $t1, $zero, L_8005AEC0
    if (ctx->r9 != 0) {
        // 0x8005AE88: nop
    
            goto L_8005AEC0;
    }
    // 0x8005AE88: nop

L_8005AE8C:
    // 0x8005AE8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AE90: jal         0x800499B0
    // 0x8005AE94: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8005AE94: nop

    after_2:
    // 0x8005AE98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005AE9C: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005AEA0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005AEA4: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8005AEA8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AEAC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8005AEB0: bne         $t6, $zero, L_8005AEC0
    if (ctx->r14 != 0) {
        // 0x8005AEB4: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_8005AEC0;
    }
    // 0x8005AEB4: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005AEB8: beq         $t7, $zero, L_8005AE8C
    if (ctx->r15 == 0) {
        // 0x8005AEBC: nop
    
            goto L_8005AE8C;
    }
    // 0x8005AEBC: nop

L_8005AEC0:
    // 0x8005AEC0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8005AEC4: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8005AEC8: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x8005AECC: nop

    // 0x8005AED0: andi        $t9, $t8, 0x402
    ctx->r25 = ctx->r24 & 0X402;
    // 0x8005AED4: beq         $t9, $zero, L_8005AF04
    if (ctx->r25 == 0) {
        // 0x8005AED8: nop
    
            goto L_8005AF04;
    }
    // 0x8005AED8: nop

L_8005AEDC:
    // 0x8005AEDC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AEE0: jal         0x800499B0
    // 0x8005AEE4: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8005AEE4: nop

    after_3:
    // 0x8005AEE8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8005AEEC: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8005AEF0: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8005AEF4: nop

    // 0x8005AEF8: andi        $t2, $t1, 0x402
    ctx->r10 = ctx->r9 & 0X402;
    // 0x8005AEFC: bne         $t2, $zero, L_8005AEDC
    if (ctx->r10 != 0) {
        // 0x8005AF00: nop
    
            goto L_8005AEDC;
    }
    // 0x8005AF00: nop

L_8005AF04:
    // 0x8005AF04: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005AF08: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AF0C: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8005AF10: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005AF14: nop

    // 0x8005AF18: sw          $t4, 0xB0($t5)
    MEM_W(0XB0, ctx->r13) = ctx->r12;
    // 0x8005AF1C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF20: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AF24: lh          $a2, 0x7C($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X7C);
    // 0x8005AF28: lw          $a3, 0x44($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X44);
    // 0x8005AF2C: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x8005AF30: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005AF34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005AF38: jal         0x80050A24
    // 0x8005AF3C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80050A24(rdram, ctx);
        goto after_4;
    // 0x8005AF3C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_4:
    // 0x8005AF40: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF44: nop

    // 0x8005AF48: sw          $zero, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = 0;
    // 0x8005AF4C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF50: nop

    // 0x8005AF54: lw          $t9, 0xA8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XA8);
    // 0x8005AF58: nop

    // 0x8005AF5C: sw          $t9, 0xA4($t8)
    MEM_W(0XA4, ctx->r24) = ctx->r25;
    // 0x8005AF60: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF64: nop

    // 0x8005AF68: lh          $t1, 0xAC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XAC);
    // 0x8005AF6C: nop

    // 0x8005AF70: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x8005AF74: sh          $t2, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r10;
    // 0x8005AF78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005AF7C:
    // 0x8005AF7C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF80: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AF84: lh          $t5, 0x7C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X7C);
    // 0x8005AF88: nop

    // 0x8005AF8C: bne         $t5, $at, L_8005AFA0
    if (ctx->r13 != ctx->r1) {
        // 0x8005AF90: nop
    
            goto L_8005AFA0;
    }
    // 0x8005AF90: nop

    // 0x8005AF94: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AF98: b           L_8005AFA8
    // 0x8005AF9C: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
        goto L_8005AFA8;
    // 0x8005AF9C: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
L_8005AFA0:
    // 0x8005AFA0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AFA4: addiu       $s0, $s0, 0x1290
    ctx->r16 = ADD32(ctx->r16, 0X1290);
L_8005AFA8:
    // 0x8005AFA8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AFAC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005AFB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AFB4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005AFB8: addiu       $a2, $a2, 0x1270
    ctx->r6 = ADD32(ctx->r6, 0X1270);
    // 0x8005AFBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005AFC0: jal         0x8005B110
    // 0x8005AFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8005B110(rdram, ctx);
        goto after_5;
    // 0x8005AFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_5:
    // 0x8005AFC8: beq         $v0, $zero, L_8005B00C
    if (ctx->r2 == 0) {
        // 0x8005AFCC: nop
    
            goto L_8005B00C;
    }
    // 0x8005AFCC: nop

    // 0x8005AFD0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005AFD4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AFD8: lh          $t3, 0x7C($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X7C);
    // 0x8005AFDC: nop

    // 0x8005AFE0: bne         $t3, $at, L_8005AFF4
    if (ctx->r11 != ctx->r1) {
        // 0x8005AFE4: nop
    
            goto L_8005AFF4;
    }
    // 0x8005AFE4: nop

    // 0x8005AFE8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AFEC: b           L_8005AFFC
    // 0x8005AFF0: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
        goto L_8005AFFC;
    // 0x8005AFF0: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
L_8005AFF4:
    // 0x8005AFF4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AFF8: addiu       $s0, $s0, 0x1290
    ctx->r16 = ADD32(ctx->r16, 0X1290);
L_8005AFFC:
    // 0x8005AFFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005B000: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B004: jal         0x8005B490
    // 0x8005B008: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8005B490(rdram, ctx);
        goto after_6;
    // 0x8005B008: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
L_8005B00C:
    // 0x8005B00C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005B010: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B014: jal         0x8005B610
    // 0x8005B018: nop

    func_8005B610(rdram, ctx);
        goto after_7;
    // 0x8005B018: nop

    after_7:
    // 0x8005B01C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B020: jal         0x800499B0
    // 0x8005B024: nop

    func_800499B0(rdram, ctx);
        goto after_8;
    // 0x8005B024: nop

    after_8:
    // 0x8005B028: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B02C: nop

    // 0x8005B030: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8005B034: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8005B038: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B03C: nop

    // 0x8005B040: lh          $t2, 0xAC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XAC);
    // 0x8005B044: nop

    // 0x8005B048: andi        $t0, $t2, 0x40
    ctx->r8 = ctx->r10 & 0X40;
    // 0x8005B04C: bne         $t0, $zero, L_8005B080
    if (ctx->r8 != 0) {
        // 0x8005B050: nop
    
            goto L_8005B080;
    }
    // 0x8005B050: nop

    // 0x8005B054: lw          $t4, 0xA4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XA4);
    // 0x8005B058: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8005B05C: bne         $t4, $at, L_8005AF7C
    if (ctx->r12 != ctx->r1) {
        // 0x8005B060: nop
    
            goto L_8005AF7C;
    }
    // 0x8005B060: nop

    // 0x8005B064: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8005B068: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8005B06C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005B070: bne         $t8, $zero, L_8005B080
    if (ctx->r24 != 0) {
        // 0x8005B074: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_8005B080;
    }
    // 0x8005B074: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8005B078: beq         $t9, $zero, L_8005AF7C
    if (ctx->r25 == 0) {
        // 0x8005B07C: nop
    
            goto L_8005AF7C;
    }
    // 0x8005B07C: nop

L_8005B080:
    // 0x8005B080: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005B084: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8005B088: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8005B08C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005B090: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005B094: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8005B098: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8005B09C: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8005B0A0: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x8005B0A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0A8: nop

    // 0x8005B0AC: sb          $zero, 0x20($t4)
    MEM_B(0X20, ctx->r12) = 0;
    // 0x8005B0B0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0B4: nop

    // 0x8005B0B8: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8005B0BC: jal         0x80098AD8
    // 0x8005B0C0: nop

    func_80098AD8(rdram, ctx);
        goto after_9;
    // 0x8005B0C0: nop

    after_9:
    // 0x8005B0C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0C8: jal         0x80049544
    // 0x8005B0CC: nop

    func_80049544(rdram, ctx);
        goto after_10;
    // 0x8005B0CC: nop

    after_10:
    // 0x8005B0D0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0D4: nop

    // 0x8005B0D8: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8005B0DC: jal         0x800C0D34
    // 0x8005B0E0: nop

    Thread_StopThread(rdram, ctx);
        goto after_11;
    // 0x8005B0E0: nop

    after_11:
L_8005B0E4:
    // 0x8005B0E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0E8: jal         0x800499B0
    // 0x8005B0EC: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x8005B0EC: nop

    after_12:
    // 0x8005B0F0: b           L_8005B0E4
    // 0x8005B0F4: nop

        goto L_8005B0E4;
    // 0x8005B0F4: nop

    // 0x8005B0F8: b           L_8005B100
    // 0x8005B0FC: nop

        goto L_8005B100;
    // 0x8005B0FC: nop

L_8005B100:
    // 0x8005B100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005B104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005B108: jr          $ra
    // 0x8005B10C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005B10C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006D0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D0F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D0F8: nop

    // 0x8006D0FC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D100: nop

    // 0x8006D104: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006D108: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D10C: jr          $ra
    // 0x8006D110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D114: jr          $ra
    // 0x8006D118: nop

    return;
    // 0x8006D118: nop

    // 0x8006D11C: jr          $ra
    // 0x8006D120: nop

    return;
    // 0x8006D120: nop

;}
RECOMP_FUNC void Main_GfxSetSegments(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE18C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BE190: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BE194: nop

    // 0x800BE198: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800BE19C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE1A0: nop

    // 0x800BE1A4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800BE1A8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800BE1AC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800BE1B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800BE1B4: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800BE1B8: ori         $t9, $t9, 0x6
    ctx->r25 = ctx->r25 | 0X6;
    // 0x800BE1BC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800BE1C0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800BE1C4: nop

    // 0x800BE1C8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800BE1CC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE1D0: nop

    // 0x800BE1D4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE1D8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800BE1DC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800BE1E0: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BE1E4: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x800BE1E8: ori         $t4, $t4, 0x406
    ctx->r12 = ctx->r12 | 0X406;
    // 0x800BE1EC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE1F0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x800BE1F4: lw          $t6, -0x6A04($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A04);
    // 0x800BE1F8: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800BE1FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE200: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800BE204: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE208: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE20C: nop

    // 0x800BE210: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE214: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BE218: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800BE21C: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x800BE220: lui         $t1, 0xBC00
    ctx->r9 = S32(0XBC00 << 16);
    // 0x800BE224: ori         $t1, $t1, 0x806
    ctx->r9 = ctx->r9 | 0X806;
    // 0x800BE228: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE22C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x800BE230: lw          $t3, -0x6508($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6508);
    // 0x800BE234: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800BE238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE23C: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800BE240: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800BE244: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE248: nop

    // 0x800BE24C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE250: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800BE254: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800BE258: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800BE25C: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x800BE260: ori         $t8, $t8, 0xC06
    ctx->r24 = ctx->r24 | 0XC06;
    // 0x800BE264: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE268: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BE26C: lw          $t0, 0x24DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X24DC);
    // 0x800BE270: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BE274: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE278: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800BE27C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800BE280: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE284: nop

    // 0x800BE288: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800BE28C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800BE290: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800BE294: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800BE298: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800BE29C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800BE2A0: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BE2A4: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x800BE2A8: addiu       $t7, $t7, 0x58
    ctx->r15 = ADD32(ctx->r15, 0X58);
    // 0x800BE2AC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE2B0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE2B4: nop

    // 0x800BE2B8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE2BC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BE2C0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800BE2C4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BE2C8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800BE2CC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE2D0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800BE2D4: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x800BE2D8: addiu       $t3, $t3, 0x80
    ctx->r11 = ADD32(ctx->r11, 0X80);
    // 0x800BE2DC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800BE2E0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE2E4: nop

    // 0x800BE2E8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800BE2EC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800BE2F0: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x800BE2F4: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BE2F8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800BE2FC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800BE300: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800BE304: nop

    // 0x800BE308: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800BE30C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE310: nop

    // 0x800BE314: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800BE318: b           L_800BE320
    // 0x800BE31C: nop

        goto L_800BE320;
    // 0x800BE31C: nop

L_800BE320:
    // 0x800BE320: jr          $ra
    // 0x800BE324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800BE324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
