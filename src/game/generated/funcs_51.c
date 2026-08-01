#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800D0078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0078: nop

    // 0x800D007C: nop

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
RECOMP_FUNC void func_800D0D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0D1C: nop

;}
RECOMP_FUNC void func_800D1014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1014: nop

    // 0x800D1018: nop

    // 0x800D101C: nop

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
RECOMP_FUNC void func_800D1C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C74: nop

    // 0x800D1C78: nop

    // 0x800D1C7C: nop

;}
RECOMP_FUNC void func_800D1D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1D88: nop

    // 0x800D1D8C: nop

;}
RECOMP_FUNC void func_800D1FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1FC8: nop

    // 0x800D1FCC: nop

;}
RECOMP_FUNC void func_800D2158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2158: jr          $ra
    // 0x800D215C: nop

    return;
    // 0x800D215C: nop

;}
RECOMP_FUNC void func_800D252C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D252C: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x800D2530: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D2534: bne         $t6, $at, L_800D259C
    if (ctx->r14 != ctx->r1) {
        // 0x800D2538: nop
    
            goto L_800D259C;
    }
    // 0x800D2538: nop

    // 0x800D253C: lbu         $t7, 0x9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9);
    // 0x800D2540: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800D2544: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800D2548: bne         $t7, $at, L_800D259C
    if (ctx->r15 != ctx->r1) {
        // 0x800D254C: nop
    
            goto L_800D259C;
    }
    // 0x800D254C: nop

    // 0x800D2550: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800D2554: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800D2558: lw          $a2, 0x18($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X18);
    // 0x800D255C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800D2560: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800D2564: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D2568: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800D256C: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800D2570: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800D2574: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800D2578: beq         $a2, $zero, L_800D2598
    if (ctx->r6 == 0) {
        // 0x800D257C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D2598;
    }
    // 0x800D257C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D2580: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800D2584: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D2588: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D258C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800D2590: jr          $ra
    // 0x800D2594: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    return;
    // 0x800D2594: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
L_800D2598:
    // 0x800D2598: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
L_800D259C:
    // 0x800D259C: jr          $ra
    // 0x800D25A0: nop

    return;
    // 0x800D25A0: nop

;}
RECOMP_FUNC void func_800D27CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D27CC: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800D27D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D27D4: lbu         $s6, 0x8($a0)
    ctx->r22 = MEM_BU(ctx->r4, 0X8);
    // 0x800D27D8: lbu         $s3, 0x9($a0)
    ctx->r19 = MEM_BU(ctx->r4, 0X9);
    // 0x800D27DC: lbu         $s4, 0xA($a0)
    ctx->r20 = MEM_BU(ctx->r4, 0XA);
    // 0x800D27E0: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x800D27E4: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x800D27E8: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x800D27EC: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x800D27F0: beq         $at, $zero, L_800D2FD4
    if (ctx->r1 == 0) {
        // 0x800D27F4: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_800D2FD4;
    }
    // 0x800D27F4: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x800D27F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D27FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D2800: addu        $at, $at, $t7
    gpr jr_addend_800D2808 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D2804: lw          $t7, 0x370($at)
    ctx->r15 = ADD32(ctx->r1, 0X370);
    // 0x800D2808: jr          $t7
    // 0x800D280C: nop

    switch (jr_addend_800D2808 >> 2) {
        case 0: goto L_800D2B64; break;
        case 1: goto L_800D2FD4; break;
        case 2: goto L_800D2FD4; break;
        case 3: goto L_800D2FD4; break;
        case 4: goto L_800D2FD4; break;
        case 5: goto L_800D2FD4; break;
        case 6: goto L_800D2FD4; break;
        case 7: goto L_800D2FD4; break;
        case 8: goto L_800D2FD4; break;
        case 9: goto L_800D2FD4; break;
        case 10: goto L_800D2FD4; break;
        case 11: goto L_800D2FD4; break;
        case 12: goto L_800D2FD4; break;
        case 13: goto L_800D2FD4; break;
        case 14: goto L_800D2FD4; break;
        case 15: goto L_800D2FD4; break;
        case 16: goto L_800D2810; break;
        case 17: goto L_800D2FD4; break;
        case 18: goto L_800D2FD4; break;
        case 19: goto L_800D2FD4; break;
        case 20: goto L_800D2FD4; break;
        case 21: goto L_800D2FD4; break;
        case 22: goto L_800D2FD4; break;
        case 23: goto L_800D2FD4; break;
        case 24: goto L_800D2FD4; break;
        case 25: goto L_800D2FD4; break;
        case 26: goto L_800D2FD4; break;
        case 27: goto L_800D2FD4; break;
        case 28: goto L_800D2FD4; break;
        case 29: goto L_800D2FD4; break;
        case 30: goto L_800D2FD4; break;
        case 31: goto L_800D2FD4; break;
        case 32: goto L_800D2BBC; break;
        case 33: goto L_800D2FD4; break;
        case 34: goto L_800D2FD4; break;
        case 35: goto L_800D2FD4; break;
        case 36: goto L_800D2FD4; break;
        case 37: goto L_800D2FD4; break;
        case 38: goto L_800D2FD4; break;
        case 39: goto L_800D2FD4; break;
        case 40: goto L_800D2FD4; break;
        case 41: goto L_800D2FD4; break;
        case 42: goto L_800D2FD4; break;
        case 43: goto L_800D2FD4; break;
        case 44: goto L_800D2FD4; break;
        case 45: goto L_800D2FD4; break;
        case 46: goto L_800D2FD4; break;
        case 47: goto L_800D2FD4; break;
        case 48: goto L_800D2C9C; break;
        case 49: goto L_800D2FD4; break;
        case 50: goto L_800D2FD4; break;
        case 51: goto L_800D2FD4; break;
        case 52: goto L_800D2FD4; break;
        case 53: goto L_800D2FD4; break;
        case 54: goto L_800D2FD4; break;
        case 55: goto L_800D2FD4; break;
        case 56: goto L_800D2FD4; break;
        case 57: goto L_800D2FD4; break;
        case 58: goto L_800D2FD4; break;
        case 59: goto L_800D2FD4; break;
        case 60: goto L_800D2FD4; break;
        case 61: goto L_800D2FD4; break;
        case 62: goto L_800D2FD4; break;
        case 63: goto L_800D2FD4; break;
        case 64: goto L_800D2F08; break;
        case 65: goto L_800D2FD4; break;
        case 66: goto L_800D2FD4; break;
        case 67: goto L_800D2FD4; break;
        case 68: goto L_800D2FD4; break;
        case 69: goto L_800D2FD4; break;
        case 70: goto L_800D2FD4; break;
        case 71: goto L_800D2FD4; break;
        case 72: goto L_800D2FD4; break;
        case 73: goto L_800D2FD4; break;
        case 74: goto L_800D2FD4; break;
        case 75: goto L_800D2FD4; break;
        case 76: goto L_800D2FD4; break;
        case 77: goto L_800D2FD4; break;
        case 78: goto L_800D2FD4; break;
        case 79: goto L_800D2FD4; break;
        case 80: goto L_800D2C24; break;
        case 81: goto L_800D2FD4; break;
        case 82: goto L_800D2FD4; break;
        case 83: goto L_800D2FD4; break;
        case 84: goto L_800D2FD4; break;
        case 85: goto L_800D2FD4; break;
        case 86: goto L_800D2FD4; break;
        case 87: goto L_800D2FD4; break;
        case 88: goto L_800D2FD4; break;
        case 89: goto L_800D2FD4; break;
        case 90: goto L_800D2FD4; break;
        case 91: goto L_800D2FD4; break;
        case 92: goto L_800D2FD4; break;
        case 93: goto L_800D2FD4; break;
        case 94: goto L_800D2FD4; break;
        case 95: goto L_800D2FD4; break;
        case 96: goto L_800D2F3C; break;
        default: switch_error(__func__, 0x800D2808, 0x800F0370);
    }
    // 0x800D280C: nop

