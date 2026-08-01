#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void _allocatePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3F00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D3F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3F08: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D3F0C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800D3F10: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800D3F14: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D3F18: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D3F1C: beq         $a3, $zero, L_800D3F54
    if (ctx->r7 == 0) {
        // 0x800D3F20: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D3F54;
    }
    // 0x800D3F20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D3F24: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D3F28: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D3F2C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D3F30: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D3F34: jal         0x800C7890
    // 0x800D3F38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800D3F38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800D3F3C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D3F40: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D3F44: jal         0x800C78C0
    // 0x800D3F48: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800D3F48: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x800D3F4C: b           L_800D3FD4
    // 0x800D3F50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800D3FD4;
    // 0x800D3F50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800D3F54:
    // 0x800D3F54: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800D3F58: beq         $a3, $zero, L_800D3F8C
    if (ctx->r7 == 0) {
        // 0x800D3F5C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800D3F8C;
    }
    // 0x800D3F5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D3F60: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D3F64: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D3F68: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D3F6C: jal         0x800C7890
    // 0x800D3F70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800D3F70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D3F74: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D3F78: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D3F7C: jal         0x800C78C0
    // 0x800D3F80: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800D3F80: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800D3F84: b           L_800D3FD4
    // 0x800D3F88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800D3FD4;
    // 0x800D3F88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800D3F8C:
    // 0x800D3F8C: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800D3F90: beql        $a3, $zero, L_800D3FD8
    if (ctx->r7 == 0) {
        // 0x800D3F94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3FD8;
    }
    goto skip_0;
    // 0x800D3F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3F98: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_800D3F9C:
    // 0x800D3F9C: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x800D3FA0: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D3FA4: bnel        $at, $zero, L_800D3FCC
    if (ctx->r1 != 0) {
        // 0x800D3FA8: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800D3FCC;
    }
    goto skip_1;
    // 0x800D3FA8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800D3FAC: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x800D3FB0: bnel        $t1, $zero, L_800D3FCC
    if (ctx->r9 != 0) {
        // 0x800D3FB4: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800D3FCC;
    }
    goto skip_2;
    // 0x800D3FB4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x800D3FB8: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D3FBC: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800D3FC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D3FC4: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x800D3FC8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_800D3FCC:
    // 0x800D3FCC: bnel        $a3, $zero, L_800D3F9C
    if (ctx->r7 != 0) {
        // 0x800D3FD0: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_800D3F9C;
    }
    goto skip_3;
    // 0x800D3FD0: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_800D3FD4:
    // 0x800D3FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3FD8:
    // 0x800D3FD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D3FDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D3FE0: jr          $ra
    // 0x800D3FE4: nop

    return;
    // 0x800D3FE4: nop

;}
RECOMP_FUNC void func_8003288C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003288C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80032890: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80032894: lhu         $t6, 0x24FC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X24FC);
    // 0x80032898: nop

    // 0x8003289C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800328A0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800328A4: lw          $t9, 0xE0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XE0);
    // 0x800328A8: nop

    // 0x800328AC: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800328B0: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800328B4: nop

    // 0x800328B8: sw          $t0, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r8;
    // 0x800328BC: lwc1        $f4, 0xFC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x800328C0: lwc1        $f6, 0x104($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X104);
    // 0x800328C4: nop

    // 0x800328C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800328CC: swc1        $f8, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f8.u32l;
    // 0x800328D0: lwc1        $f10, 0x100($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X100);
    // 0x800328D4: lwc1        $f16, 0x108($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X108);
    // 0x800328D8: nop

    // 0x800328DC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800328E0: swc1        $f18, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f18.u32l;
    // 0x800328E4: lwc1        $f4, 0x104($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X104);
    // 0x800328E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800328EC: nop

    // 0x800328F0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800328F4: nop

    // 0x800328F8: bc1f        L_80032938
    if (!c1cs) {
        // 0x800328FC: nop
    
            goto L_80032938;
    }
    // 0x800328FC: nop

    // 0x80032900: lwc1        $f8, 0xFC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x80032904: lwc1        $f10, 0xF4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80032908: nop

    // 0x8003290C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80032910: nop

    // 0x80032914: bc1f        L_80032930
    if (!c1cs) {
        // 0x80032918: nop
    
            goto L_80032930;
    }
    // 0x80032918: nop

    // 0x8003291C: lwc1        $f16, 0xFC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x80032920: lwc1        $f18, 0xF4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80032924: nop

    // 0x80032928: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003292C: swc1        $f4, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f4.u32l;
L_80032930:
    // 0x80032930: b           L_80032968
    // 0x80032934: nop

        goto L_80032968;
    // 0x80032934: nop

L_80032938:
    // 0x80032938: lwc1        $f6, 0xFC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x8003293C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80032940: nop

    // 0x80032944: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80032948: nop

    // 0x8003294C: bc1f        L_80032968
    if (!c1cs) {
        // 0x80032950: nop
    
            goto L_80032968;
    }
    // 0x80032950: nop

    // 0x80032954: lwc1        $f10, 0xFC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x80032958: lwc1        $f16, 0xF4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x8003295C: nop

    // 0x80032960: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80032964: swc1        $f18, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f18.u32l;
L_80032968:
    // 0x80032968: lwc1        $f4, 0x108($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X108);
    // 0x8003296C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80032970: nop

    // 0x80032974: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80032978: nop

    // 0x8003297C: bc1f        L_800329BC
    if (!c1cs) {
        // 0x80032980: nop
    
            goto L_800329BC;
    }
    // 0x80032980: nop

    // 0x80032984: lwc1        $f8, 0x100($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X100);
    // 0x80032988: lwc1        $f10, 0xF8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x8003298C: nop

    // 0x80032990: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80032994: nop

    // 0x80032998: bc1f        L_800329B4
    if (!c1cs) {
        // 0x8003299C: nop
    
            goto L_800329B4;
    }
    // 0x8003299C: nop

    // 0x800329A0: lwc1        $f16, 0x100($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X100);
    // 0x800329A4: lwc1        $f18, 0xF8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x800329A8: nop

    // 0x800329AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800329B0: swc1        $f4, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f4.u32l;
L_800329B4:
    // 0x800329B4: b           L_800329EC
    // 0x800329B8: nop

        goto L_800329EC;
    // 0x800329B8: nop

L_800329BC:
    // 0x800329BC: lwc1        $f6, 0x100($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X100);
    // 0x800329C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800329C4: nop

    // 0x800329C8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800329CC: nop

    // 0x800329D0: bc1f        L_800329EC
    if (!c1cs) {
        // 0x800329D4: nop
    
            goto L_800329EC;
    }
    // 0x800329D4: nop

    // 0x800329D8: lwc1        $f10, 0x100($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X100);
    // 0x800329DC: lwc1        $f16, 0xF8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x800329E0: nop

    // 0x800329E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800329E8: swc1        $f18, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f18.u32l;
L_800329EC:
    // 0x800329EC: lh          $t1, 0xF0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XF0);
    // 0x800329F0: lh          $t2, 0xEC($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XEC);
    // 0x800329F4: nop

    // 0x800329F8: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800329FC: blez        $t3, L_80032A14
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80032A00: nop
    
            goto L_80032A14;
    }
    // 0x80032A00: nop

    // 0x80032A04: lh          $t4, 0xF0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XF0);
    // 0x80032A08: lh          $t5, 0xEC($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XEC);
    // 0x80032A0C: b           L_80032A28
    // 0x80032A10: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
        goto L_80032A28;
    // 0x80032A10: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
L_80032A14:
    // 0x80032A14: lh          $t6, 0xF0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XF0);
    // 0x80032A18: lh          $t7, 0xEC($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XEC);
    // 0x80032A1C: nop

    // 0x80032A20: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x80032A24: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_80032A28:
    // 0x80032A28: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80032A2C: lwc1        $f8, 0xF4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80032A30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032A34: lwc1        $f16, 0xFC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x80032A38: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80032A3C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80032A40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80032A44: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80032A48: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80032A4C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80032A50: lh          $t8, 0xF2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XF2);
    // 0x80032A54: lh          $t9, 0xEE($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XEE);
    // 0x80032A58: nop

    // 0x80032A5C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80032A60: blez        $t0, L_80032A78
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80032A64: nop
    
            goto L_80032A78;
    }
    // 0x80032A64: nop

    // 0x80032A68: lh          $t1, 0xF2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XF2);
    // 0x80032A6C: lh          $t2, 0xEE($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XEE);
    // 0x80032A70: b           L_80032A8C
    // 0x80032A74: subu        $a1, $t1, $t2
    ctx->r5 = SUB32(ctx->r9, ctx->r10);
        goto L_80032A8C;
    // 0x80032A74: subu        $a1, $t1, $t2
    ctx->r5 = SUB32(ctx->r9, ctx->r10);
L_80032A78:
    // 0x80032A78: lh          $t3, 0xF2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XF2);
    // 0x80032A7C: lh          $t4, 0xEE($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XEE);
    // 0x80032A80: nop

    // 0x80032A84: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    // 0x80032A88: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_80032A8C:
    // 0x80032A8C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x80032A90: lwc1        $f16, 0xF8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80032A94: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80032A98: lwc1        $f4, 0x100($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X100);
    // 0x80032A9C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80032AA0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80032AA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80032AA8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80032AAC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80032AB0: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80032AB4: lh          $t5, 0xF0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XF0);
    // 0x80032AB8: lh          $t6, 0xEC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XEC);
    // 0x80032ABC: nop

    // 0x80032AC0: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80032AC4: blez        $t7, L_80032ADC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80032AC8: nop
    
            goto L_80032ADC;
    }
    // 0x80032AC8: nop

    // 0x80032ACC: lh          $t8, 0xF0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XF0);
    // 0x80032AD0: lh          $t9, 0xEC($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XEC);
    // 0x80032AD4: b           L_80032AF0
    // 0x80032AD8: subu        $a1, $t8, $t9
    ctx->r5 = SUB32(ctx->r24, ctx->r25);
        goto L_80032AF0;
    // 0x80032AD8: subu        $a1, $t8, $t9
    ctx->r5 = SUB32(ctx->r24, ctx->r25);
L_80032ADC:
    // 0x80032ADC: lh          $t0, 0xF0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XF0);
    // 0x80032AE0: lh          $t1, 0xEC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XEC);
    // 0x80032AE4: nop

    // 0x80032AE8: subu        $a1, $t0, $t1
    ctx->r5 = SUB32(ctx->r8, ctx->r9);
    // 0x80032AEC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_80032AF0:
    // 0x80032AF0: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x80032AF4: lwc1        $f4, 0xF4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80032AF8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80032AFC: lwc1        $f8, 0xF4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80032B00: lwc1        $f16, 0xFC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x80032B04: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80032B08: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80032B0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80032B10: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80032B14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80032B18: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80032B1C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80032B20: lh          $t2, 0xF2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XF2);
    // 0x80032B24: lh          $t3, 0xEE($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XEE);
    // 0x80032B28: nop

    // 0x80032B2C: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80032B30: blez        $t4, L_80032B48
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80032B34: nop
    
            goto L_80032B48;
    }
    // 0x80032B34: nop

    // 0x80032B38: lh          $t5, 0xF2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XF2);
    // 0x80032B3C: lh          $t6, 0xEE($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XEE);
    // 0x80032B40: b           L_80032B5C
    // 0x80032B44: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
        goto L_80032B5C;
    // 0x80032B44: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
L_80032B48:
    // 0x80032B48: lh          $t7, 0xF2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XF2);
    // 0x80032B4C: lh          $t8, 0xEE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XEE);
    // 0x80032B50: nop

    // 0x80032B54: subu        $a1, $t7, $t8
    ctx->r5 = SUB32(ctx->r15, ctx->r24);
    // 0x80032B58: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_80032B5C:
    // 0x80032B5C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x80032B60: lwc1        $f16, 0xF8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80032B64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80032B68: lwc1        $f4, 0xF8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80032B6C: lwc1        $f8, 0x100($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X100);
    // 0x80032B70: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80032B74: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80032B78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80032B7C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80032B80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80032B84: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80032B88: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x80032B8C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80032B90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80032B94: lwc1        $f4, 0xF4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80032B98: nop

    // 0x80032B9C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80032BA0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80032BA4: nop

    // 0x80032BA8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80032BAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032BB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032BB4: nop

    // 0x80032BB8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80032BBC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80032BC0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80032BC4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80032BC8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80032BCC: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80032BD0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
L_80032BD4:
    // 0x80032BD4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80032BD8: nop

    // 0x80032BDC: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x80032BE0: beq         $t4, $zero, L_80032C08
    if (ctx->r12 == 0) {
        // 0x80032BE4: nop
    
            goto L_80032C08;
    }
    // 0x80032BE4: nop

    // 0x80032BE8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80032BEC: nop

    // 0x80032BF0: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x80032BF4: beq         $t6, $zero, L_80032C00
    if (ctx->r14 == 0) {
        // 0x80032BF8: nop
    
            goto L_80032C00;
    }
    // 0x80032BF8: nop

    // 0x80032BFC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_80032C00:
    // 0x80032C00: b           L_80032C2C
    // 0x80032C04: nop

        goto L_80032C2C;
    // 0x80032C04: nop

L_80032C08:
    // 0x80032C08: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80032C0C: nop

    // 0x80032C10: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80032C14: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80032C18: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80032C1C: nop

    // 0x80032C20: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80032C24: bgtz        $t0, L_80032BD4
    if (SIGNED(ctx->r8) > 0) {
        // 0x80032C28: sw          $t0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r8;
            goto L_80032BD4;
    }
    // 0x80032C28: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
L_80032C2C:
    // 0x80032C2C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80032C30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80032C34: lwc1        $f16, 0xF8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80032C38: nop

    // 0x80032C3C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80032C40: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80032C44: nop

    // 0x80032C48: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80032C4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032C50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032C54: nop

    // 0x80032C58: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032C5C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80032C60: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80032C64: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80032C68: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80032C6C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80032C70: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80032C74:
    // 0x80032C74: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80032C78: nop

    // 0x80032C7C: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80032C80: beq         $t6, $zero, L_80032CA8
    if (ctx->r14 == 0) {
        // 0x80032C84: nop
    
            goto L_80032CA8;
    }
    // 0x80032C84: nop

    // 0x80032C88: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80032C8C: nop

    // 0x80032C90: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x80032C94: beq         $t8, $zero, L_80032CA0
    if (ctx->r24 == 0) {
        // 0x80032C98: nop
    
            goto L_80032CA0;
    }
    // 0x80032C98: nop

    // 0x80032C9C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80032CA0:
    // 0x80032CA0: b           L_80032CCC
    // 0x80032CA4: nop

        goto L_80032CCC;
    // 0x80032CA4: nop

L_80032CA8:
    // 0x80032CA8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80032CAC: nop

    // 0x80032CB0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80032CB4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80032CB8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80032CBC: nop

    // 0x80032CC0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80032CC4: bgtz        $t2, L_80032C74
    if (SIGNED(ctx->r10) > 0) {
        // 0x80032CC8: sw          $t2, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r10;
            goto L_80032C74;
    }
    // 0x80032CC8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80032CCC:
    // 0x80032CCC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80032CD0: nop

    // 0x80032CD4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80032CD8: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80032CDC: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80032CE0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80032CE4: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x80032CE8: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x80032CEC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80032CF0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80032CF4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80032CF8: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x80032CFC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80032D00: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80032D04: nop

    // 0x80032D08: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80032D0C: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x80032D10: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80032D14: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80032D18: lui         $t1, 0x430
    ctx->r9 = S32(0X430 << 16);
    // 0x80032D1C: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x80032D20: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80032D24: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80032D28: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x80032D2C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80032D30: nop

    // 0x80032D34: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80032D38: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80032D3C: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x80032D40: lh          $t5, 0xEC($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XEC);
    // 0x80032D44: nop

    // 0x80032D48: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80032D4C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80032D50: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x80032D54: lh          $t7, 0xEE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XEE);
    // 0x80032D58: nop

    // 0x80032D5C: sh          $t7, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r15;
    // 0x80032D60: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80032D64: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x80032D68: nop

    // 0x80032D6C: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x80032D70: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80032D74: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80032D78: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80032D7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032D80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032D84: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80032D88: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80032D8C: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x80032D90: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80032D94: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80032D98: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x80032D9C: nop

    // 0x80032DA0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80032DA4: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80032DA8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80032DAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032DB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032DB4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80032DB8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80032DBC: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x80032DC0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80032DC4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80032DC8: sh          $t4, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r12;
    // 0x80032DCC: nop

    // 0x80032DD0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80032DD4: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x80032DD8: nop

    // 0x80032DDC: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x80032DE0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80032DE4: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x80032DE8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80032DEC: sb          $t7, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r15;
    // 0x80032DF0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80032DF4: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x80032DF8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80032DFC: sb          $t9, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r25;
    // 0x80032E00: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80032E04: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x80032E08: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80032E0C: sb          $t1, 0xE($t2)
    MEM_B(0XE, ctx->r10) = ctx->r9;
    // 0x80032E10: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80032E14: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x80032E18: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80032E1C: sb          $t3, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r11;
    // 0x80032E20: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80032E24: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x80032E28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80032E2C: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x80032E30: sw          $t6, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r14;
    // 0x80032E34: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80032E38: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x80032E3C: lh          $t7, 0xF0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XF0);
    // 0x80032E40: nop

    // 0x80032E44: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80032E48: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80032E4C: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x80032E50: lh          $t9, 0xEE($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XEE);
    // 0x80032E54: nop

    // 0x80032E58: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80032E5C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80032E60: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x80032E64: nop

    // 0x80032E68: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
    // 0x80032E6C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80032E70: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80032E74: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80032E78: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032E7C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032E80: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80032E84: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032E88: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x80032E8C: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80032E90: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80032E94: sh          $t3, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r11;
    // 0x80032E98: nop

    // 0x80032E9C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80032EA0: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80032EA4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80032EA8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032EAC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032EB0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80032EB4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80032EB8: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x80032EBC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80032EC0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80032EC4: sh          $t6, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r14;
    // 0x80032EC8: nop

    // 0x80032ECC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80032ED0: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x80032ED4: nop

    // 0x80032ED8: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x80032EDC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80032EE0: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x80032EE4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80032EE8: sb          $t9, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r25;
    // 0x80032EEC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80032EF0: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x80032EF4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80032EF8: sb          $t1, 0xD($t2)
    MEM_B(0XD, ctx->r10) = ctx->r9;
    // 0x80032EFC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80032F00: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x80032F04: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80032F08: sb          $t3, 0xE($t4)
    MEM_B(0XE, ctx->r12) = ctx->r11;
    // 0x80032F0C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80032F10: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x80032F14: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80032F18: sb          $t5, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r13;
    // 0x80032F1C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80032F20: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x80032F24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80032F28: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80032F2C: sw          $t8, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r24;
    // 0x80032F30: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80032F34: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x80032F38: lh          $t9, 0xEC($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XEC);
    // 0x80032F3C: nop

    // 0x80032F40: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80032F44: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80032F48: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x80032F4C: lh          $t1, 0xF2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XF2);
    // 0x80032F50: nop

    // 0x80032F54: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80032F58: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80032F5C: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x80032F60: nop

    // 0x80032F64: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x80032F68: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80032F6C: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80032F70: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80032F74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032F78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032F7C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80032F80: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80032F84: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x80032F88: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80032F8C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80032F90: sh          $t5, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r13;
    // 0x80032F94: nop

    // 0x80032F98: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032F9C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80032FA0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032FA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032FA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032FAC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80032FB0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032FB4: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x80032FB8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80032FBC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032FC0: sh          $t8, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r24;
    // 0x80032FC4: nop

    // 0x80032FC8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80032FCC: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x80032FD0: nop

    // 0x80032FD4: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x80032FD8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80032FDC: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x80032FE0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80032FE4: sb          $t1, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r9;
    // 0x80032FE8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80032FEC: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x80032FF0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80032FF4: sb          $t3, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r11;
    // 0x80032FF8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80032FFC: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x80033000: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80033004: sb          $t5, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r13;
    // 0x80033008: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003300C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x80033010: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80033014: sb          $t7, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r15;
    // 0x80033018: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003301C: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x80033020: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80033024: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80033028: sw          $t0, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r8;
    // 0x8003302C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80033030: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x80033034: lh          $t1, 0xF0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XF0);
    // 0x80033038: nop

    // 0x8003303C: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80033040: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80033044: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x80033048: lh          $t3, 0xF2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XF2);
    // 0x8003304C: nop

    // 0x80033050: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80033054: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80033058: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8003305C: nop

    // 0x80033060: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x80033064: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80033068: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003306C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80033070: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033074: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033078: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003307C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80033080: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x80033084: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80033088: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003308C: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x80033090: nop

    // 0x80033094: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033098: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003309C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800330A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800330A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800330A8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800330AC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800330B0: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800330B4: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800330B8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800330BC: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    // 0x800330C0: nop

    // 0x800330C4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800330C8: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800330CC: nop

    // 0x800330D0: sh          $zero, 0x6($t2)
    MEM_H(0X6, ctx->r10) = 0;
    // 0x800330D4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800330D8: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800330DC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800330E0: sb          $t3, 0xC($t4)
    MEM_B(0XC, ctx->r12) = ctx->r11;
    // 0x800330E4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800330E8: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800330EC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800330F0: sb          $t5, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r13;
    // 0x800330F4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800330F8: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800330FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80033100: sb          $t7, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r15;
    // 0x80033104: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80033108: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8003310C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80033110: sb          $t9, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r25;
    // 0x80033114: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80033118: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8003311C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80033120: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x80033124: sw          $t2, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r10;
    // 0x80033128: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8003312C: nop

    // 0x80033130: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80033134: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80033138: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8003313C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80033140: lui         $t5, 0xFD10
    ctx->r13 = S32(0XFD10 << 16);
    // 0x80033144: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80033148: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x8003314C: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x80033150: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80033154: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80033158: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8003315C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80033160: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80033164: nop

    // 0x80033168: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003316C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80033170: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80033174: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80033178: lui         $t2, 0xF510
    ctx->r10 = S32(0XF510 << 16);
    // 0x8003317C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80033180: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80033184: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80033188: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8003318C: sll         $t6, $t5, 14
    ctx->r14 = S32(ctx->r13 << 14);
    // 0x80033190: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80033194: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80033198: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8003319C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800331A0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800331A4: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x800331A8: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800331AC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800331B0: nop

    // 0x800331B4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800331B8: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800331BC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800331C0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800331C4: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800331C8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800331CC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800331D0: nop

    // 0x800331D4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800331D8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800331DC: nop

    // 0x800331E0: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x800331E4: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x800331E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800331EC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800331F0: lui         $t0, 0xF300
    ctx->r8 = S32(0XF300 << 16);
    // 0x800331F4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800331F8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800331FC: lwc1        $f4, 0xF4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80033200: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80033204: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033208: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003320C: lwc1        $f8, 0xF8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80033210: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033214: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80033218: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8003321C: nop

    // 0x80033220: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80033224: nop

    // 0x80033228: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8003322C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033230: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033234: nop

    // 0x80033238: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003323C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80033240: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80033244: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033248: mflo        $t6
    ctx->r14 = lo;
    // 0x8003324C: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80033250: slti        $at, $t8, 0x7FF
    ctx->r1 = SIGNED(ctx->r24) < 0X7FF ? 1 : 0;
    // 0x80033254: beq         $at, $zero, L_800332BC
    if (ctx->r1 == 0) {
        // 0x80033258: nop
    
            goto L_800332BC;
    }
    // 0x80033258: nop

    // 0x8003325C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033260: lwc1        $f16, 0xF4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80033264: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80033268: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003326C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033270: lwc1        $f4, 0xF8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80033274: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80033278: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003327C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80033280: nop

    // 0x80033284: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80033288: nop

    // 0x8003328C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80033290: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033294: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033298: nop

    // 0x8003329C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800332A0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800332A4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800332A8: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800332AC: mflo        $a3
    ctx->r7 = lo;
    // 0x800332B0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800332B4: b           L_800332C0
    // 0x800332B8: nop

        goto L_800332C0;
    // 0x800332B8: nop

