#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void MtxUtil_ClearRotation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C197C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1980: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800C1984: bne         $a0, $zero, L_800C199C
    if (ctx->r4 != 0) {
        // 0x800C1988: nop

            goto L_800C199C;
    }
    // 0x800C1988: nop

    // 0x800C198C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1990: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1994: nop

    // 0x800C1998: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
L_800C199C:
    // 0x800C199C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C19A0: nop

    // 0x800C19A4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C19A8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800C19AC: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_800C19B0:
    // 0x800C19B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C19B4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C19B8: nop

    // 0x800C19BC: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C19C0: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C19C4: nop

    // 0x800C19C8: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C19CC: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x800C19D0: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C19D4: nop

    // 0x800C19D8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800C19DC: bgtz        $t3, L_800C19B0
    if (SIGNED(ctx->r11) > 0) {
        // 0x800C19E0: sw          $t3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r11;
            goto L_800C19B0;
    }
    // 0x800C19E0: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800C19E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C19E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C19EC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C19F0: nop

    // 0x800C19F4: swc1        $f6, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f6.u32l;
    // 0x800C19F8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C19FC: nop

    // 0x800C1A00: lwc1        $f12, 0x28($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X28);
    // 0x800C1A04: nop

    // 0x800C1A08: swc1        $f12, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f12.u32l;
    // 0x800C1A0C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C1A10: nop

    // 0x800C1A14: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x800C1A18: b           L_800C1A20
    // 0x800C1A1C: nop

        goto L_800C1A20;
    // 0x800C1A1C: nop

L_800C1A20:
    // 0x800C1A20: jr          $ra
    // 0x800C1A24: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1A24: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_Pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1A28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1A2C: lw          $t6, 0xCD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCD8);
    // 0x800C1A30: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800C1A34: bne         $t6, $at, L_800C1A44
    if (ctx->r14 != ctx->r1) {
        // 0x800C1A38: nop

            goto L_800C1A44;
    }
    // 0x800C1A38: nop

    // 0x800C1A3C: jr          $ra
    // 0x800C1A40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C1A40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1A44:
    // 0x800C1A44: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C1A48: lw          $t7, 0xCD8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCD8);
    // 0x800C1A4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1A50: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C1A54: sw          $t8, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r24;
    // 0x800C1A58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C1A5C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C1A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1A64: addiu       $t0, $t9, -0x40
    ctx->r8 = ADD32(ctx->r25, -0X40);
    // 0x800C1A68: sw          $t0, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r8;
    // 0x800C1A6C: jr          $ra
    // 0x800C1A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C1A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1A74: jr          $ra
    // 0x800C1A78: nop

    return;
    // 0x800C1A78: nop

    // 0x800C1A7C: jr          $ra
    // 0x800C1A80: nop

    return;
    // 0x800C1A80: nop

;}
RECOMP_FUNC void MtxUtil_CopyCurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1A84: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1A88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1A8C: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1A90: nop

    // 0x800C1A94: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800C1A98: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800C1A9C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C1AA0: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800C1AA4:
    // 0x800C1AA4: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C1AA8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C1AAC: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C1AB0: nop

    // 0x800C1AB4: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1AB8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C1ABC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C1AC0: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1AC4: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C1AC8: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C1ACC: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C1AD0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1AD4: nop

    // 0x800C1AD8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800C1ADC: bgtz        $t5, L_800C1AA4
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C1AE0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C1AA4;
    }
    // 0x800C1AE0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C1AE4: b           L_800C1AEC
    // 0x800C1AE8: nop

        goto L_800C1AEC;
    // 0x800C1AE8: nop

L_800C1AEC:
    // 0x800C1AEC: jr          $ra
    // 0x800C1AF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1AF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_SetCurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1AF4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1AF8: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800C1AFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1B00: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1B04: nop

    // 0x800C1B08: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800C1B0C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C1B10: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800C1B14:
    // 0x800C1B14: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C1B18: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C1B1C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C1B20: nop

    // 0x800C1B24: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1B28: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C1B2C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C1B30: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1B34: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C1B38: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C1B3C: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C1B40: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1B44: nop

    // 0x800C1B48: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800C1B4C: bgtz        $t5, L_800C1B14
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C1B50: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C1B14;
    }
    // 0x800C1B50: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C1B54: b           L_800C1B5C
    // 0x800C1B58: nop

        goto L_800C1B5C;
    // 0x800C1B58: nop

L_800C1B5C:
    // 0x800C1B5C: jr          $ra
    // 0x800C1B60: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1B60: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800C1B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1B64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C1B68: bne         $a0, $zero, L_800C1B80
    if (ctx->r4 != 0) {
        // 0x800C1B6C: nop

            goto L_800C1B80;
    }
    // 0x800C1B6C: nop

    // 0x800C1B70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1B74: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1B78: b           L_800C1B84
    // 0x800C1B7C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_800C1B84;
    // 0x800C1B7C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_800C1B80:
    // 0x800C1B80: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
L_800C1B84:
    // 0x800C1B84: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1B88: nop

    // 0x800C1B8C: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x800C1B90: nop

    // 0x800C1B94: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800C1B98: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1B9C: nop

    // 0x800C1BA0: lwc1        $f6, 0x34($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X34);
    // 0x800C1BA4: nop

    // 0x800C1BA8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800C1BAC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1BB0: nop

    // 0x800C1BB4: lwc1        $f8, 0x38($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X38);
    // 0x800C1BB8: nop

    // 0x800C1BBC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800C1BC0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1BC4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C1BC8: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C1BCC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C1BD0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x800C1BD4: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C1BD8: nop

    // 0x800C1BDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C1BE0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800C1BE4: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C1BE8: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C1BEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1BF0: nop

    // 0x800C1BF4: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800C1BF8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C1BFC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800C1C00: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800C1C04: swc1        $f10, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f10.u32l;
    // 0x800C1C08: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1C0C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C1C10: lwc1        $f12, 0x10($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X10);
    // 0x800C1C14: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C1C18: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800C1C1C: lwc1        $f8, 0x18($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X18);
    // 0x800C1C20: nop

    // 0x800C1C24: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C1C28: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800C1C2C: lwc1        $f6, 0x14($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800C1C30: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C1C34: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1C38: nop

    // 0x800C1C3C: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800C1C40: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800C1C44: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800C1C48: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800C1C4C: swc1        $f8, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f8.u32l;
    // 0x800C1C50: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1C54: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C1C58: lwc1        $f14, 0x24($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X24);
    // 0x800C1C5C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C1C60: swc1        $f14, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f14.u32l;
    // 0x800C1C64: lwc1        $f12, 0x20($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800C1C68: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C1C6C: swc1        $f12, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f12.u32l;
    // 0x800C1C70: lwc1        $f16, 0x28($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X28);
    // 0x800C1C74: nop

    // 0x800C1C78: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800C1C7C: nop

    // 0x800C1C80: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C1C84: nop

    // 0x800C1C88: mul.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C1C8C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C1C90: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800C1C94: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800C1C98: swc1        $f8, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f8.u32l;
    // 0x800C1C9C: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C1CA0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1CA4: nop

    // 0x800C1CA8: swc1        $f6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f6.u32l;
    // 0x800C1CAC: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C1CB0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1CB4: nop

    // 0x800C1CB8: swc1        $f16, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f16.u32l;
    // 0x800C1CBC: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800C1CC0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1CC4: nop

    // 0x800C1CC8: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    // 0x800C1CCC: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C1CD0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1CD4: nop

    // 0x800C1CD8: swc1        $f10, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f10.u32l;
    // 0x800C1CDC: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C1CE0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1CE4: nop

    // 0x800C1CE8: swc1        $f4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
    // 0x800C1CEC: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C1CF0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1CF4: nop

    // 0x800C1CF8: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
    // 0x800C1CFC: b           L_800C1D04
    // 0x800C1D00: nop

        goto L_800C1D04;
    // 0x800C1D00: nop

L_800C1D04:
    // 0x800C1D04: jr          $ra
    // 0x800C1D08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C1D08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C1D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1D0C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C1D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1D14: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800C1D18: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800C1D1C: jal         0x800C2F1C
    // 0x800C1D20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x800C1D20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800C1D24: jal         0x800C1D44
    // 0x800C1D28: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800C1D44(rdram, ctx);
        goto after_1;
    // 0x800C1D28: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800C1D2C: b           L_800C1D34
    // 0x800C1D30: nop

        goto L_800C1D34;
    // 0x800C1D30: nop

L_800C1D34:
    // 0x800C1D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1D38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800C1D3C: jr          $ra
    // 0x800C1D40: nop

    return;
    // 0x800C1D40: nop

