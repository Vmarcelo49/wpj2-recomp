#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80068C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068C08: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068C0C: nop

    // 0x80068C10: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068C14: nop

    // 0x80068C18: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068C1C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068C20: jr          $ra
    // 0x80068C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068C24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068C28: jr          $ra
    // 0x80068C2C: nop

    return;
    // 0x80068C2C: nop

    // 0x80068C30: jr          $ra
    // 0x80068C34: nop

    return;
    // 0x80068C34: nop

;}
RECOMP_FUNC void func_800AF060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AF064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF068: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AF06C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AF070: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AF074: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x800AF078: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF07C: sh          $t6, -0x490($at)
    MEM_H(-0X490, ctx->r1) = ctx->r14;
    // 0x800AF080: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x800AF084: nop

    // 0x800AF088: addu        $a0, $t7, $t7
    ctx->r4 = ADD32(ctx->r15, ctx->r15);
    // 0x800AF08C: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x800AF090: jal         0x800BC6EC
    // 0x800AF094: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800AF094: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800AF098: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF09C: sw          $v0, -0x784($at)
    MEM_W(-0X784, ctx->r1) = ctx->r2;
    // 0x800AF0A0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800AF0A4: lw          $t9, -0x784($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X784);
    // 0x800AF0A8: nop

    // 0x800AF0AC: bne         $t9, $zero, L_800AF0BC
    if (ctx->r25 != 0) {
        // 0x800AF0B0: nop
    
            goto L_800AF0BC;
    }
    // 0x800AF0B0: nop

    // 0x800AF0B4: b           L_800AF170
    // 0x800AF0B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AF170;
    // 0x800AF0B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AF0BC:
    // 0x800AF0BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF0C0: sb          $zero, 0x448($at)
    MEM_B(0X448, ctx->r1) = 0;
    // 0x800AF0C4: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
L_800AF0C8:
    // 0x800AF0C8: lhu         $t0, 0x2E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF0CC: lhu         $t2, 0x2E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF0D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF0D4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800AF0D8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800AF0DC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800AF0E0: addiu       $t4, $t4, -0x450
    ctx->r12 = ADD32(ctx->r12, -0X450);
    // 0x800AF0E4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800AF0E8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800AF0EC: sw          $zero, -0x44C($at)
    MEM_W(-0X44C, ctx->r1) = 0;
    // 0x800AF0F0: lw          $s1, 0x4($t5)
    ctx->r17 = MEM_W(ctx->r13, 0X4);
    // 0x800AF0F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF0F8: sw          $s1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r17;
    // 0x800AF0FC: lhu         $t6, 0x2E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF100: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF104: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800AF108: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AF10C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800AF110: sw          $s0, -0x46C($at)
    MEM_W(-0X46C, ctx->r1) = ctx->r16;
    // 0x800AF114: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF118: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800AF11C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AF120: sw          $s0, -0x470($at)
    MEM_W(-0X470, ctx->r1) = ctx->r16;
    // 0x800AF124: lhu         $t0, 0x2E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF128: nop

    // 0x800AF12C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800AF130: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800AF134: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800AF138: bne         $at, $zero, L_800AF0C8
    if (ctx->r1 != 0) {
        // 0x800AF13C: sh          $t1, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r9;
            goto L_800AF0C8;
    }
    // 0x800AF13C: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x800AF140: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800AF144: addiu       $t3, $t3, -0x470
    ctx->r11 = ADD32(ctx->r11, -0X470);
    // 0x800AF148: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF14C: sw          $t3, -0x45C($at)
    MEM_W(-0X45C, ctx->r1) = ctx->r11;
    // 0x800AF150: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800AF154: addiu       $t4, $t4, -0x450
    ctx->r12 = ADD32(ctx->r12, -0X450);
    // 0x800AF158: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF15C: sw          $t4, -0x440($at)
    MEM_W(-0X440, ctx->r1) = ctx->r12;
    // 0x800AF160: b           L_800AF170
    // 0x800AF164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AF170;
    // 0x800AF164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF168: b           L_800AF170
    // 0x800AF16C: nop

        goto L_800AF170;
    // 0x800AF16C: nop

L_800AF170:
    // 0x800AF170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF174: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AF178: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AF17C: jr          $ra
    // 0x800AF180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AF180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006D434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D434: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D438: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D43C: nop

    // 0x8006D440: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D444: nop

    // 0x8006D448: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D44C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D450: jr          $ra
    // 0x8006D454: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D454: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D458: jr          $ra
    // 0x8006D45C: nop

    return;
    // 0x8006D45C: nop

    // 0x8006D460: jr          $ra
    // 0x8006D464: nop

    return;
    // 0x8006D464: nop

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
RECOMP_FUNC void func_80064B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064B68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064B6C: nop

    // 0x80064B70: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064B74: nop

    // 0x80064B78: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064B7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064B80: jr          $ra
    // 0x80064B84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064B84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064B88: jr          $ra
    // 0x80064B8C: nop

    return;
    // 0x80064B8C: nop

    // 0x80064B90: jr          $ra
    // 0x80064B94: nop

    return;
    // 0x80064B94: nop

;}
RECOMP_FUNC void func_800960E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800960E8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800960EC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800960F0: addiu       $t7, $t7, -0x42B8
    ctx->r15 = ADD32(ctx->r15, -0X42B8);
    // 0x800960F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800960F8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800960FC: lw          $t9, 0x400($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X400);
    // 0x80096100: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80096104: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80096108: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x8009610C: sw          $t0, 0x400($t2)
    MEM_W(0X400, ctx->r10) = ctx->r8;
    // 0x80096110: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096114: lw          $t3, -0x2878($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2878);
    // 0x80096118: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8009611C: addiu       $t4, $t4, -0x28B8
    ctx->r12 = ADD32(ctx->r12, -0X28B8);
    // 0x80096120: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80096124: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80096128: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8009612C: beq         $at, $zero, L_80096158
    if (ctx->r1 == 0) {
        // 0x80096130: nop
    
            goto L_80096158;
    }
    // 0x80096130: nop

    // 0x80096134: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80096138: lw          $t8, -0x2878($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2878);
    // 0x8009613C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096140: lw          $t1, -0x4CD8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4CD8);
    // 0x80096144: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096148: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8009614C: sw          $t9, -0x2878($at)
    MEM_W(-0X2878, ctx->r1) = ctx->r25;
    // 0x80096150: b           L_80096170
    // 0x80096154: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
        goto L_80096170;
    // 0x80096154: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_80096158:
    // 0x80096158: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8009615C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80096160: lw          $t0, -0x2878($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2878);
    // 0x80096164: lw          $t7, -0x4CD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CD8);
    // 0x80096168: nop

    // 0x8009616C: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
L_80096170:
    // 0x80096170: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80096174: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096178: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8009617C: lw          $t3, -0x42B8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X42B8);
    // 0x80096180: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096184: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
    // 0x80096188: jr          $ra
    // 0x8009618C: nop

    return;
    // 0x8009618C: nop

    // 0x80096190: jr          $ra
    // 0x80096194: nop

    return;
    // 0x80096194: nop

;}
RECOMP_FUNC void func_80062EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062EC4: jal         0x8005F064
    // 0x80062EC8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062EC8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_0:
    // 0x80062ECC: b           L_80062EDC
    // 0x80062ED0: nop

        goto L_80062EDC;
    // 0x80062ED0: nop

    // 0x80062ED4: b           L_80062EDC
    // 0x80062ED8: nop

        goto L_80062EDC;
    // 0x80062ED8: nop

L_80062EDC:
    // 0x80062EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062EE4: jr          $ra
    // 0x80062EE8: nop

    return;
    // 0x80062EE8: nop

;}
RECOMP_FUNC void func_80066924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006692C: jal         0x80061348
    // 0x80066930: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066930: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80066934: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066938: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006693C: beq         $v0, $zero, L_80066954
    if (ctx->r2 == 0) {
        // 0x80066940: nop
    
            goto L_80066954;
    }
    // 0x80066940: nop

    // 0x80066944: jal         0x80061348
    // 0x80066948: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066948: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006694C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066950: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066954:
    // 0x80066954: b           L_80066964
    // 0x80066958: nop

        goto L_80066964;
    // 0x80066958: nop

    // 0x8006695C: b           L_80066964
    // 0x80066960: nop

        goto L_80066964;
    // 0x80066960: nop

L_80066964:
    // 0x80066964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006696C: jr          $ra
    // 0x80066970: nop

    return;
    // 0x80066970: nop

;}
RECOMP_FUNC void func_80064F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064F20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064F24: nop

    // 0x80064F28: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80064F2C: nop

    // 0x80064F30: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064F34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064F38: jr          $ra
    // 0x80064F3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064F3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064F40: jr          $ra
    // 0x80064F44: nop

    return;
    // 0x80064F44: nop

    // 0x80064F48: jr          $ra
    // 0x80064F4C: nop

    return;
    // 0x80064F4C: nop

;}
RECOMP_FUNC void func_80075694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007569C: jal         0x80061348
    // 0x800756A0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800756A0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x800756A4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800756A8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800756AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800756B0: beq         $v0, $zero, L_80075704
    if (ctx->r2 == 0) {
        // 0x800756B4: nop
    
            goto L_80075704;
    }
    // 0x800756B4: nop

    // 0x800756B8: jal         0x80061348
    // 0x800756BC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800756BC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x800756C0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800756C4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800756C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800756CC: beq         $v0, $zero, L_80075704
    if (ctx->r2 == 0) {
        // 0x800756D0: nop
    
            goto L_80075704;
    }
    // 0x800756D0: nop

    // 0x800756D4: jal         0x80061348
    // 0x800756D8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800756D8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x800756DC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800756E0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800756E4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800756E8: beq         $v0, $zero, L_80075704
    if (ctx->r2 == 0) {
        // 0x800756EC: nop
    
            goto L_80075704;
    }
    // 0x800756EC: nop

    // 0x800756F0: jal         0x80061348
    // 0x800756F4: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800756F4: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x800756F8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800756FC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075700: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075704:
    // 0x80075704: b           L_80075714
    // 0x80075708: nop

        goto L_80075714;
    // 0x80075708: nop

    // 0x8007570C: b           L_80075714
    // 0x80075710: nop

        goto L_80075714;
    // 0x80075710: nop

L_80075714:
    // 0x80075714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007571C: jr          $ra
    // 0x80075720: nop

    return;
    // 0x80075720: nop

;}
RECOMP_FUNC void func_80067FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067FD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067FDC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067FE0: nop

    // 0x80067FE4: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067FE8: nop

    // 0x80067FEC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067FF0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067FF4: jr          $ra
    // 0x80067FF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067FF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067FFC: jr          $ra
    // 0x80068000: nop

    return;
    // 0x80068000: nop

    // 0x80068004: jr          $ra
    // 0x80068008: nop

    return;
    // 0x80068008: nop

;}
RECOMP_FUNC void func_8006C210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C218: jal         0x8005F064
    // 0x8006C21C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C21C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x8006C220: b           L_8006C230
    // 0x8006C224: nop

        goto L_8006C230;
    // 0x8006C224: nop

    // 0x8006C228: b           L_8006C230
    // 0x8006C22C: nop

        goto L_8006C230;
    // 0x8006C22C: nop

L_8006C230:
    // 0x8006C230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C238: jr          $ra
    // 0x8006C23C: nop

    return;
    // 0x8006C23C: nop

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
RECOMP_FUNC void func_80088B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80088B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088B24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80088B28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80088B2C: jal         0x8008A46C
    // 0x80088B30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80088B30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80088B34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80088B38: jal         0x80089170
    // 0x80088B3C: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80088B3C: nop

    after_1:
    // 0x80088B40: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80088B44: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80088B48: jal         0x800898D8
    // 0x80088B4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800898D8(rdram, ctx);
        goto after_2;
    // 0x80088B4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_2:
    // 0x80088B50: beq         $v0, $zero, L_80088BA0
    if (ctx->r2 == 0) {
        // 0x80088B54: nop
    
            goto L_80088BA0;
    }
    // 0x80088B54: nop

    // 0x80088B58: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80088B5C: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x80088B60: lh          $t9, 0x20($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20);
    // 0x80088B64: lh          $t0, 0x24($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X24);
    // 0x80088B68: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80088B6C: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80088B70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80088B74: bgez        $a1, L_80088B84
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80088B78: sra         $t8, $a1, 1
        ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80088B84;
    }
    // 0x80088B78: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80088B7C: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80088B80: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80088B84:
    // 0x80088B84: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80088B88: bgez        $a2, L_80088B98
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80088B8C: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80088B98;
    }
    // 0x80088B8C: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80088B90: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80088B94: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80088B98:
    // 0x80088B98: jal         0x80089B04
    // 0x80088B9C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_80089B04(rdram, ctx);
        goto after_3;
    // 0x80088B9C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_3:
L_80088BA0:
    // 0x80088BA0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80088BA4: nop

    // 0x80088BA8: lh          $v0, 0x4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X4);
    // 0x80088BAC: b           L_80088BBC
    // 0x80088BB0: nop

        goto L_80088BBC;
    // 0x80088BB0: nop

    // 0x80088BB4: b           L_80088BBC
    // 0x80088BB8: nop

        goto L_80088BBC;
    // 0x80088BB8: nop

L_80088BBC:
    // 0x80088BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088BC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80088BC4: jr          $ra
    // 0x80088BC8: nop

    return;
    // 0x80088BC8: nop

;}
RECOMP_FUNC void func_8006BA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA98: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BA9C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BAA0: nop

    // 0x8006BAA4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BAA8: nop

    // 0x8006BAAC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006BAB0: jr          $ra
    // 0x8006BAB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BAB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BAB8: jr          $ra
    // 0x8006BABC: nop

    return;
    // 0x8006BABC: nop

    // 0x8006BAC0: jr          $ra
    // 0x8006BAC4: nop

    return;
    // 0x8006BAC4: nop

;}
RECOMP_FUNC void func_80076FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076FC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076FD0: jal         0x80061348
    // 0x80076FD4: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076FD4: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80076FD8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076FDC: b           L_80076FEC
    // 0x80076FE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076FEC;
    // 0x80076FE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076FE4: b           L_80076FEC
    // 0x80076FE8: nop

        goto L_80076FEC;
    // 0x80076FE8: nop

L_80076FEC:
    // 0x80076FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076FF4: jr          $ra
    // 0x80076FF8: nop

    return;
    // 0x80076FF8: nop

;}
RECOMP_FUNC void func_800780C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800780C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800780C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800780C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800780CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800780D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800780D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800780D8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800780DC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800780E0: lh          $t7, 0x14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X14);
    // 0x800780E4: nop

    // 0x800780E8: bne         $t7, $at, L_800780F8
    if (ctx->r15 != ctx->r1) {
        // 0x800780EC: nop
    
            goto L_800780F8;
    }
    // 0x800780EC: nop

    // 0x800780F0: b           L_80078158
    // 0x800780F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078158;
    // 0x800780F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800780F8:
    // 0x800780F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800780FC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80078100: lh          $a3, 0x14($t8)
    ctx->r7 = MEM_H(ctx->r24, 0X14);
    // 0x80078104: lw          $a2, 0xA0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XA0);
    // 0x80078108: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007810C: lhu         $t9, 0x42($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X42);
    // 0x80078110: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80078114: addiu       $a1, $t8, 0x20
    ctx->r5 = ADD32(ctx->r24, 0X20);
    // 0x80078118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007811C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80078120: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80078124: jal         0x80078628
    // 0x80078128: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80078628(rdram, ctx);
        goto after_0;
    // 0x80078128: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x8007812C: bne         $v0, $zero, L_80078148
    if (ctx->r2 != 0) {
        // 0x80078130: nop
    
            goto L_80078148;
    }
    // 0x80078130: nop

    // 0x80078134: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078138: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007813C: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x80078140: b           L_80078158
    // 0x80078144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078158;
    // 0x80078144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078148:
    // 0x80078148: b           L_80078158
    // 0x8007814C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078158;
    // 0x8007814C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078150: b           L_80078158
    // 0x80078154: nop

        goto L_80078158;
    // 0x80078154: nop

L_80078158:
    // 0x80078158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007815C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80078160: jr          $ra
    // 0x80078164: nop

    return;
    // 0x80078164: nop

;}
RECOMP_FUNC void func_80065ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065AC4: jal         0x80061488
    // 0x80065AC8: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065AC8: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065ACC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065AD0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065AD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065AD8: beq         $v0, $zero, L_80065B00
    if (ctx->r2 == 0) {
        // 0x80065ADC: nop
    
            goto L_80065B00;
    }
    // 0x80065ADC: nop

    // 0x80065AE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065AE4: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065AE8: nop

    // 0x80065AEC: lh          $v0, 0x34($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X34);
    // 0x80065AF0: nop

    // 0x80065AF4: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065AF8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065AFC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065B00:
    // 0x80065B00: b           L_80065B10
    // 0x80065B04: nop

        goto L_80065B10;
    // 0x80065B04: nop

    // 0x80065B08: b           L_80065B10
    // 0x80065B0C: nop

        goto L_80065B10;
    // 0x80065B0C: nop

L_80065B10:
    // 0x80065B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065B18: jr          $ra
    // 0x80065B1C: nop

    return;
    // 0x80065B1C: nop

;}
RECOMP_FUNC void func_80072A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072A10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072A14: nop

    // 0x80072A18: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072A1C: nop

    // 0x80072A20: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072A24: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072A28: jr          $ra
    // 0x80072A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072A30: jr          $ra
    // 0x80072A34: nop

    return;
    // 0x80072A34: nop

    // 0x80072A38: jr          $ra
    // 0x80072A3C: nop

    return;
    // 0x80072A3C: nop

;}
RECOMP_FUNC void func_80023ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023ED4: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80023ED8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80023EDC: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
    // 0x80023EE0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80023EE4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80023EE8: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80023EEC: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x80023EF0: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80023EF4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80023EF8: sh          $zero, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = 0;
    // 0x80023EFC: sh          $zero, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = 0;
    // 0x80023F00: sw          $zero, 0x120($sp)
    MEM_W(0X120, ctx->r29) = 0;
    // 0x80023F04: jal         0x800C1680
    // 0x80023F08: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x80023F08: nop

    after_0:
    // 0x80023F0C: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x80023F10: nop

    // 0x80023F14: lwc1        $f4, 0x1B0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1B0);
    // 0x80023F18: nop

    // 0x80023F1C: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x80023F20: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x80023F24: nop

    // 0x80023F28: lwc1        $f6, 0x1B4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1B4);
    // 0x80023F2C: nop

    // 0x80023F30: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80023F34: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x80023F38: nop

    // 0x80023F3C: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80023F40: nop

    // 0x80023F44: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x80023F48: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x80023F4C: nop

    // 0x80023F50: lw          $t1, 0x210($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X210);
    // 0x80023F54: nop

    // 0x80023F58: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80023F5C: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x80023F60: nop

    // 0x80023F64: lw          $t3, 0x214($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X214);
    // 0x80023F68: nop

    // 0x80023F6C: sw          $t3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r11;
    // 0x80023F70: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023F74: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80023F78: jal         0x8002A0F8
    // 0x80023F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_1;
    // 0x80023F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80023F80: sh          $v0, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r2;
    // 0x80023F84: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80023F88: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80023F8C: lhu         $t5, 0x1042($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1042);
    // 0x80023F90: lhu         $t4, 0x1258($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1258);
    // 0x80023F94: nop

    // 0x80023F98: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80023F9C: sh          $t6, 0x116($sp)
    MEM_H(0X116, ctx->r29) = ctx->r14;
    // 0x80023FA0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80023FA4: lhu         $t7, 0x126E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X126E);
    // 0x80023FA8: nop

    // 0x80023FAC: beq         $t7, $zero, L_8002406C
    if (ctx->r15 == 0) {
        // 0x80023FB0: nop
    
            goto L_8002406C;
    }
    // 0x80023FB0: nop

    // 0x80023FB4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80023FB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80023FBC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80023FC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023FC4: nop

    // 0x80023FC8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80023FCC: swc1        $f8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f8.u32l;
    // 0x80023FD0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80023FD4: swc1        $f8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f8.u32l;
    // 0x80023FD8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80023FDC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80023FE0: beq         $t9, $zero, L_80024034
    if (ctx->r25 == 0) {
        // 0x80023FE4: nop
    
            goto L_80024034;
    }
    // 0x80023FE4: nop

    // 0x80023FE8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80023FEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023FF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80023FF4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80023FF8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80023FFC: nop

    // 0x80024000: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80024004: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80024008: nop

    // 0x8002400C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80024010: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80024014: bne         $t9, $zero, L_8002402C
    if (ctx->r25 != 0) {
        // 0x80024018: nop
    
            goto L_8002402C;
    }
    // 0x80024018: nop

    // 0x8002401C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80024020: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024024: b           L_80024044
    // 0x80024028: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80024044;
    // 0x80024028: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8002402C:
    // 0x8002402C: b           L_80024044
    // 0x80024030: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80024044;
    // 0x80024030: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80024034:
    // 0x80024034: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80024038: nop

    // 0x8002403C: bltz        $t9, L_8002402C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80024040: nop
    
            goto L_8002402C;
    }
    // 0x80024040: nop

L_80024044:
    // 0x80024044: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80024048: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8002404C: sh          $t0, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r8;
    // 0x80024050: sh          $t9, 0x118($sp)
    MEM_H(0X118, ctx->r29) = ctx->r25;
    // 0x80024054: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80024058: lhu         $t1, 0x126E($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X126E);
    // 0x8002405C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024060: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80024064: b           L_800240E4
    // 0x80024068: sh          $t2, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = ctx->r10;
        goto L_800240E4;
    // 0x80024068: sh          $t2, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = ctx->r10;
L_8002406C:
    // 0x8002406C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80024070: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80024074: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80024078: nop

    // 0x8002407C: andi        $t5, $t4, 0x400
    ctx->r13 = ctx->r12 & 0X400;
    // 0x80024080: beq         $t5, $zero, L_80024094
    if (ctx->r13 == 0) {
        // 0x80024084: nop
    
            goto L_80024094;
    }
    // 0x80024084: nop

    // 0x80024088: sh          $zero, 0x118($sp)
    MEM_H(0X118, ctx->r29) = 0;
    // 0x8002408C: b           L_800240BC
    // 0x80024090: sh          $zero, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = 0;
        goto L_800240BC;
    // 0x80024090: sh          $zero, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = 0;
L_80024094:
    // 0x80024094: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80024098: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8002409C: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800240A0: nop

    // 0x800240A4: sh          $t7, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r15;
    // 0x800240A8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800240AC: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800240B0: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x800240B4: nop

    // 0x800240B8: sh          $t9, 0x118($sp)
    MEM_H(0X118, ctx->r29) = ctx->r25;
L_800240BC:
    // 0x800240BC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800240C0: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800240C4: lwc1        $f16, 0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800240C8: nop

    // 0x800240CC: swc1        $f16, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f16.u32l;
    // 0x800240D0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800240D4: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x800240D8: lwc1        $f18, 0x14($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800240DC: nop

    // 0x800240E0: swc1        $f18, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f18.u32l;
L_800240E4:
    // 0x800240E4: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x800240E8: nop

    // 0x800240EC: lh          $t3, 0x22($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X22);
    // 0x800240F0: nop

    // 0x800240F4: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800240F8: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800240FC: nop

    // 0x80024100: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80024104: nop

    // 0x80024108: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x8002410C: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80024110: nop

    // 0x80024114: lh          $t6, 0x24($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X24);
    // 0x80024118: nop

    // 0x8002411C: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
    // 0x80024120: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x80024124: nop

    // 0x80024128: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8002412C: nop

    // 0x80024130: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80024134: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80024138: nop

    // 0x8002413C: lh          $t0, 0x28($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X28);
    // 0x80024140: nop

    // 0x80024144: sh          $t0, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r8;
    // 0x80024148: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8002414C: nop

    // 0x80024150: lh          $t2, 0x2C($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2C);
    // 0x80024154: nop

    // 0x80024158: sh          $t2, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r10;
    // 0x8002415C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80024160: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80024164: nop

    // 0x80024168: beq         $t3, $zero, L_8002420C
    if (ctx->r11 == 0) {
        // 0x8002416C: nop
    
            goto L_8002420C;
    }
    // 0x8002416C: nop

    // 0x80024170: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80024174: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80024178: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8002417C: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80024180: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80024184: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80024188: swc1        $f6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f6.u32l;
    // 0x8002418C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80024190: nop

    // 0x80024194: bc1f        L_800241A4
    if (!c1cs) {
        // 0x80024198: nop
    
            goto L_800241A4;
    }
    // 0x80024198: nop

    // 0x8002419C: b           L_800241AC
    // 0x800241A0: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
        goto L_800241AC;
    // 0x800241A0: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
L_800241A4:
    // 0x800241A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800241A8: sh          $t5, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r13;
L_800241AC:
    // 0x800241AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800241B0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800241B4: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800241B8: addiu       $a1, $t6, 0x4C
    ctx->r5 = ADD32(ctx->r14, 0X4C);
    // 0x800241BC: jal         0x800B3A24
    // 0x800241C0: addiu       $a2, $t6, 0x50
    ctx->r6 = ADD32(ctx->r14, 0X50);
    func_800B3A24(rdram, ctx);
        goto after_2;
    // 0x800241C0: addiu       $a2, $t6, 0x50
    ctx->r6 = ADD32(ctx->r14, 0X50);
    after_2:
    // 0x800241C4: addiu       $t7, $sp, 0xD4
    ctx->r15 = ADD32(ctx->r29, 0XD4);
    // 0x800241C8: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800241CC: nop

    // 0x800241D0: swc1        $f18, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f18.u32l;
    // 0x800241D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800241D8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800241DC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800241E0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800241E4: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
    // 0x800241E8: addiu       $at, $zero, 0x0
    ctx->r1 = ADD32(0, 0X0);
    // 0x800241EC: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x800241F0: xor         $s0, $s0, $t3
    ctx->r16 = ctx->r16 ^ ctx->r11;
    // 0x800241F4: xor         $at, $at, $t2
    ctx->r1 = ctx->r1 ^ ctx->r10;
    // 0x800241F8: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
    // 0x800241FC: sltiu       $s0, $s0, 0x1
    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80024200: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80024204: b           L_80024254
    // 0x80024208: sh          $s0, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r16;
        goto L_80024254;
    // 0x80024208: sh          $s0, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r16;
L_8002420C:
    // 0x8002420C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024210: sh          $zero, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = 0;
    // 0x80024214: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80024218: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002421C: swc1        $f8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f8.u32l;
    // 0x80024220: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80024224: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024228: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002422C: nop

    // 0x80024230: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80024234: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80024238: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002423C: sh          $t4, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r12;
    // 0x80024240: nop

    // 0x80024244: lui         $at, 0xC320
    ctx->r1 = S32(0XC320 << 16);
    // 0x80024248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002424C: nop

    // 0x80024250: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
L_80024254:
    // 0x80024254: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80024258: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8002425C: nop

    // 0x80024260: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80024264: nop

    // 0x80024268: beq         $t6, $zero, L_80024280
    if (ctx->r14 == 0) {
        // 0x8002426C: nop
    
            goto L_80024280;
    }
    // 0x8002426C: nop

    // 0x80024270: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x80024274: nop

    // 0x80024278: bne         $t7, $zero, L_80024288
    if (ctx->r15 != 0) {
        // 0x8002427C: nop
    
            goto L_80024288;
    }
    // 0x8002427C: nop

L_80024280:
    // 0x80024280: sh          $zero, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = 0;
    // 0x80024284: sh          $zero, 0x118($sp)
    MEM_H(0X118, ctx->r29) = 0;
L_80024288:
    // 0x80024288: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002428C: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x80024290: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80024294: bne         $t8, $at, L_800243DC
    if (ctx->r24 != ctx->r1) {
        // 0x80024298: nop
    
            goto L_800243DC;
    }
    // 0x80024298: nop

    // 0x8002429C: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x800242A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800242A4: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x800242A8: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800242AC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800242B0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800242B4: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x800242B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800242BC: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800242C0: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800242C4: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800242C8: nop

    // 0x800242CC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800242D0: nop

    // 0x800242D4: bc1f        L_800242E8
    if (!c1cs) {
        // 0x800242D8: nop
    
            goto L_800242E8;
    }
    // 0x800242D8: nop

    // 0x800242DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800242E0: b           L_800242EC
    // 0x800242E4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
        goto L_800242EC;
    // 0x800242E4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
L_800242E8:
    // 0x800242E8: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_800242EC:
    // 0x800242EC: addiu       $t4, $sp, 0xD4
    ctx->r12 = ADD32(ctx->r29, 0XD4);
    // 0x800242F0: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800242F4: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800242F8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800242FC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80024300: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80024304: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80024308: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002430C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80024310: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80024314: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024318: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002431C: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024320: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80024324: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80024328: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8002432C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80024330: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80024334: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80024338: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8002433C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80024340: jal         0x800C3D70
    // 0x80024344: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    func_800C3D70(rdram, ctx);
        goto after_3;
    // 0x80024344: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    after_3:
    // 0x80024348: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x8002434C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80024350: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80024354: nop

    // 0x80024358: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8002435C: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80024360: nop

    // 0x80024364: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x80024368: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8002436C: nop

    // 0x80024370: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80024374: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x80024378: nop

    // 0x8002437C: sw          $t1, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r9;
    // 0x80024380: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80024384: nop

    // 0x80024388: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x8002438C: lw          $t1, 0x14($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X14);
    // 0x80024390: nop

    // 0x80024394: sw          $t1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r9;
    // 0x80024398: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x8002439C: nop

    // 0x800243A0: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x800243A4: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800243A8: nop

    // 0x800243AC: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x800243B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800243B4: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800243B8: lwc1        $f9, -0x1C40($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1C40);
    // 0x800243BC: lwc1        $f8, -0x1C3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C3C);
    // 0x800243C0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800243C4: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800243C8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800243CC: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x800243D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800243D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800243D8: sh          $t2, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r10;
L_800243DC:
    // 0x800243DC: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800243E0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800243E4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800243E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800243EC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800243F0: sub.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d - ctx->f4.d;
    // 0x800243F4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800243F8: nop

    // 0x800243FC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80024400: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024404: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80024408: nop

    // 0x8002440C: cvt.w.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_D(ctx->f8.d);
    // 0x80024410: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80024414: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80024418: sh          $t9, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r25;
    // 0x8002441C: nop

    // 0x80024420: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024424: sw          $zero, 0x103C($at)
    MEM_W(0X103C, ctx->r1) = 0;
    // 0x80024428: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002442C: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x80024430: nop

    // 0x80024434: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80024438: beq         $at, $zero, L_800244B0
    if (ctx->r1 == 0) {
        // 0x8002443C: nop
    
            goto L_800244B0;
    }
    // 0x8002443C: nop

    // 0x80024440: lh          $t6, 0x13A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X13A);
    // 0x80024444: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80024448: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8002444C: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024450: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80024454: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80024458: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002445C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80024460: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80024464: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80024468: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8002446C: addiu       $a0, $a0, 0x10F8
    ctx->r4 = ADD32(ctx->r4, 0X10F8);
    // 0x80024470: jal         0x800782A8
    // 0x80024474: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800782A8(rdram, ctx);
        goto after_4;
    // 0x80024474: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80024478: beq         $v0, $zero, L_800244B0
    if (ctx->r2 == 0) {
        // 0x8002447C: nop
    
            goto L_800244B0;
    }
    // 0x8002447C: nop

    // 0x80024480: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80024484: lbu         $t8, 0x110E($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X110E);
    // 0x80024488: nop

    // 0x8002448C: ori         $t5, $t8, 0x8000
    ctx->r13 = ctx->r24 | 0X8000;
    // 0x80024490: sh          $t5, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r13;
    // 0x80024494: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80024498: lw          $t7, 0x1110($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1110);
    // 0x8002449C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800244A0: beq         $t7, $zero, L_800244B0
    if (ctx->r15 == 0) {
        // 0x800244A4: sw          $t7, 0x103C($at)
        MEM_W(0X103C, ctx->r1) = ctx->r15;
            goto L_800244B0;
    }
    // 0x800244A4: sw          $t7, 0x103C($at)
    MEM_W(0X103C, ctx->r1) = ctx->r15;
    // 0x800244A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800244AC: sh          $t1, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r9;
L_800244B0:
    // 0x800244B0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800244B4: lbu         $t2, 0xE54($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XE54);
    // 0x800244B8: nop

    // 0x800244BC: bne         $t2, $zero, L_80024748
    if (ctx->r10 != 0) {
        // 0x800244C0: nop
    
            goto L_80024748;
    }
    // 0x800244C0: nop

    // 0x800244C4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800244C8: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x800244CC: nop

    // 0x800244D0: beq         $t3, $zero, L_80024740
    if (ctx->r11 == 0) {
        // 0x800244D4: nop
    
            goto L_80024740;
    }
    // 0x800244D4: nop

    // 0x800244D8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800244DC: addiu       $t9, $t9, 0x5B0
    ctx->r25 = ADD32(ctx->r25, 0X5B0);
    // 0x800244E0: sw          $t9, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r25;
    // 0x800244E4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800244E8: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x800244EC: nop

    // 0x800244F0: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800244F4: beq         $at, $zero, L_80024504
    if (ctx->r1 == 0) {
        // 0x800244F8: nop
    
            goto L_80024504;
    }
    // 0x800244F8: nop

    // 0x800244FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024500: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
L_80024504:
    // 0x80024504: jal         0x80023E50
    // 0x80024508: nop

    func_80023E50(rdram, ctx);
        goto after_5;
    // 0x80024508: nop

    after_5:
    // 0x8002450C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80024510: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80024514: lh          $t6, 0x1B48($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1B48);
    // 0x80024518: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x8002451C: blez        $t6, L_80024740
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80024520: nop
    
            goto L_80024740;
    }
    // 0x80024520: nop

L_80024524:
    // 0x80024524: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80024528: nop

    // 0x8002452C: lh          $t8, 0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X6);
    // 0x80024530: nop

    // 0x80024534: bne         $t8, $zero, L_80024708
    if (ctx->r24 != 0) {
        // 0x80024538: nop
    
            goto L_80024708;
    }
    // 0x80024538: nop

    // 0x8002453C: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80024540: nop

    // 0x80024544: lbu         $t7, 0x10($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X10);
    // 0x80024548: nop

    // 0x8002454C: sh          $t7, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r15;
    // 0x80024550: lh          $t1, 0x13C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X13C);
    // 0x80024554: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80024558: addiu       $t3, $t3, 0x24D8
    ctx->r11 = ADD32(ctx->r11, 0X24D8);
    // 0x8002455C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80024560: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x80024564: lw          $a1, 0x18($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X18);
    // 0x80024568: lw          $a2, 0x1C($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X1C);
    // 0x8002456C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80024570: jal         0x800B35D4
    // 0x80024574: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800B35D4(rdram, ctx);
        goto after_6;
    // 0x80024574: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x80024578: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x8002457C: nop

    // 0x80024580: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80024584: nop

    // 0x80024588: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x8002458C: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x80024590: nop

    // 0x80024594: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80024598: nop

    // 0x8002459C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x800245A0: lui         $at, 0xC304
    ctx->r1 = S32(0XC304 << 16);
    // 0x800245A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800245A8: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800245AC: nop

    // 0x800245B0: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800245B4: nop

    // 0x800245B8: bc1f        L_800245F8
    if (!c1cs) {
        // 0x800245BC: nop
    
            goto L_800245F8;
    }
    // 0x800245BC: nop

    // 0x800245C0: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800245C4: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800245C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800245CC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800245D0: lwc1        $f7, -0x1C38($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1C38);
    // 0x800245D4: lwc1        $f6, -0x1C34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C34);
    // 0x800245D8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800245DC: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x800245E0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800245E4: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    // 0x800245E8: lui         $at, 0xC304
    ctx->r1 = S32(0XC304 << 16);
    // 0x800245EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800245F0: b           L_80024650
    // 0x800245F4: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_80024650;
    // 0x800245F4: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800245F8:
    // 0x800245F8: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x800245FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80024600: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80024604: nop

    // 0x80024608: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8002460C: nop

    // 0x80024610: bc1f        L_80024650
    if (!c1cs) {
        // 0x80024614: nop
    
            goto L_80024650;
    }
    // 0x80024614: nop

    // 0x80024618: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8002461C: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80024620: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024624: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80024628: lwc1        $f5, -0x1C30($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1C30);
    // 0x8002462C: lwc1        $f4, -0x1C2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C2C);
    // 0x80024630: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80024634: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x80024638: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002463C: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x80024640: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x80024644: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80024648: nop

    // 0x8002464C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
L_80024650:
    // 0x80024650: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80024654: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80024658: nop

    // 0x8002465C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80024660: nop

    // 0x80024664: bc1f        L_80024708
    if (!c1cs) {
        // 0x80024668: nop
    
            goto L_80024708;
    }
    // 0x80024668: nop

    // 0x8002466C: lh          $t8, 0x13A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13A);
    // 0x80024670: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80024674: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80024678: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8002467C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80024680: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80024684: nop

    // 0x80024688: bc1f        L_80024708
    if (!c1cs) {
        // 0x8002468C: nop
    
            goto L_80024708;
    }
    // 0x8002468C: nop

    // 0x80024690: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80024694: nop

    // 0x80024698: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8002469C: nop

    // 0x800246A0: bc1f        L_80024708
    if (!c1cs) {
        // 0x800246A4: nop
    
            goto L_80024708;
    }
    // 0x800246A4: nop

    // 0x800246A8: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800246AC: nop

    // 0x800246B0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800246B4: nop

    // 0x800246B8: bc1f        L_80024708
    if (!c1cs) {
        // 0x800246BC: nop
    
            goto L_80024708;
    }
    // 0x800246BC: nop

    // 0x800246C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800246C4: sh          $t5, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r13;
    // 0x800246C8: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800246CC: nop

    // 0x800246D0: lh          $t1, 0x0($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X0);
    // 0x800246D4: nop

    // 0x800246D8: sh          $t1, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r9;
    // 0x800246DC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800246E0: lh          $t2, 0x664($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X664);
    // 0x800246E4: nop

    // 0x800246E8: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800246EC: beq         $at, $zero, L_80024700
    if (ctx->r1 == 0) {
        // 0x800246F0: nop
    
            goto L_80024700;
    }
    // 0x800246F0: nop

    // 0x800246F4: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x800246F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800246FC: sw          $t3, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = ctx->r11;
