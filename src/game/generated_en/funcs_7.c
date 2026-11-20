#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80047808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047808: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8004780C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80047810: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80047814: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80047818: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004781C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80047820: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80047824: jal         0x800AF060
    // 0x80047828: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x80047828: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x8004782C: jal         0x800A41B4
    // 0x80047830: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x80047830: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x80047834: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80047838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004783C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80047840: swc1        $f4, 0x450($at)
    MEM_W(0X450, ctx->r1) = ctx->f4.u32l;
    // 0x80047844: jal         0x800BC6EC
    // 0x80047848: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80047848: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_2:
    // 0x8004784C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80047850: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80047854: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047858: sw          $t6, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r14;
    // 0x8004785C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80047860: nop

    // 0x80047864: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80047868: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8004786C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80047870: sb          $t8, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r24;
    // 0x80047874: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80047878: nop

    // 0x8004787C: lbu         $t1, 0x4($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4);
    // 0x80047880: nop

    // 0x80047884: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x80047888: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8004788C: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80047890: sb          $t2, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r10;
    // 0x80047894: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80047898: nop

    // 0x8004789C: lbu         $t5, 0x5($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5);
    // 0x800478A0: nop

    // 0x800478A4: sb          $t5, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r13;
    // 0x800478A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800478AC: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x800478B0: sb          $t6, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r14;
    // 0x800478B4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800478B8: nop

    // 0x800478BC: lbu         $t9, 0x6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X6);
    // 0x800478C0: nop

    // 0x800478C4: sb          $t9, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r25;
    // 0x800478C8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800478CC: nop

    // 0x800478D0: sb          $zero, 0x7($t1)
    MEM_B(0X7, ctx->r9) = 0;
    // 0x800478D4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800478D8: nop

    // 0x800478DC: lbu         $t2, 0x7($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X7);
    // 0x800478E0: nop

    // 0x800478E4: sb          $t2, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r10;
    // 0x800478E8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800478EC: nop

    // 0x800478F0: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800478F4: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x800478F8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800478FC: nop

    // 0x80047900: sb          $zero, 0x4($t4)
    MEM_B(0X4, ctx->r12) = 0;
    // 0x80047904: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80047908: nop

    // 0x8004790C: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x80047910: nop

    // 0x80047914: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
    // 0x80047918: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8004791C: nop

    // 0x80047920: sb          $zero, 0x5($t9)
    MEM_B(0X5, ctx->r25) = 0;
    // 0x80047924: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047928: nop

    // 0x8004792C: lbu         $t1, 0x5($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X5);
    // 0x80047930: nop

    // 0x80047934: sb          $t1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r9;
    // 0x80047938: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8004793C: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x80047940: sb          $t2, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r10;
    // 0x80047944: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80047948: nop

    // 0x8004794C: lbu         $t5, 0x6($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X6);
    // 0x80047950: nop

    // 0x80047954: sb          $t5, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r13;
    // 0x80047958: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8004795C: addiu       $t4, $zero, 0x59
    ctx->r12 = ADD32(0, 0X59);
    // 0x80047960: sb          $t4, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r12;
    // 0x80047964: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80047968: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8004796C: sb          $t6, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r14;
    // 0x80047970: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80047974: nop

    // 0x80047978: sb          $zero, 0xA($t1)
    MEM_B(0XA, ctx->r9) = 0;
    // 0x8004797C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047980: nop

    // 0x80047984: sb          $zero, 0xB($t8)
    MEM_B(0XB, ctx->r24) = 0;
    // 0x80047988: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8004798C: nop

    // 0x80047990: lbu         $s0, 0xB($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0XB);
    // 0x80047994: nop

    // 0x80047998: sb          $s0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r16;
    // 0x8004799C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800479A0: nop

    // 0x800479A4: sb          $s0, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r16;
    // 0x800479A8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800479AC: nop

    // 0x800479B0: addiu       $t3, $t5, 0x18
    ctx->r11 = ADD32(ctx->r13, 0X18);
    // 0x800479B4: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800479B8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800479BC: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800479C0: sb          $t4, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r12;
    // 0x800479C4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800479C8: nop

    // 0x800479CC: lbu         $t9, 0x4($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X4);
    // 0x800479D0: nop

    // 0x800479D4: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800479D8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800479DC: nop

    // 0x800479E0: sb          $zero, 0x5($t1)
    MEM_B(0X5, ctx->r9) = 0;
    // 0x800479E4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800479E8: nop

    // 0x800479EC: lbu         $t2, 0x5($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X5);
    // 0x800479F0: nop

    // 0x800479F4: sb          $t2, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r10;
    // 0x800479F8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800479FC: nop

    // 0x80047A00: sb          $zero, 0x6($t0)
    MEM_B(0X6, ctx->r8) = 0;
    // 0x80047A04: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80047A08: nop

    // 0x80047A0C: lbu         $t3, 0x6($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X6);
    // 0x80047A10: nop

    // 0x80047A14: sb          $t3, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r11;
    // 0x80047A18: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80047A1C: nop

    // 0x80047A20: sb          $zero, 0x8($t4)
    MEM_B(0X8, ctx->r12) = 0;
    // 0x80047A24: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80047A28: nop

    // 0x80047A2C: sb          $zero, 0x9($t7)
    MEM_B(0X9, ctx->r15) = 0;
    // 0x80047A30: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80047A34: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80047A38: sb          $t9, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r25;
    // 0x80047A3C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80047A40: nop

    // 0x80047A44: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x80047A48: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80047A4C: nop

    // 0x80047A50: lbu         $s0, 0xB($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0XB);
    // 0x80047A54: nop

    // 0x80047A58: sb          $s0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r16;
    // 0x80047A5C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047A60: nop

    // 0x80047A64: sb          $s0, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r16;
    // 0x80047A68: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80047A6C: jal         0x800A5624
    // 0x80047A70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_3;
    // 0x80047A70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80047A74: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    // 0x80047A78: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x80047A7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047A80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80047A84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80047A88: jal         0x800A57C4
    // 0x80047A8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800A57C4(rdram, ctx);
        goto after_4;
    // 0x80047A8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x80047A90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80047A94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80047A98: sw          $t0, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r8;
    // 0x80047A9C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80047AA0: sh          $t3, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r11;
    // 0x80047AA4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80047AA8: lh          $t5, 0x7268($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7268);
    // 0x80047AAC: nop

    // 0x80047AB0: andi        $t4, $t5, 0x7FFF
    ctx->r12 = ctx->r13 & 0X7FFF;
    // 0x80047AB4: bne         $t4, $zero, L_80047AD0
    if (ctx->r12 != 0) {
        // 0x80047AB8: nop

            goto L_80047AD0;
    }
    // 0x80047AB8: nop

    // 0x80047ABC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80047AC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047AC4: sh          $t7, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r15;
    // 0x80047AC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047ACC: sb          $zero, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = 0;
L_80047AD0:
    // 0x80047AD0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80047AD4: lh          $t9, 0x7268($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7268);
    // 0x80047AD8: nop

    // 0x80047ADC: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80047AE0: andi        $t1, $t6, 0x7FFF
    ctx->r9 = ctx->r14 & 0X7FFF;
    // 0x80047AE4: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x80047AE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047AEC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80047AF0: addiu       $t2, $t2, 0x7158
    ctx->r10 = ADD32(ctx->r10, 0X7158);
    // 0x80047AF4: swc1        $f6, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f6.u32l;
    // 0x80047AF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047AFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80047B00: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047B04: addiu       $t8, $t8, 0x7158
    ctx->r24 = ADD32(ctx->r24, 0X7158);
    // 0x80047B08: swc1        $f8, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f8.u32l;
    // 0x80047B0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047B10: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80047B14: addiu       $t0, $t0, 0x7158
    ctx->r8 = ADD32(ctx->r8, 0X7158);
    // 0x80047B18: swc1        $f10, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f10.u32l;
    // 0x80047B1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047B20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80047B24: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80047B28: addiu       $t3, $t3, 0x7158
    ctx->r11 = ADD32(ctx->r11, 0X7158);
    // 0x80047B2C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80047B30: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x80047B34: swc1        $f16, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f16.u32l;
    // 0x80047B38: lwc1        $f20, 0x20($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0X20);
    // 0x80047B3C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80047B40: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x80047B44: swc1        $f20, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f20.u32l;
    // 0x80047B48: swc1        $f20, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f20.u32l;
    // 0x80047B4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047B50: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80047B54: jal         0x800C4240
    // 0x80047B58: nop

    guRandom(rdram, ctx);
        goto after_5;
    // 0x80047B58: nop

    after_5:
    // 0x80047B5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80047B60: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80047B64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047B68: mfhi        $t7
    ctx->r15 = hi;
    // 0x80047B6C: addiu       $t9, $t7, 0x5
    ctx->r25 = ADD32(ctx->r15, 0X5);
    // 0x80047B70: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80047B74: nop

    // 0x80047B78: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80047B7C: swc1        $f4, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f4.u32l;
    // 0x80047B80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047B84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047B88: swc1        $f6, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f6.u32l;
    // 0x80047B8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047B90: sh          $zero, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = 0;
    // 0x80047B94: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80047B98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80047B9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BA0: swc1        $f8, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f8.u32l;
    // 0x80047BA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047BA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BAC: swc1        $f10, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f10.u32l;
    // 0x80047BB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BB4: swc1        $f10, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f10.u32l;
    // 0x80047BB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80047BBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BC0: swc1        $f16, 0x733C($at)
    MEM_W(0X733C, ctx->r1) = ctx->f16.u32l;
    // 0x80047BC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BC8: swc1        $f16, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->f16.u32l;
    // 0x80047BCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BD0: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
    // 0x80047BD4: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80047BD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80047BDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047BE0: swc1        $f18, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = ctx->f18.u32l;
    // 0x80047BE4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80047BE8: lbu         $t6, 0x7256($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7256);
    // 0x80047BEC: nop

    // 0x80047BF0: bne         $t6, $zero, L_80047DBC
    if (ctx->r14 != 0) {
        // 0x80047BF4: nop

            goto L_80047DBC;
    }
    // 0x80047BF4: nop

    // 0x80047BF8: lhu         $t1, 0x72($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X72);
    // 0x80047BFC: nop

    // 0x80047C00: bne         $t1, $zero, L_80047C48
    if (ctx->r9 != 0) {
        // 0x80047C04: nop

            goto L_80047C48;
    }
    // 0x80047C04: nop

    // 0x80047C08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047C0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047C10: swc1        $f4, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f4.u32l;
    // 0x80047C14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80047C18: lwc1        $f6, -0x1130($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1130);
    // 0x80047C1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047C20: swc1        $f6, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f6.u32l;
    // 0x80047C24: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80047C28: lwc1        $f8, -0x112C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X112C);
    // 0x80047C2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047C30: swc1        $f8, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f8.u32l;
    // 0x80047C34: jal         0x800BC918
    // 0x80047C38: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_6;
    // 0x80047C38: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_6:
    // 0x80047C3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047C40: b           L_80047DB4
    // 0x80047C44: sw          $v0, 0x7260($at)
    MEM_W(0X7260, ctx->r1) = ctx->r2;
        goto L_80047DB4;
    // 0x80047C44: sw          $v0, 0x7260($at)
    MEM_W(0X7260, ctx->r1) = ctx->r2;
L_80047C48:
    // 0x80047C48: jal         0x800C4240
    // 0x80047C4C: nop

    guRandom(rdram, ctx);
        goto after_7;
    // 0x80047C4C: nop

    after_7:
    // 0x80047C50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047C54: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80047C58: mfhi        $t2
    ctx->r10 = hi;
    // 0x80047C5C: andi        $t8, $t2, 0xFFFF
    ctx->r24 = ctx->r10 & 0XFFFF;
    // 0x80047C60: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
    // 0x80047C64: jal         0x800C4240
    // 0x80047C68: nop

    guRandom(rdram, ctx);
        goto after_8;
    // 0x80047C68: nop

    after_8:
    // 0x80047C6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047C70: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80047C74: mfhi        $t0
    ctx->r8 = hi;
    // 0x80047C78: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x80047C7C: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x80047C80: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
    // 0x80047C84: lhu         $t4, 0x6E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6E);
    // 0x80047C88: nop

    // 0x80047C8C: bne         $t5, $t4, L_80047CEC
    if (ctx->r13 != ctx->r12) {
        // 0x80047C90: nop

            goto L_80047CEC;
    }
    // 0x80047C90: nop

    // 0x80047C94: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80047C98: nop

    // 0x80047C9C: bne         $t7, $zero, L_80047CEC
    if (ctx->r15 != 0) {
        // 0x80047CA0: nop

            goto L_80047CEC;
    }
    // 0x80047CA0: nop

    // 0x80047CA4: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80047CA8: nop

    // 0x80047CAC: bne         $t9, $zero, L_80047CEC
    if (ctx->r25 != 0) {
        // 0x80047CB0: nop

            goto L_80047CEC;
    }
    // 0x80047CB0: nop

    // 0x80047CB4: jal         0x800C4240
    // 0x80047CB8: nop

    guRandom(rdram, ctx);
        goto after_9;
    // 0x80047CB8: nop

    after_9:
    // 0x80047CBC: bgez        $v0, L_80047CD0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80047CC0: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80047CD0;
    }
    // 0x80047CC0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80047CC4: beq         $t6, $zero, L_80047CD0
    if (ctx->r14 == 0) {
        // 0x80047CC8: nop

            goto L_80047CD0;
    }
    // 0x80047CC8: nop

    // 0x80047CCC: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_80047CD0:
    // 0x80047CD0: beq         $t6, $zero, L_80047CE4
    if (ctx->r14 == 0) {
        // 0x80047CD4: nop

            goto L_80047CE4;
    }
    // 0x80047CD4: nop

    // 0x80047CD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80047CDC: b           L_80047CEC
    // 0x80047CE0: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
        goto L_80047CEC;
    // 0x80047CE0: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
L_80047CE4:
    // 0x80047CE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80047CE8: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
L_80047CEC:
    // 0x80047CEC: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x80047CF0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047CF4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80047CF8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80047CFC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80047D00: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80047D04: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80047D08: addiu       $t3, $t0, 0x46
    ctx->r11 = ADD32(ctx->r8, 0X46);
    // 0x80047D0C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80047D10: nop

    // 0x80047D14: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047D18: swc1        $f16, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f16.u32l;
    // 0x80047D1C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80047D20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047D24: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80047D28: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x80047D2C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047D30: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80047D34: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047D38: addiu       $t7, $t4, 0x46
    ctx->r15 = ADD32(ctx->r12, 0X46);
    // 0x80047D3C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80047D40: nop

    // 0x80047D44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80047D48: swc1        $f4, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f4.u32l;
    // 0x80047D4C: jal         0x800C4240
    // 0x80047D50: nop

    guRandom(rdram, ctx);
        goto after_10;
    // 0x80047D50: nop

    after_10:
    // 0x80047D54: bgez        $v0, L_80047D68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80047D58: andi        $t9, $v0, 0x3
        ctx->r25 = ctx->r2 & 0X3;
            goto L_80047D68;
    }
    // 0x80047D58: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x80047D5C: beq         $t9, $zero, L_80047D68
    if (ctx->r25 == 0) {
        // 0x80047D60: nop

            goto L_80047D68;
    }
    // 0x80047D60: nop

    // 0x80047D64: addiu       $t9, $t9, -0x4
    ctx->r25 = ADD32(ctx->r25, -0X4);
L_80047D68:
    // 0x80047D68: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80047D6C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80047D70: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x80047D74: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80047D78: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x80047D7C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80047D80: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x80047D84: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80047D88: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80047D8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047D90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80047D94: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
    // 0x80047D98: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047D9C: lw          $t8, 0x7260($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7260);
    // 0x80047DA0: addiu       $t2, $zero, 0x168
    ctx->r10 = ADD32(0, 0X168);
    // 0x80047DA4: sh          $t2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r10;
    // 0x80047DA8: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x80047DAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047DB0: sh          $t0, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r8;
L_80047DB4:
    // 0x80047DB4: b           L_80047E84
    // 0x80047DB8: nop

        goto L_80047E84;
    // 0x80047DB8: nop

L_80047DBC:
    // 0x80047DBC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80047DC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047DC4: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80047DC8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80047DCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047DD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047DD4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80047DD8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80047DDC: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80047DE0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80047DE4: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80047DE8: sra         $t7, $t4, 16
    ctx->r15 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80047DEC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80047DF0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047DF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80047DF8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80047DFC: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80047E00: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80047E04: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80047E08: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80047E0C: addiu       $t1, $t6, 0x46
    ctx->r9 = ADD32(ctx->r14, 0X46);
    // 0x80047E10: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80047E14: nop

    // 0x80047E18: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80047E1C: swc1        $f4, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f4.u32l;
    // 0x80047E20: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80047E24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047E28: lwc1        $f6, -0x73D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80047E2C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80047E30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047E34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047E38: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80047E3C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80047E40: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80047E44: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80047E48: sll         $t0, $t8, 16
    ctx->r8 = S32(ctx->r24 << 16);
    // 0x80047E4C: sra         $t3, $t0, 16
    ctx->r11 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80047E50: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80047E54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047E58: mflo        $t5
    ctx->r13 = lo;
    // 0x80047E5C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80047E60: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x80047E64: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047E68: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80047E6C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047E70: addiu       $t7, $t4, 0x46
    ctx->r15 = ADD32(ctx->r12, 0X46);
    // 0x80047E74: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80047E78: nop

    // 0x80047E7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047E80: swc1        $f16, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f16.u32l;
L_80047E84:
    // 0x80047E84: jal         0x800BC6EC
    // 0x80047E88: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x80047E88: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_11:
    // 0x80047E8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047E90: sw          $v0, 0x71FC($at)
    MEM_W(0X71FC, ctx->r1) = ctx->r2;
    // 0x80047E94: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80047E98: lw          $t9, 0x7260($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7260);
    // 0x80047E9C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80047EA0: lw          $t1, 0x71FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71FC);
    // 0x80047EA4: addiu       $t6, $t9, 0x2
    ctx->r14 = ADD32(ctx->r25, 0X2);
    // 0x80047EA8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80047EAC: jal         0x800BC6EC
    // 0x80047EB0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_12;
    // 0x80047EB0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_12:
    // 0x80047EB4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80047EB8: lhu         $t2, 0x72($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X72);
    // 0x80047EBC: nop

    // 0x80047EC0: bne         $t2, $zero, L_80047EE4
    if (ctx->r10 != 0) {
        // 0x80047EC4: nop

            goto L_80047EE4;
    }
    // 0x80047EC4: nop

    // 0x80047EC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047ECC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80047ED0: addiu       $a0, $a0, -0x2C10
    ctx->r4 = ADD32(ctx->r4, -0X2C10);
    // 0x80047ED4: jal         0x800BD218
    // 0x80047ED8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_13;
    // 0x80047ED8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_13:
    // 0x80047EDC: b           L_80047EF8
    // 0x80047EE0: nop

        goto L_80047EF8;
    // 0x80047EE0: nop

L_80047EE4:
    // 0x80047EE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047EE8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80047EEC: addiu       $a0, $a0, -0x2C00
    ctx->r4 = ADD32(ctx->r4, -0X2C00);
    // 0x80047EF0: jal         0x800BD218
    // 0x80047EF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_14;
    // 0x80047EF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_14:
L_80047EF8:
    // 0x80047EF8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047EFC: lw          $t8, 0x71FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X71FC);
    // 0x80047F00: nop

    // 0x80047F04: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80047F08: nop

    // 0x80047F0C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x80047F10: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_80047F14:
    // 0x80047F14: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
L_80047F18:
    // 0x80047F18: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80047F1C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80047F20: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80047F24: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80047F28: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80047F2C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80047F30: lbu         $t1, 0x0($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X0);
    // 0x80047F34: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80047F38: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80047F3C: lbu         $t2, -0x2C20($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2C20);
    // 0x80047F40: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80047F44: nop

    // 0x80047F48: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
    // 0x80047F4C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80047F50: nop

    // 0x80047F54: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80047F58: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x80047F5C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80047F60: nop

    // 0x80047F64: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80047F68: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80047F6C: bne         $at, $zero, L_80047F18
    if (ctx->r1 != 0) {
        // 0x80047F70: sw          $t4, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r12;
            goto L_80047F18;
    }
    // 0x80047F70: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x80047F74: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80047F78: nop

    // 0x80047F7C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80047F80: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80047F84: bne         $at, $zero, L_80047F14
    if (ctx->r1 != 0) {
        // 0x80047F88: sw          $t9, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r25;
            goto L_80047F14;
    }
    // 0x80047F88: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80047F8C: lhu         $t6, 0x72($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X72);
    // 0x80047F90: nop

    // 0x80047F94: bne         $t6, $zero, L_80047FB4
    if (ctx->r14 != 0) {
        // 0x80047F98: nop

            goto L_80047FB4;
    }
    // 0x80047F98: nop

    // 0x80047F9C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80047FA0: lw          $t2, 0x71FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71FC);
    // 0x80047FA4: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    // 0x80047FA8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80047FAC: b           L_80047FCC
    // 0x80047FB0: sb          $t1, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r9;
        goto L_80047FCC;
    // 0x80047FB0: sb          $t1, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r9;
L_80047FB4:
    // 0x80047FB4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80047FB8: lw          $t3, 0x71FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X71FC);
    // 0x80047FBC: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x80047FC0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80047FC4: nop

    // 0x80047FC8: sb          $t0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r8;
L_80047FCC:
    // 0x80047FCC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80047FD0: jal         0x800BC980
    // 0x80047FD4: nop

    SysMem_Free(rdram, ctx);
        goto after_15;
    // 0x80047FD4: nop

    after_15:
    // 0x80047FD8: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x80047FDC: lw          $a3, 0x71FC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X71FC);
    // 0x80047FE0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80047FE4: addiu       $a2, $a2, -0x3BE0
    ctx->r6 = ADD32(ctx->r6, -0X3BE0);
    // 0x80047FE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80047FEC: jal         0x80043F14
    // 0x80047FF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80043F14(rdram, ctx);
        goto after_16;
    // 0x80047FF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80047FF4: lhu         $t4, 0x72($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X72);
    // 0x80047FF8: lhu         $t7, 0x6E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X6E);
    // 0x80047FFC: nop

    // 0x80048000: bne         $t4, $t7, L_8004806C
    if (ctx->r12 != ctx->r15) {
        // 0x80048004: nop

            goto L_8004806C;
    }
    // 0x80048004: nop

    // 0x80048008: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004800C: lbu         $t9, 0x7256($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7256);
    // 0x80048010: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80048014: bne         $t9, $at, L_80048048
    if (ctx->r25 != ctx->r1) {
        // 0x80048018: nop

            goto L_80048048;
    }
    // 0x80048018: nop

    // 0x8004801C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048020: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80048024: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80048028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004802C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80048030: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80048034: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80048038: jal         0x80044248
    // 0x8004803C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_80044248(rdram, ctx);
        goto after_17;
    // 0x8004803C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_17:
    // 0x80048040: b           L_8004806C
    // 0x80048044: nop

        goto L_8004806C;
    // 0x80048044: nop

L_80048048:
    // 0x80048048: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8004804C: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80048050: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80048054: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80048058: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8004805C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80048060: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80048064: jal         0x80044248
    // 0x80048068: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_80044248(rdram, ctx);
        goto after_18;
    // 0x80048068: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_18:
L_8004806C:
    // 0x8004806C: lui         $a0, 0x80A4
    ctx->r4 = S32(0X80A4 << 16);
    // 0x80048070: jal         0x800AF92C
    // 0x80048074: addiu       $a0, $a0, -0x40D0
    ctx->r4 = ADD32(ctx->r4, -0X40D0);
    func_800AF92C(rdram, ctx);
        goto after_19;
    // 0x80048074: addiu       $a0, $a0, -0x40D0
    ctx->r4 = ADD32(ctx->r4, -0X40D0);
    after_19:
    // 0x80048078: lui         $a0, 0x80A3
    ctx->r4 = S32(0X80A3 << 16);
    // 0x8004807C: jal         0x800AF72C
    // 0x80048080: addiu       $a0, $a0, 0x7648
    ctx->r4 = ADD32(ctx->r4, 0X7648);
    func_800AF72C(rdram, ctx);
        goto after_20;
    // 0x80048080: addiu       $a0, $a0, 0x7648
    ctx->r4 = ADD32(ctx->r4, 0X7648);
    after_20:
    // 0x80048084: jal         0x800BC6EC
    // 0x80048088: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_21;
    // 0x80048088: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_21:
    // 0x8004808C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80048090: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80048094: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80048098: sw          $t3, -0x73B8($at)
    MEM_W(-0X73B8, ctx->r1) = ctx->r11;
    // 0x8004809C: jal         0x800BC6EC
    // 0x800480A0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_22;
    // 0x800480A0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_22:
    // 0x800480A4: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x800480A8: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800480AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800480B0: sw          $t0, -0x73B4($at)
    MEM_W(-0X73B4, ctx->r1) = ctx->r8;
    // 0x800480B4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800480B8: jal         0x80099E2C
    // 0x800480BC: nop

    func_80099E2C(rdram, ctx);
        goto after_23;
    // 0x800480BC: nop

    after_23:
    // 0x800480C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800480C4: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800480C8: nop

    // 0x800480CC: swc1        $f18, 0xD4($t5)
    MEM_W(0XD4, ctx->r13) = ctx->f18.u32l;
    // 0x800480D0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800480D4: lui         $t4, 0x4
    ctx->r12 = S32(0X4 << 16);
    // 0x800480D8: ori         $t4, $t4, 0x8004
    ctx->r12 = ctx->r12 | 0X8004;
    // 0x800480DC: sw          $t4, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r12;
    // 0x800480E0: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800480E4: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x800480E8: sh          $t9, 0x11E($t6)
    MEM_H(0X11E, ctx->r14) = ctx->r25;
    // 0x800480EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800480F0: lwc1        $f4, -0x1128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1128);
    // 0x800480F4: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x800480F8: nop

    // 0x800480FC: swc1        $f4, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->f4.u32l;
    // 0x80048100: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80048104: nop

    // 0x80048108: sw          $zero, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = 0;
    // 0x8004810C: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80048110: nop

    // 0x80048114: sw          $zero, 0x140($t8)
    MEM_W(0X140, ctx->r24) = 0;
    // 0x80048118: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8004811C: nop

    // 0x80048120: lw          $t0, 0x140($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X140);
    // 0x80048124: nop

    // 0x80048128: sw          $t0, 0x13C($t3)
    MEM_W(0X13C, ctx->r11) = ctx->r8;
    // 0x8004812C: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80048130: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80048134: sh          $t5, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r13;
    // 0x80048138: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8004813C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80048140: jal         0x800B1B04
    // 0x80048144: nop

    func_800B1B04(rdram, ctx);
        goto after_24;
    // 0x80048144: nop

    after_24:
    // 0x80048148: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004814C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048150: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80048154: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80048158: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8004815C: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x80048160: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80048164: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80048168: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004816C: jal         0x800B1F0C
    // 0x80048170: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_25;
    // 0x80048170: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_25:
    // 0x80048174: addiu       $t7, $zero, 0x27
    ctx->r15 = ADD32(0, 0X27);
    // 0x80048178: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004817C: sh          $t7, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r15;
    // 0x80048180: jal         0x800BC6EC
    // 0x80048184: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_26;
    // 0x80048184: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_26:
    // 0x80048188: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004818C: sw          $v0, 0x722C($at)
    MEM_W(0X722C, ctx->r1) = ctx->r2;
    // 0x80048190: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80048194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80048198: jal         0x800AFB70
    // 0x8004819C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_27;
    // 0x8004819C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x800481A0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800481A4: lw          $t9, 0x722C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X722C);
    // 0x800481A8: nop

    // 0x800481AC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800481B0: jal         0x800BC6EC
    // 0x800481B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_28;
    // 0x800481B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_28:
    // 0x800481B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800481BC: sw          $v0, 0x7220($at)
    MEM_W(0X7220, ctx->r1) = ctx->r2;
    // 0x800481C0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800481C4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800481C8: lw          $t6, 0x7220($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7220);
    // 0x800481CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800481D0: nop

    // 0x800481D4: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x800481D8: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x800481DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800481E0: lw          $t2, 0x7220($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7220);
    // 0x800481E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800481E8: nop

    // 0x800481EC: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x800481F0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800481F4: lw          $t1, 0x7220($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7220);
    // 0x800481F8: nop

    // 0x800481FC: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x80048200: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80048204: lw          $t8, 0x7220($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7220);
    // 0x80048208: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004820C: nop

    // 0x80048210: swc1        $f18, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f18.u32l;
    // 0x80048214: lhu         $t0, 0x72($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X72);
    // 0x80048218: lhu         $t3, 0x6E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6E);
    // 0x8004821C: nop

    // 0x80048220: bne         $t0, $t3, L_80048250
    if (ctx->r8 != ctx->r11) {
        // 0x80048224: nop

            goto L_80048250;
    }
    // 0x80048224: nop

    // 0x80048228: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004822C: lw          $t5, 0x7260($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7260);
    // 0x80048230: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048234: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80048238: swc1        $f4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f4.u32l;
    // 0x8004823C: lw          $t4, 0x7260($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7260);
    // 0x80048240: nop

    // 0x80048244: lwc1        $f6, 0x18($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X18);
    // 0x80048248: b           L_80048440
    // 0x8004824C: swc1        $f6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f6.u32l;
        goto L_80048440;
    // 0x8004824C: swc1        $f6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f6.u32l;
L_80048250:
    // 0x80048250: jal         0x800BC6EC
    // 0x80048254: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_29;
    // 0x80048254: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_29:
    // 0x80048258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004825C: sw          $v0, 0x726C($at)
    MEM_W(0X726C, ctx->r1) = ctx->r2;
    // 0x80048260: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80048264: lbu         $t7, 0x7256($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7256);
    // 0x80048268: nop

    // 0x8004826C: bne         $t7, $zero, L_8004834C
    if (ctx->r15 != 0) {
        // 0x80048270: nop

            goto L_8004834C;
    }
    // 0x80048270: nop

    // 0x80048274: jal         0x800C4240
    // 0x80048278: nop

    guRandom(rdram, ctx);
        goto after_30;
    // 0x80048278: nop

    after_30:
    // 0x8004827C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048280: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80048284: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80048288: lw          $t8, 0x726C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X726C);
    // 0x8004828C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80048290: mfhi        $s1
    ctx->r17 = hi;
    // 0x80048294: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80048298: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8004829C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800482A0: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800482A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800482A8: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x800482AC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800482B0: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800482B4: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x800482B8: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x800482BC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800482C0: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800482C4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800482C8: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800482CC: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x800482D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800482D4: lw          $t0, 0x7260($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7260);
    // 0x800482D8: nop

    // 0x800482DC: swc1        $f10, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f10.u32l;
    // 0x800482E0: jal         0x800C4240
    // 0x800482E4: nop

    guRandom(rdram, ctx);
        goto after_31;
    // 0x800482E4: nop

    after_31:
    // 0x800482E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800482EC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800482F0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800482F4: lw          $t9, 0x726C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X726C);
    // 0x800482F8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800482FC: mfhi        $s1
    ctx->r17 = hi;
    // 0x80048300: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80048304: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80048308: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8004830C: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80048310: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80048314: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x80048318: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004831C: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80048320: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x80048324: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80048328: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x8004832C: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80048330: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80048334: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x80048338: sh          $s1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r17;
    // 0x8004833C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80048340: lw          $t6, 0x7260($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7260);
    // 0x80048344: b           L_800483BC
    // 0x80048348: swc1        $f18, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f18.u32l;
        goto L_800483BC;
    // 0x80048348: swc1        $f18, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f18.u32l;
L_8004834C:
    // 0x8004834C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80048350: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80048354: lw          $t2, 0x7260($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7260);
    // 0x80048358: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8004835C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048360: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048364: lwc1        $f4, 0x14($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80048368: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004836C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80048370: lw          $t0, 0x726C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X726C);
    // 0x80048374: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80048378: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8004837C: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80048380: nop

    // 0x80048384: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80048388: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004838C: lw          $t3, 0x7260($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7260);
    // 0x80048390: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80048394: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048398: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004839C: lwc1        $f8, 0x18($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X18);
    // 0x800483A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800483A4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800483A8: lw          $t7, 0x726C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X726C);
    // 0x800483AC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800483B0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800483B4: sh          $t4, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r12;
    // 0x800483B8: nop

L_800483BC:
    // 0x800483BC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800483C0: lw          $t9, 0x726C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X726C);
    // 0x800483C4: nop

    // 0x800483C8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800483CC: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x800483D0: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x800483D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800483D8: jal         0x800AFB70
    // 0x800483DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_32;
    // 0x800483DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x800483E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800483E4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800483E8: jal         0x800A424C
    // 0x800483EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800A424C(rdram, ctx);
        goto after_33;
    // 0x800483EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_33:
    // 0x800483F0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800483F4: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800483F8: sh          $t2, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r10;
    // 0x800483FC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80048400: nop

    // 0x80048404: lw          $t0, 0xC0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC0);
    // 0x80048408: nop

    // 0x8004840C: ori         $t3, $t0, 0xA000
    ctx->r11 = ctx->r8 | 0XA000;
    // 0x80048410: sw          $t3, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r11;
    // 0x80048414: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80048418: nop

    // 0x8004841C: sh          $zero, 0xD0($t5)
    MEM_H(0XD0, ctx->r13) = 0;
    // 0x80048420: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80048424: nop

    // 0x80048428: lh          $s1, 0xD0($t4)
    ctx->r17 = MEM_H(ctx->r12, 0XD0);
    // 0x8004842C: nop

    // 0x80048430: sh          $s1, 0xCE($t4)
    MEM_H(0XCE, ctx->r12) = ctx->r17;
    // 0x80048434: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80048438: nop

    // 0x8004843C: sh          $s1, 0xCC($t7)
    MEM_H(0XCC, ctx->r15) = ctx->r17;
L_80048440:
    // 0x80048440: jal         0x800BC6EC
    // 0x80048444: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_34;
    // 0x80048444: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    after_34:
    // 0x80048448: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004844C: sw          $v0, 0x724C($at)
    MEM_W(0X724C, ctx->r1) = ctx->r2;
    // 0x80048450: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80048454: lw          $t9, 0x7260($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7260);
    // 0x80048458: nop

    // 0x8004845C: lwc1        $f16, 0x14($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80048460: nop

    // 0x80048464: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80048468: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004846C: lw          $t6, 0x7260($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7260);
    // 0x80048470: nop

    // 0x80048474: lwc1        $f18, 0x18($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80048478: nop

    // 0x8004847C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
L_80048480:
    // 0x80048480: jal         0x800C4240
    // 0x80048484: nop

    guRandom(rdram, ctx);
        goto after_35;
    // 0x80048484: nop

    after_35:
    // 0x80048488: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004848C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80048490: mfhi        $t2
    ctx->r10 = hi;
    // 0x80048494: andi        $t1, $t2, 0xFFFF
    ctx->r9 = ctx->r10 & 0XFFFF;
    // 0x80048498: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x8004849C: jal         0x800C4240
    // 0x800484A0: nop

    guRandom(rdram, ctx);
        goto after_36;
    // 0x800484A0: nop

    after_36:
    // 0x800484A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800484A8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800484AC: mfhi        $t0
    ctx->r8 = hi;
    // 0x800484B0: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800484B4: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x800484B8: lhu         $t8, 0x72($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X72);
    // 0x800484BC: lhu         $t5, 0x6E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6E);
    // 0x800484C0: nop

    // 0x800484C4: bne         $t8, $t5, L_80048524
    if (ctx->r24 != ctx->r13) {
        // 0x800484C8: nop

            goto L_80048524;
    }
    // 0x800484C8: nop

    // 0x800484CC: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x800484D0: nop

    // 0x800484D4: bne         $t4, $zero, L_80048524
    if (ctx->r12 != 0) {
        // 0x800484D8: nop

            goto L_80048524;
    }
    // 0x800484D8: nop

    // 0x800484DC: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800484E0: nop

    // 0x800484E4: bne         $t7, $zero, L_80048524
    if (ctx->r15 != 0) {
        // 0x800484E8: nop

            goto L_80048524;
    }
    // 0x800484E8: nop

    // 0x800484EC: jal         0x800C4240
    // 0x800484F0: nop

    guRandom(rdram, ctx);
        goto after_37;
    // 0x800484F0: nop

    after_37:
    // 0x800484F4: bgez        $v0, L_80048508
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800484F8: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_80048508;
    }
    // 0x800484F8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800484FC: beq         $t9, $zero, L_80048508
    if (ctx->r25 == 0) {
        // 0x80048500: nop

            goto L_80048508;
    }
    // 0x80048500: nop

    // 0x80048504: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80048508:
    // 0x80048508: beq         $t9, $zero, L_8004851C
    if (ctx->r25 == 0) {
        // 0x8004850C: nop

            goto L_8004851C;
    }
    // 0x8004850C: nop

    // 0x80048510: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048514: b           L_80048524
    // 0x80048518: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
        goto L_80048524;
    // 0x80048518: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
L_8004851C:
    // 0x8004851C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80048520: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
L_80048524:
    // 0x80048524: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80048528: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8004852C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80048530: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80048534: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80048538: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x8004853C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80048540: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80048544: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x80048548: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x8004854C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80048550: sra         $t3, $s1, 16
    ctx->r11 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80048554: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80048558: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8004855C: lw          $t8, 0x724C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X724C);
    // 0x80048560: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80048564: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x80048568: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8004856C: lw          $s1, 0x80($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X80);
    // 0x80048570: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80048574: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80048578: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x8004857C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80048580: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x80048584: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80048588: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8004858C: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x80048590: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80048594: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x80048598: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004859C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800485A0: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800485A4: lw          $t9, 0x724C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X724C);
    // 0x800485A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800485AC: sh          $s1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r17;
    // 0x800485B0: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x800485B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800485B8: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x800485BC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800485C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800485C4: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800485C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800485CC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800485D0: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800485D4: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x800485D8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800485DC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800485E0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800485E4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800485E8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800485EC: jal         0x800C3C80
    // 0x800485F0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_38;
    // 0x800485F0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_38:
    // 0x800485F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800485F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800485FC: nop

    // 0x80048600: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80048604: nop

    // 0x80048608: bc1f        L_80048480
    if (!c1cs) {
        // 0x8004860C: nop

            goto L_80048480;
    }
    // 0x8004860C: nop

    // 0x80048610: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80048614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048618: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8004861C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80048620: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80048624: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80048628: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004862C: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80048630: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80048634: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80048638: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004863C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80048640: jal         0x800C3C80
    // 0x80048644: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_39;
    // 0x80048644: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_39:
    // 0x80048648: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004864C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048650: nop

    // 0x80048654: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80048658: nop

    // 0x8004865C: bc1f        L_80048480
    if (!c1cs) {
        // 0x80048660: nop

            goto L_80048480;
    }
    // 0x80048660: nop

    // 0x80048664: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80048668: lbu         $t6, 0x7256($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7256);
    // 0x8004866C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80048670: bne         $t6, $at, L_8004868C
    if (ctx->r14 != ctx->r1) {
        // 0x80048674: nop

            goto L_8004868C;
    }
    // 0x80048674: nop

    // 0x80048678: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004867C: lw          $t1, 0x724C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X724C);
    // 0x80048680: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80048684: b           L_8004869C
    // 0x80048688: sb          $t2, 0x1A8($t1)
    MEM_B(0X1A8, ctx->r9) = ctx->r10;
        goto L_8004869C;
    // 0x80048688: sb          $t2, 0x1A8($t1)
    MEM_B(0X1A8, ctx->r9) = ctx->r10;
L_8004868C:
    // 0x8004868C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80048690: lw          $t0, 0x724C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X724C);
    // 0x80048694: nop

    // 0x80048698: sb          $zero, 0x1A8($t0)
    MEM_B(0X1A8, ctx->r8) = 0;
L_8004869C:
    // 0x8004869C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800486A0: lw          $t3, 0x724C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X724C);
    // 0x800486A4: nop

    // 0x800486A8: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x800486AC: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x800486B0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800486B4: lw          $t5, 0x724C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X724C);
    // 0x800486B8: nop

    // 0x800486BC: addiu       $t4, $t5, 0x168
    ctx->r12 = ADD32(ctx->r13, 0X168);
    // 0x800486C0: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x800486C4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800486C8: jal         0x80099E2C
    // 0x800486CC: nop

    func_80099E2C(rdram, ctx);
        goto after_40;
    // 0x800486CC: nop

    after_40:
    // 0x800486D0: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800486D4: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800486D8: jal         0x800B1B04
    // 0x800486DC: nop

    func_800B1B04(rdram, ctx);
        goto after_41;
    // 0x800486DC: nop

    after_41:
    // 0x800486E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800486E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800486E8: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800486EC: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800486F0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800486F4: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x800486F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800486FC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80048700: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80048704: jal         0x800B1F0C
    // 0x80048708: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_42;
    // 0x80048708: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_42:
    // 0x8004870C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80048710: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x80048714: ori         $t7, $t7, 0x2004
    ctx->r15 = ctx->r15 | 0X2004;
    // 0x80048718: sw          $t7, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r15;
    // 0x8004871C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80048720: lwc1        $f16, -0x1124($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1124);
    // 0x80048724: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80048728: nop

    // 0x8004872C: swc1        $f16, 0xFC($t6)
    MEM_W(0XFC, ctx->r14) = ctx->f16.u32l;
    // 0x80048730: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80048734: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80048738: sh          $t2, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r10;
    // 0x8004873C: b           L_80048744
    // 0x80048740: nop

        goto L_80048744;
    // 0x80048740: nop

L_80048744:
    // 0x80048744: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80048748: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8004874C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80048750: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80048754: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80048758: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8004875C: jr          $ra
    // 0x80048760: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80048760: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80048764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048764: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80048768: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004876C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80048770: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80048774: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80048778: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8004877C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80048780: addiu       $t7, $t7, -0x2ADC
    ctx->r15 = ADD32(ctx->r15, -0X2ADC);
    // 0x80048784: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80048788: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8004878C: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80048790: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80048794: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80048798: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8004879C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800487A0: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x800487A4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800487A8: jal         0x800AF060
    // 0x800487AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x800487AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800487B0: jal         0x800A41B4
    // 0x800487B4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x800487B4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_1:
    // 0x800487B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800487BC: addiu       $a1, $a1, -0x2BF0
    ctx->r5 = ADD32(ctx->r5, -0X2BF0);
    // 0x800487C0: jal         0x800A5624
    // 0x800487C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_2;
    // 0x800487C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800487C8: addiu       $t0, $zero, 0x2710
    ctx->r8 = ADD32(0, 0X2710);
    // 0x800487CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800487D0: sw          $t0, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r8;
    // 0x800487D4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800487D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800487DC: sw          $t1, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r9;
    // 0x800487E0: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x800487E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800487E8: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    // 0x800487EC: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
    // 0x800487F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800487F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800487F8: jal         0x800A57C4
    // 0x800487FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800A57C4(rdram, ctx);
        goto after_3;
    // 0x800487FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x80048800: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048804: sh          $zero, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = 0;
    // 0x80048808: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004880C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80048810: sh          $t3, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r11;
    // 0x80048814: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048818: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8004881C: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x80048820: swc1        $f4, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f4.u32l;
    // 0x80048824: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048828: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004882C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80048830: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x80048834: swc1        $f6, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f6.u32l;
    // 0x80048838: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004883C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80048840: addiu       $t8, $t8, 0x7158
    ctx->r24 = ADD32(ctx->r24, 0X7158);
    // 0x80048844: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
    // 0x80048848: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004884C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048850: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80048854: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x80048858: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004885C: addiu       $t7, $t7, 0x7158
    ctx->r15 = ADD32(ctx->r15, 0X7158);
    // 0x80048860: swc1        $f10, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
    // 0x80048864: lwc1        $f20, 0x20($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80048868: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004886C: addiu       $t9, $t9, 0x7158
    ctx->r25 = ADD32(ctx->r25, 0X7158);
    // 0x80048870: swc1        $f20, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f20.u32l;
    // 0x80048874: swc1        $f20, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f20.u32l;
    // 0x80048878: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004887C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048880: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
    // 0x80048884: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048888: swc1        $f16, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f16.u32l;
    // 0x8004888C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80048890: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048894: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048898: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x8004889C: jal         0x800BC6EC
    // 0x800488A0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800488A0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_4:
    // 0x800488A4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800488A8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800488AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800488B0: sw          $t0, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r8;
    // 0x800488B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800488B8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800488BC: nop

    // 0x800488C0: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x800488C4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800488C8: nop

    // 0x800488CC: lwc1        $f22, 0xC($t2)
    ctx->f22.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800488D0: nop

    // 0x800488D4: swc1        $f22, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f22.u32l;
    // 0x800488D8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800488DC: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x800488E0: swc1        $f20, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f20.u32l;
    // 0x800488E4: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800488E8: nop

    // 0x800488EC: swc1        $f20, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f20.u32l;
    // 0x800488F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800488F4: lwc1        $f6, -0x1120($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1120);
    // 0x800488F8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800488FC: nop

    // 0x80048900: swc1        $f6, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f6.u32l;
    // 0x80048904: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80048908: nop

    // 0x8004890C: lwc1        $f22, 0x1C($t8)
    ctx->f22.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80048910: nop

    // 0x80048914: swc1        $f22, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f22.u32l;
    // 0x80048918: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8004891C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80048920: swc1        $f20, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f20.u32l;
    // 0x80048924: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80048928: nop

    // 0x8004892C: swc1        $f20, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f20.u32l;
    // 0x80048930: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80048934: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80048938: nop

    // 0x8004893C: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x80048940: nop

    // 0x80048944: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80048948: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8004894C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80048950: slti        $at, $t3, 0xE43
    ctx->r1 = SIGNED(ctx->r11) < 0XE43 ? 1 : 0;
    // 0x80048954: bne         $at, $zero, L_80048968
    if (ctx->r1 != 0) {
        // 0x80048958: sh          $t1, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r9;
            goto L_80048968;
    }
    // 0x80048958: sh          $t1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r9;
    // 0x8004895C: addiu       $t4, $zero, 0xE42
    ctx->r12 = ADD32(0, 0XE42);
    // 0x80048960: b           L_80048984
    // 0x80048964: sh          $t4, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r12;
        goto L_80048984;
    // 0x80048964: sh          $t4, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r12;
L_80048968:
    // 0x80048968: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x8004896C: nop

    // 0x80048970: slti        $at, $t5, 0x7D0
    ctx->r1 = SIGNED(ctx->r13) < 0X7D0 ? 1 : 0;
    // 0x80048974: beq         $at, $zero, L_80048984
    if (ctx->r1 == 0) {
        // 0x80048978: nop

            goto L_80048984;
    }
    // 0x80048978: nop

    // 0x8004897C: addiu       $t8, $zero, 0x7D0
    ctx->r24 = ADD32(0, 0X7D0);
    // 0x80048980: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
L_80048984:
    // 0x80048984: lh          $t6, 0x56($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X56);
    // 0x80048988: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8004898C: nop

    // 0x80048990: sh          $t6, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r14;
    // 0x80048994: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80048998: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8004899C: nop

    // 0x800489A0: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x800489A4: nop

    // 0x800489A8: addiu       $t1, $t0, 0xB4
    ctx->r9 = ADD32(ctx->r8, 0XB4);
    // 0x800489AC: sh          $t1, 0x4A($t9)
    MEM_H(0X4A, ctx->r25) = ctx->r9;
    // 0x800489B0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800489B4:
    // 0x800489B4: lhu         $t2, 0x54($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X54);
    // 0x800489B8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800489BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800489C0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800489C4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800489C8: lw          $t4, -0x73D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73D0);
    // 0x800489CC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800489D0: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800489D4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800489D8: lw          $t8, 0xC0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC0);
    // 0x800489DC: nop

    // 0x800489E0: ori         $t6, $t8, 0x8240
    ctx->r14 = ctx->r24 | 0X8240;
    // 0x800489E4: sw          $t6, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r14;
    // 0x800489E8: lhu         $t7, 0x54($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X54);
    // 0x800489EC: nop

    // 0x800489F0: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800489F4: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800489F8: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800489FC: bne         $at, $zero, L_800489B4
    if (ctx->r1 != 0) {
        // 0x80048A00: sh          $t0, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r8;
            goto L_800489B4;
    }
    // 0x80048A00: sh          $t0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r8;
    // 0x80048A04: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80048A08: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x80048A0C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80048A10: lw          $t2, 0xC0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC0);
    // 0x80048A14: nop

    // 0x80048A18: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80048A1C: beq         $t3, $zero, L_80048A88
    if (ctx->r11 == 0) {
        // 0x80048A20: nop

            goto L_80048A88;
    }
    // 0x80048A20: nop

    // 0x80048A24: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80048A28: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80048A2C: nop

    // 0x80048A30: lw          $t8, 0xC0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC0);
    // 0x80048A34: nop

    // 0x80048A38: ori         $t6, $t8, 0x8240
    ctx->r14 = ctx->r24 | 0X8240;
    // 0x80048A3C: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x80048A40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80048A44: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80048A48: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80048A4C: sh          $t5, 0xC4($t7)
    MEM_H(0XC4, ctx->r15) = ctx->r13;
    // 0x80048A50: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80048A54: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80048A58: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80048A5C: nop

    // 0x80048A60: andi        $t9, $t1, 0x200
    ctx->r25 = ctx->r9 & 0X200;
    // 0x80048A64: beq         $t9, $zero, L_80048A88
    if (ctx->r25 == 0) {
        // 0x80048A68: nop

            goto L_80048A88;
    }
    // 0x80048A68: nop

    // 0x80048A6C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80048A70: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80048A74: nop

    // 0x80048A78: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x80048A7C: nop

    // 0x80048A80: ori         $t8, $t3, 0x80
    ctx->r24 = ctx->r11 | 0X80;
    // 0x80048A84: sw          $t8, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r24;
L_80048A88:
    // 0x80048A88: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80048A8C: jal         0x800BC6EC
    // 0x80048A90: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80048A90: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_5:
    // 0x80048A94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048A98: sw          $v0, 0x722C($at)
    MEM_W(0X722C, ctx->r1) = ctx->r2;
    // 0x80048A9C: lhu         $t6, 0x54($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AA0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048AA4: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x80048AA8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x80048AAC: lhu         $t5, 0x38($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X38);
    // 0x80048AB0: nop

    // 0x80048AB4: beq         $t5, $at, L_80048B14
    if (ctx->r13 == ctx->r1) {
        // 0x80048AB8: sh          $t5, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r13;
            goto L_80048B14;
    }
    // 0x80048AB8: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
L_80048ABC:
    // 0x80048ABC: lhu         $a0, 0x52($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X52);
    // 0x80048AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80048AC4: jal         0x800AFB70
    // 0x80048AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_6;
    // 0x80048AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80048ACC: lhu         $t0, 0x54($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AD0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80048AD4: lw          $t7, 0x722C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X722C);
    // 0x80048AD8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80048ADC: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80048AE0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80048AE4: lhu         $t3, 0x54($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AE8: nop

    // 0x80048AEC: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80048AF0: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80048AF4: lhu         $t2, 0x54($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AF8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048AFC: sll         $t6, $t2, 1
    ctx->r14 = S32(ctx->r10 << 1);
    // 0x80048B00: addu        $t4, $sp, $t6
    ctx->r12 = ADD32(ctx->r29, ctx->r14);
    // 0x80048B04: lhu         $t4, 0x38($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X38);
    // 0x80048B08: nop

    // 0x80048B0C: bne         $t4, $at, L_80048ABC
    if (ctx->r12 != ctx->r1) {
        // 0x80048B10: sh          $t4, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r12;
            goto L_80048ABC;
    }
    // 0x80048B10: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
L_80048B14:
    // 0x80048B14: jal         0x800BC6EC
    // 0x80048B18: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x80048B18: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    after_7:
    // 0x80048B1C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80048B20: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80048B24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048B28: sw          $t5, 0x7240($at)
    MEM_W(0X7240, ctx->r1) = ctx->r13;
    // 0x80048B2C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80048B30:
    // 0x80048B30: lhu         $t0, 0x54($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X54);
    // 0x80048B34: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80048B38: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80048B3C: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80048B40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048B44: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80048B48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048B4C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80048B50: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80048B54: addiu       $t1, $t7, 0x9DD
    ctx->r9 = ADD32(ctx->r15, 0X9DD);
    // 0x80048B58: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80048B5C: nop

    // 0x80048B60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80048B64: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x80048B68: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80048B6C: nop

    // 0x80048B70: addiu       $t8, $t3, 0x10
    ctx->r24 = ADD32(ctx->r11, 0X10);
    // 0x80048B74: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80048B78: lhu         $t2, 0x54($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X54);
    // 0x80048B7C: nop

    // 0x80048B80: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x80048B84: andi        $t4, $t6, 0xFFFF
    ctx->r12 = ctx->r14 & 0XFFFF;
    // 0x80048B88: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80048B8C: bne         $at, $zero, L_80048B30
    if (ctx->r1 != 0) {
        // 0x80048B90: sh          $t6, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r14;
            goto L_80048B30;
    }
    // 0x80048B90: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80048B94: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80048B98: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
L_80048B9C:
    // 0x80048B9C: lhu         $t0, 0x54($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X54);
    // 0x80048BA0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80048BA4: negu        $at, $t0
    ctx->r1 = SUB32(0, ctx->r8);
    // 0x80048BA8: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x80048BAC: addu        $t7, $t7, $at
    ctx->r15 = ADD32(ctx->r15, ctx->r1);
    // 0x80048BB0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048BB4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80048BB8: nop

    // 0x80048BBC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80048BC0: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x80048BC4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80048BC8: nop

    // 0x80048BCC: addiu       $t3, $t9, 0x10
    ctx->r11 = ADD32(ctx->r25, 0X10);
    // 0x80048BD0: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80048BD4: lhu         $t8, 0x54($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X54);
    // 0x80048BD8: nop

    // 0x80048BDC: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x80048BE0: andi        $t6, $t2, 0xFFFF
    ctx->r14 = ctx->r10 & 0XFFFF;
    // 0x80048BE4: slti        $at, $t6, 0x12
    ctx->r1 = SIGNED(ctx->r14) < 0X12 ? 1 : 0;
    // 0x80048BE8: bne         $at, $zero, L_80048B9C
    if (ctx->r1 != 0) {
        // 0x80048BEC: sh          $t2, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r10;
            goto L_80048B9C;
    }
    // 0x80048BEC: sh          $t2, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r10;
    // 0x80048BF0: jal         0x80044444
    // 0x80048BF4: nop

    func_80044444(rdram, ctx);
        goto after_8;
    // 0x80048BF4: nop

    after_8:
    // 0x80048BF8: jal         0x80021ED0
    // 0x80048BFC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_9;
    // 0x80048BFC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_9:
    // 0x80048C00: b           L_80048C08
    // 0x80048C04: nop

        goto L_80048C08;
    // 0x80048C04: nop

L_80048C08:
    // 0x80048C08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80048C0C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80048C10: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80048C14: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80048C18: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80048C1C: jr          $ra
    // 0x80048C20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80048C20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80048C24: nop

    // 0x80048C28: nop

    // 0x80048C2C: nop

;}
RECOMP_FUNC void func_80048C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80048C34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048C38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80048C3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80048C40: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80048C44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048C48: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80048C4C: nop

    // 0x80048C50: beq         $t6, $zero, L_80048C68
    if (ctx->r14 == 0) {
        // 0x80048C54: nop

            goto L_80048C68;
    }
    // 0x80048C54: nop

    // 0x80048C58: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80048C5C: nop

    // 0x80048C60: bne         $t7, $zero, L_80048C70
    if (ctx->r15 != 0) {
        // 0x80048C64: nop

            goto L_80048C70;
    }
    // 0x80048C64: nop

L_80048C68:
    // 0x80048C68: b           L_80048DB4
    // 0x80048C6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80048DB4;
    // 0x80048C6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80048C70:
    // 0x80048C70: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80048C74: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80048C78: nop

    // 0x80048C7C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80048C80: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80048C84: nop

    // 0x80048C88: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80048C8C: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x80048C90: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80048C94: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048C98: lhu         $s0, 0x0($t0)
    ctx->r16 = MEM_HU(ctx->r8, 0X0);
    // 0x80048C9C: addiu       $t2, $t0, 0x2
    ctx->r10 = ADD32(ctx->r8, 0X2);
    // 0x80048CA0: xor         $t1, $s0, $at
    ctx->r9 = ctx->r16 ^ ctx->r1;
    // 0x80048CA4: sltu        $t1, $zero, $t1
    ctx->r9 = 0 < ctx->r9 ? 1 : 0;
    // 0x80048CA8: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80048CAC: beq         $s0, $zero, L_80048CE8
    if (ctx->r16 == 0) {
        // 0x80048CB0: sw          $t2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r10;
            goto L_80048CE8;
    }
    // 0x80048CB0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80048CB4:
    // 0x80048CB4: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048CB8: nop

    // 0x80048CBC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80048CC0: sh          $t4, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r12;
    // 0x80048CC4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80048CC8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048CCC: lhu         $s0, 0x0($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0X0);
    // 0x80048CD0: addiu       $t7, $t5, 0x2
    ctx->r15 = ADD32(ctx->r13, 0X2);
    // 0x80048CD4: xor         $t6, $s0, $at
    ctx->r14 = ctx->r16 ^ ctx->r1;
    // 0x80048CD8: sltu        $t6, $zero, $t6
    ctx->r14 = 0 < ctx->r14 ? 1 : 0;
    // 0x80048CDC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80048CE0: bne         $s0, $zero, L_80048CB4
    if (ctx->r16 != 0) {
        // 0x80048CE4: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_80048CB4;
    }
    // 0x80048CE4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80048CE8:
    // 0x80048CE8: lhu         $t8, 0x2C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048CEC: nop

    // 0x80048CF0: bne         $t8, $zero, L_80048D00
    if (ctx->r24 != 0) {
        // 0x80048CF4: nop

            goto L_80048D00;
    }
    // 0x80048CF4: nop

    // 0x80048CF8: b           L_80048DB4
    // 0x80048CFC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80048DB4;
    // 0x80048CFC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80048D00:
    // 0x80048D00: lhu         $a0, 0x2C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D04: nop

    // 0x80048D08: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80048D0C: jal         0x800BC6EC
    // 0x80048D10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80048D10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80048D14: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80048D18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80048D1C: sw          $s0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r16;
    // 0x80048D20: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80048D24: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80048D28: nop

    // 0x80048D2C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80048D30: lhu         $t2, 0x2C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D34: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80048D38: blez        $t2, L_80048D88
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80048D3C: nop

            goto L_80048D88;
    }
    // 0x80048D3C: nop

L_80048D40:
    // 0x80048D40: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80048D44: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80048D48: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80048D4C: nop

    // 0x80048D50: sh          $t4, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r12;
    // 0x80048D54: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80048D58: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80048D5C: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x80048D60: addiu       $t7, $t5, 0x2
    ctx->r15 = ADD32(ctx->r13, 0X2);
    // 0x80048D64: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80048D68: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80048D6C: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
    // 0x80048D70: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D74: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80048D78: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x80048D7C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80048D80: bne         $at, $zero, L_80048D40
    if (ctx->r1 != 0) {
        // 0x80048D84: sh          $t0, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r8;
            goto L_80048D40;
    }
    // 0x80048D84: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
L_80048D88:
    // 0x80048D88: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80048D90: nop

    // 0x80048D94: sh          $t4, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r12;
    // 0x80048D98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80048D9C: jal         0x80048F40
    // 0x80048DA0: nop

    func_80048F40(rdram, ctx);
        goto after_1;
    // 0x80048DA0: nop

    after_1:
    // 0x80048DA4: b           L_80048DB4
    // 0x80048DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80048DB4;
    // 0x80048DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048DAC: b           L_80048DB4
    // 0x80048DB0: nop

        goto L_80048DB4;
    // 0x80048DB0: nop

L_80048DB4:
    // 0x80048DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80048DB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80048DBC: jr          $ra
    // 0x80048DC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80048DC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80048DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048DC4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80048DC8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80048DCC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80048DD0: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80048DD4: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80048DD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048DDC: nop

    // 0x80048DE0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80048DE4: nop

    // 0x80048DE8: bc1t        L_80048E30
    if (c1cs) {
        // 0x80048DEC: nop

            goto L_80048E30;
    }
    // 0x80048DEC: nop

    // 0x80048DF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80048DF4: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80048DF8: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80048DFC: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80048E00: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80048E04: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80048E08: swc1        $f18, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f18.u32l;
    // 0x80048E0C: bc1f        L_80048E24
    if (!c1cs) {
        // 0x80048E10: nop

            goto L_80048E24;
    }
    // 0x80048E10: nop

    // 0x80048E14: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80048E18: nop

    // 0x80048E1C: ori         $t7, $t6, 0x3
    ctx->r15 = ctx->r14 | 0X3;
    // 0x80048E20: sh          $t7, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r15;
L_80048E24:
    // 0x80048E24: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80048E28: nop

    // 0x80048E2C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
L_80048E30:
    // 0x80048E30: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x80048E34: nop

    // 0x80048E38: sh          $t8, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r24;
    // 0x80048E3C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80048E40: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80048E44: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x80048E48: nop

    // 0x80048E4C: beq         $t0, $zero, L_80048E68
    if (ctx->r8 == 0) {
        // 0x80048E50: sh          $t0, 0xE($sp)
        MEM_H(0XE, ctx->r29) = ctx->r8;
            goto L_80048E68;
    }
    // 0x80048E50: sh          $t0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r8;
    // 0x80048E54: lhu         $t1, 0xC($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XC);
    // 0x80048E58: nop

    // 0x80048E5C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80048E60: beq         $t2, $zero, L_80048E74
    if (ctx->r10 == 0) {
        // 0x80048E64: nop

            goto L_80048E74;
    }
    // 0x80048E64: nop

L_80048E68:
    // 0x80048E68: lh          $v0, 0xC($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XC);
    // 0x80048E6C: b           L_80048F38
    // 0x80048E70: nop

        goto L_80048F38;
    // 0x80048E70: nop

L_80048E74:
    // 0x80048E74: lhu         $t3, 0xA($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0XA);
    // 0x80048E78: nop

    // 0x80048E7C: sh          $t3, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r11;
    // 0x80048E80: lhu         $t5, 0xA($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XA);
    // 0x80048E84: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    // 0x80048E88: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80048E8C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80048E90: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80048E94: lhu         $t9, 0xE($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XE);
    // 0x80048E98: nop

    // 0x80048E9C: beq         $t8, $t9, L_80048EB4
    if (ctx->r24 == ctx->r25) {
        // 0x80048EA0: nop

            goto L_80048EB4;
    }
    // 0x80048EA0: nop

    // 0x80048EA4: lhu         $t0, 0xC($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XC);
    // 0x80048EA8: nop

    // 0x80048EAC: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80048EB0: sh          $t1, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r9;
L_80048EB4:
    // 0x80048EB4: lhu         $t2, 0xA($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XA);
    // 0x80048EB8: nop

    // 0x80048EBC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80048EC0: sh          $t3, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r11;
    // 0x80048EC4: lhu         $t5, 0xA($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XA);
    // 0x80048EC8: lhu         $t4, 0x8($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X8);
    // 0x80048ECC: nop

    // 0x80048ED0: bne         $t5, $t4, L_80048F0C
    if (ctx->r13 != ctx->r12) {
        // 0x80048ED4: nop

            goto L_80048F0C;
    }
    // 0x80048ED4: nop

    // 0x80048ED8: lhu         $t6, 0xC($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XC);
    // 0x80048EDC: nop

    // 0x80048EE0: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80048EE4: sh          $t7, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r15;
    // 0x80048EE8: lhu         $t8, 0xC($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XC);
    // 0x80048EEC: nop

    // 0x80048EF0: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80048EF4: bne         $t9, $zero, L_80048F0C
    if (ctx->r25 != 0) {
        // 0x80048EF8: nop

            goto L_80048F0C;
    }
    // 0x80048EF8: nop

    // 0x80048EFC: lhu         $t0, 0xC($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XC);
    // 0x80048F00: nop

    // 0x80048F04: ori         $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 | 0X8000;
    // 0x80048F08: sh          $t1, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r9;
L_80048F0C:
    // 0x80048F0C: lhu         $t2, 0xC($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XC);
    // 0x80048F10: nop

    // 0x80048F14: sh          $t2, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r10;
    // 0x80048F18: lhu         $t3, 0xA($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XA);
    // 0x80048F1C: nop

    // 0x80048F20: sh          $t3, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r11;
    // 0x80048F24: lh          $v0, 0xC($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XC);
    // 0x80048F28: b           L_80048F38
    // 0x80048F2C: nop

        goto L_80048F38;
    // 0x80048F2C: nop

    // 0x80048F30: b           L_80048F38
    // 0x80048F34: nop

        goto L_80048F38;
    // 0x80048F34: nop

L_80048F38:
    // 0x80048F38: jr          $ra
    // 0x80048F3C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80048F3C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80048F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048F40: bne         $a0, $zero, L_80048F50
    if (ctx->r4 != 0) {
        // 0x80048F44: nop

            goto L_80048F50;
    }
    // 0x80048F44: nop

    // 0x80048F48: jr          $ra
    // 0x80048F4C: nop

    return;
    // 0x80048F4C: nop

L_80048F50:
    // 0x80048F50: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80048F54: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80048F58: nop

    // 0x80048F5C: sh          $t6, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r14;
    // 0x80048F60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048F64: nop

    // 0x80048F68: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80048F6C: jr          $ra
    // 0x80048F70: nop

    return;
    // 0x80048F70: nop

    // 0x80048F74: jr          $ra
    // 0x80048F78: nop

    return;
    // 0x80048F78: nop

;}
RECOMP_FUNC void func_80048F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048F7C: nop

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
RECOMP_FUNC void func_800490C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800490C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800490C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800490C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800490CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800490D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800490D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800490D8: lbu         $t7, 0x7E($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X7E);
    // 0x800490DC: addiu       $t9, $t9, 0xEF8
    ctx->r25 = ADD32(ctx->r25, 0XEF8);
    // 0x800490E0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800490E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800490E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800490EC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800490F0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800490F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800490F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800490FC: jal         0x800C0640
    // 0x80049100: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    Thread_CreateSimple(rdram, ctx);
        goto after_0;
    // 0x80049100: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_0:
    // 0x80049104: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80049108: nop

    // 0x8004910C: sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    // 0x80049110: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80049114: nop

    // 0x80049118: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x8004911C: jal         0x800C0988
    // 0x80049120: nop

    func_800C0988(rdram, ctx);
        goto after_1;
    // 0x80049120: nop

    after_1:
    // 0x80049124: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80049128: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x8004912C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80049130: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80049134: nop

    // 0x80049138: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x8004913C: jal         0x800C0E04
    // 0x80049140: nop

    Thread_GetPtr(rdram, ctx);
        goto after_2;
    // 0x80049140: nop

    after_2:
    // 0x80049144: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80049148: nop

    // 0x8004914C: sw          $v0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r2;
    // 0x80049150: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80049154: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80049158: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8004915C: nop

    // 0x80049160: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80049164: sw          $t7, 0x2F9($at)
    MEM_W(0X2F9, ctx->r1) = ctx->r15;
    // 0x80049168: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8004916C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80049170: sb          $t0, 0x20($t1)
    MEM_B(0X20, ctx->r9) = ctx->r8;
    // 0x80049174: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80049178: nop

    // 0x8004917C: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80049180: jal         0x800C0C8C
    // 0x80049184: nop

    Thread_Start(rdram, ctx);
        goto after_3;
    // 0x80049184: nop

    after_3:
    // 0x80049188: b           L_80049190
    // 0x8004918C: nop

        goto L_80049190;
    // 0x8004918C: nop

L_80049190:
    // 0x80049190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049198: jr          $ra
    // 0x8004919C: nop

    return;
    // 0x8004919C: nop

;}
RECOMP_FUNC void func_800491A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800491A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800491A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800491A8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800491AC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800491B0: addiu       $a1, $a1, 0xFF8
    ctx->r5 = ADD32(ctx->r5, 0XFF8);
    // 0x800491B4: addiu       $a0, $a0, -0x2898
    ctx->r4 = ADD32(ctx->r4, -0X2898);
    // 0x800491B8: jal         0x800C0640
    // 0x800491BC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    Thread_CreateSimple(rdram, ctx);
        goto after_0;
    // 0x800491BC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_0:
    // 0x800491C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800491C4: sb          $v0, 0xFF8($at)
    MEM_B(0XFF8, ctx->r1) = ctx->r2;
    // 0x800491C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800491CC: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x800491D0: jal         0x800C0988
    // 0x800491D4: nop

    func_800C0988(rdram, ctx);
        goto after_1;
    // 0x800491D4: nop

    after_1:
    // 0x800491D8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800491DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800491E0: sw          $t6, 0xFFC($at)
    MEM_W(0XFFC, ctx->r1) = ctx->r14;
    // 0x800491E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800491E8: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x800491EC: jal         0x800C0E04
    // 0x800491F0: nop

    Thread_GetPtr(rdram, ctx);
        goto after_2;
    // 0x800491F0: nop

    after_2:
    // 0x800491F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800491F8: sw          $v0, 0x1010($at)
    MEM_W(0X1010, ctx->r1) = ctx->r2;
    // 0x800491FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80049200: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049204: sb          $t7, 0x1018($at)
    MEM_B(0X1018, ctx->r1) = ctx->r15;
    // 0x80049208: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004920C: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x80049210: jal         0x800C0C8C
    // 0x80049214: nop

    Thread_Start(rdram, ctx);
        goto after_3;
    // 0x80049214: nop

    after_3:
    // 0x80049218: b           L_80049220
    // 0x8004921C: nop

        goto L_80049220;
    // 0x8004921C: nop

L_80049220:
    // 0x80049220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049228: jr          $ra
    // 0x8004922C: nop

    return;
    // 0x8004922C: nop

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
RECOMP_FUNC void func_80049438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004943C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049440: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80049444: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80049448: nop

    // 0x8004944C: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80049450: nop

    // 0x80049454: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80049458: jal         0x800C0B70
    // 0x8004945C: nop

    Thread_DestroyThread(rdram, ctx);
        goto after_0;
    // 0x8004945C: nop

    after_0:
    // 0x80049460: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80049464: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049468: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x8004946C: nop

    // 0x80049470: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80049474: nop

    // 0x80049478: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8004947C: lh          $t1, 0x2F7($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2F7);
    // 0x80049480: nop

    // 0x80049484: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80049488: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8004948C: lw          $a0, 0x1028($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1028);
    // 0x80049490: jal         0x800BC980
    // 0x80049494: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80049494: nop

    after_1:
    // 0x80049498: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8004949C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800494A0: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800494A4: nop

    // 0x800494A8: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x800494AC: nop

    // 0x800494B0: addiu       $t6, $t5, 0x7FFF
    ctx->r14 = ADD32(ctx->r13, 0X7FFF);
    // 0x800494B4: lh          $t6, 0x2F7($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2F7);
    // 0x800494B8: nop

    // 0x800494BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800494C0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800494C4: sw          $zero, 0x1028($at)
    MEM_W(0X1028, ctx->r1) = 0;
    // 0x800494C8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800494CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800494D0: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800494D4: nop

    // 0x800494D8: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800494DC: nop

    // 0x800494E0: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800494E4: lh          $t1, 0x2F7($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2F7);
    // 0x800494E8: sb          $t2, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r10;
    // 0x800494EC: beq         $t1, $zero, L_80049510
    if (ctx->r9 == 0) {
        // 0x800494F0: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_80049510;
    }
    // 0x800494F0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_800494F4:
    // 0x800494F4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800494F8: lbu         $t5, 0x1B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X1B);
    // 0x800494FC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80049500: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80049504: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x80049508: bne         $t4, $zero, L_800494F4
    if (ctx->r12 != 0) {
        // 0x8004950C: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800494F4;
    }
    // 0x8004950C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_80049510:
    // 0x80049510: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x80049514: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049518: lbu         $t7, 0x1040($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1040);
    // 0x8004951C: nor         $t9, $t8, $zero
    ctx->r25 = ~(ctx->r24 | 0);
    // 0x80049520: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049524: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x80049528: sb          $t0, 0x1040($at)
    MEM_B(0X1040, ctx->r1) = ctx->r8;
    // 0x8004952C: b           L_80049534
    // 0x80049530: nop

        goto L_80049534;
    // 0x80049530: nop

L_80049534:
    // 0x80049534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004953C: jr          $ra
    // 0x80049540: nop

    return;
    // 0x80049540: nop

;}
RECOMP_FUNC void func_80049544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004954C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80049550: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80049554: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80049558: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004955C: nop

    // 0x80049560: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80049564: bne         $t8, $zero, L_80049724
    if (ctx->r24 != 0) {
        // 0x80049568: nop

            goto L_80049724;
    }
    // 0x80049568: nop

    // 0x8004956C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80049570: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80049574: lbu         $t1, 0xFF8($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XFF8);
    // 0x80049578: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8004957C: nop

    // 0x80049580: bne         $t0, $t1, L_80049614
    if (ctx->r8 != ctx->r9) {
        // 0x80049584: nop

            goto L_80049614;
    }
    // 0x80049584: nop

    // 0x80049588: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004958C: lbu         $t2, 0xEE8($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XEE8);
    // 0x80049590: nop

    // 0x80049594: beq         $t2, $zero, L_800495BC
    if (ctx->r10 == 0) {
        // 0x80049598: nop

            goto L_800495BC;
    }
    // 0x80049598: nop

    // 0x8004959C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800495A0: lbu         $a0, 0xEC8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XEC8);
    // 0x800495A4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800495A8: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x800495AC: jal         0x800C1264
    // 0x800495B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x800495B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800495B4: b           L_8004974C
    // 0x800495B8: nop

        goto L_8004974C;
    // 0x800495B8: nop

L_800495BC:
    // 0x800495BC: jal         0x8004975C
    // 0x800495C0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_8004975C(rdram, ctx);
        goto after_1;
    // 0x800495C0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_1:
    // 0x800495C4: beq         $v0, $zero, L_800495D4
    if (ctx->r2 == 0) {
        // 0x800495C8: nop

            goto L_800495D4;
    }
    // 0x800495C8: nop

    // 0x800495CC: b           L_8004974C
    // 0x800495D0: nop

        goto L_8004974C;
    // 0x800495D0: nop

L_800495D4:
    // 0x800495D4: jal         0x800498CC
    // 0x800495D8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_800498CC(rdram, ctx);
        goto after_2;
    // 0x800495D8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_2:
    // 0x800495DC: beq         $v0, $zero, L_800495EC
    if (ctx->r2 == 0) {
        // 0x800495E0: nop

            goto L_800495EC;
    }
    // 0x800495E0: nop

    // 0x800495E4: b           L_8004974C
    // 0x800495E8: nop

        goto L_8004974C;
    // 0x800495E8: nop

L_800495EC:
    // 0x800495EC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800495F0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800495F4: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x800495F8: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x800495FC: jal         0x800C1528
    // 0x80049600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_3;
    // 0x80049600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80049604: b           L_8004974C
    // 0x80049608: nop

        goto L_8004974C;
    // 0x80049608: nop

    // 0x8004960C: b           L_80049724
    // 0x80049610: nop

        goto L_80049724;
    // 0x80049610: nop

L_80049614:
    // 0x80049614: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80049618: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004961C: lbu         $t5, 0xEC8($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0XEC8);
    // 0x80049620: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80049624: nop

    // 0x80049628: bne         $t4, $t5, L_80049688
    if (ctx->r12 != ctx->r13) {
        // 0x8004962C: nop

            goto L_80049688;
    }
    // 0x8004962C: nop

    // 0x80049630: jal         0x8004975C
    // 0x80049634: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_8004975C(rdram, ctx);
        goto after_4;
    // 0x80049634: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_4:
    // 0x80049638: beq         $v0, $zero, L_80049648
    if (ctx->r2 == 0) {
        // 0x8004963C: nop

            goto L_80049648;
    }
    // 0x8004963C: nop

    // 0x80049640: b           L_8004974C
    // 0x80049644: nop

        goto L_8004974C;
    // 0x80049644: nop

L_80049648:
    // 0x80049648: jal         0x800498CC
    // 0x8004964C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_800498CC(rdram, ctx);
        goto after_5;
    // 0x8004964C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_5:
    // 0x80049650: beq         $v0, $zero, L_80049660
    if (ctx->r2 == 0) {
        // 0x80049654: nop

            goto L_80049660;
    }
    // 0x80049654: nop

    // 0x80049658: b           L_8004974C
    // 0x8004965C: nop

        goto L_8004974C;
    // 0x8004965C: nop

L_80049660:
    // 0x80049660: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80049664: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80049668: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x8004966C: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x80049670: jal         0x800C1528
    // 0x80049674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_6;
    // 0x80049674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80049678: b           L_8004974C
    // 0x8004967C: nop

        goto L_8004974C;
    // 0x8004967C: nop

    // 0x80049680: b           L_80049724
    // 0x80049684: nop

        goto L_80049724;
    // 0x80049684: nop

L_80049688:
    // 0x80049688: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004968C: jal         0x8004984C
    // 0x80049690: nop

    func_8004984C(rdram, ctx);
        goto after_7;
    // 0x80049690: nop

    after_7:
    // 0x80049694: beq         $v0, $zero, L_80049700
    if (ctx->r2 == 0) {
        // 0x80049698: nop

            goto L_80049700;
    }
    // 0x80049698: nop

    // 0x8004969C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800496A0: nop

    // 0x800496A4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800496A8: jal         0x8004975C
    // 0x800496AC: nop

    func_8004975C(rdram, ctx);
        goto after_8;
    // 0x800496AC: nop

    after_8:
    // 0x800496B0: beq         $v0, $zero, L_800496C0
    if (ctx->r2 == 0) {
        // 0x800496B4: nop

            goto L_800496C0;
    }
    // 0x800496B4: nop

    // 0x800496B8: b           L_8004974C
    // 0x800496BC: nop

        goto L_8004974C;
    // 0x800496BC: nop

L_800496C0:
    // 0x800496C0: jal         0x800498CC
    // 0x800496C4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_800498CC(rdram, ctx);
        goto after_9;
    // 0x800496C4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_9:
    // 0x800496C8: beq         $v0, $zero, L_800496D8
    if (ctx->r2 == 0) {
        // 0x800496CC: nop

            goto L_800496D8;
    }
    // 0x800496CC: nop

    // 0x800496D0: b           L_8004974C
    // 0x800496D4: nop

        goto L_8004974C;
    // 0x800496D4: nop

L_800496D8:
    // 0x800496D8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800496DC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800496E0: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x800496E4: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x800496E8: jal         0x800C1528
    // 0x800496EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_10;
    // 0x800496EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x800496F0: b           L_8004974C
    // 0x800496F4: nop

        goto L_8004974C;
    // 0x800496F4: nop

    // 0x800496F8: b           L_80049724
    // 0x800496FC: nop

        goto L_80049724;
    // 0x800496FC: nop

L_80049700:
    // 0x80049700: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80049704: nop

    // 0x80049708: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8004970C: jal         0x800498CC
    // 0x80049710: nop

    func_800498CC(rdram, ctx);
        goto after_11;
    // 0x80049710: nop

    after_11:
    // 0x80049714: beq         $v0, $zero, L_80049724
    if (ctx->r2 == 0) {
        // 0x80049718: nop

            goto L_80049724;
    }
    // 0x80049718: nop

    // 0x8004971C: b           L_8004974C
    // 0x80049720: nop

        goto L_8004974C;
    // 0x80049720: nop

L_80049724:
    // 0x80049724: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80049728: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8004972C: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x80049730: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x80049734: jal         0x800C1528
    // 0x80049738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_12;
    // 0x80049738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x8004973C: b           L_8004974C
    // 0x80049740: nop

        goto L_8004974C;
    // 0x80049740: nop

    // 0x80049744: b           L_8004974C
    // 0x80049748: nop

        goto L_8004974C;
    // 0x80049748: nop

L_8004974C:
    // 0x8004974C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049754: jr          $ra
    // 0x80049758: nop

    return;
    // 0x80049758: nop

;}
RECOMP_FUNC void func_8004975C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004975C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049764: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80049768: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8004976C: nop

    // 0x80049770: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x80049774: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80049778:
    // 0x80049778: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8004977C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80049780: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80049784: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80049788: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004978C: addiu       $t9, $t9, 0xEF8
    ctx->r25 = ADD32(ctx->r25, 0XEF8);
    // 0x80049790: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80049794: lbu         $t1, 0x20($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X20);
    // 0x80049798: nop

    // 0x8004979C: beq         $t1, $zero, L_800497E0
    if (ctx->r9 == 0) {
        // 0x800497A0: nop

            goto L_800497E0;
    }
    // 0x800497A0: nop

    // 0x800497A4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800497A8: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x800497AC: nop

    // 0x800497B0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800497B4: beq         $at, $zero, L_800497E0
    if (ctx->r1 == 0) {
        // 0x800497B8: nop

            goto L_800497E0;
    }
    // 0x800497B8: nop

    // 0x800497BC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800497C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800497C4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800497C8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800497CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800497D0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800497D4: lbu         $t6, 0xEF8($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XEF8);
    // 0x800497D8: nop

    // 0x800497DC: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
L_800497E0:
    // 0x800497E0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800497E4: nop

    // 0x800497E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800497EC: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x800497F0: bne         $at, $zero, L_80049778
    if (ctx->r1 != 0) {
        // 0x800497F4: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80049778;
    }
    // 0x800497F4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800497F8: lbu         $t9, 0x1B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1B);
    // 0x800497FC: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x80049800: nop

    // 0x80049804: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80049808: beq         $at, $zero, L_8004982C
    if (ctx->r1 == 0) {
        // 0x8004980C: nop

            goto L_8004982C;
    }
    // 0x8004980C: nop

    // 0x80049810: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x80049814: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80049818: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x8004981C: jal         0x800C1264
    // 0x80049820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x80049820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80049824: b           L_8004983C
    // 0x80049828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004983C;
    // 0x80049828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004982C:
    // 0x8004982C: b           L_8004983C
    // 0x80049830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004983C;
    // 0x80049830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049834: b           L_8004983C
    // 0x80049838: nop

        goto L_8004983C;
    // 0x80049838: nop

L_8004983C:
    // 0x8004983C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049844: jr          $ra
    // 0x80049848: nop

    return;
    // 0x80049848: nop

;}
RECOMP_FUNC void func_8004984C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004984C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80049850: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80049854:
    // 0x80049854: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80049858: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004985C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80049860: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80049864: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80049868: addiu       $t8, $t8, 0xEF8
    ctx->r24 = ADD32(ctx->r24, 0XEF8);
    // 0x8004986C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80049870: lbu         $t0, 0x20($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X20);
    // 0x80049874: nop

    // 0x80049878: beq         $t0, $zero, L_8004989C
    if (ctx->r8 == 0) {
        // 0x8004987C: nop

            goto L_8004989C;
    }
    // 0x8004987C: nop

    // 0x80049880: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x80049884: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x80049888: nop

    // 0x8004988C: bne         $t1, $t2, L_8004989C
    if (ctx->r9 != ctx->r10) {
        // 0x80049890: nop

            goto L_8004989C;
    }
    // 0x80049890: nop

    // 0x80049894: b           L_800498C4
    // 0x80049898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800498C4;
    // 0x80049898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004989C:
    // 0x8004989C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800498A0: nop

    // 0x800498A4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800498A8: slti        $at, $t4, 0x7
    ctx->r1 = SIGNED(ctx->r12) < 0X7 ? 1 : 0;
    // 0x800498AC: bne         $at, $zero, L_80049854
    if (ctx->r1 != 0) {
        // 0x800498B0: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_80049854;
    }
    // 0x800498B0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800498B4: b           L_800498C4
    // 0x800498B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800498C4;
    // 0x800498B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800498BC: b           L_800498C4
    // 0x800498C0: nop

        goto L_800498C4;
    // 0x800498C0: nop

L_800498C4:
    // 0x800498C4: jr          $ra
    // 0x800498C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800498C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800498CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800498CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800498D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800498D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800498D8: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800498DC: nop

    // 0x800498E0: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x800498E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800498E8:
    // 0x800498E8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800498EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800498F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800498F4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800498F8: lw          $t9, 0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1028);
    // 0x800498FC: nop

    // 0x80049900: beq         $t9, $zero, L_80049944
    if (ctx->r25 == 0) {
        // 0x80049904: nop

            goto L_80049944;
    }
    // 0x80049904: nop

    // 0x80049908: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8004990C: lbu         $t1, 0x1B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1B);
    // 0x80049910: nop

    // 0x80049914: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80049918: beq         $at, $zero, L_80049944
    if (ctx->r1 == 0) {
        // 0x8004991C: nop

            goto L_80049944;
    }
    // 0x8004991C: nop

    // 0x80049920: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80049924: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80049928: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004992C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80049930: lw          $t4, 0x1028($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1028);
    // 0x80049934: nop

    // 0x80049938: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8004993C: nop

    // 0x80049940: sb          $t5, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r13;
L_80049944:
    // 0x80049944: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80049948: nop

    // 0x8004994C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80049950: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80049954: bne         $at, $zero, L_800498E8
    if (ctx->r1 != 0) {
        // 0x80049958: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_800498E8;
    }
    // 0x80049958: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8004995C: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x80049960: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x80049964: nop

    // 0x80049968: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8004996C: beq         $at, $zero, L_80049990
    if (ctx->r1 == 0) {
        // 0x80049970: nop

            goto L_80049990;
    }
    // 0x80049970: nop

    // 0x80049974: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x80049978: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8004997C: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x80049980: jal         0x800C1264
    // 0x80049984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x80049984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80049988: b           L_800499A0
    // 0x8004998C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800499A0;
    // 0x8004998C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80049990:
    // 0x80049990: b           L_800499A0
    // 0x80049994: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800499A0;
    // 0x80049994: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049998: b           L_800499A0
    // 0x8004999C: nop

        goto L_800499A0;
    // 0x8004999C: nop

L_800499A0:
    // 0x800499A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800499A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800499A8: jr          $ra
    // 0x800499AC: nop

    return;
    // 0x800499AC: nop

;}
RECOMP_FUNC void func_800499B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800499B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800499B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800499B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800499BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800499C0: lw          $t6, 0x6C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C4);
    // 0x800499C4: nop

    // 0x800499C8: beq         $t6, $zero, L_800499DC
    if (ctx->r14 == 0) {
        // 0x800499CC: nop

            goto L_800499DC;
    }
    // 0x800499CC: nop

    // 0x800499D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800499D4: jal         0x80049544
    // 0x800499D8: nop

    func_80049544(rdram, ctx);
        goto after_0;
    // 0x800499D8: nop

    after_0:
L_800499DC:
    // 0x800499DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800499E0: jal         0x80032410
    // 0x800499E4: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x800499E4: nop

    after_1:
    // 0x800499E8: b           L_800499F0
    // 0x800499EC: nop

        goto L_800499F0;
    // 0x800499EC: nop

L_800499F0:
    // 0x800499F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800499F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800499F8: jr          $ra
    // 0x800499FC: nop

    return;
    // 0x800499FC: nop

;}
RECOMP_FUNC void func_80049A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049A00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80049A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80049A08: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80049A0C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80049A10: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80049A14: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80049A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80049A1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80049A20: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    // 0x80049A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049A28: bne         $t6, $at, L_80049A38
    if (ctx->r14 != ctx->r1) {
        // 0x80049A2C: nop

            goto L_80049A38;
    }
    // 0x80049A2C: nop

    // 0x80049A30: b           L_80049A3C
    // 0x80049A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80049A3C;
    // 0x80049A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80049A38:
    // 0x80049A38: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80049A3C:
    // 0x80049A3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80049A40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80049A44: jal         0x8005EB00
    // 0x80049A48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8005EB00(rdram, ctx);
        goto after_0;
    // 0x80049A48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80049A4C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80049A50: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80049A54: nop

    // 0x80049A58: beq         $t7, $zero, L_8004A02C
    if (ctx->r15 == 0) {
        // 0x80049A5C: nop

            goto L_8004A02C;
    }
    // 0x80049A5C: nop

    // 0x80049A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049A64: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80049A68: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80049A6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80049A70: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80049A74: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80049A78: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80049A7C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80049A80: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80049A84: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80049A88: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80049A8C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80049A90: nop

    // 0x80049A94: beq         $t9, $zero, L_80049AA8
    if (ctx->r25 == 0) {
        // 0x80049A98: nop

            goto L_80049AA8;
    }
    // 0x80049A98: nop

    // 0x80049A9C: lui         $s0, 0x80
    ctx->r16 = S32(0X80 << 16);
    // 0x80049AA0: b           L_80049AAC
    // 0x80049AA4: ori         $s0, $s0, 0x8
    ctx->r16 = ctx->r16 | 0X8;
        goto L_80049AAC;
    // 0x80049AA4: ori         $s0, $s0, 0x8
    ctx->r16 = ctx->r16 | 0X8;
L_80049AA8:
    // 0x80049AA8: lui         $s0, 0x80
    ctx->r16 = S32(0X80 << 16);
L_80049AAC:
    // 0x80049AAC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80049AB0: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x80049AB4: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80049AB8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80049ABC: sra         $t0, $s0, 31
    ctx->r8 = S32(SIGNED(ctx->r16) >> 31);
    // 0x80049AC0: or          $t2, $t6, $t0
    ctx->r10 = ctx->r14 | ctx->r8;
    // 0x80049AC4: or          $t3, $t7, $t1
    ctx->r11 = ctx->r15 | ctx->r9;
    // 0x80049AC8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80049ACC: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80049AD0: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x80049AD4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80049AD8: nop

    // 0x80049ADC: sh          $t5, 0x48($t8)
    MEM_H(0X48, ctx->r24) = ctx->r13;
    // 0x80049AE0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80049AE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80049AE8: nop

    // 0x80049AEC: sw          $t9, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r25;
    // 0x80049AF0: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x80049AF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049AF8: beq         $s0, $at, L_80049B20
    if (ctx->r16 == ctx->r1) {
        // 0x80049AFC: nop

            goto L_80049B20;
    }
    // 0x80049AFC: nop

    // 0x80049B00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049B04: beq         $s0, $at, L_80049B48
    if (ctx->r16 == ctx->r1) {
        // 0x80049B08: nop

            goto L_80049B48;
    }
    // 0x80049B08: nop

    // 0x80049B0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049B10: beq         $s0, $at, L_80049B70
    if (ctx->r16 == ctx->r1) {
        // 0x80049B14: nop

            goto L_80049B70;
    }
    // 0x80049B14: nop

    // 0x80049B18: b           L_80049B98
    // 0x80049B1C: nop

        goto L_80049B98;
    // 0x80049B1C: nop

L_80049B20:
    // 0x80049B20: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80049B24: nop

    // 0x80049B28: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80049B2C: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80049B30: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80049B34: ori         $t3, $t1, 0x20
    ctx->r11 = ctx->r9 | 0X20;
    // 0x80049B38: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x80049B3C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80049B40: b           L_80049B98
    // 0x80049B44: nop

        goto L_80049B98;
    // 0x80049B44: nop

L_80049B48:
    // 0x80049B48: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80049B4C: nop

    // 0x80049B50: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80049B54: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80049B58: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x80049B5C: ori         $t7, $t9, 0x40
    ctx->r15 = ctx->r25 | 0X40;
    // 0x80049B60: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80049B64: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80049B68: b           L_80049B98
    // 0x80049B6C: nop

        goto L_80049B98;
    // 0x80049B6C: nop

L_80049B70:
    // 0x80049B70: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80049B74: nop

    // 0x80049B78: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80049B7C: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x80049B80: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80049B84: ori         $t3, $t1, 0x10
    ctx->r11 = ctx->r9 | 0X10;
    // 0x80049B88: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80049B8C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80049B90: b           L_80049B98
    // 0x80049B94: nop

        goto L_80049B98;
    // 0x80049B94: nop

L_80049B98:
    // 0x80049B98: lh          $t8, 0x4A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4A);
    // 0x80049B9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049BA0: bne         $t8, $at, L_80049F6C
    if (ctx->r24 != ctx->r1) {
        // 0x80049BA4: nop

            goto L_80049F6C;
    }
    // 0x80049BA4: nop

    // 0x80049BA8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80049BAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049BB0: sw          $t9, 0xE64($at)
    MEM_W(0XE64, ctx->r1) = ctx->r25;
    // 0x80049BB4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80049BB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049BBC: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x80049BC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049BC4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80049BC8: nop

    // 0x80049BCC: sw          $zero, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = 0;
    // 0x80049BD0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80049BD4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80049BD8: lh          $t4, 0x4A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X4A);
    // 0x80049BDC: nop

    // 0x80049BE0: sh          $t4, 0x7C($t0)
    MEM_H(0X7C, ctx->r8) = ctx->r12;
    // 0x80049BE4: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049BE8: nop

    // 0x80049BEC: beq         $t1, $zero, L_80049F64
    if (ctx->r9 == 0) {
        // 0x80049BF0: nop

            goto L_80049F64;
    }
    // 0x80049BF0: nop

    // 0x80049BF4: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049BF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049BFC: bne         $t2, $at, L_80049C10
    if (ctx->r10 != ctx->r1) {
        // 0x80049C00: nop

            goto L_80049C10;
    }
    // 0x80049C00: nop

    // 0x80049C04: lbu         $t3, 0x53($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X53);
    // 0x80049C08: b           L_80049C20
    // 0x80049C0C: sb          $t3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r11;
        goto L_80049C20;
    // 0x80049C0C: sb          $t3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r11;
L_80049C10:
    // 0x80049C10: lbu         $t5, 0x53($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X53);
    // 0x80049C14: nop

    // 0x80049C18: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x80049C1C: sb          $t8, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r24;
L_80049C20:
    // 0x80049C20: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049C24: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80049C28: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80049C2C: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80049C30: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80049C34: lw          $t7, -0x2864($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2864);
    // 0x80049C38: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80049C3C: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80049C40: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80049C44: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80049C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049C4C: jal         0x80060440
    // 0x80049C50: addu        $a0, $t4, $t1
    ctx->r4 = ADD32(ctx->r12, ctx->r9);
    func_80060440(rdram, ctx);
        goto after_1;
    // 0x80049C50: addu        $a0, $t4, $t1
    ctx->r4 = ADD32(ctx->r12, ctx->r9);
    after_1:
    // 0x80049C54: bne         $v0, $zero, L_80049C5C
    if (ctx->r2 != 0) {
        // 0x80049C58: nop

            goto L_80049C5C;
    }
    // 0x80049C58: nop

L_80049C5C:
    // 0x80049C5C: lbu         $s0, 0x4F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049C60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049C64: beq         $s0, $at, L_80049C80
    if (ctx->r16 == ctx->r1) {
        // 0x80049C68: nop

            goto L_80049C80;
    }
    // 0x80049C68: nop

    // 0x80049C6C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80049C70: beq         $s0, $at, L_80049DD0
    if (ctx->r16 == ctx->r1) {
        // 0x80049C74: nop

            goto L_80049DD0;
    }
    // 0x80049C74: nop

    // 0x80049C78: b           L_80049F64
    // 0x80049C7C: nop

        goto L_80049F64;
    // 0x80049C7C: nop

L_80049C80:
    // 0x80049C80: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80049C84: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80049C88: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80049C8C: lw          $t2, 0x306C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X306C);
    // 0x80049C90: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80049C94: blez        $t3, L_80049DA4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80049C98: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_80049DA4;
    }
    // 0x80049C98: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80049C9C: beq         $t2, $zero, L_80049DA4
    if (ctx->r10 == 0) {
        // 0x80049CA0: nop

            goto L_80049DA4;
    }
    // 0x80049CA0: nop

    // 0x80049CA4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80049CA8: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80049CAC: lh          $t5, 0x2($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X2);
    // 0x80049CB0: nop

    // 0x80049CB4: bne         $t5, $t8, L_80049DA4
    if (ctx->r13 != ctx->r24) {
        // 0x80049CB8: nop

            goto L_80049DA4;
    }
    // 0x80049CB8: nop

    // 0x80049CBC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80049CC0: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x80049CC4: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80049CC8: nop

    // 0x80049CCC: bne         $t9, $t6, L_80049DA4
    if (ctx->r25 != ctx->r14) {
        // 0x80049CD0: nop

            goto L_80049DA4;
    }
    // 0x80049CD0: nop

L_80049CD4:
    // 0x80049CD4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80049CD8: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x80049CDC: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80049CE0: slti        $t1, $t4, 0x2A
    ctx->r9 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x80049CE4: xori        $t1, $t1, 0x1
    ctx->r9 = ctx->r9 ^ 0X1;
    // 0x80049CE8: bne         $t0, $t1, L_80049D08
    if (ctx->r8 != ctx->r9) {
        // 0x80049CEC: nop

            goto L_80049D08;
    }
    // 0x80049CEC: nop

    // 0x80049CF0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80049CF4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80049CF8: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x80049CFC: lw          $s0, -0x28DC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X28DC);
    // 0x80049D00: b           L_80049D10
    // 0x80049D04: nop

        goto L_80049D10;
    // 0x80049D04: nop

L_80049D08:
    // 0x80049D08: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x80049D0C: nop

L_80049D10:
    // 0x80049D10: beq         $s0, $zero, L_80049D50
    if (ctx->r16 == 0) {
        // 0x80049D14: nop

            goto L_80049D50;
    }
    // 0x80049D14: nop

    // 0x80049D18: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80049D1C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80049D20: nop

    // 0x80049D24: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80049D28: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x80049D2C: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x80049D30: ori         $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 | 0X8000;
    // 0x80049D34: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80049D38: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80049D3C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049D40: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80049D44: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80049D48: nop

    // 0x80049D4C: sw          $t6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->r14;
L_80049D50:
    // 0x80049D50: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80049D54: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80049D58: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80049D5C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80049D60: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x80049D64: blez        $t1, L_80049DA4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80049D68: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_80049DA4;
    }
    // 0x80049D68: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80049D6C: beq         $t8, $zero, L_80049DA4
    if (ctx->r24 == 0) {
        // 0x80049D70: nop

            goto L_80049DA4;
    }
    // 0x80049D70: nop

    // 0x80049D74: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80049D78: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x80049D7C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80049D80: nop

    // 0x80049D84: bne         $t9, $t2, L_80049DA4
    if (ctx->r25 != ctx->r10) {
        // 0x80049D88: nop

            goto L_80049DA4;
    }
    // 0x80049D88: nop

    // 0x80049D8C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80049D90: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80049D94: lh          $t3, 0x4($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X4);
    // 0x80049D98: nop

    // 0x80049D9C: beq         $t3, $t5, L_80049CD4
    if (ctx->r11 == ctx->r13) {
        // 0x80049DA0: nop

            goto L_80049CD4;
    }
    // 0x80049DA0: nop

L_80049DA4:
    // 0x80049DA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80049DA8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80049DAC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80049DB0: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80049DB4: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80049DB8: bne         $t4, $zero, L_80049DC8
    if (ctx->r12 != 0) {
        // 0x80049DBC: andi        $t5, $t1, 0x8000
        ctx->r13 = ctx->r9 & 0X8000;
            goto L_80049DC8;
    }
    // 0x80049DBC: andi        $t5, $t1, 0x8000
    ctx->r13 = ctx->r9 & 0X8000;
    // 0x80049DC0: bne         $t5, $zero, L_80049DC8
    if (ctx->r13 != 0) {
        // 0x80049DC4: nop

            goto L_80049DC8;
    }
    // 0x80049DC4: nop

L_80049DC8:
    // 0x80049DC8: b           L_80049F64
    // 0x80049DCC: nop

        goto L_80049F64;
    // 0x80049DCC: nop

L_80049DD0:
    // 0x80049DD0: lbu         $a0, 0x53($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X53);
    // 0x80049DD4: jal         0x80056DF4
    // 0x80049DD8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80056DF4(rdram, ctx);
        goto after_2;
    // 0x80049DD8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_2:
    // 0x80049DDC: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80049DE0: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80049DE4: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80049DE8: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x80049DEC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80049DF0: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80049DF4: lh          $t2, 0x2C50($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2C50);
    // 0x80049DF8: nop

    // 0x80049DFC: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80049E00: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80049E04: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80049E08: nop

    // 0x80049E0C: lw          $t3, 0x144($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X144);
    // 0x80049E10: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80049E14: beq         $t3, $zero, L_80049F34
    if (ctx->r11 == 0) {
        // 0x80049E18: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80049F34;
    }
    // 0x80049E18: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80049E1C: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x80049E20: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049E24: bne         $t6, $at, L_80049E3C
    if (ctx->r14 != ctx->r1) {
        // 0x80049E28: nop

            goto L_80049E3C;
    }
    // 0x80049E28: nop

    // 0x80049E2C: lhu         $t0, 0x2($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X2);
    // 0x80049E30: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049E34: beq         $t0, $at, L_80049F34
    if (ctx->r8 == ctx->r1) {
        // 0x80049E38: nop

            goto L_80049F34;
    }
    // 0x80049E38: nop

L_80049E3C:
    // 0x80049E3C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80049E40: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80049E44: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x80049E48: nop

    // 0x80049E4C: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80049E50: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x80049E54: bne         $t7, $t9, L_80049EF8
    if (ctx->r15 != ctx->r25) {
        // 0x80049E58: nop

            goto L_80049EF8;
    }
    // 0x80049E58: nop

    // 0x80049E5C: sra         $t2, $t4, 8
    ctx->r10 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80049E60: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x80049E64: bne         $t8, $zero, L_80049EF8
    if (ctx->r24 != 0) {
        // 0x80049E68: nop

            goto L_80049EF8;
    }
    // 0x80049E68: nop

    // 0x80049E6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049E70: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80049E74: jal         0x8007959C
    // 0x80049E78: addiu       $a0, $a0, 0x11B0
    ctx->r4 = ADD32(ctx->r4, 0X11B0);
    func_8007959C(rdram, ctx);
        goto after_3;
    // 0x80049E78: addiu       $a0, $a0, 0x11B0
    ctx->r4 = ADD32(ctx->r4, 0X11B0);
    after_3:
    // 0x80049E7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80049E80: lw          $t6, 0x11C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11C8);
    // 0x80049E84: nop

    // 0x80049E88: beq         $t6, $zero, L_80049EA0
    if (ctx->r14 == 0) {
        // 0x80049E8C: nop

            goto L_80049EA0;
    }
    // 0x80049E8C: nop

    // 0x80049E90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049E94: lw          $a0, 0x11C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11C8);
    // 0x80049E98: jal         0x800BC980
    // 0x80049E9C: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x80049E9C: nop

    after_4:
L_80049EA0:
    // 0x80049EA0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80049EA4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80049EA8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80049EAC: addiu       $t3, $t3, 0x11B0
    ctx->r11 = ADD32(ctx->r11, 0X11B0);
    // 0x80049EB0: sw          $t3, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r11;
    // 0x80049EB4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80049EB8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80049EBC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80049EC0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80049EC4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x80049EC8: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80049ECC: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x80049ED0: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80049ED4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80049ED8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049EDC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80049EE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80049EE4: lw          $t9, 0x58($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X58);
    // 0x80049EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80049EEC: lbu         $a0, 0x16($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X16);
    // 0x80049EF0: jal         0x8008312C
    // 0x80049EF4: nop

    func_8008312C(rdram, ctx);
        goto after_5;
    // 0x80049EF4: nop

    after_5:
L_80049EF8:
    // 0x80049EF8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80049EFC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80049F00: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80049F04: addiu       $t4, $t0, 0x10
    ctx->r12 = ADD32(ctx->r8, 0X10);
    // 0x80049F08: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80049F0C: beq         $t4, $zero, L_80049F34
    if (ctx->r12 == 0) {
        // 0x80049F10: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80049F34;
    }
    // 0x80049F10: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80049F14: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80049F18: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049F1C: bne         $t5, $at, L_80049E3C
    if (ctx->r13 != ctx->r1) {
        // 0x80049F20: nop

            goto L_80049E3C;
    }
    // 0x80049F20: nop

    // 0x80049F24: lhu         $t2, 0x2($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X2);
    // 0x80049F28: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049F2C: bne         $t2, $at, L_80049E3C
    if (ctx->r10 != ctx->r1) {
        // 0x80049F30: nop

            goto L_80049E3C;
    }
    // 0x80049F30: nop

L_80049F34:
    // 0x80049F34: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80049F38: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80049F3C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80049F40: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80049F44: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80049F48: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80049F4C: bne         $t6, $zero, L_80049F5C
    if (ctx->r14 != 0) {
        // 0x80049F50: and         $t7, $t9, $at
        ctx->r15 = ctx->r25 & ctx->r1;
            goto L_80049F5C;
    }
    // 0x80049F50: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80049F54: bne         $t7, $zero, L_80049F5C
    if (ctx->r15 != 0) {
        // 0x80049F58: nop

            goto L_80049F5C;
    }
    // 0x80049F58: nop

L_80049F5C:
    // 0x80049F5C: b           L_80049F64
    // 0x80049F60: nop

        goto L_80049F64;
    // 0x80049F60: nop

L_80049F64:
    // 0x80049F64: b           L_8004A02C
    // 0x80049F68: nop

        goto L_8004A02C;
    // 0x80049F68: nop

L_80049F6C:
    // 0x80049F6C: lh          $t1, 0x4A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X4A);
    // 0x80049F70: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80049F74: nop

    // 0x80049F78: sh          $t1, 0x7C($t0)
    MEM_H(0X7C, ctx->r8) = ctx->r9;
    // 0x80049F7C: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049F80: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80049F84: nop

    // 0x80049F88: sw          $t5, 0x80($t4)
    MEM_W(0X80, ctx->r12) = ctx->r13;
    // 0x80049F8C: lbu         $t2, 0x53($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X53);
    // 0x80049F90: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80049F94: nop

    // 0x80049F98: sw          $t2, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->r10;
    // 0x80049F9C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80049FA0: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80049FA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049FA8: bne         $t8, $at, L_80049FDC
    if (ctx->r24 != ctx->r1) {
        // 0x80049FAC: nop

            goto L_80049FDC;
    }
    // 0x80049FAC: nop

    // 0x80049FB0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80049FB4: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x80049FB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049FBC: bne         $t9, $at, L_80049FDC
    if (ctx->r25 != ctx->r1) {
        // 0x80049FC0: nop

            goto L_80049FDC;
    }
    // 0x80049FC0: nop

    // 0x80049FC4: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80049FC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80049FCC: jal         0x800490C0
    // 0x80049FD0: addiu       $a0, $a0, 0x7AB8
    ctx->r4 = ADD32(ctx->r4, 0X7AB8);
    func_800490C0(rdram, ctx);
        goto after_6;
    // 0x80049FD0: addiu       $a0, $a0, 0x7AB8
    ctx->r4 = ADD32(ctx->r4, 0X7AB8);
    after_6:
    // 0x80049FD4: b           L_8004A02C
    // 0x80049FD8: nop

        goto L_8004A02C;
    // 0x80049FD8: nop

L_80049FDC:
    // 0x80049FDC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80049FE0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x80049FE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049FE8: bne         $t6, $at, L_8004A01C
    if (ctx->r14 != ctx->r1) {
        // 0x80049FEC: nop

            goto L_8004A01C;
    }
    // 0x80049FEC: nop

    // 0x80049FF0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80049FF4: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x80049FF8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80049FFC: bne         $t7, $at, L_8004A01C
    if (ctx->r15 != ctx->r1) {
        // 0x8004A000: nop

            goto L_8004A01C;
    }
    // 0x8004A000: nop

    // 0x8004A004: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8004A008: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004A00C: jal         0x800490C0
    // 0x8004A010: addiu       $a0, $a0, -0x5248
    ctx->r4 = ADD32(ctx->r4, -0X5248);
    func_800490C0(rdram, ctx);
        goto after_7;
    // 0x8004A010: addiu       $a0, $a0, -0x5248
    ctx->r4 = ADD32(ctx->r4, -0X5248);
    after_7:
    // 0x8004A014: b           L_8004A02C
    // 0x8004A018: nop

        goto L_8004A02C;
    // 0x8004A018: nop

L_8004A01C:
    // 0x8004A01C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8004A020: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004A024: jal         0x800490C0
    // 0x8004A028: addiu       $a0, $a0, -0x4890
    ctx->r4 = ADD32(ctx->r4, -0X4890);
    func_800490C0(rdram, ctx);
        goto after_8;
    // 0x8004A028: addiu       $a0, $a0, -0x4890
    ctx->r4 = ADD32(ctx->r4, -0X4890);
    after_8:
L_8004A02C:
    // 0x8004A02C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8004A030: b           L_8004A040
    // 0x8004A034: nop

        goto L_8004A040;
    // 0x8004A034: nop

    // 0x8004A038: b           L_8004A040
    // 0x8004A03C: nop

        goto L_8004A040;
    // 0x8004A03C: nop

L_8004A040:
    // 0x8004A040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A044: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004A048: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004A04C: jr          $ra
    // 0x8004A050: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8004A050: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
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
RECOMP_FUNC void func_8004A0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A0B4: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8004A0B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004A0BC: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x8004A0C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8004A0C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8004A0C8: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8004A0CC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8004A0D0: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x8004A0D4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8004A0D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A0DC: nop

    // 0x8004A0E0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8004A0E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004A0E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A0EC: nop

    // 0x8004A0F0: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8004A0F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004A0F8: nop

    // 0x8004A0FC: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8004A100: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x8004A104: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8004A108: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8004A10C: nop

    // 0x8004A110: sw          $t9, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r25;
    // 0x8004A114: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A118: nop

    // 0x8004A11C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8004A120: nop

    // 0x8004A124: sw          $t1, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r9;
    // 0x8004A128: lw          $t2, 0x12C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A12C: nop

    // 0x8004A130: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x8004A134: jal         0x80098754
    // 0x8004A138: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8004A138: nop

    after_0:
    // 0x8004A13C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8004A140: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8004A144: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8004A148: nop

    // 0x8004A14C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8004A150: beq         $t5, $zero, L_8004A180
    if (ctx->r13 == 0) {
        // 0x8004A154: nop

            goto L_8004A180;
    }
    // 0x8004A154: nop

L_8004A158:
    // 0x8004A158: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A15C: jal         0x800499B0
    // 0x8004A160: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8004A160: nop

    after_1:
    // 0x8004A164: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004A168: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004A16C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004A170: nop

    // 0x8004A174: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8004A178: bne         $t8, $zero, L_8004A158
    if (ctx->r24 != 0) {
        // 0x8004A17C: nop

            goto L_8004A158;
    }
    // 0x8004A17C: nop

L_8004A180:
    // 0x8004A180: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A184: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A188: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004A18C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004A190: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004A194: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004A198: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004A19C: bne         $t2, $zero, L_8004A1E4
    if (ctx->r10 != 0) {
        // 0x8004A1A0: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004A1E4;
    }
    // 0x8004A1A0: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A1A4: bne         $t3, $zero, L_8004A1E4
    if (ctx->r11 != 0) {
        // 0x8004A1A8: nop

            goto L_8004A1E4;
    }
    // 0x8004A1A8: nop

L_8004A1AC:
    // 0x8004A1AC: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A1B0: jal         0x800499B0
    // 0x8004A1B4: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8004A1B4: nop

    after_2:
    // 0x8004A1B8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A1BC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004A1C0: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004A1C4: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004A1C8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004A1CC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004A1D0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004A1D4: bne         $t8, $zero, L_8004A1E4
    if (ctx->r24 != 0) {
        // 0x8004A1D8: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004A1E4;
    }
    // 0x8004A1D8: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004A1DC: beq         $t9, $zero, L_8004A1AC
    if (ctx->r25 == 0) {
        // 0x8004A1E0: nop

            goto L_8004A1AC;
    }
    // 0x8004A1E0: nop

L_8004A1E4:
    // 0x8004A1E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A1E8: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A1EC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004A1F0: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x8004A1F4: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004A1F8: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8004A1FC: bne         $t2, $zero, L_8004A20C
    if (ctx->r10 != 0) {
        // 0x8004A200: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004A20C;
    }
    // 0x8004A200: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A204: beq         $t3, $zero, L_8004A214
    if (ctx->r11 == 0) {
        // 0x8004A208: nop

            goto L_8004A214;
    }
    // 0x8004A208: nop

L_8004A20C:
    // 0x8004A20C: b           L_8004AB04
    // 0x8004A210: nop

        goto L_8004AB04;
    // 0x8004A210: nop

L_8004A214:
    // 0x8004A214: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8004A218: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8004A21C: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x8004A220: nop

    // 0x8004A224: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x8004A228: beq         $t7, $zero, L_8004A258
    if (ctx->r15 == 0) {
        // 0x8004A22C: nop

            goto L_8004A258;
    }
    // 0x8004A22C: nop

L_8004A230:
    // 0x8004A230: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A234: jal         0x800499B0
    // 0x8004A238: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8004A238: nop

    after_3:
    // 0x8004A23C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8004A240: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8004A244: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8004A248: nop

    // 0x8004A24C: andi        $t5, $t9, 0x400
    ctx->r13 = ctx->r25 & 0X400;
    // 0x8004A250: bne         $t5, $zero, L_8004A230
    if (ctx->r13 != 0) {
        // 0x8004A254: nop

            goto L_8004A230;
    }
    // 0x8004A254: nop

L_8004A258:
    // 0x8004A258: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A25C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004A260: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004A264: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004A268: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8004A26C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004A270: bne         $t4, $zero, L_8004A280
    if (ctx->r12 != 0) {
        // 0x8004A274: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8004A280;
    }
    // 0x8004A274: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004A278: beq         $t5, $zero, L_8004A438
    if (ctx->r13 == 0) {
        // 0x8004A27C: nop

            goto L_8004A438;
    }
    // 0x8004A27C: nop

L_8004A280:
    // 0x8004A280: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004A284: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A288: sh          $t1, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r9;
    // 0x8004A28C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A290: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004A294: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8004A298: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x8004A29C: nop

    // 0x8004A2A0: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8004A2A4: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2A8: nop

            goto L_8004A3D4;
    }
    // 0x8004A2A8: nop

    // 0x8004A2AC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8004A2B0: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2B4: nop

            goto L_8004A3D4;
    }
    // 0x8004A2B4: nop

    // 0x8004A2B8: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8004A2BC: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2C0: nop

            goto L_8004A3D4;
    }
    // 0x8004A2C0: nop

    // 0x8004A2C4: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8004A2C8: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2CC: nop

            goto L_8004A3D4;
    }
    // 0x8004A2CC: nop

    // 0x8004A2D0: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x8004A2D4: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2D8: nop

            goto L_8004A3D4;
    }
    // 0x8004A2D8: nop

    // 0x8004A2DC: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8004A2E0: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2E4: nop

            goto L_8004A3D4;
    }
    // 0x8004A2E4: nop

    // 0x8004A2E8: addiu       $at, $zero, 0x73
    ctx->r1 = ADD32(0, 0X73);
    // 0x8004A2EC: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2F0: nop

            goto L_8004A3D4;
    }
    // 0x8004A2F0: nop

    // 0x8004A2F4: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8004A2F8: beq         $t8, $at, L_8004A3D4
    if (ctx->r24 == ctx->r1) {
        // 0x8004A2FC: nop

            goto L_8004A3D4;
    }
    // 0x8004A2FC: nop

    // 0x8004A300: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A304: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A308: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8004A30C: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x8004A310: nop

    // 0x8004A314: andi        $t2, $t0, 0x1FFF
    ctx->r10 = ctx->r8 & 0X1FFF;
    // 0x8004A318: beq         $t2, $at, L_8004A32C
    if (ctx->r10 == ctx->r1) {
        // 0x8004A31C: nop

            goto L_8004A32C;
    }
    // 0x8004A31C: nop

    // 0x8004A320: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8004A324: bne         $t2, $at, L_8004A380
    if (ctx->r10 != ctx->r1) {
        // 0x8004A328: nop

            goto L_8004A380;
    }
    // 0x8004A328: nop

L_8004A32C:
    // 0x8004A32C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004A330: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004A334: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A338: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004A33C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004A340: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8004A344: lui         $at, 0xFFBF
    ctx->r1 = S32(0XFFBF << 16);
    // 0x8004A348: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004A34C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004A350: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004A354: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004A358: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004A35C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004A360: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004A364: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8004A368: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x8004A36C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8004A370: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8004A374: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8004A378: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8004A37C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_8004A380:
    // 0x8004A380: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A384: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004A388: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004A38C: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004A390: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004A394: bne         $t8, $zero, L_8004A3D4
    if (ctx->r24 != 0) {
        // 0x8004A398: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_8004A3D4;
    }
    // 0x8004A398: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8004A39C: bne         $t9, $zero, L_8004A3D4
    if (ctx->r25 != 0) {
        // 0x8004A3A0: nop

            goto L_8004A3D4;
    }
    // 0x8004A3A0: nop

L_8004A3A4:
    // 0x8004A3A4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A3A8: jal         0x800499B0
    // 0x8004A3AC: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x8004A3AC: nop

    after_4:
    // 0x8004A3B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A3B4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A3B8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004A3BC: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x8004A3C0: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8004A3C4: bne         $t2, $zero, L_8004A3D4
    if (ctx->r10 != 0) {
        // 0x8004A3C8: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_8004A3D4;
    }
    // 0x8004A3C8: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x8004A3CC: beq         $t3, $zero, L_8004A3A4
    if (ctx->r11 == 0) {
        // 0x8004A3D0: nop

            goto L_8004A3A4;
    }
    // 0x8004A3D0: nop

L_8004A3D4:
    // 0x8004A3D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A3D8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004A3DC: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8004A3E0: sw          $t4, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r12;
    // 0x8004A3E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A3E8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004A3EC: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A3F0: lh          $a1, 0x4A($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X4A);
    // 0x8004A3F4: nop

    // 0x8004A3F8: andi        $t8, $a1, 0x1FFF
    ctx->r24 = ctx->r5 & 0X1FFF;
    // 0x8004A3FC: jal         0x8005218C
    // 0x8004A400: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8005218C(rdram, ctx);
        goto after_5;
    // 0x8004A400: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_5:
    // 0x8004A404: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A408: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A40C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A410: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004A414: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004A418: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8004A41C: lui         $at, 0xFFBF
    ctx->r1 = S32(0XFFBF << 16);
    // 0x8004A420: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004A424: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A428: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8004A42C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8004A430: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A434: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_8004A438:
    // 0x8004A438: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A43C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A440: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004A444: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8004A448: lw          $t5, 0x4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4);
    // 0x8004A44C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004A450: bne         $t6, $zero, L_8004A460
    if (ctx->r14 != 0) {
        // 0x8004A454: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_8004A460;
    }
    // 0x8004A454: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004A458: beq         $t7, $zero, L_8004A4BC
    if (ctx->r15 == 0) {
        // 0x8004A45C: nop

            goto L_8004A4BC;
    }
    // 0x8004A45C: nop

L_8004A460:
    // 0x8004A460: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A464: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004A468: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A46C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004A470: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004A474: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8004A478: lui         $at, 0xFDFF
    ctx->r1 = S32(0XFDFF << 16);
    // 0x8004A47C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004A480: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004A484: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8004A488: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8004A48C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A490: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x8004A494: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004A498: beq         $t9, $at, L_8004A4BC
    if (ctx->r25 == ctx->r1) {
        // 0x8004A49C: nop

            goto L_8004A4BC;
    }
    // 0x8004A49C: nop

    // 0x8004A4A0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A4A4: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8004A4A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A4AC: beq         $t4, $at, L_8004A4BC
    if (ctx->r12 == ctx->r1) {
        // 0x8004A4B0: nop

            goto L_8004A4BC;
    }
    // 0x8004A4B0: nop

    // 0x8004A4B4: b           L_8004A55C
    // 0x8004A4B8: nop

        goto L_8004A55C;
    // 0x8004A4B8: nop

L_8004A4BC:
    // 0x8004A4BC: jal         0x8005A768
    // 0x8004A4C0: nop

    func_8005A768(rdram, ctx);
        goto after_6;
    // 0x8004A4C0: nop

    after_6:
    // 0x8004A4C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A4C8: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
    // 0x8004A4CC: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8004A4D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A4D4: sh          $t5, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r13;
    // 0x8004A4D8: jal         0x80057960
    // 0x8004A4DC: nop

    func_80057960(rdram, ctx);
        goto after_7;
    // 0x8004A4DC: nop

    after_7:
    // 0x8004A4E0: sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    // 0x8004A4E4: lw          $t6, 0x120($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X120);
    // 0x8004A4E8: nop

    // 0x8004A4EC: beq         $t6, $zero, L_8004A4FC
    if (ctx->r14 == 0) {
        // 0x8004A4F0: nop

            goto L_8004A4FC;
    }
    // 0x8004A4F0: nop

    // 0x8004A4F4: b           L_8004AB04
    // 0x8004A4F8: nop

        goto L_8004AB04;
    // 0x8004A4F8: nop

L_8004A4FC:
    // 0x8004A4FC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004A500: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x8004A504: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004A508: bne         $t7, $at, L_8004A52C
    if (ctx->r15 != ctx->r1) {
        // 0x8004A50C: nop

            goto L_8004A52C;
    }
    // 0x8004A50C: nop

    // 0x8004A510: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004A514: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004A518: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004A51C: bne         $t0, $at, L_8004A52C
    if (ctx->r8 != ctx->r1) {
        // 0x8004A520: nop

            goto L_8004A52C;
    }
    // 0x8004A520: nop

    // 0x8004A524: b           L_8004AB04
    // 0x8004A528: nop

        goto L_8004AB04;
    // 0x8004A528: nop

L_8004A52C:
    // 0x8004A52C: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A530: jal         0x80050AC4
    // 0x8004A534: nop

    func_80050AC4(rdram, ctx);
        goto after_8;
    // 0x8004A534: nop

    after_8:
    // 0x8004A538: jal         0x80057960
    // 0x8004A53C: nop

    func_80057960(rdram, ctx);
        goto after_9;
    // 0x8004A53C: nop

    after_9:
    // 0x8004A540: sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    // 0x8004A544: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x8004A548: nop

    // 0x8004A54C: beq         $t1, $zero, L_8004A55C
    if (ctx->r9 == 0) {
        // 0x8004A550: nop

            goto L_8004A55C;
    }
    // 0x8004A550: nop

    // 0x8004A554: b           L_8004AB04
    // 0x8004A558: nop

        goto L_8004AB04;
    // 0x8004A558: nop

L_8004A55C:
    // 0x8004A55C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A560: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004A564: nop

    // 0x8004A568: sw          $zero, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = 0;
    // 0x8004A56C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004A570: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004A574: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004A578: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8004A57C: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x8004A580: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004A584: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8004A588: bne         $t4, $zero, L_8004A598
    if (ctx->r12 != 0) {
        // 0x8004A58C: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004A598;
    }
    // 0x8004A58C: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004A590: beq         $t5, $zero, L_8004A5B4
    if (ctx->r13 == 0) {
        // 0x8004A594: nop

            goto L_8004A5B4;
    }
    // 0x8004A594: nop

L_8004A598:
    // 0x8004A598: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A59C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x8004A5A0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8004A5A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A5A8: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x8004A5AC: b           L_8004AAA8
    // 0x8004A5B0: nop

        goto L_8004AAA8;
    // 0x8004A5B0: nop

L_8004A5B4:
    // 0x8004A5B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A5B8: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x8004A5BC: nop

    // 0x8004A5C0: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x8004A5C4: beq         $at, $zero, L_8004A688
    if (ctx->r1 == 0) {
        // 0x8004A5C8: nop

            goto L_8004A688;
    }
    // 0x8004A5C8: nop

    // 0x8004A5CC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A5D0: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x8004A5D4: nop

    // 0x8004A5D8: beq         $t0, $zero, L_8004A644
    if (ctx->r8 == 0) {
        // 0x8004A5DC: nop

            goto L_8004A644;
    }
    // 0x8004A5DC: nop

L_8004A5E0:
    // 0x8004A5E0: jal         0x8005151C
    // 0x8004A5E4: nop

    func_8005151C(rdram, ctx);
        goto after_10;
    // 0x8004A5E4: nop

    after_10:
    // 0x8004A5E8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004A5EC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004A5F0: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004A5F4: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8004A5F8: lh          $t2, 0x4A($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4A);
    // 0x8004A5FC: nop

    // 0x8004A600: beq         $t2, $t3, L_8004A624
    if (ctx->r10 == ctx->r11) {
        // 0x8004A604: nop

            goto L_8004A624;
    }
    // 0x8004A604: nop

    // 0x8004A608: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A60C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004A610: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8004A614: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A618: lh          $a1, 0x42($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X42);
    // 0x8004A61C: jal         0x8004EF90
    // 0x8004A620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_11;
    // 0x8004A620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
L_8004A624:
    // 0x8004A624: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A628: jal         0x800499B0
    // 0x8004A62C: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x8004A62C: nop

    after_12:
    // 0x8004A630: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A634: lh          $t9, 0x6C0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X6C0);
    // 0x8004A638: nop

    // 0x8004A63C: bne         $t9, $zero, L_8004A5E0
    if (ctx->r25 != 0) {
        // 0x8004A640: nop

            goto L_8004A5E0;
    }
    // 0x8004A640: nop

L_8004A644:
    // 0x8004A644: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A648: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A64C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004A650: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x8004A654: nop

    // 0x8004A658: sb          $t4, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r12;
    // 0x8004A65C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A660: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004A664: nop

    // 0x8004A668: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8004A66C: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x8004A670: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8004A674: ori         $t3, $t1, 0x4000
    ctx->r11 = ctx->r9 | 0X4000;
    // 0x8004A678: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8004A67C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8004A680: b           L_8004A598
    // 0x8004A684: nop

        goto L_8004A598;
    // 0x8004A684: nop

L_8004A688:
    // 0x8004A688: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A68C: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x8004A690: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004A694: beq         $t7, $at, L_8004A958
    if (ctx->r15 == ctx->r1) {
        // 0x8004A698: nop

            goto L_8004A958;
    }
    // 0x8004A698: nop

    // 0x8004A69C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A6A0: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004A6A4: nop

    // 0x8004A6A8: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x8004A6AC: nop

    // 0x8004A6B0: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x8004A6B4: bne         $at, $zero, L_8004A720
    if (ctx->r1 != 0) {
        // 0x8004A6B8: nop

            goto L_8004A720;
    }
    // 0x8004A6B8: nop

    // 0x8004A6BC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A6C0: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004A6C4: nop

    // 0x8004A6C8: lh          $t5, 0x2E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2E);
    // 0x8004A6CC: nop

    // 0x8004A6D0: slti        $at, $t5, 0x384
    ctx->r1 = SIGNED(ctx->r13) < 0X384 ? 1 : 0;
    // 0x8004A6D4: beq         $at, $zero, L_8004A6F4
    if (ctx->r1 == 0) {
        // 0x8004A6D8: nop

            goto L_8004A6F4;
    }
    // 0x8004A6D8: nop

    // 0x8004A6DC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A6E0: lw          $t0, 0x670($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X670);
    // 0x8004A6E4: nop

    // 0x8004A6E8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8004A6EC: beq         $t1, $zero, L_8004A720
    if (ctx->r9 == 0) {
        // 0x8004A6F0: nop

            goto L_8004A720;
    }
    // 0x8004A6F0: nop

L_8004A6F4:
    // 0x8004A6F4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A6F8: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004A6FC: nop

    // 0x8004A700: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8004A704: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8004A708: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004A70C: ori         $t9, $t7, 0x2000
    ctx->r25 = ctx->r15 | 0X2000;
    // 0x8004A710: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8004A714: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8004A718: b           L_8004A598
    // 0x8004A71C: nop

        goto L_8004A598;
    // 0x8004A71C: nop

L_8004A720:
    // 0x8004A720: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004A724: lh          $a0, 0x10F0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X10F0);
    // 0x8004A728: jal         0x8005A2CC
    // 0x8004A72C: nop

    func_8005A2CC(rdram, ctx);
        goto after_13;
    // 0x8004A72C: nop

    after_13:
    // 0x8004A730: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004A734: lh          $t3, 0x10F0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X10F0);
    // 0x8004A738: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004A73C: bne         $t3, $at, L_8004A800
    if (ctx->r11 != ctx->r1) {
        // 0x8004A740: nop

            goto L_8004A800;
    }
    // 0x8004A740: nop

    // 0x8004A744: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004A748: jal         0x800527C4
    // 0x8004A74C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800527C4(rdram, ctx);
        goto after_14;
    // 0x8004A74C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8004A750: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A754: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8004A758: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A75C: bne         $t4, $at, L_8004A76C
    if (ctx->r12 != ctx->r1) {
        // 0x8004A760: nop

            goto L_8004A76C;
    }
    // 0x8004A760: nop

    // 0x8004A764: b           L_8004A438
    // 0x8004A768: nop

        goto L_8004A438;
    // 0x8004A768: nop

L_8004A76C:
    // 0x8004A76C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004A770: lh          $t5, 0x10F0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X10F0);
    // 0x8004A774: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004A778: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A77C: nop

            goto L_8004A7E0;
    }
    // 0x8004A77C: nop

    // 0x8004A780: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004A784: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A788: nop

            goto L_8004A7E0;
    }
    // 0x8004A788: nop

    // 0x8004A78C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A790: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A794: nop

            goto L_8004A7E0;
    }
    // 0x8004A794: nop

    // 0x8004A798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A79C: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A7A0: nop

            goto L_8004A7E0;
    }
    // 0x8004A7A0: nop

    // 0x8004A7A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A7A8: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A7AC: nop

            goto L_8004A7E0;
    }
    // 0x8004A7AC: nop

    // 0x8004A7B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004A7B4: beq         $t5, $at, L_8004A7E0
    if (ctx->r13 == ctx->r1) {
        // 0x8004A7B8: nop

            goto L_8004A7E0;
    }
    // 0x8004A7B8: nop

    // 0x8004A7BC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A7C0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004A7C4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004A7C8: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8004A7CC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004A7D0: bne         $t8, $zero, L_8004A7E0
    if (ctx->r24 != 0) {
        // 0x8004A7D4: andi        $t9, $t7, 0x1000
        ctx->r25 = ctx->r15 & 0X1000;
            goto L_8004A7E0;
    }
    // 0x8004A7D4: andi        $t9, $t7, 0x1000
    ctx->r25 = ctx->r15 & 0X1000;
    // 0x8004A7D8: beq         $t9, $zero, L_8004A7F8
    if (ctx->r25 == 0) {
        // 0x8004A7DC: nop

            goto L_8004A7F8;
    }
    // 0x8004A7DC: nop

L_8004A7E0:
    // 0x8004A7E0: jal         0x80061F08
    // 0x8004A7E4: nop

    func_80061F08(rdram, ctx);
        goto after_15;
    // 0x8004A7E4: nop

    after_15:
    // 0x8004A7E8: bne         $v0, $zero, L_8004A7F8
    if (ctx->r2 != 0) {
        // 0x8004A7EC: nop

            goto L_8004A7F8;
    }
    // 0x8004A7EC: nop

    // 0x8004A7F0: b           L_8004A55C
    // 0x8004A7F4: nop

        goto L_8004A55C;
    // 0x8004A7F4: nop

L_8004A7F8:
    // 0x8004A7F8: b           L_8004A950
    // 0x8004A7FC: nop

        goto L_8004A950;
    // 0x8004A7FC: nop

L_8004A800:
    // 0x8004A800: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004A804: lh          $t1, 0x10F0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X10F0);
    // 0x8004A808: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004A80C: bne         $t1, $at, L_8004A8C4
    if (ctx->r9 != ctx->r1) {
        // 0x8004A810: nop

            goto L_8004A8C4;
    }
    // 0x8004A810: nop

    // 0x8004A814: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A818: lw          $t2, 0x11A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11A0);
    // 0x8004A81C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8004A820: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x8004A824: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8004A828: nop

    // 0x8004A82C: bne         $t3, $t4, L_8004A8B4
    if (ctx->r11 != ctx->r12) {
        // 0x8004A830: nop

            goto L_8004A8B4;
    }
    // 0x8004A830: nop

    // 0x8004A834: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004A838: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004A83C: lh          $t5, 0x4($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X4);
    // 0x8004A840: nop

    // 0x8004A844: bne         $t5, $t0, L_8004A8B4
    if (ctx->r13 != ctx->r8) {
        // 0x8004A848: nop

            goto L_8004A8B4;
    }
    // 0x8004A848: nop

    // 0x8004A84C: lh          $t6, 0x6($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X6);
    // 0x8004A850: nop

    // 0x8004A854: bne         $t6, $zero, L_8004A8B4
    if (ctx->r14 != 0) {
        // 0x8004A858: nop

            goto L_8004A8B4;
    }
    // 0x8004A858: nop

    // 0x8004A85C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A860: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A864: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004A868: lw          $t7, 0x11A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11A0);
    // 0x8004A86C: nop

    // 0x8004A870: sw          $t7, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->r15;
    // 0x8004A874: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A878: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A87C: nop

    // 0x8004A880: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8004A884: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8004A888: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8004A88C: ori         $t1, $t5, 0x8000
    ctx->r9 = ctx->r13 | 0X8000;
    // 0x8004A890: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004A894: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004A898: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8004A89C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A8A0: sh          $t3, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r11;
    // 0x8004A8A4: b           L_8004AAA8
    // 0x8004A8A8: nop

        goto L_8004AAA8;
    // 0x8004A8A8: nop

    // 0x8004A8AC: b           L_8004A8BC
    // 0x8004A8B0: nop

        goto L_8004A8BC;
    // 0x8004A8B0: nop

L_8004A8B4:
    // 0x8004A8B4: b           L_8004A438
    // 0x8004A8B8: nop

        goto L_8004A438;
    // 0x8004A8B8: nop

L_8004A8BC:
    // 0x8004A8BC: b           L_8004A950
    // 0x8004A8C0: nop

        goto L_8004A950;
    // 0x8004A8C0: nop

L_8004A8C4:
    // 0x8004A8C4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004A8C8: lh          $t2, 0x10F0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X10F0);
    // 0x8004A8CC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004A8D0: bne         $t2, $at, L_8004A950
    if (ctx->r10 != ctx->r1) {
        // 0x8004A8D4: nop

            goto L_8004A950;
    }
    // 0x8004A8D4: nop

    // 0x8004A8D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A8DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A8E0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004A8E4: lw          $t6, 0x11A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11A8);
    // 0x8004A8E8: nop

    // 0x8004A8EC: sw          $t6, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->r14;
    // 0x8004A8F0: jal         0x80059ED0
    // 0x8004A8F4: nop

    func_80059ED0(rdram, ctx);
        goto after_16;
    // 0x8004A8F4: nop

    after_16:
    // 0x8004A8F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A8FC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004A900: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004A904: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8004A908: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8004A90C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8004A910: or          $t1, $t5, $at
    ctx->r9 = ctx->r13 | ctx->r1;
    // 0x8004A914: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8004A918: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8004A91C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A920: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004A924: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8004A928: lw          $t3, 0x58($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X58);
    // 0x8004A92C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004A930: lbu         $a0, 0x16($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X16);
    // 0x8004A934: jal         0x8008312C
    // 0x8004A938: nop

    func_8008312C(rdram, ctx);
        goto after_17;
    // 0x8004A938: nop

    after_17:
    // 0x8004A93C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8004A940: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A944: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x8004A948: b           L_8004AAA8
    // 0x8004A94C: nop

        goto L_8004AAA8;
    // 0x8004A94C: nop

L_8004A950:
    // 0x8004A950: b           L_8004AA94
    // 0x8004A954: nop

        goto L_8004AA94;
    // 0x8004A954: nop

L_8004A958:
    // 0x8004A958: jal         0x80056118
    // 0x8004A95C: nop

    func_80056118(rdram, ctx);
        goto after_18;
    // 0x8004A95C: nop

    after_18:
    // 0x8004A960: bne         $v0, $zero, L_8004AA94
    if (ctx->r2 != 0) {
        // 0x8004A964: nop

            goto L_8004AA94;
    }
    // 0x8004A964: nop

    // 0x8004A968: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8004A96C: lw          $s0, 0x678($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X678);
    // 0x8004A970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A974: bgez        $s0, L_8004A988
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8004A978: andi        $t6, $s0, 0x7
        ctx->r14 = ctx->r16 & 0X7;
            goto L_8004A988;
    }
    // 0x8004A978: andi        $t6, $s0, 0x7
    ctx->r14 = ctx->r16 & 0X7;
    // 0x8004A97C: beq         $t6, $zero, L_8004A988
    if (ctx->r14 == 0) {
        // 0x8004A980: nop

            goto L_8004A988;
    }
    // 0x8004A980: nop

    // 0x8004A984: addiu       $t6, $t6, -0x8
    ctx->r14 = ADD32(ctx->r14, -0X8);
L_8004A988:
    // 0x8004A988: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8004A98C: beq         $s0, $at, L_8004A9B4
    if (ctx->r16 == ctx->r1) {
        // 0x8004A990: nop

            goto L_8004A9B4;
    }
    // 0x8004A990: nop

    // 0x8004A994: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A998: beq         $s0, $at, L_8004A9B4
    if (ctx->r16 == ctx->r1) {
        // 0x8004A99C: nop

            goto L_8004A9B4;
    }
    // 0x8004A99C: nop

    // 0x8004A9A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A9A4: beq         $s0, $at, L_8004AA08
    if (ctx->r16 == ctx->r1) {
        // 0x8004A9A8: nop

            goto L_8004AA08;
    }
    // 0x8004A9A8: nop

    // 0x8004A9AC: b           L_8004AA94
    // 0x8004A9B0: nop

        goto L_8004AA94;
    // 0x8004A9B0: nop

L_8004A9B4:
    // 0x8004A9B4: jal         0x80057538
    // 0x8004A9B8: nop

    func_80057538(rdram, ctx);
        goto after_19;
    // 0x8004A9B8: nop

    after_19:
    // 0x8004A9BC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A9C0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004A9C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8004A9C8: beq         $s1, $zero, L_8004AA00
    if (ctx->r17 == 0) {
        // 0x8004A9CC: sw          $s1, 0x5C($t7)
        MEM_W(0X5C, ctx->r15) = ctx->r17;
            goto L_8004AA00;
    }
    // 0x8004A9CC: sw          $s1, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->r17;
    // 0x8004A9D0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A9D4: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004A9D8: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004A9DC: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004A9E0: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x8004A9E4: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x8004A9E8: ori         $t8, $t0, 0x2
    ctx->r24 = ctx->r8 | 0X2;
    // 0x8004A9EC: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x8004A9F0: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004A9F4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8004A9F8: b           L_8004A598
    // 0x8004A9FC: nop

        goto L_8004A598;
    // 0x8004A9FC: nop

L_8004AA00:
    // 0x8004AA00: b           L_8004AA94
    // 0x8004AA04: nop

        goto L_8004AA94;
    // 0x8004AA04: nop

L_8004AA08:
    // 0x8004AA08: jal         0x80061E14
    // 0x8004AA0C: nop

    func_80061E14(rdram, ctx);
        goto after_20;
    // 0x8004AA0C: nop

    after_20:
    // 0x8004AA10: beq         $v0, $zero, L_8004AA20
    if (ctx->r2 == 0) {
        // 0x8004AA14: nop

            goto L_8004AA20;
    }
    // 0x8004AA14: nop

    // 0x8004AA18: b           L_8004A598
    // 0x8004AA1C: nop

        goto L_8004A598;
    // 0x8004AA1C: nop

L_8004AA20:
    // 0x8004AA20: jal         0x80057714
    // 0x8004AA24: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_80057714(rdram, ctx);
        goto after_21;
    // 0x8004AA24: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_21:
    // 0x8004AA28: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004AA2C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004AA30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004AA34: beq         $s0, $zero, L_8004AA8C
    if (ctx->r16 == 0) {
        // 0x8004AA38: sw          $s0, 0x58($t5)
        MEM_W(0X58, ctx->r13) = ctx->r16;
            goto L_8004AA8C;
    }
    // 0x8004AA38: sw          $s0, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r16;
    // 0x8004AA3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AA40: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004AA44: lui         $at, 0x201
    ctx->r1 = S32(0X201 << 16);
    // 0x8004AA48: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x8004AA4C: or          $t6, $t3, $zero
    ctx->r14 = ctx->r11 | 0;
    // 0x8004AA50: lw          $t3, 0x4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4);
    // 0x8004AA54: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x8004AA58: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8004AA5C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8004AA60: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8004AA64: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004AA68: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004AA6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8004AA70: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x8004AA74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004AA78: lbu         $a0, 0x16($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X16);
    // 0x8004AA7C: jal         0x8008312C
    // 0x8004AA80: nop

    func_8008312C(rdram, ctx);
        goto after_22;
    // 0x8004AA80: nop

    after_22:
    // 0x8004AA84: b           L_8004A598
    // 0x8004AA88: nop

        goto L_8004A598;
    // 0x8004AA88: nop

L_8004AA8C:
    // 0x8004AA8C: b           L_8004AA94
    // 0x8004AA90: nop

        goto L_8004AA94;
    // 0x8004AA90: nop

L_8004AA94:
    // 0x8004AA94: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004AA98: lh          $t9, 0x10F0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X10F0);
    // 0x8004AA9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004AAA0: bne         $t9, $at, L_8004A438
    if (ctx->r25 != ctx->r1) {
        // 0x8004AAA4: nop

            goto L_8004A438;
    }
    // 0x8004AAA4: nop

L_8004AAA8:
    // 0x8004AAA8: jal         0x80031AC8
    // 0x8004AAAC: nop

    func_80031AC8(rdram, ctx);
        goto after_23;
    // 0x8004AAAC: nop

    after_23:
    // 0x8004AAB0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AAB4: bne         $v0, $at, L_8004AAD0
    if (ctx->r2 != ctx->r1) {
        // 0x8004AAB8: nop

            goto L_8004AAD0;
    }
    // 0x8004AAB8: nop

    // 0x8004AABC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004AAC0: lh          $t4, 0x6C0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C0);
    // 0x8004AAC4: nop

    // 0x8004AAC8: beq         $t4, $zero, L_8004AB04
    if (ctx->r12 == 0) {
        // 0x8004AACC: nop

            goto L_8004AB04;
    }
    // 0x8004AACC: nop

L_8004AAD0:
    // 0x8004AAD0: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004AAD4: jal         0x800499B0
    // 0x8004AAD8: nop

    func_800499B0(rdram, ctx);
        goto after_24;
    // 0x8004AAD8: nop

    after_24:
    // 0x8004AADC: jal         0x80031AC8
    // 0x8004AAE0: nop

    func_80031AC8(rdram, ctx);
        goto after_25;
    // 0x8004AAE0: nop

    after_25:
    // 0x8004AAE4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AAE8: bne         $v0, $at, L_8004AAD0
    if (ctx->r2 != ctx->r1) {
        // 0x8004AAEC: nop

            goto L_8004AAD0;
    }
    // 0x8004AAEC: nop

    // 0x8004AAF0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004AAF4: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x8004AAF8: nop

    // 0x8004AAFC: bne         $t5, $zero, L_8004AAD0
    if (ctx->r13 != 0) {
        // 0x8004AB00: nop

            goto L_8004AAD0;
    }
    // 0x8004AB00: nop

L_8004AB04:
    // 0x8004AB04: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
L_8004AB08:
    // 0x8004AB08: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8004AB0C: jal         0x8005F268
    // 0x8004AB10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_8005F268(rdram, ctx);
        goto after_26;
    // 0x8004AB10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_26:
    // 0x8004AB14: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8004AB18: nop

    // 0x8004AB1C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8004AB20: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8004AB24: bne         $at, $zero, L_8004AB08
    if (ctx->r1 != 0) {
        // 0x8004AB28: sw          $t3, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r11;
            goto L_8004AB08;
    }
    // 0x8004AB28: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
L_8004AB2C:
    // 0x8004AB2C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004AB30: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004AB34: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004AB38: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8004AB3C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004AB40: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004AB44: bne         $t8, $zero, L_8004AB7C
    if (ctx->r24 != 0) {
        // 0x8004AB48: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004AB7C;
    }
    // 0x8004AB48: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004AB4C: bne         $t9, $zero, L_8004AB7C
    if (ctx->r25 != 0) {
        // 0x8004AB50: nop

            goto L_8004AB7C;
    }
    // 0x8004AB50: nop

    // 0x8004AB54: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    // 0x8004AB58: addiu       $a1, $sp, 0x11C
    ctx->r5 = ADD32(ctx->r29, 0X11C);
    // 0x8004AB5C: jal         0x80054690
    // 0x8004AB60: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_80054690(rdram, ctx);
        goto after_27;
    // 0x8004AB60: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_27:
    // 0x8004AB64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004AB68: lw          $a0, 0x120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X120);
    // 0x8004AB6C: jal         0x80060440
    // 0x8004AB70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80060440(rdram, ctx);
        goto after_28;
    // 0x8004AB70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_28:
    // 0x8004AB74: bne         $v0, $zero, L_8004AB7C
    if (ctx->r2 != 0) {
        // 0x8004AB78: nop

            goto L_8004AB7C;
    }
    // 0x8004AB78: nop

L_8004AB7C:
    // 0x8004AB7C: jal         0x80031AC8
    // 0x8004AB80: nop

    func_80031AC8(rdram, ctx);
        goto after_29;
    // 0x8004AB80: nop

    after_29:
    // 0x8004AB84: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004AB88: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8004AB8C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AB90: beq         $t1, $at, L_8004ABD0
    if (ctx->r9 == ctx->r1) {
        // 0x8004AB94: nop

            goto L_8004ABD0;
    }
    // 0x8004AB94: nop

    // 0x8004AB98: beq         $t1, $zero, L_8004ABD0
    if (ctx->r9 == 0) {
        // 0x8004AB9C: nop

            goto L_8004ABD0;
    }
    // 0x8004AB9C: nop

L_8004ABA0:
    // 0x8004ABA0: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ABA4: jal         0x800499B0
    // 0x8004ABA8: nop

    func_800499B0(rdram, ctx);
        goto after_30;
    // 0x8004ABA8: nop

    after_30:
    // 0x8004ABAC: jal         0x80031AC8
    // 0x8004ABB0: nop

    func_80031AC8(rdram, ctx);
        goto after_31;
    // 0x8004ABB0: nop

    after_31:
    // 0x8004ABB4: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004ABB8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8004ABBC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004ABC0: beq         $t4, $at, L_8004ABD0
    if (ctx->r12 == ctx->r1) {
        // 0x8004ABC4: nop

            goto L_8004ABD0;
    }
    // 0x8004ABC4: nop

    // 0x8004ABC8: bne         $t4, $zero, L_8004ABA0
    if (ctx->r12 != 0) {
        // 0x8004ABCC: nop

            goto L_8004ABA0;
    }
    // 0x8004ABCC: nop

L_8004ABD0:
    // 0x8004ABD0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004ABD4: lh          $t5, 0x6C0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C0);
    // 0x8004ABD8: nop

    // 0x8004ABDC: beq         $t5, $zero, L_8004AC04
    if (ctx->r13 == 0) {
        // 0x8004ABE0: nop

            goto L_8004AC04;
    }
    // 0x8004ABE0: nop

L_8004ABE4:
    // 0x8004ABE4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ABE8: jal         0x800499B0
    // 0x8004ABEC: nop

    func_800499B0(rdram, ctx);
        goto after_32;
    // 0x8004ABEC: nop

    after_32:
    // 0x8004ABF0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004ABF4: lh          $t2, 0x6C0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6C0);
    // 0x8004ABF8: nop

    // 0x8004ABFC: bne         $t2, $zero, L_8004ABE4
    if (ctx->r10 != 0) {
        // 0x8004AC00: nop

            goto L_8004ABE4;
    }
    // 0x8004AC00: nop

L_8004AC04:
    // 0x8004AC04: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AC08: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004AC0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AC10: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004AC14: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004AC18: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x8004AC1C: lui         $at, 0xFBFB
    ctx->r1 = S32(0XFBFB << 16);
    // 0x8004AC20: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004AC24: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004AC28: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004AC2C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004AC30: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004AC34: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004AC38: lw          $a1, 0xE64($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE64);
    // 0x8004AC3C: lw          $a0, 0x640($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X640);
    // 0x8004AC40: jal         0x8006081C
    // 0x8004AC44: nop

    func_8006081C(rdram, ctx);
        goto after_33;
    // 0x8004AC44: nop

    after_33:
    // 0x8004AC48: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
    // 0x8004AC4C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004AC50: lw          $t8, 0x640($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X640);
    // 0x8004AC54: nop

    // 0x8004AC58: lbu         $t9, 0xA($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XA);
    // 0x8004AC5C: nop

    // 0x8004AC60: bne         $t9, $zero, L_8004AD3C
    if (ctx->r25 != 0) {
        // 0x8004AC64: nop

            goto L_8004AD3C;
    }
    // 0x8004AC64: nop

    // 0x8004AC68: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004AC6C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004AC70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004AC74: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8004AC78: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004AC7C: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8004AC80: bne         $t0, $zero, L_8004AD3C
    if (ctx->r8 != 0) {
        // 0x8004AC84: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_8004AD3C;
    }
    // 0x8004AC84: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004AC88: bne         $t1, $zero, L_8004AD3C
    if (ctx->r9 != 0) {
        // 0x8004AC8C: nop

            goto L_8004AD3C;
    }
    // 0x8004AC8C: nop

    // 0x8004AC90: jal         0x80031AC8
    // 0x8004AC94: nop

    func_80031AC8(rdram, ctx);
        goto after_34;
    // 0x8004AC94: nop

    after_34:
    // 0x8004AC98: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004AC9C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8004ACA0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004ACA4: beq         $t5, $at, L_8004ACE4
    if (ctx->r13 == ctx->r1) {
        // 0x8004ACA8: nop

            goto L_8004ACE4;
    }
    // 0x8004ACA8: nop

    // 0x8004ACAC: beq         $t5, $zero, L_8004ACE4
    if (ctx->r13 == 0) {
        // 0x8004ACB0: nop

            goto L_8004ACE4;
    }
    // 0x8004ACB0: nop

L_8004ACB4:
    // 0x8004ACB4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ACB8: jal         0x800499B0
    // 0x8004ACBC: nop

    func_800499B0(rdram, ctx);
        goto after_35;
    // 0x8004ACBC: nop

    after_35:
    // 0x8004ACC0: jal         0x80031AC8
    // 0x8004ACC4: nop

    func_80031AC8(rdram, ctx);
        goto after_36;
    // 0x8004ACC4: nop

    after_36:
    // 0x8004ACC8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004ACCC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8004ACD0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004ACD4: beq         $t6, $at, L_8004ACE4
    if (ctx->r14 == ctx->r1) {
        // 0x8004ACD8: nop

            goto L_8004ACE4;
    }
    // 0x8004ACD8: nop

    // 0x8004ACDC: bne         $t6, $zero, L_8004ACB4
    if (ctx->r14 != 0) {
        // 0x8004ACE0: nop

            goto L_8004ACB4;
    }
    // 0x8004ACE0: nop

L_8004ACE4:
    // 0x8004ACE4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004ACE8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004ACEC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004ACF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004ACF4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8004ACF8: andi        $t4, $t8, 0x1
    ctx->r12 = ctx->r24 & 0X1;
    // 0x8004ACFC: bne         $t4, $zero, L_8004AD3C
    if (ctx->r12 != 0) {
        // 0x8004AD00: and         $t5, $t9, $at
        ctx->r13 = ctx->r25 & ctx->r1;
            goto L_8004AD3C;
    }
    // 0x8004AD00: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8004AD04: bne         $t5, $zero, L_8004AD3C
    if (ctx->r13 != 0) {
        // 0x8004AD08: nop

            goto L_8004AD3C;
    }
    // 0x8004AD08: nop

    // 0x8004AD0C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004AD10: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004AD14: nop

    // 0x8004AD18: lbu         $a0, 0x8($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X8);
    // 0x8004AD1C: jal         0x80060E24
    // 0x8004AD20: nop

    func_80060E24(rdram, ctx);
        goto after_37;
    // 0x8004AD20: nop

    after_37:
    // 0x8004AD24: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004AD28: lw          $a1, 0xE64($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE64);
    // 0x8004AD2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004AD30: jal         0x80060ACC
    // 0x8004AD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060ACC(rdram, ctx);
        goto after_38;
    // 0x8004AD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8004AD38: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
L_8004AD3C:
    // 0x8004AD3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AD40: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004AD44: addiu       $at, $zero, 0x64D
    ctx->r1 = ADD32(0, 0X64D);
    // 0x8004AD48: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8004AD4C: nop

    // 0x8004AD50: bne         $t0, $at, L_8004ADB4
    if (ctx->r8 != ctx->r1) {
        // 0x8004AD54: nop

            goto L_8004ADB4;
    }
    // 0x8004AD54: nop

    // 0x8004AD58: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004AD5C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004AD60: nop

    // 0x8004AD64: lbu         $a0, 0x8($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X8);
    // 0x8004AD68: jal         0x80060E24
    // 0x8004AD6C: nop

    func_80060E24(rdram, ctx);
        goto after_39;
    // 0x8004AD6C: nop

    after_39:
    // 0x8004AD70: bne         $v0, $zero, L_8004ADB4
    if (ctx->r2 != 0) {
        // 0x8004AD74: nop

            goto L_8004ADB4;
    }
    // 0x8004AD74: nop

    // 0x8004AD78: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x8004AD7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004AD80: sh          $t6, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r14;
    // 0x8004AD84: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x8004AD88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004AD8C: sh          $t7, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r15;
    // 0x8004AD90: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8004AD94: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8004AD98: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8004AD9C: nop

    // 0x8004ADA0: ori         $t4, $t9, 0x40
    ctx->r12 = ctx->r25 | 0X40;
    // 0x8004ADA4: sh          $t4, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r12;
    // 0x8004ADA8: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004ADAC: jal         0x800499B0
    // 0x8004ADB0: nop

    func_800499B0(rdram, ctx);
        goto after_40;
    // 0x8004ADB0: nop

    after_40:
L_8004ADB4:
    // 0x8004ADB4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004ADB8: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004ADBC: nop

    // 0x8004ADC0: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004ADC4: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004ADC8: andi        $t0, $t2, 0x1
    ctx->r8 = ctx->r10 & 0X1;
    // 0x8004ADCC: bne         $t0, $zero, L_8004ADDC
    if (ctx->r8 != 0) {
        // 0x8004ADD0: andi        $t1, $t3, 0x0
        ctx->r9 = ctx->r11 & 0X0;
            goto L_8004ADDC;
    }
    // 0x8004ADD0: andi        $t1, $t3, 0x0
    ctx->r9 = ctx->r11 & 0X0;
    // 0x8004ADD4: beq         $t1, $zero, L_8004AE44
    if (ctx->r9 == 0) {
        // 0x8004ADD8: nop

            goto L_8004AE44;
    }
    // 0x8004ADD8: nop

L_8004ADDC:
    // 0x8004ADDC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004ADE0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004ADE4: nop

    // 0x8004ADE8: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8004ADEC: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x8004ADF0: andi        $t8, $t4, 0x2
    ctx->r24 = ctx->r12 & 0X2;
    // 0x8004ADF4: bne         $t8, $zero, L_8004AE04
    if (ctx->r24 != 0) {
        // 0x8004ADF8: andi        $t9, $t5, 0x0
        ctx->r25 = ctx->r13 & 0X0;
            goto L_8004AE04;
    }
    // 0x8004ADF8: andi        $t9, $t5, 0x0
    ctx->r25 = ctx->r13 & 0X0;
    // 0x8004ADFC: beq         $t9, $zero, L_8004AE10
    if (ctx->r25 == 0) {
        // 0x8004AE00: nop

            goto L_8004AE10;
    }
    // 0x8004AE00: nop

L_8004AE04:
    // 0x8004AE04: addiu       $t7, $zero, 0x6F1
    ctx->r15 = ADD32(0, 0X6F1);
    // 0x8004AE08: b           L_8004AE18
    // 0x8004AE0C: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
        goto L_8004AE18;
    // 0x8004AE0C: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
L_8004AE10:
    // 0x8004AE10: addiu       $t2, $zero, 0xFD2
    ctx->r10 = ADD32(0, 0XFD2);
    // 0x8004AE14: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
L_8004AE18:
    // 0x8004AE18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AE1C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004AE20: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004AE24: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004AE28: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004AE2C: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x8004AE30: lui         $at, 0xFDFF
    ctx->r1 = S32(0XFDFF << 16);
    // 0x8004AE34: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004AE38: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004AE3C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004AE40: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_8004AE44:
    // 0x8004AE44: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004AE48: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004AE4C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004AE50: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8004AE54: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8004AE58: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8004AE5C: bne         $t2, $zero, L_8004AE6C
    if (ctx->r10 != 0) {
        // 0x8004AE60: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_8004AE6C;
    }
    // 0x8004AE60: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8004AE64: beq         $t3, $zero, L_8004AE80
    if (ctx->r11 == 0) {
        // 0x8004AE68: nop

            goto L_8004AE80;
    }
    // 0x8004AE68: nop

L_8004AE6C:
    // 0x8004AE6C: lh          $t5, 0x72($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X72);
    // 0x8004AE70: addiu       $at, $zero, 0x6F1
    ctx->r1 = ADD32(0, 0X6F1);
    // 0x8004AE74: beq         $t5, $at, L_8004AE80
    if (ctx->r13 == ctx->r1) {
        // 0x8004AE78: nop

            goto L_8004AE80;
    }
    // 0x8004AE78: nop

    // 0x8004AE7C: sh          $zero, 0x72($sp)
    MEM_H(0X72, ctx->r29) = 0;
L_8004AE80:
    // 0x8004AE80: lh          $t0, 0x72($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X72);
    // 0x8004AE84: nop

    // 0x8004AE88: beq         $t0, $zero, L_8004AEAC
    if (ctx->r8 == 0) {
        // 0x8004AE8C: nop

            goto L_8004AEAC;
    }
    // 0x8004AE8C: nop

    // 0x8004AE90: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8004AE94: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8004AE98: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x8004AE9C: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x8004AEA0: lh          $a0, 0x72($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X72);
    // 0x8004AEA4: jal         0x80061990
    // 0x8004AEA8: nop

    func_80061990(rdram, ctx);
        goto after_41;
    // 0x8004AEA8: nop

    after_41:
L_8004AEAC:
    // 0x8004AEAC: lh          $t1, 0x72($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X72);
    // 0x8004AEB0: addiu       $at, $zero, 0x4AF
    ctx->r1 = ADD32(0, 0X4AF);
    // 0x8004AEB4: bne         $t1, $at, L_8004AEE0
    if (ctx->r9 != ctx->r1) {
        // 0x8004AEB8: nop

            goto L_8004AEE0;
    }
    // 0x8004AEB8: nop

    // 0x8004AEBC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004AEC0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004AEC4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004AEC8: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8004AECC: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x8004AED0: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004AED4: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8004AED8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8004AEDC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8004AEE0:
    // 0x8004AEE0: lh          $t7, 0x72($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X72);
    // 0x8004AEE4: nop

    // 0x8004AEE8: bne         $t7, $zero, L_8004AB7C
    if (ctx->r15 != 0) {
        // 0x8004AEEC: nop

            goto L_8004AB7C;
    }
    // 0x8004AEEC: nop

    // 0x8004AEF0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004AEF4: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004AEF8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8004AEFC: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004AF00: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004AF04: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x8004AF08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AF0C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004AF10: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8004AF14: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8004AF18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AF1C: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004AF20: addiu       $at, $zero, 0x62A
    ctx->r1 = ADD32(0, 0X62A);
    // 0x8004AF24: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8004AF28: nop

    // 0x8004AF2C: beq         $t8, $at, L_8004AF40
    if (ctx->r24 == ctx->r1) {
        // 0x8004AF30: nop

            goto L_8004AF40;
    }
    // 0x8004AF30: nop

    // 0x8004AF34: addiu       $at, $zero, 0x62D
    ctx->r1 = ADD32(0, 0X62D);
    // 0x8004AF38: bne         $t8, $at, L_8004AFA0
    if (ctx->r24 != ctx->r1) {
        // 0x8004AF3C: nop

            goto L_8004AFA0;
    }
    // 0x8004AF3C: nop

L_8004AF40:
    // 0x8004AF40: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004AF44: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004AF48: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004AF4C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004AF50: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004AF54: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8004AF58: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8004AF5C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004AF60: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004AF64: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004AF68: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004AF6C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8004AF70: sw          $t4, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r12;
    // 0x8004AF74: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004AF78: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004AF7C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004AF80: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004AF84: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004AF88: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004AF8C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004AF90: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004AF94: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004AF98: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8004AF9C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8004AFA0:
    // 0x8004AFA0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004AFA4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004AFA8: addiu       $at, $zero, 0x624
    ctx->r1 = ADD32(0, 0X624);
    // 0x8004AFAC: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8004AFB0: nop

    // 0x8004AFB4: beq         $t0, $at, L_8004AFC8
    if (ctx->r8 == ctx->r1) {
        // 0x8004AFB8: nop

            goto L_8004AFC8;
    }
    // 0x8004AFB8: nop

    // 0x8004AFBC: addiu       $at, $zero, 0x628
    ctx->r1 = ADD32(0, 0X628);
    // 0x8004AFC0: bne         $t0, $at, L_8004B028
    if (ctx->r8 != ctx->r1) {
        // 0x8004AFC4: nop

            goto L_8004B028;
    }
    // 0x8004AFC4: nop

L_8004AFC8:
    // 0x8004AFC8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004AFCC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004AFD0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004AFD4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004AFD8: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8004AFDC: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004AFE0: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8004AFE4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004AFE8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004AFEC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004AFF0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004AFF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004AFF8: sw          $t6, 0xB8($t7)
    MEM_W(0XB8, ctx->r15) = ctx->r14;
    // 0x8004AFFC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B000: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B004: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B008: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004B00C: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004B010: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x8004B014: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B018: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B01C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004B020: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8004B024: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_8004B028:
    // 0x8004B028: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B02C: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B030: addiu       $at, $zero, 0x62F
    ctx->r1 = ADD32(0, 0X62F);
    // 0x8004B034: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8004B038: nop

    // 0x8004B03C: beq         $t8, $at, L_8004B050
    if (ctx->r24 == ctx->r1) {
        // 0x8004B040: nop

            goto L_8004B050;
    }
    // 0x8004B040: nop

    // 0x8004B044: addiu       $at, $zero, 0x632
    ctx->r1 = ADD32(0, 0X632);
    // 0x8004B048: bne         $t8, $at, L_8004B0B0
    if (ctx->r24 != ctx->r1) {
        // 0x8004B04C: nop

            goto L_8004B0B0;
    }
    // 0x8004B04C: nop

L_8004B050:
    // 0x8004B050: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004B054: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004B058: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B05C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004B060: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004B064: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8004B068: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8004B06C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004B070: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004B074: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004B078: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004B07C: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x8004B080: sw          $t4, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r12;
    // 0x8004B084: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B088: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B08C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B090: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004B094: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004B098: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004B09C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B0A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B0A4: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004B0A8: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8004B0AC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8004B0B0:
    // 0x8004B0B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B0B4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B0B8: addiu       $at, $zero, 0x634
    ctx->r1 = ADD32(0, 0X634);
    // 0x8004B0BC: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8004B0C0: nop

    // 0x8004B0C4: beq         $t0, $at, L_8004B0D8
    if (ctx->r8 == ctx->r1) {
        // 0x8004B0C8: nop

            goto L_8004B0D8;
    }
    // 0x8004B0C8: nop

    // 0x8004B0CC: addiu       $at, $zero, 0x637
    ctx->r1 = ADD32(0, 0X637);
    // 0x8004B0D0: bne         $t0, $at, L_8004B138
    if (ctx->r8 != ctx->r1) {
        // 0x8004B0D4: nop

            goto L_8004B138;
    }
    // 0x8004B0D4: nop

L_8004B0D8:
    // 0x8004B0D8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B0DC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004B0E0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B0E4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004B0E8: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8004B0EC: or          $t8, $t4, $zero
    ctx->r24 = ctx->r12 | 0;
    // 0x8004B0F0: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8004B0F4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004B0F8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004B0FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004B100: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004B104: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8004B108: sw          $t6, 0xB8($t7)
    MEM_W(0XB8, ctx->r15) = ctx->r14;
    // 0x8004B10C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B110: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B114: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B118: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004B11C: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004B120: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x8004B124: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B128: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B12C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004B130: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8004B134: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_8004B138:
    // 0x8004B138: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B13C: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B140: addiu       $at, $zero, 0x639
    ctx->r1 = ADD32(0, 0X639);
    // 0x8004B144: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8004B148: nop

    // 0x8004B14C: beq         $t8, $at, L_8004B160
    if (ctx->r24 == ctx->r1) {
        // 0x8004B150: nop

            goto L_8004B160;
    }
    // 0x8004B150: nop

    // 0x8004B154: addiu       $at, $zero, 0x63D
    ctx->r1 = ADD32(0, 0X63D);
    // 0x8004B158: bne         $t8, $at, L_8004B1C0
    if (ctx->r24 != ctx->r1) {
        // 0x8004B15C: nop

            goto L_8004B1C0;
    }
    // 0x8004B15C: nop

L_8004B160:
    // 0x8004B160: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004B164: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004B168: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B16C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8004B170: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8004B174: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8004B178: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8004B17C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8004B180: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8004B184: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004B188: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004B18C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8004B190: sw          $t4, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r12;
    // 0x8004B194: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B198: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B19C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8004B1A0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8004B1A4: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8004B1A8: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004B1AC: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8004B1B0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B1B4: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004B1B8: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8004B1BC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8004B1C0:
    // 0x8004B1C0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B1C4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004B1C8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004B1CC: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004B1D0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004B1D4: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8004B1D8: bne         $t4, $zero, L_8004AB2C
    if (ctx->r12 != 0) {
        // 0x8004B1DC: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_8004AB2C;
    }
    // 0x8004B1DC: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004B1E0: bne         $t5, $zero, L_8004AB2C
    if (ctx->r13 != 0) {
        // 0x8004B1E4: nop

            goto L_8004AB2C;
    }
    // 0x8004B1E4: nop

    // 0x8004B1E8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004B1EC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004B1F0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004B1F4: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8004B1F8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004B1FC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8004B200: bne         $t2, $zero, L_8004B26C
    if (ctx->r10 != 0) {
        // 0x8004B204: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8004B26C;
    }
    // 0x8004B204: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8004B208: bne         $t3, $zero, L_8004B26C
    if (ctx->r11 != 0) {
        // 0x8004B20C: nop

            goto L_8004B26C;
    }
    // 0x8004B20C: nop

    // 0x8004B210: jal         0x80031AC8
    // 0x8004B214: nop

    func_80031AC8(rdram, ctx);
        goto after_42;
    // 0x8004B214: nop

    after_42:
    // 0x8004B218: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004B21C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8004B220: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B224: beq         $t9, $at, L_8004B264
    if (ctx->r25 == ctx->r1) {
        // 0x8004B228: nop

            goto L_8004B264;
    }
    // 0x8004B228: nop

    // 0x8004B22C: beq         $t9, $zero, L_8004B264
    if (ctx->r25 == 0) {
        // 0x8004B230: nop

            goto L_8004B264;
    }
    // 0x8004B230: nop

L_8004B234:
    // 0x8004B234: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B238: jal         0x800499B0
    // 0x8004B23C: nop

    func_800499B0(rdram, ctx);
        goto after_43;
    // 0x8004B23C: nop

    after_43:
    // 0x8004B240: jal         0x80031AC8
    // 0x8004B244: nop

    func_80031AC8(rdram, ctx);
        goto after_44;
    // 0x8004B244: nop

    after_44:
    // 0x8004B248: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8004B24C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8004B250: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B254: beq         $t0, $at, L_8004B264
    if (ctx->r8 == ctx->r1) {
        // 0x8004B258: nop

            goto L_8004B264;
    }
    // 0x8004B258: nop

    // 0x8004B25C: bne         $t0, $zero, L_8004B234
    if (ctx->r8 != 0) {
        // 0x8004B260: nop

            goto L_8004B234;
    }
    // 0x8004B260: nop

L_8004B264:
    // 0x8004B264: jal         0x80031B6C
    // 0x8004B268: nop

    func_80031B6C(rdram, ctx);
        goto after_45;
    // 0x8004B268: nop

    after_45:
L_8004B26C:
    // 0x8004B26C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B270: lw          $t1, 0x640($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X640);
    // 0x8004B274: addiu       $at, $zero, 0x751
    ctx->r1 = ADD32(0, 0X751);
    // 0x8004B278: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x8004B27C: nop

    // 0x8004B280: bne         $t4, $at, L_8004B2A8
    if (ctx->r12 != ctx->r1) {
        // 0x8004B284: nop

            goto L_8004B2A8;
    }
    // 0x8004B284: nop

    // 0x8004B288: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004B28C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004B290: addiu       $t5, $zero, 0xE10
    ctx->r13 = ADD32(0, 0XE10);
    // 0x8004B294: sh          $t5, 0x3E($t8)
    MEM_H(0X3E, ctx->r24) = ctx->r13;
    // 0x8004B298: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004B29C: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004B2A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004B2A4: sh          $t6, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = ctx->r14;
L_8004B2A8:
    // 0x8004B2A8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004B2AC: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x8004B2B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B2B4: bne         $t2, $at, L_8004B378
    if (ctx->r10 != ctx->r1) {
        // 0x8004B2B8: nop

            goto L_8004B378;
    }
    // 0x8004B2B8: nop

    // 0x8004B2BC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004B2C0: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8004B2C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004B2C8: bne         $t3, $at, L_8004B378
    if (ctx->r11 != ctx->r1) {
        // 0x8004B2CC: nop

            goto L_8004B378;
    }
    // 0x8004B2CC: nop

    // 0x8004B2D0: jal         0x8005F064
    // 0x8004B2D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F064(rdram, ctx);
        goto after_46;
    // 0x8004B2D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x8004B2D8: bne         $v0, $zero, L_8004B334
    if (ctx->r2 != 0) {
        // 0x8004B2DC: nop

            goto L_8004B334;
    }
    // 0x8004B2DC: nop

    // 0x8004B2E0: addiu       $t9, $zero, 0x38
    ctx->r25 = ADD32(0, 0X38);
    // 0x8004B2E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B2E8: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
    // 0x8004B2EC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004B2F0: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8004B2F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B2F8: ori         $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 | 0X8000;
    // 0x8004B2FC: sh          $t1, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r9;
    // 0x8004B300: jal         0x80031914
    // 0x8004B304: nop

    func_80031914(rdram, ctx);
        goto after_47;
    // 0x8004B304: nop

    after_47:
    // 0x8004B308: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004B30C: lw          $a0, 0x7260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7260);
    // 0x8004B310: jal         0x800BCB10
    // 0x8004B314: nop

    func_800BCB10(rdram, ctx);
        goto after_48;
    // 0x8004B314: nop

    after_48:
L_8004B318:
    // 0x8004B318: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B31C: jal         0x800499B0
    // 0x8004B320: nop

    func_800499B0(rdram, ctx);
        goto after_49;
    // 0x8004B320: nop

    after_49:
    // 0x8004B324: b           L_8004B318
    // 0x8004B328: nop

        goto L_8004B318;
    // 0x8004B328: nop

    // 0x8004B32C: b           L_8004B378
    // 0x8004B330: nop

        goto L_8004B378;
    // 0x8004B330: nop

L_8004B334:
    // 0x8004B334: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8004B338: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B33C: sh          $t4, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r12;
    // 0x8004B340: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8004B344: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B348: sh          $t5, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r13;
    // 0x8004B34C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004B350: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B354: sb          $t8, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r24;
    // 0x8004B358: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8004B35C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B360: sh          $t6, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r14;
    // 0x8004B364: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8004B368: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B36C: sw          $t7, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r15;
    // 0x8004B370: jal         0x80031914
    // 0x8004B374: nop

    func_80031914(rdram, ctx);
        goto after_50;
    // 0x8004B374: nop

    after_50:
L_8004B378:
    // 0x8004B378: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B37C: lw          $t2, 0x640($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X640);
    // 0x8004B380: addiu       $at, $zero, 0x5BF
    ctx->r1 = ADD32(0, 0X5BF);
    // 0x8004B384: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8004B388: nop

    // 0x8004B38C: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B390: nop

            goto L_8004B3C4;
    }
    // 0x8004B390: nop

    // 0x8004B394: addiu       $at, $zero, 0x629
    ctx->r1 = ADD32(0, 0X629);
    // 0x8004B398: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B39C: nop

            goto L_8004B3C4;
    }
    // 0x8004B39C: nop

    // 0x8004B3A0: addiu       $at, $zero, 0x62E
    ctx->r1 = ADD32(0, 0X62E);
    // 0x8004B3A4: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B3A8: nop

            goto L_8004B3C4;
    }
    // 0x8004B3A8: nop

    // 0x8004B3AC: addiu       $at, $zero, 0x633
    ctx->r1 = ADD32(0, 0X633);
    // 0x8004B3B0: beq         $t3, $at, L_8004B3C4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B3B4: nop

            goto L_8004B3C4;
    }
    // 0x8004B3B4: nop

    // 0x8004B3B8: addiu       $at, $zero, 0x638
    ctx->r1 = ADD32(0, 0X638);
    // 0x8004B3BC: bne         $t3, $at, L_8004B49C
    if (ctx->r11 != ctx->r1) {
        // 0x8004B3C0: nop

            goto L_8004B49C;
    }
    // 0x8004B3C0: nop

L_8004B3C4:
    // 0x8004B3C4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8004B3C8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8004B3CC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8004B3D0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004B3D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B3D8: nop

    // 0x8004B3DC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8004B3E0: jal         0x80016620
    // 0x8004B3E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80016620(rdram, ctx);
        goto after_51;
    // 0x8004B3E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_51:
    // 0x8004B3E8: jal         0x80016138
    // 0x8004B3EC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_52;
    // 0x8004B3EC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_52:
    // 0x8004B3F0: beq         $v0, $zero, L_8004B414
    if (ctx->r2 == 0) {
        // 0x8004B3F4: nop

            goto L_8004B414;
    }
    // 0x8004B3F4: nop

L_8004B3F8:
    // 0x8004B3F8: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B3FC: jal         0x800499B0
    // 0x8004B400: nop

    func_800499B0(rdram, ctx);
        goto after_53;
    // 0x8004B400: nop

    after_53:
    // 0x8004B404: jal         0x80016138
    // 0x8004B408: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_54;
    // 0x8004B408: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_54:
    // 0x8004B40C: bne         $v0, $zero, L_8004B3F8
    if (ctx->r2 != 0) {
        // 0x8004B410: nop

            goto L_8004B3F8;
    }
    // 0x8004B410: nop

L_8004B414:
    // 0x8004B414: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
L_8004B418:
    // 0x8004B418: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B41C: jal         0x800499B0
    // 0x8004B420: nop

    func_800499B0(rdram, ctx);
        goto after_55;
    // 0x8004B420: nop

    after_55:
    // 0x8004B424: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8004B428: nop

    // 0x8004B42C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8004B430: slti        $at, $t0, 0x78
    ctx->r1 = SIGNED(ctx->r8) < 0X78 ? 1 : 0;
    // 0x8004B434: bne         $at, $zero, L_8004B418
    if (ctx->r1 != 0) {
        // 0x8004B438: sw          $t0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r8;
            goto L_8004B418;
    }
    // 0x8004B438: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8004B43C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8004B440: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B444: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x8004B448: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004B44C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B450: sh          $t4, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r12;
    // 0x8004B454: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B458: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
    // 0x8004B45C: addiu       $t5, $zero, 0x1F
    ctx->r13 = ADD32(0, 0X1F);
    // 0x8004B460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B464: sh          $t5, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r13;
    // 0x8004B468: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8004B46C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B470: sw          $t8, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r24;
    // 0x8004B474: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004B478: lw          $t6, 0x718C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X718C);
    // 0x8004B47C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B480: addiu       $t7, $t6, -0x64
    ctx->r15 = ADD32(ctx->r14, -0X64);
    // 0x8004B484: sw          $t7, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r15;
L_8004B488:
    // 0x8004B488: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B48C: jal         0x800499B0
    // 0x8004B490: nop

    func_800499B0(rdram, ctx);
        goto after_56;
    // 0x8004B490: nop

    after_56:
    // 0x8004B494: b           L_8004B488
    // 0x8004B498: nop

        goto L_8004B488;
    // 0x8004B498: nop

L_8004B49C:
    // 0x8004B49C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B4A0: lw          $t2, 0x640($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X640);
    // 0x8004B4A4: addiu       $at, $zero, 0x6CB
    ctx->r1 = ADD32(0, 0X6CB);
    // 0x8004B4A8: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8004B4AC: nop

    // 0x8004B4B0: beq         $t3, $at, L_8004B4E4
    if (ctx->r11 == ctx->r1) {
        // 0x8004B4B4: nop

            goto L_8004B4E4;
    }
    // 0x8004B4B4: nop

    // 0x8004B4B8: addiu       $at, $zero, 0x553
    ctx->r1 = ADD32(0, 0X553);
    // 0x8004B4BC: bne         $t3, $at, L_8004B568
    if (ctx->r11 != ctx->r1) {
        // 0x8004B4C0: nop

            goto L_8004B568;
    }
    // 0x8004B4C0: nop

    // 0x8004B4C4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004B4C8: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004B4CC: nop

    // 0x8004B4D0: lbu         $a0, 0x8($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X8);
    // 0x8004B4D4: jal         0x80060E24
    // 0x8004B4D8: nop

    func_80060E24(rdram, ctx);
        goto after_57;
    // 0x8004B4D8: nop

    after_57:
    // 0x8004B4DC: bne         $v0, $zero, L_8004B568
    if (ctx->r2 != 0) {
        // 0x8004B4E0: nop

            goto L_8004B568;
    }
    // 0x8004B4E0: nop

L_8004B4E4:
    // 0x8004B4E4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8004B4E8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8004B4EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8004B4F0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004B4F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004B4F8: nop

    // 0x8004B4FC: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8004B500: jal         0x80016620
    // 0x8004B504: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80016620(rdram, ctx);
        goto after_58;
    // 0x8004B504: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_58:
    // 0x8004B508: jal         0x80016138
    // 0x8004B50C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_59;
    // 0x8004B50C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_59:
    // 0x8004B510: beq         $v0, $zero, L_8004B534
    if (ctx->r2 == 0) {
        // 0x8004B514: nop

            goto L_8004B534;
    }
    // 0x8004B514: nop

L_8004B518:
    // 0x8004B518: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B51C: jal         0x800499B0
    // 0x8004B520: nop

    func_800499B0(rdram, ctx);
        goto after_60;
    // 0x8004B520: nop

    after_60:
    // 0x8004B524: jal         0x80016138
    // 0x8004B528: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_61;
    // 0x8004B528: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_61:
    // 0x8004B52C: bne         $v0, $zero, L_8004B518
    if (ctx->r2 != 0) {
        // 0x8004B530: nop

            goto L_8004B518;
    }
    // 0x8004B530: nop

L_8004B534:
    // 0x8004B534: addiu       $t0, $zero, 0x36
    ctx->r8 = ADD32(0, 0X36);
    // 0x8004B538: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B53C: sh          $t0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r8;
    // 0x8004B540: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004B544: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8004B548: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B54C: ori         $t4, $t1, 0x8000
    ctx->r12 = ctx->r9 | 0X8000;
    // 0x8004B550: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
L_8004B554:
    // 0x8004B554: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B558: jal         0x800499B0
    // 0x8004B55C: nop

    func_800499B0(rdram, ctx);
        goto after_62;
    // 0x8004B55C: nop

    after_62:
    // 0x8004B560: b           L_8004B554
    // 0x8004B564: nop

        goto L_8004B554;
    // 0x8004B564: nop

L_8004B568:
    // 0x8004B568: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004B56C: lw          $t5, 0x640($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X640);
    // 0x8004B570: addiu       $at, $zero, 0x6FD
    ctx->r1 = ADD32(0, 0X6FD);
    // 0x8004B574: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8004B578: nop

    // 0x8004B57C: bne         $t8, $at, L_8004B5B8
    if (ctx->r24 != ctx->r1) {
        // 0x8004B580: nop

            goto L_8004B5B8;
    }
    // 0x8004B580: nop

    // 0x8004B584: addiu       $t6, $zero, 0x44
    ctx->r14 = ADD32(0, 0X44);
    // 0x8004B588: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B58C: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
    // 0x8004B590: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004B594: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x8004B598: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B59C: ori         $t2, $t7, 0x8000
    ctx->r10 = ctx->r15 | 0X8000;
    // 0x8004B5A0: sh          $t2, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r10;
L_8004B5A4:
    // 0x8004B5A4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B5A8: jal         0x800499B0
    // 0x8004B5AC: nop

    func_800499B0(rdram, ctx);
        goto after_63;
    // 0x8004B5AC: nop

    after_63:
    // 0x8004B5B0: b           L_8004B5A4
    // 0x8004B5B4: nop

        goto L_8004B5A4;
    // 0x8004B5B4: nop

L_8004B5B8:
    // 0x8004B5B8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004B5BC: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x8004B5C0: addiu       $at, $zero, 0x6DD
    ctx->r1 = ADD32(0, 0X6DD);
    // 0x8004B5C4: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8004B5C8: nop

    // 0x8004B5CC: bne         $t9, $at, L_8004B634
    if (ctx->r25 != ctx->r1) {
        // 0x8004B5D0: nop

            goto L_8004B634;
    }
    // 0x8004B5D0: nop

    // 0x8004B5D4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004B5D8: lh          $t0, 0x1B48($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X1B48);
    // 0x8004B5DC: nop

    // 0x8004B5E0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8004B5E4: bne         $at, $zero, L_8004B604
    if (ctx->r1 != 0) {
        // 0x8004B5E8: nop

            goto L_8004B604;
    }
    // 0x8004B5E8: nop

    // 0x8004B5EC: jal         0x80029C8C
    // 0x8004B5F0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_80029C8C(rdram, ctx);
        goto after_64;
    // 0x8004B5F0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_64:
    // 0x8004B5F4: jal         0x80029ED8
    // 0x8004B5F8: nop

    func_80029ED8(rdram, ctx);
        goto after_65;
    // 0x8004B5F8: nop

    after_65:
    // 0x8004B5FC: b           L_8004B634
    // 0x8004B600: nop

        goto L_8004B634;
    // 0x8004B600: nop

L_8004B604:
    // 0x8004B604: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B608: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004B60C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004B610: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B614: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004B618: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8004B61C: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8004B620: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8004B624: lw          $a3, 0xC($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XC);
    // 0x8004B628: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8004B62C: jal         0x800298A4
    // 0x8004B630: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800298A4(rdram, ctx);
        goto after_66;
    // 0x8004B630: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_66:
L_8004B634:
    // 0x8004B634: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004B638: lw          $t4, 0x640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X640);
    // 0x8004B63C: addiu       $at, $zero, 0x5C0
    ctx->r1 = ADD32(0, 0X5C0);
    // 0x8004B640: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8004B644: nop

    // 0x8004B648: bne         $t5, $at, L_8004B684
    if (ctx->r13 != ctx->r1) {
        // 0x8004B64C: nop

            goto L_8004B684;
    }
    // 0x8004B64C: nop

    // 0x8004B650: addiu       $t8, $zero, 0x29
    ctx->r24 = ADD32(0, 0X29);
    // 0x8004B654: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004B658: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x8004B65C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004B660: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8004B664: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004B668: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8004B66C: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
L_8004B670:
    // 0x8004B670: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B674: jal         0x800499B0
    // 0x8004B678: nop

    func_800499B0(rdram, ctx);
        goto after_67;
    // 0x8004B678: nop

    after_67:
    // 0x8004B67C: b           L_8004B670
    // 0x8004B680: nop

        goto L_8004B670;
    // 0x8004B680: nop

L_8004B684:
    // 0x8004B684: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004B688: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004B68C: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B690: lh          $a1, 0x4A($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X4A);
    // 0x8004B694: nop

    // 0x8004B698: andi        $t3, $a1, 0x1FFF
    ctx->r11 = ctx->r5 & 0X1FFF;
    // 0x8004B69C: jal         0x8005218C
    // 0x8004B6A0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8005218C(rdram, ctx);
        goto after_68;
    // 0x8004B6A0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_68:
    // 0x8004B6A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B6A8: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
    // 0x8004B6AC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004B6B0: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004B6B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B6B8: bne         $t9, $at, L_8004B6E8
    if (ctx->r25 != ctx->r1) {
        // 0x8004B6BC: nop

            goto L_8004B6E8;
    }
    // 0x8004B6BC: nop

    // 0x8004B6C0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004B6C4: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004B6C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004B6CC: bne         $t0, $at, L_8004B6E8
    if (ctx->r8 != ctx->r1) {
        // 0x8004B6D0: nop

            goto L_8004B6E8;
    }
    // 0x8004B6D0: nop

L_8004B6D4:
    // 0x8004B6D4: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x8004B6D8: jal         0x800499B0
    // 0x8004B6DC: nop

    func_800499B0(rdram, ctx);
        goto after_69;
    // 0x8004B6DC: nop

    after_69:
    // 0x8004B6E0: b           L_8004B6D4
    // 0x8004B6E4: nop

        goto L_8004B6D4;
    // 0x8004B6E4: nop

L_8004B6E8:
    // 0x8004B6E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B6EC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004B6F0: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004B6F4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8004B6F8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004B6FC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004B700: bne         $t8, $zero, L_8004B71C
    if (ctx->r24 != 0) {
        // 0x8004B704: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_8004B71C;
    }
    // 0x8004B704: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x8004B708: bne         $t9, $zero, L_8004B71C
    if (ctx->r25 != 0) {
        // 0x8004B70C: nop

            goto L_8004B71C;
    }
    // 0x8004B70C: nop

    // 0x8004B710: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B714: b           L_8004B74C
    // 0x8004B718: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
        goto L_8004B74C;
    // 0x8004B718: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_8004B71C:
    // 0x8004B71C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004B720: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004B724: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8004B728: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8004B72C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B730: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004B734: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x8004B738: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004B73C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8004B740: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8004B744: b           L_8004A180
    // 0x8004B748: nop

        goto L_8004A180;
    // 0x8004B748: nop

L_8004B74C:
    // 0x8004B74C: b           L_8004A438
    // 0x8004B750: nop

        goto L_8004A438;
    // 0x8004B750: nop

    // 0x8004B754: b           L_8004B75C
    // 0x8004B758: nop

        goto L_8004B75C;
    // 0x8004B758: nop

L_8004B75C:
    // 0x8004B75C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004B760: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8004B764: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8004B768: jr          $ra
    // 0x8004B76C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8004B76C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_8004B770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B770: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8004B774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004B778: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8004B77C: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x8004B780: nop

    // 0x8004B784: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x8004B788: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B78C: nop

    // 0x8004B790: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8004B794: nop

    // 0x8004B798: sw          $t8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r24;
    // 0x8004B79C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x8004B7A0: nop

    // 0x8004B7A4: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x8004B7A8: lw          $t0, 0x2F9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2F9);
    // 0x8004B7AC: nop

    // 0x8004B7B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8004B7B4: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B7B8: nop

    // 0x8004B7BC: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x8004B7C0: jal         0x80098754
    // 0x8004B7C4: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8004B7C4: nop

    after_0:
    // 0x8004B7C8: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B7CC: jal         0x80032410
    // 0x8004B7D0: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x8004B7D0: nop

    after_1:
    // 0x8004B7D4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8004B7D8: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8004B7DC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8004B7E0: nop

    // 0x8004B7E4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8004B7E8: beq         $t4, $zero, L_8004B818
    if (ctx->r12 == 0) {
        // 0x8004B7EC: nop

            goto L_8004B818;
    }
    // 0x8004B7EC: nop

L_8004B7F0:
    // 0x8004B7F0: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B7F4: jal         0x800499B0
    // 0x8004B7F8: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8004B7F8: nop

    after_2:
    // 0x8004B7FC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8004B800: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x8004B804: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8004B808: nop

    // 0x8004B80C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8004B810: bne         $t7, $zero, L_8004B7F0
    if (ctx->r15 != 0) {
        // 0x8004B814: nop

            goto L_8004B7F0;
    }
    // 0x8004B814: nop

L_8004B818:
    // 0x8004B818: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8004B81C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004B820: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8004B824: lw          $t1, 0x634($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X634);
    // 0x8004B828: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8004B82C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8004B830: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8004B834: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8004B838: lh          $t3, -0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, -0X2);
    // 0x8004B83C: nop

    // 0x8004B840: bne         $t3, $zero, L_8004B85C
    if (ctx->r11 != 0) {
        // 0x8004B844: sh          $t3, 0x1C($sp)
        MEM_H(0X1C, ctx->r29) = ctx->r11;
            goto L_8004B85C;
    }
    // 0x8004B844: sh          $t3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r11;
L_8004B848:
    // 0x8004B848: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B84C: jal         0x800499B0
    // 0x8004B850: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8004B850: nop

    after_3:
    // 0x8004B854: b           L_8004B848
    // 0x8004B858: nop

        goto L_8004B848;
    // 0x8004B858: nop

L_8004B85C:
    // 0x8004B85C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8004B860: lh          $a0, 0x1C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1C);
    // 0x8004B864: lw          $a1, 0x74($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X74);
    // 0x8004B868: lw          $a2, 0x78($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X78);
    // 0x8004B86C: jal         0x80061990
    // 0x8004B870: nop

    func_80061990(rdram, ctx);
        goto after_4;
    // 0x8004B870: nop

    after_4:
L_8004B874:
    // 0x8004B874: jal         0x80031AC8
    // 0x8004B878: nop

    func_80031AC8(rdram, ctx);
        goto after_5;
    // 0x8004B878: nop

    after_5:
    // 0x8004B87C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B880: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8004B884: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B888: beq         $t5, $at, L_8004B8C8
    if (ctx->r13 == ctx->r1) {
        // 0x8004B88C: nop

            goto L_8004B8C8;
    }
    // 0x8004B88C: nop

    // 0x8004B890: beq         $t5, $zero, L_8004B8C8
    if (ctx->r13 == 0) {
        // 0x8004B894: nop

            goto L_8004B8C8;
    }
    // 0x8004B894: nop

L_8004B898:
    // 0x8004B898: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B89C: jal         0x800499B0
    // 0x8004B8A0: nop

    func_800499B0(rdram, ctx);
        goto after_6;
    // 0x8004B8A0: nop

    after_6:
    // 0x8004B8A4: jal         0x80031AC8
    // 0x8004B8A8: nop

    func_80031AC8(rdram, ctx);
        goto after_7;
    // 0x8004B8A8: nop

    after_7:
    // 0x8004B8AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B8B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8004B8B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B8B8: beq         $t6, $at, L_8004B8C8
    if (ctx->r14 == ctx->r1) {
        // 0x8004B8BC: nop

            goto L_8004B8C8;
    }
    // 0x8004B8BC: nop

    // 0x8004B8C0: bne         $t6, $zero, L_8004B898
    if (ctx->r14 != 0) {
        // 0x8004B8C4: nop

            goto L_8004B898;
    }
    // 0x8004B8C4: nop

L_8004B8C8:
    // 0x8004B8C8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8004B8CC: nop

    // 0x8004B8D0: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8004B8D4: jal         0x8006081C
    // 0x8004B8D8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8006081C(rdram, ctx);
        goto after_8;
    // 0x8004B8D8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_8:
    // 0x8004B8DC: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8004B8E0: lh          $t8, 0x1E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1E);
    // 0x8004B8E4: nop

    // 0x8004B8E8: beq         $t8, $zero, L_8004B908
    if (ctx->r24 == 0) {
        // 0x8004B8EC: nop

            goto L_8004B908;
    }
    // 0x8004B8EC: nop

    // 0x8004B8F0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004B8F4: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x8004B8F8: lw          $a1, 0x74($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X74);
    // 0x8004B8FC: lw          $a2, 0x78($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X78);
    // 0x8004B900: jal         0x80061990
    // 0x8004B904: nop

    func_80061990(rdram, ctx);
        goto after_9;
    // 0x8004B904: nop

    after_9:
L_8004B908:
    // 0x8004B908: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x8004B90C: nop

    // 0x8004B910: bne         $t0, $zero, L_8004B874
    if (ctx->r8 != 0) {
        // 0x8004B914: nop

            goto L_8004B874;
    }
    // 0x8004B914: nop

    // 0x8004B918: jal         0x80031AC8
    // 0x8004B91C: nop

    func_80031AC8(rdram, ctx);
        goto after_10;
    // 0x8004B91C: nop

    after_10:
    // 0x8004B920: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B924: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8004B928: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B92C: beq         $t1, $at, L_8004B96C
    if (ctx->r9 == ctx->r1) {
        // 0x8004B930: nop

            goto L_8004B96C;
    }
    // 0x8004B930: nop

    // 0x8004B934: beq         $t1, $zero, L_8004B96C
    if (ctx->r9 == 0) {
        // 0x8004B938: nop

            goto L_8004B96C;
    }
    // 0x8004B938: nop

L_8004B93C:
    // 0x8004B93C: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B940: jal         0x800499B0
    // 0x8004B944: nop

    func_800499B0(rdram, ctx);
        goto after_11;
    // 0x8004B944: nop

    after_11:
    // 0x8004B948: jal         0x80031AC8
    // 0x8004B94C: nop

    func_80031AC8(rdram, ctx);
        goto after_12;
    // 0x8004B94C: nop

    after_12:
    // 0x8004B950: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8004B954: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8004B958: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004B95C: beq         $t2, $at, L_8004B96C
    if (ctx->r10 == ctx->r1) {
        // 0x8004B960: nop

            goto L_8004B96C;
    }
    // 0x8004B960: nop

    // 0x8004B964: bne         $t2, $zero, L_8004B93C
    if (ctx->r10 != 0) {
        // 0x8004B968: nop

            goto L_8004B93C;
    }
    // 0x8004B968: nop

L_8004B96C:
    // 0x8004B96C: jal         0x80031B6C
    // 0x8004B970: nop

    func_80031B6C(rdram, ctx);
        goto after_13;
    // 0x8004B970: nop

    after_13:
    // 0x8004B974: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8004B978: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8004B97C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004B980: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004B984: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004B988: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004B98C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8004B990: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004B994: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004B998: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B99C: nop

    // 0x8004B9A0: sb          $zero, 0x20($t8)
    MEM_B(0X20, ctx->r24) = 0;
    // 0x8004B9A4: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9A8: nop

    // 0x8004B9AC: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8004B9B0: jal         0x80098AD8
    // 0x8004B9B4: nop

    func_80098AD8(rdram, ctx);
        goto after_14;
    // 0x8004B9B4: nop

    after_14:
    // 0x8004B9B8: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9BC: jal         0x80049544
    // 0x8004B9C0: nop

    func_80049544(rdram, ctx);
        goto after_15;
    // 0x8004B9C0: nop

    after_15:
    // 0x8004B9C4: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9C8: nop

    // 0x8004B9CC: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8004B9D0: jal         0x800C0D34
    // 0x8004B9D4: nop

    Thread_StopThread(rdram, ctx);
        goto after_16;
    // 0x8004B9D4: nop

    after_16:
L_8004B9D8:
    // 0x8004B9D8: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    // 0x8004B9DC: jal         0x800499B0
    // 0x8004B9E0: nop

    func_800499B0(rdram, ctx);
        goto after_17;
    // 0x8004B9E0: nop

    after_17:
    // 0x8004B9E4: b           L_8004B9D8
    // 0x8004B9E8: nop

        goto L_8004B9D8;
    // 0x8004B9E8: nop

    // 0x8004B9EC: b           L_8004B9F4
    // 0x8004B9F0: nop

        goto L_8004B9F4;
    // 0x8004B9F0: nop

L_8004B9F4:
    // 0x8004B9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004B9F8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x8004B9FC: jr          $ra
    // 0x8004BA00: nop

    return;
    // 0x8004BA00: nop

;}
RECOMP_FUNC void func_8004BA04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BA04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004BA08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004BA0C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004BA10: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004BA14: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004BA18: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004BA1C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004BA20: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004BA24: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BA28: nop

    // 0x8004BA2C: bne         $t6, $t7, L_8004BA44
    if (ctx->r14 != ctx->r15) {
        // 0x8004BA30: nop

            goto L_8004BA44;
    }
    // 0x8004BA30: nop

    // 0x8004BA34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004BA38: addiu       $t8, $t8, 0xEC8
    ctx->r24 = ADD32(ctx->r24, 0XEC8);
    // 0x8004BA3C: b           L_8004BA68
    // 0x8004BA40: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_8004BA68;
    // 0x8004BA40: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8004BA44:
    // 0x8004BA44: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BA48: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004BA4C: lbu         $t0, 0x7E($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7E);
    // 0x8004BA50: addiu       $t2, $t2, 0xEF8
    ctx->r10 = ADD32(ctx->r10, 0XEF8);
    // 0x8004BA54: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8004BA58: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8004BA5C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8004BA60: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8004BA64: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_8004BA68:
    // 0x8004BA68: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BA6C: nop

    // 0x8004BA70: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x8004BA74: jal         0x800989BC
    // 0x8004BA78: nop

    func_800989BC(rdram, ctx);
        goto after_0;
    // 0x8004BA78: nop

    after_0:
    // 0x8004BA7C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8004BA80: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BA84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BA88: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x8004BA8C: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x8004BA90: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004BA94: addiu       $a1, $a1, -0x448C
    ctx->r5 = ADD32(ctx->r5, -0X448C);
    // 0x8004BA98: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004BA9C: jal         0x80049230
    // 0x8004BAA0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_80049230(rdram, ctx);
        goto after_1;
    // 0x8004BAA0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_1:
    // 0x8004BAA4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BAA8: nop

    // 0x8004BAAC: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8004BAB0: jal         0x800C13B8
    // 0x8004BAB4: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_2;
    // 0x8004BAB4: nop

    after_2:
    // 0x8004BAB8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004BABC: lw          $t8, 0x6C4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6C4);
    // 0x8004BAC0: nop

    // 0x8004BAC4: beq         $t8, $zero, L_8004BB1C
    if (ctx->r24 == 0) {
        // 0x8004BAC8: nop

            goto L_8004BB1C;
    }
    // 0x8004BAC8: nop

L_8004BACC:
    // 0x8004BACC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BAD0: jal         0x80049544
    // 0x8004BAD4: nop

    func_80049544(rdram, ctx);
        goto after_3;
    // 0x8004BAD4: nop

    after_3:
    // 0x8004BAD8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BADC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8004BAE0: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8004BAE4: jal         0x800C143C
    // 0x8004BAE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_4;
    // 0x8004BAE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8004BAEC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8004BAF0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004BAF4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8004BAF8: nop

    // 0x8004BAFC: bne         $t1, $at, L_8004BB0C
    if (ctx->r9 != ctx->r1) {
        // 0x8004BB00: nop

            goto L_8004BB0C;
    }
    // 0x8004BB00: nop

    // 0x8004BB04: b           L_8004BB14
    // 0x8004BB08: nop

        goto L_8004BB14;
    // 0x8004BB08: nop

L_8004BB0C:
    // 0x8004BB0C: b           L_8004BACC
    // 0x8004BB10: nop

        goto L_8004BACC;
    // 0x8004BB10: nop

L_8004BB14:
    // 0x8004BB14: b           L_8004BB28
    // 0x8004BB18: nop

        goto L_8004BB28;
    // 0x8004BB18: nop

L_8004BB1C:
    // 0x8004BB1C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB20: jal         0x80032410
    // 0x8004BB24: nop

    func_80032410(rdram, ctx);
        goto after_5;
    // 0x8004BB24: nop

    after_5:
L_8004BB28:
    // 0x8004BB28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB2C: jal         0x80049438
    // 0x8004BB30: nop

    func_80049438(rdram, ctx);
        goto after_6;
    // 0x8004BB30: nop

    after_6:
    // 0x8004BB34: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB38: nop

    // 0x8004BB3C: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x8004BB40: jal         0x80098754
    // 0x8004BB44: nop

    func_80098754(rdram, ctx);
        goto after_7;
    // 0x8004BB44: nop

    after_7:
    // 0x8004BB48: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB4C: nop

    // 0x8004BB50: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x8004BB54: jal         0x800C13B8
    // 0x8004BB58: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_8;
    // 0x8004BB58: nop

    after_8:
    // 0x8004BB5C: b           L_8004BB64
    // 0x8004BB60: nop

        goto L_8004BB64;
    // 0x8004BB60: nop

L_8004BB64:
    // 0x8004BB64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004BB68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004BB6C: jr          $ra
    // 0x8004BB70: nop

    return;
    // 0x8004BB70: nop

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
RECOMP_FUNC void func_8004D768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D768: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004D76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D770: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8004D774: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8004D778: nop

    // 0x8004D77C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8004D780: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8004D784: nop

    // 0x8004D788: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8004D78C: nop

    // 0x8004D790: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8004D794: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D798: nop

    // 0x8004D79C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8004D7A0: jal         0x80098754
    // 0x8004D7A4: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8004D7A4: nop

    after_0:
    // 0x8004D7A8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8004D7AC: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8004D7B0: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8004D7B4: nop

    // 0x8004D7B8: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8004D7BC: beq         $t2, $zero, L_8004D7EC
    if (ctx->r10 == 0) {
        // 0x8004D7C0: nop

            goto L_8004D7EC;
    }
    // 0x8004D7C0: nop

L_8004D7C4:
    // 0x8004D7C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8004D7C8: jal         0x800499B0
    // 0x8004D7CC: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8004D7CC: nop

    after_1:
    // 0x8004D7D0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8004D7D4: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8004D7D8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8004D7DC: nop

    // 0x8004D7E0: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8004D7E4: bne         $t5, $zero, L_8004D7C4
    if (ctx->r13 != 0) {
        // 0x8004D7E8: nop

            goto L_8004D7C4;
    }
    // 0x8004D7E8: nop

L_8004D7EC:
    // 0x8004D7EC: jal         0x80058824
    // 0x8004D7F0: nop

    func_80058824(rdram, ctx);
        goto after_2;
    // 0x8004D7F0: nop

    after_2:
    // 0x8004D7F4: jal         0x80058B4C
    // 0x8004D7F8: nop

    func_80058B4C(rdram, ctx);
        goto after_3;
    // 0x8004D7F8: nop

    after_3:
    // 0x8004D7FC: jal         0x80058E78
    // 0x8004D800: nop

    func_80058E78(rdram, ctx);
        goto after_4;
    // 0x8004D800: nop

    after_4:
    // 0x8004D804: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8004D808:
    // 0x8004D808: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8004D80C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004D810: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004D814: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8004D818: lw          $t8, 0xE80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE80);
    // 0x8004D81C: nop

    // 0x8004D820: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8004D824: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8004D828: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004D82C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004D830: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D834: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004D838: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004D83C: bne         $t2, $zero, L_8004D84C
    if (ctx->r10 != 0) {
        // 0x8004D840: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004D84C;
    }
    // 0x8004D840: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004D844: beq         $t3, $zero, L_8004DBBC
    if (ctx->r11 == 0) {
        // 0x8004D848: nop

            goto L_8004DBBC;
    }
    // 0x8004D848: nop

L_8004D84C:
    // 0x8004D84C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8004D850: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004D854: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004D858: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004D85C: bne         $t8, $zero, L_8004DBB0
    if (ctx->r24 != 0) {
        // 0x8004D860: andi        $t9, $t7, 0x4
        ctx->r25 = ctx->r15 & 0X4;
            goto L_8004DBB0;
    }
    // 0x8004D860: andi        $t9, $t7, 0x4
    ctx->r25 = ctx->r15 & 0X4;
    // 0x8004D864: bne         $t9, $zero, L_8004DBB0
    if (ctx->r25 != 0) {
        // 0x8004D868: nop

            goto L_8004DBB0;
    }
    // 0x8004D868: nop

    // 0x8004D86C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8004D870: nop

    // 0x8004D874: addiu       $a0, $t5, 0x4C
    ctx->r4 = ADD32(ctx->r13, 0X4C);
    // 0x8004D878: jal         0x800B2748
    // 0x8004D87C: addiu       $a1, $t5, 0x50
    ctx->r5 = ADD32(ctx->r13, 0X50);
    func_800B2748(rdram, ctx);
        goto after_5;
    // 0x8004D87C: addiu       $a1, $t5, 0x50
    ctx->r5 = ADD32(ctx->r13, 0X50);
    after_5:
    // 0x8004D880: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8004D884: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8004D888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D88C: beq         $t0, $at, L_8004D920
    if (ctx->r8 == ctx->r1) {
        // 0x8004D890: nop

            goto L_8004D920;
    }
    // 0x8004D890: nop

    // 0x8004D894: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8004D898: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8004D89C: nop

    // 0x8004D8A0: sh          $t1, 0x48($t2)
    MEM_H(0X48, ctx->r10) = ctx->r9;
    // 0x8004D8A4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8A8: nop

    // 0x8004D8AC: lw          $t4, 0x4C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4C);
    // 0x8004D8B0: nop

    // 0x8004D8B4: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8004D8B8: nop

    // 0x8004D8BC: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
    // 0x8004D8C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8C4: nop

    // 0x8004D8C8: lw          $t7, 0x4C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4C);
    // 0x8004D8CC: nop

    // 0x8004D8D0: lwc1        $f6, 0xD0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x8004D8D4: nop

    // 0x8004D8D8: swc1        $f6, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f6.u32l;
    // 0x8004D8DC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8E0: nop

    // 0x8004D8E4: addiu       $a0, $t8, 0x50
    ctx->r4 = ADD32(ctx->r24, 0X50);
    // 0x8004D8E8: jal         0x8005A5F4
    // 0x8004D8EC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_6;
    // 0x8004D8EC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_6:
    // 0x8004D8F0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004D8F4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004D8F8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8FC: nop

    // 0x8004D900: bne         $t9, $t5, L_8004D918
    if (ctx->r25 != ctx->r13) {
        // 0x8004D904: nop

            goto L_8004D918;
    }
    // 0x8004D904: nop

    // 0x8004D908: jal         0x80056848
    // 0x8004D90C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80056848(rdram, ctx);
        goto after_7;
    // 0x8004D90C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8004D910: jal         0x8005A870
    // 0x8004D914: nop

    func_8005A870(rdram, ctx);
        goto after_8;
    // 0x8004D914: nop

    after_8:
L_8004D918:
    // 0x8004D918: b           L_8004DB90
    // 0x8004D91C: nop

        goto L_8004DB90;
    // 0x8004D91C: nop

L_8004D920:
    // 0x8004D920: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8004D924: nop

    // 0x8004D928: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004D92C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004D930: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x8004D934: ori         $t5, $t3, 0x2
    ctx->r13 = ctx->r11 | 0X2;
    // 0x8004D938: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8004D93C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8004D940: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004D944: nop

    // 0x8004D948: lh          $t7, 0x4A($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X4A);
    // 0x8004D94C: nop

    // 0x8004D950: andi        $t6, $t7, 0x1FFF
    ctx->r14 = ctx->r15 & 0X1FFF;
    // 0x8004D954: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8004D958: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004D95C: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8004D960: lh          $t9, 0x7C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X7C);
    // 0x8004D964: nop

    // 0x8004D968: bne         $t9, $at, L_8004D9A8
    if (ctx->r25 != ctx->r1) {
        // 0x8004D96C: nop

            goto L_8004D9A8;
    }
    // 0x8004D96C: nop

    // 0x8004D970: lh          $t2, 0x4A($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4A);
    // 0x8004D974: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x8004D978: bne         $t2, $at, L_8004D9A8
    if (ctx->r10 != ctx->r1) {
        // 0x8004D97C: nop

            goto L_8004D9A8;
    }
    // 0x8004D97C: nop

    // 0x8004D980: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004D984: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D988: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004D98C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004D990: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x8004D994: lui         $at, 0xFF7F
    ctx->r1 = S32(0XFF7F << 16);
    // 0x8004D998: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004D99C: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x8004D9A0: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8004D9A4: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
L_8004D9A8:
    // 0x8004D9A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004D9AC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004D9B0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8004D9B4: nop

    // 0x8004D9B8: bne         $t7, $t6, L_8004DB90
    if (ctx->r15 != ctx->r14) {
        // 0x8004D9BC: nop

            goto L_8004DB90;
    }
    // 0x8004D9BC: nop

    // 0x8004D9C0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004D9C4: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8004D9C8: beq         $t9, $at, L_8004D9F4
    if (ctx->r25 == ctx->r1) {
        // 0x8004D9CC: nop

            goto L_8004D9F4;
    }
    // 0x8004D9CC: nop

    // 0x8004D9D0: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x8004D9D4: beq         $t9, $at, L_8004D9F4
    if (ctx->r25 == ctx->r1) {
        // 0x8004D9D8: nop

            goto L_8004D9F4;
    }
    // 0x8004D9D8: nop

    // 0x8004D9DC: addiu       $at, $zero, 0x6B
    ctx->r1 = ADD32(0, 0X6B);
    // 0x8004D9E0: beq         $t9, $at, L_8004D9F4
    if (ctx->r25 == ctx->r1) {
        // 0x8004D9E4: nop

            goto L_8004D9F4;
    }
    // 0x8004D9E4: nop

    // 0x8004D9E8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8004D9EC: bne         $t9, $at, L_8004DA00
    if (ctx->r25 != ctx->r1) {
        // 0x8004D9F0: nop

            goto L_8004DA00;
    }
    // 0x8004D9F0: nop

L_8004D9F4:
    // 0x8004D9F4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8004D9F8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8004D9FC: sw          $t8, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r24;
L_8004DA00:
    // 0x8004DA00: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8004DA04: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x8004DA08: beq         $t4, $at, L_8004DA34
    if (ctx->r12 == ctx->r1) {
        // 0x8004DA0C: nop

            goto L_8004DA34;
    }
    // 0x8004DA0C: nop

    // 0x8004DA10: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x8004DA14: beq         $t4, $at, L_8004DA34
    if (ctx->r12 == ctx->r1) {
        // 0x8004DA18: nop

            goto L_8004DA34;
    }
    // 0x8004DA18: nop

    // 0x8004DA1C: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8004DA20: beq         $t4, $at, L_8004DA34
    if (ctx->r12 == ctx->r1) {
        // 0x8004DA24: nop

            goto L_8004DA34;
    }
    // 0x8004DA24: nop

    // 0x8004DA28: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8004DA2C: bne         $t4, $at, L_8004DA54
    if (ctx->r12 != ctx->r1) {
        // 0x8004DA30: nop

            goto L_8004DA54;
    }
    // 0x8004DA30: nop

L_8004DA34:
    // 0x8004DA34: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA38: nop

    // 0x8004DA3C: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8004DA40: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x8004DA44: or          $t6, $t0, $zero
    ctx->r14 = ctx->r8 | 0;
    // 0x8004DA48: xori        $t7, $t1, 0x8
    ctx->r15 = ctx->r9 ^ 0X8;
    // 0x8004DA4C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8004DA50: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_8004DA54:
    // 0x8004DA54: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA58: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004DA5C: lh          $a3, 0x4A($t3)
    ctx->r7 = MEM_H(ctx->r11, 0X4A);
    // 0x8004DA60: addiu       $a0, $sp, 0x1E
    ctx->r4 = ADD32(ctx->r29, 0X1E);
    // 0x8004DA64: andi        $t9, $a3, 0x1FFF
    ctx->r25 = ctx->r7 & 0X1FFF;
    // 0x8004DA68: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8004DA6C: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x8004DA70: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8004DA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004DA78: jal         0x800B3230
    // 0x8004DA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_9;
    // 0x8004DA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8004DA80: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x8004DA84: nop

    // 0x8004DA88: andi        $t4, $t2, 0x60
    ctx->r12 = ctx->r10 & 0X60;
    // 0x8004DA8C: sra         $t0, $t4, 5
    ctx->r8 = S32(SIGNED(ctx->r12) >> 5);
    // 0x8004DA90: bne         $t0, $zero, L_8004DAE4
    if (ctx->r8 != 0) {
        // 0x8004DA94: nop

            goto L_8004DAE4;
    }
    // 0x8004DA94: nop

    // 0x8004DA98: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA9C: nop

    // 0x8004DAA0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8004DAA4: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8004DAA8: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004DAAC: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x8004DAB0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004DAB4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004DAB8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8004DABC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DAC0: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004DAC4: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004DAC8: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004DACC: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8004DAD0: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8004DAD4: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004DAD8: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8004DADC: b           L_8004DB90
    // 0x8004DAE0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
        goto L_8004DB90;
    // 0x8004DAE0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_8004DAE4:
    // 0x8004DAE4: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x8004DAE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DAEC: andi        $t7, $t6, 0x60
    ctx->r15 = ctx->r14 & 0X60;
    // 0x8004DAF0: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x8004DAF4: bne         $t8, $at, L_8004DB48
    if (ctx->r24 != ctx->r1) {
        // 0x8004DAF8: nop

            goto L_8004DB48;
    }
    // 0x8004DAF8: nop

    // 0x8004DAFC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DB04: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8004DB08: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8004DB0C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004DB10: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8004DB14: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004DB18: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8004DB1C: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8004DB20: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB24: nop

    // 0x8004DB28: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8004DB2C: or          $t6, $t1, $zero
    ctx->r14 = ctx->r9 | 0;
    // 0x8004DB30: lw          $t1, 0x4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4);
    // 0x8004DB34: or          $t8, $t0, $zero
    ctx->r24 = ctx->r8 | 0;
    // 0x8004DB38: ori         $t9, $t1, 0x40
    ctx->r25 = ctx->r9 | 0X40;
    // 0x8004DB3C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8004DB40: b           L_8004DB90
    // 0x8004DB44: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_8004DB90;
    // 0x8004DB44: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8004DB48:
    // 0x8004DB48: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DB50: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8004DB54: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8004DB58: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004DB5C: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8004DB60: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004DB64: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8004DB68: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8004DB6C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DB74: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8004DB78: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8004DB7C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004DB80: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8004DB84: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004DB88: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8004DB8C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8004DB90:
    // 0x8004DB90: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB94: nop

    // 0x8004DB98: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004DB9C: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8004DBA0: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x8004DBA4: ori         $t5, $t3, 0x4
    ctx->r13 = ctx->r11 | 0X4;
    // 0x8004DBA8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8004DBAC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_8004DBB0:
    // 0x8004DBB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004DBB4: jal         0x8004DCE8
    // 0x8004DBB8: nop

    func_8004DCE8(rdram, ctx);
        goto after_10;
    // 0x8004DBB8: nop

    after_10:
L_8004DBBC:
    // 0x8004DBBC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8004DBC0: nop

    // 0x8004DBC4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004DBC8: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x8004DBCC: bne         $at, $zero, L_8004D808
    if (ctx->r1 != 0) {
        // 0x8004DBD0: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8004D808;
    }
    // 0x8004DBD0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8004DBD4: jal         0x80016138
    // 0x8004DBD8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_11;
    // 0x8004DBD8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_11:
    // 0x8004DBDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DBE0: beq         $v0, $at, L_8004DCAC
    if (ctx->r2 == ctx->r1) {
        // 0x8004DBE4: nop

            goto L_8004DCAC;
    }
    // 0x8004DBE4: nop

    // 0x8004DBE8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004DBEC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004DBF0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004DBF4: nop

    // 0x8004DBF8: andi        $t0, $t7, 0x2
    ctx->r8 = ctx->r15 & 0X2;
    // 0x8004DBFC: bne         $t0, $zero, L_8004DCAC
    if (ctx->r8 != 0) {
        // 0x8004DC00: nop

            goto L_8004DCAC;
    }
    // 0x8004DC00: nop

    // 0x8004DC04: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004DC08: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x8004DC0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004DC10: bne         $t2, $at, L_8004DCAC
    if (ctx->r10 != ctx->r1) {
        // 0x8004DC14: nop

            goto L_8004DCAC;
    }
    // 0x8004DC14: nop

    // 0x8004DC18: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004DC1C: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8004DC20: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8004DC24: bne         $t3, $at, L_8004DCAC
    if (ctx->r11 != ctx->r1) {
        // 0x8004DC28: nop

            goto L_8004DCAC;
    }
    // 0x8004DC28: nop

    // 0x8004DC2C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004DC30: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004DC34: nop

    // 0x8004DC38: beq         $t4, $zero, L_8004DCAC
    if (ctx->r12 == 0) {
        // 0x8004DC3C: nop

            goto L_8004DCAC;
    }
    // 0x8004DC3C: nop

    // 0x8004DC40: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004DC44: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8004DC48: nop

    // 0x8004DC4C: beq         $t5, $zero, L_8004DCAC
    if (ctx->r13 == 0) {
        // 0x8004DC50: nop

            goto L_8004DCAC;
    }
    // 0x8004DC50: nop

    // 0x8004DC54: lw          $t1, 0xA4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XA4);
    // 0x8004DC58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004DC5C: beq         $t1, $at, L_8004DCAC
    if (ctx->r9 == ctx->r1) {
        // 0x8004DC60: nop

            goto L_8004DCAC;
    }
    // 0x8004DC60: nop

    // 0x8004DC64: lw          $t8, 0xA4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XA4);
    // 0x8004DC68: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004DC6C: beq         $t8, $at, L_8004DCAC
    if (ctx->r24 == ctx->r1) {
        // 0x8004DC70: nop

            goto L_8004DCAC;
    }
    // 0x8004DC70: nop

    // 0x8004DC74: lh          $t9, 0xAC($t4)
    ctx->r25 = MEM_H(ctx->r12, 0XAC);
    // 0x8004DC78: nop

    // 0x8004DC7C: andi        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 & 0X20;
    // 0x8004DC80: beq         $t6, $zero, L_8004DCAC
    if (ctx->r14 == 0) {
        // 0x8004DC84: nop

            goto L_8004DCAC;
    }
    // 0x8004DC84: nop

    // 0x8004DC88: lh          $t7, 0xAC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XAC);
    // 0x8004DC8C: nop

    // 0x8004DC90: andi        $t0, $t7, 0x20
    ctx->r8 = ctx->r15 & 0X20;
    // 0x8004DC94: beq         $t0, $zero, L_8004DCAC
    if (ctx->r8 == 0) {
        // 0x8004DC98: nop

            goto L_8004DCAC;
    }
    // 0x8004DC98: nop

    // 0x8004DC9C: jal         0x8005C304
    // 0x8004DCA0: nop

    func_8005C304(rdram, ctx);
        goto after_12;
    // 0x8004DCA0: nop

    after_12:
    // 0x8004DCA4: jal         0x8005CDBC
    // 0x8004DCA8: nop

    func_8005CDBC(rdram, ctx);
        goto after_13;
    // 0x8004DCA8: nop

    after_13:
L_8004DCAC:
    // 0x8004DCAC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004DCB0: lw          $t2, 0x258C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X258C);
    // 0x8004DCB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DCB8: sw          $t2, 0xE58($at)
    MEM_W(0XE58, ctx->r1) = ctx->r10;
    // 0x8004DCBC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8004DCC0: jal         0x800499B0
    // 0x8004DCC4: nop

    func_800499B0(rdram, ctx);
        goto after_14;
    // 0x8004DCC4: nop

    after_14:
    // 0x8004DCC8: b           L_8004D7EC
    // 0x8004DCCC: nop

        goto L_8004D7EC;
    // 0x8004DCCC: nop

    // 0x8004DCD0: b           L_8004DCD8
    // 0x8004DCD4: nop

        goto L_8004DCD8;
    // 0x8004DCD4: nop

L_8004DCD8:
    // 0x8004DCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004DCDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8004DCE0: jr          $ra
    // 0x8004DCE4: nop

    return;
    // 0x8004DCE4: nop

;}
RECOMP_FUNC void func_8004DCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DCE8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8004DCEC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8004DCF0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004DCF4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004DCF8: bne         $t8, $zero, L_8004DD08
    if (ctx->r24 != 0) {
        // 0x8004DCFC: andi        $t9, $t7, 0x800
        ctx->r25 = ctx->r15 & 0X800;
            goto L_8004DD08;
    }
    // 0x8004DCFC: andi        $t9, $t7, 0x800
    ctx->r25 = ctx->r15 & 0X800;
    // 0x8004DD00: beq         $t9, $zero, L_8004DE94
    if (ctx->r25 == 0) {
        // 0x8004DD04: nop

            goto L_8004DE94;
    }
    // 0x8004DD04: nop

L_8004DD08:
    // 0x8004DD08: lw          $t0, 0x88($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X88);
    // 0x8004DD0C: nop

    // 0x8004DD10: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x8004DD14: bne         $at, $zero, L_8004DDD0
    if (ctx->r1 != 0) {
        // 0x8004DD18: nop

            goto L_8004DDD0;
    }
    // 0x8004DD18: nop

    // 0x8004DD1C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8004DD20: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8004DD24: nop

    // 0x8004DD28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004DD2C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8004DD30: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8004DD34: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8004DD38: nop

    // 0x8004DD3C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8004DD40: nop

    // 0x8004DD44: bc1f        L_8004DD64
    if (!c1cs) {
        // 0x8004DD48: nop

            goto L_8004DD64;
    }
    // 0x8004DD48: nop

    // 0x8004DD4C: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8004DD50: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8004DD54: nop

    // 0x8004DD58: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004DD5C: b           L_8004DD78
    // 0x8004DD60: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
        goto L_8004DD78;
    // 0x8004DD60: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_8004DD64:
    // 0x8004DD64: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8004DD68: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8004DD6C: nop

    // 0x8004DD70: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004DD74: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
L_8004DD78:
    // 0x8004DD78: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8004DD7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004DD80: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004DD84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004DD88: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8004DD8C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8004DD90: nop

    // 0x8004DD94: bc1f        L_8004DDC8
    if (!c1cs) {
        // 0x8004DD98: nop

            goto L_8004DDC8;
    }
    // 0x8004DD98: nop

    // 0x8004DD9C: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8004DDA0: nop

    // 0x8004DDA4: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8004DDA8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8004DDAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DDB0: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8004DDB4: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004DDB8: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8004DDBC: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004DDC0: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8004DDC4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
L_8004DDC8:
    // 0x8004DDC8: b           L_8004DE94
    // 0x8004DDCC: nop

        goto L_8004DE94;
    // 0x8004DDCC: nop

L_8004DDD0:
    // 0x8004DDD0: lw          $t1, 0x88($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X88);
    // 0x8004DDD4: nop

    // 0x8004DDD8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8004DDDC: bgez        $t1, L_8004DDF4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8004DDE0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8004DDF4;
    }
    // 0x8004DDE0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004DDE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8004DDE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004DDEC: nop

    // 0x8004DDF0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8004DDF4:
    // 0x8004DDF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DDF8: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004DDFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004DE00: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8004DE04: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004DE08: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004DE0C: nop

    // 0x8004DE10: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8004DE14: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004DE18: nop

    // 0x8004DE1C: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8004DE20: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8004DE24: beq         $t7, $zero, L_8004DE78
    if (ctx->r15 == 0) {
        // 0x8004DE28: nop

            goto L_8004DE78;
    }
    // 0x8004DE28: nop

    // 0x8004DE2C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8004DE30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004DE34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004DE38: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004DE3C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004DE40: nop

    // 0x8004DE44: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004DE48: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004DE4C: nop

    // 0x8004DE50: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8004DE54: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8004DE58: bne         $t7, $zero, L_8004DE70
    if (ctx->r15 != 0) {
        // 0x8004DE5C: nop

            goto L_8004DE70;
    }
    // 0x8004DE5C: nop

    // 0x8004DE60: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8004DE64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004DE68: b           L_8004DE88
    // 0x8004DE6C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8004DE88;
    // 0x8004DE6C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8004DE70:
    // 0x8004DE70: b           L_8004DE88
    // 0x8004DE74: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8004DE88;
    // 0x8004DE74: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8004DE78:
    // 0x8004DE78: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8004DE7C: nop

    // 0x8004DE80: bltz        $t7, L_8004DE70
    if (SIGNED(ctx->r15) < 0) {
        // 0x8004DE84: nop

            goto L_8004DE70;
    }
    // 0x8004DE84: nop

L_8004DE88:
    // 0x8004DE88: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004DE8C: sw          $t7, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r15;
    // 0x8004DE90: nop

L_8004DE94:
    // 0x8004DE94: b           L_8004DE9C
    // 0x8004DE98: nop

        goto L_8004DE9C;
    // 0x8004DE98: nop

L_8004DE9C:
    // 0x8004DE9C: jr          $ra
    // 0x8004DEA0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8004DEA0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8004DEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DEA4: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8004DEA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004DEAC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004DEB0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004DEB4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004DEB8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004DEBC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004DEC0: nop

    // 0x8004DEC4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8004DEC8: beq         $t8, $zero, L_8004DED8
    if (ctx->r24 == 0) {
        // 0x8004DECC: nop

            goto L_8004DED8;
    }
    // 0x8004DECC: nop

    // 0x8004DED0: b           L_8004EC94
    // 0x8004DED4: nop

        goto L_8004EC94;
    // 0x8004DED4: nop

L_8004DED8:
    // 0x8004DED8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004DEDC: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004DEE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004DEE4: bne         $t9, $at, L_8004DF08
    if (ctx->r25 != ctx->r1) {
        // 0x8004DEE8: nop

            goto L_8004DF08;
    }
    // 0x8004DEE8: nop

    // 0x8004DEEC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004DEF0: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004DEF4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8004DEF8: bne         $t0, $at, L_8004DF08
    if (ctx->r8 != ctx->r1) {
        // 0x8004DEFC: nop

            goto L_8004DF08;
    }
    // 0x8004DEFC: nop

    // 0x8004DF00: jal         0x8005CDBC
    // 0x8004DF04: nop

    func_8005CDBC(rdram, ctx);
        goto after_0;
    // 0x8004DF04: nop

    after_0:
L_8004DF08:
    // 0x8004DF08: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004DF0C: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8004DF10: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004DF14: bne         $t1, $at, L_8004DF84
    if (ctx->r9 != ctx->r1) {
        // 0x8004DF18: nop

            goto L_8004DF84;
    }
    // 0x8004DF18: nop

    // 0x8004DF1C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004DF20: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8004DF24: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004DF28: bne         $t2, $at, L_8004DF84
    if (ctx->r10 != ctx->r1) {
        // 0x8004DF2C: nop

            goto L_8004DF84;
    }
    // 0x8004DF2C: nop

    // 0x8004DF30: jal         0x8005F064
    // 0x8004DF34: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x8004DF34: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_1:
    // 0x8004DF38: bne         $v0, $zero, L_8004DF84
    if (ctx->r2 != 0) {
        // 0x8004DF3C: nop

            goto L_8004DF84;
    }
    // 0x8004DF3C: nop

    // 0x8004DF40: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004DF44: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004DF48: nop

    // 0x8004DF4C: lh          $t4, 0x48($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X48);
    // 0x8004DF50: nop

    // 0x8004DF54: slti        $at, $t4, 0x32
    ctx->r1 = SIGNED(ctx->r12) < 0X32 ? 1 : 0;
    // 0x8004DF58: bne         $at, $zero, L_8004DF84
    if (ctx->r1 != 0) {
        // 0x8004DF5C: nop

            goto L_8004DF84;
    }
    // 0x8004DF5C: nop

    // 0x8004DF60: jal         0x8005F0DC
    // 0x8004DF64: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    func_8005F0DC(rdram, ctx);
        goto after_2;
    // 0x8004DF64: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_2:
    // 0x8004DF68: jal         0x80021F20
    // 0x8004DF6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_3;
    // 0x8004DF6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x8004DF70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004DF74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DF78: sw          $t5, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = ctx->r13;
    // 0x8004DF7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DF80: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004DF84:
    // 0x8004DF84: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8004DF88: lw          $s0, 0x1634($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1634);
    // 0x8004DF8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DF90: beq         $s0, $at, L_8004DFB8
    if (ctx->r16 == ctx->r1) {
        // 0x8004DF94: nop

            goto L_8004DFB8;
    }
    // 0x8004DF94: nop

    // 0x8004DF98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004DF9C: beq         $s0, $at, L_8004E004
    if (ctx->r16 == ctx->r1) {
        // 0x8004DFA0: nop

            goto L_8004E004;
    }
    // 0x8004DFA0: nop

    // 0x8004DFA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004DFA8: beq         $s0, $at, L_8004E050
    if (ctx->r16 == ctx->r1) {
        // 0x8004DFAC: nop

            goto L_8004E050;
    }
    // 0x8004DFAC: nop

    // 0x8004DFB0: b           L_8004E090
    // 0x8004DFB4: nop

        goto L_8004E090;
    // 0x8004DFB4: nop

L_8004DFB8:
    // 0x8004DFB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004DFBC: lw          $t6, 0x1628($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1628);
    // 0x8004DFC0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8004DFC4: slt         $s1, $at, $t6
    ctx->r17 = SIGNED(ctx->r1) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004DFC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DFCC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004DFD0: beq         $s1, $zero, L_8004DFFC
    if (ctx->r17 == 0) {
        // 0x8004DFD4: sw          $t7, 0x1628($at)
        MEM_W(0X1628, ctx->r1) = ctx->r15;
            goto L_8004DFFC;
    }
    // 0x8004DFD4: sw          $t7, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = ctx->r15;
    // 0x8004DFD8: jal         0x80021ED0
    // 0x8004DFDC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_4;
    // 0x8004DFDC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_4:
    // 0x8004DFE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004DFE4: lw          $t8, 0x1634($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1634);
    // 0x8004DFE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DFEC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004DFF0: sw          $t9, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = ctx->r25;
    // 0x8004DFF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DFF8: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004DFFC:
    // 0x8004DFFC: b           L_8004E090
    // 0x8004E000: nop

        goto L_8004E090;
    // 0x8004E000: nop

L_8004E004:
    // 0x8004E004: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E008: lw          $t0, 0x1628($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1628);
    // 0x8004E00C: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8004E010: slt         $s0, $at, $t0
    ctx->r16 = SIGNED(ctx->r1) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004E014: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E018: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004E01C: beq         $s0, $zero, L_8004E048
    if (ctx->r16 == 0) {
        // 0x8004E020: sw          $t1, 0x1628($at)
        MEM_W(0X1628, ctx->r1) = ctx->r9;
            goto L_8004E048;
    }
    // 0x8004E020: sw          $t1, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = ctx->r9;
    // 0x8004E024: jal         0x80021F20
    // 0x8004E028: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_5;
    // 0x8004E028: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x8004E02C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E030: lw          $t2, 0x1634($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1634);
    // 0x8004E034: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E038: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8004E03C: sw          $t3, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = ctx->r11;
    // 0x8004E040: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E044: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004E048:
    // 0x8004E048: b           L_8004E090
    // 0x8004E04C: nop

        goto L_8004E090;
    // 0x8004E04C: nop

L_8004E050:
    // 0x8004E050: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E054: lw          $t4, 0x1628($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1628);
    // 0x8004E058: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004E05C: slt         $s0, $at, $t4
    ctx->r16 = SIGNED(ctx->r1) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8004E060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E064: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8004E068: beq         $s0, $zero, L_8004E088
    if (ctx->r16 == 0) {
        // 0x8004E06C: sw          $t5, 0x1628($at)
        MEM_W(0X1628, ctx->r1) = ctx->r13;
            goto L_8004E088;
    }
    // 0x8004E06C: sw          $t5, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = ctx->r13;
    // 0x8004E070: jal         0x80021ED0
    // 0x8004E074: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_6;
    // 0x8004E074: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_6:
    // 0x8004E078: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E07C: sw          $zero, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = 0;
    // 0x8004E080: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E084: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004E088:
    // 0x8004E088: b           L_8004E090
    // 0x8004E08C: nop

        goto L_8004E090;
    // 0x8004E08C: nop

L_8004E090:
    // 0x8004E090: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004E094: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004E098: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004E09C: nop

    // 0x8004E0A0: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x8004E0A4: bne         $t8, $zero, L_8004E2C0
    if (ctx->r24 != 0) {
        // 0x8004E0A8: nop

            goto L_8004E2C0;
    }
    // 0x8004E0A8: nop

    // 0x8004E0AC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004E0B0: lh          $t9, 0x721C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X721C);
    // 0x8004E0B4: nop

    // 0x8004E0B8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8004E0BC: beq         $at, $zero, L_8004E2C0
    if (ctx->r1 == 0) {
        // 0x8004E0C0: nop

            goto L_8004E2C0;
    }
    // 0x8004E0C0: nop

    // 0x8004E0C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E0C8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004E0CC: nop

    // 0x8004E0D0: beq         $t0, $zero, L_8004E2C0
    if (ctx->r8 == 0) {
        // 0x8004E0D4: nop

            goto L_8004E2C0;
    }
    // 0x8004E0D4: nop

    // 0x8004E0D8: jal         0x8005A578
    // 0x8004E0DC: nop

    func_8005A578(rdram, ctx);
        goto after_7;
    // 0x8004E0DC: nop

    after_7:
    // 0x8004E0E0: beq         $v0, $zero, L_8004E2C0
    if (ctx->r2 == 0) {
        // 0x8004E0E4: nop

            goto L_8004E2C0;
    }
    // 0x8004E0E4: nop

    // 0x8004E0E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004E0EC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004E0F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E0F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004E0F8: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8004E0FC: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x8004E100: andi        $t4, $t2, 0x8
    ctx->r12 = ctx->r10 & 0X8;
    // 0x8004E104: bne         $t4, $zero, L_8004E14C
    if (ctx->r12 != 0) {
        // 0x8004E108: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8004E14C;
    }
    // 0x8004E108: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004E10C: bne         $t5, $zero, L_8004E14C
    if (ctx->r13 != 0) {
        // 0x8004E110: nop

            goto L_8004E14C;
    }
    // 0x8004E110: nop

    // 0x8004E114: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8004E118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E11C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004E120: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8004E124: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004E128: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004E12C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004E130: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8004E134: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8004E138: lh          $t7, 0x3E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X3E);
    // 0x8004E13C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8004E140: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8004E144: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8004E148: sh          $t0, 0x3E($t6)
    MEM_H(0X3E, ctx->r14) = ctx->r8;
L_8004E14C:
    // 0x8004E14C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004E150: lw          $t1, 0x70E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E8);
    // 0x8004E154: nop

    // 0x8004E158: sltiu       $at, $t1, 0x7531
    ctx->r1 = ctx->r9 < 0X7531 ? 1 : 0;
    // 0x8004E15C: bne         $at, $zero, L_8004E178
    if (ctx->r1 != 0) {
        // 0x8004E160: nop

            goto L_8004E178;
    }
    // 0x8004E160: nop

    // 0x8004E164: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004E168: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004E16C: addiu       $t2, $zero, 0x7530
    ctx->r10 = ADD32(0, 0X7530);
    // 0x8004E170: b           L_8004E190
    // 0x8004E174: sh          $t2, 0x44($t3)
    MEM_H(0X44, ctx->r11) = ctx->r10;
        goto L_8004E190;
    // 0x8004E174: sh          $t2, 0x44($t3)
    MEM_H(0X44, ctx->r11) = ctx->r10;
L_8004E178:
    // 0x8004E178: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8004E17C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004E180: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8004E184: lw          $t4, 0x70E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70E8);
    // 0x8004E188: nop

    // 0x8004E18C: sh          $t4, 0x44($t5)
    MEM_H(0X44, ctx->r13) = ctx->r12;
L_8004E190:
    // 0x8004E190: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E194: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004E198: nop

    // 0x8004E19C: lh          $t7, 0x3E($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X3E);
    // 0x8004E1A0: nop

    // 0x8004E1A4: andi        $t9, $t7, 0x1F
    ctx->r25 = ctx->r15 & 0X1F;
    // 0x8004E1A8: bne         $t9, $zero, L_8004E2C0
    if (ctx->r25 != 0) {
        // 0x8004E1AC: nop

            goto L_8004E2C0;
    }
    // 0x8004E1AC: nop

    // 0x8004E1B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E1B4: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8004E1B8: nop

    // 0x8004E1BC: lh          $t6, 0x30($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X30);
    // 0x8004E1C0: nop

    // 0x8004E1C4: blez        $t6, L_8004E1F4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004E1C8: nop

            goto L_8004E1F4;
    }
    // 0x8004E1C8: nop

    // 0x8004E1CC: slti        $at, $t6, 0x2BC
    ctx->r1 = SIGNED(ctx->r14) < 0X2BC ? 1 : 0;
    // 0x8004E1D0: beq         $at, $zero, L_8004E1F4
    if (ctx->r1 == 0) {
        // 0x8004E1D4: nop

            goto L_8004E1F4;
    }
    // 0x8004E1D4: nop

    // 0x8004E1D8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004E1DC: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8004E1E0: nop

    // 0x8004E1E4: lh          $t2, 0x30($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X30);
    // 0x8004E1E8: nop

    // 0x8004E1EC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8004E1F0: sh          $t3, 0x30($t1)
    MEM_H(0X30, ctx->r9) = ctx->r11;
L_8004E1F4:
    // 0x8004E1F4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E1F8: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004E1FC: nop

    // 0x8004E200: lh          $t5, 0x32($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X32);
    // 0x8004E204: nop

    // 0x8004E208: blez        $t5, L_8004E238
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004E20C: nop

            goto L_8004E238;
    }
    // 0x8004E20C: nop

    // 0x8004E210: slti        $at, $t5, 0x2BC
    ctx->r1 = SIGNED(ctx->r13) < 0X2BC ? 1 : 0;
    // 0x8004E214: beq         $at, $zero, L_8004E238
    if (ctx->r1 == 0) {
        // 0x8004E218: nop

            goto L_8004E238;
    }
    // 0x8004E218: nop

    // 0x8004E21C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E220: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004E224: nop

    // 0x8004E228: lh          $t7, 0x32($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X32);
    // 0x8004E22C: nop

    // 0x8004E230: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8004E234: sh          $t9, 0x32($t8)
    MEM_H(0X32, ctx->r24) = ctx->r25;
L_8004E238:
    // 0x8004E238: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E23C: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8004E240: nop

    // 0x8004E244: lh          $t6, 0x34($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X34);
    // 0x8004E248: nop

    // 0x8004E24C: blez        $t6, L_8004E27C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004E250: nop

            goto L_8004E27C;
    }
    // 0x8004E250: nop

    // 0x8004E254: slti        $at, $t6, 0x2BC
    ctx->r1 = SIGNED(ctx->r14) < 0X2BC ? 1 : 0;
    // 0x8004E258: beq         $at, $zero, L_8004E27C
    if (ctx->r1 == 0) {
        // 0x8004E25C: nop

            goto L_8004E27C;
    }
    // 0x8004E25C: nop

    // 0x8004E260: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E264: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004E268: nop

    // 0x8004E26C: lh          $t3, 0x34($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X34);
    // 0x8004E270: nop

    // 0x8004E274: addiu       $t1, $t3, -0x1
    ctx->r9 = ADD32(ctx->r11, -0X1);
    // 0x8004E278: sh          $t1, 0x34($t2)
    MEM_H(0X34, ctx->r10) = ctx->r9;
L_8004E27C:
    // 0x8004E27C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E280: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004E284: nop

    // 0x8004E288: lh          $t5, 0x36($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X36);
    // 0x8004E28C: nop

    // 0x8004E290: blez        $t5, L_8004E2C0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004E294: nop

            goto L_8004E2C0;
    }
    // 0x8004E294: nop

    // 0x8004E298: slti        $at, $t5, 0x2BC
    ctx->r1 = SIGNED(ctx->r13) < 0X2BC ? 1 : 0;
    // 0x8004E29C: beq         $at, $zero, L_8004E2C0
    if (ctx->r1 == 0) {
        // 0x8004E2A0: nop

            goto L_8004E2C0;
    }
    // 0x8004E2A0: nop

    // 0x8004E2A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004E2A8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004E2AC: nop

    // 0x8004E2B0: lh          $t9, 0x36($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X36);
    // 0x8004E2B4: nop

    // 0x8004E2B8: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8004E2BC: sh          $t8, 0x36($t7)
    MEM_H(0X36, ctx->r15) = ctx->r24;
L_8004E2C0:
    // 0x8004E2C0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004E2C4: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8004E2C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004E2CC: bne         $t0, $at, L_8004E2F0
    if (ctx->r8 != ctx->r1) {
        // 0x8004E2D0: nop

            goto L_8004E2F0;
    }
    // 0x8004E2D0: nop

    // 0x8004E2D4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004E2D8: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8004E2DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004E2E0: bne         $t6, $at, L_8004E2F0
    if (ctx->r14 != ctx->r1) {
        // 0x8004E2E4: nop

            goto L_8004E2F0;
    }
    // 0x8004E2E4: nop

    // 0x8004E2E8: jal         0x800226F4
    // 0x8004E2EC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800226F4(rdram, ctx);
        goto after_8;
    // 0x8004E2EC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_8:
L_8004E2F0:
    // 0x8004E2F0: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
L_8004E2F4:
    // 0x8004E2F4: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004E2F8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E2FC: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8004E300: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8004E304: lw          $t2, 0xE80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE80);
    // 0x8004E308: nop

    // 0x8004E30C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8004E310: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E314: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004E318: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8004E31C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004E320: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004E324: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8004E328: bne         $t0, $zero, L_8004E338
    if (ctx->r8 != 0) {
        // 0x8004E32C: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8004E338;
    }
    // 0x8004E32C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8004E330: beq         $t1, $zero, L_8004EB34
    if (ctx->r9 == 0) {
        // 0x8004E334: nop

            goto L_8004EB34;
    }
    // 0x8004E334: nop

L_8004E338:
    // 0x8004E338: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004E33C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004E340: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E344: nop

    // 0x8004E348: bne         $t5, $t7, L_8004E7BC
    if (ctx->r13 != ctx->r15) {
        // 0x8004E34C: nop

            goto L_8004E7BC;
    }
    // 0x8004E34C: nop

    // 0x8004E350: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004E354: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004E358: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004E35C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004E360: bne         $t2, $zero, L_8004E7BC
    if (ctx->r10 != 0) {
        // 0x8004E364: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8004E7BC;
    }
    // 0x8004E364: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8004E368: bne         $t3, $zero, L_8004E7BC
    if (ctx->r11 != 0) {
        // 0x8004E36C: nop

            goto L_8004E7BC;
    }
    // 0x8004E36C: nop

    // 0x8004E370: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E374: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E378: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004E37C: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8004E380: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8004E384: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8004E388: bne         $t0, $zero, L_8004E7BC
    if (ctx->r8 != 0) {
        // 0x8004E38C: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8004E7BC;
    }
    // 0x8004E38C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8004E390: bne         $t1, $zero, L_8004E7BC
    if (ctx->r9 != 0) {
        // 0x8004E394: nop

            goto L_8004E7BC;
    }
    // 0x8004E394: nop

    // 0x8004E398: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004E39C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004E3A0: lh          $t6, 0x7254($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7254);
    // 0x8004E3A4: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8004E3A8: nop

    // 0x8004E3AC: bne         $t5, $t6, L_8004E7BC
    if (ctx->r13 != ctx->r14) {
        // 0x8004E3B0: nop

            goto L_8004E7BC;
    }
    // 0x8004E3B0: nop

    // 0x8004E3B4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004E3B8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004E3BC: lh          $t2, 0x725C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X725C);
    // 0x8004E3C0: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8004E3C4: nop

    // 0x8004E3C8: bne         $t7, $t2, L_8004E7BC
    if (ctx->r15 != ctx->r10) {
        // 0x8004E3CC: nop

            goto L_8004E7BC;
    }
    // 0x8004E3CC: nop

    // 0x8004E3D0: andi        $t3, $t5, 0x8000
    ctx->r11 = ctx->r13 & 0X8000;
    // 0x8004E3D4: bne         $t3, $zero, L_8004E7BC
    if (ctx->r11 != 0) {
        // 0x8004E3D8: nop

            goto L_8004E7BC;
    }
    // 0x8004E3D8: nop

    // 0x8004E3DC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E3E0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E3E4: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x8004E3E8: lh          $t8, 0x4A($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X4A);
    // 0x8004E3EC: nop

    // 0x8004E3F0: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x8004E3F4: beq         $t9, $at, L_8004E41C
    if (ctx->r25 == ctx->r1) {
        // 0x8004E3F8: nop

            goto L_8004E41C;
    }
    // 0x8004E3F8: nop

    // 0x8004E3FC: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x8004E400: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004E404: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004E408: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004E40C: bne         $t6, $zero, L_8004E554
    if (ctx->r14 != 0) {
        // 0x8004E410: and         $t7, $t1, $at
        ctx->r15 = ctx->r9 & ctx->r1;
            goto L_8004E554;
    }
    // 0x8004E410: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004E414: bne         $t7, $zero, L_8004E554
    if (ctx->r15 != 0) {
        // 0x8004E418: nop

            goto L_8004E554;
    }
    // 0x8004E418: nop

L_8004E41C:
    // 0x8004E41C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E420: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004E424: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004E428: lw          $a1, 0x4C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4C);
    // 0x8004E42C: lw          $a2, 0x50($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X50);
    // 0x8004E430: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E434: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8004E438: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004E43C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8004E440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8004E444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8004E448: jal         0x80077FF0
    // 0x8004E44C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80077FF0(rdram, ctx);
        goto after_9;
    // 0x8004E44C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8004E450: beq         $v0, $zero, L_8004E54C
    if (ctx->r2 == 0) {
        // 0x8004E454: nop

            goto L_8004E54C;
    }
    // 0x8004E454: nop

    // 0x8004E458: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004E45C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004E460: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004E464: lw          $a3, 0x4C($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4C);
    // 0x8004E468: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E46C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004E470: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8004E474: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8004E478: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8004E47C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8004E480: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8004E484: jal         0x80078168
    // 0x8004E488: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80078168(rdram, ctx);
        goto after_10;
    // 0x8004E488: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x8004E48C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004E490: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004E494: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004E498: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8004E49C: nop

    // 0x8004E4A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E4A4: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x8004E4A8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E4AC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E4B0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004E4B4: lwc1        $f10, 0x10($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8004E4B8: nop

    // 0x8004E4BC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004E4C0: swc1        $f18, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f18.u32l;
    // 0x8004E4C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E4C8: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x8004E4CC: addiu       $t7, $t1, 0xA8
    ctx->r15 = ADD32(ctx->r9, 0XA8);
    // 0x8004E4D0: addiu       $t0, $t0, 0x12A8
    ctx->r8 = ADD32(ctx->r8, 0X12A8);
L_8004E4D4:
    // 0x8004E4D4: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8004E4D8: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8004E4DC: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8004E4E0: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x8004E4E4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8004E4E8: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8004E4EC: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x8004E4F0: bne         $t1, $t7, L_8004E4D4
    if (ctx->r9 != ctx->r15) {
        // 0x8004E4F4: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8004E4D4;
    }
    // 0x8004E4F4: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x8004E4F8: jal         0x8005A6BC
    // 0x8004E4FC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8005A6BC(rdram, ctx);
        goto after_11;
    // 0x8004E4FC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_11:
    // 0x8004E500: beq         $v0, $zero, L_8004E54C
    if (ctx->r2 == 0) {
        // 0x8004E504: nop

            goto L_8004E54C;
    }
    // 0x8004E504: nop

    // 0x8004E508: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E50C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004E510: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x8004E514: lh          $t5, 0x4A($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X4A);
    // 0x8004E518: nop

    // 0x8004E51C: andi        $t3, $t5, 0x1FFF
    ctx->r11 = ctx->r13 & 0X1FFF;
    // 0x8004E520: beq         $t3, $at, L_8004E54C
    if (ctx->r11 == ctx->r1) {
        // 0x8004E524: nop

            goto L_8004E54C;
    }
    // 0x8004E524: nop

    // 0x8004E528: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E52C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004E530: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004E534: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8004E538: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8004E53C: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x8004E540: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8004E544: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8004E548: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_8004E54C:
    // 0x8004E54C: b           L_8004E7BC
    // 0x8004E550: nop

        goto L_8004E7BC;
    // 0x8004E550: nop

L_8004E554:
    // 0x8004E554: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004E558: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004E55C: lh          $t1, 0x7254($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7254);
    // 0x8004E560: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004E564: nop

    // 0x8004E568: bne         $t9, $t1, L_8004E7BC
    if (ctx->r25 != ctx->r9) {
        // 0x8004E56C: nop

            goto L_8004E7BC;
    }
    // 0x8004E56C: nop

    // 0x8004E570: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004E574: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004E578: lh          $t2, 0x725C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X725C);
    // 0x8004E57C: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004E580: nop

    // 0x8004E584: bne         $t0, $t2, L_8004E7BC
    if (ctx->r8 != ctx->r10) {
        // 0x8004E588: nop

            goto L_8004E7BC;
    }
    // 0x8004E588: nop

    // 0x8004E58C: andi        $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 & 0X8000;
    // 0x8004E590: bne         $t3, $zero, L_8004E7BC
    if (ctx->r11 != 0) {
        // 0x8004E594: nop

            goto L_8004E7BC;
    }
    // 0x8004E594: nop

    // 0x8004E598: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E59C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E5A0: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004E5A4: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004E5A8: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x8004E5AC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004E5B0: bne         $t8, $zero, L_8004E5E0
    if (ctx->r24 != 0) {
        // 0x8004E5B4: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004E5E0;
    }
    // 0x8004E5B4: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004E5B8: bne         $t9, $zero, L_8004E5E0
    if (ctx->r25 != 0) {
        // 0x8004E5BC: nop

            goto L_8004E5E0;
    }
    // 0x8004E5BC: nop

    // 0x8004E5C0: lh          $t5, 0x4A($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4A);
    // 0x8004E5C4: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8004E5C8: andi        $t1, $t5, 0x1FFF
    ctx->r9 = ctx->r13 & 0X1FFF;
    // 0x8004E5CC: beq         $t1, $at, L_8004E5E0
    if (ctx->r9 == ctx->r1) {
        // 0x8004E5D0: nop

            goto L_8004E5E0;
    }
    // 0x8004E5D0: nop

    // 0x8004E5D4: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8004E5D8: bne         $t1, $at, L_8004E7BC
    if (ctx->r9 != ctx->r1) {
        // 0x8004E5DC: nop

            goto L_8004E7BC;
    }
    // 0x8004E5DC: nop

L_8004E5E0:
    // 0x8004E5E0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E5E4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004E5E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004E5EC: lw          $a1, 0x4C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4C);
    // 0x8004E5F0: lw          $a2, 0x50($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X50);
    // 0x8004E5F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E5F8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8004E5FC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8004E600: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8004E604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8004E608: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8004E60C: jal         0x80077FF0
    // 0x8004E610: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80077FF0(rdram, ctx);
        goto after_12;
    // 0x8004E610: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8004E614: beq         $v0, $zero, L_8004E7BC
    if (ctx->r2 == 0) {
        // 0x8004E618: nop

            goto L_8004E7BC;
    }
    // 0x8004E618: nop

    // 0x8004E61C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004E620: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8004E624: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004E628: bne         $t3, $at, L_8004E68C
    if (ctx->r11 != ctx->r1) {
        // 0x8004E62C: nop

            goto L_8004E68C;
    }
    // 0x8004E62C: nop

    // 0x8004E630: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004E634: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8004E638: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x8004E63C: bne         $t6, $at, L_8004E68C
    if (ctx->r14 != ctx->r1) {
        // 0x8004E640: nop

            goto L_8004E68C;
    }
    // 0x8004E640: nop

    // 0x8004E644: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004E648: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004E64C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E650: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8004E654: nop

    // 0x8004E658: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8004E65C: nop

    // 0x8004E660: bc1f        L_8004E68C
    if (!c1cs) {
        // 0x8004E664: nop

            goto L_8004E68C;
    }
    // 0x8004E664: nop

    // 0x8004E668: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8004E66C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004E670: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x8004E674: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004E678: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004E67C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E680: ori         $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 | 0X8000;
    // 0x8004E684: b           L_8004E7BC
    // 0x8004E688: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
        goto L_8004E7BC;
    // 0x8004E688: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
L_8004E68C:
    // 0x8004E68C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004E690: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8004E694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004E698: bne         $t5, $at, L_8004E6FC
    if (ctx->r13 != ctx->r1) {
        // 0x8004E69C: nop

            goto L_8004E6FC;
    }
    // 0x8004E69C: nop

    // 0x8004E6A0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004E6A4: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x8004E6A8: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x8004E6AC: bne         $t1, $at, L_8004E6FC
    if (ctx->r9 != ctx->r1) {
        // 0x8004E6B0: nop

            goto L_8004E6FC;
    }
    // 0x8004E6B0: nop

    // 0x8004E6B4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E6B8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004E6BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E6C0: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8004E6C4: nop

    // 0x8004E6C8: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8004E6CC: nop

    // 0x8004E6D0: bc1f        L_8004E6FC
    if (!c1cs) {
        // 0x8004E6D4: nop

            goto L_8004E6FC;
    }
    // 0x8004E6D4: nop

    // 0x8004E6D8: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x8004E6DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004E6E0: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
    // 0x8004E6E4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004E6E8: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8004E6EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E6F0: ori         $t6, $t3, 0x8000
    ctx->r14 = ctx->r11 | 0X8000;
    // 0x8004E6F4: b           L_8004E7BC
    // 0x8004E6F8: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
        goto L_8004E7BC;
    // 0x8004E6F8: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
L_8004E6FC:
    // 0x8004E6FC: lh          $t7, 0x68($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X68);
    // 0x8004E700: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E704: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x8004E708: sh          $t8, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r24;
    // 0x8004E70C: lh          $t9, 0x6A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6A);
    // 0x8004E710: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E714: ori         $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 | 0X8000;
    // 0x8004E718: sh          $t4, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r12;
    // 0x8004E71C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004E720: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x8004E724: addiu       $t3, $t1, 0xA8
    ctx->r11 = ADD32(ctx->r9, 0XA8);
    // 0x8004E728: addiu       $t5, $t5, 0x12A8
    ctx->r13 = ADD32(ctx->r13, 0X12A8);
L_8004E72C:
    // 0x8004E72C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8004E730: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8004E734: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8004E738: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x8004E73C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8004E740: sw          $at, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r1;
    // 0x8004E744: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x8004E748: bne         $t1, $t3, L_8004E72C
    if (ctx->r9 != ctx->r11) {
        // 0x8004E74C: sw          $at, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r1;
            goto L_8004E72C;
    }
    // 0x8004E74C: sw          $at, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r1;
    // 0x8004E750: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
    // 0x8004E754: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E758: sh          $t6, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r14;
    // 0x8004E75C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E760: sb          $t6, 0xD9C($at)
    MEM_B(0XD9C, ctx->r1) = ctx->r14;
    // 0x8004E764: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004E768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E76C: sb          $t7, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r15;
    // 0x8004E770: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E774: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004E778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E77C: lh          $t9, 0x4A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4A);
    // 0x8004E780: nop

    // 0x8004E784: sh          $t9, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r25;
    // 0x8004E788: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E78C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E790: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E794: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8004E798: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8004E79C: and         $t0, $t2, $at
    ctx->r8 = ctx->r10 & ctx->r1;
    // 0x8004E7A0: lui         $at, 0xFFDF
    ctx->r1 = S32(0XFFDF << 16);
    // 0x8004E7A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004E7A8: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004E7AC: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8004E7B0: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x8004E7B4: jal         0x80031914
    // 0x8004E7B8: nop

    func_80031914(rdram, ctx);
        goto after_13;
    // 0x8004E7B8: nop

    after_13:
L_8004E7BC:
    // 0x8004E7BC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E7C0: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004E7C4: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004E7C8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004E7CC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004E7D0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004E7D4: bne         $t8, $zero, L_8004E7E4
    if (ctx->r24 != 0) {
        // 0x8004E7D8: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004E7E4;
    }
    // 0x8004E7D8: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004E7DC: beq         $t9, $zero, L_8004EB34
    if (ctx->r25 == 0) {
        // 0x8004E7E0: nop

            goto L_8004EB34;
    }
    // 0x8004E7E0: nop

L_8004E7E4:
    // 0x8004E7E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E7E8: jal         0x8004ECA8
    // 0x8004E7EC: nop

    func_8004ECA8(rdram, ctx);
        goto after_14;
    // 0x8004E7EC: nop

    after_14:
    // 0x8004E7F0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E7F4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004E7F8: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004E7FC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8004E800: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004E804: bne         $t4, $zero, L_8004E814
    if (ctx->r12 != 0) {
        // 0x8004E808: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_8004E814;
    }
    // 0x8004E808: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004E80C: beq         $t5, $zero, L_8004E850
    if (ctx->r13 == 0) {
        // 0x8004E810: nop

            goto L_8004E850;
    }
    // 0x8004E810: nop

L_8004E814:
    // 0x8004E814: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E818: nop

    // 0x8004E81C: lw          $t6, 0x8C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8C);
    // 0x8004E820: nop

    // 0x8004E824: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004E828: sw          $t7, 0x8C($t3)
    MEM_W(0X8C, ctx->r11) = ctx->r15;
    // 0x8004E82C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E830: nop

    // 0x8004E834: lw          $t9, 0x8C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8C);
    // 0x8004E838: nop

    // 0x8004E83C: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x8004E840: beq         $t2, $zero, L_8004E850
    if (ctx->r10 == 0) {
        // 0x8004E844: nop

            goto L_8004E850;
    }
    // 0x8004E844: nop

    // 0x8004E848: b           L_8004EB10
    // 0x8004E84C: nop

        goto L_8004EB10;
    // 0x8004E84C: nop

L_8004E850:
    // 0x8004E850: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E854: sw          $zero, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = 0;
    // 0x8004E858: lh          $t1, 0x48($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X48);
    // 0x8004E85C: nop

    // 0x8004E860: blez        $t1, L_8004EB10
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8004E864: nop

            goto L_8004EB10;
    }
    // 0x8004E864: nop

L_8004E868:
    // 0x8004E868: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E86C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E870: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004E874: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E878: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004E87C: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E880: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E884: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8004E888: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8004E88C: addu        $t3, $t5, $t7
    ctx->r11 = ADD32(ctx->r13, ctx->r15);
    // 0x8004E890: swc1        $f4, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f4.u32l;
    // 0x8004E894: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E898: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E89C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8004E8A0: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E8A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8004E8A8: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x8004E8AC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E8B0: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8004E8B4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8004E8B8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004E8BC: swc1        $f6, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f6.u32l;
    // 0x8004E8C0: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E8C4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E8C8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8004E8CC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8004E8D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004E8D4: lw          $t6, 0x4C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E8D8: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8004E8DC: lwc1        $f8, 0x14($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8004E8E0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8004E8E4: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x8004E8E8: swc1        $f8, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f8.u32l;
    // 0x8004E8EC: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E8F0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E8F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8004E8F8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8004E8FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8004E900: lw          $t2, 0x4C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X4C);
    // 0x8004E904: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8004E908: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8004E90C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8004E910: addu        $t1, $t2, $t0
    ctx->r9 = ADD32(ctx->r10, ctx->r8);
    // 0x8004E914: swc1        $f10, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f10.u32l;
    // 0x8004E918: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E91C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E920: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004E924: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E928: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004E92C: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E930: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E934: lwc1        $f16, 0x18($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8004E938: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8004E93C: addu        $t3, $t5, $t7
    ctx->r11 = ADD32(ctx->r13, ctx->r15);
    // 0x8004E940: swc1        $f16, 0xF4($t3)
    MEM_W(0XF4, ctx->r11) = ctx->f16.u32l;
    // 0x8004E944: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E948: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E94C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8004E950: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E954: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8004E958: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x8004E95C: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E960: lwc1        $f18, 0x1C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8004E964: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8004E968: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004E96C: swc1        $f18, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f18.u32l;
    // 0x8004E970: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E974: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E978: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8004E97C: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x8004E980: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004E984: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E988: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x8004E98C: lw          $t6, 0x40($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X40);
    // 0x8004E990: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8004E994: addu        $t8, $t5, $t3
    ctx->r24 = ADD32(ctx->r13, ctx->r11);
    // 0x8004E998: sh          $t6, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r14;
    // 0x8004E99C: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E9A0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E9A4: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8004E9A8: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8004E9AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8004E9B0: lw          $t0, 0x4C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4C);
    // 0x8004E9B4: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8004E9B8: lw          $t9, 0x3C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X3C);
    // 0x8004E9BC: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8004E9C0: addu        $t7, $t0, $t4
    ctx->r15 = ADD32(ctx->r8, ctx->r12);
    // 0x8004E9C4: sw          $t9, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r25;
    // 0x8004E9C8: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E9CC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E9D0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8004E9D4: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8004E9D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004E9DC: lw          $t3, 0x4C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4C);
    // 0x8004E9E0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8004E9E4: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8004E9E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E9EC: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x8004E9F0: lwc1        $f4, 0xCC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8004E9F4: lwc1        $f6, 0x125C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X125C);
    // 0x8004E9F8: nop

    // 0x8004E9FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004EA00: swc1        $f8, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f8.u32l;
    // 0x8004EA04: jal         0x800C1754
    // 0x8004EA08: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_15;
    // 0x8004EA08: nop

    after_15:
    // 0x8004EA0C: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EA10: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EA14: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8004EA18: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8004EA1C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004EA20: lw          $t0, 0x4C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4C);
    // 0x8004EA24: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8004EA28: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8004EA2C: jal         0x8009A14C
    // 0x8004EA30: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    func_8009A14C(rdram, ctx);
        goto after_16;
    // 0x8004EA30: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    after_16:
    // 0x8004EA34: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EA38: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EA3C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8004EA40: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8004EA44: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004EA48: lw          $t5, 0x4C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4C);
    // 0x8004EA4C: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8004EA50: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8004EA54: addu        $t8, $t5, $t3
    ctx->r24 = ADD32(ctx->r13, ctx->r11);
    // 0x8004EA58: lwc1        $f12, 0xF0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8004EA5C: jal         0x800C2780
    // 0x8004EA60: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_17;
    // 0x8004EA60: nop

    after_17:
    // 0x8004EA64: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8004EA68: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8004EA6C: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x8004EA70: nop

    // 0x8004EA74: andi        $t4, $t1, 0x200
    ctx->r12 = ctx->r9 & 0X200;
    // 0x8004EA78: bne         $t4, $zero, L_8004EAA8
    if (ctx->r12 != 0) {
        // 0x8004EA7C: nop

            goto L_8004EAA8;
    }
    // 0x8004EA7C: nop

    // 0x8004EA80: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EA84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EA88: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8004EA8C: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8004EA90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004EA94: lw          $t9, 0x4C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4C);
    // 0x8004EA98: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8004EA9C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8004EAA0: jal         0x800997D8
    // 0x8004EAA4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    func_800997D8(rdram, ctx);
        goto after_18;
    // 0x8004EAA4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    after_18:
L_8004EAA8:
    // 0x8004EAA8: jal         0x800C1A28
    // 0x8004EAAC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_19;
    // 0x8004EAAC: nop

    after_19:
    // 0x8004EAB0: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EAB4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EAB8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8004EABC: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x8004EAC0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8004EAC4: lw          $t3, 0x4C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4C);
    // 0x8004EAC8: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x8004EACC: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8004EAD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EAD4: addu        $t1, $t3, $t2
    ctx->r9 = ADD32(ctx->r11, ctx->r10);
    // 0x8004EAD8: lwc1        $f10, 0xCC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8004EADC: lwc1        $f16, 0x125C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X125C);
    // 0x8004EAE0: nop

    // 0x8004EAE4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8004EAE8: swc1        $f18, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f18.u32l;
    // 0x8004EAEC: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EAF0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EAF4: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x8004EAF8: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    // 0x8004EAFC: lh          $t9, 0x48($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X48);
    // 0x8004EB00: nop

    // 0x8004EB04: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8004EB08: bne         $at, $zero, L_8004E868
    if (ctx->r1 != 0) {
        // 0x8004EB0C: nop

            goto L_8004E868;
    }
    // 0x8004EB0C: nop

L_8004EB10:
    // 0x8004EB10: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EB14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EB18: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004EB1C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004EB20: and         $t2, $t8, $at
    ctx->r10 = ctx->r24 & ctx->r1;
    // 0x8004EB24: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8004EB28: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8004EB2C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8004EB30: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
L_8004EB34:
    // 0x8004EB34: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004EB38: nop

    // 0x8004EB3C: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x8004EB40: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8004EB44: bne         $at, $zero, L_8004E2F4
    if (ctx->r1 != 0) {
        // 0x8004EB48: sw          $t1, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->r9;
            goto L_8004E2F4;
    }
    // 0x8004EB48: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x8004EB4C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8004EB50: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8004EB54: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x8004EB58: nop

    // 0x8004EB5C: andi        $t0, $t7, 0x40
    ctx->r8 = ctx->r15 & 0X40;
    // 0x8004EB60: bne         $t0, $zero, L_8004EC38
    if (ctx->r8 != 0) {
        // 0x8004EB64: nop

            goto L_8004EC38;
    }
    // 0x8004EB64: nop

    // 0x8004EB68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004EB6C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004EB70: nop

    // 0x8004EB74: beq         $t8, $zero, L_8004EC38
    if (ctx->r24 == 0) {
        // 0x8004EB78: nop

            goto L_8004EC38;
    }
    // 0x8004EB78: nop

    // 0x8004EB7C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8004EB80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EB84: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004EB88: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8004EB8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004EB90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004EB94: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004EB98: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8004EB9C: lw          $t9, 0x6CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CC);
    // 0x8004EBA0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8004EBA4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8004EBA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EBAC: subu        $t6, $t9, $t3
    ctx->r14 = SUB32(ctx->r25, ctx->r11);
    // 0x8004EBB0: sw          $t6, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r14;
    // 0x8004EBB4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004EBB8: lw          $t5, 0x6CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6CC);
    // 0x8004EBBC: nop

    // 0x8004EBC0: bgez        $t5, L_8004EBD0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8004EBC4: nop

            goto L_8004EBD0;
    }
    // 0x8004EBC4: nop

    // 0x8004EBC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EBCC: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
L_8004EBD0:
    // 0x8004EBD0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004EBD4: lw          $t1, 0xCD4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCD4);
    // 0x8004EBD8: nop

    // 0x8004EBDC: beq         $t1, $zero, L_8004EC1C
    if (ctx->r9 == 0) {
        // 0x8004EBE0: nop

            goto L_8004EC1C;
    }
    // 0x8004EBE0: nop

    // 0x8004EBE4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004EBE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EBEC: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004EBF0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8004EBF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004EBF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004EBFC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004EC00: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004EC04: lw          $t4, 0xCD4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCD4);
    // 0x8004EC08: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004EC0C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004EC10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC14: subu        $t8, $t4, $t0
    ctx->r24 = SUB32(ctx->r12, ctx->r8);
    // 0x8004EC18: sw          $t8, 0xCD4($at)
    MEM_W(0XCD4, ctx->r1) = ctx->r24;
L_8004EC1C:
    // 0x8004EC1C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004EC20: lw          $t2, 0xCD4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD4);
    // 0x8004EC24: nop

    // 0x8004EC28: bgez        $t2, L_8004EC38
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8004EC2C: nop

            goto L_8004EC38;
    }
    // 0x8004EC2C: nop

    // 0x8004EC30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC34: sw          $zero, 0xCD4($at)
    MEM_W(0XCD4, ctx->r1) = 0;
L_8004EC38:
    // 0x8004EC38: jal         0x800C4240
    // 0x8004EC3C: nop

    guRandom(rdram, ctx);
        goto after_20;
    // 0x8004EC3C: nop

    after_20:
    // 0x8004EC40: addiu       $at, $zero, 0x2710
    ctx->r1 = ADD32(0, 0X2710);
    // 0x8004EC44: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8004EC48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC4C: mfhi        $t9
    ctx->r25 = hi;
    // 0x8004EC50: sw          $t9, 0x678($at)
    MEM_W(0X678, ctx->r1) = ctx->r25;
    // 0x8004EC54: nop

    // 0x8004EC58: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004EC5C: lw          $t3, 0x678($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X678);
    // 0x8004EC60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004EC64: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8004EC68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC6C: mflo        $t6
    ctx->r14 = lo;
    // 0x8004EC70: sw          $t6, 0x670($at)
    MEM_W(0X670, ctx->r1) = ctx->r14;
    // 0x8004EC74: nop

    // 0x8004EC78: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004EC7C: lw          $t5, 0x1268($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1268);
    // 0x8004EC80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC84: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x8004EC88: sw          $t1, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r9;
    // 0x8004EC8C: b           L_8004EC94
    // 0x8004EC90: nop

        goto L_8004EC94;
    // 0x8004EC90: nop

L_8004EC94:
    // 0x8004EC94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004EC98: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004EC9C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004ECA0: jr          $ra
    // 0x8004ECA4: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8004ECA4: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_8004ECA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004ECA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004ECAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004ECB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004ECB4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8004ECB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004ECBC: lh          $t7, 0x7C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X7C);
    // 0x8004ECC0: nop

    // 0x8004ECC4: beq         $t7, $at, L_8004ECD4
    if (ctx->r15 == ctx->r1) {
        // 0x8004ECC8: nop

            goto L_8004ECD4;
    }
    // 0x8004ECC8: nop

    // 0x8004ECCC: b           L_8004EF80
    // 0x8004ECD0: nop

        goto L_8004EF80;
    // 0x8004ECD0: nop

L_8004ECD4:
    // 0x8004ECD4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8004ECD8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004ECDC: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004ECE0: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8004ECE4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004ECE8: bne         $t2, $zero, L_8004ECF8
    if (ctx->r10 != 0) {
        // 0x8004ECEC: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004ECF8;
    }
    // 0x8004ECEC: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004ECF0: beq         $t3, $zero, L_8004EDEC
    if (ctx->r11 == 0) {
        // 0x8004ECF4: nop

            goto L_8004EDEC;
    }
    // 0x8004ECF4: nop

L_8004ECF8:
    // 0x8004ECF8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004ECFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004ED00: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004ED04: lwc1        $f4, 0xA0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XA0);
    // 0x8004ED08: lwc1        $f10, 0x34($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X34);
    // 0x8004ED0C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004ED10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004ED14: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8004ED18: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x8004ED1C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8004ED20: lwc1        $f6, -0x110C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X110C);
    // 0x8004ED24: lwc1        $f18, 0x34($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X34);
    // 0x8004ED28: lwc1        $f7, -0x1110($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1110);
    // 0x8004ED2C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8004ED30: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8004ED34: nop

    // 0x8004ED38: bc1f        L_8004EDE4
    if (!c1cs) {
        // 0x8004ED3C: nop

            goto L_8004EDE4;
    }
    // 0x8004ED3C: nop

    // 0x8004ED40: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8004ED44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004ED48: lwc1        $f10, 0x34($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X34);
    // 0x8004ED4C: lwc1        $f17, -0x1108($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1108);
    // 0x8004ED50: lwc1        $f16, -0x1104($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1104);
    // 0x8004ED54: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8004ED58: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x8004ED5C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004ED60: swc1        $f4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f4.u32l;
    // 0x8004ED64: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8004ED68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004ED6C: lw          $t7, 0x9C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X9C);
    // 0x8004ED70: nop

    // 0x8004ED74: beq         $t7, $at, L_8004EDE4
    if (ctx->r15 == ctx->r1) {
        // 0x8004ED78: nop

            goto L_8004EDE4;
    }
    // 0x8004ED78: nop

    // 0x8004ED7C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8004ED80: nop

    // 0x8004ED84: lw          $t0, 0x9C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X9C);
    // 0x8004ED88: nop

    // 0x8004ED8C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8004ED90: sw          $t1, 0x9C($t8)
    MEM_W(0X9C, ctx->r24) = ctx->r9;
    // 0x8004ED94: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8004ED98: nop

    // 0x8004ED9C: lw          $t3, 0x9C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X9C);
    // 0x8004EDA0: nop

    // 0x8004EDA4: bne         $t3, $zero, L_8004EDE4
    if (ctx->r11 != 0) {
        // 0x8004EDA8: nop

            goto L_8004EDE4;
    }
    // 0x8004EDA8: nop

    // 0x8004EDAC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004EDB0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004EDB4: nop

    // 0x8004EDB8: swc1        $f6, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f6.u32l;
    // 0x8004EDBC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8004EDC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EDC4: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004EDC8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004EDCC: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8004EDD0: lui         $at, 0xFEFF
    ctx->r1 = S32(0XFEFF << 16);
    // 0x8004EDD4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004EDD8: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8004EDDC: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8004EDE0: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_8004EDE4:
    // 0x8004EDE4: b           L_8004EE5C
    // 0x8004EDE8: nop

        goto L_8004EE5C;
    // 0x8004EDE8: nop

L_8004EDEC:
    // 0x8004EDEC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8004EDF0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EDF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004EDF8: lwc1        $f10, 0x34($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X34);
    // 0x8004EDFC: nop

    // 0x8004EE00: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8004EE04: nop

    // 0x8004EE08: bc1t        L_8004EE2C
    if (c1cs) {
        // 0x8004EE0C: nop

            goto L_8004EE2C;
    }
    // 0x8004EE0C: nop

    // 0x8004EE10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004EE14: lwc1        $f16, -0x1100($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1100);
    // 0x8004EE18: nop

    // 0x8004EE1C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8004EE20: nop

    // 0x8004EE24: bc1f        L_8004EE3C
    if (!c1cs) {
        // 0x8004EE28: nop

            goto L_8004EE3C;
    }
    // 0x8004EE28: nop

L_8004EE2C:
    // 0x8004EE2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004EE30: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8004EE34: b           L_8004EE5C
    // 0x8004EE38: swc1        $f18, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f18.u32l;
        goto L_8004EE5C;
    // 0x8004EE38: swc1        $f18, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f18.u32l;
L_8004EE3C:
    // 0x8004EE3C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8004EE40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EE44: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004EE48: lwc1        $f4, 0xA0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XA0);
    // 0x8004EE4C: lwc1        $f10, 0x34($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8004EE50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004EE54: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8004EE58: swc1        $f16, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f16.u32l;
L_8004EE5C:
    // 0x8004EE5C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8004EE60: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004EE64: lwc1        $f18, 0x34($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X34);
    // 0x8004EE68: lwc1        $f7, -0x10F8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X10F8);
    // 0x8004EE6C: lwc1        $f6, -0x10F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X10F4);
    // 0x8004EE70: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8004EE74: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004EE78: jal         0x800C3070
    // 0x8004EE7C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_0;
    // 0x8004EE7C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_0:
    // 0x8004EE80: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8004EE84: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004EE88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004EE8C: lwc1        $f19, -0x10F0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X10F0);
    // 0x8004EE90: lwc1        $f18, -0x10EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X10EC);
    // 0x8004EE94: lwc1        $f8, 0x34($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X34);
    // 0x8004EE98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004EE9C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8004EEA0: lwc1        $f7, -0x10E8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X10E8);
    // 0x8004EEA4: lwc1        $f6, -0x10E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X10E4);
    // 0x8004EEA8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8004EEAC: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004EEB0: jal         0x800C3338
    // 0x8004EEB4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_1;
    // 0x8004EEB4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x8004EEB8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8004EEBC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004EEC0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004EEC4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004EEC8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004EECC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8004EED0: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8004EED4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004EED8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004EEDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004EEE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8004EEE4: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x8004EEE8: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8004EEEC: swc1        $f8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f8.u32l;
    // 0x8004EEF0: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004EEF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004EEF8: nop

    // 0x8004EEFC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8004EF00: nop

    // 0x8004EF04: bc1f        L_8004EF44
    if (!c1cs) {
        // 0x8004EF08: nop

            goto L_8004EF44;
    }
    // 0x8004EF08: nop

    // 0x8004EF0C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004EF10: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004EF14: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004EF18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004EF1C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004EF20: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8004EF24: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004EF28: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8004EF2C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004EF30: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8004EF34: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x8004EF38: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004EF3C: b           L_8004EF78
    // 0x8004EF40: swc1        $f4, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f4.u32l;
        goto L_8004EF78;
    // 0x8004EF40: swc1        $f4, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f4.u32l;
L_8004EF44:
    // 0x8004EF44: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004EF48: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004EF4C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004EF50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004EF54: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8004EF58: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8004EF5C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004EF60: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004EF64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004EF68: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8004EF6C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8004EF70: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004EF74: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
L_8004EF78:
    // 0x8004EF78: b           L_8004EF80
    // 0x8004EF7C: nop

        goto L_8004EF80;
    // 0x8004EF7C: nop

L_8004EF80:
    // 0x8004EF80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EF84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004EF88: jr          $ra
    // 0x8004EF8C: nop

    return;
    // 0x8004EF8C: nop

;}
RECOMP_FUNC void func_8004EF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EF90: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004EF94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004EF98: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8004EF9C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8004EFA0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8004EFA4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8004EFA8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004EFAC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8004EFB0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004EFB4: andi        $t7, $t6, 0x1FFF
    ctx->r15 = ctx->r14 & 0X1FFF;
    // 0x8004EFB8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8004EFBC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8004EFC0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8004EFC4: nop

    // 0x8004EFC8: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x8004EFCC: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x8004EFD0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004EFD4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004EFD8: nop

    // 0x8004EFDC: sw          $zero, 0x98($t1)
    MEM_W(0X98, ctx->r9) = 0;
    // 0x8004EFE0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004EFE4: lw          $t2, 0x258C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X258C);
    // 0x8004EFE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004EFEC: sw          $t2, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r10;
    // 0x8004EFF0: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    // 0x8004EFF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004EFF8: or          $t3, $a3, $at
    ctx->r11 = ctx->r7 | ctx->r1;
    // 0x8004EFFC: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x8004F000: addiu       $a0, $sp, 0x46
    ctx->r4 = ADD32(ctx->r29, 0X46);
    // 0x8004F004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004F008: jal         0x800B3230
    // 0x8004F00C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_0;
    // 0x8004F00C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8004F010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F014: bne         $v0, $at, L_8004F050
    if (ctx->r2 != ctx->r1) {
        // 0x8004F018: nop

            goto L_8004F050;
    }
    // 0x8004F018: nop

    // 0x8004F01C: addiu       $t4, $zero, 0x23
    ctx->r12 = ADD32(0, 0X23);
    // 0x8004F020: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x8004F024: ori         $a3, $a3, 0x23
    ctx->r7 = ctx->r7 | 0X23;
    // 0x8004F028: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8004F02C: addiu       $a0, $sp, 0x46
    ctx->r4 = ADD32(ctx->r29, 0X46);
    // 0x8004F030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004F034: jal         0x800B3230
    // 0x8004F038: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_1;
    // 0x8004F038: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8004F03C: lui         $t5, 0x2A
    ctx->r13 = S32(0X2A << 16);
    // 0x8004F040: ori         $t5, $t5, 0x45
    ctx->r13 = ctx->r13 | 0X45;
    // 0x8004F044: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8004F048: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8004F04C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_8004F050:
    // 0x8004F050: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004F054: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x8004F058: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004F05C: bne         $t7, $at, L_8004F080
    if (ctx->r15 != ctx->r1) {
        // 0x8004F060: nop

            goto L_8004F080;
    }
    // 0x8004F060: nop

    // 0x8004F064: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8004F068: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x8004F06C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004F070: bne         $t8, $at, L_8004F080
    if (ctx->r24 != ctx->r1) {
        // 0x8004F074: nop

            goto L_8004F080;
    }
    // 0x8004F074: nop

    // 0x8004F078: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8004F07C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_8004F080:
    // 0x8004F080: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004F084: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004F088: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004F08C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004F090: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004F094: bne         $t4, $zero, L_8004F0A4
    if (ctx->r12 != 0) {
        // 0x8004F098: andi        $t5, $t3, 0x8
        ctx->r13 = ctx->r11 & 0X8;
            goto L_8004F0A4;
    }
    // 0x8004F098: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x8004F09C: beq         $t5, $zero, L_8004F0B0
    if (ctx->r13 == 0) {
        // 0x8004F0A0: nop

            goto L_8004F0B0;
    }
    // 0x8004F0A0: nop

L_8004F0A4:
    // 0x8004F0A4: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x8004F0A8: b           L_8004F0C0
    // 0x8004F0AC: nop

        goto L_8004F0C0;
    // 0x8004F0AC: nop

L_8004F0B0:
    // 0x8004F0B0: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x8004F0B4: nop

    // 0x8004F0B8: ori         $t1, $s0, 0x1
    ctx->r9 = ctx->r16 | 0X1;
    // 0x8004F0BC: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8004F0C0:
    // 0x8004F0C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F0C4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F0C8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8004F0CC: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8004F0D0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004F0D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8004F0D8: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8004F0DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F0E0: addiu       $a0, $t6, 0x4C
    ctx->r4 = ADD32(ctx->r14, 0X4C);
    // 0x8004F0E4: addiu       $a1, $t6, 0x50
    ctx->r5 = ADD32(ctx->r14, 0X50);
    // 0x8004F0E8: jal         0x800B202C
    // 0x8004F0EC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_2;
    // 0x8004F0EC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8004F0F0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F0F4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F0F8: nop

    // 0x8004F0FC: sh          $v0, 0x48($t7)
    MEM_H(0X48, ctx->r15) = ctx->r2;
    // 0x8004F100: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004F104: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004F108: nop

    // 0x8004F10C: addiu       $a0, $t8, 0x50
    ctx->r4 = ADD32(ctx->r24, 0X50);
    // 0x8004F110: jal         0x8005A5F4
    // 0x8004F114: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_3;
    // 0x8004F114: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_3:
    // 0x8004F118: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004F11C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004F120: nop

    // 0x8004F124: lw          $t0, 0x4C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4C);
    // 0x8004F128: nop

    // 0x8004F12C: lwc1        $f8, 0xCC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x8004F130: nop

    // 0x8004F134: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x8004F138: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004F13C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004F140: nop

    // 0x8004F144: lw          $t3, 0x4C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4C);
    // 0x8004F148: nop

    // 0x8004F14C: lwc1        $f10, 0xD0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8004F150: nop

    // 0x8004F154: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x8004F158: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F15C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F160: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8004F164: nop

    // 0x8004F168: sh          $t4, 0x4A($t5)
    MEM_H(0X4A, ctx->r13) = ctx->r12;
    // 0x8004F16C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F170: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004F174: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F178: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8004F17C: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8004F180: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8004F184: lui         $at, 0xEFFF
    ctx->r1 = S32(0XEFFF << 16);
    // 0x8004F188: ori         $at, $at, 0xF8FD
    ctx->r1 = ctx->r1 | 0XF8FD;
    // 0x8004F18C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004F190: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004F194: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004F198: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x8004F19C: nop

    // 0x8004F1A0: andi        $t3, $t0, 0x1
    ctx->r11 = ctx->r8 & 0X1;
    // 0x8004F1A4: beq         $t3, $zero, L_8004F200
    if (ctx->r11 == 0) {
        // 0x8004F1A8: nop

            goto L_8004F200;
    }
    // 0x8004F1A8: nop

    // 0x8004F1AC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8004F1B0: nop

    // 0x8004F1B4: andi        $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 & 0X8000;
    // 0x8004F1B8: beq         $t4, $zero, L_8004F1E8
    if (ctx->r12 == 0) {
        // 0x8004F1BC: nop

            goto L_8004F1E8;
    }
    // 0x8004F1BC: nop

    // 0x8004F1C0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F1C4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F1C8: nop

    // 0x8004F1CC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004F1D0: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004F1D4: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004F1D8: ori         $t9, $t7, 0x400
    ctx->r25 = ctx->r15 | 0X400;
    // 0x8004F1DC: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8004F1E0: b           L_8004F200
    // 0x8004F1E4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
        goto L_8004F200;
    // 0x8004F1E4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
L_8004F1E8:
    // 0x8004F1E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F1EC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004F1F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004F1F4: addiu       $a0, $t1, 0x4C
    ctx->r4 = ADD32(ctx->r9, 0X4C);
    // 0x8004F1F8: jal         0x800B2CBC
    // 0x8004F1FC: addiu       $a1, $t1, 0x50
    ctx->r5 = ADD32(ctx->r9, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_4;
    // 0x8004F1FC: addiu       $a1, $t1, 0x50
    ctx->r5 = ADD32(ctx->r9, 0X50);
    after_4:
L_8004F200:
    // 0x8004F200: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x8004F204: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F208: andi        $t3, $t0, 0xE
    ctx->r11 = ctx->r8 & 0XE;
    // 0x8004F20C: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8004F210: bne         $t2, $at, L_8004F23C
    if (ctx->r10 != ctx->r1) {
        // 0x8004F214: nop

            goto L_8004F23C;
    }
    // 0x8004F214: nop

    // 0x8004F218: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004F21C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004F220: nop

    // 0x8004F224: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004F228: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004F22C: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004F230: ori         $t9, $t7, 0x100
    ctx->r25 = ctx->r15 | 0X100;
    // 0x8004F234: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004F238: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_8004F23C:
    // 0x8004F23C: lhu         $t5, 0x46($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X46);
    // 0x8004F240: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004F244: andi        $t1, $t5, 0xE
    ctx->r9 = ctx->r13 & 0XE;
    // 0x8004F248: sra         $t0, $t1, 1
    ctx->r8 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8004F24C: beq         $t0, $at, L_8004F260
    if (ctx->r8 == ctx->r1) {
        // 0x8004F250: nop

            goto L_8004F260;
    }
    // 0x8004F250: nop

    // 0x8004F254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004F258: bne         $t0, $at, L_8004F288
    if (ctx->r8 != ctx->r1) {
        // 0x8004F25C: nop

            goto L_8004F288;
    }
    // 0x8004F25C: nop

L_8004F260:
    // 0x8004F260: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004F264: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004F268: nop

    // 0x8004F26C: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x8004F270: or          $t6, $t3, $zero
    ctx->r14 = ctx->r11 | 0;
    // 0x8004F274: lw          $t3, 0x4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4);
    // 0x8004F278: or          $t8, $t2, $zero
    ctx->r24 = ctx->r10 | 0;
    // 0x8004F27C: ori         $t9, $t3, 0x200
    ctx->r25 = ctx->r11 | 0X200;
    // 0x8004F280: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8004F284: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8004F288:
    // 0x8004F288: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F28C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F290: nop

    // 0x8004F294: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x8004F298: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x8004F29C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8004F2A0: ori         $t1, $t5, 0x4
    ctx->r9 = ctx->r13 | 0X4;
    // 0x8004F2A4: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x8004F2A8: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8004F2AC: lh          $t2, 0x3A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3A);
    // 0x8004F2B0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8004F2B4: beq         $t2, $at, L_8004F2E0
    if (ctx->r10 == ctx->r1) {
        // 0x8004F2B8: nop

            goto L_8004F2E0;
    }
    // 0x8004F2B8: nop

    // 0x8004F2BC: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8004F2C0: beq         $t2, $at, L_8004F2E0
    if (ctx->r10 == ctx->r1) {
        // 0x8004F2C4: nop

            goto L_8004F2E0;
    }
    // 0x8004F2C4: nop

    // 0x8004F2C8: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8004F2CC: beq         $t2, $at, L_8004F2E0
    if (ctx->r10 == ctx->r1) {
        // 0x8004F2D0: nop

            goto L_8004F2E0;
    }
    // 0x8004F2D0: nop

    // 0x8004F2D4: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8004F2D8: bne         $t2, $at, L_8004F3D0
    if (ctx->r10 != ctx->r1) {
        // 0x8004F2DC: nop

            goto L_8004F3D0;
    }
    // 0x8004F2DC: nop

L_8004F2E0:
    // 0x8004F2E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004F2E4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004F2E8: addiu       $t3, $zero, 0x63
    ctx->r11 = ADD32(0, 0X63);
    // 0x8004F2EC: sw          $t3, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r11;
    // 0x8004F2F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004F2F4: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004F2F8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8004F2FC: lwc1        $f16, 0xC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8004F300: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004F304: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F308: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8004F30C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8004F310: nop

    // 0x8004F314: bc1f        L_8004F334
    if (!c1cs) {
        // 0x8004F318: nop

            goto L_8004F334;
    }
    // 0x8004F318: nop

    // 0x8004F31C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8004F320: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F324: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F328: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F32C: b           L_8004F38C
    // 0x8004F330: swc1        $f6, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f6.u32l;
        goto L_8004F38C;
    // 0x8004F330: swc1        $f6, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f6.u32l;
L_8004F334:
    // 0x8004F334: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004F338: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004F33C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8004F340: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8004F344: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8004F348: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004F34C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004F350: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8004F354: nop

    // 0x8004F358: bc1f        L_8004F374
    if (!c1cs) {
        // 0x8004F35C: nop

            goto L_8004F374;
    }
    // 0x8004F35C: nop

    // 0x8004F360: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F364: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F368: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004F36C: b           L_8004F38C
    // 0x8004F370: swc1        $f18, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f18.u32l;
        goto L_8004F38C;
    // 0x8004F370: swc1        $f18, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f18.u32l;
L_8004F374:
    // 0x8004F374: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004F378: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004F37C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004F380: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004F384: nop

    // 0x8004F388: swc1        $f4, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f4.u32l;
L_8004F38C:
    // 0x8004F38C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F390: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004F394: lui         $at, 0x4041
    ctx->r1 = S32(0X4041 << 16);
    // 0x8004F398: lwc1        $f6, 0x6C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x8004F39C: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8004F3A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004F3A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004F3A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004F3AC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004F3B0: nop

    // 0x8004F3B4: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x8004F3B8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004F3BC: swc1        $f6, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f6.u32l;
    // 0x8004F3C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F3C4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F3C8: nop

    // 0x8004F3CC: sw          $zero, 0x88($t7)
    MEM_W(0X88, ctx->r15) = 0;
L_8004F3D0:
    // 0x8004F3D0: b           L_8004F3D8
    // 0x8004F3D4: nop

        goto L_8004F3D8;
    // 0x8004F3D4: nop

L_8004F3D8:
    // 0x8004F3D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F3DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004F3E0: jr          $ra
    // 0x8004F3E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004F3E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
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
RECOMP_FUNC void func_8004F66C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F66C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8004F670: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004F674: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8004F678: beq         $a0, $at, L_8004F6BC
    if (ctx->r4 == ctx->r1) {
        // 0x8004F67C: nop

            goto L_8004F6BC;
    }
    // 0x8004F67C: nop

    // 0x8004F680: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8004F684: beq         $a0, $at, L_8004F6BC
    if (ctx->r4 == ctx->r1) {
        // 0x8004F688: nop

            goto L_8004F6BC;
    }
    // 0x8004F688: nop

    // 0x8004F68C: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x8004F690: beq         $a0, $at, L_8004F6BC
    if (ctx->r4 == ctx->r1) {
        // 0x8004F694: nop

            goto L_8004F6BC;
    }
    // 0x8004F694: nop

    // 0x8004F698: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8004F69C: beq         $a0, $at, L_8004F6BC
    if (ctx->r4 == ctx->r1) {
        // 0x8004F6A0: nop

            goto L_8004F6BC;
    }
    // 0x8004F6A0: nop

    // 0x8004F6A4: addiu       $at, $zero, 0x73
    ctx->r1 = ADD32(0, 0X73);
    // 0x8004F6A8: beq         $a0, $at, L_8004F6BC
    if (ctx->r4 == ctx->r1) {
        // 0x8004F6AC: nop

            goto L_8004F6BC;
    }
    // 0x8004F6AC: nop

    // 0x8004F6B0: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8004F6B4: bne         $a0, $at, L_8004F6CC
    if (ctx->r4 != ctx->r1) {
        // 0x8004F6B8: nop

            goto L_8004F6CC;
    }
    // 0x8004F6B8: nop

L_8004F6BC:
    // 0x8004F6BC: jr          $ra
    // 0x8004F6C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8004F6C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004F6C4: b           L_8004F6D4
    // 0x8004F6C8: nop

        goto L_8004F6D4;
    // 0x8004F6C8: nop

L_8004F6CC:
    // 0x8004F6CC: jr          $ra
    // 0x8004F6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8004F6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004F6D4:
    // 0x8004F6D4: jr          $ra
    // 0x8004F6D8: nop

    return;
    // 0x8004F6D8: nop

    // 0x8004F6DC: jr          $ra
    // 0x8004F6E0: nop

    return;
    // 0x8004F6E0: nop

;}
RECOMP_FUNC void func_8004F6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F6E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004F6E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F6EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004F6F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F6F4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F6F8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004F6FC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004F700: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004F704: bne         $t0, $zero, L_8004F714
    if (ctx->r8 != 0) {
        // 0x8004F708: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_8004F714;
    }
    // 0x8004F708: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x8004F70C: beq         $t1, $zero, L_8004F798
    if (ctx->r9 == 0) {
        // 0x8004F710: nop

            goto L_8004F798;
    }
    // 0x8004F710: nop

L_8004F714:
    // 0x8004F714: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F718: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F71C: nop

    // 0x8004F720: lwc1        $f4, 0x6C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x8004F724: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8004F728: nop

    // 0x8004F72C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004F730: nop

    // 0x8004F734: bc1f        L_8004F744
    if (!c1cs) {
        // 0x8004F738: nop

            goto L_8004F744;
    }
    // 0x8004F738: nop

    // 0x8004F73C: b           L_8004F8BC
    // 0x8004F740: nop

        goto L_8004F8BC;
    // 0x8004F740: nop

L_8004F744:
    // 0x8004F744: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004F748: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004F74C: nop

    // 0x8004F750: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x8004F754: lwc1        $f8, 0x6C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X6C);
    // 0x8004F758: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8004F75C: nop

    // 0x8004F760: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8004F764: nop

    // 0x8004F768: bc1f        L_8004F790
    if (!c1cs) {
        // 0x8004F76C: nop

            goto L_8004F790;
    }
    // 0x8004F76C: nop

    // 0x8004F770: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004F774: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004F778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004F77C: lw          $a1, 0x6C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X6C);
    // 0x8004F780: jal         0x80054198
    // 0x8004F784: nop

    func_80054198(rdram, ctx);
        goto after_0;
    // 0x8004F784: nop

    after_0:
    // 0x8004F788: b           L_8004F8BC
    // 0x8004F78C: nop

        goto L_8004F8BC;
    // 0x8004F78C: nop

L_8004F790:
    // 0x8004F790: b           L_8004F814
    // 0x8004F794: nop

        goto L_8004F814;
    // 0x8004F794: nop

L_8004F798:
    // 0x8004F798: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F79C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F7A0: nop

    // 0x8004F7A4: lwc1        $f16, 0x6C($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X6C);
    // 0x8004F7A8: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8004F7AC: nop

    // 0x8004F7B0: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8004F7B4: nop

    // 0x8004F7B8: bc1f        L_8004F7C8
    if (!c1cs) {
        // 0x8004F7BC: nop

            goto L_8004F7C8;
    }
    // 0x8004F7BC: nop

    // 0x8004F7C0: b           L_8004F8BC
    // 0x8004F7C4: nop

        goto L_8004F8BC;
    // 0x8004F7C4: nop

L_8004F7C8:
    // 0x8004F7C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F7CC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F7D0: nop

    // 0x8004F7D4: lw          $t8, 0x5C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X5C);
    // 0x8004F7D8: lwc1        $f4, 0x6C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X6C);
    // 0x8004F7DC: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8004F7E0: nop

    // 0x8004F7E4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8004F7E8: nop

    // 0x8004F7EC: bc1f        L_8004F814
    if (!c1cs) {
        // 0x8004F7F0: nop

            goto L_8004F814;
    }
    // 0x8004F7F0: nop

    // 0x8004F7F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004F7F8: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004F7FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004F800: lw          $a1, 0x6C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X6C);
    // 0x8004F804: jal         0x80054198
    // 0x8004F808: nop

    func_80054198(rdram, ctx);
        goto after_1;
    // 0x8004F808: nop

    after_1:
    // 0x8004F80C: b           L_8004F8BC
    // 0x8004F810: nop

        goto L_8004F8BC;
    // 0x8004F810: nop

L_8004F814:
    // 0x8004F814: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004F818: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004F81C: nop

    // 0x8004F820: lwc1        $f8, 0x6C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x8004F824: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8004F828: nop

    // 0x8004F82C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004F830: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8004F834: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004F838: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F83C: nop

    // 0x8004F840: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004F844: nop

    // 0x8004F848: bc1f        L_8004F864
    if (!c1cs) {
        // 0x8004F84C: nop

            goto L_8004F864;
    }
    // 0x8004F84C: nop

    // 0x8004F850: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004F854: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004F858: nop

    // 0x8004F85C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004F860: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_8004F864:
    // 0x8004F864: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004F868: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004F86C: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004F870: nop

    // 0x8004F874: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8004F878: nop

    // 0x8004F87C: bc1f        L_8004F89C
    if (!c1cs) {
        // 0x8004F880: nop

            goto L_8004F89C;
    }
    // 0x8004F880: nop

    // 0x8004F884: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004F888: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004F88C: nop

    // 0x8004F890: lwc1        $f4, 0x6C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x8004F894: b           L_8004F8B4
    // 0x8004F898: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
        goto L_8004F8B4;
    // 0x8004F898: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
L_8004F89C:
    // 0x8004F89C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F8A0: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F8A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004F8A8: lw          $a1, 0x6C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X6C);
    // 0x8004F8AC: jal         0x80054198
    // 0x8004F8B0: nop

    func_80054198(rdram, ctx);
        goto after_2;
    // 0x8004F8B0: nop

    after_2:
L_8004F8B4:
    // 0x8004F8B4: b           L_8004F8BC
    // 0x8004F8B8: nop

        goto L_8004F8BC;
    // 0x8004F8B8: nop

L_8004F8BC:
    // 0x8004F8BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F8C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004F8C4: jr          $ra
    // 0x8004F8C8: nop

    return;
    // 0x8004F8C8: nop

;}
RECOMP_FUNC void func_8004F8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004F8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F8D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004F8D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F8DC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F8E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004F8E4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004F8E8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004F8EC: bne         $t0, $zero, L_8004F8FC
    if (ctx->r8 != 0) {
        // 0x8004F8F0: andi        $t1, $t9, 0x8000
        ctx->r9 = ctx->r25 & 0X8000;
            goto L_8004F8FC;
    }
    // 0x8004F8F0: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x8004F8F4: beq         $t1, $zero, L_8004FA40
    if (ctx->r9 == 0) {
        // 0x8004F8F8: nop

            goto L_8004FA40;
    }
    // 0x8004F8F8: nop

L_8004F8FC:
    // 0x8004F8FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004F900: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004F904: nop

    // 0x8004F908: lw          $t2, 0x5C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X5C);
    // 0x8004F90C: nop

    // 0x8004F910: beq         $t2, $zero, L_8004F960
    if (ctx->r10 == 0) {
        // 0x8004F914: nop

            goto L_8004F960;
    }
    // 0x8004F914: nop

    // 0x8004F918: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x8004F91C: nop

    // 0x8004F920: beq         $t3, $zero, L_8004F960
    if (ctx->r11 == 0) {
        // 0x8004F924: nop

            goto L_8004F960;
    }
    // 0x8004F924: nop

    // 0x8004F928: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F92C: beq         $t3, $at, L_8004F960
    if (ctx->r11 == ctx->r1) {
        // 0x8004F930: nop

            goto L_8004F960;
    }
    // 0x8004F930: nop

    // 0x8004F934: lhu         $t4, 0x60($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X60);
    // 0x8004F938: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x8004F93C: beq         $t4, $at, L_8004F960
    if (ctx->r12 == ctx->r1) {
        // 0x8004F940: nop

            goto L_8004F960;
    }
    // 0x8004F940: nop

    // 0x8004F944: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004F948: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004F94C: ori         $a2, $zero, 0x8037
    ctx->r6 = 0 | 0X8037;
    // 0x8004F950: lw          $a0, 0x5C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X5C);
    // 0x8004F954: lhu         $a1, 0x60($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X60);
    // 0x8004F958: jal         0x80029538
    // 0x8004F95C: nop

    func_80029538(rdram, ctx);
        goto after_0;
    // 0x8004F95C: nop

    after_0:
L_8004F960:
    // 0x8004F960: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004F964: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004F968: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004F96C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004F970: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004F974: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004F978: bne         $t0, $zero, L_8004F988
    if (ctx->r8 != 0) {
        // 0x8004F97C: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8004F988;
    }
    // 0x8004F97C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8004F980: beq         $t1, $zero, L_8004F9B8
    if (ctx->r9 == 0) {
        // 0x8004F984: nop

            goto L_8004F9B8;
    }
    // 0x8004F984: nop

L_8004F988:
    // 0x8004F988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F98C: jal         0x800507AC
    // 0x8004F990: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    func_800507AC(rdram, ctx);
        goto after_1;
    // 0x8004F990: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    after_1:
    // 0x8004F994: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F998: jal         0x800507AC
    // 0x8004F99C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x8004F99C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    after_2:
    // 0x8004F9A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F9A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004F9A8: jal         0x80052508
    // 0x8004F9AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_3;
    // 0x8004F9AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8004F9B0: b           L_8004FA14
    // 0x8004F9B4: nop

        goto L_8004FA14;
    // 0x8004F9B4: nop

L_8004F9B8:
    // 0x8004F9B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F9BC: jal         0x800507AC
    // 0x8004F9C0: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    func_800507AC(rdram, ctx);
        goto after_4;
    // 0x8004F9C0: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_4:
    // 0x8004F9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004F9C8: jal         0x800507AC
    // 0x8004F9CC: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800507AC(rdram, ctx);
        goto after_5;
    // 0x8004F9CC: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_5:
    // 0x8004F9D0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004F9D4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004F9D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004F9DC: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8004F9E0: nop

    // 0x8004F9E4: addiu       $t7, $t3, -0xA
    ctx->r15 = ADD32(ctx->r11, -0XA);
    // 0x8004F9E8: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
    // 0x8004F9EC: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004F9F0: nop

    // 0x8004F9F4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8004F9F8: nop

    // 0x8004F9FC: bgez        $t5, L_8004FA14
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8004FA00: nop

            goto L_8004FA14;
    }
    // 0x8004FA00: nop

    // 0x8004FA04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004FA08: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8004FA0C: nop

    // 0x8004FA10: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
L_8004FA14:
    // 0x8004FA14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004FA18: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004FA1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004FA20: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004FA24: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8004FA28: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8004FA2C: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x8004FA30: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004FA34: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004FA38: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8004FA3C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
L_8004FA40:
    // 0x8004FA40: b           L_8004FA48
    // 0x8004FA44: nop

        goto L_8004FA48;
    // 0x8004FA44: nop

L_8004FA48:
    // 0x8004FA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004FA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004FA50: jr          $ra
    // 0x8004FA54: nop

    return;
    // 0x8004FA54: nop

;}
RECOMP_FUNC void func_8004FA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FA58: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8004FA5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004FA60: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x8004FA64: beq         $a0, $at, L_8004FA90
    if (ctx->r4 == ctx->r1) {
        // 0x8004FA68: nop

            goto L_8004FA90;
    }
    // 0x8004FA68: nop

    // 0x8004FA6C: addiu       $at, $zero, 0x79
    ctx->r1 = ADD32(0, 0X79);
    // 0x8004FA70: beq         $a0, $at, L_8004FA90
    if (ctx->r4 == ctx->r1) {
        // 0x8004FA74: nop

            goto L_8004FA90;
    }
    // 0x8004FA74: nop

    // 0x8004FA78: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    // 0x8004FA7C: beq         $a0, $at, L_8004FA90
    if (ctx->r4 == ctx->r1) {
        // 0x8004FA80: nop

            goto L_8004FA90;
    }
    // 0x8004FA80: nop

    // 0x8004FA84: addiu       $at, $zero, 0x7B
    ctx->r1 = ADD32(0, 0X7B);
    // 0x8004FA88: bne         $a0, $at, L_8004FA98
    if (ctx->r4 != ctx->r1) {
        // 0x8004FA8C: nop

            goto L_8004FA98;
    }
    // 0x8004FA8C: nop

L_8004FA90:
    // 0x8004FA90: jr          $ra
    // 0x8004FA94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8004FA94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004FA98:
    // 0x8004FA98: jr          $ra
    // 0x8004FA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8004FA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8004FAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FAA0: jr          $ra
    // 0x8004FAA4: nop

    return;
    // 0x8004FAA4: nop

    // 0x8004FAA8: jr          $ra
    // 0x8004FAAC: nop

    return;
    // 0x8004FAAC: nop

;}
RECOMP_FUNC void func_8004FAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FAB0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8004FAB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004FAB8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8004FABC: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8004FAC0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004FAC4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004FAC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004FACC: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8004FAD0: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8004FAD4: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x8004FAD8: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8004FADC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004FAE0: nop

    // 0x8004FAE4: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x8004FAE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004FAEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FAF0: nop

    // 0x8004FAF4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8004FAF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004FAFC: nop

    // 0x8004FB00: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8004FB04: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x8004FB08: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x8004FB0C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004FB10: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004FB14: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004FB18: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004FB1C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004FB20: bne         $t2, $zero, L_8004FB30
    if (ctx->r10 != 0) {
        // 0x8004FB24: andi        $t3, $t1, 0x8000
        ctx->r11 = ctx->r9 & 0X8000;
            goto L_8004FB30;
    }
    // 0x8004FB24: andi        $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 & 0X8000;
    // 0x8004FB28: beq         $t3, $zero, L_8004FE00
    if (ctx->r11 == 0) {
        // 0x8004FB2C: nop

            goto L_8004FE00;
    }
    // 0x8004FB2C: nop

L_8004FB30:
    // 0x8004FB30: lh          $t4, 0x76($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X76);
    // 0x8004FB34: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x8004FB38: bne         $t4, $at, L_8004FE00
    if (ctx->r12 != ctx->r1) {
        // 0x8004FB3C: nop

            goto L_8004FE00;
    }
    // 0x8004FB3C: nop

    // 0x8004FB40: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004FB44: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004FB48: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x8004FB4C: lw          $t6, 0x5C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X5C);
    // 0x8004FB50: nop

    // 0x8004FB54: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8004FB58: nop

    // 0x8004FB5C: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB60: nop

            goto L_8004FB94;
    }
    // 0x8004FB60: nop

    // 0x8004FB64: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8004FB68: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB6C: nop

            goto L_8004FB94;
    }
    // 0x8004FB6C: nop

    // 0x8004FB70: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x8004FB74: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB78: nop

            goto L_8004FB94;
    }
    // 0x8004FB78: nop

    // 0x8004FB7C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8004FB80: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB84: nop

            goto L_8004FB94;
    }
    // 0x8004FB84: nop

    // 0x8004FB88: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x8004FB8C: bne         $t7, $at, L_8004FE00
    if (ctx->r15 != ctx->r1) {
        // 0x8004FB90: nop

            goto L_8004FE00;
    }
    // 0x8004FB90: nop

L_8004FB94:
    // 0x8004FB94: jal         0x80031B6C
    // 0x8004FB98: nop

    func_80031B6C(rdram, ctx);
        goto after_0;
    // 0x8004FB98: nop

    after_0:
    // 0x8004FB9C: jal         0x80031AC8
    // 0x8004FBA0: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x8004FBA0: nop

    after_1:
    // 0x8004FBA4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004FBA8: beq         $v0, $at, L_8004FBD0
    if (ctx->r2 == ctx->r1) {
        // 0x8004FBAC: nop

            goto L_8004FBD0;
    }
    // 0x8004FBAC: nop

L_8004FBB0:
    // 0x8004FBB0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FBB4: jal         0x800499B0
    // 0x8004FBB8: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8004FBB8: nop

    after_2:
    // 0x8004FBBC: jal         0x80031AC8
    // 0x8004FBC0: nop

    func_80031AC8(rdram, ctx);
        goto after_3;
    // 0x8004FBC0: nop

    after_3:
    // 0x8004FBC4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004FBC8: bne         $v0, $at, L_8004FBB0
    if (ctx->r2 != ctx->r1) {
        // 0x8004FBCC: nop

            goto L_8004FBB0;
    }
    // 0x8004FBCC: nop

L_8004FBD0:
    // 0x8004FBD0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8004FBD4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8004FBD8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8004FBDC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004FBE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004FBE4: nop

    // 0x8004FBE8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8004FBEC: jal         0x80016620
    // 0x8004FBF0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_80016620(rdram, ctx);
        goto after_4;
    // 0x8004FBF0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x8004FBF4: jal         0x80016138
    // 0x8004FBF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_5;
    // 0x8004FBF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_5:
    // 0x8004FBFC: beq         $v0, $zero, L_8004FC20
    if (ctx->r2 == 0) {
        // 0x8004FC00: nop

            goto L_8004FC20;
    }
    // 0x8004FC00: nop

L_8004FC04:
    // 0x8004FC04: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FC08: jal         0x800499B0
    // 0x8004FC0C: nop

    func_800499B0(rdram, ctx);
        goto after_6;
    // 0x8004FC0C: nop

    after_6:
    // 0x8004FC10: jal         0x80016138
    // 0x8004FC14: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_7;
    // 0x8004FC14: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_7:
    // 0x8004FC18: bne         $v0, $zero, L_8004FC04
    if (ctx->r2 != 0) {
        // 0x8004FC1C: nop

            goto L_8004FC04;
    }
    // 0x8004FC1C: nop

L_8004FC20:
    // 0x8004FC20: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004FC24: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004FC28: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8004FC2C: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x8004FC30: nop

    // 0x8004FC34: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8004FC38: nop

    // 0x8004FC3C: bne         $t0, $at, L_8004FC50
    if (ctx->r8 != ctx->r1) {
        // 0x8004FC40: nop

            goto L_8004FC50;
    }
    // 0x8004FC40: nop

    // 0x8004FC44: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8004FC48: b           L_8004FC74
    // 0x8004FC4C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
        goto L_8004FC74;
    // 0x8004FC4C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_8004FC50:
    // 0x8004FC50: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004FC54: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004FC58: nop

    // 0x8004FC5C: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x8004FC60: nop

    // 0x8004FC64: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8004FC68: nop

    // 0x8004FC6C: addiu       $t5, $t4, -0x24
    ctx->r13 = ADD32(ctx->r12, -0X24);
    // 0x8004FC70: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
L_8004FC74:
    // 0x8004FC74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004FC78: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004FC7C: nop

    // 0x8004FC80: lw          $a0, 0x5C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X5C);
    // 0x8004FC84: jal         0x800299C4
    // 0x8004FC88: nop

    func_800299C4(rdram, ctx);
        goto after_8;
    // 0x8004FC88: nop

    after_8:
    // 0x8004FC8C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004FC90: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004FC94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004FC98: lh          $t8, 0x42($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X42);
    // 0x8004FC9C: nop

    // 0x8004FCA0: bne         $t8, $at, L_8004FCB0
    if (ctx->r24 != ctx->r1) {
        // 0x8004FCA4: nop

            goto L_8004FCB0;
    }
    // 0x8004FCA4: nop

    // 0x8004FCA8: b           L_8004FCC8
    // 0x8004FCAC: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
        goto L_8004FCC8;
    // 0x8004FCAC: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
L_8004FCB0:
    // 0x8004FCB0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004FCB4: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8004FCB8: nop

    // 0x8004FCBC: lh          $s0, 0x42($t9)
    ctx->r16 = MEM_H(ctx->r25, 0X42);
    // 0x8004FCC0: nop

    // 0x8004FCC4: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_8004FCC8:
    // 0x8004FCC8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004FCCC: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004FCD0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004FCD4: lwc1        $f16, 0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8004FCD8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8004FCDC: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8004FCE0: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8004FCE4: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x8004FCE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004FCEC: jal         0x800298A4
    // 0x8004FCF0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800298A4(rdram, ctx);
        goto after_9;
    // 0x8004FCF0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x8004FCF4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004FCF8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004FCFC: nop

    // 0x8004FD00: sw          $v0, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->r2;
    // 0x8004FD04: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD08: jal         0x80051700
    // 0x8004FD0C: nop

    func_80051700(rdram, ctx);
        goto after_10;
    // 0x8004FD0C: nop

    after_10:
    // 0x8004FD10: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004FD14: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004FD18: lh          $s1, 0x3E($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X3E);
    // 0x8004FD1C: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x8004FD20: sra         $t2, $s2, 16
    ctx->r10 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8004FD24: sh          $s1, 0x42($t3)
    MEM_H(0X42, ctx->r11) = ctx->r17;
    // 0x8004FD28: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD2C: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8004FD30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004FD34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004FD38: jal         0x8004EF90
    // 0x8004FD3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004EF90(rdram, ctx);
        goto after_11;
    // 0x8004FD3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x8004FD40: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8004FD44: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_8004FD48:
    // 0x8004FD48: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD4C: jal         0x800499B0
    // 0x8004FD50: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x8004FD50: nop

    after_12:
    // 0x8004FD54: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8004FD58: nop

    // 0x8004FD5C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8004FD60: bne         $t6, $zero, L_8004FD48
    if (ctx->r14 != 0) {
        // 0x8004FD64: sw          $t6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r14;
            goto L_8004FD48;
    }
    // 0x8004FD64: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8004FD68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004FD6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004FD70: nop

    // 0x8004FD74: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x8004FD78: jal         0x80016620
    // 0x8004FD7C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_80016620(rdram, ctx);
        goto after_13;
    // 0x8004FD7C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_13:
    // 0x8004FD80: jal         0x80016138
    // 0x8004FD84: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_14;
    // 0x8004FD84: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_14:
    // 0x8004FD88: beq         $v0, $zero, L_8004FDAC
    if (ctx->r2 == 0) {
        // 0x8004FD8C: nop

            goto L_8004FDAC;
    }
    // 0x8004FD8C: nop

L_8004FD90:
    // 0x8004FD90: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD94: jal         0x800499B0
    // 0x8004FD98: nop

    func_800499B0(rdram, ctx);
        goto after_15;
    // 0x8004FD98: nop

    after_15:
    // 0x8004FD9C: jal         0x80016138
    // 0x8004FDA0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_16;
    // 0x8004FDA0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_16:
    // 0x8004FDA4: bne         $v0, $zero, L_8004FD90
    if (ctx->r2 != 0) {
        // 0x8004FDA8: nop

            goto L_8004FD90;
    }
    // 0x8004FDA8: nop

L_8004FDAC:
    // 0x8004FDAC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8004FDB0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_8004FDB4:
    // 0x8004FDB4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FDB8: jal         0x800499B0
    // 0x8004FDBC: nop

    func_800499B0(rdram, ctx);
        goto after_17;
    // 0x8004FDBC: nop

    after_17:
    // 0x8004FDC0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8004FDC4: nop

    // 0x8004FDC8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8004FDCC: bne         $t9, $zero, L_8004FDB4
    if (ctx->r25 != 0) {
        // 0x8004FDD0: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_8004FDB4;
    }
    // 0x8004FDD0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8004FDD4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004FDD8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004FDDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004FDE0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004FDE4: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004FDE8: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004FDEC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004FDF0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004FDF4: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004FDF8: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8004FDFC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_8004FE00:
    // 0x8004FE00: b           L_8004FE08
    // 0x8004FE04: nop

        goto L_8004FE08;
    // 0x8004FE04: nop

L_8004FE08:
    // 0x8004FE08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004FE0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004FE10: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004FE14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004FE18: jr          $ra
    // 0x8004FE1C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8004FE1C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8004FE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FE20: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004FE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FE28: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8004FE2C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8004FE30: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8004FE34: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8004FE38: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x8004FE3C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8004FE40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004FE44: nop

    // 0x8004FE48: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8004FE4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004FE50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FE54: nop

    // 0x8004FE58: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8004FE5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004FE60: nop

    // 0x8004FE64: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8004FE68: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x8004FE6C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8004FE70: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8004FE74: addiu       $at, $zero, 0xB2
    ctx->r1 = ADD32(0, 0XB2);
    // 0x8004FE78: bne         $t9, $at, L_80050064
    if (ctx->r25 != ctx->r1) {
        // 0x8004FE7C: nop

            goto L_80050064;
    }
    // 0x8004FE7C: nop

    // 0x8004FE80: jal         0x80031B6C
    // 0x8004FE84: nop

    func_80031B6C(rdram, ctx);
        goto after_0;
    // 0x8004FE84: nop

    after_0:
    // 0x8004FE88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8004FE8C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8004FE90: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8004FE94: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004FE98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004FE9C: nop

    // 0x8004FEA0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8004FEA4: jal         0x80016620
    // 0x8004FEA8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_1;
    // 0x8004FEA8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8004FEAC: jal         0x80021F20
    // 0x8004FEB0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_2;
    // 0x8004FEB0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x8004FEB4: jal         0x80016138
    // 0x8004FEB8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_3;
    // 0x8004FEB8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_3:
    // 0x8004FEBC: beq         $v0, $zero, L_8004FEE0
    if (ctx->r2 == 0) {
        // 0x8004FEC0: nop

            goto L_8004FEE0;
    }
    // 0x8004FEC0: nop

L_8004FEC4:
    // 0x8004FEC4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8004FEC8: jal         0x800499B0
    // 0x8004FECC: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x8004FECC: nop

    after_4:
    // 0x8004FED0: jal         0x80016138
    // 0x8004FED4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_5;
    // 0x8004FED4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_5:
    // 0x8004FED8: bne         $v0, $zero, L_8004FEC4
    if (ctx->r2 != 0) {
        // 0x8004FEDC: nop

            goto L_8004FEC4;
    }
    // 0x8004FEDC: nop

L_8004FEE0:
    // 0x8004FEE0: jal         0x80021ED0
    // 0x8004FEE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_6;
    // 0x8004FEE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_6:
    // 0x8004FEE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004FEEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004FEF0: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8004FEF4: lwc1        $f5, -0x10E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X10E0);
    // 0x8004FEF8: lwc1        $f4, -0x10DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X10DC);
    // 0x8004FEFC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8004FF00: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8004FF04: nop

    // 0x8004FF08: bc1f        L_8004FF4C
    if (!c1cs) {
        // 0x8004FF0C: nop

            goto L_8004FF4C;
    }
    // 0x8004FF0C: nop

L_8004FF10:
    // 0x8004FF10: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8004FF14: jal         0x800499B0
    // 0x8004FF18: nop

    func_800499B0(rdram, ctx);
        goto after_7;
    // 0x8004FF18: nop

    after_7:
    // 0x8004FF1C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8004FF20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004FF24: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004FF28: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8004FF2C: lwc1        $f11, -0x10D8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X10D8);
    // 0x8004FF30: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8004FF34: lwc1        $f10, -0x10D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X10D4);
    // 0x8004FF38: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8004FF3C: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004FF40: nop

    // 0x8004FF44: bc1t        L_8004FF10
    if (c1cs) {
        // 0x8004FF48: nop

            goto L_8004FF10;
    }
    // 0x8004FF48: nop

L_8004FF4C:
    // 0x8004FF4C: jal         0x80021ED0
    // 0x8004FF50: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_8;
    // 0x8004FF50: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // 0x8004FF54: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004FF58: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004FF5C: nop

    // 0x8004FF60: lh          $t3, 0x40($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X40);
    // 0x8004FF64: nop

    // 0x8004FF68: slti        $at, $t3, 0x3E7
    ctx->r1 = SIGNED(ctx->r11) < 0X3E7 ? 1 : 0;
    // 0x8004FF6C: beq         $at, $zero, L_8004FF90
    if (ctx->r1 == 0) {
        // 0x8004FF70: nop

            goto L_8004FF90;
    }
    // 0x8004FF70: nop

    // 0x8004FF74: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004FF78: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004FF7C: nop

    // 0x8004FF80: lh          $t5, 0x40($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X40);
    // 0x8004FF84: nop

    // 0x8004FF88: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004FF8C: sh          $t6, 0x40($t4)
    MEM_H(0X40, ctx->r12) = ctx->r14;
L_8004FF90:
    // 0x8004FF90: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004FF94: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004FF98: nop

    // 0x8004FF9C: lh          $t8, 0x38($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X38);
    // 0x8004FFA0: nop

    // 0x8004FFA4: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x8004FFA8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004FFAC: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8004FFB0: nop

    // 0x8004FFB4: lh          $t0, 0x3A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X3A);
    // 0x8004FFB8: nop

    // 0x8004FFBC: sh          $t0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r8;
    // 0x8004FFC0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004FFC4: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8004FFC8: nop

    // 0x8004FFCC: sh          $zero, 0x3C($t1)
    MEM_H(0X3C, ctx->r9) = 0;
    // 0x8004FFD0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004FFD4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004FFD8: nop

    // 0x8004FFDC: sh          $zero, 0x3E($t2)
    MEM_H(0X3E, ctx->r10) = 0;
    // 0x8004FFE0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004FFE4: lw          $t3, 0x718C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X718C);
    // 0x8004FFE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004FFEC: addiu       $t5, $t3, -0x32
    ctx->r13 = ADD32(ctx->r11, -0X32);
    // 0x8004FFF0: sw          $t5, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r13;
    // 0x8004FFF4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004FFF8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004FFFC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80050000: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x80050004: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x80050008: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x8005000C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x80050010: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80050014: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80050018: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8005001C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80050020: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80050024: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80050028: nop

    // 0x8005002C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80050030: jal         0x80016620
    // 0x80050034: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_9;
    // 0x80050034: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_9:
    // 0x80050038: jal         0x80016138
    // 0x8005003C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_10;
    // 0x8005003C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_10:
    // 0x80050040: beq         $v0, $zero, L_80050064
    if (ctx->r2 == 0) {
        // 0x80050044: nop

            goto L_80050064;
    }
    // 0x80050044: nop

L_80050048:
    // 0x80050048: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8005004C: jal         0x800499B0
    // 0x80050050: nop

    func_800499B0(rdram, ctx);
        goto after_11;
    // 0x80050050: nop

    after_11:
    // 0x80050054: jal         0x80016138
    // 0x80050058: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_12;
    // 0x80050058: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_12:
    // 0x8005005C: bne         $v0, $zero, L_80050048
    if (ctx->r2 != 0) {
        // 0x80050060: nop

            goto L_80050048;
    }
    // 0x80050060: nop

L_80050064:
    // 0x80050064: b           L_8005006C
    // 0x80050068: nop

        goto L_8005006C;
    // 0x80050068: nop

L_8005006C:
    // 0x8005006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050070: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80050074: jr          $ra
    // 0x80050078: nop

    return;
    // 0x80050078: nop

;}
RECOMP_FUNC void func_8005007C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005007C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050084: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80050088: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005008C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050090: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050094: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80050098: nop

    // 0x8005009C: beq         $t6, $t7, L_800500AC
    if (ctx->r14 == ctx->r15) {
        // 0x800500A0: nop

            goto L_800500AC;
    }
    // 0x800500A0: nop

    // 0x800500A4: b           L_8005030C
    // 0x800500A8: nop

        goto L_8005030C;
    // 0x800500A8: nop

L_800500AC:
    // 0x800500AC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800500B0: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800500B4: addiu       $at, $zero, 0x93
    ctx->r1 = ADD32(0, 0X93);
    // 0x800500B8: lh          $t9, 0x4A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4A);
    // 0x800500BC: nop

    // 0x800500C0: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x800500C4: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800500C8: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800500CC: beq         $t2, $at, L_800500E8
    if (ctx->r10 == ctx->r1) {
        // 0x800500D0: sh          $t0, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r8;
            goto L_800500E8;
    }
    // 0x800500D0: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    // 0x800500D4: sll         $t3, $t0, 16
    ctx->r11 = S32(ctx->r8 << 16);
    // 0x800500D8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800500DC: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x800500E0: bne         $t4, $at, L_800501E8
    if (ctx->r12 != ctx->r1) {
        // 0x800500E4: nop

            goto L_800501E8;
    }
    // 0x800500E4: nop

L_800500E8:
    // 0x800500E8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800500EC: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800500F0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800500F4: lh          $a1, 0x42($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X42);
    // 0x800500F8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800500FC: jal         0x8004EF90
    // 0x80050100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_0;
    // 0x80050100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80050104: jal         0x800B9000
    // 0x80050108: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x80050108: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x8005010C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050110: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050114: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80050118: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005011C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050120: swc1        $f4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f4.u32l;
    // 0x80050124: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050128: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005012C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050130: swc1        $f6, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f6.u32l;
    // 0x80050134: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050138: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005013C: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80050140: lwc1        $f17, -0x10D0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X10D0);
    // 0x80050144: lwc1        $f16, -0x10CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X10CC);
    // 0x80050148: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005014C: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80050150: nop

    // 0x80050154: bc1f        L_800501C4
    if (!c1cs) {
        // 0x80050158: nop

            goto L_800501C4;
    }
    // 0x80050158: nop

L_8005015C:
    // 0x8005015C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050160: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050164: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80050168: lw          $a2, 0x28($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X28);
    // 0x8005016C: jal         0x8005D07C
    // 0x80050170: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8005D07C(rdram, ctx);
        goto after_2;
    // 0x80050170: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x80050174: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80050178: jal         0x800499B0
    // 0x8005017C: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8005017C: nop

    after_3:
    // 0x80050180: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050184: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050188: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005018C: lwc1        $f18, 0x28($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X28);
    // 0x80050190: lwc1        $f4, 0x30($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80050194: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80050198: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005019C: swc1        $f6, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f6.u32l;
    // 0x800501A0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800501A4: lwc1        $f16, -0x10C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X10C4);
    // 0x800501A8: lwc1        $f8, 0x10($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800501AC: lwc1        $f17, -0x10C8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X10C8);
    // 0x800501B0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800501B4: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x800501B8: nop

    // 0x800501BC: bc1t        L_8005015C
    if (c1cs) {
        // 0x800501C0: nop

            goto L_8005015C;
    }
    // 0x800501C0: nop

L_800501C4:
    // 0x800501C4: jal         0x80031728
    // 0x800501C8: nop

    func_80031728(rdram, ctx);
        goto after_4;
    // 0x800501C8: nop

    after_4:
    // 0x800501CC: jal         0x80059D80
    // 0x800501D0: nop

    func_80059D80(rdram, ctx);
        goto after_5;
    // 0x800501D0: nop

    after_5:
L_800501D4:
    // 0x800501D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800501D8: jal         0x800499B0
    // 0x800501DC: nop

    func_800499B0(rdram, ctx);
        goto after_6;
    // 0x800501DC: nop

    after_6:
    // 0x800501E0: b           L_800501D4
    // 0x800501E4: nop

        goto L_800501D4;
    // 0x800501E4: nop

L_800501E8:
    // 0x800501E8: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x800501EC: addiu       $at, $zero, 0x88
    ctx->r1 = ADD32(0, 0X88);
    // 0x800501F0: beq         $t0, $at, L_80050204
    if (ctx->r8 == ctx->r1) {
        // 0x800501F4: nop

            goto L_80050204;
    }
    // 0x800501F4: nop

    // 0x800501F8: addiu       $at, $zero, 0x8B
    ctx->r1 = ADD32(0, 0X8B);
    // 0x800501FC: bne         $t0, $at, L_80050304
    if (ctx->r8 != ctx->r1) {
        // 0x80050200: nop

            goto L_80050304;
    }
    // 0x80050200: nop

L_80050204:
    // 0x80050204: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80050208: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005020C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80050210: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80050214: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    // 0x80050218: jal         0x8004EF90
    // 0x8005021C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_7;
    // 0x8005021C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80050220: jal         0x800B9000
    // 0x80050224: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B9000(rdram, ctx);
        goto after_8;
    // 0x80050224: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_8:
    // 0x80050228: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005022C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80050230: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050234: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80050238: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005023C: swc1        $f18, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f18.u32l;
    // 0x80050240: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80050244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80050248: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005024C: swc1        $f4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f4.u32l;
    // 0x80050250: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050254: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80050258: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8005025C: lwc1        $f11, -0x10C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X10C0);
    // 0x80050260: lwc1        $f10, -0x10BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X10BC);
    // 0x80050264: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80050268: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8005026C: nop

    // 0x80050270: bc1f        L_800502E0
    if (!c1cs) {
        // 0x80050274: nop

            goto L_800502E0;
    }
    // 0x80050274: nop

L_80050278:
    // 0x80050278: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005027C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050280: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80050284: lw          $a2, 0x28($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X28);
    // 0x80050288: jal         0x8005D07C
    // 0x8005028C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_8005D07C(rdram, ctx);
        goto after_9;
    // 0x8005028C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_9:
    // 0x80050290: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80050294: jal         0x800499B0
    // 0x80050298: nop

    func_800499B0(rdram, ctx);
        goto after_10;
    // 0x80050298: nop

    after_10:
    // 0x8005029C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800502A0: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800502A4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800502A8: lwc1        $f16, 0x28($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X28);
    // 0x800502AC: lwc1        $f18, 0x30($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X30);
    // 0x800502B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800502B4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800502B8: swc1        $f4, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f4.u32l;
    // 0x800502BC: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x800502C0: lwc1        $f10, -0x10B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X10B4);
    // 0x800502C4: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800502C8: lwc1        $f11, -0x10B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X10B8);
    // 0x800502CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800502D0: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x800502D4: nop

    // 0x800502D8: bc1t        L_80050278
    if (c1cs) {
        // 0x800502DC: nop

            goto L_80050278;
    }
    // 0x800502DC: nop

L_800502E0:
    // 0x800502E0: jal         0x80031728
    // 0x800502E4: nop

    func_80031728(rdram, ctx);
        goto after_11;
    // 0x800502E4: nop

    after_11:
    // 0x800502E8: jal         0x80059D80
    // 0x800502EC: nop

    func_80059D80(rdram, ctx);
        goto after_12;
    // 0x800502EC: nop

    after_12:
L_800502F0:
    // 0x800502F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800502F4: jal         0x800499B0
    // 0x800502F8: nop

    func_800499B0(rdram, ctx);
        goto after_13;
    // 0x800502F8: nop

    after_13:
    // 0x800502FC: b           L_800502F0
    // 0x80050300: nop

        goto L_800502F0;
    // 0x80050300: nop

L_80050304:
    // 0x80050304: b           L_8005030C
    // 0x80050308: nop

        goto L_8005030C;
    // 0x80050308: nop

L_8005030C:
    // 0x8005030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050314: jr          $ra
    // 0x80050318: nop

    return;
    // 0x80050318: nop

;}
RECOMP_FUNC void func_8005031C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005031C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80050328: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005032C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80050330: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80050334: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80050338: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005033C: nop

    // 0x80050340: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80050344: nop

    // 0x80050348: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8005034C: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
    // 0x80050350: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050354: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050358: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005035C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80050360: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80050364: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80050368: bne         $t2, $zero, L_80050378
    if (ctx->r10 != 0) {
        // 0x8005036C: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80050378;
    }
    // 0x8005036C: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80050370: beq         $t3, $zero, L_800503A0
    if (ctx->r11 == 0) {
        // 0x80050374: nop

            goto L_800503A0;
    }
    // 0x80050374: nop

L_80050378:
    // 0x80050378: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005037C: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80050380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050384: bne         $t4, $at, L_800503A0
    if (ctx->r12 != ctx->r1) {
        // 0x80050388: nop

            goto L_800503A0;
    }
    // 0x80050388: nop

    // 0x8005038C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80050390: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80050394: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050398: beq         $t5, $at, L_800503F0
    if (ctx->r13 == ctx->r1) {
        // 0x8005039C: nop

            goto L_800503F0;
    }
    // 0x8005039C: nop

L_800503A0:
    // 0x800503A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800503A4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800503A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800503AC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800503B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800503B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800503B8: bne         $t0, $zero, L_800503C8
    if (ctx->r8 != 0) {
        // 0x800503BC: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_800503C8;
    }
    // 0x800503BC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800503C0: beq         $t1, $zero, L_80050788
    if (ctx->r9 == 0) {
        // 0x800503C4: nop

            goto L_80050788;
    }
    // 0x800503C4: nop

L_800503C8:
    // 0x800503C8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800503CC: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x800503D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800503D4: bne         $t7, $at, L_80050788
    if (ctx->r15 != ctx->r1) {
        // 0x800503D8: nop

            goto L_80050788;
    }
    // 0x800503D8: nop

    // 0x800503DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800503E0: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x800503E4: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x800503E8: bne         $t2, $at, L_80050788
    if (ctx->r10 != ctx->r1) {
        // 0x800503EC: nop

            goto L_80050788;
    }
    // 0x800503EC: nop

L_800503F0:
    // 0x800503F0: lh          $t3, 0x2A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A);
    // 0x800503F4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800503F8: beq         $t3, $at, L_80050424
    if (ctx->r11 == ctx->r1) {
        // 0x800503FC: nop

            goto L_80050424;
    }
    // 0x800503FC: nop

    // 0x80050400: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80050404: beq         $t3, $at, L_80050424
    if (ctx->r11 == ctx->r1) {
        // 0x80050408: nop

            goto L_80050424;
    }
    // 0x80050408: nop

    // 0x8005040C: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x80050410: beq         $t3, $at, L_80050424
    if (ctx->r11 == ctx->r1) {
        // 0x80050414: nop

            goto L_80050424;
    }
    // 0x80050414: nop

    // 0x80050418: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8005041C: bne         $t3, $at, L_80050788
    if (ctx->r11 != ctx->r1) {
        // 0x80050420: nop

            goto L_80050788;
    }
    // 0x80050420: nop

L_80050424:
    // 0x80050424: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80050428: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005042C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80050430: jal         0x800B334C
    // 0x80050434: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_0;
    // 0x80050434: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x80050438: andi        $t4, $v0, 0x2000
    ctx->r12 = ctx->r2 & 0X2000;
    // 0x8005043C: bne         $t4, $zero, L_80050470
    if (ctx->r12 != 0) {
        // 0x80050440: nop

            goto L_80050470;
    }
    // 0x80050440: nop

L_80050444:
    // 0x80050444: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050448: jal         0x800499B0
    // 0x8005044C: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8005044C: nop

    after_1:
    // 0x80050450: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80050454: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x80050458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005045C: jal         0x800B334C
    // 0x80050460: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_2;
    // 0x80050460: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_2:
    // 0x80050464: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
    // 0x80050468: beq         $t5, $zero, L_80050444
    if (ctx->r13 == 0) {
        // 0x8005046C: nop

            goto L_80050444;
    }
    // 0x8005046C: nop

L_80050470:
    // 0x80050470: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050474: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8005047C: lw          $t8, 0x58($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X58);
    // 0x80050480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050484: lbu         $a0, 0x16($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X16);
    // 0x80050488: jal         0x8008312C
    // 0x8005048C: nop

    func_8008312C(rdram, ctx);
        goto after_3;
    // 0x8005048C: nop

    after_3:
    // 0x80050490: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050494: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050498: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005049C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x800504A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800504A4: bne         $t2, $zero, L_800504E4
    if (ctx->r10 != 0) {
        // 0x800504A8: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_800504E4;
    }
    // 0x800504A8: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x800504AC: bne         $t3, $zero, L_800504E4
    if (ctx->r11 != 0) {
        // 0x800504B0: nop

            goto L_800504E4;
    }
    // 0x800504B0: nop

L_800504B4:
    // 0x800504B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800504B8: jal         0x800499B0
    // 0x800504BC: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x800504BC: nop

    after_4:
    // 0x800504C0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800504C4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800504C8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800504CC: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x800504D0: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x800504D4: bne         $t6, $zero, L_800504E4
    if (ctx->r14 != 0) {
        // 0x800504D8: andi        $t7, $t5, 0x2
        ctx->r15 = ctx->r13 & 0X2;
            goto L_800504E4;
    }
    // 0x800504D8: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x800504DC: beq         $t7, $zero, L_800504B4
    if (ctx->r15 == 0) {
        // 0x800504E0: nop

            goto L_800504B4;
    }
    // 0x800504E0: nop

L_800504E4:
    // 0x800504E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800504E8: jal         0x800578E8
    // 0x800504EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_5;
    // 0x800504EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_5:
    // 0x800504F0: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x800504F4: jal         0x80056E88
    // 0x800504F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_6;
    // 0x800504F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800504FC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050500: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80050504: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80050508: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005050C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80050510: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80050514: lh          $a1, 0x42($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X42);
    // 0x80050518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005051C: jal         0x8004EF90
    // 0x80050520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_7;
    // 0x80050520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80050524: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050528: jal         0x800578E8
    // 0x8005052C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_800578E8(rdram, ctx);
        goto after_8;
    // 0x8005052C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_8:
    // 0x80050530: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80050534: jal         0x80056E88
    // 0x80050538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_9;
    // 0x80050538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8005053C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050540: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80050544: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80050548: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005054C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80050550: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80050554: lh          $a1, 0x42($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X42);
    // 0x80050558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005055C: jal         0x8004EF90
    // 0x80050560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_10;
    // 0x80050560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80050564: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050568: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005056C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80050570: lw          $t3, 0x58($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X58);
    // 0x80050574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050578: lbu         $a0, 0x16($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X16);
    // 0x8005057C: jal         0x8008312C
    // 0x80050580: nop

    func_8008312C(rdram, ctx);
        goto after_11;
    // 0x80050580: nop

    after_11:
    // 0x80050584: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050588: jal         0x800578E8
    // 0x8005058C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800578E8(rdram, ctx);
        goto after_12;
    // 0x8005058C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_12:
    // 0x80050590: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80050594: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050598: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x8005059C: nop

    // 0x800505A0: beq         $t5, $at, L_80050618
    if (ctx->r13 == ctx->r1) {
        // 0x800505A4: nop

            goto L_80050618;
    }
    // 0x800505A4: nop

    // 0x800505A8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800505AC: nop

    // 0x800505B0: beq         $t6, $zero, L_800505CC
    if (ctx->r14 == 0) {
        // 0x800505B4: nop

            goto L_800505CC;
    }
    // 0x800505B4: nop

    // 0x800505B8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800505BC: nop

    // 0x800505C0: lh          $s1, 0x2($t7)
    ctx->r17 = MEM_H(ctx->r15, 0X2);
    // 0x800505C4: b           L_800505DC
    // 0x800505C8: addiu       $s1, $s1, 0x2710
    ctx->r17 = ADD32(ctx->r17, 0X2710);
        goto L_800505DC;
    // 0x800505C8: addiu       $s1, $s1, 0x2710
    ctx->r17 = ADD32(ctx->r17, 0X2710);
L_800505CC:
    // 0x800505CC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800505D0: nop

    // 0x800505D4: lh          $s1, 0x2($t8)
    ctx->r17 = MEM_H(ctx->r24, 0X2);
    // 0x800505D8: nop

L_800505DC:
    // 0x800505DC: jal         0x80062678
    // 0x800505E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80062678(rdram, ctx);
        goto after_13;
    // 0x800505E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800505E4: jal         0x80031AC8
    // 0x800505E8: nop

    func_80031AC8(rdram, ctx);
        goto after_14;
    // 0x800505E8: nop

    after_14:
    // 0x800505EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800505F0: beq         $v0, $at, L_80050618
    if (ctx->r2 == ctx->r1) {
        // 0x800505F4: nop

            goto L_80050618;
    }
    // 0x800505F4: nop

L_800505F8:
    // 0x800505F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800505FC: jal         0x800499B0
    // 0x80050600: nop

    func_800499B0(rdram, ctx);
        goto after_15;
    // 0x80050600: nop

    after_15:
    // 0x80050604: jal         0x80031AC8
    // 0x80050608: nop

    func_80031AC8(rdram, ctx);
        goto after_16;
    // 0x80050608: nop

    after_16:
    // 0x8005060C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050610: bne         $v0, $at, L_800505F8
    if (ctx->r2 != ctx->r1) {
        // 0x80050614: nop

            goto L_800505F8;
    }
    // 0x80050614: nop

L_80050618:
    // 0x80050618: jal         0x80031AC8
    // 0x8005061C: nop

    func_80031AC8(rdram, ctx);
        goto after_17;
    // 0x8005061C: nop

    after_17:
    // 0x80050620: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80050624: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80050628: nop

    // 0x8005062C: beq         $t9, $zero, L_80050674
    if (ctx->r25 == 0) {
        // 0x80050630: nop

            goto L_80050674;
    }
    // 0x80050630: nop

    // 0x80050634: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80050638: beq         $t9, $at, L_80050674
    if (ctx->r25 == ctx->r1) {
        // 0x8005063C: nop

            goto L_80050674;
    }
    // 0x8005063C: nop

L_80050640:
    // 0x80050640: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050644: jal         0x800499B0
    // 0x80050648: nop

    func_800499B0(rdram, ctx);
        goto after_18;
    // 0x80050648: nop

    after_18:
    // 0x8005064C: jal         0x80031AC8
    // 0x80050650: nop

    func_80031AC8(rdram, ctx);
        goto after_19;
    // 0x80050650: nop

    after_19:
    // 0x80050654: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80050658: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005065C: nop

    // 0x80050660: beq         $t0, $zero, L_80050674
    if (ctx->r8 == 0) {
        // 0x80050664: nop

            goto L_80050674;
    }
    // 0x80050664: nop

    // 0x80050668: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8005066C: bne         $t0, $at, L_80050640
    if (ctx->r8 != ctx->r1) {
        // 0x80050670: nop

            goto L_80050640;
    }
    // 0x80050670: nop

L_80050674:
    // 0x80050674: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050678: jal         0x800578E8
    // 0x8005067C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_20;
    // 0x8005067C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_20:
    // 0x80050680: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050684: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050688: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8005068C: lw          $t2, 0x58($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X58);
    // 0x80050690: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050694: lbu         $a0, 0x16($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X16);
    // 0x80050698: jal         0x8008312C
    // 0x8005069C: nop

    func_8008312C(rdram, ctx);
        goto after_21;
    // 0x8005069C: nop

    after_21:
    // 0x800506A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800506A4: jal         0x800578E8
    // 0x800506A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_22;
    // 0x800506A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_22:
    // 0x800506AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800506B0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800506B4: nop

    // 0x800506B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800506BC: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800506C0: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x800506C4: xori        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 ^ 0X8;
    // 0x800506C8: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x800506CC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800506D0: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x800506D4: jal         0x80056E88
    // 0x800506D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_23;
    // 0x800506D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x800506DC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800506E0: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x800506E4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800506E8: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800506EC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800506F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800506F4: lh          $a1, 0x42($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X42);
    // 0x800506F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800506FC: jal         0x8004EF90
    // 0x80050700: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_24;
    // 0x80050700: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x80050704: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050708: jal         0x800578E8
    // 0x8005070C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_800578E8(rdram, ctx);
        goto after_25;
    // 0x8005070C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_25:
    // 0x80050710: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050714: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050718: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8005071C: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
    // 0x80050720: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80050724: jal         0x80056E88
    // 0x80050728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_26;
    // 0x80050728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x8005072C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050730: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x80050734: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80050738: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005073C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80050740: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80050744: lh          $a1, 0x42($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X42);
    // 0x80050748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005074C: jal         0x8004EF90
    // 0x80050750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_27;
    // 0x80050750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80050754: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80050758: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005075C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80050760: lw          $t6, 0x58($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X58);
    // 0x80050764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050768: lbu         $a0, 0x16($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X16);
    // 0x8005076C: jal         0x8008312C
    // 0x80050770: nop

    func_8008312C(rdram, ctx);
        goto after_28;
    // 0x80050770: nop

    after_28:
    // 0x80050774: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050778: jal         0x800578E8
    // 0x8005077C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800578E8(rdram, ctx);
        goto after_29;
    // 0x8005077C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_29:
    // 0x80050780: b           L_80050798
    // 0x80050784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80050798;
    // 0x80050784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050788:
    // 0x80050788: b           L_80050798
    // 0x8005078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050798;
    // 0x8005078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80050790: b           L_80050798
    // 0x80050794: nop

        goto L_80050798;
    // 0x80050794: nop

L_80050798:
    // 0x80050798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005079C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800507A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800507A4: jr          $ra
    // 0x800507A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800507A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800507AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800507AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800507B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800507B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800507B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800507BC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800507C0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800507C4: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x800507C8: addiu       $at, $zero, 0xCF
    ctx->r1 = ADD32(0, 0XCF);
    // 0x800507CC: bne         $t6, $at, L_800507E4
    if (ctx->r14 != ctx->r1) {
        // 0x800507D0: nop

            goto L_800507E4;
    }
    // 0x800507D0: nop

    // 0x800507D4: jal         0x800B9000
    // 0x800507D8: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x800507D8: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_0:
    // 0x800507DC: jal         0x800B9000
    // 0x800507E0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x800507E0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
L_800507E4:
    // 0x800507E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800507E8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800507EC: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x800507F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800507F4: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x800507F8: jal         0x8004EF90
    // 0x800507FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_2;
    // 0x800507FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80050800: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050804: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050808: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005080C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050810: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050814: bne         $t2, $zero, L_80050910
    if (ctx->r10 != 0) {
        // 0x80050818: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_80050910;
    }
    // 0x80050818: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x8005081C: bne         $t3, $zero, L_80050910
    if (ctx->r11 != 0) {
        // 0x80050820: nop

            goto L_80050910;
    }
    // 0x80050820: nop

L_80050824:
    // 0x80050824: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050828: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005082C: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x80050830: lh          $t4, 0x4A($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X4A);
    // 0x80050834: nop

    // 0x80050838: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x8005083C: bne         $t5, $at, L_800508E0
    if (ctx->r13 != ctx->r1) {
        // 0x80050840: nop

            goto L_800508E0;
    }
    // 0x80050840: nop

    // 0x80050844: lw          $t6, 0x50($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X50);
    // 0x80050848: nop

    // 0x8005084C: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x80050850: nop

    // 0x80050854: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80050858: beq         $at, $zero, L_800508E0
    if (ctx->r1 == 0) {
        // 0x8005085C: nop

            goto L_800508E0;
    }
    // 0x8005085C: nop

    // 0x80050860: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050864: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050868: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005086C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050870: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050874: bne         $t2, $zero, L_80050884
    if (ctx->r10 != 0) {
        // 0x80050878: andi        $t3, $t1, 0x8
        ctx->r11 = ctx->r9 & 0X8;
            goto L_80050884;
    }
    // 0x80050878: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x8005087C: beq         $t3, $zero, L_80050898
    if (ctx->r11 == 0) {
        // 0x80050880: nop

            goto L_80050898;
    }
    // 0x80050880: nop

L_80050884:
    // 0x80050884: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80050888: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005088C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80050890: b           L_800508A8
    // 0x80050894: nop

        goto L_800508A8;
    // 0x80050894: nop

L_80050898:
    // 0x80050898: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005089C: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800508A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800508A4: nop

L_800508A8:
    // 0x800508A8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800508AC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800508B0: nop

    // 0x800508B4: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800508B8: nop

    // 0x800508BC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800508C0: add.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d);
    ctx->f8.d = ctx->f6.d + ctx->f20.d;
    // 0x800508C4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800508C8: swc1        $f10, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f10.u32l;
    // 0x800508CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800508D0: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x800508D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800508D8: jal         0x8005D07C
    // 0x800508DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_3;
    // 0x800508DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
L_800508E0:
    // 0x800508E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800508E4: jal         0x800499B0
    // 0x800508E8: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x800508E8: nop

    after_4:
    // 0x800508EC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800508F0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800508F4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800508F8: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x800508FC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80050900: bne         $t8, $zero, L_80050910
    if (ctx->r24 != 0) {
        // 0x80050904: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_80050910;
    }
    // 0x80050904: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x80050908: beq         $t9, $zero, L_80050824
    if (ctx->r25 == 0) {
        // 0x8005090C: nop

            goto L_80050824;
    }
    // 0x8005090C: nop

L_80050910:
    // 0x80050910: b           L_80050918
    // 0x80050914: nop

        goto L_80050918;
    // 0x80050914: nop

L_80050918:
    // 0x80050918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005091C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80050920: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80050924: jr          $ra
    // 0x80050928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80050928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005092C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005092C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005093C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050940: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80050944: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x80050948: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8005094C: lh          $a1, 0x42($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X42);
    // 0x80050950: jal         0x8004EF90
    // 0x80050954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_0;
    // 0x80050954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80050958: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005095C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050960: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80050964: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80050968: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8005096C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80050970: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80050974: bne         $t0, $zero, L_800509BC
    if (ctx->r8 != 0) {
        // 0x80050978: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_800509BC;
    }
    // 0x80050978: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005097C: bne         $t1, $zero, L_800509BC
    if (ctx->r9 != 0) {
        // 0x80050980: nop

            goto L_800509BC;
    }
    // 0x80050980: nop

L_80050984:
    // 0x80050984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80050988: jal         0x800499B0
    // 0x8005098C: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8005098C: nop

    after_1:
    // 0x80050990: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050994: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80050998: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8005099C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800509A0: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x800509A4: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800509A8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800509AC: bne         $t6, $zero, L_800509BC
    if (ctx->r14 != 0) {
        // 0x800509B0: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_800509BC;
    }
    // 0x800509B0: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800509B4: beq         $t7, $zero, L_80050984
    if (ctx->r15 == 0) {
        // 0x800509B8: nop

            goto L_80050984;
    }
    // 0x800509B8: nop

L_800509BC:
    // 0x800509BC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800509C0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800509C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800509C8: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x800509CC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800509D0: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800509D4: bne         $t0, $zero, L_800509E4
    if (ctx->r8 != 0) {
        // 0x800509D8: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_800509E4;
    }
    // 0x800509D8: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800509DC: beq         $t1, $zero, L_80050A0C
    if (ctx->r9 == 0) {
        // 0x800509E0: nop

            goto L_80050A0C;
    }
    // 0x800509E0: nop

L_800509E4:
    // 0x800509E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800509E8: jal         0x800507AC
    // 0x800509EC: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x800509EC: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_2:
    // 0x800509F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800509F4: jal         0x800507AC
    // 0x800509F8: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800507AC(rdram, ctx);
        goto after_3;
    // 0x800509F8: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_3:
    // 0x800509FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80050A00: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x80050A04: jal         0x80052508
    // 0x80050A08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_4;
    // 0x80050A08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80050A0C:
    // 0x80050A0C: b           L_80050A14
    // 0x80050A10: nop

        goto L_80050A14;
    // 0x80050A10: nop

L_80050A14:
    // 0x80050A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050A1C: jr          $ra
    // 0x80050A20: nop

    return;
    // 0x80050A20: nop

;}
RECOMP_FUNC void func_80050A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050A2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80050A30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80050A34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80050A38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80050A3C: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80050A40: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80050A44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80050A48: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80050A4C: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x80050A50: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80050A54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80050A58: jal         0x8004F3E8
    // 0x80050A5C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8004F3E8(rdram, ctx);
        goto after_0;
    // 0x80050A5C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80050A60: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80050A64: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050A68: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050A6C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050A70: bne         $t2, $zero, L_80050AAC
    if (ctx->r10 != 0) {
        // 0x80050A74: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_80050AAC;
    }
    // 0x80050A74: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x80050A78: bne         $t3, $zero, L_80050AAC
    if (ctx->r11 != 0) {
        // 0x80050A7C: nop

            goto L_80050AAC;
    }
    // 0x80050A7C: nop

L_80050A80:
    // 0x80050A80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80050A84: jal         0x800499B0
    // 0x80050A88: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x80050A88: nop

    after_1:
    // 0x80050A8C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80050A90: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80050A94: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80050A98: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80050A9C: bne         $t6, $zero, L_80050AAC
    if (ctx->r14 != 0) {
        // 0x80050AA0: andi        $t7, $t5, 0x2
        ctx->r15 = ctx->r13 & 0X2;
            goto L_80050AAC;
    }
    // 0x80050AA0: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x80050AA4: beq         $t7, $zero, L_80050A80
    if (ctx->r15 == 0) {
        // 0x80050AA8: nop

            goto L_80050A80;
    }
    // 0x80050AA8: nop

L_80050AAC:
    // 0x80050AAC: b           L_80050AB4
    // 0x80050AB0: nop

        goto L_80050AB4;
    // 0x80050AB0: nop

L_80050AB4:
    // 0x80050AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80050AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050ABC: jr          $ra
    // 0x80050AC0: nop

    return;
    // 0x80050AC0: nop

;}
RECOMP_FUNC void func_80050AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050AC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050ACC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80050AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80050AD4:
    // 0x80050AD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050AD8: lw          $t6, 0x6CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6CC);
    // 0x80050ADC: nop

    // 0x80050AE0: beq         $t6, $zero, L_8005110C
    if (ctx->r14 == 0) {
        // 0x80050AE4: nop

            goto L_8005110C;
    }
    // 0x80050AE4: nop

    // 0x80050AE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050AEC: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80050AF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050AF4: bne         $t7, $at, L_8005110C
    if (ctx->r15 != ctx->r1) {
        // 0x80050AF8: nop

            goto L_8005110C;
    }
    // 0x80050AF8: nop

    // 0x80050AFC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050B00: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050B04: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80050B08: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050B0C: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x80050B10: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050B14: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050B18: bne         $t2, $zero, L_8005110C
    if (ctx->r10 != 0) {
        // 0x80050B1C: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8005110C;
    }
    // 0x80050B1C: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80050B20: bne         $t3, $zero, L_8005110C
    if (ctx->r11 != 0) {
        // 0x80050B24: nop

            goto L_8005110C;
    }
    // 0x80050B24: nop

    // 0x80050B28: jal         0x80057960
    // 0x80050B2C: nop

    func_80057960(rdram, ctx);
        goto after_0;
    // 0x80050B2C: nop

    after_0:
    // 0x80050B30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80050B34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80050B38: nop

    // 0x80050B3C: bne         $t9, $zero, L_8005110C
    if (ctx->r25 != 0) {
        // 0x80050B40: nop

            goto L_8005110C;
    }
    // 0x80050B40: nop

L_80050B44:
    // 0x80050B44: jal         0x80055148
    // 0x80050B48: nop

    func_80055148(rdram, ctx);
        goto after_1;
    // 0x80050B48: nop

    after_1:
    // 0x80050B4C: beq         $v0, $zero, L_80050B5C
    if (ctx->r2 == 0) {
        // 0x80050B50: nop

            goto L_80050B5C;
    }
    // 0x80050B50: nop

    // 0x80050B54: b           L_8005110C
    // 0x80050B58: nop

        goto L_8005110C;
    // 0x80050B58: nop

L_80050B5C:
    // 0x80050B5C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80050B60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80050B68: jal         0x80052508
    // 0x80050B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_2;
    // 0x80050B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80050B70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80050B74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050B78: beq         $s0, $at, L_80050BA0
    if (ctx->r16 == ctx->r1) {
        // 0x80050B7C: nop

            goto L_80050BA0;
    }
    // 0x80050B7C: nop

    // 0x80050B80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050B84: beq         $s0, $at, L_80050BA0
    if (ctx->r16 == ctx->r1) {
        // 0x80050B88: nop

            goto L_80050BA0;
    }
    // 0x80050B88: nop

    // 0x80050B8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050B90: beq         $s0, $at, L_80050BB0
    if (ctx->r16 == ctx->r1) {
        // 0x80050B94: nop

            goto L_80050BB0;
    }
    // 0x80050B94: nop

    // 0x80050B98: b           L_80050BC0
    // 0x80050B9C: nop

        goto L_80050BC0;
    // 0x80050B9C: nop

L_80050BA0:
    // 0x80050BA0: addiu       $t4, $zero, 0x70
    ctx->r12 = ADD32(0, 0X70);
    // 0x80050BA4: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80050BA8: b           L_80050E20
    // 0x80050BAC: nop

        goto L_80050E20;
    // 0x80050BAC: nop

L_80050BB0:
    // 0x80050BB0: addiu       $t5, $zero, 0x70
    ctx->r13 = ADD32(0, 0X70);
    // 0x80050BB4: sh          $t5, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r13;
    // 0x80050BB8: b           L_80050E20
    // 0x80050BBC: nop

        goto L_80050E20;
    // 0x80050BBC: nop

L_80050BC0:
    // 0x80050BC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050BC4: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x80050BC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80050BCC: beq         $t6, $at, L_80050BF8
    if (ctx->r14 == ctx->r1) {
        // 0x80050BD0: nop

            goto L_80050BF8;
    }
    // 0x80050BD0: nop

    // 0x80050BD4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80050BD8: bne         $t6, $at, L_80050D44
    if (ctx->r14 != ctx->r1) {
        // 0x80050BDC: nop

            goto L_80050D44;
    }
    // 0x80050BDC: nop

    // 0x80050BE0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80050BE4: lhu         $t7, -0x6504($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6504);
    // 0x80050BE8: nop

    // 0x80050BEC: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80050BF0: beq         $t8, $zero, L_80050D44
    if (ctx->r24 == 0) {
        // 0x80050BF4: nop

            goto L_80050D44;
    }
    // 0x80050BF4: nop

L_80050BF8:
    // 0x80050BF8: jal         0x80061E14
    // 0x80050BFC: nop

    func_80061E14(rdram, ctx);
        goto after_3;
    // 0x80050BFC: nop

    after_3:
    // 0x80050C00: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80050C04: beq         $v0, $at, L_80050C60
    if (ctx->r2 == ctx->r1) {
        // 0x80050C08: nop

            goto L_80050C60;
    }
    // 0x80050C08: nop

    // 0x80050C0C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80050C10: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80050C14: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80050C18: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80050C1C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80050C20: bne         $t4, $zero, L_80050C60
    if (ctx->r12 != 0) {
        // 0x80050C24: andi        $t5, $t3, 0x20
        ctx->r13 = ctx->r11 & 0X20;
            goto L_80050C60;
    }
    // 0x80050C24: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80050C28: bne         $t5, $zero, L_80050C60
    if (ctx->r13 != 0) {
        // 0x80050C2C: nop

            goto L_80050C60;
    }
    // 0x80050C2C: nop

    // 0x80050C30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050C34: jal         0x800507AC
    // 0x80050C38: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800507AC(rdram, ctx);
        goto after_4;
    // 0x80050C38: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_4:
    // 0x80050C3C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050C40: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050C44: nop

    // 0x80050C48: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80050C4C: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80050C50: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x80050C54: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x80050C58: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80050C5C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_80050C60:
    // 0x80050C60: jal         0x80061E14
    // 0x80050C64: nop

    func_80061E14(rdram, ctx);
        goto after_5;
    // 0x80050C64: nop

    after_5:
    // 0x80050C68: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80050C6C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80050C70: nop

    // 0x80050C74: beq         $t0, $zero, L_80050C8C
    if (ctx->r8 == 0) {
        // 0x80050C78: nop

            goto L_80050C8C;
    }
    // 0x80050C78: nop

    // 0x80050C7C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80050C80: nop

    // 0x80050C84: addiu       $t3, $t2, -0x17
    ctx->r11 = ADD32(ctx->r10, -0X17);
    // 0x80050C88: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80050C8C:
    // 0x80050C8C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80050C90: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80050C94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80050C98: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80050C9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050CA0: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x80050CA4: lw          $t7, -0x27E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X27E0);
    // 0x80050CA8: nop

    // 0x80050CAC: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80050CB0: beq         $at, $zero, L_80050D28
    if (ctx->r1 == 0) {
        // 0x80050CB4: nop

            goto L_80050D28;
    }
    // 0x80050CB4: nop

    // 0x80050CB8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80050CBC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80050CC0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80050CC4: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80050CC8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050CCC: lw          $t8, 0x670($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X670);
    // 0x80050CD0: lw          $t0, -0x27E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X27E0);
    // 0x80050CD4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80050CD8: div         $zero, $t8, $t0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r8)));
    // 0x80050CDC: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80050CE0: lw          $t5, -0x27F4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X27F4);
    // 0x80050CE4: bne         $t0, $zero, L_80050CF0
    if (ctx->r8 != 0) {
        // 0x80050CE8: nop

            goto L_80050CF0;
    }
    // 0x80050CE8: nop

    // 0x80050CEC: break       7
    do_break(2147814636);
L_80050CF0:
    // 0x80050CF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050CF4: bne         $t0, $at, L_80050D08
    if (ctx->r8 != ctx->r1) {
        // 0x80050CF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80050D08;
    }
    // 0x80050CF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80050CFC: bne         $t8, $at, L_80050D08
    if (ctx->r24 != ctx->r1) {
        // 0x80050D00: nop

            goto L_80050D08;
    }
    // 0x80050D00: nop

    // 0x80050D04: break       6
    do_break(2147814660);
L_80050D08:
    // 0x80050D08: mfhi        $t2
    ctx->r10 = hi;
    // 0x80050D0C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80050D10: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x80050D14: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80050D18: nop

    // 0x80050D1C: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80050D20: b           L_80050E20
    // 0x80050D24: nop

        goto L_80050E20;
    // 0x80050D24: nop

L_80050D28:
    // 0x80050D28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050D2C: jal         0x80051700
    // 0x80050D30: nop

    func_80051700(rdram, ctx);
        goto after_6;
    // 0x80050D30: nop

    after_6:
    // 0x80050D34: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80050D38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80050D3C: b           L_80050E20
    // 0x80050D40: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_80050E20;
    // 0x80050D40: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_80050D44:
    // 0x80050D44: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050D48: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050D4C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80050D50: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80050D54: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80050D58: bne         $t0, $zero, L_80050D68
    if (ctx->r8 != 0) {
        // 0x80050D5C: andi        $t1, $t9, 0x20
        ctx->r9 = ctx->r25 & 0X20;
            goto L_80050D68;
    }
    // 0x80050D5C: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x80050D60: beq         $t1, $zero, L_80050D9C
    if (ctx->r9 == 0) {
        // 0x80050D64: nop

            goto L_80050D9C;
    }
    // 0x80050D64: nop

L_80050D68:
    // 0x80050D68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050D6C: jal         0x800507AC
    // 0x80050D70: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    func_800507AC(rdram, ctx);
        goto after_7;
    // 0x80050D70: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_7:
    // 0x80050D74: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050D78: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80050D7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050D80: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80050D84: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x80050D88: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x80050D8C: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80050D90: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x80050D94: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80050D98: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80050D9C:
    // 0x80050D9C: jal         0x80061E14
    // 0x80050DA0: nop

    func_80061E14(rdram, ctx);
        goto after_8;
    // 0x80050DA0: nop

    after_8:
    // 0x80050DA4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80050DA8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80050DAC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80050DB0: beq         $t3, $at, L_80050DF0
    if (ctx->r11 == ctx->r1) {
        // 0x80050DB4: nop

            goto L_80050DF0;
    }
    // 0x80050DB4: nop

    // 0x80050DB8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80050DBC: beq         $t3, $at, L_80050DF0
    if (ctx->r11 == ctx->r1) {
        // 0x80050DC0: nop

            goto L_80050DF0;
    }
    // 0x80050DC0: nop

    // 0x80050DC4: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80050DC8: beq         $t3, $at, L_80050DF0
    if (ctx->r11 == ctx->r1) {
        // 0x80050DCC: nop

            goto L_80050DF0;
    }
    // 0x80050DCC: nop

    // 0x80050DD0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050DD4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80050DD8: nop

    // 0x80050DDC: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x80050DE0: nop

    // 0x80050DE4: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80050DE8: bne         $at, $zero, L_80050E0C
    if (ctx->r1 != 0) {
        // 0x80050DEC: nop

            goto L_80050E0C;
    }
    // 0x80050DEC: nop

L_80050DF0:
    // 0x80050DF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050DF4: jal         0x80051700
    // 0x80050DF8: nop

    func_80051700(rdram, ctx);
        goto after_9;
    // 0x80050DF8: nop

    after_9:
    // 0x80050DFC: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80050E00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80050E04: b           L_80050E20
    // 0x80050E08: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
        goto L_80050E20;
    // 0x80050E08: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_80050E0C:
    // 0x80050E0C: jal         0x8005151C
    // 0x80050E10: nop

    func_8005151C(rdram, ctx);
        goto after_10;
    // 0x80050E10: nop

    after_10:
    // 0x80050E14: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80050E18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80050E1C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80050E20:
    // 0x80050E20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050E24: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80050E28: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80050E2C: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x80050E30: nop

    // 0x80050E34: bne         $t7, $t4, L_80050E50
    if (ctx->r15 != ctx->r12) {
        // 0x80050E38: nop

            goto L_80050E50;
    }
    // 0x80050E38: nop

    // 0x80050E3C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050E40: jal         0x800499B0
    // 0x80050E44: nop

    func_800499B0(rdram, ctx);
        goto after_11;
    // 0x80050E44: nop

    after_11:
    // 0x80050E48: b           L_8005109C
    // 0x80050E4C: nop

        goto L_8005109C;
    // 0x80050E4C: nop

L_80050E50:
    // 0x80050E50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80050E54: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80050E58: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x80050E5C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80050E60: lh          $a1, 0x42($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X42);
    // 0x80050E64: jal         0x8004EF90
    // 0x80050E68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_12;
    // 0x80050E68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80050E6C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050E70: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80050E74: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80050E78: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80050E7C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80050E80: bne         $t0, $zero, L_80050EA0
    if (ctx->r8 != 0) {
        // 0x80050E84: andi        $t1, $t9, 0x100
        ctx->r9 = ctx->r25 & 0X100;
            goto L_80050EA0;
    }
    // 0x80050E84: andi        $t1, $t9, 0x100
    ctx->r9 = ctx->r25 & 0X100;
    // 0x80050E88: bne         $t1, $zero, L_80050EA0
    if (ctx->r9 != 0) {
        // 0x80050E8C: nop

            goto L_80050EA0;
    }
    // 0x80050E8C: nop

    // 0x80050E90: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80050E94: nop

    // 0x80050E98: beq         $t3, $zero, L_80050EB4
    if (ctx->r11 == 0) {
        // 0x80050E9C: nop

            goto L_80050EB4;
    }
    // 0x80050E9C: nop

L_80050EA0:
    // 0x80050EA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050EA4: jal         0x800499B0
    // 0x80050EA8: nop

    func_800499B0(rdram, ctx);
        goto after_13;
    // 0x80050EA8: nop

    after_13:
    // 0x80050EAC: b           L_8005109C
    // 0x80050EB0: nop

        goto L_8005109C;
    // 0x80050EB0: nop

L_80050EB4:
    // 0x80050EB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050EB8: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x80050EBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80050EC0: beq         $t6, $at, L_80050ED4
    if (ctx->r14 == ctx->r1) {
        // 0x80050EC4: nop

            goto L_80050ED4;
    }
    // 0x80050EC4: nop

    // 0x80050EC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80050ECC: bne         $t6, $at, L_80050FF4
    if (ctx->r14 != ctx->r1) {
        // 0x80050ED0: nop

            goto L_80050FF4;
    }
    // 0x80050ED0: nop

L_80050ED4:
    // 0x80050ED4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80050ED8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050EDC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050EE0: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x80050EE4: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80050EE8: bne         $t2, $zero, L_80050F78
    if (ctx->r10 != 0) {
        // 0x80050EEC: andi        $t3, $t5, 0x2
        ctx->r11 = ctx->r13 & 0X2;
            goto L_80050F78;
    }
    // 0x80050EEC: andi        $t3, $t5, 0x2
    ctx->r11 = ctx->r13 & 0X2;
    // 0x80050EF0: bne         $t3, $zero, L_80050F78
    if (ctx->r11 != 0) {
        // 0x80050EF4: nop

            goto L_80050F78;
    }
    // 0x80050EF4: nop

    // 0x80050EF8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80050EFC: bne         $t8, $zero, L_80050F78
    if (ctx->r24 != 0) {
        // 0x80050F00: andi        $t9, $t5, 0x1000
        ctx->r25 = ctx->r13 & 0X1000;
            goto L_80050F78;
    }
    // 0x80050F00: andi        $t9, $t5, 0x1000
    ctx->r25 = ctx->r13 & 0X1000;
    // 0x80050F04: bne         $t9, $zero, L_80050F78
    if (ctx->r25 != 0) {
        // 0x80050F08: nop

            goto L_80050F78;
    }
    // 0x80050F08: nop

    // 0x80050F0C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80050F10: lh          $t0, 0x10F0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X10F0);
    // 0x80050F14: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050F18: bne         $t0, $at, L_80050F78
    if (ctx->r8 != ctx->r1) {
        // 0x80050F1C: nop

            goto L_80050F78;
    }
    // 0x80050F1C: nop

L_80050F20:
    // 0x80050F20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050F24: jal         0x800499B0
    // 0x80050F28: nop

    func_800499B0(rdram, ctx);
        goto after_14;
    // 0x80050F28: nop

    after_14:
    // 0x80050F2C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050F30: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80050F34: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050F38: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80050F3C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80050F40: bne         $t2, $zero, L_80050F78
    if (ctx->r10 != 0) {
        // 0x80050F44: andi        $t3, $t7, 0x2
        ctx->r11 = ctx->r15 & 0X2;
            goto L_80050F78;
    }
    // 0x80050F44: andi        $t3, $t7, 0x2
    ctx->r11 = ctx->r15 & 0X2;
    // 0x80050F48: bne         $t3, $zero, L_80050F78
    if (ctx->r11 != 0) {
        // 0x80050F4C: nop

            goto L_80050F78;
    }
    // 0x80050F4C: nop

    // 0x80050F50: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80050F54: bne         $t4, $zero, L_80050F78
    if (ctx->r12 != 0) {
        // 0x80050F58: andi        $t5, $t7, 0x1000
        ctx->r13 = ctx->r15 & 0X1000;
            goto L_80050F78;
    }
    // 0x80050F58: andi        $t5, $t7, 0x1000
    ctx->r13 = ctx->r15 & 0X1000;
    // 0x80050F5C: bne         $t5, $zero, L_80050F78
    if (ctx->r13 != 0) {
        // 0x80050F60: nop

            goto L_80050F78;
    }
    // 0x80050F60: nop

    // 0x80050F64: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050F68: lh          $t8, 0x10F0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X10F0);
    // 0x80050F6C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050F70: beq         $t8, $at, L_80050F20
    if (ctx->r24 == ctx->r1) {
        // 0x80050F74: nop

            goto L_80050F20;
    }
    // 0x80050F74: nop

L_80050F78:
    // 0x80050F78: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050F7C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80050F80: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050F84: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80050F88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80050F8C: bne         $t2, $zero, L_80050F9C
    if (ctx->r10 != 0) {
        // 0x80050F90: andi        $t3, $t1, 0x1000
        ctx->r11 = ctx->r9 & 0X1000;
            goto L_80050F9C;
    }
    // 0x80050F90: andi        $t3, $t1, 0x1000
    ctx->r11 = ctx->r9 & 0X1000;
    // 0x80050F94: beq         $t3, $zero, L_80050FA4
    if (ctx->r11 == 0) {
        // 0x80050F98: nop

            goto L_80050FA4;
    }
    // 0x80050F98: nop

L_80050F9C:
    // 0x80050F9C: b           L_8005110C
    // 0x80050FA0: nop

        goto L_8005110C;
    // 0x80050FA0: nop

L_80050FA4:
    // 0x80050FA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050FA8: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x80050FAC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80050FB0: beq         $t6, $at, L_80050FEC
    if (ctx->r14 == ctx->r1) {
        // 0x80050FB4: nop

            goto L_80050FEC;
    }
    // 0x80050FB4: nop

    // 0x80050FB8: jal         0x80061F08
    // 0x80050FBC: nop

    func_80061F08(rdram, ctx);
        goto after_15;
    // 0x80050FBC: nop

    after_15:
    // 0x80050FC0: bne         $v0, $zero, L_80050FD8
    if (ctx->r2 != 0) {
        // 0x80050FC4: nop

            goto L_80050FD8;
    }
    // 0x80050FC4: nop

    // 0x80050FC8: b           L_8005110C
    // 0x80050FCC: nop

        goto L_8005110C;
    // 0x80050FCC: nop

    // 0x80050FD0: b           L_80050FEC
    // 0x80050FD4: nop

        goto L_80050FEC;
    // 0x80050FD4: nop

L_80050FD8:
    // 0x80050FD8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80050FDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80050FE0: sh          $t7, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r15;
    // 0x80050FE4: b           L_80050ED4
    // 0x80050FE8: nop

        goto L_80050ED4;
    // 0x80050FE8: nop

L_80050FEC:
    // 0x80050FEC: b           L_8005109C
    // 0x80050FF0: nop

        goto L_8005109C;
    // 0x80050FF0: nop

L_80050FF4:
    // 0x80050FF4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050FF8: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80050FFC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051000: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80051004: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80051008: bne         $t0, $zero, L_80051070
    if (ctx->r8 != 0) {
        // 0x8005100C: andi        $t1, $t9, 0x2
        ctx->r9 = ctx->r25 & 0X2;
            goto L_80051070;
    }
    // 0x8005100C: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x80051010: bne         $t1, $zero, L_80051070
    if (ctx->r9 != 0) {
        // 0x80051014: nop

            goto L_80051070;
    }
    // 0x80051014: nop

    // 0x80051018: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005101C: bne         $t2, $zero, L_80051070
    if (ctx->r10 != 0) {
        // 0x80051020: andi        $t3, $t9, 0x1000
        ctx->r11 = ctx->r25 & 0X1000;
            goto L_80051070;
    }
    // 0x80051020: andi        $t3, $t9, 0x1000
    ctx->r11 = ctx->r25 & 0X1000;
    // 0x80051024: bne         $t3, $zero, L_80051070
    if (ctx->r11 != 0) {
        // 0x80051028: nop

            goto L_80051070;
    }
    // 0x80051028: nop

L_8005102C:
    // 0x8005102C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051030: jal         0x800499B0
    // 0x80051034: nop

    func_800499B0(rdram, ctx);
        goto after_16;
    // 0x80051034: nop

    after_16:
    // 0x80051038: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005103C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051040: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051044: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80051048: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8005104C: bne         $t4, $zero, L_80051070
    if (ctx->r12 != 0) {
        // 0x80051050: andi        $t5, $t7, 0x2
        ctx->r13 = ctx->r15 & 0X2;
            goto L_80051070;
    }
    // 0x80051050: andi        $t5, $t7, 0x2
    ctx->r13 = ctx->r15 & 0X2;
    // 0x80051054: bne         $t5, $zero, L_80051070
    if (ctx->r13 != 0) {
        // 0x80051058: nop

            goto L_80051070;
    }
    // 0x80051058: nop

    // 0x8005105C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051060: bne         $t0, $zero, L_80051070
    if (ctx->r8 != 0) {
        // 0x80051064: andi        $t1, $t7, 0x1000
        ctx->r9 = ctx->r15 & 0X1000;
            goto L_80051070;
    }
    // 0x80051064: andi        $t1, $t7, 0x1000
    ctx->r9 = ctx->r15 & 0X1000;
    // 0x80051068: beq         $t1, $zero, L_8005102C
    if (ctx->r9 == 0) {
        // 0x8005106C: nop

            goto L_8005102C;
    }
    // 0x8005106C: nop

L_80051070:
    // 0x80051070: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051074: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80051078: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005107C: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x80051080: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x80051084: bne         $t4, $zero, L_80051094
    if (ctx->r12 != 0) {
        // 0x80051088: andi        $t5, $t3, 0x1000
        ctx->r13 = ctx->r11 & 0X1000;
            goto L_80051094;
    }
    // 0x80051088: andi        $t5, $t3, 0x1000
    ctx->r13 = ctx->r11 & 0X1000;
    // 0x8005108C: beq         $t5, $zero, L_8005109C
    if (ctx->r13 == 0) {
        // 0x80051090: nop

            goto L_8005109C;
    }
    // 0x80051090: nop

L_80051094:
    // 0x80051094: b           L_8005110C
    // 0x80051098: nop

        goto L_8005110C;
    // 0x80051098: nop

L_8005109C:
    // 0x8005109C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800510A0: lw          $t9, 0x6CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CC);
    // 0x800510A4: nop

    // 0x800510A8: beq         $t9, $zero, L_8005110C
    if (ctx->r25 == 0) {
        // 0x800510AC: nop

            goto L_8005110C;
    }
    // 0x800510AC: nop

    // 0x800510B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800510B4: lh          $t6, 0x10F0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X10F0);
    // 0x800510B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800510BC: bne         $t6, $at, L_8005110C
    if (ctx->r14 != ctx->r1) {
        // 0x800510C0: nop

            goto L_8005110C;
    }
    // 0x800510C0: nop

    // 0x800510C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800510C8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800510CC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800510D0: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x800510D4: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x800510D8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800510DC: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x800510E0: bne         $t8, $zero, L_8005110C
    if (ctx->r24 != 0) {
        // 0x800510E4: and         $t9, $t1, $at
        ctx->r25 = ctx->r9 & ctx->r1;
            goto L_8005110C;
    }
    // 0x800510E4: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x800510E8: bne         $t9, $zero, L_8005110C
    if (ctx->r25 != 0) {
        // 0x800510EC: nop

            goto L_8005110C;
    }
    // 0x800510EC: nop

    // 0x800510F0: jal         0x80057960
    // 0x800510F4: nop

    func_80057960(rdram, ctx);
        goto after_17;
    // 0x800510F4: nop

    after_17:
    // 0x800510F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800510FC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80051100: nop

    // 0x80051104: beq         $t2, $zero, L_80050B44
    if (ctx->r10 == 0) {
        // 0x80051108: nop

            goto L_80050B44;
    }
    // 0x80051108: nop

L_8005110C:
    // 0x8005110C: jal         0x80057960
    // 0x80051110: nop

    func_80057960(rdram, ctx);
        goto after_18;
    // 0x80051110: nop

    after_18:
    // 0x80051114: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80051118: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005111C: nop

    // 0x80051120: beq         $t3, $zero, L_80051138
    if (ctx->r11 == 0) {
        // 0x80051124: nop

            goto L_80051138;
    }
    // 0x80051124: nop

    // 0x80051128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005112C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x80051130: b           L_80051368
    // 0x80051134: nop

        goto L_80051368;
    // 0x80051134: nop

L_80051138:
    // 0x80051138: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005113C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051140: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051144: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80051148: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005114C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80051150: bne         $t0, $zero, L_80051160
    if (ctx->r8 != 0) {
        // 0x80051154: and         $t1, $t7, $at
        ctx->r9 = ctx->r15 & ctx->r1;
            goto L_80051160;
    }
    // 0x80051154: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x80051158: beq         $t1, $zero, L_80051170
    if (ctx->r9 == 0) {
        // 0x8005115C: nop

            goto L_80051170;
    }
    // 0x8005115C: nop

L_80051160:
    // 0x80051160: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051164: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x80051168: b           L_80051368
    // 0x8005116C: nop

        goto L_80051368;
    // 0x8005116C: nop

L_80051170:
    // 0x80051170: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80051174: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051178: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005117C: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x80051180: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80051184: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80051188: bne         $t2, $zero, L_80051198
    if (ctx->r10 != 0) {
        // 0x8005118C: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_80051198;
    }
    // 0x8005118C: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x80051190: beq         $t3, $zero, L_800511B8
    if (ctx->r11 == 0) {
        // 0x80051194: nop

            goto L_800511B8;
    }
    // 0x80051194: nop

L_80051198:
    // 0x80051198: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005119C: jal         0x80054618
    // 0x800511A0: nop

    func_80054618(rdram, ctx);
        goto after_19;
    // 0x800511A0: nop

    after_19:
    // 0x800511A4: jal         0x8005A768
    // 0x800511A8: nop

    func_8005A768(rdram, ctx);
        goto after_20;
    // 0x800511A8: nop

    after_20:
    // 0x800511AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800511B0: b           L_80051354
    // 0x800511B4: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
        goto L_80051354;
    // 0x800511B4: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
L_800511B8:
    // 0x800511B8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800511BC: lh          $t4, 0x10F0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X10F0);
    // 0x800511C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800511C4: bne         $t4, $at, L_800511F0
    if (ctx->r12 != ctx->r1) {
        // 0x800511C8: nop

            goto L_800511F0;
    }
    // 0x800511C8: nop

    // 0x800511CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800511D0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800511D4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800511D8: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x800511DC: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800511E0: bne         $t8, $zero, L_800511F0
    if (ctx->r24 != 0) {
        // 0x800511E4: andi        $t9, $t1, 0x1000
        ctx->r25 = ctx->r9 & 0X1000;
            goto L_800511F0;
    }
    // 0x800511E4: andi        $t9, $t1, 0x1000
    ctx->r25 = ctx->r9 & 0X1000;
    // 0x800511E8: beq         $t9, $zero, L_80051298
    if (ctx->r25 == 0) {
        // 0x800511EC: nop

            goto L_80051298;
    }
    // 0x800511EC: nop

L_800511F0:
    // 0x800511F0: jal         0x80061F08
    // 0x800511F4: nop

    func_80061F08(rdram, ctx);
        goto after_21;
    // 0x800511F4: nop

    after_21:
    // 0x800511F8: bne         $v0, $zero, L_80051258
    if (ctx->r2 != 0) {
        // 0x800511FC: nop

            goto L_80051258;
    }
    // 0x800511FC: nop

    // 0x80051200: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051204: lh          $t7, 0x10F0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X10F0);
    // 0x80051208: nop

    // 0x8005120C: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80051210: beq         $at, $zero, L_80051248
    if (ctx->r1 == 0) {
        // 0x80051214: nop

            goto L_80051248;
    }
    // 0x80051214: nop

    // 0x80051218: jal         0x8005A578
    // 0x8005121C: nop

    func_8005A578(rdram, ctx);
        goto after_22;
    // 0x8005121C: nop

    after_22:
    // 0x80051220: bne         $v0, $zero, L_80051248
    if (ctx->r2 != 0) {
        // 0x80051224: nop

            goto L_80051248;
    }
    // 0x80051224: nop

    // 0x80051228: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005122C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051230: sh          $t5, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r13;
    // 0x80051234: jal         0x8005A768
    // 0x80051238: nop

    func_8005A768(rdram, ctx);
        goto after_23;
    // 0x80051238: nop

    after_23:
    // 0x8005123C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051240: b           L_80051250
    // 0x80051244: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
        goto L_80051250;
    // 0x80051244: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
L_80051248:
    // 0x80051248: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005124C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
L_80051250:
    // 0x80051250: b           L_80051290
    // 0x80051254: nop

        goto L_80051290;
    // 0x80051254: nop

L_80051258:
    // 0x80051258: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8005125C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051260: sh          $t2, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r10;
    // 0x80051264: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80051268: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005126C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80051270: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80051274: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80051278: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8005127C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x80051280: ori         $at, $at, 0xEFFF
    ctx->r1 = ctx->r1 | 0XEFFF;
    // 0x80051284: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80051288: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8005128C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_80051290:
    // 0x80051290: b           L_80051354
    // 0x80051294: nop

        goto L_80051354;
    // 0x80051294: nop

L_80051298:
    // 0x80051298: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005129C: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800512A0: nop

    // 0x800512A4: bne         $t0, $zero, L_800512CC
    if (ctx->r8 != 0) {
        // 0x800512A8: nop

            goto L_800512CC;
    }
    // 0x800512A8: nop

    // 0x800512AC: jal         0x8005A578
    // 0x800512B0: nop

    func_8005A578(rdram, ctx);
        goto after_24;
    // 0x800512B0: nop

    after_24:
    // 0x800512B4: bne         $v0, $zero, L_800512E0
    if (ctx->r2 != 0) {
        // 0x800512B8: nop

            goto L_800512E0;
    }
    // 0x800512B8: nop

    // 0x800512BC: jal         0x80061F08
    // 0x800512C0: nop

    func_80061F08(rdram, ctx);
        goto after_25;
    // 0x800512C0: nop

    after_25:
    // 0x800512C4: bne         $v0, $zero, L_800512E0
    if (ctx->r2 != 0) {
        // 0x800512C8: nop

            goto L_800512E0;
    }
    // 0x800512C8: nop

L_800512CC:
    // 0x800512CC: jal         0x8005A768
    // 0x800512D0: nop

    func_8005A768(rdram, ctx);
        goto after_26;
    // 0x800512D0: nop

    after_26:
    // 0x800512D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800512D8: b           L_80051354
    // 0x800512DC: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
        goto L_80051354;
    // 0x800512DC: sw          $v0, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r2;
L_800512E0:
    // 0x800512E0: jal         0x80061E14
    // 0x800512E4: nop

    func_80061E14(rdram, ctx);
        goto after_27;
    // 0x800512E4: nop

    after_27:
    // 0x800512E8: bne         $v0, $zero, L_80051354
    if (ctx->r2 != 0) {
        // 0x800512EC: nop

            goto L_80051354;
    }
    // 0x800512EC: nop

    // 0x800512F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800512F4: lwc1        $f4, 0xDA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XDA0);
    // 0x800512F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800512FC: nop

    // 0x80051300: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80051304: nop

    // 0x80051308: bc1f        L_80051348
    if (!c1cs) {
        // 0x8005130C: nop

            goto L_80051348;
    }
    // 0x8005130C: nop

    // 0x80051310: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051314: lwc1        $f8, 0xE48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE48);
    // 0x80051318: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005131C: nop

    // 0x80051320: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80051324: nop

    // 0x80051328: bc1f        L_80051348
    if (!c1cs) {
        // 0x8005132C: nop

            goto L_80051348;
    }
    // 0x8005132C: nop

    // 0x80051330: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80051334: lbu         $t1, 0x125A($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X125A);
    // 0x80051338: nop

    // 0x8005133C: andi        $t8, $t1, 0x2
    ctx->r24 = ctx->r9 & 0X2;
    // 0x80051340: beq         $t8, $zero, L_80051354
    if (ctx->r24 == 0) {
        // 0x80051344: nop

            goto L_80051354;
    }
    // 0x80051344: nop

L_80051348:
    // 0x80051348: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8005134C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051350: sw          $t9, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r25;
L_80051354:
    // 0x80051354: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051358: lw          $t2, 0x6CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6CC);
    // 0x8005135C: nop

    // 0x80051360: bne         $t2, $zero, L_80050AD4
    if (ctx->r10 != 0) {
        // 0x80051364: nop

            goto L_80050AD4;
    }
    // 0x80051364: nop

L_80051368:
    // 0x80051368: b           L_80051370
    // 0x8005136C: nop

        goto L_80051370;
    // 0x8005136C: nop

L_80051370:
    // 0x80051370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80051374: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051378: jr          $ra
    // 0x8005137C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005137C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80051380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051384: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80051388: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005138C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80051390: jal         0x80056118
    // 0x80051394: nop

    func_80056118(rdram, ctx);
        goto after_0;
    // 0x80051394: nop

    after_0:
    // 0x80051398: bne         $v0, $zero, L_800513A8
    if (ctx->r2 != 0) {
        // 0x8005139C: nop

            goto L_800513A8;
    }
    // 0x8005139C: nop

    // 0x800513A0: b           L_80051508
    // 0x800513A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x800513A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800513A8:
    // 0x800513A8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800513AC: lh          $s0, 0x10F0($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X10F0);
    // 0x800513B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800513B4: beq         $s0, $at, L_800513D0
    if (ctx->r16 == ctx->r1) {
        // 0x800513B8: nop

            goto L_800513D0;
    }
    // 0x800513B8: nop

    // 0x800513BC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800513C0: beq         $s0, $at, L_8005148C
    if (ctx->r16 == ctx->r1) {
        // 0x800513C4: nop

            goto L_8005148C;
    }
    // 0x800513C4: nop

    // 0x800513C8: b           L_800514EC
    // 0x800513CC: nop

        goto L_800514EC;
    // 0x800513CC: nop

L_800513D0:
    // 0x800513D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800513D4: lw          $t6, 0x11A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11A0);
    // 0x800513D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800513DC: lh          $s0, 0x0($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X0);
    // 0x800513E0: nop

    // 0x800513E4: beq         $s0, $at, L_8005140C
    if (ctx->r16 == ctx->r1) {
        // 0x800513E8: nop

            goto L_8005140C;
    }
    // 0x800513E8: nop

    // 0x800513EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800513F0: beq         $s0, $at, L_80051444
    if (ctx->r16 == ctx->r1) {
        // 0x800513F4: nop

            goto L_80051444;
    }
    // 0x800513F4: nop

    // 0x800513F8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800513FC: beq         $s0, $at, L_8005147C
    if (ctx->r16 == ctx->r1) {
        // 0x80051400: nop

            goto L_8005147C;
    }
    // 0x80051400: nop

    // 0x80051404: b           L_80051484
    // 0x80051408: nop

        goto L_80051484;
    // 0x80051408: nop

L_8005140C:
    // 0x8005140C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051410: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80051414: nop

    // 0x80051418: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8005141C: nop

    // 0x80051420: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x80051424: beq         $at, $zero, L_8005143C
    if (ctx->r1 == 0) {
        // 0x80051428: nop

            goto L_8005143C;
    }
    // 0x80051428: nop

    // 0x8005142C: b           L_80051508
    // 0x80051430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x80051430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80051434: b           L_80051444
    // 0x80051438: nop

        goto L_80051444;
    // 0x80051438: nop

L_8005143C:
    // 0x8005143C: b           L_800514EC
    // 0x80051440: nop

        goto L_800514EC;
    // 0x80051440: nop

L_80051444:
    // 0x80051444: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80051448: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8005144C: nop

    // 0x80051450: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80051454: nop

    // 0x80051458: slti        $at, $t0, 0x3D
    ctx->r1 = SIGNED(ctx->r8) < 0X3D ? 1 : 0;
    // 0x8005145C: beq         $at, $zero, L_80051474
    if (ctx->r1 == 0) {
        // 0x80051460: nop

            goto L_80051474;
    }
    // 0x80051460: nop

    // 0x80051464: b           L_80051508
    // 0x80051468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x80051468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005146C: b           L_8005147C
    // 0x80051470: nop

        goto L_8005147C;
    // 0x80051470: nop

L_80051474:
    // 0x80051474: b           L_800514EC
    // 0x80051478: nop

        goto L_800514EC;
    // 0x80051478: nop

L_8005147C:
    // 0x8005147C: b           L_80051508
    // 0x80051480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x80051480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051484:
    // 0x80051484: b           L_800514EC
    // 0x80051488: nop

        goto L_800514EC;
    // 0x80051488: nop

L_8005148C:
    // 0x8005148C: jal         0x80061F08
    // 0x80051490: nop

    func_80061F08(rdram, ctx);
        goto after_1;
    // 0x80051490: nop

    after_1:
    // 0x80051494: beq         $v0, $zero, L_800514A4
    if (ctx->r2 == 0) {
        // 0x80051498: nop

            goto L_800514A4;
    }
    // 0x80051498: nop

    // 0x8005149C: b           L_800514EC
    // 0x800514A0: nop

        goto L_800514EC;
    // 0x800514A0: nop

L_800514A4:
    // 0x800514A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800514A8: lw          $a0, 0x11A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11A8);
    // 0x800514AC: jal         0x80056C60
    // 0x800514B0: nop

    func_80056C60(rdram, ctx);
        goto after_2;
    // 0x800514B0: nop

    after_2:
    // 0x800514B4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800514B8: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800514BC: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800514C0: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    // 0x800514C4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800514C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800514CC: lh          $t3, 0x2C5C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2C5C);
    // 0x800514D0: nop

    // 0x800514D4: beq         $t3, $zero, L_800514E4
    if (ctx->r11 == 0) {
        // 0x800514D8: nop

            goto L_800514E4;
    }
    // 0x800514D8: nop

    // 0x800514DC: b           L_80051508
    // 0x800514E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x800514E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800514E4:
    // 0x800514E4: b           L_800514EC
    // 0x800514E8: nop

        goto L_800514EC;
    // 0x800514E8: nop

L_800514EC:
    // 0x800514EC: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800514F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800514F4: sh          $t4, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r12;
    // 0x800514F8: b           L_80051508
    // 0x800514FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051508;
    // 0x800514FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80051500: b           L_80051508
    // 0x80051504: nop

        goto L_80051508;
    // 0x80051504: nop

L_80051508:
    // 0x80051508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005150C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80051510: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80051514: jr          $ra
    // 0x80051518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80051518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005151C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005151C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051524: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051528: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005152C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051530: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80051534: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80051538: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005153C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80051540: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80051544: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80051548: bc1f        L_80051560
    if (!c1cs) {
        // 0x8005154C: nop

            goto L_80051560;
    }
    // 0x8005154C: nop

    // 0x80051550: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80051554: lwc1        $f16, -0x10B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X10B0);
    // 0x80051558: nop

    // 0x8005155C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
L_80051560:
    // 0x80051560: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051564: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051568: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005156C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80051570: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80051574: bne         $t0, $zero, L_80051584
    if (ctx->r8 != 0) {
        // 0x80051578: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_80051584;
    }
    // 0x80051578: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x8005157C: beq         $t1, $zero, L_80051598
    if (ctx->r9 == 0) {
        // 0x80051580: nop

            goto L_80051598;
    }
    // 0x80051580: nop

L_80051584:
    // 0x80051584: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051588: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005158C: nop

    // 0x80051590: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80051594: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
L_80051598:
    // 0x80051598: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005159C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800515A0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800515A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800515A8: lwc1        $f8, 0x10($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800515AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800515B0: lwc1        $f18, 0xE6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XE6C);
    // 0x800515B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800515B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800515BC: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800515C0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800515C4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800515C8: bc1f        L_800515E0
    if (!c1cs) {
        // 0x800515CC: nop

            goto L_800515E0;
    }
    // 0x800515CC: nop

    // 0x800515D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800515D4: lwc1        $f8, -0x10AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X10AC);
    // 0x800515D8: nop

    // 0x800515DC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
L_800515E0:
    // 0x800515E0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800515E4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800515E8: jal         0x800C3A34
    // 0x800515EC: nop

    func_800C3A34(rdram, ctx);
        goto after_0;
    // 0x800515EC: nop

    after_0:
    // 0x800515F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800515F4: lwc1        $f19, -0x10A8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X10A8);
    // 0x800515F8: lwc1        $f18, -0x10A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X10A4);
    // 0x800515FC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80051600: nop

    // 0x80051604: div.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80051608: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8005160C: nop

    // 0x80051610: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80051614: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80051618: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005161C: nop

    // 0x80051620: cvt.w.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_D(ctx->f16.d);
    // 0x80051624: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80051628: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8005162C: nop

    // 0x80051630: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80051634: nop

    // 0x80051638: slti        $at, $t4, 0xF
    ctx->r1 = SIGNED(ctx->r12) < 0XF ? 1 : 0;
    // 0x8005163C: beq         $at, $zero, L_8005164C
    if (ctx->r1 == 0) {
        // 0x80051640: nop

            goto L_8005164C;
    }
    // 0x80051640: nop

    // 0x80051644: b           L_800516F0
    // 0x80051648: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_800516F0;
    // 0x80051648: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_8005164C:
    // 0x8005164C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80051650: nop

    // 0x80051654: slti        $at, $t5, 0x5A
    ctx->r1 = SIGNED(ctx->r13) < 0X5A ? 1 : 0;
    // 0x80051658: beq         $at, $zero, L_80051668
    if (ctx->r1 == 0) {
        // 0x8005165C: nop

            goto L_80051668;
    }
    // 0x8005165C: nop

    // 0x80051660: b           L_800516F0
    // 0x80051664: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_800516F0;
    // 0x80051664: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80051668:
    // 0x80051668: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005166C: nop

    // 0x80051670: slti        $at, $t6, 0xA5
    ctx->r1 = SIGNED(ctx->r14) < 0XA5 ? 1 : 0;
    // 0x80051674: beq         $at, $zero, L_80051684
    if (ctx->r1 == 0) {
        // 0x80051678: nop

            goto L_80051684;
    }
    // 0x80051678: nop

    // 0x8005167C: b           L_800516F0
    // 0x80051680: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
        goto L_800516F0;
    // 0x80051680: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
L_80051684:
    // 0x80051684: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80051688: nop

    // 0x8005168C: slti        $at, $t7, 0xC3
    ctx->r1 = SIGNED(ctx->r15) < 0XC3 ? 1 : 0;
    // 0x80051690: beq         $at, $zero, L_800516A0
    if (ctx->r1 == 0) {
        // 0x80051694: nop

            goto L_800516A0;
    }
    // 0x80051694: nop

    // 0x80051698: b           L_800516F0
    // 0x8005169C: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
        goto L_800516F0;
    // 0x8005169C: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
L_800516A0:
    // 0x800516A0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800516A4: nop

    // 0x800516A8: slti        $at, $t8, 0x10E
    ctx->r1 = SIGNED(ctx->r24) < 0X10E ? 1 : 0;
    // 0x800516AC: beq         $at, $zero, L_800516BC
    if (ctx->r1 == 0) {
        // 0x800516B0: nop

            goto L_800516BC;
    }
    // 0x800516B0: nop

    // 0x800516B4: b           L_800516F0
    // 0x800516B8: addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
        goto L_800516F0;
    // 0x800516B8: addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
L_800516BC:
    // 0x800516BC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800516C0: nop

    // 0x800516C4: slti        $at, $t9, 0x159
    ctx->r1 = SIGNED(ctx->r25) < 0X159 ? 1 : 0;
    // 0x800516C8: beq         $at, $zero, L_800516E0
    if (ctx->r1 == 0) {
        // 0x800516CC: nop

            goto L_800516E0;
    }
    // 0x800516CC: nop

    // 0x800516D0: b           L_800516F0
    // 0x800516D4: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
        goto L_800516F0;
    // 0x800516D4: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x800516D8: b           L_800516E8
    // 0x800516DC: nop

        goto L_800516E8;
    // 0x800516DC: nop

L_800516E0:
    // 0x800516E0: b           L_800516F0
    // 0x800516E4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_800516F0;
    // 0x800516E4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_800516E8:
    // 0x800516E8: b           L_800516F0
    // 0x800516EC: nop

        goto L_800516F0;
    // 0x800516EC: nop

L_800516F0:
    // 0x800516F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800516F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800516F8: jr          $ra
    // 0x800516FC: nop

    return;
    // 0x800516FC: nop

;}
RECOMP_FUNC void func_80051700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005170C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051710: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051714: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051718: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005171C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80051720: bne         $t0, $zero, L_80051730
    if (ctx->r8 != 0) {
        // 0x80051724: andi        $t1, $t9, 0x10
        ctx->r9 = ctx->r25 & 0X10;
            goto L_80051730;
    }
    // 0x80051724: andi        $t1, $t9, 0x10
    ctx->r9 = ctx->r25 & 0X10;
    // 0x80051728: beq         $t1, $zero, L_80051760
    if (ctx->r9 == 0) {
        // 0x8005172C: nop

            goto L_80051760;
    }
    // 0x8005172C: nop

L_80051730:
    // 0x80051730: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051734: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051738: nop

    // 0x8005173C: lh          $v0, 0x4A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X4A);
    // 0x80051740: nop

    // 0x80051744: andi        $t2, $v0, 0x1FFF
    ctx->r10 = ctx->r2 & 0X1FFF;
    // 0x80051748: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8005174C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80051750: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80051754: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80051758: b           L_800517F4
    // 0x8005175C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800517F4;
    // 0x8005175C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80051760:
    // 0x80051760: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80051764: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051768: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005176C: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80051770: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80051774: bne         $t8, $zero, L_80051784
    if (ctx->r24 != 0) {
        // 0x80051778: andi        $t9, $t7, 0x40
        ctx->r25 = ctx->r15 & 0X40;
            goto L_80051784;
    }
    // 0x80051778: andi        $t9, $t7, 0x40
    ctx->r25 = ctx->r15 & 0X40;
    // 0x8005177C: beq         $t9, $zero, L_80051798
    if (ctx->r25 == 0) {
        // 0x80051780: nop

            goto L_80051798;
    }
    // 0x80051780: nop

L_80051784:
    // 0x80051784: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80051788: jal         0x80056E88
    // 0x8005178C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_0;
    // 0x8005178C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80051790: b           L_800517F4
    // 0x80051794: nop

        goto L_800517F4;
    // 0x80051794: nop

L_80051798:
    // 0x80051798: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005179C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800517A0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800517A4: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800517A8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800517AC: bne         $t4, $zero, L_800517BC
    if (ctx->r12 != 0) {
        // 0x800517B0: andi        $t5, $t3, 0x20
        ctx->r13 = ctx->r11 & 0X20;
            goto L_800517BC;
    }
    // 0x800517B0: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x800517B4: beq         $t5, $zero, L_800517D8
    if (ctx->r13 == 0) {
        // 0x800517B8: nop

            goto L_800517D8;
    }
    // 0x800517B8: nop

L_800517BC:
    // 0x800517BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x800517C0: jal         0x80056E88
    // 0x800517C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_1;
    // 0x800517C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800517C8: b           L_800517F4
    // 0x800517CC: nop

        goto L_800517F4;
    // 0x800517CC: nop

    // 0x800517D0: b           L_800517EC
    // 0x800517D4: nop

        goto L_800517EC;
    // 0x800517D4: nop

L_800517D8:
    // 0x800517D8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800517DC: jal         0x80056E88
    // 0x800517E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_2;
    // 0x800517E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800517E4: b           L_800517F4
    // 0x800517E8: nop

        goto L_800517F4;
    // 0x800517E8: nop

L_800517EC:
    // 0x800517EC: b           L_800517F4
    // 0x800517F0: nop

        goto L_800517F4;
    // 0x800517F0: nop

L_800517F4:
    // 0x800517F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800517F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800517FC: jr          $ra
    // 0x80051800: nop

    return;
    // 0x80051800: nop

;}
RECOMP_FUNC void func_80051804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051804: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80051808: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005180C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80051810: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80051814: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80051818: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005181C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051824: lh          $t6, 0x3E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3E);
    // 0x80051828: nop

    // 0x8005182C: andi        $t7, $t6, 0x1FFF
    ctx->r15 = ctx->r14 & 0X1FFF;
    // 0x80051830: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x80051834: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051838: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005183C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80051840: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80051844: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051848: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005184C: bne         $t2, $zero, L_8005185C
    if (ctx->r10 != 0) {
        // 0x80051850: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8005185C;
    }
    // 0x80051850: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80051854: beq         $t3, $zero, L_80051CBC
    if (ctx->r11 == 0) {
        // 0x80051858: nop

            goto L_80051CBC;
    }
    // 0x80051858: nop

L_8005185C:
    // 0x8005185C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80051860: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80051864: nop

    // 0x80051868: lw          $a0, 0x58($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X58);
    // 0x8005186C: jal         0x80056C60
    // 0x80051870: nop

    func_80056C60(rdram, ctx);
        goto after_0;
    // 0x80051870: nop

    after_0:
    // 0x80051874: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80051878: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005187C: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80051880: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051884: beq         $t4, $at, L_8005189C
    if (ctx->r12 == ctx->r1) {
        // 0x80051888: nop

            goto L_8005189C;
    }
    // 0x80051888: nop

    // 0x8005188C: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80051890: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x80051894: beq         $t5, $at, L_800519F0
    if (ctx->r13 == ctx->r1) {
        // 0x80051898: nop

            goto L_800519F0;
    }
    // 0x80051898: nop

L_8005189C:
    // 0x8005189C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800518A0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x800518A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800518A8: beq         $t6, $at, L_800518C0
    if (ctx->r14 == ctx->r1) {
        // 0x800518AC: nop

            goto L_800518C0;
    }
    // 0x800518AC: nop

    // 0x800518B0: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x800518B4: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x800518B8: beq         $t7, $at, L_800519F0
    if (ctx->r15 == ctx->r1) {
        // 0x800518BC: nop

            goto L_800519F0;
    }
    // 0x800518BC: nop

L_800518C0:
    // 0x800518C0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800518C4: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800518C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800518CC: beq         $t8, $at, L_800518E4
    if (ctx->r24 == ctx->r1) {
        // 0x800518D0: nop

            goto L_800518E4;
    }
    // 0x800518D0: nop

    // 0x800518D4: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x800518D8: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x800518DC: beq         $t0, $at, L_800519F0
    if (ctx->r8 == ctx->r1) {
        // 0x800518E0: nop

            goto L_800519F0;
    }
    // 0x800518E0: nop

L_800518E4:
    // 0x800518E4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800518E8: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x800518EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800518F0: beq         $t1, $at, L_80051908
    if (ctx->r9 == ctx->r1) {
        // 0x800518F4: nop

            goto L_80051908;
    }
    // 0x800518F4: nop

    // 0x800518F8: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x800518FC: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x80051900: beq         $t2, $at, L_800519F0
    if (ctx->r10 == ctx->r1) {
        // 0x80051904: nop

            goto L_800519F0;
    }
    // 0x80051904: nop

L_80051908:
    // 0x80051908: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005190C: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80051910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051914: beq         $t3, $at, L_8005192C
    if (ctx->r11 == ctx->r1) {
        // 0x80051918: nop

            goto L_8005192C;
    }
    // 0x80051918: nop

    // 0x8005191C: lh          $t9, 0x3E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3E);
    // 0x80051920: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x80051924: beq         $t9, $at, L_800519F0
    if (ctx->r25 == ctx->r1) {
        // 0x80051928: nop

            goto L_800519F0;
    }
    // 0x80051928: nop

L_8005192C:
    // 0x8005192C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80051930: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80051934: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051938: beq         $t4, $at, L_80051950
    if (ctx->r12 == ctx->r1) {
        // 0x8005193C: nop

            goto L_80051950;
    }
    // 0x8005193C: nop

    // 0x80051940: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80051944: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80051948: beq         $t5, $at, L_800519F0
    if (ctx->r13 == ctx->r1) {
        // 0x8005194C: nop

            goto L_800519F0;
    }
    // 0x8005194C: nop

L_80051950:
    // 0x80051950: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80051954: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x80051958: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005195C: beq         $t6, $at, L_80051974
    if (ctx->r14 == ctx->r1) {
        // 0x80051960: nop

            goto L_80051974;
    }
    // 0x80051960: nop

    // 0x80051964: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x80051968: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x8005196C: beq         $t7, $at, L_800519F0
    if (ctx->r15 == ctx->r1) {
        // 0x80051970: nop

            goto L_800519F0;
    }
    // 0x80051970: nop

L_80051974:
    // 0x80051974: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80051978: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x8005197C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051980: beq         $t8, $at, L_80051998
    if (ctx->r24 == ctx->r1) {
        // 0x80051984: nop

            goto L_80051998;
    }
    // 0x80051984: nop

    // 0x80051988: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x8005198C: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x80051990: beq         $t0, $at, L_800519F0
    if (ctx->r8 == ctx->r1) {
        // 0x80051994: nop

            goto L_800519F0;
    }
    // 0x80051994: nop

L_80051998:
    // 0x80051998: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x8005199C: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x800519A0: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519A4: nop

            goto L_800519F0;
    }
    // 0x800519A4: nop

    // 0x800519A8: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x800519AC: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519B0: nop

            goto L_800519F0;
    }
    // 0x800519B0: nop

    // 0x800519B4: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x800519B8: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519BC: nop

            goto L_800519F0;
    }
    // 0x800519BC: nop

    // 0x800519C0: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x800519C4: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519C8: nop

            goto L_800519F0;
    }
    // 0x800519C8: nop

    // 0x800519CC: addiu       $at, $zero, 0xD3
    ctx->r1 = ADD32(0, 0XD3);
    // 0x800519D0: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519D4: nop

            goto L_800519F0;
    }
    // 0x800519D4: nop

    // 0x800519D8: addiu       $at, $zero, 0xD4
    ctx->r1 = ADD32(0, 0XD4);
    // 0x800519DC: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519E0: nop

            goto L_800519F0;
    }
    // 0x800519E0: nop

    // 0x800519E4: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x800519E8: bne         $t1, $at, L_80051A30
    if (ctx->r9 != ctx->r1) {
        // 0x800519EC: nop

            goto L_80051A30;
    }
    // 0x800519EC: nop

L_800519F0:
    // 0x800519F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800519F4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800519F8: jal         0x80051804
    // 0x800519FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80051804(rdram, ctx);
        goto after_1;
    // 0x800519FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80051A00: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051A04: jal         0x800507AC
    // 0x80051A08: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x80051A08: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x80051A0C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051A10: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051A14: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80051A18: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80051A1C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80051A20: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x80051A24: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x80051A28: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80051A2C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80051A30:
    // 0x80051A30: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80051A34: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80051A38: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x80051A3C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80051A40: lh          $s0, 0x2C5A($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X2C5A);
    // 0x80051A44: nop

    // 0x80051A48: beq         $s0, $zero, L_80051A70
    if (ctx->r16 == 0) {
        // 0x80051A4C: nop

            goto L_80051A70;
    }
    // 0x80051A4C: nop

    // 0x80051A50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051A54: beq         $s0, $at, L_80051AC0
    if (ctx->r16 == ctx->r1) {
        // 0x80051A58: nop

            goto L_80051AC0;
    }
    // 0x80051A58: nop

    // 0x80051A5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80051A60: beq         $s0, $at, L_80051B10
    if (ctx->r16 == ctx->r1) {
        // 0x80051A64: nop

            goto L_80051B10;
    }
    // 0x80051A64: nop

    // 0x80051A68: b           L_80051B4C
    // 0x80051A6C: nop

        goto L_80051B4C;
    // 0x80051A6C: nop

L_80051A70:
    // 0x80051A70: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051A74: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80051A78: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051A7C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80051A80: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80051A84: bne         $t4, $zero, L_80051A94
    if (ctx->r12 != 0) {
        // 0x80051A88: andi        $t5, $t1, 0x8
        ctx->r13 = ctx->r9 & 0X8;
            goto L_80051A94;
    }
    // 0x80051A88: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x80051A8C: beq         $t5, $zero, L_80051AB8
    if (ctx->r13 == 0) {
        // 0x80051A90: nop

            goto L_80051AB8;
    }
    // 0x80051A90: nop

L_80051A94:
    // 0x80051A94: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80051A98: jal         0x80056E88
    // 0x80051A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_3;
    // 0x80051A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80051AA0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80051AA4: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051AA8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80051AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051AB0: jal         0x800507AC
    // 0x80051AB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_4;
    // 0x80051AB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80051AB8:
    // 0x80051AB8: b           L_80051B4C
    // 0x80051ABC: nop

        goto L_80051B4C;
    // 0x80051ABC: nop

L_80051AC0:
    // 0x80051AC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051AC4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051AC8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80051ACC: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80051AD0: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80051AD4: bne         $t8, $zero, L_80051B08
    if (ctx->r24 != 0) {
        // 0x80051AD8: andi        $t9, $t3, 0x8
        ctx->r25 = ctx->r11 & 0X8;
            goto L_80051B08;
    }
    // 0x80051AD8: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x80051ADC: bne         $t9, $zero, L_80051B08
    if (ctx->r25 != 0) {
        // 0x80051AE0: nop

            goto L_80051B08;
    }
    // 0x80051AE0: nop

    // 0x80051AE4: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80051AE8: jal         0x80056E88
    // 0x80051AEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_5;
    // 0x80051AEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80051AF0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80051AF4: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051AF8: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80051AFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051B00: jal         0x800507AC
    // 0x80051B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_6;
    // 0x80051B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
L_80051B08:
    // 0x80051B08: b           L_80051B4C
    // 0x80051B0C: nop

        goto L_80051B4C;
    // 0x80051B0C: nop

L_80051B10:
    // 0x80051B10: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80051B14: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x80051B18: bne         $t1, $at, L_80051B44
    if (ctx->r9 != ctx->r1) {
        // 0x80051B1C: nop

            goto L_80051B44;
    }
    // 0x80051B1C: nop

    // 0x80051B20: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80051B24: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051B28: nop

    // 0x80051B2C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80051B30: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80051B34: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80051B38: ori         $t3, $t7, 0x8
    ctx->r11 = ctx->r15 | 0X8;
    // 0x80051B3C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80051B40: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
L_80051B44:
    // 0x80051B44: b           L_80051B4C
    // 0x80051B48: nop

        goto L_80051B4C;
    // 0x80051B48: nop

L_80051B4C:
    // 0x80051B4C: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80051B50: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x80051B54: beq         $t5, $at, L_80051B68
    if (ctx->r13 == ctx->r1) {
        // 0x80051B58: nop

            goto L_80051B68;
    }
    // 0x80051B58: nop

    // 0x80051B5C: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x80051B60: bne         $t5, $at, L_80051B74
    if (ctx->r13 != ctx->r1) {
        // 0x80051B64: nop

            goto L_80051B74;
    }
    // 0x80051B64: nop

L_80051B68:
    // 0x80051B68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051B6C: jal         0x800507AC
    // 0x80051B70: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    func_800507AC(rdram, ctx);
        goto after_7;
    // 0x80051B70: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_7:
L_80051B74:
    // 0x80051B74: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x80051B78: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x80051B7C: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051B80: nop

            goto L_80051C5C;
    }
    // 0x80051B80: nop

    // 0x80051B84: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80051B88: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051B8C: nop

            goto L_80051C5C;
    }
    // 0x80051B8C: nop

    // 0x80051B90: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x80051B94: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051B98: nop

            goto L_80051C5C;
    }
    // 0x80051B98: nop

    // 0x80051B9C: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x80051BA0: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BA4: nop

            goto L_80051C5C;
    }
    // 0x80051BA4: nop

    // 0x80051BA8: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x80051BAC: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BB0: nop

            goto L_80051C5C;
    }
    // 0x80051BB0: nop

    // 0x80051BB4: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80051BB8: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BBC: nop

            goto L_80051C5C;
    }
    // 0x80051BBC: nop

    // 0x80051BC0: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80051BC4: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BC8: nop

            goto L_80051C5C;
    }
    // 0x80051BC8: nop

    // 0x80051BCC: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x80051BD0: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BD4: nop

            goto L_80051C5C;
    }
    // 0x80051BD4: nop

    // 0x80051BD8: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x80051BDC: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BE0: nop

            goto L_80051C5C;
    }
    // 0x80051BE0: nop

    // 0x80051BE4: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x80051BE8: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BEC: nop

            goto L_80051C5C;
    }
    // 0x80051BEC: nop

    // 0x80051BF0: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x80051BF4: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BF8: nop

            goto L_80051C5C;
    }
    // 0x80051BF8: nop

    // 0x80051BFC: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x80051C00: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C04: nop

            goto L_80051C5C;
    }
    // 0x80051C04: nop

    // 0x80051C08: addiu       $at, $zero, 0xD3
    ctx->r1 = ADD32(0, 0XD3);
    // 0x80051C0C: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C10: nop

            goto L_80051C5C;
    }
    // 0x80051C10: nop

    // 0x80051C14: addiu       $at, $zero, 0xD4
    ctx->r1 = ADD32(0, 0XD4);
    // 0x80051C18: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C1C: nop

            goto L_80051C5C;
    }
    // 0x80051C1C: nop

    // 0x80051C20: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80051C24: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C28: nop

            goto L_80051C5C;
    }
    // 0x80051C28: nop

    // 0x80051C2C: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80051C30: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C34: nop

            goto L_80051C5C;
    }
    // 0x80051C34: nop

    // 0x80051C38: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x80051C3C: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C40: nop

            goto L_80051C5C;
    }
    // 0x80051C40: nop

    // 0x80051C44: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x80051C48: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C4C: nop

            goto L_80051C5C;
    }
    // 0x80051C4C: nop

    // 0x80051C50: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x80051C54: bne         $t8, $at, L_80051CA0
    if (ctx->r24 != ctx->r1) {
        // 0x80051C58: nop

            goto L_80051CA0;
    }
    // 0x80051C58: nop

L_80051C5C:
    // 0x80051C5C: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80051C60: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80051C64: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80051C68: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80051C6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051C70: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051C74: lh          $t1, 0x2C56($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2C56);
    // 0x80051C78: nop

    // 0x80051C7C: sw          $t1, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r9;
    // 0x80051C80: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x80051C84: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80051C88: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80051C8C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80051C90: lh          $t3, 0x2C58($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2C58);
    // 0x80051C94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051C98: b           L_80051CBC
    // 0x80051C9C: sw          $t3, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r11;
        goto L_80051CBC;
    // 0x80051C9C: sw          $t3, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r11;
L_80051CA0:
    // 0x80051CA0: lh          $t4, 0x36($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X36);
    // 0x80051CA4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80051CA8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80051CAC: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x80051CB0: lh          $t8, 0x2C58($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2C58);
    // 0x80051CB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051CB8: sw          $t8, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r24;
L_80051CBC:
    // 0x80051CBC: lh          $a3, 0x3E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3E);
    // 0x80051CC0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051CC4: or          $t9, $a3, $at
    ctx->r25 = ctx->r7 | ctx->r1;
    // 0x80051CC8: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80051CCC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80051CD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051CD4: jal         0x800B3230
    // 0x80051CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_8;
    // 0x80051CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80051CDC: lhu         $t0, 0x34($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X34);
    // 0x80051CE0: nop

    // 0x80051CE4: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80051CE8: sra         $t6, $t1, 7
    ctx->r14 = S32(SIGNED(ctx->r9) >> 7);
    // 0x80051CEC: bne         $t6, $zero, L_80051DDC
    if (ctx->r14 != 0) {
        // 0x80051CF0: nop

            goto L_80051DDC;
    }
    // 0x80051CF0: nop

    // 0x80051CF4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051CF8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051CFC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051D00: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80051D04: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80051D08: bne         $t4, $zero, L_80051D18
    if (ctx->r12 != 0) {
        // 0x80051D0C: andi        $t5, $t3, 0x10
        ctx->r13 = ctx->r11 & 0X10;
            goto L_80051D18;
    }
    // 0x80051D0C: andi        $t5, $t3, 0x10
    ctx->r13 = ctx->r11 & 0X10;
    // 0x80051D10: beq         $t5, $zero, L_80051DDC
    if (ctx->r13 == 0) {
        // 0x80051D14: nop

            goto L_80051DDC;
    }
    // 0x80051D14: nop

L_80051D18:
    // 0x80051D18: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051D1C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80051D20: nop

    // 0x80051D24: lh          $a0, 0x4A($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4A);
    // 0x80051D28: nop

    // 0x80051D2C: andi        $t9, $a0, 0x1FFF
    ctx->r25 = ctx->r4 & 0X1FFF;
    // 0x80051D30: jal         0x800574CC
    // 0x80051D34: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800574CC(rdram, ctx);
        goto after_9;
    // 0x80051D34: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
    // 0x80051D38: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x80051D3C: sra         $t0, $s2, 16
    ctx->r8 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80051D40: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
    // 0x80051D44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051D48: jal         0x80056E88
    // 0x80051D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_10;
    // 0x80051D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80051D50: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80051D54: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051D58: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80051D5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051D60: jal         0x800507AC
    // 0x80051D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_11;
    // 0x80051D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x80051D68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051D6C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051D70: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80051D74: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80051D78: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80051D7C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x80051D80: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80051D84: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80051D88: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80051D8C: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80051D90: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051D94: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051D98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051D9C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80051DA0: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80051DA4: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80051DA8: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80051DAC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80051DB0: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x80051DB4: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x80051DB8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051DBC: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051DC0: nop

    // 0x80051DC4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80051DC8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80051DCC: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x80051DD0: ori         $t7, $t5, 0x40
    ctx->r15 = ctx->r13 | 0X40;
    // 0x80051DD4: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80051DD8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80051DDC:
    // 0x80051DDC: lhu         $s0, 0x34($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X34);
    // 0x80051DE0: nop

    // 0x80051DE4: andi        $t3, $s0, 0x300
    ctx->r11 = ctx->r16 & 0X300;
    // 0x80051DE8: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80051DEC: sra         $t8, $s0, 8
    ctx->r24 = S32(SIGNED(ctx->r16) >> 8);
    // 0x80051DF0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80051DF4: beq         $s0, $zero, L_80051E10
    if (ctx->r16 == 0) {
        // 0x80051DF8: nop

            goto L_80051E10;
    }
    // 0x80051DF8: nop

    // 0x80051DFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051E00: beq         $s0, $at, L_80051EEC
    if (ctx->r16 == ctx->r1) {
        // 0x80051E04: nop

            goto L_80051EEC;
    }
    // 0x80051E04: nop

    // 0x80051E08: b           L_80051FC8
    // 0x80051E0C: nop

        goto L_80051FC8;
    // 0x80051E0C: nop

L_80051E10:
    // 0x80051E10: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80051E14: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80051E18: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051E1C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80051E20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80051E24: bne         $t4, $zero, L_80051E34
    if (ctx->r12 != 0) {
        // 0x80051E28: andi        $t5, $t1, 0x40
        ctx->r13 = ctx->r9 & 0X40;
            goto L_80051E34;
    }
    // 0x80051E28: andi        $t5, $t1, 0x40
    ctx->r13 = ctx->r9 & 0X40;
    // 0x80051E2C: beq         $t5, $zero, L_80051E90
    if (ctx->r13 == 0) {
        // 0x80051E30: nop

            goto L_80051E90;
    }
    // 0x80051E30: nop

L_80051E34:
    // 0x80051E34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051E38: jal         0x800507AC
    // 0x80051E3C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    func_800507AC(rdram, ctx);
        goto after_12;
    // 0x80051E3C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_12:
    // 0x80051E40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051E44: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051E48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051E4C: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80051E50: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80051E54: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x80051E58: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80051E5C: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80051E60: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80051E64: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80051E68: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051E6C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051E70: nop

    // 0x80051E74: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80051E78: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80051E7C: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80051E80: ori         $t5, $t1, 0x20
    ctx->r13 = ctx->r9 | 0X20;
    // 0x80051E84: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80051E88: b           L_80051EE4
    // 0x80051E8C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
        goto L_80051EE4;
    // 0x80051E8C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
L_80051E90:
    // 0x80051E90: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051E94: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051E98: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80051E9C: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80051EA0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80051EA4: bne         $t6, $zero, L_80051EE4
    if (ctx->r14 != 0) {
        // 0x80051EA8: andi        $t7, $t9, 0x20
        ctx->r15 = ctx->r25 & 0X20;
            goto L_80051EE4;
    }
    // 0x80051EA8: andi        $t7, $t9, 0x20
    ctx->r15 = ctx->r25 & 0X20;
    // 0x80051EAC: bne         $t7, $zero, L_80051EE4
    if (ctx->r15 != 0) {
        // 0x80051EB0: nop

            goto L_80051EE4;
    }
    // 0x80051EB0: nop

    // 0x80051EB4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051EB8: jal         0x800507AC
    // 0x80051EBC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800507AC(rdram, ctx);
        goto after_13;
    // 0x80051EBC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_13:
    // 0x80051EC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80051EC4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80051EC8: nop

    // 0x80051ECC: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80051ED0: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80051ED4: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80051ED8: ori         $t5, $t1, 0x20
    ctx->r13 = ctx->r9 | 0X20;
    // 0x80051EDC: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80051EE0: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
L_80051EE4:
    // 0x80051EE4: b           L_80052078
    // 0x80051EE8: nop

        goto L_80052078;
    // 0x80051EE8: nop

L_80051EEC:
    // 0x80051EEC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051EF0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051EF4: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80051EF8: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80051EFC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80051F00: bne         $t6, $zero, L_80051F10
    if (ctx->r14 != 0) {
        // 0x80051F04: andi        $t7, $t9, 0x20
        ctx->r15 = ctx->r25 & 0X20;
            goto L_80051F10;
    }
    // 0x80051F04: andi        $t7, $t9, 0x20
    ctx->r15 = ctx->r25 & 0X20;
    // 0x80051F08: beq         $t7, $zero, L_80051F6C
    if (ctx->r15 == 0) {
        // 0x80051F0C: nop

            goto L_80051F6C;
    }
    // 0x80051F0C: nop

L_80051F10:
    // 0x80051F10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051F14: jal         0x800507AC
    // 0x80051F18: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    func_800507AC(rdram, ctx);
        goto after_14;
    // 0x80051F18: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_14:
    // 0x80051F1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80051F20: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80051F24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051F28: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80051F2C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80051F30: and         $t2, $t4, $at
    ctx->r10 = ctx->r12 & ctx->r1;
    // 0x80051F34: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80051F38: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x80051F3C: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80051F40: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80051F44: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80051F48: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80051F4C: nop

    // 0x80051F50: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80051F54: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x80051F58: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x80051F5C: ori         $t7, $t9, 0x40
    ctx->r15 = ctx->r25 | 0X40;
    // 0x80051F60: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80051F64: b           L_80051FC0
    // 0x80051F68: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
        goto L_80051FC0;
    // 0x80051F68: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_80051F6C:
    // 0x80051F6C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80051F70: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051F74: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051F78: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80051F7C: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x80051F80: bne         $t0, $zero, L_80051FC0
    if (ctx->r8 != 0) {
        // 0x80051F84: andi        $t1, $t3, 0x40
        ctx->r9 = ctx->r11 & 0X40;
            goto L_80051FC0;
    }
    // 0x80051F84: andi        $t1, $t3, 0x40
    ctx->r9 = ctx->r11 & 0X40;
    // 0x80051F88: bne         $t1, $zero, L_80051FC0
    if (ctx->r9 != 0) {
        // 0x80051F8C: nop

            goto L_80051FC0;
    }
    // 0x80051F8C: nop

    // 0x80051F90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051F94: jal         0x800507AC
    // 0x80051F98: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    func_800507AC(rdram, ctx);
        goto after_15;
    // 0x80051F98: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    after_15:
    // 0x80051F9C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80051FA0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051FA4: nop

    // 0x80051FA8: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80051FAC: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x80051FB0: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x80051FB4: ori         $t7, $t9, 0x40
    ctx->r15 = ctx->r25 | 0X40;
    // 0x80051FB8: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80051FBC: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80051FC0:
    // 0x80051FC0: b           L_80052078
    // 0x80051FC4: nop

        goto L_80052078;
    // 0x80051FC4: nop

L_80051FC8:
    // 0x80051FC8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80051FCC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051FD0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051FD4: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80051FD8: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x80051FDC: bne         $t0, $zero, L_80051FEC
    if (ctx->r8 != 0) {
        // 0x80051FE0: andi        $t1, $t3, 0x40
        ctx->r9 = ctx->r11 & 0X40;
            goto L_80051FEC;
    }
    // 0x80051FE0: andi        $t1, $t3, 0x40
    ctx->r9 = ctx->r11 & 0X40;
    // 0x80051FE4: beq         $t1, $zero, L_80052020
    if (ctx->r9 == 0) {
        // 0x80051FE8: nop

            goto L_80052020;
    }
    // 0x80051FE8: nop

L_80051FEC:
    // 0x80051FEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051FF0: jal         0x800507AC
    // 0x80051FF4: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800507AC(rdram, ctx);
        goto after_16;
    // 0x80051FF4: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_16:
    // 0x80051FF8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051FFC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052000: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052004: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80052008: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005200C: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x80052010: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80052014: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x80052018: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8005201C: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
L_80052020:
    // 0x80052020: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80052024: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80052028: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005202C: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x80052030: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80052034: bne         $t0, $zero, L_80052044
    if (ctx->r8 != 0) {
        // 0x80052038: andi        $t1, $t3, 0x20
        ctx->r9 = ctx->r11 & 0X20;
            goto L_80052044;
    }
    // 0x80052038: andi        $t1, $t3, 0x20
    ctx->r9 = ctx->r11 & 0X20;
    // 0x8005203C: beq         $t1, $zero, L_80052078
    if (ctx->r9 == 0) {
        // 0x80052040: nop

            goto L_80052078;
    }
    // 0x80052040: nop

L_80052044:
    // 0x80052044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80052048: jal         0x800507AC
    // 0x8005204C: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    func_800507AC(rdram, ctx);
        goto after_17;
    // 0x8005204C: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_17:
    // 0x80052050: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052054: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005205C: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x80052060: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x80052064: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80052068: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8005206C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80052070: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80052074: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_80052078:
    // 0x80052078: lhu         $t7, 0x34($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X34);
    // 0x8005207C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052080: andi        $t2, $t7, 0x80
    ctx->r10 = ctx->r15 & 0X80;
    // 0x80052084: sra         $t3, $t2, 7
    ctx->r11 = S32(SIGNED(ctx->r10) >> 7);
    // 0x80052088: bne         $t3, $at, L_8005216C
    if (ctx->r11 != ctx->r1) {
        // 0x8005208C: nop

            goto L_8005216C;
    }
    // 0x8005208C: nop

    // 0x80052090: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052094: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80052098: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005209C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x800520A0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800520A4: bne         $t8, $zero, L_8005216C
    if (ctx->r24 != 0) {
        // 0x800520A8: andi        $t9, $t5, 0x10
        ctx->r25 = ctx->r13 & 0X10;
            goto L_8005216C;
    }
    // 0x800520A8: andi        $t9, $t5, 0x10
    ctx->r25 = ctx->r13 & 0X10;
    // 0x800520AC: bne         $t9, $zero, L_8005216C
    if (ctx->r25 != 0) {
        // 0x800520B0: nop

            goto L_8005216C;
    }
    // 0x800520B0: nop

    // 0x800520B4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800520B8: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x800520BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800520C0: bne         $t1, $at, L_800520F0
    if (ctx->r9 != ctx->r1) {
        // 0x800520C4: nop

            goto L_800520F0;
    }
    // 0x800520C4: nop

    // 0x800520C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800520CC: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x800520D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800520D4: bne         $t6, $at, L_800520F0
    if (ctx->r14 != ctx->r1) {
        // 0x800520D8: nop

            goto L_800520F0;
    }
    // 0x800520D8: nop

    // 0x800520DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800520E0: jal         0x800507AC
    // 0x800520E4: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    func_800507AC(rdram, ctx);
        goto after_18;
    // 0x800520E4: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    after_18:
    // 0x800520E8: b           L_80052148
    // 0x800520EC: nop

        goto L_80052148;
    // 0x800520EC: nop

L_800520F0:
    // 0x800520F0: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x800520F4: jal         0x80056E88
    // 0x800520F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_19;
    // 0x800520F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x800520FC: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80052100: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80052104: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80052108: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005210C: jal         0x800507AC
    // 0x80052110: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_20;
    // 0x80052110: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_20:
    // 0x80052114: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80052118: nop

    // 0x8005211C: beq         $t2, $zero, L_80052148
    if (ctx->r10 == 0) {
        // 0x80052120: nop

            goto L_80052148;
    }
    // 0x80052120: nop

    // 0x80052124: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052128: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005212C: nop

    // 0x80052130: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80052134: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80052138: ori         $t4, $t0, 0x4
    ctx->r12 = ctx->r8 | 0X4;
    // 0x8005213C: ori         $t5, $t1, 0x0
    ctx->r13 = ctx->r9 | 0X0;
    // 0x80052140: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80052144: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
L_80052148:
    // 0x80052148: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005214C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052150: nop

    // 0x80052154: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80052158: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005215C: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80052160: ori         $t3, $t7, 0x10
    ctx->r11 = ctx->r15 | 0X10;
    // 0x80052164: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80052168: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
L_8005216C:
    // 0x8005216C: b           L_80052174
    // 0x80052170: nop

        goto L_80052174;
    // 0x80052170: nop

L_80052174:
    // 0x80052174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005217C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80052180: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80052184: jr          $ra
    // 0x80052188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80052188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005218C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005218C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052194: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80052198: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005219C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800521A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800521A4: jal         0x80016138
    // 0x800521A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_0;
    // 0x800521A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x800521AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800521B0: bne         $v0, $at, L_800521D8
    if (ctx->r2 != ctx->r1) {
        // 0x800521B4: nop

            goto L_800521D8;
    }
    // 0x800521B4: nop

L_800521B8:
    // 0x800521B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800521BC: jal         0x800499B0
    // 0x800521C0: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x800521C0: nop

    after_1:
    // 0x800521C4: jal         0x80016138
    // 0x800521C8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_2;
    // 0x800521C8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_2:
    // 0x800521CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800521D0: beq         $v0, $at, L_800521B8
    if (ctx->r2 == ctx->r1) {
        // 0x800521D4: nop

            goto L_800521B8;
    }
    // 0x800521D4: nop

L_800521D8:
    // 0x800521D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800521DC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800521E0: addiu       $at, $zero, 0xAD
    ctx->r1 = ADD32(0, 0XAD);
    // 0x800521E4: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x800521E8: nop

    // 0x800521EC: beq         $t7, $at, L_80052200
    if (ctx->r15 == ctx->r1) {
        // 0x800521F0: nop

            goto L_80052200;
    }
    // 0x800521F0: nop

    // 0x800521F4: addiu       $at, $zero, 0xAE
    ctx->r1 = ADD32(0, 0XAE);
    // 0x800521F8: bne         $t7, $at, L_8005220C
    if (ctx->r15 != ctx->r1) {
        // 0x800521FC: nop

            goto L_8005220C;
    }
    // 0x800521FC: nop

L_80052200:
    // 0x80052200: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052204: jal         0x800507AC
    // 0x80052208: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    func_800507AC(rdram, ctx);
        goto after_3;
    // 0x80052208: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_3:
L_8005220C:
    // 0x8005220C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052210: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052214: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80052218: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005221C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80052220: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80052224: bne         $t2, $zero, L_80052234
    if (ctx->r10 != 0) {
        // 0x80052228: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80052234;
    }
    // 0x80052228: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8005222C: beq         $t3, $zero, L_80052294
    if (ctx->r11 == 0) {
        // 0x80052230: nop

            goto L_80052294;
    }
    // 0x80052230: nop

L_80052234:
    // 0x80052234: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052238: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8005223C: jal         0x80051804
    // 0x80052240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80051804(rdram, ctx);
        goto after_4;
    // 0x80052240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80052244: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    // 0x80052248: jal         0x80056E88
    // 0x8005224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_5;
    // 0x8005224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80052250: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80052254: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052258: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8005225C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052260: jal         0x800507AC
    // 0x80052264: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_6;
    // 0x80052264: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80052268: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005226C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80052270: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052274: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80052278: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005227C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80052280: lui         $at, 0xFFEF
    ctx->r1 = S32(0XFFEF << 16);
    // 0x80052284: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80052288: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8005228C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80052290: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_80052294:
    // 0x80052294: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052298: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005229C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800522A0: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x800522A4: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x800522A8: bne         $t2, $zero, L_800522B8
    if (ctx->r10 != 0) {
        // 0x800522AC: andi        $t3, $t1, 0x10
        ctx->r11 = ctx->r9 & 0X10;
            goto L_800522B8;
    }
    // 0x800522AC: andi        $t3, $t1, 0x10
    ctx->r11 = ctx->r9 & 0X10;
    // 0x800522B0: beq         $t3, $zero, L_800523A0
    if (ctx->r11 == 0) {
        // 0x800522B4: nop

            goto L_800523A0;
    }
    // 0x800522B4: nop

L_800522B8:
    // 0x800522B8: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x800522BC: jal         0x800574CC
    // 0x800522C0: nop

    func_800574CC(rdram, ctx);
        goto after_7;
    // 0x800522C0: nop

    after_7:
    // 0x800522C4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800522C8: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800522CC: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800522D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800522D4: jal         0x80056E88
    // 0x800522D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_8;
    // 0x800522D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800522DC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800522E0: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800522E4: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800522E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800522EC: jal         0x800507AC
    // 0x800522F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_9;
    // 0x800522F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800522F4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800522F8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800522FC: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80052300: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80052304: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x80052308: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x8005230C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052310: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x80052314: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80052318: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8005231C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x80052320: jal         0x80056E88
    // 0x80052324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_10;
    // 0x80052324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80052328: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8005232C: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052330: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80052334: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052338: jal         0x800507AC
    // 0x8005233C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_11;
    // 0x8005233C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80052340: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80052344: jal         0x80056E88
    // 0x80052348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_12;
    // 0x80052348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8005234C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052350: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80052354: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80052358: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005235C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80052360: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80052364: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80052368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005236C: jal         0x8004EF90
    // 0x80052370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_13;
    // 0x80052370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80052374: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052378: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005237C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052380: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x80052384: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x80052388: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x8005238C: addiu       $at, $zero, -0x71
    ctx->r1 = ADD32(0, -0X71);
    // 0x80052390: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x80052394: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80052398: b           L_800524EC
    // 0x8005239C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
        goto L_800524EC;
    // 0x8005239C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
L_800523A0:
    // 0x800523A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800523A4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800523A8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800523AC: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800523B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800523B4: bne         $t2, $zero, L_800523C4
    if (ctx->r10 != 0) {
        // 0x800523B8: andi        $t3, $t9, 0x20
        ctx->r11 = ctx->r25 & 0X20;
            goto L_800523C4;
    }
    // 0x800523B8: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x800523BC: beq         $t3, $zero, L_80052448
    if (ctx->r11 == 0) {
        // 0x800523C0: nop

            goto L_80052448;
    }
    // 0x800523C0: nop

L_800523C4:
    // 0x800523C4: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x800523C8: jal         0x80056E88
    // 0x800523CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_14;
    // 0x800523CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x800523D0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800523D4: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800523D8: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x800523DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800523E0: jal         0x800507AC
    // 0x800523E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_15;
    // 0x800523E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x800523E8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800523EC: jal         0x80056E88
    // 0x800523F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_16;
    // 0x800523F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x800523F4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800523F8: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x800523FC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80052400: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052404: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80052408: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8005240C: lh          $a1, 0x42($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X42);
    // 0x80052410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052414: jal         0x8004EF90
    // 0x80052418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_17;
    // 0x80052418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8005241C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052420: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80052424: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052428: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8005242C: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80052430: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80052434: addiu       $at, $zero, -0x61
    ctx->r1 = ADD32(0, -0X61);
    // 0x80052438: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8005243C: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80052440: b           L_800524EC
    // 0x80052444: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
        goto L_800524EC;
    // 0x80052444: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_80052448:
    // 0x80052448: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005244C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80052450: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80052454: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80052458: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8005245C: bne         $t0, $zero, L_8005246C
    if (ctx->r8 != 0) {
        // 0x80052460: andi        $t1, $t5, 0x40
        ctx->r9 = ctx->r13 & 0X40;
            goto L_8005246C;
    }
    // 0x80052460: andi        $t1, $t5, 0x40
    ctx->r9 = ctx->r13 & 0X40;
    // 0x80052464: beq         $t1, $zero, L_800524EC
    if (ctx->r9 == 0) {
        // 0x80052468: nop

            goto L_800524EC;
    }
    // 0x80052468: nop

L_8005246C:
    // 0x8005246C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x80052470: jal         0x80056E88
    // 0x80052474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_18;
    // 0x80052474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80052478: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8005247C: sra         $t3, $s0, 16
    ctx->r11 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052480: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80052484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052488: jal         0x800507AC
    // 0x8005248C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_19;
    // 0x8005248C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x80052490: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80052494: jal         0x80056E88
    // 0x80052498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_20;
    // 0x80052498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8005249C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800524A0: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800524A4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800524A8: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800524AC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800524B0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800524B4: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x800524B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800524BC: jal         0x8004EF90
    // 0x800524C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_21;
    // 0x800524C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x800524C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800524C8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800524CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800524D0: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800524D4: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x800524D8: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x800524DC: addiu       $at, $zero, -0x61
    ctx->r1 = ADD32(0, -0X61);
    // 0x800524E0: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800524E4: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x800524E8: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
L_800524EC:
    // 0x800524EC: b           L_800524F4
    // 0x800524F0: nop

        goto L_800524F4;
    // 0x800524F0: nop

L_800524F4:
    // 0x800524F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800524F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800524FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80052500: jr          $ra
    // 0x80052504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80052504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80052508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052508: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005250C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052510: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80052514: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80052518: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005251C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052520: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80052524: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80052528: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005252C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052530: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80052534: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x80052538: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8005253C: nop

    // 0x80052540: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80052544: nop

    // 0x80052548: bgez        $t1, L_80052560
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005254C: nop

            goto L_80052560;
    }
    // 0x8005254C: nop

    // 0x80052550: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052554: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80052558: nop

    // 0x8005255C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_80052560:
    // 0x80052560: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052564: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80052568: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005256C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80052570: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052574: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x80052578: sh          $t7, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r15;
    // 0x8005257C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80052580: nop

    // 0x80052584: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80052588: nop

    // 0x8005258C: bgez        $t9, L_800525A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80052590: nop

            goto L_800525A4;
    }
    // 0x80052590: nop

    // 0x80052594: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052598: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005259C: nop

    // 0x800525A0: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
L_800525A4:
    // 0x800525A4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800525A8: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x800525AC: nop

    // 0x800525B0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800525B4: nop

    // 0x800525B8: beq         $t1, $zero, L_800525D0
    if (ctx->r9 == 0) {
        // 0x800525BC: nop

            goto L_800525D0;
    }
    // 0x800525BC: nop

    // 0x800525C0: lh          $t2, 0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X2);
    // 0x800525C4: nop

    // 0x800525C8: bne         $t2, $zero, L_80052650
    if (ctx->r10 != 0) {
        // 0x800525CC: nop

            goto L_80052650;
    }
    // 0x800525CC: nop

L_800525D0:
    // 0x800525D0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800525D4: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800525D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800525DC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800525E0: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x800525E4: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800525E8: lui         $at, 0xFEFF
    ctx->r1 = S32(0XFEFF << 16);
    // 0x800525EC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800525F0: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800525F4: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x800525F8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800525FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80052600: jal         0x800507AC
    // 0x80052604: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    func_800507AC(rdram, ctx);
        goto after_0;
    // 0x80052604: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    after_0:
    // 0x80052608: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005260C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052610: sh          $t5, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r13;
    // 0x80052614: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80052618:
    // 0x80052618: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005261C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80052620: bne         $t3, $at, L_80052630
    if (ctx->r11 != ctx->r1) {
        // 0x80052624: nop

            goto L_80052630;
    }
    // 0x80052624: nop

    // 0x80052628: jal         0x80059D80
    // 0x8005262C: nop

    func_80059D80(rdram, ctx);
        goto after_1;
    // 0x8005262C: nop

    after_1:
L_80052630:
    // 0x80052630: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80052634: jal         0x800499B0
    // 0x80052638: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x80052638: nop

    after_2:
    // 0x8005263C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80052640: nop

    // 0x80052644: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80052648: b           L_80052618
    // 0x8005264C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
        goto L_80052618;
    // 0x8005264C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80052650:
    // 0x80052650: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052654: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80052658: nop

    // 0x8005265C: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x80052660: nop

    // 0x80052664: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x80052668: beq         $at, $zero, L_80052678
    if (ctx->r1 == 0) {
        // 0x8005266C: nop

            goto L_80052678;
    }
    // 0x8005266C: nop

    // 0x80052670: b           L_800526B0
    // 0x80052674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800526B0;
    // 0x80052674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052678:
    // 0x80052678: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005267C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80052680: nop

    // 0x80052684: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x80052688: nop

    // 0x8005268C: slti        $at, $t6, 0x3D
    ctx->r1 = SIGNED(ctx->r14) < 0X3D ? 1 : 0;
    // 0x80052690: beq         $at, $zero, L_800526A0
    if (ctx->r1 == 0) {
        // 0x80052694: nop

            goto L_800526A0;
    }
    // 0x80052694: nop

    // 0x80052698: b           L_800526B0
    // 0x8005269C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800526B0;
    // 0x8005269C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800526A0:
    // 0x800526A0: b           L_800526B0
    // 0x800526A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800526B0;
    // 0x800526A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800526A8: b           L_800526B0
    // 0x800526AC: nop

        goto L_800526B0;
    // 0x800526AC: nop

L_800526B0:
    // 0x800526B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800526B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800526B8: jr          $ra
    // 0x800526BC: nop

    return;
    // 0x800526BC: nop

;}
RECOMP_FUNC void func_800526C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800526C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800526C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800526C8: nop

    // 0x800526CC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800526D0: nop

    // 0x800526D4: beq         $t7, $zero, L_800526EC
    if (ctx->r15 == 0) {
        // 0x800526D8: nop

            goto L_800526EC;
    }
    // 0x800526D8: nop

    // 0x800526DC: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x800526E0: nop

    // 0x800526E4: bne         $t8, $zero, L_800526F4
    if (ctx->r24 != 0) {
        // 0x800526E8: nop

            goto L_800526F4;
    }
    // 0x800526E8: nop

L_800526EC:
    // 0x800526EC: jr          $ra
    // 0x800526F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800526F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800526F4:
    // 0x800526F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800526F8: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x800526FC: nop

    // 0x80052700: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80052704: nop

    // 0x80052708: slti        $at, $t0, 0x3D
    ctx->r1 = SIGNED(ctx->r8) < 0X3D ? 1 : 0;
    // 0x8005270C: beq         $at, $zero, L_8005271C
    if (ctx->r1 == 0) {
        // 0x80052710: nop

            goto L_8005271C;
    }
    // 0x80052710: nop

    // 0x80052714: jr          $ra
    // 0x80052718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80052718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005271C:
    // 0x8005271C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052720: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80052724: nop

    // 0x80052728: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8005272C: nop

    // 0x80052730: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x80052734: beq         $at, $zero, L_80052744
    if (ctx->r1 == 0) {
        // 0x80052738: nop

            goto L_80052744;
    }
    // 0x80052738: nop

    // 0x8005273C: jr          $ra
    // 0x80052740: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80052740: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80052744:
    // 0x80052744: jr          $ra
    // 0x80052748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80052748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8005274C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005274C: jr          $ra
    // 0x80052750: nop

    return;
    // 0x80052750: nop

    // 0x80052754: jr          $ra
    // 0x80052758: nop

    return;
    // 0x80052758: nop

;}
RECOMP_FUNC void func_8005275C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005275C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052760: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80052764: nop

    // 0x80052768: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005276C: nop

    // 0x80052770: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x80052774: beq         $at, $zero, L_80052784
    if (ctx->r1 == 0) {
        // 0x80052778: nop

            goto L_80052784;
    }
    // 0x80052778: nop

    // 0x8005277C: jr          $ra
    // 0x80052780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80052780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052784:
    // 0x80052784: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052788: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005278C: nop

    // 0x80052790: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80052794: nop

    // 0x80052798: slti        $at, $t9, 0x3D
    ctx->r1 = SIGNED(ctx->r25) < 0X3D ? 1 : 0;
    // 0x8005279C: beq         $at, $zero, L_800527AC
    if (ctx->r1 == 0) {
        // 0x800527A0: nop

            goto L_800527AC;
    }
    // 0x800527A0: nop

    // 0x800527A4: jr          $ra
    // 0x800527A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800527A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800527AC:
    // 0x800527AC: jr          $ra
    // 0x800527B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800527B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