;}
RECOMP_FUNC void func_800C1D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1D44: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C1D48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1D4C: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1D50: nop

    // 0x800C1D54: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C1D58: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C1D5C: addiu       $t7, $t7, 0xCF0
    ctx->r15 = ADD32(ctx->r15, 0XCF0);
    // 0x800C1D60: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C1D64: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_800C1D68:
    // 0x800C1D68: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1D6C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C1D70: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C1D74: nop

    // 0x800C1D78: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1D7C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C1D80: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C1D84: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1D88: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C1D8C: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x800C1D90: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800C1D94: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1D98: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C1D9C: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C1DA0: nop

    // 0x800C1DA4: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x800C1DA8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DAC: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C1DB0: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C1DB4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C1DB8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C1DBC: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C1DC0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DC4: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C1DC8: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C1DCC: nop

    // 0x800C1DD0: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x800C1DD4: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DD8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C1DDC: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800C1DE0: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1DE4: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C1DE8: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C1DEC: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C1DF0: nop

    // 0x800C1DF4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C1DF8: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800C1DFC: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C1E00: nop

    // 0x800C1E04: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C1E08: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C1E0C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C1E10: nop

    // 0x800C1E14: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C1E18: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800C1E1C: bne         $at, $zero, L_800C1D68
    if (ctx->r1 != 0) {
        // 0x800C1E20: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_800C1D68;
    }
    // 0x800C1E20: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800C1E24: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800C1E28: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E2C: nop

    // 0x800C1E30: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C1E34: nop

    // 0x800C1E38: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800C1E3C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E40: nop

    // 0x800C1E44: lwc1        $f16, 0x4($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800C1E48: nop

    // 0x800C1E4C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800C1E50: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E54: nop

    // 0x800C1E58: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800C1E5C: nop

    // 0x800C1E60: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x800C1E64: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E68: nop

    // 0x800C1E6C: lwc1        $f4, 0x10($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800C1E70: nop

    // 0x800C1E74: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800C1E78: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E7C: nop

    // 0x800C1E80: lwc1        $f6, 0x14($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800C1E84: nop

    // 0x800C1E88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800C1E8C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C1E90: nop

    // 0x800C1E94: lwc1        $f8, 0x18($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X18);
    // 0x800C1E98: nop

    // 0x800C1E9C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800C1EA0: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EA4: nop

    // 0x800C1EA8: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x800C1EAC: nop

    // 0x800C1EB0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800C1EB4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EB8: nop

    // 0x800C1EBC: lwc1        $f16, 0x24($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X24);
    // 0x800C1EC0: nop

    // 0x800C1EC4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800C1EC8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C1ECC: nop

    // 0x800C1ED0: lwc1        $f18, 0x28($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X28);
    // 0x800C1ED4: nop

    // 0x800C1ED8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800C1EDC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EE0: nop

    // 0x800C1EE4: lwc1        $f4, 0x30($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X30);
    // 0x800C1EE8: nop

    // 0x800C1EEC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800C1EF0: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C1EF4: nop

    // 0x800C1EF8: lwc1        $f6, 0x34($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800C1EFC: nop

    // 0x800C1F00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C1F04: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C1F08: nop

    // 0x800C1F0C: lwc1        $f8, 0x38($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X38);
    // 0x800C1F10: nop

    // 0x800C1F14: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800C1F18: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800C1F1C: lw          $t4, 0xCE4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCE4);
    // 0x800C1F20: nop

    // 0x800C1F24: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800C1F28: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800C1F2C: addiu       $t5, $t5, 0xCF0
    ctx->r13 = ADD32(ctx->r13, 0XCF0);
    // 0x800C1F30: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x800C1F34: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800C1F38: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_800C1F3C:
    // 0x800C1F3C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C1F40: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C1F44: lwc1        $f14, 0x10($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X10);
    // 0x800C1F48: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C1F4C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800C1F50: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800C1F54: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C1F58: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C1F5C: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800C1F60: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C1F64: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C1F68: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800C1F6C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800C1F70: nop

    // 0x800C1F74: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800C1F78: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C1F7C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C1F80: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800C1F84: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C1F88: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C1F8C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1F90: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C1F94: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C1F98: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C1F9C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C1FA0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800C1FA4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C1FA8: nop

    // 0x800C1FAC: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800C1FB0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800C1FB4: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C1FB8: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x800C1FBC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C1FC0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C1FC4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1FC8: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1FCC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C1FD0: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C1FD4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C1FD8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C1FDC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C1FE0: nop

    // 0x800C1FE4: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C1FE8: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800C1FEC: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800C1FF0: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800C1FF4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C1FF8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C1FFC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2000: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800C2004: lwc1        $f16, 0x14($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2008: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C200C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C2010: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800C2014: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C2018: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C201C: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800C2020: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800C2024: lwc1        $f18, 0x30($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X30);
    // 0x800C2028: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C202C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C2030: swc1        $f6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f6.u32l;
    // 0x800C2034: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C2038: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C203C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800C2040: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x800C2044: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800C2048: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800C204C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800C2050: nop

    // 0x800C2054: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C2058: bgtz        $t8, L_800C1F3C
    if (SIGNED(ctx->r24) > 0) {
        // 0x800C205C: sw          $t8, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r24;
            goto L_800C1F3C;
    }
    // 0x800C205C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C2060: b           L_800C2068
    // 0x800C2064: nop

        goto L_800C2068;
    // 0x800C2064: nop

L_800C2068:
    // 0x800C2068: jr          $ra
    // 0x800C206C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C206C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800C2070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2070: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C2074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2078: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C207C: nop

    // 0x800C2080: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C2084: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800C2088: nop

    // 0x800C208C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800C2090: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C2094: nop

    // 0x800C2098: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800C209C: nop

    // 0x800C20A0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800C20A4: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C20A8: nop

    // 0x800C20AC: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800C20B0: nop

    // 0x800C20B4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800C20B8: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C20BC: nop

    // 0x800C20C0: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800C20C4: nop

    // 0x800C20C8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800C20CC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C20D0: nop

    // 0x800C20D4: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800C20D8: nop

    // 0x800C20DC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800C20E0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C20E4: nop

    // 0x800C20E8: lwc1        $f18, 0x18($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X18);
    // 0x800C20EC: nop

    // 0x800C20F0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x800C20F4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C20F8: nop

    // 0x800C20FC: lwc1        $f4, 0x20($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800C2100: nop

    // 0x800C2104: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800C2108: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C210C: nop

    // 0x800C2110: lwc1        $f6, 0x24($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X24);
    // 0x800C2114: nop

    // 0x800C2118: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800C211C: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C2120: nop

    // 0x800C2124: lwc1        $f8, 0x28($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X28);
    // 0x800C2128: nop

    // 0x800C212C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800C2130: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C2134: nop

    // 0x800C2138: lwc1        $f10, 0x30($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X30);
    // 0x800C213C: nop

    // 0x800C2140: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800C2144: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C2148: nop

    // 0x800C214C: lwc1        $f16, 0x34($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800C2150: nop

    // 0x800C2154: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800C2158: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C215C: nop

    // 0x800C2160: lwc1        $f18, 0x38($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X38);
    // 0x800C2164: nop

    // 0x800C2168: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800C216C: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800C2170: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2174: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C2178: nop

    // 0x800C217C: addiu       $t9, $t8, -0x40
    ctx->r25 = ADD32(ctx->r24, -0X40);
    // 0x800C2180: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C2184: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_800C2188:
    // 0x800C2188: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C218C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2190: lwc1        $f14, 0x10($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800C2194: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2198: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800C219C: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C21A0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C21A4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C21A8: lwc1        $f4, 0x20($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800C21AC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C21B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C21B4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C21B8: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800C21BC: nop

    // 0x800C21C0: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800C21C4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800C21C8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800C21CC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x800C21D0: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C21D4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C21D8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C21DC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800C21E0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C21E4: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C21E8: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C21EC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C21F0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C21F4: nop

    // 0x800C21F8: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800C21FC: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800C2200: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C2204: swc1        $f4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f4.u32l;
    // 0x800C2208: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C220C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C2210: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2214: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C2218: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C221C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2220: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C2224: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800C2228: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C222C: nop

    // 0x800C2230: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2234: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800C2238: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800C223C: swc1        $f8, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f8.u32l;
    // 0x800C2240: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2244: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C2248: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C224C: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800C2250: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2254: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2258: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800C225C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800C2260: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C2264: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C2268: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800C226C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C2270: lwc1        $f8, 0x30($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X30);
    // 0x800C2274: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C2278: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800C227C: swc1        $f16, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f16.u32l;
    // 0x800C2280: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C2284: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C2288: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C228C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C2290: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800C2294: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C2298: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C229C: nop

    // 0x800C22A0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C22A4: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x800C22A8: bne         $at, $zero, L_800C2188
    if (ctx->r1 != 0) {
        // 0x800C22AC: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_800C2188;
    }
    // 0x800C22AC: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800C22B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C22B4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C22B8: nop

    // 0x800C22BC: swc1        $f10, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f10.u32l;
    // 0x800C22C0: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C22C4: nop

    // 0x800C22C8: lwc1        $f12, 0x20($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X20);
    // 0x800C22CC: nop

    // 0x800C22D0: swc1        $f12, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f12.u32l;
    // 0x800C22D4: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C22D8: nop

    // 0x800C22DC: swc1        $f12, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f12.u32l;
    // 0x800C22E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C22E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C22E8: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C22EC: nop

    // 0x800C22F0: swc1        $f4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f4.u32l;
    // 0x800C22F4: b           L_800C22FC
    // 0x800C22F8: nop

        goto L_800C22FC;
    // 0x800C22F8: nop

L_800C22FC:
    // 0x800C22FC: jr          $ra
    // 0x800C2300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C2300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void MtxUtil_TranslateLocal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2304: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C2308: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x800C230C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2310: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C2314: nop

    // 0x800C2318: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x800C231C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C2320: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800C2324: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800C2328: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C232C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C2330: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800C2334: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C2338: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C233C: lwc1        $f18, 0x20($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X20);
    // 0x800C2340: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C2344: nop

    // 0x800C2348: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C234C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C2350: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C2354: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C2358: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800C235C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x800C2360: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800C2364: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800C2368: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C236C: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800C2370: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C2374: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C2378: lwc1        $f18, 0x24($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X24);
    // 0x800C237C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C2380: nop

    // 0x800C2384: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C2388: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800C238C: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800C2390: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800C2394: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C2398: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
    // 0x800C239C: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800C23A0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C23A4: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800C23A8: lwc1        $f8, 0x18($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X18);
    // 0x800C23AC: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C23B0: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C23B4: lwc1        $f18, 0x28($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X28);
    // 0x800C23B8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C23BC: nop

    // 0x800C23C0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C23C4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C23C8: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800C23CC: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C23D0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800C23D4: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
    // 0x800C23D8: b           L_800C23E0
    // 0x800C23DC: nop

        goto L_800C23E0;
    // 0x800C23DC: nop

L_800C23E0:
    // 0x800C23E0: jr          $ra
    // 0x800C23E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C23E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void MtxUtil_RotateX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C23E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C23EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C23F0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C23F4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C23F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C23FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2400: jal         0x800C1A84
    // 0x800C2404: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_0;
    // 0x800C2404: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    after_0:
    // 0x800C2408: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C240C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2410: lwc1        $f9, -0x1A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A0);
    // 0x800C2414: lwc1        $f8, -0x19C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X19C);
    // 0x800C2418: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C241C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800C2420: jal         0x800C3338
    // 0x800C2424: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_1;
    // 0x800C2424: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800C2428: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800C242C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C2430: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2434: lwc1        $f5, -0x198($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X198);
    // 0x800C2438: lwc1        $f4, -0x194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X194);
    // 0x800C243C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C2440: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C2444: jal         0x800C3070
    // 0x800C2448: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800C2448: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_2:
    // 0x800C244C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C2450: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2454: nop

    // 0x800C2458: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800C245C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C2460: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2464: addiu       $t6, $t6, 0xCF0
    ctx->r14 = ADD32(ctx->r14, 0XCF0);
    // 0x800C2468: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800C246C: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800C2470: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800C2474: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800C2478: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C247C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C2480: nop

    // 0x800C2484: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800C2488: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800C248C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800C2490: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800C2494: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800C2498: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C249C: lwc1        $f20, 0x0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C24A0: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C24A4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C24A8: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C24AC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C24B0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C24B4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800C24B8: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800C24BC: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C24C0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C24C4: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800C24C8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C24CC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C24D0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C24D4: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C24D8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C24DC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C24E0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C24E4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C24E8: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
    // 0x800C24EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C24F0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C24F4: lwc1        $f20, 0x4($t6)
    ctx->f20.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C24F8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C24FC: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2500: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800C2504: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2508: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C250C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C2510: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800C2514: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2518: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C251C: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x800C2520: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2524: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2528: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C252C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C2530: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2534: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2538: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C253C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C2540: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
    // 0x800C2544: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C2548: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C254C: lwc1        $f20, 0x8($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C2550: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2554: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2558: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800C255C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2560: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2564: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C2568: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C256C: mul.s       $f16, $f20, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2570: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C2574: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x800C2578: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C257C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2580: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2584: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2588: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C258C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2590: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C2594: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C2598: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x800C259C: b           L_800C25A4
    // 0x800C25A0: nop

        goto L_800C25A4;
    // 0x800C25A0: nop