L_800332BC:
    // 0x800332BC: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
L_800332C0:
    // 0x800332C0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800332C4: lwc1        $f8, 0xF4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x800332C8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800332CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800332D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800332D4: nop

    // 0x800332D8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800332DC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800332E0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800332E4: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x800332E8: bgez        $t3, L_800332F8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800332EC: sra         $t5, $t3, 3
        ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
            goto L_800332F8;
    }
    // 0x800332EC: sra         $t5, $t3, 3
    ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
    // 0x800332F0: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x800332F4: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_800332F8:
    // 0x800332F8: bgtz        $t5, L_80033308
    if (SIGNED(ctx->r13) > 0) {
        // 0x800332FC: nop
    
            goto L_80033308;
    }
    // 0x800332FC: nop

    // 0x80033300: b           L_80033348
    // 0x80033304: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80033348;
    // 0x80033304: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80033308:
    // 0x80033308: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003330C: lwc1        $f16, 0xF4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80033310: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80033314: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033318: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003331C: nop

    // 0x80033320: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80033324: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80033328: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003332C: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80033330: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80033334: bgez        $a2, L_80033344
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80033338: sra         $t9, $a2, 3
        ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
            goto L_80033344;
    }
    // 0x80033338: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8003333C: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x80033340: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_80033344:
    // 0x80033344: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_80033348:
    // 0x80033348: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8003334C: lwc1        $f4, 0xF4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80033350: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80033354: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033358: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003335C: nop

    // 0x80033360: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033364: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80033368: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003336C: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x80033370: bgez        $t1, L_80033380
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80033374: sra         $t2, $t1, 3
        ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
            goto L_80033380;
    }
    // 0x80033374: sra         $t2, $t1, 3
    ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80033378: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x8003337C: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_80033380:
    // 0x80033380: bgtz        $t2, L_80033390
    if (SIGNED(ctx->r10) > 0) {
        // 0x80033384: nop
    
            goto L_80033390;
    }
    // 0x80033384: nop

    // 0x80033388: b           L_800333D0
    // 0x8003338C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800333D0;
    // 0x8003338C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80033390:
    // 0x80033390: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80033394: lwc1        $f8, 0xF4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80033398: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8003339C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800333A4: nop

    // 0x800333A8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800333AC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800333B0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800333B4: sll         $t3, $a1, 1
    ctx->r11 = S32(ctx->r5 << 1);
    // 0x800333B8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800333BC: bgez        $a1, L_800333CC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800333C0: sra         $t5, $a1, 3
        ctx->r13 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800333CC;
    }
    // 0x800333C0: sra         $t5, $a1, 3
    ctx->r13 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800333C4: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x800333C8: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_800333CC:
    // 0x800333CC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_800333D0:
    // 0x800333D0: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x800333D4: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x800333D8: andi        $t0, $a3, 0xFFF
    ctx->r8 = ctx->r7 & 0XFFF;
    // 0x800333DC: bne         $a1, $zero, L_800333E8
    if (ctx->r5 != 0) {
        // 0x800333E0: nop
    
            goto L_800333E8;
    }
    // 0x800333E0: nop

    // 0x800333E4: break       7
    do_break(2147693540);
L_800333E8:
    // 0x800333E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800333EC: bne         $a1, $at, L_80033400
    if (ctx->r5 != ctx->r1) {
        // 0x800333F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80033400;
    }
    // 0x800333F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800333F4: bne         $t6, $at, L_80033400
    if (ctx->r14 != ctx->r1) {
        // 0x800333F8: nop
    
            goto L_80033400;
    }
    // 0x800333F8: nop

    // 0x800333FC: break       6
    do_break(2147693564);
L_80033400:
    // 0x80033400: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80033404: sll         $t7, $t0, 12
    ctx->r15 = S32(ctx->r8 << 12);
    // 0x80033408: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8003340C: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x80033410: mflo        $t8
    ctx->r24 = lo;
    // 0x80033414: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80033418: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8003341C: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x80033420: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80033424: nop

    // 0x80033428: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8003342C: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x80033430: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80033434: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80033438: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8003343C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80033440: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80033444: nop

    // 0x80033448: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8003344C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80033450: nop

    // 0x80033454: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80033458: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8003345C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80033460: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80033464: lwc1        $f16, 0xF4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x80033468: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8003346C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033470: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033474: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80033478: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003347C: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80033480: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80033484: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80033488: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8003348C: addiu       $t3, $t4, 0x7
    ctx->r11 = ADD32(ctx->r12, 0X7);
    // 0x80033490: sra         $t5, $t3, 3
    ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80033494: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80033498: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8003349C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x800334A0: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x800334A4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800334A8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800334AC: andi        $t1, $t9, 0xF
    ctx->r9 = ctx->r25 & 0XF;
    // 0x800334B0: andi        $t3, $t4, 0xF
    ctx->r11 = ctx->r12 & 0XF;
    // 0x800334B4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800334B8: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x800334BC: sll         $t2, $t1, 14
    ctx->r10 = S32(ctx->r9 << 14);
    // 0x800334C0: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800334C4: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x800334C8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800334CC: nop

    // 0x800334D0: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800334D4: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x800334D8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800334DC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800334E0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800334E4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800334E8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800334EC: lwc1        $f4, 0xF4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x800334F0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800334F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800334F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800334FC: lwc1        $f8, 0xF8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80033500: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033504: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80033508: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8003350C: nop

    // 0x80033510: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80033514: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x80033518: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8003351C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033520: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033524: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80033528: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003352C: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80033530: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80033534: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80033538: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8003353C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80033540: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x80033544: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80033548: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003354C: or          $t3, $t8, $t4
    ctx->r11 = ctx->r24 | ctx->r12;
    // 0x80033550: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x80033554: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80033558: nop

    // 0x8003355C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80033560: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80033564: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80033568: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003356C: lui         $t0, 0xBF00
    ctx->r8 = S32(0XBF00 << 16);
    // 0x80033570: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x80033574: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80033578: addiu       $t9, $zero, 0x1E0A
    ctx->r25 = ADD32(0, 0X1E0A);
    // 0x8003357C: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80033580: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80033584: nop

    // 0x80033588: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x8003358C: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80033590: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80033594: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80033598: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x8003359C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800335A0: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800335A4: addiu       $t5, $zero, 0x141E
    ctx->r13 = ADD32(0, 0X141E);
    // 0x800335A8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800335AC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800335B0: nop

    // 0x800335B4: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800335B8: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x800335BC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800335C0: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x800335C4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800335C8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800335CC: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800335D0: nop

    // 0x800335D4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800335D8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800335DC: nop

    // 0x800335E0: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800335E4: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x800335E8: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800335EC: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800335F0: lui         $t2, 0xB800
    ctx->r10 = S32(0XB800 << 16);
    // 0x800335F4: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800335F8: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800335FC: nop

    // 0x80033600: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80033604: b           L_8003360C
    // 0x80033608: nop

        goto L_8003360C;
    // 0x80033608: nop

L_8003360C:
    // 0x8003360C: jr          $ra
    // 0x80033610: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80033610: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800658B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800658B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800658BC: jal         0x8005F064
    // 0x800658C0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800658C0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_0:
    // 0x800658C4: b           L_800658D4
    // 0x800658C8: nop

        goto L_800658D4;
    // 0x800658C8: nop

    // 0x800658CC: b           L_800658D4
    // 0x800658D0: nop

        goto L_800658D4;
    // 0x800658D0: nop

L_800658D4:
    // 0x800658D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800658D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800658DC: jr          $ra
    // 0x800658E0: nop

    return;
    // 0x800658E0: nop

;}
RECOMP_FUNC void func_8007A8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A8B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A8C0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A8C4: lw          $t6, 0x70F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F8);
    // 0x8007A8C8: nop

    // 0x8007A8CC: beq         $t6, $zero, L_8007A8E0
    if (ctx->r14 == 0) {
        // 0x8007A8D0: nop
    
            goto L_8007A8E0;
    }
    // 0x8007A8D0: nop

    // 0x8007A8D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A8D8: bne         $t6, $at, L_8007A910
    if (ctx->r14 != ctx->r1) {
        // 0x8007A8DC: nop
    
            goto L_8007A910;
    }
    // 0x8007A8DC: nop

L_8007A8E0:
    // 0x8007A8E0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A8E4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8007A8E8: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x8007A8EC: lhu         $t7, 0x7148($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7148);
    // 0x8007A8F0: nop

    // 0x8007A8F4: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8007A8F8: beq         $t9, $zero, L_8007A910
    if (ctx->r25 == 0) {
        // 0x8007A8FC: nop
    
            goto L_8007A910;
    }
    // 0x8007A8FC: nop

    // 0x8007A900: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007A904: lhu         $v0, 0x101C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X101C);
    // 0x8007A908: b           L_8007AA80
    // 0x8007A90C: nop

        goto L_8007AA80;
    // 0x8007A90C: nop

L_8007A910:
    // 0x8007A910: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8007A914: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8007A918: lhu         $t1, 0xFF4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XFF4);
    // 0x8007A91C: lhu         $t0, 0x10F2($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X10F2);
    // 0x8007A920: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007A924: lhu         $t3, 0x7148($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7148);
    // 0x8007A928: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x8007A92C: and         $t4, $t3, $t2
    ctx->r12 = ctx->r11 & ctx->r10;
    // 0x8007A930: beq         $t4, $zero, L_8007A994
    if (ctx->r12 == 0) {
        // 0x8007A934: nop
    
            goto L_8007A994;
    }
    // 0x8007A934: nop

    // 0x8007A938: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A93C: lw          $t5, 0x70F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F8);
    // 0x8007A940: nop

    // 0x8007A944: beq         $t5, $zero, L_8007A958
    if (ctx->r13 == 0) {
        // 0x8007A948: nop
    
            goto L_8007A958;
    }
    // 0x8007A948: nop

    // 0x8007A94C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A950: bne         $t5, $at, L_8007A968
    if (ctx->r13 != ctx->r1) {
        // 0x8007A954: nop
    
            goto L_8007A968;
    }
    // 0x8007A954: nop

L_8007A958:
    // 0x8007A958: jal         0x800B9000
    // 0x8007A95C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x8007A95C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8007A960: b           L_8007A970
    // 0x8007A964: nop

        goto L_8007A970;
    // 0x8007A964: nop

L_8007A968:
    // 0x8007A968: jal         0x800B9000
    // 0x8007A96C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8007A96C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_1:
L_8007A970:
    // 0x8007A970: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007A974: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007A978: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x8007A97C: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8007A980: nop

    // 0x8007A984: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x8007A988: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8007A98C: b           L_8007AA80
    // 0x8007A990: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8007AA80;
    // 0x8007A990: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8007A994:
    // 0x8007A994: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A998: lwc1        $f4, 0x713C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X713C);
    // 0x8007A99C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007A9A0: nop

    // 0x8007A9A4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8007A9A8: nop

    // 0x8007A9AC: bc1f        L_8007AA08
    if (!c1cs) {
        // 0x8007A9B0: nop
    
            goto L_8007AA08;
    }
    // 0x8007A9B0: nop

    // 0x8007A9B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A9B8: lwc1        $f8, 0x713C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X713C);
    // 0x8007A9BC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007A9C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A9C4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007A9C8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007A9CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007A9D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007A9D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A9D8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8007A9DC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8007A9E0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007A9E4: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8007A9E8: sra         $t3, $t1, 16
    ctx->r11 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8007A9EC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8007A9F0: nop

    // 0x8007A9F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007A9F8: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8007A9FC: swc1        $f6, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f6.u32l;
    // 0x8007AA00: b           L_8007AA80
    // 0x8007AA04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007AA80;
    // 0x8007AA04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AA08:
    // 0x8007AA08: jal         0x8007AA90
    // 0x8007AA0C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8007AA90(rdram, ctx);
        goto after_2;
    // 0x8007AA0C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8007AA10: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007AA14: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007AA18: nop

    // 0x8007AA1C: beq         $t2, $zero, L_8007AA70
    if (ctx->r10 == 0) {
        // 0x8007AA20: nop
    
            goto L_8007AA70;
    }
    // 0x8007AA20: nop

    // 0x8007AA24: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007AA28: lh          $a0, 0x7132($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7132);
    // 0x8007AA2C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8007AA30: jal         0x8007B3DC
    // 0x8007AA34: nop

    func_8007B3DC(rdram, ctx);
        goto after_3;
    // 0x8007AA34: nop

    after_3:
    // 0x8007AA38: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8007AA3C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007AA40: lh          $t5, 0x7132($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7132);
    // 0x8007AA44: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8007AA48: nop

    // 0x8007AA4C: beq         $t4, $t5, L_8007AA70
    if (ctx->r12 == ctx->r13) {
        // 0x8007AA50: nop
    
            goto L_8007AA70;
    }
    // 0x8007AA50: nop

    // 0x8007AA54: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x8007AA58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AA5C: sh          $t6, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r14;
    // 0x8007AA60: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007AA64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007AA68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AA6C: swc1        $f10, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f10.u32l;
L_8007AA70:
    // 0x8007AA70: b           L_8007AA80
    // 0x8007AA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007AA80;
    // 0x8007AA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007AA78: b           L_8007AA80
    // 0x8007AA7C: nop

        goto L_8007AA80;
    // 0x8007AA7C: nop

L_8007AA80:
    // 0x8007AA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007AA84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007AA88: jr          $ra
    // 0x8007AA8C: nop

    return;
    // 0x8007AA8C: nop

;}
RECOMP_FUNC void func_80077D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077D14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077D18: nop

    // 0x80077D1C: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80077D20: nop

    // 0x80077D24: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80077D28: jr          $ra
    // 0x80077D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077D30: jr          $ra
    // 0x80077D34: nop

    return;
    // 0x80077D34: nop

    // 0x80077D38: jr          $ra
    // 0x80077D3C: nop

    return;
    // 0x80077D3C: nop

;}
RECOMP_FUNC void func_80063D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D78: jal         0x80061488
    // 0x80063D7C: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063D7C: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    after_0:
    // 0x80063D80: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063D84: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063D88: b           L_80063D98
    // 0x80063D8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063D98;
    // 0x80063D8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063D90: b           L_80063D98
    // 0x80063D94: nop

        goto L_80063D98;
    // 0x80063D94: nop

L_80063D98:
    // 0x80063D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063DA0: jr          $ra
    // 0x80063DA4: nop

    return;
    // 0x80063DA4: nop

;}
RECOMP_FUNC void Thread_UnkDbgFunc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0F1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C0F20: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0F24: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0F28: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0F2C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0F30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0F34: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0F38: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0F3C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0F40: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0F44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0F48: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0F4C: nop

    // 0x800C0F50: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0F54: bne         $t9, $zero, L_800C0F64
    if (ctx->r25 != 0) {
        // 0x800C0F58: nop
    
            goto L_800C0F64;
    }
    // 0x800C0F58: nop

    // 0x800C0F5C: b           L_800C0FA0
    // 0x800C0F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0FA0;
    // 0x800C0F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0F64:
    // 0x800C0F64: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0F68: jal         0x800C0FFC
    // 0x800C0F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Thread_SetPriority(rdram, ctx);
        goto after_0;
    // 0x800C0F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800C0F70: beq         $v0, $zero, L_800C0F80
    if (ctx->r2 == 0) {
        // 0x800C0F74: nop
    
            goto L_800C0F80;
    }
    // 0x800C0F74: nop

    // 0x800C0F78: b           L_800C0FA0
    // 0x800C0F7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0FA0;
    // 0x800C0F7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0F80:
    // 0x800C0F80: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C0F84: jal         0x800C0C8C
    // 0x800C0F88: nop

    Thread_Start(rdram, ctx);
        goto after_1;
    // 0x800C0F88: nop

    after_1:
    // 0x800C0F8C: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0F90: jal         0x800C0D34
    // 0x800C0F94: nop

    Thread_StopThread(rdram, ctx);
        goto after_2;
    // 0x800C0F94: nop

    after_2:
    // 0x800C0F98: b           L_800C0FA0
    // 0x800C0F9C: nop

        goto L_800C0FA0;
    // 0x800C0F9C: nop

L_800C0FA0:
    // 0x800C0FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0FA8: jr          $ra
    // 0x800C0FAC: nop

    return;
    // 0x800C0FAC: nop

;}
RECOMP_FUNC void func_800683B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800683B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800683B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800683B8: nop

    // 0x800683BC: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x800683C0: nop

    // 0x800683C4: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800683C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800683CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800683D0: beq         $v0, $zero, L_800683EC
    if (ctx->r2 == 0) {
        // 0x800683D4: nop
    
            goto L_800683EC;
    }
    // 0x800683D4: nop

    // 0x800683D8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x800683DC: nop

    // 0x800683E0: slti        $t8, $v0, 0x64
    ctx->r24 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800683E4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800683E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800683EC:
    // 0x800683EC: jr          $ra
    // 0x800683F0: nop

    return;
    // 0x800683F0: nop

    // 0x800683F4: jr          $ra
    // 0x800683F8: nop

    return;
    // 0x800683F8: nop

    // 0x800683FC: jr          $ra
    // 0x80068400: nop

    return;
    // 0x80068400: nop

;}
RECOMP_FUNC void func_80068644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068644: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068648: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006864C: nop

    // 0x80068650: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068654: nop

    // 0x80068658: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006865C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068660: jr          $ra
    // 0x80068664: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068664: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068668: jr          $ra
    // 0x8006866C: nop

    return;
    // 0x8006866C: nop

    // 0x80068670: jr          $ra
    // 0x80068674: nop

    return;
    // 0x80068674: nop

;}
RECOMP_FUNC void func_800652F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800652F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800652F8: jal         0x8005F064
    // 0x800652FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800652FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80065300: b           L_80065310
    // 0x80065304: nop

        goto L_80065310;
    // 0x80065304: nop

    // 0x80065308: b           L_80065310
    // 0x8006530C: nop

        goto L_80065310;
    // 0x8006530C: nop

L_80065310:
    // 0x80065310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065318: jr          $ra
    // 0x8006531C: nop

    return;
    // 0x8006531C: nop

;}
RECOMP_FUNC void AudioDriver_UpdateOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBBBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BBBC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BBBC4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BBBC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BBBCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BBBD0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800BBBD4: nop

    // 0x800BBBD8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800BBBDC: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x800BBBE0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800BBBE4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BBBE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BBBEC: lbu         $s0, 0x4($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X4);
    // 0x800BBBF0: nop

    // 0x800BBBF4: beq         $s0, $at, L_800BBC58
    if (ctx->r16 == ctx->r1) {
        // 0x800BBBF8: nop
    
            goto L_800BBC58;
    }
    // 0x800BBBF8: nop

    // 0x800BBBFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BBC00: beq         $s0, $at, L_800BBD9C
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC04: nop
    
            goto L_800BBD9C;
    }
    // 0x800BBC04: nop

    // 0x800BBC08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BBC0C: beq         $s0, $at, L_800BBE68
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC10: nop
    
            goto L_800BBE68;
    }
    // 0x800BBC10: nop

    // 0x800BBC14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BBC18: beq         $s0, $at, L_800BBF80
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC1C: nop
    
            goto L_800BBF80;
    }
    // 0x800BBC1C: nop

    // 0x800BBC20: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800BBC24: beq         $s0, $at, L_800BC098
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC28: nop
    
            goto L_800BC098;
    }
    // 0x800BBC28: nop

    // 0x800BBC2C: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x800BBC30: beq         $s0, $at, L_800BC1B0
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC34: nop
    
            goto L_800BC1B0;
    }
    // 0x800BBC34: nop

    // 0x800BBC38: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x800BBC3C: beq         $s0, $at, L_800BC230
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC40: nop
    
            goto L_800BC230;
    }
    // 0x800BBC40: nop

    // 0x800BBC44: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x800BBC48: beq         $s0, $at, L_800BC358
    if (ctx->r16 == ctx->r1) {
        // 0x800BBC4C: nop
    
            goto L_800BC358;
    }
    // 0x800BBC4C: nop

    // 0x800BBC50: b           L_800BC480
    // 0x800BBC54: nop

        goto L_800BC480;
    // 0x800BBC54: nop

L_800BBC58:
    // 0x800BBC58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBC5C: nop

    // 0x800BBC60: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x800BBC64: nop

    // 0x800BBC68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BBC6C: sh          $t1, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r9;
    // 0x800BBC70: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BBC74: nop

    // 0x800BBC78: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800BBC7C: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x800BBC80: nop

    // 0x800BBC84: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BBC88: bne         $at, $zero, L_800BBC9C
    if (ctx->r1 != 0) {
        // 0x800BBC8C: nop
    
            goto L_800BBC9C;
    }
    // 0x800BBC8C: nop

    // 0x800BBC90: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BBC94: nop

    // 0x800BBC98: sh          $zero, 0x8($t5)
    MEM_H(0X8, ctx->r13) = 0;
L_800BBC9C:
    // 0x800BBC9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BBCA0: nop

    // 0x800BBCA4: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x800BBCA8: nop

    // 0x800BBCAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BBCB0: bgez        $t7, L_800BBCC8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800BBCB4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BBCC8;
    }
    // 0x800BBCB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBCB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBCBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBCC0: nop

    // 0x800BBCC4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800BBCC8:
    // 0x800BBCC8: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x800BBCCC: nop

    // 0x800BBCD0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BBCD4: bgez        $t8, L_800BBCEC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800BBCD8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BBCEC;
    }
    // 0x800BBCD8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBCDC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBCE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BBCE4: nop

    // 0x800BBCE8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800BBCEC:
    // 0x800BBCEC: nop

    // 0x800BBCF0: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BBCF4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800BBCF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BBCFC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBD00: lwc1        $f19, -0x238($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X238);
    // 0x800BBD04: lwc1        $f18, -0x234($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X234);
    // 0x800BBD08: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800BBD0C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800BBD10: jal         0x800CAE10
    // 0x800BBD14: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800BBD14: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_0:
    // 0x800BBD18: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800BBD1C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBD20: nop

    // 0x800BBD24: lbu         $t1, 0xC($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XC);
    // 0x800BBD28: nop

    // 0x800BBD2C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800BBD30: bgez        $t1, L_800BBD48
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800BBD34: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBD48;
    }
    // 0x800BBD34: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBD38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBD3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBD40: nop

    // 0x800BBD44: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800BBD48:
    // 0x800BBD48: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBD4C: nop

    // 0x800BBD50: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBD54: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800BBD58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBD5C: nop

    // 0x800BBD60: lbu         $t2, 0xD($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XD);
    // 0x800BBD64: nop

    // 0x800BBD68: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BBD6C: bgez        $t2, L_800BBD84
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBD70: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800BBD84;
    }
    // 0x800BBD70: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BBD74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBD78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBD7C: nop

    // 0x800BBD80: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_800BBD84:
    // 0x800BBD84: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBD88: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BBD8C: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800BBD90: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x800BBD94: b           L_800BC480
    // 0x800BBD98: nop

        goto L_800BC480;
    // 0x800BBD98: nop