L_800D2810:
    // 0x800D2810: beql        $s4, $zero, L_800D2B68
    if (ctx->r20 == 0) {
        // 0x800D2814: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D2B68;
    }
    goto skip_0;
    // 0x800D2814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800D2818: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x800D281C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2824: bne         $t8, $at, L_800D2FD4
    if (ctx->r24 != ctx->r1) {
        // 0x800D2828: andi        $a1, $s3, 0xFF
        ctx->r5 = ctx->r19 & 0XFF;
            goto L_800D2FD4;
    }
    // 0x800D2828: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D282C: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800D2830: jal         0x800D26D0
    // 0x800D2834: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    __lookupSoundQuick(rdram, ctx);
        goto after_0;
    // 0x800D2834: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    after_0:
    // 0x800D2838: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D283C: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D283C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800D2840: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2844: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800D2848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D284C: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800D2850: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x800D2854: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800D2858: sb          $zero, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = 0;
    // 0x800D285C: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D2860: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800D2864: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800D2868: jal         0x800D2660
    // 0x800D286C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    __mapVoice(rdram, ctx);
        goto after_1;
    // 0x800D286C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    after_1:
    // 0x800D2870: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D2874: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D2874: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D2878: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D287C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800D2880: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D2884: jal         0x800D3FE8
    // 0x800D2888: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    alSynAllocVoice(rdram, ctx);
        goto after_2;
    // 0x800D2888: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_2:
    // 0x800D288C: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x800D2890: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x800D2894: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x800D2898: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800D289C: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x800D28A0: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x800D28A4: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x800D28A8: bnel        $at, $zero, L_800D28BC
    if (ctx->r1 != 0) {
        // 0x800D28AC: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_800D28BC;
    }
    goto skip_1;
    // 0x800D28AC: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x800D28B0: b           L_800D28BC
    // 0x800D28B4: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800D28BC;
    // 0x800D28B4: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x800D28B8: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800D28BC:
    // 0x800D28BC: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x800D28C0: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800D28C4: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x800D28C8: subu        $t8, $s3, $t7
    ctx->r24 = SUB32(ctx->r19, ctx->r15);
    // 0x800D28CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800D28D0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800D28D4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800D28D8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800D28DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D28E0: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800D28E4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800D28E8: jal         0x800CADC0
    // 0x800D28EC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x800D28EC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x800D28F0: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800D28F4: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800D28F8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800D28FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D2900: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x800D2904: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x800D2908: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800D290C: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2910: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800D2914: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x800D2918: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800D291C: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x800D2920: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x800D2924: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x800D2928: lw          $s2, 0x0($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X0);
    // 0x800D292C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x800D2930: lbu         $a2, 0x4($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X4);
    // 0x800D2934: beql        $a2, $zero, L_800D29A0
    if (ctx->r6 == 0) {
        // 0x800D2938: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800D29A0;
    }
    goto skip_2;
    // 0x800D2938: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x800D293C: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x800D2940: beql        $v0, $zero, L_800D29A0
    if (ctx->r2 == 0) {
        // 0x800D2944: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800D29A0;
    }
    goto skip_3;
    // 0x800D2944: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x800D2948: lbu         $t9, 0x6($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X6);
    // 0x800D294C: lbu         $a3, 0x5($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X5);
    // 0x800D2950: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800D2954: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D2958: lbu         $t6, 0x7($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X7);
    // 0x800D295C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800D2960: jalr        $v0
    // 0x800D2964: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800D2964: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x800D2968: beq         $v0, $zero, L_800D299C
    if (ctx->r2 == 0) {
        // 0x800D296C: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_800D299C;
    }
    // 0x800D296C: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800D2970: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800D2974: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x800D2978: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x800D297C: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x800D2980: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800D2984: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D2988: jal         0x800D3A2C
    // 0x800D298C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x800D298C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_5:
    // 0x800D2990: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800D2994: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x800D2998: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800D299C:
    // 0x800D299C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_800D29A0:
    // 0x800D29A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D29A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D29A8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800D29AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800D29B0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800D29B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D29B8: nop

    // 0x800D29BC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D29C0: beql        $t7, $zero, L_800D2A10
    if (ctx->r15 == 0) {
        // 0x800D29C4: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_800D2A10;
    }
    goto skip_4;
    // 0x800D29C4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x800D29C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D29CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D29D0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D29D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D29D8: nop

    // 0x800D29DC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800D29E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D29E4: nop

    // 0x800D29E8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D29EC: bne         $t7, $zero, L_800D2A04
    if (ctx->r15 != 0) {
        // 0x800D29F0: nop
    
            goto L_800D2A04;
    }
    // 0x800D29F0: nop

    // 0x800D29F4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800D29F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D29FC: b           L_800D2A1C
    // 0x800D2A00: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800D2A1C;
    // 0x800D2A00: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800D2A04:
    // 0x800D2A04: b           L_800D2A1C
    // 0x800D2A08: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800D2A1C;
    // 0x800D2A08: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D2A0C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_800D2A10:
    // 0x800D2A10: nop

    // 0x800D2A14: bltz        $t7, L_800D2A04
    if (SIGNED(ctx->r15) < 0) {
        // 0x800D2A18: nop
    
            goto L_800D2A04;
    }
    // 0x800D2A18: nop

L_800D2A1C:
    // 0x800D2A1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2A20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D2A24: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x800D2A28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800D2A2C: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x800D2A30: lbu         $a2, 0x8($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X8);
    // 0x800D2A34: addiu       $s5, $s1, 0x48
    ctx->r21 = ADD32(ctx->r17, 0X48);
    // 0x800D2A38: beql        $a2, $zero, L_800D2AA8
    if (ctx->r6 == 0) {
        // 0x800D2A3C: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800D2AA8;
    }
    goto skip_5;
    // 0x800D2A3C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_5:
    // 0x800D2A40: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x800D2A44: beql        $v0, $zero, L_800D2AA8
    if (ctx->r2 == 0) {
        // 0x800D2A48: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800D2AA8;
    }
    goto skip_6;
    // 0x800D2A48: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_6:
    // 0x800D2A4C: lbu         $t9, 0xA($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XA);
    // 0x800D2A50: lbu         $a3, 0x9($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X9);
    // 0x800D2A54: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800D2A58: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D2A5C: lbu         $t6, 0xB($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XB);
    // 0x800D2A60: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800D2A64: jalr        $v0
    // 0x800D2A68: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800D2A68: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x800D2A6C: beq         $v0, $zero, L_800D2AA4
    if (ctx->r2 == 0) {
        // 0x800D2A70: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_800D2AA4;
    }
    // 0x800D2A70: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x800D2A74: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800D2A78: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x800D2A7C: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x800D2A80: sb          $s6, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r22;
    // 0x800D2A84: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2A88: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800D2A8C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D2A90: jal         0x800D3A2C
    // 0x800D2A94: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800D2A94: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_7:
    // 0x800D2A98: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800D2A9C: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x800D2AA0: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800D2AA4:
    // 0x800D2AA4: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