L_80024700:
    // 0x80024700: b           L_80024740
    // 0x80024704: nop

        goto L_80024740;
    // 0x80024704: nop

L_80024708:
    // 0x80024708: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8002470C: nop

    // 0x80024710: lw          $t4, 0x14($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X14);
    // 0x80024714: nop

    // 0x80024718: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x8002471C: lh          $t6, 0x13E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X13E);
    // 0x80024720: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80024724: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80024728: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x8002472C: sll         $t0, $t8, 16
    ctx->r8 = S32(ctx->r24 << 16);
    // 0x80024730: sra         $t5, $t0, 16
    ctx->r13 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80024734: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80024738: bne         $at, $zero, L_80024524
    if (ctx->r1 != 0) {
        // 0x8002473C: sh          $t8, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r24;
            goto L_80024524;
    }
    // 0x8002473C: sh          $t8, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r24;
L_80024740:
    // 0x80024740: b           L_8002475C
    // 0x80024744: nop

        goto L_8002475C;
    // 0x80024744: nop

L_80024748:
    // 0x80024748: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002474C: lbu         $t1, 0xE54($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XE54);
    // 0x80024750: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024754: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80024758: sb          $t2, 0xE54($at)
    MEM_B(0XE54, ctx->r1) = ctx->r10;
L_8002475C:
    // 0x8002475C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80024760: jal         0x800B2748
    // 0x80024764: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    func_800B2748(rdram, ctx);
        goto after_7;
    // 0x80024764: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    after_7:
    // 0x80024768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002476C: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
    // 0x80024770: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80024774: lh          $t3, 0x11A6($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X11A6);
    // 0x80024778: nop

    // 0x8002477C: bgez        $t3, L_8002479C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80024780: nop
    
            goto L_8002479C;
    }
    // 0x80024780: nop

    // 0x80024784: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80024788: sw          $t9, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r25;
    // 0x8002478C: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80024790: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80024794: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80024798: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
L_8002479C:
    // 0x8002479C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800247A0: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x800247A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800247A8: bne         $t8, $at, L_80024824
    if (ctx->r24 != ctx->r1) {
        // 0x800247AC: nop
    
            goto L_80024824;
    }
    // 0x800247AC: nop

    // 0x800247B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800247B4: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800247B8: nop

    // 0x800247BC: bne         $t0, $zero, L_8002481C
    if (ctx->r8 != 0) {
        // 0x800247C0: nop
    
            goto L_8002481C;
    }
    // 0x800247C0: nop

    // 0x800247C4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800247C8: lh          $t5, 0x664($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X664);
    // 0x800247CC: nop

    // 0x800247D0: bne         $t5, $zero, L_8002481C
    if (ctx->r13 != 0) {
        // 0x800247D4: nop
    
            goto L_8002481C;
    }
    // 0x800247D4: nop

    // 0x800247D8: lh          $t7, 0x134($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X134);
    // 0x800247DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800247E0: beq         $t7, $at, L_8002481C
    if (ctx->r15 == ctx->r1) {
        // 0x800247E4: nop
    
            goto L_8002481C;
    }
    // 0x800247E4: nop

    // 0x800247E8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800247EC: beq         $t7, $at, L_8002481C
    if (ctx->r15 == ctx->r1) {
        // 0x800247F0: nop
    
            goto L_8002481C;
    }
    // 0x800247F0: nop

    // 0x800247F4: addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
    // 0x800247F8: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x800247FC: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80024800: nop

    // 0x80024804: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80024808: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x8002480C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80024810: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80024814: and         $t4, $t9, $at
    ctx->r12 = ctx->r25 & ctx->r1;
    // 0x80024818: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
L_8002481C:
    // 0x8002481C: b           L_80024850
    // 0x80024820: nop

        goto L_80024850;
    // 0x80024820: nop

L_80024824:
    // 0x80024824: lh          $t6, 0x134($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X134);
    // 0x80024828: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002482C: bne         $t6, $at, L_80024850
    if (ctx->r14 != ctx->r1) {
        // 0x80024830: nop
    
            goto L_80024850;
    }
    // 0x80024830: nop

    // 0x80024834: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80024838: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002483C: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x80024840: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80024844: addiu       $at, $zero, -0xF
    ctx->r1 = ADD32(0, -0XF);
    // 0x80024848: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8002484C: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
L_80024850:
    // 0x80024850: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80024854: lh          $t5, 0x66C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X66C);
    // 0x80024858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002485C: bne         $t5, $at, L_800248D8
    if (ctx->r13 != ctx->r1) {
        // 0x80024860: nop
    
            goto L_800248D8;
    }
    // 0x80024860: nop

    // 0x80024864: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80024868: lh          $t7, 0x6C0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6C0);
    // 0x8002486C: nop

    // 0x80024870: bne         $t7, $zero, L_800248D0
    if (ctx->r15 != 0) {
        // 0x80024874: nop
    
            goto L_800248D0;
    }
    // 0x80024874: nop

    // 0x80024878: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002487C: lh          $t1, 0x664($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X664);
    // 0x80024880: nop

    // 0x80024884: bne         $t1, $zero, L_800248D0
    if (ctx->r9 != 0) {
        // 0x80024888: nop
    
            goto L_800248D0;
    }
    // 0x80024888: nop

    // 0x8002488C: lh          $t2, 0x134($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X134);
    // 0x80024890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024894: beq         $t2, $at, L_800248D0
    if (ctx->r10 == ctx->r1) {
        // 0x80024898: nop
    
            goto L_800248D0;
    }
    // 0x80024898: nop

    // 0x8002489C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800248A0: beq         $t2, $at, L_800248D0
    if (ctx->r10 == ctx->r1) {
        // 0x800248A4: nop
    
            goto L_800248D0;
    }
    // 0x800248A4: nop

    // 0x800248A8: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x800248AC: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800248B0: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800248B4: nop

    // 0x800248B8: ori         $t4, $t9, 0x14
    ctx->r12 = ctx->r25 | 0X14;
    // 0x800248BC: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x800248C0: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x800248C4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800248C8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800248CC: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_800248D0:
    // 0x800248D0: b           L_80024904
    // 0x800248D4: nop

        goto L_80024904;
    // 0x800248D4: nop

L_800248D8:
    // 0x800248D8: lh          $t0, 0x134($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X134);
    // 0x800248DC: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800248E0: bne         $t0, $at, L_80024904
    if (ctx->r8 != ctx->r1) {
        // 0x800248E4: nop
    
            goto L_80024904;
    }
    // 0x800248E4: nop

    // 0x800248E8: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800248EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800248F0: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x800248F4: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x800248F8: addiu       $at, $zero, -0xF
    ctx->r1 = ADD32(0, -0XF);
    // 0x800248FC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80024900: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
L_80024904:
    // 0x80024904: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024908: sh          $zero, 0xFF6($at)
    MEM_H(0XFF6, ctx->r1) = 0;
    // 0x8002490C: lhu         $t1, 0x118($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X118);
    // 0x80024910: nop

    // 0x80024914: bne         $t1, $zero, L_800249A0
    if (ctx->r9 != 0) {
        // 0x80024918: nop
    
            goto L_800249A0;
    }
    // 0x80024918: nop

    // 0x8002491C: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80024920: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80024924: nop

    // 0x80024928: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8002492C: nop

    // 0x80024930: bc1f        L_80024940
    if (!c1cs) {
        // 0x80024934: nop
    
            goto L_80024940;
    }
    // 0x80024934: nop

    // 0x80024938: b           L_8002494C
    // 0x8002493C: mov.s       $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = ctx->f6.fl;
        goto L_8002494C;
    // 0x8002493C: mov.s       $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = ctx->f6.fl;
L_80024940:
    // 0x80024940: lwc1        $f22, 0x10C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80024944: nop

    // 0x80024948: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
L_8002494C:
    // 0x8002494C: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80024950: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024954: nop

    // 0x80024958: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8002495C: nop

    // 0x80024960: bc1f        L_80024970
    if (!c1cs) {
        // 0x80024964: nop
    
            goto L_80024970;
    }
    // 0x80024964: nop

    // 0x80024968: b           L_8002497C
    // 0x8002496C: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
        goto L_8002497C;
    // 0x8002496C: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_80024970:
    // 0x80024970: lwc1        $f20, 0x108($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80024974: nop

    // 0x80024978: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8002497C:
    // 0x8002497C: add.s       $f10, $f20, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80024980: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80024984: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80024988: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002498C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80024990: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x80024994: nop

    // 0x80024998: bc1f        L_80024A14
    if (!c1cs) {
        // 0x8002499C: nop
    
            goto L_80024A14;
    }
    // 0x8002499C: nop

L_800249A0:
    // 0x800249A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249A4: lwc1        $f6, 0xEF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x800249A8: lui         $at, 0x4561
    ctx->r1 = S32(0X4561 << 16);
    // 0x800249AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800249B0: nop

    // 0x800249B4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800249B8: nop

    // 0x800249BC: bc1f        L_800249E8
    if (!c1cs) {
        // 0x800249C0: nop
    
            goto L_800249E8;
    }
    // 0x800249C0: nop

    // 0x800249C4: jal         0x8005618C
    // 0x800249C8: nop

    func_8005618C(rdram, ctx);
        goto after_8;
    // 0x800249C8: nop

    after_8:
    // 0x800249CC: bne         $v0, $zero, L_800249E8
    if (ctx->r2 != 0) {
        // 0x800249D0: nop
    
            goto L_800249E8;
    }
    // 0x800249D0: nop

    // 0x800249D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800249D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249DC: sh          $t2, 0xFF6($at)
    MEM_H(0XFF6, ctx->r1) = ctx->r10;
    // 0x800249E0: jal         0x80055FB8
    // 0x800249E4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80055FB8(rdram, ctx);
        goto after_9;
    // 0x800249E4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_9:
L_800249E8:
    // 0x800249E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800249EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249F0: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800249F4: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x800249F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249FC: swc1        $f10, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f10.u32l;
    // 0x80024A00: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80024A04: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80024A08: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80024A0C: b           L_80024A9C
    // 0x80024A10: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
        goto L_80024A9C;
    // 0x80024A10: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
L_80024A14:
    // 0x80024A14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A18: lwc1        $f8, 0xEF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x80024A1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A20: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80024A24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A28: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80024A2C: swc1        $f6, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f6.u32l;
    // 0x80024A30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024A34: lwc1        $f4, -0x1C28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C28);
    // 0x80024A38: nop

    // 0x80024A3C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80024A40: nop

    // 0x80024A44: bc1f        L_80024A5C
    if (!c1cs) {
        // 0x80024A48: nop
    
            goto L_80024A5C;
    }
    // 0x80024A48: nop

    // 0x80024A4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024A50: lwc1        $f16, -0x1C24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1C24);
    // 0x80024A54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A58: swc1        $f16, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f16.u32l;
L_80024A5C:
    // 0x80024A5C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80024A60: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x80024A64: nop

    // 0x80024A68: bne         $t4, $zero, L_80024A9C
    if (ctx->r12 != 0) {
        // 0x80024A6C: nop
    
            goto L_80024A9C;
    }
    // 0x80024A6C: nop

    // 0x80024A70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80024A74: lw          $t6, 0x64C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X64C);
    // 0x80024A78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A7C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80024A80: sw          $t8, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = ctx->r24;
    // 0x80024A84: slti        $at, $t8, 0x2000
    ctx->r1 = SIGNED(ctx->r24) < 0X2000 ? 1 : 0;
    // 0x80024A88: bne         $at, $zero, L_80024A9C
    if (ctx->r1 != 0) {
        // 0x80024A8C: nop
    
            goto L_80024A9C;
    }
    // 0x80024A8C: nop

    // 0x80024A90: addiu       $t0, $zero, 0x1FFF
    ctx->r8 = ADD32(0, 0X1FFF);
    // 0x80024A94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A98: sw          $t0, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = ctx->r8;
L_80024A9C:
    // 0x80024A9C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80024AA0: lw          $t5, 0x64C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X64C);
    // 0x80024AA4: nop

    // 0x80024AA8: slti        $at, $t5, 0x12D
    ctx->r1 = SIGNED(ctx->r13) < 0X12D ? 1 : 0;
    // 0x80024AAC: bne         $at, $zero, L_80024AC8
    if (ctx->r1 != 0) {
        // 0x80024AB0: nop
    
            goto L_80024AC8;
    }
    // 0x80024AB0: nop

    // 0x80024AB4: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x80024AB8: nop

    // 0x80024ABC: andi        $t1, $t7, 0x8
    ctx->r9 = ctx->r15 & 0X8;
    // 0x80024AC0: beq         $t1, $zero, L_80024AEC
    if (ctx->r9 == 0) {
        // 0x80024AC4: nop
    
            goto L_80024AEC;
    }
    // 0x80024AC4: nop

L_80024AC8:
    // 0x80024AC8: lw          $t2, 0x120($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X120);
    // 0x80024ACC: nop

    // 0x80024AD0: beq         $t2, $zero, L_80024B34
    if (ctx->r10 == 0) {
        // 0x80024AD4: nop
    
            goto L_80024B34;
    }
    // 0x80024AD4: nop

    // 0x80024AD8: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80024ADC: nop

    // 0x80024AE0: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x80024AE4: beq         $t9, $zero, L_80024B34
    if (ctx->r25 == 0) {
        // 0x80024AE8: nop
    
            goto L_80024B34;
    }
    // 0x80024AE8: nop

L_80024AEC:
    // 0x80024AEC: sw          $zero, 0x120($sp)
    MEM_W(0X120, ctx->r29) = 0;
    // 0x80024AF0: jal         0x800C4240
    // 0x80024AF4: nop

    guRandom(rdram, ctx);
        goto after_10;
    // 0x80024AF4: nop

    after_10:
    // 0x80024AF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024AFC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80024B00: mfhi        $t4
    ctx->r12 = hi;
    // 0x80024B04: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80024B08: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80024B0C: addiu       $t0, $t8, 0x13
    ctx->r8 = ADD32(ctx->r24, 0X13);
    // 0x80024B10: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80024B14: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80024B18: nop

    // 0x80024B1C: ori         $t7, $t5, 0x8
    ctx->r15 = ctx->r13 | 0X8;
    // 0x80024B20: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x80024B24: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x80024B28: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80024B2C: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80024B30: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
L_80024B34:
    // 0x80024B34: lw          $a3, 0x140($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X140);
    // 0x80024B38: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80024B3C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80024B40: addiu       $a1, $sp, 0xF8
    ctx->r5 = ADD32(ctx->r29, 0XF8);
    // 0x80024B44: addiu       $a2, $sp, 0xF4
    ctx->r6 = ADD32(ctx->r29, 0XF4);
    // 0x80024B48: addiu       $a3, $a3, 0x1B8
    ctx->r7 = ADD32(ctx->r7, 0X1B8);
    // 0x80024B4C: jal         0x800C3F2C
    // 0x80024B50: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_11;
    // 0x80024B50: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80024B54: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80024B58: nop

    // 0x80024B5C: lwc1        $f8, 0x18($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80024B60: nop

    // 0x80024B64: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x80024B68: lhu         $a0, 0x11A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X11A);
    // 0x80024B6C: jal         0x80023CA0
    // 0x80024B70: nop

    func_80023CA0(rdram, ctx);
        goto after_12;
    // 0x80024B70: nop

    after_12:
    // 0x80024B74: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80024B78: lh          $s0, 0x664($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X664);
    // 0x80024B7C: nop

    // 0x80024B80: slti        $at, $s0, 0x3E7
    ctx->r1 = SIGNED(ctx->r16) < 0X3E7 ? 1 : 0;
    // 0x80024B84: bne         $at, $zero, L_80024BA0
    if (ctx->r1 != 0) {
        // 0x80024B88: nop
    
            goto L_80024BA0;
    }
    // 0x80024B88: nop

    // 0x80024B8C: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80024B90: beq         $s0, $at, L_80027F58
    if (ctx->r16 == ctx->r1) {
        // 0x80024B94: nop
    
            goto L_80027F58;
    }
    // 0x80024B94: nop

    // 0x80024B98: b           L_80028048
    // 0x80024B9C: nop

        goto L_80028048;
    // 0x80024B9C: nop

L_80024BA0:
    // 0x80024BA0: slti        $at, $s0, 0x66
    ctx->r1 = SIGNED(ctx->r16) < 0X66 ? 1 : 0;
    // 0x80024BA4: bne         $at, $zero, L_80024BC0
    if (ctx->r1 != 0) {
        // 0x80024BA8: nop
    
            goto L_80024BC0;
    }
    // 0x80024BA8: nop

    // 0x80024BAC: addiu       $at, $zero, 0x3E6
    ctx->r1 = ADD32(0, 0X3E6);
    // 0x80024BB0: beq         $s0, $at, L_80027E4C
    if (ctx->r16 == ctx->r1) {
        // 0x80024BB4: nop
    
            goto L_80027E4C;
    }
    // 0x80024BB4: nop

    // 0x80024BB8: b           L_80028048
    // 0x80024BBC: nop

        goto L_80028048;
    // 0x80024BBC: nop

L_80024BC0:
    // 0x80024BC0: sltiu       $at, $s0, 0x66
    ctx->r1 = ctx->r16 < 0X66 ? 1 : 0;
    // 0x80024BC4: beq         $at, $zero, L_80028048
    if (ctx->r1 == 0) {
        // 0x80024BC8: nop
    
            goto L_80028048;
    }
    // 0x80024BC8: nop

    // 0x80024BCC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80024BD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024BD4: addu        $at, $at, $t9
    gpr jr_addend_80024BE0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80024BD8: lw          $t9, -0x1C20($at)
    ctx->r25 = ADD32(ctx->r1, -0X1C20);
    // 0x80024BDC: nop

    // 0x80024BE0: jr          $t9
    // 0x80024BE4: nop

    switch (jr_addend_80024BE0 >> 2) {
        case 0: goto L_80024BE8; break;
        case 1: goto L_80025294; break;
        case 2: goto L_800258B8; break;
        case 3: goto L_80025C1C; break;
        case 4: goto L_80028048; break;
        case 5: goto L_80025F6C; break;
        case 6: goto L_800260B0; break;
        case 7: goto L_80028048; break;
        case 8: goto L_80028048; break;
        case 9: goto L_80028048; break;
        case 10: goto L_800260F4; break;
        case 11: goto L_80028048; break;
        case 12: goto L_80028048; break;
        case 13: goto L_80028048; break;
        case 14: goto L_80028048; break;
        case 15: goto L_80026130; break;
        case 16: goto L_800260F4; break;
        case 17: goto L_80028048; break;
        case 18: goto L_80028048; break;
        case 19: goto L_80028048; break;
        case 20: goto L_8002760C; break;
        case 21: goto L_800276A4; break;
        case 22: goto L_80028048; break;
        case 23: goto L_80028048; break;
        case 24: goto L_80028048; break;
        case 25: goto L_80027894; break;
        case 26: goto L_800279B8; break;
        case 27: goto L_80028048; break;
        case 28: goto L_80028048; break;
        case 29: goto L_80028048; break;
        case 30: goto L_800279F4; break;
        case 31: goto L_80028048; break;
        case 32: goto L_80028048; break;
        case 33: goto L_80028048; break;
        case 34: goto L_80028048; break;
        case 35: goto L_80027ABC; break;
        case 36: goto L_80028048; break;
        case 37: goto L_80028048; break;
        case 38: goto L_80028048; break;
        case 39: goto L_80028048; break;
        case 40: goto L_80027B84; break;
        case 41: goto L_80027C14; break;
        case 42: goto L_80028048; break;
        case 43: goto L_80028048; break;
        case 44: goto L_80028048; break;
        case 45: goto L_80028048; break;
        case 46: goto L_80028048; break;
        case 47: goto L_80028048; break;
        case 48: goto L_80028048; break;
        case 49: goto L_80028048; break;
        case 50: goto L_80028048; break;
        case 51: goto L_80028048; break;
        case 52: goto L_80028048; break;
        case 53: goto L_80028048; break;
        case 54: goto L_80028048; break;
        case 55: goto L_80028048; break;
        case 56: goto L_80028048; break;
        case 57: goto L_80028048; break;
        case 58: goto L_80028048; break;
        case 59: goto L_80028048; break;
        case 60: goto L_800261CC; break;
        case 61: goto L_80028048; break;
        case 62: goto L_80028048; break;
        case 63: goto L_800262FC; break;
        case 64: goto L_80028048; break;
        case 65: goto L_80028048; break;
        case 66: goto L_80028048; break;
        case 67: goto L_80028048; break;
        case 68: goto L_80028048; break;
        case 69: goto L_80028048; break;
        case 70: goto L_80026B74; break;
        case 71: goto L_80028048; break;
        case 72: goto L_80028048; break;
        case 73: goto L_80028048; break;
        case 74: goto L_80028048; break;
        case 75: goto L_80026BA0; break;
        case 76: goto L_80026EF0; break;
        case 77: goto L_80026FBC; break;
        case 78: goto L_8002714C; break;
        case 79: goto L_80028048; break;
        case 80: goto L_80027184; break;
        case 81: goto L_80027328; break;
        case 82: goto L_80028048; break;
        case 83: goto L_80028048; break;
        case 84: goto L_80028048; break;
        case 85: goto L_80028048; break;
        case 86: goto L_80028048; break;
        case 87: goto L_80028048; break;
        case 88: goto L_80028048; break;
        case 89: goto L_80028048; break;
        case 90: goto L_800273CC; break;
        case 91: goto L_80027448; break;
        case 92: goto L_80028048; break;
        case 93: goto L_80028048; break;
        case 94: goto L_80028048; break;
        case 95: goto L_80027574; break;
        case 96: goto L_80028048; break;
        case 97: goto L_80028048; break;
        case 98: goto L_80028048; break;
        case 99: goto L_80028048; break;
        case 100: goto L_80027DA4; break;
        case 101: goto L_80027E44; break;
        default: switch_error(__func__, 0x80024BE0, 0x800EE3E0);
    }
    // 0x80024BE4: nop

L_80024BE8:
    // 0x80024BE8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80024BEC: lbu         $t4, 0x125A($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X125A);
    // 0x80024BF0: nop

    // 0x80024BF4: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80024BF8: beq         $t6, $zero, L_80024C14
    if (ctx->r14 == 0) {
        // 0x80024BFC: nop
    
            goto L_80024C14;
    }
    // 0x80024BFC: nop

    // 0x80024C00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80024C04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024C08: swc1        $f18, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
    // 0x80024C0C: b           L_80028048
    // 0x80024C10: nop

        goto L_80028048;
    // 0x80024C10: nop

L_80024C14:
    // 0x80024C14: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    // 0x80024C18: addiu       $a1, $sp, 0x134
    ctx->r5 = ADD32(ctx->r29, 0X134);
    // 0x80024C1C: jal         0x80023634
    // 0x80024C20: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    func_80023634(rdram, ctx);
        goto after_13;
    // 0x80024C20: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    after_13:
    // 0x80024C24: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x80024C28: nop

    // 0x80024C2C: lwc1        $f6, 0x1B0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1B0);
    // 0x80024C30: nop

    // 0x80024C34: swc1        $f6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f6.u32l;
    // 0x80024C38: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x80024C3C: nop

    // 0x80024C40: lwc1        $f4, 0x1B4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1B4);
    // 0x80024C44: nop

    // 0x80024C48: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80024C4C: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80024C50: nop

    // 0x80024C54: lh          $t7, 0x24($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X24);
    // 0x80024C58: nop

    // 0x80024C5C: sh          $t7, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r15;
    // 0x80024C60: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80024C64: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80024C68: nop

    // 0x80024C6C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80024C70: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80024C74: andi        $t4, $t2, 0x4
    ctx->r12 = ctx->r10 & 0X4;
    // 0x80024C78: bne         $t4, $zero, L_80024C88
    if (ctx->r12 != 0) {
        // 0x80024C7C: andi        $t5, $t3, 0x0
        ctx->r13 = ctx->r11 & 0X0;
            goto L_80024C88;
    }
    // 0x80024C7C: andi        $t5, $t3, 0x0
    ctx->r13 = ctx->r11 & 0X0;
    // 0x80024C80: beq         $t5, $zero, L_80024E40
    if (ctx->r13 == 0) {
        // 0x80024C84: nop
    
            goto L_80024E40;
    }
    // 0x80024C84: nop

L_80024C88:
    // 0x80024C88: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024C8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80024C90: nop

    // 0x80024C94: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80024C98: nop

    // 0x80024C9C: bc1f        L_80024CC0
    if (!c1cs) {
        // 0x80024CA0: nop
    
            goto L_80024CC0;
    }
    // 0x80024CA0: nop

    // 0x80024CA4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80024CA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80024CAC: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024CB0: nop

    // 0x80024CB4: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80024CB8: b           L_80024CD8
    // 0x80024CBC: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
        goto L_80024CD8;
    // 0x80024CBC: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
L_80024CC0:
    // 0x80024CC0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80024CC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80024CC8: lwc1        $f4, 0x100($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024CCC: nop

    // 0x80024CD0: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80024CD4: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
L_80024CD8:
    // 0x80024CD8: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024CDC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80024CE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80024CE4: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80024CE8: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x80024CEC: nop

    // 0x80024CF0: bc1f        L_80024D08
    if (!c1cs) {
        // 0x80024CF4: nop
    
            goto L_80024D08;
    }
    // 0x80024CF4: nop

    // 0x80024CF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024CFC: lwc1        $f4, -0x1A88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A88);
    // 0x80024D00: nop

    // 0x80024D04: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
L_80024D08:
    // 0x80024D08: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024D0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80024D10: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80024D14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80024D18: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80024D1C: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80024D20: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80024D24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80024D28: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80024D2C: jal         0x800C3D70
    // 0x80024D30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_14;
    // 0x80024D30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x80024D34: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x80024D38: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80024D3C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80024D40: nop

    // 0x80024D44: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80024D48: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80024D4C: nop

    // 0x80024D50: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80024D54: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80024D58: nop

    // 0x80024D5C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80024D60: lw          $t1, 0xC($t8)
    ctx->r9 = MEM_W(ctx->r24, 0XC);
    // 0x80024D64: nop

    // 0x80024D68: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80024D6C: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x80024D70: nop

    // 0x80024D74: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80024D78: lw          $t1, 0x14($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X14);
    // 0x80024D7C: nop

    // 0x80024D80: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x80024D84: lw          $at, 0x18($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X18);
    // 0x80024D88: nop

    // 0x80024D8C: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x80024D90: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80024D94: nop

    // 0x80024D98: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x80024D9C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80024DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80024DA4: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80024DA8: nop

    // 0x80024DAC: div.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80024DB0: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x80024DB4: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80024DB8: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80024DBC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80024DC0: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x80024DC4: addiu       $t4, $zero, 0x11
    ctx->r12 = ADD32(0, 0X11);
    // 0x80024DC8: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80024DCC: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80024DD0: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80024DD4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80024DD8: nop

    // 0x80024DDC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80024DE0: nop

    // 0x80024DE4: bc1f        L_80024DF8
    if (!c1cs) {
        // 0x80024DE8: nop
    
            goto L_80024DF8;
    }
    // 0x80024DE8: nop

    // 0x80024DEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80024DF0: b           L_80024DFC
    // 0x80024DF4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
        goto L_80024DFC;
    // 0x80024DF4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
L_80024DF8:
    // 0x80024DF8: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80024DFC:
    // 0x80024DFC: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80024E00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E04: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80024E08: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80024E0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E10: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80024E14: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x80024E18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E1C: swc1        $f18, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
    // 0x80024E20: lwc1        $f6, 0xF8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80024E24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E28: swc1        $f6, 0xE78($at)
    MEM_W(0XE78, ctx->r1) = ctx->f6.u32l;
    // 0x80024E2C: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024E30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E34: swc1        $f4, 0xEC4($at)
    MEM_W(0XEC4, ctx->r1) = ctx->f4.u32l;
    // 0x80024E38: b           L_80028048
    // 0x80024E3C: nop

        goto L_80028048;
    // 0x80024E3C: nop

L_80024E40:
    // 0x80024E40: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80024E44: lh          $t0, 0xFF6($t0)
    ctx->r8 = MEM_H(ctx->r8, 0XFF6);
    // 0x80024E48: nop

    // 0x80024E4C: beq         $t0, $zero, L_80024E5C
    if (ctx->r8 == 0) {
        // 0x80024E50: nop
    
            goto L_80024E5C;
    }
    // 0x80024E50: nop

    // 0x80024E54: b           L_80028048
    // 0x80024E58: nop

        goto L_80028048;
    // 0x80024E58: nop

L_80024E5C:
    // 0x80024E5C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80024E60: lh          $t6, 0x66C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X66C);
    // 0x80024E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024E68: beq         $t6, $at, L_80025250
    if (ctx->r14 == ctx->r1) {
        // 0x80024E6C: nop
    
            goto L_80025250;
    }
    // 0x80024E6C: nop

    // 0x80024E70: lh          $t8, 0xD2($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XD2);
    // 0x80024E74: nop

    // 0x80024E78: beq         $t8, $zero, L_80024F08
    if (ctx->r24 == 0) {
        // 0x80024E7C: nop
    
            goto L_80024F08;
    }
    // 0x80024E7C: nop

    // 0x80024E80: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x80024E84: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80024E88: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024E8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80024E90: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80024E94: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80024E98: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80024E9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80024EA0: add.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d + ctx->f8.d;
    // 0x80024EA4: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x80024EA8: nop

    // 0x80024EAC: bc1f        L_80024EF8
    if (!c1cs) {
        // 0x80024EB0: nop
    
            goto L_80024EF8;
    }
    // 0x80024EB0: nop

    // 0x80024EB4: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024EB8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80024EBC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80024EC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024EC4: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80024EC8: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x80024ECC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80024ED0: nop

    // 0x80024ED4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80024ED8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024EDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80024EE0: nop

    // 0x80024EE4: cvt.w.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_D(ctx->f8.d);
    // 0x80024EE8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80024EEC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80024EF0: b           L_80024F00
    // 0x80024EF4: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
        goto L_80024F00;
    // 0x80024EF4: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
L_80024EF8:
    // 0x80024EF8: addiu       $t3, $zero, 0x16
    ctx->r11 = ADD32(0, 0X16);
    // 0x80024EFC: sh          $t3, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r11;
L_80024F00:
    // 0x80024F00: b           L_80024F88
    // 0x80024F04: nop

        goto L_80024F88;
    // 0x80024F04: nop

L_80024F08:
    // 0x80024F08: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x80024F0C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80024F10: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024F14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024F18: lui         $at, 0xC060
    ctx->r1 = S32(0XC060 << 16);
    // 0x80024F1C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80024F20: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80024F24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80024F28: sub.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f16.d - ctx->f4.d;
    // 0x80024F2C: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80024F30: nop

    // 0x80024F34: bc1f        L_80024F80
    if (!c1cs) {
        // 0x80024F38: nop
    
            goto L_80024F80;
    }
    // 0x80024F38: nop

    // 0x80024F3C: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024F40: lui         $at, 0xC060
    ctx->r1 = S32(0XC060 << 16);
    // 0x80024F44: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80024F48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80024F4C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80024F50: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x80024F54: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80024F58: nop

    // 0x80024F5C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80024F60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024F64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80024F68: nop

    // 0x80024F6C: cvt.w.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_D(ctx->f4.d);
    // 0x80024F70: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80024F74: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80024F78: b           L_80024F88
    // 0x80024F7C: sh          $t5, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r13;
        goto L_80024F88;
    // 0x80024F7C: sh          $t5, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r13;
L_80024F80:
    // 0x80024F80: addiu       $t9, $zero, -0x16
    ctx->r25 = ADD32(0, -0X16);
    // 0x80024F84: sh          $t9, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r25;
L_80024F88:
    // 0x80024F88: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80024F8C: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x80024F90: lhu         $t7, 0x118($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X118);
    // 0x80024F94: nop

    // 0x80024F98: and         $t6, $t7, $t0
    ctx->r14 = ctx->r15 & ctx->r8;
    // 0x80024F9C: beq         $t6, $zero, L_800250EC
    if (ctx->r14 == 0) {
        // 0x80024FA0: nop
    
            goto L_800250EC;
    }
    // 0x80024FA0: nop

    // 0x80024FA4: lh          $t8, 0x13C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13C);
    // 0x80024FA8: lwc1        $f18, 0x100($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024FAC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80024FB0: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024FB4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80024FB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024FBC: lwc1        $f14, 0xFC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80024FC0: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80024FC4: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x80024FC8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80024FCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80024FD0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80024FD4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80024FD8: jal         0x800C3D70
    // 0x80024FDC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_15;
    // 0x80024FDC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x80024FE0: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80024FE4: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80024FE8: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80024FEC: nop

    // 0x80024FF0: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80024FF4: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80024FF8: nop

    // 0x80024FFC: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80025000: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80025004: nop

    // 0x80025008: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x8002500C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    // 0x80025010: nop

    // 0x80025014: sw          $t9, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r25;
    // 0x80025018: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x8002501C: nop

    // 0x80025020: sw          $at, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r1;
    // 0x80025024: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x80025028: nop

    // 0x8002502C: sw          $t9, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r25;
    // 0x80025030: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x80025034: nop

    // 0x80025038: sw          $at, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r1;
    // 0x8002503C: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80025040: nop

    // 0x80025044: swc1        $f10, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f10.u32l;
    // 0x80025048: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x8002504C: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80025050: sh          $t7, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r15;
    // 0x80025054: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80025058: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002505C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80025060: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80025064: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80025068: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x8002506C: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80025070: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80025074: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025078: nop

    // 0x8002507C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80025080: nop

    // 0x80025084: bc1f        L_80025098
    if (!c1cs) {
        // 0x80025088: nop
    
            goto L_80025098;
    }
    // 0x80025088: nop

    // 0x8002508C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80025090: b           L_8002509C
    // 0x80025094: sh          $t4, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r12;
        goto L_8002509C;
    // 0x80025094: sh          $t4, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r12;
L_80025098:
    // 0x80025098: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_8002509C:
    // 0x8002509C: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800250A0: nop

    // 0x800250A4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800250A8: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x800250AC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800250B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250B4: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x800250B8: jal         0x80055FB8
    // 0x800250BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_16;
    // 0x800250BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
    // 0x800250C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800250C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250C8: sh          $t7, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r15;
    // 0x800250CC: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800250D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250D4: swc1        $f18, 0xE78($at)
    MEM_W(0XE78, ctx->r1) = ctx->f18.u32l;
    // 0x800250D8: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800250DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250E0: swc1        $f16, 0xEC4($at)
    MEM_W(0XEC4, ctx->r1) = ctx->f16.u32l;
    // 0x800250E4: b           L_80028048
    // 0x800250E8: nop

        goto L_80028048;
    // 0x800250E8: nop

L_800250EC:
    // 0x800250EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800250F0: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x800250F4: lhu         $t0, 0x118($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X118);
    // 0x800250F8: nop

    // 0x800250FC: and         $t8, $t0, $t6
    ctx->r24 = ctx->r8 & ctx->r14;
    // 0x80025100: beq         $t8, $zero, L_80025250
    if (ctx->r24 == 0) {
        // 0x80025104: nop
    
            goto L_80025250;
    }
    // 0x80025104: nop

    // 0x80025108: lh          $t1, 0x13C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X13C);
    // 0x8002510C: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80025110: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80025114: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025118: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002511C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80025120: lwc1        $f14, 0xFC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80025124: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025128: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x8002512C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80025130: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025134: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80025138: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8002513C: jal         0x800C3D70
    // 0x80025140: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C3D70(rdram, ctx);
        goto after_17;
    // 0x80025140: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x80025144: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80025148: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8002514C: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80025150: nop

    // 0x80025154: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80025158: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8002515C: nop

    // 0x80025160: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80025164: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80025168: nop

    // 0x8002516C: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80025170: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x80025174: nop

    // 0x80025178: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x8002517C: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x80025180: nop

    // 0x80025184: sw          $at, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r1;
    // 0x80025188: lw          $t7, 0x14($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X14);
    // 0x8002518C: nop

    // 0x80025190: sw          $t7, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r15;
    // 0x80025194: lw          $at, 0x18($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X18);
    // 0x80025198: nop

    // 0x8002519C: sw          $at, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r1;
    // 0x800251A0: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800251A4: nop

    // 0x800251A8: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x800251AC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800251B0: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800251B4: sh          $t0, 0x26($t6)
    MEM_H(0X26, ctx->r14) = ctx->r8;
    // 0x800251B8: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x800251BC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800251C0: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x800251C4: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x800251C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800251CC: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x800251D0: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x800251D4: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800251D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800251DC: nop

    // 0x800251E0: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800251E4: nop

    // 0x800251E8: bc1f        L_800251FC
    if (!c1cs) {
        // 0x800251EC: nop
    
            goto L_800251FC;
    }
    // 0x800251EC: nop

    // 0x800251F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800251F4: b           L_80025200
    // 0x800251F8: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
        goto L_80025200;
    // 0x800251F8: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_800251FC:
    // 0x800251FC: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80025200:
    // 0x80025200: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80025204: nop

    // 0x80025208: ori         $t2, $t4, 0x1
    ctx->r10 = ctx->r12 | 0X1;
    // 0x8002520C: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x80025210: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80025214: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025218: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x8002521C: jal         0x80055FB8
    // 0x80025220: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_18;
    // 0x80025220: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_18:
    // 0x80025224: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80025228: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002522C: sh          $t0, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r8;
    // 0x80025230: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025234: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025238: swc1        $f8, 0xE78($at)
    MEM_W(0XE78, ctx->r1) = ctx->f8.u32l;
    // 0x8002523C: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025244: swc1        $f6, 0xEC4($at)
    MEM_W(0XEC4, ctx->r1) = ctx->f6.u32l;
    // 0x80025248: b           L_80028048
    // 0x8002524C: nop

        goto L_80028048;
    // 0x8002524C: nop