L_800BBD9C:
    // 0x800BBD9C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BBDA0: nop

    // 0x800BBDA4: lbu         $t5, 0x5($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5);
    // 0x800BBDA8: nop

    // 0x800BBDAC: bne         $t5, $zero, L_800BBDFC
    if (ctx->r13 != 0) {
        // 0x800BBDB0: nop
    
            goto L_800BBDFC;
    }
    // 0x800BBDB0: nop

    // 0x800BBDB4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BBDB8: nop

    // 0x800BBDBC: lbu         $t6, 0xE($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XE);
    // 0x800BBDC0: nop

    // 0x800BBDC4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800BBDC8: bgez        $t6, L_800BBDE0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BBDCC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BBDE0;
    }
    // 0x800BBDCC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BBDD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBDD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBDD8: nop

    // 0x800BBDDC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800BBDE0:
    // 0x800BBDE0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BBDE4: nop

    // 0x800BBDE8: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x800BBDEC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BBDF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BBDF4: b           L_800BBE40
    // 0x800BBDF8: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
        goto L_800BBE40;
    // 0x800BBDF8: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
L_800BBDFC:
    // 0x800BBDFC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE00: nop

    // 0x800BBE04: lbu         $t2, 0xD($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XD);
    // 0x800BBE08: nop

    // 0x800BBE0C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800BBE10: bgez        $t2, L_800BBE28
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBE14: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBE28;
    }
    // 0x800BBE14: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBE18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBE1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BBE20: nop

    // 0x800BBE24: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_800BBE28:
    // 0x800BBE28: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BBE2C: nop

    // 0x800BBE30: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800BBE34: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE38: nop

    // 0x800BBE3C: sb          $zero, 0x5($t4)
    MEM_B(0X5, ctx->r12) = 0;
L_800BBE40:
    // 0x800BBE40: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800BBE48: lhu         $t6, 0x6($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X6);
    // 0x800BBE4C: nop

    // 0x800BBE50: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBE54: mflo        $t8
    ctx->r24 = lo;
    // 0x800BBE58: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800BBE5C: nop

    // 0x800BBE60: b           L_800BC480
    // 0x800BBE64: nop

        goto L_800BC480;
    // 0x800BBE64: nop

L_800BBE68:
    // 0x800BBE68: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE6C: nop

    // 0x800BBE70: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x800BBE74: nop

    // 0x800BBE78: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800BBE7C: sh          $t9, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r25;
    // 0x800BBE80: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BBE84: nop

    // 0x800BBE88: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800BBE8C: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x800BBE90: nop

    // 0x800BBE94: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BBE98: beq         $at, $zero, L_800BBEAC
    if (ctx->r1 == 0) {
        // 0x800BBE9C: nop
    
            goto L_800BBEAC;
    }
    // 0x800BBE9C: nop

    // 0x800BBEA0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BBEA4: nop

    // 0x800BBEA8: sh          $zero, 0x8($t7)
    MEM_H(0X8, ctx->r15) = 0;
L_800BBEAC:
    // 0x800BBEAC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BBEB0: nop

    // 0x800BBEB4: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x800BBEB8: nop

    // 0x800BBEBC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800BBEC0: bgez        $t6, L_800BBED8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BBEC4: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BBED8;
    }
    // 0x800BBEC4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BBEC8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBECC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BBED0: nop

    // 0x800BBED4: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800BBED8:
    // 0x800BBED8: lhu         $t8, 0x6($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X6);
    // 0x800BBEDC: nop

    // 0x800BBEE0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BBEE4: bgez        $t8, L_800BBEFC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800BBEE8: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBEFC;
    }
    // 0x800BBEE8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBEEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBEF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BBEF4: nop

    // 0x800BBEF8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800BBEFC:
    // 0x800BBEFC: nop

    // 0x800BBF00: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BBF04: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800BBF08: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF0C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBF10: lbu         $t9, 0xD($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0XD);
    // 0x800BBF14: nop

    // 0x800BBF18: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800BBF1C: bgez        $t9, L_800BBF34
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BBF20: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BBF34;
    }
    // 0x800BBF20: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBF24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBF28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBF2C: nop

    // 0x800BBF30: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800BBF34:
    // 0x800BBF34: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BBF38: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800BBF3C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF40: nop

    // 0x800BBF44: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x800BBF48: nop

    // 0x800BBF4C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BBF50: bgez        $t2, L_800BBF68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBF54: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BBF68;
    }
    // 0x800BBF54: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BBF58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBF5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBF60: nop

    // 0x800BBF64: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_800BBF68:
    // 0x800BBF68: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BBF6C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BBF70: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800BBF74: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800BBF78: b           L_800BC480
    // 0x800BBF7C: nop

        goto L_800BC480;
    // 0x800BBF7C: nop

L_800BBF80:
    // 0x800BBF80: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF84: nop

    // 0x800BBF88: lhu         $t7, 0x8($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X8);
    // 0x800BBF8C: nop

    // 0x800BBF90: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800BBF94: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
    // 0x800BBF98: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BBF9C: nop

    // 0x800BBFA0: lhu         $t8, 0x8($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X8);
    // 0x800BBFA4: lhu         $t1, 0x6($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X6);
    // 0x800BBFA8: nop

    // 0x800BBFAC: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BBFB0: beq         $at, $zero, L_800BBFC4
    if (ctx->r1 == 0) {
        // 0x800BBFB4: nop
    
            goto L_800BBFC4;
    }
    // 0x800BBFB4: nop

    // 0x800BBFB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBFBC: nop

    // 0x800BBFC0: sh          $zero, 0x8($t9)
    MEM_H(0X8, ctx->r25) = 0;
L_800BBFC4:
    // 0x800BBFC4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BBFC8: nop

    // 0x800BBFCC: lhu         $t2, 0x8($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X8);
    // 0x800BBFD0: nop

    // 0x800BBFD4: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800BBFD8: bgez        $t2, L_800BBFF0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BBFDC: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BBFF0;
    }
    // 0x800BBFDC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBFE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBFE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBFE8: nop

    // 0x800BBFEC: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_800BBFF0:
    // 0x800BBFF0: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x800BBFF4: nop

    // 0x800BBFF8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800BBFFC: bgez        $t3, L_800BC014
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BC000: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC014;
    }
    // 0x800BC000: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC004: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BC00C: nop

    // 0x800BC010: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800BC014:
    // 0x800BC014: nop

    // 0x800BC018: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800BC01C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800BC020: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BC024: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC028: lbu         $t6, 0xD($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XD);
    // 0x800BC02C: nop

    // 0x800BC030: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800BC034: bgez        $t6, L_800BC04C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BC038: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC04C;
    }
    // 0x800BC038: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC03C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC040: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC044: nop

    // 0x800BC048: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_800BC04C:
    // 0x800BC04C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800BC050: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC054: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BC058: nop

    // 0x800BC05C: lbu         $t5, 0xC($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XC);
    // 0x800BC060: nop

    // 0x800BC064: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800BC068: bgez        $t5, L_800BC080
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BC06C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BC080;
    }
    // 0x800BC06C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BC070: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC074: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC078: nop

    // 0x800BC07C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800BC080:
    // 0x800BC080: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC084: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BC088: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800BC08C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BC090: b           L_800BC480
    // 0x800BC094: nop

        goto L_800BC480;
    // 0x800BC094: nop

L_800BC098:
    // 0x800BC098: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BC09C: nop

    // 0x800BC0A0: lhu         $t9, 0x8($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X8);
    // 0x800BC0A4: nop

    // 0x800BC0A8: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800BC0AC: sh          $t2, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r10;
    // 0x800BC0B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC0B4: nop

    // 0x800BC0B8: lhu         $t3, 0x8($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X8);
    // 0x800BC0BC: lhu         $t7, 0x6($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X6);
    // 0x800BC0C0: nop

    // 0x800BC0C4: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC0C8: bne         $at, $zero, L_800BC0DC
    if (ctx->r1 != 0) {
        // 0x800BC0CC: nop
    
            goto L_800BC0DC;
    }
    // 0x800BC0CC: nop

    // 0x800BC0D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC0D4: nop

    // 0x800BC0D8: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
L_800BC0DC:
    // 0x800BC0DC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800BC0E0: nop

    // 0x800BC0E4: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x800BC0E8: nop

    // 0x800BC0EC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800BC0F0: bgez        $t5, L_800BC108
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BC0F4: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800BC108;
    }
    // 0x800BC0F4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BC0F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC0FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC100: nop

    // 0x800BC104: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_800BC108:
    // 0x800BC108: lhu         $t8, 0x6($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X6);
    // 0x800BC10C: nop

    // 0x800BC110: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BC114: bgez        $t8, L_800BC12C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800BC118: cvt.s.w     $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC12C;
    }
    // 0x800BC118: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC11C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BC124: nop

    // 0x800BC128: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800BC12C:
    // 0x800BC12C: nop

    // 0x800BC130: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BC134: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC138: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BC13C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC140: lwc1        $f5, -0x230($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X230);
    // 0x800BC144: lwc1        $f4, -0x22C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X22C);
    // 0x800BC148: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800BC14C: mul.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800BC150: jal         0x800CAE10
    // 0x800BC154: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BC154: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800BC158: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BC15C: nop

    // 0x800BC160: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800BC164: nop

    // 0x800BC168: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800BC16C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC170: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800BC174: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC178: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800BC17C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BC180: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BC184: nop

    // 0x800BC188: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800BC18C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x800BC190: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800BC194: jal         0x800CADC0
    // 0x800BC198: nop

    alCents2Ratio(rdram, ctx);
        goto after_2;
    // 0x800BC198: nop

    after_2:
    // 0x800BC19C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BC1A0: nop

    // 0x800BC1A4: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x800BC1A8: b           L_800BC480
    // 0x800BC1AC: nop

        goto L_800BC480;
    // 0x800BC1AC: nop

L_800BC1B0:
    // 0x800BC1B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1B4: nop

    // 0x800BC1B8: lbu         $t3, 0x5($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X5);
    // 0x800BC1BC: nop

    // 0x800BC1C0: bne         $t3, $zero, L_800BC1E8
    if (ctx->r11 != 0) {
        // 0x800BC1C4: nop
    
            goto L_800BC1E8;
    }
    // 0x800BC1C4: nop

    // 0x800BC1C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BC1D0: sb          $t7, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r15;
    // 0x800BC1D4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1D8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800BC1DC: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800BC1E0: b           L_800BC208
    // 0x800BC1E4: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
        goto L_800BC208;
    // 0x800BC1E4: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_800BC1E8:
    // 0x800BC1E8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1EC: nop

    // 0x800BC1F0: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
    // 0x800BC1F4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BC1F8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BC1FC: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800BC200: nop

    // 0x800BC204: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
L_800BC208:
    // 0x800BC208: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC20C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BC210: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x800BC214: nop

    // 0x800BC218: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC21C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC220: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800BC224: nop

    // 0x800BC228: b           L_800BC480
    // 0x800BC22C: nop

        goto L_800BC480;
    // 0x800BC22C: nop

L_800BC230:
    // 0x800BC230: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC234: nop

    // 0x800BC238: lhu         $t5, 0x8($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X8);
    // 0x800BC23C: nop

    // 0x800BC240: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800BC244: sh          $t4, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r12;
    // 0x800BC248: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BC24C: nop

    // 0x800BC250: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800BC254: lhu         $t2, 0x6($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X6);
    // 0x800BC258: nop

    // 0x800BC25C: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BC260: beq         $at, $zero, L_800BC274
    if (ctx->r1 == 0) {
        // 0x800BC264: nop
    
            goto L_800BC274;
    }
    // 0x800BC264: nop

    // 0x800BC268: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC26C: nop

    // 0x800BC270: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
L_800BC274:
    // 0x800BC274: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BC278: nop

    // 0x800BC27C: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x800BC280: nop

    // 0x800BC284: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800BC288: bgez        $t3, L_800BC2A0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BC28C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BC2A0;
    }
    // 0x800BC28C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BC290: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC294: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BC298: nop

    // 0x800BC29C: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_800BC2A0:
    // 0x800BC2A0: lhu         $t7, 0x6($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X6);
    // 0x800BC2A4: nop

    // 0x800BC2A8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800BC2AC: bgez        $t7, L_800BC2C4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800BC2B0: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BC2C4;
    }
    // 0x800BC2B0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC2B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC2B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BC2BC: nop

    // 0x800BC2C0: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_800BC2C4:
    // 0x800BC2C4: nop

    // 0x800BC2C8: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BC2CC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800BC2D0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BC2D4: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC2D8: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x800BC2DC: nop

    // 0x800BC2E0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800BC2E4: nop

    // 0x800BC2E8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC2EC: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800BC2F0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800BC2F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC2F8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC2FC: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800BC300: nop

    // 0x800BC304: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BC308: nop

    // 0x800BC30C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC310: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800BC314: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800BC318: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BC31C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC320: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BC324: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BC328: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BC32C: nop

    // 0x800BC330: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800BC334: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800BC338: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BC33C: jal         0x800CADC0
    // 0x800BC340: nop

    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x800BC340: nop

    after_3:
    // 0x800BC344: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BC348: nop

    // 0x800BC34C: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x800BC350: b           L_800BC480
    // 0x800BC354: nop

        goto L_800BC480;
    // 0x800BC354: nop

L_800BC358:
    // 0x800BC358: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC35C: nop

    // 0x800BC360: lhu         $t3, 0x8($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X8);
    // 0x800BC364: nop

    // 0x800BC368: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x800BC36C: sh          $t1, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r9;
    // 0x800BC370: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BC374: nop

    // 0x800BC378: lhu         $t5, 0x8($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X8);
    // 0x800BC37C: lhu         $t4, 0x6($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X6);
    // 0x800BC380: nop

    // 0x800BC384: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BC388: beq         $at, $zero, L_800BC39C
    if (ctx->r1 == 0) {
        // 0x800BC38C: nop
    
            goto L_800BC39C;
    }
    // 0x800BC38C: nop

    // 0x800BC390: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BC394: nop

    // 0x800BC398: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
L_800BC39C:
    // 0x800BC39C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BC3A0: nop

    // 0x800BC3A4: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800BC3A8: nop

    // 0x800BC3AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BC3B0: bgez        $t9, L_800BC3C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BC3B4: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BC3C8;
    }
    // 0x800BC3B4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC3B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC3BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BC3C0: nop

    // 0x800BC3C4: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_800BC3C8:
    // 0x800BC3C8: lhu         $t2, 0x6($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X6);
    // 0x800BC3CC: nop

    // 0x800BC3D0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BC3D4: bgez        $t2, L_800BC3EC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BC3D8: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BC3EC;
    }
    // 0x800BC3D8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BC3DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC3E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BC3E4: nop

    // 0x800BC3E8: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800BC3EC:
    // 0x800BC3EC: nop

    // 0x800BC3F0: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BC3F4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800BC3F8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800BC3FC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC400: lw          $t1, 0x10($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X10);
    // 0x800BC404: nop

    // 0x800BC408: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800BC40C: nop

    // 0x800BC410: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BC414: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800BC418: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800BC41C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BC420: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC424: lw          $t7, 0xC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XC);
    // 0x800BC428: nop

    // 0x800BC42C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BC430: nop

    // 0x800BC434: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC438: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800BC43C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800BC440: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800BC444: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BC448: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800BC44C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BC450: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BC454: nop

    // 0x800BC458: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BC45C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800BC460: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800BC464: jal         0x800CADC0
    // 0x800BC468: nop

    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x800BC468: nop

    after_4:
    // 0x800BC46C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800BC470: nop

    // 0x800BC474: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x800BC478: b           L_800BC480
    // 0x800BC47C: nop

        goto L_800BC480;
    // 0x800BC47C: nop

L_800BC480:
    // 0x800BC480: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800BC484: b           L_800BC494
    // 0x800BC488: nop

        goto L_800BC494;
    // 0x800BC488: nop

    // 0x800BC48C: b           L_800BC494
    // 0x800BC490: nop

        goto L_800BC494;
    // 0x800BC490: nop

L_800BC494:
    // 0x800BC494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BC49C: jr          $ra
    // 0x800BC4A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800BC4A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006BB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BB68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BB6C: nop

    // 0x8006BB70: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BB74: nop

    // 0x8006BB78: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006BB7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BB80: jr          $ra
    // 0x8006BB84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BB84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BB88: jr          $ra
    // 0x8006BB8C: nop

    return;
    // 0x8006BB8C: nop

    // 0x8006BB90: jr          $ra
    // 0x8006BB94: nop

    return;
    // 0x8006BB94: nop

;}
RECOMP_FUNC void func_8008D9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D9E4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008D9E8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D9EC: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D9F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008D9F4: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8008D9F8: lwc1        $f9, -0xA00($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XA00);
    // 0x8008D9FC: lwc1        $f8, -0x9FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X9FC);
    // 0x8008DA00: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008DA04: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008DA08: nop

    // 0x8008DA0C: bc1f        L_8008DB5C
    if (!c1cs) {
        // 0x8008DA10: nop
    
            goto L_8008DB5C;
    }
    // 0x8008DA10: nop

    // 0x8008DA14: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008DA18: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008DA1C: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008DA20: beq         $t7, $zero, L_8008DB10
    if (ctx->r15 == 0) {
        // 0x8008DA24: sw          $t7, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r15;
            goto L_8008DB10;
    }
    // 0x8008DA24: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_8008DA28:
    // 0x8008DA28: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008DA2C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8008DA30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008DA34: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008DA38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008DA3C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008DA40: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8008DA44: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008DA48: nop

    // 0x8008DA4C: lwc1        $f6, 0xE8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8008DA50: nop

    // 0x8008DA54: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008DA58: sub.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d - ctx->f4.d;
    // 0x8008DA5C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8008DA60: swc1        $f10, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f10.u32l;
    // 0x8008DA64: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008DA68: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008DA6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008DA70: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008DA74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008DA78: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008DA7C: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8008DA80: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008DA84: nop

    // 0x8008DA88: lwc1        $f16, 0xF0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8008DA8C: nop

    // 0x8008DA90: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8008DA94: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x8008DA98: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8008DA9C: swc1        $f18, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f18.u32l;
    // 0x8008DAA0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008DAA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008DAA8: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8008DAAC: lwc1        $f11, -0x9F8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X9F8);
    // 0x8008DAB0: lwc1        $f10, -0x9F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X9F4);
    // 0x8008DAB4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8008DAB8: nop

    // 0x8008DABC: div.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x8008DAC0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008DAC4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008DAC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008DACC: nop

    // 0x8008DAD0: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x8008DAD4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8008DAD8: swc1        $f12, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f12.u32l;
    // 0x8008DADC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008DAE0: nop

    // 0x8008DAE4: swc1        $f12, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f12.u32l;
    // 0x8008DAE8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008DAEC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008DAF0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008DAF4: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8008DAF8: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x8008DAFC: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x8008DB00: beq         $at, $zero, L_8008DB10
    if (ctx->r1 == 0) {
        // 0x8008DB04: sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
            goto L_8008DB10;
    }
    // 0x8008DB04: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x8008DB08: bne         $t5, $zero, L_8008DA28
    if (ctx->r13 != 0) {
        // 0x8008DB0C: nop
    
            goto L_8008DA28;
    }
    // 0x8008DB0C: nop

L_8008DB10:
    // 0x8008DB10: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008DB14: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008DB18: nop

    // 0x8008DB1C: lwc1        $f12, 0xF4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XF4);
    // 0x8008DB20: nop

    // 0x8008DB24: swc1        $f12, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->f12.u32l;
    // 0x8008DB28: swc1        $f12, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->f12.u32l;
    // 0x8008DB2C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008DB30: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008DB34: nop

    // 0x8008DB38: lwc1        $f8, 0xE8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8008DB3C: nop

    // 0x8008DB40: swc1        $f8, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f8.u32l;
    // 0x8008DB44: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008DB48: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008DB4C: nop

    // 0x8008DB50: lwc1        $f16, 0xF0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8008DB54: b           L_8008DB64
    // 0x8008DB58: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
        goto L_8008DB64;
    // 0x8008DB58: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
L_8008DB5C:
    // 0x8008DB5C: b           L_8008DB74
    // 0x8008DB60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8008DB74;
    // 0x8008DB60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8008DB64:
    // 0x8008DB64: b           L_8008DB74
    // 0x8008DB68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008DB74;
    // 0x8008DB68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8008DB6C: b           L_8008DB74
    // 0x8008DB70: nop

        goto L_8008DB74;
    // 0x8008DB70: nop

L_8008DB74:
    // 0x8008DB74: jr          $ra
    // 0x8008DB78: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008DB78: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80068CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068CE0: jal         0x80061488
    // 0x80068CE4: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068CE4: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    after_0:
    // 0x80068CE8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068CEC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068CF0: b           L_80068D00
    // 0x80068CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068D00;
    // 0x80068CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068CF8: b           L_80068D00
    // 0x80068CFC: nop

        goto L_80068D00;
    // 0x80068CFC: nop

L_80068D00:
    // 0x80068D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068D08: jr          $ra
    // 0x80068D0C: nop

    return;
    // 0x80068D0C: nop

;}
RECOMP_FUNC void func_800688F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800688F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800688FC: nop

    // 0x80068900: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x80068904: nop

    // 0x80068908: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006890C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068910: jr          $ra
    // 0x80068914: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068914: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068918: jr          $ra
    // 0x8006891C: nop

    return;
    // 0x8006891C: nop

    // 0x80068920: jr          $ra
    // 0x80068924: nop

    return;
    // 0x80068924: nop

;}
RECOMP_FUNC void func_80076308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007630C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076310: jal         0x80061488
    // 0x80076314: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076314: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    after_0:
    // 0x80076318: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007631C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076320: b           L_80076330
    // 0x80076324: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076330;
    // 0x80076324: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076328: b           L_80076330
    // 0x8007632C: nop

        goto L_80076330;
    // 0x8007632C: nop

L_80076330:
    // 0x80076330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076338: jr          $ra
    // 0x8007633C: nop

    return;
    // 0x8007633C: nop

;}
RECOMP_FUNC void func_800527B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800527B4: jr          $ra
    // 0x800527B8: nop

    return;
    // 0x800527B8: nop

    // 0x800527BC: jr          $ra
    // 0x800527C0: nop

    return;
    // 0x800527C0: nop

;}
RECOMP_FUNC void func_80081204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008120C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80081210: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80081214: nop

    // 0x80081218: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008121C: nop

    // 0x80081220: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80081224: jal         0x800B2748
    // 0x80081228: addiu       $a1, $t7, 0x4
    ctx->r5 = ADD32(ctx->r15, 0X4);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x80081228: addiu       $a1, $t7, 0x4
    ctx->r5 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x8008122C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80081230: nop

    // 0x80081234: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80081238: nop

    // 0x8008123C: sh          $v0, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r2;
    // 0x80081240: b           L_80081250
    // 0x80081244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081250;
    // 0x80081244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80081248: b           L_80081250
    // 0x8008124C: nop

        goto L_80081250;
    // 0x8008124C: nop

L_80081250:
    // 0x80081250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081258: jr          $ra
    // 0x8008125C: nop

    return;
    // 0x8008125C: nop

;}
RECOMP_FUNC void func_80076C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076C18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076C1C: nop

    // 0x80076C20: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076C24: nop

    // 0x80076C28: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80076C2C: jr          $ra
    // 0x80076C30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076C30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076C34: jr          $ra
    // 0x80076C38: nop

    return;
    // 0x80076C38: nop

    // 0x80076C3C: jr          $ra
    // 0x80076C40: nop

    return;
    // 0x80076C40: nop