L_800C25A4:
    // 0x800C25A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C25A8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C25AC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C25B0: jr          $ra
    // 0x800C25B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C25B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void MtxUtil_RotateY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C25B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C25BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C25C0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C25C4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C25C8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C25CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C25D0: jal         0x800C1A84
    // 0x800C25D4: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_0;
    // 0x800C25D4: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    after_0:
    // 0x800C25D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C25DC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C25E0: lwc1        $f9, -0x190($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X190);
    // 0x800C25E4: lwc1        $f8, -0x18C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X18C);
    // 0x800C25E8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C25EC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800C25F0: jal         0x800C3338
    // 0x800C25F4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_1;
    // 0x800C25F4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800C25F8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800C25FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C2600: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2604: lwc1        $f5, -0x188($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X188);
    // 0x800C2608: lwc1        $f4, -0x184($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X184);
    // 0x800C260C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C2610: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C2614: jal         0x800C3070
    // 0x800C2618: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800C2618: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_2:
    // 0x800C261C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C2620: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2624: nop

    // 0x800C2628: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800C262C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C2630: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2634: addiu       $t6, $t6, 0xCF0
    ctx->r14 = ADD32(ctx->r14, 0XCF0);
    // 0x800C2638: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800C263C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800C2640: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800C2644: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2648: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C264C: nop

    // 0x800C2650: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800C2654: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800C2658: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800C265C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C2660: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C2664: lwc1        $f20, 0x0($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C2668: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C266C: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2670: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C2674: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2678: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C267C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C2680: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800C2684: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2688: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C268C: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x800C2690: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2694: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2698: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C269C: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C26A0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C26A4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C26A8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C26AC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C26B0: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x800C26B4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800C26B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C26BC: lwc1        $f20, 0x4($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C26C0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C26C4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C26C8: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x800C26CC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C26D0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C26D4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C26D8: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800C26DC: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C26E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C26E4: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x800C26E8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C26EC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C26F0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C26F4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C26F8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C26FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2700: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C2704: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C2708: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x800C270C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C2710: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C2714: lwc1        $f20, 0x8($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800C2718: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C271C: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2720: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800C2724: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2728: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C272C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C2730: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C2734: mul.s       $f16, $f20, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2738: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C273C: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x800C2740: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2744: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2748: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C274C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2750: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2754: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2758: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C275C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C2760: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x800C2764: b           L_800C276C
    // 0x800C2768: nop

        goto L_800C276C;
    // 0x800C2768: nop

L_800C276C:
    // 0x800C276C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2770: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C2774: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2778: jr          $ra
    // 0x800C277C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C277C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void MtxUtil_RotateZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2780: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C2784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2788: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C278C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C2790: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C2794: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2798: jal         0x800C1A84
    // 0x800C279C: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_0;
    // 0x800C279C: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    after_0:
    // 0x800C27A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C27A4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C27A8: lwc1        $f9, -0x180($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X180);
    // 0x800C27AC: lwc1        $f8, -0x17C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X17C);
    // 0x800C27B0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C27B4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800C27B8: jal         0x800C3338
    // 0x800C27BC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_1;
    // 0x800C27BC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800C27C0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800C27C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C27C8: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C27CC: lwc1        $f5, -0x178($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X178);
    // 0x800C27D0: lwc1        $f4, -0x174($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X174);
    // 0x800C27D4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C27D8: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C27DC: jal         0x800C3070
    // 0x800C27E0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800C27E0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_2:
    // 0x800C27E4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C27E8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C27EC: nop

    // 0x800C27F0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800C27F4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C27F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C27FC: addiu       $t6, $t6, 0xCF0
    ctx->r14 = ADD32(ctx->r14, 0XCF0);
    // 0x800C2800: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800C2804: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800C2808: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800C280C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2810: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C2814: nop

    // 0x800C2818: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800C281C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800C2820: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800C2824: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C2828: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C282C: lwc1        $f20, 0x0($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C2830: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2834: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2838: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C283C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2840: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2844: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C2848: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800C284C: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2850: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C2854: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x800C2858: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C285C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2860: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2864: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2868: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C286C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2870: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2874: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C2878: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x800C287C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800C2880: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C2884: lwc1        $f20, 0x4($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C2888: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C288C: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2890: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x800C2894: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2898: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C289C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C28A0: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800C28A4: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C28A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C28AC: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x800C28B0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C28B4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C28B8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C28BC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C28C0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C28C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C28C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C28CC: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C28D0: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x800C28D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C28D8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C28DC: lwc1        $f20, 0x8($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800C28E0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C28E4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C28E8: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800C28EC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C28F0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C28F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C28F8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C28FC: mul.s       $f16, $f20, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2900: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C2904: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x800C2908: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C290C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2910: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2914: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2918: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C291C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2920: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C2924: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C2928: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x800C292C: b           L_800C2934
    // 0x800C2930: nop

        goto L_800C2934;
    // 0x800C2930: nop

L_800C2934:
    // 0x800C2934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2938: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C293C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2940: jr          $ra
    // 0x800C2944: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C2944: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void MtxUtil_ScaleAxes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2948: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C294C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800C2950: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2954: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C2958: nop

    // 0x800C295C: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800C2960: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800C2964: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800C2968: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C296C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C2970: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C2974: nop

    // 0x800C2978: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C297C: nop

    // 0x800C2980: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C2984: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800C2988: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C298C: nop

    // 0x800C2990: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C2994: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800C2998: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C299C: nop

    // 0x800C29A0: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C29A4: nop

    // 0x800C29A8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C29AC: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x800C29B0: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800C29B4: nop

    // 0x800C29B8: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x800C29BC: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x800C29C0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C29C4: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C29C8: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800C29CC: nop

    // 0x800C29D0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C29D4: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x800C29D8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C29DC: nop

    // 0x800C29E0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C29E4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C29E8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C29EC: nop

    // 0x800C29F0: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C29F4: nop

    // 0x800C29F8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800C29FC: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800C2A00: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C2A04: nop

    // 0x800C2A08: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800C2A0C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x800C2A10: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C2A14: nop

    // 0x800C2A18: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C2A1C: nop

    // 0x800C2A20: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800C2A24: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
    // 0x800C2A28: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C2A2C: nop

    // 0x800C2A30: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C2A34: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C2A38: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C2A3C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C2A40: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C2A44: nop

    // 0x800C2A48: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C2A4C: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
    // 0x800C2A50: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C2A54: nop

    // 0x800C2A58: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800C2A5C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800C2A60: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C2A64: nop

    // 0x800C2A68: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800C2A6C: nop

    // 0x800C2A70: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800C2A74: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800C2A78: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C2A7C: nop

    // 0x800C2A80: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C2A84: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C2A88: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C2A8C: nop

    // 0x800C2A90: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C2A94: nop

    // 0x800C2A98: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800C2A9C: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x800C2AA0: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C2AA4: nop

    // 0x800C2AA8: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800C2AAC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800C2AB0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C2AB4: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C2AB8: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C2ABC: nop

    // 0x800C2AC0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C2AC4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800C2AC8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C2ACC: nop

    // 0x800C2AD0: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800C2AD4: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800C2AD8: b           L_800C2AE0
    // 0x800C2ADC: nop

        goto L_800C2AE0;
    // 0x800C2ADC: nop

L_800C2AE0:
    // 0x800C2AE0: jr          $ra
    // 0x800C2AE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C2AE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
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
RECOMP_FUNC void MtxUtil_SetCurrentFromMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2B28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2B2C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2B30: lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE4);
    // 0x800C2B34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C2B38: jal         0x800C2F1C
    // 0x800C2B3C: nop

    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x800C2B3C: nop

    after_0:
    // 0x800C2B40: b           L_800C2B48
    // 0x800C2B44: nop

        goto L_800C2B48;
    // 0x800C2B44: nop

L_800C2B48:
    // 0x800C2B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2B50: jr          $ra
    // 0x800C2B54: nop

    return;
    // 0x800C2B54: nop

;}
RECOMP_FUNC void MtxUtil_Copy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2B58: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C2B5C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C2B60: nop

    // 0x800C2B64: bne         $t6, $zero, L_800C2B7C
    if (ctx->r14 != 0) {
        // 0x800C2B68: nop

            goto L_800C2B7C;
    }
    // 0x800C2B68: nop

    // 0x800C2B6C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C2B70: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C2B74: b           L_800C2B80
    // 0x800C2B78: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
        goto L_800C2B80;
    // 0x800C2B78: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
L_800C2B7C:
    // 0x800C2B7C: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
L_800C2B80:
    // 0x800C2B80: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800C2B84: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800C2B88:
    // 0x800C2B88: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C2B8C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C2B90: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C2B94: nop

    // 0x800C2B98: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C2B9C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C2BA0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C2BA4: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C2BA8: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C2BAC: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C2BB0: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C2BB4: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C2BB8: nop

    // 0x800C2BBC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C2BC0: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x800C2BC4: bne         $at, $zero, L_800C2B88
    if (ctx->r1 != 0) {
        // 0x800C2BC8: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C2B88;
    }
    // 0x800C2BC8: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C2BCC: b           L_800C2BD4
    // 0x800C2BD0: nop

        goto L_800C2BD4;
    // 0x800C2BD0: nop

L_800C2BD4:
    // 0x800C2BD4: jr          $ra
    // 0x800C2BD8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C2BD8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_CopyMtxFTranslationRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2BDC: bne         $a1, $zero, L_800C2C44
    if (ctx->r5 != 0) {
        // 0x800C2BE0: nop

            goto L_800C2C44;
    }
    // 0x800C2BE0: nop

    // 0x800C2BE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2BE8: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C2BEC: nop

    // 0x800C2BF0: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x800C2BF4: nop

    // 0x800C2BF8: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x800C2BFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C2C00: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C2C04: nop

    // 0x800C2C08: lwc1        $f6, 0x34($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X34);
    // 0x800C2C0C: nop

    // 0x800C2C10: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800C2C14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2C18: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C2C1C: nop

    // 0x800C2C20: lwc1        $f8, 0x38($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X38);
    // 0x800C2C24: nop

    // 0x800C2C28: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x800C2C2C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C2C30: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C2C34: nop

    // 0x800C2C38: lwc1        $f10, 0x3C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x800C2C3C: b           L_800C2C74
    // 0x800C2C40: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
        goto L_800C2C74;
    // 0x800C2C40: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
