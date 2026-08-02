#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80088C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80088CA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80088CA4: jal         0x8008B4EC
    // 0x80088CA8: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80088CA8: nop

    after_0:
    // 0x80088CAC: b           L_80088CB4
    // 0x80088CB0: nop

        goto L_80088CB4;
    // 0x80088CB0: nop

L_80088CB4:
    // 0x80088CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088CBC: jr          $ra
    // 0x80088CC0: nop

    return;
    // 0x80088CC0: nop

;}
RECOMP_FUNC void func_80013624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013624: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80013628: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001362C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80013630: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80013634: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80013638: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001363C: jal         0x8000DA44
    // 0x80013640: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80013640: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x80013644: bgez        $v0, L_80013654
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013648: nop
    
            goto L_80013654;
    }
    // 0x80013648: nop

    // 0x8001364C: b           L_800139A8
    // 0x80013650: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800139A8;
    // 0x80013650: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013654:
    // 0x80013654: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80013658: nop

    // 0x8001365C: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80013660: nop

    // 0x80013664: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80013668: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001366C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80013670: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x80013674: nop

    // 0x80013678: beq         $t9, $at, L_80013688
    if (ctx->r25 == ctx->r1) {
        // 0x8001367C: nop
    
            goto L_80013688;
    }
    // 0x8001367C: nop

    // 0x80013680: b           L_800139A8
    // 0x80013684: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800139A8;
    // 0x80013684: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013688:
    // 0x80013688: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8001368C: nop

    // 0x80013690: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x80013694: nop

    // 0x80013698: bne         $t1, $zero, L_80013764
    if (ctx->r9 != 0) {
        // 0x8001369C: nop
    
            goto L_80013764;
    }
    // 0x8001369C: nop

    // 0x800136A0: jal         0x8000D164
    // 0x800136A4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    TempHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x800136A4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_1:
    // 0x800136A8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800136AC: nop

    // 0x800136B0: sw          $v0, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->r2;
    // 0x800136B4: jal         0x8000D164
    // 0x800136B8: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    TempHeap_Alloc(rdram, ctx);
        goto after_2;
    // 0x800136B8: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    after_2:
    // 0x800136BC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800136C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800136C4: lw          $t4, 0x5C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X5C);
    // 0x800136C8: nop

    // 0x800136CC: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
    // 0x800136D0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800136D4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800136D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800136DC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800136E0: nop

    // 0x800136E4: swc1        $f4, 0x1B0($t5)
    MEM_W(0X1B0, ctx->r13) = ctx->f4.u32l;
    // 0x800136E8: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x800136EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800136F0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800136F4: nop

    // 0x800136F8: swc1        $f6, 0x1B4($t6)
    MEM_W(0X1B4, ctx->r14) = ctx->f6.u32l;
    // 0x800136FC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80013700: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80013704: sh          $t7, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r15;
    // 0x80013708: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8001370C: lui         $t9, 0x7FFF
    ctx->r25 = S32(0X7FFF << 16);
    // 0x80013710: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80013714: sw          $t9, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->r25;
    // 0x80013718: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8001371C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80013720: nop

    // 0x80013724: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
    // 0x80013728: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8001372C: nop

    // 0x80013730: lw          $t4, 0x5C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X5C);
    // 0x80013734: nop

    // 0x80013738: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8001373C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80013740: nop

    // 0x80013744: lw          $t6, 0x5C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X5C);
    // 0x80013748: nop

    // 0x8001374C: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x80013750: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80013754: jal         0x8001A690
    // 0x80013758: nop

    func_8001A690(rdram, ctx);
        goto after_3;
    // 0x80013758: nop

    after_3:
    // 0x8001375C: b           L_80013780
    // 0x80013760: nop

        goto L_80013780;
    // 0x80013760: nop

L_80013764:
    // 0x80013764: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80013768: nop

    // 0x8001376C: lw          $t8, 0x5C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X5C);
    // 0x80013770: nop

    // 0x80013774: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80013778: nop

    // 0x8001377C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80013780:
    // 0x80013780: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80013784: nop

    // 0x80013788: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x8001378C: nop

    // 0x80013790: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80013794: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_80013798:
    // 0x80013798: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8001379C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800137A0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800137A4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800137A8: lw          $t6, 0x12C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X12C);
    // 0x800137AC: nop

    // 0x800137B0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800137B4: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_800137B8:
    // 0x800137B8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800137BC: nop

    // 0x800137C0: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x800137C4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800137C8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800137CC: ori         $at, $zero, 0xA800
    ctx->r1 = 0 | 0XA800;
    // 0x800137D0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800137D4: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800137D8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800137DC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800137E0: bne         $at, $zero, L_800137B8
    if (ctx->r1 != 0) {
        // 0x800137E4: sw          $t9, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r25;
            goto L_800137B8;
    }
    // 0x800137E4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x800137E8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800137EC: nop

    // 0x800137F0: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x800137F4: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800137F8: bne         $at, $zero, L_80013798
    if (ctx->r1 != 0) {
        // 0x800137FC: sw          $t2, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r10;
            goto L_80013798;
    }
    // 0x800137FC: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x80013800: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x80013804: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x80013808: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8001380C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80013810: nop

    // 0x80013814: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013818: swc1        $f10, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f10.u32l;
    // 0x8001381C: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x80013820: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80013824: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80013828: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8001382C: nop

    // 0x80013830: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80013834: swc1        $f18, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f18.u32l;
    // 0x80013838: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001383C: lh          $t1, -0x7290($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7290);
    // 0x80013840: nop

    // 0x80013844: slti        $at, $t1, 0x1F4
    ctx->r1 = SIGNED(ctx->r9) < 0X1F4 ? 1 : 0;
    // 0x80013848: beq         $at, $zero, L_80013898
    if (ctx->r1 == 0) {
        // 0x8001384C: nop
    
            goto L_80013898;
    }
    // 0x8001384C: nop

    // 0x80013850: lui         $t9, 0x8098
    ctx->r25 = S32(0X8098 << 16);
    // 0x80013854: addiu       $t9, $t9, -0xB30
    ctx->r25 = ADD32(ctx->r25, -0XB30);
    // 0x80013858: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8001385C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80013860: lw          $t3, 0x3070($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3070);
    // 0x80013864: nop

    // 0x80013868: bne         $t3, $zero, L_80013880
    if (ctx->r11 != 0) {
        // 0x8001386C: nop
    
            goto L_80013880;
    }
    // 0x8001386C: nop

    // 0x80013870: lui         $t2, 0x8098
    ctx->r10 = S32(0X8098 << 16);
    // 0x80013874: addiu       $t2, $t2, 0x1A00
    ctx->r10 = ADD32(ctx->r10, 0X1A00);
    // 0x80013878: b           L_80013890
    // 0x8001387C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
        goto L_80013890;
    // 0x8001387C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
L_80013880:
    // 0x80013880: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80013884: lw          $t4, 0x3070($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3070);
    // 0x80013888: nop

    // 0x8001388C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80013890:
    // 0x80013890: b           L_800138D8
    // 0x80013894: nop

        goto L_800138D8;
    // 0x80013894: nop

L_80013898:
    // 0x80013898: lui         $t5, 0x8099
    ctx->r13 = S32(0X8099 << 16);
    // 0x8001389C: addiu       $t5, $t5, 0x68B0
    ctx->r13 = ADD32(ctx->r13, 0X68B0);
    // 0x800138A0: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800138A4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800138A8: lw          $t6, 0x3078($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3078);
    // 0x800138AC: nop

    // 0x800138B0: bne         $t6, $zero, L_800138C8
    if (ctx->r14 != 0) {
        // 0x800138B4: nop
    
            goto L_800138C8;
    }
    // 0x800138B4: nop

    // 0x800138B8: lui         $t7, 0x80B0
    ctx->r15 = S32(0X80B0 << 16);
    // 0x800138BC: addiu       $t7, $t7, 0x4E40
    ctx->r15 = ADD32(ctx->r15, 0X4E40);
    // 0x800138C0: b           L_800138D8
    // 0x800138C4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_800138D8;
    // 0x800138C4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_800138C8:
    // 0x800138C8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800138CC: lw          $t8, 0x3078($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3078);
    // 0x800138D0: nop

    // 0x800138D4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_800138D8:
    // 0x800138D8: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800138DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800138E0: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x800138E4: lhu         $t9, 0x6($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X6);
    // 0x800138E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800138EC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800138F0: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x800138F4: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x800138F8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800138FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80013900: jal         0x80096B38
    // 0x80013904: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_80096B38(rdram, ctx);
        goto after_4;
    // 0x80013904: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_4:
    // 0x80013908: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8001390C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80013910: nop

    // 0x80013914: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x80013918: nop

    // 0x8001391C: bne         $t2, $zero, L_80013938
    if (ctx->r10 != 0) {
        // 0x80013920: nop
    
            goto L_80013938;
    }
    // 0x80013920: nop

    // 0x80013924: jal         0x8000D164
    // 0x80013928: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    TempHeap_Alloc(rdram, ctx);
        goto after_5;
    // 0x80013928: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_5:
    // 0x8001392C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80013930: nop

    // 0x80013934: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
L_80013938:
    // 0x80013938: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8001393C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80013940: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80013944: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x80013948: jal         0x80096D40
    // 0x8001394C: nop

    func_80096D40(rdram, ctx);
        goto after_6;
    // 0x8001394C: nop

    after_6:
    // 0x80013950: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80013954: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80013958: nop

    // 0x8001395C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80013960: nop

    // 0x80013964: bne         $t7, $zero, L_80013980
    if (ctx->r15 != 0) {
        // 0x80013968: nop
    
            goto L_80013980;
    }
    // 0x80013968: nop

    // 0x8001396C: jal         0x8000D164
    // 0x80013970: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    TempHeap_Alloc(rdram, ctx);
        goto after_7;
    // 0x80013970: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_7:
    // 0x80013974: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80013978: nop

    // 0x8001397C: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
L_80013980:
    // 0x80013980: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80013984: nop

    // 0x80013988: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8001398C: nop

    // 0x80013990: ori         $t9, $t1, 0x200
    ctx->r25 = ctx->r9 | 0X200;
    // 0x80013994: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80013998: b           L_800139A8
    // 0x8001399C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800139A8;
    // 0x8001399C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800139A0: b           L_800139A8
    // 0x800139A4: nop

        goto L_800139A8;
    // 0x800139A4: nop

L_800139A8:
    // 0x800139A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800139AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800139B0: jr          $ra
    // 0x800139B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800139B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8005A5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A5F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005A5F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A5FC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005A600: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005A604: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005A608: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005A60C: jal         0x800B3434
    // 0x8005A610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_0;
    // 0x8005A610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8005A614: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8005A618: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8005A61C: nop

    // 0x8005A620: andi        $t7, $t6, 0xC000
    ctx->r15 = ctx->r14 & 0XC000;
    // 0x8005A624: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005A628: beq         $t8, $zero, L_8005A6A4
    if (ctx->r24 == 0) {
        // 0x8005A62C: sh          $t7, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r15;
            goto L_8005A6A4;
    }
    // 0x8005A62C: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x8005A630: lhu         $t9, 0x2A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2A);
    // 0x8005A634: nop

    // 0x8005A638: andi        $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 & 0X4000;
    // 0x8005A63C: beq         $t0, $zero, L_8005A64C
    if (ctx->r8 == 0) {
        // 0x8005A640: nop
    
            goto L_8005A64C;
    }
    // 0x8005A640: nop

    // 0x8005A644: b           L_8005A650
    // 0x8005A648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8005A650;
    // 0x8005A648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8005A64C:
    // 0x8005A64C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8005A650:
    // 0x8005A650: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005A654: jal         0x800B32E4
    // 0x8005A658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800B32E4(rdram, ctx);
        goto after_1;
    // 0x8005A658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8005A65C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005A660: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005A664: nop

    // 0x8005A668: beq         $t1, $zero, L_8005A698
    if (ctx->r9 == 0) {
        // 0x8005A66C: nop
    
            goto L_8005A698;
    }
    // 0x8005A66C: nop

    // 0x8005A670: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A674: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8005A678: bne         $t2, $at, L_8005A698
    if (ctx->r10 != ctx->r1) {
        // 0x8005A67C: nop
    
            goto L_8005A698;
    }
    // 0x8005A67C: nop

    // 0x8005A680: lh          $t3, 0x7C($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X7C);
    // 0x8005A684: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A688: bne         $t3, $at, L_8005A698
    if (ctx->r11 != ctx->r1) {
        // 0x8005A68C: nop
    
            goto L_8005A698;
    }
    // 0x8005A68C: nop

    // 0x8005A690: addiu       $t4, $zero, 0x8C
    ctx->r12 = ADD32(0, 0X8C);
    // 0x8005A694: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8005A698:
    // 0x8005A698: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A69C: jal         0x800B9000
    // 0x8005A6A0: nop

    func_800B9000(rdram, ctx);
        goto after_2;
    // 0x8005A6A0: nop

    after_2:
L_8005A6A4:
    // 0x8005A6A4: b           L_8005A6AC
    // 0x8005A6A8: nop

        goto L_8005A6AC;
    // 0x8005A6A8: nop

L_8005A6AC:
    // 0x8005A6AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A6B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A6B4: jr          $ra
    // 0x8005A6B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005A6B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B1BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1BD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1BD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B1BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1BDC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1BE0: jal         0x800B1CD4
    // 0x800B1BE4: nop

    func_800B1CD4(rdram, ctx);
        goto after_0;
    // 0x800B1BE4: nop

    after_0:
    // 0x800B1BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1BEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1BF0: jal         0x800B1E58
    // 0x800B1BF4: nop

    func_800B1E58(rdram, ctx);
        goto after_1;
    // 0x800B1BF4: nop

    after_1:
    // 0x800B1BF8: b           L_800B1C00
    // 0x800B1BFC: nop

        goto L_800B1C00;
    // 0x800B1BFC: nop

L_800B1C00:
    // 0x800B1C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1C08: jr          $ra
    // 0x800B1C0C: nop

    return;
    // 0x800B1C0C: nop

;}
RECOMP_FUNC void func_80017B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017B00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80017B04: lw          $t6, 0x1A0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A0);
    // 0x80017B08: nop

    // 0x80017B0C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80017B10: sw          $t7, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r15;
    // 0x80017B14: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80017B18: sw          $zero, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = 0;
    // 0x80017B1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017B20: nop

    // 0x80017B24: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x80017B28: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80017B2C: nop

    // 0x80017B30: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x80017B34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017B38: nop

    // 0x80017B3C: swc1        $f8, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f8.u32l;
    // 0x80017B40: lwc1        $f10, 0x1F4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x80017B44: nop

    // 0x80017B48: swc1        $f10, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f10.u32l;
    // 0x80017B4C: sw          $zero, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = 0;
    // 0x80017B50: sw          $zero, 0x210($a0)
    MEM_W(0X210, ctx->r4) = 0;
    // 0x80017B54: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80017B58: lw          $t8, -0x4538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4538);
    // 0x80017B5C: nop

    // 0x80017B60: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x80017B64: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80017B68: b           L_80017B78
    // 0x80017B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017B78;
    // 0x80017B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017B70: b           L_80017B78
    // 0x80017B74: nop

        goto L_80017B78;
    // 0x80017B74: nop

L_80017B78:
    // 0x80017B78: jr          $ra
    // 0x80017B7C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80017B7C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006BE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BE20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BE28: jal         0x8005F064
    // 0x8006BE2C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BE2C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x8006BE30: b           L_8006BE40
    // 0x8006BE34: nop

        goto L_8006BE40;
    // 0x8006BE34: nop

    // 0x8006BE38: b           L_8006BE40
    // 0x8006BE3C: nop

        goto L_8006BE40;
    // 0x8006BE3C: nop

L_8006BE40:
    // 0x8006BE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BE44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BE48: jr          $ra
    // 0x8006BE4C: nop

    return;
    // 0x8006BE4C: nop

;}
RECOMP_FUNC void func_800660A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800660A8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800660AC: nop

    // 0x800660B0: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800660B4: nop

    // 0x800660B8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800660BC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800660C0: jr          $ra
    // 0x800660C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800660C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800660C8: jr          $ra
    // 0x800660CC: nop

    return;
    // 0x800660CC: nop

    // 0x800660D0: jr          $ra
    // 0x800660D4: nop

    return;
    // 0x800660D4: nop

;}
RECOMP_FUNC void func_80062784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062784: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80062788: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006278C: nop

    // 0x80062790: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80062794: nop

    // 0x80062798: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006279C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800627A0: jr          $ra
    // 0x800627A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800627A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800627A8: jr          $ra
    // 0x800627AC: nop

    return;
    // 0x800627AC: nop

    // 0x800627B0: jr          $ra
    // 0x800627B4: nop

    return;
    // 0x800627B4: nop

;}
RECOMP_FUNC void func_8008E0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E0A8: lh          $t6, 0x126($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X126);
    // 0x8008E0AC: lh          $t7, 0x16A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X16A);
    // 0x8008E0B0: nop

    // 0x8008E0B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008E0B8: sh          $t8, 0x126($a0)
    MEM_H(0X126, ctx->r4) = ctx->r24;
    // 0x8008E0BC: lh          $t9, 0x126($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X126);
    // 0x8008E0C0: nop

    // 0x8008E0C4: bgez        $t9, L_8008E114
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8008E0C8: nop
    
            goto L_8008E114;
    }
    // 0x8008E0C8: nop

    // 0x8008E0CC: sh          $zero, 0x126($a0)
    MEM_H(0X126, ctx->r4) = 0;
    // 0x8008E0D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008E0D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E0D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008E0DC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008E0E0: nop

    // 0x8008E0E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008E0E8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8008E0EC: nop

    // 0x8008E0F0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8008E0F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E0F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E0FC: nop

    // 0x8008E100: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008E104: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8008E108: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8008E10C: sh          $t1, 0x16A($a0)
    MEM_H(0X16A, ctx->r4) = ctx->r9;
    // 0x8008E110: nop

L_8008E114:
    // 0x8008E114: lh          $t2, 0x126($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X126);
    // 0x8008E118: nop

    // 0x8008E11C: slti        $at, $t2, 0xC9
    ctx->r1 = SIGNED(ctx->r10) < 0XC9 ? 1 : 0;
    // 0x8008E120: bne         $at, $zero, L_8008E174
    if (ctx->r1 != 0) {
        // 0x8008E124: nop
    
            goto L_8008E174;
    }
    // 0x8008E124: nop

    // 0x8008E128: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8008E12C: sh          $t3, 0x126($a0)
    MEM_H(0X126, ctx->r4) = ctx->r11;
    // 0x8008E130: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8008E134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008E138: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008E13C: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008E140: nop

    // 0x8008E144: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8008E148: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8008E14C: nop

    // 0x8008E150: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8008E154: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E158: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E15C: nop

    // 0x8008E160: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008E164: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8008E168: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8008E16C: sh          $t5, 0x16A($a0)
    MEM_H(0X16A, ctx->r4) = ctx->r13;
    // 0x8008E170: nop

L_8008E174:
    // 0x8008E174: jr          $ra
    // 0x8008E178: nop

    return;
    // 0x8008E178: nop

    // 0x8008E17C: jr          $ra
    // 0x8008E180: nop

    return;
    // 0x8008E180: nop

;}
RECOMP_FUNC void func_80085B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085B24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80085B28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80085B2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80085B30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80085B34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80085B38: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085B3C: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80085B40: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80085B44: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80085B48: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80085B4C: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80085B50: beq         $t0, $zero, L_80085C14
    if (ctx->r8 == 0) {
        // 0x80085B54: nop
    
            goto L_80085C14;
    }
    // 0x80085B54: nop

    // 0x80085B58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80085B5C: jal         0x8008A518
    // 0x80085B60: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80085B60: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80085B64: beq         $v0, $zero, L_80085C14
    if (ctx->r2 == 0) {
        // 0x80085B68: nop
    
            goto L_80085C14;
    }
    // 0x80085B68: nop

    // 0x80085B6C: lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X24);
    // 0x80085B70: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80085B74: beq         $s0, $at, L_80085B90
    if (ctx->r16 == ctx->r1) {
        // 0x80085B78: nop
    
            goto L_80085B90;
    }
    // 0x80085B78: nop

    // 0x80085B7C: addiu       $at, $zero, 0x4005
    ctx->r1 = ADD32(0, 0X4005);
    // 0x80085B80: beq         $s0, $at, L_80085BB8
    if (ctx->r16 == ctx->r1) {
        // 0x80085B84: nop
    
            goto L_80085BB8;
    }
    // 0x80085B84: nop

    // 0x80085B88: b           L_80085C14
    // 0x80085B8C: nop

        goto L_80085C14;
    // 0x80085B8C: nop

L_80085B90:
    // 0x80085B90: jal         0x8008CE48
    // 0x80085B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80085B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80085B98: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80085B9C: nop

    // 0x80085BA0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80085BA4: nop

    // 0x80085BA8: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80085BAC: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80085BB0: b           L_80085C74
    // 0x80085BB4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80085C74;
    // 0x80085BB4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80085BB8:
    // 0x80085BB8: jal         0x8008CE48
    // 0x80085BBC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80085BBC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80085BC0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80085BC4: nop

    // 0x80085BC8: lw          $a0, 0xC10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC10);
    // 0x80085BCC: jal         0x8008C854
    // 0x80085BD0: nop

    func_8008C854(rdram, ctx);
        goto after_3;
    // 0x80085BD0: nop

    after_3:
    // 0x80085BD4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80085BD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80085BDC: lh          $t6, 0xBFE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBFE);
    // 0x80085BE0: nop

    // 0x80085BE4: sh          $t6, 0x7A16($at)
    MEM_H(0X7A16, ctx->r1) = ctx->r14;
    // 0x80085BE8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085BEC: nop

    // 0x80085BF0: sh          $zero, 0xBEC($t7)
    MEM_H(0XBEC, ctx->r15) = 0;
    // 0x80085BF4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80085BF8: nop

    // 0x80085BFC: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80085C00: nop

    // 0x80085C04: ori         $t0, $t8, 0x200
    ctx->r8 = ctx->r24 | 0X200;
    // 0x80085C08: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x80085C0C: b           L_80085C74
    // 0x80085C10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80085C74;
    // 0x80085C10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80085C14:
    // 0x80085C14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80085C18: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x80085C1C: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80085C20: nop

    // 0x80085C24: and         $t1, $t2, $t3
    ctx->r9 = ctx->r10 & ctx->r11;
    // 0x80085C28: beq         $t1, $zero, L_80085C58
    if (ctx->r9 == 0) {
        // 0x80085C2C: nop
    
            goto L_80085C58;
    }
    // 0x80085C2C: nop

    // 0x80085C30: jal         0x8008CE48
    // 0x80085C34: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x80085C34: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_4:
    // 0x80085C38: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80085C3C: nop

    // 0x80085C40: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80085C44: nop

    // 0x80085C48: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x80085C4C: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80085C50: b           L_80085C74
    // 0x80085C54: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80085C74;
    // 0x80085C54: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80085C58:
    // 0x80085C58: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085C5C: nop

    // 0x80085C60: lh          $v0, 0x4($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X4);
    // 0x80085C64: b           L_80085C74
    // 0x80085C68: nop

        goto L_80085C74;
    // 0x80085C68: nop

    // 0x80085C6C: b           L_80085C74
    // 0x80085C70: nop

        goto L_80085C74;
    // 0x80085C70: nop