L_80025250:
    // 0x80025250: jal         0x80022E48
    // 0x80025254: nop

    func_80022E48(rdram, ctx);
        goto after_19;
    // 0x80025254: nop

    after_19:
    // 0x80025258: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x8002525C: nop

    // 0x80025260: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80025264: bne         $t8, $zero, L_8002528C
    if (ctx->r24 != 0) {
        // 0x80025268: nop
    
            goto L_8002528C;
    }
    // 0x80025268: nop

    // 0x8002526C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025270: lh          $t1, 0x66C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X66C);
    // 0x80025274: nop

    // 0x80025278: beq         $t1, $zero, L_80025294
    if (ctx->r9 == 0) {
        // 0x8002527C: nop
    
            goto L_80025294;
    }
    // 0x8002527C: nop

    // 0x80025280: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80025284: beq         $t1, $at, L_80025294
    if (ctx->r9 == ctx->r1) {
        // 0x80025288: nop
    
            goto L_80025294;
    }
    // 0x80025288: nop

L_8002528C:
    // 0x8002528C: b           L_80028048
    // 0x80025290: nop

        goto L_80028048;
    // 0x80025290: nop

L_80025294:
    // 0x80025294: lw          $t5, 0x120($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X120);
    // 0x80025298: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002529C: bne         $t5, $at, L_800252C0
    if (ctx->r13 != ctx->r1) {
        // 0x800252A0: nop
    
            goto L_800252C0;
    }
    // 0x800252A0: nop

    // 0x800252A4: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800252A8: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800252AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800252B0: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x800252B4: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x800252B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800252BC: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
L_800252C0:
    // 0x800252C0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800252C4: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x800252C8: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x800252CC: nop

    // 0x800252D0: and         $t7, $t4, $t2
    ctx->r15 = ctx->r12 & ctx->r10;
    // 0x800252D4: beq         $t7, $zero, L_800255F0
    if (ctx->r15 == 0) {
        // 0x800252D8: nop
    
            goto L_800255F0;
    }
    // 0x800252D8: nop

    // 0x800252DC: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800252E0: lui         $at, 0xC054
    ctx->r1 = S32(0XC054 << 16);
    // 0x800252E4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800252E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800252EC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800252F0: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800252F4: nop

    // 0x800252F8: bc1f        L_80025424
    if (!c1cs) {
        // 0x800252FC: nop
    
            goto L_80025424;
    }
    // 0x800252FC: nop

    // 0x80025300: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80025304: lw          $t0, 0xD70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD70);
    // 0x80025308: nop

    // 0x8002530C: bne         $t0, $zero, L_80025424
    if (ctx->r8 != 0) {
        // 0x80025310: nop
    
            goto L_80025424;
    }
    // 0x80025310: nop

    // 0x80025314: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80025318: lbu         $t6, -0x6A00($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6A00);
    // 0x8002531C: nop

    // 0x80025320: bne         $t6, $zero, L_80025424
    if (ctx->r14 != 0) {
        // 0x80025324: nop
    
            goto L_80025424;
    }
    // 0x80025324: nop

    // 0x80025328: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002532C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80025330: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025334: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80025338: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8002533C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80025340: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025344: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x80025348: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8002534C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025350: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80025354: jal         0x800C3D70
    // 0x80025358: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800C3D70(rdram, ctx);
        goto after_20;
    // 0x80025358: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x8002535C: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80025360: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80025364: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80025368: nop

    // 0x8002536C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80025370: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x80025374: nop

    // 0x80025378: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8002537C: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80025380: nop

    // 0x80025384: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80025388: lw          $t3, 0xC($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XC);
    // 0x8002538C: nop

    // 0x80025390: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80025394: lw          $at, 0x10($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X10);
    // 0x80025398: nop

    // 0x8002539C: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x800253A0: lw          $t3, 0x14($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X14);
    // 0x800253A4: nop

    // 0x800253A8: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x800253AC: lw          $at, 0x18($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X18);
    // 0x800253B0: nop

    // 0x800253B4: sw          $at, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r1;
    // 0x800253B8: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800253BC: nop

    // 0x800253C0: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x800253C4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800253C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800253CC: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800253D0: nop

    // 0x800253D4: div.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800253D8: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x800253DC: addiu       $t4, $zero, 0x11
    ctx->r12 = ADD32(0, 0X11);
    // 0x800253E0: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x800253E4: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x800253E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800253EC: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x800253F0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800253F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800253F8: sh          $t7, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r15;
    // 0x800253FC: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80025400: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025404: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x80025408: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x8002540C: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80025410: nop

    // 0x80025414: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80025418: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x8002541C: b           L_80028048
    // 0x80025420: nop

        goto L_80028048;
    // 0x80025420: nop

L_80025424:
    // 0x80025424: lh          $t1, 0x12C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X12C);
    // 0x80025428: nop

    // 0x8002542C: andi        $t5, $t1, 0x8000
    ctx->r13 = ctx->r9 & 0X8000;
    // 0x80025430: beq         $t5, $zero, L_8002550C
    if (ctx->r13 == 0) {
        // 0x80025434: nop
    
            goto L_8002550C;
    }
    // 0x80025434: nop

    // 0x80025438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002543C: lwc1        $f10, 0x10F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X10F8);
    // 0x80025440: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025444: lwc1        $f8, 0x1100($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1100);
    // 0x80025448: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002544C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80025450: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80025454: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80025458: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002545C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80025460: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025464: nop

    // 0x80025468: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8002546C: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80025470: nop

    // 0x80025474: bc1f        L_80025488
    if (!c1cs) {
        // 0x80025478: nop
    
            goto L_80025488;
    }
    // 0x80025478: nop

    // 0x8002547C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80025480: b           L_8002548C
    // 0x80025484: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
        goto L_8002548C;
    // 0x80025484: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_80025488:
    // 0x80025488: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_8002548C:
    // 0x8002548C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80025490: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80025494: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80025498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002549C: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x800254A0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800254A4: addiu       $t0, $t0, 0x10F8
    ctx->r8 = ADD32(ctx->r8, 0X10F8);
    // 0x800254A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800254AC: addiu       $t7, $t7, 0x1048
    ctx->r15 = ADD32(ctx->r15, 0X1048);
    // 0x800254B0: addiu       $t9, $t0, 0xA8
    ctx->r25 = ADD32(ctx->r8, 0XA8);
L_800254B4:
    // 0x800254B4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800254B8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800254BC: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800254C0: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x800254C4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800254C8: sw          $at, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r1;
    // 0x800254CC: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x800254D0: bne         $t0, $t9, L_800254B4
    if (ctx->r8 != ctx->r25) {
        // 0x800254D4: sw          $at, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r1;
            goto L_800254B4;
    }
    // 0x800254D4: sw          $at, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r1;
    // 0x800254D8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800254DC: addiu       $t1, $t1, 0x1048
    ctx->r9 = ADD32(ctx->r9, 0X1048);
    // 0x800254E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800254E4: sw          $t1, 0x11A8($at)
    MEM_W(0X11A8, ctx->r1) = ctx->r9;
    // 0x800254E8: jal         0x80055FB8
    // 0x800254EC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_80055FB8(rdram, ctx);
        goto after_21;
    // 0x800254EC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_21:
    // 0x800254F0: lh          $a0, 0x12C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X12C);
    // 0x800254F4: nop

    // 0x800254F8: andi        $t5, $a0, 0x7FFF
    ctx->r13 = ctx->r4 & 0X7FFF;
    // 0x800254FC: jal         0x8008308C
    // 0x80025500: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_8008308C(rdram, ctx);
        goto after_22;
    // 0x80025500: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_22:
    // 0x80025504: b           L_800255C8
    // 0x80025508: nop

        goto L_800255C8;
    // 0x80025508: nop

L_8002550C:
    // 0x8002550C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80025510: lw          $t3, 0xD70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD70);
    // 0x80025514: nop

    // 0x80025518: bne         $t3, $zero, L_80025568
    if (ctx->r11 != 0) {
        // 0x8002551C: nop
    
            goto L_80025568;
    }
    // 0x8002551C: nop

    // 0x80025520: jal         0x80055FB8
    // 0x80025524: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80055FB8(rdram, ctx);
        goto after_23;
    // 0x80025524: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_23:
    // 0x80025528: lh          $t4, 0x134($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X134);
    // 0x8002552C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80025530: beq         $t4, $at, L_80025558
    if (ctx->r12 == ctx->r1) {
        // 0x80025534: nop
    
            goto L_80025558;
    }
    // 0x80025534: nop

    // 0x80025538: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002553C: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80025540: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80025544: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025548: sh          $t8, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r24;
    // 0x8002554C: lh          $t6, 0x138($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X138);
    // 0x80025550: b           L_80025560
    // 0x80025554: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
        goto L_80025560;
    // 0x80025554: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
L_80025558:
    // 0x80025558: b           L_80028048
    // 0x8002555C: nop

        goto L_80028048;
    // 0x8002555C: nop

L_80025560:
    // 0x80025560: b           L_800255C8
    // 0x80025564: nop

        goto L_800255C8;
    // 0x80025564: nop

L_80025568:
    // 0x80025568: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002556C: lw          $t9, 0xD70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD70);
    // 0x80025570: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025574: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80025578: nop

    // 0x8002557C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80025580: nop

    // 0x80025584: bc1f        L_80025598
    if (!c1cs) {
        // 0x80025588: nop
    
            goto L_80025598;
    }
    // 0x80025588: nop

    // 0x8002558C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80025590: b           L_8002559C
    // 0x80025594: sh          $t0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r8;
        goto L_8002559C;
    // 0x80025594: sh          $t0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r8;
L_80025598:
    // 0x80025598: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_8002559C:
    // 0x8002559C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800255A0: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x800255A4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800255A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800255AC: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x800255B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800255B4: lw          $t5, 0xD70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD70);
    // 0x800255B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800255BC: sw          $t5, 0x11A0($at)
    MEM_W(0X11A0, ctx->r1) = ctx->r13;
    // 0x800255C0: jal         0x80055FB8
    // 0x800255C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80055FB8(rdram, ctx);
        goto after_24;
    // 0x800255C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_24:
L_800255C8:
    // 0x800255C8: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x800255CC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800255D0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800255D4: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x800255D8: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800255DC: nop

    // 0x800255E0: ori         $t8, $t2, 0x1
    ctx->r24 = ctx->r10 | 0X1;
    // 0x800255E4: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x800255E8: b           L_80028048
    // 0x800255EC: nop

        goto L_80028048;
    // 0x800255EC: nop

L_800255F0:
    // 0x800255F0: lhu         $t6, 0x118($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X118);
    // 0x800255F4: lhu         $t9, 0x116($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X116);
    // 0x800255F8: nop

    // 0x800255FC: and         $t0, $t6, $t9
    ctx->r8 = ctx->r14 & ctx->r25;
    // 0x80025600: beq         $t0, $zero, L_80025800
    if (ctx->r8 == 0) {
        // 0x80025604: nop
    
            goto L_80025800;
    }
    // 0x80025604: nop

    // 0x80025608: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002560C: lw          $t7, 0xD70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD70);
    // 0x80025610: nop

    // 0x80025614: bne         $t7, $zero, L_800256A8
    if (ctx->r15 != 0) {
        // 0x80025618: nop
    
            goto L_800256A8;
    }
    // 0x80025618: nop

    // 0x8002561C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025620: lh          $t1, 0x66C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X66C);
    // 0x80025624: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80025628: bne         $t1, $at, L_80025698
    if (ctx->r9 != ctx->r1) {
        // 0x8002562C: nop
    
            goto L_80025698;
    }
    // 0x8002562C: nop

    // 0x80025630: lh          $t5, 0x134($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X134);
    // 0x80025634: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80025638: beq         $t5, $at, L_80025698
    if (ctx->r13 == ctx->r1) {
        // 0x8002563C: nop
    
            goto L_80025698;
    }
    // 0x8002563C: nop

    // 0x80025640: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80025644: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80025648: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002564C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025650: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
    // 0x80025654: lh          $t2, 0x138($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X138);
    // 0x80025658: nop

    // 0x8002565C: sh          $t2, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r10;
    // 0x80025660: jal         0x80055FB8
    // 0x80025664: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80055FB8(rdram, ctx);
        goto after_25;
    // 0x80025664: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_25:
    // 0x80025668: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8002566C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025670: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80025674: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80025678: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x8002567C: nop

    // 0x80025680: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80025684: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x80025688: b           L_80028048
    // 0x8002568C: nop

        goto L_80028048;
    // 0x8002568C: nop

    // 0x80025690: b           L_800256A0
    // 0x80025694: nop

        goto L_800256A0;
    // 0x80025694: nop

L_80025698:
    // 0x80025698: b           L_80028048
    // 0x8002569C: nop

        goto L_80028048;
    // 0x8002569C: nop

L_800256A0:
    // 0x800256A0: b           L_800257D8
    // 0x800256A4: nop

        goto L_800257D8;
    // 0x800256A4: nop

L_800256A8:
    // 0x800256A8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800256AC: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x800256B0: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x800256B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800256B8: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x800256BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800256C0: lw          $t5, 0xD70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD70);
    // 0x800256C4: nop

    // 0x800256C8: lh          $a0, 0x0($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X0);
    // 0x800256CC: jal         0x8002BB9C
    // 0x800256D0: nop

    func_8002BB9C(rdram, ctx);
        goto after_26;
    // 0x800256D0: nop

    after_26:
    // 0x800256D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800256D8: lwc1        $f11, -0x1A80($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A80);
    // 0x800256DC: lwc1        $f10, -0x1A7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A7C);
    // 0x800256E0: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800256E4: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x800256E8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800256EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800256F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800256F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800256F8: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x800256FC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80025700: swc1        $f18, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f18.u32l;
    // 0x80025704: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80025708: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002570C: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x80025710: jal         0x80022690
    // 0x80025714: nop

    func_80022690(rdram, ctx);
        goto after_27;
    // 0x80025714: nop

    after_27:
    // 0x80025718: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002571C: lw          $t4, 0xD70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD70);
    // 0x80025720: nop

    // 0x80025724: lw          $t2, 0x18($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X18);
    // 0x80025728: nop

    // 0x8002572C: beq         $t2, $zero, L_800257C8
    if (ctx->r10 == 0) {
        // 0x80025730: sw          $t2, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r10;
            goto L_800257C8;
    }
    // 0x80025730: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    // 0x80025734: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80025738: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8002573C: lh          $t8, 0x2($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X2);
    // 0x80025740: nop

    // 0x80025744: bne         $t8, $t6, L_800257C8
    if (ctx->r24 != ctx->r14) {
        // 0x80025748: nop
    
            goto L_800257C8;
    }
    // 0x80025748: nop

    // 0x8002574C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80025750: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x80025754: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80025758: nop

    // 0x8002575C: bne         $t9, $t0, L_800257C8
    if (ctx->r25 != ctx->r8) {
        // 0x80025760: nop
    
            goto L_800257C8;
    }
    // 0x80025760: nop

    // 0x80025764: jal         0x80023E50
    // 0x80025768: nop

    func_80023E50(rdram, ctx);
        goto after_28;
    // 0x80025768: nop

    after_28:
    // 0x8002576C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80025770: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80025774: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025778: lw          $t1, 0xD70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD70);
    // 0x8002577C: lw          $t7, 0x306C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X306C);
    // 0x80025780: nop

    // 0x80025784: bne         $t7, $t1, L_800257A4
    if (ctx->r15 != ctx->r9) {
        // 0x80025788: nop
    
            goto L_800257A4;
    }
    // 0x80025788: nop

    // 0x8002578C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80025790: lw          $t5, 0x306C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X306C);
    // 0x80025794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80025798: lw          $t3, 0x18($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X18);
    // 0x8002579C: nop

    // 0x800257A0: sw          $t3, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r11;
L_800257A4:
    // 0x800257A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800257A8: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800257AC: jal         0x80029394
    // 0x800257B0: nop

    func_80029394(rdram, ctx);
        goto after_29;
    // 0x800257B0: nop

    after_29:
    // 0x800257B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800257B8: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800257BC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x800257C0: jal         0x800291B4
    // 0x800257C4: nop

    func_800291B4(rdram, ctx);
        goto after_30;
    // 0x800257C4: nop

    after_30:
L_800257C8:
    // 0x800257C8: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800257CC: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800257D0: jal         0x800234D8
    // 0x800257D4: nop

    func_800234D8(rdram, ctx);
        goto after_31;
    // 0x800257D4: nop

    after_31:
L_800257D8:
    // 0x800257D8: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x800257DC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800257E0: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x800257E4: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x800257E8: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x800257EC: nop

    // 0x800257F0: ori         $t2, $t6, 0x1
    ctx->r10 = ctx->r14 | 0X1;
    // 0x800257F4: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x800257F8: b           L_80028048
    // 0x800257FC: nop

        goto L_80028048;
    // 0x800257FC: nop

L_80025800:
    // 0x80025800: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80025804: lhu         $t0, 0x11AC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X11AC);
    // 0x80025808: lhu         $t9, 0x118($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X118);
    // 0x8002580C: nop

    // 0x80025810: and         $t7, $t9, $t0
    ctx->r15 = ctx->r25 & ctx->r8;
    // 0x80025814: beq         $t7, $zero, L_800258B0
    if (ctx->r15 == 0) {
        // 0x80025818: nop
    
            goto L_800258B0;
    }
    // 0x80025818: nop

    // 0x8002581C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025820: lw          $t1, 0xD70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD70);
    // 0x80025824: nop

    // 0x80025828: beq         $t1, $zero, L_800258B0
    if (ctx->r9 == 0) {
        // 0x8002582C: nop
    
            goto L_800258B0;
    }
    // 0x8002582C: nop

    // 0x80025830: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80025834: lh          $t5, 0x1630($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1630);
    // 0x80025838: nop

    // 0x8002583C: bne         $t5, $zero, L_800258B0
    if (ctx->r13 != 0) {
        // 0x80025840: nop
    
            goto L_800258B0;
    }
    // 0x80025840: nop

    // 0x80025844: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80025848: lbu         $t3, -0x6A00($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6A00);
    // 0x8002584C: nop

    // 0x80025850: bne         $t3, $zero, L_800258B0
    if (ctx->r11 != 0) {
        // 0x80025854: nop
    
            goto L_800258B0;
    }
    // 0x80025854: nop

    // 0x80025858: jal         0x80022690
    // 0x8002585C: nop

    func_80022690(rdram, ctx);
        goto after_32;
    // 0x8002585C: nop

    after_32:
    // 0x80025860: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025864: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025868: jal         0x800234D8
    // 0x8002586C: nop

    func_800234D8(rdram, ctx);
        goto after_33;
    // 0x8002586C: nop

    after_33:
    // 0x80025870: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80025874: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80025878: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8002587C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025880: sh          $t8, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r24;
    // 0x80025884: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80025888: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002588C: sh          $t6, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r14;
    // 0x80025890: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80025894: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025898: and         $t9, $t2, $at
    ctx->r25 = ctx->r10 & ctx->r1;
    // 0x8002589C: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x800258A0: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x800258A4: nop

    // 0x800258A8: ori         $t7, $t0, 0x1
    ctx->r15 = ctx->r8 | 0X1;
    // 0x800258AC: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
L_800258B0:
    // 0x800258B0: b           L_80028048
    // 0x800258B4: nop

        goto L_80028048;
    // 0x800258B4: nop

L_800258B8:
    // 0x800258B8: jal         0x80022E48
    // 0x800258BC: nop

    func_80022E48(rdram, ctx);
        goto after_34;
    // 0x800258BC: nop

    after_34:
    // 0x800258C0: beq         $v0, $zero, L_8002591C
    if (ctx->r2 == 0) {
        // 0x800258C4: nop
    
            goto L_8002591C;
    }
    // 0x800258C4: nop

    // 0x800258C8: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800258CC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800258D0: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x800258D4: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x800258D8: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800258DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800258E0: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800258E4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800258E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800258EC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800258F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800258F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800258F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800258FC: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80025900: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x80025904: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80025908: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8002590C: sh          $t4, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r12;
    // 0x80025910: nop

    // 0x80025914: b           L_80028048
    // 0x80025918: nop

        goto L_80028048;
    // 0x80025918: nop

L_8002591C:
    // 0x8002591C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80025920: lhu         $t6, 0xFF4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XFF4);
    // 0x80025924: lhu         $t8, 0x118($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X118);
    // 0x80025928: nop

    // 0x8002592C: and         $t2, $t8, $t6
    ctx->r10 = ctx->r24 & ctx->r14;
    // 0x80025930: beq         $t2, $zero, L_8002599C
    if (ctx->r10 == 0) {
        // 0x80025934: nop
    
            goto L_8002599C;
    }
    // 0x80025934: nop

    // 0x80025938: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8002593C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025940: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80025944: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80025948: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x8002594C: sh          $t0, 0x26($t7)
    MEM_H(0X26, ctx->r15) = ctx->r8;
    // 0x80025950: jal         0x80055FB8
    // 0x80025954: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_35;
    // 0x80025954: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_35:
    // 0x80025958: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8002595C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80025960: nop

    // 0x80025964: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x80025968: nop

    // 0x8002596C: bc1f        L_80025994
    if (!c1cs) {
        // 0x80025970: nop
    
            goto L_80025994;
    }
    // 0x80025970: nop

    // 0x80025974: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80025978: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x8002597C: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80025980: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025984: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x80025988: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x8002598C: jal         0x800B9000
    // 0x80025990: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_36;
    // 0x80025990: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_36:
L_80025994:
    // 0x80025994: b           L_80028048
    // 0x80025998: nop

        goto L_80028048;
    // 0x80025998: nop

L_8002599C:
    // 0x8002599C: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800259A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800259A4: nop

    // 0x800259A8: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x800259AC: nop

    // 0x800259B0: bc1f        L_80025BA0
    if (!c1cs) {
        // 0x800259B4: nop
    
            goto L_80025BA0;
    }
    // 0x800259B4: nop

    // 0x800259B8: lh          $t4, 0x134($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X134);
    // 0x800259BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800259C0: beq         $t4, $at, L_80025B44
    if (ctx->r12 == ctx->r1) {
        // 0x800259C4: nop
    
            goto L_80025B44;
    }
    // 0x800259C4: nop

    // 0x800259C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800259CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800259D0: sh          $t8, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r24;
    // 0x800259D4: lw          $t6, 0x120($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X120);
    // 0x800259D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800259DC: bne         $t6, $at, L_80025AE8
    if (ctx->r14 != ctx->r1) {
        // 0x800259E0: nop
    
            goto L_80025AE8;
    }
    // 0x800259E0: nop

    // 0x800259E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800259E8: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x800259EC: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800259F0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800259F4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800259F8: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x800259FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025A00: lwc1        $f10, 0xE78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025A04: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025A08: nop

    // 0x80025A0C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80025A10: nop

    // 0x80025A14: bc1f        L_80025A24
    if (!c1cs) {
        // 0x80025A18: nop
    
            goto L_80025A24;
    }
    // 0x80025A18: nop

    // 0x80025A1C: b           L_80025A2C
    // 0x80025A20: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_80025A2C;
    // 0x80025A20: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80025A24:
    // 0x80025A24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80025A28: sh          $t7, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r15;
L_80025A2C:
    // 0x80025A2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025A30: lwc1        $f12, 0xE78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025A34: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025A38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80025A3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025A40: lwc1        $f14, 0xEC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XEC4);
    // 0x80025A44: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025A48: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x80025A4C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80025A50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025A54: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80025A58: jal         0x800C3D70
    // 0x80025A5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_37;
    // 0x80025A5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_37:
    // 0x80025A60: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80025A64: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80025A68: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80025A6C: nop

    // 0x80025A70: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80025A74: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x80025A78: nop

    // 0x80025A7C: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x80025A80: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80025A84: nop

    // 0x80025A88: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80025A8C: lw          $t6, 0xC($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC);
    // 0x80025A90: nop

    // 0x80025A94: sw          $t6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r14;
    // 0x80025A98: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x80025A9C: nop

    // 0x80025AA0: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80025AA4: lw          $t6, 0x14($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X14);
    // 0x80025AA8: nop

    // 0x80025AAC: sw          $t6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r14;
    // 0x80025AB0: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x80025AB4: nop

    // 0x80025AB8: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x80025ABC: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80025AC0: nop

    // 0x80025AC4: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x80025AC8: addiu       $t2, $zero, 0x5F
    ctx->r10 = ADD32(0, 0X5F);
    // 0x80025ACC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025AD0: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x80025AD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80025AD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025ADC: sh          $t9, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r25;
    // 0x80025AE0: b           L_80028048
    // 0x80025AE4: nop

        goto L_80028048;
    // 0x80025AE4: nop

L_80025AE8:
    // 0x80025AE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80025AEC: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x80025AF0: lhu         $t0, 0x118($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X118);
    // 0x80025AF4: nop

    // 0x80025AF8: and         $t1, $t0, $t7
    ctx->r9 = ctx->r8 & ctx->r15;
    // 0x80025AFC: beq         $t1, $zero, L_80025B3C
    if (ctx->r9 == 0) {
        // 0x80025B00: nop
    
            goto L_80025B3C;
    }
    // 0x80025B00: nop

    // 0x80025B04: lh          $t8, 0x134($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X134);
    // 0x80025B08: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80025B0C: bne         $t8, $at, L_80025B3C
    if (ctx->r24 != ctx->r1) {
        // 0x80025B10: nop
    
            goto L_80025B3C;
    }
    // 0x80025B10: nop

    // 0x80025B14: jal         0x80055FB8
    // 0x80025B18: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80055FB8(rdram, ctx);
        goto after_38;
    // 0x80025B18: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_38:
    // 0x80025B1C: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80025B20: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025B24: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80025B28: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80025B2C: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80025B30: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80025B34: jal         0x800B9000
    // 0x80025B38: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_39;
    // 0x80025B38: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_39:
L_80025B3C:
    // 0x80025B3C: b           L_80025B98
    // 0x80025B40: nop

        goto L_80025B98;
    // 0x80025B40: nop

L_80025B44:
    // 0x80025B44: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80025B48: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025B4C: and         $t2, $t6, $at
    ctx->r10 = ctx->r14 & ctx->r1;
    // 0x80025B50: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x80025B54: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80025B58: nop

    // 0x80025B5C: lh          $t0, 0x26($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X26);
    // 0x80025B60: nop

    // 0x80025B64: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80025B68: lh          $s0, 0xD2($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XD2);
    // 0x80025B6C: nop

    // 0x80025B70: sltiu       $t7, $s0, 0x1
    ctx->r15 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80025B74: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80025B78: sh          $s0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r16;
    // 0x80025B7C: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80025B80: nop

    // 0x80025B84: lh          $t8, 0x26($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X26);
    // 0x80025B88: nop

    // 0x80025B8C: sh          $t8, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r24;
    // 0x80025B90: jal         0x800B9000
    // 0x80025B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_40;
    // 0x80025B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_40:
L_80025B98:
    // 0x80025B98: b           L_80025C14
    // 0x80025B9C: nop

        goto L_80025C14;
    // 0x80025B9C: nop

L_80025BA0:
    // 0x80025BA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80025BA4: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025BA8: lwc1        $f11, -0x1A78($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A78);
    // 0x80025BAC: lwc1        $f10, -0x1A74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A74);
    // 0x80025BB0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80025BB4: mul.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80025BB8: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80025BBC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80025BC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80025BC4: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80025BC8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025BCC: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x80025BD0: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x80025BD4: bc1f        L_80025BEC
    if (!c1cs) {
        // 0x80025BD8: nop
    
            goto L_80025BEC;
    }
    // 0x80025BD8: nop

    // 0x80025BDC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80025BE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80025BE4: nop

    // 0x80025BE8: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
L_80025BEC:
    // 0x80025BEC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80025BF0: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x80025BF4: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x80025BF8: nop

    // 0x80025BFC: and         $t3, $t4, $t5
    ctx->r11 = ctx->r12 & ctx->r13;
    // 0x80025C00: beq         $t3, $zero, L_80025C14
    if (ctx->r11 == 0) {
        // 0x80025C04: nop
    
            goto L_80025C14;
    }
    // 0x80025C04: nop

    // 0x80025C08: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80025C0C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80025C10: sh          $t6, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r14;
L_80025C14:
    // 0x80025C14: b           L_80028048
    // 0x80025C18: nop

        goto L_80028048;
    // 0x80025C18: nop

L_80025C1C:
    // 0x80025C1C: jal         0x80022E48
    // 0x80025C20: nop

    func_80022E48(rdram, ctx);
        goto after_41;
    // 0x80025C20: nop

    after_41:
    // 0x80025C24: beq         $v0, $zero, L_80025C80
    if (ctx->r2 == 0) {
        // 0x80025C28: nop
    
            goto L_80025C80;
    }
    // 0x80025C28: nop

    // 0x80025C2C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80025C30: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80025C34: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80025C38: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x80025C3C: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80025C40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025C44: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80025C48: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80025C4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80025C50: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80025C54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80025C58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80025C5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025C60: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80025C64: swc1        $f10, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f10.u32l;
    // 0x80025C68: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80025C6C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80025C70: sh          $t1, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r9;
    // 0x80025C74: nop

    // 0x80025C78: b           L_80028048
    // 0x80025C7C: nop

        goto L_80028048;
    // 0x80025C7C: nop

L_80025C80:
    // 0x80025C80: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80025C84: lhu         $t4, 0x101C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X101C);
    // 0x80025C88: lhu         $t8, 0x118($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X118);
    // 0x80025C8C: nop

    // 0x80025C90: and         $t5, $t8, $t4
    ctx->r13 = ctx->r24 & ctx->r12;
    // 0x80025C94: beq         $t5, $zero, L_80025D00
    if (ctx->r13 == 0) {
        // 0x80025C98: nop
    
            goto L_80025D00;
    }
    // 0x80025C98: nop

    // 0x80025C9C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80025CA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025CA4: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
    // 0x80025CA8: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80025CAC: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80025CB0: sh          $t6, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r14;
    // 0x80025CB4: jal         0x80055FB8
    // 0x80025CB8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_42;
    // 0x80025CB8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_42:
    // 0x80025CBC: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025CC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025CC4: nop

    // 0x80025CC8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80025CCC: nop

    // 0x80025CD0: bc1f        L_80025CF8
    if (!c1cs) {
        // 0x80025CD4: nop
    
            goto L_80025CF8;
    }
    // 0x80025CD4: nop

    // 0x80025CD8: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80025CDC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x80025CE0: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80025CE4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025CE8: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x80025CEC: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x80025CF0: jal         0x800B9000
    // 0x80025CF4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_43;
    // 0x80025CF4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_43:
L_80025CF8:
    // 0x80025CF8: b           L_80028048
    // 0x80025CFC: nop

        goto L_80028048;
    // 0x80025CFC: nop

L_80025D00:
    // 0x80025D00: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025D04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80025D08: nop

    // 0x80025D0C: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x80025D10: nop

    // 0x80025D14: bc1f        L_80025EF0
    if (!c1cs) {
        // 0x80025D18: nop
    
            goto L_80025EF0;
    }
    // 0x80025D18: nop

    // 0x80025D1C: lh          $t1, 0x134($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X134);
    // 0x80025D20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025D24: beq         $t1, $at, L_80025EA8
    if (ctx->r9 == ctx->r1) {
        // 0x80025D28: nop
    
            goto L_80025EA8;
    }
    // 0x80025D28: nop

    // 0x80025D2C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80025D30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025D34: sh          $t8, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r24;
    // 0x80025D38: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x80025D3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025D40: bne         $t4, $at, L_80025E4C
    if (ctx->r12 != ctx->r1) {
        // 0x80025D44: nop
    
            goto L_80025E4C;
    }
    // 0x80025D44: nop

    // 0x80025D48: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80025D4C: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x80025D50: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80025D54: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80025D58: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x80025D5C: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80025D60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025D64: lwc1        $f8, 0xE78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025D68: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025D6C: nop

    // 0x80025D70: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80025D74: nop

    // 0x80025D78: bc1f        L_80025D88
    if (!c1cs) {
        // 0x80025D7C: nop
    
            goto L_80025D88;
    }
    // 0x80025D7C: nop

    // 0x80025D80: b           L_80025D90
    // 0x80025D84: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_80025D90;
    // 0x80025D84: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80025D88:
    // 0x80025D88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80025D8C: sh          $t2, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r10;
L_80025D90:
    // 0x80025D90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025D94: lwc1        $f12, 0xE78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025D98: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025D9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025DA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025DA4: lwc1        $f14, 0xEC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XEC4);
    // 0x80025DA8: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025DAC: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80025DB0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80025DB4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025DB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80025DBC: jal         0x800C3D70
    // 0x80025DC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_44;
    // 0x80025DC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_44:
    // 0x80025DC4: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x80025DC8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80025DCC: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x80025DD0: nop

    // 0x80025DD4: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80025DD8: lw          $t4, 0x4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X4);
    // 0x80025DDC: nop

    // 0x80025DE0: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80025DE4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80025DE8: nop

    // 0x80025DEC: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80025DF0: lw          $t4, 0xC($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XC);
    // 0x80025DF4: nop

    // 0x80025DF8: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80025DFC: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80025E00: nop

    // 0x80025E04: sw          $at, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r1;
    // 0x80025E08: lw          $t4, 0x14($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X14);
    // 0x80025E0C: nop

    // 0x80025E10: sw          $t4, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r12;
    // 0x80025E14: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x80025E18: nop

    // 0x80025E1C: sw          $at, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r1;
    // 0x80025E20: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80025E24: nop

    // 0x80025E28: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x80025E2C: addiu       $t5, $zero, 0x5F
    ctx->r13 = ADD32(0, 0X5F);
    // 0x80025E30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025E34: sh          $t5, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r13;
    // 0x80025E38: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80025E3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025E40: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x80025E44: b           L_80028048
    // 0x80025E48: nop

        goto L_80028048;
    // 0x80025E48: nop

L_80025E4C:
    // 0x80025E4C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80025E50: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x80025E54: lhu         $t6, 0x118($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X118);
    // 0x80025E58: nop

    // 0x80025E5C: and         $t9, $t6, $t2
    ctx->r25 = ctx->r14 & ctx->r10;
    // 0x80025E60: beq         $t9, $zero, L_80025EA0
    if (ctx->r25 == 0) {
        // 0x80025E64: nop
    
            goto L_80025EA0;
    }
    // 0x80025E64: nop

    // 0x80025E68: lh          $t8, 0x134($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X134);
    // 0x80025E6C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80025E70: bne         $t8, $at, L_80025EA0
    if (ctx->r24 != ctx->r1) {
        // 0x80025E74: nop
    
            goto L_80025EA0;
    }
    // 0x80025E74: nop

    // 0x80025E78: jal         0x800B9000
    // 0x80025E7C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_45;
    // 0x80025E7C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_45:
    // 0x80025E80: jal         0x80055FB8
    // 0x80025E84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80055FB8(rdram, ctx);
        goto after_46;
    // 0x80025E84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x80025E88: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x80025E8C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025E90: and         $t0, $t1, $at
    ctx->r8 = ctx->r9 & ctx->r1;
    // 0x80025E94: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x80025E98: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80025E9C: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
L_80025EA0:
    // 0x80025EA0: b           L_80025EE8
    // 0x80025EA4: nop

        goto L_80025EE8;
    // 0x80025EA4: nop

L_80025EA8:
    // 0x80025EA8: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80025EAC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025EB0: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80025EB4: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80025EB8: lh          $s0, 0xD2($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XD2);
    // 0x80025EBC: nop

    // 0x80025EC0: sltiu       $t3, $s0, 0x1
    ctx->r11 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80025EC4: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80025EC8: sh          $s0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r16;
    // 0x80025ECC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80025ED0: nop

    // 0x80025ED4: lh          $t2, 0x26($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X26);
    // 0x80025ED8: nop

    // 0x80025EDC: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80025EE0: jal         0x800B9000
    // 0x80025EE4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_47;
    // 0x80025EE4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_47:
L_80025EE8:
    // 0x80025EE8: b           L_80025F64
    // 0x80025EEC: nop

        goto L_80025F64;
    // 0x80025EEC: nop

L_80025EF0:
    // 0x80025EF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80025EF4: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025EF8: lwc1        $f9, -0x1A70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A70);
    // 0x80025EFC: lwc1        $f8, -0x1A6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A6C);
    // 0x80025F00: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80025F04: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80025F08: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80025F0C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80025F10: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80025F14: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80025F18: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80025F1C: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80025F20: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x80025F24: bc1f        L_80025F3C
    if (!c1cs) {
        // 0x80025F28: nop
    
            goto L_80025F3C;
    }
    // 0x80025F28: nop

    // 0x80025F2C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80025F30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80025F34: nop

    // 0x80025F38: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