L_800C2C44:
    // 0x800C2C44: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800C2C48: nop

    // 0x800C2C4C: swc1        $f16, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f16.u32l;
    // 0x800C2C50: lwc1        $f18, 0x34($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800C2C54: nop

    // 0x800C2C58: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x800C2C5C: lwc1        $f4, 0x38($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800C2C60: nop

    // 0x800C2C64: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x800C2C68: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800C2C6C: nop

    // 0x800C2C70: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
L_800C2C74:
    // 0x800C2C74: jr          $ra
    // 0x800C2C78: nop

    return;
    // 0x800C2C78: nop

    // 0x800C2C7C: jr          $ra
    // 0x800C2C80: nop

    return;
    // 0x800C2C80: nop

;}
RECOMP_FUNC void MtxUtil_CopyOrientation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2C84: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C2C88: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C2C8C: nop

    // 0x800C2C90: bne         $t6, $zero, L_800C2CA8
    if (ctx->r14 != 0) {
        // 0x800C2C94: nop

            goto L_800C2CA8;
    }
    // 0x800C2C94: nop

    // 0x800C2C98: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C2C9C: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C2CA0: b           L_800C2CAC
    // 0x800C2CA4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
        goto L_800C2CAC;
    // 0x800C2CA4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
L_800C2CA8:
    // 0x800C2CA8: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
L_800C2CAC:
    // 0x800C2CAC: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800C2CB0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800C2CB4:
    // 0x800C2CB4: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C2CB8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C2CBC: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C2CC0: nop

    // 0x800C2CC4: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C2CC8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C2CCC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C2CD0: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C2CD4: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C2CD8: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C2CDC: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C2CE0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C2CE4: nop

    // 0x800C2CE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C2CEC: slti        $at, $t5, 0xC
    ctx->r1 = SIGNED(ctx->r13) < 0XC ? 1 : 0;
    // 0x800C2CF0: bne         $at, $zero, L_800C2CB4
    if (ctx->r1 != 0) {
        // 0x800C2CF4: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C2CB4;
    }
    // 0x800C2CF4: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C2CF8: b           L_800C2D00
    // 0x800C2CFC: nop

        goto L_800C2D00;
    // 0x800C2CFC: nop

L_800C2D00:
    // 0x800C2D00: jr          $ra
    // 0x800C2D04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C2D04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void MtxUtil_MtxToMtxF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2D10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2D14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2D18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D1C: nop

    // 0x800C2D20: bne         $t6, $zero, L_800C2D44
    if (ctx->r14 != 0) {
        // 0x800C2D24: nop

            goto L_800C2D44;
    }
    // 0x800C2D24: nop

    // 0x800C2D28: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2D2C: lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE4);
    // 0x800C2D30: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D34: jal         0x800C2F1C
    // 0x800C2D38: nop

    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x800C2D38: nop

    after_0:
    // 0x800C2D3C: b           L_800C2D54
    // 0x800C2D40: nop

        goto L_800C2D54;
    // 0x800C2D40: nop

L_800C2D44:
    // 0x800C2D44: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D48: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D4C: jal         0x800C2F1C
    // 0x800C2D50: nop

    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_1;
    // 0x800C2D50: nop

    after_1:
L_800C2D54:
    // 0x800C2D54: b           L_800C2D5C
    // 0x800C2D58: nop

        goto L_800C2D5C;
    // 0x800C2D58: nop

L_800C2D5C:
    // 0x800C2D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2D64: jr          $ra
    // 0x800C2D68: nop

    return;
    // 0x800C2D68: nop

;}
RECOMP_FUNC void MtxUtil_MtxFToMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2D74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2D78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2D7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D80: nop

    // 0x800C2D84: bne         $t6, $zero, L_800C2DA8
    if (ctx->r14 != 0) {
        // 0x800C2D88: nop

            goto L_800C2DA8;
    }
    // 0x800C2D88: nop

    // 0x800C2D8C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2D90: lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE4);
    // 0x800C2D94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D98: jal         0x800C2DD0
    // 0x800C2D9C: nop

    MtxUtil__MtxFToMtx(rdram, ctx);
        goto after_0;
    // 0x800C2D9C: nop

    after_0:
    // 0x800C2DA0: b           L_800C2DB8
    // 0x800C2DA4: nop

        goto L_800C2DB8;
    // 0x800C2DA4: nop

L_800C2DA8:
    // 0x800C2DA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2DAC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2DB0: jal         0x800C2DD0
    // 0x800C2DB4: nop

    MtxUtil__MtxFToMtx(rdram, ctx);
        goto after_1;
    // 0x800C2DB4: nop

    after_1:
L_800C2DB8:
    // 0x800C2DB8: b           L_800C2DC0
    // 0x800C2DBC: nop

        goto L_800C2DC0;
    // 0x800C2DBC: nop

L_800C2DC0:
    // 0x800C2DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2DC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2DC8: jr          $ra
    // 0x800C2DCC: nop

    return;
    // 0x800C2DCC: nop

;}
RECOMP_FUNC void MtxUtil__MtxFToMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2DD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C2DD4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800C2DD8: addiu       $t6, $a1, 0x20
    ctx->r14 = ADD32(ctx->r5, 0X20);
    // 0x800C2DDC: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C2DE0: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800C2DE4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800C2DE8:
    // 0x800C2DE8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800C2DEC:
    // 0x800C2DEC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C2DF0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800C2DF4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C2DF8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800C2DFC: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800C2E00: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C2E04: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C2E08: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800C2E0C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C2E10: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x800C2E14: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C2E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2E1C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800C2E20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C2E24: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C2E28: nop

    // 0x800C2E2C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C2E30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2E34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2E38: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C2E3C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C2E40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C2E44: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800C2E48: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C2E4C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800C2E50: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C2E54: nop

    // 0x800C2E58: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2E5C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C2E60: nop

    // 0x800C2E64: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800C2E68: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2E6C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2E70: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800C2E74: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C2E78: and         $t0, $a2, $at
    ctx->r8 = ctx->r6 & ctx->r1;
    // 0x800C2E7C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800C2E80: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C2E84: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800C2E88: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800C2E8C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800C2E90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C2E94: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C2E98: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x800C2E9C: nop

    // 0x800C2EA0: addiu       $t5, $t2, 0x4
    ctx->r13 = ADD32(ctx->r10, 0X4);
    // 0x800C2EA4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C2EA8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C2EAC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C2EB0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800C2EB4: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800C2EB8: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C2EBC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800C2EC0: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800C2EC4: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x800C2EC8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800C2ECC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C2ED0: nop

    // 0x800C2ED4: addiu       $t2, $t3, 0x4
    ctx->r10 = ADD32(ctx->r11, 0X4);
    // 0x800C2ED8: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x800C2EDC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800C2EE0: nop

    // 0x800C2EE4: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800C2EE8: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800C2EEC: bne         $at, $zero, L_800C2DEC
    if (ctx->r1 != 0) {
        // 0x800C2EF0: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800C2DEC;
    }
    // 0x800C2EF0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800C2EF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C2EF8: nop

    // 0x800C2EFC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800C2F00: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800C2F04: bne         $at, $zero, L_800C2DE8
    if (ctx->r1 != 0) {
        // 0x800C2F08: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_800C2DE8;
    }
    // 0x800C2F08: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800C2F0C: b           L_800C2F14
    // 0x800C2F10: nop

        goto L_800C2F14;
    // 0x800C2F10: nop

L_800C2F14:
    // 0x800C2F14: jr          $ra
    // 0x800C2F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C2F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
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
RECOMP_FUNC void func_800C3064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3064: nop

    // 0x800C3068: nop

    // 0x800C306C: nop

;}
RECOMP_FUNC void MathUtil_Sinf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3070: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3074: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800C3078: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800C307C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C3080: nop

    // 0x800C3084: sra         $t8, $t7, 22
    ctx->r24 = S32(SIGNED(ctx->r15) >> 22);
    // 0x800C3088: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800C308C: slti        $at, $t9, 0xE6
    ctx->r1 = SIGNED(ctx->r25) < 0XE6 ? 1 : 0;
    // 0x800C3090: beq         $at, $zero, L_800C30A4
    if (ctx->r1 == 0) {
        // 0x800C3094: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_800C30A4;
    }
    // 0x800C3094: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800C3098: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C309C: b           L_800C3330
    // 0x800C30A0: nop

        goto L_800C3330;
    // 0x800C30A0: nop

L_800C30A4:
    // 0x800C30A4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C30A8: nop

    // 0x800C30AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C30B0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800C30B4: swc1        $f7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x800C30B8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C30BC: nop

    // 0x800C30C0: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
    // 0x800C30C4: beq         $at, $zero, L_800C3150
    if (ctx->r1 == 0) {
        // 0x800C30C8: nop

            goto L_800C3150;
    }
    // 0x800C30C8: nop

    // 0x800C30CC: lwc1        $f9, 0x20($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C30D0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C30D4: nop

    // 0x800C30D8: mul.d       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f8.d);
    // 0x800C30DC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C30E0: swc1        $f11, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
    // 0x800C30E4: lwc1        $f17, 0x20($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C30E8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C30EC: lwc1        $f19, 0x18($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C30F0: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C30F4: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800C30F8: addiu       $t1, $t1, -0x5568
    ctx->r9 = ADD32(ctx->r9, -0X5568);
    // 0x800C30FC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800C3100: lwc1        $f7, 0x18($t1)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r9, 0X18);
    // 0x800C3104: lwc1        $f6, 0x1C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800C3108: lwc1        $f11, 0x10($t1)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r9, 0X10);
    // 0x800C310C: lwc1        $f10, 0x14($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800C3110: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800C3114: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x800C3118: lwc1        $f10, 0xC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800C311C: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800C3120: lwc1        $f11, 0x8($t1)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r9, 0X8);
    // 0x800C3124: nop

    // 0x800C3128: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x800C312C: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800C3130: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800C3134: lwc1        $f11, 0x0($t1)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r9, 0X0);
    // 0x800C3138: nop

    // 0x800C313C: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x800C3140: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C3144: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x800C3148: b           L_800C3330
    // 0x800C314C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_800C3330;
    // 0x800C314C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_800C3150:
    // 0x800C3150: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800C3154: nop

    // 0x800C3158: slti        $at, $t2, 0x136
    ctx->r1 = SIGNED(ctx->r10) < 0X136 ? 1 : 0;
    // 0x800C315C: beq         $at, $zero, L_800C331C
    if (ctx->r1 == 0) {
        // 0x800C3160: nop

            goto L_800C331C;
    }
    // 0x800C3160: nop

    // 0x800C3164: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3168: lwc1        $f5, -0x5580($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C316C: lwc1        $f4, -0x557C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C3170: lwc1        $f11, 0x20($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3174: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3178: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800C317C: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800C3180: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C3184: nop

    // 0x800C3188: c.le.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d <= ctx->f6.d;
    // 0x800C318C: nop

    // 0x800C3190: bc1f        L_800C31D4
    if (!c1cs) {
        // 0x800C3194: nop

            goto L_800C31D4;
    }
    // 0x800C3194: nop

    // 0x800C3198: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C319C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C31A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C31A4: nop

    // 0x800C31A8: add.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f8.d = ctx->f6.d + ctx->f16.d;
    // 0x800C31AC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800C31B0: nop

    // 0x800C31B4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800C31B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C31BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C31C0: nop

    // 0x800C31C4: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C31C8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800C31CC: b           L_800C3228
    // 0x800C31D0: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
        goto L_800C3228;
    // 0x800C31D0: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
