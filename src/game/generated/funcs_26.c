#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80013398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013398: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001339C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800133A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800133A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800133A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800133AC: jal         0x8000DA44
    // 0x800133B0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800133B0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800133B4: bgez        $v0, L_800133C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800133B8: nop
    
            goto L_800133C4;
    }
    // 0x800133B8: nop

    // 0x800133BC: b           L_80013464
    // 0x800133C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013464;
    // 0x800133C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800133C4:
    // 0x800133C4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800133C8: nop

    // 0x800133CC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800133D0: nop

    // 0x800133D4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800133D8: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x800133DC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800133E0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800133E4: nop

    // 0x800133E8: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x800133EC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800133F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800133F4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800133F8: nop

    // 0x800133FC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80013400: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x80013404: nop

    // 0x80013408: blez        $t3, L_80013454
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8001340C: nop
    
            goto L_80013454;
    }
    // 0x8001340C: nop

L_80013410:
    // 0x80013410: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80013414: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80013418: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001341C: nop

    // 0x80013420: sw          $t5, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r13;
    // 0x80013424: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80013428: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001342C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80013430: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80013434: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80013438: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8001343C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80013440: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x80013444: nop

    // 0x80013448: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001344C: bne         $at, $zero, L_80013410
    if (ctx->r1 != 0) {
        // 0x80013450: nop
    
            goto L_80013410;
    }
    // 0x80013450: nop

L_80013454:
    // 0x80013454: b           L_80013464
    // 0x80013458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013464;
    // 0x80013458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001345C: b           L_80013464
    // 0x80013460: nop

        goto L_80013464;
    // 0x80013460: nop

L_80013464:
    // 0x80013464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013468: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001346C: jr          $ra
    // 0x80013470: nop

    return;
    // 0x80013470: nop

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
RECOMP_FUNC void alEvtqFlushType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3910: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D3914: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D3918: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x800D391C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D3920: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D3924: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D3928: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D392C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800D3930: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3934: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3938: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800D393C: jal         0x800C41A0
    // 0x800D3940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D3944: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D3948: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800D394C: beq         $s0, $zero, L_800D3998
    if (ctx->r16 == 0) {
        // 0x800D3950: nop
    
            goto L_800D3998;
    }
    // 0x800D3950: nop

L_800D3954:
    // 0x800D3954: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800D3958: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D395C: bne         $s3, $t7, L_800D3990
    if (ctx->r19 != ctx->r15) {
        // 0x800D3960: nop
    
            goto L_800D3990;
    }
    // 0x800D3960: nop

    // 0x800D3964: beq         $s1, $zero, L_800D397C
    if (ctx->r17 == 0) {
        // 0x800D3968: nop
    
            goto L_800D397C;
    }
    // 0x800D3968: nop

    // 0x800D396C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800D3970: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D3974: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D3978: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800D397C:
    // 0x800D397C: jal         0x800C7890
    // 0x800D3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3988: jal         0x800C78C0
    // 0x800D398C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800D398C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800D3990:
    // 0x800D3990: bne         $s1, $zero, L_800D3954
    if (ctx->r17 != 0) {
        // 0x800D3994: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D3954;
    }
    // 0x800D3994: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800D3998:
    // 0x800D3998: jal         0x800C41A0
    // 0x800D399C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800D399C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800D39A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D39A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D39A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D39AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D39B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D39B4: jr          $ra
    // 0x800D39B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D39B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80056118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005611C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056120: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056124: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80056128: nop

    // 0x8005612C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80056130: nop

    // 0x80056134: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x80056138: bne         $at, $zero, L_80056164
    if (ctx->r1 != 0) {
        // 0x8005613C: nop
    
            goto L_80056164;
    }
    // 0x8005613C: nop

    // 0x80056140: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x80056144: nop

    // 0x80056148: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x8005614C: bne         $at, $zero, L_80056164
    if (ctx->r1 != 0) {
        // 0x80056150: nop
    
            goto L_80056164;
    }
    // 0x80056150: nop

    // 0x80056154: jal         0x80061F08
    // 0x80056158: nop

    func_80061F08(rdram, ctx);
        goto after_0;
    // 0x80056158: nop

    after_0:
    // 0x8005615C: beq         $v0, $zero, L_8005616C
    if (ctx->r2 == 0) {
        // 0x80056160: nop
    
            goto L_8005616C;
    }
    // 0x80056160: nop

L_80056164:
    // 0x80056164: b           L_8005617C
    // 0x80056168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005617C;
    // 0x80056168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005616C:
    // 0x8005616C: b           L_8005617C
    // 0x80056170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005617C;
    // 0x80056170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80056174: b           L_8005617C
    // 0x80056178: nop

        goto L_8005617C;
    // 0x80056178: nop

L_8005617C:
    // 0x8005617C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80056184: jr          $ra
    // 0x80056188: nop

    return;
    // 0x80056188: nop

;}
RECOMP_FUNC void func_80064E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064E2C: jal         0x8005F064
    // 0x80064E30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064E30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064E34: b           L_80064E44
    // 0x80064E38: nop

        goto L_80064E44;
    // 0x80064E38: nop

    // 0x80064E3C: b           L_80064E44
    // 0x80064E40: nop

        goto L_80064E44;
    // 0x80064E40: nop

L_80064E44:
    // 0x80064E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064E4C: jr          $ra
    // 0x80064E50: nop

    return;
    // 0x80064E50: nop

;}
RECOMP_FUNC void AudioMgr_HandleFrameMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B8CA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B8CA8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B8CAC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B8CB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B8CB4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800B8CB8: jal         0x800B93E0
    // 0x800B8CBC: nop

    AudioMgr_ClearAudioDMA(rdram, ctx);
        goto after_0;
    // 0x800B8CBC: nop

    after_0:
    // 0x800B8CC0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B8CC4: nop

    // 0x800B8CC8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800B8CCC: jal         0x800C79C0
    // 0x800B8CD0: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800B8CD0: nop

    after_1:
    // 0x800B8CD4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800B8CD8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B8CDC: nop

    // 0x800B8CE0: beq         $t7, $zero, L_800B8D04
    if (ctx->r15 == 0) {
        // 0x800B8CE4: nop
    
            goto L_800B8D04;
    }
    // 0x800B8CE4: nop

    // 0x800B8CE8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800B8CEC: nop

    // 0x800B8CF0: lh          $a1, 0x4($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X4);
    // 0x800B8CF4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B8CF8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800B8CFC: jal         0x800C7A40
    // 0x800B8D00: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x800B8D00: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_2:
L_800B8D04:
    // 0x800B8D04: jal         0x800C79B0
    // 0x800B8D08: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_3;
    // 0x800B8D08: nop

    after_3:
    // 0x800B8D0C: srl         $t0, $v0, 2
    ctx->r8 = S32(U32(ctx->r2) >> 2);
    // 0x800B8D10: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B8D14: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8D18: lw          $t1, -0x33CC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33CC);
    // 0x800B8D1C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800B8D20: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D24: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800B8D28: addiu       $t4, $t3, 0x60
    ctx->r12 = ADD32(ctx->r11, 0X60);
    // 0x800B8D2C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800B8D30: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800B8D34: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x800B8D38: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D3C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B8D40: lw          $t9, -0x33C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33C8);
    // 0x800B8D44: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x800B8D48: nop

    // 0x800B8D4C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B8D50: beq         $at, $zero, L_800B8D6C
    if (ctx->r1 == 0) {
        // 0x800B8D54: nop
    
            goto L_800B8D6C;
    }
    // 0x800B8D54: nop

    // 0x800B8D58: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B8D5C: lw          $t0, -0x33C8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X33C8);
    // 0x800B8D60: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D64: nop

    // 0x800B8D68: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
L_800B8D6C:
    // 0x800B8D6C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B8D70: lw          $t2, -0x33C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X33C0);
    // 0x800B8D74: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D78: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8D7C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B8D80: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800B8D84: lw          $a0, -0x34B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34B0);
    // 0x800B8D88: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B8D8C: lh          $a3, 0x4($t4)
    ctx->r7 = MEM_H(ctx->r12, 0X4);
    // 0x800B8D90: jal         0x800C7C38
    // 0x800B8D94: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    alAudioFrame(rdram, ctx);
        goto after_4;
    // 0x800B8D94: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x800B8D98: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B8D9C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8DA0: nop

    // 0x800B8DA4: bne         $t5, $zero, L_800B8DB4
    if (ctx->r13 != 0) {
        // 0x800B8DA8: nop
    
            goto L_800B8DB4;
    }
    // 0x800B8DA8: nop

    // 0x800B8DAC: b           L_800B8F5C
    // 0x800B8DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B8F5C;
    // 0x800B8DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B8DB4:
    // 0x800B8DB4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B8DB8: nop

    // 0x800B8DBC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800B8DC0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800B8DC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DC8: nop

    // 0x800B8DCC: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800B8DD0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B8DD4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DD8: addiu       $t9, $t9, -0x34B0
    ctx->r25 = ADD32(ctx->r25, -0X34B0);
    // 0x800B8DDC: addiu       $t0, $t9, 0x14
    ctx->r8 = ADD32(ctx->r25, 0X14);
    // 0x800B8DE0: sw          $t0, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->r8;
    // 0x800B8DE4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B8DE8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DEC: addiu       $t3, $t2, 0x60
    ctx->r11 = ADD32(ctx->r10, 0X60);
    // 0x800B8DF0: sw          $t3, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->r11;
    // 0x800B8DF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DF8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800B8DFC: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x800B8E00: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E04: nop

    // 0x800B8E08: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x800B8E0C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B8E10: lw          $t8, -0x33C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X33C0);
    // 0x800B8E14: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B8E18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B8E1C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B8E20: lw          $t0, -0x34B0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X34B0);
    // 0x800B8E24: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E28: nop

    // 0x800B8E2C: sw          $t0, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->r8;
    // 0x800B8E30: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800B8E34: lw          $t3, -0x33C0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33C0);
    // 0x800B8E38: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800B8E3C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B8E40: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800B8E44: lw          $t5, -0x34B0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X34B0);
    // 0x800B8E48: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B8E4C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E50: subu        $t6, $t2, $t5
    ctx->r14 = SUB32(ctx->r10, ctx->r13);
    // 0x800B8E54: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B8E58: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B8E5C: sw          $t8, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r24;
    // 0x800B8E60: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E64: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800B8E68: sw          $t0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r8;
    // 0x800B8E6C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E70: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800B8E74: addiu       $t3, $t3, 0x6B70
    ctx->r11 = ADD32(ctx->r11, 0X6B70);
    // 0x800B8E78: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x800B8E7C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800B8E80: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800B8E84: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E88: addiu       $t5, $t5, 0x6B70
    ctx->r13 = ADD32(ctx->r13, 0X6B70);
    // 0x800B8E8C: addiu       $t2, $t2, 0x6C40
    ctx->r10 = ADD32(ctx->r10, 0X6C40);
    // 0x800B8E90: subu        $t6, $t2, $t5
    ctx->r14 = SUB32(ctx->r10, ctx->r13);
    // 0x800B8E94: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
    // 0x800B8E98: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E9C: nop

    // 0x800B8EA0: sw          $zero, 0x14($t8)
    MEM_W(0X14, ctx->r24) = 0;
    // 0x800B8EA4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EA8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B8EAC: addiu       $t9, $t9, -0x7050
    ctx->r25 = ADD32(ctx->r25, -0X7050);
    // 0x800B8EB0: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
    // 0x800B8EB4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EB8: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800B8EBC: addiu       $t1, $t1, 0x1620
    ctx->r9 = ADD32(ctx->r9, 0X1620);
    // 0x800B8EC0: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x800B8EC4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EC8: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x800B8ECC: sw          $t4, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r12;
    // 0x800B8ED0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B8ED4: nop

    // 0x800B8ED8: sw          $zero, 0x48($t5)
    MEM_W(0X48, ctx->r13) = 0;
    // 0x800B8EDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EE0: nop

    // 0x800B8EE4: sw          $zero, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = 0;
    // 0x800B8EE8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EEC: nop

    // 0x800B8EF0: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x800B8EF4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EF8: nop

    // 0x800B8EFC: sw          $zero, 0x34($t8)
    MEM_W(0X34, ctx->r24) = 0;
    // 0x800B8F00: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B8F04: nop

    // 0x800B8F08: sw          $zero, 0x38($t9)
    MEM_W(0X38, ctx->r25) = 0;
    // 0x800B8F0C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B8F10: nop

    // 0x800B8F14: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x800B8F18: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B8F1C: jal         0x80097408
    // 0x800B8F20: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    func_80097408(rdram, ctx);
        goto after_5;
    // 0x800B8F20: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_5:
    // 0x800B8F24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B8F28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B8F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B8F30: jal         0x800C4AA0
    // 0x800B8F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800B8F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x800B8F38: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8F3C: lw          $t1, -0x33C0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33C0);
    // 0x800B8F40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8F44: xori        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 ^ 0X1;
    // 0x800B8F48: sw          $t3, -0x33C0($at)
    MEM_W(-0X33C0, ctx->r1) = ctx->r11;
    // 0x800B8F4C: b           L_800B8F5C
    // 0x800B8F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B8F5C;
    // 0x800B8F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B8F54: b           L_800B8F5C
    // 0x800B8F58: nop

        goto L_800B8F5C;
    // 0x800B8F58: nop

L_800B8F5C:
    // 0x800B8F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8F60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B8F64: jr          $ra
    // 0x800B8F68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B8F68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006B258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B260: jal         0x80061348
    // 0x8006B264: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006B264: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006B268: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B26C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B274: beq         $v0, $zero, L_8006B2B4
    if (ctx->r2 == 0) {
        // 0x8006B278: nop
    
            goto L_8006B2B4;
    }
    // 0x8006B278: nop

    // 0x8006B27C: jal         0x80061348
    // 0x8006B280: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006B280: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006B284: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B288: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B28C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B290: beq         $v0, $zero, L_8006B2B4
    if (ctx->r2 == 0) {
        // 0x8006B294: nop
    
            goto L_8006B2B4;
    }
    // 0x8006B294: nop

    // 0x8006B298: jal         0x80061348
    // 0x8006B29C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006B29C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006B2A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B2A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B2A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B2AC: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B2B0: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B2B0: nop