;}
RECOMP_FUNC void func_8006C820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C828: jal         0x8005F064
    // 0x8006C82C: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C82C: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_0:
    // 0x8006C830: b           L_8006C840
    // 0x8006C834: nop

        goto L_8006C840;
    // 0x8006C834: nop

    // 0x8006C838: b           L_8006C840
    // 0x8006C83C: nop

        goto L_8006C840;
    // 0x8006C83C: nop

L_8006C840:
    // 0x8006C840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C848: jr          $ra
    // 0x8006C84C: nop

    return;
    // 0x8006C84C: nop

;}
RECOMP_FUNC void func_800065BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800065BC: addiu       $sp, $sp, -0x1D8
    ctx->r29 = ADD32(ctx->r29, -0X1D8);
    // 0x800065C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800065C4: sw          $a0, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r4;
    // 0x800065C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800065CC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800065D0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800065D4: lw          $t6, 0x1D8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D8);
    // 0x800065D8: nop

    // 0x800065DC: sw          $t6, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r14;
    // 0x800065E0: lw          $t7, 0x1B8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1B8);
    // 0x800065E4: nop

    // 0x800065E8: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800065EC: nop

    // 0x800065F0: sw          $t8, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r24;
    // 0x800065F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800065F8: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800065FC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80006600: addiu       $t9, $t9, -0x5B58
    ctx->r25 = ADD32(ctx->r25, -0X5B58);
    // 0x80006604: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x80006608: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000660C: lwc1        $f6, 0x6194($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80006610: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80006614: addiu       $t0, $t0, -0x5B58
    ctx->r8 = ADD32(ctx->r8, -0X5B58);
    // 0x80006618: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8000661C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80006620: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80006624: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80006628: addiu       $t1, $t1, -0x5B58
    ctx->r9 = ADD32(ctx->r9, -0X5B58);
    // 0x8000662C: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x80006630: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80006634: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80006638: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8000663C: addiu       $t2, $t2, -0x5B58
    ctx->r10 = ADD32(ctx->r10, -0X5B58);
    // 0x80006640: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x80006644: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80006648: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8000664C: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x80006650: jal         0x800AC0A4
    // 0x80006654: addiu       $a3, $zero, 0xE1
    ctx->r7 = ADD32(0, 0XE1);
    func_800AC0A4(rdram, ctx);
        goto after_0;
    // 0x80006654: addiu       $a3, $zero, 0xE1
    ctx->r7 = ADD32(0, 0XE1);
    after_0:
    // 0x80006658: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000665C: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80006660: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80006664: nop

    // 0x80006668: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8000666C: beq         $t5, $zero, L_800068BC
    if (ctx->r13 == 0) {
        // 0x80006670: nop
    
            goto L_800068BC;
    }
    // 0x80006670: nop

    // 0x80006674: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80006678: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x8000667C: addiu       $t7, $t6, 0x1080
    ctx->r15 = ADD32(ctx->r14, 0X1080);
    // 0x80006680: sw          $t7, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r15;
    // 0x80006684: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80006688: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000668C: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006690: nop

    // 0x80006694: swc1        $f16, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f16.u32l;
    // 0x80006698: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8000669C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800066A0: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066A4: nop

    // 0x800066A8: swc1        $f18, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f18.u32l;
    // 0x800066AC: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800066B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800066B8: lwc1        $f4, 0xE8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x800066BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800066C0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800066C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800066C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800066CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800066D0: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x800066D4: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
    // 0x800066D8: swc1        $f20, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f20.u32l;
    // 0x800066DC: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066E0: nop

    // 0x800066E4: swc1        $f20, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f20.u32l;
    // 0x800066E8: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066EC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800066F0: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800066F4: nop

    // 0x800066F8: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800066FC: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x80006700: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006704: nop

    // 0x80006708: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x8000670C: nop

    // 0x80006710: ori         $t7, $t6, 0x810
    ctx->r15 = ctx->r14 | 0X810;
    // 0x80006714: sw          $t7, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r15;
    // 0x80006718: addiu       $t8, $sp, 0x40
    ctx->r24 = ADD32(ctx->r29, 0X40);
    // 0x8000671C: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x80006720: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006724: jal         0x80099E2C
    // 0x80006728: nop

    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x80006728: nop

    after_1:
    // 0x8000672C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80006730: nop

    // 0x80006734: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
    // 0x80006738: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    // 0x8000673C: swc1        $f4, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f4.u32l;
    // 0x80006740: sw          $zero, 0x148($sp)
    MEM_W(0X148, ctx->r29) = 0;
    // 0x80006744: sw          $zero, 0x144($sp)
    MEM_W(0X144, ctx->r29) = 0;
    // 0x80006748: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000674C: nop

    // 0x80006750: swc1        $f6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f6.u32l;
    // 0x80006754: swc1        $f6, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f6.u32l;
    // 0x80006758: swc1        $f6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f6.u32l;
    // 0x8000675C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006764: nop

    // 0x80006768: swc1        $f8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f8.u32l;
    // 0x8000676C: swc1        $f8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f8.u32l;
    // 0x80006770: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80006774: sh          $t9, 0x15E($sp)
    MEM_H(0X15E, ctx->r29) = ctx->r25;
    // 0x80006778: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000677C: sh          $t0, 0x156($sp)
    MEM_H(0X156, ctx->r29) = ctx->r8;
    // 0x80006780: addiu       $t1, $zero, 0x814
    ctx->r9 = ADD32(0, 0X814);
    // 0x80006784: sw          $t1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r9;
    // 0x80006788: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8000678C: sh          $t3, 0x154($sp)
    MEM_H(0X154, ctx->r29) = ctx->r11;
    // 0x80006790: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006794: nop

    // 0x80006798: lw          $t2, 0xC8($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC8);
    // 0x8000679C: nop

    // 0x800067A0: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800067A4: sw          $t6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r14;
    // 0x800067A8: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x800067AC: sh          $t7, 0x140($sp)
    MEM_H(0X140, ctx->r29) = ctx->r15;
    // 0x800067B0: addiu       $t5, $zero, 0xB0
    ctx->r13 = ADD32(0, 0XB0);
    // 0x800067B4: sh          $t5, 0x142($sp)
    MEM_H(0X142, ctx->r29) = ctx->r13;
    // 0x800067B8: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800067BC: nop

    // 0x800067C0: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x800067C4: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x800067C8: nop

    // 0x800067CC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800067D0: mflo        $a0
    ctx->r4 = lo;
    // 0x800067D4: jal         0x800BC6EC
    // 0x800067D8: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800067D8: nop

    after_2:
    // 0x800067DC: sw          $v0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r2;
    // 0x800067E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800067E4: addiu       $t1, $t1, -0x44B8
    ctx->r9 = ADD32(ctx->r9, -0X44B8);
    // 0x800067E8: sw          $t1, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r9;
    // 0x800067EC: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x800067F0: nop

    // 0x800067F4: sw          $t3, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r11;
    // 0x800067F8: lh          $t4, 0x140($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X140);
    // 0x800067FC: lh          $t2, 0x142($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X142);
    // 0x80006800: sw          $zero, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = 0;
    // 0x80006804: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006808: mflo        $t6
    ctx->r14 = lo;
    // 0x8000680C: blez        $t6, L_80006850
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80006810: nop
    
            goto L_80006850;
    }
    // 0x80006810: nop

L_80006814:
    // 0x80006814: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x80006818: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x8000681C: nop

    // 0x80006820: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x80006824: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80006828: lh          $t1, 0x140($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X140);
    // 0x8000682C: lh          $t3, 0x142($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X142);
    // 0x80006830: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x80006834: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006838: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000683C: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x80006840: mflo        $t4
    ctx->r12 = lo;
    // 0x80006844: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80006848: bne         $at, $zero, L_80006814
    if (ctx->r1 != 0) {
        // 0x8000684C: nop
    
            goto L_80006814;
    }
    // 0x8000684C: nop

L_80006850:
    // 0x80006850: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80006854: lw          $t2, -0x6080($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6080);
    // 0x80006858: nop

    // 0x8000685C: bne         $t2, $zero, L_8000688C
    if (ctx->r10 != 0) {
        // 0x80006860: nop
    
            goto L_8000688C;
    }
    // 0x80006860: nop

    // 0x80006864: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80006868: addiu       $t6, $t6, -0x66B0
    ctx->r14 = ADD32(ctx->r14, -0X66B0);
    // 0x8000686C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006870: sw          $t6, -0x6080($at)
    MEM_W(-0X6080, ctx->r1) = ctx->r14;
    // 0x80006874: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006878: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000687C: lw          $a1, 0x648($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X648);
    // 0x80006880: lw          $a0, -0x6080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6080);
    // 0x80006884: jal         0x800BCFCC
    // 0x80006888: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x80006888: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    after_3:
L_8000688C:
    // 0x8000688C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80006890: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80006894: nop

    // 0x80006898: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8000689C: sw          $zero, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = 0;
    // 0x800068A0: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800068A4: lw          $a1, 0x1C4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C4);
    // 0x800068A8: jal         0x800062C0
    // 0x800068AC: nop

    func_800062C0(rdram, ctx);
        goto after_4;
    // 0x800068AC: nop

    after_4:
    // 0x800068B0: sw          $zero, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = 0;
    // 0x800068B4: b           L_80006A1C
    // 0x800068B8: sw          $zero, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = 0;
        goto L_80006A1C;
    // 0x800068B8: sw          $zero, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = 0;
L_800068BC:
    // 0x800068BC: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x800068C0: nop

    // 0x800068C4: addiu       $t8, $t5, 0x7FFF
    ctx->r24 = ADD32(ctx->r13, 0X7FFF);
    // 0x800068C8: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x800068CC: nop

    // 0x800068D0: blez        $t8, L_80006954
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800068D4: nop
    
            goto L_80006954;
    }
    // 0x800068D4: nop

L_800068D8:
    // 0x800068D8: lw          $t9, 0x1B8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B8);
    // 0x800068DC: addiu       $a1, $sp, 0x1B0
    ctx->r5 = ADD32(ctx->r29, 0X1B0);
    // 0x800068E0: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x800068E4: jal         0x800C143C
    // 0x800068E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_5;
    // 0x800068E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800068EC: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800068F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800068F4: lh          $t3, 0x0($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X0);
    // 0x800068F8: nop

    // 0x800068FC: bne         $t3, $at, L_80006938
    if (ctx->r11 != ctx->r1) {
        // 0x80006900: nop
    
            goto L_80006938;
    }
    // 0x80006900: nop

    // 0x80006904: b           L_8000690C
    // 0x80006908: nop

        goto L_8000690C;
    // 0x80006908: nop

L_8000690C:
    // 0x8000690C: jal         0x80099520
    // 0x80006910: nop

    func_80099520(rdram, ctx);
        goto after_6;
    // 0x80006910: nop

    after_6:
    // 0x80006914: lw          $t0, 0x1B4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1B4);
    // 0x80006918: nop

    // 0x8000691C: addiu       $t4, $t0, 0x7FFF
    ctx->r12 = ADD32(ctx->r8, 0X7FFF);
    // 0x80006920: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x80006924: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x80006928: addiu       $t2, $t4, -0x1
    ctx->r10 = ADD32(ctx->r12, -0X1);
    // 0x8000692C: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
    // 0x80006930: b           L_80006938
    // 0x80006934: nop

        goto L_80006938;
    // 0x80006934: nop

L_80006938:
    // 0x80006938: lw          $t6, 0x1B4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1B4);
    // 0x8000693C: nop

    // 0x80006940: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x80006944: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80006948: nop

    // 0x8000694C: bgtz        $t7, L_800068D8
    if (SIGNED(ctx->r15) > 0) {
        // 0x80006950: nop
    
            goto L_800068D8;
    }
    // 0x80006950: nop

L_80006954:
    // 0x80006954: jal         0x80098820
    // 0x80006958: nop

    func_80098820(rdram, ctx);
        goto after_7;
    // 0x80006958: nop

    after_7:
    // 0x8000695C: jal         0x80098868
    // 0x80006960: nop

    func_80098868(rdram, ctx);
        goto after_8;
    // 0x80006960: nop

    after_8:
    // 0x80006964: sw          $zero, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = 0;
L_80006968:
    // 0x80006968: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x8000696C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80006970: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80006974: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x80006978: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000697C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x80006980: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80006984: addiu       $t9, $t9, -0x6658
    ctx->r25 = ADD32(ctx->r25, -0X6658);
    // 0x80006988: jal         0x80099E2C
    // 0x8000698C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    func_80099E2C(rdram, ctx);
        goto after_9;
    // 0x8000698C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x80006990: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x80006994: nop

    // 0x80006998: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8000699C: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x800069A0: bne         $at, $zero, L_80006968
    if (ctx->r1 != 0) {
        // 0x800069A4: sw          $t3, 0x1D4($sp)
        MEM_W(0X1D4, ctx->r29) = ctx->r11;
            goto L_80006968;
    }
    // 0x800069A4: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800069A8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800069AC: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800069B0: jal         0x800A6670
    // 0x800069B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_10;
    // 0x800069B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x800069B8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800069BC: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800069C0: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x800069C4: jal         0x800A6670
    // 0x800069C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_11;
    // 0x800069C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_11:
    // 0x800069CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x800069D0: jal         0x80005124
    // 0x800069D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80005124(rdram, ctx);
        goto after_12;
    // 0x800069D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_12:
    // 0x800069D8: sw          $v0, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r2;
    // 0x800069DC: lw          $t4, 0x1BC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1BC);
    // 0x800069E0: nop

    // 0x800069E4: bne         $t4, $zero, L_800069F8
    if (ctx->r12 != 0) {
        // 0x800069E8: nop
    
            goto L_800069F8;
    }
    // 0x800069E8: nop

    // 0x800069EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800069F0: jal         0x800A6F20
    // 0x800069F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800A6F20(rdram, ctx);
        goto after_13;
    // 0x800069F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
L_800069F8:
    // 0x800069F8: jal         0x8008CE90
    // 0x800069FC: nop

    func_8008CE90(rdram, ctx);
        goto after_14;
    // 0x800069FC: nop

    after_14:
    // 0x80006A00: lw          $t2, 0x1B8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B8);
    // 0x80006A04: nop

    // 0x80006A08: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80006A0C: jal         0x800C13B8
    // 0x80006A10: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_15;
    // 0x80006A10: nop

    after_15:
    // 0x80006A14: jal         0x80098820
    // 0x80006A18: nop

    func_80098820(rdram, ctx);
        goto after_16;
    // 0x80006A18: nop

    after_16:
L_80006A1C:
    // 0x80006A1C: sw          $zero, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = 0;
    // 0x80006A20: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80006A24: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80006A28: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x80006A2C: nop

    // 0x80006A30: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80006A34: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x80006A38: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x80006A3C: nop

    // 0x80006A40: bne         $t5, $zero, L_80007580
    if (ctx->r13 != 0) {
        // 0x80006A44: nop
    
            goto L_80007580;
    }
    // 0x80006A44: nop

L_80006A48:
    // 0x80006A48: lw          $t8, 0x1B8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B8);
    // 0x80006A4C: addiu       $a1, $sp, 0x1B0
    ctx->r5 = ADD32(ctx->r29, 0X1B0);
    // 0x80006A50: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80006A54: jal         0x800C143C
    // 0x80006A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_17;
    // 0x80006A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80006A5C: lw          $t9, 0x1B0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B0);
    // 0x80006A60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006A64: lh          $s0, 0x0($t9)
    ctx->r16 = MEM_H(ctx->r25, 0X0);
    // 0x80006A68: nop

    // 0x80006A6C: beq         $s0, $at, L_80006A94
    if (ctx->r16 == ctx->r1) {
        // 0x80006A70: nop
    
            goto L_80006A94;
    }
    // 0x80006A70: nop

    // 0x80006A74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006A78: beq         $s0, $at, L_80007368
    if (ctx->r16 == ctx->r1) {
        // 0x80006A7C: nop
    
            goto L_80007368;
    }
    // 0x80006A7C: nop

    // 0x80006A80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80006A84: beq         $s0, $at, L_80007558
    if (ctx->r16 == ctx->r1) {
        // 0x80006A88: nop
    
            goto L_80007558;
    }
    // 0x80006A88: nop

    // 0x80006A8C: b           L_80007568
    // 0x80006A90: nop

        goto L_80007568;
    // 0x80006A90: nop

L_80006A94:
    // 0x80006A94: lw          $t1, 0x1B4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B4);
    // 0x80006A98: nop

    // 0x80006A9C: addiu       $t3, $t1, 0x7FFF
    ctx->r11 = ADD32(ctx->r9, 0X7FFF);
    // 0x80006AA0: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x80006AA4: nop

    // 0x80006AA8: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80006AAC: beq         $at, $zero, L_80007360
    if (ctx->r1 == 0) {
        // 0x80006AB0: nop
    
            goto L_80007360;
    }
    // 0x80006AB0: nop

    // 0x80006AB4: jal         0x80099768
    // 0x80006AB8: nop

    func_80099768(rdram, ctx);
        goto after_18;
    // 0x80006AB8: nop

    after_18:
    // 0x80006ABC: jal         0x800AFB28
    // 0x80006AC0: nop

    func_800AFB28(rdram, ctx);
        goto after_19;
    // 0x80006AC0: nop

    after_19:
    // 0x80006AC4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80006AC8: lw          $t2, -0x4CC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CC4);
    // 0x80006ACC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80006AD0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80006AD4: lw          $t4, -0x4CCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CCC);
    // 0x80006AD8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80006ADC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80006AE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006AE4: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80006AE8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80006AEC: jal         0x800BE510
    // 0x80006AF0: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    func_800BE510(rdram, ctx);
        goto after_20;
    // 0x80006AF0: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_20:
    // 0x80006AF4: jal         0x80032604
    // 0x80006AF8: nop

    func_80032604(rdram, ctx);
        goto after_21;
    // 0x80006AF8: nop

    after_21:
    // 0x80006AFC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80006B00: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80006B04: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80006B08: nop

    // 0x80006B0C: andi        $t0, $t7, 0x8000
    ctx->r8 = ctx->r15 & 0X8000;
    // 0x80006B10: beq         $t0, $zero, L_800072D0
    if (ctx->r8 == 0) {
        // 0x80006B14: nop
    
            goto L_800072D0;
    }
    // 0x80006B14: nop

    // 0x80006B18: sw          $zero, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = 0;
    // 0x80006B1C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80006B20: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80006B24: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80006B28: lhu         $t9, 0xE74($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE74);
    // 0x80006B2C: lhu         $t8, 0x8($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X8);
    // 0x80006B30: nop

    // 0x80006B34: and         $t1, $t8, $t9
    ctx->r9 = ctx->r24 & ctx->r25;
    // 0x80006B38: bne         $t1, $zero, L_80006B58
    if (ctx->r9 != 0) {
        // 0x80006B3C: nop
    
            goto L_80006B58;
    }
    // 0x80006B3C: nop

    // 0x80006B40: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80006B44: lhu         $t3, 0xEEC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XEEC);
    // 0x80006B48: nop

    // 0x80006B4C: and         $t4, $t8, $t3
    ctx->r12 = ctx->r24 & ctx->r11;
    // 0x80006B50: beq         $t4, $zero, L_80006B78
    if (ctx->r12 == 0) {
        // 0x80006B54: nop
    
            goto L_80006B78;
    }
    // 0x80006B54: nop

L_80006B58:
    // 0x80006B58: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006B5C: nop

    // 0x80006B60: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x80006B64: sw          $t6, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r14;
    // 0x80006B68: lw          $t7, 0x1C0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006B6C: nop

    // 0x80006B70: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80006B74: sw          $t0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r8;
L_80006B78:
    // 0x80006B78: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80006B7C: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80006B80: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80006B84: lhu         $t1, 0xE68($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XE68);
    // 0x80006B88: lhu         $t9, 0x8($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X8);
    // 0x80006B8C: nop

    // 0x80006B90: and         $t8, $t9, $t1
    ctx->r24 = ctx->r25 & ctx->r9;
    // 0x80006B94: bne         $t8, $zero, L_80006BB4
    if (ctx->r24 != 0) {
        // 0x80006B98: nop
    
            goto L_80006BB4;
    }
    // 0x80006B98: nop

    // 0x80006B9C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80006BA0: lhu         $t3, 0xEC0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XEC0);
    // 0x80006BA4: nop

    // 0x80006BA8: and         $t4, $t9, $t3
    ctx->r12 = ctx->r25 & ctx->r11;
    // 0x80006BAC: beq         $t4, $zero, L_80006BD4
    if (ctx->r12 == 0) {
        // 0x80006BB0: nop
    
            goto L_80006BD4;
    }
    // 0x80006BB0: nop

L_80006BB4:
    // 0x80006BB4: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006BB8: nop

    // 0x80006BBC: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x80006BC0: sw          $t6, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r14;
    // 0x80006BC4: lw          $t7, 0x1C0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006BC8: nop

    // 0x80006BCC: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80006BD0: sw          $t0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r8;
L_80006BD4:
    // 0x80006BD4: lw          $t5, 0x1C4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006BD8: nop

    // 0x80006BDC: bgez        $t5, L_80006BE8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80006BE0: nop
    
            goto L_80006BE8;
    }
    // 0x80006BE0: nop

    // 0x80006BE4: sw          $zero, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = 0;
L_80006BE8:
    // 0x80006BE8: lw          $t1, 0x1C4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006BEC: nop

    // 0x80006BF0: slti        $at, $t1, 0x2A
    ctx->r1 = SIGNED(ctx->r9) < 0X2A ? 1 : 0;
    // 0x80006BF4: bne         $at, $zero, L_80006C04
    if (ctx->r1 != 0) {
        // 0x80006BF8: nop
    
            goto L_80006C04;
    }
    // 0x80006BF8: nop

    // 0x80006BFC: addiu       $t8, $zero, 0x29
    ctx->r24 = ADD32(0, 0X29);
    // 0x80006C00: sw          $t8, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r24;
L_80006C04:
    // 0x80006C04: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80006C08: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80006C0C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80006C10: lhu         $t4, 0xFF4($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XFF4);
    // 0x80006C14: lhu         $t3, 0x8($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X8);
    // 0x80006C18: nop

    // 0x80006C1C: and         $t2, $t3, $t4
    ctx->r10 = ctx->r11 & ctx->r12;
    // 0x80006C20: beq         $t2, $zero, L_80006C58
    if (ctx->r10 == 0) {
        // 0x80006C24: nop
    
            goto L_80006C58;
    }
    // 0x80006C24: nop

    // 0x80006C28: lw          $t7, 0x1C4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006C2C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80006C30: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x80006C34: addu        $t5, $t6, $t0
    ctx->r13 = ADD32(ctx->r14, ctx->r8);
    // 0x80006C38: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80006C3C: nop

    // 0x80006C40: addiu       $t8, $t1, 0x1
    ctx->r24 = ADD32(ctx->r9, 0X1);
    // 0x80006C44: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
    // 0x80006C48: lw          $t9, 0x1C0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006C4C: nop

    // 0x80006C50: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80006C54: sw          $t3, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r11;
L_80006C58:
    // 0x80006C58: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80006C5C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80006C60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80006C64: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x80006C68: lhu         $t2, 0x8($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X8);
    // 0x80006C6C: nop

    // 0x80006C70: and         $t6, $t2, $t7
    ctx->r14 = ctx->r10 & ctx->r15;
    // 0x80006C74: beq         $t6, $zero, L_80006CAC
    if (ctx->r14 == 0) {
        // 0x80006C78: nop
    
            goto L_80006CAC;
    }
    // 0x80006C78: nop

    // 0x80006C7C: lw          $t1, 0x1C4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006C80: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80006C84: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x80006C88: addu        $t5, $t0, $t8
    ctx->r13 = ADD32(ctx->r8, ctx->r24);
    // 0x80006C8C: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x80006C90: nop

    // 0x80006C94: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80006C98: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
    // 0x80006C9C: lw          $t4, 0x1C0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006CA0: nop

    // 0x80006CA4: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80006CA8: sw          $t2, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r10;