L_80085C74:
    // 0x80085C74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085C78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085C7C: jr          $ra
    // 0x80085C80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80085C80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63D8: jr          $ra
    // 0x800D63DC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800D63DC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_8006C7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C7C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C7C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C7C8: jal         0x8005F064
    // 0x8006C7CC: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C7CC: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_0:
    // 0x8006C7D0: b           L_8006C7E0
    // 0x8006C7D4: nop

        goto L_8006C7E0;
    // 0x8006C7D4: nop

    // 0x8006C7D8: b           L_8006C7E0
    // 0x8006C7DC: nop

        goto L_8006C7E0;
    // 0x8006C7DC: nop

L_8006C7E0:
    // 0x8006C7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C7E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C7E8: jr          $ra
    // 0x8006C7EC: nop

    return;
    // 0x8006C7EC: nop

;}
RECOMP_FUNC void func_80004510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004510: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80004514: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80004518: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000451C:
    // 0x8000451C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80004520: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80004524: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80004528: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000452C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004530: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004534: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004538: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000453C: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x80004540: nop

    // 0x80004544: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80004548: bne         $t9, $zero, L_80004584
    if (ctx->r25 != 0) {
        // 0x8000454C: nop
    
            goto L_80004584;
    }
    // 0x8000454C: nop

    // 0x80004550: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80004554: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80004558: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8000455C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80004560: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80004564: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80004568: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8000456C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80004570: sw          $zero, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = 0;
    // 0x80004574: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80004578: nop

    // 0x8000457C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80004580: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
L_80004584:
    // 0x80004584: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80004588: nop

    // 0x8000458C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80004590: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x80004594: bne         $at, $zero, L_8000451C
    if (ctx->r1 != 0) {
        // 0x80004598: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_8000451C;
    }
    // 0x80004598: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8000459C: b           L_800045A4
    // 0x800045A0: nop

        goto L_800045A4;
    // 0x800045A0: nop

L_800045A4:
    // 0x800045A4: jr          $ra
    // 0x800045A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800045A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006675C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006675C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066764: jal         0x80061348
    // 0x80066768: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066768: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x8006676C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066770: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066774: b           L_80066784
    // 0x80066778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066784;
    // 0x80066778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006677C: b           L_80066784
    // 0x80066780: nop

        goto L_80066784;
    // 0x80066780: nop

L_80066784:
    // 0x80066784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006678C: jr          $ra
    // 0x80066790: nop

    return;
    // 0x80066790: nop

;}
RECOMP_FUNC void func_8000E3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E3D4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8000E3D8: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8000E3DC: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x8000E3E0: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8000E3E4: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x8000E3E8: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8000E3EC: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8000E3F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E3F4: nop

    // 0x8000E3F8: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8000E3FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E400: nop

    // 0x8000E404: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8000E408: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E40C: nop

    // 0x8000E410: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x8000E414: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E418: nop

    // 0x8000E41C: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x8000E420: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8000E424: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000E428: nop

    // 0x8000E42C: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x8000E430: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E434: nop

    // 0x8000E438: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x8000E43C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8000E440: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8000E444: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
    // 0x8000E448: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    // 0x8000E44C: sh          $zero, 0x62($a0)
    MEM_H(0X62, ctx->r4) = 0;
    // 0x8000E450: sh          $zero, 0x64($a0)
    MEM_H(0X64, ctx->r4) = 0;
    // 0x8000E454: sh          $zero, 0x66($a0)
    MEM_H(0X66, ctx->r4) = 0;
    // 0x8000E458: sh          $zero, 0x68($a0)
    MEM_H(0X68, ctx->r4) = 0;
    // 0x8000E45C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E460: nop

    // 0x8000E464: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8000E468: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E46C: nop

    // 0x8000E470: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8000E474: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E478: nop

    // 0x8000E47C: swc1        $f8, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f8.u32l;
    // 0x8000E480: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8000E484: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E488: nop

    // 0x8000E48C: swc1        $f10, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f10.u32l;
    // 0x8000E490: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000E494: nop

    // 0x8000E498: swc1        $f16, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f16.u32l;
    // 0x8000E49C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E4A0: nop

    // 0x8000E4A4: swc1        $f18, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f18.u32l;
    // 0x8000E4A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E4AC: nop

    // 0x8000E4B0: swc1        $f4, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f4.u32l;
    // 0x8000E4B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E4B8: nop

    // 0x8000E4BC: swc1        $f6, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->f6.u32l;
    // 0x8000E4C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E4C4: nop

    // 0x8000E4C8: swc1        $f8, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f8.u32l;
    // 0x8000E4CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E4D0: nop

    // 0x8000E4D4: swc1        $f10, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f10.u32l;
    // 0x8000E4D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000E4DC: nop

    // 0x8000E4E0: swc1        $f16, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f16.u32l;
    // 0x8000E4E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E4E8: nop

    // 0x8000E4EC: swc1        $f18, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f18.u32l;
    // 0x8000E4F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E4F4: nop

    // 0x8000E4F8: swc1        $f4, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f4.u32l;
    // 0x8000E4FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E500: nop

    // 0x8000E504: swc1        $f6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f6.u32l;
    // 0x8000E508: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E50C: nop

    // 0x8000E510: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8000E514: jr          $ra
    // 0x8000E518: nop

    return;
    // 0x8000E518: nop

    // 0x8000E51C: jr          $ra
    // 0x8000E520: nop

    return;
    // 0x8000E520: nop

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
RECOMP_FUNC void func_8009FC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FC68: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x8009FC6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009FC70: sw          $a0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r4;
    // 0x8009FC74: sw          $a1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r5;
    // 0x8009FC78: sw          $a2, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r6;
    // 0x8009FC7C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009FC80: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009FC84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009FC88: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x8009FC8C: nop

    // 0x8009FC90: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009FC94: nop

    // 0x8009FC98: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x8009FC9C: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009FCA0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009FCA4: lw          $t0, 0x7250($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7250);
    // 0x8009FCA8: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x8009FCAC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009FCB0: lw          $t2, 0x7258($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7258);
    // 0x8009FCB4: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8009FCB8: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8009FCBC: sw          $t3, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r11;
    // 0x8009FCC0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009FCC4: lw          $t5, 0x70E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E4);
    // 0x8009FCC8: lw          $t4, 0x198($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X198);
    // 0x8009FCCC: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8009FCD0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8009FCD4: sw          $t7, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r15;
    // 0x8009FCD8: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009FCDC: lw          $t0, 0x198($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X198);
    // 0x8009FCE0: lh          $t9, 0x11E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X11E);
    // 0x8009FCE4: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8009FCE8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8009FCEC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8009FCF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009FCF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009FCF8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009FCFC: nop

    // 0x8009FD00: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009FD04: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8009FD08: nop

    // 0x8009FD0C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8009FD10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009FD14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009FD18: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009FD1C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8009FD20: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8009FD24: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009FD28: sh          $t2, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r10;
    // 0x8009FD2C: nop

    // 0x8009FD30: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x8009FD34: nop

    // 0x8009FD38: andi        $t5, $t3, 0x40
    ctx->r13 = ctx->r11 & 0X40;
    // 0x8009FD3C: bne         $t5, $zero, L_8009FD80
    if (ctx->r13 != 0) {
        // 0x8009FD40: nop
    
            goto L_8009FD80;
    }
    // 0x8009FD40: nop

    // 0x8009FD44: lw          $t4, 0x194($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X194);
    // 0x8009FD48: nop

    // 0x8009FD4C: lwc1        $f6, 0xF4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x8009FD50: lwc1        $f8, 0xFC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XFC);
    // 0x8009FD54: nop

    // 0x8009FD58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009FD5C: swc1        $f10, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f10.u32l;
    // 0x8009FD60: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8009FD64: nop

    // 0x8009FD68: lwc1        $f16, 0xF8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XF8);
    // 0x8009FD6C: lwc1        $f18, 0xFC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XFC);
    // 0x8009FD70: nop

    // 0x8009FD74: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009FD78: b           L_8009FE1C
    // 0x8009FD7C: swc1        $f4, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f4.u32l;
        goto L_8009FE1C;
    // 0x8009FD7C: swc1        $f4, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f4.u32l;
L_8009FD80:
    // 0x8009FD80: jal         0x800C1680
    // 0x8009FD84: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x8009FD84: nop

    after_0:
    // 0x8009FD88: lw          $a0, 0x144($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X144);
    // 0x8009FD8C: jal         0x800C2B20
    // 0x8009FD90: nop

    MtxUtil_SetCurrentFromMtx(rdram, ctx);
        goto after_1;
    // 0x8009FD90: nop

    after_1:
    // 0x8009FD94: lw          $a0, 0x194($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X194);
    // 0x8009FD98: jal         0x800C1D44
    // 0x8009FD9C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_2;
    // 0x8009FD9C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_2:
    // 0x8009FDA0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009FDA4: jal         0x800C1A84
    // 0x8009FDA8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_3;
    // 0x8009FDA8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_3:
    // 0x8009FDAC: jal         0x800C1A28
    // 0x8009FDB0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_4;
    // 0x8009FDB0: nop

    after_4:
    // 0x8009FDB4: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8009FDB8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8009FDBC: lwc1        $f6, 0xF4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x8009FDC0: lwc1        $f8, 0xFC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x8009FDC4: addiu       $t8, $t8, 0x6BC8
    ctx->r24 = ADD32(ctx->r24, 0X6BC8);
    // 0x8009FDC8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009FDCC: lwc1        $f16, 0x38($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8009FDD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009FDD4: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009FDD8: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8009FDDC: nop

    // 0x8009FDE0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009FDE4: swc1        $f6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f6.u32l;
    // 0x8009FDE8: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009FDEC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8009FDF0: lwc1        $f8, 0xF8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x8009FDF4: lwc1        $f16, 0xFC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XFC);
    // 0x8009FDF8: addiu       $t0, $t0, 0x6BC8
    ctx->r8 = ADD32(ctx->r8, 0X6BC8);
    // 0x8009FDFC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009FE00: lwc1        $f18, 0x38($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X38);
    // 0x8009FE04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009FE08: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009FE0C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8009FE10: nop

    // 0x8009FE14: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009FE18: swc1        $f8, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f8.u32l;
L_8009FE1C:
    // 0x8009FE1C: jal         0x800C1754
    // 0x8009FE20: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_5;
    // 0x8009FE20: nop

    after_5:
    // 0x8009FE24: lw          $a0, 0x144($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X144);
    // 0x8009FE28: jal         0x800C2B20
    // 0x8009FE2C: nop

    MtxUtil_SetCurrentFromMtx(rdram, ctx);
        goto after_6;
    // 0x8009FE2C: nop

    after_6:
    // 0x8009FE30: lw          $a0, 0x194($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X194);
    // 0x8009FE34: jal         0x800C1D44
    // 0x8009FE38: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_7;
    // 0x8009FE38: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_7:
    // 0x8009FE3C: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x8009FE40: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8009FE44: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8009FE48: beq         $t2, $zero, L_8009FE94
    if (ctx->r10 == 0) {
        // 0x8009FE4C: nop
    
            goto L_8009FE94;
    }
    // 0x8009FE4C: nop

    // 0x8009FE50: jal         0x800C1680
    // 0x8009FE54: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_8;
    // 0x8009FE54: nop

    after_8:
    // 0x8009FE58: lw          $a0, 0x194($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X194);
    // 0x8009FE5C: jal         0x800C1AF4
    // 0x8009FE60: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_9;
    // 0x8009FE60: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_9:
    // 0x8009FE64: jal         0x800C1908
    // 0x8009FE68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearTranslation(rdram, ctx);
        goto after_10;
    // 0x8009FE68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8009FE6C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009FE70: jal         0x800C1A84
    // 0x8009FE74: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_11;
    // 0x8009FE74: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_11:
    // 0x8009FE78: jal         0x800C1A28
    // 0x8009FE7C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_12;
    // 0x8009FE7C: nop

    after_12:
    // 0x8009FE80: jal         0x800C197C
    // 0x8009FE84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearRotation(rdram, ctx);
        goto after_13;
    // 0x8009FE84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8009FE88: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009FE8C: jal         0x800C1D44
    // 0x8009FE90: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    func_800C1D44(rdram, ctx);
        goto after_14;
    // 0x8009FE90: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_14:
L_8009FE94:
    // 0x8009FE94: lwc1        $f12, 0x14C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009FE98: lwc1        $f14, 0x148($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8009FE9C: jal         0x800C2948
    // 0x8009FEA0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_15;
    // 0x8009FEA0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_15:
    // 0x8009FEA4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009FEA8: lw          $t5, 0x70E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E4);
    // 0x8009FEAC: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009FEB0: sll         $t4, $t5, 6
    ctx->r12 = S32(ctx->r13 << 6);
    // 0x8009FEB4: jal         0x800C2AE8
    // 0x8009FEB8: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_16;
    // 0x8009FEB8: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_16:
    // 0x8009FEBC: jal         0x800C1A28
    // 0x8009FEC0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_17;
    // 0x8009FEC0: nop

    after_17:
    // 0x8009FEC4: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8009FEC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009FECC: lh          $t7, 0x116($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X116);
    // 0x8009FED0: nop

    // 0x8009FED4: bne         $t7, $at, L_8009FEE4
    if (ctx->r15 != ctx->r1) {
        // 0x8009FED8: nop
    
            goto L_8009FEE4;
    }
    // 0x8009FED8: nop

    // 0x8009FEDC: b           L_800A1998
    // 0x8009FEE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A1998;
    // 0x8009FEE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009FEE4:
    // 0x8009FEE4: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009FEE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009FEEC: lw          $t9, 0x128($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X128);
    // 0x8009FEF0: nop

    // 0x8009FEF4: sw          $t9, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r25;
    // 0x8009FEF8: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x8009FEFC: nop

    // 0x8009FF00: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x8009FF04: bne         $t1, $zero, L_8009FF44
    if (ctx->r9 != 0) {
        // 0x8009FF08: nop
    
            goto L_8009FF44;
    }
    // 0x8009FF08: nop

    // 0x8009FF0C: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x8009FF10: nop

    // 0x8009FF14: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x8009FF18: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x8009FF1C: sw          $t2, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r10;
    // 0x8009FF20: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x8009FF24: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8009FF28: ori         $t3, $t3, 0x1402
    ctx->r11 = ctx->r11 | 0X1402;
    // 0x8009FF2C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8009FF30: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8009FF34: nop

    // 0x8009FF38: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8009FF3C: b           L_8009FF74
    // 0x8009FF40: nop

        goto L_8009FF74;
    // 0x8009FF40: nop

L_8009FF44:
    // 0x8009FF44: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x8009FF48: nop

    // 0x8009FF4C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8009FF50: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x8009FF54: sw          $t7, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r15;
    // 0x8009FF58: lw          $t0, 0x13C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X13C);
    // 0x8009FF5C: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8009FF60: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x8009FF64: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8009FF68: lw          $t2, 0x13C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X13C);
    // 0x8009FF6C: lui         $t1, 0x10
    ctx->r9 = S32(0X10 << 16);
    // 0x8009FF70: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_8009FF74:
    // 0x8009FF74: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x8009FF78: nop

    // 0x8009FF7C: andi        $t3, $t5, 0x200
    ctx->r11 = ctx->r13 & 0X200;
    // 0x8009FF80: bne         $t3, $zero, L_8009FFC0
    if (ctx->r11 != 0) {
        // 0x8009FF84: nop
    
            goto L_8009FFC0;
    }
    // 0x8009FF84: nop

    // 0x8009FF88: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x8009FF8C: nop

    // 0x8009FF90: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x8009FF94: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x8009FF98: sw          $t4, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r12;
    // 0x8009FF9C: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x8009FFA0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8009FFA4: ori         $t7, $t7, 0x201
    ctx->r15 = ctx->r15 | 0X201;
    // 0x8009FFA8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009FFAC: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x8009FFB0: nop

    // 0x8009FFB4: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009FFB8: b           L_800A0000
    // 0x8009FFBC: nop

        goto L_800A0000;
    // 0x8009FFBC: nop

L_8009FFC0:
    // 0x8009FFC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009FFC4: lwc1        $f16, 0x25A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25A8);
    // 0x8009FFC8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8009FFCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009FFD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009FFD4: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009FFD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FFDC: lw          $a0, 0x190($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X190);
    // 0x8009FFE0: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8009FFE4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8009FFE8: jal         0x8009A084
    // 0x8009FFEC: nop

    func_8009A084(rdram, ctx);
        goto after_18;
    // 0x8009FFEC: nop

    after_18:
    // 0x8009FFF0: bgez        $v0, L_800A0000
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009FFF4: nop
    
            goto L_800A0000;
    }
    // 0x8009FFF4: nop

    // 0x8009FFF8: b           L_800A1998
    // 0x8009FFFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A1998;
    // 0x8009FFFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A0000:
    // 0x800A0000: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0004: nop

    // 0x800A0008: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A000C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A0010: sw          $t0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r8;
    // 0x800A0014: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x800A0018: lui         $t2, 0x106
    ctx->r10 = S32(0X106 << 16);
    // 0x800A001C: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x800A0020: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A0024: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0028: lw          $t4, 0x70E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70E4);
    // 0x800A002C: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x800A0030: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A0034: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x800A0038: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x800A003C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A0040: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800A0044: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800A0048: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A004C: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0050: nop

    // 0x800A0054: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A0058: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A005C: sw          $t0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r8;
    // 0x800A0060: lw          $t5, 0x130($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X130);
    // 0x800A0064: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x800A0068: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x800A006C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A0070: lw          $t3, 0x130($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X130);
    // 0x800A0074: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A0078: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x800A007C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A0080: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x800A0084: nop

    // 0x800A0088: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x800A008C: bne         $t7, $zero, L_800A02D8
    if (ctx->r15 != 0) {
        // 0x800A0090: nop
    
            goto L_800A02D8;
    }
    // 0x800A0090: nop

    // 0x800A0094: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0098: nop

    // 0x800A009C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A00A0: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A00A4: sw          $t8, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r24;
    // 0x800A00A8: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x800A00AC: lui         $t0, 0xB600
    ctx->r8 = S32(0XB600 << 16);
    // 0x800A00B0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A00B4: lw          $t5, 0x12C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X12C);
    // 0x800A00B8: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800A00BC: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // 0x800A00C0: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800A00C4: nop

    // 0x800A00C8: andi        $t3, $t4, 0x20
    ctx->r11 = ctx->r12 & 0X20;
    // 0x800A00CC: beq         $t3, $zero, L_800A0144
    if (ctx->r11 == 0) {
        // 0x800A00D0: nop
    
            goto L_800A0144;
    }
    // 0x800A00D0: nop

    // 0x800A00D4: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A00D8: nop

    // 0x800A00DC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A00E0: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A00E4: sw          $t6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r14;
    // 0x800A00E8: lw          $t9, 0x128($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X128);
    // 0x800A00EC: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800A00F0: ori         $t8, $t8, 0xFE24
    ctx->r24 = ctx->r24 | 0XFE24;
    // 0x800A00F4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A00F8: lw          $t1, 0x128($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X128);
    // 0x800A00FC: lui         $t0, 0xFF30
    ctx->r8 = S32(0XFF30 << 16);
    // 0x800A0100: ori         $t0, $t0, 0xF3FF
    ctx->r8 = ctx->r8 | 0XF3FF;
    // 0x800A0104: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A0108: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A010C: nop

    // 0x800A0110: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A0114: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A0118: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x800A011C: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x800A0120: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x800A0124: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x800A0128: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A012C: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x800A0130: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x800A0134: ori         $t6, $t6, 0x233
    ctx->r14 = ctx->r14 | 0X233;
    // 0x800A0138: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A013C: b           L_800A0230
    // 0x800A0140: nop

        goto L_800A0230;
    // 0x800A0140: nop

L_800A0144:
    // 0x800A0144: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800A0148: nop

    // 0x800A014C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800A0150: beq         $t9, $zero, L_800A01C8
    if (ctx->r25 == 0) {
        // 0x800A0154: nop
    
            goto L_800A01C8;
    }
    // 0x800A0154: nop

    // 0x800A0158: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A015C: nop

    // 0x800A0160: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A0164: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A0168: sw          $t0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r8;
    // 0x800A016C: lw          $t5, 0x120($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X120);
    // 0x800A0170: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x800A0174: ori         $t2, $t2, 0xFE24
    ctx->r10 = ctx->r10 | 0XFE24;
    // 0x800A0178: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A017C: lw          $t3, 0x120($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X120);
    // 0x800A0180: lui         $t4, 0xFF30
    ctx->r12 = S32(0XFF30 << 16);
    // 0x800A0184: ori         $t4, $t4, 0xF3FF
    ctx->r12 = ctx->r12 | 0XF3FF;
    // 0x800A0188: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A018C: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0190: nop

    // 0x800A0194: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A0198: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A019C: sw          $t6, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r14;
    // 0x800A01A0: lw          $t9, 0x11C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X11C);
    // 0x800A01A4: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800A01A8: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x800A01AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A01B0: lw          $t1, 0x11C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X11C);
    // 0x800A01B4: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x800A01B8: ori         $t0, $t0, 0x4A50
    ctx->r8 = ctx->r8 | 0X4A50;
    // 0x800A01BC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A01C0: b           L_800A0230
    // 0x800A01C4: nop

        goto L_800A0230;
    // 0x800A01C4: nop