L_8006B2B4:
    // 0x8006B2B4: jal         0x80061348
    // 0x8006B2B8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006B2B8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006B2BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B2C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B2C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B2C8: beq         $v0, $zero, L_8006B308
    if (ctx->r2 == 0) {
        // 0x8006B2CC: nop
    
            goto L_8006B308;
    }
    // 0x8006B2CC: nop

    // 0x8006B2D0: jal         0x80061348
    // 0x8006B2D4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006B2D4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006B2D8: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B2DC: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B2E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B2E4: beq         $v0, $zero, L_8006B308
    if (ctx->r2 == 0) {
        // 0x8006B2E8: nop
    
            goto L_8006B308;
    }
    // 0x8006B2E8: nop

    // 0x8006B2EC: jal         0x80061348
    // 0x8006B2F0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006B2F0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006B2F4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B2F8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B2FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B300: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B304: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B304: nop

L_8006B308:
    // 0x8006B308: jal         0x80061348
    // 0x8006B30C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006B30C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006B310: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B314: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B318: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B31C: beq         $v0, $zero, L_8006B35C
    if (ctx->r2 == 0) {
        // 0x8006B320: nop
    
            goto L_8006B35C;
    }
    // 0x8006B320: nop

    // 0x8006B324: jal         0x80061348
    // 0x8006B328: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006B328: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006B32C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B330: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B334: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B338: beq         $v0, $zero, L_8006B35C
    if (ctx->r2 == 0) {
        // 0x8006B33C: nop
    
            goto L_8006B35C;
    }
    // 0x8006B33C: nop

    // 0x8006B340: jal         0x80061348
    // 0x8006B344: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006B344: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006B348: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B34C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B350: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B354: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B358: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B358: nop

L_8006B35C:
    // 0x8006B35C: jal         0x80061348
    // 0x8006B360: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006B360: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006B364: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B368: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B36C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B370: beq         $v0, $zero, L_8006B3B0
    if (ctx->r2 == 0) {
        // 0x8006B374: nop
    
            goto L_8006B3B0;
    }
    // 0x8006B374: nop

    // 0x8006B378: jal         0x80061348
    // 0x8006B37C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006B37C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006B380: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B384: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B388: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B38C: beq         $v0, $zero, L_8006B3B0
    if (ctx->r2 == 0) {
        // 0x8006B390: nop
    
            goto L_8006B3B0;
    }
    // 0x8006B390: nop

    // 0x8006B394: jal         0x80061348
    // 0x8006B398: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006B398: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006B39C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B3A0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B3A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B3A8: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B3AC: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B3AC: nop

L_8006B3B0:
    // 0x8006B3B0: jal         0x80061348
    // 0x8006B3B4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006B3B4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006B3B8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B3BC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B3C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B3C4: beq         $v0, $zero, L_8006B404
    if (ctx->r2 == 0) {
        // 0x8006B3C8: nop
    
            goto L_8006B404;
    }
    // 0x8006B3C8: nop

    // 0x8006B3CC: jal         0x80061348
    // 0x8006B3D0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006B3D0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006B3D4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B3D8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B3DC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B3E0: beq         $v0, $zero, L_8006B404
    if (ctx->r2 == 0) {
        // 0x8006B3E4: nop
    
            goto L_8006B404;
    }
    // 0x8006B3E4: nop

    // 0x8006B3E8: jal         0x80061348
    // 0x8006B3EC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006B3EC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006B3F0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B3F4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B3F8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B3FC: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B400: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B400: nop

L_8006B404:
    // 0x8006B404: jal         0x80061348
    // 0x8006B408: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006B408: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006B40C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B410: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B414: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B418: beq         $v0, $zero, L_8006B458
    if (ctx->r2 == 0) {
        // 0x8006B41C: nop
    
            goto L_8006B458;
    }
    // 0x8006B41C: nop

    // 0x8006B420: jal         0x80061348
    // 0x8006B424: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006B424: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006B428: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B42C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B430: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B434: beq         $v0, $zero, L_8006B458
    if (ctx->r2 == 0) {
        // 0x8006B438: nop
    
            goto L_8006B458;
    }
    // 0x8006B438: nop

    // 0x8006B43C: jal         0x80061348
    // 0x8006B440: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006B440: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006B444: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B448: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B44C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B450: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B454: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B454: nop

L_8006B458:
    // 0x8006B458: jal         0x80061348
    // 0x8006B45C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006B45C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006B460: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B464: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B468: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B46C: beq         $v0, $zero, L_8006B4AC
    if (ctx->r2 == 0) {
        // 0x8006B470: nop
    
            goto L_8006B4AC;
    }
    // 0x8006B470: nop

    // 0x8006B474: jal         0x80061348
    // 0x8006B478: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006B478: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006B47C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B480: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B484: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B488: beq         $v0, $zero, L_8006B4AC
    if (ctx->r2 == 0) {
        // 0x8006B48C: nop
    
            goto L_8006B4AC;
    }
    // 0x8006B48C: nop

    // 0x8006B490: jal         0x80061348
    // 0x8006B494: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006B494: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006B498: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B49C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B4A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B4A4: bne         $v0, $zero, L_8006B4F8
    if (ctx->r2 != 0) {
        // 0x8006B4A8: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B4A8: nop

L_8006B4AC:
    // 0x8006B4AC: jal         0x80061348
    // 0x8006B4B0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006B4B0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006B4B4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B4B8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B4BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B4C0: beq         $v0, $zero, L_8006B4F8
    if (ctx->r2 == 0) {
        // 0x8006B4C4: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B4C4: nop

    // 0x8006B4C8: jal         0x80061348
    // 0x8006B4CC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006B4CC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006B4D0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B4D4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B4D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B4DC: beq         $v0, $zero, L_8006B4F8
    if (ctx->r2 == 0) {
        // 0x8006B4E0: nop
    
            goto L_8006B4F8;
    }
    // 0x8006B4E0: nop

    // 0x8006B4E4: jal         0x80061348
    // 0x8006B4E8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006B4E8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006B4EC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B4F0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B4F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006B4F8:
    // 0x8006B4F8: b           L_8006B508
    // 0x8006B4FC: nop

        goto L_8006B508;
    // 0x8006B4FC: nop

    // 0x8006B500: b           L_8006B508
    // 0x8006B504: nop

        goto L_8006B508;
    // 0x8006B504: nop

L_8006B508:
    // 0x8006B508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B50C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B510: jr          $ra
    // 0x8006B514: nop

    return;
    // 0x8006B514: nop

;}
RECOMP_FUNC void func_800B73DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B73DC: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B73E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B73E4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B73E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B73EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B73F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B73F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B73F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B73FC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B7400: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B7404: swc1        $f18, -0x44CC($at)
    MEM_W(-0X44CC, ctx->r1) = ctx->f18.u32l;
    // 0x800B7408: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800B740C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B7410: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B7414: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7418: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B741C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7420: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B7424: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B7428: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B742C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B7430: swc1        $f18, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f18.u32l;
    // 0x800B7434: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x800B7438: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B743C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B7440: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B7444: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7448: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B744C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B7450: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B7454: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B7458: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800B745C: swc1        $f18, -0x44C4($at)
    MEM_W(-0X44C4, ctx->r1) = ctx->f18.u32l;
    // 0x800B7460: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x800B7464: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B7468: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
    // 0x800B746C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B7470: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x800B7474: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x800B7478: nop

    // 0x800B747C: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x800B7480: sh          $t2, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r10;
    // 0x800B7484: jr          $ra
    // 0x800B7488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B7488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8009600C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009600C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80096010: addiu       $t6, $t6, -0x28B8
    ctx->r14 = ADD32(ctx->r14, -0X28B8);
    // 0x80096014: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096018: sw          $t6, -0x2878($at)
    MEM_W(-0X2878, ctx->r1) = ctx->r14;
    // 0x8009601C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80096020: addiu       $t7, $t7, -0x2870
    ctx->r15 = ADD32(ctx->r15, -0X2870);
    // 0x80096024: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096028: sw          $t7, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r15;
    // 0x8009602C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80096030: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096034: sw          $t8, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r24;
    // 0x80096038: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8009603C: lhu         $t9, -0x44C8($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X44C8);
    // 0x80096040: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096044: sh          $t9, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r25;
    // 0x80096048: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8009604C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096050: lw          $t1, -0x2878($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2878);
    // 0x80096054: lw          $t0, -0x4CD8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4CD8);
    // 0x80096058: nop

    // 0x8009605C: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80096060: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80096064: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096068: lw          $t3, -0x282C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X282C);
    // 0x8009606C: lhu         $t2, -0x44C0($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X44C0);
    // 0x80096070: nop

    // 0x80096074: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80096078: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009607C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096080: swc1        $f4, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f4.u32l;
    // 0x80096084: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80096088: addiu       $t4, $t4, -0x3AB8
    ctx->r12 = ADD32(ctx->r12, -0X3AB8);
    // 0x8009608C: sh          $zero, 0x104($t4)
    MEM_H(0X104, ctx->r12) = 0;
    // 0x80096090: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096094: addiu       $t5, $t5, -0x3AB8
    ctx->r13 = ADD32(ctx->r13, -0X3AB8);
    // 0x80096098: sh          $zero, 0x106($t5)
    MEM_H(0X106, ctx->r13) = 0;
    // 0x8009609C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800960A0: addiu       $t6, $t6, -0x3AB8
    ctx->r14 = ADD32(ctx->r14, -0X3AB8);
    // 0x800960A4: sh          $zero, 0x108($t6)
    MEM_H(0X108, ctx->r14) = 0;
    // 0x800960A8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800960AC: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x800960B0: sh          $zero, 0x10A($t7)
    MEM_H(0X10A, ctx->r15) = 0;
    // 0x800960B4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800960B8: addiu       $t8, $t8, -0x3AB8
    ctx->r24 = ADD32(ctx->r24, -0X3AB8);
    // 0x800960BC: sh          $zero, 0x10C($t8)
    MEM_H(0X10C, ctx->r24) = 0;
    // 0x800960C0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800960C4: lh          $t9, -0x4CC8($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4CC8);
    // 0x800960C8: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800960CC: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800960D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800960D4: sh          $t0, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r8;
    // 0x800960D8: jr          $ra
    // 0x800960DC: nop

    return;
    // 0x800960DC: nop

    // 0x800960E0: jr          $ra
    // 0x800960E4: nop

    return;
    // 0x800960E4: nop

;}
RECOMP_FUNC void func_800047C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800047C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800047CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800047D0: nop

    // 0x800047D4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800047D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800047DC: nop

    // 0x800047E0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800047E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800047E8: nop

    // 0x800047EC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800047F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800047F4: nop

    // 0x800047F8: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800047FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80004800: nop

    // 0x80004804: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80004808: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000480C: nop

    // 0x80004810: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80004814: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80004818: sh          $t6, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r14;
    // 0x8000481C: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80004820: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x80004824: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80004828: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8000482C: nop

    // 0x80004830: lw          $t8, 0x144($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X144);
    // 0x80004834: nop

    // 0x80004838: bne         $t8, $zero, L_80004848
    if (ctx->r24 != 0) {
        // 0x8000483C: sw          $t8, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r24;
            goto L_80004848;
    }
    // 0x8000483C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80004840: b           L_80004AD4
    // 0x80004844: nop

        goto L_80004AD4;
    // 0x80004844: nop

L_80004848:
    // 0x80004848: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8000484C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004850: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80004854: nop

    // 0x80004858: bne         $t0, $at, L_80004878
    if (ctx->r8 != ctx->r1) {
        // 0x8000485C: nop
    
            goto L_80004878;
    }
    // 0x8000485C: nop

    // 0x80004860: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x80004864: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004868: bne         $t1, $at, L_80004878
    if (ctx->r9 != ctx->r1) {
        // 0x8000486C: nop
    
            goto L_80004878;
    }
    // 0x8000486C: nop

    // 0x80004870: b           L_80004ACC
    // 0x80004874: nop

        goto L_80004ACC;
    // 0x80004874: nop