L_800D2AA8:
    // 0x800D2AA8: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D2AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2AB0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800D2AB4: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x800D2AB8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D2ABC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2AC0: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x800D2AC4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800D2AC8: lbu         $s2, 0xA($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0XA);
    // 0x800D2ACC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D2AD0: nop

    // 0x800D2AD4: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D2AD8: jal         0x800D25A4
    // 0x800D2ADC: nop

    __vsPan(rdram, ctx);
        goto after_8;
    // 0x800D2ADC: nop

    after_8:
    // 0x800D2AE0: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x800D2AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2AE8: jal         0x800D2184
    // 0x800D2AEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsVol(rdram, ctx);
        goto after_9;
    // 0x800D2AEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800D2AF0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800D2AF4: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2AF8: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x800D2AFC: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x800D2B00: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800D2B04: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800D2B08: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800D2B0C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800D2B10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D2B14: jal         0x800D4130
    // 0x800D2B18: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    alSynStartVoiceParams(rdram, ctx);
        goto after_10;
    // 0x800D2B18: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x800D2B1C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800D2B20: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800D2B24: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    // 0x800D2B28: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x800D2B2C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800D2B30: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2B34: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800D2B38: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x800D2B3C: sb          $t7, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r15;
    // 0x800D2B40: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800D2B44: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800D2B48: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x800D2B4C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800D2B50: lw          $s3, 0x0($t8)
    ctx->r19 = MEM_W(ctx->r24, 0X0);
    // 0x800D2B54: jal         0x800D3A2C
    // 0x800D2B58: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x800D2B58: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_11:
    // 0x800D2B5C: b           L_800D2FD8
    // 0x800D2B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2B64:
    // 0x800D2B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D2B68:
    // 0x800D2B68: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D2B6C: jal         0x800D25EC
    // 0x800D2B70: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_12;
    // 0x800D2B70: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_12:
    // 0x800D2B74: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D2B78: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D2B78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D2B7C: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x800D2B80: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800D2B84: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800D2B88: bne         $s6, $t7, L_800D2B98
    if (ctx->r22 != ctx->r15) {
        // 0x800D2B8C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D2B98;
    }
    // 0x800D2B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2B90: b           L_800D2FD4
    // 0x800D2B94: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_800D2FD4;
    // 0x800D2B94: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_800D2B98:
    // 0x800D2B98: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800D2B9C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800D2BA0: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800D2BA4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800D2BA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2BAC: jal         0x800D220C
    // 0x800D2BB0: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_13;
    // 0x800D2BB0: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_13:
    // 0x800D2BB4: b           L_800D2FD8
    // 0x800D2BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2BBC:
    // 0x800D2BBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2BC0: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800D2BC4: jal         0x800D25EC
    // 0x800D2BC8: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_14;
    // 0x800D2BC8: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_14:
    // 0x800D2BCC: beq         $v0, $zero, L_800D2FD4
    if (ctx->r2 == 0) {
        // 0x800D2BD0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D2FD4;
    }
    // 0x800D2BD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D2BD4: sb          $s4, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r20;
    // 0x800D2BD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2BDC: jal         0x800D2184
    // 0x800D2BE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsVol(rdram, ctx);
        goto after_15;
    // 0x800D2BE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x800D2BE4: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2BE8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D2BEC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D2BF0: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D2BF4: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x800D2BF8: bltz        $a0, L_800D2C08
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D2BFC: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_800D2C08;
    }
    // 0x800D2BFC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800D2C00: b           L_800D2C0C
    // 0x800D2C04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D2C0C;
    // 0x800D2C04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D2C08:
    // 0x800D2C08: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D2C0C:
    // 0x800D2C0C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2C10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2C14: jal         0x800D3DD0
    // 0x800D2C18: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_16;
    // 0x800D2C18: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_16:
    // 0x800D2C1C: b           L_800D2FD8
    // 0x800D2C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2C24:
    // 0x800D2C24: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2C28: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2C2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_7;
    // 0x800D2C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x800D2C30: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2C34: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800D2C38:
    // 0x800D2C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2C3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2C40: bnel        $s2, $t6, L_800D2C8C
    if (ctx->r18 != ctx->r14) {
        // 0x800D2C44: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2C8C;
    }
    goto skip_8;
    // 0x800D2C44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x800D2C48: jal         0x800D2184
    // 0x800D2C4C: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    __vsVol(rdram, ctx);
        goto after_17;
    // 0x800D2C4C: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    after_17:
    // 0x800D2C50: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2C54: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D2C58: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D2C5C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D2C60: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x800D2C64: bltz        $a0, L_800D2C74
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D2C68: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800D2C74;
    }
    // 0x800D2C68: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800D2C6C: b           L_800D2C78
    // 0x800D2C70: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D2C78;
    // 0x800D2C70: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D2C74:
    // 0x800D2C74: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D2C78:
    // 0x800D2C78: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2C7C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2C80: jal         0x800D3DD0
    // 0x800D2C84: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_18;
    // 0x800D2C84: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x800D2C88: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2C8C:
    // 0x800D2C8C: bnel        $s0, $zero, L_800D2C38
    if (ctx->r16 != 0) {
        // 0x800D2C90: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2C38;
    }
    goto skip_9;
    // 0x800D2C90: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_9:
    // 0x800D2C94: b           L_800D2FD8
    // 0x800D2C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2C9C:
    // 0x800D2C9C: slti        $at, $s3, 0x41
    ctx->r1 = SIGNED(ctx->r19) < 0X41 ? 1 : 0;
    // 0x800D2CA0: bne         $at, $zero, L_800D2CC4
    if (ctx->r1 != 0) {
        // 0x800D2CA4: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800D2CC4;
    }
    // 0x800D2CA4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800D2CA8: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800D2CAC: beq         $v0, $at, L_800D2EB8
    if (ctx->r2 == ctx->r1) {
        // 0x800D2CB0: addiu       $at, $zero, 0x5D
        ctx->r1 = ADD32(0, 0X5D);
            goto L_800D2EB8;
    }
    // 0x800D2CB0: addiu       $at, $zero, 0x5D
    ctx->r1 = ADD32(0, 0X5D);
    // 0x800D2CB4: beql        $v0, $at, L_800D2FD8
    if (ctx->r2 == ctx->r1) {
        // 0x800D2CB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_10;
    // 0x800D2CB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x800D2CBC: b           L_800D2FD8
    // 0x800D2CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2CC4:
    // 0x800D2CC4: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x800D2CC8: bne         $at, $zero, L_800D2CE4
    if (ctx->r1 != 0) {
        // 0x800D2CCC: addiu       $t9, $v0, -0x7
        ctx->r25 = ADD32(ctx->r2, -0X7);
            goto L_800D2CE4;
    }
    // 0x800D2CCC: addiu       $t9, $v0, -0x7
    ctx->r25 = ADD32(ctx->r2, -0X7);
    // 0x800D2CD0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800D2CD4: beql        $v0, $at, L_800D2E0C
    if (ctx->r2 == ctx->r1) {
        // 0x800D2CD8: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_800D2E0C;
    }
    goto skip_11;
    // 0x800D2CD8: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_11:
    // 0x800D2CDC: b           L_800D2FD8
    // 0x800D2CE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2CE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2CE4:
    // 0x800D2CE4: sltiu       $at, $t9, 0x15
    ctx->r1 = ctx->r25 < 0X15 ? 1 : 0;
    // 0x800D2CE8: beq         $at, $zero, L_800D2FD4
    if (ctx->r1 == 0) {
        // 0x800D2CEC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D2FD4;
    }
    // 0x800D2CEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D2CF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D2CF4: addu        $at, $at, $t9
    gpr jr_addend_800D2CFC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D2CF8: lw          $t9, 0x4F4($at)
    ctx->r25 = ADD32(ctx->r1, 0X4F4);
    // 0x800D2CFC: jr          $t9
    // 0x800D2D00: nop

    switch (jr_addend_800D2CFC >> 2) {
        case 0: goto L_800D2D60; break;
        case 1: goto L_800D2FD4; break;
        case 2: goto L_800D2FD4; break;
        case 3: goto L_800D2D04; break;
        case 4: goto L_800D2FD4; break;
        case 5: goto L_800D2FD4; break;
        case 6: goto L_800D2FD4; break;
        case 7: goto L_800D2FD4; break;
        case 8: goto L_800D2FD4; break;
        case 9: goto L_800D2DF4; break;
        case 10: goto L_800D2FD4; break;
        case 11: goto L_800D2FD4; break;
        case 12: goto L_800D2FD4; break;
        case 13: goto L_800D2FD4; break;
        case 14: goto L_800D2FD4; break;
        case 15: goto L_800D2FD4; break;
        case 16: goto L_800D2FD4; break;
        case 17: goto L_800D2FD4; break;
        case 18: goto L_800D2FD4; break;
        case 19: goto L_800D2FD4; break;
        case 20: goto L_800D2FD4; break;
        default: switch_error(__func__, 0x800D2CFC, 0x800F04F4);
    }
    // 0x800D2D00: nop

L_800D2D04:
    // 0x800D2D04: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x800D2D08: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x800D2D0C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800D2D10: sb          $s4, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r20;
    // 0x800D2D14: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2D18: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2D1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_12;
    // 0x800D2D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x800D2D20: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2D24: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800D2D28:
    // 0x800D2D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2D2C: bnel        $s2, $t9, L_800D2D50
    if (ctx->r18 != ctx->r25) {
        // 0x800D2D30: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2D50;
    }
    goto skip_13;
    // 0x800D2D30: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x800D2D34: jal         0x800D25A4
    // 0x800D2D38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsPan(rdram, ctx);
        goto after_19;
    // 0x800D2D38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_19:
    // 0x800D2D3C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2D40: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2D44: jal         0x800D4220
    // 0x800D2D48: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_20;
    // 0x800D2D48: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_20:
    // 0x800D2D4C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2D50:
    // 0x800D2D50: bnel        $s0, $zero, L_800D2D28
    if (ctx->r16 != 0) {
        // 0x800D2D54: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2D28;
    }
    goto skip_14;
    // 0x800D2D54: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x800D2D58: b           L_800D2FD8
    // 0x800D2D5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2D5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2D60:
    // 0x800D2D60: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x800D2D64: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x800D2D68: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800D2D6C: sb          $s4, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r20;
    // 0x800D2D70: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2D74: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2D78: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_15;
    // 0x800D2D78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x800D2D7C: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2D80: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800D2D84: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800D2D88:
    // 0x800D2D88: bnel        $s2, $t9, L_800D2DE4
    if (ctx->r18 != ctx->r25) {
        // 0x800D2D8C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2DE4;
    }
    goto skip_16;
    // 0x800D2D8C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x800D2D90: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800D2D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2D98: beql        $s3, $t6, L_800D2DE4
    if (ctx->r19 == ctx->r14) {
        // 0x800D2D9C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2DE4;
    }
    goto skip_17;
    // 0x800D2D9C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x800D2DA0: jal         0x800D2184
    // 0x800D2DA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __vsVol(rdram, ctx);
        goto after_21;
    // 0x800D2DA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_21:
    // 0x800D2DA8: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800D2DAC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D2DB0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D2DB4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D2DB8: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x800D2DBC: bltz        $a0, L_800D2DCC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D2DC0: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800D2DCC;
    }
    // 0x800D2DC0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800D2DC4: b           L_800D2DD0
    // 0x800D2DC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D2DD0;
    // 0x800D2DC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D2DCC:
    // 0x800D2DCC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D2DD0:
    // 0x800D2DD0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2DD4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2DD8: jal         0x800D3DD0
    // 0x800D2DDC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_22;
    // 0x800D2DDC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_22:
    // 0x800D2DE0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2DE4:
    // 0x800D2DE4: bnel        $s0, $zero, L_800D2D88
    if (ctx->r16 != 0) {
        // 0x800D2DE8: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2D88;
    }
    goto skip_18;
    // 0x800D2DE8: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x800D2DEC: b           L_800D2FD8
    // 0x800D2DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2DF4:
    // 0x800D2DF4: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2DF8: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800D2DFC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800D2E00: b           L_800D2FD4
    // 0x800D2E04: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
        goto L_800D2FD4;
    // 0x800D2E04: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
    // 0x800D2E08: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_800D2E0C:
    // 0x800D2E0C: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x800D2E10: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800D2E14: sb          $s4, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r20;
    // 0x800D2E18: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2E1C: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2E20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_19;
    // 0x800D2E20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x800D2E24: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2E28: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800D2E2C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800D2E30: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800D2E34: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800D2E38: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800D2E3C: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_800D2E40:
    // 0x800D2E40: bnel        $s2, $t8, L_800D2EA8
    if (ctx->r18 != ctx->r24) {
        // 0x800D2E44: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_20;
    // 0x800D2E44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x800D2E48: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800D2E4C: slti        $at, $s4, 0x40
    ctx->r1 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // 0x800D2E50: beql        $s3, $v0, L_800D2EA8
    if (ctx->r19 == ctx->r2) {
        // 0x800D2E54: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_21;
    // 0x800D2E54: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x800D2E58: bne         $at, $zero, L_800D2E70
    if (ctx->r1 != 0) {
        // 0x800D2E5C: nop
    
            goto L_800D2E70;
    }
    // 0x800D2E5C: nop

    // 0x800D2E60: bnel        $v0, $zero, L_800D2EA8
    if (ctx->r2 != 0) {
        // 0x800D2E64: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_22;
    // 0x800D2E64: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x800D2E68: b           L_800D2EA4
    // 0x800D2E6C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800D2EA4;
    // 0x800D2E6C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_800D2E70:
    // 0x800D2E70: bne         $s6, $v0, L_800D2E80
    if (ctx->r22 != ctx->r2) {
        // 0x800D2E74: nop
    
            goto L_800D2E80;
    }
    // 0x800D2E74: nop

    // 0x800D2E78: b           L_800D2EA4
    // 0x800D2E7C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_800D2EA4;
    // 0x800D2E7C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800D2E80:
    // 0x800D2E80: bnel        $s7, $v0, L_800D2EA8
    if (ctx->r23 != ctx->r2) {
        // 0x800D2E84: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EA8;
    }
    goto skip_23;
    // 0x800D2E84: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x800D2E88: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800D2E8C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800D2E90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2E94: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800D2E98: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2E9C: jal         0x800D220C
    // 0x800D2EA0: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    __seqpReleaseVoice(rdram, ctx);
        goto after_23;
    // 0x800D2EA0: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    after_23:
L_800D2EA4:
    // 0x800D2EA4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2EA8:
    // 0x800D2EA8: bnel        $s0, $zero, L_800D2E40
    if (ctx->r16 != 0) {
        // 0x800D2EAC: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2E40;
    }
    goto skip_24;
    // 0x800D2EAC: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x800D2EB0: b           L_800D2FD8
    // 0x800D2EB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2EB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2EB8:
    // 0x800D2EB8: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x800D2EBC: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x800D2EC0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800D2EC4: sb          $s4, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r20;
    // 0x800D2EC8: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2ECC: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2ED0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_25;
    // 0x800D2ED0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x800D2ED4: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2ED8: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800D2EDC:
    // 0x800D2EDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2EE0: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800D2EE4: bnel        $s2, $t9, L_800D2EF8
    if (ctx->r18 != ctx->r25) {
        // 0x800D2EE8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2EF8;
    }
    goto skip_26;
    // 0x800D2EE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x800D2EEC: jal         0x800D42B0
    // 0x800D2EF0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    alSynSetFXMix(rdram, ctx);
        goto after_24;
    // 0x800D2EF0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_24:
    // 0x800D2EF4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2EF8:
    // 0x800D2EF8: bnel        $s0, $zero, L_800D2EDC
    if (ctx->r16 != 0) {
        // 0x800D2EFC: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2EDC;
    }
    goto skip_27;
    // 0x800D2EFC: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x800D2F00: b           L_800D2FD8
    // 0x800D2F04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2F04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2F08:
    // 0x800D2F08: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800D2F0C: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x800D2F10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2F14: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800D2F18: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800D2F1C: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x800D2F20: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D2F24: beql        $at, $zero, L_800D2FD8
    if (ctx->r1 == 0) {
        // 0x800D2F28: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_28;
    // 0x800D2F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x800D2F2C: jal         0x800D1FD0
    // 0x800D2F30: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    __setInstChanState(rdram, ctx);
        goto after_25;
    // 0x800D2F30: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    after_25:
    // 0x800D2F34: b           L_800D2FD8
    // 0x800D2F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D2FD8;
    // 0x800D2F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2F3C:
    // 0x800D2F3C: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2F40: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800D2F44: sll         $t7, $s4, 7
    ctx->r15 = S32(ctx->r20 << 7);
    // 0x800D2F48: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800D2F4C: lh          $t8, 0x4($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X4);
    // 0x800D2F50: addu        $t9, $t7, $s3
    ctx->r25 = ADD32(ctx->r15, ctx->r19);
    // 0x800D2F54: addiu       $t6, $t9, -0x2000
    ctx->r14 = ADD32(ctx->r25, -0X2000);
    // 0x800D2F58: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2F5C: mflo        $a0
    ctx->r4 = lo;
    // 0x800D2F60: bgez        $a0, L_800D2F70
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D2F64: sra         $t7, $a0, 13
        ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
            goto L_800D2F70;
    }
    // 0x800D2F64: sra         $t7, $a0, 13
    ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
    // 0x800D2F68: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x800D2F6C: sra         $t7, $at, 13
    ctx->r15 = S32(SIGNED(ctx->r1) >> 13);
L_800D2F70:
    // 0x800D2F70: jal         0x800CADC0
    // 0x800D2F74: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_26;
    // 0x800D2F74: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_26:
    // 0x800D2F78: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800D2F7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D2F80: addu        $t8, $t9, $fp
    ctx->r24 = ADD32(ctx->r25, ctx->r30);
    // 0x800D2F84: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x800D2F88: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800D2F8C: beql        $s0, $zero, L_800D2FD8
    if (ctx->r16 == 0) {
        // 0x800D2F90: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2FD8;
    }
    goto skip_29;
    // 0x800D2F90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x800D2F94: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800D2F98: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800D2F9C:
    // 0x800D2F9C: bnel        $s2, $t6, L_800D2FCC
    if (ctx->r18 != ctx->r14) {
        // 0x800D2FA0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2FCC;
    }
    goto skip_30;
    // 0x800D2FA0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
    // 0x800D2FA4: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D2FA8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D2FAC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800D2FB0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800D2FB4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800D2FB8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D2FBC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800D2FC0: jal         0x800D3E70
    // 0x800D2FC4: nop

    alSynSetPitch(rdram, ctx);
        goto after_27;
    // 0x800D2FC4: nop

    after_27:
    // 0x800D2FC8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2FCC:
    // 0x800D2FCC: bnel        $s0, $zero, L_800D2F9C
    if (ctx->r16 != 0) {
        // 0x800D2FD0: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800D2F9C;
    }
    goto skip_31;
    // 0x800D2FD0: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_800D2FD4:
    // 0x800D2FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2FD8:
    // 0x800D2FD8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x800D2FDC: jr          $ra
    // 0x800D2FE0: nop

    return;
    // 0x800D2FE0: nop

    // 0x800D2FE4: jr          $ra
    // 0x800D2FE8: nop

    return;
    // 0x800D2FE8: nop

    // 0x800D2FEC: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800D2FF0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D2FF4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D2FF8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800D2FFC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D3000: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D3004: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D3008: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D300C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D3010: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D3014: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D3018: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D301C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D3020: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D3024: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800D3028: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_800D302C:
    // 0x800D302C: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x800D3030: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800D3034: beq         $at, $zero, L_800D35BC
    if (ctx->r1 == 0) {
        // 0x800D3038: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800D35BC;
    }
    // 0x800D3038: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D303C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D3040: addu        $at, $at, $t7
    gpr jr_addend_800D3048 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D3044: lw          $t7, 0x548($at)
    ctx->r15 = ADD32(ctx->r1, 0X548);
    // 0x800D3048: jr          $t7
    // 0x800D304C: nop

    switch (jr_addend_800D3048 >> 2) {
        case 0: goto L_800D3050; break;
        case 1: goto L_800D35BC; break;
        case 2: goto L_800D3364; break;
        case 3: goto L_800D35BC; break;
        case 4: goto L_800D35BC; break;
        case 5: goto L_800D311C; break;
        case 6: goto L_800D3168; break;
        case 7: goto L_800D3384; break;
        case 8: goto L_800D35BC; break;
        case 9: goto L_800D30FC; break;
        case 10: goto L_800D34BC; break;
        case 11: goto L_800D3524; break;
        case 12: goto L_800D3540; break;
        case 13: goto L_800D355C; break;
        case 14: goto L_800D35AC; break;
        case 15: goto L_800D3398; break;
        case 16: goto L_800D33BC; break;
        case 17: goto L_800D342C; break;
        case 18: goto L_800D35BC; break;
        case 19: goto L_800D35BC; break;
        case 20: goto L_800D35BC; break;
        case 21: goto L_800D35BC; break;
        case 22: goto L_800D31CC; break;
        case 23: goto L_800D32DC; break;
        default: switch_error(__func__, 0x800D3048, 0x800F0548);
    }
    // 0x800D304C: nop

L_800D3050:
    // 0x800D3050: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x800D3054: beql        $a0, $zero, L_800D35C0
    if (ctx->r4 == 0) {
        // 0x800D3058: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_32;
    // 0x800D3058: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_32:
    // 0x800D305C: jal         0x800D6434
    // 0x800D3060: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    alSeqNextEvent(rdram, ctx);
        goto after_28;
    // 0x800D3060: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_28:
    // 0x800D3064: lh          $v0, 0x88($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X88);
    // 0x800D3068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D306C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800D3070: beq         $v0, $at, L_800D3098
    if (ctx->r2 == ctx->r1) {
        // 0x800D3074: addiu       $a0, $sp, 0x88
        ctx->r4 = ADD32(ctx->r29, 0X88);
            goto L_800D3098;
    }
    // 0x800D3074: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800D3078: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D307C: beq         $v0, $at, L_800D30BC
    if (ctx->r2 == ctx->r1) {
        // 0x800D3080: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800D30BC;
    }
    // 0x800D3080: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D3084: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D3088: beq         $v0, $at, L_800D30D4
    if (ctx->r2 == ctx->r1) {
        // 0x800D308C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_800D30D4;
    }
    // 0x800D308C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800D3090: b           L_800D35C0
    // 0x800D3094: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3094: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3098:
    // 0x800D3098: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x800D309C: jal         0x800D27CC
    // 0x800D30A0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_800D27CC(rdram, ctx);
        goto after_29;
    // 0x800D30A0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_29:
    // 0x800D30A4: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x800D30A8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800D30AC: jal         0x800D2450
    // 0x800D30B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __postNextSeqEvent(rdram, ctx);
        goto after_30;
    // 0x800D30B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x800D30B4: b           L_800D35C0
    // 0x800D30B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D30B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D30BC:
    // 0x800D30BC: jal         0x800D252C
    // 0x800D30C0: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_800D252C(rdram, ctx);
        goto after_31;
    // 0x800D30C0: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_31:
    // 0x800D30C4: jal         0x800D2450
    // 0x800D30C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __postNextSeqEvent(rdram, ctx);
        goto after_32;
    // 0x800D30C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_32:
    // 0x800D30CC: b           L_800D35C0
    // 0x800D30D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D30D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D30D4:
    // 0x800D30D4: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x800D30D8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800D30DC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800D30E0: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x800D30E4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800D30E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D30EC: jal         0x800D3A2C
    // 0x800D30F0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    alEvtqPostEvent(rdram, ctx);
        goto after_33;
    // 0x800D30F0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_33:
    // 0x800D30F4: b           L_800D35C0
    // 0x800D30F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D30F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D30FC:
    // 0x800D30FC: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x800D3100: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x800D3104: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x800D3108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D310C: jal         0x800D3A2C
    // 0x800D3110: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    alEvtqPostEvent(rdram, ctx);
        goto after_34;
    // 0x800D3110: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_34:
    // 0x800D3114: b           L_800D35C0
    // 0x800D3118: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3118: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D311C:
    // 0x800D311C: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800D3120: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3124: jal         0x800D3CA0
    // 0x800D3128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_35;
    // 0x800D3128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_35:
    // 0x800D312C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3130: jal         0x800D3D20
    // 0x800D3134: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_36;
    // 0x800D3134: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_36:
    // 0x800D3138: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800D313C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D3140: lbu         $t7, 0x37($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X37);
    // 0x800D3144: beql        $t7, $zero, L_800D3158
    if (ctx->r15 == 0) {
        // 0x800D3148: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D3158;
    }
    goto skip_33;
    // 0x800D3148: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_33:
    // 0x800D314C: jal         0x800D3610
    // 0x800D3150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_37;
    // 0x800D3150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_37:
    // 0x800D3154: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D3158:
    // 0x800D3158: jal         0x800D23E0
    // 0x800D315C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_38;
    // 0x800D315C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_38:
    // 0x800D3160: b           L_800D35C0
    // 0x800D3164: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3164: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3168:
    // 0x800D3168: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800D316C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D3170: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800D3174: lbu         $t8, 0x34($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X34);
    // 0x800D3178: bnel        $t8, $zero, L_800D3188
    if (ctx->r24 != 0) {
        // 0x800D317C: lbu         $t6, 0x44($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X44);
            goto L_800D3188;
    }
    goto skip_34;
    // 0x800D317C: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    skip_34:
    // 0x800D3180: sb          $t9, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r25;
    // 0x800D3184: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
L_800D3188:
    // 0x800D3188: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    // 0x800D318C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3190: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    // 0x800D3194: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x800D3198: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D319C: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x800D31A0: jal         0x800D2184
    // 0x800D31A4: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    __vsVol(rdram, ctx);
        goto after_39;
    // 0x800D31A4: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    after_39:
    // 0x800D31A8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D31AC: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D31B0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800D31B4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D31B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D31BC: jal         0x800D3DD0
    // 0x800D31C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    alSynSetVol(rdram, ctx);
        goto after_40;
    // 0x800D31C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_40:
    // 0x800D31C4: b           L_800D35C0
    // 0x800D31C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D31C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D31CC:
    // 0x800D31CC: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800D31D0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800D31D4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800D31D8: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800D31DC: jalr        $t9
    // 0x800D31E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_41;
    // 0x800D31E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_41:
    // 0x800D31E4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800D31E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D31EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D31F0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800D31F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D31F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800D31FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800D3200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3204: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D3208: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D320C: nop

    // 0x800D3210: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D3214: beql        $t7, $zero, L_800D3264
    if (ctx->r15 == 0) {
        // 0x800D3218: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_800D3264;
    }
    goto skip_35;
    // 0x800D3218: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_35:
    // 0x800D321C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D3220: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D3224: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D3228: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D322C: nop

    // 0x800D3230: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800D3234: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D3238: nop

    // 0x800D323C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800D3240: bne         $t7, $zero, L_800D3258
    if (ctx->r15 != 0) {
        // 0x800D3244: nop
    
            goto L_800D3258;
    }
    // 0x800D3244: nop

    // 0x800D3248: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800D324C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D3250: b           L_800D3270
    // 0x800D3254: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800D3270;
    // 0x800D3254: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800D3258:
    // 0x800D3258: b           L_800D3270
    // 0x800D325C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800D3270;
    // 0x800D325C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D3260: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_800D3264:
    // 0x800D3264: nop

    // 0x800D3268: bltz        $t7, L_800D3258
    if (SIGNED(ctx->r15) < 0) {
        // 0x800D326C: nop
    
            goto L_800D3258;
    }
    // 0x800D326C: nop

L_800D3270:
    // 0x800D3270: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800D3274: jal         0x800D2184
    // 0x800D3278: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    __vsVol(rdram, ctx);
        goto after_42;
    // 0x800D3278: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    after_42:
    // 0x800D327C: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x800D3280: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x800D3284: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D3288: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D328C: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x800D3290: bltz        $a0, L_800D32A0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D3294: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800D32A0;
    }
    // 0x800D3294: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800D3298: b           L_800D32A4
    // 0x800D329C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D32A4;
    // 0x800D329C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D32A0:
    // 0x800D32A0: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D32A4:
    // 0x800D32A4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D32A8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800D32AC: jal         0x800D3DD0
    // 0x800D32B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_43;
    // 0x800D32B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_43:
    // 0x800D32B4: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x800D32B8: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x800D32BC: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x800D32C0: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x800D32C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D32C8: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800D32CC: jal         0x800D3A2C
    // 0x800D32D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_44;
    // 0x800D32D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_44:
    // 0x800D32D4: b           L_800D35C0
    // 0x800D32D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D32D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D32DC:
    // 0x800D32DC: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800D32E0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800D32E4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800D32E8: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800D32EC: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800D32F0: jalr        $t9
    // 0x800D32F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_45;
    // 0x800D32F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_45:
    // 0x800D32F8: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800D32FC: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800D3300: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x800D3304: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800D3308: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800D330C: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800D3310: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D3314: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800D3318: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800D331C: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800D3320: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3324: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800D3328: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800D332C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800D3330: jal         0x800D3E70
    // 0x800D3334: nop

    alSynSetPitch(rdram, ctx);
        goto after_46;
    // 0x800D3334: nop

    after_46:
    // 0x800D3338: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x800D333C: sh          $t9, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r25;
    // 0x800D3340: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x800D3344: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x800D3348: sb          $s0, 0xC8($sp)
    MEM_B(0XC8, ctx->r29) = ctx->r16;
    // 0x800D334C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D3350: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800D3354: jal         0x800D3A2C
    // 0x800D3358: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_47;
    // 0x800D3358: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_47:
    // 0x800D335C: b           L_800D35C0
    // 0x800D3360: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3360: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3364:
    // 0x800D3364: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800D3368: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800D336C: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x800D3370: jal         0x800D27CC
    // 0x800D3374: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_800D27CC(rdram, ctx);
        goto after_48;
    // 0x800D3374: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_48:
    // 0x800D3378: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x800D337C: b           L_800D35BC
    // 0x800D3380: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_800D35BC;
    // 0x800D3380: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_800D3384:
    // 0x800D3384: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D3388: jal         0x800D252C
    // 0x800D338C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800D252C(rdram, ctx);
        goto after_49;
    // 0x800D338C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_49:
    // 0x800D3390: b           L_800D35C0
    // 0x800D3394: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3394: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3398:
    // 0x800D3398: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x800D339C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D33A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D33A4: beq         $t7, $at, L_800D35BC
    if (ctx->r15 == ctx->r1) {
        // 0x800D33A8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D35BC;
    }
    // 0x800D33A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D33AC: jal         0x800D2450
    // 0x800D33B0: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    __postNextSeqEvent(rdram, ctx);
        goto after_50;
    // 0x800D33B0: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    after_50:
    // 0x800D33B4: b           L_800D35C0
    // 0x800D33B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D33B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D33BC:
    // 0x800D33BC: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x800D33C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D33C4: bnel        $t6, $at, L_800D35C0
    if (ctx->r14 != ctx->r1) {
        // 0x800D33C8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_36;
    // 0x800D33C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_36:
    // 0x800D33CC: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D33D0: beq         $s1, $zero, L_800D3420
    if (ctx->r17 == 0) {
        // 0x800D33D4: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D3420;
    }
    // 0x800D33D4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800D33D8:
    // 0x800D33D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D33DC: jal         0x800D3CA0
    // 0x800D33E0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    alSynStopVoice(rdram, ctx);
        goto after_51;
    // 0x800D33E0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_51:
    // 0x800D33E4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D33E8: jal         0x800D3D20
    // 0x800D33EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_52;
    // 0x800D33EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_52:
    // 0x800D33F0: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x800D33F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D33F8: beql        $t9, $zero, L_800D340C
    if (ctx->r25 == 0) {
        // 0x800D33FC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D340C;
    }
    goto skip_37;
    // 0x800D33FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_37:
    // 0x800D3400: jal         0x800D3610
    // 0x800D3404: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_53;
    // 0x800D3404: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_53:
    // 0x800D3408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D340C:
    // 0x800D340C: jal         0x800D23E0
    // 0x800D3410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_54;
    // 0x800D3410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_54:
    // 0x800D3414: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D3418: bnel        $s1, $zero, L_800D33D8
    if (ctx->r17 != 0) {
        // 0x800D341C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D33D8;
    }
    goto skip_38;
    // 0x800D341C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_38:
L_800D3420:
    // 0x800D3420: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
    // 0x800D3424: b           L_800D35BC
    // 0x800D3428: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_800D35BC;
    // 0x800D3428: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_800D342C:
    // 0x800D342C: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x800D3430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D3434: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D3438: bnel        $t7, $at, L_800D35C0
    if (ctx->r15 != ctx->r1) {
        // 0x800D343C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_39;
    // 0x800D343C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_39:
    // 0x800D3440: jal         0x800D3910
    // 0x800D3444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_55;
    // 0x800D3444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_55:
    // 0x800D3448: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D344C: jal         0x800D3910
    // 0x800D3450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_56;
    // 0x800D3450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_56:
    // 0x800D3454: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D3458: beq         $s1, $zero, L_800D3490
    if (ctx->r17 == 0) {
        // 0x800D345C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D3490;
    }
    // 0x800D345C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800D3460:
    // 0x800D3460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D3464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D3468: jal         0x800D2338
    // 0x800D346C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_57;
    // 0x800D346C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_57:
    // 0x800D3470: beq         $v0, $zero, L_800D3484
    if (ctx->r2 == 0) {
        // 0x800D3474: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D3484;
    }
    // 0x800D3474: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D3478: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D347C: jal         0x800D220C
    // 0x800D3480: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __seqpReleaseVoice(rdram, ctx);
        goto after_58;
    // 0x800D3480: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_58:
L_800D3484:
    // 0x800D3484: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800D3488: bnel        $s1, $zero, L_800D3460
    if (ctx->r17 != 0) {
        // 0x800D348C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800D3460;
    }
    goto skip_40;
    // 0x800D348C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_40:
L_800D3490:
    // 0x800D3490: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800D3494: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x800D3498: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800D349C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800D34A0: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x800D34A4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800D34A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D34AC: jal         0x800D3A2C
    // 0x800D34B0: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    alEvtqPostEvent(rdram, ctx);
        goto after_59;
    // 0x800D34B0: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_59:
    // 0x800D34B4: b           L_800D35C0
    // 0x800D34B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D34B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D34BC:
    // 0x800D34BC: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800D34C0: lh          $t9, 0x3C($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X3C);
    // 0x800D34C4: beq         $s1, $zero, L_800D35BC
    if (ctx->r17 == 0) {
        // 0x800D34C8: sh          $t9, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r25;
            goto L_800D35BC;
    }
    // 0x800D34C8: sh          $t9, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r25;
    // 0x800D34CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D34D0:
    // 0x800D34D0: jal         0x800D2184
    // 0x800D34D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_60;
    // 0x800D34D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_60:
    // 0x800D34D8: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x800D34DC: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x800D34E0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D34E4: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D34E8: subu        $a0, $t8, $v1
    ctx->r4 = SUB32(ctx->r24, ctx->r3);
    // 0x800D34EC: bltz        $a0, L_800D34FC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D34F0: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_800D34FC;
    }
    // 0x800D34F0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800D34F4: b           L_800D3500
    // 0x800D34F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D3500;
    // 0x800D34F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D34FC:
    // 0x800D34FC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800D3500:
    // 0x800D3500: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800D3504: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800D3508: jal         0x800D3DD0
    // 0x800D350C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_61;
    // 0x800D350C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_61:
    // 0x800D3510: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800D3514: bnel        $s1, $zero, L_800D34D0
    if (ctx->r17 != 0) {
        // 0x800D3518: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D34D0;
    }
    goto skip_41;
    // 0x800D3518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_41:
    // 0x800D351C: b           L_800D35C0
    // 0x800D3520: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D3520: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D3524:
    // 0x800D3524: lw          $t6, 0x3C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X3C);
    // 0x800D3528: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x800D352C: lw          $t7, 0x44($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X44);
    // 0x800D3530: sw          $t6, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r14;
    // 0x800D3534: sw          $t9, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r25;
    // 0x800D3538: b           L_800D35BC
    // 0x800D353C: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
        goto L_800D35BC;
    // 0x800D353C: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
L_800D3540:
    // 0x800D3540: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x800D3544: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x800D3548: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x800D354C: sll         $t9, $s0, 4
    ctx->r25 = S32(ctx->r16 << 4);
    // 0x800D3550: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800D3554: b           L_800D35BC
    // 0x800D3558: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_800D35BC;
    // 0x800D3558: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_800D355C:
    // 0x800D355C: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x800D3560: addiu       $t7, $zero, 0x1E8
    ctx->r15 = ADD32(0, 0X1E8);
    // 0x800D3564: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D3568: beq         $a1, $zero, L_800D358C
    if (ctx->r5 == 0) {
        // 0x800D356C: sw          $a1, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r5;
            goto L_800D358C;
    }
    // 0x800D356C: sw          $a1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r5;
    // 0x800D3570: lwc1        $f6, 0x5A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A8);
    // 0x800D3574: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800D3578: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D357C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D3580: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800D3584: b           L_800D3590
    // 0x800D3588: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
        goto L_800D3590;
    // 0x800D3588: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
L_800D358C:
    // 0x800D358C: sw          $t7, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r15;
L_800D3590:
    // 0x800D3590: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x800D3594: beql        $a1, $zero, L_800D35C0
    if (ctx->r5 == 0) {
        // 0x800D3598: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D35C0;
    }
    goto skip_42;
    // 0x800D3598: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_42:
    // 0x800D359C: jal         0x800D20A4
    // 0x800D35A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_62;
    // 0x800D35A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_62:
    // 0x800D35A4: b           L_800D35C0
    // 0x800D35A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800D35C0;
    // 0x800D35A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D35AC:
    // 0x800D35AC: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x800D35B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D35B4: jal         0x800D20A4
    // 0x800D35B8: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_63;
    // 0x800D35B8: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_63:
L_800D35BC:
    // 0x800D35BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800D35C0:
    // 0x800D35C0: jal         0x800D3B50
    // 0x800D35C4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    alEvtqNextEvent(rdram, ctx);
        goto after_64;
    // 0x800D35C4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_64:
    // 0x800D35C8: beq         $v0, $zero, L_800D302C
    if (ctx->r2 == 0) {
        // 0x800D35CC: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800D302C;
    }
    // 0x800D35CC: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x800D35D0: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x800D35D4: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800D35D8: sw          $t9, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r25;
    // 0x800D35DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D35E0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D35E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D35E8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D35EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D35F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D35F4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D35F8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D35FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D3600: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D3604: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D3608: jr          $ra
    // 0x800D360C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800D360C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_800D3904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3904: nop

    // 0x800D3908: nop

    // 0x800D390C: nop

;}
RECOMP_FUNC void func_800D3D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D18: nop

    // 0x800D3D1C: nop

;}
RECOMP_FUNC void func_800D3E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E6C: nop

;}
RECOMP_FUNC void func_800D3EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3EF4: nop

    // 0x800D3EF8: nop

    // 0x800D3EFC: nop

;}
RECOMP_FUNC void func_800D4128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4128: nop

    // 0x800D412C: nop