L_80006CAC:
    // 0x80006CAC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80006CB0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80006CB4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80006CB8: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x80006CBC: lhu         $t6, 0x8($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X8);
    // 0x80006CC0: nop

    // 0x80006CC4: and         $t0, $t6, $t1
    ctx->r8 = ctx->r14 & ctx->r9;
    // 0x80006CC8: beq         $t0, $zero, L_80006D00
    if (ctx->r8 == 0) {
        // 0x80006CCC: nop
    
            goto L_80006D00;
    }
    // 0x80006CCC: nop

    // 0x80006CD0: lw          $t9, 0x1C4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006CD4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80006CD8: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x80006CDC: addu        $t5, $t8, $t3
    ctx->r13 = ADD32(ctx->r24, ctx->r11);
    // 0x80006CE0: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x80006CE4: nop

    // 0x80006CE8: addiu       $t2, $t4, 0xA
    ctx->r10 = ADD32(ctx->r12, 0XA);
    // 0x80006CEC: sh          $t2, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r10;
    // 0x80006CF0: lw          $t7, 0x1C0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006CF4: nop

    // 0x80006CF8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80006CFC: sw          $t6, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r14;
L_80006D00:
    // 0x80006D00: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80006D04: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x80006D08: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80006D0C: lhu         $t9, 0x1260($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1260);
    // 0x80006D10: lhu         $t0, 0x8($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X8);
    // 0x80006D14: nop

    // 0x80006D18: and         $t8, $t0, $t9
    ctx->r24 = ctx->r8 & ctx->r25;
    // 0x80006D1C: beq         $t8, $zero, L_80006D54
    if (ctx->r24 == 0) {
        // 0x80006D20: nop
    
            goto L_80006D54;
    }
    // 0x80006D20: nop

    // 0x80006D24: lw          $t4, 0x1C4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006D28: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80006D2C: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x80006D30: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80006D34: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80006D38: nop

    // 0x80006D3C: addiu       $t6, $t7, -0xA
    ctx->r14 = ADD32(ctx->r15, -0XA);
    // 0x80006D40: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
    // 0x80006D44: lw          $t1, 0x1C0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006D48: nop

    // 0x80006D4C: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80006D50: sw          $t0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r8;
L_80006D54:
    // 0x80006D54: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80006D58: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80006D5C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80006D60: lhu         $t4, 0x126C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X126C);
    // 0x80006D64: lhu         $t8, 0x8($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X8);
    // 0x80006D68: nop

    // 0x80006D6C: and         $t3, $t8, $t4
    ctx->r11 = ctx->r24 & ctx->r12;
    // 0x80006D70: beq         $t3, $zero, L_80006DA8
    if (ctx->r11 == 0) {
        // 0x80006D74: nop
    
            goto L_80006DA8;
    }
    // 0x80006D74: nop

    // 0x80006D78: lw          $t7, 0x1C4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006D7C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80006D80: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80006D84: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x80006D88: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80006D8C: nop

    // 0x80006D90: addiu       $t0, $t1, 0x64
    ctx->r8 = ADD32(ctx->r9, 0X64);
    // 0x80006D94: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    // 0x80006D98: lw          $t9, 0x1C0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006D9C: nop

    // 0x80006DA0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80006DA4: sw          $t8, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r24;
L_80006DA8:
    // 0x80006DA8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80006DAC: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80006DB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80006DB4: lhu         $t7, 0x11AC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X11AC);
    // 0x80006DB8: lhu         $t3, 0x8($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X8);
    // 0x80006DBC: nop

    // 0x80006DC0: and         $t2, $t3, $t7
    ctx->r10 = ctx->r11 & ctx->r15;
    // 0x80006DC4: beq         $t2, $zero, L_80006DFC
    if (ctx->r10 == 0) {
        // 0x80006DC8: nop
    
            goto L_80006DFC;
    }
    // 0x80006DC8: nop

    // 0x80006DCC: lw          $t1, 0x1C4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006DD0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80006DD4: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x80006DD8: addu        $t5, $t6, $t0
    ctx->r13 = ADD32(ctx->r14, ctx->r8);
    // 0x80006DDC: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x80006DE0: nop

    // 0x80006DE4: addiu       $t8, $t9, -0x64
    ctx->r24 = ADD32(ctx->r25, -0X64);
    // 0x80006DE8: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
    // 0x80006DEC: lw          $t4, 0x1C0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006DF0: nop

    // 0x80006DF4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80006DF8: sw          $t3, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r11;
L_80006DFC:
    // 0x80006DFC: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E00: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E04: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x80006E08: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x80006E0C: lh          $t0, 0x0($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X0);
    // 0x80006E10: nop

    // 0x80006E14: bgez        $t0, L_80006E30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80006E18: nop
    
            goto L_80006E30;
    }
    // 0x80006E18: nop

    // 0x80006E1C: lw          $t8, 0x1C4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E20: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E24: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80006E28: addu        $t4, $t9, $t5
    ctx->r12 = ADD32(ctx->r25, ctx->r13);
    // 0x80006E2C: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
L_80006E30:
    // 0x80006E30: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E34: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E38: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x80006E3C: addu        $t1, $t3, $t7
    ctx->r9 = ADD32(ctx->r11, ctx->r15);
    // 0x80006E40: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80006E44: nop

    // 0x80006E48: slti        $at, $t6, 0x3E8
    ctx->r1 = SIGNED(ctx->r14) < 0X3E8 ? 1 : 0;
    // 0x80006E4C: bne         $at, $zero, L_80006E6C
    if (ctx->r1 != 0) {
        // 0x80006E50: nop
    
            goto L_80006E6C;
    }
    // 0x80006E50: nop

    // 0x80006E54: lw          $t9, 0x1C4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E58: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E5C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80006E60: addiu       $t0, $zero, 0x3E7
    ctx->r8 = ADD32(0, 0X3E7);
    // 0x80006E64: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x80006E68: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
L_80006E6C:
    // 0x80006E6C: lw          $t2, 0x1C0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006E70: nop

    // 0x80006E74: beq         $t2, $zero, L_80006E8C
    if (ctx->r10 == 0) {
        // 0x80006E78: nop
    
            goto L_80006E8C;
    }
    // 0x80006E78: nop

    // 0x80006E7C: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006E80: lw          $a1, 0x1C4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E84: jal         0x800062C0
    // 0x80006E88: nop

    func_800062C0(rdram, ctx);
        goto after_22;
    // 0x80006E88: nop

    after_22:
L_80006E8C:
    // 0x80006E8C: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
    // 0x80006E90: sw          $t3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r11;
    // 0x80006E94: jal         0x800C1754
    // 0x80006E98: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_23;
    // 0x80006E98: nop

    after_23:
    // 0x80006E9C: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006EA0: jal         0x8009A14C
    // 0x80006EA4: nop

    func_8009A14C(rdram, ctx);
        goto after_24;
    // 0x80006EA4: nop

    after_24:
    // 0x80006EA8: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006EAC: nop

    // 0x80006EB0: lw          $t1, 0xC0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC0);
    // 0x80006EB4: nop

    // 0x80006EB8: andi        $t6, $t1, 0x8
    ctx->r14 = ctx->r9 & 0X8;
    // 0x80006EBC: bne         $t6, $zero, L_8000726C
    if (ctx->r14 != 0) {
        // 0x80006EC0: nop
    
            goto L_8000726C;
    }
    // 0x80006EC0: nop

    // 0x80006EC4: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006EC8: nop

    // 0x80006ECC: bne         $t9, $zero, L_800070A4
    if (ctx->r25 != 0) {
        // 0x80006ED0: nop
    
            goto L_800070A4;
    }
    // 0x80006ED0: nop

    // 0x80006ED4: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006ED8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80006EDC: lwc1        $f18, 0xE8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x80006EE0: nop

    // 0x80006EE4: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80006EE8: nop

    // 0x80006EEC: bc1f        L_80006FC8
    if (!c1cs) {
        // 0x80006EF0: nop
    
            goto L_80006FC8;
    }
    // 0x80006EF0: nop

    // 0x80006EF4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80006EF8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80006EFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006F00: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80006F04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006F08: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80006F0C: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80006F10: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006F14: nop

    // 0x80006F18: lwc1        $f18, 0xE8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x80006F1C: nop

    // 0x80006F20: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80006F24: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x80006F28: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80006F2C: swc1        $f6, 0xE8($t5)
    MEM_W(0XE8, ctx->r13) = ctx->f6.u32l;
    // 0x80006F30: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80006F34: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80006F38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006F3C: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80006F40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80006F44: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80006F48: mul.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80006F4C: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006F50: nop

    // 0x80006F54: lwc1        $f8, 0xF0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80006F58: nop

    // 0x80006F5C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80006F60: sub.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d - ctx->f10.d;
    // 0x80006F64: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80006F68: swc1        $f16, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f16.u32l;
    // 0x80006F6C: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006F70: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80006F74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006F78: lwc1        $f4, 0xE8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x80006F7C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80006F80: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80006F84: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80006F88: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80006F8C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80006F90: sub.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d - ctx->f10.d;
    // 0x80006F94: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    // 0x80006F98: swc1        $f20, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f20.u32l;
    // 0x80006F9C: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FA0: nop

    // 0x80006FA4: swc1        $f20, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f20.u32l;
    // 0x80006FA8: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FAC: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006FB0: lwc1        $f20, 0xF4($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0XF4);
    // 0x80006FB4: nop

    // 0x80006FB8: swc1        $f20, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f20.u32l;
    // 0x80006FBC: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006FC0: b           L_8000709C
    // 0x80006FC4: swc1        $f20, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f20.u32l;
        goto L_8000709C;
    // 0x80006FC4: swc1        $f20, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f20.u32l;
L_80006FC8:
    // 0x80006FC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80006FCC: lw          $t6, 0x1A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FD0: nop

    // 0x80006FD4: swc1        $f4, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f4.u32l;
    // 0x80006FD8: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FDC: nop

    // 0x80006FE0: lwc1        $f8, 0xF0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x80006FE4: nop

    // 0x80006FE8: swc1        $f8, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f8.u32l;
    // 0x80006FEC: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FF0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80006FF4: lw          $t5, 0xC0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0XC0);
    // 0x80006FF8: nop

    // 0x80006FFC: and         $t0, $t5, $at
    ctx->r8 = ctx->r13 & ctx->r1;
    // 0x80007000: sw          $t0, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r8;
    // 0x80007004: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007008: nop

    // 0x8000700C: lw          $t2, 0xC0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC0);
    // 0x80007010: nop

    // 0x80007014: ori         $t3, $t2, 0x48
    ctx->r11 = ctx->r10 | 0X48;
    // 0x80007018: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x8000701C: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007020: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80007024: lw          $t1, 0xC0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC0);
    // 0x80007028: nop

    // 0x8000702C: and         $t6, $t1, $at
    ctx->r14 = ctx->r9 & ctx->r1;
    // 0x80007030: sw          $t6, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r14;
    // 0x80007034: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007038: nop

    // 0x8000703C: lw          $t5, 0xC0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC0);
    // 0x80007040: nop

    // 0x80007044: ori         $t0, $t5, 0x48
    ctx->r8 = ctx->r13 | 0X48;
    // 0x80007048: sw          $t0, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r8;
    // 0x8000704C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80007054: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007058: nop

    // 0x8000705C: swc1        $f6, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f6.u32l;
    // 0x80007060: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007064: nop

    // 0x80007068: lwc1        $f18, 0xF8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XF8);
    // 0x8000706C: nop

    // 0x80007070: swc1        $f18, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f18.u32l;
    // 0x80007074: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007078: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000707C: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007080: nop

    // 0x80007084: swc1        $f10, 0xF8($t3)
    MEM_W(0XF8, ctx->r11) = ctx->f10.u32l;
    // 0x80007088: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x8000708C: nop

    // 0x80007090: lwc1        $f16, 0xF8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XF8);
    // 0x80007094: nop

    // 0x80007098: swc1        $f16, 0xF4($t4)
    MEM_W(0XF4, ctx->r12) = ctx->f16.u32l;
L_8000709C:
    // 0x8000709C: b           L_8000726C
    // 0x800070A0: nop

        goto L_8000726C;
    // 0x800070A0: nop

L_800070A4:
    // 0x800070A4: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800070A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800070AC: lwc1        $f4, 0xE8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x800070B0: nop

    // 0x800070B4: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800070B8: nop

    // 0x800070BC: bc1t        L_80007198
    if (c1cs) {
        // 0x800070C0: nop
    
            goto L_80007198;
    }
    // 0x800070C0: nop

    // 0x800070C4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800070C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800070CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800070D0: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800070D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800070D8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x800070DC: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800070E0: lw          $t6, 0x1A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A8);
    // 0x800070E4: nop

    // 0x800070E8: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x800070EC: nop

    // 0x800070F0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800070F4: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x800070F8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x800070FC: swc1        $f6, 0xE8($t6)
    MEM_W(0XE8, ctx->r14) = ctx->f6.u32l;
    // 0x80007100: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80007104: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80007108: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000710C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80007110: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80007114: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80007118: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8000711C: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007120: nop

    // 0x80007124: lwc1        $f18, 0xF0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XF0);
    // 0x80007128: nop

    // 0x8000712C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80007130: sub.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d - ctx->f16.d;
    // 0x80007134: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80007138: swc1        $f10, 0xF0($t7)
    MEM_W(0XF0, ctx->r15) = ctx->f10.u32l;
    // 0x8000713C: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007140: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80007144: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80007148: lwc1        $f8, 0xE8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x8000714C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80007150: div.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80007154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80007158: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000715C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80007160: sub.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f4.d - ctx->f16.d;
    // 0x80007164: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x80007168: swc1        $f20, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f20.u32l;
    // 0x8000716C: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007170: nop

    // 0x80007174: swc1        $f20, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->f20.u32l;
    // 0x80007178: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x8000717C: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007180: lwc1        $f20, 0xF4($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x80007184: nop

    // 0x80007188: swc1        $f20, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f20.u32l;
    // 0x8000718C: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007190: b           L_8000726C
    // 0x80007194: swc1        $f20, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f20.u32l;
        goto L_8000726C;
    // 0x80007194: swc1        $f20, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f20.u32l;
L_80007198:
    // 0x80007198: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000719C: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071A0: nop

    // 0x800071A4: swc1        $f8, 0xF0($t3)
    MEM_W(0XF0, ctx->r11) = ctx->f8.u32l;
    // 0x800071A8: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071AC: nop

    // 0x800071B0: lwc1        $f18, 0xF0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800071B4: nop

    // 0x800071B8: swc1        $f18, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f18.u32l;
    // 0x800071BC: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071C0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800071C4: lw          $t6, 0xC0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC0);
    // 0x800071C8: nop

    // 0x800071CC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800071D0: sw          $t7, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r15;
    // 0x800071D4: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071D8: nop

    // 0x800071DC: lw          $t0, 0xC0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC0);
    // 0x800071E0: nop

    // 0x800071E4: ori         $t9, $t0, 0x8
    ctx->r25 = ctx->r8 | 0X8;
    // 0x800071E8: sw          $t9, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r25;
    // 0x800071EC: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800071F0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800071F4: lw          $t2, 0xC0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XC0);
    // 0x800071F8: nop

    // 0x800071FC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80007200: sw          $t3, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r11;
    // 0x80007204: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007208: nop

    // 0x8000720C: lw          $t6, 0xC0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC0);
    // 0x80007210: nop

    // 0x80007214: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80007218: sw          $t7, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r15;
    // 0x8000721C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80007224: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007228: nop

    // 0x8000722C: swc1        $f6, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f6.u32l;
    // 0x80007230: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007234: nop

    // 0x80007238: lwc1        $f4, 0xF8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x8000723C: nop

    // 0x80007240: swc1        $f4, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->f4.u32l;
    // 0x80007244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000724C: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007250: nop

    // 0x80007254: swc1        $f16, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f16.u32l;
    // 0x80007258: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8000725C: nop

    // 0x80007260: lwc1        $f10, 0xF8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x80007264: nop

    // 0x80007268: swc1        $f10, 0xF4($t5)
    MEM_W(0XF4, ctx->r13) = ctx->f10.u32l;
L_8000726C:
    // 0x8000726C: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007270: nop

    // 0x80007274: lwc1        $f12, 0xF0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x80007278: jal         0x800C2780
    // 0x8000727C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_25;
    // 0x8000727C: nop

    after_25:
    // 0x80007280: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007284: nop

    // 0x80007288: lwc1        $f12, 0xEC($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XEC);
    // 0x8000728C: jal         0x800C25B8
    // 0x80007290: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_26;
    // 0x80007290: nop

    after_26:
    // 0x80007294: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007298: nop

    // 0x8000729C: lwc1        $f12, 0xE8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x800072A0: jal         0x800C23E8
    // 0x800072A4: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_27;
    // 0x800072A4: nop

    after_27:
    // 0x800072A8: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x800072AC: jal         0x800997D8
    // 0x800072B0: nop

    func_800997D8(rdram, ctx);
        goto after_28;
    // 0x800072B0: nop

    after_28:
    // 0x800072B4: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800072B8: jal         0x800997D8
    // 0x800072BC: nop

    func_800997D8(rdram, ctx);
        goto after_29;
    // 0x800072BC: nop

    after_29:
    // 0x800072C0: jal         0x800C1A28
    // 0x800072C4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_30;
    // 0x800072C4: nop

    after_30:
    // 0x800072C8: b           L_800072E8
    // 0x800072CC: nop

        goto L_800072E8;
    // 0x800072CC: nop

L_800072D0:
    // 0x800072D0: jal         0x8008D0CC
    // 0x800072D4: nop

    func_8008D0CC(rdram, ctx);
        goto after_31;
    // 0x800072D4: nop

    after_31:
    // 0x800072D8: beq         $v0, $zero, L_800072E8
    if (ctx->r2 == 0) {
        // 0x800072DC: nop
    
            goto L_800072E8;
    }
    // 0x800072DC: nop

    // 0x800072E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800072E4: sw          $t6, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r14;
L_800072E8:
    // 0x800072E8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800072EC: addiu       $a0, $a0, -0x6658
    ctx->r4 = ADD32(ctx->r4, -0X6658);
    // 0x800072F0: jal         0x8000262C
    // 0x800072F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000262C(rdram, ctx);
        goto after_32;
    // 0x800072F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x800072F8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800072FC: jal         0x8009A664
    // 0x80007300: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_33;
    // 0x80007300: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_33:
    // 0x80007304: jal         0x800BE610
    // 0x80007308: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_34;
    // 0x80007308: nop

    after_34:
    // 0x8000730C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80007310: lw          $t7, 0x1B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B4C);
    // 0x80007314: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80007318: lw          $t4, 0x1B44($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B44);
    // 0x8000731C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80007320: jal         0x8009908C
    // 0x80007324: subu        $a1, $t4, $t7
    ctx->r5 = SUB32(ctx->r12, ctx->r15);
    CreateGfxTask(rdram, ctx);
        goto after_35;
    // 0x80007324: subu        $a1, $t4, $t7
    ctx->r5 = SUB32(ctx->r12, ctx->r15);
    after_35:
    // 0x80007328: lw          $t1, 0x1B8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B8);
    // 0x8000732C: nop

    // 0x80007330: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80007334: jal         0x80098D24
    // 0x80007338: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_36;
    // 0x80007338: nop

    after_36:
    // 0x8000733C: jal         0x80099450
    // 0x80007340: nop

    func_80099450(rdram, ctx);
        goto after_37;
    // 0x80007340: nop

    after_37:
    // 0x80007344: lw          $t0, 0x1B4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007348: nop

    // 0x8000734C: addiu       $t9, $t0, 0x7FFF
    ctx->r25 = ADD32(ctx->r8, 0X7FFF);
    // 0x80007350: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x80007354: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x80007358: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8000735C: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
L_80007360:
    // 0x80007360: b           L_80007570
    // 0x80007364: nop

        goto L_80007570;
    // 0x80007364: nop

L_80007368:
    // 0x80007368: jal         0x80099520
    // 0x8000736C: nop

    func_80099520(rdram, ctx);
        goto after_38;
    // 0x8000736C: nop

    after_38:
    // 0x80007370: lw          $t2, 0x1B4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007374: nop

    // 0x80007378: addiu       $t3, $t2, 0x7FFF
    ctx->r11 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000737C: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x80007380: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007384: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x80007388: sw          $t8, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r24;
    // 0x8000738C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80007390: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80007394: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
    // 0x80007398: nop

    // 0x8000739C: andi        $t7, $t4, 0x8000
    ctx->r15 = ctx->r12 & 0X8000;
    // 0x800073A0: beq         $t7, $zero, L_80007550
    if (ctx->r15 == 0) {
        // 0x800073A4: nop
    
            goto L_80007550;
    }
    // 0x800073A4: nop

    // 0x800073A8: lw          $t1, 0x1CC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1CC);
    // 0x800073AC: nop

    // 0x800073B0: bne         $t1, $zero, L_800074C0
    if (ctx->r9 != 0) {
        // 0x800073B4: nop
    
            goto L_800074C0;
    }
    // 0x800073B4: nop

    // 0x800073B8: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x800073BC: nop

    // 0x800073C0: lw          $t5, 0xC0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC0);
    // 0x800073C4: nop

    // 0x800073C8: andi        $t0, $t5, 0x8
    ctx->r8 = ctx->r13 & 0X8;
    // 0x800073CC: beq         $t0, $zero, L_800074B8
    if (ctx->r8 == 0) {
        // 0x800073D0: nop
    
            goto L_800074B8;
    }
    // 0x800073D0: nop

    // 0x800073D4: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800073D8: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x800073DC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800073E0: lhu         $t2, 0x11A4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X11A4);
    // 0x800073E4: lhu         $t8, 0x6($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X6);
    // 0x800073E8: nop

    // 0x800073EC: and         $t6, $t8, $t2
    ctx->r14 = ctx->r24 & ctx->r10;
    // 0x800073F0: bne         $t6, $zero, L_80007410
    if (ctx->r14 != 0) {
        // 0x800073F4: nop
    
            goto L_80007410;
    }
    // 0x800073F4: nop

    // 0x800073F8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800073FC: lhu         $t4, 0x10F2($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X10F2);
    // 0x80007400: nop

    // 0x80007404: and         $t7, $t8, $t4
    ctx->r15 = ctx->r24 & ctx->r12;
    // 0x80007408: beq         $t7, $zero, L_800074B8
    if (ctx->r15 == 0) {
        // 0x8000740C: nop
    
            goto L_800074B8;
    }
    // 0x8000740C: nop

