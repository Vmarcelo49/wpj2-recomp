#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void _saveBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5830: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D5834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D5838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D583C: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800D5840: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800D5844: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800D5848: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800D584C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800D5850: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D5854: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x800D5858: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800D585C: beq         $at, $zero, L_800D5868
    if (ctx->r1 == 0) {
        // 0x800D5860: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_800D5868;
    }
    // 0x800D5860: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x800D5864: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_800D5868:
    // 0x800D5868: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x800D586C: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x800D5870: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x800D5874: beq         $at, $zero, L_800D5968
    if (ctx->r1 == 0) {
        // 0x800D5878: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_800D5968;
    }
    // 0x800D5878: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D587C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x800D5880: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800D5884: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800D5888: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800D588C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800D5890: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x800D5894: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800D5898: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D589C: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D58A0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D58A4: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x800D58A8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800D58AC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800D58B0: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800D58B4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800D58B8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D58BC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800D58C0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800D58C4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800D58C8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800D58CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D58D0: jal         0x800C79C0
    // 0x800D58D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800D58D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D58D8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800D58DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D58E0: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D58E4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800D58E8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800D58EC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800D58F0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D58F4: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800D58F8: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800D58FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D5900: subu        $t7, $a3, $t1
    ctx->r15 = SUB32(ctx->r7, ctx->r9);
    // 0x800D5904: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800D5908: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800D590C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800D5910: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800D5914: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800D5918: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D591C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D5920: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D5924: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D5928: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800D592C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800D5930: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x800D5934: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800D5938: jal         0x800C79C0
    // 0x800D593C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800D593C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x800D5940: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800D5944: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800D5948: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D594C: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x800D5950: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800D5954: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800D5958: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D595C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D5960: b           L_800D59A4
    // 0x800D5964: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800D59A4;
    // 0x800D5964: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800D5968:
    // 0x800D5968: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x800D596C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800D5970: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800D5974: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800D5978: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D597C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800D5980: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D5984: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800D5988: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D598C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800D5990: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D5994: jal         0x800C79C0
    // 0x800D5998: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D5998: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800D599C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800D59A0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800D59A4:
    // 0x800D59A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D59A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D59AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D59B0: jr          $ra
    // 0x800D59B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D59B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80063E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063EA4: jal         0x8005F064
    // 0x80063EA8: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063EA8: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x80063EAC: b           L_80063EBC
    // 0x80063EB0: nop

        goto L_80063EBC;
    // 0x80063EB0: nop

    // 0x80063EB4: b           L_80063EBC
    // 0x80063EB8: nop

        goto L_80063EBC;
    // 0x80063EB8: nop

L_80063EBC:
    // 0x80063EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063EC4: jr          $ra
    // 0x80063EC8: nop

    return;
    // 0x80063EC8: nop

;}
RECOMP_FUNC void func_80072B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B44: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072B48: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072B4C: nop

    // 0x80072B50: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072B54: nop

    // 0x80072B58: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072B5C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072B60: jr          $ra
    // 0x80072B64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072B64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B68: jr          $ra
    // 0x80072B6C: nop

    return;
    // 0x80072B6C: nop

    // 0x80072B70: jr          $ra
    // 0x80072B74: nop

    return;
    // 0x80072B74: nop

;}
RECOMP_FUNC void func_800797F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800797F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800797F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800797FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80079800: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079804: jal         0x800BC6EC
    // 0x80079808: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80079808: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x8007980C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80079810: lui         $t6, 0x807A
    ctx->r14 = S32(0X807A << 16);
    // 0x80079814: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x80079818: addiu       $t7, $t7, 0x7B08
    ctx->r15 = ADD32(ctx->r15, 0X7B08);
    // 0x8007981C: addiu       $t6, $t6, 0x7BE0
    ctx->r14 = ADD32(ctx->r14, 0X7BE0);
    // 0x80079820: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80079824: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80079828: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007982C: jal         0x800BC6EC
    // 0x80079830: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80079830: nop

    after_1:
    // 0x80079834: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80079838: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007983C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80079840: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x80079844: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x80079848: lui         $a2, 0x807A
    ctx->r6 = S32(0X807A << 16);
    // 0x8007984C: jal         0x800BD1FC
    // 0x80079850: addiu       $a2, $a2, 0x7B08
    ctx->r6 = ADD32(ctx->r6, 0X7B08);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x80079850: addiu       $a2, $a2, 0x7B08
    ctx->r6 = ADD32(ctx->r6, 0X7B08);
    after_2:
    // 0x80079854: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80079858: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007985C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80079860: jal         0x800BD218
    // 0x80079864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x80079864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80079868: lhu         $t0, 0x3A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3A);
    // 0x8007986C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80079870: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80079874: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80079878: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8007987C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80079880: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80079884: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x80079888: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x8007988C: jal         0x800BD1FC
    // 0x80079890: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x80079890: nop

    after_4:
    // 0x80079894: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80079898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007989C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800798A0: jal         0x800BD218
    // 0x800798A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x800798A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x800798A8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800798AC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800798B0: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800798B4: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x800798B8: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x800798BC: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x800798C0: jal         0x800BD1FC
    // 0x800798C4: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x800798C4: nop

    after_6:
    // 0x800798C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800798CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800798D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800798D4: jal         0x800BD218
    // 0x800798D8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_7;
    // 0x800798D8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_7:
    // 0x800798DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800798E0: jal         0x800BC980
    // 0x800798E4: nop

    SysMem_Free(rdram, ctx);
        goto after_8;
    // 0x800798E4: nop

    after_8:
    // 0x800798E8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800798EC: b           L_800798FC
    // 0x800798F0: nop

        goto L_800798FC;
    // 0x800798F0: nop

    // 0x800798F4: b           L_800798FC
    // 0x800798F8: nop

        goto L_800798FC;
    // 0x800798F8: nop

L_800798FC:
    // 0x800798FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80079900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079904: jr          $ra
    // 0x80079908: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80079908: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007990C: nop

;}
RECOMP_FUNC void func_80078A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078A90: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80078A94: blez        $a1, L_80079114
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80078A98: sw          $zero, 0x14($sp)
        MEM_W(0X14, ctx->r29) = 0;
            goto L_80079114;
    }
    // 0x80078A98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80078A9C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80078AA0: nop

    // 0x80078AA4: bne         $t6, $zero, L_80079114
    if (ctx->r14 != 0) {
        // 0x80078AA8: nop
    
            goto L_80079114;
    }
    // 0x80078AA8: nop

L_80078AAC:
    // 0x80078AAC: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80078AB0: nop

    // 0x80078AB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80078AB8: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x80078ABC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80078AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80078AC4: blez        $t9, L_800790D4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80078AC8: nop
    
            goto L_800790D4;
    }
    // 0x80078AC8: nop

    // 0x80078ACC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80078AD0: nop

    // 0x80078AD4: bne         $t0, $zero, L_800790D4
    if (ctx->r8 != 0) {
        // 0x80078AD8: nop
    
            goto L_800790D4;
    }
    // 0x80078AD8: nop

L_80078ADC:
    // 0x80078ADC: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x80078AE0: nop

    // 0x80078AE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80078AE8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x80078AEC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80078AF0: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80078AF4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80078AF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80078AFC: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80078B00: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80078B04: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80078B08: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80078B0C: nop

    // 0x80078B10: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078B14: nop

    // 0x80078B18: bc1f        L_80078B44
    if (!c1cs) {
        // 0x80078B1C: nop
    
            goto L_80078B44;
    }
    // 0x80078B1C: nop

    // 0x80078B20: addu        $t9, $a0, $t4
    ctx->r25 = ADD32(ctx->r4, ctx->r12);
    // 0x80078B24: addu        $t0, $a3, $t7
    ctx->r8 = ADD32(ctx->r7, ctx->r15);
    // 0x80078B28: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80078B2C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078B30: nop

    // 0x80078B34: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078B38: nop

    // 0x80078B3C: bc1t        L_80078B9C
    if (c1cs) {
        // 0x80078B40: nop
    
            goto L_80078B9C;
    }
    // 0x80078B40: nop

L_80078B44:
    // 0x80078B44: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80078B48: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x80078B4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80078B50: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80078B54: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x80078B58: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80078B5C: lwc1        $f16, 0x8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80078B60: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80078B64: nop

    // 0x80078B68: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078B6C: nop

    // 0x80078B70: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078B74: nop
    
            goto L_80078C5C;
    }
    // 0x80078B74: nop

    // 0x80078B78: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x80078B7C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80078B80: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80078B84: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078B88: nop

    // 0x80078B8C: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078B90: nop

    // 0x80078B94: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078B98: nop
    
            goto L_80078C5C;
    }
    // 0x80078B98: nop

L_80078B9C:
    // 0x80078B9C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80078BA0: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80078BA4: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80078BA8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80078BAC: addu        $t8, $a3, $t5
    ctx->r24 = ADD32(ctx->r7, ctx->r13);
    // 0x80078BB0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80078BB4: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80078BB8: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80078BBC: nop

    // 0x80078BC0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078BC4: nop

    // 0x80078BC8: bc1f        L_80078BF4
    if (!c1cs) {
        // 0x80078BCC: nop
    
            goto L_80078BF4;
    }
    // 0x80078BCC: nop

    // 0x80078BD0: addu        $t2, $a0, $t0
    ctx->r10 = ADD32(ctx->r4, ctx->r8);
    // 0x80078BD4: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x80078BD8: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80078BDC: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80078BE0: nop

    // 0x80078BE4: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078BE8: nop

    // 0x80078BEC: bc1t        L_80078C4C
    if (c1cs) {
        // 0x80078BF0: nop
    
            goto L_80078C4C;
    }
    // 0x80078BF0: nop

L_80078BF4:
    // 0x80078BF4: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80078BF8: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078BFC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80078C00: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80078C04: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x80078C08: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x80078C0C: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80078C10: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80078C14: nop

    // 0x80078C18: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078C1C: nop

    // 0x80078C20: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078C24: nop
    
            goto L_80078C5C;
    }
    // 0x80078C24: nop

    // 0x80078C28: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80078C2C: addu        $t2, $a3, $t3
    ctx->r10 = ADD32(ctx->r7, ctx->r11);
    // 0x80078C30: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80078C34: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80078C38: nop

    // 0x80078C3C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078C40: nop

    // 0x80078C44: bc1f        L_80078C5C
    if (!c1cs) {
        // 0x80078C48: nop
    
            goto L_80078C5C;
    }
    // 0x80078C48: nop

L_80078C4C:
    // 0x80078C4C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80078C50: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80078C54: b           L_800790D4
    // 0x80078C58: nop

        goto L_800790D4;
    // 0x80078C58: nop

L_80078C5C:
    // 0x80078C5C: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x80078C60: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80078C64: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80078C68: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80078C6C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80078C70: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80078C74: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80078C78: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078C7C: nop

    // 0x80078C80: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078C84: nop

    // 0x80078C88: bc1f        L_80078CB4
    if (!c1cs) {
        // 0x80078C8C: nop
    
            goto L_80078CB4;
    }
    // 0x80078C8C: nop

    // 0x80078C90: addu        $t0, $a3, $t6
    ctx->r8 = ADD32(ctx->r7, ctx->r14);
    // 0x80078C94: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x80078C98: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80078C9C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80078CA0: nop

    // 0x80078CA4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078CA8: nop

    // 0x80078CAC: bc1t        L_80078D0C
    if (c1cs) {
        // 0x80078CB0: nop
    
            goto L_80078D0C;
    }
    // 0x80078CB0: nop

L_80078CB4:
    // 0x80078CB4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80078CB8: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80078CBC: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80078CC0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80078CC4: addu        $t9, $a0, $t1
    ctx->r25 = ADD32(ctx->r4, ctx->r9);
    // 0x80078CC8: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x80078CCC: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078CD0: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078CD4: nop

    // 0x80078CD8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078CDC: nop

    // 0x80078CE0: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078CE4: nop
    
            goto L_80078DCC;
    }
    // 0x80078CE4: nop

    // 0x80078CE8: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80078CEC: addu        $t0, $a0, $t1
    ctx->r8 = ADD32(ctx->r4, ctx->r9);
    // 0x80078CF0: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80078CF4: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80078CF8: nop

    // 0x80078CFC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078D00: nop

    // 0x80078D04: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078D08: nop
    
            goto L_80078DCC;
    }
    // 0x80078D08: nop

L_80078D0C:
    // 0x80078D0C: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80078D10: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x80078D14: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80078D18: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80078D1C: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x80078D20: addu        $t2, $a3, $t3
    ctx->r10 = ADD32(ctx->r7, ctx->r11);
    // 0x80078D24: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80078D28: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80078D2C: nop

    // 0x80078D30: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078D34: nop

    // 0x80078D38: bc1f        L_80078D64
    if (!c1cs) {
        // 0x80078D3C: nop
    
            goto L_80078D64;
    }
    // 0x80078D3C: nop

    // 0x80078D40: addu        $t5, $a3, $t3
    ctx->r13 = ADD32(ctx->r7, ctx->r11);
    // 0x80078D44: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x80078D48: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80078D4C: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80078D50: nop

    // 0x80078D54: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078D58: nop

    // 0x80078D5C: bc1t        L_80078DBC
    if (c1cs) {
        // 0x80078D60: nop
    
            goto L_80078DBC;
    }
    // 0x80078D60: nop

L_80078D64:
    // 0x80078D64: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078D68: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80078D6C: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80078D70: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80078D74: addu        $t9, $a0, $t4
    ctx->r25 = ADD32(ctx->r4, ctx->r12);
    // 0x80078D78: addu        $t8, $a3, $t0
    ctx->r24 = ADD32(ctx->r7, ctx->r8);
    // 0x80078D7C: lwc1        $f16, 0xC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80078D80: lwc1        $f18, 0x4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80078D84: nop

    // 0x80078D88: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078D8C: nop

    // 0x80078D90: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078D94: nop
    
            goto L_80078DCC;
    }
    // 0x80078D94: nop

    // 0x80078D98: addu        $t3, $a3, $t0
    ctx->r11 = ADD32(ctx->r7, ctx->r8);
    // 0x80078D9C: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80078DA0: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80078DA4: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80078DA8: nop

    // 0x80078DAC: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078DB0: nop

    // 0x80078DB4: bc1f        L_80078DCC
    if (!c1cs) {
        // 0x80078DB8: nop
    
            goto L_80078DCC;
    }
    // 0x80078DB8: nop

L_80078DBC:
    // 0x80078DBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80078DC0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80078DC4: b           L_800790D4
    // 0x80078DC8: nop

        goto L_800790D4;
    // 0x80078DC8: nop

L_80078DCC:
    // 0x80078DCC: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80078DD0: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80078DD4: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80078DD8: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80078DDC: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x80078DE0: addu        $t8, $a0, $t1
    ctx->r24 = ADD32(ctx->r4, ctx->r9);
    // 0x80078DE4: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80078DE8: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80078DEC: nop

    // 0x80078DF0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078DF4: nop

    // 0x80078DF8: bc1f        L_80078E24
    if (!c1cs) {
        // 0x80078DFC: nop
    
            goto L_80078E24;
    }
    // 0x80078DFC: nop

    // 0x80078E00: addu        $t3, $a0, $t1
    ctx->r11 = ADD32(ctx->r4, ctx->r9);
    // 0x80078E04: addu        $t4, $a3, $t9
    ctx->r12 = ADD32(ctx->r7, ctx->r25);
    // 0x80078E08: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078E0C: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80078E10: nop

    // 0x80078E14: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078E18: nop

    // 0x80078E1C: bc1t        L_80078E7C
    if (c1cs) {
        // 0x80078E20: nop
    
            goto L_80078E7C;
    }
    // 0x80078E20: nop

L_80078E24:
    // 0x80078E24: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80078E28: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80078E2C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80078E30: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80078E34: addu        $t0, $a3, $t2
    ctx->r8 = ADD32(ctx->r7, ctx->r10);
    // 0x80078E38: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x80078E3C: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80078E40: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80078E44: nop

    // 0x80078E48: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078E4C: nop

    // 0x80078E50: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078E54: nop
    
            goto L_80078F3C;
    }
    // 0x80078E54: nop

    // 0x80078E58: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x80078E5C: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x80078E60: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80078E64: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80078E68: nop

    // 0x80078E6C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078E70: nop

    // 0x80078E74: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078E78: nop
    
            goto L_80078F3C;
    }
    // 0x80078E78: nop

L_80078E7C:
    // 0x80078E7C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80078E80: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80078E84: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80078E88: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078E8C: addu        $t0, $a0, $t8
    ctx->r8 = ADD32(ctx->r4, ctx->r24);
    // 0x80078E90: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x80078E94: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80078E98: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80078E9C: nop

    // 0x80078EA0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078EA4: nop

    // 0x80078EA8: bc1f        L_80078ED4
    if (!c1cs) {
        // 0x80078EAC: nop
    
            goto L_80078ED4;
    }
    // 0x80078EAC: nop

    // 0x80078EB0: addu        $t7, $a3, $t4
    ctx->r15 = ADD32(ctx->r7, ctx->r12);
    // 0x80078EB4: addu        $t1, $a0, $t8
    ctx->r9 = ADD32(ctx->r4, ctx->r24);
    // 0x80078EB8: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80078EBC: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80078EC0: nop

    // 0x80078EC4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078EC8: nop

    // 0x80078ECC: bc1t        L_80078F2C
    if (c1cs) {
        // 0x80078ED0: nop
    
            goto L_80078F2C;
    }
    // 0x80078ED0: nop

L_80078ED4:
    // 0x80078ED4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80078ED8: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80078EDC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80078EE0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80078EE4: addu        $t0, $a0, $t6
    ctx->r8 = ADD32(ctx->r4, ctx->r14);
    // 0x80078EE8: addu        $t9, $a3, $t3
    ctx->r25 = ADD32(ctx->r7, ctx->r11);
    // 0x80078EEC: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80078EF0: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80078EF4: nop

    // 0x80078EF8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80078EFC: nop

    // 0x80078F00: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078F04: nop
    
            goto L_80078F3C;
    }
    // 0x80078F04: nop

    // 0x80078F08: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80078F0C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80078F10: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80078F14: lwc1        $f16, 0xC($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80078F18: nop

    // 0x80078F1C: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80078F20: nop

    // 0x80078F24: bc1f        L_80078F3C
    if (!c1cs) {
        // 0x80078F28: nop
    
            goto L_80078F3C;
    }
    // 0x80078F28: nop

L_80078F2C:
    // 0x80078F2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80078F30: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80078F34: b           L_800790D4
    // 0x80078F38: nop

        goto L_800790D4;
    // 0x80078F38: nop

L_80078F3C:
    // 0x80078F3C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078F40: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80078F44: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80078F48: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80078F4C: addu        $t3, $a0, $t0
    ctx->r11 = ADD32(ctx->r4, ctx->r8);
    // 0x80078F50: addu        $t9, $a3, $t2
    ctx->r25 = ADD32(ctx->r7, ctx->r10);
    // 0x80078F54: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80078F58: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80078F5C: nop

    // 0x80078F60: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078F64: nop

    // 0x80078F68: bc1f        L_80078F94
    if (!c1cs) {
        // 0x80078F6C: nop
    
            goto L_80078F94;
    }
    // 0x80078F6C: nop

    // 0x80078F70: addu        $t4, $a3, $t2
    ctx->r12 = ADD32(ctx->r7, ctx->r10);
    // 0x80078F74: addu        $t6, $a0, $t0
    ctx->r14 = ADD32(ctx->r4, ctx->r8);
    // 0x80078F78: lwc1        $f10, 0x8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80078F7C: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80078F80: nop

    // 0x80078F84: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80078F88: nop

    // 0x80078F8C: bc1t        L_80078FEC
    if (c1cs) {
        // 0x80078F90: nop
    
            goto L_80078FEC;
    }
    // 0x80078F90: nop

L_80078F94:
    // 0x80078F94: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80078F98: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80078F9C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80078FA0: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80078FA4: addu        $t3, $a0, $t5
    ctx->r11 = ADD32(ctx->r4, ctx->r13);
    // 0x80078FA8: addu        $t1, $a3, $t8
    ctx->r9 = ADD32(ctx->r7, ctx->r24);
    // 0x80078FAC: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80078FB0: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80078FB4: nop

    // 0x80078FB8: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80078FBC: nop

    // 0x80078FC0: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80078FC4: nop
    
            goto L_800790AC;
    }
    // 0x80078FC4: nop

    // 0x80078FC8: addu        $t2, $a3, $t8
    ctx->r10 = ADD32(ctx->r7, ctx->r24);
    // 0x80078FCC: addu        $t4, $a0, $t5
    ctx->r12 = ADD32(ctx->r4, ctx->r13);
    // 0x80078FD0: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80078FD4: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80078FD8: nop

    // 0x80078FDC: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80078FE0: nop

    // 0x80078FE4: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80078FE8: nop
    
            goto L_800790AC;
    }
    // 0x80078FE8: nop

L_80078FEC:
    // 0x80078FEC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80078FF0: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80078FF4: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80078FF8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x80078FFC: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x80079000: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80079004: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80079008: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8007900C: nop

    // 0x80079010: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80079014: nop

    // 0x80079018: bc1f        L_80079044
    if (!c1cs) {
        // 0x8007901C: nop
    
            goto L_80079044;
    }
    // 0x8007901C: nop

    // 0x80079020: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x80079024: addu        $t2, $a3, $t9
    ctx->r10 = ADD32(ctx->r7, ctx->r25);
    // 0x80079028: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8007902C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80079030: nop

    // 0x80079034: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80079038: nop

    // 0x8007903C: bc1t        L_8007909C
    if (c1cs) {
        // 0x80079040: nop
    
            goto L_8007909C;
    }
    // 0x80079040: nop

L_80079044:
    // 0x80079044: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80079048: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8007904C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80079050: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80079054: addu        $t3, $a3, $t1
    ctx->r11 = ADD32(ctx->r7, ctx->r9);
    // 0x80079058: addu        $t0, $a0, $t4
    ctx->r8 = ADD32(ctx->r4, ctx->r12);
    // 0x8007905C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80079060: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80079064: nop

    // 0x80079068: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8007906C: nop

    // 0x80079070: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80079074: nop
    
            goto L_800790AC;
    }
    // 0x80079074: nop

    // 0x80079078: addu        $t6, $a0, $t4
    ctx->r14 = ADD32(ctx->r4, ctx->r12);
    // 0x8007907C: addu        $t8, $a3, $t1
    ctx->r24 = ADD32(ctx->r7, ctx->r9);
    // 0x80079080: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80079084: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80079088: nop

    // 0x8007908C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80079090: nop

    // 0x80079094: bc1f        L_800790AC
    if (!c1cs) {
        // 0x80079098: nop
    
            goto L_800790AC;
    }
    // 0x80079098: nop

L_8007909C:
    // 0x8007909C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800790A0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800790A4: b           L_800790D4
    // 0x800790A8: nop

        goto L_800790D4;
    // 0x800790A8: nop

L_800790AC:
    // 0x800790AC: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x800790B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800790B4: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x800790B8: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800790BC: beq         $at, $zero, L_800790D4
    if (ctx->r1 == 0) {
        // 0x800790C0: sw          $t5, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r13;
            goto L_800790D4;
    }
    // 0x800790C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800790C4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800790C8: nop

    // 0x800790CC: beq         $t7, $zero, L_80078ADC
    if (ctx->r15 == 0) {
        // 0x800790D0: nop
    
            goto L_80078ADC;
    }
    // 0x800790D0: nop

L_800790D4:
    // 0x800790D4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800790D8: nop

    // 0x800790DC: beq         $t3, $zero, L_800790EC
    if (ctx->r11 == 0) {
        // 0x800790E0: nop
    
            goto L_800790EC;
    }
    // 0x800790E0: nop

    // 0x800790E4: b           L_80079114
    // 0x800790E8: nop

        goto L_80079114;
    // 0x800790E8: nop

L_800790EC:
    // 0x800790EC: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800790F0: nop

    // 0x800790F4: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800790F8: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800790FC: beq         $at, $zero, L_80079114
    if (ctx->r1 == 0) {
        // 0x80079100: sw          $t6, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r14;
            goto L_80079114;
    }
    // 0x80079100: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80079104: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80079108: nop

    // 0x8007910C: beq         $t1, $zero, L_80078AAC
    if (ctx->r9 == 0) {
        // 0x80079110: nop
    
            goto L_80078AAC;
    }
    // 0x80079110: nop