L_800C31D4:
    // 0x800C31D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C31D8: lwc1        $f19, -0x5580($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C31DC: lwc1        $f18, -0x557C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C31E0: lwc1        $f5, 0x20($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C31E4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C31E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C31EC: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x800C31F0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C31F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C31F8: nop

    // 0x800C31FC: sub.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f8.d = ctx->f6.d - ctx->f16.d;
    // 0x800C3200: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800C3204: nop

    // 0x800C3208: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800C320C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C3210: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C3214: nop

    // 0x800C3218: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C321C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800C3220: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800C3224: nop

L_800C3228:
    // 0x800C3228: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C322C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3230: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C3234: lwc1        $f7, -0x5578($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5578);
    // 0x800C3238: cvt.d.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
    // 0x800C323C: lwc1        $f6, -0x5574($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5574);
    // 0x800C3240: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3244: mul.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800C3248: lwc1        $f5, -0x5570($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X5570);
    // 0x800C324C: lwc1        $f4, -0x556C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X556C);
    // 0x800C3250: lwc1        $f9, 0x20($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3254: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3258: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C325C: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x800C3260: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800C3264: swc1        $f19, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x800C3268: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800C326C: mul.d       $f16, $f8, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f8.d);
    // 0x800C3270: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800C3274: swc1        $f9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C3278: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800C327C: swc1        $f17, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800C3280: lwc1        $f19, 0x20($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3284: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3288: lwc1        $f5, 0x18($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C328C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3290: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C3294: addiu       $t6, $t6, -0x5568
    ctx->r14 = ADD32(ctx->r14, -0X5568);
    // 0x800C3298: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C329C: lwc1        $f7, 0x18($t6)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r14, 0X18);
    // 0x800C32A0: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800C32A4: lwc1        $f17, 0x10($t6)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r14, 0X10);
    // 0x800C32A8: lwc1        $f16, 0x14($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800C32AC: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800C32B0: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x800C32B4: lwc1        $f16, 0xC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800C32B8: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800C32BC: lwc1        $f17, 0x8($t6)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r14, 0X8);
    // 0x800C32C0: nop

    // 0x800C32C4: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x800C32C8: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C32CC: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800C32D0: lwc1        $f17, 0x0($t6)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r14, 0X0);
    // 0x800C32D4: nop

    // 0x800C32D8: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x800C32DC: mul.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800C32E0: add.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f4.d + ctx->f18.d;
    // 0x800C32E4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800C32E8: swc1        $f16, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f16.u32l;
    // 0x800C32EC: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C32F0: nop

    // 0x800C32F4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C32F8: beq         $t8, $zero, L_800C330C
    if (ctx->r24 == 0) {
        // 0x800C32FC: nop

            goto L_800C330C;
    }
    // 0x800C32FC: nop

    // 0x800C3300: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C3304: b           L_800C3314
    // 0x800C3308: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
        goto L_800C3314;
    // 0x800C3308: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
L_800C330C:
    // 0x800C330C: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C3310: nop

L_800C3314:
    // 0x800C3314: b           L_800C3330
    // 0x800C3318: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_800C3330;
    // 0x800C3318: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_800C331C:
    // 0x800C331C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C3320: b           L_800C3330
    // 0x800C3324: nop

        goto L_800C3330;
    // 0x800C3324: nop

    // 0x800C3328: b           L_800C3330
    // 0x800C332C: nop

        goto L_800C3330;
    // 0x800C332C: nop

L_800C3330:
    // 0x800C3330: jr          $ra
    // 0x800C3334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C3334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void MathUtil_Cosf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3338: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C333C: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800C3340: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x800C3344: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C3348: nop

    // 0x800C334C: sra         $t8, $t7, 22
    ctx->r24 = S32(SIGNED(ctx->r15) >> 22);
    // 0x800C3350: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800C3354: slti        $at, $t9, 0x136
    ctx->r1 = SIGNED(ctx->r25) < 0X136 ? 1 : 0;
    // 0x800C3358: beq         $at, $zero, L_800C3634
    if (ctx->r1 == 0) {
        // 0x800C335C: nop

            goto L_800C3634;
    }
    // 0x800C335C: nop

    // 0x800C3360: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3368: nop

    // 0x800C336C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800C3370: nop

    // 0x800C3374: bc1f        L_800C3384
    if (!c1cs) {
        // 0x800C3378: nop

            goto L_800C3384;
    }
    // 0x800C3378: nop

    // 0x800C337C: b           L_800C3390
    // 0x800C3380: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
        goto L_800C3390;
    // 0x800C3380: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
L_800C3384:
    // 0x800C3384: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3388: nop

    // 0x800C338C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
L_800C3390:
    // 0x800C3390: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x800C3394: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3398: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800C339C: swc1        $f11, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
    // 0x800C33A0: lwc1        $f5, 0x30($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C33A4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C33A8: lwc1        $f7, -0x5580($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C33AC: lwc1        $f6, -0x557C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C33B0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C33B4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C33B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C33BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C33C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C33C4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800C33C8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x800C33CC: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x800C33D0: nop

    // 0x800C33D4: bc1f        L_800C3474
    if (!c1cs) {
        // 0x800C33D8: nop

            goto L_800C3474;
    }
    // 0x800C33D8: nop

    // 0x800C33DC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C33E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C33E4: nop

    // 0x800C33E8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800C33EC: nop

    // 0x800C33F0: bc1f        L_800C3400
    if (!c1cs) {
        // 0x800C33F4: nop

            goto L_800C3400;
    }
    // 0x800C33F4: nop

    // 0x800C33F8: b           L_800C340C
    // 0x800C33FC: mov.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = ctx->f8.fl;
        goto L_800C340C;
    // 0x800C33FC: mov.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = ctx->f8.fl;
L_800C3400:
    // 0x800C3400: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3404: nop

    // 0x800C3408: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f16.fl = -ctx->f16.fl;
L_800C340C:
    // 0x800C340C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3410: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3414: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800C3418: swc1        $f5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x800C341C: lwc1        $f7, 0x30($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C3420: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3424: lwc1        $f11, -0x5580($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C3428: lwc1        $f10, -0x557C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C342C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C3430: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800C3434: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C3438: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C343C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3440: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C3444: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x800C3448: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800C344C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C3450: nop

    // 0x800C3454: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800C3458: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C345C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C3460: nop

    // 0x800C3464: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C3468: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C346C: b           L_800C350C
    // 0x800C3470: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
        goto L_800C350C;
    // 0x800C3470: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
L_800C3474:
    // 0x800C3474: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3478: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C347C: nop

    // 0x800C3480: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800C3484: nop

    // 0x800C3488: bc1f        L_800C3498
    if (!c1cs) {
        // 0x800C348C: nop

            goto L_800C3498;
    }
    // 0x800C348C: nop

    // 0x800C3490: b           L_800C34A4
    // 0x800C3494: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
        goto L_800C34A4;
    // 0x800C3494: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
L_800C3498:
    // 0x800C3498: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C349C: nop

    // 0x800C34A0: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = -ctx->f18.fl;
L_800C34A4:
    // 0x800C34A4: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800C34A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C34AC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800C34B0: swc1        $f9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C34B4: lwc1        $f5, 0x30($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C34B8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C34BC: lwc1        $f11, -0x5580($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C34C0: lwc1        $f10, -0x557C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C34C4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C34C8: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800C34CC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C34D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C34D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C34D8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C34DC: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x800C34E0: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x800C34E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800C34E8: nop

    // 0x800C34EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800C34F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C34F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C34F8: nop

    // 0x800C34FC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800C3500: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800C3504: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C3508: nop

L_800C350C:
    // 0x800C350C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800C3510: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C3514: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800C3518: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C351C: cvt.d.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = CVT_D_W(ctx->f4.u32l);
    // 0x800C3520: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3524: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3528: lwc1        $f5, -0x5578($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X5578);
    // 0x800C352C: lwc1        $f4, -0x5574($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5574);
    // 0x800C3530: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800C3534: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3538: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x800C353C: lwc1        $f7, 0x30($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C3540: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3544: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800C3548: swc1        $f9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C354C: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x800C3550: lwc1        $f6, -0x556C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X556C);
    // 0x800C3554: lwc1        $f7, -0x5570($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5570);
    // 0x800C3558: nop

    // 0x800C355C: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x800C3560: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x800C3564: mul.d       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f8.d);
    // 0x800C3568: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800C356C: swc1        $f9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C3570: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800C3574: swc1        $f7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x800C3578: lwc1        $f5, 0x30($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C357C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3580: lwc1        $f11, 0x28($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800C3584: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C3588: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C358C: addiu       $t3, $t3, -0x5568
    ctx->r11 = ADD32(ctx->r11, -0X5568);
    // 0x800C3590: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800C3594: lwc1        $f7, 0x18($t3)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r11, 0X18);
    // 0x800C3598: lwc1        $f6, 0x1C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800C359C: swc1        $f5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x800C35A0: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800C35A4: mul.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800C35A8: lwc1        $f4, 0x14($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X14);
    // 0x800C35AC: lwc1        $f5, 0x10($t3)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r11, 0X10);
    // 0x800C35B0: nop

    // 0x800C35B4: add.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f6.d + ctx->f4.d;
    // 0x800C35B8: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800C35BC: lwc1        $f6, 0xC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800C35C0: lwc1        $f7, 0x8($t3)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r11, 0X8);
    // 0x800C35C4: nop

    // 0x800C35C8: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
    // 0x800C35CC: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800C35D0: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800C35D4: lwc1        $f5, 0x0($t3)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r11, 0X0);
    // 0x800C35D8: nop

    // 0x800C35DC: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x800C35E0: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C35E4: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800C35E8: lwc1        $f5, 0x0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800C35EC: nop

    // 0x800C35F0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800C35F4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800C35F8: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x800C35FC: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800C3600: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800C3604: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C3608: nop

    // 0x800C360C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800C3610: beq         $t5, $zero, L_800C3624
    if (ctx->r13 == 0) {
        // 0x800C3614: nop

            goto L_800C3624;
    }
    // 0x800C3614: nop

    // 0x800C3618: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C361C: b           L_800C362C
    // 0x800C3620: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
        goto L_800C362C;
    // 0x800C3620: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