L_80007410:
    // 0x80007410: lw          $t1, 0x1CC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1CC);
    // 0x80007414: nop

    // 0x80007418: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8000741C: sw          $t9, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r25;
    // 0x80007420: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80007424: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007428: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x8000742C: nop

    // 0x80007430: swc1        $f8, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f8.u32l;
    // 0x80007434: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007438: nop

    // 0x8000743C: lwc1        $f18, 0xF0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80007440: nop

    // 0x80007444: swc1        $f18, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f18.u32l;
    // 0x80007448: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x8000744C: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x80007450: lw          $t2, 0xC0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC0);
    // 0x80007454: nop

    // 0x80007458: and         $t6, $t2, $at
    ctx->r14 = ctx->r10 & ctx->r1;
    // 0x8000745C: sw          $t6, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r14;
    // 0x80007460: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007464: nop

    // 0x80007468: lw          $t4, 0xC0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0XC0);
    // 0x8000746C: nop

    // 0x80007470: ori         $t7, $t4, 0x10
    ctx->r15 = ctx->r12 | 0X10;
    // 0x80007474: sw          $t7, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r15;
    // 0x80007478: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x8000747C: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x80007480: lw          $t9, 0xC0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC0);
    // 0x80007484: nop

    // 0x80007488: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8000748C: sw          $t5, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r13;
    // 0x80007490: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007494: nop

    // 0x80007498: lw          $t2, 0xC0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC0);
    // 0x8000749C: nop

    // 0x800074A0: ori         $t6, $t2, 0x10
    ctx->r14 = ctx->r10 | 0X10;
    // 0x800074A4: sw          $t6, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r14;
    // 0x800074A8: lw          $t3, 0x1C8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C8);
    // 0x800074AC: nop

    // 0x800074B0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800074B4: sw          $t4, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r12;
L_800074B8:
    // 0x800074B8: b           L_80007520
    // 0x800074BC: nop

        goto L_80007520;
    // 0x800074BC: nop

L_800074C0:
    // 0x800074C0: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    // 0x800074C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800074C8: lwc1        $f6, 0xE8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x800074CC: nop

    // 0x800074D0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800074D4: nop

    // 0x800074D8: bc1f        L_800074E8
    if (!c1cs) {
        // 0x800074DC: nop
    
            goto L_800074E8;
    }
    // 0x800074DC: nop

    // 0x800074E0: b           L_800074FC
    // 0x800074E4: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
        goto L_800074FC;
    // 0x800074E4: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
L_800074E8:
    // 0x800074E8: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x800074EC: nop

    // 0x800074F0: lwc1        $f20, 0xE8($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x800074F4: nop

    // 0x800074F8: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_800074FC:
    // 0x800074FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80007500: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80007504: nop

    // 0x80007508: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x8000750C: nop

    // 0x80007510: bc1f        L_80007520
    if (!c1cs) {
        // 0x80007514: nop
    
            goto L_80007520;
    }
    // 0x80007514: nop

    // 0x80007518: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000751C: sw          $t9, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r25;
L_80007520:
    // 0x80007520: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80007524: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80007528: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000752C: lhu         $t2, 0x1038($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1038);
    // 0x80007530: lhu         $t1, 0x6($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X6);
    // 0x80007534: nop

    // 0x80007538: and         $t6, $t1, $t2
    ctx->r14 = ctx->r9 & ctx->r10;
    // 0x8000753C: beq         $t6, $zero, L_80007550
    if (ctx->r14 == 0) {
        // 0x80007540: nop
    
            goto L_80007550;
    }
    // 0x80007540: nop

    // 0x80007544: lw          $a0, 0x1B8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1B8);
    // 0x80007548: jal         0x8001AFA0
    // 0x8000754C: nop

    func_8001AFA0(rdram, ctx);
        goto after_39;
    // 0x8000754C: nop

    after_39:
L_80007550:
    // 0x80007550: b           L_80007570
    // 0x80007554: nop

        goto L_80007570;
    // 0x80007554: nop

L_80007558:
    // 0x80007558: b           L_80007558
    pause_self(rdram);
    // 0x8000755C: nop

    // 0x80007560: b           L_80007570
    // 0x80007564: nop

        goto L_80007570;
    // 0x80007564: nop

L_80007568:
    // 0x80007568: b           L_80007570
    // 0x8000756C: nop

        goto L_80007570;
    // 0x8000756C: nop

L_80007570:
    // 0x80007570: lw          $t0, 0x1D0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D0);
    // 0x80007574: nop

    // 0x80007578: beq         $t0, $zero, L_80006A48
    if (ctx->r8 == 0) {
        // 0x8000757C: nop
    
            goto L_80006A48;
    }
    // 0x8000757C: nop

L_80007580:
    // 0x80007580: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80007584: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80007588: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000758C: nop

    // 0x80007590: andi        $t7, $t4, 0x8000
    ctx->r15 = ctx->r12 & 0X8000;
    // 0x80007594: beq         $t7, $zero, L_800075E0
    if (ctx->r15 == 0) {
        // 0x80007598: nop
    
            goto L_800075E0;
    }
    // 0x80007598: nop

    // 0x8000759C: lw          $a0, 0x168($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X168);
    // 0x800075A0: jal         0x800BC980
    // 0x800075A4: nop

    SysMem_Free(rdram, ctx);
        goto after_40;
    // 0x800075A4: nop

    after_40:
    // 0x800075A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800075AC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800075B0: lw          $a1, 0x648($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X648);
    // 0x800075B4: lw          $a0, -0x6080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6080);
    // 0x800075B8: jal         0x800BCFCC
    // 0x800075BC: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    SysMem_Copy8(rdram, ctx);
        goto after_41;
    // 0x800075BC: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    after_41:
    // 0x800075C0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800075C4: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800075C8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800075CC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800075D0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800075D4: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x800075D8: b           L_800076F0
    // 0x800075DC: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
        goto L_800076F0;
    // 0x800075DC: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
L_800075E0:
    // 0x800075E0: jal         0x8008D23C
    // 0x800075E4: nop

    func_8008D23C(rdram, ctx);
        goto after_42;
    // 0x800075E4: nop

    after_42:
    // 0x800075E8: lw          $t1, 0x1B4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B4);
    // 0x800075EC: nop

    // 0x800075F0: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x800075F4: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800075F8: nop

    // 0x800075FC: blez        $t2, L_80007680
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80007600: nop
    
            goto L_80007680;
    }
    // 0x80007600: nop

L_80007604:
    // 0x80007604: lw          $t6, 0x1B8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1B8);
    // 0x80007608: addiu       $a1, $sp, 0x1B0
    ctx->r5 = ADD32(ctx->r29, 0X1B0);
    // 0x8000760C: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80007610: jal         0x800C143C
    // 0x80007614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_43;
    // 0x80007614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_43:
    // 0x80007618: lw          $t0, 0x1B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1B0);
    // 0x8000761C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80007620: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80007624: nop

    // 0x80007628: bne         $t3, $at, L_80007664
    if (ctx->r11 != ctx->r1) {
        // 0x8000762C: nop
    
            goto L_80007664;
    }
    // 0x8000762C: nop

    // 0x80007630: b           L_80007638
    // 0x80007634: nop

        goto L_80007638;
    // 0x80007634: nop

L_80007638:
    // 0x80007638: jal         0x80099520
    // 0x8000763C: nop

    func_80099520(rdram, ctx);
        goto after_44;
    // 0x8000763C: nop

    after_44:
    // 0x80007640: lw          $t4, 0x1B4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007644: nop

    // 0x80007648: addiu       $t7, $t4, 0x7FFF
    ctx->r15 = ADD32(ctx->r12, 0X7FFF);
    // 0x8000764C: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80007650: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80007654: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80007658: sw          $t9, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r25;
    // 0x8000765C: b           L_80007664
    // 0x80007660: nop

        goto L_80007664;
    // 0x80007660: nop

L_80007664:
    // 0x80007664: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007668: nop

    // 0x8000766C: addiu       $t8, $t5, 0x7FFF
    ctx->r24 = ADD32(ctx->r13, 0X7FFF);
    // 0x80007670: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80007674: nop

    // 0x80007678: bgtz        $t8, L_80007604
    if (SIGNED(ctx->r24) > 0) {
        // 0x8000767C: nop
    
            goto L_80007604;
    }
    // 0x8000767C: nop

L_80007680:
    // 0x80007680: jal         0x80098820
    // 0x80007684: nop

    func_80098820(rdram, ctx);
        goto after_45;
    // 0x80007684: nop

    after_45:
    // 0x80007688: jal         0x80098868
    // 0x8000768C: nop

    func_80098868(rdram, ctx);
        goto after_46;
    // 0x8000768C: nop

    after_46:
    // 0x80007690: lw          $t1, 0x1BC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1BC);
    // 0x80007694: nop

    // 0x80007698: bne         $t1, $zero, L_800076CC
    if (ctx->r9 != 0) {
        // 0x8000769C: nop
    
            goto L_800076CC;
    }
    // 0x8000769C: nop

    // 0x800076A0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800076A4: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800076A8: jal         0x800A6670
    // 0x800076AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_47;
    // 0x800076AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_47:
    // 0x800076B0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800076B4: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800076B8: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x800076BC: jal         0x800A6670
    // 0x800076C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_48;
    // 0x800076C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_48:
    // 0x800076C4: jal         0x80005460
    // 0x800076C8: nop

    func_80005460(rdram, ctx);
        goto after_49;
    // 0x800076C8: nop

    after_49:
L_800076CC:
    // 0x800076CC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800076D0: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800076D4: jal         0x800A6670
    // 0x800076D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_50;
    // 0x800076D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_50:
    // 0x800076DC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800076E0: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800076E4: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x800076E8: jal         0x800A6670
    // 0x800076EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_51;
    // 0x800076EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_51:
L_800076F0:
    // 0x800076F0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800076F4: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800076F8: lhu         $t6, 0x0($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X0);
    // 0x800076FC: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80007700: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x80007704: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x80007708: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000770C: addiu       $t3, $t3, -0x5B58
    ctx->r11 = ADD32(ctx->r11, -0X5B58);
    // 0x80007710: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80007714: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007718: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x8000771C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80007720: addiu       $t7, $t7, -0x5B58
    ctx->r15 = ADD32(ctx->r15, -0X5B58);
    // 0x80007724: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80007728: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000772C: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
    // 0x80007730: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80007734: addiu       $t9, $t9, -0x5B58
    ctx->r25 = ADD32(ctx->r25, -0X5B58);
    // 0x80007738: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8000773C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007740: swc1        $f18, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f18.u32l;
    // 0x80007744: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007748: addiu       $t4, $t4, -0x5B58
    ctx->r12 = ADD32(ctx->r12, -0X5B58);
    // 0x8000774C: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80007750: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007754: swc1        $f4, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f4.u32l;
    // 0x80007758: lw          $t5, 0x1B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B8);
    // 0x8000775C: nop

    // 0x80007760: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80007764: jal         0x800C13B8
    // 0x80007768: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_52;
    // 0x80007768: nop

    after_52:
    // 0x8000776C: jal         0x80098820
    // 0x80007770: nop

    func_80098820(rdram, ctx);
        goto after_53;
    // 0x80007770: nop

    after_53:
    // 0x80007774: b           L_8000777C
    // 0x80007778: nop

        goto L_8000777C;
    // 0x80007778: nop

L_8000777C:
    // 0x8000777C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80007780: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80007784: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80007788: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000778C: jr          $ra
    // 0x80007790: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
    return;
    // 0x80007790: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
;}
RECOMP_FUNC void func_8006DBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DBC8: jal         0x80061348
    // 0x8006DBCC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DBCC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DBD0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DBD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DBD8: beq         $v0, $zero, L_8006DC08
    if (ctx->r2 == 0) {
        // 0x8006DBDC: nop
    
            goto L_8006DC08;
    }
    // 0x8006DBDC: nop

    // 0x8006DBE0: jal         0x80061348
    // 0x8006DBE4: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DBE4: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DBE8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DBEC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DBF0: beq         $v0, $zero, L_8006DC08
    if (ctx->r2 == 0) {
        // 0x8006DBF4: nop
    
            goto L_8006DC08;
    }
    // 0x8006DBF4: nop

    // 0x8006DBF8: jal         0x80061348
    // 0x8006DBFC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DBFC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_2:
    // 0x8006DC00: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC04: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DC08:
    // 0x8006DC08: b           L_8006DC18
    // 0x8006DC0C: nop

        goto L_8006DC18;
    // 0x8006DC0C: nop

    // 0x8006DC10: b           L_8006DC18
    // 0x8006DC14: nop

        goto L_8006DC18;
    // 0x8006DC14: nop

L_8006DC18:
    // 0x8006DC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DC1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DC20: jr          $ra
    // 0x8006DC24: nop

    return;
    // 0x8006DC24: nop

;}
RECOMP_FUNC void alSynFreeVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3D28: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x800D3D2C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D3D30: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D3D34: beql        $a2, $zero, L_800D3DC4
    if (ctx->r6 == 0) {
        // 0x800D3D38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3DC4;
    }
    goto skip_0;
    // 0x800D3D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3D3C: lw          $t6, 0xD8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD8);
    // 0x800D3D40: beql        $t6, $zero, L_800D3DAC
    if (ctx->r14 == 0) {
        // 0x800D3D44: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800D3DAC;
    }
    goto skip_1;
    // 0x800D3D44: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x800D3D48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D3D4C: jal         0x800C7C00
    // 0x800D3D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D3D54: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3D58: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800D3D5C: beq         $v0, $zero, L_800D3DC0
    if (ctx->r2 == 0) {
        // 0x800D3D60: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D3DC0;
    }
    // 0x800D3D60: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3D64: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x800D3D68: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800D3D6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3D70: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x800D3D74: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800D3D78: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800D3D7C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D3D80: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800D3D84: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800D3D88: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D3D8C: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D3D90: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800D3D94: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3D98: jalr        $t9
    // 0x800D3D9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D3D9C: nop

    after_1:
    // 0x800D3DA0: b           L_800D3DBC
    // 0x800D3DA4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800D3DBC;
    // 0x800D3DA4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3DA8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800D3DAC:
    // 0x800D3DAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800D3DB0: jal         0x800C7B50
    // 0x800D3DB4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _freePVoice(rdram, ctx);
        goto after_2;
    // 0x800D3DB4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800D3DB8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800D3DBC:
    // 0x800D3DBC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_800D3DC0:
    // 0x800D3DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3DC4:
    // 0x800D3DC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3DC8: jr          $ra
    // 0x800D3DCC: nop

    return;
    // 0x800D3DCC: nop

;}
RECOMP_FUNC void func_8001E980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001E984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E988: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001E98C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001E990: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E994: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E998: nop

    // 0x8001E99C: bltz        $t6, L_8001EA64
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001E9A0: nop
    
            goto L_8001EA64;
    }
    // 0x8001E9A0: nop

    // 0x8001E9A4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E9A8: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E9AC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001E9B0: lhu         $t9, 0xEC0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEC0);
    // 0x8001E9B4: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001E9B8: nop

    // 0x8001E9BC: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001E9C0: beq         $t0, $zero, L_8001E9DC
    if (ctx->r8 == 0) {
        // 0x8001E9C4: nop
    
            goto L_8001E9DC;
    }
    // 0x8001E9C4: nop

    // 0x8001E9C8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001E9CC: lw          $t1, 0x1680($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1680);
    // 0x8001E9D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E9D4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8001E9D8: sw          $t2, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r10;
L_8001E9DC:
    // 0x8001E9DC: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001E9E0: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001E9E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E9E8: lhu         $t5, 0xEEC($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEEC);
    // 0x8001E9EC: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001E9F0: nop

    // 0x8001E9F4: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001E9F8: beq         $t6, $zero, L_8001EA14
    if (ctx->r14 == 0) {
        // 0x8001E9FC: nop
    
            goto L_8001EA14;
    }
    // 0x8001E9FC: nop

    // 0x8001EA00: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001EA04: lw          $t7, 0x1680($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1680);
    // 0x8001EA08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001EA0C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001EA10: sw          $t8, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r24;
L_8001EA14:
    // 0x8001EA14: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EA18: lw          $t9, 0x1680($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1680);
    // 0x8001EA1C: nop

    // 0x8001EA20: bgez        $t9, L_8001EA30
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001EA24: nop
    
            goto L_8001EA30;
    }
    // 0x8001EA24: nop

    // 0x8001EA28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001EA2C: sw          $zero, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = 0;
L_8001EA30:
    // 0x8001EA30: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001EA34: lw          $t0, 0x1680($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1680);
    // 0x8001EA38: nop

    // 0x8001EA3C: sltiu       $at, $t0, 0x4
    ctx->r1 = ctx->r8 < 0X4 ? 1 : 0;
    // 0x8001EA40: bne         $at, $zero, L_8001EA54
    if (ctx->r1 != 0) {
        // 0x8001EA44: nop
    
            goto L_8001EA54;
    }
    // 0x8001EA44: nop

    // 0x8001EA48: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8001EA4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001EA50: sw          $t1, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r9;
L_8001EA54:
    // 0x8001EA54: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8001EA58: lw          $a0, 0x1680($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1680);
    // 0x8001EA5C: jal         0x800BD9D0
    // 0x8001EA60: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800BD9D0(rdram, ctx);
        goto after_0;
    // 0x8001EA60: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
L_8001EA64:
    // 0x8001EA64: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001EA68: lw          $s0, 0x1680($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1680);
    // 0x8001EA6C: nop

    // 0x8001EA70: beq         $s0, $zero, L_8001EAA4
    if (ctx->r16 == 0) {
        // 0x8001EA74: nop
    
            goto L_8001EAA4;
    }
    // 0x8001EA74: nop

    // 0x8001EA78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001EA7C: beq         $s0, $at, L_8001EAB8
    if (ctx->r16 == ctx->r1) {
        // 0x8001EA80: nop
    
            goto L_8001EAB8;
    }
    // 0x8001EA80: nop

    // 0x8001EA84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001EA88: beq         $s0, $at, L_8001EACC
    if (ctx->r16 == ctx->r1) {
        // 0x8001EA8C: nop
    
            goto L_8001EACC;
    }
    // 0x8001EA8C: nop

    // 0x8001EA90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001EA94: beq         $s0, $at, L_8001EAE0
    if (ctx->r16 == ctx->r1) {
        // 0x8001EA98: nop
    
            goto L_8001EAE0;
    }
    // 0x8001EA98: nop

    // 0x8001EA9C: b           L_8001EAF4
    // 0x8001EAA0: nop

        goto L_8001EAF4;
    // 0x8001EAA0: nop

L_8001EAA4:
    // 0x8001EAA4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EAA8: jal         0x8008ECE4
    // 0x8001EAAC: addiu       $a0, $a0, -0x257C
    ctx->r4 = ADD32(ctx->r4, -0X257C);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001EAAC: addiu       $a0, $a0, -0x257C
    ctx->r4 = ADD32(ctx->r4, -0X257C);
    after_1:
    // 0x8001EAB0: b           L_8001EAF4
    // 0x8001EAB4: nop

        goto L_8001EAF4;
    // 0x8001EAB4: nop

L_8001EAB8:
    // 0x8001EAB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EABC: jal         0x8008ECE4
    // 0x8001EAC0: addiu       $a0, $a0, -0x255C
    ctx->r4 = ADD32(ctx->r4, -0X255C);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001EAC0: addiu       $a0, $a0, -0x255C
    ctx->r4 = ADD32(ctx->r4, -0X255C);
    after_2:
    // 0x8001EAC4: b           L_8001EAF4
    // 0x8001EAC8: nop

        goto L_8001EAF4;
    // 0x8001EAC8: nop

L_8001EACC:
    // 0x8001EACC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EAD0: jal         0x8008ECE4
    // 0x8001EAD4: addiu       $a0, $a0, -0x253C
    ctx->r4 = ADD32(ctx->r4, -0X253C);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001EAD4: addiu       $a0, $a0, -0x253C
    ctx->r4 = ADD32(ctx->r4, -0X253C);
    after_3:
    // 0x8001EAD8: b           L_8001EAF4
    // 0x8001EADC: nop

        goto L_8001EAF4;
    // 0x8001EADC: nop

L_8001EAE0:
    // 0x8001EAE0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EAE4: jal         0x8008ECE4
    // 0x8001EAE8: addiu       $a0, $a0, -0x251C
    ctx->r4 = ADD32(ctx->r4, -0X251C);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8001EAE8: addiu       $a0, $a0, -0x251C
    ctx->r4 = ADD32(ctx->r4, -0X251C);
    after_4:
    // 0x8001EAEC: b           L_8001EAF4
    // 0x8001EAF0: nop

        goto L_8001EAF4;
    // 0x8001EAF0: nop

L_8001EAF4:
    // 0x8001EAF4: b           L_8001EB04
    // 0x8001EAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EB04;
    // 0x8001EAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EAFC: b           L_8001EB04
    // 0x8001EB00: nop

        goto L_8001EB04;
    // 0x8001EB00: nop

L_8001EB04:
    // 0x8001EB04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EB08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EB0C: jr          $ra
    // 0x8001EB10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001EB10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006CA38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA40: jal         0x8005F064
    // 0x8006CA44: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CA44: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_0:
    // 0x8006CA48: b           L_8006CA58
    // 0x8006CA4C: nop

        goto L_8006CA58;
    // 0x8006CA4C: nop

    // 0x8006CA50: b           L_8006CA58
    // 0x8006CA54: nop

        goto L_8006CA58;
    // 0x8006CA54: nop

L_8006CA58:
    // 0x8006CA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA60: jr          $ra
    // 0x8006CA64: nop

    return;
    // 0x8006CA64: nop

;}
RECOMP_FUNC void func_8005A5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A5E4: jr          $ra
    // 0x8005A5E8: nop

    return;
    // 0x8005A5E8: nop

    // 0x8005A5EC: jr          $ra
    // 0x8005A5F0: nop

    return;
    // 0x8005A5F0: nop

;}
RECOMP_FUNC void func_80062938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006293C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062940: jal         0x8005F064
    // 0x80062944: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062944: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    after_0:
    // 0x80062948: b           L_80062958
    // 0x8006294C: nop

        goto L_80062958;
    // 0x8006294C: nop

    // 0x80062950: b           L_80062958
    // 0x80062954: nop

        goto L_80062958;
    // 0x80062954: nop

L_80062958:
    // 0x80062958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006295C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062960: jr          $ra
    // 0x80062964: nop

    return;
    // 0x80062964: nop

;}
RECOMP_FUNC void func_800702A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800702A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800702AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800702B0: jal         0x80061348
    // 0x800702B4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800702B4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800702B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800702BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800702C0: beq         $v0, $zero, L_80070310
    if (ctx->r2 == 0) {
        // 0x800702C4: nop
    
            goto L_80070310;
    }
    // 0x800702C4: nop

    // 0x800702C8: jal         0x80061348
    // 0x800702CC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800702CC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800702D0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800702D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800702D8: beq         $v0, $zero, L_80070310
    if (ctx->r2 == 0) {
        // 0x800702DC: nop
    
            goto L_80070310;
    }
    // 0x800702DC: nop

    // 0x800702E0: jal         0x80061348
    // 0x800702E4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800702E4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800702E8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800702EC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800702F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800702F4: beq         $v0, $zero, L_80070310
    if (ctx->r2 == 0) {
        // 0x800702F8: nop
    
            goto L_80070310;
    }
    // 0x800702F8: nop

    // 0x800702FC: jal         0x80061348
    // 0x80070300: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070300: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070304: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070308: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007030C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070310:
    // 0x80070310: b           L_80070320
    // 0x80070314: nop

        goto L_80070320;
    // 0x80070314: nop

    // 0x80070318: b           L_80070320
    // 0x8007031C: nop

        goto L_80070320;
    // 0x8007031C: nop

L_80070320:
    // 0x80070320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070328: jr          $ra
    // 0x8007032C: nop

    return;
    // 0x8007032C: nop