L_80079114:
    // 0x80079114: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80079118: nop

    // 0x8007911C: beq         $t8, $zero, L_80079140
    if (ctx->r24 == 0) {
        // 0x80079120: nop
    
            goto L_80079140;
    }
    // 0x80079120: nop

    // 0x80079124: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80079128: nop

    // 0x8007912C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80079130: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80079134: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80079138: nop

    // 0x8007913C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
L_80079140:
    // 0x80079140: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80079144: b           L_80079154
    // 0x80079148: nop

        goto L_80079154;
    // 0x80079148: nop

    // 0x8007914C: b           L_80079154
    // 0x80079150: nop

        goto L_80079154;
    // 0x80079150: nop

L_80079154:
    // 0x80079154: jr          $ra
    // 0x80079158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800BE684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE684: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE68C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE690: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x800BE694: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE698: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE69C: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x800BE6A0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800BE6A4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BE6A8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800BE6AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE6B0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BE6B4: lui         $t0, 0x100
    ctx->r8 = S32(0X100 << 16);
    // 0x800BE6B8: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
    // 0x800BE6BC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800BE6C0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800BE6C4: lw          $t2, 0x1B44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1B44);
    // 0x800BE6C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE6CC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE6D0: sw          $t3, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r11;
    // 0x800BE6D4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800BE6D8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BE6DC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800BE6E0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE6E4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BE6E8: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x800BE6EC: addiu       $t6, $t6, 0x58
    ctx->r14 = ADD32(ctx->r14, 0X58);
    // 0x800BE6F0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800BE6F4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800BE6F8: lw          $t8, 0x1B44($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B44);
    // 0x800BE6FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE700: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800BE704: sw          $t9, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r25;
    // 0x800BE708: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800BE70C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE710: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800BE714: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800BE718: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE71C: nop

    // 0x800BE720: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800BE724: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE728: jal         0x800BE328
    // 0x800BE72C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    Main_GfxClearScreen(rdram, ctx);
        goto after_0;
    // 0x800BE72C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_0:
    // 0x800BE730: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800BE734: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x800BE738: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE73C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800BE740: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x800BE744: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800BE748: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BE74C: lui         $t5, 0xFF10
    ctx->r13 = S32(0XFF10 << 16);
    // 0x800BE750: ori         $t5, $t5, 0x13F
    ctx->r13 = ctx->r13 | 0X13F;
    // 0x800BE754: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800BE758: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BE75C: lw          $t7, 0x24DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X24DC);
    // 0x800BE760: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800BE764: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE768: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800BE76C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800BE770: b           L_800BE778
    // 0x800BE774: nop

        goto L_800BE778;
    // 0x800BE774: nop

L_800BE778:
    // 0x800BE778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE77C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE780: jr          $ra
    // 0x800BE784: nop

    return;
    // 0x800BE784: nop

;}
RECOMP_FUNC void func_80061F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F08: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061F0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061F10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80061F14: nop

    // 0x80061F18: lh          $t7, 0x30($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X30);
    // 0x80061F1C: nop

    // 0x80061F20: slti        $at, $t7, 0x384
    ctx->r1 = SIGNED(ctx->r15) < 0X384 ? 1 : 0;
    // 0x80061F24: beq         $at, $zero, L_80061F68
    if (ctx->r1 == 0) {
        // 0x80061F28: nop
    
            goto L_80061F68;
    }
    // 0x80061F28: nop

    // 0x80061F2C: lh          $t8, 0x32($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X32);
    // 0x80061F30: nop

    // 0x80061F34: slti        $at, $t8, 0x384
    ctx->r1 = SIGNED(ctx->r24) < 0X384 ? 1 : 0;
    // 0x80061F38: beq         $at, $zero, L_80061F68
    if (ctx->r1 == 0) {
        // 0x80061F3C: nop
    
            goto L_80061F68;
    }
    // 0x80061F3C: nop

    // 0x80061F40: lh          $t9, 0x34($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X34);
    // 0x80061F44: nop

    // 0x80061F48: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80061F4C: beq         $at, $zero, L_80061F68
    if (ctx->r1 == 0) {
        // 0x80061F50: nop
    
            goto L_80061F68;
    }
    // 0x80061F50: nop

    // 0x80061F54: lh          $t0, 0x36($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X36);
    // 0x80061F58: nop

    // 0x80061F5C: slti        $at, $t0, 0x384
    ctx->r1 = SIGNED(ctx->r8) < 0X384 ? 1 : 0;
    // 0x80061F60: bne         $at, $zero, L_80061FE4
    if (ctx->r1 != 0) {
        // 0x80061F64: nop
    
            goto L_80061FE4;
    }
    // 0x80061F64: nop

L_80061F68:
    // 0x80061F68: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80061F6C: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80061F70: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80061F74: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_80061F78:
    // 0x80061F78: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061F7C: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061F80: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80061F84: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80061F88: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80061F8C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80061F90: addu        $t0, $t3, $t6
    ctx->r8 = ADD32(ctx->r11, ctx->r14);
    // 0x80061F94: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80061F98: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061F9C: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80061FA0: nop

    // 0x80061FA4: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061FA8: beq         $at, $zero, L_80061FC0
    if (ctx->r1 == 0) {
        // 0x80061FAC: nop
    
            goto L_80061FC0;
    }
    // 0x80061FAC: nop

    // 0x80061FB0: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061FB4: nop

    // 0x80061FB8: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80061FBC: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
L_80061FC0:
    // 0x80061FC0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80061FC4: nop

    // 0x80061FC8: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80061FCC: slti        $at, $t7, 0x1B
    ctx->r1 = SIGNED(ctx->r15) < 0X1B ? 1 : 0;
    // 0x80061FD0: bne         $at, $zero, L_80061F78
    if (ctx->r1 != 0) {
        // 0x80061FD4: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80061F78;
    }
    // 0x80061FD4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80061FD8: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80061FDC: b           L_80061FF4
    // 0x80061FE0: nop

        goto L_80061FF4;
    // 0x80061FE0: nop

L_80061FE4:
    // 0x80061FE4: b           L_80061FF4
    // 0x80061FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061FF4;
    // 0x80061FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061FEC: b           L_80061FF4
    // 0x80061FF0: nop

        goto L_80061FF4;
    // 0x80061FF0: nop

L_80061FF4:
    // 0x80061FF4: jr          $ra
    // 0x80061FF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80061FF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80066D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066D28: jal         0x80061348
    // 0x80066D2C: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066D2C: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    after_0:
    // 0x80066D30: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066D34: b           L_80066D44
    // 0x80066D38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066D44;
    // 0x80066D38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066D3C: b           L_80066D44
    // 0x80066D40: nop

        goto L_80066D44;
    // 0x80066D40: nop

L_80066D44:
    // 0x80066D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066D4C: jr          $ra
    // 0x80066D50: nop

    return;
    // 0x80066D50: nop

;}
RECOMP_FUNC void func_8006822C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006822C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068230: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068234: nop

    // 0x80068238: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006823C: nop

    // 0x80068240: slti        $t7, $v0, 0x190
    ctx->r15 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068244: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006824C: beq         $v0, $zero, L_80068284
    if (ctx->r2 == 0) {
        // 0x80068250: nop
    
            goto L_80068284;
    }
    // 0x80068250: nop

    // 0x80068254: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80068258: nop

    // 0x8006825C: slti        $t8, $v0, 0x190
    ctx->r24 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068260: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80068264: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80068268: beq         $v0, $zero, L_80068284
    if (ctx->r2 == 0) {
        // 0x8006826C: nop
    
            goto L_80068284;
    }
    // 0x8006826C: nop

    // 0x80068270: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80068274: nop

    // 0x80068278: slti        $t9, $v0, 0x190
    ctx->r25 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x8006827C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80068280: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80068284:
    // 0x80068284: jr          $ra
    // 0x80068288: nop

    return;
    // 0x80068288: nop

    // 0x8006828C: jr          $ra
    // 0x80068290: nop

    return;
    // 0x80068290: nop

    // 0x80068294: jr          $ra
    // 0x80068298: nop

    return;
    // 0x80068298: nop

;}
RECOMP_FUNC void func_8006501C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006501C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065024: jal         0x80061488
    // 0x80065028: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065028: addiu       $a0, $zero, 0x5E0
    ctx->r4 = ADD32(0, 0X5E0);
    after_0:
    // 0x8006502C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80065030: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065034: b           L_80065044
    // 0x80065038: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065044;
    // 0x80065038: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006503C: b           L_80065044
    // 0x80065040: nop

        goto L_80065044;
    // 0x80065040: nop

L_80065044:
    // 0x80065044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006504C: jr          $ra
    // 0x80065050: nop

    return;
    // 0x80065050: nop

;}
RECOMP_FUNC void func_80096198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096198: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8009619C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800961A0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800961A4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800961A8: lw          $t7, -0x42B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X42B8);
    // 0x800961AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800961B0: sw          $t7, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r15;
    // 0x800961B4: jr          $ra
    // 0x800961B8: nop

    return;
    // 0x800961B8: nop

    // 0x800961BC: jr          $ra
    // 0x800961C0: nop

    return;
    // 0x800961C0: nop

;}
RECOMP_FUNC void func_800700A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800700A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800700A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800700AC: jal         0x80061348
    // 0x800700B0: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800700B0: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800700B4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800700B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800700BC: beq         $v0, $zero, L_8007010C
    if (ctx->r2 == 0) {
        // 0x800700C0: nop
    
            goto L_8007010C;
    }
    // 0x800700C0: nop

    // 0x800700C4: jal         0x80061348
    // 0x800700C8: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800700C8: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800700CC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800700D0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800700D4: beq         $v0, $zero, L_8007010C
    if (ctx->r2 == 0) {
        // 0x800700D8: nop
    
            goto L_8007010C;
    }
    // 0x800700D8: nop

    // 0x800700DC: jal         0x80061348
    // 0x800700E0: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800700E0: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800700E4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800700E8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800700EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800700F0: beq         $v0, $zero, L_8007010C
    if (ctx->r2 == 0) {
        // 0x800700F4: nop
    
            goto L_8007010C;
    }
    // 0x800700F4: nop

    // 0x800700F8: jal         0x80061348
    // 0x800700FC: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800700FC: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070100: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070104: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070108: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007010C:
    // 0x8007010C: b           L_8007011C
    // 0x80070110: nop

        goto L_8007011C;
    // 0x80070110: nop

    // 0x80070114: b           L_8007011C
    // 0x80070118: nop

        goto L_8007011C;
    // 0x80070118: nop

L_8007011C:
    // 0x8007011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070124: jr          $ra
    // 0x80070128: nop

    return;
    // 0x80070128: nop

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
RECOMP_FUNC void func_800123AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800123AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800123B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800123B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800123B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800123BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800123C0: jal         0x8000DA44
    // 0x800123C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800123C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800123C8: bgez        $v0, L_800123D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800123CC: nop
    
            goto L_800123D8;
    }
    // 0x800123CC: nop

    // 0x800123D0: b           L_800124A8
    // 0x800123D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800124A8;
    // 0x800123D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800123D8:
    // 0x800123D8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800123DC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800123E0: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800123E4: nop

    // 0x800123E8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800123EC: bne         $at, $zero, L_8001240C
    if (ctx->r1 != 0) {
        // 0x800123F0: nop
    
            goto L_8001240C;
    }
    // 0x800123F0: nop

    // 0x800123F4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x800123F8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800123FC: beq         $at, $zero, L_8001240C
    if (ctx->r1 == 0) {
        // 0x80012400: nop
    
            goto L_8001240C;
    }
    // 0x80012400: nop

    // 0x80012404: b           L_800124A8
    // 0x80012408: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800124A8;
    // 0x80012408: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001240C:
    // 0x8001240C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80012410: nop

    // 0x80012414: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80012418: nop

    // 0x8001241C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80012420: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80012424: nop

    // 0x80012428: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8001242C: nop

    // 0x80012430: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80012434: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x80012438: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001243C: nop

    // 0x80012440: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80012444: nop

    // 0x80012448: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8001244C: bne         $at, $zero, L_80012460
    if (ctx->r1 != 0) {
        // 0x80012450: nop
    
            goto L_80012460;
    }
    // 0x80012450: nop

    // 0x80012454: slti        $at, $t4, 0x2A
    ctx->r1 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x80012458: bne         $at, $zero, L_80012468
    if (ctx->r1 != 0) {
        // 0x8001245C: nop
    
            goto L_80012468;
    }
    // 0x8001245C: nop

L_80012460:
    // 0x80012460: b           L_800124A8
    // 0x80012464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800124A8;
    // 0x80012464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012468:
    // 0x80012468: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8001246C: nop

    // 0x80012470: lw          $a0, 0x7C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X7C);
    // 0x80012474: jal         0x80014B5C
    // 0x80012478: nop

    func_80014B5C(rdram, ctx);
        goto after_1;
    // 0x80012478: nop

    after_1:
    // 0x8001247C: beq         $v0, $zero, L_80012498
    if (ctx->r2 == 0) {
        // 0x80012480: nop
    
            goto L_80012498;
    }
    // 0x80012480: nop

    // 0x80012484: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80012488: nop

    // 0x8001248C: lw          $a0, 0x7C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X7C);
    // 0x80012490: jal         0x800299C4
    // 0x80012494: nop

    func_800299C4(rdram, ctx);
        goto after_2;
    // 0x80012494: nop

    after_2:
L_80012498:
    // 0x80012498: b           L_800124A8
    // 0x8001249C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800124A8;
    // 0x8001249C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800124A0: b           L_800124A8
    // 0x800124A4: nop

        goto L_800124A8;
    // 0x800124A4: nop

L_800124A8:
    // 0x800124A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800124AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800124B0: jr          $ra
    // 0x800124B4: nop

    return;
    // 0x800124B4: nop

;}
RECOMP_FUNC void func_80075724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075724: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075728: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007572C: nop

    // 0x80075730: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075734: nop

    // 0x80075738: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007573C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075740: jr          $ra
    // 0x80075744: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075744: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075748: jr          $ra
    // 0x8007574C: nop

    return;
    // 0x8007574C: nop

    // 0x80075750: jr          $ra
    // 0x80075754: nop

    return;
    // 0x80075754: nop

;}
RECOMP_FUNC void func_8008C3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C3D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C3DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008C3E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008C3E4:
    // 0x8008C3E4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008C3E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C3EC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008C3F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008C3F4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8008C3F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C3FC: nop

    // 0x8008C400: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008C404: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8008C408: bne         $at, $zero, L_8008C3E4
    if (ctx->r1 != 0) {
        // 0x8008C40C: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8008C3E4;
    }
    // 0x8008C40C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8008C410: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008C414:
    // 0x8008C414: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8008C418: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C41C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008C420: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8008C424: sb          $t2, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r10;
    // 0x8008C428: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C42C: nop

    // 0x8008C430: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008C434: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8008C438: bne         $at, $zero, L_8008C414
    if (ctx->r1 != 0) {
        // 0x8008C43C: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_8008C414;
    }
    // 0x8008C43C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8008C440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008C444: jal         0x80028F74
    // 0x8008C448: nop

    func_80028F74(rdram, ctx);
        goto after_0;
    // 0x8008C448: nop

    after_0:
    // 0x8008C44C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008C450: nop

    // 0x8008C454: sb          $zero, 0x64($t6)
    MEM_B(0X64, ctx->r14) = 0;
    // 0x8008C458: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8008C45C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8008C460: lw          $t0, 0x70E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70E8);
    // 0x8008C464: lw          $t9, 0x718C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X718C);
    // 0x8008C468: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8008C46C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8008C470: sw          $t1, 0x68($t3)
    MEM_W(0X68, ctx->r11) = ctx->r9;
    // 0x8008C474: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8008C478: lbu         $t4, 0x7208($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7208);
    // 0x8008C47C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008C480: nop

    // 0x8008C484: sh          $t4, 0x6C($t2)
    MEM_H(0X6C, ctx->r10) = ctx->r12;
    // 0x8008C488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008C48C: jal         0x8005F410
    // 0x8008C490: nop

    func_8005F410(rdram, ctx);
        goto after_1;
    // 0x8008C490: nop

    after_1:
    // 0x8008C494: b           L_8008C49C
    // 0x8008C498: nop

        goto L_8008C49C;
    // 0x8008C498: nop

L_8008C49C:
    // 0x8008C49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C4A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008C4A4: jr          $ra
    // 0x8008C4A8: nop

    return;
    // 0x8008C4A8: nop

;}
RECOMP_FUNC void func_800B0E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0E88: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800B0E8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B0E90: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800B0E94: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800B0E98: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800B0E9C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800B0EA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B0EA4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B0EA8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B0EAC: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B0EB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0EB4: swc1        $f4, 0x220($at)
    MEM_W(0X220, ctx->r1) = ctx->f4.u32l;
    // 0x800B0EB8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B0EBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0EC0: swc1        $f6, 0x428($at)
    MEM_W(0X428, ctx->r1) = ctx->f6.u32l;
    // 0x800B0EC4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800B0EC8: nop

    // 0x800B0ECC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B0ED0: nop

    // 0x800B0ED4: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B0ED8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B0EDC: addiu       $t8, $t8, 0x1E0
    ctx->r24 = ADD32(ctx->r24, 0X1E0);
    // 0x800B0EE0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800B0EE4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B0EE8: lw          $t9, 0x1B14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B14);
    // 0x800B0EEC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B0EF0: addiu       $t1, $t1, -0x770
    ctx->r9 = ADD32(ctx->r9, -0X770);
    // 0x800B0EF4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800B0EF8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B0EFC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800B0F00: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B0F04: lw          $t3, 0x1B14($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B14);
    // 0x800B0F08: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B0F0C: addiu       $t5, $t5, -0x558
    ctx->r13 = ADD32(ctx->r13, -0X558);
    // 0x800B0F10: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x800B0F14: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800B0F18: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800B0F1C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
L_800B0F20:
    // 0x800B0F20: lh          $t8, 0x56($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X56);
    // 0x800B0F24: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0F28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B0F2C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B0F30: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B0F34: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800B0F38: lh          $t1, 0x56($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X56);
    // 0x800B0F3C: nop

    // 0x800B0F40: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B0F44: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800B0F48: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800B0F4C: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x800B0F50: bne         $at, $zero, L_800B0F20
    if (ctx->r1 != 0) {
        // 0x800B0F54: sh          $t2, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r10;
            goto L_800B0F20;
    }
    // 0x800B0F54: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x800B0F58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0F5C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B0F60: lwc1        $f19, -0x6C8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X6C8);
    // 0x800B0F64: lwc1        $f18, -0x6C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6C4);
    // 0x800B0F68: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800B0F6C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B0F70: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800B0F74: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800B0F78: jal         0x800C3338
    // 0x800B0F7C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    MathUtil_Cosf(rdram, ctx);
        goto after_0;
    // 0x800B0F7C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    after_0:
    // 0x800B0F80: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B0F84: jal         0x800C3070
    // 0x800B0F88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x800B0F88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x800B0F8C: nop

    // 0x800B0F90: div.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B0F94: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B0F98: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B0F9C: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B0FA0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0FA4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800B0FA8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0FAC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B0FB0: nop

    // 0x800B0FB4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0FB8: nop

    // 0x800B0FBC: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B0FC0: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800B0FC4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B0FC8: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B0FCC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0FD0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800B0FD4: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
    // 0x800B0FD8: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B0FDC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B0FE0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B0FE4: add.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B0FE8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0FEC: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800B0FF0: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800B0FF4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800B0FF8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800B0FFC: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B1000: swc1        $f6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f6.u32l;
    // 0x800B1004: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B1008: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800B100C: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x800B1010: swc1        $f8, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f8.u32l;
    // 0x800B1014: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B1018: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B101C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B1020: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B1024: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800B1028: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800B102C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B1030: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B1034: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B1038: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B103C: mul.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B1040: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800B1044: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B1048: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x800B104C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B1050: nop

    // 0x800B1054: div.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f8.d);
    // 0x800B1058: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x800B105C: swc1        $f16, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f16.u32l;
    // 0x800B1060: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B1064: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B1068: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B106C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B1070: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800B1074: c.le.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d <= ctx->f18.d;
    // 0x800B1078: nop

    // 0x800B107C: bc1f        L_800B1094
    if (!c1cs) {
        // 0x800B1080: nop
    
            goto L_800B1094;
    }
    // 0x800B1080: nop

    // 0x800B1084: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1088: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x800B108C: b           L_800B1150
    // 0x800B1090: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
        goto L_800B1150;
    // 0x800B1090: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
L_800B1094:
    // 0x800B1094: lui         $at, 0x4800
    ctx->r1 = S32(0X4800 << 16);
    // 0x800B1098: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B109C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B10A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800B10A4: div.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800B10A8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B10AC: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800B10B0: nop

    // 0x800B10B4: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B10B8: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800B10BC: nop

    // 0x800B10C0: andi        $at, $s0, 0x4
    ctx->r1 = ctx->r16 & 0X4;
    // 0x800B10C4: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800B10C8: beq         $s0, $zero, L_800B111C
    if (ctx->r16 == 0) {
        // 0x800B10CC: nop
    
            goto L_800B111C;
    }
    // 0x800B10CC: nop

    // 0x800B10D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B10D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B10D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800B10DC: sub.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800B10E0: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800B10E4: nop

    // 0x800B10E8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B10EC: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800B10F0: nop

    // 0x800B10F4: andi        $at, $s0, 0x4
    ctx->r1 = ctx->r16 & 0X4;
    // 0x800B10F8: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800B10FC: bne         $s0, $zero, L_800B1114
    if (ctx->r16 != 0) {
        // 0x800B1100: nop
    
            goto L_800B1114;
    }
    // 0x800B1100: nop

    // 0x800B1104: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800B1108: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B110C: b           L_800B112C
    // 0x800B1110: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_800B112C;
    // 0x800B1110: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_800B1114:
    // 0x800B1114: b           L_800B112C
    // 0x800B1118: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_800B112C;
    // 0x800B1118: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_800B111C:
    // 0x800B111C: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800B1120: nop

    // 0x800B1124: bltz        $s0, L_800B1114
    if (SIGNED(ctx->r16) < 0) {
        // 0x800B1128: nop
    
            goto L_800B1114;
    }
    // 0x800B1128: nop

L_800B112C:
    // 0x800B112C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1130: andi        $t3, $s0, 0xFFFF
    ctx->r11 = ctx->r16 & 0XFFFF;
    // 0x800B1134: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x800B1138: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B113C: bgtz        $s0, L_800B1150
    if (SIGNED(ctx->r16) > 0) {
        // 0x800B1140: sh          $s0, 0x0($t4)
        MEM_H(0X0, ctx->r12) = ctx->r16;
            goto L_800B1150;
    }
    // 0x800B1140: sh          $s0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r16;
    // 0x800B1144: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1148: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B114C: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_800B1150:
    // 0x800B1150: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B1154: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800B1158: jal         0x800C2D6C
    // 0x800B115C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    MtxUtil_MtxFToMtx(rdram, ctx);
        goto after_2;
    // 0x800B115C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_2:
    // 0x800B1160: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B1164: lhu         $t8, -0x778($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X778);
    // 0x800B1168: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B116C: lw          $t9, -0x77C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X77C);
    // 0x800B1170: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B1174: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x800B1178: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    // 0x800B117C: jal         0x800C2D6C
    // 0x800B1180: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    MtxUtil_MtxFToMtx(rdram, ctx);
        goto after_3;
    // 0x800B1180: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    after_3:
    // 0x800B1184: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800B1188: nop

    // 0x800B118C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800B1190: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800B1194: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B1198: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B119C: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800B11A0: ori         $t2, $t2, 0xE
    ctx->r10 = ctx->r10 | 0XE;
    // 0x800B11A4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800B11A8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B11AC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B11B0: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800B11B4: nop

    // 0x800B11B8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800B11BC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800B11C0: nop

    // 0x800B11C4: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800B11C8: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B11CC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800B11D0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B11D4: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x800B11D8: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x800B11DC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B11E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B11E4: lhu         $t1, -0x778($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X778);
    // 0x800B11E8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800B11EC: lw          $t3, -0x77C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X77C);
    // 0x800B11F0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800B11F4: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x800B11F8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B11FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B1200: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1204: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800B1208: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B120C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800B1210: lhu         $t8, -0x778($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X778);
    // 0x800B1214: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1218: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800B121C: sh          $t7, -0x778($at)
    MEM_H(-0X778, ctx->r1) = ctx->r15;
    // 0x800B1220: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800B1224: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800B1228: nop

    // 0x800B122C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B1230: b           L_800B1238
    // 0x800B1234: nop

        goto L_800B1238;
    // 0x800B1234: nop