L_800C3624:
    // 0x800C3624: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3628: nop

L_800C362C:
    // 0x800C362C: b           L_800C3648
    // 0x800C3630: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_800C3648;
    // 0x800C3630: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_800C3634:
    // 0x800C3634: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C3638: b           L_800C3648
    // 0x800C363C: nop

        goto L_800C3648;
    // 0x800C363C: nop

    // 0x800C3640: b           L_800C3648
    // 0x800C3644: nop

        goto L_800C3648;
    // 0x800C3644: nop

L_800C3648:
    // 0x800C3648: jr          $ra
    // 0x800C364C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C364C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C3650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3654: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3658: lwc1        $f7, -0x170($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X170);
    // 0x800C365C: lwc1        $f6, -0x16C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X16C);
    // 0x800C3660: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C3664: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C3668: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800C366C: swc1        $f10, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f10.u32l;
    // 0x800C3670: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C3674: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800C3678: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C367C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3680: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x800C3684: nop

    // 0x800C3688: bc1f        L_800C36A4
    if (!c1cs) {
        // 0x800C368C: nop

            goto L_800C36A4;
    }
    // 0x800C368C: nop

    // 0x800C3690: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C3694: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3698: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C369C: b           L_800C36BC
    // 0x800C36A0: add.d       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f14.d = ctx->f18.d + ctx->f6.d;
        goto L_800C36BC;
    // 0x800C36A0: add.d       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f14.d = ctx->f18.d + ctx->f6.d;
L_800C36A4:
    // 0x800C36A4: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C36A8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C36AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C36B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C36B4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800C36B8: sub.d       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f14.d = ctx->f10.d - ctx->f16.d;
L_800C36BC:
    // 0x800C36BC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C36C0: nop

    // 0x800C36C4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800C36C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C36CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C36D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C36D4: cvt.w.d     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = CVT_W_D(ctx->f14.d);
    // 0x800C36D8: lwc1        $f11, -0x168($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X168);
    // 0x800C36DC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800C36E0: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800C36E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C36E8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800C36EC: lwc1        $f10, -0x164($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X164);
    // 0x800C36F0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C36F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C36F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C36FC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800C3700: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C3704: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800C3708: lwc1        $f4, -0x15C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X15C);
    // 0x800C370C: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x800C3710: lwc1        $f5, -0x160($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X160);
    // 0x800C3714: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C3718: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800C371C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C3720: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C3724: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800C3728: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C372C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800C3730: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800C3734: mul.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800C3738: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C373C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C3740: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3744: sub.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = ctx->f18.d - ctx->f16.d;
    // 0x800C3748: nop

    // 0x800C374C: div.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x800C3750: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3754: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3758: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C375C: sub.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = ctx->f4.d - ctx->f8.d;
    // 0x800C3760: nop

    // 0x800C3764: div.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x800C3768: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800C376C: lwc1        $f18, -0x154($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X154);
    // 0x800C3770: lwc1        $f19, -0x158($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X158);
    // 0x800C3774: sub.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = ctx->f6.d - ctx->f16.d;
    // 0x800C3778: nop

    // 0x800C377C: div.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x800C3780: add.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = ctx->f10.d + ctx->f18.d;
    // 0x800C3784: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x800C3788: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800C378C: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800C3790: nop

    // 0x800C3794: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800C3798: beq         $t9, $zero, L_800C37EC
    if (ctx->r25 == 0) {
        // 0x800C379C: nop

            goto L_800C37EC;
    }
    // 0x800C379C: nop

    // 0x800C37A0: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C37A4: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800C37A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C37AC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800C37B0: c.eq.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d == ctx->f10.d;
    // 0x800C37B4: nop

    // 0x800C37B8: bc1t        L_800C37D4
    if (c1cs) {
        // 0x800C37BC: nop

            goto L_800C37D4;
    }
    // 0x800C37BC: nop

    // 0x800C37C0: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C37C4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C37C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C37CC: b           L_800C37E4
    // 0x800C37D0: div.d       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f14.d = DIV_D(ctx->f18.d, ctx->f4.d);
        goto L_800C37E4;
    // 0x800C37D0: div.d       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f14.d = DIV_D(ctx->f18.d, ctx->f4.d);
L_800C37D4:
    // 0x800C37D4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C37D8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800C37DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C37E0: nop

L_800C37E4:
    // 0x800C37E4: b           L_800C3800
    // 0x800C37E8: cvt.s.d     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d);
    ctx->f0.fl = CVT_S_D(ctx->f14.d);
        goto L_800C3800;
    // 0x800C37E8: cvt.s.d     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d);
    ctx->f0.fl = CVT_S_D(ctx->f14.d);
L_800C37EC:
    // 0x800C37EC: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C37F0: b           L_800C3800
    // 0x800C37F4: nop

        goto L_800C3800;
    // 0x800C37F4: nop

    // 0x800C37F8: b           L_800C3800
    // 0x800C37FC: nop

        goto L_800C3800;
    // 0x800C37FC: nop

L_800C3800:
    // 0x800C3800: jr          $ra
    // 0x800C3804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C3804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C3808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3808: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C380C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3810: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800C3814: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3818: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C381C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C3820: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3824: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C3828: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C382C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3830: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3834: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x800C3838: jal         0x800C42A0
    // 0x800C383C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C383C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_0:
    // 0x800C3840: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C3844: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C3848: jal         0x800C38F4
    // 0x800C384C: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    func_800C38F4(rdram, ctx);
        goto after_1;
    // 0x800C384C: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    after_1:
    // 0x800C3850: b           L_800C3860
    // 0x800C3854: nop

        goto L_800C3860;
    // 0x800C3854: nop

    // 0x800C3858: b           L_800C3860
    // 0x800C385C: nop

        goto L_800C3860;
    // 0x800C385C: nop

L_800C3860:
    // 0x800C3860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3864: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3868: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C386C: jr          $ra
    // 0x800C3870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C3870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C3874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3874: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C387C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800C3880: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3884: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3888: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C388C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3890: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C3894: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C3898: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C389C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C38A0: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x800C38A4: jal         0x800C42A0
    // 0x800C38A8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C38A8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_0:
    // 0x800C38AC: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C38B0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C38B4: jal         0x800C38F4
    // 0x800C38B8: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    func_800C38F4(rdram, ctx);
        goto after_1;
    // 0x800C38B8: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    after_1:
    // 0x800C38BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C38C0: lwc1        $f5, -0x150($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X150);
    // 0x800C38C4: lwc1        $f4, -0x14C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14C);
    // 0x800C38C8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800C38CC: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x800C38D0: b           L_800C38E0
    // 0x800C38D4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_800C38E0;
    // 0x800C38D4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800C38D8: b           L_800C38E0
    // 0x800C38DC: nop

        goto L_800C38E0;
    // 0x800C38DC: nop

L_800C38E0:
    // 0x800C38E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C38E4: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C38E8: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C38EC: jr          $ra
    // 0x800C38F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C38F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C38F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C38F4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C38F8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800C38FC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3900: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3904: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3908: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C390C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800C3910: nop

    // 0x800C3914: bc1f        L_800C394C
    if (!c1cs) {
        // 0x800C3918: nop

            goto L_800C394C;
    }
    // 0x800C3918: nop

    // 0x800C391C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C3920: nop

    // 0x800C3924: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C3928: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C392C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3930: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C3934: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3938: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x800C393C: nop

    // 0x800C3940: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800C3944: b           L_800C3998
    // 0x800C3948: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
        goto L_800C3998;
    // 0x800C3948: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
L_800C394C:
    // 0x800C394C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C3950: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C3954: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3958: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x800C395C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x800C3960: nop

    // 0x800C3964: bc1f        L_800C3998
    if (!c1cs) {
        // 0x800C3968: nop

            goto L_800C3998;
    }
    // 0x800C3968: nop

    // 0x800C396C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800C3970: nop

    // 0x800C3974: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C3978: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800C397C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3980: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3984: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3988: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800C398C: nop

    // 0x800C3990: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800C3994: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_800C3998:
    // 0x800C3998: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl);
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C399C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C39A0: lwc1        $f5, -0x148($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X148);
    // 0x800C39A4: lwc1        $f4, -0x144($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X144);
    // 0x800C39A8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C39AC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C39B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C39B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C39B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C39BC: nop

    // 0x800C39C0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800C39C4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800C39C8: nop

    // 0x800C39CC: div.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x800C39D0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800C39D4: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x800C39D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C39DC: nop

    // 0x800C39E0: beq         $t0, $zero, L_800C3A18
    if (ctx->r8 == 0) {
        // 0x800C39E4: nop

            goto L_800C3A18;
    }
    // 0x800C39E4: nop

    // 0x800C39E8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800C39EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C39F0: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800C39F4: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800C39F8: lwc1        $f9, -0x140($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X140);
    // 0x800C39FC: lwc1        $f8, -0x13C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X13C);
    // 0x800C3A00: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800C3A04: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3A08: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x800C3A0C: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800C3A10: b           L_800C3A2C
    // 0x800C3A14: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
        goto L_800C3A2C;
    // 0x800C3A14: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_800C3A18:
    // 0x800C3A18: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800C3A1C: b           L_800C3A2C
    // 0x800C3A20: nop

        goto L_800C3A2C;
    // 0x800C3A20: nop

    // 0x800C3A24: b           L_800C3A2C
    // 0x800C3A28: nop

        goto L_800C3A2C;
    // 0x800C3A28: nop

