#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void static_1_800D13E4(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void static_1_800D167C(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void static_1_800D63E8(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void static_1_800D68B8(uint8_t* rdram, recomp_context* ctx) {
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