L_800B1238:
    // 0x800B1238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B123C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B1240: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B1244: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B1248: jr          $ra
    // 0x800B124C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800B124C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80045318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045318: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8004531C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80045320: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80045324: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80045328: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x8004532C: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80045330: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x80045334: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80045338: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x8004533C: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80045340: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80045344: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80045348: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8004534C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80045350: addiu       $t7, $t7, -0x2AF8
    ctx->r15 = ADD32(ctx->r15, -0X2AF8);
    // 0x80045354: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80045358: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8004535C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80045360: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80045364: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80045368: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8004536C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80045370: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x80045374: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80045378: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8004537C: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80045380: lhu         $at, 0x18($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X18);
    // 0x80045384: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x80045388: sh          $at, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r1;
    // 0x8004538C: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x80045390: jal         0x800AF060
    // 0x80045394: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x80045394: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80045398: jal         0x800A41B4
    // 0x8004539C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x8004539C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x800453A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800453A4: addiu       $a1, $a1, -0x3FD0
    ctx->r5 = ADD32(ctx->r5, -0X3FD0);
    // 0x800453A8: jal         0x800A5624
    // 0x800453AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_2;
    // 0x800453AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800453B0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800453B4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800453B8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800453BC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800453C0: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    // 0x800453C4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800453C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800453CC: jal         0x800A57C4
    // 0x800453D0: addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    func_800A57C4(rdram, ctx);
        goto after_3;
    // 0x800453D0: addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    after_3:
    // 0x800453D4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800453D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800453DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800453E0: swc1        $f4, 0x25D0($at)
    MEM_W(0X25D0, ctx->r1) = ctx->f4.u32l;
    // 0x800453E4: addiu       $t2, $zero, 0x5DC
    ctx->r10 = ADD32(0, 0X5DC);
    // 0x800453E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800453EC: sw          $t2, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r10;
    // 0x800453F0: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800453F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800453F8: sw          $t3, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r11;
    // 0x800453FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80045400: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80045404: swc1        $f6, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f6.u32l;
    // 0x80045408: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004540C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80045410: sb          $t4, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = ctx->r12;
    // 0x80045414: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80045418: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
    // 0x8004541C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80045420: sh          $zero, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = 0;
    // 0x80045424: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80045428: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004542C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80045430: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80045434: swc1        $f8, 0x718($t5)
    MEM_W(0X718, ctx->r13) = ctx->f8.u32l;
    // 0x80045438: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8004543C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80045440: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80045444: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x80045448: swc1        $f10, 0x71C($t8)
    MEM_W(0X71C, ctx->r24) = ctx->f10.u32l;
    // 0x8004544C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80045450: addiu       $t7, $t7, 0x61D8
    ctx->r15 = ADD32(ctx->r15, 0X61D8);
    // 0x80045454: addiu       $t6, $zero, 0x155
    ctx->r14 = ADD32(0, 0X155);
    // 0x80045458: sh          $t6, 0x69C($t7)
    MEM_H(0X69C, ctx->r15) = ctx->r14;
    // 0x8004545C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80045460: addiu       $t0, $t0, 0x61D8
    ctx->r8 = ADD32(ctx->r8, 0X61D8);
    // 0x80045464: addiu       $t9, $zero, 0x1FF
    ctx->r25 = ADD32(0, 0X1FF);
    // 0x80045468: sh          $t9, 0x6A4($t0)
    MEM_H(0X6A4, ctx->r8) = ctx->r25;
    // 0x8004546C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80045470: addiu       $t2, $t2, 0x61D8
    ctx->r10 = ADD32(ctx->r10, 0X61D8);
    // 0x80045474: addiu       $t1, $zero, 0x155
    ctx->r9 = ADD32(0, 0X155);
    // 0x80045478: sh          $t1, 0x6AC($t2)
    MEM_H(0X6AC, ctx->r10) = ctx->r9;
    // 0x8004547C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80045480: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x80045484: addiu       $t3, $zero, 0x1FF
    ctx->r11 = ADD32(0, 0X1FF);
    // 0x80045488: sh          $t3, 0x6B4($t4)
    MEM_H(0X6B4, ctx->r12) = ctx->r11;
    // 0x8004548C: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_80045490:
    // 0x80045490: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x80045494: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80045498: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8004549C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800454A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800454A4: lw          $t6, -0x73D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73D0);
    // 0x800454A8: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800454AC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800454B0: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800454B4: lw          $t9, 0xC0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC0);
    // 0x800454B8: nop

    // 0x800454BC: ori         $t0, $t9, 0x8240
    ctx->r8 = ctx->r25 | 0X8240;
    // 0x800454C0: sw          $t0, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r8;
    // 0x800454C4: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x800454C8: nop

    // 0x800454CC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800454D0: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x800454D4: bne         $at, $zero, L_80045490
    if (ctx->r1 != 0) {
        // 0x800454D8: sw          $t2, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r10;
            goto L_80045490;
    }
    // 0x800454D8: sw          $t2, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r10;
    // 0x800454DC: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_800454E0:
    // 0x800454E0: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x800454E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800454E8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800454EC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800454F0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800454F4: lw          $t5, 0x263C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X263C);
    // 0x800454F8: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800454FC: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80045500: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x80045504: lw          $t6, 0xC0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC0);
    // 0x80045508: nop

    // 0x8004550C: ori         $t9, $t6, 0x8240
    ctx->r25 = ctx->r14 | 0X8240;
    // 0x80045510: sw          $t9, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r25;
    // 0x80045514: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80045518: nop

    // 0x8004551C: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80045520: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80045524: bne         $at, $zero, L_800454E0
    if (ctx->r1 != 0) {
        // 0x80045528: sw          $t7, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r15;
            goto L_800454E0;
    }
    // 0x80045528: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8004552C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80045530: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x80045534: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80045538: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8004553C: nop

    // 0x80045540: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80045544: beq         $t3, $zero, L_800455B0
    if (ctx->r11 == 0) {
        // 0x80045548: nop
    
            goto L_800455B0;
    }
    // 0x80045548: nop

    // 0x8004554C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80045550: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80045554: nop

    // 0x80045558: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x8004555C: nop

    // 0x80045560: ori         $t6, $t5, 0x8240
    ctx->r14 = ctx->r13 | 0X8240;
    // 0x80045564: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x80045568: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8004556C: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80045570: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80045574: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x80045578: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8004557C: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80045580: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x80045584: nop

    // 0x80045588: andi        $t1, $t7, 0x200
    ctx->r9 = ctx->r15 & 0X200;
    // 0x8004558C: beq         $t1, $zero, L_800455B0
    if (ctx->r9 == 0) {
        // 0x80045590: nop
    
            goto L_800455B0;
    }
    // 0x80045590: nop

    // 0x80045594: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80045598: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8004559C: nop

    // 0x800455A0: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800455A4: nop

    // 0x800455A8: ori         $t5, $t3, 0x80
    ctx->r13 = ctx->r11 | 0X80;
    // 0x800455AC: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
L_800455B0:
    // 0x800455B0: jal         0x80043E20
    // 0x800455B4: nop

    func_80043E20(rdram, ctx);
        goto after_4;
    // 0x800455B4: nop

    after_4:
    // 0x800455B8: jal         0x800BC6EC
    // 0x800455BC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x800455BC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_5:
    // 0x800455C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800455C4: sw          $v0, 0x7278($at)
    MEM_W(0X7278, ctx->r1) = ctx->r2;
    // 0x800455C8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800455CC: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x800455D0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800455D4: sh          $t6, 0x1C($t4)
    MEM_H(0X1C, ctx->r12) = ctx->r14;
    // 0x800455D8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800455DC: lw          $t9, 0x7278($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7278);
    // 0x800455E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800455E4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800455E8: swc1        $f16, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f16.u32l;
    // 0x800455EC: lw          $t8, 0x7278($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7278);
    // 0x800455F0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800455F4: lwc1        $f28, 0x18($t8)
    ctx->f28.u32l = MEM_W(ctx->r24, 0X18);
    // 0x800455F8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800455FC: swc1        $f28, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f28.u32l;
    // 0x80045600: lw          $t0, 0x7278($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7278);
    // 0x80045604: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x80045608: swc1        $f26, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f26.u32l;
    // 0x8004560C: lw          $t7, 0x7278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7278);
    // 0x80045610: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x80045614: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80045618: swc1        $f24, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f24.u32l;
    // 0x8004561C: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x80045620: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80045624: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80045628: swc1        $f22, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f22.u32l;
    // 0x8004562C: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x80045630: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80045634: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80045638: swc1        $f20, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f20.u32l;
    // 0x8004563C: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x80045640: nop

    // 0x80045644: swc1        $f20, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f20.u32l;
    // 0x80045648: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8004564C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80045650: lw          $t2, 0x7278($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7278);
    // 0x80045654: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80045658: nop

    // 0x8004565C: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
    // 0x80045660: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80045664: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80045668: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x8004566C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80045670: nop

    // 0x80045674: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x80045678: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004567C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80045680: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x80045684: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045688: nop

    // 0x8004568C: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
    // 0x80045690: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80045694: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80045698: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004569C: swc1        $f8, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f8.u32l;
    // 0x800456A0: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
    // 0x800456A4: jal         0x800BC6EC
    // 0x800456A8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800456A8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_6:
    // 0x800456AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800456B0: sw          $v0, 0x722C($at)
    MEM_W(0X722C, ctx->r1) = ctx->r2;
    // 0x800456B4: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x800456B8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800456BC: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800456C0: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x800456C4: lhu         $t0, 0x70($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X70);
    // 0x800456C8: nop

    // 0x800456CC: beq         $t0, $at, L_80045738
    if (ctx->r8 == ctx->r1) {
        // 0x800456D0: nop
    
            goto L_80045738;
    }
    // 0x800456D0: nop

L_800456D4:
    // 0x800456D4: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x800456D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800456DC: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x800456E0: addu        $a0, $sp, $t1
    ctx->r4 = ADD32(ctx->r29, ctx->r9);
    // 0x800456E4: lhu         $a0, 0x70($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X70);
    // 0x800456E8: jal         0x800AFB70
    // 0x800456EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_7;
    // 0x800456EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800456F0: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x800456F4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800456F8: lw          $t3, 0x722C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X722C);
    // 0x800456FC: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x80045700: addu        $t6, $t3, $t2
    ctx->r14 = ADD32(ctx->r11, ctx->r10);
    // 0x80045704: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80045708: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8004570C: nop

    // 0x80045710: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x80045714: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x80045718: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8004571C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80045720: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80045724: addu        $t7, $sp, $t0
    ctx->r15 = ADD32(ctx->r29, ctx->r8);
    // 0x80045728: lhu         $t7, 0x70($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X70);
    // 0x8004572C: nop

    // 0x80045730: bne         $t7, $at, L_800456D4
    if (ctx->r15 != ctx->r1) {
        // 0x80045734: nop
    
            goto L_800456D4;
    }
    // 0x80045734: nop