;}
RECOMP_FUNC void func_80010460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010460: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80010464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010468: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001046C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80010470: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80010474: nop

    // 0x80010478: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001047C: nop

    // 0x80010480: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80010484: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80010488: nop

    // 0x8001048C: bne         $t8, $zero, L_800105DC
    if (ctx->r24 != 0) {
        // 0x80010490: nop
    
            goto L_800105DC;
    }
    // 0x80010490: nop

    // 0x80010494: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80010498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001049C: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800104A0: lwc1        $f4, 0x30($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X30);
    // 0x800104A4: lwc1        $f10, 0x2C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x800104A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800104AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800104B0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800104B4: swc1        $f16, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f16.u32l;
    // 0x800104B8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800104BC: lwc1        $f6, -0x2B7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B7C);
    // 0x800104C0: lwc1        $f18, 0x2C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x800104C4: lwc1        $f7, -0x2B80($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2B80);
    // 0x800104C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800104CC: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800104D0: nop

    // 0x800104D4: bc1f        L_80010500
    if (!c1cs) {
        // 0x800104D8: nop
    
            goto L_80010500;
    }
    // 0x800104D8: nop

    // 0x800104DC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800104E0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800104E4: lwc1        $f10, 0x2C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800104E8: lwc1        $f17, -0x2B78($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2B78);
    // 0x800104EC: lwc1        $f16, -0x2B74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B74);
    // 0x800104F0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800104F4: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x800104F8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800104FC: swc1        $f4, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->f4.u32l;
L_80010500:
    // 0x80010500: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80010504: nop

    // 0x80010508: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x8001050C: nop

    // 0x80010510: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80010514: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80010518: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001051C: lwc1        $f10, 0x2C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x80010520: lwc1        $f17, -0x2B70($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2B70);
    // 0x80010524: lwc1        $f16, -0x2B6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B6C);
    // 0x80010528: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8001052C: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80010530: jal         0x800C3070
    // 0x80010534: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_0;
    // 0x80010534: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x80010538: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8001053C: nop

    // 0x80010540: lwc1        $f4, 0x34($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X34);
    // 0x80010544: nop

    // 0x80010548: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001054C: swc1        $f6, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f6.u32l;
    // 0x80010550: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80010554: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80010558: lwc1        $f10, 0x38($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X38);
    // 0x8001055C: nop

    // 0x80010560: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80010564: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x80010568: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001056C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80010570: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80010574: nop

    // 0x80010578: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8001057C: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80010580: nop

    // 0x80010584: blez        $t8, L_800105D4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010588: nop
    
            goto L_800105D4;
    }
    // 0x80010588: nop

L_8001058C:
    // 0x8001058C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80010590: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80010594: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x80010598: nop

    // 0x8001059C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800105A0: swc1        $f6, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f6.u32l;
    // 0x800105A4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800105A8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800105AC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800105B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800105B4: addiu       $t3, $t2, 0x160
    ctx->r11 = ADD32(ctx->r10, 0X160);
    // 0x800105B8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800105BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800105C0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800105C4: nop

    // 0x800105C8: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800105CC: bne         $at, $zero, L_8001058C
    if (ctx->r1 != 0) {
        // 0x800105D0: nop
    
            goto L_8001058C;
    }
    // 0x800105D0: nop

L_800105D4:
    // 0x800105D4: b           L_80010724
    // 0x800105D8: nop

        goto L_80010724;
    // 0x800105D8: nop

L_800105DC:
    // 0x800105DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800105E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800105E4: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800105E8: lwc1        $f10, 0x40($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X40);
    // 0x800105EC: lwc1        $f18, 0x3C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x800105F0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800105F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800105F8: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800105FC: swc1        $f4, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f4.u32l;
    // 0x80010600: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80010604: lwc1        $f8, -0x2B64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B64);
    // 0x80010608: lwc1        $f6, 0x3C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x8001060C: lwc1        $f9, -0x2B68($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2B68);
    // 0x80010610: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80010614: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80010618: nop

    // 0x8001061C: bc1f        L_80010648
    if (!c1cs) {
        // 0x80010620: nop
    
            goto L_80010648;
    }
    // 0x80010620: nop

    // 0x80010624: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80010628: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001062C: lwc1        $f18, 0x3C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x80010630: lwc1        $f5, -0x2B60($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2B60);
    // 0x80010634: lwc1        $f4, -0x2B5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x80010638: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8001063C: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x80010640: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80010644: swc1        $f10, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f10.u32l;
L_80010648:
    // 0x80010648: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8001064C: nop

    // 0x80010650: lwc1        $f8, 0x48($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X48);
    // 0x80010654: nop

    // 0x80010658: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001065C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80010660: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80010664: lwc1        $f18, 0x3C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80010668: lwc1        $f5, -0x2B58($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2B58);
    // 0x8001066C: lwc1        $f4, -0x2B54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x80010670: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80010674: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80010678: jal         0x800C3070
    // 0x8001067C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x8001067C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_1:
    // 0x80010680: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80010684: nop

    // 0x80010688: lwc1        $f10, 0x44($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X44);
    // 0x8001068C: nop

    // 0x80010690: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80010694: swc1        $f8, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f8.u32l;
    // 0x80010698: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001069C: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800106A0: lwc1        $f18, 0x48($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X48);
    // 0x800106A4: nop

    // 0x800106A8: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800106AC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800106B0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800106B4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800106B8: lw          $t1, 0xC($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC);
    // 0x800106BC: nop

    // 0x800106C0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800106C4: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800106C8: nop

    // 0x800106CC: blez        $t5, L_8001071C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800106D0: nop
    
            goto L_8001071C;
    }
    // 0x800106D0: nop

L_800106D4:
    // 0x800106D4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800106D8: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800106DC: lwc1        $f6, 0xD0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x800106E0: nop

    // 0x800106E4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800106E8: swc1        $f8, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f8.u32l;
    // 0x800106EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800106F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800106F4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800106F8: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800106FC: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80010700: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80010704: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80010708: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x8001070C: nop

    // 0x80010710: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010714: bne         $at, $zero, L_800106D4
    if (ctx->r1 != 0) {
        // 0x80010718: nop
    
            goto L_800106D4;
    }
    // 0x80010718: nop

L_8001071C:
    // 0x8001071C: b           L_80010724
    // 0x80010720: nop

        goto L_80010724;
    // 0x80010720: nop

L_80010724:
    // 0x80010724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010728: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001072C: jr          $ra
    // 0x80010730: nop

    return;
    // 0x80010730: nop

;}
RECOMP_FUNC void func_800679F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800679F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800679FC: nop

    // 0x80067A00: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80067A04: nop

    // 0x80067A08: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067A0C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067A10: jr          $ra
    // 0x80067A14: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067A14: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067A18: jr          $ra
    // 0x80067A1C: nop

    return;
    // 0x80067A1C: nop

    // 0x80067A20: jr          $ra
    // 0x80067A24: nop

    return;
    // 0x80067A24: nop

;}
RECOMP_FUNC void func_80077174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077174: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077178: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007717C: nop

    // 0x80077180: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80077184: nop

    // 0x80077188: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8007718C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077190: jr          $ra
    // 0x80077194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077198: jr          $ra
    // 0x8007719C: nop

    return;
    // 0x8007719C: nop

    // 0x800771A0: jr          $ra
    // 0x800771A4: nop

    return;
    // 0x800771A4: nop

;}
RECOMP_FUNC void MtxUtil__MtxToMtxF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2F1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C2F20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2F24: addiu       $t6, $a1, 0x20
    ctx->r14 = ADD32(ctx->r5, 0X20);
    // 0x800C2F28: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800C2F2C: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800C2F30: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
L_800C2F34:
    // 0x800C2F34: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
L_800C2F38:
    // 0x800C2F38: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2F3C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800C2F40: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x800C2F44: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800C2F48: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x800C2F4C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C2F50: and         $t2, $a2, $at
    ctx->r10 = ctx->r6 & ctx->r1;
    // 0x800C2F54: srl         $t0, $t9, 16
    ctx->r8 = S32(U32(ctx->r25) >> 16);
    // 0x800C2F58: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800C2F5C: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x800C2F60: addiu       $t4, $t7, 0x4
    ctx->r12 = ADD32(ctx->r15, 0X4);
    // 0x800C2F64: addiu       $t5, $t8, 0x4
    ctx->r13 = ADD32(ctx->r24, 0X4);
    // 0x800C2F68: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800C2F6C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800C2F70: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800C2F74: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C2F78: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800C2F7C: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x800C2F80: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800C2F84: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x800C2F88: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800C2F8C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800C2F90: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x800C2F94: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800C2F98: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C2F9C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C2FA0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800C2FA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C2FA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C2FAC: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x800C2FB0: lh          $t8, 0x2C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2C);
    // 0x800C2FB4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C2FB8: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800C2FBC: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x800C2FC0: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x800C2FC4: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x800C2FC8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800C2FCC: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800C2FD0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C2FD4: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800C2FD8: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x800C2FDC: sh          $a3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r7;
    // 0x800C2FE0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800C2FE4: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x800C2FE8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800C2FEC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C2FF0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800C2FF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2FF8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C2FFC: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800C3000: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3004: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C3008: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C300C: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800C3010: swc1        $f6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f6.u32l;
    // 0x800C3014: lh          $t9, 0x2C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2C);
    // 0x800C3018: nop

    // 0x800C301C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800C3020: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x800C3024: sra         $t2, $t0, 16
    ctx->r10 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800C3028: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800C302C: bne         $at, $zero, L_800C2F38
    if (ctx->r1 != 0) {
        // 0x800C3030: sh          $t1, 0x2C($sp)
        MEM_H(0X2C, ctx->r29) = ctx->r9;
            goto L_800C2F38;
    }
    // 0x800C3030: sh          $t1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r9;
    // 0x800C3034: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x800C3038: nop

    // 0x800C303C: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x800C3040: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800C3044: sra         $t8, $t4, 16
    ctx->r24 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800C3048: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800C304C: bne         $at, $zero, L_800C2F34
    if (ctx->r1 != 0) {
        // 0x800C3050: sh          $t7, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r15;
            goto L_800C2F34;
    }
    // 0x800C3050: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
    // 0x800C3054: b           L_800C305C
    // 0x800C3058: nop

        goto L_800C305C;
    // 0x800C3058: nop

L_800C305C:
    // 0x800C305C: jr          $ra
    // 0x800C3060: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C3060: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80067074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067078: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006707C: nop

    // 0x80067080: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80067084: nop

    // 0x80067088: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006708C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067090: jr          $ra
    // 0x80067094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067098: jr          $ra
    // 0x8006709C: nop

    return;
    // 0x8006709C: nop

    // 0x800670A0: jr          $ra
    // 0x800670A4: nop

    return;
    // 0x800670A4: nop

;}
RECOMP_FUNC void func_8006C918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C920: jal         0x8005F064
    // 0x8006C924: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C924: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_0:
    // 0x8006C928: b           L_8006C938
    // 0x8006C92C: nop

        goto L_8006C938;
    // 0x8006C92C: nop

    // 0x8006C930: b           L_8006C938
    // 0x8006C934: nop

        goto L_8006C938;
    // 0x8006C934: nop

L_8006C938:
    // 0x8006C938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C940: jr          $ra
    // 0x8006C944: nop

    return;
    // 0x8006C944: nop

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
RECOMP_FUNC void func_800B3DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3DBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B3DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3DC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B3DC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B3DCC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B3DD0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3DD4: nop

    // 0x800B3DD8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B3DDC: nop

    // 0x800B3DE0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B3DE4: nop

    // 0x800B3DE8: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x800B3DEC: nop

    // 0x800B3DF0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800B3DF4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3DF8: nop

    // 0x800B3DFC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B3E00: nop

    // 0x800B3E04: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800B3E08: nop

    // 0x800B3E0C: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800B3E10: beq         $t3, $zero, L_800B3E40
    if (ctx->r11 == 0) {
        // 0x800B3E14: nop
    
            goto L_800B3E40;
    }
    // 0x800B3E14: nop

    // 0x800B3E18: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3E1C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B3E20: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B3E24: nop

    // 0x800B3E28: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B3E2C: nop

    // 0x800B3E30: lbu         $t8, 0xF($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF);
    // 0x800B3E34: nop

    // 0x800B3E38: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800B3E3C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800B3E40:
    // 0x800B3E40: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B3E44: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800B3E48: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B3E4C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3E50: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800B3E54: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B3E58: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B3E5C: blez        $t5, L_800B3EA8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B3E60: sw          $t3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r11;
            goto L_800B3EA8;
    }
    // 0x800B3E60: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_800B3E64:
    // 0x800B3E64: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3E68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B3E6C: lhu         $a2, 0x32($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X32);
    // 0x800B3E70: jal         0x800B53A0
    // 0x800B3E74: nop

    LoadPalette(rdram, ctx);
        goto after_0;
    // 0x800B3E74: nop

    after_0:
    // 0x800B3E78: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B3E7C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3E80: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800B3E84: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B3E88: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B3E8C: addiu       $t8, $t4, 0x160
    ctx->r24 = ADD32(ctx->r12, 0X160);
    // 0x800B3E90: addiu       $t0, $t9, 0x40
    ctx->r8 = ADD32(ctx->r25, 0X40);
    // 0x800B3E94: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B3E98: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800B3E9C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800B3EA0: bne         $at, $zero, L_800B3E64
    if (ctx->r1 != 0) {
        // 0x800B3EA4: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_800B3E64;
    }
    // 0x800B3EA4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800B3EA8:
    // 0x800B3EA8: b           L_800B3EB0
    // 0x800B3EAC: nop

        goto L_800B3EB0;
    // 0x800B3EAC: nop

L_800B3EB0:
    // 0x800B3EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3EB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B3EB8: jr          $ra
    // 0x800B3EBC: nop

    return;
    // 0x800B3EBC: nop

;}
RECOMP_FUNC void func_80068678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068678: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006867C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068680: nop

    // 0x80068684: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068688: nop

    // 0x8006868C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068690: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068694: jr          $ra
    // 0x80068698: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068698: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006869C: jr          $ra
    // 0x800686A0: nop

    return;
    // 0x800686A0: nop

    // 0x800686A4: jr          $ra
    // 0x800686A8: nop

    return;
    // 0x800686A8: nop

;}
RECOMP_FUNC void func_8008C280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C280: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C284: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008C288: lh          $t6, 0x7A12($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7A12);
    // 0x8008C28C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8008C290: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x8008C294: mflo        $t7
    ctx->r15 = lo;
    // 0x8008C298: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8008C29C: nop

    // 0x8008C2A0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008C2A4: lh          $t9, 0x7A14($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7A14);
    // 0x8008C2A8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008C2AC: nop

    // 0x8008C2B0: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8008C2B4: beq         $at, $zero, L_8008C2CC
    if (ctx->r1 == 0) {
        // 0x8008C2B8: nop
    
            goto L_8008C2CC;
    }
    // 0x8008C2B8: nop

    // 0x8008C2BC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008C2C0: lh          $t0, 0x7A14($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7A14);
    // 0x8008C2C4: nop

    // 0x8008C2C8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
L_8008C2CC:
    // 0x8008C2CC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8008C2D0: b           L_8008C2E0
    // 0x8008C2D4: nop

        goto L_8008C2E0;
    // 0x8008C2D4: nop

    // 0x8008C2D8: b           L_8008C2E0
    // 0x8008C2DC: nop

        goto L_8008C2E0;
    // 0x8008C2DC: nop

L_8008C2E0:
    // 0x8008C2E0: jr          $ra
    // 0x8008C2E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C2E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80098BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098BB8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098BBC: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098BC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098BC4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80098BC8: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098BCC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80098BD0: lw          $t8, 0x72DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72DC);
    // 0x80098BD4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80098BD8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80098BDC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098BE0: sw          $t9, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r25;
    // 0x80098BE4: jr          $ra
    // 0x80098BE8: nop

    return;
    // 0x80098BE8: nop

    // 0x80098BEC: jr          $ra
    // 0x80098BF0: nop

    return;
    // 0x80098BF0: nop

;}
RECOMP_FUNC void func_800345E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800345E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800345E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800345E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800345EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800345F0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800345F4: lhu         $t9, -0x3A70($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X3A70);
    // 0x800345F8: lhu         $t0, 0x2E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2E);
    // 0x800345FC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80034600: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034604: lw          $t7, -0x3A6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3A6C);
    // 0x80034608: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8003460C: nop

    // 0x80034610: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80034614: mflo        $t1
    ctx->r9 = lo;
    // 0x80034618: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8003461C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80034620: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80034624: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80034628: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8003462C: nop

    // 0x80034630: bne         $t4, $at, L_80034640
    if (ctx->r12 != ctx->r1) {
        // 0x80034634: sb          $t4, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r12;
            goto L_80034640;
    }
    // 0x80034634: sb          $t4, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r12;
    // 0x80034638: b           L_800346D4
    // 0x8003463C: nop

        goto L_800346D4;
    // 0x8003463C: nop

L_80034640:
    // 0x80034640: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x80034644: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80034648: lw          $t5, 0x1D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1D4);
    // 0x8003464C: lhu         $t0, 0x2A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2A);
    // 0x80034650: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80034654: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80034658: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8003465C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80034660: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80034664: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80034668: bgez        $t0, L_80034680
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8003466C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80034680;
    }
    // 0x8003466C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034670: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80034674: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034678: nop

    // 0x8003467C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80034680:
    // 0x80034680: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80034684: lwc1        $f10, -0x3A78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A78);
    // 0x80034688: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x8003468C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80034690: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80034694: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80034698: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8003469C: bgez        $t8, L_800346B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800346A0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800346B4;
    }
    // 0x800346A0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800346A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800346A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800346AC: nop

    // 0x800346B0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800346B4:
    // 0x800346B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800346B8: lwc1        $f6, -0x3A74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A74);
    // 0x800346BC: nop

    // 0x800346C0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800346C4: jal         0x800AF330
    // 0x800346C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800AF330(rdram, ctx);
        goto after_0;
    // 0x800346C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800346CC: b           L_800346D4
    // 0x800346D0: nop

        goto L_800346D4;
    // 0x800346D0: nop

L_800346D4:
    // 0x800346D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800346D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800346DC: jr          $ra
    // 0x800346E0: nop

    return;
    // 0x800346E0: nop

;}
RECOMP_FUNC void func_80014A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014A80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014A88: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80014A8C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014A90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80014A94: jal         0x8000DA44
    // 0x80014A98: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80014A98: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80014A9C: bgez        $v0, L_80014AAC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80014AA0: nop
    
            goto L_80014AAC;
    }
    // 0x80014AA0: nop

    // 0x80014AA4: b           L_80014B4C
    // 0x80014AA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80014B4C;
    // 0x80014AA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014AAC:
    // 0x80014AAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014AB0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80014AB4: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80014AB8: nop

    // 0x80014ABC: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80014AC0: bne         $at, $zero, L_80014AE0
    if (ctx->r1 != 0) {
        // 0x80014AC4: nop
    
            goto L_80014AE0;
    }
    // 0x80014AC4: nop

    // 0x80014AC8: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80014ACC: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80014AD0: beq         $at, $zero, L_80014AE0
    if (ctx->r1 == 0) {
        // 0x80014AD4: nop
    
            goto L_80014AE0;
    }
    // 0x80014AD4: nop

    // 0x80014AD8: b           L_80014B4C
    // 0x80014ADC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80014B4C;
    // 0x80014ADC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014AE0:
    // 0x80014AE0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014AE4: nop

    // 0x80014AE8: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80014AEC: nop

    // 0x80014AF0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80014AF4: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80014AF8: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80014AFC: nop

    // 0x80014B00: bne         $t1, $zero, L_80014B24
    if (ctx->r9 != 0) {
        // 0x80014B04: nop
    
            goto L_80014B24;
    }
    // 0x80014B04: nop

    // 0x80014B08: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80014B0C: nop

    // 0x80014B10: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80014B14: nop

    // 0x80014B18: ori         $t4, $t3, 0x800
    ctx->r12 = ctx->r11 | 0X800;
    // 0x80014B1C: b           L_80014B3C
    // 0x80014B20: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
        goto L_80014B3C;
    // 0x80014B20: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
L_80014B24:
    // 0x80014B24: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80014B28: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80014B2C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80014B30: nop

    // 0x80014B34: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80014B38: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
L_80014B3C:
    // 0x80014B3C: b           L_80014B4C
    // 0x80014B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80014B4C;
    // 0x80014B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014B44: b           L_80014B4C
    // 0x80014B48: nop

        goto L_80014B4C;
    // 0x80014B48: nop

L_80014B4C:
    // 0x80014B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014B50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014B54: jr          $ra
    // 0x80014B58: nop

    return;
    // 0x80014B58: nop

;}
RECOMP_FUNC void func_8006DE58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DE5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DE60: jal         0x80061348
    // 0x8006DE64: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DE64: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006DE68: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DE70: beq         $v0, $zero, L_8006DE88
    if (ctx->r2 == 0) {
        // 0x8006DE74: nop
    
            goto L_8006DE88;
    }
    // 0x8006DE74: nop

    // 0x8006DE78: jal         0x80061348
    // 0x8006DE7C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DE7C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DE80: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DE84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DE88:
    // 0x8006DE88: b           L_8006DE98
    // 0x8006DE8C: nop

        goto L_8006DE98;
    // 0x8006DE8C: nop

    // 0x8006DE90: b           L_8006DE98
    // 0x8006DE94: nop

        goto L_8006DE98;
    // 0x8006DE94: nop

L_8006DE98:
    // 0x8006DE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DE9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DEA0: jr          $ra
    // 0x8006DEA4: nop

    return;
    // 0x8006DEA4: nop

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
RECOMP_FUNC void func_8007F878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007F884: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F888: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007F88C: jal         0x800A4104
    // 0x8007F890: nop

    func_800A4104(rdram, ctx);
        goto after_0;
    // 0x8007F890: nop

    after_0:
    // 0x8007F894: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F898: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007F89C: jal         0x800A3FC0
    // 0x8007F8A0: nop

    func_800A3FC0(rdram, ctx);
        goto after_1;
    // 0x8007F8A0: nop

    after_1:
    // 0x8007F8A4: jal         0x800BC6EC
    // 0x8007F8A8: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8007F8A8: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_2:
    // 0x8007F8AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F8B0: sw          $v0, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = ctx->r2;
    // 0x8007F8B4: jal         0x800BC6EC
    // 0x8007F8B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8007F8B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_3:
    // 0x8007F8BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F8C0: sw          $v0, 0x70F0($at)
    MEM_W(0X70F0, ctx->r1) = ctx->r2;
    // 0x8007F8C4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F8C8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007F8CC: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007F8D0: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007F8D4: jal         0x800B1B04
    // 0x8007F8D8: nop

    func_800B1B04(rdram, ctx);
        goto after_4;
    // 0x8007F8D8: nop

    after_4:
    // 0x8007F8DC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F8E0: lh          $t6, 0x7132($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7132);
    // 0x8007F8E4: nop

    // 0x8007F8E8: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x8007F8EC: beq         $at, $zero, L_8007F904
    if (ctx->r1 == 0) {
        // 0x8007F8F0: nop
    
            goto L_8007F904;
    }
    // 0x8007F8F0: nop

    // 0x8007F8F4: jal         0x8007B710
    // 0x8007F8F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8007B710(rdram, ctx);
        goto after_5;
    // 0x8007F8F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x8007F8FC: b           L_8007F90C
    // 0x8007F900: nop

        goto L_8007F90C;
    // 0x8007F900: nop

L_8007F904:
    // 0x8007F904: jal         0x8007B710
    // 0x8007F908: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8007B710(rdram, ctx);
        goto after_6;
    // 0x8007F908: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_6:
L_8007F90C:
    // 0x8007F90C: addiu       $t7, $zero, 0x33
    ctx->r15 = ADD32(0, 0X33);
    // 0x8007F910: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F914: sh          $t7, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r15;
    // 0x8007F918: b           L_8007F920
    // 0x8007F91C: nop

        goto L_8007F920;
    // 0x8007F91C: nop