L_80025F3C:
    // 0x80025F3C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80025F40: lhu         $t8, 0xFF4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XFF4);
    // 0x80025F44: lhu         $t9, 0x118($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X118);
    // 0x80025F48: nop

    // 0x80025F4C: and         $t1, $t9, $t8
    ctx->r9 = ctx->r25 & ctx->r24;
    // 0x80025F50: beq         $t1, $zero, L_80025F64
    if (ctx->r9 == 0) {
        // 0x80025F54: nop
    
            goto L_80025F64;
    }
    // 0x80025F54: nop

    // 0x80025F58: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80025F5C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80025F60: sh          $t0, 0x26($t7)
    MEM_H(0X26, ctx->r15) = ctx->r8;
L_80025F64:
    // 0x80025F64: b           L_80028048
    // 0x80025F68: nop

        goto L_80028048;
    // 0x80025F68: nop

L_80025F6C:
    // 0x80025F6C: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025F70: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80025F74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025F78: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80025F7C: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80025F80: nop

    // 0x80025F84: bc1f        L_800260A8
    if (!c1cs) {
        // 0x80025F88: nop
    
            goto L_800260A8;
    }
    // 0x80025F88: nop

    // 0x80025F8C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80025F90: addiu       $t4, $zero, 0x5A
    ctx->r12 = ADD32(0, 0X5A);
    // 0x80025F94: sw          $t4, 0xC8($t5)
    MEM_W(0XC8, ctx->r13) = ctx->r12;
    // 0x80025F98: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80025F9C: lw          $t6, 0xCE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE8);
    // 0x80025FA0: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80025FA4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80025FA8: sw          $t3, 0x228($t6)
    MEM_W(0X228, ctx->r14) = ctx->r11;
    // 0x80025FAC: lw          $t2, 0xCE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCE8);
    // 0x80025FB0: nop

    // 0x80025FB4: lw          $t9, 0x228($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X228);
    // 0x80025FB8: nop

    // 0x80025FBC: sw          $t9, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r25;
    // 0x80025FC0: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
L_80025FC4:
    // 0x80025FC4: lh          $t0, 0x13E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X13E);
    // 0x80025FC8: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80025FCC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80025FD0: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80025FD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80025FD8: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80025FDC: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80025FE0: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80025FE4: addu        $t4, $t1, $t7
    ctx->r12 = ADD32(ctx->r9, ctx->r15);
    // 0x80025FE8: sh          $t8, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r24;
    // 0x80025FEC: lh          $t5, 0x13E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X13E);
    // 0x80025FF0: nop

    // 0x80025FF4: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x80025FF8: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x80025FFC: sra         $t9, $t6, 16
    ctx->r25 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80026000: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80026004: bne         $at, $zero, L_80025FC4
    if (ctx->r1 != 0) {
        // 0x80026008: sh          $t3, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r11;
            goto L_80025FC4;
    }
    // 0x80026008: sh          $t3, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r11;
    // 0x8002600C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80026010: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80026014: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80026018: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002601C: sh          $t2, 0x224($t0)
    MEM_H(0X224, ctx->r8) = ctx->r10;
    // 0x80026020: lw          $t1, 0xCE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCE8);
    // 0x80026024: nop

    // 0x80026028: lhu         $t7, 0x224($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X224);
    // 0x8002602C: nop

    // 0x80026030: sh          $t7, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r15;
    // 0x80026034: jal         0x800228A8
    // 0x80026038: nop

    func_800228A8(rdram, ctx);
        goto after_48;
    // 0x80026038: nop

    after_48:
    // 0x8002603C: jal         0x8003168C
    // 0x80026040: nop

    func_8003168C(rdram, ctx);
        goto after_49;
    // 0x80026040: nop

    after_49:
    // 0x80026044: beq         $v0, $zero, L_8002606C
    if (ctx->r2 == 0) {
        // 0x80026048: nop
    
            goto L_8002606C;
    }
    // 0x80026048: nop

    // 0x8002604C: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80026050: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80026054: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80026058: and         $t4, $t8, $at
    ctx->r12 = ctx->r24 & ctx->r1;
    // 0x8002605C: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x80026060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026064: b           L_800260A8
    // 0x80026068: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
        goto L_800260A8;
    // 0x80026068: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
L_8002606C:
    // 0x8002606C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80026070: jal         0x800319B0
    // 0x80026074: addiu       $a0, $a0, -0x48A0
    ctx->r4 = ADD32(ctx->r4, -0X48A0);
    func_800319B0(rdram, ctx);
        goto after_50;
    // 0x80026074: addiu       $a0, $a0, -0x48A0
    ctx->r4 = ADD32(ctx->r4, -0X48A0);
    after_50:
    // 0x80026078: jal         0x80031B6C
    // 0x8002607C: nop

    func_80031B6C(rdram, ctx);
        goto after_51;
    // 0x8002607C: nop

    after_51:
    // 0x80026080: addiu       $t5, $zero, 0x12
    ctx->r13 = ADD32(0, 0X12);
    // 0x80026084: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x80026088: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002608C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026090: sh          $t3, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r11;
    // 0x80026094: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80026098: lh          $t6, 0x664($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X664);
    // 0x8002609C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260A0: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800260A4: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
L_800260A8:
    // 0x800260A8: b           L_80028048
    // 0x800260AC: nop

        goto L_80028048;
    // 0x800260AC: nop

L_800260B0:
    // 0x800260B0: jal         0x80031AC8
    // 0x800260B4: nop

    func_80031AC8(rdram, ctx);
        goto after_52;
    // 0x800260B4: nop

    after_52:
    // 0x800260B8: bne         $v0, $zero, L_800260EC
    if (ctx->r2 != 0) {
        // 0x800260BC: nop
    
            goto L_800260EC;
    }
    // 0x800260BC: nop

    // 0x800260C0: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800260C4: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800260C8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800260CC: and         $t0, $t2, $at
    ctx->r8 = ctx->r10 & ctx->r1;
    // 0x800260D0: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x800260D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260D8: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800260DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260E0: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
    // 0x800260E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260E8: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_800260EC:
    // 0x800260EC: b           L_80028048
    // 0x800260F0: nop

        goto L_80028048;
    // 0x800260F0: nop

L_800260F4:
    // 0x800260F4: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x800260F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800260FC: bne         $t7, $at, L_80026128
    if (ctx->r15 != ctx->r1) {
        // 0x80026100: nop
    
            goto L_80026128;
    }
    // 0x80026100: nop

    // 0x80026104: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80026108: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x8002610C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80026110: and         $t8, $t1, $at
    ctx->r24 = ctx->r9 & ctx->r1;
    // 0x80026114: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80026118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002611C: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80026120: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026124: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_80026128:
    // 0x80026128: b           L_80028048
    // 0x8002612C: nop

        goto L_80028048;
    // 0x8002612C: nop

L_80026130:
    // 0x80026130: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80026134: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80026138: addiu       $t4, $t4, 0x5B0
    ctx->r12 = ADD32(ctx->r12, 0X5B0);
    // 0x8002613C: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x80026140: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80026144: lw          $t5, 0xD70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD70);
    // 0x80026148: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002614C: lwc1        $f16, 0xD98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XD98);
    // 0x80026150: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80026154: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80026158: addiu       $a3, $a3, 0x5B0
    ctx->r7 = ADD32(ctx->r7, 0X5B0);
    // 0x8002615C: addiu       $a0, $a0, 0xD78
    ctx->r4 = ADD32(ctx->r4, 0XD78);
    // 0x80026160: addiu       $a1, $t5, 0x8
    ctx->r5 = ADD32(ctx->r13, 0X8);
    // 0x80026164: addiu       $a2, $t5, 0xC
    ctx->r6 = ADD32(ctx->r13, 0XC);
    // 0x80026168: jal         0x800C3F2C
    // 0x8002616C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_53;
    // 0x8002616C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_53:
    // 0x80026170: lw          $t3, 0x120($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X120);
    // 0x80026174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026178: bne         $t3, $at, L_800261C4
    if (ctx->r11 != ctx->r1) {
        // 0x8002617C: nop
    
            goto L_800261C4;
    }
    // 0x8002617C: nop

    // 0x80026180: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80026184: sh          $t6, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r14;
    // 0x80026188: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x8002618C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80026190: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x80026194: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x80026198: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8002619C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800261A0: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x800261A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800261A8: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800261AC: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x800261B0: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x800261B4: jal         0x8002C0FC
    // 0x800261B8: nop

    func_8002C0FC(rdram, ctx);
        goto after_54;
    // 0x800261B8: nop

    after_54:
    // 0x800261BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800261C0: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
L_800261C4:
    // 0x800261C4: b           L_80028048
    // 0x800261C8: nop

        goto L_80028048;
    // 0x800261C8: nop

L_800261CC:
    // 0x800261CC: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800261D0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800261D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800261D8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800261DC: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x800261E0: nop

    // 0x800261E4: bc1f        L_800262F4
    if (!c1cs) {
        // 0x800261E8: nop
    
            goto L_800262F4;
    }
    // 0x800261E8: nop

    // 0x800261EC: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x800261F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800261F4: bne         $t7, $at, L_800262F4
    if (ctx->r15 != ctx->r1) {
        // 0x800261F8: nop
    
            goto L_800262F4;
    }
    // 0x800261F8: nop

    // 0x800261FC: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
    // 0x80026200: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80026208: nop

    // 0x8002620C: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80026210: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80026214: addiu       $t1, $zero, 0xDC
    ctx->r9 = ADD32(0, 0XDC);
    // 0x80026218: sw          $t1, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r9;
    // 0x8002621C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80026220: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x80026224: addiu       $t4, $zero, 0xD2
    ctx->r12 = ADD32(0, 0XD2);
    // 0x80026228: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002622C: sw          $t4, 0x228($t5)
    MEM_W(0X228, ctx->r13) = ctx->r12;
    // 0x80026230: lw          $t3, 0xCE8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XCE8);
    // 0x80026234: nop

    // 0x80026238: lw          $t6, 0x228($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X228);
    // 0x8002623C: nop

    // 0x80026240: sw          $t6, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r14;
    // 0x80026244: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
L_80026248:
    // 0x80026248: lh          $t0, 0x13E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X13E);
    // 0x8002624C: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80026250: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80026254: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80026258: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002625C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80026260: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80026264: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80026268: addu        $t1, $t2, $t7
    ctx->r9 = ADD32(ctx->r10, ctx->r15);
    // 0x8002626C: sh          $t9, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r25;
    // 0x80026270: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x80026274: nop

    // 0x80026278: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8002627C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80026280: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80026284: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80026288: bne         $at, $zero, L_80026248
    if (ctx->r1 != 0) {
        // 0x8002628C: sh          $t4, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r12;
            goto L_80026248;
    }
    // 0x8002628C: sh          $t4, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r12;
    // 0x80026290: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80026294: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80026298: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8002629C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800262A0: sh          $t3, 0x224($t0)
    MEM_H(0X224, ctx->r8) = ctx->r11;
    // 0x800262A4: lw          $t2, 0xCE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCE8);
    // 0x800262A8: nop

    // 0x800262AC: lhu         $t7, 0x224($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X224);
    // 0x800262B0: nop

    // 0x800262B4: sh          $t7, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r15;
    // 0x800262B8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800262BC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x800262C0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800262C4: sh          $t1, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r9;
    // 0x800262C8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800262CC: sh          $t8, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r24;
    // 0x800262D0: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800262D4: nop

    // 0x800262D8: sh          $zero, 0x2A($t4)
    MEM_H(0X2A, ctx->r12) = 0;
    // 0x800262DC: addiu       $t5, $zero, 0x3F
    ctx->r13 = ADD32(0, 0X3F);
    // 0x800262E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800262E4: sh          $t5, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r13;
    // 0x800262E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800262EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800262F0: sh          $t6, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = ctx->r14;
L_800262F4:
    // 0x800262F4: b           L_80028048
    // 0x800262F8: nop

        goto L_80028048;
    // 0x800262F8: nop

L_800262FC:
    // 0x800262FC: jal         0x80023C60
    // 0x80026300: nop

    func_80023C60(rdram, ctx);
        goto after_55;
    // 0x80026300: nop

    after_55:
    // 0x80026304: beq         $v0, $zero, L_80026314
    if (ctx->r2 == 0) {
        // 0x80026308: nop
    
            goto L_80026314;
    }
    // 0x80026308: nop

    // 0x8002630C: b           L_80028048
    // 0x80026310: nop

        goto L_80028048;
    // 0x80026310: nop

L_80026314:
    // 0x80026314: lh          $t3, 0x130($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X130);
    // 0x80026318: nop

    // 0x8002631C: sh          $t3, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r11;
    // 0x80026320: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x80026324: nop

    // 0x80026328: lh          $t7, 0x2A($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2A);
    // 0x8002632C: nop

    // 0x80026330: sh          $t7, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r15;
    // 0x80026334: lh          $t2, 0x13C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X13C);
    // 0x80026338: lh          $t1, 0x12A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X12A);
    // 0x8002633C: addiu       $t9, $t2, -0x2
    ctx->r25 = ADD32(ctx->r10, -0X2);
    // 0x80026340: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80026344: sra         $t4, $t8, 16
    ctx->r12 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026348: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002634C: beq         $at, $zero, L_80026398
    if (ctx->r1 == 0) {
        // 0x80026350: sh          $t9, 0x136($sp)
        MEM_H(0X136, ctx->r29) = ctx->r25;
            goto L_80026398;
    }
    // 0x80026350: sh          $t9, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r25;
    // 0x80026354: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80026358: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002635C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026360: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026364: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80026368: c.eq.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d == ctx->f10.d;
    // 0x8002636C: nop

    // 0x80026370: bc1f        L_80026398
    if (!c1cs) {
        // 0x80026374: nop
    
            goto L_80026398;
    }
    // 0x80026374: nop

    // 0x80026378: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002637C: sh          $t5, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r13;
    // 0x80026380: lh          $t6, 0x136($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X136);
    // 0x80026384: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80026388: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8002638C: lbu         $t3, -0x6500($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6500);
    // 0x80026390: nop

    // 0x80026394: sh          $t3, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r11;
L_80026398:
    // 0x80026398: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8002639C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800263A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800263A4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800263A8: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x800263AC: nop

    // 0x800263B0: bc1f        L_8002642C
    if (!c1cs) {
        // 0x800263B4: nop
    
            goto L_8002642C;
    }
    // 0x800263B4: nop

    // 0x800263B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800263BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800263C0: nop

    // 0x800263C4: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800263C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800263CC: sh          $t0, 0x112($sp)
    MEM_H(0X112, ctx->r29) = ctx->r8;
    // 0x800263D0: lhu         $t7, 0x114($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X114);
    // 0x800263D4: nop

    // 0x800263D8: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x800263DC: beq         $at, $zero, L_80026424
    if (ctx->r1 == 0) {
        // 0x800263E0: nop
    
            goto L_80026424;
    }
    // 0x800263E0: nop

    // 0x800263E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800263E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800263EC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800263F0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800263F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800263F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800263FC: lhu         $t2, 0x114($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X114);
    // 0x80026400: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80026404: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80026408: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002640C: sll         $t1, $t8, 16
    ctx->r9 = S32(ctx->r24 << 16);
    // 0x80026410: sra         $t4, $t1, 16
    ctx->r12 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80026414: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80026418: sh          $t5, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r13;
    // 0x8002641C: b           L_80028048
    // 0x80026420: nop

        goto L_80028048;
    // 0x80026420: nop

L_80026424:
    // 0x80026424: b           L_80026430
    // 0x80026428: nop

        goto L_80026430;
    // 0x80026428: nop

L_8002642C:
    // 0x8002642C: sh          $zero, 0x112($sp)
    MEM_H(0X112, ctx->r29) = 0;
L_80026430:
    // 0x80026430: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80026434: lwc1        $f8, -0x7820($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80026438: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8002643C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026440: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80026444: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80026448: nop

    // 0x8002644C: bc1f        L_80026604
    if (!c1cs) {
        // 0x80026450: nop
    
            goto L_80026604;
    }
    // 0x80026450: nop

    // 0x80026454: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80026458: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8002645C: lhu         $t6, 0x11A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X11A);
    // 0x80026460: nop

    // 0x80026464: and         $t0, $t6, $t3
    ctx->r8 = ctx->r14 & ctx->r11;
    // 0x80026468: beq         $t0, $zero, L_800264A4
    if (ctx->r8 == 0) {
        // 0x8002646C: nop
    
            goto L_800264A4;
    }
    // 0x8002646C: nop

    // 0x80026470: lh          $t7, 0x13C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13C);
    // 0x80026474: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80026478: beq         $t7, $at, L_800264A4
    if (ctx->r15 == ctx->r1) {
        // 0x8002647C: nop
    
            goto L_800264A4;
    }
    // 0x8002647C: nop

    // 0x80026480: lh          $t9, 0x12A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12A);
    // 0x80026484: nop

    // 0x80026488: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002648C: bne         $at, $zero, L_800264A4
    if (ctx->r1 != 0) {
        // 0x80026490: nop
    
            goto L_800264A4;
    }
    // 0x80026490: nop

    // 0x80026494: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80026498: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002649C: b           L_80026604
    // 0x800264A0: swc1        $f18, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f18.u32l;
        goto L_80026604;
    // 0x800264A0: swc1        $f18, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f18.u32l;
L_800264A4:
    // 0x800264A4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800264A8: lhu         $t1, 0x1260($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1260);
    // 0x800264AC: lhu         $t8, 0x11A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X11A);
    // 0x800264B0: nop

    // 0x800264B4: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x800264B8: beq         $t2, $zero, L_80026604
    if (ctx->r10 == 0) {
        // 0x800264BC: nop
    
            goto L_80026604;
    }
    // 0x800264BC: nop

    // 0x800264C0: lh          $t4, 0x13C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13C);
    // 0x800264C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800264C8: beq         $t4, $at, L_80026604
    if (ctx->r12 == ctx->r1) {
        // 0x800264CC: nop
    
            goto L_80026604;
    }
    // 0x800264CC: nop

    // 0x800264D0: lh          $t5, 0x12A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X12A);
    // 0x800264D4: nop

    // 0x800264D8: beq         $t5, $zero, L_80026604
    if (ctx->r13 == 0) {
        // 0x800264DC: nop
    
            goto L_80026604;
    }
    // 0x800264DC: nop

    // 0x800264E0: lh          $t6, 0x13C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X13C);
    // 0x800264E4: lh          $t3, 0x12A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X12A);
    // 0x800264E8: nop

    // 0x800264EC: subu        $t0, $t6, $t3
    ctx->r8 = SUB32(ctx->r14, ctx->r11);
    // 0x800264F0: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x800264F4: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800264F8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800264FC: blez        $t8, L_800265F4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80026500: sh          $t9, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r25;
            goto L_800265F4;
    }
    // 0x80026500: sh          $t9, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r25;
    // 0x80026504: lhu         $t1, 0x112($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X112);
    // 0x80026508: nop

    // 0x8002650C: beq         $t1, $zero, L_800265F4
    if (ctx->r9 == 0) {
        // 0x80026510: nop
    
            goto L_800265F4;
    }
    // 0x80026510: nop

    // 0x80026514: lh          $t2, 0x13E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X13E);
    // 0x80026518: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8002651C: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80026520: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80026524: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026528: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002652C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026530: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80026534: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80026538: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8002653C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026540: sub.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80026544: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026548: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x8002654C: jal         0x800C3D70
    // 0x80026550: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_56;
    // 0x80026550: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_56:
    // 0x80026554: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80026558: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8002655C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80026560: nop

    // 0x80026564: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80026568: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8002656C: nop

    // 0x80026570: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80026574: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80026578: nop

    // 0x8002657C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80026580: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    // 0x80026584: nop

    // 0x80026588: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8002658C: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x80026590: nop

    // 0x80026594: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80026598: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x8002659C: nop

    // 0x800265A0: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x800265A4: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x800265A8: nop

    // 0x800265AC: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800265B0: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800265B4: nop

    // 0x800265B8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x800265BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800265C0: nop

    // 0x800265C4: swc1        $f10, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f10.u32l;
    // 0x800265C8: lh          $t7, 0x13C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13C);
    // 0x800265CC: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x800265D0: nop

    // 0x800265D4: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
    // 0x800265D8: sh          $t1, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r9;
    // 0x800265DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800265E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800265E4: nop

    // 0x800265E8: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x800265EC: b           L_80026604
    // 0x800265F0: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
        goto L_80026604;
    // 0x800265F0: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
L_800265F4:
    // 0x800265F4: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x800265F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800265FC: nop

    // 0x80026600: swc1        $f16, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f16.u32l;
L_80026604:
    // 0x80026604: lh          $t2, 0x12E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X12E);
    // 0x80026608: nop

    // 0x8002660C: beq         $t2, $zero, L_80026638
    if (ctx->r10 == 0) {
        // 0x80026610: nop
    
            goto L_80026638;
    }
    // 0x80026610: nop

    // 0x80026614: lh          $t4, 0x136($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X136);
    // 0x80026618: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002661C: addu        $a3, $a3, $t4
    ctx->r7 = ADD32(ctx->r7, ctx->r12);
    // 0x80026620: lbu         $a3, -0x6500($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X6500);
    // 0x80026624: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80026628: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002662C: lw          $a2, 0x104($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X104);
    // 0x80026630: jal         0x80022918
    // 0x80026634: nop

    func_80022918(rdram, ctx);
        goto after_57;
    // 0x80026634: nop

    after_57:
L_80026638:
    // 0x80026638: sh          $zero, 0x136($sp)
    MEM_H(0X136, ctx->r29) = 0;
    // 0x8002663C: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026640: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026644: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80026648: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002664C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80026650: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80026654: nop

    // 0x80026658: bc1f        L_800266A4
    if (!c1cs) {
        // 0x8002665C: nop
    
            goto L_800266A4;
    }
    // 0x8002665C: nop

    // 0x80026660: lh          $t5, 0x13A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X13A);
    // 0x80026664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026668: beq         $t5, $at, L_80026684
    if (ctx->r13 == ctx->r1) {
        // 0x8002666C: nop
    
            goto L_80026684;
    }
    // 0x8002666C: nop

    // 0x80026670: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80026674: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80026678: sh          $t6, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r14;
    // 0x8002667C: b           L_8002669C
    // 0x80026680: sh          $t0, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r8;
        goto L_8002669C;
    // 0x80026680: sh          $t0, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r8;
L_80026684:
    // 0x80026684: lhu         $t3, 0x112($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X112);
    // 0x80026688: nop

    // 0x8002668C: beq         $t3, $zero, L_8002669C
    if (ctx->r11 == 0) {
        // 0x80026690: nop
    
            goto L_8002669C;
    }
    // 0x80026690: nop

    // 0x80026694: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80026698: sh          $t9, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r25;
L_8002669C:
    // 0x8002669C: b           L_80026710
    // 0x800266A0: nop

        goto L_80026710;
    // 0x800266A0: nop

L_800266A4:
    // 0x800266A4: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800266A8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800266AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800266B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800266B4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800266B8: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800266BC: nop

    // 0x800266C0: bc1f        L_8002670C
    if (!c1cs) {
        // 0x800266C4: nop
    
            goto L_8002670C;
    }
    // 0x800266C4: nop

    // 0x800266C8: lh          $t7, 0x13A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13A);
    // 0x800266CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800266D0: beq         $t7, $at, L_800266EC
    if (ctx->r15 == ctx->r1) {
        // 0x800266D4: nop
    
            goto L_800266EC;
    }
    // 0x800266D4: nop

    // 0x800266D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800266DC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800266E0: sh          $t1, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r9;
    // 0x800266E4: b           L_80026704
    // 0x800266E8: sh          $t8, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r24;
        goto L_80026704;
    // 0x800266E8: sh          $t8, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r24;
L_800266EC:
    // 0x800266EC: lhu         $t2, 0x112($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X112);
    // 0x800266F0: nop

    // 0x800266F4: beq         $t2, $zero, L_80026704
    if (ctx->r10 == 0) {
        // 0x800266F8: nop
    
            goto L_80026704;
    }
    // 0x800266F8: nop

    // 0x800266FC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80026700: sh          $t4, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r12;
L_80026704:
    // 0x80026704: b           L_80026710
    // 0x80026708: nop

        goto L_80026710;
    // 0x80026708: nop

L_8002670C:
    // 0x8002670C: sh          $zero, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = 0;
L_80026710:
    // 0x80026710: lh          $t5, 0x136($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X136);
    // 0x80026714: nop

    // 0x80026718: beq         $t5, $zero, L_8002691C
    if (ctx->r13 == 0) {
        // 0x8002671C: nop
    
            goto L_8002691C;
    }
    // 0x8002671C: nop

    // 0x80026720: lhu         $t0, 0x112($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X112);
    // 0x80026724: nop

    // 0x80026728: beq         $t0, $zero, L_8002691C
    if (ctx->r8 == 0) {
        // 0x8002672C: nop
    
            goto L_8002691C;
    }
    // 0x8002672C: nop

    // 0x80026730: lh          $t6, 0x136($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X136);
    // 0x80026734: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026738: bne         $t6, $at, L_800267FC
    if (ctx->r14 != ctx->r1) {
        // 0x8002673C: nop
    
            goto L_800267FC;
    }
    // 0x8002673C: nop

    // 0x80026740: lh          $t3, 0x13C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X13C);
    // 0x80026744: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80026748: bne         $t3, $at, L_800267B0
    if (ctx->r11 != ctx->r1) {
        // 0x8002674C: nop
    
            goto L_800267B0;
    }
    // 0x8002674C: nop

    // 0x80026750: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80026754: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026758: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002675C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026760: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026764: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026768: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x8002676C: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80026770: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80026774: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026778: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002677C: jal         0x800C3D70
    // 0x80026780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_58;
    // 0x80026780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_58:
    // 0x80026784: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80026788: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002678C: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80026790: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80026794: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80026798: nop

    // 0x8002679C: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800267A0: jal         0x800228A8
    // 0x800267A4: nop

    func_800228A8(rdram, ctx);
        goto after_59;
    // 0x800267A4: nop

    after_59:
    // 0x800267A8: b           L_800267E8
    // 0x800267AC: nop

        goto L_800267E8;
    // 0x800267AC: nop

L_800267B0:
    // 0x800267B0: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800267B4: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800267B8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800267BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800267C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800267C4: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800267C8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800267CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800267D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800267D4: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x800267D8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800267DC: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800267E0: jal         0x800C3D70
    // 0x800267E4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_60;
    // 0x800267E4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_60:
L_800267E8:
    // 0x800267E8: lh          $t1, 0x13C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X13C);
    // 0x800267EC: nop

    // 0x800267F0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800267F4: b           L_800268B4
    // 0x800267F8: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
        goto L_800268B4;
    // 0x800267F8: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
L_800267FC:
    // 0x800267FC: lh          $t4, 0x13C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13C);
    // 0x80026800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80026804: bne         $t4, $at, L_8002686C
    if (ctx->r12 != ctx->r1) {
        // 0x80026808: nop
    
            goto L_8002686C;
    }
    // 0x80026808: nop

    // 0x8002680C: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80026810: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026814: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026818: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002681C: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026820: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026824: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80026828: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x8002682C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80026830: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026834: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80026838: jal         0x800C3D70
    // 0x8002683C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C3D70(rdram, ctx);
        goto after_61;
    // 0x8002683C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_61:
    // 0x80026840: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x80026844: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026848: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x8002684C: jal         0x800228A8
    // 0x80026850: nop

    func_800228A8(rdram, ctx);
        goto after_62;
    // 0x80026850: nop

    after_62:
    // 0x80026854: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80026858: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002685C: nop

    // 0x80026860: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80026864: b           L_800268A4
    // 0x80026868: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
        goto L_800268A4;
    // 0x80026868: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
L_8002686C:
    // 0x8002686C: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80026870: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026874: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80026878: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002687C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026880: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80026884: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80026888: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8002688C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026890: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x80026894: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026898: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002689C: jal         0x800C3D70
    // 0x800268A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_63;
    // 0x800268A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_63:
L_800268A4:
    // 0x800268A4: lh          $t3, 0x13C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X13C);
    // 0x800268A8: nop

    // 0x800268AC: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x800268B0: sh          $t9, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r25;
L_800268B4:
    // 0x800268B4: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800268B8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800268BC: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x800268C0: nop

    // 0x800268C4: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800268C8: lw          $t4, 0x4($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X4);
    // 0x800268CC: nop

    // 0x800268D0: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x800268D4: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x800268D8: nop

    // 0x800268DC: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x800268E0: lw          $t4, 0xC($t8)
    ctx->r12 = MEM_W(ctx->r24, 0XC);
    // 0x800268E4: nop

    // 0x800268E8: sw          $t4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r12;
    // 0x800268EC: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x800268F0: nop

    // 0x800268F4: sw          $at, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r1;
    // 0x800268F8: lw          $t4, 0x14($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X14);
    // 0x800268FC: nop

    // 0x80026900: sw          $t4, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r12;
    // 0x80026904: lw          $at, 0x18($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X18);
    // 0x80026908: nop

    // 0x8002690C: sw          $at, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r1;
    // 0x80026910: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026914: nop

    // 0x80026918: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
L_8002691C:
    // 0x8002691C: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026920: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80026924: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026928: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002692C: c.eq.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d == ctx->f10.d;
    // 0x80026930: nop

    // 0x80026934: bc1f        L_80026B50
    if (!c1cs) {
        // 0x80026938: nop
    
            goto L_80026B50;
    }
    // 0x80026938: nop

    // 0x8002693C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80026940: lhu         $t0, 0x10F2($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X10F2);
    // 0x80026944: lhu         $t5, 0x118($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X118);
    // 0x80026948: nop

    // 0x8002694C: and         $t6, $t5, $t0
    ctx->r14 = ctx->r13 & ctx->r8;
    // 0x80026950: beq         $t6, $zero, L_8002698C
    if (ctx->r14 == 0) {
        // 0x80026954: nop
    
            goto L_8002698C;
    }
    // 0x80026954: nop

    // 0x80026958: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8002695C: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80026960: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80026964: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80026968: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002696C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80026970: nop

    // 0x80026974: bc1f        L_8002698C
    if (!c1cs) {
        // 0x80026978: nop
    
            goto L_8002698C;
    }
    // 0x80026978: nop

    // 0x8002697C: addiu       $t3, $zero, 0x3E7
    ctx->r11 = ADD32(0, 0X3E7);
    // 0x80026980: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026984: b           L_80026B50
    // 0x80026988: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
        goto L_80026B50;
    // 0x80026988: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
L_8002698C:
    // 0x8002698C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80026990: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x80026994: lhu         $t9, 0x118($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X118);
    // 0x80026998: nop

    // 0x8002699C: and         $t1, $t9, $t2
    ctx->r9 = ctx->r25 & ctx->r10;
    // 0x800269A0: beq         $t1, $zero, L_80026B50
    if (ctx->r9 == 0) {
        // 0x800269A4: nop
    
            goto L_80026B50;
    }
    // 0x800269A4: nop

    // 0x800269A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800269AC: lh          $t7, 0x1630($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1630);
    // 0x800269B0: nop

    // 0x800269B4: bne         $t7, $zero, L_80026B50
    if (ctx->r15 != 0) {
        // 0x800269B8: nop
    
            goto L_80026B50;
    }
    // 0x800269B8: nop

    // 0x800269BC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800269C0: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x800269C4: jal         0x8002A0F8
    // 0x800269C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_64;
    // 0x800269C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_64:
    // 0x800269CC: sh          $v0, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r2;
    // 0x800269D0: lh          $t4, 0x136($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X136);
    // 0x800269D4: lh          $t8, 0x13C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13C);
    // 0x800269D8: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x800269DC: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800269E0: beq         $at, $zero, L_80026B50
    if (ctx->r1 == 0) {
        // 0x800269E4: nop
    
            goto L_80026B50;
    }
    // 0x800269E4: nop

    // 0x800269E8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800269EC: lh          $t0, 0x1B48($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X1B48);
    // 0x800269F0: nop

    // 0x800269F4: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800269F8: beq         $at, $zero, L_80026A7C
    if (ctx->r1 == 0) {
        // 0x800269FC: nop
    
            goto L_80026A7C;
    }
    // 0x800269FC: nop

    // 0x80026A00: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80026A04: sh          $t6, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r14;
    // 0x80026A08: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80026A0C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026A10: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80026A14: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80026A18: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x80026A1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026A20: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x80026A24: lh          $a1, 0x13C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X13C);
    // 0x80026A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026A2C: jal         0x8002A22C
    // 0x80026A30: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_8002A22C(rdram, ctx);
        goto after_65;
    // 0x80026A30: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_65:
    // 0x80026A34: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80026A38: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80026A3C: nop

    // 0x80026A40: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80026A44: nop

    // 0x80026A48: sh          $t7, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r15;
    // 0x80026A4C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80026A50: jal         0x800299C4
    // 0x80026A54: nop

    func_800299C4(rdram, ctx);
        goto after_66;
    // 0x80026A54: nop

    after_66:
    // 0x80026A58: lh          $a0, 0x13E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X13E);
    // 0x80026A5C: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x80026A60: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x80026A64: jal         0x8002C004
    // 0x80026A68: nop

    func_8002C004(rdram, ctx);
        goto after_67;
    // 0x80026A68: nop

    after_67:
    // 0x80026A6C: jal         0x80029ED8
    // 0x80026A70: nop

    func_80029ED8(rdram, ctx);
        goto after_68;
    // 0x80026A70: nop

    after_68:
    // 0x80026A74: b           L_80026B50
    // 0x80026A78: nop

        goto L_80026B50;
    // 0x80026A78: nop

L_80026A7C:
    // 0x80026A7C: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80026A80: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026A84: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80026A88: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80026A8C: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80026A90: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x80026A94: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80026A98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026A9C: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x80026AA0: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80026AA4: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026AA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026AAC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80026AB0: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80026AB4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80026AB8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80026ABC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026AC0: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    // 0x80026AC4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80026AC8: jal         0x800C3D70
    // 0x80026ACC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_69;
    // 0x80026ACC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_69:
    // 0x80026AD0: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80026AD4: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80026AD8: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80026ADC: nop

    // 0x80026AE0: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80026AE4: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80026AE8: nop

    // 0x80026AEC: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80026AF0: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80026AF4: nop

    // 0x80026AF8: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80026AFC: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80026B00: nop

    // 0x80026B04: sw          $t7, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r15;
    // 0x80026B08: lw          $at, 0x10($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X10);
    // 0x80026B0C: nop

    // 0x80026B10: sw          $at, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r1;
    // 0x80026B14: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x80026B18: nop

    // 0x80026B1C: sw          $t7, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r15;
    // 0x80026B20: lw          $at, 0x18($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X18);
    // 0x80026B24: nop

    // 0x80026B28: sw          $at, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r1;
    // 0x80026B2C: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026B30: nop

    // 0x80026B34: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
    // 0x80026B38: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80026B3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80026B40: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026B44: nop

    // 0x80026B48: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80026B4C: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_80026B50:
    // 0x80026B50: lh          $t4, 0x13C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13C);
    // 0x80026B54: nop

    // 0x80026B58: sh          $t4, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r12;
    // 0x80026B5C: lh          $t8, 0x13A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13A);
    // 0x80026B60: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80026B64: nop

    // 0x80026B68: sh          $t8, 0x2A($t5)
    MEM_H(0X2A, ctx->r13) = ctx->r24;
    // 0x80026B6C: b           L_80028048
    // 0x80026B70: nop

        goto L_80028048;
    // 0x80026B70: nop

L_80026B74:
    // 0x80026B74: lw          $t0, 0x120($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X120);
    // 0x80026B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026B7C: bne         $t0, $at, L_80026B98
    if (ctx->r8 != ctx->r1) {
        // 0x80026B80: nop
    
            goto L_80026B98;
    }
    // 0x80026B80: nop

    // 0x80026B84: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80026B88: sh          $t6, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r14;
    // 0x80026B8C: addiu       $t1, $zero, 0x3F
    ctx->r9 = ADD32(0, 0X3F);
    // 0x80026B90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026B94: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
L_80026B98:
    // 0x80026B98: b           L_80028048
    // 0x80026B9C: nop

        goto L_80028048;
    // 0x80026B9C: nop

L_80026BA0:
    // 0x80026BA0: jal         0x80023C60
    // 0x80026BA4: nop

    func_80023C60(rdram, ctx);
        goto after_70;
    // 0x80026BA4: nop

    after_70:
    // 0x80026BA8: beq         $v0, $zero, L_80026BB8
    if (ctx->r2 == 0) {
        // 0x80026BAC: nop
    
            goto L_80026BB8;
    }
    // 0x80026BAC: nop

    // 0x80026BB0: b           L_80028048
    // 0x80026BB4: nop

        goto L_80028048;
    // 0x80026BB4: nop

L_80026BB8:
    // 0x80026BB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026BBC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80026BC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80026BC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026BC8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80026BCC: lhu         $t2, 0x114($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X114);
    // 0x80026BD0: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80026BD4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026BD8: nop

    // 0x80026BDC: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80026BE0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80026BE4: beq         $t9, $zero, L_80026C38
    if (ctx->r25 == 0) {
        // 0x80026BE8: nop
    
            goto L_80026C38;
    }
    // 0x80026BE8: nop

    // 0x80026BEC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80026BF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80026BF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80026BF8: sub.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80026BFC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026C00: nop

    // 0x80026C04: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80026C08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026C0C: nop

    // 0x80026C10: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80026C14: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80026C18: bne         $t9, $zero, L_80026C30
    if (ctx->r25 != 0) {
        // 0x80026C1C: nop
    
            goto L_80026C30;
    }
    // 0x80026C1C: nop

    // 0x80026C20: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80026C24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80026C28: b           L_80026C48
    // 0x80026C2C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80026C48;
    // 0x80026C2C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80026C30:
    // 0x80026C30: b           L_80026C48
    // 0x80026C34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80026C48;
    // 0x80026C34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80026C38:
    // 0x80026C38: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80026C3C: nop

    // 0x80026C40: bltz        $t9, L_80026C30
    if (SIGNED(ctx->r25) < 0) {
        // 0x80026C44: nop
    
            goto L_80026C30;
    }
    // 0x80026C44: nop