L_80045738:
    // 0x80045738: jal         0x800BC6EC
    // 0x8004573C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x8004573C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_8:
    // 0x80045740: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80045744: sw          $v0, 0x7284($at)
    MEM_W(0X7284, ctx->r1) = ctx->r2;
    // 0x80045748: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_8004574C:
    // 0x8004574C: jal         0x800BC6EC
    // 0x80045750: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_9;
    // 0x80045750: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_9:
    // 0x80045754: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x80045758: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004575C: lw          $t1, 0x7284($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7284);
    // 0x80045760: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x80045764: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x80045768: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8004576C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80045770: nop

    // 0x80045774: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x80045778: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8004577C: bne         $at, $zero, L_8004574C
    if (ctx->r1 != 0) {
        // 0x80045780: sw          $t4, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r12;
            goto L_8004574C;
    }
    // 0x80045780: sw          $t4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r12;
    // 0x80045784: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80045788: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8004578C: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80045790: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80045794: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x80045798: jal         0x800BD1FC
    // 0x8004579C: addiu       $a2, $a2, -0x1BD0
    ctx->r6 = ADD32(ctx->r6, -0X1BD0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_10;
    // 0x8004579C: addiu       $a2, $a2, -0x1BD0
    ctx->r6 = ADD32(ctx->r6, -0X1BD0);
    after_10:
    // 0x800457A0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800457A4: lw          $t9, 0x7284($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7284);
    // 0x800457A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800457AC: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800457B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800457B4: jal         0x800BD218
    // 0x800457B8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    SysMem_DmaCopy(rdram, ctx);
        goto after_11;
    // 0x800457B8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_11:
    // 0x800457BC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800457C0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800457C4: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800457C8: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800457CC: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x800457D0: jal         0x800BD1FC
    // 0x800457D4: addiu       $a2, $a2, -0x1BA4
    ctx->r6 = ADD32(ctx->r6, -0X1BA4);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_12;
    // 0x800457D4: addiu       $a2, $a2, -0x1BA4
    ctx->r6 = ADD32(ctx->r6, -0X1BA4);
    after_12:
    // 0x800457D8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800457DC: lw          $t8, 0x7284($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7284);
    // 0x800457E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800457E4: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x800457E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800457EC: jal         0x800BD218
    // 0x800457F0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    SysMem_DmaCopy(rdram, ctx);
        goto after_13;
    // 0x800457F0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_13:
    // 0x800457F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800457F8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800457FC: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80045800: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80045804: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x80045808: jal         0x800BD1FC
    // 0x8004580C: addiu       $a2, $a2, -0x1B18
    ctx->r6 = ADD32(ctx->r6, -0X1B18);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_14;
    // 0x8004580C: addiu       $a2, $a2, -0x1B18
    ctx->r6 = ADD32(ctx->r6, -0X1B18);
    after_14:
    // 0x80045810: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80045814: lw          $t0, 0x7284($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7284);
    // 0x80045818: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004581C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x80045820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80045824: jal         0x800BD218
    // 0x80045828: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    SysMem_DmaCopy(rdram, ctx);
        goto after_15;
    // 0x80045828: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_15:
    // 0x8004582C: jal         0x800BC6EC
    // 0x80045830: addiu       $a0, $zero, 0xAE8
    ctx->r4 = ADD32(0, 0XAE8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_16;
    // 0x80045830: addiu       $a0, $zero, 0xAE8
    ctx->r4 = ADD32(0, 0XAE8);
    after_16:
    // 0x80045834: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80045838: sw          $v0, 0x7298($at)
    MEM_W(0X7298, ctx->r1) = ctx->r2;
    // 0x8004583C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80045840: lw          $t7, 0x7298($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7298);
    // 0x80045844: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80045848: nop

    // 0x8004584C: swc1        $f10, 0xAE4($t7)
    MEM_W(0XAE4, ctx->r15) = ctx->f10.u32l;
    // 0x80045850: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80045854: lw          $t5, 0x7298($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7298);
    // 0x80045858: nop

    // 0x8004585C: sh          $zero, 0xAE0($t5)
    MEM_H(0XAE0, ctx->r13) = 0;
    // 0x80045860: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_80045864:
    // 0x80045864: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80045868: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004586C: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x80045870: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80045874: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80045878: lw          $t1, 0x7298($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7298);
    // 0x8004587C: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80045880: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80045884: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x80045888: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x8004588C: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x80045890: nop

    // 0x80045894: sh          $zero, 0xC($t4)
    MEM_H(0XC, ctx->r12) = 0;
    // 0x80045898: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8004589C: nop

    // 0x800458A0: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800458A4: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x800458A8: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x800458AC: nop

    // 0x800458B0: addiu       $t7, $t0, 0x190
    ctx->r15 = ADD32(ctx->r8, 0X190);
    // 0x800458B4: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    // 0x800458B8: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800458BC: jal         0x80099E2C
    // 0x800458C0: nop

    func_80099E2C(rdram, ctx);
        goto after_17;
    // 0x800458C0: nop

    after_17:
    // 0x800458C4: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x800458C8: lui         $t5, 0x4
    ctx->r13 = S32(0X4 << 16);
    // 0x800458CC: ori         $t5, $t5, 0x2004
    ctx->r13 = ctx->r13 | 0X2004;
    // 0x800458D0: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x800458D4: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x800458D8: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x800458DC: sw          $t1, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r9;
    // 0x800458E0: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x800458E4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800458E8: sh          $t6, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r14;
    // 0x800458EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800458F0: lwc1        $f16, -0x116C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X116C);
    // 0x800458F4: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x800458F8: nop

    // 0x800458FC: swc1        $f16, 0xFC($t9)
    MEM_W(0XFC, ctx->r25) = ctx->f16.u32l;
    // 0x80045900: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80045904: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80045908: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x8004590C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80045910: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80045914: lw          $t8, 0x7298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7298);
    // 0x80045918: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8004591C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80045920: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x80045924: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
    // 0x80045928: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x8004592C: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    // 0x80045930: jal         0x800B1B04
    // 0x80045934: nop

    func_800B1B04(rdram, ctx);
        goto after_18;
    // 0x80045934: nop

    after_18:
    // 0x80045938: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x8004593C: nop

    // 0x80045940: bgez        $t3, L_80045954
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80045944: andi        $t1, $t3, 0x1
        ctx->r9 = ctx->r11 & 0X1;
            goto L_80045954;
    }
    // 0x80045944: andi        $t1, $t3, 0x1
    ctx->r9 = ctx->r11 & 0X1;
    // 0x80045948: beq         $t1, $zero, L_80045954
    if (ctx->r9 == 0) {
        // 0x8004594C: nop
    
            goto L_80045954;
    }
    // 0x8004594C: nop

    // 0x80045950: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_80045954:
    // 0x80045954: beq         $t1, $zero, L_80045964
    if (ctx->r9 == 0) {
        // 0x80045958: nop
    
            goto L_80045964;
    }
    // 0x80045958: nop

    // 0x8004595C: b           L_80045968
    // 0x80045960: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80045968;
    // 0x80045960: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80045964:
    // 0x80045964: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80045968:
    // 0x80045968: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004596C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80045970: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80045974: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    // 0x80045978: lui         $a2, 0x69
    ctx->r6 = S32(0X69 << 16);
    // 0x8004597C: ori         $a2, $a2, 0x1E2
    ctx->r6 = ctx->r6 | 0X1E2;
    // 0x80045980: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x80045984: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80045988: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8004598C: jal         0x800B1F0C
    // 0x80045990: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_19;
    // 0x80045990: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x80045994: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x80045998: nop

    // 0x8004599C: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800459A0: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x800459A4: bne         $at, $zero, L_80045864
    if (ctx->r1 != 0) {
        // 0x800459A8: sw          $t6, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r14;
            goto L_80045864;
    }
    // 0x800459A8: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800459AC: jal         0x800BC6EC
    // 0x800459B0: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_20;
    // 0x800459B0: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    after_20:
    // 0x800459B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800459B8: sw          $v0, 0x72A4($at)
    MEM_W(0X72A4, ctx->r1) = ctx->r2;
    // 0x800459BC: jal         0x800BC6EC
    // 0x800459C0: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_21;
    // 0x800459C0: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    after_21:
    // 0x800459C4: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800459C8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800459CC: lw          $t9, 0x72A4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72A4);
    // 0x800459D0: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x800459D4: nop

    // 0x800459D8: sw          $t4, 0x14C($t9)
    MEM_W(0X14C, ctx->r25) = ctx->r12;
    // 0x800459DC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800459E0: lw          $t0, 0x72A4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72A4);
    // 0x800459E4: nop

    // 0x800459E8: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x800459EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800459F0: addiu       $t8, $t8, -0x40B0
    ctx->r24 = ADD32(ctx->r24, -0X40B0);
    // 0x800459F4: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800459F8: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800459FC: nop

    // 0x80045A00: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x80045A04: nop

    // 0x80045A08: beq         $t5, $zero, L_80045BF0
    if (ctx->r13 == 0) {
        // 0x80045A0C: nop
    
            goto L_80045BF0;
    }
    // 0x80045A0C: nop

L_80045A10:
    // 0x80045A10: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x80045A14: nop

    // 0x80045A18: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x80045A1C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80045A20: jal         0x800BC6EC
    // 0x80045A24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_22;
    // 0x80045A24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_22:
    // 0x80045A28: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x80045A2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80045A30: sw          $s0, 0x148($t2)
    MEM_W(0X148, ctx->r10) = ctx->r16;
    // 0x80045A34: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x80045A38: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80045A3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80045A40: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80045A44: lwc1        $f11, -0x1168($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1168);
    // 0x80045A48: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80045A4C: lwc1        $f10, -0x1164($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1164);
    // 0x80045A50: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80045A54: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80045A58: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80045A5C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80045A60: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x80045A64: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80045A68: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80045A6C: lbu         $t8, 0x6($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X6);
    // 0x80045A70: nop

    // 0x80045A74: sh          $t8, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r24;
    // 0x80045A78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80045A7C: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80045A80: nop

    // 0x80045A84: swc1        $f4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f4.u32l;
    // 0x80045A88: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80045A8C: nop

    // 0x80045A90: sh          $zero, 0xE($t3)
    MEM_H(0XE, ctx->r11) = 0;
    // 0x80045A94: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80045A98: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80045A9C: sh          $t1, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r9;
    // 0x80045AA0: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80045AA4: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80045AA8: lh          $t4, 0x2($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X2);
    // 0x80045AAC: nop

    // 0x80045AB0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80045AB4: nop

    // 0x80045AB8: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80045ABC: swc1        $f20, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f20.u32l;
    // 0x80045AC0: swc1        $f20, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f20.u32l;
    // 0x80045AC4: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80045AC8: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80045ACC: lh          $t8, 0x4($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X4);
    // 0x80045AD0: nop

    // 0x80045AD4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80045AD8: nop

    // 0x80045ADC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80045AE0: swc1        $f10, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f10.u32l;
    // 0x80045AE4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80045AE8: nop

    // 0x80045AEC: swc1        $f16, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f16.u32l;
    // 0x80045AF0: lwc1        $f18, 0xC8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80045AF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80045AF8: nop

    // 0x80045AFC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80045B00: nop

    // 0x80045B04: bc1f        L_80045B1C
    if (!c1cs) {
        // 0x80045B08: nop
    
            goto L_80045B1C;
    }
    // 0x80045B08: nop

    // 0x80045B0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80045B10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045B14: nop

    // 0x80045B18: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
L_80045B1C:
    // 0x80045B1C: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80045B20: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80045B24: nop

    // 0x80045B28: swc1        $f8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f8.u32l;
    // 0x80045B2C: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x80045B30: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80045B34: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80045B38: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x80045B3C: nop

    // 0x80045B40: sh          $zero, 0x2($t2)
    MEM_H(0X2, ctx->r10) = 0;
    // 0x80045B44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80045B48: lwc1        $f10, -0x1160($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1160);
    // 0x80045B4C: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x80045B50: nop

    // 0x80045B54: swc1        $f10, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f10.u32l;
    // 0x80045B58: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x80045B5C: nop

    // 0x80045B60: sw          $zero, 0x14C($t4)
    MEM_W(0X14C, ctx->r12) = 0;
    // 0x80045B64: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80045B68: lw          $t9, 0x722C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X722C);
    // 0x80045B6C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80045B70: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80045B74: jal         0x800A424C
    // 0x80045B78: nop

    func_800A424C(rdram, ctx);
        goto after_23;
    // 0x80045B78: nop

    after_23:
    // 0x80045B7C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80045B80: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80045B84: sh          $t0, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r8;
    // 0x80045B88: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80045B8C: nop

    // 0x80045B90: lw          $t5, 0xC0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC0);
    // 0x80045B94: nop

    // 0x80045B98: ori         $t3, $t5, 0x2000
    ctx->r11 = ctx->r13 | 0X2000;
    // 0x80045B9C: sw          $t3, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r11;
    // 0x80045BA0: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x80045BA4: nop

    // 0x80045BA8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80045BAC: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
    // 0x80045BB0: jal         0x800BC6EC
    // 0x80045BB4: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_24;
    // 0x80045BB4: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    after_24:
    // 0x80045BB8: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x80045BBC: nop

    // 0x80045BC0: sw          $v0, 0x14C($t6)
    MEM_W(0X14C, ctx->r14) = ctx->r2;
    // 0x80045BC4: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x80045BC8: nop

    // 0x80045BCC: lw          $t9, 0x14C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14C);
    // 0x80045BD0: nop

    // 0x80045BD4: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x80045BD8: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80045BDC: nop

    // 0x80045BE0: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x80045BE4: nop

    // 0x80045BE8: bne         $t8, $zero, L_80045A10
    if (ctx->r24 != 0) {
        // 0x80045BEC: nop
    
            goto L_80045A10;
    }
    // 0x80045BEC: nop

L_80045BF0:
    // 0x80045BF0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80045BF4: addiu       $t5, $t5, -0x4058
    ctx->r13 = ADD32(ctx->r13, -0X4058);
    // 0x80045BF8: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
    // 0x80045BFC: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x80045C00: nop

    // 0x80045C04: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80045C08: nop

    // 0x80045C0C: beq         $t7, $zero, L_80045DAC
    if (ctx->r15 == 0) {
        // 0x80045C10: nop
    
            goto L_80045DAC;
    }
    // 0x80045C10: nop

L_80045C14:
    // 0x80045C14: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x80045C18: nop

    // 0x80045C1C: addiu       $t2, $t1, 0x30
    ctx->r10 = ADD32(ctx->r9, 0X30);
    // 0x80045C20: sw          $t2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r10;
    // 0x80045C24: jal         0x800BC6EC
    // 0x80045C28: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_25;
    // 0x80045C28: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_25:
    // 0x80045C2C: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x80045C30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80045C34: sw          $s0, 0x148($t6)
    MEM_W(0X148, ctx->r14) = ctx->r16;
    // 0x80045C38: sw          $s0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r16;
    // 0x80045C3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80045C40: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x80045C44: nop

    // 0x80045C48: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
    // 0x80045C4C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80045C50: nop

    // 0x80045C54: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x80045C58: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x80045C5C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80045C60: sh          $t0, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r8;
    // 0x80045C64: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x80045C68: nop

    // 0x80045C6C: sh          $zero, 0x8($t5)
    MEM_H(0X8, ctx->r13) = 0;
    // 0x80045C70: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x80045C74: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x80045C78: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80045C7C: nop

    // 0x80045C80: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80045C84: nop

    // 0x80045C88: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80045C8C: swc1        $f4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f4.u32l;
    // 0x80045C90: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x80045C94: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x80045C98: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x80045C9C: nop

    // 0x80045CA0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80045CA4: nop

    // 0x80045CA8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80045CAC: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x80045CB0: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x80045CB4: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x80045CB8: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80045CBC: nop

    // 0x80045CC0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80045CC4: nop

    // 0x80045CC8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80045CCC: swc1        $f16, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f16.u32l;
    // 0x80045CD0: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x80045CD4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80045CD8: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
    // 0x80045CDC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80045CE0: nop

    // 0x80045CE4: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x80045CE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80045CEC: lwc1        $f18, -0x115C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X115C);
    // 0x80045CF0: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x80045CF4: nop

    // 0x80045CF8: swc1        $f18, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f18.u32l;
    // 0x80045CFC: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x80045D00: nop

    // 0x80045D04: sw          $zero, 0x14C($t2)
    MEM_W(0X14C, ctx->r10) = 0;
    // 0x80045D08: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80045D0C: lw          $t6, 0x722C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X722C);
    // 0x80045D10: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80045D14: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80045D18: jal         0x800A424C
    // 0x80045D1C: nop

    func_800A424C(rdram, ctx);
        goto after_26;
    // 0x80045D1C: nop

    after_26:
    // 0x80045D20: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80045D24: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80045D28: sh          $t4, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r12;
    // 0x80045D2C: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80045D30: nop

    // 0x80045D34: lw          $t8, 0xC0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC0);
    // 0x80045D38: nop

    // 0x80045D3C: ori         $t5, $t8, 0x2000
    ctx->r13 = ctx->r24 | 0X2000;
    // 0x80045D40: sw          $t5, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r13;
    // 0x80045D44: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x80045D48: nop

    // 0x80045D4C: addiu       $t7, $t3, 0x6
    ctx->r15 = ADD32(ctx->r11, 0X6);
    // 0x80045D50: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x80045D54: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80045D58: nop

    // 0x80045D5C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80045D60: nop

    // 0x80045D64: beq         $t2, $zero, L_80045D94
    if (ctx->r10 == 0) {
        // 0x80045D68: nop
    
            goto L_80045D94;
    }
    // 0x80045D68: nop

    // 0x80045D6C: jal         0x800BC6EC
    // 0x80045D70: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_27;
    // 0x80045D70: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    after_27:
    // 0x80045D74: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x80045D78: nop

    // 0x80045D7C: sw          $v0, 0x14C($t6)
    MEM_W(0X14C, ctx->r14) = ctx->r2;
    // 0x80045D80: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x80045D84: nop

    // 0x80045D88: lw          $t9, 0x14C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14C);
    // 0x80045D8C: nop

    // 0x80045D90: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
L_80045D94:
    // 0x80045D94: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x80045D98: nop

    // 0x80045D9C: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80045DA0: nop

    // 0x80045DA4: bne         $t5, $zero, L_80045C14
    if (ctx->r13 != 0) {
        // 0x80045DA8: nop
    
            goto L_80045C14;
    }
    // 0x80045DA8: nop

L_80045DAC:
    // 0x80045DAC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80045DB0: addiu       $t0, $t0, -0x4038
    ctx->r8 = ADD32(ctx->r8, -0X4038);
    // 0x80045DB4: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    // 0x80045DB8: jal         0x800BC6EC
    // 0x80045DBC: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_28;
    // 0x80045DBC: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_28:
    // 0x80045DC0: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80045DC4: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80045DC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80045DCC: sw          $t3, 0x7240($at)
    MEM_W(0X7240, ctx->r1) = ctx->r11;
    // 0x80045DD0: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80045DD4: nop

    // 0x80045DD8: lh          $t1, 0x0($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X0);
    // 0x80045DDC: nop

    // 0x80045DE0: beq         $t1, $zero, L_80045F08
    if (ctx->r9 == 0) {
        // 0x80045DE4: nop
    
            goto L_80045F08;
    }
    // 0x80045DE4: nop

L_80045DE8:
    // 0x80045DE8: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80045DEC: nop

    // 0x80045DF0: addiu       $t6, $t2, 0x10
    ctx->r14 = ADD32(ctx->r10, 0X10);
    // 0x80045DF4: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x80045DF8: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x80045DFC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80045E00: lh          $t9, 0x0($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X0);
    // 0x80045E04: nop

    // 0x80045E08: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80045E0C: nop

    // 0x80045E10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80045E14: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x80045E18: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x80045E1C: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80045E20: lh          $t0, 0x2($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X2);
    // 0x80045E24: nop

    // 0x80045E28: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80045E2C: nop

    // 0x80045E30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80045E34: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x80045E38: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80045E3C: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80045E40: lh          $t1, 0x4($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X4);
    // 0x80045E44: nop

    // 0x80045E48: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80045E4C: nop

    // 0x80045E50: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80045E54: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x80045E58: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80045E5C: nop

    // 0x80045E60: sw          $zero, 0x128($t6)
    MEM_W(0X128, ctx->r14) = 0;
    // 0x80045E64: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80045E68: lw          $t4, 0x722C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X722C);
    // 0x80045E6C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80045E70: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x80045E74: jal         0x800A424C
    // 0x80045E78: nop

    func_800A424C(rdram, ctx);
        goto after_29;
    // 0x80045E78: nop

    after_29:
    // 0x80045E7C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80045E80: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80045E84: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x80045E88: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80045E8C: nop

    // 0x80045E90: lw          $t0, 0xC0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC0);
    // 0x80045E94: nop

    // 0x80045E98: ori         $t3, $t0, 0x2000
    ctx->r11 = ctx->r8 | 0X2000;
    // 0x80045E9C: sw          $t3, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r11;
    // 0x80045EA0: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80045EA4: nop

    // 0x80045EA8: addiu       $t1, $t7, 0x6
    ctx->r9 = ADD32(ctx->r15, 0X6);
    // 0x80045EAC: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x80045EB0: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x80045EB4: nop

    // 0x80045EB8: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x80045EBC: nop

    // 0x80045EC0: beq         $t6, $zero, L_80045EF0
    if (ctx->r14 == 0) {
        // 0x80045EC4: nop
    
            goto L_80045EF0;
    }
    // 0x80045EC4: nop

    // 0x80045EC8: jal         0x800BC6EC
    // 0x80045ECC: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_30;
    // 0x80045ECC: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_30:
    // 0x80045ED0: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80045ED4: nop

    // 0x80045ED8: sw          $v0, 0x128($t4)
    MEM_W(0X128, ctx->r12) = ctx->r2;
    // 0x80045EDC: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80045EE0: nop

    // 0x80045EE4: lw          $t8, 0x128($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X128);
    // 0x80045EE8: nop

    // 0x80045EEC: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
L_80045EF0:
    // 0x80045EF0: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80045EF4: nop

    // 0x80045EF8: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80045EFC: nop

    // 0x80045F00: bne         $t3, $zero, L_80045DE8
    if (ctx->r11 != 0) {
        // 0x80045F04: nop
    
            goto L_80045DE8;
    }
    // 0x80045F04: nop

L_80045F08:
    // 0x80045F08: jal         0x800BC6EC
    // 0x80045F0C: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_31;
    // 0x80045F0C: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_31:
    // 0x80045F10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80045F14: sw          $v0, 0x72C8($at)
    MEM_W(0X72C8, ctx->r1) = ctx->r2;
    // 0x80045F18: addiu       $a0, $zero, 0xF4
    ctx->r4 = ADD32(0, 0XF4);
    // 0x80045F1C: jal         0x800B08FC
    // 0x80045F20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B08FC(rdram, ctx);
        goto after_32;
    // 0x80045F20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80045F24: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80045F28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80045F2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045F30: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045F34: lw          $a0, 0x72C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72C8);
    // 0x80045F38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80045F3C: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x80045F40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80045F44: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80045F48: addiu       $a1, $zero, -0x2000
    ctx->r5 = ADD32(0, -0X2000);
    // 0x80045F4C: addiu       $a2, $zero, -0x2000
    ctx->r6 = ADD32(0, -0X2000);
    // 0x80045F50: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80045F54: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80045F58: jal         0x8003276C
    // 0x80045F5C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_8003276C(rdram, ctx);
        goto after_33;
    // 0x80045F5C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_33:
    // 0x80045F60: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045F64: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80045F68: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80045F6C: lw          $a0, 0x72C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72C8);
    // 0x80045F70: jal         0x80032844
    // 0x80045F74: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_80032844(rdram, ctx);
        goto after_34;
    // 0x80045F74: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_34:
    // 0x80045F78: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80045F7C: lw          $t1, 0x72C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72C8);
    // 0x80045F80: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80045F84: sh          $t7, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r15;
    // 0x80045F88: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80045F8C: lw          $t2, 0x72C8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72C8);
    // 0x80045F90: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80045F94: lw          $t6, 0xC0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC0);
    // 0x80045F98: nop

    // 0x80045F9C: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x80045FA0: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x80045FA4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80045FA8: lw          $t9, 0x72C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72C8);
    // 0x80045FAC: nop

    // 0x80045FB0: lw          $t8, 0xC0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0XC0);
    // 0x80045FB4: nop

    // 0x80045FB8: ori         $t0, $t8, 0x200
    ctx->r8 = ctx->r24 | 0X200;
    // 0x80045FBC: sw          $t0, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r8;
    // 0x80045FC0: jal         0x800BC6EC
    // 0x80045FC4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_35;
    // 0x80045FC4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_35:
    // 0x80045FC8: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80045FCC: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x80045FD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80045FD4: sw          $t3, 0x7260($at)
    MEM_W(0X7260, ctx->r1) = ctx->r11;
    // 0x80045FD8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80045FDC: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x80045FE0: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80045FE4: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80045FE8: nop

    // 0x80045FEC: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x80045FF0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80045FF4: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x80045FF8: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80045FFC: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80046000: nop

    // 0x80046004: swc1        $f10, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f10.u32l;
    // 0x80046008: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004600C: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80046010: nop

    // 0x80046014: swc1        $f16, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f16.u32l;
    // 0x80046018: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8004601C: nop

    // 0x80046020: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80046024: nop

    // 0x80046028: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x8004602C: jal         0x800BC6EC
    // 0x80046030: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_36;
    // 0x80046030: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    after_36:
    // 0x80046034: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046038: sw          $v0, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r2;
    // 0x8004603C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80046040: lw          $t8, 0x7214($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7214);
    // 0x80046044: nop

    // 0x80046048: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8004604C: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_80046050:
    // 0x80046050: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x80046054: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80046058: nop

    // 0x8004605C: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x80046060: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x80046064: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x80046068: nop

    // 0x8004606C: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80046070: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80046074: bne         $at, $zero, L_80046050
    if (ctx->r1 != 0) {
        // 0x80046078: sw          $t7, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r15;
            goto L_80046050;
    }
    // 0x80046078: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8004607C: jal         0x800BC6EC
    // 0x80046080: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_37;
    // 0x80046080: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    after_37:
    // 0x80046084: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046088: sw          $v0, 0x7220($at)
    MEM_W(0X7220, ctx->r1) = ctx->r2;
    // 0x8004608C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80046090: lw          $t1, 0x7220($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7220);
    // 0x80046094: nop

    // 0x80046098: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x8004609C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800460A0: nop

    // 0x800460A4: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x800460A8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x800460AC: nop

    // 0x800460B0: addiu       $t2, $t4, 0x160
    ctx->r10 = ADD32(ctx->r12, 0X160);
    // 0x800460B4: sw          $t2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r10;
    // 0x800460B8: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800460BC: jal         0x80099E2C
    // 0x800460C0: nop

    func_80099E2C(rdram, ctx);
        goto after_38;
    // 0x800460C0: nop

    after_38:
    // 0x800460C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800460C8: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800460CC: nop

    // 0x800460D0: swc1        $f4, 0xD4($t8)
    MEM_W(0XD4, ctx->r24) = ctx->f4.u32l;
    // 0x800460D4: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800460D8: nop

    // 0x800460DC: lwc1        $f6, 0xD4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XD4);
    // 0x800460E0: nop

    // 0x800460E4: swc1        $f6, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f6.u32l;
    // 0x800460E8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800460EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800460F0: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x800460F4: nop

    // 0x800460F8: swc1        $f8, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f8.u32l;
    // 0x800460FC: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x80046100: lui         $t3, 0x4
    ctx->r11 = S32(0X4 << 16);
    // 0x80046104: ori         $t3, $t3, 0x8004
    ctx->r11 = ctx->r11 | 0X8004;
    // 0x80046108: sw          $t3, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r11;
    // 0x8004610C: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x80046110: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80046114: sw          $t7, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r15;
    // 0x80046118: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x8004611C: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80046120: sh          $t6, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r14;
    // 0x80046124: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80046128: lwc1        $f10, -0x1158($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1158);
    // 0x8004612C: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x80046130: nop

    // 0x80046134: swc1        $f10, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->f10.u32l;
    // 0x80046138: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x8004613C: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    // 0x80046140: jal         0x800B1B04
    // 0x80046144: nop

    func_800B1B04(rdram, ctx);
        goto after_39;
    // 0x80046144: nop

    after_39:
    // 0x80046148: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004614C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80046150: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80046154: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    // 0x80046158: lui         $a2, 0x69
    ctx->r6 = S32(0X69 << 16);
    // 0x8004615C: ori         $a2, $a2, 0x21F
    ctx->r6 = ctx->r6 | 0X21F;
    // 0x80046160: addiu       $a3, $zero, 0x55
    ctx->r7 = ADD32(0, 0X55);
    // 0x80046164: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80046168: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8004616C: jal         0x800B1F0C
    // 0x80046170: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_40;
    // 0x80046170: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_40:
    // 0x80046174: jal         0x800BC6EC
    // 0x80046178: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_41;
    // 0x80046178: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    after_41:
    // 0x8004617C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80046180: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80046184: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80046188: sw          $t8, 0x103C($at)
    MEM_W(0X103C, ctx->r1) = ctx->r24;
    // 0x8004618C: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x80046190: nop

    // 0x80046194: sb          $zero, 0x1A8($t0)
    MEM_B(0X1A8, ctx->r8) = 0;
    // 0x80046198: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004619C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800461A0: nop

    // 0x800461A4: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800461A8: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x800461AC: nop

    // 0x800461B0: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800461B4: sw          $t5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r13;
    // 0x800461B8: jal         0x80099E2C
    // 0x800461BC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80099E2C(rdram, ctx);
        goto after_42;
    // 0x800461BC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_42:
    // 0x800461C0: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800461C4: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800461C8: addiu       $t1, $t7, 0x168
    ctx->r9 = ADD32(ctx->r15, 0X168);
    // 0x800461CC: sw          $t1, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r9;
    // 0x800461D0: jal         0x800B1B04
    // 0x800461D4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_800B1B04(rdram, ctx);
        goto after_43;
    // 0x800461D4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_43:
    // 0x800461D8: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x800461DC: ori         $t6, $zero, 0x8214
    ctx->r14 = 0 | 0X8214;
    // 0x800461E0: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x800461E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800461E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800461EC: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800461F0: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    // 0x800461F4: lui         $a2, 0xAE
    ctx->r6 = S32(0XAE << 16);
    // 0x800461F8: ori         $a2, $a2, 0x252
    ctx->r6 = ctx->r6 | 0X252;
    // 0x800461FC: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x80046200: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80046204: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80046208: jal         0x800B1F0C
    // 0x8004620C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_44;
    // 0x8004620C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_44:
    // 0x80046210: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x80046214: addiu       $t2, $zero, 0x7FFF
    ctx->r10 = ADD32(0, 0X7FFF);
    // 0x80046218: sw          $t2, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r10;
    // 0x8004621C: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80046220: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80046224: sh          $t0, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r8;
    // 0x80046228: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x8004622C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80046230: sh          $t3, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r11;
    // 0x80046234: lui         $at, 0x42B0
    ctx->r1 = S32(0X42B0 << 16);
    // 0x80046238: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004623C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80046240: nop

    // 0x80046244: swc1        $f10, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f10.u32l;
    // 0x80046248: lui         $at, 0xC258
    ctx->r1 = S32(0XC258 << 16);
    // 0x8004624C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80046250: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x80046254: nop

    // 0x80046258: swc1        $f16, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f16.u32l;
    // 0x8004625C: b           L_80046264
    // 0x80046260: nop

        goto L_80046264;
    // 0x80046260: nop

L_80046264:
    // 0x80046264: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80046268: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8004626C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80046270: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80046274: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80046278: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8004627C: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80046280: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80046284: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80046288: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8004628C: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80046290: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80046294: jr          $ra
    // 0x80046298: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80046298: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_80062C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C40: jal         0x80061488
    // 0x80062C44: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062C44: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    after_0:
    // 0x80062C48: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062C4C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062C50: b           L_80062C60
    // 0x80062C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062C60;
    // 0x80062C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062C58: b           L_80062C60
    // 0x80062C5C: nop

        goto L_80062C60;
    // 0x80062C5C: nop

L_80062C60:
    // 0x80062C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062C68: jr          $ra
    // 0x80062C6C: nop

    return;
    // 0x80062C6C: nop

;}
RECOMP_FUNC void func_8006489C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006489C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800648A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800648A4: jal         0x80061488
    // 0x800648A8: addiu       $a0, $zero, 0x632
    ctx->r4 = ADD32(0, 0X632);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800648A8: addiu       $a0, $zero, 0x632
    ctx->r4 = ADD32(0, 0X632);
    after_0:
    // 0x800648AC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800648B0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800648B4: b           L_800648C4
    // 0x800648B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800648C4;
    // 0x800648B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800648BC: b           L_800648C4
    // 0x800648C0: nop

        goto L_800648C4;
    // 0x800648C0: nop

L_800648C4:
    // 0x800648C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800648C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800648CC: jr          $ra
    // 0x800648D0: nop

    return;
    // 0x800648D0: nop

;}
RECOMP_FUNC void func_80004654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000465C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80004660: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80004664:
    // 0x80004664: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80004668: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000466C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80004670: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80004674: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004678: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000467C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004680: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80004684: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x80004688: nop

    // 0x8000468C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80004690: bne         $t9, $zero, L_800046AC
    if (ctx->r25 != 0) {
        // 0x80004694: nop
    
            goto L_800046AC;
    }
    // 0x80004694: nop

    // 0x80004698: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x8000469C: bne         $t0, $zero, L_800046AC
    if (ctx->r8 != 0) {
        // 0x800046A0: nop
    
            goto L_800046AC;
    }
    // 0x800046A0: nop

    // 0x800046A4: b           L_800046C4
    // 0x800046A8: nop

        goto L_800046C4;
    // 0x800046A8: nop

L_800046AC:
    // 0x800046AC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800046B0: nop

    // 0x800046B4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800046B8: slti        $at, $t2, 0x20
    ctx->r1 = SIGNED(ctx->r10) < 0X20 ? 1 : 0;
    // 0x800046BC: bne         $at, $zero, L_80004664
    if (ctx->r1 != 0) {
        // 0x800046C0: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_80004664;
    }
    // 0x800046C0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800046C4:
    // 0x800046C4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800046C8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800046CC: bne         $t3, $at, L_800046DC
    if (ctx->r11 != ctx->r1) {
        // 0x800046D0: nop
    
            goto L_800046DC;
    }
    // 0x800046D0: nop

    // 0x800046D4: b           L_800047B8
    // 0x800046D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800047B8;
    // 0x800046D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800046DC:
    // 0x800046DC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800046E0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800046E4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800046E8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800046EC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800046F0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800046F4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800046F8: addiu       $t6, $t6, 0x6C20
    ctx->r14 = ADD32(ctx->r14, 0X6C20);
    // 0x800046FC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80004700: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80004704: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80004708: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000470C: sw          $t9, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->r25;
    // 0x80004710: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80004714: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80004718: nop

    // 0x8000471C: sw          $t0, 0x1A4($t1)
    MEM_W(0X1A4, ctx->r9) = ctx->r8;
    // 0x80004720: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80004724: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80004728: lw          $t3, 0x1A4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A4);
    // 0x8000472C: nop

    // 0x80004730: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80004734: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80004738: lw          $t5, -0x2490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2490);
    // 0x8000473C: nop

    // 0x80004740: bne         $t5, $zero, L_8000475C
    if (ctx->r13 != 0) {
        // 0x80004744: nop
    
            goto L_8000475C;
    }
    // 0x80004744: nop

    // 0x80004748: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000474C: nop

    // 0x80004750: sw          $zero, 0x1A0($t6)
    MEM_W(0X1A0, ctx->r14) = 0;
    // 0x80004754: b           L_800047B8
    // 0x80004758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800047B8;
    // 0x80004758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000475C:
    // 0x8000475C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80004760: nop

    // 0x80004764: lw          $t9, 0x1A4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1A4);
    // 0x80004768: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8000476C: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x80004770: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80004774: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80004778: lw          $t9, -0x2490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2490);
    // 0x8000477C: nop

    // 0x80004780: jalr        $t9
    // 0x80004784: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80004784: nop

    after_0:
    // 0x80004788: bgez        $v0, L_8000479C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000478C: nop
    
            goto L_8000479C;
    }
    // 0x8000478C: nop

    // 0x80004790: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80004794: nop

    // 0x80004798: sw          $zero, 0x1A0($t0)
    MEM_W(0X1A0, ctx->r8) = 0;
L_8000479C:
    // 0x8000479C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800047A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800047A4: sw          $t1, 0x6C10($at)
    MEM_W(0X6C10, ctx->r1) = ctx->r9;
    // 0x800047A8: b           L_800047B8
    // 0x800047AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800047B8;
    // 0x800047AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800047B0: b           L_800047B8
    // 0x800047B4: nop

        goto L_800047B8;
    // 0x800047B4: nop