;}
RECOMP_FUNC void func_800D4214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4214: nop

    // 0x800D4218: nop

    // 0x800D421C: nop

;}
RECOMP_FUNC void func_800D42A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D42A4: nop

    // 0x800D42A8: nop

    // 0x800D42AC: nop

;}
RECOMP_FUNC void func_800D4344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4344: nop

    // 0x800D4348: nop

    // 0x800D434C: nop

;}
RECOMP_FUNC void func_800D43DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D43DC: nop

    // 0x800D43E0: nop

    // 0x800D43E4: nop

    // 0x800D43E8: nop

    // 0x800D43EC: nop

    // 0x800D43F0: nop

    // 0x800D43F4: nop

    // 0x800D43F8: nop

    // 0x800D43FC: nop

    // 0x800D4400: nop

    // 0x800D4404: nop

    // 0x800D4408: nop

    // 0x800D440C: nop

    // 0x800D4410: nop

    // 0x800D4414: nop

    // 0x800D4418: nop

    // 0x800D441C: nop

;}
RECOMP_FUNC void func_800D443C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D443C: nop

;}
RECOMP_FUNC void func_800D44EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D44EC: nop

;}
RECOMP_FUNC void func_800D4564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4564: nop

    // 0x800D4568: nop

    // 0x800D456C: nop