L_800A01C8:
    // 0x800A01C8: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A01CC: nop

    // 0x800A01D0: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A01D4: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A01D8: sw          $t2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r10;
    // 0x800A01DC: lw          $t3, 0x118($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X118);
    // 0x800A01E0: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x800A01E4: ori         $t4, $t4, 0xFE24
    ctx->r12 = ctx->r12 | 0XFE24;
    // 0x800A01E8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A01EC: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x800A01F0: lui         $t6, 0xFF30
    ctx->r14 = S32(0XFF30 << 16);
    // 0x800A01F4: ori         $t6, $t6, 0xF3FF
    ctx->r14 = ctx->r14 | 0XF3FF;
    // 0x800A01F8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A01FC: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0200: nop

    // 0x800A0204: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A0208: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A020C: sw          $t8, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r24;
    // 0x800A0210: lw          $t1, 0x114($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X114);
    // 0x800A0214: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x800A0218: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x800A021C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A0220: lw          $t5, 0x114($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X114);
    // 0x800A0224: lui         $t2, 0x55
    ctx->r10 = S32(0X55 << 16);
    // 0x800A0228: ori         $t2, $t2, 0x3078
    ctx->r10 = ctx->r10 | 0X3078;
    // 0x800A022C: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
L_800A0230:
    // 0x800A0230: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800A0234: nop

    // 0x800A0238: andi        $t3, $t4, 0x800
    ctx->r11 = ctx->r12 & 0X800;
    // 0x800A023C: bne         $t3, $zero, L_800A02A4
    if (ctx->r11 != 0) {
        // 0x800A0240: nop
    
            goto L_800A02A4;
    }
    // 0x800A0240: nop

    // 0x800A0244: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0248: nop

    // 0x800A024C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A0250: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A0254: sw          $t6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r14;
    // 0x800A0258: lw          $t9, 0x110($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X110);
    // 0x800A025C: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x800A0260: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A0264: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x800A0268: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
    // 0x800A026C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A0270: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0274: nop

    // 0x800A0278: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A027C: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A0280: sw          $t2, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r10;
    // 0x800A0284: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x800A0288: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x800A028C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A0290: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x800A0294: addiu       $t6, $zero, 0x205
    ctx->r14 = ADD32(0, 0X205);
    // 0x800A0298: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A029C: b           L_800A02D0
    // 0x800A02A0: nop

        goto L_800A02D0;
    // 0x800A02A0: nop

L_800A02A4:
    // 0x800A02A4: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A02A8: nop

    // 0x800A02AC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A02B0: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A02B4: sw          $t8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r24;
    // 0x800A02B8: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x800A02BC: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x800A02C0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A02C4: lw          $t5, 0x108($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X108);
    // 0x800A02C8: addiu       $t2, $zero, 0x2205
    ctx->r10 = ADD32(0, 0X2205);
    // 0x800A02CC: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
L_800A02D0:
    // 0x800A02D0: b           L_800A03E4
    // 0x800A02D4: nop

        goto L_800A03E4;
    // 0x800A02D4: nop

L_800A02D8:
    // 0x800A02D8: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A02DC: nop

    // 0x800A02E0: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800A02E4: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A02E8: sw          $t4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r12;
    // 0x800A02EC: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800A02F0: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A02F4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A02F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A02FC: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x800A0300: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x800A0304: ori         $t8, $t8, 0xF238
    ctx->r24 = ctx->r24 | 0XF238;
    // 0x800A0308: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A030C: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0310: nop

    // 0x800A0314: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A0318: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A031C: sw          $t0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r8;
    // 0x800A0320: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x800A0324: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x800A0328: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x800A032C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A0330: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x800A0334: lui         $t4, 0xC811
    ctx->r12 = S32(0XC811 << 16);
    // 0x800A0338: ori         $t4, $t4, 0x3078
    ctx->r12 = ctx->r12 | 0X3078;
    // 0x800A033C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A0340: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x800A0344: nop

    // 0x800A0348: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800A034C: bne         $t7, $zero, L_800A03B8
    if (ctx->r15 != 0) {
        // 0x800A0350: nop
    
            goto L_800A03B8;
    }
    // 0x800A0350: nop

    // 0x800A0354: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0358: nop

    // 0x800A035C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A0360: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A0364: sw          $t8, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r24;
    // 0x800A0368: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x800A036C: lui         $t0, 0xB600
    ctx->r8 = S32(0XB600 << 16);
    // 0x800A0370: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A0374: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x800A0378: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x800A037C: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // 0x800A0380: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0384: nop

    // 0x800A0388: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800A038C: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A0390: sw          $t4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r12;
    // 0x800A0394: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x800A0398: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x800A039C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A03A0: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x800A03A4: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800A03A8: ori         $t8, $t8, 0x205
    ctx->r24 = ctx->r24 | 0X205;
    // 0x800A03AC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A03B0: b           L_800A03E4
    // 0x800A03B4: nop

        goto L_800A03E4;
    // 0x800A03B4: nop

L_800A03B8:
    // 0x800A03B8: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A03BC: nop

    // 0x800A03C0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A03C4: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A03C8: sw          $t0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r8;
    // 0x800A03CC: lw          $t5, 0xF4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF4);
    // 0x800A03D0: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x800A03D4: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A03D8: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x800A03DC: addiu       $t4, $zero, 0x2205
    ctx->r12 = ADD32(0, 0X2205);
    // 0x800A03E0: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
L_800A03E4:
    // 0x800A03E4: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A03E8: nop

    // 0x800A03EC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A03F0: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A03F4: sw          $t6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r14;
    // 0x800A03F8: lw          $t9, 0xF0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF0);
    // 0x800A03FC: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800A0400: ori         $t8, $t8, 0x1301
    ctx->r24 = ctx->r24 | 0X1301;
    // 0x800A0404: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A0408: lw          $t1, 0xF0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF0);
    // 0x800A040C: lui         $t0, 0x8
    ctx->r8 = S32(0X8 << 16);
    // 0x800A0410: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A0414: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0418: nop

    // 0x800A041C: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A0420: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A0424: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x800A0428: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x800A042C: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A0430: ori         $t4, $t4, 0x1102
    ctx->r12 = ctx->r12 | 0X1102;
    // 0x800A0434: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A0438: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x800A043C: lui         $t6, 0x4
    ctx->r14 = S32(0X4 << 16);
    // 0x800A0440: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A0444: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0448: nop

    // 0x800A044C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A0450: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A0454: sw          $t8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r24;
    // 0x800A0458: lw          $t1, 0xE8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE8);
    // 0x800A045C: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x800A0460: ori         $t0, $t0, 0x1001
    ctx->r8 = ctx->r8 | 0X1001;
    // 0x800A0464: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A0468: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x800A046C: nop

    // 0x800A0470: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A0474: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x800A0478: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A047C: lh          $t4, 0x116($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X116);
    // 0x800A0480: nop

    // 0x800A0484: beq         $t4, $at, L_800A0724
    if (ctx->r12 == ctx->r1) {
        // 0x800A0488: nop
    
            goto L_800A0724;
    }
    // 0x800A0488: nop

    // 0x800A048C: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x800A0490: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0494: lh          $t6, 0x116($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X116);
    // 0x800A0498: nop

    // 0x800A049C: bne         $t6, $at, L_800A05CC
    if (ctx->r14 != ctx->r1) {
        // 0x800A04A0: nop
    
            goto L_800A05CC;
    }
    // 0x800A04A0: nop

    // 0x800A04A4: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A04A8: nop

    // 0x800A04AC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A04B0: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A04B4: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x800A04B8: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x800A04BC: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x800A04C0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A04C4: lw          $t1, 0x194($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X194);
    // 0x800A04C8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A04CC: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x800A04D0: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x800A04D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A04D8: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x800A04DC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x800A04E0: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A04E4: nop

    // 0x800A04E8: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800A04EC: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A04F0: sw          $t3, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r11;
    // 0x800A04F4: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x800A04F8: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x800A04FC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A0500: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x800A0504: nop

    // 0x800A0508: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A050C: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0510: nop

    // 0x800A0514: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A0518: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A051C: sw          $t0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r8;
    // 0x800A0520: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x800A0524: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x800A0528: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800A052C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A0530: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x800A0534: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800A0538: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A053C: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0540: nop

    // 0x800A0544: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A0548: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A054C: sw          $t6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r14;
    // 0x800A0550: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x800A0554: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800A0558: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A055C: lw          $t0, 0xD8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD8);
    // 0x800A0560: nop

    // 0x800A0564: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800A0568: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A056C: nop

    // 0x800A0570: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A0574: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A0578: sw          $t1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r9;
    // 0x800A057C: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x800A0580: lui         $t5, 0xF000
    ctx->r13 = S32(0XF000 << 16);
    // 0x800A0584: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A0588: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800A058C: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x800A0590: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x800A0594: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800A0598: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A059C: nop

    // 0x800A05A0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A05A4: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A05A8: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
    // 0x800A05AC: lw          $t0, 0xD0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD0);
    // 0x800A05B0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800A05B4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A05B8: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x800A05BC: nop

    // 0x800A05C0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A05C4: b           L_800A06EC
    // 0x800A05C8: nop

        goto L_800A06EC;
    // 0x800A05C8: nop

L_800A05CC:
    // 0x800A05CC: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A05D0: nop

    // 0x800A05D4: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A05D8: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A05DC: sw          $t2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r10;
    // 0x800A05E0: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x800A05E4: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x800A05E8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A05EC: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x800A05F0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A05F4: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x800A05F8: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x800A05FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A0600: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800A0604: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A0608: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A060C: nop

    // 0x800A0610: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A0614: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A0618: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x800A061C: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800A0620: lui         $t2, 0xE800
    ctx->r10 = S32(0XE800 << 16);
    // 0x800A0624: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A0628: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800A062C: nop

    // 0x800A0630: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800A0634: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0638: nop

    // 0x800A063C: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800A0640: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A0644: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800A0648: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A064C: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x800A0650: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x800A0654: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A0658: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A065C: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x800A0660: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A0664: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0668: nop

    // 0x800A066C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A0670: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A0674: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x800A0678: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800A067C: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800A0680: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A0684: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x800A0688: nop

    // 0x800A068C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A0690: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0694: nop

    // 0x800A0698: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A069C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A06A0: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x800A06A4: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x800A06A8: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x800A06AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A06B0: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x800A06B4: lui         $t0, 0x703
    ctx->r8 = S32(0X703 << 16);
    // 0x800A06B8: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x800A06BC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A06C0: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A06C4: nop

    // 0x800A06C8: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A06CC: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A06D0: sw          $t2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r10;
    // 0x800A06D4: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x800A06D8: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800A06DC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A06E0: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800A06E4: nop

    // 0x800A06E8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_800A06EC:
    // 0x800A06EC: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A06F0: nop

    // 0x800A06F4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A06F8: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A06FC: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x800A0700: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800A0704: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A0708: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x800A070C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A0710: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800A0714: ori         $t1, $zero, 0x8000
    ctx->r9 = 0 | 0X8000;
    // 0x800A0718: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A071C: b           L_800A0754
    // 0x800A0720: nop

        goto L_800A0754;
    // 0x800A0720: nop

L_800A0724:
    // 0x800A0724: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0728: nop

    // 0x800A072C: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x800A0730: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A0734: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x800A0738: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800A073C: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A0740: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x800A0744: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800A0748: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x800A074C: nop

    // 0x800A0750: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
L_800A0754:
    // 0x800A0754: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0758: nop

    // 0x800A075C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A0760: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A0764: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x800A0768: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800A076C: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x800A0770: ori         $t0, $t0, 0x903
    ctx->r8 = ctx->r8 | 0X903;
    // 0x800A0774: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A0778: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x800A077C: addiu       $t2, $zero, 0xC00
    ctx->r10 = ADD32(0, 0XC00);
    // 0x800A0780: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // 0x800A0784: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800A0788: nop

    // 0x800A078C: andi        $t3, $t4, 0x4
    ctx->r11 = ctx->r12 & 0X4;
    // 0x800A0790: bne         $t3, $zero, L_800A07D0
    if (ctx->r11 != 0) {
        // 0x800A0794: nop
    
            goto L_800A07D0;
    }
    // 0x800A0794: nop

    // 0x800A0798: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A079C: nop

    // 0x800A07A0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A07A4: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A07A8: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x800A07AC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800A07B0: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800A07B4: ori         $t8, $t8, 0xC02
    ctx->r24 = ctx->r24 | 0XC02;
    // 0x800A07B8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A07BC: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x800A07C0: nop

    // 0x800A07C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800A07C8: b           L_800A0800
    // 0x800A07CC: nop

        goto L_800A0800;
    // 0x800A07CC: nop

L_800A07D0:
    // 0x800A07D0: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A07D4: nop

    // 0x800A07D8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A07DC: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A07E0: sw          $t1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r9;
    // 0x800A07E4: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x800A07E8: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A07EC: ori         $t5, $t5, 0xC02
    ctx->r13 = ctx->r13 | 0XC02;
    // 0x800A07F0: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A07F4: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800A07F8: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x800A07FC: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
L_800A0800:
    // 0x800A0800: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A0804: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A0808: nop

    // 0x800A080C: sw          $t7, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r15;
    // 0x800A0810: sw          $zero, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = 0;
L_800A0814:
    // 0x800A0814: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A0818: lw          $t8, 0x72D0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72D0);
    // 0x800A081C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0820: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800A0824: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x800A0828: sw          $t0, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r8;
    // 0x800A082C: sh          $t9, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r25;
    // 0x800A0830: lh          $t1, 0x186($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X186);
    // 0x800A0834: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800A0838: bne         $t1, $at, L_800A0848
    if (ctx->r9 != ctx->r1) {
        // 0x800A083C: nop
    
            goto L_800A0848;
    }
    // 0x800A083C: nop

    // 0x800A0840: b           L_800A0DB4
    // 0x800A0844: nop

        goto L_800A0DB4;
    // 0x800A0844: nop

L_800A0848:
    // 0x800A0848: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A084C: lw          $t2, 0x72D0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72D0);
    // 0x800A0850: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0854: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x800A0858: addiu       $t4, $t2, 0x2
    ctx->r12 = ADD32(ctx->r10, 0X2);
    // 0x800A085C: sw          $t4, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r12;
    // 0x800A0860: sh          $t5, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r13;
    // 0x800A0864: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A0868: lw          $t3, 0x72D0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72D0);
    // 0x800A086C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0870: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x800A0874: addiu       $t7, $t3, 0x2
    ctx->r15 = ADD32(ctx->r11, 0X2);
    // 0x800A0878: sw          $t7, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r15;
    // 0x800A087C: sh          $t6, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r14;
    // 0x800A0880: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0884: lw          $t9, 0x72D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72D0);
    // 0x800A0888: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A088C: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x800A0890: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x800A0894: sw          $t0, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r8;
    // 0x800A0898: sh          $t8, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r24;
    // 0x800A089C: lw          $t5, 0x16C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X16C);
    // 0x800A08A0: lh          $t1, 0x182($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X182);
    // 0x800A08A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A08A8: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x800A08AC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800A08B0: sh          $t1, 0x7328($at)
    MEM_H(0X7328, ctx->r1) = ctx->r9;
    // 0x800A08B4: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x800A08B8: lh          $t4, 0x180($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X180);
    // 0x800A08BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A08C0: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800A08C4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800A08C8: sh          $t4, 0x732A($at)
    MEM_H(0X732A, ctx->r1) = ctx->r12;
    // 0x800A08CC: lw          $t7, 0x15C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X15C);
    // 0x800A08D0: nop

    // 0x800A08D4: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x800A08D8: bne         $t8, $zero, L_800A0988
    if (ctx->r24 != 0) {
        // 0x800A08DC: nop
    
            goto L_800A0988;
    }
    // 0x800A08DC: nop

    // 0x800A08E0: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800A08E4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A08E8: lw          $t9, 0x72D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72D0);
    // 0x800A08EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A08F0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A08F4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800A08F8: sw          $t9, 0x7310($at)
    MEM_W(0X7310, ctx->r1) = ctx->r25;
    // 0x800A08FC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A0900: lw          $t1, 0x72D0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72D0);
    // 0x800A0904: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0908: sw          $t1, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r9;
    // 0x800A090C: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x800A0910: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0914: lh          $t6, 0x116($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X116);
    // 0x800A0918: nop

    // 0x800A091C: bne         $t6, $at, L_800A094C
    if (ctx->r14 != ctx->r1) {
        // 0x800A0920: nop
    
            goto L_800A094C;
    }
    // 0x800A0920: nop

    // 0x800A0924: lh          $t4, 0x182($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X182);
    // 0x800A0928: lh          $t3, 0x180($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X180);
    // 0x800A092C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A0930: multu       $t4, $t3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A0934: lw          $t8, 0x72E0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72E0);
    // 0x800A0938: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A093C: mflo        $t7
    ctx->r15 = lo;
    // 0x800A0940: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x800A0944: b           L_800A0974
    // 0x800A0948: sw          $t0, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r8;
        goto L_800A0974;
    // 0x800A0948: sw          $t0, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r8;
L_800A094C:
    // 0x800A094C: lh          $t9, 0x182($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X182);
    // 0x800A0950: lh          $t5, 0x180($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X180);
    // 0x800A0954: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0958: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A095C: lw          $t6, 0x72E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72E0);
    // 0x800A0960: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0964: mflo        $t1
    ctx->r9 = lo;
    // 0x800A0968: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800A096C: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x800A0970: sw          $t4, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r12;
L_800A0974:
    // 0x800A0974: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A0978: lw          $t3, 0x72E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72E0);
    // 0x800A097C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0980: b           L_800A09BC
    // 0x800A0984: sw          $t3, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r11;
        goto L_800A09BC;
    // 0x800A0984: sw          $t3, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r11;
L_800A0988:
    // 0x800A0988: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A098C: lw          $t8, 0x72D0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72D0);
    // 0x800A0990: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800A0994: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800A0998: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A099C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800A09A0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A09A4: sw          $t7, 0x7310($at)
    MEM_W(0X7310, ctx->r1) = ctx->r15;
    // 0x800A09A8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A09AC: lw          $t5, 0x72D0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72D0);
    // 0x800A09B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A09B4: addiu       $t1, $t5, 0x4
    ctx->r9 = ADD32(ctx->r13, 0X4);
    // 0x800A09B8: sw          $t1, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r9;
L_800A09BC:
    // 0x800A09BC: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x800A09C0: lh          $t6, 0x186($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X186);
    // 0x800A09C4: lh          $t4, 0x106($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X106);
    // 0x800A09C8: nop

    // 0x800A09CC: addu        $t3, $t6, $t4
    ctx->r11 = ADD32(ctx->r14, ctx->r12);
    // 0x800A09D0: sh          $t3, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r11;
    // 0x800A09D4: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x800A09D8: lh          $t7, 0x184($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X184);
    // 0x800A09DC: lh          $t0, 0x10A($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X10A);
    // 0x800A09E0: nop

    // 0x800A09E4: subu        $t9, $t0, $t7
    ctx->r25 = SUB32(ctx->r8, ctx->r15);
    // 0x800A09E8: sh          $t9, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r25;
    // 0x800A09EC: lh          $t5, 0x186($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X186);
    // 0x800A09F0: lh          $t1, 0x182($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X182);
    // 0x800A09F4: nop

    // 0x800A09F8: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x800A09FC: sh          $t2, 0x17E($sp)
    MEM_H(0X17E, ctx->r29) = ctx->r10;
    // 0x800A0A00: lh          $t6, 0x184($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X184);
    // 0x800A0A04: lh          $t4, 0x180($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X180);
    // 0x800A0A08: nop

    // 0x800A0A0C: subu        $t3, $t6, $t4
    ctx->r11 = SUB32(ctx->r14, ctx->r12);
    // 0x800A0A10: sh          $t3, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r11;
    // 0x800A0A14: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800A0A18: nop

    // 0x800A0A1C: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x800A0A20: beq         $t0, $zero, L_800A0A48
    if (ctx->r8 == 0) {
        // 0x800A0A24: nop
    
            goto L_800A0A48;
    }
    // 0x800A0A24: nop

    // 0x800A0A28: lh          $t7, 0x186($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X186);
    // 0x800A0A2C: nop

    // 0x800A0A30: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800A0A34: sh          $t9, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r25;
    // 0x800A0A38: lh          $t5, 0x17E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X17E);
    // 0x800A0A3C: nop

    // 0x800A0A40: negu        $t1, $t5
    ctx->r9 = SUB32(0, ctx->r13);
    // 0x800A0A44: sh          $t1, 0x17E($sp)
    MEM_H(0X17E, ctx->r29) = ctx->r9;
L_800A0A48:
    // 0x800A0A48: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x800A0A4C: nop

    // 0x800A0A50: andi        $t6, $t2, 0x2
    ctx->r14 = ctx->r10 & 0X2;
    // 0x800A0A54: beq         $t6, $zero, L_800A0A7C
    if (ctx->r14 == 0) {
        // 0x800A0A58: nop
    
            goto L_800A0A7C;
    }
    // 0x800A0A58: nop

    // 0x800A0A5C: lh          $t4, 0x184($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X184);
    // 0x800A0A60: nop

    // 0x800A0A64: negu        $t3, $t4
    ctx->r11 = SUB32(0, ctx->r12);
    // 0x800A0A68: sh          $t3, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r11;
    // 0x800A0A6C: lh          $t8, 0x17C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X17C);
    // 0x800A0A70: nop

    // 0x800A0A74: negu        $t0, $t8
    ctx->r8 = SUB32(0, ctx->r24);
    // 0x800A0A78: sh          $t0, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r8;