L_800047B8:
    // 0x800047B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800047BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800047C0: jr          $ra
    // 0x800047C4: nop

    return;
    // 0x800047C4: nop

;}
RECOMP_FUNC void func_80070C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070C80: jal         0x80061348
    // 0x80070C84: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070C84: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070C88: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070C8C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070C90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070C94: beq         $v0, $zero, L_80070CE8
    if (ctx->r2 == 0) {
        // 0x80070C98: nop
    
            goto L_80070CE8;
    }
    // 0x80070C98: nop

    // 0x80070C9C: jal         0x80061348
    // 0x80070CA0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070CA0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070CA4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070CA8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070CAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070CB0: beq         $v0, $zero, L_80070CE8
    if (ctx->r2 == 0) {
        // 0x80070CB4: nop
    
            goto L_80070CE8;
    }
    // 0x80070CB4: nop

    // 0x80070CB8: jal         0x80061348
    // 0x80070CBC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070CBC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070CC0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070CC4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070CC8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070CCC: beq         $v0, $zero, L_80070CE8
    if (ctx->r2 == 0) {
        // 0x80070CD0: nop
    
            goto L_80070CE8;
    }
    // 0x80070CD0: nop

    // 0x80070CD4: jal         0x80061348
    // 0x80070CD8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070CD8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070CDC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070CE0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070CE4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070CE8:
    // 0x80070CE8: b           L_80070CF8
    // 0x80070CEC: nop

        goto L_80070CF8;
    // 0x80070CEC: nop

    // 0x80070CF0: b           L_80070CF8
    // 0x80070CF4: nop

        goto L_80070CF8;
    // 0x80070CF4: nop

L_80070CF8:
    // 0x80070CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070D00: jr          $ra
    // 0x80070D04: nop

    return;
    // 0x80070D04: nop

;}
RECOMP_FUNC void func_800640CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800640CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800640D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800640D4: jal         0x8005F064
    // 0x800640D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800640D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x800640DC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800640E0: b           L_800640F0
    // 0x800640E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800640F0;
    // 0x800640E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800640E8: b           L_800640F0
    // 0x800640EC: nop

        goto L_800640F0;
    // 0x800640EC: nop

L_800640F0:
    // 0x800640F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800640F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800640F8: jr          $ra
    // 0x800640FC: nop

    return;
    // 0x800640FC: nop

;}
RECOMP_FUNC void func_800744DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800744DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800744E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800744E4: jal         0x80061348
    // 0x800744E8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800744E8: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x800744EC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800744F0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800744F4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800744F8: beq         $v0, $zero, L_8007454C
    if (ctx->r2 == 0) {
        // 0x800744FC: nop
    
            goto L_8007454C;
    }
    // 0x800744FC: nop

    // 0x80074500: jal         0x80061348
    // 0x80074504: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074504: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074508: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007450C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074510: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074514: beq         $v0, $zero, L_8007454C
    if (ctx->r2 == 0) {
        // 0x80074518: nop
    
            goto L_8007454C;
    }
    // 0x80074518: nop

    // 0x8007451C: jal         0x80061348
    // 0x80074520: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074520: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x80074524: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074528: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007452C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074530: beq         $v0, $zero, L_8007454C
    if (ctx->r2 == 0) {
        // 0x80074534: nop
    
            goto L_8007454C;
    }
    // 0x80074534: nop

    // 0x80074538: jal         0x80061348
    // 0x8007453C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007453C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074540: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074544: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074548: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007454C:
    // 0x8007454C: b           L_8007455C
    // 0x80074550: nop

        goto L_8007455C;
    // 0x80074550: nop

    // 0x80074554: b           L_8007455C
    // 0x80074558: nop

        goto L_8007455C;
    // 0x80074558: nop

L_8007455C:
    // 0x8007455C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074564: jr          $ra
    // 0x80074568: nop

    return;
    // 0x80074568: nop

;}
RECOMP_FUNC void func_80034CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034CA0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80034CA4: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80034CA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80034CAC: lwc1        $f7, -0x1678($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1678);
    // 0x80034CB0: lwc1        $f6, -0x1674($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1674);
    // 0x80034CB4: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80034CB8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80034CBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80034CC0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80034CC4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034CC8: nop

    // 0x80034CCC: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80034CD0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034CD4: nop

    // 0x80034CD8: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80034CDC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80034CE0: beq         $t7, $zero, L_80034D38
    if (ctx->r15 == 0) {
        // 0x80034CE4: nop
    
            goto L_80034D38;
    }
    // 0x80034CE4: nop

    // 0x80034CE8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80034CEC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80034CF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034CF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80034CF8: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x80034CFC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034D00: nop

    // 0x80034D04: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x80034D08: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034D0C: nop

    // 0x80034D10: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80034D14: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80034D18: bne         $t7, $zero, L_80034D30
    if (ctx->r15 != 0) {
        // 0x80034D1C: nop
    
            goto L_80034D30;
    }
    // 0x80034D1C: nop

    // 0x80034D20: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80034D24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034D28: b           L_80034D48
    // 0x80034D2C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80034D48;
    // 0x80034D2C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80034D30:
    // 0x80034D30: b           L_80034D48
    // 0x80034D34: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80034D48;
    // 0x80034D34: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80034D38:
    // 0x80034D38: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80034D3C: nop

    // 0x80034D40: bltz        $t7, L_80034D30
    if (SIGNED(ctx->r15) < 0) {
        // 0x80034D44: nop
    
            goto L_80034D30;
    }
    // 0x80034D44: nop

L_80034D48:
    // 0x80034D48: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80034D4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80034D50: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80034D54: lw          $t0, 0x71FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X71FC);
    // 0x80034D58: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80034D5C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80034D60: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80034D64: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80034D68: sll         $t9, $t9, 7
    ctx->r25 = S32(ctx->r25 << 7);
    // 0x80034D6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80034D70: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x80034D74: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80034D78: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80034D7C: lwc1        $f19, -0x1670($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1670);
    // 0x80034D80: lwc1        $f18, -0x166C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X166C);
    // 0x80034D84: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x80034D88: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80034D8C: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80034D90: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80034D94: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80034D98: nop

    // 0x80034D9C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80034DA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80034DA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034DA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80034DAC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80034DB0: lwc1        $f17, -0x1668($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1668);
    // 0x80034DB4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80034DB8: lwc1        $f16, -0x1664($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1664);
    // 0x80034DBC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80034DC0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80034DC4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80034DC8: nop

    // 0x80034DCC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80034DD0: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80034DD4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80034DD8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80034DDC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80034DE0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80034DE4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034DE8: nop

    // 0x80034DEC: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x80034DF0: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80034DF4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80034DF8: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x80034DFC: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80034E00: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80034E04: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80034E08: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80034E0C: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x80034E10: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80034E14: nop

    // 0x80034E18: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
    // 0x80034E1C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034E20: lbu         $t6, 0x7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7);
    // 0x80034E24: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80034E28: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80034E2C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034E30: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x80034E34: cvt.w.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80034E38: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80034E3C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80034E40: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034E44: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80034E48: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80034E4C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80034E50: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80034E54: mfhi        $t2
    ctx->r10 = hi;
    // 0x80034E58: nop

    // 0x80034E5C: nop

    // 0x80034E60: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80034E64: mflo        $t8
    ctx->r24 = lo;
    // 0x80034E68: subu        $t4, $t3, $t8
    ctx->r12 = SUB32(ctx->r11, ctx->r24);
    // 0x80034E6C: srav        $t5, $t6, $t4
    ctx->r13 = S32(SIGNED(ctx->r14) >> (ctx->r12 & 31));
    // 0x80034E70: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80034E74: beq         $t7, $zero, L_80034E84
    if (ctx->r15 == 0) {
        // 0x80034E78: nop
    
            goto L_80034E84;
    }
    // 0x80034E78: nop

    // 0x80034E7C: b           L_80034E94
    // 0x80034E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80034E94;
    // 0x80034E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80034E84:
    // 0x80034E84: b           L_80034E94
    // 0x80034E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034E94;
    // 0x80034E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034E8C: b           L_80034E94
    // 0x80034E90: nop

        goto L_80034E94;
    // 0x80034E90: nop

L_80034E94:
    // 0x80034E94: jr          $ra
    // 0x80034E98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80034E98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80004CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004CD4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80004CD8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80004CDC: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80004CE0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80004CE4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80004CE8: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80004CEC: nop

    // 0x80004CF0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80004CF4: nop

    // 0x80004CF8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80004CFC: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80004D00: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80004D04: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80004D08: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80004D0C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80004D10: beq         $t0, $at, L_80004EE4
    if (ctx->r8 == ctx->r1) {
        // 0x80004D14: nop
    
            goto L_80004EE4;
    }
    // 0x80004D14: nop

L_80004D18:
    // 0x80004D18: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80004D1C: nop

    // 0x80004D20: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004D24: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x80004D28: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80004D2C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80004D30: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80004D34: nop

    // 0x80004D38: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80004D3C: addiu       $t6, $t4, 0x2
    ctx->r14 = ADD32(ctx->r12, 0X2);
    // 0x80004D40: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80004D44: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x80004D48: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x80004D4C: lui         $t8, 0x807A
    ctx->r24 = S32(0X807A << 16);
    // 0x80004D50: addiu       $t8, $t8, 0x80
    ctx->r24 = ADD32(ctx->r24, 0X80);
    // 0x80004D54: addiu       $t7, $t7, 0x1A20
    ctx->r15 = ADD32(ctx->r15, 0X1A20);
    // 0x80004D58: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80004D5C: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x80004D60: srl         $t9, $a0, 3
    ctx->r25 = S32(U32(ctx->r4) >> 3);
    // 0x80004D64: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80004D68: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x80004D6C: jal         0x800BC6EC
    // 0x80004D70: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80004D70: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
    // 0x80004D74: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80004D78: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80004D7C: nop

    // 0x80004D80: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x80004D84: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80004D88: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80004D8C: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x80004D90: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x80004D94: lui         $a2, 0x807A
    ctx->r6 = S32(0X807A << 16);
    // 0x80004D98: jal         0x800BD1FC
    // 0x80004D9C: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x80004D9C: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    after_1:
    // 0x80004DA0: lui         $t1, 0x807A
    ctx->r9 = S32(0X807A << 16);
    // 0x80004DA4: lui         $t3, 0x807A
    ctx->r11 = S32(0X807A << 16);
    // 0x80004DA8: addiu       $t3, $t3, 0x80
    ctx->r11 = ADD32(ctx->r11, 0X80);
    // 0x80004DAC: addiu       $t1, $t1, 0x1A20
    ctx->r9 = ADD32(ctx->r9, 0X1A20);
    // 0x80004DB0: subu        $a2, $t1, $t3
    ctx->r6 = SUB32(ctx->r9, ctx->r11);
    // 0x80004DB4: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x80004DB8: srl         $t5, $a2, 3
    ctx->r13 = S32(U32(ctx->r6) >> 3);
    // 0x80004DBC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80004DC0: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x80004DC4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004DC8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80004DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004DD0: jal         0x800BD218
    // 0x80004DD4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x80004DD4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_2:
L_80004DD8:
    // 0x80004DD8: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80004DDC: nop

    // 0x80004DE0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80004DE4: nop

    // 0x80004DE8: bne         $t7, $zero, L_80004E04
    if (ctx->r15 != 0) {
        // 0x80004DEC: nop
    
            goto L_80004E04;
    }
    // 0x80004DEC: nop

    // 0x80004DF0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80004DF4: jal         0x800BC980
    // 0x80004DF8: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80004DF8: nop

    after_3:
    // 0x80004DFC: b           L_80005114
    // 0x80004E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005114;
    // 0x80004E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80004E04:
    // 0x80004E04: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E08: lhu         $t0, 0x42($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X42);
    // 0x80004E0C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80004E10: nop

    // 0x80004E14: bne         $t9, $t0, L_80004E38
    if (ctx->r25 != ctx->r8) {
        // 0x80004E18: nop
    
            goto L_80004E38;
    }
    // 0x80004E18: nop

    // 0x80004E1C: lh          $t2, 0x2($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X2);
    // 0x80004E20: lhu         $t1, 0x40($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X40);
    // 0x80004E24: nop

    // 0x80004E28: bne         $t2, $t1, L_80004E38
    if (ctx->r10 != ctx->r9) {
        // 0x80004E2C: nop
    
            goto L_80004E38;
    }
    // 0x80004E2C: nop

    // 0x80004E30: b           L_80004E4C
    // 0x80004E34: nop

        goto L_80004E4C;
    // 0x80004E34: nop

L_80004E38:
    // 0x80004E38: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E3C: nop

    // 0x80004E40: addiu       $t5, $t3, 0x20
    ctx->r13 = ADD32(ctx->r11, 0X20);
    // 0x80004E44: b           L_80004DD8
    // 0x80004E48: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
        goto L_80004DD8;
    // 0x80004E48: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
L_80004E4C:
    // 0x80004E4C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E50: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80004E54: jal         0x800BCFCC
    // 0x80004E58: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x80004E58: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_4:
    // 0x80004E5C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E60: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80004E64: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80004E68: jal         0x800BCFCC
    // 0x80004E6C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80004E6C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_5:
    // 0x80004E70: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80004E74: jal         0x800BC980
    // 0x80004E78: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x80004E78: nop

    after_6:
    // 0x80004E7C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80004E80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004E84: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80004E88: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80004E8C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80004E90: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80004E94: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80004E98: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80004E9C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80004EA0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80004EA4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80004EA8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80004EAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004EB0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80004EB4: jal         0x800A66EC
    // 0x80004EB8: subu        $a2, $t4, $t6
    ctx->r6 = SUB32(ctx->r12, ctx->r14);
    func_800A66EC(rdram, ctx);
        goto after_7;
    // 0x80004EB8: subu        $a2, $t4, $t6
    ctx->r6 = SUB32(ctx->r12, ctx->r14);
    after_7:
    // 0x80004EBC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80004EC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004EC4: addu        $t2, $t8, $s0
    ctx->r10 = ADD32(ctx->r24, ctx->r16);
    // 0x80004EC8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80004ECC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80004ED0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80004ED4: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80004ED8: nop

    // 0x80004EDC: bne         $t3, $at, L_80004D18
    if (ctx->r11 != ctx->r1) {
        // 0x80004EE0: nop
    
            goto L_80004D18;
    }
    // 0x80004EE0: nop

L_80004EE4:
    // 0x80004EE4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80004EE8: nop

    // 0x80004EEC: addiu       $t4, $t5, 0x2
    ctx->r12 = ADD32(ctx->r13, 0X2);
    // 0x80004EF0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80004EF4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80004EF8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80004EFC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004F00: nop

    // 0x80004F04: beq         $t7, $at, L_800050E4
    if (ctx->r15 == ctx->r1) {
        // 0x80004F08: nop
    
            goto L_800050E4;
    }
    // 0x80004F08: nop

L_80004F0C:
    // 0x80004F0C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80004F10: nop

    // 0x80004F14: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80004F18: addiu       $t8, $t9, 0x2
    ctx->r24 = ADD32(ctx->r25, 0X2);
    // 0x80004F1C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80004F20: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x80004F24: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80004F28: nop

    // 0x80004F2C: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x80004F30: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80004F34: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80004F38: sh          $t1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r9;
    // 0x80004F3C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80004F40: nop

    // 0x80004F44: lhu         $t4, 0x0($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X0);
    // 0x80004F48: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004F4C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80004F50: sh          $t4, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r12;
    // 0x80004F54: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80004F58: nop

    // 0x80004F5C: lhu         $t0, 0x0($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X0);
    // 0x80004F60: addiu       $t9, $t7, 0x2
    ctx->r25 = ADD32(ctx->r15, 0X2);
    // 0x80004F64: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80004F68: sh          $t0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r8;
    // 0x80004F6C: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x80004F70: nop

    // 0x80004F74: bne         $t8, $zero, L_8000504C
    if (ctx->r24 != 0) {
        // 0x80004F78: nop
    
            goto L_8000504C;
    }
    // 0x80004F78: nop

    // 0x80004F7C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80004F80: nop

    // 0x80004F84: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80004F88: beq         $at, $zero, L_80004FEC
    if (ctx->r1 == 0) {
        // 0x80004F8C: nop
    
            goto L_80004FEC;
    }
    // 0x80004F8C: nop

    // 0x80004F90: lhu         $t4, 0x42($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X42);
    // 0x80004F94: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80004F98: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80004F9C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80004FA0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80004FA4: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80004FA8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80004FAC: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x80004FB0: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80004FB4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80004FB8: sw          $t2, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r10;
    // 0x80004FBC: lhu         $t9, 0x42($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X42);
    // 0x80004FC0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80004FC4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80004FC8: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80004FCC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80004FD0: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80004FD4: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80004FD8: lhu         $t0, 0x3C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3C);
    // 0x80004FDC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80004FE0: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x80004FE4: b           L_80005044
    // 0x80004FE8: sh          $t0, 0x124($t1)
    MEM_H(0X124, ctx->r9) = ctx->r8;
        goto L_80005044;
    // 0x80004FE8: sh          $t0, 0x124($t1)
    MEM_H(0X124, ctx->r9) = ctx->r8;
L_80004FEC:
    // 0x80004FEC: lhu         $t5, 0x42($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X42);
    // 0x80004FF0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80004FF4: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x80004FF8: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x80004FFC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80005000: lw          $t3, -0x73DC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73DC);
    // 0x80005004: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x80005008: lhu         $t4, 0x40($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X40);
    // 0x8000500C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80005010: addu        $t6, $t3, $t2
    ctx->r14 = ADD32(ctx->r11, ctx->r10);
    // 0x80005014: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
    // 0x80005018: lhu         $t8, 0x42($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X42);
    // 0x8000501C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80005020: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80005024: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80005028: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8000502C: lw          $t7, -0x73DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73DC);
    // 0x80005030: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80005034: lhu         $t9, 0x3C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3C);
    // 0x80005038: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8000503C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80005040: sh          $t9, 0x124($t1)
    MEM_H(0X124, ctx->r9) = ctx->r25;
L_80005044:
    // 0x80005044: b           L_800050CC
    // 0x80005048: nop

        goto L_800050CC;
    // 0x80005048: nop

L_8000504C:
    // 0x8000504C: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80005050: nop

    // 0x80005054: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80005058: beq         $at, $zero, L_80005098
    if (ctx->r1 == 0) {
        // 0x8000505C: nop
    
            goto L_80005098;
    }
    // 0x8000505C: nop

    // 0x80005060: lhu         $t3, 0x42($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X42);
    // 0x80005064: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80005068: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8000506C: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80005070: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80005074: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80005078: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8000507C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80005080: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x80005084: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x80005088: nop

    // 0x8000508C: ori         $t7, $t8, 0x80
    ctx->r15 = ctx->r24 | 0X80;
    // 0x80005090: b           L_800050CC
    // 0x80005094: sw          $t7, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r15;
        goto L_800050CC;
    // 0x80005094: sw          $t7, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r15;
L_80005098:
    // 0x80005098: lhu         $t0, 0x42($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X42);
    // 0x8000509C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800050A0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800050A4: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x800050A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800050AC: lw          $t1, -0x73DC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73DC);
    // 0x800050B0: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x800050B4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800050B8: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x800050BC: lw          $t3, 0xC0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XC0);
    // 0x800050C0: nop

    // 0x800050C4: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x800050C8: sw          $t2, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r10;
L_800050CC:
    // 0x800050CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800050D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800050D4: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x800050D8: nop

    // 0x800050DC: bne         $t8, $at, L_80004F0C
    if (ctx->r24 != ctx->r1) {
        // 0x800050E0: nop
    
            goto L_80004F0C;
    }
    // 0x800050E0: nop

L_800050E4:
    // 0x800050E4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800050E8: nop

    // 0x800050EC: addiu       $t6, $t7, 0x2
    ctx->r14 = ADD32(ctx->r15, 0X2);
    // 0x800050F0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800050F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800050F8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800050FC: nop

    // 0x80005100: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80005104: b           L_80005114
    // 0x80005108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005114;
    // 0x80005108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000510C: b           L_80005114
    // 0x80005110: nop

        goto L_80005114;
    // 0x80005110: nop

L_80005114:
    // 0x80005114: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80005118: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000511C: jr          $ra
    // 0x80005120: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80005120: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800776FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800776FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077704: jal         0x80061488
    // 0x80077708: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077708: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    after_0:
    // 0x8007770C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077710: b           L_80077720
    // 0x80077714: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077720;
    // 0x80077714: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077718: b           L_80077720
    // 0x8007771C: nop

        goto L_80077720;
    // 0x8007771C: nop

L_80077720:
    // 0x80077720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077728: jr          $ra
    // 0x8007772C: nop

    return;
    // 0x8007772C: nop

;}
RECOMP_FUNC void func_8006446C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006446C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064474: jal         0x80061488
    // 0x80064478: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064478: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x8006447C: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064480: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064484: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x80064488: nop
    
            goto L_80064518;
    }
    // 0x80064488: nop

    // 0x8006448C: jal         0x80061488
    // 0x80064490: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064490: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064494: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064498: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006449C: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644A0: nop
    
            goto L_80064518;
    }
    // 0x800644A0: nop

    // 0x800644A4: jal         0x80061488
    // 0x800644A8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x800644A8: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x800644AC: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800644B0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800644B4: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644B8: nop
    
            goto L_80064518;
    }
    // 0x800644B8: nop

    // 0x800644BC: jal         0x80061488
    // 0x800644C0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x800644C0: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x800644C4: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800644C8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800644CC: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644D0: nop
    
            goto L_80064518;
    }
    // 0x800644D0: nop

    // 0x800644D4: jal         0x80061488
    // 0x800644D8: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x800644D8: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x800644DC: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800644E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800644E4: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x800644E8: nop
    
            goto L_80064518;
    }
    // 0x800644E8: nop

    // 0x800644EC: jal         0x8005F064
    // 0x800644F0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800644F0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800644F4: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800644F8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800644FC: beq         $v0, $zero, L_80064518
    if (ctx->r2 == 0) {
        // 0x80064500: nop
    
            goto L_80064518;
    }
    // 0x80064500: nop

    // 0x80064504: jal         0x80061348
    // 0x80064508: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064508: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x8006450C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064510: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064514: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064518:
    // 0x80064518: b           L_80064528
    // 0x8006451C: nop

        goto L_80064528;
    // 0x8006451C: nop

    // 0x80064520: b           L_80064528
    // 0x80064524: nop

        goto L_80064528;
    // 0x80064524: nop

L_80064528:
    // 0x80064528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006452C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064530: jr          $ra
    // 0x80064534: nop

    return;
    // 0x80064534: nop

;}
RECOMP_FUNC void func_80064EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064EF4: jal         0x8005F064
    // 0x80064EF8: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064EF8: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x80064EFC: b           L_80064F0C
    // 0x80064F00: nop

        goto L_80064F0C;
    // 0x80064F00: nop

    // 0x80064F04: b           L_80064F0C
    // 0x80064F08: nop

        goto L_80064F0C;
    // 0x80064F08: nop

L_80064F0C:
    // 0x80064F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064F14: jr          $ra
    // 0x80064F18: nop

    return;
    // 0x80064F18: nop

;}
RECOMP_FUNC void func_8005B490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B490: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B498: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005B49C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005B4A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005B4A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005B4A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005B4AC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005B4B0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005B4B4: bne         $t0, $zero, L_8005B4C4
    if (ctx->r8 != 0) {
        // 0x8005B4B8: andi        $t1, $t9, 0x2
        ctx->r9 = ctx->r25 & 0X2;
            goto L_8005B4C4;
    }
    // 0x8005B4B8: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x8005B4BC: beq         $t1, $zero, L_8005B4E4
    if (ctx->r9 == 0) {
        // 0x8005B4C0: nop
    
            goto L_8005B4E4;
    }
    // 0x8005B4C0: nop

L_8005B4C4:
    // 0x8005B4C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005B4C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8005B4CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8005B4D0: jal         0x8005B994
    // 0x8005B4D4: nop

    func_8005B994(rdram, ctx);
        goto after_0;
    // 0x8005B4D4: nop

    after_0:
    // 0x8005B4D8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005B4DC: b           L_8005B5F8
    // 0x8005B4E0: sw          $v0, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = ctx->r2;
        goto L_8005B5F8;
    // 0x8005B4E0: sw          $v0, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = ctx->r2;