;}
RECOMP_FUNC void func_800D45C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D45C8: nop

    // 0x800D45CC: nop

;}
RECOMP_FUNC void func_800D4624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4624: nop

    // 0x800D4628: nop

    // 0x800D462C: nop

;}
RECOMP_FUNC void func_800D46CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D46CC: nop

;}
RECOMP_FUNC void func_800D4F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4F94: nop

    // 0x800D4F98: nop

    // 0x800D4F9C: nop

;}
RECOMP_FUNC void func_800D54FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D54FC: nop

;}
RECOMP_FUNC void func_800D552C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D552C: nop

;}
RECOMP_FUNC void func_800D56CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D56CC: nop

;}
RECOMP_FUNC void func_800D631C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D631C: nop

;}
RECOMP_FUNC void func_800D6394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6394: nop

    // 0x800D6398: nop

    // 0x800D639C: nop

;}
RECOMP_FUNC void func_800D63E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D63E0: jr          $ra
    // 0x800D63E4: nop

    return;
    // 0x800D63E4: nop

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
RECOMP_FUNC void func_800D6868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6868: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800D686C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800D6870: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x800D6874: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800D6878: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D687C: sll         $t6, $v1, 24
    ctx->r14 = S32(ctx->r3 << 24);
    // 0x800D6880: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D6884: or          $v1, $t6, $t9
    ctx->r3 = ctx->r14 | ctx->r25;
    // 0x800D6888: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800D688C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D6890: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800D6894: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D6898: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800D689C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800D68A0: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x800D68A4: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x800D68A8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800D68AC: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800D68B0: jr          $ra
    // 0x800D68B4: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
    return;
    // 0x800D68B4: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
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
RECOMP_FUNC void func_800D6ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6ABC: nop