L_800C3A2C:
    // 0x800C3A2C: jr          $ra
    // 0x800C3A30: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C3A30: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C3A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3A34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3A3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800C3A40: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800C3A44: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3A48: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800C3A4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3A50: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C3A54: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x800C3A58: nop

    // 0x800C3A5C: bc1f        L_800C3A70
    if (!c1cs) {
        // 0x800C3A60: nop

            goto L_800C3A70;
    }
    // 0x800C3A60: nop

    // 0x800C3A64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3A68: b           L_800C3BA0
    // 0x800C3A6C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
        goto L_800C3BA0;
    // 0x800C3A6C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_800C3A70:
    // 0x800C3A70: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3A74: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800C3A78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3A7C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3A80: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x800C3A84: nop

    // 0x800C3A88: bc1f        L_800C3B00
    if (!c1cs) {
        // 0x800C3A8C: nop

            goto L_800C3B00;
    }
    // 0x800C3A8C: nop

    // 0x800C3A90: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3A94: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800C3A98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3A9C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3AA0: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x800C3AA4: nop

    // 0x800C3AA8: bc1f        L_800C3AC8
    if (!c1cs) {
        // 0x800C3AAC: nop

            goto L_800C3AC8;
    }
    // 0x800C3AAC: nop

    // 0x800C3AB0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3AB4: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3AB8: jal         0x800C38F4
    // 0x800C3ABC: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    func_800C38F4(rdram, ctx);
        goto after_0;
    // 0x800C3ABC: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_0:
    // 0x800C3AC0: b           L_800C3AF8
    // 0x800C3AC4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_800C3AF8;
    // 0x800C3AC4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_800C3AC8:
    // 0x800C3AC8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3ACC: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3AD0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800C3AD4: jal         0x800C38F4
    // 0x800C3AD8: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    func_800C38F4(rdram, ctx);
        goto after_1;
    // 0x800C3AD8: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    after_1:
    // 0x800C3ADC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3AE0: lwc1        $f11, -0x138($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X138);
    // 0x800C3AE4: lwc1        $f10, -0x134($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X134);
    // 0x800C3AE8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800C3AEC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x800C3AF0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800C3AF4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
L_800C3AF8:
    // 0x800C3AF8: b           L_800C3BA0
    // 0x800C3AFC: nop

        goto L_800C3BA0;
    // 0x800C3AFC: nop

L_800C3B00:
    // 0x800C3B00: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3B04: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C3B08: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C3B0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3B10: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3B14: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800C3B18: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800C3B1C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800C3B20: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3B24: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800C3B28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3B2C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C3B30: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x800C3B34: nop

    // 0x800C3B38: bc1f        L_800C3B70
    if (!c1cs) {
        // 0x800C3B3C: nop

            goto L_800C3B70;
    }
    // 0x800C3B3C: nop

    // 0x800C3B40: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3B44: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3B48: jal         0x800C38F4
    // 0x800C3B4C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    func_800C38F4(rdram, ctx);
        goto after_2;
    // 0x800C3B4C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_2:
    // 0x800C3B50: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3B54: lwc1        $f19, -0x130($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X130);
    // 0x800C3B58: lwc1        $f18, -0x12C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X12C);
    // 0x800C3B5C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800C3B60: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x800C3B64: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800C3B68: b           L_800C3BA0
    // 0x800C3B6C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
        goto L_800C3BA0;
    // 0x800C3B6C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_800C3B70:
    // 0x800C3B70: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3B74: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3B78: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800C3B7C: jal         0x800C38F4
    // 0x800C3B80: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    func_800C38F4(rdram, ctx);
        goto after_3;
    // 0x800C3B80: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_3:
    // 0x800C3B84: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3B88: lwc1        $f7, -0x128($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X128);
    // 0x800C3B8C: lwc1        $f6, -0x124($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X124);
    // 0x800C3B90: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800C3B94: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800C3B98: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800C3B9C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_800C3BA0:
    // 0x800C3BA0: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3BA4: b           L_800C3BB4
    // 0x800C3BA8: nop

        goto L_800C3BB4;
    // 0x800C3BA8: nop

    // 0x800C3BAC: b           L_800C3BB4
    // 0x800C3BB0: nop

        goto L_800C3BB4;
    // 0x800C3BB0: nop

L_800C3BB4:
    // 0x800C3BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3BB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3BBC: jr          $ra
    // 0x800C3BC0: nop

    return;
    // 0x800C3BC0: nop

;}
RECOMP_FUNC void MathUtil_MultiplyVec3fComponents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3BC4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C3BC8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C3BCC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C3BD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C3BD4: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C3BD8: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C3BDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C3BE0: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800C3BE4: nop

    // 0x800C3BE8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C3BEC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800C3BF0: jr          $ra
    // 0x800C3BF4: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    return;
    // 0x800C3BF4: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800C3BF8: jr          $ra
    // 0x800C3BFC: nop

    return;
    // 0x800C3BFC: nop

    // 0x800C3C00: jr          $ra
    // 0x800C3C04: nop

    return;
    // 0x800C3C04: nop

;}
RECOMP_FUNC void MathUtil_GetDistance2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3C08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C3C0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3C10: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C3C14: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C3C18: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800C3C1C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800C3C20: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3C24: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3C28: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C3C2C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3C30: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3C34: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C3C38: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C3C3C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C3C40: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800C3C44: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800C3C48: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C3C4C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x800C3C50: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800C3C54: jal         0x800C42A0
    // 0x800C3C58: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3C58: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_0:
    // 0x800C3C5C: b           L_800C3C6C
    // 0x800C3C60: nop

        goto L_800C3C6C;
    // 0x800C3C60: nop

    // 0x800C3C64: b           L_800C3C6C
    // 0x800C3C68: nop

        goto L_800C3C6C;
    // 0x800C3C68: nop

L_800C3C6C:
    // 0x800C3C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3C70: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3C74: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C3C78: jr          $ra
    // 0x800C3C7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C3C7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void MathUtil_GetDistanceIfWithinRadius(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3C80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C3C84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C3C88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C3C8C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C3C90: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800C3C94: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800C3C98: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800C3C9C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800C3CA0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3CA4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3CA8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C3CAC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3CB0: nop

    // 0x800C3CB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C3CB8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800C3CBC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3CC0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C3CC4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C3CC8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C3CCC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3CD0: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C3CD4: sub.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f22.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800C3CD8: sub.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f20.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800C3CDC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x800C3CE0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C3CE4: swc1        $f20, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f20.u32l;
    // 0x800C3CE8: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800C3CEC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C3CF0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3CF4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C3CF8: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800C3CFC: nop

    // 0x800C3D00: mul.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x800C3D04: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C3D08: jal         0x800C42A0
    // 0x800C3D0C: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3D0C: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_0:
    // 0x800C3D10: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800C3D14: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3D18: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C3D1C: nop

    // 0x800C3D20: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x800C3D24: nop

    // 0x800C3D28: bc1f        L_800C3D3C
    if (!c1cs) {
        // 0x800C3D2C: nop

            goto L_800C3D3C;
    }
    // 0x800C3D2C: nop

    // 0x800C3D30: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3D34: b           L_800C3D54
    // 0x800C3D38: nop

        goto L_800C3D54;
    // 0x800C3D38: nop

L_800C3D3C:
    // 0x800C3D3C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800C3D40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C3D44: b           L_800C3D54
    // 0x800C3D48: nop

        goto L_800C3D54;
    // 0x800C3D48: nop

    // 0x800C3D4C: b           L_800C3D54
    // 0x800C3D50: nop

        goto L_800C3D54;
    // 0x800C3D50: nop

L_800C3D54:
    // 0x800C3D54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C3D58: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3D5C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C3D60: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C3D64: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3D68: jr          $ra
    // 0x800C3D6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C3D6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C3D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3D70: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C3D74: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C3D78: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800C3D7C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800C3D80: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x800C3D84: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x800C3D88: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800C3D8C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800C3D90: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800C3D94: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800C3D98: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800C3D9C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800C3DA0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3DA4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3DA8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C3DAC: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C3DB0: nop

    // 0x800C3DB4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800C3DB8: nop

    // 0x800C3DBC: bc1f        L_800C3E0C
    if (!c1cs) {
        // 0x800C3DC0: nop

            goto L_800C3E0C;
    }
    // 0x800C3DC0: nop

    // 0x800C3DC4: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C3DC8: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C3DCC: nop

    // 0x800C3DD0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800C3DD4: nop

    // 0x800C3DD8: bc1f        L_800C3E0C
    if (!c1cs) {
        // 0x800C3DDC: nop

            goto L_800C3E0C;
    }
    // 0x800C3DDC: nop

    // 0x800C3DE0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C3DE4: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C3DE8: nop

    // 0x800C3DEC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800C3DF0: nop

    // 0x800C3DF4: bc1f        L_800C3E0C
    if (!c1cs) {
        // 0x800C3DF8: nop

            goto L_800C3E0C;
    }
    // 0x800C3DF8: nop

    // 0x800C3DFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3E00: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800C3E04: b           L_800C3EF8
    // 0x800C3E08: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
        goto L_800C3EF8;
    // 0x800C3E08: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
L_800C3E0C:
    // 0x800C3E0C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C3E10: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C3E14: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800C3E18: sub.s       $f26, $f6, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f26.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C3E1C: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x800C3E20: swc1        $f26, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f26.u32l;
    // 0x800C3E24: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C3E28: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C3E2C: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x800C3E30: sub.s       $f24, $f10, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f24.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800C3E34: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x800C3E38: swc1        $f24, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f24.u32l;
    // 0x800C3E3C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C3E40: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C3E44: nop

    // 0x800C3E48: sub.s       $f22, $f18, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f22.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800C3E4C: swc1        $f22, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f22.u32l;
    // 0x800C3E50: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C3E54: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C3E58: mul.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x800C3E5C: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C3E60: mul.s       $f16, $f26, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x800C3E64: nop

    // 0x800C3E68: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800C3E6C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C3E70: jal         0x800C42A0
    // 0x800C3E74: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3E74: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_0:
    // 0x800C3E78: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800C3E7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C3E80: swc1        $f20, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f20.u32l;
    // 0x800C3E84: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x800C3E88: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_800C3E8C:
    // 0x800C3E8C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800C3E90: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C3E94: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C3E98: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x800C3E9C: lwc1        $f10, 0x50($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X50);
    // 0x800C3EA0: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800C3EA4: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800C3EA8: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x800C3EAC: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x800C3EB0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800C3EB4: nop

    // 0x800C3EB8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C3EBC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800C3EC0: bne         $at, $zero, L_800C3E8C
    if (ctx->r1 != 0) {
        // 0x800C3EC4: sw          $t8, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r24;
            goto L_800C3E8C;
    }
    // 0x800C3EC4: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800C3EC8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C3ECC: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800C3ED0: nop

    // 0x800C3ED4: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x800C3ED8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C3EDC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800C3EE0: nop

    // 0x800C3EE4: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x800C3EE8: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C3EEC: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800C3EF0: nop

    // 0x800C3EF4: swc1        $f18, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f18.u32l;