L_800A0A7C:
    // 0x800A0A7C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0A80: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0A84: lh          $t7, 0x186($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X186);
    // 0x800A0A88: nop

    // 0x800A0A8C: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x800A0A90: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A0A94: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A0A98: lh          $t5, 0x184($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X184);
    // 0x800A0A9C: nop

    // 0x800A0AA0: sh          $t5, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r13;
    // 0x800A0AA4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A0AA8: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A0AAC: nop

    // 0x800A0AB0: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x800A0AB4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0AB8: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A0ABC: nop

    // 0x800A0AC0: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800A0AC4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0AC8: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A0ACC: nop

    // 0x800A0AD0: sh          $zero, 0xA($t4)
    MEM_H(0XA, ctx->r12) = 0;
    // 0x800A0AD4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A0AD8: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A0ADC: nop

    // 0x800A0AE0: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x800A0AE4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A0AE8: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A0AEC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A0AF0: sb          $t8, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r24;
    // 0x800A0AF4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0AF8: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0AFC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A0B00: sb          $t7, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r15;
    // 0x800A0B04: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A0B08: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A0B0C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A0B10: sb          $t5, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r13;
    // 0x800A0B14: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800A0B18: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0B1C: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A0B20: lh          $t2, -0x4CDC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CDC);
    // 0x800A0B24: nop

    // 0x800A0B28: sb          $t2, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r10;
    // 0x800A0B2C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0B30: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A0B34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0B38: addiu       $t3, $t4, 0x10
    ctx->r11 = ADD32(ctx->r12, 0X10);
    // 0x800A0B3C: sw          $t3, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r11;
    // 0x800A0B40: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A0B44: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A0B48: lh          $t8, 0x17E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X17E);
    // 0x800A0B4C: nop

    // 0x800A0B50: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x800A0B54: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0B58: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0B5C: lh          $t7, 0x184($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X184);
    // 0x800A0B60: nop

    // 0x800A0B64: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x800A0B68: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A0B6C: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A0B70: nop

    // 0x800A0B74: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800A0B78: lh          $t1, 0x182($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X182);
    // 0x800A0B7C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0B80: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A0B84: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x800A0B88: sh          $t2, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r10;
    // 0x800A0B8C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0B90: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A0B94: nop

    // 0x800A0B98: sh          $zero, 0xA($t4)
    MEM_H(0XA, ctx->r12) = 0;
    // 0x800A0B9C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A0BA0: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A0BA4: nop

    // 0x800A0BA8: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x800A0BAC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A0BB0: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A0BB4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A0BB8: sb          $t8, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r24;
    // 0x800A0BBC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0BC0: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0BC4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A0BC8: sb          $t7, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r15;
    // 0x800A0BCC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A0BD0: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A0BD4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A0BD8: sb          $t5, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r13;
    // 0x800A0BDC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800A0BE0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0BE4: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A0BE8: lh          $t2, -0x4CDC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CDC);
    // 0x800A0BEC: nop

    // 0x800A0BF0: sb          $t2, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r10;
    // 0x800A0BF4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0BF8: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A0BFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0C00: addiu       $t3, $t4, 0x10
    ctx->r11 = ADD32(ctx->r12, 0X10);
    // 0x800A0C04: sw          $t3, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r11;
    // 0x800A0C08: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A0C0C: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A0C10: lh          $t8, 0x186($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X186);
    // 0x800A0C14: nop

    // 0x800A0C18: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x800A0C1C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0C20: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0C24: lh          $t7, 0x17C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X17C);
    // 0x800A0C28: nop

    // 0x800A0C2C: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x800A0C30: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A0C34: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A0C38: nop

    // 0x800A0C3C: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800A0C40: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A0C44: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A0C48: nop

    // 0x800A0C4C: sh          $zero, 0x8($t1)
    MEM_H(0X8, ctx->r9) = 0;
    // 0x800A0C50: lh          $t2, 0x180($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X180);
    // 0x800A0C54: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0C58: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A0C5C: sll         $t6, $t2, 6
    ctx->r14 = S32(ctx->r10 << 6);
    // 0x800A0C60: sh          $t6, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r14;
    // 0x800A0C64: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A0C68: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A0C6C: nop

    // 0x800A0C70: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x800A0C74: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A0C78: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A0C7C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A0C80: sb          $t8, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r24;
    // 0x800A0C84: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0C88: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0C8C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A0C90: sb          $t7, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r15;
    // 0x800A0C94: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A0C98: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A0C9C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A0CA0: sb          $t5, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r13;
    // 0x800A0CA4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800A0CA8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0CAC: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A0CB0: lh          $t2, -0x4CDC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CDC);
    // 0x800A0CB4: nop

    // 0x800A0CB8: sb          $t2, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r10;
    // 0x800A0CBC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0CC0: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A0CC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0CC8: addiu       $t3, $t4, 0x10
    ctx->r11 = ADD32(ctx->r12, 0X10);
    // 0x800A0CCC: sw          $t3, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r11;
    // 0x800A0CD0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A0CD4: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A0CD8: lh          $t8, 0x17E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X17E);
    // 0x800A0CDC: nop

    // 0x800A0CE0: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x800A0CE4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0CE8: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0CEC: lh          $t7, 0x17C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X17C);
    // 0x800A0CF0: nop

    // 0x800A0CF4: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x800A0CF8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A0CFC: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A0D00: nop

    // 0x800A0D04: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800A0D08: lh          $t1, 0x182($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X182);
    // 0x800A0D0C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0D10: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A0D14: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x800A0D18: sh          $t2, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r10;
    // 0x800A0D1C: lh          $t4, 0x180($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X180);
    // 0x800A0D20: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A0D24: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A0D28: sll         $t3, $t4, 6
    ctx->r11 = S32(ctx->r12 << 6);
    // 0x800A0D2C: sh          $t3, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r11;
    // 0x800A0D30: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A0D34: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A0D38: nop

    // 0x800A0D3C: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x800A0D40: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A0D44: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A0D48: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A0D4C: sb          $t7, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r15;
    // 0x800A0D50: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A0D54: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A0D58: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A0D5C: sb          $t5, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r13;
    // 0x800A0D60: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A0D64: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A0D68: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A0D6C: sb          $t2, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r10;
    // 0x800A0D70: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800A0D74: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A0D78: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A0D7C: lh          $t4, -0x4CDC($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CDC);
    // 0x800A0D80: nop

    // 0x800A0D84: sb          $t4, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r12;
    // 0x800A0D88: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A0D8C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A0D90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0D94: addiu       $t0, $t8, 0x10
    ctx->r8 = ADD32(ctx->r24, 0X10);
    // 0x800A0D98: sw          $t0, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r8;
    // 0x800A0D9C: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x800A0DA0: nop

    // 0x800A0DA4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800A0DA8: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800A0DAC: bne         $at, $zero, L_800A0814
    if (ctx->r1 != 0) {
        // 0x800A0DB0: sw          $t9, 0x16C($sp)
        MEM_W(0X16C, ctx->r29) = ctx->r25;
            goto L_800A0814;
    }
    // 0x800A0DB0: sw          $t9, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r25;
L_800A0DB4:
    // 0x800A0DB4: lw          $t5, 0x16C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X16C);
    // 0x800A0DB8: nop

    // 0x800A0DBC: bne         $t5, $zero, L_800A0DCC
    if (ctx->r13 != 0) {
        // 0x800A0DC0: nop
    
            goto L_800A0DCC;
    }
    // 0x800A0DC0: nop

    // 0x800A0DC4: b           L_800A18F4
    // 0x800A0DC8: nop

        goto L_800A18F4;
    // 0x800A0DC8: nop

L_800A0DCC:
    // 0x800A0DCC: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0DD0: nop

    // 0x800A0DD4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A0DD8: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A0DDC: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x800A0DE0: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x800A0DE4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800A0DE8: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800A0DEC: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x800A0DF0: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x800A0DF4: andi        $t0, $t8, 0xFF
    ctx->r8 = ctx->r24 & 0XFF;
    // 0x800A0DF8: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800A0DFC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800A0E00: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x800A0E04: andi        $t1, $t5, 0xFFFF
    ctx->r9 = ctx->r13 & 0XFFFF;
    // 0x800A0E08: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800A0E0C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x800A0E10: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x800A0E14: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x800A0E18: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A0E1C: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x800A0E20: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A0E24: and         $t8, $t3, $at
    ctx->r24 = ctx->r11 & ctx->r1;
    // 0x800A0E28: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800A0E2C: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x800A0E30: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
    // 0x800A0E34: blez        $t7, L_800A18D4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A0E38: nop
    
            goto L_800A18D4;
    }
    // 0x800A0E38: nop

L_800A0E3C:
    // 0x800A0E3C: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x800A0E40: nop

    // 0x800A0E44: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A0E48: sw          $t5, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r13;
    // 0x800A0E4C: lw          $t9, 0x168($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X168);
    // 0x800A0E50: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A0E54: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800A0E58: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A0E5C: lw          $t2, 0x7310($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7310);
    // 0x800A0E60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A0E64: sw          $t2, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r10;
    // 0x800A0E68: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x800A0E6C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A0E70: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800A0E74: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x800A0E78: lh          $t8, 0x7328($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7328);
    // 0x800A0E7C: nop

    // 0x800A0E80: sh          $t8, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r24;
    // 0x800A0E84: lw          $t0, 0x168($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X168);
    // 0x800A0E88: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A0E8C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800A0E90: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x800A0E94: lh          $t4, 0x732A($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X732A);
    // 0x800A0E98: nop

    // 0x800A0E9C: sh          $t4, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r12;
    // 0x800A0EA0: lh          $t5, 0x182($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X182);
    // 0x800A0EA4: nop

    // 0x800A0EA8: bgez        $t5, L_800A0EB8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A0EAC: sra         $t9, $t5, 1
        ctx->r25 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800A0EB8;
    }
    // 0x800A0EAC: sra         $t9, $t5, 1
    ctx->r25 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800A0EB0: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800A0EB4: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800A0EB8:
    // 0x800A0EB8: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x800A0EBC: sw          $t1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r9;
    // 0x800A0EC0: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800A0EC4: sw          $t2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r10;
L_800A0EC8:
    // 0x800A0EC8: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x800A0ECC: nop

    // 0x800A0ED0: andi        $t3, $t6, 0x80
    ctx->r11 = ctx->r14 & 0X80;
    // 0x800A0ED4: beq         $t3, $zero, L_800A0EFC
    if (ctx->r11 == 0) {
        // 0x800A0ED8: nop
    
            goto L_800A0EFC;
    }
    // 0x800A0ED8: nop

    // 0x800A0EDC: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800A0EE0: nop

    // 0x800A0EE4: andi        $t0, $t8, 0x7F
    ctx->r8 = ctx->r24 & 0X7F;
    // 0x800A0EE8: beq         $t0, $zero, L_800A0EF4
    if (ctx->r8 == 0) {
        // 0x800A0EEC: nop
    
            goto L_800A0EF4;
    }
    // 0x800A0EEC: nop

    // 0x800A0EF0: sw          $zero, 0x158($sp)
    MEM_W(0X158, ctx->r29) = 0;
L_800A0EF4:
    // 0x800A0EF4: b           L_800A0F20
    // 0x800A0EF8: nop

        goto L_800A0F20;
    // 0x800A0EF8: nop

L_800A0EFC:
    // 0x800A0EFC: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800A0F00: nop

    // 0x800A0F04: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x800A0F08: sw          $t4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r12;
    // 0x800A0F0C: lw          $t5, 0x158($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X158);
    // 0x800A0F10: nop

    // 0x800A0F14: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x800A0F18: bgtz        $t9, L_800A0EC8
    if (SIGNED(ctx->r25) > 0) {
        // 0x800A0F1C: sw          $t9, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r25;
            goto L_800A0EC8;
    }
    // 0x800A0F1C: sw          $t9, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r25;
L_800A0F20:
    // 0x800A0F20: lh          $t1, 0x180($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X180);
    // 0x800A0F24: nop

    // 0x800A0F28: bgez        $t1, L_800A0F38
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800A0F2C: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_800A0F38;
    }
    // 0x800A0F2C: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800A0F30: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x800A0F34: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800A0F38:
    // 0x800A0F38: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x800A0F3C: sw          $t6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r14;
    // 0x800A0F40: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800A0F44: sw          $t3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r11;
L_800A0F48:
    // 0x800A0F48: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800A0F4C: nop

    // 0x800A0F50: andi        $t0, $t8, 0x80
    ctx->r8 = ctx->r24 & 0X80;
    // 0x800A0F54: beq         $t0, $zero, L_800A0F7C
    if (ctx->r8 == 0) {
        // 0x800A0F58: nop
    
            goto L_800A0F7C;
    }
    // 0x800A0F58: nop

    // 0x800A0F5C: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800A0F60: nop

    // 0x800A0F64: andi        $t4, $t7, 0x7F
    ctx->r12 = ctx->r15 & 0X7F;
    // 0x800A0F68: beq         $t4, $zero, L_800A0F74
    if (ctx->r12 == 0) {
        // 0x800A0F6C: nop
    
            goto L_800A0F74;
    }
    // 0x800A0F6C: nop

    // 0x800A0F70: sw          $zero, 0x154($sp)
    MEM_W(0X154, ctx->r29) = 0;
L_800A0F74:
    // 0x800A0F74: b           L_800A0FA0
    // 0x800A0F78: nop

        goto L_800A0FA0;
    // 0x800A0F78: nop

L_800A0F7C:
    // 0x800A0F7C: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800A0F80: nop

    // 0x800A0F84: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x800A0F88: sw          $t9, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r25;
    // 0x800A0F8C: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    // 0x800A0F90: nop

    // 0x800A0F94: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800A0F98: bgtz        $t2, L_800A0F48
    if (SIGNED(ctx->r10) > 0) {
        // 0x800A0F9C: sw          $t2, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r10;
            goto L_800A0F48;
    }
    // 0x800A0F9C: sw          $t2, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r10;
L_800A0FA0:
    // 0x800A0FA0: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x800A0FA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0FA8: lh          $t3, 0x116($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X116);
    // 0x800A0FAC: nop

    // 0x800A0FB0: bne         $t3, $at, L_800A128C
    if (ctx->r11 != ctx->r1) {
        // 0x800A0FB4: nop
    
            goto L_800A128C;
    }
    // 0x800A0FB4: nop

    // 0x800A0FB8: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0FBC: nop

    // 0x800A0FC0: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x800A0FC4: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A0FC8: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x800A0FCC: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x800A0FD0: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x800A0FD4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800A0FD8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A0FDC: lw          $t5, 0x72E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E0);
    // 0x800A0FE0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A0FE4: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x800A0FE8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A0FEC: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x800A0FF0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800A0FF4: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A0FF8: nop

    // 0x800A0FFC: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x800A1000: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A1004: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800A1008: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A100C: lui         $t3, 0xF550
    ctx->r11 = S32(0XF550 << 16);
    // 0x800A1010: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800A1014: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800A1018: lw          $t1, 0x158($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X158);
    // 0x800A101C: andi        $t7, $t0, 0xF
    ctx->r15 = ctx->r8 & 0XF;
    // 0x800A1020: sll         $t4, $t7, 14
    ctx->r12 = S32(ctx->r15 << 14);
    // 0x800A1024: lui         $at, 0x708
    ctx->r1 = S32(0X708 << 16);
    // 0x800A1028: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800A102C: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800A1030: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A1034: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x800A1038: ori         $t9, $t5, 0x200
    ctx->r25 = ctx->r13 | 0X200;
    // 0x800A103C: or          $t3, $t9, $t6
    ctx->r11 = ctx->r25 | ctx->r14;
    // 0x800A1040: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x800A1044: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1048: nop

    // 0x800A104C: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800A1050: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A1054: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x800A1058: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x800A105C: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800A1060: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A1064: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x800A1068: nop

    // 0x800A106C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A1070: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1074: nop

    // 0x800A1078: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800A107C: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A1080: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800A1084: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800A1088: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800A108C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800A1090: lh          $t8, 0x182($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X182);
    // 0x800A1094: lh          $t0, 0x180($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X180);
    // 0x800A1098: nop

    // 0x800A109C: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A10A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800A10A4: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x800A10A8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800A10AC: addiu       $t1, $t5, -0x1
    ctx->r9 = ADD32(ctx->r13, -0X1);
    // 0x800A10B0: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x800A10B4: beq         $at, $zero, L_800A10C4
    if (ctx->r1 == 0) {
        // 0x800A10B8: nop
    
            goto L_800A10C4;
    }
    // 0x800A10B8: nop

    // 0x800A10BC: b           L_800A10C8
    // 0x800A10C0: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
        goto L_800A10C8;
    // 0x800A10C0: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
L_800A10C4:
    // 0x800A10C4: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800A10C8:
    // 0x800A10C8: lh          $t2, 0x182($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X182);
    // 0x800A10CC: nop

    // 0x800A10D0: bgez        $t2, L_800A10E0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A10D4: sra         $t9, $t2, 3
        ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
            goto L_800A10E0;
    }
    // 0x800A10D4: sra         $t9, $t2, 3
    ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800A10D8: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x800A10DC: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800A10E0:
    // 0x800A10E0: bgtz        $t9, L_800A10F0
    if (SIGNED(ctx->r25) > 0) {
        // 0x800A10E4: nop
    
            goto L_800A10F0;
    }
    // 0x800A10E4: nop

    // 0x800A10E8: b           L_800A110C
    // 0x800A10EC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800A110C;
    // 0x800A10EC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800A10F0:
    // 0x800A10F0: lh          $s1, 0x182($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X182);
    // 0x800A10F4: nop

    // 0x800A10F8: bgez        $s1, L_800A1108
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800A10FC: sra         $t6, $s1, 3
        ctx->r14 = S32(SIGNED(ctx->r17) >> 3);
            goto L_800A1108;
    }
    // 0x800A10FC: sra         $t6, $s1, 3
    ctx->r14 = S32(SIGNED(ctx->r17) >> 3);
    // 0x800A1100: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x800A1104: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800A1108:
    // 0x800A1108: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_800A110C:
    // 0x800A110C: lh          $t3, 0x182($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X182);
    // 0x800A1110: nop

    // 0x800A1114: bgez        $t3, L_800A1124
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A1118: sra         $t8, $t3, 3
        ctx->r24 = S32(SIGNED(ctx->r11) >> 3);
            goto L_800A1124;
    }
    // 0x800A1118: sra         $t8, $t3, 3
    ctx->r24 = S32(SIGNED(ctx->r11) >> 3);
    // 0x800A111C: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x800A1120: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800A1124:
    // 0x800A1124: bgtz        $t8, L_800A1134
    if (SIGNED(ctx->r24) > 0) {
        // 0x800A1128: nop
    
            goto L_800A1134;
    }
    // 0x800A1128: nop

    // 0x800A112C: b           L_800A1150
    // 0x800A1130: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800A1150;
    // 0x800A1130: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800A1134:
    // 0x800A1134: lh          $s0, 0x182($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X182);
    // 0x800A1138: nop

    // 0x800A113C: bgez        $s0, L_800A114C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800A1140: sra         $t0, $s0, 3
        ctx->r8 = S32(SIGNED(ctx->r16) >> 3);
            goto L_800A114C;
    }
    // 0x800A1140: sra         $t0, $s0, 3
    ctx->r8 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800A1144: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x800A1148: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_800A114C:
    // 0x800A114C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_800A1150:
    // 0x800A1150: addiu       $t7, $s1, 0x7FF
    ctx->r15 = ADD32(ctx->r17, 0X7FF);
    // 0x800A1154: div         $zero, $t7, $s0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r16)));
    // 0x800A1158: andi        $t1, $s2, 0xFFF
    ctx->r9 = ctx->r18 & 0XFFF;
    // 0x800A115C: bne         $s0, $zero, L_800A1168
    if (ctx->r16 != 0) {
        // 0x800A1160: nop
    
            goto L_800A1168;
    }
    // 0x800A1160: nop

    // 0x800A1164: break       7
    do_break(2148143460);
L_800A1168:
    // 0x800A1168: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A116C: bne         $s0, $at, L_800A1180
    if (ctx->r16 != ctx->r1) {
        // 0x800A1170: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A1180;
    }
    // 0x800A1170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1174: bne         $t7, $at, L_800A1180
    if (ctx->r15 != ctx->r1) {
        // 0x800A1178: nop
    
            goto L_800A1180;
    }
    // 0x800A1178: nop

    // 0x800A117C: break       6
    do_break(2148143484);
L_800A1180:
    // 0x800A1180: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800A1184: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x800A1188: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800A118C: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800A1190: mflo        $t4
    ctx->r12 = lo;
    // 0x800A1194: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800A1198: or          $t6, $t5, $t9
    ctx->r14 = ctx->r13 | ctx->r25;
    // 0x800A119C: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x800A11A0: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A11A4: nop

    // 0x800A11A8: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x800A11AC: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A11B0: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x800A11B4: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800A11B8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800A11BC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800A11C0: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800A11C4: nop

    // 0x800A11C8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A11CC: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A11D0: nop

    // 0x800A11D4: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A11D8: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A11DC: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x800A11E0: lh          $t9, 0x182($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X182);
    // 0x800A11E4: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800A11E8: addiu       $t6, $t9, 0x7
    ctx->r14 = ADD32(ctx->r25, 0X7);
    // 0x800A11EC: sra         $t3, $t6, 3
    ctx->r11 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800A11F0: andi        $t8, $t3, 0x1FF
    ctx->r24 = ctx->r11 & 0X1FF;
    // 0x800A11F4: sll         $t0, $t8, 9
    ctx->r8 = S32(ctx->r24 << 9);
    // 0x800A11F8: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x800A11FC: or          $t7, $t0, $at
    ctx->r15 = ctx->r8 | ctx->r1;
    // 0x800A1200: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800A1204: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    // 0x800A1208: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x800A120C: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800A1210: sll         $t5, $t2, 14
    ctx->r13 = S32(ctx->r10 << 14);
    // 0x800A1214: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800A1218: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x800A121C: andi        $t8, $t3, 0xF
    ctx->r24 = ctx->r11 & 0XF;
    // 0x800A1220: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800A1224: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x800A1228: ori         $t6, $t9, 0x200
    ctx->r14 = ctx->r25 | 0X200;
    // 0x800A122C: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x800A1230: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x800A1234: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1238: nop

    // 0x800A123C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A1240: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A1244: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x800A1248: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x800A124C: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x800A1250: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800A1254: lh          $t3, 0x182($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X182);
    // 0x800A1258: lh          $t4, 0x180($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X180);
    // 0x800A125C: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x800A1260: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800A1264: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x800A1268: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A126C: andi        $t0, $t6, 0xFFF
    ctx->r8 = ctx->r14 & 0XFFF;
    // 0x800A1270: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x800A1274: sll         $t7, $t0, 12
    ctx->r15 = S32(ctx->r8 << 12);
    // 0x800A1278: andi        $t5, $t2, 0xFFF
    ctx->r13 = ctx->r10 & 0XFFF;
    // 0x800A127C: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800A1280: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x800A1284: b           L_800A17D0
    // 0x800A1288: nop

        goto L_800A17D0;
    // 0x800A1288: nop