L_80004878:
    // 0x80004878: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8000487C: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x80004880: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80004884: nop

    // 0x80004888: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8000488C: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80004890: nop

    // 0x80004894: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004898: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8000489C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800048A0: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x800048A4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800048A8: nop

    // 0x800048AC: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
    // 0x800048B0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800048B4: nop

    // 0x800048B8: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x800048BC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800048C0: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800048C4: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x800048C8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800048CC: nop

    // 0x800048D0: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x800048D4: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800048D8: nop

    // 0x800048DC: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x800048E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800048E4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800048E8: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x800048EC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800048F0: nop

    // 0x800048F4: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
    // 0x800048F8: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800048FC: nop

    // 0x80004900: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x80004904: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80004908: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8000490C: addiu       $t4, $sp, 0xC
    ctx->r12 = ADD32(ctx->r29, 0XC);
    // 0x80004910: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80004914: nop

    // 0x80004918: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8000491C: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80004920: nop

    // 0x80004924: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004928: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8000492C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80004930: addiu       $t0, $sp, 0xC
    ctx->r8 = ADD32(ctx->r29, 0XC);
    // 0x80004934: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80004938: nop

    // 0x8000493C: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
    // 0x80004940: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80004944: nop

    // 0x80004948: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x8000494C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80004950: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80004954: addiu       $t4, $sp, 0xC
    ctx->r12 = ADD32(ctx->r29, 0XC);
    // 0x80004958: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000495C: nop

    // 0x80004960: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80004964: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80004968: nop

    // 0x8000496C: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004970: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80004974: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80004978: addiu       $t0, $sp, 0xC
    ctx->r8 = ADD32(ctx->r29, 0XC);
    // 0x8000497C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80004980: nop

    // 0x80004984: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
    // 0x80004988: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8000498C: nop

    // 0x80004990: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x80004994: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80004998: addiu       $t2, $sp, 0xC
    ctx->r10 = ADD32(ctx->r29, 0XC);
    // 0x8000499C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800049A0: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800049A4: andi        $t4, $t3, 0x7F00
    ctx->r12 = ctx->r11 & 0X7F00;
    // 0x800049A8: bne         $t4, $at, L_80004AC4
    if (ctx->r12 != ctx->r1) {
        // 0x800049AC: nop
    
            goto L_80004AC4;
    }
    // 0x800049AC: nop

    // 0x800049B0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800049B4: lh          $t7, 0x7268($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7268);
    // 0x800049B8: sra         $t5, $t3, 2
    ctx->r13 = S32(SIGNED(ctx->r11) >> 2);
    // 0x800049BC: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800049C0: bne         $t6, $t7, L_80004AC4
    if (ctx->r14 != ctx->r15) {
        // 0x800049C4: nop
    
            goto L_80004AC4;
    }
    // 0x800049C4: nop

    // 0x800049C8: addiu       $t8, $sp, 0x4
    ctx->r24 = ADD32(ctx->r29, 0X4);
    // 0x800049CC: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x800049D0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800049D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800049D8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800049DC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800049E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800049E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800049E8: nop

    // 0x800049EC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800049F0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800049F4: addiu       $t2, $sp, 0x4
    ctx->r10 = ADD32(ctx->r29, 0X4);
    // 0x800049F8: lh          $t4, 0x2($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X2);
    // 0x800049FC: nop

    // 0x80004A00: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80004A04: nop

    // 0x80004A08: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004A0C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80004A10: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80004A14: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x80004A18: nop

    // 0x80004A1C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80004A20: nop

    // 0x80004A24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004A28: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80004A2C: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80004A30: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80004A34: nop

    // 0x80004A38: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80004A3C: nop

    // 0x80004A40: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004A44: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x80004A48: addiu       $t8, $sp, 0x4
    ctx->r24 = ADD32(ctx->r29, 0X4);
    // 0x80004A4C: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x80004A50: nop

    // 0x80004A54: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80004A58: nop

    // 0x80004A5C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004A60: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80004A64: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80004A68: lh          $t1, 0x6($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X6);
    // 0x80004A6C: nop

    // 0x80004A70: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80004A74: nop

    // 0x80004A78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004A7C: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80004A80: addiu       $t2, $sp, 0xC
    ctx->r10 = ADD32(ctx->r29, 0XC);
    // 0x80004A84: lhu         $t4, 0x2($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X2);
    // 0x80004A88: nop

    // 0x80004A8C: sh          $t4, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r12;
    // 0x80004A90: addiu       $t3, $sp, 0xC
    ctx->r11 = ADD32(ctx->r29, 0XC);
    // 0x80004A94: lhu         $t5, 0x4($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X4);
    // 0x80004A98: nop

    // 0x80004A9C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80004AA0: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x80004AA4: addiu       $t7, $sp, 0xC
    ctx->r15 = ADD32(ctx->r29, 0XC);
    // 0x80004AA8: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x80004AAC: nop

    // 0x80004AB0: sra         $t0, $t8, 8
    ctx->r8 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80004AB4: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x80004AB8: sh          $t9, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r25;
    // 0x80004ABC: b           L_80004ACC
    // 0x80004AC0: nop

        goto L_80004ACC;
    // 0x80004AC0: nop

L_80004AC4:
    // 0x80004AC4: b           L_80004848
    // 0x80004AC8: nop

        goto L_80004848;
    // 0x80004AC8: nop

L_80004ACC:
    // 0x80004ACC: b           L_80004AD4
    // 0x80004AD0: nop

        goto L_80004AD4;
    // 0x80004AD0: nop

L_80004AD4:
    // 0x80004AD4: jr          $ra
    // 0x80004AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Scheduler_AppendTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097D44: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80097D48: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80097D4C: nop

    // 0x80097D50: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80097D54: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80097D58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80097D5C: bne         $t7, $at, L_80097D94
    if (ctx->r15 != ctx->r1) {
        // 0x80097D60: nop
    
            goto L_80097D94;
    }
    // 0x80097D60: nop

    // 0x80097D64: lw          $t8, 0x28C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X28C);
    // 0x80097D68: nop

    // 0x80097D6C: beq         $t8, $zero, L_80097D80
    if (ctx->r24 == 0) {
        // 0x80097D70: nop
    
            goto L_80097D80;
    }
    // 0x80097D70: nop

    // 0x80097D74: lw          $t9, 0x28C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X28C);
    // 0x80097D78: b           L_80097D84
    // 0x80097D7C: sw          $a1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r5;
        goto L_80097D84;
    // 0x80097D7C: sw          $a1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r5;
L_80097D80:
    // 0x80097D80: sw          $a1, 0x284($a0)
    MEM_W(0X284, ctx->r4) = ctx->r5;
L_80097D84:
    // 0x80097D84: sw          $a1, 0x28C($a0)
    MEM_W(0X28C, ctx->r4) = ctx->r5;
    // 0x80097D88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80097D8C: b           L_80097DB8
    // 0x80097D90: sw          $t0, 0x2A4($a0)
    MEM_W(0X2A4, ctx->r4) = ctx->r8;
        goto L_80097DB8;
    // 0x80097D90: sw          $t0, 0x2A4($a0)
    MEM_W(0X2A4, ctx->r4) = ctx->r8;
L_80097D94:
    // 0x80097D94: lw          $t1, 0x290($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X290);
    // 0x80097D98: nop

    // 0x80097D9C: beq         $t1, $zero, L_80097DB0
    if (ctx->r9 == 0) {
        // 0x80097DA0: nop
    
            goto L_80097DB0;
    }
    // 0x80097DA0: nop

    // 0x80097DA4: lw          $t2, 0x290($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X290);
    // 0x80097DA8: b           L_80097DB4
    // 0x80097DAC: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
        goto L_80097DB4;
    // 0x80097DAC: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80097DB0:
    // 0x80097DB0: sw          $a1, 0x288($a0)
    MEM_W(0X288, ctx->r4) = ctx->r5;
L_80097DB4:
    // 0x80097DB4: sw          $a1, 0x290($a0)
    MEM_W(0X290, ctx->r4) = ctx->r5;
L_80097DB8:
    // 0x80097DB8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80097DBC: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x80097DC0: nop

    // 0x80097DC4: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80097DC8: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80097DCC: b           L_80097DD4
    // 0x80097DD0: nop

        goto L_80097DD4;
    // 0x80097DD0: nop

L_80097DD4:
    // 0x80097DD4: jr          $ra
    // 0x80097DD8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80097DD8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80016138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001613C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80016148: jal         0x80016074
    // 0x8001614C: nop

    func_80016074(rdram, ctx);
        goto after_0;
    // 0x8001614C: nop

    after_0:
    // 0x80016150: bne         $v0, $zero, L_80016160
    if (ctx->r2 != 0) {
        // 0x80016154: nop
    
            goto L_80016160;
    }
    // 0x80016154: nop

    // 0x80016158: b           L_800161D0
    // 0x8001615C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800161D0;
    // 0x8001615C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80016160:
    // 0x80016160: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80016164: lw          $t6, -0x4538($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4538);
    // 0x80016168: nop

    // 0x8001616C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80016170: nop

    // 0x80016174: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x80016178: nop

    // 0x8001617C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80016180: beq         $t9, $zero, L_80016190
    if (ctx->r25 == 0) {
        // 0x80016184: nop
    
            goto L_80016190;
    }
    // 0x80016184: nop

    // 0x80016188: b           L_800161D0
    // 0x8001618C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800161D0;
    // 0x8001618C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016190:
    // 0x80016190: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80016194: lw          $t0, -0x4538($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4538);
    // 0x80016198: nop

    // 0x8001619C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800161A0: nop

    // 0x800161A4: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x800161A8: nop

    // 0x800161AC: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800161B0: beq         $t3, $zero, L_800161C0
    if (ctx->r11 == 0) {
        // 0x800161B4: nop
    
            goto L_800161C0;
    }
    // 0x800161B4: nop

    // 0x800161B8: b           L_800161D0
    // 0x800161BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800161D0;
    // 0x800161BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800161C0:
    // 0x800161C0: b           L_800161D0
    // 0x800161C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800161D0;
    // 0x800161C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800161C8: b           L_800161D0
    // 0x800161CC: nop

        goto L_800161D0;
    // 0x800161CC: nop

L_800161D0:
    // 0x800161D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800161D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800161D8: jr          $ra
    // 0x800161DC: nop

    return;
    // 0x800161DC: nop

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
RECOMP_FUNC void func_8000D934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D934: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000D938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D93C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000D940: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000D944: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000D948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000D94C: jal         0x8000D688
    // 0x8000D950: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x8000D950: nop

    after_0:
    // 0x8000D954: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000D958: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D95C: nop

    // 0x8000D960: bne         $t6, $zero, L_8000D970
    if (ctx->r14 != 0) {
        // 0x8000D964: nop
    
            goto L_8000D970;
    }
    // 0x8000D964: nop

    // 0x8000D968: b           L_8000DA34
    // 0x8000D96C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000DA34;
    // 0x8000D96C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D970:
    // 0x8000D970: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D974: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8000D978: blez        $t7, L_8000DA24
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000D97C: nop
    
            goto L_8000DA24;
    }
    // 0x8000D97C: nop

L_8000D980:
    // 0x8000D980: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000D984: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D988: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000D98C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000D990: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000D994: lwc1        $f4, 0x1EC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1EC);
    // 0x8000D998: nop

    // 0x8000D99C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000D9A0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8000D9A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000D9A8: bgez        $t0, L_8000D9BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8000D9AC: andi        $t1, $t0, 0x7F
        ctx->r9 = ctx->r8 & 0X7F;
            goto L_8000D9BC;
    }
    // 0x8000D9AC: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x8000D9B0: beq         $t1, $zero, L_8000D9BC
    if (ctx->r9 == 0) {
        // 0x8000D9B4: nop
    
            goto L_8000D9BC;
    }
    // 0x8000D9B4: nop

    // 0x8000D9B8: addiu       $t1, $t1, -0x80
    ctx->r9 = ADD32(ctx->r9, -0X80);
L_8000D9BC:
    // 0x8000D9BC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8000D9C0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D9C4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000D9C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000D9CC: lw          $t5, 0x210($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X210);
    // 0x8000D9D0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000D9D4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000D9D8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8000D9DC: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x8000D9E0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8000D9E4: nop

    // 0x8000D9E8: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x8000D9EC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8000D9F0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D9F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D9F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000D9FC: lwc1        $f8, 0x1EC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1EC);
    // 0x8000DA00: nop

    // 0x8000DA04: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000DA08: swc1        $f16, 0x1EC($t1)
    MEM_W(0X1EC, ctx->r9) = ctx->f16.u32l;
    // 0x8000DA0C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8000DA10: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DA14: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8000DA18: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000DA1C: bne         $at, $zero, L_8000D980
    if (ctx->r1 != 0) {
        // 0x8000DA20: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_8000D980;
    }
    // 0x8000DA20: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_8000DA24:
    // 0x8000DA24: b           L_8000DA34
    // 0x8000DA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DA34;
    // 0x8000DA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DA2C: b           L_8000DA34
    // 0x8000DA30: nop

        goto L_8000DA34;
    // 0x8000DA30: nop

L_8000DA34:
    // 0x8000DA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DA38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000DA3C: jr          $ra
    // 0x8000DA40: nop

    return;
    // 0x8000DA40: nop

;}
RECOMP_FUNC void func_80068F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068F50: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068F54: nop

    // 0x80068F58: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80068F5C: nop

    // 0x80068F60: slti        $t7, $v0, 0x385
    ctx->r15 = SIGNED(ctx->r2) < 0X385 ? 1 : 0;
    // 0x80068F64: jr          $ra
    // 0x80068F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F6C: jr          $ra
    // 0x80068F70: nop

    return;
    // 0x80068F70: nop

    // 0x80068F74: jr          $ra
    // 0x80068F78: nop

    return;
    // 0x80068F78: nop

;}
RECOMP_FUNC void Spi_Decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFB60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BFB64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BFB68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BFB6C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB70: sw          $zero, 0x47C($at)
    MEM_W(0X47C, ctx->r1) = 0;
    // 0x800BFB74: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800BFB78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800BFB7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB80: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
    // 0x800BFB84: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BFB88:
    // 0x800BFB88: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BFB8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFB90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BFB94: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BFB98: sw          $t6, 0x228($at)
    MEM_W(0X228, ctx->r1) = ctx->r14;
    // 0x800BFB9C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BFBA0: nop

    // 0x800BFBA4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BFBA8: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800BFBAC: bne         $at, $zero, L_800BFB88
    if (ctx->r1 != 0) {
        // 0x800BFBB0: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_800BFB88;
    }
    // 0x800BFBB0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800BFBB4: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800BFBB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFBBC: sw          $t0, 0x42C($at)
    MEM_W(0X42C, ctx->r1) = ctx->r8;
    // 0x800BFBC0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFBC4: addiu       $t1, $t1, 0x490
    ctx->r9 = ADD32(ctx->r9, 0X490);
    // 0x800BFBC8: lbu         $t2, 0x3($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X3);
    // 0x800BFBCC: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800BFBD0: bne         $t2, $at, L_800BFDE0
    if (ctx->r10 != ctx->r1) {
        // 0x800BFBD4: nop
    
            goto L_800BFDE0;
    }
    // 0x800BFBD4: nop

    // 0x800BFBD8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFBDC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFBE0: lw          $t4, 0x46C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X46C);
    // 0x800BFBE4: lw          $t3, 0x454($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X454);
    // 0x800BFBE8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFBEC: lw          $t6, 0x494($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X494);
    // 0x800BFBF0: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800BFBF4: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x800BFBF8: beq         $at, $zero, L_800BFDD8
    if (ctx->r1 == 0) {
        // 0x800BFBFC: nop
    
            goto L_800BFDD8;
    }
    // 0x800BFBFC: nop