;}
RECOMP_FUNC void func_800D6B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6B18: nop

    // 0x800D6B1C: nop

;}
RECOMP_FUNC void func_800D6B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6B6C: nop

;}
RECOMP_FUNC void func_800E8CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8CB0: nop

;}
RECOMP_FUNC void func_800ECBF5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECBF5: nop

    // 0x800ECBF9: nop

    // 0x800ECBFD: nop

    // 0x800ECC01: nop

    // 0x800ECC05: nop

    // 0x800ECC09: nop

;}
RECOMP_FUNC void func_800ECC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC14: nop

    // 0x800ECC18: nop

    // 0x800ECC1C: nop

;}
RECOMP_FUNC void func_800ECC24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC24: nop

    // 0x800ECC28: nop

    // 0x800ECC2C: nop

    // 0x800ECC30: nop

    // 0x800ECC34: nop

    // 0x800ECC38: nop

    // 0x800ECC3C: nop

;}
RECOMP_FUNC void func_800ECC59(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC59: nop

;}
RECOMP_FUNC void func_800ECC65(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC65: nop

    // 0x800ECC69: nop

    // 0x800ECC6D: nop

    // 0x800ECC71: nop

    // 0x800ECC75: nop

;}
RECOMP_FUNC void func_800ECC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC80: nop

    // 0x800ECC84: nop

    // 0x800ECC88: nop

    // 0x800ECC8C: nop

    // 0x800ECC90: nop

    // 0x800ECC94: nop

    // 0x800ECC98: nop

    // 0x800ECC9C: nop

    // 0x800ECCA0: nop

    // 0x800ECCA4: nop

    // 0x800ECCA8: nop

    // 0x800ECCAC: nop

    // 0x800ECCB0: nop

    // 0x800ECCB4: nop

    // 0x800ECCB8: nop

    // 0x800ECCBC: nop

    // 0x800ECCC0: nop

    // 0x800ECCC4: nop

    // 0x800ECCC8: nop

    // 0x800ECCCC: nop

    // 0x800ECCD0: nop

    // 0x800ECCD4: nop

    // 0x800ECCD8: nop

    // 0x800ECCDC: nop