L_8005B4E4:
    // 0x8005B4E4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8005B4E8: nop

    // 0x8005B4EC: lw          $t3, 0xA4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XA4);
    // 0x8005B4F0: nop

    // 0x8005B4F4: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8005B4F8: beq         $at, $zero, L_8005B590
    if (ctx->r1 == 0) {
        // 0x8005B4FC: nop
    
            goto L_8005B590;
    }
    // 0x8005B4FC: nop

    // 0x8005B500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005B504: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8005B508: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8005B50C: jal         0x8005B994
    // 0x8005B510: nop

    func_8005B994(rdram, ctx);
        goto after_1;
    // 0x8005B510: nop

    after_1:
    // 0x8005B514: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8005B518: nop

    // 0x8005B51C: sw          $v0, 0xA8($t4)
    MEM_W(0XA8, ctx->r12) = ctx->r2;
    // 0x8005B520: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005B524: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B528: lw          $t6, 0xA8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XA8);
    // 0x8005B52C: nop

    // 0x8005B530: bne         $t6, $at, L_8005B548
    if (ctx->r14 != ctx->r1) {
        // 0x8005B534: nop
    
            goto L_8005B548;
    }
    // 0x8005B534: nop

    // 0x8005B538: lw          $t8, 0xA4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XA4);
    // 0x8005B53C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B540: beq         $t8, $at, L_8005B574
    if (ctx->r24 == ctx->r1) {
        // 0x8005B544: nop
    
            goto L_8005B574;
    }
    // 0x8005B544: nop

L_8005B548:
    // 0x8005B548: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8005B54C: nop

    // 0x8005B550: lw          $t0, 0xA8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XA8);
    // 0x8005B554: nop

    // 0x8005B558: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8005B55C: beq         $at, $zero, L_8005B588
    if (ctx->r1 == 0) {
        // 0x8005B560: nop
    
            goto L_8005B588;
    }
    // 0x8005B560: nop

    // 0x8005B564: lw          $t1, 0xA4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XA4);
    // 0x8005B568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B56C: beq         $t1, $at, L_8005B588
    if (ctx->r9 == ctx->r1) {
        // 0x8005B570: nop
    
            goto L_8005B588;
    }
    // 0x8005B570: nop

L_8005B574:
    // 0x8005B574: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005B578: nop

    // 0x8005B57C: lw          $t2, 0xA4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0XA4);
    // 0x8005B580: nop

    // 0x8005B584: sw          $t2, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = ctx->r10;
L_8005B588:
    // 0x8005B588: b           L_8005B5F8
    // 0x8005B58C: nop

        goto L_8005B5F8;
    // 0x8005B58C: nop

L_8005B590:
    // 0x8005B590: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8005B594: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8005B598: lw          $t4, 0xA4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XA4);
    // 0x8005B59C: nop

    // 0x8005B5A0: beq         $t4, $at, L_8005B5B4
    if (ctx->r12 == ctx->r1) {
        // 0x8005B5A4: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_8005B5B4;
    }
    // 0x8005B5A4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8005B5A8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8005B5AC: bne         $t4, $at, L_8005B5F8
    if (ctx->r12 != ctx->r1) {
        // 0x8005B5B0: nop
    
            goto L_8005B5F8;
    }
    // 0x8005B5B0: nop

L_8005B5B4:
    // 0x8005B5B4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005B5B8: nop

    // 0x8005B5BC: lw          $t5, 0xB0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XB0);
    // 0x8005B5C0: nop

    // 0x8005B5C4: lw          $t8, 0xA4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XA4);
    // 0x8005B5C8: nop

    // 0x8005B5CC: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8005B5D0: bne         $at, $zero, L_8005B5E4
    if (ctx->r1 != 0) {
        // 0x8005B5D4: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_8005B5E4;
    }
    // 0x8005B5D4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005B5D8: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x8005B5DC: bne         $at, $zero, L_8005B5F8
    if (ctx->r1 != 0) {
        // 0x8005B5E0: nop
    
            goto L_8005B5F8;
    }
    // 0x8005B5E0: nop

L_8005B5E4:
    // 0x8005B5E4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005B5E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005B5EC: addiu       $a0, $t0, 0x4C
    ctx->r4 = ADD32(ctx->r8, 0X4C);
    // 0x8005B5F0: jal         0x800B2CBC
    // 0x8005B5F4: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_2;
    // 0x8005B5F4: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    after_2:
L_8005B5F8:
    // 0x8005B5F8: b           L_8005B600
    // 0x8005B5FC: nop

        goto L_8005B600;
    // 0x8005B5FC: nop

L_8005B600:
    // 0x8005B600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B604: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005B608: jr          $ra
    // 0x8005B60C: nop

    return;
    // 0x8005B60C: nop

;}
RECOMP_FUNC void func_80065CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065CC0: jal         0x8005F064
    // 0x80065CC4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065CC4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_0:
    // 0x80065CC8: b           L_80065CD8
    // 0x80065CCC: nop

        goto L_80065CD8;
    // 0x80065CCC: nop

    // 0x80065CD0: b           L_80065CD8
    // 0x80065CD4: nop

        goto L_80065CD8;
    // 0x80065CD4: nop

L_80065CD8:
    // 0x80065CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065CE0: jr          $ra
    // 0x80065CE4: nop

    return;
    // 0x80065CE4: nop

;}
RECOMP_FUNC void func_8005A870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A878: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8005A87C: lh          $t6, -0x73C0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X73C0);
    // 0x8005A880: nop

    // 0x8005A884: bgez        $t6, L_8005A978
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005A888: nop
    
            goto L_8005A978;
    }
    // 0x8005A888: nop

    // 0x8005A88C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A890: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A894: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005A898: lh          $a1, 0x4A($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X4A);
    // 0x8005A89C: nop

    // 0x8005A8A0: andi        $t8, $a1, 0x1FFF
    ctx->r24 = ctx->r5 & 0X1FFF;
    // 0x8005A8A4: jal         0x8008E510
    // 0x8005A8A8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8008E510(rdram, ctx);
        goto after_0;
    // 0x8005A8A8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_0:
    // 0x8005A8AC: bne         $v0, $zero, L_8005A978
    if (ctx->r2 != 0) {
        // 0x8005A8B0: nop
    
            goto L_8005A978;
    }
    // 0x8005A8B0: nop

    // 0x8005A8B4: jal         0x80031AC8
    // 0x8005A8B8: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x8005A8B8: nop

    after_1:
    // 0x8005A8BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A8C0: bne         $v0, $at, L_8005A978
    if (ctx->r2 != ctx->r1) {
        // 0x8005A8C4: nop
    
            goto L_8005A978;
    }
    // 0x8005A8C4: nop

    // 0x8005A8C8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8005A8CC: lh          $t9, 0x1B08($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X1B08);
    // 0x8005A8D0: nop

    // 0x8005A8D4: bne         $t9, $zero, L_8005A978
    if (ctx->r25 != 0) {
        // 0x8005A8D8: nop
    
            goto L_8005A978;
    }
    // 0x8005A8D8: nop

    // 0x8005A8DC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005A8E0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005A8E4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005A8E8: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8005A8EC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8005A8F0: bne         $t4, $zero, L_8005A900
    if (ctx->r12 != 0) {
        // 0x8005A8F4: andi        $t5, $t3, 0x400
        ctx->r13 = ctx->r11 & 0X400;
            goto L_8005A900;
    }
    // 0x8005A8F4: andi        $t5, $t3, 0x400
    ctx->r13 = ctx->r11 & 0X400;
    // 0x8005A8F8: beq         $t5, $zero, L_8005A978
    if (ctx->r13 == 0) {
        // 0x8005A8FC: nop
    
            goto L_8005A978;
    }
    // 0x8005A8FC: nop

L_8005A900:
    // 0x8005A900: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005A904: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A908: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8005A90C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005A910: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A914: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A918: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005A91C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005A920: lw          $t1, 0x161C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X161C);
    // 0x8005A924: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005A928: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005A92C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A930: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8005A934: sw          $t8, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = ctx->r24;
    // 0x8005A938: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005A93C: lw          $t9, 0x161C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X161C);
    // 0x8005A940: nop

    // 0x8005A944: slti        $at, $t9, 0xB5
    ctx->r1 = SIGNED(ctx->r25) < 0XB5 ? 1 : 0;
    // 0x8005A948: bne         $at, $zero, L_8005A970
    if (ctx->r1 != 0) {
        // 0x8005A94C: nop
    
            goto L_8005A970;
    }
    // 0x8005A94C: nop

    // 0x8005A950: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005A954: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005A958: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8005A95C: addiu       $a0, $t0, 0x4C
    ctx->r4 = ADD32(ctx->r8, 0X4C);
    // 0x8005A960: jal         0x800B2CBC
    // 0x8005A964: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_2;
    // 0x8005A964: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    after_2:
    // 0x8005A968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A96C: sw          $zero, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = 0;
L_8005A970:
    // 0x8005A970: b           L_8005A980
    // 0x8005A974: nop

        goto L_8005A980;
    // 0x8005A974: nop

L_8005A978:
    // 0x8005A978: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005A97C: sw          $zero, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = 0;
L_8005A980:
    // 0x8005A980: b           L_8005A988
    // 0x8005A984: nop

        goto L_8005A988;
    // 0x8005A984: nop

L_8005A988:
    // 0x8005A988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A98C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A990: jr          $ra
    // 0x8005A994: nop

    return;
    // 0x8005A994: nop

    // 0x8005A998: nop

    // 0x8005A99C: nop

;}
RECOMP_FUNC void func_8006E76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E76C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E774: jal         0x80061348
    // 0x8006E778: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E778: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E77C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E780: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E784: beq         $v0, $zero, L_8006E79C
    if (ctx->r2 == 0) {
        // 0x8006E788: nop
    
            goto L_8006E79C;
    }
    // 0x8006E788: nop

    // 0x8006E78C: jal         0x80061348
    // 0x8006E790: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E790: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    after_1:
    // 0x8006E794: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E79C:
    // 0x8006E79C: b           L_8006E7AC
    // 0x8006E7A0: nop

        goto L_8006E7AC;
    // 0x8006E7A0: nop

    // 0x8006E7A4: b           L_8006E7AC
    // 0x8006E7A8: nop

        goto L_8006E7AC;
    // 0x8006E7A8: nop

L_8006E7AC:
    // 0x8006E7AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E7B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E7B4: jr          $ra
    // 0x8006E7B8: nop

    return;
    // 0x8006E7B8: nop

;}
RECOMP_FUNC void func_8006B708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B708: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B70C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B710: nop

    // 0x8006B714: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B718: nop

    // 0x8006B71C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B720: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B724: jr          $ra
    // 0x8006B728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B72C: jr          $ra
    // 0x8006B730: nop

    return;
    // 0x8006B730: nop

    // 0x8006B734: jr          $ra
    // 0x8006B738: nop

    return;
    // 0x8006B738: nop

;}
RECOMP_FUNC void func_80072C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072C14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072C18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072C1C: nop

    // 0x80072C20: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072C24: nop

    // 0x80072C28: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072C2C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072C30: jr          $ra
    // 0x80072C34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072C38: jr          $ra
    // 0x80072C3C: nop

    return;
    // 0x80072C3C: nop

    // 0x80072C40: jr          $ra
    // 0x80072C44: nop

    return;
    // 0x80072C44: nop

;}
RECOMP_FUNC void AudioGeneral_BGMFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021F98: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x80021F9C: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80021FA0: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80021FA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021FA8: bne         $t6, $zero, L_80021FB4
    if (ctx->r14 != 0) {
        // 0x80021FAC: nop
    
            goto L_80021FB4;
    }
    // 0x80021FAC: nop

    // 0x80021FB0: break       7
    do_break(2147622832);
L_80021FB4:
    // 0x80021FB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021FB8: bne         $t6, $at, L_80021FCC
    if (ctx->r14 != ctx->r1) {
        // 0x80021FBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021FCC;
    }
    // 0x80021FBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021FC0: bne         $t7, $at, L_80021FCC
    if (ctx->r15 != ctx->r1) {
        // 0x80021FC4: nop
    
            goto L_80021FCC;
    }
    // 0x80021FC4: nop

    // 0x80021FC8: break       6
    do_break(2147622856);
L_80021FCC:
    // 0x80021FCC: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x80021FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80021FD4: mflo        $a1
    ctx->r5 = lo;
    // 0x80021FD8: jal         0x800BB52C
    // 0x80021FDC: nop

    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80021FDC: nop

    after_0:
    // 0x80021FE0: b           L_80021FE8
    // 0x80021FE4: nop

        goto L_80021FE8;
    // 0x80021FE4: nop

L_80021FE8:
    // 0x80021FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021FF0: jr          $ra
    // 0x80021FF4: nop

    return;
    // 0x80021FF4: nop

;}
RECOMP_FUNC void func_8006BF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF78: jal         0x8005F064
    // 0x8006BF7C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BF7C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x8006BF80: b           L_8006BF90
    // 0x8006BF84: nop

        goto L_8006BF90;
    // 0x8006BF84: nop

    // 0x8006BF88: b           L_8006BF90
    // 0x8006BF8C: nop

        goto L_8006BF90;
    // 0x8006BF8C: nop

L_8006BF90:
    // 0x8006BF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF98: jr          $ra
    // 0x8006BF9C: nop

    return;
    // 0x8006BF9C: nop

;}
RECOMP_FUNC void func_80076340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076340: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076344: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076348: nop

    // 0x8007634C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80076350: nop

    // 0x80076354: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80076358: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007635C: jr          $ra
    // 0x80076360: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076360: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076364: jr          $ra
    // 0x80076368: nop

    return;
    // 0x80076368: nop

    // 0x8007636C: jr          $ra
    // 0x80076370: nop

    return;
    // 0x80076370: nop

;}
RECOMP_FUNC void func_8007D538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D538: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8007D53C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D540: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007D544: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D548: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007D54C: nop

    // 0x8007D550: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8007D554: bne         $t7, $zero, L_8007D564
    if (ctx->r15 != 0) {
        // 0x8007D558: nop
    
            goto L_8007D564;
    }
    // 0x8007D558: nop

    // 0x8007D55C: b           L_8007DF2C
    // 0x8007D560: nop

        goto L_8007DF2C;
    // 0x8007D560: nop

L_8007D564:
    // 0x8007D564: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007D568: jal         0x8001ABEC
    // 0x8007D56C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001ABEC(rdram, ctx);
        goto after_0;
    // 0x8007D56C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_0:
    // 0x8007D570: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007D574: jal         0x8008EAA8
    // 0x8007D578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_1;
    // 0x8007D578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8007D57C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D580: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007D584: swc1        $f4, -0x3974($at)
    MEM_W(-0X3974, ctx->r1) = ctx->f4.u32l;
    // 0x8007D588: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007D58C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007D590: swc1        $f6, -0x3970($at)
    MEM_W(-0X3970, ctx->r1) = ctx->f6.u32l;
    // 0x8007D594: jal         0x8007E94C
    // 0x8007D598: nop

    func_8007E94C(rdram, ctx);
        goto after_2;
    // 0x8007D598: nop

    after_2:
    // 0x8007D59C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007D5A0: lw          $t8, 0x7100($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7100);
    // 0x8007D5A4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007D5A8: bne         $t8, $at, L_8007D764
    if (ctx->r24 != ctx->r1) {
        // 0x8007D5AC: nop
    
            goto L_8007D764;
    }
    // 0x8007D5AC: nop

    // 0x8007D5B0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007D5B4: lw          $t9, 0x7104($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7104);
    // 0x8007D5B8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8007D5BC: bne         $t9, $at, L_8007D764
    if (ctx->r25 != ctx->r1) {
        // 0x8007D5C0: nop
    
            goto L_8007D764;
    }
    // 0x8007D5C0: nop

    // 0x8007D5C4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D5C8: lb          $t0, 0x7140($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7140);
    // 0x8007D5CC: nop

    // 0x8007D5D0: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8007D5D4: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8007D5D8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8007D5DC: slti        $at, $t1, 0x28
    ctx->r1 = SIGNED(ctx->r9) < 0X28 ? 1 : 0;
    // 0x8007D5E0: beq         $at, $zero, L_8007D764
    if (ctx->r1 == 0) {
        // 0x8007D5E4: nop
    
            goto L_8007D764;
    }
    // 0x8007D5E4: nop

L_8007D5E8:
    // 0x8007D5E8: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8007D5EC: nop

    // 0x8007D5F0: slti        $at, $t2, 0x28
    ctx->r1 = SIGNED(ctx->r10) < 0X28 ? 1 : 0;
    // 0x8007D5F4: beq         $at, $zero, L_8007D644
    if (ctx->r1 == 0) {
        // 0x8007D5F8: nop
    
            goto L_8007D644;
    }
    // 0x8007D5F8: nop

L_8007D5FC:
    // 0x8007D5FC: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8007D600: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007D604: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007D608: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007D60C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007D610: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8007D614: lh          $t5, 0x2460($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2460);
    // 0x8007D618: nop

    // 0x8007D61C: bltz        $t5, L_8007D62C
    if (SIGNED(ctx->r13) < 0) {
        // 0x8007D620: nop
    
            goto L_8007D62C;
    }
    // 0x8007D620: nop

    // 0x8007D624: b           L_8007D644
    // 0x8007D628: nop

        goto L_8007D644;
    // 0x8007D628: nop

L_8007D62C:
    // 0x8007D62C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8007D630: nop

    // 0x8007D634: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007D638: slti        $at, $t7, 0x28
    ctx->r1 = SIGNED(ctx->r15) < 0X28 ? 1 : 0;
    // 0x8007D63C: bne         $at, $zero, L_8007D5FC
    if (ctx->r1 != 0) {
        // 0x8007D640: sw          $t7, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r15;
            goto L_8007D5FC;
    }
    // 0x8007D640: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
L_8007D644:
    // 0x8007D644: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8007D648: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007D64C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007D650: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007D654: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8007D658: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8007D65C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007D660: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007D664: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007D668: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007D66C: lw          $a2, 0x2458($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2458);
    // 0x8007D670: jal         0x800BD1FC
    // 0x8007D674: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8007D674: nop

    after_3:
    // 0x8007D678: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007D67C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D680: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007D684: jal         0x800BD218
    // 0x8007D688: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x8007D688: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_4:
    // 0x8007D68C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8007D690: jal         0x800805C4
    // 0x8007D694: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800805C4(rdram, ctx);
        goto after_5;
    // 0x8007D694: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_5:
    // 0x8007D698: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007D69C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8007D6A0: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D6A4: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, 0X6BA0);
    // 0x8007D6A8: addiu       $a0, $a0, 0x6B98
    ctx->r4 = ADD32(ctx->r4, 0X6B98);
    // 0x8007D6AC: jal         0x8007EB90
    // 0x8007D6B0: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    func_8007EB90(rdram, ctx);
        goto after_6;
    // 0x8007D6B0: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    after_6:
    // 0x8007D6B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8007D6B8: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x8007D6BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D6C0: addiu       $t1, $t0, 0x5
    ctx->r9 = ADD32(ctx->r8, 0X5);
    // 0x8007D6C4: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8007D6C8: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D6CC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007D6D0: lw          $t3, -0x3908($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3908);
    // 0x8007D6D4: lhu         $t2, 0x2A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007D6D8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8007D6DC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8007D6E0: sh          $t2, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r10;
    // 0x8007D6E4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8007D6E8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007D6EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D6F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007D6F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007D6F8: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x8007D6FC: lh          $a3, 0x2460($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X2460);
    // 0x8007D700: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D704: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8007D708: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x8007D70C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8007D710: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D714: addiu       $a0, $a0, -0xDD0
    ctx->r4 = ADD32(ctx->r4, -0XDD0);
    // 0x8007D718: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8007D71C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8007D720: jal         0x8008ECE4
    // 0x8007D724: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8007D724: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_7:
    // 0x8007D728: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8007D72C: nop

    // 0x8007D730: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007D734: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8007D738: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8007D73C: nop

    // 0x8007D740: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8007D744: slti        $at, $t3, 0x6
    ctx->r1 = SIGNED(ctx->r11) < 0X6 ? 1 : 0;
    // 0x8007D748: beq         $at, $zero, L_8007D764
    if (ctx->r1 == 0) {
        // 0x8007D74C: sw          $t3, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r11;
            goto L_8007D764;
    }
    // 0x8007D74C: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8007D750: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8007D754: nop

    // 0x8007D758: slti        $at, $t5, 0x28
    ctx->r1 = SIGNED(ctx->r13) < 0X28 ? 1 : 0;
    // 0x8007D75C: bne         $at, $zero, L_8007D5E8
    if (ctx->r1 != 0) {
        // 0x8007D760: nop
    
            goto L_8007D5E8;
    }
    // 0x8007D760: nop

L_8007D764:
    // 0x8007D764: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007D768: lw          $t2, 0x7100($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7100);
    // 0x8007D76C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007D770: bne         $t2, $at, L_8007D9D4
    if (ctx->r10 != ctx->r1) {
        // 0x8007D774: nop
    
            goto L_8007D9D4;
    }
    // 0x8007D774: nop

    // 0x8007D778: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D77C: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007D780: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007D784: beq         $t6, $at, L_8007D798
    if (ctx->r14 == ctx->r1) {
        // 0x8007D788: nop
    
            goto L_8007D798;
    }
    // 0x8007D788: nop

    // 0x8007D78C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007D790: bne         $t6, $at, L_8007D9D4
    if (ctx->r14 != ctx->r1) {
        // 0x8007D794: nop
    
            goto L_8007D9D4;
    }
    // 0x8007D794: nop

L_8007D798:
    // 0x8007D798: addiu       $t7, $zero, 0xAD
    ctx->r15 = ADD32(0, 0XAD);
    // 0x8007D79C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D7A0: sw          $t7, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r15;
    // 0x8007D7A4: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8007D7A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D7AC: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x8007D7B0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007D7B4: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007D7B8: ori         $t9, $zero, 0xD6B5
    ctx->r25 = 0 | 0XD6B5;
    // 0x8007D7BC: sh          $t9, 0x100($t0)
    MEM_H(0X100, ctx->r8) = ctx->r25;
    // 0x8007D7C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D7C4: addiu       $a0, $a0, -0xDC4
    ctx->r4 = ADD32(ctx->r4, -0XDC4);
    // 0x8007D7C8: jal         0x8008ECE4
    // 0x8007D7CC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x8007D7CC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_8:
    // 0x8007D7D0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007D7D4: lw          $t1, 0x70E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E8);
    // 0x8007D7D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007D7DC: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8007D7E0: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x8007D7E4: bne         $at, $zero, L_8007D808
    if (ctx->r1 != 0) {
        // 0x8007D7E8: nop
    
            goto L_8007D808;
    }
    // 0x8007D7E8: nop

    // 0x8007D7EC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D7F0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8007D7F4: ori         $a1, $a1, 0x869F
    ctx->r5 = ctx->r5 | 0X869F;
    // 0x8007D7F8: jal         0x8008ECE4
    // 0x8007D7FC: addiu       $a0, $a0, -0xDC0
    ctx->r4 = ADD32(ctx->r4, -0XDC0);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8007D7FC: addiu       $a0, $a0, -0xDC0
    ctx->r4 = ADD32(ctx->r4, -0XDC0);
    after_9:
    // 0x8007D800: b           L_8007D81C
    // 0x8007D804: nop

        goto L_8007D81C;
    // 0x8007D804: nop

L_8007D808:
    // 0x8007D808: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007D80C: lw          $a1, 0x70E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70E8);
    // 0x8007D810: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D814: jal         0x8008ECE4
    // 0x8007D818: addiu       $a0, $a0, -0xDB8
    ctx->r4 = ADD32(ctx->r4, -0XDB8);
    func_8008ECE4(rdram, ctx);
        goto after_10;
    // 0x8007D818: addiu       $a0, $a0, -0xDB8
    ctx->r4 = ADD32(ctx->r4, -0XDB8);
    after_10:
L_8007D81C:
    // 0x8007D81C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007D820: lb          $t4, 0x7142($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7142);
    // 0x8007D824: nop

    // 0x8007D828: bltz        $t4, L_8007D9D4
    if (SIGNED(ctx->r12) < 0) {
        // 0x8007D82C: nop
    
            goto L_8007D9D4;
    }
    // 0x8007D82C: nop

    // 0x8007D830: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D834: lb          $t3, 0x7142($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7142);
    // 0x8007D838: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007D83C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8007D840: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8007D844: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007D848: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8007D84C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007D850: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007D854: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007D858: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007D85C: lw          $a2, 0x2458($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2458);
    // 0x8007D860: jal         0x800BD1FC
    // 0x8007D864: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_11;
    // 0x8007D864: nop

    after_11:
    // 0x8007D868: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007D86C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D870: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007D874: jal         0x800BD218
    // 0x8007D878: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_12;
    // 0x8007D878: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_12:
    // 0x8007D87C: jal         0x800808A4
    // 0x8007D880: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800808A4(rdram, ctx);
        goto after_13;
    // 0x8007D880: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_13:
    // 0x8007D884: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
    // 0x8007D888: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D88C: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8007D890: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8007D894: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D898: sw          $t6, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r14;
    // 0x8007D89C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D8A0: jal         0x8008ECE4
    // 0x8007D8A4: addiu       $a0, $a0, -0xDB0
    ctx->r4 = ADD32(ctx->r4, -0XDB0);
    func_8008ECE4(rdram, ctx);
        goto after_14;
    // 0x8007D8A4: addiu       $a0, $a0, -0xDB0
    ctx->r4 = ADD32(ctx->r4, -0XDB0);
    after_14:
    // 0x8007D8A8: jal         0x80080698
    // 0x8007D8AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80080698(rdram, ctx);
        goto after_15;
    // 0x8007D8AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_15:
    // 0x8007D8B0: negu        $t7, $v0
    ctx->r15 = SUB32(0, ctx->r2);
    // 0x8007D8B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D8B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007D8BC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8007D8C0: addiu       $t9, $t8, 0x51
    ctx->r25 = ADD32(ctx->r24, 0X51);
    // 0x8007D8C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8C8: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8007D8CC: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8007D8D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8D4: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x8007D8D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D8DC: addiu       $a0, $a0, -0xDA4
    ctx->r4 = ADD32(ctx->r4, -0XDA4);
    // 0x8007D8E0: jal         0x8008ECE4
    // 0x8007D8E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_16;
    // 0x8007D8E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_16:
    // 0x8007D8E8: addiu       $t1, $zero, 0x9D
    ctx->r9 = ADD32(0, 0X9D);
    // 0x8007D8EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8F0: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8007D8F4: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8007D8F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007D8FC: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8007D900: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D904: lw          $t3, 0x7104($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7104);
    // 0x8007D908: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007D90C: bne         $t3, $at, L_8007D958
    if (ctx->r11 != ctx->r1) {
        // 0x8007D910: nop
    
            goto L_8007D958;
    }
    // 0x8007D910: nop

    // 0x8007D914: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007D918: lb          $t5, 0x7142($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7142);
    // 0x8007D91C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007D920: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8007D924: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8007D928: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007D92C: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x8007D930: lh          $a1, 0x2460($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2460);
    // 0x8007D934: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D938: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8007D93C: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8007D940: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8007D944: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8007D948: jal         0x8008ECE4
    // 0x8007D94C: addiu       $a0, $a0, -0xDA0
    ctx->r4 = ADD32(ctx->r4, -0XDA0);
    func_8008ECE4(rdram, ctx);
        goto after_17;
    // 0x8007D94C: addiu       $a0, $a0, -0xDA0
    ctx->r4 = ADD32(ctx->r4, -0XDA0);
    after_17:
    // 0x8007D950: b           L_8007D9D4
    // 0x8007D954: nop

        goto L_8007D9D4;
    // 0x8007D954: nop

L_8007D958:
    // 0x8007D958: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007D95C: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007D960: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007D964: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D968: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007D96C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007D970: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007D974: lh          $t9, 0x2462($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2462);
    // 0x8007D978: nop

    // 0x8007D97C: bgez        $t9, L_8007D998
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007D980: nop
    
            goto L_8007D998;
    }
    // 0x8007D980: nop

    // 0x8007D984: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D988: jal         0x8008ECE4
    // 0x8007D98C: addiu       $a0, $a0, -0xD98
    ctx->r4 = ADD32(ctx->r4, -0XD98);
    func_8008ECE4(rdram, ctx);
        goto after_18;
    // 0x8007D98C: addiu       $a0, $a0, -0xD98
    ctx->r4 = ADD32(ctx->r4, -0XD98);
    after_18:
    // 0x8007D990: b           L_8007D9D4
    // 0x8007D994: nop

        goto L_8007D9D4;
    // 0x8007D994: nop

L_8007D998:
    // 0x8007D998: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D99C: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007D9A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007D9A4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007D9A8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007D9AC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007D9B0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8007D9B4: lh          $a1, 0x2462($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2462);
    // 0x8007D9B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007D9BC: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8007D9C0: addu        $t4, $t4, $a1
    ctx->r12 = ADD32(ctx->r12, ctx->r5);
    // 0x8007D9C4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8007D9C8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8007D9CC: jal         0x8008ECE4
    // 0x8007D9D0: addiu       $a0, $a0, -0xD90
    ctx->r4 = ADD32(ctx->r4, -0XD90);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x8007D9D0: addiu       $a0, $a0, -0xD90
    ctx->r4 = ADD32(ctx->r4, -0XD90);
    after_19:
L_8007D9D4:
    // 0x8007D9D4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D9D8: lw          $t3, 0x7100($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7100);
    // 0x8007D9DC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007D9E0: bne         $t3, $at, L_8007DAFC
    if (ctx->r11 != ctx->r1) {
        // 0x8007D9E4: nop
    
            goto L_8007DAFC;
    }
    // 0x8007D9E4: nop

    // 0x8007D9E8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007D9EC: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007D9F0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007D9F4: bne         $t5, $at, L_8007DAFC
    if (ctx->r13 != ctx->r1) {
        // 0x8007D9F8: nop
    
            goto L_8007DAFC;
    }
    // 0x8007D9F8: nop

    // 0x8007D9FC: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_8007DA00:
    // 0x8007DA00: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8007DA04: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8007DA08: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA0C: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, 0X6BA0);
    // 0x8007DA10: addiu       $a0, $a0, 0x6B98
    ctx->r4 = ADD32(ctx->r4, 0X6B98);
    // 0x8007DA14: jal         0x8007EB90
    // 0x8007DA18: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    func_8007EB90(rdram, ctx);
        goto after_20;
    // 0x8007DA18: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    after_20:
    // 0x8007DA1C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA20: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DA24: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8007DA28: subu        $t6, $t6, $t2
    ctx->r14 = SUB32(ctx->r14, ctx->r10);
    // 0x8007DA2C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007DA30: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8007DA34: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DA38: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DA3C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DA40: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DA44: lw          $a2, 0x2798($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2798);
    // 0x8007DA48: jal         0x800BD1FC
    // 0x8007DA4C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_21;
    // 0x8007DA4C: nop

    after_21:
    // 0x8007DA50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DA58: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DA5C: jal         0x800BD218
    // 0x8007DA60: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_22;
    // 0x8007DA60: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_22:
    // 0x8007DA64: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007DA6C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007DA70: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007DA74: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007DA78: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8007DA7C: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007DA80: jal         0x8005F064
    // 0x8007DA84: nop

    func_8005F064(rdram, ctx);
        goto after_23;
    // 0x8007DA84: nop

    after_23:
    // 0x8007DA88: beq         $v0, $zero, L_8007DAB0
    if (ctx->r2 == 0) {
        // 0x8007DA8C: nop
    
            goto L_8007DAB0;
    }
    // 0x8007DA8C: nop

    // 0x8007DA90: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DA94: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007DA98: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007DA9C: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8007DAA0: addiu       $t9, $zero, 0x6319
    ctx->r25 = ADD32(0, 0X6319);
    // 0x8007DAA4: addu        $t3, $t0, $t4
    ctx->r11 = ADD32(ctx->r8, ctx->r12);
    // 0x8007DAA8: b           L_8007DACC
    // 0x8007DAAC: sh          $t9, 0x100($t3)
    MEM_H(0X100, ctx->r11) = ctx->r25;
        goto L_8007DACC;
    // 0x8007DAAC: sh          $t9, 0x100($t3)
    MEM_H(0X100, ctx->r11) = ctx->r25;
L_8007DAB0:
    // 0x8007DAB0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DAB4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007DAB8: lw          $t2, -0x3908($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3908);
    // 0x8007DABC: lhu         $t5, 0x2A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007DAC0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8007DAC4: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8007DAC8: sh          $t5, 0x100($t8)
    MEM_H(0X100, ctx->r24) = ctx->r13;
L_8007DACC:
    // 0x8007DACC: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DAD0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DAD4: addiu       $a0, $a0, -0xD88
    ctx->r4 = ADD32(ctx->r4, -0XD88);
    // 0x8007DAD8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8007DADC: jal         0x8008ECE4
    // 0x8007DAE0: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_24;
    // 0x8007DAE0: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_24:
    // 0x8007DAE4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DAE8: nop

    // 0x8007DAEC: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8007DAF0: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8007DAF4: bne         $at, $zero, L_8007DA00
    if (ctx->r1 != 0) {
        // 0x8007DAF8: sw          $t0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r8;
            goto L_8007DA00;
    }
    // 0x8007DAF8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
L_8007DAFC:
    // 0x8007DAFC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007DB00: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007DB04: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007DB08: bne         $t4, $at, L_8007DEF4
    if (ctx->r12 != ctx->r1) {
        // 0x8007DB0C: nop
    
            goto L_8007DEF4;
    }
    // 0x8007DB0C: nop

    // 0x8007DB10: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007DB14: lw          $t9, 0x7104($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7104);
    // 0x8007DB18: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007DB1C: bne         $t9, $at, L_8007DEF4
    if (ctx->r25 != ctx->r1) {
        // 0x8007DB20: nop
    
            goto L_8007DEF4;
    }
    // 0x8007DB20: nop

    // 0x8007DB24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007DB28: lw          $t6, -0x3908($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3908);
    // 0x8007DB2C: addiu       $t3, $zero, 0x2109
    ctx->r11 = ADD32(0, 0X2109);
    // 0x8007DB30: sh          $t3, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r11;
    // 0x8007DB34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DB38: addiu       $a0, $a0, -0xD80
    ctx->r4 = ADD32(ctx->r4, -0XD80);
    // 0x8007DB3C: jal         0x8008ECE4
    // 0x8007DB40: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_25;
    // 0x8007DB40: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_25:
    // 0x8007DB44: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8007DB48: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DB4C: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8007DB50: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x8007DB54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DB58: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x8007DB5C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007DB60: lb          $t5, 0x7142($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7142);
    // 0x8007DB64: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DB68: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8007DB6C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8007DB70: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007DB74: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8007DB78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DB7C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DB80: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DB84: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DB88: lw          $a2, 0x279C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X279C);
    // 0x8007DB8C: jal         0x800BD1FC
    // 0x8007DB90: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_26;
    // 0x8007DB90: nop

    after_26:
    // 0x8007DB94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DB9C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DBA0: jal         0x800BD218
    // 0x8007DBA4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_27;
    // 0x8007DBA4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_27:
    // 0x8007DBA8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007DBAC: addiu       $t1, $t1, -0x3808
    ctx->r9 = ADD32(ctx->r9, -0X3808);
    // 0x8007DBB0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8007DBB4: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x8007DBB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DBBC: addiu       $a0, $a0, -0xD7C
    ctx->r4 = ADD32(ctx->r4, -0XD7C);
    // 0x8007DBC0: jal         0x8008ECE4
    // 0x8007DBC4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x8007DBC4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_28:
    // 0x8007DBC8: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8007DBCC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DBD0: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x8007DBD4: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x8007DBD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DBDC: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8007DBE0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007DBE4: addiu       $t9, $t9, -0x3808
    ctx->r25 = ADD32(ctx->r25, -0X3808);
    // 0x8007DBE8: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    // 0x8007DBEC: lw          $a2, 0xC($t9)
    ctx->r6 = MEM_W(ctx->r25, 0XC);
    // 0x8007DBF0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DBF4: jal         0x8008ECE4
    // 0x8007DBF8: addiu       $a0, $a0, -0xD70
    ctx->r4 = ADD32(ctx->r4, -0XD70);
    func_8008ECE4(rdram, ctx);
        goto after_29;
    // 0x8007DBF8: addiu       $a0, $a0, -0xD70
    ctx->r4 = ADD32(ctx->r4, -0XD70);
    after_29:
    // 0x8007DBFC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007DC00: lb          $t3, 0x7142($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7142);
    // 0x8007DC04: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007DC08: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8007DC0C: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x8007DC10: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007DC14: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8007DC18: lh          $t2, 0x27AA($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X27AA);
    // 0x8007DC1C: nop

    // 0x8007DC20: bgez        $t2, L_8007DC48
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007DC24: nop
    
            goto L_8007DC48;
    }
    // 0x8007DC24: nop

    // 0x8007DC28: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007DC2C: addiu       $t7, $t7, -0x3808
    ctx->r15 = ADD32(ctx->r15, -0X3808);
    // 0x8007DC30: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x8007DC34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DC38: jal         0x8008ECE4
    // 0x8007DC3C: addiu       $a0, $a0, -0xD68
    ctx->r4 = ADD32(ctx->r4, -0XD68);
    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x8007DC3C: addiu       $a0, $a0, -0xD68
    ctx->r4 = ADD32(ctx->r4, -0XD68);
    after_30:
    // 0x8007DC40: b           L_8007DC84
    // 0x8007DC44: nop

        goto L_8007DC84;
    // 0x8007DC44: nop

L_8007DC48:
    // 0x8007DC48: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007DC4C: lb          $t8, 0x7142($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7142);
    // 0x8007DC50: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007DC54: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8007DC58: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8007DC5C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007DC60: addiu       $t5, $t5, -0x3808
    ctx->r13 = ADD32(ctx->r13, -0X3808);
    // 0x8007DC64: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DC68: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8007DC6C: lh          $a2, 0x27AA($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X27AA);
    // 0x8007DC70: lw          $a1, 0x10($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X10);
    // 0x8007DC74: lw          $a3, 0x14($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X14);
    // 0x8007DC78: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DC7C: jal         0x8008ECE4
    // 0x8007DC80: addiu       $a0, $a0, -0xD64
    ctx->r4 = ADD32(ctx->r4, -0XD64);
    func_8008ECE4(rdram, ctx);
        goto after_31;
    // 0x8007DC80: addiu       $a0, $a0, -0xD64
    ctx->r4 = ADD32(ctx->r4, -0XD64);
    after_31:
L_8007DC84:
    // 0x8007DC84: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007DC88: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007DC8C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DC90: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x8007DC94: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x8007DC98: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8007DC9C: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8007DCA0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DCA4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DCA8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DCAC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DCB0: lw          $a2, 0x27A0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X27A0);
    // 0x8007DCB4: jal         0x800BD1FC
    // 0x8007DCB8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_32;
    // 0x8007DCB8: nop

    after_32:
    // 0x8007DCBC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DCC4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DCC8: jal         0x800BD218
    // 0x8007DCCC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_33;
    // 0x8007DCCC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_33:
    // 0x8007DCD0: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8007DCD4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DCD8: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8007DCDC: addiu       $t3, $zero, 0x4A
    ctx->r11 = ADD32(0, 0X4A);
    // 0x8007DCE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DCE4: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8007DCE8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007DCEC: addiu       $t6, $t6, -0x3808
    ctx->r14 = ADD32(ctx->r14, -0X3808);
    // 0x8007DCF0: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x8007DCF4: lw          $a2, 0xC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XC);
    // 0x8007DCF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DCFC: addiu       $a0, $a0, -0xD5C
    ctx->r4 = ADD32(ctx->r4, -0XD5C);
    // 0x8007DD00: jal         0x8008ECE4
    // 0x8007DD04: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_34;
    // 0x8007DD04: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_34:
    // 0x8007DD08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007DD0C: lb          $t2, 0x7142($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7142);
    // 0x8007DD10: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007DD14: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007DD18: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x8007DD1C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007DD20: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007DD24: lw          $t8, 0x27A4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X27A4);
    // 0x8007DD28: nop

    // 0x8007DD2C: beq         $t8, $zero, L_8007DDA8
    if (ctx->r24 == 0) {
        // 0x8007DD30: nop
    
            goto L_8007DDA8;
    }
    // 0x8007DD30: nop

    // 0x8007DD34: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007DD38: lb          $t1, 0x7142($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X7142);
    // 0x8007DD3C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DD40: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x8007DD44: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x8007DD48: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007DD4C: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8007DD50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DD54: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DD58: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007DD5C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007DD60: lw          $a2, 0x27A4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X27A4);
    // 0x8007DD64: jal         0x800BD1FC
    // 0x8007DD68: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_35;
    // 0x8007DD68: nop

    after_35:
    // 0x8007DD6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007DD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DD74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8007DD78: jal         0x800BD218
    // 0x8007DD7C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    SysMem_DmaCopy(rdram, ctx);
        goto after_36;
    // 0x8007DD7C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_36:
    // 0x8007DD80: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x8007DD84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DD88: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x8007DD8C: addiu       $t4, $zero, 0x57
    ctx->r12 = ADD32(0, 0X57);
    // 0x8007DD90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DD94: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8007DD98: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DD9C: addiu       $a0, $a0, -0xD54
    ctx->r4 = ADD32(ctx->r4, -0XD54);
    // 0x8007DDA0: jal         0x8008ECE4
    // 0x8007DDA4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008ECE4(rdram, ctx);
        goto after_37;
    // 0x8007DDA4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_37:
L_8007DDA8:
    // 0x8007DDA8: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x8007DDAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DDB0: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8007DDB4: addiu       $t3, $zero, 0x68
    ctx->r11 = ADD32(0, 0X68);
    // 0x8007DDB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DDBC: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8007DDC0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007DDC4: lw          $t2, -0x3908($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3908);
    // 0x8007DDC8: addiu       $t6, $zero, 0x2109
    ctx->r14 = ADD32(0, 0X2109);
    // 0x8007DDCC: sh          $t6, 0x102($t2)
    MEM_H(0X102, ctx->r10) = ctx->r14;
    // 0x8007DDD0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007DDD4: addiu       $t7, $t7, -0x3808
    ctx->r15 = ADD32(ctx->r15, -0X3808);
    // 0x8007DDD8: lw          $a2, 0x1C($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X1C);
    // 0x8007DDDC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DDE0: addiu       $a0, $a0, -0xD50
    ctx->r4 = ADD32(ctx->r4, -0XD50);
    // 0x8007DDE4: jal         0x8008ECE4
    // 0x8007DDE8: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    func_8008ECE4(rdram, ctx);
        goto after_38;
    // 0x8007DDE8: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_38:
    // 0x8007DDEC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8007DDF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DDF4: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8007DDF8: addiu       $t1, $zero, 0x68
    ctx->r9 = ADD32(0, 0X68);
    // 0x8007DDFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE00: sw          $t1, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r9;
    // 0x8007DE04: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007DE08: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007DE0C: ori         $t5, $zero, 0xD6B5
    ctx->r13 = 0 | 0XD6B5;
    // 0x8007DE10: sh          $t5, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r13;
    // 0x8007DE14: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007DE18: lb          $t4, 0x7142($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7142);
    // 0x8007DE1C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007DE20: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8007DE24: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8007DE28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8007DE2C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8007DE30: lh          $a2, 0x27AC($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X27AC);
    // 0x8007DE34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DE38: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8007DE3C: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x8007DE40: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8007DE44: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8007DE48: addiu       $a0, $a0, -0xD48
    ctx->r4 = ADD32(ctx->r4, -0XD48);
    // 0x8007DE4C: jal         0x8008ECE4
    // 0x8007DE50: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_39;
    // 0x8007DE50: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_39:
    // 0x8007DE54: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x8007DE58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE5C: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x8007DE60: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8007DE64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE68: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x8007DE6C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007DE70: addiu       $t7, $t7, -0x3808
    ctx->r15 = ADD32(ctx->r15, -0X3808);
    // 0x8007DE74: lw          $a2, 0x20($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X20);
    // 0x8007DE78: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DE7C: addiu       $a0, $a0, -0xD40
    ctx->r4 = ADD32(ctx->r4, -0XD40);
    // 0x8007DE80: jal         0x8008ECE4
    // 0x8007DE84: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    func_8008ECE4(rdram, ctx);
        goto after_40;
    // 0x8007DE84: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_40:
    // 0x8007DE88: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8007DE8C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE90: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8007DE94: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x8007DE98: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8007DE9C: sw          $t1, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r9;
    // 0x8007DEA0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007DEA4: lw          $t5, 0x70E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E8);
    // 0x8007DEA8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007DEAC: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8007DEB0: sltu        $at, $t5, $at
    ctx->r1 = ctx->r13 < ctx->r1 ? 1 : 0;
    // 0x8007DEB4: bne         $at, $zero, L_8007DEDC
    if (ctx->r1 != 0) {
        // 0x8007DEB8: nop
    
            goto L_8007DEDC;
    }
    // 0x8007DEB8: nop

    // 0x8007DEBC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DEC0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8007DEC4: ori         $a2, $a2, 0x869F
    ctx->r6 = ctx->r6 | 0X869F;
    // 0x8007DEC8: addiu       $a0, $a0, -0xD38
    ctx->r4 = ADD32(ctx->r4, -0XD38);
    // 0x8007DECC: jal         0x8008ECE4
    // 0x8007DED0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_41;
    // 0x8007DED0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_41:
    // 0x8007DED4: b           L_8007DEF4
    // 0x8007DED8: nop

        goto L_8007DEF4;
    // 0x8007DED8: nop

L_8007DEDC:
    // 0x8007DEDC: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8007DEE0: lw          $a2, 0x70E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X70E8);
    // 0x8007DEE4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007DEE8: addiu       $a0, $a0, -0xD30
    ctx->r4 = ADD32(ctx->r4, -0XD30);
    // 0x8007DEEC: jal         0x8008ECE4
    // 0x8007DEF0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_42;
    // 0x8007DEF0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_42:
L_8007DEF4:
    // 0x8007DEF4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007DEF8: lw          $t0, -0x3908($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3908);
    // 0x8007DEFC: nop

    // 0x8007DF00: sh          $zero, 0x20($t0)
    MEM_H(0X20, ctx->r8) = 0;
    // 0x8007DF04: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007DF08: jal         0x8001ACDC
    // 0x8007DF0C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001ACDC(rdram, ctx);
        goto after_43;
    // 0x8007DF0C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_43:
    // 0x8007DF10: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8007DF14: jal         0x8001ADBC
    // 0x8007DF18: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001ADBC(rdram, ctx);
        goto after_44;
    // 0x8007DF18: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_44:
    // 0x8007DF1C: b           L_8007DF2C
    // 0x8007DF20: nop

        goto L_8007DF2C;
    // 0x8007DF20: nop

    // 0x8007DF24: b           L_8007DF2C
    // 0x8007DF28: nop

        goto L_8007DF2C;
    // 0x8007DF28: nop