L_800BFC00:
    // 0x800BFC00: jal         0x800C0328
    // 0x800BFC04: nop

    func_800C0328(rdram, ctx);
        goto after_0;
    // 0x800BFC04: nop

    after_0:
    // 0x800BFC08: beq         $v0, $zero, L_800BFC54
    if (ctx->r2 == 0) {
        // 0x800BFC0C: nop
    
            goto L_800BFC54;
    }
    // 0x800BFC0C: nop

    // 0x800BFC10: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFC14: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFC18: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFC1C: lw          $t9, 0x454($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X454);
    // 0x800BFC20: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800BFC24: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFC28: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BFC2C: lw          $t0, 0x454($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X454);
    // 0x800BFC30: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BFC34: lw          $t2, 0x444($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X444);
    // 0x800BFC38: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFC3C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BFC40: sw          $t1, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r9;
    // 0x800BFC44: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFC48: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BFC4C: b           L_800BFDB0
    // 0x800BFC50: sw          $t3, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r11;
        goto L_800BFDB0;
    // 0x800BFC50: sw          $t3, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r11;
L_800BFC54:
    // 0x800BFC54: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFC58: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BFC5C: nop

    // 0x800BFC60: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BFC64: nop

    // 0x800BFC68: bgez        $t5, L_800BFC78
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BFC6C: sra         $t6, $t5, 4
        ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
            goto L_800BFC78;
    }
    // 0x800BFC6C: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800BFC70: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x800BFC74: sra         $t6, $at, 4
    ctx->r14 = S32(SIGNED(ctx->r1) >> 4);
L_800BFC78:
    // 0x800BFC78: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800BFC7C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800BFC80: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFC84: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFC88: nop

    // 0x800BFC8C: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFC90: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x800BFC94: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800BFC98: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800BFC9C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800BFCA0: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800BFCA4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800BFCA8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800BFCAC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFCB0: lw          $t6, 0x444($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X444);
    // 0x800BFCB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFCB8: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800BFCBC: sw          $t7, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r15;
    // 0x800BFCC0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BFCC4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800BFCC8: bne         $t9, $at, L_800BFD4C
    if (ctx->r25 != ctx->r1) {
        // 0x800BFCCC: nop
    
            goto L_800BFD4C;
    }
    // 0x800BFCCC: nop

L_800BFCD0:
    // 0x800BFCD0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFCD4: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFCD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800BFCDC: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFCE0: nop

    // 0x800BFCE4: bne         $t1, $at, L_800BFD14
    if (ctx->r9 != ctx->r1) {
        // 0x800BFCE8: nop
    
            goto L_800BFD14;
    }
    // 0x800BFCE8: nop

    // 0x800BFCEC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BFCF0: nop

    // 0x800BFCF4: addiu       $t0, $t2, 0xFF
    ctx->r8 = ADD32(ctx->r10, 0XFF);
    // 0x800BFCF8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800BFCFC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFD00: lw          $t3, 0x444($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X444);
    // 0x800BFD04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFD08: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800BFD0C: b           L_800BFD44
    // 0x800BFD10: sw          $t4, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r12;
        goto L_800BFD44;
    // 0x800BFD10: sw          $t4, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r12;
L_800BFD14:
    // 0x800BFD14: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFD18: lw          $t6, 0x444($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X444);
    // 0x800BFD1C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD20: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BFD24: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFD28: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800BFD2C: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x800BFD30: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x800BFD34: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BFD38: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BFD3C: b           L_800BFD4C
    // 0x800BFD40: nop

        goto L_800BFD4C;
    // 0x800BFD40: nop

L_800BFD44:
    // 0x800BFD44: b           L_800BFCD0
    // 0x800BFD48: nop

        goto L_800BFCD0;
    // 0x800BFD48: nop

L_800BFD4C:
    // 0x800BFD4C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD50: nop

    // 0x800BFD54: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x800BFD58: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800BFD5C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD60: nop

    // 0x800BFD64: blez        $t3, L_800BFDB0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BFD68: nop
    
            goto L_800BFDB0;
    }
    // 0x800BFD68: nop

L_800BFD6C:
    // 0x800BFD6C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFD70: lw          $t4, 0x454($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X454);
    // 0x800BFD74: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800BFD78: nop

    // 0x800BFD7C: subu        $t5, $t4, $t7
    ctx->r13 = SUB32(ctx->r12, ctx->r15);
    // 0x800BFD80: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x800BFD84: nop

    // 0x800BFD88: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x800BFD8C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFD90: lw          $t1, 0x454($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X454);
    // 0x800BFD94: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BFD98: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFD9C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BFDA0: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800BFDA4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800BFDA8: bgtz        $t6, L_800BFD6C
    if (SIGNED(ctx->r14) > 0) {
        // 0x800BFDAC: sw          $t2, 0x454($at)
        MEM_W(0X454, ctx->r1) = ctx->r10;
            goto L_800BFD6C;
    }
    // 0x800BFDAC: sw          $t2, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r10;
L_800BFDB0:
    // 0x800BFDB0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFDB4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFDB8: lw          $t3, 0x46C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X46C);
    // 0x800BFDBC: lw          $t0, 0x454($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X454);
    // 0x800BFDC0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BFDC4: lw          $t5, 0x494($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X494);
    // 0x800BFDC8: subu        $t7, $t0, $t3
    ctx->r15 = SUB32(ctx->r8, ctx->r11);
    // 0x800BFDCC: sltu        $at, $t7, $t5
    ctx->r1 = ctx->r15 < ctx->r13 ? 1 : 0;
    // 0x800BFDD0: bne         $at, $zero, L_800BFC00
    if (ctx->r1 != 0) {
        // 0x800BFDD4: nop
    
            goto L_800BFC00;
    }
    // 0x800BFDD4: nop

L_800BFDD8:
    // 0x800BFDD8: b           L_800C008C
    // 0x800BFDDC: nop

        goto L_800C008C;
    // 0x800BFDDC: nop

L_800BFDE0:
    // 0x800BFDE0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFDE4: addiu       $t9, $t9, 0x490
    ctx->r25 = ADD32(ctx->r25, 0X490);
    // 0x800BFDE8: lbu         $t4, 0x3($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X3);
    // 0x800BFDEC: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x800BFDF0: bne         $t4, $at, L_800C006C
    if (ctx->r12 != ctx->r1) {
        // 0x800BFDF4: nop
    
            goto L_800C006C;
    }
    // 0x800BFDF4: nop

    // 0x800BFDF8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFDFC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFE00: lw          $t1, 0x46C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X46C);
    // 0x800BFE04: lw          $t8, 0x454($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X454);
    // 0x800BFE08: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFE0C: lw          $t6, 0x494($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X494);
    // 0x800BFE10: subu        $t2, $t8, $t1
    ctx->r10 = SUB32(ctx->r24, ctx->r9);
    // 0x800BFE14: sltu        $at, $t2, $t6
    ctx->r1 = ctx->r10 < ctx->r14 ? 1 : 0;
    // 0x800BFE18: beq         $at, $zero, L_800C0064
    if (ctx->r1 == 0) {
        // 0x800BFE1C: nop
    
            goto L_800C0064;
    }
    // 0x800BFE1C: nop

L_800BFE20:
    // 0x800BFE20: jal         0x800C0328
    // 0x800BFE24: nop

    func_800C0328(rdram, ctx);
        goto after_1;
    // 0x800BFE24: nop

    after_1:
    // 0x800BFE28: beq         $v0, $zero, L_800BFEE0
    if (ctx->r2 == 0) {
        // 0x800BFE2C: nop
    
            goto L_800BFEE0;
    }
    // 0x800BFE2C: nop

    // 0x800BFE30: jal         0x800C0328
    // 0x800BFE34: nop

    func_800C0328(rdram, ctx);
        goto after_2;
    // 0x800BFE34: nop

    after_2:
    // 0x800BFE38: beq         $v0, $zero, L_800BFEA4
    if (ctx->r2 == 0) {
        // 0x800BFE3C: nop
    
            goto L_800BFEA4;
    }
    // 0x800BFE3C: nop

    // 0x800BFE40: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFE44: lw          $t0, 0x444($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X444);
    // 0x800BFE48: nop

    // 0x800BFE4C: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x800BFE50: nop

    // 0x800BFE54: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x800BFE58: jal         0x800C055C
    // 0x800BFE5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800C055C(rdram, ctx);
        goto after_3;
    // 0x800BFE5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_3:
    // 0x800BFE60: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFE64: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFE68: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFE6C: lw          $t9, 0x454($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X454);
    // 0x800BFE70: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x800BFE74: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BFE78: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
    // 0x800BFE7C: lw          $t4, 0x454($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X454);
    // 0x800BFE80: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BFE84: lw          $t1, 0x444($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X444);
    // 0x800BFE88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFE8C: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x800BFE90: sw          $t8, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r24;
    // 0x800BFE94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFE98: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BFE9C: b           L_800BFED8
    // 0x800BFEA0: sw          $t2, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r10;
        goto L_800BFED8;
    // 0x800BFEA0: sw          $t2, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r10;
L_800BFEA4:
    // 0x800BFEA4: jal         0x800C01D4
    // 0x800BFEA8: nop

    func_800C01D4(rdram, ctx);
        goto after_4;
    // 0x800BFEA8: nop

    after_4:
    // 0x800BFEAC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800BFEB0: jal         0x800C0534
    // 0x800BFEB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C0534(rdram, ctx);
        goto after_5;
    // 0x800BFEB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800BFEB8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800BFEBC: lw          $t6, 0x454($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X454);
    // 0x800BFEC0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BFEC4: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800BFEC8: lw          $t0, 0x454($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X454);
    // 0x800BFECC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFED0: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800BFED4: sw          $t3, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r11;
L_800BFED8:
    // 0x800BFED8: b           L_800C003C
    // 0x800BFEDC: nop

        goto L_800C003C;
    // 0x800BFEDC: nop

L_800BFEE0:
    // 0x800BFEE0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFEE4: lw          $t7, 0x444($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X444);
    // 0x800BFEE8: nop

    // 0x800BFEEC: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x800BFEF0: nop

    // 0x800BFEF4: bgez        $t5, L_800BFF04
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800BFEF8: sra         $t9, $t5, 4
        ctx->r25 = S32(SIGNED(ctx->r13) >> 4);
            goto L_800BFF04;
    }
    // 0x800BFEF8: sra         $t9, $t5, 4
    ctx->r25 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800BFEFC: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x800BFF00: sra         $t9, $at, 4
    ctx->r25 = S32(SIGNED(ctx->r1) >> 4);
L_800BFF04:
    // 0x800BFF04: andi        $t4, $t9, 0xF
    ctx->r12 = ctx->r25 & 0XF;
    // 0x800BFF08: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800BFF0C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFF10: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFF14: nop

    // 0x800BFF18: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFF1C: lbu         $t1, 0x1($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X1);
    // 0x800BFF20: andi        $t0, $t6, 0xF
    ctx->r8 = ctx->r14 & 0XF;
    // 0x800BFF24: sll         $t3, $t0, 8
    ctx->r11 = S32(ctx->r8 << 8);
    // 0x800BFF28: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800BFF2C: addu        $t7, $t2, $t3
    ctx->r15 = ADD32(ctx->r10, ctx->r11);
    // 0x800BFF30: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x800BFF34: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800BFF38: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFF3C: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BFF40: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFF44: addiu       $t4, $t9, 0x2
    ctx->r12 = ADD32(ctx->r25, 0X2);
    // 0x800BFF48: sw          $t4, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r12;
    // 0x800BFF4C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800BFF50: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800BFF54: bne         $t1, $at, L_800BFFD8
    if (ctx->r9 != ctx->r1) {
        // 0x800BFF58: nop
    
            goto L_800BFFD8;
    }
    // 0x800BFF58: nop

L_800BFF5C:
    // 0x800BFF5C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BFF60: lw          $t8, 0x444($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X444);
    // 0x800BFF64: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800BFF68: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800BFF6C: nop

    // 0x800BFF70: bne         $t6, $at, L_800BFFA0
    if (ctx->r14 != ctx->r1) {
        // 0x800BFF74: nop
    
            goto L_800BFFA0;
    }
    // 0x800BFF74: nop

    // 0x800BFF78: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BFF7C: nop

    // 0x800BFF80: addiu       $t2, $t0, 0xFF
    ctx->r10 = ADD32(ctx->r8, 0XFF);
    // 0x800BFF84: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800BFF88: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BFF8C: lw          $t3, 0x444($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X444);
    // 0x800BFF90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFF94: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x800BFF98: b           L_800BFFD0
    // 0x800BFF9C: sw          $t7, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r15;
        goto L_800BFFD0;
    // 0x800BFF9C: sw          $t7, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r15;
L_800BFFA0:
    // 0x800BFFA0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BFFA4: lw          $t9, 0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X444);
    // 0x800BFFA8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800BFFAC: lbu         $t4, 0x0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X0);
    // 0x800BFFB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BFFB4: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800BFFB8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BFFBC: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x800BFFC0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800BFFC4: sw          $t6, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r14;
    // 0x800BFFC8: b           L_800BFFD8
    // 0x800BFFCC: nop

        goto L_800BFFD8;
    // 0x800BFFCC: nop

L_800BFFD0:
    // 0x800BFFD0: b           L_800BFF5C
    // 0x800BFFD4: nop

        goto L_800BFF5C;
    // 0x800BFFD4: nop

L_800BFFD8:
    // 0x800BFFD8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BFFDC: nop

    // 0x800BFFE0: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x800BFFE4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800BFFE8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800BFFEC: nop

    // 0x800BFFF0: blez        $t3, L_800C003C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BFFF4: nop
    
            goto L_800C003C;
    }
    // 0x800BFFF4: nop