;}
RECOMP_FUNC void func_800ECCEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECCEC: nop

;}
RECOMP_FUNC void func_800ECCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECCF4: nop

    // 0x800ECCF8: nop

    // 0x800ECCFC: nop

;}
RECOMP_FUNC void func_800ECD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECD18: nop

    // 0x800ECD1C: nop

;}
RECOMP_FUNC void func_800ECD25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECD25: nop

    // 0x800ECD29: nop

    // 0x800ECD2D: nop

    // 0x800ECD31: nop

    // 0x800ECD35: nop

    // 0x800ECD39: nop

;}
RECOMP_FUNC void func_800ED024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED024: nop

    // 0x800ED028: nop

    // 0x800ED02C: nop

;}
RECOMP_FUNC void func_800EF790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF790: lb          $t1, -0x7CB0($zero)
    ctx->r9 = MEM_B(0, -0X7CB0);
    // 0x800EF794: lb          $t1, -0x7DA0($zero)
    ctx->r9 = MEM_B(0, -0X7DA0);
    // 0x800EF798: lb          $t1, -0x7F00($zero)
    ctx->r9 = MEM_B(0, -0X7F00);
    // 0x800EF79C: lb          $t1, -0x7CB0($zero)
    ctx->r9 = MEM_B(0, -0X7CB0);
    // 0x800EF7A0: lb          $t1, -0x7CB0($zero)
    ctx->r9 = MEM_B(0, -0X7CB0);
    // 0x800EF7A4: lb          $t1, -0x7DA0($zero)
    ctx->r9 = MEM_B(0, -0X7DA0);
    // 0x800EF7A8: lb          $t1, -0x7DA0($zero)
    ctx->r9 = MEM_B(0, -0X7DA0);
    // 0x800EF7AC: nop

;}