L_8007DF2C:
    // 0x8007DF2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007DF30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007DF34: jr          $ra
    // 0x8007DF38: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007DF38: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800AC978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC978: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800AC97C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800AC980: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800AC984: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AC988: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800AC98C: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x800AC990: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800AC994: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800AC998: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AC99C: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800AC9A0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800AC9A4: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800AC9A8: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800AC9AC: nop

    // 0x800AC9B0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AC9B4: bne         $t1, $zero, L_800AC9C4
    if (ctx->r9 != 0) {
        // 0x800AC9B8: nop
    
            goto L_800AC9C4;
    }
    // 0x800AC9B8: nop

    // 0x800AC9BC: b           L_800ACB40
    // 0x800AC9C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ACB40;
    // 0x800AC9C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AC9C4:
    // 0x800AC9C4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800AC9C8: addiu       $t3, $t3, -0x7390
    ctx->r11 = ADD32(ctx->r11, -0X7390);
    // 0x800AC9CC: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x800AC9D0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC9D4: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800AC9D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800AC9DC: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800AC9E0: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x800AC9E4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800AC9E8: sw          $t6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r14;
    // 0x800AC9EC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800AC9F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800AC9F4: lh          $t0, 0x10C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10C);
    // 0x800AC9F8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800AC9FC: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x800ACA00: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800ACA04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800ACA08: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800ACA0C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800ACA10: lwc1        $f17, -0x730($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X730);
    // 0x800ACA14: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800ACA18: lwc1        $f16, -0x72C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72C);
    // 0x800ACA1C: nop

    // 0x800ACA20: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x800ACA24: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800ACA28: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x800ACA2C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800ACA30: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800ACA34: lh          $t4, 0x10C($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X10C);
    // 0x800ACA38: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800ACA3C: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800ACA40: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800ACA44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800ACA48: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800ACA4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800ACA50: lwc1        $f19, -0x728($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X728);
    // 0x800ACA54: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800ACA58: lwc1        $f18, -0x724($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X724);
    // 0x800ACA5C: nop

    // 0x800ACA60: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x800ACA64: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800ACA68: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800ACA6C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800ACA70: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ACA74: lwc1        $f8, 0xCC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800ACA78: nop

    // 0x800ACA7C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800ACA80: nop

    // 0x800ACA84: bc1f        L_800ACAC4
    if (!c1cs) {
        // 0x800ACA88: nop
    
            goto L_800ACAC4;
    }
    // 0x800ACA88: nop

    // 0x800ACA8C: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ACA90: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800ACA94: nop

    // 0x800ACA98: swc1        $f10, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f10.u32l;
    // 0x800ACA9C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800ACAA0: addiu       $t8, $t8, -0x7390
    ctx->r24 = ADD32(ctx->r24, -0X7390);
    // 0x800ACAA4: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800ACAA8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800ACAAC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x800ACAB0: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x800ACAB4: addu        $t4, $t2, $t8
    ctx->r12 = ADD32(ctx->r10, ctx->r24);
    // 0x800ACAB8: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x800ACABC: b           L_800ACB18
    // 0x800ACAC0: sw          $t1, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r9;
        goto L_800ACB18;
    // 0x800ACAC0: sw          $t1, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r9;
L_800ACAC4:
    // 0x800ACAC4: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800ACAC8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800ACACC: lwc1        $f18, 0xCC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x800ACAD0: nop

    // 0x800ACAD4: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800ACAD8: nop

    // 0x800ACADC: bc1f        L_800ACB18
    if (!c1cs) {
        // 0x800ACAE0: nop
    
            goto L_800ACB18;
    }
    // 0x800ACAE0: nop

    // 0x800ACAE4: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800ACAE8: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800ACAEC: nop

    // 0x800ACAF0: swc1        $f6, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f6.u32l;
    // 0x800ACAF4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800ACAF8: addiu       $t6, $t6, -0x7390
    ctx->r14 = ADD32(ctx->r14, -0X7390);
    // 0x800ACAFC: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800ACB00: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800ACB04: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x800ACB08: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800ACB0C: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x800ACB10: ori         $t2, $t0, 0x1
    ctx->r10 = ctx->r8 | 0X1;
    // 0x800ACB14: sw          $t2, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r10;
L_800ACB18:
    // 0x800ACB18: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x800ACB1C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x800ACB20: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800ACB24: lw          $v0, -0x7384($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7384);
    // 0x800ACB28: nop

    // 0x800ACB2C: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x800ACB30: b           L_800ACB40
    // 0x800ACB34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800ACB40;
    // 0x800ACB34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800ACB38: b           L_800ACB40
    // 0x800ACB3C: nop

        goto L_800ACB40;
    // 0x800ACB3C: nop

L_800ACB40:
    // 0x800ACB40: jr          $ra
    // 0x800ACB44: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800ACB44: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800A4BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4BE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A4BE8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800A4BEC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4BF0: nop

    // 0x800A4BF4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800A4BF8: lw          $t7, 0xC0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC0);
    // 0x800A4BFC: nop

    // 0x800A4C00: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800A4C04: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4C08: nop

    // 0x800A4C0C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A4C10: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800A4C14: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800A4C18: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800A4C1C: lui         $t0, 0x104
    ctx->r8 = S32(0X104 << 16);
    // 0x800A4C20: ori         $t0, $t0, 0x40
    ctx->r8 = ctx->r8 | 0X40;
    // 0x800A4C24: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A4C28: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A4C2C: lw          $t2, 0x70E4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70E4);
    // 0x800A4C30: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A4C34: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x800A4C38: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A4C3C: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x800A4C40: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A4C44: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800A4C48: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A4C4C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800A4C50: lw          $t7, -0x4CD4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CD4);
    // 0x800A4C54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4C58: beq         $t7, $at, L_800A4DF0
    if (ctx->r15 == ctx->r1) {
        // 0x800A4C5C: nop
    
            goto L_800A4DF0;
    }
    // 0x800A4C5C: nop

    // 0x800A4C60: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4C64: nop

    // 0x800A4C68: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A4C6C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800A4C70: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800A4C74: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A4C78: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x800A4C7C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A4C80: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800A4C84: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800A4C88: ori         $t2, $t2, 0x2205
    ctx->r10 = ctx->r10 | 0X2205;
    // 0x800A4C8C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A4C90: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4C94: nop

    // 0x800A4C98: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A4C9C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800A4CA0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800A4CA4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4CA8: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x800A4CAC: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x800A4CB0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A4CB4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4CB8: lui         $t8, 0xC811
    ctx->r24 = S32(0XC811 << 16);
    // 0x800A4CBC: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x800A4CC0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A4CC4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4CC8: nop

    // 0x800A4CCC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A4CD0: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800A4CD4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A4CD8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A4CDC: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800A4CE0: ori         $t2, $t2, 0x1402
    ctx->r10 = ctx->r10 | 0X1402;
    // 0x800A4CE4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A4CE8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A4CEC: lui         $t4, 0x10
    ctx->r12 = S32(0X10 << 16);
    // 0x800A4CF0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A4CF4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4CF8: nop

    // 0x800A4CFC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A4D00: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A4D04: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800A4D08: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800A4D0C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800A4D10: ori         $t8, $t8, 0x201
    ctx->r24 = ctx->r24 | 0X201;
    // 0x800A4D14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A4D18: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800A4D1C: nop

    // 0x800A4D20: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800A4D24: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4D28: nop

    // 0x800A4D2C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A4D30: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800A4D34: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800A4D38: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800A4D3C: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A4D40: ori         $t3, $t3, 0x1301
    ctx->r11 = ctx->r11 | 0X1301;
    // 0x800A4D44: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A4D48: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A4D4C: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x800A4D50: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A4D54: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4D58: nop

    // 0x800A4D5C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A4D60: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800A4D64: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A4D68: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4D6C: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A4D70: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x800A4D74: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A4D78: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4D7C: nop

    // 0x800A4D80: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A4D84: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4D88: nop

    // 0x800A4D8C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A4D90: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800A4D94: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A4D98: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A4D9C: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A4DA0: ori         $t4, $t4, 0xE02
    ctx->r12 = ctx->r12 | 0XE02;
    // 0x800A4DA4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A4DA8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A4DAC: nop

    // 0x800A4DB0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A4DB4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4DB8: nop

    // 0x800A4DBC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A4DC0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800A4DC4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A4DC8: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800A4DCC: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A4DD0: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x800A4DD4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A4DD8: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800A4DDC: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x800A4DE0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A4DE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A4DE8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A4DEC: sw          $t3, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r11;
L_800A4DF0:
    // 0x800A4DF0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4DF4: nop

    // 0x800A4DF8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A4DFC: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800A4E00: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A4E04: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800A4E08: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A4E0C: ori         $t6, $t6, 0xFE04
    ctx->r14 = ctx->r14 | 0XFE04;
    // 0x800A4E10: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A4E14: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x800A4E18: lui         $t8, 0xFF10
    ctx->r24 = S32(0XFF10 << 16);
    // 0x800A4E1C: ori         $t8, $t8, 0xF3FF
    ctx->r24 = ctx->r24 | 0XF3FF;
    // 0x800A4E20: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A4E24: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4E28: nop

    // 0x800A4E2C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A4E30: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800A4E34: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x800A4E38: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800A4E3C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800A4E40: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A4E44: lw          $t4, 0xCC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XCC);
    // 0x800A4E48: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A4E4C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800A4E50: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A4E54: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800A4E58: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A4E5C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4E60: nop

    // 0x800A4E64: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A4E68: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800A4E6C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800A4E70: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800A4E74: lui         $t9, 0xBD00
    ctx->r25 = S32(0XBD00 << 16);
    // 0x800A4E78: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A4E7C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800A4E80: nop

    // 0x800A4E84: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A4E88: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4E8C: nop

    // 0x800A4E90: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A4E94: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800A4E98: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800A4E9C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800A4EA0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800A4EA4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A4EA8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800A4EAC: nop

    // 0x800A4EB0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A4EB4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4EB8: nop

    // 0x800A4EBC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A4EC0: b           L_800A4ED0
    // 0x800A4EC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A4ED0;
    // 0x800A4EC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A4EC8: b           L_800A4ED0
    // 0x800A4ECC: nop

        goto L_800A4ED0;
    // 0x800A4ECC: nop

L_800A4ED0:
    // 0x800A4ED0: jr          $ra
    // 0x800A4ED4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800A4ED4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8007355C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007355C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073564: jal         0x80061488
    // 0x80073568: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073568: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    after_0:
    // 0x8007356C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073570: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073574: b           L_80073584
    // 0x80073578: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073584;
    // 0x80073578: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007357C: b           L_80073584
    // 0x80073580: nop

        goto L_80073584;
    // 0x80073580: nop

L_80073584:
    // 0x80073584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007358C: jr          $ra
    // 0x80073590: nop

    return;
    // 0x80073590: nop

;}
RECOMP_FUNC void func_800BCCE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCCE4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCCE8: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x800BCCEC: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BCCF0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800BCCF4: nop

    // 0x800BCCF8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800BCCFC: nop

    // 0x800BCD00: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BCD04: bne         $t9, $zero, L_800BCD14
    if (ctx->r25 != 0) {
        // 0x800BCD08: nop
    
            goto L_800BCD14;
    }
    // 0x800BCD08: nop

    // 0x800BCD0C: b           L_800BCD34
    // 0x800BCD10: nop

        goto L_800BCD34;
    // 0x800BCD10: nop

L_800BCD14:
    // 0x800BCD14: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BCD18: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800BCD1C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800BCD20: nop

    // 0x800BCD24: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800BCD28: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x800BCD2C: b           L_800BCD34
    // 0x800BCD30: nop

        goto L_800BCD34;
    // 0x800BCD30: nop

L_800BCD34:
    // 0x800BCD34: jr          $ra
    // 0x800BCD38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCD38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Main_Unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE788: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BE78C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BE790: b           L_800BE798
    // 0x800BE794: nop

        goto L_800BE798;
    // 0x800BE794: nop

L_800BE798:
    // 0x800BE798: jr          $ra
    // 0x800BE79C: nop

    return;
    // 0x800BE79C: nop

;}
RECOMP_FUNC void func_800C0988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0988: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C098C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800C0990: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C0994: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0998: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800C099C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C09A0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C09A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C09A8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800C09AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C09B0: lbu         $t7, -0x63C8($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X63C8);
    // 0x800C09B4: nop

    // 0x800C09B8: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800C09BC: bne         $t8, $zero, L_800C09CC
    if (ctx->r24 != 0) {
        // 0x800C09C0: nop
    
            goto L_800C09CC;
    }
    // 0x800C09C0: nop

    // 0x800C09C4: jr          $ra
    // 0x800C09C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C09C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C09CC:
    // 0x800C09CC: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x800C09D0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C09D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C09D8: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800C09DC: sll         $t4, $a0, 5
    ctx->r12 = S32(ctx->r4 << 5);
    // 0x800C09E0: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800C09E4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C09E8: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C09EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C09F0: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C09F4: addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // 0x800C09F8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x800C09FC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C0A00: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C0A04: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800C0A08: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800C0A0C: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x800C0A10: lbu         $t2, 0x2E9($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X2E9);
    // 0x800C0A14: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800C0A18: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800C0A1C: addiu       $at, $t5, 0x7FFF
    ctx->r1 = ADD32(ctx->r13, 0X7FFF);
    // 0x800C0A20: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800C0A24: sb          $t3, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r11;
    // 0x800C0A28: jr          $ra
    // 0x800C0A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C0A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0A30: jr          $ra
    // 0x800C0A34: nop

    return;
    // 0x800C0A34: nop

    // 0x800C0A38: jr          $ra
    // 0x800C0A3C: nop

    return;
    // 0x800C0A3C: nop

;}
RECOMP_FUNC void func_80005460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005468: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000546C: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80005470: nop

    // 0x80005474: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80005478: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000547C:
    // 0x8000547C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005480: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80005484: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x80005488: nop

    // 0x8000548C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80005490: beq         $t9, $zero, L_80005558
    if (ctx->r25 == 0) {
        // 0x80005494: nop
    
            goto L_80005558;
    }
    // 0x80005494: nop

    // 0x80005498: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x8000549C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800054A0: beq         $t0, $zero, L_80005558
    if (ctx->r8 == 0) {
        // 0x800054A4: nop
    
            goto L_80005558;
    }
    // 0x800054A4: nop

    // 0x800054A8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800054AC: nop

    // 0x800054B0: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x800054B4: nop

    // 0x800054B8: beq         $t2, $zero, L_800054D4
    if (ctx->r10 == 0) {
        // 0x800054BC: nop
    
            goto L_800054D4;
    }
    // 0x800054BC: nop

    // 0x800054C0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800054C4: nop

    // 0x800054C8: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x800054CC: jal         0x800BC980
    // 0x800054D0: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800054D0: nop

    after_0:
L_800054D4:
    // 0x800054D4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800054D8: nop

    // 0x800054DC: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x800054E0: nop

    // 0x800054E4: beq         $t5, $zero, L_80005500
    if (ctx->r13 == 0) {
        // 0x800054E8: nop
    
            goto L_80005500;
    }
    // 0x800054E8: nop

    // 0x800054EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800054F0: nop

    // 0x800054F4: lw          $a0, 0x12C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X12C);
    // 0x800054F8: jal         0x800BC980
    // 0x800054FC: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800054FC: nop

    after_1:
L_80005500:
    // 0x80005500: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005504: nop

    // 0x80005508: lw          $t9, 0x130($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X130);
    // 0x8000550C: nop

    // 0x80005510: beq         $t9, $zero, L_8000552C
    if (ctx->r25 == 0) {
        // 0x80005514: nop
    
            goto L_8000552C;
    }
    // 0x80005514: nop

    // 0x80005518: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000551C: nop

    // 0x80005520: lw          $a0, 0x130($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X130);
    // 0x80005524: jal         0x800BC980
    // 0x80005528: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x80005528: nop

    after_2:
L_8000552C:
    // 0x8000552C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80005530: nop

    // 0x80005534: lw          $t1, 0x144($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X144);
    // 0x80005538: nop

    // 0x8000553C: beq         $t1, $zero, L_80005558
    if (ctx->r9 == 0) {
        // 0x80005540: nop
    
            goto L_80005558;
    }
    // 0x80005540: nop

    // 0x80005544: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80005548: nop

    // 0x8000554C: lw          $a0, 0x144($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X144);
    // 0x80005550: jal         0x800BC980
    // 0x80005554: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80005554: nop

    after_3:
L_80005558:
    // 0x80005558: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8000555C: nop

    // 0x80005560: sw          $zero, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = 0;
    // 0x80005564: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80005568: nop

    // 0x8000556C: sw          $zero, 0x138($t4)
    MEM_W(0X138, ctx->r12) = 0;
    // 0x80005570: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80005574: nop

    // 0x80005578: sw          $zero, 0x12C($t5)
    MEM_W(0X12C, ctx->r13) = 0;
    // 0x8000557C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80005580: nop

    // 0x80005584: sw          $zero, 0x130($t6)
    MEM_W(0X130, ctx->r14) = 0;
    // 0x80005588: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000558C: nop

    // 0x80005590: sw          $zero, 0x144($t7)
    MEM_W(0X144, ctx->r15) = 0;
    // 0x80005594: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80005598: nop

    // 0x8000559C: addiu       $t8, $t9, 0x160
    ctx->r24 = ADD32(ctx->r25, 0X160);
    // 0x800055A0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800055A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800055A8: nop

    // 0x800055AC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800055B0: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800055B4: bne         $at, $zero, L_8000547C
    if (ctx->r1 != 0) {
        // 0x800055B8: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8000547C;
    }
    // 0x800055B8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800055BC: b           L_800055CC
    // 0x800055C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800055CC;
    // 0x800055C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800055C4: b           L_800055CC
    // 0x800055C8: nop

        goto L_800055CC;
    // 0x800055C8: nop

L_800055CC:
    // 0x800055CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800055D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800055D4: jr          $ra
    // 0x800055D8: nop

    return;
    // 0x800055D8: nop

;}
RECOMP_FUNC void func_800AC890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC890: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AC894: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800AC898:
    // 0x800AC898: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC89C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC8A0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800AC8A4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AC8A8: sw          $zero, -0x7384($at)
    MEM_W(-0X7384, ctx->r1) = 0;
    // 0x800AC8AC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8B0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AC8B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC8BC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800AC8C0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800AC8C4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AC8C8: addiu       $t2, $t2, -0x7390
    ctx->r10 = ADD32(ctx->r10, -0X7390);
    // 0x800AC8CC: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800AC8D0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800AC8D4: swc1        $f4, -0x7388($at)
    MEM_W(-0X7388, ctx->r1) = ctx->f4.u32l;
    // 0x800AC8D8: lwc1        $f12, 0x8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800AC8DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC8E0: swc1        $f12, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f12.u32l;
    // 0x800AC8E4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8E8: nop

    // 0x800AC8EC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800AC8F0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800AC8F4: swc1        $f12, -0x7390($at)
    MEM_W(-0X7390, ctx->r1) = ctx->f12.u32l;
    // 0x800AC8F8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8FC: nop

    // 0x800AC900: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800AC904: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x800AC908: bne         $at, $zero, L_800AC898
    if (ctx->r1 != 0) {
        // 0x800AC90C: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800AC898;
    }
    // 0x800AC90C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800AC910: b           L_800AC918
    // 0x800AC914: nop

        goto L_800AC918;
    // 0x800AC914: nop

L_800AC918:
    // 0x800AC918: jr          $ra
    // 0x800AC91C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AC91C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80055CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055CC4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80055CC8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80055CCC:
    // 0x80055CCC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80055CD0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80055CD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055CD8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80055CDC: addiu       $t0, $t0, -0x2AC0
    ctx->r8 = ADD32(ctx->r8, -0X2AC0);
    // 0x80055CE0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80055CE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055CE8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80055CEC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80055CF0: lw          $t8, 0xC($t1)
    ctx->r24 = MEM_W(ctx->r9, 0XC);
    // 0x80055CF4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80055CF8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80055CFC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80055D00: addu        $t4, $t6, $t3
    ctx->r12 = ADD32(ctx->r14, ctx->r11);
    // 0x80055D04: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80055D08: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x80055D0C: nop

    // 0x80055D10: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80055D14: bne         $at, $zero, L_80055D30
    if (ctx->r1 != 0) {
        // 0x80055D18: nop
    
            goto L_80055D30;
    }
    // 0x80055D18: nop

    // 0x80055D1C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80055D20: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80055D24: addu        $t8, $a0, $t4
    ctx->r24 = ADD32(ctx->r4, ctx->r12);
    // 0x80055D28: b           L_80055D54
    // 0x80055D2C: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
        goto L_80055D54;
    // 0x80055D2C: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
L_80055D30:
    // 0x80055D30: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80055D34: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80055D38: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80055D3C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80055D40: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x80055D44: lw          $t5, -0x2AB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AB8);
    // 0x80055D48: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80055D4C: addu        $t1, $a0, $t2
    ctx->r9 = ADD32(ctx->r4, ctx->r10);
    // 0x80055D50: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
L_80055D54:
    // 0x80055D54: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80055D58: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055D5C: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80055D60: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80055D64: addiu       $t9, $t9, -0x2AC0
    ctx->r25 = ADD32(ctx->r25, -0X2AC0);
    // 0x80055D68: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80055D6C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80055D70: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80055D74: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80055D78: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x80055D7C: sll         $t2, $t6, 1
    ctx->r10 = S32(ctx->r14 << 1);
    // 0x80055D80: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80055D84: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80055D88: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x80055D8C: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80055D90: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80055D94: nop

    // 0x80055D98: slt         $at, $t1, $t6
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80055D9C: bne         $at, $zero, L_80055DB4
    if (ctx->r1 != 0) {
        // 0x80055DA0: nop
    
            goto L_80055DB4;
    }
    // 0x80055DA0: nop

    // 0x80055DA4: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x80055DA8: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x80055DAC: b           L_80055DEC
    // 0x80055DB0: sh          $t1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r9;
        goto L_80055DEC;
    // 0x80055DB0: sh          $t1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r9;
L_80055DB4:
    // 0x80055DB4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80055DB8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80055DBC: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80055DC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055DC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80055DC8: lw          $t9, -0x2AB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AB4);
    // 0x80055DCC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80055DD0: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80055DD4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80055DD8: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x80055DDC: lh          $t2, 0x0($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X0);
    // 0x80055DE0: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80055DE4: addu        $t5, $a0, $t1
    ctx->r13 = ADD32(ctx->r4, ctx->r9);
    // 0x80055DE8: sh          $t2, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r10;
L_80055DEC:
    // 0x80055DEC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80055DF0: nop

    // 0x80055DF4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80055DF8: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80055DFC: bne         $at, $zero, L_80055CCC
    if (ctx->r1 != 0) {
        // 0x80055E00: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_80055CCC;
    }
    // 0x80055E00: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80055E04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80055E08: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x80055E0C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80055E10: srl         $t0, $t9, 1
    ctx->r8 = S32(U32(ctx->r25) >> 1);
    // 0x80055E14: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x80055E18: mfhi        $t6
    ctx->r14 = hi;
    // 0x80055E1C: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80055E20: addu        $t3, $t4, $a0
    ctx->r11 = ADD32(ctx->r12, ctx->r4);
    // 0x80055E24: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x80055E28: b           L_80055E38
    // 0x80055E2C: nop

        goto L_80055E38;
    // 0x80055E2C: nop

    // 0x80055E30: b           L_80055E38
    // 0x80055E34: nop

        goto L_80055E38;
    // 0x80055E34: nop

L_80055E38:
    // 0x80055E38: jr          $ra
    // 0x80055E3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80055E3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006D960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D968: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D96C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D970: nop

    // 0x8006D974: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D978: nop

    // 0x8006D97C: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D980: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D984: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D988: beq         $v0, $zero, L_8006D9BC
    if (ctx->r2 == 0) {
        // 0x8006D98C: nop
    
            goto L_8006D9BC;
    }
    // 0x8006D98C: nop

    // 0x8006D990: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006D994: nop

    // 0x8006D998: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D99C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D9A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D9A4: beq         $v0, $zero, L_8006D9BC
    if (ctx->r2 == 0) {
        // 0x8006D9A8: nop
    
            goto L_8006D9BC;
    }
    // 0x8006D9A8: nop

    // 0x8006D9AC: jal         0x8005F064
    // 0x8006D9B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D9B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8006D9B4: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006D9B8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006D9BC:
    // 0x8006D9BC: b           L_8006D9CC
    // 0x8006D9C0: nop

        goto L_8006D9CC;
    // 0x8006D9C0: nop

    // 0x8006D9C4: b           L_8006D9CC
    // 0x8006D9C8: nop

        goto L_8006D9CC;
    // 0x8006D9C8: nop

L_8006D9CC:
    // 0x8006D9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D9D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D9D4: jr          $ra
    // 0x8006D9D8: nop

    return;
    // 0x8006D9D8: nop

;}
RECOMP_FUNC void func_80064010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064018: jal         0x8005F064
    // 0x8006401C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006401C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064020: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064024: b           L_80064034
    // 0x80064028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064034;
    // 0x80064028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006402C: b           L_80064034
    // 0x80064030: nop

        goto L_80064034;
    // 0x80064030: nop

L_80064034:
    // 0x80064034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006403C: jr          $ra
    // 0x80064040: nop

    return;
    // 0x80064040: nop

;}