L_800C3EF8:
    // 0x800C3EF8: b           L_800C3F00
    // 0x800C3EFC: nop

        goto L_800C3F00;
    // 0x800C3EFC: nop

L_800C3F00:
    // 0x800C3F00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C3F04: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3F08: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C3F0C: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C3F10: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3F14: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3F18: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3F1C: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800C3F20: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C3F24: jr          $ra
    // 0x800C3F28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800C3F28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800C3F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3F2C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C3F30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C3F34: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800C3F38: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3F3C: nop

    // 0x800C3F40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C3F44: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C3F48: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800C3F4C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800C3F50: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800C3F54: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3F58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3F5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3F60: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x800C3F64: nop

    // 0x800C3F68: bc1t        L_800C4060
    if (c1cs) {
        // 0x800C3F6C: nop

            goto L_800C4060;
    }
    // 0x800C3F6C: nop

    // 0x800C3F70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C3F74: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3F78: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3F7C: nop

    // 0x800C3F80: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800C3F84: nop

    // 0x800C3F88: bc1f        L_800C4028
    if (!c1cs) {
        // 0x800C3F8C: nop

            goto L_800C4028;
    }
    // 0x800C3F8C: nop

    // 0x800C3F90: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3F94: nop

    // 0x800C3F98: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800C3F9C: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800C3FA0: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3FA4: nop

    // 0x800C3FA8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800C3FAC: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800C3FB0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FB4: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3FB8: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800C3FBC: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C3FC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C3FC4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800C3FC8: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800C3FCC: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FD0: nop

    // 0x800C3FD4: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800C3FD8: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x800C3FDC: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FE0: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3FE4: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C3FE8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C3FEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C3FF0: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C3FF4: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x800C3FF8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FFC: nop

    // 0x800C4000: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C4004: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800C4008: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800C400C: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C4010: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C4014: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800C4018: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C401C: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800C4020: b           L_800C4058
    // 0x800C4024: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
        goto L_800C4058;
    // 0x800C4024: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_800C4028:
    // 0x800C4028: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C402C: nop

    // 0x800C4030: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800C4034: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800C4038: nop

    // 0x800C403C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800C4040: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C4044: nop

    // 0x800C4048: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x800C404C: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800C4050: nop

    // 0x800C4054: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
L_800C4058:
    // 0x800C4058: b           L_800C4070
    // 0x800C405C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C4070;
    // 0x800C405C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C4060:
    // 0x800C4060: b           L_800C4070
    // 0x800C4064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C4070;
    // 0x800C4064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C4068: b           L_800C4070
    // 0x800C406C: nop

        goto L_800C4070;
    // 0x800C406C: nop

L_800C4070:
    // 0x800C4070: jr          $ra
    // 0x800C4074: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C4074: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C4078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4078: nop

    // 0x800C407C: nop

;}
RECOMP_FUNC void func_800C4154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4154: nop

    // 0x800C4158: nop

    // 0x800C415C: nop

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
RECOMP_FUNC void func_800C426C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C426C: nop

;}
RECOMP_FUNC void func_800C4298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4298: nop

    // 0x800C429C: nop

;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42A0: jr          $ra
    // 0x800C42A4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800C42A4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void func_800C42A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42A8: nop

    // 0x800C42AC: nop

;}
RECOMP_FUNC void func_800C42DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42DC: nop

;}
RECOMP_FUNC void func_800C4468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4468: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C446C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4470: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C4474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C4478: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800C447C: jal         0x800CC000
    // 0x800C4480: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    __osViGetCurrentContext_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4480: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_0:
    // 0x800C4484: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800C4488: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800C448C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4490: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800C4494: bne         $t7, $zero, L_800C44A8
    if (ctx->r15 != 0) {
        // 0x800C4498: sh          $t7, -0x590($at)
        MEM_H(-0X590, ctx->r1) = ctx->r15;
            goto L_800C44A8;
    }
    // 0x800C4498: sh          $t7, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r15;
    // 0x800C449C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C44A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C44A4: sh          $t8, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r24;
L_800C44A8:
    // 0x800C44A8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800C44AC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_800C44B0:
    // 0x800C44B0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C44B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800C44B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C44BC: jal         0x800C4C40
    // 0x800C44C0: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800C44C0: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    after_1:
    // 0x800C44C4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C44C8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800C44CC: lhu         $s0, 0x0($t1)
    ctx->r16 = MEM_HU(ctx->r9, 0X0);
    // 0x800C44D0: beq         $s0, $at, L_800C44E8
    if (ctx->r16 == ctx->r1) {
        // 0x800C44D4: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_800C44E8;
    }
    // 0x800C44D4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800C44D8: beq         $s0, $at, L_800C45F8
    if (ctx->r16 == ctx->r1) {
        // 0x800C44DC: nop

            goto L_800C45F8;
    }
    // 0x800C44DC: nop

    // 0x800C44E0: b           L_800C44B0
    // 0x800C44E4: nop

        goto L_800C44B0;
    // 0x800C44E4: nop

L_800C44E8:
    // 0x800C44E8: jal         0x800CC010
    // 0x800C44EC: nop

    __osViSwapContext_recomp(rdram, ctx);
        goto after_2;
    // 0x800C44EC: nop

    after_2:
    // 0x800C44F0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800C44F4: lhu         $t2, -0x590($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X590);
    // 0x800C44F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C44FC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800C4500: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800C4504: bne         $t4, $zero, L_800C4548
    if (ctx->r12 != 0) {
        // 0x800C4508: sh          $t3, -0x590($at)
        MEM_H(-0X590, ctx->r1) = ctx->r11;
            goto L_800C4548;
    }
    // 0x800C4508: sh          $t3, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r11;
    // 0x800C450C: jal         0x800CC000
    // 0x800C4510: nop

    __osViGetCurrentContext_recomp(rdram, ctx);
        goto after_3;
    // 0x800C4510: nop

    after_3:
    // 0x800C4514: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800C4518: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800C451C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800C4520: beq         $t6, $zero, L_800C4538
    if (ctx->r14 == 0) {
        // 0x800C4524: nop

            goto L_800C4538;
    }
    // 0x800C4524: nop

    // 0x800C4528: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C452C: lw          $a1, 0x14($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X14);
    // 0x800C4530: jal         0x800C4AA0
    // 0x800C4534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800C4534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_800C4538:
    // 0x800C4538: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800C453C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4540: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x800C4544: sh          $t8, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r24;
L_800C4548:
    // 0x800C4548: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800C454C: lw          $t9, 0xE1C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE1C);
    // 0x800C4550: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C4554: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4558: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C455C: beq         $t1, $zero, L_800C4590
    if (ctx->r9 == 0) {
        // 0x800C4560: sw          $t0, 0xE1C($at)
        MEM_W(0XE1C, ctx->r1) = ctx->r8;
            goto L_800C4590;
    }
    // 0x800C4560: sw          $t0, 0xE1C($at)
    MEM_W(0XE1C, ctx->r1) = ctx->r8;
    // 0x800C4564: jal         0x800CBBB0
    // 0x800C4568: nop

    osGetCount_recomp(rdram, ctx);
        goto after_5;
    // 0x800C4568: nop

    after_5:
    // 0x800C456C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C4570: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C4574: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800C4578: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C457C: sw          $t4, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = ctx->r12;
    // 0x800C4580: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4584: or          $t5, $t2, $zero
    ctx->r13 = ctx->r10 | 0;
    // 0x800C4588: sw          $t5, 0xE14($at)
    MEM_W(0XE14, ctx->r1) = ctx->r13;
    // 0x800C458C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_800C4590:
    // 0x800C4590: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800C4594: lw          $t3, 0xE18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE18);
    // 0x800C4598: jal         0x800CBBB0
    // 0x800C459C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    osGetCount_recomp(rdram, ctx);
        goto after_6;
    // 0x800C459C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_6:
    // 0x800C45A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C45A4: sw          $v0, 0xE18($at)
    MEM_W(0XE18, ctx->r1) = ctx->r2;
    // 0x800C45A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800C45AC: lw          $t6, 0xE18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE18);
    // 0x800C45B0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C45B4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800C45B8: lw          $t3, 0xE14($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE14);
    // 0x800C45BC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800C45C0: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C45C4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800C45C8: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x800C45CC: lw          $t2, 0xE10($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE10);
    // 0x800C45D0: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800C45D4: sltu        $at, $t5, $t3
    ctx->r1 = ctx->r13 < ctx->r11 ? 1 : 0;
    // 0x800C45D8: addu        $t4, $at, $t0
    ctx->r12 = ADD32(ctx->r1, ctx->r8);
    // 0x800C45DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C45E0: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800C45E4: sw          $t4, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = ctx->r12;
    // 0x800C45E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C45EC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800C45F0: b           L_800C44B0
    // 0x800C45F4: sw          $t5, 0xE14($at)
    MEM_W(0XE14, ctx->r1) = ctx->r13;
        goto L_800C44B0;
    // 0x800C45F4: sw          $t5, 0xE14($at)
    MEM_W(0XE14, ctx->r1) = ctx->r13;
L_800C45F8:
    // 0x800C45F8: jal         0x800CBC4C
    // 0x800C45FC: nop

    __osTimerInterrupt_recomp(rdram, ctx);
        goto after_7;
    // 0x800C45FC: nop

    after_7:
    // 0x800C4600: b           L_800C44B0
    // 0x800C4604: nop

        goto L_800C44B0;
    // 0x800C4604: nop

    // 0x800C4608: nop

    // 0x800C460C: nop

    // 0x800C4610: nop

    // 0x800C4614: nop

    // 0x800C4618: nop

    // 0x800C461C: nop

    // 0x800C4620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4624: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C4628: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C462C: jr          $ra
    // 0x800C4630: nop

    return;
    // 0x800C4630: nop

    // 0x800C4634: nop

    // 0x800C4638: nop

    // 0x800C463C: nop

;}
RECOMP_FUNC void func_800C46A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46A8: nop

    // 0x800C46AC: nop

;}
RECOMP_FUNC void func_800C4788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4788: nop

    // 0x800C478C: nop

;}
RECOMP_FUNC void func_800C47FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C47FC: nop

;}
RECOMP_FUNC void func_800C4944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4944: nop

    // 0x800C4948: nop

    // 0x800C494C: nop

;}
RECOMP_FUNC void func_800C4BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4BEC: nop

;}
RECOMP_FUNC void func_800C4C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4C3C: nop

;}