L_800BFFF8:
    // 0x800BFFF8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BFFFC: lw          $t7, 0x454($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X454);
    // 0x800C0000: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0004: nop

    // 0x800C0008: subu        $t5, $t7, $t4
    ctx->r13 = SUB32(ctx->r15, ctx->r12);
    // 0x800C000C: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x800C0010: nop

    // 0x800C0014: sb          $t1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r9;
    // 0x800C0018: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C001C: lw          $t6, 0x454($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X454);
    // 0x800C0020: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C0024: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0028: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x800C002C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C0030: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800C0034: bgtz        $t9, L_800BFFF8
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C0038: sw          $t0, 0x454($at)
        MEM_W(0X454, ctx->r1) = ctx->r8;
            goto L_800BFFF8;
    }
    // 0x800C0038: sw          $t0, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r8;
L_800C003C:
    // 0x800C003C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800C0040: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800C0044: lw          $t3, 0x46C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X46C);
    // 0x800C0048: lw          $t2, 0x454($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X454);
    // 0x800C004C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800C0050: lw          $t5, 0x494($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X494);
    // 0x800C0054: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800C0058: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x800C005C: bne         $at, $zero, L_800BFE20
    if (ctx->r1 != 0) {
        // 0x800C0060: nop
    
            goto L_800BFE20;
    }
    // 0x800C0060: nop

L_800C0064:
    // 0x800C0064: b           L_800C008C
    // 0x800C0068: nop

        goto L_800C008C;
    // 0x800C0068: nop

L_800C006C:
    // 0x800C006C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800C0070: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800C0074: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800C0078: lw          $a2, 0x494($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X494);
    // 0x800C007C: lw          $a1, 0x434($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X434);
    // 0x800C0080: lw          $a0, 0x454($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X454);
    // 0x800C0084: jal         0x800BCFCC
    // 0x800C0088: nop

    SysMem_Copy8(rdram, ctx);
        goto after_6;
    // 0x800C0088: nop

    after_6:
L_800C008C:
    // 0x800C008C: b           L_800C0094
    // 0x800C0090: nop

        goto L_800C0094;
    // 0x800C0090: nop

L_800C0094:
    // 0x800C0094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C009C: jr          $ra
    // 0x800C00A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C00A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80087598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008759C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800875A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800875A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800875A8: jal         0x8008B4EC
    // 0x800875AC: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800875AC: nop

    after_0:
    // 0x800875B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800875B4: jal         0x8008B600
    // 0x800875B8: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800875B8: nop

    after_1:
    // 0x800875BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800875C0: jal         0x8008BA24
    // 0x800875C4: nop

    func_8008BA24(rdram, ctx);
        goto after_2;
    // 0x800875C4: nop

    after_2:
    // 0x800875C8: b           L_800875D0
    // 0x800875CC: nop

        goto L_800875D0;
    // 0x800875CC: nop

L_800875D0:
    // 0x800875D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800875D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800875D8: jr          $ra
    // 0x800875DC: nop

    return;
    // 0x800875DC: nop

;}
RECOMP_FUNC void func_80063708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063708: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006370C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063710: nop

    // 0x80063714: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80063718: nop

    // 0x8006371C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80063720: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063724: jr          $ra
    // 0x80063728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006372C: jr          $ra
    // 0x80063730: nop

    return;
    // 0x80063730: nop

    // 0x80063734: jr          $ra
    // 0x80063738: nop

    return;
    // 0x80063738: nop

;}
RECOMP_FUNC void func_800723B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800723B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800723B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800723B8: jal         0x80061488
    // 0x800723BC: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800723BC: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x800723C0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800723C4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800723C8: b           L_800723D8
    // 0x800723CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800723D8;
    // 0x800723CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800723D0: b           L_800723D8
    // 0x800723D4: nop

        goto L_800723D8;
    // 0x800723D4: nop

L_800723D8:
    // 0x800723D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800723DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800723E0: jr          $ra
    // 0x800723E4: nop

    return;
    // 0x800723E4: nop

;}
RECOMP_FUNC void func_8006C850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C858: jal         0x8005F064
    // 0x8006C85C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C85C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x8006C860: b           L_8006C870
    // 0x8006C864: nop

        goto L_8006C870;
    // 0x8006C864: nop

    // 0x8006C868: b           L_8006C870
    // 0x8006C86C: nop

        goto L_8006C870;
    // 0x8006C86C: nop

L_8006C870:
    // 0x8006C870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C878: jr          $ra
    // 0x8006C87C: nop

    return;
    // 0x8006C87C: nop

;}
RECOMP_FUNC void func_80073824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007382C: jal         0x80061488
    // 0x80073830: addiu       $a0, $zero, 0x538
    ctx->r4 = ADD32(0, 0X538);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073830: addiu       $a0, $zero, 0x538
    ctx->r4 = ADD32(0, 0X538);
    after_0:
    // 0x80073834: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80073838: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007383C: b           L_8007384C
    // 0x80073840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007384C;
    // 0x80073840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073844: b           L_8007384C
    // 0x80073848: nop

        goto L_8007384C;
    // 0x80073848: nop

L_8007384C:
    // 0x8007384C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073854: jr          $ra
    // 0x80073858: nop

    return;
    // 0x80073858: nop

;}
RECOMP_FUNC void alSynStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3CA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D3CAC: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D3CB0: beql        $t6, $zero, L_800D3D0C
    if (ctx->r14 == 0) {
        // 0x800D3CB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3D0C;
    }
    goto skip_0;
    // 0x800D3CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3CB8: jal         0x800C7C00
    // 0x800D3CBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3CBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D3CC0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3CC4: beq         $v0, $zero, L_800D3D08
    if (ctx->r2 == 0) {
        // 0x800D3CC8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D3D08;
    }
    // 0x800D3CC8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3CCC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D3CD0: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D3CD4: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800D3CD8: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D3CDC: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D3CE0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D3CE4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D3CE8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D3CEC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D3CF0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D3CF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3CF8: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D3CFC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3D00: jalr        $t9
    // 0x800D3D04: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D3D04: nop

    after_1:
L_800D3D08:
    // 0x800D3D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3D0C:
    // 0x800D3D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3D10: jr          $ra
    // 0x800D3D14: nop

    return;
    // 0x800D3D14: nop

;}
RECOMP_FUNC void func_8006F474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F474: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F478: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F47C: nop

    // 0x8006F480: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F484: nop

    // 0x8006F488: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F48C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F490: jr          $ra
    // 0x8006F494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F498: jr          $ra
    // 0x8006F49C: nop

    return;
    // 0x8006F49C: nop

    // 0x8006F4A0: jr          $ra
    // 0x8006F4A4: nop

    return;
    // 0x8006F4A4: nop

;}
RECOMP_FUNC void Scheduler_CreateScheduler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80096EEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80096EF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80096EF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80096EF8: nop

    // 0x80096EFC: sw          $zero, 0x294($t6)
    MEM_W(0X294, ctx->r14) = 0;
    // 0x80096F00: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80096F04: nop

    // 0x80096F08: sw          $zero, 0x298($t7)
    MEM_W(0X298, ctx->r15) = 0;
    // 0x80096F0C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80096F10: nop

    // 0x80096F14: sw          $zero, 0x280($t8)
    MEM_W(0X280, ctx->r24) = 0;
    // 0x80096F18: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80096F1C: nop

    // 0x80096F20: sw          $zero, 0x29C($t9)
    MEM_W(0X29C, ctx->r25) = 0;
    // 0x80096F24: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80096F28: nop

    // 0x80096F2C: sw          $zero, 0x2A0($t0)
    MEM_W(0X2A0, ctx->r8) = 0;
    // 0x80096F30: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80096F34: nop

    // 0x80096F38: sw          $zero, 0x284($t1)
    MEM_W(0X284, ctx->r9) = 0;
    // 0x80096F3C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80096F40: nop

    // 0x80096F44: sw          $zero, 0x288($t2)
    MEM_W(0X288, ctx->r10) = 0;
    // 0x80096F48: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80096F4C: nop

    // 0x80096F50: sw          $zero, 0x28C($t3)
    MEM_W(0X28C, ctx->r11) = 0;
    // 0x80096F54: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80096F58: nop

    // 0x80096F5C: sw          $zero, 0x290($t4)
    MEM_W(0X290, ctx->r12) = 0;
    // 0x80096F60: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80096F64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80096F68: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80096F6C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80096F70: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80096F74: sh          $t7, 0x20($t8)
    MEM_H(0X20, ctx->r24) = ctx->r15;
    // 0x80096F78: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80096F7C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80096F80: sh          $t9, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r25;
    // 0x80096F84: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80096F88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80096F8C: sh          $t1, 0x72F0($at)
    MEM_H(0X72F0, ctx->r1) = ctx->r9;
    // 0x80096F90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80096F94: sw          $zero, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = 0;
    // 0x80096F98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80096F9C: sw          $zero, 0x72CC($at)
    MEM_W(0X72CC, ctx->r1) = 0;
    // 0x80096FA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80096FA4: sw          $zero, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = 0;
    // 0x80096FA8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80096FAC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80096FB0: addiu       $a0, $t2, 0x60
    ctx->r4 = ADD32(ctx->r10, 0X60);
    // 0x80096FB4: jal         0x800C42B0
    // 0x80096FB8: addiu       $a1, $t2, 0x78
    ctx->r5 = ADD32(ctx->r10, 0X78);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80096FB8: addiu       $a1, $t2, 0x78
    ctx->r5 = ADD32(ctx->r10, 0X78);
    after_0:
    // 0x80096FBC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80096FC0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80096FC4: addiu       $a0, $t3, 0x98
    ctx->r4 = ADD32(ctx->r11, 0X98);
    // 0x80096FC8: jal         0x800C42B0
    // 0x80096FCC: addiu       $a1, $t3, 0xB0
    ctx->r5 = ADD32(ctx->r11, 0XB0);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80096FCC: addiu       $a1, $t3, 0xB0
    ctx->r5 = ADD32(ctx->r11, 0XB0);
    after_1:
    // 0x80096FD0: jal         0x800C42E0
    // 0x80096FD4: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_2;
    // 0x80096FD4: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_2:
    // 0x80096FD8: lbu         $t4, 0x1F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1F);
    // 0x80096FDC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80096FE0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80096FE4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80096FE8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80096FEC: addiu       $t6, $t6, -0x4130
    ctx->r14 = ADD32(ctx->r14, -0X4130);
    // 0x80096FF0: jal         0x800C4640
    // 0x80096FF4: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    osViSetMode_recomp(rdram, ctx);
        goto after_3;
    // 0x80096FF4: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_3:
    // 0x80096FF8: jal         0x800C46B0
    // 0x80096FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_4;
    // 0x80096FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80097000: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80097004: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80097008: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    // 0x8009700C: jal         0x800C4720
    // 0x80097010: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80097010: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    after_5:
    // 0x80097014: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80097018: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8009701C: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    // 0x80097020: jal         0x800C4720
    // 0x80097024: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80097024: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    after_6:
    // 0x80097028: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8009702C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80097030: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    // 0x80097034: jal         0x800C4720
    // 0x80097038: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80097038: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    after_7:
    // 0x8009703C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097040: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x80097044: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x80097048: jal         0x800C4790
    // 0x8009704C: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    osViSetEvent_recomp(rdram, ctx);
        goto after_8;
    // 0x8009704C: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    after_8:
    // 0x80097050: b           L_80097058
    // 0x80097054: nop

        goto L_80097058;
    // 0x80097054: nop

L_80097058:
    // 0x80097058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009705C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097060: jr          $ra
    // 0x80097064: nop

    return;
    // 0x80097064: nop

;}
RECOMP_FUNC void func_8008C34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C34C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C354: jal         0x800AE398
    // 0x8008C358: nop

    ContPak_GetPakInitilizationResult(rdram, ctx);
        goto after_0;
    // 0x8008C358: nop

    after_0:
    // 0x8008C35C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008C360: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C364: nop

    // 0x8008C368: bne         $t6, $zero, L_8008C3B0
    if (ctx->r14 != 0) {
        // 0x8008C36C: nop
    
            goto L_8008C3B0;
    }
    // 0x8008C36C: nop

    // 0x8008C370: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008C374: lw          $t7, 0x1350($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1350);
    // 0x8008C378: nop

    // 0x8008C37C: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8008C380: beq         $t8, $zero, L_8008C3A8
    if (ctx->r24 == 0) {
        // 0x8008C384: nop
    
            goto L_8008C3A8;
    }
    // 0x8008C384: nop

    // 0x8008C388: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008C38C: lw          $t9, 0x129C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X129C);
    // 0x8008C390: nop

    // 0x8008C394: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8008C398: beq         $t0, $zero, L_8008C3A8
    if (ctx->r8 == 0) {
        // 0x8008C39C: nop
    
            goto L_8008C3A8;
    }
    // 0x8008C39C: nop

    // 0x8008C3A0: b           L_8008C3C4
    // 0x8008C3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C3C4;
    // 0x8008C3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C3A8:
    // 0x8008C3A8: b           L_8008C3C4
    // 0x8008C3AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008C3C4;
    // 0x8008C3AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008C3B0:
    // 0x8008C3B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C3B4: b           L_8008C3C4
    // 0x8008C3B8: nop

        goto L_8008C3C4;
    // 0x8008C3B8: nop

    // 0x8008C3BC: b           L_8008C3C4
    // 0x8008C3C0: nop

        goto L_8008C3C4;
    // 0x8008C3C0: nop

L_8008C3C4:
    // 0x8008C3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C3C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008C3CC: jr          $ra
    // 0x8008C3D0: nop

    return;
    // 0x8008C3D0: nop