L_80026C48:
    // 0x80026C48: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80026C4C: addu        $t4, $t2, $t7
    ctx->r12 = ADD32(ctx->r10, ctx->r15);
    // 0x80026C50: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x80026C54: slti        $at, $t8, 0x33
    ctx->r1 = SIGNED(ctx->r24) < 0X33 ? 1 : 0;
    // 0x80026C58: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80026C5C: bne         $at, $zero, L_80026C6C
    if (ctx->r1 != 0) {
        // 0x80026C60: sh          $t4, 0x114($sp)
        MEM_H(0X114, ctx->r29) = ctx->r12;
            goto L_80026C6C;
    }
    // 0x80026C60: sh          $t4, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r12;
    // 0x80026C64: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x80026C68: sh          $t5, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r13;
L_80026C6C:
    // 0x80026C6C: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026C70: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80026C74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80026C78: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80026C7C: c.eq.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d == ctx->f18.d;
    // 0x80026C80: nop

    // 0x80026C84: bc1f        L_80026EE8
    if (!c1cs) {
        // 0x80026C88: nop
    
            goto L_80026EE8;
    }
    // 0x80026C88: nop

    // 0x80026C8C: lhu         $t0, 0x114($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X114);
    // 0x80026C90: nop

    // 0x80026C94: slti        $at, $t0, 0xF
    ctx->r1 = SIGNED(ctx->r8) < 0XF ? 1 : 0;
    // 0x80026C98: bne         $at, $zero, L_80026E58
    if (ctx->r1 != 0) {
        // 0x80026C9C: nop
    
            goto L_80026E58;
    }
    // 0x80026C9C: nop

    // 0x80026CA0: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026CA4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026CA8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026CAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026CB0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80026CB4: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80026CB8: nop

    // 0x80026CBC: bc1f        L_80026D84
    if (!c1cs) {
        // 0x80026CC0: nop
    
            goto L_80026D84;
    }
    // 0x80026CC0: nop

    // 0x80026CC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80026CC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026CCC: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026CD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026CD4: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026CD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026CDC: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80026CE0: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80026CE4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80026CE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026CEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026CF0: jal         0x800C3D70
    // 0x80026CF4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_71;
    // 0x80026CF4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_71:
    // 0x80026CF8: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80026CFC: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80026D00: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80026D04: nop

    // 0x80026D08: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80026D0C: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x80026D10: nop

    // 0x80026D14: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80026D18: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80026D1C: nop

    // 0x80026D20: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80026D24: lw          $t2, 0xC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC);
    // 0x80026D28: nop

    // 0x80026D2C: sw          $t2, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r10;
    // 0x80026D30: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x80026D34: nop

    // 0x80026D38: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x80026D3C: lw          $t2, 0x14($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X14);
    // 0x80026D40: nop

    // 0x80026D44: sw          $t2, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r10;
    // 0x80026D48: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x80026D4C: nop

    // 0x80026D50: sw          $at, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r1;
    // 0x80026D54: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026D58: nop

    // 0x80026D5C: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x80026D60: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80026D64: sh          $t7, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r15;
    // 0x80026D68: addiu       $t4, $zero, 0x4E
    ctx->r12 = ADD32(0, 0X4E);
    // 0x80026D6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026D70: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
    // 0x80026D74: b           L_80028048
    // 0x80026D78: nop

        goto L_80028048;
    // 0x80026D78: nop

    // 0x80026D7C: b           L_80026E58
    // 0x80026D80: nop

        goto L_80026E58;
    // 0x80026D80: nop

L_80026D84:
    // 0x80026D84: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026D88: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80026D8C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026D90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026D94: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80026D98: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80026D9C: nop

    // 0x80026DA0: bc1f        L_80026E58
    if (!c1cs) {
        // 0x80026DA4: nop
    
            goto L_80026E58;
    }
    // 0x80026DA4: nop

    // 0x80026DA8: lui         $at, 0xC230
    ctx->r1 = S32(0XC230 << 16);
    // 0x80026DAC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026DB0: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026DB4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026DB8: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026DBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026DC0: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80026DC4: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x80026DC8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80026DCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026DD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026DD4: jal         0x800C3D70
    // 0x80026DD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_72;
    // 0x80026DD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_72:
    // 0x80026DDC: addiu       $t0, $sp, 0xB4
    ctx->r8 = ADD32(ctx->r29, 0XB4);
    // 0x80026DE0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80026DE4: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80026DE8: nop

    // 0x80026DEC: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80026DF0: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x80026DF4: nop

    // 0x80026DF8: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80026DFC: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80026E00: nop

    // 0x80026E04: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80026E08: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x80026E0C: nop

    // 0x80026E10: sw          $t9, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r25;
    // 0x80026E14: lw          $at, 0x10($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X10);
    // 0x80026E18: nop

    // 0x80026E1C: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80026E20: lw          $t9, 0x14($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X14);
    // 0x80026E24: nop

    // 0x80026E28: sw          $t9, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r25;
    // 0x80026E2C: lw          $at, 0x18($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X18);
    // 0x80026E30: nop

    // 0x80026E34: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x80026E38: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026E3C: nop

    // 0x80026E40: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x80026E44: addiu       $t1, $zero, 0x4D
    ctx->r9 = ADD32(0, 0X4D);
    // 0x80026E48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026E4C: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x80026E50: b           L_80028048
    // 0x80026E54: nop

        goto L_80028048;
    // 0x80026E54: nop

L_80026E58:
    // 0x80026E58: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80026E5C: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x80026E60: lhu         $t3, 0x118($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X118);
    // 0x80026E64: nop

    // 0x80026E68: and         $t7, $t3, $t2
    ctx->r15 = ctx->r11 & ctx->r10;
    // 0x80026E6C: beq         $t7, $zero, L_80026EE8
    if (ctx->r15 == 0) {
        // 0x80026E70: nop
    
            goto L_80026EE8;
    }
    // 0x80026E70: nop

    // 0x80026E74: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80026E78: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80026E7C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026E80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026E84: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80026E88: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80026E8C: nop

    // 0x80026E90: bc1f        L_80026EA8
    if (!c1cs) {
        // 0x80026E94: nop
    
            goto L_80026EA8;
    }
    // 0x80026E94: nop

    // 0x80026E98: addiu       $t4, $zero, 0x3E7
    ctx->r12 = ADD32(0, 0X3E7);
    // 0x80026E9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026EA0: b           L_80026EE8
    // 0x80026EA4: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
        goto L_80026EE8;
    // 0x80026EA4: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
L_80026EA8:
    // 0x80026EA8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80026EAC: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80026EB0: jal         0x8002A0F8
    // 0x80026EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A0F8(rdram, ctx);
        goto after_73;
    // 0x80026EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_73:
    // 0x80026EB8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80026EBC: bne         $at, $zero, L_80026EE8
    if (ctx->r1 != 0) {
        // 0x80026EC0: nop
    
            goto L_80026EE8;
    }
    // 0x80026EC0: nop

    // 0x80026EC4: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x80026EC8: sh          $t8, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r24;
    // 0x80026ECC: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80026ED0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026ED4: and         $t5, $t6, $at
    ctx->r13 = ctx->r14 & ctx->r1;
    // 0x80026ED8: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80026EDC: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
    // 0x80026EE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026EE4: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
L_80026EE8:
    // 0x80026EE8: b           L_80028048
    // 0x80026EEC: nop

        goto L_80028048;
    // 0x80026EEC: nop

L_80026EF0:
    // 0x80026EF0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80026EF4: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x80026EF8: lhu         $t9, 0x11A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X11A);
    // 0x80026EFC: nop

    // 0x80026F00: and         $t3, $t9, $t1
    ctx->r11 = ctx->r25 & ctx->r9;
    // 0x80026F04: beq         $t3, $zero, L_80026F1C
    if (ctx->r11 == 0) {
        // 0x80026F08: nop
    
            goto L_80026F1C;
    }
    // 0x80026F08: nop

    // 0x80026F0C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80026F10: lhu         $a0, 0x1260($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1260);
    // 0x80026F14: jal         0x80023CA0
    // 0x80026F18: nop

    func_80023CA0(rdram, ctx);
        goto after_74;
    // 0x80026F18: nop

    after_74:
L_80026F1C:
    // 0x80026F1C: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026F20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026F24: nop

    // 0x80026F28: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80026F2C: nop

    // 0x80026F30: bc1f        L_80026F40
    if (!c1cs) {
        // 0x80026F34: nop
    
            goto L_80026F40;
    }
    // 0x80026F34: nop

    // 0x80026F38: b           L_80026F4C
    // 0x80026F3C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_80026F4C;
    // 0x80026F3C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_80026F40:
    // 0x80026F40: lwc1        $f20, 0x10C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026F44: nop

    // 0x80026F48: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80026F4C:
    // 0x80026F4C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026F50: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80026F54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80026F58: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80026F5C: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x80026F60: nop

    // 0x80026F64: bc1t        L_80026F90
    if (c1cs) {
        // 0x80026F68: nop
    
            goto L_80026F90;
    }
    // 0x80026F68: nop

    // 0x80026F6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80026F70: lwc1        $f16, -0x7820($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80026F74: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80026F78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026F7C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80026F80: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x80026F84: nop

    // 0x80026F88: bc1f        L_80026FB4
    if (!c1cs) {
        // 0x80026F8C: nop
    
            goto L_80026FB4;
    }
    // 0x80026F8C: nop

L_80026F90:
    // 0x80026F90: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80026F94: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80026F98: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x80026F9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026FA0: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80026FA4: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80026FA8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026FAC: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80026FB0: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_80026FB4:
    // 0x80026FB4: b           L_80028048
    // 0x80026FB8: nop

        goto L_80028048;
    // 0x80026FB8: nop

L_80026FBC:
    // 0x80026FBC: jal         0x80023C60
    // 0x80026FC0: nop

    func_80023C60(rdram, ctx);
        goto after_75;
    // 0x80026FC0: nop

    after_75:
    // 0x80026FC4: beq         $v0, $zero, L_80026FD4
    if (ctx->r2 == 0) {
        // 0x80026FC8: nop
    
            goto L_80026FD4;
    }
    // 0x80026FC8: nop

    // 0x80026FCC: b           L_80028048
    // 0x80026FD0: nop

        goto L_80028048;
    // 0x80026FD0: nop

L_80026FD4:
    // 0x80026FD4: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026FD8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80026FDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80026FE0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80026FE4: c.eq.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d == ctx->f8.d;
    // 0x80026FE8: nop

    // 0x80026FEC: bc1f        L_80027144
    if (!c1cs) {
        // 0x80026FF0: nop
    
            goto L_80027144;
    }
    // 0x80026FF0: nop

    // 0x80026FF4: lwc1        $f16, 0x10C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026FF8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026FFC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80027000: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027004: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80027008: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002700C: nop

    // 0x80027010: bc1f        L_800270DC
    if (!c1cs) {
        // 0x80027014: nop
    
            goto L_800270DC;
    }
    // 0x80027014: nop

    // 0x80027018: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8002701C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80027020: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80027024: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80027028: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x8002702C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80027030: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80027034: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80027038: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8002703C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80027040: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80027044: jal         0x800C3D70
    // 0x80027048: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C3D70(rdram, ctx);
        goto after_76;
    // 0x80027048: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_76:
    // 0x8002704C: addiu       $t0, $sp, 0xB4
    ctx->r8 = ADD32(ctx->r29, 0XB4);
    // 0x80027050: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80027054: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80027058: nop

    // 0x8002705C: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80027060: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80027064: nop

    // 0x80027068: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8002706C: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80027070: nop

    // 0x80027074: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80027078: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8002707C: nop

    // 0x80027080: sw          $t1, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r9;
    // 0x80027084: lw          $at, 0x10($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X10);
    // 0x80027088: nop

    // 0x8002708C: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80027090: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x80027094: nop

    // 0x80027098: sw          $t1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r9;
    // 0x8002709C: lw          $at, 0x18($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X18);
    // 0x800270A0: nop

    // 0x800270A4: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x800270A8: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800270AC: nop

    // 0x800270B0: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x800270B4: lh          $t3, 0x130($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X130);
    // 0x800270B8: nop

    // 0x800270BC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x800270C0: sh          $t2, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r10;
    // 0x800270C4: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
    // 0x800270C8: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x800270CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800270D0: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x800270D4: b           L_80028048
    // 0x800270D8: nop

        goto L_80028048;
    // 0x800270D8: nop

L_800270DC:
    // 0x800270DC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800270E0: lhu         $t8, 0x10F2($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X10F2);
    // 0x800270E4: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x800270E8: nop

    // 0x800270EC: and         $t6, $t4, $t8
    ctx->r14 = ctx->r12 & ctx->r24;
    // 0x800270F0: beq         $t6, $zero, L_80027144
    if (ctx->r14 == 0) {
        // 0x800270F4: nop
    
            goto L_80027144;
    }
    // 0x800270F4: nop

    // 0x800270F8: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800270FC: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80027100: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80027104: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027108: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8002710C: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80027110: nop

    // 0x80027114: bc1f        L_8002712C
    if (!c1cs) {
        // 0x80027118: nop
    
            goto L_8002712C;
    }
    // 0x80027118: nop

    // 0x8002711C: addiu       $t9, $zero, 0x3E7
    ctx->r25 = ADD32(0, 0X3E7);
    // 0x80027120: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027124: b           L_80027144
    // 0x80027128: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
        goto L_80027144;
    // 0x80027128: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
L_8002712C:
    // 0x8002712C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80027130: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80027134: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
    // 0x80027138: nop

    // 0x8002713C: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80027140: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
L_80027144:
    // 0x80027144: b           L_80028048
    // 0x80027148: nop

        goto L_80028048;
    // 0x80027148: nop

L_8002714C:
    // 0x8002714C: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027150: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80027154: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80027158: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8002715C: c.eq.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d == ctx->f8.d;
    // 0x80027160: nop

    // 0x80027164: bc1f        L_8002717C
    if (!c1cs) {
        // 0x80027168: nop
    
            goto L_8002717C;
    }
    // 0x80027168: nop

    // 0x8002716C: addiu       $t3, $zero, 0x3F
    ctx->r11 = ADD32(0, 0X3F);
    // 0x80027170: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027174: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
    // 0x80027178: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
L_8002717C:
    // 0x8002717C: b           L_80028048
    // 0x80027180: nop

        goto L_80028048;
    // 0x80027180: nop

L_80027184:
    // 0x80027184: jal         0x80023C60
    // 0x80027188: nop

    func_80023C60(rdram, ctx);
        goto after_77;
    // 0x80027188: nop

    after_77:
    // 0x8002718C: beq         $v0, $zero, L_8002719C
    if (ctx->r2 == 0) {
        // 0x80027190: nop
    
            goto L_8002719C;
    }
    // 0x80027190: nop

    // 0x80027194: b           L_80028048
    // 0x80027198: nop

        goto L_80028048;
    // 0x80027198: nop

L_8002719C:
    // 0x8002719C: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800271A0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800271A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800271A8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800271AC: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x800271B0: nop

    // 0x800271B4: bc1f        L_80027320
    if (!c1cs) {
        // 0x800271B8: nop
    
            goto L_80027320;
    }
    // 0x800271B8: nop

    // 0x800271BC: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800271C0: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800271C4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800271C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800271CC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800271D0: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x800271D4: nop

    // 0x800271D8: bc1f        L_80027298
    if (!c1cs) {
        // 0x800271DC: nop
    
            goto L_80027298;
    }
    // 0x800271DC: nop

    // 0x800271E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800271E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800271E8: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800271EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800271F0: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x800271F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800271F8: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x800271FC: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80027200: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80027204: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80027208: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002720C: jal         0x800C3D70
    // 0x80027210: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_78;
    // 0x80027210: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_78:
    // 0x80027214: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
    // 0x80027218: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x8002721C: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80027220: nop

    // 0x80027224: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80027228: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x8002722C: nop

    // 0x80027230: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80027234: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80027238: nop

    // 0x8002723C: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x80027240: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80027244: nop

    // 0x80027248: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
    // 0x8002724C: lw          $at, 0x10($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X10);
    // 0x80027250: nop

    // 0x80027254: sw          $at, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r1;
    // 0x80027258: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x8002725C: nop

    // 0x80027260: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    // 0x80027264: lw          $at, 0x18($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X18);
    // 0x80027268: nop

    // 0x8002726C: sw          $at, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r1;
    // 0x80027270: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80027274: nop

    // 0x80027278: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x8002727C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80027280: sh          $t9, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r25;
    // 0x80027284: addiu       $t0, $zero, 0x4E
    ctx->r8 = ADD32(0, 0X4E);
    // 0x80027288: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002728C: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x80027290: b           L_80028048
    // 0x80027294: nop

        goto L_80028048;
    // 0x80027294: nop

L_80027298:
    // 0x80027298: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002729C: lhu         $t5, 0x10F2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X10F2);
    // 0x800272A0: lhu         $t1, 0x118($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X118);
    // 0x800272A4: nop

    // 0x800272A8: and         $t3, $t1, $t5
    ctx->r11 = ctx->r9 & ctx->r13;
    // 0x800272AC: beq         $t3, $zero, L_80027320
    if (ctx->r11 == 0) {
        // 0x800272B0: nop
    
            goto L_80027320;
    }
    // 0x800272B0: nop

    // 0x800272B4: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800272B8: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x800272BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800272C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800272C4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800272C8: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x800272CC: nop

    // 0x800272D0: bc1f        L_800272E8
    if (!c1cs) {
        // 0x800272D4: nop
    
            goto L_800272E8;
    }
    // 0x800272D4: nop

    // 0x800272D8: addiu       $t2, $zero, 0x3E7
    ctx->r10 = ADD32(0, 0X3E7);
    // 0x800272DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800272E0: b           L_80027320
    // 0x800272E4: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
        goto L_80027320;
    // 0x800272E4: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
L_800272E8:
    // 0x800272E8: lh          $t8, 0x12A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X12A);
    // 0x800272EC: nop

    // 0x800272F0: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800272F4: bne         $at, $zero, L_80027320
    if (ctx->r1 != 0) {
        // 0x800272F8: nop
    
            goto L_80027320;
    }
    // 0x800272F8: nop

    // 0x800272FC: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80027300: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x80027304: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80027308: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002730C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80027310: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027314: addiu       $t9, $zero, 0x51
    ctx->r25 = ADD32(0, 0X51);
    // 0x80027318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002731C: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
L_80027320:
    // 0x80027320: b           L_80028048
    // 0x80027324: nop

        goto L_80028048;
    // 0x80027324: nop

L_80027328:
    // 0x80027328: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002732C: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x80027330: lhu         $t0, 0x11A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X11A);
    // 0x80027334: nop

    // 0x80027338: and         $t5, $t0, $t1
    ctx->r13 = ctx->r8 & ctx->r9;
    // 0x8002733C: beq         $t5, $zero, L_80027354
    if (ctx->r13 == 0) {
        // 0x80027340: nop
    
            goto L_80027354;
    }
    // 0x80027340: nop

    // 0x80027344: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80027348: lhu         $a0, 0x126C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X126C);
    // 0x8002734C: jal         0x80023CA0
    // 0x80027350: nop

    func_80023CA0(rdram, ctx);
        goto after_79;
    // 0x80027350: nop

    after_79:
L_80027354:
    // 0x80027354: lwc1        $f16, 0x10C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80027358: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8002735C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80027360: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80027364: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    // 0x80027368: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8002736C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80027370: nop

    // 0x80027374: bc1t        L_800273A0
    if (c1cs) {
        // 0x80027378: nop
    
            goto L_800273A0;
    }
    // 0x80027378: nop

    // 0x8002737C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80027380: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80027384: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80027388: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002738C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80027390: c.eq.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d == ctx->f16.d;
    // 0x80027394: nop

    // 0x80027398: bc1f        L_800273C4
    if (!c1cs) {
        // 0x8002739C: nop
    
            goto L_800273C4;
    }
    // 0x8002739C: nop

L_800273A0:
    // 0x800273A0: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800273A4: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800273A8: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x800273AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800273B0: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x800273B4: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x800273B8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800273BC: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x800273C0: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
L_800273C4:
    // 0x800273C4: b           L_80028048
    // 0x800273C8: nop

        goto L_80028048;
    // 0x800273C8: nop

L_800273CC:
    // 0x800273CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800273D0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800273D4: addiu       $t4, $t4, 0x5B0
    ctx->r12 = ADD32(ctx->r12, 0X5B0);
    // 0x800273D8: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800273DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800273E0: lw          $t6, 0xD70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD70);
    // 0x800273E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800273E8: lwc1        $f6, 0xD98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD98);
    // 0x800273EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800273F0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800273F4: addiu       $a3, $a3, 0x5B0
    ctx->r7 = ADD32(ctx->r7, 0X5B0);
    // 0x800273F8: addiu       $a0, $a0, 0xD78
    ctx->r4 = ADD32(ctx->r4, 0XD78);
    // 0x800273FC: addiu       $a1, $t6, 0x8
    ctx->r5 = ADD32(ctx->r14, 0X8);
    // 0x80027400: addiu       $a2, $t6, 0xC
    ctx->r6 = ADD32(ctx->r14, 0XC);
    // 0x80027404: jal         0x800C3F2C
    // 0x80027408: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_80;
    // 0x80027408: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_80:
    // 0x8002740C: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x80027410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027414: bne         $t9, $at, L_80027440
    if (ctx->r25 != ctx->r1) {
        // 0x80027418: nop
    
            goto L_80027440;
    }
    // 0x80027418: nop

    // 0x8002741C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80027420: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80027424: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x80027428: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002742C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80027430: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80027434: addiu       $t3, $zero, 0x5B
    ctx->r11 = ADD32(0, 0X5B);
    // 0x80027438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002743C: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
L_80027440:
    // 0x80027440: b           L_80028048
    // 0x80027444: nop

        goto L_80028048;
    // 0x80027444: nop

L_80027448:
    // 0x80027448: lhu         $t2, 0x11A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X11A);
    // 0x8002744C: lhu         $t8, 0x116($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X116);
    // 0x80027450: nop

    // 0x80027454: and         $t7, $t2, $t8
    ctx->r15 = ctx->r10 & ctx->r24;
    // 0x80027458: beq         $t7, $zero, L_800274C8
    if (ctx->r15 == 0) {
        // 0x8002745C: nop
    
            goto L_800274C8;
    }
    // 0x8002745C: nop

    // 0x80027460: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    // 0x80027464: addiu       $a1, $sp, 0x134
    ctx->r5 = ADD32(ctx->r29, 0X134);
    // 0x80027468: jal         0x80023634
    // 0x8002746C: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    func_80023634(rdram, ctx);
        goto after_81;
    // 0x8002746C: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    after_81:
    // 0x80027470: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x80027474: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80027478: lwc1        $f4, 0x1B0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1B0);
    // 0x8002747C: lw          $t6, 0xD70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD70);
    // 0x80027480: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x80027484: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x80027488: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002748C: lw          $t0, 0x1B50($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B50);
    // 0x80027490: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x80027494: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80027498: lwc1        $f18, 0x1B4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X1B4);
    // 0x8002749C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800274A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800274A4: lw          $t1, 0xD70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD70);
    // 0x800274A8: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800274AC: swc1        $f18, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f18.u32l;
    // 0x800274B0: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x800274B4: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800274B8: nop

    // 0x800274BC: lh          $t3, 0x24($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X24);
    // 0x800274C0: b           L_8002756C
    // 0x800274C4: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
        goto L_8002756C;
    // 0x800274C4: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_800274C8:
    // 0x800274C8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800274CC: lw          $t2, 0xD70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XD70);
    // 0x800274D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800274D4: lbu         $s1, 0x10($t2)
    ctx->r17 = MEM_BU(ctx->r10, 0X10);
    // 0x800274D8: lwc1        $f6, 0xDA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XDA0);
    // 0x800274DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800274E0: sll         $t8, $s1, 5
    ctx->r24 = S32(ctx->r17 << 5);
    // 0x800274E4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800274E8: sh          $s1, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r17;
    // 0x800274EC: swc1        $f6, 0x24D8($at)
    MEM_W(0X24D8, ctx->r1) = ctx->f6.u32l;
    // 0x800274F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800274F4: lwc1        $f4, 0xE48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE48);
    // 0x800274F8: lh          $t7, 0x13E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13E);
    // 0x800274FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80027500: sll         $t4, $t7, 5
    ctx->r12 = S32(ctx->r15 << 5);
    // 0x80027504: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80027508: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8002750C: swc1        $f8, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->f8.u32l;
    // 0x80027510: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80027514: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80027518: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002751C: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80027520: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80027524: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027528: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x8002752C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027530: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027534: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80027538: lw          $t0, 0xD70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD70);
    // 0x8002753C: nop

    // 0x80027540: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x80027544: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80027548: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002754C: sb          $t1, 0xE54($at)
    MEM_B(0XE54, ctx->r1) = ctx->r9;
    // 0x80027550: sh          $zero, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = 0;
    // 0x80027554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027558: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
    // 0x8002755C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027560: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027568: swc1        $f18, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f18.u32l;
L_8002756C:
    // 0x8002756C: b           L_80028048
    // 0x80027570: nop

        goto L_80028048;
    // 0x80027570: nop

L_80027574:
    // 0x80027574: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027578: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002757C: nop

    // 0x80027580: c.eq.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl == ctx->f10.fl;
    // 0x80027584: nop

    // 0x80027588: bc1f        L_800275B8
    if (!c1cs) {
        // 0x8002758C: nop
    
            goto L_800275B8;
    }
    // 0x8002758C: nop

    // 0x80027590: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80027594: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027598: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002759C: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x800275A0: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x800275A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800275A8: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800275AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800275B0: b           L_80027604
    // 0x800275B4: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
        goto L_80027604;
    // 0x800275B4: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_800275B8:
    // 0x800275B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800275BC: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800275C0: lwc1        $f9, -0x1A68($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A68);
    // 0x800275C4: lwc1        $f8, -0x1A64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A64);
    // 0x800275C8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800275CC: mul.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800275D0: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x800275D4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800275D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800275DC: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800275E0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800275E4: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x800275E8: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
    // 0x800275EC: bc1f        L_80027604
    if (!c1cs) {
        // 0x800275F0: nop
    
            goto L_80027604;
    }
    // 0x800275F0: nop

    // 0x800275F4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800275F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800275FC: nop

    // 0x80027600: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
L_80027604:
    // 0x80027604: b           L_80028048
    // 0x80027608: nop

        goto L_80028048;
    // 0x80027608: nop

L_8002760C:
    // 0x8002760C: lw          $t2, 0x120($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X120);
    // 0x80027610: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027614: bne         $t2, $at, L_8002769C
    if (ctx->r10 != ctx->r1) {
        // 0x80027618: nop
    
            goto L_8002769C;
    }
    // 0x80027618: nop

    // 0x8002761C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80027620: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x80027624: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80027628: bne         $t8, $at, L_8002764C
    if (ctx->r24 != ctx->r1) {
        // 0x8002762C: nop
    
            goto L_8002764C;
    }
    // 0x8002762C: nop

    // 0x80027630: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x80027634: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x80027638: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x8002763C: nop

    // 0x80027640: ori         $t6, $t4, 0x10
    ctx->r14 = ctx->r12 | 0X10;
    // 0x80027644: b           L_80027654
    // 0x80027648: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
        goto L_80027654;
    // 0x80027648: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
L_8002764C:
    // 0x8002764C: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x80027650: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
L_80027654:
    // 0x80027654: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80027658: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002765C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80027660: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x80027664: addiu       $t5, $zero, 0x15
    ctx->r13 = ADD32(0, 0X15);
    // 0x80027668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002766C: sh          $t5, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r13;
    // 0x80027670: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80027674: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80027678: nop

    // 0x8002767C: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80027680: nop

    // 0x80027684: bc1f        L_80027694
    if (!c1cs) {
        // 0x80027688: nop
    
            goto L_80027694;
    }
    // 0x80027688: nop

    // 0x8002768C: b           L_8002769C
    // 0x80027690: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_8002769C;
    // 0x80027690: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80027694:
    // 0x80027694: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80027698: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_8002769C:
    // 0x8002769C: b           L_80028048
    // 0x800276A0: nop

        goto L_80028048;
    // 0x800276A0: nop

L_800276A4:
    // 0x800276A4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800276A8: lh          $t2, 0x66C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X66C);
    // 0x800276AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800276B0: bne         $t2, $at, L_800276F4
    if (ctx->r10 != ctx->r1) {
        // 0x800276B4: nop
    
            goto L_800276F4;
    }
    // 0x800276B4: nop

    // 0x800276B8: lh          $t8, 0x134($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X134);
    // 0x800276BC: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800276C0: beq         $t8, $at, L_800276F4
    if (ctx->r24 == ctx->r1) {
        // 0x800276C4: nop
    
            goto L_800276F4;
    }
    // 0x800276C4: nop

    // 0x800276C8: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x800276CC: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x800276D0: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x800276D4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800276D8: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x800276DC: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x800276E0: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800276E4: nop

    // 0x800276E8: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x800276EC: b           L_80027730
    // 0x800276F0: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
        goto L_80027730;
    // 0x800276F0: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
L_800276F4:
    // 0x800276F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800276F8: lh          $t1, 0x66C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X66C);
    // 0x800276FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80027700: beq         $t1, $at, L_80027730
    if (ctx->r9 == ctx->r1) {
        // 0x80027704: nop
    
            goto L_80027730;
    }
    // 0x80027704: nop

    // 0x80027708: lh          $t5, 0x134($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X134);
    // 0x8002770C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80027710: beq         $t5, $at, L_80027730
    if (ctx->r13 == ctx->r1) {
        // 0x80027714: nop
    
            goto L_80027730;
    }
    // 0x80027714: nop

    // 0x80027718: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    // 0x8002771C: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80027720: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80027724: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027728: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x8002772C: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_80027730:
    // 0x80027730: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80027734: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80027738: nop

    // 0x8002773C: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80027740: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x80027744: andi        $t6, $t4, 0x4
    ctx->r14 = ctx->r12 & 0X4;
    // 0x80027748: bne         $t6, $zero, L_800277B8
    if (ctx->r14 != 0) {
        // 0x8002774C: andi        $t7, $t5, 0x0
        ctx->r15 = ctx->r13 & 0X0;
            goto L_800277B8;
    }
    // 0x8002774C: andi        $t7, $t5, 0x0
    ctx->r15 = ctx->r13 & 0X0;
    // 0x80027750: bne         $t7, $zero, L_800277B8
    if (ctx->r15 != 0) {
        // 0x80027754: nop
    
            goto L_800277B8;
    }
    // 0x80027754: nop

    // 0x80027758: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8002775C: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x80027760: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80027764: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027768: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8002776C: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x80027770: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    // 0x80027774: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027778: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
    // 0x8002777C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027780: lwc1        $f16, 0xE78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80027784: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80027788: nop

    // 0x8002778C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80027790: nop

    // 0x80027794: bc1f        L_800277A4
    if (!c1cs) {
        // 0x80027798: nop
    
            goto L_800277A4;
    }
    // 0x80027798: nop

    // 0x8002779C: b           L_800277AC
    // 0x800277A0: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_800277AC;
    // 0x800277A0: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_800277A4:
    // 0x800277A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800277A8: sh          $t2, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r10;
L_800277AC:
    // 0x800277AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800277B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800277B4: swc1        $f6, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f6.u32l;
L_800277B8:
    // 0x800277B8: jal         0x80022E48
    // 0x800277BC: nop

    func_80022E48(rdram, ctx);
        goto after_82;
    // 0x800277BC: nop

    after_82:
    // 0x800277C0: bne         $v0, $zero, L_8002788C
    if (ctx->r2 != 0) {
        // 0x800277C4: nop
    
            goto L_8002788C;
    }
    // 0x800277C4: nop

    // 0x800277C8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800277CC: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x800277D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800277D4: bne         $t8, $at, L_8002788C
    if (ctx->r24 != ctx->r1) {
        // 0x800277D8: nop
    
            goto L_8002788C;
    }
    // 0x800277D8: nop

    // 0x800277DC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800277E0: lhu         $t5, 0xFF4($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XFF4);
    // 0x800277E4: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x800277E8: nop

    // 0x800277EC: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x800277F0: beq         $t6, $zero, L_80027838
    if (ctx->r14 == 0) {
        // 0x800277F4: nop
    
            goto L_80027838;
    }
    // 0x800277F4: nop

    // 0x800277F8: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x800277FC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027800: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80027804: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80027808: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    // 0x8002780C: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80027810: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x80027814: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027818: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x8002781C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80027820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027824: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x80027828: jal         0x80055FB8
    // 0x8002782C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_83;
    // 0x8002782C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_83:
    // 0x80027830: b           L_8002788C
    // 0x80027834: nop

        goto L_8002788C;
    // 0x80027834: nop

L_80027838:
    // 0x80027838: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002783C: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x80027840: lhu         $t2, 0x118($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X118);
    // 0x80027844: nop

    // 0x80027848: and         $t4, $t2, $t8
    ctx->r12 = ctx->r10 & ctx->r24;
    // 0x8002784C: beq         $t4, $zero, L_8002788C
    if (ctx->r12 == 0) {
        // 0x80027850: nop
    
            goto L_8002788C;
    }
    // 0x80027850: nop

    // 0x80027854: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027858: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002785C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80027860: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027864: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x80027868: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x8002786C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80027870: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027874: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80027878: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002787C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027880: sh          $t0, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r8;
    // 0x80027884: jal         0x80055FB8
    // 0x80027888: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_84;
    // 0x80027888: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_84:
L_8002788C:
    // 0x8002788C: b           L_80028048
    // 0x80027890: nop

        goto L_80028048;
    // 0x80027890: nop

L_80027894:
    // 0x80027894: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027898: lwc1        $f4, 0x1020($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x8002789C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278A0: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800278A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278A8: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800278AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800278B0: swc1        $f18, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f18.u32l;
    // 0x800278B4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x800278B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800278BC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800278C0: c.le.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d <= ctx->f16.d;
    // 0x800278C4: nop

    // 0x800278C8: bc1f        L_800279B0
    if (!c1cs) {
        // 0x800278CC: nop
    
            goto L_800279B0;
    }
    // 0x800278CC: nop

    // 0x800278D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278D4: lwc1        $f12, 0xE78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x800278D8: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800278DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800278E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278E4: lwc1        $f14, 0xEC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XEC4);
    // 0x800278E8: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x800278EC: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x800278F0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800278F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800278F8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800278FC: jal         0x800C3D70
    // 0x80027900: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_85;
    // 0x80027900: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_85:
    // 0x80027904: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80027908: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8002790C: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80027910: nop

    // 0x80027914: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80027918: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8002791C: nop

    // 0x80027920: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x80027924: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80027928: nop

    // 0x8002792C: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80027930: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x80027934: nop

    // 0x80027938: sw          $t4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r12;
    // 0x8002793C: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x80027940: nop

    // 0x80027944: sw          $at, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r1;
    // 0x80027948: lw          $t4, 0x14($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X14);
    // 0x8002794C: nop

    // 0x80027950: sw          $t4, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r12;
    // 0x80027954: lw          $at, 0x18($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X18);
    // 0x80027958: nop

    // 0x8002795C: sw          $at, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r1;
    // 0x80027960: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80027964: nop

    // 0x80027968: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x8002796C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027970: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027974: lwc1        $f11, -0x1A60($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A60);
    // 0x80027978: lwc1        $f10, -0x1A5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A5C);
    // 0x8002797C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80027980: mul.d       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80027984: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80027988: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x8002798C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027990: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027994: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027998: swc1        $f8, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f8.u32l;
    // 0x8002799C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800279A0: lh          $t5, 0x664($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X664);
    // 0x800279A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800279A8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800279AC: sh          $t6, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r14;
L_800279B0:
    // 0x800279B0: b           L_80028048
    // 0x800279B4: nop

        goto L_80028048;
    // 0x800279B4: nop

L_800279B8:
    // 0x800279B8: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x800279BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800279C0: bne         $t7, $at, L_800279EC
    if (ctx->r15 != ctx->r1) {
        // 0x800279C4: nop
    
            goto L_800279EC;
    }
    // 0x800279C4: nop

    // 0x800279C8: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800279CC: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800279D0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800279D4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800279D8: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x800279DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800279E0: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800279E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800279E8: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_800279EC:
    // 0x800279EC: b           L_80028048
    // 0x800279F0: nop

        goto L_80028048;
    // 0x800279F0: nop

L_800279F4:
    // 0x800279F4: jal         0x80022E48
    // 0x800279F8: nop

    func_80022E48(rdram, ctx);
        goto after_86;
    // 0x800279F8: nop

    after_86:
    // 0x800279FC: bne         $v0, $zero, L_80027A14
    if (ctx->r2 != 0) {
        // 0x80027A00: nop
    
            goto L_80027A14;
    }
    // 0x80027A00: nop

    // 0x80027A04: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x80027A08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027A0C: bne         $t1, $at, L_80027A4C
    if (ctx->r9 != ctx->r1) {
        // 0x80027A10: nop
    
            goto L_80027A4C;
    }
    // 0x80027A10: nop