L_800A128C:
    // 0x800A128C: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x800A1290: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1294: lh          $t6, 0x116($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X116);
    // 0x800A1298: nop

    // 0x800A129C: bne         $t6, $at, L_800A158C
    if (ctx->r14 != ctx->r1) {
        // 0x800A12A0: nop
    
            goto L_800A158C;
    }
    // 0x800A12A0: nop

    // 0x800A12A4: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A12A8: nop

    // 0x800A12AC: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800A12B0: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A12B4: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x800A12B8: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800A12BC: lui         $t1, 0xFD10
    ctx->r9 = S32(0XFD10 << 16);
    // 0x800A12C0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A12C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A12C8: lw          $t7, 0x72E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E0);
    // 0x800A12CC: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A12D0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800A12D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A12D8: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x800A12DC: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x800A12E0: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A12E4: nop

    // 0x800A12E8: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x800A12EC: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A12F0: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800A12F4: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800A12F8: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x800A12FC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800A1300: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800A1304: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800A1308: andi        $t1, $t4, 0xF
    ctx->r9 = ctx->r12 & 0XF;
    // 0x800A130C: sll         $t2, $t1, 14
    ctx->r10 = S32(ctx->r9 << 14);
    // 0x800A1310: lui         $at, 0x708
    ctx->r1 = S32(0X708 << 16);
    // 0x800A1314: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x800A1318: andi        $t3, $t9, 0xF
    ctx->r11 = ctx->r25 & 0XF;
    // 0x800A131C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800A1320: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x800A1324: ori         $t5, $t7, 0x200
    ctx->r13 = ctx->r15 | 0X200;
    // 0x800A1328: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x800A132C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800A1330: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1334: nop

    // 0x800A1338: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x800A133C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A1340: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x800A1344: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A1348: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x800A134C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800A1350: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800A1354: nop

    // 0x800A1358: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A135C: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1360: nop

    // 0x800A1364: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800A1368: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A136C: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x800A1370: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800A1374: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800A1378: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800A137C: lh          $t0, 0x182($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X182);
    // 0x800A1380: lh          $t4, 0x180($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X180);
    // 0x800A1384: nop

    // 0x800A1388: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A138C: mflo        $t1
    ctx->r9 = lo;
    // 0x800A1390: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800A1394: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x800A1398: beq         $at, $zero, L_800A13A8
    if (ctx->r1 == 0) {
        // 0x800A139C: nop
    
            goto L_800A13A8;
    }
    // 0x800A139C: nop

    // 0x800A13A0: b           L_800A13AC
    // 0x800A13A4: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
        goto L_800A13AC;
    // 0x800A13A4: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
L_800A13A8:
    // 0x800A13A8: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800A13AC:
    // 0x800A13AC: lh          $t7, 0x182($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X182);
    // 0x800A13B0: nop

    // 0x800A13B4: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800A13B8: bgez        $t9, L_800A13C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A13BC: sra         $t3, $t9, 3
        ctx->r11 = S32(SIGNED(ctx->r25) >> 3);
            goto L_800A13C8;
    }
    // 0x800A13BC: sra         $t3, $t9, 3
    ctx->r11 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800A13C0: addiu       $at, $t9, 0x7
    ctx->r1 = ADD32(ctx->r25, 0X7);
    // 0x800A13C4: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_800A13C8:
    // 0x800A13C8: bgtz        $t3, L_800A13D8
    if (SIGNED(ctx->r11) > 0) {
        // 0x800A13CC: nop
    
            goto L_800A13D8;
    }
    // 0x800A13CC: nop

    // 0x800A13D0: b           L_800A13FC
    // 0x800A13D4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800A13FC;
    // 0x800A13D4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800A13D8:
    // 0x800A13D8: lh          $s1, 0x182($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X182);
    // 0x800A13DC: nop

    // 0x800A13E0: sll         $t5, $s1, 1
    ctx->r13 = S32(ctx->r17 << 1);
    // 0x800A13E4: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x800A13E8: bgez        $s1, L_800A13F8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800A13EC: sra         $t8, $s1, 3
        ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
            goto L_800A13F8;
    }
    // 0x800A13EC: sra         $t8, $s1, 3
    ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
    // 0x800A13F0: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x800A13F4: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800A13F8:
    // 0x800A13F8: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_800A13FC:
    // 0x800A13FC: lh          $t6, 0x182($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X182);
    // 0x800A1400: nop

    // 0x800A1404: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x800A1408: bgez        $t0, L_800A1418
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A140C: sra         $t4, $t0, 3
        ctx->r12 = S32(SIGNED(ctx->r8) >> 3);
            goto L_800A1418;
    }
    // 0x800A140C: sra         $t4, $t0, 3
    ctx->r12 = S32(SIGNED(ctx->r8) >> 3);
    // 0x800A1410: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x800A1414: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800A1418:
    // 0x800A1418: bgtz        $t4, L_800A1428
    if (SIGNED(ctx->r12) > 0) {
        // 0x800A141C: nop
    
            goto L_800A1428;
    }
    // 0x800A141C: nop

    // 0x800A1420: b           L_800A144C
    // 0x800A1424: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800A144C;
    // 0x800A1424: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800A1428:
    // 0x800A1428: lh          $s0, 0x182($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X182);
    // 0x800A142C: nop

    // 0x800A1430: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x800A1434: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x800A1438: bgez        $s0, L_800A1448
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800A143C: sra         $t2, $s0, 3
        ctx->r10 = S32(SIGNED(ctx->r16) >> 3);
            goto L_800A1448;
    }
    // 0x800A143C: sra         $t2, $s0, 3
    ctx->r10 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800A1440: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x800A1444: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_800A1448:
    // 0x800A1448: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_800A144C:
    // 0x800A144C: addiu       $t7, $s1, 0x7FF
    ctx->r15 = ADD32(ctx->r17, 0X7FF);
    // 0x800A1450: div         $zero, $t7, $s0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r16)));
    // 0x800A1454: andi        $t5, $s2, 0xFFF
    ctx->r13 = ctx->r18 & 0XFFF;
    // 0x800A1458: bne         $s0, $zero, L_800A1464
    if (ctx->r16 != 0) {
        // 0x800A145C: nop
    
            goto L_800A1464;
    }
    // 0x800A145C: nop

    // 0x800A1460: break       7
    do_break(2148144224);
L_800A1464:
    // 0x800A1464: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1468: bne         $s0, $at, L_800A147C
    if (ctx->r16 != ctx->r1) {
        // 0x800A146C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A147C;
    }
    // 0x800A146C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1470: bne         $t7, $at, L_800A147C
    if (ctx->r15 != ctx->r1) {
        // 0x800A1474: nop
    
            goto L_800A147C;
    }
    // 0x800A1474: nop

    // 0x800A1478: break       6
    do_break(2148144248);
L_800A147C:
    // 0x800A147C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800A1480: sll         $t8, $t5, 12
    ctx->r24 = S32(ctx->r13 << 12);
    // 0x800A1484: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800A1488: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800A148C: mflo        $t9
    ctx->r25 = lo;
    // 0x800A1490: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x800A1494: or          $t0, $t3, $t6
    ctx->r8 = ctx->r11 | ctx->r14;
    // 0x800A1498: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x800A149C: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A14A0: nop

    // 0x800A14A4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A14A8: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A14AC: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x800A14B0: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800A14B4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800A14B8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800A14BC: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800A14C0: nop

    // 0x800A14C4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A14C8: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A14CC: nop

    // 0x800A14D0: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x800A14D4: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A14D8: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x800A14DC: lh          $t6, 0x182($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X182);
    // 0x800A14E0: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800A14E4: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x800A14E8: addiu       $t4, $t0, 0x7
    ctx->r12 = ADD32(ctx->r8, 0X7);
    // 0x800A14EC: sra         $t1, $t4, 3
    ctx->r9 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800A14F0: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x800A14F4: sll         $t7, $t2, 9
    ctx->r15 = S32(ctx->r10 << 9);
    // 0x800A14F8: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800A14FC: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800A1500: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A1504: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x800A1508: lw          $t1, 0x158($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X158);
    // 0x800A150C: andi        $t3, $t8, 0xF
    ctx->r11 = ctx->r24 & 0XF;
    // 0x800A1510: sll         $t6, $t3, 14
    ctx->r14 = S32(ctx->r11 << 14);
    // 0x800A1514: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800A1518: or          $t0, $t6, $at
    ctx->r8 = ctx->r14 | ctx->r1;
    // 0x800A151C: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800A1520: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800A1524: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x800A1528: ori         $t4, $t0, 0x200
    ctx->r12 = ctx->r8 | 0X200;
    // 0x800A152C: or          $t9, $t4, $t7
    ctx->r25 = ctx->r12 | ctx->r15;
    // 0x800A1530: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800A1534: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1538: nop

    // 0x800A153C: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x800A1540: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A1544: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800A1548: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800A154C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800A1550: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800A1554: lh          $t1, 0x182($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X182);
    // 0x800A1558: lh          $t5, 0x180($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X180);
    // 0x800A155C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800A1560: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800A1564: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x800A1568: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x800A156C: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800A1570: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800A1574: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800A1578: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x800A157C: or          $t0, $t9, $t6
    ctx->r8 = ctx->r25 | ctx->r14;
    // 0x800A1580: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A1584: b           L_800A17D0
    // 0x800A1588: nop

        goto L_800A17D0;
    // 0x800A1588: nop

L_800A158C:
    // 0x800A158C: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1590: nop

    // 0x800A1594: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800A1598: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A159C: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x800A15A0: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800A15A4: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x800A15A8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800A15AC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A15B0: lw          $t8, 0x72E0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72E0);
    // 0x800A15B4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A15B8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800A15BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A15C0: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x800A15C4: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x800A15C8: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A15CC: nop

    // 0x800A15D0: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x800A15D4: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A15D8: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800A15DC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800A15E0: lui         $t1, 0xF550
    ctx->r9 = S32(0XF550 << 16);
    // 0x800A15E4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A15E8: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800A15EC: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800A15F0: andi        $t7, $t4, 0xF
    ctx->r15 = ctx->r12 & 0XF;
    // 0x800A15F4: sll         $t5, $t7, 14
    ctx->r13 = S32(ctx->r15 << 14);
    // 0x800A15F8: lui         $at, 0x708
    ctx->r1 = S32(0X708 << 16);
    // 0x800A15FC: or          $t8, $t5, $at
    ctx->r24 = ctx->r13 | ctx->r1;
    // 0x800A1600: andi        $t6, $t9, 0xF
    ctx->r14 = ctx->r25 & 0XF;
    // 0x800A1604: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800A1608: sll         $t0, $t6, 4
    ctx->r8 = S32(ctx->r14 << 4);
    // 0x800A160C: ori         $t3, $t8, 0x200
    ctx->r11 = ctx->r24 | 0X200;
    // 0x800A1610: or          $t1, $t3, $t0
    ctx->r9 = ctx->r11 | ctx->r8;
    // 0x800A1614: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A1618: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A161C: nop

    // 0x800A1620: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x800A1624: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A1628: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800A162C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800A1630: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800A1634: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800A1638: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A163C: nop

    // 0x800A1640: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A1644: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1648: nop

    // 0x800A164C: addiu       $t3, $t6, 0x8
    ctx->r11 = ADD32(ctx->r14, 0X8);
    // 0x800A1650: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A1654: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x800A1658: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A165C: lui         $t0, 0xF300
    ctx->r8 = S32(0XF300 << 16);
    // 0x800A1660: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A1664: lh          $t2, 0x182($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X182);
    // 0x800A1668: lh          $t4, 0x180($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X180);
    // 0x800A166C: nop

    // 0x800A1670: multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A1674: mflo        $t7
    ctx->r15 = lo;
    // 0x800A1678: addiu       $t5, $t7, 0x3
    ctx->r13 = ADD32(ctx->r15, 0X3);
    // 0x800A167C: sra         $t8, $t5, 2
    ctx->r24 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800A1680: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800A1684: slti        $at, $t9, 0x7FF
    ctx->r1 = SIGNED(ctx->r25) < 0X7FF ? 1 : 0;
    // 0x800A1688: beq         $at, $zero, L_800A1698
    if (ctx->r1 == 0) {
        // 0x800A168C: nop
    
            goto L_800A1698;
    }
    // 0x800A168C: nop

    // 0x800A1690: b           L_800A169C
    // 0x800A1694: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
        goto L_800A169C;
    // 0x800A1694: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_800A1698:
    // 0x800A1698: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800A169C:
    // 0x800A169C: b           L_800A16A8
    // 0x800A16A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800A16A8;
    // 0x800A16A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800A16A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800A16A8:
    // 0x800A16A8: b           L_800A16B4
    // 0x800A16AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800A16B4;
    // 0x800A16AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800A16B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800A16B4:
    // 0x800A16B4: addiu       $t6, $s1, 0x7FF
    ctx->r14 = ADD32(ctx->r17, 0X7FF);
    // 0x800A16B8: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x800A16BC: andi        $t1, $s2, 0xFFF
    ctx->r9 = ctx->r18 & 0XFFF;
    // 0x800A16C0: bne         $s0, $zero, L_800A16CC
    if (ctx->r16 != 0) {
        // 0x800A16C4: nop
    
            goto L_800A16CC;
    }
    // 0x800A16C4: nop

    // 0x800A16C8: break       7
    do_break(2148144840);
L_800A16CC:
    // 0x800A16CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A16D0: bne         $s0, $at, L_800A16E4
    if (ctx->r16 != ctx->r1) {
        // 0x800A16D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A16E4;
    }
    // 0x800A16D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A16D8: bne         $t6, $at, L_800A16E4
    if (ctx->r14 != ctx->r1) {
        // 0x800A16DC: nop
    
            goto L_800A16E4;
    }
    // 0x800A16DC: nop

    // 0x800A16E0: break       6
    do_break(2148144864);
L_800A16E4:
    // 0x800A16E4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800A16E8: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x800A16EC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800A16F0: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x800A16F4: mflo        $t3
    ctx->r11 = lo;
    // 0x800A16F8: andi        $t0, $t3, 0xFFF
    ctx->r8 = ctx->r11 & 0XFFF;
    // 0x800A16FC: or          $t7, $t0, $t4
    ctx->r15 = ctx->r8 | ctx->r12;
    // 0x800A1700: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800A1704: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1708: nop

    // 0x800A170C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A1710: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A1714: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x800A1718: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800A171C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800A1720: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800A1724: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800A1728: nop

    // 0x800A172C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A1730: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1734: nop

    // 0x800A1738: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A173C: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A1740: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800A1744: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1748: lui         $t4, 0xF540
    ctx->r12 = S32(0XF540 << 16);
    // 0x800A174C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x800A1750: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x800A1754: lw          $t1, 0x158($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X158);
    // 0x800A1758: andi        $t8, $t5, 0xF
    ctx->r24 = ctx->r13 & 0XF;
    // 0x800A175C: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x800A1760: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800A1764: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800A1768: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800A176C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1770: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x800A1774: ori         $t3, $t6, 0x200
    ctx->r11 = ctx->r14 | 0X200;
    // 0x800A1778: or          $t4, $t3, $t0
    ctx->r12 = ctx->r11 | ctx->r8;
    // 0x800A177C: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x800A1780: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1784: nop

    // 0x800A1788: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x800A178C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A1790: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800A1794: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A1798: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800A179C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800A17A0: lh          $t1, 0x182($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X182);
    // 0x800A17A4: lh          $t7, 0x180($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X180);
    // 0x800A17A8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800A17AC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A17B0: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800A17B4: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800A17B8: andi        $t0, $t3, 0xFFF
    ctx->r8 = ctx->r11 & 0XFFF;
    // 0x800A17BC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A17C0: sll         $t4, $t0, 12
    ctx->r12 = S32(ctx->r8 << 12);
    // 0x800A17C4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800A17C8: or          $t6, $t4, $t9
    ctx->r14 = ctx->r12 | ctx->r25;
    // 0x800A17CC: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
L_800A17D0:
    // 0x800A17D0: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A17D4: nop

    // 0x800A17D8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A17DC: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A17E0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800A17E4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800A17E8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800A17EC: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x800A17F0: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800A17F4: nop

    // 0x800A17F8: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A17FC: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1800: nop

    // 0x800A1804: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800A1808: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A180C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800A1810: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A1814: lui         $t9, 0xBF00
    ctx->r25 = S32(0XBF00 << 16);
    // 0x800A1818: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800A181C: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x800A1820: nop

    // 0x800A1824: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A1828: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A182C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800A1830: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800A1834: addiu       $t7, $t2, 0x1E
    ctx->r15 = ADD32(ctx->r10, 0X1E);
    // 0x800A1838: andi        $t5, $t7, 0xFF
    ctx->r13 = ctx->r15 & 0XFF;
    // 0x800A183C: sll         $t0, $t3, 16
    ctx->r8 = S32(ctx->r11 << 16);
    // 0x800A1840: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x800A1844: addiu       $t9, $t2, 0xA
    ctx->r25 = ADD32(ctx->r10, 0XA);
    // 0x800A1848: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800A184C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800A1850: or          $t4, $t0, $t8
    ctx->r12 = ctx->r8 | ctx->r24;
    // 0x800A1854: or          $t1, $t4, $t6
    ctx->r9 = ctx->r12 | ctx->r14;
    // 0x800A1858: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800A185C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1860: nop

    // 0x800A1864: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800A1868: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A186C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800A1870: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800A1874: lui         $t0, 0xBF00
    ctx->r8 = S32(0XBF00 << 16);
    // 0x800A1878: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800A187C: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x800A1880: nop

    // 0x800A1884: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800A1888: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x800A188C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800A1890: andi        $t4, $t9, 0xFF
    ctx->r12 = ctx->r25 & 0XFF;
    // 0x800A1894: addiu       $t1, $t9, 0x14
    ctx->r9 = ADD32(ctx->r25, 0X14);
    // 0x800A1898: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x800A189C: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800A18A0: sll         $t7, $t3, 8
    ctx->r15 = S32(ctx->r11 << 8);
    // 0x800A18A4: addiu       $t0, $t9, 0x1E
    ctx->r8 = ADD32(ctx->r25, 0X1E);
    // 0x800A18A8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A18AC: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x800A18B0: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x800A18B4: or          $t2, $t5, $t8
    ctx->r10 = ctx->r13 | ctx->r24;
    // 0x800A18B8: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800A18BC: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x800A18C0: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x800A18C4: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800A18C8: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A18CC: bne         $at, $zero, L_800A0E3C
    if (ctx->r1 != 0) {
        // 0x800A18D0: sw          $t3, 0x168($sp)
        MEM_W(0X168, ctx->r29) = ctx->r11;
            goto L_800A0E3C;
    }
    // 0x800A18D0: sw          $t3, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r11;
L_800A18D4:
    // 0x800A18D4: lh          $t7, 0x186($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X186);
    // 0x800A18D8: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800A18DC: bne         $t7, $at, L_800A18EC
    if (ctx->r15 != ctx->r1) {
        // 0x800A18E0: nop
    
            goto L_800A18EC;
    }
    // 0x800A18E0: nop

    // 0x800A18E4: b           L_800A18F4
    // 0x800A18E8: nop

        goto L_800A18F4;
    // 0x800A18E8: nop

L_800A18EC:
    // 0x800A18EC: b           L_800A0800
    // 0x800A18F0: nop

        goto L_800A0800;
    // 0x800A18F0: nop

L_800A18F4:
    // 0x800A18F4: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A18F8: nop

    // 0x800A18FC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A1900: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A1904: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800A1908: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800A190C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800A1910: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800A1914: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1918: nop

    // 0x800A191C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A1920: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1924: nop

    // 0x800A1928: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x800A192C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A1930: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800A1934: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800A1938: lui         $t3, 0xBD00
    ctx->r11 = S32(0XBD00 << 16);
    // 0x800A193C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800A1940: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A1944: nop

    // 0x800A1948: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A194C: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1950: nop

    // 0x800A1954: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A1958: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A195C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800A1960: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800A1964: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800A1968: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800A196C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800A1970: nop

    // 0x800A1974: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A1978: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A197C: lw          $t1, 0x190($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X190);
    // 0x800A1980: nop

    // 0x800A1984: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A1988: b           L_800A1998
    // 0x800A198C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A1998;
    // 0x800A198C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A1990: b           L_800A1998
    // 0x800A1994: nop

        goto L_800A1998;
    // 0x800A1994: nop

L_800A1998:
    // 0x800A1998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A199C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A19A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A19A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A19A8: jr          $ra
    // 0x800A19AC: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x800A19AC: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void func_80071764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007176C: jal         0x80061348
    // 0x80071770: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071770: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071774: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071778: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007177C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071780: beq         $v0, $zero, L_800717D4
    if (ctx->r2 == 0) {
        // 0x80071784: nop
    
            goto L_800717D4;
    }
    // 0x80071784: nop

    // 0x80071788: jal         0x80061348
    // 0x8007178C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007178C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071790: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071794: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007179C: beq         $v0, $zero, L_800717D4
    if (ctx->r2 == 0) {
        // 0x800717A0: nop
    
            goto L_800717D4;
    }
    // 0x800717A0: nop

    // 0x800717A4: jal         0x80061348
    // 0x800717A8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800717A8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x800717AC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800717B0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800717B4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800717B8: beq         $v0, $zero, L_800717D4
    if (ctx->r2 == 0) {
        // 0x800717BC: nop
    
            goto L_800717D4;
    }
    // 0x800717BC: nop

    // 0x800717C0: jal         0x80061348
    // 0x800717C4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800717C4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x800717C8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800717CC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800717D0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800717D4:
    // 0x800717D4: b           L_800717E4
    // 0x800717D8: nop

        goto L_800717E4;
    // 0x800717D8: nop

    // 0x800717DC: b           L_800717E4
    // 0x800717E0: nop

        goto L_800717E4;
    // 0x800717E0: nop

L_800717E4:
    // 0x800717E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800717E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800717EC: jr          $ra
    // 0x800717F0: nop

    return;
    // 0x800717F0: nop

;}
RECOMP_FUNC void func_80076100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076108: jal         0x80061348
    // 0x8007610C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007610C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80076110: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076114: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076118: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007611C: beq         $v0, $zero, L_80076170
    if (ctx->r2 == 0) {
        // 0x80076120: nop
    
            goto L_80076170;
    }
    // 0x80076120: nop

    // 0x80076124: jal         0x80061348
    // 0x80076128: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076128: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x8007612C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80076130: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076134: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076138: beq         $v0, $zero, L_80076170
    if (ctx->r2 == 0) {
        // 0x8007613C: nop
    
            goto L_80076170;
    }
    // 0x8007613C: nop

    // 0x80076140: jal         0x80061348
    // 0x80076144: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076144: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80076148: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007614C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80076150: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80076154: beq         $v0, $zero, L_80076170
    if (ctx->r2 == 0) {
        // 0x80076158: nop
    
            goto L_80076170;
    }
    // 0x80076158: nop

    // 0x8007615C: jal         0x80061348
    // 0x80076160: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80076160: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80076164: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80076168: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007616C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076170:
    // 0x80076170: b           L_80076180
    // 0x80076174: nop

        goto L_80076180;
    // 0x80076174: nop

    // 0x80076178: b           L_80076180
    // 0x8007617C: nop

        goto L_80076180;
    // 0x8007617C: nop