;}
RECOMP_FUNC void func_80083EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083EB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80083EB8: sh          $zero, 0x7A10($at)
    MEM_H(0X7A10, ctx->r1) = 0;
    // 0x80083EBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80083EC0: sh          $zero, 0x7A12($at)
    MEM_H(0X7A12, ctx->r1) = 0;
    // 0x80083EC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80083EC8: sh          $zero, 0x7A14($at)
    MEM_H(0X7A14, ctx->r1) = 0;
    // 0x80083ECC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80083ED0:
    // 0x80083ED0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80083ED4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083ED8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80083EDC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80083EE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80083EE4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80083EE8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80083EEC: addiu       $t8, $t8, 0x7AE8
    ctx->r24 = ADD32(ctx->r24, 0X7AE8);
    // 0x80083EF0: jal         0x8008C0D8
    // 0x80083EF4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_8008C0D8(rdram, ctx);
        goto after_0;
    // 0x80083EF4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80083EF8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80083EFC: nop

    // 0x80083F00: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80083F04: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80083F08: bne         $at, $zero, L_80083ED0
    if (ctx->r1 != 0) {
        // 0x80083F0C: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_80083ED0;
    }
    // 0x80083F0C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80083F10: b           L_80083F18
    // 0x80083F14: nop

        goto L_80083F18;
    // 0x80083F14: nop

L_80083F18:
    // 0x80083F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083F1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083F20: jr          $ra
    // 0x80083F24: nop

    return;
    // 0x80083F24: nop

;}
RECOMP_FUNC void func_80012798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012798: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001279C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800127A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800127A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800127A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800127AC: jal         0x8000DA44
    // 0x800127B0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800127B0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800127B4: bgez        $v0, L_800127C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800127B8: nop
    
            goto L_800127C4;
    }
    // 0x800127B8: nop

    // 0x800127BC: b           L_8001291C
    // 0x800127C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001291C;
    // 0x800127C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800127C4:
    // 0x800127C4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800127C8: nop

    // 0x800127CC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800127D0: nop

    // 0x800127D4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800127D8: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800127DC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800127E0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800127E4: nop

    // 0x800127E8: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x800127EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800127F0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800127F4: nop

    // 0x800127F8: swc1        $f4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f4.u32l;
    // 0x800127FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80012800: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80012804: nop

    // 0x80012808: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
    // 0x8001280C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80012810: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80012814: nop

    // 0x80012818: swc1        $f8, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f8.u32l;
    // 0x8001281C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80012820: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80012824: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80012828: nop

    // 0x8001282C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80012830: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80012834: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80012838: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8001283C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80012840: nop

    // 0x80012844: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80012848: lhu         $t9, 0x6($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X6);
    // 0x8001284C: nop

    // 0x80012850: blez        $t9, L_8001290C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80012854: nop
    
            goto L_8001290C;
    }
    // 0x80012854: nop

L_80012858:
    // 0x80012858: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x8001285C: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80012860: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80012864: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80012868: nop

    // 0x8001286C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80012870: swc1        $f16, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f16.u32l;
    // 0x80012874: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x80012878: lh          $t5, 0x6($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X6);
    // 0x8001287C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80012880: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80012884: nop

    // 0x80012888: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001288C: swc1        $f4, 0xEC($t6)
    MEM_W(0XEC, ctx->r14) = ctx->f4.u32l;
    // 0x80012890: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x80012894: lh          $t8, 0x8($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X8);
    // 0x80012898: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8001289C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800128A0: nop

    // 0x800128A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800128A8: swc1        $f8, 0xF0($t7)
    MEM_W(0XF0, ctx->r15) = ctx->f8.u32l;
    // 0x800128AC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800128B0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800128B4: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800128B8: nop

    // 0x800128BC: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800128C0: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
    // 0x800128C4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800128C8: nop

    // 0x800128CC: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800128D0: nop

    // 0x800128D4: ori         $t5, $t3, 0x10
    ctx->r13 = ctx->r11 | 0X10;
    // 0x800128D8: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
    // 0x800128DC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800128E0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800128E4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800128E8: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x800128EC: addiu       $t7, $t8, 0x160
    ctx->r15 = ADD32(ctx->r24, 0X160);
    // 0x800128F0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800128F4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800128F8: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x800128FC: nop

    // 0x80012900: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80012904: bne         $at, $zero, L_80012858
    if (ctx->r1 != 0) {
        // 0x80012908: nop
    
            goto L_80012858;
    }
    // 0x80012908: nop

L_8001290C:
    // 0x8001290C: b           L_8001291C
    // 0x80012910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001291C;
    // 0x80012910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012914: b           L_8001291C
    // 0x80012918: nop

        goto L_8001291C;
    // 0x80012918: nop

L_8001291C:
    // 0x8001291C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012920: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80012924: jr          $ra
    // 0x80012928: nop

    return;
    // 0x80012928: nop

;}
RECOMP_FUNC void func_800681F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800681F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800681FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068200: nop

    // 0x80068204: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80068208: nop

    // 0x8006820C: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80068210: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068214: jr          $ra
    // 0x80068218: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068218: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006821C: jr          $ra
    // 0x80068220: nop

    return;
    // 0x80068220: nop

    // 0x80068224: jr          $ra
    // 0x80068228: nop

    return;
    // 0x80068228: nop

;}
RECOMP_FUNC void func_800AD7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD7E4: jr          $ra
    // 0x800AD7E8: nop

    return;
    // 0x800AD7E8: nop

    // 0x800AD7EC: jr          $ra
    // 0x800AD7F0: nop

    return;
    // 0x800AD7F0: nop

    // 0x800AD7F4: nop

    // 0x800AD7F8: nop

    // 0x800AD7FC: nop

;}
RECOMP_FUNC void func_800B5AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5AA0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5AA4: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5AA8: nop

    // 0x800B5AAC: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B5AB0: nop

    // 0x800B5AB4: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x800B5AB8: beq         $t8, $zero, L_800B5AE0
    if (ctx->r24 == 0) {
        // 0x800B5ABC: nop
    
            goto L_800B5AE0;
    }
    // 0x800B5ABC: nop

    // 0x800B5AC0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800B5AC4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B5AC8: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x800B5ACC: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x800B5AD0: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x800B5AD4: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x800B5AD8: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x800B5ADC: sh          $t3, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r11;
L_800B5AE0:
    // 0x800B5AE0: jr          $ra
    // 0x800B5AE4: nop

    return;
    // 0x800B5AE4: nop

    // 0x800B5AE8: jr          $ra
    // 0x800B5AEC: nop

    return;
    // 0x800B5AEC: nop

;}
RECOMP_FUNC void func_80063C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063C7C: jal         0x8005F064
    // 0x80063C80: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063C80: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x80063C84: b           L_80063C94
    // 0x80063C88: nop

        goto L_80063C94;
    // 0x80063C88: nop

    // 0x80063C8C: b           L_80063C94
    // 0x80063C90: nop

        goto L_80063C94;
    // 0x80063C90: nop

L_80063C94:
    // 0x80063C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C9C: jr          $ra
    // 0x80063CA0: nop

    return;
    // 0x80063CA0: nop

;}
RECOMP_FUNC void func_8002BB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BB04: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BB08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BB0C: slti        $at, $a0, 0x2A
    ctx->r1 = SIGNED(ctx->r4) < 0X2A ? 1 : 0;
    // 0x8002BB10: bne         $at, $zero, L_8002BB28
    if (ctx->r1 != 0) {
        // 0x8002BB14: nop
    
            goto L_8002BB28;
    }
    // 0x8002BB14: nop

    // 0x8002BB18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002BB1C: lwc1        $f0, -0x1910($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1910);
    // 0x8002BB20: jr          $ra
    // 0x8002BB24: nop

    return;
    // 0x8002BB24: nop

L_8002BB28:
    // 0x8002BB28: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BB2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002BB30: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002BB34: lwc1        $f0, -0x46C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X46C8);
    // 0x8002BB38: jr          $ra
    // 0x8002BB3C: nop

    return;
    // 0x8002BB3C: nop

    // 0x8002BB40: jr          $ra
    // 0x8002BB44: nop

    return;
    // 0x8002BB44: nop

    // 0x8002BB48: jr          $ra
    // 0x8002BB4C: nop

    return;
    // 0x8002BB4C: nop

;}
RECOMP_FUNC void func_800B7DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7DCC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B7DD0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B7DD4:
    // 0x800B7DD4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800B7DD8: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7DDC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B7DE0: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B7DE4: sh          $t6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r14;
    // 0x800B7DE8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7DEC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800B7DF0: nop

    // 0x800B7DF4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B7DF8: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x800B7DFC: bne         $at, $zero, L_800B7DD4
    if (ctx->r1 != 0) {
        // 0x800B7E00: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800B7DD4;
    }
    // 0x800B7E00: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800B7E04: addiu       $t2, $sp, 0x8
    ctx->r10 = ADD32(ctx->r29, 0X8);
    // 0x800B7E08: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800B7E0C: nop

    // 0x800B7E10: bne         $t3, $zero, L_800B7E54
    if (ctx->r11 != 0) {
        // 0x800B7E14: nop
    
            goto L_800B7E54;
    }
    // 0x800B7E14: nop

    // 0x800B7E18: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B7E1C: lw          $t5, -0x794($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X794);
    // 0x800B7E20: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B7E24: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B7E28: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800B7E2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B7E30: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800B7E34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B7E38: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x800B7E3C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800B7E40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B7E44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B7E48: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800B7E4C: b           L_800B7E84
    // 0x800B7E50: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
        goto L_800B7E84;
    // 0x800B7E50: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
L_800B7E54:
    // 0x800B7E54: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B7E58: lw          $t9, -0x794($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X794);
    // 0x800B7E5C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B7E60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800B7E64: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800B7E68: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800B7E6C: lw          $t8, 0x718C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X718C);
    // 0x800B7E70: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B7E74: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800B7E78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B7E7C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800B7E80: sw          $t1, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r9;
L_800B7E84:
    // 0x800B7E84: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B7E88: sw          $zero, -0x794($at)
    MEM_W(-0X794, ctx->r1) = 0;
    // 0x800B7E8C: b           L_800B7E9C
    // 0x800B7E90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B7E9C;
    // 0x800B7E90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7E94: b           L_800B7E9C
    // 0x800B7E98: nop

        goto L_800B7E9C;
    // 0x800B7E98: nop

L_800B7E9C:
    // 0x800B7E9C: jr          $ra
    // 0x800B7EA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B7EA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005D07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D07C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005D080: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8005D084: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8005D088: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005D08C: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8005D090: nop

    // 0x8005D094: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005D098: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8005D09C: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005D0A0: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8005D0A4: nop

    // 0x8005D0A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005D0AC: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x8005D0B0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8005D0B4: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x8005D0B8: nop

    // 0x8005D0BC: blez        $t6, L_8005D138
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005D0C0: nop
    
            goto L_8005D138;
    }
    // 0x8005D0C0: nop

L_8005D0C4:
    // 0x8005D0C4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005D0C8: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8005D0CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005D0D0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005D0D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005D0D8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005D0DC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005D0E0: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8005D0E4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8005D0E8: swc1        $f4, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f4.u32l;
    // 0x8005D0EC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005D0F0: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8005D0F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005D0F8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005D0FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005D100: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005D104: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005D108: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8005D10C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005D110: swc1        $f6, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f6.u32l;
    // 0x8005D114: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005D118: nop

    // 0x8005D11C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005D120: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8005D124: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x8005D128: nop

    // 0x8005D12C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8005D130: bne         $at, $zero, L_8005D0C4
    if (ctx->r1 != 0) {
        // 0x8005D134: nop
    
            goto L_8005D0C4;
    }
    // 0x8005D134: nop

L_8005D138:
    // 0x8005D138: b           L_8005D140
    // 0x8005D13C: nop

        goto L_8005D140;
    // 0x8005D13C: nop

L_8005D140:
    // 0x8005D140: jr          $ra
    // 0x8005D144: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005D144: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8005D148: nop

    // 0x8005D14C: nop

;}
RECOMP_FUNC void func_8006C6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C6C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C6C8: jal         0x8005F064
    // 0x8006C6CC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C6CC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_0:
    // 0x8006C6D0: b           L_8006C6E0
    // 0x8006C6D4: nop

        goto L_8006C6E0;
    // 0x8006C6D4: nop

    // 0x8006C6D8: b           L_8006C6E0
    // 0x8006C6DC: nop

        goto L_8006C6E0;
    // 0x8006C6DC: nop

L_8006C6E0:
    // 0x8006C6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C6E8: jr          $ra
    // 0x8006C6EC: nop

    return;
    // 0x8006C6EC: nop

;}
RECOMP_FUNC void func_80062908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006290C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062910: jal         0x8005F064
    // 0x80062914: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062914: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_0:
    // 0x80062918: b           L_80062928
    // 0x8006291C: nop

        goto L_80062928;
    // 0x8006291C: nop

    // 0x80062920: b           L_80062928
    // 0x80062924: nop

        goto L_80062928;
    // 0x80062924: nop

L_80062928:
    // 0x80062928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006292C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062930: jr          $ra
    // 0x80062934: nop

    return;
    // 0x80062934: nop

;}
RECOMP_FUNC void func_80066E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066EA0: jal         0x80061348
    // 0x80066EA4: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066EA4: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    after_0:
    // 0x80066EA8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066EAC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066EB0: b           L_80066EC0
    // 0x80066EB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066EC0;
    // 0x80066EB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066EB8: b           L_80066EC0
    // 0x80066EBC: nop

        goto L_80066EC0;
    // 0x80066EBC: nop

L_80066EC0:
    // 0x80066EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066EC8: jr          $ra
    // 0x80066ECC: nop

    return;
    // 0x80066ECC: nop

;}
RECOMP_FUNC void func_800B1CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1CD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B1CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1CDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B1CE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B1CE4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B1CE8: nop

    // 0x800B1CEC: beq         $t6, $zero, L_800B1D4C
    if (ctx->r14 == 0) {
        // 0x800B1CF0: nop
    
            goto L_800B1D4C;
    }
    // 0x800B1CF0: nop

    // 0x800B1CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B1CF8:
    // 0x800B1CF8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1CFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B1D00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B1D04: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B1D08: lw          $t1, 0x12C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X12C);
    // 0x800B1D0C: nop

    // 0x800B1D10: beq         $t1, $zero, L_800B1D34
    if (ctx->r9 == 0) {
        // 0x800B1D14: nop
    
            goto L_800B1D34;
    }
    // 0x800B1D14: nop

    // 0x800B1D18: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D1C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800B1D20: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B1D24: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800B1D28: lw          $a0, 0x12C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X12C);
    // 0x800B1D2C: jal         0x800BC980
    // 0x800B1D30: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800B1D30: nop

    after_0:
L_800B1D34:
    // 0x800B1D34: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D38: nop

    // 0x800B1D3C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800B1D40: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800B1D44: bne         $at, $zero, L_800B1CF8
    if (ctx->r1 != 0) {
        // 0x800B1D48: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800B1CF8;
    }
    // 0x800B1D48: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800B1D4C:
    // 0x800B1D4C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B1D50: nop

    // 0x800B1D54: bne         $t7, $zero, L_800B1D64
    if (ctx->r15 != 0) {
        // 0x800B1D58: nop
    
            goto L_800B1D64;
    }
    // 0x800B1D58: nop

    // 0x800B1D5C: b           L_800B1E48
    // 0x800B1D60: nop

        goto L_800B1E48;
    // 0x800B1D60: nop

L_800B1D64:
    // 0x800B1D64: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B1D68:
    // 0x800B1D68: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D6C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B1D70: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B1D74: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800B1D78: lw          $t2, 0x14($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X14);
    // 0x800B1D7C: nop

    // 0x800B1D80: beq         $t2, $zero, L_800B1DA4
    if (ctx->r10 == 0) {
        // 0x800B1D84: nop
    
            goto L_800B1DA4;
    }
    // 0x800B1D84: nop

    // 0x800B1D88: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D8C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B1D90: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B1D94: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800B1D98: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x800B1D9C: jal         0x800BC980
    // 0x800B1DA0: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800B1DA0: nop

    after_1:
L_800B1DA4:
    // 0x800B1DA4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1DA8: nop

    // 0x800B1DAC: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800B1DB0: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800B1DB4: bne         $at, $zero, L_800B1D68
    if (ctx->r1 != 0) {
        // 0x800B1DB8: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800B1D68;
    }
    // 0x800B1DB8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B1DBC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B1DC0: nop

    // 0x800B1DC4: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x800B1DC8: nop

    // 0x800B1DCC: beq         $t1, $zero, L_800B1DE8
    if (ctx->r9 == 0) {
        // 0x800B1DD0: nop
    
            goto L_800B1DE8;
    }
    // 0x800B1DD0: nop

    // 0x800B1DD4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B1DD8: nop

    // 0x800B1DDC: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B1DE0: jal         0x800BC980
    // 0x800B1DE4: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800B1DE4: nop

    after_2:
L_800B1DE8:
    // 0x800B1DE8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B1DEC: nop

    // 0x800B1DF0: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x800B1DF4: nop

    // 0x800B1DF8: beq         $t5, $zero, L_800B1E14
    if (ctx->r13 == 0) {
        // 0x800B1DFC: nop
    
            goto L_800B1E14;
    }
    // 0x800B1DFC: nop

    // 0x800B1E00: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B1E04: nop

    // 0x800B1E08: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x800B1E0C: jal         0x800BC980
    // 0x800B1E10: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800B1E10: nop

    after_3:
L_800B1E14:
    // 0x800B1E14: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B1E18: nop

    // 0x800B1E1C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800B1E20: nop

    // 0x800B1E24: beq         $t8, $zero, L_800B1E40
    if (ctx->r24 == 0) {
        // 0x800B1E28: nop
    
            goto L_800B1E40;
    }
    // 0x800B1E28: nop

    // 0x800B1E2C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B1E30: nop

    // 0x800B1E34: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x800B1E38: jal         0x800BC980
    // 0x800B1E3C: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x800B1E3C: nop

    after_4:
L_800B1E40:
    // 0x800B1E40: b           L_800B1E48
    // 0x800B1E44: nop

        goto L_800B1E48;
    // 0x800B1E44: nop

L_800B1E48:
    // 0x800B1E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B1E50: jr          $ra
    // 0x800B1E54: nop

    return;
    // 0x800B1E54: nop

;}
RECOMP_FUNC void func_80064364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006436C: jal         0x80061488
    // 0x80064370: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064370: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    after_0:
    // 0x80064374: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80064378: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006437C: b           L_8006438C
    // 0x80064380: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006438C;
    // 0x80064380: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064384: b           L_8006438C
    // 0x80064388: nop

        goto L_8006438C;
    // 0x80064388: nop

L_8006438C:
    // 0x8006438C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064394: jr          $ra
    // 0x80064398: nop

    return;
    // 0x80064398: nop

;}
RECOMP_FUNC void func_80062B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B80: jal         0x8005F064
    // 0x80062B84: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062B84: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062B88: b           L_80062B98
    // 0x80062B8C: nop

        goto L_80062B98;
    // 0x80062B8C: nop

    // 0x80062B90: b           L_80062B98
    // 0x80062B94: nop

        goto L_80062B98;
    // 0x80062B94: nop

L_80062B98:
    // 0x80062B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062BA0: jr          $ra
    // 0x80062BA4: nop

    return;
    // 0x80062BA4: nop

;}
RECOMP_FUNC void func_80087104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008710C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087114: jal         0x8008BFF4
    // 0x80087118: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x80087118: nop

    after_0:
    // 0x8008711C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80087120: nop

    // 0x80087124: sh          $zero, 0xC14($t6)
    MEM_H(0XC14, ctx->r14) = 0;
    // 0x80087128: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008712C: nop

    // 0x80087130: lh          $a1, 0xBE8($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XBE8);
    // 0x80087134: jal         0x8008C2E8
    // 0x80087138: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_1;
    // 0x80087138: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    after_1:
    // 0x8008713C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80087140: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087144: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80087148: jal         0x800AEA98
    // 0x8008714C: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_2;
    // 0x8008714C: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_2:
    // 0x80087150: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80087154: nop

    // 0x80087158: lh          $v0, 0x4($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X4);
    // 0x8008715C: b           L_8008716C
    // 0x80087160: nop

        goto L_8008716C;
    // 0x80087160: nop

    // 0x80087164: b           L_8008716C
    // 0x80087168: nop

        goto L_8008716C;
    // 0x80087168: nop

L_8008716C:
    // 0x8008716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087174: jr          $ra
    // 0x80087178: nop

    return;
    // 0x80087178: nop

;}
RECOMP_FUNC void func_800637F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800637F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800637FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063800: jal         0x80061488
    // 0x80063804: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063804: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    after_0:
    // 0x80063808: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006380C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063810: b           L_80063820
    // 0x80063814: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063820;
    // 0x80063814: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063818: b           L_80063820
    // 0x8006381C: nop

        goto L_80063820;
    // 0x8006381C: nop

L_80063820:
    // 0x80063820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063828: jr          $ra
    // 0x8006382C: nop

    return;
    // 0x8006382C: nop

;}
RECOMP_FUNC void func_80068404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068404: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068408: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006840C: nop

    // 0x80068410: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068414: nop

    // 0x80068418: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006841C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068420: jr          $ra
    // 0x80068424: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068424: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068428: jr          $ra
    // 0x8006842C: nop

    return;
    // 0x8006842C: nop

    // 0x80068430: jr          $ra
    // 0x80068434: nop

    return;
    // 0x80068434: nop

;}
RECOMP_FUNC void alSynStartVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D435C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D4360: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D4364: beql        $t6, $zero, L_800D43D0
    if (ctx->r14 == 0) {
        // 0x800D4368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D43D0;
    }
    goto skip_0;
    // 0x800D4368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D436C: jal         0x800C7C00
    // 0x800D4370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D4370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D4374: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4378: beq         $v0, $zero, L_800D43CC
    if (ctx->r2 == 0) {
        // 0x800D437C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D43CC;
    }
    // 0x800D437C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D4380: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D4384: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D4388: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x800D438C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D4390: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D4394: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D4398: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D439C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D43A0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D43A4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D43A8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D43AC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D43B0: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x800D43B4: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x800D43B8: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800D43BC: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800D43C0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D43C4: jalr        $t9
    // 0x800D43C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D43C8: nop

    after_1:
L_800D43CC:
    // 0x800D43CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D43D0:
    // 0x800D43D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D43D4: jr          $ra
    // 0x800D43D8: nop

    return;
    // 0x800D43D8: nop

;}
RECOMP_FUNC void func_80072BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072BAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072BB0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072BB4: nop

    // 0x80072BB8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072BBC: nop

    // 0x80072BC0: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x80072BC4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072BC8: jr          $ra
    // 0x80072BCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072BCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072BD0: jr          $ra
    // 0x80072BD4: nop

    return;
    // 0x80072BD4: nop

    // 0x80072BD8: jr          $ra
    // 0x80072BDC: nop

    return;
    // 0x80072BDC: nop

;}
RECOMP_FUNC void func_80062DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062DFC: jal         0x8005F064
    // 0x80062E00: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062E00: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_0:
    // 0x80062E04: b           L_80062E14
    // 0x80062E08: nop

        goto L_80062E14;
    // 0x80062E08: nop

    // 0x80062E0C: b           L_80062E14
    // 0x80062E10: nop

        goto L_80062E14;
    // 0x80062E10: nop

L_80062E14:
    // 0x80062E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062E1C: jr          $ra
    // 0x80062E20: nop

    return;
    // 0x80062E20: nop

;}
RECOMP_FUNC void func_80095F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095F9C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80095FA0: andi        $t6, $a0, 0xFF00
    ctx->r14 = ctx->r4 & 0XFF00;
    // 0x80095FA4: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x80095FA8: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80095FAC: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80095FB0: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80095FB4: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80095FB8: nop

    // 0x80095FBC: sltiu       $at, $t9, 0x80
    ctx->r1 = ctx->r25 < 0X80 ? 1 : 0;
    // 0x80095FC0: bne         $at, $zero, L_80095FD8
    if (ctx->r1 != 0) {
        // 0x80095FC4: nop
    
            goto L_80095FD8;
    }
    // 0x80095FC4: nop

    // 0x80095FC8: sltiu       $at, $t9, 0xFF
    ctx->r1 = ctx->r25 < 0XFF ? 1 : 0;
    // 0x80095FCC: beq         $at, $zero, L_80095FD8
    if (ctx->r1 == 0) {
        // 0x80095FD0: nop
    
            goto L_80095FD8;
    }
    // 0x80095FD0: nop

    // 0x80095FD4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80095FD8:
    // 0x80095FD8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80095FDC: nop

    // 0x80095FE0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80095FE4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80095FE8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80095FEC: subu        $a0, $a0, $t1
    ctx->r4 = SUB32(ctx->r4, ctx->r9);
    // 0x80095FF0: addiu       $a0, $a0, 0x2244
    ctx->r4 = ADD32(ctx->r4, 0X2244);
    // 0x80095FF4: b           L_80096004
    // 0x80095FF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80096004;
    // 0x80095FF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80095FFC: b           L_80096004
    // 0x80096000: nop

        goto L_80096004;
    // 0x80096000: nop

L_80096004:
    // 0x80096004: jr          $ra
    // 0x80096008: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80096008: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80076374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076374: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076378: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007637C: nop

    // 0x80076380: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076384: nop

    // 0x80076388: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007638C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076390: jr          $ra
    // 0x80076394: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076394: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076398: jr          $ra
    // 0x8007639C: nop

    return;
    // 0x8007639C: nop

    // 0x800763A0: jr          $ra
    // 0x800763A4: nop

    return;
    // 0x800763A4: nop

;}
RECOMP_FUNC void ContPak_InitializePak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE0EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE0F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE0F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AE0F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE0FC: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE100: nop

    // 0x800AE104: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AE108: beq         $t7, $zero, L_800AE118
    if (ctx->r15 == 0) {
        // 0x800AE10C: nop
    
            goto L_800AE118;
    }
    // 0x800AE10C: nop

    // 0x800AE110: b           L_800AE338
    // 0x800AE114: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE114: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE118:
    // 0x800AE118: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE11C: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE120: nop

    // 0x800AE124: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AE128: beq         $t9, $zero, L_800AE138
    if (ctx->r25 == 0) {
        // 0x800AE12C: nop
    
            goto L_800AE138;
    }
    // 0x800AE12C: nop

    // 0x800AE130: b           L_800AE338
    // 0x800AE134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE138:
    // 0x800AE138: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE13C: lw          $t0, 0x1690($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1690);
    // 0x800AE140: nop

    // 0x800AE144: bne         $t0, $zero, L_800AE15C
    if (ctx->r8 != 0) {
        // 0x800AE148: nop
    
            goto L_800AE15C;
    }
    // 0x800AE148: nop

    // 0x800AE14C: b           L_800AE338
    // 0x800AE150: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE150: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800AE154: b           L_800AE170
    // 0x800AE158: nop

        goto L_800AE170;
    // 0x800AE158: nop

L_800AE15C:
    // 0x800AE15C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE160: lw          $t1, 0x1690($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1690);
    // 0x800AE164: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE168: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800AE16C: sw          $t2, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r10;
L_800AE170:
    // 0x800AE170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AE174: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE178: jal         0x800C5FA0
    // 0x800AE17C: addiu       $a1, $a1, 0x2540
    ctx->r5 = ADD32(ctx->r5, 0X2540);
    osContReset_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE17C: addiu       $a1, $a1, 0x2540
    ctx->r5 = ADD32(ctx->r5, 0X2540);
    after_0:
    // 0x800AE180: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE184: addiu       $t3, $t3, 0x2540
    ctx->r11 = ADD32(ctx->r11, 0X2540);
    // 0x800AE188: lbu         $t4, 0x2($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X2);
    // 0x800AE18C: nop

    // 0x800AE190: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800AE194: bne         $t5, $zero, L_800AE1DC
    if (ctx->r13 != 0) {
        // 0x800AE198: nop
    
            goto L_800AE1DC;
    }
    // 0x800AE198: nop

    // 0x800AE19C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE1A0: lw          $t6, 0x1690($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1690);
    // 0x800AE1A4: nop

    // 0x800AE1A8: bne         $t6, $zero, L_800AE1CC
    if (ctx->r14 != 0) {
        // 0x800AE1AC: nop
    
            goto L_800AE1CC;
    }
    // 0x800AE1AC: nop

    // 0x800AE1B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AE1B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE1B8: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE1BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE1C0: sb          $zero, 0x127C($at)
    MEM_B(0X127C, ctx->r1) = 0;
    // 0x800AE1C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE1C8: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