L_80027A14:
    // 0x80027A14: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80027A18: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027A1C: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x80027A20: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x80027A24: addiu       $t2, $zero, 0x17
    ctx->r10 = ADD32(0, 0X17);
    // 0x80027A28: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80027A2C: addiu       $t4, $zero, 0x15
    ctx->r12 = ADD32(0, 0X15);
    // 0x80027A30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A34: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
    // 0x80027A38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A3C: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027A40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A44: b           L_80027AB4
    // 0x80027A48: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
        goto L_80027AB4;
    // 0x80027A48: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_80027A4C:
    // 0x80027A4C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80027A50: lh          $t5, 0x66C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X66C);
    // 0x80027A54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027A58: beq         $t5, $at, L_80027AB4
    if (ctx->r13 == ctx->r1) {
        // 0x80027A5C: nop
    
            goto L_80027AB4;
    }
    // 0x80027A5C: nop

    // 0x80027A60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80027A64: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80027A68: lhu         $t6, 0x118($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X118);
    // 0x80027A6C: nop

    // 0x80027A70: and         $t9, $t6, $t7
    ctx->r25 = ctx->r14 & ctx->r15;
    // 0x80027A74: beq         $t9, $zero, L_80027AB4
    if (ctx->r25 == 0) {
        // 0x80027A78: nop
    
            goto L_80027AB4;
    }
    // 0x80027A78: nop

    // 0x80027A7C: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
    // 0x80027A80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A84: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x80027A88: jal         0x80055FB8
    // 0x80027A8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_87;
    // 0x80027A8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_87:
    // 0x80027A90: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x80027A94: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x80027A98: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80027A9C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027AA0: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x80027AA4: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x80027AA8: addiu       $t2, $zero, 0x23
    ctx->r10 = ADD32(0, 0X23);
    // 0x80027AAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027AB0: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
L_80027AB4:
    // 0x80027AB4: b           L_80028048
    // 0x80027AB8: nop

        goto L_80028048;
    // 0x80027AB8: nop

L_80027ABC:
    // 0x80027ABC: jal         0x80022E48
    // 0x80027AC0: nop

    func_80022E48(rdram, ctx);
        goto after_88;
    // 0x80027AC0: nop

    after_88:
    // 0x80027AC4: bne         $v0, $zero, L_80027ADC
    if (ctx->r2 != 0) {
        // 0x80027AC8: nop
    
            goto L_80027ADC;
    }
    // 0x80027AC8: nop

    // 0x80027ACC: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x80027AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027AD4: bne         $t4, $at, L_80027B14
    if (ctx->r12 != ctx->r1) {
        // 0x80027AD8: nop
    
            goto L_80027B14;
    }
    // 0x80027AD8: nop

L_80027ADC:
    // 0x80027ADC: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027AE0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027AE4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80027AE8: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027AEC: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x80027AF0: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x80027AF4: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x80027AF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027AFC: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80027B00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B04: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027B08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B0C: b           L_80027B7C
    // 0x80027B10: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
        goto L_80027B7C;
    // 0x80027B10: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_80027B14:
    // 0x80027B14: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80027B18: lh          $t0, 0x66C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X66C);
    // 0x80027B1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027B20: beq         $t0, $at, L_80027B7C
    if (ctx->r8 == ctx->r1) {
        // 0x80027B24: nop
    
            goto L_80027B7C;
    }
    // 0x80027B24: nop

    // 0x80027B28: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80027B2C: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x80027B30: lhu         $t1, 0x118($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X118);
    // 0x80027B34: nop

    // 0x80027B38: and         $t3, $t1, $t8
    ctx->r11 = ctx->r9 & ctx->r24;
    // 0x80027B3C: beq         $t3, $zero, L_80027B7C
    if (ctx->r11 == 0) {
        // 0x80027B40: nop
    
            goto L_80027B7C;
    }
    // 0x80027B40: nop

    // 0x80027B44: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80027B48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B4C: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x80027B50: jal         0x80055FB8
    // 0x80027B54: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_89;
    // 0x80027B54: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_89:
    // 0x80027B58: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x80027B5C: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80027B60: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027B64: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027B68: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80027B6C: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027B70: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80027B74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B78: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
L_80027B7C:
    // 0x80027B7C: b           L_80028048
    // 0x80027B80: nop

        goto L_80028048;
    // 0x80027B80: nop

L_80027B84:
    // 0x80027B84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B88: lwc1        $f18, 0x1020($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x80027B8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B90: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80027B94: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80027B98: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80027B9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80027BA0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80027BA4: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80027BA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027BAC: bc1f        L_80027C0C
    if (!c1cs) {
        // 0x80027BB0: swc1        $f10, 0x1020($at)
        MEM_W(0X1020, ctx->r1) = ctx->f10.u32l;
            goto L_80027C0C;
    }
    // 0x80027BB0: swc1        $f10, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f10.u32l;
    // 0x80027BB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027BB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027BBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027BC0: swc1        $f8, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f8.u32l;
    // 0x80027BC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027BC8: lwc1        $f18, -0x1A58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1A58);
    // 0x80027BCC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80027BD0: nop

    // 0x80027BD4: swc1        $f18, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f18.u32l;
    // 0x80027BD8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80027BDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027BE0: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80027BE4: nop

    // 0x80027BE8: swc1        $f16, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f16.u32l;
    // 0x80027BEC: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80027BF0: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80027BF4: sh          $t1, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r9;
    // 0x80027BF8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80027BFC: lh          $t3, 0x664($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X664);
    // 0x80027C00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027C04: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80027C08: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
L_80027C0C:
    // 0x80027C0C: b           L_80028048
    // 0x80027C10: nop

        goto L_80028048;
    // 0x80027C10: nop

L_80027C14:
    // 0x80027C14: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x80027C18: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C1C: nop

    // 0x80027C20: lh          $t5, 0x11E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X11E);
    // 0x80027C24: nop

    // 0x80027C28: addiu       $t6, $t5, 0xF
    ctx->r14 = ADD32(ctx->r13, 0XF);
    // 0x80027C2C: sh          $t6, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r14;
    // 0x80027C30: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C34: nop

    // 0x80027C38: lh          $t9, 0x11E($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X11E);
    // 0x80027C3C: nop

    // 0x80027C40: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80027C44: bne         $at, $zero, L_80027C68
    if (ctx->r1 != 0) {
        // 0x80027C48: nop
    
            goto L_80027C68;
    }
    // 0x80027C48: nop

    // 0x80027C4C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C50: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80027C54: sh          $t0, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r8;
    // 0x80027C58: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x80027C5C: nop

    // 0x80027C60: ori         $t3, $t8, 0x1
    ctx->r11 = ctx->r24 | 0X1;
    // 0x80027C64: sh          $t3, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r11;
L_80027C68:
    // 0x80027C68: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027C6C: lwc1        $f11, -0x1A50($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A50);
    // 0x80027C70: lwc1        $f10, -0x1A4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A4C);
    // 0x80027C74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027C78: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80027C7C: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C80: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80027C84: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80027C88: lwc1        $f18, 0xF4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XF4);
    // 0x80027C8C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027C90: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80027C94: add.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f16.d + ctx->f8.d;
    // 0x80027C98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80027C9C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80027CA0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80027CA4: swc1        $f10, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f10.u32l;
    // 0x80027CA8: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80027CAC: nop

    // 0x80027CB0: lwc1        $f4, 0xF4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XF4);
    // 0x80027CB4: nop

    // 0x80027CB8: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80027CBC: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x80027CC0: nop

    // 0x80027CC4: bc1f        L_80027CF0
    if (!c1cs) {
        // 0x80027CC8: nop
    
            goto L_80027CF0;
    }
    // 0x80027CC8: nop

    // 0x80027CCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027CD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027CD4: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80027CD8: nop

    // 0x80027CDC: swc1        $f8, 0xF4($t6)
    MEM_W(0XF4, ctx->r14) = ctx->f8.u32l;
    // 0x80027CE0: lh          $t4, 0x13E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13E);
    // 0x80027CE4: nop

    // 0x80027CE8: ori         $t7, $t4, 0x2
    ctx->r15 = ctx->r12 | 0X2;
    // 0x80027CEC: sh          $t7, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r15;
L_80027CF0:
    // 0x80027CF0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027CF4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80027CF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027CFC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80027D00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027D04: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80027D08: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80027D0C: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80027D10: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027D14: lwc1        $f16, 0xF8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x80027D18: nop

    // 0x80027D1C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80027D20: sub.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f8.d - ctx->f18.d;
    // 0x80027D24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80027D28: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80027D2C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80027D30: swc1        $f6, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f6.u32l;
    // 0x80027D34: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80027D38: nop

    // 0x80027D3C: lwc1        $f4, 0xF8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x80027D40: nop

    // 0x80027D44: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80027D48: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x80027D4C: nop

    // 0x80027D50: bc1f        L_80027D7C
    if (!c1cs) {
        // 0x80027D54: nop
    
            goto L_80027D7C;
    }
    // 0x80027D54: nop

    // 0x80027D58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027D5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027D60: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80027D64: nop

    // 0x80027D68: swc1        $f18, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f18.u32l;
    // 0x80027D6C: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x80027D70: nop

    // 0x80027D74: ori         $t3, $t8, 0x4
    ctx->r11 = ctx->r24 | 0X4;
    // 0x80027D78: sh          $t3, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r11;
L_80027D7C:
    // 0x80027D7C: lh          $t2, 0x13E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X13E);
    // 0x80027D80: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80027D84: bne         $t2, $at, L_80027D9C
    if (ctx->r10 != ctx->r1) {
        // 0x80027D88: nop
    
            goto L_80027D9C;
    }
    // 0x80027D88: nop

    // 0x80027D8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027D90: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80027D94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027D98: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_80027D9C:
    // 0x80027D9C: b           L_80028048
    // 0x80027DA0: nop

        goto L_80028048;
    // 0x80027DA0: nop

L_80027DA4:
    // 0x80027DA4: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027DA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027DAC: nop

    // 0x80027DB0: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x80027DB4: nop

    // 0x80027DB8: bc1f        L_80027DF0
    if (!c1cs) {
        // 0x80027DBC: nop
    
            goto L_80027DF0;
    }
    // 0x80027DBC: nop

    // 0x80027DC0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80027DC4: lh          $t5, 0x664($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X664);
    // 0x80027DC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027DCC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80027DD0: sh          $t6, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r14;
    // 0x80027DD4: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80027DD8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027DDC: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x80027DE0: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x80027DE4: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80027DE8: b           L_80027E3C
    // 0x80027DEC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
        goto L_80027E3C;
    // 0x80027DEC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
L_80027DF0:
    // 0x80027DF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027DF4: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027DF8: lwc1        $f9, -0x1A48($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A48);
    // 0x80027DFC: lwc1        $f8, -0x1A44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A44);
    // 0x80027E00: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80027E04: mul.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80027E08: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027E0C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80027E10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80027E14: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80027E18: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80027E1C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80027E20: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80027E24: bc1f        L_80027E3C
    if (!c1cs) {
        // 0x80027E28: nop
    
            goto L_80027E3C;
    }
    // 0x80027E28: nop

    // 0x80027E2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027E30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027E34: nop

    // 0x80027E38: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
L_80027E3C:
    // 0x80027E3C: b           L_80028048
    // 0x80027E40: nop

        goto L_80028048;
    // 0x80027E40: nop

L_80027E44:
    // 0x80027E44: b           L_80028048
    // 0x80027E48: nop

        goto L_80028048;
    // 0x80027E48: nop

L_80027E4C:
    // 0x80027E4C: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027E50: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80027E54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80027E58: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80027E5C: c.eq.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d == ctx->f10.d;
    // 0x80027E60: nop

    // 0x80027E64: bc1f        L_80027F50
    if (!c1cs) {
        // 0x80027E68: nop
    
            goto L_80027F50;
    }
    // 0x80027E68: nop

    // 0x80027E6C: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80027E70: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80027E74: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x80027E78: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80027E7C: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x80027E80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027E84: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80027E88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027E8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027E90: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x80027E94: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027E98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027E9C: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027EA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027EA4: swc1        $f4, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f4.u32l;
    // 0x80027EA8: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x80027EAC: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x80027EB0: sw          $t8, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r24;
    // 0x80027EB4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80027EB8: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x80027EBC: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x80027EC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80027EC4: sw          $t2, 0x228($t5)
    MEM_W(0X228, ctx->r13) = ctx->r10;
    // 0x80027EC8: lw          $t6, 0xCE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE8);
    // 0x80027ECC: nop

    // 0x80027ED0: lw          $t4, 0x228($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X228);
    // 0x80027ED4: nop

    // 0x80027ED8: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
    // 0x80027EDC: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
L_80027EE0:
    // 0x80027EE0: lh          $t0, 0x13E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X13E);
    // 0x80027EE4: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80027EE8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80027EEC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80027EF0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80027EF4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80027EF8: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80027EFC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80027F00: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x80027F04: sh          $t7, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r15;
    // 0x80027F08: lh          $t3, 0x13E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X13E);
    // 0x80027F0C: nop

    // 0x80027F10: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80027F14: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x80027F18: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80027F1C: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80027F20: bne         $at, $zero, L_80027EE0
    if (ctx->r1 != 0) {
        // 0x80027F24: sh          $t2, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r10;
            goto L_80027EE0;
    }
    // 0x80027F24: sh          $t2, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r10;
    // 0x80027F28: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80027F2C: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80027F30: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80027F34: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80027F38: sh          $t6, 0x224($t0)
    MEM_H(0X224, ctx->r8) = ctx->r14;
    // 0x80027F3C: lw          $t9, 0xCE8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE8);
    // 0x80027F40: nop

    // 0x80027F44: lhu         $t1, 0x224($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X224);
    // 0x80027F48: nop

    // 0x80027F4C: sh          $t1, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r9;
L_80027F50:
    // 0x80027F50: b           L_80028048
    // 0x80027F54: nop

        goto L_80028048;
    // 0x80027F54: nop

L_80027F58:
    // 0x80027F58: jal         0x800228A8
    // 0x80027F5C: nop

    func_800228A8(rdram, ctx);
        goto after_90;
    // 0x80027F5C: nop

    after_90:
    // 0x80027F60: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x80027F64: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80027F68: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80027F6C: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80027F70: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80027F74: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80027F78: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80027F7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027F80: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80027F84: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80027F88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027F8C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80027F90: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80027F94: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80027F98: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80027F9C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80027FA0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80027FA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80027FA8: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80027FAC: jal         0x800C3D70
    // 0x80027FB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_91;
    // 0x80027FB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_91:
    // 0x80027FB4: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
    // 0x80027FB8: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80027FBC: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80027FC0: nop

    // 0x80027FC4: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80027FC8: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x80027FCC: nop

    // 0x80027FD0: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x80027FD4: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80027FD8: nop

    // 0x80027FDC: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80027FE0: lw          $t1, 0xC($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC);
    // 0x80027FE4: nop

    // 0x80027FE8: sw          $t1, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r9;
    // 0x80027FEC: lw          $at, 0x10($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X10);
    // 0x80027FF0: nop

    // 0x80027FF4: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80027FF8: lw          $t1, 0x14($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X14);
    // 0x80027FFC: nop

    // 0x80028000: sw          $t1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r9;
    // 0x80028004: lw          $at, 0x18($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X18);
    // 0x80028008: nop

    // 0x8002800C: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x80028010: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80028014: nop

    // 0x80028018: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
    // 0x8002801C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80028020: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80028024: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80028028: nop

    // 0x8002802C: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80028030: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x80028034: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80028038: lh          $t9, 0x664($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X664);
    // 0x8002803C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028040: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80028044: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
L_80028048:
    // 0x80028048: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8002804C: nop

    // 0x80028050: andi        $t3, $t8, 0x2
    ctx->r11 = ctx->r24 & 0X2;
    // 0x80028054: bne         $t3, $zero, L_800280F8
    if (ctx->r11 != 0) {
        // 0x80028058: nop
    
            goto L_800280F8;
    }
    // 0x80028058: nop

    // 0x8002805C: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80028060: nop

    // 0x80028064: andi        $t0, $t2, 0x10
    ctx->r8 = ctx->r10 & 0X10;
    // 0x80028068: beq         $t0, $zero, L_800280B4
    if (ctx->r8 == 0) {
        // 0x8002806C: nop
    
            goto L_800280B4;
    }
    // 0x8002806C: nop

    // 0x80028070: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80028074: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80028078: lh          $a2, 0x134($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X134);
    // 0x8002807C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80028080: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x80028084: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80028088: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8002808C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80028090: jal         0x800B202C
    // 0x80028094: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_92;
    // 0x80028094: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_92:
    // 0x80028098: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002809C: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
    // 0x800280A0: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x800280A4: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800280A8: and         $t5, $t6, $at
    ctx->r13 = ctx->r14 & ctx->r1;
    // 0x800280AC: b           L_800280E8
    // 0x800280B0: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
        goto L_800280E8;
    // 0x800280B0: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
L_800280B4:
    // 0x800280B4: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800280B8: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800280BC: lh          $t4, 0x132($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X132);
    // 0x800280C0: lh          $a2, 0x134($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X134);
    // 0x800280C4: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800280C8: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x800280CC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800280D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800280D4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800280D8: jal         0x800B202C
    // 0x800280DC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_800B202C(rdram, ctx);
        goto after_93;
    // 0x800280DC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_93:
    // 0x800280E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800280E4: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
L_800280E8:
    // 0x800280E8: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800280EC: nop

    // 0x800280F0: ori         $t9, $t1, 0x2
    ctx->r25 = ctx->r9 | 0X2;
    // 0x800280F4: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
L_800280F8:
    // 0x800280F8: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800280FC: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80028100: nop

    // 0x80028104: swc1        $f8, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f8.u32l;
    // 0x80028108: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002810C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80028110: nop

    // 0x80028114: swc1        $f18, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f18.u32l;
    // 0x80028118: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002811C: lh          $t3, 0x664($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X664);
    // 0x80028120: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80028124: beq         $t3, $at, L_800281C8
    if (ctx->r11 == ctx->r1) {
        // 0x80028128: nop
    
            goto L_800281C8;
    }
    // 0x80028128: nop

    // 0x8002812C: jal         0x800C1850
    // 0x80028130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_94;
    // 0x80028130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_94:
    // 0x80028134: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80028138: jal         0x8009A14C
    // 0x8002813C: nop

    func_8009A14C(rdram, ctx);
        goto after_95;
    // 0x8002813C: nop

    after_95:
    // 0x80028140: jal         0x800C1A84
    // 0x80028144: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_96;
    // 0x80028144: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_96:
    // 0x80028148: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8002814C: nop

    // 0x80028150: lw          $t0, 0xC8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0XC8);
    // 0x80028154: nop

    // 0x80028158: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    // 0x8002815C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80028160: lh          $t6, 0x11A6($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X11A6);
    // 0x80028164: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x80028168: blez        $t6, L_800281C8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002816C: nop
    
            goto L_800281C8;
    }
    // 0x8002816C: nop

L_80028170:
    // 0x80028170: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x80028174: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80028178: nop

    // 0x8002817C: sw          $t5, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r13;
    // 0x80028180: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80028184: jal         0x800997D8
    // 0x80028188: nop

    func_800997D8(rdram, ctx);
        goto after_97;
    // 0x80028188: nop

    after_97:
    // 0x8002818C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80028190: nop

    // 0x80028194: addiu       $t9, $t1, 0x160
    ctx->r25 = ADD32(ctx->r9, 0X160);
    // 0x80028198: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    // 0x8002819C: jal         0x800C1AF4
    // 0x800281A0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_98;
    // 0x800281A0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_98:
    // 0x800281A4: lh          $t7, 0x13E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13E);
    // 0x800281A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800281AC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800281B0: lh          $t0, 0x11A6($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X11A6);
    // 0x800281B4: sll         $t3, $t8, 16
    ctx->r11 = S32(ctx->r24 << 16);
    // 0x800281B8: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800281BC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800281C0: bne         $at, $zero, L_80028170
    if (ctx->r1 != 0) {
        // 0x800281C4: sh          $t8, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r24;
            goto L_80028170;
    }
    // 0x800281C4: sh          $t8, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r24;
L_800281C8:
    // 0x800281C8: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800281CC: jal         0x800B3434
    // 0x800281D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_99;
    // 0x800281D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_99:
    // 0x800281D4: sh          $v0, 0x110($sp)
    MEM_H(0X110, ctx->r29) = ctx->r2;
    // 0x800281D8: lhu         $t6, 0x110($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X110);
    // 0x800281DC: nop

    // 0x800281E0: andi        $t5, $t6, 0x4000
    ctx->r13 = ctx->r14 & 0X4000;
    // 0x800281E4: beq         $t5, $zero, L_80028204
    if (ctx->r13 == 0) {
        // 0x800281E8: nop
    
            goto L_80028204;
    }
    // 0x800281E8: nop

    // 0x800281EC: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800281F0: jal         0x800B32E4
    // 0x800281F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B32E4(rdram, ctx);
        goto after_100;
    // 0x800281F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_100:
    // 0x800281F8: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x800281FC: jal         0x800B9000
    // 0x80028200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B9000(rdram, ctx);
        goto after_101;
    // 0x80028200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_101:
L_80028204:
    // 0x80028204: lhu         $t4, 0x110($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X110);
    // 0x80028208: nop

    // 0x8002820C: andi        $t1, $t4, 0x8000
    ctx->r9 = ctx->r12 & 0X8000;
    // 0x80028210: beq         $t1, $zero, L_80028230
    if (ctx->r9 == 0) {
        // 0x80028214: nop
    
            goto L_80028230;
    }
    // 0x80028214: nop

    // 0x80028218: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x8002821C: jal         0x800B32E4
    // 0x80028220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B32E4(rdram, ctx);
        goto after_102;
    // 0x80028220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_102:
    // 0x80028224: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80028228: jal         0x800B9000
    // 0x8002822C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B9000(rdram, ctx);
        goto after_103;
    // 0x8002822C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_103:
L_80028230:
    // 0x80028230: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80028234: lbu         $t9, 0x125A($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X125A);
    // 0x80028238: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002823C: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80028240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028244: sb          $t7, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r15;
    // 0x80028248: lh          $t8, 0x12C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X12C);
    // 0x8002824C: nop

    // 0x80028250: bne         $t8, $zero, L_80028260
    if (ctx->r24 != 0) {
        // 0x80028254: nop
    
            goto L_80028260;
    }
    // 0x80028254: nop

    // 0x80028258: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002825C: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
L_80028260:
    // 0x80028260: lh          $t3, 0x12E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X12E);
    // 0x80028264: nop

    // 0x80028268: beq         $t3, $zero, L_800282D0
    if (ctx->r11 == 0) {
        // 0x8002826C: nop
    
            goto L_800282D0;
    }
    // 0x8002826C: nop

    // 0x80028270: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80028274: lh          $t2, 0x66C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X66C);
    // 0x80028278: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002827C: beq         $t2, $at, L_800282D0
    if (ctx->r10 == ctx->r1) {
        // 0x80028280: nop
    
            goto L_800282D0;
    }
    // 0x80028280: nop

    // 0x80028284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80028288: beq         $t2, $at, L_800282D0
    if (ctx->r10 == ctx->r1) {
        // 0x8002828C: nop
    
            goto L_800282D0;
    }
    // 0x8002828C: nop

    // 0x80028290: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80028294: lh          $t0, 0x664($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X664);
    // 0x80028298: nop

    // 0x8002829C: beq         $t0, $zero, L_800282BC
    if (ctx->r8 == 0) {
        // 0x800282A0: nop
    
            goto L_800282BC;
    }
    // 0x800282A0: nop

    // 0x800282A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800282A8: beq         $t0, $at, L_800282BC
    if (ctx->r8 == ctx->r1) {
        // 0x800282AC: nop
    
            goto L_800282BC;
    }
    // 0x800282AC: nop

    // 0x800282B0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x800282B4: bne         $t0, $at, L_800282D0
    if (ctx->r8 != ctx->r1) {
        // 0x800282B8: nop
    
            goto L_800282D0;
    }
    // 0x800282B8: nop

L_800282BC:
    // 0x800282BC: lh          $a0, 0x12C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X12C);
    // 0x800282C0: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x800282C4: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x800282C8: jal         0x80022EE4
    // 0x800282CC: nop

    func_80022EE4(rdram, ctx);
        goto after_104;
    // 0x800282CC: nop

    after_104:
L_800282D0:
    // 0x800282D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800282D4: lw          $t6, 0x103C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X103C);
    // 0x800282D8: nop

    // 0x800282DC: beq         $t6, $zero, L_800282F4
    if (ctx->r14 == 0) {
        // 0x800282E0: nop
    
            goto L_800282F4;
    }
    // 0x800282E0: nop

    // 0x800282E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800282E8: lw          $a0, 0x103C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X103C);
    // 0x800282EC: jal         0x800BC980
    // 0x800282F0: nop

    SysMem_Free(rdram, ctx);
        goto after_105;
    // 0x800282F0: nop

    after_105:
L_800282F4:
    // 0x800282F4: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x800282F8: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800282FC: nop

    // 0x80028300: sw          $t5, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r13;
    // 0x80028304: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80028308: lw          $t1, 0x140($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X140);
    // 0x8002830C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028310: swc1        $f10, 0x1B0($t1)
    MEM_W(0X1B0, ctx->r9) = ctx->f10.u32l;
    // 0x80028314: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x80028318: nop

    // 0x8002831C: lwc1        $f6, 0x1B0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1B0);
    // 0x80028320: nop

    // 0x80028324: swc1        $f6, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f6.u32l;
    // 0x80028328: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002832C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x80028330: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028334: swc1        $f4, 0x1B4($t7)
    MEM_W(0X1B4, ctx->r15) = ctx->f4.u32l;
    // 0x80028338: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8002833C: nop

    // 0x80028340: lwc1        $f16, 0x1B4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1B4);
    // 0x80028344: nop

    // 0x80028348: swc1        $f16, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f16.u32l;
    // 0x8002834C: lh          $t3, 0x134($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X134);
    // 0x80028350: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80028354: nop

    // 0x80028358: sh          $t3, 0x22($t2)
    MEM_H(0X22, ctx->r10) = ctx->r11;
    // 0x8002835C: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x80028360: nop

    // 0x80028364: lh          $t6, 0x20($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X20);
    // 0x80028368: nop

    // 0x8002836C: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80028370: sh          $t5, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r13;
    // 0x80028374: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80028378: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x8002837C: nop

    // 0x80028380: swc1        $f8, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f8.u32l;
    // 0x80028384: lh          $t1, 0x132($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X132);
    // 0x80028388: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8002838C: nop

    // 0x80028390: sh          $t1, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r9;
    // 0x80028394: lh          $t7, 0x130($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X130);
    // 0x80028398: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8002839C: nop

    // 0x800283A0: sh          $t7, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r15;
    // 0x800283A4: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800283A8: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800283AC: nop

    // 0x800283B0: swc1        $f18, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f18.u32l;
    // 0x800283B4: lhu         $t2, 0x114($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X114);
    // 0x800283B8: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800283BC: nop

    // 0x800283C0: sh          $t2, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = ctx->r10;
    // 0x800283C4: jal         0x800C1A28
    // 0x800283C8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_106;
    // 0x800283C8: nop

    after_106:
    // 0x800283CC: b           L_800283DC
    // 0x800283D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800283DC;
    // 0x800283D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800283D4: b           L_800283DC
    // 0x800283D8: nop

        goto L_800283DC;
    // 0x800283D8: nop

L_800283DC:
    // 0x800283DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800283E0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800283E4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800283E8: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800283EC: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800283F0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800283F4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800283F8: jr          $ra
    // 0x800283FC: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x800283FC: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void func_800961C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800961C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800961C8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800961CC: addiu       $t7, $t7, -0x42B8
    ctx->r15 = ADD32(ctx->r15, -0X42B8);
    // 0x800961D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800961D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800961D8: lw          $t9, 0x400($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X400);
    // 0x800961DC: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800961E0: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x800961E4: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x800961E8: sw          $t0, 0x400($t2)
    MEM_W(0X400, ctx->r10) = ctx->r8;
    // 0x800961EC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800961F0: lw          $t4, -0x2878($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2878);
    // 0x800961F4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800961F8: addiu       $t3, $t3, -0x28B8
    ctx->r11 = ADD32(ctx->r11, -0X28B8);
    // 0x800961FC: beq         $t3, $t4, L_80096228
    if (ctx->r11 == ctx->r12) {
        // 0x80096200: nop
    
            goto L_80096228;
    }
    // 0x80096200: nop

    // 0x80096204: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096208: lw          $t5, -0x2878($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2878);
    // 0x8009620C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096210: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80096214: addiu       $t8, $t5, -0x2
    ctx->r24 = ADD32(ctx->r13, -0X2);
    // 0x80096218: sw          $t6, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r14;
    // 0x8009621C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096220: b           L_80096240
    // 0x80096224: sw          $t8, -0x2878($at)
    MEM_W(-0X2878, ctx->r1) = ctx->r24;
        goto L_80096240;
    // 0x80096224: sw          $t8, -0x2878($at)
    MEM_W(-0X2878, ctx->r1) = ctx->r24;
L_80096228:
    // 0x80096228: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8009622C: lw          $t9, -0x2878($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2878);
    // 0x80096230: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096234: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x80096238: nop

    // 0x8009623C: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
L_80096240:
    // 0x80096240: jr          $ra
    // 0x80096244: nop

    return;
    // 0x80096244: nop

    // 0x80096248: jr          $ra
    // 0x8009624C: nop

    return;
    // 0x8009624C: nop

;}
RECOMP_FUNC void func_800173D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800173D0: lw          $t6, 0x1A0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A0);
    // 0x800173D4: nop

    // 0x800173D8: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x800173DC: sw          $t7, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r15;
    // 0x800173E0: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x800173E4: sw          $zero, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = 0;
    // 0x800173E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800173EC: nop

    // 0x800173F0: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x800173F4: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x800173F8: nop

    // 0x800173FC: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x80017400: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017404: nop

    // 0x80017408: swc1        $f8, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f8.u32l;
    // 0x8001740C: lwc1        $f10, 0x1F4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x80017410: nop

    // 0x80017414: swc1        $f10, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f10.u32l;
    // 0x80017418: sw          $zero, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = 0;
    // 0x8001741C: sw          $zero, 0x210($a0)
    MEM_W(0X210, ctx->r4) = 0;
    // 0x80017420: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80017424: lw          $t8, -0x4538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4538);
    // 0x80017428: nop

    // 0x8001742C: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x80017430: jr          $ra
    // 0x80017434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80017434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80064C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064C60: jal         0x80061488
    // 0x80064C64: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064C64: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064C68: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064C6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064C70: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064C74: nop
    
            goto L_80064D04;
    }
    // 0x80064C74: nop

    // 0x80064C78: jal         0x80061488
    // 0x80064C7C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064C7C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064C80: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064C84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064C88: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064C8C: nop
    
            goto L_80064D04;
    }
    // 0x80064C8C: nop

    // 0x80064C90: jal         0x80061488
    // 0x80064C94: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064C94: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064C98: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064C9C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064CA0: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CA4: nop
    
            goto L_80064D04;
    }
    // 0x80064CA4: nop

    // 0x80064CA8: jal         0x80061488
    // 0x80064CAC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064CAC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064CB0: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064CB4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064CB8: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CBC: nop
    
            goto L_80064D04;
    }
    // 0x80064CBC: nop

    // 0x80064CC0: jal         0x80061488
    // 0x80064CC4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064CC4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064CC8: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064CCC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064CD0: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CD4: nop
    
            goto L_80064D04;
    }
    // 0x80064CD4: nop

    // 0x80064CD8: jal         0x8005F064
    // 0x80064CDC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064CDC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064CE0: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064CE4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064CE8: beq         $v0, $zero, L_80064D04
    if (ctx->r2 == 0) {
        // 0x80064CEC: nop
    
            goto L_80064D04;
    }
    // 0x80064CEC: nop

    // 0x80064CF0: jal         0x80061348
    // 0x80064CF4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064CF4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064CF8: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064CFC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064D00: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064D04:
    // 0x80064D04: b           L_80064D14
    // 0x80064D08: nop

        goto L_80064D14;
    // 0x80064D08: nop

    // 0x80064D0C: b           L_80064D14
    // 0x80064D10: nop

        goto L_80064D14;
    // 0x80064D10: nop

L_80064D14:
    // 0x80064D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064D1C: jr          $ra
    // 0x80064D20: nop

    return;
    // 0x80064D20: nop

;}
RECOMP_FUNC void func_800742FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800742FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074304: jal         0x80061348
    // 0x80074308: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074308: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007430C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074310: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074314: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074318: beq         $v0, $zero, L_80074334
    if (ctx->r2 == 0) {
        // 0x8007431C: nop
    
            goto L_80074334;
    }
    // 0x8007431C: nop

    // 0x80074320: jal         0x80061348
    // 0x80074324: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074324: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074328: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007432C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074330: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074334:
    // 0x80074334: b           L_80074344
    // 0x80074338: nop

        goto L_80074344;
    // 0x80074338: nop

    // 0x8007433C: b           L_80074344
    // 0x80074340: nop

        goto L_80074344;
    // 0x80074340: nop

L_80074344:
    // 0x80074344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007434C: jr          $ra
    // 0x80074350: nop

    return;
    // 0x80074350: nop

;}
RECOMP_FUNC void func_80077764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077764: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077768: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007776C: nop

    // 0x80077770: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077774: nop

    // 0x80077778: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007777C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077780: jr          $ra
    // 0x80077784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077788: jr          $ra
    // 0x8007778C: nop

    return;
    // 0x8007778C: nop

    // 0x80077790: jr          $ra
    // 0x80077794: nop

    return;
    // 0x80077794: nop

;}
RECOMP_FUNC void func_80073DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073DEC: jal         0x80061348
    // 0x80073DF0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073DF0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073DF4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073DF8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073DFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073E00: beq         $v0, $zero, L_80073E54
    if (ctx->r2 == 0) {
        // 0x80073E04: nop
    
            goto L_80073E54;
    }
    // 0x80073E04: nop

    // 0x80073E08: jal         0x80061348
    // 0x80073E0C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073E0C: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073E10: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073E14: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073E18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073E1C: beq         $v0, $zero, L_80073E54
    if (ctx->r2 == 0) {
        // 0x80073E20: nop
    
            goto L_80073E54;
    }
    // 0x80073E20: nop

    // 0x80073E24: jal         0x80061348
    // 0x80073E28: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073E28: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073E2C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073E30: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073E34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073E38: beq         $v0, $zero, L_80073E54
    if (ctx->r2 == 0) {
        // 0x80073E3C: nop
    
            goto L_80073E54;
    }
    // 0x80073E3C: nop

    // 0x80073E40: jal         0x80061348
    // 0x80073E44: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073E44: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073E48: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073E4C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073E50: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073E54:
    // 0x80073E54: b           L_80073E64
    // 0x80073E58: nop

        goto L_80073E64;
    // 0x80073E58: nop

    // 0x80073E5C: b           L_80073E64
    // 0x80073E60: nop

        goto L_80073E64;
    // 0x80073E60: nop

L_80073E64:
    // 0x80073E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073E6C: jr          $ra
    // 0x80073E70: nop

    return;
    // 0x80073E70: nop

;}
RECOMP_FUNC void alSynAddPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3C58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3C5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800D3C60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D3C64: jal         0x800C41A0
    // 0x800D3C68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3C68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D3C6C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800D3C70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3C74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D3C78: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x800D3C7C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800D3C80: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D3C84: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D3C88: jal         0x800C41A0
    // 0x800D3C8C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D3C8C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x800D3C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3C98: jr          $ra
    // 0x800D3C9C: nop

    return;
    // 0x800D3C9C: nop

;}
RECOMP_FUNC void func_800713E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800713E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800713E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800713E8: jal         0x80061348
    // 0x800713EC: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800713EC: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x800713F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800713F4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800713F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800713FC: beq         $v0, $zero, L_80071450
    if (ctx->r2 == 0) {
        // 0x80071400: nop
    
            goto L_80071450;
    }
    // 0x80071400: nop

    // 0x80071404: jal         0x80061348
    // 0x80071408: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071408: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x8007140C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071410: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071414: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071418: beq         $v0, $zero, L_80071450
    if (ctx->r2 == 0) {
        // 0x8007141C: nop
    
            goto L_80071450;
    }
    // 0x8007141C: nop

    // 0x80071420: jal         0x80061348
    // 0x80071424: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071424: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x80071428: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007142C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071430: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071434: beq         $v0, $zero, L_80071450
    if (ctx->r2 == 0) {
        // 0x80071438: nop
    
            goto L_80071450;
    }
    // 0x80071438: nop

    // 0x8007143C: jal         0x80061348
    // 0x80071440: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071440: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x80071444: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071448: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007144C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071450:
    // 0x80071450: b           L_80071460
    // 0x80071454: nop

        goto L_80071460;
    // 0x80071454: nop

    // 0x80071458: b           L_80071460
    // 0x8007145C: nop

        goto L_80071460;
    // 0x8007145C: nop