L_8007F920:
    // 0x8007F920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007F924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007F928: jr          $ra
    // 0x8007F92C: nop

    return;
    // 0x8007F92C: nop

;}
RECOMP_FUNC void guRandom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4240: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C4244: lw          $a0, -0x4140($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4140);
    // 0x800C4248: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C424C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C4250: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800C4254: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x800C4258: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C425C: mflo        $a1
    ctx->r5 = lo;
    // 0x800C4260: srl         $v0, $a1, 2
    ctx->r2 = S32(U32(ctx->r5) >> 2);
    // 0x800C4264: jr          $ra
    // 0x800C4268: sw          $v0, -0x4140($at)
    MEM_W(-0X4140, ctx->r1) = ctx->r2;
    return;
    // 0x800C4268: sw          $v0, -0x4140($at)
    MEM_W(-0X4140, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80087718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087718: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008771C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087720: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80087724: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80087728: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008772C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80087730: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80087734: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80087738: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x8008773C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80087740: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80087744: beq         $t0, $zero, L_800879C0
    if (ctx->r8 == 0) {
        // 0x80087748: nop
    
            goto L_800879C0;
    }
    // 0x80087748: nop

    // 0x8008774C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80087750: jal         0x8008A518
    // 0x80087754: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80087754: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80087758: beq         $v0, $zero, L_800879C0
    if (ctx->r2 == 0) {
        // 0x8008775C: nop
    
            goto L_800879C0;
    }
    // 0x8008775C: nop

    // 0x80087760: lhu         $t1, 0x2C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087764: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80087768: bne         $t1, $at, L_800877C8
    if (ctx->r9 != ctx->r1) {
        // 0x8008776C: nop
    
            goto L_800877C8;
    }
    // 0x8008776C: nop

    // 0x80087770: jal         0x8008CE48
    // 0x80087774: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80087774: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80087778: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008777C: nop

    // 0x80087780: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80087784: nop

    // 0x80087788: andi        $t4, $t3, 0x800
    ctx->r12 = ctx->r11 & 0X800;
    // 0x8008778C: beq         $t4, $zero, L_800877C0
    if (ctx->r12 == 0) {
        // 0x80087790: nop
    
            goto L_800877C0;
    }
    // 0x80087790: nop

    // 0x80087794: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80087798: nop

    // 0x8008779C: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800877A0: nop

    // 0x800877A4: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800877A8: beq         $t7, $zero, L_800877B8
    if (ctx->r15 == 0) {
        // 0x800877AC: nop
    
            goto L_800877B8;
    }
    // 0x800877AC: nop

    // 0x800877B0: b           L_80087B70
    // 0x800877B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80087B70;
    // 0x800877B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800877B8:
    // 0x800877B8: b           L_80087B70
    // 0x800877BC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_80087B70;
    // 0x800877BC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800877C0:
    // 0x800877C0: b           L_80087B70
    // 0x800877C4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80087B70;
    // 0x800877C4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800877C8:
    // 0x800877C8: lhu         $t9, 0x2C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2C);
    // 0x800877CC: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800877D0: bne         $t9, $at, L_80087850
    if (ctx->r25 != ctx->r1) {
        // 0x800877D4: nop
    
            goto L_80087850;
    }
    // 0x800877D4: nop

    // 0x800877D8: jal         0x8008CE48
    // 0x800877DC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x800877DC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x800877E0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800877E4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800877E8: lbu         $t0, 0x10($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X10);
    // 0x800877EC: nop

    // 0x800877F0: bne         $t0, $at, L_80087830
    if (ctx->r8 != ctx->r1) {
        // 0x800877F4: nop
    
            goto L_80087830;
    }
    // 0x800877F4: nop

    // 0x800877F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800877FC:
    // 0x800877FC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80087800: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80087804: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80087808: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8008780C: lbu         $t2, 0x4BEC($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4BEC);
    // 0x80087810: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x80087814: sb          $t2, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r10;
    // 0x80087818: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8008781C: nop

    // 0x80087820: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087824: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80087828: bne         $at, $zero, L_800877FC
    if (ctx->r1 != 0) {
        // 0x8008782C: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800877FC;
    }
    // 0x8008782C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80087830:
    // 0x80087830: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80087834: nop

    // 0x80087838: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x8008783C: nop

    // 0x80087840: ori         $t8, $t9, 0x200
    ctx->r24 = ctx->r25 | 0X200;
    // 0x80087844: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x80087848: b           L_80087B70
    // 0x8008784C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087B70;
    // 0x8008784C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80087850:
    // 0x80087850: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087854: ori         $at, $zero, 0x805A
    ctx->r1 = 0 | 0X805A;
    // 0x80087858: bne         $t0, $at, L_80087880
    if (ctx->r8 != ctx->r1) {
        // 0x8008785C: nop
    
            goto L_80087880;
    }
    // 0x8008785C: nop

    // 0x80087860: jal         0x8008CE48
    // 0x80087864: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80087864: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_3:
    // 0x80087868: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008786C: nop

    // 0x80087870: lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X0);
    // 0x80087874: nop

    // 0x80087878: xori        $t2, $t1, 0x400
    ctx->r10 = ctx->r9 ^ 0X400;
    // 0x8008787C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
L_80087880:
    // 0x80087880: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087884: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80087888: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8008788C: bne         $at, $zero, L_800879C0
    if (ctx->r1 != 0) {
        // 0x80087890: nop
    
            goto L_800879C0;
    }
    // 0x80087890: nop

    // 0x80087894: ori         $at, $zero, 0x805A
    ctx->r1 = 0 | 0X805A;
    // 0x80087898: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8008789C: beq         $at, $zero, L_800879C0
    if (ctx->r1 == 0) {
        // 0x800878A0: nop
    
            goto L_800879C0;
    }
    // 0x800878A0: nop

    // 0x800878A4: jal         0x8008CE48
    // 0x800878A8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x800878A8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x800878AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800878B0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800878B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800878B8: lbu         $t6, 0x10($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X10);
    // 0x800878BC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800878C0: beq         $t6, $at, L_800878FC
    if (ctx->r14 == ctx->r1) {
        // 0x800878C4: nop
    
            goto L_800878FC;
    }
    // 0x800878C4: nop

L_800878C8:
    // 0x800878C8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800878CC: nop

    // 0x800878D0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800878D4: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x800878D8: beq         $at, $zero, L_800878FC
    if (ctx->r1 == 0) {
        // 0x800878DC: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800878FC;
    }
    // 0x800878DC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800878E0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800878E4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800878E8: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x800878EC: lbu         $t1, 0x10($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X10);
    // 0x800878F0: nop

    // 0x800878F4: bne         $t1, $at, L_800878C8
    if (ctx->r9 != ctx->r1) {
        // 0x800878F8: nop
    
            goto L_800878C8;
    }
    // 0x800878F8: nop

L_800878FC:
    // 0x800878FC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80087900: nop

    // 0x80087904: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80087908: bne         $at, $zero, L_80087918
    if (ctx->r1 != 0) {
        // 0x8008790C: nop
    
            goto L_80087918;
    }
    // 0x8008790C: nop

    // 0x80087910: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80087914: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_80087918:
    // 0x80087918: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008791C: nop

    // 0x80087920: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80087924: bne         $at, $zero, L_80087934
    if (ctx->r1 != 0) {
        // 0x80087928: nop
    
            goto L_80087934;
    }
    // 0x80087928: nop

    // 0x8008792C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80087930: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_80087934:
    // 0x80087934: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087938: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008793C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80087940: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80087944: ori         $at, $at, 0x7FFD
    ctx->r1 = ctx->r1 | 0X7FFD;
    // 0x80087948: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x8008794C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80087950: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80087954: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087958: nop

    // 0x8008795C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80087960: nop

    // 0x80087964: andi        $t3, $t2, 0x400
    ctx->r11 = ctx->r10 & 0X400;
    // 0x80087968: beq         $t3, $zero, L_80087990
    if (ctx->r11 == 0) {
        // 0x8008796C: nop
    
            goto L_80087990;
    }
    // 0x8008796C: nop

    // 0x80087970: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80087974: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80087978: nop

    // 0x8008797C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80087980: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x80087984: nop

    // 0x80087988: addiu       $t8, $t7, 0x57
    ctx->r24 = ADD32(ctx->r15, 0X57);
    // 0x8008798C: sb          $t8, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r24;
L_80087990:
    // 0x80087990: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80087994: nop

    // 0x80087998: beq         $t9, $zero, L_800879C0
    if (ctx->r25 == 0) {
        // 0x8008799C: nop
    
            goto L_800879C0;
    }
    // 0x8008799C: nop

    // 0x800879A0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800879A4: nop

    // 0x800879A8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800879AC: nop

    // 0x800879B0: ori         $t2, $t1, 0x200
    ctx->r10 = ctx->r9 | 0X200;
    // 0x800879B4: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x800879B8: b           L_80087B70
    // 0x800879BC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087B70;
    // 0x800879BC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_800879C0:
    // 0x800879C0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800879C4: lhu         $t4, 0x101C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X101C);
    // 0x800879C8: lhu         $t3, 0x3E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3E);
    // 0x800879CC: nop

    // 0x800879D0: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800879D4: beq         $t5, $zero, L_80087AC0
    if (ctx->r13 == 0) {
        // 0x800879D8: nop
    
            goto L_80087AC0;
    }
    // 0x800879D8: nop

    // 0x800879DC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800879E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800879E4: lbu         $t8, 0x10($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X10);
    // 0x800879E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800879EC: beq         $t8, $at, L_80087A28
    if (ctx->r24 == ctx->r1) {
        // 0x800879F0: nop
    
            goto L_80087A28;
    }
    // 0x800879F0: nop

L_800879F4:
    // 0x800879F4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800879F8: nop

    // 0x800879FC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80087A00: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80087A04: beq         $at, $zero, L_80087A28
    if (ctx->r1 == 0) {
        // 0x80087A08: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_80087A28;
    }
    // 0x80087A08: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80087A0C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087A10: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80087A14: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x80087A18: lbu         $t0, 0x10($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X10);
    // 0x80087A1C: nop

    // 0x80087A20: bne         $t0, $at, L_800879F4
    if (ctx->r8 != ctx->r1) {
        // 0x80087A24: nop
    
            goto L_800879F4;
    }
    // 0x80087A24: nop

L_80087A28:
    // 0x80087A28: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A2C: nop

    // 0x80087A30: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80087A34: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80087A38: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A3C: nop

    // 0x80087A40: bltz        $t5, L_80087A68
    if (SIGNED(ctx->r13) < 0) {
        // 0x80087A44: nop
    
            goto L_80087A68;
    }
    // 0x80087A44: nop

    // 0x80087A48: jal         0x8008CE48
    // 0x80087A4C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_5;
    // 0x80087A4C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_5:
    // 0x80087A50: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80087A54: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A58: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80087A5C: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x80087A60: b           L_80087AC0
    // 0x80087A64: sb          $t7, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r15;
        goto L_80087AC0;
    // 0x80087A64: sb          $t7, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r15;
L_80087A68:
    // 0x80087A68: jal         0x8008CE48
    // 0x80087A6C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80087A6C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_6:
    // 0x80087A70: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80087A74: nop

    // 0x80087A78: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x80087A7C: nop

    // 0x80087A80: andi        $t0, $t2, 0x800
    ctx->r8 = ctx->r10 & 0X800;
    // 0x80087A84: beq         $t0, $zero, L_80087AB8
    if (ctx->r8 == 0) {
        // 0x80087A88: nop
    
            goto L_80087AB8;
    }
    // 0x80087A88: nop

    // 0x80087A8C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80087A90: nop

    // 0x80087A94: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80087A98: nop

    // 0x80087A9C: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x80087AA0: beq         $t5, $zero, L_80087AB0
    if (ctx->r13 == 0) {
        // 0x80087AA4: nop
    
            goto L_80087AB0;
    }
    // 0x80087AA4: nop

    // 0x80087AA8: b           L_80087B70
    // 0x80087AAC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80087B70;
    // 0x80087AAC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80087AB0:
    // 0x80087AB0: b           L_80087B70
    // 0x80087AB4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_80087B70;
    // 0x80087AB4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80087AB8:
    // 0x80087AB8: b           L_80087B70
    // 0x80087ABC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80087B70;
    // 0x80087ABC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80087AC0:
    // 0x80087AC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80087AC4: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x80087AC8: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x80087ACC: nop

    // 0x80087AD0: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x80087AD4: beq         $t7, $zero, L_80087B54
    if (ctx->r15 == 0) {
        // 0x80087AD8: nop
    
            goto L_80087B54;
    }
    // 0x80087AD8: nop

    // 0x80087ADC: jal         0x8008CE48
    // 0x80087AE0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_7;
    // 0x80087AE0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_7:
    // 0x80087AE4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087AE8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80087AEC: lbu         $t9, 0x10($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X10);
    // 0x80087AF0: nop

    // 0x80087AF4: bne         $t9, $at, L_80087B34
    if (ctx->r25 != ctx->r1) {
        // 0x80087AF8: nop
    
            goto L_80087B34;
    }
    // 0x80087AF8: nop

    // 0x80087AFC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80087B00:
    // 0x80087B00: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80087B04: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80087B08: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80087B0C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80087B10: lbu         $t0, 0x4BEC($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4BEC);
    // 0x80087B14: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80087B18: sb          $t0, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r8;
    // 0x80087B1C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80087B20: nop

    // 0x80087B24: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80087B28: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x80087B2C: bne         $at, $zero, L_80087B00
    if (ctx->r1 != 0) {
        // 0x80087B30: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80087B00;
    }
    // 0x80087B30: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80087B34:
    // 0x80087B34: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80087B38: nop

    // 0x80087B3C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80087B40: nop

    // 0x80087B44: ori         $t1, $t7, 0x200
    ctx->r9 = ctx->r15 | 0X200;
    // 0x80087B48: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x80087B4C: b           L_80087B70
    // 0x80087B50: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087B70;
    // 0x80087B50: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80087B54:
    // 0x80087B54: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80087B58: nop

    // 0x80087B5C: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x80087B60: b           L_80087B70
    // 0x80087B64: nop

        goto L_80087B70;
    // 0x80087B64: nop

    // 0x80087B68: b           L_80087B70
    // 0x80087B6C: nop

        goto L_80087B70;
    // 0x80087B6C: nop

L_80087B70:
    // 0x80087B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80087B78: jr          $ra
    // 0x80087B7C: nop

    return;
    // 0x80087B7C: nop

;}
RECOMP_FUNC void func_8001CC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CC84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001CC88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CC8C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CC90: nop

    // 0x8001CC94: bltz        $t6, L_8001CCF0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001CC98: nop
    
            goto L_8001CCF0;
    }
    // 0x8001CC98: nop

    // 0x8001CC9C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CCA0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CCA4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CCA8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001CCAC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CCB0: nop

    // 0x8001CCB4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CCB8: bne         $t0, $zero, L_8001CCD8
    if (ctx->r8 != 0) {
        // 0x8001CCBC: nop
    
            goto L_8001CCD8;
    }
    // 0x8001CCBC: nop

    // 0x8001CCC0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001CCC4: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001CCC8: nop

    // 0x8001CCCC: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001CCD0: beq         $t2, $zero, L_8001CCF0
    if (ctx->r10 == 0) {
        // 0x8001CCD4: nop
    
            goto L_8001CCF0;
    }
    // 0x8001CCD4: nop

L_8001CCD8:
    // 0x8001CCD8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001CCDC: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001CCE0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001CCE4: nop

    // 0x8001CCE8: xori        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 ^ 0X4000;
    // 0x8001CCEC: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
L_8001CCF0:
    // 0x8001CCF0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8001CCF4: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8001CCF8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8001CCFC: nop

    // 0x8001CD00: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x8001CD04: beq         $t9, $zero, L_8001CD20
    if (ctx->r25 == 0) {
        // 0x8001CD08: nop
    
            goto L_8001CD20;
    }
    // 0x8001CD08: nop

    // 0x8001CD0C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CD10: jal         0x8008ECE4
    // 0x8001CD14: addiu       $a0, $a0, -0x26D4
    ctx->r4 = ADD32(ctx->r4, -0X26D4);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CD14: addiu       $a0, $a0, -0x26D4
    ctx->r4 = ADD32(ctx->r4, -0X26D4);
    after_0:
    // 0x8001CD18: b           L_8001CD2C
    // 0x8001CD1C: nop

        goto L_8001CD2C;
    // 0x8001CD1C: nop

L_8001CD20:
    // 0x8001CD20: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CD24: jal         0x8008ECE4
    // 0x8001CD28: addiu       $a0, $a0, -0x26CC
    ctx->r4 = ADD32(ctx->r4, -0X26CC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CD28: addiu       $a0, $a0, -0x26CC
    ctx->r4 = ADD32(ctx->r4, -0X26CC);
    after_1:
L_8001CD2C:
    // 0x8001CD2C: b           L_8001CD3C
    // 0x8001CD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CD3C;
    // 0x8001CD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CD34: b           L_8001CD3C
    // 0x8001CD38: nop

        goto L_8001CD3C;
    // 0x8001CD38: nop

L_8001CD3C:
    // 0x8001CD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CD40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CD44: jr          $ra
    // 0x8001CD48: nop

    return;
    // 0x8001CD48: nop

;}
RECOMP_FUNC void func_80076D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D50: jal         0x80061348
    // 0x80076D54: addiu       $a0, $zero, 0x552
    ctx->r4 = ADD32(0, 0X552);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076D54: addiu       $a0, $zero, 0x552
    ctx->r4 = ADD32(0, 0X552);
    after_0:
    // 0x80076D58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076D5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076D60: b           L_80076D70
    // 0x80076D64: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80076D70;
    // 0x80076D64: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076D68: b           L_80076D70
    // 0x80076D6C: nop

        goto L_80076D70;
    // 0x80076D6C: nop

L_80076D70:
    // 0x80076D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076D78: jr          $ra
    // 0x80076D7C: nop

    return;
    // 0x80076D7C: nop

;}
RECOMP_FUNC void func_800637A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800637A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800637A8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800637AC: nop

    // 0x800637B0: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800637B4: nop

    // 0x800637B8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800637BC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800637C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800637C4: beq         $v0, $zero, L_800637E0
    if (ctx->r2 == 0) {
        // 0x800637C8: nop
    
            goto L_800637E0;
    }
    // 0x800637C8: nop

    // 0x800637CC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x800637D0: nop

    // 0x800637D4: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800637D8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800637DC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800637E0:
    // 0x800637E0: jr          $ra
    // 0x800637E4: nop

    return;
    // 0x800637E4: nop

    // 0x800637E8: jr          $ra
    // 0x800637EC: nop

    return;
    // 0x800637EC: nop

    // 0x800637F0: jr          $ra
    // 0x800637F4: nop

    return;
    // 0x800637F4: nop

;}
RECOMP_FUNC void func_80095E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095E78: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80095E7C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80095E80: nop

    // 0x80095E84: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80095E88: sb          $t7, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r15;
    // 0x80095E8C: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x80095E90: nop

    // 0x80095E94: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80095E98: sb          $t9, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r25;
    // 0x80095E9C: lbu         $t0, 0x7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7);
    // 0x80095EA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095EA4: bgez        $t0, L_80095EB8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80095EA8: andi        $t1, $t0, 0x1
        ctx->r9 = ctx->r8 & 0X1;
            goto L_80095EB8;
    }
    // 0x80095EA8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80095EAC: beq         $t1, $zero, L_80095EB8
    if (ctx->r9 == 0) {
        // 0x80095EB0: nop
    
            goto L_80095EB8;
    }
    // 0x80095EB0: nop

    // 0x80095EB4: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_80095EB8:
    // 0x80095EB8: bne         $t1, $at, L_80095EFC
    if (ctx->r9 != ctx->r1) {
        // 0x80095EBC: nop
    
            goto L_80095EFC;
    }
    // 0x80095EBC: nop

    // 0x80095EC0: lbu         $t2, 0x6($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6);
    // 0x80095EC4: nop

    // 0x80095EC8: addiu       $t3, $t2, 0x1F
    ctx->r11 = ADD32(ctx->r10, 0X1F);
    // 0x80095ECC: sb          $t3, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r11;
    // 0x80095ED0: lbu         $t4, 0x6($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X6);
    // 0x80095ED4: nop

    // 0x80095ED8: slti        $at, $t4, 0x7F
    ctx->r1 = SIGNED(ctx->r12) < 0X7F ? 1 : 0;
    // 0x80095EDC: bne         $at, $zero, L_80095EF4
    if (ctx->r1 != 0) {
        // 0x80095EE0: nop
    
            goto L_80095EF4;
    }
    // 0x80095EE0: nop

    // 0x80095EE4: lbu         $t5, 0x6($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X6);
    // 0x80095EE8: nop

    // 0x80095EEC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80095EF0: sb          $t6, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r14;
L_80095EF4:
    // 0x80095EF4: b           L_80095F0C
    // 0x80095EF8: nop

        goto L_80095F0C;
    // 0x80095EF8: nop

L_80095EFC:
    // 0x80095EFC: lbu         $t7, 0x6($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6);
    // 0x80095F00: nop

    // 0x80095F04: addiu       $t8, $t7, 0x7E
    ctx->r24 = ADD32(ctx->r15, 0X7E);
    // 0x80095F08: sb          $t8, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r24;
L_80095F0C:
    // 0x80095F0C: lbu         $t9, 0x7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F10: nop

    // 0x80095F14: addiu       $t0, $t9, -0x21
    ctx->r8 = ADD32(ctx->r25, -0X21);
    // 0x80095F18: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80095F1C: addiu       $t2, $t1, 0x81
    ctx->r10 = ADD32(ctx->r9, 0X81);
    // 0x80095F20: sb          $t2, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r10;
    // 0x80095F24: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F28: nop

    // 0x80095F2C: slti        $at, $t3, 0xA0
    ctx->r1 = SIGNED(ctx->r11) < 0XA0 ? 1 : 0;
    // 0x80095F30: bne         $at, $zero, L_80095F48
    if (ctx->r1 != 0) {
        // 0x80095F34: nop
    
            goto L_80095F48;
    }
    // 0x80095F34: nop

    // 0x80095F38: lbu         $t4, 0x7($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F3C: nop

    // 0x80095F40: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x80095F44: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_80095F48:
    // 0x80095F48: beq         $a0, $zero, L_80095F78
    if (ctx->r4 == 0) {
        // 0x80095F4C: nop
    
            goto L_80095F78;
    }
    // 0x80095F4C: nop

    // 0x80095F50: lbu         $t6, 0x7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F54: nop

    // 0x80095F58: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80095F5C: lbu         $t7, 0x6($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6);
    // 0x80095F60: nop

    // 0x80095F64: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x80095F68: b           L_80095F94
    // 0x80095F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80095F94;
    // 0x80095F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80095F70: b           L_80095F8C
    // 0x80095F74: nop

        goto L_80095F8C;
    // 0x80095F74: nop

L_80095F78:
    // 0x80095F78: lbu         $t8, 0x7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F7C: lbu         $t0, 0x6($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6);
    // 0x80095F80: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80095F84: b           L_80095F94
    // 0x80095F88: or          $v0, $t9, $t0
    ctx->r2 = ctx->r25 | ctx->r8;
        goto L_80095F94;
    // 0x80095F88: or          $v0, $t9, $t0
    ctx->r2 = ctx->r25 | ctx->r8;
L_80095F8C:
    // 0x80095F8C: b           L_80095F94
    // 0x80095F90: nop

        goto L_80095F94;
    // 0x80095F90: nop

L_80095F94:
    // 0x80095F94: jr          $ra
    // 0x80095F98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80095F98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