L_80076180:
    // 0x80076180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076188: jr          $ra
    // 0x8007618C: nop

    return;
    // 0x8007618C: nop

;}
RECOMP_FUNC void func_800758E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800758E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800758E4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800758E8: nop

    // 0x800758EC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800758F0: nop

    // 0x800758F4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800758F8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800758FC: jr          $ra
    // 0x80075900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075904: jr          $ra
    // 0x80075908: nop

    return;
    // 0x80075908: nop

    // 0x8007590C: jr          $ra
    // 0x80075910: nop

    return;
    // 0x80075910: nop

;}
RECOMP_FUNC void alSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D643C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D6440: jal         0x800D63E8
    // 0x800D6444: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    static_5_800D63E8(rdram, ctx);
        goto after_0;
    // 0x800D6444: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_0:
    // 0x800D6448: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x800D644C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D6450: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800D6454: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800D6458: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x800D645C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6460: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D6464: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D6468: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D646C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D6470: bne         $a0, $at, L_800D6530
    if (ctx->r4 != ctx->r1) {
        // 0x800D6474: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_800D6530;
    }
    // 0x800D6474: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800D6478: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800D647C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D6480: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800D6484: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x800D6488: bne         $v0, $at, L_800D64F8
    if (ctx->r2 != ctx->r1) {
        // 0x800D648C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800D64F8;
    }
    // 0x800D648C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800D6490: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D6494: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x800D6498: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D649C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D64A0: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x800D64A4: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64A8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64AC: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800D64B0: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800D64B4: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x800D64B8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64BC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64C0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D64C4: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D64C8: sb          $a0, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r4;
    // 0x800D64CC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64D0: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64D4: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800D64D8: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x800D64DC: sb          $a1, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r5;
    // 0x800D64E0: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D64E4: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D64E8: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D64EC: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x800D64F0: b           L_800D6528
    // 0x800D64F4: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
        goto L_800D6528;
    // 0x800D64F4: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
L_800D64F8:
    // 0x800D64F8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800D64FC: bne         $v0, $at, L_800D6528
    if (ctx->r2 != ctx->r1) {
        // 0x800D6500: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_800D6528;
    }
    // 0x800D6500: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800D6504: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x800D6508: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D650C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D6510: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x800D6514: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D6518: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D651C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D6520: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D6524: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_800D6528:
    // 0x800D6528: b           L_800D65A8
    // 0x800D652C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
        goto L_800D65A8;
    // 0x800D652C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
L_800D6530:
    // 0x800D6530: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6534: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800D6538: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x800D653C: beq         $t6, $zero, L_800D6564
    if (ctx->r14 == 0) {
        // 0x800D6540: sw          $t1, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r9;
            goto L_800D6564;
    }
    // 0x800D6540: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D6544: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D6548: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D654C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6550: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800D6554: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800D6558: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800D655C: b           L_800D6570
    // 0x800D6560: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
        goto L_800D6570;
    // 0x800D6560: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
L_800D6564:
    // 0x800D6564: lh          $t8, 0x1A($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1A);
    // 0x800D6568: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800D656C: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
L_800D6570:
    // 0x800D6570: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x800D6574: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800D6578: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800D657C: beq         $t9, $at, L_800D65A4
    if (ctx->r25 == ctx->r1) {
        // 0x800D6580: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800D65A4;
    }
    // 0x800D6580: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800D6584: beql        $t9, $at, L_800D65A8
    if (ctx->r25 == ctx->r1) {
        // 0x800D6588: sb          $zero, 0xA($a3)
        MEM_B(0XA, ctx->r7) = 0;
            goto L_800D65A8;
    }
    goto skip_0;
    // 0x800D6588: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
    skip_0:
    // 0x800D658C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800D6590: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D6594: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D6598: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x800D659C: b           L_800D65A8
    // 0x800D65A0: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
        goto L_800D65A8;
    // 0x800D65A0: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_800D65A4:
    // 0x800D65A4: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
L_800D65A8:
    // 0x800D65A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D65AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D65B0: jr          $ra
    // 0x800D65B4: nop

    return;
    // 0x800D65B4: nop

;}
RECOMP_FUNC void func_800BADA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BADA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BADAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BADB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BADB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BADB8:
    // 0x800BADB8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BADBC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BADC0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BADC4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BADC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BADCC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800BADD0: lw          $t8, -0x1A64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1A64);
    // 0x800BADD4: nop

    // 0x800BADD8: bne         $t8, $zero, L_800BADE8
    if (ctx->r24 != 0) {
        // 0x800BADDC: nop
    
            goto L_800BADE8;
    }
    // 0x800BADDC: nop

    // 0x800BADE0: b           L_800BAE00
    // 0x800BADE4: nop

        goto L_800BAE00;
    // 0x800BADE4: nop

L_800BADE8:
    // 0x800BADE8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BADEC: nop

    // 0x800BADF0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BADF4: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800BADF8: bne         $at, $zero, L_800BADB8
    if (ctx->r1 != 0) {
        // 0x800BADFC: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800BADB8;
    }
    // 0x800BADFC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800BAE00:
    // 0x800BAE00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE04: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BAE08: bne         $t1, $at, L_800BAE18
    if (ctx->r9 != ctx->r1) {
        // 0x800BAE0C: nop
    
            goto L_800BAE18;
    }
    // 0x800BAE0C: nop

    // 0x800BAE10: b           L_800BB15C
    // 0x800BAE14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BB15C;
    // 0x800BAE14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BAE18:
    // 0x800BAE18: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAE20: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800BAE24: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800BAE28: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BAE2C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800BAE30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800BAE34: sw          $t2, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = ctx->r10;
    // 0x800BAE38: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE3C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BAE40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BAE44: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BAE48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BAE4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800BAE50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BAE54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAE58: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BAE5C: sw          $t5, -0x1980($at)
    MEM_W(-0X1980, ctx->r1) = ctx->r13;
    // 0x800BAE60: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE64: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAE68: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BAE6C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800BAE70: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAE74: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800BAE78: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAE7C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800BAE80: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800BAE84: sh          $t8, -0x1970($at)
    MEM_H(-0X1970, ctx->r1) = ctx->r24;
    // 0x800BAE88: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE8C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800BAE90: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800BAE94: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800BAE98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAE9C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800BAEA0: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x800BAEA4: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x800BAEA8: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800BAEAC: lw          $t2, -0x5EBC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5EBC);
    // 0x800BAEB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAEB4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAEB8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BAEBC: sw          $t2, -0x197C($at)
    MEM_W(-0X197C, ctx->r1) = ctx->r10;
    // 0x800BAEC0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAEC4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BAEC8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800BAECC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800BAED0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAED4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800BAED8: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800BAEDC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800BAEE0: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800BAEE4: lbu         $t9, -0x5EB8($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X5EB8);
    // 0x800BAEE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAEEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAEF0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800BAEF4: sb          $t9, -0x1956($at)
    MEM_B(-0X1956, ctx->r1) = ctx->r25;
    // 0x800BAEF8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAEFC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BAF00: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800BAF04: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800BAF08: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BAF0C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800BAF10: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BAF14: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x800BAF18: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x800BAF1C: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x800BAF20: nop

    // 0x800BAF24: sw          $t6, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r14;
    // 0x800BAF28: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAF2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAF30: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BAF34: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BAF38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BAF3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800BAF40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BAF44: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BAF48: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800BAF4C: sw          $t5, -0x1984($at)
    MEM_W(-0X1984, ctx->r1) = ctx->r13;
    // 0x800BAF50: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAF54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAF58: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BAF5C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BAF60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BAF64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BAF68: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BAF6C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800BAF70: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800BAF74: sh          $t9, -0x195C($at)
    MEM_H(-0X195C, ctx->r1) = ctx->r25;
    // 0x800BAF78: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAF7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAF80: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800BAF84: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800BAF88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAF8C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800BAF90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAF94: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BAF98: addiu       $t3, $zero, 0x2710
    ctx->r11 = ADD32(0, 0X2710);
    // 0x800BAF9C: sw          $t3, -0x1964($at)
    MEM_W(-0X1964, ctx->r1) = ctx->r11;
    // 0x800BAFA0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAFA4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAFA8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800BAFAC: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x800BAFB0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BAFB4: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800BAFB8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BAFBC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800BAFC0: addiu       $t2, $zero, 0x2710
    ctx->r10 = ADD32(0, 0X2710);
    // 0x800BAFC4: sw          $t2, -0x1960($at)
    MEM_W(-0X1960, ctx->r1) = ctx->r10;
    // 0x800BAFC8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAFCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAFD0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800BAFD4: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x800BAFD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BAFDC: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x800BAFE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BAFE4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BAFE8: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800BAFEC: sb          $t8, -0x1957($at)
    MEM_B(-0X1957, ctx->r1) = ctx->r24;
    // 0x800BAFF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAFF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAFF8: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800BAFFC: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800BB000: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB004: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x800BB008: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB00C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800BB010: sb          $zero, -0x1958($at)
    MEM_B(-0X1958, ctx->r1) = 0;
    // 0x800BB014: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB018: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB01C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BB020: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BB024: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BB028: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BB02C: addiu       $t3, $zero, 0x2710
    ctx->r11 = ADD32(0, 0X2710);
    // 0x800BB030: sw          $t3, -0x1A60($at)
    MEM_W(-0X1A60, ctx->r1) = ctx->r11;
    // 0x800BB034: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB038: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB03C: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x800BB040: subu        $t0, $t0, $t5
    ctx->r8 = SUB32(ctx->r8, ctx->r13);
    // 0x800BB044: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BB048: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800BB04C: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800BB050: sb          $t2, -0x1A4E($at)
    MEM_B(-0X1A4E, ctx->r1) = ctx->r10;
    // 0x800BB054: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB058: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB05C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BB060: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800BB064: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BB068: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BB06C: sb          $zero, -0x1A4D($at)
    MEM_B(-0X1A4D, ctx->r1) = 0;
    // 0x800BB070: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB074: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB078: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x800BB07C: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800BB080: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB084: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BB088: addiu       $t1, $zero, 0x7FFF
    ctx->r9 = ADD32(0, 0X7FFF);
    // 0x800BB08C: sw          $t1, -0x1A5C($at)
    MEM_W(-0X1A5C, ctx->r1) = ctx->r9;
    // 0x800BB090: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB094: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB098: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x800BB09C: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x800BB0A0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB0A4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800BB0A8: addiu       $t3, $zero, 0x7FFF
    ctx->r11 = ADD32(0, 0X7FFF);
    // 0x800BB0AC: sh          $t3, -0x1A50($at)
    MEM_H(-0X1A50, ctx->r1) = ctx->r11;
    // 0x800BB0B0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB0B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB0B8: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x800BB0BC: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800BB0C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BB0C4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BB0C8: addiu       $t2, $zero, 0x7FFF
    ctx->r10 = ADD32(0, 0X7FFF);
    // 0x800BB0CC: sw          $t2, -0x1A58($at)
    MEM_W(-0X1A58, ctx->r1) = ctx->r10;
    // 0x800BB0D0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB0D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB0D8: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x800BB0DC: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x800BB0E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB0E4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800BB0E8: sw          $zero, -0x1A54($at)
    MEM_W(-0X1A54, ctx->r1) = 0;
    // 0x800BB0EC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB0F0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800BB0F4: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x800BB0F8: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x800BB0FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB100: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x800BB104: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB108: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB10C: lbu         $t7, -0x1956($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1956);
    // 0x800BB110: nop

    // 0x800BB114: beq         $t7, $zero, L_800BB148
    if (ctx->r15 == 0) {
        // 0x800BB118: nop
    
            goto L_800BB148;
    }
    // 0x800BB118: nop

    // 0x800BB11C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB120: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BB124: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800BB128: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x800BB12C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB130: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800BB134: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB138: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800BB13C: lbu         $a0, -0x1956($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1956);
    // 0x800BB140: jal         0x800BB16C
    // 0x800BB144: nop

    func_800BB16C(rdram, ctx);
        goto after_0;
    // 0x800BB144: nop

    after_0:
L_800BB148:
    // 0x800BB148: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB14C: b           L_800BB15C
    // 0x800BB150: nop

        goto L_800BB15C;
    // 0x800BB150: nop

    // 0x800BB154: b           L_800BB15C
    // 0x800BB158: nop

        goto L_800BB15C;
    // 0x800BB158: nop

L_800BB15C:
    // 0x800BB15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BB164: jr          $ra
    // 0x800BB168: nop

    return;
    // 0x800BB168: nop

;}
RECOMP_FUNC void func_800108B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800108B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800108BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800108C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800108C4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800108C8: nop

    // 0x800108CC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800108D0: nop

    // 0x800108D4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800108D8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800108DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800108E0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800108E4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800108E8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800108EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800108F0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800108F4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800108F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800108FC: nop

    // 0x80010900: lwc1        $f16, 0x80($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X80);
    // 0x80010904: nop

    // 0x80010908: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001090C: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80010910: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80010914: swc1        $f6, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->f6.u32l;
    // 0x80010918: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001091C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80010920: lwc1        $f8, 0x80($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X80);
    // 0x80010924: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010928: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001092C: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x80010930: nop

    // 0x80010934: bc1f        L_800109E0
    if (!c1cs) {
        // 0x80010938: nop
    
            goto L_800109E0;
    }
    // 0x80010938: nop

L_8001093C:
    // 0x8001093C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80010940: nop

    // 0x80010944: lhu         $t1, 0x8E($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8E);
    // 0x80010948: nop

    // 0x8001094C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80010950: sh          $t2, 0x8E($t0)
    MEM_H(0X8E, ctx->r8) = ctx->r10;
    // 0x80010954: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80010958: nop

    // 0x8001095C: lhu         $t4, 0x8E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8E);
    // 0x80010960: lhu         $t5, 0x8C($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X8C);
    // 0x80010964: nop

    // 0x80010968: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001096C: bne         $at, $zero, L_80010980
    if (ctx->r1 != 0) {
        // 0x80010970: nop
    
            goto L_80010980;
    }
    // 0x80010970: nop

    // 0x80010974: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80010978: nop

    // 0x8001097C: sh          $zero, 0x8E($t6)
    MEM_H(0X8E, ctx->r14) = 0;
L_80010980:
    // 0x80010980: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80010984: nop

    // 0x80010988: lhu         $t8, 0x84($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X84);
    // 0x8001098C: lwc1        $f10, 0x80($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X80);
    // 0x80010990: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80010994: bgez        $t8, L_800109AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80010998: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800109AC;
    }
    // 0x80010998: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001099C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800109A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800109A4: nop

    // 0x800109A8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800109AC:
    // 0x800109AC: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800109B0: swc1        $f16, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->f16.u32l;
    // 0x800109B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800109B8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800109BC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800109C0: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800109C4: lwc1        $f18, 0x80($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X80);
    // 0x800109C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800109CC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800109D0: c.le.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d <= ctx->f8.d;
    // 0x800109D4: nop

    // 0x800109D8: bc1t        L_8001093C
    if (c1cs) {
        // 0x800109DC: nop
    
            goto L_8001093C;
    }
    // 0x800109DC: nop

L_800109E0:
    // 0x800109E0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800109E4: nop

    // 0x800109E8: beq         $t2, $zero, L_80010AB0
    if (ctx->r10 == 0) {
        // 0x800109EC: nop
    
            goto L_80010AB0;
    }
    // 0x800109EC: nop

    // 0x800109F0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800109F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800109F8: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800109FC: nop

    // 0x80010A00: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80010A04: lhu         $t4, 0x6($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X6);
    // 0x80010A08: nop

    // 0x80010A0C: blez        $t4, L_80010AB0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010A10: nop
    
            goto L_80010AB0;
    }
    // 0x80010A10: nop

L_80010A14:
    // 0x80010A14: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80010A18: nop

    // 0x80010A1C: lw          $t6, 0x138($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X138);
    // 0x80010A20: nop

    // 0x80010A24: bne         $t6, $zero, L_80010A34
    if (ctx->r14 != 0) {
        // 0x80010A28: nop
    
            goto L_80010A34;
    }
    // 0x80010A28: nop

    // 0x80010A2C: b           L_80010A80
    // 0x80010A30: nop

        goto L_80010A80;
    // 0x80010A30: nop

L_80010A34:
    // 0x80010A34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80010A38: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80010A3C: lh          $t5, 0x90($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X90);
    // 0x80010A40: lhu         $t6, 0x8E($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X8E);
    // 0x80010A44: lhu         $t1, 0x86($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X86);
    // 0x80010A48: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010A4C: lw          $t7, 0x138($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X138);
    // 0x80010A50: lhu         $t3, 0x88($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X88);
    // 0x80010A54: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80010A58: lhu         $a2, 0x8A($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X8A);
    // 0x80010A5C: addu        $a0, $t7, $t2
    ctx->r4 = ADD32(ctx->r15, ctx->r10);
    // 0x80010A60: sll         $t0, $t3, 1
    ctx->r8 = S32(ctx->r11 << 1);
    // 0x80010A64: addu        $t4, $t7, $t0
    ctx->r12 = ADD32(ctx->r15, ctx->r8);
    // 0x80010A68: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80010A6C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80010A70: mflo        $t8
    ctx->r24 = lo;
    // 0x80010A74: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x80010A78: jal         0x800BCFCC
    // 0x80010A7C: addu        $a1, $t4, $t1
    ctx->r5 = ADD32(ctx->r12, ctx->r9);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x80010A7C: addu        $a1, $t4, $t1
    ctx->r5 = ADD32(ctx->r12, ctx->r9);
    after_0:
L_80010A80:
    // 0x80010A80: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80010A84: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80010A88: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80010A8C: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x80010A90: addiu       $t5, $t0, 0x160
    ctx->r13 = ADD32(ctx->r8, 0X160);
    // 0x80010A94: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80010A98: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80010A9C: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80010AA0: nop

    // 0x80010AA4: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80010AA8: bne         $at, $zero, L_80010A14
    if (ctx->r1 != 0) {
        // 0x80010AAC: nop
    
            goto L_80010A14;
    }
    // 0x80010AAC: nop

L_80010AB0:
    // 0x80010AB0: b           L_80010AB8
    // 0x80010AB4: nop

        goto L_80010AB8;
    // 0x80010AB4: nop

L_80010AB8:
    // 0x80010AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010ABC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80010AC0: jr          $ra
    // 0x80010AC4: nop

    return;
    // 0x80010AC4: nop

;}
RECOMP_FUNC void func_80033CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033CF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80033CF4: lwc1        $f7, -0x1690($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1690);
    // 0x80033CF8: lwc1        $f6, -0x168C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X168C);
    // 0x80033CFC: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80033D00: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x80033D04: nop

    // 0x80033D08: bc1f        L_80033D2C
    if (!c1cs) {
        // 0x80033D0C: nop
    
            goto L_80033D2C;
    }
    // 0x80033D0C: nop

    // 0x80033D10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80033D14: lwc1        $f11, -0x1688($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1688);
    // 0x80033D18: lwc1        $f10, -0x1684($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1684);
    // 0x80033D1C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80033D20: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x80033D24: b           L_80033D60
    // 0x80033D28: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
        goto L_80033D60;
    // 0x80033D28: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
L_80033D2C:
    // 0x80033D2C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80033D30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80033D34: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80033D38: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80033D3C: nop

    // 0x80033D40: bc1f        L_80033D60
    if (!c1cs) {
        // 0x80033D44: nop
    
            goto L_80033D60;
    }
    // 0x80033D44: nop

    // 0x80033D48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80033D4C: lwc1        $f9, -0x1680($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1680);
    // 0x80033D50: lwc1        $f8, -0x167C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X167C);
    // 0x80033D54: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80033D58: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80033D5C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_80033D60:
    // 0x80033D60: jr          $ra
    // 0x80033D64: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80033D64: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80033D68: jr          $ra
    // 0x80033D6C: nop

    return;
    // 0x80033D6C: nop

    // 0x80033D70: jr          $ra
    // 0x80033D74: nop

    return;
    // 0x80033D74: nop

;}
RECOMP_FUNC void func_8006F798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F798: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F79C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F7A0: nop

    // 0x8006F7A4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F7A8: nop

    // 0x8006F7AC: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x8006F7B0: jr          $ra
    // 0x8006F7B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F7B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F7B8: jr          $ra
    // 0x8006F7BC: nop

    return;
    // 0x8006F7BC: nop

    // 0x8006F7C0: jr          $ra
    // 0x8006F7C4: nop

    return;
    // 0x8006F7C4: nop

;}
RECOMP_FUNC void func_8006E5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E5E0: jal         0x80061348
    // 0x8006E5E4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E5E4: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E5E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E5EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E5F0: beq         $v0, $zero, L_8006E608
    if (ctx->r2 == 0) {
        // 0x8006E5F4: nop
    
            goto L_8006E608;
    }
    // 0x8006E5F4: nop

    // 0x8006E5F8: jal         0x80061348
    // 0x8006E5FC: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E5FC: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    after_1:
    // 0x8006E600: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E604: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E608:
    // 0x8006E608: b           L_8006E618
    // 0x8006E60C: nop

        goto L_8006E618;
    // 0x8006E60C: nop

    // 0x8006E610: b           L_8006E618
    // 0x8006E614: nop

        goto L_8006E618;
    // 0x8006E614: nop

L_8006E618:
    // 0x8006E618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E620: jr          $ra
    // 0x8006E624: nop

    return;
    // 0x8006E624: nop

;}
RECOMP_FUNC void func_80076070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076078: jal         0x80061348
    // 0x8007607C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007607C: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80076080: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076084: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076088: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007608C: beq         $v0, $zero, L_800760E0
    if (ctx->r2 == 0) {
        // 0x80076090: nop
    
            goto L_800760E0;
    }
    // 0x80076090: nop

    // 0x80076094: jal         0x80061348
    // 0x80076098: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076098: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x8007609C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800760A0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800760A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800760A8: beq         $v0, $zero, L_800760E0
    if (ctx->r2 == 0) {
        // 0x800760AC: nop
    
            goto L_800760E0;
    }
    // 0x800760AC: nop

    // 0x800760B0: jal         0x80061348
    // 0x800760B4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800760B4: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x800760B8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800760BC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800760C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800760C4: beq         $v0, $zero, L_800760E0
    if (ctx->r2 == 0) {
        // 0x800760C8: nop
    
            goto L_800760E0;
    }
    // 0x800760C8: nop

    // 0x800760CC: jal         0x80061348
    // 0x800760D0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800760D0: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x800760D4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800760D8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800760DC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800760E0:
    // 0x800760E0: b           L_800760F0
    // 0x800760E4: nop

        goto L_800760F0;
    // 0x800760E4: nop

    // 0x800760E8: b           L_800760F0
    // 0x800760EC: nop

        goto L_800760F0;
    // 0x800760EC: nop