L_80071460:
    // 0x80071460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071468: jr          $ra
    // 0x8007146C: nop

    return;
    // 0x8007146C: nop

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
RECOMP_FUNC void func_800349C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800349C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800349C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800349C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800349CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800349D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800349D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800349D8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800349DC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800349E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800349E4: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800349E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800349EC: swc1        $f4, -0x3A78($at)
    MEM_W(-0X3A78, ctx->r1) = ctx->f4.u32l;
    // 0x800349F0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800349F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800349F8: nop

    // 0x800349FC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80034A00: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034A04: nop

    // 0x80034A08: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80034A0C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80034A10: beq         $t7, $zero, L_80034A64
    if (ctx->r15 == 0) {
        // 0x80034A14: nop
    
            goto L_80034A64;
    }
    // 0x80034A14: nop

    // 0x80034A18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80034A1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80034A20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80034A24: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034A28: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034A2C: nop

    // 0x80034A30: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80034A34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034A38: nop

    // 0x80034A3C: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80034A40: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80034A44: bne         $t7, $zero, L_80034A5C
    if (ctx->r15 != 0) {
        // 0x80034A48: nop
    
            goto L_80034A5C;
    }
    // 0x80034A48: nop

    // 0x80034A4C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80034A50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034A54: b           L_80034A74
    // 0x80034A58: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80034A74;
    // 0x80034A58: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80034A5C:
    // 0x80034A5C: b           L_80034A74
    // 0x80034A60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80034A74;
    // 0x80034A60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80034A64:
    // 0x80034A64: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80034A68: nop

    // 0x80034A6C: bltz        $t7, L_80034A5C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80034A70: nop
    
            goto L_80034A5C;
    }
    // 0x80034A70: nop

L_80034A74:
    // 0x80034A74: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80034A78: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x80034A7C: nop

    // 0x80034A80: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80034A84: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80034A88: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80034A8C: div.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80034A90: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80034A94: swc1        $f16, -0x3A74($at)
    MEM_W(-0X3A74, ctx->r1) = ctx->f16.u32l;
    // 0x80034A98: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80034A9C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80034AA0: nop

    // 0x80034AA4: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80034AA8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80034AAC: nop

    // 0x80034AB0: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80034AB4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80034AB8: beq         $t9, $zero, L_80034B0C
    if (ctx->r25 == 0) {
        // 0x80034ABC: nop
    
            goto L_80034B0C;
    }
    // 0x80034ABC: nop

    // 0x80034AC0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80034AC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034AC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80034ACC: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80034AD0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80034AD4: nop

    // 0x80034AD8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80034ADC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80034AE0: nop

    // 0x80034AE4: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80034AE8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80034AEC: bne         $t9, $zero, L_80034B04
    if (ctx->r25 != 0) {
        // 0x80034AF0: nop
    
            goto L_80034B04;
    }
    // 0x80034AF0: nop

    // 0x80034AF4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80034AF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034AFC: b           L_80034B1C
    // 0x80034B00: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80034B1C;
    // 0x80034B00: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80034B04:
    // 0x80034B04: b           L_80034B1C
    // 0x80034B08: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80034B1C;
    // 0x80034B08: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80034B0C:
    // 0x80034B0C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80034B10: nop

    // 0x80034B14: bltz        $t9, L_80034B04
    if (SIGNED(ctx->r25) < 0) {
        // 0x80034B18: nop
    
            goto L_80034B04;
    }
    // 0x80034B18: nop

L_80034B1C:
    // 0x80034B1C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80034B20: sh          $t9, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r25;
    // 0x80034B24: nop

    // 0x80034B28: lhu         $t0, 0x36($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X36);
    // 0x80034B2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80034B30: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80034B34: sh          $t1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r9;
    // 0x80034B38: sh          $t0, -0x3A70($at)
    MEM_H(-0X3A70, ctx->r1) = ctx->r8;
    // 0x80034B3C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80034B40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80034B44: sw          $t2, -0x3A6C($at)
    MEM_W(-0X3A6C, ctx->r1) = ctx->r10;
    // 0x80034B48: lhu         $t3, 0x3A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3A);
    // 0x80034B4C: nop

    // 0x80034B50: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80034B54: sh          $t4, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r12;
    // 0x80034B58: lhu         $t5, 0x1C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034B5C: nop

    // 0x80034B60: beq         $t5, $zero, L_80034BC4
    if (ctx->r13 == 0) {
        // 0x80034B64: nop
    
            goto L_80034BC4;
    }
    // 0x80034B64: nop

    // 0x80034B68: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034B6C: nop

    // 0x80034B70: beq         $t6, $zero, L_80034B8C
    if (ctx->r14 == 0) {
        // 0x80034B74: nop
    
            goto L_80034B8C;
    }
    // 0x80034B74: nop

    // 0x80034B78: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034B7C: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034B80: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80034B84: jal         0x800345E0
    // 0x80034B88: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800345E0(rdram, ctx);
        goto after_0;
    // 0x80034B88: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
L_80034B8C:
    // 0x80034B8C: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034B90: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034B94: jal         0x800345E0
    // 0x80034B98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800345E0(rdram, ctx);
        goto after_1;
    // 0x80034B98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_1:
    // 0x80034B9C: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034BA0: lhu         $t8, 0x36($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X36);
    // 0x80034BA4: nop

    // 0x80034BA8: beq         $t7, $t8, L_80034BC4
    if (ctx->r15 == ctx->r24) {
        // 0x80034BAC: nop
    
            goto L_80034BC4;
    }
    // 0x80034BAC: nop

    // 0x80034BB0: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034BB4: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034BB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034BBC: jal         0x800345E0
    // 0x80034BC0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800345E0(rdram, ctx);
        goto after_2;
    // 0x80034BC0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_2:
L_80034BC4:
    // 0x80034BC4: lhu         $t9, 0x1E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034BC8: nop

    // 0x80034BCC: beq         $t9, $zero, L_80034BE4
    if (ctx->r25 == 0) {
        // 0x80034BD0: nop
    
            goto L_80034BE4;
    }
    // 0x80034BD0: nop

    // 0x80034BD4: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034BD8: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034BDC: jal         0x800345E0
    // 0x80034BE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800345E0(rdram, ctx);
        goto after_3;
    // 0x80034BE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_3:
L_80034BE4:
    // 0x80034BE4: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034BE8: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034BEC: jal         0x800345E0
    // 0x80034BF0: nop

    func_800345E0(rdram, ctx);
        goto after_4;
    // 0x80034BF0: nop

    after_4:
    // 0x80034BF4: lhu         $t0, 0x1E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034BF8: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x80034BFC: nop

    // 0x80034C00: beq         $t0, $t1, L_80034C18
    if (ctx->r8 == ctx->r9) {
        // 0x80034C04: nop
    
            goto L_80034C18;
    }
    // 0x80034C04: nop

    // 0x80034C08: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034C0C: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034C10: jal         0x800345E0
    // 0x80034C14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800345E0(rdram, ctx);
        goto after_5;
    // 0x80034C14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_5:
L_80034C18:
    // 0x80034C18: lhu         $t2, 0x1C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034C1C: lhu         $t3, 0x3A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3A);
    // 0x80034C20: nop

    // 0x80034C24: beq         $t2, $t3, L_80034C88
    if (ctx->r10 == ctx->r11) {
        // 0x80034C28: nop
    
            goto L_80034C88;
    }
    // 0x80034C28: nop

    // 0x80034C2C: lhu         $t4, 0x1E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034C30: nop

    // 0x80034C34: beq         $t4, $zero, L_80034C50
    if (ctx->r12 == 0) {
        // 0x80034C38: nop
    
            goto L_80034C50;
    }
    // 0x80034C38: nop

    // 0x80034C3C: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034C40: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034C44: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80034C48: jal         0x800345E0
    // 0x80034C4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800345E0(rdram, ctx);
        goto after_6;
    // 0x80034C4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_6:
L_80034C50:
    // 0x80034C50: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034C54: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034C58: jal         0x800345E0
    // 0x80034C5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800345E0(rdram, ctx);
        goto after_7;
    // 0x80034C5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_7:
    // 0x80034C60: lhu         $t5, 0x1E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034C64: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x80034C68: nop

    // 0x80034C6C: beq         $t5, $t6, L_80034C88
    if (ctx->r13 == ctx->r14) {
        // 0x80034C70: nop
    
            goto L_80034C88;
    }
    // 0x80034C70: nop

    // 0x80034C74: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x80034C78: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x80034C7C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034C80: jal         0x800345E0
    // 0x80034C84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800345E0(rdram, ctx);
        goto after_8;
    // 0x80034C84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_8:
L_80034C88:
    // 0x80034C88: b           L_80034C90
    // 0x80034C8C: nop

        goto L_80034C90;
    // 0x80034C8C: nop

L_80034C90:
    // 0x80034C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80034C98: jr          $ra
    // 0x80034C9C: nop

    return;
    // 0x80034C9C: nop

;}
RECOMP_FUNC void func_80062A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062A30: jal         0x8005F064
    // 0x80062A34: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062A34: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80062A38: b           L_80062A48
    // 0x80062A3C: nop

        goto L_80062A48;
    // 0x80062A3C: nop

    // 0x80062A40: b           L_80062A48
    // 0x80062A44: nop

        goto L_80062A48;
    // 0x80062A44: nop

L_80062A48:
    // 0x80062A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062A50: jr          $ra
    // 0x80062A54: nop

    return;
    // 0x80062A54: nop

;}
RECOMP_FUNC void func_80066F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066F90: jal         0x80061348
    // 0x80066F94: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066F94: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x80066F98: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066FA0: bne         $v0, $zero, L_80066FE8
    if (ctx->r2 != 0) {
        // 0x80066FA4: nop
    
            goto L_80066FE8;
    }
    // 0x80066FA4: nop

    // 0x80066FA8: jal         0x80061348
    // 0x80066FAC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066FAC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_1:
    // 0x80066FB0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066FB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066FB8: bne         $v0, $zero, L_80066FE8
    if (ctx->r2 != 0) {
        // 0x80066FBC: nop
    
            goto L_80066FE8;
    }
    // 0x80066FBC: nop

    // 0x80066FC0: jal         0x80061348
    // 0x80066FC4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80066FC4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_2:
    // 0x80066FC8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066FCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80066FD0: bne         $v0, $zero, L_80066FE8
    if (ctx->r2 != 0) {
        // 0x80066FD4: nop
    
            goto L_80066FE8;
    }
    // 0x80066FD4: nop

    // 0x80066FD8: jal         0x80061348
    // 0x80066FDC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80066FDC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_3:
    // 0x80066FE0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066FE4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066FE8:
    // 0x80066FE8: b           L_80066FF8
    // 0x80066FEC: nop

        goto L_80066FF8;
    // 0x80066FEC: nop

    // 0x80066FF0: b           L_80066FF8
    // 0x80066FF4: nop

        goto L_80066FF8;
    // 0x80066FF4: nop

L_80066FF8:
    // 0x80066FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067000: jr          $ra
    // 0x80067004: nop

    return;
    // 0x80067004: nop

;}
RECOMP_FUNC void func_80075568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075568: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007556C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075570: nop

    // 0x80075574: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075578: nop

    // 0x8007557C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80075580: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075584: jr          $ra
    // 0x80075588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007558C: jr          $ra
    // 0x80075590: nop

    return;
    // 0x80075590: nop

    // 0x80075594: jr          $ra
    // 0x80075598: nop

    return;
    // 0x80075598: nop

;}
RECOMP_FUNC void func_800ABEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABEDC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800ABEE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800ABEE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEE8: swc1        $f12, 0x61C0($at)
    MEM_W(0X61C0, ctx->r1) = ctx->f12.u32l;
    // 0x800ABEEC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEF0: swc1        $f14, 0x61C4($at)
    MEM_W(0X61C4, ctx->r1) = ctx->f14.u32l;
    // 0x800ABEF4: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ABEF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEFC: swc1        $f4, 0x61C8($at)
    MEM_W(0X61C8, ctx->r1) = ctx->f4.u32l;
    // 0x800ABF00: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ABF04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF08: swc1        $f6, 0x61D0($at)
    MEM_W(0X61D0, ctx->r1) = ctx->f6.u32l;
    // 0x800ABF0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF10: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABF14: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF18: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x800ABF1C: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x800ABF20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF24: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABF28: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ABF2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF30: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ABF34: swc1        $f4, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f4.u32l;
    // 0x800ABF38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF3C: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABF40: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF44: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x800ABF48: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
    // 0x800ABF4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF50: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABF54: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ABF58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF5C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800ABF60: swc1        $f18, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f18.u32l;
    // 0x800ABF64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF68: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800ABF6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF70: lwc1        $f6, 0x61C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800ABF74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF78: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABF7C: nop

    // 0x800ABF80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ABF84: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800ABF88: nop

    // 0x800ABF8C: bc1f        L_800ABFB0
    if (!c1cs) {
        // 0x800ABF90: nop
    
            goto L_800ABFB0;
    }
    // 0x800ABF90: nop

    // 0x800ABF94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF98: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800ABF9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABFA0: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABFA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFA8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ABFAC: swc1        $f6, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f6.u32l;
L_800ABFB0:
    // 0x800ABFB0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFB4: lwc1        $f8, 0x6194($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800ABFB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFBC: lwc1        $f4, 0x61C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800ABFC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABFC4: lwc1        $f10, 0x7230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABFC8: nop

    // 0x800ABFCC: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800ABFD0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800ABFD4: nop

    // 0x800ABFD8: bc1f        L_800ABFFC
    if (!c1cs) {
        // 0x800ABFDC: nop
    
            goto L_800ABFFC;
    }
    // 0x800ABFDC: nop

    // 0x800ABFE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFE4: lwc1        $f18, 0x61C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800ABFE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABFEC: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABFF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFF4: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800ABFF8: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
L_800ABFFC:
    // 0x800ABFFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC000: lwc1        $f10, 0x6198($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC004: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC008: lwc1        $f8, 0x61C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC00C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC010: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC014: nop

    // 0x800AC018: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AC01C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800AC020: nop

    // 0x800AC024: bc1f        L_800AC048
    if (!c1cs) {
        // 0x800AC028: nop
    
            goto L_800AC048;
    }
    // 0x800AC028: nop

    // 0x800AC02C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC030: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC034: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC038: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC03C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC040: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AC044: swc1        $f8, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f8.u32l;
L_800AC048:
    // 0x800AC048: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC04C: lwc1        $f16, 0x619C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC050: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC054: lwc1        $f10, 0x61D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC058: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC05C: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC060: nop

    // 0x800AC064: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AC068: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800AC06C: nop

    // 0x800AC070: bc1f        L_800AC094
    if (!c1cs) {
        // 0x800AC074: nop
    
            goto L_800AC094;
    }
    // 0x800AC074: nop

    // 0x800AC078: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC07C: lwc1        $f4, 0x61D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC080: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC084: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC088: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC08C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800AC090: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
L_800AC094:
    // 0x800AC094: b           L_800AC09C
    // 0x800AC098: nop

        goto L_800AC09C;
    // 0x800AC098: nop

L_800AC09C:
    // 0x800AC09C: jr          $ra
    // 0x800AC0A0: nop

    return;
    // 0x800AC0A0: nop

;}
RECOMP_FUNC void func_8005A6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A6BC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005A6C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A6C4: nop

    // 0x8005A6C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8005A6CC: nop

    // 0x8005A6D0: bc1f        L_8005A71C
    if (!c1cs) {
        // 0x8005A6D4: nop
    
            goto L_8005A71C;
    }
    // 0x8005A6D4: nop

    // 0x8005A6D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A6DC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005A6E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005A6E4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005A6E8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005A6EC: bne         $t0, $zero, L_8005A70C
    if (ctx->r8 != 0) {
        // 0x8005A6F0: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_8005A70C;
    }
    // 0x8005A6F0: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x8005A6F4: bne         $t1, $zero, L_8005A70C
    if (ctx->r9 != 0) {
        // 0x8005A6F8: nop
    
            goto L_8005A70C;
    }
    // 0x8005A6F8: nop

    // 0x8005A6FC: jr          $ra
    // 0x8005A700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A704: b           L_8005A714
    // 0x8005A708: nop

        goto L_8005A714;
    // 0x8005A708: nop

L_8005A70C:
    // 0x8005A70C: jr          $ra
    // 0x8005A710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005A710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A714:
    // 0x8005A714: b           L_8005A758
    // 0x8005A718: nop

        goto L_8005A758;
    // 0x8005A718: nop

L_8005A71C:
    // 0x8005A71C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A720: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A724: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005A728: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005A72C: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8005A730: bne         $t4, $zero, L_8005A740
    if (ctx->r12 != 0) {
        // 0x8005A734: andi        $t5, $t3, 0x8
        ctx->r13 = ctx->r11 & 0X8;
            goto L_8005A740;
    }
    // 0x8005A734: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x8005A738: beq         $t5, $zero, L_8005A750
    if (ctx->r13 == 0) {
        // 0x8005A73C: nop
    
            goto L_8005A750;
    }
    // 0x8005A73C: nop

L_8005A740:
    // 0x8005A740: jr          $ra
    // 0x8005A744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A748: b           L_8005A758
    // 0x8005A74C: nop

        goto L_8005A758;
    // 0x8005A74C: nop

L_8005A750:
    // 0x8005A750: jr          $ra
    // 0x8005A754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005A754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A758:
    // 0x8005A758: jr          $ra
    // 0x8005A75C: nop

    return;
    // 0x8005A75C: nop

    // 0x8005A760: jr          $ra
    // 0x8005A764: nop

    return;
    // 0x8005A764: nop

;}
RECOMP_FUNC void func_800768B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800768B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800768B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800768B8: jal         0x80061348
    // 0x800768BC: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800768BC: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x800768C0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800768C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800768C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800768CC: beq         $v0, $zero, L_80076904
    if (ctx->r2 == 0) {
        // 0x800768D0: nop
    
            goto L_80076904;
    }
    // 0x800768D0: nop

    // 0x800768D4: jal         0x80061348
    // 0x800768D8: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800768D8: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x800768DC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800768E0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800768E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800768E8: beq         $v0, $zero, L_80076904
    if (ctx->r2 == 0) {
        // 0x800768EC: nop
    
            goto L_80076904;
    }
    // 0x800768EC: nop

    // 0x800768F0: jal         0x80061348
    // 0x800768F4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800768F4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x800768F8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800768FC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80076900: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076904:
    // 0x80076904: b           L_80076914
    // 0x80076908: nop

        goto L_80076914;
    // 0x80076908: nop

    // 0x8007690C: b           L_80076914
    // 0x80076910: nop

        goto L_80076914;
    // 0x80076910: nop

L_80076914:
    // 0x80076914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007691C: jr          $ra
    // 0x80076920: nop

    return;
    // 0x80076920: nop

;}
RECOMP_FUNC void func_80063920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063920: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063924: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063928: nop

    // 0x8006392C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80063930: nop

    // 0x80063934: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80063938: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006393C: jr          $ra
    // 0x80063940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063944: jr          $ra
    // 0x80063948: nop

    return;
    // 0x80063948: nop

    // 0x8006394C: jr          $ra
    // 0x80063950: nop

    return;
    // 0x80063950: nop

;}
RECOMP_FUNC void func_80078168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078168: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007816C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80078170: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80078174: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80078178: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8007817C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80078180: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80078184: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80078188: jal         0x8009A3E8
    // 0x8007818C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_8009A3E8(rdram, ctx);
        goto after_0;
    // 0x8007818C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80078190: bgez        $v0, L_800781C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078194: nop
    
            goto L_800781C0;
    }
    // 0x80078194: nop

    // 0x80078198: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007819C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800781A0: nop

    // 0x800781A4: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800781A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800781AC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800781B0: nop

    // 0x800781B4: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800781B8: b           L_80078298
    // 0x800781BC: nop

        goto L_80078298;
    // 0x800781BC: nop

L_800781C0:
    // 0x800781C0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800781C4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800781C8: lwc1        $f8, 0xCC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x800781CC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800781D0: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x800781D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800781D8: lhu         $t9, 0x62($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X62);
    // 0x800781DC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800781E0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800781E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800781E8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800781EC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800781F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800781F4: jal         0x8007915C
    // 0x800781F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8007915C(rdram, ctx);
        goto after_1;
    // 0x800781F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x800781FC: jal         0x8001AB84
    // 0x80078200: nop

    func_8001AB84(rdram, ctx);
        goto after_2;
    // 0x80078200: nop

    after_2:
    // 0x80078204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80078208: jal         0x8008EAA8
    // 0x8007820C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x8007820C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80078210: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80078214: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80078218: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007821C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80078220: swc1        $f19, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x80078224: lwc1        $f4, 0xCC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x80078228: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007822C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80078230: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80078234: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80078238: swc1        $f7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x8007823C: lwc1        $f8, 0xD0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80078240: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80078244: mfc1        $a2, $f11
    ctx->r6 = (int32_t)ctx->f_odd[(11 - 1) * 2];
    // 0x80078248: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007824C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80078250: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80078254: swc1        $f11, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
    // 0x80078258: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8007825C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80078260: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80078264: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80078268: swc1        $f19, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8007826C: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80078270: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80078274: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80078278: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8007827C: swc1        $f7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x80078280: jal         0x8008ECE4
    // 0x80078284: addiu       $a0, $a0, -0xE00
    ctx->r4 = ADD32(ctx->r4, -0XE00);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x80078284: addiu       $a0, $a0, -0xE00
    ctx->r4 = ADD32(ctx->r4, -0XE00);
    after_4:
    // 0x80078288: jal         0x8001AC74
    // 0x8007828C: nop

    func_8001AC74(rdram, ctx);
        goto after_5;
    // 0x8007828C: nop

    after_5:
    // 0x80078290: b           L_80078298
    // 0x80078294: nop

        goto L_80078298;
    // 0x80078294: nop

L_80078298:
    // 0x80078298: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007829C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800782A0: jr          $ra
    // 0x800782A4: nop

    return;
    // 0x800782A4: nop

;}
RECOMP_FUNC void func_8006543C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006543C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065444: jal         0x8005F064
    // 0x80065448: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065448: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    after_0:
    // 0x8006544C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80065450: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065454: beq         $v0, $zero, L_8006546C
    if (ctx->r2 == 0) {
        // 0x80065458: nop
    
            goto L_8006546C;
    }
    // 0x80065458: nop

    // 0x8006545C: jal         0x8005F064
    // 0x80065460: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80065460: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_1:
    // 0x80065464: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065468: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006546C:
    // 0x8006546C: b           L_8006547C
    // 0x80065470: nop

        goto L_8006547C;
    // 0x80065470: nop

    // 0x80065474: b           L_8006547C
    // 0x80065478: nop

        goto L_8006547C;
    // 0x80065478: nop

L_8006547C:
    // 0x8006547C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065484: jr          $ra
    // 0x80065488: nop

    return;
    // 0x80065488: nop

;}
RECOMP_FUNC void func_80022E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022E50: sh          $zero, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = 0;
    // 0x80022E54: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80022E58: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80022E5C: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x80022E60: nop

    // 0x80022E64: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x80022E68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80022E6C: lhu         $t9, 0x1258($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1258);
    // 0x80022E70: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x80022E74: nop

    // 0x80022E78: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80022E7C: bne         $t0, $zero, L_80022E9C
    if (ctx->r8 != 0) {
        // 0x80022E80: nop
    
            goto L_80022E9C;
    }
    // 0x80022E80: nop

    // 0x80022E84: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022E88: lhu         $t1, 0x1042($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1042);
    // 0x80022E8C: nop

    // 0x80022E90: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x80022E94: beq         $t2, $zero, L_80022EC0
    if (ctx->r10 == 0) {
        // 0x80022E98: nop
    
            goto L_80022EC0;
    }
    // 0x80022E98: nop

L_80022E9C:
    // 0x80022E9C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80022EA0: lh          $t3, 0x66C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X66C);
    // 0x80022EA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022EA8: bne         $t3, $at, L_80022EC0
    if (ctx->r11 != ctx->r1) {
        // 0x80022EAC: nop
    
            goto L_80022EC0;
    }
    // 0x80022EAC: nop

    // 0x80022EB0: jal         0x80055FB8
    // 0x80022EB4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80055FB8(rdram, ctx);
        goto after_0;
    // 0x80022EB4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x80022EB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80022EBC: sh          $t4, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r12;
L_80022EC0:
    // 0x80022EC0: lh          $v0, 0x1C($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1C);
    // 0x80022EC4: b           L_80022ED4
    // 0x80022EC8: nop

        goto L_80022ED4;
    // 0x80022EC8: nop

    // 0x80022ECC: b           L_80022ED4
    // 0x80022ED0: nop

        goto L_80022ED4;
    // 0x80022ED0: nop

L_80022ED4:
    // 0x80022ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022EDC: jr          $ra
    // 0x80022EE0: nop

    return;
    // 0x80022EE0: nop

;}
RECOMP_FUNC void func_8006439C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006439C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800643A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800643A4: jal         0x80061488
    // 0x800643A8: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800643A8: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    after_0:
    // 0x800643AC: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x800643B0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800643B4: b           L_800643C4
    // 0x800643B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800643C4;
    // 0x800643B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800643BC: b           L_800643C4
    // 0x800643C0: nop

        goto L_800643C4;
    // 0x800643C0: nop

L_800643C4:
    // 0x800643C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800643C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800643CC: jr          $ra
    // 0x800643D0: nop

    return;
    // 0x800643D0: nop

;}
RECOMP_FUNC void func_800734C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800734C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800734C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800734C8: jal         0x80061488
    // 0x800734CC: addiu       $a0, $zero, 0x63F
    ctx->r4 = ADD32(0, 0X63F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800734CC: addiu       $a0, $zero, 0x63F
    ctx->r4 = ADD32(0, 0X63F);
    after_0:
    // 0x800734D0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800734D4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800734D8: b           L_800734E8
    // 0x800734DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800734E8;
    // 0x800734DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800734E0: b           L_800734E8
    // 0x800734E4: nop

        goto L_800734E8;
    // 0x800734E4: nop

L_800734E8:
    // 0x800734E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800734EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800734F0: jr          $ra
    // 0x800734F4: nop

    return;
    // 0x800734F4: nop

;}
RECOMP_FUNC void func_80073088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073088: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007308C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073090: nop

    // 0x80073094: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073098: nop

    // 0x8007309C: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x800730A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800730A4: jr          $ra
    // 0x800730A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800730A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800730AC: jr          $ra
    // 0x800730B0: nop

    return;
    // 0x800730B0: nop

    // 0x800730B4: jr          $ra
    // 0x800730B8: nop

    return;
    // 0x800730B8: nop

;}
RECOMP_FUNC void func_80087C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80087C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087C34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80087C38: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80087C3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80087C40: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x80087C44: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80087C48: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x80087C4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80087C50: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80087C54: nop

    // 0x80087C58: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80087C5C: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80087C60: nop

    // 0x80087C64: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80087C68: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80087C6C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80087C70: nop

    // 0x80087C74: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80087C78: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087C7C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087C80: nop

    // 0x80087C84: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80087C88: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80087C8C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80087C90: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x80087C94: nop

    // 0x80087C98: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80087C9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80087CA0: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x80087CA4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80087CA8: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80087CAC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80087CB0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80087CB4: nop

    // 0x80087CB8: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80087CBC: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80087CC0: nop

    // 0x80087CC4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80087CC8: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80087CCC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80087CD0: nop

    // 0x80087CD4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80087CD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087CDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087CE0: nop

    // 0x80087CE4: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80087CE8: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80087CEC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80087CF0: sh          $t3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r11;
    // 0x80087CF4: nop

    // 0x80087CF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80087CFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087D00: addiu       $a0, $a0, -0x6110
    ctx->r4 = ADD32(ctx->r4, -0X6110);
    // 0x80087D04: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80087D08: jal         0x8008BE0C
    // 0x80087D0C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_8008BE0C(rdram, ctx);
        goto after_0;
    // 0x80087D0C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x80087D10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80087D14: jal         0x80089170
    // 0x80087D18: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80087D18: nop

    after_1:
    // 0x80087D1C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80087D20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80087D24: jal         0x800898D8
    // 0x80087D28: addiu       $a2, $zero, 0x4007
    ctx->r6 = ADD32(0, 0X4007);
    func_800898D8(rdram, ctx);
        goto after_2;
    // 0x80087D28: addiu       $a2, $zero, 0x4007
    ctx->r6 = ADD32(0, 0X4007);
    after_2:
    // 0x80087D2C: beq         $v0, $zero, L_80087D7C
    if (ctx->r2 == 0) {
        // 0x80087D30: nop
    
            goto L_80087D7C;
    }
    // 0x80087D30: nop

    // 0x80087D34: lh          $t4, 0x1A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1A);
    // 0x80087D38: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x80087D3C: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x80087D40: lh          $t8, 0x20($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X20);
    // 0x80087D44: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80087D48: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x80087D4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80087D50: bgez        $a1, L_80087D60
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80087D54: sra         $t6, $a1, 1
        ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80087D60;
    }
    // 0x80087D54: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80087D58: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80087D5C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80087D60:
    // 0x80087D60: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80087D64: bgez        $a2, L_80087D74
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80087D68: sra         $t9, $a2, 1
        ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80087D74;
    }
    // 0x80087D68: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80087D6C: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80087D70: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80087D74:
    // 0x80087D74: jal         0x80089B04
    // 0x80087D78: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_80089B04(rdram, ctx);
        goto after_3;
    // 0x80087D78: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_3:
L_80087D7C:
    // 0x80087D7C: b           L_80087D8C
    // 0x80087D80: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087D8C;
    // 0x80087D80: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80087D84: b           L_80087D8C
    // 0x80087D88: nop

        goto L_80087D8C;
    // 0x80087D88: nop

L_80087D8C:
    // 0x80087D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80087D94: jr          $ra
    // 0x80087D98: nop

    return;
    // 0x80087D98: nop

;}
RECOMP_FUNC void func_8001A690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A690: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001A694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A698: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001A69C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001A6A0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001A6A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6A8: nop

    // 0x8001A6AC: sw          $zero, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = 0;
    // 0x8001A6B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6B4: nop

    // 0x8001A6B8: sw          $zero, 0x1AC($t7)
    MEM_W(0X1AC, ctx->r15) = 0;
    // 0x8001A6BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A6C0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6C4: nop

    // 0x8001A6C8: swc1        $f4, 0x1EC($t8)
    MEM_W(0X1EC, ctx->r24) = ctx->f4.u32l;
    // 0x8001A6CC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6D0: nop

    // 0x8001A6D4: lwc1        $f6, 0x1EC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1EC);
    // 0x8001A6D8: nop

    // 0x8001A6DC: swc1        $f6, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f6.u32l;
    // 0x8001A6E0: jal         0x800BC6EC
    // 0x8001A6E4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8001A6E4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x8001A6E8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6EC: nop

    // 0x8001A6F0: sw          $v0, 0x20C($t0)
    MEM_W(0X20C, ctx->r8) = ctx->r2;
    // 0x8001A6F4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6F8: nop

    // 0x8001A6FC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8001A700: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001A704: jal         0x80099E2C
    // 0x8001A708: nop

    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x8001A708: nop

    after_1:
    // 0x8001A70C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001A710: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A714: nop

    // 0x8001A718: swc1        $f8, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->f8.u32l;
    // 0x8001A71C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A720: nop

    // 0x8001A724: lwc1        $f20, 0xD4($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0XD4);
    // 0x8001A728: nop

    // 0x8001A72C: swc1        $f20, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f20.u32l;
    // 0x8001A730: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A734: nop

    // 0x8001A738: swc1        $f20, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f20.u32l;
    // 0x8001A73C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001A740: nop

    // 0x8001A744: sw          $zero, 0x108($t5)
    MEM_W(0X108, ctx->r13) = 0;
    // 0x8001A748: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A74C: nop

    // 0x8001A750: lw          $t7, 0x108($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X108);
    // 0x8001A754: nop

    // 0x8001A758: sw          $t7, 0x104($t6)
    MEM_W(0X104, ctx->r14) = ctx->r15;
    // 0x8001A75C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001A760: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A764: nop

    // 0x8001A768: swc1        $f10, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f10.u32l;
    // 0x8001A76C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001A770: nop

    // 0x8001A774: lwc1        $f20, 0xF0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8001A778: nop

    // 0x8001A77C: swc1        $f20, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f20.u32l;
    // 0x8001A780: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A784: nop

    // 0x8001A788: swc1        $f20, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f20.u32l;
    // 0x8001A78C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A790: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001A794: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A798: nop

    // 0x8001A79C: swc1        $f16, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f16.u32l;
    // 0x8001A7A0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7A4: nop

    // 0x8001A7A8: lwc1        $f18, 0xF8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XF8);
    // 0x8001A7AC: nop

    // 0x8001A7B0: swc1        $f18, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f18.u32l;
    // 0x8001A7B4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7B8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8001A7BC: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x8001A7C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001A7C8: sh          $t5, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r13;
    // 0x8001A7CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7D0: lui         $t6, 0x7FFF
    ctx->r14 = S32(0X7FFF << 16);
    // 0x8001A7D4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8001A7D8: sw          $t6, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r14;
    // 0x8001A7DC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7E0: addiu       $t9, $zero, 0x84C
    ctx->r25 = ADD32(0, 0X84C);
    // 0x8001A7E4: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x8001A7E8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7EC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8001A7F0: sh          $t1, 0x114($t2)
    MEM_H(0X114, ctx->r10) = ctx->r9;
    // 0x8001A7F4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001A7F8: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001A7FC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001A800: nop

    // 0x8001A804: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x8001A808: beq         $t5, $zero, L_8001A8E4
    if (ctx->r13 == 0) {
        // 0x8001A80C: nop
    
            goto L_8001A8E4;
    }
    // 0x8001A80C: nop

    // 0x8001A810: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8001A814: nop

    // 0x8001A818: lw          $t6, 0x1A8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X1A8);
    // 0x8001A81C: nop

    // 0x8001A820: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x8001A824: sw          $t8, 0x1A8($t7)
    MEM_W(0X1A8, ctx->r15) = ctx->r24;
    // 0x8001A828: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A82C: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x8001A830: sh          $t9, 0x100($t0)
    MEM_H(0X100, ctx->r8) = ctx->r25;
    // 0x8001A834: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A838: addiu       $t1, $zero, 0xE0
    ctx->r9 = ADD32(0, 0XE0);
    // 0x8001A83C: sh          $t1, 0x102($t2)
    MEM_H(0X102, ctx->r10) = ctx->r9;
    // 0x8001A840: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A844: nop

    // 0x8001A848: lh          $t4, 0x100($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X100);
    // 0x8001A84C: lh          $t5, 0x102($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X102);
    // 0x8001A850: nop

    // 0x8001A854: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A858: mflo        $a0
    ctx->r4 = lo;
    // 0x8001A85C: jal         0x800BC6EC
    // 0x8001A860: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8001A860: nop

    after_2:
    // 0x8001A864: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A868: nop

    // 0x8001A86C: sw          $v0, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r2;
    // 0x8001A870: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A874: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8001A878: lh          $t9, 0x102($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X102);
    // 0x8001A87C: lh          $t7, 0x100($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X100);
    // 0x8001A880: nop

    // 0x8001A884: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A888: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A88C: blez        $t0, L_8001A8DC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001A890: nop
    
            goto L_8001A8DC;
    }
    // 0x8001A890: nop

L_8001A894:
    // 0x8001A894: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A898: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A89C: lw          $t2, 0x128($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X128);
    // 0x8001A8A0: nop

    // 0x8001A8A4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A8A8: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x8001A8AC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A8B0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A8B4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001A8B8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8001A8BC: lh          $t9, 0x102($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X102);
    // 0x8001A8C0: lh          $t7, 0x100($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X100);
    // 0x8001A8C4: nop

    // 0x8001A8C8: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A8CC: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A8D0: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001A8D4: bne         $at, $zero, L_8001A894
    if (ctx->r1 != 0) {
        // 0x8001A8D8: nop
    
            goto L_8001A894;
    }
    // 0x8001A8D8: nop

L_8001A8DC:
    // 0x8001A8DC: b           L_8001AA28
    // 0x8001A8E0: nop

        goto L_8001AA28;
    // 0x8001A8E0: nop

L_8001A8E4:
    // 0x8001A8E4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001A8E8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8001A8EC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001A8F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001A8F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001A8F8: lwc1        $f4, 0x1B0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1B0);
    // 0x8001A8FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A900: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001A904: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8001A908: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001A90C: sh          $t3, 0x100($t4)
    MEM_H(0X100, ctx->r12) = ctx->r11;
    // 0x8001A910: nop

    // 0x8001A914: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001A918: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8001A91C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001A920: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001A924: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001A928: lwc1        $f8, 0x1B4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1B4);
    // 0x8001A92C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001A930: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001A934: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8001A938: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001A93C: sh          $t7, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r15;
    // 0x8001A940: nop

    // 0x8001A944: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A948: nop

    // 0x8001A94C: lh          $t0, 0x100($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X100);
    // 0x8001A950: lh          $t1, 0x102($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X102);
    // 0x8001A954: nop

    // 0x8001A958: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A95C: mflo        $a0
    ctx->r4 = lo;
    // 0x8001A960: jal         0x800BC6EC
    // 0x8001A964: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8001A964: nop

    after_3:
    // 0x8001A968: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A96C: nop

    // 0x8001A970: sw          $v0, 0x12C($t2)
    MEM_W(0X12C, ctx->r10) = ctx->r2;
    // 0x8001A974: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A978: nop

    // 0x8001A97C: lh          $t4, 0x100($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X100);
    // 0x8001A980: lh          $t5, 0x102($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X102);
    // 0x8001A984: nop

    // 0x8001A988: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A98C: mflo        $a0
    ctx->r4 = lo;
    // 0x8001A990: jal         0x800BC6EC
    // 0x8001A994: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8001A994: nop

    after_4:
    // 0x8001A998: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A99C: nop

    // 0x8001A9A0: sw          $v0, 0x130($t8)
    MEM_W(0X130, ctx->r24) = ctx->r2;
    // 0x8001A9A4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001A9A8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8001A9AC: lh          $t6, 0x102($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X102);
    // 0x8001A9B0: lh          $t9, 0x100($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X100);
    // 0x8001A9B4: nop

    // 0x8001A9B8: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A9BC: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A9C0: blez        $t0, L_8001AA28
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001A9C4: nop
    
            goto L_8001AA28;
    }
    // 0x8001A9C4: nop