L_800AE1CC:
    // 0x800AE1CC: b           L_800AE338
    // 0x800AE1D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE1D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800AE1D4: b           L_800AE22C
    // 0x800AE1D8: nop

        goto L_800AE22C;
    // 0x800AE1D8: nop

L_800AE1DC:
    // 0x800AE1DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AE1E0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE1E4: jal         0x800C6120
    // 0x800AE1E8: addiu       $a1, $a1, 0x127C
    ctx->r5 = ADD32(ctx->r5, 0X127C);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE1E8: addiu       $a1, $a1, 0x127C
    ctx->r5 = ADD32(ctx->r5, 0X127C);
    after_1:
    // 0x800AE1EC: bgez        $v0, L_800AE22C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AE1F0: nop
    
            goto L_800AE22C;
    }
    // 0x800AE1F0: nop

    // 0x800AE1F4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE1F8: lw          $t8, 0x1690($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1690);
    // 0x800AE1FC: nop

    // 0x800AE200: bne         $t8, $zero, L_800AE224
    if (ctx->r24 != 0) {
        // 0x800AE204: nop
    
            goto L_800AE224;
    }
    // 0x800AE204: nop

    // 0x800AE208: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AE20C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE210: sw          $t9, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r25;
    // 0x800AE214: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE218: sb          $zero, 0x127C($at)
    MEM_B(0X127C, ctx->r1) = 0;
    // 0x800AE21C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE220: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
L_800AE224:
    // 0x800AE224: b           L_800AE338
    // 0x800AE228: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE228: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE22C:
    // 0x800AE22C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE230: lbu         $t0, 0x127C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X127C);
    // 0x800AE234: nop

    // 0x800AE238: beq         $t0, $zero, L_800AE258
    if (ctx->r8 == 0) {
        // 0x800AE23C: nop
    
            goto L_800AE258;
    }
    // 0x800AE23C: nop

    // 0x800AE240: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE244: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE248: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE24C: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800AE250: b           L_800AE270
    // 0x800AE254: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
        goto L_800AE270;
    // 0x800AE254: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
L_800AE258:
    // 0x800AE258: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE25C: lw          $t3, 0x129C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X129C);
    // 0x800AE260: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800AE264: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800AE268: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE26C: sw          $t4, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r12;
L_800AE270:
    // 0x800AE270: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE274: lbu         $t5, 0x127C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X127C);
    // 0x800AE278: nop

    // 0x800AE27C: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x800AE280: beq         $t6, $zero, L_800AE2A0
    if (ctx->r14 == 0) {
        // 0x800AE284: nop
    
            goto L_800AE2A0;
    }
    // 0x800AE284: nop

    // 0x800AE288: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800AE28C: lw          $t7, 0x129C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X129C);
    // 0x800AE290: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE294: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x800AE298: b           L_800AE2B8
    // 0x800AE29C: sw          $t8, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r24;
        goto L_800AE2B8;
    // 0x800AE29C: sw          $t8, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r24;
L_800AE2A0:
    // 0x800AE2A0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800AE2A4: lw          $t9, 0x129C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X129C);
    // 0x800AE2A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800AE2AC: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800AE2B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE2B4: sw          $t0, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r8;
L_800AE2B8:
    // 0x800AE2B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE2BC: lbu         $t1, 0x127C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X127C);
    // 0x800AE2C0: nop

    // 0x800AE2C4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800AE2C8: beq         $t2, $zero, L_800AE2E4
    if (ctx->r10 == 0) {
        // 0x800AE2CC: nop
    
            goto L_800AE2E4;
    }
    // 0x800AE2CC: nop

    // 0x800AE2D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AE2D4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE2D8: addiu       $a1, $a1, 0x1360
    ctx->r5 = ADD32(ctx->r5, 0X1360);
    // 0x800AE2DC: jal         0x800C6490
    // 0x800AE2E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800AE2E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_800AE2E4:
    // 0x800AE2E4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800AE2E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE2EC: sw          $t3, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r11;
    // 0x800AE2F0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AE2F4: lw          $t4, 0x1350($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1350);
    // 0x800AE2F8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800AE2FC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AE300: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE304: sw          $t5, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r13;
    // 0x800AE308: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE30C: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x800AE310: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800AE314: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE31C: sw          $t7, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r15;
    // 0x800AE320: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE324: sw          $zero, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = 0;
    // 0x800AE328: b           L_800AE338
    // 0x800AE32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE338;
    // 0x800AE32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE330: b           L_800AE338
    // 0x800AE334: nop

        goto L_800AE338;
    // 0x800AE334: nop

L_800AE338:
    // 0x800AE338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE33C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE340: jr          $ra
    // 0x800AE344: nop

    return;
    // 0x800AE344: nop

;}
RECOMP_FUNC void func_80057AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057AB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80057ABC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80057AC0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80057AC4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80057AC8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80057ACC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80057AD0: nop

    // 0x80057AD4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80057AD8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80057ADC: nop

    // 0x80057AE0: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80057AE4: nop

    // 0x80057AE8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80057AEC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80057AF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80057AF4: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80057AF8: lw          $t0, 0x2F9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2F9);
    // 0x80057AFC: nop

    // 0x80057B00: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80057B04: sw          $t0, 0xE70($at)
    MEM_W(0XE70, ctx->r1) = ctx->r8;
    // 0x80057B08: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B0C: nop

    // 0x80057B10: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80057B14: jal         0x80098754
    // 0x80057B18: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x80057B18: nop

    after_0:
    // 0x80057B1C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B20: jal         0x80032410
    // 0x80057B24: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x80057B24: nop

    after_1:
    // 0x80057B28: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80057B2C: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80057B30: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80057B34: nop

    // 0x80057B38: andi        $t4, $t3, 0x402
    ctx->r12 = ctx->r11 & 0X402;
    // 0x80057B3C: beq         $t4, $zero, L_80057B6C
    if (ctx->r12 == 0) {
        // 0x80057B40: nop
    
            goto L_80057B6C;
    }
    // 0x80057B40: nop

L_80057B44:
    // 0x80057B44: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B48: jal         0x800499B0
    // 0x80057B4C: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x80057B4C: nop

    after_2:
    // 0x80057B50: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80057B54: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80057B58: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80057B5C: nop

    // 0x80057B60: andi        $t7, $t6, 0x402
    ctx->r15 = ctx->r14 & 0X402;
    // 0x80057B64: bne         $t7, $zero, L_80057B44
    if (ctx->r15 != 0) {
        // 0x80057B68: nop
    
            goto L_80057B44;
    }
    // 0x80057B68: nop

L_80057B6C:
    // 0x80057B6C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80057B70: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80057B74: lh          $a1, 0x7C($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X7C);
    // 0x80057B78: lw          $a3, 0x44($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X44);
    // 0x80057B7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80057B80: addiu       $a2, $zero, 0x8F
    ctx->r6 = ADD32(0, 0X8F);
    // 0x80057B84: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80057B88: jal         0x8004F3E8
    // 0x80057B8C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8004F3E8(rdram, ctx);
        goto after_3;
    // 0x80057B8C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_3:
    // 0x80057B90: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80057B94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057B98: nop

    // 0x80057B9C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80057BA0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80057BA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80057BA8: nop

    // 0x80057BAC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80057BB0:
    // 0x80057BB0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80057BB4: nop

    // 0x80057BB8: bne         $t0, $zero, L_80057C34
    if (ctx->r8 != 0) {
        // 0x80057BBC: nop
    
            goto L_80057C34;
    }
    // 0x80057BBC: nop

    // 0x80057BC0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80057BC4: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80057BC8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80057BCC: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80057BD0: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80057BD4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80057BD8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80057BDC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80057BE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80057BE4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80057BE8: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x80057BEC: nop

    // 0x80057BF0: bc1f        L_80057C34
    if (!c1cs) {
        // 0x80057BF4: nop
    
            goto L_80057C34;
    }
    // 0x80057BF4: nop

    // 0x80057BF8: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x80057BFC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80057C00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80057C04: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80057C08: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80057C0C: nop

    // 0x80057C10: bc1f        L_80057C34
    if (!c1cs) {
        // 0x80057C14: nop
    
            goto L_80057C34;
    }
    // 0x80057C14: nop

    // 0x80057C18: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80057C1C: nop

    // 0x80057C20: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80057C24: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80057C28: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80057C2C: nop

    // 0x80057C30: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_80057C34:
    // 0x80057C34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057C38: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057C3C: lwc1        $f11, -0xEF8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XEF8);
    // 0x80057C40: lwc1        $f10, -0xEF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEF4);
    // 0x80057C44: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80057C48: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80057C4C: jal         0x800C3070
    // 0x80057C50: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_4;
    // 0x80057C50: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_4:
    // 0x80057C54: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057C58: lwc1        $f17, -0xEF0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XEF0);
    // 0x80057C5C: lwc1        $f16, -0xEEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x80057C60: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80057C64: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x80057C68: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80057C6C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80057C70: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80057C74: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80057C78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80057C7C: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x80057C80: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80057C84: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80057C88: jal         0x8005D07C
    // 0x80057C8C: nop

    func_8005D07C(rdram, ctx);
        goto after_5;
    // 0x80057C8C: nop

    after_5:
    // 0x80057C90: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80057C94: nop

    // 0x80057C98: beq         $t5, $zero, L_80057D34
    if (ctx->r13 == 0) {
        // 0x80057C9C: nop
    
            goto L_80057D34;
    }
    // 0x80057C9C: nop

    // 0x80057CA0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057CA4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80057CA8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80057CAC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80057CB0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80057CB4: add.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f4.d + ctx->f18.d;
    // 0x80057CB8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80057CBC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80057CC0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057CC4: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
    // 0x80057CC8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80057CCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80057CD0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80057CD4: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80057CD8: nop

    // 0x80057CDC: bc1f        L_80057D0C
    if (!c1cs) {
        // 0x80057CE0: nop
    
            goto L_80057D0C;
    }
    // 0x80057CE0: nop

    // 0x80057CE4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80057CE8: nop

    // 0x80057CEC: addiu       $a0, $t6, 0x4C
    ctx->r4 = ADD32(ctx->r14, 0X4C);
    // 0x80057CF0: jal         0x800B2748
    // 0x80057CF4: addiu       $a1, $t6, 0x50
    ctx->r5 = ADD32(ctx->r14, 0X50);
    func_800B2748(rdram, ctx);
        goto after_6;
    // 0x80057CF4: addiu       $a1, $t6, 0x50
    ctx->r5 = ADD32(ctx->r14, 0X50);
    after_6:
    // 0x80057CF8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80057CFC: nop

    // 0x80057D00: addiu       $a0, $t7, 0x50
    ctx->r4 = ADD32(ctx->r15, 0X50);
    // 0x80057D04: jal         0x8005A5F4
    // 0x80057D08: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_7;
    // 0x80057D08: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_7:
L_80057D0C:
    // 0x80057D0C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80057D10: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057D14: lwc1        $f7, -0xEE8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XEE8);
    // 0x80057D18: lwc1        $f6, -0xEE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x80057D1C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80057D20: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80057D24: nop

    // 0x80057D28: bc1f        L_80057D34
    if (!c1cs) {
        // 0x80057D2C: nop
    
            goto L_80057D34;
    }
    // 0x80057D2C: nop

    // 0x80057D30: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80057D34:
    // 0x80057D34: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057D38: jal         0x800499B0
    // 0x80057D3C: nop

    func_800499B0(rdram, ctx);
        goto after_8;
    // 0x80057D3C: nop

    after_8:
    // 0x80057D40: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80057D44: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x80057D48: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80057D4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80057D50: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80057D54: nop

    // 0x80057D58: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80057D5C: nop

    // 0x80057D60: bc1t        L_80057BB0
    if (c1cs) {
        // 0x80057D64: nop
    
            goto L_80057BB0;
    }
    // 0x80057D64: nop

    // 0x80057D68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80057D6C: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x80057D70: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x80057D74: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80057D78: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80057D7C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80057D80: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80057D84: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80057D88: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80057D8C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80057D90: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80057D94: nop

    // 0x80057D98: sb          $zero, 0x20($t4)
    MEM_B(0X20, ctx->r12) = 0;
    // 0x80057D9C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DA0: nop

    // 0x80057DA4: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80057DA8: jal         0x80098AD8
    // 0x80057DAC: nop

    func_80098AD8(rdram, ctx);
        goto after_9;
    // 0x80057DAC: nop

    after_9:
    // 0x80057DB0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DB4: jal         0x80049544
    // 0x80057DB8: nop

    func_80049544(rdram, ctx);
        goto after_10;
    // 0x80057DB8: nop

    after_10:
    // 0x80057DBC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DC0: nop

    // 0x80057DC4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80057DC8: jal         0x800C0D34
    // 0x80057DCC: nop

    Thread_StopThread(rdram, ctx);
        goto after_11;
    // 0x80057DCC: nop

    after_11:
L_80057DD0:
    // 0x80057DD0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80057DD4: jal         0x800499B0
    // 0x80057DD8: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x80057DD8: nop

    after_12:
    // 0x80057DDC: b           L_80057DD0
    // 0x80057DE0: nop

        goto L_80057DD0;
    // 0x80057DE0: nop

    // 0x80057DE4: b           L_80057DEC
    // 0x80057DE8: nop

        goto L_80057DEC;
    // 0x80057DE8: nop

L_80057DEC:
    // 0x80057DEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80057DF0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80057DF4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80057DF8: jr          $ra
    // 0x80057DFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80057DFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