L_800760F0:
    // 0x800760F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800760F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800760F8: jr          $ra
    // 0x800760FC: nop

    return;
    // 0x800760FC: nop

;}
RECOMP_FUNC void func_8000BB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BB00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BB04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BB08: jal         0x800045AC
    // 0x8000BB0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_0;
    // 0x8000BB0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8000BB10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000BB14: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB18: nop

    // 0x8000BB1C: bne         $t6, $zero, L_8000BB2C
    if (ctx->r14 != 0) {
        // 0x8000BB20: nop
    
            goto L_8000BB2C;
    }
    // 0x8000BB20: nop

    // 0x8000BB24: b           L_8000BC6C
    // 0x8000BB28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000BC6C;
    // 0x8000BB28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000BB2C:
    // 0x8000BB2C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB30: nop

    // 0x8000BB34: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8000BB38: nop

    // 0x8000BB3C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000BB40: beq         $t9, $zero, L_8000BB50
    if (ctx->r25 == 0) {
        // 0x8000BB44: nop
    
            goto L_8000BB50;
    }
    // 0x8000BB44: nop

    // 0x8000BB48: jal         0x800B81B4
    // 0x8000BB4C: nop

    func_800B81B4(rdram, ctx);
        goto after_1;
    // 0x8000BB4C: nop

    after_1:
L_8000BB50:
    // 0x8000BB50: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB54: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000BB58: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000BB5C: nop

    // 0x8000BB60: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8000BB64: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x8000BB68: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB6C: nop

    // 0x8000BB70: lw          $t4, 0x20C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20C);
    // 0x8000BB74: nop

    // 0x8000BB78: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8000BB7C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8000BB80: nop

    // 0x8000BB84: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8000BB88: nop

    // 0x8000BB8C: bne         $t6, $zero, L_8000BBDC
    if (ctx->r14 != 0) {
        // 0x8000BB90: nop
    
            goto L_8000BBDC;
    }
    // 0x8000BB90: nop

    // 0x8000BB94: jal         0x80004654
    // 0x8000BB98: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80004654(rdram, ctx);
        goto after_2;
    // 0x8000BB98: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8000BB9C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000BBA0: lw          $t7, 0x6C10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C10);
    // 0x8000BBA4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000BBA8: nop

    // 0x8000BBAC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000BBB0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8000BBB4: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x8000BBB8: nop

    // 0x8000BBBC: beq         $t9, $zero, L_8000BBD4
    if (ctx->r25 == 0) {
        // 0x8000BBC0: nop
    
            goto L_8000BBD4;
    }
    // 0x8000BBC0: nop

    // 0x8000BBC4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8000BBC8: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x8000BBCC: nop

    // 0x8000BBD0: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
L_8000BBD4:
    // 0x8000BBD4: b           L_8000BC3C
    // 0x8000BBD8: nop

        goto L_8000BC3C;
    // 0x8000BBD8: nop

L_8000BBDC:
    // 0x8000BBDC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8000BBE0: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x8000BBE4: nop

    // 0x8000BBE8: beq         $t2, $zero, L_8000BC08
    if (ctx->r10 == 0) {
        // 0x8000BBEC: nop
    
            goto L_8000BC08;
    }
    // 0x8000BBEC: nop

    // 0x8000BBF0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000BBF4: lw          $a0, 0x3068($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3068);
    // 0x8000BBF8: jal         0x8000D390
    // 0x8000BBFC: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x8000BBFC: nop

    after_3:
    // 0x8000BC00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000BC04: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
L_8000BC08:
    // 0x8000BC08: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000BC0C: nop

    // 0x8000BC10: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8000BC14: nop

    // 0x8000BC18: sw          $zero, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = 0;
    // 0x8000BC1C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8000BC20: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000BC24: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000BC28: nop

    // 0x8000BC2C: lw          $t6, 0x1A0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000BC30: nop

    // 0x8000BC34: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8000BC38: sw          $t7, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r15;
L_8000BC3C:
    // 0x8000BC3C: jal         0x8005F064
    // 0x8000BC40: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F064(rdram, ctx);
        goto after_4;
    // 0x8000BC40: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_4:
    // 0x8000BC44: bne         $v0, $zero, L_8000BC54
    if (ctx->r2 != 0) {
        // 0x8000BC48: nop
    
            goto L_8000BC54;
    }
    // 0x8000BC48: nop

    // 0x8000BC4C: jal         0x80022124
    // 0x8000BC50: nop

    func_80022124(rdram, ctx);
        goto after_5;
    // 0x8000BC50: nop

    after_5:
L_8000BC54:
    // 0x8000BC54: jal         0x8005F268
    // 0x8000BC58: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F268(rdram, ctx);
        goto after_6;
    // 0x8000BC58: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_6:
    // 0x8000BC5C: b           L_8000BC6C
    // 0x8000BC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000BC6C;
    // 0x8000BC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000BC64: b           L_8000BC6C
    // 0x8000BC68: nop

        goto L_8000BC6C;
    // 0x8000BC68: nop

L_8000BC6C:
    // 0x8000BC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BC74: jr          $ra
    // 0x8000BC78: nop

    return;
    // 0x8000BC78: nop

;}
RECOMP_FUNC void func_8006D404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D404: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D408: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D40C: nop

    // 0x8006D410: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D414: nop

    // 0x8006D418: slti        $t7, $v0, 0x97
    ctx->r15 = SIGNED(ctx->r2) < 0X97 ? 1 : 0;
    // 0x8006D41C: jr          $ra
    // 0x8006D420: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D420: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D424: jr          $ra
    // 0x8006D428: nop

    return;
    // 0x8006D428: nop

    // 0x8006D42C: jr          $ra
    // 0x8006D430: nop

    return;
    // 0x8006D430: nop

;}
RECOMP_FUNC void func_800C0534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0534: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C0538: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800C053C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800C0540: lw          $v0, 0x228($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X228);
    // 0x800C0544: jr          $ra
    // 0x800C0548: nop

    return;
    // 0x800C0548: nop

    // 0x800C054C: jr          $ra
    // 0x800C0550: nop

    return;
    // 0x800C0550: nop

    // 0x800C0554: jr          $ra
    // 0x800C0558: nop

    return;
    // 0x800C0558: nop

;}
RECOMP_FUNC void func_80019F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019F54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019F58: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80019F5C: nop

    // 0x80019F60: lw          $a0, 0x12C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X12C);
    // 0x80019F64: jal         0x800BCB10
    // 0x80019F68: nop

    func_800BCB10(rdram, ctx);
        goto after_0;
    // 0x80019F68: nop

    after_0:
    // 0x80019F6C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80019F70: nop

    // 0x80019F74: lw          $a0, 0x128($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X128);
    // 0x80019F78: jal         0x800BCB10
    // 0x80019F7C: nop

    func_800BCB10(rdram, ctx);
        goto after_1;
    // 0x80019F7C: nop

    after_1:
    // 0x80019F80: b           L_80019F88
    // 0x80019F84: nop

        goto L_80019F88;
    // 0x80019F84: nop

L_80019F88:
    // 0x80019F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019F90: jr          $ra
    // 0x80019F94: nop

    return;
    // 0x80019F94: nop

    // 0x80019F98: nop

    // 0x80019F9C: nop

;}
RECOMP_FUNC void func_8000E7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E7E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E7EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000E7F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000E7F4: nop

    // 0x8000E7F8: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000E7FC: nop

    // 0x8000E800: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8000E804: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E808: nop

    // 0x8000E80C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8000E810: nop

    // 0x8000E814: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8000E818: beq         $t0, $zero, L_8000E828
    if (ctx->r8 == 0) {
        // 0x8000E81C: nop
    
            goto L_8000E828;
    }
    // 0x8000E81C: nop

    // 0x8000E820: b           L_8000E9E8
    // 0x8000E824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E9E8;
    // 0x8000E824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E828:
    // 0x8000E828: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E82C: nop

    // 0x8000E830: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8000E834: nop

    // 0x8000E838: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x8000E83C: beq         $t3, $zero, L_8000E850
    if (ctx->r11 == 0) {
        // 0x8000E840: nop
    
            goto L_8000E850;
    }
    // 0x8000E840: nop

    // 0x8000E844: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E848: jal         0x8000FCD8
    // 0x8000E84C: nop

    func_8000FCD8(rdram, ctx);
        goto after_0;
    // 0x8000E84C: nop

    after_0:
L_8000E850:
    // 0x8000E850: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E854: nop

    // 0x8000E858: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8000E85C: nop

    // 0x8000E860: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x8000E864: beq         $t6, $zero, L_8000E878
    if (ctx->r14 == 0) {
        // 0x8000E868: nop
    
            goto L_8000E878;
    }
    // 0x8000E868: nop

    // 0x8000E86C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E870: jal         0x80010150
    // 0x8000E874: nop

    func_80010150(rdram, ctx);
        goto after_1;
    // 0x8000E874: nop

    after_1:
L_8000E878:
    // 0x8000E878: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E87C: nop

    // 0x8000E880: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000E884: nop

    // 0x8000E888: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8000E88C: beq         $t9, $zero, L_8000E8A0
    if (ctx->r25 == 0) {
        // 0x8000E890: nop
    
            goto L_8000E8A0;
    }
    // 0x8000E890: nop

    // 0x8000E894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E898: jal         0x80010460
    // 0x8000E89C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80010460(rdram, ctx);
        goto after_2;
    // 0x8000E89C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8000E8A0:
    // 0x8000E8A0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E8A4: nop

    // 0x8000E8A8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000E8AC: nop

    // 0x8000E8B0: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x8000E8B4: beq         $t2, $zero, L_8000E8C8
    if (ctx->r10 == 0) {
        // 0x8000E8B8: nop
    
            goto L_8000E8C8;
    }
    // 0x8000E8B8: nop

    // 0x8000E8BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E8C0: jal         0x80010460
    // 0x8000E8C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80010460(rdram, ctx);
        goto after_3;
    // 0x8000E8C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_8000E8C8:
    // 0x8000E8C8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E8CC: nop

    // 0x8000E8D0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000E8D4: nop

    // 0x8000E8D8: andi        $t5, $t4, 0x400
    ctx->r13 = ctx->r12 & 0X400;
    // 0x8000E8DC: beq         $t5, $zero, L_8000E8F0
    if (ctx->r13 == 0) {
        // 0x8000E8E0: nop
    
            goto L_8000E8F0;
    }
    // 0x8000E8E0: nop

    // 0x8000E8E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E8E8: jal         0x80010734
    // 0x8000E8EC: nop

    func_80010734(rdram, ctx);
        goto after_4;
    // 0x8000E8EC: nop

    after_4:
L_8000E8F0:
    // 0x8000E8F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E8F4: nop

    // 0x8000E8F8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000E8FC: nop

    // 0x8000E900: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x8000E904: beq         $t8, $zero, L_8000E918
    if (ctx->r24 == 0) {
        // 0x8000E908: nop
    
            goto L_8000E918;
    }
    // 0x8000E908: nop

    // 0x8000E90C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E910: jal         0x800108B8
    // 0x8000E914: nop

    func_800108B8(rdram, ctx);
        goto after_5;
    // 0x8000E914: nop

    after_5:
L_8000E918:
    // 0x8000E918: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E91C: nop

    // 0x8000E920: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8000E924: nop

    // 0x8000E928: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x8000E92C: beq         $t1, $zero, L_8000E940
    if (ctx->r9 == 0) {
        // 0x8000E930: nop
    
            goto L_8000E940;
    }
    // 0x8000E930: nop

    // 0x8000E934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E938: jal         0x80011040
    // 0x8000E93C: nop

    func_80011040(rdram, ctx);
        goto after_6;
    // 0x8000E93C: nop

    after_6:
L_8000E940:
    // 0x8000E940: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E944: nop

    // 0x8000E948: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000E94C: nop

    // 0x8000E950: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x8000E954: beq         $t4, $zero, L_8000E9E0
    if (ctx->r12 == 0) {
        // 0x8000E958: nop
    
            goto L_8000E9E0;
    }
    // 0x8000E958: nop

    // 0x8000E95C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E960: jal         0x8000F624
    // 0x8000E964: nop

    func_8000F624(rdram, ctx);
        goto after_7;
    // 0x8000E964: nop

    after_7:
    // 0x8000E968: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8000E96C: nop

    // 0x8000E970: lw          $t6, 0x1AC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1AC);
    // 0x8000E974: nop

    // 0x8000E978: slti        $at, $t6, 0x4000
    ctx->r1 = SIGNED(ctx->r14) < 0X4000 ? 1 : 0;
    // 0x8000E97C: bne         $at, $zero, L_8000E9A8
    if (ctx->r1 != 0) {
        // 0x8000E980: nop
    
            goto L_8000E9A8;
    }
    // 0x8000E980: nop

    // 0x8000E984: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E988: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E98C: beq         $at, $zero, L_8000E9A8
    if (ctx->r1 == 0) {
        // 0x8000E990: nop
    
            goto L_8000E9A8;
    }
    // 0x8000E990: nop

    // 0x8000E994: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E998: jal         0x80014F38
    // 0x8000E99C: nop

    func_80014F38(rdram, ctx);
        goto after_8;
    // 0x8000E99C: nop

    after_8:
    // 0x8000E9A0: b           L_8000E9E0
    // 0x8000E9A4: nop

        goto L_8000E9E0;
    // 0x8000E9A4: nop

L_8000E9A8:
    // 0x8000E9A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000E9AC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E9B0: lw          $t8, 0x1AC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1AC);
    // 0x8000E9B4: nop

    // 0x8000E9B8: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E9BC: bne         $at, $zero, L_8000E9D4
    if (ctx->r1 != 0) {
        // 0x8000E9C0: nop
    
            goto L_8000E9D4;
    }
    // 0x8000E9C0: nop

    // 0x8000E9C4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x8000E9C8: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E9CC: bne         $at, $zero, L_8000E9E0
    if (ctx->r1 != 0) {
        // 0x8000E9D0: nop
    
            goto L_8000E9E0;
    }
    // 0x8000E9D0: nop

L_8000E9D4:
    // 0x8000E9D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E9D8: jal         0x80010AC8
    // 0x8000E9DC: nop

    func_80010AC8(rdram, ctx);
        goto after_9;
    // 0x8000E9DC: nop

    after_9:
L_8000E9E0:
    // 0x8000E9E0: b           L_8000E9E8
    // 0x8000E9E4: nop

        goto L_8000E9E8;
    // 0x8000E9E4: nop

L_8000E9E8:
    // 0x8000E9E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E9EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E9F0: jr          $ra
    // 0x8000E9F4: nop

    return;
    // 0x8000E9F4: nop

;}
RECOMP_FUNC void func_80072560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072560: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072564: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072568: nop

    // 0x8007256C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072570: nop

    // 0x80072574: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072578: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007257C: jr          $ra
    // 0x80072580: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072580: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072584: jr          $ra
    // 0x80072588: nop

    return;
    // 0x80072588: nop

    // 0x8007258C: jr          $ra
    // 0x80072590: nop

    return;
    // 0x80072590: nop

;}
RECOMP_FUNC void func_800B1844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1844: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B1848: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B184C: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800B1850: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B1854: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x800B1858: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800B185C: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x800B1860: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x800B1864: nop

    // 0x800B1868: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800B186C: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800B1870: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800B1874: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800B1878: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800B187C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800B1880: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800B1884: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800B1888: nop

    // 0x800B188C: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800B1890: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800B1894: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800B1898: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800B189C: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800B18A0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800B18A4: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800B18A8: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800B18AC: nop

    // 0x800B18B0: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800B18B4: b           L_800B18BC
    // 0x800B18B8: nop

        goto L_800B18BC;
    // 0x800B18B8: nop

L_800B18BC:
    // 0x800B18BC: jr          $ra
    // 0x800B18C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B18C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80074474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074474: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074478: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007447C: nop

    // 0x80074480: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80074484: nop

    // 0x80074488: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007448C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074490: jr          $ra
    // 0x80074494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80074494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074498: jr          $ra
    // 0x8007449C: nop

    return;
    // 0x8007449C: nop

    // 0x800744A0: jr          $ra
    // 0x800744A4: nop

    return;
    // 0x800744A4: nop

;}
RECOMP_FUNC void func_80054264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80054268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005426C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80054270: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054274: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80054278: nop

    // 0x8005427C: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80054280: nop

    // 0x80054284: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80054288: jal         0x80059E28
    // 0x8005428C: nop

    func_80059E28(rdram, ctx);
        goto after_0;
    // 0x8005428C: nop

    after_0:
    // 0x80054290: beq         $v0, $zero, L_800542A0
    if (ctx->r2 == 0) {
        // 0x80054294: nop
    
            goto L_800542A0;
    }
    // 0x80054294: nop

    // 0x80054298: b           L_800543A0
    // 0x8005429C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800543A0;
    // 0x8005429C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800542A0:
    // 0x800542A0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800542A4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x800542A8: nop

    // 0x800542AC: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x800542B0: nop

    // 0x800542B4: slti        $at, $t9, 0xFB
    ctx->r1 = SIGNED(ctx->r25) < 0XFB ? 1 : 0;
    // 0x800542B8: bne         $at, $zero, L_800542CC
    if (ctx->r1 != 0) {
        // 0x800542BC: nop
    
            goto L_800542CC;
    }
    // 0x800542BC: nop

    // 0x800542C0: addiu       $t0, $zero, 0xFA
    ctx->r8 = ADD32(0, 0XFA);
    // 0x800542C4: b           L_800542CC
    // 0x800542C8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
        goto L_800542CC;
    // 0x800542C8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800542CC:
    // 0x800542CC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800542D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800542D4: lw          $t1, 0x670($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X670);
    // 0x800542D8: addiu       $t3, $t2, 0x2EE
    ctx->r11 = ADD32(ctx->r10, 0X2EE);
    // 0x800542DC: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800542E0: beq         $at, $zero, L_80054390
    if (ctx->r1 == 0) {
        // 0x800542E4: nop
    
            goto L_80054390;
    }
    // 0x800542E4: nop

    // 0x800542E8: jal         0x800B9000
    // 0x800542EC: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x800542EC: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_1:
    // 0x800542F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800542F4: jal         0x800507AC
    // 0x800542F8: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x800542F8: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    after_2:
    // 0x800542FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80054300: jal         0x800507AC
    // 0x80054304: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    func_800507AC(rdram, ctx);
        goto after_3;
    // 0x80054304: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    after_3:
    // 0x80054308: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005430C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054314: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80054318: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005431C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80054320: lui         $at, 0xFBFB
    ctx->r1 = S32(0XFBFB << 16);
    // 0x80054324: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80054328: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8005432C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80054330: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80054334: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054338: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8005433C: nop

    // 0x80054340: lh          $t0, 0xE($t5)
    ctx->r8 = MEM_H(ctx->r13, 0XE);
    // 0x80054344: nop

    // 0x80054348: addiu       $t2, $t0, 0xA
    ctx->r10 = ADD32(ctx->r8, 0XA);
    // 0x8005434C: sh          $t2, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r10;
    // 0x80054350: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054354: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80054358: nop

    // 0x8005435C: lh          $t3, 0xE($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XE);
    // 0x80054360: nop

    // 0x80054364: slti        $at, $t3, 0x3E8
    ctx->r1 = SIGNED(ctx->r11) < 0X3E8 ? 1 : 0;
    // 0x80054368: bne         $at, $zero, L_80054380
    if (ctx->r1 != 0) {
        // 0x8005436C: nop
    
            goto L_80054380;
    }
    // 0x8005436C: nop

    // 0x80054370: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054374: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80054378: addiu       $t6, $zero, 0x3E7
    ctx->r14 = ADD32(0, 0X3E7);
    // 0x8005437C: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
L_80054380:
    // 0x80054380: b           L_800543A0
    // 0x80054384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800543A0;
    // 0x80054384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80054388: b           L_80054398
    // 0x8005438C: nop

        goto L_80054398;
    // 0x8005438C: nop

L_80054390:
    // 0x80054390: b           L_800543A0
    // 0x80054394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800543A0;
    // 0x80054394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054398:
    // 0x80054398: b           L_800543A0
    // 0x8005439C: nop

        goto L_800543A0;
    // 0x8005439C: nop

L_800543A0:
    // 0x800543A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800543A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800543A8: jr          $ra
    // 0x800543AC: nop

    return;
    // 0x800543AC: nop

;}
RECOMP_FUNC void Main_UpdateControllers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE960: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BE964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BE968: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BE96C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BE970: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BE974: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800BE978: nop

    // 0x800BE97C: bne         $t6, $zero, L_800BE9A4
    if (ctx->r14 != 0) {
        // 0x800BE980: nop
    
            goto L_800BE9A4;
    }
    // 0x800BE980: nop

    // 0x800BE984: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE988: jal         0x800C5590
    // 0x800BE98C: addiu       $a0, $a0, 0x24E0
    ctx->r4 = ADD32(ctx->r4, 0X24E0);
    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x800BE98C: addiu       $a0, $a0, 0x24E0
    ctx->r4 = ADD32(ctx->r4, 0X24E0);
    after_0:
    // 0x800BE990: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE994: addiu       $a0, $a0, 0x24E0
    ctx->r4 = ADD32(ctx->r4, 0X24E0);
    // 0x800BE998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BE99C: jal         0x800C4C40
    // 0x800BE9A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE9A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800BE9A4:
    // 0x800BE9A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BE9A8: jal         0x800C5654
    // 0x800BE9AC: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    osContGetReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x800BE9AC: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    after_2:
    // 0x800BE9B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800BE9B4:
    // 0x800BE9B4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE9B8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BE9BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BE9C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BE9C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800BE9C8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BE9CC: lbu         $t9, 0x255C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X255C);
    // 0x800BE9D0: nop

    // 0x800BE9D4: bne         $t9, $zero, L_800BEC00
    if (ctx->r25 != 0) {
        // 0x800BE9D8: nop
    
            goto L_800BEC00;
    }
    // 0x800BE9D8: nop

    // 0x800BE9DC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE9E0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BE9E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BE9E8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BE9EC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800BE9F0: addiu       $t2, $t2, 0xDA8
    ctx->r10 = ADD32(ctx->r10, 0XDA8);
    // 0x800BE9F4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800BE9F8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE9FC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA00: nop

    // 0x800BEA04: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800BEA08: nop

    // 0x800BEA0C: beq         $t5, $zero, L_800BEA3C
    if (ctx->r13 == 0) {
        // 0x800BEA10: nop
    
            goto L_800BEA3C;
    }
    // 0x800BEA10: nop

    // 0x800BEA14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BEA18: lwc1        $f4, 0xE50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE50);
    // 0x800BEA1C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA20: nop

    // 0x800BEA24: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x800BEA28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BEA2C: lwc1        $f6, 0xE5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE5C);
    // 0x800BEA30: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA34: nop

    // 0x800BEA38: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