L_8001A9C8:
    // 0x8001A9C8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A9CC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A9D0: lw          $t2, 0x12C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C);
    // 0x8001A9D4: nop

    // 0x8001A9D8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A9DC: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x8001A9E0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001A9E4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A9E8: lw          $t8, 0x130($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X130);
    // 0x8001A9EC: nop

    // 0x8001A9F0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8001A9F4: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8001A9F8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A9FC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA00: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8001AA04: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8001AA08: lh          $t3, 0x102($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X102);
    // 0x8001AA0C: lh          $t2, 0x100($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X100);
    // 0x8001AA10: nop

    // 0x8001AA14: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AA18: mflo        $t4
    ctx->r12 = lo;
    // 0x8001AA1C: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001AA20: bne         $at, $zero, L_8001A9C8
    if (ctx->r1 != 0) {
        // 0x8001AA24: nop
    
            goto L_8001A9C8;
    }
    // 0x8001AA24: nop

L_8001AA28:
    // 0x8001AA28: jal         0x800BC6EC
    // 0x8001AA2C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8001AA2C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_5:
    // 0x8001AA30: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA34: nop

    // 0x8001AA38: sw          $v0, 0x138($t5)
    MEM_W(0X138, ctx->r13) = ctx->r2;
    // 0x8001AA3C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA40: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8001AA44: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x8001AA48: jal         0x80090A38
    // 0x8001AA4C: nop

    func_80090A38(rdram, ctx);
        goto after_6;
    // 0x8001AA4C: nop

    after_6:
    // 0x8001AA50: jal         0x80096474
    // 0x8001AA54: nop

    func_80096474(rdram, ctx);
        goto after_7;
    // 0x8001AA54: nop

    after_7:
    // 0x8001AA58: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA5C: nop

    // 0x8001AA60: lw          $a0, 0x128($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X128);
    // 0x8001AA64: jal         0x8008ECCC
    // 0x8001AA68: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_8;
    // 0x8001AA68: nop

    after_8:
    // 0x8001AA6C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA70: nop

    // 0x8001AA74: lh          $t6, 0x100($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X100);
    // 0x8001AA78: lh          $t1, 0x102($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X102);
    // 0x8001AA7C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001AA80: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8001AA84: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001AA88: jal         0x8008EC8C
    // 0x8001AA8C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_8008EC8C(rdram, ctx);
        goto after_9;
    // 0x8001AA8C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_9:
    // 0x8001AA90: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA94: nop

    // 0x8001AA98: lh          $t3, 0x100($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X100);
    // 0x8001AA9C: lh          $t0, 0x102($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X102);
    // 0x8001AAA0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8001AAA4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8001AAA8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001AAAC: jal         0x8008ECAC
    // 0x8001AAB0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_8008ECAC(rdram, ctx);
        goto after_10;
    // 0x8001AAB0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_10:
    // 0x8001AAB4: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8001AAB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001AABC: sw          $t4, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r12;
    // 0x8001AAC0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8001AAC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001AAC8: sw          $t5, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r13;
    // 0x8001AACC: jal         0x80090754
    // 0x8001AAD0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    func_80090754(rdram, ctx);
        goto after_11;
    // 0x8001AAD0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    after_11:
    // 0x8001AAD4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8001AAD8: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8001AADC: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x8001AAE0: nop

    // 0x8001AAE4: andi        $t6, $t7, 0x800
    ctx->r14 = ctx->r15 & 0X800;
    // 0x8001AAE8: beq         $t6, $zero, L_8001AB00
    if (ctx->r14 == 0) {
        // 0x8001AAEC: nop
    
            goto L_8001AB00;
    }
    // 0x8001AAEC: nop

    // 0x8001AAF0: jal         0x80090728
    // 0x8001AAF4: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    func_80090728(rdram, ctx);
        goto after_12;
    // 0x8001AAF4: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    after_12:
    // 0x8001AAF8: b           L_8001AB08
    // 0x8001AAFC: nop

        goto L_8001AB08;
    // 0x8001AAFC: nop

L_8001AB00:
    // 0x8001AB00: jal         0x80090728
    // 0x8001AB04: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80090728(rdram, ctx);
        goto after_13;
    // 0x8001AB04: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_13:
L_8001AB08:
    // 0x8001AB08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AB0C: jal         0x8008EAA8
    // 0x8001AB10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_14;
    // 0x8001AB10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8001AB14: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8001AB18: nop

    // 0x8001AB1C: lw          $a0, 0x20C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20C);
    // 0x8001AB20: jal         0x80096374
    // 0x8001AB24: nop

    func_80096374(rdram, ctx);
        goto after_15;
    // 0x8001AB24: nop

    after_15:
    // 0x8001AB28: jal         0x800967D8
    // 0x8001AB2C: nop

    func_800967D8(rdram, ctx);
        goto after_16;
    // 0x8001AB2C: nop

    after_16:
    // 0x8001AB30: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001AB34: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001AB38: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8001AB3C: nop

    // 0x8001AB40: andi        $t2, $t3, 0x800
    ctx->r10 = ctx->r11 & 0X800;
    // 0x8001AB44: beq         $t2, $zero, L_8001AB60
    if (ctx->r10 == 0) {
        // 0x8001AB48: nop
    
            goto L_8001AB60;
    }
    // 0x8001AB48: nop

    // 0x8001AB4C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8001AB50: lw          $t4, -0x4538($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4538);
    // 0x8001AB54: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001AB58: nop

    // 0x8001AB5C: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_8001AB60:
    // 0x8001AB60: b           L_8001AB70
    // 0x8001AB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AB70;
    // 0x8001AB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AB68: b           L_8001AB70
    // 0x8001AB6C: nop

        goto L_8001AB70;
    // 0x8001AB6C: nop

L_8001AB70:
    // 0x8001AB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AB74: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001AB78: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001AB7C: jr          $ra
    // 0x8001AB80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001AB80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void SysMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x80000454: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80000458: sw          $a0, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r4;
    // 0x8000045C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80000460: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80000464: lw          $t6, 0x1E0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1E0);
    // 0x80000468: nop

    // 0x8000046C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80000470: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80000474: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80000478: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8000047C: addiu       $t9, $t9, 0x3DF8
    ctx->r25 = ADD32(ctx->r25, 0X3DF8);
    // 0x80000480: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80000484: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80000488: nop

    // 0x8000048C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80000490: nop

    // 0x80000494: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80000498: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000049C: jal         0x800983B0
    // 0x800004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    InitScheduler(rdram, ctx);
        goto after_0;
    // 0x800004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800004A4: jal         0x800AD800
    // 0x800004A8: nop

    ContThread_InitControllers(rdram, ctx);
        goto after_1;
    // 0x800004A8: nop

    after_1:
    // 0x800004AC: jal         0x800984B4
    // 0x800004B0: nop

    CreateSchedulerThread(rdram, ctx);
        goto after_2;
    // 0x800004B0: nop

    after_2:
    // 0x800004B4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800004B8: nop

    // 0x800004BC: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800004C0: jal         0x800985BC
    // 0x800004C4: nop

    func_800985BC(rdram, ctx);
        goto after_3;
    // 0x800004C4: nop

    after_3:
    // 0x800004C8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800004CC: nop

    // 0x800004D0: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x800004D4: nop

    // 0x800004D8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800004DC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800004E0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800004E4: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x800004E8: sh          $t5, 0xBD($at)
    MEM_H(0XBD, ctx->r1) = ctx->r13;
    // 0x800004EC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800004F0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800004F4: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x800004F8: sh          $t7, 0xDD($at)
    MEM_H(0XDD, ctx->r1) = ctx->r15;
    // 0x800004FC: lui         $t9, 0x8020
    ctx->r25 = S32(0X8020 << 16);
    // 0x80000500: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x80000504: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x80000508: addiu       $t0, $t0, 0x0
    ctx->r8 = ADD32(ctx->r8, 0X0);
    // 0x8000050C: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x80000510: lhu         $s1, 0x6($t0)
    ctx->r17 = MEM_HU(ctx->r8, 0X6);
    // 0x80000514: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x80000518: addiu       $t1, $t1, 0x0
    ctx->r9 = ADD32(ctx->r9, 0X0);
    // 0x8000051C: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x80000520: sh          $s1, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r17;
    // 0x80000524: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80000528: sh          $s0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r16;
    // 0x8000052C: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x80000530: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
    // 0x80000534: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x80000538: addiu       $t3, $t3, 0x0
    ctx->r11 = ADD32(ctx->r11, 0X0);
    // 0x8000053C: addiu       $a0, $t3, 0x8
    ctx->r4 = ADD32(ctx->r11, 0X8);
    // 0x80000540: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80000544: jal         0x800BD110
    // 0x80000548: addiu       $a2, $zero, 0x4AFF
    ctx->r6 = ADD32(0, 0X4AFF);
    SysMem_Copy64(rdram, ctx);
        goto after_4;
    // 0x80000548: addiu       $a2, $zero, 0x4AFF
    ctx->r6 = ADD32(0, 0X4AFF);
    after_4:
    // 0x8000054C: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x80000550: jal         0x800C4080
    // 0x80000554: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x80000554: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    after_5:
    // 0x80000558: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8000055C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x80000560: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80000564: addiu       $a0, $a0, -0x5800
    ctx->r4 = ADD32(ctx->r4, -0X5800);
    // 0x80000568: jal         0x800BD110
    // 0x8000056C: addiu       $a2, $zero, 0x4B00
    ctx->r6 = ADD32(0, 0X4B00);
    SysMem_Copy64(rdram, ctx);
        goto after_6;
    // 0x8000056C: addiu       $a2, $zero, 0x4B00
    ctx->r6 = ADD32(0, 0X4B00);
    after_6:
    // 0x80000570: jal         0x8008E5A0
    // 0x80000574: nop

    func_8008E5A0(rdram, ctx);
        goto after_7;
    // 0x80000574: nop

    after_7:
    // 0x80000578: jal         0x800B8A2C
    // 0x8000057C: nop

    AudioMgr_InitThread(rdram, ctx);
        goto after_8;
    // 0x8000057C: nop

    after_8:
    // 0x80000580: lui         $t4, 0xF
    ctx->r12 = S32(0XF << 16);
    // 0x80000584: addiu       $t4, $t4, 0x27E0
    ctx->r12 = ADD32(ctx->r12, 0X27E0);
    // 0x80000588: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000058C: sw          $t4, 0x3DF0($at)
    MEM_W(0X3DF0, ctx->r1) = ctx->r12;
    // 0x80000590: lui         $t5, 0x8040
    ctx->r13 = S32(0X8040 << 16);
    // 0x80000594: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x80000598: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000059C: sw          $t5, 0x3E28($at)
    MEM_W(0X3E28, ctx->r1) = ctx->r13;
    // 0x800005A0: lui         $t6, 0x49
    ctx->r14 = S32(0X49 << 16);
    // 0x800005A4: addiu       $t6, $t6, 0x2860
    ctx->r14 = ADD32(ctx->r14, 0X2860);
    // 0x800005A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005AC: sw          $t6, 0x3E2C($at)
    MEM_W(0X3E2C, ctx->r1) = ctx->r14;
    // 0x800005B0: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x800005B4: addiu       $t7, $t7, 0x80
    ctx->r15 = ADD32(ctx->r15, 0X80);
    // 0x800005B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005BC: sw          $t7, 0x40D8($at)
    MEM_W(0X40D8, ctx->r1) = ctx->r15;
    // 0x800005C0: lui         $t8, 0x6A
    ctx->r24 = S32(0X6A << 16);
    // 0x800005C4: addiu       $t8, $t8, -0x5690
    ctx->r24 = ADD32(ctx->r24, -0X5690);
    // 0x800005C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005CC: sw          $t8, 0x60E0($at)
    MEM_W(0X60E0, ctx->r1) = ctx->r24;
    // 0x800005D0: lui         $t9, 0x809B
    ctx->r25 = S32(0X809B << 16);
    // 0x800005D4: addiu       $t9, $t9, -0x7E70
    ctx->r25 = ADD32(ctx->r25, -0X7E70);
    // 0x800005D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005DC: sw          $t9, 0x60E8($at)
    MEM_W(0X60E8, ctx->r1) = ctx->r25;
    // 0x800005E0: lui         $t0, 0x8094
    ctx->r8 = S32(0X8094 << 16);
    // 0x800005E4: addiu       $t0, $t0, 0x7340
    ctx->r8 = ADD32(ctx->r8, 0X7340);
    // 0x800005E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800005EC: sw          $t0, 0x49C0($at)
    MEM_W(0X49C0, ctx->r1) = ctx->r8;
    // 0x800005F0: lui         $t1, 0x64
    ctx->r9 = S32(0X64 << 16);
    // 0x800005F4: addiu       $t1, $t1, -0x64E0
    ctx->r9 = ADD32(ctx->r9, -0X64E0);
    // 0x800005F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800005FC: sw          $t1, 0x29B8($at)
    MEM_W(0X29B8, ctx->r1) = ctx->r9;
    // 0x80000600: lui         $t2, 0x6E
    ctx->r10 = S32(0X6E << 16);
    // 0x80000604: addiu       $t2, $t2, 0x3A40
    ctx->r10 = ADD32(ctx->r10, 0X3A40);
    // 0x80000608: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000060C: sw          $t2, -0x488($at)
    MEM_W(-0X488, ctx->r1) = ctx->r10;
    // 0x80000610: lui         $t3, 0x809F
    ctx->r11 = S32(0X809F << 16);
    // 0x80000614: addiu       $t3, $t3, 0x1260
    ctx->r11 = ADD32(ctx->r11, 0X1260);
    // 0x80000618: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000061C: sw          $t3, -0x480($at)
    MEM_W(-0X480, ctx->r1) = ctx->r11;
    // 0x80000620: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80000624: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80000628: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x8000062C: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x80000630: lui         $a2, 0x807A
    ctx->r6 = S32(0X807A << 16);
    // 0x80000634: jal         0x800BD1FC
    // 0x80000638: addiu       $a2, $a2, 0x1A20
    ctx->r6 = ADD32(ctx->r6, 0X1A20);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_9;
    // 0x80000638: addiu       $a2, $a2, 0x1A20
    ctx->r6 = ADD32(ctx->r6, 0X1A20);
    after_9:
    // 0x8000063C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80000640: sw          $v0, 0x193C($at)
    MEM_W(0X193C, ctx->r1) = ctx->r2;
    // 0x80000644: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80000648: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000064C: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x80000650: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x80000654: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x80000658: jal         0x800BD1FC
    // 0x8000065C: addiu       $a2, $a2, -0x7DD0
    ctx->r6 = ADD32(ctx->r6, -0X7DD0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_10;
    // 0x8000065C: addiu       $a2, $a2, -0x7DD0
    ctx->r6 = ADD32(ctx->r6, -0X7DD0);
    after_10:
    // 0x80000660: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000664: sw          $v0, 0x3DB0($at)
    MEM_W(0X3DB0, ctx->r1) = ctx->r2;
    // 0x80000668: lui         $t4, 0x8044
    ctx->r12 = S32(0X8044 << 16);
    // 0x8000066C: lui         $t5, 0x8045
    ctx->r13 = S32(0X8045 << 16);
    // 0x80000670: lui         $t6, 0x8079
    ctx->r14 = S32(0X8079 << 16);
    // 0x80000674: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x80000678: lui         $t8, 0x807A
    ctx->r24 = S32(0X807A << 16);
    // 0x8000067C: addiu       $t8, $t8, -0x58D0
    ctx->r24 = ADD32(ctx->r24, -0X58D0);
    // 0x80000680: addiu       $t7, $t7, -0x6E40
    ctx->r15 = ADD32(ctx->r15, -0X6E40);
    // 0x80000684: addiu       $t6, $t6, -0x2E40
    ctx->r14 = ADD32(ctx->r14, -0X2E40);
    // 0x80000688: addiu       $t5, $t5, -0x5500
    ctx->r13 = ADD32(ctx->r13, -0X5500);
    // 0x8000068C: addiu       $t4, $t4, 0x12E0
    ctx->r12 = ADD32(ctx->r12, 0X12E0);
    // 0x80000690: lui         $a0, 0x8040
    ctx->r4 = S32(0X8040 << 16);
    // 0x80000694: lui         $a1, 0x8041
    ctx->r5 = S32(0X8041 << 16);
    // 0x80000698: lui         $a2, 0x8041
    ctx->r6 = S32(0X8041 << 16);
    // 0x8000069C: lui         $a3, 0x8041
    ctx->r7 = S32(0X8041 << 16);
    // 0x800006A0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800006A4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800006A8: addiu       $a3, $a3, 0x2A40
    ctx->r7 = ADD32(ctx->r7, 0X2A40);
    // 0x800006AC: addiu       $a2, $a2, -0x5660
    ctx->r6 = ADD32(ctx->r6, -0X5660);
    // 0x800006B0: addiu       $a1, $a1, -0x64C0
    ctx->r5 = ADD32(ctx->r5, -0X64C0);
    // 0x800006B4: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    // 0x800006B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800006BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800006C0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800006C4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800006C8: jal         0x800B1A50
    // 0x800006CC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_800B1A50(rdram, ctx);
        goto after_11;
    // 0x800006CC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_11:
    // 0x800006D0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800006D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800006D8: sw          $t0, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r8;
    // 0x800006DC: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x800006E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800006E4: sw          $t1, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r9;
    // 0x800006E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800006EC: lwc1        $f4, -0x2ED0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2ED0);
    // 0x800006F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800006F4: swc1        $f4, 0x25D8($at)
    MEM_W(0X25D8, ctx->r1) = ctx->f4.u32l;
    // 0x800006F8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800006FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000704: swc1        $f6, 0x25D0($at)
    MEM_W(0X25D0, ctx->r1) = ctx->f6.u32l;
    // 0x80000708: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000070C: lwc1        $f8, 0x25D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80000710: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000714: swc1        $f8, 0x25A0($at)
    MEM_W(0X25A0, ctx->r1) = ctx->f8.u32l;
    // 0x80000718: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8000071C: lw          $t2, -0x4CCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CCC);
    // 0x80000720: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000724: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80000728: nop

    // 0x8000072C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80000730: swc1        $f16, 0x25A8($at)
    MEM_W(0X25A8, ctx->r1) = ctx->f16.u32l;
    // 0x80000734: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80000738: lw          $t3, -0x4CC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CC4);
    // 0x8000073C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000740: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80000744: nop

    // 0x80000748: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000074C: swc1        $f4, 0x25B0($at)
    MEM_W(0X25B0, ctx->r1) = ctx->f4.u32l;
    // 0x80000750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000758: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000075C: swc1        $f6, 0x25B8($at)
    MEM_W(0X25B8, ctx->r1) = ctx->f6.u32l;
    // 0x80000760: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80000764: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80000768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000076C: swc1        $f8, 0x25C0($at)
    MEM_W(0X25C0, ctx->r1) = ctx->f8.u32l;
    // 0x80000770: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80000774: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80000778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000077C: swc1        $f10, 0x25C8($at)
    MEM_W(0X25C8, ctx->r1) = ctx->f10.u32l;
    // 0x80000780: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80000784: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80000788: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8000078C: jal         0x800BDC70
    // 0x80000790: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BDC70(rdram, ctx);
        goto after_12;
    // 0x80000790: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80000794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000798: sw          $zero, 0x70E4($at)
    MEM_W(0X70E4, ctx->r1) = 0;
    // 0x8000079C: sw          $zero, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = 0;
L_800007A0:
    // 0x800007A0: lw          $a0, 0x1DC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1DC);
    // 0x800007A4: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800007A8: jal         0x800BECCC
    // 0x800007AC: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    Main_SetContRawStickScale(rdram, ctx);
        goto after_13;
    // 0x800007AC: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_13:
    // 0x800007B0: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800007B4: nop

    // 0x800007B8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800007BC: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x800007C0: bne         $at, $zero, L_800007A0
    if (ctx->r1 != 0) {
        // 0x800007C4: sw          $t5, 0x1DC($sp)
        MEM_W(0X1DC, ctx->r29) = ctx->r13;
            goto L_800007A0;
    }
    // 0x800007C4: sw          $t5, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r13;
    // 0x800007C8: jal         0x80083EAC
    // 0x800007CC: nop

    func_80083EAC(rdram, ctx);
        goto after_14;
    // 0x800007CC: nop

    after_14:
    // 0x800007D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800007D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800007D8: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
    // 0x800007DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800007E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800007E4: sh          $t7, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r15;
    // 0x800007E8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800007EC: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800007F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800007F4: sh          $t8, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r24;
    // 0x800007F8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800007FC: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x80000800: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000804: sh          $t9, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r25;
    // 0x80000808: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000080C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000810: sh          $t0, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r8;
    // 0x80000814: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80000818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000081C: sh          $t1, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r9;
    // 0x80000820: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x80000824: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000828: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
    // 0x8000082C: addiu       $t3, $zero, -0x2
    ctx->r11 = ADD32(0, -0X2);
    // 0x80000830: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000834: sh          $t3, -0x73A8($at)
    MEM_H(-0X73A8, ctx->r1) = ctx->r11;
    // 0x80000838: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000083C: sh          $zero, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = 0;
    // 0x80000840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000844: sh          $zero, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = 0;
    // 0x80000848: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000084C: sh          $zero, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = 0;
    // 0x80000850: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000854: sb          $zero, 0x7141($at)
    MEM_B(0X7141, ctx->r1) = 0;
    // 0x80000858: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000085C: sw          $zero, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = 0;
    // 0x80000860: sw          $zero, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = 0;
L_80000864:
    // 0x80000864: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x80000868: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000086C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80000870: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80000874: sh          $zero, -0x7278($at)
    MEM_H(-0X7278, ctx->r1) = 0;
    // 0x80000878: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x8000087C: nop

    // 0x80000880: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80000884: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80000888: bne         $at, $zero, L_80000864
    if (ctx->r1 != 0) {
        // 0x8000088C: sw          $t7, 0x1DC($sp)
        MEM_W(0X1DC, ctx->r29) = ctx->r15;
            goto L_80000864;
    }
    // 0x8000088C: sw          $t7, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r15;
    // 0x80000890: jal         0x800044BC
    // 0x80000894: nop

    func_800044BC(rdram, ctx);
        goto after_15;
    // 0x80000894: nop

    after_15:
    // 0x80000898: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000089C: sw          $zero, 0x3080($at)
    MEM_W(0X3080, ctx->r1) = 0;
    // 0x800008A0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800008A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800008A8: sw          $t8, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r24;
    // 0x800008AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800008B0: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x800008B4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800008B8: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800008BC: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800008C0: nop

    // 0x800008C4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800008C8: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x800008CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800008D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800008D4: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x800008D8: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x800008DC: lui         $a2, 0x809A
    ctx->r6 = S32(0X809A << 16);
    // 0x800008E0: jal         0x800BD1FC
    // 0x800008E4: addiu       $a2, $a2, -0x6560
    ctx->r6 = ADD32(ctx->r6, -0X6560);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_16;
    // 0x800008E4: addiu       $a2, $a2, -0x6560
    ctx->r6 = ADD32(ctx->r6, -0X6560);
    after_16:
    // 0x800008E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800008EC: sw          $v0, -0x780($at)
    MEM_W(-0X780, ctx->r1) = ctx->r2;
    // 0x800008F0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800008F4: lw          $a0, -0x780($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X780);
    // 0x800008F8: jal         0x800BED70
    // 0x800008FC: nop

    Spi_GetHeader(rdram, ctx);
        goto after_17;
    // 0x800008FC: nop

    after_17:
    // 0x80000900: sw          $v0, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r2;
    // 0x80000904: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80000908: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8000090C: jal         0x800BC918
    // 0x80000910: nop

    SysMem_HeapAllocMark(rdram, ctx);
        goto after_18;
    // 0x80000910: nop

    after_18:
    // 0x80000914: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000918: sw          $v0, -0x78C($at)
    MEM_W(-0X78C, ctx->r1) = ctx->r2;
    // 0x8000091C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80000920: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80000924: lw          $a2, -0x78C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X78C);
    // 0x80000928: lw          $a0, -0x780($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X780);
    // 0x8000092C: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x80000930: jal         0x800BF0B4
    // 0x80000934: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_19;
    // 0x80000934: nop

    after_19:
    // 0x80000938: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8000093C: lw          $t2, -0x78C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X78C);
    // 0x80000940: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000944: sw          $t2, -0x780($at)
    MEM_W(-0X780, ctx->r1) = ctx->r10;
    // 0x80000948: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000094C: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80000950: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80000954: nop

    // 0x80000958: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8000095C: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
    // 0x80000960: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000964: sw          $zero, 0x3DF4($at)
    MEM_W(0X3DF4, ctx->r1) = 0;
    // 0x80000968: jal         0x800BD620
    // 0x8000096C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BD620(rdram, ctx);
        goto after_20;
    // 0x8000096C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80000970: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000974: sw          $zero, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = 0;
    // 0x80000978: jal         0x8005D150
    // 0x8000097C: nop

    func_8005D150(rdram, ctx);
        goto after_21;
    // 0x8000097C: nop

    after_21:
    // 0x80000980: jal         0x8005F01C
    // 0x80000984: nop

    func_8005F01C(rdram, ctx);
        goto after_22;
    // 0x80000984: nop

    after_22:
    // 0x80000988: jal         0x8002856C
    // 0x8000098C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002856C(rdram, ctx);
        goto after_23;
    // 0x8000098C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80000990: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80000994: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80000998: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000099C: nop

    // 0x800009A0: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x800009A4: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x800009A8: addiu       $t0, $zero, 0x1388
    ctx->r8 = ADD32(0, 0X1388);
    // 0x800009AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009B0: sw          $t0, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r8;
    // 0x800009B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009B8: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x800009BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800009C0: sw          $zero, -0x794($at)
    MEM_W(-0X794, ctx->r1) = 0;
    // 0x800009C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009C8: sh          $zero, 0x72E4($at)
    MEM_H(0X72E4, ctx->r1) = 0;
    // 0x800009CC: addiu       $t1, $zero, 0x1A
    ctx->r9 = ADD32(0, 0X1A);
    // 0x800009D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800009D4: sh          $t1, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r9;
    // 0x800009D8: addiu       $t9, $zero, -0x21
    ctx->r25 = ADD32(0, -0X21);
    // 0x800009DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800009E0: sh          $t9, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r25;
    // 0x800009E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009E8: sh          $zero, 0x72D4($at)
    MEM_H(0X72D4, ctx->r1) = 0;
    // 0x800009EC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800009F0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800009F4: addiu       $t4, $t4, -0x38B8
    ctx->r12 = ADD32(ctx->r12, -0X38B8);
    // 0x800009F8: addiu       $t2, $t2, -0x611C
    ctx->r10 = ADD32(ctx->r10, -0X611C);
    // 0x800009FC: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80000A00: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80000A04: addiu       $t3, $t3, -0x38B8
    ctx->r11 = ADD32(ctx->r11, -0X38B8);
    // 0x80000A08: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80000A0C: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x80000A10: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80000A14: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80000A18: addiu       $t8, $t8, -0x38B8
    ctx->r24 = ADD32(ctx->r24, -0X38B8);
    // 0x80000A1C: addiu       $t7, $t7, -0x6110
    ctx->r15 = ADD32(ctx->r15, -0X6110);
    // 0x80000A20: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80000A24: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80000A28: addiu       $t0, $t0, -0x38B8
    ctx->r8 = ADD32(ctx->r8, -0X38B8);
    // 0x80000A2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000A30: sw          $t6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r14;
    // 0x80000A34: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80000A38: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80000A3C: addiu       $t9, $t9, -0x38B8
    ctx->r25 = ADD32(ctx->r25, -0X38B8);
    // 0x80000A40: addiu       $t1, $t1, -0x794
    ctx->r9 = ADD32(ctx->r9, -0X794);
    // 0x80000A44: sw          $t1, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r9;
    // 0x80000A48: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80000A4C: addiu       $t4, $t4, -0x38B8
    ctx->r12 = ADD32(ctx->r12, -0X38B8);
    // 0x80000A50: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80000A54: sw          $t2, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r10;
    // 0x80000A58: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80000A5C: addiu       $t3, $t3, -0x38B8
    ctx->r11 = ADD32(ctx->r11, -0X38B8);
    // 0x80000A60: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80000A64: sw          $t5, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r13;
    // 0x80000A68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000A6C: sh          $zero, 0x7294($at)
    MEM_H(0X7294, ctx->r1) = 0;
    // 0x80000A70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80000A74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000A78: sh          $t7, 0x72A0($at)
    MEM_H(0X72A0, ctx->r1) = ctx->r15;
    // 0x80000A7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80000A80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000A84: sh          $t8, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r24;
    // 0x80000A88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000A8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000A90: sh          $t6, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r14;
    // 0x80000A94: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80000A98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80000A9C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AA0: swc1        $f16, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f16.u32l;
    // 0x80000AA4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AA8: sw          $zero, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = 0;
    // 0x80000AAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AB0: sw          $zero, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = 0;
    // 0x80000AB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AB8: sw          $zero, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = 0;
    // 0x80000ABC: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x80000AC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AC4: sw          $t0, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r8;
    // 0x80000AC8: addiu       $t1, $zero, 0xA8
    ctx->r9 = ADD32(0, 0XA8);
    // 0x80000ACC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AD0: sw          $t1, -0x44F4($at)
    MEM_W(-0X44F4, ctx->r1) = ctx->r9;
    // 0x80000AD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000AD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000ADC: swc1        $f18, -0x44F0($at)
    MEM_W(-0X44F0, ctx->r1) = ctx->f18.u32l;
    // 0x80000AE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80000AE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80000AE8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AEC: swc1        $f4, -0x44EC($at)
    MEM_W(-0X44EC, ctx->r1) = ctx->f4.u32l;
    // 0x80000AF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80000AF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AF8: swc1        $f6, -0x44E8($at)
    MEM_W(-0X44E8, ctx->r1) = ctx->f6.u32l;
    // 0x80000AFC: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80000B00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000B04: sw          $t9, -0x44E4($at)
    MEM_W(-0X44E4, ctx->r1) = ctx->r25;
    // 0x80000B08: addiu       $t2, $zero, 0x21
    ctx->r10 = ADD32(0, 0X21);
    // 0x80000B0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000B10: sh          $t2, -0x820($at)
    MEM_H(-0X820, ctx->r1) = ctx->r10;
    // 0x80000B14: lui         $a1, 0x4E4A
    ctx->r5 = S32(0X4E4A << 16);
    // 0x80000B18: ori         $a1, $a1, 0x324A
    ctx->r5 = ctx->r5 | 0X324A;
    // 0x80000B1C: jal         0x800AE0C0
    // 0x80000B20: addiu       $a0, $zero, 0x4234
    ctx->r4 = ADD32(0, 0X4234);
    ContPak_SetPfsCodes(rdram, ctx);
        goto after_24;
    // 0x80000B20: addiu       $a0, $zero, 0x4234
    ctx->r4 = ADD32(0, 0X4234);
    after_24:
L_80000B24:
    // 0x80000B24: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80000B28: nop

    // 0x80000B2C: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80000B30: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000B34: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80000B38: jal         0x8000A2C0
    // 0x80000B3C: nop

    func_8000A2C0(rdram, ctx);
        goto after_25;
    // 0x80000B3C: nop

    after_25:
    // 0x80000B40: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80000B44: lw          $t5, -0x5B14($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B14);
    // 0x80000B48: nop

    // 0x80000B4C: beq         $t5, $zero, L_80000BD8
    if (ctx->r13 == 0) {
        // 0x80000B50: nop
    
            goto L_80000BD8;
    }
    // 0x80000B50: nop

    // 0x80000B54: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80000B58: nop

    // 0x80000B5C: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x80000B60: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000B64: jal         0x80002F20
    // 0x80000B68: nop

    func_80002F20(rdram, ctx);
        goto after_26;
    // 0x80000B68: nop

    after_26:
    // 0x80000B6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000B70: sh          $zero, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = 0;
    // 0x80000B74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000B78: sh          $zero, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = 0;
    // 0x80000B7C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80000B80: jal         0x8001AFA0
    // 0x80000B84: nop

    func_8001AFA0(rdram, ctx);
        goto after_27;
    // 0x80000B84: nop

    after_27:
    // 0x80000B88: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80000B8C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80000B90: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x80000B94: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80000B98: nop

    // 0x80000B9C: bne         $t7, $t8, L_80000BD0
    if (ctx->r15 != ctx->r24) {
        // 0x80000BA0: nop
    
            goto L_80000BD0;
    }
    // 0x80000BA0: nop

    // 0x80000BA4: bne         $t7, $zero, L_80000BD0
    if (ctx->r15 != 0) {
        // 0x80000BA8: nop
    
            goto L_80000BD0;
    }
    // 0x80000BA8: nop

    // 0x80000BAC: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x80000BB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000BB4: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
    // 0x80000BB8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80000BBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000BC0: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
    // 0x80000BC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000BC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80000BCC: sh          $t1, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r9;
L_80000BD0:
    // 0x80000BD0: b           L_80000BE4
    // 0x80000BD4: nop

        goto L_80000BE4;
    // 0x80000BD4: nop

L_80000BD8:
    // 0x80000BD8: addiu       $t9, $zero, 0x1F4
    ctx->r25 = ADD32(0, 0X1F4);
    // 0x80000BDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000BE0: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
L_80000BE4:
    // 0x80000BE4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80000BE8: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x80000BEC: nop

    // 0x80000BF0: bne         $t2, $zero, L_80000C04
    if (ctx->r10 != 0) {
        // 0x80000BF4: nop
    
            goto L_80000C04;
    }
    // 0x80000BF4: nop

    // 0x80000BF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80000BFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000C00: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
L_80000C04:
    // 0x80000C04: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80000C08: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80000C0C: nop

    // 0x80000C10: bne         $t5, $zero, L_80000C24
    if (ctx->r13 != 0) {
        // 0x80000C14: nop
    
            goto L_80000C24;
    }
    // 0x80000C14: nop

    // 0x80000C18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80000C1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000C20: sh          $t3, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r11;
L_80000C24:
    // 0x80000C24: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80000C28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000C2C: sw          $t8, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r24;
    // 0x80000C30: jal         0x80098820
    // 0x80000C34: nop

    func_80098820(rdram, ctx);
        goto after_28;
    // 0x80000C34: nop

    after_28:
    // 0x80000C38: jal         0x80098868
    // 0x80000C3C: nop

    func_80098868(rdram, ctx);
        goto after_29;
    // 0x80000C3C: nop

    after_29:
    // 0x80000C40: jal         0x800C0A40
    // 0x80000C44: nop

    func_800C0A40(rdram, ctx);
        goto after_30;
    // 0x80000C44: nop

    after_30:
    // 0x80000C48: jal         0x800BCB54
    // 0x80000C4C: nop

    func_800BCB54(rdram, ctx);
        goto after_31;
    // 0x80000C4C: nop

    after_31:
    // 0x80000C50: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80000C54: nop

    // 0x80000C58: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x80000C5C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000C60: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80000C64: jal         0x80000C90
    // 0x80000C68: nop

    func_80000C90(rdram, ctx);
        goto after_32;
    // 0x80000C68: nop

    after_32:
    // 0x80000C6C: b           L_80000B24
    // 0x80000C70: nop

        goto L_80000B24;
    // 0x80000C70: nop

    // 0x80000C74: b           L_80000C7C
    // 0x80000C78: nop

        goto L_80000C7C;
    // 0x80000C78: nop

L_80000C7C:
    // 0x80000C7C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80000C80: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80000C84: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80000C88: jr          $ra
    // 0x80000C8C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x80000C8C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void func_8006B884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B884: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B888: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B88C: nop

    // 0x8006B890: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006B894: nop

    // 0x8006B898: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8006B89C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B8A0: jr          $ra
    // 0x8006B8A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B8A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B8A8: jr          $ra
    // 0x8006B8AC: nop

    return;
    // 0x8006B8AC: nop

    // 0x8006B8B0: jr          $ra
    // 0x8006B8B4: nop

    return;
    // 0x8006B8B4: nop

;}
RECOMP_FUNC void func_80070BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070BB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80070BB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80070BBC: nop

    // 0x80070BC0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80070BC4: nop

    // 0x80070BC8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80070BCC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80070BD0: jr          $ra
    // 0x80070BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80070BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070BD8: jr          $ra
    // 0x80070BDC: nop

    return;
    // 0x80070BDC: nop

    // 0x80070BE0: jr          $ra
    // 0x80070BE4: nop

    return;
    // 0x80070BE4: nop

;}
RECOMP_FUNC void func_80070A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070A30: jal         0x80061348
    // 0x80070A34: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070A34: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070A38: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070A3C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070A40: b           L_80070A50
    // 0x80070A44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80070A50;
    // 0x80070A44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070A48: b           L_80070A50
    // 0x80070A4C: nop

        goto L_80070A50;
    // 0x80070A4C: nop

L_80070A50:
    // 0x80070A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070A58: jr          $ra
    // 0x80070A5C: nop

    return;
    // 0x80070A5C: nop

;}
RECOMP_FUNC void func_8006F114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F11C: jal         0x80061348
    // 0x8006F120: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F120: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    after_0:
    // 0x8006F124: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F128: b           L_8006F138
    // 0x8006F12C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F138;
    // 0x8006F12C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F130: b           L_8006F138
    // 0x8006F134: nop

        goto L_8006F138;
    // 0x8006F134: nop

L_8006F138:
    // 0x8006F138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F140: jr          $ra
    // 0x8006F144: nop

    return;
    // 0x8006F144: nop

;}