L_800BEA3C:
    // 0x800BEA3C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA40: nop

    // 0x800BEA44: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BEA48: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA4C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800BEA50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEA54: lwc1        $f8, 0x18($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X18);
    // 0x800BEA58: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEA5C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BEA60: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BEA64: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BEA68: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800BEA6C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BEA70: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800BEA74: lb          $t2, 0x255A($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X255A);
    // 0x800BEA78: nop

    // 0x800BEA7C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BEA80: nop

    // 0x800BEA84: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BEA88: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BEA8C: swc1        $f6, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f6.u32l;
    // 0x800BEA90: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BEA94: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800BEA98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BEA9C: lwc1        $f8, 0x1C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800BEAA0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEAA4: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BEAA8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800BEAAC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800BEAB0: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800BEAB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BEAB8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800BEABC: lb          $t6, 0x255B($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X255B);
    // 0x800BEAC0: nop

    // 0x800BEAC4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800BEAC8: nop

    // 0x800BEACC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BEAD0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800BEAD4: swc1        $f6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f6.u32l;
    // 0x800BEAD8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BEADC: nop

    // 0x800BEAE0: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x800BEAE4: nop

    // 0x800BEAE8: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BEAEC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEAF0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BEAF4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BEAF8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BEAFC: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800BEB00: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800BEB04: lhu         $t2, 0x2558($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2558);
    // 0x800BEB08: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB0C: nop

    // 0x800BEB10: sh          $t2, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r10;
    // 0x800BEB14: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB18: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BEB1C: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800BEB20: nop

    // 0x800BEB24: xor         $t3, $t5, $t6
    ctx->r11 = ctx->r13 ^ ctx->r14;
    // 0x800BEB28: and         $t7, $t3, $t5
    ctx->r15 = ctx->r11 & ctx->r13;
    // 0x800BEB2C: sh          $t7, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r15;
    // 0x800BEB30: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BEB38: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800BEB3C: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800BEB40: nop

    // 0x800BEB44: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800BEB48: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x800BEB4C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB50: nop

    // 0x800BEB54: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800BEB58: lhu         $t2, 0xA($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0XA);
    // 0x800BEB5C: nop

    // 0x800BEB60: beq         $t1, $t2, L_800BEBA4
    if (ctx->r9 == ctx->r10) {
        // 0x800BEB64: nop
    
            goto L_800BEBA4;
    }
    // 0x800BEB64: nop

    // 0x800BEB68: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB6C: nop

    // 0x800BEB70: lhu         $t6, 0x4($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X4);
    // 0x800BEB74: nop

    // 0x800BEB78: sh          $t6, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r14;
    // 0x800BEB7C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB80: nop

    // 0x800BEB84: lhu         $t5, 0x4($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X4);
    // 0x800BEB88: nop

    // 0x800BEB8C: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
    // 0x800BEB90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800BEB94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BEB98: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BEB9C: b           L_800BEBF8
    // 0x800BEBA0: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
        goto L_800BEBF8;
    // 0x800BEBA0: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
L_800BEBA4:
    // 0x800BEBA4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BEBAC: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800BEBB0: nop

    // 0x800BEBB4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800BEBB8: nop

    // 0x800BEBBC: bc1f        L_800BEBEC
    if (!c1cs) {
        // 0x800BEBC0: nop
    
            goto L_800BEBEC;
    }
    // 0x800BEBC0: nop

    // 0x800BEBC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBC8: nop

    // 0x800BEBCC: lhu         $t0, 0xA($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0XA);
    // 0x800BEBD0: nop

    // 0x800BEBD4: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
    // 0x800BEBD8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800BEBDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BEBE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBE4: b           L_800BEBF8
    // 0x800BEBE8: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
        goto L_800BEBF8;
    // 0x800BEBE8: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
L_800BEBEC:
    // 0x800BEBEC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BEBF0: nop

    // 0x800BEBF4: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
L_800BEBF8:
    // 0x800BEBF8: b           L_800BEC98
    // 0x800BEBFC: nop

        goto L_800BEC98;
    // 0x800BEBFC: nop

L_800BEC00:
    // 0x800BEC00: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEC04: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BEC08: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800BEC0C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800BEC10: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800BEC14: addiu       $t5, $t5, 0xDA8
    ctx->r13 = ADD32(ctx->r13, 0XDA8);
    // 0x800BEC18: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x800BEC1C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BEC20: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800BEC28: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800BEC2C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC30: nop

    // 0x800BEC34: sh          $zero, 0xA($t0)
    MEM_H(0XA, ctx->r8) = 0;
    // 0x800BEC38: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC3C: nop

    // 0x800BEC40: lhu         $s1, 0xA($t8)
    ctx->r17 = MEM_HU(ctx->r24, 0XA);
    // 0x800BEC44: nop

    // 0x800BEC48: sh          $s1, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r17;
    // 0x800BEC4C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC50: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800BEC54: sh          $s0, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r16;
    // 0x800BEC58: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC5C: nop

    // 0x800BEC60: sh          $s0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r16;
    // 0x800BEC64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BEC68: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC6C: nop

    // 0x800BEC70: swc1        $f10, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f10.u32l;
    // 0x800BEC74: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC78: nop

    // 0x800BEC7C: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800BEC80: nop

    // 0x800BEC84: swc1        $f4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f4.u32l;
    // 0x800BEC88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800BEC8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800BEC90: nop

    // 0x800BEC94: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
L_800BEC98:
    // 0x800BEC98: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEC9C: nop

    // 0x800BECA0: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x800BECA4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800BECA8: bne         $at, $zero, L_800BE9B4
    if (ctx->r1 != 0) {
        // 0x800BECAC: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_800BE9B4;
    }
    // 0x800BECAC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800BECB0: b           L_800BECB8
    // 0x800BECB4: nop

        goto L_800BECB8;
    // 0x800BECB4: nop

L_800BECB8:
    // 0x800BECB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BECBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BECC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BECC4: jr          $ra
    // 0x800BECC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800BECC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80071CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071CC4: jal         0x80061348
    // 0x80071CC8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071CC8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071CCC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071CD0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071CD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071CD8: beq         $v0, $zero, L_80071D10
    if (ctx->r2 == 0) {
        // 0x80071CDC: nop
    
            goto L_80071D10;
    }
    // 0x80071CDC: nop

    // 0x80071CE0: jal         0x80061348
    // 0x80071CE4: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071CE4: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071CE8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071CEC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071CF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071CF4: beq         $v0, $zero, L_80071D10
    if (ctx->r2 == 0) {
        // 0x80071CF8: nop
    
            goto L_80071D10;
    }
    // 0x80071CF8: nop

    // 0x80071CFC: jal         0x80061348
    // 0x80071D00: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071D00: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071D04: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071D08: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071D0C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071D10:
    // 0x80071D10: b           L_80071D20
    // 0x80071D14: nop

        goto L_80071D20;
    // 0x80071D14: nop

    // 0x80071D18: b           L_80071D20
    // 0x80071D1C: nop

        goto L_80071D20;
    // 0x80071D1C: nop

L_80071D20:
    // 0x80071D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D28: jr          $ra
    // 0x80071D2C: nop

    return;
    // 0x80071D2C: nop

;}
RECOMP_FUNC void func_8006D054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D05C: nop

    // 0x8006D060: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D064: nop

    // 0x8006D068: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D06C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D070: jr          $ra
    // 0x8006D074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D078: jr          $ra
    // 0x8006D07C: nop

    return;
    // 0x8006D07C: nop

    // 0x8006D080: jr          $ra
    // 0x8006D084: nop

    return;
    // 0x8006D084: nop

;}
RECOMP_FUNC void SysMem_GetUnlockedSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCD3C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCD40: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800BCD44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCD48: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BCD4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCD50: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BCD54: lw          $t7, 0x25E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E8);
    // 0x800BCD58: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCD5C: nop

    // 0x800BCD60: beq         $t6, $t7, L_800BCDD8
    if (ctx->r14 == ctx->r15) {
        // 0x800BCD64: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800BCDD8;
    }
    // 0x800BCD64: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
L_800BCD68:
    // 0x800BCD68: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCD6C: nop

    // 0x800BCD70: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BCD74: nop

    // 0x800BCD78: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BCD7C: beq         $t0, $zero, L_800BCDBC
    if (ctx->r8 == 0) {
        // 0x800BCD80: nop
    
            goto L_800BCDBC;
    }
    // 0x800BCD80: nop

    // 0x800BCD84: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x800BCD88: bne         $t1, $zero, L_800BCDBC
    if (ctx->r9 != 0) {
        // 0x800BCD8C: nop
    
            goto L_800BCDBC;
    }
    // 0x800BCD8C: nop

    // 0x800BCD90: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800BCD94: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BCD98: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800BCD9C: nop

    // 0x800BCDA0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800BCDA4: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800BCDA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCDAC: lh          $t6, 0x2638($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2638);
    // 0x800BCDB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BCDB4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BCDB8: sh          $t7, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = ctx->r15;
L_800BCDBC:
    // 0x800BCDBC: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCDC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BCDC4: lw          $t9, 0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25E8);
    // 0x800BCDC8: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800BCDCC: nop

    // 0x800BCDD0: bne         $t0, $t9, L_800BCD68
    if (ctx->r8 != ctx->r25) {
        // 0x800BCDD4: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_800BCD68;
    }
    // 0x800BCDD4: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_800BCDD8:
    // 0x800BCDD8: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BCDDC: nop

    // 0x800BCDE0: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800BCDE4: b           L_800BCDF4
    // 0x800BCDE8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800BCDF4;
    // 0x800BCDE8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800BCDEC: b           L_800BCDF4
    // 0x800BCDF0: nop

        goto L_800BCDF4;
    // 0x800BCDF0: nop

L_800BCDF4:
    // 0x800BCDF4: jr          $ra
    // 0x800BCDF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCDF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800747AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800747AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800747B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800747B4: jal         0x80061348
    // 0x800747B8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800747B8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x800747BC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800747C0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800747C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800747C8: beq         $v0, $zero, L_8007481C
    if (ctx->r2 == 0) {
        // 0x800747CC: nop
    
            goto L_8007481C;
    }
    // 0x800747CC: nop

    // 0x800747D0: jal         0x80061348
    // 0x800747D4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800747D4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x800747D8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800747DC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800747E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800747E4: beq         $v0, $zero, L_8007481C
    if (ctx->r2 == 0) {
        // 0x800747E8: nop
    
            goto L_8007481C;
    }
    // 0x800747E8: nop

    // 0x800747EC: jal         0x80061348
    // 0x800747F0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800747F0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x800747F4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800747F8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800747FC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074800: beq         $v0, $zero, L_8007481C
    if (ctx->r2 == 0) {
        // 0x80074804: nop
    
            goto L_8007481C;
    }
    // 0x80074804: nop

    // 0x80074808: jal         0x80061348
    // 0x8007480C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007480C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074810: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074814: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074818: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007481C:
    // 0x8007481C: b           L_8007482C
    // 0x80074820: nop

        goto L_8007482C;
    // 0x80074820: nop

    // 0x80074824: b           L_8007482C
    // 0x80074828: nop

        goto L_8007482C;
    // 0x80074828: nop

L_8007482C:
    // 0x8007482C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074834: jr          $ra
    // 0x80074838: nop

    return;
    // 0x80074838: nop

;}
RECOMP_FUNC void func_800677C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800677C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800677C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800677C8: jal         0x80061348
    // 0x800677CC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800677CC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800677D0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800677D4: b           L_800677E4
    // 0x800677D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800677E4;
    // 0x800677D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800677DC: b           L_800677E4
    // 0x800677E0: nop

        goto L_800677E4;
    // 0x800677E0: nop

L_800677E4:
    // 0x800677E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800677E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800677EC: jr          $ra
    // 0x800677F0: nop

    return;
    // 0x800677F0: nop

;}
RECOMP_FUNC void func_80072B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072B14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072B18: nop

    // 0x80072B1C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072B20: nop

    // 0x80072B24: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072B28: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072B2C: jr          $ra
    // 0x80072B30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072B30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B34: jr          $ra
    // 0x80072B38: nop

    return;
    // 0x80072B38: nop

    // 0x80072B3C: jr          $ra
    // 0x80072B40: nop

    return;
    // 0x80072B40: nop

;}
RECOMP_FUNC void func_8000D5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D5A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000D5AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D5B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000D5B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000D5B8:
    // 0x8000D5B8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D5BC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D5C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D5C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000D5C8: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x8000D5CC: nop

    // 0x8000D5D0: bne         $t8, $zero, L_8000D5E0
    if (ctx->r24 != 0) {
        // 0x8000D5D4: nop
    
            goto L_8000D5E0;
    }
    // 0x8000D5D4: nop

    // 0x8000D5D8: b           L_8000D5F8
    // 0x8000D5DC: nop

        goto L_8000D5F8;
    // 0x8000D5DC: nop

L_8000D5E0:
    // 0x8000D5E0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D5E4: nop

    // 0x8000D5E8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000D5EC: slti        $at, $t0, 0x14
    ctx->r1 = SIGNED(ctx->r8) < 0X14 ? 1 : 0;
    // 0x8000D5F0: bne         $at, $zero, L_8000D5B8
    if (ctx->r1 != 0) {
        // 0x8000D5F4: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_8000D5B8;
    }
    // 0x8000D5F4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_8000D5F8:
    // 0x8000D5F8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D5FC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8000D600: bne         $t1, $at, L_8000D610
    if (ctx->r9 != ctx->r1) {
        // 0x8000D604: nop
    
            goto L_8000D610;
    }
    // 0x8000D604: nop

    // 0x8000D608: b           L_8000D678
    // 0x8000D60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D678;
    // 0x8000D60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D610:
    // 0x8000D610: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D614: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8000D618: addiu       $t4, $t4, -0x7E8
    ctx->r12 = ADD32(ctx->r12, -0X7E8);
    // 0x8000D61C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000D620: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000D624: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D628: sw          $t5, -0x7F4($at)
    MEM_W(-0X7F4, ctx->r1) = ctx->r13;
    // 0x8000D62C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000D630: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D634: sw          $t6, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r14;
    // 0x8000D638: jal         0x80004654
    // 0x8000D63C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_80004654(rdram, ctx);
        goto after_0;
    // 0x8000D63C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x8000D640: bgez        $v0, L_8000D650
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000D644: nop
    
            goto L_8000D650;
    }
    // 0x8000D644: nop

    // 0x8000D648: b           L_8000D678
    // 0x8000D64C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D678;
    // 0x8000D64C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D650:
    // 0x8000D650: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000D654: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D658: lw          $t8, -0x7F4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7F4);
    // 0x8000D65C: lw          $t7, 0x6C10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C10);
    // 0x8000D660: nop

    // 0x8000D664: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000D668: b           L_8000D678
    // 0x8000D66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D678;
    // 0x8000D66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D670: b           L_8000D678
    // 0x8000D674: nop

        goto L_8000D678;
    // 0x8000D674: nop

L_8000D678:
    // 0x8000D678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D67C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000D680: jr          $ra
    // 0x8000D684: nop

    return;
    // 0x8000D684: nop

;}
RECOMP_FUNC void func_800AF1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AF1F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800AF1F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800AF1FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800AF200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AF204: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF208: nop

    // 0x800AF20C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF210: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800AF214: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF218: lwc1        $f4, 0x430($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X430);
    // 0x800AF21C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF220: nop

    // 0x800AF224: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x800AF228: nop

    // 0x800AF22C: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF230: nop
    
            goto L_800AF318;
    }
    // 0x800AF230: nop

    // 0x800AF234: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF238: lwc1        $f6, 0x438($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X438);
    // 0x800AF23C: nop

    // 0x800AF240: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800AF244: nop

    // 0x800AF248: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF24C: nop
    
            goto L_800AF318;
    }
    // 0x800AF24C: nop

    // 0x800AF250: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AF258: nop

    // 0x800AF25C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800AF260: nop

    // 0x800AF264: bc1f        L_800AF274
    if (!c1cs) {
        // 0x800AF268: nop
    
            goto L_800AF274;
    }
    // 0x800AF268: nop

    // 0x800AF26C: b           L_800AF284
    // 0x800AF270: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
        goto L_800AF284;
    // 0x800AF270: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
L_800AF274:
    // 0x800AF274: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF278: nop

    // 0x800AF27C: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800AF280: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
L_800AF284:
    // 0x800AF284: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF288: lwc1        $f8, 0x440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X440);
    // 0x800AF28C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800AF290: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AF294: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800AF298: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AF29C: nop

    // 0x800AF2A0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800AF2A4: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AF2A8: bc1f        L_800AF2B8
    if (!c1cs) {
        // 0x800AF2AC: swc1        $f18, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
            goto L_800AF2B8;
    }
    // 0x800AF2AC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800AF2B0: b           L_800AF2BC
    // 0x800AF2B4: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
        goto L_800AF2BC;
    // 0x800AF2B4: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_800AF2B8:
    // 0x800AF2B8: neg.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = -ctx->f12.fl;
L_800AF2BC:
    // 0x800AF2BC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x800AF2C0: nop

    // 0x800AF2C4: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF2C8: nop
    
            goto L_800AF318;
    }
    // 0x800AF2C8: nop

    // 0x800AF2CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AF2D0: nop

    // 0x800AF2D4: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x800AF2D8: nop

    // 0x800AF2DC: bc1f        L_800AF2EC
    if (!c1cs) {
        // 0x800AF2E0: nop
    
            goto L_800AF2EC;
    }
    // 0x800AF2E0: nop

    // 0x800AF2E4: b           L_800AF2F4
    // 0x800AF2E8: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
        goto L_800AF2F4;
    // 0x800AF2E8: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
L_800AF2EC:
    // 0x800AF2EC: neg.s       $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = -ctx->f14.fl;
    // 0x800AF2F0: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
L_800AF2F4:
    // 0x800AF2F4: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AF2F8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800AF2FC: nop

    // 0x800AF300: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800AF304: nop

    // 0x800AF308: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF30C: nop
    
            goto L_800AF318;
    }
    // 0x800AF30C: nop

    // 0x800AF310: b           L_800AF328
    // 0x800AF314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800AF328;
    // 0x800AF314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AF318:
    // 0x800AF318: b           L_800AF328
    // 0x800AF31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AF328;
    // 0x800AF31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF320: b           L_800AF328
    // 0x800AF324: nop

        goto L_800AF328;
    // 0x800AF324: nop

L_800AF328:
    // 0x800AF328: jr          $ra
    // 0x800AF32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AF32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800774F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800774F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800774F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800774F8: jal         0x80061488
    // 0x800774FC: addiu       $a0, $zero, 0x496
    ctx->r4 = ADD32(0, 0X496);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800774FC: addiu       $a0, $zero, 0x496
    ctx->r4 = ADD32(0, 0X496);
    after_0:
    // 0x80077500: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80077504: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80077508: b           L_80077518
    // 0x8007750C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077518;
    // 0x8007750C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077510: b           L_80077518
    // 0x80077514: nop

        goto L_80077518;
    // 0x80077514: nop

L_80077518:
    // 0x80077518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007751C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077520: jr          $ra
    // 0x80077524: nop

    return;
    // 0x80077524: nop

;}
RECOMP_FUNC void func_80072E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072E24: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072E28: nop

    // 0x80072E2C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072E30: nop

    // 0x80072E34: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072E38: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072E3C: jr          $ra
    // 0x80072E40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072E40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072E44: jr          $ra
    // 0x80072E48: nop

    return;
    // 0x80072E48: nop

    // 0x80072E4C: jr          $ra
    // 0x80072E50: nop

    return;
    // 0x80072E50: nop

;}
RECOMP_FUNC void func_8006903C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006903C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069044: jal         0x80061348
    // 0x80069048: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069048: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_0:
    // 0x8006904C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069050: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069054: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069058: beq         $v0, $zero, L_80069074
    if (ctx->r2 == 0) {
        // 0x8006905C: nop
    
            goto L_80069074;
    }
    // 0x8006905C: nop

    // 0x80069060: jal         0x80061348
    // 0x80069064: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069064: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069068: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006906C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069070: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80069074:
    // 0x80069074: b           L_80069084
    // 0x80069078: nop

        goto L_80069084;
    // 0x80069078: nop

    // 0x8006907C: b           L_80069084
    // 0x80069080: nop

        goto L_80069084;
    // 0x80069080: nop

L_80069084:
    // 0x80069084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006908C: jr          $ra
    // 0x80069090: nop

    return;
    // 0x80069090: nop

;}
RECOMP_FUNC void __vsVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2184: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x800D2188: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x800D218C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x800D2190: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x800D2194: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2198: lw          $t1, 0x60($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X60);
    // 0x800D219C: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800D21A0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800D21A4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D21A8: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x800D21AC: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x800D21B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800D21B4: nop

    // 0x800D21B8: nop

    // 0x800D21BC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21C0: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x800D21C4: mflo        $v1
    ctx->r3 = lo;
    // 0x800D21C8: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800D21CC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800D21D0: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21D4: mflo        $t8
    ctx->r24 = lo;
    // 0x800D21D8: nop

    // 0x800D21DC: nop

    // 0x800D21E0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21E4: mflo        $a2
    ctx->r6 = lo;
    // 0x800D21E8: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x800D21EC: nop

    // 0x800D21F0: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D21F4: mflo        $v1
    ctx->r3 = lo;
    // 0x800D21F8: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x800D21FC: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x800D2200: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D2204: jr          $ra
    // 0x800D2208: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800D2208: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void func_800672FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800672FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067304: jal         0x80061488
    // 0x80067308: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067308: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8006730C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067310: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067314: b           L_80067324
    // 0x80067318: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067324;
    // 0x80067318: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006731C: b           L_80067324
    // 0x80067320: nop

        goto L_80067324;
    // 0x80067320: nop

L_80067324:
    // 0x80067324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006732C: jr          $ra
    // 0x80067330: nop

    return;
    // 0x80067330: nop

;}
